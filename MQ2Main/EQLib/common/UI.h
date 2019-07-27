/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include "Common.h"
#include "CXStr.h"
#include "CXWnd.h"
#include "Containers.h"

namespace eqlib {

//----------------------------------------------------------------------------
// Forward Declarations

class CButtonWnd;
class CLabel;

//----------------------------------------------------------------------------

class WndEventHandler
{
	unsigned int lastUpdate;

public:
};

//============================================================================
// CUITexturePiece
//============================================================================

enum enDir
{
	cUIDirectory,
	cUIDirectoryAtlas,
	cUIDirectoryTexture,
	cUIDirectoryMaps,

	cUIDirectoryCount,
};

struct CUITextureInfo
{
public:
	EQLIB_OBJECT CUITextureInfo();
	EQLIB_OBJECT CUITextureInfo(const CXStr& name, int size);
	EQLIB_OBJECT CUITextureInfo(const CXStr& name, const CXSize& size);
	EQLIB_OBJECT CUITextureInfo(uint32_t id, int size);
	EQLIB_OBJECT CUITextureInfo(uint32_t id, const CXSize& size);

	//EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, const CXRect&, D3DCOLOR*, D3DCOLOR*) const;
	//EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, const CXRect&, D3DCOLOR, D3DCOLOR) const;
	//EQLIB_OBJECT int Preload();
	//EQLIB_OBJECT int Tile(const CXRect&, D3DCOLOR*, D3DCOLOR*) const;
	//EQLIB_OBJECT int Tile(const CXRect&, D3DCOLOR, D3DCOLOR) const;

	//----------------------------------------------------------------------------
	// data members
/*0x00*/ bool          bValid = false;
/*0x04*/ enDir         Directory = cUIDirectory;
/*0x08*/ CXStr         Name;
/*0x0c*/ CXSize        TextureSize;
/*0x14*/ uint32_t      TextureId = -1;
/*0x18*/
};

class CUITexturePiece
{
public:
	EQLIB_OBJECT CUITexturePiece();
	EQLIB_OBJECT CUITexturePiece(const CUITextureInfo&, const CXRect&);
	EQLIB_OBJECT CUITexturePiece(const CUITextureInfo&);

	//EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, const CXRect&, D3DCOLOR, D3DCOLOR) const;
	//EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, D3DCOLOR, D3DCOLOR) const;

	const CUITextureInfo& GetTextureInfo() const { return m_info; }
	CXSize GetSize() const { return m_rect.GetSize(); }
	const CXRect& GetRect() const { return m_rect; }

private:
/*0x00*/ CUITextureInfo      m_info;
/*0x18*/ CXRect              m_rect;
/*0x28*/
};

//============================================================================
// CTextureAnimation
//============================================================================

struct STextureAnimationFrame
{
/*0x00*/ CUITexturePiece    Piece;
/*0x28*/ uint32_t           Ticks = 0;
/*0x2c*/ CXPoint            Hotspot;
/*0x34*/
};

class CTextureAnimation
{
public:
	EQLIB_OBJECT CTextureAnimation();
	EQLIB_OBJECT CTextureAnimation(const CXStr& name);
	EQLIB_OBJECT CTextureAnimation(CUITexturePiece tp);
	EQLIB_OBJECT virtual ~CTextureAnimation();

	EQLIB_OBJECT int AddFrame(const CUITextureInfo* ti, const CXRect& rect, uint32_t ticks, CXPoint hotspot = {});
	EQLIB_OBJECT int AddFrame(CUITexturePiece tp, uint32_t ticks, CXPoint hotspot = {});
	EQLIB_OBJECT int AddBlankFrame(uint32_t ticks, CXPoint hotspot = {});
	EQLIB_OBJECT void SetCurFrame(int);
	EQLIB_OBJECT int GetCurFrame() const;
	EQLIB_OBJECT void Pause(bool pause);
	EQLIB_OBJECT CXPoint GetHotspot() const;
	EQLIB_OBJECT const CXStr& GetName() const { return Name; }
	EQLIB_OBJECT void SetCurCell(int);
	EQLIB_OBJECT CXSize GetSize() const { return Size; }

