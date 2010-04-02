        TITLE orig.asm
        .386P

EXTRN _myextern_array:DWORD
__EncryptPad1 EQU _myextern_array
crc32_table EQU _myextern_array

_TEXT   SEGMENT PARA USE32 PUBLIC 'CODE'



__MemChecker1   proc near               ; CODE XREF: sub_62FB70+203p
                                        ; sub_6600E0+20bp

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch

                mov     ecx, [esp+arg_8]
                or      eax, 0FFFFFFFFh
                test    ecx, ecx
                push    esi
                jz      short loc_665B3F
                xor     eax, eax
                mov     al, cl
                movzx   ecx, ch
                not     eax
                and     eax, 0FFh
                mov     eax, crc32_table[eax*4]
                xor     eax, 0FFFFFFh
                xor     ecx, eax
                and     ecx, 0FFh
                mov     edx, crc32_table[ecx*4]
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
                mov     esi, crc32_table[edx*4]
                and     eax, 0FFFFFFh
                xor     eax, esi
                xor     ecx, eax
                and     ecx, 0FFh
                mov     edx, crc32_table[ecx*4]
                sar     eax, 8
                and     eax, 0FFFFFFh
                xor     eax, edx

loc_665B3F:                             ; CODE XREF: CRC::GetBufferCRC(void const *,uint,int)+Aj
                mov     ecx, [esp+4+arg_0]
                mov     edx, [esp+4+arg_4]
                lea     esi, [ecx+edx]
                cmp     ecx, esi
                jnb     short loc_665B73
                push    edi
                nop

loc_665B50:                             ; CODE XREF: CRC::GetBufferCRC(void const *,uint,int)+B0j
                xor     edx, edx
                mov     dl, [ecx]
                xor     edx, eax
                sar     eax, 8
                and     edx, 0FFh
                mov     edi, crc32_table[edx*4]
                and     eax, 0FFFFFFh
                xor     eax, edi
                inc     ecx
                cmp     ecx, esi
                jb      short loc_665B50
                pop     edi

loc_665B73:                             ; CODE XREF: CRC::GetBufferCRC(void const *,uint,int)+8Cj
                not     eax
                pop     esi
                retn

__MemChecker1   endp






_TEXT   ENDS
END
