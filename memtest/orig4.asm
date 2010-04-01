        TITLE orig.asm
        .386P

EXTRN _myextern_array:DWORD

_TEXT   SEGMENT PARA USE32 PUBLIC 'CODE'

PUBLIC __MemChecker4

__MemChecker4   proc near               ; CODE XREF: sub_5E6360+161p
                                        ; sub_5E7F40+20Bp

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch

                mov     ecx, [esp+arg_8]
                mov     eax, ecx
                not     eax
                and     eax, 0FFh
                mov     eax, _myextern_array[eax*4]
                xor     eax, 0FFFFFFh
                mov     edx, ecx
                sar     edx, 8
                xor     edx, eax
                sar     eax, 8
                and     edx, 0FFh
                and     eax, 0FFFFFFh
                push    esi
                xor     eax, _myextern_array[edx*4]
                mov     edx, ecx
                sar     edx, 10h
                xor     edx, eax
                sar     eax, 8
                and     edx, 0FFh
                mov     esi, _myextern_array[edx*4]
                mov     edx, [esp+4+arg_4]
                and     eax, 0FFFFFFh
                xor     eax, esi
                sar     ecx, 18h
                xor     ecx, eax
                and     ecx, 0FFh
                mov     esi, _myextern_array[ecx*4]
                mov     ecx, [esp+4+arg_0]
                sar     eax, 8
                and     eax, 0FFFFFFh
                xor     eax, esi
                lea     esi, [ecx+edx]
                cmp     ecx, esi
                jnb     short loc_600AD3
                push    edi

loc_600AB0:                             ; CODE XREF: __MemChecker4+A0j
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
                jb      short loc_600AB0
                pop     edi

loc_600AD3:                             ; CODE XREF: __MemChecker4+7Dj
                not     eax
                pop     esi
                retn
__MemChecker4   endp



_TEXT   ENDS
END
