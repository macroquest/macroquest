/*****************************************************************************
    eqlib.dll: MacroQuest's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x510
#define DIRECTINPUT_VERSION 0x800

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW
#include "stdafx.h"
#include "MQ2Main.h"

typedef struct _OurDetours {
    unsigned int addr;
    unsigned int count;
    unsigned char array[50];
	PBYTE pfDetour;
	PBYTE pfTrampoline;

	struct _OurDetours *pNext;
	struct _OurDetours *pLast;
} OurDetours;

OurDetours *ourdetours=0;


BOOL AddDetour(DWORD address, PBYTE pfDetour, PBYTE pfTrampoline)
{
	BOOL Ret=TRUE;
	DebugSpew("AddDetour(0x%X,0x%X,0x%X)",address,pfDetour,pfTrampoline);
	OurDetours *detour = new OurDetours;
	detour->addr=address;
	detour->count=20;
	memcpy(detour->array,(char *)address, 20);
	detour->pNext=ourdetours;
	detour->pLast=0;
    if (pfDetour && !DetourFunctionWithEmptyTrampoline(pfTrampoline, 
         (PBYTE)address, 
         pfDetour))
	{
		detour->pfDetour=0;
		detour->pfTrampoline=0;
		Ret=FALSE;
		DebugSpew("Detour failed.");
	}
	else
	{
		detour->pfDetour=pfDetour;
		detour->pfTrampoline=pfTrampoline;
		DebugSpew("Detour success.");
	}
	ourdetours=detour;
	return Ret;
}

void RemoveDetour(DWORD address)
{
	OurDetours *detour = ourdetours;
	while (detour)
	{
		if (detour->addr==address)
		{
			if (detour->pfDetour)
			{
		      DetourRemove(detour->pfTrampoline, 
				detour->pfDetour); 				
			}
		}
		detour=detour->pNext;
	}
}

void RemoveOurDetours()
{
	OurDetours *detour = NULL;
	if (!ourdetours)
		return;
	while (ourdetours)
	{
		if (ourdetours->pfDetour)
		{
			DetourRemove(ourdetours->pfTrampoline, 
			ourdetours->pfDetour); 				
		}
		detour=ourdetours->pNext;
		delete ourdetours;
		ourdetours=detour;
	}
}


// this is the memory checker key struct
struct mckey {
    union {
        int x;
        unsigned char a[4];
    };
};

// pointer to encryption pad for memory checker
unsigned int *extern_array = NULL;
unsigned int *extern_array2 = NULL;
unsigned int *extern_array3 = NULL;
int __cdecl memcheck(unsigned char *buffer, int count, struct mckey key);
int __cdecl memcheck2(unsigned char *buffer, int count, struct mckey key);
int __cdecl memcheck3(unsigned char *buffer, int count, struct mckey key);



// ***************************************************************************
// Function:    HookMemChecker
// Description: Hook MemChecker
// ***************************************************************************
int (__cdecl *memcheck_tramp)(unsigned char *buffer, int count, struct mckey key);
int (__cdecl *memcheck2_tramp)(unsigned char *buffer, int count, struct mckey key);
int (__cdecl *memcheck3_tramp)(unsigned char *buffer, int count, struct mckey key);

VOID HookMemChecker(BOOL Patch)
{
    // hit the debugger if we don't hook this
    // take no chances
    if ((!EQADDR_MEMCHECK) ||
        (!EQADDR_MEMCHECK2) ||
        (!EQADDR_MEMCHECKADDR1) ||
        (!EQADDR_MEMCHECKADDR2) ||
        (!EQADDR_MEMCHECK3)) {
        _asm int 3
    }
    DebugSpew("HookMemChecker - %satching",(Patch)?"P":"Unp");
    if (Patch) {

		AddDetour((DWORD)EQADDR_MEMCHECK);

        (*(PBYTE*)&memcheck_tramp) = DetourFunction( (PBYTE) EQADDR_MEMCHECK,
                                                    (PBYTE) memcheck);

		AddDetour((DWORD)EQADDR_MEMCHECK2);

        (*(PBYTE*)&memcheck2_tramp) = DetourFunction( (PBYTE) EQADDR_MEMCHECK2,
                                                    (PBYTE) memcheck2);

		AddDetour((DWORD)EQADDR_MEMCHECK3);

        (*(PBYTE*)&memcheck3_tramp) = DetourFunction( (PBYTE) EQADDR_MEMCHECK3,
                                                    (PBYTE) memcheck3);
    } else {
        DetourRemove((PBYTE) memcheck_tramp,
                     (PBYTE) memcheck);

        memcheck_tramp = NULL;
        DetourRemove((PBYTE) memcheck2_tramp,
                     (PBYTE) memcheck2);
        memcheck2_tramp = NULL;

		DetourRemove((PBYTE) memcheck3_tramp,
                     (PBYTE) memcheck3);
        memcheck3_tramp = NULL;
    }
}


//  004F7D24: 55                 push        ebp
//  004F7D25: 8B EC              mov         ebp,esp
//  004F7D27: 8A 45 10           mov         al,byte ptr [ebp+10h]
//  004F7D2A: 56                 push        esi


int __cdecl memcheck(unsigned char *buffer, int count, struct mckey key)
{
    unsigned int x, i;
    unsigned int ecx;
    unsigned int eax = ~key.a[0] & 0xff;

    if (!extern_array) {
        if (!EQADDR_ENCRYPTPAD) {
            //_asm int 3
        } else {
          extern_array = (unsigned int *)EQADDR_ENCRYPTPAD;
        }
    }

//  004F7D2B: F6 D0              not         al
//  004F7D2D: 0F B6 C0           movzx       eax,al
    unsigned int edx = key.a[1] & 0xff;
//  004F7D30: 0F B6 55 11        movzx       edx,byte ptr [ebp+11h]
//  004F7D34: 8B 04 85 6C 7B 5C  mov         eax,dword ptr [eax*4+005C7B6Ch]
//            00

    eax = extern_array[eax];

//  004F7D3B: BE FF FF FF 00     mov         esi,0FFFFFFh
//  004F7D40: 33 C6              xor         eax,esi
    eax ^= 0xffffff;

//  004F7D42: 57                 push        edi
//  004F7D43: 8B C8              mov         ecx,eax
//  004F7D45: BF FF 00 00 00     mov         edi,0FFh

//  004F7D4A: 23 CF              and         ecx,edi
    ecx = eax & 0xff;
//  004F7D4C: 33 CA              xor         ecx,edx
    ecx ^= edx;
//  004F7D4E: 0F B6 55 12        movzx       edx,byte ptr [ebp+12h]
    edx = key.a[2] & 0xff;

//  004F7D52: 8B 0C 8D 6C 7B 5C  mov         ecx,dword ptr [ecx*4+005C7B6Ch]
//            00
    ecx = extern_array[ecx];

//  004F7D59: C1 F8 08           sar         eax,8
//  004F7D5C: 23 C6              and         eax,esi
    eax = ((int)eax>>8) & 0xffffff;

//  004F7D5E: 33 C8              xor         ecx,eax
    ecx ^= eax;

//  004F7D60: 8B C1              mov         eax,ecx
//  004F7D62: 23 C7              and         eax,edi
//  004F7D64: 33 C2              xor         eax,edx
    eax = (ecx & 0xff) ^ edx;

//  004F7D66: C1 F9 08           sar         ecx,8
    ecx = (int)ecx >> 8;

//  004F7D69: 8B 14 85 6C 7B 5C  mov         edx,dword ptr [eax*4+005C7B6Ch]
//            00
    edx = extern_array[eax];

//  004F7D70: 23 CE              and         ecx,esi
//  004F7D72: 33 D1              xor         edx,ecx
    edx ^= ecx & 0xffffff;

//  004F7D74: 0F B6 4D 13        movzx       ecx,byte ptr [ebp+13h]
    ecx = key.a[3] & 0xff;

//  004F7D78: 8B C2              mov         eax,edx
//  004F7D7A: 23 C7              and         eax,edi
//  004F7D7C: 33 C1              xor         eax,ecx
//  004F7D7E: 8B 4D 08           mov         ecx,dword ptr [ebp+8]
//  004F7D81: C1 FA 08           sar         edx,8
//  004F7D84: 8B 04 85 6C 7B 5C  mov         eax,dword ptr [eax*4+005C7B6Ch]
//            00

    eax = extern_array[(edx & 0xff) ^ ecx];

//  004F7D8B: 23 D6              and         edx,esi
//  004F7D8D: 33 C2              xor         eax,edx
    eax ^= ((int)edx>>8) & 0xffffff;

//  004F7D8F: 8B 55 0C           mov         edx,dword ptr [ebp+0Ch]
//  004F7D92: 03 D1              add         edx,ecx
//  004F7D94: 89 4D 10           mov         dword ptr [ebp+10h],ecx
//  004F7D97: 3B CA              cmp         ecx,edx
//  004F7D99: 73 24              jae         004F7DBF
    if (count == 0) return ~eax;

//  004F7D9B: 53                 push        ebx
//  004F7D9C: 8B 5D 10           mov         ebx,dword ptr [ebp+10h]
//  004F7D9F: 8B C8              mov         ecx,eax
//  004F7DA1: 23 CF              and         ecx,edi
//  004F7DA3: 0F B6 1B           movzx       ebx,byte ptr [ebx]
//  004F7DA6: 33 CB              xor         ecx,ebx
//  004F7DA8: C1 F8 08           sar         eax,8
//  004F7DAB: 8B 0C 8D 6C 7B 5C  mov         ecx,dword ptr [ecx*4+005C7B6Ch]
//            00
//  004F7DB2: 23 C6              and         eax,esi
//  004F7DB4: 33 C1              xor         eax,ecx
//  004F7DB6: FF 45 10           inc         dword ptr [ebp+10h]
//  004F7DB9: 39 55 10           cmp         dword ptr [ebp+10h],edx
//  004F7DBC: 72 DE              jb          004F7D9C

//  004F7DBE: 5B                 pop         ebx
//  004F7DBF: 5F                 pop         edi
//  004F7DC0: 5E                 pop         esi
//  004F7DC1: F7 D0              not         eax
//  004F7DC3: 5D                 pop         ebp
//  004F7DC4: C3                 ret

    for (i=0;i<(unsigned int)count;i++) {
        unsigned char tmp;
		OurDetours *detour = ourdetours;
        unsigned int b=(int) &buffer[i];
		while(detour)
		{
			if (detour->count && (b >= detour->addr) &&
                 (b < detour->addr+detour->count) ) {
                 tmp = detour->array[b - detour->addr];
                 break;
            }
			detour=detour->pNext;
		}
        if (!detour) tmp = buffer[i];
        x = (int)tmp ^ (eax & 0xff);
        eax = ((int)eax >> 8) & 0xffffff;
        x = extern_array[x];
        eax ^= x;
    }
    return ~eax;
}


//
// detour 4F77B2 to memcheck2 for 4/8
//

int __cdecl memcheck2(unsigned char *buffer, int count, struct mckey key);

//#define first 0x4f7836
//#define second 0x4f786e

//        TITLE orig.asm
//        .386P
//
//EXTRN _extern_array2:DWORD
//
//_TEXT SEGMENT
//
//getret  PROC NEAR
//        mov         eax,dword ptr [esp]
//        ret
//getret  ENDP
//
//PUBLIC _memcheck2
int __cdecl memcheck2(unsigned char *buffer, int count, struct mckey key)
{
    unsigned int i;
    unsigned int ecx, ebx, edx, eax;

    //DebugSpewAlways("memcheck2: 0x%x", buffer);

    if (!extern_array2) {
        if (!EQADDR_ENCRYPTPAD2) {
            //_asm int 3
        } else {
          extern_array2 = (unsigned int *)EQADDR_ENCRYPTPAD2;
        }
    }
//_memcheck2 PROC NEAR
//        push        ebp
//        mov         ebp,esp
//        mov         al,byte ptr [ebp+10h]
//        push        ebx
//        not         al
//        movzx       eax,al
    eax = ~key.a[0] & 0xff;

//        movzx       edx,byte ptr [ebp+11h]
    edx = key.a[1] & 0xff;

//        mov         eax,dword ptr [eax*4+_extern_array2]
    eax = extern_array2[eax];

//        push        esi
//        mov         esi,0FFFFFFh
//        push        edi
//        xor         eax,esi
    eax ^= 0xffffff;

//        mov         edi,0FFh
//        mov         ecx,eax
//        and         ecx,edi
    ecx = eax & 0xff;

//        xor         ecx,edx
    ecx ^= edx;

//        movzx       edx,byte ptr [ebp+12h]
    edx = key.a[2] & 0xff;

//        mov         ecx,dword ptr [ecx*4+_extern_array2]
    ecx = extern_array2[ecx];

//        sar         eax,8
//        and         eax,esi
    eax = ((int)eax>>8) & 0xffffff;

//        xor         ecx,eax
    ecx ^= eax;

//        mov         eax,ecx
//        and         eax,edi
//        xor         eax,edx
    eax = (ecx & 0xff) ^ edx;

//        movzx       edx,byte ptr [ebp+13h]
    edx = key.a[3] & 0xff;

//        mov         eax,dword ptr [eax*4+_extern_array2]
    eax = extern_array2[eax];

//        sar         ecx,8
//        and         ecx,esi
    ecx = ((int)ecx>>8) & 0xffffff;

//        xor         eax,ecx
    eax ^= ecx;

//        mov         ecx,eax
//        and         ecx,edi
//        xor         ecx,edx
    ecx = (eax & 0xff) ^ edx;

//        sar         eax,8
    eax = ((int)eax>>8) & 0xffffff;
//        mov         ebx,dword ptr [ecx*4+_extern_array2]
//        and         eax,esi
    ebx = extern_array2[ecx];

//        xor         ebx,eax
    ebx ^= eax;
    ebx ^= EQADDR_MEMCHECKADDR1;
//        call        getret
//        mov         ecx,dword ptr [ebp+0Ch]
//        xor         ebx,eax
//        mov         eax,dword ptr [ebp+8]
//        add         ecx,eax
//        mov         dword ptr [ebp+10h],eax
//        cmp         eax,ecx
    if (count == 0) goto done;
//        jae         done
//myloop:
//        mov         edx,dword ptr [ebp+10h]
//        mov         eax,ebx
//        and         eax,edi
//        movzx       edx,byte ptr [edx]
//        xor         eax,edx
//        sar         ebx,8
//        mov         eax,dword ptr [eax*4+_extern_array2]
//
//        and         ebx,esi
//        xor         ebx,eax
//        inc         dword ptr [ebp+10h]
//        cmp         dword ptr [ebp+10h],ecx
//        jb          myloop
    for (i=0;i<(unsigned int)count;i++) {
        unsigned char tmp = buffer[i];
		OurDetours *detour = ourdetours;
        unsigned int b=(int) &buffer[i];
		while(detour)
		{
			if (detour->count && (b >= detour->addr) &&
                 (b < detour->addr+detour->count) ) {
                 tmp = detour->array[b - detour->addr];
                 break;
            }
			detour=detour->pNext;
		}
        if (!detour) tmp = buffer[i];
        eax = (int) tmp ^ (ebx & 0xff);
        ebx = ((int)ebx >> 8) & 0xffffff;
        eax = extern_array2[eax];
        ebx ^= eax;
    }
//done:
done:
//        call        getret
    eax = EQADDR_MEMCHECKADDR2;
    eax ^= ~ebx;
    return eax;
//        not         ebx
//        pop         edi
//        xor         eax,ebx
//        pop         esi
//        pop         ebx
//        pop         ebp
//        ret
//_memcheck2  ENDP
//_TEXT   ENDS
//END
}


//extern int extern_arrray[];
//unsigned int *extern_array3 = (unsigned int *)0x5C0E98;

//  004F4AB9: 55                 push        ebp
//  004F4ABA: 8B EC              mov         ebp,esp
//  004F4ABC: 56                 push        esi

//  bah - 83 /1 ib OR r/m16,imm8 r/m16 OR imm8 (sign-extended)
//  sign extended!!!!!!!!!!!!

//  004F4ABD: 83 C8 FF           or          eax,0FFh

int __cdecl memcheck3(unsigned char *buffer, int count, struct mckey key)
{
    unsigned int fake; // use instead of eax
    unsigned int ecx, edx, i;

    __asm mov fake,eax

    if (!extern_array3) {
        if (!EQADDR_ENCRYPTPAD3) {
            //_asm int 3
        } else {
          extern_array3 = (unsigned int *)EQADDR_ENCRYPTPAD3;
        }
    }

//  004F4AC0: 83 7D 10 00        cmp         dword ptr [ebp+10h],0
    if (key.x)  {
//  004F4AC4: 57                 push        edi
//  004F4AC5: BE FF FF FF 00     mov         esi,0FFFFFFh
//  004F4ACA: BF FF 00 00 00     mov         edi,0FFh
//  004F4ACF: 74 59              je          004F4B2A

//  004F4AD1: 8A 45 10           mov         al,byte ptr [ebp+10h]
//  004F4AD4: F6 D0              not         al
//  004F4AD6: 0F B6 C0           movzx       eax,al
    fake = ~key.a[0] & 0xff;

//  004F4AD9: 0F B6 55 11        movzx       edx,byte ptr [ebp+11h]
    edx = key.a[1] & 0xff;

//  004F4ADD: 8B 04 85 98 0E 5C  mov         eax,dword ptr [eax*4+005C0E98h]
//            00
    fake = extern_array3[fake];

//  004F4AE4: 33 C6              xor         eax,esi
    fake ^= 0xffffff;

//  004F4AE6: 8B C8              mov         ecx,eax
//  004F4AE8: 23 CF              and         ecx,edi
//  004F4AEA: 33 CA              xor         ecx,edx
    ecx = (fake & 0xff) ^ edx;

//  004F4AEC: 0F B6 55 12        movzx       edx,byte ptr [ebp+12h]
    edx = key.a[2] & 0xff;

//  004F4AF0: 8B 0C 8D 98 0E 5C  mov         ecx,dword ptr [ecx*4+005C0E98h]
//            00
    ecx = extern_array3[ecx];

//  004F4AF7: C1 F8 08           sar         eax,8
//  004F4AFA: 23 C6              and         eax,esi
    fake = ((int)fake>>8) & 0xffffff;

//  004F4AFC: 33 C8              xor         ecx,eax
    ecx ^= fake;

//  004F4AFE: 8B C1              mov         eax,ecx
//  004F4B00: 23 C7              and         eax,edi
//  004F4B02: 33 C2              xor         eax,edx
    fake = (ecx & 0xff) ^ edx;

//  004F4B04: C1 F9 08           sar         ecx,8
    ecx = (int) ecx >> 8;

//  004F4B07: 8B 14 85 98 0E 5C  mov         edx,dword ptr [eax*4+005C0E98h]
//            00
    edx = extern_array3[fake];

//  004F4B0E: 23 CE              and         ecx,esi
//  004F4B10: 33 D1              xor         edx,ecx
    edx ^= ecx & 0xffffff;

//  004F4B12: 0F B6 4D 13        movzx       ecx,byte ptr [ebp+13h]
    ecx = key.a[3] & 0xff;

//  004F4B16: 8B C2              mov         eax,edx
//  004F4B18: 23 C7              and         eax,edi
//  004F4B1A: 33 C1              xor         eax,ecx
//  004F4B1C: C1 FA 08           sar         edx,8
//  004F4B1F: 8B 04 85 98 0E 5C  mov         eax,dword ptr [eax*4+005C0E98h]
//            00

    fake = extern_array3[(edx & 0xff) ^ ecx];

//  004F4B26: 23 D6              and         edx,esi
//  004F4B28: 33 C2              xor         eax,edx
    fake ^= ((int) edx>>8) & 0xffffff;

    } else { // if (!key.x)
        fake |= 0xffffffff;
    }
    // fake = eax here

//  004F4B2A: 8B 4D 08           mov         ecx,dword ptr [ebp+8]
//  004F4B2D: 8B 55 0C           mov         edx,dword ptr [ebp+0Ch]
//  004F4B30: 03 D1              add         edx,ecx
//  004F4B32: 3B CA              cmp         ecx,edx
//  004F4B34: 89 55 10           mov         dword ptr [ebp+10h],edx
//  004F4B37: 73 1F              jae         004F4B58
    if (count == 0) return ~fake;

//  004F4B39: 53                 push        ebx
//  004F4B3A: 0F B6 19           movzx       ebx,byte ptr [ecx]
//  004F4B3D: 8B D0              mov         edx,eax
//  004F4B3F: 23 D7              and         edx,edi
//  004F4B41: 33 D3              xor         edx,ebx
//  004F4B43: C1 F8 08           sar         eax,8
//  004F4B46: 8B 14 95 98 0E 5C  mov         edx,dword ptr [edx*4+005C0E98h]
//            00
//  004F4B4D: 23 C6              and         eax,esi
//  004F4B4F: 33 C2              xor         eax,edx
//  004F4B51: 41                 inc         ecx
//  004F4B52: 3B 4D 10           cmp         ecx,dword ptr [ebp+10h]
//  004F4B55: 72 E3              jb          004F4B3A

    for (i=0;i<(unsigned int)count;i++) {
        unsigned char tmp;
		OurDetours *detour = ourdetours;
        unsigned int b=(int) &buffer[i];
		while(detour)
		{
			if (detour->count && (b >= detour->addr) &&
                 (b < detour->addr+detour->count) ) {
                 tmp = detour->array[b - detour->addr];
                 break;
            }
			detour=detour->pNext;
		}
        if (!detour) tmp = buffer[i];
        edx = (int)tmp ^ (fake & 0xff);
        fake = ((int)fake >> 8) & 0xffffff;
        edx = extern_array3[edx];
        fake ^= edx;
    }
    return ~fake;


//  004F4B57: 5B                 pop         ebx
//  004F4B58: 5F                 pop         edi
//  004F4B59: 5E                 pop         esi
//  004F4B5A: F7 D0              not         eax
//  004F4B5C: 5D                 pop         ebp
//  004F4B5D: C3                 ret
}

void InitializeMQ2Detours()
{
	HookMemChecker(TRUE);

}

void ShutdownMQ2Detours()
{
	HookMemChecker(FALSE);
	RemoveOurDetours();
}
