/*****************************************************************************
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

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

#include "MQ2Main.h"
#ifndef ISXEQ

typedef struct _OurDetours {
    /* 0x00 */    unsigned int addr;
    /* 0x04 */    unsigned int count;
    /* 0x08 */    unsigned char array[50];
    /* 0x3a */    PBYTE pfDetour;
    /* 0x3e */    PBYTE pfTrampoline;
    /* 0x42 */    struct _OurDetours *pNext;
    /* 0x46 */    struct _OurDetours *pLast;
} OurDetours;

OurDetours *ourdetours=0;
CRITICAL_SECTION gDetourCS;


OurDetours *FindDetour(DWORD address)
{
    OurDetours *pDetour=ourdetours;
    while(pDetour)
    {
        if (pDetour->addr==address)
            return pDetour;
        pDetour=pDetour->pNext;
    }
    return 0;
}

BOOL AddDetour(DWORD address, PBYTE pfDetour, PBYTE pfTrampoline, DWORD Count)
{
    CAutoLock Lock(&gDetourCS);
    BOOL Ret=TRUE;
    DebugSpew("AddDetour(0x%X,0x%X,0x%X,0x%X)",address,pfDetour,pfTrampoline,Count);
    if (FindDetour(address))
    {

        DebugSpew("Address 0x%x already detoured.",address);
        return FALSE;
    }
    OurDetours *detour = new OurDetours;
    detour->addr=address;
    detour->count=Count;
    memcpy(detour->array,(char *)address, Count);
    detour->pNext=ourdetours;
    if (ourdetours)
        ourdetours->pLast=detour;
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

void AddDetourf(DWORD address, ...)
{
    va_list marker;
    int i=0;
    va_start(marker, address);
    DWORD Parameters[3];
    DWORD nParameters=0;
    while (i!=-1) 
    {
        if (nParameters<3)
        {
            Parameters[nParameters]=i;
            nParameters++;
        }
        i = va_arg(marker,int);
    }
    va_end(marker);
    if (nParameters==3)
    {
        AddDetour(address,(PBYTE)Parameters[1],(PBYTE)Parameters[2],20);
    }
    else
    {
        DebugSpew("Illegal AddDetourf call");
    }
}

void RemoveDetour(DWORD address)
{
    CAutoLock Lock(&gDetourCS);
    DebugSpew("RemoveDetour(%X)",address);
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
            if (detour->pLast)
                detour->pLast->pNext=detour->pNext;
            else
                ourdetours=detour->pNext;

            if (detour->pNext)
                detour->pNext->pLast=detour->pLast;
            delete detour;
            DebugSpew("Detour removed.");
            return;
        }
        detour=detour->pNext;
    }
    DebugSpew("Detour not found in RemoveDetour()");
}

void RemoveOurDetours()
{
    CAutoLock Lock(&gDetourCS);
    DebugSpew("RemoveOurDetours()");
    if (!ourdetours)
        return;
    while (ourdetours)
    {
        if (ourdetours->pfDetour)
        {
            DebugSpew("RemoveOurDetours() -- Removing %X",ourdetours->addr);
            DetourRemove(ourdetours->pfTrampoline,ourdetours->pfDetour);                 
        }

        OurDetours *pNext=ourdetours->pNext;
        delete ourdetours;
        ourdetours=pNext;
    }
}

#endif


class CObfuscator 
{
public:
    int doit_tramp(int, int); 
    int doit_detour(int opcode, int flag);
};

int CObfuscator::doit_detour(int opcode, int flag)
{
#if 0
    if (EQ_BEGIN_ZONE == opcode) {
        DebugSpewAlways("EQ_BEGIN_ZONE");
    } else {
        DebugSpewAlways("opcode %d", opcode);
    }
#endif
    if (opcode==EQ_BEGIN_ZONE) PluginsBeginZone(); 
    if (opcode==EQ_END_ZONE) PluginsEndZone();
    return doit_tramp(opcode, flag);
};

DETOUR_TRAMPOLINE_EMPTY(int CObfuscator::doit_tramp(int, int));

#define EB_SIZE (1024*4)
void emotify(void);
void emotify2(char *buffer);

