        TITLE orig.asm
        .386P

EXTRN _myextern_array:DWORD

_TEXT   SEGMENT PARA USE32 PUBLIC 'CODE'

PUBLIC __MemChecker1

__MemChecker1   proc near

arg_0           = dword ptr  8
arg_4           = dword ptr  0Ch
arg_8           = dword ptr  10h

                push    ebp
                mov     ebp, esp
                push    esi
                push    edi
                or      edi, 0FFFFFFFFh
                cmp     [ebp+arg_8], 0
                mov     esi, 0FFh
                mov     ecx, 0FFFFFFh
                jz      short loc_526F89
                xor     eax, eax
                mov     al, byte ptr [ebp+arg_8]
                xor     edx, edx
                mov     dl, byte ptr [ebp+arg_8+1]
                not     eax
                and     eax, esi
                mov     eax, _myextern_array[eax*4]
                xor     eax, ecx
                xor     edx, eax
                and     edx, esi
                sar     eax, 8
                and     eax, ecx
                xor     eax, _myextern_array[edx*4]
                xor     edx, edx
                mov     dl, byte ptr [ebp+arg_8+2]
                xor     edx, eax
                sar     eax, 8
                and     edx, esi
                and     eax, ecx
                xor     eax, _myextern_array[edx*4]
                xor     edx, edx
                mov     dl, byte ptr [ebp+arg_8+3]
                xor     edx, eax
                sar     eax, 8
                and     edx, esi
                and     eax, ecx
                xor     eax, _myextern_array[edx*4]
                mov     edi, eax

loc_526F89:                             ; CODE XREF: memcheck1+16j
                mov     edx, [ebp+arg_0]
                mov     eax, [ebp+arg_4]
                add     eax, edx
                cmp     edx, eax
                jnb     short loc_526FB0
                push    ebx

loc_526F96:                             ; CODE XREF: memcheck1+8Fj
                xor     ebx, ebx
                mov     bl, [edx]
                xor     ebx, edi
                sar     edi, 8
                and     ebx, esi
                and     edi, ecx
                xor     edi, _myextern_array[ebx*4]
                inc     edx
                cmp     edx, eax
                jb      short loc_526F96
                pop     ebx

loc_526FB0:                             ; CODE XREF: memcheck1+75j
                mov     eax, edi
                pop     edi
                not     eax
                pop     esi
                pop     ebp
                retn

__MemChecker1   endp

_TEXT   ENDS
END
