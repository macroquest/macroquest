;---------------------------------------------------------------------------------------

extern _CXWnd__CXWnd
extern _CSidlScreenWnd__CSidlScreenWnd1
extern _CSidlScreenWnd__CSidlScreenWnd2

section .text

; eqlib::CXWnd::CXWnd
global ??0CXWnd@eqlib@@QAE@PAV01@IUCXRect@1@@Z
??0CXWnd@eqlib@@QAE@PAV01@IUCXRect@1@@Z:
	mov eax, [_CXWnd__CXWnd]
	jmp [eax]

;---------------------------------------------------------------------------------------

; eqlib::CSidlScreenWnd::CSidlScreenWnd
global ??0CSidlScreenWnd@eqlib@@QAE@PAVCXWnd@1@ABVCXStr@1@@Z
??0CSidlScreenWnd@eqlib@@QAE@PAVCXWnd@1@ABVCXStr@1@@Z:
	mov eax, [_CSidlScreenWnd__CSidlScreenWnd1]
	jmp [eax]

;---------------------------------------------------------------------------------------

; eqlib::CSidlScreenWnd::CSidlScreenWnd
global ??0CSidlScreenWnd@eqlib@@QAE@PAVCXWnd@1@ABVCXStr@1@HHPAD@Z
??0CSidlScreenWnd@eqlib@@QAE@PAVCXWnd@1@ABVCXStr@1@HHPAD@Z:
	mov eax, [_CSidlScreenWnd__CSidlScreenWnd2]
	jmp [eax]
