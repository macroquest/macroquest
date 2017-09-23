        TITLE orig.asm
        .386P

EXTRN _myextern_array:DWORD
__EncryptPad3 EQU _myextern_array

_TEXT   SEGMENT PARA USE32 PUBLIC 'CODE'

PUBLIC __MemChecker3

__MemChecker3   proc near               ; CODE XREF: SecurityCrc2(int)+17p
                                        ; SecurityCrc2(int)+30rp ...

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
                mov     eax, __EncryptPad3[eax*4]
                xor     eax, 0FFFFFFh
                xor     ecx, eax
                and     ecx, 0FFh
                mov     edx, __EncryptPad3[ecx*4]
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
                mov     esi, __EncryptPad3[edx*4]
                mov     edx, [esp+4+arg_4]
                and     eax, 0FFFFFFh
                xor     eax, esi
                xor     ecx, eax
                and     ecx, 0FFh
                mov     esi, __EncryptPad3[ecx*4]
                mov     ecx, [esp+4+arg_0]
                sar     eax, 8
                and     eax, 0FFFFFFh
                xor     eax, esi
                lea     esi, [ecx+edx]
                cmp     ecx, esi
                jnb     short loc_55F5BB
                push    edi

loc_55F598:                             ; CODE XREF: __MemChecker3+A8j
                xor     edx, edx
                mov     dl, [ecx]
                xor     edx, eax
                sar     eax, 8
                and     edx, 0FFh
                mov     edi, __EncryptPad3[edx*4]
                and     eax, 0FFFFFFh
                xor     eax, edi
                inc     ecx
                cmp     ecx, esi
                jb      short loc_55F598
                pop     edi

loc_55F5BB:                             ; CODE XREF: __MemChecker3+85j
                not     eax
                pop     esi
                retn
__MemChecker3   endp



_TEXT   ENDS
END
