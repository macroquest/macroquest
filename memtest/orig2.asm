        TITLE orig.asm
        .386P

EXTRN _myextern_array:DWORD

_TEXT   SEGMENT PARA USE32 PUBLIC 'CODE'

PUBLIC __MemChecker2



__MemChecker2   proc near               ; CODE XREF: Win__CodeCrc+17p
                                        ; Win__CodeCrc+30_p ...

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch

                mov     ecx, [esp+arg_8]
                xor     eax, eax
                mov     al, cl
                movzx   ecx, ch
                push    esi
                not     eax
                and     eax, 0FFh
                mov     eax, _myextern_array[eax*4]
                xor     eax, 0FFFFFFh
                xor     ecx, eax
                and     ecx, 0FFh
                mov     edx, _myextern_array[ecx*4]
                mov     ecx, [esp+4+arg_8]
                sar     eax, 8
                and     eax, 0FFFFFFh
                xor     eax, edx
                shr     ecx, 10h
                xor     edx, edx
                mov     dl, cl
                movzx   ecx, ch
                xor     edx, eax
                sar     eax, 8
                and     edx, 0FFh
                mov     esi, _myextern_array[edx*4]
                mov     edx, [esp+4+arg_4]
                and     eax, 0FFFFFFh
                xor     eax, esi
                xor     ecx, eax
                and     ecx, 0FFh
                mov     esi, _myextern_array[ecx*4]
                mov     ecx, [esp+4+arg_0]
                sar     eax, 8
                and     eax, 0FFFFFFh
                xor     eax, esi
                lea     esi, [ecx+edx]
                cmp     ecx, esi
                jnb     short loc_50F5AB
                push    edi

loc_50F588:                             ; CODE XREF: __MemChecker2+A8j
                xor     edx, edx
                mov     dl, [ecx]
                xor     edx, eax
                sar     eax, 8
                and     edx, 0FFh
                mov     edi, _myextern_array[edx*4]
                and     eax, 0FFFFFFh
                xor     eax, edi
                inc     ecx
                cmp     ecx, esi
                jb      short loc_50F588
                pop     edi

loc_50F5AB:                             ; CODE XREF: __MemChecker2+85j
                not     eax
                pop     esi
                retn
__MemChecker2   endp





_TEXT   ENDS
END
