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
class CChatContainerWindow;
class CChatWindow;
class CContextMenu;
class CEditWnd;
class CLabel;
class CStmlWnd;

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
/*0x033c*/ CXWnd*      MapRenderArea;                      // its the MVW_MapRenderArea window... found at aMvw_maprendera
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

//============================================================================
// CChatWindowManager
//============================================================================

#define MAX_CHAT_WINDOWS     32
#define MAX_HITMODES         8

// Size is 82 see 4E4072 in Mar 05 2019 Test -eqmule
enum ChatFilterEnum
{
	CHAT_FILTER_SAY,
	CHAT_FILTER_TELL,
	CHAT_FILTER_GROUP,
	CHAT_FILTER_RAID,
	CHAT_FILTER_GUILD,
	CHAT_FILTER_OOC,
	CHAT_FILTER_AUCTION,
	CHAT_FILTER_SHOUT,
	CHAT_FILTER_EMOTE,
	CHAT_FILTER_MELEE_YOUR_HITS,
	CHAT_FILTER_SPELLS_MINE,
	CHAT_FILTER_SKILLS,
	CHAT_FILTER_CHAT1,
	CHAT_FILTER_CHAT2,
	CHAT_FILTER_CHAT3,
	CHAT_FILTER_CHAT4,
	CHAT_FILTER_CHAT5,
	CHAT_FILTER_CHAT6,
	CHAT_FILTER_CHAT7,
	CHAT_FILTER_CHAT8,
	CHAT_FILTER_CHAT9,
	CHAT_FILTER_CHAT10,
	CHAT_FILTER_OTHER,
	CHAT_FILTER_MELEE_YOUR_MISSES,
	CHAT_FILTER_MELEE_YOU_BEING_HIT,
	CHAT_FILTER_MELEE_YOU_BEING_MISSED,
	CHAT_FILTER_MELEE_OTHERS_HITS,
	CHAT_FILTER_MELEE_OTHERS_MISSES,
	CHAT_FILTER_MELEE_MY_DEATH,
	CHAT_FILTER_MELEE_OTHER_PC_DEATH,
	CHAT_FILTER_MELEE_CRITICAL_HITS,
	CHAT_FILTER_MELEE_DISCIPLINES,
	CHAT_FILTER_MELEE_WARNINGS,
	CHAT_FILTER_MELEE_NPC_RAMPAGE,
	CHAT_FILTER_MELEE_NPC_FLURRY,
	CHAT_FILTER_MELEE_NPC_ENRAGE,
	CHAT_FILTER_SPELLS_OTHERS,
	CHAT_FILTER_SPELLS_FAILURES,
	CHAT_FILTER_SPELLS_CRITICALS,
	CHAT_FILTER_SPELLS_WORN_OFF,
	CHAT_FILTER_SPELLS_DD_YOURS,
	CHAT_FILTER_FOCUS_EFFECTS,
	CHAT_FILTER_RANDOM_YOUR_ROLLS,
	CHAT_FILTER_PET_MESSAGES,
	CHAT_FILTER_PET_RAMPAGE_FLURRY,
	CHAT_FILTER_PET_CRITICALS,
	CHAT_FILTER_DAMAGE_SHIELDS_YOU_ATTACKING,
	CHAT_FILTER_EXPERIENCE_MESSAGES,
	CHAT_FILTER_NPC_EMOTES,
	CHAT_FILTER_SYSTEM_MESSAGES,
	CHAT_FILTER_WHO,
	CHAT_FILTER_PET_SPELLS,
	CHAT_FILTER_PET_RESPONSES,
	CHAT_FILTER_ITEM_SPEECH,
	CHAT_FILTER_FELLOWSHIP_MESSAGES,
	CHAT_FILTER_MERCENARY_MESSAGES,
	CHAT_FILTER_PVP_MESSAGES,
	CHAT_FILTER_MELEE_YOUR_FLURRY,
	CHAT_FILTER_DEBUG,                           // todo: check this not 100% sure its it...
	CHAT_FILTER_MELEE_NPC_DEATH,
	CHAT_FILTER_RANDOM_OTHERS_ROLLS,
	CHAT_FILTER_RANDOM_GROUP_RAID_ROLLS,
	CHAT_FILTER_ENVIRONMENTAL_DAMAGE_YOURS,
	CHAT_FILTER_ENVIRONMENTAL_DAMAGE_OTHERS,
	CHAT_FILTER_DAMAGE_SHIELDS_YOU_DEFENDING,
	CHAT_FILTER_DAMAGE_SHIELDS_OTHERS,
	CHAT_FILTER_EVENT_MESSAGES,
	CHAT_FILTER_OVERWRITTEN_DETRIMENTAL_SPELL_MESSAGES,
	CHAT_FILTER_OVERWRITTEN_BENEFICIAL_SPELL_MESSAGES,
	CHAT_FILTER_YOU_CANT_USE_THAT_COMMAND,       // Added chat color and filtering options for 'You can't use that command' messages.
	CHAT_FILTER_COMBAT_ABILITY_REUSE,            // Added chat color and filtering options for combat ability and AA ability reuse time messages.
	CHAT_FILTER_SPELLS_AA_ABILITY_REUSE,
	CHAT_FILTER_ITEM_DESTROYED,
	CHAT_FILTER_SPELLS_AURAS_YOU,
	CHAT_FILTER_SPELLS_AURAS_OTHERS,
	CHAT_FILTER_SPELLS_HEALS_YOURS,
	CHAT_FILTER_SPELLS_HEALS_OTHERS,
	CHAT_FILTER_SPELLS_DOTS_YOURS,
	CHAT_FILTER_SPELLS_DOTS_OTHERS,
	CHAT_FILTER_SPELLS_SONGS,
	CHAT_FILTER_SPELLS_DD_OTHERS,
	CHAT_FILTER_ZERO_HEALS,
	CHAT_FILTER_SOMETHING,

