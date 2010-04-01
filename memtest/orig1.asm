        TITLE orig.asm
        .386P

EXTRN _myextern_array:DWORD

_TEXT   SEGMENT PARA USE32 PUBLIC 'CODE'

__MemChecker1   proc near               ; CODE XREF: sub_5EC2D0+20p
                                        ; sub_5F4710+1B5_p

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch

                mov     ecx, [esp+arg_8]
                or      eax, 0FFFFFFFFh
                test    ecx, ecx
                push    esi
                jz      short loc_5EC28F
                xor     eax, eax
                mov     al, cl
                movzx   ecx, ch
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
                and     eax, 0FFFFFFh
                xor     eax, esi
                xor     ecx, eax
                and     ecx, 0FFh
                mov     edx, _myextern_array[ecx*4]
                sar     eax, 8
                and     eax, 0FFFFFFh
                xor     eax, edx

loc_5EC28F:                             ; CODE XREF: __MemChecker1+Aj
                mov     ecx, [esp+4+arg_0]
                mov     edx, [esp+4+arg_4]
                lea     esi, [ecx+edx]
                cmp     ecx, esi
                jnb     short loc_5EC2C3
                push    edi
                nop

loc_5EC2A0:                             ; CODE XREF: __MemChecker1+B0j
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
                jb      short loc_5EC2A0
                pop     edi

loc_5EC2C3:                             ; CODE XREF: __MemChecker1+8Cj
                not     eax
                pop     esi
                retn
__MemChecker1   endp

; ---------------------------------------------------------------------------
                align 10h

; ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦ S U B R O U T I N e ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦


sub_5EC2D0      proc near               ; CODE XREF: EQPlayer__LoadPlayerAnims+ECp
                                        ; sub_4028A0+1A5p ...

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                mov     edx, [esp+arg_0]
                mov     eax, edx
                push    esi
                lea     esi, [eax+1]
                lea     ebx, [ebx+0]

loc_5EC2E0:                             ; CODE XREF: sub_5EC2D0+15j
                mov     cl, [eax]
                inc     eax
                test    cl, cl
                jnz     short loc_5EC2E0
                mov     ecx, [esp+4+arg_4]
                push    ecx
                sub     eax, esi
                push    eax
                push    edx
                call    __MemChecker1
                add     esp, 0Ch
                pop     esi
                retn
sub_5EC2D0      endp



_TEXT   ENDS
END