	//EQLIB_OBJECT int Draw(const CXPoint&, const CXRect&, unsigned long, unsigned long) const;
	//EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, unsigned long, unsigned long) const;
	//EQLIB_OBJECT int Preload();
	//EQLIB_OBJECT void Reset();

	//----------------------------------------------------------------------------
	// data members
/*0x04*/ CXStr         Name;
/*0x08*/ ArrayClass<STextureAnimationFrame> Frames;
/*0x18*/ uint32_t           TotalTicks = 0;
/*0x1c*/ int                ZeroFrame = 0;
/*0x20*/ uint32_t           StartTicks = GetTickCount();
/*0x24*/ CXSize             Size;
/*0x2c*/ bool               bPaused = false;
/*0x2d*/ bool               bCycle = true;
/*0x2e*/ bool               bGrid = false;
/*0x2f*/ bool               bVertical = false;
/*0x30*/ int                CellWidth = 0;
/*0x34*/ int                CellHeight = 0;
/*0x38*/ int                CurCell = -1;
/*0x3c*/ CXRect             CellRect;
/*0x4c*/
};

//============================================================================
// CEQSuiteTextureLoader
//============================================================================

enum eBitmapType
{
	eBitmapTypeNormal,
	eBitmapTypeLayer,
	eBitmapType_SingleDetail,
	eBitmapTypePaletteDetailMain,
	eBitmapTypePaletteDetailPalette,
	eBitmapTypePaletteDetailDetail
};

// have to fake these i dont wanna map them now... we dont need them anyway : public CThreadLoader, public TListNode<CEQGBitmap>
class CEQGBitmap
{
public:
	void* vftable;
	BYTE               Header[0x1c];
	eBitmapType        eType;
	int                eMemoryPoolManagerType;   // eMemoryPoolManagerType need to figure out this enum
	char* FileName;
	UINT               SourceWidth;
	UINT               SourceHeight;
	float              DetailScale;
	UINT               GrassDensity;
	UINT               Width;
	UINT               Height;
	bool               bHasTexture;
	union
	{
		void* pD3DTexture;              // IDirect3DBaseTexture9
		void* pRawBitmap;
	};
	UINT               ObjectIndex;
	UINT               Size;
	bool               bForceMipMap;
	int	               TrackingType;
	float              SQDistanceToCamera;
	UINT               LastDistanceTime;
	UINT               LastRenderTime;
	UINT               LoadedTime;
};

struct BMI
{
	char*              Name;
	unsigned int       Flags;
	CEQGBitmap*        pBmp;
};

struct _SuiteTexture
{
	bool               bUsed;
	CXStr              Name;
	enDir              Directory;
	BMI*               pBMInfo;
};

struct SWadFile;

class CEQSuiteTextureLoader
{
public:
	SWadFile*         pWadFile;
	ArrayClass<_SuiteTexture> Textures;
	CXStr              UIPath[cUIDirectoryCount];
	CXStr              DefaultUIPath[cUIDirectoryCount];

	EQLIB_OBJECT CEQSuiteTextureLoader();
	EQLIB_OBJECT ~CEQSuiteTextureLoader();
	EQLIB_OBJECT BMI* GetTexture(const CUITextureInfo& ti);
	EQLIB_OBJECT unsigned int CreateTexture(const CUITextureInfo&);
	EQLIB_OBJECT void UnloadAllTextures();
	EQLIB_OBJECT const CXStr& GetDefaultUIPath(int DirType) const;
};


//============================================================================
// CButtonDrawTemplate
//============================================================================

class CButtonDrawTemplate
{
public:
	EQLIB_OBJECT CButtonDrawTemplate();
	EQLIB_OBJECT ~CButtonDrawTemplate();

	// Returns the appropriate texture to use for the button given the specified properties
	EQLIB_OBJECT CTextureAnimation* GetAnimation(bool pressed, bool hover, bool disabled, bool decal = false) const;
	EQLIB_OBJECT CXSize GetSize() const;