	MAX_CHAT_FILTERS = CHAT_FILTER_SOMETHING
};


// Size 0x384 in eqgame dated 05 Mar 2019 Test (see 0x5418AB)
class CChatWindowManager
{
	//EQLIB_OBJECT CChatWindowManager();
	//EQLIB_OBJECT ~CChatWindowManager();

	EQLIB_OBJECT COLORREF GetRGBAFromIndex(int);
	EQLIB_OBJECT int InitContextMenu(CChatWindow*);
	EQLIB_OBJECT void FreeChatWindow(CChatWindow*);
	EQLIB_OBJECT CChatWindow* GetLockedActiveChatWindow();   // might be returning CChatContainerWindow now
	EQLIB_OBJECT void SetLockedActiveChatWindow(CChatWindow*);
	EQLIB_OBJECT void CreateChatWindow(CXWnd* pParentWnd, int ID, char* Name, int Language, int DefaultChannel,
		int ChatChannel, char* szTellTarget, int FontStyle, bool bScrollbar, bool bHighLight, COLORREF HighlightColor);

	//EQLIB_OBJECT CChatWindow* GetActiveChatWindow();
	//EQLIB_OBJECT CChatWindow* GetChannelMap(int);
	//EQLIB_OBJECT CXStr GetAllVisibleText(CXStr);
	//EQLIB_OBJECT int GetChannelFromColor(int);
	//EQLIB_OBJECT void Activate();
	//EQLIB_OBJECT void AddText(CXStr, int);
	//EQLIB_OBJECT void ClearChannelMap(int);
	//EQLIB_OBJECT void ClearChannelMaps(CChatWindow*);
	//EQLIB_OBJECT void CreateChatWindow();
	//EQLIB_OBJECT void Deactivate();
	//EQLIB_OBJECT void LoadChatInis();
	//EQLIB_OBJECT void Process();
	//EQLIB_OBJECT void SetActiveChatWindow(CChatWindow*);
	//EQLIB_OBJECT void SetChannelMap(int, CChatWindow*);
	//EQLIB_OBJECT void UpdateContextMenus(CChatWindow*);
	//EQLIB_OBJECT void UpdateTellMenus(CChatWindow*);

/*0x000*/ CChatWindow*       ChatWnd[MAX_CHAT_WINDOWS];

