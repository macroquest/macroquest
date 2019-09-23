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

#include <limits>

#pragma warning(disable : 5030) // Single pragma seems to suffice for the entire codebase

#if !defined(_USE_32BIT_TIME_T)
#define _USE_32BIT_TIME_T
#endif

#if !defined(NOMINMAX)
#define NOMINMAX
#endif

#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

#undef GetWindowText
#undef FindWindow

#include <cstdlib>
#include <cstdint>

#ifdef EQLIB_EXPORTS
#define EQLIB_API extern "C" __declspec(dllexport)
#define EQLIB_VAR extern "C" __declspec(dllexport)
#define EQLIB_OBJECT __declspec(dllexport)
#else
#define EQLIB_API extern "C" __declspec(dllimport)
#define EQLIB_VAR extern "C" __declspec(dllimport)
#define EQLIB_OBJECT __declspec(dllimport)
#endif

#define CONSTRUCTOR_AT_ADDRESS(function, offset)

#define FUNCTION_AT_ADDRESS(Function, Offset)                                            \
	__declspec(naked) Function                                                           \
	{                                                                                    \
		__asm mov eax, Offset                                                            \
		__asm jmp eax                                                                    \
	}

#define FUNCTION_AT_VARIABLE_ADDRESS(Function, Variable)                                 \
	__declspec(naked) Function                                                           \
	{                                                                                    \
		__asm mov eax, [Variable]                                                        \
		__asm jmp eax                                                                    \
	}

#define FUNCTION_AT_VIRTUAL_ADDRESS(Function, VirtualOffset)                             \
	__declspec(naked) Function                                                           \
	{                                                                                    \
		__asm mov eax, [ecx]                                                             \
		__asm lea eax, [eax+VirtualOffset]                                               \
		__asm mov eax, [eax]                                                             \
		__asm jmp eax                                                                    \
	}

#define FORWARD_FUNCTION_TO_VTABLE(Function, Class, Member)                              \
	__declspec(naked) Function                                                           \
	{                                                                                    \
		using VFT = Class::VirtualFunctionTable;                                         \
		__asm mov eax, [Class::sm_vftable]                                               \
		__asm jmp dword ptr [eax]VFT.Member                                              \
	}

#define FORWARD_FUNCTION_TO_VTABLE2(Function, Class, Base, Member)                       \
	__declspec(naked) Function                                                           \
	{                                                                                    \
		using VFT = Base::VirtualFunctionTable;                                          \
		__asm mov eax, [Class::sm_vftable]                                               \
		__asm jmp dword ptr [eax]VFT.Member                                              \
	}


#define PreserveRegisters(code)                                                          \
{                                                                                        \
	__asm push eax                                                                       \
	__asm push ebx                                                                       \
	__asm push ecx                                                                       \
	__asm push edx                                                                       \
	__asm push esi                                                                       \
	__asm push edi                                                                       \
	code;                                                                                \
	__asm pop edi                                                                        \
    __asm pop esi                                                                        \
	__asm pop edx                                                                        \
	__asm pop ecx                                                                        \
	__asm pop ebx                                                                        \
	__asm pop eax                                                                        \
}


template <typename T, size_t N>
constexpr size_t lengthof(const T(&)[N])
{
	return N;
}

namespace eqlib {

class CXSize;

class EQLIB_OBJECT CXPoint
{
public:
	CXPoint() = default;
	CXPoint(int x_, int y_) : x(x_), y(y_) {}
	CXPoint(const CXPoint& other) : x(other.x), y(other.y) {}
	explicit CXPoint(const CXSize& other);

	CXPoint& operator=(const CXPoint& other)
	{
		x = other.x;
		y = other.y;

		return *this;
	}

	bool operator==(const CXPoint& other)
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const CXPoint& other)
	{
		return !(*this == other);
	}

	int x = 0, y = 0;
};

// Literally the same as CXPoint, but the variable names are cx and cy...
class EQLIB_OBJECT CXSize
{
public:
	CXSize() = default;
	CXSize(int x_, int y_) : cx(x_), cy(y_) {}
	CXSize(const CXSize& other) : cx(other.cx), cy(other.cy) {}
	explicit CXSize(const CXPoint& other);