// we need this detour to clean up the stack because
// emote sends 1024 bytes no matter how many bytes in the string
// MQ2 variables get left on the stack....
class CEmoteHook 
{ 
public: 
    VOID Trampoline(void);
    VOID Detour(void);
};

VOID CEmoteHook::Detour(void)
{ 
    emotify();
    Trampoline();
}
DETOUR_TRAMPOLINE_EMPTY(VOID CEmoteHook::Trampoline(void)); 


// this is the memory checker key struct
struct mckey {
    union {
        int x;
        unsigned char a[4];
        char sa[4];
    };
};

// pointer to encryption pad for memory checker
unsigned int *extern_array0 = NULL;
unsigned int *extern_array1 = NULL;
unsigned int *extern_array2 = NULL;
unsigned int *extern_array3 = NULL;
unsigned int *extern_array4 = NULL;
#ifndef ISXEQ
int __cdecl memcheck0(unsigned char *buffer, int count);
int __cdecl memcheck1(unsigned char *buffer, int count, struct mckey key);
int __cdecl memcheck2(unsigned char *buffer, int count, struct mckey key);
int __cdecl memcheck3(unsigned char *buffer, int count, struct mckey key);
int __cdecl memcheck4(unsigned char *buffer, int count, struct mckey key);
#endif

// ***************************************************************************
// Function:    HookMemChecker
// Description: Hook MemChecker
// ***************************************************************************
int (__cdecl *memcheck0_tramp)(unsigned char *buffer, int count);
int (__cdecl *memcheck1_tramp)(unsigned char *buffer, int count, struct mckey key);
int (__cdecl *memcheck2_tramp)(unsigned char *buffer, int count, struct mckey key);
int (__cdecl *memcheck3_tramp)(unsigned char *buffer, int count, struct mckey key);
int (__cdecl *memcheck4_tramp)(unsigned char *buffer, int count, struct mckey key);
VOID HookInlineChecks(BOOL Patch)
{
    int i;
    DWORD oldperm, tmp, NewData;

    int cmps[] = { __AC1 + 6 };

    int cmps2[] = { __AC2,
                    __AC3,
                    __AC4,
                    __AC5,
                    __AC6,
                    __AC7 };

    int len2[] = { 6, 6, 6, 6, 6, 6 }; 

    char NewData2[20];

    static char OldData2[sizeof(cmps2)/sizeof(cmps2[0])][20];

    if (Patch)
    {
        NewData = 0x7fffffff;

        for (i=0;i<sizeof(cmps)/sizeof(cmps[0]);i++) {
#ifdef ISXEQ
            EzModify(cmps[i],&NewData,4);
#else
            AddDetour(cmps[i], NULL, NULL, 4);
            VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps[i], 4, PAGE_EXECUTE_READWRITE, &oldperm);
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)cmps[i], (LPVOID)&NewData, 4, NULL);
            VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps[i], 4, oldperm, &tmp);
#endif
        }

        memset(NewData2, 0x90, 20);

        for (i=0;i<sizeof(cmps2)/sizeof(cmps2[0]);i++) {
#ifdef ISXEQ
            EzModify(cmps2[i],NewData2,len2[i]);
#else
            AddDetour(cmps2[i], NULL, NULL, len2[i]);
            VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps2[i], len2[i], PAGE_EXECUTE_READWRITE, &oldperm);
            memcpy((void *)OldData2[i], (void *)cmps2[i], len2[i]);
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)cmps2[i], (LPVOID)NewData2, len2[i], NULL);
            VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps2[i], len2[i], oldperm, &tmp);
#endif
        }
    }
    else
    {
        NewData = __AC1_Data;

        for (i=0;i<sizeof(cmps)/sizeof(cmps[0]);i++) {
#ifdef ISXEQ
            EzUnModify(cmps[i]);
#else
            VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps[i], 4, PAGE_EXECUTE_READWRITE, &oldperm);
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)cmps[i], (LPVOID)&NewData, 4, NULL);
            VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps[i], 4, oldperm, &tmp);
            RemoveDetour(cmps[i]);