	// this is likely a class as a member variable
/*0x080*/ void*              ChatContainerWindow_vfTable;
/*0x084*/ DWORD              Unknown0x084;
/*0x088*/ DWORD              Unknown0x088;
/*0x08c*/ DWORD              Unknown0x08c;
/*0x090*/ CChatContainerWindow* ChatContainerWindow[MAX_CHAT_WINDOWS];
/*0x110*/ DWORD              Unknown0x110;

/*0x114*/ DWORD              NumWindows;
/*0x118*/ DWORD              LockedWindow;
/*0x11c*/ DWORD              ActiveWindow;
/*0x120*/ DWORD              Unknown0x120;                       // CurrentActive... CChat::GetActiveChatWindow
/*0x124*/ DWORD              Unknown0x124;                       // LockedActive... CChatManager__GetLockedActiveChatWindow_x
/*0x128*/ CChatWindow*       ChannelMap[MAX_CHAT_FILTERS];       // channel map
/*0x1a0*/ CContextMenu*      pCM_MainMenu;
/*0x1a4*/ int                ScrollbarIndex;
/*0x1a8*/ CContextMenu*      pCM_LanguageMenu;
/*0x1ac*/ int                LanguageMenuIndex;
/*0x1b0*/ CContextMenu*      pCM_FilterMenu;
/*0x1b4*/ int                FilterMenuIndex;
/*0x1b8*/ int                ChatChannelFilterMenuIndex;
/*0x1bc*/ int                MeleeFilterSubMenuIndex;
/*0x1c0*/ int                SpellsFilterSubMenuIndex;
/*0x1c4*/ CContextMenu*      pCM_MeleeMenu;
/*0x1c8*/ int                MeleeFilterMenuIndex;
/*0x1cc*/ CContextMenu*      pCM_SpellMenu;
/*0x1d0*/ int                SpellsMenuIndex;
/*0x1d4*/ CContextMenu*      pCM_ChannelMenu;
/*0x1d8*/ int                ChannelMenuIndex;
/*0x1dc*/ CContextMenu*      pCM_DefaultChannelMenu;
/*0x1e0*/ int                DefaultChannelMenu;
/*0x1e4*/ int                DefaultChannelMenu2;
/*0x1e8*/ CContextMenu*      pCM_ChatChannelDefChan;
/*0x1ec*/ int                ChatChannelDefChanIndex;
/*0x1f0*/ CContextMenu*      pCM_YourHitsMenu;
/*0x1f4*/ int                YourHitsMenuIndex;
/*0x1f8*/ CContextMenu*      pCM_YourMissesMenu;
/*0x1fc*/ int                YourMissesMenuindex;
/*0x200*/ CContextMenu*      pCM_YouBeingHitMenu;
/*0x204*/ int                YouBeingHitMenuindex;
/*0x208*/ CContextMenu*      pCM_OthersHitsMenu;
/*0x20c*/ int                OthersHitsMenuindex;
/*0x210*/ CContextMenu*      pCM_OthersMissesMenu;
/*0x214*/ int                OthersMissesMenuindex;
/*0x218*/ CContextMenu*      pCM_AllContextMenu;
/*0x21c*/ int                AllContextMenuindex;
/*0x220*/ CContextMenu*      pCM_HitModesMenu;
/*0x224*/ int                HitModesMenuindex;
/*0x228*/ CContextMenu*      pCM_ReplyToMenu;
/*0x22c*/ int                ReplyToMenuindex;
/*0x230*/ CContextMenu*      pCM_TellFriendMenu;
/*0x234*/ int                TellFriendMenuindex;
/*0x238*/ CContextMenu*      pCM_TellRaidmemberMenu;
/*0x23c*/ int                TellRaidmemberMenuindex;
/*0x240*/ int                ReplyToSubIndex;
/*0x244*/ int                TellFriendSubIndex;
/*0x248*/ int                TellRaidmemberSubIndex;
/*0x24c*/ int                HitModes[MAX_HITMODES];
/*0x26c*/ int                DefaultChannel;
/*0x270*/ CContextMenu*      pCM_RandomFilterMenu;
/*0x274*/ int                RandomFilterIndex;
/*0x278*/ int                RandomFilterSubIndex;
/*0x27c*/ CContextMenu*      pCM_EnvironmentalDamageMenu;
/*0x280*/ int                EnvironmentalDamageIndex;
/*0x284*/ int                EnvironmentalDamageSubIndex;
/*0x288*/ CContextMenu*      pCM_DamageShieldsFilterMenu;
/*0x28c*/ int                DamageShieldsFilterIndex;
/*0x290*/ int                DamageShieldsFilterSubIndex;
/*0x294*/ CContextMenu*      pCM_BeneficialSpellsFilterMenu;
/*0x298*/ int                BeneficialSpellsFilteIndex;
/*0x29c*/
};

