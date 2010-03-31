        TITLE orig.asm
        .386P

EXTRN _myextern_array:DWORD

_TEXT   SEGMENT PARA USE32 PUBLIC 'CODE'


ub_4A403E      proc near               ; CODE XREF: sub_42B5EF+306p
                                        ; __MemChecker2+4F2p ...
                xor     eax, eax
                retn
ub_4A403E      endp


PUBLIC __MemChecker3
__MemChecker3   proc near

arg_0           = dword ptr  8
arg_4           = dword ptr  0Ch
arg_8           = byte ptr  10h
arg_9           = byte ptr  11h
arg_A           = byte ptr  12h
arg_B           = byte ptr  13h

                push    ebp
                mov     ebp, esp
                xor     eax, eax
                mov     al, [ebp+arg_8]
                xor     edx, edx
                mov     dl, [ebp+arg_9]
                push    esi
                mov     esi, 0FFh
                mov     ecx, 0FFFFFFh
                push    edi
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
                mov     dl, [ebp+arg_A]
                mov     edi, [ebp+arg_4]
                xor     edx, eax
                sar     eax, 8
                and     edx, esi
                and     eax, ecx
                xor     eax, _myextern_array[edx*4]
                xor     edx, edx
                mov     dl, [ebp+arg_B]
                xor     edx, eax
                sar     eax, 8
                and     edx, esi
                and     eax, ecx
                xor     eax, _myextern_array[edx*4]
                mov     edx, [ebp+arg_0]
                add     edi, edx
                cmp     edx, edi
                jnb     short loc_52AED7
                push    ebx

loc_52AEBD:                             ; CODE XREF: memcheck3+84j
                xor     ebx, ebx
                mov     bl, [edx]
                xor     ebx, eax
                sar     eax, 8
                and     ebx, esi
                and     eax, ecx
                xor     eax, _myextern_array[ebx*4]
                inc     edx
                cmp     edx, edi
                jb      short loc_52AEBD
                pop     ebx

loc_52AED7:                             ; CODE XREF: memcheck3+6Aj
                pop     edi
                not     eax
                pop     esi
                pop     ebp
                retn


__MemChecker3   endp

_TEXT   ENDS
END