	CXSize& operator=(const CXSize& other)
	{
		cx = other.cx;
		cy = other.cy;

		return *this;
	}

	bool operator==(const CXSize& other)
	{
		return cx == other.cx && cy == other.cy;
	}

	bool operator!=(const CXSize& other)
	{
		return !(*this == other);
	}

	int cx = 0, cy = 0;
};

class EQLIB_OBJECT CXRect
{
public:
	CXRect() = default;
	CXRect(int left_, int top_, int right_, int bottom_)
		: left(left_), top(top_), right(right_), bottom(bottom_) {}
	CXRect(const CXPoint& pt, const CXSize& size)
		: left(pt.x), top(pt.y), right(pt.x + size.cx), bottom(pt.y + size.cy) {}
	CXRect(const CXPoint& pt1, const CXPoint& pt2)
		: left(pt1.x), top(pt1.y), right(pt2.x), bottom(pt2.y) {}
	CXRect(const CXRect& other)
		: left(other.left), top(other.top), right(other.right), bottom(other.bottom) {}

	CXRect& operator=(const CXRect& other)
	{
		left = other.left;
		top = other.top;
		right = other.right;
		bottom = other.bottom;

		return *this;
	}

	bool operator==(const CXRect& other)
	{
		return left == other.left
			&& top == other.top
			&& right == other.right
			&& bottom == other.bottom;
	}

	bool operator!=(const CXRect& other)
	{
		return !(*this == other);
	}

	int GetWidth() const { return right - left; }
	int GetHeight() const { return bottom - top; }

	CXSize GetSize() const { return CXSize{ GetWidth(), GetHeight() }; }

	bool IsEmpty() const { return GetWidth() == 0 && GetHeight() == 0; }
	bool IsAbnormal() const { return GetWidth() < 0 && GetHeight() < 0; }

	CXPoint CenterPoint() const
	{
		return CXPoint{ left + (GetWidth() / 2), top + (GetHeight() / 2) };
	}

	CXPoint TopLeft() const { return CXPoint{ left, top }; }
	CXPoint TopRight() const { return CXPoint{ right, top }; }
	CXPoint BottomLeft() const { return CXPoint{ left, bottom }; }
	CXPoint BottomRight() const { return CXPoint{ right, bottom }; }

	int left = 0;
	int top = 0;
	int right = 0;
	int bottom = 0;
};

inline CXPoint::CXPoint(const CXSize& other)
{
	x = other.cx;
	y = other.cy;
}

inline CXSize::CXSize(const CXPoint& other)
{
	cx = other.x;
	cy= other.y;
}

class CVector2
{
public:
	float X, Y;
};

class CVector3
{
public:
	EQLIB_OBJECT CVector3(float x, float y, float z) : X(x), Y(y), Z(z) {}
	EQLIB_OBJECT CVector3() {}

	// float GetLength() const;
	EQLIB_OBJECT float NormalizeAndReturnLength();
	EQLIB_OBJECT void Normalize();

	void Set(float x, float y, float z)
	{
		X = x;
		Y = y;
		Z = z;
	}

	inline CVector3& operator-=(const CVector3& vec)
	{
		X -= vec.X;
		Y -= vec.Y;
		Z -= vec.Z;
		return *this;
	}

	inline CVector3& operator+=(const CVector3& vec)
	{
		X += vec.X;
		Y += vec.Y;
		Z += vec.Z;
		return *this;
	}

	inline void Scale(float val)
	{
		X *= val;
		Y *= val;
		Z *= val;
	}

	inline CVector3 operator*(float val) const
	{
		CVector3 ret = *this;
		ret.Scale(val);

		return ret;
	}

	void SetMax()
	{
		X = Y = Z = std::numeric_limits<float>::max();
	}

	float GetLengthSquared() const
	{
		return (X * X) + (Y * Y) + (Z * Z);
	}

	float GetLength() const
	{
		return sqrtf(GetLengthSquared());
	}

	CVector3 operator-() const
	{
		CVector3 res;
		res.Set(-X, -Y, -Z);

		return res;
	}

	CVector3 operator-(const CVector3 & vec) const
	{
		CVector3 res;
		res.Set(X - vec.X, Y - vec.Y, Z - vec.Z);

		return res;
	}