	//----------------------------------------------------------------------------
	// data members
	CXStr              Name;
	CTextureAnimation* Normal = nullptr;
	CTextureAnimation* Pressed = nullptr;
	CTextureAnimation* Flyby = nullptr;
	CTextureAnimation* Disabled = nullptr;
	CTextureAnimation* PressedFlyby = nullptr;
	CTextureAnimation* PressedDisabled = nullptr;
	CTextureAnimation* NormalDecal = nullptr;
	CTextureAnimation* PressedDecal = nullptr;
	CTextureAnimation* FlybyDecal = nullptr;
	CTextureAnimation* DisabledDecal = nullptr;
	CTextureAnimation* PressedFlybyDecal = nullptr;
	CTextureAnimation* PressedDisabledDecal = nullptr;
};

//============================================================================
// CRadioGroup
//============================================================================

class CRadioGroup
{
public:
	EQLIB_OBJECT CRadioGroup(CXStr name = {});
	EQLIB_OBJECT virtual ~CRadioGroup();

	CXStr                    Name;
	ArrayClass<CButtonWnd*>  Buttons;
	int                      CurSel = -1;
	bool                     bAllowMultiSelect = false;
	int                      nSelectionLimit = -1;
	bool                     bAllowNullable = false;
};

//============================================================================
// CButtonWnd
//============================================================================

// CButtonWnd__CButtonWnd_x
// size is 0x290 see 8E0709 in eqgame.exe dated Oct 13 2017 Test
class CButtonWnd : public CXWnd
{
public:
	//----------------------------------------------------------------------------
	// constructor / destructor
	EQLIB_OBJECT CButtonWnd(CXWnd* parent, uint32_t id, const CXRect& rect,
		const CXPoint& decalOffset, const CXSize& decalSize,
		CTextureAnimation* normal, CTextureAnimation* pressed,
		CTextureAnimation* hover, CTextureAnimation* disabled,
		CTextureAnimation* pressedHover, CTextureAnimation* pressedDisabled,
		CTextureAnimation* normalDecal, CTextureAnimation* pressedDecal,
		CTextureAnimation* hoverDecal, CTextureAnimation* pressedDisabledDecal);
	//EQLIB_OBJECT CButtonWnd(CXWnd* parent, uint32_t id, const CXRect& rect);
	//EQLIB_OBJECT CBUttonWnd(CXWnd* parent, uint32_t id, const CXRect& rect, const CXStr& label);
	EQLIB_OBJECT virtual ~CButtonWnd();

	//----------------------------------------------------------------------------
	// virtual functions
	EQLIB_OBJECT virtual void SetRadioGroup(CRadioGroup* group);
	EQLIB_OBJECT virtual int DrawWndText(const CXRect& rect, const CXRect& clip);
	EQLIB_OBJECT virtual int DrawCooldown();
	EQLIB_OBJECT virtual void SetCheck(bool check);
	EQLIB_OBJECT virtual void SetCoolDownCompletionTimeDelta(uint32_t delta, uint32_t total);
	EQLIB_OBJECT virtual void SetCoolDownCompletionTime(uint32_t time, uint32_t total);
	EQLIB_OBJECT virtual void SetCoolDownCompletionTime(time_t time, uint32_t total);
	EQLIB_OBJECT virtual void SetCoolDownBeginTime(uint32_t time, uint32_t total);
	EQLIB_OBJECT virtual void SetCoolDownUpdatedBeginTime(uint32_t time, uint32_t total);
	EQLIB_OBJECT virtual uint32_t GetCoolDownBeginTime() const;
	EQLIB_OBJECT virtual uint32_t GetCoolDownTotalDuration() const;
	EQLIB_OBJECT virtual uint32_t GetCoolDownTimeRemaining() const;
	EQLIB_OBJECT virtual void ClearCoolDownCompletionTime();

