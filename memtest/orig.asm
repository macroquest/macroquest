        TITLE orig.asm
        .386P

EXTRN _myextern_array:DWORD
__EncryptPad0 EQU _myextern_array

_TEXT   SEGMENT PARA USE32 PUBLIC 'CODE'


__MemChecker0   proc near               ; CODE XREF: EQChecksumFile(char *,int *)+80p
                                        ; SendSpellChecksum(UdpLibrary::UdpConnection *)+AAp ...

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                push    esi
                mov     esi, [esp+4+arg_4]
                or      eax, 0FFFFFFFFh
                xor     edx, edx
                test    esi, esi
                jle     short loc_509A33
                push    ebx
                push    edi
                mov     edi, [esp+0Ch+arg_0]

loc_509A14:                             ; CODE XREF: __MemChecker0+2Fj
                movsx   ecx, byte ptr [edx+edi]
                xor     ecx, eax
                and     ecx, 0FFh
                mov     ebx, __EncryptPad0[ecx*4]
                shr     eax, 8
                inc     edx
                xor     eax, ebx
                cmp     edx, esi
                jl      short loc_509A14
                pop     edi
                pop     ebx

loc_509A33:                             ; CODE XREF: __MemChecker0+Cj
                pop     esi
                retn
__MemChecker0   endp


_TEXT   ENDS
END