#endif
        }

        for (i=0;i<sizeof(cmps2)/sizeof(cmps2[0]);i++) {
#ifdef ISXEQ
            EzUnModify(cmps2[i]);
#else
            VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps2[i], len2[i], PAGE_EXECUTE_READWRITE, &oldperm);
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)cmps2[i], (LPVOID)OldData2[i], len2[i], NULL);
            VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps2[i], len2[i], oldperm, &tmp);
            RemoveDetour(cmps2[i]);
#endif
        }
    }
}

#ifndef ISXEQ
VOID HookMemChecker(BOOL Patch)
{

    // hit the debugger if we don't hook this
    // take no chances
    if ((!EQADDR_MEMCHECK0) ||
        (!EQADDR_MEMCHECK1) ||
        (!EQADDR_MEMCHECK2) ||
        (!EQADDR_MEMCHECK3) ||
        (!EQADDR_MEMCHECK4)) {
            _asm int 3
    }

    DebugSpew("HookMemChecker - %satching",(Patch)?"P":"Unp");
    if (Patch) {

        AddDetour((DWORD)EQADDR_MEMCHECK0);

        (*(PBYTE*)&memcheck0_tramp) = DetourFunction( (PBYTE) EQADDR_MEMCHECK0,
            (PBYTE) memcheck0);

        AddDetour((DWORD)EQADDR_MEMCHECK1);

        (*(PBYTE*)&memcheck1_tramp) = DetourFunction( (PBYTE) EQADDR_MEMCHECK1,
            (PBYTE) memcheck1);

        AddDetour((DWORD)EQADDR_MEMCHECK2);

        (*(PBYTE*)&memcheck2_tramp) = DetourFunction( (PBYTE) EQADDR_MEMCHECK2,
            (PBYTE) memcheck2);

        AddDetour((DWORD)EQADDR_MEMCHECK3);

        (*(PBYTE*)&memcheck3_tramp) = DetourFunction( (PBYTE) EQADDR_MEMCHECK3,
            (PBYTE) memcheck3);

        AddDetour((DWORD)EQADDR_MEMCHECK4);

        (*(PBYTE*)&memcheck4_tramp) = DetourFunction( (PBYTE) EQADDR_MEMCHECK4,
            (PBYTE) memcheck4);

        EzDetour(CObfuscator__doit,&CObfuscator::doit_detour,&CObfuscator::doit_tramp);
        EzDetour(CEverQuest__Emote,&CEmoteHook::Detour,&CEmoteHook::Trampoline);

        HookInlineChecks(Patch);
    } else {
        HookInlineChecks(Patch);



        DetourRemove((PBYTE) memcheck0_tramp,
            (PBYTE) memcheck0);
        memcheck0_tramp = NULL;
        RemoveDetour(EQADDR_MEMCHECK0);

        DetourRemove((PBYTE) memcheck1_tramp,
            (PBYTE) memcheck1);
        memcheck1_tramp = NULL;
        RemoveDetour(EQADDR_MEMCHECK1);

        DetourRemove((PBYTE) memcheck2_tramp,
            (PBYTE) memcheck2);
        memcheck2_tramp = NULL;
        RemoveDetour(EQADDR_MEMCHECK2);

        DetourRemove((PBYTE) memcheck3_tramp,
            (PBYTE) memcheck3);
        memcheck3_tramp = NULL;
        RemoveDetour(EQADDR_MEMCHECK3);

        DetourRemove((PBYTE) memcheck4_tramp,
            (PBYTE) memcheck4);
        memcheck4_tramp = NULL;
        RemoveDetour(EQADDR_MEMCHECK4);

        RemoveDetour(CObfuscator__doit);
        RemoveDetour(CEverQuest__Emote);
    }
}
#endif

int __cdecl memcheck0(unsigned char *buffer, int count)
{
    unsigned int x, i;
    unsigned int eax = 0xffffffff;

    if (!extern_array0) {
        if (!EQADDR_ENCRYPTPAD0) {
            //_asm int 3
        } else {
            extern_array0 = (unsigned int *)EQADDR_ENCRYPTPAD0;
        }
    }

#ifdef ISXEQ
    unsigned char *realbuffer=(unsigned char *)malloc(count);
    pExtension->Memcpy_Clean((unsigned int)buffer,realbuffer,count);
#endif

    for (i=0;i<(unsigned int)count;i++) {
        unsigned char tmp;
#ifdef ISXEQ
        tmp=realbuffer[i];
#else
        unsigned int b=(int) &buffer[i];
        OurDetours *detour = ourdetours;
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
#endif
        x = (int)tmp ^ (eax & 0xff);
        eax = ((int)eax >> 8) & 0xffffff;
        x = extern_array0[x];
        eax ^= x;
    }

#ifdef ISXEQ
    free(realbuffer);
#endif
    return eax;
}


