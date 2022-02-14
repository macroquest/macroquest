
section .text

; The original vtable that we are jumping to
; eqlib::CSidlScreenWnd::VirtualFunctionTable * eqlib::detail::CXWndTrampoline<eqlib::CItemDisplayWnd>::s_originalVTable
%define VTABLE ?s_originalVTable@?$CXWndTrampoline@VCItemDisplayWnd@eqlib@@@detail@eqlib@@2PEAUVirtualFunctionTable@CSidlScreenWnd@3@EA
extern VTABLE

%macro make_override 2
	global %2
	%2:
		mov rax, [rel VTABLE]
		jmp [rax + %1]

%endmacro


; virtual class eqlib::CXRect eqlib::detail::CXWndTrampoline<class eqlib::CItemDisplayWnd>::GetMinimizedRect(void)const
make_override 0x58, ?GetMinimizedRect@?$CXWndTrampoline@VCItemDisplayWnd@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@XZ

; virtual class eqlib::CXStr eqlib::detail::CXWndTrampoline<class eqlib::CItemDisplayWnd>::GetTooltip(void)const
make_override 0x1D0, ?GetTooltip@?$CXWndTrampoline@VCItemDisplayWnd@eqlib@@@detail@eqlib@@UEBA?AVCXStr@3@XZ

; virtual class eqlib::CXRect eqlib::detail::CXWndTrampoline<class eqlib::CItemDisplayWnd>::GetHitTestRect(int)const
make_override 0x1E8, ?GetHitTestRect@?$CXWndTrampoline@VCItemDisplayWnd@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@H@Z

; virtual class eqlib::CXRect eqlib::detail::CXWndTrampoline<class eqlib::CItemDisplayWnd>::GetInnerRect(void)const
make_override 0x1F0, ?GetInnerRect@?$CXWndTrampoline@VCItemDisplayWnd@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@XZ

; virtual class eqlib::CXRect eqlib::detail::CXWndTrampoline<class eqlib::CItemDisplayWnd>::GetClientRect(void)const
make_override 0x1F8, ?GetClientRect@?$CXWndTrampoline@VCItemDisplayWnd@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@XZ

; virtual class eqlib::CXRect eqlib::detail::CXWndTrampoline<class eqlib::CItemDisplayWnd>::GetClientClipRect(void)const
make_override 0x200, ?GetClientClipRect@?$CXWndTrampoline@VCItemDisplayWnd@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@XZ

; virtual class eqlib::CXSize eqlib::detail::CXWndTrampoline<class eqlib::CItemDisplayWnd>::GetMinSize(bool)const
make_override 0x208, ?GetMinSize@?$CXWndTrampoline@VCItemDisplayWnd@eqlib@@@detail@eqlib@@UEBA?AVCXSize@3@_N@Z

; virtual class eqlib::CXSize eqlib::detail::CXWndTrampoline<class eqlib::CItemDisplayWnd>::GetMaxSize(bool)const
make_override 0x210, ?GetMaxSize@?$CXWndTrampoline@VCItemDisplayWnd@eqlib@@@detail@eqlib@@UEBA?AVCXSize@3@_N@Z

; virtual class eqlib::CXSize eqlib::detail::CXWndTrampoline<class eqlib::CItemDisplayWnd>::GetUntileSize(void)const
make_override 0x218, ?GetUntileSize@?$CXWndTrampoline@VCItemDisplayWnd@eqlib@@@detail@eqlib@@UEBA?AVCXSize@3@XZ















