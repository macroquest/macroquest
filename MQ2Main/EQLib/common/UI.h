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

enum enDir
{
	UI_DefaultDir,
	UI_AtlasDir,
	UI_TextureDir,
	UI_MapsDir,
};

class WndEventHandler
{
	unsigned int lastUpdate;

public:
};

class CUITextureInfo2
{
public:
	/*0x00*/ bool          bValid;
	/*0x04*/ enDir         Dir;
	/*0x08*/ CXStr         Name;
	/*0x0c*/ SIZE          TextureSize;
	/*0x14*/ UINT          TextureID;
	/*0x18*/
};

class CUITexturePiece
{
public:
	EQLIB_OBJECT ~CUITexturePiece();
	EQLIB_OBJECT CUITexturePiece(const CUITexturePiece&);
	EQLIB_OBJECT CUITexturePiece(CUITextureInfo, class CXRect);
	EQLIB_OBJECT CUITexturePiece();
	EQLIB_OBJECT CUITexturePiece& operator=(const CUITexturePiece&);
	EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, const CXRect&, unsigned long, unsigned long) const;
	EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, unsigned long, unsigned long) const;

	// Should be a CUITextureInfo
	CUITextureInfo2 TInfo;
	CXRect Rect;
};

struct STextureAnimationFrame
{
	CUITexturePiece    TPiece;
	uint32_t           Ticks;
	CXPoint            Hotspot;
};

enum eBitmapType
{
	eBT_Normal,
	eBT_Layer,
	eBT_SingleDetail,
	eBT_PaletteDetailMain,
	eBT_PaletteDetailPalette,
	eBT_PaletteDetailDetail
};

class CEQGBitmap // have to fake these i dont wanna map them now... we dont need them anyway : public CThreadLoader, public TListNode<CEQGBitmap>
{
public:
	void*              vftable;
	BYTE               Header[0x1c];
	eBitmapType        eType;
	int                eMemoryPoolManagerType;   // eMemoryPoolManagerType need to figure out this enum
	char*              FileName;
	UINT               SourceWidth;
	UINT               SourceHeight;
	float              DetailScale;
	UINT               GrassDensity;
	UINT               Width;
	UINT               Height;
	bool               bHasTexture;
	union
	{
		void*          pD3DTexture;              // IDirect3DBaseTexture9
		void*          pRawBitmap;
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
	UINT               Flags;
	CEQGBitmap*        pBmp;
};

struct SuiteTexture
{
	bool               bUsed;
	CXStr              Name;
	enDir              Directory;
	BMI* pBMInfo;
};
using PSuiteTexture = SuiteTexture *;

class CTextureAnimation
{
public:
	EQLIB_OBJECT CTextureAnimation(CXStr);
	EQLIB_OBJECT CTextureAnimation();
	EQLIB_OBJECT CTextureAnimation& operator=(const CTextureAnimation&);
	EQLIB_OBJECT CXPoint GetHotspot() const;
	EQLIB_OBJECT CXStr GetName() const;
	EQLIB_OBJECT int AddBlankFrame(uint32_t, CXPoint);
	EQLIB_OBJECT int AddFrame(CUITexturePiece, uint32_t, CXPoint);
	EQLIB_OBJECT int AddFrame(const CUITextureInfo*, const CXRect&, uint32_t, CXPoint);
	EQLIB_OBJECT int Draw(const CXPoint&, const CXRect&, unsigned long, unsigned long) const;
	EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, unsigned long, unsigned long) const;
	EQLIB_OBJECT int GetCurFrame() const;
	EQLIB_OBJECT int Preload();
	EQLIB_OBJECT void Reset();
	EQLIB_OBJECT void SetCurCell(int);
	EQLIB_OBJECT void SetCurFrame(int);

	// virtual
	EQLIB_OBJECT ~CTextureAnimation();

	// protected
	static uint32_t MaxID;

/*0x00*/ void*         vfTable;
/*0x04*/ CXStr         Name;
/*0x08*/ ArrayClass_RO<STextureAnimationFrame> Frames;
	// and more ...
};

class CButtonDrawTemplate
{
public:
	CXStr              Name;
	CTextureAnimation* Normal;
	CTextureAnimation* Pressed;
	CTextureAnimation* Flyby;
	CTextureAnimation* Disabled;
	CTextureAnimation* PressedFlyby;
	CTextureAnimation* PressedDisabled;
	CTextureAnimation* NormalDecal;
	CTextureAnimation* PressedDecal;
	CTextureAnimation* FlybyDecal;
	CTextureAnimation* DisabledDecal;
	CTextureAnimation* PressedFlybyDecal;
	CTextureAnimation* PressedDisabledDecal;

	EQLIB_OBJECT CButtonDrawTemplate();
	EQLIB_OBJECT ~CButtonDrawTemplate();
	EQLIB_OBJECT CButtonDrawTemplate(const CButtonDrawTemplate&);
	EQLIB_OBJECT CButtonDrawTemplate& operator=(const CButtonDrawTemplate&);
	EQLIB_OBJECT CXSize GetSize() const;
};

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

} // namespace eqlib