	CVector3 operator+(const CVector3 & vec) const
	{
		CVector3 res;
		res.Set(vec.X + X, vec.Y + Y, vec.Z + Z);

		return res;
	}

	float GetDistanceSquared(const CVector3 & vec) const
	{
		CVector3 Delta = *this - vec;
		return Delta.GetLengthSquared();
	}

	float X = 0.f;
	float Y = 0.f;
	float Z = 0.f;
};

union RGB
{
	struct
	{
		unsigned char Blue;
		unsigned char Green;
		unsigned char Red;
		unsigned char Alpha;
	};
	unsigned long ARGB;
};

struct EQRGB
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

struct ARGBCOLOR
{
	union
	{
		struct
		{
			BYTE B;
			BYTE G;
			BYTE R;
			BYTE A;
		};

		DWORD ARGB;
	};
};
using PARGBCOLOR = ARGBCOLOR *;

struct EQLOC
{
	float x;
	float y;
	float z;
};

enum UIType;

enum EQExpansion
{
	EQExpansionNone                    = 0,
	EQExpansionKunark                  = 1,
	EQExpansionVelious                 = 2,
	EQExpansionLuclin                  = 3,
	EQExpansionPOP                     = 4,
	EQExpansionYkesha                  = 5,
	EQExpansionLDON                    = 6,
	EQExpansionGates                   = 7,
	EQExpansionOOW                     = 8,
	EQExpansionDON                     = 9,
	EQExpansionDODH                    = 10,
	EQExpansionPOR                     = 11,
	EQExpansionTSS                     = 12,
	EQExpansionTBS                     = 13,
	EQExpansionSOF                     = 14,
	EQExpansionSOD                     = 15,
	EQExpansionUF                      = 16,
	EQExpansionHOT                     = 17,
	EQExpansionVOA                     = 18,
	EQExpansionROF                     = 19,
	EQExpansionCOTF                    = 20,
	EQExpansionTDS                     = 21,
	EQExpansionTBM                     = 22,
	EQExpansionEOK                     = 23,
	EQExpansionROS                     = 24,
	EQExpansionTBL                     = 25,
};

enum EQExpansionOwned
{
	EQExpansionNoneOwned               = 0x00000000,
	EQExpansionKunarkOwned             = 0x00000001,
	EQExpansionVeliousOwned            = 0x00000002,
	EQExpansionLuclinOwned             = 0x00000004,
	EQExpansionPOPOwned                = 0x00000008,
	EQExpansionYkeshaOwned             = 0x00000010,
	EQExpansionLDONOwned               = 0x00000020,
	EQExpansionGatesOwned              = 0x00000040,
	EQExpansionOOWOwned                = 0x00000080,
	EQExpansionDONOwned                = 0x00000100,
	EQExpansionDODHOwned               = 0x00000200,
	EQExpansionPOROwned                = 0x00000400,
	EQExpansionTSSOwned                = 0x00000800,
	EQExpansionTBSOwned                = 0x00001000,
	EQExpansionSOFOwned                = 0x00002000,
	EQExpansionSODOwned                = 0x00004000,
	EQExpansionUFOwned                 = 0x00008000,
	EQExpansionHOTOwned                = 0x00010000,
	EQExpansionVOAOwned                = 0x00020000,
	EQExpansionROFOwned                = 0x00040000,
	EQExpansionCOTFOwned               = 0x00080000,
	EQExpansionTDSOwned                = 0x00100000,
	EQExpansionTBMOwned                = 0x00200000,
	EQExpansionEOKOwned                = 0x00400000,
	EQExpansionROSOwned                = 0x00800000,
	EQExpansionTBLOwned                = 0x01000000,

	EQExpansionAllOwned                = 0x01ffffff,
};

// TODO: Find a common place to put constants
constexpr int MAX_BANDOLIER_SLOTS = 4;


// Enumerations...
using EQZoneIndex = uint32_t;
using EQLocalizeLanguage = uint32_t;
enum EWndRuntimeType;

