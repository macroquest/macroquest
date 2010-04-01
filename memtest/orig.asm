        TITLE orig.asm
        .386P

EXTRN _myextern_array:DWORD

_TEXT   SEGMENT PARA USE32 PUBLIC 'CODE'

PUBLIC __MemChecker0


__MemChecker0   proc near               ; CODE XREF: sub_4656C2+71p
                                        ; sub_46DD41+B5p ...

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                xor     edx, edx
                or      eax, 0FFFFFFFFh
                cmp     [esp+arg_4], edx
                jle     short locret_4B6C13

loc_4B6BF2:                             ; CODE XREF: __MemChecker0+2Aj
                mov     ecx, [esp+arg_0]
                movsx   ecx, byte ptr [edx+ecx]
                xor     ecx, eax
                and     ecx, 0FFh
                shr     eax, 8
                xor     eax, _myextern_array[ecx*4]
                inc     edx
                cmp     edx, [esp+arg_4]
                jl      short loc_4B6BF2

locret_4B6C13:                          ; CODE XREF: __MemChecker0+9j
                retn
__MemChecker0   endp













_TEXT   ENDS
END
