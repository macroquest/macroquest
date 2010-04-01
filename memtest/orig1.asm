        TITLE orig.asm
        .386P

EXTRN _myextern_array:DWORD
__EncryptPad1 EQU _myextern_array

_TEXT   SEGMENT PARA USE32 PUBLIC 'CODE'


__MemChecker1   proc near               ; CODE XREF: sub_5ED2A0+20p
                                        ; sub_5F5750+1B5_p

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch

                mov     ecx, [esp+arg_8]
                or      eax, 0FFFFFFFFh
                test    ecx, ecx
                push    esi
                jz      short loc_5ED25F
                xor     eax, eax
                mov     al, cl
                movzx   ecx, ch
                not     eax
                and     eax, 0FFh
                mov     eax, __EncryptPad1[eax*4]
                xor     eax, 0FFFFFFh
                xor     ecx, eax
                and     ecx, 0FFh
                mov     edx, __EncryptPad1[ecx*4]
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
                mov     esi, __EncryptPad1[edx*4]
                and     eax, 0FFFFFFh
                xor     eax, esi
                xor     ecx, eax
                and     ecx, 0FFh
                mov     edx, __EncryptPad1[ecx*4]
                sar     eax, 8
                and     eax, 0FFFFFFh
                xor     eax, edx

loc_5ED25F:                             ; CODE XREF: __MemChecker1+Aj
                mov     ecx, [esp+4+arg_0]
                mov     edx, [esp+4+arg_4]
                lea     esi, [ecx+edx]
                cmp     ecx, esi
                jnb     short loc_5ED293
                push    edi
                nop

loc_5ED270:                             ; CODE XREF: __MemChecker1+B0j
                xor     edx, edx
                mov     dl, [ecx]
                xor     edx, eax
                sar     eax, 8
                and     edx, 0FFh
                mov     edi, __EncryptPad1[edx*4]
                and     eax, 0FFFFFFh
                xor     eax, edi
                inc     ecx
                cmp     ecx, esi
                jb      short loc_5ED270
                pop     edi

loc_5ED293:                             ; CODE XREF: __MemChecker1+8Cj
                not     eax
                pop     esi
                retn
__MemChecker1   endp



_TEXT   ENDS
END