int __cdecl memcheck1(unsigned char *buffer, int count, struct mckey key) 
{
    unsigned int i;
    unsigned int ebx, eax, edx;

    if (!extern_array1) {
        if (!EQADDR_ENCRYPTPAD1) {
            //_asm int 3
        } else {
            extern_array1 = (unsigned int *)EQADDR_ENCRYPTPAD1;
        }
    }
//                push    ebp
//                mov     ebp, esp
//                push    esi
//                push    edi
//                or      edi, 0FFFFFFFFh
//                cmp     [ebp+arg_8], 0
    if (key.x != 0) {
//                mov     esi, 0FFh
//                mov     ecx, 0FFFFFFh
//                jz      short loc_4C3978
//                xor     eax, eax
//                mov     al, byte ptr [ebp+arg_8]
//                xor     edx, edx
//                mov     dl, byte ptr [ebp+arg_8+1]
        edx = key.a[1];
//                not     eax
//                and     eax, esi
        eax = ~key.a[0] & 0xff;
//                mov     eax, encryptpad1[eax*4]
        eax = extern_array1[eax];
//                xor     eax, ecx
        eax ^= 0xffffff;
//                xor     edx, eax
//                and     edx, esi
        edx = (edx ^ eax) & 0xff;
//                sar     eax, 8
//                and     eax, ecx
        eax = ((int)eax >> 8) & 0xffffff;
//                xor     eax, encryptpad1[edx*4]
        eax ^= extern_array1[edx];
//                xor     edx, edx
//                mov     dl, byte ptr [ebp+arg_8+2]
        edx = key.a[2];
//                xor     edx, eax
//                sar     eax, 8
//                and     edx, esi
        edx = (edx ^ eax) & 0xff;
//                and     eax, ecx
        eax = ((int)eax >> 8) & 0xffffff;
//                xor     eax, encryptpad1[edx*4]
        eax ^= extern_array1[edx];
//                xor     edx, edx
//                mov     dl, byte ptr [ebp+arg_8+3]
        edx = key.a[3];
//                xor     edx, eax
//                sar     eax, 8
//                and     edx, esi
        edx = (edx ^ eax) & 0xff;
//                and     eax, ecx
        eax = ((int)eax >> 8) & 0xffffff;
//                xor     eax, encryptpad1[edx*4]
        eax ^= extern_array1[edx];
//                mov     edi, eax
//
    } else { // key.x != 0
        eax = 0xffffffff;
    }
//loc_4C3978:                             ; CODE XREF: new_memcheck1+16j
//                mov     edx, [ebp+arg_0]
//                mov     eax, [ebp+arg_4]
//                add     eax, edx
//                cmp     edx, eax
//                jnb     short loc_4C399F
//                push    ebx
//
//loc_4C3985:                             ; CODE XREF: new_memcheck1+8Fj
//                xor     ebx, ebx
//                mov     bl, [edx]
//                xor     ebx, edi
//                sar     edi, 8
//                and     ebx, esi
//                and     edi, ecx
//                xor     edi, encryptpad1[ebx*4]
//                inc     edx
//                cmp     edx, eax
//                jb      short loc_4C3985
//                pop     ebx
//
//loc_4C399F:                             ; CODE XREF: new_memcheck1+75j
//                mov     eax, edi
//                pop     edi
//                not     eax
//                pop     esi
//                pop     ebp
//                retn
//

#ifdef ISXEQ
    unsigned char *realbuffer=(unsigned char *)malloc(count);
    pExtension->Memcpy_Clean((unsigned int)buffer,realbuffer,count);
#endif

    for (i=0;i<(unsigned int)count;i++) {
        unsigned char tmp;
#ifdef ISXEQ
        tmp=realbuffer[i];
#else
        unsigned int b=(int) &buffer[i];
        OurDetours *detour = ourdetours;
        while(detour) {
            if (detour->count && (b >= detour->addr) &&
                (b < detour->addr+detour->count) ) {
                    tmp = detour->array[b - detour->addr];
                    break;
            }
            detour=detour->pNext;
        }
        if (!detour) tmp = buffer[i];
#endif
        ebx = ((int)tmp ^ eax) & 0xff;
        eax = ((int)eax >> 8) & 0xffffff;
        eax ^= extern_array1[ebx];
    }
#ifdef ISXEQ
    free(realbuffer);
#endif
    return ~eax;
}



