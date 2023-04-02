
section .text

; The original vtable that we are jumping to
; eqlib::CSidlScreenWnd::VirtualFunctionTable * eqlib::detail::CXWndTrampoline<eqlib::MapViewMap>::s_originalVTable
%define VTABLE ?s_originalVTable@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@2PEAUVirtualFunctionTable@CSidlScreenWnd@3@EA
extern VTABLE

%macro make_override 2
	global %2
	%2:
		mov rax, [rel VTABLE]
		jmp [rax + %1]

%endmacro

%ifdef TEST

; Test has a different vtable setup currently.

make_override 0x0, ?IsValid@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NXZ
; intentionally skipped destructor because we can't make this one ourselves.
make_override 0x10, ?GetWndClassName@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEBDXZ
make_override 0x18, ?DrawNC@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHXZ
make_override 0x20, ?Draw@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x28, ?PostDraw@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x30, ?DrawCursor@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@AEBVCXRect@3@AEA_N@Z
make_override 0x38, ?DrawChildItem@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHPEBVCXWnd@3@PEAX@Z
make_override 0x40, ?DrawCaret@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHXZ
make_override 0x48, ?DrawBackground@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHXZ
make_override 0x50, ?DrawTooltip@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHPEBVCXWnd@3@@Z
make_override 0x58, ?DrawTooltipAtPoint@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHAEBVCXPoint@3@AEBVCXStr@3@@Z
make_override 0x60, ?GetMinimizedRect@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@XZ
make_override 0x68, ?DrawTitleBar@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHAEBVCXRect@3@@Z
make_override 0x70, ?SetZLayer@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXH@Z
make_override 0x78, ?GetCursorToDisplay@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEAUHICON__@@XZ
make_override 0x80, ?HandleLButtonDown@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0x88, ?HandleLButtonUp@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0x90, ?HandleLButtonHeld@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0x98, ?HandleLButtonUpAfterHeld@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xa0, ?HandleRButtonDown@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xa8, ?HandleRButtonUp@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xb0, ?HandleRButtonHeld@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xb8, ?HandleRButtonUpAfterHeld@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xc0, ?HandleWheelButtonDown@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xc8, ?HandleWheelButtonUp@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xd0, ?HandleMouseMove@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xd8, ?HandleWheelMove@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@HI@Z
make_override 0xe0, ?HandleKeyboardMsg@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHII_N@Z
make_override 0xe8, ?HandleMouseLeave@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0xf0, ?OnDragDrop@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHPEAUSDragDropInfo@3@@Z
make_override 0xf8, ?GetDragDropCursor@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEAUHICON__@@PEAUSDragDropInfo@3@@Z
make_override 0x100, ?QueryDropOK@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NPEAUSDragDropInfo@3@@Z
make_override 0x108, ?OnClickStick@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHPEAVCClickStickInfo@3@I_N@Z
make_override 0x110, ?GetClickStickCursor@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEAUHICON__@@PEAVCClickStickInfo@3@@Z	
make_override 0x118, ?QueryClickStickDropOK@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NPEAVCClickStickInfo@3@@Z
make_override 0x120, ?WndNotification@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHPEAVCXWnd@3@IPEAX@Z
make_override 0x128, ?OnWndNotification@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x130, ?Activate@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x138, ?Deactivate@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x140, ?OnShow@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x148, ?OnMove@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXRect@3@@Z
make_override 0x150, ?OnResize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHHH@Z
make_override 0x158, ?OnBeginMoveOrResize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x160, ?OnCompleteMoveOrResize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x168, ?OnMinimizeBox@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x170, ?OnMaximizeBox@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x178, ?OnTileBox@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x180, ?OnTile@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x188, ?OnSetFocus@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHPEAVCXWnd@3@@Z
make_override 0x190, ?OnKillFocus@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHPEAVCXWnd@3@@Z
make_override 0x198, ?OnProcessFrame@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x1a0, ?OnVScroll@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHW4EScrollCode@3@H@Z
make_override 0x1a8, ?OnHScroll@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHW4EScrollCode@3@H@Z
make_override 0x1b0, ?OnBroughtToTop@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ	
make_override 0x1b8, ?OnActivate@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHPEAVCXWnd@3@@Z
make_override 0x1c0, ?Show@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAH_N00@Z
make_override 0x1c8, ?AboutToShow@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAA_NXZ
make_override 0x1d0, ?AboutToHide@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAA_NXZ
make_override 0x1d8, ?RequestDockInfo@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHIPEAVCXWnd@3@PEAVCXRect@3@@Z
make_override 0x1e0, ?GetTooltip@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXStr@3@XZ
make_override 0x1e8, ?Unknown0x0EC@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x1f0, ?SetLocked@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAX_N@Z
make_override 0x1f8, ?HitTest@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHAEBVCXPoint@3@PEAH@Z
make_override 0x200, ?GetHitTestRect@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@H@Z
make_override 0x208, ?GetInnerRect@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@XZ
make_override 0x210, ?GetClientRect@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@XZ
make_override 0x218, ?GetClientClipRect@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@XZ
make_override 0x220, ?GetMinSize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXSize@3@_N@Z
make_override 0x228, ?GetMaxSize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXSize@3@_N@Z
make_override 0x230, ?GetUntileSize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXSize@3@XZ
make_override 0x238, ?IsPointTransparent@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NAEBVCXPoint@3@@Z
make_override 0x240, ?ShouldProcessChildrenFrames@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NXZ
make_override 0x248, ?ShouldProcessControllerFrame@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NXZ
make_override 0x250, ?SetDrawTemplate@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXPEAVCXWndDrawTemplate@3@@Z
make_override 0x258, ?SetBGType@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXI@Z
make_override 0x260, ?SetBGColor@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXK@Z
make_override 0x268, ?UpdateGeometry@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXRect@3@_N111@Z
make_override 0x270, ?Move@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@@Z
make_override 0x278, ?Minimize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAH_N@Z
make_override 0x280, ?SetWindowText@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXAEBVCXStr@3@@Z
make_override 0x288, ?SetTooltip@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXAEBVCXStr@3@@Z
make_override 0x290, ?Center@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x298, ?Top@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAX_N@Z
make_override 0x2a0, ?Bottom@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAX_N@Z
make_override 0x2a8, ?Right@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAX_N@Z
make_override 0x2b0, ?Left@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAX_N@Z
make_override 0x2b8, ?GetChildWndAt@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEAVCXWnd@3@AEBVCXPoint@3@_N1@Z
make_override 0x2c0, ?GetSidlPiece@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEAVCScreenPieceTemplate@3@AEBVCXStr@3@_N@Z
make_override 0x2c8, ?GetWindowName@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEBVCXStr@3@XZ
make_override 0x2d0, ?SetVScrollPos@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHH@Z
make_override 0x2d8, ?SetHScrollPos@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHH@Z
make_override 0x2e0, ?AutoSetVScrollPos@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHVCXRect@3@@Z
make_override 0x2e8, ?AutoSetHScrollPos@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHVCXRect@3@@Z
make_override 0x2f0, ?SetAttributesFromSidl@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXPEAVCParamScreenPiece@3@@Z
make_override 0x2f8, ?OnReloadSidl@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x300, ?HasActivatedFirstTimeAlert@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NXZ
make_override 0x308, ?SetHasActivatedFirstTimeAlert@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAX_N@Z
make_override 0x310, ?GetMinClientSize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAAEBVCXSize@3@XZ
make_override 0x318, ?GetMaxClientSize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAAEBVCXSize@3@XZ
make_override 0x320, ?GetActiveEditWnd@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEAVCEditWnd@3@XZ
make_override 0x328, ?UpdateLayout@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAX_N@Z