using EQCHATMGR = CChatWindowManager;
using PEQCHATMGR = CChatWindowManager*;

//============================================================================
// CChatWindow
//============================================================================

// in CChatWindow__SetChatFont see 692847 in eqgame.exe Test dated Jun 28 2016
const int EQ_CHAT_FONT_OFFSET = 0x11c;

// CChatWindow__CChatWindow_x
// Size 0x388 see 69AE4D in Oct 26 2017 Beta exe -eqmule
class CChatWindow : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CChatWindow(CXWnd* parent);
	EQLIB_OBJECT virtual ~CChatWindow();

	//----------------------------------------------------------------------------
	// virtuals

	virtual int Draw() override;
	virtual int HandleRButtonDown(const CXPoint&, uint32_t) override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd* sender, uint32_t message, void* data) override;
	virtual int OnSetFocus(CXWnd* wnd) override;
	virtual int OnKillFocus(CXWnd* wnd) override;
	virtual void Deactivate() override;

	EQLIB_OBJECT void Clear();
	EQLIB_OBJECT void AddHistory(CXStr Text);
	EQLIB_OBJECT CEditWnd* GetInputWnd() { return InputWnd; }
	EQLIB_OBJECT CStmlWnd* GetOutputWnd() { return OutputWnd; }

	//EQLIB_OBJECT CXStr GetInputText();
	//EQLIB_OBJECT void AddOutputText(CXStr, int);
	//EQLIB_OBJECT void HistoryBack();
	//EQLIB_OBJECT void HistoryForward();
	//EQLIB_OBJECT void PageDown();
	//EQLIB_OBJECT void PageUp();
	//EQLIB_OBJECT void SetChatFont(int);

/*0x240*/ CChatWindowManager* ChatManager;
/*0x244*/ CEditWnd*    InputWnd;
/*0x248*/ CStmlWnd*    OutputWnd;
/*0x24c*/ int          ChatChannel;
/*0x250*/ int          ChatChannelIndex;
/*0x254*/ char         TellTarget[0x40];
/*0x294*/ int          Language;
/*0x298*/ bool         bIsMainChat;
/*0x299*/ bool         bIsTellWnd;
/*0x29c*/ int          TimestampFormat;
/*0x2a0*/ COLORREF     TimestampColor;
/*0x2a4*/ bool         bTimestampMatchChatColor;
/*0x2a8*/ CXStr        CommandHistory[0x28];     // see 690DAA in apr 11 2017 test
/*0x348*/ int          HistoryIndex;
/*0x34c*/ int          HistoryLastShown;
/*0x350*/ int          FontSize;                 // style
/*0x354*/ int          AlwaysChathereIndex;      // menu
/*0x358*/ int          NamesContextMenu;         // guess
/*0x35c*/ int          ContextMenuID;            // also a guess
/*0x360*/ int          ContextMenuSubID[0xa];    // this is not correct but ill fix it later.
/*0x388*/
};

using EQCHATWINDOW = CChatWindow;
using PEQCHATWINDOW = CChatWindow*;

//----------------------------------------------------------------------------

void InitializeUI();

} // namespace eqlib