int __cdecl memcheck2(unsigned char *buffer, int count, struct mckey key)
{
    unsigned int i;
    unsigned int ebx, edx, eax;

    //DebugSpewAlways("memcheck2: 0x%x", buffer);

    if (!extern_array2) {
        if (!EQADDR_ENCRYPTPAD2) {
            //_asm int 3
        } else {
            extern_array2 = (unsigned int *)EQADDR_ENCRYPTPAD2;
        }
    }
//                push    ebp
//                mov     ebp, esp
//                push    ecx
//                xor     eax, eax
//                mov     al, [ebp+arg_8]
//                xor     edx, edx
//                mov     dl, [ebp+arg_9]
    edx = key.a[1];
//                push    ebx
//                push    esi
//                mov     esi, 0FFh
//                mov     ecx, 0FFFFFFh
//                not     eax
//                and     eax, esi
    eax = ~key.a[0] & 0xff;
//                mov     eax, encryptpad2[eax*4]
    eax = extern_array2[eax];
//                xor     eax, ecx
    eax ^= 0xffffff;
//                xor     edx, eax
    edx = (edx ^ eax) & 0xff;
//                sar     eax, 8
//                and     edx, esi
//                and     eax, ecx
    eax = ((int)eax >> 8) & 0xffffff;
//                xor     eax, encryptpad2[edx*4]
    eax ^= extern_array2[edx];
//                xor     edx, edx
//                mov     dl, [ebp+arg_A]
    edx = key.a[2];
//                push    edi
//                xor     edx, eax
    edx = (edx ^ eax) & 0xff;
//                sar     eax, 8
//                and     edx, esi
//                and     eax, ecx
    eax = ((int)eax >> 8) & 0xffffff;
//                xor     eax, encryptpad2[edx*4]
//                mov     edx, eax
    edx = eax ^ extern_array2[edx];
//                call    null_sub_ret_0
    eax = 0;
//                mov     edi, [ebp+arg_0]
//                xor     ebx, ebx
//                mov     bl, [ebp+arg_B]
    ebx = key.a[3];
//                mov     [ebp+var_4], eax
//                xor     ebx, edx
    ebx = (edx ^ ebx) & 0xff;
//                sar     edx, 8
//                and     edx, ecx
//                and     ebx, esi
    edx = ((int)edx >> 8) & 0xffffff;
//                xor     edx, encryptpad2[ebx*4]
    edx ^= extern_array2[ebx];
//                xor     edx, eax
    edx ^= eax;
//                mov     eax, [ebp+arg_4]
//                add     eax, edi
//                jmp     short loc_4C5776
//; ---------------------------------------------------------------------------
//
//loc_4C5761:                             ; CODE XREF: new_memcheck2+8Fj
//                xor     ebx, ebx
//                mov     bl, [edi]
//                xor     ebx, edx
//                sar     edx, 8
//                and     ebx, esi
//                and     edx, ecx
//                xor     edx, encryptpad2[ebx*4]
//                inc     edi
//
//loc_4C5776:                             ; CODE XREF: new_memcheck2+76j
//                cmp     edi, eax
//                jb      short loc_4C5761
//                pop     edi
//                mov     eax, edx
//                not     eax
//                xor     eax, [ebp+var_4]
//                pop     esi
//                pop     ebx
//                leave
//                retn


#ifdef ISXEQ
    unsigned char *realbuffer=(unsigned char *)malloc(count);
    pExtension->Memcpy_Clean((unsigned int)buffer,realbuffer,count);
#endif

    for (i=0;i<(unsigned int)count;i++) {
        unsigned char tmp;

#ifdef ISXEQ
        tmp=realbuffer[i];
#else
        unsigned int b=(int) &buffer[i];
        OurDetours *detour = ourdetours;
        while(detour) {
            if (detour->count && (b >= detour->addr) &&
                (b < detour->addr+detour->count) ) {
                    tmp = detour->array[b - detour->addr];
                    break;
            }
            detour=detour->pNext;
        }
        if (!detour) tmp = buffer[i];
#endif

        ebx = ((int) tmp ^ edx) & 0xff;
        edx = ((int)edx >> 8) & 0xffffff;
        edx ^= extern_array2[ebx];
    }
    eax = ~edx ^ 0;
#ifdef ISXEQ
    free(realbuffer);
#endif
    return eax;
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
    unsigned int eax, ebx, edx, i;

    if (!extern_array3) {
        if (!EQADDR_ENCRYPTPAD3) {
            //_asm int 3
        } else {
            extern_array3 = (unsigned int *)EQADDR_ENCRYPTPAD3;
        }
    }
//                push    ebp
//                mov     ebp, esp
//                push    ecx
//                xor     eax, eax
//                mov     al, [ebp+arg_8]
//                xor     edx, edx
//                mov     dl, [ebp+arg_9]
    edx = key.a[1];
//                push    ebx
//                push    esi
//                mov     esi, 0FFh
//                mov     ecx, 0FFFFFFh
//                not     eax
//                and     eax, esi
    eax = ~key.a[0] & 0xff;
//                mov     eax, encryptpad3[eax*4]
    eax = extern_array3[eax];
//                xor     eax, ecx
    eax ^= 0xffffff;
//                xor     edx, eax
//                sar     eax, 8
//                and     edx, esi
    edx = (edx ^ eax) & 0xff;
//                and     eax, ecx
    eax = ((int)eax>>8) & 0xffffff;
//                xor     eax, encryptpad3[edx*4]
    eax ^= extern_array3[edx];
//                xor     edx, edx
//                mov     dl, [ebp+arg_A]
    edx = key.a[2];
//                push    edi
//                xor     edx, eax
    edx = (edx ^ eax) & 0xff;
//                sar     eax, 8
//                and     edx, esi
//                and     eax, ecx
    eax = ((int)eax>>8) & 0xffffff;
//                xor     eax, encryptpad3[edx*4]
//                mov     edx, eax
    edx = eax ^ extern_array3[edx];

//                call    null_sub_ret_0
    eax = 0;
//                mov     edi, [ebp+arg_0]
//                xor     ebx, ebx
//                mov     bl, [ebp+arg_B]
    ebx = key.a[3];
//                mov     [ebp+var_4], eax
//                xor     ebx, edx
//                sar     edx, 8
//                and     edx, ecx
//                and     ebx, esi
    ebx = (ebx ^ edx) & 0xff;
    edx = ((int)edx>>8) & 0xffffff;
//                xor     edx, encryptpad3[ebx*4]
    edx ^= extern_array3[ebx];
//                xor     edx, eax
    edx ^= eax;
//                mov     eax, [ebp+arg_4]
//                add     eax, edi
//                jmp     short loc_4C5813
//; ---------------------------------------------------------------------------
//
//loc_4C57FE:                             ; CODE XREF: new_memcheck3+8Fj
//                xor     ebx, ebx
//                mov     bl, [edi]
//                xor     ebx, edx
//                sar     edx, 8
//                and     ebx, esi
//                and     edx, ecx
//                xor     edx, encryptpad3[ebx*4]
//                inc     edi
//

#ifdef ISXEQ
    unsigned char *realbuffer=(unsigned char *)malloc(count);
    pExtension->Memcpy_Clean((unsigned int)buffer,realbuffer,count);
#endif

    for (i=0;i<(unsigned int)count;i++) {
        unsigned char tmp;
#ifdef ISXEQ
        tmp=realbuffer[i];
#else
        unsigned int b=(int) &buffer[i];
        OurDetours *detour = ourdetours;
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
#endif

        ebx = (tmp ^ edx) & 0xff;
        edx = ((int)edx >> 8) & 0xffffff;
        edx ^= extern_array3[ebx];
    }
//loc_4C5813:                             ; CODE XREF: new_memcheck3+76j
//                cmp     edi, eax
//                jb      short loc_4C57FE
//                pop     edi
//                mov     eax, edx
//                not     eax
//                xor     eax, [ebp+var_4]
    eax = ~edx ^ 0;

#ifdef ISXEQ
    free(realbuffer);
#endif
    return eax;
//                pop     esi
//                pop     ebx
//                leave
//                retn
}