; CSidlScreenWnd virtual functions
make_override 0x330, ?Unknown0x330@?$CSidlScreenWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXPEBD_N@Z
make_override 0x338, ?OnZone@?$CSidlScreenWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x340, ?OnPreZone@?$CSidlScreenWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x348, ?LoadIniInfo@?$CSidlScreenWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x350, ?StoreIniInfo@?$CSidlScreenWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x358, ?AsSidlScreenWnd@?$CSidlScreenWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAPEAVCSidlScreenWnd@3@XZ
make_override 0x360, ?GetScreenWndType@?$CSidlScreenWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAA_NXZ

%else

make_override 0x0, ?IsValid@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NXZ
; intentionally skipped destructor because we can't make this one ourselves.
make_override 0x10, ?DrawNC@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHXZ
make_override 0x18, ?Draw@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x20, ?PostDraw@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x28, ?DrawCursor@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@AEBVCXRect@3@AEA_N@Z
make_override 0x30, ?DrawChildItem@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHPEBVCXWnd@3@PEAX@Z
make_override 0x38, ?DrawCaret@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHXZ
make_override 0x40, ?DrawBackground@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHXZ
make_override 0x48, ?DrawTooltip@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHPEBVCXWnd@3@@Z
make_override 0x50, ?DrawTooltipAtPoint@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHAEBVCXPoint@3@AEBVCXStr@3@@Z
make_override 0x58, ?GetMinimizedRect@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@XZ
make_override 0x60, ?DrawTitleBar@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHAEBVCXRect@3@@Z
make_override 0x68, ?GetCursorToDisplay@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEAUHICON__@@XZ
make_override 0x70, ?HandleLButtonDown@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0x78, ?HandleLButtonUp@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0x80, ?HandleLButtonHeld@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0x88, ?HandleLButtonUpAfterHeld@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0x90, ?HandleRButtonDown@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0x98, ?HandleRButtonUp@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xa0, ?HandleRButtonHeld@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xa8, ?HandleRButtonUpAfterHeld@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xb0, ?HandleWheelButtonDown@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xb8, ?HandleWheelButtonUp@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xc0, ?HandleMouseMove@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@I@Z
make_override 0xc8, ?HandleWheelMove@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@HI@Z
make_override 0xd0, ?HandleKeyboardMsg@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHII_N@Z
make_override 0xd8, ?HandleMouseLeave@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0xe0, ?OnDragDrop@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHPEAUSDragDropInfo@3@@Z
make_override 0xe8, ?GetDragDropCursor@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEAUHICON__@@PEAUSDragDropInfo@3@@Z
make_override 0xf0, ?QueryDropOK@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NPEAUSDragDropInfo@3@@Z
make_override 0xf8, ?OnClickStick@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHPEAVCClickStickInfo@3@I_N@Z
make_override 0x100, ?GetClickStickCursor@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEAUHICON__@@PEAVCClickStickInfo@3@@Z	
make_override 0x108, ?QueryClickStickDropOK@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NPEAVCClickStickInfo@3@@Z
make_override 0x110, ?WndNotification@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHPEAVCXWnd@3@IPEAX@Z
make_override 0x118, ?OnWndNotification@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x120, ?Activate@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x128, ?Deactivate@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x130, ?OnShow@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x138, ?OnMove@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXRect@3@@Z
make_override 0x140, ?OnResize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHHH@Z
make_override 0x148, ?OnBeginMoveOrResize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x150, ?OnCompleteMoveOrResize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x158, ?OnMinimizeBox@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x160, ?OnMaximizeBox@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x168, ?OnTileBox@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x170, ?OnTile@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x178, ?OnSetFocus@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHPEAVCXWnd@3@@Z
make_override 0x180, ?OnKillFocus@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHPEAVCXWnd@3@@Z
make_override 0x188, ?OnProcessFrame@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x190, ?OnVScroll@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHW4EScrollCode@3@H@Z
make_override 0x198, ?OnHScroll@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHW4EScrollCode@3@H@Z
make_override 0x1a0, ?OnBroughtToTop@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ	
make_override 0x1a8, ?OnActivate@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHPEAVCXWnd@3@@Z
make_override 0x1b0, ?Show@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAH_N00@Z
make_override 0x1b8, ?AboutToShow@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAA_NXZ
make_override 0x1c0, ?AboutToHide@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAA_NXZ
make_override 0x1c8, ?RequestDockInfo@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHIPEAVCXWnd@3@PEAVCXRect@3@@Z
make_override 0x1d0, ?GetTooltip@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXStr@3@XZ
make_override 0x1d8, ?Unknown0x0EC@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x1e0, ?HitTest@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAHAEBVCXPoint@3@PEAH@Z
make_override 0x1e8, ?GetHitTestRect@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@H@Z
make_override 0x1f0, ?GetInnerRect@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@XZ
make_override 0x1f8, ?GetClientRect@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@XZ
make_override 0x200, ?GetClientClipRect@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXRect@3@XZ
make_override 0x208, ?GetMinSize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXSize@3@_N@Z
make_override 0x210, ?GetMaxSize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXSize@3@_N@Z
make_override 0x218, ?GetUntileSize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA?AVCXSize@3@XZ
make_override 0x220, ?IsPointTransparent@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NAEBVCXPoint@3@@Z
make_override 0x228, ?ShouldProcessChildrenFrames@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NXZ
make_override 0x230, ?ShouldProcessControllerFrame@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NXZ
make_override 0x238, ?SetDrawTemplate@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXPEAVCXWndDrawTemplate@3@@Z
make_override 0x240, ?UpdateGeometry@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXRect@3@_N111@Z
make_override 0x248, ?Move@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHAEBVCXPoint@3@@Z
make_override 0x250, ?SetWindowText@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXAEBVCXStr@3@@Z
make_override 0x258, ?GetChildWndAt@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEAVCXWnd@3@AEBVCXPoint@3@_N1@Z
make_override 0x260, ?GetSidlPiece@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEAVCScreenPieceTemplate@3@AEBVCXStr@3@_N@Z
make_override 0x268, ?GetWindowName@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEBVCXStr@3@XZ
make_override 0x270, ?SetVScrollPos@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHH@Z
make_override 0x278, ?SetHScrollPos@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHH@Z
make_override 0x280, ?AutoSetVScrollPos@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHVCXRect@3@@Z
make_override 0x288, ?AutoSetHScrollPos@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHVCXRect@3@@Z
make_override 0x290, ?SetAttributesFromSidl@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXPEAVCParamScreenPiece@3@@Z	
make_override 0x298, ?OnReloadSidl@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x2a0, ?HasActivatedFirstTimeAlert@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBA_NXZ
make_override 0x2a8, ?SetHasActivatedFirstTimeAlert@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAX_N@Z
make_override 0x2b0, ?GetMinClientSize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAAEBVCXSize@3@XZ
make_override 0x2b8, ?GetMaxClientSize@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAAEBVCXSize@3@XZ
make_override 0x2c0, ?GetActiveEditWnd@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEBAPEAVCEditWnd@3@XZ
make_override 0x2c8, ?UpdateLayout@?$CXWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAX_N@Z


; CSidlScreenWnd virtual functions

make_override 0x2d0, ?OnZone@?$CSidlScreenWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x2d8, ?OnPreZone@?$CSidlScreenWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAHXZ
make_override 0x2e0, ?LoadIniInfo@?$CSidlScreenWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x2e8, ?StoreIniInfo@?$CSidlScreenWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAXXZ
make_override 0x2f0, ?AsSidlScreenWnd@?$CSidlScreenWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAAPEAVCSidlScreenWnd@3@XZ
make_override 0x2f8, ?GetScreenWndType@?$CSidlScreenWndTrampoline@VMapViewMap@eqlib@@@detail@eqlib@@UEAA_NXZ

%endif
