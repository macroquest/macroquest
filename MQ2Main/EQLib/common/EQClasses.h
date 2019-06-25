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

#include "SharedClasses.h"
#include "eq.h"

#undef FindWindow
#undef InsertMenuItem

struct IShellFolder;

namespace EQClasses {

// Other
class CXSize
{
public:
	DWORD A, B, C, D, E, F;
	CXSize::~CXSize() {};
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


// Enumerations...
using EQZoneIndex = DWORD;
using EQLocalizeLanguage = DWORD;
using EScrollCode = DWORD;

// Forward class declarations
class _EverQuestinfo;
class _PackFileData;
class _PackFileDataRawFile;
class _partyGroup;
class CAltAbilityData;
class AltAdvManager;
class CAuraWnd;
class bad_word_class;
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
class CChatManager;
class CChatWindow;
class CCheckBoxWnd;
class CClickStickInfo;
class CCollisionInfoTargetVisibility;
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
class CDIMap;
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
class ChannelServerApi;
class ChannelServerHandler;
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
class CParseTokensXML;
class CParseTokXML;
class CPetInfoWnd;
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
class CRC32Generator;
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
class CSoulmarkWnd;
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
class CStrRep;
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
class CTokenXML;
class CTrackingWnd;
class CTradeWnd;
class CTrainWnd;
class CTreeView;
class CUITextureInfo;
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
class CXMLSOMCursor;
class CXMLSOMCursorSave;
class CXMLSOMCursorSaveFast;
class CXMLSOMCursorTraverseChildren;
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
class CXStrSingleton;
class CXWnd;
class EQLIB_OBJECT CXWndDrawTemplate;
class CXWndManager;
//class ActorClient;
class EmitterManager;
class engineInterface;
class EQ_Affect;
class EQ_AltAbility;
class EQ_Character;
class EQ_CharacterData;
class EQ_Container;
class EQ_Equipment;
class EQ_Item;
class EQ_LoadingS;
class CLineBase;
class EQ_Note;
class EQ_PC;
class EQ_Skill;
class EQ_Spell;
class EQAnimation;
class EQEffect;
class EqEmitterData;
class EQHSprite;
class EQItemList;
class EQMissile;
struct EQMissileHitinfo;
class EqMobileEmitter;
class EQMoneyList;
class EQObject;
class EQPlayer;
class EQPlayerDeath;
class EQPMInfo;
class EqSoundManager;
class EQSwitch;
class EqSwitchManager;
class EQUtil;
class EQWorldData;
class EQZoneInfo;
class FilePath;
class flex_unit;
class GrammarRulesClass;
class GuildMember;
class IconCache;
class ItemBase;
//class ItemBaseContainer;
class JournalNPC;
class KeyCombo;
class KeypressHandler;
class LogicalPacket;
class LootFiltersManager;
class EQSpellStrings;
class MapViewMap;
class MemoryPoolManager;
class MidiInstance;
class monty;
class Mp3Manager;
class MusicManager;
class PacketPacker;
class PacketPackerManager;
class PackFile;
class PackFS;
class PooledLogicalPacket;
class public_key;
class PcClient;
class SAmpersandEntry;
struct SDragDropInfo;
class SFormattedText;
class ShareBase;
class SharedString;
class SHistoryElement;
class SimpleLogicalPacket;
class SListWndCellEditUpdate;
class SListWndSortInfo;
class SoundAsset;
class SoundControl;
class SoundEmitter;
class SoundInstance;
class SoundManager;
class SoundObject;
class SParseVariables;
class SpellManager;
class STable;
class STableCell;
class STempTable;
class STempTableCell;
class STempTableRow;
class StringItem;
class StringTable;
class TextFileReader;
class type_info;
class UdpConnection;
class UdpConnectionHandler;
class UdpIpAddress;
class UdpManager;
class UdpMisc;
class UdpReliableChannel;
class Wave3dInstance;
class WaveInstance;
class WrappedLogicalPacket;
class ZlibUtil;
class ZoneNPCLoadTextManager;
class CTextOverlay;
class PcZoneClient;
class CharacterZoneClient;
class CZoneGuideWnd;
// End forward class declarations

struct cTargetHeader
{
	int m_id;
	int m_timeNext;
	bool m_bComplete;
	short m_count;
};

struct cTargetBuff
{
	int slot;
	int spellId;
	int duration;            // in ticks...
	int count;
	char casterName[64];

	// not actually part of this packet but we need it for cachedbuffs map
	DWORD timeStamp;         // when the buffpacket arrived.
};
using PcTargetBuff = cTargetBuff*;

struct AggroMeterListEntry
{
	void*    vfTable;
	uint16_t AggroPct;
};
using PAggroMeterListEntry = AggroMeterListEntry*;

class EQLIB_OBJECT AggroMeterManagerClient
{
public:
	static AggroMeterManagerClient& Instance();

/*0x00*/ TSafeArrayStatic<AggroMeterListEntry, 0x1e> aggroData;
/*0xf0*/ DWORD AggroLockID;                     // this can be 0, I dont know what it is...
/*0xf4*/ DWORD AggroTargetID;                   // this is id of whoever we are fighting
/*0xf8*/ DWORD AggroSecondaryID;                // this is id of whoever the npc is fighting
/*0xfc*/
};

struct Personal_Loot
{
	CButtonWnd* NPC_Name;
	CButtonWnd* Item;
	CButtonWnd* Loot;
	CButtonWnd* Leave;
	CButtonWnd* AN;
	CButtonWnd* AG;
	CButtonWnd* Never;
};
using PPersonal_Loot = Personal_Loot*;

struct Shared_Loot
{
	CButtonWnd* NPC_Name;
	CButtonWnd* Item;
	CButtonWnd* Status;
	CButtonWnd* Action;
	CButtonWnd* Manage;
	CButtonWnd* AutoRoll;
	CButtonWnd* ND;
	CButtonWnd* GD;
	CButtonWnd* NO;
	CButtonWnd* AN;
	CButtonWnd* AG;
	CButtonWnd* NV;
};
using PShared_Loot = Shared_Loot*;

enum ePetCommandType
{
	PCT_ReportHealth, 
	PCT_WhoLeader,
	PCT_Attack, 
	PCT_QueueAttack,
	PCT_ToggleFollow,
	PCT_ToggleGuard,
	PCT_ToggleSit,
	PCT_SitOn,
	PCT_SitOff,
	PCT_ToggleStop,
	PCT_StopOn,
	PCT_StopOff,
	PCT_ToggleTaunt,
	PCT_TauntOn,
	PCT_TauntOff,
	PCT_ToggleHold,
	PCT_HoldOn,
	PCT_HoldOff, 
	PCT_ToggleGHold,
	PCT_GHoldOn,
	PCT_GHoldOff, 
	PCT_ToggleSpellHold,
	PCT_SpellHoldOn,
	PCT_SpellHoldOff,
	PCT_ToggleFocus,
	PCT_FocusOn,
	PCT_FocusOff,
	PCT_FeignDeath, 
	PCT_BackOff, 
	PCT_GetLost, 
	PCT_TargetPet,
	PCT_ToggleRegroup,
	PCT_RegroupOn,
	PCT_RegroupOff,
	PCT_Something,
	PCT_Something2,
	PCT_DoNothing
};

struct CXSTR;
using PCXSTR = CXSTR*;

// Class declarations
class EQLIB_OBJECT CXStr
{
public:
	CXStr();
	CXStr(const char*);
	CXStr(const char*, int);
	CXStr(char);
	CXStr(const CXStr&);
	CXStr(int, int, char);
	CXStr(unsigned short const*);
	~CXStr();

	CXStr& operator=(const char*);
	CXStr& operator=(const CXStr&);
	char operator[](int) const;
	operator const char* ();

	bool Find(char, int&);
	bool Find(const CXStr&, int&);
	bool Find(unsigned short, int&);
	bool FindLast(char, int&);

	char GetChar(long) const;
	char SetChar(long, char);

	CXStr Copy(long, long) const;
	CXStr Left(int) const;
	CXStr Mid(int, int) const;
	CXStr Right(int) const;
	//enum EStringEncoding CXStr::GetEncoding() const;
	int PrintString(const char*, ...);
	//int Compare(CXStr const &, enum CompareCode) const;
	//int CompareN(CXStr const &, int, enum CompareCode) const;
	int ConvertToInt();
	int operator==(const char*) const;
	int operator==(const CXStr&) const;
	int operator>(const CXStr&) const;
	long GetLength() const;
	wchar_t GetUnicode(long pos) const;
	unsigned short SetUnicode(long, unsigned short);
	bool FindNext(char ch, int& pos) const;
	void AddCr();
	void Blank();
	void BlankPreAllocate(int);
	void CopySelf(long, long);
	void Delete(long, long);
	void Insert(long, char);
	void Insert(long pos, const CXStr& str);
	void operator+=(const char*);
	void operator+=(char);
	void operator+=(const CXStr&);
	void operator+=(unsigned short);
	//void SetEncoding(enum EStringEncoding);
	void SetLowerCase();
	void SetUpperCase();
	void Strip(char);
	void StripAll(char);
	void StripLeading(char);
	void StripTrailing(char);

	// protected
	static int LenUnicodeToUtf8(unsigned short const*);
	static int UnicodeToUtf8(unsigned short const*, char*, int);
	static int Utf8ToUnicode(const char*, unsigned short*, int);
	//CStrRep* AllocRepNoLock(long, enum EStringEncoding);
	//void Assure(long, enum EStringEncoding);
	void AssureCopy();
	void FreeRep(CStrRep*);
	void FreeRepNoLock(CStrRep*);

	// private
	void CheckNoLock();
	void SetString(const char* Str, long len);

	PCXSTR Ptr;
};

enum EWndRuntimeType
{
	WRT_WND = 0,
	WRT_LISTWND,
	WRT_EDITWND,
	WRT_TREEWND,
	WRT_PAGEWND,
	WRT_TABWND,
	WRT_HTMLWND,
	WRT_HOTKEYWND,
	WRT_EDITHOTKEYWND,
	WRT_RANGESLIDERWND,
	WRT_STMLWND,
	WRT_BROWSERWND,
	WRT_MODALMESSAGEWND,
	WRT_CHECKBOXWND,
	WRT_SIDLSCREENWND,
	WRT_SLIDERWND,
	WRT_LABEL,
	WRT_BUTTON,
	WRT_GAUGE,
	WRT_COMBOBOX,
	WRT_CHATWND,
	WRT_HELPWND,
};

class EQLIB_OBJECT CXWnd
{
public:
	//CXWnd() {};
	void dCXWnd();
	CXWnd* SetParent(CXWnd*);
	UIType GetType();
	CXMLData* GetXMLData();
	CXWnd* GetChildItem(char* Name);
	CXWnd(CXWnd*, uint32_t, const CXRect&);
	bool HasFocus() const;
	bool IsActive() const;
	bool IsDescendantOf(CXWnd const*) const;
	bool IsEnabled() const;
	bool IsReallyVisible() const;
	bool IsType(EWndRuntimeType eType) const;
	const CButtonDrawTemplate* GetCloseBoxTemplate() const;
	const CButtonDrawTemplate* GetMinimizeBoxTemplate() const;
	const CButtonDrawTemplate* GetTileBoxTemplate() const;
	const CTAFrameDraw* GetBorderFrame() const;
	const CTAFrameDraw* GetTitlebarHeader() const;
	CXRect GetClientClipRect() const;
	CXRect GetRelativeRect() const;
	CXRect GetScreenClipRect() const;
	CXRect GetScreenRect() const;
	CXStr GetWindowTextA() const;
	CXStr GetXMLTooltip() const;
	CXWnd* GetChildItem(CXStr const &);
	CXWnd* GetChildWndAt(CXPoint*, int, int) const;
	CXWnd* GetFirstChildWnd() const;
	CXWnd* GetNextChildWnd(CXWnd*) const;
	CXWnd* GetNextSib() const;
	CXWnd* SetFocus();
	int DoAllDrawing() const;
	int DrawChildren() const;
	int DrawCloseBox() const;
	int DrawHScrollbar(int, int, int) const;
	int DrawMinimizeBox() const;
	int DrawTileBox() const;
	int DrawVScrollbar(int, int, int) const;
	int GetWidth() const;
	int Minimize(bool);
#if !defined(ROF2EMU) && !defined(UFEMU)
	int Move(CXPoint const &);
#else
	int Move(CXPoint);
#endif
	//Move (this is CXWnd__Move1_x) was checked on apr 29 2016 - eqmule
	int Move(const CXRect& rc, bool bUpdateLayout = true, bool bForceUpdateLayout = false, bool bCompleteMoveOrResize = false, bool bMoveAutoStretch = false);
	int ProcessTransition();
	int Resize(int Width, int Height, bool bUpdateLayout = true, bool bCompleteMoveOrResize = false, bool bMoveAutoStretch = false);
	int Show(bool bShow = true, bool bBringToTop = true, bool bUpdateLayout = true);
	int Tile(bool);
	static CXRect GetTooltipRect(const CXPoint&, const CXSize&);
	static CXRect GetTooltipRect(const CXRect&);
	static CXWndDrawTemplate sm_wdtDefaults;
	static int DrawColoredRect(const CXRect&, unsigned long, const CXRect&);
	static int DrawLasso(const CXRect&, unsigned long, const CXRect&);
	static int DrawRaisedRect(const CXRect&, const CXRect&);
	static int DrawSunkenRect(const CXRect&, const CXRect&);
	void Bottom();
	void BringChildWndToTop(CXWnd*);
	void BringToTop(bool bRecurse = true);
	void Center();
	void ClrFocus();
	int Destroy();
	void DrawTooltipAtPoint(CXPoint) const;
	void Left();
	void Refade();
	void Right();
	void SetFirstChildPointer(CXWnd*);
	void SetKeyTooltip(int, int);
	void SetLookLikeParent();
	void SetMouseOver(bool);
	void SetNextSibPointer(CXWnd*);
	void SetTooltip(CXStr);
	void SetXMLTooltip(CXStr);
	//void SetZLayer(int);
	void StartFade(unsigned char, uint32_t);

	// virtual
	bool IsPointTransparent(CXPoint) const;
	bool IsValid() const;
	bool QueryClickStickDropOK(CClickStickInfo*) const;
	bool QueryDropOK(SDragDropInfo*) const;
	CTextureAnimation* GetClickStickCursor(CClickStickInfo*) const;
	CTextureAnimation* GetCursorToDisplay() const;
	CTextureAnimation* GetDragDropCursor(SDragDropInfo*) const;
	CXRect GetClientRect() const;
	CXRect GetHitTestRect(int) const;
	CXRect GetInnerRect() const;
	CXRect GetMinimizedRect() const;
	CXSize GetMinSize() const;
	CXSize GetUntileSize() const;
	CXStr GetTooltip() const;
	int AboutToDeleteWnd(CXWnd*);
	int Draw() const;
	int DrawBackground() const;
	int DrawCaret() const;
	int DrawChildItem(CXWnd const*, void*) const;
	int DrawCursor(CXPoint, const CXRect&, bool &);
	int DrawNC() const;
	int DrawTitleBar(const CXRect&) const;
	int DrawTooltip(CXWnd const*) const;
	int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	int HandleLButtonDown(const CXPoint&, uint32_t);
	int HandleLButtonHeld(const CXPoint&, uint32_t);
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int HandleLButtonUpAfterHeld(const CXPoint&, uint32_t);
	int HandleMouseMove(const CXPoint&, uint32_t);
	int HandleRButtonDown(const CXPoint&, uint32_t);
	int HandleRButtonHeld(const CXPoint&, uint32_t);
	int HandleRButtonUp(const CXPoint&, uint32_t);
	int HandleRButtonUpAfterHeld(const CXPoint&, uint32_t);
	int HandleWheelButtonDown(CXPoint, uint32_t);
	int HandleWheelButtonUp(CXPoint, uint32_t);
	int HandleWheelMove(CXPoint, int, uint32_t);
	int HitTest(CXPoint, int*) const;
	int OnActivate(CXWnd*);
	int OnBroughtToTop();
	int OnClickStick(CClickStickInfo*, uint32_t, bool);
	int OnDragDrop(SDragDropInfo*);
	int OnHScroll(EScrollCode, int);
	int OnKillFocus(CXWnd*);
	int OnMinimizeBox();
	int OnMove(const CXRect&);
	int OnProcessFrame();
	int OnResize(int, int);
	int OnSetFocus(CXWnd*);
	int OnShow();
	int OnTile();
	int OnTileBox();
	int OnVScroll(EScrollCode, int);
	int PostDraw() const;
	//int RequestDockInfo(enum EDockAction, CXWnd*, class CXRect*);
	int SetVScrollPos(int);
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
	void OnReloadSidl();
	void SetAttributesFromSidl(CParamScreenPiece*);
	void SetDrawTemplate(CXWndDrawTemplate*);
	void SetWindowTextA(const CXStr& Str);
	// protected
	static CXWndManager*& sm_pMgr;
	// private
	static unsigned char sm_byCurrentAlpha;
	int SetFont(void*);

	CXW;
};

class EQLIB_OBJECT CSidlScreenWnd
{
public:
	int GetContextMenuIndex() { return ContextMenuID; }
	UIType GetType();
	CXMLData* GetXMLData();
	CXWnd* GetChildItem(char* Name);
	CSidlScreenWnd() {};
	CSidlScreenWnd(CXWnd* pParent, const CXStr& Screen);
	CSidlScreenWnd(CXWnd* pWnd, const CXStr& Screen, int Flags, int IniVersion = 1, char* BlockName = nullptr);
	CSidlScreenWnd(CXWnd*, uint32_t, const CXRect&, const CXStr&);
	CScreenPieceTemplate* GetSidlPiece(CXStr*, bool bTopLevel=true) const;
	CXRect GetSidlPieceRect(CScreenPieceTemplate*, CXRect) const;
	CXWnd* GetChildItem(CXStr&, bool bDebug);
	int DrawSidlPiece(CScreenPieceTemplate*, CXRect, CXRect) const;
	void AddButtonToRadioGroup(CXStr, CButtonWnd*);
	void CalculateHSBRange();
	void CalculateVSBRange();
#if !defined(ROF2EMU) && !defined(UFEMU)
	void CreateChildrenFromSidl(DWORD = 0);
#else
	void CreateChildrenFromSidl();
#endif
	void EnableIniStorage(int, char*);
	void Init(int, CXStr*, int, int, int);
	void Init(CXWnd*, uint32_t, CXRect, CXStr, int, char*);
	void LoadIniListWnd(CListWnd*, char*);
	void SetScreen(CXStr*);
	void StoreIniListWnd(CListWnd const*, char*);
	void StoreIniVis();
	// virtual
	~CSidlScreenWnd();
	int DrawBackground() const;
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int HandleRButtonDown(const CXPoint&, uint32_t);
	int OnResize(int, int);
	int OnShow();
	int WndNotification(CXWnd*, uint32_t, void*);
	void LoadIniInfo();
	void StoreIniInfo();
	// protected
	int ConvertToRes(int, int, int, int);
	void LoadSidlScreen();
	// private
	static bool m_useIniFile;

	inline CXWnd* pXWnd() { return (CXWnd*)this; }

	CSW
};

class EQLIB_OBJECT _EverQuestinfo
{
public:
	void SetAutoAttack(bool);
};

class EQLIB_OBJECT _PackFileData
{
public:
	~_PackFileData();
	// virtual
	int readBlock();
};

class EQLIB_OBJECT _PackFileDataRawFile
{
public:
	// virtual
	int readBlock();
};

class EQLIB_OBJECT _partyGroup
{
public:
	int getNumMembers() const;
};

class EQLIB_OBJECT CAdvancedLootWnd : public CSidlScreenWnd
{
public:
	CAdvancedLootWnd(CXWnd*);
	DWORD DoAdvLootAction(DWORD listindex, CXStr* Name, DWORD Action, DWORD Quantity);
#if !defined(ROF2EMU) && !defined(UFEMU)
	DWORD DoSharedAdvLootAction(PLOOTITEM pLootItem, CXStr* Assignee, DWORD Action, DWORD Quantity);
#endif
	// virtual
	~CAdvancedLootWnd();
};

class EQLIB_OBJECT CRewardSelectionWnd : public CSidlScreenWnd
{
public:
	CRewardSelectionWnd(CXWnd*);
	// virtual
	~CRewardSelectionWnd();
};

class EQLIB_OBJECT CAltAbilityData
{
public:
	int GetMercCurrentRank(int);
	int GetMercMaxRank(int);
	int GetMaxRank();                   //it really is called GetMaxLevel but that doesnt make sense to me so... rank it is...
};

class EQLIB_OBJECT AltAdvManager
{
public:
	AltAdvManager();
	// IsAbilityReady was checked on apr 29 2016, it looks like it has 5 arguments in IDA, but it doesnt. (it has 4)
	bool IsAbilityReady(EQ_PC*, ALTABILITY*, int* Refresh/*out*/, int* Timer/*out*/ = 0);
	int AbilitiesByClass(int, int);
	int AltSkillReqs(EQ_PC*, int);
	int CalculateDoubleAttackChance(EQ_PC*, int, unsigned char);
	int CalculateFleetOfFoot(EQ_PC*);
	int CalculateHideTimeReduce(EQ_PC*);
	int CalculateInstrumentMasteryMod(EQ_PC*);
	int CalculateLoHHarmTouchReuseTimer(EQ_PC*, int);
	int CalculateMaxHPAA(EQ_PC*, int);
	int CalculateMaxStatAA(EQ_PC*, int);
	int CalculateMitigationBoost(EQ_PC*, int);
	int CalculateNimbleEvasionChance(EQ_PC*);
	int CalculateSingingMasteryMod(EQ_PC*, int);
	int CalculateSpellCastingMastery(EQ_PC*);
	int CalculateStalwartEnduranceChance(EQ_PC*);
	bool CanTrainAbility(PcZoneClient*, CAltAbilityData*, bool, bool, bool);
	bool CanSeeAbility(PcZoneClient*, CAltAbilityData*);
	int GetAALevelNeeded(EQ_PC*, int);
	int GetAbilityTitle(EQPlayer*);
	int GetNextAbilityCost(int, int);
	int MeetsPoPLevelReqs(EQ_PC*, int, int);
	int TotalPointsInSkill(int, int);
	unsigned long GetCalculatedTimer(EQ_PC*, ALTABILITY*);
	void GetAbilityReqs(char*, int);
#if !defined(ROF2EMU) && !defined(UFEMU)
	ALTABILITY* GetAAById(int index, int level = -1);
#else
	ALTABILITY* GetAAById(int index);
#endif
};

// we call this _AURAINFO
class AssociatedSOIData
{
public:
/*0x000*/ char         Name[0x40];
/*0x040*/ uint32_t     SpawnID;
/*0x044*/ int          Cost;
/*0x048*/ int          IconnID;
/*0x04c*/
};

// we call this _AURAMGR
class EQLIB_OBJECT ClientSOIManager
{
public:
	ArrayClass2_RO<AssociatedSOIData> Auras;

	static ClientSOIManager* GetSingleton();
};

class EQLIB_OBJECT CAuraWnd : public CSidlScreenWnd
{
public:
	CAuraWnd(CXWnd*);

	// virtual
	~CAuraWnd();
};

class EQLIB_OBJECT bad_word_class
{
public:
	bad_word_class(char*);
};

class EQLIB_OBJECT CAAWnd : public CSidlScreenWnd
{
public:
	CAAWnd(CXWnd*);
	~CAAWnd();

	void Activate();
	void CancelAASpend();
	void ConfirmAASpend();
	void SendNewPercent();
	void ShowAbility(int);
	void Update();
	void UpdateTimer();

	// virtual
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void Init();
	void UpdateSelected();
};

class EQLIB_OBJECT CActionsWnd : public CSidlScreenWnd
{
public:
	CActionsWnd(CXWnd*);
	CButtonWnd* GetAbilityBtn(int);
	CButtonWnd* GetCombatBtn(int);
	CButtonWnd* GetMenuBtn(int);
	int GetCurrentPageEnum() const;
	void Activate(int);
	void KeyMapUpdated();
	void SelectSkillForAbilityBtn(int);
	void SelectSkillForCombatBtn(int);
	void UpdateButtonText();

	// virtual
	~CActionsWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	int AbilitiesPageActivate();
	int AbilitiesPageDeactivate();
	int AbilitiesPageOnProcessFrame();
	int AbilitiesPageWndNotification(CXWnd*, uint32_t, void*);
	int CombatPageActivate();
	int CombatPageDeactivate();
	int CombatPageOnProcessFrame();
	int CombatPageWndNotification(CXWnd*, uint32_t, void*);
	int MainPageActivate();
	int MainPageDeactivate();
	int MainPageOnProcessFrame();
	int MainPageWndNotification(CXWnd*, uint32_t, void*);
	int RedirectActivateTo(CPageWnd*);
	int RedirectDeactivateTo(CPageWnd*);
	int RedirectOnProcessFrameTo(CPageWnd*);
	int RedirectWndNotificationTo(CPageWnd*, CXWnd*, uint32_t, void*);
	int SocialsPageActivate();
	int SocialsPageDeactivate();
	int SocialsPageOnProcessFrame();
	int SocialsPageWndNotification(CXWnd*, uint32_t, void*);
};

class EQLIB_OBJECT CAchievementsWnd : public CSidlScreenWnd
{
public:
	CAchievementsWnd(CXWnd*);
};

class EQLIB_OBJECT CRealEstateItemsWnd : public CSidlScreenWnd
{
public:
	CRealEstateItemsWnd(CXWnd*);
};

class EQGroundItem
{
public:
/*0x00*/ EQGroundItem* pPrev;
/*0x04*/ EQGroundItem* pNext;
/*0x08*/ VePointer<CONTENTS> pContents;
/*0x0c*/ DWORD         DropID;                   // unique id
/*0x10*/ DWORD         ZoneID;
/*0x14*/ DWORD         DropSubID;                // well zonefile id, but yeah...
/*0x18*/ void*         pSwitch;                  // CActorInterface
/*0x1c*/ char          Name[0x40];
/*0x5c*/ long          Expires;
/*0x60*/ float         Heading;
/*0x64*/ float	       Pitch;
/*0x68*/ float	       Roll;
/*0x6c*/ float	       Scale;
/*0x70*/ float         Y;
/*0x74*/ float         X;
/*0x78*/ float         Z;
/*0x7c*/ int           Weight;                   // -1 means it can't be picked up
/*0x80*/
};

class EQLIB_OBJECT EQGroundItemListManager
{
public:
	EQGroundItem*      Top;

	static EQGroundItemListManager& Instance();
};

// well we call this CTextOverlay but whatever should probably rename at some point...
class EQLIB_OBJECT CBroadcast
{
public:
	static CBroadcast* Get();
	void BroadcastString(const CXStr cxStr, int TextColor, int Priority, int MaxAlpha, UINT FadeInTime, UINT FadeOutTime, UINT DisplayTime);
	void BroadcastString(const char* Str, int TextColor, int Priority, int MaxAlpha, UINT FadeInTime, UINT FadeOutTime, UINT DisplayTime);
	void EndBroadcast(UINT FadeOutTime);
	void Draw();

	CTextObjectInterface* TextObject;
	bool               bBroadcastActive;
	bool               bFadingOut;
	bool               bFadingIn;
	UINT               StartTime;
	UINT               FadeInTime;
	UINT               EndTime;
	UINT               FadeOutTime;
	UINT               DisplayTime;
	int                BroadcastColor;
	int                CurrentPriority;
	int                MaxAlpha;
};

class EQLIB_OBJECT CAlarmWnd : public CSidlScreenWnd
{
public:
	CAlarmWnd(CXWnd*);
	void Activate();

	// virtual
	~CAlarmWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void DoNeverButton();
};

class EQLIB_OBJECT CBankWnd : public CSidlScreenWnd //, public WndEventHandler but we just add the member LastCheckTime
{
public:
/*0x238*/ UINT         LastCheckTime;            // from WndEventHandler

/*0x23c*/ int          MoneyButtonIndex;
/*0x240*/ UINT         NextRefreshTime;
/*0x244*/ bool         bInventoryWasActive;
/*0x245*/ bool         bRealEstateManagementWasActive;
/*0x248*/ CButtonWnd*  MoneyButtons[5];          // including shared plat
/*0x25C*/ CLabel*      BankerNameLabel;
/*0x260*/ CInvSlotWnd* InvSlotWindows[NUM_BANK_SLOTS];
/*0x2C0*/ CLabel*      SharedBankLabel;
/*0x2C4*/ CInvSlotWnd* SharedSlotWindows[NUM_SHAREDBANK_SLOTS];
/*0x2DC*/ CButtonWnd*  DoneButton;
/*0x2E0*/ CButtonWnd*  ChangeButton;
/*0x2E4*/ CButtonWnd*  AutoButton;
/*0x2E8*/ CButtonWnd*  AltStorageButton;
/*0x2EC*/ CButtonWnd*  FindItemButton;
/*0x2F0*/ int          BankSize;
/*0x2F4*/ int          Unknown0x2F4;
/*0x2F8*/ 

	CBankWnd(CXWnd*, CXStr);
	int GetNumBankSlots() const;
	void Activate(EQPlayer*);
	void Deactivate(bool);

	// virtual
	~CBankWnd();
	int OnProcessFrame();
	int PostDraw() const;
	int WndNotification(CXWnd* pWnd, unsigned int uiMessage, void* pData);
	void Deactivate();

	// private
	long GetBankQtyFromCoinType(int);
	void ClickedMoneyButton(int, int);
	void Init();
	void UpdateMoneyDisplay();
};

class EQLIB_OBJECT CBazaarSearchWnd : public CSidlScreenWnd
{
public:
	CBazaarSearchWnd(CXWnd*);
	char* GetPriceString(unsigned long);
	void Activate();
	void HandleBazaarMsg(char*, int);
	void UpdatePlayerCombo();
	void UpdatePlayerUpdateButton(bool);

	// virtual
	~CBazaarSearchWnd();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void AddItemtoList(char*, unsigned long, char*, int, int);
	void doQuery();
	void Init();
	void InitListArray();
	void SortItemList(int);
	void UpdateComboButtons();
};

class EQLIB_OBJECT CBazaarWnd : public CSidlScreenWnd
{
public:
	CBazaarWnd(CXWnd*);
	bool StoreSelectedPrice();
	char* GetPriceString(unsigned long);
	EQ_Item* ReturnItemByIndex(int);
	int UpdateBazaarListtoServer();
	long GetQtyFromCoinType(int);
	unsigned long GetPrice();
	void Activate();
	void AddBazaarText(char*, int);
	void AddEquipmentToBazaarArray(EQ_Item*, int, unsigned long);
	void BuildBazaarItemArray();
	void ClickedMoneyButton(int, int);
	void HandleTraderMsg(char*);
	void RebuildItemArray();
	void SelectBazaarSlotItem(int, CTextureAnimation*);
	void SetMoneyButton(int, int);
	void UpdatePriceButtons();

	// virtual
	~CBazaarWnd();
	int OnProcessFrame();
	int PostDraw() const;
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// protected
	void UpdateButtons();

	// private
	void CreateBZRIniFilename();
	void Init();
	void ToggleBzrItemActive(int, bool);
};

class EQLIB_OBJECT CBodyTintWnd : public CSidlScreenWnd
{
public:
	CBodyTintWnd(CXWnd*);
	char* BuildRBGTooltip(unsigned long, char* const);
	unsigned long GetButtonTint(int);
	unsigned long GetItemTint(int);
	void Activate();
	void GetReagentCount();
	void GetTintChangeCount();
	void ResetToOrigBodyTints();
	void SetSlotLabels(bool);
	void StoreModifiedBodyTints();
	void UpdateLabelsAndButtons();
	void UpdateLocalTintColor(unsigned long);
	void UpdateMaterialTintLocal(unsigned long);

	// virtual
	~CBodyTintWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
};

class EQLIB_OBJECT CBookWnd : public CSidlScreenWnd
{
public:
	CBookWnd(CXWnd*);
	bool CheckBook(EQ_Note*);
	void Activate();
	void SetBook(char*);

	// virtual
	~CBookWnd();
	int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// protected
	void CleanPages();
	void DisplayText();
	void ProcessText();
	void ShowButtons();

	// private
	void Init();
};

class EQLIB_OBJECT CBreathWnd : public CSidlScreenWnd
{
public:
	CBreathWnd(CXWnd*);
	void Activate();

	// virtual
	~CBreathWnd();
	int OnProcessFrame();
	void Deactivate();

	// private
	void Init();
};

enum BuffWindowType
{
	BuffWindowStandard,
	BuffWindowShortDuration,
	BuffWindowMelee
};

class EQLIB_OBJECT CBuffWindow : public CSidlScreenWnd
{
public:
	CBuffWindow(CXWnd*, BuffWindowType);
	void Activate();
	void SetBuffIcon(CButtonWnd*, int, int);

	// virtual
	~CBuffWindow();
	CXSize GetMinSize() const;
	int OnProcessFrame();
	int PostDraw() const;
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void HandleSpellInfoDisplay(CXWnd*);
	void Init();
	void RefreshBuffDisplay();
	void RefreshIconArrangement();
};

class EQLIB_OBJECT CBugReportWnd : public CSidlScreenWnd
{
public:
	CBugReportWnd(CXWnd*);
	void Activate();

	// virtual
	~CBugReportWnd();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void UpdateLocation();
};

class EQLIB_OBJECT CButtonDrawTemplate
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

	CButtonDrawTemplate();
	~CButtonDrawTemplate();
	CButtonDrawTemplate(const CButtonDrawTemplate&);
	CButtonDrawTemplate& operator=(const CButtonDrawTemplate&);
	CXSize GetSize() const;
};

class EQLIB_OBJECT CButtonTemplate
{
public:
	CButtonTemplate(CParamButton*);

	// virtual
	~CButtonTemplate();
};

class EQLIB_OBJECT CButtonWnd : public CXWnd
{
public:
/*0x1e0*/ int          MouseButtonState;
/*0x1e4*/ bool         bImage;
/*0x1e8*/ CRadioGroup* RadioGroup;
/*0x1ec*/ bool         Checked;
/*0x1ed*/ bool         Highlighted;
/*0x1f0*/ tagPOINT     DecalOffset;
/*0x1f8*/ tagSIZE      DecalSize;
/*0x200*/ COLORREF     DecalTint;
/*0x204*/ RECT         TextOffsets;
/*0x214*/ int          TextMode;
/*0x218*/ COLORREF     MouseoverColor;
/*0x21c*/ COLORREF     PressedColor;
/*0x220*/ COLORREF     DisabledColor;
/*0x224*/ UINT         CoolDownStartTime;
/*0x228*/ UINT         CoolDownDuration;
/*0x22c*/ CXSTR*       Indicator;
/*0x230*/ UINT         IndicatorValue;
/*0x234*/ void*        pIndicatorTextObject;
/*0x238*/ CXSTR*       Name;
/*0x23c*/ CTextureAnimation* TANormal;
/*0x240*/ CTextureAnimation* TAPressed;
/*0x244*/ CTextureAnimation* TAFlyby;
/*0x248*/ CTextureAnimation* TADisabled;
/*0x24c*/ CTextureAnimation* TAPressedFlyby;
/*0x250*/ CTextureAnimation* TAPressedDisabled;
/*0x254*/ CTextureAnimation* TANormalDecal;
/*0x258*/ CTextureAnimation* TAPressedDecal;
/*0x25c*/ CTextureAnimation* TAFlybyDecal;
/*0x260*/ CTextureAnimation* TADisabledDecal;
/*0x264*/ CTextureAnimation* TAPressedFlybyDecal;
/*0x268*/ CTextureAnimation* TAPressedDisabledDecal;
/*0x26c*/ bool         bAllowButtonPassThrough;
/*0x270*/ bool         bCooldownrelated;
/*0x274*/ bool         bIsCheckbox;
/*0x278*/ bool         bDrawLasso;               // draws the yellow border...
/*0x27c*/ uint32_t     ButtonStyle;

	CButtonWnd(CXWnd*, uint32_t, const CXRect&, const CXPoint&, const CXSize&, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*);
	void SetCheck(bool);

	// virtual
	// CButtonWnd() {};
	~CButtonWnd();
	bool IsPointTransparent(CXPoint) const;
	int Draw() const;
	int HandleLButtonDown(const CXPoint&, uint32_t);
	int HandleLButtonHeld(const CXPoint&, uint32_t);
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int HandleLButtonUpAfterHeld(const CXPoint&, uint32_t);
	int HandleMouseMove(const CXPoint&, uint32_t);
	int HandleRButtonDown(const CXPoint&, uint32_t);
	int HandleRButtonHeld(const CXPoint&, uint32_t);
	int HandleRButtonUp(const CXPoint&, uint32_t);
	int HandleRButtonUpAfterHeld(const CXPoint&, uint32_t);
	int OnProcessFrame();
	void SetAttributesFromSidl(CParamScreenPiece*);
	void SetRadioGroup(CRadioGroup*);
	UINT GetCoolDownTotalDuration() const;
	UINT GetCoolDownTimeRemaining() const;
};

class EQLIB_OBJECT CCastingWnd : public CSidlScreenWnd
{
public:
	CCastingWnd(CXWnd*);
	void Activate();

	// virtual
	~CCastingWnd();
	int OnProcessFrame();
	void Deactivate();
};

class EQLIB_OBJECT CCastSpellWnd : public CSidlScreenWnd
{
public:
	CCastSpellWnd(CXWnd*);
	static void Unmemorize(int);
	static void UnmemorizeList(int*, int);
	void Activate();
	void ForgetMemorizedSpell(int);
	void HandleSpellInfoDisplay(CXWnd*);
	void HandleSpellLeftClick(int);
	void HandleSpellRightClick(int);
	void KeyMapUpdated();
	void RecacheCategorizedSpells();
	void RecacheLoadoutContextMenu();
	void SpellBookDeactivating();

	// virtual
	~CCastSpellWnd();
	int OnProcessFrame();
	int PostDraw() const;
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	bool IsBardSongPlaying();
	unsigned long GetSpellGemColor(EQ_Spell*);
	void CategorizeSpell(int, int, int, int);
	void ClearSpellCategories();
	void Init();
	void MakeSpellSelectMenu();
	void RefreshSpellGemButtons();
	void UpdateSpellGems(int);
	void UpdateSpellGemTooltips(int);
};

class EQLIB_OBJECT CCharacterCreation : public CSidlScreenWnd
{
public:
	CCharacterCreation(CXWnd*);
	void Activate();
	void ActivateScreen(int);
	void DoBackButton();
	void DoNextButton();
	void HandleNameApprovalResponse(int);
	void NameGenerated(char*);

	// virtual
	~CCharacterCreation();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
	
	// private
	bool IsLackingExpansion(bool, bool);
	char* GetCharCreateText(char*, int, int, int, int);
	int GetClassButtonIndex(int);
	int GetRaceButtonIndex(int);
	void DoStatButton(int);
	void FinalizeNewPCAndSendToWorld();
	void Init();
	void InitNewPC();
	void InitStartingCities();
	void InitStats(bool);
	void RandomizeCharacter(bool, bool);
	void RandomizeFacialFeatures();
	void SelectedClassButton(int);
	void SelectedRaceButton(int);
	void SelectStartingCity(int);
	void SetNewPCDeityFromBtnIndex(int);
	void SetPlayerAppearanceFromNewPC(EQPlayer*, EQ_PC*, bool);
	void SubmitNameToWorld();
	void UpdatePlayerFromNewPC();
	void UpdateScreenZeroButtons(bool);
};

class EQLIB_OBJECT CCharacterListWnd : public CSidlScreenWnd
{
public:
	CCharacterListWnd(CXWnd*);
	int IsEmptyCharacterSlot(int);
	int IsValidCharacterSelected();
	int NumberOfCharacters();
	unsigned char IsEvil(int, int, int);
	void Activate();
	void DeleteCharacter();
	void EnterExplorationMode();
	void EnterWorld();
	void LeaveExplorationMode();
	void Quit();
	void UpdateList(bool bForceUpdate = false);
	void SelectCharacter(int charindex, bool bSwitchVisually = true, bool bForceUpdate = false /*dont mess with this*/);
	void SetLoadZonePlayerLocation();
	void SwitchModel(EQPlayer*, unsigned char, int, unsigned char, unsigned char);
	void UpdateButtonNames();

	// virtual
	~CCharacterListWnd();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void CreateExplorationModePlayers();
	void EnableButtons(bool);
	void EnableEqMovementCommands(bool);
	void Init();
	void RemoveExplorationModePlayers();
	void SetLocationByClass(EQPlayer*, bool, int);
	void SetRoomLocationByIndex(int, EQPlayer*);
};

class EQLIB_OBJECT CChatManager
{
public:
	~CChatManager();
	CChatManager();
	CChatWindow* GetActiveChatWindow();
	CChatWindow* GetChannelMap(int);
	CXStr GetAllVisibleText(CXStr);
	int GetChannelFromColor(int);
	int InitContextMenu(CChatWindow*);
	unsigned long GetRGBAFromIndex(int);
	void Activate();
	void AddText(CXStr, int);
	void ClearChannelMap(int);
	void ClearChannelMaps(CChatWindow*);
	void CreateChatWindow(char*, char*, int, int, int, char*, int);
	void CreateChatWindow();
	void Deactivate();
	void FreeChatWindow(CChatWindow*);
	void LoadChatInis();
	void Process();
	void SetActiveChatWindow(CChatWindow*);
	void SetChannelMap(int, CChatWindow*);
	void SetLockedActiveChatWindow(CChatWindow*);
	void UpdateContextMenus(CChatWindow*);
	void UpdateTellMenus(CChatWindow*);
	CChatWindow*GetLockedActiveChatWindow();
#if !defined(ROF2EMU) && !defined(UFEMU)
	void CreateChatWindow(CXWnd* pParentWnd, int ID, char* Name, int Language, int DefaultChannel, int ChatChannel, char* szTellTarget, int FontStyle, bool bScrollbar, bool bHighLight, COLORREF HighlightColor);
#else
	void CreateChatWindow(char* Name, char*IniName, int Language, int DefaultChannel, int ChatChannel, char* szTellTarget, int FontStyle, bool bScrollbar);
#endif
};

class EQLIB_OBJECT ChatManagerClient : public CChatManager
{
public:
	static ChatManagerClient& Instance();
};

class EQLIB_OBJECT CChatWindow : public CSidlScreenWnd
{
public:
	CChatWindow(CXWnd*);
	CEditWnd* GetInputWnd();
	CStmlWnd* GetOutputWnd();
	CXStr GetInputText();
	void AddHistory(CXStr Text);
	void AddOutputText(PCXSTR, int);
	void Clear();
	void HistoryBack();
	void HistoryForward();
	void PageDown();
	void PageUp();
	void SetChatFont(int);

	// virtual
	~CChatWindow();
	int Draw() const;
	int HandleRButtonDown(const CXPoint&, uint32_t);
	int OnKillFocus(CXWnd*);
	int OnProcessFrame();
	int OnSetFocus(CXWnd*);
	int WndNotification(CXWnd*, uint32_t, void*);
	void operator delete[](void*);
	void Deactivate();

/*0x220*/ EQCHATMGR*   ChatManager; 
/*0x224*/ CSIDLWND*    InputWnd;
/*0x228*/ CSIDLWND*    OutputWnd;
/*0x22c*/ int          ChatChannel;
/*0x230*/ int          ChatChannelIndex;
/*0x234*/ char         TellTarget[0x40];
/*0x274*/ int          Language;
/*0x278*/ bool         bIsMainChat;
/*0x279*/ bool         bIsTellWnd;
/*0x27c*/ CXSTR*       CommandHistory[0x28];     // ->0x198
/*0x31c*/ int          HistoryIndex;
/*0x320*/ int          HistoryLastShown;
/*0x324*/ int          FontSize;                 // style
/*0x328*/ int          AlwaysChathereIndex;      // menu
/*0x32c*/ int          DontKnow;
/*0x330*/
};

class EQLIB_OBJECT CCheckBoxWnd : public CButtonWnd
{
public:
	bool bOrgState;

	CCheckBoxWnd(CXWnd*, uint32_t, const CXRect&, const CXPoint&, const CXSize&, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*);
	void SetRadioLook();

	// virtual
	~CCheckBoxWnd();
	int HandleLButtonDown(const CXPoint&, uint32_t);
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int HandleMouseMove(const CXPoint&, uint32_t);
	void SetRadioGroup(CRadioGroup*);

	// protected
	static bool sm_bAnimsInitialized;
	static CButtonDrawTemplate sm_bdtCheck;
	static CButtonDrawTemplate sm_bdtRadio;
};

class EQLIB_OBJECT CClickStickInfo
{
public:
	CClickStickInfo();

	// virtual
	~CClickStickInfo();

/*0x00*/ DWORD         vfTable;
/*0x04*/ CXWnd*        FromWnd;
/*0x08*/ CXWnd*        ToWnd;
/*0x10*/ POINT         FromPoint;
/*0x18*/ POINT         ToPoint;
/*0x20*/ int           Code;
/*0x24*/ void*         Data;
/*0x28*/
};

class EQLIB_OBJECT CCollisionInfoTargetVisibility
{
public:
	// CCollisionInfoTargetVisibility(const CLineSegment& rLineSegment, const PlayerBase* pPlayerSelf, const PlayerBase* pPlayerOther);
	CCollisionInfoTargetVisibility(CLineSegment* rLineSegment, EQPlayer* pSelf, EQPlayer* pOther);
};

class WndEventHandler2
{
public:
	UINT LastCheckTime;

	WndEventHandler2();
	void OnWndEvent(CXWnd*pwndSender) const;
};

class EQLIB_OBJECT CColorPickerWnd : public CSidlScreenWnd, public WndEventHandler2
{
public:
	int                ContextMenuIndex;
	int                MaxSliderValue;
	CXWnd*             pwndCaller;
	CButtonWnd*        ColorButton[16];
	int                RedSliderValue;
	CSliderWnd*        RedSlider;
	CEditWnd*          RedSliderInputEdit;
	int                GreenSliderValue;
	CSliderWnd*        GreenSlider;
	CEditWnd*          GreenSliderInputEdit;
	int                BlueSliderValue;
	CSliderWnd*        BlueSlider;
	CEditWnd*          BlueSliderInputEdit;
	CButtonWnd*        AcceptButton;

	CColorPickerWnd(CXWnd* pwndParent);
	void Activate(CXWnd*, unsigned long);
	void CheckMaxEditWnd();
	void SetCurrentColor(unsigned long);
	void SetTemplateColor(int, unsigned long);
	void UpdateCurrentColor();
	void UpdateEditWndFromSlider(CSliderWnd* pSlider, CEditWnd* pEdit, int* value);
	void UpdateSliderFromEditWnd(CSliderWnd* pSlider, CEditWnd* pEdit, int* value);
	void Deactivate();
	void Init();
	int Open(CXWnd* pwndCaller, D3DCOLOR CurrentColor = 0x00FFFFFF);
	virtual bool AboutToHide();
	virtual int WndNotification(CXWnd* pwndSender, UINT Msg, void* pData);
	virtual void OnWndNotification();
};

class EQLIB_OBJECT CCombatSkillsSelectWnd : public CSidlScreenWnd
{
public:
	CCombatSkillsSelectWnd(CXWnd*);

	// virtual
	~CCombatSkillsSelectWnd();

	// private
	bool ShouldDisplayThisSkill(int);
};

class EQLIB_OBJECT CComboboxTemplate
{
public:
	CComboboxTemplate(CParamCombobox*);
	// virtual
	~CComboboxTemplate();
};

class EQLIB_OBJECT CComboWnd// : public CXWnd
{
public:
	CXW
/*0x1e0*/ CListWnd*                    pListWnd;
/*0x1e4*/ int                          ListHeightMax;
/*0x1e8*/ int                          ListHeight;
    // CButtonDrawTemplate starts here but we cant use it cause it will call the contructor if we do...
/*0x1ec*/ CXStr*                       Name;
/*0x1f0*/ CTextureAnimation*           Normal;
/*0x1f4*/ CTextureAnimation*           taPressed;
/*0x1f8*/ CTextureAnimation*           Flyby;
/*0x1fc*/ CTextureAnimation*           taDisabled;
/*0x200*/ CTextureAnimation*           PressedFlyby;
/*0x204*/ CTextureAnimation*           PressedDisabled;
/*0x208*/ CTextureAnimation*           NormalDecal;
/*0x20c*/ CTextureAnimation*           PressedDecal;
/*0x210*/ CTextureAnimation*           FlybyDecal;
/*0x214*/ CTextureAnimation*           DisabledDecal;
/*0x218*/ CTextureAnimation*           PressedFlybyDecal;
/*0x21c*/ CTextureAnimation*           PressedDisabledDecal;

	CComboWnd(CXWnd*, uint32_t, const CXRect&, int, const CButtonDrawTemplate&, CListWnd*);
	CXRect GetButtonRect() const;
#if !defined(ROF2EMU) && !defined(UFEMU)
	CXRect GetListRect(bool) const;
#else
	CXRect GetListRect() const;
#endif
	CXRect GetTextRect() const;
	CXStr GetCurChoiceText() const;
	int GetCurChoice() const;
	int GetItemCount();
	void DeleteAll();
	void InsertChoice(CXStr*, unsigned long);
	void InsertChoice(char*);
	void SetChoice(int);
	void SetColors(unsigned long, unsigned long, unsigned long);

	// virtual
	~CComboWnd();
	CXSize GetMinSize() const;
	int Draw() const;
	int HandleLButtonDown(const CXPoint&, uint32_t);
	int HitTest(CXPoint, int*) const;
	int OnMove(const CXRect&);
	int OnResize(int, int);
	int WndNotification(CXWnd*, uint32_t, void*);
	void SetDrawTemplate(CXWndDrawTemplate*);
};

class EQLIB_OBJECT CCompassWnd : public CSidlScreenWnd
{
public:
	CCompassWnd(CXWnd*);
	void Activate();
	void SenseHeading();

	// virtual
	~CCompassWnd();
	int Draw() const;
	int OnProcessFrame();
	void Deactivate();

	// protected
	static double const HI_SPEED;
	static double const LO_SPEED;
	void PickNewTarget();
	void SetSpeed();

	// private
	void Init();
};

class EQLIB_OBJECT CConfirmationDialog : public CSidlScreenWnd
{
public:
	CConfirmationDialog(CXWnd*);
	void Activate(int, unsigned int, const char*, int, int, int, int);
	void HandleButtonNoPressed();
	void HandleButtonOkPressed();
	void HandleButtonYesPressed();
	void ProcessNo(int);
	void ProcessYes();
	void SetNameApprovalData(char*, char*, int, int, char*);

	// virtual
	~CConfirmationDialog();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void ExpireCurrentDialog();
	void Init();
	void ResetFocusOnClose();

	// Data members
/*0x15c*/ CXWND*       OutputText;
/*0x160*/ CXWND*       pYesButton;
/*0x164*/ CXWND*       pNoButton;
/*0x168*/ DWORD        Unknown0x168;
/*0x16c*/ CXWND*       pOKButton;
/*0x170*/ BYTE         Unknown0x170[0x18];
/*0x188*/
};

class EQLIB_OBJECT ItemBase
{
public:
	bool IsLore(bool bIncludeSockets = false) const;
	bool IsLoreEquipped(bool bIncludeSockets = false) const;
};

class EQLIB_OBJECT ItemGlobalIndex
{
public:
	ItemContainerInstance Location;
	ItemIndex Index;

	ItemGlobalIndex();
	bool IsKeyRingLocation();
	bool IsEquippedLocation();
	bool IsValidIndex();
};

class EQLIB_OBJECT CContainerMgr
{
public:
	void*              vfTable;
	CContainerWnd*     pContainerWnds[38];
	ArrayClass<CContainerWnd*> ContainerWndsToDelete;
	VePointer<CONTENTS> pWorldContainer;
	DWORD              WorldContainerSerialNumber;
	int                WorldContainerRealEstateID;
	int                WorldContainerRealEstateItemID;
	DWORD              Timer;
	bool               bShowDone;

	CContainerMgr();
	bool CloseAllContainers();
	EQ_Item* GetWorldContainerItem(int);
	void ClearWorldContainerItems();
	void CloseContainer(EQ_Container*, bool);
	void CloseEQContainer(EQ_Container*);
	void OpenContainer(EQ_Container*, int, bool);
	void OpenWorldContainer(EQ_Container*, unsigned long);
	void Process();
	void SetWorldContainerItem(EQ_Item*, int);

	// virtual
	~CContainerMgr();

	// private
	CContainerWnd* GetFreeContainerWnd();
	void OpenExperimentContainer(const VePointer<CONTENTS>& pCont, const ItemGlobalIndex& Location);
};

class EQLIB_OBJECT CContainerWnd : public CSidlScreenWnd
{
public:
	CContainerWnd(CXWnd*);
	void Activate();
	void CheckCloseable();
	void SetContainer(PCONTENTS &pContainer, const ItemGlobalIndex& location);

	// virtual
	~CContainerWnd();
	int OnProcessFrame();
	int PostDraw() const;
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	bool ContainsNoDrop();
	void HandleCombine();
	void Init();

/*0x04*/ PCONTENTS     pCont;
/*0x08*/ ItemGlobalIndex Location;
/*0x14*/ VeArray<CInvSlotWnd*> InvSlotWnds;
/*0x18*/ CButtonWnd*   pCombineButton;
/*0x1c*/ CButtonWnd*   pDoneButton;
/*0x20*/ CButtonWnd*   pStandardDoneButton;
/*0x24*/ CButtonWnd*   pCombineDoneButton;
/*0x28*/ CButtonWnd*   pContainerIcon;
/*0x2c*/ CButtonWnd*   pContainerStandardIcon;
/*0x30*/ CButtonWnd*   pContainerCombineIcon;
/*0x34*/ CTextureAnimation* pIconAnimation;
/*0x38*/ CLabel*       ContainerLabel;
/*0x3c*/ CInvSlotWnd*  pContainerSlotTemplate;
/*0x40*/ CXWnd*        pStandardItems;
/*0x44*/ CXWnd*        pStandardItemsWithDone;
/*0x48*/ CXWnd*        pCombineItems;
/*0x4c*/ CStmlWnd*     pStandardSize;
/*0x50*/ CStmlWnd*     pCombineSize;
/*0x54*/ bool          bCombineValid;
/*0x55*/ bool          bUserCloseable;
/*0x58*/ int           ContainerType;            // classic = 0, standard = 1, combine = 2
/*0x5c*/ int           IndexDoneButton;
/*0x60*/ CContextMenu* ContextMenu;
/*0x64*/ 
};

class CContextMenuManager : public CXWnd
{
public:
	CXWnd*             pParentMenuWnd;
	CContextMenu*      pCurrMenus[8];
	int                NumVisibleMenus;
	int                CurrMenu;
	CContextMenu*      pMenus[0x400];
	int                NumMenus;
	CXWnd*             pHandlerWnd;
	int                HandlerCmd;
	int                DefaultMenuIndex;
	int                DefaultHelpItem;
	int                DefaultBGItem;
	int                DefaultMinItem;
	int                DefaultCloseItem;
	int                DefaultLockItem;
	int                DefaultEscapeItem;

	CContextMenuManager(CXWnd*, uint32_t, const CXRect&);
	int AddMenu(CContextMenu*);
	int GetDefaultMenuIndex() { return DefaultMenuIndex; }
	CContextMenu*GetMenu(int);
	int HandleWindowMenuCommands(CXWnd*, int);
	int PopupMenu(int, const CXPoin&, CXWnd*);
	int RemoveMenu(int, bool);
	void Flush();
	void WarnDefaultMenu(CXWnd*);

	// virtual
	~CContextMenuManager();
	int HandleLButtonDown(const CXPoint&, uint32_t);
	int HandleRButtonDown(const CXPoint&, uint32_t);
	int HandleWheelButtonDown(CXPoint, uint32_t);
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void CreateDefaultMenu();
};

class EQLIB_OBJECT CScreenPieceTemplate
{
public:
/*0x00*/ void*         vfTable;
/*0x04*/ ArrayClass2_RO<uint32_t> RuntimeTypes;
/*0x20*/ CXSTR*        Name;
/*0x24*/ uint32_t      ParamObjectID;
/*0x28*/ CXSTR*        ScreenID;
/*0x2c*/ uint32_t      Font;
/*0x30*/ bool          bRelativePosition;
/*0x31*/ bool          bAutoStretchVertical;
/*0x32*/ bool          bAutoStretchHorizontal;
/*0x33*/ bool          bTopAnchorToTop;
/*0x34*/ bool          bBottomAnchorToTop;
/*0x35*/ bool          bLeftAnchorToLeft;
/*0x36*/ bool          bRightAnchorToLeft;
/*0x38*/ int           TopOffset;
/*0x3c*/ int           BottomOffset;
/*0x40*/ int           LeftOffset;
/*0x44*/ int           RightOffset;
/*0x48*/ int           MinVSize;
/*0x4c*/ int           MinHSize;
/*0x50*/ int           MaxVSize;
/*0x54*/ int           MaxHSize;
/*0x58*/ RECT          Rect;
/*0x68*/ CXSTR*        Text;
/*0x6c*/ D3DCOLOR      TextColor;
/*0x70*/ D3DCOLOR      DisabledColor;
/*0x74*/ D3DCOLOR      EnabledColor;
/*0x78*/ bool          bUseInLayoutHorizontal;
/*0x79*/ bool          bUseInLayoutVertical;
/*0x7c*/ D3DCOLOR      BackgroundTextureTint;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x80*/ D3DCOLOR      DisabledBackgroundTextureTint;
#endif
/*0x84*/
	CScreenPieceTemplate(CParamScreenPiece*);
	bool IsType(uint32_t) const;
	CXStr GetName() const;

	// virtual
	~CScreenPieceTemplate();
};

class EQLIB_OBJECT CControlTemplate : public CScreenPieceTemplate
{
public:
/*0x84*/ uint32_t      StyleBits;
/*0x88*/ BYTE          SizableMask;
/*0x89*/ bool          bEscapable;
/*0x8c*/ CXSTR*        Tooltip;
/*0x90*/ CXWndDrawTemplate* pDrawTemplate;
/*0x94*/ CXSTR*        Controller;
/*0x98*/ void*         pLayoutStrategyTemplate;  // CLayoutStrategyTemplate
/*0x9c*/

	CControlTemplate(CParamControl*);

	// virtual
	~CControlTemplate();
};

class HasATimer
{
	UINT Timer;
};

class EQLIB_OBJECT CCursorAttachment // : public CSidlScreenWnd : public HasATimer
{
public:
/*0x000*/ CSIDLWNDVFTABLE* pvfTable;
	CXW_NO_VTABLE
	SIDL
/*0x220*/ UINT         Timer;
/*0x224*/ int          Type;
/*0x228*/ int          Index;
/*0x22c*/ EqItemGuid   ItemGuid;
/*0x240*/ int          ItemID;
/*0x244*/ int          Qty;
/*0x248*/ CXStr*       ButtonText;
	// and more...

	CCursorAttachment(CXWnd*);
	bool IsOkToActivate(int);
	bool RemoveAttachment();
	void Activate(CTextureAnimation*, int, int, int);
	// virtual
	~CCursorAttachment();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	// void* `scalar deleting destructor'(unsigned int);
	// void* `vector deleting destructor'(unsigned int);
	void Deactivate();
	// private
	void DrawButtonText() const;
	void DrawQuantity() const;
	void Init();
#if !defined(ROF2EMU) && !defined(UFEMU)
	void AttachToCursor(CTextureAnimation* Overlay, CTextureAnimation* pTABG, int Type, int Index, const char* Assigned_Name, const char*Name, int Qty = -1, int IconID = -1);
	void AttachToCursor(CTextureAnimation* Overlay, CTextureAnimation* pTABG, int Type, int Index, const EqItemGuid& ItemGuid, int ItemID, const char *Assigned_Name, const char*Name, int Qty = -1, int IconID = -1);
#else
	void AttachToCursor(CTextureAnimation* Overlay, CTextureAnimation* pTABG, int Type, int Index, const char* Name, int Qty = -1);
	void AttachToCursor(CTextureAnimation* Overlay, CTextureAnimation* pTABG, int Type, int Index, const EqItemGuid& ItemGuid, int ItemID, const char*Name, int Qty = -1);
#endif
};

class EQLIB_OBJECT CDIMap
{
public:
	~CDIMap();
	CDIMap();
	// private
	static char* mKeymapAltArray;
	static char* mKeymapArray;
	static char* mKeymapShiftArray;
	void LoadMappingFromFile(char*);
};

class EQLIB_OBJECT CVector3
{
public:
	CVector3(float x, float y, float z) : X(x), Y(y), Z(z) {}
	CVector3() {}

	// float GetLength() const;
	float NormalizeAndReturnLength();
	void Normalize();

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
		X = Y = Z = FLOAT_MAX;
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

	CVector3 operator-(const CVector3& vec) const
	{
		CVector3 res;
		res.Set(X - vec.X, Y - vec.Y, Z - vec.Z);

		return res;
	}

	CVector3 operator+(const CVector3& vec) const
	{
		CVector3 res;
		res.Set(vec.X + X, vec.Y + Y, vec.Z + Z);
	
		return res;
	}

	float GetDistanceSquared(const CVector3& vec) const
	{
		CVector3 Delta = *this - vec;
		return Delta.GetLengthSquared();
	}

	float X;
	float Y;
	float Z;
};

struct physicsinfo; // now CPhysicsInfo

class EQLIB_OBJECT CDisplay
{
public:
/*0x0000*/ BOOL        ErrorFlag;
/*0x0004*/ BYTE        BFog;
/*0x0005*/ BYTE        BMoveAnims;
/*0x0008*/ float       Yon;
/*0x000c*/ float       AmbientLight;
/*0x0010*/ BYTE        DragItem;
/*0x0011*/ BYTE        DragMoney;
/*0x0012*/ BYTE        DragHotButton;
/*0x0013*/ bool        bInRenderLoop;
/*0x0014*/ bool        bHideLootedCorpses;
/*0x0015*/ char        LastTeleportAreaTag[0x100];
/*0x0118*/ void*       pCamera;                  // CCameraInterface
/*0x011c*/ CVector3*   CamPos;
/*0x0120*/ CVector3*   CamOrientation;
/*0x0124*/ void*       WadFileLoadScreen;        // SWadFile
/*0x0128*/ BYTE        NewPCModelsLoaded;
/*0x0129*/ bool        bHorsesLoaded;
/*0x012c*/ void*       pActorTagManager;
/*0x0130*/ BYTE        Unknown0x130[0x24];
/*0x0154*/ DWORD       TimeStamp;
/*0x0158*/ BYTE        Unknown0x158[0x2c12];
/*0x2d6a*/ BYTE        NpcNames;                 // show npc names

	~CDisplay();
	CDisplay(HWND);
	bool GenericSphereColl(float, float, float, float, float, float, float*, float*, float*, unsigned char);
	bool SlideSwitchLeftRight(EQSwitch*, float, int, float);
	bool const GetWorldFilePath(char*, const char*);
	char* GetIniRaceName(int);
	EQPlayer* GetNearestPlayerInView(float, bool);
	float FindZoneTopZ(float, float, float);
	float FixHeading(float);
	float GetFloorHeight(float X, float Y, float F, float Radius = 0.0f, CVector3& CollisionVector = CVector3(-1, -1, 1), CActorApplicationData* pAppData = 0, EActorType eActorType = Undefined, float ZOffset = 1.0f);
	float HeadingDiff(float, float, float*);
	float PlayerDistance(EQPlayer*, EQPlayer*, float);
	float PlayerSimpleDistance(EQPlayer*, EQPlayer*, float);
	float SetActorBoundingRadius(CActorInterface*, float, float);
	float SimpleDistance(float, float, float, float, float, float, float);
	float TrueDistance(float fromx, float fromy, float fromz, float tox, float toy, float toz, float zfactor);
	int GetItemType(int);
	int GetNewPCIniFlag(int, int);
	int GetSkyTime(int*, int*);
	int is_3dON();
	int is_ParticleSystemON();
	int MoveMissile(EQMissile*);
	int ShouldLoadNewPcModel(int, int);
	int TurnInfravisionEffectOff();
	int TurnInfravisionEffectOn();
	long SetUserRender(int);
	static char* DefaultUIPath;
	static char* UIPath;
	static int __cdecl WriteTextHD2(const char*text, int X, int Y, int color);
	static unsigned long __cdecl GetUserDefinedColor(int);
	static void __cdecl SetUserDefinedColor(int, int, int, int);
	CLightInterface* CreateLight(unsigned char, float, float, float, float);
	CActorInterface* CreateActor(char*, float, float, float, float, float, float, bool, bool);
	CActorInterface* GetClickedActor(int X, int Y, bool bFlag, CVector3& Vector1, CVector3& Vector2);
	unsigned char GetEnvironment(float, float, float, int*);
	unsigned char GetIntensity(unsigned char);
	unsigned char LoadBMPFile();
	unsigned char LoadNPCFromS3D(char*, char*, char*);
	unsigned char LoadWorldFile(char*, char*, int, unsigned char);
	unsigned int IsShield(int) const;
	void ActivateMainUI(bool);
	void ChangeVideoMode();
	void CheckForScreenModeToggle();
	void CleanUpDDraw();
	void ClearScreen();
	void CreatePlayerActor(EQPlayer*);
	void DDrawUpdateDisplay();
	void DeactivateMainUI();
	void default_cameras();
	void DefineSoloMode();
	void DeleteActor(CActorInterface*);
	void DeleteLight(CLightInterface*);
	void GetOnActor(CActorInterface*, EQPlayer*);
	void HandleMaterial(EQ_PC*, int, EQ_Item*, EQ_Item*);
	void hideGrassObjects();
	void InitCharSelectUI();
	void InitCommonLights();
	void InitDDraw();
	void InitEverQuestLocale(EQLocalizeLanguage);
	void InitUserDefinedColors();
	void InitWorld();
	void KeyMapUpdated();
	void LightningStrike();
	void loadGrassObjects(char*);
	void MoveLight(CLightInterface*, physicsinfo*);
	void MoveLocalPlayerToSafeCoords();
	void NewUIProcessEscape();
	void PlaySoundAtLocation(float, float, float, int);
	void ProcessCloud();
	void ProcessEffects();
	void ProcessParticleEmitter(EQSwitch*);
	void ProcessSky();
	void ProcessSwitches();
	void ProcessWeather();
	void RealRender_World();
	void ReloadUI(bool);
	void Render_MinWorld();
	void Render_World();
	void ResetRenderWindow();
	void SetActorScaleFactor(CActorInterface*, float, unsigned char);
	void SetActorSpriteTint(EQRGB*, CActorInterface*);
	void SetActorUserData(CActorInterface*, void*);
	void SetActorYon(float);
	void SetAmbientLight(float);
	void SetCCreateCamera(int);
	void SetDayPeriod(unsigned char);
	void SetFog(bool, float, float, unsigned char, unsigned char, unsigned char);
	void SetGammaCorrection(float);
	void SetGenericEnvironment();
	void SetPCloudDensity(int);
	void SetSkyBackground();
	void SetSkyLayer(int);
	void SetSpecialEnvironment(EnvironmentType);
	void SetSunLight();
	void SetupEmitterEnvironment();
	void SetupEQPlayers();
	void SetViewActor(CActorInterface*);
	void SetRenderWindow(int mode);
	void ToggleScreenshotMode();
	void SetViewActorByName(char*);
	void SetViewAngle(int);
	void SetYon(float);
	void ShowDisplay();
	void StartWeather(int, unsigned char);
	void StartWorldDisplay(EQZoneIndex);
	void StartWorldDisplay_Bailout(const char*);
	void StopWeather(int, unsigned char);
	void StopWorldDisplay();
	void SwitchToDefaultCameraMode();
	void ToggleCharacterNameSprites(bool);
	void ToggleNpcNameSprites(bool);
	void ToggleView();
	void UpdateCameraAfterModeSwitch();
	void updateGrassObjects();
	void UpdateMobileEmitterLocations();
	void FreeAllItemLists();

	// private
	void CleanCharSelectUI();
	void CleanGameUI();
	void CleanUpNewUI();
	void InitGameUI();
	void InitNewUI();
};

class EQLIB_OBJECT CDistillerInfo
{
public:
	static CDistillerInfo &Instance();
	int GetIDFromRecordNum(int ID, bool bWhat);
};

enum eTextAlign
{
	eta_Left,
	eta_Center,
	eta_Right,
};

class EQLIB_OBJECT CEditBaseWnd //ok Look... this SHOULD inherit CXWnd but doing so... calls the constructor, and we dont want that... so... : public CXWnd
{
public:
	// we include CXW instead...
/*0x000*/ CXW

/*0x1F0*/ eTextAlign   eAlign;//see 8EAC07 in eqgame 11 sep 2017 test - eqmule
/*0x1F4*/ int          StartPos;
/*0x1F8*/ int          EndPos;
/*0x1Fc*/ int          MaxChars;
/*0x200*/ int          MaxBytesUTF8;
/*0x204*/ CXSTR*       InputText;
/*0x208*/ int          TagPrintableStarts[0xa];
/*0x230*/ int          TagPrintableEnds[0xa];
/*0x258*/ int          TagOriginalStarts[0xa];
/*0x280*/ int          TagOriginalEnds[0xa];
/*0x2a8*/ int          TagDynamicSize[0xa];
/*0x2d0*/ int          TagCodes[0xa];
/*0x2f8*/ CXSTR*       TagStrings[0xa];
/*0x320*/ int          TagCount;
/*0x324*/ uint32_t     EditWndStyle;
/*0x328*/

	void SetMaxChars(int);
	void SetSel(int, int);

	// virtual
	~CEditBaseWnd();
	int OnKillFocus(CXWnd*);
};

class EQLIB_OBJECT CEditboxTemplate
{
public:
	CEditboxTemplate(class CParamEditbox*);
	// virtual
	~CEditboxTemplate();
};

class EQLIB_OBJECT CEditLabelWnd : public CSidlScreenWnd
{
public:
	CEditLabelWnd(CXWnd*);
	CXStr GetLabelText();
	void Activate(CXWnd*, char*, int, unsigned long);

	// virtual
	~CEditLabelWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
};

class CEditWnd : public CEditBaseWnd
{
public:
/*0x328*/ bool         bAnchorAtStart;
/*0x329*/ bool         bCaretAtEnd;
/*0x32a*/ bool         bAutoVScrollCalc;
/*0x32b*/ bool         bEditable;
/*0x32c*/ CXSTR*       FilterChars;
/*0x330*/ int          EditMode;
/*0x334*/ wchar_t      PasswordChar;
/*0x338*/ ArrayClass2_RO<uint32_t> LineIndices;
/*0x354*/

	CEditWnd(CXWnd*, uint32_t, const CXRect&, uint32_t);
	CXPoint GetCharIndexPt(int) const;
	CXPoint GetSelEndPt() const;
	CXPoint GetSelStartPt() const;
	CXStr GetSTMLSafeText();
	int ConvertIndexPrintableToTagged(int);
	int ConvertIndexTaggedToPrintable(int);
	int GetLineForPrintableChar(int) const;
	int GetLineLength(int) const;
	int SelectableCharFromPoint(CXPoint) const;
	void AddItemTag(int, char*, int);
	void CalculateScrollRange();
	void EnsureCaretVisible();
	void ReplaceSelection(char, bool);
	void ReplaceSelection(CXStr, bool);
	void SetEditable(bool);

	// virtual
	~CEditWnd();
	CXPoint GetCaretPt() const;
	CXPoint PointFromPrintableChar(int) const;
	CXStr GetDisplayString() const;
	CXStr GetWindowText() const;
	int Draw() const;
	int DrawCaret() const;
	int DrawMultiline() const;
	int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	int HandleLButtonDown(const CXPoint&, uint32_t);
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int HandleMouseMove(const CXPoint&, uint32_t);
	int OnKillFocus(CXWnd*);
	int OnMove(class CXRect);
	int OnResize(int, int);
	int OnSetFocus(CXWnd*);
	int ResetWnd();
	void SetWindowTextA(const CXStr& Str);

	// protected
	static CDIMap m_mapKeys;
	// virtual int GetHorzOffset() const;
	void FillIndexArray(CXStr) const;
	void FilterInputStr(CXStr &);
	void ProcessText();
};

class EQLIB_OBJECT UniversalChatProxy
{
public:
	char* GetChannelName(int channelNumber);
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
/*0x08*/ CXSTR*        Name;
/*0x0c*/ SIZE          TextureSize;
/*0x14*/ UINT          TextureID;
/*0x18*/
};

struct SuiteTexture
{
	bool               bUsed;
	CXSTR*             Name;
	enDir              Directory;
	BMI*               pBMInfo;
};
using PSuiteTexture = SuiteTexture*;

class EQLIB_OBJECT CEQSuiteTextureLoader
{
public:
	void*              pWadFile; // SWadFile
	ArrayClass_RO<SuiteTexture> Textures;
	CXSTR*             UIPath[4];
	CXSTR*             DefaultUIPath[4];

	~CEQSuiteTextureLoader();
	CEQSuiteTextureLoader();
	BMI* GetTexture(const CUITextureInfo2 &ti);
	unsigned int CreateTexture(const CUITextureInfo&);
	void UnloadAllTextures();
	const CXStr& GetDefaultUIPath(int DirType) const;
};

struct TARGETRING
{
/*0x00*/ DWORD         Gem;                      // the gem the spell below is memmed in... 0-11
/*0x04*/ PSPELL        thespell;
/*0x08*/ ItemGlobalIndex ItemLoc;
/*0x14*/ ItemSpellTypes SpellType;
/*0x18*/ float         SquaredRange;
/*0x1c*/ bool          bCursorVisible;
/*0x20*/
};
using PTARGETRING = TARGETRING*;

struct EQSuccessfulHit
{
/*0x00*/ uint16_t      DamagedID;                // Spawn that was hit
/*0x02*/ uint16_t      AttackerID;               // spawn who did the hit
/*0x04*/ uint8_t       Skill;                    // 1 HS etc...
/*0x05*/ uint8_t       Filler0x5[0x3];
/*0x08*/ int           SpellID;
/*0x0c*/ int           DamageCaused;
/*0x10*/ float         Force;
/*0x14*/ float         HitHeading;
/*0x18*/ float         HitPitch;
/*0x1c*/ bool          bSecondary;
/*0x1d*/ uint8_t       Filler0x1d[0x3];
/*0x20*/ int           SpecialCase;              // origin of damage? need to investigate further
/*0x24*/ 
};
using pEQSuccessfulHit = EQSuccessfulHit*;

struct LfgGroupStatus;
struct LfgGroupQuery;
struct LfgPlayerStatus;
struct LfgPlayerQuery;
struct connection_t;

enum ZONE_REQ_REASON
{

};

class EQLIB_OBJECT CEverQuest
{
public:
	~CEverQuest();
	CEverQuest(HWND);
	void CreateTargetIndicator(int Slot, PSPELL pSpell, const ItemGlobalIndex& ItemLoc, ItemSpellTypes spelltype);
	int DeleteTargetIndicator();
	bool IsInTypingMode();
	bool IsOkToTransact();
	bool ReadClientINIBool(char*, char*, bool);
	bool ReadUIINIBool(char*, char*, bool);
	char* GetBodyTypeDesc(int);
	char* GetClassDesc(int);
	char* GetClassThreeLetterCode(int);
	char* GetDeityDesc(int);
	char* GetInnateDesc(int);
	char* GetItemClassDesc(int);
	char* GetLangDesc(int);
	char* GetRaceDesc(int);
	char* GetSingleMessage(uint32_t, int, int*, char*);
	char* GrabFirstWord(char*, char*);
	char* GrabFirstWord2(char*, char*, int);
	char* ReadClientINIString(char*, char*, char*, char*, int);
	char* ReadUIINIString(char*, char*, char*, char*, int);
	char* stripName(char*);
	char* StripShipName(char*, char*);
	char* trimName(char*);
	EQPlayer* ClickedPlayer(int, int);
	EQSwitch* ClickedSwitch(int, int);
	ZONE_REQ_STATUS IsZoneAvailable(char*, EQZoneIndex, ZONE_REQ_REASON);
	float GetMaxLightRadius();
	float ReadClientINIFloat(char*, char*, float);
	int BeingIgnored(char*);
	int DoLogin(HWND, HINSTANCE);
	int GetCombatSound(EQPlayer*, EQPlayer*);
	int GetCurrentLanguage() const;
	int HandleItems(void*, int);
	int IsFriend(const char*);
	int IsValidName(char*);
	int LootCorpse(EQPlayer*, int);
	int MoveMoney(int, int, int, int, int, bool);
	int msgStartIcon(void*);
	int msgStartIeq(void*);
	int msgStartInotes(void*);
	int ProcessMBox();
	int ReadClientINIInt(char*, char*, int);
	int ReadUIINIInt(char*, char*, int);
	int TypingMode();
	unsigned char HandleWorldMessage(connection_t*, uint32_t, char*, uint32_t);
	unsigned char IFoundMyVehicle();
	void DoLoadScreenProgressBar(int, const char*, ...);
	void ApplyPoison(unsigned long);
	void Camp();
	void CancelSneakHide();
	void ChatServerConnect(char*, int, char*, char*);
	void ChatServerDisconnect();
	void ChatServerGiveTime();
	void ChatServerMessage(char*);
	void ChatServerNotificationAdd(bool, char*, char*, int);
	void ChatServerNotificationFlush();
	void CleanupBadFiles();
	void clr_chat_input();
	void Consider(EQPlayer*, void*);
	void CopyFirstWord(char*, char*);
	void CreateDataSubdirectories();
	void CreateFilenameServerCode(char*);
	void CreateIniFilenames();
	void CreateInitialActors();
	void DeacSpellScreen();
	void Disband();
	void DisplayScreen(char*);
	void DoCharacterSelection();
	void doInspect(EQPlayer*);
	void doInvite(uint32_t, char*);
	void DoLoadScreen(int);
	void doLoot();
	void DoMainLoop(HWND);
	void DoNewCharacterCreation();
	void DoPercentConvert(char*line, bool bOutGoing);
	void DoSplit(char*);
	void DoTellWindow(char*, char*, char*, void*, int, bool);
	void OutputTextToLog(const char*Text);
	void doUnInvite(char*);
	void DropHeldItemOnGround(int);
	void DropHeldMoneyOnGround(int);
	void DropItemOrMoneyOnPlayer(EQPlayer*);
	void dsp_chat(const char*);
#if !defined(ROF2EMU) && !defined(UFEMU)
	void dsp_chat(const char *line, int color = 273, bool bLogIsOk = true, bool bConvertPercent = true, char*SomeStr = NULL);
#else
	void dsp_chat(const char *line, int color, bool bLogIsOk, bool bConvertPercent);
#endif
	void dsp_chat(const char*, int, bool);
	void Emote();
	void EnterZone(HWND);
#if !defined(ROF2EMU) && !defined(UFEMU)
	int Follow(int);
#else
	int Follow();
#endif
	void FreeSwitches();
	void GetSndDriver();
	void GetZoneInfoFromNetwork(char*);
	void GuildDelete();
	void GuildInvite(char*, char*);
	void GuildLeader(char*);
	void GuildPeace(char*);
	void GuildRemove(char*);
	void GuildSay(char*);
	void GuildStatus(char*);
	void GuildWar(char*, int);
	void InitCommands();
	void initCustom();
	void InterpretCmd(EQPlayer*, char*);
	void Invite(int);
	void InviteOk(char*);
	void IssueLfgGroupQuery(LfgGroupQuery*);
	void IssueLfgPlayerQuery(LfgPlayerQuery*);
#if !defined(ROF2EMU) && !defined(UFEMU)
	void IssuePetCommand(ePetCommandType, int TargetID, bool bQuiet, bool bsomethingelse = 1);
#else
	void IssuePetCommand(ePetCommandType, int TargetID, bool bQuiet);
#endif
	void Kill(char*, char*);
	void LeaveBankMode(bool);
	void LeaveGuildMaster();
	void LeftClickedOnPlayer(EQPlayer*);
	void LMouseDown(int, int);
	void LMouseUp(int, int);
	void loadCustom();
	void loadCustomFromINI(char*);
	void loadOptions();
	void loadSoundsGame();
	void LoadStringTables();
	void LoadSwitchesNonAvatar(EQZoneIndex);
	void LocalDeath(EQPlayerDeath*, unsigned char);
	void MouseWheelScrolled(int);
	void MoveToZone(int, char*, int, int, float, float, float, int);
	void MoveToZone(char*, char*, int, ZONE_REQ_REASON);
	void MoveToZone(EQZoneIndex, char*, int, ZONE_REQ_REASON);
	void PrepareLocalPCForRepop();
	void ProcessControls();
	void ProcessGame(HWND, HINSTANCE);
	void ProcessLocalPCIni(int);
	void procMouse(int);
	void RemoveCharacterOptionFile(char*);
	void ReportDeath(EQPlayerDeath*);
	void ReportSuccessfulHit(EQSuccessfulHit*pHit, unsigned char bOutputText, int ActualHeal);
	void reqChannel();
	void ResetVisionRGBs();
	void RightClickedOnPlayer(EQPlayer*, int);
	void RMouseDown(int, int);
	void RMouseUp(int, int);
	void SaveCamerasToINI();
	void saveCustom();
	void saveOptions();
	void saveOptions2();
	void SavePC(int, int, unsigned char);
	void SavePCForce(int);
	void send_auction();
	void send_broadcast();
	void send_chat();
	void send_gsay();
	void send_ooc();
	void send_petition();
	void send_private();
	void send_shout();
	void send_social(int, char*, char*);
	void send_tell(char*, char*);
	void send_update_filters();
	void SendLightInfo(EQPlayer*, unsigned char);
	void SendNewText(int, char*, char*);
	void SetDefaultDamageDescByRace(char*, int, unsigned char);
	void SetDefaultGameValues();
	void SetGameState(int);
	void SetLfgGroupStatus(LfgGroupStatus*);
	void SetLfgPlayerStatus(LfgPlayerStatus*);
	void SetPlayerAppearanceFromPInfo(EQPlayer*, int, bool);
	void SetTimedFog(int);
	void SetupCharSelectCamera();
	void Sit();
	void SortSpellLoadouts();
	void StartCasting(void*);
	void StartNetworkGame(HWND, HINSTANCE, char*);
	void Surname(char*);
	void ToggleAutoSplit();
	void UpdateMyAppearance();
	void UseCharge(unsigned long);
	void WhatTimeIsIt();
	void Who(char*);
	void WriteBoolToClientINI(bool, char*, char*);
	void WriteBoolToUIINI(bool, char*, char*);
	void WriteFloatToClientINI(float, char*, char*);
	void WriteIntToClientINI(int, char*, char*);
	void WriteIntToUIINI(int, char*, char*);
	void WriteStringToClientINI(char*, char*, char*);
	void WriteStringToUIINI(char*, char*, char*);

	// virtual
	void CshOnBuddyStatusChange(char*, int BuddyStatus);
	void CshOnChannelListChange();
	void CshOnMessage(char*, char*, int, char*, bool);
	void CshOnPlayerEntering(char*, int, char*);
	void CshOnPlayerLeaving(char*, int, char*);
};

class EQLIB_OBJECT CExploreModeWnd : public CSidlScreenWnd
{
public:
	CExploreModeWnd(CXWnd*);
	void Activate();

	// virtual
	~CExploreModeWnd();
	void Deactivate();
};

class EQLIB_OBJECT CExtendedTargetWnd : public CSidlScreenWnd
{
public:
};

// Size: 258h see 53F643 Nov 29 2018 Beta 
class EQLIB_OBJECT CFactionWnd : public CSidlScreenWnd
{
public:
	CFactionWnd(CXWnd*);
};

class EQLIB_OBJECT CFacePick : public CSidlScreenWnd
{
public:
	CFacePick(CXWnd*);
	void Activate();
	void SetFaceSelectionsFromPlayer();

	// virtual
	~CFacePick();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void CycleThroughFHEB(int, int);
	void Init();
	void ShowButtonGroup(int, bool);
};

class EQLIB_OBJECT CFindItemWnd : public CSidlScreenWnd //, public WndEventHandler but we just add the member LastCheckTime
{
public:
/*0x230*/ UINT         LastCheckTime;//from WndEventHandler
/*0x234*/ CComboWnd*   SearchCombo0;
/*0x238*/ CComboWnd*   SearchCombo1;
/*0x23c*/ int          SelIndex;
/*0x240*/ VeArray<ItemGlobalIndex*> gi;
/*0x24c*/ int          Unknown0x24c;
/*0x250*/ int          Unknown0x250;
/*0x254*/ int          Unknown0x254;
/*0x258*/ int          Unknown0x258;
/*0x25c*/ int          Unknown0x25c;
/*0x260*/ int          FIW_ClassAnim;
/*0x264*/ CSidlScreenWnd* FIW_CharacterView;
/*0x268*/ CListWnd*    FIW_ItemList;
/*0x26c*/ CButtonWnd*  FIW_QueryButton;
/*0x270*/ CButtonWnd*  FIW_RequestItemButton;
/*0x274*/ CButtonWnd*  FIW_RequestPreviewButton;
/*0x278*/ CButtonWnd*  FIW_Default;
/*0x27c*/ CButtonWnd*  FIW_GrabButton;
/*0x280*/ CButtonWnd*  FIW_HighlightButton;
/*0x284*/ CButtonWnd*  FIW_DestroyItem;
/*0x288*/ CComboWnd*   FIW_ItemLocationCombobox;
/*0x28c*/ CComboWnd*   FIW_ItemSlotCombobox;
/*0x290*/ CComboWnd*   FIW_StatSlotCombobox;
/*0x294*/ CComboWnd*   FIW_RaceSlotCombobox;
/*0x298*/ CComboWnd*   FIW_ClassSlotCombobox;
/*0x29c*/ CComboWnd*   FIW_ItemTypeCombobox;
/*0x2a0*/ CComboWnd*   FIW_ItemPrestigeCombobox;
/*0x2a4*/ CComboWnd*   FIW_ItemAugmentCombobox;
/*0x2a8*/ CEditWnd*    FIW_ItemNameInput;
/*0x2ac*/ CEditWnd*    FIW_MaxLevelInput;
/*0x2b0*/ CEditWnd*    FIW_MinLevelInput;
/*0x2b4*/ CEditWnd*    Unknown0x2b4;
/*0x2B8*/

#if !defined(ROF2EMU) && !defined(UFEMU)
	CFindItemWnd(CXWnd*);
	void Update();
	void PickupSelectedItem();
	int WndNotification(CXWnd*, uint32_t, void*);
#endif
};

class EQLIB_OBJECT CFeedbackWnd : public CSidlScreenWnd
{
public:
	CFeedbackWnd(CXWnd*);
	void Activate();

	// virtual
	~CFeedbackWnd();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
};

class EQLIB_OBJECT CUnSerializeBuffer
{
public:
	const char*        m_pBuffer;
	uint32_t           m_uLength;
	uint32_t           m_uReadOffset;

	void Reset() { m_uReadOffset = 0; }

	template<typename T>
	void Read(T& r)
	{
		r = *(T*)(m_pBuffer + m_uReadOffset);
		m_uReadOffset += sizeof(T);
	}

	void ReadString(std::string& out)
	{
		int len = 0;
		while (m_pBuffer[m_uReadOffset] != '\0')
		{
			out.append(1, (char)(m_pBuffer[m_uReadOffset]));
			m_uReadOffset++;
		}

		m_uReadOffset++;
	}

	template <typename T>
	void Read(T* r, size_t size)
	{
		size_t savedSize;
		Read(savedSize);

		for (size_t i = 0; i < savedSize && i < size; i++)
		{
			Read(r[i]);
		}
	}

	template <unsigned int _Size>
	void ReadpChar(char(&_Buffer)[_Size])
	{
		_Buffer[0] = '\0';
		int len = 0;

		while(m_pBuffer[m_uReadOffset] != '\0' && len < _Size)
		{
			_Buffer[len++] = (char)(m_pBuffer[m_uReadOffset]);
			m_uReadOffset++;
		}
	
		// take null term into account...
		m_uReadOffset++;
	}
};

class EQLIB_OBJECT CFindLocationWnd : public CSidlScreenWnd
{
	// has virtuals, but we get those from CSidlScreenWnd
public:
	bool HandleFindBegin();
	void HandleFindEnd();
	void HandleRowClicked(int Index);
	void HandleFindableZoneConnectionsMessage(CUnSerializeBuffer& buf);
};

struct _ITEMIDLIST;

class EQLIB_OBJECT CFileSelectionWnd : public CSidlScreenWnd
{
public:
	CFileSelectionWnd(CXWnd*);
	CXStr GetSelectedFile(int);
	int GetSelectedFileCount();
	void Activate(CXWnd*, int);
	void Callback(bool);

	// virtual
	~CFileSelectionWnd();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	bool DirectoryEmpty(IShellFolder*, _ITEMIDLIST*);
	unsigned long GetPath(IShellFolder*, _ITEMIDLIST*, bool, CXStr&);
	void ClearFileList();
	void GoSubdirectory(_ITEMIDLIST*);
	void MakeFilePath();
	void UpdateButtons();
	void UpdateFileList();
};

class EQLIB_OBJECT CFriendsWnd : public CSidlScreenWnd
{
public:
	CFriendsWnd(CXWnd*);
	void Activate();
	void UpdateFriendsList();
	void UpdateIgnoreList();

	// virtual
	~CFriendsWnd();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// protected
	void AddFriend();
	void AddIgnore();
	void UpdateButtons();
};

class EQLIB_OBJECT CGaugeDrawTemplate
{
public:
/*0x00*/ PCXSTR        Name;
/*0x04*/ CTextureAnimation* Background;
/*0x08*/ CTextureAnimation* Fill;
/*0x0c*/ CTextureAnimation* Lines;
/*0x10*/ CTextureAnimation* LinesFill;
/*0x14*/ CTextureAnimation* EndCapLeft;
/*0x18*/ CTextureAnimation* EndCapRight;
/*0x1c*/ 

	~CGaugeDrawTemplate();
};

class EQLIB_OBJECT CGaugeTemplate
{
public:
	CGaugeTemplate(CParamGauge*);

	// virtual
	~CGaugeTemplate();
};

// size 0x248 see 7E24DB in Sep 21 2018
class EQLIB_OBJECT CGaugeWnd : public CXWnd
{
public:
//*0x000*/ PCXWNDVFTABLE pvfTable;
//*0x004*/ CXW_NO_VTABLE
/*0x1e0*/ int          EQType;
/*0x1e4*/ D3DCOLOR     FillTint;
/*0x1e8*/ D3DCOLOR     LinesFillTint;
/*0x1ec*/ bool         bDrawLinesFill;
/*0x1f0*/ int          TextOffsetX;
/*0x1f4*/ int          TextOffsetY;
/*0x1f8*/ int          GaugeOffsetX;
/*0x1fc*/ int          GaugeOffsetY;
/*0x200*/ float        LastFrameVal;
/*0x204*/ CXSTR*       LastFrameName;
/*0x208*/ int          LastFrameTime;
/*0x20c*/ int          LastFrameTarget;
/*0x210*/ CXSTR*       GaugeTooltip;
/*0x214*/ int          TooltipVal;
/*0x218*/ CGaugeDrawTemplate DrawTemplate;       // size 0x1c
/*0x234*/ CTextObjectInterface* pTextObject;
/*0x238*/ CXSTR*       NextDrawStr;
/*0x23c*/ bool         bSmooth;
/*0x240*/ int          TargetVal;
/*0x244*/ bool         bUseTargetVal;
/*0x248*/

	CGaugeWnd(CXWnd*, uint32_t, const CXRect&, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, int, unsigned long, unsigned long, bool, int, int, int, int);
	CXRect CalcFillRect(CXRect*, int) const;
	CXRect CalcLinesFillRect(CXRect*, int) const;
	void SpecialToolTip();

	// virtual
	~CGaugeWnd();
	int Draw() const;
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int OnProcessFrame();
	void SetAttributesFromSidl(CParamScreenPiece*);
};

struct _GemsBlock;

class EQLIB_OBJECT CGemsGameWnd : public CSidlScreenWnd
{
public:
	CGemsGameWnd(CXWnd*);
	void Activate();
	void MoveCurBlock(int);

	// virtual
	~CGemsGameWnd();
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int OnProcessFrame();
	int PostDraw() const;
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	bool BadSpecial(int) const;
	bool LegalBlockMove(int, int, int, int, bool);
	int GetRndBlockImage();
	void ActivateSpecialMode(int);
	void AdvanceToNextWave();
	void CheckForMatches(int, int);
	void CheckForNewHighScore();
	void ClearBlock(_GemsBlock*);
	void ClearHighScores();
	void DoMatchScore(int);
	void DrawSpellGem(int, const CXRect&, int, bool) const;
	void GetNextBlock();
	void Init();
	void MakeBlockDrop(int, int, int);
	void MarkHigherBlocksFalling(int, int);
	void ProcessMatches(int);
	void ProcessMoveCurBlock(int);
	void ReadHighScores();
	void Restart();
	void SetNextUpdate();
	void SetPause(bool);
	void TogglePause();
	void Update();
	void UpdateDisplay();
	void WriteHighScores();
};

class EQLIB_OBJECT PopDialogHandler
{
public:
	void* vfTable;
};

class EQLIB_OBJECT CGiveWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler2
{
public:
	CButtonWnd*        pMoneyButton[4];
	CButtonWnd*        TradeButton;
	CButtonWnd*        CancelButton;
	CLabel*            NPCNameLabel;
	CInvSlotWnd*       pInvSlotWnd[4];

	CGiveWnd(CXWnd*);
	void Activate();
	void UpdateGiveDisplay();

	// virtual
	~CGiveWnd();
	int OnProcessFrame();
	int PostDraw() const;
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void Init();
};

class EQLIB_OBJECT CGroupSearchFiltersWnd : public CSidlScreenWnd
{
public:
	CGroupSearchFiltersWnd(CXWnd*);
	bool ShouldFilterPlayer(const char*, const char*) const;
	bool UseExclusiveSearchMode() const;
	void Activate();
	void HandleAddDesiredGuild();
	void HandleAddExcludedGuild();
	void HandleDesiredGuildsSelected();
	void HandleExcludeGuildsSelected();
	void HandleRemoveAllDesiredGuilds();
	void HandleRemoveAllExcludedGuilds();
	void HandleRemoveDesiredGuild();
	void HandleRemoveExcludedGuild();
	void HandleUseFriendsListSelected();
	void HandleUseIgnoreListSelected();

	// virtual
	~CGroupSearchFiltersWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	bool GuildIsInDesiredGuildsList(const char*) const;
	bool GuildIsInExcludedGuildsList(const char*) const;
	bool Load();
	bool NameIsInFriendsList(const char*) const;
	bool NameIsInIgnoreList(const char*) const;
	bool UseDesiredGuilds() const;
	bool UseExcludedGuilds() const;
	bool UseFriendsList() const;
	bool UseIgnoreList() const;
	void ClearUiPointers();
	void FetchUiPointers();
	void InitPieces();
	void Save() const;
};

struct LfgGroupResult;
class SListWndSortInfo;
struct LfgPlayerData;

class EQLIB_OBJECT CGroupSearchWnd : public CSidlScreenWnd
{
public:
	CGroupSearchWnd(CXWnd*);
	void Activate(int);
	void AddGroupResult(const LfgGroupResult*);
	void AddPlayerResult(const LfgPlayerResult*);
	void HandleDeselectAllClasses();
	void HandleDoubleClickedOnPlayer(const char*);
	void HandleGroupInfoPost();
	void HandleGroupInfoRemove();
	void HandleGroupInfoUpdate();
	void HandleGroupMakeupChanged();
	void HandleGroupResultColSelected(int);
	void HandleGroupResultRowSelected(int);
	void HandleNumericSort(SListWndSortInfo*);
	void HandleOpenFiltersWindow();
	void HandlePlayerInfoPost();
	void HandlePlayerInfoRemove();
	void HandlePlayerInfoUpdate();
	void HandlePlayerResultColSelected(int);
	void HandleQueryingForGroups();
	void HandleQueryingForPlayers();
	void HandleSelectAllClasses();
	void ResetGroupList();
	void ResetPlayerList();
	void SendServerLfgOff();
	void SendServerLfgOn();
	void SendServerLfpOff();
	void SendServerLfpOn();

	// virtual
	~CGroupSearchWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	bool IsLevelRangeValid(int, int) const;
	bool PlayerShouldBeFiltered(const LfgPlayerData*) const;
	int CheckIfCurrentLfgInfoIsValid() const;
	int CheckIfCurrentLfpInfoIsValid() const;
	int GetDesiredClassesFlag() const;
	int GetDesiredGroupMaxLevel() const;
	int GetDesiredGroupMinLevel() const;
	int GetDesiredPlayerMaxLevel() const;
	int GetDesiredPlayerMinLevel() const;
	int GetEqClassType(int) const;
	int GroupInfoPageOnProcessFrame();
	int GroupInfoPageWndNotification(CXWnd*, uint32_t, void*);
	int GroupListPageOnProcessFrame();
	int GroupListPageWndNotification(CXWnd*, uint32_t, void*);
	int PlayerInfoPageOnProcessFrame();
	int PlayerInfoPageWndNotification(CXWnd*, uint32_t, void*);
	int PlayerListPageOnProcessFrame();
	int PlayerListPageWndNotification(CXWnd*, uint32_t, void*);
	int RedirectOnProcessFrameTo(CPageWnd*);
	int RedirectWndNotificationTo(CPageWnd*, CXWnd*, uint32_t, void*);
	void ClearUiPointers();
	void FetchUiPointers();
	void FilterOutBadWords(const char*, char*) const;
	void GetDefaultLfgLevelRange(EQ_PC const*, int*, int*) const;
	void GetDefaultLfpLevelRange(EQ_PC const*, int*, int*) const;
	void InitLfg();
	void InitLfp();
	void LockQueryButtonAtTime(long);
	void PopUpErrorMessage(int) const;
	void ShowGroupDetails(LfgGroupResult const*);
	void UpdateGroupLabel();
	void UpdateLfgPostingStatus();
	void UpdateLfpPostingStatus();
	void UpdatePlayerLabel();
	void UpdateRemainingQueryLockedTime(long);
};

// Sep 21 2018
class EQLIB_OBJECT CGroupWnd : public CSidlScreenWnd
{
public:
	CButtonWnd*        InviteButton;
	CButtonWnd*        DisbandButton;
	CButtonWnd*        FollowButton;
	CButtonWnd*        DeclineButton;
	CButtonWnd*        LFGButton;
	CGaugeWnd*         HPGauge[6];
	CGaugeWnd*         PetGauge[6];
	CGaugeWnd*         ManaGauge[6];
	CGaugeWnd*         EnduranceGauge[6];
	CLabel*            HPLabel[6];
	CLabel*            HPPercLabel[6];
	CLabel*            ManaLabel[6];
	CLabel*            ManaPercLabel[6];
	CLabel*            EnduranceLabel[6];
	CLabel*            EndurancePercLabel[6];
	COLORREF           HPTextColor[6];
	CButtonWnd*        GroupTankButton[6];
	CButtonWnd*        GroupAssistButton[6];
	CButtonWnd*        GroupPullerButton[6];
	CButtonWnd*        GroupMarkNPCButton[6];
	CLabel*            AggroPercLabel[6];
	long               Timer;
	CContextMenu*      GroupContextMenu;
	bool               bPetbars;
	bool               bManabars;
	bool               bEndurancebars;
	bool               bAggroPct;
	int                PetBarIndex;
	int                ManaBarIndex;
	int                EnduranceBarIndex;
	int                AggroPctIndex;
	int                RoleSeparatorID;
	int                RoleSelectMenu;
	int                RoleSelectMenuID;
	bool               bPlayerInvited;

	CGroupWnd(CXWnd*);
	void Activate();
	void CreateLocalMenu();
	void KeyMapUpdated();
	void SetInvited(bool);
	void UpdateContextMenu();

	// virtual
	~CGroupWnd();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
	void LoadIniInfo();
	void StoreIniInfo();

	// protected
	void UpdateButtons();
	void UpdateDisplay(int Index, PSPAWNINFO groupmember, COLORREF NameColor, UINT RoleBits);

	// private
	void Init();
};

struct guildmotdSet;
struct connection_t;
class GuildMember;

class EQLIB_OBJECT CGuild
{
public:
	CGuild();
	bool ValidGuildName(int);
	char* GetGuildMotd();
	char* GetGuildMotdAuthor();
#if !defined(ROF2EMU) && !defined(UFEMU)
	char* GetGuildName(int64_t);
	int64_t GetGuildIndex(char*);
#else
	char* GetGuildName(DWORD);
	int  GetGuildIndex(char*);
#endif
	GuildMember* FindMemberByName(char*);
	void DeleteAllMembers();
	void DemoteMember(GuildMember*);
	void HandleGuildMessage(connection_t*, uint32_t, char*, uint32_t);
	void SendPublicCommentChange(char*, char*);
	void SetGuildMotd(guildmotdSet*);

	// virtual
	~CGuild();

	// private
	void AddGuildMember(GuildMember*);
	void ChangeGuildMemberName(char*);
	void HandleAddGuildMember(char*, int);
	void HandleDeleteGuildResponse(char*);
	void HandleGuildInvite(connection_t*, uint32_t, char*, uint32_t);
	void HandleMemberLevelUpdate(char*);
	void HandleRemoveGuildMember(char*, int);
	void InitializeFromDump(char*);
	void UpdateGuildMemberOnWindow(GuildMember*);
	void UpdateMemberStatus(char*);
	void UpdatePublicComment(char*);
};

class EQLIB_OBJECT CGuildMgmtWnd : public CSidlScreenWnd
{
public:
	CGuildMgmtWnd(CXWnd*);
	void Activate();
	void AddMember(GuildMember*);
	void Clean();
	void DumpToFile(char*);
	void RemoveMember(GuildMember*);
	void RenameMember(char*, char*);
	void SetMOTD(char*, char*);
	void SetPlayerCount(int);
	void SortList(int, bool);
	void UpdateButtons();
	void UpdateListMember(GuildMember*, int);

	// virtual
	~CGuildMgmtWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// protected
	char* GetPersonalNote(char*);
	int FindListMember(GuildMember*);
	void CleanAndRefillListWnd(bool);
	void CreatePersonalNotesFilename();
	void LoadINI();
	void LoadPersonalNotes();
	void SavePersonalNotes();
	void SetPersonalNote(char*, char*);

	// private
	void Init();
};

class EQLIB_OBJECT ChannelServerApi
{
public:
	~ChannelServerApi();
	ChannelServerApi(char*, int, char*, char*, ChannelServerHandler*, bool, bool, char*);
	char* GetChannelName(int);
	// enum Status GetStatus();
	int GetChannelCount();
	int GetChannelNumber(char*);
	static char* AllocateString(char*);
	static char* Strncpy(char*, char*, int);
	static int GetNextField(char*, int, char**, char);
	static void* SmartResize(void*, int, int);
	void GiveTime();
	void SendMessageA(char*);

	// virtual
	void OnRoutePacket(UdpConnection*, unsigned const char*, int);

	// protected
	void FreeChannelList();
	// void SetBuddyStatus(char*, enum BuddyStatus);
	void SortBuddyList();
};

class EQLIB_OBJECT ChannelServerHandler
{
public:
	// virtual
	void CshOnLoginConfirm(bool);
	void CshOnPacket(void*, int, char*, int, char*, bool);
};

struct CKeyUInt32ValueInt32
{
	uint32_t key;
	int      value;
};

class EQLIB_OBJECT CHashCXStrInt32
{
public:
	ArrayClass2_RO<ArrayClass2_RO<CKeyUInt32ValueInt32>> HashData;

	~CHashCXStrInt32();
	CHashCXStrInt32();
	bool Insert(CXStr const &, int);
	bool LookUp(CXStr const &, int &) const;
	void Reset();

	// private
	int KeyToBin(CXStr const &) const;
};

class EQLIB_OBJECT CHelpWnd : public CSidlScreenWnd
{
public:
	CHelpWnd(CXWnd*);
	void Activate();
	void SetFile(CXStr);

	// virtual
	~CHelpWnd();
	int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void Init();
};

class EQLIB_OBJECT CHotButton // : public CXWnd
{
public:
	CXW
/*0x1e0*/ int          BarIndex;
/*0x1e4*/ int          ButtonIndex;
/*0x1e8*/ UINT         Timer;
/*0x1ec*/ CTextureAnimation* DecalIcon;
/*0x1f0*/ int          LastButtonType;
/*0x1f4*/ int          LastButtonSlot;
/*0x1f8*/ char         LastButtonPage;
/*0x1f9*/ EqItemGuid   LastItemGuid;
/*0x20c*/ int          LastItemId;
/*0x210*/ int          LastIconType;
/*0x214*/ int          LastIconSlot;
/*0x218*/ CXSTR*       LastLabel;
/*0x21c*/ CXSTR*       DefaultLabel;
/*0x220*/ bool         bForceUpdate;
/*0x224*/ CTextObjectInterface* pKeyMapText;
/*0x228*/ int          Unknown0x228;
/*0x22c*/ CButtonWnd*  pButtonWnd;
/*0x230*/ CInvSlotWnd* pInvSlotWnd;
/*0x234*/ CSpellGemWnd* pSpellGemWnd;
/*0x238*/ tagSIZE      BaseSize;
/*0x240*/ int          ButtonPercentSize;
/*0x244*/ tagSIZE      BaseButtonSize;
/*0x24c*/ tagSIZE      BaseDecalSize;
/*0x254*/ tagSIZE      BaseInvButtonSize;
/*0x25c*/ tagSIZE      BaseSpellButtonSize;
/*0x264*/ int          Unknown0x264;
/*0x268*/
	void SetButtonSize(int percent, bool bUpdateParent = true);
};

class EQLIB_OBJECT CHotButtonWnd : public CSidlScreenWnd
{
public:
	CHotButtonWnd(CXWnd*);
	void Activate();
#if !defined(ROF2EMU) && !defined(UFEMU)
	void DoHotButton(int Button, int AllowAutoRightClick, int something);
#else
	void DoHotButton(int Button, int AllowAutoRightClick);
#endif
	void DoHotButtonRightClick(int);
	void UpdatePage();

	// virtual
	~CHotButtonWnd();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void Init();
};

class EQLIB_OBJECT CIMECandidateList
{
public:
	~CIMECandidateList();
	CIMECandidateList(CIMEManager*);
	int show(CIMEComposition const*) const;

	// private
	int repositionImeCandidateList(int, int) const;
};

struct CompAttr;

class EQLIB_OBJECT CIMEComposition
{
public:
	~CIMEComposition();
	CIMEComposition(CIMEManager*);
	CXPoint getCursorPoint() const;
	CXRect getCompositionArea() const;
	int addInputChar(unsigned short);
	int addInputString(CXStr const &, int);
	int addInputString(unsigned short*, int);
	int addStringFromIme(long);
	void directToEditWnd(CEditWnd*);

	// private
	int addCompositionHighlights();
	int applyChineseComposingRules(CXStr*);
	int applyJapaneseComposingRules(CXStr*);
	int applyKoreanComposingRules(CXStr*);
	int getCompositionInsertIndex() const;
	int handleImeComposing();
	int handleImeResult();
	int repositionImeCompositionWindow(int, int) const;
	CompAttr* allocateImeCompositionAttributes() const;
	unsigned short* allocateImeCompositionString(long) const;
	void backupCurrentText();
	void revertToBackupText();
};

class EQLIB_OBJECT CIMEManager
{
public:
	~CIMEManager();
	CIMEManager(HWND);
	bool imeIsOff() const;
	bool imeIsOn() const;
	int getImeProperties() const;
	int getInputLanguage() const;
	int getInputState() const;
	int handleWndProc(unsigned int, unsigned int, long);
	int setInputEditWnd(CEditWnd*);
	HWND getWindowHandle() const;
	void setInputState(int);
	void turnImeOff();
	void turnImeOn();

	// private
	int handleAddChar(unsigned short);
	int handleChangeCandidates();
	int handleCloseCandidates();
	int handleEndComposition();
	int handleImeChanged();
	int handleImeStatusChanged();
	int handleInputComposition(long);
	int handleOpenCandidates();
	int handleStartComposition();
	int queryImeLanguage() const;
	int queryImeProperties() const;
	void enableIme(bool);
};

class EQLIB_OBJECT CIMEStatusBar
{
public:
	CIMEStatusBar(CIMEManager*);
	int hide();
	int show(const CIMEComposition*);
	int update();

	// private
	int repositionStatusWindow();
	void handleChineseSimplifiedStatusChange(unsigned long);
	void handleChineseTraditionalStatusChange(unsigned long);
	void handleJapaneseStatusChange(unsigned long);
	void handleKoreanStatusChange(unsigned long);
};

struct _inspect;

class EQLIB_OBJECT CInspectWnd : public CSidlScreenWnd
{
public:
	CInspectWnd(CXWnd*);
	void Activate(_inspect*);
	void PlayerBeingDeleted(EQPlayer*);

	// virtual
	~CInspectWnd();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void AcceptInspectText();
	void Init();
};

class EQLIB_OBJECT CInventoryWnd : public CSidlScreenWnd
{
public:
	CInventoryWnd(CXWnd*);
	void Activate();

	// virtual
	~CInventoryWnd();
	int Draw() const;
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	long GetInventoryQtyFromCoinType(int);
	void ClickedMoneyButton(int, int);
	void DestroyHeld();
	void Init();
	void UpdateMoneyDisplay();

	DWORD              Unknown0x0xx[0x22];
	int64_t            VitalityCap;
	int                AAVitalityCap;
};

class EQLIB_OBJECT CInvSlot
{
public:
	void*              pvftable;
	CInvSlotWnd*       pInvSlotWnd;
	CTextureAnimation* pInvSlotAnimation;
	int                Index;
	bool               bEnabled;

	CInvSlot();
	bool IllegalBigBank(int);
	void DoDrinkEatPoison(EQ_Item*, int);
	void HandleLButtonDown(const CXPoint&);
	void HandleLButtonHeld(const CXPoint&);
	void HandleLButtonUp(const CXPoint&, bool);
	void HandleLButtonUpAfterHeld(const CXPoint&);
	void HandleRButtonDown(const CXPoint&);
	void HandleRButtonHeld(const CXPoint&);
	void HandleRButtonUp(const CXPoint&*);
	void HandleRButtonUpAfterHeld(const CXPoint&);
	void SetInvSlotWnd(CInvSlotWnd*);
	void SetItem(EQ_Item*);
	void SliderComplete(int);
	void GetItemBase(CONTENTS**);
	void UpdateItem();

	// virtual
	~CInvSlot();
};

class EQLIB_OBJECT CInvSlotMgr
{
public:
	CInvSlotMgr();
	CInvSlot* CreateInvSlot( CInvSlotWnd*);
#if !defined(ROF2EMU) && !defined(UFEMU)
	CInvSlot* FindInvSlot(int TopSlot, int SubSlot=-1, int FindWindowRelated = 0, bool bSomething = 1);
#else
	CInvSlot* FindInvSlot(int TopSlot, int SubSlot=-1);
#endif
	bool MoveItem(ItemGlobalIndex* from, ItemGlobalIndex* to, bool bDebugOut, bool CombineIsOk, bool MoveFromIntoToBag = false, bool MoveToIntoFromBag = false);
	void Process();
	void SelectSlot(CInvSlot*);
	void UpdateSlots();

	// virtual
	~CInvSlotMgr();
};

class EQLIB_OBJECT CInvSlotTemplate
{
public:
	CInvSlotTemplate(CParamInvSlot*);

	// virtual
	~CInvSlotTemplate();
};

class EQLIB_OBJECT CInvSlotWnd
{
public:
	// inherits from CXWnd via CButtonWnd
	CXW
	// inherits from CButtonWnd
/*0x01e8*/ int         MouseButtonState;
/*0x01ec*/ bool        bPicture;
/*0x01f0*/ CRadioGroup* pGroup;
/*0x01f4*/ bool        bChecked;
/*0x01f5*/ bool        bMouseOverLastFrame;
/*0x01f8*/ tagPOINT    DecalOffset;
/*0x0200*/ tagSIZE     DecalSize;
/*0x0208*/ COLORREF    DecalTint;
/*0x020c*/ RECT        TextOffsets;
/*0x021c*/ int         TextModeBits;
/*0x0220*/ COLORREF    Mouseover;
/*0x0224*/ COLORREF    Pressed;
/*0x0228*/ COLORREF    Disabled;
/*0x022c*/ UINT        CoolDownBeginTime;
/*0x0230*/ UINT        CoolDownDuration;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x0234*/ CXStr       Indicator;
/*0x0238*/ UINT        IndicatorVal;
/*0x023c*/ void*       pIndicatorTextObject;
#endif
	/* CButtonDrawTemplate Start*/
/*0x0240*/ CXStr       Name;
/*0x0244*/ CTextureAnimation* Normal;
/*0x0248*/ CTextureAnimation* taPressed;
/*0x024c*/ CTextureAnimation* Flyby;
/*0x0250*/ CTextureAnimation* taDisabled;
/*0x0254*/ CTextureAnimation* PressedFlyby;
/*0x0258*/ CTextureAnimation* PressedDisabled;
/*0x025c*/ CTextureAnimation* NormalDecal;
/*0x0260*/ CTextureAnimation* PressedDecal;
/*0x0264*/ CTextureAnimation* FlybyDecal;
/*0x0268*/ CTextureAnimation* DisabledDecal;
/*0x026c*/ CTextureAnimation* PressedFlybyDecal;
/*0x0270*/ CTextureAnimation* PressedDisabledDecal;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x0274*/ bool        bAllowButtonClickThrough;
/*0x0275*/ bool        bCoolDownDoDelayedStart;
#endif
/*0x0276*/ bool        bIsCheckbox;
/*0x0277*/ bool        bIsDrawLasso;
/*0x0278*/ UINT        ButtonStyle;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x027c*/ CLabel*     pButtonLabel;
#endif
/*0x0280*/

	// Actual start of CInvSlotWnd
	CTextureAnimation* pBackground;

	// These two should be an ItemGlobalIndex
	ItemContainerInstance ICLocation;
	ItemIndex          iIndex;
	void*              LinkedItem;
	int                ItemOffsetX;
	int                ItemOffsetY;
	CTextureAnimation* ptItem;
	int                Quantity;
	bool               bSelected;
	int                RecastLeft;
	bool               bHotButton;
	bool               bInventorySlotLinked;
	CInvSlot*          pEQInvSlot;
	void*              pinvslotwndTextObject;
	int                TextFontStyle;
    int                Mode;
	COLORREF           BGTintRollover;
	COLORREF           BGTintNormal;
	long               LastTime;

	CInvSlotWnd(CXWnd* pParent, uint32_t ID, CXRect rect, CTextureAnimation* ptaBackground,
		const ItemGlobalIndex& itemLocation, int ItemOffsetX, int ItemOffsetY);
	void SetInvSlot(CInvSlot*);

	// virtual
	~CInvSlotWnd();
	int Draw() const;
	int DrawTooltip(CXWnd const*) const;
	int HandleLButtonDown(const CXPoint&, uint32_t);
	int HandleLButtonHeld(const CXPoint&, uint32_t);
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int HandleLButtonUpAfterHeld(const CXPoint&, uint32_t);
	int HandleRButtonDown(const CXPoint&, uint32_t);
	int HandleRButtonHeld(const CXPoint&, uint32_t);
	int HandleRButtonUp(const CXPoint&, uint32_t);
	int HandleRButtonUpAfterHeld(const CXPoint&, uint32_t);
	int WndNotification(CXWnd*, uint32_t, void*);
	void SetAttributesFromSidl(CParamScreenPiece*);
};

enum ItemDisplayFlags
{
	PREVENT_LINK = 0x00000001,
	RECYCLE_WINDOW = 0x00000002,
	FROM_LINK = 0x00000004,
    FROM_BAZAAR_SEARCH = 0x00000008,
    FROM_BARTER_SEARCH = 0x00000010
};

class EQLIB_OBJECT CItemDisplayWnd : public CSidlScreenWnd
{
public:
/*0x0230*/ CStmlWnd*         pDescription;
/*0x0234*/ CStmlWnd*         pName;
/*0x0238*/ CButtonWnd*       pIconButton;
/*0x023c*/ CStmlWnd*         pLore;
/*0x0240*/ CTabWnd*          pItemDescriptionTab;
/*0x0244*/ CPageWnd*         pDescriptionPage;
/*0x0248*/ CPageWnd*         pLorePage;
/*0x024c*/ CSidlScreenWnd*   pAppearanceSocketScreen;
/*0x0250*/ CButtonWnd*       pAppearanceSocketItem;
/*0x0254*/ CButtonWnd*       pAppearanceSocketBuyButton;
/*0x0258*/ CStmlWnd*         pAppearanceSocketDescription;
/*0x025c*/ CSidlScreenWnd*   pItemSocketScreen[6];
/*0x0274*/ CButtonWnd*       pItemSocketItemButton[6];
/*0x028c*/ CStmlWnd*         pItemSocketDescription[6];
/*0x02a4*/ CXStr             ItemInfo;
/*0x02a8*/ CXStr             MoreText;
/*0x02ac*/ CXStr             LoreText;
/*0x02b0*/ CXStr             CreatorName;
/*0x02b4*/ CXStr             BackupTabTitle;
/*0x02b8*/ CXStr             SolventText;
/*0x02bc*/ CXStr             InformationText;
/*0x02c0*/ PCONTENTS         pCurrentItem;
/*0x02c4*/ bool              bActiveItem;
/*0x02c5*/ bool              bItemTextSet;
/*0x02c8*/ CTextureAnimation* pTABuffIcons;
/*0x02cc*/ CTextureAnimation* pTADragIcons;
/*0x02d0*/ bool              bTaggable;
/*0x02d1*/ bool              bFailed;
/*0x02d4*/ UINT              TabCount;
/*0x02d8*/ CLabel*           pModButtonLabel;
/*0x02dc*/ CStmlWnd*         pConvertButtonStml;
/*0x02e0*/ CLabel*           pMadeByLabel;
/*0x02e4*/ CLabel*           pCollectedLabel;
/*0x02e8*/ CLabel*           pScribedLabel;
/*0x02ec*/ int               Row;
/*0x02f0*/ bool              bAntiTwink;
/*0x02f4*/ CButtonWnd*       pModButton;
/*0x02f8*/ CButtonWnd*       pPrintRealEstateItems;
/*0x02fc*/ CButtonWnd*       pConvertButton;
/*0x0300*/ bool              bCollected;
/*0x0301*/ bool              bReceivedCollectableStatus;
/*0x0304*/ int               Group[6];
/*0x031c*/ bool              bClickedTwink;
/*0x0320*/ int               HeroicCount;
/*0x0324*/ int               ItemInfoCount;
/*0x0328*/ CLabel*           pItemInfoLabel[13];
/*0x035c*/ CLabel*           pStatLabel[0x1a][3];
/*0x0494*/ CLabel*           pValueLabel[0x1a][3];
/*0x05cc*/ CLabel*           pHeroicLabel[0xd];
/*0x0600*/ int               RightClickMenuID;
/*0x0604*/ int               RightClickMenuSocketSlot;
/*0x0608*/ int               WindowID;
/*0x060c*/

	CItemDisplayWnd(CXWnd*);
	CXStr CreateEquipmentStatusString(EQ_Item*);
	void SetItem(PCONTENTS*pCont, int flags);
	void SetItemText(char*);
	void SetSpell(int SpellID, bool HasSpellDescr, int);
	void UpdateStrings();

	// virtual
	~CItemDisplayWnd();
	int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	int OnProcessFrame();
	int WndNotification(CXWnd* pWnd, uint32_t Message, void* pData);
	void Activate();
	void Deactivate();

	// protected
	CXStr CreateClassString(EQ_Equipment*);
	CXStr CreateMealSizeString(EQ_Equipment*);
	CXStr CreateModString(EQ_Equipment*, int, int, int*);
	CXStr CreateRaceString(EQ_Equipment*);
	void GetSizeString(int, char*);
	void InsertAugmentRequest(int AugSlot);
	void RemoveAugmentRequest(int AugSlot);
	bool AboutToShow();
	void RequestConvertItem();
};

class EQLIB_OBJECT CJournalCatWnd : public CSidlScreenWnd
{
public:
	CJournalCatWnd(CXWnd*);
	void Activate();
	void Clean();
	void UpdateAll(bool);
	void UpdateButtons();

	// virtual
	~CJournalCatWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// protected
	void BuildList();
	void LoadINI();
	void SelectCategory(int);
	void SortList(int, bool);
	void StoreINI();
	void UpdateListWnd(bool);

	// private
	void Init();
};

class EQLIB_OBJECT CJournalNPCWnd : public CSidlScreenWnd
{
public:
	CJournalNPCWnd(CXWnd*);
	void Activate();
	void EnterIntoJournal(char*, float, float, float, char*);
	void LoadJournal(int);
	void SaveJournal();
	void UpdateAll(bool);
	void UpdateCategories();
	// virtual
	~CJournalNPCWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// protected
	void BuildList();
	void DoBackups(CXStr);
	void GetLogState();
	void SelectNPCIndex(int);
	void SortList(int, bool);
	void StoreLogState();
	void UpdateButtons();
	void UpdateListWnd(bool);

	// private
	void Init();
};

class JournalNPC;

class EQLIB_OBJECT CJournalTextWnd : public CSidlScreenWnd
{
public:
	CJournalTextWnd(CXWnd*);
	void Activate();
	void Clear();
	void DisplayNPC(JournalNPC*);
	void SetSearch(CXStr);
	void UpdateAll(bool);
	void UpdateCategories();

	// virtual
	~CJournalTextWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// protected
	void BuildList();
	void SelectEntryIndex(int);
	void SortList(int, bool);
	void UpdateButtons();
	void UpdateListWnd(bool);
};

class EQLIB_OBJECT CKeyCXStrValueInt32
{
public:
	CKeyCXStrValueInt32();
	~CKeyCXStrValueInt32();
};

// CLabelWnd__CLabelWnd_x
// size 0x200 see 8D5699 in Aug 10 2017 Live
// size 0x210 see 8DCE59 in Sep 11 2017 Test
// size 0x200 see 668D5B in Oct 17 2017 Live
// size 0x1e4 see 86BFC9 in rof2
class EQLIB_OBJECT CLabelWnd// : public CXWnd
{
public:
/*0x000*/ PCXWNDVFTABLE      pvfTable;
/*0x004*/ CXW_NO_VTABLE
/*0x1e0*/ bool               bNoWrap;
/*0x1e1*/ bool               bAlignRight;
/*0x1e2*/ bool               bAlignCenter;
/*0x1e4*/ int                xOffset;
/*0x1e8*/ bool               bResizeHeightToText;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x1ec*/ int                Unknown0x1ec;
/*0x1f0*/ CXStr              Text;
/*0x1f4*/ int                Unknown0x1f4;
/*0x1f8*/ bool               Unknown0x1f8;
/*0x1fc*/ int                Unknown0x1fc;
/*0x200*/
#endif

	CLabelWnd(CXWnd* pParent, uint32_t ID, const CXRect& rect);
};

// CLabel__CLabel_x
// size is 0x208 see 79C989 in Aug 10 2017 Live
// size is 0x218 see 7A3819 in Sep 11 2017 Test
// size 0x208 see 7A5739 in Oct 17 2017 Live
// size 0x1e8 see 755709 in Rof2
class EQLIB_OBJECT CLabel : public CLabelWnd
{
public:
/*0x200*/ int          EQType;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x204*/ int          Unknown0x204;
#endif
/*0x208*/

	CLabel(CXWnd* pParent, uint32_t id, const CXRect& rect, int eqtype = 0);
	void SetAlignCenter(bool);
	void SetAlignRight(bool);
	void SetNoWrap(bool);

	// virtual
	~CLabel();
	int Draw() const;
};

class EQLIB_OBJECT CLabelTemplate
{
public:
	CLabelTemplate(CParamLabel*);
	// virtual
	~CLabelTemplate();
};

class EQLIB_OBJECT CLargeDialogWnd
{
public:
	void Open(bool bYesNoEnabled, CXStr DialogText, unsigned long closeTimer /* 0 means never */,
		CXStr DialogTitle, bool bShowVolumeControls, CXStr YesText, CXStr NoText);
};

class EQLIB_OBJECT CWndDisplayManager
{
public:
	void*                    vfTable;
	ArrayClass2_RO<CXWnd*>   pWindows;
	ArrayClass2_RO<LONG>     pTimes;
	int                      MaxWindows;

	int FindWindow(bool bNewWnd);
	CWndDisplayManager();
	~CWndDisplayManager();
	bool CloseNewest();
	void CloseAll();

	//virtual
	int CreateWindowInstance();
};

class EQLIB_OBJECT CItemDisplayManager : public CWndDisplayManager
{
public:
	int CreateWindowInstance();
};

class EQLIB_OBJECT CLineBase
{
public:
	CLineBase();
	~CLineBase();
};

class EQLIB_OBJECT CListboxColumnTemplate
{
public:
	CListboxColumnTemplate(CParamListboxColumn*);
	~CListboxColumnTemplate();
};

class EQLIB_OBJECT CListboxTemplate
{
public:
	CListboxTemplate(CParamListbox*);

	// virtual
	~CListboxTemplate();
};

// See Also CUITextureInfo2...
class EQLIB_OBJECT CUITextureInfo
{
public:
	~CUITextureInfo();
	CUITextureInfo(CXStr, CXSize);
	CUITextureInfo(CXStr, int);
	CUITextureInfo(const CUITextureInfo&);
	CUITextureInfo(uint32_t, int);
	CUITextureInfo();
	CXStr GetName() const;
	int Draw(CXRect, CXRect, CXRect, unsigned long*, unsigned long*) const;
	int Draw(CXRect, CXRect, CXRect, unsigned long, unsigned long) const;
	int Preload();
	int Tile(CXRect, unsigned long*, unsigned long*) const;
	int Tile(CXRect, unsigned long, unsigned long) const;
	CUITextureInfo& operator=(const CUITextureInfo&);
};

struct SListWndCell_RO
{
	const CTextureAnimation* pTA;
	CXStr                    Text;
	COLORREF                 Color;
	bool                     bOnlyDrawTexture;
	CXWnd*                   pWnd;
};

struct SListWndCell : SListWndCell_RO
{
	SListWndCell()
	{
		pTA = NULL;
		Color = RGB(255, 255, 255);
		bOnlyDrawTexture = false;
		pWnd = NULL;
	}
};

struct TreeData_RO
{
/*0x00*/ int       Depth;
/*0x04*/ bool      bIsExpandable;
/*0x08*/
};

struct TreeData : TreeData_RO
{
	TreeData()
	{
		Depth = 0;
		bIsExpandable = false;
	}
};

struct SListWndLine_RO
{
/*0x000*/ ArrayClass_RO<SListWndCell_RO> Cells;
#if defined(ROF2EMU) || defined(UFEMU)
/*0x010*/ UINT         Data;
#else
/*0x010*/ uint64_t     Data;
#endif
/*0x018*/ int          Height;
/*0x01c*/ bool         bSelected;
/*0x01d*/ bool         bEnabled;
/*0x020*/ TreeData_RO  Treedata;
/*0x028*/ char         TooltipText[0x100];
/*0x128*/ bool         bVisible;
/*0x12C*/ int          Filler0x12C;
/*0x130*/
};

struct SListWndLine
{
/*0x000*/ ArrayClass<SListWndCell> Cells;
#if defined(ROF2EMU) || defined(UFEMU)
/*0x010*/ UINT         Data;
#else
/*0x010*/ uint64_t     Data;
#endif
/*0x018*/ int          Height;
/*0x01c*/ bool         bSelected;
/*0x01d*/ bool         bEnabled;
/*0x020*/ TreeData_RO  Treedata;
/*0x028*/ char         TooltipText[0x100];
/*0x128*/ bool         bVisible;
/*0x12C*/ int          Filler0x12C;
/*0x130*/

	SListWndLine()
	{
		Data = 0;
		Height = -1;
		bSelected = false;
		bEnabled = true;
		bVisible = true;
	}
};

struct SListWndColumn_RO
{
/*0x00*/ int           Width;
/*0x04*/ int           MinWidth;
/*0x08*/ SIZE          TextureSize;
/*0x10*/ POINT         TextureOffset;
/*0x18*/ CXSTR*        StrLabel;
#if defined(ROF2EMU) || defined(UFEMU)
/*0x20*/ UINT          Data;
#else
/*0x20*/ uint64_t      Data;
#endif
/*0x28*/ UINT          Flags;
/*0x2c*/ UINT          Type;
/*0x30*/ CTextureAnimation* pTextureAnim;
/*0x34*/ CTextureAnimation* pSelected;
/*0x38*/ CTextureAnimation* pMouseOver;
/*0x3c*/ CXStr         Tooltip;
/*0x40*/ bool          bResizeable;
/*0x44*/ int           Filler0x44;
/*0x48*/
};

struct SListWndColumn
{
/*0x00*/ int           Width;
/*0x04*/ int           MinWidth;
/*0x08*/ SIZE          TextureSize;
/*0x10*/ POINT         TextureOffset;
/*0x18*/ CXSTR*        StrLabel;
#if defined(ROF2EMU) || defined(UFEMU)
/*0x20*/ UINT          Data;
#else
/*0x20*/ uint64_t      Data;
#endif
/*0x28*/ UINT          Flags;
/*0x2c*/ UINT          Type;
/*0x30*/ CTextureAnimation* pTextureAnim;
/*0x34*/ CTextureAnimation* pSelected;
/*0x38*/ CTextureAnimation* pMouseOver;
/*0x3c*/ CXStr         Tooltip;
/*0x40*/ bool          bResizeable;
/*0x44*/

	//SListWndColumn() {};
	SListWndColumn(CXSTR* strLabel = nullptr,
		int width = 0,
		CTextureAnimation* pta = nullptr,
		UINT flags = 0,
		UINT type = 0x03,
		CTextureAnimation* pselected = nullptr,
		CTextureAnimation* pmouseOver = nullptr,
		CXSTR* tooltip = nullptr,
		bool bResizeable = false,
		SIZE textureSize = { 0 },
		POINT textureOffset = { 0 })
	{
		Width = width;
		MinWidth = 10;
		StrLabel = strLabel;
		pTextureAnim = pta;
		Flags = flags;
		Type = type;
		pSelected = pselected;
		pMouseOver = pmouseOver;
		Tooltip = tooltip;
		TextureSize = textureSize;
		TextureOffset = textureOffset;
	}
};

// Size is 0x298 in eqgame Sep 11 2017 Test (see 8D1D4C)
class EQLIB_OBJECT CListWnd //ok Look... this SHOULD inherit CXWnd but doing so... calls the constructor, and we dont want that... so... : public CXWnd
{
public:
	// we include CXW instead...
/*0x000*/ PCCONTEXTMENUVFTABLE pvfTable;
/*0x004*/ CXW_NO_VTABLE

	// CListWnd members
	// NOTE: ItemsArray has subids and this is the reason why you WILL NOT see
	// anything useful in the debugger sometimes if you cursor over it and expand it...
	// So... list->ItemsArray.m_array[0].Cells.m_array[1] might display something
	// while list->ItemsArray.m_array[0].Cells.m_array[0] might not
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x1f0*/ int          Filler0x1f0;
#endif
/*0x1f4*/ ArrayClass_RO<SListWndLine_RO> ItemsArray;       // see CListWnd__GetItemData_x 0x8BD768                 add     ecx, 1F4h
/*0x204*/ ArrayClass_RO<SListWndColumn_RO> Columns;
/*0x214*/ int          CurSel;
/*0x218*/ int          CurCol;
/*0x21c*/ int          DownItem;
/*0x220*/ int          ScrollOffsetY;
/*0x224*/ int          HeaderHeight;
/*0x228*/ int          FirstVisibleLine;
/*0x22c*/ int          SortCol;
/*0x230*/ bool         bSortAsc;
/*0x231*/ bool         bFixedHeight;
/*0x232*/ bool         bOwnerDraw;
/*0x233*/ bool         bCalcHeights;
/*0x234*/ bool         bColumnSizable;
/*0x238*/ int          LineHeight;
/*0x23c*/ int          ColumnSepDragged;
/*0x240*/ int          ColumnSepMouseOver;
/*0x244*/ COLORREF     HeaderText;
/*0x248*/ COLORREF     Highlight;
/*0x24c*/ COLORREF     Selected;
/*0x250*/ CUITextureInfo2 BGHeader;
/*0x268*/ COLORREF     BGHeaderTint;
/*0x26c*/ CTextureAnimation* pRowSep;
/*0x270*/ CTextureAnimation* pColumnSep;
/*0x274*/ CEditBaseWnd* pEditCell;
/*0x278*/ void*        pItemDataSomething;
/*0x27c*/ bool         bHasItemTooltips;
/*0x280*/ RECT         PrevInsideRect;
/*0x290*/ UINT         ListWndStyle;
/*0x294*/ LONG         LastVisibleTime;
/*0x298*/

	CListWnd(CXWnd*, uint32_t, const CXRect&);
	CListWnd() {};
	bool IsLineEnabled(int) const;
	const CTextureAnimation* GetColumnAnimation(int) const;
	const CTextureAnimation* GetColumnAnimationMouseOver(int) const;
	const CTextureAnimation* GetColumnAnimationSelected(int) const;
	const CTextureAnimation* GetItemIcon(int, int) const;
	CXRect GetHeaderRect(int) const;
	CXRect GetItemRect(int, int) const;
	CXRect GetSeparatorRect(int) const;
	CXStr GetColumnLabel(int) const;
	CXStr* GetItemText(CXStr*, int, int) const;
	int AddColumn(const CXStr& Label, CTextureAnimation* pTA, int Width, uint32_t Flags, CXStr Tooltip = "",
		uint32_t Type = 3, CTextureAnimation* pTASelected = 0, CTextureAnimation* pTAMouseOver = 0,
		bool bResizeable = false, tagSIZE TextureSize = { 0, 0 }, tagPOINT TextureOffset = { 0, 0 });
	int AddColumn(const CXStr& Label, int Width, uint32_t Flags, uint32_t Type = 3/*text/icon type*/);
	int AddLine(SListWndLine*);
#if !defined(ROF2EMU) && !defined(UFEMU)
	int AddString(const CXStr& Str, COLORREF Color, uint64_t Data = 0, const CTextureAnimation*pTa = NULL, const char*TooltipStr = NULL);
	int AddString(const char* Str, COLORREF Color, uint64_t Data, const CTextureAnimation*pTa, const char* TooltipStr = NULL);
#else
	int AddString(const CXStr& Str, COLORREF Color, uint32_t Data = 0, const CTextureAnimation*pTa = NULL, const char*TooltipStr = NULL);
	int AddString(const char*Str, COLORREF Color, uint32_t Data, const CTextureAnimation*pTa, const char* TooltipStr = NULL);
#endif
	int GetColumnJustification(int) const;
	int GetColumnMinWidth(int) const;
	CXStr GetColumnTooltip(int) const;
	int GetColumnWidth(int) const;
	int GetCurCol() const;
	int GetCurSel() const;
	int GetItemAtPoint(const POINT& pt) const;
	int GetItemHeight(int) const;
	uint32_t GetColumnFlags(int) const;
#if !defined(ROF2EMU) && !defined(UFEMU) 
	uint64_t GetItemData(int) const;
#else
	uint32_t GetItemData(int) const;
#endif
	COLORREF GetItemColor(int, int) const;
	void CalculateFirstVisibleLine();
	void CalculateLineHeights();
	void CalculateVSBRange();
	void ClearAllSel();
	void ClearSel(int);
	void CloseAndUpdateEditWindow();
	void EnableLine(int Index, bool bVal);
	void EnsureVisible(int);
	void ExtendSel(int);
	void GetItemAtPoint(const CXPoint& pt, int* ID, int* SubItem) const;
	void InsertLine(int ID, SListWndLine*rEntry);
	void RemoveLine(int);
	void RemoveString(int);
	void SetColors(unsigned long, unsigned long, unsigned long);
	void SetColumnJustification(int, int);
	void SetColumnLabel(int, const CXStr&);
	void SetColumnWidth(int, int);
	void SetCurSel(int);
	void SetItemColor(int, int, unsigned long);
#if !defined(ROF2EMU) && !defined(UFEMU) 
	void SetItemData(int ID, uint64_t Data);
#else
	void SetItemData(int ID, uint32_t Data);
#endif
	void SetItemText(int ID, int SubID, const CXStr& Text);
	void ShiftColumnSeparator(int, int);
	void ToggleSel(int);

	// virtual
	~CListWnd();
	CTextureAnimation* GetCursorToDisplay() const;
	int Compare(const SListWndLine&, const SListWndLine&) const;
	int Draw() const;
	int DrawBackground() const;
	int DrawColumnSeparators() const;
	int DrawHeader() const;
	int DrawItem(int, int, int) const;
	int DrawLine(int) const;
	int DrawSeparator(int) const;
	int HandleLButtonDown(const CXPoint&, uint32_t);
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int HandleLButtonUpAfterHeld(const CXPoint&, uint32_t);
	int HandleMouseMove(const CXPoint&, uint32_t);
	int HandleRButtonDown(const CXPoint&, uint32_t);
	int OnHeaderClick(CXPoint);
	int OnMove(CXRect);
	int OnResize(int, int);
	int OnVScroll(EScrollCode, int);
	int SetVScrollPos(int Pos);
	int WndNotification(CXWnd*, uint32_t, void*);
	void DeleteAll();
	void Sort();
	void SetColumnsSizable(bool bColumnsSizable);
	void GetWndPosition(CXWnd* pWnd, int& ItemID, int& SubItemID) const;
	void SetItemWnd(int Index, int SubItem, CXWnd* pWnd);
	CXWnd* GetItemWnd(int Index, int SubItem) const;
	void SetItemIcon(int Index, int SubItem, const CTextureAnimation* pTA);
	void CalculateCustomWindowPositions();
};

// Size is 0x290 in eagame 2016 Nov 14
class EQLIB_OBJECT CContextMenu // cant do this it calls the constructor if we create a menu so no... : public CListWnd
{
public:
	// we include the CListWnd class manually instead... it has a CXWnd first...
/*0x000*/ PCCONTEXTMENUVFTABLE pvfTable;
/*0x004*/ CXW_NO_VTABLE
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x1e0*/ int          Filler0x1e0;
#endif
/*0x1e4*/ ArrayClass_RO<SListWndLine_RO> ItemsArray; //see CListWnd__GetItemData_x 0x8BD768                 add     ecx, 1F4h
/*0x1f4*/ ArrayClass_RO<SListWndColumn_RO> Columns;
/*0x204*/ int          CurSel;
/*0x208*/ int          CurCol;
/*0x20c*/ int          DownItem;
/*0x210*/ int          ScrollOffsetY;
/*0x214*/ int          HeaderHeight;
/*0x218*/ int          FirstVisibleLine;
/*0x21c*/ int          SortCol;
/*0x220*/ bool         bSortAsc;
/*0x221*/ bool         bFixedHeight;
/*0x222*/ bool         bOwnerDraw;
/*0x223*/ bool         bCalcHeights;
/*0x224*/ bool         bColumnSizable;
/*0x228*/ int          LineHeight;
/*0x22c*/ int          ColumnSepDragged;
/*0x230*/ int          ColumnSepMouseOver;
/*0x234*/ COLORREF     HeaderText;
/*0x238*/ COLORREF     Highlight;
/*0x23c*/ COLORREF     Selected;
/*0x240*/ CUITextureInfo2 BGHeader;
/*0x258*/ COLORREF     BGHeaderTint;
/*0x25c*/ CTextureAnimation* pRowSep;
/*0x260*/ CTextureAnimation* pColumnSep;
/*0x264*/ CEditBaseWnd* pEditCell;
/*0x268*/ void*        pItemDataSomething;
/*0x26c*/ bool         bHasItemTooltips;
/*0x270*/ RECT         PrevInsideRect;
/*0x280*/ UINT         ListWndStyle;
/*0x284*/ LONG         LastVisibleTime;
/*0x288*/ int          NumItems;
/*0x28C*/ int          Unknown0x28C;
/*0x290*/

	int InsertMenuItem(const CXStr& str, unsigned int position, unsigned int ItemID,
		bool bChecked, COLORREF Color, bool bEnable);
	CContextMenu(CXWnd* pParent, uint32_t MenuID, const CXRect& rect);
	CContextMenu(CXWnd*, uint32_t, const tagRECT&);
	// MenuID: Set HighPart as the ID for submenus and LowPart is then the subindex
	int AddMenuItem(const CXStr& str, unsigned int MenuID, bool bChecked = false, COLORREF Color = 0xFFFFFFFF, bool bEnable = true);
	int AddSeparator();
	void Activate(CXPoint, int, int);
	void CheckMenuItem(int ID, bool bVal = true, bool bUncheckAll = false);
	void EnableMenuItem(int ID, bool bVal = true);
	void RemoveAllMenuItems();
	void RemoveMenuItem(int id);
	void SetMenuItem(int ID, const CXStr& Str, bool bChecked = false, COLORREF Color = 0xFFFFFFFF, bool bEnable = true);

	// virtual
	~CContextMenu();
	CContextMenu() {}
	int OnKillFocus(CXWnd*);
	void Deactivate();
};

class EQLIB_OBJECT CLoadskinWnd : public CSidlScreenWnd
{
public:
	CLoadskinWnd(CXWnd*);
	void Activate();
	void UpdateSkinList();

	// virtual
	~CLoadskinWnd();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
};

class EQLIB_OBJECT CLootWnd : public CSidlScreenWnd
{
public:
	CLootWnd(CXWnd*);
	void Activate(unsigned char, long, long, long, long);
	void AddContainerToLootArray(EQ_Item*);
	void AddEquipmentToLootArray(EQ_Item*);
	void AddNoteToLootArray(EQ_Item*);
	void Deactivate(bool);
	void LootAll(bool);
	void RequestLootSlot(int Slot, bool bAutoInventory);
	void SlotLooted(int);

	// virtual
	~CLootWnd();
	int OnProcessFrame();
	int PostDraw() const;
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void FinalizeLoot();
	void Init();

/*0x208*/ BYTE         Unknown0x1b8[0xd1];
/*0x2d9*/ bool         bLootAll;
/*0x2da*/
};

class EQLIB_OBJECT CMapToolbarWnd : public CSidlScreenWnd
{
public:
	CMapToolbarWnd(CXWnd*);
	void Activate();
	void SetAutoMapButton(bool);

	// virtual
	~CMapToolbarWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
};

//class CMapViewWnd : public CSidlScreenWnd, public WndEventHandler
class EQLIB_OBJECT CMapViewWnd
{
public:
/*0x000*/ CSIDLWNDVFTABLE* pvfTable;
	CXW_NO_VTABLE
	SIDL

	CMapViewWnd(CXWnd*);
	bool IsMappingEnabled();
	void Activate();
	void ActivateAutoMapping();
	void DeactivateAutoMapping();
	// void SetCurrentZone(EQZoneIndex, struct T3D_XYZ*, struct T3D_XYZ*);

	// virtual
	~CMapViewWnd();
	int HandleLButtonDown(const CXPoint&&, uint32_t);
	int HandleLButtonHeld(const CXPoint&, uint32_t);
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int HandleLButtonUpAfterHeld(const CXPoint&, uint32_t);
	int HandleWheelMove(CXPoint, int, uint32_t);
	int OnProcessFrame();
	int PostDraw() const;
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
	void LoadIniInfo();
	void StoreIniInfo();
	void GetWorldCoordinates(float*);

	// private
	void Init();
};

class EQLIB_OBJECT CMemoryStream
{
public:
	CXStr GetString();
	static int GetStringSize(CXStr&);
	void GetString(CXStr&);
	void PutString(CXStr&);
};

EQLIB_OBJECT struct POINTMERCHANTITEM
{ 
/*0x00*/ char          ItemName[0x40]; 
/*0x40*/ int           ItemID;
/*0x44*/ DWORD         Price; 
/*0x48*/ int           ThemeID;
/*0x4c*/ int           IsStackable;
/*0x50*/ int           IsLore;
/*0x54*/ int           RaceMask;
/*0x58*/ int           ClassMask;
/*0x5c*/ bool          bCanUse;
/*0x60*/ 
};
using PPOINTMERCHANTITEM = POINTMERCHANTITEM*;

class PointMerchantInterface;

class EQLIB_OBJECT PointMerchantWnd : public CSidlScreenWnd
{
public:
	int                Unknown0x000;
	int                Unknown0x004;
	int                Unknown0x008;
	int                NumItems;
	bool               HdrItemName;
	bool               HdrTheme;
	bool               HdrPrice;
	char               OriginalPointsLabel[0x40];
	CLabel*            MerchantNameLabel;
	CListWnd*          ItemList;
	CListWnd*          PointList;
	CButtonWnd*        EquipButton;
	CButtonWnd*        PurchaseButton;
	CButtonWnd*        SellButton;
	CButtonWnd*        DoneButton;
	CLabel*            PointsAvailableValue;
	CLabel*            PointsEverEarnedLabel;
	CLabel*            PointsAvailableLabel;
	UINT               NextRefreshTime;
	PSPAWNINFO         ActiveMerchant;
	POINTMERCHANTITEM** Items;
	int                MerchantThemeId;
	int                CurrentSelection;
	int                CurrentSort;
	bool               bCurrentAscending;
	ItemGlobalIndex    ItemLocation;
	CONTENTS*          pSelectedItem;
	bool               bInventoryWasActive;
	int                CurrentItem;
	int                CurrentQuantity;
	int                SliderType;
	PointMerchantInterface* pHandler;
};

class EQLIB_OBJECT VeBaseReferenceCount
{
public:
/*0x00*/ virtual UINT GetMemUsage() const;
/*0x04*/ virtual ~VeBaseReferenceCount();
 
/*0x04*/ int References;
};

enum eMerchantServices
{
	Regular,
	Recovery,
	Mail,
	ServiceCount
};

class EQLIB_OBJECT PopDialogHandler2
{
public:
/*0x08*/ virtual void Unknownv0x08();
};

class EQLIB_OBJECT WndEventHandler
{
public:
	UINT LastCheckTime;
	UINT Filler;
};

struct sell_msg;

class EQLIB_OBJECT CMerchantWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
#if !defined(ROF2EMU) && !defined(UFEMU)
	class MerchantPageHandler : public VeBaseReferenceCount
	{
	public:
	/*0x08*/ CMerchantWnd*   pParent;
	/*0x0c*/ int             MaxItems;
	/*0x10*/ int             LastIndex;
	/*0x14*/ CListWnd*       ItemsList;
	/*0x18*/ CPageWnd*       PurchasePage;
	/*0x1c*/ bool            bListNeedsRefresh;
	/*0x20*/ EQArray<_CONTENTDATA> ItemContainer;
	/*0x40*/ int Unknown0x40;
	/*0x44*/ int Unknown0x44;
	/*0x48*/ int Unknown0x48;
	/*0x4c*/ int Unknown0x4c;
	/*0x50*/ int Unknown0x50;
	/*0x54*/ int Unknown0x54;
	/*0x58*/ int Unknown0x58;
	/*0x5c*/ int Unknown0x5c;
	/*0x60*/ int Unknown0x60;
	/*0x64*/ int Unknown0x64;
	/*0x68*/ int Unknown0x68;
	/*0x6c*/ int Unknown0x6c;
	/*0x70*/ int Unknown0x70;
	/*0x74*/ int Unknown0x74;
	/*0x78*/ int Unknown0x78;
	/*0x7c*/ int Unknown0x7c;
	/*0x80*/ int Unknown0x80;
	/*0x84*/

	// offset comments indicate vtable offset
	/*0x0c*/ virtual void Unknownv0x08();
	/*0x0c*/ virtual void Unknownv0x0c();
	/*0x10*/ virtual void Unknownv0x10();
	/*0x14*/ virtual void Unknownv0x14();
	/*0x18*/ virtual void DestroyItemByUniqueId(int64_t UniqueID);
	/*0x1c*/ virtual void DestroyItemByItemGuid(const EqItemGuid& ItemGuid);
	/*0x20*/ virtual bool AddItemToArray(const VePointer<CONTENTS>& pSentItem);
	/*0x24*/ virtual int Sort(SListWndSortInfo* SortInfo);
	/*0x28*/ virtual void UpdateList();
	/*0x2c*/ virtual int DisplayBuyOrSellPrice(const VePointer<CONTENTS>& pItem, bool bBuy) const;
	/*0x30*/ virtual CXStr GetPriceString(int Price) const;
	/*0x34*/ virtual void UpdateControls();
	/*0x38*/ virtual bool RequestGetItem(int Qty);
	/*0x3c*/ virtual void RequestPutItem(int Qty);
	/*0x40*/ virtual bool CanSelectSlot(const ItemGlobalIndex& Location) const;
	/*0x44*/ virtual void DisablePageSpecificButtons();
	/*0x48*/ virtual eMerchantServices GetHandlerType() const;
	/*0x4c*/ virtual void CXWnd__OnShowANDPostDraw() const;
	/*0x50*/ virtual void Unknownv0x50() const;
	/*0x54*/ virtual void Unknownv0x54() const;
	/*0x58*/ virtual void Unknownv0x58() const;
	};

	class PurchasePageHandler : public MerchantPageHandler
	{
	public:
	/*0x84*/ bool bShowAllItems;
	/*0x88*/ int Unknown0x88;
	/*0x8c*/ int Unknown0x8c;
	/*0x90*/ int Unknown0x90;
	/*0x94*/ int Unknown0x94;
	/*0x98*/ int Unknown0x98;
	/*0x9c*/ int Unknown0x9c;
	/*0xa0*/ int Unknown0xa0;
	/*0xa4*/ int Unknown0xa4;
	/*0xa8*/
		bool RequestGetItem(int);
		void RequestPutItem(int);
	};

	// size 0x420 in Nov 02 2017 Beta 
/*0x230*/ UINT         NextRefreshTime;
/*0x234*/ bool         bInventoryWasActive;
/*0x240*/ VeArray<VePointer<MerchantPageHandler>> PageHandlers;
/*0x24c*/ float        MerchantGreed;
/*0x250*/ ItemGlobalIndex ItemLocation;
/*0x25c*/ BYTE         Unknown0x254[0x8];
/*0x264*/ VePointer<CONTENTS> pSelectedItem;
/*0x268*/ __time32_t   MailExpireTime;
/*0x26c*/ bool         bAutoRetrieveingMail;
/*0x270*/ BYTE         Unknown0x268[0x10];
/*0x280*/ char*        Labels[0xc];
/*0x2b0*/ CEditWnd*    SearchEdit;
/*0x2b4*/ CButtonWnd*  SearchButton;
/*0x2b8*/ CLabel*      MerchantNameLabel;
/*0x2bc*/ CLabel*      SelectedItemLabel;
/*0x2c0*/ CLabel*      SelectedPriceLabel;
/*0x2c4*/ CButtonWnd*  InspectButton;
/*0x2c8*/ CButtonWnd*  PreviewButton;
/*0x2cc*/ CButtonWnd*  SelectedItemButton;
/*0x2d0*/ CButtonWnd*  BuyButton;
/*0x2d4*/ CButtonWnd*  BuyMarketPlaceButton;
/*0x2d8*/ CButtonWnd*  SellButton;
/*0x2dc*/ CButtonWnd*  RecoverButton;
/*0x2e0*/ CButtonWnd*  RetrieveButton;
/*0x2e4*/ CButtonWnd*  RetrieveAllButton;
/*0x2e8*/ CButtonWnd*  SendButton;
/*0x2ec*/ CButtonWnd*  AdventureButton;
/*0x2f0*/ CLabel*      SendToLabel;
/*0x2f4*/ CEditWnd*    SendToEdit;
/*0x2f8*/ CLabel*      NoteLabel;
/*0x2fc*/ CEditWnd*    NoteEdit;
/*0x300*/ CButtonWnd*  ClearNoteButton;
/*0x304*/ CListWnd*    ItemsList;
/*0x308*/ CListWnd*    ItemsRecoveryList;
/*0x30c*/ CListWnd*    ItemsMailList;
/*0x310*/ CButtonWnd*  DoneButton;
/*0x314*/ CPageWnd*    PurchasePage;
/*0x318*/ CPageWnd*    RecoveryPage;
/*0x31c*/ CPageWnd*    MailPage;
/*0x320*/ CTabWnd*     TabWindow;
/*0x324*/ CButtonWnd*  UsableButton;
/*0x328*/ CLabel*      CurrentCurrencyLabel;
/*0x32c*/ int          Unknown0x32c;
/*0x330*/ int          Unknown0x330;
/*0x334*/ int          Unknown0x334;
/*0x338*/ int          Unknown0x338;
/*0x33C*/ int          Unknown0x33C;
/*0x340*/ int          Guk_Currency;
/*0x344*/ BYTE Unknown0x340[0x100];
/*0x444*/
#else
	template <typename TItem>
	class ItemContainer
	{
	public:
	/*0x00*/UINT       Size;
	/*0x04*/int        Spec;
	/*0x08*/VeArray<VePointer<TItem>> Items;
	/*0x14*/BYTE       AtDepth;
	/*0x16*/short      Slots[2];
	/*0x1a*/bool       bDynamic;
	/*0x1c*/
	};

	class ItemBaseContainer : public ItemContainer<CONTENTS>
	{
	public:
		// size is 0x1c
	};

	class MerchantPageHandler : public VeBaseReferenceCount
	{
	public:
	/*0x08*/ CMerchantWnd* pParent;
	/*0x0c*/ ItemBaseContainer ItemContainer; // size 0x1c
	/*0x28*/ int       MaxItems;
	/*0x2c*/ int       LastIndex;
	/*0x30*/ CListWnd* ItemsList;
	/*0x34*/ CPageWnd* Page;
	/*0x38*/ bool      bListNeedsRefresh;
	/*0x3c*/ 

	/*0x0c*/ virtual void Unknownv0x10();
	/*0x10*/ virtual void Unknownv0x14();
	/*0x14*/ virtual void DestroyItemByUniqueId(int64_t UniqueID);
	/*0x18*/ virtual void DestroyItemByItemGuid(const EqItemGuid& ItemGuid);
	/*0x1c*/ virtual bool AddItemToArray(const VePointer<CONTENTS>& pSentItem);
	/*0x20*/ virtual int Sort(SListWndSortInfo*SortInfo);
	/*0x24*/ virtual void UpdateList();
	/*0x28*/ virtual int DisplayBuyOrSellPrice(const VePointer<CONTENTS>& pItem, bool bBuy) const;
	/*0x2c*/ virtual CXStr GetPriceString(int Price) const;
	/*0x30*/ virtual void UpdateControls();
	/*0x34*/ virtual bool RequestGetItem(int Qty);
	/*0x38*/ virtual void RequestPutItem(int Qty);
	};

	class PurchasePageHandler : public MerchantPageHandler
	{
	public:
	/*0x3c*/ bool bShowAllItems;
	/*0x40*/
		bool RequestGetItem(int);
		void RequestPutItem(int);
	};

/*0x228*/ UINT         NextRefreshTime;
/*0x22c*/ bool         bInventoryWasActive;
/*0x238*/ VeArray<VePointer<MerchantPageHandler>> PageHandlers;
/*0x244*/ float        MerchantGreed;
/*0x248*/ ItemGlobalIndex ItemLocation;
/*0x258*/ VePointer<CONTENTS> pSelectedItem;
/*0x25c*/ __time32_t   MailExpireTime;
/*0x260*/ bool         bAutoRetrieveingMail;
/*0x264*/ CLabel*      plabelMerchantName;
/*0x268*/ CLabel*      plabelSelectedItem;
/*0x26c*/ CLabel*      plabelSelectedPrice;
/*0x270*/ CButtonWnd*  InspectButton;
/*0x274*/ CButtonWnd*  PreviewButton;
/*0x278*/ CButtonWnd*  SelectedItemLabel;
/*0x27c*/ CButtonWnd*  BuyButton;
/*0x280*/ CButtonWnd*  SellButton;
/*0x2dc*/ CButtonWnd*  RecoverButton;
/*0x2e0*/ CButtonWnd*  RetrieveButton;
/*0x2e4*/ CButtonWnd*  RetrieveAllButton;
/*0x2e8*/ CButtonWnd*  SendButton;
/*0x2f0*/ CLabel*      SendToLabel;
/*0x2f4*/ CEditWnd*    SendToEdit;
/*0x2f8*/ CLabel*      NoteLabel;
/*0x2fc*/ CEditWnd*    NoteEdit;
/*0x300*/ CButtonWnd*  ClearNoteButton;
/*0x304*/ CListWnd*    ItemsList;
/*0x308*/ CListWnd*    ItemsRecoveryList;
/*0x30c*/ CListWnd*    ItemsMailList;
/*0x310*/ CButtonWnd*  DoneButton;
/*0x314*/ CPageWnd*    PurchasePage;
/*0x318*/ CPageWnd*    RecoveryPage;
/*0x31c*/ CPageWnd*    MailPage;
/*0x320*/ CTabWnd*     TabWindow;
/*0x324*/ CButtonWnd*  UsableButton;
#endif

	CMerchantWnd(CXWnd*);
	void Activate(EQPlayer*, float);
	void AddContainerToMercArray(EQ_Container*);
	void AddEquipmentToMercArray(EQ_Equipment*);
	void AddNoteToMercArray(EQ_Note*);
	void ClearMerchantSlot(int);
	void FinishBuyingItem(sell_msg*);
	void FinishSellingItem(sell_msg*);
	// older clients and im not really sure that it was correct then
	// EQLIB_OBJECT void SelectBuySellSlot(int, CTextureAnimation*);
#if !defined(ROF2EMU) && !defined(UFEMU)
	// for itemlists such as merchant items, we also need to send the actual listindex.
	int SelectBuySellSlot(ItemGlobalIndex*, int ListIndex = -1);
#else
	int SelectBuySellSlot(ItemGlobalIndex*);
#endif
	// virtual
	~CMerchantWnd();
	int OnProcessFrame();
	int PostDraw() const;
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void DisplayBuyOrSellPrice(bool, EQ_Item*);
	void HandleBuy(int);
	void HandleSell(int);
	void Init();
	void UpdateBuySellButtons();
};

class EQLIB_OBJECT CMusicPlayerWnd : public CSidlScreenWnd
{
public:
	CMusicPlayerWnd(CXWnd*);
	void Activate();
	void AutoStart();

	// virtual
	~CMusicPlayerWnd();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
	void LoadIniInfo();
	void StoreIniInfo();

	// protected
	void Update();
	void UpdateButtons();

	// private
	void Init();
};

class EQLIB_OBJECT CNoteWnd : public CSidlScreenWnd
{
public:
	CNoteWnd(CXWnd*);
	bool CheckNote(EQ_Note*);
	void Activate();
	void SetNote(char*);

	// virtual
	~CNoteWnd();
	int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void Init();
};

class EQLIB_OBJECT ConversationJournal
{
public:
	~ConversationJournal();
	ConversationJournal();
	JournalNPC* FindNPCByNameZone(char*, int);
	JournalNPC* GetNPC(int);
	int AddEntry(char*, int, long, float, float, float, char*, int);
	int DeleteNPC(char*, int);
	int Load(char*);
	int Save(char*);
	JournalCategory** GetCategoryList();
	JournalCategory* AddCategory(char*, char*, int);
	JournalCategory* AddCategory(int);
	JournalCategory* GetCategory(char*);
	JournalCategory* GetCategory(int);
	void Clean();
	void DeleteCategory(int);

	// protected
	int FindFreeID();

	// private
	JournalNPC* AddNPC(char*, int);
	JournalNPC* ReadNPC(FILE*);
	void AllocateCatArray();
	void AllocateNPCArray();
	void ReadCategory(FILE*);
};

class EQLIB_OBJECT COptionsWnd : public CSidlScreenWnd
{
public:
	COptionsWnd(CXWnd*);
	// KeyboardAssignmentData::~KeyboardAssignmentData();
	// KeyboardAssignmentData::KeyboardAssignmentData();
	void Activate();
	void RefreshCurrentKeyboardAssignmentList();
	void ResetKeysToDefault();
	void RestoreDefaultColors();

	// virtual
	~COptionsWnd();
	int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	int ChatPageOnProcessFrame();
	int ChatPageWndNotification(CXWnd*, uint32_t, void*);
	int ColorPageOnProcessFrame();
	int ColorPageWndNotification(CXWnd*, uint32_t, void*);
	int DisplayPageOnProcessFrame();
	int DisplayPageWndNotification(CXWnd*, uint32_t, void*);
	int GeneralPageOnProcessFrame();
	int GeneralPageWndNotification(CXWnd*, uint32_t, void*);
	int KeyboardPageDeactivate();
	int KeyboardPageHandleKeyboardMsg(uint32_t, uint32_t, bool);
	int KeyboardPageOnProcessFrame();
	int KeyboardPageWndNotification(CXWnd*, uint32_t, void*);
	int MousePageOnProcessFrame();
	int MousePageWndNotification(CXWnd*, uint32_t, void*);
	int RedirectDeactivateTo(CPageWnd*);
	int RedirectHandleKeyboardMsgTo(CPageWnd*, uint32_t, uint32_t, bool);
	int RedirectOnProcessFrameTo(CPageWnd*);
	int RedirectWndNotificationTo(CPageWnd*, CXWnd*, uint32_t, void*);
	void AddKeyboardAssignment(int, int, int);
	void InitKeyboardAssignments();
	void InitKeyboardPage();
	void KeyboardPageCancelKeypressAssignment();
	void SetBagOptions(int, int);
	void SyncChatPage();
	void SyncColorPage();
	void SyncDisplayPage();
	void SyncGeneralPage();
	void SyncMousePage();
	void FillChatFilterList();
};

class EQLIB_OBJECT CPageTemplate
{
public:
	CPageTemplate(CParamPage*);

	// virtual
	~CPageTemplate();
};

class EQLIB_OBJECT CPageWnd : public CSidlScreenWnd
{
public:
	CPageWnd(CXWnd*, uint32_t, CXRect, CXStr, CPageTemplate*);
	CXStr GetTabText(bool bSomething = false) const;
	void SetTabText(CXStr &) const;
	// virtual
	~CPageWnd();
};

class EQLIB_OBJECT CParam
{
public:
	CParam& operator=(const CParam&);
	// virtual
	~CParam();
};

class EQLIB_OBJECT CParamButton
{
public:
	CParamButton();
	CParamButton& operator=(const CParamButton&);

	// virtual
	~CParamButton();
	bool ReadFromXMLSOM(CXMLSOMDocument &);
	bool WriteToXMLSOM(CXMLSOMDocument &);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream &);
	void WriteToStream(CMemoryStream &);
};

class EQLIB_OBJECT CParamButtonDrawTemplate
{
public:
	CParamButtonDrawTemplate();
	CParamButtonDrawTemplate& operator=(const CParamButtonDrawTemplate&);

	// virtual
	~CParamButtonDrawTemplate();
	bool ReadFromXMLSOM(CXMLSOMDocument &);
	bool WriteToXMLSOM(CXMLSOMDocument &);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream &);
	void WriteToStream(CMemoryStream &);
};

class EQLIB_OBJECT CParamClass
{
public:
	CParamClass();
	CParamClass& operator=(const CParamClass&);

	// virtual
	~CParamClass();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamCombobox
{
public:
	CParamCombobox();
	CParamCombobox& operator=(const CParamCombobox&);
	// virtual
	~CParamCombobox();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamControl
{
public:
	CParamControl();
	CParamControl& operator=(const CParamControl&);
	// virtual
	~CParamControl();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamEditbox
{
public:
	CParamEditbox();
	CParamEditbox& operator=(const CParamEditbox&);

	// virtual
	~CParamEditbox();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamFrame
{
public:
	CParamFrame();
	// virtual
	~CParamFrame();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamFrameTemplate
{
public:
	CParamFrameTemplate();
	CParamFrameTemplate& operator=(const CParamFrameTemplate&);

	// virtual
	~CParamFrameTemplate();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamGauge
{
public:
	CParamGauge();
	CParamGauge& operator=(const CParamGauge&);

	// virtual
	~CParamGauge();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamGaugeDrawTemplate
{
public:
	CParamGaugeDrawTemplate();
	CParamGaugeDrawTemplate& operator=(const CParamGaugeDrawTemplate&);

	// virtual
	~CParamGaugeDrawTemplate();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamInvSlot
{
public:
	CParamInvSlot();
	CParamInvSlot& operator=(const CParamInvSlot&);

	// virtual
	~CParamInvSlot();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamLabel
{
public:
	CParamLabel();
	CParamLabel& operator=(const CParamLabel&);

	// virtual
	~CParamLabel();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamListbox
{
public:
	CParamListbox();
	CParamListbox& operator=(const CParamListbox&);
	// virtual
	~CParamListbox();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamListboxColumn
{
public:
	CParamListboxColumn();
	CParamListboxColumn& operator=(const CParamListboxColumn&);

	// virtual
	~CParamListboxColumn();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamPage
{
public:
	CParamPage();
	CParamPage& operator=(const CParamPage&);

	// virtual
	~CParamPage();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamPoint
{
public:
	CParamPoint();
	CParamPoint& operator=(const CParamPoint&);

	// virtual
	~CParamPoint();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamRGB
{
public:
	CParamRGB();
	CParamRGB& operator=(const CParamRGB&);

	// virtual
	~CParamRGB();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamScreen
{
public:
	CParamScreen();
	CParamScreen& operator=(const CParamScreen&);

	// virtual
	~CParamScreen();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamScreenPiece
{
public:
	CParamScreenPiece();
	CParamScreenPiece& operator=(const CParamScreenPiece&);

	// virtual
	~CParamScreenPiece();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamScrollbarDrawTemplate
{
public:
	CParamScrollbarDrawTemplate();
	CParamScrollbarDrawTemplate& operator=(const CParamScrollbarDrawTemplate&);

	// virtual
	~CParamScrollbarDrawTemplate();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamSize
{
public:
	CParamSize();
	CParamSize& operator=(const CParamSize&);

	// virtual
	~CParamSize();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamSlider
{
public:
	CParamSlider();
	CParamSlider& operator=(const CParamSlider&);

	// virtual
	~CParamSlider();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamSliderDrawTemplate
{
public:
	CParamSliderDrawTemplate();
	CParamSliderDrawTemplate& operator=(const CParamSliderDrawTemplate&);

	// virtual
	~CParamSliderDrawTemplate();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamSpellGem
{
public:
	CParamSpellGem();
	CParamSpellGem& operator=(const CParamSpellGem&);

	// virtual
	~CParamSpellGem();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamSpellGemDrawTemplate
{
public:
	CParamSpellGemDrawTemplate();
	CParamSpellGemDrawTemplate& operator=(const CParamSpellGemDrawTemplate&);

	// virtual
	~CParamSpellGemDrawTemplate();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamStaticAnimation
{
public:
	CParamStaticAnimation();
	CParamStaticAnimation& operator=(const CParamStaticAnimation&);

	// virtual
	~CParamStaticAnimation();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamStaticFrame
{
public:
	CParamStaticFrame();
	CParamStaticFrame& operator=(const CParamStaticFrame&);

	// virtual
	~CParamStaticFrame();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamStaticHeader
{
public:
	CParamStaticHeader();
	CParamStaticHeader& operator=(const CParamStaticHeader&);

	// virtual
	~CParamStaticHeader();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamStaticScreenPiece
{
public:
	CParamStaticScreenPiece();

	// virtual
	~CParamStaticScreenPiece();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamStaticText
{
public:
	CParamStaticText();
	CParamStaticText& operator=(const CParamStaticText&);

	// virtual
	~CParamStaticText();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamSTMLbox
{
public:
	CParamSTMLbox();

	// virtual
	~CParamSTMLbox();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamSuiteDefaults
{
public:
	CParamSuiteDefaults();
	CParamSuiteDefaults& operator=(const CParamSuiteDefaults&);

	// virtual
	~CParamSuiteDefaults();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamTabBox
{
public:
	CParamTabBox();
	CParamTabBox& operator=(const CParamTabBox&);


	// virtual
	~CParamTabBox();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamTextureInfo
{
public:
	CParamTextureInfo();

	// virtual
	~CParamTextureInfo();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamUi2DAnimation
{
public:
	CParamUi2DAnimation();

	// virtual
	~CParamUi2DAnimation();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParamWindowDrawTemplate
{
public:
	CParamWindowDrawTemplate();

	// virtual
	~CParamWindowDrawTemplate();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CParseTokensXML
{
public:
	~CParseTokensXML();
	// bool Accept(enum ETokTypeXML);
	bool StartFileBased(CXStr);
	CXStr GetCurFile();
	void SetError(const char*, ...);
};

class EQLIB_OBJECT CParseTokXML
{
public:
	~CParseTokXML();
	// enum ETokTypeXML NextToken();

	// private
	bool GetEntityRef(char &);
};

class EQLIB_OBJECT CPetInfoWnd : public CSidlScreenWnd
{
public:
	CPetInfoWnd(CXWnd*);
	CButtonWnd* GetButton(int);
	void Activate();
	void SetShowOnSummon(bool);
	void Update();

	// virtual
	~CPetInfoWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void Init();
};

struct petitionQtype;

class EQLIB_OBJECT CPetitionQWnd : public CSidlScreenWnd
{
public:
	CPetitionQWnd(CXWnd*);
	char* GetCurrentPetitionersName();
	void Activate();
	void AddGMText();
	void CheckedOut(const petitionQtype*, int);
	void ClearCurrentPet();
	void FillFields();
	void LogPetitionText();
	void SetButtonsForPetition(bool, bool);
	void SetPriorityDisplay();
	void UndoCheckout();
	void UpdatePetitions();

	// virtual
	~CPetitionQWnd();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
};

class EQLIB_OBJECT CPlayerNotesWnd : public CSidlScreenWnd
{
public:
	CPlayerNotesWnd(CXWnd*);
	void Activate();
	void AppendText(char*);
	void SaveNotes();

	// virtual
	~CPlayerNotesWnd();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void Init();
};

class EQLIB_OBJECT CPlayerWnd : public CSidlScreenWnd
{
public:
	CPlayerWnd(CXWnd*);
	void Activate();
	void CreateLocalMenu();
	void UpdateContextMenu();

	// virtual
	~CPlayerWnd();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
	void LoadIniInfo();
	void StoreIniInfo();

	// private
	void Init();
};

class EQLIB_OBJECT CPotionBeltWnd : public CSidlScreenWnd
{
public:
	// virtual
	int DrawTooltip(const CXWnd*) const;
};

class EQLIB_OBJECT CBandolierWnd : public CSidlScreenWnd, public WndEventHandler2
{
public:
	CButtonWnd*        pAddButton;
	CButtonWnd*        pDeleteButton;
	CButtonWnd*        pUseButton;
	CButtonWnd*        pMkHotButton;
	CButtonWnd*        pAutoSwapButton;
	CButtonWnd*        pDisplayButtons[4];
	CListWnd*          pWeaponSetList;
};

class EQLIB_OBJECT CQuantityWnd : public CSidlScreenWnd
{
public:
	CQuantityWnd(CXWnd*);
	void Activate(CXWnd*, int, int, int, int, bool);

	// virtual
	~CQuantityWnd();
	void Open(CXWnd*, int, int, int, int, int, int, bool);
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void CheckMaxEditWnd();
	void UpdateEditWndFromSlider();
	void UpdateSliderFromEditWnd();
};

class EQLIB_OBJECT CRadioGroup
{
public:
	CRadioGroup(const CXStr&);
	CXStr GetName() const;

	// virtual
	~CRadioGroup();
};

struct RaidAddMember;
struct SCRaidMessage;
struct CreateRaidMessage;
struct RenameRaidMember;
struct RaidMember;

class EQLIB_OBJECT CRaid
{
public:
	~CRaid();
	CRaid();
	bool IsInRaid();
	bool IsInvited();
	bool IsRaidGroupLeader();
	bool IsRaidLeader();
	bool IsRaidMember(char*);
	int GetLootType();
	int GetNumRaidMembers();
	RaidMember* GetRaidMemberAt(int);
	void AddRaidLooter();
	void ClearInvitedState();
	void CreateInviteRaid();
	void HandleC2SRaidMessage(char*);
	void HandleCreateInviteRaid(CSRaidMessage*);
	void HandleS2CRaidMessage(char*);
	void RemoveRaidLooter();
	void RemoveRaidMember();
	void ResetRaid();
	void ResetWindow();
	void SendInviteResponse(bool);
	void SendLeadershipChange(char*);
	void SendRaidChat(char*);
	void SetLootType(char*);
	void SetRaidLeader(char*);
	void SetTargetRaidPlayer(char*);
	void UpdateClassColor(int, unsigned long);
	void UpdateOptionsWindow();

	// private
	bool IsRaidLooter(char*);
	int FindOpenIndex();
	int FindPlayerIndex(char*);
	int FindRaidGroupLeader(int);
	void AddRaidMember(RaidAddMember*);
	void ChangeLeadership(char*);
	void DeleteRaidMember(SCRaidMessage*);
	void DetermineRaidChanges(char*);
	void HandleAddLooter(char*);
	void HandlePositionChange(SCRaidMessage*);
	void HandleRemoveLooter(char*);
	void HandleSetLootType(int);
	void InitializeRaid(char*);
	void RaidCreated(CreateRaidMessage*);
	void RaidGroupLeaderChange(SCRaidMessage*);
	void RenameMember(RenameRaidMember*);
	void SendRaidMsg(int, char*, char*, int);
	void SetLootTypeResponse(SCRaidMessage*);
	void UpdateLevelAverage();
};

class EQLIB_OBJECT CRaidOptionsWnd : public CSidlScreenWnd
{
public:
	CRaidOptionsWnd(CXWnd*);
	void Activate();
	void AddLooterToList(char*);
	void ClearLooterList();
	void UpdateComponents();

	// virtual
	~CRaidOptionsWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void Init();
	void InitializeClassColors();
};

class EQLIB_OBJECT CRaidWnd : public CSidlScreenWnd
{
public:
	CRaidWnd(CXWnd*);
	void Activate();
	void AddPlayertoList(char*, char*, char*, char*, int, int, bool);
	void ChangePosition(char*, int, int, int, bool);
	void ChangeRaidGroupLeader(char*, int, char*);
	void ClearPlayerList();
	void RemovePlayerFromList(char*, int);
	void SetClassColor(int, unsigned long);
	void SetPlayerClassColor(char*, int, int);
	void SetPlayerClassColor(int, int, int);
	void SetRaidCount(int);
	void SetRaidMemberRank(char*, char*, int);
	void SetRaidTarget(char*, int, char*, int);
	void UpdateButtons();
	void UpdateLevelAverage(int);
	void UpdateMemberName(char*, char*, int);

	// virtual
	~CRaidWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	int FindIndexNotInGroupList(char*);
	int FindOpenIndexInGroup(int);
	int FindPlayerIndexInGroup(char*, int);
	void AddSeparator();
	void Init();
	void InitializeClassColors();
	void ResortRaidGroupList(int, int);
};

class EQLIB_OBJECT CRC32Generator
{
public:
	unsigned int generateCRC32(unsigned const char*, unsigned int) const;
	unsigned int updateCRC32(unsigned int, unsigned const char*, unsigned int) const;

	// private
	static unsigned int* _crcTable;
};

EQLIB_OBJECT struct ResolutionUpdateData
{
	int                Width;
	int                Height;
	int                BitsPerPixel;
	int                RefreshRate;
	bool               bFullscreen;

	void Set(int width, int height, int bitsPerPixel, int refreshRate, bool bfullscreen = false)
	{
		Width = width;
		Height = height;
		BitsPerPixel = bitsPerPixel;
		RefreshRate = refreshRate;
		bFullscreen = bfullscreen;
	}
};

struct SDeviceInfo
{
	char Name[0x80];
};

class EQLIB_OBJECT CResolutionHandlerBase
{
public:
	static bool IsFullscreenAvailable();
	static int GetDesktopBitsPerPixel();
	static int GetDesktopHeight();
	static int GetDesktopRefreshRate();
	static int GetDesktopWidth();
	static int GetHeight();
	static int GetWidth();
	static int Init();
	static void ChangeToResolution(int, int, int, int, int);
	static void SaveSettings();
	static void Shutdown();
	static void ToggleScreenMode();
	static void UpdateWindowPosition();

	DWORD              vfTable;
	bool               bIsFullscreen;
	int                FullscreenBitsPerPixel;
	int                FullscreenRefreshRate;
	int                FullscreenWidth;
	int                FullscreenHeight;
	int                WindowedWidth;
	int                WindowedHeight;
	int                WindowOffsetX;
	int                WindowOffsetY;
	int                RestoredWidth;
	int                RestoredHeight;
	int                RestoredOffsetX;
	int                RestoredOffsetY;
	SDeviceInfo        DeviceTable[0x10];
	int                DeviceCount;
	long               DeviceIndex;
	bool               bUseD3DTextureCompression;
	bool               bResizable;
	bool               bMaximized;
	bool               bAlwaysOnTop;
	bool               bActive;
	UINT               ActiveThreadID;
	HWND               ActiveWnd;
	bool               bChangingScreenResolutions;
};

class EQLIB_OBJECT CResolutionHandler : public CResolutionHandlerBase
{
public:
	void UpdateResolution(ResolutionUpdateData& data);
	DWORD GetWindowedStyle() const;
};

class EQLIB_OBJECT CRespawnWnd
{
public:
	CRespawnWnd(CXWnd* pParent);

	// virtual
	~CRespawnWnd();
};

class EQLIB_OBJECT CScreenTemplate
{
public:
	CScreenTemplate(CParamScreen*);

	// virtual
	~CScreenTemplate();
};

class EQLIB_OBJECT CScrollbarTemplate
{
public:
	~CScrollbarTemplate();
	CScrollbarTemplate(const CScrollbarTemplate&);
	CScrollbarTemplate();
	CScrollbarTemplate& operator=(const CScrollbarTemplate&);
};

class EQLIB_OBJECT CSelectorWnd : public CSidlScreenWnd
{
public:
	CSelectorWnd(CXWnd*);
	void Activate();
	void KeyMapUpdated();

	// virtual
	~CSelectorWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
};

template <class ElementType, int Cnt>
class HashCXStrElement
{
public:
	struct CKeyCXStrElementType
	{
		CXStr          key;
		ElementType    value;
	};

	ArrayClass2_RO<ArrayClass2_RO<CKeyCXStrElementType>> HashData;
};

class EQLIB_OBJECT CXMLSymbolItem
{
public:
	CXStr                              ItemString;
	bool                               bDeclared;
	bool                               bValid;
};

class EQLIB_OBJECT CXMLSymbolClass
{
public:
	CXStr                              Class;
	ArrayClass2_RO<CXMLSymbolItem>     ItemsArray;
	CHashCXStrInt32                    ItemsHashes;
	bool                               bValid;
};

class EQLIB_OBJECT CXMLSymbolTable
{
public:
/*0x00*/ void*                         vfTable;
/*0x04*/ ArrayClass2_RO<CXMLSymbolClass> ClassesArray;
/*0x20*/ CHashCXStrInt32               ClassesHashes;
/*0x3C*/
};

class EQLIB_OBJECT CXMLDataManager
{
public:
/*0x00*/ void*                         vfTable;
/*0x00*/ CHashCXStrInt32               EnumTypeHashes;
/*0x00*/ ArrayClass2_RO<CXMLEnumInfo>  XMLEnumArray;
/*0x1c*/ HashCXStrElement<CXMLDataPtr, 16* 1024> ClassItemHashes;
/*0x38*/ ArrayClass2_RO<CXMLDataClass> XMLDataArray;
/*0x54*/ CXMLSymbolTable               SymbolTable;
/*0x90*/ CXStr                         ErrorString;
/*0x94*/

	CXMLDataManager();
	bool IsDerivedFrom(int, int);
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	CXMLData* GetXMLData(CXStr, CXStr);
	CXMLData* GetXMLData(int, int);
	int GetClassIdx(CXStr);
	int GetItemIdx(int, CXStr);
	int GetNumClass();
	int GetNumItem(int);

	// virtual
	~CXMLDataManager();
	bool DataValidate();
	bool ReadValidate(CMemoryStream&);
	bool WriteValidate(CMemoryStream&);
	int GetStreamSize();
	void IndexAll();
	void ReadFromStream(CMemoryStream&);
	void Set(CXMLDataManager&);
	void WriteToStream(CMemoryStream&);

	// protected
	void AddToSuperType(CXStr, CXMLDataPtr);
	void SetEnumHash();
};

class EQLIB_OBJECT CXMLParamManager : public CXMLDataManager
{
public:
	// virtual
	~CXMLParamManager();
	bool XMLDataCopy(CXMLData*, CXMLData*);
	CXMLData* AllocPtr(CXMLDataPtr&, int, const CXMLData*);
};

class EQLIB_OBJECT CSidlManagerBase
{
public:
/*0x000*/ void*                                  vftable;
/*0x004*/ int                                    ScreenPieceClassIndex[5];
/*0x018*/ ArrayClass_RO<CUITextureInfo*>         Textures;
/*0x028*/ ArrayClass_RO<CButtonDrawTemplate*>    ButtonDrawTemplateArray;
/*0x038*/ ArrayClass_RO<CScrollbarTemplate*>     ScrollbarTemplateArray;
/*0x048*/ ArrayClass_RO<CSliderDrawTemplate*>    SliderDrawTemplateArray;
/*0x058*/ ArrayClass_RO<CXStr>                   ScreenNameArray;
/*0x068*/ ArrayClass_RO<CXWndDrawTemplate*>      DrawTemplateArray;
/*0x078*/ CHashCXStrInt32                        DrawTemplateHash;
/*0x094*/ ArrayClass_RO<CTextureAnimation*>      AnimationArray;
/*0x0A4*/ CHashCXStrInt32                        AnimationsHash;
/*0x0C0*/ ArrayClass_RO<CTAFrameDraw*>           TAFrameArray;
/*0x0D0*/ CHashCXStrInt32                        TAFrameHash;
/*0x0EC*/ ArrayClass_RO<CScreenPieceTemplate*>   ScreenPieceArray;
/*0x0FC*/ CHashCXStrInt32                        ScreenPiecesHash;
/*0x118*/ ArrayClass_RO<void*>                   LayoutStrategyTemplateArray;            // CLayoutStrategyTemplate* todo: map this later...
/*0x128*/ CHashCXStrInt32                        LayoutStrategyTemplatesHash;
/*0x144*/ CXMLParamManager                       XMLDataMgr;
/*0x1F8*/ bool                                   bLoadError;
/*0x1FC*/ CXStr                                  ErrorString;
/*0x200*/
};

enum EStaticScreenPieceClasses
{
	StaticScreenPiece_Unknown                = -1,
	StaticScreenPiece_Header                 = 0,
	StaticScreenPiece_Frame                  = 1,
	StaticScreenPiece_Text                   = 2,
	StaticScreenPiece_Animation              = 3,
	StaticScreenPiece_TintedBlendAnimation   = 4,
}

// size 0x200 see 53ED93 in 2019 01 11 eqgame.exe
class EQLIB_OBJECT CSidlManager : public CSidlManagerBase
{
public:
	CSidlManager();
	CButtonDrawTemplate* FindButtonDrawTemplate(const CXStr& Name) const;
	CButtonDrawTemplate* FindButtonDrawTemplate(uint32_t ID) const;
	CButtonDrawTemplate GetButtonDrawTemplateFromParamButtonDrawTemplate(const CParamButtonDrawTemplate&) const;
	CGaugeDrawTemplate GetGaugeDrawTemplateFromParamGaugeDrawTemplate(const CParamGaugeDrawTemplate&) const;
	CScreenPieceTemplate* CreateScreenPieceTemplateFromParamScreenPiece(const CParamScreenPiece*) const;
	CScreenPieceTemplate* FindScreenPieceTemplate(const CXStr& Name) const;
	CScreenPieceTemplate* FindScreenPieceTemplate(const char* Name);
	CScreenPieceTemplate* FindScreenPieceTemplate(uint32_t) const;
	CScrollbarTemplate GetScrollbarTemplateFromParamScrollbarTemplate(const CParamScrollbarDrawTemplate&) const;
	CSliderDrawTemplate* FindSliderDrawTemplate(const CXStr& Name) const;
	CSliderDrawTemplate* FindSliderDrawTemplate(uint32_t) const;
	CSliderDrawTemplate GetSliderDrawTemplateFromParamSliderDrawTemplate(const CParamSliderDrawTemplate&) const;
	CSpellGemDrawTemplate GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate(const CParamSpellGemDrawTemplate&) const;
	CTAFrameDraw* FindFrameDraw(uint32_t) const;
	CTAFrameDraw CreateTAFrameDrawFromSidlFrame(const CParamFrameTemplate*) const;
	CTextureAnimation* FindAnimation(const CXStr&) const;
	CTextureAnimation* FindAnimation(uint32_t) const;
	CTextureAnimation CreateTextureAnimationFromSidlAnimation(const CParamUi2DAnimation*) const;
	CXStr GetParsingErrorMsg() const;
#if !defined(ROF2EMU) && !defined(UFEMU)
	CXWnd* CreateXWndFromTemplate(CXWnd*, CControlTemplate*, bool bSomething = 0);
#else
	CXWnd* CreateXWndFromTemplate(CXWnd*, CControlTemplate*);
#endif
	CXWnd* CreateXWnd(CXWnd* pwndParent, CControlTemplate* pControl);
	CXWnd* CreateHotButtonWnd(CXWnd* pwndParent, CControlTemplate* pControl);
	CXWnd* CreateXWndFromTemplate(CXWnd*, const CXStr&);
	CXWndDrawTemplate* FindDrawTemplate(const CXStr&) const;
	CXWndDrawTemplate* FindDrawTemplate(uint32_t) const;
	CXWndDrawTemplate CreateDrawTemplateFromParamWindowDrawTemplate(const CParamWindowDrawTemplate*) const;
	EStaticScreenPieceClasses GetScreenPieceEnum(CScreenPieceTemplate*) const;
	static CXPoint GetPointFromParamPoint(const CParamPoint&);
	static CXRect GetRectFromParamPointSize(const CParamPoint&, const CParamSize&);
	static CXSize GetSizeFromParamSize(const CParamSize&);
	static CXStr TranslateString(const CXStr&);
	static D3DCOLOR GetD3DCOLOR(const CParamRGB&);
	CUITextureInfo* FindTexture(const CXStr&) const;
	CUITextureInfo* FindTexture(uint32_t) const;
	void AddAnimationInOrder(CTextureAnimation*);
	void AddDrawTemplateInOrder(CXWndDrawTemplate*);
	void AddScreenPieceTemplateInOrder(CScreenPieceTemplate*);
	void AddTAFrameDrawInOrder(CTAFrameDraw*);
	void DeleteContents();
	void LoadSidl(const CXStr& Path, const CXStr& DefaultPath, const CXStr& Filename, const CXStr& DefaultClientPath = "UIFiles\\default\\");

	// virtual
	~CSidlManager();
};

class EQLIB_OBJECT CSkillsSelectWnd : public CSidlScreenWnd
{
public:
	CSkillsSelectWnd(CXWnd*);
	void Refresh();
	void SetTypesToDisplay(int);

	// virtual
	~CSkillsSelectWnd();
	bool IsActive();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Activate();
	void Deactivate();

	// private
	void UpdateAll();
	void UpdateSkill(int);
};

class EQLIB_OBJECT CSkillsWnd : public CSidlScreenWnd
{
public:
	CSkillsWnd(CXWnd*);
	void Activate();
	void SkillImproveOccurred(int);

	// virtual
	~CSkillsWnd();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// protected
	void UpdateAll();
	void UpdateSkill(int);
};

class EQLIB_OBJECT CSliderDrawTemplate
{
public:
	~CSliderDrawTemplate();
};

class EQLIB_OBJECT CSliderTemplate
{
public:
	CSliderTemplate(CParamSlider*);
	// virtual
	~CSliderTemplate();
};

class EQLIB_OBJECT CSliderWnd : public CSidlScreenWnd
{
public:
	CSliderWnd(CXWnd*, uint32_t, const CXRect&, CSliderTemplate*);
	CXRect GetEndCapLeftRect() const;
	CXRect GetEndCapRightRect() const;
	CXRect GetMiddleRangeRect() const;
	CXRect GetThumbRect() const;
	int GetValue() const;
	void SetNumTicks(int);
	void SetValue(int);

	// virtual
	~CSliderWnd();
	int Draw() const;
	int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	int HandleLButtonDown(const CXPoint&, uint32_t);
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int HandleLButtonUpAfterHeld(const CXPoint&, uint32_t);
	int HandleMouseMove(const CXPoint&, uint32_t);
	int OnProcessFrame();
	// private
	int DrawEndCapLeft() const;
	int DrawEndCapRight() const;
	int DrawMiddleRange() const;
	int DrawThumb() const;
	void SetThumbToOffset(int);
	void UpdateMiddleRange();
	void UpdateThumb();
};

class EQLIB_OBJECT CSocialEditWnd : public CSidlScreenWnd
{
public:
	CSocialEditWnd(CXWnd*);
	unsigned long GetSocialTextColor(int);
	void Activate(int);

	// virtual
	~CSocialEditWnd();
	int Draw() const;
	int OnProcessFrame();
	int OnSetFocus(CXWnd*);
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void ClickedAccept();
	void ClickedClear();
	void ClickedTextColorButton(int);
	void Init();
	void UpdateControlsFromSocial();
};

struct soulMarkMsg;

class EQLIB_OBJECT CSoulmarkWnd : public CSidlScreenWnd
{
public:
	CSoulmarkWnd(CXWnd*);
	void Activate(char*, char*);
	void Activate();
	void Clear();
	void FillFields();
	void Inquire(char*);
	void Praise(char*);
	void SaveMarks();
	void UpdateList();
	void UpdateSoulmarks(soulMarkMsg*);
	void Warn(char*);

	// virtual
	~CSoulmarkWnd();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// protected
	void AddMark(int, char*, char*, char*);
	void Inquire(char*, char*);
};

class EQLIB_OBJECT CSpellBookWnd : public CSidlScreenWnd
{
public:
	CSpellBookWnd(CXWnd*);
	bool StartSpellMemorization(int, int, bool);
	int GetSpellMemTicksLeft();
	int GetSpellScribeTicksLeft();
	static int GetBookSlot(int);
	void Activate();
	void AutoMemSpell(int, int);
	void DeleteSpellFromBook(int, int);
	void FinishMemorizing(int, int);
	void FinishScribing(int, int);
	void MemorizeSet(int*, int);
	void RequestSpellDeletion(int);
	void SwapSpellBookSlots(int, int);
	void TurnToPage(int);

	// virtual
	~CSpellBookWnd();
	int Draw() const;
	int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	bool CanStartMemming(int);
	void ContinueSetMem();
	void DelayedSpellMem(int, int, int);
	void DisplaySpellInfo(int);
	void EndSetMem();
	void GetSpellDeletionConfirmation(int);
	void HandleLeftClickOnSpell(int);
	void HandleRightClickOnSpell(int);
	void HandleSpellInfoDisplay(CXWnd*);
	void Init();
	void StartSpellMemorizationDrag(int, CButtonWnd*);
	void StartSpellScribe(int);
	void StopSpellBookAction();
	void UpdateSpellBookDisplay();
};

class EQLIB_OBJECT CSpellGemDrawTemplate
{
public:
	~CSpellGemDrawTemplate();
};

class EQLIB_OBJECT CSpellGemTemplate
{
public:
	CSpellGemTemplate(CParamSpellGem*);
	// virtual
	~CSpellGemTemplate();
};

class EQLIB_OBJECT CSpellGemWnd : public CSidlScreenWnd
{
public:
	CSpellGemWnd(CXWnd*, uint32_t, const CXRect&, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, int, int, unsigned long);
	void SetCheck(bool);
	void SetGemTintStage(int);
	void SetSpellGemTint(unsigned long);
	void SetSpellIconIndex(int);

	// virtual
	~CSpellGemWnd();
	int Draw() const;
	int HandleLButtonDown(const CXPoint&, uint32_t);
	int HandleLButtonHeld(const CXPoint&, uint32_t);
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int HandleLButtonUpAfterHeld(const CXPoint&, uint32_t);
	int HandleRButtonDown(const CXPoint&, uint32_t);
	int HandleRButtonHeld(const CXPoint&, uint32_t);
	int HandleRButtonUp(const CXPoint&, uint32_t);
	int HandleRButtonUpAfterHeld(const CXPoint&, uint32_t);
	int OnProcessFrame();
	void SetAttributesFromSidl(CParamScreenPiece*);

	// protected
	void Init();
};

class EQLIB_OBJECT CStaticAnimationTemplate
{
public:
	CStaticAnimationTemplate(CParamStaticAnimation*);
	// virtual
	~CStaticAnimationTemplate();
};

class EQLIB_OBJECT CStaticFrameTemplate
{
public:
	CStaticFrameTemplate(CParamStaticFrame*);
	// virtual
	~CStaticFrameTemplate();
};

class EQLIB_OBJECT CStaticHeaderTemplate
{
public:
	CStaticHeaderTemplate(CParamStaticHeader*);
	// virtual
	~CStaticHeaderTemplate();
};

class EQLIB_OBJECT CStaticScreenPieceTemplate
{
public:
	CStaticScreenPieceTemplate(CParamStaticScreenPiece*);
	// virtual
	~CStaticScreenPieceTemplate();
};

class EQLIB_OBJECT CStaticTextTemplate
{
public:
	CStaticTextTemplate(CParamStaticText*);
	const CXStr& SetText(const CXStr&);

	// virtual
	~CStaticTextTemplate();
};

class EQLIB_OBJECT CSTMLboxTemplate
{
public:
	CSTMLboxTemplate(CParamSTMLbox*);

	// virtual
	~CSTMLboxTemplate();
};

class EQLIB_OBJECT CStmlReport
{
public:
	CXStr GetReport() const;
	static CStmlReport* CreateReport(const CXStr&);

	// private
	static uint32_t LastID;
};

enum eSTMLLinkType
{
	estmlt_File,
	estmlt_Unit,
	estmlt_Building,
	estmlt_Msg,
	estmlt_Camera,
	estmlt_Report,
	estmlt_WndNotify,
	estmlt_Empty,
	estmlt_Url,
	estmlt_Player,
	estmlt_Spam,
	estmlt_Achievement,
	estmlt_Help,
	estmlt_Dlg_Response,
	estmlt_Cmd,
};

enum estmlTargetType
{
	estmltt_Self,
	estmltt_Empty,
};

struct SLinkInfo
{
	eSTMLLinkType      Type;
	uint32_t           MsgID;
	CXStr              Name;
	estmlTargetType    TargetType;
};

struct HistoryElement
{
	SLinkInfo          sLink;
	CXStr              STMLText;
};

enum eSTMLParseState
{
	sps_Body,
	sps_Head,
};

struct FontTag
{
	CTextureFont*      Face;
	COLORREF           Color;
};

struct FormattedText
{
	FontTag            Font;
	uint32_t           Style;
	int                Left;
	int                Right;
	PCXSTR             Text;
	int32_t            LinkID;
	CTextureAnimation* Texture;
	int32_t            TableID;
	int32_t            IndexStart;
};

struct STextLine
{
	ArrayClass_RO<FormattedText> TextPieces;
	int                yBottom;
	int                yTop;
	int32_t            IndexStart;
};

class SParseVariables;
class STable;

// size is 0x2b8 in sep 11 2017 test see 8DCF69
class EQLIB_OBJECT CStmlWnd //ok Look... this SHOULD inherit CXWnd but doing so... calls the constructor, and we dont want that... so... : public CXWnd
{
public:
	// we include CXW instead...
/*0x000*/ CXW
/*0x1F0*/ PCXSTR                       STMLText;
/*0x1F4*/ CircularArrayClass2<STextLine> TextLines;
/*0x21c*/ int32_t                      TextTotalHeight;
/*0x220*/ int32_t                      TextTotalWidth;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x224*/ int32_t                      Unknown0x224;                 // this value was first added in the apr 27 2017 test patch see 8EAB3B, timestamp related? heroic stuff? calendar? something... dont know - eqmule
#endif
/*0x228*/ ArrayClass2_RO<SLinkInfo>    Links;                        // size 0x1c at 0x228 for sure see 8F4487 in Sep 11 2017 test - eqmule
/*0x244*/ ArrayClass_RO<STable>        Tables;
/*0x254*/ bool                         bReparseNow;
/*0x255*/ bool                         bResized;
/*0x256*/ bool                         bAlignCenter;
/*0x258*/ int                          LineSpacingAdjust;
/*0x25c*/ int32_t                      CapturedLinkID;
/*0x260*/ int32_t                      MousedOverLinkID;
/*0x264*/ COLORREF                     BackGroundColor;
/*0x268*/ COLORREF                     TextColor;
/*0x26c*/ COLORREF                     LinkColor;
/*0x270*/ COLORREF                     VLinkColor;
/*0x274*/ COLORREF                     ALinkColor;
/*0x278*/ COLORREF                     MLinkColor;
/*0x27c*/ eSTMLParseState              CurrentParseState;
/*0x280*/ ArrayClass2_RO<HistoryElement> HistoryArray;
/*0x29c*/ int32_t                      HistoryIndex;
/*0x2a0*/ CStmlReport*                 pStmlReport;
/*0x2a4*/ int                          MaxLines;
/*0x2a8*/ int                          PlayerContextMenuIndex;
/*0x2ac*/ int                          Unknown0x2ac;
/*0x2b0*/ int                          Unknown0x2b0;
/*0x2b4*/ int                          Unknown0x2b4;
/*0x2b8*/

	CStmlWnd(CXWnd*, uint32_t, const CXRect&);
	bool CanGoBackward();
	CXSize AppendSTML(CXStr);
	CXStr GetSTMLText() const;
	CXStr GetVisibleText(CXStr, const CXRect&) const;
	static CXStr MakeStmlColorTag(unsigned long);
	static CXStr MakeWndNotificationTag(uint32_t, const CXStr&, const CXStr&);
	void ActivateLink(SLinkInfo);
	void ForceParseNow();
	void GoToBackHistoryLink();
	// void LoadPage(CXStr, enum ESTMLTargetValue, bool);
	void SetSTMLText(CXStr, bool, SLinkInfo*);
	void SetSTMLTextWithoutHistory(CXStr);

	// virtual
	~CStmlWnd();
	bool IsPointTransparent(CXPoint) const;
	CTextureAnimation* GetCursorToDisplay() const;
	int Draw() const;
	int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	int HandleLButtonDown(const CXPoint&, uint32_t);
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int HandleMouseMove(const CXPoint&, uint32_t);
	int OnHScroll(EScrollCode, int);
	int OnMove(const CXRect&);
	int OnProcessFrame();
	int OnResize(int, int);
	int OnVScroll(EScrollCode, int);
	void SetWindowText(const CXStr&);

	// protected
	bool IsLinkActive(SLinkInfo) const;
	bool ParseAmpersand(CXStr, char*) const;
	static bool CanBreakAtCharacter(unsigned short);
	static bool IsCharacterNotASpaceAndNotNULL(unsigned short);
	static bool IsCharacterNotEquals(unsigned short);
	static bool IsCharacterNotQuotes(unsigned short);
	unsigned short FastForwardPastQuotesAndGetNextTagPiece(const CXStr&, CXStr*, int*, bool);
	unsigned short FastForwardPastSpaces(const CXStr&, int*);
	unsigned short FastForwardPastSpacesAndQuotes(const CXStr&, int*);
	unsigned short FastForwardToEndOfTag(const CXStr&, CXStr*, int*, char);
	unsigned short GetNextChar(int*, const CXStr&);
	unsigned short GetNextTagPiece(const CXStr&, CXStr*, int*, bool (*)(unsigned short), bool);
	unsigned short GetThisChar(int, const CXStr&);
	void ActivateLinkFile(SLinkInfo);
	void ActivateLinkMessageId(SLinkInfo);
	void ActivateLinkReport(SLinkInfo, bool);
	void ActivateLinkWndNotify(SLinkInfo);
	void AddLinkToHistory(SLinkInfo, const CXStr&);
	void AddTextPieceToLine(SParseVariables*);
	void CalculateHSBRange(int);
	void CalculateVSBRange(int);
	void CompleteParse();
	void InitializeTempVariables(SParseVariables*, const CXRect&);
	void InitializeTextLine(SParseVariables*, int);
	void InitializeWindowVariables();
	// void ParseLinkTarget(const CXStr&, enum ESTMLTargetValue*) const;
	void ParseSTMLHead(const CXStr&);
	void ParseSTMLTable(const CXStr&, int*, const CXStr&, SParseVariables*);
	void ParseSTMLTableAttributes(const CXStr&, STable*);
	// void ParseTagAlign(const CXStr&, enum ESTMLAlign*) const;
	void ParseTagColor(const CXStr&, unsigned long*) const;
	void ParseTagFace(const CXStr&, const CTextureFont**) const;
	void ResetTempVariablesForNewLine(SParseVariables*);
	void StripFirstSTMLLines(int);
	void UpdateHistoryString(int32_t, const CXStr&);
};

class EQLIB_OBJECT CStoryWnd : public CSidlScreenWnd
{
public:
	CStoryWnd(CXWnd*);
	bool HasNew();
	bool ShowAuto();
	void Activate();
	void SaveIni();

	// virtual
	~CStoryWnd();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
	void LoadIniInfo();

	// protected
	void SelectIndex(int);
	void SelectOldestNew();

	// private
	void Init();
};

class EQLIB_OBJECT CTabBoxTemplate
{
public:
	CTabBoxTemplate(CParamTabBox*);

	// virtual
	~CTabBoxTemplate();
};

class EQLIB_OBJECT CTabWnd : public CSidlScreenWnd
{
public:
	CTabWnd(CXWnd* pParent, UINT uId, RECT* rect, CTabBoxTemplate* pTabContents);
	CPageWnd* GetCurrentPage() const;
	CXRect GetPageClientRect() const;
	CXRect GetPageInnerRect() const;
	CXRect GetTabInnerRect(int) const;
	CXRect GetTabRect(int) const;
	int GetCurrentTabIndex() const;
	int GetNumTabs() const;
	void InsertPage(CPageWnd*, int);
	void SetPage(CPageWnd*, bool);
#if !defined(ROF2EMU) && !defined(UFEMU)
	void SetPage(int index, bool bNotifyParent, bool bBringToTop = true, bool bSomething = true);
#else
	void SetPage(int index, bool bNotifyParent);
#endif
	void SetPageRect(const CXRect&);
	void UpdatePage();

	// virtual
	~CTabWnd();
	int Draw() const;
	int DrawTooltip(const CXWnd*);
	int HandleLButtonDown(const CXPoint&, uint32_t);
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int OnResize(int, int);
	int OnShow();

	// private
	bool IndexInBounds(int) const;
	CPageWnd* GetPageFromTabIndex(int) const;
	CPageWnd* GetPageFromTabPoint(CXPoint) const;
	int DrawCurrentPage() const;
	int DrawTab(int) const;
};

class EQLIB_OBJECT CTAFrameDraw
{
public:
	~CTAFrameDraw();
	CTAFrameDraw(const CTAFrameDraw&);
	CTAFrameDraw(CXStr);
	bool IsHorizontal() const;
	bool IsVertical() const;
	CTAFrameDraw& operator=(const CTAFrameDraw&);
	CTextureAnimation* GetAnimation(int) const;
	CXRect GetHitTestRect(const CXRect&, int) const;
	CXRect GetInnerRect(const CXRect&) const;
	CXRect GetPieceRect(const CXRect&, int) const;
	CXSize GetFrameSize() const;
	CXStr GetName() const;
	int Draw(const CXRect&, const CXRect&) const;
	int Draw(const CXRect&, const CXRect&, int) const;
	int GetExtent() const;
	int GetMinLength() const;
	void Set(CTextureAnimation** const);
};

class EQLIB_OBJECT CTargetManager
{
public:
	static CTargetManager* Get();
	void Update();
};

class EQLIB_OBJECT CTargetRing
{
public:
	int Cast(CVector3* pos);

/*0x00*/ DWORD         Gem;           // the gem the spell below is memmed in... 0-11
/*0x04*/ PSPELL        thespell;
/*0x08*/ ItemGlobalIndex ItemLoc;
/*0x14*/ ItemSpellTypes SpellType;
/*0x18*/ float         SquaredRange;
/*0x1c*/ bool          bCursorVisible;
/*0x20*/
};

class EQLIB_OBJECT CTargetWnd : public CSidlScreenWnd
{
public:
	CTargetWnd(CXWnd*);
	void Activate();

	// virtual
	~CTargetWnd();
	CXStr* GetBuffCaster(int SpellID);
	int OnProcessFrame();
	void Deactivate();

	// private
	void Init();
	void RefreshTargetBuffs(PBYTE buffer);
	void HandleBuffRemoveRequest(CXWnd* pWnd);
};

class EQLIB_OBJECT CTaskWnd : public CSidlScreenWnd
{
public:
	CTaskWnd(CXWnd*);
	int UpdateTaskTimers(unsigned long fasttime);

	// virtual
	~CTaskWnd();
};

enum TaskType
{
	TT_Unknown = -1,
	TT_None = 0,
	TT_Deliver,
	TT_Kill,
	TT_Loot,
	TT_Hail,
	TT_Explore,
	TT_Tradeskill,
	TT_Fishing,
	TT_Foraging,
	TT_Cast,
	TT_UseSkill,
	TT_DZSwitch,
	TT_DestroyObject,
	TT_Collect,
	TT_Dialogue,
	TT_TotalCount
};

enum TaskGroupType
{
	TGT_Solo,
	TGT_Group,
	TGT_Raid
};

struct CTaskElement
{
/*0x000*/ TaskType           Type;
/*0x004*/ TaskGroupType      GroupType;
/*0x008*/ char               TargetName[0x40];
/*0x048*/ char               ZoneID[0x40];
/*0x088*/ char               TargetZoneID[0x40];
/*0x0c8*/ int                RequiredCount;
/*0x0cc*/ bool               bOptional;
/*0x0d0*/ int                ElementGroup;
/*0x0d4*/ int                DZSwitchID;
/*0x0d8*/ char               ElementDescriptionOverride[0x80];
/*0x158*/ CXStr              ItemNameList;
/*0x15c*/ CXStr              SkillIDList;
/*0x160*/ CXStr              SpellIDList;
/*0x164*/ CXStr              TaskTitle;
/*0x168*/
};

struct CTaskEntry
{
/*0x0000*/ int               TaskID;
/*0x0004*/ float             RewardAdjustment;
/*0x0008*/ char              TaskTitle[0x40];
/*0x0048*/ int               DurationSeconds;
/*0x004C*/ int               DurCode;
/*0x0050*/ char              StartText[0xFa0];
/*0x0FF0*/ bool              bShowReward;
/*0x0FF4*/ int               RewardCash;
/*0x0FF8*/ int               RewardExp;
/*0x0FFC*/ int               RewardPoints;
/*0x1000*/ int               RewardFactionID;
/*0x1004*/ int               RewardFactionAmount;
/*0x1008*/ CXStr             RewardItemTag;aletate
/*0x100C*/ CTaskElement      Elements[0x14];
/*0x2C2C*/ int               TaskSystem;
/*0x2C30*/ int               PointType;
/*0x2C34*/ bool              StartTextCompiled;
/*0x0000*/ char              RawStartText[0xFa0];
/*0x0000*/ bool              bElementsReceived;
/*0x0000*/ __time32_t        TimeCompleted;
/*0x3BDC*/ ArrayClass_RO<MonsterMissionTemplate> MonsterTemplates;
/*0x3BEC*/ bool              bTemplateSelectionLocked;
/*0x3BED*/ bool              bHasRewardSet;
/*0x3BF0*/
};

enum SharedTaskPlayerRole
{ 
	STPR_None,
	STPR_Leader
};

struct SharedTaskClientPlayerInfo
{
	char                               Name[0x40];
	int                                TemplateID;
	SharedTaskPlayerRole               m_role;
	SharedTaskClientPlayerInfo*        pNext;
};

class EQLIB_OBJECT CTaskManager// : public PopDialogHandler /*0x000000*/ 
{
public:
/*0x000000*/ void*                     vfTable;
/*0x000004*/ CTaskEntry                TaskEntries[1];
/*0x003BF4*/ CTaskEntry                QuestEntries[0x1d];
/*0x070624*/ CTaskEntry                SharedTaskEntries[1];
/*0x074214*/ CTaskEntry                QuestHistoryEntries[0x32];
/*0x12F6F4*/ int                       AddPlayerID;
/*0x12F6F8*/ bool                      bAddPlayerIsSwap;
/*0x12F6FC*/ char                      AddPlayerSwapeeName[0x40];
/*0x12F73C*/ SharedTaskClientPlayerInfo* pFirstMember;
/*0x12F740*/
	CTaskManager(CXWnd*);
	// virtual
	~CTaskManager();
	CTaskEntry* GetEntry(int Index, int System, bool bCheckEmpty = true);
};

class EQLIB_OBJECT CTextEntryWnd : public CEditBaseWnd
{
public:
	void Open(CXWnd* pwnd, int EditMode, char*Prompt, int MinLength, int MaxLength, const char* InitialText);
	CTextEntryWnd(CXWnd*);
	CXStr GetEntryText();
	void Activate(CXWnd*, int, char*, int, int, char*);
	void Callback(bool);

	// virtual
	~CTextEntryWnd();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void UpdateButtons();

/*0x148*/// DWORD Unknown0x148;
/*0x14C*/// DWORD Unknown0x14c;
/*0x150*/// PCXSTR Data;
/*0x154*/// DWORD Unknown0x154;
/*0x158*/// CSidlScreenWnd*Entry;
/*0x15c*/// CSidlScreenWnd*Prompt;
/*0x160*/// CSidlScreenWnd*OK;
/*0x164*/// CSidlScreenWnd*Cancel;
};

class EQLIB_OBJECT CUITexturePiece
{
public:
	~CUITexturePiece();
	CUITexturePiece(const CUITexturePiece&);
	CUITexturePiece(CUITextureInfo, class CXRect);
	CUITexturePiece();
	CUITexturePiece& operator=(const CUITexturePiece&);
	int Draw(const CXRect&, const CXRect&, const CXRect&, unsigned long, unsigned long) const;
	int Draw(const CXRect&, const CXRect&, unsigned long, unsigned long) const;

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

class EQLIB_OBJECT CTextureAnimation
{
public:
	CTextureAnimation(CXStr);
	CTextureAnimation();
	CTextureAnimation& operator=(const CTextureAnimation&);
	CXPoint GetHotspot() const;
	CXStr GetName() const;
	int AddBlankFrame(uint32_t, CXPoint);
	int AddFrame(CUITexturePiece, uint32_t, CXPoint);
	int AddFrame(const CUITextureInfo*, const CXRect&, uint32_t, CXPoint);
	int Draw(const CXPoint&, const CXRect&, unsigned long, unsigned long) const;
	int Draw(const CXRect&, const CXRect&, unsigned long, unsigned long) const;
	int GetCurFrame() const;
	int Preload();
	void Reset();
	void SetCurCell(int);
	void SetCurFrame(int);

	// virtual
	~CTextureAnimation();

	// protected
	static uint32_t MaxID;

/*0x00*/ void*         vfTable;
/*0x04*/ CXStr         Name;
/*0x08*/ ArrayClass_RO<STextureAnimationFrame> Frames;
	// and more ...
};

class EQLIB_OBJECT CTextureFont
{
public:
	CXStr GetName() const;
	int DrawWrappedText(const CXStr&, const CXRect&, const CXRect&, unsigned long, unsigned short, int) const;
	int DrawWrappedText(const CXStr& Str, int x, int y, int Width, const CXRect& BoundRect, COLORREF Color, uint16_t Flags = 0, int StartX = 0) const;
	int GetHeight() const;
	int GetKerning(unsigned short, unsigned short) const;
#if !defined(ROF2EMU) && !defined(UFEMU)
	int GetTextExtent(CXStr*);
#else
	int GetTextExtent();
#endif
	int GetWidth(unsigned short) const;

	// virtual
	~CTextureFont();

/*0x00*/ void* vftable;
/*0x00*/ DWORD FontStyle;
};

class EQLIB_OBJECT CTimeLeftWnd : public CSidlScreenWnd
{
public:
	CTimeLeftWnd(long);
	void Activate();

	// virtual
	~CTimeLeftWnd();
	int Draw() const;
	int OnProcessFrame();
	void Deactivate();
};

class EQLIB_OBJECT CTipWnd : public CSidlScreenWnd
{
public:
	CTipWnd(CXWnd*, int);
	bool Activate(int, bool);
	void InitializeTipSettings();
	void UpdateButtons();

	// virtual
	~CTipWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// protected
	bool IsRecentTOTD(int);
	int SelectRandomTip();
	void AddContextTip(int);
	void LoadINISettings();
	void SetTOTD(int);
	void ShowHistoryTip(int);

	// private
	void CleanDayTips();
	void LoadDayTips();
};

class EQLIB_OBJECT CTokenXML
{
public:
	~CTokenXML();
};

struct TrackingHit;

class EQLIB_OBJECT CTrackingWnd : public CSidlScreenWnd
{
public:
	CTrackingWnd(CXWnd*);
	void Activate();
	void DoTrackFilter(bool);
	void DoTrackSort(bool);
	void RemovePlayerFromTracking(EQPlayer*);
	void SetTrackingList(TrackingHit*, int);
	// virtual
	~CTrackingWnd();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
	// private
	int GetListIdByData(unsigned int);
	unsigned long GetTrackColor(int);
	void GenerateTrackingList();
	void Init();
	void NotifyServerOfTrackingTarget(int);
	void RemoveFromListWndByData(unsigned int);
	void RemovePlayerFromTracking(int);
	void UpdateTrackingControls();
	void UpdateTrackingList(bool);
};

class EQLIB_OBJECT CTradeWnd : public CSidlScreenWnd, public WndEventHandler2
{
public:
	CTradeWnd(CXWnd*);
	bool IsMyTradeSlot(int, bool*);
	void Activate(EQPlayer*, bool);
	void AddContainerToHisTradeArray(EQ_Container*);
	void AddEquipmentToHisTradeArray(EQ_Equipment*);
	void AddNoteToHisTradeArray(EQ_Note*);
	void ClickedCancelButton();
	void ClickedMoneyButton(int);
	void ClickedTradeButton();
	void CompleteTrade();
	void DeleteItemFromHisTradeArray(int);
	void DropItemIntoTrade();
	void SetHisMoney(int, long);
	void SetHisReadyTrade(bool);
	void SetMyReadyTrade(bool);
	void TradeItemChanged(int, int);

	// virtual
	~CTradeWnd();
	int OnProcessFrame();
	int PostDraw() const;
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void Init();
	void UpdateTradeDisplay();

	UINT               NextRefreshTime;
	bool               bInventoryWasOpen;
	CButtonWnd*        HisMoneyButton[4];
	CButtonWnd*        MyMoneyButton[4];
	CButtonWnd*        TradeButton;
	CButtonWnd*        CancelButton;
	CLabel*            HisNameLabel;
	CLabel*            MyNameLabel;
	CInvSlotWnd*       pInvSlotWnd[16];
	long               HisMoney[4];
	long               MyMoney[4];
	ItemBaseContainer  TradeItems;     // 16 items
	bool               bHisReadyTrade;
	bool               bMyReadyTrade;
	bool               bIsTrading;
};

class EQLIB_OBJECT CTrainWnd : public CSidlScreenWnd
{
public:
	CTrainWnd(CXWnd*);
	void SetGMData(int*, unsigned char*, float);
	void SkillChanged(int);

	// virtual
	~CTrainWnd();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// protected
	char* SkillName(int);
	int SkillValue(int);
	void Activate();
	void SortNames(int);
	void SortSkill(int);
	void SwapSkill(int, int);
	void Train();
	void UpdateAll(bool);
	void UpdateRight();
	void UpdateSkill(int);
};

class EQLIB_OBJECT CTreeView : public CListWnd
{
public:
	CTreeView(CXWnd*, uint32_t, CXRect, int);
	// virtual
	~CTreeView();
};

class EQLIB_OBJECT CVideoModesWnd : public CSidlScreenWnd
{
public:
	CVideoModesWnd(CXWnd*);
	void Activate();
	void RestoreOldMode();
	void Update();

	// virtual
	~CVideoModesWnd();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void Init();
	void UpdateSelection(unsigned int);
};

// work in progress
class EQLIB_OBJECT CNotification
{
public:
	int Type;
};
class IObserver;

class EQLIB_OBJECT CObservable
{
public:
	void NotifyObservers(CNotification* Notification = 0)
	{
	}

private:
	std::list<IObserver*> ObserverList;
};

class EQLIB_OBJECT IObserver
{
public:
	// virtual void IObserver::Notify(CObservable* Src, const CNotification* const Notification) = 0;
};

// Bad name. This is a libMozilla::Window.
class EQLIB_OBJECT Window
{
public:
	float getProgress(bool& bIsLoading);
	const wchar_t* getStatus() const;
	const char* getURI() const;
};

class EQLIB_OBJECT CHtmlComponentWnd //: public CXWnd, public mozilla::ICallback, public CObservable
{
public:
	CXW;
};

class EQLIB_OBJECT CHtmlWnd : public CSidlScreenWnd, public TListNode<CHtmlWnd>
{
public:
	void SetClientCallbacks(void* cb);
	void AddObserver(IObserver* Observer);
	void RemoveObserver(IObserver* Observer);

	CHtmlComponentWnd* pHtmlComponentMain;
	CButtonWnd*        pBackBtn;
	CButtonWnd*        pForwardBtn;
	CGaugeWnd*         pProgressGauge;
	CLabelWnd*         pStatusLabel;
	CXStr              WindowID;
};

class EQLIB_OBJECT CWebManager
{
public:
	CHtmlWnd* CreateHtmlWnd(const char* Url, const char* IDString, const char* PostString = nullptr,
		bool bBypasFilter = false, const char* OverrideTitle = nullptr);
};

class EQLIB_OBJECT CXFileXML
{
public:
	~CXFileXML();
	bool Load(char*);
};

class EQLIB_OBJECT CXMLData
{
public:
	CXMLData();
	CXMLData& operator=(const CXMLData&);

	// virtual
	~CXMLData();
	bool ReadFromXMLSOM(CXMLSOMDocument&);
	bool WriteToXMLSOM(CXMLSOMDocument&);
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);

/*0x00*/ void*         pvfTable;
/*0x04*/ DWORD         Unknown0x04;             // always 8
/*0x08*/ UIType        Type;
/*0x0C*/ DWORD         Unknown0x0C;             // no idea yet, some number but not unique
/*0x10*/ DWORD         Unknown0x10;             // always -1
/*0x14*/ CXStr         TypeName;                // "Screen" (control type)
/*0x18*/ CXStr         Name;                    // "ChatWindow"  control name (used only for Screen)
/*0x1C*/ DWORD         Unknown0x1C;             // always null
/*0x20*/ CXStr         ScreenID;                // ScreenID (used only within Screen)
};

class EQLIB_OBJECT CXMLDataClass
{
public:
	~CXMLDataClass();
	CXMLDataClass();
	int GetNumLeaf();
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&, CXMLDataManager&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CXMLDataPtr
{
public:
	CXMLDataPtr();
	CXMLDataPtr& operator=(const CXMLDataPtr&);
	void SetNewPtr(CXMLData*);

	// virtual
	~CXMLDataPtr();

	// protected
	CXMLData* AllocPtr(CXMLDataPtr&, int, const CXMLData*);
	void Free();
};

class EQLIB_OBJECT CXMLEnumInfo
{
public:
	~CXMLEnumInfo();
	CXMLEnumInfo();
	int GetStreamSize();
	void ReadFromStream(CMemoryStream&);
	void WriteToStream(CMemoryStream&);
};

class EQLIB_OBJECT CXMLSOMAttribute
{
public:
	~CXMLSOMAttribute();
	CXMLSOMAttribute();
	CXMLSOMAttribute& operator=(const CXMLSOMAttribute&);
};

class EQLIB_OBJECT CXMLSOMAttributeType
{
public:
	~CXMLSOMAttributeType();
	CXMLSOMAttributeType();
	CXMLSOMAttributeType& operator=(const CXMLSOMAttributeType&);
};

class EQLIB_OBJECT CXMLSOMCursor
{
public:
	~CXMLSOMCursor();
	CXMLSOMCursor();
	CXMLSOMCursor& operator=(const CXMLSOMCursor&);
};

class EQLIB_OBJECT CXMLSOMCursorSave
{
public:
	~CXMLSOMCursorSave();
};

class EQLIB_OBJECT CXMLSOMCursorSaveFast
{
public:
	~CXMLSOMCursorSaveFast();
};

class EQLIB_OBJECT CXMLSOMCursorTraverseChildren
{
public:
	~CXMLSOMCursorTraverseChildren();
	CXMLSOMCursor& Cursor();
};

class EQLIB_OBJECT CXMLSOMDocument
{
public:
	bool FieldParseItemOfClass(CXStr, CXStr, uint32_t&);
	bool GetValueObjectId(CXStr, CXStr, uint32_t&);
	bool SetValueObjectId(CXStr, CXStr, uint32_t);

	// virtual
	~CXMLSOMDocument();
};

class EQLIB_OBJECT CXMLSOMDocumentBase
{
public:
	bool CursorFieldFind(CXStr);
	bool CursorFind(CXStr);
	bool CursorNextInOrder();
	bool CursorNextSibling();
	bool CursorPop();
	bool CursorPush();
	bool FieldParseClassItem(CXStr, CXStr&, CXStr&);
	bool FieldParseItemOfClass(CXStr, CXStr, int32_t &, int32_t &);
	bool GetAttrValueInt(CXStr, int32_t &);
	bool GetAttrValueStr(CXStr, CXStr&);
	bool GetValue(CXStr, int32_t &);
	bool GetValue(CXStr, bool &);
	bool GetValue(CXStr, CXStr&);
	bool SetValue(CXStr, int32_t);
	bool SetValue(CXStr, bool);
	bool SetValue(CXStr, CXStr);
	bool ValidateData();
	bool ValidateSchema();
	bool XMLMerge(CXMLSOMDocumentBase&);
	bool XMLRead(CXStr*, CXStr*, CXStr*);
	CXMLSOMCursor& Cursor();
	CXMLSOMCursor& CursorParent();
	CXStr GetAttrValueStr(CXStr);
	CXStr GetErrorMsg() const;
	int XMLReadNoValidate(CXStr, CXStr, CXStr);
	void CursorInit();
	void CursorNewChild();
	void CursorNewSibling();
	void CursorSetPtr(CXMLSOMNodePtr);
	void Init();
	void SetErrorMsg(CXStr);
	void SetErrorMsgAtCursor(CXStr);
	void SetErrorMsgAtLine(CXStr, int, CXStr);

	// virtual
	~CXMLSOMDocumentBase();

	// protected
	bool ValidateDataElements(CXMLSOMElementType&);
	bool ValidateSchemaCategories();
	bool ValidateSchemaDefinition();
	bool ValidateSchemaElementType();
	bool ValidateSchemaSimpleType();
	bool ValidateSchemaSimpleTypeNode(CXMLSOMSimpleType&);
	bool ValidateSchemaTypeRefs();
	bool XMLProcessComposite(CXStr, CXStr);
};

class EQLIB_OBJECT CXMLSOMElement
{
public:
	~CXMLSOMElement();
	CXMLSOMElement();
	CXMLSOMElement& operator=(const CXMLSOMElement&);
};

class EQLIB_OBJECT CXMLSOMElementType
{
public:
	~CXMLSOMElementType();
	CXMLSOMElementType();
	int GetItemIdx(CXStr);
};

class EQLIB_OBJECT CXMLSOMNode
{
public:
	static void* operator new(unsigned int);
	static void FreeAllAllocs();
	static void operator delete(void*);

	// protected
	static char** pAllAlloc;
	static CXMLSOMNode* pFreeHead;

	// private
	~CXMLSOMNode();
	CXMLSOMNode();
};

class EQLIB_OBJECT CXMLSOMNodePtr
{
public:
	~CXMLSOMNodePtr();
	CXMLSOMNodePtr();
	CXMLSOMNode* operator->() const;
	CXMLSOMNodePtr& operator=(const CXMLSOMNodePtr&);

	// protected
	void Assure() const;
};

class EQLIB_OBJECT CXMLSOMParser
{
public:
	~CXMLSOMParser();
	bool ParseFile(CXStr);

	// protected
	bool ParseDocument();
	bool ParseEndTag(CXStr);
	bool ParseNameSpaceToken(CXStr&);
	bool ParseNode();
	bool ParseNodeList();
	bool ParseProcess();
	bool ParseStartTag(bool &);
};

class EQLIB_OBJECT CXMLSOMSchema
{
public:
	~CXMLSOMSchema();
	CXMLSOMSchema();
	bool AddItem(CXStr, CXStr);
	bool FindElementType(CXStr);
	bool FindItem(CXStr, CXStr);
	bool FindSimpleType(CXStr);
	bool IsDerivedFrom(CXStr, CXStr);
	int GetElementTypeIdx(CXStr);
};

class EQLIB_OBJECT CXMLSOMSimpleType
{
public:
	~CXMLSOMSimpleType();
	CXMLSOMSimpleType();
};

class CXPoint
{
public:
	CXPoint operator=(CXPoint);

	int X, Y;
};

class EQLIB_OBJECT CXRect
{
public:
	CXRect(int nLeft, int nTop, int nRight, int nBottom)
	{
		left   = nLeft;
		top    = nTop;
		right  = nRight;
		bottom = nBottom;
	}

	CXRect() {};
	CXPoint CenterPoint() const;
	CXRect& operator=(const CXRect&);
	CXRect operator&(CXRect) const;
	CXRect operator|(CXRect) const;
	int Width() const;
	void Move(CXPoint);
	void Normalize();

	int left;
	int top;
	int right;
	int bottom;
};

class EQLIB_OBJECT CXStrSingleton
{
public:
	static int active;
};

class EQLIB_OBJECT CXWndDrawTemplate
{
public:
	~CXWndDrawTemplate();
	CXWndDrawTemplate(const CXWndDrawTemplate&);
	CXWndDrawTemplate();
	CXWndDrawTemplate& operator=(const CXWndDrawTemplate&);
};

class EQLIB_OBJECT CXWndManager
{
public:
	CXWndManager(CSidlManager*);
	bool IsAllValid();
	bool IsWindowActive(const CXWnd*) const;
	bool IsWindowMovingOrSizing(CXWnd*) const;
	bool IsWindowPieceDown(const CXWnd*, int) const;
	bool OkayToSendMouseMessage(CXWnd*) const;
	const CTextureAnimation* GetCursorToDisplay() const;
	CTextureFont* GetFont(CXStr);
	CXWnd* FindWnd(CXPoint, int*) const;
	CXWnd* GetFirstChildWnd(CXWnd const*) const;
	CXWnd* GetFocusWnd() const;
	CXWnd* GetNextSib(CXWnd const*) const;
	CXWnd* SetFocusWnd(CXWnd*);
	int ActivateWnd(CXWnd*);
	int AddFont(CTextureFont*);
	int AddWnd(CXWnd*);
	int DrawCursor() const;
	int DrawWindows() const;
	int HandleKeyboardMsg(uint32_t, bool);
	int HandleLButtonDown(const CXPoint&);
	int HandleLButtonHeld(const CXPoint&);
	int HandleLButtonUp(const CXPoint&);
	int HandleLButtonUpAfterHeld(const CXPoint&);
	int HandleMouseMove(const CXPoint&);
	int HandleRButtonDown(const CXPoint&);
	int HandleRButtonHeld(const CXPoint&);
	int HandleRButtonUp(const CXPoint&);
	int HandleRButtonUpAfterHeld(const CXPoint&);
	int HandleWheelMove(int);
	int NotifyAllWindows(CXWnd*, uint32_t, void*);
	int OnWindowCloseBox(CXWnd*);
	int OnWindowMinimizeBox(CXWnd*);
	int OnWindowTileBox(CXWnd*);
	int ProcessFrame();
	int RemoveWnd(CXWnd*);
	static CTextureAnimation sm_curDefault;
	static CTextureAnimation sm_curDrag;
	static CTextureAnimation sm_curResizeEW;
	static CTextureAnimation sm_curResizeNESW;
	static CTextureAnimation sm_curResizeNS;
	static CTextureAnimation sm_curResizeNWSE;
	uint32_t GetDisplayWidth() const;
	uint32_t GetGlobalFadeDuration() const;
	uint32_t GetKeyboardFlags() const;
	unsigned char GetGlobalAlpha() const;
	unsigned char GetGlobalFadeToAlpha() const;
	unsigned long GetGlobalFadeDelay() const;
	void BringWndToTop(CXWnd*, bool);
	void CheckInvalidateLastFoundWnd();
	void CleanupWindows();
	void DestroyAllWindows();
	void FlushKeyboardFlags();
	void OnWindowShown(CXWnd*, bool);
	void SetGlobalAlpha(unsigned char);
	void SetGlobalFadeDelay(unsigned long);
	void SetGlobalFadeDuration(uint32_t);
	void SetGlobalFadeToAlpha(unsigned char);
	void SetSystemFont(CTextureFont*);
	void UpdateChildAndSiblingInfo();

	// virtual
	~CXWndManager();
	CTextureFont* GetFont(int FontIndex) const
	{
		if (PCXWNDMGR wndmgr = (PCXWNDMGR)this)
		{
			if (wndmgr->FontsArray.Count >= FontIndex)
			{
				return (CTextureFont*)wndmgr->FontsArray[FontIndex];
			}
		}
		return nullptr;
	}

	int DestroyWnd(CXWnd*wnd);
};

class EQLIB_OBJECT EmitterManager
{
public:
	~EmitterManager();
	EmitterManager(SoundManager*);
	float GetEffectsLevel();
	float GetVolumeLevel();
	void Add(SoundEmitter*);
	void GetListenerLocation(float*, float*, float*, float*);
	void GiveTime();
	void Remove(SoundEmitter*);
	void SetEffectsLevel(float);
	void SetVolumeLevel(float);
};

struct SlotData
{
	LONG     Slot;
	DWORD    Value;
};

class EQLIB_OBJECT EQ_Affect
{
public:
	void Reset();
	int GetAffectData(int) const;

/*0x00*/ BYTE          Type;
/*0x01*/ BYTE          CasterLevel;
/*0x02*/ BYTE          ChargesRemaining;
/*0x03*/ BYTE          Activatable;
/*0x04*/ float         BaseDmgMod;
/*0x08*/ int           ID;
/*0x0c*/ int           DurationTick;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x10*/ int           MaxDuration;
/*0x14*/ int           Duration3;
/*0x18*/ EqGuid        CasterGuid;
#else
/*0x10*/ int           CasterID;
#endif
/*0x20*/ int           HitCounter;
/*0x24*/ float         HitLocationY;
/*0x28*/ float         HitLocationX;
/*0x2c*/ float         HitLocationZ;
/*0x30*/ UINT          Flags;                    // twincast
/*0x34*/ SlotData      Data[NUM_SLOTDATA];
/*0x64*/ DWORD         Unknown0x64;
/*0x68*/
};

class EQLIB_OBJECT EQ_AltAbility
{
public:
	EQ_AltAbility(int);
};

class CEQItemLocation;

// This is also CharacterZoneClient
class EQLIB_OBJECT EQ_Character1
{
public:
	int GetEnduranceRegen(bool bIncItemsAndBuffs, bool bCombat);
	int GetHPRegen(bool bIncItemsAndBuffs, bool*bIsBleeding/*no you shouldnt set this, its an OUT value.*/, bool bCombat);
	int GetManaRegen(bool bIncItemsAndBuffs, bool bCombat);
	int Cur_HP(int Spawntype/*PC = 0 NPC=1 and so on*/, bool bCapAtMax=true);
	int Max_Endurance(bool bCapAtMax=true);
	int Max_HP(int SpawnType, bool bCapAtMax=true); 
	int Max_Mana(bool bCapAtMax=true);
	const int GetCastingTimeModifier(const EQ_Spell* pSpell);//used to get aa modifiers
	const int GetFocusCastingTimeModifier(const EQ_Spell*pSpell, VePointer<CONTENTS>&pItemOut, bool bEvalOnly = false);
	// int const GetFocusCastingTimeModifier(class EQ_Spell const*, class EQ_Equipment**, int);
	unsigned char CastSpell(unsigned char gemid, int spellid, EQ_Item**ppItem, CEQItemLocation* ppitemloc, ItemSpellTypes slot, unsigned char spell_loc, int arg7, int arg8, int arg9, bool arg10); 
	void SetEffectId(unsigned char, unsigned int);
	void StopSpellCast(unsigned char);
	void StopSpellCast(unsigned char, int);
	void StunMe(unsigned int, bool, bool, bool);
	void UnStunMe();
	#if defined(ROF2EMU) || defined(UFEMU)
	void UseSkill(unsigned char skill, EQPlayer*Target);
	#else
	void UseSkill(unsigned char skill, EQPlayer*Target, bool bAuto = false);
	#endif
	const int GetFocusRangeModifier(const EQ_Spell*pSpell, VePointer<CONTENTS>&pItemOut);
	int IsExpansionFlag(int);
	int TotalEffect(int spaID, bool bIncludeItems = true, int subindex = 0, bool bIncludeAA = true, bool bincludeBuffs = true);
	int GetAdjustedSkill(int);
	int GetBaseSkill(int);
	bool CanUseItem(PCONTENTS*pItem, bool bUseRequiredLvl, bool bOutput);
};

class HateListEntry;

// This is CharacterZoneClient now
class EQLIB_OBJECT EQ_Character
{
public:
	~EQ_Character();
	EQ_Character();
	bool DoesSpellMatchFocusFilters(EQ_Spell const*, EQ_Spell const*);
	bool IsSpellTooPowerfull(EQ_Spell*, EQ_Character*);
	bool CanUseMemorizedSpellSlot(int gem);
	bool IsValidAffect(int);
	char* Class(int);
	char* KunarkClass(int, int, int, bool);
	char* Race(int);
	EQ_Affect& GetEffect(int);
	EQ_Affect* GetPCSpellAffect(int theaffect, int*slotnum, int*spaslot = NULL) const;
	EQ_Equipment* GetFocusItem(EQ_Spell const*, int);
	EQ_Spell* GetFocusEffect(EQ_Spell const*, int);
	EQPlayer* FindClosest(int, int, int, int, int);
	EQPlayer* GetMyPetPlayer();
	float encum_factor();
	int ac(bool);
	int Agi();
	int AntiTwinkAdj(EQ_Equipment*, int, int);
	int ApplyDamage(int, EQMissileHitinfo*, bool, HateListEntry*, bool);
	int ApplyFatigue(int);
	int AutoEat(unsigned char);
	int BaneDamage(EQ_Equipment*);
	int BardCastBard(EQ_Spell const*, int) const;
	int basesave_cold();
	int basesave_disease();
	int basesave_fire();
	int basesave_magic();
	int basesave_poison();
	int CalculateBardSongMod(int);
	int CapStat(int, int);
	int Cha();
	int CheckFoodAndWater();
	int compute_defense();
	int compute_tohit(unsigned char);
	int cur_encumbrance();
	int Cur_Mana(bool bCapAtMax = true);
	int defense_agility_bonus();
	int Dex();
	int ElementResistDmg(EQ_Equipment*, int);
	int eqspa_change_form(EQ_Spell*, int, int, EQ_Affect*);
	int eqspa_hp(unsigned int, EQ_Affect*, int, EQ_Spell*);
	int GetBardInstrumentMod(int);
	int GetClassACBonus(int);
	int GetFirstEffectSlot(bool);
	int GetHPFromStamina(int);
	int GetIndexSkillMinDamageMod(int);
	int GetLastEffectSlot(bool);
	int GetOpenEffectSlot(bool, int);
	int HasInnateSkill(unsigned char, int);
	int HasSkill(unsigned char);
	int HasSpell(int);
	int IHaveSkill(unsigned char);
	int InSpecialBindSpot(EQPlayer*);
	int Int();
	int IsMage();
	int IsSpecialBazaarSpot(EQPlayer*);
	int IsSpellcaster();
	int ItemSpellAffects(int);
	int max_encumbrance();
	int NoBashMe(int);
	int NoMezMe(int, EQPlayer*, EQ_Spell*);
	int offense(unsigned char);
	int ProcessAffects();
	int save_bash(int);
	int save_cold();
	int save_disease();
	int save_fire();
	int save_magic();
	int save_poison();
	int SetLocalVar(char*, int);
	int Skill(int);
	int SpellDuration(EQ_Spell const*, unsigned char, unsigned char);
	int Sta();
	int Str();
	int TakeFallDamage(float);
	int TotalSpellAffects(unsigned char, bool, int*);
	int Wis();
	int const GetFocusConserveRegChance(const EQ_Spell*, EQ_Equipment**);
	long TotalOnPerson();
	static int normal_to_special(int);
	unsigned char BarbarianCanWorship(unsigned char, unsigned char);
	unsigned char BaseAttr(int, unsigned char);
	unsigned char CanDoubleAttack(EQPlayer*, unsigned char);
	unsigned char CanIBreathe();
	unsigned char CanISeeInvis();
	unsigned char CanMedOnHorse();
	unsigned char CanSecondaryAttack(EQPlayer*);
	unsigned char CanWorship(int, int, unsigned char);
	unsigned char CastingRequirementsMet(int);
	unsigned char CheckClass(int, int);
	unsigned char CityCanStart(int, int, int, int);
	unsigned char ClassMin(int, int, unsigned char);
	unsigned char DarkElfCanWorship(unsigned char, unsigned char);
	unsigned char DwarfCanWorship(unsigned char, unsigned char);
	unsigned char ElfCanWorship(unsigned char, unsigned char);
	unsigned char EruditeCanWorship(unsigned char, unsigned char);
	unsigned char ExpendItemCharge(int, int);
	unsigned char FindItemByClass(int, int*, int*);
	unsigned char FindItemQty(int, int);
	unsigned char FroglockCanWorship(unsigned char, unsigned char);
	unsigned char GetSkillBaseDamage(unsigned char, EQPlayer*);
	unsigned char GnomeCanWorship(unsigned char, unsigned char);
	unsigned char HalfElfCanWorship(unsigned char, unsigned char);
	unsigned char HalflingCanWorship(unsigned char, unsigned char);
	unsigned char HighElfCanWorship(unsigned char, unsigned char);
	unsigned char HumanCanWorship(unsigned char, unsigned char);
	unsigned char IksarCanWorship(unsigned char, unsigned char);
	unsigned char IsSpellAffectingPC(int, int);
	unsigned char LaunchSpell(unsigned char, int, EQ_Item**);
	unsigned char OgreCanWorship(unsigned char, unsigned char);
	unsigned char SpellFizzled(unsigned char, EQ_Spell*);
	unsigned char TrollCanWorship(unsigned char, unsigned char);
	unsigned char VahShirCanWorship(unsigned char, unsigned char);
	void CalcFoodDrinkBonus(int);
	void DoFishingEvent();
	void DoIntimidationEvent();
	void DoLight(unsigned char);
	void DoMeditation();
	void DoPassageOfTime();
	void EQ_CharacterResetAllMembers();
	void EQSPA_Feign_Death(int);
	void eqspa_levitation();
	void eqspa_locate_corpse();
	void eqspa_movement_rate(int);
	void HandleSpecialPCAffects(int);
	void HitBySpell(EQMissileHitinfo*);
	void IAmDead(EQMissileHitinfo*, int);
	void InitInnates(unsigned int, unsigned int);
	void InitMyLanguages();
	void InitSkills(unsigned char, unsigned int);
	void ItemSold(long);
#if defined(ROF2EMU) || defined(UFEMU)
	void ModifyCurHP(int modification, PlayerZoneClient* resposibleplayer, int skilltype);
#else
	void ModifyCurHP(int64_t modification, PlayerZoneClient* resposibleplayer, int skilltype);
#endif
	void NotifyPCAffectChange(int, int);
	void ProcessAllStats();
	void ProcessEnvironment();
	void ProcessHungerandThirst(unsigned int);
	void RemovePCAffect(EQ_Affect*);
	void RemovePCAffectex(EQ_Affect*, int);
	void ResetCur_HP(int);
	void UpdateMyVisibleStatus();
	bool DoCombatAbility(int spellID, int dummy=1);
	unsigned long GetConLevel(EQPlayer*);

	// private
	int GetCachEQSPA(int);
	void ReCachItemEffects();
	void ReCachSpellEffects();
};

class EQLIB_OBJECT EQ_CharacterData
{
public:
	void EQ_CharacterDataResetAllMembers();
};

class EQLIB_OBJECT EQ_Container
{
public:
	~EQ_Container();
	EQ_Container();
	unsigned char Close();
	unsigned char IsOpen();
	unsigned char Open();
};

class EQLIB_OBJECT EQ_Equipment
{
public:
	EQ_Equipment();
	int IsInstrument();
	int IsWeapon();
	void SendTextRequestMsg();
};

enum KeyRingType
{
	eMount,
	eIllusion,
	eFamiliar,
};

enum eAugFitRet
{
	AF_FITS,
	AF_RACE_MISMATCH,
	AF_CLASS_MISMATCH,
	AF_DEITY_MISMATCH,
	AF_LOC_MISMATCH,
	AF_SLOTFULL,
	AF_INVALIDSLOT,
	AF_AUG_MISMATCH,
	AF_SKIN_MISMATCH,
	AF_AUGCLASS,
	AF_ERR_DUPLICATE,
	AF_NOTRANSFER,
	AF_ITEMRANK_MISMATCH,
	AF_APPEARANCE_MISMATCH,
	AF_ERR_STACKABLE,
	AF_ERR_NOTANAUG,
	AF_ERR_NOEQUIPPEDLOC,
};

// this is really the ItemBase class
class EQLIB_OBJECT EQ_Item
{
public:
	bool IsSpecialNoDrop();
	char* ValueSBuy(float, long);
	char* ValueSRent();
	char* ValueSSell(float, long);
	int Copper();
	int Gold();
	int Platinum();
	int Silver();
	long ValueSellMerchant(float, long) const;
	bool IsStackable();
#if !defined(ROF2EMU) && !defined(UFEMU)
	char* CreateItemTagString(char*, int, bool bFlag = true); // SwiftyMUSE 11-09-2018
#else
	char* CreateItemTagString(char*, int); // Lax 11-14-2003
#endif
	bool CanDrop(bool bDisplayText = false, bool bIncludeContainedItems = true, bool bAllowOverrideNoDropCheck = false, bool bCantDropIfContainingRealEstate = true) const;
	int GetImageNum() const;
	static VePointer<CONTENTS> CreateItemClient(PBYTE*, DWORD);
	int GetItemValue(bool) const;
	bool IsKeyRingItem(KeyRingType type) const;
	bool CanGoInBag(PCONTENTS*pCont, int OutputText = 0, bool mustbefalse = false) const;
	bool IsEmpty() const;
	int GetMaxItemCount() const;
	int GetAugmentFitBySlot(PCONTENTS* Aug, int Slot, bool bCheckSlot = true, bool bCheckDup = true) const;

	ITEMINFO Data;
};

class EQLIB_OBJECT EQ_LoadingS
{
public:
	~EQ_LoadingS();
	EQ_LoadingS();
	void draw();
	void DrawBackground();
	void SetProgressBar(int, const char*);
	void WriteTextHD(char*, int, int, int);

	// virtual
	void Activate();
	void Deactivate();
	void DefineImages();
};

class EQLIB_OBJECT EQ_Note
{
public:
	~EQ_Note();
	EQ_Note();
	void SendTextRequestMsg();
};

EQLIB_OBJECT struct ItemContainingRealEstate
{
	int                RealEstateID;
	ItemGlobalIndex    ItemLocation;
};

// This is now PcZoneClient. Most of this class is defunct
class EQLIB_OBJECT EQ_PC
{
public:
	~EQ_PC();
	EQ_PC(EQ_PC*);
	int BitchCanTrain(int, int, int);
	int CheckDupLoreItems();
	int checkLang(int);
	int CostToTrain(int, float, int);
	int DelLoreItemDup(int, int, int, EQ_Item*);
	// GetAlternateAbilityId checked on May 1 2016 only reason why it looks like it takes 2 args(which it doesnt) is cause it pushes another which is meant for AltAdvManager__GetAAById_x see 43BBB7 in eqgame 21 apr 2016 live for an example.
	int GetAlternateAbilityId(int);
	int GetArmorType(int);
	int GetCombatAbility(int);
	PcZoneClient* GetPcZoneClient() const;
	int HandleMoney(long);
	int IsAGroupMember(char*);
	int MaxAirSupply();
	int numInParty();
	static EQ_PC* top;
	unsigned char AtSkillLimit(int);
	unsigned char RemoveMyAffect(int);
	unsigned long GetArmorTint(int);
	unsigned long GetBodyTint(int);
	void CheckForGroupChanges();
	void CheckForLanguageImprovement(unsigned char, unsigned char);
	void CheckSkillImprove(int, float);
	void ClearSharedVault();
	void DestroyHeldItemOrMoney();
	void DetermineQuestExpGained(int);
	void EmptyPossessionSlots();
	void InitializeNewPCVariables(int);
	void InitPlayerStart(unsigned int, unsigned char, int);
	void PrepareForRepop(int);
	void ProcessAirSupply();
	void ProcessFatigue();
	void RefitNewbieEQ();
	void RefreshMe(int);
	void SetAltAbilityIndex(int, int);
	void SetArmorTint(int, unsigned long);
	void SetArmorType(int, int);
	void SetFatigue(int);
	void UnpackMyNetPC(char*, int);
	void AlertInventoryChanged();
	// GetCombatAbilityTimer has 2 parameters confirmed apr 21 2016 eqgame.exe (live)
#if !defined(ROF2EMU) && !defined(UFEMU)
	unsigned long GetCombatAbilityTimer(int, int);
	unsigned long GetItemRecastTimer(EQ_Item* item, ItemSpellTypes etype);
#else
	unsigned long GetCombatAbilityTimer(int);
	unsigned long GetItemRecastTimer(class EQ_Item*item);
#endif
	bool HasLoreItem(EQ_Item*, int, int, int, int);
	void GetItemContainedRealEstateIds(ArrayClass<ItemContainingRealEstate> &Out, bool bCurrentProfileOnly = false, bool bIncludeAltStorage = true, bool bIncludeArchived = true);
	void GetNonArchivedOwnedRealEstates(ArrayClass<int>& output);
};

class EQLIB_OBJECT ProfileManager
{
public:
	BaseProfile* GetCurrentProfile();
};

class EQLIB_OBJECT EQ_Skill
{
public:
	EQ_Skill(int);
	~EQ_Skill();
};

class EQLIB_OBJECT EQ_Spell
{
public:
	~EQ_Spell();
	EQ_Spell(char*);
	bool IsStackableDot() const;
	bool IsStackable() const;
	int IsPermIllusionSpell() const;
	int SpellUsesDragonBreathEffect();
	unsigned char SpellAffects(int) const;              // this one takes an attrib(soe calls it affect) and returns the index for it...
	unsigned char GetSpellLevelNeeded(int) const;       // takes a Class, druid for example is 6
	int SpellAffectBase(int) const;                     // takes a SPA, returns the first matching base it finds for it
	const SPELLCALCINFO* GetSpellAffectBySlot(int Slot) const;
#if !defined(ROF2EMU)
	const SPELLCALCINFO* GetSpellAffectByIndex(int Index) const;
#endif
	bool IsNoRemove() const;
	static bool IsDegeneratingLevelMod(int);

	static bool IsSPAStacking(int Spa);
	static bool IsSPAIgnoredByStacking(int Spa);

	bool IsNoDispell() const { return Data.NoDisspell; }
	bool IsStackableOnAnyone() const { return SpellAffects(424) != 0; }
	int GetNoOverwrite() const { return Data.NoOverwrite; }
	bool IsBeneficialSpell() const { return Data.SpellType >= 1; }
	bool IsDetrimentalSpell() const { return Data.SpellType == 0; }
	bool IsShortEffectDuration() const { return Data.DurationWindow; }
	bool GetIsSkillSpell() const { return Data.IsSkill; }
	bool IsDoTSpell() const
	{
		return SpellAffects(0) || SpellAffects(20) || SpellAffects(69) || SpellAffects(114) || SpellAffects(125);
	}

	SPELL Data;
};

class EQLIB_OBJECT EQAnimation
{
public:
	EQAnimation();
	~EQAnimation();
};

class EQLIB_OBJECT EQEffect
{
public:
	static EQEffect* top;

	~EQEffect();
	EQEffect(EQEffect*, char*, int, EQLOC*, EQPlayer*, EQMissile*, EQRGB*, float, int, int, float, float);
};

class EQLIB_OBJECT EqEmitterData
{
public:
	EqEmitterData();
	void SetLoadString(char*);
};

class EQHSprite
{
public:
	static EQHSprite* top;

	~EQHSprite();
	EQHSprite(char*, CActorInterface*, EQPlayer*);
	bool GetAnimationTrackPtr(char*, char*, int, int, unsigned char, int);
	EQHSprite* get_object(char*);
};

class EQLIB_OBJECT EQItemList
{
public:
	static class EQItemList* top;

	~EQItemList();
	EQItemList();
	EQItemList* get_item(long);
	EQItemList* is_item_actor(CActorInterface*);
};

class EQLIB_OBJECT EQMissile
{
public:
	static EQMissile* top;

	~EQMissile();
	EQMissile(EQ_Equipment*, EQPlayer*, EQMissile*, char*, unsigned char, unsigned int);
	EQMissile* is_missile_actor(CActorInterface*);
	void CleanUpMyEffects();
	void HitActor(CActorInterface*, bool);
	void LeaveTrail();
	void MissileAI();
	void ProcessMissile();
};

class EQLIB_OBJECT EqMobileEmitter
{
public:
	~EqMobileEmitter();
	EqMobileEmitter(EqSoundManager*);
	void Move(float, float, float);
	void SetNpcHeight(float);
	void SetWave(int, char*);
};

class EQLIB_OBJECT EQMoneyList
{
public:
	EQMoneyList();
	~EQMoneyList();
	EQMoneyList* get_money(long);

	static EQMoneyList* top;
};

class EQLIB_OBJECT EQObject
{
public:
	EQObject(EQObject*, EQPlayer*, char*, char*);
	~EQObject();

	static EQObject* top;
};

enum ePlacementType
{
	PLACEMENT_TYPE_FLOOR,
	PLACEMENT_TYPE_WALL,
	PLACEMENT_TYPE_CEILING,
};

class EQLIB_OBJECT EQPlacedItem
{
public:
/*0x00*/ void*         vftable;
/*0x04*/ EQPlacedItem* pPrev;
/*0x08*/ EQPlacedItem* pNext;
/*0x0c*/ int           RecordNum;
/*0x10*/ EqItemGuid    ItemGuid;
/*0x22*/
/*0x24*/ int           RealEstateID;
/*0x28*/ int           RealEstateItemID;
/*0x2C*/ bool          bIsNPC;
/*0x30*/ UINT          PlacingItemNpcID;
/*0x34*/ CLightInterface* pLight;
/*0x38*/ CActorInterface* pActor;
/*0x3c*/ char          Name[0x40];
/*0x7c*/ float         Scale;
/*0x80*/ float         Heading;
/*0x84*/ float         Angle;
/*0x88*/ float         Roll;
/*0x8c*/ float         Y;
/*0x90*/ float         X;
/*0x94*/ float         Z;
/*0x98*/ bool          bIgnoreCollisions;
/*0x98*/ bool          bDisablePlacementRotation;
/*0x98*/ bool          bDisableFreePlacement;
/*0x9c*/ ePlacementType PlacementType;
/*0xa0*/ float         ScaleRangeMin;
/*0xa4*/ float         ScaleRangeMax;
/*0xa8*/ float         DefaultScale;
/*0xac*/ float         DefaultHeading;
/*0xb0*/ float         DefaultAngle;
/*0xb4*/ float         DefaultRoll;
/*0xb8*/ int           LightType;
/*0xbc*/ float         NPCHeight;
/*0xC0*/
};

class EQLIB_OBJECT EQPlacedItemManager
{ 
public:
	static EQPlacedItemManager& Instance();
	EQPlacedItem* GetItemByGuid(const EqItemGuid& ItemGuid);
	EQPlacedItem* GetItemByRealEstateAndRealEstateItemIds(int RealEstateID, int RealEstateItemID);

	EQPlacedItem*      Top;
};

class EQLIB_OBJECT RealEstateItemIds
{
public:
	int                RealEstateID;
	int                RealEstateItemID;
};

class EQLIB_OBJECT RealEstateItemState
{
public:
	bool               bPlaced;
	__time32_t         UpkeepExpiredTime;
};

class EQLIB_OBJECT RealEstateItemPosition
{
public:
	float              Heading;
	float              Pitch;
	float              Roll;
	float              Scale;
	float              X;
	float              Y;
	float              Z;
};

class EQLIB_OBJECT RealEstateItemOwnerInfo
{
public:
	CXSTR*             OwnerName;
	CXSTR*             OwnerHandle;
	int                OwnerNameHashKey;
};

class EQLIB_OBJECT RealEstateItemObject
{
public:
	VePointer<CONTENTS> pItemBase;
};

class EQLIB_OBJECT RealEstateItem
{
public:
	RealEstateItemState                State;
	RealEstateItemPosition             Position;
	RealEstateItemOwnerInfo            OwnerInfo;
	RealEstateItemObject               Object;
};

class EQLIB_OBJECT RealEstateItemClient : public RealEstateItem
{
public:
	RealEstateItemIds IDs;
};

enum eRealEstateType
{
	RET_None = 0,
	RET_Zone,
	RET_GuildHall,
	RET_PlayerHousing,
	RET_PlayerPlot,
	RET_Neighborhood,
	RET_Town,
	RET_MovingCrate,
	RET_GuildPlot,
	RET_Count,
	RET_Unknown,
	RET_Any
};

class EQLIB_OBJECT RealEstateManagerClient
{
public:
/*0x00*/ void*         vftable;
/*0x04*/ BYTE          Stuff[0xb4];
/*0xb8*/ UINT          lastRefreshTime;
/*0xbc*/ int           ZoneRealEstateId;
/*0xc0*/ eRealEstateType ZoneRealEstateType;
/*0xc4*/ int           CurrentRealEstateID;
/*0xc8*/ int           CurrentYardID;
/*0xcc*/ int           CurrentHouseID;
/*0xa0*/ int           CurrentMovingCrateID;
/*0xa4*/ bool          bRequestPending;
/*0xa8*/ UINT          RequestTime;
/*0xac*/ bool          bPrintRequestTimes;

	static RealEstateManagerClient& Instance();
	const RealEstateItemClient* GetItemByRealEstateAndItemIds(int RealEstateID, int RealEstateItemID) const;
};

class EQLIB_OBJECT FactionManagerClient
{
public:
/*0x00*/ void*         vftable;
/*0x04*/ // todo: map it

	static FactionManagerClient& Instance();
	void HandleFactionMessage(UINT MessageID, char* pData, unsigned int DataLength);
};

struct chngForm;

// This is now PlayerZoneClient
class EQLIB_OBJECT EQPlayer
{
public:
	~EQPlayer();
	EQPlayer(EQPlayer*, unsigned char, unsigned int, unsigned char, char*);
	bool AllowedToAttack(EQPlayer*, int);
	bool CanChangeForm(int Race, BYTE Sex, float Height);
	bool CanIFitHere(float, float, float);
	bool CanIHit(EQPlayer*, float);
	bool CanSee(EQPlayer*);
	bool CanSee(CVector3* pos);
	bool IsAMount();
	bool IsFlyer();
	bool IsInvisible(EQPlayer*);
	bool IsInvited();
	bool IsRoleplaying();
	bool IsUntexturedHorse();
	bool IWasHit(EQMissileHitinfo*);
	bool MyFeetAreOnGround();
	bool SetNameSpriteTint();
	bool UpdatePlayerActor();
	bool const HasInvalidRiderTexture() const;
	float GetDefaultHeight(int, unsigned char);
	float GetPlayerFloorHeight(float, float, float, unsigned char);
	int AimAtTarget(EQPlayer*, EQMissile*);
	int CanBeBald();
	int CheckForJump();
#if defined(ROF2EMU) || defined(UFEMU)
	bool DoAttack(BYTE slot, BYTE skill, EQPlayer* Target);
#else
	bool DoAttack(BYTE slot, BYTE skill, EQPlayer* Target, bool bSomething = false, bool bAuto = false, bool bDontknow = false);
#endif
	int GetAlternateTrackNumber(int, unsigned char*);
	int GetArmorType(int);
	int GetAttachedHelmITNum(int, int*);
	int GetGuild() const;
	int GetRaceSexITOffset();
	bool IsValidTeleport(float X, float Y, float Z, float Heading, float Distance);
	int Levitating();
	int MountableRace();
	int MovePlayer();
	int NotOnSameDeity(EQPlayer*, EQ_Spell*);
	int ReplaceSpecialCloakMaterials();
	int SetEyeMaterial(unsigned char, int);
	int SetFHEB(unsigned char, unsigned char);
	int SetFHEB_Color(unsigned char, unsigned char);
	int SetHairOrBeard(int);
	int SetNameSpriteState(bool);
	int SetPlayerPitchType();
	int SwapBody(int, int);
	int SwapFace(int, int);
	int SwapHead(int, int, unsigned long, int);
	int SwapMaterial(int, int, int, int, unsigned char);
	int SwapNPCMaterials();
	static EQPlayer* GetClosestPlayerFromPartialName(char*, EQPlayer*);
	static EQPlayer* GetPlayerFromPartialName(char*);
	static EQPlayer* IsPlayerActor(CActorInterfaceBase*);
	static EQPlayer* GetPlayerFromName(const char*);
	static void ComputeSpecialHeights(int, float*, float*, float*, float*, bool);
	static void GetPCActorTag(char*, unsigned int, unsigned char);
	static void TackOnNeuterChar(char*, unsigned int);
	static void UpdateAllPlayersVisibility();
	CLightInterface* CreateUserLight(CLightDefinitionInterface*, int);
	unsigned char DoTeleport(char*, int);
	unsigned char DoTeleportB(int, float, float, float, float, char*, int);
	unsigned char GetBaseFaceNbr(int, unsigned char*);
	unsigned char GetNearestActorTag(char*, void*);
	unsigned char HandleAmmo();
	unsigned char HasAttachedBeard();
	unsigned char HasAttachedHair();
	unsigned char SkillUsed(unsigned char);
	unsigned char UpdateItemSlot(unsigned char, char*, int);
	unsigned int CalcAnimLength(int);
	unsigned int ModifyAttackSpeed(unsigned int, int);
	unsigned long GetArmorTint(int);
	void BodyEnvironmentChange(unsigned char);
	void ChangeHeight(float);
	void ChangeLight();
	void ChangeNoGravity(int);
	void ChangePosition(unsigned char);
	void CheckForUnderFloor();
	void CleanUpMyEffects();
	void CleanUpTarget();
	void CleanUpVehicle();
	void DeleteMyMissiles();
	void Dismount();
	void DisplayWeaponsAndArmor();
	void do_change_form(chngForm*);
	void DoCamAi();
	void DoClassRandomAnimation();
	void DoFloorCheck();
	void DoItemSlot(int);
	void DoSwimJump(unsigned char);
	void FacePlayer(EQPlayer*);
	void FeetEnvironmentChange(unsigned char);
	void FollowPlayerAI();
	void ForceInvisible(bool);
	void GetActorTag(char*);
	void GetAllowedHairColorIndexRange(int, int*, int*);
	void GetConscious();
	void HandleMaterialEx(int, unsigned int, unsigned int, unsigned long, int);
	void HandoverControlToZoneserver();
	void HeadEnvironmentChange(unsigned char);
	void HideOrShowAttachedHair();
	void IDied(EQPlayerDeath*);
	void IHaveFallen(float);
	void InitSneakMod();
	void KnockedOut();
	void MakeRiderMountUp();
	void MountEQPlayer(EQPlayer*);
	void PlaySoundA(int);
	void PositionOnFloor();
	void PushAlongHeading(float);
	void PutPlayerOnFloor();
	void ResetVariables();
	void SetAccel(float, int);
	void SetAfk(int);
	void SetAndReserveID(unsigned int);
	void SetAnimVariation();
	void SetArmorTint(int, unsigned long);
	void SetArmorType(int, int);
	void SetCurrentLoopSound(int);
	void SetDefaultFacialFeaturesByFace(int, unsigned char, unsigned char);
	void SetDefaultITAttachments(int);
	void SetHeights();
	void SetInvited(bool);
	void SetRace(int);
	void SetSounds();
	void SetToRandomRace();
	void TouchingSwitch();
	void TriggerSpellEffect(EQMissileHitinfo*);
	void TurnOffAutoFollow();
	void UpdateAppearance();
	void UpdateBonePointers();
	void UpdateNameSprite();
	void UpdatePlayerVisibility();
	bool HasProperty(unsigned int, int, int);
	CLineSegment& GetVisibilityLineSegment(CLineSegment& ls, EQPlayer& pSpawn, unsigned int index = 0); // index MUST be 0

	// private
	int IdUsed(unsigned int);
	unsigned char GetAlternateAnimVariation(int, unsigned char);
	unsigned int GetUnusedID();
	void FindDefaultEyeMaterialIndexes();
	void InitializeIDArray();
	BYTE GetLevel() const;
	static EQPlayer* mTop;

	SPAWNINFO Data;
};

class EQLIB_OBJECT ExtendedTargetListClient : public ExtendedTargetList
{
public:
	int CurrentSlot;
	int ContextSlot;
};

enum eParcelStatus
{
	ePS_NoParcels,
	ePS_HasParcels,
	ePS_OverParcelsLimit,
};

class EQLIB_OBJECT CGroupMemberBase
{
public:
/*0x00*/ void*         vftable;
/*0x04*/ CXSTR*        Name;
/*0x08*/ short         Type;
/*0x0c*/ CXSTR*        OwnerName;
/*0x10*/ int           Level;
/*0x14*/ bool          bIsOffline;
/*0x18*/ UINT          UniquePlayerID;
/*0x1c*/ bool          bRoleStates[6];
/*0x24*/ UINT          CurrentRoleBits;
/*0x28*/ UINT          OnlineTimestamp;
};

class EQLIB_OBJECT CGroupMemberClient : public CGroupMemberBase
{
public:
	CharacterZoneClient* pCharacter;
	SPAWNINFO*           pSpawn;
	int                  GroupIndex;
};

class EQLIB_OBJECT CGroupBase
{
public:
/*0x00*/ void*         vftable;
/*0x04*/ CGroupMemberClient* pMembers[6];
/*0x1c*/ CGroupMemberClient* pGroupLeader;
/*0x20*/ uint32_t      ID;
};

class EQLIB_OBJECT CGroupClient : public CGroupBase
{
public:
/*0x024*/ int          GroupSelectID;
};

class EQLIB_OBJECT PlayerBase : public TListNode<PlayerBase>, public CActorApplicationData 
{
public:
/*0x0010*/ float                       JumpStrength;
/*0x0014*/ float                       SwimStrength;
/*0x0018*/ float                       SpeedMultiplier;
/*0x001c*/ float                       AreaFriction;
/*0x0020*/ float                       AccelerationFriction;
/*0x0024*/ EActorType                  CollidingType;                // ok finally had time to get this one right, when we collide with something this gets set.
/*0x0028*/ float                       FloorHeight;
/*0x002c*/ bool                        bSinksInWater;
/*0x0030*/ UINT                        PlayerTimeStamp;              // doesn't update when on a Vehicle (mounts/boats etc)
/*0x0034*/ UINT                        LastTimeIdle;
/*0x0038*/ char                        Lastname[0x20];
/*0x0058*/ float                       AreaHPRegenMod;               // from guild hall pools etc.
/*0x005c*/ float                       AreaEndRegenMod;
/*0x0060*/ float                       AreaManaRegenMod;
/*0x0064*/ float                       Y;
/*0x0068*/ float                       X;
/*0x006c*/ float                       Z;
/*0x0070*/ float                       SpeedY;
/*0x0074*/ float                       SpeedX;
/*0x0078*/ float                       SpeedZ;
/*0x007c*/ float                       SpeedRun;
/*0x0080*/ float                       Heading;
/*0x0084*/ float                       Angle;
/*0x0088*/ float                       AccelAngle;
/*0x008c*/ float                       SpeedHeading;
/*0x0090*/ float                       CameraAngle;
/*0x0094*/ UINT                        UnderWater;                   // LastHeadEnvironmentType
/*0x0098*/ UINT                        LastBodyEnvironmentType;
/*0x009c*/ UINT                        LastFeetEnvironmentType;
/*0x00a0*/ BYTE                        HeadWet;                      // these really are environment related, like lava as well for example
/*0x00a1*/ BYTE                        FeetWet;
/*0x00a2*/ BYTE                        BodyWet;
/*0x00a3*/ BYTE                        LastBodyWet;
/*0x00a4*/ char                        Name[0x40];                   // ie priest_of_discord00
/*0x00e4*/ char                        DisplayedName[0x40];          // ie Priest of Discord
/*0x0124*/ BYTE                        PossiblyStuck;                // never seen this be 1 so maybe it was used a a point but not now...
/*0x0125*/ BYTE                        Type;
/*0x0128*/ DWORD**                     BodyType;                     // this really should be renamed to charprops or something its broken anyway
/*0x012c*/ BYTE                        CharPropFiller[0xc];          // well since the above is a CharacterPropertyHash we have to pad here...
/*0x0138*/ float                       AvatarHeight;                 // height of avatar from groundwhen standing
/*0x013c*/ float                       Height;
/*0x0140*/ float                       Width;
/*0x0144*/ float                       Length;
/*0x0148*/ DWORD                       SpawnID;
/*0x014c*/ DWORD                       PlayerState;                  // 0=Idle 1=Open 2=WeaponSheathed 4=Aggressive 8=ForcedAggressive 0x10=InstrumentEquipped 0x20=Stunned 0x40=PrimaryWeaponEquipped 0x80=SecondaryWeaponEquipped
/*0x0150*/ SPAWNINFO*                  Vehicle;                      // NULL until you collide with a vehicle (boat, airship etc)
/*0x0154*/ SPAWNINFO*                  Mount;                        // NULL if no mount present
/*0x0158*/ SPAWNINFO*                  Rider;                        // _SPAWNINFO of mount's rider
/*0x015c*/ DWORD                       Unknown0x015c;
/*0x0160*/ bool                        Targetable;	                 // true if mob is targetable
/*0x0161*/ bool                        bTargetCyclable;
/*0x0162*/ bool                        bClickThrough;
/*0x0163*/ bool                        bBeingFlung;
/*0x0164*/ UINT                        FlingActiveTimer;
/*0x0168*/ UINT                        FlingTimerStart;
/*0x016c*/ bool                        bFlingSomething;
/*0x0170*/ float                       FlingY;
/*0x0174*/ float                       FlingX;
/*0x0178*/ float                       FlingZ;
/*0x017c*/ bool                        bFlingSnapToDest;
/*0x0180*/ int                         SplineID;
/*0x0184*/ int                         SplineRiderID;

	unsigned int GetId() const
	{
		return SpawnID;
	}
};

#define EQR_GNOME           0xc        // 5A1511 in rof2
#define EQR_IKSAR           0x80       // 5A1516 in rof2
#define EQR_VAHSHIR         0x82       // 5A151D in rof2
#define EQR_FROGLOCK        0x14a      // 5A1524 in rof2
#define EQR_DRAKKIN         0x20a      // 5A152B in rof2
#define EQR_SKELETON        0x3c
#define EQR_SKELETON_NEW    0x16f
#define EQR_OEQ_SKELETON    0x322
#define EQR_SOL_SKELETON    0x323

class EQLIB_OBJECT PlayerZoneClient : public PlayerBase
{
public:
/*0x0188*/ UINT                        LastIntimidateUse;
/*0x018c*/ PLAYERZONECLIENT
/*0x0614*/ // I wont finetune these comments every single patch cause they change since PLAYERZONECLIENT size change...
/*0x0614*/ TCircularBuffer<SDoCollisionMovementStats, 0x14> MovementStats;
/*0x0f2c*/ SPAWNINFO*                  WhoFollowing;                 // NULL if autofollow off
/*0x0f30*/ DWORD                       GroupAssistNPC[0x1];
/*0x0f34*/ DWORD                       RaidAssistNPC[0x3];
/*0x0f40*/ DWORD                       GroupMarkNPC[0x3];
/*0x0f4c*/ DWORD                       RaidMarkNPC[0x3];
/*0x0f58*/ DWORD                       TargetOfTarget;
/*0x0f5c*/ BYTE                        PhysStuff[0x20];
/*0x0f7c*/ UINT                        ParticleCastStartTime;
/*0x0f80*/ UINT                        ParticleCastDuration;
/*0x0f84*/ int                         ParticleVisualSpellNum;
/*0x0f88*/ BYTE                        Filler0x0f88[0x4];
/*0x0f8c*/ ActorClient                 mActorClient;                 // start of ActorClient struct  size 0x1BC?
/*0x1148*/ PlayerAnimationBase*        pAnimation;
/*0x114c*/ float                       MeleeRadius;                  // used by GetMeleeRange
/*0x1150*/ UINT                        CollisionCounter;
/*0x1154*/ float                       CachedFloorLocationY;
/*0x1158*/ float                       CachedFloorLocationX;
/*0x115c*/ float                       CachedFloorLocationZ;
/*0x1160*/ float                       CachedFloorHeight;
/*0x1164*/ float                       CachedCeilingLocationY;
/*0x1168*/ float                       CachedCeilingLocationX;
/*0x116c*/ float                       CachedCeilingLocationZ;
/*0x1170*/ float                       CachedCeilingHeight;
/*0x1174*/ CCapsule                    StaticCollision;
/*0x1190*/ ArrayClass_RO<PhysicsEffect> mPhysicsEffects;
/*0x11a0*/ ArrayClass_RO<bool>         PhysicsEffectsUpdated;

#if defined(UFEMU)
	// this function doesnt exist in the emu build, so well... im adding it i guess...
	int LegalPlayerRace(int race)
	{
		if (race == -1)
		{
			race = this->mActorClient.Race;
		}

		if ((race <= EQR_GNOME) || (race == EQR_IKSAR) || (race == EQR_VAHSHIR) || (race == EQR_FROGLOCK) || (race == EQR_DRAKKIN))
		{
			return 1;
		}
		return 0;
	}
#else
	int LegalPlayerRace(int race);
#endif

};

// this is what we call EQPlayer maybe i should just rename that one but too late now?
class EQLIB_OBJECT PlayerClient : public PlayerZoneClient
{
public:
/*0x1198*/ int                         Animation;
/*0x11xx*/ int                         NextAnim;
/*0x11xx*/ int                         CurrLowerBodyAnim;
/*0x1194*/ int                         NextLowerBodyAnim;
/*0x1198*/ int                         CurrLowerAnimVariation;
/*0x119c*/ int                         CurrAnimVariation;
/*0x11a0*/ int                         CurrAnimRndVariation;

	// Begin of sound Ids
/*0x11a4*/ int                         Loop3d_SoundID;

/*0x11a8*/ int                         Step_SoundID;;
/*0x11ac*/ int                         CurLoop_SoundID;
/*0x11b0*/ int                         Idle3d1_SoundID;
/*0x11b4*/ int                         Idle3d2_SoundID;
/*0x11b8*/ int                         Jump_SoundID;
/*0x11bc*/ int                         Hit1_SoundID;
/*0x11c0*/ int                         Hit2_SoundID;
/*0x11c4*/ int                         Hit3_SoundID;
/*0x11c8*/ int                         Hit4_SoundID;
/*0x11cc*/ int                         Gasp1_SoundID;
/*0x11d0*/ int                         Gasp2_SoundID;
/*0x11d4*/ int                         Drown_SoundID;
/*0x11d8*/ int                         Death_SoundID;
/*0x11dc*/ int                         Attk1_SoundID;
/*0x11e0*/ int                         Attk2_SoundID;
/*0x11e4*/ int                         Attk3_SoundID;
/*0x11e8*/ int                         Walk_SoundID;
/*0x11ec*/ int                         Run_SoundID;
/*0x11f0*/ int                         Crouch_SoundID;
/*0x11f4*/ int                         Swim_SoundID;
/*0x11f8*/ int                         TreadWater_SoundID;
/*0x11fc*/ int                         Climb_SoundID;
/*0x1200*/ int                         Sit_SoundID;
/*0x1204*/ int                         Kick_SoundID;
/*0x1208*/ int                         Bash_SoundID;
/*0x120c*/ int                         FireBow_SoundID;
/*0x1210*/ int                         MonkAttack1_SoundID;
/*0x1214*/ int                         MonkAttack2_SoundID;
/*0x1218*/ int                         MonkSpecial_SoundID;
/*0x121c*/ int                         PrimaryBlunt_SoundID;
/*0x1220*/ int                         PrimarySlash_SoundID;
/*0x1224*/ int                         PrimaryStab_SoundID;
/*0x1228*/ int                         Punch_SoundID;
/*0x122c*/ int                         Roundhouse_SoundID;
/*0x1230*/ int                         SecondaryBlunt_SoundID;
/*0x1234*/ int                         SecondarySlash_SoundID;
/*0x1238*/ int                         SecondaryStab_SoundID;
/*0x123c*/ int                         SwimAttack_SoundID;
/*0x1240*/ int                         TwoHandedBlunt_SoundID;
/*0x1244*/ int                         TwoHandedSlash_SoundID;
/*0x1248*/ int                         TwoHandedStab_SoundID;
/*0x124c*/ int                         SecondaryPunch_SoundID;
/*0x1250*/ int                         JumpAcross_SoundID;
/*0x1254*/ int                         WalkBackwards_SoundID;
/*0x1258*/ int                         CrouchWalk_SoundID;

/*0x125c*/ UINT                        LastHurtSound;
/*0x1260*/ UINT                        LastWalkTime;                 // used for animations
/*0x1264*/ int                         ShipRelated;                  // ID? look into.
/*0x1268*/ int                         RightHolding;                 // Nothing=0 Other/Weapon=1 shield=2
/*0x126c*/ int                         LeftHolding;                  // old Holding
/*0x1270*/ UINT                        DeathAnimationFinishTime;
/*0x1274*/ bool                        bRemoveCorpseAfterDeathAnim;  // used by /hidecorpse
/*0x1278*/ UINT                        LastBubblesTime;
/*0x127c*/ UINT                        LastBubblesTime1;
/*0x1280*/ UINT                        LastColdBreathTime;
/*0x1284*/ UINT                        LastParticleUpdateTime;
/*0x1288*/ UINT                        MercID;                       // if the spawn is player and has a merc up this is it's spawn ID 16 jul 2014
/*0x128c*/ UINT                        ContractorID;                 // if the spawn is a merc this is its contractor's spawn ID 16 jul 2014
/*0x1290*/ float                       CeilingHeightAtCurrLocation;
/*0x1294*/ void*                       MobileEmitter;                // todo: change and map to EqMobileEmitter*
/*0x1298*/ bool                        bInstantHPGaugeChange;
/*0x129c*/ UINT                        LastUpdateReceivedTime;
/*0x12a0*/ float                       MaxSpeakDistance;
/*0x12a4*/ float                       WalkSpeed;                    // how much we will slow down while sneaking
/*0x12a8*/ bool                        bHideCorpse;
/*0x12a9*/ char                        AssistName[0x40];
/*0x12E9*/ bool                        InvitedToGroup;
/*0x12ec*/ int                         GroupMemberTargeted;          // 0xFFFFFFFF if no target, else 1 through 5
/*0x12f0*/ bool                        bRemovalPending;
/*0x12f4*/ void*                       pCorpse;
/*0x12f8*/ float                       EmitterScalingRadius;
/*0x12fc*/ int                         DefaultEmitterID;
/*0x1300*/ bool                        bDisplayNameSprite;
/*0x1301*/ bool                        bIdleAnimationOff;
/*0x1302*/ bool                        bIsInteractiveObject;
/*0x1303*/ BYTE                        InteractiveObjectModelName[0x80];
/*0x1383*/ BYTE                        InteractiveObjectOtherName[0x80];
/*0x1403*/ BYTE                        InteractiveObjectName[0x40];
/*0x1443*/
/*0x1444*/ CPhysicsInfo                PhysicsBeforeLastPort;
/*0x1474*/ DWORD                       notsure;
/*0x1478*/ FELLOWSHIPINFO              Fellowship;
/*0x1E60*/ float                       CampfireY;
/*0x1e64*/ float                       CampfireX;
/*0x1e68*/ float                       CampfireZ;
/*0x1e6c*/ int                         CampfireZoneID;               // zone ID where campfire is
/*0x1e70*/ int                         CampfireTimestamp;            // CampfireTimestamp-FastTime()=time left on campfire
/*0x1e74*/ int                         CampfireTimestamp2;
/*0x1e78*/ int                         FellowShipID;
/*0x1e7c*/ int                         FellowShipID2;
/*0x1e80*/ int                         CampType;
/*0x1e84*/ bool                        Campfire;
/*0x1e88*/ TSafeArrayStatic<int, 3>    SeeInvis;
/*0x1E94*/ EQUIPMENT                   Equipment;
/*0x1F48*/ bool                        bIsPlacingItem;
/*0x1f49*/ bool                        bGMCreatedNPC;
/*0x1f4c*/ int                         ObjectAnimationID;
/*0x1f50*/ bool                        bInteractiveObjectCollidable;
/*0x1f54*/ int                         InteractiveObjectType;
/*0x1f58*/ int                         SoundIDs[0xa];
/*0x1f80*/ UINT                        LastHistorySentTime;
/*0x1f84*/ ArrayClass2_RO<UINT>        BardTwistSpells;
/*0x1fA0*/ int64_t                     CurrentBardTwistIndex;
/*0x1fA8*/ PlayerPhysicsClient         mPlayerPhysicsClient;
/*0x1Fd0*/ int                         SpawnStatus[6];               // todo: look closer at these i think they can show like status of mobs slowed, mezzed etc, but not sure
/*0x1fe8*/ int                         BannerIndex0;                 // guild banners
/*0x1fec*/ int                         BannerIndex1;
/*0x1ff0*/ ARGBCOLOR                   BannerTint0;
/*0x1ff4*/ ARGBCOLOR                   BannerTint1;
/*0x1ff8*/ int                         MountAnimationRelated;
/*0x1ffc*/ bool                        bGuildShowAnim;               // or sprite? need to check
/*0x1ffd*/ bool                        bWaitingForPort;              // check this

	PcClient* GetPcClient() const;     // call this using pLocalPlayer->GetPcClient();

	int GetClass()
	{
		return mActorClient.Class;
	}

	BYTE GetCharacterType()
	{
		return Type;
	}

	char IsGm()
	{
		return GM;
	}
};

class MercenaryAbilityEffectsDefinition;

class EQLIB_OBJECT SpellCache
{
public:
	struct EffectCache
	{
		int            SubIndex;
		int            TotalPlayerEffects;
		int            TotalItemEffects;
		bool           bDegenerating;
		int            TotalContrib;
	};

	struct AltEffectCache
	{
		int            SubIndex
		int            AltTotal;
	};

	struct CachedFocusItem
	{
		CONTENTS*      pContents;
		int            Percent;
		ItemSpellTypes SpellType;
	};

	struct CachedFocusEffect
	{
		const SPELL*   pSpell;
		int            Percent;
		short          AffectIndex;
	};

	struct CachedFocusAbility
	{
		const void*    pEffectData;
		int            Percent;
	};

	struct CachedFocusMercAbility
	{
		const MercenaryAbilityEffectsDefinition* pAbilityEffectDef;
		int            Percent;
	};

/*0x00*/ HashTable<EffectCache>*       pCachedEffects;
/*0x04*/ bool                          bCachedSpellEffects;
/*0x08*/ HashTable<AltEffectCache>*    pCachedAltAbilityEffects;
/*0x0c*/ bool                          bCachedAltEffects;
/*0x10*/ HashTable<EffectCache>*       pCachedLimitedEffects;
/*0x14*/ bool                          bCachedLimitedEffects;
/*0x18*/ HashTable<CachedFocusItem, int64_t>        CachedFocusItems;
/*0x28*/ HashTable<CachedFocusEffect, int64_t>      CachedFocusEffects;
/*0x38*/ HashTable<CachedFocusAbility, int64_t>     CachedFocusAbilities;
/*0x48*/ HashTable<CachedFocusMercAbility, int64_t> CachedFocusMercAbilities;
/*0x58*/ 
};

enum GILocationOption
{
	Bag_Or_Base,
	Socket
};

class EQLIB_OBJECT CharacterBase
{
public:
/*0x0000*/ void*                       CharacterBase_vftable;
/*0x0004*/ CProfileManager             ProfileManager;
/*0x000C*/ TSafeArrayStatic<BYTE, 0x20> languages;
/*0x002C*/ float                       X;
/*0x0030*/ float                       Y;
/*0x0034*/ float                       Z;
/*0x0038*/ float                       Heading;
/*0x003c*/ TSafeString<0x40>           Name;
/*0x007c*/ TSafeString<0x20>           Lastname;
/*0x009c*/ TSafeString<0x80>           Title;
/*0x011c*/ TSafeString<0x40>           VehicleName;
/*0x015c*/ char                        Stunned;                      // well status really
/*0x0160*/ EQZoneIndex                 zoneId;
/*0x0164*/ BYTE                        standstate;
/*0x0168*/ RaidData                    raidData;
/*0x0244*/ int                         ExpansionFlags;
/*0x0248*/ bool                        bSuperPKILL;
/*0x024a*/ bool                        bUnclone;
/*0x024b*/ bool                        bDead;
/*0x024C*/ int                         LD_Timer;
/*0x0250*/ int                         SpellInterruptCount;
/*0x0254*/ bool                        bAutoSplit;
/*0x0255*/ bool                        bTellsOff;
/*0x0256*/ bool                        bGmInvis;
/*0x0258*/ int                         KillMe;
/*0x025c*/ bool                        CheaterLdFlag;                // likely this is int SoulMarkCount instead.
/*0x025d*/ bool                        NoRent;
/*0x025e*/ bool                        Corpse;
/*0x025f*/ bool                        ClientGmFlagSet;
/*0x0260*/ int                         BankSharedPlat;               // 31e4 CharBaseBegin+488
/*0x0264*/ int                         BankSharedGold;               // CharBaseBegin+48c
/*0x0268*/ int                         BankSharedSilver;             // CharBaseBegin+490
/*0x026c*/ int                         BankSharedCopper;             // CharBaseBegin+494
/*0x0270*/ int                         BankPlat;                     // CharBaseBegin+498
/*0x0274*/ int                         BankGold;                     // CharBaseBegin+49c
/*0x0278*/ int                         BankSilver;                   // CharBaseBegin+4a0
/*0x027c*/ int                         BankCopper;                   // CharBaseBegin+4a4
/*0x0280*/ int                         STR;                          // CharBaseBegin+4a8
/*0x0284*/ int                         STA;                          // CharBaseBegin+4ac
/*0x0288*/ int                         CHA;                          // CharBaseBegin+4b0
/*0x028c*/ int                         DEX;                          // CharBaseBegin+4b4
/*0x0290*/ int                         INT;                          // CharBaseBegin+4b8
/*0x0294*/ int                         AGI;                          // CharBaseBegin+4bc
/*0x0298*/ int                         WIS;                          // CharBaseBegin+4c0
/*0x029c*/ int                         SavePoison;                   // CharBaseBegin+4c4
/*0x02a0*/ int                         SaveMagic;                    // CharBaseBegin+4c8
/*0x02a4*/ int                         SaveDisease;                  // CharBaseBegin+4cc
/*0x02a8*/ int                         SaveCorruption;               // CharBaseBegin+4d0
/*0x02ac*/ int                         SaveFire;                     // CharBaseBegin+4d4
/*0x02b0*/ int                         SaveCold;                     // CharBaseBegin+4d8
/*0x02b4*/ int                         SavePhysical;
/*0x02b8*/ int                         UncappedStr;
/*0x02bc*/ int                         UncappedSta;
/*0x02c0*/ int                         UncappedCha;
/*0x02c4*/ int                         UncappedDex;
/*0x02c8*/ int                         UncappedInt;
/*0x02cc*/ int                         UncappedAgi;
/*0x02d0*/ int                         UncappedWis;
/*0x02d4*/ int                         UncappedResistPoison;
/*0x02d8*/ int                         UncappedResistMagic;
/*0x02dc*/ int                         UncappedResistDisease;
/*0x02e0*/ int                         UncappedResistCorruption;
/*0x02e4*/ int                         UncappedResistFire;
/*0x02e8*/ int                         UncappedResistCold;
/*0x02ec*/ int                         NoBuffStr;
/*0x02f0*/ int                         NoBuffSta;
/*0x02f4*/ int                         NoBuffCha;
/*0x02f8*/ int                         NoBuffDex;
/*0x02fc*/ int                         NoBuffInt;
/*0x0300*/ int                         NoBuffAgi;
/*0x0304*/ int                         NoBuffWis;
/*0x0308*/ int                         NoBuffResistPoison;
/*0x030c*/ int                         NoBuffResistMagic;
/*0x0310*/ int                         NoBuffResistDisease;
/*0x0314*/ int                         NoBuffResistCorruption;
/*0x0318*/ int                         NoBuffResistFire;
/*0x031c*/ int                         NoBuffResistCold;
/*0x0320*/ int                         NoBuffResistPhysical;
/*0x0320*/ int                         NoBuffResistPhysical2;
/*0x0320*/ int                         NoBuffResistPhysical3;
/*0x0324*/

	unsigned int GetEffectId(int index);

	LONG GetMemorizedSpell(int gem);             // 0-0xf this func returns the spellid for whatever is in the gem

	ItemGlobalIndex CreateItemGlobalIndex(int Slot0, int Slot1 = -1, int Slot2 = -1);
	ItemIndex CreateItemIndex(int Slot0, int Slot1 = -1, int Slot2 = -1);

	const BaseProfile& GetCurrentBaseProfile() const
	{
		return *ProfileManager.GetCurrentProfile();
	}

	BYTE GetLanguageSkill(int) const;
	VePointer<CONTENTS> GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex) const;
	VePointer<CONTENTS> GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex, GILocationOption Option) const;
	VePointer<CONTENTS> GetItemPossession(const ItemIndex& lIndex) const;
};

EQLIB_OBJECT char* build_token_string_PARAM(char* pBuffer, int token,
	const char* param0 = nullptr,
	const char* param1 = nullptr,
	const char* param2 = nullptr,
	const char* param3 = nullptr,
	const char* param4 = nullptr,
	const char* param5 = nullptr,
	const char* param6 = nullptr,
	const char* param7 = nullptr,
	const char* param8 = nullptr);

class EQLIB_OBJECT CharacterZoneClient : virtual public CharacterBase
{
public:
	union {
/*0x2424*/ PlayerClient*               me;                 // just here for comparing the 2, todo: fix
/*0x2424*/ PSPAWNINFO                  me2;
	};
/*0x242c*/ bool                        bUpdateStuff;
/*0x242d*/ bool                        bZoningStatProcessing;
/*0x2430*/ DWORD                       ArmorClassBonus;              // vtable2+10
/*0x2434*/ DWORD                       CurrWeight;                   // vtable2+14
/*0x2438*/ int                         LastHitPointSendPercent;
/*0x243c*/ int                         LastManaPointSendPercent;
/*0x2440*/ int                         LastEndurancePointSendPercent;
/*0x2444*/ DWORD                       HPBonus;                      // vtable2+24
/*0x2448*/ DWORD                       ManaBonus;                    // vtable2+28
/*0x244c*/ DWORD                       EnduranceBonus;               // vtable2+2c
/*0x2450*/ BYTE                        Unknown0x2450[0x4];
/*0x2454*/ DWORD                       CombatEffectsBonus;           // vtable2+34 Combat Effects in UI
/*0x2458*/ DWORD                       ShieldingBonus;               // vtable2+38 Melee Shielding in UI
/*0x245c*/ DWORD                       SpellShieldBonus;             // vtable2+3c Spell Shielding in UI
/*0x2460*/ DWORD                       AvoidanceBonus;               // vtable2+40 Avoidance in UI
/*0x2464*/ DWORD                       AccuracyBonus;                // vtable2+44 Accuracy in UI
/*0x2468*/ DWORD                       StunResistBonus;              // vtable2+48 Stun Resist in UI
/*0x246c*/ DWORD                       StrikeThroughBonus;           // vtable2+4c Strike Through in UI
/*0x2470*/ DWORD                       DoTShieldBonus;               // vtable2+50 Dot Shielding in UI
/*0x2474*/ DWORD                       DamageShieldMitigationBonus;  // vtable2+54 Damage Shield Mitig in UI
/*0x2478*/ DWORD                       DamageShieldBonus;            // vtable2+58 Damage Shielding in UI
/*0x247c*/ TSafeArrayStatic<int, 9>    ItemSkillMinDamageMod;
/*0x24a0*/ TSafeArrayStatic<int, 9>    SkillMinDamageModBonus;
/*0x24c4*/ DWORD                       HeroicSTRBonus;               // vtable2+a4
/*0x24c8*/ DWORD                       HeroicINTBonus;               // vtable2+a8
/*0x24cc*/ DWORD                       HeroicWISBonus;               // vtable2+ac
/*0x24d0*/ DWORD                       HeroicAGIBonus;               // vtable2+b0
/*0x24d4*/ DWORD                       HeroicDEXBonus;               // vtable2+b4
/*0x24d8*/ DWORD                       HeroicSTABonus;               // vtable2+b8
/*0x24dc*/ DWORD                       HeroicCHABonus;               // vtable2+bc
/*0x24e0*/ DWORD                       HeroicSvMagicBonus;           // vtable2+c0
/*0x24e4*/ DWORD                       HeroicSvFireBonus;            // vtable2+c4
/*0x24e8*/ DWORD                       HeroicSvColdBonus;            // vtable2+c8
/*0x24ec*/ DWORD                       HeroicSvDiseaseBonus;         // vtable2+cc
/*0x24f0*/ DWORD                       HeroicSvPoisonBonus;          // vtable2+d0
/*0x24f4*/ DWORD                       HeroicSvCorruptionBonus;      // vtable2+d4
/*0x24f8*/ DWORD                       HealAmountBonus;              // vtable2+d8
/*0x24fc*/ DWORD                       SpellDamageBonus;             // vtable2+dc
/*0x2500*/ int                         ItemHealAmountDotMod;
/*0x2504*/ int                         ItemSpellDamageDotMod;
/*0x2508*/ DWORD                       ClairvoyanceBonus;            // vtable2+e8
/*0x250c*/ DWORD                       AttackBonus;                  // vtable2+ec
/*0x2510*/ DWORD                       HPRegenBonus;                 // vtable2+f0
/*0x2514*/ DWORD                       ManaRegenBonus;               // vtable2+f4
/*0x2518*/ DWORD                       EnduranceRegenBonus;          // vtable2+f8
/*0x251c*/ DWORD                       AttackSpeed;                  // vtable2+fc
/*0x2520*/ //int                         ItemPotionBelt;
/*0x2520*/ int                         NoBuffItemHitpointAdjustment;
/*0x2524*/ int                         NoBuffItemManaAdjustment;
/*0x2528*/ int                         NoBuffItemEnduranceAdjustment;
/*0x252c*/ int                         NoBuffItemBaseChanceProc;
/*0x2530*/ int                         NoBuffItemMinDamageMod;
/*0x2534*/ int                         NoBuffItemInnateSpellRune;
/*0x2538*/ int                         NoBuffItemAvoidance;
/*0x253c*/ int                         NoBuffItemToHit;
/*0x2540*/ int                         NoBuffItemResistStunChance;
/*0x2544*/ int                         NoBuffItemDotShieldingEffect;
/*0x2548*/ int                         NoBuffItemStrikeThroughChance;
/*0x254c*/ int                         NoBuffItemAttack;
/*0x2550*/ int                         NoBuffItemHitPointRegen;
/*0x2554*/ int                         NoBuffItemManaRegen;
/*0x2558*/ int                         NoBuffItemEnduranceRegen;
/*0x255c*/ int                         NoBuffItemDamageShield;
/*0x2560*/ int                         NoBuffItemDamageShieldMitigation;
/*0x2564*/ int                         NoBuffItemHaste;
/*0x256c*/ //int                         NoBuffItemPotionBelt;
/*0x2568*/ TSafeArrayStatic<int, 9>    NoBuffItemSkillMinDamageMod;  // size 0x24
/*0x258c*/ bool                        bOutputHpRegen;
/*0x258d*/ bool                        bInvulnerable;
/*0x258e*/ bool                        bOnAVehicle;
/*0x2590*/ EQData::SpellCache          spellCache;                   // size 0x58
/*0x25e8*/ HashListSet<int, 0x80>      DoomEffectsBySlot;            // size 0x10 + (0x80* 4)
/*0x27f8*/ UINT                        LastHitEval;
/*0x27fc*/

	CharacterZoneClient();
	int CalcAffectChange(const EQ_Spell* spell, BYTE casterLevel, BYTE affextIndex, const EQ_Affect* theAffect, int EffectIndex = 0, PlayerZoneClient* pCaster = NULL, bool overrideChangeVal = false, int ChangeVal = -1, bool bCap = true);
	int CalcAffectChangeGeneric(const EQ_Spell* spell, BYTE casterLevel, BYTE affextIndex, const EQ_Affect* theAffect, int EffectIndex, bool bCap = true);
	void MakeMeVisible(int, bool);
	int GetItemCountWorn(int);
	int GetItemCountInInventory(int);
	int GetCursorItemCount(int);
	bool HasSkill(int);
	EQ_Affect*FindAffectSlot(int SpellID, SPAWNINFO* Caster, int* slindex, bool bJustTest, int CasterLevel = -1, EQ_Affect* BuffArray = NULL, int BuffArraySize = 0, bool bFailAltAbilities = true);
	EQ_Affect*FindAffectSlotMine(int SpellID, SPAWNINFO* Caster, int* slindex, bool bJustTest, int CasterLevel = -1, EQ_Affect* BuffArray = NULL, int BuffArraySize = 0, bool bFailAltAbilities = true);
#if !defined(ROF2EMU) && !defined(UFEMU)
	bool IsStackBlocked(const EQ_Spell* pSpell, SPAWNINFO* pCaster, EQ_Affect* pEffecs = NULL, int EffectsSize = 0, bool bMessageOn = false);
#else
	bool IsStackBlocked(const EQ_Spell* pSpell, SPAWNINFO* pCaster, EQ_Affect* pEffecs = NULL, int EffectsSize = 0);
#endif
	int BardCastBard(const EQ_Spell* pSpell, signed int caster_class) const;
	unsigned char GetMaxEffects() const;
	EQ_Affect& GetEffect(int) const;
	int GetOpenEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill, int Index = -1);
	int GetFirstEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill);
	int GetLastEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill, bool bIsDisplay = false);
	const int GetFocusReuseMod(const EQ_Spell* pSpell, VePointer<CONTENTS>& pOutItem);
	bool FindItemByGuid(const EqItemGuid& ItemGuid, int* pos_slot, int* con_slot);
	BYTE FindItemByRecord(int ItemNumber recordnum, int*pos_slot, int* con_slot, bool bReverseLookup);
};

enum EAreaCorner
{
	eAC_None                           = -1,
	eAC_TopLeftCorner                  = 0,
	eAC_TopRightCorner                 = 1,
	eAC_BottomLeftCorner               = 2,
	eAC_BottomRightCorner              = 3,
};

// work in progres
class EQLIB_OBJECT PcBase : virtual public CharacterBase
{
public:
/*0x0008*/ // void*    vfTable_CharacterZoneClient;
/*0x0008*/ // void*    vfTable_CharacterBase;
/*0x000C*/ // void*    vfTable_PcBase;
//last one changed 
/*0x000C*/ virtual void vftableph() {};

/*0x0010*/ TSafeArrayStatic<int, 0xa>            RecentTasks;
/*0x0038*/ TSafeArrayStatic<PCTaskStatus, 1>     Tasks;
/*0x00A8*/ TSafeArrayStatic<PCTaskStatus, 0x1d>  Quests;
/*0x0D58*/ TSafeArrayStatic<BYTE, 6400 / 8>      BitFlags;
/*0x1078*/ TSafeArrayStatic<BenefitSelection, 5> ActiveTributeBenefits;
/*0x10A0*/ TSafeArrayStatic<BenefitSelection, 10> ActiveTrophyTributeBenefits;
/*0x10f0*/ TSafeArrayStatic<BYTE, 0x320>         BitFlags2;
/*0x10f0*/ ItemBaseContainer                     BankItems;
/*0x110c*/ ItemBaseContainer                     SharedBankItems;
/*0x1128*/ ItemBaseContainer                     OverflowBufferItems;
/*0x1144*/ ItemBaseContainer                     LimboBufferItems;
/*0x1160*/ ItemBaseContainer                     MercenaryItems;
/*0x117c*/ ItemBaseContainer                     MountKeyRingItems;
/*0x1198*/ ItemBaseContainer                     IllusionKeyRingItems;
/*0x11b4*/ ItemBaseContainer                     FamiliarKeyRingItems;
/*0x11d0*/ ItemBaseContainer                     AltStorageItems;
/*0x11ec*/ ItemBaseContainer                     ArchivedDeletedItems;
/*0x1208*/ ItemBaseContainer                     MailItems;
/*0x1224*/ HashTable<MailItemData, EqItemGuid, ResizePolicyNoShrink> MailItemsData;
/*0x1234*/ TSafeArrayStatic<UINT, 1>             RecentMoves;
//fine to this point
/*0x1238*/ HashTable<DynamicZoneData>            CurrentDynamicZones;
/*0x1248*/ HashTable<int>                        LearnedRecipes;
/*0x1258*/ EQList<TradeskillRecipeCount*>        QualifyingRecipeCounts;
/*0x1268*/ HashTable<int>                        NonrepeatableQuests;
/*0x1278*/ HashTable<int>                        CompletedTasks;
/*0x1288*/ HashTable<int>                        CompletedTasks2;
/*0x1298*/ UINT                                  AlchemyTimestamp;
/*0x129c*/ bool                                  bWhat;
/*0x12a0*/ bool                                  bSomethingHome;
/*0x12a4*/ DWORD                                 LoginTime;
/*0x12a8*/ int64_t                               GuildID;                      // GuildID_0
/*0x12b0*/ int64_t                               FellowshipID;
/*0x12b8*/ PFELLOWSHIPINFO                       pFellowship;
/*0x12bc*/ int                                   GuildStatus;
/*0x12c0*/ int                                   GuildFlags;
/*0x12c4*/ bool                                  GuildShowSprite;
/*0x12c8*/ UINT                                  CreationTime;
/*0x12cc*/ UINT                                  AccountCreationTime;
/*0x12d0*/ UINT                                  LastPlayedTime;
/*0x12d4*/ DWORD                                 MinutesPlayed;
/*0x12d8*/ BYTE                                  Anonymous;
/*0x12d9*/ bool                                  bGM;
/*0x12da*/ bool                                  bGMStealth;
/*0x12dc*/ DWORD                                 AAExp;
/*0x12e0*/ BYTE                                  NobilityRank;
/*0x12e1*/ BYTE                                  PercentEXPtoAA;
/*0x12e4*/ int                                   AirSupply;
/*0x12e8*/ int                                   SerialNum;
/*0x12ec*/ bool                                  bNewCharacter;
/*0x12f0*/ int                                   TasksAssigned;
/*0x12f4*/ int                                   TasksCompleted;
/*0x12f8*/ long                                  TaskRequestTimer;
/*0x12fc*/ unsigned int                          UniquePlayerID;
/*0x1300*/ WorldLocation                         DynamicZoneSafeReturnLocation;
/*0x1314*/ DynamicZoneTimerData*                 pDZTimerRoot;
/*0x1318*/ DWORD                                 TributeTimer;
/*0x131c*/ DWORD                                 BenefitTimer;
/*0x1320*/ int64_t                               CareerFavor;
/*0x1328*/ int64_t                               CurrFavor;
/*0x1330*/ bool                                  bBenefitsActive;
/*0x1331*/ bool                                  bTrophyBenefitsActive;
/*0x1332*/ bool                                  bHasResetStartingCity;
/*0x1333*/ bool                                  bIsHeadStartCharacter;
/*0x1334*/ int                                   PvPKills;
/*0x1338*/ int                                   PvPDeaths;
/*0x133c*/ int                                   PvPCurrentPoints;
/*0x1340*/ int                                   PvPTotalPointsEarned;
/*0x1344*/ int                                   PvPKillStreak;
/*0x1348*/ int                                   PvPDeathStreak;
/*0x134c*/ int                                   PvPCurrentStreak;
/*0x1350*/ PvPKill                               LastKill;
/*0x13a8*/ PvPDeath                              LastDeath;
/*0x1400*/ HashTable<PvPKill24HourData>          PvPLast24HoursKillHash;
/*0x1410*/ int                                   PvPInfamyLevel;
/*0x1414*/ int                                   PvPVitality;
/*0x1418*/ UINT                                  PvPLastInfamyTime;
/*0x141c*/ int                                   LastLastNameChange;
/*0x1420*/ int                                   LastNameChangePriv;
/*0x1424*/ UINT                                  PvPLastVitalityTime;
/*0x1428*/ bool                                  bKeepItemsOnDeath;
/*0x1429*/ bool                                  bResetSpecializationSkills;
/*0x142c*/ int                                   CharityPointsAvailable;
/*0x1430*/ int                                   CharityTotalPointsEarned;
/*0x1434*/ int                                   GoodPointsAvailable;
/*0x1438*/ int                                   GoodTotalPointsEarned;
/*0x143c*/ int                                   EvilPointsAvailable;
/*0x1440*/ int                                   EvilTotalPointsEarned;
/*0x1444*/ bool                                  bCanRequestNameChange;
/*0x1445*/ bool                                  bCanRequestNameChange2;
/*0x1446*/ bool                                  bCanRequestServerTransfer;
/*0x1447*/ bool                                  bIsCopied;
/*0x1448*/ int                                   ServerTransferGrantTime;
/*0x144c*/ bool                                  bCanRequestRaceChange;
/*0x1450*/ UINT                                  LastAAResetTime;
/*0x1454*/ UINT                                  LastMercAAResetTime;
/*0x1458*/ EQZoneIndex                           NewZoneID;
/*0x145c*/ int                                   NewAreaID;
/*0x1460*/ EAreaCorner                           eNewAreaCorner;
/*0x1464*/ EQZoneIndex                           PreviousZoneID;
/*0x1468*/ int                                   RealEstateZoneID;
/*0x146c*/ char                                  ServerCreated[0x20];
/*0x1470*/ PCAdventureData                       AdventureData;
/*0x14xx*/ PCSharedTaskData                      SharedTaskData;
/*0x14xx*/ TaskTimerData*                        pTaskTimerData;
/*0x14xx*/ PCQuestHistoryData                    QuestHistoryData;
/*0x14xx*/ PCStatistics                          PcStatistics;
/*0x1954*/ GroupMemberStats                      GroupStats;
/*0x1aa4*/ bool                                  bIsLfg;
/*0x1aa8*/ int64_t                               RaidId;
/*0x1ab0*/ int64_t                               GroupID;
/*0x1ab8*/ int64_t                               Exp;
/*0x1ac0*/ int                                   DaysEntitled;
/*0x1ac4*/ int                                   SpentVeteranRewards;
/*0x1ac8*/ bool                                  bVeteranRewardEntitled;
/*0x1ac9*/ bool                                  bAutoConsentGroup;
/*0x1aca*/ bool                                  bAutoConsentRaid;
/*0x1acb*/ bool                                  bAutoConsentGuild;
/*0x1acc*/ bool                                  bPrivateForEqPlayers;
/*0x1ad0*/ long                                  AchievementFilesModificationTime;
/*0x1ad4*/ char                                  StationID[0x20];
/*0x1af8*/ EqGuid                                Guid;
/*0x1b00*/ bool                                  bBetaBuffed;
/*0x1b04*/ int                                   Unknown0x1ad4;
/*0x1b08*/ int                                   StartingCity;
/*0x1b0c*/ int                                   MainLevel;
/*0x1b10*/ bool                                  bShowHelm;
/*0x1b18*/ int64_t                               LastTestCopyTime;
/*0x1b20*/ CPlayerPointManager                   PointManager;
/*0x1b34*/ PointSystemBase                       PointSystem;
/*0x1B48*/ UINT                                  LoyaltyVelocity;
/*0x1B4c*/ UINT                                  LoyaltyTokens;
/*0x1B50*/ bool                                  bHasLoyaltyInfo;
/*0x1B54*/ ArrayClass_RO<int>                    OwnedRealEstates;
/*0x1B64*/ ArrayClass_RO<int>                    OwnedItemRealEstates;
/*0x1B74*/ ArrayClass_RO<int>                    ArchivedRealEstates;
/*0x1B84*/ char                                  OverridePetName[0x40];
/*0x1Bc4*/ bool                                  bCanRequestPetNameChange;
/*0x1Bc5*/ char                                  OverrideFamiliarName[0x40];
/*0x1c05*/ bool                                  bCanRequestFamiliarNameChange;
/*0x1c08*/ CXSTR*                                OverrideMercName[0xb];
/*0x1c34*/ bool                                  bCanRequestMercNameChange;
/*0x1c38*/ PendingRewardList                     PendingRewards;
/*0x1c64*/ UINT                                  DowntimeReductionTime;
/*0x1c68*/ UINT                                  DowntimeTimerStart;
/*0x1c6c*/ float                                 ActivityValue;
/*0x1c70*/ UINT                                  NextItemId;
/*0x1c74*/ CXSTR*                                SharedBank;
/*0x1c78*/ CXSTR*                                BankBuffer;
/*0x1c7c*/ CXSTR*                                OverflowBuffer;
/*0x1c80*/ CXSTR*                                LimboBuffer;
/*0x1c84*/ CXSTR*                                MercenaryBuffer;
/*0x1c88*/ CXSTR*                                KeyRingBuffer[3];
/*0x1c94*/ CXSTR*                                AltStorageBuffer;
/*0x1c98*/ UINT                                  AltStorageTimestamp;
/*0x1c9c*/ ELockoutCharacterReason               LCR;
/*0x1ca0*/ HashTable<ProgressionExperience>      ProgressionExp;
/*0x1cb0*/ PCXSTR                                ArchivedStorageBuffer;
/*0x1cb4*/ PCXSTR                                MailItemsBuffer;
/*0x1cb8*/ PCXSTR                                MailItemsDataBuffer;
/*0x1cbc*/ int                                   MailItemsOverCapWarningCount;
/*0x1cc0*/ ItemIndex                             StatKeyRingItemIndex[3];
/*0x1cd2*/ bool                                  UseAdvancedLooting;
/*0x1cd3*/ bool                                  MasterLootCandidate;
/*0x1cd4*/ bool                                  bIsCorrupted;
/*0x1cd8*/ char*                                 pCorruptionReport;
/*0x1cdc*/ TString<0x100>                        InspectText;
/*0x1ddc*/ HashTable<int>                        BlockedSpellsHash;
/*0x1dec*/ int                                   BlockedSpell[0x28];
/*0x1e8c*/ HashTable<int>                        BlockedPetSpellsHash;
/*0x1e9c*/ int                                   BlockedPetSpell[0x28];
/*0x1f3c*/ ClaimDataCollection                   ConsumableFeatures;
/*0x1f4c*/ bool                                  bGrantItemsRegistered;
/*0x1f50*/ uint64_t                              CreatedGuildID;
/*0x1f58*/ UINT                                  GuildCreateTime;
/*0x1f5c*/ CXSTR*                                GuildCreateCharacter;
/*0x1f60*/ bool                                  bInventoryUnserialized;
/*0x1f61*/ bool                                  bAltStorageUnserialized;
/*0x1f62*/ bool                                  bArchivedStorageUnserialized;
/*0x1f63*/ bool                                  bMailUnserialized;
/*0x1f64*/ bool                                  bPendingInventorySerialization;	
/*0x1f68*/ CXSTR*                                BuyLines;
/*0x1f6c*/ ArrayClass_RO<PCXSTR>                 OfflineTraderSoldItems;
/*0x1f7c*/ ArrayClass_RO<PCXSTR>                 OfflineBuyerBoughtItems;
/*0x1f8c*/ UINT                                  Krono;
/*0x1f90*/ UINT                                  CursorKrono;
/*0x1f98*/ int64_t                               MercAAExp;                    // divide this with 3.30f and you get the percent
/*0x1fa0*/ DWORD                                 MercAAPoints;                 // number of unspent merc AA points
/*0x1fa4*/ DWORD                                 MercAAPointsSpent;            // number of spent merc AA points
/*0x1fa8*/ ArrayClass_RO<MercenaryAbilityInfo*>  MercenaryAbilities;
/*0x1fb8*/ HashTable<CompletedAchievementData, int, ResizePolicyNoShrink>         CompletedAchievements;
/*0x1fc8*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> CompletedEventBasedSubComponents;
/*0x1fd8*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> OpenEventBasedSubComponents;
/*0x1fe8*/ int                                   LastFellowshipJoin;
/*0x1ff0*/ int64_t                               Vitality;
/*0x1ff8*/ int                                   AAVitality;
/*0x1ffc*/ int                                   Unknown0x1ffc;
/*0x2000*/ int                                   FPStuff[0x1c];
/*0x2070*/ //CharacterZoneClient
};

class EQLIB_OBJECT DebugText
{
public:
};

class EQLIB_OBJECT PcZoneClient : public PcBase, public CharacterZoneClient, public DebugText
{
public:
/*0x245c*/ void*       vfTable_PcZoneClient;
/*0x2460*/ TSafeArrayStatic<unsigned long, 3> Flags;
/*0x246C*/ uint32_t    TransfersReceived;
/*0x2470*/ int         LastLanguageSpoken;
/*0x2474*/ int         CurPowerSourceDrain;
/*0x2478*/ EQList<ALCHEMYBONUSSKILLDATA*> AlchemyBaseSkillBonusList;
/*0x2488*/ UINT        MomentumBalance; 
/*0x248C*/ UINT        LoyaltyRewardBalance;
/*0x2490*/

	int GetPcSkillLimit(int);
	bool HasCombatAbility(int);
	void RemovePetEffect(int);
	bool CanEquipItem(CONTENTS** pCont, int slotid, bool bOutputDebug, bool bUseRequiredLevel);
#if !defined(ROF2EMU) && !defined(UFEMU)
	bool HasAlternateAbility(int aaindex, int*, bool, bool);
#else
	bool HasAlternateAbility(int aaindex, int*, bool);
#endif
	int GetCurrentMod(int index);
#if !defined(ROF2EMU) && !defined(UFEMU)
	int GetModCap(int index, bool bToggle = false);
#else
	int GetModCap(int index);
#endif
	void RemoveBuffEffect(int Index, int SpawnID);
	CONTENTS** GetItemByID(CONTENTS** contOut, int itemid, ItemIndex* itemindex = nullptr);
	CONTENTS** GetItemByItemClass(CONTENTS** contOut, int itemclass, ItemIndex* itemindex = nullptr);
	void BandolierSwap(int index);
	UINT GetLinkedSpellReuseTimer(int index);
};

class EQLIB_OBJECT PcClient// : public PcZoneClient
{
	// has a vftable but we get it from PcZoneClient
public:
	PcClient();

	BYTE Filler[0x2b10];
};

class EQLIB_OBJECT EQPlayerManager
{
public:
	EQPlayer* GetSpawnByID(int);
	EQPlayer* GetSpawnByName(char*);
	EQPlayer* GetPlayerFromPartialName(const char*, PlayerBase*);
	EQPlayer* GetSpawnByName2(CXStr, int);

	SPAWNMANAGER Data;
};

class EQLIB_OBJECT EQPMInfo
{
public:
	~EQPMInfo();
	EQPMInfo(char*);
	void SetApplyGravity(bool);
};

enum SpeakerType
{
	SpeakerTypeNormal                  = 0, // AIL_3D_2_SPEAKER
	SpeakerTypeHeadphone               = 1, // AIL_3D_HEADPHONE
	SpeakerTypeSurround                = 2, // AIL_3D_SURROUND
	SpeakerTypeFour                    = 3, // AIL_3D_4_SPEAKER
	SpeakerTypeDolby51                 = 4, // AIL_3D_51_SPEAKER
	SpeakerTypeDolby71                 = 5, // AIL_3D_71_SPEAKER
}

enum EnvironmentType
{
	ENVIRONMENT_GENERIC,                // factory default
	ENVIRONMENT_PADDEDCELL,
	ENVIRONMENT_ROOM,                   // standard environments
	ENVIRONMENT_BATHROOM,
	ENVIRONMENT_LIVINGROOM,
	ENVIRONMENT_STONEROOM,
	ENVIRONMENT_AUDITORIUM,
	ENVIRONMENT_CONCERTHALL,
	ENVIRONMENT_CAVE,
	ENVIRONMENT_ARENA,
	ENVIRONMENT_HANGAR,
	ENVIRONMENT_CARPETEDHALLWAY,
	ENVIRONMENT_HALLWAY,
	ENVIRONMENT_STONECORRIDOR,
	ENVIRONMENT_ALLEY,
	ENVIRONMENT_FOREST,
	ENVIRONMENT_CITY,
	ENVIRONMENT_MOUNTAINS,
	ENVIRONMENT_QUARRY,
	ENVIRONMENT_PLAIN,
	ENVIRONMENT_PARKINGLOT,
	ENVIRONMENT_SEWERPIPE,
	ENVIRONMENT_UNDERWATER,
	ENVIRONMENT_DRUGGED,
	ENVIRONMENT_DIZZY,
	ENVIRONMENT_PSYCHOTIC,

	ENVIRONMENT_COUNT           // total number of environments
}

class EQLIB_OBJECT EqSoundManager
{
public:
	~EqSoundManager();
	EqSoundManager(bool, bool, SpeakerType);
	bool EmitterLoad(char*);
	bool WaveIsPlaying(int);
	SoundAsset* EqWaveGet(int);
	EnvironmentType GetListenerEnvironment();
	void EmitterAdd(EqEmitterData*);
	void EmitterSetIndoors(bool);
	void EmitterSetNight(bool);
	void EmitterSetRaining(bool);
	void EmitterSetUserDisabled(bool);
	void EmitterSetWind(bool);
	void GiveTime();
	void SetCurrentZone(char*);
	void SetEffectsLevel(float);
	void SetListenerEnvironment(EnvironmentType);
	void SetListenerEnvironmentHigh();
	void SetListenerEnvironmentLow();
	void SetListenerEnvironmentOutside();
	void SetListenerLocation(float, float, float, float);
	void SetMixAhead(int);
	void SetMusicSelection(int, bool);
	void SetMusicVolume(float);
	void SetWaveVolume(float);
	void WaveLoad(char*, int, bool);
	void WavePlay(int, SoundControl*);
	void WaveStop(int);

	// private
	SoundAsset* GetAsset(char*);
	SoundAsset* OldMp3GetSelection(int);
	SoundEmitter* CreateOldEmitter(int, float, float, float, int, int, int, float, int, int, int);
	int GetMusicId();
	void LoadGlobalEmitters();
	void LoadGlobalMusic();
	void LoadGlobalWaves();
	void LoadListOfWaveFiles(char**, int);
	void LoadOldEmitters();
	void OldMp3ClearSelections();
	void OldMp3Init();
	void OldMp3Terminate();
	void PlayScriptMp3(char* Name, float Vol = 1.00f);
	void ReleaseZoneSpecificEmitters();
	void ReleaseZoneSpecificMidi();
	void ReleaseZoneSpecificWaves();
	void UpdateEmitterStates();

	Mp3Manager*        pMp3Manager;
	SoundManager*      pSoundManager;
	EmitterManager*    pEmitterManager;
	MusicManager*      pMusicManager;
	SoundAsset*        pGlobalMidiAsset;
	SoundAsset*        pOpenerMidiAsset;
	SoundAsset*        pOpenerMp3Asset;
	SoundAsset*        pDeathMp3Asset;
	SoundAsset*        pCombatMp3Asset;
	SoundAsset*        pMerchantMp3Asset;
	SoundAsset*        pZoneMidiAsset;
	SoundAsset*        pScriptMp3Asset;
	bool               bDisabled;
	int                NextMusicID;
	SoundEmitter*      pEmitters[1000];
	int                EmittersCount;
	SoundEmitter*      pRainEmitter;
	SoundEmitter*      pWindEmitter;
	int                EnvironmentHigh;
	int                EnvironmentLow;
	int                EnvironmentOutside;
	float              fEffectsLevel;
	float              fWaveVolumeLevel;
	// more here but i only need volume for now so...
};

struct EQClientSwitch;
struct OldDiskSwitch;

class EQSwitch
{
public:
	~EQSwitch();
	EQSwitch(char*, bool);
	EQSwitch(EQClientSwitch*);
	EQSwitch(OldDiskSwitch*, bool);
	float GetCustomMoveDistance();
	float TopSpeed(float*);
	int GetSwitchDamage();
	unsigned char SwitchIsNotUsable(int);
	unsigned char SwitchWasOpened(int, int, PlayerClient*, bool*);
	unsigned char SwitchWasOpenedActual(int, int, PlayerClient*, bool*);
	unsigned int RepopFrequency();
	void ChangeState(unsigned char, PlayerClient*, bool);
	void LoadSwitchSounds(int);
	void PostInit();
	void PreInit();
	void RepopSwitch();
	void ResetSwitchState(unsigned char);
	void UseSwitch(UINT SpawnID, int KeyID, int PickSkill, const CVector3* hitloc = 0);
};

class EQLIB_OBJECT EqSwitchManager
{
public:
	~EqSwitchManager();
	EqSwitchManager();
	EQSwitch* GetSwitch(int);
	EQSwitch* GetSwitchByActor(CActorInterface*);
	EQSwitch* GetSwitchById(int, bool);
	int GetCount();
	void AddSwitch(EQSwitch*);
	void DeleteAll();
	void Load(char*, bool);

	// protected
	void LoadOld(char*, bool);
};

class EQLIB_OBJECT EQUtil
{
public:
	static char* FormatCharName(char*, char*, int);
};

class EQLIB_OBJECT EQWorldData
{
public:
	EQWorldData();
	bool GetGeometryNameFromIndex(EQZoneIndex, char*) const;
	bool IsFlagSet(EQZoneIndex, unsigned long) const;
	bool IsNewbieZone(EQZoneIndex) const;
	bool IsNoAirZone(EQZoneIndex) const;
	bool IsNoBindZone(EQZoneIndex) const;
	bool const AddZone(EQExpansion, EQZoneIndex, const char*, const char*, int, unsigned long, int, int);
	EQExpansion ExpansionZone(EQZoneIndex) const;
	EQZoneIndex GetIndexFromZoneName(const char*);
	int GetMinLevel(EQZoneIndex) const;
	void AdvanceTime(unsigned int);
	void CurrentGameTime(char*);
	void GetFullZoneName(EQZoneIndex, char*);

	// virtual
	~EQWorldData();
};

class EQLIB_OBJECT EQZoneInfo
{
public:
	EQZoneInfo(EQExpansion, EQZoneIndex, const char*, const char*, int, uint64_t flags, int, int);

	// virtual
	~EQZoneInfo();
};

class EQLIB_OBJECT FilePath
{
public:
	~FilePath();
	FilePath(const char*);
	FilePath(SharedString const &);
	FilePath();
};

class EQLIB_OBJECT GuildMember
{
public:
	GuildMember();
};

enum eIconCacheType
{
	eit_Items,
	eit_Spells,
	eit_Menus,
	eit_Vivox,
};

class EQLIB_OBJECT IconCache
{
public:
	HashTable<CTextureAnimation*> IconTextures;
	CXSTR*             pAnimationName;
	int                Offset;
	int                MinValue;
	int                MaxValue;

	~IconCache();
	IconCache();
	CTextureAnimation* GetIcon(int);
};

class EQLIB_OBJECT JournalNPC
{
public:
	~JournalNPC();
	JournalNPC();
	int AddEntry(long, float, float, float, char*, int);
	int AddEntry(long, float, float, float, int, int);
	int DeleteEntryByHash(int);
	int DeleteEntryByIndex(int);
	int FindThisText(char*, bool, int);
	int ReadEntry(FILE*);
	static char* GetText(int);
	JournalEntry* FindEntryByCategory(int, int);
	JournalEntry* FindEntryByHash(int);
	JournalEntry* GetEntry(int);
	void ConvertCategory(int, int);

	// private
	void AllocateArray();
	void CleanEntries();
	void ComputeLatestTime();
};

class EQLIB_OBJECT KeyCombo
{
public:
	KeyCombo(int);

	KeyCombo(unsigned char keycode, bool alt, bool ctrl, bool shift)
	{
		Data[0] = alt;
		Data[1] = ctrl;
		Data[2] = shift;
		Data[3] = keycode;
	}

	KeyCombo(unsigned int, unsigned int, bool, bool, bool);

	KeyCombo()
	{
		Data = { 0, 0, 0, 0} ;
	}

	void Clear()
	{
		Data = { 0, 0, 0, 0 };
	}

	bool UsesAlt() const
	{
		return Data[0] != 0;
	}

	bool UsesCtrl() const
	{
		return Data[1] != 0;
	}

	bool UsesShift() const
	{
		return Data[2] != 0;
	}

	uint8_t GetKey() const
	{
		return Data[3];
	}

	int operator==(const KeyCombo& Combo)
	{
		return *(uint32_t*)&Data == *(uint32_t*)&Combo.Data;
	}

	CXStr GetTextDescription() const;

	const KeyCombo& operator=(int);

	int operator int() const;
	bool GetPrintableLetter(unsigned short*) const;

	// private
	bool GetPrintableLetterFromScanCode(unsigned char, bool, bool, unsigned short*) const;
	bool GetPrintableLetterFromVirtualKey(unsigned int, unsigned int, bool, bool, unsigned short*) const;
	bool GetScanCodeFromVirtualKey(unsigned int, unsigned int, unsigned char*) const;
	bool GetVirtualKeyFromScanCode(unsigned char, int*) const;

	uint8_t Data[4];

	// actually:
	// bool Alt;
	// bool Ctrl;
	// bool Shift;
	// uint8_t KeyCode;
};

class EQLIB_OBJECT KeypressHandler
{
public:
	static KeypressHandler& Get();

	KeypressHandler();
	~KeypressHandler();
	bool AttachAltKeyToEqCommand(const KeyCombo&, unsigned int);
	bool AttachKeyToEqCommand(const KeyCombo&, unsigned int);
	bool HandleKeyDown(const KeyCombo&);
	bool HandleKeyUp(const KeyCombo&);
	const KeyCombo& GetAltKeyAttachedToEqCommand(unsigned int) const;
	const KeyCombo& GetKeyAttachedToEqCommand(unsigned int) const;
	void ResetKeysToEqDefaults();

	// private
	bool IsReservedKey(const KeyCombo&) const;
	bool LoadAndConvertOldKeymappingFormat(unsigned int, int, KeyCombo*);
	bool LoadKeymapping(unsigned int, int, KeyCombo*);
	bool MapKeyToEqCommand(const KeyCombo&, int, unsigned int);
	CXStr GetEqCommandSaveName(unsigned int, int) const;
	void ClearCommandStateArray();
	void LoadAndSetKeymappings();
	void SaveKeymapping(unsigned int, const KeyCombo&, int);

/*0x000*/ KeyCombo     NormalKey[nEQMappableCommands];
/*0x2 4*/ KeyCombo     AltKey[nEQMappableCommands];
/*0x5C8*/ char         CommandState[nEQMappableCommands];
};

class EQLIB_OBJECT LogicalPacket
{
public:
	LogicalPacket();

	// virtual
	bool IsInternalPacket() const;
	int GetRefCount() const;
	void AddRef() const;
	void Release() const;

	// protected
	virtual ~LogicalPacket();
};

struct ItemFilterData
{
/*0x00*/ int           Types;
/*0x04*/ int           ID;
/*0x08*/ int           Icon;
/*0x0c*/ char          Name[0x40];
};

class EQLIB_OBJECT LootFiltersManager
{
public:
	bool AddItemLootFilter(int ItemID, int IconID, const char* ItemName, int FilterTypes, bool bFromFile = false);
	const ItemFilterData* GetItemFilterData(int ItemID);
	bool RemoveItemLootFilter(int ItemID, int FilterTypes);
	bool SetItemLootFilter(int ItemID, int IconID, const char* ItemName, int FilterTypes, bool bKeepRndSetting, bool bScrollToIt);
};

class EQLIB_OBJECT MercenaryAbilityReq
{
public:
/*0x00*/ int           ReqGroupID;
/*0x04*/ int           ReqGroupRank;
};

class EQLIB_OBJECT MercenaryAbilitiesData
{
public:
/*0x00*/ int           AbilityID;
/*0x00*/ int           nName;
/*0x00*/ int           nDesc;
/*0x00*/ int           Cost;
/*0x00*/ int           GroupID;
/*0x00*/ int           GroupRank;
/*0x00*/ int           Type;
/*0x00*/ int           MinPlayerLevel;           // min level to purchase...
/*0x00*/ int           RequirementAssociationID;
/*0x00*/ int           Refund;
/*0x00*/ int           BetaOnly;
/*0x00*/ int           QuestAbility;
/*0x00*/ ArrayClass<MercenaryAbilityReq> AbilityReqs;
};

class EQLIB_OBJECT MercenaryAlternateAdvancementManagerClient
{
public:
	static MercenaryAlternateAdvancementManagerClient& Instance();

	HashList<int, 5>                             MercenaryTypes;
	HashList<MercenaryAbilitiesData, 0x40>       MercenaryAbilities;
	HashList<int, 0x40>                          MercenaryAbilitiesByGroupID;
	HashList<int, 0x40>                          MercenaryAbilitiesOwnedByGroupID;
	HashList<HashList<int, 0x10>, 0x40>          MercenaryAbilityGroups; 
};

class EQLIB_OBJECT EQSpellStrings
{
public:
	char* GetString(int SpellID, int StrIndex);
};

struct MapViewLabel;

class EQLIB_OBJECT MapViewMap
{
public:
	~MapViewMap();
	MapViewMap();
	bool DrawClippedLine(C3Vector*, RGB, CXRect);
	bool IsLayerVisible(int);
	bool LoadEx(char*, int);
	bool PointInMapViewArea(CXPoint, CXRect);
	int GetMaxZ();
	int GetMinZ();
	unsigned long GetCurrentColor();
	unsigned long GetMarkedLineColor();
	void AddLabel(float, float, float, unsigned long, int, char*);
	void AddPoint(float, float, float);
	void CalcLabelRenderOffsets(CXRect);
	void Clear();
	void ClearActiveLayer();
	void Draw(CXRect);
	void EndLine(float, float, float);
	void JoinLinesAtIntersect(bool);
	void Load(char*);
	void MoveLabel(MapViewLabel*, float, float, float);
	void PreCalcRenderValues();
	void RecalcLabelExtents(MapViewLabel*);
	void RemoveLabel(MapViewLabel*);
	void RemoveLabel();
	void RemoveLine(MapViewLabel*);
	void RemoveLine();
	void Save(char*);
	void SaveEx(char*, int);
	void SetCurrentColor(unsigned long);
	void SetMarkedLine(MapViewLabel*);
	void SetMarkedLineColor(unsigned long);
	void SetZoneExtents(int, int, int, int);
	void SetZoom(float);
	void StartLine(float, float, float);
	void TransformPoint(C3Vector*);
};

class EQLIB_OBJECT MemoryPoolManager
{
public:
	~MemoryPoolManager();
	MemoryPoolManager();
	void* Alloc(int);
	void Free(void*);
};

enum InstanceType
{
	InstanceTypeWave,
	InstanceTypeWave3d,
	InstanceTypeMidi,
};

class EQLIB_OBJECT MidiInstance
{
public:
	MidiInstance(SoundManager*);
	virtual ~MidiInstance();

	// virtual
	bool GiveTime();
	InstanceType GetType();
	void AdjustVolume(float, int);
	void GuaranteeStopped();
	void Move(float, float, float);
	void Play(SoundControl*);
};

enum StreamingStatus
{
	StreamingStatusDone,
	StreamingStatusPlaying,
	StreamingStatusStopped,
};

class EQLIB_OBJECT Mp3Manager
{
public:
	class Entry
	{
	public:
		Entry(char*, char*, int, int);
		~Entry()
	};

	enum SortOrder
	{
		SortOrderNormal,
		SortOrderRandom,
	};

	Mp3Manager(SoundManager*, MusicManager*);
	~Mp3Manager();

	char* GetName(int);
	SortOrder GetSort();
	StreamingStatus Status();
	float GetVolumeLevel();
	int Add(char*);
	int Count();
	int GetPosition();
	int GetSongLength();
	int GetSongPosition();
	void Back();
	void Delete(int);
	void DeleteAll();
	void GiveTime();
	void Next();
	void Pause();
	void Play();
	void SaveList(char*);
	void SetPosition(int);
	void SetSongPosition(int);
	void SetVolumeLevel(float);
	void Sort(SortOrder);
	void Stop();

	// private
	int InternalAdd(char*, char*, int);
};

class EQLIB_OBJECT MusicManager
{
public:
	class MusicEntry
	{
	public:
		MusicEntry(int, SoundAsset*, int, float, int, int, int, int, int, int);
		~MusicEntry();

		void AdjustVolume(float);
		void FadeIn(float);
		void FadeOut(bool);
	};

	~MusicManager();
	MusicManager();
	void Clear(SoundAsset*);
	void Clear(int);
	void Enable(bool);
	void GiveTime();
	void Play(int);
	void Set(int, SoundAsset*, int, float, int, int, int, int, int, int);
	void SetVolumeLevel(float);
	void Stop(int);
};

class EQLIB_OBJECT SFormattedText
{
public:
	~SFormattedText();
	SFormattedText();
};

class EQLIB_OBJECT ShareBase
{
public:
	void removeRef();

	// virtual
	~ShareBase();
};

class EQLIB_OBJECT SharedString
{
public:
	~SharedString();
	SharedString(const char*);
	SharedString& operator=(const SharedString&);

	// protected
	void _updateTag() const;
};

class EQLIB_OBJECT SHistoryElement
{
public:
	~SHistoryElement();
	SHistoryElement();
};

class EQLIB_OBJECT SimpleLogicalPacket
{
public:
	SimpleLogicalPacket(const void*, int);

	// virtual
	int GetDataLen() const;
	void* GetDataPtr();
	void SetDataLen(int);
	const void* GetDataPtr() const;

	// protected
	virtual ~SimpleLogicalPacket();
};

class EQLIB_OBJECT SListWndCellEditUpdate
{
public:
	~SListWndCellEditUpdate();
};

class EQLIB_OBJECT SListWndSortInfo
{
public:
/*0x00*/ int           SortCol;
/*0x04*/ const SListWndLine& ListWndLine1;
/*0x08*/ CXSTR*        StrLabel1;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x10*/ uint64_t      Data1;
#else
/*0x0c*/ uint32_t      Data1;
#endif
/*0x18*/ const SListWndLine& ListWndLine2;
/*0x1c*/ CXSTR*        StrLabel2;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x20*/ uint64_t      Data2;
#else
/*0x18*/ uint32_t      Data2;
#endif
/*0x28*/ int           SortResult;
/*0x2c*/ 
	~SListWndSortInfo();
};

class EQLIB_OBJECT SoundAsset
{
public:
	SoundAsset(SoundManager*, char*, char*, int);
	bool IsPlaying();
	char* GetName();
	SoundInstance* Play(SoundControl*);
	// enum AssetType GetType();
	void AdjustVolume(float, int);
	void GiveTime();
	void Stop();

	// protected
	virtual ~SoundAsset();
	void YourManagerDeleted();
};

class EQLIB_OBJECT SoundControl
{
public:
	SoundControl();
};

class EQLIB_OBJECT SoundEmitter
{
public:
	SoundEmitter(EmitterManager*, MusicManager*, int);
	SoundEmitter(EmitterManager*, SoundAsset*, int);
	void Enable(bool);
	void GiveTime();
	void Move(float, float, float);
	void SetAsset(SoundAsset*);

	// protected
	virtual ~SoundEmitter();
	void Init();
	void ReleaseLoopingSound();
	void ResetTimer();
};

class EQLIB_OBJECT SoundInstance
{
public:
	SoundInstance(SoundManager*);

	// virtual
	void SetPoolNumber(int);
	void SetSoundAsset(SoundAsset*);

	// protected
	virtual ~SoundInstance();
	void YourManagerDeleted();
};

class EQLIB_OBJECT SoundManager
{
public:
	~SoundManager();
	// SoundManager(int, int, bool, int, int, bool, enum SpeakerType);
	SoundAsset* AssetGet(char*);
	// SoundInstance* BorrowInstance(enum InstanceType, int);
	// enum EnvironmentType GetListenerEnvironment();
	// enum StreamingStatus StreamingStatus();
	float StreamingGetVolumeLevel();
	int StreamingGetSongLength();
	int StreamingGetSongPosition();
	// void AddPool(enum InstanceType, int, int);
	void GetListenerLocation(float*, float*, float*, float*);
	void GiveTime();
	void ReturnInstance(SoundInstance*);
	// void SetListenerEnvironment(enum EnvironmentType);
	void SetListenerLocation(float, float, float, float);
	void SetMixAhead(int);
	void StreamingPause();
	void StreamingPlay(char*);
	void StreamingSetSongPosition(int);
	void StreamingSetVolumeLevel(float);
	void StreamingStop();

	// protected
	void AssetAdd(SoundAsset*);
	void AssetGiveTime();
	void AssetRemove(SoundAsset*);
};

class EQLIB_OBJECT SoundObject
{
public:
	SoundObject();
	void AddRef();
	void Release();

	// protected
	virtual ~SoundObject();
};

class EQLIB_OBJECT SParseVariables
{
public:
	~SParseVariables();
};

class EQLIB_OBJECT FileStatMgr
{
public:
	struct FileStat
	{
		struct _stat32 Stats;
		CXSTR*         Filename;
		CXSTR*         Key;
	};

	HashTable<FileStat*> FileStats;
};

enum ReqType
{
	RT_None,
	RT_Sex,
	RT_MinLevel,
	RT_MaxLevel,
	RT_LevelRange,
	RT_Class,
	RT_Race,
	// there are like 72 more of these I dont have time to add them all now.
};

class EQLIB_OBJECT RequirementAssociationManager : public FileStatMgr
{
public:
	void*              vfTable;
	HashTable<HashTable<DoublyLinkedList<int>*>*> Requirements;
	char               AssocFilename[512];
	ReqType            LastFailReason;
	int                LastFailGroupID;
	int                LastFailReqID;
};

class SpellRequirementAssociationManager : public RequirementAssociationManager
{
public:
	HashList<HashList<HashList<int, 10>, 10>, 1000> ReqAssData;
};

struct EQRGB
{
	BYTE               Red;
	BYTE               Green;
	BYTE               Blue;
};

struct StageType
{
	char               BlitSprite[3][0x20];
	char               AttachTag[0x20];
	int                DAGnum[3];
	int                pcloud[3];
	char               SpriteTAG[0xc][0x20];
	int                SpritEffect;
	int                SoundNum;
	ARGBCOLOR          Tint[3];
	float              Gravity[3];
	float              NormalX1;
	float              NormalY1;
	float              NormalZ1;
	float              NormalX2;
	float              NormalY2;
	float              NormalZ2;
	float              NormalX3;
	float              NormalY3;
	float              NormalZ3;
	float              Radius[3];
	float              Angle[3];
	ULONG              Lifespan[3];
	float              Velocity[3];
	ULONG              Rate[3];
	float              Scale[3];
	EQRGB              SpriteRGB[0xc];
	float              RollRate[0xc];
	short              HdgOffset[0xc];
	short              PitchOffset[0xc];
	float              Distance[0xc];
	short              EffectType[12];
	float              ScaleFactor[12];
};

struct OldSpellEffect
{
	int                Tgts;
	int                Perm;
	StageType          stages[3];
};

enum EEffectActor
{
	EEA_None,
	EEA_Caster,
	EEA_Missile,
	EEA_Target,
	EEA_COUNT,
};

enum EAttachPoint
{
	EAP_None,
	EAP_Default,
	EAP_Chest,
	EAP_Head,
	EAP_LeftHand,
	EAP_RightHand,
	EAP_LeftFoot,
	EAP_RightFoot,
	EAP_Weapon,
	EAP_LeftEye,
	EAP_RightEye,
	EAP_Mouth,
	EAP_Ground,
	EAP_Cnt,
};

struct SpellEffectEmitter
{
	int DefIndex;
	int RequiredLevel;
	EEffectActor EffectActor;
	EAttachPoint AttachPoint;
};

struct SpellEffectStage
{
	int                SoundNum;
	SpellEffectEmitter Emitters[4];
};

struct NewSpellEffect
{
	char               szSpellEffectName[0x40];
	SpellEffectStage   Stages[3];
};

class EQSpellExtra
{
public:
	OldSpellEffect*    OldSpellEff;
	NewSpellEffect*    NewSpellEff;
};

//Matching stack group ID rules
enum ESpellStackingRules
{
	ESSR_None,                                   // default
	ESSR_SingleCaster,
	ESSR_AllCasters,
	ESSR_SingleCasterOnlyGreater,
	ESSR_AllCastersOnlyGreater,
	ESSR_SingleCasterNeverOverwrite,
	ESSR_AllCastersNeverOverwrite,
	ESSR_SingleCasterAlwaysOverwrite,
	ESSR_AllCastersAlwaysOverwrite,
	ESSR_Invalid,
};

struct StackingGroupData
{
	int StackingGroupID;
	int StackingGroupRank;
	ESpellStackingRules StackingGroupRuleType;
};

// really would like to get this to work and align but its kinda complicated, maybe another day.
class EQLIB_OBJECT SpellManager : public FileStatMgr
{
public:
/*0x000000*/ void*    vfTable;
/*0x000004*/ int      SpellsCrc32[TOTAL_SPELL_COUNT+1];
/*0x03A988*/ PSPELL   MissingSpell;
/*0x03A98c*/ PSPELLCALCINFO* MissingSpellAffect;
/*0x03A990*/ PSPELLCALCINFO* MissingSpellAffectAC;
/*0x03A994*/ int      MissingSpellCrc32;
/*0x03A998*/ int      SpellFileCRC;
/*0x03A99c*/ int      SpellAssocFileCRC;
/*0x03A9A0*/ int      SpellStackingFileCRC;
/*0x03A9A4*/ SpellRequirementAssociationManager ReqAssocManager;
/*0x03BB8C*/ HashTable<int, int, ResizePolicyNoShrink> SpellGroups;
/*0x03BB9C*/

	SpellManager(char*);
	const EQ_Spell* GetSpellByGroupAndRank(int Group, int SubGroup, int Rank = -1, bool bLesserRanksOk = false);
};

class EQLIB_OBJECT ClientSpellManager : public SpellManager
{
public:
	// virtual
	// ~ClientSpellManager();
	bool LoadSpells(const char* FileName, const char* AssocFilename, const char* StackingFileName);
	bool LoadSpellStackingData(const char* StackingFileName);
#if !defined(ROF2EMU) && !defined(UFEMU)
	bool DoesMeetRequirement(PlayerZoneClient* pPlayer, int SpellAssocID);
#endif
	void PrintFailedRequirementString(int StrToken, int StringID);
	int GetSpellStackingGroupID(int SpellID);
	int GetSpellStackingGroupRank(int SpellID);
	ESpellStackingRules GetSpellStackingGroupRule(int SpellID);
	PSPELL GetSpellByID(int SpellID);
	SPELLCALCINFO* GetSpellAffect(int index);
	bool GetSpellAffectEmpty(bool);

/*0x03BBAC*/ SPELL*    Spells[TOTAL_SPELL_COUNT+1];        // 60001 last one is the unknown spell...
/*0x076530*/ SPELLCALCINFO* CalcInfo[CalcInfoSize];        // 175000
	EQSpellExtra       SpellExtraData[TOTAL_SPELL_COUNT+1];
	HashTable<StackingGroupData> StackingData;
};

class EQLIB_OBJECT STable
{
public:
	~STable();
	STable();
	STable& operator=(const STable&);
};

class EQLIB_OBJECT STableCell
{
public:
	~STableCell();
	STableCell();
};

class EQLIB_OBJECT STempTable
{
public:
	~STempTable();
};

class EQLIB_OBJECT STempTableCell
{
public:
	~STempTableCell();
	STempTableCell();
};

class EQLIB_OBJECT STempTableRow
{
public:
	~STempTableRow();
	STempTableRow();
};

class EQLIB_OBJECT StringItem
{
public:
	~StringItem();
	StringItem();
	int load(FILE*, int);
};

class EQLIB_OBJECT StringTable
{
public:
	~StringTable();
	StringTable();
	char* getString(unsigned long ID, bool* bFound = nullptr);
	int load(const char*, int);
	void addItem(StringItem*);

	// private
	StringItem* findItem(unsigned long, int, int);
	void checkAlloc();
};

class EQLIB_OBJECT TextFileReader
{
public:
	~TextFileReader();
	TextFileReader(char*, char);
	bool IsOpen();
	int GetNextField(char*, int);
	int ReadLine();
	void GetLine(char*, int);
};

class EQLIB_OBJECT UdpConnection
{
public:
	// bool Send(enum UdpChannel, const void*, int);
	int ConnectionAge() const;
	int LastReceive() const;
	int TotalPendingBytes() const;
	void FlushMultiBuffer();
	// void GetChannelStatus(enum UdpChannel, struct ChannelStatus*) const;
	void PingStatReset();
	void Release();
	void SetSilentDisconnect(bool);

	// protected
	UdpConnection(UdpManager*, UdpIpAddress, int, int);
	// UdpConnection(class UdpManager*, class PacketHistoryEntry const*);
	void GiveTime();
	void PortUnreachable();
	// void ProcessRawPacket(class PacketHistoryEntry const*);

	// private
	~UdpConnection();
	// bool InternalSend(enum UdpChannel, unsigned const char*, int, unsigned const char*, int);
	bool IsNonEncryptPacket(unsigned const char*) const;
	int DecryptNone(unsigned char*, unsigned const char*, int);
	int DecryptUserSupplied(unsigned char*, unsigned const char*, int);
	int DecryptUserSupplied2(unsigned char*, unsigned const char*, int);
	int DecryptXor(unsigned char*, unsigned const char*, int);
	int DecryptXorBuffer(unsigned char*, unsigned const char*, int);
	int EncryptNone(unsigned char*, unsigned const char*, int);
	int EncryptUserSupplied(unsigned char*, unsigned const char*, int);
	int EncryptUserSupplied2(unsigned char*, unsigned const char*, int);
	int EncryptXor(unsigned char*, unsigned const char*, int);
	int EncryptXorBuffer(unsigned char*, unsigned const char*, int);
	int ExpireReceiveBin();
	int ExpireSendBin();
	unsigned char* BufferedSend(unsigned const char*, int, unsigned const char*, int, bool);
	// void CallbackCorruptPacket(unsigned const char*, int, enum UdpCorruptionReason);
	void CallbackRoutePacket(unsigned const char*, int);
	void Init(UdpManager*, UdpIpAddress, int);
	// void InternalDisconnect(int, enum DisconnectReason);
	void InternalGiveTime();
	void PhysicalSend(unsigned const char*, int, bool);
	void ProcessCookedPacket(unsigned const char*, int);
	void RawSend(unsigned const char*, int);
	void ScheduleTimeNow();
	// void SendTerminatePacket(int, enum DisconnectReason);
	void SetupEncryptModel();
};

class EQLIB_OBJECT UdpConnectionHandler
{
public:
	// virtual
	void OnConnectComplete(UdpConnection*);
	void OnCrcReject(UdpConnection*, unsigned const char*, int);
	// void OnPacketCorrupt(UdpConnection*, unsigned const char*, int, enum UdpCorruptionReason);
	void OnTerminated(UdpConnection*);
};

class EQLIB_OBJECT UdpIpAddress
{
public:
	UdpIpAddress(unsigned int);
};

class EQLIB_OBJECT UdpManager
{
public:
	class PacketHistoryEntry
	{
	public:
		PacketHistoryEntry(int);
		~PacketHistoryEntry();
	};

	class Params
	{
	public:
		Params();
	};

	// UdpManager(struct Params const*);
	bool GiveTime(int, bool);
	class LogicalPacket* CreatePacket(const void*, int, const void*, int);
	class UdpConnection* EstablishConnection(const char*, int, int);
	void Release();
	void ResetStats();

	// protected
	class UdpConnection* AddressGetConnection(class UdpIpAddress, int) const;
	class UdpConnection* ConnectCodeGetConnection(int) const;
	// class PacketHistoryEntry* ActualReceive();
	class WrappedLogicalPacket* WrappedBorrow(class LogicalPacket const*);
	void ActualSend(unsigned const char*, int, class UdpIpAddress, int);
	void ActualSendHelper(unsigned const char*, int, class UdpIpAddress, int);
	void AddConnection(class UdpConnection*);
	void CloseSocket();
	void CreateAndBindSocket(int);
	void KeepUntilDisconnected(class UdpConnection*);
	void PoolCreated(class PooledLogicalPacket*);
	void PoolDestroyed(class PooledLogicalPacket*);
	void PoolReturn(class PooledLogicalPacket*);
	void ProcessDisconnectPending();
	void ProcessIcmpErrors();
	// void ProcessRawPacket(class PacketHistoryEntry const*);
	void RemoveConnection(class UdpConnection*);
	void SendPortAlive(class UdpIpAddress, int);
	void WrappedCreated(class WrappedLogicalPacket*);
	void WrappedDestroyed(class WrappedLogicalPacket*);
	void WrappedReturn(class WrappedLogicalPacket*);

	// private
	~UdpManager();
};

class EQLIB_OBJECT UdpMisc
{
public:
	static int64_t Clock();
	static int64_t GetValue64(const void*);
	static LogicalPacket* CreateQuickLogicalPacket(const void*, int, const void*, int);
	static int Crc32(const void*, int, int);
	static int PutValue24(void*, unsigned int);
	static int PutValue32(void*, unsigned int);
	static int PutValue64(void*, int64_t);
	static int Random(int*);
	static int SyncStampShortDeltaTime(unsigned short, unsigned short);
	static unsigned int GetValue24(const void*);
	static unsigned int GetValue32(const void*);
	static unsigned int GetVariableValue(const void*, unsigned int*);
	static unsigned int PutVariableValue(void*, unsigned int);
};

class EQLIB_OBJECT UdpReliableChannel
{
public:
	class IncomingQueueEntry
	{
	public:
		~IncomingQueueEntry();
		IncomingQueueEntry();
	};

	class PhysicalPacket
	{
	public:
		PhysicalPacket();
		~PhysicalPacket();
	};

	// protected
	int64_t GetReliableIncomingId(int) const;
	~UdpReliableChannel();
	// UdpReliableChannel(int, class UdpConnection*, struct ReliableConfig*);
	bool PullDown(int);
	int GiveTime();
	void Ack(int64_t);
	void AckAllPacket(unsigned const char*, int);
	void AckPacket(unsigned const char*, int);
	void FlushCoalesce();
	void QueueLogicalPacket(const LogicalPacket*);
	void ReliablePacket(unsigned const char*, int);
	void Send(unsigned const char*, int, unsigned const char*, int);
	void SendCoalesce(unsigned const char*, int, unsigned const char*, int);
};

class EQLIB_OBJECT Wave3dInstance
{
public:
	Wave3dInstance(SoundManager*);

	// virtual
	bool GiveTime();
	enum InstanceType GetType();
	void AdjustVolume(float, int);
	void GuaranteeStopped();
	void Move(float, float, float);
	void Play(SoundControl*);

	// protected
	virtual ~Wave3dInstance();
};

class EQLIB_OBJECT WaveInstance
{
public:
	WaveInstance(SoundManager*);

	// virtual
	bool GiveTime();
	// enum InstanceType GetType();
	void AdjustVolume(float, int);
	void GuaranteeStopped();
	void Move(float, float, float);
	void Play(SoundControl*);

	// protected
	virtual ~WaveInstance();
};

class EQLIB_OBJECT WrappedLogicalPacket
{
public:
	WrappedLogicalPacket(UdpManager*);

	// virtual
	int GetDataLen() const;
	void* GetDataPtr();
	void AddRef() const;
	void Release() const;
	void SetDataLen(int);
	const void* GetDataPtr() const;

	// protected
	virtual ~WrappedLogicalPacket();
	void SetLogicalPacket(LogicalPacket const*);
};

class EQLIB_OBJECT ZlibUtil
{
public:
	static int Compress(const char*, int, char*, int, int);
	static int Decompress(const char*, int, char*, int);

	// private
	static MemoryPoolManager sMemoryPoolManager;
	static int zcompress(unsigned char*, unsigned long*, unsigned const char*, unsigned long, int);
	static int zuncompress(unsigned char*, unsigned long*, unsigned const char*, unsigned long);
	static void* zcalloc(void*, unsigned int, unsigned int);
	static void zfree(void*, void*);
};

class EQLIB_OBJECT ZoneNPCLoadTextManager
{
public:
	~ZoneNPCLoadTextManager();
	ZoneNPCLoadTextManager(char*);
	char* GetNPCCode(int);
	char* GetS3DName(int);
	void LoadText(char*);
};

class EQLIB_OBJECT CTextOverlay
{
public:
	void DisplayText(const char* Str, int TextColor, int Priority, int MaxAlpha, UINT FadeInTime, UINT FadeOutTime, UINT DisplayTime);
}; 

class EQLIB_OBJECT DatabaseStringTable
{
public:
	const char* GetString(int id, int type, bool* found = nullptr);
};
using CDBStr = DatabaseStringTable;

class EQLIB_OBJECT CCombatAbilityWnd : public CSidlScreenWnd
{
public:
	CCombatAbilityWnd(CXWnd*);
	void Activate(int);
	void Deactivate();
	int OnProcessFrame();
	int WndNotification(CXWnd*, uint32_t, void*);
	~CCombatAbilityWnd();
};

class EQLIB_OBJECT EQMisc
{
public:
	int GetActiveFavorCost();
};

class EQLIB_OBJECT CSkillMgr
{
public:
	unsigned long GetNameToken(int);
	unsigned long GetSkillCap(EQ_Character*, int, int, int, bool, bool, bool);
	unsigned long SkillAvailableAtLevel(int, int);
	bool IsActivatedSkill(int);
	unsigned long GetBaseDamage(int);
	unsigned long GetReuseTime(int);
	bool IsAvailable(int);
	bool IsCombatSkill(int);
};

class EQLIB_OBJECT CChatService
{
public:
	int GetNumberOfFriends();
	char* GetFriendName(int);
};

class EQLIB_OBJECT PlayerPointManager
{
public:
	unsigned long GetAltCurrency(unsigned long, unsigned long b = 1);
};

enum eZoneGuideConnectionsView
{
	eZGCV_None,
	eZGCV_Selected,
	eZGCV_PreviewPath,
	eZGCV_ActivePath,
	eZGCV_Disabled,
};

class EQLIB_OBJECT ZoneGuideConnection
{
public:
	EQZoneIndex        DestZone;
	int                TransferTypeIndex;
	int                RequiredExpansions;       // EQExpansionOwned
	bool               bDisabled;
};

class EQLIB_OBJECT ZoneGuideZone
{
public:
/*0x00*/ EQZoneIndex   ID;
/*0x04*/ CXSTR*        Name;
/*0x08*/ int           ContinentIndex;
/*0x0C*/ int           MinLevel;
/*0x10*/ int           MaxLevel;
/*0x14*/ DynamicBitField<unsigned short, short> Types;
/*0x1C*/ ArrayClass_RO<ZoneGuideConnection> ZoneConnections;
/*0x2C*/ // see 8E87D6 in Apr 15 2019 exe
};

class EQLIB_OBJECT ZoneGuideContinent
{
public:
	int                ID;
	int                DisplaySequence;
	CXSTR*             Name;
};

class EQLIB_OBJECT ZoneGuideZoneType
{
public:
	int                ID;
	int                DisplaySequence;
	CXSTR*             Name;
};

class EQLIB_OBJECT ZoneGuideTransferType
{
public:
	int                ID;
	CXSTR*             Description;
};

// see 8D35C1 in may 10 2018 exe
// see 8E87D1 in Apr 15 2019 exe
#if defined(ROF2EMU) || defined(UFEMU)
// see 7FEC8D
#define ZONE_COUNT 768
#else
#define ZONE_COUNT 836
#endif

class EQLIB_OBJECT ZoneGuideManagerBase
{
public:
/*0x0000*/ void*       vfTable;
/*0x0004*/ ZoneGuideZone Zones[ZONE_COUNT];
/*0x8FB4*/ ArrayClass_RO<ZoneGuideContinent> Continents;
/*0x8FC4*/ ArrayClass_RO<ZoneGuideZoneType> ZoneTypes;
/*0x8FD4*/ ArrayClass_RO<ZoneGuideTransferType> TransferTypes;
/*0x8FE4*/
};

struct ZonePathData
{
	EQZoneIndex        ZoneID;
	int                TransferTypeIndex;
};
using PZonePathData = ZonePathData*;

// size: 0x9010 see 6AB098 in Apr 15 2019 exe
// todo: fix this for the rof2 emu client...
class EQLIB_OBJECT ZoneGuideManagerClient : public ZoneGuideManagerBase
{
public:
/*0x8FE4*/ ArrayClass_RO<ZonePathData> ActivePath;
/*0x8FF4*/ ArrayClass_RO<ZonePathData> PreviewPath;
/*0x9004*/ EQZoneIndex CurrZone;
/*0x9008*/ int         HerosJourneyIndex;
/*0x900C*/ bool        bZoneGuideDataSet;
/*0x900D*/ bool        bIncludeBindZoneInPath;
/*0x900E*/ bool        bAutoFindActivePath;
/*0x900F*/ bool        bFindActivePath;
/*0x9010*/

	static ZoneGuideManagerClient& Instance();
};

class EQLIB_OBJECT CZoneGuideWnd : public CSidlScreenWnd, public WndEventHandler2
{
public:
	void*              VerticalLayout;           // CVerticalLayoutWnd
	CButtonWnd*        FilterMyLevelButton;
	CButtonWnd*        FilterAllLevelsButton;
	CButtonWnd*        FilterZonesActiveButton;
	CButtonWnd*        FilterZonesInactiveButton;
	CButtonWnd*        ZoneRunSearchButton;
	CButtonWnd*        ZoneClearSearchButton;	
	CButtonWnd*        SelectCurrentZoneButton;
	CEditWnd*          LevelFilterEdit;
	CEditWnd*          ZoneSearchEdit;
	CComboWnd*         TypeFilterCombo;
	CComboWnd*         ContinentFilterCombo;
	CListWnd*          ZonesList;
	CLabelWnd*         ViewZoneConnectionsSelectedZoneLabel;
	CLabelWnd*         ViewZoneConnectionsPreviewPathLabel;
	CLabelWnd*         ViewZoneConnectionsActivePathLabel;
	CLabelWnd*         ViewZoneConnectionsDisabledLabel;
	CButtonWnd*        ViewZoneConnectionsSelectedZoneButton;
	CButtonWnd*        ViewZoneConnectionsPreviewPathButton;
	CButtonWnd*        ViewZoneConnectionsActivePathButton;
	CButtonWnd*        ViewZoneConnectionsDisabledButton;
	CButtonWnd*        DisableConnectionTemplateButton;
	CListWnd*          ZoneConnectionsList;
	CButtonWnd*        ResetPathStartZoneButton;
	CButtonWnd*        SetPathStartZoneButton;
	CButtonWnd*        SetPathEndZoneButton;
	CButtonWnd*        ShowPathWndButton;
	CButtonWnd*        HidePathWndButton;
	CButtonWnd*        FindPathButton;
	CButtonWnd*        EndFindButton;
	CButtonWnd*        ClearPathWndButton;
	CButtonWnd*        ActivatePathButton;
	CButtonWnd*        IncludeBindZoneInPathGenerationButton;
	CButtonWnd*        ShowPathWndOnPathActivationButton;
	CButtonWnd*        AutoFindActivePathButton;
	CEditWnd*          PathStartZoneEdit;
	CEditWnd*          PathEndZoneEdit;
	UINT               NextButtonRefreshTime;
	EQZoneIndex        eCurrentZone;
	bool               bFilterActive;
	int                FilterLevel;
	int                FilterContinentIndex;
	int                FilterZoneTypeIndex;
	bool               bSelectCurrentZone;
	CXSTR*             ZoneSearchString;
	eZoneGuideConnectionsView eCurrConnectionsView;
	EQZoneIndex        CurrConnectionsViewSelectedZone;
	bool               bCurrentConnectionsViewPreviewPathChanged;
	bool               bCurrentConnectionsViewActivePathChanged;
	bool               bSetPathStartZoneToCurrentZone;
	EQZoneIndex        StartZone;
	EQZoneIndex        EndZone;
	bool               bZoneGuideDataChanged;
	bool               bZoneListChanged;
	bool               bZoneConnectionsListChanged;
	bool               bPathStartZoneChanged;
	int                RightClickMenuID;
};

enum eKeyboardMode
{
	Typing,
	KBM_Command,
};

#pragma pack(push)
#pragma pack(4)

struct EVERQUESTINFO
{
/*0x00000*/	HWND       Wnd;
/*0x00004*/ HINSTANCE  hInst;
/*0x00008*/	int        Render_MinX;
/*0x0000c*/	int        Render_MinY;
/*0x00010*/	int        Render_MaxX;
/*0x00014*/	int        Render_MaxY;
/*0x00018*/	int        Render_XScale;
/*0x0001c*/	int        Render_YScale;
/*0x00020*/	int        Render_WidthScale;
/*0x00024*/	int        Render_HeightScale;
/*0x00028*/	int        ReadyEnterWorld;
/*0x0002c*/	bool       InsideDoMainWhileLoop;
/*0x00030*/	int        Hidden;
/*0x00034*/ DWORD      Displayflags;
/*0x00038*/ DWORD      Command;
/*0x0003c*/	BYTE       Unknown0x0003c;
/*0x00040*/	int        ScreenXRes;
/*0x00044*/	int        ScreenYRes;
/*0x00048*/	int        WindowXOffset;
/*0x0004c*/	int        WindowYOffset;
/*0x00050*/	BOOL       FullscreenMode;
/*0x00054*/	eKeyboardMode KeyboardMode;
/*0x00058*/	BYTE       Runmode;                  // dont EVER set this to something > 1 unless you WANT to get banned.
/*0x00059*/	BYTE       Unknown0x00059;
/*0x0005a*/	BYTE       Unknown0x0005a;
/*0x0005b*/	BYTE       MouseCntrl;
/*0x0005c*/	BYTE       MouseActive;
/*0x0005d*/	BYTE       ForceCrouch;
/*0x00060*/	UINT       ForceCrouchTimer;
/*0x00064*/	float      Unknown0x00064;
/*0x00068*/	float      Unknown0x00068;
/*0x0006c*/	int        MouseX;
/*0x00070*/	int        MouseY;
/*0x00074*/	int        MouseZ;
/*0x00078*/	int        Lastmx;
/*0x0007c*/	int        Lastmy;
/*0x00080*/	bool       MouseInClientRect;
/*0x00084*/ int        MXSensitivity;
/*0x00088*/ int        MYSensitivity;
/*0x0008c*/	int        MousePointerSpeedMod;
/*0x00090*/	bool       ServerFilter;
/*0x00094*/	int        IsTrader;
/*0x00098*/	BYTE       CurrentChan;
/*0x0009c*/	int        CurrentLang;
/*0x000a0*/	char       TellTarget[0x40];
/*0x000e0*/	UINT       LastMinute;
/*0x000e4*/	UINT       LastLocal;
/*0x000e8*/	UINT       LastControlled;
/*0x000ec*/	BYTE       MInverse;
/*0x000ed*/	BYTE       Unknown0x000ed;
/*0x000ee*/	BYTE       MouseLook;
/*0x000ef*/	bool       bDefaultMouseLook;
/*0x000f0*/	BYTE       Strafe;
/*0x000f1*/	bool       bNetstat;
/*0x000f2*/	BYTE       ModInventory;
/*0x000f4*/	UINT       LastHitter;
/*0x000f8*/	BYTE       Harmless;
/*0x000f9*/	BYTE       Silenced;
/*0x000fc*/	UINT       JumpTimer;
/*0x00100*/	UINT       EventJump;
/*0x00104*/	UINT       LastJump;
/*0x00108*/	UINT       FrameTime;
/*0x0010c*/	int        AutoRun;
/*0x00110*/	UINT       PoisonTimer;
/*0x00114*/	ItemGlobalIndex2 PoisonGI;
/*0x00120*/	int        OldX;
/*0x00124*/	int        OldY;
/*0x00128*/	BYTE       OldMouseButtons[8];
/*0x00130*/	BYTE       MouseButtons[8];
/*0x00138*/	bool       bIsMouseRightHanded;
/*0x0013c*/	int        Unknown0x0013c;
/*0x00140*/	int        CharStatePending;
/*0x00144*/	char       PendingCharacterName[0x40];
/*0x00184*/	int        TutorialMode;
/*0x00188*/	int        RMouseSecond;
/*0x0018c*/	int        LMouseSecond;
/*0x00190*/	UINT       RMouseDown;
/*0x00194*/	UINT       LMouseDown;
/*0x00198*/	char       Unknown0x00198[0x40];
/*0x001d8*/	UINT       DuelTarget;
/*0x001dc*/	UINT       DuelMe;
/*0x001e0*/	BYTE       DuelOn;
/*0x001e4*/	UINT       AutoHelp;
/*0x001e8*/	BYTE       OldMouseLook;
/*0x001ec*/	UINT       LastLocalUpdate;
/*0x001f0*/	UINT       LastControlledUpdate;
/*0x001f4*/	UINT       DataRate;
/*0x001f8*/	int        SavedPC;
/*0x001fc*/	int        InfraRed;
/*0x00200*/	int        InfraGreen;
/*0x00204*/	int        InfraBlue;
/*0x00208*/	int        UltraRed;
/*0x0020c*/	int        UltraGreen;
/*0x00210*/	int        UltraBlue;
/*0x00214*/	int        Unknown0x00214;
/*0x00218*/	int        IOLines;
/*0x0021c*/	int        IOLineSpacing;
/*0x00220*/	char       ObjTag[0x14];
/*0x00234*/	long       NumObjects;
/*0x00238*/	long       NumLights;
/*0x0023c*/	long       DecrTime[0xa];
/*0x00264*/	long       DecrMsg[0xa];
/*0x0028c*/	long       DecrIndex;
/*0x00290*/	BYTE       AffectsOn;
/*0x00291*/	BYTE       InspectMode;
/*0x00292*/	BYTE       UpMouseAnim;
/*0x00294*/	UINT       ExitCounter;
/*0x00298*/	UINT       ExitStart;
/*0x0029c*/	UINT       ForcedExitCounter;
/*0x002a0*/	UINT       OfflineModeRequestTime;
/*0x002a4*/	int        SwimJump;
/*0x002a8*/	BYTE       DisplayCamp;
/*0x002ac*/	int        PolysOff;
/*0x002b0*/	float      CampY;
/*0x002b4*/	float      CampX;
/*0x002b8*/	float         CampZ;
/*0x002bc*/ int        Hits;
/*0x002c0*/	int        Bandage;
/*0x002c4*/	UINT       BackSpace;
/*0x002c8*/	long       StartBandage;
/*0x002cc*/	long       MyY;
/*0x002d0*/	long       MyX;
/*0x002d4*/	long       MyZ;
/*0x002d8*/	long       TargetY;
/*0x002dc*/	long       TargetX;
/*0x002e0*/	long       TargetZ;
/*0x002e4*/	ZONEINFO   ZoneInfo;
/*0x0068c*/	BYTE       ZDefined;
/*0x00690*/	int        TrackTimer;
/*0x00694*/	long       StartTrack;
/*0x00698*/	int        bTrackPlayers;
/*0x0069c*/ bool       bTrackMercs;
/*0x0069d*/ bool       bTrackPets;
/*0x006a0*/	int        iTrackSortType;
/*0x006a4*/	int        iTrackFilterType;
/*0x006a8*/	UINT       MouseTimer;
/*0x006ac*/	int        SoundUpdate;
/*0x006b0*/	BOOL       MouseOn;
/*0x006b4*/	USINGSKILL UsingSkill;
/*0x006bc*/	int        Unknown0x006bc[4];
/*0x006cc*/ BYTE       ClickThroughMask;
/*0x006d0*/	int        ShowSpellDescriptions;
/*0x006d4*/	bool       ReceivedWorldObjects;
/*0x006d5*/	BYTE       Unknown0x006d5;
/*0x006d6*/	bool       Unknown0x006d6;
/*0x006d8*/	float      SavedViewPitch;
/*0x006dc*/	int        SendPcReceived;
/*0x006e0*/	int        WeatherReceived;
/*0x006e4*/	int        PixelInit;
/*0x006e8*/	bool       bIsPressedShift;
/*0x006e9*/	bool       bIsPressedControl;
/*0x006ea*/	bool       bIsPressedAlt;
/*0x006eb*/	bool       bIsPressedLShift;
/*0x006ec*/	bool       bIsPressedLControl;
/*0x006ed*/	bool       bIsPressedLAlt;
/*0x006ee*/	bool       bIsPressedRShift;
/*0x006ef*/	bool       bIsPressedRControl;
/*0x006f0*/	bool       bIsPressedRAlt;
/*0x006f4*/	int        Currkeypress;
/*0x006f8*/	int        Lastkeypress;
/*0x006fc*/	int        Rateup;
/*0x00700*/	int        Ratedown;
/*0x00704*/	int        Rateforward;
/*0x00708*/	int        Rateback;
/*0x0070c*/	int        Rateleft;
/*0x00710*/	int        Rateright;
/*0x00714*/	int        RaceWar;
/*0x00718*/	int        Ruleset;
/*0x0071c*/	bool       bRpServer;
/*0x0071d*/	bool       bAcceleratedServer;
/*0x0071e*/	bool       bProgressionServer;
/*0x00720*/	int        ProgressionOpenExpansions;
/*0x00724*/ bool       bIsDevServer;
/*0x00725*/ bool       bIsBetaServer;
/*0x00726*/ bool       bIsTestServer;
/*0x00727*/ bool       bIsStageServer;
/*0x00728*/	bool       bUseMailSystem;
/*0x00729*/	bool       bIsEscapeServer;
/*0x0072a*/	bool       bIsTutorialEnabled;
/*0x0072b*/	bool       bCanCreateHeadStartCharacter;
/*0x0072c*/ bool       bCanCreateHeroicCharacter;
/*0x00730*/ int        HeroicSlots;
/*0x00734*/	bool       bAutoIdentify;
/*0x00735*/	bool       bNameGen;
/*0x00736*/	bool       bGibberish;
/*0x00738*/	int        Locale;
/*0x0073c*/	BYTE       UpdateControlled;
/*0x0073d*/	BYTE       UpdateLocal;
/*0x0073e*/	BYTE       EnterZone;
/*0x0073f*/	BYTE       ExitGame;
/*0x00740*/ int        EnterZoneReason;
/*0x00744*/	bool       UseVoiceMacros;
/*0x00748*/	int        Deltax;
/*0x0074c*/	int        Deltay;
/*0x00750*/	int        OldRate1;
/*0x00754*/	int        OldRate2;
/*0x00758*/	float      StrafeRate;
/*0x0075c*/	int        SaveIndex;
/*0x00760*/	float      Unknown0x00760;
/*0x00764*/ // plus more ...
};
#pragma pack(pop)
using PEVERQUESTINFO = EVERQUESTINFO*;

// size 0x20 -- brainiac 11/14/2016
struct tp_coords
{
/*0x00*/ int           Index;
/*0x04*/ float         Y;
/*0x08*/ float         X;
/*0x0C*/ float         Z;
/*0x10*/ float         Heading;
/*0x14*/ int           ZoneId;
/*0x18*/ int           FilterID;
/*0x1C*/ UINT          VehicleID;
/*0x20*/
};

} // namespace EQClasses

using namespace EQClasses;