// Forward class declarations
class _EverQuestinfo;
class _partyGroup;
class CAltAbilityData;
class AltAdvManager;
class CAuraWnd;
class CAAWnd;
class CActionsWnd;
class CActorInterface;
class CActorInterfaceBase;
class CAchievementsWnd;
class CRealEstateItemsWnd;
class CAlarmWnd;
class CBankWnd;
class CBazaarSearchWnd;
class CBazaarWnd;
class CBodyTintWnd;
class CBookWnd;
class CBreathWnd;
class CBuffWindow;
class CBugReportWnd;
class CButtonDrawTemplate;
class CButtonTemplate;
class CButtonWnd;
class CCastingWnd;
class CCastSpellWnd;
class CCharacterCreation;
class CCharacterListWnd;
class CChatWindowManager;
class CChatWindow;
class CCheckBoxWnd;
class CClickStickInfo;
class CColorPickerWnd;
class CCombatSkillsSelectWnd;
class CComboboxTemplate;
class CComboWnd;
class CCompassWnd;
class CConfirmationDialog;
class CContainerMgr;
class CContainerWnd;
class CContextMenu;
class CContextMenuManager;
class CControlTemplate;
class CCursorAttachment;
class CDisplay;
class CEditBaseWnd;
class CEditboxTemplate;
class CEditLabelWnd;
class CEditWnd;
class CEQSuiteTextureLoader;
class CEverQuest;
class CExploreModeWnd;
class CFacePick;
class CFactionWnd;
class CExtendedTargetWnd;
class CFindItemWnd;
class CFeedbackWnd;
class CFileSelectionWnd;
class CFriendsWnd;
class CGaugeDrawTemplate;
class CGaugeTemplate;
class CGaugeWnd;
class CGemsGameWnd;
class CGiveWnd;
class CGroupSearchFiltersWnd;
class CGroupSearchWnd;
class CGroupWnd;
class CGuild;
class CGuildMgmtWnd;
class CharacterBase;
class CHashCXStrInt32;
class CHelpWnd;
class CHotButton;
class CHotButtonWnd;
class CIMECandidateList;
class CIMEComposition;
class CIMEManager;
class CIMEStatusBar;
class CInspectWnd;
class CInventoryWnd;
class CInvSlot;
class CInvSlotMgr;
class CInvSlotTemplate;
class CInvSlotWnd;
class CItemDisplayWnd;
class CJournalCatWnd;
class CJournalNPCWnd;
class CJournalTextWnd;
class CKeyCXStrValueInt32;
class CLabel;
class CLabelTemplate;
class CLargeDialogWnd;
class CLightDefinitionInterface;
class CLightInterface;
class CListboxColumnTemplate;
class CListboxTemplate;
class CListWnd;
class CLoadskinWnd;
class CLootWnd;
class CMapToolbarWnd;
class CMapViewWnd;
class CMemoryStream;
class PointMerchantWnd;
class CMerchantWnd;
class CMusicPlayerWnd;
class CNoteWnd;
class ConversationJournal;
class COptionsWnd;
class CPageTemplate;
class CPageWnd;
class CParam;
class CParamButton;
class CParamButtonDrawTemplate;
class CParamClass;
class CParamCombobox;
class CParamControl;
class CParamEditbox;
class CParamFrame;
class CParamFrameTemplate;
class CParamGauge;
class CParamGaugeDrawTemplate;
class CParamInvSlot;
class CParamLabel;
class CParamListbox;
class CParamListboxColumn;
class CParamPage;
class CParamPoint;
class CParamRGB;
class CParamScreen;
class CParamScreenPiece;
class CParamScrollbarDrawTemplate;
class CParamSize;
class CParamSlider;
class CParamSliderDrawTemplate;
class CParamSpellGem;
class CParamSpellGemDrawTemplate;
class CParamStaticAnimation;
class CParamStaticFrame;
class CParamStaticHeader;
class CParamStaticScreenPiece;
class CParamStaticText;
class CParamSTMLbox;
class CParamSuiteDefaults;
class CParamTabBox;
class CParamTextureInfo;
class CParamUi2DAnimation;
class CParamWindowDrawTemplate;
class CPetitionQWnd;
class CPlayerNotesWnd;
class CPlayerWnd;
class CPotionBeltWnd;
class CBandolierWnd;
class CQuantityWnd;
class CRadioGroup;
class CRaid;
class CRaidOptionsWnd;
class CRaidWnd;
class CResolutionHandler;
class CScreenPieceTemplate;
class CScreenTemplate;
class CScrollbarTemplate;
class CSelectorWnd;
class CSidlManager;
class CSidlScreenWnd;
class CSkillsSelectWnd;
class CSkillsWnd;
class CSliderDrawTemplate;
class CSliderTemplate;
class CSliderWnd;
class CSocialEditWnd;
class CSpellBookWnd;
class CSpellGemDrawTemplate;
class CSpellGemTemplate;
class CSpellGemWnd;
class CStaticAnimationTemplate;
class CStaticFrameTemplate;
class CStaticHeaderTemplate;
class CStaticScreenPieceTemplate;
class CStaticTextTemplate;
class CSTMLboxTemplate;
class CStmlReport;
class CStmlWnd;
struct CStrRep;
class CStoryWnd;
class CTabBoxTemplate;
class CTabWnd;
class CTAFrameDraw;
class CTargetManager;
class CTargetRing;
class CTargetWnd;
class CTaskWnd;
class CTaskManager;
class CTextEntryWnd;
class CTextObjectInterface;
class CTextureAnimation;
class CTextureFont;
class CTimeLeftWnd;
class CTipWnd;
class CTrackingWnd;
class CTradeWnd;
class CTrainWnd;
class CTreeView;
struct CUITextureInfo;
class CUITexturePiece;
class CVector3;
class CVideoModesWnd;
class CXFileXML;
class CXMLData;
class CXMLDataClass;
class CXMLDataManager;
class CXMLDataPtr;
class CXMLEnumInfo;
class CXMLParamManager;
class CXMLSOMAttribute;
class CXMLSOMAttributeType;
class CXMLSOMDocument;
class CXMLSOMDocumentBase;
class CXMLSOMElement;
class CXMLSOMElementType;
class CXMLSOMNode;
class CXMLSOMNodePtr;
class CXMLSOMParser;
class CXMLSOMSchema;
class CXMLSOMSimpleType;
class CXPoint;
class CXRect;
class CXStr;
class CXWnd;
class CXWndDrawTemplate;
class CXWndManager;
//class ActorClient;
class EmitterManager;
class engineInterface;
class EQ_Affect;
class EQ_AltAbility;
class EQ_CharacterData;
class EQ_Container;
class EQ_Equipment;
class EQ_Item;
class EQ_LoadingS;
class CLineBase;
class EQ_Note;
class EQ_Skill;
class EQ_Spell;
class EQAnimation;
class EQEffect;
class EqEmitterData;
class EQItemList;
class EQMissile;
struct EQMissileHitinfo;
class EqMobileEmitter;
class EQMoneyList;
class EQObject;
class EQPlayerDeath;
class EQPMInfo;
class EqSoundManager;
class EQSwitch;
class EqSwitchManager;
class EQUtil;
class EQWorldData;
class EQZoneInfo;
struct GuildMember;
class IconCache;
class ItemBase;
class ItemBaseContainer;
class JournalNPC;
class KeyCombo;
class KeypressHandler;
class LootFiltersManager;
class EQSpellStrings;
class MapViewMap;
class MidiInstance;
class monty;
class Mp3Manager;
class MusicManager;
class PcClient;
class SAmpersandEntry;
struct SDragDropInfo;
class SListWndSortInfo;
class SoundAsset;
struct SoundControl;
class SoundEmitter;
class SoundInstance;
class SoundManager;
class SoundObject;
struct SParseVariables;
class SpellManager;
struct STable;
struct STableCell;
struct STempTable;
struct STempTableCell;
struct STempTableRow;
class StringTable;
class UdpConnection;
class Wave3dInstance;
class WaveInstance;
class CTextOverlay;
class PcZoneClient;
class CharacterZoneClient;
class CZoneGuideWnd;
// End forward class declarations

#if defined (_DEBUG)
#define FORCE_SYMBOLS __declspec(dllexport) const void* __force_symbol_generation__() const { return this; }
#else
#define FORCE_SYMBOLS
#endif

} // namespace eqlib