int __cdecl memcheck4(unsigned char *buffer, int count, struct mckey key)
{
    unsigned int eax, ebx, edx, i;

    if (!extern_array4) {
        if (!EQADDR_ENCRYPTPAD4) {
            //_asm int 3
        } else {
            extern_array4 = (unsigned int *)EQADDR_ENCRYPTPAD4;
        }
    }
    edx = key.a[1];
    eax = ~key.a[0] & 0xff;
    eax = extern_array4[eax];
    eax ^= 0xffffff;
    edx = (edx ^ eax) & 0xff;
    eax = ((int)eax>>8) & 0xffffff;
    eax ^= extern_array4[edx];
    edx = key.a[2];
    edx = (edx ^ eax) & 0xff;
    eax = ((int)eax>>8) & 0xffffff;
    edx = eax ^ extern_array4[edx];
    eax = 0;
    ebx = key.a[3];
    ebx = (ebx ^ edx) & 0xff;
    edx = ((int)edx>>8) & 0xffffff;
    edx ^= extern_array4[ebx];
    edx ^= eax;

#ifdef ISXEQ
    unsigned char *realbuffer=(unsigned char *)malloc(count);
    pExtension->Memcpy_Clean((unsigned int)buffer,realbuffer,count);
#endif

    for (i=0;i<(unsigned int)count;i++) {
        unsigned char tmp;
#ifdef ISXEQ
        tmp=realbuffer[i];
#else
        unsigned int b=(int) &buffer[i];
        OurDetours *detour = ourdetours;
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
#endif

        ebx = (tmp ^ edx) & 0xff;
        edx = ((int)edx >> 8) & 0xffffff;
        edx ^= extern_array4[ebx];
    }
    eax = ~edx ^ 0;

#ifdef ISXEQ
    free(realbuffer);
#endif
    return eax;
}
typedef struct _Launchinfo
{
/*0x000*/	PCHAR eqgamepath;
/*0x004*/	PCHAR CmdLine;
} Launchinfo,*PLaunchinfo;
typedef struct _EQCrash
{
/*0x000*/	DWORD funcaddress;
/*0x004*/	DWORD Unknown0x004;
/*0x008*/	DWORD ErrorCode;
/*0x00C*/	DWORD Unknown0x00C; //00000000
/*0x010*/	DWORD Unknown0x010; //FFFFFFFF
/*0x014*/	PLaunchinfo pLinfo;
} EQCrash,*PEQCrash;
typedef struct _CrashReport
{
/*0x000*/	DWORD Unknown0x000;
/*0x004*/	DWORD Unknown0x004;
/*0x008*/	DWORD Unknown0x008;
/*0x00C*/	DWORD Unknown0x00C;
/*0x010*/	PEQCrash pthecrash;
/*0x014*/	PCHAR sessionpath;
} CrashReport,*PCrashReport;

