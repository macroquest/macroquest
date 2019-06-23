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

struct IShellFolder;

namespace EQClasses 
{
// Other
class CXSize
{
public:
	DWORD A, B, C, D, E, F;
	CXSize::~CXSize() {};
};

// Enumerations...
typedef DWORD EQZoneIndex;
typedef DWORD EQLocalizeLanguage;
typedef DWORD EScrollCode;

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
class CMutexLock;
class CMutexLockCounted;
class CMutexSync;
class CMutexSyncCounted;
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
class CXWndDrawTemplate;
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
class EqMobileEmitter;
class EQMoneyList;
class EQNewPlayerAnimation;
class EQObject;
class EQOldPlayerAnimation;
class EQPlayer;
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
class vlong;
class vlong_value;
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
	CHAR casterName[64];

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

EQLIB_OBJECT class AggroMeterManagerClient
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
using PShared_Loot = pShared_Loot*;

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
EQLIB_OBJECT class CXStr
{
public:
	CXStr();
	CXStr(char const*);
	CXStr(char const*, int);
	CXStr(char);
	CXStr(const CXStr&);
	CXStr(int, int, char);
	CXStr(unsigned short const*);
	~CXStr();

	CXStr& operator=(char const*);
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
	int PrintString(char const*, ...);
	//int Compare(class CXStr const &, enum CompareCode) const;
	//int CompareN(class CXStr const &, int, enum CompareCode) const;
	int ConvertToInt();
	int operator==(char const*) const;
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
	void operator+=(char const*);
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
	static int Utf8ToUnicode(char const*, unsigned short*, int);
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

EQLIB_OBJECT class CXWnd
{
public:
	//CXWnd() {};
	void dCXWnd();
	CXWnd* SetParent(CXWnd*);
	enum UIType GetType();
	class CXMLData* GetXMLData();
	class CXWnd* GetChildItem(PCHAR Name);
	CXWnd(class CXWnd*, uint32_t, class CXRect);
	bool HasFocus() const;
	bool IsActive() const;
	bool IsDescendantOf(class CXWnd const*) const;
	bool IsEnabled() const;
	bool IsReallyVisible() const;
	bool IsType(EWndRuntimeType eType) const;
	class CButtonDrawTemplate const* GetCloseBoxTemplate() const;
	class CButtonDrawTemplate const* GetMinimizeBoxTemplate() const;
	class CButtonDrawTemplate const* GetTileBoxTemplate() const;
	class CTAFrameDraw const* GetBorderFrame() const;
	class CTAFrameDraw const* GetTitlebarHeader() const;
	class CXRect GetClientClipRect() const;
	class CXRect GetRelativeRect() const;
	class CXRect GetScreenClipRect() const;
	class CXRect GetScreenRect() const;
	class CXStr GetWindowTextA() const;
	class CXStr GetXMLTooltip() const;
	class CXWnd* GetChildItem(CXStr const &);
	class CXWnd* GetChildWndAt(class CXPoint*, int, int) const;
	class CXWnd* GetFirstChildWnd() const;
	class CXWnd* GetNextChildWnd(class CXWnd*) const;
	class CXWnd* GetNextSib() const;
	class CXWnd* SetFocus();
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
	int Move(class CXPoint const &);
#else
	int Move(class CXPoint);
#endif
	//Move (this is CXWnd__Move1_x) was checked on apr 29 2016 - eqmule
	int Move(const CXRect& rc, bool bUpdateLayout = true, bool bForceUpdateLayout = false, bool bCompleteMoveOrResize = false, bool bMoveAutoStretch = false);
	int ProcessTransition();
	int Resize(int Width, int Height, bool bUpdateLayout = true, bool bCompleteMoveOrResize = false, bool bMoveAutoStretch = false);
	int Show(bool bShow = true, bool bBringToTop = true, bool bUpdateLayout = true);
	int Tile(bool);
	static class CXRect GetTooltipRect(class CXPoint, class CXSize);
	static class CXRect* GetTooltipRect(class CXRect*);
	static class CXWndDrawTemplate sm_wdtDefaults;
	static int DrawColoredRect(class CXRect, unsigned long, class CXRect);
	static int DrawLasso(class CXRect, unsigned long, class CXRect);
	static int DrawRaisedRect(class CXRect, class CXRect);
	static int DrawSunkenRect(class CXRect, class CXRect);
	void Bottom();
	void BringChildWndToTop(class CXWnd*);
	void BringToTop(bool bRecurse = true);
	void Center();
	void ClrFocus();
	int Destroy();
	void DrawTooltipAtPoint(class CXPoint) const;
	void Left();
	void Refade();
	void Right();
	void SetFirstChildPointer(class CXWnd*);
	void SetKeyTooltip(int, int);
	void SetLookLikeParent();
	void SetMouseOver(bool);
	void SetNextSibPointer(class CXWnd*);
	void SetTooltip(class CXStr);
	void SetXMLTooltip(class CXStr);
	//void SetZLayer(int);
	void StartFade(unsigned char, uint32_t);
	// virtual
	bool IsPointTransparent(class CXPoint) const;
	bool IsValid() const;
	bool QueryClickStickDropOK(class CClickStickInfo*) const;
	bool QueryDropOK(struct SDragDropInfo*) const;
	class CTextureAnimation* GetClickStickCursor(class CClickStickInfo*) const;
	class CTextureAnimation* GetCursorToDisplay() const;
	class CTextureAnimation* GetDragDropCursor(struct SDragDropInfo*) const;
	class CXRect GetClientRect() const;
	class CXRect GetHitTestRect(int) const;
	class CXRect GetInnerRect() const;
	class CXRect GetMinimizedRect() const;
	class CXSize GetMinSize() const;
	class CXSize GetUntileSize() const;
	class CXStr GetTooltip() const;
	int AboutToDeleteWnd(class CXWnd*);
	int Draw() const;
	int DrawBackground() const;
	int DrawCaret() const;
	int DrawChildItem(class CXWnd const*, void*) const;
	int DrawCursor(class CXPoint, class CXRect, bool &);
	int DrawNC() const;
	int DrawTitleBar(class CXRect) const;
	int DrawTooltip(class CXWnd const*) const;
	int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	int HandleLButtonDown(class CXPoint*, uint32_t);
	int HandleLButtonHeld(class CXPoint*, uint32_t);
	int HandleLButtonUp(class CXPoint*, uint32_t);
	int HandleLButtonUpAfterHeld(class CXPoint*, uint32_t);
	int HandleMouseMove(class CXPoint, uint32_t);
	int HandleRButtonDown(class CXPoint*, uint32_t);
	int HandleRButtonHeld(class CXPoint*, uint32_t);
	int HandleRButtonUp(class CXPoint*, uint32_t);
	int HandleRButtonUpAfterHeld(class CXPoint*, uint32_t);
	int HandleWheelButtonDown(class CXPoint, uint32_t);
	int HandleWheelButtonUp(class CXPoint, uint32_t);
	int HandleWheelMove(class CXPoint, int, uint32_t);
	int HitTest(class CXPoint, int*) const;
	int OnActivate(class CXWnd*);
	int OnBroughtToTop();
	int OnClickStick(class CClickStickInfo*, uint32_t, bool);
	int OnDragDrop(struct SDragDropInfo*);
	int OnHScroll(EScrollCode, int);
	int OnKillFocus(class CXWnd*);
	int OnMinimizeBox();
	int OnMove(class CXRect);
	int OnProcessFrame();
	int OnResize(int, int);
	int OnSetFocus(class CXWnd*);
	int OnShow();
	int OnTile();
	int OnTileBox();
	int OnVScroll(EScrollCode, int);
	int PostDraw() const;
	//int RequestDockInfo(enum EDockAction, class CXWnd*, class CXRect*);
	int SetVScrollPos(int);
	int WndNotification(class CXWnd*, uint32_t, void*);
	void Deactivate();
	void OnReloadSidl();
	void SetAttributesFromSidl(class CParamScreenPiece*);
	void SetDrawTemplate(class CXWndDrawTemplate*);
	void SetWindowTextA(const CXStr& Str);
	// protected
	static CXWndManager*& sm_pMgr;
	// private
	static unsigned char sm_byCurrentAlpha;
	int SetFont(void*);

	CXW;
};

EQLIB_OBJECT class CSidlScreenWnd
{
public:
	int GetContextMenuIndex() { return ContextMenuID; }
	UIType GetType();
	CXMLData* GetXMLData();
	CXWnd* GetChildItem(PCHAR Name);
	CSidlScreenWnd() {};
	CSidlScreenWnd(CXWnd* pParent, const CXStr& Screen);
	CSidlScreenWnd(CXWnd* pWnd, const CXStr& Screen, int Flags, int IniVersion = 1, char* BlockName = nullptr);
	CSidlScreenWnd(CXWnd*, uint32_t, const CXRect&, const CXStr&);
	CScreenPieceTemplate* GetSidlPiece(CXStr*, bool bTopLevel=true) const;
	CXRect GetSidlPieceRect(CScreenPieceTemplate*, CXRect) const;
	CXWnd*GetChildItem(CXStr&, bool bDebug);
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
	void SetScreen(class CXStr*);
	void StoreIniListWnd(class CListWnd const*, char*);
	void StoreIniVis();
	// virtual
	~CSidlScreenWnd();
	int DrawBackground() const;
	int HandleLButtonUp(class CXPoint, uint32_t);
	int HandleRButtonDown(class CXPoint, uint32_t);
	int OnResize(int, int);
	int OnShow();
	int WndNotification(class CXWnd*, uint32_t, void*);
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

EQLIB_OBJECT class _EverQuestinfo
{
public:
	void SetAutoAttack(bool);
};

EQLIB_OBJECT class _PackFileData
{
public:
	~_PackFileData();
	// virtual
	int readBlock();
};

EQLIB_OBJECT class _PackFileDataRawFile
{
public:
	// virtual
	int readBlock();
};

EQLIB_OBJECT class _partyGroup
{
public:
	int getNumMembers() const;
};

EQLIB_OBJECT class CAdvancedLootWnd : public CSidlScreenWnd
{
public:
	CAdvancedLootWnd(class CXWnd*);
	DWORD DoAdvLootAction(DWORD listindex, CXStr* Name, DWORD Action, DWORD Quantity);
#if !defined(ROF2EMU) && !defined(UFEMU)
	DWORD DoSharedAdvLootAction(PLOOTITEM pLootItem, CXStr* Assignee, DWORD Action, DWORD Quantity);
#endif
	// virtual
	~CAdvancedLootWnd();
};

EQLIB_OBJECT class CRewardSelectionWnd : public CSidlScreenWnd
{
public:
	CRewardSelectionWnd(class CXWnd*);
	// virtual
	~CRewardSelectionWnd();
};

EQLIB_OBJECT class CAltAbilityData
{
public:
	int GetMercCurrentRank(int);
	int GetMercMaxRank(int);
	int GetMaxRank();                   //it really is called GetMaxLevel but that doesnt make sense to me so... rank it is...
};

EQLIB_OBJECT class AltAdvManager
{
public:
	AltAdvManager();
	// IsAbilityReady was checked on apr 29 2016, it looks like it has 5 arguments in IDA, but it doesnt. (it has 4)
	bool IsAbilityReady(class EQ_PC*, EQData::PALTABILITY, int* Refresh/*out*/, int* Timer/*out*/ = 0);
	int AbilitiesByClass(int, int);
	int AltSkillReqs(class EQ_PC*, int);
	int CalculateDoubleAttackChance(class EQ_PC*, int, unsigned char);
	int CalculateFleetOfFoot(class EQ_PC*);
	int CalculateHideTimeReduce(class EQ_PC*);
	int CalculateInstrumentMasteryMod(class EQ_PC*);
	int CalculateLoHHarmTouchReuseTimer(class EQ_PC*, int);
	int CalculateMaxHPAA(class EQ_PC*, int);
	int CalculateMaxStatAA(class EQ_PC*, int);
	int CalculateMitigationBoost(class EQ_PC*, int);
	int CalculateNimbleEvasionChance(class EQ_PC*);
	int CalculateSingingMasteryMod(class EQ_PC*, int);
	int CalculateSpellCastingMastery(class EQ_PC*);
	int CalculateStalwartEnduranceChance(class EQ_PC*);
	bool CanTrainAbility(class PcZoneClient*, class CAltAbilityData*, bool, bool, bool);
	bool CanSeeAbility(class PcZoneClient*, class CAltAbilityData*);
	int GetAALevelNeeded(class EQ_PC*, int);
	int GetAbilityTitle(class EQPlayer*);
	int GetNextAbilityCost(int, int);
	int MeetsPoPLevelReqs(class EQ_PC*, int, int);
	int TotalPointsInSkill(int, int);
	unsigned long GetCalculatedTimer(class EQ_PC*, EQData::PALTABILITY);
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
/*0x000*/ CHAR         Name[0x40];
/*0x040*/ uint32_t     SpawnID;
/*0x044*/ int          Cost;
/*0x048*/ int          IconnID;
/*0x04c*/
};

// we call this _AURAMGR
EQLIB_OBJECT class ClientSOIManager
{
public:
	ArrayClass2_RO<AssociatedSOIData> Auras;

	static ClientSOIManager* GetSingleton();
};

EQLIB_OBJECT class CAuraWnd : public CSidlScreenWnd
{
public:
	CAuraWnd(CXWnd*);

	// virtual
	~CAuraWnd();
};

EQLIB_OBJECT class bad_word_class
{
public:
	bad_word_class(char*);
};

EQLIB_OBJECT class CAAWnd : public CSidlScreenWnd
{
public:
	CAAWnd(class CXWnd*);
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
	int WndNotification(class CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void Init();
	void UpdateSelected();
};

EQLIB_OBJECT class CActionsWnd : public CSidlScreenWnd
{
public:
	CActionsWnd(class CXWnd*);
	class CButtonWnd* GetAbilityBtn(int);
	class CButtonWnd* GetCombatBtn(int);
	class CButtonWnd* GetMenuBtn(int);
	int GetCurrentPageEnum() const;
	void Activate(int);
	void KeyMapUpdated();
	void SelectSkillForAbilityBtn(int);
	void SelectSkillForCombatBtn(int);
	void UpdateButtonText();

	// virtual
	~CActionsWnd();
	int OnProcessFrame();
	int WndNotification(class CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	int AbilitiesPageActivate();
	int AbilitiesPageDeactivate();
	int AbilitiesPageOnProcessFrame();
	int AbilitiesPageWndNotification(class CXWnd*, uint32_t, void*);
	int CombatPageActivate();
	int CombatPageDeactivate();
	int CombatPageOnProcessFrame();
	int CombatPageWndNotification(class CXWnd*, uint32_t, void*);
	int MainPageActivate();
	int MainPageDeactivate();
	int MainPageOnProcessFrame();
	int MainPageWndNotification(class CXWnd*, uint32_t, void*);
	int RedirectActivateTo(class CPageWnd*);
	int RedirectDeactivateTo(class CPageWnd*);
	int RedirectOnProcessFrameTo(class CPageWnd*);
	int RedirectWndNotificationTo(class CPageWnd*, class CXWnd*, uint32_t, void*);
	int SocialsPageActivate();
	int SocialsPageDeactivate();
	int SocialsPageOnProcessFrame();
	int SocialsPageWndNotification(class CXWnd*, uint32_t, void*);
};

EQLIB_OBJECT class CAchievementsWnd : public CSidlScreenWnd
{
public:
	CAchievementsWnd(class CXWnd*);
};

EQLIB_OBJECT class CRealEstateItemsWnd : public CSidlScreenWnd
{
public:
	CRealEstateItemsWnd(class CXWnd*);
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
/*0x1c*/ CHAR          Name[0x40];
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

EQLIB_OBJECT class EQGroundItemListManager
{
public:
	EQGroundItem*      Top;

	static EQGroundItemListManager& Instance();
};

// well we call this CTextOverlay but whatever should probably rename at some point...
EQLIB_OBJECT class CBroadcast
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

EQLIB_OBJECT class CAlarmWnd : public CSidlScreenWnd
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

EQLIB_OBJECT class CBankWnd : public CSidlScreenWnd //, public WndEventHandler but we just add the member LastCheckTime
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

	CBankWnd(CXWnd*, class CXStr);
	int GetNumBankSlots() const;
	void Activate(class EQPlayer*);
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

EQLIB_OBJECT class CBazaarSearchWnd : public CSidlScreenWnd
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
	int WndNotification(class CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void AddItemtoList(char*, unsigned long, char*, int, int);
	void doQuery();
	void Init();
	void InitListArray();
	void SortItemList(int);
	void UpdateComboButtons();
};

EQLIB_OBJECT class CBazaarWnd : public CSidlScreenWnd
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

EQLIB_OBJECT class CBodyTintWnd : public CSidlScreenWnd
{
public:
	CBodyTintWnd(class CXWnd*);
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
	int WndNotification(class CXWnd*, uint32_t, void*);
	void Deactivate();
};

EQLIB_OBJECT class CBookWnd : public CSidlScreenWnd
{
public:
	CBookWnd(class CXWnd*);
	bool CheckBook(class EQ_Note*);
	void Activate();
	void SetBook(char*);

	// virtual
	~CBookWnd();
	int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	int WndNotification(class CXWnd*, uint32_t, void*);
	void Deactivate();

	// protected
	void CleanPages();
	void DisplayText();
	void ProcessText();
	void ShowButtons();

	// private
	void Init();
};

EQLIB_OBJECT class CBreathWnd : public CSidlScreenWnd
{
public:
	CBreathWnd(class CXWnd*);
	void Activate();

	// virtual
	~CBreathWnd();
	int OnProcessFrame();
	void Deactivate();

	// private
	void Init();
};

EQLIB_OBJECT class CBuffWindow : public CSidlScreenWnd
{
public:
	CBuffWindow(class CXWnd*, enum BuffWindowType);
	void Activate();
	void SetBuffIcon(class CButtonWnd*, int, int);

	// virtual
	~CBuffWindow();
	class CXSize GetMinSize() const;
	int OnProcessFrame();
	int PostDraw() const;
	int WndNotification(class CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void HandleSpellInfoDisplay(class CXWnd*);
	void Init();
	void RefreshBuffDisplay();
	void RefreshIconArrangement();
};

EQLIB_OBJECT class CBugReportWnd : public CSidlScreenWnd
{
public:
	CBugReportWnd(class CXWnd*);
	void Activate();

	// virtual
	~CBugReportWnd();
	int WndNotification(class CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void UpdateLocation();
};

EQLIB_OBJECT class CButtonDrawTemplate
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

EQLIB_OBJECT class CButtonTemplate
{
public:
	CButtonTemplate(CParamButton*);

	// virtual
	CButtonTemplate::~CButtonTemplate();
};

EQLIB_OBJECT class CButtonWnd : public CXWnd
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

	CButtonWnd(class CXWnd*, uint32_t, class CXRect, class CXPoint, class CXSize, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*);
	void SetCheck(bool);

	// virtual
	//EQLIB_OBJECT CButtonWnd() {};
	~CButtonWnd();
	bool IsPointTransparent(class CXPoint) const;
	int Draw() const;
	int HandleLButtonDown(class CXPoint, uint32_t);
	int HandleLButtonHeld(class CXPoint, uint32_t);
	int HandleLButtonUp(class CXPoint, uint32_t);
	int HandleLButtonUpAfterHeld(class CXPoint, uint32_t);
	int HandleMouseMove(class CXPoint, uint32_t);
	int HandleRButtonDown(class CXPoint, uint32_t);
	int HandleRButtonHeld(class CXPoint, uint32_t);
	int HandleRButtonUp(class CXPoint, uint32_t);
	int HandleRButtonUpAfterHeld(class CXPoint, uint32_t);
	int OnProcessFrame();
	void SetAttributesFromSidl(class CParamScreenPiece*);
	void SetRadioGroup(class CRadioGroup*);
	UINT GetCoolDownTotalDuration() const;
	UINT GetCoolDownTimeRemaining() const;
};

EQLIB_OBJECT class CCastingWnd : public CSidlScreenWnd
{
public:
	CCastingWnd(class CXWnd*);
	void Activate();

	// virtual
	~CCastingWnd();
	int OnProcessFrame();
	void Deactivate();
};

EQLIB_OBJECT class CCastSpellWnd : public CSidlScreenWnd
{
public:
	CCastSpellWnd(class CXWnd*);
	static void Unmemorize(int);
	static void UnmemorizeList(int*, int);
	void Activate();
	void ForgetMemorizedSpell(int);
	void HandleSpellInfoDisplay(class CXWnd*);
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
	int WndNotification(class CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	bool IsBardSongPlaying();
	unsigned long GetSpellGemColor(class EQ_Spell*);
	void CategorizeSpell(int, int, int, int);
	void ClearSpellCategories();
	void Init();
	void MakeSpellSelectMenu();
	void RefreshSpellGemButtons();
	void UpdateSpellGems(int);
	void UpdateSpellGemTooltips(int);
};

EQLIB_OBJECT class CCharacterCreation : public CSidlScreenWnd
{
public:
	CCharacterCreation(class CXWnd*);
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
	int WndNotification(class CXWnd*, uint32_t, void*);
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
	void SetPlayerAppearanceFromNewPC(class EQPlayer*, class EQ_PC*, bool);
	void SubmitNameToWorld();
	void UpdatePlayerFromNewPC();
	void UpdateScreenZeroButtons(bool);
};

EQLIB_OBJECT class CCharacterListWnd : public CSidlScreenWnd
{
public:
	CCharacterListWnd(class CXWnd*);
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
	void SwitchModel(class EQPlayer*, unsigned char, int, unsigned char, unsigned char);
	void UpdateButtonNames();

	// virtual
	~CCharacterListWnd();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(class CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void CreateExplorationModePlayers();
	void EnableButtons(bool);
	void EnableEqMovementCommands(bool);
	void Init();
	void RemoveExplorationModePlayers();
	void SetLocationByClass(class EQPlayer*, bool, int);
	void SetRoomLocationByIndex(int, class EQPlayer*);
};

EQLIB_OBJECT class CChatManager
{
public:
	~CChatManager();
	CChatManager();
	class CChatWindow* GetActiveChatWindow();
	class CChatWindow* GetChannelMap(int);
	class CXStr GetAllVisibleText(class CXStr);
	int GetChannelFromColor(int);
	int InitContextMenu(class CChatWindow*);
	unsigned long GetRGBAFromIndex(int);
	void Activate();
	void AddText(class CXStr, int);
	void ClearChannelMap(int);
	void ClearChannelMaps(class CChatWindow*);
	void CreateChatWindow(char*, char*, int, int, int, char*, int);
	void CreateChatWindow();
	void Deactivate();
	void FreeChatWindow(class CChatWindow*);
	void LoadChatInis();
	void Process();
	void SetActiveChatWindow(class CChatWindow*);
	void SetChannelMap(int, class CChatWindow*);
	void SetLockedActiveChatWindow(CChatWindow*);
	void UpdateContextMenus(class CChatWindow*);
	void UpdateTellMenus(class CChatWindow*);
	CChatWindow*GetLockedActiveChatWindow();
#if !defined(ROF2EMU) && !defined(UFEMU)
	void CreateChatWindow(CXWnd* pParentWnd, int ID, char* Name, int Language, int DefaultChannel, int ChatChannel, char* szTellTarget, int FontStyle, bool bScrollbar, bool bHighLight, COLORREF HighlightColor);
#else
	void CreateChatWindow(char* Name, char*IniName, int Language, int DefaultChannel, int ChatChannel, char* szTellTarget, int FontStyle, bool bScrollbar);
#endif
};

EQLIB_OBJECT class ChatManagerClient : public CChatManager
{
public:
	static ChatManagerClient& Instance();
};

EQLIB_OBJECT class CChatWindow : public CSidlScreenWnd
{
public:
	CChatWindow(class CXWnd*);
	class CEditWnd* GetInputWnd();
	class CStmlWnd* GetOutputWnd();
	class CXStr GetInputText();
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
	int HandleRButtonDown(class CXPoint, uint32_t);
	int OnKillFocus(class CXWnd*);
	int OnProcessFrame();
	int OnSetFocus(class CXWnd*);
	int WndNotification(class CXWnd*, uint32_t, void*);
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

EQLIB_OBJECT class CCheckBoxWnd : public CButtonWnd
{
public:
	bool bOrgState;

	CCheckBoxWnd(class CXWnd*, uint32_t, class CXRect, class CXPoint, class CXSize, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*);
	void SetRadioLook();

	// virtual
	~CCheckBoxWnd();
	int HandleLButtonDown(class CXPoint, uint32_t);
	int HandleLButtonUp(class CXPoint, uint32_t);
	int HandleMouseMove(class CXPoint, uint32_t);
	void SetRadioGroup(class CRadioGroup*);

	// protected
	static bool sm_bAnimsInitialized;
	static class CButtonDrawTemplate sm_bdtCheck;
	static class CButtonDrawTemplate sm_bdtRadio;
};

EQLIB_OBJECT class CClickStickInfo
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

EQLIB_OBJECT class CCollisionInfoTargetVisibility
{
public:
	// CCollisionInfoTargetVisibility(const CLineSegment& rLineSegment, const PlayerBase* pPlayerSelf, const PlayerBase* pPlayerOther);
	CCollisionInfoTargetVisibility(CLineSegment*rLineSegment, EQPlayer* pSelf, EQPlayer* pOther);
};

class WndEventHandler2
{
public:
	UINT LastCheckTime;

	WndEventHandler2();
	void OnWndEvent(CXWnd*pwndSender) const;
};

EQLIB_OBJECT class CColorPickerWnd : public CSidlScreenWnd, public WndEventHandler2
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

	CColorPickerWnd(CXWnd*pwndParent);
	void Activate(CXWnd*, unsigned long);
	void CheckMaxEditWnd();
	void SetCurrentColor(unsigned long);
	void SetTemplateColor(int, unsigned long);
	void UpdateCurrentColor();
	void UpdateEditWndFromSlider(CSliderWnd*pSlider, class CEditWnd*pEdit, int*value);
	void UpdateSliderFromEditWnd(CSliderWnd*pSlider, class CEditWnd*pEdit, int*value);
	void Deactivate();
	void Init();
	int Open(CXWnd* pwndCaller, D3DCOLOR CurrentColor = 0x00FFFFFF);
	virtual bool AboutToHide();
	virtual int WndNotification(CXWnd*pwndSender, UINT Msg, LPVOID pData);
	virtual void OnWndNotification();
};

EQLIB_OBJECT class CCombatSkillsSelectWnd : public CSidlScreenWnd
{
public:
	CCombatSkillsSelectWnd(class CXWnd*);

	// virtual
	~CCombatSkillsSelectWnd();

	// private
	bool ShouldDisplayThisSkill(int);
};

EQLIB_OBJECT class CComboboxTemplate
{
public:
	CComboboxTemplate(class CParamCombobox*);
	// virtual
	~CComboboxTemplate();
};

EQLIB_OBJECT class CComboWnd// : public CXWnd
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

	CComboWnd(class CXWnd*, uint32_t, class CXRect, int, class CButtonDrawTemplate, class CListWnd*);
	class CXRect GetButtonRect() const;
#if !defined(ROF2EMU) && !defined(UFEMU)
	class CXRect GetListRect(bool) const;
#else
	class CXRect GetListRect() const;
#endif
	class CXRect GetTextRect() const;
	class CXStr GetCurChoiceText() const;
	int GetCurChoice() const;
	int GetItemCount();
	void DeleteAll();
	void InsertChoice(class CXStr*, unsigned long);
	void InsertChoice(char*);
	void SetChoice(int);
	void SetColors(unsigned long, unsigned long, unsigned long);

	// virtual
	~CComboWnd();
	class CXSize GetMinSize() const;
	int Draw() const;
	int HandleLButtonDown(class CXPoint, uint32_t);
	int HitTest(class CXPoint, int*) const;
	int OnMove(class CXRect);
	int OnResize(int, int);
	int WndNotification(class CXWnd*, uint32_t, void*);
	void SetDrawTemplate(class CXWndDrawTemplate*);
};

EQLIB_OBJECT class CCompassWnd : public CSidlScreenWnd
{
public:
	CCompassWnd(class CXWnd*);
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

EQLIB_OBJECT class CConfirmationDialog : public CSidlScreenWnd
{
public:
	CConfirmationDialog(class CXWnd*);
	void Activate(int, unsigned int, char const*, int, int, int, int);
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
	int WndNotification(class CXWnd*, uint32_t, void*);
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

EQLIB_OBJECT class ItemBase
{
public:
	bool IsLore(bool bIncludeSockets = false) const;
	bool IsLoreEquipped(bool bIncludeSockets = false) const;
};

EQLIB_OBJECT class ItemGlobalIndex
{
public:
	ItemContainerInstance Location;
	ItemIndex Index;

	ItemGlobalIndex();
	bool IsKeyRingLocation();
	bool IsEquippedLocation();
	bool IsValidIndex();
};

EQLIB_OBJECT class CContainerMgr
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
	class EQ_Item* GetWorldContainerItem(int);
	void ClearWorldContainerItems();
	void CloseContainer(class EQ_Container*, bool);
	void CloseEQContainer(class EQ_Container*);
	void OpenContainer(class EQ_Container*, int, bool);
	void OpenWorldContainer(class EQ_Container*, unsigned long);
	void Process();
	void SetWorldContainerItem(class EQ_Item*, int);

	// virtual
	~CContainerMgr();

	// private
	class CContainerWnd* GetFreeContainerWnd();
	void OpenExperimentContainer(const VePointer<CONTENTS>& pCont, const ItemGlobalIndex& Location);
};

EQLIB_OBJECT class CContainerWnd : public CSidlScreenWnd
{
public:
	CContainerWnd(class CXWnd*);
	void Activate();
	void CheckCloseable();
	void SetContainer(PCONTENTS &pContainer, const ItemGlobalIndex& location);

	// virtual
	~CContainerWnd();
	int OnProcessFrame();
	int PostDraw() const;
	int WndNotification(class CXWnd*, uint32_t, void*);
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

	CContextMenuManager(class CXWnd*, uint32_t, class CXRect);
	int AddMenu(class CContextMenu*);
	int GetDefaultMenuIndex() { return DefaultMenuIndex; }
	CContextMenu*GetMenu(int);
	int HandleWindowMenuCommands(class CXWnd*, int);
	int PopupMenu(int, class CXPoint const &, class CXWnd*);
	int RemoveMenu(int, bool);
	void Flush();
	void WarnDefaultMenu(class CXWnd*);

	// virtual
	~CContextMenuManager();
	int HandleLButtonDown(class CXPoint, uint32_t);
	int HandleRButtonDown(class CXPoint, uint32_t);
	int HandleWheelButtonDown(class CXPoint, uint32_t);
	int OnProcessFrame();
	int WndNotification(class CXWnd*, uint32_t, void*);
	void Deactivate();

	// private
	void CreateDefaultMenu();
};

EQLIB_OBJECT class CScreenPieceTemplate
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
	CScreenPieceTemplate(class CParamScreenPiece*);
	bool IsType(uint32_t) const;
	class CXStr GetName() const;

	// virtual
	~CScreenPieceTemplate();
};

EQLIB_OBJECT class CControlTemplate : public CScreenPieceTemplate
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

	CControlTemplate(class CParamControl*);

	// virtual
	~CControlTemplate();
};

class HasATimer
{
	UINT Timer;
};

EQLIB_OBJECT class CCursorAttachment // : public CSidlScreenWnd : public HasATimer
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

	CCursorAttachment(class CXWnd*);
	bool IsOkToActivate(int);
	bool RemoveAttachment();
	void Activate(class CTextureAnimation*, int, int, int);
	// virtual
	~CCursorAttachment();
	int Draw() const;
	int OnProcessFrame();
	int WndNotification(class CXWnd*, uint32_t, void*);
	//EQLIB_OBJECT void* `scalar deleting destructor'(unsigned int);
	//EQLIB_OBJECT void* `vector deleting destructor'(unsigned int);
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

EQLIB_OBJECT class CDIMap
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

EQLIB_OBJECT class CVector3
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

EQLIB_OBJECT class CDisplay
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
/*0x0015*/ CHAR        LastTeleportAreaTag[0x100];
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
	bool SlideSwitchLeftRight(class EQSwitch*, float, int, float);
	bool const GetWorldFilePath(char*, char const*);
	char* GetIniRaceName(int);
	class EQPlayer* GetNearestPlayerInView(float, bool);
	float FindZoneTopZ(float, float, float);
	float FixHeading(float);
	float GetFloorHeight(float X, float Y, float F, float Radius = 0.0f, CVector3& CollisionVector = CVector3(-1, -1, 1), CActorApplicationData* pAppData = 0, EActorType eActorType = Undefined, float ZOffset = 1.0f);
	float HeadingDiff(float, float, float*);
	float PlayerDistance(class EQPlayer*, class EQPlayer*, float);
	float PlayerSimpleDistance(class EQPlayer*, class EQPlayer*, float);
	float SetActorBoundingRadius(struct T3D_tagACTORINSTANCE*, float, float);
	float SimpleDistance(float, float, float, float, float, float, float);
	float TrueDistance(float fromx, float fromy, float fromz, float tox, float toy, float toz, float zfactor);
	int GetItemType(int);
	int GetNewPCIniFlag(int, int);
	int GetSkyTime(int*, int*);
	int is_3dON();
	int is_ParticleSystemON();
	int MoveMissile(class EQMissile*);
	int ReplaceCloakMaterials(int, struct T3D_HIERARCHICALSPRITEINSTANCE*, struct T3D_RGB*);
	int ReplaceMaterial(char*, char*, struct T3D_HIERARCHICALSPRITEINSTANCE*, struct T3D_RGB*, int);
	int SetBoneSpriteTint(struct T3D_DAG*, struct T3D_RGB*);
	int ShouldLoadNewPcModel(int, int);
	int TurnInfravisionEffectOff();
	int TurnInfravisionEffectOn();
	long SetUserRender(int);
	static char* DefaultUIPath;
	static char* UIPath;
	static int __cdecl WriteTextHD2(char const*text, int X, int Y, int color);
	static unsigned long __cdecl GetUserDefinedColor(int);
	static void __cdecl SetUserDefinedColor(int, int, int, int);
	struct T3D_POINTLIGHT* CreateLight(unsigned char, float, float, float, float);
	struct T3D_tagACTORINSTANCE* CreateActor(char*, float, float, float, float, float, float, bool, bool);
	struct T3D_tagACTORINSTANCE* GetClickedActor(int X, int Y, bool bFlag, CVector3& Vector1, CVector3& Vector2);
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
	void CreatePlayerActor(class EQPlayer*);
	void DDrawUpdateDisplay();
	void DeactivateMainUI();
	void default_cameras();
	void DefineSoloMode();
	void DeleteActor(struct T3D_tagACTORINSTANCE*);
	void DeleteLight(struct T3D_POINTLIGHT*);
	void DeleteParticleCloudInstance(struct T3D_PARTICLECLOUDINSTANCE**);
	void GetOnActor(struct T3D_tagACTORINSTANCE*, class EQPlayer*);
	void HandleMaterial(class EQ_PC*, int, class EQ_Item*, class EQ_Item*);
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
	void MoveLight(struct T3D_POINTLIGHT*, struct _physicsinfo*);
	void MoveLocalPlayerToSafeCoords();
	void NewUIProcessEscape();
	void PlaySoundAtLocation(float, float, float, int);
	void ProcessCloud();
	void ProcessEffects();
	void ProcessParticleEmitter(class EQSwitch*);
	void ProcessSky();
	void ProcessSwitches();
	void ProcessWeather();
	void RealRender_World();
	void ReloadUI(bool);
	void Render_MinWorld();
	void Render_World();
	void ResetRenderWindow();
	void SetActorScaleFactor(struct T3D_tagACTORINSTANCE*, float, unsigned char);
	void SetActorSpriteTint(struct _EQRGB*, struct T3D_tagACTORINSTANCE*);
	void SetActorUserData(struct T3D_tagACTORINSTANCE*, void*);
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
	void SetSpecialEnvironment(enum EnvironmentType);
	void SetSunLight();
	void SetupEmitterEnvironment();
	void SetupEQPlayers();
	void SetViewActor(struct T3D_tagACTORINSTANCE*);
	void SetRenderWindow(int mode);
	void ToggleScreenshotMode();
	void SetViewActorByName(char*);
	void SetViewAngle(int);
	void SetYon(float);
	void ShowDisplay();
	void SpurtBloodOnDag(struct T3D_DAG*);
	void StartWeather(int, unsigned char);
	void StartWorldDisplay(EQZoneIndex);
	void StartWorldDisplay_Bailout(char const*);
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
	struct T3D_HIERARCHICALSPRITEINSTANCE* dupActorHierarchicalSprite(struct T3D_tagACTORINSTANCE*);
	void CleanCharSelectUI();
	void CleanGameUI();
	void CleanUpNewUI();
	void InitGameUI();
	void InitNewUI();
};

EQLIB_OBJECT class CDistillerInfo
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

EQLIB_OBJECT class CEditBaseWnd //ok Look... this SHOULD inherit CXWnd but doing so... calls the constructor, and we dont want that... so... : public CXWnd
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

	EQLIB_OBJECT void SetMaxChars(int);
	EQLIB_OBJECT void SetSel(int, int);

	// virtual
	EQLIB_OBJECT ~CEditBaseWnd();
	EQLIB_OBJECT int OnKillFocus(class CXWnd*);
};

EQLIB_OBJECT class CEditboxTemplate
{
public:
	EQLIB_OBJECT CEditboxTemplate(class CParamEditbox*);
	// virtual
	EQLIB_OBJECT ~CEditboxTemplate();
};

EQLIB_OBJECT class CEditLabelWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CEditLabelWnd(class CXWnd*);
	EQLIB_OBJECT class CXStr GetLabelText();
	EQLIB_OBJECT void Activate(class CXWnd*, char*, int, unsigned long);

	// virtual
	EQLIB_OBJECT ~CEditLabelWnd();
	EQLIB_OBJECT int OnProcessFrame();
	EQLIB_OBJECT int WndNotification(class CXWnd*, uint32_t, void*);
	EQLIB_OBJECT void Deactivate();
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

	EQLIB_OBJECT CEditWnd(class CXWnd*, uint32_t, class CXRect, uint32_t);
	EQLIB_OBJECT class CXPoint GetCharIndexPt(int) const;
	EQLIB_OBJECT class CXPoint GetSelEndPt() const;
	EQLIB_OBJECT class CXPoint GetSelStartPt() const;
	EQLIB_OBJECT class CXStr GetSTMLSafeText();
	EQLIB_OBJECT int ConvertIndexPrintableToTagged(int);
	EQLIB_OBJECT int ConvertIndexTaggedToPrintable(int);
	EQLIB_OBJECT int GetLineForPrintableChar(int) const;
	EQLIB_OBJECT int GetLineLength(int) const;
	EQLIB_OBJECT int SelectableCharFromPoint(class CXPoint) const;
	EQLIB_OBJECT void AddItemTag(int, char*, int);
	EQLIB_OBJECT void CalculateScrollRange();
	EQLIB_OBJECT void EnsureCaretVisible();
	EQLIB_OBJECT void ReplaceSelection(char, bool);
	EQLIB_OBJECT void ReplaceSelection(class CXStr, bool);
	EQLIB_OBJECT void SetEditable(bool);

	// virtual
	EQLIB_OBJECT ~CEditWnd();
	EQLIB_OBJECT class CXPoint GetCaretPt() const;
	EQLIB_OBJECT class CXPoint PointFromPrintableChar(int) const;
	EQLIB_OBJECT class CXStr GetDisplayString() const;
	EQLIB_OBJECT class CXStr GetWindowTextA() const;
	EQLIB_OBJECT int Draw() const;
	EQLIB_OBJECT int DrawCaret() const;
	EQLIB_OBJECT int DrawMultiline() const;
	EQLIB_OBJECT int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	EQLIB_OBJECT int HandleLButtonDown(class CXPoint, uint32_t);
	EQLIB_OBJECT int HandleLButtonUp(class CXPoint, uint32_t);
	EQLIB_OBJECT int HandleMouseMove(class CXPoint, uint32_t);
	EQLIB_OBJECT int OnKillFocus(class CXWnd*);
	EQLIB_OBJECT int OnMove(class CXRect);
	EQLIB_OBJECT int OnResize(int, int);
	EQLIB_OBJECT int OnSetFocus(class CXWnd*);
	EQLIB_OBJECT int ResetWnd();
	EQLIB_OBJECT void SetWindowTextA(const CXStr& Str);

	// protected
	EQLIB_OBJECT static class CDIMap m_mapKeys;
	//EQLIB_OBJECT virtual int GetHorzOffset() const;
	EQLIB_OBJECT void FillIndexArray(class CXStr) const;
	EQLIB_OBJECT void FilterInputStr(class CXStr &);
	EQLIB_OBJECT void ProcessText();
};

EQLIB_OBJECT class UniversalChatProxy
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

EQLIB_OBJECT class CEQSuiteTextureLoader
{
public:
	void*              pWadFile;//SWadFile
	ArrayClass_RO<SuiteTexture> Textures;
	CXSTR*             UIPath[4];
	CXSTR*             DefaultUIPath[4];

	EQLIB_OBJECT ~CEQSuiteTextureLoader();
	EQLIB_OBJECT CEQSuiteTextureLoader();
	EQLIB_OBJECT BMI* GetTexture(const CUITextureInfo2 &ti);
	EQLIB_OBJECT unsigned int CreateTexture(class CUITextureInfo const &);
	EQLIB_OBJECT void UnloadAllTextures();
	EQLIB_OBJECT const CXStr& GetDefaultUIPath(int DirType) const;
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

EQLIB_OBJECT class CEverQuest
{
public:
	EQLIB_OBJECT ~CEverQuest();
	EQLIB_OBJECT CEverQuest(HWND);
	EQLIB_OBJECT void CreateTargetIndicator(int Slot, PSPELL pSpell, const ItemGlobalIndex& ItemLoc, ItemSpellTypes spelltype);
	EQLIB_OBJECT int DeleteTargetIndicator();
	EQLIB_OBJECT bool IsInTypingMode();
	EQLIB_OBJECT bool IsOkToTransact();
	EQLIB_OBJECT bool ReadClientINIBool(char*, char*, bool);
	EQLIB_OBJECT bool ReadUIINIBool(char*, char*, bool);
	EQLIB_OBJECT char* GetBodyTypeDesc(int);
	EQLIB_OBJECT char* GetClassDesc(int);
	EQLIB_OBJECT char* GetClassThreeLetterCode(int);
	EQLIB_OBJECT char* GetDeityDesc(int);
	EQLIB_OBJECT char* GetInnateDesc(int);
	EQLIB_OBJECT char* GetItemClassDesc(int);
	EQLIB_OBJECT char* GetLangDesc(int);
	EQLIB_OBJECT char* GetRaceDesc(int);
	EQLIB_OBJECT char* GetSingleMessage(uint32_t, int, int*, char*);
	EQLIB_OBJECT char* GrabFirstWord(char*, char*);
	EQLIB_OBJECT char* GrabFirstWord2(char*, char*, int);
	EQLIB_OBJECT char* ReadClientINIString(char*, char*, char*, char*, int);
	EQLIB_OBJECT char* ReadUIINIString(char*, char*, char*, char*, int);
	EQLIB_OBJECT char* stripName(char*);
	EQLIB_OBJECT char* StripShipName(char*, char*);
	EQLIB_OBJECT char* trimName(char*);
	EQLIB_OBJECT class EQPlayer* ClickedPlayer(int, int);
	EQLIB_OBJECT class EQSwitch* ClickedSwitch(int, int);
	EQLIB_OBJECT enum ZONE_REQ_STATUS IsZoneAvailable(char*, EQZoneIndex, enum ZONE_REQ_REASON);
	EQLIB_OBJECT float GetMaxLightRadius();
	EQLIB_OBJECT float ReadClientINIFloat(char*, char*, float);
	EQLIB_OBJECT int BeingIgnored(char*);
	EQLIB_OBJECT int DoLogin(struct HWND__*, struct HINSTANCE__*);
	EQLIB_OBJECT int GetCombatSound(class EQPlayer*, class EQPlayer*);
	EQLIB_OBJECT int GetCurrentLanguage() const;
	EQLIB_OBJECT int HandleItems(void*, int);
	EQLIB_OBJECT int IsFriend(char const*);
	EQLIB_OBJECT int IsValidName(char*);
	EQLIB_OBJECT int LootCorpse(class EQPlayer*, int);
	EQLIB_OBJECT int MoveMoney(int, int, int, int, int, bool);
	EQLIB_OBJECT int msgStartIcon(void*);
	EQLIB_OBJECT int msgStartIeq(void*);
	EQLIB_OBJECT int msgStartInotes(void*);
	EQLIB_OBJECT int ProcessMBox();
	EQLIB_OBJECT int ReadClientINIInt(char*, char*, int);
	EQLIB_OBJECT int ReadUIINIInt(char*, char*, int);
	EQLIB_OBJECT int TypingMode();
	EQLIB_OBJECT unsigned char HandleWorldMessage(struct connection_t*, uint32_t, char*, uint32_t);
	EQLIB_OBJECT unsigned char IFoundMyVehicle();
	EQLIB_OBJECT void DoLoadScreenProgressBar(int, char const*, ...);
	EQLIB_OBJECT void ApplyPoison(unsigned long);
	EQLIB_OBJECT void Camp();
	EQLIB_OBJECT void CancelSneakHide();
	EQLIB_OBJECT void ChatServerConnect(char*, int, char*, char*);
	EQLIB_OBJECT void ChatServerDisconnect();
	EQLIB_OBJECT void ChatServerGiveTime();
	EQLIB_OBJECT void ChatServerMessage(char*);
	EQLIB_OBJECT void ChatServerNotificationAdd(bool, char*, char*, int);
	EQLIB_OBJECT void ChatServerNotificationFlush();
	EQLIB_OBJECT void CleanupBadFiles();
	EQLIB_OBJECT void clr_chat_input();
	EQLIB_OBJECT void Consider(class EQPlayer*, void*);
	EQLIB_OBJECT void CopyFirstWord(char*, char*);
	EQLIB_OBJECT void CreateDataSubdirectories();
	EQLIB_OBJECT void CreateFilenameServerCode(char*);
	EQLIB_OBJECT void CreateIniFilenames();
	EQLIB_OBJECT void CreateInitialActors();
	EQLIB_OBJECT void DeacSpellScreen();
	EQLIB_OBJECT void Disband();
	EQLIB_OBJECT void DisplayScreen(char*);
	EQLIB_OBJECT void DoCharacterSelection();
	EQLIB_OBJECT void doInspect(class EQPlayer*);
	EQLIB_OBJECT void doInvite(uint32_t, char*);
	EQLIB_OBJECT void DoLoadScreen(int);
	EQLIB_OBJECT void doLoot();
	EQLIB_OBJECT void DoMainLoop(struct HWND__*);
	EQLIB_OBJECT void DoNewCharacterCreation();
	EQLIB_OBJECT void DoPercentConvert(char*line, bool bOutGoing);
	EQLIB_OBJECT void DoSplit(char*);
	EQLIB_OBJECT void DoTellWindow(char*, char*, char*, void*, int, bool);
	EQLIB_OBJECT void OutputTextToLog(const char*Text);
	EQLIB_OBJECT void doUnInvite(char*);
	EQLIB_OBJECT void DropHeldItemOnGround(int);
	EQLIB_OBJECT void DropHeldMoneyOnGround(int);
	EQLIB_OBJECT void DropItemOrMoneyOnPlayer(class EQPlayer*);
	EQLIB_OBJECT void dsp_chat(char const*);
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT void dsp_chat(const char *line, int color = 273, bool bLogIsOk = true, bool bConvertPercent = true, char*SomeStr = NULL);
#else
	EQLIB_OBJECT void dsp_chat(const char *line, int color, bool bLogIsOk, bool bConvertPercent);
#endif
	EQLIB_OBJECT void dsp_chat(char const*, int, bool);
	EQLIB_OBJECT void Emote();
	EQLIB_OBJECT void EnterZone(struct HWND__*);
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT int Follow(int);
#else
	EQLIB_OBJECT int Follow();
#endif
	EQLIB_OBJECT void FreeSwitches();
	EQLIB_OBJECT void GetSndDriver();
	EQLIB_OBJECT void GetZoneInfoFromNetwork(char*);
	EQLIB_OBJECT void GuildDelete();
	EQLIB_OBJECT void GuildInvite(char*, char*);
	EQLIB_OBJECT void GuildLeader(char*);
	EQLIB_OBJECT void GuildPeace(char*);
	EQLIB_OBJECT void GuildRemove(char*);
	EQLIB_OBJECT void GuildSay(char*);
	EQLIB_OBJECT void GuildStatus(char*);
	EQLIB_OBJECT void GuildWar(char*, int);
	EQLIB_OBJECT void InitCommands();
	EQLIB_OBJECT void initCustom();
	EQLIB_OBJECT void InterpretCmd(class EQPlayer*, char*);
	EQLIB_OBJECT void Invite(int);
	EQLIB_OBJECT void InviteOk(char*);
	EQLIB_OBJECT void IssueLfgGroupQuery(struct LfgGroupQuery*);
	EQLIB_OBJECT void IssueLfgPlayerQuery(struct LfgPlayerQuery*);
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT void IssuePetCommand(ePetCommandType, int TargetID, bool bQuiet, bool bsomethingelse = 1);
#else
	EQLIB_OBJECT void IssuePetCommand(ePetCommandType, int TargetID, bool bQuiet);
#endif
	EQLIB_OBJECT void Kill(char*, char*);
	EQLIB_OBJECT void LeaveBankMode(bool);
	EQLIB_OBJECT void LeaveGuildMaster();
	EQLIB_OBJECT void LeftClickedOnPlayer(class EQPlayer*);
	EQLIB_OBJECT void LMouseDown(int, int);
	EQLIB_OBJECT void LMouseUp(int, int);
	EQLIB_OBJECT void loadCustom();
	EQLIB_OBJECT void loadCustomFromINI(char*);
	EQLIB_OBJECT void loadOptions();
	EQLIB_OBJECT void loadSoundsGame();
	EQLIB_OBJECT void LoadStringTables();
	EQLIB_OBJECT void LoadSwitchesNonAvatar(EQZoneIndex);
	EQLIB_OBJECT void LocalDeath(struct _EQPlayerDeath*, unsigned char);
	EQLIB_OBJECT void MouseWheelScrolled(int);
	EQLIB_OBJECT void MoveToZone(int, char*, int, int, float, float, float, int);
	EQLIB_OBJECT void MoveToZone(char*, char*, int, enum ZONE_REQ_REASON);
	EQLIB_OBJECT void MoveToZone(EQZoneIndex, char*, int, enum ZONE_REQ_REASON);
	EQLIB_OBJECT void PrepareLocalPCForRepop();
	EQLIB_OBJECT void ProcessControls();
	EQLIB_OBJECT void ProcessGame(struct HWND__*, struct HINSTANCE__*);
	EQLIB_OBJECT void ProcessLocalPCIni(int);
	EQLIB_OBJECT void procMouse(int);
	EQLIB_OBJECT void RemoveCharacterOptionFile(char*);
	EQLIB_OBJECT void ReportDeath(struct _EQPlayerDeath*);
	EQLIB_OBJECT void ReportSuccessfulHit(EQSuccessfulHit*pHit, unsigned char bOutputText, int ActualHeal);
	EQLIB_OBJECT void reqChannel();
	EQLIB_OBJECT void ResetVisionRGBs();
	EQLIB_OBJECT void RightClickedOnPlayer(class EQPlayer*, int);
	EQLIB_OBJECT void RMouseDown(int, int);
	EQLIB_OBJECT void RMouseUp(int, int);
	EQLIB_OBJECT void SaveCamerasToINI();
	EQLIB_OBJECT void saveCustom();
	EQLIB_OBJECT void saveOptions();
	EQLIB_OBJECT void saveOptions2();
	EQLIB_OBJECT void SavePC(int, int, unsigned char);
	EQLIB_OBJECT void SavePCForce(int);
	EQLIB_OBJECT void send_auction();
	EQLIB_OBJECT void send_broadcast();
	EQLIB_OBJECT void send_chat();
	EQLIB_OBJECT void send_gsay();
	EQLIB_OBJECT void send_ooc();
	EQLIB_OBJECT void send_petition();
	EQLIB_OBJECT void send_private();
	EQLIB_OBJECT void send_shout();
	EQLIB_OBJECT void send_social(int, char*, char*);
	EQLIB_OBJECT void send_tell(char*, char*);
	EQLIB_OBJECT void send_update_filters();
	EQLIB_OBJECT void SendLightInfo(class EQPlayer*, unsigned char);
	EQLIB_OBJECT void SendNewText(int, char*, char*);
	EQLIB_OBJECT void SetDefaultDamageDescByRace(char*, int, unsigned char);
	EQLIB_OBJECT void SetDefaultGameValues();
	EQLIB_OBJECT void SetGameState(int);
	EQLIB_OBJECT void SetLfgGroupStatus(struct LfgGroupStatus*);
	EQLIB_OBJECT void SetLfgPlayerStatus(struct LfgPlayerStatus*);
	EQLIB_OBJECT void SetPlayerAppearanceFromPInfo(class EQPlayer*, int, bool);
	EQLIB_OBJECT void SetTimedFog(int);
	EQLIB_OBJECT void SetupCharSelectCamera();
	EQLIB_OBJECT void Sit();
	EQLIB_OBJECT void SortSpellLoadouts();
	EQLIB_OBJECT void StartCasting(void*);
	EQLIB_OBJECT void StartNetworkGame(struct HWND__*, struct HINSTANCE__*, char*);
	EQLIB_OBJECT void Surname(char*);
	EQLIB_OBJECT void ToggleAutoSplit();
	EQLIB_OBJECT void UpdateMyAppearance();
	EQLIB_OBJECT void UseCharge(unsigned long);
	EQLIB_OBJECT void WhatTimeIsIt();
	EQLIB_OBJECT void Who(char*);
	EQLIB_OBJECT void WriteBoolToClientINI(bool, char*, char*);
	EQLIB_OBJECT void WriteBoolToUIINI(bool, char*, char*);
	EQLIB_OBJECT void WriteFloatToClientINI(float, char*, char*);
	EQLIB_OBJECT void WriteIntToClientINI(int, char*, char*);
	EQLIB_OBJECT void WriteIntToUIINI(int, char*, char*);
	EQLIB_OBJECT void WriteStringToClientINI(char*, char*, char*);
	EQLIB_OBJECT void WriteStringToUIINI(char*, char*, char*);

	// virtual
	EQLIB_OBJECT void CshOnBuddyStatusChange(char*, int BuddyStatus);
	EQLIB_OBJECT void CshOnChannelListChange();
	EQLIB_OBJECT void CshOnMessage(char*, char*, int, char*, bool);
	EQLIB_OBJECT void CshOnPlayerEntering(char*, int, char*);
	EQLIB_OBJECT void CshOnPlayerLeaving(char*, int, char*);
};

EQLIB_OBJECT class CExploreModeWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CExploreModeWnd::CExploreModeWnd(class CXWnd*);
	EQLIB_OBJECT void CExploreModeWnd::Activate();

	// virtual
	EQLIB_OBJECT CExploreModeWnd::~CExploreModeWnd();
	EQLIB_OBJECT void CExploreModeWnd::Deactivate();
};

EQLIB_OBJECT class CExtendedTargetWnd : public CSidlScreenWnd
{
public:
};

// Size: 258h see 53F643 Nov 29 2018 Beta 
EQLIB_OBJECT class CFactionWnd : public CSidlScreenWnd
{
public:
	CFactionWnd(class CXWnd*);
};

EQLIB_OBJECT class CFacePick : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CFacePick(class CXWnd*);
	EQLIB_OBJECT void Activate();
	EQLIB_OBJECT void SetFaceSelectionsFromPlayer();

	// virtual
	EQLIB_OBJECT ~CFacePick();
	EQLIB_OBJECT int Draw() const;
	EQLIB_OBJECT int OnProcessFrame();
	EQLIB_OBJECT int WndNotification(class CXWnd*, uint32_t, void*);
	EQLIB_OBJECT void Deactivate();

	// private
	EQLIB_OBJECT void CycleThroughFHEB(int, int);
	EQLIB_OBJECT void Init();
	EQLIB_OBJECT void ShowButtonGroup(int, bool);
};

EQLIB_OBJECT class CFindItemWnd : public CSidlScreenWnd //, public WndEventHandler but we just add the member LastCheckTime
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

EQLIB_OBJECT class CFeedbackWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CFeedbackWnd(class CXWnd*);
	EQLIB_OBJECT void Activate();

	// virtual
	EQLIB_OBJECT ~CFeedbackWnd();
	EQLIB_OBJECT int WndNotification(class CXWnd*, uint32_t, void*);
	EQLIB_OBJECT void Deactivate();
};

EQLIB_OBJECT class CUnSerializeBuffer
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

EQLIB_OBJECT class CFindLocationWnd : public CSidlScreenWnd
{
	// has virtuals, but we get those from CSidlScreenWnd
public:
	bool HandleFindBegin();
	void HandleFindEnd();
	void HandleRowClicked(int Index);
	void HandleFindableZoneConnectionsMessage(CUnSerializeBuffer& buf);
};

EQLIB_OBJECT class CFileSelectionWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CFileSelectionWnd(class CXWnd*);
	EQLIB_OBJECT class CXStr GetSelectedFile(int);
	EQLIB_OBJECT int GetSelectedFileCount();
	EQLIB_OBJECT void Activate(class CXWnd*, int);
	EQLIB_OBJECT void Callback(bool);

	// virtual
	EQLIB_OBJECT ~CFileSelectionWnd();
	EQLIB_OBJECT int WndNotification(class CXWnd*, uint32_t, void*);
	EQLIB_OBJECT void Deactivate();

	// private
	EQLIB_OBJECT bool DirectoryEmpty(IShellFolder*, struct _ITEMIDLIST*);
	EQLIB_OBJECT unsigned long GetPath(IShellFolder*, struct _ITEMIDLIST*, bool, class CXStr &);
	EQLIB_OBJECT void ClearFileList();
	EQLIB_OBJECT void GoSubdirectory(struct _ITEMIDLIST*);
	EQLIB_OBJECT void MakeFilePath();
	EQLIB_OBJECT void UpdateButtons();
	EQLIB_OBJECT void UpdateFileList();
};

EQLIB_OBJECT class CFriendsWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CFriendsWnd(class CXWnd*);
	EQLIB_OBJECT void Activate();
	EQLIB_OBJECT void UpdateFriendsList();
	EQLIB_OBJECT void UpdateIgnoreList();

	// virtual
	EQLIB_OBJECT ~CFriendsWnd();
	EQLIB_OBJECT int WndNotification(class CXWnd*, uint32_t, void*);
	EQLIB_OBJECT void Deactivate();

	// protected
	EQLIB_OBJECT void AddFriend();
	EQLIB_OBJECT void AddIgnore();
	EQLIB_OBJECT void UpdateButtons();
};

EQLIB_OBJECT class CGaugeDrawTemplate
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

EQLIB_OBJECT class CGaugeTemplate
{
public:
	EQLIB_OBJECT CGaugeTemplate(class CParamGauge*);

	// virtual
	EQLIB_OBJECT ~CGaugeTemplate();
};

// size 0x248 see 7E24DB in Sep 21 2018
EQLIB_OBJECT class CGaugeWnd : public CXWnd
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

EQLIB_OBJECT CGaugeWnd::CGaugeWnd(class CXWnd*, uint32_t, class CXRect, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, int, unsigned long, unsigned long, bool, int, int, int, int);
EQLIB_OBJECT class CXRect CGaugeWnd::CalcFillRect(class CXRect*, int) const;
EQLIB_OBJECT class CXRect CGaugeWnd::CalcLinesFillRect(class CXRect*, int) const;
EQLIB_OBJECT void CGaugeWnd::SpecialToolTip();
// virtual
EQLIB_OBJECT CGaugeWnd::~CGaugeWnd();
EQLIB_OBJECT int CGaugeWnd::Draw() const;
EQLIB_OBJECT int CGaugeWnd::HandleLButtonUp(class CXPoint, uint32_t);
EQLIB_OBJECT int CGaugeWnd::OnProcessFrame();
//EQLIB_OBJECT void* CGaugeWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CGaugeWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGaugeWnd::SetAttributesFromSidl(class CParamScreenPiece*);
};

class CGemsGameWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CGemsGameWnd::CGemsGameWnd(class CXWnd*);
EQLIB_OBJECT void CGemsGameWnd::Activate();
EQLIB_OBJECT void CGemsGameWnd::MoveCurBlock(int);
// virtual
EQLIB_OBJECT CGemsGameWnd::~CGemsGameWnd();
EQLIB_OBJECT int CGemsGameWnd::HandleLButtonUp(class CXPoint, uint32_t);
EQLIB_OBJECT int CGemsGameWnd::OnProcessFrame();
EQLIB_OBJECT int CGemsGameWnd::PostDraw() const;
EQLIB_OBJECT int CGemsGameWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CGemsGameWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CGemsGameWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGemsGameWnd::Deactivate();
// private
EQLIB_OBJECT bool CGemsGameWnd::BadSpecial(int) const;
EQLIB_OBJECT bool CGemsGameWnd::LegalBlockMove(int, int, int, int, bool);
EQLIB_OBJECT int CGemsGameWnd::GetRndBlockImage();
EQLIB_OBJECT void CGemsGameWnd::ActivateSpecialMode(int);
EQLIB_OBJECT void CGemsGameWnd::AdvanceToNextWave();
EQLIB_OBJECT void CGemsGameWnd::CheckForMatches(int, int);
EQLIB_OBJECT void CGemsGameWnd::CheckForNewHighScore();
EQLIB_OBJECT void CGemsGameWnd::ClearBlock(struct _GemsBlock*);
EQLIB_OBJECT void CGemsGameWnd::ClearHighScores();
EQLIB_OBJECT void CGemsGameWnd::DoMatchScore(int);
EQLIB_OBJECT void CGemsGameWnd::DrawSpellGem(int, class CXRect, int, bool) const;
EQLIB_OBJECT void CGemsGameWnd::GetNextBlock();
EQLIB_OBJECT void CGemsGameWnd::Init();
EQLIB_OBJECT void CGemsGameWnd::MakeBlockDrop(int, int, int);
EQLIB_OBJECT void CGemsGameWnd::MarkHigherBlocksFalling(int, int);
EQLIB_OBJECT void CGemsGameWnd::ProcessMatches(int);
EQLIB_OBJECT void CGemsGameWnd::ProcessMoveCurBlock(int);
EQLIB_OBJECT void CGemsGameWnd::ReadHighScores();
EQLIB_OBJECT void CGemsGameWnd::Restart();
EQLIB_OBJECT void CGemsGameWnd::SetNextUpdate();
EQLIB_OBJECT void CGemsGameWnd::SetPause(bool);
EQLIB_OBJECT void CGemsGameWnd::TogglePause();
EQLIB_OBJECT void CGemsGameWnd::Update();
EQLIB_OBJECT void CGemsGameWnd::UpdateDisplay();
EQLIB_OBJECT void CGemsGameWnd::WriteHighScores();
};

class PopDialogHandler
{
public:
	//this has a vftable
	DWORD vfTable;
};
class CGiveWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler2
{
public:
	CButtonWnd *pMoneyButton[4];
    CButtonWnd *TradeButton;
    CButtonWnd*CancelButton;
	CLabel*NPCNameLabel;
	CInvSlotWnd*pInvSlotWnd[4];

EQLIB_OBJECT CGiveWnd::CGiveWnd(class CXWnd*);
EQLIB_OBJECT void CGiveWnd::Activate();
EQLIB_OBJECT void CGiveWnd::UpdateGiveDisplay();
// virtual
EQLIB_OBJECT CGiveWnd::~CGiveWnd();
EQLIB_OBJECT int CGiveWnd::OnProcessFrame();
EQLIB_OBJECT int CGiveWnd::PostDraw() const;
EQLIB_OBJECT int CGiveWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CGiveWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CGiveWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGiveWnd::Deactivate();
// private
EQLIB_OBJECT void CGiveWnd::Init();
};

class CGroupSearchFiltersWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CGroupSearchFiltersWnd::CGroupSearchFiltersWnd(class CXWnd*);
EQLIB_OBJECT bool CGroupSearchFiltersWnd::ShouldFilterPlayer(char const*, char const*) const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::UseExclusiveSearchMode() const;
EQLIB_OBJECT void CGroupSearchFiltersWnd::Activate();
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleAddDesiredGuild();
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleAddExcludedGuild();
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleDesiredGuildsSelected();
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleExcludeGuildsSelected();
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleRemoveAllDesiredGuilds();
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleRemoveAllExcludedGuilds();
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleRemoveDesiredGuild();
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleRemoveExcludedGuild();
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleUseFriendsListSelected();
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleUseIgnoreListSelected();
// virtual
EQLIB_OBJECT CGroupSearchFiltersWnd::~CGroupSearchFiltersWnd();
EQLIB_OBJECT int CGroupSearchFiltersWnd::OnProcessFrame();
EQLIB_OBJECT int CGroupSearchFiltersWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CGroupSearchFiltersWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CGroupSearchFiltersWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGroupSearchFiltersWnd::Deactivate();
// private
EQLIB_OBJECT bool CGroupSearchFiltersWnd::GuildIsInDesiredGuildsList(char const*) const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::GuildIsInExcludedGuildsList(char const*) const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::Load();
EQLIB_OBJECT bool CGroupSearchFiltersWnd::NameIsInFriendsList(char const*) const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::NameIsInIgnoreList(char const*) const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::UseDesiredGuilds() const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::UseExcludedGuilds() const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::UseFriendsList() const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::UseIgnoreList() const;
EQLIB_OBJECT void CGroupSearchFiltersWnd::ClearUiPointers();
EQLIB_OBJECT void CGroupSearchFiltersWnd::FetchUiPointers();
EQLIB_OBJECT void CGroupSearchFiltersWnd::InitPieces();
EQLIB_OBJECT void CGroupSearchFiltersWnd::Save() const;
};

class CGroupSearchWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CGroupSearchWnd::CGroupSearchWnd(class CXWnd*);
EQLIB_OBJECT void CGroupSearchWnd::Activate(int);
EQLIB_OBJECT void CGroupSearchWnd::AddGroupResult(struct LfgGroupResult const*);
EQLIB_OBJECT void CGroupSearchWnd::AddPlayerResult(struct LfgPlayerResult const*);
EQLIB_OBJECT void CGroupSearchWnd::HandleDeselectAllClasses();
EQLIB_OBJECT void CGroupSearchWnd::HandleDoubleClickedOnPlayer(char const*);
EQLIB_OBJECT void CGroupSearchWnd::HandleGroupInfoPost();
EQLIB_OBJECT void CGroupSearchWnd::HandleGroupInfoRemove();
EQLIB_OBJECT void CGroupSearchWnd::HandleGroupInfoUpdate();
EQLIB_OBJECT void CGroupSearchWnd::HandleGroupMakeupChanged();
EQLIB_OBJECT void CGroupSearchWnd::HandleGroupResultColSelected(int);
EQLIB_OBJECT void CGroupSearchWnd::HandleGroupResultRowSelected(int);
EQLIB_OBJECT void CGroupSearchWnd::HandleNumericSort(class SListWndSortInfo*);
EQLIB_OBJECT void CGroupSearchWnd::HandleOpenFiltersWindow();
EQLIB_OBJECT void CGroupSearchWnd::HandlePlayerInfoPost();
EQLIB_OBJECT void CGroupSearchWnd::HandlePlayerInfoRemove();
EQLIB_OBJECT void CGroupSearchWnd::HandlePlayerInfoUpdate();
EQLIB_OBJECT void CGroupSearchWnd::HandlePlayerResultColSelected(int);
EQLIB_OBJECT void CGroupSearchWnd::HandleQueryingForGroups();
EQLIB_OBJECT void CGroupSearchWnd::HandleQueryingForPlayers();
EQLIB_OBJECT void CGroupSearchWnd::HandleSelectAllClasses();
EQLIB_OBJECT void CGroupSearchWnd::ResetGroupList();
EQLIB_OBJECT void CGroupSearchWnd::ResetPlayerList();
EQLIB_OBJECT void CGroupSearchWnd::SendServerLfgOff();
EQLIB_OBJECT void CGroupSearchWnd::SendServerLfgOn();
EQLIB_OBJECT void CGroupSearchWnd::SendServerLfpOff();
EQLIB_OBJECT void CGroupSearchWnd::SendServerLfpOn();
// virtual
EQLIB_OBJECT CGroupSearchWnd::~CGroupSearchWnd();
EQLIB_OBJECT int CGroupSearchWnd::OnProcessFrame();
EQLIB_OBJECT int CGroupSearchWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CGroupSearchWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CGroupSearchWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGroupSearchWnd::Deactivate();
// private
EQLIB_OBJECT bool CGroupSearchWnd::IsLevelRangeValid(int, int) const;
EQLIB_OBJECT bool CGroupSearchWnd::PlayerShouldBeFiltered(struct LfgPlayerData const*) const;
EQLIB_OBJECT int CGroupSearchWnd::CheckIfCurrentLfgInfoIsValid() const;
EQLIB_OBJECT int CGroupSearchWnd::CheckIfCurrentLfpInfoIsValid() const;
EQLIB_OBJECT int CGroupSearchWnd::GetDesiredClassesFlag() const;
EQLIB_OBJECT int CGroupSearchWnd::GetDesiredGroupMaxLevel() const;
EQLIB_OBJECT int CGroupSearchWnd::GetDesiredGroupMinLevel() const;
EQLIB_OBJECT int CGroupSearchWnd::GetDesiredPlayerMaxLevel() const;
EQLIB_OBJECT int CGroupSearchWnd::GetDesiredPlayerMinLevel() const;
EQLIB_OBJECT int CGroupSearchWnd::GetEqClassType(int) const;
EQLIB_OBJECT int CGroupSearchWnd::GroupInfoPageOnProcessFrame();
EQLIB_OBJECT int CGroupSearchWnd::GroupInfoPageWndNotification(class CXWnd*, uint32_t, void*);
EQLIB_OBJECT int CGroupSearchWnd::GroupListPageOnProcessFrame();
EQLIB_OBJECT int CGroupSearchWnd::GroupListPageWndNotification(class CXWnd*, uint32_t, void*);
EQLIB_OBJECT int CGroupSearchWnd::PlayerInfoPageOnProcessFrame();
EQLIB_OBJECT int CGroupSearchWnd::PlayerInfoPageWndNotification(class CXWnd*, uint32_t, void*);
EQLIB_OBJECT int CGroupSearchWnd::PlayerListPageOnProcessFrame();
EQLIB_OBJECT int CGroupSearchWnd::PlayerListPageWndNotification(class CXWnd*, uint32_t, void*);
EQLIB_OBJECT int CGroupSearchWnd::RedirectOnProcessFrameTo(class CPageWnd*);
EQLIB_OBJECT int CGroupSearchWnd::RedirectWndNotificationTo(class CPageWnd*, class CXWnd*, uint32_t, void*);
EQLIB_OBJECT void CGroupSearchWnd::ClearUiPointers();
EQLIB_OBJECT void CGroupSearchWnd::FetchUiPointers();
EQLIB_OBJECT void CGroupSearchWnd::FilterOutBadWords(char const*, char*) const;
EQLIB_OBJECT void CGroupSearchWnd::GetDefaultLfgLevelRange(class EQ_PC const*, int*, int*) const;
EQLIB_OBJECT void CGroupSearchWnd::GetDefaultLfpLevelRange(class EQ_PC const*, int*, int*) const;
EQLIB_OBJECT void CGroupSearchWnd::InitLfg();
EQLIB_OBJECT void CGroupSearchWnd::InitLfp();
EQLIB_OBJECT void CGroupSearchWnd::LockQueryButtonAtTime(long);
EQLIB_OBJECT void CGroupSearchWnd::PopUpErrorMessage(int) const;
EQLIB_OBJECT void CGroupSearchWnd::ShowGroupDetails(struct LfgGroupResult const*);
EQLIB_OBJECT void CGroupSearchWnd::UpdateGroupLabel();
EQLIB_OBJECT void CGroupSearchWnd::UpdateLfgPostingStatus();
EQLIB_OBJECT void CGroupSearchWnd::UpdateLfpPostingStatus();
EQLIB_OBJECT void CGroupSearchWnd::UpdatePlayerLabel();
EQLIB_OBJECT void CGroupSearchWnd::UpdateRemainingQueryLockedTime(long);
};
//Sep 21 2018
class CGroupWnd : public CSidlScreenWnd
{
public:
	CButtonWnd *InviteButton;
    CButtonWnd *DisbandButton;
    CButtonWnd *FollowButton;
    CButtonWnd *DeclineButton;
    CButtonWnd *LFGButton;
	CGaugeWnd	*HPGauge[6];
	CGaugeWnd	*PetGauge[6];
	CGaugeWnd	*ManaGauge[6];
	CGaugeWnd	*EnduranceGauge[6];
	CLabel		*HPLabel[6];
	CLabel		*HPPercLabel[6];
	CLabel		*ManaLabel[6];
	CLabel		*ManaPercLabel[6];
	CLabel		*EnduranceLabel[6];
	CLabel		*EndurancePercLabel[6];
	COLORREF	HPTextColor[6];
	CButtonWnd	*GroupTankButton[6];
	CButtonWnd	*GroupAssistButton[6];
	CButtonWnd	*GroupPullerButton[6];
    CButtonWnd	*GroupMarkNPCButton[6];
	CLabel		*AggroPercLabel[6];
	long		Timer;
	CContextMenu*GroupContextMenu;
	bool		bPetbars;
	bool		bManabars;
	bool		bEndurancebars;
	bool		bAggroPct;
	int			PetBarIndex;
	int			ManaBarIndex;
	int			EnduranceBarIndex;
	int			AggroPctIndex;
	int			RoleSeparatorID;
	int			RoleSelectMenu;
	int			RoleSelectMenuID;
	bool		bPlayerInvited;

EQLIB_OBJECT CGroupWnd::CGroupWnd(class CXWnd*);
EQLIB_OBJECT void CGroupWnd::Activate();
EQLIB_OBJECT void CGroupWnd::CreateLocalMenu();
EQLIB_OBJECT void CGroupWnd::KeyMapUpdated();
EQLIB_OBJECT void CGroupWnd::SetInvited(bool);
EQLIB_OBJECT void CGroupWnd::UpdateContextMenu();
// virtual
EQLIB_OBJECT CGroupWnd::~CGroupWnd();
EQLIB_OBJECT int CGroupWnd::Draw() const;
EQLIB_OBJECT int CGroupWnd::OnProcessFrame();
EQLIB_OBJECT int CGroupWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CGroupWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CGroupWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGroupWnd::Deactivate();
EQLIB_OBJECT void CGroupWnd::LoadIniInfo();
EQLIB_OBJECT void CGroupWnd::StoreIniInfo();
// protected
EQLIB_OBJECT void CGroupWnd::UpdateButtons();
EQLIB_OBJECT void CGroupWnd::UpdateDisplay(int Index, PSPAWNINFO groupmember, COLORREF NameColor, UINT RoleBits);
// private
EQLIB_OBJECT void CGroupWnd::Init();
};

class CGuild
{
public:
EQLIB_OBJECT CGuild::CGuild();
EQLIB_OBJECT bool CGuild::ValidGuildName(int);
EQLIB_OBJECT char* CGuild::GetGuildMotd();
EQLIB_OBJECT char* CGuild::GetGuildMotdAuthor();
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT char* CGuild::GetGuildName(int64_t);
EQLIB_OBJECT int64_t CGuild::GetGuildIndex(char*);
#else
EQLIB_OBJECT char* CGuild::GetGuildName(DWORD);
EQLIB_OBJECT int  CGuild::GetGuildIndex(char*);
#endif
EQLIB_OBJECT class GuildMember* CGuild::FindMemberByName(char*);
EQLIB_OBJECT void CGuild::DeleteAllMembers();
EQLIB_OBJECT void CGuild::DemoteMember(class GuildMember*);
EQLIB_OBJECT void CGuild::HandleGuildMessage(struct connection_t*, uint32_t, char*, uint32_t);
EQLIB_OBJECT void CGuild::SendPublicCommentChange(char*, char*);
EQLIB_OBJECT void CGuild::SetGuildMotd(struct guildmotdSet*);
// virtual
EQLIB_OBJECT CGuild::~CGuild();
// private
EQLIB_OBJECT void CGuild::AddGuildMember(class GuildMember*);
EQLIB_OBJECT void CGuild::ChangeGuildMemberName(char*);
EQLIB_OBJECT void CGuild::HandleAddGuildMember(char*, int);
EQLIB_OBJECT void CGuild::HandleDeleteGuildResponse(char*);
EQLIB_OBJECT void CGuild::HandleGuildInvite(struct connection_t*, uint32_t, char*, uint32_t);
EQLIB_OBJECT void CGuild::HandleMemberLevelUpdate(char*);
EQLIB_OBJECT void CGuild::HandleRemoveGuildMember(char*, int);
EQLIB_OBJECT void CGuild::InitializeFromDump(char*);
EQLIB_OBJECT void CGuild::UpdateGuildMemberOnWindow(class GuildMember*);
EQLIB_OBJECT void CGuild::UpdateMemberStatus(char*);
EQLIB_OBJECT void CGuild::UpdatePublicComment(char*);
};

class CGuildMgmtWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CGuildMgmtWnd::CGuildMgmtWnd(class CXWnd*);
EQLIB_OBJECT void CGuildMgmtWnd::Activate();
EQLIB_OBJECT void CGuildMgmtWnd::AddMember(class GuildMember*);
EQLIB_OBJECT void CGuildMgmtWnd::Clean();
EQLIB_OBJECT void CGuildMgmtWnd::DumpToFile(char*);
EQLIB_OBJECT void CGuildMgmtWnd::RemoveMember(class GuildMember*);
EQLIB_OBJECT void CGuildMgmtWnd::RenameMember(char*, char*);
EQLIB_OBJECT void CGuildMgmtWnd::SetMOTD(char*, char*);
EQLIB_OBJECT void CGuildMgmtWnd::SetPlayerCount(int);
EQLIB_OBJECT void CGuildMgmtWnd::SortList(int, bool);
EQLIB_OBJECT void CGuildMgmtWnd::UpdateButtons();
EQLIB_OBJECT void CGuildMgmtWnd::UpdateListMember(class GuildMember*, int);
// virtual
EQLIB_OBJECT CGuildMgmtWnd::~CGuildMgmtWnd();
EQLIB_OBJECT int CGuildMgmtWnd::OnProcessFrame();
EQLIB_OBJECT int CGuildMgmtWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CGuildMgmtWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CGuildMgmtWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGuildMgmtWnd::Deactivate();
// protected
EQLIB_OBJECT char* CGuildMgmtWnd::GetPersonalNote(char*);
EQLIB_OBJECT int CGuildMgmtWnd::FindListMember(class GuildMember*);
EQLIB_OBJECT void CGuildMgmtWnd::CleanAndRefillListWnd(bool);
EQLIB_OBJECT void CGuildMgmtWnd::CreatePersonalNotesFilename();
EQLIB_OBJECT void CGuildMgmtWnd::LoadINI();
EQLIB_OBJECT void CGuildMgmtWnd::LoadPersonalNotes();
EQLIB_OBJECT void CGuildMgmtWnd::SavePersonalNotes();
EQLIB_OBJECT void CGuildMgmtWnd::SetPersonalNote(char*, char*);
// private
EQLIB_OBJECT void CGuildMgmtWnd::Init();
};

class ChannelServerApi
{
public:
EQLIB_OBJECT ChannelServerApi::~ChannelServerApi();
EQLIB_OBJECT ChannelServerApi::ChannelServerApi(char*, int, char*, char*, class ChannelServerHandler*, bool, bool, char*);
EQLIB_OBJECT char* ChannelServerApi::GetChannelName(int);
//EQLIB_OBJECT enum ChannelServerApi::Status ChannelServerApi::GetStatus();
EQLIB_OBJECT int ChannelServerApi::GetChannelCount();
EQLIB_OBJECT int ChannelServerApi::GetChannelNumber(char*);
EQLIB_OBJECT static char* __cdecl ChannelServerApi::AllocateString(char*);
EQLIB_OBJECT static char* __cdecl ChannelServerApi::Strncpy(char*, char*, int);
EQLIB_OBJECT static int __cdecl ChannelServerApi::GetNextField(char*, int, char**, char);
EQLIB_OBJECT static void* __cdecl ChannelServerApi::SmartResize(void*, int, int);
EQLIB_OBJECT void ChannelServerApi::GiveTime();
EQLIB_OBJECT void ChannelServerApi::SendMessageA(char*);
// virtual
EQLIB_OBJECT void ChannelServerApi::OnRoutePacket(class UdpConnection*, unsigned char const*, int);
// protected
EQLIB_OBJECT void ChannelServerApi::FreeChannelList();
//EQLIB_OBJECT void ChannelServerApi::SetBuddyStatus(char*, enum ChannelServerApi::BuddyStatus);
EQLIB_OBJECT void ChannelServerApi::SortBuddyList();
};

class ChannelServerHandler
{
public:
// virtual
EQLIB_OBJECT void ChannelServerHandler::CshOnLoginConfirm(bool);
EQLIB_OBJECT void ChannelServerHandler::CshOnPacket(void*, int, char*, int, char*, bool);
};
struct CKeyUInt32ValueInt32
{
	uint32_t key;
	int value;
};
class CHashCXStrInt32
{
public:
EQLIB_OBJECT CHashCXStrInt32::~CHashCXStrInt32();
EQLIB_OBJECT CHashCXStrInt32::CHashCXStrInt32();
EQLIB_OBJECT bool CHashCXStrInt32::Insert(class CXStr const &, int);
EQLIB_OBJECT bool CHashCXStrInt32::LookUp(class CXStr const &, int &) const;
EQLIB_OBJECT void CHashCXStrInt32::Reset();
// private
EQLIB_OBJECT int CHashCXStrInt32::KeyToBin(class CXStr const &) const;
	ArrayClass2_RO<ArrayClass2_RO<CKeyUInt32ValueInt32>> HashData;
};

class CHelpWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CHelpWnd::CHelpWnd(class CXWnd*);
EQLIB_OBJECT void CHelpWnd::Activate();
EQLIB_OBJECT void CHelpWnd::SetFile(class CXStr);
// virtual
EQLIB_OBJECT CHelpWnd::~CHelpWnd();
EQLIB_OBJECT int CHelpWnd::HandleKeyboardMsg(uint32_t, uint32_t, bool);
EQLIB_OBJECT int CHelpWnd::OnProcessFrame();
EQLIB_OBJECT int CHelpWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CHelpWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CHelpWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CHelpWnd::Deactivate();
// private
EQLIB_OBJECT void CHelpWnd::Init();
};
class CHotButton// : public CXWnd
{
public:
	CXW
/*0x1e0*/ int					BarIndex;
/*0x1e4*/ int					ButtonIndex;
/*0x1e8*/ UINT					Timer;
/*0x1ec*/ CTextureAnimation*	DecalIcon;
/*0x1f0*/ int					LastButtonType;
/*0x1f4*/ int					LastButtonSlot;
/*0x1f8*/ CHAR					LastButtonPage;
/*0x1f9*/ EqItemGuid			LastItemGuid;
/*0x20c*/ int					LastItemId;
/*0x210*/ int					LastIconType;
/*0x214*/ int					LastIconSlot;
/*0x218*/ PCXSTR				LastLabel;
/*0x21c*/ PCXSTR				DefaultLabel;
/*0x220*/ bool					bForceUpdate;
/*0x224*/ void*				pKeyMapText;//CTextObjectInterface
/*0x228*/ int					Unknown0x228;
/*0x22c*/ CButtonWnd*			pButtonWnd;
/*0x230*/ CInvSlotWnd*			pInvSlotWnd;
/*0x234*/ CSpellGemWnd*		pSpellGemWnd;
/*0x238*/ tagSIZE				BaseSize;
/*0x240*/ int					ButtonPercentSize;
/*0x244*/ tagSIZE				BaseButtonSize;
/*0x24c*/ tagSIZE				BaseDecalSize;
/*0x254*/ tagSIZE				BaseInvButtonSize;
/*0x25c*/ tagSIZE				BaseSpellButtonSize;
/*0x264*/ int					Unknown0x264;
/*0x268*/
EQLIB_OBJECT void CHotButton::SetButtonSize(int percent, bool bUpdateParent = true);
};
class CHotButtonWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CHotButtonWnd::CHotButtonWnd(class CXWnd*);
EQLIB_OBJECT void CHotButtonWnd::Activate();
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT void CHotButtonWnd::DoHotButton(int Button, int AllowAutoRightClick, int something);
#else
EQLIB_OBJECT void CHotButtonWnd::DoHotButton(int Button, int AllowAutoRightClick);
#endif
EQLIB_OBJECT void CHotButtonWnd::DoHotButtonRightClick(int);
EQLIB_OBJECT void CHotButtonWnd::UpdatePage();
// virtual
EQLIB_OBJECT CHotButtonWnd::~CHotButtonWnd();
EQLIB_OBJECT int CHotButtonWnd::Draw() const;
EQLIB_OBJECT int CHotButtonWnd::OnProcessFrame();
EQLIB_OBJECT int CHotButtonWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CHotButtonWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CHotButtonWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CHotButtonWnd::Deactivate();
// private
EQLIB_OBJECT void CHotButtonWnd::Init();
};

class CIMECandidateList
{
public:
EQLIB_OBJECT CIMECandidateList::~CIMECandidateList();
EQLIB_OBJECT CIMECandidateList::CIMECandidateList(class CIMEManager*);
EQLIB_OBJECT int CIMECandidateList::show(class CIMEComposition const*) const;
// private
EQLIB_OBJECT int CIMECandidateList::repositionImeCandidateList(int, int) const;
};

class CIMEComposition
{
public:
EQLIB_OBJECT CIMEComposition::~CIMEComposition();
EQLIB_OBJECT CIMEComposition::CIMEComposition(class CIMEManager*);
EQLIB_OBJECT class CXPoint CIMEComposition::getCursorPoint() const;
EQLIB_OBJECT class CXRect CIMEComposition::getCompositionArea() const;
EQLIB_OBJECT int CIMEComposition::addInputChar(unsigned short);
EQLIB_OBJECT int CIMEComposition::addInputString(class CXStr const &, int);
EQLIB_OBJECT int CIMEComposition::addInputString(unsigned short*, int);
EQLIB_OBJECT int CIMEComposition::addStringFromIme(long);
EQLIB_OBJECT void CIMEComposition::directToEditWnd(class CEditWnd*);
// private
EQLIB_OBJECT int CIMEComposition::addCompositionHighlights();
EQLIB_OBJECT int CIMEComposition::applyChineseComposingRules(class CXStr*);
EQLIB_OBJECT int CIMEComposition::applyJapaneseComposingRules(class CXStr*);
EQLIB_OBJECT int CIMEComposition::applyKoreanComposingRules(class CXStr*);
EQLIB_OBJECT int CIMEComposition::getCompositionInsertIndex() const;
EQLIB_OBJECT int CIMEComposition::handleImeComposing();
EQLIB_OBJECT int CIMEComposition::handleImeResult();
EQLIB_OBJECT int CIMEComposition::repositionImeCompositionWindow(int, int) const;
EQLIB_OBJECT struct CompAttr* CIMEComposition::allocateImeCompositionAttributes() const;
EQLIB_OBJECT unsigned short* CIMEComposition::allocateImeCompositionString(long) const;
EQLIB_OBJECT void CIMEComposition::backupCurrentText();
EQLIB_OBJECT void CIMEComposition::revertToBackupText();
};

class CIMEManager
{
public:
EQLIB_OBJECT CIMEManager::~CIMEManager();
EQLIB_OBJECT CIMEManager::CIMEManager(struct HWND__*);
EQLIB_OBJECT bool CIMEManager::imeIsOff() const;
EQLIB_OBJECT bool CIMEManager::imeIsOn() const;
EQLIB_OBJECT int CIMEManager::getImeProperties() const;
EQLIB_OBJECT int CIMEManager::getInputLanguage() const;
EQLIB_OBJECT int CIMEManager::getInputState() const;
EQLIB_OBJECT int CIMEManager::handleWndProc(unsigned int, unsigned int, long);
EQLIB_OBJECT int CIMEManager::setInputEditWnd(class CEditWnd*);
EQLIB_OBJECT struct HWND__* CIMEManager::getWindowHandle() const;
EQLIB_OBJECT void CIMEManager::setInputState(int);
EQLIB_OBJECT void CIMEManager::turnImeOff();
EQLIB_OBJECT void CIMEManager::turnImeOn();
// private
EQLIB_OBJECT int CIMEManager::handleAddChar(unsigned short);
EQLIB_OBJECT int CIMEManager::handleChangeCandidates();
EQLIB_OBJECT int CIMEManager::handleCloseCandidates();
EQLIB_OBJECT int CIMEManager::handleEndComposition();
EQLIB_OBJECT int CIMEManager::handleImeChanged();
EQLIB_OBJECT int CIMEManager::handleImeStatusChanged();
EQLIB_OBJECT int CIMEManager::handleInputComposition(long);
EQLIB_OBJECT int CIMEManager::handleOpenCandidates();
EQLIB_OBJECT int CIMEManager::handleStartComposition();
EQLIB_OBJECT int CIMEManager::queryImeLanguage() const;
EQLIB_OBJECT int CIMEManager::queryImeProperties() const;
EQLIB_OBJECT void CIMEManager::enableIme(bool);
};

class CIMEStatusBar
{
public:
EQLIB_OBJECT CIMEStatusBar::CIMEStatusBar(class CIMEManager*);
EQLIB_OBJECT int CIMEStatusBar::hide();
EQLIB_OBJECT int CIMEStatusBar::show(class CIMEComposition const*);
EQLIB_OBJECT int CIMEStatusBar::update();
// private
EQLIB_OBJECT int CIMEStatusBar::repositionStatusWindow();
EQLIB_OBJECT void CIMEStatusBar::handleChineseSimplifiedStatusChange(unsigned long);
EQLIB_OBJECT void CIMEStatusBar::handleChineseTraditionalStatusChange(unsigned long);
EQLIB_OBJECT void CIMEStatusBar::handleJapaneseStatusChange(unsigned long);
EQLIB_OBJECT void CIMEStatusBar::handleKoreanStatusChange(unsigned long);
};

class CInspectWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CInspectWnd::CInspectWnd(class CXWnd*);
EQLIB_OBJECT void CInspectWnd::Activate(struct _inspect*);
EQLIB_OBJECT void CInspectWnd::PlayerBeingDeleted(class EQPlayer*);
// virtual
EQLIB_OBJECT CInspectWnd::~CInspectWnd();
EQLIB_OBJECT int CInspectWnd::Draw() const;
EQLIB_OBJECT int CInspectWnd::OnProcessFrame();
EQLIB_OBJECT int CInspectWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CInspectWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CInspectWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CInspectWnd::Deactivate();
// private
EQLIB_OBJECT void CInspectWnd::AcceptInspectText();
EQLIB_OBJECT void CInspectWnd::Init();
};

class CInventoryWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CInventoryWnd::CInventoryWnd(class CXWnd*);
EQLIB_OBJECT void CInventoryWnd::Activate();
// virtual
EQLIB_OBJECT CInventoryWnd::~CInventoryWnd();
EQLIB_OBJECT int CInventoryWnd::Draw() const;
EQLIB_OBJECT int CInventoryWnd::HandleLButtonUp(class CXPoint, uint32_t);
EQLIB_OBJECT int CInventoryWnd::OnProcessFrame();
EQLIB_OBJECT int CInventoryWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CInventoryWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CInventoryWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CInventoryWnd::Deactivate();
// private
EQLIB_OBJECT long CInventoryWnd::GetInventoryQtyFromCoinType(int);
EQLIB_OBJECT void CInventoryWnd::ClickedMoneyButton(int, int);
EQLIB_OBJECT void CInventoryWnd::DestroyHeld();
EQLIB_OBJECT void CInventoryWnd::Init();
EQLIB_OBJECT void CInventoryWnd::UpdateMoneyDisplay();
DWORD         Unknown0x0xx[0x22];
int64_t		VitalityCap;
int			AAVitalityCap;
};

class CInvSlot
{
public:
	void*pvftable;
	CInvSlotWnd*pInvSlotWnd;
	CTextureAnimation*pInvSlotAnimation;
	int Index;
	bool bEnabled;
EQLIB_OBJECT CInvSlot::CInvSlot();
EQLIB_OBJECT bool CInvSlot::IllegalBigBank(int);
EQLIB_OBJECT void CInvSlot::DoDrinkEatPoison(class EQ_Item*, int);
EQLIB_OBJECT void CInvSlot::HandleLButtonDown(class CXPoint);
EQLIB_OBJECT void CInvSlot::HandleLButtonHeld(class CXPoint);
EQLIB_OBJECT void CInvSlot::HandleLButtonUp(class CXPoint, bool);
EQLIB_OBJECT void CInvSlot::HandleLButtonUpAfterHeld(class CXPoint);
EQLIB_OBJECT void CInvSlot::HandleRButtonDown(class CXPoint);
EQLIB_OBJECT void CInvSlot::HandleRButtonHeld(class CXPoint);
EQLIB_OBJECT void CInvSlot::HandleRButtonUp(class CXPoint*);
EQLIB_OBJECT void CInvSlot::HandleRButtonUpAfterHeld(class CXPoint);
EQLIB_OBJECT void CInvSlot::SetInvSlotWnd(class CInvSlotWnd*);
EQLIB_OBJECT void CInvSlot::SetItem(class EQ_Item*);
EQLIB_OBJECT void CInvSlot::SliderComplete(int);
EQLIB_OBJECT void CInvSlot::GetItemBase(struct _CONTENTS**);
EQLIB_OBJECT void CInvSlot::UpdateItem();
// virtual
EQLIB_OBJECT CInvSlot::~CInvSlot();
//EQLIB_OBJECT void* CInvSlot::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CInvSlot::`vector deleting destructor'(unsigned int);
};


class CInvSlotMgr
{
public:
EQLIB_OBJECT CInvSlotMgr::CInvSlotMgr();
EQLIB_OBJECT class CInvSlot* CInvSlotMgr::CreateInvSlot(class CInvSlotWnd*);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT class CInvSlot* CInvSlotMgr::FindInvSlot(int TopSlot, int SubSlot=-1, int FindWindowRelated = 0, bool bSomething = 1);
#else
EQLIB_OBJECT class CInvSlot* CInvSlotMgr::FindInvSlot(int TopSlot, int SubSlot=-1);
#endif
EQLIB_OBJECT bool CInvSlotMgr::MoveItem(ItemGlobalIndex*from, ItemGlobalIndex*to, bool bDebugOut, bool CombineIsOk, bool MoveFromIntoToBag = false, bool MoveToIntoFromBag = false);
EQLIB_OBJECT void CInvSlotMgr::Process();
EQLIB_OBJECT void CInvSlotMgr::SelectSlot(class CInvSlot*);
EQLIB_OBJECT void CInvSlotMgr::UpdateSlots();
// virtual
EQLIB_OBJECT CInvSlotMgr::~CInvSlotMgr();
//EQLIB_OBJECT void* CInvSlotMgr::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CInvSlotMgr::`vector deleting destructor'(unsigned int);
};

class CInvSlotTemplate
{
public:
EQLIB_OBJECT CInvSlotTemplate::CInvSlotTemplate(class CParamInvSlot*);
// virtual
EQLIB_OBJECT CInvSlotTemplate::~CInvSlotTemplate();
//EQLIB_OBJECT void* CInvSlotTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CInvSlotTemplate::`vector deleting destructor'(unsigned int);
};

class CInvSlotWnd
{
public:
/****** CXwnd inherits******/
	CXW
/****** ButtonWnd inherits******/
/*0x01e8*/ int		MouseButtonState;
/*0x01ec*/ bool	    bPicture;
/*0x01f0*/ CRadioGroup* pGroup;
/*0x01f4*/ bool	    bChecked;
/*0x01f5*/ bool	    bMouseOverLastFrame;
/*0x01f8*/ tagPOINT	DecalOffset;
/*0x0200*/ tagSIZE	DecalSize;
/*0x0208*/ COLORREF	DecalTint;
/*0x020c*/ RECT		TextOffsets;
/*0x021c*/ int		TextModeBits;
/*0x0220*/ COLORREF	Mouseover;
/*0x0224*/ COLORREF	Pressed;
/*0x0228*/ COLORREF	Disabled;
/*0x022c*/ UINT		CoolDownBeginTime;
/*0x0230*/ UINT		CoolDownDuration;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x0234*/ CXStr*   Indicator;
/*0x0238*/ UINT	    IndicatorVal;
/*0x023c*/ void*    pIndicatorTextObject;
#endif
	/* CButtonDrawTemplate Start*/
/*0x0240*/ CXStr*	Name;
/*0x0244*/ CTextureAnimation*  Normal;
/*0x0248*/ CTextureAnimation*  taPressed;
/*0x024c*/ CTextureAnimation*  Flyby;
/*0x0250*/ CTextureAnimation*  taDisabled;
/*0x0254*/ CTextureAnimation*  PressedFlyby;
/*0x0258*/ CTextureAnimation*  PressedDisabled;
/*0x025c*/ CTextureAnimation*  NormalDecal;
/*0x0260*/ CTextureAnimation*  PressedDecal;
/*0x0264*/ CTextureAnimation*  FlybyDecal;
/*0x0268*/ CTextureAnimation*  DisabledDecal;
/*0x026c*/ CTextureAnimation*  PressedFlybyDecal;
/*0x0270*/ CTextureAnimation*  PressedDisabledDecal;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x0274*/ bool		bAllowButtonClickThrough;
/*0x0275*/ bool		bCoolDownDoDelayedStart;
#endif
/*0x0276*/ bool		bIsCheckbox;
/*0x0277*/ bool		bIsDrawLasso;
/*0x0278*/ UINT		ButtonStyle;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x027c*/ CLabel*  pButtonLabel;
#endif
/*0x0280*/
/****** CInvSlotWnd Start******/
	CTextureAnimation*  pBackground;
	//ItemGlobalIndex	ItemLocation;
	ItemContainerInstance ICLocation;
	ItemIndex iIndex;
	void*   LinkedItem;
	int		ItemOffsetX;
	int		ItemOffsetY;
	CTextureAnimation*	ptItem;
	int		Quantity;
	bool	bSelected;
	int		RecastLeft;
	bool	bHotButton;
	bool	bInventorySlotLinked;
	CInvSlot*   pEQInvSlot;
	void*   pinvslotwndTextObject;
	int		TextFontStyle;
    int		Mode;
	COLORREF	BGTintRollover;
	COLORREF	BGTintNormal;
	long	LastTime;
EQLIB_OBJECT CInvSlotWnd::CInvSlotWnd(CXWnd*pParent, uint32_t ID, CXRect rect,	CTextureAnimation*ptaBackground, ItemGlobalIndex*itemLocation, int ItemOffsetX, int ItemOffsetY);
EQLIB_OBJECT void CInvSlotWnd::SetInvSlot(class CInvSlot*);
// virtual
EQLIB_OBJECT CInvSlotWnd::~CInvSlotWnd();
EQLIB_OBJECT int CInvSlotWnd::Draw() const;
EQLIB_OBJECT int CInvSlotWnd::DrawTooltip(class CXWnd const*) const;
EQLIB_OBJECT int CInvSlotWnd::HandleLButtonDown(class CXPoint, uint32_t);
EQLIB_OBJECT int CInvSlotWnd::HandleLButtonHeld(class CXPoint, uint32_t);
EQLIB_OBJECT int CInvSlotWnd::HandleLButtonUp(class CXPoint, uint32_t);
EQLIB_OBJECT int CInvSlotWnd::HandleLButtonUpAfterHeld(class CXPoint, uint32_t);
EQLIB_OBJECT int CInvSlotWnd::HandleRButtonDown(class CXPoint, uint32_t);
EQLIB_OBJECT int CInvSlotWnd::HandleRButtonHeld(class CXPoint, uint32_t);
EQLIB_OBJECT int CInvSlotWnd::HandleRButtonUp(class CXPoint, uint32_t);
EQLIB_OBJECT int CInvSlotWnd::HandleRButtonUpAfterHeld(class CXPoint, uint32_t);
EQLIB_OBJECT int CInvSlotWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CInvSlotWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CInvSlotWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CInvSlotWnd::SetAttributesFromSidl(class CParamScreenPiece*);
};
enum ItemDisplayFlags
{
	PREVENT_LINK = 0x00000001,
	RECYCLE_WINDOW = 0x00000002,
	FROM_LINK = 0x00000004,
    FROM_BAZAAR_SEARCH = 0x00000008,
    FROM_BARTER_SEARCH = 0x00000010
};

class CItemDisplayWnd : public CSidlScreenWnd
{
public:
/*0x0230*/ CStmlWnd*pDescription;
/*0x0234*/ CStmlWnd*pName;
/*0x0238*/ CButtonWnd*pIconButton;
/*0x023c*/ CStmlWnd*pLore;
/*0x0240*/ CTabWnd*pItemDescriptionTab;
/*0x0244*/ CPageWnd*pDescriptionPage;
/*0x0248*/ CPageWnd*pLorePage;
/*0x024c*/ CSidlScreenWnd*pAppearanceSocketScreen;
/*0x0250*/ CButtonWnd*pAppearanceSocketItem;
/*0x0254*/ CButtonWnd*pAppearanceSocketBuyButton;
/*0x0258*/ CStmlWnd*pAppearanceSocketDescription;
/*0x025c*/ CSidlScreenWnd*pItemSocketScreen[6];
/*0x0274*/ CButtonWnd*pItemSocketItemButton[6];
/*0x028c*/ CStmlWnd*pItemSocketDescription[6];
/*0x02a4*/ PCXSTR ItemInfo;
/*0x02a8*/ PCXSTR MoreText;
/*0x02ac*/ PCXSTR LoreText;
/*0x02b0*/ PCXSTR CreatorName;
/*0x02b4*/ PCXSTR BackupTabTitle;
/*0x02b8*/ PCXSTR SolventText;
/*0x02bc*/ PCXSTR InformationText;
/*0x02c0*/ PCONTENTS pCurrentItem;
/*0x02c4*/ bool bActiveItem;
/*0x02c5*/ bool bItemTextSet;
/*0x02c8*/ CTextureAnimation* pTABuffIcons;
/*0x02cc*/ CTextureAnimation* pTADragIcons;
/*0x02d0*/ bool bTaggable;
/*0x02d1*/ bool bFailed;
/*0x02d4*/ UINT TabCount;
/*0x02d8*/ CLabel*pModButtonLabel;
/*0x02dc*/ CStmlWnd*pConvertButtonStml;
/*0x02e0*/ CLabel*pMadeByLabel;
/*0x02e4*/ CLabel*pCollectedLabel;//for sure
/*0x02e8*/ CLabel*pScribedLabel;
/*0x02ec*/ int Row;
/*0x02f0*/ bool bAntiTwink;
/*0x02f4*/ CButtonWnd*pModButton;
/*0x02f8*/ CButtonWnd*pPrintRealEstateItems;
/*0x02fc*/ CButtonWnd*pConvertButton;
/*0x0300*/ bool bCollected;
/*0x0301*/ bool bReceivedCollectableStatus;
/*0x0304*/ int Group[6];
/*0x031c*/ bool bClickedTwink;
/*0x0320*/ int HeroicCount;
/*0x0324*/ int ItemInfoCount;
/*0x0328*/ CLabel*pItemInfoLabel[13];//for sure at 0x330
/*0x035c*/ CLabel*pStatLabel[0x1a][3];//size 0x138
/*0x0494*/ CLabel*pValueLabel[0x1a][3];//size 0x138
/*0x05cc*/ CLabel*pHeroicLabel[0xd];
/*0x0600*/ int RightClickMenuID;
/*0x0604*/ int RightClickMenuSocketSlot;
/*0x0608*/ int WindowID;
/*0x060c*/

EQLIB_OBJECT CItemDisplayWnd::CItemDisplayWnd(CXWnd*);
EQLIB_OBJECT class CXStr CItemDisplayWnd::CreateEquipmentStatusString(class EQ_Item*);
EQLIB_OBJECT void CItemDisplayWnd::SetItem(PCONTENTS*pCont, int flags);
EQLIB_OBJECT void CItemDisplayWnd::SetItemText(char*);
EQLIB_OBJECT void CItemDisplayWnd::SetSpell(int SpellID, bool HasSpellDescr, int);
EQLIB_OBJECT void CItemDisplayWnd::UpdateStrings();
// virtual
EQLIB_OBJECT CItemDisplayWnd::~CItemDisplayWnd();
EQLIB_OBJECT int CItemDisplayWnd::HandleKeyboardMsg(uint32_t, uint32_t, bool);
EQLIB_OBJECT int CItemDisplayWnd::OnProcessFrame();
EQLIB_OBJECT int CItemDisplayWnd::WndNotification(CXWnd*pWnd, uint32_t Message, void*pData);
//EQLIB_OBJECT void* CItemDisplayWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CItemDisplayWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CItemDisplayWnd::Activate();
EQLIB_OBJECT void CItemDisplayWnd::Deactivate();
// protected
EQLIB_OBJECT class CXStr CItemDisplayWnd::CreateClassString(class EQ_Equipment*);
EQLIB_OBJECT class CXStr CItemDisplayWnd::CreateMealSizeString(class EQ_Equipment*);
EQLIB_OBJECT class CXStr CItemDisplayWnd::CreateModString(class EQ_Equipment*, int, int, int*);
EQLIB_OBJECT class CXStr CItemDisplayWnd::CreateRaceString(class EQ_Equipment*);
EQLIB_OBJECT void CItemDisplayWnd::GetSizeString(int, char*);
EQLIB_OBJECT void CItemDisplayWnd::InsertAugmentRequest(int AugSlot);
EQLIB_OBJECT void CItemDisplayWnd::RemoveAugmentRequest(int AugSlot);
EQLIB_OBJECT bool CItemDisplayWnd::AboutToShow();
EQLIB_OBJECT void CItemDisplayWnd::RequestConvertItem();
};

class CJournalCatWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CJournalCatWnd::CJournalCatWnd(class CXWnd*);
EQLIB_OBJECT void CJournalCatWnd::Activate();
EQLIB_OBJECT void CJournalCatWnd::Clean();
EQLIB_OBJECT void CJournalCatWnd::UpdateAll(bool);
EQLIB_OBJECT void CJournalCatWnd::UpdateButtons();
// virtual
EQLIB_OBJECT CJournalCatWnd::~CJournalCatWnd();
EQLIB_OBJECT int CJournalCatWnd::OnProcessFrame();
EQLIB_OBJECT int CJournalCatWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CJournalCatWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CJournalCatWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CJournalCatWnd::Deactivate();
// protected
EQLIB_OBJECT void CJournalCatWnd::BuildList();
EQLIB_OBJECT void CJournalCatWnd::LoadINI();
EQLIB_OBJECT void CJournalCatWnd::SelectCategory(int);
EQLIB_OBJECT void CJournalCatWnd::SortList(int, bool);
EQLIB_OBJECT void CJournalCatWnd::StoreINI();
EQLIB_OBJECT void CJournalCatWnd::UpdateListWnd(bool);
// private
EQLIB_OBJECT void CJournalCatWnd::Init();
};

class CJournalNPCWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CJournalNPCWnd::CJournalNPCWnd(class CXWnd*);
EQLIB_OBJECT void CJournalNPCWnd::Activate();
EQLIB_OBJECT void CJournalNPCWnd::EnterIntoJournal(char*, float, float, float, char*);
EQLIB_OBJECT void CJournalNPCWnd::LoadJournal(int);
EQLIB_OBJECT void CJournalNPCWnd::SaveJournal();
EQLIB_OBJECT void CJournalNPCWnd::UpdateAll(bool);
EQLIB_OBJECT void CJournalNPCWnd::UpdateCategories();
// virtual
EQLIB_OBJECT CJournalNPCWnd::~CJournalNPCWnd();
EQLIB_OBJECT int CJournalNPCWnd::OnProcessFrame();
EQLIB_OBJECT int CJournalNPCWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CJournalNPCWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CJournalNPCWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CJournalNPCWnd::Deactivate();
// protected
EQLIB_OBJECT void CJournalNPCWnd::BuildList();
EQLIB_OBJECT void CJournalNPCWnd::DoBackups(class CXStr);
EQLIB_OBJECT void CJournalNPCWnd::GetLogState();
EQLIB_OBJECT void CJournalNPCWnd::SelectNPCIndex(int);
EQLIB_OBJECT void CJournalNPCWnd::SortList(int, bool);
EQLIB_OBJECT void CJournalNPCWnd::StoreLogState();
EQLIB_OBJECT void CJournalNPCWnd::UpdateButtons();
EQLIB_OBJECT void CJournalNPCWnd::UpdateListWnd(bool);
// private
EQLIB_OBJECT void CJournalNPCWnd::Init();
};

class CJournalTextWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CJournalTextWnd::CJournalTextWnd(class CXWnd*);
EQLIB_OBJECT void CJournalTextWnd::Activate();
EQLIB_OBJECT void CJournalTextWnd::Clear();
EQLIB_OBJECT void CJournalTextWnd::DisplayNPC(class JournalNPC*);
EQLIB_OBJECT void CJournalTextWnd::SetSearch(class CXStr);
EQLIB_OBJECT void CJournalTextWnd::UpdateAll(bool);
EQLIB_OBJECT void CJournalTextWnd::UpdateCategories();
// virtual
EQLIB_OBJECT CJournalTextWnd::~CJournalTextWnd();
EQLIB_OBJECT int CJournalTextWnd::OnProcessFrame();
EQLIB_OBJECT int CJournalTextWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CJournalTextWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CJournalTextWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CJournalTextWnd::Deactivate();
// protected
EQLIB_OBJECT void CJournalTextWnd::BuildList();
EQLIB_OBJECT void CJournalTextWnd::SelectEntryIndex(int);
EQLIB_OBJECT void CJournalTextWnd::SortList(int, bool);
EQLIB_OBJECT void CJournalTextWnd::UpdateButtons();
EQLIB_OBJECT void CJournalTextWnd::UpdateListWnd(bool);
};

class CKeyCXStrValueInt32
{
public:
EQLIB_OBJECT CKeyCXStrValueInt32::~CKeyCXStrValueInt32();
EQLIB_OBJECT CKeyCXStrValueInt32::CKeyCXStrValueInt32();
//EQLIB_OBJECT void* CKeyCXStrValueInt32::`vector deleting destructor'(unsigned int);
};

//CLabelWnd__CLabelWnd_x
//size 0x200 see 8D5699 in Aug 10 2017 Live
//size 0x210 see 8DCE59 in Sep 11 2017 Test
//size 0x200 see 668D5B in Oct 17 2017 Live
//size 0x1e4 see 86BFC9 in rof2
class CLabelWnd// : public CXWnd
{
public:
EQLIB_OBJECT CLabelWnd::CLabelWnd(CXWnd*pParent, uint32_t ID, const CXRect*rect);
/*0x000*/ PCXWNDVFTABLE pvfTable;
/*0x004*/ CXW_NO_VTABLE				//rof2				
/*0x1e0*/ bool bNoWrap;				/*0x1d8*/
/*0x1e1*/ bool bAlignRight;			/*0x1d9*/
/*0x1e2*/ bool bAlignCenter;		/*0x1da*/
/*0x1e4*/ int  xOffset;				/*0x1dc*/
/*0x1e8*/ bool bResizeHeightToText;	/*0x1e0*/
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x1ec*/ int Unknown0x1ec;
/*0x1f0*/ PCXSTR Text;
/*0x1f4*/ int Unknown0x1f4;
/*0x1f8*/ bool Unknown0x1f8;
/*0x1fc*/ int Unknown0x1fc;
/*0x200*/							/*0x1e4*/
#endif
};
//CLabel__CLabel_x
//size is 0x208 see 79C989 in Aug 10 2017 Live
//size is 0x218 see 7A3819 in Sep 11 2017 Test
//size 0x208 see 7A5739 in Oct 17 2017 Live
//size 0x1e8 see 755709 in Rof2
class CLabel : public CLabelWnd
{
public:								//rof2
/*0x200*/ int EQType;				/*0x1e4*/
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x204*/ int Unknown0x204;
#endif
/*0x208*/							/*0x1e8*/
EQLIB_OBJECT CLabel::CLabel(class CXWnd*pParent, uint32_t id, CXRect*rect, int eqtype = 0);
EQLIB_OBJECT void CLabel::SetAlignCenter(bool);
EQLIB_OBJECT void CLabel::SetAlignRight(bool);
EQLIB_OBJECT void CLabel::SetNoWrap(bool);
// virtual
EQLIB_OBJECT CLabel::~CLabel();
EQLIB_OBJECT int CLabel::Draw() const;
//EQLIB_OBJECT void* CLabel::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CLabel::`vector deleting destructor'(unsigned int);
};

class CLabelTemplate
{
public:
EQLIB_OBJECT CLabelTemplate::CLabelTemplate(class CParamLabel*);
// virtual
EQLIB_OBJECT CLabelTemplate::~CLabelTemplate();
//EQLIB_OBJECT void* CLabelTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CLabelTemplate::`vector deleting destructor'(unsigned int);
};
class CLargeDialogWnd
{
public:
EQLIB_OBJECT void CLargeDialogWnd::Open(bool bYesNoEnabled, class CXStr DialogText, unsigned long closeTimer/*0 means never*/, class CXStr DialogTitle, bool bShowVolumeControls, class CXStr YesText, class CXStr NoText);
};
class CWndDisplayManager
{
public:
	PVOID vfTable;
	ArrayClass2_RO<CXWnd*> pWindows;
	ArrayClass2_RO<LONG> pTimes;
	int MaxWindows;
EQLIB_OBJECT int CWndDisplayManager::FindWindowA(bool bNewWnd);
EQLIB_OBJECT CWndDisplayManager::CWndDisplayManager();
EQLIB_OBJECT CWndDisplayManager::~CWndDisplayManager();
EQLIB_OBJECT bool CWndDisplayManager::CloseNewest();
EQLIB_OBJECT void CWndDisplayManager::CloseAll();
//virtual
EQLIB_OBJECT int CreateWindowInstance();
};
class CItemDisplayManager : public CWndDisplayManager
{
public:
EQLIB_OBJECT int CItemDisplayManager::CreateWindowInstance();
};

class CLineBase
{
public:
EQLIB_OBJECT CLineBase::~CLineBase();
EQLIB_OBJECT CLineBase::CLineBase();
};

class CListboxColumnTemplate
{
public:
EQLIB_OBJECT CListboxColumnTemplate::~CListboxColumnTemplate();
EQLIB_OBJECT CListboxColumnTemplate::CListboxColumnTemplate(class CParamListboxColumn*);
//EQLIB_OBJECT void CListboxColumnTemplate::`default constructor closure'();
};

class CListboxTemplate
{
public:
EQLIB_OBJECT CListboxTemplate::CListboxTemplate(class CParamListbox*);
// virtual
EQLIB_OBJECT CListboxTemplate::~CListboxTemplate();
//EQLIB_OBJECT void* CListboxTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CListboxTemplate::`vector deleting destructor'(unsigned int);
};

class CUITextureInfo
{
public:
EQLIB_OBJECT CUITextureInfo::~CUITextureInfo();
EQLIB_OBJECT CUITextureInfo::CUITextureInfo(class CXStr, class CXSize);
EQLIB_OBJECT CUITextureInfo::CUITextureInfo(class CXStr, int);
EQLIB_OBJECT CUITextureInfo::CUITextureInfo(class CUITextureInfo const &);
EQLIB_OBJECT CUITextureInfo::CUITextureInfo(uint32_t, int);
EQLIB_OBJECT CUITextureInfo::CUITextureInfo();
EQLIB_OBJECT class CXStr CUITextureInfo::GetName() const;
EQLIB_OBJECT int CUITextureInfo::Draw(class CXRect, class CXRect, class CXRect, unsigned long*, unsigned long*) const;
EQLIB_OBJECT int CUITextureInfo::Draw(class CXRect, class CXRect, class CXRect, unsigned long, unsigned long) const;
EQLIB_OBJECT int CUITextureInfo::Preload();
EQLIB_OBJECT int CUITextureInfo::Tile(class CXRect, unsigned long*, unsigned long*) const;
EQLIB_OBJECT int CUITextureInfo::Tile(class CXRect, unsigned long, unsigned long) const;
EQLIB_OBJECT class CUITextureInfo & CUITextureInfo::operator=(class CUITextureInfo const &);
};
struct SListWndCell
{
    SListWndCell() {
		pTA = NULL;
        Color = RGB(255, 255, 255);
		bOnlyDrawTexture = false;
		pWnd = NULL;
    }
    const CTextureAnimation*pTA;
    struct _CXSTR*Text;
    COLORREF Color;
	bool bOnlyDrawTexture;
	CXWnd*pWnd;
};
struct SListWndCell_RO
{
    CTextureAnimation*pTA;
    struct _CXSTR*Text;
    COLORREF Color;
	bool bOnlyDrawTexture;
	CXWnd*pWnd;
};
struct TreeData
{
	TreeData() : Depth(0), bIsExpandable(false) {}
	int		Depth;
	bool	bIsExpandable;
};
struct TreeData_RO
{
/*0x00*/ int		Depth;
/*0x04*/ bool	bIsExpandable;
/*0x08*/
};
struct SListWndLine
{
	ArrayClass<SListWndCell> Cells;
#if defined(ROF2EMU) || defined(UFEMU)
	UINT	Data;
#else
	uint64_t	Data;
#endif
	int		Height;
	bool	bSelected;
	bool	bEnabled;
	TreeData Treedata;
	CHAR	TooltipText[256];
	bool	bVisible;
	SListWndLine() : Data(0), Height(-1), bSelected(false), bEnabled(true), bVisible(true) {
	}
};
struct SListWndLine_RO
{
/*0x00*/ ArrayClass_RO<SListWndCell_RO> Cells;
#if defined(ROF2EMU) || defined(UFEMU)
/*0x10*/ UINT	Data;
#else
/*0x10*/ uint64_t	Data;
#endif
/*0x18*/ int		Height;
/*0x1c*/ bool	bSelected;
/*0x1d*/ bool	bEnabled;
/*0x20*/ TreeData_RO Treedata;
/*0x28*/ CHAR	TooltipText[0x100];
/*0x128*/ bool	bVisible;
/*0x12C*/ int Filler0x12C;
/*0x130*/
};
struct SListWndColumn
{
/*0x00*/	int	Width;
/*0x04*/	int	MinWidth;
/*0x08*/	SIZE	TextureSize;
/*0x10*/	POINT	TextureOffset;
/*0x18*/    PCXSTR	StrLabel;
#if defined(ROF2EMU) || defined(UFEMU)
/*0x20*/    UINT	Data;
#else
/*0x20*/    uint64_t	Data;
#endif
/*0x28*/    UINT	Flags;
/*0x2c*/	UINT	Type;
/*0x30*/    CTextureAnimation	*pTextureAnim;
/*0x34*/	CTextureAnimation	*pSelected;
/*0x38*/	CTextureAnimation	*pMouseOver;
/*0x3c*/	PCXSTR	Tooltip;
/*0x40*/	bool	bResizeable;
/*0x44*/
	//SListWndColumn() {};
	SListWndColumn(PCXSTR strLabel = 0, int width = 0, CTextureAnimation*pta = NULL, UINT flags = 0,
		UINT type = 0x03, CTextureAnimation*pselected = NULL, CTextureAnimation*pmouseOver = NULL,
		PCXSTR tooltip = 0, bool bResizeable = false, SIZE textureSize = { 0 }, POINT textureOffset = { 0 }) {
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
struct SListWndColumn_RO
{
/*0x00*/	int	Width;
/*0x04*/	int	MinWidth;
/*0x08*/	SIZE	TextureSize;
/*0x10*/	POINT	TextureOffset;
/*0x18*/    PCXSTR	StrLabel;
#if defined(ROF2EMU) || defined(UFEMU)
/*0x20*/    UINT	Data;
#else
/*0x20*/    uint64_t	Data;
#endif
/*0x28*/    UINT	Flags;
/*0x2c*/	UINT	Type;
/*0x30*/    CTextureAnimation	*pTextureAnim;
/*0x34*/	CTextureAnimation	*pSelected;
/*0x38*/	CTextureAnimation	*pMouseOver;
/*0x3c*/	PCXSTR	Tooltip;
/*0x40*/	bool	bResizeable;
/*0x44*/	int Filler0x44;
/*0x48*/
};
//Size is 0x298 in eqgame Sep 11 2017 Test (see 8D1D4C) eqmule
class CListWnd//ok Look... this SHOULD inherit CXWnd but doing so... calls the constructor, and we dont want that... so... : public CXWnd
{
public:
	//we include CXW instead...
/*0x000*/ PCCONTEXTMENUVFTABLE pvfTable;
/*0x004*/ CXW_NO_VTABLE
//alright now that we got that settled, it also has members of its own:
//look, as a reminder to myself and future maintainers:
//NOTE: ItemsArray has subids and this is the reason why you WILL NOT see
//anything useful in the debugger sometimes if you cursor over it and expand it...
//So... list->ItemsArray.m_array[0].Cells.m_array[1] might display something
//while list->ItemsArray.m_array[0].Cells.m_array[0] might not
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x1f0*/ int Filler0x1f0;
#endif
/*0x1f4*/ ArrayClass_RO<SListWndLine_RO> ItemsArray; //see CListWnd__GetItemData_x 0x8BD768                 add     ecx, 1F4h
/*0x204*/ ArrayClass_RO<SListWndColumn_RO> Columns;
/*0x214*/ int	CurSel;
/*0x218*/ int	CurCol;
/*0x21c*/ int	DownItem;
/*0x220*/ int	ScrollOffsetY;
/*0x224*/ int	HeaderHeight;
/*0x228*/ int	FirstVisibleLine;
/*0x22c*/ int	SortCol;
/*0x230*/ bool	bSortAsc;
/*0x231*/ bool	bFixedHeight;
/*0x232*/ bool	bOwnerDraw;
/*0x233*/ bool	bCalcHeights;
/*0x234*/ bool	bColumnSizable;
/*0x238*/ int	LineHeight;
/*0x23c*/ int	ColumnSepDragged;
/*0x240*/ int	ColumnSepMouseOver;
/*0x244*/ COLORREF	HeaderText;
/*0x248*/ COLORREF	Highlight;
/*0x24c*/ COLORREF	Selected;
/*0x250*/ CUITextureInfo2	BGHeader;//size 0x18
/*0x268*/ COLORREF	BGHeaderTint;
/*0x26c*/ CTextureAnimation	*pRowSep;
/*0x270*/ CTextureAnimation	*pColumnSep;
/*0x274*/ CEditBaseWnd	*pEditCell;
/*0x278*/ void	*pItemDataSomething;
/*0x27c*/ bool	bHasItemTooltips;
/*0x280*/ RECT	PrevInsideRect;
/*0x290*/ UINT	ListWndStyle;
/*0x294*/ LONG	LastVisibleTime;//change to a __time32_t? not really important...
/*0x298*/

EQLIB_OBJECT CListWnd::CListWnd(class CXWnd*, uint32_t, class CXRect const &);
EQLIB_OBJECT CListWnd::CListWnd() {};
EQLIB_OBJECT bool CListWnd::IsLineEnabled(int) const;
EQLIB_OBJECT class CTextureAnimation const* CListWnd::GetColumnAnimation(int) const;
EQLIB_OBJECT class CTextureAnimation const* CListWnd::GetColumnAnimationMouseOver(int) const;
EQLIB_OBJECT class CTextureAnimation const* CListWnd::GetColumnAnimationSelected(int) const;
EQLIB_OBJECT class CTextureAnimation const* CListWnd::GetItemIcon(int, int) const;
EQLIB_OBJECT class CXRect CListWnd::GetHeaderRect(int) const;
//CListWnd::GetItemRect looks like it has 3 args in ida but one of them is PUSH ESI so that doesnt count...
//checked on apr 29 2016 by eqmule (it has 2)
EQLIB_OBJECT class CXRect CListWnd::GetItemRect(int, int) const;
EQLIB_OBJECT class CXRect CListWnd::GetSeparatorRect(int) const;
EQLIB_OBJECT class CXStr CListWnd::GetColumnLabel(int) const;
EQLIB_OBJECT class CXStr*CListWnd::GetItemText(class CXStr*, int, int) const;
EQLIB_OBJECT int CListWnd::AddColumn(const CXStr& Label, CTextureAnimation* pTA, int Width, uint32_t Flags, CXStr Tooltip = "", uint32_t Type = 3, CTextureAnimation* pTASelected = 0, CTextureAnimation* pTAMouseOver = 0, bool bResizeable = false, tagSIZE TextureSize = { 0, 0 }, tagPOINT TextureOffset = { 0, 0 });
EQLIB_OBJECT int CListWnd::AddColumn(const CXStr& Label, int Width, uint32_t Flags, uint32_t Type = 3/*text/icon type*/);
EQLIB_OBJECT int CListWnd::AddLine(SListWndLine*);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT int CListWnd::AddString(const CXStr &Str, COLORREF Color, uint64_t Data = 0, const CTextureAnimation*pTa = NULL, const char*TooltipStr = NULL);
EQLIB_OBJECT int CListWnd::AddString(const char*Str, COLORREF Color, uint64_t Data, const CTextureAnimation*pTa, const char* TooltipStr = NULL);
#else
EQLIB_OBJECT int CListWnd::AddString(const CXStr &Str, COLORREF Color, uint32_t Data = 0, const CTextureAnimation*pTa = NULL, const char*TooltipStr = NULL);
EQLIB_OBJECT int CListWnd::AddString(const char*Str, COLORREF Color, uint32_t Data, const CTextureAnimation*pTa, const char* TooltipStr = NULL);
#endif
EQLIB_OBJECT int CListWnd::GetColumnJustification(int) const;
EQLIB_OBJECT int CListWnd::GetColumnMinWidth(int) const;
EQLIB_OBJECT CXStr CListWnd::GetColumnTooltip(int) const;
EQLIB_OBJECT int CListWnd::GetColumnWidth(int) const;
EQLIB_OBJECT int CListWnd::GetCurCol() const;
EQLIB_OBJECT int CListWnd::GetCurSel() const;
EQLIB_OBJECT int CListWnd::GetItemAtPoint(POINT*pt) const;
EQLIB_OBJECT int CListWnd::GetItemHeight(int) const;
EQLIB_OBJECT uint32_t CListWnd::GetColumnFlags(int) const;
#if !defined(ROF2EMU) && !defined(UFEMU) 
EQLIB_OBJECT uint64_t CListWnd::GetItemData(int) const;
#else
EQLIB_OBJECT uint32_t CListWnd::GetItemData(int) const;
#endif
EQLIB_OBJECT unsigned long CListWnd::GetItemColor(int, int) const;
EQLIB_OBJECT void CListWnd::CalculateFirstVisibleLine();
EQLIB_OBJECT void CListWnd::CalculateLineHeights();
EQLIB_OBJECT void CListWnd::CalculateVSBRange();
EQLIB_OBJECT void CListWnd::ClearAllSel();
EQLIB_OBJECT void CListWnd::ClearSel(int);
EQLIB_OBJECT void CListWnd::CloseAndUpdateEditWindow();
EQLIB_OBJECT void CListWnd::EnableLine(int Index, bool bVal);
EQLIB_OBJECT void CListWnd::EnsureVisible(int);
EQLIB_OBJECT void CListWnd::ExtendSel(int);
EQLIB_OBJECT void CListWnd::GetItemAtPoint(CXPoint*pt, int*ID, int*SubItem) const;
EQLIB_OBJECT void CListWnd::InsertLine(int ID, SListWndLine*rEntry);
EQLIB_OBJECT void CListWnd::RemoveLine(int);
EQLIB_OBJECT void CListWnd::RemoveString(int);
EQLIB_OBJECT void CListWnd::SetColors(unsigned long, unsigned long, unsigned long);
EQLIB_OBJECT void CListWnd::SetColumnJustification(int, int);
EQLIB_OBJECT void CListWnd::SetColumnLabel(int, class CXStr);
EQLIB_OBJECT void CListWnd::SetColumnWidth(int, int);
EQLIB_OBJECT void CListWnd::SetCurSel(int);
EQLIB_OBJECT void CListWnd::SetItemColor(int, int, unsigned long);
#if !defined(ROF2EMU) && !defined(UFEMU) 
EQLIB_OBJECT void CListWnd::SetItemData(int ID, uint64_t Data);
#else
EQLIB_OBJECT void CListWnd::SetItemData(int ID, uint32_t Data);
#endif
EQLIB_OBJECT void CListWnd::SetItemText(int ID, int SubID, class CXStr*Text);
EQLIB_OBJECT void CListWnd::ShiftColumnSeparator(int, int);
EQLIB_OBJECT void CListWnd::ToggleSel(int);
// virtual
EQLIB_OBJECT CListWnd::~CListWnd();
EQLIB_OBJECT class CTextureAnimation* CListWnd::GetCursorToDisplay() const;
EQLIB_OBJECT int CListWnd::Compare(SListWndLine const &, SListWndLine const &) const;
EQLIB_OBJECT int CListWnd::Draw() const;
EQLIB_OBJECT int CListWnd::DrawBackground() const;
EQLIB_OBJECT int CListWnd::DrawColumnSeparators() const;
EQLIB_OBJECT int CListWnd::DrawHeader() const;
EQLIB_OBJECT int CListWnd::DrawItem(int, int, int) const;
EQLIB_OBJECT int CListWnd::DrawLine(int) const;
EQLIB_OBJECT int CListWnd::DrawSeparator(int) const;
EQLIB_OBJECT int CListWnd::HandleLButtonDown(class CXPoint, uint32_t);
EQLIB_OBJECT int CListWnd::HandleLButtonUp(class CXPoint, uint32_t);
EQLIB_OBJECT int CListWnd::HandleLButtonUpAfterHeld(class CXPoint, uint32_t);
EQLIB_OBJECT int CListWnd::HandleMouseMove(class CXPoint, uint32_t);
EQLIB_OBJECT int CListWnd::HandleRButtonDown(class CXPoint, uint32_t);
EQLIB_OBJECT int CListWnd::OnHeaderClick(class CXPoint);
EQLIB_OBJECT int CListWnd::OnMove(class CXRect);
EQLIB_OBJECT int CListWnd::OnResize(int, int);
EQLIB_OBJECT int CListWnd::OnVScroll(EScrollCode, int);
EQLIB_OBJECT int CListWnd::SetVScrollPos(int Pos);
EQLIB_OBJECT int CListWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CListWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CListWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CListWnd::DeleteAll();
EQLIB_OBJECT void CListWnd::Sort();
EQLIB_OBJECT void CListWnd::SetColumnsSizable(bool bColumnsSizable);
EQLIB_OBJECT void CListWnd::GetWndPosition(CXWnd*pWnd, int &ItemID, int &SubItemID) const;
EQLIB_OBJECT void CListWnd::SetItemWnd(int Index, int SubItem, CXWnd*pWnd);
EQLIB_OBJECT CXWnd*CListWnd::GetItemWnd(int Index, int SubItem) const;
EQLIB_OBJECT void CListWnd::SetItemIcon(int Index, int SubItem, const CTextureAnimation*pTA);
EQLIB_OBJECT void CListWnd::CalculateCustomWindowPositions();
};
//Size is 0x290 in eagame 2016 Nov 14 eqmule
class CContextMenu// cant do this it calls the constructor if we create a menu so no... : public CListWnd
{
public:
//we include the CListWnd class manually instead... it has a CXWnd first...
/*0x000*/ PCCONTEXTMENUVFTABLE pvfTable;
/*0x004*/ CXW_NO_VTABLE
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x1e0*/ int Filler0x1e0;
#endif
/*0x1e4*/ ArrayClass_RO<SListWndLine_RO> ItemsArray; //see CListWnd__GetItemData_x 0x8BD768                 add     ecx, 1F4h
/*0x1f4*/ ArrayClass_RO<SListWndColumn_RO> Columns;
/*0x204*/ int	CurSel;
/*0x208*/ int	CurCol;
/*0x20c*/ int	DownItem;
/*0x210*/ int	ScrollOffsetY;
/*0x214*/ int	HeaderHeight;
/*0x218*/ int	FirstVisibleLine;
/*0x21c*/ int	SortCol;
/*0x220*/ bool	bSortAsc;
/*0x221*/ bool	bFixedHeight;
/*0x222*/ bool	bOwnerDraw;
/*0x223*/ bool	bCalcHeights;
/*0x224*/ bool	bColumnSizable;
/*0x228*/ int	LineHeight;
/*0x22c*/ int	ColumnSepDragged;
/*0x230*/ int	ColumnSepMouseOver;
/*0x234*/ COLORREF	HeaderText;
/*0x238*/ COLORREF	Highlight;
/*0x23c*/ COLORREF	Selected;
/*0x240*/ CUITextureInfo2	BGHeader;//size 0x18
/*0x258*/ COLORREF	BGHeaderTint;
/*0x25c*/ CTextureAnimation	*pRowSep;
/*0x260*/ CTextureAnimation	*pColumnSep;
/*0x264*/ CEditBaseWnd	*pEditCell;
/*0x268*/ void	*pItemDataSomething;
/*0x26c*/ bool	bHasItemTooltips;
/*0x270*/ RECT	PrevInsideRect;
/*0x280*/ UINT	ListWndStyle;
/*0x284*/ LONG	LastVisibleTime;//change to a __time32_t? not really important...
/*0x288*/


/*0x288*/ int NumItems;
/*0x28C*/ int Unknown0x28C;
/*0x290*/
EQLIB_OBJECT int CContextMenu::InsertMenuItemA(CXStr*str, unsigned int position, unsigned int ItemID, bool bChecked, COLORREF Color, bool bEnable);
EQLIB_OBJECT CContextMenu::CContextMenu(CXWnd*pParent, uint32_t MenuID, const CXRect& rect);
EQLIB_OBJECT CContextMenu::CContextMenu(CXWnd*, uint32_t, tagRECT*);
EQLIB_OBJECT int CContextMenu::AddMenuItem(CXStr const &str, unsigned int MenuID/*Set HighPart as the ID for submenus and LowPart is then the subindex*/, bool bChecked = false, COLORREF Color = 0xFFFFFFFF, bool bEnable = true);
EQLIB_OBJECT int CContextMenu::AddSeparator();
EQLIB_OBJECT void CContextMenu::Activate(class CXPoint, int, int);
EQLIB_OBJECT void CContextMenu::CheckMenuItem(int ID, bool bVal = true, bool bUncheckAll = false);
EQLIB_OBJECT void CContextMenu::EnableMenuItem(int ID, bool bVal = true);
EQLIB_OBJECT void CContextMenu::RemoveAllMenuItems();
EQLIB_OBJECT void CContextMenu::RemoveMenuItem(int id);
EQLIB_OBJECT void CContextMenu::SetMenuItem(int ID, const CXStr &Str, bool bChecked = false, COLORREF Color = 0xFFFFFFFF, bool bEnable = true);
// virtual
EQLIB_OBJECT CContextMenu::~CContextMenu();
EQLIB_OBJECT CContextMenu::CContextMenu() {
	Sleep(0);
};
EQLIB_OBJECT int CContextMenu::OnKillFocus(class CXWnd*);
//EQLIB_OBJECT void* CContextMenu::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CContextMenu::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CContextMenu::Deactivate();
};

class CLoadskinWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CLoadskinWnd::CLoadskinWnd(class CXWnd*);
EQLIB_OBJECT void CLoadskinWnd::Activate();
EQLIB_OBJECT void CLoadskinWnd::UpdateSkinList();
// virtual
EQLIB_OBJECT CLoadskinWnd::~CLoadskinWnd();
EQLIB_OBJECT int CLoadskinWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CLoadskinWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CLoadskinWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CLoadskinWnd::Deactivate();
};

class CLootWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CLootWnd::CLootWnd(class CXWnd*);
EQLIB_OBJECT void CLootWnd::Activate(unsigned char, long, long, long, long);
EQLIB_OBJECT void CLootWnd::AddContainerToLootArray(class EQ_Item*);
EQLIB_OBJECT void CLootWnd::AddEquipmentToLootArray(class EQ_Item*);
EQLIB_OBJECT void CLootWnd::AddNoteToLootArray(class EQ_Item*);
EQLIB_OBJECT void CLootWnd::Deactivate(bool);
EQLIB_OBJECT void CLootWnd::LootAll(bool);
EQLIB_OBJECT void CLootWnd::RequestLootSlot(int Slot, bool bAutoInventory);
EQLIB_OBJECT void CLootWnd::SlotLooted(int);
// virtual
EQLIB_OBJECT CLootWnd::~CLootWnd();
EQLIB_OBJECT int CLootWnd::OnProcessFrame();
EQLIB_OBJECT int CLootWnd::PostDraw() const;
EQLIB_OBJECT int CLootWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CLootWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CLootWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CLootWnd::Deactivate();
// private
EQLIB_OBJECT void CLootWnd::FinalizeLoot();
EQLIB_OBJECT void CLootWnd::Init();
/*0x208*/ BYTE Unknown0x1b8[0xd1];   // should be 2d9 on 2012/01/11
/*0x2d9*/ BYTE bLootAll;
/*0x2da*/
};

class CMapToolbarWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CMapToolbarWnd::CMapToolbarWnd(class CXWnd*);
EQLIB_OBJECT void CMapToolbarWnd::Activate();
EQLIB_OBJECT void CMapToolbarWnd::SetAutoMapButton(bool);
// virtual
EQLIB_OBJECT CMapToolbarWnd::~CMapToolbarWnd();
EQLIB_OBJECT int CMapToolbarWnd::OnProcessFrame();
EQLIB_OBJECT int CMapToolbarWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CMapToolbarWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CMapToolbarWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CMapToolbarWnd::Deactivate();
};
//class CMapViewWnd : public CSidlScreenWnd, public WndEventHandler
class CMapViewWnd
{
public:
/*0x000*/ struct _CSIDLWNDVFTABLE* pvfTable; \
	CXW_NO_VTABLE
	SIDL

EQLIB_OBJECT CMapViewWnd::CMapViewWnd(class CXWnd*);
EQLIB_OBJECT bool CMapViewWnd::IsMappingEnabled();
EQLIB_OBJECT void CMapViewWnd::Activate();
EQLIB_OBJECT void CMapViewWnd::ActivateAutoMapping();
EQLIB_OBJECT void CMapViewWnd::DeactivateAutoMapping();
//EQLIB_OBJECT void CMapViewWnd::SetCurrentZone(EQZoneIndex, struct T3D_XYZ*, struct T3D_XYZ*);
// virtual
EQLIB_OBJECT CMapViewWnd::~CMapViewWnd();
EQLIB_OBJECT int CMapViewWnd::HandleLButtonDown(class CXPoint&, uint32_t);
EQLIB_OBJECT int CMapViewWnd::HandleLButtonHeld(class CXPoint, uint32_t);
EQLIB_OBJECT int CMapViewWnd::HandleLButtonUp(class CXPoint, uint32_t);
EQLIB_OBJECT int CMapViewWnd::HandleLButtonUpAfterHeld(class CXPoint, uint32_t);
EQLIB_OBJECT int CMapViewWnd::HandleWheelMove(class CXPoint, int, uint32_t);
EQLIB_OBJECT int CMapViewWnd::OnProcessFrame();
EQLIB_OBJECT int CMapViewWnd::PostDraw() const;
EQLIB_OBJECT int CMapViewWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CMapViewWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CMapViewWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CMapViewWnd::Deactivate();
EQLIB_OBJECT void CMapViewWnd::LoadIniInfo();
EQLIB_OBJECT void CMapViewWnd::StoreIniInfo();
EQLIB_OBJECT void CMapViewWnd::GetWorldCoordinates(float*);
// private
EQLIB_OBJECT void CMapViewWnd::Init();
};

class CMemoryStream
{
public:
EQLIB_OBJECT class CXStr CMemoryStream::GetString();
EQLIB_OBJECT static int __cdecl CMemoryStream::GetStringSize(class CXStr &);
EQLIB_OBJECT void CMemoryStream::GetString(class CXStr &);
EQLIB_OBJECT void CMemoryStream::PutString(class CXStr &);
};
typedef struct _POINTMERCHANTITEM
{ 
/*0x00*/ char ItemName[0x40]; 
/*0x40*/ int ItemID;
/*0x44*/ DWORD Price; 
/*0x48*/ int ThemeID;
/*0x4c*/ int IsStackable;
/*0x50*/ int IsLore;
/*0x54*/ int RaceMask;
/*0x58*/ int ClassMask;
/*0x5c*/ bool bCanUse;
/*0x60*/ 
} POINTMERCHANTITEM,*PPOINTMERCHANTITEM;
class PointMerchantWnd : public CSidlScreenWnd
{
public:
	int Unknown0x000;
	int Unknown0x004;
	int Unknown0x008;
	int NumItems;
	bool HdrItemName;
	bool HdrTheme;
	bool HdrPrice;
	CHAR OriginalPointsLabel[0x40];
	CLabel*MerchantNameLabel;
	CListWnd*ItemList;
	CListWnd*PointList;
	CButtonWnd*EquipButton;
	CButtonWnd*PurchaseButton;
	CButtonWnd*SellButton;
	CButtonWnd*DoneButton;
	CLabel*PointsAvailableValue;
	CLabel*PointsEverEarnedLabel;
	CLabel*PointsAvailableLabel;
	UINT NextRefreshTime;
	PSPAWNINFO ActiveMerchant;
	PPOINTMERCHANTITEM*Items;
	int MerchantThemeId;
	int CurrentSelection;
	int CurrentSort;
	bool bCurrentAscending;
	ItemGlobalIndex ItemLocation;
	PCONTENTS pSelectedItem;
	bool bInventoryWasActive;
	int CurrentItem;
	int CurrentQuantity;
	int SliderType;
	void*pHandler;//PointMerchantInterface*
};

class VeBaseReferenceCount
{
public:
	//just couting the vftable here, dont get confused
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
class PopDialogHandler2
{
public:
/*0x08*/ virtual void Unknownv0x08();
};
class WndEventHandler
{
public:
	UINT LastCheckTime;
	UINT Filler;
};
class CMerchantWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
#if !defined(ROF2EMU) && !defined(UFEMU)
	class MerchantPageHandler : public VeBaseReferenceCount
	{
	public:
	/*0x08*/ CMerchantWnd*pParent;
	/*0x0c*/ int MaxItems;
	/*0x10*/ int LastIndex;
	/*0x14*/ CListWnd	*ItemsList;
	/*0x18*/ CPageWnd	*PurchasePage;
	/*0x1c*/ bool bListNeedsRefresh;
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
	//dont pay any attention to the count on these, i needed to figure out the vftable
	//so thats why they are commented like this.
/*0x0c*/ virtual void Unknownv0x08();
/*0x0c*/ virtual void Unknownv0x0c();
/*0x10*/ virtual void Unknownv0x10();
/*0x14*/ virtual void Unknownv0x14();
/*0x18*/ virtual void DestroyItemByUniqueId(int64_t UniqueID);
/*0x1c*/ virtual void DestroyItemByItemGuid(const EqItemGuid& ItemGuid);
/*0x20*/ virtual bool AddItemToArray(const VePointer<CONTENTS>& pSentItem);
/*0x24*/ virtual int Sort(SListWndSortInfo*SortInfo);
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
//there are 22 of them...

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
	bool CMerchantWnd::PurchasePageHandler::RequestGetItem(int);
	void CMerchantWnd::PurchasePageHandler::RequestPutItem(int);
	};
//size 0x420 in Nov 02 2017 Beta 
/*0x230*/ UINT NextRefreshTime;
/*0x234*/ bool bInventoryWasActive;
/*0x240*/ VeArray<VePointer<MerchantPageHandler>> PageHandlers;
/*0x24c*/ float MerchantGreed;
/*0x250*/ ItemGlobalIndex ItemLocation;//size 0xc
/*0x25c*/ BYTE Unknown0x254[0x8];
/*0x264*/ VePointer<CONTENTS>pSelectedItem;
/*0x268*/ __time32_t MailExpireTime;
/*0x26c*/ bool bAutoRetrieveingMail;
/*0x270*/ BYTE Unknown0x268[0x10];
/*0x280*/ PCHAR Labels[0xc];
/*0x2b0*/ CEditWnd   *SearchEdit;//0x2b0 for sure
/*0x2b4*/ CButtonWnd *SearchButton;
/*0x2b8*/ CLabel*MerchantNameLabel;
/*0x2bc*/ CLabel*SelectedItemLabel;
/*0x2c0*/ CLabel*SelectedPriceLabel;
/*0x2c4*/ CButtonWnd *InspectButton;
/*0x2c8*/ CButtonWnd *PreviewButton;
/*0x2cc*/ CButtonWnd *SelectedItemButton;
/*0x2d0*/ CButtonWnd *BuyButton;
/*0x2d4*/ CButtonWnd *BuyMarketPlaceButton;
/*0x2d8*/ CButtonWnd *SellButton;
/*0x2dc*/ CButtonWnd	*RecoverButton;
/*0x2e0*/ CButtonWnd	*RetrieveButton;
/*0x2e4*/ CButtonWnd	*RetrieveAllButton;
/*0x2e8*/ CButtonWnd	*SendButton;
/*0x2ec*/ CButtonWnd	*AdventureButton;
/*0x2f0*/ CLabel		*SendToLabel;
/*0x2f4*/ CEditWnd	*SendToEdit;
/*0x2f8*/ CLabel     *NoteLabel;
/*0x2fc*/ CEditWnd   *NoteEdit;
/*0x300*/ CButtonWnd	*ClearNoteButton;
/*0x304*/ CListWnd	*ItemsList;//at 0x304 for sure! see 742D04 Nov 03 2017 Beta
/*0x308*/ CListWnd	*ItemsRecoveryList;
/*0x30c*/ CListWnd	*ItemsMailList;
/*0x310*/ CButtonWnd	*DoneButton;
/*0x314*/ CPageWnd	*PurchasePage;
/*0x318*/ CPageWnd	*RecoveryPage;
/*0x31c*/ CPageWnd	*MailPage;
/*0x320*/ CTabWnd		*TabWindow;
/*0x324*/ CButtonWnd	*UsableButton;
/*0x328*/ CLabel		*CurrentCurrencyLabel;
/*0x32c*/ int Unknown0x32c;
/*0x330*/ int Unknown0x330;
/*0x334*/ int Unknown0x334;
/*0x338*/ int Unknown0x338;
/*0x33C*/ int Unknown0x33C;
/*0x340*/ int Guk_Currency;
/*0x344*/ BYTE Unknown0x340[0x100];
/*0x444*/
#else
	template <typename TItem> class ItemContainer
	{
	public:
	/*0x00*/	UINT Size;//see 87DFAB in Nov 03 2017 Beta
	/*0x04*/	int Spec;
	/*0x08*/	VeArray<VePointer<TItem>> Items;//size 0xc
	/*0x14*/	BYTE AtDepth;
	/*0x16*/	short Slots[2];
	/*0x1a*/	bool bDynamic;
	/*0x1c*/
	};
	class ItemBaseContainer : public ItemContainer<CONTENTS>
	{
	public:
		//size is 0x1c
	};
	class MerchantPageHandler : public VeBaseReferenceCount
	{
	public:
	/*0x08*/ CMerchantWnd*pParent;
	/*0x0c*/ ItemBaseContainer ItemContainer;//size 0x1c
	/*0x28*/ int MaxItems;
	/*0x2c*/ int LastIndex;
	/*0x30*/ CListWnd* ItemsList;
	/*0x34*/ CPageWnd* Page;
	/*0x38*/ bool bListNeedsRefresh;
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
	bool CMerchantWnd::PurchasePageHandler::RequestGetItem(int);
	void CMerchantWnd::PurchasePageHandler::RequestPutItem(int);
	};
/*0x228*/ UINT NextRefreshTime;
/*0x22c*/ bool bInventoryWasActive;
/*0x238*/ VeArray<VePointer<MerchantPageHandler>> PageHandlers;
/*0x244*/ float MerchantGreed;
/*0x248*/ ItemGlobalIndex ItemLocation;
/*0x258*/ VePointer<CONTENTS>pSelectedItem;
/*0x25c*/ __time32_t MailExpireTime;
/*0x260*/ bool bAutoRetrieveingMail;
/*0x264*/ CLabel*plabelMerchantName;
	CLabel*plabelSelectedItem;
	CLabel*plabelSelectedPrice;
	CButtonWnd *InspectButton;
	CButtonWnd *PreviewButton;
    CButtonWnd *SelectedItemLabel;
    CButtonWnd *BuyButton;
    CButtonWnd *SellButton;
/*0x2dc*/ CButtonWnd	*RecoverButton;
/*0x2e0*/ CButtonWnd	*RetrieveButton;
/*0x2e4*/ CButtonWnd	*RetrieveAllButton;
/*0x2e8*/ CButtonWnd	*SendButton;
/*0x2f0*/ CLabel	*SendToLabel;
/*0x2f4*/ CEditWnd	*SendToEdit;
/*0x2f8*/ CLabel     *NoteLabel;
/*0x2fc*/ CEditWnd   *NoteEdit;
/*0x300*/ CButtonWnd	*ClearNoteButton;
/*0x304*/ CListWnd	*ItemsList;//at 0x304 for sure! see 742D04 Nov 03 2017 Beta
/*0x308*/ CListWnd	*ItemsRecoveryList;
/*0x30c*/ CListWnd	*ItemsMailList;
/*0x310*/ CButtonWnd	*DoneButton;
/*0x314*/ CPageWnd	*PurchasePage;
/*0x318*/ CPageWnd	*RecoveryPage;
/*0x31c*/ CPageWnd	*MailPage;
/*0x320*/ CTabWnd	*TabWindow;
/*0x324*/ CButtonWnd	*UsableButton;
#endif

EQLIB_OBJECT CMerchantWnd::CMerchantWnd(class CXWnd*);
EQLIB_OBJECT void CMerchantWnd::Activate(class EQPlayer*, float);
EQLIB_OBJECT void CMerchantWnd::AddContainerToMercArray(class EQ_Container*);
EQLIB_OBJECT void CMerchantWnd::AddEquipmentToMercArray(class EQ_Equipment*);
EQLIB_OBJECT void CMerchantWnd::AddNoteToMercArray(class EQ_Note*);
EQLIB_OBJECT void CMerchantWnd::ClearMerchantSlot(int);
EQLIB_OBJECT void CMerchantWnd::FinishBuyingItem(struct _sell_msg*);
EQLIB_OBJECT void CMerchantWnd::FinishSellingItem(struct _sell_msg*);
//older clients and im not really sure that it was correct then
//EQLIB_OBJECT void CMerchantWnd::SelectBuySellSlot(int, class CTextureAnimation*);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT int CMerchantWnd::SelectBuySellSlot(ItemGlobalIndex*, int ListIndex = -1);//for itemlists such as merchant items, we also need to send the actual listindex.
#else
EQLIB_OBJECT int CMerchantWnd::SelectBuySellSlot(ItemGlobalIndex*);
#endif
// virtual
EQLIB_OBJECT CMerchantWnd::~CMerchantWnd();
EQLIB_OBJECT int CMerchantWnd::OnProcessFrame();
EQLIB_OBJECT int CMerchantWnd::PostDraw() const;
EQLIB_OBJECT int CMerchantWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CMerchantWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CMerchantWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CMerchantWnd::Deactivate();
// private
EQLIB_OBJECT void CMerchantWnd::DisplayBuyOrSellPrice(bool, class EQ_Item*);
EQLIB_OBJECT void CMerchantWnd::HandleBuy(int);
EQLIB_OBJECT void CMerchantWnd::HandleSell(int);
EQLIB_OBJECT void CMerchantWnd::Init();
EQLIB_OBJECT void CMerchantWnd::UpdateBuySellButtons();
};

class CMusicPlayerWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CMusicPlayerWnd::CMusicPlayerWnd(class CXWnd*);
EQLIB_OBJECT void CMusicPlayerWnd::Activate();
EQLIB_OBJECT void CMusicPlayerWnd::AutoStart();
// virtual
EQLIB_OBJECT CMusicPlayerWnd::~CMusicPlayerWnd();
EQLIB_OBJECT int CMusicPlayerWnd::Draw() const;
EQLIB_OBJECT int CMusicPlayerWnd::OnProcessFrame();
EQLIB_OBJECT int CMusicPlayerWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CMusicPlayerWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CMusicPlayerWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CMusicPlayerWnd::Deactivate();
EQLIB_OBJECT void CMusicPlayerWnd::LoadIniInfo();
EQLIB_OBJECT void CMusicPlayerWnd::StoreIniInfo();
// protected
EQLIB_OBJECT void CMusicPlayerWnd::Update();
EQLIB_OBJECT void CMusicPlayerWnd::UpdateButtons();
// private
EQLIB_OBJECT void CMusicPlayerWnd::Init();
};

class CMutexLock
{
public:
EQLIB_OBJECT CMutexLock::~CMutexLock();
};

class CMutexLockCounted
{
public:
EQLIB_OBJECT CMutexLockCounted::~CMutexLockCounted();
};

class CMutexSync
{
public:
// private
EQLIB_OBJECT static int CMutexSync::isValid;
};

class CMutexSyncCounted
{
public:
EQLIB_OBJECT CMutexSyncCounted::~CMutexSyncCounted();
EQLIB_OBJECT CMutexSyncCounted::CMutexSyncCounted();
};

class CNoteWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CNoteWnd::CNoteWnd(class CXWnd*);
EQLIB_OBJECT bool CNoteWnd::CheckNote(class EQ_Note*);
EQLIB_OBJECT void CNoteWnd::Activate();
EQLIB_OBJECT void CNoteWnd::SetNote(char*);
// virtual
EQLIB_OBJECT CNoteWnd::~CNoteWnd();
EQLIB_OBJECT int CNoteWnd::HandleKeyboardMsg(uint32_t, uint32_t, bool);
EQLIB_OBJECT int CNoteWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CNoteWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CNoteWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CNoteWnd::Deactivate();
// private
EQLIB_OBJECT void CNoteWnd::Init();
};

class ConversationJournal
{
public:
EQLIB_OBJECT ConversationJournal::~ConversationJournal();
EQLIB_OBJECT ConversationJournal::ConversationJournal();
EQLIB_OBJECT class JournalNPC* ConversationJournal::FindNPCByNameZone(char*, int);
EQLIB_OBJECT class JournalNPC* ConversationJournal::GetNPC(int);
EQLIB_OBJECT int ConversationJournal::AddEntry(char*, int, long, float, float, float, char*, int);
EQLIB_OBJECT int ConversationJournal::DeleteNPC(char*, int);
EQLIB_OBJECT int ConversationJournal::Load(char*);
EQLIB_OBJECT int ConversationJournal::Save(char*);
EQLIB_OBJECT struct JournalCategory** ConversationJournal::GetCategoryList();
EQLIB_OBJECT struct JournalCategory* ConversationJournal::AddCategory(char*, char*, int);
EQLIB_OBJECT struct JournalCategory* ConversationJournal::AddCategory(int);
EQLIB_OBJECT struct JournalCategory* ConversationJournal::GetCategory(char*);
EQLIB_OBJECT struct JournalCategory* ConversationJournal::GetCategory(int);
EQLIB_OBJECT void ConversationJournal::Clean();
EQLIB_OBJECT void ConversationJournal::DeleteCategory(int);
// protected
EQLIB_OBJECT int ConversationJournal::FindFreeID();
// private
EQLIB_OBJECT class JournalNPC* ConversationJournal::AddNPC(char*, int);
EQLIB_OBJECT class JournalNPC* ConversationJournal::ReadNPC(struct _iobuf*);
EQLIB_OBJECT void ConversationJournal::AllocateCatArray();
EQLIB_OBJECT void ConversationJournal::AllocateNPCArray();
EQLIB_OBJECT void ConversationJournal::ReadCategory(struct _iobuf*);
};

class COptionsWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT COptionsWnd::COptionsWnd(class CXWnd*);
//EQLIB_OBJECT COptionsWnd::KeyboardAssignmentData::~KeyboardAssignmentData();
//EQLIB_OBJECT COptionsWnd::KeyboardAssignmentData::KeyboardAssignmentData();
EQLIB_OBJECT void COptionsWnd::Activate();
EQLIB_OBJECT void COptionsWnd::RefreshCurrentKeyboardAssignmentList();
EQLIB_OBJECT void COptionsWnd::ResetKeysToDefault();
EQLIB_OBJECT void COptionsWnd::RestoreDefaultColors();
// virtual
EQLIB_OBJECT COptionsWnd::~COptionsWnd();
EQLIB_OBJECT int COptionsWnd::HandleKeyboardMsg(uint32_t, uint32_t, bool);
EQLIB_OBJECT int COptionsWnd::OnProcessFrame();
EQLIB_OBJECT int COptionsWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* COptionsWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* COptionsWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void COptionsWnd::Deactivate();
// private
EQLIB_OBJECT int COptionsWnd::ChatPageOnProcessFrame();
EQLIB_OBJECT int COptionsWnd::ChatPageWndNotification(class CXWnd*, uint32_t, void*);
EQLIB_OBJECT int COptionsWnd::ColorPageOnProcessFrame();
EQLIB_OBJECT int COptionsWnd::ColorPageWndNotification(class CXWnd*, uint32_t, void*);
EQLIB_OBJECT int COptionsWnd::DisplayPageOnProcessFrame();
EQLIB_OBJECT int COptionsWnd::DisplayPageWndNotification(class CXWnd*, uint32_t, void*);
EQLIB_OBJECT int COptionsWnd::GeneralPageOnProcessFrame();
EQLIB_OBJECT int COptionsWnd::GeneralPageWndNotification(class CXWnd*, uint32_t, void*);
EQLIB_OBJECT int COptionsWnd::KeyboardPageDeactivate();
EQLIB_OBJECT int COptionsWnd::KeyboardPageHandleKeyboardMsg(uint32_t, uint32_t, bool);
EQLIB_OBJECT int COptionsWnd::KeyboardPageOnProcessFrame();
EQLIB_OBJECT int COptionsWnd::KeyboardPageWndNotification(class CXWnd*, uint32_t, void*);
EQLIB_OBJECT int COptionsWnd::MousePageOnProcessFrame();
EQLIB_OBJECT int COptionsWnd::MousePageWndNotification(class CXWnd*, uint32_t, void*);
EQLIB_OBJECT int COptionsWnd::RedirectDeactivateTo(class CPageWnd*);
EQLIB_OBJECT int COptionsWnd::RedirectHandleKeyboardMsgTo(class CPageWnd*, uint32_t, uint32_t, bool);
EQLIB_OBJECT int COptionsWnd::RedirectOnProcessFrameTo(class CPageWnd*);
EQLIB_OBJECT int COptionsWnd::RedirectWndNotificationTo(class CPageWnd*, class CXWnd*, uint32_t, void*);
EQLIB_OBJECT void COptionsWnd::AddKeyboardAssignment(int, int, int);
EQLIB_OBJECT void COptionsWnd::InitKeyboardAssignments();
EQLIB_OBJECT void COptionsWnd::InitKeyboardPage();
EQLIB_OBJECT void COptionsWnd::KeyboardPageCancelKeypressAssignment();
EQLIB_OBJECT void COptionsWnd::SetBagOptions(int, int);
EQLIB_OBJECT void COptionsWnd::SyncChatPage();
EQLIB_OBJECT void COptionsWnd::SyncColorPage();
EQLIB_OBJECT void COptionsWnd::SyncDisplayPage();
EQLIB_OBJECT void COptionsWnd::SyncGeneralPage();
EQLIB_OBJECT void COptionsWnd::SyncMousePage();
EQLIB_OBJECT void COptionsWnd::FillChatFilterList();
};

class CPageTemplate
{
public:
EQLIB_OBJECT CPageTemplate::CPageTemplate(class CParamPage*);
// virtual
EQLIB_OBJECT CPageTemplate::~CPageTemplate();
//EQLIB_OBJECT void* CPageTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CPageTemplate::`vector deleting destructor'(unsigned int);
};

class CPageWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CPageWnd::CPageWnd(class CXWnd*, uint32_t, class CXRect, class CXStr, class CPageTemplate*);
EQLIB_OBJECT CXStr CPageWnd::GetTabText(bool bSomething = false) const;
EQLIB_OBJECT void CPageWnd::SetTabText(CXStr &) const;
// virtual
EQLIB_OBJECT CPageWnd::~CPageWnd();
//EQLIB_OBJECT void* CPageWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CPageWnd::`vector deleting destructor'(unsigned int);
};

class CParam
{
public:
EQLIB_OBJECT class CParam & CParam::operator=(class CParam const &);
// virtual
EQLIB_OBJECT CParam::~CParam();
//EQLIB_OBJECT void* CParam::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParam::`vector deleting destructor'(unsigned int);
};

class CParamButton
{
public:
EQLIB_OBJECT CParamButton::CParamButton();
EQLIB_OBJECT class CParamButton & CParamButton::operator=(class CParamButton const &);
// virtual
EQLIB_OBJECT CParamButton::~CParamButton();
EQLIB_OBJECT bool CParamButton::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamButton::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamButton::GetStreamSize();
//EQLIB_OBJECT void* CParamButton::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamButton::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamButton::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamButton::WriteToStream(class CMemoryStream &);
};

class CParamButtonDrawTemplate
{
public:
EQLIB_OBJECT CParamButtonDrawTemplate::CParamButtonDrawTemplate();
EQLIB_OBJECT class CParamButtonDrawTemplate & CParamButtonDrawTemplate::operator=(class CParamButtonDrawTemplate const &);
// virtual
EQLIB_OBJECT CParamButtonDrawTemplate::~CParamButtonDrawTemplate();
EQLIB_OBJECT bool CParamButtonDrawTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamButtonDrawTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamButtonDrawTemplate::GetStreamSize();
//EQLIB_OBJECT void* CParamButtonDrawTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamButtonDrawTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamButtonDrawTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamButtonDrawTemplate::WriteToStream(class CMemoryStream &);
};

class CParamClass
{
public:
EQLIB_OBJECT CParamClass::CParamClass();
EQLIB_OBJECT class CParamClass & CParamClass::operator=(class CParamClass const &);
// virtual
EQLIB_OBJECT CParamClass::~CParamClass();
EQLIB_OBJECT bool CParamClass::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamClass::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamClass::GetStreamSize();
//EQLIB_OBJECT void* CParamClass::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamClass::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamClass::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamClass::WriteToStream(class CMemoryStream &);
};

class CParamCombobox
{
public:
EQLIB_OBJECT CParamCombobox::CParamCombobox();
EQLIB_OBJECT class CParamCombobox & CParamCombobox::operator=(class CParamCombobox const &);
// virtual
EQLIB_OBJECT CParamCombobox::~CParamCombobox();
EQLIB_OBJECT bool CParamCombobox::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamCombobox::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamCombobox::GetStreamSize();
//EQLIB_OBJECT void* CParamCombobox::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamCombobox::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamCombobox::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamCombobox::WriteToStream(class CMemoryStream &);
};

class CParamControl
{
public:
EQLIB_OBJECT CParamControl::CParamControl();
EQLIB_OBJECT class CParamControl & CParamControl::operator=(class CParamControl const &);
// virtual
EQLIB_OBJECT CParamControl::~CParamControl();
EQLIB_OBJECT bool CParamControl::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamControl::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamControl::GetStreamSize();
//EQLIB_OBJECT void* CParamControl::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamControl::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamControl::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamControl::WriteToStream(class CMemoryStream &);
};

class CParamEditbox
{
public:
EQLIB_OBJECT CParamEditbox::CParamEditbox();
EQLIB_OBJECT class CParamEditbox & CParamEditbox::operator=(class CParamEditbox const &);
// virtual
EQLIB_OBJECT CParamEditbox::~CParamEditbox();
EQLIB_OBJECT bool CParamEditbox::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamEditbox::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamEditbox::GetStreamSize();
//EQLIB_OBJECT void* CParamEditbox::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamEditbox::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamEditbox::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamEditbox::WriteToStream(class CMemoryStream &);
};

class CParamFrame
{
public:
EQLIB_OBJECT CParamFrame::CParamFrame();
// virtual
EQLIB_OBJECT CParamFrame::~CParamFrame();
EQLIB_OBJECT bool CParamFrame::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamFrame::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamFrame::GetStreamSize();
//EQLIB_OBJECT void* CParamFrame::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamFrame::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamFrame::WriteToStream(class CMemoryStream &);
};

class CParamFrameTemplate
{
public:
EQLIB_OBJECT CParamFrameTemplate::CParamFrameTemplate();
EQLIB_OBJECT class CParamFrameTemplate & CParamFrameTemplate::operator=(class CParamFrameTemplate const &);
// virtual
EQLIB_OBJECT CParamFrameTemplate::~CParamFrameTemplate();
EQLIB_OBJECT bool CParamFrameTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamFrameTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamFrameTemplate::GetStreamSize();
//EQLIB_OBJECT void* CParamFrameTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamFrameTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamFrameTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamFrameTemplate::WriteToStream(class CMemoryStream &);
};

class CParamGauge
{
public:
EQLIB_OBJECT CParamGauge::CParamGauge();
EQLIB_OBJECT class CParamGauge & CParamGauge::operator=(class CParamGauge const &);
// virtual
EQLIB_OBJECT CParamGauge::~CParamGauge();
EQLIB_OBJECT bool CParamGauge::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamGauge::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamGauge::GetStreamSize();
//EQLIB_OBJECT void* CParamGauge::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamGauge::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamGauge::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamGauge::WriteToStream(class CMemoryStream &);
};

class CParamGaugeDrawTemplate
{
public:
EQLIB_OBJECT CParamGaugeDrawTemplate::CParamGaugeDrawTemplate();
EQLIB_OBJECT class CParamGaugeDrawTemplate & CParamGaugeDrawTemplate::operator=(class CParamGaugeDrawTemplate const &);
// virtual
EQLIB_OBJECT CParamGaugeDrawTemplate::~CParamGaugeDrawTemplate();
EQLIB_OBJECT bool CParamGaugeDrawTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamGaugeDrawTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamGaugeDrawTemplate::GetStreamSize();
//EQLIB_OBJECT void* CParamGaugeDrawTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamGaugeDrawTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamGaugeDrawTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamGaugeDrawTemplate::WriteToStream(class CMemoryStream &);
};

class CParamInvSlot
{
public:
EQLIB_OBJECT CParamInvSlot::CParamInvSlot();
EQLIB_OBJECT class CParamInvSlot & CParamInvSlot::operator=(class CParamInvSlot const &);
// virtual
EQLIB_OBJECT CParamInvSlot::~CParamInvSlot();
EQLIB_OBJECT bool CParamInvSlot::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamInvSlot::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamInvSlot::GetStreamSize();
//EQLIB_OBJECT void* CParamInvSlot::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamInvSlot::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamInvSlot::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamInvSlot::WriteToStream(class CMemoryStream &);
};

class CParamLabel
{
public:
EQLIB_OBJECT CParamLabel::CParamLabel();
EQLIB_OBJECT class CParamLabel & CParamLabel::operator=(class CParamLabel const &);
// virtual
EQLIB_OBJECT CParamLabel::~CParamLabel();
EQLIB_OBJECT bool CParamLabel::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamLabel::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamLabel::GetStreamSize();
//EQLIB_OBJECT void* CParamLabel::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamLabel::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamLabel::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamLabel::WriteToStream(class CMemoryStream &);
};

class CParamListbox
{
public:
EQLIB_OBJECT CParamListbox::CParamListbox();
EQLIB_OBJECT class CParamListbox & CParamListbox::operator=(class CParamListbox const &);
// virtual
EQLIB_OBJECT CParamListbox::~CParamListbox();
EQLIB_OBJECT bool CParamListbox::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamListbox::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamListbox::GetStreamSize();
//EQLIB_OBJECT void* CParamListbox::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamListbox::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamListbox::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamListbox::WriteToStream(class CMemoryStream &);
};

class CParamListboxColumn
{
public:
EQLIB_OBJECT CParamListboxColumn::CParamListboxColumn();
EQLIB_OBJECT class CParamListboxColumn & CParamListboxColumn::operator=(class CParamListboxColumn const &);
// virtual
EQLIB_OBJECT CParamListboxColumn::~CParamListboxColumn();
EQLIB_OBJECT bool CParamListboxColumn::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamListboxColumn::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamListboxColumn::GetStreamSize();
//EQLIB_OBJECT void* CParamListboxColumn::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamListboxColumn::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamListboxColumn::WriteToStream(class CMemoryStream &);
};

class CParamPage
{
public:
EQLIB_OBJECT CParamPage::CParamPage();
EQLIB_OBJECT class CParamPage & CParamPage::operator=(class CParamPage const &);
// virtual
EQLIB_OBJECT CParamPage::~CParamPage();
EQLIB_OBJECT bool CParamPage::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamPage::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamPage::GetStreamSize();
//EQLIB_OBJECT void* CParamPage::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamPage::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamPage::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamPage::WriteToStream(class CMemoryStream &);
};

class CParamPoint
{
public:
EQLIB_OBJECT CParamPoint::CParamPoint();
EQLIB_OBJECT class CParamPoint & CParamPoint::operator=(class CParamPoint const &);
// virtual
EQLIB_OBJECT CParamPoint::~CParamPoint();
EQLIB_OBJECT bool CParamPoint::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamPoint::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamPoint::GetStreamSize();
//EQLIB_OBJECT void* CParamPoint::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamPoint::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamPoint::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamPoint::WriteToStream(class CMemoryStream &);
};

class CParamRGB
{
public:
EQLIB_OBJECT CParamRGB::CParamRGB();
EQLIB_OBJECT class CParamRGB & CParamRGB::operator=(class CParamRGB const &);
// virtual
EQLIB_OBJECT CParamRGB::~CParamRGB();
EQLIB_OBJECT bool CParamRGB::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamRGB::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamRGB::GetStreamSize();
//EQLIB_OBJECT void* CParamRGB::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamRGB::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamRGB::WriteToStream(class CMemoryStream &);
};

class CParamScreen
{
public:
EQLIB_OBJECT CParamScreen::CParamScreen();
EQLIB_OBJECT class CParamScreen & CParamScreen::operator=(class CParamScreen const &);
// virtual
EQLIB_OBJECT CParamScreen::~CParamScreen();
EQLIB_OBJECT bool CParamScreen::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamScreen::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamScreen::GetStreamSize();
//EQLIB_OBJECT void* CParamScreen::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamScreen::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamScreen::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamScreen::WriteToStream(class CMemoryStream &);
};

class CParamScreenPiece
{
public:
EQLIB_OBJECT CParamScreenPiece::CParamScreenPiece();
EQLIB_OBJECT class CParamScreenPiece & CParamScreenPiece::operator=(class CParamScreenPiece const &);
// virtual
EQLIB_OBJECT CParamScreenPiece::~CParamScreenPiece();
EQLIB_OBJECT bool CParamScreenPiece::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamScreenPiece::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamScreenPiece::GetStreamSize();
//EQLIB_OBJECT void* CParamScreenPiece::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamScreenPiece::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamScreenPiece::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamScreenPiece::WriteToStream(class CMemoryStream &);
};

class CParamScrollbarDrawTemplate
{
public:
EQLIB_OBJECT CParamScrollbarDrawTemplate::CParamScrollbarDrawTemplate();
EQLIB_OBJECT class CParamScrollbarDrawTemplate & CParamScrollbarDrawTemplate::operator=(class CParamScrollbarDrawTemplate const &);
// virtual
EQLIB_OBJECT CParamScrollbarDrawTemplate::~CParamScrollbarDrawTemplate();
EQLIB_OBJECT bool CParamScrollbarDrawTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamScrollbarDrawTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamScrollbarDrawTemplate::GetStreamSize();
//EQLIB_OBJECT void* CParamScrollbarDrawTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamScrollbarDrawTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamScrollbarDrawTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamScrollbarDrawTemplate::WriteToStream(class CMemoryStream &);
};

class CParamSize
{
public:
EQLIB_OBJECT CParamSize::CParamSize();
EQLIB_OBJECT class CParamSize & CParamSize::operator=(class CParamSize const &);
// virtual
EQLIB_OBJECT CParamSize::~CParamSize();
EQLIB_OBJECT bool CParamSize::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSize::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSize::GetStreamSize();
//EQLIB_OBJECT void* CParamSize::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamSize::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSize::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSize::WriteToStream(class CMemoryStream &);
};

class CParamSlider
{
public:
EQLIB_OBJECT CParamSlider::CParamSlider();
EQLIB_OBJECT class CParamSlider & CParamSlider::operator=(class CParamSlider const &);
// virtual
EQLIB_OBJECT CParamSlider::~CParamSlider();
EQLIB_OBJECT bool CParamSlider::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSlider::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSlider::GetStreamSize();
//EQLIB_OBJECT void* CParamSlider::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamSlider::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSlider::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSlider::WriteToStream(class CMemoryStream &);
};

class CParamSliderDrawTemplate
{
public:
EQLIB_OBJECT CParamSliderDrawTemplate::CParamSliderDrawTemplate();
EQLIB_OBJECT class CParamSliderDrawTemplate & CParamSliderDrawTemplate::operator=(class CParamSliderDrawTemplate const &);
// virtual
EQLIB_OBJECT CParamSliderDrawTemplate::~CParamSliderDrawTemplate();
EQLIB_OBJECT bool CParamSliderDrawTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSliderDrawTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSliderDrawTemplate::GetStreamSize();
//EQLIB_OBJECT void* CParamSliderDrawTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamSliderDrawTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSliderDrawTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSliderDrawTemplate::WriteToStream(class CMemoryStream &);
};

class CParamSpellGem
{
public:
EQLIB_OBJECT CParamSpellGem::CParamSpellGem();
EQLIB_OBJECT class CParamSpellGem & CParamSpellGem::operator=(class CParamSpellGem const &);
// virtual
EQLIB_OBJECT CParamSpellGem::~CParamSpellGem();
EQLIB_OBJECT bool CParamSpellGem::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSpellGem::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSpellGem::GetStreamSize();
//EQLIB_OBJECT void* CParamSpellGem::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamSpellGem::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSpellGem::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSpellGem::WriteToStream(class CMemoryStream &);
};

class CParamSpellGemDrawTemplate
{
public:
EQLIB_OBJECT CParamSpellGemDrawTemplate::CParamSpellGemDrawTemplate();
EQLIB_OBJECT class CParamSpellGemDrawTemplate & CParamSpellGemDrawTemplate::operator=(class CParamSpellGemDrawTemplate const &);
// virtual
EQLIB_OBJECT CParamSpellGemDrawTemplate::~CParamSpellGemDrawTemplate();
EQLIB_OBJECT bool CParamSpellGemDrawTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSpellGemDrawTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSpellGemDrawTemplate::GetStreamSize();
//EQLIB_OBJECT void* CParamSpellGemDrawTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamSpellGemDrawTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSpellGemDrawTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSpellGemDrawTemplate::WriteToStream(class CMemoryStream &);
};

class CParamStaticAnimation
{
public:
EQLIB_OBJECT CParamStaticAnimation::CParamStaticAnimation();
EQLIB_OBJECT class CParamStaticAnimation & CParamStaticAnimation::operator=(class CParamStaticAnimation const &);
// virtual
EQLIB_OBJECT CParamStaticAnimation::~CParamStaticAnimation();
EQLIB_OBJECT bool CParamStaticAnimation::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamStaticAnimation::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamStaticAnimation::GetStreamSize();
//EQLIB_OBJECT void* CParamStaticAnimation::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamStaticAnimation::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamStaticAnimation::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamStaticAnimation::WriteToStream(class CMemoryStream &);
};

class CParamStaticFrame
{
public:
EQLIB_OBJECT CParamStaticFrame::CParamStaticFrame();
EQLIB_OBJECT class CParamStaticFrame & CParamStaticFrame::operator=(class CParamStaticFrame const &);
// virtual
EQLIB_OBJECT CParamStaticFrame::~CParamStaticFrame();
EQLIB_OBJECT bool CParamStaticFrame::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamStaticFrame::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamStaticFrame::GetStreamSize();
//EQLIB_OBJECT void* CParamStaticFrame::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamStaticFrame::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamStaticFrame::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamStaticFrame::WriteToStream(class CMemoryStream &);
};

class CParamStaticHeader
{
public:
EQLIB_OBJECT CParamStaticHeader::CParamStaticHeader();
EQLIB_OBJECT class CParamStaticHeader & CParamStaticHeader::operator=(class CParamStaticHeader const &);
// virtual
EQLIB_OBJECT CParamStaticHeader::~CParamStaticHeader();
EQLIB_OBJECT bool CParamStaticHeader::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamStaticHeader::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamStaticHeader::GetStreamSize();
//EQLIB_OBJECT void* CParamStaticHeader::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamStaticHeader::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamStaticHeader::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamStaticHeader::WriteToStream(class CMemoryStream &);
};

class CParamStaticScreenPiece
{
public:
EQLIB_OBJECT CParamStaticScreenPiece::CParamStaticScreenPiece();
// virtual
EQLIB_OBJECT CParamStaticScreenPiece::~CParamStaticScreenPiece();
EQLIB_OBJECT bool CParamStaticScreenPiece::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamStaticScreenPiece::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamStaticScreenPiece::GetStreamSize();
//EQLIB_OBJECT void* CParamStaticScreenPiece::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamStaticScreenPiece::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamStaticScreenPiece::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamStaticScreenPiece::WriteToStream(class CMemoryStream &);
};

class CParamStaticText
{
public:
EQLIB_OBJECT CParamStaticText::CParamStaticText();
EQLIB_OBJECT class CParamStaticText & CParamStaticText::operator=(class CParamStaticText const &);
// virtual
EQLIB_OBJECT CParamStaticText::~CParamStaticText();
EQLIB_OBJECT bool CParamStaticText::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamStaticText::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamStaticText::GetStreamSize();
//EQLIB_OBJECT void* CParamStaticText::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamStaticText::`vector deleting destructor'(unsigned int);
#define SafeYLoc 0
EQLIB_OBJECT void CParamStaticText::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamStaticText::WriteToStream(class CMemoryStream &);
};

class CParamSTMLbox
{
public:
EQLIB_OBJECT CParamSTMLbox::CParamSTMLbox();
// virtual
EQLIB_OBJECT CParamSTMLbox::~CParamSTMLbox();
EQLIB_OBJECT bool CParamSTMLbox::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSTMLbox::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSTMLbox::GetStreamSize();
//EQLIB_OBJECT void* CParamSTMLbox::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamSTMLbox::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSTMLbox::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSTMLbox::WriteToStream(class CMemoryStream &);
};

class CParamSuiteDefaults
{
public:
EQLIB_OBJECT CParamSuiteDefaults::CParamSuiteDefaults();
EQLIB_OBJECT class CParamSuiteDefaults & CParamSuiteDefaults::operator=(class CParamSuiteDefaults const &);
// virtual
EQLIB_OBJECT CParamSuiteDefaults::~CParamSuiteDefaults();
EQLIB_OBJECT bool CParamSuiteDefaults::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSuiteDefaults::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSuiteDefaults::GetStreamSize();
//EQLIB_OBJECT void* CParamSuiteDefaults::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamSuiteDefaults::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSuiteDefaults::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSuiteDefaults::WriteToStream(class CMemoryStream &);
};

class CParamTabBox
{
public:
EQLIB_OBJECT CParamTabBox::CParamTabBox();
EQLIB_OBJECT class CParamTabBox & CParamTabBox::operator=(class CParamTabBox const &);
// virtual
EQLIB_OBJECT CParamTabBox::~CParamTabBox();
EQLIB_OBJECT bool CParamTabBox::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamTabBox::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamTabBox::GetStreamSize();
//EQLIB_OBJECT void* CParamTabBox::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamTabBox::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamTabBox::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamTabBox::WriteToStream(class CMemoryStream &);
};

class CParamTextureInfo
{
public:
EQLIB_OBJECT CParamTextureInfo::CParamTextureInfo();
// virtual
EQLIB_OBJECT CParamTextureInfo::~CParamTextureInfo();
EQLIB_OBJECT bool CParamTextureInfo::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamTextureInfo::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamTextureInfo::GetStreamSize();
//EQLIB_OBJECT void* CParamTextureInfo::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamTextureInfo::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamTextureInfo::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamTextureInfo::WriteToStream(class CMemoryStream &);
};

class CParamUi2DAnimation
{
public:
EQLIB_OBJECT CParamUi2DAnimation::CParamUi2DAnimation();
// virtual
EQLIB_OBJECT CParamUi2DAnimation::~CParamUi2DAnimation();
EQLIB_OBJECT bool CParamUi2DAnimation::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamUi2DAnimation::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamUi2DAnimation::GetStreamSize();
//EQLIB_OBJECT void* CParamUi2DAnimation::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamUi2DAnimation::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamUi2DAnimation::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamUi2DAnimation::WriteToStream(class CMemoryStream &);
};

class CParamWindowDrawTemplate
{
public:
EQLIB_OBJECT CParamWindowDrawTemplate::CParamWindowDrawTemplate();
// virtual
EQLIB_OBJECT CParamWindowDrawTemplate::~CParamWindowDrawTemplate();
EQLIB_OBJECT bool CParamWindowDrawTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamWindowDrawTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamWindowDrawTemplate::GetStreamSize();
//EQLIB_OBJECT void* CParamWindowDrawTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CParamWindowDrawTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamWindowDrawTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamWindowDrawTemplate::WriteToStream(class CMemoryStream &);
};

class CParseTokensXML
{
public:
EQLIB_OBJECT CParseTokensXML::~CParseTokensXML();
//EQLIB_OBJECT bool CParseTokensXML::Accept(enum ETokTypeXML);
EQLIB_OBJECT bool CParseTokensXML::StartFileBased(class CXStr);
EQLIB_OBJECT class CXStr CParseTokensXML::GetCurFile();
EQLIB_OBJECT void __cdecl CParseTokensXML::SetError(char const*, ...);
};

class CParseTokXML
{
public:
EQLIB_OBJECT CParseTokXML::~CParseTokXML();
//EQLIB_OBJECT enum ETokTypeXML CParseTokXML::NextToken();
//EQLIB_OBJECT void* CParseTokXML::`scalar deleting destructor'(unsigned int);
// private
EQLIB_OBJECT bool CParseTokXML::GetEntityRef(char &);
};

class CPetInfoWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CPetInfoWnd::CPetInfoWnd(class CXWnd*);
EQLIB_OBJECT class CButtonWnd* CPetInfoWnd::GetButton(int);
EQLIB_OBJECT void CPetInfoWnd::Activate();
EQLIB_OBJECT void CPetInfoWnd::SetShowOnSummon(bool);
EQLIB_OBJECT void CPetInfoWnd::Update();
// virtual
EQLIB_OBJECT CPetInfoWnd::~CPetInfoWnd();
EQLIB_OBJECT int CPetInfoWnd::OnProcessFrame();
EQLIB_OBJECT int CPetInfoWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CPetInfoWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CPetInfoWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CPetInfoWnd::Deactivate();
// private
EQLIB_OBJECT void CPetInfoWnd::Init();
};

class CPetitionQWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CPetitionQWnd::CPetitionQWnd(class CXWnd*);
EQLIB_OBJECT char* CPetitionQWnd::GetCurrentPetitionersName();
EQLIB_OBJECT void CPetitionQWnd::Activate();
EQLIB_OBJECT void CPetitionQWnd::AddGMText();
EQLIB_OBJECT void CPetitionQWnd::CheckedOut(struct petitionQtype const*, int);
EQLIB_OBJECT void CPetitionQWnd::ClearCurrentPet();
EQLIB_OBJECT void CPetitionQWnd::FillFields();
EQLIB_OBJECT void CPetitionQWnd::LogPetitionText();
EQLIB_OBJECT void CPetitionQWnd::SetButtonsForPetition(bool, bool);
EQLIB_OBJECT void CPetitionQWnd::SetPriorityDisplay();
EQLIB_OBJECT void CPetitionQWnd::UndoCheckout();
EQLIB_OBJECT void CPetitionQWnd::UpdatePetitions();
// virtual
EQLIB_OBJECT CPetitionQWnd::~CPetitionQWnd();
EQLIB_OBJECT int CPetitionQWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CPetitionQWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CPetitionQWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CPetitionQWnd::Deactivate();
};

class CPlayerNotesWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CPlayerNotesWnd::CPlayerNotesWnd(class CXWnd*);
EQLIB_OBJECT void CPlayerNotesWnd::Activate();
EQLIB_OBJECT void CPlayerNotesWnd::AppendText(char*);
EQLIB_OBJECT void CPlayerNotesWnd::SaveNotes();
// virtual
EQLIB_OBJECT CPlayerNotesWnd::~CPlayerNotesWnd();
EQLIB_OBJECT int CPlayerNotesWnd::Draw() const;
EQLIB_OBJECT int CPlayerNotesWnd::OnProcessFrame();
EQLIB_OBJECT int CPlayerNotesWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CPlayerNotesWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CPlayerNotesWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CPlayerNotesWnd::Deactivate();
// private
EQLIB_OBJECT void CPlayerNotesWnd::Init();
};

class CPlayerWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CPlayerWnd::CPlayerWnd(class CXWnd*);
EQLIB_OBJECT void CPlayerWnd::Activate();
EQLIB_OBJECT void CPlayerWnd::CreateLocalMenu();
EQLIB_OBJECT void CPlayerWnd::UpdateContextMenu();
// virtual
EQLIB_OBJECT CPlayerWnd::~CPlayerWnd();
EQLIB_OBJECT int CPlayerWnd::Draw() const;
EQLIB_OBJECT int CPlayerWnd::OnProcessFrame();
EQLIB_OBJECT int CPlayerWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CPlayerWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CPlayerWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CPlayerWnd::Deactivate();
EQLIB_OBJECT void CPlayerWnd::LoadIniInfo();
EQLIB_OBJECT void CPlayerWnd::StoreIniInfo();
// private
EQLIB_OBJECT void CPlayerWnd::Init();
};

class CPotionBeltWnd : public CSidlScreenWnd
{
public:
// virtual
EQLIB_OBJECT int CPotionBeltWnd::DrawTooltip(class CXWnd const*) const;
};
class CBandolierWnd : public CSidlScreenWnd, public WndEventHandler2
{
public:
	CButtonWnd*	pAddButton;
	CButtonWnd*	pDeleteButton;
	CButtonWnd*	pUseButton;
	CButtonWnd*	pMkHotButton;
	CButtonWnd* pAutoSwapButton;
	CButtonWnd* pDisplayButtons[4];
	CListWnd*	pWeaponSetList;
};
class CQuantityWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CQuantityWnd::CQuantityWnd(class CXWnd*);
EQLIB_OBJECT void CQuantityWnd::Activate(class CXWnd*, int, int, int, int, bool);
// virtual
EQLIB_OBJECT CQuantityWnd::~CQuantityWnd();
EQLIB_OBJECT void CQuantityWnd::Open(class CXWnd*, int, int, int, int, int, int, bool);
EQLIB_OBJECT int CQuantityWnd::Draw() const;
EQLIB_OBJECT int CQuantityWnd::OnProcessFrame();
EQLIB_OBJECT int CQuantityWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CQuantityWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CQuantityWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CQuantityWnd::Deactivate();
// private
//EQLIB_OBJECT void CQuantityWnd::Accept;
EQLIB_OBJECT void CQuantityWnd::CheckMaxEditWnd();
EQLIB_OBJECT void CQuantityWnd::UpdateEditWndFromSlider();
EQLIB_OBJECT void CQuantityWnd::UpdateSliderFromEditWnd();
};

class CRadioGroup
{
public:
EQLIB_OBJECT CRadioGroup::CRadioGroup(class CXStr);
EQLIB_OBJECT class CXStr CRadioGroup::GetName() const;
// virtual
EQLIB_OBJECT CRadioGroup::~CRadioGroup();
//EQLIB_OBJECT void* CRadioGroup::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CRadioGroup::`vector deleting destructor'(unsigned int);
};

class CRaid
{
public:
EQLIB_OBJECT CRaid::~CRaid();
EQLIB_OBJECT CRaid::CRaid();
EQLIB_OBJECT bool CRaid::IsInRaid();
EQLIB_OBJECT bool CRaid::IsInvited();
EQLIB_OBJECT bool CRaid::IsRaidGroupLeader();
EQLIB_OBJECT bool CRaid::IsRaidLeader();
EQLIB_OBJECT bool CRaid::IsRaidMember(char*);
EQLIB_OBJECT int CRaid::GetLootType();
EQLIB_OBJECT int CRaid::GetNumRaidMembers();
EQLIB_OBJECT struct RaidMember* CRaid::GetRaidMemberAt(int);
EQLIB_OBJECT void CRaid::AddRaidLooter();
EQLIB_OBJECT void CRaid::ClearInvitedState();
EQLIB_OBJECT void CRaid::CreateInviteRaid();
EQLIB_OBJECT void CRaid::HandleC2SRaidMessage(char*);
EQLIB_OBJECT void CRaid::HandleCreateInviteRaid(struct CSRaidMessage*);
EQLIB_OBJECT void CRaid::HandleS2CRaidMessage(char*);
EQLIB_OBJECT void CRaid::RemoveRaidLooter();
EQLIB_OBJECT void CRaid::RemoveRaidMember();
EQLIB_OBJECT void CRaid::ResetRaid();
EQLIB_OBJECT void CRaid::ResetWindow();
EQLIB_OBJECT void CRaid::SendInviteResponse(bool);
EQLIB_OBJECT void CRaid::SendLeadershipChange(char*);
EQLIB_OBJECT void CRaid::SendRaidChat(char*);
EQLIB_OBJECT void CRaid::SetLootType(char*);
EQLIB_OBJECT void CRaid::SetRaidLeader(char*);
EQLIB_OBJECT void CRaid::SetTargetRaidPlayer(char*);
EQLIB_OBJECT void CRaid::UpdateClassColor(int, unsigned long);
EQLIB_OBJECT void CRaid::UpdateOptionsWindow();
// private
EQLIB_OBJECT bool CRaid::IsRaidLooter(char*);
EQLIB_OBJECT int CRaid::FindOpenIndex();
EQLIB_OBJECT int CRaid::FindPlayerIndex(char*);
EQLIB_OBJECT int CRaid::FindRaidGroupLeader(int);
EQLIB_OBJECT void CRaid::AddRaidMember(struct RaidAddMember*);
EQLIB_OBJECT void CRaid::ChangeLeadership(char*);
EQLIB_OBJECT void CRaid::DeleteRaidMember(struct SCRaidMessage*);
EQLIB_OBJECT void CRaid::DetermineRaidChanges(char*);
EQLIB_OBJECT void CRaid::HandleAddLooter(char*);
EQLIB_OBJECT void CRaid::HandlePositionChange(struct SCRaidMessage*);
EQLIB_OBJECT void CRaid::HandleRemoveLooter(char*);
EQLIB_OBJECT void CRaid::HandleSetLootType(int);
EQLIB_OBJECT void CRaid::InitializeRaid(char*);
EQLIB_OBJECT void CRaid::RaidCreated(struct CreateRaidMessage*);
EQLIB_OBJECT void CRaid::RaidGroupLeaderChange(struct SCRaidMessage*);
EQLIB_OBJECT void CRaid::RenameMember(struct RenameRaidMember*);
EQLIB_OBJECT void CRaid::SendRaidMsg(int, char*, char*, int);
EQLIB_OBJECT void CRaid::SetLootTypeResponse(struct SCRaidMessage*);
EQLIB_OBJECT void CRaid::UpdateLevelAverage();
};

class CRaidOptionsWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CRaidOptionsWnd::CRaidOptionsWnd(class CXWnd*);
EQLIB_OBJECT void CRaidOptionsWnd::Activate();
EQLIB_OBJECT void CRaidOptionsWnd::AddLooterToList(char*);
EQLIB_OBJECT void CRaidOptionsWnd::ClearLooterList();
EQLIB_OBJECT void CRaidOptionsWnd::UpdateComponents();
// virtual
EQLIB_OBJECT CRaidOptionsWnd::~CRaidOptionsWnd();
EQLIB_OBJECT int CRaidOptionsWnd::OnProcessFrame();
EQLIB_OBJECT int CRaidOptionsWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CRaidOptionsWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CRaidOptionsWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CRaidOptionsWnd::Deactivate();
// private
EQLIB_OBJECT void CRaidOptionsWnd::Init();
EQLIB_OBJECT void CRaidOptionsWnd::InitializeClassColors();
};

class CRaidWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CRaidWnd::CRaidWnd(class CXWnd*);
EQLIB_OBJECT void CRaidWnd::Activate();
EQLIB_OBJECT void CRaidWnd::AddPlayertoList(char*, char*, char*, char*, int, int, bool);
EQLIB_OBJECT void CRaidWnd::ChangePosition(char*, int, int, int, bool);
EQLIB_OBJECT void CRaidWnd::ChangeRaidGroupLeader(char*, int, char*);
EQLIB_OBJECT void CRaidWnd::ClearPlayerList();
EQLIB_OBJECT void CRaidWnd::RemovePlayerFromList(char*, int);
EQLIB_OBJECT void CRaidWnd::SetClassColor(int, unsigned long);
EQLIB_OBJECT void CRaidWnd::SetPlayerClassColor(char*, int, int);
EQLIB_OBJECT void CRaidWnd::SetPlayerClassColor(int, int, int);
EQLIB_OBJECT void CRaidWnd::SetRaidCount(int);
EQLIB_OBJECT void CRaidWnd::SetRaidMemberRank(char*, char*, int);
EQLIB_OBJECT void CRaidWnd::SetRaidTarget(char*, int, char*, int);
EQLIB_OBJECT void CRaidWnd::UpdateButtons();
EQLIB_OBJECT void CRaidWnd::UpdateLevelAverage(int);
EQLIB_OBJECT void CRaidWnd::UpdateMemberName(char*, char*, int);
// virtual
EQLIB_OBJECT CRaidWnd::~CRaidWnd();
EQLIB_OBJECT int CRaidWnd::OnProcessFrame();
EQLIB_OBJECT int CRaidWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CRaidWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CRaidWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CRaidWnd::Deactivate();
// private
EQLIB_OBJECT int CRaidWnd::FindIndexNotInGroupList(char*);
EQLIB_OBJECT int CRaidWnd::FindOpenIndexInGroup(int);
EQLIB_OBJECT int CRaidWnd::FindPlayerIndexInGroup(char*, int);
EQLIB_OBJECT void CRaidWnd::AddSeparator();
EQLIB_OBJECT void CRaidWnd::Init();
EQLIB_OBJECT void CRaidWnd::InitializeClassColors();
EQLIB_OBJECT void CRaidWnd::ResortRaidGroupList(int, int);
};

class CRC32Generator
{
public:
EQLIB_OBJECT unsigned int CRC32Generator::generateCRC32(unsigned char const*, unsigned int) const;
EQLIB_OBJECT unsigned int CRC32Generator::updateCRC32(unsigned int, unsigned char const*, unsigned int) const;
// private
EQLIB_OBJECT static unsigned int* CRC32Generator::_crcTable;
};
typedef struct _ResolutionUpdateData 
{
	int Width;
	int Height;
	int BitsPerPixel;
	int RefreshRate;
	bool bFullscreen;
	void Set(int width, int height, int bitsPerPixel, int refreshRate, bool bfullscreen = false)
	{
		Width = width;
		Height = height;
		BitsPerPixel = bitsPerPixel;
		RefreshRate = refreshRate;
		bFullscreen = bfullscreen;
	}
}ResolutionUpdateData,*PResolutionUpdateData;
typedef struct _SDeviceInfo
{
	CHAR Name[0x80];
}SDeviceInfo,*PSDeviceInfo;

class CResolutionHandlerBase
{
public:
EQLIB_OBJECT static bool __cdecl CResolutionHandlerBase::IsFullscreenAvailable();
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::GetDesktopBitsPerPixel();
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::GetDesktopHeight();
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::GetDesktopRefreshRate();
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::GetDesktopWidth();
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::GetHeight();
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::GetWidth();
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::Init();
EQLIB_OBJECT static void __cdecl CResolutionHandlerBase::ChangeToResolution(int, int, int, int, int);
EQLIB_OBJECT static void __cdecl CResolutionHandlerBase::SaveSettings();
EQLIB_OBJECT static void __cdecl CResolutionHandlerBase::Shutdown();
EQLIB_OBJECT static void __cdecl CResolutionHandlerBase::ToggleScreenMode();
EQLIB_OBJECT static void __cdecl CResolutionHandlerBase::UpdateWindowPosition();


	DWORD vfTable;
	bool bIsFullscreen;
	int FullscreenBitsPerPixel;
	int FullscreenRefreshRate;
	int FullscreenWidth;
	int FullscreenHeight;
	int WindowedWidth;
	int WindowedHeight;
    int WindowOffsetX;
    int WindowOffsetY;
	int RestoredWidth;
	int RestoredHeight;
	int RestoredOffsetX;
	int RestoredOffsetY;
	SDeviceInfo DeviceTable[0x10];
	int DeviceCount;
	long DeviceIndex;
	bool bUseD3DTextureCompression;
	bool bResizable;
	bool bMaximized;
	bool bAlwaysOnTop;
	bool bActive;
	UINT ActiveThreadID;
	HWND ActiveWnd;
	bool bChangingScreenResolutions;
};
class CResolutionHandler : public CResolutionHandlerBase
{
public:
	void UpdateResolution(ResolutionUpdateData& data);
	DWORD GetWindowedStyle() const;
};
class CRespawnWnd
{
public:
EQLIB_OBJECT CRespawnWnd::CRespawnWnd(CXWnd*pParent);
// virtual
EQLIB_OBJECT CRespawnWnd::~CRespawnWnd();
};

class CScreenTemplate
{
public:
EQLIB_OBJECT CScreenTemplate::CScreenTemplate(class CParamScreen*);
// virtual
EQLIB_OBJECT CScreenTemplate::~CScreenTemplate();
//EQLIB_OBJECT void* CScreenTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CScreenTemplate::`vector deleting destructor'(unsigned int);
};

class CScrollbarTemplate
{
public:
EQLIB_OBJECT CScrollbarTemplate::~CScrollbarTemplate();
EQLIB_OBJECT CScrollbarTemplate::CScrollbarTemplate(class CScrollbarTemplate const &);
EQLIB_OBJECT CScrollbarTemplate::CScrollbarTemplate();
EQLIB_OBJECT class CScrollbarTemplate & CScrollbarTemplate::operator=(class CScrollbarTemplate const &);
};

class CSelectorWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSelectorWnd::CSelectorWnd(class CXWnd*);
EQLIB_OBJECT void CSelectorWnd::Activate();
EQLIB_OBJECT void CSelectorWnd::KeyMapUpdated();
// virtual
EQLIB_OBJECT CSelectorWnd::~CSelectorWnd();
EQLIB_OBJECT int CSelectorWnd::OnProcessFrame();
EQLIB_OBJECT int CSelectorWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CSelectorWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CSelectorWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSelectorWnd::Deactivate();
};

template <class ElementType, int Cnt> class HashCXStrElement
{
public:
    struct CKeyCXStrElementType
    {
		CXStr key;
		ElementType value;
    };
    ArrayClass2_RO<ArrayClass2_RO<CKeyCXStrElementType>> HashData;
};
class CXMLSymbolItem
{
public:
	CXStr ItemString;
	bool bDeclared;
	bool bValid;
};
class CXMLSymbolClass
{
public:
	CXStr Class;
	ArrayClass2_RO<CXMLSymbolItem> ItemsArray;
	CHashCXStrInt32 ItemsHashes;
	bool bValid;
};
class CXMLSymbolTable
{
public:
/*0x00*/ PVOID vfTable;
/*0x04*/ ArrayClass2_RO<CXMLSymbolClass> ClassesArray;
/*0x20*/ CHashCXStrInt32 ClassesHashes;
/*0x3C*/
};
class CXMLDataManager
{
public:
/*0x00*/ PVOID							vfTable;
/*0x00*/ CHashCXStrInt32				EnumTypeHashes;
/*0x00*/ ArrayClass2_RO<CXMLEnumInfo>	XMLEnumArray;//size 0x1c
/*0x1c*/ HashCXStrElement<CXMLDataPtr, 16* 1024> ClassItemHashes;//size 0x1c
/*0x38*/ ArrayClass2_RO<CXMLDataClass>	XMLDataArray;
/*0x54*/ CXMLSymbolTable				SymbolTable;
/*0x90*/ CXStr							ErrorString;
/*0x94*/ 
EQLIB_OBJECT CXMLDataManager::CXMLDataManager();
EQLIB_OBJECT bool CXMLDataManager::IsDerivedFrom(int, int);
EQLIB_OBJECT bool CXMLDataManager::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT class CXMLData* CXMLDataManager::GetXMLData(class CXStr, class CXStr);
EQLIB_OBJECT class CXMLData* CXMLDataManager::GetXMLData(int, int);
EQLIB_OBJECT int CXMLDataManager::GetClassIdx(class CXStr);
EQLIB_OBJECT int CXMLDataManager::GetItemIdx(int, class CXStr);
EQLIB_OBJECT int CXMLDataManager::GetNumClass();
EQLIB_OBJECT int CXMLDataManager::GetNumItem(int);
// virtual
EQLIB_OBJECT CXMLDataManager::~CXMLDataManager();
EQLIB_OBJECT bool CXMLDataManager::DataValidate();
EQLIB_OBJECT bool CXMLDataManager::ReadValidate(class CMemoryStream &);
EQLIB_OBJECT bool CXMLDataManager::WriteValidate(class CMemoryStream &);
EQLIB_OBJECT int CXMLDataManager::GetStreamSize();
//EQLIB_OBJECT void* CXMLDataManager::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CXMLDataManager::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CXMLDataManager::IndexAll();
EQLIB_OBJECT void CXMLDataManager::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CXMLDataManager::Set(class CXMLDataManager &);
EQLIB_OBJECT void CXMLDataManager::WriteToStream(class CMemoryStream &);
// protected
EQLIB_OBJECT void CXMLDataManager::AddToSuperType(class CXStr, class CXMLDataPtr);
EQLIB_OBJECT void CXMLDataManager::SetEnumHash();
};
class CXMLParamManager : public CXMLDataManager
{
public:
// virtual
EQLIB_OBJECT CXMLParamManager::~CXMLParamManager();
EQLIB_OBJECT bool CXMLParamManager::XMLDataCopy(class CXMLData*, class CXMLData*);
EQLIB_OBJECT class CXMLData* CXMLParamManager::AllocPtr(class CXMLDataPtr &, int, class CXMLData const*);
//EQLIB_OBJECT void* CXMLParamManager::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CXMLParamManager::`vector deleting destructor'(unsigned int);
};

class CSidlManagerBase
{
#if !defined(TEST) && !defined(LIVE)
/*0x000*/ void*vftable;
/*0x004*/ int ScreenPieceClassIndex[5];
/*0x018*/ ArrayClass_RO<CUITextureInfo*>		Textures;
/*0x028*/ ArrayClass_RO<CButtonDrawTemplate*>	ButtonDrawTemplateArray;
/*0x038*/ ArrayClass_RO<CScrollbarTemplate*>	ScrollbarTemplateArray;
/*0x048*/ ArrayClass_RO<CSliderDrawTemplate*>	SliderDrawTemplateArray;
/*0x058*/ ArrayClass_RO<CXStr>				ScreenNameArray;
/*0x068*/ ArrayClass_RO<CXWndDrawTemplate*>	DrawTemplateArray;
/*0x078*/ CHashCXStrInt32						DrawTemplateHash;//size 0x1c
/*0x094*/ ArrayClass_RO<CTextureAnimation*>	AnimationArray;
/*0x0A4*/ CHashCXStrInt32						AnimationsHash;
/*0x0C0*/ ArrayClass_RO<CTAFrameDraw*>		TAFrameArray;
/*0x0D0*/ CHashCXStrInt32						TAFrameHash;
/*0x0EC*/ ArrayClass_RO<CScreenPieceTemplate*> ScreenPieceArray;
/*0x0FC*/ CHashCXStrInt32						ScreenPiecesHash;
/*0x118*/ ArrayClass_RO<void*> LayoutStrategyTemplateArray;//CLayoutStrategyTemplate* todo: map this later...
/*0x128*/ CHashCXStrInt32 LayoutStrategyTemplatesHash;
/*0x144*/ CXMLParamManager XMLDataMgr;//size 0xB4
/*0x1F8*/ bool bLoadError;
/*0x1FC*/ CXStr ErrorString;
/*0x200*/
#else
/*0x000*/ void*vftable;
/*0x004*/ int ScreenPieceClassIndex[5];
/*0x018*/ ArrayClass_RO<CUITextureInfo*>		Textures;
/*0x028*/ ArrayClass_RO<CButtonDrawTemplate*>	ButtonDrawTemplateArray;
/*0x038*/ ArrayClass_RO<CScrollbarTemplate*>	ScrollbarTemplateArray;
/*0x048*/ ArrayClass_RO<CSliderDrawTemplate*>	SliderDrawTemplateArray;
/*0x058*/ ArrayClass_RO<CXStr>				ScreenNameArray;
/*0x068*/ ArrayClass_RO<CXWndDrawTemplate*>	DrawTemplateArray;
/*0x078*/ CHashCXStrInt32						DrawTemplateHash;//size 0x18
/*0x090*/ ArrayClass_RO<CTextureAnimation*>	AnimationArray;
/*0x0A0*/ CHashCXStrInt32						AnimationsHash;
/*0x0B8*/ ArrayClass_RO<CTAFrameDraw*>		TAFrameArray;
/*0x0C8*/ CHashCXStrInt32						TAFrameHash;
/*0x0E0*/ ArrayClass_RO<CScreenPieceTemplate*> ScreenPieceArray;
/*0x0F0*/ CHashCXStrInt32						ScreenPiecesHash;
/*0x108*/ ArrayClass_RO<void*> LayoutStrategyTemplateArray;//CLayoutStrategyTemplate* todo: map this later...
/*0x118*/ CHashCXStrInt32 LayoutStrategyTemplatesHash;
/*0x130*/ CXMLParamManager XMLDataMgr;//size 0x9c
/*0x1CC*/ bool bLoadError;
/*0x1D0*/ CXStr ErrorString;
/*0x1D4*/
#endif
};
//size 0x200 see 53ED93 in 2019 01 11 eqgame.exe
class CSidlManager : public CSidlManagerBase
{
public:
EQLIB_OBJECT CSidlManager::CSidlManager();
EQLIB_OBJECT CButtonDrawTemplate*CSidlManager::FindButtonDrawTemplate(const CXStr& Name) const;
EQLIB_OBJECT CButtonDrawTemplate*CSidlManager::FindButtonDrawTemplate(uint32_t ID) const;
EQLIB_OBJECT class CButtonDrawTemplate CSidlManager::GetButtonDrawTemplateFromParamButtonDrawTemplate(class CParamButtonDrawTemplate const &) const;
EQLIB_OBJECT class CGaugeDrawTemplate CSidlManager::GetGaugeDrawTemplateFromParamGaugeDrawTemplate(class CParamGaugeDrawTemplate const &) const;
EQLIB_OBJECT class CScreenPieceTemplate* CSidlManager::CreateScreenPieceTemplateFromParamScreenPiece(class CParamScreenPiece const*) const;
EQLIB_OBJECT class CScreenPieceTemplate* CSidlManager::FindScreenPieceTemplate(class CXStr*) const;
EQLIB_OBJECT class CScreenPieceTemplate* CSidlManager::FindScreenPieceTemplate(char*);
EQLIB_OBJECT class CScreenPieceTemplate* CSidlManager::FindScreenPieceTemplate(uint32_t) const;
EQLIB_OBJECT class CScrollbarTemplate CSidlManager::GetScrollbarTemplateFromParamScrollbarTemplate(class CParamScrollbarDrawTemplate const &) const;
EQLIB_OBJECT class CSliderDrawTemplate* CSidlManager::FindSliderDrawTemplate(class CXStr) const;
EQLIB_OBJECT class CSliderDrawTemplate* CSidlManager::FindSliderDrawTemplate(uint32_t) const;
EQLIB_OBJECT class CSliderDrawTemplate CSidlManager::GetSliderDrawTemplateFromParamSliderDrawTemplate(class CParamSliderDrawTemplate const &) const;
EQLIB_OBJECT class CSpellGemDrawTemplate CSidlManager::GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate(class CParamSpellGemDrawTemplate const &) const;
EQLIB_OBJECT class CTAFrameDraw* CSidlManager::FindFrameDraw(uint32_t) const;
EQLIB_OBJECT class CTAFrameDraw CSidlManager::CreateTAFrameDrawFromSidlFrame(class CParamFrameTemplate const*) const;
EQLIB_OBJECT class CTextureAnimation* CSidlManager::FindAnimation(class CXStr const &) const;
EQLIB_OBJECT class CTextureAnimation* CSidlManager::FindAnimation(uint32_t) const;
EQLIB_OBJECT class CTextureAnimation CSidlManager::CreateTextureAnimationFromSidlAnimation(class CParamUi2DAnimation const*) const;
EQLIB_OBJECT class CXStr CSidlManager::GetParsingErrorMsg() const;
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT class CXWnd* CSidlManager::CreateXWndFromTemplate(class CXWnd*, class CControlTemplate*, bool bSomething = 0);
#else
EQLIB_OBJECT class CXWnd* CSidlManager::CreateXWndFromTemplate(class CXWnd*, class CControlTemplate*);
#endif
EQLIB_OBJECT CXWnd* CSidlManager::CreateXWnd(CXWnd*pwndParent, CControlTemplate*pControl);
EQLIB_OBJECT CXWnd* CSidlManager::CreateHotButtonWnd(CXWnd* pwndParent, CControlTemplate* pControl);
EQLIB_OBJECT CXWnd* CSidlManager::CreateXWndFromTemplate(CXWnd*, CXStr &);
EQLIB_OBJECT class CXWndDrawTemplate* CSidlManager::FindDrawTemplate(CXStr*) const;
EQLIB_OBJECT class CXWndDrawTemplate* CSidlManager::FindDrawTemplate(uint32_t) const;
EQLIB_OBJECT class CXWndDrawTemplate CSidlManager::CreateDrawTemplateFromParamWindowDrawTemplate(class CParamWindowDrawTemplate const*) const;
//EQLIB_OBJECT enum EStaticScreenPieceClasses CSidlManager::GetScreenPieceEnum(class CScreenPieceTemplate*) const;
EQLIB_OBJECT static class CXPoint __cdecl CSidlManager::GetPointFromParamPoint(class CParamPoint const &);
EQLIB_OBJECT static class CXRect __cdecl CSidlManager::GetRectFromParamPointSize(class CParamPoint const &, class CParamSize const &);
EQLIB_OBJECT static class CXSize __cdecl CSidlManager::GetSizeFromParamSize(class CParamSize const &);
EQLIB_OBJECT static class CXStr __cdecl CSidlManager::TranslateString(class CXStr);
EQLIB_OBJECT static unsigned long __cdecl CSidlManager::GetD3DCOLOR(class CParamRGB const &);
EQLIB_OBJECT class CUITextureInfo* CSidlManager::FindTexture(class CXStr) const;
EQLIB_OBJECT class CUITextureInfo* CSidlManager::FindTexture(uint32_t) const;
EQLIB_OBJECT void CSidlManager::AddAnimationInOrder(class CTextureAnimation*);
EQLIB_OBJECT void CSidlManager::AddDrawTemplateInOrder(class CXWndDrawTemplate*);
EQLIB_OBJECT void CSidlManager::AddScreenPieceTemplateInOrder(class CScreenPieceTemplate*);
EQLIB_OBJECT void CSidlManager::AddTAFrameDrawInOrder(class CTAFrameDraw*);
EQLIB_OBJECT void CSidlManager::DeleteContents();
EQLIB_OBJECT void CSidlManager::LoadSidl(CXStr const &, CXStr const &, CXStr const &, CXStr const &);
// virtual
EQLIB_OBJECT CSidlManager::~CSidlManager();
//EQLIB_OBJECT void* CSidlManager::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CSidlManager::`vector deleting destructor'(unsigned int);
};

class CSkillsSelectWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSkillsSelectWnd::CSkillsSelectWnd(class CXWnd*);
EQLIB_OBJECT void CSkillsSelectWnd::Refresh();
EQLIB_OBJECT void CSkillsSelectWnd::SetTypesToDisplay(int);
// virtual
EQLIB_OBJECT CSkillsSelectWnd::~CSkillsSelectWnd();
EQLIB_OBJECT bool CSkillsSelectWnd::IsActive();
EQLIB_OBJECT int CSkillsSelectWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CSkillsSelectWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CSkillsSelectWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSkillsSelectWnd::Activate();
EQLIB_OBJECT void CSkillsSelectWnd::Deactivate();
// private
EQLIB_OBJECT void CSkillsSelectWnd::UpdateAll();
EQLIB_OBJECT void CSkillsSelectWnd::UpdateSkill(int);
};

class CSkillsWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSkillsWnd::CSkillsWnd(class CXWnd*);
EQLIB_OBJECT void CSkillsWnd::Activate();
EQLIB_OBJECT void CSkillsWnd::SkillImproveOccurred(int);
// virtual
EQLIB_OBJECT CSkillsWnd::~CSkillsWnd();
EQLIB_OBJECT int CSkillsWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CSkillsWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CSkillsWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSkillsWnd::Deactivate();
// protected
EQLIB_OBJECT void CSkillsWnd::UpdateAll();
EQLIB_OBJECT void CSkillsWnd::UpdateSkill(int);
};

class CSliderDrawTemplate
{
public:
EQLIB_OBJECT CSliderDrawTemplate::~CSliderDrawTemplate();
};

class CSliderTemplate
{
public:
EQLIB_OBJECT CSliderTemplate::CSliderTemplate(class CParamSlider*);
// virtual
EQLIB_OBJECT CSliderTemplate::~CSliderTemplate();
//EQLIB_OBJECT void* CSliderTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CSliderTemplate::`vector deleting destructor'(unsigned int);
};

class CSliderWnd: public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSliderWnd::CSliderWnd(class CXWnd*, uint32_t, class CXRect, class CSliderTemplate*);
EQLIB_OBJECT class CXRect CSliderWnd::GetEndCapLeftRect() const;
EQLIB_OBJECT class CXRect CSliderWnd::GetEndCapRightRect() const;
EQLIB_OBJECT class CXRect CSliderWnd::GetMiddleRangeRect() const;
EQLIB_OBJECT class CXRect CSliderWnd::GetThumbRect() const;
EQLIB_OBJECT int CSliderWnd::GetValue() const;
EQLIB_OBJECT void CSliderWnd::SetNumTicks(int);
EQLIB_OBJECT void CSliderWnd::SetValue(int);
// virtual
EQLIB_OBJECT CSliderWnd::~CSliderWnd();
EQLIB_OBJECT int CSliderWnd::Draw() const;
EQLIB_OBJECT int CSliderWnd::HandleKeyboardMsg(uint32_t, uint32_t, bool);
EQLIB_OBJECT int CSliderWnd::HandleLButtonDown(class CXPoint, uint32_t);
EQLIB_OBJECT int CSliderWnd::HandleLButtonUp(class CXPoint, uint32_t);
EQLIB_OBJECT int CSliderWnd::HandleLButtonUpAfterHeld(class CXPoint, uint32_t);
EQLIB_OBJECT int CSliderWnd::HandleMouseMove(class CXPoint, uint32_t);
EQLIB_OBJECT int CSliderWnd::OnProcessFrame();
//EQLIB_OBJECT void* CSliderWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CSliderWnd::`vector deleting destructor'(unsigned int);
// private
EQLIB_OBJECT int CSliderWnd::DrawEndCapLeft() const;
EQLIB_OBJECT int CSliderWnd::DrawEndCapRight() const;
EQLIB_OBJECT int CSliderWnd::DrawMiddleRange() const;
EQLIB_OBJECT int CSliderWnd::DrawThumb() const;
EQLIB_OBJECT void CSliderWnd::SetThumbToOffset(int);
EQLIB_OBJECT void CSliderWnd::UpdateMiddleRange();
EQLIB_OBJECT void CSliderWnd::UpdateThumb();
};

class CSocialEditWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSocialEditWnd::CSocialEditWnd(class CXWnd*);
EQLIB_OBJECT unsigned long CSocialEditWnd::GetSocialTextColor(int);
EQLIB_OBJECT void CSocialEditWnd::Activate(int);
// virtual
EQLIB_OBJECT CSocialEditWnd::~CSocialEditWnd();
EQLIB_OBJECT int CSocialEditWnd::Draw() const;
EQLIB_OBJECT int CSocialEditWnd::OnProcessFrame();
EQLIB_OBJECT int CSocialEditWnd::OnSetFocus(class CXWnd*);
EQLIB_OBJECT int CSocialEditWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CSocialEditWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CSocialEditWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSocialEditWnd::Deactivate();
// private
EQLIB_OBJECT void CSocialEditWnd::ClickedAccept();
EQLIB_OBJECT void CSocialEditWnd::ClickedClear();
EQLIB_OBJECT void CSocialEditWnd::ClickedTextColorButton(int);
EQLIB_OBJECT void CSocialEditWnd::Init();
EQLIB_OBJECT void CSocialEditWnd::UpdateControlsFromSocial();
};

class CSoulmarkWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSoulmarkWnd::CSoulmarkWnd(class CXWnd*);
EQLIB_OBJECT void CSoulmarkWnd::Activate(char*, char*);
EQLIB_OBJECT void CSoulmarkWnd::Activate();
EQLIB_OBJECT void CSoulmarkWnd::Clear();
EQLIB_OBJECT void CSoulmarkWnd::FillFields();
EQLIB_OBJECT void CSoulmarkWnd::Inquire(char*);
EQLIB_OBJECT void CSoulmarkWnd::Praise(char*);
EQLIB_OBJECT void CSoulmarkWnd::SaveMarks();
EQLIB_OBJECT void CSoulmarkWnd::UpdateList();
EQLIB_OBJECT void CSoulmarkWnd::UpdateSoulmarks(struct soulMarkMsg*);
EQLIB_OBJECT void CSoulmarkWnd::Warn(char*);
// virtual
EQLIB_OBJECT CSoulmarkWnd::~CSoulmarkWnd();
EQLIB_OBJECT int CSoulmarkWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CSoulmarkWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CSoulmarkWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSoulmarkWnd::Deactivate();
// protected
EQLIB_OBJECT void CSoulmarkWnd::AddMark(int, char*, char*, char*);
EQLIB_OBJECT void CSoulmarkWnd::Inquire(char*, char*);
};

class CSpellBookWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSpellBookWnd::CSpellBookWnd(class CXWnd*);
EQLIB_OBJECT bool CSpellBookWnd::StartSpellMemorization(int, int, bool);
EQLIB_OBJECT int CSpellBookWnd::GetSpellMemTicksLeft();
EQLIB_OBJECT int CSpellBookWnd::GetSpellScribeTicksLeft();
EQLIB_OBJECT static int __cdecl CSpellBookWnd::GetBookSlot(int);
EQLIB_OBJECT void CSpellBookWnd::Activate();
EQLIB_OBJECT void CSpellBookWnd::AutoMemSpell(int, int);
EQLIB_OBJECT void CSpellBookWnd::DeleteSpellFromBook(int, int);
EQLIB_OBJECT void CSpellBookWnd::FinishMemorizing(int, int);
EQLIB_OBJECT void CSpellBookWnd::FinishScribing(int, int);
EQLIB_OBJECT void CSpellBookWnd::MemorizeSet(int*, int);
EQLIB_OBJECT void CSpellBookWnd::RequestSpellDeletion(int);
EQLIB_OBJECT void CSpellBookWnd::SwapSpellBookSlots(int, int);
EQLIB_OBJECT void CSpellBookWnd::TurnToPage(int);
// virtual
EQLIB_OBJECT CSpellBookWnd::~CSpellBookWnd();
EQLIB_OBJECT int CSpellBookWnd::Draw() const;
EQLIB_OBJECT int CSpellBookWnd::HandleKeyboardMsg(uint32_t, uint32_t, bool);
EQLIB_OBJECT int CSpellBookWnd::OnProcessFrame();
EQLIB_OBJECT int CSpellBookWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CSpellBookWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CSpellBookWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSpellBookWnd::Deactivate();
// private
EQLIB_OBJECT bool CSpellBookWnd::CanStartMemming(int);
EQLIB_OBJECT void CSpellBookWnd::ContinueSetMem();
EQLIB_OBJECT void CSpellBookWnd::DelayedSpellMem(int, int, int);
EQLIB_OBJECT void CSpellBookWnd::DisplaySpellInfo(int);
EQLIB_OBJECT void CSpellBookWnd::EndSetMem();
EQLIB_OBJECT void CSpellBookWnd::GetSpellDeletionConfirmation(int);
EQLIB_OBJECT void CSpellBookWnd::HandleLeftClickOnSpell(int);
EQLIB_OBJECT void CSpellBookWnd::HandleRightClickOnSpell(int);
EQLIB_OBJECT void CSpellBookWnd::HandleSpellInfoDisplay(class CXWnd*);
EQLIB_OBJECT void CSpellBookWnd::Init();
EQLIB_OBJECT void CSpellBookWnd::StartSpellMemorizationDrag(int, class CButtonWnd*);
EQLIB_OBJECT void CSpellBookWnd::StartSpellScribe(int);
EQLIB_OBJECT void CSpellBookWnd::StopSpellBookAction();
EQLIB_OBJECT void CSpellBookWnd::UpdateSpellBookDisplay();
};

class CSpellGemDrawTemplate
{
public:
EQLIB_OBJECT CSpellGemDrawTemplate::~CSpellGemDrawTemplate();
};

class CSpellGemTemplate
{
public:
EQLIB_OBJECT CSpellGemTemplate::CSpellGemTemplate(class CParamSpellGem*);
// virtual
EQLIB_OBJECT CSpellGemTemplate::~CSpellGemTemplate();
//EQLIB_OBJECT void* CSpellGemTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CSpellGemTemplate::`vector deleting destructor'(unsigned int);
};

class CSpellGemWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSpellGemWnd::CSpellGemWnd(class CXWnd*, uint32_t, class CXRect, class CTextureAnimation*, class CTextureAnimation*, class CTextureAnimation*, int, int, unsigned long);
EQLIB_OBJECT void CSpellGemWnd::SetCheck(bool);
EQLIB_OBJECT void CSpellGemWnd::SetGemTintStage(int);
EQLIB_OBJECT void CSpellGemWnd::SetSpellGemTint(unsigned long);
EQLIB_OBJECT void CSpellGemWnd::SetSpellIconIndex(int);
// virtual
EQLIB_OBJECT CSpellGemWnd::~CSpellGemWnd();
EQLIB_OBJECT int CSpellGemWnd::Draw() const;
EQLIB_OBJECT int CSpellGemWnd::HandleLButtonDown(class CXPoint, uint32_t);
EQLIB_OBJECT int CSpellGemWnd::HandleLButtonHeld(class CXPoint, uint32_t);
EQLIB_OBJECT int CSpellGemWnd::HandleLButtonUp(class CXPoint, uint32_t);
EQLIB_OBJECT int CSpellGemWnd::HandleLButtonUpAfterHeld(class CXPoint, uint32_t);
EQLIB_OBJECT int CSpellGemWnd::HandleRButtonDown(class CXPoint, uint32_t);
EQLIB_OBJECT int CSpellGemWnd::HandleRButtonHeld(class CXPoint, uint32_t);
EQLIB_OBJECT int CSpellGemWnd::HandleRButtonUp(class CXPoint, uint32_t);
EQLIB_OBJECT int CSpellGemWnd::HandleRButtonUpAfterHeld(class CXPoint, uint32_t);
EQLIB_OBJECT int CSpellGemWnd::OnProcessFrame();
//EQLIB_OBJECT void* CSpellGemWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CSpellGemWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSpellGemWnd::SetAttributesFromSidl(class CParamScreenPiece*);
// protected
EQLIB_OBJECT void CSpellGemWnd::Init();
};

class CStaticAnimationTemplate
{
public:
EQLIB_OBJECT CStaticAnimationTemplate::CStaticAnimationTemplate(class CParamStaticAnimation*);
// virtual
EQLIB_OBJECT CStaticAnimationTemplate::~CStaticAnimationTemplate();
//EQLIB_OBJECT void* CStaticAnimationTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CStaticAnimationTemplate::`vector deleting destructor'(unsigned int);
};

class CStaticFrameTemplate
{
public:
EQLIB_OBJECT CStaticFrameTemplate::CStaticFrameTemplate(class CParamStaticFrame*);
// virtual
EQLIB_OBJECT CStaticFrameTemplate::~CStaticFrameTemplate();
//EQLIB_OBJECT void* CStaticFrameTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CStaticFrameTemplate::`vector deleting destructor'(unsigned int);
};

class CStaticHeaderTemplate
{
public:
EQLIB_OBJECT CStaticHeaderTemplate::CStaticHeaderTemplate(class CParamStaticHeader*);
// virtual
EQLIB_OBJECT CStaticHeaderTemplate::~CStaticHeaderTemplate();
//EQLIB_OBJECT void* CStaticHeaderTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CStaticHeaderTemplate::`vector deleting destructor'(unsigned int);
};

class CStaticScreenPieceTemplate
{
public:
EQLIB_OBJECT CStaticScreenPieceTemplate::CStaticScreenPieceTemplate(class CParamStaticScreenPiece*);
// virtual
EQLIB_OBJECT CStaticScreenPieceTemplate::~CStaticScreenPieceTemplate();
//EQLIB_OBJECT void* CStaticScreenPieceTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CStaticScreenPieceTemplate::`vector deleting destructor'(unsigned int);
};

class CStaticTextTemplate
{
public:
EQLIB_OBJECT CStaticTextTemplate::CStaticTextTemplate(class CParamStaticText*);
EQLIB_OBJECT class CXStr CStaticTextTemplate::SetText(class CXStr);
// virtual
EQLIB_OBJECT CStaticTextTemplate::~CStaticTextTemplate();
//EQLIB_OBJECT void* CStaticTextTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CStaticTextTemplate::`vector deleting destructor'(unsigned int);
};

class CSTMLboxTemplate
{
public:
EQLIB_OBJECT CSTMLboxTemplate::CSTMLboxTemplate(class CParamSTMLbox*);
// virtual
EQLIB_OBJECT CSTMLboxTemplate::~CSTMLboxTemplate();
//EQLIB_OBJECT void* CSTMLboxTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CSTMLboxTemplate::`vector deleting destructor'(unsigned int);
};

class CStmlReport
{
public:
EQLIB_OBJECT class CXStr CStmlReport::GetReport() const;
EQLIB_OBJECT static class CStmlReport* __cdecl CStmlReport::CreateReport(class CXStr);
// private
EQLIB_OBJECT static uint32_t CStmlReport::LastID;
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
	eSTMLLinkType Type;
	uint32_t MsgID;
	PCXSTR Name;
	estmlTargetType TargetType;
};
struct HistoryElement
{
	SLinkInfo sLink;
	PCXSTR STMLText;
};
enum eSTMLParseState
{
	sps_Body,
	sps_Head,
};
struct _FontTag
{
	CTextureFont* Face;
	COLORREF Color;
};
struct _FormattedText
{
	_FontTag Font;
	uint32_t Style;
	int	Left;
	int	Right;
	PCXSTR Text;
	int32_t	LinkID;
	CTextureAnimation*Texture;
	int32_t TableID;
	int32_t IndexStart;
};

struct STextLine
{
	ArrayClass_RO<_FormattedText> TextPieces;
	int yBottom;
	int yTop;
	int32_t	IndexStart;
};

//size is 0x2b8 in sep 11 2017 test see 8DCF69
class CStmlWnd//ok Look... this SHOULD inherit CXWnd but doing so... calls the constructor, and we dont want that... so... : public CXWnd
{
public:
	//we include CXW instead...
/*0x000*/ CXW
/*0x1F0*/ PCXSTR STMLText;
/*0x1F4*/ CircularArrayClass2<STextLine> TextLines;//size 0x24
/*0x21c*/ int32_t TextTotalHeight;
/*0x220*/ int32_t TextTotalWidth;//0x220 see 8F5A6F in sep 11 2017 test - eqmule
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x224*/ int32_t Unknown0x224;//this value was first added in the apr 27 2017 test patch see 8EAB3B, timestamp related? heroic stuff? calendar? something... dont know - eqmule
#endif
/*0x228*/ ArrayClass2_RO<SLinkInfo> Links;//size 0x1c at 0x228 for sure see 8F4487 in Sep 11 2017 test - eqmule
/*0x244*/ ArrayClass_RO<STable>	Tables;
/*0x254*/ bool		bReparseNow;
/*0x255*/ bool		bResized;
/*0x256*/ bool		bAlignCenter;
/*0x258*/ int		LineSpacingAdjust;
/*0x25c*/ int32_t	CapturedLinkID;
/*0x260*/ int32_t	MousedOverLinkID;
/*0x264*/ COLORREF	BackGroundColor;
/*0x268*/ COLORREF	TextColor;
/*0x26c*/ COLORREF	LinkColor;
/*0x270*/ COLORREF	VLinkColor;
/*0x274*/ COLORREF	ALinkColor;
/*0x278*/ COLORREF	MLinkColor;
/*0x27c*/ eSTMLParseState	CurrentParseState;
/*0x280*/ ArrayClass2_RO<HistoryElement> HistoryArray;
/*0x29c*/ int32_t		HistoryIndex;
/*0x2a0*/ CStmlReport	*pStmlReport;
/*0x2a4*/ int		MaxLines;
/*0x2a8*/ int		PlayerContextMenuIndex;
/*0x2ac*/ int		Unknown0x2ac;
/*0x2b0*/ int		Unknown0x2b0;
/*0x2b4*/ int		Unknown0x2b4;
/*0x2b8*/ 
EQLIB_OBJECT CStmlWnd::CStmlWnd(class CXWnd*, uint32_t, class CXRect);
EQLIB_OBJECT bool CStmlWnd::CanGoBackward();
EQLIB_OBJECT CXSize CStmlWnd::AppendSTML(CXStr); // lax 11-15-2003
EQLIB_OBJECT class CXStr CStmlWnd::GetSTMLText() const;
EQLIB_OBJECT class CXStr CStmlWnd::GetVisibleText(class CXStr&, class CXRect) const;
EQLIB_OBJECT static class CXStr __cdecl CStmlWnd::MakeStmlColorTag(unsigned long);
EQLIB_OBJECT static class CXStr __cdecl CStmlWnd::MakeWndNotificationTag(uint32_t, class CXStr&, class CXStr&);
EQLIB_OBJECT void CStmlWnd::ActivateLink(SLinkInfo);
EQLIB_OBJECT void CStmlWnd::ForceParseNow();
EQLIB_OBJECT void CStmlWnd::GoToBackHistoryLink();
//EQLIB_OBJECT void CStmlWnd::LoadPage(class CXStr, enum ESTMLTargetValue, bool);
EQLIB_OBJECT void CStmlWnd::SetSTMLText(class CXStr, bool, SLinkInfo*);
EQLIB_OBJECT void CStmlWnd::SetSTMLTextWithoutHistory(class CXStr);
// virtual
EQLIB_OBJECT CStmlWnd::~CStmlWnd();
EQLIB_OBJECT bool CStmlWnd::IsPointTransparent(class CXPoint) const;
EQLIB_OBJECT class CTextureAnimation* CStmlWnd::GetCursorToDisplay() const;
EQLIB_OBJECT int CStmlWnd::Draw() const;
EQLIB_OBJECT int CStmlWnd::HandleKeyboardMsg(uint32_t, uint32_t, bool);
EQLIB_OBJECT int CStmlWnd::HandleLButtonDown(class CXPoint, uint32_t);
EQLIB_OBJECT int CStmlWnd::HandleLButtonUp(class CXPoint, uint32_t);
EQLIB_OBJECT int CStmlWnd::HandleMouseMove(class CXPoint, uint32_t);
EQLIB_OBJECT int CStmlWnd::OnHScroll(EScrollCode, int);
EQLIB_OBJECT int CStmlWnd::OnMove(class CXRect);
EQLIB_OBJECT int CStmlWnd::OnProcessFrame();
EQLIB_OBJECT int CStmlWnd::OnResize(int, int);
EQLIB_OBJECT int CStmlWnd::OnVScroll(EScrollCode, int);
//EQLIB_OBJECT void* CStmlWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CStmlWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CStmlWnd::SetWindowTextA(class CXStr);
// protected
EQLIB_OBJECT bool CStmlWnd::IsLinkActive(SLinkInfo) const;
EQLIB_OBJECT bool CStmlWnd::ParseAmpersand(class CXStr, char*) const;
EQLIB_OBJECT static bool __cdecl CStmlWnd::CanBreakAtCharacter(unsigned short);
EQLIB_OBJECT static bool __cdecl CStmlWnd::IsCharacterNotASpaceAndNotNULL(unsigned short);
EQLIB_OBJECT static bool __cdecl CStmlWnd::IsCharacterNotEquals(unsigned short);
EQLIB_OBJECT static bool __cdecl CStmlWnd::IsCharacterNotQuotes(unsigned short);
EQLIB_OBJECT unsigned short CStmlWnd::FastForwardPastQuotesAndGetNextTagPiece(class CXStr&, class CXStr*, int*, bool);
EQLIB_OBJECT unsigned short CStmlWnd::FastForwardPastSpaces(class CXStr&, int*);
EQLIB_OBJECT unsigned short CStmlWnd::FastForwardPastSpacesAndQuotes(class CXStr&, int*);
EQLIB_OBJECT unsigned short CStmlWnd::FastForwardToEndOfTag(class CXStr&, class CXStr*, int*, char);
EQLIB_OBJECT unsigned short CStmlWnd::GetNextChar(int*, class CXStr&);
EQLIB_OBJECT unsigned short CStmlWnd::GetNextTagPiece(class CXStr&, class CXStr*, int*, bool (__cdecl*)(unsigned short), bool);
EQLIB_OBJECT unsigned short CStmlWnd::GetThisChar(int, class CXStr&);
EQLIB_OBJECT void CStmlWnd::ActivateLinkFile(SLinkInfo);
EQLIB_OBJECT void CStmlWnd::ActivateLinkMessageId(SLinkInfo);
EQLIB_OBJECT void CStmlWnd::ActivateLinkReport(SLinkInfo, bool);
EQLIB_OBJECT void CStmlWnd::ActivateLinkWndNotify(SLinkInfo);
EQLIB_OBJECT void CStmlWnd::AddLinkToHistory(SLinkInfo, class CXStr);
EQLIB_OBJECT void CStmlWnd::AddTextPieceToLine(class SParseVariables*);
EQLIB_OBJECT void CStmlWnd::CalculateHSBRange(int);
EQLIB_OBJECT void CStmlWnd::CalculateVSBRange(int);
EQLIB_OBJECT void CStmlWnd::CompleteParse();
EQLIB_OBJECT void CStmlWnd::InitializeTempVariables(class SParseVariables*, class CXRect);
EQLIB_OBJECT void CStmlWnd::InitializeTextLine(class SParseVariables*, int);
EQLIB_OBJECT void CStmlWnd::InitializeWindowVariables();
//EQLIB_OBJECT void CStmlWnd::ParseLinkTarget(class CXStr, enum ESTMLTargetValue*) const;
EQLIB_OBJECT void CStmlWnd::ParseSTMLHead(class CXStr&);
EQLIB_OBJECT void CStmlWnd::ParseSTMLTable(class CXStr&, int*, class CXStr, class SParseVariables*);
EQLIB_OBJECT void CStmlWnd::ParseSTMLTableAttributes(class CXStr&, class STable*);
//EQLIB_OBJECT void CStmlWnd::ParseTagAlign(class CXStr, enum ESTMLAlign*) const;
EQLIB_OBJECT void CStmlWnd::ParseTagColor(class CXStr&, unsigned long*) const;
EQLIB_OBJECT void CStmlWnd::ParseTagFace(class CXStr&, class CTextureFont const**) const;
EQLIB_OBJECT void CStmlWnd::ResetTempVariablesForNewLine(class SParseVariables*);
EQLIB_OBJECT void CStmlWnd::StripFirstSTMLLines(int);
EQLIB_OBJECT void CStmlWnd::UpdateHistoryString(int32_t, class CXStr&);
};

class CStoryWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CStoryWnd::CStoryWnd(class CXWnd*);
EQLIB_OBJECT bool CStoryWnd::HasNew();
EQLIB_OBJECT bool CStoryWnd::ShowAuto();
EQLIB_OBJECT void CStoryWnd::Activate();
EQLIB_OBJECT void CStoryWnd::SaveIni();
// virtual
EQLIB_OBJECT CStoryWnd::~CStoryWnd();
EQLIB_OBJECT int CStoryWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CStoryWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CStoryWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CStoryWnd::Deactivate();
EQLIB_OBJECT void CStoryWnd::LoadIniInfo();
// protected
EQLIB_OBJECT void CStoryWnd::SelectIndex(int);
EQLIB_OBJECT void CStoryWnd::SelectOldestNew();
// private
EQLIB_OBJECT void CStoryWnd::Init();
};

class CTabBoxTemplate
{
public:
EQLIB_OBJECT CTabBoxTemplate::CTabBoxTemplate(class CParamTabBox*);
// virtual
EQLIB_OBJECT CTabBoxTemplate::~CTabBoxTemplate();
//EQLIB_OBJECT void* CTabBoxTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CTabBoxTemplate::`vector deleting destructor'(unsigned int);
};

class CTabWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTabWnd::CTabWnd(CXWnd*pParent, UINT uId, RECT*rect, CTabBoxTemplate*pTabContents);
EQLIB_OBJECT class CPageWnd* CTabWnd::GetCurrentPage() const;
EQLIB_OBJECT class CXRect CTabWnd::GetPageClientRect() const;
EQLIB_OBJECT class CXRect CTabWnd::GetPageInnerRect() const;
EQLIB_OBJECT class CXRect CTabWnd::GetTabInnerRect(int) const;
EQLIB_OBJECT class CXRect CTabWnd::GetTabRect(int) const;
EQLIB_OBJECT int CTabWnd::GetCurrentTabIndex() const;
EQLIB_OBJECT int CTabWnd::GetNumTabs() const;
EQLIB_OBJECT void CTabWnd::InsertPage(class CPageWnd*, int);
EQLIB_OBJECT void CTabWnd::SetPage(class CPageWnd*, bool);
#if !defined(ROF2EMU) && !defined(UFEMU)
	void CTabWnd::SetPage(int index, bool bNotifyParent, bool bBringToTop = true, bool bSomething = true);
#else
	void CTabWnd::SetPage(int index, bool bNotifyParent);
#endif
EQLIB_OBJECT void CTabWnd::SetPageRect(class CXRect);
EQLIB_OBJECT void CTabWnd::UpdatePage();
// virtual
EQLIB_OBJECT CTabWnd::~CTabWnd();
EQLIB_OBJECT int CTabWnd::Draw() const;
EQLIB_OBJECT int CTabWnd::DrawTooltip(class CXWnd const*);
EQLIB_OBJECT int CTabWnd::HandleLButtonDown(class CXPoint, uint32_t);
EQLIB_OBJECT int CTabWnd::HandleLButtonUp(class CXPoint, uint32_t);
EQLIB_OBJECT int CTabWnd::OnResize(int, int);
EQLIB_OBJECT int CTabWnd::OnShow();
//EQLIB_OBJECT void* CTabWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CTabWnd::`vector deleting destructor'(unsigned int);
// private
EQLIB_OBJECT bool CTabWnd::IndexInBounds(int) const;
EQLIB_OBJECT CPageWnd* CTabWnd::GetPageFromTabIndex(int) const;
EQLIB_OBJECT CPageWnd* CTabWnd::GetPageFromTabPoint(class CXPoint) const;
EQLIB_OBJECT int CTabWnd::DrawCurrentPage() const;
EQLIB_OBJECT int CTabWnd::DrawTab(int) const;
};

class CTAFrameDraw
{
public:
EQLIB_OBJECT CTAFrameDraw::~CTAFrameDraw();
EQLIB_OBJECT CTAFrameDraw::CTAFrameDraw(class CTAFrameDraw const &);
EQLIB_OBJECT CTAFrameDraw::CTAFrameDraw(class CXStr);
EQLIB_OBJECT bool CTAFrameDraw::IsHorizontal() const;
EQLIB_OBJECT bool CTAFrameDraw::IsVertical() const;
EQLIB_OBJECT class CTAFrameDraw & CTAFrameDraw::operator=(class CTAFrameDraw const &);
EQLIB_OBJECT class CTextureAnimation* CTAFrameDraw::GetAnimation(int) const;
EQLIB_OBJECT class CXRect CTAFrameDraw::GetHitTestRect(class CXRect, int) const;
EQLIB_OBJECT class CXRect CTAFrameDraw::GetInnerRect(class CXRect) const;
EQLIB_OBJECT class CXRect CTAFrameDraw::GetPieceRect(class CXRect, int) const;
EQLIB_OBJECT class CXSize CTAFrameDraw::GetFrameSize() const;
EQLIB_OBJECT class CXStr CTAFrameDraw::GetName() const;
EQLIB_OBJECT int CTAFrameDraw::Draw(class CXRect, class CXRect) const;
EQLIB_OBJECT int CTAFrameDraw::Draw(class CXRect, class CXRect, int) const;
EQLIB_OBJECT int CTAFrameDraw::GetExtent() const;
EQLIB_OBJECT int CTAFrameDraw::GetMinLength() const;
EQLIB_OBJECT void CTAFrameDraw::Set(class CTextureAnimation** const);
};

class CTargetManager
{
public:
EQLIB_OBJECT static CTargetManager*CTargetManager::Get();
EQLIB_OBJECT void CTargetManager::Update();
};

class CTargetRing
{
public:
EQLIB_OBJECT int CTargetRing::Cast(CVector3*pos);
/*0x00*/	DWORD Gem;//the gem the spell below is memmed in... 0-11
/*0x04*/	PSPELL thespell;
/*0x08*/	ItemGlobalIndex ItemLoc;//size 0xc
/*0x14*/	ItemSpellTypes SpellType;
/*0x18*/	float SquaredRange;
/*0x1c*/	bool bCursorVisible;
/*0x20*/
};

class CTargetWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTargetWnd::CTargetWnd(class CXWnd*);
EQLIB_OBJECT void CTargetWnd::Activate();
// virtual
EQLIB_OBJECT CTargetWnd::~CTargetWnd();
EQLIB_OBJECT class CXStr*CTargetWnd::GetBuffCaster(int SpellID);
EQLIB_OBJECT int CTargetWnd::OnProcessFrame();
//EQLIB_OBJECT void* CTargetWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CTargetWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTargetWnd::Deactivate();
// private
EQLIB_OBJECT void CTargetWnd::Init();
EQLIB_OBJECT void CTargetWnd::RefreshTargetBuffs(PBYTE buffer);
EQLIB_OBJECT void CTargetWnd::HandleBuffRemoveRequest(CXWnd*pWnd);
};

class CTaskWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTaskWnd::CTaskWnd(class CXWnd*);
EQLIB_OBJECT int CTaskWnd::UpdateTaskTimers(unsigned long fasttime);
// virtual
EQLIB_OBJECT CTaskWnd::~CTaskWnd();
};
enum TaskType {
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
enum TaskGroupType {
	TGT_Solo,
	TGT_Group,
	TGT_Raid
};
typedef struct _CTaskElement
{
/*0x000*/ TaskType Type;
/*0x004*/ TaskGroupType GroupType;
/*0x008*/ CHAR TargetName[0x40];
/*0x048*/ CHAR ZoneID[0x40];
/*0x088*/ CHAR TargetZoneID[0x40];
/*0x0c8*/ int RequiredCount;
/*0x0cc*/ bool bOptional;
/*0x0d0*/ int ElementGroup;
/*0x0d4*/ int DZSwitchID;
/*0x0d8*/ CHAR ElementDescriptionOverride[0x80];
/*0x158*/ PCXSTR ItemNameList;
/*0x15c*/ PCXSTR SkillIDList;
/*0x160*/ PCXSTR SpellIDList;
/*0x164*/ PCXSTR TaskTitle;
/*0x168*/
} CTaskElement,*PCTaskElement;
typedef struct _CTaskEntry
{
/*0x0000*/ int TaskID;
/*0x0004*/ float RewardAdjustment;
/*0x0008*/ CHAR TaskTitle[0x40];
/*0x0048*/ int DurationSeconds;
/*0x004C*/ int DurCode;
/*0x0050*/ CHAR StartText[0xFa0];//4000
/*0x0FF0*/ bool bShowReward;
/*0x0FF4*/ int RewardCash;
/*0x0FF8*/ int RewardExp;
/*0x0FFC*/ int RewardPoints;
/*0x1000*/ int RewardFactionID;
/*0x1004*/ int RewardFactionAmount;
/*0x1008*/ PCXSTR RewardItemTag;
/*0x100C*/ CTaskElement Elements[0x14];//0x168* 0x14 = 0x1C20
/*0x2C2C*/ int TaskSystem;
/*0x2C30*/ int PointType;
/*0x2C34*/ bool StartTextCompiled;//for sure see 51B861 in Nov 13 2018 Live
/*0x0000*/ CHAR RawStartText[0xFa0];//4000
/*0x0000*/ bool bElementsReceived;
/*0x0000*/ __time32_t TimeCompleted;
/*0x3BDC*/ ArrayClass_RO<MonsterMissionTemplate> MonsterTemplates;
/*0x3BEC*/ bool bTemplateSelectionLocked;//51B887
/*0x3BED*/ bool bHasRewardSet;
/*0x3BF0*/ 
} CTaskEntry,*PCTaskEntry;
enum SharedTaskPlayerRole 
{ 
	STPR_None,
	STPR_Leader
};
typedef struct _SharedTaskClientPlayerInfo
{
	CHAR	Name[0x40];
	int		TemplateID;
	SharedTaskPlayerRole m_role;
	_SharedTaskClientPlayerInfo*pNext;
}SharedTaskClientPlayerInfo,*PSharedTaskClientPlayerInfo;

class CTaskManager// : public PopDialogHandler /*0x000000*/ 
{
public:
/*0x000000*/ PVOID vfTable;
/*0x000004*/ CTaskEntry TaskEntries[1];
/*0x003BF4*/ CTaskEntry QuestEntries[0x1d];//see 51B93B 0x1d* 0x3BF0 = 0x6CA30
/*0x070624*/ CTaskEntry SharedTaskEntries[1];
/*0x074214*/ CTaskEntry QuestHistoryEntries[0x32];
/*0x12F6F4*/ int AddPlayerID;
/*0x12F6F8*/ bool bAddPlayerIsSwap;
/*0x12F6FC*/ CHAR AddPlayerSwapeeName[0x40];
/*0x12F73C*/ SharedTaskClientPlayerInfo*pFirstMember;//51B9D8
/*0x12F740*/
EQLIB_OBJECT CTaskManager::CTaskManager(class CXWnd*);
// virtual
EQLIB_OBJECT CTaskManager::~CTaskManager();
EQLIB_OBJECT CTaskEntry*CTaskManager::GetEntry(int Index, int System, bool bCheckEmpty = true);
};
class CTextEntryWnd : public CEditBaseWnd
{
public:
EQLIB_OBJECT void CTextEntryWnd::Open(CXWnd*pwnd, int EditMode, char*Prompt, int MinLength, int MaxLength, const char*InitialText);
EQLIB_OBJECT CTextEntryWnd::CTextEntryWnd(class CXWnd*);
EQLIB_OBJECT class CXStr CTextEntryWnd::GetEntryText();
EQLIB_OBJECT void CTextEntryWnd::Activate(class CXWnd*, int, char*, int, int, char*);
EQLIB_OBJECT void CTextEntryWnd::Callback(bool);
// virtual
EQLIB_OBJECT CTextEntryWnd::~CTextEntryWnd();
EQLIB_OBJECT int CTextEntryWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CTextEntryWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CTextEntryWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTextEntryWnd::Deactivate();
// private
EQLIB_OBJECT void CTextEntryWnd::UpdateButtons();

/*0x148*///    DWORD Unknown0x148;
/*0x14C*/// DWORD Unknown0x14c;
/*0x150*/// PCXSTR Data;
/*0x154*/// DWORD Unknown0x154;
/*0x158*/// CSidlScreenWnd*Entry;
/*0x15c*/// CSidlScreenWnd*Prompt;
/*0x160*/// CSidlScreenWnd*OK;
/*0x164*/// CSidlScreenWnd*Cancel;
};

class CUITexturePiece
{
public:
	CUITextureInfo2 TInfo;
    RECT Rect;
EQLIB_OBJECT CUITexturePiece::~CUITexturePiece();
EQLIB_OBJECT CUITexturePiece::CUITexturePiece(class CUITexturePiece const &);
EQLIB_OBJECT CUITexturePiece::CUITexturePiece(class CUITextureInfo, class CXRect);
EQLIB_OBJECT CUITexturePiece::CUITexturePiece();
EQLIB_OBJECT class CUITexturePiece & CUITexturePiece::operator=(class CUITexturePiece const &);
EQLIB_OBJECT int CUITexturePiece::Draw(class CXRect, class CXRect, class CXRect, unsigned long, unsigned long) const;
EQLIB_OBJECT int CUITexturePiece::Draw(class CXRect, class CXRect, unsigned long, unsigned long) const;
};

struct STextureAnimationFrame
{
    CUITexturePiece TPiece;
    uint32_t Ticks;
    POINT Hotspot;
};
class CTextureAnimation
{
public:
	PVOID vfTable;
	PCXSTR Name;
    ArrayClass_RO<STextureAnimationFrame> Frames;

EQLIB_OBJECT CTextureAnimation::CTextureAnimation(class CXStr);
EQLIB_OBJECT CTextureAnimation::CTextureAnimation();
EQLIB_OBJECT class CTextureAnimation & CTextureAnimation::operator=(class CTextureAnimation const &);
EQLIB_OBJECT class CXPoint CTextureAnimation::GetHotspot() const;
EQLIB_OBJECT class CXStr CTextureAnimation::GetName() const;
EQLIB_OBJECT int CTextureAnimation::AddBlankFrame(uint32_t, class CXPoint);
EQLIB_OBJECT int CTextureAnimation::AddFrame(class CUITexturePiece, uint32_t, class CXPoint);
EQLIB_OBJECT int CTextureAnimation::AddFrame(class CUITextureInfo const*, class CXRect, uint32_t, class CXPoint);
EQLIB_OBJECT int CTextureAnimation::Draw(class CXPoint, class CXRect, unsigned long, unsigned long) const;
EQLIB_OBJECT int CTextureAnimation::Draw(class CXRect, class CXRect, unsigned long, unsigned long) const;
EQLIB_OBJECT int CTextureAnimation::GetCurFrame() const;
EQLIB_OBJECT int CTextureAnimation::Preload();
EQLIB_OBJECT void CTextureAnimation::Reset();
EQLIB_OBJECT void CTextureAnimation::SetCurCell(int);
EQLIB_OBJECT void CTextureAnimation::SetCurFrame(int);
// virtual
EQLIB_OBJECT CTextureAnimation::~CTextureAnimation();
//EQLIB_OBJECT void* CTextureAnimation::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CTextureAnimation::`vector deleting destructor'(unsigned int);
// protected
EQLIB_OBJECT static uint32_t CTextureAnimation::MaxID;
};

class CTextureFont
{
public:
EQLIB_OBJECT class CXStr CTextureFont::GetName() const;
EQLIB_OBJECT int CTextureFont::DrawWrappedText(class CXStr, class CXRect, class CXRect, unsigned long, unsigned short, int) const;
EQLIB_OBJECT int CTextureFont::DrawWrappedText(CXStr*Str, int x, int y, int Width, CXRect*BoundRect, COLORREF Color, WORD Flags = 0, int StartX = 0) const;
EQLIB_OBJECT int CTextureFont::GetHeight() const;
EQLIB_OBJECT int CTextureFont::GetKerning(unsigned short, unsigned short) const;
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT int CTextureFont::GetTextExtent(CXStr*);
#else
EQLIB_OBJECT int CTextureFont::GetTextExtent();
#endif
EQLIB_OBJECT int CTextureFont::GetWidth(unsigned short) const;
// virtual
EQLIB_OBJECT CTextureFont::~CTextureFont();
//EQLIB_OBJECT void* CTextureFont::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CTextureFont::`vector deleting destructor'(unsigned int);
void *vftable;
DWORD FontStyle;
};

class CTimeLeftWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTimeLeftWnd::CTimeLeftWnd(long);
EQLIB_OBJECT void CTimeLeftWnd::Activate();
// virtual
EQLIB_OBJECT CTimeLeftWnd::~CTimeLeftWnd();
EQLIB_OBJECT int CTimeLeftWnd::Draw() const;
EQLIB_OBJECT int CTimeLeftWnd::OnProcessFrame();
//EQLIB_OBJECT void* CTimeLeftWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CTimeLeftWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTimeLeftWnd::Deactivate();
};

class CTipWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTipWnd::CTipWnd(class CXWnd*, int);
EQLIB_OBJECT bool CTipWnd::Activate(int, bool);
EQLIB_OBJECT void CTipWnd::InitializeTipSettings();
EQLIB_OBJECT void CTipWnd::UpdateButtons();
// virtual
EQLIB_OBJECT CTipWnd::~CTipWnd();
EQLIB_OBJECT int CTipWnd::OnProcessFrame();
EQLIB_OBJECT int CTipWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CTipWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CTipWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTipWnd::Deactivate();
// protected
EQLIB_OBJECT bool CTipWnd::IsRecentTOTD(int);
EQLIB_OBJECT int CTipWnd::SelectRandomTip();
EQLIB_OBJECT void CTipWnd::AddContextTip(int);
EQLIB_OBJECT void CTipWnd::LoadINISettings();
EQLIB_OBJECT void CTipWnd::SetTOTD(int);
EQLIB_OBJECT void CTipWnd::ShowHistoryTip(int);
// private
EQLIB_OBJECT void CTipWnd::CleanDayTips();
EQLIB_OBJECT void CTipWnd::LoadDayTips();
};

class CTokenXML
{
public:
EQLIB_OBJECT CTokenXML::~CTokenXML();
};

class CTrackingWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTrackingWnd::CTrackingWnd(class CXWnd*);
EQLIB_OBJECT void CTrackingWnd::Activate();
EQLIB_OBJECT void CTrackingWnd::DoTrackFilter(bool);
EQLIB_OBJECT void CTrackingWnd::DoTrackSort(bool);
EQLIB_OBJECT void CTrackingWnd::RemovePlayerFromTracking(class EQPlayer*);
EQLIB_OBJECT void CTrackingWnd::SetTrackingList(struct TrackingHit*, int);
// virtual
EQLIB_OBJECT CTrackingWnd::~CTrackingWnd();
EQLIB_OBJECT int CTrackingWnd::Draw() const;
EQLIB_OBJECT int CTrackingWnd::OnProcessFrame();
EQLIB_OBJECT int CTrackingWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CTrackingWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CTrackingWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTrackingWnd::Deactivate();
// private
EQLIB_OBJECT int CTrackingWnd::GetListIdByData(unsigned int);
EQLIB_OBJECT unsigned long CTrackingWnd::GetTrackColor(int);
EQLIB_OBJECT void CTrackingWnd::GenerateTrackingList();
EQLIB_OBJECT void CTrackingWnd::Init();
EQLIB_OBJECT void CTrackingWnd::NotifyServerOfTrackingTarget(int);
EQLIB_OBJECT void CTrackingWnd::RemoveFromListWndByData(unsigned int);
EQLIB_OBJECT void CTrackingWnd::RemovePlayerFromTracking(int);
EQLIB_OBJECT void CTrackingWnd::UpdateTrackingControls();
EQLIB_OBJECT void CTrackingWnd::UpdateTrackingList(bool);
};

class CTradeWnd : public CSidlScreenWnd, public WndEventHandler2
{
public:
	UINT NextRefreshTime;
	bool bInventoryWasOpen;
    CButtonWnd*HisMoneyButton[4];
    CButtonWnd*MyMoneyButton[4];
    CButtonWnd*TradeButton;
    CButtonWnd*CancelButton;
	CLabel*HisNameLabel;
	CLabel*MyNameLabel;
	CInvSlotWnd*pInvSlotWnd[16];
	long HisMoney[4];
	long MyMoney[4];
	ItemBaseContainer TradeItems;//16 items
	bool bHisReadyTrade;
	bool bMyReadyTrade;
	bool bIsTrading;

EQLIB_OBJECT CTradeWnd::CTradeWnd(class CXWnd*);
EQLIB_OBJECT bool CTradeWnd::IsMyTradeSlot(int, bool*);
EQLIB_OBJECT void CTradeWnd::Activate(class EQPlayer*, bool);
EQLIB_OBJECT void CTradeWnd::AddContainerToHisTradeArray(class EQ_Container*);
EQLIB_OBJECT void CTradeWnd::AddEquipmentToHisTradeArray(class EQ_Equipment*);
EQLIB_OBJECT void CTradeWnd::AddNoteToHisTradeArray(class EQ_Note*);
EQLIB_OBJECT void CTradeWnd::ClickedCancelButton();
EQLIB_OBJECT void CTradeWnd::ClickedMoneyButton(int);
EQLIB_OBJECT void CTradeWnd::ClickedTradeButton();
EQLIB_OBJECT void CTradeWnd::CompleteTrade();
EQLIB_OBJECT void CTradeWnd::DeleteItemFromHisTradeArray(int);
EQLIB_OBJECT void CTradeWnd::DropItemIntoTrade();
EQLIB_OBJECT void CTradeWnd::SetHisMoney(int, long);
EQLIB_OBJECT void CTradeWnd::SetHisReadyTrade(bool);
EQLIB_OBJECT void CTradeWnd::SetMyReadyTrade(bool);
EQLIB_OBJECT void CTradeWnd::TradeItemChanged(int, int);
// virtual
EQLIB_OBJECT CTradeWnd::~CTradeWnd();
EQLIB_OBJECT int CTradeWnd::OnProcessFrame();
EQLIB_OBJECT int CTradeWnd::PostDraw() const;
EQLIB_OBJECT int CTradeWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CTradeWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CTradeWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTradeWnd::Deactivate();
// private
EQLIB_OBJECT void CTradeWnd::Init();
EQLIB_OBJECT void CTradeWnd::UpdateTradeDisplay();
};

class CTrainWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTrainWnd::CTrainWnd(class CXWnd*);
EQLIB_OBJECT void CTrainWnd::SetGMData(int*, unsigned char*, float);
EQLIB_OBJECT void CTrainWnd::SkillChanged(int);
// virtual
EQLIB_OBJECT CTrainWnd::~CTrainWnd();
EQLIB_OBJECT int CTrainWnd::OnProcessFrame();
EQLIB_OBJECT int CTrainWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CTrainWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CTrainWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTrainWnd::Deactivate();
// protected
EQLIB_OBJECT char* CTrainWnd::SkillName(int);
EQLIB_OBJECT int CTrainWnd::SkillValue(int);
EQLIB_OBJECT void CTrainWnd::Activate();
EQLIB_OBJECT void CTrainWnd::SortNames(int);
EQLIB_OBJECT void CTrainWnd::SortSkill(int);
EQLIB_OBJECT void CTrainWnd::SwapSkill(int, int);
EQLIB_OBJECT void CTrainWnd::Train();
EQLIB_OBJECT void CTrainWnd::UpdateAll(bool);
EQLIB_OBJECT void CTrainWnd::UpdateRight();
EQLIB_OBJECT void CTrainWnd::UpdateSkill(int);
};

class CTreeView : public CListWnd
{
public:
EQLIB_OBJECT CTreeView::CTreeView(class CXWnd*, uint32_t, class CXRect, int);
// virtual
EQLIB_OBJECT CTreeView::~CTreeView();
};

class CVideoModesWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CVideoModesWnd::CVideoModesWnd(class CXWnd*);
EQLIB_OBJECT void CVideoModesWnd::Activate();
EQLIB_OBJECT void CVideoModesWnd::RestoreOldMode();
EQLIB_OBJECT void CVideoModesWnd::Update();
// virtual
EQLIB_OBJECT CVideoModesWnd::~CVideoModesWnd();
EQLIB_OBJECT int CVideoModesWnd::Draw() const;
EQLIB_OBJECT int CVideoModesWnd::OnProcessFrame();
EQLIB_OBJECT int CVideoModesWnd::WndNotification(class CXWnd*, uint32_t, void*);
//EQLIB_OBJECT void* CVideoModesWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CVideoModesWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CVideoModesWnd::Deactivate();
// private
EQLIB_OBJECT void CVideoModesWnd::Init();
EQLIB_OBJECT void CVideoModesWnd::UpdateSelection(unsigned int);
};
//work in progress
class CNotification
{
public:
	int Type;
};
class IObserver;
class CObservable
{
public:
EQLIB_OBJECT void NotifyObservers(CNotification*Notification = 0)
{

	Sleep(0);
}

private:
	std::list<IObserver*> ObserverList;
};
class IObserver
{
public:
	//EQLIB_OBJECT virtual void IObserver::Notify(CObservable*Src, const CNotification* const Notification) = 0;
};
class Window
{
public:
	float Window::getProgress(bool &bIsLoading);
	const wchar_t*Window::getStatus() const;
	const char*Window::getURI() const;
};
class CHtmlComponentWnd //: public CXWnd, public mozilla::ICallback, public CObservable
{
public:
	CXW;
};
class CHtmlWnd : public CSidlScreenWnd, public TListNode<CHtmlWnd>
{
public:
	void CHtmlWnd::SetClientCallbacks(void* cb);
	void CHtmlWnd::AddObserver(IObserver*Observer);
	void CHtmlWnd::RemoveObserver(IObserver*Observer);
	CHtmlComponentWnd* pHtmlComponentMain;
	CButtonWnd* pBackBtn;
	CButtonWnd* pForwardBtn;
	CGaugeWnd* pProgressGauge;
	CLabelWnd* pStatusLabel;
	CXStr*WindowID;
};

class CWebManager
{
public:
EQLIB_OBJECT CHtmlWnd* CWebManager::CreateHtmlWnd(const char*Url, const char* IDString, const char* PostString= NULL, bool bBypasFilter = false, const char*OverrideTitle = NULL);
};

class CXFileXML
{
public:
EQLIB_OBJECT CXFileXML::~CXFileXML();
EQLIB_OBJECT bool CXFileXML::Load(char*);
};

class CXMLData
{
public:
EQLIB_OBJECT CXMLData::CXMLData();
EQLIB_OBJECT class CXMLData & CXMLData::operator=(class CXMLData const &);
// virtual
EQLIB_OBJECT CXMLData::~CXMLData();
EQLIB_OBJECT bool CXMLData::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CXMLData::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CXMLData::GetStreamSize();
//EQLIB_OBJECT void* CXMLData::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CXMLData::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CXMLData::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CXMLData::WriteToStream(class CMemoryStream &);
// data members
/*0x00*/ PVOID pvfTable;
/*0x04*/ DWORD Unknown0x04;// always 8
/*0x08*/ enum UIType Type;
/*0x0C*/ DWORD Unknown0x0C;// no idea yet, some number but not unique
/*0x10*/ DWORD Unknown0x10;// always -1
/*0x14*/ CXStr TypeName;// "Screen" (control type)
/*0x18*/ CXStr Name;// "ChatWindow"  control name (used only for Screen)
/*0x1C*/ DWORD Unknown0x1C;// always null
/*0x20*/ CXStr ScreenID;// ScreenID (used only within Screen)
};

class CXMLDataClass
{
public:
EQLIB_OBJECT CXMLDataClass::~CXMLDataClass();
EQLIB_OBJECT CXMLDataClass::CXMLDataClass();
EQLIB_OBJECT int CXMLDataClass::GetNumLeaf();
EQLIB_OBJECT int CXMLDataClass::GetStreamSize();
//EQLIB_OBJECT void* CXMLDataClass::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CXMLDataClass::ReadFromStream(class CMemoryStream &, class CXMLDataManager &);
EQLIB_OBJECT void CXMLDataClass::WriteToStream(class CMemoryStream &);
};

class CXMLDataPtr
{
public:
EQLIB_OBJECT CXMLDataPtr::CXMLDataPtr();
EQLIB_OBJECT class CXMLDataPtr & CXMLDataPtr::operator=(class CXMLDataPtr const &);
EQLIB_OBJECT void CXMLDataPtr::SetNewPtr(class CXMLData*);
// virtual
EQLIB_OBJECT CXMLDataPtr::~CXMLDataPtr();
//EQLIB_OBJECT void* CXMLDataPtr::`vector deleting destructor'(unsigned int);
// protected
EQLIB_OBJECT class CXMLData* CXMLDataPtr::AllocPtr(class CXMLDataPtr &, int, class CXMLData const*);
EQLIB_OBJECT void CXMLDataPtr::Free();
};

class CXMLEnumInfo
{
public:
EQLIB_OBJECT CXMLEnumInfo::~CXMLEnumInfo();
EQLIB_OBJECT CXMLEnumInfo::CXMLEnumInfo();
EQLIB_OBJECT int CXMLEnumInfo::GetStreamSize();
EQLIB_OBJECT void CXMLEnumInfo::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CXMLEnumInfo::WriteToStream(class CMemoryStream &);
};

class CXMLSOMAttribute
{
public:
EQLIB_OBJECT CXMLSOMAttribute::~CXMLSOMAttribute();
EQLIB_OBJECT CXMLSOMAttribute::CXMLSOMAttribute();
EQLIB_OBJECT class CXMLSOMAttribute & CXMLSOMAttribute::operator=(class CXMLSOMAttribute const &);
//EQLIB_OBJECT void* CXMLSOMAttribute::`vector deleting destructor'(unsigned int);
};

class CXMLSOMAttributeType
{
public:
EQLIB_OBJECT CXMLSOMAttributeType::~CXMLSOMAttributeType();
EQLIB_OBJECT CXMLSOMAttributeType::CXMLSOMAttributeType();
EQLIB_OBJECT class CXMLSOMAttributeType & CXMLSOMAttributeType::operator=(class CXMLSOMAttributeType const &);
//EQLIB_OBJECT void* CXMLSOMAttributeType::`vector deleting destructor'(unsigned int);
};

class CXMLSOMCursor
{
public:
EQLIB_OBJECT CXMLSOMCursor::~CXMLSOMCursor();
EQLIB_OBJECT CXMLSOMCursor::CXMLSOMCursor();
EQLIB_OBJECT class CXMLSOMCursor & CXMLSOMCursor::operator=(class CXMLSOMCursor const &);
//EQLIB_OBJECT void* CXMLSOMCursor::`vector deleting destructor'(unsigned int);
};

class CXMLSOMCursorSave
{
public:
EQLIB_OBJECT CXMLSOMCursorSave::~CXMLSOMCursorSave();
};

class CXMLSOMCursorSaveFast
{
public:
EQLIB_OBJECT CXMLSOMCursorSaveFast::~CXMLSOMCursorSaveFast();
};

class CXMLSOMCursorTraverseChildren
{
public:
EQLIB_OBJECT CXMLSOMCursorTraverseChildren::~CXMLSOMCursorTraverseChildren();
EQLIB_OBJECT class CXMLSOMCursor & CXMLSOMCursorTraverseChildren::Cursor();
};

class CXMLSOMDocument
{
public:
EQLIB_OBJECT bool CXMLSOMDocument::FieldParseItemOfClass(class CXStr, class CXStr, uint32_t &);
EQLIB_OBJECT bool CXMLSOMDocument::GetValueObjectId(class CXStr, class CXStr, uint32_t &);
EQLIB_OBJECT bool CXMLSOMDocument::SetValueObjectId(class CXStr, class CXStr, uint32_t);
// virtual
EQLIB_OBJECT CXMLSOMDocument::~CXMLSOMDocument();
//EQLIB_OBJECT void* CXMLSOMDocument::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CXMLSOMDocument::`vector deleting destructor'(unsigned int);
};

class CXMLSOMDocumentBase
{
public:
EQLIB_OBJECT bool CXMLSOMDocumentBase::CursorFieldFind(class CXStr);
EQLIB_OBJECT bool CXMLSOMDocumentBase::CursorFind(class CXStr);
EQLIB_OBJECT bool CXMLSOMDocumentBase::CursorNextInOrder();
EQLIB_OBJECT bool CXMLSOMDocumentBase::CursorNextSibling();
EQLIB_OBJECT bool CXMLSOMDocumentBase::CursorPop();
EQLIB_OBJECT bool CXMLSOMDocumentBase::CursorPush();
EQLIB_OBJECT bool CXMLSOMDocumentBase::FieldParseClassItem(class CXStr, class CXStr &, class CXStr &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::FieldParseItemOfClass(class CXStr, class CXStr, int32_t &, int32_t &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::GetAttrValueInt(class CXStr, int32_t &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::GetAttrValueStr(class CXStr, class CXStr &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::GetValue(class CXStr, int32_t &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::GetValue(class CXStr, bool &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::GetValue(class CXStr, class CXStr &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::SetValue(class CXStr, int32_t);
EQLIB_OBJECT bool CXMLSOMDocumentBase::SetValue(class CXStr, bool);
EQLIB_OBJECT bool CXMLSOMDocumentBase::SetValue(class CXStr, class CXStr);
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateData();
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchema();
EQLIB_OBJECT bool CXMLSOMDocumentBase::XMLMerge(class CXMLSOMDocumentBase &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::XMLRead(class CXStr*, class CXStr*, class CXStr*);
EQLIB_OBJECT class CXMLSOMCursor & CXMLSOMDocumentBase::Cursor();
EQLIB_OBJECT class CXMLSOMCursor & CXMLSOMDocumentBase::CursorParent();
EQLIB_OBJECT class CXStr CXMLSOMDocumentBase::GetAttrValueStr(class CXStr);
EQLIB_OBJECT class CXStr CXMLSOMDocumentBase::GetErrorMsg() const;
EQLIB_OBJECT int CXMLSOMDocumentBase::XMLReadNoValidate(class CXStr, class CXStr, class CXStr);
EQLIB_OBJECT void CXMLSOMDocumentBase::CursorInit();
EQLIB_OBJECT void CXMLSOMDocumentBase::CursorNewChild();
EQLIB_OBJECT void CXMLSOMDocumentBase::CursorNewSibling();
EQLIB_OBJECT void CXMLSOMDocumentBase::CursorSetPtr(class CXMLSOMNodePtr);
EQLIB_OBJECT void CXMLSOMDocumentBase::Init();
EQLIB_OBJECT void CXMLSOMDocumentBase::SetErrorMsg(class CXStr);
EQLIB_OBJECT void CXMLSOMDocumentBase::SetErrorMsgAtCursor(class CXStr);
EQLIB_OBJECT void CXMLSOMDocumentBase::SetErrorMsgAtLine(class CXStr, int, class CXStr);
// virtual
EQLIB_OBJECT CXMLSOMDocumentBase::~CXMLSOMDocumentBase();
//EQLIB_OBJECT void* CXMLSOMDocumentBase::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CXMLSOMDocumentBase::`vector deleting destructor'(unsigned int);
// protected
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateDataElements(class CXMLSOMElementType &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchemaCategories();
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchemaDefinition();
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchemaElementType();
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchemaSimpleType();
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchemaSimpleTypeNode(class CXMLSOMSimpleType &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchemaTypeRefs();
EQLIB_OBJECT bool CXMLSOMDocumentBase::XMLProcessComposite(class CXStr, class CXStr);
};

class CXMLSOMElement
{
public:
EQLIB_OBJECT CXMLSOMElement::~CXMLSOMElement();
EQLIB_OBJECT CXMLSOMElement::CXMLSOMElement();
EQLIB_OBJECT class CXMLSOMElement & CXMLSOMElement::operator=(class CXMLSOMElement const &);
//EQLIB_OBJECT void* CXMLSOMElement::`vector deleting destructor'(unsigned int);
};

class CXMLSOMElementType
{
public:
EQLIB_OBJECT CXMLSOMElementType::~CXMLSOMElementType();
EQLIB_OBJECT CXMLSOMElementType::CXMLSOMElementType();
EQLIB_OBJECT int CXMLSOMElementType::GetItemIdx(class CXStr);
//EQLIB_OBJECT void* CXMLSOMElementType::`vector deleting destructor'(unsigned int);
};

class CXMLSOMNode
{
public:
EQLIB_OBJECT static void* __cdecl CXMLSOMNode::operator new(unsigned int);
EQLIB_OBJECT static void __cdecl CXMLSOMNode::FreeAllAllocs();
EQLIB_OBJECT static void __cdecl CXMLSOMNode::operator delete(void*);
// protected
EQLIB_OBJECT static char** CXMLSOMNode::pAllAlloc;
EQLIB_OBJECT static class CMutexSync CXMLSOMNode::mutexAccess;
EQLIB_OBJECT static class CXMLSOMNode* CXMLSOMNode::pFreeHead;
// private
EQLIB_OBJECT CXMLSOMNode::~CXMLSOMNode();
EQLIB_OBJECT CXMLSOMNode::CXMLSOMNode();
//EQLIB_OBJECT void* CXMLSOMNode::`scalar deleting destructor'(unsigned int);
};

class CXMLSOMNodePtr
{
public:
EQLIB_OBJECT CXMLSOMNodePtr::~CXMLSOMNodePtr();
EQLIB_OBJECT CXMLSOMNodePtr::CXMLSOMNodePtr();
EQLIB_OBJECT class CXMLSOMNode* CXMLSOMNodePtr::operator->() const;
EQLIB_OBJECT class CXMLSOMNodePtr & CXMLSOMNodePtr::operator=(class CXMLSOMNodePtr const &);
//EQLIB_OBJECT void* CXMLSOMNodePtr::`vector deleting destructor'(unsigned int);
// protected
EQLIB_OBJECT void CXMLSOMNodePtr::Assure() const;
};

class CXMLSOMParser
{
public:
EQLIB_OBJECT CXMLSOMParser::~CXMLSOMParser();
EQLIB_OBJECT bool CXMLSOMParser::ParseFile(class CXStr);
// protected
EQLIB_OBJECT bool CXMLSOMParser::ParseDocument();
EQLIB_OBJECT bool CXMLSOMParser::ParseEndTag(class CXStr);
EQLIB_OBJECT bool CXMLSOMParser::ParseNameSpaceToken(class CXStr &);
EQLIB_OBJECT bool CXMLSOMParser::ParseNode();
EQLIB_OBJECT bool CXMLSOMParser::ParseNodeList();
EQLIB_OBJECT bool CXMLSOMParser::ParseProcess();
EQLIB_OBJECT bool CXMLSOMParser::ParseStartTag(bool &);
};

class CXMLSOMSchema
{
public:
EQLIB_OBJECT CXMLSOMSchema::~CXMLSOMSchema();
EQLIB_OBJECT CXMLSOMSchema::CXMLSOMSchema();
EQLIB_OBJECT bool CXMLSOMSchema::AddItem(class CXStr, class CXStr);
EQLIB_OBJECT bool CXMLSOMSchema::FindElementType(class CXStr);
EQLIB_OBJECT bool CXMLSOMSchema::FindItem(class CXStr, class CXStr);
EQLIB_OBJECT bool CXMLSOMSchema::FindSimpleType(class CXStr);
EQLIB_OBJECT bool CXMLSOMSchema::IsDerivedFrom(class CXStr, class CXStr);
EQLIB_OBJECT int CXMLSOMSchema::GetElementTypeIdx(class CXStr);
};

class CXMLSOMSimpleType
{
public:
EQLIB_OBJECT CXMLSOMSimpleType::~CXMLSOMSimpleType();
EQLIB_OBJECT CXMLSOMSimpleType::CXMLSOMSimpleType();
//EQLIB_OBJECT void* CXMLSOMSimpleType::`vector deleting destructor'(unsigned int);
};

class CXPoint
{
public:
EQLIB_OBJECT class CXPoint CXPoint::operator=(class CXPoint);
DWORD X, Y;
};

class CXRect
{
public:
EQLIB_OBJECT CXRect::CXRect(int nLeft, int nTop, int nRight, int nBottom)
{
    left=nLeft;
    top=nTop;
    right=nRight;
    bottom=nBottom;
}
EQLIB_OBJECT CXRect::CXRect() {};
EQLIB_OBJECT class CXPoint CXRect::CenterPoint() const;
EQLIB_OBJECT class CXRect & CXRect::operator=(class CXRect const &);
EQLIB_OBJECT class CXRect CXRect::operator&(class CXRect) const;
EQLIB_OBJECT class CXRect CXRect::operator|(class CXRect) const;
EQLIB_OBJECT int CXRect::Width() const;
EQLIB_OBJECT void CXRect::Move(class CXPoint);
EQLIB_OBJECT void CXRect::Normalize();
DWORD left, top, right, bottom;
};

class CXStrSingleton
{
public:
EQLIB_OBJECT static int CXStrSingleton::active;
};

class CXWndDrawTemplate
{
public:
EQLIB_OBJECT CXWndDrawTemplate::~CXWndDrawTemplate();
EQLIB_OBJECT CXWndDrawTemplate::CXWndDrawTemplate(class CXWndDrawTemplate const &);
EQLIB_OBJECT CXWndDrawTemplate::CXWndDrawTemplate();
EQLIB_OBJECT class CXWndDrawTemplate & CXWndDrawTemplate::operator=(class CXWndDrawTemplate const &);
};

class CXWndManager
{
public:
EQLIB_OBJECT CXWndManager::CXWndManager(class CSidlManager*);
EQLIB_OBJECT bool CXWndManager::IsAllValid();
EQLIB_OBJECT bool CXWndManager::IsWindowActive(class CXWnd const*) const;
EQLIB_OBJECT bool CXWndManager::IsWindowMovingOrSizing(class CXWnd*) const;
EQLIB_OBJECT bool CXWndManager::IsWindowPieceDown(class CXWnd const*, int) const;
EQLIB_OBJECT bool CXWndManager::OkayToSendMouseMessage(class CXWnd*) const;
EQLIB_OBJECT class CTextureAnimation const* CXWndManager::GetCursorToDisplay() const;
//EQLIB_OBJECT class CTextureFont* CXWndManager::GetFont(class CXStr);
EQLIB_OBJECT class CXWnd* CXWndManager::FindWnd(class CXPoint, int*) const;
EQLIB_OBJECT class CXWnd* CXWndManager::GetFirstChildWnd(class CXWnd const*) const;
EQLIB_OBJECT class CXWnd* CXWndManager::GetFocusWnd() const;
EQLIB_OBJECT class CXWnd* CXWndManager::GetNextSib(class CXWnd const*) const;
EQLIB_OBJECT class CXWnd* CXWndManager::SetFocusWnd(class CXWnd*);
EQLIB_OBJECT int CXWndManager::ActivateWnd(class CXWnd*);
EQLIB_OBJECT int CXWndManager::AddFont(class CTextureFont*);
EQLIB_OBJECT int CXWndManager::AddWnd(class CXWnd*);
EQLIB_OBJECT int CXWndManager::DrawCursor() const;
EQLIB_OBJECT int CXWndManager::DrawWindows() const;
EQLIB_OBJECT int CXWndManager::HandleKeyboardMsg(uint32_t, bool);
EQLIB_OBJECT int CXWndManager::HandleLButtonDown(class CXPoint);
EQLIB_OBJECT int CXWndManager::HandleLButtonHeld(class CXPoint);
EQLIB_OBJECT int CXWndManager::HandleLButtonUp(class CXPoint);
EQLIB_OBJECT int CXWndManager::HandleLButtonUpAfterHeld(class CXPoint);
EQLIB_OBJECT int CXWndManager::HandleMouseMove(class CXPoint);
EQLIB_OBJECT int CXWndManager::HandleRButtonDown(class CXPoint);
EQLIB_OBJECT int CXWndManager::HandleRButtonHeld(class CXPoint);
EQLIB_OBJECT int CXWndManager::HandleRButtonUp(class CXPoint);
EQLIB_OBJECT int CXWndManager::HandleRButtonUpAfterHeld(class CXPoint);
EQLIB_OBJECT int CXWndManager::HandleWheelMove(int);
EQLIB_OBJECT int CXWndManager::NotifyAllWindows(class CXWnd*, uint32_t, void*);
EQLIB_OBJECT int CXWndManager::OnWindowCloseBox(class CXWnd*);
EQLIB_OBJECT int CXWndManager::OnWindowMinimizeBox(class CXWnd*);
EQLIB_OBJECT int CXWndManager::OnWindowTileBox(class CXWnd*);
EQLIB_OBJECT int CXWndManager::ProcessFrame();
EQLIB_OBJECT int CXWndManager::RemoveWnd(class CXWnd*);
EQLIB_OBJECT static class CTextureAnimation CXWndManager::sm_curDefault;
EQLIB_OBJECT static class CTextureAnimation CXWndManager::sm_curDrag;
EQLIB_OBJECT static class CTextureAnimation CXWndManager::sm_curResizeEW;
EQLIB_OBJECT static class CTextureAnimation CXWndManager::sm_curResizeNESW;
EQLIB_OBJECT static class CTextureAnimation CXWndManager::sm_curResizeNS;
EQLIB_OBJECT static class CTextureAnimation CXWndManager::sm_curResizeNWSE;
EQLIB_OBJECT uint32_t CXWndManager::GetDisplayWidth() const;
EQLIB_OBJECT uint32_t CXWndManager::GetGlobalFadeDuration() const;
EQLIB_OBJECT uint32_t CXWndManager::GetKeyboardFlags() const;
EQLIB_OBJECT unsigned char CXWndManager::GetGlobalAlpha() const;
EQLIB_OBJECT unsigned char CXWndManager::GetGlobalFadeToAlpha() const;
EQLIB_OBJECT unsigned long CXWndManager::GetGlobalFadeDelay() const;
EQLIB_OBJECT void CXWndManager::BringWndToTop(class CXWnd*, bool);
EQLIB_OBJECT void CXWndManager::CheckInvalidateLastFoundWnd();
EQLIB_OBJECT void CXWndManager::CleanupWindows();
EQLIB_OBJECT void CXWndManager::DestroyAllWindows();
EQLIB_OBJECT void CXWndManager::FlushKeyboardFlags();
EQLIB_OBJECT void CXWndManager::OnWindowShown(class CXWnd*, bool);
EQLIB_OBJECT void CXWndManager::SetGlobalAlpha(unsigned char);
EQLIB_OBJECT void CXWndManager::SetGlobalFadeDelay(unsigned long);
EQLIB_OBJECT void CXWndManager::SetGlobalFadeDuration(uint32_t);
EQLIB_OBJECT void CXWndManager::SetGlobalFadeToAlpha(unsigned char);
EQLIB_OBJECT void CXWndManager::SetSystemFont(class CTextureFont*);
EQLIB_OBJECT void CXWndManager::UpdateChildAndSiblingInfo();
// virtual
EQLIB_OBJECT CXWndManager::~CXWndManager();
EQLIB_OBJECT class CTextureFont*GetFont(int FontIndex) const {
	if (PCXWNDMGR wndmgr = (PCXWNDMGR)this) {
		if (wndmgr->FontsArray.Count >= FontIndex) {
			return (CTextureFont*)wndmgr->FontsArray[FontIndex];
		}
	}
	return 0;
}
EQLIB_OBJECT int CXWndManager::DestroyWnd(CXWnd*wnd);
//EQLIB_OBJECT void* CXWndManager::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* CXWndManager::`vector deleting destructor'(unsigned int);
};

class EmitterManager
{
public:
EQLIB_OBJECT EmitterManager::~EmitterManager();
EQLIB_OBJECT EmitterManager::EmitterManager(class SoundManager*);
EQLIB_OBJECT float EmitterManager::GetEffectsLevel();
EQLIB_OBJECT float EmitterManager::GetVolumeLevel();
EQLIB_OBJECT void EmitterManager::Add(class SoundEmitter*);
EQLIB_OBJECT void EmitterManager::GetListenerLocation(float*, float*, float*, float*);
EQLIB_OBJECT void EmitterManager::GiveTime();
EQLIB_OBJECT void EmitterManager::Remove(class SoundEmitter*);
EQLIB_OBJECT void EmitterManager::SetEffectsLevel(float);
EQLIB_OBJECT void EmitterManager::SetVolumeLevel(float);
};

class engineInterface
{
public:
EQLIB_OBJECT static class engineInterface* __cdecl engineInterface::get();
EQLIB_OBJECT unsigned long* engineInterface::ChangeDag(struct T3D_tagWORLD*, struct T3D_DAG*, char*);
// private
EQLIB_OBJECT engineInterface::engineInterface();
EQLIB_OBJECT static class engineInterface* engineInterface::mSelf;
};
typedef struct _SlotData {
	LONG Slot;
	DWORD Value;
} SlotData;
class EQ_Affect
{
public:
EQLIB_OBJECT void EQ_Affect::Reset();
EQLIB_OBJECT int EQ_Affect::GetAffectData(int) const;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x00*/	BYTE Type;
/*0x01*/	BYTE CasterLevel;
/*0x02*/	BYTE ChargesRemaining;
/*0x03*/	BYTE Activatable;
/*0x04*/	float BaseDmgMod;
/*0x08*/	int ID;
/*0x0c*/	int DurationTick;
/*0x10*/	int MaxDuration;
/*0x14*/	int Duration3;
/*0x18*/	EqGuid CasterGuid;
/*0x20*/	int HitCounter;
/*0x24*/	float HitLocationY;
/*0x28*/	float HitLocationX;
/*0x2c*/	float HitLocationZ;
/*0x30*/	UINT Flags;//twincast
/*0x34*/	SlotData Data[NUM_SLOTDATA];
/*0x64*/	DWORD Unknown0x64;
/*0x68*/
#else
/*0x00*/	BYTE Type;
/*0x01*/	BYTE CasterLevel;
/*0x02*/	BYTE ChargesRemaining;
/*0x03*/	BYTE Activatable;
/*0x04*/	float BaseDmgMod;
/*0x08*/	int ID;
/*0x0c*/	int DurationTick;
/*0x10*/	int CasterID;
/*0x14*/	int HitCounter;
/*0x18*/	float HitLocationY;
/*0x1c*/	float HitLocationX;
/*0x20*/	float HitLocationZ;
/*0x24*/	UINT Flags;//twincast
/*0x28*/	SlotData Data[NUM_SLOTDATA];
/*0x58*/
#endif
};

class EQ_AltAbility
{
public:
EQLIB_OBJECT EQ_AltAbility::EQ_AltAbility(int);
};

class EQ_Character1
{
public:
EQLIB_OBJECT int EQ_Character1::GetEnduranceRegen(bool bIncItemsAndBuffs, bool bCombat);
EQLIB_OBJECT int EQ_Character1::GetHPRegen(bool bIncItemsAndBuffs, bool*bIsBleeding/*no you shouldnt set this, its an OUT value.*/, bool bCombat);
EQLIB_OBJECT int EQ_Character1::GetManaRegen(bool bIncItemsAndBuffs, bool bCombat);
EQLIB_OBJECT int EQ_Character1::Cur_HP(int Spawntype/*PC = 0 NPC=1 and so on*/, bool bCapAtMax=true);
EQLIB_OBJECT int EQ_Character1::Max_Endurance(bool bCapAtMax=true);
EQLIB_OBJECT int EQ_Character1::Max_HP(int SpawnType, bool bCapAtMax=true); 
EQLIB_OBJECT int EQ_Character1::Max_Mana(bool bCapAtMax=true);
EQLIB_OBJECT const int EQ_Character1::GetCastingTimeModifier(const EQ_Spell* pSpell);//used to get aa modifiers
EQLIB_OBJECT const int EQ_Character1::GetFocusCastingTimeModifier(const EQ_Spell*pSpell, VePointer<CONTENTS>&pItemOut, bool bEvalOnly = false);
//EQLIB_OBJECT int const EQ_Character1::GetFocusCastingTimeModifier(class EQ_Spell const*, class EQ_Equipment**, int);
EQLIB_OBJECT unsigned char EQ_Character1::CastSpell(unsigned char gemid, int spellid, class EQ_Item**ppItem, class CEQItemLocation* ppitemloc, enum  ItemSpellTypes slot, unsigned char spell_loc, int arg7, int arg8, int arg9, bool arg10); 
EQLIB_OBJECT void EQ_Character1::SetEffectId(unsigned char, unsigned int);
EQLIB_OBJECT void EQ_Character1::StopSpellCast(unsigned char);
EQLIB_OBJECT void EQ_Character1::StopSpellCast(unsigned char, int);
EQLIB_OBJECT void EQ_Character1::StunMe(unsigned int, bool, bool, bool);
EQLIB_OBJECT void EQ_Character1::UnStunMe();
#if defined(ROF2EMU) || defined(UFEMU)
EQLIB_OBJECT void EQ_Character1::UseSkill(unsigned char skill, class EQPlayer*Target);
#else
EQLIB_OBJECT void EQ_Character1::UseSkill(unsigned char skill, class EQPlayer*Target, bool bAuto = false);
#endif
EQLIB_OBJECT const int EQ_Character1::GetFocusRangeModifier(const EQ_Spell*pSpell, VePointer<CONTENTS>&pItemOut);
EQLIB_OBJECT int EQ_Character1::IsExpansionFlag(int);
EQLIB_OBJECT int EQ_Character1::TotalEffect(int spaID, bool bIncludeItems = true, int subindex = 0, bool bIncludeAA = true, bool bincludeBuffs = true);
EQLIB_OBJECT int EQ_Character1::GetAdjustedSkill(int);
EQLIB_OBJECT int EQ_Character1::GetBaseSkill(int);
EQLIB_OBJECT bool EQ_Character1::CanUseItem(PCONTENTS*pItem, bool bUseRequiredLvl, bool bOutput);
};

class EQ_Character
{
public:
EQLIB_OBJECT EQ_Character::~EQ_Character();
EQLIB_OBJECT EQ_Character::EQ_Character();
EQLIB_OBJECT bool EQ_Character::DoesSpellMatchFocusFilters(class EQ_Spell const*, class EQ_Spell const*);
EQLIB_OBJECT bool EQ_Character::IsSpellTooPowerfull(class EQ_Spell*, class EQ_Character*);
EQLIB_OBJECT bool EQ_Character::CanUseMemorizedSpellSlot(int gem);
EQLIB_OBJECT bool EQ_Character::IsValidAffect(int);
EQLIB_OBJECT char* EQ_Character::Class(int);
EQLIB_OBJECT char* EQ_Character::KunarkClass(int, int, int, bool);
EQLIB_OBJECT char* EQ_Character::Race(int);
EQLIB_OBJECT class EQ_Affect & EQ_Character::GetEffect(int);
EQLIB_OBJECT class EQ_Affect* EQ_Character::GetPCSpellAffect(int theaffect, int*slotnum, int*spaslot = NULL) const;
EQLIB_OBJECT class EQ_Equipment* EQ_Character::GetFocusItem(class EQ_Spell const*, int);
EQLIB_OBJECT class EQ_Spell* EQ_Character::GetFocusEffect(class EQ_Spell const*, int);
EQLIB_OBJECT class EQPlayer* EQ_Character::FindClosest(int, int, int, int, int);
EQLIB_OBJECT class EQPlayer* EQ_Character::GetMyPetPlayer();
EQLIB_OBJECT float EQ_Character::encum_factor();
EQLIB_OBJECT int EQ_Character::ac(bool);
EQLIB_OBJECT int EQ_Character::Agi();
EQLIB_OBJECT int EQ_Character::AntiTwinkAdj(class EQ_Equipment*, int, int);
EQLIB_OBJECT int EQ_Character::ApplyDamage(int, struct _EQMissileHitinfo*, bool, class HateListEntry*, bool);
EQLIB_OBJECT int EQ_Character::ApplyFatigue(int);
EQLIB_OBJECT int EQ_Character::AutoEat(unsigned char);
EQLIB_OBJECT int EQ_Character::BaneDamage(class EQ_Equipment*);
EQLIB_OBJECT int EQ_Character::BardCastBard(class EQ_Spell const*, int) const;
EQLIB_OBJECT int EQ_Character::basesave_cold();
EQLIB_OBJECT int EQ_Character::basesave_disease();
EQLIB_OBJECT int EQ_Character::basesave_fire();
EQLIB_OBJECT int EQ_Character::basesave_magic();
EQLIB_OBJECT int EQ_Character::basesave_poison();
EQLIB_OBJECT int EQ_Character::CalculateBardSongMod(int);
EQLIB_OBJECT int EQ_Character::CapStat(int, int);
EQLIB_OBJECT int EQ_Character::Cha();
EQLIB_OBJECT int EQ_Character::CheckFoodAndWater();
EQLIB_OBJECT int EQ_Character::compute_defense();
EQLIB_OBJECT int EQ_Character::compute_tohit(unsigned char);
EQLIB_OBJECT int EQ_Character::cur_encumbrance();
EQLIB_OBJECT int EQ_Character::Cur_Mana(bool bCapAtMax = true);
EQLIB_OBJECT int EQ_Character::defense_agility_bonus();
EQLIB_OBJECT int EQ_Character::Dex();
EQLIB_OBJECT int EQ_Character::ElementResistDmg(class EQ_Equipment*, int);
EQLIB_OBJECT int EQ_Character::eqspa_change_form(class EQ_Spell*, int, int, class EQ_Affect*);
EQLIB_OBJECT int EQ_Character::eqspa_hp(unsigned int, class EQ_Affect*, int, class EQ_Spell*);
EQLIB_OBJECT int EQ_Character::GetBardInstrumentMod(int);
EQLIB_OBJECT int EQ_Character::GetClassACBonus(int);
EQLIB_OBJECT int EQ_Character::GetFirstEffectSlot(bool);
EQLIB_OBJECT int EQ_Character::GetHPFromStamina(int);
EQLIB_OBJECT int EQ_Character::GetIndexSkillMinDamageMod(int);
EQLIB_OBJECT int EQ_Character::GetLastEffectSlot(bool);
EQLIB_OBJECT int EQ_Character::GetOpenEffectSlot(bool, int);
EQLIB_OBJECT int EQ_Character::HasInnateSkill(unsigned char, int);
EQLIB_OBJECT int EQ_Character::HasSkill(unsigned char);
EQLIB_OBJECT int EQ_Character::HasSpell(int);
EQLIB_OBJECT int EQ_Character::IHaveSkill(unsigned char);
EQLIB_OBJECT int EQ_Character::InSpecialBindSpot(class EQPlayer*);
EQLIB_OBJECT int EQ_Character::Int();
EQLIB_OBJECT int EQ_Character::IsMage();
EQLIB_OBJECT int EQ_Character::IsSpecialBazaarSpot(class EQPlayer*);
EQLIB_OBJECT int EQ_Character::IsSpellcaster();
EQLIB_OBJECT int EQ_Character::ItemSpellAffects(int);
EQLIB_OBJECT int EQ_Character::max_encumbrance();
EQLIB_OBJECT int EQ_Character::NoBashMe(int);
EQLIB_OBJECT int EQ_Character::NoMezMe(int, class EQPlayer*, class EQ_Spell*);
EQLIB_OBJECT int EQ_Character::offense(unsigned char);
EQLIB_OBJECT int EQ_Character::ProcessAffects();
EQLIB_OBJECT int EQ_Character::save_bash(int);
EQLIB_OBJECT int EQ_Character::save_cold();
EQLIB_OBJECT int EQ_Character::save_disease();
EQLIB_OBJECT int EQ_Character::save_fire();
EQLIB_OBJECT int EQ_Character::save_magic();
EQLIB_OBJECT int EQ_Character::save_poison();
EQLIB_OBJECT int EQ_Character::SetLocalVar(char*, int);
EQLIB_OBJECT int EQ_Character::Skill(int);
EQLIB_OBJECT int EQ_Character::SpellDuration(class EQ_Spell const*, unsigned char, unsigned char);
EQLIB_OBJECT int EQ_Character::Sta();
EQLIB_OBJECT int EQ_Character::Str();
EQLIB_OBJECT int EQ_Character::TakeFallDamage(float);
EQLIB_OBJECT int EQ_Character::TotalSpellAffects(unsigned char, bool, int*);
EQLIB_OBJECT int EQ_Character::Wis();
EQLIB_OBJECT int const EQ_Character::GetFocusConserveRegChance(class EQ_Spell const*, class EQ_Equipment**);
EQLIB_OBJECT long EQ_Character::TotalOnPerson();
EQLIB_OBJECT static int __cdecl EQ_Character::normal_to_special(int);
EQLIB_OBJECT unsigned char EQ_Character::BarbarianCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::BaseAttr(int, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::CanDoubleAttack(class EQPlayer*, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::CanIBreathe();
EQLIB_OBJECT unsigned char EQ_Character::CanISeeInvis();
EQLIB_OBJECT unsigned char EQ_Character::CanMedOnHorse();
EQLIB_OBJECT unsigned char EQ_Character::CanSecondaryAttack(class EQPlayer*);
EQLIB_OBJECT unsigned char EQ_Character::CanWorship(int, int, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::CastingRequirementsMet(int);
EQLIB_OBJECT unsigned char EQ_Character::CheckClass(int, int);
EQLIB_OBJECT unsigned char EQ_Character::CityCanStart(int, int, int, int);
EQLIB_OBJECT unsigned char EQ_Character::ClassMin(int, int, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::DarkElfCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::DwarfCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::ElfCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::EruditeCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::ExpendItemCharge(int, int);
EQLIB_OBJECT unsigned char EQ_Character::FindItemByClass(int, int*, int*);
EQLIB_OBJECT unsigned char EQ_Character::FindItemQty(int, int);
EQLIB_OBJECT unsigned char EQ_Character::FroglockCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::GetSkillBaseDamage(unsigned char, class EQPlayer*);
EQLIB_OBJECT unsigned char EQ_Character::GnomeCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::HalfElfCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::HalflingCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::HighElfCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::HumanCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::IksarCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::IsSpellAffectingPC(int, int);
EQLIB_OBJECT unsigned char EQ_Character::LaunchSpell(unsigned char, int, class EQ_Item**);
EQLIB_OBJECT unsigned char EQ_Character::OgreCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::SpellFizzled(unsigned char, class EQ_Spell*);
EQLIB_OBJECT unsigned char EQ_Character::TrollCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::VahShirCanWorship(unsigned char, unsigned char);
EQLIB_OBJECT void EQ_Character::CalcFoodDrinkBonus(int);
EQLIB_OBJECT void EQ_Character::DoFishingEvent();
EQLIB_OBJECT void EQ_Character::DoIntimidationEvent();
EQLIB_OBJECT void EQ_Character::DoLight(unsigned char);
EQLIB_OBJECT void EQ_Character::DoMeditation();
EQLIB_OBJECT void EQ_Character::DoPassageOfTime();
EQLIB_OBJECT void EQ_Character::EQ_CharacterResetAllMembers();
EQLIB_OBJECT void EQ_Character::EQSPA_Feign_Death(int);
EQLIB_OBJECT void EQ_Character::eqspa_levitation();
EQLIB_OBJECT void EQ_Character::eqspa_locate_corpse();
EQLIB_OBJECT void EQ_Character::eqspa_movement_rate(int);
EQLIB_OBJECT void EQ_Character::HandleSpecialPCAffects(int);
EQLIB_OBJECT void EQ_Character::HitBySpell(struct _EQMissileHitinfo*);
EQLIB_OBJECT void EQ_Character::IAmDead(struct _EQMissileHitinfo*, int);
EQLIB_OBJECT void EQ_Character::InitInnates(unsigned int, unsigned int);
EQLIB_OBJECT void EQ_Character::InitMyLanguages();
EQLIB_OBJECT void EQ_Character::InitSkills(unsigned char, unsigned int);
EQLIB_OBJECT void EQ_Character::ItemSold(long);
#if defined(ROF2EMU) || defined(UFEMU)
EQLIB_OBJECT void EQ_Character::ModifyCurHP(int modification, class PlayerZoneClient*resposibleplayer, int skilltype);
#else
EQLIB_OBJECT void EQ_Character::ModifyCurHP(int64_t modification, class PlayerZoneClient*resposibleplayer, int skilltype);
#endif
EQLIB_OBJECT void EQ_Character::NotifyPCAffectChange(int, int);
EQLIB_OBJECT void EQ_Character::ProcessAllStats();
EQLIB_OBJECT void EQ_Character::ProcessEnvironment();
EQLIB_OBJECT void EQ_Character::ProcessHungerandThirst(unsigned int);
EQLIB_OBJECT void EQ_Character::RemovePCAffect(class EQ_Affect*);
EQLIB_OBJECT void EQ_Character::RemovePCAffectex(class EQ_Affect*, int);
EQLIB_OBJECT void EQ_Character::ResetCur_HP(int);
EQLIB_OBJECT void EQ_Character::UpdateMyVisibleStatus();
//confirmed having only 2 parameters (looks like it has 3 but it doesnt) in apr 21 2016 eqgame.exe (live) - eqmule
EQLIB_OBJECT bool EQ_Character::DoCombatAbility(int spellID, int dummy=1);
EQLIB_OBJECT unsigned long EQ_Character::GetConLevel(class EQPlayer*);
// private
EQLIB_OBJECT int EQ_Character::GetCachEQSPA(int);
EQLIB_OBJECT void EQ_Character::ReCachItemEffects();
EQLIB_OBJECT void EQ_Character::ReCachSpellEffects();
};

class EQ_CharacterData
{
public:
EQLIB_OBJECT void EQ_CharacterData::EQ_CharacterDataResetAllMembers();
};

class EQ_Container
{
public:
EQLIB_OBJECT EQ_Container::~EQ_Container();
EQLIB_OBJECT EQ_Container::EQ_Container();
EQLIB_OBJECT unsigned char EQ_Container::Close();
EQLIB_OBJECT unsigned char EQ_Container::IsOpen();
EQLIB_OBJECT unsigned char EQ_Container::Open();
};

class EQ_Equipment
{
public:
EQLIB_OBJECT EQ_Equipment::EQ_Equipment();
EQLIB_OBJECT int EQ_Equipment::IsInstrument();
EQLIB_OBJECT int EQ_Equipment::IsWeapon();
EQLIB_OBJECT void EQ_Equipment::SendTextRequestMsg();
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
//this is really the ItemBase class
//eqmule 2014 feb 06
class EQ_Item
{
public:
EQLIB_OBJECT bool EQ_Item::IsSpecialNoDrop();
EQLIB_OBJECT char* EQ_Item::ValueSBuy(float, long);
EQLIB_OBJECT char* EQ_Item::ValueSRent();
EQLIB_OBJECT char* EQ_Item::ValueSSell(float, long);
EQLIB_OBJECT int EQ_Item::Copper();
EQLIB_OBJECT int EQ_Item::Gold();
EQLIB_OBJECT int EQ_Item::Platinum();
EQLIB_OBJECT int EQ_Item::Silver();
EQLIB_OBJECT long EQ_Item::ValueSellMerchant(float, long) const;
EQLIB_OBJECT bool EQ_Item::IsStackable(); // Valerian 12-20-2004 
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT char* EQ_Item::CreateItemTagString(char*, int, bool bFlag = true); // SwiftyMUSE 11-09-2018
#else
EQLIB_OBJECT char* EQ_Item::CreateItemTagString(char*, int); // Lax 11-14-2003
#endif
EQLIB_OBJECT bool EQ_Item::CanDrop(bool bDisplayText = false, bool bIncludeContainedItems = true, bool bAllowOverrideNoDropCheck = false, bool bCantDropIfContainingRealEstate = true) const;
EQLIB_OBJECT int EQ_Item::GetImageNum() const;
EQLIB_OBJECT struct  _CONTENTS** __cdecl CreateItemClient(PBYTE*, DWORD);
EQLIB_OBJECT int EQ_Item::GetItemValue(bool) const;
EQLIB_OBJECT bool EQ_Item::IsKeyRingItem(KeyRingType type) const;
EQLIB_OBJECT bool EQ_Item::CanGoInBag(PCONTENTS*pCont, int OutputText = 0, bool mustbefalse = false) const;
EQLIB_OBJECT bool EQ_Item::IsEmpty() const;
EQLIB_OBJECT int EQ_Item::GetMaxItemCount() const;
EQLIB_OBJECT int EQ_Item::GetAugmentFitBySlot(PCONTENTS*Aug, int Slot, bool bCheckSlot = true, bool bCheckDup = true) const; 
ITEMINFO Data;
};

class EQ_LoadingS
{
public:
EQLIB_OBJECT EQ_LoadingS::~EQ_LoadingS();
EQLIB_OBJECT EQ_LoadingS::EQ_LoadingS();
EQLIB_OBJECT void EQ_LoadingS::draw();
EQLIB_OBJECT void EQ_LoadingS::DrawBackground(struct T3D_XYZ*);
EQLIB_OBJECT void EQ_LoadingS::SetProgressBar(int, char const*);
EQLIB_OBJECT void EQ_LoadingS::WriteTextHD(char*, int, int, int);
// virtual
EQLIB_OBJECT void EQ_LoadingS::Activate();
EQLIB_OBJECT void EQ_LoadingS::Deactivate();
EQLIB_OBJECT void EQ_LoadingS::DefineImages();
};

class EQ_Note
{
public:
EQLIB_OBJECT EQ_Note::~EQ_Note();
EQLIB_OBJECT EQ_Note::EQ_Note();
EQLIB_OBJECT void EQ_Note::SendTextRequestMsg();
};
struct ItemContainingRealEstate
{
	int RealEstateID;
	ItemGlobalIndex ItemLocation;
};
class EQ_PC
{
public:
EQLIB_OBJECT EQ_PC::~EQ_PC();
EQLIB_OBJECT EQ_PC::EQ_PC(class EQ_PC*);
EQLIB_OBJECT int EQ_PC::BitchCanTrain(int, int, int);
EQLIB_OBJECT int EQ_PC::CheckDupLoreItems();
EQLIB_OBJECT int EQ_PC::checkLang(int);
EQLIB_OBJECT int EQ_PC::CostToTrain(int, float, int);
EQLIB_OBJECT int EQ_PC::DelLoreItemDup(int, int, int, class EQ_Item*);
//EQ_PC::GetAlternateAbilityId checked on May 1 2016 only reason why it looks like it takes 2 args(which it doesnt) is cause it pushes another which is meant for AltAdvManager__GetAAById_x see 43BBB7 in eqgame 21 apr 2016 live for an example.
EQLIB_OBJECT int EQ_PC::GetAlternateAbilityId(int);
EQLIB_OBJECT int EQ_PC::GetArmorType(int);
EQLIB_OBJECT int EQ_PC::GetCombatAbility(int);
EQLIB_OBJECT class PcZoneClient*EQ_PC::GetPcZoneClient() const;
EQLIB_OBJECT int EQ_PC::HandleMoney(long);
EQLIB_OBJECT int EQ_PC::IsAGroupMember(char*);
EQLIB_OBJECT int EQ_PC::MaxAirSupply();
EQLIB_OBJECT int EQ_PC::numInParty();
EQLIB_OBJECT static class EQ_PC* EQ_PC::top;
EQLIB_OBJECT unsigned char EQ_PC::AtSkillLimit(int);
EQLIB_OBJECT unsigned char EQ_PC::RemoveMyAffect(int);
EQLIB_OBJECT class MQItemBaseContainer &EQ_PC::GetKeyRingItems(enum KeyRingType);
EQLIB_OBJECT unsigned long EQ_PC::GetArmorTint(int);
EQLIB_OBJECT unsigned long EQ_PC::GetBodyTint(int);
EQLIB_OBJECT void EQ_PC::CheckForGroupChanges();
EQLIB_OBJECT void EQ_PC::CheckForLanguageImprovement(unsigned char, unsigned char);
EQLIB_OBJECT void EQ_PC::CheckSkillImprove(int, float);
EQLIB_OBJECT void EQ_PC::ClearSharedVault();
EQLIB_OBJECT void EQ_PC::DestroyHeldItemOrMoney();
EQLIB_OBJECT void EQ_PC::DetermineQuestExpGained(int);
EQLIB_OBJECT void EQ_PC::EmptyPossessionSlots();
EQLIB_OBJECT void EQ_PC::InitializeNewPCVariables(int);
EQLIB_OBJECT void EQ_PC::InitPlayerStart(unsigned int, unsigned char, int);
EQLIB_OBJECT void EQ_PC::PrepareForRepop(int);
EQLIB_OBJECT void EQ_PC::ProcessAirSupply();
EQLIB_OBJECT void EQ_PC::ProcessFatigue();
EQLIB_OBJECT void EQ_PC::RefitNewbieEQ();
EQLIB_OBJECT void EQ_PC::RefreshMe(int);
EQLIB_OBJECT void EQ_PC::SetAltAbilityIndex(int, int);
EQLIB_OBJECT void EQ_PC::SetArmorTint(int, unsigned long);
EQLIB_OBJECT void EQ_PC::SetArmorType(int, int);
EQLIB_OBJECT void EQ_PC::SetFatigue(int);
EQLIB_OBJECT void EQ_PC::UnpackMyNetPC(char*, int);
EQLIB_OBJECT void EQ_PC::AlertInventoryChanged();
//EQ_PC::GetCombatAbilityTimer has 2 parameters confirmed apr 21 2016 eqgame.exe (live)
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT unsigned long EQ_PC::GetCombatAbilityTimer(int, int);
EQLIB_OBJECT unsigned long EQ_PC::GetItemRecastTimer(class EQ_Item*item, ItemSpellTypes etype);
#else
EQLIB_OBJECT unsigned long EQ_PC::GetCombatAbilityTimer(int);
EQLIB_OBJECT unsigned long EQ_PC::GetItemRecastTimer(class EQ_Item*item);
#endif
EQLIB_OBJECT bool EQ_PC::HasLoreItem(class EQ_Item*, int, int, int, int);
EQLIB_OBJECT void EQ_PC::GetItemContainedRealEstateIds(ArrayClass<ItemContainingRealEstate> &Out, bool bCurrentProfileOnly = false, bool bIncludeAltStorage = true, bool bIncludeArchived = true);
EQLIB_OBJECT void EQ_PC::GetNonArchivedOwnedRealEstates(ArrayClass<int>& output);

};

class ProfileManager
{
public:
EQLIB_OBJECT BaseProfile* ProfileManager::GetCurrentProfile();

};

class EQ_Skill
{
public:
EQLIB_OBJECT EQ_Skill::~EQ_Skill();
EQLIB_OBJECT EQ_Skill::EQ_Skill(int);
};

class EQ_Spell
{
public:
EQLIB_OBJECT EQ_Spell::~EQ_Spell();
EQLIB_OBJECT EQ_Spell::EQ_Spell(char*);
EQLIB_OBJECT bool EQ_Spell::IsStackableDot() const;
EQLIB_OBJECT bool EQ_Spell::IsStackable() const;
EQLIB_OBJECT int EQ_Spell::IsPermIllusionSpell() const;
EQLIB_OBJECT int EQ_Spell::SpellUsesDragonBreathEffect();
EQLIB_OBJECT unsigned char EQ_Spell::SpellAffects(int) const;//this one takes an attrib(soe calls it affect) and returns the index for it...
EQLIB_OBJECT unsigned char EQ_Spell::GetSpellLevelNeeded(int) const;//takes a Class, druid for example is 6
EQLIB_OBJECT int EQ_Spell::SpellAffectBase(int) const;//takes a SPA, returns the first matching base it finds for it
EQLIB_OBJECT const PSPELLCALCINFO EQ_Spell::GetSpellAffectBySlot(int Slot) const;
#if !defined(ROF2EMU)
EQLIB_OBJECT const PSPELLCALCINFO EQ_Spell::GetSpellAffectByIndex(int Index) const;
#endif
EQLIB_OBJECT bool EQ_Spell::IsNoRemove() const;
EQLIB_OBJECT static bool EQ_Spell::IsDegeneratingLevelMod(int);

EQLIB_OBJECT static bool EQ_Spell::IsSPAStacking(int Spa);
EQLIB_OBJECT static bool EQ_Spell::IsSPAIgnoredByStacking(int Spa);
inline bool EQ_Spell::IsNoDispell() const
{
	return Data.NoDisspell;
}
inline bool EQ_Spell::IsStackableOnAnyone() const
{
	return SpellAffects(424) != 0;
}
inline int GetNoOverwrite() const
{
	return Data.NoOverwrite;
}
inline bool IsBeneficialSpell() const
{
	return (Data.SpellType >= 1);
}
inline bool IsDetrimentalSpell() const
{
	return (Data.SpellType == 0);
}
inline bool IsShortEffectDuration() const 
{
	return Data.DurationWindow;
}
inline bool GetIsSkillSpell() const
{ 
	return Data.IsSkill;
}
inline bool IsDoTSpell() const
{
	return SpellAffects(0) || SpellAffects(20) || SpellAffects(69) || SpellAffects(114) || SpellAffects(125);
}
SPELL Data;
};
class EQAnimation
{
public:
EQLIB_OBJECT EQAnimation::~EQAnimation();
EQLIB_OBJECT EQAnimation::EQAnimation();
};

class EQEffect
{
public:
EQLIB_OBJECT EQEffect::~EQEffect();
EQLIB_OBJECT EQEffect::EQEffect(class EQEffect*, char*, int, struct _EQLOC*, class EQPlayer*, class EQMissile*, struct _EQRGB*, float, int, int, float, float);
EQLIB_OBJECT static class EQEffect* EQEffect::top;
};

class EqEmitterData
{
public:
EQLIB_OBJECT EqEmitterData::EqEmitterData();
EQLIB_OBJECT void EqEmitterData::SetLoadString(char*);
};

class EQHSprite
{
public:
EQLIB_OBJECT EQHSprite::~EQHSprite();
EQLIB_OBJECT EQHSprite::EQHSprite(char*, struct T3D_tagACTORINSTANCE*, class EQPlayer*);
EQLIB_OBJECT bool EQHSprite::GetAnimationTrackPtr(char*, char*, int, int, unsigned char, int);
EQLIB_OBJECT class EQHSprite* EQHSprite::get_object(char*);
EQLIB_OBJECT static class EQHSprite* EQHSprite::top;
};

class EQItemList
{
public:
EQLIB_OBJECT EQItemList::~EQItemList();
EQLIB_OBJECT EQItemList::EQItemList();
EQLIB_OBJECT class EQItemList* EQItemList::get_item(long);
EQLIB_OBJECT class EQItemList* EQItemList::is_item_actor(struct T3D_tagACTORINSTANCE*);
EQLIB_OBJECT static class EQItemList* EQItemList::top;
};

class EQMissile
{
public:
EQLIB_OBJECT EQMissile::~EQMissile();
EQLIB_OBJECT EQMissile::EQMissile(class EQ_Equipment*, class EQPlayer*, class EQMissile*, char*, unsigned char, unsigned int);
EQLIB_OBJECT class EQMissile* EQMissile::is_missile_actor(struct T3D_tagACTORINSTANCE*);
EQLIB_OBJECT static class EQMissile* EQMissile::top;
EQLIB_OBJECT void EQMissile::CleanUpMyEffects();
EQLIB_OBJECT void EQMissile::HitActor(struct T3D_tagACTORINSTANCE*, bool);
EQLIB_OBJECT void EQMissile::LeaveTrail();
EQLIB_OBJECT void EQMissile::MissileAI();
EQLIB_OBJECT void EQMissile::ProcessMissile();
};

class EqMobileEmitter
{
public:
EQLIB_OBJECT EqMobileEmitter::~EqMobileEmitter();
EQLIB_OBJECT EqMobileEmitter::EqMobileEmitter(class EqSoundManager*);
EQLIB_OBJECT void EqMobileEmitter::Move(float, float, float);
EQLIB_OBJECT void EqMobileEmitter::SetNpcHeight(float);
EQLIB_OBJECT void EqMobileEmitter::SetWave(int, char*);
};

class EQMoneyList
{
public:
EQLIB_OBJECT EQMoneyList::~EQMoneyList();
EQLIB_OBJECT EQMoneyList::EQMoneyList();
EQLIB_OBJECT class EQMoneyList* EQMoneyList::get_money(long);
EQLIB_OBJECT static class EQMoneyList* EQMoneyList::top;
};

class EQNewPlayerAnimation
{
public:
EQLIB_OBJECT static void __cdecl EQNewPlayerAnimation::InitAnimationData();
};

class EQObject
{
public:
EQLIB_OBJECT EQObject::~EQObject();
EQLIB_OBJECT EQObject::EQObject(class EQObject*, class EQPlayer*, char*, char*);
EQLIB_OBJECT static class EQObject* EQObject::top;
};

class EQOldPlayerAnimation
{
public:
EQLIB_OBJECT EQOldPlayerAnimation::EQOldPlayerAnimation(class EQPlayer*);
EQLIB_OBJECT static void __cdecl EQOldPlayerAnimation::InitAnimationData();
// virtual
EQLIB_OBJECT bool EQOldPlayerAnimation::RequestAnimation(unsigned short, bool, bool, float, unsigned char);
EQLIB_OBJECT bool EQOldPlayerAnimation::RequestAnimation(unsigned short, bool, bool, float, unsigned char, unsigned char);
EQLIB_OBJECT int EQOldPlayerAnimation::GetAnimNum(int, int, int, float*, unsigned char);
EQLIB_OBJECT void EQOldPlayerAnimation::InitAnimationTracks(class EQHSprite*, struct T3D_tagACTORINSTANCE*);
EQLIB_OBJECT void EQOldPlayerAnimation::PlayAnimationSound(int);
EQLIB_OBJECT void EQOldPlayerAnimation::ProcessAnimation(bool, bool);
// private
EQLIB_OBJECT bool EQOldPlayerAnimation::AnimationIsAggressive(int);
EQLIB_OBJECT bool EQOldPlayerAnimation::InterruptCurrentAnimation(int, unsigned char);
EQLIB_OBJECT bool EQOldPlayerAnimation::IsIdleAnimation(int);
EQLIB_OBJECT bool EQOldPlayerAnimation::IsSocialAnimation(int);
EQLIB_OBJECT bool EQOldPlayerAnimation::IsStandAnimation(int);
EQLIB_OBJECT static bool* EQOldPlayerAnimation::mAnimAllowsSeparateLower;
EQLIB_OBJECT static bool* EQOldPlayerAnimation::mAnimAllowsSeparateUpper;
EQLIB_OBJECT static bool* EQOldPlayerAnimation::mAnimInterruptable;
EQLIB_OBJECT static char (* EQOldPlayerAnimation::mAnimationPrefix)[20];
EQLIB_OBJECT virtual bool EQOldPlayerAnimation::GetAlternateAnimTag(char*, char*, bool);
EQLIB_OBJECT void EQOldPlayerAnimation::ChangeAttachmentAnimationTrackSpeeds(bool, float);
EQLIB_OBJECT void EQOldPlayerAnimation::PlayAttachmentAnimationTracks(int, int, bool, bool, float, bool, unsigned char);
};
enum ePlacementType
{
	PLACEMENT_TYPE_FLOOR,
	PLACEMENT_TYPE_WALL,
	PLACEMENT_TYPE_CEILING,
};
class EQPlacedItem
{
public:
/*0x00*/ PVOID vftable;
/*0x04*/ EQPlacedItem*pPrev;
/*0x08*/ EQPlacedItem*pNext;
/*0x0c*/ int	RecordNum;
/*0x10*/ EqItemGuid ItemGuid;
/*0x22*/
/*0x24*/ int	RealEstateID;
/*0x28*/ int	RealEstateItemID;
/*0x2C*/ bool	bIsNPC;
/*0x30*/ UINT	PlacingItemNpcID;
/*0x34*/ void*	pLight;//CLightInterface
/*0x38*/ void*	pActor;//CActorInterface
/*0x3c*/ CHAR   Name[0x40];
/*0x7c*/ float  Scale;
/*0x80*/ float  Heading;
/*0x84*/ float  Angle;
/*0x88*/ float  Roll;
/*0x8c*/ float  Y;
/*0x90*/ float  X;
/*0x94*/ float  Z;
/*0x98*/ bool	bIgnoreCollisions;
/*0x98*/ bool	bDisablePlacementRotation;
/*0x98*/ bool	bDisableFreePlacement;
/*0x9c*/ ePlacementType  PlacementType;
/*0xa0*/ float  ScaleRangeMin;
/*0xa4*/ float  ScaleRangeMax;
/*0xa8*/ float  DefaultScale;
/*0xac*/ float  DefaultHeading;
/*0xb0*/ float  DefaultAngle;
/*0xb4*/ float  DefaultRoll;
/*0xb8*/ int	LightType;
/*0xbc*/ float  NPCHeight;
/*0xC0*/
};

class EQPlacedItemManager
{ 
public:
EQLIB_OBJECT static EQPlacedItemManager& Instance();
EQLIB_OBJECT EQPlacedItem* GetItemByGuid(const EqItemGuid& ItemGuid);
EQLIB_OBJECT EQPlacedItem* GetItemByRealEstateAndRealEstateItemIds(int RealEstateID, int RealEstateItemID);

	EQPlacedItem*Top;
};
class RealEstateItemIds
{
public:
	int RealEstateID;
	int RealEstateItemID;
};
class RealEstateItemState
{
public:
	bool		bPlaced;
	__time32_t	UpkeepExpiredTime;
};
class RealEstateItemPosition
{
public:
	float Heading;
	float Pitch;
	float Roll;
	float Scale;
	float X;
	float Y;
	float Z;
};
class RealEstateItemOwnerInfo
{
public:
	PCXSTR	OwnerName;
	PCXSTR	OwnerHandle;
	int		OwnerNameHashKey;
};
class RealEstateItemObject
{
public:
	VePointer<CONTENTS> pItemBase;
};
class RealEstateItem
{
public:
	RealEstateItemState		State;
	RealEstateItemPosition	Position;
	RealEstateItemOwnerInfo	OwnerInfo;
	RealEstateItemObject	Object;
};
class RealEstateItemClient : public RealEstateItem
{
public:
	RealEstateItemIds IDs;
};
enum eRealEstateType
{
	RET_None = 0,
	RET_Zone = 1,
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
class RealEstateManagerClient
{
public:
/*0x00*/ PVOID vftable;
/*0x04*/ BYTE Stuff[0xb4];
/*0xb8*/ UINT lastRefreshTime;
/*0xbc*/ int ZoneRealEstateId;
/*0xc0*/ eRealEstateType ZoneRealEstateType;
/*0xc4*/ int CurrentRealEstateID;
/*0xc8*/ int CurrentYardID;
/*0xcc*/ int CurrentHouseID;
/*0xa0*/ int CurrentMovingCrateID;
/*0xa4*/ bool bRequestPending;
/*0xa8*/ UINT RequestTime;
/*0xac*/ bool bPrintRequestTimes;
	static RealEstateManagerClient &RealEstateManagerClient::Instance();
	const RealEstateItemClient* GetItemByRealEstateAndItemIds( int RealEstateID, int RealEstateItemID ) const;
};

class FactionManagerClient
{
public:
/*0x00*/ PVOID vftable;
/*0x04*/ //todo: map it
	static FactionManagerClient &FactionManagerClient::Instance();
	void FactionManagerClient::HandleFactionMessage(UINT MessageID, PCHAR pData, unsigned int DataLength);
};
class EQPlayer
{
public:
EQLIB_OBJECT EQPlayer::~EQPlayer();
EQLIB_OBJECT EQPlayer::EQPlayer(class EQPlayer*, unsigned char, unsigned int, unsigned char, char*);
EQLIB_OBJECT bool EQPlayer::AllowedToAttack(class EQPlayer*, int);
EQLIB_OBJECT bool EQPlayer::CanChangeForm(int Race, BYTE Sex, float Height);
EQLIB_OBJECT bool EQPlayer::CanIFitHere(float, float, float);
EQLIB_OBJECT bool EQPlayer::CanIHit(class EQPlayer*, float);
EQLIB_OBJECT bool EQPlayer::CanSee(class EQPlayer*);
EQLIB_OBJECT bool EQPlayer::CanSee(CVector3*pos);
EQLIB_OBJECT bool EQPlayer::GetBoneCoords(struct T3D_DAG*, struct _EQLOC*);
EQLIB_OBJECT bool EQPlayer::IsAMount();
EQLIB_OBJECT bool EQPlayer::IsFlyer();
EQLIB_OBJECT bool EQPlayer::IsInvisible(class EQPlayer*);
EQLIB_OBJECT bool EQPlayer::IsInvited();
EQLIB_OBJECT bool EQPlayer::IsRoleplaying();
EQLIB_OBJECT bool EQPlayer::IsUntexturedHorse();
EQLIB_OBJECT bool EQPlayer::IWasHit(struct _EQMissileHitinfo*);
EQLIB_OBJECT bool EQPlayer::MyFeetAreOnGround();
EQLIB_OBJECT bool EQPlayer::SetNameSpriteTint();
EQLIB_OBJECT bool EQPlayer::UpdatePlayerActor();
EQLIB_OBJECT bool const EQPlayer::HasInvalidRiderTexture() const;
EQLIB_OBJECT float EQPlayer::GetDefaultHeight(int, unsigned char);
EQLIB_OBJECT float EQPlayer::GetPlayerFloorHeight(float, float, float, unsigned char);
EQLIB_OBJECT int EQPlayer::AimAtTarget(class EQPlayer*, class EQMissile*);
EQLIB_OBJECT int EQPlayer::AttachPlayerToPlayerBone(class EQPlayer*, struct T3D_DAG*);
EQLIB_OBJECT int EQPlayer::CanBeBald();
EQLIB_OBJECT int EQPlayer::CheckForJump();
#if defined(ROF2EMU) || defined(UFEMU)
	bool EQPlayer::DoAttack(BYTE slot, BYTE skill, class EQPlayer*Target);
#else
	bool EQPlayer::DoAttack(BYTE slot, BYTE skill, EQPlayer*Target, bool bSomething = false, bool bAuto = false, bool bDontknow = false);
#endif
EQLIB_OBJECT int EQPlayer::GetAlternateTrackNumber(int, unsigned char*);
EQLIB_OBJECT int EQPlayer::GetArmorType(int);
EQLIB_OBJECT int EQPlayer::GetAttachedHelmITNum(int, int*);
EQLIB_OBJECT int EQPlayer::GetGuild() const;
EQLIB_OBJECT int EQPlayer::GetRaceSexITOffset();
EQLIB_OBJECT bool EQPlayer::IsValidTeleport(float X, float Y, float Z, float Heading, float Distance);
EQLIB_OBJECT int EQPlayer::Levitating();
EQLIB_OBJECT int EQPlayer::MountableRace();
EQLIB_OBJECT int EQPlayer::MovePlayer();
EQLIB_OBJECT int EQPlayer::NotOnSameDeity(class EQPlayer*, class EQ_Spell*);
EQLIB_OBJECT int EQPlayer::ReplaceSpecialCloakMaterials();
EQLIB_OBJECT int EQPlayer::SetEyeMaterial(unsigned char, int);
EQLIB_OBJECT int EQPlayer::SetFHEB(unsigned char, unsigned char);
EQLIB_OBJECT int EQPlayer::SetFHEB_Color(unsigned char, unsigned char);
EQLIB_OBJECT int EQPlayer::SetHairOrBeard(int);
EQLIB_OBJECT int EQPlayer::SetNameSpriteState(bool);
EQLIB_OBJECT int EQPlayer::SetPlayerPitchType();
EQLIB_OBJECT int EQPlayer::SwapBody(int, int);
EQLIB_OBJECT int EQPlayer::SwapFace(int, int);
EQLIB_OBJECT int EQPlayer::SwapHead(int, int, unsigned long, int);
EQLIB_OBJECT int EQPlayer::SwapMaterial(int, int, int, int, unsigned char);
EQLIB_OBJECT int EQPlayer::SwapNPCMaterials();
EQLIB_OBJECT static class EQPlayer* __cdecl EQPlayer::GetClosestPlayerFromPartialName(char*, class EQPlayer*);
EQLIB_OBJECT static class EQPlayer* __cdecl EQPlayer::GetPlayerFromPartialName(char*);
EQLIB_OBJECT static class EQPlayer* __cdecl EQPlayer::IsPlayerActor(struct T3D_tagACTORINSTANCE*);
EQLIB_OBJECT static class EQPlayer* __cdecl EQPlayer::GetPlayerFromName(char const*);
EQLIB_OBJECT static void __cdecl EQPlayer::ComputeSpecialHeights(int, float*, float*, float*, float*, bool);
EQLIB_OBJECT static void __cdecl EQPlayer::GetPCActorTag(char*, unsigned int, unsigned char);
EQLIB_OBJECT static void __cdecl EQPlayer::TackOnNeuterChar(char*, unsigned int);
EQLIB_OBJECT static void __cdecl EQPlayer::UpdateAllPlayersVisibility();
EQLIB_OBJECT struct T3D_DAG* EQPlayer::GetBonePointerByITS(int, int);
EQLIB_OBJECT struct T3D_POINTLIGHT* EQPlayer::CreateUserLight(struct T3D_LIGHTDEFINITION*, int);
EQLIB_OBJECT unsigned char EQPlayer::DoTeleport(char*, int);
EQLIB_OBJECT unsigned char EQPlayer::DoTeleportB(int, float, float, float, float, char*, int);
EQLIB_OBJECT unsigned char EQPlayer::GetBaseFaceNbr(int, unsigned char*);
EQLIB_OBJECT unsigned char EQPlayer::GetNearestActorTag(char*, void*);
EQLIB_OBJECT unsigned char EQPlayer::HandleAmmo();
EQLIB_OBJECT unsigned char EQPlayer::HasAttachedBeard();
EQLIB_OBJECT unsigned char EQPlayer::HasAttachedHair();
EQLIB_OBJECT unsigned char EQPlayer::SkillUsed(unsigned char);
EQLIB_OBJECT unsigned char EQPlayer::UpdateItemSlot(unsigned char, char*, int);
EQLIB_OBJECT unsigned int EQPlayer::CalcAnimLength(int);
EQLIB_OBJECT unsigned int EQPlayer::ModifyAttackSpeed(unsigned int, int);
EQLIB_OBJECT unsigned long EQPlayer::GetArmorTint(int);
EQLIB_OBJECT void EQPlayer::BodyEnvironmentChange(unsigned char);
EQLIB_OBJECT void EQPlayer::ChangeHeight(float);
EQLIB_OBJECT void EQPlayer::ChangeLight();
EQLIB_OBJECT void EQPlayer::ChangeNoGravity(int);
EQLIB_OBJECT void EQPlayer::ChangePosition(unsigned char);
EQLIB_OBJECT void EQPlayer::CheckForUnderFloor();
EQLIB_OBJECT void EQPlayer::CleanUpMyEffects();
EQLIB_OBJECT void EQPlayer::CleanUpTarget();
EQLIB_OBJECT void EQPlayer::CleanUpVehicle();
EQLIB_OBJECT void EQPlayer::DeleteMyMissiles();
EQLIB_OBJECT void EQPlayer::Dismount();
EQLIB_OBJECT void EQPlayer::DisplayWeaponsAndArmor();
EQLIB_OBJECT void EQPlayer::do_change_form(struct chngForm*);
EQLIB_OBJECT void EQPlayer::DoCamAi();
EQLIB_OBJECT void EQPlayer::DoClassRandomAnimation();
EQLIB_OBJECT void EQPlayer::DoFloorCheck();
EQLIB_OBJECT void EQPlayer::DoItemSlot(int);
EQLIB_OBJECT void EQPlayer::DoSwimJump(unsigned char);
EQLIB_OBJECT void EQPlayer::FacePlayer(class EQPlayer*);
EQLIB_OBJECT void EQPlayer::FeetEnvironmentChange(unsigned char);
EQLIB_OBJECT void EQPlayer::FollowPlayerAI();
EQLIB_OBJECT void EQPlayer::ForceInvisible(bool);
EQLIB_OBJECT void EQPlayer::GetActorTag(char*);
EQLIB_OBJECT void EQPlayer::GetAllowedHairColorIndexRange(int, int*, int*);
EQLIB_OBJECT void EQPlayer::GetConscious();
EQLIB_OBJECT void EQPlayer::HandleMaterialEx(int, unsigned int, unsigned int, unsigned long, int);
EQLIB_OBJECT void EQPlayer::HandoverControlToZoneserver();
EQLIB_OBJECT void EQPlayer::HeadEnvironmentChange(unsigned char);
EQLIB_OBJECT void EQPlayer::HideOrShowAttachedHair();
EQLIB_OBJECT void EQPlayer::IDied(struct _EQPlayerDeath*);
EQLIB_OBJECT void EQPlayer::IHaveFallen(float);
EQLIB_OBJECT void EQPlayer::InitSneakMod();
EQLIB_OBJECT void EQPlayer::KnockedOut();
EQLIB_OBJECT void EQPlayer::MakeRiderMountUp();
EQLIB_OBJECT void EQPlayer::MountEQPlayer(class EQPlayer*);
EQLIB_OBJECT void EQPlayer::PlaySoundA(int);
EQLIB_OBJECT void EQPlayer::PositionOnFloor();
EQLIB_OBJECT void EQPlayer::PushAlongHeading(float);
EQLIB_OBJECT void EQPlayer::PutPlayerOnFloor();
EQLIB_OBJECT void EQPlayer::ResetVariables();
EQLIB_OBJECT void EQPlayer::SetAccel(float, int);
EQLIB_OBJECT void EQPlayer::SetAfk(int);
EQLIB_OBJECT void EQPlayer::SetAndReserveID(unsigned int);
EQLIB_OBJECT void EQPlayer::SetAnimVariation();
EQLIB_OBJECT void EQPlayer::SetArmorTint(int, unsigned long);
EQLIB_OBJECT void EQPlayer::SetArmorType(int, int);
EQLIB_OBJECT void EQPlayer::SetCurrentLoopSound(int);
EQLIB_OBJECT void EQPlayer::SetDefaultFacialFeaturesByFace(int, unsigned char, unsigned char);
EQLIB_OBJECT void EQPlayer::SetDefaultITAttachments(int);
EQLIB_OBJECT void EQPlayer::SetHeights();
EQLIB_OBJECT void EQPlayer::SetInvited(bool);
EQLIB_OBJECT void EQPlayer::SetPlayerConstantAmbient(struct T3D_RGB*);
EQLIB_OBJECT void EQPlayer::SetRace(int);
EQLIB_OBJECT void EQPlayer::SetSounds();
EQLIB_OBJECT void EQPlayer::SetToRandomRace();
EQLIB_OBJECT void EQPlayer::TouchingSwitch();
EQLIB_OBJECT void EQPlayer::TriggerSpellEffect(struct _EQMissileHitinfo*);
EQLIB_OBJECT void EQPlayer::TurnOffAutoFollow();
EQLIB_OBJECT void EQPlayer::UpdateAppearance();
EQLIB_OBJECT void EQPlayer::UpdateBonePointers();
EQLIB_OBJECT void EQPlayer::UpdateNameSprite();
EQLIB_OBJECT void EQPlayer::UpdatePlayerVisibility();
EQLIB_OBJECT bool EQPlayer::HasProperty(unsigned int, int, int);
EQLIB_OBJECT class CLineSegment &EQPlayer::GetVisibilityLineSegment(class CLineSegment&ls, class EQPlayer& pSpawn, unsigned int index = 0);//index MUST be 0
// private
EQLIB_OBJECT int EQPlayer::IdUsed(unsigned int);
EQLIB_OBJECT static class EQPlayer* EQPlayer::mTop;
EQLIB_OBJECT struct S3D_STRINGSPRITE* EQPlayer::ChangeBoneStringSprite(struct T3D_DAG*, char*);
EQLIB_OBJECT unsigned char EQPlayer::GetAlternateAnimVariation(int, unsigned char);
EQLIB_OBJECT unsigned int EQPlayer::GetUnusedID();
EQLIB_OBJECT void EQPlayer::FindDefaultEyeMaterialIndexes();
EQLIB_OBJECT void EQPlayer::InitializeIDArray();
EQLIB_OBJECT BYTE EQPlayer::GetLevel() const;

SPAWNINFO Data;
};

class ExtendedTargetListClient : public ExtendedTargetList
{
	//has no vftable
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

class CGroupMemberBase
{
	//has a vftable
public:
	/*0x00*/ void  *vftable;
	PCXSTR	Name;
	short	Type;
	PCXSTR	OwnerName;
	int		Level;
	bool	bIsOffline;
	UINT UniquePlayerID;
	bool bRoleStates[6];
	UINT CurrentRoleBits;
	UINT OnlineTimestamp;
};
class CGroupMemberClient : public CGroupMemberBase
{
public:
	CharacterZoneClient*pCharacter;
	PSPAWNINFO pSpawn;
	int GroupIndex;

};
class CGroupBase
{
	//has a vftable
public:
/*0x00*/ void  *vftable;
	CGroupMemberClient* pMembers[6];
	CGroupMemberClient* pGroupLeader;
	UINT ID;
};
class CGroupClient : public CGroupBase
{
	//has no vftable
public:
	int GroupSelectID;
};


class PlayerBaseVfTable
{
	/*0x0000*/ void*	vtable;
};
class PlayerBase : public TListNode<PlayerBase>, public CActorApplicationData 

//class PlayerBase : public PlayerBaseVfTable, public TListNode<PlayerBase>
{
public:
/*0x0010*/ float	JumpStrength;
/*0x0014*/ float	SwimStrength;
/*0x0018*/ float	SpeedMultiplier;
/*0x001c*/ float	AreaFriction;
/*0x0020*/ float	AccelerationFriction;
/*0x0024*/ EActorType CollidingType; /* ok finally had time to get this one right, when we collide with something this gets set.*/
/*0x0028*/ float	FloorHeight;
/*0x002c*/ bool		bSinksInWater;
/*0x0030*/ UINT		PlayerTimeStamp; /* doesn't update when on a Vehicle (mounts/boats etc)*/
/*0x0034*/ UINT		LastTimeIdle;
/*0x0038*/ CHAR		Lastname[0x20];
/*0x0058*/ float	AreaHPRegenMod; /*from guild hall pools etc.*/
/*0x005c*/ float	AreaEndRegenMod;
/*0x0060*/ float	AreaManaRegenMod;
/*0x0064*/ float	Y;
/*0x0068*/ float	X;
/*0x006c*/ float	Z;
/*0x0070*/ float	SpeedY;
/*0x0074*/ float	SpeedX;
/*0x0078*/ float	SpeedZ;
/*0x007c*/ float	SpeedRun;
/*0x0080*/ float	Heading;
/*0x0084*/ float	Angle;
/*0x0088*/ float	AccelAngle;
/*0x008c*/ float	SpeedHeading;
/*0x0090*/ float	CameraAngle;
/*0x0094*/ UINT		UnderWater; /*LastHeadEnvironmentType*/
/*0x0098*/ UINT		LastBodyEnvironmentType;
/*0x009c*/ UINT		LastFeetEnvironmentType;
/*0x00a0*/ BYTE		HeadWet; /*these really are environment related, like lava as well for example*/
/*0x00a1*/ BYTE		FeetWet;
/*0x00a2*/ BYTE		BodyWet;
/*0x00a3*/ BYTE		LastBodyWet;
/*0x00a4*/ CHAR		Name[0x40];             /* ie priest_of_discord00*/
/*0x00e4*/ CHAR		DisplayedName[0x40];    /* ie Priest of Discord*/
/*0x0124*/ BYTE		PossiblyStuck;          /* never seen this be 1 so maybe it was used a a point but not now...*/
/*0x0125*/ BYTE		Type;
/*0x0128*/ DWORD**	BodyType;	/* this really should be renamed to charprops or something its broken anyway*/
/*0x012c*/ BYTE		CharPropFiller[0xc]; /* well since the above is a CharacterPropertyHash we have to pad here...*/
/*0x0138*/ float	AvatarHeight;           /* height of avatar from groundwhen standing*/
/*0x013c*/ float	Height;
/*0x0140*/ float	Width;
/*0x0144*/ float	Length;
/*0x0148*/ DWORD	SpawnID;
/*0x014c*/ DWORD	PlayerState;         /* 0=Idle 1=Open 2=WeaponSheathed 4=Aggressive 8=ForcedAggressive 0x10=InstrumentEquipped 0x20=Stunned 0x40=PrimaryWeaponEquipped 0x80=SecondaryWeaponEquipped*/
/*0x0150*/ struct _SPAWNINFO*	Vehicle;    /* NULL until you collide with a vehicle (boat, airship etc)*/
/*0x0154*/ struct _SPAWNINFO*	Mount;      /* NULL if no mount present*/
/*0x0158*/ struct _SPAWNINFO*	Rider;      /* _SPAWNINFO of mount's rider*/
/*0x015c*/ DWORD	Unknown0x015c;
/*0x0160*/ bool		Targetable;	/* true if mob is targetable*/
/*0x0161*/ bool		bTargetCyclable;
/*0x0162*/ bool		bClickThrough;
/*0x0163*/ bool		bBeingFlung;
/*0x0164*/ UINT		FlingActiveTimer;
/*0x0168*/ UINT		FlingTimerStart;
/*0x016c*/ bool		bFlingSomething;
/*0x0170*/ float	FlingY;
/*0x0174*/ float	FlingX;
/*0x0178*/ float	FlingZ;
/*0x017c*/ bool		bFlingSnapToDest;
/*0x0180*/ int		SplineID;
/*0x0184*/ int		SplineRiderID;
inline unsigned int GetId() const
{
	return SpawnID;
}
};
#define EQR_GNOME			0xc//5A1511 in rof2
#define EQR_IKSAR			0x80//5A1516 in rof2
#define EQR_VAHSHIR			0x82//5A151D in rof2
#define EQR_FROGLOCK		0x14a//5A1524 in rof2
#define EQR_DRAKKIN			0x20a//5A152B in rof2
#define EQR_SKELETON		0x3c
#define EQR_SKELETON_NEW	0x16f
#define EQR_OEQ_SKELETON	0x322
#define EQR_SOL_SKELETON	0x323

class PlayerZoneClient : public PlayerBase
{
public:
/*0x0188*/ UINT		LastIntimidateUse;
/*0x018c*/ PLAYERZONECLIENT
/*0x0614*/ //I wont finetune these comments every single patch cause they change since PLAYERZONECLIENT size change...
/*0x0614*/ TCircularBuffer<SDoCollisionMovementStats, 0x14>MovementStats; /* size (0x74* 0x14) +8 = 0x918*/
/*0x0f2c*/ struct _SPAWNINFO*   WhoFollowing; // NULL if autofollow off
/*0x0f30*/ DWORD	GroupAssistNPC[0x1];
/*0x0f34*/ DWORD	RaidAssistNPC[0x3];
/*0x0f40*/ DWORD	GroupMarkNPC[0x3];
/*0x0f4c*/ DWORD	RaidMarkNPC[0x3];
/*0x0f58*/ DWORD	TargetOfTarget;
/*0x0f5c*/ BYTE		PhysStuff[0x20];
/*0x0f7c*/ UINT		ParticleCastStartTime;
/*0x0f80*/ UINT		ParticleCastDuration;
/*0x0f84*/ int		ParticleVisualSpellNum;
/*0x0f88*/ BYTE		Filler0x0f88[0x4];
/*0x0f8c*/ ActorClient	mActorClient;          // start of ActorClient struct  size 0x1BC?
/*0x1148*/ PlayerAnimationBase*pAnimation;
/*0x114c*/ float	MeleeRadius;      // used by GetMeleeRange
/*0x1150*/ UINT		CollisionCounter;
/*0x1154*/ float	CachedFloorLocationY;
/*0x1158*/ float	CachedFloorLocationX;
/*0x115c*/ float	CachedFloorLocationZ;
/*0x1160*/ float	CachedFloorHeight;
/*0x1164*/ float	CachedCeilingLocationY;
/*0x1168*/ float	CachedCeilingLocationX;
/*0x116c*/ float	CachedCeilingLocationZ;
/*0x1170*/ float	CachedCeilingHeight;
/*0x1174*/ CCapsule	StaticCollision;//size 0x1c
/*0x1190*/ ArrayClass_RO<PhysicsEffect> mPhysicsEffects;//size is 0x10
/*0x11a0*/ ArrayClass_RO<bool> PhysicsEffectsUpdated;//size is 0x10
#if !defined(UFEMU)
EQLIB_OBJECT int PlayerZoneClient::LegalPlayerRace(int race);
#else
//this function doesnt exist in the emu build, so well... im adding it i guess...
EQLIB_OBJECT int PlayerZoneClient::LegalPlayerRace(int race)
{
	if (race == -1)
	{
		race = this->mActorClient.Race;
	}
	if((race <= EQR_GNOME) || (race == EQR_IKSAR) || (race == EQR_VAHSHIR) || (race == EQR_FROGLOCK) || (race == EQR_DRAKKIN))
	{
		return 1;
	}
	return 0;
}
#endif

};
//this is what we call EQPlayer maybe i should just rename that one but too late now?
class PlayerClient : public PlayerZoneClient
{
public:
/*0x1198*/ int		Animation; //0x1198 confirmed Apr 24 2017 always on 8 alignment? /* Current Animation Playing.*/
/*0x11xx*/ int		NextAnim;
/*0x11xx*/ int		CurrLowerBodyAnim;
/*0x1194*/ int		NextLowerBodyAnim;
/*0x1198*/ int		CurrLowerAnimVariation;
/*0x119c*/ int		CurrAnimVariation;
/*0x11a0*/ int		CurrAnimRndVariation;
/*********************sound ID's BEGIN********************/
/*0x11a4*/ int		Loop3d_SoundID;

/*0x11a8*/ int		Step_SoundID;;
/*0x11ac*/ int		CurLoop_SoundID;
/*0x11b0*/ int		Idle3d1_SoundID;
/*0x11b4*/ int		Idle3d2_SoundID;
/*0x11b8*/ int		Jump_SoundID;
/*0x11bc*/ int		Hit1_SoundID;
/*0x11c0*/ int		Hit2_SoundID;
/*0x11c4*/ int		Hit3_SoundID;

/*0x11c8*/ int		Hit4_SoundID;
/*0x11cc*/ int		Gasp1_SoundID;
/*0x11d0*/ int		Gasp2_SoundID;
/*0x11d4*/ int		Drown_SoundID;
/*0x11d8*/ int		Death_SoundID;
/*0x11dc*/ int		Attk1_SoundID;
/*0x11e0*/ int		Attk2_SoundID;
/*0x11e4*/ int		Attk3_SoundID;

/*0x11e8*/ int		Walk_SoundID;
/*0x11ec*/ int		Run_SoundID;
/*0x11f0*/ int		Crouch_SoundID;
/*0x11f4*/ int		Swim_SoundID;
/*0x11f8*/ int		TreadWater_SoundID;
/*0x11fc*/ int		Climb_SoundID;
/*0x1200*/ int		Sit_SoundID;
/*0x1204*/ int		Kick_SoundID;

/*0x1208*/ int		Bash_SoundID;
/*0x120c*/ int		FireBow_SoundID;
/*0x1210*/ int		MonkAttack1_SoundID;
/*0x1214*/ int		MonkAttack2_SoundID;
/*0x1218*/ int		MonkSpecial_SoundID;
/*0x121c*/ int		PrimaryBlunt_SoundID;
/*0x1220*/ int		PrimarySlash_SoundID;
/*0x1224*/ int		PrimaryStab_SoundID;

/*0x1228*/ int		Punch_SoundID;
/*0x122c*/ int		Roundhouse_SoundID;
/*0x1230*/ int		SecondaryBlunt_SoundID;
/*0x1234*/ int		SecondarySlash_SoundID;
/*0x1238*/ int		SecondaryStab_SoundID;
/*0x123c*/ int		SwimAttack_SoundID;
/*0x1240*/ int		TwoHandedBlunt_SoundID;
/*0x1244*/ int		TwoHandedSlash_SoundID;

/*0x1248*/ int		TwoHandedStab_SoundID;
/*0x124c*/ int		SecondaryPunch_SoundID;
/*0x1250*/ int		JumpAcross_SoundID;
/*0x1254*/ int		WalkBackwards_SoundID;
/*0x1258*/ int		CrouchWalk_SoundID;
/********************* sound ID's END*******************/
/*0x125c*/ UINT		LastHurtSound;
/*0x1260*/ UINT		LastWalkTime;//used for animations
/*0x1264*/ int		ShipRelated;//ID? look into.
/*0x1268*/ int		RightHolding;//Nothing=0 Other/Weapon=1 shield=2
/*0x126c*/ int		LeftHolding;//old Holding
/*0x1270*/ UINT		DeathAnimationFinishTime;
/*0x1274*/ bool		bRemoveCorpseAfterDeathAnim;//0x1274 for sure used by /hidecorpse
/*0x1278*/ UINT		LastBubblesTime;
/*0x127c*/ UINT		LastBubblesTime1;
/*0x1280*/ UINT		LastColdBreathTime;
/*0x1284*/ UINT		LastParticleUpdateTime;
/*0x1288*/ UINT		MercID;    // IT IS 0x1288      //if the spawn is player and has a merc up this is it's spawn ID 16 jul 2014
/*0x128c*/ UINT		ContractorID;    //if the spawn is a merc this is its contractor's spawn ID 16 jul 2014
/*0x1290*/ float	CeilingHeightAtCurrLocation;
/*0x1294*/ void		*MobileEmitter;//todo: change and map to EqMobileEmitter*
/*0x1298*/ bool		bInstantHPGaugeChange;
/*0x129c*/ UINT		LastUpdateReceivedTime;
/*0x12a0*/ float	MaxSpeakDistance;
/*0x12a4*/ float	WalkSpeed;//how much we will slow down while sneaking
/*0x12a8*/ bool		bHideCorpse;// IT IS 0x12a8
/*0x12a9*/ CHAR		AssistName[0x40];
/*0x12E9*/ bool		InvitedToGroup;//IT IS 12E9!
/*0x12ec*/ int		GroupMemberTargeted;//12ec for sure!    // 0xFFFFFFFF if no target, else 1 through 5
/*0x12f0*/ bool		bRemovalPending;
/*0x12f4*/ void		*pCorpse;//look into 0x12f4 for sure!
/*0x12f8*/ float	EmitterScalingRadius;//0x12f8 FOR SURE
/*0x12fc*/ int		DefaultEmitterID;
/*0x1300*/ bool		bDisplayNameSprite;
/*0x1301*/ bool		bIdleAnimationOff;
/*0x1302*/ bool		bIsInteractiveObject;
/*0x1303*/ BYTE		InteractiveObjectModelName[0x80];
/*0x1383*/ BYTE		InteractiveObjectOtherName[0x80];
/*0x1403*/ BYTE		InteractiveObjectName[0x40];
/*0x1443*/
/*0x1444*/ CPhysicsInfo PhysicsBeforeLastPort;//size IS /*0x30*/
/*0x1474*/ DWORD notsure;
/*0x1478*/ struct _FELLOWSHIPINFO	Fellowship; // IT IS AT 0x1478 // size 0x9e8 //it IS at 1478
/*0x1E60*/ float	CampfireY;
/*0x1e64*/ float	CampfireX;
/*0x1e68*/ float	CampfireZ;
/*0x1e6c*/ int		CampfireZoneID;         // zone ID where campfire is
/*0x1e70*/ int		CampfireTimestamp;      // CampfireTimestamp-FastTime()=time left on campfire
/*0x1e74*/ int		CampfireTimestamp2;
/*0x1e78*/ int		FellowShipID;
/*0x1e7c*/ int		FellowShipID2;
/*0x1e80*/ int		CampType;
/*0x1e84*/ bool		Campfire;
/*0x1e88*/ TSafeArrayStatic<int, 3> SeeInvis;
/*0x1E94*/ struct _EQUIPMENT	Equipment;// size 0xb4
/*0x1F48*/ bool		bIsPlacingItem;
/*0x1f49*/ bool		bGMCreatedNPC;
/*0x1f4c*/ int		ObjectAnimationID;
/*0x1f50*/ bool		bInteractiveObjectCollidable;
/*0x1f54*/ int		InteractiveObjectType;
/*0x1f58*/ int		SoundIDs[0xa];//0x28 bytes
/*0x1f80*/ UINT		LastHistorySentTime;
/*0x1f84*/ ArrayClass2_RO<UINT>	BardTwistSpells;//size 0x1c
/*0x1fA0*/ int64_t		CurrentBardTwistIndex;
/*0x1fA8*/ PlayerPhysicsClient mPlayerPhysicsClient;//size 0x28
/*0x1Fd0*/ int		SpawnStatus[6];//todo: look closer at these i think they can show like status of mobs slowed, mezzed etc, but not sure
/*0x1fe8*/ int		BannerIndex0;//guild banners
/*0x1fec*/ int		BannerIndex1;
/*0x1ff0*/ ARGBCOLOR BannerTint0;
/*0x1ff4*/ ARGBCOLOR BannerTint1;
/*0x1ff8*/ int		MountAnimationRelated;
/*0x1ffc*/ bool		bGuildShowAnim;//or sprite? need to check
/*0x1ffd*/ bool		bWaitingForPort;//check this
EQLIB_OBJECT PcClient* PlayerClient::GetPcClient() const;//call this using pLocalPlayer->GetPcClient();
inline signed int GetClass()
{
	return mActorClient.Class;
}
inline BYTE GetCharacterType()
{
	return Type;
}
inline CHAR IsGm()
{
	return GM;
}
};

class SpellCache
{
	//has no vftable
public:
	struct EffectCache {
		int SubIndex;
		int TotalPlayerEffects;
		int TotalItemEffects;
		bool bDegenerating;
		int TotalContrib;
	};
	struct AltEffectCache {
		int SubIndex;
		int AltTotal;
	};
    struct CachedFocusItem {
        PCONTENTS         pContents;
        int	Percent;
        ItemSpellTypes SpellType;
    };
    struct CachedFocusEffect {
        const PSPELL     pSpell;
        int	Percent;
		short AffectIndex;
    };
    struct CachedFocusAbility {
        const void*pEffectData;
        int Percent;
    };
    struct CachedFocusMercAbility {
        const void* pAbilityEffectDef;//todo change this to a MercenaryAbilityEffectsDefinition*
        int Percent;
    };
/*0x00*/ HashTable<EffectCache>*pCachedEffects;
/*0x04*/ bool bCachedSpellEffects;
/*0x08*/ HashTable<AltEffectCache>*pCachedAltAbilityEffects;
/*0x0c*/ bool bCachedAltEffects;
/*0x10*/ HashTable<EffectCache>*pCachedLimitedEffects;
/*0x14*/ bool bCachedLimitedEffects;
/*0x18*/ HashTable<CachedFocusItem, int64_t>		CachedFocusItems;
/*0x28*/ HashTable<CachedFocusEffect, int64_t>		CachedFocusEffects;
/*0x38*/ HashTable<CachedFocusAbility, int64_t>		CachedFocusAbilities;
/*0x48*/ HashTable<CachedFocusMercAbility, int64_t>	CachedFocusMercAbilities;
/*0x58*/ 
};
class SomeClass
{
public:
/*0x0000*/ void*CharacterZoneClient_vftable;
};

enum GILocationOption
{
	Bag_Or_Base,
	Socket
};
class CharacterBase
{
public:
/*0x0000*/ void*CharacterBase_vftable;
/*0x0004*/ CProfileManager ProfileManager;//size 0x8
/*0x000C*/ TSafeArrayStatic<BYTE, 0x20>	languages;
/*0x002C*/ float         X;
/*0x0030*/ float         Y;
/*0x0034*/ float         Z;
/*0x0038*/ float         Heading;
/*0x003c*/ TSafeString<0x40>	Name;
/*0x007c*/ TSafeString<0x20>	Lastname;
/*0x009c*/ TSafeString<0x80>	Title;
/*0x011c*/ TSafeString<0x40>	VehicleName;
/*0x015c*/ char			Stunned;//well status really
/*0x0160*/ EQZoneIndex		zoneId;
/*0x0164*/ BYTE	standstate;
/*0x0168*/ RaidData raidData;//size 0xdc
/*0x0244*/ int			ExpansionFlags;
/*0x0248*/ bool			bSuperPKILL;
/*0x024a*/ bool			bUnclone;
/*0x024b*/ bool			bDead;
/*0x024C*/ int			LD_Timer;
/*0x0250*/ int			SpellInterruptCount;
/*0x0254*/ bool			bAutoSplit;
/*0x0255*/ bool			bTellsOff;
/*0x0256*/ bool			bGmInvis;
/*0x0258*/ int			KillMe;
/*0x025c*/ bool			CheaterLdFlag;//likely this is int SoulMarkCount instead.
/*0x025d*/ bool			NoRent;
/*0x025e*/ bool			Corpse;
/*0x025f*/ bool			ClientGmFlagSet;
/*0x0260*/ int          BankSharedPlat;//31e4 CharBaseBegin+488
/*0x0264*/ int          BankSharedGold;//CharBaseBegin+48c
/*0x0268*/ int          BankSharedSilver;//CharBaseBegin+490
/*0x026c*/ int          BankSharedCopper;//CharBaseBegin+494
/*0x0270*/ int          BankPlat;//CharBaseBegin+498
/*0x0274*/ int          BankGold;//CharBaseBegin+49c
/*0x0278*/ int          BankSilver;//CharBaseBegin+4a0
/*0x027c*/ int          BankCopper;//CharBaseBegin+4a4
/*0x0280*/ int          STR;//CharBaseBegin+4a8
/*0x0284*/ int          STA;//CharBaseBegin+4ac
/*0x0288*/ int          CHA;//CharBaseBegin+4b0
/*0x028c*/ int          DEX;//CharBaseBegin+4b4
/*0x0290*/ int          INT;//CharBaseBegin+4b8
/*0x0294*/ int          AGI;//CharBaseBegin+4bc
/*0x0298*/ int          WIS;//CharBaseBegin+4c0
/*0x029c*/ int          SavePoison;//CharBaseBegin+4c4
/*0x02a0*/ int          SaveMagic;//CharBaseBegin+4c8
/*0x02a4*/ int          SaveDisease;//CharBaseBegin+4cc
/*0x02a8*/ int          SaveCorruption;//CharBaseBegin+4d0
/*0x02ac*/ int          SaveFire;//CharBaseBegin+4d4
/*0x02b0*/ int          SaveCold;//CharBaseBegin+4d8
/*0x02b4*/ int          SavePhysical;
/*0x02b8*/ int			UncappedStr;
/*0x02bc*/ int  		UncappedSta;
/*0x02c0*/ int			UncappedCha;
/*0x02c4*/ int			UncappedDex;
/*0x02c8*/ int			UncappedInt;
/*0x02cc*/ int			UncappedAgi;
/*0x02d0*/ int			UncappedWis;
/*0x02d4*/ int			UncappedResistPoison;
/*0x02d8*/ int			UncappedResistMagic;
/*0x02dc*/ int			UncappedResistDisease;
/*0x02e0*/ int			UncappedResistCorruption;
/*0x02e4*/ int			UncappedResistFire;
/*0x02e8*/ int			UncappedResistCold;
/*0x02ec*/ int			NoBuffStr;
/*0x02f0*/ int			NoBuffSta;
/*0x02f4*/ int			NoBuffCha;
/*0x02f8*/ int			NoBuffDex;
/*0x02fc*/ int			NoBuffInt;
/*0x0300*/ int			NoBuffAgi;
/*0x0304*/ int			NoBuffWis;
/*0x0308*/ int			NoBuffResistPoison;
/*0x030c*/ int			NoBuffResistMagic;
/*0x0310*/ int			NoBuffResistDisease;
/*0x0314*/ int			NoBuffResistCorruption;
/*0x0318*/ int			NoBuffResistFire;
/*0x031c*/ int			NoBuffResistCold;
/*0x0320*/ int			NoBuffResistPhysical;
/*0x0320*/ int			NoBuffResistPhysical2;
/*0x0320*/ int			NoBuffResistPhysical3;
/*0x0324*/
	unsigned int CharacterBase::GetEffectId(int index);

	LONG CharacterBase::GetMemorizedSpell(int gem);//0-0xf this func returns the spellid for whatever is in the gem
	ItemGlobalIndex CreateItemGlobalIndex(int Slot0, int Slot1 = -1, int Slot2 = -1);
	ItemIndex CreateItemIndex(int Slot0, int Slot1=-1, int Slot2=-1);
	inline const BaseProfile& GetCurrentBaseProfile() const
	{
		//CharacterBase*bp = (CharacterBase*)*this;
		return*ProfileManager.GetCurrentProfile();
	}
	BYTE CharacterBase::GetLanguageSkill(int) const;
	VePointer<CONTENTS> CharacterBase::GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex) const;
	VePointer<CONTENTS> CharacterBase::GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex, GILocationOption Option) const;
	VePointer<CONTENTS> CharacterBase::GetItemPossession(const ItemIndex &lIndex) const;
};

EQLIB_OBJECT char* build_token_string_PARAM(char*pBuffer, int token, const char*param0=NULL, const char*param1=NULL,
								const char*param2=NULL, const char*param3=NULL, const char*param4=NULL, const char*param5=NULL, 
								const char*param6=NULL, const char*param7=NULL, const char*param8=NULL);

class CharacterZoneClient : public SomeClass, virtual public CharacterBase
{
public:
union {
/*0x2424*/ PlayerClient*me;//just here for comparing the 2, todo: fix
/*0x2424*/ PSPAWNINFO me2;
};
/*0x242c*/ bool		bUpdateStuff;
/*0x242d*/ bool     bZoningStatProcessing;
/*0x2430*/ DWORD    ArmorClassBonus;//vtable2+10
/*0x2434*/ DWORD    CurrWeight;//vtable2+14
/*0x2438*/ int		LastHitPointSendPercent;
/*0x243c*/ int		LastManaPointSendPercent;
/*0x2440*/ int		LastEndurancePointSendPercent;
/*0x2444*/ DWORD    HPBonus;//vtable2+24
/*0x2448*/ DWORD    ManaBonus;//vtable2+28
/*0x244c*/ DWORD    EnduranceBonus;//vtable2+2c
/*0x2450*/ BYTE     Unknown0x2450[0x4];
/*0x2454*/ DWORD    CombatEffectsBonus;//vtable2+34 Combat Effects in UI
/*0x2458*/ DWORD    ShieldingBonus;//vtable2+38 Melee Shielding in UI
/*0x245c*/ DWORD    SpellShieldBonus;//vtable2+3c Spell Shielding in UI
/*0x2460*/ DWORD    AvoidanceBonus;//vtable2+40 Avoidance in UI
/*0x2464*/ DWORD    AccuracyBonus;//vtable2+44 Accuracy in UI
/*0x2468*/ DWORD    StunResistBonus;//vtable2+48 Stun Resist in UI
/*0x246c*/ DWORD    StrikeThroughBonus;//vtable2+4c Strike Through in UI
/*0x2470*/ DWORD    DoTShieldBonus;//vtable2+50 Dot Shielding in UI
/*0x2474*/ DWORD    DamageShieldMitigationBonus;//vtable2+54 Damage Shield Mitig in UI
/*0x2478*/ DWORD    DamageShieldBonus;//vtable2+58 Damage Shielding in UI
/*0x247c*/ TSafeArrayStatic<int, 9> ItemSkillMinDamageMod;//size 0x24
/*0x24a0*/ TSafeArrayStatic<int, 9> SkillMinDamageModBonus;//size 0x24
/*0x24c4*/ DWORD    HeroicSTRBonus;//vtable2+a4
/*0x24c8*/ DWORD    HeroicINTBonus;//vtable2+a8
/*0x24cc*/ DWORD    HeroicWISBonus;//vtable2+ac
/*0x24d0*/ DWORD    HeroicAGIBonus;//vtable2+b0
/*0x24d4*/ DWORD    HeroicDEXBonus;//vtable2+b4
/*0x24d8*/ DWORD    HeroicSTABonus;//vtable2+b8
/*0x24dc*/ DWORD    HeroicCHABonus;//vtable2+bc
/*0x24e0*/ DWORD    HeroicSvMagicBonus;//vtable2+c0
/*0x24e4*/ DWORD    HeroicSvFireBonus;//vtable2+c4
/*0x24e8*/ DWORD    HeroicSvColdBonus;//vtable2+c8
/*0x24ec*/ DWORD    HeroicSvDiseaseBonus;//vtable2+cc
/*0x24f0*/ DWORD    HeroicSvPoisonBonus;//vtable2+d0
/*0x24f4*/ DWORD    HeroicSvCorruptionBonus;//vtable2+d4
/*0x24f8*/ DWORD    HealAmountBonus;//vtable2+d8
/*0x24fc*/ DWORD    SpellDamageBonus;//vtable2+dc
/*0x2500*/ int		ItemHealAmountDotMod;
/*0x2504*/ int		ItemSpellDamageDotMod;
/*0x2508*/ DWORD    ClairvoyanceBonus;//vtable2+e8
/*0x250c*/ DWORD    AttackBonus;//vtable2+ec
/*0x2510*/ DWORD    HPRegenBonus;//vtable2+f0
/*0x2514*/ DWORD    ManaRegenBonus;//vtable2+f4
/*0x2518*/ DWORD    EnduranceRegenBonus;//vtable2+f8
/*0x251c*/ DWORD    AttackSpeed;//vtable2+fc
/*0x2520*/ //int	  ItemPotionBelt;
/*0x2520*/ int		NoBuffItemHitpointAdjustment;
/*0x2524*/ int		NoBuffItemManaAdjustment;
/*0x2528*/ int		NoBuffItemEnduranceAdjustment;
/*0x252c*/ int		NoBuffItemBaseChanceProc;
/*0x2530*/ int		NoBuffItemMinDamageMod;
/*0x2534*/ int		NoBuffItemInnateSpellRune;
/*0x2538*/ int		NoBuffItemAvoidance;
/*0x253c*/ int		NoBuffItemToHit;
/*0x2540*/ int		NoBuffItemResistStunChance;
/*0x2544*/ int		NoBuffItemDotShieldingEffect;
/*0x2548*/ int		NoBuffItemStrikeThroughChance;
/*0x254c*/ int		NoBuffItemAttack;
/*0x2550*/ int		NoBuffItemHitPointRegen;
/*0x2554*/ int		NoBuffItemManaRegen;
/*0x2558*/ int		NoBuffItemEnduranceRegen;
/*0x255c*/ int		NoBuffItemDamageShield;
/*0x2560*/ int		NoBuffItemDamageShieldMitigation;
/*0x2564*/ int		NoBuffItemHaste;
/*0x256c*/ //int	  NoBuffItemPotionBelt;
/*0x2568*/ TSafeArrayStatic<int, 9> NoBuffItemSkillMinDamageMod;//size 0x24
/*0x258c*/ bool		bOutputHpRegen;
/*0x258d*/ bool		bInvulnerable;
/*0x258e*/ bool		bOnAVehicle;
/*0x2590*/ EQData::SpellCache       spellCache;//size 0x58
/*0x25e8*/ HashListSet<int, 0x80>   DoomEffectsBySlot;//size 0x10 + (0x80* 4)
/*0x27f8*/ UINT		LastHitEval;
/*0x27fc*/

EQLIB_OBJECT CharacterZoneClient::CharacterZoneClient();
EQLIB_OBJECT int CharacterZoneClient::CalcAffectChange(const EQ_Spell*spell, BYTE casterLevel, BYTE affextIndex, const EQ_Affect*theAffect, int EffectIndex = 0, PlayerZoneClient*pCaster = NULL, bool overrideChangeVal = false, int ChangeVal = -1, bool bCap = true);
EQLIB_OBJECT int CharacterZoneClient::CalcAffectChangeGeneric(const EQ_Spell*spell, BYTE casterLevel, BYTE affextIndex, const EQ_Affect*theAffect, int EffectIndex, bool bCap = true);
EQLIB_OBJECT void CharacterZoneClient::MakeMeVisible(int, bool);
EQLIB_OBJECT int CharacterZoneClient::GetItemCountWorn(int);
EQLIB_OBJECT int CharacterZoneClient::GetItemCountInInventory(int);
EQLIB_OBJECT int CharacterZoneClient::GetCursorItemCount(int);
EQLIB_OBJECT bool CharacterZoneClient::HasSkill(int);
EQLIB_OBJECT EQ_Affect*CharacterZoneClient::FindAffectSlot(int SpellID, PSPAWNINFO Caster, int*slindex, bool bJustTest, int CasterLevel = -1, EQ_Affect* BuffArray = NULL, int BuffArraySize = 0, bool bFailAltAbilities = true);
EQLIB_OBJECT EQ_Affect*CharacterZoneClient::FindAffectSlotMine(int SpellID, PSPAWNINFO Caster, int*slindex, bool bJustTest, int CasterLevel = -1, EQ_Affect* BuffArray = NULL, int BuffArraySize = 0, bool bFailAltAbilities = true);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT bool CharacterZoneClient::IsStackBlocked(const EQ_Spell*pSpell, PSPAWNINFO pCaster, EQ_Affect* pEffecs = NULL, int EffectsSize = 0, bool bMessageOn = false);
#else
EQLIB_OBJECT bool CharacterZoneClient::IsStackBlocked(const EQ_Spell*pSpell, PSPAWNINFO pCaster, EQ_Affect* pEffecs = NULL, int EffectsSize = 0);
#endif
EQLIB_OBJECT int CharacterZoneClient::BardCastBard(const EQ_Spell* pSpell, signed int caster_class) const;
EQLIB_OBJECT unsigned char CharacterZoneClient::GetMaxEffects() const;
EQLIB_OBJECT EQ_Affect & CharacterZoneClient::GetEffect(int) const;
EQLIB_OBJECT int CharacterZoneClient::GetOpenEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill, int Index = -1);
EQLIB_OBJECT int CharacterZoneClient::GetFirstEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill);
EQLIB_OBJECT int CharacterZoneClient::GetLastEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill, bool bIsDisplay = false);
EQLIB_OBJECT const int CharacterZoneClient::GetFocusReuseMod(const EQ_Spell*pSpell, VePointer<CONTENTS>&pOutItem);
EQLIB_OBJECT bool CharacterZoneClient::FindItemByGuid(const EqItemGuid& ItemGuid, int*pos_slot, int*con_slot);
EQLIB_OBJECT BYTE CharacterZoneClient::FindItemByRecord(int ItemNumber /*recordnum*/, int*pos_slot, int*con_slot, bool bReverseLookup);
};

enum EAreaCorner
{
	eAC_None			  = -1,
	eAC_TopLeftCorner     = 0,
	eAC_TopRightCorner    = 1,
	eAC_BottomLeftCorner  = 2,
	eAC_BottomRightCorner = 3,
};

//move on nothing to see here yet, work in progress - eqmule
class PcBase : virtual public CharacterBase
{
public:
	//*0x0008*/void*vfTable_CharacterZoneClient;
//*0x0008*/void*vfTable_CharacterBase;
//*0x000C*/void*vfTable_PcBase;
//last one changed 
/*0x000C*/ virtual void vftableph() {};
/*0x0010*/ TSafeArrayStatic<int, 0xa>	RecentTasks;
/*0x0038*/ TSafeArrayStatic<PCTaskStatus, 1>	Tasks;
/*0x00A8*/ TSafeArrayStatic<PCTaskStatus, 0x1d>	Quests;
/*0x0D58*/ TSafeArrayStatic<BYTE, 6400 / 8>	BitFlags;
/*0x1078*/ TSafeArrayStatic<BenefitSelection, 5> ActiveTributeBenefits;
/*0x10A0*/ TSafeArrayStatic<BenefitSelection, 10> ActiveTrophyTributeBenefits;
/*0x10f0*/ TSafeArrayStatic<BYTE, 0x320>	BitFlags2;
/*0x10f0*/ ItemBaseContainer	BankItems;//size 0x1c correct addr
/*0x110c*/ ItemBaseContainer	SharedBankItems;
/*0x1128*/ ItemBaseContainer	OverflowBufferItems;
/*0x1144*/ ItemBaseContainer	LimboBufferItems;
/*0x1160*/ ItemBaseContainer	MercenaryItems;
/*0x117c*/ ItemBaseContainer	MountKeyRingItems;
/*0x1198*/ ItemBaseContainer	IllusionKeyRingItems;
/*0x11b4*/ ItemBaseContainer	FamiliarKeyRingItems;
/*0x11d0*/ ItemBaseContainer	AltStorageItems;
/*0x11ec*/ ItemBaseContainer	ArchivedDeletedItems;
/*0x1208*/ ItemBaseContainer	MailItems;
/*0x1224*/ HashTable<MailItemData, EqItemGuid, ResizePolicyNoShrink> MailItemsData;//size 0x10
/*0x1234*/ TSafeArrayStatic<UINT, 1>	RecentMoves;
//fine to this point
/*0x1238*/ HashTable<DynamicZoneData>	CurrentDynamicZones;
/*0x1248*/ HashTable<int>	LearnedRecipes;	
/*0x1258*/ EQList<TradeskillRecipeCount*>	QualifyingRecipeCounts;
/*0x1268*/ HashTable<int>	NonrepeatableQuests;
/*0x1278*/ HashTable<int>	CompletedTasks;
/*0x1288*/ HashTable<int>	CompletedTasks2;
/*0x1298*/ UINT	AlchemyTimestamp;
/*0x129c*/ bool	bWhat;//it i a bool for sure...
/*0x12a0*/ bool	bSomethingHome;
/*0x12a4*/ DWORD	LoginTime;
/*0x12a8*/ int64_t      GuildID;//GuildID_0
/*0x12b0*/ int64_t		FellowshipID;
/*0x12b8*/ PFELLOWSHIPINFO pFellowship;
/*0x12bc*/ int			GuildStatus;
/*0x12c0*/ int			GuildFlags;
/*0x12c4*/ bool			GuildShowSprite;
/*0x12c8*/ UINT			CreationTime;
/*0x12cc*/ UINT			AccountCreationTime;
/*0x12d0*/ UINT			LastPlayedTime;
/*0x12d4*/ DWORD		MinutesPlayed;
/*0x12d8*/ BYTE			Anonymous;
/*0x12d9*/ bool			bGM;
/*0x12da*/ bool			bGMStealth;
/*0x12dc*/ DWORD        AAExp;
/*0x12e0*/ BYTE         NobilityRank;
/*0x12e1*/ BYTE         PercentEXPtoAA;
/*0x12e4*/ int			AirSupply;
/*0x12e8*/ int			SerialNum;
/*0x12ec*/ bool			bNewCharacter;
/*0x12f0*/ int			TasksAssigned;
/*0x12f4*/ int			TasksCompleted;
/*0x12f8*/ long			TaskRequestTimer;
/*0x12fc*/ unsigned int UniquePlayerID;
/*0x1300*/ WorldLocation	DynamicZoneSafeReturnLocation;//size 0x14
/*0x1314*/ DynamicZoneTimerData* pDZTimerRoot;
/*0x1318*/ DWORD        TributeTimer;
/*0x131c*/ DWORD        BenefitTimer;
/*0x1320*/ int64_t      CareerFavor;
/*0x1328*/ int64_t      CurrFavor;
/*0x1330*/ bool			bBenefitsActive;
/*0x1331*/ bool			bTrophyBenefitsActive;
/*0x1332*/ bool			bHasResetStartingCity;
/*0x1333*/ bool			bIsHeadStartCharacter;
/*0x1334*/ int			PvPKills;
/*0x1338*/ int			PvPDeaths;
/*0x133c*/ int			PvPCurrentPoints;
/*0x1340*/ int			PvPTotalPointsEarned;
/*0x1344*/ int			PvPKillStreak;
/*0x1348*/ int			PvPDeathStreak;
/*0x134c*/ int			PvPCurrentStreak;
/*0x1350*/ PvPKill		LastKill;//size 0x58
/*0x13a8*/ PvPDeath		LastDeath;//size 0x58
/*0x1400*/ HashTable<PvPKill24HourData>	PvPLast24HoursKillHash;
/*0x1410*/ int			PvPInfamyLevel;
/*0x1414*/ int			PvPVitality;
/*0x1418*/ UINT			PvPLastInfamyTime;
/*0x141c*/ int			LastLastNameChange;
/*0x1420*/ int			LastNameChangePriv;
/*0x1424*/ UINT			PvPLastVitalityTime;
/*0x1428*/ bool			bKeepItemsOnDeath;
/*0x1429*/ bool			bResetSpecializationSkills;
/*0x142c*/ int			CharityPointsAvailable;
/*0x1430*/ int			CharityTotalPointsEarned;
/*0x1434*/ int			GoodPointsAvailable;
/*0x1438*/ int			GoodTotalPointsEarned;
/*0x143c*/ int			EvilPointsAvailable;
/*0x1440*/ int			EvilTotalPointsEarned;
/*0x1444*/ bool			bCanRequestNameChange;
/*0x1445*/ bool			bCanRequestNameChange2;
/*0x1446*/ bool			bCanRequestServerTransfer;
/*0x1447*/ bool			bIsCopied;
/*0x1448*/ int			ServerTransferGrantTime;
/*0x144c*/ bool			bCanRequestRaceChange;
/*0x1450*/ UINT			LastAAResetTime;
/*0x1454*/ UINT			LastMercAAResetTime;
/*0x1458*/ EQZoneIndex	NewZoneID;
/*0x145c*/ int			NewAreaID;
/*0x1460*/ EAreaCorner	eNewAreaCorner;
/*0x1464*/ EQZoneIndex	PreviousZoneID;
/*0x1468*/ int			RealEstateZoneID;
/*0x146c*/ CHAR			ServerCreated[0x20];
/*0x1470*/ PCAdventureData	AdventureData;
/*0x14xx*/ PCSharedTaskData	SharedTaskData;
/*0x14xx*/ TaskTimerData*	pTaskTimerData;
/*0x14xx*/ PCQuestHistoryData	QuestHistoryData;
/*0x14xx*/ PCStatistics		PcStatistics;
/*0x1954*/ GroupMemberStats		GroupStats;//size 0x150 i think
/*0x1aa4*/ bool			bIsLfg;
/*0x1aa8*/ int64_t		RaidId;//could be int
/*0x1ab0*/ int64_t		GroupID;//could be int
/*0x1ab8*/ int64_t      Exp;//confirmed mar 7 2017 test
/*0x1ac0*/ int	        DaysEntitled;
/*0x1ac4*/ int	        SpentVeteranRewards;
/*0x1ac8*/ bool	        bVeteranRewardEntitled;
/*0x1ac9*/ bool	        bAutoConsentGroup;
/*0x1aca*/ bool	        bAutoConsentRaid;
/*0x1acb*/ bool	        bAutoConsentGuild;
/*0x1acc*/ bool	        bPrivateForEqPlayers;
/*0x1ad0*/ long	        AchievementFilesModificationTime;
/*0x1ad4*/ CHAR	        StationID[0x20];
/*0x1af8*/ EqGuid       Guid;//size 8 so it MUST start at a int64 sized address.. i.e. 0 or 8
/*0x1b00*/ bool	        bBetaBuffed;
/*0x1b04*/ int	        Unknown0x1ad4;
/*0x1b08*/ int	        StartingCity;
/*0x1b0c*/ int	        MainLevel;
/*0x1b10*/ bool	        bShowHelm;
/*0x1b18*/ int64_t      LastTestCopyTime;
/*0x1b20*/ CPlayerPointManager PointManager;//size 0x14
/*0x1b34*/ PointSystemBase PointSystem;
/*0x1B48*/ UINT			LoyaltyVelocity;
/*0x1B4c*/ UINT			LoyaltyTokens;
/*0x1B50*/ bool			bHasLoyaltyInfo;
/*0x1B54*/ ArrayClass_RO<int> OwnedRealEstates;
/*0x1B64*/ ArrayClass_RO<int> OwnedItemRealEstates;
/*0x1B74*/ ArrayClass_RO<int> ArchivedRealEstates;
/*0x1B84*/ CHAR			OverridePetName[0x40];
/*0x1Bc4*/ bool			bCanRequestPetNameChange;
/*0x1Bc5*/ CHAR			OverrideFamiliarName[0x40];
/*0x1c05*/ bool			bCanRequestFamiliarNameChange;
/*0x1c08*/ _CXSTR		*OverrideMercName[0xb];
/*0x1c34*/ bool			bCanRequestMercNameChange;
/*0x1c38*/ PendingRewardList PendingRewards;//size 0x2c must be at 1c28
/*0x1c64*/ UINT         DowntimeReductionTime;
/*0x1c68*/ UINT         DowntimeTimerStart;
/*0x1c6c*/ float        ActivityValue;
/*0x1c70*/ UINT         NextItemId;
/*0x1c74*/ _CXSTR      *SharedBank;
/*0x1c78*/ _CXSTR      *BankBuffer;
/*0x1c7c*/ _CXSTR      *OverflowBuffer;
/*0x1c80*/ _CXSTR      *LimboBuffer;
/*0x1c84*/ _CXSTR      *MercenaryBuffer;
/*0x1c88*/ _CXSTR      *KeyRingBuffer[3];
/*0x1c94*/ _CXSTR      *AltStorageBuffer;
/*0x1c98*/ UINT         AltStorageTimestamp;
/*0x1c9c*/ ELockoutCharacterReason LCR;
/*0x1ca0*/ HashTable<ProgressionExperience> ProgressionExp;//pretty sure its at 1c90
/*0x1cb0*/ PCXSTR       ArchivedStorageBuffer;
/*0x1cb4*/ PCXSTR       MailItemsBuffer;
/*0x1cb8*/ PCXSTR       MailItemsDataBuffer;
/*0x1cbc*/ int          MailItemsOverCapWarningCount;//1C88
/*0x1cc0*/ ItemIndex	StatKeyRingItemIndex[3];
/*0x1cd2*/ bool         UseAdvancedLooting;     //1cc2 confirmed mar 7 2017 test //0=off 1=on
/*0x1cd3*/ bool         MasterLootCandidate;	//0=off 1=on
/*0x1cd4*/ bool			bIsCorrupted;
/*0x1cd8*/ char*		pCorruptionReport;
/*0x1cdc*/ TString<0x100> InspectText;
/*0x1ddc*/ HashTable<int>		BlockedSpellsHash;
/*0x1dec*/ int			BlockedSpell[0x28];
/*0x1e8c*/ HashTable<int>		BlockedPetSpellsHash;
/*0x1e9c*/ int			BlockedPetSpell[0x28];
/*0x1f3c*/ ClaimDataCollection     ConsumableFeatures;//size 0x10
/*0x1f4c*/ bool		bGrantItemsRegistered;
/*0x1f50*/ uint64_t	CreatedGuildID;
/*0x1f58*/ UINT		GuildCreateTime;
/*0x1f5c*/ PCXSTR	GuildCreateCharacter;
/*0x1f60*/ bool	bInventoryUnserialized;
/*0x1f61*/ bool	bAltStorageUnserialized;
/*0x1f62*/ bool	bArchivedStorageUnserialized;
/*0x1f63*/ bool	bMailUnserialized;
/*0x1f64*/ bool	bPendingInventorySerialization;	
/*0x1f68*/ PCXSTR	BuyLines;
/*0x1f6c*/ ArrayClass_RO<PCXSTR>	OfflineTraderSoldItems;
/*0x1f7c*/ ArrayClass_RO<PCXSTR>	OfflineBuyerBoughtItems;
/*0x1f8c*/ UINT        Krono;//confirmed mar 7 2017 test
/*0x1f90*/ UINT        CursorKrono;
/*0x1f98*/ int64_t      MercAAExp;// divide this with 3.30f and you get the percent - eqmule
/*0x1fa0*/ DWORD        MercAAPoints;//number of unspent merc AA points
/*0x1fa4*/ DWORD        MercAAPointsSpent;//number of spent merc AA points
/*0x1fa8*/ ArrayClass_RO<MercenaryAbilityInfo*>	MercenaryAbilities;
/*0x1fb8*/ HashTable<CompletedAchievementData, int, ResizePolicyNoShrink> CompletedAchievements;
/*0x1fc8*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> CompletedEventBasedSubComponents;
/*0x1fd8*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> OpenEventBasedSubComponents;
/*0x1fe8*/ int		LastFellowshipJoin;
/*0x1ff0*/ int64_t      Vitality;
/*0x1ff8*/ int		    AAVitality;
/*0x1ffc*/ int		    Unknown0x1ffc;
/*0x2000*/ int          FPStuff[0x1c];
/*0x2070*/ //CharacterZoneClient
};
class DebugText
{
public:
	//virtual void vftableph() {};
	//void*vfTable_DebugText;
};
class PcZoneClient: public PcBase , public CharacterZoneClient , public DebugText
{
public:
/*0x245c*/ void*vfTable_PcZoneClient;
/*0x2460*/ TSafeArrayStatic<unsigned long, 3> Flags;//hmm
/*0x246C*/ uint32_t TransfersReceived;
/*0x2470*/ int	LastLanguageSpoken;
/*0x2474*/ int CurPowerSourceDrain;
/*0x2478*/ EQList<ALCHEMYBONUSSKILLDATA*> AlchemyBaseSkillBonusList;
/*0x2488*/ UINT MomentumBalance; 
/*0x248C*/ UINT LoyaltyRewardBalance;
/*0x2490*/

EQLIB_OBJECT int PcZoneClient::GetPcSkillLimit(int);
EQLIB_OBJECT bool PcZoneClient::HasCombatAbility(int);
EQLIB_OBJECT void PcZoneClient::RemovePetEffect(int);
EQLIB_OBJECT bool PcZoneClient::CanEquipItem(PCONTENTS*pCont, int slotid, bool bOutputDebug, bool bUseRequiredLevel);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT bool PcZoneClient::HasAlternateAbility(int aaindex, int*, bool, bool);
#else
EQLIB_OBJECT bool PcZoneClient::HasAlternateAbility(int aaindex, int*, bool);
#endif
EQLIB_OBJECT int PcZoneClient::GetCurrentMod(int index);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT int PcZoneClient::GetModCap(int index, bool bToggle=false);
#else
EQLIB_OBJECT int PcZoneClient::GetModCap(int index);
#endif
EQLIB_OBJECT void PcZoneClient::RemoveBuffEffect(int Index, int SpawnID);
EQLIB_OBJECT PCONTENTS* PcZoneClient::GetItemByID(PCONTENTS*contOut, int itemid, ItemIndex*itemindex/*out*/);
EQLIB_OBJECT PCONTENTS* PcZoneClient::GetItemByItemClass(PCONTENTS*contOut, int itemclass, ItemIndex*itemindex/*out*/);
EQLIB_OBJECT void PcZoneClient::BandolierSwap(int index);
EQLIB_OBJECT UINT PcZoneClient::GetLinkedSpellReuseTimer(int index);
};

class PcClient// : public PcZoneClient
{
	//has a vftable but we get it from PcZoneClient
public:
	PcClient::PcClient();
	BYTE Filler[0x2b10];
};
class tettt
{
/*0x2490*/ ExtendedTargetListClient* pXTargetMgr;
/*0x2494*/ bool bInCombat;
/*0x2498*/ UINT Downtime;
/*0x249c*/ UINT DowntimeStamp;
/*0x24a0*/ bool bOverrideAvatarProximity;
/*0x24a4*/ CGroupClient*pGroup;
/*0x24a8*/ bool bIAmCreatingGroup;
/*0x24AC*/ VeArray<VePointer<PCONTENTS>> ItemsPendingID;//size 0xc
/*0x24B8*/ eParcelStatus ParcelStatus;//24B8 for sure see 4F1184 in may 11 2017 live exe
/*0x24BC*/ int SubscriptionDays;//24BC for sure see 7A6C40 in may 11 2017 live exe
/*0x24C0*/ short BaseKeyRingSlots[3];
/*0x24c6*/ bool bPickZoneFewest;//for sure see 4A424A in may 11 2017 live exe
/*0x24c7*/ bool filler;//might not be needed: todo check
/*0x24c8*/
};

class EQPlayerManager
{
public:
EQLIB_OBJECT class EQPlayer*EQPlayerManager::GetSpawnByID(int);
EQLIB_OBJECT class EQPlayer*EQPlayerManager::GetSpawnByName(char*);
EQLIB_OBJECT class EQPlayer*EQPlayerManager::GetPlayerFromPartialName(char const*, class PlayerBase*);

EQLIB_OBJECT class EQPlayer*EQPlayerManager::GetSpawnByName2(CXStr*, int);
SPAWNMANAGER Data;
};

class EQPMInfo
{
public:
EQLIB_OBJECT EQPMInfo::~EQPMInfo();
EQLIB_OBJECT EQPMInfo::EQPMInfo(char*);
EQLIB_OBJECT void EQPMInfo::SetApplyGravity(bool);
};

class EqSoundManager
{
public:
EQLIB_OBJECT EqSoundManager::~EqSoundManager();
//EQLIB_OBJECT EqSoundManager::EqSoundManager(bool, bool, enum SpeakerType);
EQLIB_OBJECT bool EqSoundManager::EmitterLoad(char*);
EQLIB_OBJECT bool EqSoundManager::WaveIsPlaying(int);
EQLIB_OBJECT class SoundAsset* EqSoundManager::WaveGet(int);
//EQLIB_OBJECT enum EnvironmentType EqSoundManager::GetListenerEnvironment();
EQLIB_OBJECT void EqSoundManager::EmitterAdd(class EqEmitterData*);
EQLIB_OBJECT void EqSoundManager::EmitterSetIndoors(bool);
EQLIB_OBJECT void EqSoundManager::EmitterSetNight(bool);
EQLIB_OBJECT void EqSoundManager::EmitterSetRaining(bool);
EQLIB_OBJECT void EqSoundManager::EmitterSetUserDisabled(bool);
EQLIB_OBJECT void EqSoundManager::EmitterSetWind(bool);
EQLIB_OBJECT void EqSoundManager::GiveTime();
EQLIB_OBJECT void EqSoundManager::SetCurrentZone(char*);
EQLIB_OBJECT void EqSoundManager::SetEffectsLevel(float);
//EQLIB_OBJECT void EqSoundManager::SetListenerEnvironment(enum EnvironmentType);
EQLIB_OBJECT void EqSoundManager::SetListenerEnvironmentHigh();
EQLIB_OBJECT void EqSoundManager::SetListenerEnvironmentLow();
EQLIB_OBJECT void EqSoundManager::SetListenerEnvironmentOutside();
EQLIB_OBJECT void EqSoundManager::SetListenerLocation(float, float, float, float);
EQLIB_OBJECT void EqSoundManager::SetMixAhead(int);
EQLIB_OBJECT void EqSoundManager::SetMusicSelection(int, bool);
EQLIB_OBJECT void EqSoundManager::SetMusicVolume(float);
EQLIB_OBJECT void EqSoundManager::SetWaveVolume(float);
EQLIB_OBJECT void EqSoundManager::WaveLoad(char*, int, bool);
EQLIB_OBJECT void EqSoundManager::WavePlay(int, class SoundControl*);
EQLIB_OBJECT void EqSoundManager::WaveStop(int);
// private
EQLIB_OBJECT class SoundAsset* EqSoundManager::GetAsset(char*);
EQLIB_OBJECT class SoundAsset* EqSoundManager::OldMp3GetSelection(int);
EQLIB_OBJECT class SoundEmitter* EqSoundManager::CreateOldEmitter(int, float, float, float, int, int, int, float, int, int, int);
EQLIB_OBJECT int EqSoundManager::GetMusicId();
EQLIB_OBJECT void EqSoundManager::LoadGlobalEmitters();
EQLIB_OBJECT void EqSoundManager::LoadGlobalMusic();
EQLIB_OBJECT void EqSoundManager::LoadGlobalWaves();
EQLIB_OBJECT void EqSoundManager::LoadListOfWaveFiles(char**, int);
EQLIB_OBJECT void EqSoundManager::LoadOldEmitters();
EQLIB_OBJECT void EqSoundManager::OldMp3ClearSelections();
EQLIB_OBJECT void EqSoundManager::OldMp3Init();
EQLIB_OBJECT void EqSoundManager::OldMp3Terminate();
EQLIB_OBJECT void EqSoundManager::PlayScriptMp3(char*Name, float Vol = 1.00f);
EQLIB_OBJECT void EqSoundManager::ReleaseZoneSpecificEmitters();
EQLIB_OBJECT void EqSoundManager::ReleaseZoneSpecificMidi();
EQLIB_OBJECT void EqSoundManager::ReleaseZoneSpecificWaves();
EQLIB_OBJECT void EqSoundManager::UpdateEmitterStates();
	Mp3Manager*pMp3Manager;
	SoundManager*pSoundManager;
	EmitterManager*pEmitterManager;
	MusicManager*pMusicManager;
	SoundAsset*pGlobalMidiAsset;
	SoundAsset*pOpenerMidiAsset;
	SoundAsset*pOpenerMp3Asset;
	SoundAsset*pDeathMp3Asset;
	SoundAsset*pCombatMp3Asset;
	SoundAsset*pMerchantMp3Asset;
	SoundAsset*pZoneMidiAsset;
	SoundAsset*pScriptMp3Asset;
	bool bDisabled;
	int NextMusicID;
	SoundEmitter*pEmitters[1000];
	int EmittersCount;
	SoundEmitter*pRainEmitter;
	SoundEmitter*pWindEmitter;
	int EnvironmentHigh;
	int EnvironmentLow;
	int EnvironmentOutside;
	float fEffectsLevel;
	float fWaveVolumeLevel;
	//more here but i only need volume for now so...
};

class EQSwitch
{
public:
EQLIB_OBJECT EQSwitch::~EQSwitch();
EQLIB_OBJECT EQSwitch::EQSwitch(char*, bool);
EQLIB_OBJECT EQSwitch::EQSwitch(struct _EQClientSwitch*);
EQLIB_OBJECT EQSwitch::EQSwitch(struct OldDiskSwitch*, bool);
EQLIB_OBJECT float EQSwitch::GetCustomMoveDistance();
EQLIB_OBJECT float EQSwitch::TopSpeed(float*);
EQLIB_OBJECT int EQSwitch::GetSwitchDamage();
EQLIB_OBJECT unsigned char EQSwitch::SwitchIsNotUsable(int);
EQLIB_OBJECT unsigned char EQSwitch::SwitchWasOpened(int, int, class EQPlayer*, bool*);
EQLIB_OBJECT unsigned char EQSwitch::SwitchWasOpenedActual(int, int, class EQPlayer*, bool*);
EQLIB_OBJECT unsigned int EQSwitch::RepopFrequency();
EQLIB_OBJECT void EQSwitch::ChangeState(unsigned char, class EQPlayer*, bool);
EQLIB_OBJECT void EQSwitch::LoadSwitchSounds(int);
EQLIB_OBJECT void EQSwitch::PostInit();
EQLIB_OBJECT void EQSwitch::PreInit();
EQLIB_OBJECT void EQSwitch::RepopSwitch();
EQLIB_OBJECT void EQSwitch::ResetSwitchState(unsigned char);
EQLIB_OBJECT void EQSwitch::UseSwitch(UINT SpawnID, int KeyID, int PickSkill, const CVector3* hitloc = 0);
};

class EqSwitchManager
{
public:
EQLIB_OBJECT EqSwitchManager::~EqSwitchManager();
EQLIB_OBJECT EqSwitchManager::EqSwitchManager();
EQLIB_OBJECT class EQSwitch* EqSwitchManager::GetSwitch(int);
EQLIB_OBJECT class EQSwitch* EqSwitchManager::GetSwitchByActor(struct T3D_tagACTORINSTANCE*);
EQLIB_OBJECT class EQSwitch* EqSwitchManager::GetSwitchById(int, bool);
EQLIB_OBJECT int EqSwitchManager::GetCount();
EQLIB_OBJECT void EqSwitchManager::AddSwitch(class EQSwitch*);
EQLIB_OBJECT void EqSwitchManager::DeleteAll();
EQLIB_OBJECT void EqSwitchManager::Load(char*, bool);
// protected
EQLIB_OBJECT void EqSwitchManager::LoadOld(char*, bool);
};

class EQUtil
{
public:
EQLIB_OBJECT static char* __cdecl EQUtil::FormatCharName(char*, char*, int);
};

class EQWorldData
{
public:
EQLIB_OBJECT EQWorldData::EQWorldData();
EQLIB_OBJECT bool EQWorldData::GetGeometryNameFromIndex(EQZoneIndex, char*) const;
EQLIB_OBJECT bool EQWorldData::IsFlagSet(EQZoneIndex, unsigned long) const;
EQLIB_OBJECT bool EQWorldData::IsNewbieZone(EQZoneIndex) const;
EQLIB_OBJECT bool EQWorldData::IsNoAirZone(EQZoneIndex) const;
EQLIB_OBJECT bool EQWorldData::IsNoBindZone(EQZoneIndex) const;
EQLIB_OBJECT bool const EQWorldData::AddZone(enum EQExpansion, EQZoneIndex, char const*, char const*, int, unsigned long, int, int);
//EQLIB_OBJECT enum EQExpansion const EQWorldData::ExpansionZone(EQZoneIndex) const;
EQLIB_OBJECT DWORD EQWorldData::GetIndexFromZoneName(char const*); // EQZoneIndex
EQLIB_OBJECT int EQWorldData::GetMinLevel(EQZoneIndex) const;
EQLIB_OBJECT void EQWorldData::AdvanceTime(unsigned int);
EQLIB_OBJECT void EQWorldData::CurrentGameTime(char*);
EQLIB_OBJECT void EQWorldData::GetFullZoneName(EQZoneIndex, char*);
// virtual
EQLIB_OBJECT EQWorldData::~EQWorldData();
//EQLIB_OBJECT void* EQWorldData::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* EQWorldData::`vector deleting destructor'(unsigned int);
};

class EQZoneInfo
{
public:
EQLIB_OBJECT EQZoneInfo::EQZoneInfo(enum EQExpansion, EQZoneIndex, char const*, char const*, int, unsigned long, int, int);
// virtual
EQLIB_OBJECT EQZoneInfo::~EQZoneInfo();
//EQLIB_OBJECT void* EQZoneInfo::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* EQZoneInfo::`vector deleting destructor'(unsigned int);
};

class FilePath
{
public:
EQLIB_OBJECT FilePath::~FilePath();
EQLIB_OBJECT FilePath::FilePath(char const*);
EQLIB_OBJECT FilePath::FilePath(class SharedString const &);
EQLIB_OBJECT FilePath::FilePath();
};

class flex_unit
{
public:
EQLIB_OBJECT flex_unit::~flex_unit();
EQLIB_OBJECT flex_unit::flex_unit();
EQLIB_OBJECT unsigned int flex_unit::get(unsigned int) const;
EQLIB_OBJECT void flex_unit::clear();
EQLIB_OBJECT void flex_unit::fast_mul(class flex_unit &, class flex_unit &, unsigned int);
EQLIB_OBJECT void flex_unit::reserve(unsigned int);
EQLIB_OBJECT void flex_unit::set(unsigned int, unsigned int);
};

class GrammarRulesClass
{
public:
EQLIB_OBJECT GrammarRulesClass::GrammarRulesClass();
EQLIB_OBJECT char* GrammarRulesClass::Resolve(int, int, char*, char*);
// virtual
EQLIB_OBJECT GrammarRulesClass::~GrammarRulesClass();
//EQLIB_OBJECT void* GrammarRulesClass::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* GrammarRulesClass::`vector deleting destructor'(unsigned int);
// private
EQLIB_OBJECT char* GrammarRulesClass::Parse(char*);
EQLIB_OBJECT void GrammarRulesClass::RuleDe1(char*, char*);
EQLIB_OBJECT void GrammarRulesClass::RuleEn1(char*, char*);
EQLIB_OBJECT void GrammarRulesClass::RuleEn2(char*, char*);
EQLIB_OBJECT void GrammarRulesClass::RuleEn3(char*, char*, char*, char*);
EQLIB_OBJECT void GrammarRulesClass::RuleEn4(char*, char*, char*, char*);
EQLIB_OBJECT void GrammarRulesClass::RuleFr1(char*, char*, char*, char*);
EQLIB_OBJECT void GrammarRulesClass::RuleKo1(char*, char*, char*, char*);
};

class GuildMember
{
public:
EQLIB_OBJECT GuildMember::GuildMember();
};

enum eIconCacheType
{
	eit_Items,
	eit_Spells,
	eit_Menus,
	eit_Vivox,
};
class IconCache
{
public:
	HashTable<CTextureAnimation*>IconTextures;
	PCXSTR pAnimationName;
	int Offset;
	int MinValue;
	int MaxValue;
EQLIB_OBJECT IconCache::~IconCache();
EQLIB_OBJECT IconCache::IconCache();
EQLIB_OBJECT class CTextureAnimation* IconCache::GetIcon(int);
};



class JournalNPC
{
public:
EQLIB_OBJECT JournalNPC::~JournalNPC();
EQLIB_OBJECT JournalNPC::JournalNPC();
EQLIB_OBJECT int JournalNPC::AddEntry(long, float, float, float, char*, int);
EQLIB_OBJECT int JournalNPC::AddEntry(long, float, float, float, int, int);
EQLIB_OBJECT int JournalNPC::DeleteEntryByHash(int);
EQLIB_OBJECT int JournalNPC::DeleteEntryByIndex(int);
EQLIB_OBJECT int JournalNPC::FindThisText(char*, bool, int);
EQLIB_OBJECT int JournalNPC::ReadEntry(struct _iobuf*);
EQLIB_OBJECT static char* __cdecl JournalNPC::GetText(int);
EQLIB_OBJECT struct JournalEntry* JournalNPC::FindEntryByCategory(int, int);
EQLIB_OBJECT struct JournalEntry* JournalNPC::FindEntryByHash(int);
EQLIB_OBJECT struct JournalEntry* JournalNPC::GetEntry(int);
EQLIB_OBJECT void JournalNPC::ConvertCategory(int, int);
// private
EQLIB_OBJECT void JournalNPC::AllocateArray();
EQLIB_OBJECT void JournalNPC::CleanEntries();
EQLIB_OBJECT void JournalNPC::ComputeLatestTime();
};

class KeyCombo
{
public:
EQLIB_OBJECT KeyCombo::KeyCombo(int);
inline EQLIB_OBJECT KeyCombo::KeyCombo(unsigned char keycode, bool alt, bool ctrl, bool shift)
{    
    Data[3]= keycode;
    Data[0]=alt;
    Data[1]=ctrl;
    Data[2]=shift;
}
EQLIB_OBJECT KeyCombo::KeyCombo(unsigned int, unsigned int, bool, bool, bool);
inline EQLIB_OBJECT KeyCombo::KeyCombo()
{
   *(unsigned long*)&Data[0]=0;
}
inline void EQLIB_OBJECT KeyCombo::Clear()
{
   *(unsigned long*)&Data[0]=0;
}
EQLIB_OBJECT int KeyCombo::operator int() const;
EQLIB_OBJECT bool KeyCombo::GetPrintableLetter(unsigned short*) const;
inline EQLIB_OBJECT bool KeyCombo::UsesAlt() const
{
    return (Data[0]!=0);
}
inline EQLIB_OBJECT bool KeyCombo::UsesCtrl() const
{
    return (Data[1]!=0);
}
inline EQLIB_OBJECT bool KeyCombo::UsesShift() const
{
    return (Data[2]!=0);
}
EQLIB_OBJECT class CXStr KeyCombo::GetTextDescription() const;
EQLIB_OBJECT class KeyCombo const & KeyCombo::operator=(int);
inline EQLIB_OBJECT int KeyCombo::operator==(class KeyCombo const &Combo)
{
    return ((*(unsigned long*)&Data)==(*(unsigned long*)&Combo.Data));
}
inline EQLIB_OBJECT unsigned int KeyCombo::GetKey() const
{
    return Data[3];
}
// private
EQLIB_OBJECT bool KeyCombo::GetPrintableLetterFromScanCode(unsigned char, bool, bool, unsigned short*) const;
EQLIB_OBJECT bool KeyCombo::GetPrintableLetterFromVirtualKey(unsigned int, unsigned int, bool, bool, unsigned short*) const;
EQLIB_OBJECT bool KeyCombo::GetScanCodeFromVirtualKey(unsigned int, unsigned int, unsigned char*) const;
EQLIB_OBJECT bool KeyCombo::GetVirtualKeyFromScanCode(unsigned char, int*) const;
    unsigned char Data[4];
};

class KeypressHandler
{
public:
EQLIB_OBJECT static KeypressHandler &KeypressHandler::Get();
EQLIB_OBJECT KeypressHandler::~KeypressHandler();
EQLIB_OBJECT KeypressHandler::KeypressHandler();
EQLIB_OBJECT bool KeypressHandler::AttachAltKeyToEqCommand(class KeyCombo const &, unsigned int);
EQLIB_OBJECT bool KeypressHandler::AttachKeyToEqCommand(class KeyCombo const &, unsigned int);
EQLIB_OBJECT bool KeypressHandler::HandleKeyDown(class KeyCombo const &);
EQLIB_OBJECT bool KeypressHandler::HandleKeyUp(class KeyCombo const &);
EQLIB_OBJECT class KeyCombo const & KeypressHandler::GetAltKeyAttachedToEqCommand(unsigned int) const;
EQLIB_OBJECT class KeyCombo const & KeypressHandler::GetKeyAttachedToEqCommand(unsigned int) const;
EQLIB_OBJECT void KeypressHandler::ResetKeysToEqDefaults();
// private
EQLIB_OBJECT bool KeypressHandler::IsReservedKey(class KeyCombo const &) const;
EQLIB_OBJECT bool KeypressHandler::LoadAndConvertOldKeymappingFormat(unsigned int, int, class KeyCombo*);
EQLIB_OBJECT bool KeypressHandler::LoadKeymapping(unsigned int, int, class KeyCombo*);
EQLIB_OBJECT bool KeypressHandler::MapKeyToEqCommand(class KeyCombo const &, int, unsigned int);
EQLIB_OBJECT class CXStr KeypressHandler::GetEqCommandSaveName(unsigned int, int) const;
EQLIB_OBJECT void KeypressHandler::ClearCommandStateArray();
EQLIB_OBJECT void KeypressHandler::LoadAndSetKeymappings();
EQLIB_OBJECT void KeypressHandler::SaveKeymapping(unsigned int, class KeyCombo const &, int);
/*0x000*/   class KeyCombo NormalKey[nEQMappableCommands];
/*0x2 4*/   class KeyCombo AltKey[nEQMappableCommands];
/*0x5C8*/    char CommandState[nEQMappableCommands];
};

class LogicalPacket
{
public:
EQLIB_OBJECT LogicalPacket::LogicalPacket();
// virtual
EQLIB_OBJECT bool LogicalPacket::IsInternalPacket() const;
EQLIB_OBJECT int LogicalPacket::GetRefCount() const;
EQLIB_OBJECT void LogicalPacket::AddRef() const;
EQLIB_OBJECT void LogicalPacket::Release() const;
// protected
EQLIB_OBJECT virtual LogicalPacket::~LogicalPacket();
//EQLIB_OBJECT virtual void* LogicalPacket::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void* LogicalPacket::`vector deleting destructor'(unsigned int);
};

typedef struct _ItemFilterData
{
    int	Types;
    int	ID;
    int	Icon;
    char Name[0x40];
}ItemFilterData,*PItemFilterData;

class LootFiltersManager
{
public:
EQLIB_OBJECT bool LootFiltersManager::AddItemLootFilter(int ItemID, int IconID, const char* ItemName, int FilterTypes, bool bFromFile = false);
EQLIB_OBJECT const PItemFilterData GetItemFilterData(int ItemID);
EQLIB_OBJECT bool LootFiltersManager::RemoveItemLootFilter(int ItemID, int FilterTypes);
EQLIB_OBJECT bool LootFiltersManager::SetItemLootFilter(int ItemID, int IconID, const char* ItemName, int FilterTypes, bool bKeepRndSetting, bool bScrollToIt);
};
class MercenaryAbilityReq
{
public:    
    int ReqGroupID;
    int ReqGroupRank;
};
class MercenaryAbilitiesData
{
public:
	int AbilityID;
	int nName;
	int nDesc;
	int	Cost;
	int GroupID;
	int	GroupRank;
	int	Type;
	int	MinPlayerLevel;//min level to purchase...
	int RequirementAssociationID;
	int Refund;
	int BetaOnly;  
	int QuestAbility;
    ArrayClass<MercenaryAbilityReq> AbilityReqs;
};
class MercenaryAlternateAdvancementManagerClient
{
public:
	static MercenaryAlternateAdvancementManagerClient &MercenaryAlternateAdvancementManagerClient::Instance();
	HashList<int, 5> MercenaryTypes;
	HashList<MercenaryAbilitiesData, 0x40> MercenaryAbilities;
    HashList<int, 0x40> MercenaryAbilitiesByGroupID;
	HashList<int, 0x40> MercenaryAbilitiesOwnedByGroupID;
	HashList<HashList<int, 0x10>, 0x40> MercenaryAbilityGroups; 
};
class EQSpellStrings
{
public:
	char* EQSpellStrings::GetString(int SpellID, int StrIndex);
};
class MapViewMap
{
public:
EQLIB_OBJECT MapViewMap::~MapViewMap();
EQLIB_OBJECT MapViewMap::MapViewMap();
EQLIB_OBJECT bool MapViewMap::DrawClippedLine(struct T3D_XYZ*, struct T3D_RGB, class CXRect);
EQLIB_OBJECT bool MapViewMap::IsLayerVisible(int);
EQLIB_OBJECT bool MapViewMap::LoadEx(char*, int);
EQLIB_OBJECT bool MapViewMap::PointInMapViewArea(class CXPoint, class CXRect);
EQLIB_OBJECT int MapViewMap::GetMaxZ();
EQLIB_OBJECT int MapViewMap::GetMinZ();
EQLIB_OBJECT unsigned long MapViewMap::GetCurrentColor();
EQLIB_OBJECT unsigned long MapViewMap::GetMarkedLineColor();
EQLIB_OBJECT void MapViewMap::AddLabel(float, float, float, unsigned long, int, char*);
EQLIB_OBJECT void MapViewMap::AddPoint(float, float, float);
EQLIB_OBJECT void MapViewMap::CalcLabelRenderOffsets(class CXRect);
EQLIB_OBJECT void MapViewMap::Clear();
EQLIB_OBJECT void MapViewMap::ClearActiveLayer();
EQLIB_OBJECT void MapViewMap::Draw(class CXRect);
EQLIB_OBJECT void MapViewMap::EndLine(float, float, float);
EQLIB_OBJECT void MapViewMap::JoinLinesAtIntersect(bool);
EQLIB_OBJECT void MapViewMap::Load(char*);
EQLIB_OBJECT void MapViewMap::MoveLabel(struct _mapviewlabel*, float, float, float);
EQLIB_OBJECT void MapViewMap::PreCalcRenderValues();
EQLIB_OBJECT void MapViewMap::RecalcLabelExtents(struct _mapviewlabel*);
EQLIB_OBJECT void MapViewMap::RemoveLabel(struct _mapviewlabel*);
EQLIB_OBJECT void MapViewMap::RemoveLabel();
EQLIB_OBJECT void MapViewMap::RemoveLine(struct _mapviewline*);
EQLIB_OBJECT void MapViewMap::RemoveLine();
EQLIB_OBJECT void MapViewMap::Save(char*);
EQLIB_OBJECT void MapViewMap::SaveEx(char*, int);
EQLIB_OBJECT void MapViewMap::SetCurrentColor(unsigned long);
EQLIB_OBJECT void MapViewMap::SetMarkedLine(struct _mapviewline*);
EQLIB_OBJECT void MapViewMap::SetMarkedLineColor(unsigned long);
EQLIB_OBJECT void MapViewMap::SetZoneExtents(int, int, int, int);
EQLIB_OBJECT void MapViewMap::SetZoom(float);
EQLIB_OBJECT void MapViewMap::StartLine(float, float, float);
EQLIB_OBJECT void MapViewMap::TransformPoint(struct T3D_XYZ*);
};

class MemoryPoolManager
{
public:
EQLIB_OBJECT MemoryPoolManager::~MemoryPoolManager();
EQLIB_OBJECT MemoryPoolManager::MemoryPoolManager();
EQLIB_OBJECT void* MemoryPoolManager::Alloc(int);
EQLIB_OBJECT void MemoryPoolManager::Free(void*);
};

class MidiInstance
{
public:
EQLIB_OBJECT MidiInstance::MidiInstance(class SoundManager*);
// virtual
EQLIB_OBJECT bool MidiInstance::GiveTime();
EQLIB_OBJECT enum InstanceType MidiInstance::GetType();
EQLIB_OBJECT void MidiInstance::AdjustVolume(float, int);
EQLIB_OBJECT void MidiInstance::GuaranteeStopped();
EQLIB_OBJECT void MidiInstance::Move(float, float, float);
EQLIB_OBJECT void MidiInstance::Play(class SoundControl*);
// protected
EQLIB_OBJECT virtual MidiInstance::~MidiInstance();
//EQLIB_OBJECT virtual void* MidiInstance::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void* MidiInstance::`vector deleting destructor'(unsigned int);
};

class monty
{
public:
EQLIB_OBJECT monty::~monty();
EQLIB_OBJECT monty::monty(class vlong const &);
EQLIB_OBJECT class vlong monty::exp(class vlong const &, class vlong const &);
// private
EQLIB_OBJECT void monty::mul(class vlong &, class vlong const &);
};

class Mp3Manager
{
public:
EQLIB_OBJECT Mp3Manager::~Mp3Manager();
//EQLIB_OBJECT Mp3Manager::Entry::~Entry();
//EQLIB_OBJECT Mp3Manager::Entry::Entry(char*, char*, int, int);
EQLIB_OBJECT Mp3Manager::Mp3Manager(class SoundManager*, class MusicManager*);
EQLIB_OBJECT char* Mp3Manager::GetName(int);
//EQLIB_OBJECT enum Mp3Manager::SortOrder Mp3Manager::GetSort();
//EQLIB_OBJECT enum StreamingStatus Mp3Manager::Status();
EQLIB_OBJECT float Mp3Manager::GetVolumeLevel();
EQLIB_OBJECT int Mp3Manager::Add(char*);
EQLIB_OBJECT int Mp3Manager::Count();
EQLIB_OBJECT int Mp3Manager::GetPosition();
EQLIB_OBJECT int Mp3Manager::GetSongLength();
EQLIB_OBJECT int Mp3Manager::GetSongPosition();
EQLIB_OBJECT void Mp3Manager::Back();
EQLIB_OBJECT void Mp3Manager::Delete(int);
EQLIB_OBJECT void Mp3Manager::DeleteAll();
EQLIB_OBJECT void Mp3Manager::GiveTime();
EQLIB_OBJECT void Mp3Manager::Next();
EQLIB_OBJECT void Mp3Manager::Pause();
EQLIB_OBJECT void Mp3Manager::Play();
EQLIB_OBJECT void Mp3Manager::SaveList(char*);
EQLIB_OBJECT void Mp3Manager::SetPosition(int);
EQLIB_OBJECT void Mp3Manager::SetSongPosition(int);
EQLIB_OBJECT void Mp3Manager::SetVolumeLevel(float);
//EQLIB_OBJECT void Mp3Manager::Sort(enum Mp3Manager::SortOrder);
EQLIB_OBJECT void Mp3Manager::Stop();
// private
EQLIB_OBJECT int Mp3Manager::InternalAdd(char*, char*, int);
};

class MusicManager
{
public:
EQLIB_OBJECT MusicManager::~MusicManager();
//EQLIB_OBJECT MusicManager::MusicEntry::~MusicEntry();
//EQLIB_OBJECT MusicManager::MusicEntry::MusicEntry(int, class SoundAsset*, int, float, int, int, int, int, int, int);
EQLIB_OBJECT MusicManager::MusicManager();
EQLIB_OBJECT void MusicManager::Clear(class SoundAsset*);
EQLIB_OBJECT void MusicManager::Clear(int);
EQLIB_OBJECT void MusicManager::Enable(bool);
EQLIB_OBJECT void MusicManager::GiveTime();
//EQLIB_OBJECT void MusicManager::MusicEntry::AdjustVolume(float);
//EQLIB_OBJECT void MusicManager::MusicEntry::FadeIn(float);
//EQLIB_OBJECT void MusicManager::MusicEntry::FadeOut(bool);
EQLIB_OBJECT void MusicManager::Play(int);
EQLIB_OBJECT void MusicManager::Set(int, class SoundAsset*, int, float, int, int, int, int, int, int);
EQLIB_OBJECT void MusicManager::SetVolumeLevel(float);
EQLIB_OBJECT void MusicManager::Stop(int);
};

class PacketPacker
{
public:
EQLIB_OBJECT void PacketPacker::Disassociate();
EQLIB_OBJECT void PacketPacker::Flush();
EQLIB_OBJECT void PacketPacker::SendPacket(uint32_t, void*, int, bool);
EQLIB_OBJECT void PacketPacker::SendStatUpdate(struct _statUpdate*, bool);
// private
//EQLIB_OBJECT void PacketPacker::AddPacketToBuffer(struct PacketPacker::PacketBuffer*, uint32_t, void*, int);
//EQLIB_OBJECT void PacketPacker::FlushBuffer(struct PacketPacker::PacketBuffer*);
EQLIB_OBJECT void PacketPacker::FlushPositions();
EQLIB_OBJECT void PacketPacker::ScheduleUs();
};

class PacketPackerManager
{
public:
EQLIB_OBJECT static bool __cdecl PacketPackerManager::UnpackGetFirst(struct PacketPackerState*, uint32_t, unsigned char*, int);
EQLIB_OBJECT static bool __cdecl PacketPackerManager::UnpackGetNext(struct PacketPackerState*);
EQLIB_OBJECT static void __cdecl PacketPackerManager::Initialize();
EQLIB_OBJECT void PacketPackerManager::RemovePacker(class PacketPacker*);
EQLIB_OBJECT void PacketPackerManager::SetPriority(class PacketPacker*, int64_t);
// private
EQLIB_OBJECT static int* PacketPackerManager::sKnownSize;
};

class PackFile
{
public:
EQLIB_OBJECT PackFile::~PackFile();
EQLIB_OBJECT int PackFile::length() const;
EQLIB_OBJECT int PackFile::read(void* const, int);
EQLIB_OBJECT void PackFile::close();
};

class PackFS
{
public:
EQLIB_OBJECT PackFS::PackFS();
EQLIB_OBJECT bool PackFS::addFileSystem(class FilePath);
EQLIB_OBJECT bool PackFS::openFile(class FilePath, class PackFile*) const;
EQLIB_OBJECT void PackFS::removeFileSystem(class FilePath);
};

class PooledLogicalPacket
{
public:
EQLIB_OBJECT PooledLogicalPacket::PooledLogicalPacket(class UdpManager*, int);
// virtual
EQLIB_OBJECT int PooledLogicalPacket::GetDataLen() const;
EQLIB_OBJECT void* PooledLogicalPacket::GetDataPtr();
EQLIB_OBJECT void PooledLogicalPacket::AddRef() const;
EQLIB_OBJECT void PooledLogicalPacket::Release() const;
EQLIB_OBJECT void PooledLogicalPacket::SetDataLen(int);
EQLIB_OBJECT void const* PooledLogicalPacket::GetDataPtr() const;
// protected
EQLIB_OBJECT virtual PooledLogicalPacket::~PooledLogicalPacket();
//EQLIB_OBJECT virtual void* PooledLogicalPacket::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void* PooledLogicalPacket::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void PooledLogicalPacket::SetData(void const*, int, void const*, int);
};

class public_key
{
public:
EQLIB_OBJECT public_key::~public_key();
EQLIB_OBJECT public_key::public_key();
EQLIB_OBJECT class vlong public_key::encrypt(class vlong &);
};

class SAmpersandEntry
{
public:
EQLIB_OBJECT SAmpersandEntry::~SAmpersandEntry();
EQLIB_OBJECT SAmpersandEntry::SAmpersandEntry(class CXStr, char);
};

class SFormattedText
{
public:
EQLIB_OBJECT SFormattedText::~SFormattedText();
EQLIB_OBJECT SFormattedText::SFormattedText();
//EQLIB_OBJECT void* SFormattedText::`vector deleting destructor'(unsigned int);
};

class ShareBase
{
public:
EQLIB_OBJECT void ShareBase::removeRef();
// virtual
EQLIB_OBJECT ShareBase::~ShareBase();
};

class SharedString
{
public:
EQLIB_OBJECT SharedString::~SharedString();
EQLIB_OBJECT SharedString::SharedString(char const*);
EQLIB_OBJECT class SharedString & SharedString::operator=(class SharedString const &);
// protected
EQLIB_OBJECT void SharedString::_updateTag() const;
};

class SHistoryElement
{
public:
EQLIB_OBJECT SHistoryElement::~SHistoryElement();
EQLIB_OBJECT SHistoryElement::SHistoryElement();
//EQLIB_OBJECT void* SHistoryElement::`vector deleting destructor'(unsigned int);
};

class SimpleLogicalPacket
{
public:
EQLIB_OBJECT SimpleLogicalPacket::SimpleLogicalPacket(void const*, int);
// virtual
EQLIB_OBJECT int SimpleLogicalPacket::GetDataLen() const;
EQLIB_OBJECT void* SimpleLogicalPacket::GetDataPtr();
EQLIB_OBJECT void SimpleLogicalPacket::SetDataLen(int);
EQLIB_OBJECT void const* SimpleLogicalPacket::GetDataPtr() const;
// protected
EQLIB_OBJECT virtual SimpleLogicalPacket::~SimpleLogicalPacket();
//EQLIB_OBJECT virtual void* SimpleLogicalPacket::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void* SimpleLogicalPacket::`vector deleting destructor'(unsigned int);
};

class SListWndCellEditUpdate
{
public:
EQLIB_OBJECT SListWndCellEditUpdate::~SListWndCellEditUpdate();
};

#if !defined(ROF2EMU) && !defined(UFEMU)
class SListWndSortInfo
{
public:
/*0x00*/ int SortCol;
/*0x04*/ const SListWndLine&	ListWndLine1;
/*0x08*/ PCXSTR	StrLabel1;//for sure
/*0x10*/ uint64_t Data1;
/*0x18*/ const SListWndLine&	ListWndLine2;
/*0x1c*/ PCXSTR StrLabel2;//for sure
/*0x20*/ uint64_t Data2;
/*0x28*/ int SortResult;//for sure
/*0x2c*/ 
EQLIB_OBJECT SListWndSortInfo::~SListWndSortInfo();
};
#else
class SListWndSortInfo
{
public:
/*0x00*/ int SortCol;
/*0x04*/ const SListWndLine&	ListWndLine1;
/*0x08*/ PCXSTR	StrLabel1;
/*0x0c*/ uint32_t Data1;
/*0x10*/ const SListWndLine&	ListWndLine2;
/*0x14*/ PCXSTR StrLabel2;
/*0x18*/ uint32_t Data2;
/*0x1c*/ int SortResult;
/*0x20*/ 
EQLIB_OBJECT SListWndSortInfo::~SListWndSortInfo();
};
#endif

class SoundAsset
{
public:
EQLIB_OBJECT SoundAsset::SoundAsset(class SoundManager*, char*, char*, int);
EQLIB_OBJECT bool SoundAsset::IsPlaying();
EQLIB_OBJECT char* SoundAsset::GetName();
EQLIB_OBJECT class SoundInstance* SoundAsset::Play(class SoundControl*);
//EQLIB_OBJECT enum AssetType SoundAsset::GetType();
EQLIB_OBJECT void SoundAsset::AdjustVolume(float, int);
EQLIB_OBJECT void SoundAsset::GiveTime();
EQLIB_OBJECT void SoundAsset::Stop();
// protected
EQLIB_OBJECT virtual SoundAsset::~SoundAsset();
//EQLIB_OBJECT virtual void* SoundAsset::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void* SoundAsset::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void SoundAsset::YourManagerDeleted();
};

class SoundControl
{
public:
EQLIB_OBJECT SoundControl::SoundControl();
};

class SoundEmitter
{
public:
EQLIB_OBJECT SoundEmitter::SoundEmitter(class EmitterManager*, class MusicManager*, int);
EQLIB_OBJECT SoundEmitter::SoundEmitter(class EmitterManager*, class SoundAsset*, int);
EQLIB_OBJECT void SoundEmitter::Enable(bool);
EQLIB_OBJECT void SoundEmitter::GiveTime();
EQLIB_OBJECT void SoundEmitter::Move(float, float, float);
EQLIB_OBJECT void SoundEmitter::SetAsset(class SoundAsset*);
// protected
EQLIB_OBJECT virtual SoundEmitter::~SoundEmitter();
//EQLIB_OBJECT virtual void* SoundEmitter::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void* SoundEmitter::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void SoundEmitter::Init();
EQLIB_OBJECT void SoundEmitter::ReleaseLoopingSound();
EQLIB_OBJECT void SoundEmitter::ResetTimer();
};

class SoundInstance
{
public:
EQLIB_OBJECT SoundInstance::SoundInstance(class SoundManager*);
// virtual
EQLIB_OBJECT void SoundInstance::SetPoolNumber(int);
EQLIB_OBJECT void SoundInstance::SetSoundAsset(class SoundAsset*);
// protected
EQLIB_OBJECT virtual SoundInstance::~SoundInstance();
//EQLIB_OBJECT virtual void* SoundInstance::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void* SoundInstance::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void SoundInstance::YourManagerDeleted();
};

class SoundManager
{
public:
EQLIB_OBJECT SoundManager::~SoundManager();
//EQLIB_OBJECT SoundManager::SoundManager(int, int, bool, int, int, bool, enum SpeakerType);
EQLIB_OBJECT class SoundAsset* SoundManager::AssetGet(char*);
//EQLIB_OBJECT class SoundInstance* SoundManager::BorrowInstance(enum InstanceType, int);
//EQLIB_OBJECT enum EnvironmentType SoundManager::GetListenerEnvironment();
//EQLIB_OBJECT enum StreamingStatus SoundManager::StreamingStatus();
EQLIB_OBJECT float SoundManager::StreamingGetVolumeLevel();
EQLIB_OBJECT int SoundManager::StreamingGetSongLength();
EQLIB_OBJECT int SoundManager::StreamingGetSongPosition();
//EQLIB_OBJECT void SoundManager::AddPool(enum InstanceType, int, int);
EQLIB_OBJECT void SoundManager::GetListenerLocation(float*, float*, float*, float*);
EQLIB_OBJECT void SoundManager::GiveTime();
EQLIB_OBJECT void SoundManager::ReturnInstance(class SoundInstance*);
//EQLIB_OBJECT void SoundManager::SetListenerEnvironment(enum EnvironmentType);
EQLIB_OBJECT void SoundManager::SetListenerLocation(float, float, float, float);
EQLIB_OBJECT void SoundManager::SetMixAhead(int);
EQLIB_OBJECT void SoundManager::StreamingPause();
EQLIB_OBJECT void SoundManager::StreamingPlay(char*);
EQLIB_OBJECT void SoundManager::StreamingSetSongPosition(int);
EQLIB_OBJECT void SoundManager::StreamingSetVolumeLevel(float);
EQLIB_OBJECT void SoundManager::StreamingStop();
// protected
EQLIB_OBJECT void SoundManager::AssetAdd(class SoundAsset*);
EQLIB_OBJECT void SoundManager::AssetGiveTime();
EQLIB_OBJECT void SoundManager::AssetRemove(class SoundAsset*);
};

class SoundObject
{
public:
EQLIB_OBJECT SoundObject::SoundObject();
EQLIB_OBJECT void SoundObject::AddRef();
EQLIB_OBJECT void SoundObject::Release();
// protected
EQLIB_OBJECT virtual SoundObject::~SoundObject();
//EQLIB_OBJECT virtual void* SoundObject::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void* SoundObject::`vector deleting destructor'(unsigned int);
};

class SParseVariables
{
public:
EQLIB_OBJECT SParseVariables::~SParseVariables();
};
class FileStatMgr
{
public:
	struct FileStat
	{
		struct _stat32	Stats;
		PCXSTR			Filename;
		PCXSTR			Key;
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
	//there are like 72 more of these I dont have time to add them all now.
};
class RequirementAssociationManager : public FileStatMgr
{
public:
	PVOID vfTable;
	HashTable<HashTable<DoublyLinkedList<int>*>*> Requirements;
	char AssocFilename[512];
	ReqType LastFailReason;
	int LastFailGroupID;
	int LastFailReqID;
};
class SpellRequirementAssociationManager : public RequirementAssociationManager
{
public:
	HashList<HashList<HashList<int, 10>, 10>, 1000> ReqAssData;
};

typedef struct _EQRGB
{
	BYTE Red;
	BYTE Green;
	BYTE Blue;
} EQRGB;
struct StageType
{
    CHAR BlitSprite[3][0x20];
    CHAR AttachTag[0x20];
    int DAGnum[3];
    int pcloud[3];
    CHAR SpriteTAG[0xc][0x20];
    int SpritEffect;
    int SoundNum;
    ARGBCOLOR Tint[3];
    float Gravity[3];
    float NormalX1;
    float NormalY1;
    float NormalZ1;
    float NormalX2;
    float NormalY2;
    float NormalZ2;
	float NormalX3;
    float NormalY3;
    float NormalZ3;
    float Radius[3];
    float Angle[3];
    ULONG Lifespan[3];
    float Velocity[3];
    ULONG Rate[3];
    float Scale[3];
    EQRGB SpriteRGB[0xc];
    float RollRate[0xc];
    short HdgOffset[0xc];
    short PitchOffset[0xc];
    float Distance[0xc];
    short EffectType[12];
    float ScaleFactor[12];
};
struct OldSpellEffect
{
	int Tgts;
	int Perm;
	StageType stages[3];
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

typedef struct _SpellEffectEmitter {
    int DefIndex;
    int RequiredLevel;
    EEffectActor EffectActor;
    EAttachPoint AttachPoint;
} SpellEffectEmitter,*PSpellEffectEmitter;

typedef struct _SpellEffectStage
{
	int SoundNum;
    SpellEffectEmitter Emitters[4];
} SpellEffectStage,*PSpellEffectStage;

typedef struct _NewSpellEffect
{
    char szSpellEffectName[0x40];
	SpellEffectStage Stages[3];
} NewSpellEffect,*PNewSpellEffect;

class EQSpellExtra
{
public:
	OldSpellEffect*OldSpellEff;
	NewSpellEffect*NewSpellEff;
};
//Matching stack group ID rules
enum ESpellStackingRules
{
	ESSR_None, //default
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
//really would like to get this to work and align
//but its kinda complicated, maybe another day.
class SpellManager : public FileStatMgr
{
public:

/*0x000000*/ PVOID vfTable;
/*0x000004*/ int SpellsCrc32[TOTAL_SPELL_COUNT+1];
/*0x03A988*/ PSPELL MissingSpell;
/*0x03A98c*/ PSPELLCALCINFO* MissingSpellAffect;
/*0x03A990*/ PSPELLCALCINFO* MissingSpellAffectAC;
/*0x03A994*/ int MissingSpellCrc32;
/*0x03A998*/ int SpellFileCRC;
/*0x03A99c*/ int SpellAssocFileCRC;
/*0x03A9A0*/ int SpellStackingFileCRC;
/*0x03A9A4*/ SpellRequirementAssociationManager ReqAssocManager;
/*0x03BB8C not sure*/ HashTable<int, int, ResizePolicyNoShrink> SpellGroups;
/*0x03BB9C*/

/*0x00*/ EQLIB_OBJECT SpellManager::SpellManager(char*);
EQLIB_OBJECT const EQ_Spell* SpellManager::GetSpellByGroupAndRank(int Group, int SubGroup, int Rank = -1, bool bLesserRanksOk = false);
};
class ClientSpellManager : public SpellManager
{
public:
/*0x00*/ EQLIB_OBJECT int ClientSpellManager::dSpellManager(void*, bool);
/*0x04*/ EQLIB_OBJECT bool ClientSpellManager::LoadSpells(char const*FileName, char const*AssocFilename, char const*StackingFileName);
/*0x08*/ EQLIB_OBJECT bool ClientSpellManager::LoadSpellStackingData(const char*StackingFileName);
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x0c*/ EQLIB_OBJECT bool ClientSpellManager::DoesMeetRequirement(PlayerZoneClient*pPlayer, int SpellAssocID);
#endif
/*0x10*/ EQLIB_OBJECT void ClientSpellManager::PrintFailedRequirementString(int StrToken, int StringID);
/*0x14*/ EQLIB_OBJECT int ClientSpellManager::GetSpellStackingGroupID(int SpellID);
/*0x18*/ EQLIB_OBJECT int ClientSpellManager::GetSpellStackingGroupRank(int SpellID);
/*0x1c*/ EQLIB_OBJECT ESpellStackingRules ClientSpellManager::GetSpellStackingGroupRule(int SpellID);
/*0x20*/ EQLIB_OBJECT PSPELL ClientSpellManager::GetSpellByID(int SpellID);
/*0x24*/ EQLIB_OBJECT struct _SPELLCALCINFO* ClientSpellManager::GetSpellAffect(int index);
/*0x28*/ EQLIB_OBJECT bool ClientSpellManager::GetSpellAffectEmpty(bool);

/*0x03BBAC*/ struct _SPELL* Spells[TOTAL_SPELL_COUNT+1];//60001 last one is the unknown spell...
/*0x076530*/ struct _SPELLCALCINFO* CalcInfo[CalcInfoSize];//175000
	EQSpellExtra SpellExtraData[TOTAL_SPELL_COUNT+1];
	HashTable<StackingGroupData> StackingData;
};

class STable
{
public:
EQLIB_OBJECT STable::~STable();
EQLIB_OBJECT STable::STable();
EQLIB_OBJECT class STable & STable::operator=(class STable const &);
//EQLIB_OBJECT void* STable::`vector deleting destructor'(unsigned int);
};

class STableCell
{
public:
EQLIB_OBJECT STableCell::~STableCell();
EQLIB_OBJECT STableCell::STableCell();
};

class STempTable
{
public:
EQLIB_OBJECT STempTable::~STempTable();
};

class STempTableCell
{
public:
EQLIB_OBJECT STempTableCell::~STempTableCell();
EQLIB_OBJECT STempTableCell::STempTableCell();
};

class STempTableRow
{
public:
EQLIB_OBJECT STempTableRow::~STempTableRow();
EQLIB_OBJECT STempTableRow::STempTableRow();
};

class StringItem
{
public:
EQLIB_OBJECT StringItem::~StringItem();
EQLIB_OBJECT StringItem::StringItem();
EQLIB_OBJECT int StringItem::load(struct _iobuf*, int);
};

class StringTable
{
public:
EQLIB_OBJECT StringTable::~StringTable();
EQLIB_OBJECT StringTable::StringTable();
EQLIB_OBJECT char* StringTable::getString(unsigned long ID, bool*bFound = NULL);
EQLIB_OBJECT int StringTable::load(char const*, int);
EQLIB_OBJECT void StringTable::addItem(class StringItem*);
// private
EQLIB_OBJECT class StringItem* StringTable::findItem(unsigned long, int, int);
EQLIB_OBJECT void StringTable::checkAlloc();
};

class TextFileReader
{
public:
EQLIB_OBJECT TextFileReader::~TextFileReader();
EQLIB_OBJECT TextFileReader::TextFileReader(char*, char);
EQLIB_OBJECT bool TextFileReader::IsOpen();
EQLIB_OBJECT int TextFileReader::GetNextField(char*, int);
EQLIB_OBJECT int TextFileReader::ReadLine();
EQLIB_OBJECT void TextFileReader::GetLine(char*, int);
};

class type_info
{
public:
// virtual
EQLIB_OBJECT type_info::~type_info();
//EQLIB_OBJECT void* type_info::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void* type_info::`vector deleting destructor'(unsigned int);
};

class UdpConnection
{
public:
//EQLIB_OBJECT bool UdpConnection::Send(enum UdpChannel, void const*, int);
EQLIB_OBJECT int UdpConnection::ConnectionAge() const;
EQLIB_OBJECT int UdpConnection::LastReceive() const;
EQLIB_OBJECT int UdpConnection::TotalPendingBytes() const;
EQLIB_OBJECT void UdpConnection::FlushMultiBuffer();
//EQLIB_OBJECT void UdpConnection::GetChannelStatus(enum UdpChannel, struct UdpConnection::ChannelStatus*) const;
EQLIB_OBJECT void UdpConnection::PingStatReset();
EQLIB_OBJECT void UdpConnection::Release();
EQLIB_OBJECT void UdpConnection::SetSilentDisconnect(bool);
// protected
EQLIB_OBJECT UdpConnection::UdpConnection(class UdpManager*, class UdpIpAddress, int, int);
//EQLIB_OBJECT UdpConnection::UdpConnection(class UdpManager*, class UdpManager::PacketHistoryEntry const*);
EQLIB_OBJECT void UdpConnection::GiveTime();
EQLIB_OBJECT void UdpConnection::PortUnreachable();
//EQLIB_OBJECT void UdpConnection::ProcessRawPacket(class UdpManager::PacketHistoryEntry const*);
// private
EQLIB_OBJECT UdpConnection::~UdpConnection();
//EQLIB_OBJECT bool UdpConnection::InternalSend(enum UdpChannel, unsigned char const*, int, unsigned char const*, int);
EQLIB_OBJECT bool UdpConnection::IsNonEncryptPacket(unsigned char const*) const;
EQLIB_OBJECT int UdpConnection::DecryptNone(unsigned char*, unsigned char const*, int);
EQLIB_OBJECT int UdpConnection::DecryptUserSupplied(unsigned char*, unsigned char const*, int);
EQLIB_OBJECT int UdpConnection::DecryptUserSupplied2(unsigned char*, unsigned char const*, int);
EQLIB_OBJECT int UdpConnection::DecryptXor(unsigned char*, unsigned char const*, int);
EQLIB_OBJECT int UdpConnection::DecryptXorBuffer(unsigned char*, unsigned char const*, int);
EQLIB_OBJECT int UdpConnection::EncryptNone(unsigned char*, unsigned char const*, int);
EQLIB_OBJECT int UdpConnection::EncryptUserSupplied(unsigned char*, unsigned char const*, int);
EQLIB_OBJECT int UdpConnection::EncryptUserSupplied2(unsigned char*, unsigned char const*, int);
EQLIB_OBJECT int UdpConnection::EncryptXor(unsigned char*, unsigned char const*, int);
EQLIB_OBJECT int UdpConnection::EncryptXorBuffer(unsigned char*, unsigned char const*, int);
EQLIB_OBJECT int UdpConnection::ExpireReceiveBin();
EQLIB_OBJECT int UdpConnection::ExpireSendBin();
EQLIB_OBJECT unsigned char* UdpConnection::BufferedSend(unsigned char const*, int, unsigned char const*, int, bool);
//EQLIB_OBJECT void UdpConnection::CallbackCorruptPacket(unsigned char const*, int, enum UdpCorruptionReason);
EQLIB_OBJECT void UdpConnection::CallbackRoutePacket(unsigned char const*, int);
EQLIB_OBJECT void UdpConnection::Init(class UdpManager*, class UdpIpAddress, int);
//EQLIB_OBJECT void UdpConnection::InternalDisconnect(int, enum UdpConnection::DisconnectReason);
EQLIB_OBJECT void UdpConnection::InternalGiveTime();
EQLIB_OBJECT void UdpConnection::PhysicalSend(unsigned char const*, int, bool);
EQLIB_OBJECT void UdpConnection::ProcessCookedPacket(unsigned char const*, int);
EQLIB_OBJECT void UdpConnection::RawSend(unsigned char const*, int);
EQLIB_OBJECT void UdpConnection::ScheduleTimeNow();
//EQLIB_OBJECT void UdpConnection::SendTerminatePacket(int, enum UdpConnection::DisconnectReason);
EQLIB_OBJECT void UdpConnection::SetupEncryptModel();
};

class UdpConnectionHandler
{
public:
// virtual
EQLIB_OBJECT void UdpConnectionHandler::OnConnectComplete(class UdpConnection*);
EQLIB_OBJECT void UdpConnectionHandler::OnCrcReject(class UdpConnection*, unsigned char const*, int);
//EQLIB_OBJECT void UdpConnectionHandler::OnPacketCorrupt(class UdpConnection*, unsigned char const*, int, enum UdpCorruptionReason);
EQLIB_OBJECT void UdpConnectionHandler::OnTerminated(class UdpConnection*);
};

class UdpIpAddress
{
public:
EQLIB_OBJECT UdpIpAddress::UdpIpAddress(unsigned int);
};

class UdpManager
{
public:
//EQLIB_OBJECT UdpManager::PacketHistoryEntry::~PacketHistoryEntry();
//EQLIB_OBJECT UdpManager::PacketHistoryEntry::PacketHistoryEntry(int);
//EQLIB_OBJECT UdpManager::Params::Params();
//EQLIB_OBJECT UdpManager::SimulateQueueEntry::~SimulateQueueEntry();
//EQLIB_OBJECT UdpManager::SimulateQueueEntry::SimulateQueueEntry(unsigned char const*, int, class UdpIpAddress, int);
//EQLIB_OBJECT UdpManager::UdpManager(struct UdpManager::Params const*);
EQLIB_OBJECT bool UdpManager::GiveTime(int, bool);
EQLIB_OBJECT class LogicalPacket* UdpManager::CreatePacket(void const*, int, void const*, int);
EQLIB_OBJECT class UdpConnection* UdpManager::EstablishConnection(char const*, int, int);
EQLIB_OBJECT void UdpManager::Release();
EQLIB_OBJECT void UdpManager::ResetStats();
// protected
EQLIB_OBJECT class UdpConnection* UdpManager::AddressGetConnection(class UdpIpAddress, int) const;
EQLIB_OBJECT class UdpConnection* UdpManager::ConnectCodeGetConnection(int) const;
//EQLIB_OBJECT class UdpManager::PacketHistoryEntry* UdpManager::ActualReceive();
EQLIB_OBJECT class WrappedLogicalPacket* UdpManager::WrappedBorrow(class LogicalPacket const*);
EQLIB_OBJECT void UdpManager::ActualSend(unsigned char const*, int, class UdpIpAddress, int);
EQLIB_OBJECT void UdpManager::ActualSendHelper(unsigned char const*, int, class UdpIpAddress, int);
EQLIB_OBJECT void UdpManager::AddConnection(class UdpConnection*);
EQLIB_OBJECT void UdpManager::CloseSocket();
EQLIB_OBJECT void UdpManager::CreateAndBindSocket(int);
EQLIB_OBJECT void UdpManager::KeepUntilDisconnected(class UdpConnection*);
EQLIB_OBJECT void UdpManager::PoolCreated(class PooledLogicalPacket*);
EQLIB_OBJECT void UdpManager::PoolDestroyed(class PooledLogicalPacket*);
EQLIB_OBJECT void UdpManager::PoolReturn(class PooledLogicalPacket*);
EQLIB_OBJECT void UdpManager::ProcessDisconnectPending();
EQLIB_OBJECT void UdpManager::ProcessIcmpErrors();
//EQLIB_OBJECT void UdpManager::ProcessRawPacket(class UdpManager::PacketHistoryEntry const*);
EQLIB_OBJECT void UdpManager::RemoveConnection(class UdpConnection*);
EQLIB_OBJECT void UdpManager::SendPortAlive(class UdpIpAddress, int);
EQLIB_OBJECT void UdpManager::WrappedCreated(class WrappedLogicalPacket*);
EQLIB_OBJECT void UdpManager::WrappedDestroyed(class WrappedLogicalPacket*);
EQLIB_OBJECT void UdpManager::WrappedReturn(class WrappedLogicalPacket*);
// private
EQLIB_OBJECT UdpManager::~UdpManager();
};

class UdpMisc
{
public:
EQLIB_OBJECT static int64_t __cdecl UdpMisc::Clock();
EQLIB_OBJECT static int64_t __cdecl UdpMisc::GetValue64(void const*);
EQLIB_OBJECT static class LogicalPacket* __cdecl UdpMisc::CreateQuickLogicalPacket(void const*, int, void const*, int);
EQLIB_OBJECT static int __cdecl UdpMisc::Crc32(void const*, int, int);
EQLIB_OBJECT static int __cdecl UdpMisc::PutValue24(void*, unsigned int);
EQLIB_OBJECT static int __cdecl UdpMisc::PutValue32(void*, unsigned int);
EQLIB_OBJECT static int __cdecl UdpMisc::PutValue64(void*, int64_t);
EQLIB_OBJECT static int __cdecl UdpMisc::Random(int*);
EQLIB_OBJECT static int __cdecl UdpMisc::SyncStampShortDeltaTime(unsigned short, unsigned short);
EQLIB_OBJECT static unsigned int __cdecl UdpMisc::GetValue24(void const*);
EQLIB_OBJECT static unsigned int __cdecl UdpMisc::GetValue32(void const*);
EQLIB_OBJECT static unsigned int __cdecl UdpMisc::GetVariableValue(void const*, unsigned int*);
EQLIB_OBJECT static unsigned int __cdecl UdpMisc::PutVariableValue(void*, unsigned int);
};

class UdpReliableChannel
{
public:
//EQLIB_OBJECT UdpReliableChannel::IncomingQueueEntry::~IncomingQueueEntry();
//EQLIB_OBJECT UdpReliableChannel::IncomingQueueEntry::IncomingQueueEntry();
//EQLIB_OBJECT UdpReliableChannel::PhysicalPacket::~PhysicalPacket();
//EQLIB_OBJECT UdpReliableChannel::PhysicalPacket::PhysicalPacket();
//EQLIB_OBJECT void* UdpReliableChannel::IncomingQueueEntry::`vector deleting destructor'(unsigned int);
//EQLIB_OBJECT void* UdpReliableChannel::PhysicalPacket::`vector deleting destructor'(unsigned int);
// protected
EQLIB_OBJECT int64_t UdpReliableChannel::GetReliableIncomingId(int) const;
EQLIB_OBJECT UdpReliableChannel::~UdpReliableChannel();
//EQLIB_OBJECT UdpReliableChannel::UdpReliableChannel(int, class UdpConnection*, struct UdpManager::ReliableConfig*);
EQLIB_OBJECT bool UdpReliableChannel::PullDown(int);
EQLIB_OBJECT int UdpReliableChannel::GiveTime();
EQLIB_OBJECT void UdpReliableChannel::Ack(int64_t);
EQLIB_OBJECT void UdpReliableChannel::AckAllPacket(unsigned char const*, int);
EQLIB_OBJECT void UdpReliableChannel::AckPacket(unsigned char const*, int);
EQLIB_OBJECT void UdpReliableChannel::FlushCoalesce();
//EQLIB_OBJECT void UdpReliableChannel::GetChannelStatus(struct UdpConnection::ChannelStatus*) const;
//EQLIB_OBJECT void UdpReliableChannel::ProcessPacket(enum UdpReliableChannel::ReliablePacketMode, unsigned char const*, int);
EQLIB_OBJECT void UdpReliableChannel::QueueLogicalPacket(class LogicalPacket const*);
EQLIB_OBJECT void UdpReliableChannel::ReliablePacket(unsigned char const*, int);
EQLIB_OBJECT void UdpReliableChannel::Send(unsigned char const*, int, unsigned char const*, int);
EQLIB_OBJECT void UdpReliableChannel::SendCoalesce(unsigned char const*, int, unsigned char const*, int);
};

class vlong
{
public:
EQLIB_OBJECT vlong::~vlong();
EQLIB_OBJECT vlong::vlong(class vlong const &);
EQLIB_OBJECT vlong::vlong(uint64_t);
EQLIB_OBJECT class vlong & vlong::operator+=(class vlong const &);
EQLIB_OBJECT class vlong & vlong::operator-=(class vlong const &);
EQLIB_OBJECT class vlong & vlong::operator=(class vlong);
// private
EQLIB_OBJECT int vlong::cf(class vlong) const;
EQLIB_OBJECT void vlong::docopy();
};

class vlong_value
{
public:
EQLIB_OBJECT vlong_value::~vlong_value();
EQLIB_OBJECT vlong_value::vlong_value();
EQLIB_OBJECT int vlong_value::cf(class vlong_value &) const;
EQLIB_OBJECT int vlong_value::is_zero() const;
EQLIB_OBJECT int vlong_value::test(unsigned int) const;
EQLIB_OBJECT unsigned int vlong_value::bits() const;
EQLIB_OBJECT void vlong_value::add(class vlong_value &);
EQLIB_OBJECT void vlong_value::copy(class vlong_value &);
EQLIB_OBJECT void vlong_value::divide(class vlong_value &, class vlong_value &, class vlong_value &);
EQLIB_OBJECT void vlong_value::init(unsigned int);
EQLIB_OBJECT void vlong_value::init2(unsigned int, unsigned int);
EQLIB_OBJECT void vlong_value::mul(class vlong_value &, class vlong_value &);
EQLIB_OBJECT void vlong_value::shl();
EQLIB_OBJECT void vlong_value::shr(unsigned int);
EQLIB_OBJECT void vlong_value::shr();
EQLIB_OBJECT void vlong_value::subtract(class vlong_value &);
};

class Wave3dInstance
{
public:
EQLIB_OBJECT Wave3dInstance::Wave3dInstance(class SoundManager*);
// virtual
EQLIB_OBJECT bool Wave3dInstance::GiveTime();
EQLIB_OBJECT enum InstanceType Wave3dInstance::GetType();
EQLIB_OBJECT void Wave3dInstance::AdjustVolume(float, int);
EQLIB_OBJECT void Wave3dInstance::GuaranteeStopped();
EQLIB_OBJECT void Wave3dInstance::Move(float, float, float);
EQLIB_OBJECT void Wave3dInstance::Play(class SoundControl*);
// protected
EQLIB_OBJECT virtual Wave3dInstance::~Wave3dInstance();
//EQLIB_OBJECT virtual void* Wave3dInstance::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void* Wave3dInstance::`vector deleting destructor'(unsigned int);
};

class WaveInstance
{
public:
EQLIB_OBJECT WaveInstance::WaveInstance(class SoundManager*);
// virtual
EQLIB_OBJECT bool WaveInstance::GiveTime();
//EQLIB_OBJECT enum InstanceType WaveInstance::GetType();
EQLIB_OBJECT void WaveInstance::AdjustVolume(float, int);
EQLIB_OBJECT void WaveInstance::GuaranteeStopped();
EQLIB_OBJECT void WaveInstance::Move(float, float, float);
EQLIB_OBJECT void WaveInstance::Play(class SoundControl*);
// protected
EQLIB_OBJECT virtual WaveInstance::~WaveInstance();
//EQLIB_OBJECT virtual void* WaveInstance::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void* WaveInstance::`vector deleting destructor'(unsigned int);
};

class WrappedLogicalPacket
{
public:
EQLIB_OBJECT WrappedLogicalPacket::WrappedLogicalPacket(class UdpManager*);
// virtual
EQLIB_OBJECT int WrappedLogicalPacket::GetDataLen() const;
EQLIB_OBJECT void* WrappedLogicalPacket::GetDataPtr();
EQLIB_OBJECT void WrappedLogicalPacket::AddRef() const;
EQLIB_OBJECT void WrappedLogicalPacket::Release() const;
EQLIB_OBJECT void WrappedLogicalPacket::SetDataLen(int);
EQLIB_OBJECT void const* WrappedLogicalPacket::GetDataPtr() const;
// protected
EQLIB_OBJECT virtual WrappedLogicalPacket::~WrappedLogicalPacket();
//EQLIB_OBJECT virtual void* WrappedLogicalPacket::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void* WrappedLogicalPacket::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void WrappedLogicalPacket::SetLogicalPacket(class LogicalPacket const*);
};

class ZlibUtil
{
public:
EQLIB_OBJECT static int __cdecl ZlibUtil::Compress(char const*, int, char*, int, int);
EQLIB_OBJECT static int __cdecl ZlibUtil::Decompress(char const*, int, char*, int);
// private
EQLIB_OBJECT static class MemoryPoolManager ZlibUtil::sMemoryPoolManager;
EQLIB_OBJECT static int __cdecl ZlibUtil::zcompress(unsigned char*, unsigned long*, unsigned char const*, unsigned long, int);
EQLIB_OBJECT static int __cdecl ZlibUtil::zuncompress(unsigned char*, unsigned long*, unsigned char const*, unsigned long);
EQLIB_OBJECT static void* __cdecl ZlibUtil::zcalloc(void*, unsigned int, unsigned int);
EQLIB_OBJECT static void __cdecl ZlibUtil::zfree(void*, void*);
};

class ZoneNPCLoadTextManager
{
public:
EQLIB_OBJECT ZoneNPCLoadTextManager::~ZoneNPCLoadTextManager();
EQLIB_OBJECT ZoneNPCLoadTextManager::ZoneNPCLoadTextManager(char*);
EQLIB_OBJECT char* ZoneNPCLoadTextManager::GetNPCCode(int);
EQLIB_OBJECT char* ZoneNPCLoadTextManager::GetS3DName(int);
EQLIB_OBJECT void ZoneNPCLoadTextManager::LoadText(char*);
};

class CTextOverlay
{
public:
//EQLIB_OBJECT void BroadcastString(const char* Str, int TextColor, int Priority, int MaxAlpha, UINT FadeInTime, UINT FadeOutTime, UINT DisplayTime);
EQLIB_OBJECT void CTextOverlay::DisplayText(const char* Str, int TextColor, int Priority, int MaxAlpha, UINT FadeInTime, UINT FadeOutTime, UINT DisplayTime);
}; 

class CMyInventory
{
public:
EQLIB_OBJECT struct  _CONTENTS* CMyInventory::GetSlot(int);
};

class CDBStr
{
public:
// GetString(index, subindex, &success)
EQLIB_OBJECT char*CDBStr::GetString(int, int, int*);
};

class CCombatAbilityWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CCombatAbilityWnd::CCombatAbilityWnd(class CXWnd*);
EQLIB_OBJECT void CCombatAbilityWnd::Activate(int);
EQLIB_OBJECT void CCombatAbilityWnd::Deactivate();
EQLIB_OBJECT int CCombatAbilityWnd::OnProcessFrame();
EQLIB_OBJECT int CCombatAbilityWnd::WndNotification(class CXWnd*, uint32_t, void*);
EQLIB_OBJECT CCombatAbilityWnd::~CCombatAbilityWnd();
};

class EQMisc
{
public:
EQLIB_OBJECT int EQMisc::GetActiveFavorCost();
};

class CSkillMgr
{
public:
EQLIB_OBJECT unsigned long CSkillMgr::GetNameToken(int);
EQLIB_OBJECT unsigned long CSkillMgr::GetSkillCap(class EQ_Character*, int, int, int, bool, bool, bool);
EQLIB_OBJECT unsigned long CSkillMgr::SkillAvailableAtLevel(int, int);
EQLIB_OBJECT bool CSkillMgr::IsActivatedSkill(int);
EQLIB_OBJECT unsigned long CSkillMgr::GetBaseDamage(int);
EQLIB_OBJECT unsigned long CSkillMgr::GetReuseTime(int);
EQLIB_OBJECT bool CSkillMgr::IsAvailable(int);
EQLIB_OBJECT bool CSkillMgr::IsCombatSkill(int);
};

class CChatService
{
public:
EQLIB_OBJECT int CChatService::GetNumberOfFriends();
EQLIB_OBJECT char* CChatService::GetFriendName(int);
};

class PlayerPointManager
{
public:
EQLIB_OBJECT unsigned long PlayerPointManager::GetAltCurrency(unsigned long, unsigned long b=1);
};
enum eZoneGuideConnectionsView
{
	eZGCV_None,
	eZGCV_Selected,
	eZGCV_PreviewPath,
	eZGCV_ActivePath,
	eZGCV_Disabled,
};

class ZoneGuideConnection
{
public:
	EQZoneIndex DestZone;
	int TransferTypeIndex; 
	int RequiredExpansions;//EQExpansionOwned
	bool bDisabled;
};
class ZoneGuideZone
{
public:
/*0x00*/ EQZoneIndex ID;
/*0x04*/ PCXSTR Name;
/*0x08*/ int ContinentIndex;
/*0x0C*/ int MinLevel;
/*0x10*/ int MaxLevel;
/*0x14*/ DynamicBitField<unsigned short, short> Types;
/*0x1C*/ ArrayClass_RO<ZoneGuideConnection> ZoneConnections;
/*0x2C*/ // see 8E87D6 in Apr 15 2019 exe
};
class ZoneGuideContinent
{
public:
	int ID;
	int DisplaySequence;
	PCXSTR Name;
};
class ZoneGuideZoneType
{
public:
	int ID;
	int DisplaySequence;
	PCXSTR Name;
};
class ZoneGuideTransferType
{
public:
	int ID;
	PCXSTR Description;
};
//see 8D35C1 in may 10 2018 exe
//see 8E87D1 in Apr 15 2019 exe
#if defined(ROF2EMU) || defined(UFEMU)
//see 7FEC8D
#define ZONE_COUNT 768
#else
#define ZONE_COUNT 836
#endif
class ZoneGuideManagerBase
{
public:
/*0x0000*/ PVOID vfTable;
/*0x0004*/ ZoneGuideZone Zones[ZONE_COUNT];//0x2c* 0x344
/*0x8FB4*/ ArrayClass_RO<ZoneGuideContinent> Continents;
/*0x8FC4*/ ArrayClass_RO<ZoneGuideZoneType> ZoneTypes;
/*0x8FD4*/ ArrayClass_RO<ZoneGuideTransferType> TransferTypes;
/*0x8FE4*/ 
};
typedef struct _ZonePathData
{
	EQZoneIndex ZoneID;
	int TransferTypeIndex;
}ZonePathData,*PZonePathData;

//size: 0x9010 see 6AB098 in Apr 15 2019 exe
//todo fix this for the rof2 emu client...
class ZoneGuideManagerClient : public ZoneGuideManagerBase
{
public:
EQLIB_OBJECT static ZoneGuideManagerClient& ZoneGuideManagerClient::Instance();
/*0x8FE4*/ ArrayClass_RO<ZonePathData> ActivePath;
/*0x8FF4*/ ArrayClass_RO<ZonePathData> PreviewPath;//for sure see 6AAE81
/*0x9004*/ EQZoneIndex CurrZone;//for sure see 6AA3E7
/*0x9008*/ int HerosJourneyIndex;//for sure see 6AB27D
/*0x900C*/ bool bZoneGuideDataSet;
/*0x900D*/ bool bIncludeBindZoneInPath;
/*0x900E*/ bool bAutoFindActivePath;
/*0x900F*/ bool bFindActivePath;
/*0x9010*/ 
};

class CZoneGuideWnd : public CSidlScreenWnd, public WndEventHandler2
{
public:
	void* VerticalLayout;//CVerticalLayoutWnd
	CButtonWnd*FilterMyLevelButton;
	CButtonWnd*FilterAllLevelsButton;
	CButtonWnd*FilterZonesActiveButton;
	CButtonWnd*FilterZonesInactiveButton;
	CButtonWnd*ZoneRunSearchButton;
	CButtonWnd*ZoneClearSearchButton;	
	CButtonWnd*SelectCurrentZoneButton;
	CEditWnd*LevelFilterEdit;
	CEditWnd*ZoneSearchEdit;
	CComboWnd*TypeFilterCombo;
	CComboWnd*ContinentFilterCombo;
	CListWnd*ZonesList;
	CLabelWnd*ViewZoneConnectionsSelectedZoneLabel;
	CLabelWnd*ViewZoneConnectionsPreviewPathLabel;
	CLabelWnd*ViewZoneConnectionsActivePathLabel;
	CLabelWnd*ViewZoneConnectionsDisabledLabel;
	CButtonWnd*ViewZoneConnectionsSelectedZoneButton;
	CButtonWnd*ViewZoneConnectionsPreviewPathButton;
	CButtonWnd*ViewZoneConnectionsActivePathButton;
	CButtonWnd*ViewZoneConnectionsDisabledButton;
	CButtonWnd*DisableConnectionTemplateButton;
	CListWnd*ZoneConnectionsList;
	CButtonWnd*ResetPathStartZoneButton;
	CButtonWnd*SetPathStartZoneButton;
	CButtonWnd*SetPathEndZoneButton;
	CButtonWnd*ShowPathWndButton;
	CButtonWnd*HidePathWndButton;
	CButtonWnd*FindPathButton;
	CButtonWnd*EndFindButton;
	CButtonWnd*ClearPathWndButton;
	CButtonWnd*ActivatePathButton;
	CButtonWnd*IncludeBindZoneInPathGenerationButton;
	CButtonWnd*ShowPathWndOnPathActivationButton;
	CButtonWnd*AutoFindActivePathButton;
	CEditWnd*PathStartZoneEdit;
	CEditWnd*PathEndZoneEdit;
	UINT NextButtonRefreshTime;
	EQZoneIndex eCurrentZone;
	bool bFilterActive;
	int FilterLevel;
	int FilterContinentIndex;
	int FilterZoneTypeIndex;
	bool bSelectCurrentZone;
	PCXSTR ZoneSearchString;
	eZoneGuideConnectionsView eCurrConnectionsView;
	EQZoneIndex CurrConnectionsViewSelectedZone;
	bool bCurrentConnectionsViewPreviewPathChanged;
	bool bCurrentConnectionsViewActivePathChanged;
	bool bSetPathStartZoneToCurrentZone;
	EQZoneIndex StartZone;
	EQZoneIndex EndZone;
	bool bZoneGuideDataChanged;
	bool bZoneListChanged;
	bool bZoneConnectionsListChanged;
	bool bPathStartZoneChanged;
	int RightClickMenuID;
};

#pragma pack(push)
#pragma pack(4)
enum eKeyboardMode
{
	Typing,
	KBM_Command,
};

typedef struct _EVERQUESTINFO
{
/*0x00000*/	HWND		Wnd;
/*0x00004*/ HINSTANCE	hInst;
/*0x00008*/	int		Render_MinX;
/*0x0000c*/	int		Render_MinY;
/*0x00010*/	int		Render_MaxX;
/*0x00014*/	int		Render_MaxY;
/*0x00018*/	int		Render_XScale;
/*0x0001c*/	int		Render_YScale;
/*0x00020*/	int		Render_WidthScale;
/*0x00024*/	int		Render_HeightScale;
/*0x00028*/	int		ReadyEnterWorld;
/*0x0002c*/	bool	InsideDoMainWhileLoop;
/*0x00030*/	int		Hidden;//not sure
/*0x00034*/ DWORD	Displayflags;
/*0x00038*/ DWORD	Command;
/*0x0003c*/	BYTE	Unknown0x0003c;
/*0x00040*/	int		ScreenXRes;
/*0x00044*/	int		ScreenYRes;
/*0x00048*/	int		WindowXOffset;
/*0x0004c*/	int		WindowYOffset;
/*0x00050*/	BOOL	FullscreenMode;
/*0x00054*/	eKeyboardMode	KeyboardMode;
/*0x00058*/	BYTE	Runmode;//dont EVER set this to something > 1 unless you WANT to get banned.
/*0x00059*/	BYTE	Unknown0x00059;
/*0x0005a*/	BYTE	Unknown0x0005a;
/*0x0005b*/	BYTE	MouseCntrl;
/*0x0005c*/	BYTE	MouseActive;
/*0x0005d*/	BYTE	ForceCrouch;
/*0x00060*/	UINT	ForceCrouchTimer;
/*0x00064*/	float	Unknown0x00064;
/*0x00068*/	float	Unknown0x00068;
/*0x0006c*/	int		MouseX;
/*0x00070*/	int		MouseY;
/*0x00074*/	int		MouseZ;
/*0x00078*/	int		Lastmx;
/*0x0007c*/	int		Lastmy;
/*0x00080*/	bool	MouseInClientRect;
/*0x00084*/ int		MXSensitivity;
/*0x00088*/ int		MYSensitivity;
/*0x0008c*/	int		MousePointerSpeedMod;
/*0x00090*/	bool	ServerFilter;
/*0x00094*/	int		IsTrader;
/*0x00098*/	BYTE	CurrentChan;
/*0x0009c*/	int		CurrentLang;
/*0x000a0*/	char	TellTarget[0x40];
/*0x000e0*/	UINT	LastMinute;
/*0x000e4*/	UINT	LastLocal;
/*0x000e8*/	UINT	LastControlled;
/*0x000ec*/	BYTE	MInverse;
/*0x000ed*/	BYTE	Unknown0x000ed;//mouse related
/*0x000ee*/	BYTE	MouseLook;
/*0x000ef*/	bool	bDefaultMouseLook;
/*0x000f0*/	BYTE	Strafe;
/*0x000f1*/	bool	bNetstat;
/*0x000f2*/	BYTE	ModInventory;
/*0x000f4*/	UINT	LastHitter;//check this
/*0x000f8*/	BYTE	Harmless;
/*0x000f9*/	BYTE	Silenced;
/*0x000fc*/	UINT	JumpTimer;
/*0x00100*/	UINT	EventJump;
/*0x00104*/	UINT	LastJump;
/*0x00108*/	UINT	FrameTime;
/*0x0010c*/	int		AutoRun;
/*0x00110*/	UINT	PoisonTimer;
/*0x00114*/	ItemGlobalIndex2	PoisonGI;
/*0x00120*/	int		OldX;
/*0x00124*/	int		OldY;
/*0x00128*/	BYTE	OldMouseButtons[8];
/*0x00130*/	BYTE	MouseButtons[8];
/*0x00138*/	bool	bIsMouseRightHanded;
/*0x0013c*/	int		Unknown0x0013c;
/*0x00140*/	int		CharStatePending;
/*0x00144*/	char	PendingCharacterName[0x40];
/*0x00184*/	int		TutorialMode;
/*0x00188*/	int		RMouseSecond;
/*0x0018c*/	int		LMouseSecond;
/*0x00190*/	UINT	RMouseDown;
/*0x00194*/	UINT	LMouseDown;
/*0x00198*/	CHAR	Unknown0x00198[0x40];
/*0x001d8*/	UINT	DuelTarget;
/*0x001dc*/	UINT	DuelMe;
/*0x001e0*/	BYTE	DuelOn;
/*0x001e4*/	UINT	AutoHelp;
/*0x001e8*/	BYTE	OldMouseLook;
/*0x001ec*/	UINT	LastLocalUpdate;
/*0x001f0*/	UINT	LastControlledUpdate;
/*0x001f4*/	UINT	DataRate;
/*0x001f8*/	int		SavedPC;
/*0x001fc*/	int		InfraRed;
/*0x00200*/	int		InfraGreen;
/*0x00204*/	int		InfraBlue;
/*0x00208*/	int		UltraRed;
/*0x0020c*/	int		UltraGreen;
/*0x00210*/	int		UltraBlue;
/*0x00214*/	int		Unknown0x00214;
/*0x00218*/	int		IOLines;
/*0x0021c*/	int		IOLineSpacing;
/*0x00220*/	char	ObjTag[0x14];
/*0x00234*/	long	NumObjects;
/*0x00238*/	long	NumLights;
/*0x0023c*/	long	DecrTime[0xa];
/*0x00264*/	long	DecrMsg[0xa];
/*0x0028c*/	long	DecrIndex;
/*0x00290*/	BYTE	AffectsOn;
/*0x00291*/	BYTE	InspectMode;
/*0x00292*/	BYTE	UpMouseAnim;
/*0x00294*/	UINT	ExitCounter;
/*0x00298*/	UINT	ExitStart;
/*0x0029c*/	UINT	ForcedExitCounter;
/*0x002a0*/	UINT	OfflineModeRequestTime;
/*0x002a4*/	int		SwimJump;
/*0x002a8*/	BYTE	DisplayCamp;
/*0x002ac*/	int		PolysOff;
/*0x002b0*/	float	CampY;
/*0x002b4*/	float	CampX;
/*0x002b8*/	float	CampZ;
/*0x002bc*/ int		Hits;
/*0x002c0*/	int		Bandage;
/*0x002c4*/	UINT	BackSpace;
/*0x002c8*/	long	StartBandage;
/*0x002cc*/	long	MyY;
/*0x002d0*/	long	MyX;
/*0x002d4*/	long	MyZ;
/*0x002d8*/	long	TargetY;
/*0x002dc*/	long	TargetX;
/*0x002e0*/	long	TargetZ;
/*0x002e4*/	ZONEINFO	ZoneInfo;//size 0x3a8
/*0x0068c*/	BYTE	ZDefined;
/*0x00690*/	int		TrackTimer;
/*0x00694*/	long	StartTrack;
/*0x00698*/	int		bTrackPlayers;
/*0x0069c*/ bool	bTrackMercs;
/*0x0069d*/ bool	bTrackPets;
/*0x006a0*/	int		iTrackSortType;
/*0x006a4*/	int		iTrackFilterType;
/*0x006a8*/	UINT	MouseTimer;
/*0x006ac*/	int		SoundUpdate;
/*0x006b0*/	BOOL	MouseOn;
/*0x006b4*/	USINGSKILL		UsingSkill;//size 0x8
/*0x006bc*/	int		Unknown0x006bc[4];
/*0x006cc*/ BYTE	ClickThroughMask;
/*0x006d0*/	int		ShowSpellDescriptions;
/*0x006d4*/	bool	ReceivedWorldObjects;
/*0x006d5*/	BYTE	Unknown0x006d5;
/*0x006d6*/	bool	Unknown0x006d6;
/*0x006d8*/	float	SavedViewPitch;
/*0x006dc*/	int		SendPcReceived;
/*0x006e0*/	int		WeatherReceived;
/*0x006e4*/	int		PixelInit;
/*0x006e8*/	bool	bIsPressedShift;
/*0x006e9*/	bool	bIsPressedControl;
/*0x006ea*/	bool	bIsPressedAlt;
/*0x006eb*/	bool	bIsPressedLShift;
/*0x006ec*/	bool	bIsPressedLControl;
/*0x006ed*/	bool	bIsPressedLAlt;
/*0x006ee*/	bool	bIsPressedRShift;
/*0x006ef*/	bool	bIsPressedRControl;
/*0x006f0*/	bool	bIsPressedRAlt;
/*0x006f4*/	int		Currkeypress;
/*0x006f8*/	int		Lastkeypress;
/*0x006fc*/	int		Rateup;
/*0x00700*/	int		Ratedown;
/*0x00704*/	int		Rateforward;
/*0x00708*/	int		Rateback;
/*0x0070c*/	int		Rateleft;
/*0x00710*/	int		Rateright;
/*0x00714*/	int		RaceWar;
/*0x00718*/	int		Ruleset;
/*0x0071c*/	bool	bRpServer;
/*0x0071d*/	bool	bAcceleratedServer;
/*0x0071e*/	bool	bProgressionServer;
/*0x00720*/	int		ProgressionOpenExpansions;
/*0x00724*/ bool	bIsDevServer;
/*0x00725*/ bool	bIsBetaServer;
/*0x00726*/ bool	bIsTestServer;
/*0x00727*/ bool	bIsStageServer;
/*0x00728*/	bool	bUseMailSystem;
/*0x00729*/	bool	bIsEscapeServer;
/*0x0072a*/	bool	bIsTutorialEnabled;
/*0x0072b*/	bool	bCanCreateHeadStartCharacter;
/*0x0072c*/ bool	bCanCreateHeroicCharacter;
/*0x00730*/ int		HeroicSlots;
/*0x00734*/	bool	bAutoIdentify;
/*0x00735*/	bool	bNameGen;
/*0x00736*/	bool	bGibberish;
/*0x00738*/	int		Locale;
/*0x0073c*/	BYTE	UpdateControlled;
/*0x0073d*/	BYTE	UpdateLocal;
/*0x0073e*/	BYTE	EnterZone;
/*0x0073f*/	BYTE	ExitGame;
/*0x00740*/ int		EnterZoneReason;
/*0x00744*/	bool	UseVoiceMacros;
/*0x00748*/	int		Deltax;
/*0x0074c*/	int		Deltay;
/*0x00750*/	int		OldRate1;
/*0x00754*/	int		OldRate2;
/*0x00758*/	float	StrafeRate;
/*0x0075c*/	int		SaveIndex;
/*0x00760*/	float	Unknown0x00760;
/*0x00764*/
//more data here will finish later.
}EVERQUESTINFO,*PEVERQUESTINFO;
#pragma pack(pop)

// size 0x20 -- brainiac 11/14/2016
typedef struct _tp_coords
{
/*0x00*/ int	Index;
/*0x04*/ float	Y;
/*0x08*/ float	X;
/*0x0C*/ float	Z;
/*0x10*/ float	Heading;
/*0x14*/ int	ZoneId;
/*0x18*/ int    FilterID;
/*0x1C*/ UINT   VehicleID;
/*0x20*/
} tp_coords,*Ptp_coords;

} // namespace EQClasses

using namespace EQClasses;
