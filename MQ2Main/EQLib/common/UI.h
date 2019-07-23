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

} // namespace eqlib