int wwsCrashReportCheckForUploader_Trampoline(PEQCrash,PCHAR,size_t,DWORD,DWORD,DWORD); 
int wwsCrashReportCheckForUploader_Detour(PEQCrash crash,PCHAR crashuploder,size_t ncrashuploder,DWORD a,DWORD b,DWORD c)
{ 
	//MessageBox(NULL,"crash","crash",MB_OK);
	wwsCrashReportCheckForUploader_Trampoline(crash,crashuploder,ncrashuploder,a,b,c);
	//should we redirect the upload? we could have our own server for these dumps I suppose...
	//strcpy_s(crashuploder,ncrashuploder,"mq2_crashreport_uploader.exe");
	//for now im just renaming the folder and returning 0 this will stop any uploads.
	//hmm... -eqmule

	ZeroMemory(crashuploder,ncrashuploder);
	PCrashReport pTheCrash = (PCrashReport)(((DWORD)crashuploder)+ncrashuploder);
	CHAR szMessage[MAX_STRING] = {0};
	CHAR szNewPath[MAX_STRING] = {0};
	sprintf_s(szNewPath,"%s.Copy",pTheCrash->sessionpath);
	MoveFile(pTheCrash->sessionpath,szNewPath);
	sprintf_s(szMessage,"MacroQuest2 is blocking the sending of Sony crash info for your safety and privacy.  Crashes are usually bugs either in EQ or in MacroQuest2.  It is generally not something that you yourself did, unless you have custom MQ2 plugins loaded.  If you want to submit a bug report to the MacroQuest2 message boards, please follow the instructions on how to submit a crash bug report at the top of the MQ2::Bug Reports forum.\n\nA MiniDump has been generated in %s, you can mail the .dmp file in that directory to eqmule@hotmail.com if you think this crash is mq2 related.\n\nFull dumps are located in C:\\Crash if one was generated.\n\nIf you like to break into debugger at this point click yes.",szNewPath);
	int ret = MessageBox(0,szMessage,"EverQuest Crash Report Sending Detected",MB_YESNO);
	if(ret==IDYES)
		DebugBreak();
	//and return 0 (no uploader found)
	return 0;
}
DETOUR_TRAMPOLINE_EMPTY(int wwsCrashReportCheckForUploader_Trampoline(PEQCrash,PCHAR,size_t,DWORD,DWORD,DWORD)); 
//changed in jan 21 2014 eqgame.exe - eqmule
PCHAR __cdecl CrashDetected_Trampoline(BOOL,PCHAR);
PCHAR __cdecl CrashDetected_Detour(BOOL flag,PCHAR SessionPath)
{
	//this function returns a pointer to whatever it writes to the log.
	//yeah uhm we don't need to show this dialog or we could show our own to have crashdumps sent to us
	//but for now im just gonna put a pin in that idea. -eqmule
	return 0;
}
DETOUR_TRAMPOLINE_EMPTY(PCHAR CrashDetected_Trampoline(BOOL,PCHAR));
DETOUR_TRAMPOLINE_EMPTY(int LoadFrontEnd_Trampoline());
#ifndef TESTMEM
int LoadFrontEnd_Detour()
{
    gGameState=GetGameState();

    DebugTry(Benchmark(bmPluginsSetGameState,PluginsSetGameState(gGameState))); 

    return LoadFrontEnd_Trampoline();
}
#endif
void InitializeMQ2Detours()
{
#ifndef ISXEQ
    InitializeCriticalSection(&gDetourCS);
    HookMemChecker(TRUE);
#endif
    EzDetour(wwsCrashReportCheckForUploader,wwsCrashReportCheckForUploader_Detour,wwsCrashReportCheckForUploader_Trampoline);
    EzDetour(CrashDetected,CrashDetected_Detour,CrashDetected_Trampoline);
#ifndef TESTMEM
    EzDetour(__LoadFrontEnd, LoadFrontEnd_Detour, LoadFrontEnd_Trampoline);
#endif
}

void ShutdownMQ2Detours()
{
    RemoveDetour(CrashDetected);
	RemoveDetour(wwsCrashReportCheckForUploader);
    RemoveDetour(__LoadFrontEnd);
#ifndef ISXEQ
    HookMemChecker(FALSE);
    RemoveOurDetours();
    DeleteCriticalSection(&gDetourCS);
#endif
}


#pragma optimize( "", off )

void emotify(void)
{
    char buffer[EB_SIZE];
    emotify2(buffer);
}
void emotify2(char *A)
{
    int i;
    for (i=0;i<EB_SIZE;i+=1024)
        memcpy(A+i, EQADDR_ENCRYPTPAD0, 1024);
    /*
    int Pos = &A[0];
    int End = Pos + EB_SIZE;
    for (Pos ; Pos < End ; Pos++)
        A[Pos]=0;

    int t;
    for (Pos ; Pos < 1024 ; Pos++) {
        t = (int)(397.0*rand()/(RAND_MAX+1.0));
        A[Pos]=(t <= 255) ? (char)t : 0;
    }
    */
}
#pragma optimize( "", on )
