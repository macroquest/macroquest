        TITLE orig.asm
        .386P

EXTRN _myextern_array:DWORD
__EncryptPad0 EQU _myextern_array

_TEXT   SEGMENT PARA USE32 PUBLIC 'CODE'


__MemChecker0   proc near               ; CODE XREF: EQMisc__EQChecksumFile+80p
                                        ; EQMisc__SendSpellChecksum+A6p ...

arg_0           = dword ptr  8
arg_4           = dword ptr  0Ch

                push    esi
                mov     esi, [esp+arg_4]
                or      eax, 0FFFFFFFFh
                xor     edx, edx
                test    esi, esi
                jle     short loc_4E0CC3
                push    ebx
                push    edi
                mov     edi, [esp+8+arg_0]

loc_4E0CA4:                             ; CODE XREF: __MemChecker0+2Fj
                movsx   ecx, byte ptr [edx+edi]
                xor     ecx, eax
                and     ecx, 0FFh
                mov     ebx, __EncryptPad0[ecx*4]
                shr     eax, 8
                inc     edx
                xor     eax, ebx
                cmp     edx, esi
                jl      short loc_4E0CA4
                pop     edi
                pop     ebx

loc_4E0CC3:                             ; CODE XREF: __MemChecker0+Cj
                pop     esi
                retn
__MemChecker0   endp


_TEXT   ENDS
END