	//----------------------------------------------------------------------------
	// inherited virtuals
	EQLIB_OBJECT virtual int Draw() override;
	EQLIB_OBJECT virtual int DrawTooltipAtPoint(const CXPoint& pos, const CXStr& tooltip) const override;
	EQLIB_OBJECT virtual int HandleLButtonDown(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleLButtonUp(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleLButtonHeld(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleLButtonUpAfterHeld(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleRButtonDown(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleRButtonUp(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleRButtonHeld(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleRButtonUpAfterHeld(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleMouseMove(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int OnProcessFrame() override;
	EQLIB_OBJECT virtual bool IsPointTransparent(const CXPoint& point) const override;
	EQLIB_OBJECT virtual void SetAttributesFromSidl(CParamScreenPiece*) override;

	//----------------------------------------------------------------------------
	// data members
/*0x1f8*/ int          MouseButtonState;
/*0x1fc*/ bool         bPicture;
/*0x200*/ CRadioGroup* pGroup;
/*0x204*/ bool         bChecked;
/*0x205*/ bool         bMouseOverLastFrame;
/*0x208*/ CXPoint      DecalOffset;
/*0x210*/ CXSize       DecalSize;
/*0x218*/ COLORREF     DecalTint;                // Color
/*0x21c*/ CXRect       TextOffsets;
/*0x22c*/ int          TextModeBits;
/*0x230*/ COLORREF     Mouseover;
/*0x234*/ COLORREF     Pressed;
/*0x238*/ COLORREF     Disabled;
/*0x23c*/ unsigned int CoolDownBeginTime;
/*0x240*/ unsigned int CoolDownDuration;
/*0x244*/ CXStr        Indicator;
/*0x248*/ unsigned int IndicatorVal;
/*0x24c*/ CTextObjectInterface* pIndicatorTextObject;
/*0x250*/ CButtonDrawTemplate DrawTemplate;
/*0x284*/ bool         bAllowButtonClickThrough;
/*0x285*/ bool         bCoolDownDoDelayedStart;
/*0x286*/ bool         bIsCheckbox;
/*0x287*/ bool         bIsDrawLasso;
/*0x288*/ uint32_t     ButtonStyle;              // tbd
/*0x28c*/ CLabel*      pButtonLabel;
/*0x290*/

	struct VirtualFunctionTable : public CXWnd::VirtualFunctionTable
	{
	/*0x168*/ void* SetRadioGroup;
	/*0x16c*/ void* DrawWndText;
	/*0x170*/ void* DrawCooldown;
	/*0x174*/ void* SetCheck;
	/*0x178*/ void* SetCoolDownCompletionTimeDelta;
	/*0x17c*/ void* SetCoolDownCompletionTime;
	/*0x180*/ void* SetCoolDownCompletionTime2;
	/*0x184*/ void* SetCoolDownBeginTime;
	/*0x188*/ void* SetCoolDownUpdatedBeginTime;
	/*0x18c*/ void* GetCoolDownBeginTime;
	/*0x190*/ void* GetCoolDownTotalDuration;
	/*0x194*/ void* GetCoolDownTimeRemaining;
	/*0x198*/ void* ClearCoolDownCompletionTime;
	};

	// points to the eq instance of the virtual function table for this class
	static VirtualFunctionTable* sm_vftable;
};

using CBUTTONWND = CButtonWnd;
using PCBUTTONWND = CButtonWnd*;

//============================================================================
// CLabelWnd
//============================================================================

// CLabelWnd__CLabelWnd_x
// size 0x200 see 8D5699 in Aug 10 2017 Live
// size 0x210 see 8DCE59 in Sep 11 2017 Test
// size 0x200 see 668D5B in Oct 17 2017 Live
// size 0x1e4 see 86BFC9 in rof2
class CLabelWnd : public CXWnd
{
public:
	// constructor / destructor
	CLabelWnd(CXWnd* parent, uint32_t id, const CXRect& rect);
	virtual ~CLabelWnd();

	// virtual functions
	virtual int Draw() override;
	virtual void SetWindowText(const CXStr& Text) override;

	virtual void UpdateText();
	virtual void ResizeHeightToText();

	// data members
/*0x1f8*/ bool         bNoWrap;
/*0x1f9*/ bool         bAlignRight;
/*0x1fa*/ bool         bAlignCenter;
/*0x1fc*/ int          xOffset;
/*0x200*/ bool         bResizeHeightToText;
/*0x204*/ int          Unknown0x204;
/*0x208*/ CXStr        Text;
/*0x20c*/ int          Unknown0x20c;
/*0x210*/ bool         Unknown0x210;
/*0x214*/ int          Unknown0x214;
};

//============================================================================
// CLabel
//============================================================================

// CLabel__CLabel_x
// CSidlManager__CreateLabel_x has this
// size 0x1e8 see 755709 in Rof2
// size is 0x220 see 7A5849 in Oct 13 2017 Test -eqmule
class CLabel : public CLabelWnd
{
public:
	// constructor / destructor
	CLabel(CXWnd* parent, uint32_t id, CXRect rect, int EQType);
	virtual ~CLabel();

	// virtual functions
	virtual void UpdateText() override;

	// data members
/*0x218*/ int          EQType;
};
using CLABEL = CLabel;
using PCLABEL = CLabel*;

//============================================================================
// Map Window
//============================================================================

// pLines address = 0x254 + 0x035c = 0x05b0 (address of pMapViewMapVfTable)
// CMapViewWnd__CMapViewWnd_x
// CMapViewWnd_size: 0x668 (see 542694) in May 17 2019 Test
#if 0 // old impl
struct EQMAPWINDOW
{
	/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd

	// inline MapViewMap
	/*0x0378*/ CSidlScreenWnd_VirtualFunctions* pMapViewMapVfTable;  // found at aMapviewmap
	/*0x037c*/ BYTE        Unknown0x037c[0x26c];
	/*0x05e8*/ PMAPLINE    pLines;                   // 0x258
	/*0x05ec*/ PMAPLABEL   pLabels;                  // 0x25c
	/*0x05f0*/ BYTE        Unknown0x05f0[0x78];
	/*0x0668*/
};
#endif

// Map Window sizeof() = 0x38
struct MAPLABEL
{
	/*0x00*/ uint32_t      LabelId;
	/*0x04*/ MAPLABEL*     pNext;
	/*0x08*/ MAPLABEL*     pPrev;
	/*0x0c*/ CVector3      Location;
	/*0x18*/ ARGBCOLOR     Color;
	/*0x1c*/ int           Size;                     // 1-3;
	/*0x20*/ char*         Label;
	/*0x24*/ int           Layer;                    // 0-3;
	/*0x28*/ int           Width;
	/*0x2c*/ int           Height;
	/*0x30*/ int           OffsetX;
	/*0x34*/ int           OffsetY;
	/*0x38*/
};
using PMAPLABEL = MAPLABEL *;

// sizeof() = 0x28
struct MAPLINE
{
	/*0x00*/ MAPLINE*      pNext;
	/*0x04*/ MAPLINE*      pPrev;
	/*0x08*/ CVector3      Start;
	/*0x14*/ CVector3      End;
	/*0x20*/ ARGBCOLOR     Color;
	/*0x24*/ int           Layer;                    // 0-3;
	/*0x28*/
};
using PMAPLINE = MAPLINE *;

class MapViewMap : public CSidlScreenWnd
{
public:
	// constructor / destructor
	MapViewMap();
	virtual ~MapViewMap();

	// virtual functions
	virtual int PostDraw() override;
	virtual int HandleLButtonDown(const CXPoint& pos, uint32_t flags) override;
	virtual int HandleLButtonUp(const CXPoint& pos, uint32_t flags) override;
	virtual int HandleLButtonUpAfterHeld(const CXPoint& pos, uint32_t flags) override;
	virtual int HandleRButtonDown(const CXPoint& pos, uint32_t flags) override;
	virtual int HandleWheelMove(const CXPoint& pos, int scroll, uint32_t flags) override;

	// functions
	//EQLIB_OBJECT bool DrawClippedLine(CVector3*, RGB, CXRect);
	//EQLIB_OBJECT bool IsLayerVisible(int);
	//EQLIB_OBJECT bool LoadEx(char*, int);
	//EQLIB_OBJECT bool PointInMapViewArea(CXPoint, CXRect);
	//EQLIB_OBJECT int GetMaxZ();
	//EQLIB_OBJECT int GetMinZ();
	//EQLIB_OBJECT unsigned long GetCurrentColor();
	//EQLIB_OBJECT unsigned long GetMarkedLineColor();
	//EQLIB_OBJECT void AddLabel(float, float, float, unsigned long, int, char*);
	//EQLIB_OBJECT void AddPoint(float, float, float);
	//EQLIB_OBJECT void CalcLabelRenderOffsets(CXRect);
	//EQLIB_OBJECT void Clear();
	//EQLIB_OBJECT void ClearActiveLayer();
	//EQLIB_OBJECT void Draw(CXRect);
	//EQLIB_OBJECT void EndLine(float, float, float);
	//EQLIB_OBJECT void JoinLinesAtIntersect(bool);
	//EQLIB_OBJECT void Load(char*);
	//EQLIB_OBJECT void MoveLabel(MapViewLabel*, float, float, float);
	//EQLIB_OBJECT void PreCalcRenderValues();
	//EQLIB_OBJECT void RecalcLabelExtents(MapViewLabel*);
	//EQLIB_OBJECT void RemoveLabel(MapViewLabel*);
	//EQLIB_OBJECT void RemoveLabel();
	//EQLIB_OBJECT void RemoveLine(MapViewLabel*);
	//EQLIB_OBJECT void RemoveLine();
	//EQLIB_OBJECT void Save(char*);
	//EQLIB_OBJECT void SaveEx(char*, int);
	//EQLIB_OBJECT void SetCurrentColor(unsigned long);
	//EQLIB_OBJECT void SetMarkedLine(MapViewLabel*);
	//EQLIB_OBJECT void SetMarkedLineColor(unsigned long);
	//EQLIB_OBJECT void SetZoneExtents(int, int, int, int);
	//EQLIB_OBJECT void SetZoom(float);
	//EQLIB_OBJECT void StartLine(float, float, float);
	//EQLIB_OBJECT void TransformPoint(CVector3*);

	float              mapViewMinX;
	float              mapViewMinY;
	float              mapViewMaxX;
	float              mapViewMaxY;
	int                panOffsetX;
	int                panOffsetY;
	float              lineOffsetX;
	float              lineOffsetY;
	float              scaleDiffX;
	float              scaleDiffY;
	float              mapViewScaleX;
	float              mapViewScaleY;
	PMAPLINE           pLines;
	PMAPLABEL          pLabels;
	uint32_t           nextLabelId;
	bool               lineActive;

	// more members, need to map it out.
};

class CMapViewWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	// constructor / destructor
	EQLIB_OBJECT CMapViewWnd(CXWnd*);
	EQLIB_OBJECT virtual ~CMapViewWnd();

	// virtual functions
	virtual bool AboutToShow() override;
	virtual bool AboutToHide() override;
	virtual int OnShow() override;
	virtual int OnMove(const CXRect&) override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;
	virtual void OnWndNotification() override;
	virtual void LoadIniInfo() override;
	virtual void StoreIniInfo() override;

	// functions
	EQLIB_OBJECT void ActivateAutoMapping();
	EQLIB_OBJECT void DeactivateAutoMapping();
	EQLIB_OBJECT bool IsMappingEnabled();

	EQLIB_OBJECT void SetCurrentZone(EQZoneIndex, CVector3* v3Min, CVector3* v3Max, bool);
	EQLIB_OBJECT void GetWorldCoordinates(float*); // actually MapViewMap

	// these are almost all the controls belonging to the CMapViewWnd
	/*0x0240*/ BYTE        Unknown0x0240[0x40];
	/*0x0280*/ CHAR        shortzonename[0x80];
	/*0x0300*/ BYTE        Unknown0x0300[0x3c];
	/*0x033c*/ CXWnd* MapRenderArea;                      // its the MVW_MapRenderArea window... found at aMvw_maprendera
	/*0x0340*/ BYTE        Unknown0x0340[0x38];

	/*0x0378*/ MapViewMap  MapView;                            // a window component owned by CMapViewWnd.

	// alias the stupid
	__declspec(property(get = getLines)) PMAPLINE pLines;
	__declspec(property(get = getLabels)) PMAPLABEL pLabels;

private:
	PMAPLINE getLines() { return MapView.pLines; }
	PMAPLABEL getLabels() { return MapView.pLabels; }
};

using EQMAPWINDOW = CMapViewWnd;
using PEQMAPWINDOW = CMapViewWnd *;

//----------------------------------------------------------------------------

void InitializeUI();

} // namespace eqlib
