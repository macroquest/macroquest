/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

#include "SharedClasses.h"

struct IShellFolder;

#pragma pack(push)
#pragma pack(8)

namespace EQClasses
{
// Other
class CXSize
{
public:
    DWORD A,B,C,D,E,F;
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
typedef struct _Personal_Loot
{
	CButtonWnd *NPC_Name;
	CButtonWnd *Item;
	CButtonWnd *Loot;
	CButtonWnd *Leave;
	CButtonWnd *AN;
	CButtonWnd *AG;
	CButtonWnd *Never;
} Personal_Loot, *PPersonal_Loot;
typedef struct _Shared_Loot
{
	CButtonWnd *NPC_Name;
	CButtonWnd *Item;
	CButtonWnd *Status;
	CButtonWnd *Action;
	CButtonWnd *Manage;
	CButtonWnd *AutoRoll;
	CButtonWnd *ND;
	CButtonWnd *GD;
	CButtonWnd *NO;
	CButtonWnd *AN;
	CButtonWnd *AG;
	CButtonWnd *NV;
} Shared_Loot, *PShared_Loot;

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
// Class declarations
class CXStr
{
public:
EQLIB_OBJECT operator const char*(void);
EQLIB_OBJECT CXStr::~CXStr();
EQLIB_OBJECT CXStr::CXStr(char const *);
EQLIB_OBJECT CXStr::CXStr(char const *,int);
EQLIB_OBJECT CXStr::CXStr(char);
EQLIB_OBJECT CXStr::CXStr(class CXStr const &);
EQLIB_OBJECT CXStr::CXStr(int,int,char);
EQLIB_OBJECT CXStr::CXStr(unsigned short const *);
EQLIB_OBJECT CXStr::CXStr(void);
EQLIB_OBJECT char *CXStr::operator char *(void)const;
EQLIB_OBJECT unsigned short *CXStr::operator unsigned short *(void)const;
EQLIB_OBJECT bool CXStr::Find(char,int &);
EQLIB_OBJECT bool CXStr::Find(class CXStr const &,int &);
EQLIB_OBJECT bool CXStr::Find(unsigned short,int &);
EQLIB_OBJECT bool CXStr::FindLast(char,int &);
EQLIB_OBJECT char CXStr::GetChar(long)const;
EQLIB_OBJECT char CXStr::operator[](int)const;
EQLIB_OBJECT char CXStr::SetChar(long,char);
EQLIB_OBJECT class CXStr & CXStr::operator=(char const *);
EQLIB_OBJECT class CXStr & CXStr::operator=(class CXStr const &);
EQLIB_OBJECT class CXStr CXStr::Copy(long,long)const;
EQLIB_OBJECT class CXStr CXStr::Left(int)const;
EQLIB_OBJECT class CXStr CXStr::Mid(int,int)const;
EQLIB_OBJECT class CXStr CXStr::Right(int)const;
//EQLIB_OBJECT enum EStringEncoding CXStr::GetEncoding(void)const;
EQLIB_OBJECT int __cdecl CXStr::PrintString(char const *,...);
//EQLIB_OBJECT int CXStr::Compare(class CXStr const &,enum CompareCode)const;
//EQLIB_OBJECT int CXStr::CompareN(class CXStr const &,int,enum CompareCode)const;
EQLIB_OBJECT int CXStr::ConvertToInt(void);
EQLIB_OBJECT int CXStr::operator==(char const *)const;
EQLIB_OBJECT int CXStr::operator==(class CXStr const &)const;
EQLIB_OBJECT int CXStr::operator>(class CXStr const &)const;
EQLIB_OBJECT long CXStr::GetLength(void)const;
EQLIB_OBJECT unsigned short CXStr::GetUnicode(long)const;
EQLIB_OBJECT unsigned short CXStr::SetUnicode(long,unsigned short);
//EQLIB_OBJECT void * CXStr::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CXStr::AddCr(void);
EQLIB_OBJECT void CXStr::Blank(void);
EQLIB_OBJECT void CXStr::BlankPreAllocate(int);
EQLIB_OBJECT void CXStr::CopySelf(long,long);
EQLIB_OBJECT void CXStr::Delete(long,long);
EQLIB_OBJECT void CXStr::Insert(long,char);
EQLIB_OBJECT void CXStr::Insert(long,class CXStr const &);
EQLIB_OBJECT void CXStr::operator+=(char const *);
EQLIB_OBJECT void CXStr::operator+=(char);
EQLIB_OBJECT void CXStr::operator+=(class CXStr const &);
EQLIB_OBJECT void CXStr::operator+=(unsigned short);
//EQLIB_OBJECT void CXStr::SetEncoding(enum EStringEncoding);
EQLIB_OBJECT void CXStr::SetLowerCase(void);
EQLIB_OBJECT void CXStr::SetUpperCase(void);
EQLIB_OBJECT void CXStr::Strip(char);
EQLIB_OBJECT void CXStr::StripAll(char);
EQLIB_OBJECT void CXStr::StripLeading(char);
EQLIB_OBJECT void CXStr::StripTrailing(char);
// protected
EQLIB_OBJECT static int __cdecl CXStr::LenUnicodeToUtf8(unsigned short const *);
EQLIB_OBJECT static int __cdecl CXStr::UnicodeToUtf8(unsigned short const *,char *,int);
EQLIB_OBJECT static int __cdecl CXStr::Utf8ToUnicode(char const *,unsigned short *,int);
//EQLIB_OBJECT struct CStrRep * CXStr::AllocRepNoLock(long,enum EStringEncoding);
//EQLIB_OBJECT void CXStr::Assure(long,enum EStringEncoding);
EQLIB_OBJECT void CXStr::AssureCopy(void);
EQLIB_OBJECT void CXStr::FreeRep(struct CStrRep *);
EQLIB_OBJECT void CXStr::FreeRepNoLock(struct CStrRep *);
// private
EQLIB_OBJECT void CXStr::CheckNoLock(void);
EQLIB_OBJECT void CXStr::SetString(const char* Str, long len);
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
class CXWnd
{
public:
	//CXWnd::CXWnd() {};
EQLIB_OBJECT void CXWnd::dCXWnd(void);
EQLIB_OBJECT CXWnd * CXWnd::SetParent(CXWnd *);
EQLIB_OBJECT enum UIType CXWnd::GetType();
EQLIB_OBJECT class CXMLData * CXWnd::GetXMLData();
EQLIB_OBJECT class CXWnd * CXWnd::GetChildItem(PCHAR Name);
EQLIB_OBJECT CXWnd::CXWnd(class CXWnd *,unsigned __int32,class CXRect);
EQLIB_OBJECT bool CXWnd::HasFocus(void)const;
EQLIB_OBJECT bool CXWnd::IsActive(void)const;
EQLIB_OBJECT bool CXWnd::IsDescendantOf(class CXWnd const *)const;
EQLIB_OBJECT bool CXWnd::IsEnabled(void)const;
EQLIB_OBJECT bool CXWnd::IsReallyVisible(void)const;
EQLIB_OBJECT bool CXWnd::IsType(EWndRuntimeType eType) const;
EQLIB_OBJECT class CButtonDrawTemplate const * CXWnd::GetCloseBoxTemplate(void)const;
EQLIB_OBJECT class CButtonDrawTemplate const * CXWnd::GetMinimizeBoxTemplate(void)const;
EQLIB_OBJECT class CButtonDrawTemplate const * CXWnd::GetTileBoxTemplate(void)const;
EQLIB_OBJECT class CTAFrameDraw const * CXWnd::GetBorderFrame(void)const;
EQLIB_OBJECT class CTAFrameDraw const * CXWnd::GetTitlebarHeader(void)const;
EQLIB_OBJECT class CXRect CXWnd::GetClientClipRect(void)const;
EQLIB_OBJECT class CXRect CXWnd::GetRelativeRect(void)const;
EQLIB_OBJECT class CXRect CXWnd::GetScreenClipRect(void)const;
EQLIB_OBJECT class CXRect CXWnd::GetScreenRect(void)const;
EQLIB_OBJECT class CXStr CXWnd::GetWindowTextA(void)const;
EQLIB_OBJECT class CXStr CXWnd::GetXMLTooltip(void)const;
EQLIB_OBJECT class CXWnd * CXWnd::GetChildItem(CXStr const &);
EQLIB_OBJECT class CXWnd * CXWnd::GetChildWndAt(class CXPoint *,int,int)const;
EQLIB_OBJECT class CXWnd * CXWnd::GetFirstChildWnd(void)const;
EQLIB_OBJECT class CXWnd * CXWnd::GetNextChildWnd(class CXWnd *)const;
EQLIB_OBJECT class CXWnd * CXWnd::GetNextSib(void)const;
EQLIB_OBJECT class CXWnd * CXWnd::SetFocus(void);
EQLIB_OBJECT int CXWnd::DoAllDrawing(void)const;
EQLIB_OBJECT int CXWnd::DrawChildren(void)const;
EQLIB_OBJECT int CXWnd::DrawCloseBox(void)const;
EQLIB_OBJECT int CXWnd::DrawHScrollbar(int,int,int)const;
EQLIB_OBJECT int CXWnd::DrawMinimizeBox(void)const;
EQLIB_OBJECT int CXWnd::DrawTileBox(void)const;
EQLIB_OBJECT int CXWnd::DrawVScrollbar(int,int,int)const;
EQLIB_OBJECT int CXWnd::GetWidth(void)const;
EQLIB_OBJECT int CXWnd::Minimize(bool);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT int CXWnd::Move(class CXPoint const &);
#else
EQLIB_OBJECT int CXWnd::Move(class CXPoint);
#endif
//CXWnd::Move (this is CXWnd__Move1_x) was checked on apr 29 2016 - eqmule
EQLIB_OBJECT int CXWnd::Move(class CXRect *, bool, bool, bool, bool);
EQLIB_OBJECT int CXWnd::ProcessTransition(void);
EQLIB_OBJECT int CXWnd::Resize(int Width, int Height, bool bUpdateLayout = true, bool bCompleteMoveOrResize = false, bool bMoveAutoStretch = false);
EQLIB_OBJECT int CXWnd::Show(bool bShow = true, bool bBringToTop = true, bool bUpdateLayout = true);
EQLIB_OBJECT int CXWnd::Tile(bool);
EQLIB_OBJECT static class CXRect __cdecl CXWnd::GetTooltipRect(class CXPoint,class CXSize);
//it looks like CXWnd::GetTooltipRect has 2 parameters in IDA but it only has 1. Note thats its a __cdecl so not a class member func... - eqmule apr 29 2016
EQLIB_OBJECT static class CXRect *__cdecl CXWnd::GetTooltipRect(class CXRect *);
EQLIB_OBJECT static class CXWndDrawTemplate CXWnd::sm_wdtDefaults;
EQLIB_OBJECT static int __cdecl CXWnd::DrawColoredRect(class CXRect,unsigned long,class CXRect);
EQLIB_OBJECT static int __cdecl CXWnd::DrawLasso(class CXRect,unsigned long,class CXRect);
EQLIB_OBJECT static int __cdecl CXWnd::DrawRaisedRect(class CXRect,class CXRect);
EQLIB_OBJECT static int __cdecl CXWnd::DrawSunkenRect(class CXRect,class CXRect);
EQLIB_OBJECT void CXWnd::Bottom(void);
EQLIB_OBJECT void CXWnd::BringChildWndToTop(class CXWnd *);
EQLIB_OBJECT void CXWnd::BringToTop(bool bRecurse = true);
EQLIB_OBJECT void CXWnd::Center(void);
EQLIB_OBJECT void CXWnd::ClrFocus(void);
EQLIB_OBJECT int CXWnd::Destroy(void);
EQLIB_OBJECT void CXWnd::DrawTooltipAtPoint(class CXPoint)const;
EQLIB_OBJECT void CXWnd::Left(void);
EQLIB_OBJECT void CXWnd::Refade(void);
EQLIB_OBJECT void CXWnd::Right(void);
EQLIB_OBJECT void CXWnd::SetFirstChildPointer(class CXWnd *);
EQLIB_OBJECT void CXWnd::SetKeyTooltip(int,int);
EQLIB_OBJECT void CXWnd::SetLookLikeParent(void);
EQLIB_OBJECT void CXWnd::SetMouseOver(bool);
EQLIB_OBJECT void CXWnd::SetNextSibPointer(class CXWnd *);
EQLIB_OBJECT void CXWnd::SetTooltip(class CXStr);
EQLIB_OBJECT void CXWnd::SetXMLTooltip(class CXStr);
EQLIB_OBJECT void CXWnd::SetZLayer(int);
EQLIB_OBJECT void CXWnd::StartFade(unsigned char,unsigned __int32);
// virtual
EQLIB_OBJECT bool CXWnd::IsPointTransparent(class CXPoint)const;
EQLIB_OBJECT bool CXWnd::IsValid(void)const;
EQLIB_OBJECT bool CXWnd::QueryClickStickDropOK(class CClickStickInfo *)const;
EQLIB_OBJECT bool CXWnd::QueryDropOK(struct SDragDropInfo *)const;
EQLIB_OBJECT class CTextureAnimation * CXWnd::GetClickStickCursor(class CClickStickInfo *)const;
EQLIB_OBJECT class CTextureAnimation * CXWnd::GetCursorToDisplay(void)const;
EQLIB_OBJECT class CTextureAnimation * CXWnd::GetDragDropCursor(struct SDragDropInfo *)const;
EQLIB_OBJECT class CXRect CXWnd::GetClientRect(void)const;
EQLIB_OBJECT class CXRect CXWnd::GetHitTestRect(int)const;
EQLIB_OBJECT class CXRect CXWnd::GetInnerRect(void)const;
EQLIB_OBJECT class CXRect CXWnd::GetMinimizedRect(void)const;
EQLIB_OBJECT class CXSize CXWnd::GetMinSize(void)const;
EQLIB_OBJECT class CXSize CXWnd::GetUntileSize(void)const;
EQLIB_OBJECT class CXStr CXWnd::GetTooltip(void)const;
EQLIB_OBJECT int CXWnd::AboutToDeleteWnd(class CXWnd *);
EQLIB_OBJECT int CXWnd::Draw(void)const;
EQLIB_OBJECT int CXWnd::DrawBackground(void)const;
EQLIB_OBJECT int CXWnd::DrawCaret(void)const;
EQLIB_OBJECT int CXWnd::DrawChildItem(class CXWnd const *,void *)const;
EQLIB_OBJECT int CXWnd::DrawCursor(class CXPoint,class CXRect,bool &);
EQLIB_OBJECT int CXWnd::DrawNC(void)const;
EQLIB_OBJECT int CXWnd::DrawTitleBar(class CXRect)const;
EQLIB_OBJECT int CXWnd::DrawTooltip(class CXWnd const *)const;
EQLIB_OBJECT int CXWnd::HandleKeyboardMsg(unsigned __int32,unsigned __int32,bool);
EQLIB_OBJECT int CXWnd::HandleLButtonDown(class CXPoint *,unsigned __int32);
EQLIB_OBJECT int CXWnd::HandleLButtonHeld(class CXPoint *,unsigned __int32);
EQLIB_OBJECT int CXWnd::HandleLButtonUp(class CXPoint *,unsigned __int32);
EQLIB_OBJECT int CXWnd::HandleLButtonUpAfterHeld(class CXPoint *,unsigned __int32);
EQLIB_OBJECT int CXWnd::HandleMouseMove(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CXWnd::HandleRButtonDown(class CXPoint *,unsigned __int32);
EQLIB_OBJECT int CXWnd::HandleRButtonHeld(class CXPoint *,unsigned __int32);
EQLIB_OBJECT int CXWnd::HandleRButtonUp(class CXPoint *,unsigned __int32);
EQLIB_OBJECT int CXWnd::HandleRButtonUpAfterHeld(class CXPoint *,unsigned __int32);
EQLIB_OBJECT int CXWnd::HandleWheelButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CXWnd::HandleWheelButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CXWnd::HandleWheelMove(class CXPoint,int,unsigned __int32);
EQLIB_OBJECT int CXWnd::HitTest(class CXPoint,int *)const;
EQLIB_OBJECT int CXWnd::OnActivate(class CXWnd *);
EQLIB_OBJECT int CXWnd::OnBroughtToTop(void);
EQLIB_OBJECT int CXWnd::OnClickStick(class CClickStickInfo *,unsigned __int32,bool);
EQLIB_OBJECT int CXWnd::OnDragDrop(struct SDragDropInfo *);
EQLIB_OBJECT int CXWnd::OnHScroll(EScrollCode,int);
EQLIB_OBJECT int CXWnd::OnKillFocus(class CXWnd *);
EQLIB_OBJECT int CXWnd::OnMinimizeBox(void);
EQLIB_OBJECT int CXWnd::OnMove(class CXRect);
EQLIB_OBJECT int CXWnd::OnProcessFrame(void);
EQLIB_OBJECT int CXWnd::OnResize(int,int);
EQLIB_OBJECT int CXWnd::OnSetFocus(class CXWnd *);
EQLIB_OBJECT int CXWnd::OnShow(void);
EQLIB_OBJECT int CXWnd::OnTile(void);
EQLIB_OBJECT int CXWnd::OnTileBox(void);
EQLIB_OBJECT int CXWnd::OnVScroll(EScrollCode,int);
EQLIB_OBJECT int CXWnd::PostDraw(void)const;
//EQLIB_OBJECT int CXWnd::RequestDockInfo(enum EDockAction,class CXWnd *,class CXRect *);
EQLIB_OBJECT int CXWnd::SetVScrollPos(int);
EQLIB_OBJECT int CXWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CXWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CXWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CXWnd::Deactivate(void);
EQLIB_OBJECT void CXWnd::OnReloadSidl(void);
EQLIB_OBJECT void CXWnd::SetAttributesFromSidl(class CParamScreenPiece *);
EQLIB_OBJECT void CXWnd::SetDrawTemplate(class CXWndDrawTemplate *);
EQLIB_OBJECT void CXWnd::SetWindowTextA(class CXStr &);
// protected
EQLIB_OBJECT static class CXWndManager * & CXWnd::sm_pMgr;
// private
EQLIB_OBJECT static unsigned char CXWnd::sm_byCurrentAlpha;
EQLIB_OBJECT int CXWnd::SetFont(void*);
	int GetHScrollRange() const {return HScrollMax;}
	int GetVScrollRange() const {return VScrollMax;}
	int GetHScrollPos() const {return HScrollPos;}
	int GetVScrollPos() const {return VScrollPos;}
CXW;

};

#define ZoneToGoTo 0

class CSidlScreenWnd
{
public:
	void SetStyle(DWORD Style) {WindowStyle = Style;}
	DWORD GetStyle() const {return WindowStyle;}
	int GetContextMenuIndex() { return ContextMenuID; }
EQLIB_OBJECT enum UIType CSidlScreenWnd::GetType();
EQLIB_OBJECT class CXMLData * CSidlScreenWnd::GetXMLData();
EQLIB_OBJECT class CXWnd * CSidlScreenWnd::GetChildItem(PCHAR Name);
EQLIB_OBJECT CSidlScreenWnd::CSidlScreenWnd() {};
EQLIB_OBJECT CSidlScreenWnd::CSidlScreenWnd(class CXWnd *,class CXStr);
EQLIB_OBJECT CSidlScreenWnd::CSidlScreenWnd(class CXWnd *pWnd,class CXStr *Template,int Flags,int unknown4, char *unknown5);
EQLIB_OBJECT CSidlScreenWnd::CSidlScreenWnd(class CXWnd *,unsigned __int32,class CXRect,class CXStr);
EQLIB_OBJECT CScreenPieceTemplate *CSidlScreenWnd::GetSidlPiece(class CXStr*, bool bTopLevel=true)const;
EQLIB_OBJECT class CXRect CSidlScreenWnd::GetSidlPieceRect(class CScreenPieceTemplate *,class CXRect)const;
EQLIB_OBJECT class CXWnd *CSidlScreenWnd::GetChildItem(CXStr const &, bool bDebug);
EQLIB_OBJECT int CSidlScreenWnd::DrawSidlPiece(class CScreenPieceTemplate *,class CXRect,class CXRect)const;
EQLIB_OBJECT void CSidlScreenWnd::AddButtonToRadioGroup(class CXStr,class CButtonWnd *);
EQLIB_OBJECT void CSidlScreenWnd::CalculateHSBRange(void);
EQLIB_OBJECT void CSidlScreenWnd::CalculateVSBRange(void);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT void CSidlScreenWnd::CreateChildrenFromSidl(DWORD = 0);
#else
EQLIB_OBJECT void CSidlScreenWnd::CreateChildrenFromSidl(void);
#endif
EQLIB_OBJECT void CSidlScreenWnd::EnableIniStorage(int,char *);
EQLIB_OBJECT void CSidlScreenWnd::Init(int,class CXStr*,int,int,int);
EQLIB_OBJECT void CSidlScreenWnd::Init(class CXWnd *,unsigned __int32,class CXRect,class CXStr,int,char *);
EQLIB_OBJECT void CSidlScreenWnd::LoadIniListWnd(class CListWnd *,char *);
EQLIB_OBJECT void CSidlScreenWnd::SetScreen(class CXStr*);
EQLIB_OBJECT void CSidlScreenWnd::StoreIniListWnd(class CListWnd const *,char *);
EQLIB_OBJECT void CSidlScreenWnd::StoreIniVis(void);
// virtual
EQLIB_OBJECT CSidlScreenWnd::~CSidlScreenWnd(void);
EQLIB_OBJECT int CSidlScreenWnd::DrawBackground(void)const;
EQLIB_OBJECT int CSidlScreenWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSidlScreenWnd::HandleRButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSidlScreenWnd::OnResize(int,int);
EQLIB_OBJECT int CSidlScreenWnd::OnShow(void);
EQLIB_OBJECT int CSidlScreenWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CSidlScreenWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CSidlScreenWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSidlScreenWnd::LoadIniInfo(void);
EQLIB_OBJECT void CSidlScreenWnd::StoreIniInfo(void);
// protected
EQLIB_OBJECT int CSidlScreenWnd::ConvertToRes(int,int,int,int);
EQLIB_OBJECT void CSidlScreenWnd::LoadSidlScreen(void);
// private
EQLIB_OBJECT static bool CSidlScreenWnd::m_useIniFile;

inline CXWnd *pXWnd() {return (CXWnd*)this;};
CSW
};

class _EverQuestinfo
{
public:
EQLIB_OBJECT void _EverQuestinfo::SetAutoAttack(bool);
};

class _PackFileData
{
public:
EQLIB_OBJECT _PackFileData::~_PackFileData(void);
// virtual
EQLIB_OBJECT int _PackFileData::readBlock(void);
};

class _PackFileDataRawFile
{
public:
// virtual
EQLIB_OBJECT int _PackFileDataRawFile::readBlock(void);
};

class _partyGroup
{
public:
EQLIB_OBJECT int _partyGroup::getNumMembers(void)const;
};

class CAdvancedLootWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CAdvancedLootWnd::CAdvancedLootWnd(class CXWnd *);
EQLIB_OBJECT DWORD CAdvancedLootWnd::DoAdvLootAction(DWORD listindex, CXStr *Name, DWORD Action, DWORD Quantity);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT DWORD CAdvancedLootWnd::DoSharedAdvLootAction(PLOOTITEM pLootItem,CXStr *Assignee, DWORD Action, DWORD Quantity);
#endif
// virtual
EQLIB_OBJECT CAdvancedLootWnd::~CAdvancedLootWnd(void);
};

class CRewardSelectionWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CRewardSelectionWnd::CRewardSelectionWnd(class CXWnd *);
	// virtual
	EQLIB_OBJECT CRewardSelectionWnd::~CRewardSelectionWnd(void);
};

class CAltAbilityData
{
public:
EQLIB_OBJECT int CAltAbilityData::GetMercCurrentRank(int);
EQLIB_OBJECT int CAltAbilityData::GetMercMaxRank(int);
EQLIB_OBJECT int CAltAbilityData::GetMaxRank(void);//it really is called GetMaxLevel but that doesnt make sense to me so... rank it is... -eqmule

};

class AltAdvManager
{
public:
EQLIB_OBJECT AltAdvManager::AltAdvManager(void);
//AltAdvManager::IsAbilityReady was checked on apr 29 2016, it looks like it has 5 arguments in IDA, but it doesnt. (it has 4)
EQLIB_OBJECT bool AltAdvManager::IsAbilityReady(class EQ_PC *,EQData::PALTABILITY,int *Refresh/*out*/,int *Timer/*out*/ = 0);
EQLIB_OBJECT int AltAdvManager::AbilitiesByClass(int,int);
EQLIB_OBJECT int AltAdvManager::AltSkillReqs(class EQ_PC *,int);
EQLIB_OBJECT int AltAdvManager::CalculateDoubleAttackChance(class EQ_PC *,int,unsigned char);
EQLIB_OBJECT int AltAdvManager::CalculateFleetOfFoot(class EQ_PC *);
EQLIB_OBJECT int AltAdvManager::CalculateHideTimeReduce(class EQ_PC *);
EQLIB_OBJECT int AltAdvManager::CalculateInstrumentMasteryMod(class EQ_PC *);
EQLIB_OBJECT int AltAdvManager::CalculateLoHHarmTouchReuseTimer(class EQ_PC *,int);
EQLIB_OBJECT int AltAdvManager::CalculateMaxHPAA(class EQ_PC *,int);
EQLIB_OBJECT int AltAdvManager::CalculateMaxStatAA(class EQ_PC *,int);
EQLIB_OBJECT int AltAdvManager::CalculateMitigationBoost(class EQ_PC *,int);
EQLIB_OBJECT int AltAdvManager::CalculateNimbleEvasionChance(class EQ_PC *);
EQLIB_OBJECT int AltAdvManager::CalculateSingingMasteryMod(class EQ_PC *,int);
EQLIB_OBJECT int AltAdvManager::CalculateSpellCastingMastery(class EQ_PC *);
EQLIB_OBJECT int AltAdvManager::CalculateStalwartEnduranceChance(class EQ_PC *);
EQLIB_OBJECT bool AltAdvManager::CanTrainAbility(class PcZoneClient *, class CAltAbilityData *, bool, bool, bool);
EQLIB_OBJECT bool AltAdvManager::CanSeeAbility(class PcZoneClient *, class CAltAbilityData *);
EQLIB_OBJECT int AltAdvManager::GetAALevelNeeded(class EQ_PC *,int);
EQLIB_OBJECT int AltAdvManager::GetAbilityTitle(class EQPlayer *);
EQLIB_OBJECT int AltAdvManager::GetNextAbilityCost(int,int);
EQLIB_OBJECT int AltAdvManager::MeetsPoPLevelReqs(class EQ_PC *,int,int);
EQLIB_OBJECT int AltAdvManager::TotalPointsInSkill(int,int);
EQLIB_OBJECT unsigned long AltAdvManager::GetCalculatedTimer(class EQ_PC *,EQData::PALTABILITY);
EQLIB_OBJECT void AltAdvManager::GetAbilityReqs(char *,int);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT struct _ALTABILITY *AltAdvManager::GetAAById(int index, int level = -1);
#else
EQLIB_OBJECT struct _ALTABILITY *AltAdvManager::GetAAById(int index);
#endif
};
class CAuraWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CAuraWnd::CAuraWnd(class CXWnd *);
// virtual
EQLIB_OBJECT CAuraWnd::~CAuraWnd(void);
};
class bad_word_class
{
public:
EQLIB_OBJECT bad_word_class::bad_word_class(char *);
};

class CAAWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CAAWnd::CAAWnd(class CXWnd *);
EQLIB_OBJECT void CAAWnd::Activate(void);
EQLIB_OBJECT void CAAWnd::CancelAASpend(void);
EQLIB_OBJECT void CAAWnd::ConfirmAASpend(void);
EQLIB_OBJECT void CAAWnd::SendNewPercent(void);
EQLIB_OBJECT void CAAWnd::ShowAbility(int);
EQLIB_OBJECT void CAAWnd::Update(void);
EQLIB_OBJECT void CAAWnd::UpdateTimer(void);
// virtual
EQLIB_OBJECT CAAWnd::~CAAWnd(void);
EQLIB_OBJECT int CAAWnd::OnProcessFrame(void);
EQLIB_OBJECT int CAAWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CAAWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CAAWnd::`vector deleting destructor'(unsigned int);
#define SafeZLoc 0
EQLIB_OBJECT void CAAWnd::Deactivate(void);
// private
EQLIB_OBJECT void CAAWnd::Init(void);
EQLIB_OBJECT void CAAWnd::UpdateSelected(void);
};

class CActionsWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CActionsWnd::CActionsWnd(class CXWnd *);
EQLIB_OBJECT class CButtonWnd * CActionsWnd::GetAbilityBtn(int);
EQLIB_OBJECT class CButtonWnd * CActionsWnd::GetCombatBtn(int);
EQLIB_OBJECT class CButtonWnd * CActionsWnd::GetMenuBtn(int);
EQLIB_OBJECT int CActionsWnd::GetCurrentPageEnum(void)const;
EQLIB_OBJECT void CActionsWnd::Activate(int);
EQLIB_OBJECT void CActionsWnd::KeyMapUpdated(void);
EQLIB_OBJECT void CActionsWnd::SelectSkillForAbilityBtn(int);
EQLIB_OBJECT void CActionsWnd::SelectSkillForCombatBtn(int);
EQLIB_OBJECT void CActionsWnd::UpdateButtonText(void);
// virtual
EQLIB_OBJECT CActionsWnd::~CActionsWnd(void);
EQLIB_OBJECT int CActionsWnd::OnProcessFrame(void);
EQLIB_OBJECT int CActionsWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CActionsWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CActionsWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CActionsWnd::Deactivate(void);
// private
EQLIB_OBJECT int CActionsWnd::AbilitiesPageActivate(void);
EQLIB_OBJECT int CActionsWnd::AbilitiesPageDeactivate(void);
EQLIB_OBJECT int CActionsWnd::AbilitiesPageOnProcessFrame(void);
EQLIB_OBJECT int CActionsWnd::AbilitiesPageWndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int CActionsWnd::CombatPageActivate(void);
EQLIB_OBJECT int CActionsWnd::CombatPageDeactivate(void);
EQLIB_OBJECT int CActionsWnd::CombatPageOnProcessFrame(void);
EQLIB_OBJECT int CActionsWnd::CombatPageWndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int CActionsWnd::MainPageActivate(void);
EQLIB_OBJECT int CActionsWnd::MainPageDeactivate(void);
EQLIB_OBJECT int CActionsWnd::MainPageOnProcessFrame(void);
EQLIB_OBJECT int CActionsWnd::MainPageWndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int CActionsWnd::RedirectActivateTo(class CPageWnd *);
EQLIB_OBJECT int CActionsWnd::RedirectDeactivateTo(class CPageWnd *);
EQLIB_OBJECT int CActionsWnd::RedirectOnProcessFrameTo(class CPageWnd *);
EQLIB_OBJECT int CActionsWnd::RedirectWndNotificationTo(class CPageWnd *,class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int CActionsWnd::SocialsPageActivate(void);
EQLIB_OBJECT int CActionsWnd::SocialsPageDeactivate(void);
EQLIB_OBJECT int CActionsWnd::SocialsPageOnProcessFrame(void);
EQLIB_OBJECT int CActionsWnd::SocialsPageWndNotification(class CXWnd *,unsigned __int32,void *);
};

class CAchievementsWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CAchievementsWnd::CAchievementsWnd(class CXWnd *);
};
class CRealEstateItemsWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CRealEstateItemsWnd::CRealEstateItemsWnd(class CXWnd *);
};

class CAlarmWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CAlarmWnd::CAlarmWnd(class CXWnd *);
EQLIB_OBJECT void CAlarmWnd::Activate(void);
// virtual
EQLIB_OBJECT CAlarmWnd::~CAlarmWnd(void);
EQLIB_OBJECT int CAlarmWnd::OnProcessFrame(void);
EQLIB_OBJECT int CAlarmWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CAlarmWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CAlarmWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CAlarmWnd::Deactivate(void);
// private
EQLIB_OBJECT void CAlarmWnd::DoNeverButton(void);
};

class CBankWnd : public CSidlScreenWnd//, public WndEventHandler but we just add the member LastCheckTime
{
public:
/*0x238*/ UINT LastCheckTime;//from WndEventHandler
/*0x23c*/ int MoneyButtonIndex;
/*0x240*/ UINT NextRefreshTime;
/*0x244*/ bool bInventoryWasActive;
/*0x245*/ bool bRealEstateManagementWasActive;
/*0x248*/ CButtonWnd  *MoneyButtons[5];//including shared plat
/*0x25C*/ CLabel *BankerNameLabel;
/*0x260*/ CInvSlotWnd *InvSlotWindows[NUM_BANK_SLOTS];
/*0x2C0*/ CLabel *SharedBankLabel;
/*0x2C4*/ CInvSlotWnd *SharedSlotWindows[NUM_SHAREDBANK_SLOTS];
/*0x2DC*/ CButtonWnd *DoneButton;
/*0x2E0*/ CButtonWnd *ChangeButton;
/*0x2E4*/ CButtonWnd *AutoButton;
/*0x2E8*/ CButtonWnd *AltStorageButton;
/*0x2EC*/ CButtonWnd *FindItemButton;
/*0x2F0*/ int BankSize;
/*0x2F4*/ int Unknown0x2F4;
/*0x2F8*/ 
EQLIB_OBJECT CBankWnd::CBankWnd(class CXWnd *,class CXStr);
EQLIB_OBJECT int CBankWnd::GetNumBankSlots(void)const;
EQLIB_OBJECT void CBankWnd::Activate(class EQPlayer *);
EQLIB_OBJECT void CBankWnd::Deactivate(bool);
// virtual
EQLIB_OBJECT CBankWnd::~CBankWnd(void);
EQLIB_OBJECT int CBankWnd::OnProcessFrame(void);
EQLIB_OBJECT int CBankWnd::PostDraw(void)const;
EQLIB_OBJECT int CBankWnd::WndNotification(CXWnd *pWnd, unsigned int uiMessage, void* pData);
//EQLIB_OBJECT void * CBankWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CBankWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CBankWnd::Deactivate(void);
// private
EQLIB_OBJECT long CBankWnd::GetBankQtyFromCoinType(int);
EQLIB_OBJECT void CBankWnd::ClickedMoneyButton(int,int);
EQLIB_OBJECT void CBankWnd::Init(void);
EQLIB_OBJECT void CBankWnd::UpdateMoneyDisplay(void);
};

class CBazaarSearchWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CBazaarSearchWnd::CBazaarSearchWnd(class CXWnd *);
EQLIB_OBJECT char * CBazaarSearchWnd::GetPriceString(unsigned long);
EQLIB_OBJECT void CBazaarSearchWnd::Activate(void);
EQLIB_OBJECT void CBazaarSearchWnd::HandleBazaarMsg(char *,int);
EQLIB_OBJECT void CBazaarSearchWnd::UpdatePlayerCombo(void);
EQLIB_OBJECT void CBazaarSearchWnd::UpdatePlayerUpdateButton(bool);
// virtual
EQLIB_OBJECT CBazaarSearchWnd::~CBazaarSearchWnd(void);
EQLIB_OBJECT int CBazaarSearchWnd::Draw(void)const;
EQLIB_OBJECT int CBazaarSearchWnd::OnProcessFrame(void);
EQLIB_OBJECT int CBazaarSearchWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CBazaarSearchWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CBazaarSearchWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CBazaarSearchWnd::Deactivate(void);
// private
EQLIB_OBJECT void CBazaarSearchWnd::AddItemtoList(char *,unsigned long,char *,int,int);
EQLIB_OBJECT void CBazaarSearchWnd::doQuery(void);
EQLIB_OBJECT void CBazaarSearchWnd::Init(void);
EQLIB_OBJECT void CBazaarSearchWnd::InitListArray(void);
EQLIB_OBJECT void CBazaarSearchWnd::SortItemList(int);
EQLIB_OBJECT void CBazaarSearchWnd::UpdateComboButtons(void);
};

class CBazaarWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CBazaarWnd::CBazaarWnd(class CXWnd *);
EQLIB_OBJECT bool CBazaarWnd::StoreSelectedPrice(void);
EQLIB_OBJECT char * CBazaarWnd::GetPriceString(unsigned long);
EQLIB_OBJECT class EQ_Item * CBazaarWnd::ReturnItemByIndex(int);
EQLIB_OBJECT int CBazaarWnd::UpdateBazaarListtoServer(void);
EQLIB_OBJECT long CBazaarWnd::GetQtyFromCoinType(int);
EQLIB_OBJECT unsigned long CBazaarWnd::GetPrice(void);
EQLIB_OBJECT void CBazaarWnd::Activate(void);
EQLIB_OBJECT void CBazaarWnd::AddBazaarText(char *,int);
EQLIB_OBJECT void CBazaarWnd::AddEquipmentToBazaarArray(class EQ_Item *,int,unsigned long);
EQLIB_OBJECT void CBazaarWnd::BuildBazaarItemArray(void);
EQLIB_OBJECT void CBazaarWnd::ClickedMoneyButton(int,int);
EQLIB_OBJECT void CBazaarWnd::HandleTraderMsg(char *);
EQLIB_OBJECT void CBazaarWnd::RebuildItemArray(void);
EQLIB_OBJECT void CBazaarWnd::SelectBazaarSlotItem(int,class CTextureAnimation *);
EQLIB_OBJECT void CBazaarWnd::SetMoneyButton(int,int);
EQLIB_OBJECT void CBazaarWnd::UpdatePriceButtons(void);
// virtual
EQLIB_OBJECT CBazaarWnd::~CBazaarWnd(void);
EQLIB_OBJECT int CBazaarWnd::OnProcessFrame(void);
EQLIB_OBJECT int CBazaarWnd::PostDraw(void)const;
EQLIB_OBJECT int CBazaarWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CBazaarWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CBazaarWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CBazaarWnd::Deactivate(void);
// protected
EQLIB_OBJECT void CBazaarWnd::UpdateButtons(void);
// private
EQLIB_OBJECT void CBazaarWnd::CreateBZRIniFilename(void);
EQLIB_OBJECT void CBazaarWnd::Init(void);
EQLIB_OBJECT void CBazaarWnd::ToggleBzrItemActive(int,bool);
};

class CBodyTintWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CBodyTintWnd::CBodyTintWnd(class CXWnd *);
EQLIB_OBJECT char * CBodyTintWnd::BuildRBGTooltip(unsigned long,char * const);
EQLIB_OBJECT unsigned long CBodyTintWnd::GetButtonTint(int);
EQLIB_OBJECT unsigned long CBodyTintWnd::GetItemTint(int);
EQLIB_OBJECT void CBodyTintWnd::Activate(void);
EQLIB_OBJECT void CBodyTintWnd::GetReagentCount(void);
EQLIB_OBJECT void CBodyTintWnd::GetTintChangeCount(void);
EQLIB_OBJECT void CBodyTintWnd::ResetToOrigBodyTints(void);
EQLIB_OBJECT void CBodyTintWnd::SetSlotLabels(bool);
EQLIB_OBJECT void CBodyTintWnd::StoreModifiedBodyTints(void);
EQLIB_OBJECT void CBodyTintWnd::UpdateLabelsAndButtons(void);
EQLIB_OBJECT void CBodyTintWnd::UpdateLocalTintColor(unsigned long);
EQLIB_OBJECT void CBodyTintWnd::UpdateMaterialTintLocal(unsigned long);
// virtual
EQLIB_OBJECT CBodyTintWnd::~CBodyTintWnd(void);
EQLIB_OBJECT int CBodyTintWnd::OnProcessFrame(void);
EQLIB_OBJECT int CBodyTintWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CBodyTintWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CBodyTintWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CBodyTintWnd::Deactivate(void);
};

class CBookWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CBookWnd::CBookWnd(class CXWnd *);
EQLIB_OBJECT bool CBookWnd::CheckBook(class EQ_Note *);
EQLIB_OBJECT void CBookWnd::Activate(void);
EQLIB_OBJECT void CBookWnd::SetBook(char *);
// virtual
EQLIB_OBJECT CBookWnd::~CBookWnd(void);
EQLIB_OBJECT int CBookWnd::HandleKeyboardMsg(unsigned __int32,unsigned __int32,bool);
EQLIB_OBJECT int CBookWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CBookWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CBookWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CBookWnd::Deactivate(void);
// protected
EQLIB_OBJECT void CBookWnd::CleanPages(void);
EQLIB_OBJECT void CBookWnd::DisplayText(void);
EQLIB_OBJECT void CBookWnd::ProcessText(void);
EQLIB_OBJECT void CBookWnd::ShowButtons(void);
// private
EQLIB_OBJECT void CBookWnd::Init(void);
};

class CBreathWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CBreathWnd::CBreathWnd(class CXWnd *);
EQLIB_OBJECT void CBreathWnd::Activate(void);
// virtual
EQLIB_OBJECT CBreathWnd::~CBreathWnd(void);
EQLIB_OBJECT int CBreathWnd::OnProcessFrame(void);
//EQLIB_OBJECT void * CBreathWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CBreathWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CBreathWnd::Deactivate(void);
// private
EQLIB_OBJECT void CBreathWnd::Init(void);
};

class CBuffWindow : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CBuffWindow::CBuffWindow(class CXWnd *,enum BuffWindowType);
EQLIB_OBJECT void CBuffWindow::Activate(void);
EQLIB_OBJECT void CBuffWindow::SetBuffIcon(class CButtonWnd *,int,int);
// virtual
EQLIB_OBJECT CBuffWindow::~CBuffWindow(void);
EQLIB_OBJECT class CXSize CBuffWindow::GetMinSize(void)const;
EQLIB_OBJECT int CBuffWindow::OnProcessFrame(void);
EQLIB_OBJECT int CBuffWindow::PostDraw(void)const;
EQLIB_OBJECT int CBuffWindow::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CBuffWindow::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CBuffWindow::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CBuffWindow::Deactivate(void);
// private
EQLIB_OBJECT void CBuffWindow::HandleSpellInfoDisplay(class CXWnd *);
EQLIB_OBJECT void CBuffWindow::Init(void);
EQLIB_OBJECT void CBuffWindow::RefreshBuffDisplay(void);
EQLIB_OBJECT void CBuffWindow::RefreshIconArrangement(void);
};

class CBugReportWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CBugReportWnd::CBugReportWnd(class CXWnd *);
EQLIB_OBJECT void CBugReportWnd::Activate(void);
// virtual
EQLIB_OBJECT CBugReportWnd::~CBugReportWnd(void);
EQLIB_OBJECT int CBugReportWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CBugReportWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CBugReportWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CBugReportWnd::Deactivate(void);
// private
EQLIB_OBJECT void CBugReportWnd::UpdateLocation(void);
};

class CButtonDrawTemplate
{
public:
	CXStr	Name;
    CTextureAnimation   *Normal;
    CTextureAnimation   *Pressed;
    CTextureAnimation   *Flyby;
    CTextureAnimation   *Disabled;
    CTextureAnimation   *PressedFlyby;
	CTextureAnimation   *PressedDisabled;
    CTextureAnimation   *NormalDecal;
    CTextureAnimation   *PressedDecal;
    CTextureAnimation   *FlybyDecal;
    CTextureAnimation   *DisabledDecal;
    CTextureAnimation   *PressedFlybyDecal;
	CTextureAnimation   *PressedDisabledDecal;
EQLIB_OBJECT CButtonDrawTemplate::~CButtonDrawTemplate(void);
EQLIB_OBJECT CButtonDrawTemplate::CButtonDrawTemplate(class CButtonDrawTemplate const &);
EQLIB_OBJECT CButtonDrawTemplate::CButtonDrawTemplate(void);
EQLIB_OBJECT class CButtonDrawTemplate & CButtonDrawTemplate::operator=(class CButtonDrawTemplate const &);
EQLIB_OBJECT class CXSize CButtonDrawTemplate::GetSize(void)const;
};

class CButtonTemplate
{
public:
EQLIB_OBJECT CButtonTemplate::CButtonTemplate(class CParamButton *);
// virtual
EQLIB_OBJECT CButtonTemplate::~CButtonTemplate(void);
//EQLIB_OBJECT void * CButtonTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CButtonTemplate::`vector deleting destructor'(unsigned int);
};

class CButtonWnd : public CXWnd
{
public:
/*0x1e0*/	int MouseButtonState;
/*0x1e4*/	bool bImage;
/*0x1e8*/	CRadioGroup	*RadioGroup;
/*0x1ec*/	bool Checked;
/*0x1ed*/   bool Highlighted;
/*0x1f0*/	tagPOINT	DecalOffset;
/*0x1f8*/	tagSIZE		DecalSize;
/*0x200*/	COLORREF	DecalTint;
/*0x204*/	RECT		TextOffsets;
/*0x214*/	int			TextMode;
/*0x218*/	COLORREF	MouseoverColor;
/*0x21c*/	COLORREF	PressedColor;
/*0x220*/	COLORREF	DisabledColor;
/*0x224*/	UINT		CoolDownStartTime;
/*0x228*/	UINT		CoolDownDuration;
/*0x22c*/	struct  _CXSTR*Indicator;
/*0x230*/   UINT		IndicatorValue;
/*0x234*/   void* pIndicatorTextObject;
/*0x238*/   struct  _CXSTR*Name;
    CTextureAnimation   *TANormal;
    CTextureAnimation   *TAPressed;
    CTextureAnimation   *TAFlyby;
    CTextureAnimation   *TADisabled;
    CTextureAnimation   *TAPressedFlyby;
	CTextureAnimation   *TAPressedDisabled;
    CTextureAnimation   *TANormalDecal;
    CTextureAnimation   *TAPressedDecal;
    CTextureAnimation   *TAFlybyDecal;
    CTextureAnimation   *TADisabledDecal;
    CTextureAnimation   *TAPressedFlybyDecal;
	CTextureAnimation   *TAPressedDisabledDecal;
	bool bAllowButtonPassThrough;
	bool bCooldownrelated;
	bool bIsCheckbox;
	bool bDrawLasso;//draws the yellow border...
	unsigned __int32 ButtonStyle;
EQLIB_OBJECT CButtonWnd::CButtonWnd(class CXWnd *,unsigned __int32,class CXRect,class CXPoint,class CXSize,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *);
EQLIB_OBJECT void CButtonWnd::SetCheck(bool);
// virtual
//EQLIB_OBJECT CButtonWnd::CButtonWnd() {};
EQLIB_OBJECT CButtonWnd::~CButtonWnd(void);
EQLIB_OBJECT bool CButtonWnd::IsPointTransparent(class CXPoint)const;
EQLIB_OBJECT int CButtonWnd::Draw(void)const;
EQLIB_OBJECT int CButtonWnd::HandleLButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CButtonWnd::HandleLButtonHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CButtonWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CButtonWnd::HandleLButtonUpAfterHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CButtonWnd::HandleMouseMove(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CButtonWnd::HandleRButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CButtonWnd::HandleRButtonHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CButtonWnd::HandleRButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CButtonWnd::HandleRButtonUpAfterHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CButtonWnd::OnProcessFrame(void);
//EQLIB_OBJECT void * CButtonWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CButtonWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CButtonWnd::SetAttributesFromSidl(class CParamScreenPiece *);
EQLIB_OBJECT void CButtonWnd::SetRadioGroup(class CRadioGroup *);
EQLIB_OBJECT UINT CButtonWnd::GetCoolDownTotalDuration() const;
EQLIB_OBJECT UINT CButtonWnd::GetCoolDownTimeRemaining() const;
};

class CCastingWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CCastingWnd::CCastingWnd(class CXWnd *);
EQLIB_OBJECT void CCastingWnd::Activate(void);
// virtual
EQLIB_OBJECT CCastingWnd::~CCastingWnd(void);
EQLIB_OBJECT int CCastingWnd::OnProcessFrame(void);
//EQLIB_OBJECT void * CCastingWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CCastingWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CCastingWnd::Deactivate(void);
};

class CCastSpellWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CCastSpellWnd::CCastSpellWnd(class CXWnd *);
//EQLIB_OBJECT CCastSpellWnd::SpellCategoryMajor::~SpellCategoryMajor(void);
//EQLIB_OBJECT CCastSpellWnd::SpellCategoryMinor::~SpellCategoryMinor(void);
EQLIB_OBJECT static void __cdecl CCastSpellWnd::Unmemorize(int);
EQLIB_OBJECT static void __cdecl CCastSpellWnd::UnmemorizeList(int *,int);
EQLIB_OBJECT void CCastSpellWnd::Activate(void);
EQLIB_OBJECT void CCastSpellWnd::ForgetMemorizedSpell(int);
EQLIB_OBJECT void CCastSpellWnd::HandleSpellInfoDisplay(class CXWnd *);
EQLIB_OBJECT void CCastSpellWnd::HandleSpellLeftClick(int);
EQLIB_OBJECT void CCastSpellWnd::HandleSpellRightClick(int);
EQLIB_OBJECT void CCastSpellWnd::KeyMapUpdated(void);
EQLIB_OBJECT void CCastSpellWnd::RecacheCategorizedSpells(void);
EQLIB_OBJECT void CCastSpellWnd::RecacheLoadoutContextMenu(void);
EQLIB_OBJECT void CCastSpellWnd::SpellBookDeactivating(void);
// virtual
EQLIB_OBJECT CCastSpellWnd::~CCastSpellWnd(void);
EQLIB_OBJECT int CCastSpellWnd::OnProcessFrame(void);
EQLIB_OBJECT int CCastSpellWnd::PostDraw(void)const;
EQLIB_OBJECT int CCastSpellWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CCastSpellWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CCastSpellWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CCastSpellWnd::Deactivate(void);
// private
EQLIB_OBJECT bool CCastSpellWnd::IsBardSongPlaying(void);
EQLIB_OBJECT unsigned long CCastSpellWnd::GetSpellGemColor(class EQ_Spell *);
EQLIB_OBJECT void CCastSpellWnd::CategorizeSpell(int,int,int,int);
EQLIB_OBJECT void CCastSpellWnd::ClearSpellCategories(void);
EQLIB_OBJECT void CCastSpellWnd::Init(void);
EQLIB_OBJECT void CCastSpellWnd::MakeSpellSelectMenu(void);
EQLIB_OBJECT void CCastSpellWnd::RefreshSpellGemButtons(void);
EQLIB_OBJECT void CCastSpellWnd::UpdateSpellGems(int);
EQLIB_OBJECT void CCastSpellWnd::UpdateSpellGemTooltips(int);
};

class CCharacterCreation : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CCharacterCreation::CCharacterCreation(class CXWnd *);
EQLIB_OBJECT void CCharacterCreation::Activate(void);
EQLIB_OBJECT void CCharacterCreation::ActivateScreen(int);
EQLIB_OBJECT void CCharacterCreation::DoBackButton(void);
EQLIB_OBJECT void CCharacterCreation::DoNextButton(void);
EQLIB_OBJECT void CCharacterCreation::HandleNameApprovalResponse(int);
EQLIB_OBJECT void CCharacterCreation::NameGenerated(char *);
// virtual
EQLIB_OBJECT CCharacterCreation::~CCharacterCreation(void);
EQLIB_OBJECT int CCharacterCreation::Draw(void)const;
EQLIB_OBJECT int CCharacterCreation::OnProcessFrame(void);
EQLIB_OBJECT int CCharacterCreation::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CCharacterCreation::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CCharacterCreation::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CCharacterCreation::Deactivate(void);
// private
EQLIB_OBJECT bool CCharacterCreation::IsLackingExpansion(bool,bool);
EQLIB_OBJECT char * CCharacterCreation::GetCharCreateText(char *,int,int,int,int);
EQLIB_OBJECT int CCharacterCreation::GetClassButtonIndex(int);
EQLIB_OBJECT int CCharacterCreation::GetRaceButtonIndex(int);
EQLIB_OBJECT void CCharacterCreation::DoStatButton(int);
EQLIB_OBJECT void CCharacterCreation::FinalizeNewPCAndSendToWorld(void);
EQLIB_OBJECT void CCharacterCreation::Init(void);
EQLIB_OBJECT void CCharacterCreation::InitNewPC(void);
EQLIB_OBJECT void CCharacterCreation::InitStartingCities(void);
EQLIB_OBJECT void CCharacterCreation::InitStats(bool);
EQLIB_OBJECT void CCharacterCreation::RandomizeCharacter(bool,bool);
EQLIB_OBJECT void CCharacterCreation::RandomizeFacialFeatures(void);
EQLIB_OBJECT void CCharacterCreation::SelectedClassButton(int);
EQLIB_OBJECT void CCharacterCreation::SelectedRaceButton(int);
EQLIB_OBJECT void CCharacterCreation::SelectStartingCity(int);
EQLIB_OBJECT void CCharacterCreation::SetNewPCDeityFromBtnIndex(int);
EQLIB_OBJECT void CCharacterCreation::SetPlayerAppearanceFromNewPC(class EQPlayer *,class EQ_PC *,bool);
EQLIB_OBJECT void CCharacterCreation::SubmitNameToWorld(void);
EQLIB_OBJECT void CCharacterCreation::UpdatePlayerFromNewPC(void);
EQLIB_OBJECT void CCharacterCreation::UpdateScreenZeroButtons(bool);
};


class CCharacterListWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CCharacterListWnd::CCharacterListWnd(class CXWnd *);
EQLIB_OBJECT int CCharacterListWnd::IsEmptyCharacterSlot(int);
EQLIB_OBJECT int CCharacterListWnd::IsValidCharacterSelected(void);
EQLIB_OBJECT int CCharacterListWnd::NumberOfCharacters(void);
EQLIB_OBJECT unsigned char CCharacterListWnd::IsEvil(int,int,int);
EQLIB_OBJECT void CCharacterListWnd::Activate(void);
EQLIB_OBJECT void CCharacterListWnd::DeleteCharacter(void);
EQLIB_OBJECT void CCharacterListWnd::EnterExplorationMode(void);
EQLIB_OBJECT void CCharacterListWnd::EnterWorld(void);
EQLIB_OBJECT void CCharacterListWnd::LeaveExplorationMode(void);
EQLIB_OBJECT void CCharacterListWnd::Quit(void);
EQLIB_OBJECT void CCharacterListWnd::UpdateList(bool bForceUpdate = false);
EQLIB_OBJECT void CCharacterListWnd::SelectCharacter(int charindex,bool bSwitchVisually = true,bool bForceUpdate = false /*dont mess with this*/);
EQLIB_OBJECT void CCharacterListWnd::SetLoadZonePlayerLocation(void);
EQLIB_OBJECT void CCharacterListWnd::SwitchModel(class EQPlayer *,unsigned char,int,unsigned char,unsigned char);
EQLIB_OBJECT void CCharacterListWnd::UpdateButtonNames(void);
// virtual
EQLIB_OBJECT CCharacterListWnd::~CCharacterListWnd(void);
EQLIB_OBJECT int CCharacterListWnd::Draw(void)const;
EQLIB_OBJECT int CCharacterListWnd::OnProcessFrame(void);
EQLIB_OBJECT int CCharacterListWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CCharacterListWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CCharacterListWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CCharacterListWnd::Deactivate(void);
// private
EQLIB_OBJECT void CCharacterListWnd::CreateExplorationModePlayers(void);
EQLIB_OBJECT void CCharacterListWnd::EnableButtons(bool);
EQLIB_OBJECT void CCharacterListWnd::EnableEqMovementCommands(bool);
EQLIB_OBJECT void CCharacterListWnd::Init(void);
EQLIB_OBJECT void CCharacterListWnd::RemoveExplorationModePlayers(void);
EQLIB_OBJECT void CCharacterListWnd::SetLocationByClass(class EQPlayer *,bool,int);
EQLIB_OBJECT void CCharacterListWnd::SetRoomLocationByIndex(int,class EQPlayer *);
};

class CChatManager
{
public:
EQLIB_OBJECT CChatManager::~CChatManager(void);
EQLIB_OBJECT CChatManager::CChatManager(void);
EQLIB_OBJECT class CChatWindow * CChatManager::GetActiveChatWindow(void);
EQLIB_OBJECT class CChatWindow * CChatManager::GetChannelMap(int);
EQLIB_OBJECT class CXStr CChatManager::GetAllVisibleText(class CXStr);
EQLIB_OBJECT int CChatManager::GetChannelFromColor(int);
EQLIB_OBJECT int CChatManager::InitContextMenu(class CChatWindow *);
EQLIB_OBJECT unsigned long CChatManager::GetRGBAFromIndex(int);
EQLIB_OBJECT void CChatManager::Activate(void);
EQLIB_OBJECT void CChatManager::AddText(class CXStr,int);
EQLIB_OBJECT void CChatManager::ClearChannelMap(int);
EQLIB_OBJECT void CChatManager::ClearChannelMaps(class CChatWindow *);
EQLIB_OBJECT void CChatManager::CreateChatWindow(char *,char *,int,int,int,char *,int);
EQLIB_OBJECT void CChatManager::CreateChatWindow(void);
EQLIB_OBJECT void CChatManager::Deactivate(void);
EQLIB_OBJECT void CChatManager::FreeChatWindow(class CChatWindow *);
EQLIB_OBJECT void CChatManager::LoadChatInis(void);
EQLIB_OBJECT void CChatManager::Process(void);
EQLIB_OBJECT void CChatManager::SetActiveChatWindow(class CChatWindow *);
EQLIB_OBJECT void CChatManager::SetChannelMap(int,class CChatWindow *);
EQLIB_OBJECT void CChatManager::SetLockedActiveChatWindow(CChatWindow *);
EQLIB_OBJECT void CChatManager::UpdateContextMenus(class CChatWindow *);
EQLIB_OBJECT void CChatManager::UpdateTellMenus(class CChatWindow *);
EQLIB_OBJECT CChatWindow *CChatManager::GetLockedActiveChatWindow(void);
};

class CChatWindow : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CChatWindow::CChatWindow(class CXWnd *);
EQLIB_OBJECT class CEditWnd * CChatWindow::GetInputWnd(void);
EQLIB_OBJECT class CStmlWnd * CChatWindow::GetOutputWnd(void);
EQLIB_OBJECT class CXStr CChatWindow::GetInputText(void);
EQLIB_OBJECT void CChatWindow::AddHistory(CXStr *pText);
EQLIB_OBJECT void CChatWindow::AddOutputText(PCXSTR,int);
EQLIB_OBJECT void CChatWindow::Clear(void);
EQLIB_OBJECT void CChatWindow::HistoryBack(void);
EQLIB_OBJECT void CChatWindow::HistoryForward(void);
EQLIB_OBJECT void CChatWindow::PageDown(void);
EQLIB_OBJECT void CChatWindow::PageUp(void);
EQLIB_OBJECT void CChatWindow::SetChatFont(int);
// virtual
EQLIB_OBJECT CChatWindow::~CChatWindow(void);
EQLIB_OBJECT int CChatWindow::Draw(void)const;
EQLIB_OBJECT int CChatWindow::HandleRButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CChatWindow::OnKillFocus(class CXWnd *);
EQLIB_OBJECT int CChatWindow::OnProcessFrame(void);
EQLIB_OBJECT int CChatWindow::OnSetFocus(class CXWnd *);
EQLIB_OBJECT int CChatWindow::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CChatWindow::`scalar deleting destructor'(unsigned int);
EQLIB_OBJECT void CChatWindow::operator delete[](void *);
EQLIB_OBJECT void CChatWindow::Deactivate(void);

/*0x220*/ struct _EQCHATMGR *ChatManager; 
/*0x224*/ struct _CSIDLWND* InputWnd;
/*0x228*/ struct _CSIDLWND* OutputWnd;
/*0x22c*/ int ChatChannel;
/*0x230*/ int ChatChannelIndex;
/*0x234*/ CHAR TellTarget[0x40];
/*0x274*/ int Language;
/*0x278*/ bool bIsMainChat;
/*0x279*/ bool bIsTellWnd;
/*0x27c*/ struct _CXSTR *CommandHistory[0x28]; // ->0x198
/*0x31c*/ int HistoryIndex;
/*0x320*/ int HistoryLastShown;
/*0x324*/ int FontSize;//style but yeah...
/*0x328*/ int AlwaysChathereIndex;//menu
/*0x32c*/ int DontKnow;
/*0x330*/

//EQLIB_OBJECT void *CChatWindow::operator new(size_t stAllocateBlock) {return malloc(sizeof(EQCHATWINDOW));} // 11-15-2003 lax
};

class CCheckBoxWnd : public CButtonWnd
{
public:
	bool bOrgState;  
EQLIB_OBJECT CCheckBoxWnd::CCheckBoxWnd(class CXWnd *,unsigned __int32,class CXRect,class CXPoint,class CXSize,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *);
EQLIB_OBJECT void CCheckBoxWnd::SetRadioLook(void);
// virtual
EQLIB_OBJECT CCheckBoxWnd::~CCheckBoxWnd(void);
EQLIB_OBJECT int CCheckBoxWnd::HandleLButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CCheckBoxWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CCheckBoxWnd::HandleMouseMove(class CXPoint,unsigned __int32);
//EQLIB_OBJECT void * CCheckBoxWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CCheckBoxWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CCheckBoxWnd::SetRadioGroup(class CRadioGroup *);
// protected
EQLIB_OBJECT static bool CCheckBoxWnd::sm_bAnimsInitialized;
EQLIB_OBJECT static class CButtonDrawTemplate CCheckBoxWnd::sm_bdtCheck;
EQLIB_OBJECT static class CButtonDrawTemplate CCheckBoxWnd::sm_bdtRadio;
};

class CClickStickInfo
{
public:
EQLIB_OBJECT CClickStickInfo::CClickStickInfo(void);
// virtual
EQLIB_OBJECT CClickStickInfo::~CClickStickInfo(void);
//EQLIB_OBJECT void * CClickStickInfo::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CClickStickInfo::`vector deleting destructor'(unsigned int);
/*0x00*/	DWORD vfTable;
/*0x04*/	CXWnd *FromWnd;
/*0x08*/	CXWnd *ToWnd;
/*0x10*/	POINT FromPoint;
/*0x18*/	POINT ToPoint; 
/*0x20*/	int   Code;
/*0x24*/	void  *Data;
/*0x28*/
};

class CCollisionInfoTargetVisibility
{
public:
	//CCollisionInfoTargetVisibility(const CLineSegment& rLineSegment, const PlayerBase* pPlayerSelf, const PlayerBase* pPlayerOther);
EQLIB_OBJECT CCollisionInfoTargetVisibility::CCollisionInfoTargetVisibility(CLineSegment *rLineSegment, EQPlayer* pSelf, EQPlayer* pOther);
};
class WndEventHandler2
{
public:
	UINT LastCheckTime;
EQLIB_OBJECT WndEventHandler2::WndEventHandler2();
EQLIB_OBJECT void WndEventHandler2::OnWndEvent(CXWnd *pwndSender)const;
};
class CColorPickerWnd : public CSidlScreenWnd, public WndEventHandler2
{
public:
	int ContextMenuIndex;
	int MaxSliderValue;
	CXWnd * pwndCaller;
	CButtonWnd * ColorButton[16];
	int RedSliderValue;
	CSliderWnd *RedSlider;
	CEditWnd *RedSliderInputEdit;
	int GreenSliderValue;
	CSliderWnd *GreenSlider;
	CEditWnd *GreenSliderInputEdit;
	int BlueSliderValue;
	CSliderWnd *BlueSlider;
	CEditWnd *BlueSliderInputEdit;
	CButtonWnd *AcceptButton;

EQLIB_OBJECT CColorPickerWnd::CColorPickerWnd(CXWnd *pwndParent);
EQLIB_OBJECT void CColorPickerWnd::Activate(CXWnd *,unsigned long);
EQLIB_OBJECT void CColorPickerWnd::CheckMaxEditWnd(void);
EQLIB_OBJECT void CColorPickerWnd::SetCurrentColor(unsigned long);
EQLIB_OBJECT void CColorPickerWnd::SetTemplateColor(int,unsigned long);
EQLIB_OBJECT void CColorPickerWnd::UpdateCurrentColor(void);
EQLIB_OBJECT void CColorPickerWnd::UpdateEditWndFromSlider(CSliderWnd *pSlider,class CEditWnd *pEdit,int *value);
EQLIB_OBJECT void CColorPickerWnd::UpdateSliderFromEditWnd(CSliderWnd *pSlider,class CEditWnd *pEdit,int *value);
EQLIB_OBJECT void CColorPickerWnd::Deactivate(void);
EQLIB_OBJECT void CColorPickerWnd::Init(void);
EQLIB_OBJECT int CColorPickerWnd::Open(CXWnd* pwndCaller, D3DCOLOR CurrentColor = 0x00FFFFFF);
EQLIB_OBJECT virtual bool AboutToHide();
EQLIB_OBJECT virtual int WndNotification(CXWnd *pwndSender, UINT Msg, LPVOID pData);
EQLIB_OBJECT virtual void OnWndNotification();// {
	//OnWndEvent((CXWnd *)this);
//}
};


class CCombatSkillsSelectWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CCombatSkillsSelectWnd::CCombatSkillsSelectWnd(class CXWnd *);
// virtual
EQLIB_OBJECT CCombatSkillsSelectWnd::~CCombatSkillsSelectWnd(void);
//private
EQLIB_OBJECT bool CCombatSkillsSelectWnd::ShouldDisplayThisSkill(int);
};

class CComboboxTemplate
{
public:
EQLIB_OBJECT CComboboxTemplate::CComboboxTemplate(class CParamCombobox *);
// virtual
EQLIB_OBJECT CComboboxTemplate::~CComboboxTemplate(void);
//EQLIB_OBJECT void * CComboboxTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CComboboxTemplate::`vector deleting destructor'(unsigned int);
};

class CComboWnd// : public CXWnd
{
public:
	CXW
/*0x1e0*/ CListWnd *pListWnd;
/*0x1e4*/ int ListHeightMax;
/*0x1e8*/ int ListHeight;
    //CButtonDrawTemplate starts here but we cant use it cause it will call the contructor if we do...
/*0x1ec*/ CXStr	*Name;
/*0x1f0*/ CTextureAnimation   *Normal;
/*0x1f4*/ CTextureAnimation   *taPressed;
/*0x1f8*/ CTextureAnimation   *Flyby;
/*0x1fc*/ CTextureAnimation   *taDisabled;
/*0x200*/ CTextureAnimation   *PressedFlyby;
	CTextureAnimation   *PressedDisabled;
    CTextureAnimation   *NormalDecal;
    CTextureAnimation   *PressedDecal;
    CTextureAnimation   *FlybyDecal;
    CTextureAnimation   *DisabledDecal;
    CTextureAnimation   *PressedFlybyDecal;
	CTextureAnimation   *PressedDisabledDecal;
EQLIB_OBJECT CComboWnd::CComboWnd(class CXWnd *,unsigned __int32,class CXRect,int,class CButtonDrawTemplate,class CListWnd *);
EQLIB_OBJECT class CXRect CComboWnd::GetButtonRect(void)const;
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT class CXRect CComboWnd::GetListRect(bool)const;
#else
EQLIB_OBJECT class CXRect CComboWnd::GetListRect(void)const;
#endif
EQLIB_OBJECT class CXRect CComboWnd::GetTextRect(void)const;
EQLIB_OBJECT class CXStr CComboWnd::GetCurChoiceText(void)const;
EQLIB_OBJECT int CComboWnd::GetCurChoice(void)const;
EQLIB_OBJECT int CComboWnd::GetItemCount(void);
EQLIB_OBJECT void CComboWnd::DeleteAll(void);
EQLIB_OBJECT void CComboWnd::InsertChoice(class CXStr *,unsigned long);
EQLIB_OBJECT void CComboWnd::InsertChoice(char *);
EQLIB_OBJECT void CComboWnd::SetChoice(int);
EQLIB_OBJECT void CComboWnd::SetColors(unsigned long,unsigned long,unsigned long);
// virtual
EQLIB_OBJECT CComboWnd::~CComboWnd(void);
EQLIB_OBJECT class CXSize CComboWnd::GetMinSize(void)const;
EQLIB_OBJECT int CComboWnd::Draw(void)const;
EQLIB_OBJECT int CComboWnd::HandleLButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CComboWnd::HitTest(class CXPoint,int *)const;
EQLIB_OBJECT int CComboWnd::OnMove(class CXRect);
EQLIB_OBJECT int CComboWnd::OnResize(int,int);
EQLIB_OBJECT int CComboWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CComboWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CComboWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CComboWnd::SetDrawTemplate(class CXWndDrawTemplate *);
};

class CCompassWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CCompassWnd::CCompassWnd(class CXWnd *);
EQLIB_OBJECT void CCompassWnd::Activate(void);
EQLIB_OBJECT void CCompassWnd::SenseHeading(void);
// virtual
EQLIB_OBJECT CCompassWnd::~CCompassWnd(void);
EQLIB_OBJECT int CCompassWnd::Draw(void)const;
EQLIB_OBJECT int CCompassWnd::OnProcessFrame(void);
//EQLIB_OBJECT void * CCompassWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CCompassWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CCompassWnd::Deactivate(void);
// protected
EQLIB_OBJECT static double const CCompassWnd::HI_SPEED;
EQLIB_OBJECT static double const CCompassWnd::LO_SPEED;
EQLIB_OBJECT void CCompassWnd::PickNewTarget(void);
EQLIB_OBJECT void CCompassWnd::SetSpeed(void);
// private
EQLIB_OBJECT void CCompassWnd::Init(void);
};

class CConfirmationDialog : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CConfirmationDialog::CConfirmationDialog(class CXWnd *);
EQLIB_OBJECT void CConfirmationDialog::Activate(int,unsigned int,char const *,int,int,int,int);
EQLIB_OBJECT void CConfirmationDialog::HandleButtonNoPressed(void);
EQLIB_OBJECT void CConfirmationDialog::HandleButtonOkPressed(void);
EQLIB_OBJECT void CConfirmationDialog::HandleButtonYesPressed(void);
EQLIB_OBJECT void CConfirmationDialog::ProcessNo(int);
EQLIB_OBJECT void CConfirmationDialog::ProcessYes(void);
EQLIB_OBJECT void CConfirmationDialog::SetNameApprovalData(char *,char *,int,int,char *);
// virtual
EQLIB_OBJECT CConfirmationDialog::~CConfirmationDialog(void);
EQLIB_OBJECT int CConfirmationDialog::Draw(void)const;
EQLIB_OBJECT int CConfirmationDialog::OnProcessFrame(void);
EQLIB_OBJECT int CConfirmationDialog::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CConfirmationDialog::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CConfirmationDialog::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CConfirmationDialog::Deactivate(void);
// private
EQLIB_OBJECT void CConfirmationDialog::ExpireCurrentDialog(void);
EQLIB_OBJECT void CConfirmationDialog::Init(void);
EQLIB_OBJECT void CConfirmationDialog::ResetFocusOnClose(void);
// Data members
/*0x15c*/   struct _CXWND *OutputText;
/*0x160*/   struct _CXWND *pYesButton;
/*0x164*/    struct _CXWND *pNoButton;
/*0x168*/    DWORD    Unknown0x168;
/*0x16c*/    struct _CXWND *pOKButton;
/*0x170*/    BYTE    Unknown0x170[0x18];
/*0x188*/
};
class ItemBase
{
public:
	EQLIB_OBJECT bool ItemBase::IsLore(bool bIncludeSockets = false) const;
	EQLIB_OBJECT bool ItemBase::IsLoreEquipped(bool bIncludeSockets = false) const;
};
class ItemGlobalIndex
{
public:
	ItemGlobalIndex::ItemContainerInstance Location;
	ItemGlobalIndex::ItemIndex Index;
	//CHAR morestuff[2048];
EQLIB_OBJECT	ItemGlobalIndex::ItemGlobalIndex();
EQLIB_OBJECT bool ItemGlobalIndex::IsKeyRingLocation(void);
EQLIB_OBJECT bool ItemGlobalIndex::IsEquippedLocation(void);
EQLIB_OBJECT bool ItemGlobalIndex::IsValidIndex(void);
};
class CContainerMgr
{
public:
	DWORD vfTable;
	CContainerWnd *pContainerWnds[38];
	ArrayClass<CContainerWnd*> ContainerWndsToDelete;
	VePointer<CONTENTS> pWorldContainer;
	DWORD WorldContainerSerialNumber;
	int WorldContainerRealEstateID;
	int WorldContainerRealEstateItemID;
	DWORD Timer;
	bool bShowDone;

EQLIB_OBJECT CContainerMgr::CContainerMgr(void);
EQLIB_OBJECT bool CContainerMgr::CloseAllContainers(void);
EQLIB_OBJECT class EQ_Item * CContainerMgr::GetWorldContainerItem(int);
EQLIB_OBJECT void CContainerMgr::ClearWorldContainerItems(void);
EQLIB_OBJECT void CContainerMgr::CloseContainer(class EQ_Container *,bool);
EQLIB_OBJECT void CContainerMgr::CloseEQContainer(class EQ_Container *);
EQLIB_OBJECT void CContainerMgr::OpenContainer(class EQ_Container *,int,bool);
EQLIB_OBJECT void CContainerMgr::OpenWorldContainer(class EQ_Container *,unsigned long);
EQLIB_OBJECT void CContainerMgr::Process(void);
EQLIB_OBJECT void CContainerMgr::SetWorldContainerItem(class EQ_Item *,int);
// virtual
EQLIB_OBJECT CContainerMgr::~CContainerMgr(void);
//EQLIB_OBJECT void * CContainerMgr::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CContainerMgr::`vector deleting destructor'(unsigned int);
// private
EQLIB_OBJECT class CContainerWnd * CContainerMgr::GetFreeContainerWnd(void);
EQLIB_OBJECT void CContainerMgr::OpenExperimentContainer(const VePointer<CONTENTS>& pCont, const ItemGlobalIndex& Location);
};

class CContainerWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CContainerWnd::CContainerWnd(class CXWnd *);
EQLIB_OBJECT void CContainerWnd::Activate(void);
EQLIB_OBJECT void CContainerWnd::CheckCloseable(void);
EQLIB_OBJECT void CContainerWnd::SetContainer(PCONTENTS &pContainer, const ItemGlobalIndex& location);
// virtual
EQLIB_OBJECT CContainerWnd::~CContainerWnd(void);
EQLIB_OBJECT int CContainerWnd::OnProcessFrame(void);
EQLIB_OBJECT int CContainerWnd::PostDraw(void)const;
EQLIB_OBJECT int CContainerWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CContainerWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CContainerWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CContainerWnd::Deactivate(void);
// private
EQLIB_OBJECT bool CContainerWnd::ContainsNoDrop(void);
EQLIB_OBJECT void CContainerWnd::HandleCombine(void);
EQLIB_OBJECT void CContainerWnd::Init(void);

/*0x04*/ PCONTENTS pCont;
/*0x08*/ ItemGlobalIndex	Location;
/*0x14*/ VeArray<CInvSlotWnd*> InvSlotWnds;
/*0x18*/ CButtonWnd *pCombineButton;
/*0x1c*/ CButtonWnd *pDoneButton;
/*0x20*/ CButtonWnd *pStandardDoneButton;
/*0x24*/ CButtonWnd *pCombineDoneButton;
/*0x28*/ CButtonWnd *pContainerIcon;
/*0x2c*/ CButtonWnd *pContainerStandardIcon;
/*0x30*/ CButtonWnd *pContainerCombineIcon;
/*0x34*/ CTextureAnimation *pIconAnimation;
/*0x38*/ CLabel*ContainerLabel;
/*0x3c*/ CInvSlotWnd *pContainerSlotTemplate;
/*0x40*/ CXWnd *pStandardItems;
/*0x44*/ CXWnd *pStandardItemsWithDone;
/*0x48*/ CXWnd *pCombineItems;
/*0x4c*/ CStmlWnd *pStandardSize;
/*0x50*/ CStmlWnd *pCombineSize;
/*0x54*/ bool bCombineValid;
/*0x55*/ bool bUserCloseable;
/*0x58*/ int ContainerType;//classic = 0,stamdard = 1, combine = 2
/*0x5c*/ int IndexDoneButton;
/*0x60*/ CContextMenu *ContextMenu;
/*0x64*/ 
};



class CContextMenuManager : public CXWnd
{
public:
	CXWnd *pParentMenuWnd;
    CContextMenu *pCurrMenus[8];
    int		NumVisibleMenus;
    int		CurrMenu;
    CContextMenu	*pMenus[0x400];
    int		NumMenus;
    CXWnd*	pHandlerWnd;
    int		HandlerCmd;
    int		DefaultMenuIndex;
	int		DefaultHelpItem;
    int		DefaultBGItem;
    int		DefaultMinItem;
    int		DefaultCloseItem;
    int		DefaultLockItem;
	int		DefaultEscapeItem;
EQLIB_OBJECT CContextMenuManager::CContextMenuManager(class CXWnd *,unsigned __int32,class CXRect);
EQLIB_OBJECT int CContextMenuManager::AddMenu(class CContextMenu *);
EQLIB_OBJECT int GetDefaultMenuIndex() { return DefaultMenuIndex; }
EQLIB_OBJECT CContextMenu *CContextMenuManager::GetMenu(int);
EQLIB_OBJECT int CContextMenuManager::HandleWindowMenuCommands(class CXWnd *,int);
EQLIB_OBJECT int CContextMenuManager::PopupMenu(int,class CXPoint const &,class CXWnd *);
EQLIB_OBJECT int CContextMenuManager::RemoveMenu(int,bool);
EQLIB_OBJECT void CContextMenuManager::Flush(void);
EQLIB_OBJECT void CContextMenuManager::WarnDefaultMenu(class CXWnd *);
// virtual
EQLIB_OBJECT CContextMenuManager::~CContextMenuManager(void);
EQLIB_OBJECT int CContextMenuManager::HandleLButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CContextMenuManager::HandleRButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CContextMenuManager::HandleWheelButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CContextMenuManager::OnProcessFrame(void);
EQLIB_OBJECT int CContextMenuManager::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CContextMenuManager::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CContextMenuManager::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CContextMenuManager::Deactivate(void);
// private
EQLIB_OBJECT void CContextMenuManager::CreateDefaultMenu(void);
};

class CScreenPieceTemplate
{
public:
/*0x00*/	PVOID vfTable;
/*0x04*/	ArrayClass2_RO<unsigned __int32> RuntimeTypes;
/*0x20*/	PCXSTR Name;
/*0x24*/	unsigned __int32 ParamObjectID;
/*0x28*/	PCXSTR ScreenID;
/*0x2c*/	unsigned __int32 Font;
/*0x30*/    bool	bRelativePosition;
/*0x31*/    bool	bAutoStretchVertical;
/*0x32*/	bool	bAutoStretchHorizontal;
/*0x33*/    bool	bTopAnchorToTop;
/*0x34*/    bool	bBottomAnchorToTop;
/*0x35*/    bool	bLeftAnchorToLeft;
/*0x36*/    bool	bRightAnchorToLeft;
/*0x38*/    int 	TopOffset;
/*0x3c*/    int 	BottomOffset;
/*0x40*/    int 	LeftOffset;
/*0x44*/    int 	RightOffset;
/*0x48*/	int 	MinVSize;
/*0x4c*/	int 	MinHSize;
/*0x50*/	int 	MaxVSize;
/*0x54*/	int 	MaxHSize;
/*0x58*/    RECT    Rect;
/*0x68*/    PCXSTR	Text;
/*0x6c*/    D3DCOLOR	TextColor;
/*0x70*/	D3DCOLOR    DisabledColor;
/*0x74*/	D3DCOLOR    EnabledColor;
/*0x78*/	bool		bUseInLayoutHorizontal;
/*0x79*/	bool		bUseInLayoutVertical;
/*0x7c*/	D3DCOLOR    BackgroundTextureTint;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x80*/	D3DCOLOR    DisabledBackgroundTextureTint;
/*0x84*/
#endif
EQLIB_OBJECT CScreenPieceTemplate::CScreenPieceTemplate(class CParamScreenPiece *);
EQLIB_OBJECT bool CScreenPieceTemplate::IsType(unsigned __int32)const;
EQLIB_OBJECT class CXStr CScreenPieceTemplate::GetName(void)const;
// virtual
EQLIB_OBJECT CScreenPieceTemplate::~CScreenPieceTemplate(void);
//EQLIB_OBJECT void * CScreenPieceTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CScreenPieceTemplate::`vector deleting destructor'(unsigned int);
};

class CControlTemplate : public CScreenPieceTemplate
{
public:
/*0x84*/ unsigned __int32 StyleBits;
/*0x88*/	BYTE SizableMask;
/*0x89*/	bool bEscapable;
/*0x8c*/	PCXSTR Tooltip;
/*0x90*/	CXWndDrawTemplate *pDrawTemplate;
/*0x94*/	PCXSTR Controller;
/*0x98*/	void *pLayoutStrategyTemplate;//CLayoutStrategyTemplate
/*0x9c*/

EQLIB_OBJECT CControlTemplate::CControlTemplate(class CParamControl *);
// virtual
EQLIB_OBJECT CControlTemplate::~CControlTemplate(void);
//EQLIB_OBJECT void * CControlTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CControlTemplate::`vector deleting destructor'(unsigned int);
};

class HasATimer
{
	UINT Timer;
};
class CCursorAttachment// : public CSidlScreenWnd : public HasATimer
{
public:
/*0x000*/ struct _CSIDLWNDVFTABLE* pvfTable;
	CXW_NO_VTABLE
	SIDL
/*0x220*/ UINT Timer;
/*0x224*/ int Type;
/*0x228*/ int Index;
/*0x22c*/	EqItemGuid ItemGuid;
/*0x240*/ int ItemID;
/*0x244*/ int Qty;
/*0x248*/ CXStr *ButtonText;
	//and more
EQLIB_OBJECT CCursorAttachment::CCursorAttachment(class CXWnd *);
EQLIB_OBJECT bool CCursorAttachment::IsOkToActivate(int);
EQLIB_OBJECT bool CCursorAttachment::RemoveAttachment(void);
EQLIB_OBJECT void CCursorAttachment::Activate(class CTextureAnimation *,int,int,int);
// virtual
EQLIB_OBJECT CCursorAttachment::~CCursorAttachment(void);
EQLIB_OBJECT int CCursorAttachment::Draw(void)const;
EQLIB_OBJECT int CCursorAttachment::OnProcessFrame(void);
EQLIB_OBJECT int CCursorAttachment::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CCursorAttachment::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CCursorAttachment::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CCursorAttachment::Deactivate(void);
// private
EQLIB_OBJECT void CCursorAttachment::DrawButtonText(void)const;
EQLIB_OBJECT void CCursorAttachment::DrawQuantity(void)const;
EQLIB_OBJECT void CCursorAttachment::Init(void);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT void CCursorAttachment::AttachToCursor(CTextureAnimation* Overlay, CTextureAnimation *pTABG, int Type, int Index, const char *Assigned_Name, const char *Name, int Qty = -1, int IconID = -1);
EQLIB_OBJECT void CCursorAttachment::AttachToCursor(CTextureAnimation *Overlay, class CTextureAnimation *pTABG, int Type, int Index, const EqItemGuid& ItemGuid, int ItemID, const char  *Assigned_Name, const char *Name, int Qty = -1, int IconID = -1);
#else
EQLIB_OBJECT void CCursorAttachment::AttachToCursor(CTextureAnimation *Overlay, CTextureAnimation *pTABG, int Type, int Index, const char *Name, int Qty = -1);
EQLIB_OBJECT void CCursorAttachment::AttachToCursor(CTextureAnimation *Overlay, CTextureAnimation *pTABG, int Type, int Index, const EqItemGuid &ItemGuid, int ItemID, const char *Name, int Qty = -1);
#endif
};

class CDIMap
{
public:
EQLIB_OBJECT CDIMap::~CDIMap(void);
EQLIB_OBJECT CDIMap::CDIMap(void);
// private
EQLIB_OBJECT static char * CDIMap::mKeymapAltArray;
EQLIB_OBJECT static char * CDIMap::mKeymapArray;
EQLIB_OBJECT static char * CDIMap::mKeymapShiftArray;
EQLIB_OBJECT void CDIMap::LoadMappingFromFile(char *);
};

class CVector3
{
public:
EQLIB_OBJECT CVector3::CVector3(float x, float y, float z) : X(x), Y(y), Z(z) {}
EQLIB_OBJECT CVector3::CVector3() {}
//EQLIB_OBJECT float CVector3::GetLength(void)const;
EQLIB_OBJECT float CVector3::NormalizeAndReturnLength(void);
EQLIB_OBJECT void CVector3::Normalize(void);
EQLIB_OBJECT void CVector3::Set(float x, float y, float z)
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
inline CVector3 operator*(float val)const
{
	CVector3 ret(*this);
	ret.Scale(val);
	return ret;
}
EQLIB_OBJECT void SetMax()
{
    X = Y = Z = 3.402823466e+38F;
}
EQLIB_OBJECT float GetLengthSquared()const
{
    return ((X * X) + (Y * Y) + (Z * Z));
}
EQLIB_OBJECT float GetLength()const
{ 
    return sqrtf(GetLengthSquared()); 
}
EQLIB_OBJECT CVector3 operator-()const
{
	CVector3 res;
	res.Set(-X, -Y, -Z);
	return res;
}
EQLIB_OBJECT CVector3 operator-(const CVector3& vec) const
{
	CVector3 res;
	res.Set(X - vec.X, Y - vec.Y, Z - vec.Z);
	return res;
}
EQLIB_OBJECT CVector3 operator+(const CVector3& vec)const
{
	CVector3 res;
	res.Set(vec.X + X, vec.Y + Y, vec.Z + Z);
	return res;
}
EQLIB_OBJECT float GetDistanceSquared(const CVector3& vec)const
{
	CVector3 Delta = *this - vec;
	return Delta.GetLengthSquared();
}
	float X;
	float Y;
	float Z;
};
class CDisplay
{
public:
/*0x0000*/ BOOL		ErrorFlag;
/*0x0004*/ BYTE		BFog;
/*0x0005*/ BYTE		BMoveAnims;
/*0x0008*/ FLOAT	Yon;
/*0x000c*/ FLOAT	AmbientLight;
/*0x0010*/ BYTE		DragItem;
/*0x0011*/ BYTE		DragMoney;
/*0x0012*/ BYTE		DragHotButton;
/*0x0013*/ bool		bInRenderLoop;
/*0x0014*/ bool		bHideLootedCorpses;
/*0x0015*/ CHAR		LastTeleportAreaTag[0x100];
/*0x0118*/ void*	pCamera;//CCameraInterface
/*0x011c*/ CVector3*CamPos;
/*0x0120*/ CVector3*CamOrientation;
/*0x0124*/ void*	WadFileLoadScreen;//SWadFile
/*0x0128*/ BYTE		NewPCModelsLoaded;
/*0x0129*/ bool		bHorsesLoaded;
/*0x012c*/ void		*pActorTagManager;
/*0x0130*/ BYTE		Unknown0x130[0x24];
/*0x0154*/ DWORD	TimeStamp;
/*0x0158*/ BYTE		Unknown0x158[0x2c12];
/*0x2d6a*/ BYTE		NpcNames; // show npc names
EQLIB_OBJECT CDisplay::~CDisplay(void);
EQLIB_OBJECT CDisplay::CDisplay(struct HWND__ *);
EQLIB_OBJECT bool CDisplay::GenericSphereColl(float,float,float,float,float,float,float *,float *,float *,unsigned char);
EQLIB_OBJECT bool CDisplay::SlideSwitchLeftRight(class EQSwitch *,float,int,float);
EQLIB_OBJECT bool const CDisplay::GetWorldFilePath(char *,char const *);
EQLIB_OBJECT char * CDisplay::GetIniRaceName(int);
EQLIB_OBJECT class EQPlayer * CDisplay::GetNearestPlayerInView(float,bool);
EQLIB_OBJECT float CDisplay::FindZoneTopZ(float,float,float);
EQLIB_OBJECT float CDisplay::FixHeading(float);
EQLIB_OBJECT float CDisplay::GetFloorHeight(float X,float Y,float F,float Radius = 0.0f,CVector3& CollisionVector = CVector3(-1, -1, 1), CActorApplicationData* pAppData = 0,EActorType eActorType = Undefined,float ZOffset = 1.0f);
EQLIB_OBJECT float CDisplay::HeadingDiff(float,float,float *);
EQLIB_OBJECT float CDisplay::PlayerDistance(class EQPlayer *,class EQPlayer *,float);
EQLIB_OBJECT float CDisplay::PlayerSimpleDistance(class EQPlayer *,class EQPlayer *,float);
EQLIB_OBJECT float CDisplay::SetActorBoundingRadius(struct T3D_tagACTORINSTANCE *,float,float);
EQLIB_OBJECT float CDisplay::SimpleDistance(float,float,float,float,float,float,float);
EQLIB_OBJECT float CDisplay::TrueDistance(float fromx,float fromy,float fromz,float tox,float toy,float toz,float zfactor);
EQLIB_OBJECT int CDisplay::GetItemType(int);
EQLIB_OBJECT int CDisplay::GetNewPCIniFlag(int,int);
EQLIB_OBJECT int CDisplay::GetSkyTime(int *,int *);
EQLIB_OBJECT int CDisplay::is_3dON(void);
EQLIB_OBJECT int CDisplay::is_ParticleSystemON(void);
EQLIB_OBJECT int CDisplay::MoveMissile(class EQMissile *);
EQLIB_OBJECT int CDisplay::ReplaceCloakMaterials(int,struct T3D_HIERARCHICALSPRITEINSTANCE *,struct T3D_RGB *);
EQLIB_OBJECT int CDisplay::ReplaceMaterial(char *,char *,struct T3D_HIERARCHICALSPRITEINSTANCE *,struct T3D_RGB *,int);
EQLIB_OBJECT int CDisplay::SetBoneSpriteTint(struct T3D_DAG *,struct T3D_RGB *);
EQLIB_OBJECT int CDisplay::ShouldLoadNewPcModel(int,int);
EQLIB_OBJECT int CDisplay::TurnInfravisionEffectOff(void);
EQLIB_OBJECT int CDisplay::TurnInfravisionEffectOn(void);
EQLIB_OBJECT long CDisplay::SetUserRender(int);
EQLIB_OBJECT static char * CDisplay::DefaultUIPath;
EQLIB_OBJECT static char * CDisplay::UIPath;
EQLIB_OBJECT static int __cdecl CDisplay::WriteTextHD2(char const *text,int X,int Y,int color);
EQLIB_OBJECT static unsigned long __cdecl CDisplay::GetUserDefinedColor(int);
EQLIB_OBJECT static void __cdecl CDisplay::SetUserDefinedColor(int,int,int,int);
EQLIB_OBJECT struct T3D_POINTLIGHT * CDisplay::CreateLight(unsigned char,float,float,float,float);
EQLIB_OBJECT struct T3D_tagACTORINSTANCE * CDisplay::CreateActor(char *,float,float,float,float,float,float,bool,bool);
EQLIB_OBJECT struct T3D_tagACTORINSTANCE * CDisplay::GetClickedActor(unsigned long,unsigned long,unsigned long,void *,void *);
EQLIB_OBJECT unsigned char CDisplay::GetEnvironment(float,float,float,int *);
EQLIB_OBJECT unsigned char CDisplay::GetIntensity(unsigned char);
EQLIB_OBJECT unsigned char CDisplay::LoadBMPFile(void);
EQLIB_OBJECT unsigned char CDisplay::LoadNPCFromS3D(char *,char *,char *);
EQLIB_OBJECT unsigned char CDisplay::LoadWorldFile(char *,char *,int,unsigned char);
EQLIB_OBJECT unsigned int CDisplay::IsShield(int)const;
EQLIB_OBJECT void CDisplay::ActivateMainUI(bool);
EQLIB_OBJECT void CDisplay::ChangeVideoMode(void);
EQLIB_OBJECT void CDisplay::CheckForScreenModeToggle(void);
EQLIB_OBJECT void CDisplay::CleanUpDDraw(void);
EQLIB_OBJECT void CDisplay::ClearScreen(void);
EQLIB_OBJECT void CDisplay::CreatePlayerActor(class EQPlayer *);
EQLIB_OBJECT void CDisplay::DDrawUpdateDisplay(void);
EQLIB_OBJECT void CDisplay::DeactivateMainUI(void);
EQLIB_OBJECT void CDisplay::default_cameras(void);
EQLIB_OBJECT void CDisplay::DefineSoloMode(void);
EQLIB_OBJECT void CDisplay::DeleteActor(struct T3D_tagACTORINSTANCE *);
EQLIB_OBJECT void CDisplay::DeleteLight(struct T3D_POINTLIGHT *);
EQLIB_OBJECT void CDisplay::DeleteParticleCloudInstance(struct T3D_PARTICLECLOUDINSTANCE * *);
EQLIB_OBJECT void CDisplay::GetOnActor(struct T3D_tagACTORINSTANCE *,class EQPlayer *);
EQLIB_OBJECT void CDisplay::HandleMaterial(class EQ_PC *,int,class EQ_Item *,class EQ_Item *);
EQLIB_OBJECT void CDisplay::hideGrassObjects(void);
EQLIB_OBJECT void CDisplay::InitCharSelectUI(void);
EQLIB_OBJECT void CDisplay::InitCommonLights(void);
EQLIB_OBJECT void CDisplay::InitDDraw(void);
EQLIB_OBJECT void CDisplay::InitEverQuestLocale(EQLocalizeLanguage);
EQLIB_OBJECT void CDisplay::InitUserDefinedColors(void);
EQLIB_OBJECT void CDisplay::InitWorld(void);
EQLIB_OBJECT void CDisplay::KeyMapUpdated(void);
EQLIB_OBJECT void CDisplay::LightningStrike(void);
EQLIB_OBJECT void CDisplay::loadGrassObjects(char *);
EQLIB_OBJECT void CDisplay::MoveLight(struct T3D_POINTLIGHT *,struct _physicsinfo *);
EQLIB_OBJECT void CDisplay::MoveLocalPlayerToSafeCoords(void);
EQLIB_OBJECT void CDisplay::NewUIProcessEscape(void);
EQLIB_OBJECT void CDisplay::PlaySoundAtLocation(float,float,float,int);
EQLIB_OBJECT void CDisplay::ProcessCloud(void);
EQLIB_OBJECT void CDisplay::ProcessEffects(void);
EQLIB_OBJECT void CDisplay::ProcessParticleEmitter(class EQSwitch *);
EQLIB_OBJECT void CDisplay::ProcessSky(void);
EQLIB_OBJECT void CDisplay::ProcessSwitches(void);
EQLIB_OBJECT void CDisplay::ProcessWeather(void);
EQLIB_OBJECT void CDisplay::RealRender_World(void);
EQLIB_OBJECT void CDisplay::ReloadUI(bool);
EQLIB_OBJECT void CDisplay::Render_MinWorld(void);
EQLIB_OBJECT void CDisplay::Render_World(void);
EQLIB_OBJECT void CDisplay::ResetRenderWindow(void);
EQLIB_OBJECT void CDisplay::SetActorScaleFactor(struct T3D_tagACTORINSTANCE *,float,unsigned char);
EQLIB_OBJECT void CDisplay::SetActorSpriteTint(struct _EQRGB *,struct T3D_tagACTORINSTANCE *);
EQLIB_OBJECT void CDisplay::SetActorUserData(struct T3D_tagACTORINSTANCE *,void *);
EQLIB_OBJECT void CDisplay::SetActorYon(float);
EQLIB_OBJECT void CDisplay::SetAmbientLight(float);
EQLIB_OBJECT void CDisplay::SetCCreateCamera(int);
EQLIB_OBJECT void CDisplay::SetDayPeriod(unsigned char);
EQLIB_OBJECT void CDisplay::SetFog(bool,float,float,unsigned char,unsigned char,unsigned char);
EQLIB_OBJECT void CDisplay::SetGammaCorrection(float);
EQLIB_OBJECT void CDisplay::SetGenericEnvironment(void);
EQLIB_OBJECT void CDisplay::SetPCloudDensity(int);
EQLIB_OBJECT void CDisplay::SetSkyBackground(void);
EQLIB_OBJECT void CDisplay::SetSkyLayer(int);
EQLIB_OBJECT void CDisplay::SetSpecialEnvironment(enum EnvironmentType);
EQLIB_OBJECT void CDisplay::SetSunLight(void);
EQLIB_OBJECT void CDisplay::SetupEmitterEnvironment(void);
EQLIB_OBJECT void CDisplay::SetupEQPlayers(void);
EQLIB_OBJECT void CDisplay::SetViewActor(struct T3D_tagACTORINSTANCE *);
EQLIB_OBJECT void CDisplay::SetRenderWindow(int mode);
EQLIB_OBJECT void CDisplay::ToggleScreenshotMode(void);
EQLIB_OBJECT void CDisplay::SetViewActorByName(char *);
EQLIB_OBJECT void CDisplay::SetViewAngle(int);
EQLIB_OBJECT void CDisplay::SetYon(float);
EQLIB_OBJECT void CDisplay::ShowDisplay(void);
EQLIB_OBJECT void CDisplay::SpurtBloodOnDag(struct T3D_DAG *);
EQLIB_OBJECT void CDisplay::StartWeather(int,unsigned char);
EQLIB_OBJECT void CDisplay::StartWorldDisplay(EQZoneIndex);
EQLIB_OBJECT void CDisplay::StartWorldDisplay_Bailout(char const *);
EQLIB_OBJECT void CDisplay::StopWeather(int,unsigned char);
EQLIB_OBJECT void CDisplay::StopWorldDisplay(void);
EQLIB_OBJECT void CDisplay::SwitchToDefaultCameraMode(void);
EQLIB_OBJECT void CDisplay::ToggleCharacterNameSprites(bool);
EQLIB_OBJECT void CDisplay::ToggleNpcNameSprites(bool);
EQLIB_OBJECT void CDisplay::ToggleView(void);
EQLIB_OBJECT void CDisplay::UpdateCameraAfterModeSwitch(void);
EQLIB_OBJECT void CDisplay::updateGrassObjects(void);
EQLIB_OBJECT void CDisplay::UpdateMobileEmitterLocations(void);
EQLIB_OBJECT void CDisplay::FreeAllItemLists(void);
// private
EQLIB_OBJECT struct T3D_HIERARCHICALSPRITEINSTANCE * CDisplay::dupActorHierarchicalSprite(struct T3D_tagACTORINSTANCE *);
EQLIB_OBJECT void CDisplay::CleanCharSelectUI(void);
EQLIB_OBJECT void CDisplay::CleanGameUI(void);
EQLIB_OBJECT void CDisplay::CleanUpNewUI(void);
EQLIB_OBJECT void CDisplay::InitGameUI(void);
EQLIB_OBJECT void CDisplay::InitNewUI(void);
};

class CDistillerInfo
{
public:
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT int CDistillerInfo::GetIDFromRecordNum(int ID, bool bWhat);
#endif
};

enum eTextAlign
{
    eta_Left,
    eta_Center,
    eta_Right,
};
class CEditBaseWnd//ok Look... this SHOULD inherit CXWnd but doing so... calls the constructor, and we dont want that... so... : public CXWnd
{
public:
	//we include CXW instead...
/*0x000*/ CXW
/*0x1F0*/ eTextAlign eAlign;//see 8EAC07 in eqgame 11 sep 2017 test - eqmule
/*0x1F4*/ int	StartPos;
/*0x1F8*/ int	EndPos;
/*0x1Fc*/ int	MaxChars;
/*0x200*/ int MaxBytesUTF8;
/*0x204*/ PCXSTR InputText;
/*0x208*/ int TagPrintableStarts[0xa];
/*0x230*/ int TagPrintableEnds[0xa];
/*0x258*/ int TagOriginalStarts[0xa];
/*0x280*/ int TagOriginalEnds[0xa];
/*0x2a8*/ int TagDynamicSize[0xa];
/*0x2d0*/ int TagCodes[0xa];
/*0x2f8*/ PCXSTR TagStrings[0xa];
/*0x320*/ int TagCount;
/*0x324*/ unsigned __int32 EditWndStyle;
/*0x328*/
EQLIB_OBJECT void CEditBaseWnd::SetMaxChars(int);
EQLIB_OBJECT void CEditBaseWnd::SetSel(int,int);
// virtual
EQLIB_OBJECT CEditBaseWnd::~CEditBaseWnd(void);
EQLIB_OBJECT int CEditBaseWnd::OnKillFocus(class CXWnd *);
//EQLIB_OBJECT void * CEditBaseWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CEditBaseWnd::`vector deleting destructor'(unsigned int);
};

class CEditboxTemplate
{
public:
EQLIB_OBJECT CEditboxTemplate::CEditboxTemplate(class CParamEditbox *);
// virtual
EQLIB_OBJECT CEditboxTemplate::~CEditboxTemplate(void);
//EQLIB_OBJECT void * CEditboxTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CEditboxTemplate::`vector deleting destructor'(unsigned int);
};

class CEditLabelWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CEditLabelWnd::CEditLabelWnd(class CXWnd *);
EQLIB_OBJECT class CXStr CEditLabelWnd::GetLabelText(void);
EQLIB_OBJECT void CEditLabelWnd::Activate(class CXWnd *,char *,int,unsigned long);
// virtual
EQLIB_OBJECT CEditLabelWnd::~CEditLabelWnd(void);
EQLIB_OBJECT int CEditLabelWnd::OnProcessFrame(void);
EQLIB_OBJECT int CEditLabelWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CEditLabelWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CEditLabelWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CEditLabelWnd::Deactivate(void);
};

//size 0x358 see 8DCCF8 in eqgame test sep 11 2017 - eqmule
class CEditWnd : public CEditBaseWnd
{
public:
/*0x328*/ bool	 bAnchorAtStart;
/*0x329*/ bool	 bCaretAtEnd;
/*0x32a*/ bool	 bAutoVScrollCalc;
/*0x32b*/ bool	 bEditable;
/*0x32c*/ PCXSTR FilterChars;
/*0x330*/ int	 EditMode;
/*0x334*/ wchar_t PasswordChar;
/*0x338*/ ArrayClass2_RO<unsigned __int32> LineIndices;//size 0x1c see 8EB1CB in eqgae 11 sep 2017 test - eqmule
/*0x354*/
EQLIB_OBJECT CEditWnd::CEditWnd(class CXWnd *,unsigned __int32,class CXRect,unsigned __int32);
EQLIB_OBJECT class CXPoint CEditWnd::GetCharIndexPt(int)const;
EQLIB_OBJECT class CXPoint CEditWnd::GetSelEndPt(void)const;
EQLIB_OBJECT class CXPoint CEditWnd::GetSelStartPt(void)const;
EQLIB_OBJECT class CXStr CEditWnd::GetSTMLSafeText(void);
EQLIB_OBJECT int CEditWnd::ConvertIndexPrintableToTagged(int);
EQLIB_OBJECT int CEditWnd::ConvertIndexTaggedToPrintable(int);
EQLIB_OBJECT int CEditWnd::GetLineForPrintableChar(int)const;
EQLIB_OBJECT int CEditWnd::GetLineLength(int)const;
EQLIB_OBJECT int CEditWnd::SelectableCharFromPoint(class CXPoint)const;
EQLIB_OBJECT void CEditWnd::AddItemTag(int,char *,int);
EQLIB_OBJECT void CEditWnd::CalculateScrollRange(void);
EQLIB_OBJECT void CEditWnd::EnsureCaretVisible(void);
EQLIB_OBJECT void CEditWnd::ReplaceSelection(char,bool);
EQLIB_OBJECT void CEditWnd::ReplaceSelection(class CXStr,bool);
EQLIB_OBJECT void CEditWnd::SetEditable(bool);
// virtual
EQLIB_OBJECT CEditWnd::~CEditWnd(void);
EQLIB_OBJECT class CXPoint CEditWnd::GetCaretPt(void)const;
EQLIB_OBJECT class CXPoint CEditWnd::PointFromPrintableChar(int)const;
EQLIB_OBJECT class CXStr CEditWnd::GetDisplayString(void)const;
EQLIB_OBJECT class CXStr CEditWnd::GetWindowTextA(void)const;
EQLIB_OBJECT int CEditWnd::Draw(void)const;
EQLIB_OBJECT int CEditWnd::DrawCaret(void)const;
EQLIB_OBJECT int CEditWnd::DrawMultiline(void)const;
EQLIB_OBJECT int CEditWnd::HandleKeyboardMsg(unsigned __int32,unsigned __int32,bool);
EQLIB_OBJECT int CEditWnd::HandleLButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CEditWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CEditWnd::HandleMouseMove(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CEditWnd::OnKillFocus(class CXWnd *);
EQLIB_OBJECT int CEditWnd::OnMove(class CXRect);
EQLIB_OBJECT int CEditWnd::OnResize(int,int);
EQLIB_OBJECT int CEditWnd::OnSetFocus(class CXWnd *);
EQLIB_OBJECT int CEditWnd::ResetWnd(void);
//EQLIB_OBJECT void * CEditWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CEditWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CEditWnd::SetWindowTextA(class CXStr);
// protected
EQLIB_OBJECT static class CDIMap CEditWnd::m_mapKeys;
//EQLIB_OBJECT virtual int CEditWnd::GetHorzOffset(void)const;
EQLIB_OBJECT void CEditWnd::FillIndexArray(class CXStr)const;
EQLIB_OBJECT void CEditWnd::FilterInputStr(class CXStr &);
EQLIB_OBJECT void CEditWnd::ProcessText(void);
};

class UniversalChatProxy
{
public:
	EQLIB_OBJECT char *UniversalChatProxy::GetChannelName(int channelNumber);
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

class CEQGBitmap//have to fake these i dont wanna map them now... we dont need them anyway : public CThreadLoader, public TListNode<CEQGBitmap>
{
public:
/*0x000*/ PVOID vftable;
/*0x004*/ BYTE Header[0x1c];
/*0x020*/ eBitmapType	eType;
	int	eMemoryPoolManagerType;//eMemoryPoolManagerType need to figure out this enum
	PCHAR	FileName;
	UINT	SourceWidth;
	UINT	SourceHeight;
	FLOAT	DetailScale;
	UINT	GrassDensity;
	UINT	Width;
	UINT	Height;
	bool	bHasTexture;
	union {
		void*pD3DTexture;//IDirect3DBaseTexture9
		void*pRawBitmap;
	};
	UINT	ObjectIndex;
	UINT	Size;
	bool	bForceMipMap;
	int		TrackingType;
	FLOAT	SQDistanceToCamera;
	UINT	LastDistanceTime;
	UINT	LastRenderTime;
	UINT	LoadedTime;
};
struct BMI {
	PCHAR Name;
	UINT Flags;
	CEQGBitmap *pBmp;
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
	/*0x00*/ bool	bValid;
	/*0x04*/ enDir	Dir;
	/*0x08*/ PCXSTR Name;
	/*0x0c*/ SIZE	TextureSize;
	/*0x14*/ UINT	TextureID;
	/*0x18*/
};
typedef struct _SuiteTexture {
	bool bUsed;
	PCXSTR Name;
	enDir Directory;
	BMI* pBMInfo;

} SuiteTexture,*PSuiteTexture;

class CEQSuiteTextureLoader
{
public:
	void *pWadFile;//SWadFile
    ArrayClass_RO<SuiteTexture> Textures;
    PCXSTR UIPath[4];
    PCXSTR DefaultUIPath[4];

EQLIB_OBJECT CEQSuiteTextureLoader::~CEQSuiteTextureLoader(void);
EQLIB_OBJECT CEQSuiteTextureLoader::CEQSuiteTextureLoader(void);
EQLIB_OBJECT BMI *CEQSuiteTextureLoader::GetTexture(const CUITextureInfo2 &ti);
EQLIB_OBJECT unsigned int CEQSuiteTextureLoader::CreateTexture(class CUITextureInfo const &);
EQLIB_OBJECT void CEQSuiteTextureLoader::UnloadAllTextures(void);
EQLIB_OBJECT const CXStr& CEQSuiteTextureLoader::GetDefaultUIPath(int DirType) const;
};

//oct 26 2015 - eqmule 
typedef struct _TARGETRING {
/*0x00*/	DWORD Gem;//the gem the spell below is memmed in... 0-11
/*0x04*/	PSPELL thespell;
/*0x08*/	ItemGlobalIndex ItemLoc;//size 0xc
/*0x14*/	ItemSpellTypes SpellType;
/*0x18*/	FLOAT SquaredRange;
/*0x1c*/	bool bCursorVisible;
/*0x20*/
} TARGETRING, *PTARGETRING;

typedef struct _EQSuccessfulHit 
{
/*0x00*/ unsigned short	DamagedID;//Spawn that was hit
/*0x02*/ unsigned short	AttackerID;//spawn who did the hit
/*0x04*/ unsigned char	Skill;//1 HS etc...
/*0x05*/ BYTE	Filler0x5[0x3];
/*0x08*/ int	SpellID;
/*0x0c*/ int	DamageCaused;
/*0x10*/ float	Force;
/*0x14*/ float	HitHeading;
/*0x18*/ float	HitPitch;
/*0x1c*/ bool	bSecondary;
/*0x1d*/ BYTE	Filler0x1d[0x3];
/*0x20*/ int	SpecialCase;//origin of damage? need to investigate further -eqmule
/*0x24*/ 
} EQSuccessfulHit, *pEQSuccessfulHit;

class CEverQuest
{
public:
EQLIB_OBJECT CEverQuest::~CEverQuest(void);
EQLIB_OBJECT CEverQuest::CEverQuest(struct HWND__ *);
EQLIB_OBJECT void CEverQuest::CreateTargetIndicator(int Slot, PSPELL pSpell, const ItemGlobalIndex& ItemLoc, ItemSpellTypes spelltype);
EQLIB_OBJECT int CEverQuest::DeleteTargetIndicator(void);
EQLIB_OBJECT bool CEverQuest::IsInTypingMode(void);
EQLIB_OBJECT bool CEverQuest::IsOkToTransact(void);
EQLIB_OBJECT bool CEverQuest::ReadClientINIBool(char *,char *,bool);
EQLIB_OBJECT bool CEverQuest::ReadUIINIBool(char *,char *,bool);
EQLIB_OBJECT char * CEverQuest::GetBodyTypeDesc(int);
EQLIB_OBJECT char * CEverQuest::GetClassDesc(int);
EQLIB_OBJECT char * CEverQuest::GetClassThreeLetterCode(int);
EQLIB_OBJECT char * CEverQuest::GetDeityDesc(int);
EQLIB_OBJECT char * CEverQuest::GetInnateDesc(int);
EQLIB_OBJECT char * CEverQuest::GetItemClassDesc(int);
EQLIB_OBJECT char * CEverQuest::GetLangDesc(int);
EQLIB_OBJECT char * CEverQuest::GetRaceDesc(int);
EQLIB_OBJECT char * CEverQuest::GetSingleMessage(unsigned __int32,int,int *,char *);
EQLIB_OBJECT char * CEverQuest::GrabFirstWord(char *,char *);
EQLIB_OBJECT char * CEverQuest::GrabFirstWord2(char *,char *,int);
EQLIB_OBJECT char * CEverQuest::ReadClientINIString(char *,char *,char *,char *,int);
EQLIB_OBJECT char * CEverQuest::ReadUIINIString(char *,char *,char *,char *,int);
EQLIB_OBJECT char * CEverQuest::stripName(char *);
EQLIB_OBJECT char * CEverQuest::StripShipName(char *,char *);
EQLIB_OBJECT char * CEverQuest::trimName(char *);
EQLIB_OBJECT class EQPlayer * CEverQuest::ClickedPlayer(int,int);
EQLIB_OBJECT class EQSwitch * CEverQuest::ClickedSwitch(int,int);
EQLIB_OBJECT enum ZONE_REQ_STATUS CEverQuest::IsZoneAvailable(char *,EQZoneIndex,enum ZONE_REQ_REASON);
EQLIB_OBJECT float CEverQuest::GetMaxLightRadius(void);
EQLIB_OBJECT float CEverQuest::ReadClientINIFloat(char *,char *,float);
EQLIB_OBJECT int CEverQuest::BeingIgnored(char *);
EQLIB_OBJECT int CEverQuest::DoLogin(struct HWND__ *,struct HINSTANCE__ *);
EQLIB_OBJECT int CEverQuest::GetCombatSound(class EQPlayer *,class EQPlayer *);
EQLIB_OBJECT int CEverQuest::GetCurrentLanguage(void)const;
EQLIB_OBJECT int CEverQuest::HandleItems(void *,int);
EQLIB_OBJECT int CEverQuest::IsFriend(char const *);
EQLIB_OBJECT int CEverQuest::IsValidName(char *);
EQLIB_OBJECT int CEverQuest::LootCorpse(class EQPlayer *,int);
EQLIB_OBJECT int CEverQuest::MoveMoney(int,int,int,int,int,bool);
EQLIB_OBJECT int CEverQuest::msgStartIcon(void *);
EQLIB_OBJECT int CEverQuest::msgStartIeq(void *);
EQLIB_OBJECT int CEverQuest::msgStartInotes(void *);
EQLIB_OBJECT int CEverQuest::ProcessMBox(void);
EQLIB_OBJECT int CEverQuest::ReadClientINIInt(char *,char *,int);
EQLIB_OBJECT int CEverQuest::ReadUIINIInt(char *,char *,int);
EQLIB_OBJECT int CEverQuest::TypingMode(void);
EQLIB_OBJECT unsigned char CEverQuest::HandleWorldMessage(struct connection_t *,unsigned __int32,char *,unsigned __int32);
EQLIB_OBJECT unsigned char CEverQuest::IFoundMyVehicle(void);
EQLIB_OBJECT void __cdecl CEverQuest::DoLoadScreenProgressBar(int,char const *,...);
EQLIB_OBJECT void CEverQuest::ApplyPoison(unsigned long);
EQLIB_OBJECT void CEverQuest::Camp(void);
EQLIB_OBJECT void CEverQuest::CancelSneakHide(void);
EQLIB_OBJECT void CEverQuest::ChatServerConnect(char *,int,char *,char *);
EQLIB_OBJECT void CEverQuest::ChatServerDisconnect(void);
EQLIB_OBJECT void CEverQuest::ChatServerGiveTime(void);
EQLIB_OBJECT void CEverQuest::ChatServerMessage(char *);
EQLIB_OBJECT void CEverQuest::ChatServerNotificationAdd(bool,char *,char *,int);
EQLIB_OBJECT void CEverQuest::ChatServerNotificationFlush(void);
EQLIB_OBJECT void CEverQuest::CleanupBadFiles(void);
EQLIB_OBJECT void CEverQuest::clr_chat_input(void);
EQLIB_OBJECT void CEverQuest::Consider(class EQPlayer *,void *);
EQLIB_OBJECT void CEverQuest::CopyFirstWord(char *,char *);
EQLIB_OBJECT void CEverQuest::CreateDataSubdirectories(void);
EQLIB_OBJECT void CEverQuest::CreateFilenameServerCode(char *);
EQLIB_OBJECT void CEverQuest::CreateIniFilenames(void);
EQLIB_OBJECT void CEverQuest::CreateInitialActors(void);
EQLIB_OBJECT void CEverQuest::DeacSpellScreen(void);
EQLIB_OBJECT void CEverQuest::Disband(void);
EQLIB_OBJECT void CEverQuest::DisplayScreen(char *);
EQLIB_OBJECT void CEverQuest::DoCharacterSelection(void);
EQLIB_OBJECT void CEverQuest::doInspect(class EQPlayer *);
EQLIB_OBJECT void CEverQuest::doInvite(unsigned __int32,char *);
EQLIB_OBJECT void CEverQuest::DoLoadScreen(int);
EQLIB_OBJECT void CEverQuest::doLoot(void);
EQLIB_OBJECT void CEverQuest::DoMainLoop(struct HWND__ *);
EQLIB_OBJECT void CEverQuest::DoNewCharacterCreation(void);
EQLIB_OBJECT void CEverQuest::DoPercentConvert(char *line, bool bOutGoing);
EQLIB_OBJECT void CEverQuest::DoSplit(char *);
EQLIB_OBJECT void CEverQuest::DoTellWindow(char *,char *,char *,void *,int,bool);
EQLIB_OBJECT void CEverQuest::OutputTextToLog(const char*Text);
EQLIB_OBJECT void CEverQuest::doUnInvite(char *);
EQLIB_OBJECT void CEverQuest::DropHeldItemOnGround(int);
EQLIB_OBJECT void CEverQuest::DropHeldMoneyOnGround(int);
EQLIB_OBJECT void CEverQuest::DropItemOrMoneyOnPlayer(class EQPlayer *);
EQLIB_OBJECT void CEverQuest::dsp_chat(char const *);
EQLIB_OBJECT void CEverQuest::dsp_chat(char const *line,int color,bool bLogIsOk,bool bConvertPercent);
EQLIB_OBJECT void CEverQuest::dsp_chat(char const *,int,bool);
EQLIB_OBJECT void CEverQuest::Emote(void);
EQLIB_OBJECT void CEverQuest::EnterZone(struct HWND__ *);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT int CEverQuest::Follow(int);
#else
EQLIB_OBJECT int CEverQuest::Follow(void);
#endif
EQLIB_OBJECT void CEverQuest::FreeSwitches(void);
EQLIB_OBJECT void CEverQuest::GetSndDriver(void);
EQLIB_OBJECT void CEverQuest::GetZoneInfoFromNetwork(char *);
EQLIB_OBJECT void CEverQuest::GuildDelete(void);
EQLIB_OBJECT void CEverQuest::GuildInvite(char *,char *);
EQLIB_OBJECT void CEverQuest::GuildLeader(char *);
EQLIB_OBJECT void CEverQuest::GuildPeace(char *);
EQLIB_OBJECT void CEverQuest::GuildRemove(char *);
EQLIB_OBJECT void CEverQuest::GuildSay(char *);
EQLIB_OBJECT void CEverQuest::GuildStatus(char *);
EQLIB_OBJECT void CEverQuest::GuildWar(char *,int);
EQLIB_OBJECT void CEverQuest::InitCommands(void);
EQLIB_OBJECT void CEverQuest::initCustom(void);
EQLIB_OBJECT void CEverQuest::InterpretCmd(class EQPlayer *,char *);
EQLIB_OBJECT void CEverQuest::Invite(int);
EQLIB_OBJECT void CEverQuest::InviteOk(char *);
EQLIB_OBJECT void CEverQuest::IssueLfgGroupQuery(struct LfgGroupQuery *);
EQLIB_OBJECT void CEverQuest::IssueLfgPlayerQuery(struct LfgPlayerQuery *);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT void CEverQuest::IssuePetCommand(ePetCommandType, int TargetID, bool bQuiet, bool bsomethingelse = 1);
#else
EQLIB_OBJECT void CEverQuest::IssuePetCommand(ePetCommandType, int TargetID, bool bQuiet);
#endif
EQLIB_OBJECT void CEverQuest::Kill(char *,char *);
EQLIB_OBJECT void CEverQuest::LeaveBankMode(bool);
EQLIB_OBJECT void CEverQuest::LeaveGuildMaster(void);
EQLIB_OBJECT void CEverQuest::LeftClickedOnPlayer(class EQPlayer *);
EQLIB_OBJECT void CEverQuest::LMouseDown(int,int);
EQLIB_OBJECT void CEverQuest::LMouseUp(int,int);
EQLIB_OBJECT void CEverQuest::loadCustom(void);
EQLIB_OBJECT void CEverQuest::loadCustomFromINI(char *);
EQLIB_OBJECT void CEverQuest::loadOptions(void);
EQLIB_OBJECT void CEverQuest::loadSoundsGame(void);
EQLIB_OBJECT void CEverQuest::LoadStringTables(void);
EQLIB_OBJECT void CEverQuest::LoadSwitchesNonAvatar(EQZoneIndex);
EQLIB_OBJECT void CEverQuest::LocalDeath(struct _EQPlayerDeath *,unsigned char);
EQLIB_OBJECT void CEverQuest::MouseWheelScrolled(int);
EQLIB_OBJECT void CEverQuest::MoveToZone(int,char*,int,int,float,float,float,int);
EQLIB_OBJECT void CEverQuest::MoveToZone(char *,char *,int,enum ZONE_REQ_REASON);
EQLIB_OBJECT void CEverQuest::MoveToZone(EQZoneIndex,char *,int,enum ZONE_REQ_REASON);
EQLIB_OBJECT void CEverQuest::PrepareLocalPCForRepop(void);
EQLIB_OBJECT void CEverQuest::ProcessControls(void);
EQLIB_OBJECT void CEverQuest::ProcessGame(struct HWND__ *,struct HINSTANCE__ *);
EQLIB_OBJECT void CEverQuest::ProcessLocalPCIni(int);
EQLIB_OBJECT void CEverQuest::procMouse(int);
EQLIB_OBJECT void CEverQuest::RemoveCharacterOptionFile(char *);
EQLIB_OBJECT void CEverQuest::ReportDeath(struct _EQPlayerDeath *);
EQLIB_OBJECT void CEverQuest::ReportSuccessfulHit(EQSuccessfulHit *pHit,unsigned char bOutputText,int ActualHeal);
EQLIB_OBJECT void CEverQuest::reqChannel(void);
EQLIB_OBJECT void CEverQuest::ResetVisionRGBs(void);
EQLIB_OBJECT void CEverQuest::RightClickedOnPlayer(class EQPlayer *, int);
EQLIB_OBJECT void CEverQuest::RMouseDown(int,int);
EQLIB_OBJECT void CEverQuest::RMouseUp(int,int);
EQLIB_OBJECT void CEverQuest::SaveCamerasToINI(void);
EQLIB_OBJECT void CEverQuest::saveCustom(void);
EQLIB_OBJECT void CEverQuest::saveOptions(void);
EQLIB_OBJECT void CEverQuest::saveOptions2(void);
EQLIB_OBJECT void CEverQuest::SavePC(int,int,unsigned char);
EQLIB_OBJECT void CEverQuest::SavePCForce(int);
EQLIB_OBJECT void CEverQuest::send_auction(void);
EQLIB_OBJECT void CEverQuest::send_broadcast(void);
EQLIB_OBJECT void CEverQuest::send_chat(void);
EQLIB_OBJECT void CEverQuest::send_gsay(void);
EQLIB_OBJECT void CEverQuest::send_ooc(void);
EQLIB_OBJECT void CEverQuest::send_petition(void);
EQLIB_OBJECT void CEverQuest::send_private(void);
EQLIB_OBJECT void CEverQuest::send_shout(void);
EQLIB_OBJECT void CEverQuest::send_social(int,char *,char *);
EQLIB_OBJECT void CEverQuest::send_tell(char *,char *);
EQLIB_OBJECT void CEverQuest::send_update_filters(void);
EQLIB_OBJECT void CEverQuest::SendLightInfo(class EQPlayer *,unsigned char);
EQLIB_OBJECT void CEverQuest::SendNewText(int,char *,char *);
EQLIB_OBJECT void CEverQuest::SetDefaultDamageDescByRace(char *,int,unsigned char);
EQLIB_OBJECT void CEverQuest::SetDefaultGameValues(void);
EQLIB_OBJECT void CEverQuest::SetGameState(int);
EQLIB_OBJECT void CEverQuest::SetLfgGroupStatus(struct LfgGroupStatus *);
EQLIB_OBJECT void CEverQuest::SetLfgPlayerStatus(struct LfgPlayerStatus *);
EQLIB_OBJECT void CEverQuest::SetPlayerAppearanceFromPInfo(class EQPlayer *,int,bool);
EQLIB_OBJECT void CEverQuest::SetTimedFog(int);
EQLIB_OBJECT void CEverQuest::SetupCharSelectCamera(void);
EQLIB_OBJECT void CEverQuest::Sit(void);
EQLIB_OBJECT void CEverQuest::SortSpellLoadouts(void);
EQLIB_OBJECT void CEverQuest::StartCasting(void *);
EQLIB_OBJECT void CEverQuest::StartNetworkGame(struct HWND__ *,struct HINSTANCE__ *,char *);
EQLIB_OBJECT void CEverQuest::Surname(char *);
EQLIB_OBJECT void CEverQuest::ToggleAutoSplit(void);
EQLIB_OBJECT void CEverQuest::UpdateMyAppearance(void);
EQLIB_OBJECT void CEverQuest::UseCharge(unsigned long);
EQLIB_OBJECT void CEverQuest::WhatTimeIsIt(void);
EQLIB_OBJECT void CEverQuest::Who(char *);
EQLIB_OBJECT void CEverQuest::WriteBoolToClientINI(bool,char *,char *);
EQLIB_OBJECT void CEverQuest::WriteBoolToUIINI(bool,char *,char *);
EQLIB_OBJECT void CEverQuest::WriteFloatToClientINI(float,char *,char *);
EQLIB_OBJECT void CEverQuest::WriteIntToClientINI(int,char *,char *);
EQLIB_OBJECT void CEverQuest::WriteIntToUIINI(int,char *,char *);
EQLIB_OBJECT void CEverQuest::WriteStringToClientINI(char *,char *,char *);
EQLIB_OBJECT void CEverQuest::WriteStringToUIINI(char *,char *,char *);
// virtual
EQLIB_OBJECT void CEverQuest::CshOnBuddyStatusChange(char *,int BuddyStatus);
EQLIB_OBJECT void CEverQuest::CshOnChannelListChange(void);
EQLIB_OBJECT void CEverQuest::CshOnMessage(char *,char *,int,char *,bool);
EQLIB_OBJECT void CEverQuest::CshOnPlayerEntering(char *,int,char *);
EQLIB_OBJECT void CEverQuest::CshOnPlayerLeaving(char *,int,char *);
};

class CExploreModeWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CExploreModeWnd::CExploreModeWnd(class CXWnd *);
EQLIB_OBJECT void CExploreModeWnd::Activate(void);
// virtual
EQLIB_OBJECT CExploreModeWnd::~CExploreModeWnd(void);
//EQLIB_OBJECT void * CExploreModeWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CExploreModeWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CExploreModeWnd::Deactivate(void);
};
class CExtendedTargetWnd : public CSidlScreenWnd
{
public:

};
//Size: 258h see 53F643 Nov 29 2018 Beta -eqmule 
class CFactionWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CFactionWnd::CFactionWnd(class CXWnd *);
};
class CFacePick : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CFacePick::CFacePick(class CXWnd *);
EQLIB_OBJECT void CFacePick::Activate(void);
EQLIB_OBJECT void CFacePick::SetFaceSelectionsFromPlayer(void);
// virtual
EQLIB_OBJECT CFacePick::~CFacePick(void);
EQLIB_OBJECT int CFacePick::Draw(void)const;
EQLIB_OBJECT int CFacePick::OnProcessFrame(void);
EQLIB_OBJECT int CFacePick::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CFacePick::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CFacePick::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CFacePick::Deactivate(void);
// private
EQLIB_OBJECT void CFacePick::CycleThroughFHEB(int,int);
EQLIB_OBJECT void CFacePick::Init(void);
EQLIB_OBJECT void CFacePick::ShowButtonGroup(int,bool);
};
class CFindItemWnd : public CSidlScreenWnd//, public WndEventHandler but we just add the member LastCheckTime
{
public:
	/*0x230*/ UINT LastCheckTime;//from WndEventHandler
	/*0x234*/ CComboWnd *SearchCombo0;
	/*0x238*/ CComboWnd *SearchCombo1;
	/*0x23c*/ int SelIndex;
	/*0x240*/ VeArray<ItemGlobalIndex*>gi;
	/*0x24c*/ int Unknown0x24c;
	/*0x250*/ int Unknown0x250;
	/*0x254*/ int Unknown0x254;
	/*0x258*/ int Unknown0x258;
	/*0x25c*/ int Unknown0x25c;
	/*0x260*/ int FIW_ClassAnim;
	/*0x264*/ CSidlScreenWnd *FIW_CharacterView;
	/*0x268*/ CListWnd *FIW_ItemList;
	/*0x26c*/ CButtonWnd * FIW_QueryButton;
	/*0x270*/ CButtonWnd * FIW_RequestItemButton;
	/*0x274*/ CButtonWnd * FIW_RequestPreviewButton;
	/*0x278*/ CButtonWnd * FIW_Default;
	/*0x27c*/ CButtonWnd * FIW_GrabButton;
	/*0x280*/ CButtonWnd * FIW_HighlightButton;
	/*0x284*/ CButtonWnd * FIW_DestroyItem;
	/*0x288*/ CComboWnd * FIW_ItemLocationCombobox;
	/*0x28c*/ CComboWnd * FIW_ItemSlotCombobox;
	/*0x290*/ CComboWnd * FIW_StatSlotCombobox;
	/*0x294*/ CComboWnd * FIW_RaceSlotCombobox;
	/*0x298*/ CComboWnd * FIW_ClassSlotCombobox;
	/*0x29c*/ CComboWnd * FIW_ItemTypeCombobox;
	/*0x2a0*/ CComboWnd * FIW_ItemPrestigeCombobox;
	/*0x2a4*/ CComboWnd * FIW_ItemAugmentCombobox;
	/*0x2a8*/ CEditWnd * FIW_ItemNameInput;
	/*0x2ac*/ CEditWnd * FIW_MaxLevelInput;
	/*0x2b0*/ CEditWnd * FIW_MinLevelInput;
	/*0x2b4*/ CEditWnd * Unknown0x2b4;
	/*0x2B8*/
	#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT CFindItemWnd::CFindItemWnd(CXWnd *);
	EQLIB_OBJECT void CFindItemWnd::Update();
	EQLIB_OBJECT void CFindItemWnd::PickupSelectedItem();
	EQLIB_OBJECT int CFindItemWnd::WndNotification(CXWnd *,unsigned __int32,void *);
	#endif
};
class CFeedbackWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CFeedbackWnd::CFeedbackWnd(class CXWnd *);
EQLIB_OBJECT void CFeedbackWnd::Activate(void);
// virtual
EQLIB_OBJECT CFeedbackWnd::~CFeedbackWnd(void);
EQLIB_OBJECT int CFeedbackWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CFeedbackWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CFeedbackWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CFeedbackWnd::Deactivate(void);
};
class CUnSerializeBuffer
{
public:
    const char*		m_pBuffer;
    unsigned int	m_uLength;
    unsigned int	m_uReadOffset;

    void Reset() { m_uReadOffset = 0; }

    template< typename T> void Read( T& r )
    {
        r = *(T*)(m_pBuffer + m_uReadOffset);
        m_uReadOffset += sizeof( T );
        return;
    }

    void ReadString( std::string& out )
    {
        int len = 0;
        while( m_pBuffer[m_uReadOffset] != '\0' )
        {
            out.append( 1, (char)(m_pBuffer[m_uReadOffset]) );
            m_uReadOffset++;
        }
        m_uReadOffset++;
    }
	template <typename T> void Read(T* r, size_t size)
	{
		size_t savedSize;
		Read( savedSize );
		for( size_t i = 0; i < savedSize && i < size; i++ )
		{
			Read( r[i] );
		}
	}
	template <unsigned int _Size>void ReadpChar(char(&_Buffer)[_Size])
    {
		_Buffer[0] = '\0';
		int len = 0;
        while( m_pBuffer[m_uReadOffset] != '\0' && len<_Size)
        {
			_Buffer[len++] = (char)(m_pBuffer[m_uReadOffset]);
            m_uReadOffset++;
        }
		//take null term into account...
        m_uReadOffset++;
    }
	
};
class CFindLocationWnd : public CSidlScreenWnd
{
	//has virtuals, but we get those from CSidlScreenWnd
public:
	EQLIB_OBJECT bool CFindLocationWnd::HandleFindBegin();
	EQLIB_OBJECT void CFindLocationWnd::HandleFindEnd();
	EQLIB_OBJECT void CFindLocationWnd::HandleRowClicked(int Index);
	EQLIB_OBJECT void CFindLocationWnd::HandleFindableZoneConnectionsMessage(CUnSerializeBuffer &buf);
};

class CFileSelectionWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CFileSelectionWnd::CFileSelectionWnd(class CXWnd *);
EQLIB_OBJECT class CXStr CFileSelectionWnd::GetSelectedFile(int);
EQLIB_OBJECT int CFileSelectionWnd::GetSelectedFileCount(void);
EQLIB_OBJECT void CFileSelectionWnd::Activate(class CXWnd *,int);
EQLIB_OBJECT void CFileSelectionWnd::Callback(bool);
// virtual
EQLIB_OBJECT CFileSelectionWnd::~CFileSelectionWnd(void);
EQLIB_OBJECT int CFileSelectionWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CFileSelectionWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CFileSelectionWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CFileSelectionWnd::Deactivate(void);
// private
EQLIB_OBJECT bool CFileSelectionWnd::DirectoryEmpty(IShellFolder *,struct _ITEMIDLIST *);
EQLIB_OBJECT unsigned long CFileSelectionWnd::GetPath(IShellFolder *,struct _ITEMIDLIST *,bool,class CXStr &);
EQLIB_OBJECT void CFileSelectionWnd::ClearFileList(void);
EQLIB_OBJECT void CFileSelectionWnd::GoSubdirectory(struct _ITEMIDLIST *);
EQLIB_OBJECT void CFileSelectionWnd::MakeFilePath(void);
EQLIB_OBJECT void CFileSelectionWnd::UpdateButtons(void);
EQLIB_OBJECT void CFileSelectionWnd::UpdateFileList(void);
};

class CFriendsWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CFriendsWnd::CFriendsWnd(class CXWnd *);
EQLIB_OBJECT void CFriendsWnd::Activate(void);
EQLIB_OBJECT void CFriendsWnd::UpdateFriendsList(void);
EQLIB_OBJECT void CFriendsWnd::UpdateIgnoreList(void);
// virtual
EQLIB_OBJECT CFriendsWnd::~CFriendsWnd(void);
EQLIB_OBJECT int CFriendsWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CFriendsWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CFriendsWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CFriendsWnd::Deactivate(void);
// protected
EQLIB_OBJECT void CFriendsWnd::AddFriend(void);
EQLIB_OBJECT void CFriendsWnd::AddIgnore(void);
EQLIB_OBJECT void CFriendsWnd::UpdateButtons(void);
};

class CGaugeDrawTemplate
{
public:
/*0x00*/ PCXSTR              Name;
/*0x04*/ CTextureAnimation   *Background;
/*0x08*/ CTextureAnimation   *Fill;
/*0x0c*/ CTextureAnimation   *Lines;
/*0x10*/ CTextureAnimation   *LinesFill;
/*0x14*/ CTextureAnimation   *EndCapLeft;
/*0x18*/ CTextureAnimation   *EndCapRight;
/*0x1c*/ 
EQLIB_OBJECT CGaugeDrawTemplate::~CGaugeDrawTemplate(void);
};

class CGaugeTemplate
{
public:
EQLIB_OBJECT CGaugeTemplate::CGaugeTemplate(class CParamGauge *);
// virtual
EQLIB_OBJECT CGaugeTemplate::~CGaugeTemplate(void);
//EQLIB_OBJECT void * CGaugeTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CGaugeTemplate::`vector deleting destructor'(unsigned int);
};
//size 0x248 see 7E24DB in Sep 21 2018 -eqmule
class CGaugeWnd : public CXWnd
{
public:
//*0x000*/ PCXWNDVFTABLE pvfTable;
//*0x004*/ CXW_NO_VTABLE	
/*0x1e0*/ int			EQType;
/*0x1e4*/ D3DCOLOR		FillTint;
/*0x1e8*/ D3DCOLOR		LinesFillTint;
/*0x1ec*/ bool			bDrawLinesFill;
/*0x1f0*/ int			TextOffsetX;
/*0x1f4*/ int			TextOffsetY;
/*0x1f8*/ int			GaugeOffsetX;
/*0x1fc*/ int			GaugeOffsetY;
/*0x200*/ FLOAT			LastFrameVal;
/*0x204*/ PCXSTR		LastFrameName;
/*0x208*/ LONG			LastFrameTime;
/*0x20c*/ int			LastFrameTarget;
/*0x210*/ PCXSTR		GaugeTooltip;
/*0x214*/ int			TooltipVal;
/*0x218*/ CGaugeDrawTemplate	DrawTemplate;//size 0x1c
/*0x234*/ void*			pTextObject;//CTextObjectInterface
/*0x238*/ PCXSTR		NextDrawStr;
/*0x23c*/ bool			bSmooth;
/*0x240*/ int			TargetVal;
/*0x244*/ bool			bUseTargetVal;
/*0x248*/

EQLIB_OBJECT CGaugeWnd::CGaugeWnd(class CXWnd *,unsigned __int32,class CXRect,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,int,unsigned long,unsigned long,bool,int,int,int,int);
EQLIB_OBJECT class CXRect CGaugeWnd::CalcFillRect(class CXRect *,int)const;
EQLIB_OBJECT class CXRect CGaugeWnd::CalcLinesFillRect(class CXRect *,int)const;
EQLIB_OBJECT void CGaugeWnd::SpecialToolTip(void);
// virtual
EQLIB_OBJECT CGaugeWnd::~CGaugeWnd(void);
EQLIB_OBJECT int CGaugeWnd::Draw(void)const;
EQLIB_OBJECT int CGaugeWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CGaugeWnd::OnProcessFrame(void);
//EQLIB_OBJECT void * CGaugeWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CGaugeWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGaugeWnd::SetAttributesFromSidl(class CParamScreenPiece *);
};

class CGemsGameWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CGemsGameWnd::CGemsGameWnd(class CXWnd *);
EQLIB_OBJECT void CGemsGameWnd::Activate(void);
EQLIB_OBJECT void CGemsGameWnd::MoveCurBlock(int);
// virtual
EQLIB_OBJECT CGemsGameWnd::~CGemsGameWnd(void);
EQLIB_OBJECT int CGemsGameWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CGemsGameWnd::OnProcessFrame(void);
EQLIB_OBJECT int CGemsGameWnd::PostDraw(void)const;
EQLIB_OBJECT int CGemsGameWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CGemsGameWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CGemsGameWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGemsGameWnd::Deactivate(void);
// private
EQLIB_OBJECT bool CGemsGameWnd::BadSpecial(int)const;
EQLIB_OBJECT bool CGemsGameWnd::LegalBlockMove(int,int,int,int,bool);
EQLIB_OBJECT int CGemsGameWnd::GetRndBlockImage(void);
EQLIB_OBJECT void CGemsGameWnd::ActivateSpecialMode(int);
EQLIB_OBJECT void CGemsGameWnd::AdvanceToNextWave(void);
EQLIB_OBJECT void CGemsGameWnd::CheckForMatches(int,int);
EQLIB_OBJECT void CGemsGameWnd::CheckForNewHighScore(void);
EQLIB_OBJECT void CGemsGameWnd::ClearBlock(struct _GemsBlock *);
EQLIB_OBJECT void CGemsGameWnd::ClearHighScores(void);
EQLIB_OBJECT void CGemsGameWnd::DoMatchScore(int);
EQLIB_OBJECT void CGemsGameWnd::DrawSpellGem(int,class CXRect,int,bool)const;
EQLIB_OBJECT void CGemsGameWnd::GetNextBlock(void);
EQLIB_OBJECT void CGemsGameWnd::Init(void);
EQLIB_OBJECT void CGemsGameWnd::MakeBlockDrop(int,int,int);
EQLIB_OBJECT void CGemsGameWnd::MarkHigherBlocksFalling(int,int);
EQLIB_OBJECT void CGemsGameWnd::ProcessMatches(int);
EQLIB_OBJECT void CGemsGameWnd::ProcessMoveCurBlock(int);
EQLIB_OBJECT void CGemsGameWnd::ReadHighScores(void);
EQLIB_OBJECT void CGemsGameWnd::Restart(void);
EQLIB_OBJECT void CGemsGameWnd::SetNextUpdate(void);
EQLIB_OBJECT void CGemsGameWnd::SetPause(bool);
EQLIB_OBJECT void CGemsGameWnd::TogglePause(void);
EQLIB_OBJECT void CGemsGameWnd::Update(void);
EQLIB_OBJECT void CGemsGameWnd::UpdateDisplay(void);
EQLIB_OBJECT void CGemsGameWnd::WriteHighScores(void);
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
	CButtonWnd  *pMoneyButton[4];
    CButtonWnd  *TradeButton;
    CButtonWnd *CancelButton;
	CLabel *NPCNameLabel;
	CInvSlotWnd *pInvSlotWnd[4];

EQLIB_OBJECT CGiveWnd::CGiveWnd(class CXWnd *);
EQLIB_OBJECT void CGiveWnd::Activate(void);
EQLIB_OBJECT void CGiveWnd::UpdateGiveDisplay(void);
// virtual
EQLIB_OBJECT CGiveWnd::~CGiveWnd(void);
EQLIB_OBJECT int CGiveWnd::OnProcessFrame(void);
EQLIB_OBJECT int CGiveWnd::PostDraw(void)const;
EQLIB_OBJECT int CGiveWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CGiveWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CGiveWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGiveWnd::Deactivate(void);
// private
EQLIB_OBJECT void CGiveWnd::Init(void);
};

class CGroupSearchFiltersWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CGroupSearchFiltersWnd::CGroupSearchFiltersWnd(class CXWnd *);
EQLIB_OBJECT bool CGroupSearchFiltersWnd::ShouldFilterPlayer(char const *,char const *)const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::UseExclusiveSearchMode(void)const;
EQLIB_OBJECT void CGroupSearchFiltersWnd::Activate(void);
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleAddDesiredGuild(void);
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleAddExcludedGuild(void);
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleDesiredGuildsSelected(void);
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleExcludeGuildsSelected(void);
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleRemoveAllDesiredGuilds(void);
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleRemoveAllExcludedGuilds(void);
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleRemoveDesiredGuild(void);
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleRemoveExcludedGuild(void);
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleUseFriendsListSelected(void);
EQLIB_OBJECT void CGroupSearchFiltersWnd::HandleUseIgnoreListSelected(void);
// virtual
EQLIB_OBJECT CGroupSearchFiltersWnd::~CGroupSearchFiltersWnd(void);
EQLIB_OBJECT int CGroupSearchFiltersWnd::OnProcessFrame(void);
EQLIB_OBJECT int CGroupSearchFiltersWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CGroupSearchFiltersWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CGroupSearchFiltersWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGroupSearchFiltersWnd::Deactivate(void);
// private
EQLIB_OBJECT bool CGroupSearchFiltersWnd::GuildIsInDesiredGuildsList(char const *)const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::GuildIsInExcludedGuildsList(char const *)const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::Load(void);
EQLIB_OBJECT bool CGroupSearchFiltersWnd::NameIsInFriendsList(char const *)const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::NameIsInIgnoreList(char const *)const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::UseDesiredGuilds(void)const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::UseExcludedGuilds(void)const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::UseFriendsList(void)const;
EQLIB_OBJECT bool CGroupSearchFiltersWnd::UseIgnoreList(void)const;
EQLIB_OBJECT void CGroupSearchFiltersWnd::ClearUiPointers(void);
EQLIB_OBJECT void CGroupSearchFiltersWnd::FetchUiPointers(void);
EQLIB_OBJECT void CGroupSearchFiltersWnd::InitPieces(void);
EQLIB_OBJECT void CGroupSearchFiltersWnd::Save(void)const;
};

class CGroupSearchWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CGroupSearchWnd::CGroupSearchWnd(class CXWnd *);
EQLIB_OBJECT void CGroupSearchWnd::Activate(int);
EQLIB_OBJECT void CGroupSearchWnd::AddGroupResult(struct LfgGroupResult const *);
EQLIB_OBJECT void CGroupSearchWnd::AddPlayerResult(struct LfgPlayerResult const *);
EQLIB_OBJECT void CGroupSearchWnd::HandleDeselectAllClasses(void);
EQLIB_OBJECT void CGroupSearchWnd::HandleDoubleClickedOnPlayer(char const *);
EQLIB_OBJECT void CGroupSearchWnd::HandleGroupInfoPost(void);
EQLIB_OBJECT void CGroupSearchWnd::HandleGroupInfoRemove(void);
EQLIB_OBJECT void CGroupSearchWnd::HandleGroupInfoUpdate(void);
EQLIB_OBJECT void CGroupSearchWnd::HandleGroupMakeupChanged(void);
EQLIB_OBJECT void CGroupSearchWnd::HandleGroupResultColSelected(int);
EQLIB_OBJECT void CGroupSearchWnd::HandleGroupResultRowSelected(int);
EQLIB_OBJECT void CGroupSearchWnd::HandleNumericSort(class SListWndSortInfo *);
EQLIB_OBJECT void CGroupSearchWnd::HandleOpenFiltersWindow(void);
EQLIB_OBJECT void CGroupSearchWnd::HandlePlayerInfoPost(void);
EQLIB_OBJECT void CGroupSearchWnd::HandlePlayerInfoRemove(void);
EQLIB_OBJECT void CGroupSearchWnd::HandlePlayerInfoUpdate(void);
EQLIB_OBJECT void CGroupSearchWnd::HandlePlayerResultColSelected(int);
EQLIB_OBJECT void CGroupSearchWnd::HandleQueryingForGroups(void);
EQLIB_OBJECT void CGroupSearchWnd::HandleQueryingForPlayers(void);
EQLIB_OBJECT void CGroupSearchWnd::HandleSelectAllClasses(void);
EQLIB_OBJECT void CGroupSearchWnd::ResetGroupList(void);
EQLIB_OBJECT void CGroupSearchWnd::ResetPlayerList(void);
EQLIB_OBJECT void CGroupSearchWnd::SendServerLfgOff(void);
EQLIB_OBJECT void CGroupSearchWnd::SendServerLfgOn(void);
EQLIB_OBJECT void CGroupSearchWnd::SendServerLfpOff(void);
EQLIB_OBJECT void CGroupSearchWnd::SendServerLfpOn(void);
// virtual
EQLIB_OBJECT CGroupSearchWnd::~CGroupSearchWnd(void);
EQLIB_OBJECT int CGroupSearchWnd::OnProcessFrame(void);
EQLIB_OBJECT int CGroupSearchWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CGroupSearchWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CGroupSearchWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGroupSearchWnd::Deactivate(void);
// private
EQLIB_OBJECT bool CGroupSearchWnd::IsLevelRangeValid(int,int)const;
EQLIB_OBJECT bool CGroupSearchWnd::PlayerShouldBeFiltered(struct LfgPlayerData const *)const;
EQLIB_OBJECT int CGroupSearchWnd::CheckIfCurrentLfgInfoIsValid(void)const;
EQLIB_OBJECT int CGroupSearchWnd::CheckIfCurrentLfpInfoIsValid(void)const;
EQLIB_OBJECT int CGroupSearchWnd::GetDesiredClassesFlag(void)const;
EQLIB_OBJECT int CGroupSearchWnd::GetDesiredGroupMaxLevel(void)const;
EQLIB_OBJECT int CGroupSearchWnd::GetDesiredGroupMinLevel(void)const;
EQLIB_OBJECT int CGroupSearchWnd::GetDesiredPlayerMaxLevel(void)const;
EQLIB_OBJECT int CGroupSearchWnd::GetDesiredPlayerMinLevel(void)const;
EQLIB_OBJECT int CGroupSearchWnd::GetEqClassType(int)const;
EQLIB_OBJECT int CGroupSearchWnd::GroupInfoPageOnProcessFrame(void);
EQLIB_OBJECT int CGroupSearchWnd::GroupInfoPageWndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int CGroupSearchWnd::GroupListPageOnProcessFrame(void);
EQLIB_OBJECT int CGroupSearchWnd::GroupListPageWndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int CGroupSearchWnd::PlayerInfoPageOnProcessFrame(void);
EQLIB_OBJECT int CGroupSearchWnd::PlayerInfoPageWndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int CGroupSearchWnd::PlayerListPageOnProcessFrame(void);
EQLIB_OBJECT int CGroupSearchWnd::PlayerListPageWndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int CGroupSearchWnd::RedirectOnProcessFrameTo(class CPageWnd *);
EQLIB_OBJECT int CGroupSearchWnd::RedirectWndNotificationTo(class CPageWnd *,class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT void CGroupSearchWnd::ClearUiPointers(void);
EQLIB_OBJECT void CGroupSearchWnd::FetchUiPointers(void);
EQLIB_OBJECT void CGroupSearchWnd::FilterOutBadWords(char const *,char *)const;
EQLIB_OBJECT void CGroupSearchWnd::GetDefaultLfgLevelRange(class EQ_PC const *,int *,int *)const;
EQLIB_OBJECT void CGroupSearchWnd::GetDefaultLfpLevelRange(class EQ_PC const *,int *,int *)const;
EQLIB_OBJECT void CGroupSearchWnd::InitLfg(void);
EQLIB_OBJECT void CGroupSearchWnd::InitLfp(void);
EQLIB_OBJECT void CGroupSearchWnd::LockQueryButtonAtTime(long);
EQLIB_OBJECT void CGroupSearchWnd::PopUpErrorMessage(int)const;
EQLIB_OBJECT void CGroupSearchWnd::ShowGroupDetails(struct LfgGroupResult const *);
EQLIB_OBJECT void CGroupSearchWnd::UpdateGroupLabel(void);
EQLIB_OBJECT void CGroupSearchWnd::UpdateLfgPostingStatus(void);
EQLIB_OBJECT void CGroupSearchWnd::UpdateLfpPostingStatus(void);
EQLIB_OBJECT void CGroupSearchWnd::UpdatePlayerLabel(void);
EQLIB_OBJECT void CGroupSearchWnd::UpdateRemainingQueryLockedTime(long);
};
//Sep 21 2018 -eqmule
class CGroupWnd : public CSidlScreenWnd
{
public:
	CButtonWnd  *InviteButton;
    CButtonWnd  *DisbandButton;
    CButtonWnd  *FollowButton;
    CButtonWnd  *DeclineButton;
    CButtonWnd  *LFGButton;
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
	CContextMenu *GroupContextMenu;
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

EQLIB_OBJECT CGroupWnd::CGroupWnd(class CXWnd *);
EQLIB_OBJECT void CGroupWnd::Activate(void);
EQLIB_OBJECT void CGroupWnd::CreateLocalMenu(void);
EQLIB_OBJECT void CGroupWnd::KeyMapUpdated(void);
EQLIB_OBJECT void CGroupWnd::SetInvited(bool);
EQLIB_OBJECT void CGroupWnd::UpdateContextMenu(void);
// virtual
EQLIB_OBJECT CGroupWnd::~CGroupWnd(void);
EQLIB_OBJECT int CGroupWnd::Draw(void)const;
EQLIB_OBJECT int CGroupWnd::OnProcessFrame(void);
EQLIB_OBJECT int CGroupWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CGroupWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CGroupWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGroupWnd::Deactivate(void);
EQLIB_OBJECT void CGroupWnd::LoadIniInfo(void);
EQLIB_OBJECT void CGroupWnd::StoreIniInfo(void);
// protected
EQLIB_OBJECT void CGroupWnd::UpdateButtons(void);
EQLIB_OBJECT void CGroupWnd::UpdateDisplay(int Index, PSPAWNINFO groupmember, COLORREF NameColor, UINT RoleBits);
// private
EQLIB_OBJECT void CGroupWnd::Init(void);
};

class CGuild
{
public:
EQLIB_OBJECT CGuild::CGuild(void);
EQLIB_OBJECT bool CGuild::ValidGuildName(int);
EQLIB_OBJECT char * CGuild::GetGuildMotd(void);
EQLIB_OBJECT char * CGuild::GetGuildMotdAuthor(void);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT char * CGuild::GetGuildName(__int64);
EQLIB_OBJECT __int64 CGuild::GetGuildIndex(char *);
#else
EQLIB_OBJECT char * CGuild::GetGuildName(DWORD);
EQLIB_OBJECT int  CGuild::GetGuildIndex(char *);
#endif
EQLIB_OBJECT class GuildMember * CGuild::FindMemberByName(char *);
EQLIB_OBJECT void CGuild::DeleteAllMembers(void);
EQLIB_OBJECT void CGuild::DemoteMember(class GuildMember *);
EQLIB_OBJECT void CGuild::HandleGuildMessage(struct connection_t *,unsigned __int32,char *,unsigned __int32);
EQLIB_OBJECT void CGuild::SendPublicCommentChange(char *,char *);
EQLIB_OBJECT void CGuild::SetGuildMotd(struct guildmotdSet *);
// virtual
EQLIB_OBJECT CGuild::~CGuild(void);
//EQLIB_OBJECT void * CGuild::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CGuild::`vector deleting destructor'(unsigned int);
// private
EQLIB_OBJECT void CGuild::AddGuildMember(class GuildMember *);
EQLIB_OBJECT void CGuild::ChangeGuildMemberName(char *);
EQLIB_OBJECT void CGuild::HandleAddGuildMember(char *,int);
EQLIB_OBJECT void CGuild::HandleDeleteGuildResponse(char *);
EQLIB_OBJECT void CGuild::HandleGuildInvite(struct connection_t *,unsigned __int32,char *,unsigned __int32);
EQLIB_OBJECT void CGuild::HandleMemberLevelUpdate(char *);
EQLIB_OBJECT void CGuild::HandleRemoveGuildMember(char *,int);
EQLIB_OBJECT void CGuild::InitializeFromDump(char *);
EQLIB_OBJECT void CGuild::UpdateGuildMemberOnWindow(class GuildMember *);
EQLIB_OBJECT void CGuild::UpdateMemberStatus(char *);
EQLIB_OBJECT void CGuild::UpdatePublicComment(char *);
};

class CGuildMgmtWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CGuildMgmtWnd::CGuildMgmtWnd(class CXWnd *);
EQLIB_OBJECT void CGuildMgmtWnd::Activate(void);
EQLIB_OBJECT void CGuildMgmtWnd::AddMember(class GuildMember *);
EQLIB_OBJECT void CGuildMgmtWnd::Clean(void);
EQLIB_OBJECT void CGuildMgmtWnd::DumpToFile(char *);
EQLIB_OBJECT void CGuildMgmtWnd::RemoveMember(class GuildMember *);
EQLIB_OBJECT void CGuildMgmtWnd::RenameMember(char *,char *);
EQLIB_OBJECT void CGuildMgmtWnd::SetMOTD(char *,char *);
EQLIB_OBJECT void CGuildMgmtWnd::SetPlayerCount(int);
EQLIB_OBJECT void CGuildMgmtWnd::SortList(int,bool);
EQLIB_OBJECT void CGuildMgmtWnd::UpdateButtons(void);
EQLIB_OBJECT void CGuildMgmtWnd::UpdateListMember(class GuildMember *,int);
// virtual
EQLIB_OBJECT CGuildMgmtWnd::~CGuildMgmtWnd(void);
EQLIB_OBJECT int CGuildMgmtWnd::OnProcessFrame(void);
EQLIB_OBJECT int CGuildMgmtWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CGuildMgmtWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CGuildMgmtWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CGuildMgmtWnd::Deactivate(void);
// protected
EQLIB_OBJECT char * CGuildMgmtWnd::GetPersonalNote(char *);
EQLIB_OBJECT int CGuildMgmtWnd::FindListMember(class GuildMember *);
EQLIB_OBJECT void CGuildMgmtWnd::CleanAndRefillListWnd(bool);
EQLIB_OBJECT void CGuildMgmtWnd::CreatePersonalNotesFilename(void);
EQLIB_OBJECT void CGuildMgmtWnd::LoadINI(void);
EQLIB_OBJECT void CGuildMgmtWnd::LoadPersonalNotes(void);
EQLIB_OBJECT void CGuildMgmtWnd::SavePersonalNotes(void);
EQLIB_OBJECT void CGuildMgmtWnd::SetPersonalNote(char *,char *);
// private
EQLIB_OBJECT void CGuildMgmtWnd::Init(void);
};

class ChannelServerApi
{
public:
EQLIB_OBJECT ChannelServerApi::~ChannelServerApi(void);
EQLIB_OBJECT ChannelServerApi::ChannelServerApi(char *,int,char *,char *,class ChannelServerHandler *,bool,bool,char *);
EQLIB_OBJECT char * ChannelServerApi::GetChannelName(int);
//EQLIB_OBJECT enum ChannelServerApi::Status ChannelServerApi::GetStatus(void);
EQLIB_OBJECT int ChannelServerApi::GetChannelCount(void);
EQLIB_OBJECT int ChannelServerApi::GetChannelNumber(char *);
EQLIB_OBJECT static char * __cdecl ChannelServerApi::AllocateString(char *);
EQLIB_OBJECT static char * __cdecl ChannelServerApi::Strncpy(char *,char *,int);
EQLIB_OBJECT static int __cdecl ChannelServerApi::GetNextField(char *,int,char * *,char);
EQLIB_OBJECT static void * __cdecl ChannelServerApi::SmartResize(void *,int,int);
EQLIB_OBJECT void ChannelServerApi::GiveTime(void);
EQLIB_OBJECT void ChannelServerApi::SendMessageA(char *);
// virtual
EQLIB_OBJECT void ChannelServerApi::OnRoutePacket(class UdpConnection *,unsigned char const *,int);
// protected
EQLIB_OBJECT void ChannelServerApi::FreeChannelList(void);
//EQLIB_OBJECT void ChannelServerApi::SetBuddyStatus(char *,enum ChannelServerApi::BuddyStatus);
EQLIB_OBJECT void ChannelServerApi::SortBuddyList(void);
};

class ChannelServerHandler
{
public:
// virtual
EQLIB_OBJECT void ChannelServerHandler::CshOnLoginConfirm(bool);
EQLIB_OBJECT void ChannelServerHandler::CshOnPacket(void *,int,char *,int,char *,bool);
};
struct CKeyUInt32ValueInt32
{
	unsigned __int32 key;
	int value;
};
class CHashCXStrInt32
{
public:
EQLIB_OBJECT CHashCXStrInt32::~CHashCXStrInt32(void);
EQLIB_OBJECT CHashCXStrInt32::CHashCXStrInt32(void);
EQLIB_OBJECT bool CHashCXStrInt32::Insert(class CXStr const &,int);
EQLIB_OBJECT bool CHashCXStrInt32::LookUp(class CXStr const &,int &)const;
EQLIB_OBJECT void CHashCXStrInt32::Reset(void);
// private
EQLIB_OBJECT int CHashCXStrInt32::KeyToBin(class CXStr const &)const;
	ArrayClass2_RO<ArrayClass2_RO<CKeyUInt32ValueInt32>> HashData;
};

class CHelpWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CHelpWnd::CHelpWnd(class CXWnd *);
EQLIB_OBJECT void CHelpWnd::Activate(void);
EQLIB_OBJECT void CHelpWnd::SetFile(class CXStr);
// virtual
EQLIB_OBJECT CHelpWnd::~CHelpWnd(void);
EQLIB_OBJECT int CHelpWnd::HandleKeyboardMsg(unsigned __int32,unsigned __int32,bool);
EQLIB_OBJECT int CHelpWnd::OnProcessFrame(void);
EQLIB_OBJECT int CHelpWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CHelpWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CHelpWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CHelpWnd::Deactivate(void);
// private
EQLIB_OBJECT void CHelpWnd::Init(void);
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
/*0x224*/ void *				pKeyMapText;//CTextObjectInterface
/*0x228*/ int					Unknown0x228;
/*0x22c*/ CButtonWnd *			pButtonWnd;
/*0x230*/ CInvSlotWnd *			pInvSlotWnd;
/*0x234*/ CSpellGemWnd *		pSpellGemWnd;
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
EQLIB_OBJECT CHotButtonWnd::CHotButtonWnd(class CXWnd *);
EQLIB_OBJECT void CHotButtonWnd::Activate(void);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT void CHotButtonWnd::DoHotButton(int Button,int AllowAutoRightClick,int something);
#else
EQLIB_OBJECT void CHotButtonWnd::DoHotButton(int Button,int AllowAutoRightClick);
#endif
EQLIB_OBJECT void CHotButtonWnd::DoHotButtonRightClick(int);
EQLIB_OBJECT void CHotButtonWnd::UpdatePage(void);
// virtual
EQLIB_OBJECT CHotButtonWnd::~CHotButtonWnd(void);
EQLIB_OBJECT int CHotButtonWnd::Draw(void)const;
EQLIB_OBJECT int CHotButtonWnd::OnProcessFrame(void);
EQLIB_OBJECT int CHotButtonWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CHotButtonWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CHotButtonWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CHotButtonWnd::Deactivate(void);
// private
EQLIB_OBJECT void CHotButtonWnd::Init(void);
};

class CIMECandidateList
{
public:
EQLIB_OBJECT CIMECandidateList::~CIMECandidateList(void);
EQLIB_OBJECT CIMECandidateList::CIMECandidateList(class CIMEManager *);
EQLIB_OBJECT int CIMECandidateList::show(class CIMEComposition const *)const;
// private
EQLIB_OBJECT int CIMECandidateList::repositionImeCandidateList(int,int)const;
};

class CIMEComposition
{
public:
EQLIB_OBJECT CIMEComposition::~CIMEComposition(void);
EQLIB_OBJECT CIMEComposition::CIMEComposition(class CIMEManager *);
EQLIB_OBJECT class CXPoint CIMEComposition::getCursorPoint(void)const;
EQLIB_OBJECT class CXRect CIMEComposition::getCompositionArea(void)const;
EQLIB_OBJECT int CIMEComposition::addInputChar(unsigned short);
EQLIB_OBJECT int CIMEComposition::addInputString(class CXStr const &,int);
EQLIB_OBJECT int CIMEComposition::addInputString(unsigned short *,int);
EQLIB_OBJECT int CIMEComposition::addStringFromIme(long);
EQLIB_OBJECT void CIMEComposition::directToEditWnd(class CEditWnd *);
// private
EQLIB_OBJECT int CIMEComposition::addCompositionHighlights(void);
EQLIB_OBJECT int CIMEComposition::applyChineseComposingRules(class CXStr *);
EQLIB_OBJECT int CIMEComposition::applyJapaneseComposingRules(class CXStr *);
EQLIB_OBJECT int CIMEComposition::applyKoreanComposingRules(class CXStr *);
EQLIB_OBJECT int CIMEComposition::getCompositionInsertIndex(void)const;
EQLIB_OBJECT int CIMEComposition::handleImeComposing(void);
EQLIB_OBJECT int CIMEComposition::handleImeResult(void);
EQLIB_OBJECT int CIMEComposition::repositionImeCompositionWindow(int,int)const;
EQLIB_OBJECT struct CompAttr * CIMEComposition::allocateImeCompositionAttributes(void)const;
EQLIB_OBJECT unsigned short * CIMEComposition::allocateImeCompositionString(long)const;
EQLIB_OBJECT void CIMEComposition::backupCurrentText(void);
EQLIB_OBJECT void CIMEComposition::revertToBackupText(void);
};

class CIMEManager
{
public:
EQLIB_OBJECT CIMEManager::~CIMEManager(void);
EQLIB_OBJECT CIMEManager::CIMEManager(struct HWND__ *);
EQLIB_OBJECT bool CIMEManager::imeIsOff(void)const;
EQLIB_OBJECT bool CIMEManager::imeIsOn(void)const;
EQLIB_OBJECT int CIMEManager::getImeProperties(void)const;
EQLIB_OBJECT int CIMEManager::getInputLanguage(void)const;
EQLIB_OBJECT int CIMEManager::getInputState(void)const;
EQLIB_OBJECT int CIMEManager::handleWndProc(unsigned int,unsigned int,long);
EQLIB_OBJECT int CIMEManager::setInputEditWnd(class CEditWnd *);
EQLIB_OBJECT struct HWND__ * CIMEManager::getWindowHandle(void)const;
EQLIB_OBJECT void CIMEManager::setInputState(int);
EQLIB_OBJECT void CIMEManager::turnImeOff(void);
EQLIB_OBJECT void CIMEManager::turnImeOn(void);
// private
EQLIB_OBJECT int CIMEManager::handleAddChar(unsigned short);
EQLIB_OBJECT int CIMEManager::handleChangeCandidates(void);
EQLIB_OBJECT int CIMEManager::handleCloseCandidates(void);
EQLIB_OBJECT int CIMEManager::handleEndComposition(void);
EQLIB_OBJECT int CIMEManager::handleImeChanged(void);
EQLIB_OBJECT int CIMEManager::handleImeStatusChanged(void);
EQLIB_OBJECT int CIMEManager::handleInputComposition(long);
EQLIB_OBJECT int CIMEManager::handleOpenCandidates(void);
EQLIB_OBJECT int CIMEManager::handleStartComposition(void);
EQLIB_OBJECT int CIMEManager::queryImeLanguage(void)const;
EQLIB_OBJECT int CIMEManager::queryImeProperties(void)const;
EQLIB_OBJECT void CIMEManager::enableIme(bool);
};

class CIMEStatusBar
{
public:
EQLIB_OBJECT CIMEStatusBar::CIMEStatusBar(class CIMEManager *);
EQLIB_OBJECT int CIMEStatusBar::hide(void);
EQLIB_OBJECT int CIMEStatusBar::show(class CIMEComposition const *);
EQLIB_OBJECT int CIMEStatusBar::update(void);
// private
EQLIB_OBJECT int CIMEStatusBar::repositionStatusWindow(void);
EQLIB_OBJECT void CIMEStatusBar::handleChineseSimplifiedStatusChange(unsigned long);
EQLIB_OBJECT void CIMEStatusBar::handleChineseTraditionalStatusChange(unsigned long);
EQLIB_OBJECT void CIMEStatusBar::handleJapaneseStatusChange(unsigned long);
EQLIB_OBJECT void CIMEStatusBar::handleKoreanStatusChange(unsigned long);
};

class CInspectWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CInspectWnd::CInspectWnd(class CXWnd *);
EQLIB_OBJECT void CInspectWnd::Activate(struct _inspect *);
EQLIB_OBJECT void CInspectWnd::PlayerBeingDeleted(class EQPlayer *);
// virtual
EQLIB_OBJECT CInspectWnd::~CInspectWnd(void);
EQLIB_OBJECT int CInspectWnd::Draw(void)const;
EQLIB_OBJECT int CInspectWnd::OnProcessFrame(void);
EQLIB_OBJECT int CInspectWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CInspectWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CInspectWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CInspectWnd::Deactivate(void);
// private
EQLIB_OBJECT void CInspectWnd::AcceptInspectText(void);
EQLIB_OBJECT void CInspectWnd::Init(void);
};

class CInventoryWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CInventoryWnd::CInventoryWnd(class CXWnd *);
EQLIB_OBJECT void CInventoryWnd::Activate(void);
// virtual
EQLIB_OBJECT CInventoryWnd::~CInventoryWnd(void);
EQLIB_OBJECT int CInventoryWnd::Draw(void)const;
EQLIB_OBJECT int CInventoryWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CInventoryWnd::OnProcessFrame(void);
EQLIB_OBJECT int CInventoryWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CInventoryWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CInventoryWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CInventoryWnd::Deactivate(void);
// private
EQLIB_OBJECT long CInventoryWnd::GetInventoryQtyFromCoinType(int);
EQLIB_OBJECT void CInventoryWnd::ClickedMoneyButton(int,int);
EQLIB_OBJECT void CInventoryWnd::DestroyHeld(void);
EQLIB_OBJECT void CInventoryWnd::Init(void);
EQLIB_OBJECT void CInventoryWnd::UpdateMoneyDisplay(void);
DWORD         Unknown0x0xx[0x22];
__int64		VitalityCap;
int			AAVitalityCap;
};

class CInvSlot
{
public:
	void *pvftable;
	CInvSlotWnd *pInvSlotWnd;
	CTextureAnimation *pInvSlotAnimation;
	int Index;
	bool bEnabled;
EQLIB_OBJECT CInvSlot::CInvSlot(void);
EQLIB_OBJECT bool CInvSlot::IllegalBigBank(int);
EQLIB_OBJECT void CInvSlot::DoDrinkEatPoison(class EQ_Item *,int);
EQLIB_OBJECT void CInvSlot::HandleLButtonDown(class CXPoint);
EQLIB_OBJECT void CInvSlot::HandleLButtonHeld(class CXPoint);
EQLIB_OBJECT void CInvSlot::HandleLButtonUp(class CXPoint,bool);
EQLIB_OBJECT void CInvSlot::HandleLButtonUpAfterHeld(class CXPoint);
EQLIB_OBJECT void CInvSlot::HandleRButtonDown(class CXPoint);
EQLIB_OBJECT void CInvSlot::HandleRButtonHeld(class CXPoint);
EQLIB_OBJECT void CInvSlot::HandleRButtonUp(class CXPoint *);
EQLIB_OBJECT void CInvSlot::HandleRButtonUpAfterHeld(class CXPoint);
EQLIB_OBJECT void CInvSlot::SetInvSlotWnd(class CInvSlotWnd *);
EQLIB_OBJECT void CInvSlot::SetItem(class EQ_Item *);
EQLIB_OBJECT void CInvSlot::SliderComplete(int);
EQLIB_OBJECT void CInvSlot::GetItemBase(struct _CONTENTS **);
EQLIB_OBJECT void CInvSlot::UpdateItem(void);
// virtual
EQLIB_OBJECT CInvSlot::~CInvSlot(void);
//EQLIB_OBJECT void * CInvSlot::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CInvSlot::`vector deleting destructor'(unsigned int);
};


class CInvSlotMgr
{
public:
EQLIB_OBJECT CInvSlotMgr::CInvSlotMgr(void);
EQLIB_OBJECT class CInvSlot * CInvSlotMgr::CreateInvSlot(class CInvSlotWnd *);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT class CInvSlot * CInvSlotMgr::FindInvSlot(int TopSlot,int SubSlot=-1,int FindWindowRelated = 0,bool bSomething = 1);
#else
EQLIB_OBJECT class CInvSlot * CInvSlotMgr::FindInvSlot(int TopSlot,int SubSlot=-1);
#endif
EQLIB_OBJECT bool CInvSlotMgr::MoveItem(ItemGlobalIndex *from, ItemGlobalIndex *to, bool bDebugOut, bool CombineIsOk, bool MoveFromIntoToBag = false, bool MoveToIntoFromBag = false);
EQLIB_OBJECT void CInvSlotMgr::Process(void);
EQLIB_OBJECT void CInvSlotMgr::SelectSlot(class CInvSlot *);
EQLIB_OBJECT void CInvSlotMgr::UpdateSlots(void);
// virtual
EQLIB_OBJECT CInvSlotMgr::~CInvSlotMgr(void);
//EQLIB_OBJECT void * CInvSlotMgr::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CInvSlotMgr::`vector deleting destructor'(unsigned int);
};

class CInvSlotTemplate
{
public:
EQLIB_OBJECT CInvSlotTemplate::CInvSlotTemplate(class CParamInvSlot *);
// virtual
EQLIB_OBJECT CInvSlotTemplate::~CInvSlotTemplate(void);
//EQLIB_OBJECT void * CInvSlotTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CInvSlotTemplate::`vector deleting destructor'(unsigned int);
};

class CInvSlotWnd
{
public:
/****** CXwnd inherits ******/
	CXW
/****** ButtonWnd inherits ******/
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
	/* CButtonDrawTemplate Start */
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
/****** CInvSlotWnd Start ******/
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
EQLIB_OBJECT CInvSlotWnd::CInvSlotWnd(CXWnd *pParent, unsigned __int32 ID, CXRect rect,	CTextureAnimation *ptaBackground, ItemGlobalIndex *itemLocation, int ItemOffsetX, int ItemOffsetY);
EQLIB_OBJECT void CInvSlotWnd::SetInvSlot(class CInvSlot *);
// virtual
EQLIB_OBJECT CInvSlotWnd::~CInvSlotWnd(void);
EQLIB_OBJECT int CInvSlotWnd::Draw(void)const;
EQLIB_OBJECT int CInvSlotWnd::DrawTooltip(class CXWnd const *)const;
EQLIB_OBJECT int CInvSlotWnd::HandleLButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CInvSlotWnd::HandleLButtonHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CInvSlotWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CInvSlotWnd::HandleLButtonUpAfterHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CInvSlotWnd::HandleRButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CInvSlotWnd::HandleRButtonHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CInvSlotWnd::HandleRButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CInvSlotWnd::HandleRButtonUpAfterHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CInvSlotWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CInvSlotWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CInvSlotWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CInvSlotWnd::SetAttributesFromSidl(class CParamScreenPiece *);
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
/*0x0230*/ CStmlWnd *pDescription;
/*0x0234*/ CStmlWnd *pName;
/*0x0238*/ CButtonWnd *pIconButton;
/*0x023c*/ CStmlWnd *pLore;
/*0x0240*/ CTabWnd *pItemDescriptionTab;
/*0x0244*/ CPageWnd *pDescriptionPage;
/*0x0248*/ CPageWnd *pLorePage;
/*0x024c*/ CSidlScreenWnd *pAppearanceSocketScreen;
/*0x0250*/ CButtonWnd *pAppearanceSocketItem;
/*0x0254*/ CButtonWnd *pAppearanceSocketBuyButton;
/*0x0258*/ CStmlWnd *pAppearanceSocketDescription;
/*0x025c*/ CSidlScreenWnd *pItemSocketScreen[6];
/*0x0274*/ CButtonWnd *pItemSocketItemButton[6];
/*0x028c*/ CStmlWnd *pItemSocketDescription[6];
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
/*0x02d8*/ CLabel *pModButtonLabel;
/*0x02dc*/ CStmlWnd *pConvertButtonStml;
/*0x02e0*/ CLabel *pMadeByLabel;
/*0x02e4*/ CLabel *pCollectedLabel;//for sure
/*0x02e8*/ CLabel *pScribedLabel;
/*0x02ec*/ int Row;
/*0x02f0*/ bool bAntiTwink;
/*0x02f4*/ CButtonWnd *pModButton;
/*0x02f8*/ CButtonWnd *pPrintRealEstateItems;
/*0x02fc*/ CButtonWnd *pConvertButton;
/*0x0300*/ bool bCollected;
/*0x0301*/ bool bReceivedCollectableStatus;
/*0x0304*/ int Group[6];
/*0x031c*/ bool bClickedTwink;
/*0x0320*/ int HeroicCount;
/*0x0324*/ int ItemInfoCount;
/*0x0328*/ CLabel *pItemInfoLabel[13];//for sure at 0x330
/*0x035c*/ CLabel *pStatLabel[0x1a][3];//size 0x138
/*0x0494*/ CLabel *pValueLabel[0x1a][3];//size 0x138
/*0x05cc*/ CLabel *pHeroicLabel[0xd];
/*0x0600*/ int RightClickMenuID;
/*0x0604*/ int RightClickMenuSocketSlot;
/*0x0608*/ int WindowID;
/*0x060c*/

EQLIB_OBJECT CItemDisplayWnd::CItemDisplayWnd(CXWnd *);
EQLIB_OBJECT class CXStr CItemDisplayWnd::CreateEquipmentStatusString(class EQ_Item *);
EQLIB_OBJECT void CItemDisplayWnd::SetItem(PCONTENTS *pCont, int flags);
EQLIB_OBJECT void CItemDisplayWnd::SetItemText(char *);
EQLIB_OBJECT void CItemDisplayWnd::SetSpell(int SpellID,bool HasSpellDescr,int);
EQLIB_OBJECT void CItemDisplayWnd::UpdateStrings(void);
// virtual
EQLIB_OBJECT CItemDisplayWnd::~CItemDisplayWnd();
EQLIB_OBJECT int CItemDisplayWnd::HandleKeyboardMsg(unsigned __int32,unsigned __int32,bool);
EQLIB_OBJECT int CItemDisplayWnd::OnProcessFrame(void);
EQLIB_OBJECT int CItemDisplayWnd::WndNotification(CXWnd *pWnd, unsigned __int32 Message, void *pData);
//EQLIB_OBJECT void * CItemDisplayWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CItemDisplayWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CItemDisplayWnd::Activate(void);
EQLIB_OBJECT void CItemDisplayWnd::Deactivate(void);
// protected
EQLIB_OBJECT class CXStr CItemDisplayWnd::CreateClassString(class EQ_Equipment *);
EQLIB_OBJECT class CXStr CItemDisplayWnd::CreateMealSizeString(class EQ_Equipment *);
EQLIB_OBJECT class CXStr CItemDisplayWnd::CreateModString(class EQ_Equipment *,int,int,int *);
EQLIB_OBJECT class CXStr CItemDisplayWnd::CreateRaceString(class EQ_Equipment *);
EQLIB_OBJECT void CItemDisplayWnd::GetSizeString(int,char *);
EQLIB_OBJECT void CItemDisplayWnd::InsertAugmentRequest(int AugSlot);
EQLIB_OBJECT void CItemDisplayWnd::RemoveAugmentRequest(int AugSlot);
EQLIB_OBJECT bool CItemDisplayWnd::AboutToShow(void);
EQLIB_OBJECT void CItemDisplayWnd::RequestConvertItem(void);
};

class CJournalCatWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CJournalCatWnd::CJournalCatWnd(class CXWnd *);
EQLIB_OBJECT void CJournalCatWnd::Activate(void);
EQLIB_OBJECT void CJournalCatWnd::Clean(void);
EQLIB_OBJECT void CJournalCatWnd::UpdateAll(bool);
EQLIB_OBJECT void CJournalCatWnd::UpdateButtons(void);
// virtual
EQLIB_OBJECT CJournalCatWnd::~CJournalCatWnd(void);
EQLIB_OBJECT int CJournalCatWnd::OnProcessFrame(void);
EQLIB_OBJECT int CJournalCatWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CJournalCatWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CJournalCatWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CJournalCatWnd::Deactivate(void);
// protected
EQLIB_OBJECT void CJournalCatWnd::BuildList(void);
EQLIB_OBJECT void CJournalCatWnd::LoadINI(void);
EQLIB_OBJECT void CJournalCatWnd::SelectCategory(int);
EQLIB_OBJECT void CJournalCatWnd::SortList(int,bool);
EQLIB_OBJECT void CJournalCatWnd::StoreINI(void);
EQLIB_OBJECT void CJournalCatWnd::UpdateListWnd(bool);
// private
EQLIB_OBJECT void CJournalCatWnd::Init(void);
};

class CJournalNPCWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CJournalNPCWnd::CJournalNPCWnd(class CXWnd *);
EQLIB_OBJECT void CJournalNPCWnd::Activate(void);
EQLIB_OBJECT void CJournalNPCWnd::EnterIntoJournal(char *,float,float,float,char *);
EQLIB_OBJECT void CJournalNPCWnd::LoadJournal(int);
EQLIB_OBJECT void CJournalNPCWnd::SaveJournal(void);
EQLIB_OBJECT void CJournalNPCWnd::UpdateAll(bool);
EQLIB_OBJECT void CJournalNPCWnd::UpdateCategories(void);
// virtual
EQLIB_OBJECT CJournalNPCWnd::~CJournalNPCWnd(void);
EQLIB_OBJECT int CJournalNPCWnd::OnProcessFrame(void);
EQLIB_OBJECT int CJournalNPCWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CJournalNPCWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CJournalNPCWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CJournalNPCWnd::Deactivate(void);
// protected
EQLIB_OBJECT void CJournalNPCWnd::BuildList(void);
EQLIB_OBJECT void CJournalNPCWnd::DoBackups(class CXStr);
EQLIB_OBJECT void CJournalNPCWnd::GetLogState(void);
EQLIB_OBJECT void CJournalNPCWnd::SelectNPCIndex(int);
EQLIB_OBJECT void CJournalNPCWnd::SortList(int,bool);
EQLIB_OBJECT void CJournalNPCWnd::StoreLogState(void);
EQLIB_OBJECT void CJournalNPCWnd::UpdateButtons(void);
EQLIB_OBJECT void CJournalNPCWnd::UpdateListWnd(bool);
// private
EQLIB_OBJECT void CJournalNPCWnd::Init(void);
};

class CJournalTextWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CJournalTextWnd::CJournalTextWnd(class CXWnd *);
EQLIB_OBJECT void CJournalTextWnd::Activate(void);
EQLIB_OBJECT void CJournalTextWnd::Clear(void);
EQLIB_OBJECT void CJournalTextWnd::DisplayNPC(class JournalNPC *);
EQLIB_OBJECT void CJournalTextWnd::SetSearch(class CXStr);
EQLIB_OBJECT void CJournalTextWnd::UpdateAll(bool);
EQLIB_OBJECT void CJournalTextWnd::UpdateCategories(void);
// virtual
EQLIB_OBJECT CJournalTextWnd::~CJournalTextWnd(void);
EQLIB_OBJECT int CJournalTextWnd::OnProcessFrame(void);
EQLIB_OBJECT int CJournalTextWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CJournalTextWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CJournalTextWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CJournalTextWnd::Deactivate(void);
// protected
EQLIB_OBJECT void CJournalTextWnd::BuildList(void);
EQLIB_OBJECT void CJournalTextWnd::SelectEntryIndex(int);
EQLIB_OBJECT void CJournalTextWnd::SortList(int,bool);
EQLIB_OBJECT void CJournalTextWnd::UpdateButtons(void);
EQLIB_OBJECT void CJournalTextWnd::UpdateListWnd(bool);
};

class CKeyCXStrValueInt32
{
public:
EQLIB_OBJECT CKeyCXStrValueInt32::~CKeyCXStrValueInt32(void);
EQLIB_OBJECT CKeyCXStrValueInt32::CKeyCXStrValueInt32(void);
//EQLIB_OBJECT void * CKeyCXStrValueInt32::`vector deleting destructor'(unsigned int);
};

//CLabelWnd__CLabelWnd_x
//size 0x200 see 8D5699 in Aug 10 2017 Live -eqmule
//size 0x210 see 8DCE59 in Sep 11 2017 Test -eqmule
//size 0x200 see 668D5B in Oct 17 2017 Live -eqmule
//size 0x1e4 see 86BFC9 in rof2 -eqmule
class CLabelWnd// : public CXWnd
{
public:
EQLIB_OBJECT CLabelWnd::CLabelWnd(CXWnd *pParent, unsigned __int32 ID, const CXRect *rect);
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
//size is 0x208 see 79C989 in Aug 10 2017 Live -eqmule
//size is 0x218 see 7A3819 in Sep 11 2017 Test -eqmule
//size 0x208 see 7A5739 in Oct 17 2017 Live -eqmule
//size 0x1e8 see 755709 in Rof2 -eqmule
class CLabel : public CLabelWnd
{
public:								//rof2
/*0x200*/ int EQType;				/*0x1e4*/
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x204*/ int Unknown0x204;
#endif
/*0x208*/							/*0x1e8*/
EQLIB_OBJECT CLabel::CLabel(class CXWnd *pParent,unsigned __int32 id,CXRect *rect,int eqtype = 0);
EQLIB_OBJECT void CLabel::SetAlignCenter(bool);
EQLIB_OBJECT void CLabel::SetAlignRight(bool);
EQLIB_OBJECT void CLabel::SetNoWrap(bool);
// virtual
EQLIB_OBJECT CLabel::~CLabel(void);
EQLIB_OBJECT int CLabel::Draw(void)const;
//EQLIB_OBJECT void * CLabel::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CLabel::`vector deleting destructor'(unsigned int);
};

class CLabelTemplate
{
public:
EQLIB_OBJECT CLabelTemplate::CLabelTemplate(class CParamLabel *);
// virtual
EQLIB_OBJECT CLabelTemplate::~CLabelTemplate(void);
//EQLIB_OBJECT void * CLabelTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CLabelTemplate::`vector deleting destructor'(unsigned int);
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
EQLIB_OBJECT int CItemDisplayManager::CreateWindowInstance(void);
};

class CLineBase
{
public:
EQLIB_OBJECT CLineBase::~CLineBase(void);
EQLIB_OBJECT CLineBase::CLineBase(void);
};

class CListboxColumnTemplate
{
public:
EQLIB_OBJECT CListboxColumnTemplate::~CListboxColumnTemplate(void);
EQLIB_OBJECT CListboxColumnTemplate::CListboxColumnTemplate(class CParamListboxColumn *);
//EQLIB_OBJECT void CListboxColumnTemplate::`default constructor closure'(void);
};

class CListboxTemplate
{
public:
EQLIB_OBJECT CListboxTemplate::CListboxTemplate(class CParamListbox *);
// virtual
EQLIB_OBJECT CListboxTemplate::~CListboxTemplate(void);
//EQLIB_OBJECT void * CListboxTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CListboxTemplate::`vector deleting destructor'(unsigned int);
};

class CUITextureInfo
{
public:
EQLIB_OBJECT CUITextureInfo::~CUITextureInfo(void);
EQLIB_OBJECT CUITextureInfo::CUITextureInfo(class CXStr,class CXSize);
EQLIB_OBJECT CUITextureInfo::CUITextureInfo(class CXStr,int);
EQLIB_OBJECT CUITextureInfo::CUITextureInfo(class CUITextureInfo const &);
EQLIB_OBJECT CUITextureInfo::CUITextureInfo(unsigned __int32,int);
EQLIB_OBJECT CUITextureInfo::CUITextureInfo(void);
EQLIB_OBJECT class CXStr CUITextureInfo::GetName(void)const;
EQLIB_OBJECT int CUITextureInfo::Draw(class CXRect,class CXRect,class CXRect,unsigned long *,unsigned long *)const;
EQLIB_OBJECT int CUITextureInfo::Draw(class CXRect,class CXRect,class CXRect,unsigned long,unsigned long)const;
EQLIB_OBJECT int CUITextureInfo::Preload(void);
EQLIB_OBJECT int CUITextureInfo::Tile(class CXRect,unsigned long *,unsigned long *)const;
EQLIB_OBJECT int CUITextureInfo::Tile(class CXRect,unsigned long,unsigned long)const;
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
    const CTextureAnimation *pTA;
    struct _CXSTR *Text;
    COLORREF Color;
	bool bOnlyDrawTexture;
	CXWnd *pWnd;
};
struct SListWndCell_RO
{
    CTextureAnimation *pTA;
    struct _CXSTR *Text;
    COLORREF Color;
	bool bOnlyDrawTexture;
	CXWnd *pWnd;
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
	unsigned __int64	Data;
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
/*0x10*/ unsigned __int64	Data;
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
/*0x20*/    unsigned __int64	Data;
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
	SListWndColumn(PCXSTR strLabel = 0, int width = 0, CTextureAnimation *pta = NULL, UINT flags = 0,
		UINT type = 0x03, CTextureAnimation *pselected = NULL, CTextureAnimation *pmouseOver = NULL,
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
/*0x20*/    unsigned __int64	Data;
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
//while list->ItemsArray.m_array[0].Cells.m_array[0] might not -eqmule
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

EQLIB_OBJECT CListWnd::CListWnd(class CXWnd *,unsigned __int32,class CXRect const &);
EQLIB_OBJECT CListWnd::CListWnd() {};
EQLIB_OBJECT bool CListWnd::IsLineEnabled(int)const;
EQLIB_OBJECT class CTextureAnimation const * CListWnd::GetColumnAnimation(int)const;
EQLIB_OBJECT class CTextureAnimation const * CListWnd::GetColumnAnimationMouseOver(int)const;
EQLIB_OBJECT class CTextureAnimation const * CListWnd::GetColumnAnimationSelected(int)const;
EQLIB_OBJECT class CTextureAnimation const * CListWnd::GetItemIcon(int,int)const;
EQLIB_OBJECT class CXRect CListWnd::GetHeaderRect(int)const;
//CListWnd::GetItemRect looks like it has 3 args in ida but one of them is PUSH ESI so that doesnt count...
//checked on apr 29 2016 by eqmule (it has 2)
EQLIB_OBJECT class CXRect CListWnd::GetItemRect(int,int)const;
EQLIB_OBJECT class CXRect CListWnd::GetSeparatorRect(int)const;
EQLIB_OBJECT class CXStr CListWnd::GetColumnLabel(int)const;
EQLIB_OBJECT class CXStr *CListWnd::GetItemText(class CXStr *,int,int)const;
EQLIB_OBJECT int CListWnd::AddColumn(const CXStr *Label, CTextureAnimation*pTA, int Width, unsigned __int32 Flags, CXStr Tooltip = "", unsigned __int32 Type = 3, CTextureAnimation *pTASelected = 0, CTextureAnimation *pTAMouseOver = 0, bool bResizeable = false, tagSIZE TextureSize = { 0,0 }, tagPOINT TextureOffset = { 0,0 });
EQLIB_OBJECT int CListWnd::AddColumn(const CXStr *Label,int Width,unsigned __int32 Flags,unsigned __int32 Type = 3/*text/icon type*/);
EQLIB_OBJECT int CListWnd::AddLine(SListWndLine *);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT int CListWnd::AddString(CXStr *str, COLORREF cref, unsigned __int32 data = 0, CTextureAnimation *pta = NULL, char* tooltipstr = NULL, bool bDebug = false);
#else
EQLIB_OBJECT int CListWnd::AddString(CXStr *,unsigned long,unsigned __int32,class CTextureAnimation const *, const char* p5 = 0);
#endif
EQLIB_OBJECT int CListWnd::AddString(char *,unsigned long,unsigned __int32,CTextureAnimation *, const char* p5 = 0);
EQLIB_OBJECT int CListWnd::GetColumnJustification(int)const;
EQLIB_OBJECT int CListWnd::GetColumnMinWidth(int) const;
EQLIB_OBJECT CXStr CListWnd::GetColumnTooltip(int) const;
EQLIB_OBJECT int CListWnd::GetColumnWidth(int)const;
EQLIB_OBJECT int CListWnd::GetCurCol(void)const;
EQLIB_OBJECT int CListWnd::GetCurSel(void)const;
EQLIB_OBJECT int CListWnd::GetItemAtPoint(POINT *pt)const;
EQLIB_OBJECT int CListWnd::GetItemHeight(int)const;
EQLIB_OBJECT unsigned __int32 CListWnd::GetColumnFlags(int)const;
EQLIB_OBJECT unsigned __int32 CListWnd::GetItemData(int)const;
EQLIB_OBJECT unsigned long CListWnd::GetItemColor(int,int)const;
EQLIB_OBJECT void CListWnd::CalculateFirstVisibleLine(void);
EQLIB_OBJECT void CListWnd::CalculateLineHeights(void);
EQLIB_OBJECT void CListWnd::CalculateVSBRange(void);
EQLIB_OBJECT void CListWnd::ClearAllSel(void);
EQLIB_OBJECT void CListWnd::ClearSel(int);
EQLIB_OBJECT void CListWnd::CloseAndUpdateEditWindow(void);
EQLIB_OBJECT void CListWnd::EnableLine(int Index, bool bVal);
EQLIB_OBJECT void CListWnd::EnsureVisible(int);
EQLIB_OBJECT void CListWnd::ExtendSel(int);
EQLIB_OBJECT void CListWnd::GetItemAtPoint(CXPoint *pt,int *ID,int *SubItem)const;
EQLIB_OBJECT void CListWnd::InsertLine(int ID, SListWndLine *rEntry);
EQLIB_OBJECT void CListWnd::RemoveLine(int);
EQLIB_OBJECT void CListWnd::RemoveString(int);
EQLIB_OBJECT void CListWnd::SetColors(unsigned long,unsigned long,unsigned long);
EQLIB_OBJECT void CListWnd::SetColumnJustification(int,int);
EQLIB_OBJECT void CListWnd::SetColumnLabel(int,class CXStr);
EQLIB_OBJECT void CListWnd::SetColumnWidth(int,int);
EQLIB_OBJECT void CListWnd::SetCurSel(int);
EQLIB_OBJECT void CListWnd::SetItemColor(int,int,unsigned long);
#if !defined(ROF2EMU) && !defined(UFEMU) 
EQLIB_OBJECT void CListWnd::SetItemData(int ID,unsigned __int32 Data, BOOL bSomething = false);
#else
EQLIB_OBJECT void CListWnd::SetItemData(int ID, unsigned __int32 Data);
#endif
EQLIB_OBJECT void CListWnd::SetItemText(int ID,int SubID,class CXStr *Text);
EQLIB_OBJECT void CListWnd::ShiftColumnSeparator(int,int);
EQLIB_OBJECT void CListWnd::ToggleSel(int);
// virtual
EQLIB_OBJECT CListWnd::~CListWnd(void);
EQLIB_OBJECT class CTextureAnimation * CListWnd::GetCursorToDisplay(void)const;
EQLIB_OBJECT int CListWnd::Compare(SListWndLine const &,SListWndLine const &)const;
EQLIB_OBJECT int CListWnd::Draw(void)const;
EQLIB_OBJECT int CListWnd::DrawBackground(void)const;
EQLIB_OBJECT int CListWnd::DrawColumnSeparators(void)const;
EQLIB_OBJECT int CListWnd::DrawHeader(void)const;
EQLIB_OBJECT int CListWnd::DrawItem(int,int,int)const;
EQLIB_OBJECT int CListWnd::DrawLine(int)const;
EQLIB_OBJECT int CListWnd::DrawSeparator(int)const;
EQLIB_OBJECT int CListWnd::HandleLButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CListWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CListWnd::HandleLButtonUpAfterHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CListWnd::HandleMouseMove(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CListWnd::HandleRButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CListWnd::OnHeaderClick(class CXPoint);
EQLIB_OBJECT int CListWnd::OnMove(class CXRect);
EQLIB_OBJECT int CListWnd::OnResize(int,int);
EQLIB_OBJECT int CListWnd::OnVScroll(EScrollCode,int);
EQLIB_OBJECT int CListWnd::SetVScrollPos(int);
EQLIB_OBJECT int CListWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CListWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CListWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CListWnd::DeleteAll(void);
EQLIB_OBJECT void CListWnd::Sort(void);
EQLIB_OBJECT void CListWnd::SetColumnsSizable(bool bColumnsSizable);
EQLIB_OBJECT void CListWnd::GetWndPosition(CXWnd *pWnd, int &ItemID, int &SubItemID)const;
EQLIB_OBJECT void CListWnd::SetItemWnd(int Index, int SubItem, CXWnd *pWnd);
EQLIB_OBJECT CXWnd *CListWnd::GetItemWnd(int Index, int SubItem) const;
EQLIB_OBJECT void CListWnd::SetItemIcon(int Index, int SubItem, const CTextureAnimation *pTA);
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
EQLIB_OBJECT int CContextMenu::InsertMenuItemA(CXStr *str,unsigned int position, unsigned int ItemID, bool bChecked, COLORREF Color, bool bEnable);
EQLIB_OBJECT CContextMenu::CContextMenu(CXWnd *pParent, unsigned __int32 MenuID, const CXRect& rect);
EQLIB_OBJECT CContextMenu::CContextMenu(CXWnd *,unsigned __int32,tagRECT *);
EQLIB_OBJECT int CContextMenu::AddMenuItem(CXStr const &str,unsigned int MenuID/*Set HighPart as the ID for submenus and LowPart is then the subindex*/,bool bChecked = false,COLORREF Color = 0xFFFFFFFF,bool bEnable = true);
EQLIB_OBJECT int CContextMenu::AddSeparator(void);
EQLIB_OBJECT void CContextMenu::Activate(class CXPoint,int,int);
EQLIB_OBJECT void CContextMenu::CheckMenuItem(int ID, bool bVal = true, bool bUncheckAll = false);
EQLIB_OBJECT void CContextMenu::EnableMenuItem(int ID, bool bVal = true);
EQLIB_OBJECT void CContextMenu::RemoveAllMenuItems(void);
EQLIB_OBJECT void CContextMenu::RemoveMenuItem(int id);
EQLIB_OBJECT void CContextMenu::SetMenuItem(int ID, const CXStr &Str, bool bChecked = false, COLORREF Color = 0xFFFFFFFF, bool bEnable = true);
// virtual
EQLIB_OBJECT CContextMenu::~CContextMenu(void);
EQLIB_OBJECT CContextMenu::CContextMenu() {
	Sleep(0);
};
EQLIB_OBJECT int CContextMenu::OnKillFocus(class CXWnd *);
//EQLIB_OBJECT void * CContextMenu::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CContextMenu::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CContextMenu::Deactivate(void);
};

class CLoadskinWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CLoadskinWnd::CLoadskinWnd(class CXWnd *);
EQLIB_OBJECT void CLoadskinWnd::Activate(void);
EQLIB_OBJECT void CLoadskinWnd::UpdateSkinList(void);
// virtual
EQLIB_OBJECT CLoadskinWnd::~CLoadskinWnd(void);
EQLIB_OBJECT int CLoadskinWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CLoadskinWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CLoadskinWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CLoadskinWnd::Deactivate(void);
};

class CLootWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CLootWnd::CLootWnd(class CXWnd *);
EQLIB_OBJECT void CLootWnd::Activate(unsigned char,long,long,long,long);
EQLIB_OBJECT void CLootWnd::AddContainerToLootArray(class EQ_Item *);
EQLIB_OBJECT void CLootWnd::AddEquipmentToLootArray(class EQ_Item *);
EQLIB_OBJECT void CLootWnd::AddNoteToLootArray(class EQ_Item *);
EQLIB_OBJECT void CLootWnd::Deactivate(bool);
EQLIB_OBJECT void CLootWnd::LootAll(bool);
EQLIB_OBJECT void CLootWnd::RequestLootSlot(int Slot,bool bAutoInventory);
EQLIB_OBJECT void CLootWnd::SlotLooted(int);
// virtual
EQLIB_OBJECT CLootWnd::~CLootWnd(void);
EQLIB_OBJECT int CLootWnd::OnProcessFrame(void);
EQLIB_OBJECT int CLootWnd::PostDraw(void)const;
EQLIB_OBJECT int CLootWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CLootWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CLootWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CLootWnd::Deactivate(void);
// private
EQLIB_OBJECT void CLootWnd::FinalizeLoot(void);
EQLIB_OBJECT void CLootWnd::Init(void);
/*0x208*/ BYTE Unknown0x1b8[0xd1];   // should be 2d9 on 2012/01/11
/*0x2d9*/ BYTE bLootAll;
/*0x2da*/
};

class CMapToolbarWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CMapToolbarWnd::CMapToolbarWnd(class CXWnd *);
EQLIB_OBJECT void CMapToolbarWnd::Activate(void);
EQLIB_OBJECT void CMapToolbarWnd::SetAutoMapButton(bool);
// virtual
EQLIB_OBJECT CMapToolbarWnd::~CMapToolbarWnd(void);
EQLIB_OBJECT int CMapToolbarWnd::OnProcessFrame(void);
EQLIB_OBJECT int CMapToolbarWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CMapToolbarWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CMapToolbarWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CMapToolbarWnd::Deactivate(void);
};
//class CMapViewWnd : public CSidlScreenWnd, public WndEventHandler
class CMapViewWnd
{
public:
/*0x000*/ struct _CSIDLWNDVFTABLE* pvfTable; \
	CXW_NO_VTABLE
	SIDL

EQLIB_OBJECT CMapViewWnd::CMapViewWnd(class CXWnd *);
EQLIB_OBJECT bool CMapViewWnd::IsMappingEnabled(void);
EQLIB_OBJECT void CMapViewWnd::Activate(void);
EQLIB_OBJECT void CMapViewWnd::ActivateAutoMapping(void);
EQLIB_OBJECT void CMapViewWnd::DeactivateAutoMapping(void);
//EQLIB_OBJECT void CMapViewWnd::SetCurrentZone(EQZoneIndex,struct T3D_XYZ *,struct T3D_XYZ *);
// virtual
EQLIB_OBJECT CMapViewWnd::~CMapViewWnd(void);
EQLIB_OBJECT int CMapViewWnd::HandleLButtonDown(class CXPoint&,unsigned __int32);
EQLIB_OBJECT int CMapViewWnd::HandleLButtonHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CMapViewWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CMapViewWnd::HandleLButtonUpAfterHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CMapViewWnd::HandleWheelMove(class CXPoint,int,unsigned __int32);
EQLIB_OBJECT int CMapViewWnd::OnProcessFrame(void);
EQLIB_OBJECT int CMapViewWnd::PostDraw(void)const;
EQLIB_OBJECT int CMapViewWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CMapViewWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CMapViewWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CMapViewWnd::Deactivate(void);
EQLIB_OBJECT void CMapViewWnd::LoadIniInfo(void);
EQLIB_OBJECT void CMapViewWnd::StoreIniInfo(void);
EQLIB_OBJECT void CMapViewWnd::GetWorldCoordinates(float*);
// private
EQLIB_OBJECT void CMapViewWnd::Init(void);
};

class CMemoryStream
{
public:
EQLIB_OBJECT class CXStr CMemoryStream::GetString(void);
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
} POINTMERCHANTITEM, *PPOINTMERCHANTITEM;
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
	CLabel *MerchantNameLabel;
	CListWnd *ItemList;
	CListWnd *PointList;
	CButtonWnd *EquipButton;
	CButtonWnd *PurchaseButton;
	CButtonWnd *SellButton;
	CButtonWnd *DoneButton;
	CLabel *PointsAvailableValue;
	CLabel *PointsEverEarnedLabel;
	CLabel *PointsAvailableLabel;
	UINT NextRefreshTime;
	PSPAWNINFO ActiveMerchant;
	PPOINTMERCHANTITEM *Items;
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
	void *pHandler;//PointMerchantInterface*
};

class VeBaseReferenceCount
{
public:
	//just couting the vftable here, dont get confused -eqmule
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
	/*0x08*/ CMerchantWnd *pParent;
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
/*0x18*/ virtual void DestroyItemByUniqueId(__int64 UniqueID);
/*0x1c*/ virtual void DestroyItemByItemGuid(const EqItemGuid& ItemGuid);
/*0x20*/ virtual bool AddItemToArray(const VePointer<CONTENTS>& pSentItem);
/*0x24*/ virtual int Sort(SListWndSortInfo *SortInfo);
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
	EQLIB_OBJECT bool CMerchantWnd::PurchasePageHandler::RequestGetItem(int);
	EQLIB_OBJECT void CMerchantWnd::PurchasePageHandler::RequestPutItem(int);
	};
//size 0x420 in Nov 02 2017 Beta  -eqmule
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
/*0x2b0*/ CEditWnd    *SearchEdit;//0x2b0 for sure
/*0x2b4*/ CButtonWnd  *SearchButton;
/*0x2b8*/ CLabel *MerchantNameLabel;
/*0x2bc*/ CLabel *SelectedItemLabel;
/*0x2c0*/ CLabel *SelectedPriceLabel;
/*0x2c4*/ CButtonWnd  *InspectButton;
/*0x2c8*/ CButtonWnd  *PreviewButton;
/*0x2cc*/ CButtonWnd  *SelectedItemButton;
/*0x2d0*/ CButtonWnd  *BuyButton;
/*0x2d4*/ CButtonWnd  *BuyMarketPlaceButton;
/*0x2d8*/ CButtonWnd  *SellButton;
/*0x2dc*/ CButtonWnd	*RecoverButton;
/*0x2e0*/ CButtonWnd	*RetrieveButton;
/*0x2e4*/ CButtonWnd	*RetrieveAllButton;
/*0x2e8*/ CButtonWnd	*SendButton;
/*0x2ec*/ CButtonWnd	*AdventureButton;
/*0x2f0*/ CLabel		*SendToLabel;
/*0x2f4*/ CEditWnd	*SendToEdit;
/*0x2f8*/ CLabel      *NoteLabel;
/*0x2fc*/ CEditWnd    *NoteEdit;
/*0x300*/ CButtonWnd	*ClearNoteButton;
/*0x304*/ CListWnd	*ItemsList;//at 0x304 for sure! see 742D04 Nov 03 2017 Beta -eqmule
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
	/*0x08*/ CMerchantWnd *pParent;
	/*0x0c*/ ItemBaseContainer ItemContainer;//size 0x1c
	/*0x28*/ int MaxItems;
	/*0x2c*/ int LastIndex;
	/*0x30*/ CListWnd* ItemsList;
	/*0x34*/ CPageWnd* Page;
	/*0x38*/ bool bListNeedsRefresh;
	/*0x3c*/ 
/*0x0c*/ virtual void Unknownv0x10();
/*0x10*/ virtual void Unknownv0x14();
/*0x14*/ virtual void DestroyItemByUniqueId(__int64 UniqueID);
/*0x18*/ virtual void DestroyItemByItemGuid(const EqItemGuid& ItemGuid);
/*0x1c*/ virtual bool AddItemToArray(const VePointer<CONTENTS>& pSentItem);
/*0x20*/ virtual int Sort(SListWndSortInfo *SortInfo);
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
	EQLIB_OBJECT bool CMerchantWnd::PurchasePageHandler::RequestGetItem(int);
	EQLIB_OBJECT void CMerchantWnd::PurchasePageHandler::RequestPutItem(int);
	};
/*0x228*/ UINT NextRefreshTime;
/*0x22c*/ bool bInventoryWasActive;
/*0x238*/ VeArray<VePointer<MerchantPageHandler>> PageHandlers;
/*0x244*/ float MerchantGreed;
/*0x248*/ ItemGlobalIndex ItemLocation;
/*0x258*/ VePointer<CONTENTS>pSelectedItem;
/*0x25c*/ __time32_t MailExpireTime;
/*0x260*/ bool bAutoRetrieveingMail;
/*0x264*/ CLabel *plabelMerchantName;
	CLabel *plabelSelectedItem;
	CLabel *plabelSelectedPrice;
	CButtonWnd  *InspectButton;
	CButtonWnd  *PreviewButton;
    CButtonWnd  *SelectedItemLabel;
    CButtonWnd  *BuyButton;
    CButtonWnd  *SellButton;
/*0x2dc*/ CButtonWnd	*RecoverButton;
/*0x2e0*/ CButtonWnd	*RetrieveButton;
/*0x2e4*/ CButtonWnd	*RetrieveAllButton;
/*0x2e8*/ CButtonWnd	*SendButton;
/*0x2f0*/ CLabel	*SendToLabel;
/*0x2f4*/ CEditWnd	*SendToEdit;
/*0x2f8*/ CLabel      *NoteLabel;
/*0x2fc*/ CEditWnd    *NoteEdit;
/*0x300*/ CButtonWnd	*ClearNoteButton;
/*0x304*/ CListWnd	*ItemsList;//at 0x304 for sure! see 742D04 Nov 03 2017 Beta -eqmule
/*0x308*/ CListWnd	*ItemsRecoveryList;
/*0x30c*/ CListWnd	*ItemsMailList;
/*0x310*/ CButtonWnd	*DoneButton;
/*0x314*/ CPageWnd	*PurchasePage;
/*0x318*/ CPageWnd	*RecoveryPage;
/*0x31c*/ CPageWnd	*MailPage;
/*0x320*/ CTabWnd	*TabWindow;
/*0x324*/ CButtonWnd	*UsableButton;
#endif

EQLIB_OBJECT CMerchantWnd::CMerchantWnd(class CXWnd *);
EQLIB_OBJECT void CMerchantWnd::Activate(class EQPlayer *,float);
EQLIB_OBJECT void CMerchantWnd::AddContainerToMercArray(class EQ_Container *);
EQLIB_OBJECT void CMerchantWnd::AddEquipmentToMercArray(class EQ_Equipment *);
EQLIB_OBJECT void CMerchantWnd::AddNoteToMercArray(class EQ_Note *);
EQLIB_OBJECT void CMerchantWnd::ClearMerchantSlot(int);
EQLIB_OBJECT void CMerchantWnd::FinishBuyingItem(struct _sell_msg *);
EQLIB_OBJECT void CMerchantWnd::FinishSellingItem(struct _sell_msg *);
//older clients and im not really sure that it was correct then
//EQLIB_OBJECT void CMerchantWnd::SelectBuySellSlot(int,class CTextureAnimation *);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT int CMerchantWnd::SelectBuySellSlot(ItemGlobalIndex *,int ListIndex = -1);//for itemlists such as merchant items, we also need to send the actual listindex.
#else
EQLIB_OBJECT int CMerchantWnd::SelectBuySellSlot(ItemGlobalIndex *);
#endif
// virtual
EQLIB_OBJECT CMerchantWnd::~CMerchantWnd(void);
EQLIB_OBJECT int CMerchantWnd::OnProcessFrame(void);
EQLIB_OBJECT int CMerchantWnd::PostDraw(void)const;
EQLIB_OBJECT int CMerchantWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CMerchantWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CMerchantWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CMerchantWnd::Deactivate(void);
// private
EQLIB_OBJECT void CMerchantWnd::DisplayBuyOrSellPrice(bool,class EQ_Item *);
EQLIB_OBJECT void CMerchantWnd::HandleBuy(int);
EQLIB_OBJECT void CMerchantWnd::HandleSell(int);
EQLIB_OBJECT void CMerchantWnd::Init(void);
EQLIB_OBJECT void CMerchantWnd::UpdateBuySellButtons(void);
};

class CMusicPlayerWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CMusicPlayerWnd::CMusicPlayerWnd(class CXWnd *);
EQLIB_OBJECT void CMusicPlayerWnd::Activate(void);
EQLIB_OBJECT void CMusicPlayerWnd::AutoStart(void);
// virtual
EQLIB_OBJECT CMusicPlayerWnd::~CMusicPlayerWnd(void);
EQLIB_OBJECT int CMusicPlayerWnd::Draw(void)const;
EQLIB_OBJECT int CMusicPlayerWnd::OnProcessFrame(void);
EQLIB_OBJECT int CMusicPlayerWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CMusicPlayerWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CMusicPlayerWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CMusicPlayerWnd::Deactivate(void);
EQLIB_OBJECT void CMusicPlayerWnd::LoadIniInfo(void);
EQLIB_OBJECT void CMusicPlayerWnd::StoreIniInfo(void);
// protected
EQLIB_OBJECT void CMusicPlayerWnd::Update(void);
EQLIB_OBJECT void CMusicPlayerWnd::UpdateButtons(void);
// private
EQLIB_OBJECT void CMusicPlayerWnd::Init(void);
};

class CMutexLock
{
public:
EQLIB_OBJECT CMutexLock::~CMutexLock(void);
};

class CMutexLockCounted
{
public:
EQLIB_OBJECT CMutexLockCounted::~CMutexLockCounted(void);
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
EQLIB_OBJECT CMutexSyncCounted::~CMutexSyncCounted(void);
EQLIB_OBJECT CMutexSyncCounted::CMutexSyncCounted(void);
};

class CNoteWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CNoteWnd::CNoteWnd(class CXWnd *);
EQLIB_OBJECT bool CNoteWnd::CheckNote(class EQ_Note *);
EQLIB_OBJECT void CNoteWnd::Activate(void);
EQLIB_OBJECT void CNoteWnd::SetNote(char *);
// virtual
EQLIB_OBJECT CNoteWnd::~CNoteWnd(void);
EQLIB_OBJECT int CNoteWnd::HandleKeyboardMsg(unsigned __int32,unsigned __int32,bool);
EQLIB_OBJECT int CNoteWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CNoteWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CNoteWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CNoteWnd::Deactivate(void);
// private
EQLIB_OBJECT void CNoteWnd::Init(void);
};

class ConversationJournal
{
public:
EQLIB_OBJECT ConversationJournal::~ConversationJournal(void);
EQLIB_OBJECT ConversationJournal::ConversationJournal(void);
EQLIB_OBJECT class JournalNPC * ConversationJournal::FindNPCByNameZone(char *,int);
EQLIB_OBJECT class JournalNPC * ConversationJournal::GetNPC(int);
EQLIB_OBJECT int ConversationJournal::AddEntry(char *,int,long,float,float,float,char *,int);
EQLIB_OBJECT int ConversationJournal::DeleteNPC(char *,int);
EQLIB_OBJECT int ConversationJournal::Load(char *);
EQLIB_OBJECT int ConversationJournal::Save(char *);
EQLIB_OBJECT struct JournalCategory * * ConversationJournal::GetCategoryList(void);
EQLIB_OBJECT struct JournalCategory * ConversationJournal::AddCategory(char *,char *,int);
EQLIB_OBJECT struct JournalCategory * ConversationJournal::AddCategory(int);
EQLIB_OBJECT struct JournalCategory * ConversationJournal::GetCategory(char *);
EQLIB_OBJECT struct JournalCategory * ConversationJournal::GetCategory(int);
EQLIB_OBJECT void ConversationJournal::Clean(void);
EQLIB_OBJECT void ConversationJournal::DeleteCategory(int);
// protected
EQLIB_OBJECT int ConversationJournal::FindFreeID(void);
// private
EQLIB_OBJECT class JournalNPC * ConversationJournal::AddNPC(char *,int);
EQLIB_OBJECT class JournalNPC * ConversationJournal::ReadNPC(struct _iobuf *);
EQLIB_OBJECT void ConversationJournal::AllocateCatArray(void);
EQLIB_OBJECT void ConversationJournal::AllocateNPCArray(void);
EQLIB_OBJECT void ConversationJournal::ReadCategory(struct _iobuf *);
};

class COptionsWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT COptionsWnd::COptionsWnd(class CXWnd *);
//EQLIB_OBJECT COptionsWnd::KeyboardAssignmentData::~KeyboardAssignmentData(void);
//EQLIB_OBJECT COptionsWnd::KeyboardAssignmentData::KeyboardAssignmentData(void);
EQLIB_OBJECT void COptionsWnd::Activate(void);
EQLIB_OBJECT void COptionsWnd::RefreshCurrentKeyboardAssignmentList(void);
EQLIB_OBJECT void COptionsWnd::ResetKeysToDefault(void);
EQLIB_OBJECT void COptionsWnd::RestoreDefaultColors(void);
// virtual
EQLIB_OBJECT COptionsWnd::~COptionsWnd(void);
EQLIB_OBJECT int COptionsWnd::HandleKeyboardMsg(unsigned __int32,unsigned __int32,bool);
EQLIB_OBJECT int COptionsWnd::OnProcessFrame(void);
EQLIB_OBJECT int COptionsWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * COptionsWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * COptionsWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void COptionsWnd::Deactivate(void);
// private
EQLIB_OBJECT int COptionsWnd::ChatPageOnProcessFrame(void);
EQLIB_OBJECT int COptionsWnd::ChatPageWndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int COptionsWnd::ColorPageOnProcessFrame(void);
EQLIB_OBJECT int COptionsWnd::ColorPageWndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int COptionsWnd::DisplayPageOnProcessFrame(void);
EQLIB_OBJECT int COptionsWnd::DisplayPageWndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int COptionsWnd::GeneralPageOnProcessFrame(void);
EQLIB_OBJECT int COptionsWnd::GeneralPageWndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int COptionsWnd::KeyboardPageDeactivate(void);
EQLIB_OBJECT int COptionsWnd::KeyboardPageHandleKeyboardMsg(unsigned __int32,unsigned __int32,bool);
EQLIB_OBJECT int COptionsWnd::KeyboardPageOnProcessFrame(void);
EQLIB_OBJECT int COptionsWnd::KeyboardPageWndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int COptionsWnd::MousePageOnProcessFrame(void);
EQLIB_OBJECT int COptionsWnd::MousePageWndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int COptionsWnd::RedirectDeactivateTo(class CPageWnd *);
EQLIB_OBJECT int COptionsWnd::RedirectHandleKeyboardMsgTo(class CPageWnd *,unsigned __int32,unsigned __int32,bool);
EQLIB_OBJECT int COptionsWnd::RedirectOnProcessFrameTo(class CPageWnd *);
EQLIB_OBJECT int COptionsWnd::RedirectWndNotificationTo(class CPageWnd *,class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT void COptionsWnd::AddKeyboardAssignment(int,int,int);
EQLIB_OBJECT void COptionsWnd::InitKeyboardAssignments(void);
EQLIB_OBJECT void COptionsWnd::InitKeyboardPage(void);
EQLIB_OBJECT void COptionsWnd::KeyboardPageCancelKeypressAssignment(void);
EQLIB_OBJECT void COptionsWnd::SetBagOptions(int,int);
EQLIB_OBJECT void COptionsWnd::SyncChatPage(void);
EQLIB_OBJECT void COptionsWnd::SyncColorPage(void);
EQLIB_OBJECT void COptionsWnd::SyncDisplayPage(void);
EQLIB_OBJECT void COptionsWnd::SyncGeneralPage(void);
EQLIB_OBJECT void COptionsWnd::SyncMousePage(void);
EQLIB_OBJECT void COptionsWnd::FillChatFilterList(void);
};

class CPageTemplate
{
public:
EQLIB_OBJECT CPageTemplate::CPageTemplate(class CParamPage *);
// virtual
EQLIB_OBJECT CPageTemplate::~CPageTemplate(void);
//EQLIB_OBJECT void * CPageTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CPageTemplate::`vector deleting destructor'(unsigned int);
};

class CPageWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CPageWnd::CPageWnd(class CXWnd *,unsigned __int32,class CXRect,class CXStr,class CPageTemplate *);
EQLIB_OBJECT class CXStr CPageWnd::GetTabText(void)const;
EQLIB_OBJECT void CPageWnd::SetTabText(CXStr &)const;
// virtual
EQLIB_OBJECT CPageWnd::~CPageWnd(void);
//EQLIB_OBJECT void * CPageWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CPageWnd::`vector deleting destructor'(unsigned int);
};

class CParam
{
public:
EQLIB_OBJECT class CParam & CParam::operator=(class CParam const &);
// virtual
EQLIB_OBJECT CParam::~CParam(void);
//EQLIB_OBJECT void * CParam::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParam::`vector deleting destructor'(unsigned int);
};

class CParamButton
{
public:
EQLIB_OBJECT CParamButton::CParamButton(void);
EQLIB_OBJECT class CParamButton & CParamButton::operator=(class CParamButton const &);
// virtual
EQLIB_OBJECT CParamButton::~CParamButton(void);
EQLIB_OBJECT bool CParamButton::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamButton::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamButton::GetStreamSize(void);
//EQLIB_OBJECT void * CParamButton::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamButton::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamButton::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamButton::WriteToStream(class CMemoryStream &);
};

class CParamButtonDrawTemplate
{
public:
EQLIB_OBJECT CParamButtonDrawTemplate::CParamButtonDrawTemplate(void);
EQLIB_OBJECT class CParamButtonDrawTemplate & CParamButtonDrawTemplate::operator=(class CParamButtonDrawTemplate const &);
// virtual
EQLIB_OBJECT CParamButtonDrawTemplate::~CParamButtonDrawTemplate(void);
EQLIB_OBJECT bool CParamButtonDrawTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamButtonDrawTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamButtonDrawTemplate::GetStreamSize(void);
//EQLIB_OBJECT void * CParamButtonDrawTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamButtonDrawTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamButtonDrawTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamButtonDrawTemplate::WriteToStream(class CMemoryStream &);
};

class CParamClass
{
public:
EQLIB_OBJECT CParamClass::CParamClass(void);
EQLIB_OBJECT class CParamClass & CParamClass::operator=(class CParamClass const &);
// virtual
EQLIB_OBJECT CParamClass::~CParamClass(void);
EQLIB_OBJECT bool CParamClass::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamClass::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamClass::GetStreamSize(void);
//EQLIB_OBJECT void * CParamClass::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamClass::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamClass::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamClass::WriteToStream(class CMemoryStream &);
};

class CParamCombobox
{
public:
EQLIB_OBJECT CParamCombobox::CParamCombobox(void);
EQLIB_OBJECT class CParamCombobox & CParamCombobox::operator=(class CParamCombobox const &);
// virtual
EQLIB_OBJECT CParamCombobox::~CParamCombobox(void);
EQLIB_OBJECT bool CParamCombobox::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamCombobox::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamCombobox::GetStreamSize(void);
//EQLIB_OBJECT void * CParamCombobox::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamCombobox::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamCombobox::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamCombobox::WriteToStream(class CMemoryStream &);
};

class CParamControl
{
public:
EQLIB_OBJECT CParamControl::CParamControl(void);
EQLIB_OBJECT class CParamControl & CParamControl::operator=(class CParamControl const &);
// virtual
EQLIB_OBJECT CParamControl::~CParamControl(void);
EQLIB_OBJECT bool CParamControl::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamControl::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamControl::GetStreamSize(void);
//EQLIB_OBJECT void * CParamControl::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamControl::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamControl::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamControl::WriteToStream(class CMemoryStream &);
};

class CParamEditbox
{
public:
EQLIB_OBJECT CParamEditbox::CParamEditbox(void);
EQLIB_OBJECT class CParamEditbox & CParamEditbox::operator=(class CParamEditbox const &);
// virtual
EQLIB_OBJECT CParamEditbox::~CParamEditbox(void);
EQLIB_OBJECT bool CParamEditbox::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamEditbox::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamEditbox::GetStreamSize(void);
//EQLIB_OBJECT void * CParamEditbox::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamEditbox::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamEditbox::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamEditbox::WriteToStream(class CMemoryStream &);
};

class CParamFrame
{
public:
EQLIB_OBJECT CParamFrame::CParamFrame(void);
// virtual
EQLIB_OBJECT CParamFrame::~CParamFrame(void);
EQLIB_OBJECT bool CParamFrame::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamFrame::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamFrame::GetStreamSize(void);
//EQLIB_OBJECT void * CParamFrame::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamFrame::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamFrame::WriteToStream(class CMemoryStream &);
};

class CParamFrameTemplate
{
public:
EQLIB_OBJECT CParamFrameTemplate::CParamFrameTemplate(void);
EQLIB_OBJECT class CParamFrameTemplate & CParamFrameTemplate::operator=(class CParamFrameTemplate const &);
// virtual
EQLIB_OBJECT CParamFrameTemplate::~CParamFrameTemplate(void);
EQLIB_OBJECT bool CParamFrameTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamFrameTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamFrameTemplate::GetStreamSize(void);
//EQLIB_OBJECT void * CParamFrameTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamFrameTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamFrameTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamFrameTemplate::WriteToStream(class CMemoryStream &);
};

class CParamGauge
{
public:
EQLIB_OBJECT CParamGauge::CParamGauge(void);
EQLIB_OBJECT class CParamGauge & CParamGauge::operator=(class CParamGauge const &);
// virtual
EQLIB_OBJECT CParamGauge::~CParamGauge(void);
EQLIB_OBJECT bool CParamGauge::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamGauge::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamGauge::GetStreamSize(void);
//EQLIB_OBJECT void * CParamGauge::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamGauge::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamGauge::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamGauge::WriteToStream(class CMemoryStream &);
};

class CParamGaugeDrawTemplate
{
public:
EQLIB_OBJECT CParamGaugeDrawTemplate::CParamGaugeDrawTemplate(void);
EQLIB_OBJECT class CParamGaugeDrawTemplate & CParamGaugeDrawTemplate::operator=(class CParamGaugeDrawTemplate const &);
// virtual
EQLIB_OBJECT CParamGaugeDrawTemplate::~CParamGaugeDrawTemplate(void);
EQLIB_OBJECT bool CParamGaugeDrawTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamGaugeDrawTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamGaugeDrawTemplate::GetStreamSize(void);
//EQLIB_OBJECT void * CParamGaugeDrawTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamGaugeDrawTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamGaugeDrawTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamGaugeDrawTemplate::WriteToStream(class CMemoryStream &);
};

class CParamInvSlot
{
public:
EQLIB_OBJECT CParamInvSlot::CParamInvSlot(void);
EQLIB_OBJECT class CParamInvSlot & CParamInvSlot::operator=(class CParamInvSlot const &);
// virtual
EQLIB_OBJECT CParamInvSlot::~CParamInvSlot(void);
EQLIB_OBJECT bool CParamInvSlot::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamInvSlot::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamInvSlot::GetStreamSize(void);
//EQLIB_OBJECT void * CParamInvSlot::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamInvSlot::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamInvSlot::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamInvSlot::WriteToStream(class CMemoryStream &);
};

class CParamLabel
{
public:
EQLIB_OBJECT CParamLabel::CParamLabel(void);
EQLIB_OBJECT class CParamLabel & CParamLabel::operator=(class CParamLabel const &);
// virtual
EQLIB_OBJECT CParamLabel::~CParamLabel(void);
EQLIB_OBJECT bool CParamLabel::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamLabel::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamLabel::GetStreamSize(void);
//EQLIB_OBJECT void * CParamLabel::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamLabel::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamLabel::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamLabel::WriteToStream(class CMemoryStream &);
};

class CParamListbox
{
public:
EQLIB_OBJECT CParamListbox::CParamListbox(void);
EQLIB_OBJECT class CParamListbox & CParamListbox::operator=(class CParamListbox const &);
// virtual
EQLIB_OBJECT CParamListbox::~CParamListbox(void);
EQLIB_OBJECT bool CParamListbox::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamListbox::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamListbox::GetStreamSize(void);
//EQLIB_OBJECT void * CParamListbox::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamListbox::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamListbox::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamListbox::WriteToStream(class CMemoryStream &);
};

class CParamListboxColumn
{
public:
EQLIB_OBJECT CParamListboxColumn::CParamListboxColumn(void);
EQLIB_OBJECT class CParamListboxColumn & CParamListboxColumn::operator=(class CParamListboxColumn const &);
// virtual
EQLIB_OBJECT CParamListboxColumn::~CParamListboxColumn(void);
EQLIB_OBJECT bool CParamListboxColumn::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamListboxColumn::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamListboxColumn::GetStreamSize(void);
//EQLIB_OBJECT void * CParamListboxColumn::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamListboxColumn::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamListboxColumn::WriteToStream(class CMemoryStream &);
};

class CParamPage
{
public:
EQLIB_OBJECT CParamPage::CParamPage(void);
EQLIB_OBJECT class CParamPage & CParamPage::operator=(class CParamPage const &);
// virtual
EQLIB_OBJECT CParamPage::~CParamPage(void);
EQLIB_OBJECT bool CParamPage::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamPage::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamPage::GetStreamSize(void);
//EQLIB_OBJECT void * CParamPage::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamPage::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamPage::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamPage::WriteToStream(class CMemoryStream &);
};

class CParamPoint
{
public:
EQLIB_OBJECT CParamPoint::CParamPoint(void);
EQLIB_OBJECT class CParamPoint & CParamPoint::operator=(class CParamPoint const &);
// virtual
EQLIB_OBJECT CParamPoint::~CParamPoint(void);
EQLIB_OBJECT bool CParamPoint::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamPoint::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamPoint::GetStreamSize(void);
//EQLIB_OBJECT void * CParamPoint::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamPoint::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamPoint::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamPoint::WriteToStream(class CMemoryStream &);
};

class CParamRGB
{
public:
EQLIB_OBJECT CParamRGB::CParamRGB(void);
EQLIB_OBJECT class CParamRGB & CParamRGB::operator=(class CParamRGB const &);
// virtual
EQLIB_OBJECT CParamRGB::~CParamRGB(void);
EQLIB_OBJECT bool CParamRGB::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamRGB::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamRGB::GetStreamSize(void);
//EQLIB_OBJECT void * CParamRGB::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamRGB::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamRGB::WriteToStream(class CMemoryStream &);
};

class CParamScreen
{
public:
EQLIB_OBJECT CParamScreen::CParamScreen(void);
EQLIB_OBJECT class CParamScreen & CParamScreen::operator=(class CParamScreen const &);
// virtual
EQLIB_OBJECT CParamScreen::~CParamScreen(void);
EQLIB_OBJECT bool CParamScreen::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamScreen::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamScreen::GetStreamSize(void);
//EQLIB_OBJECT void * CParamScreen::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamScreen::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamScreen::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamScreen::WriteToStream(class CMemoryStream &);
};

class CParamScreenPiece
{
public:
EQLIB_OBJECT CParamScreenPiece::CParamScreenPiece(void);
EQLIB_OBJECT class CParamScreenPiece & CParamScreenPiece::operator=(class CParamScreenPiece const &);
// virtual
EQLIB_OBJECT CParamScreenPiece::~CParamScreenPiece(void);
EQLIB_OBJECT bool CParamScreenPiece::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamScreenPiece::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamScreenPiece::GetStreamSize(void);
//EQLIB_OBJECT void * CParamScreenPiece::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamScreenPiece::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamScreenPiece::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamScreenPiece::WriteToStream(class CMemoryStream &);
};

class CParamScrollbarDrawTemplate
{
public:
EQLIB_OBJECT CParamScrollbarDrawTemplate::CParamScrollbarDrawTemplate(void);
EQLIB_OBJECT class CParamScrollbarDrawTemplate & CParamScrollbarDrawTemplate::operator=(class CParamScrollbarDrawTemplate const &);
// virtual
EQLIB_OBJECT CParamScrollbarDrawTemplate::~CParamScrollbarDrawTemplate(void);
EQLIB_OBJECT bool CParamScrollbarDrawTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamScrollbarDrawTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamScrollbarDrawTemplate::GetStreamSize(void);
//EQLIB_OBJECT void * CParamScrollbarDrawTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamScrollbarDrawTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamScrollbarDrawTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamScrollbarDrawTemplate::WriteToStream(class CMemoryStream &);
};

class CParamSize
{
public:
EQLIB_OBJECT CParamSize::CParamSize(void);
EQLIB_OBJECT class CParamSize & CParamSize::operator=(class CParamSize const &);
// virtual
EQLIB_OBJECT CParamSize::~CParamSize(void);
EQLIB_OBJECT bool CParamSize::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSize::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSize::GetStreamSize(void);
//EQLIB_OBJECT void * CParamSize::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamSize::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSize::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSize::WriteToStream(class CMemoryStream &);
};

class CParamSlider
{
public:
EQLIB_OBJECT CParamSlider::CParamSlider(void);
EQLIB_OBJECT class CParamSlider & CParamSlider::operator=(class CParamSlider const &);
// virtual
EQLIB_OBJECT CParamSlider::~CParamSlider(void);
EQLIB_OBJECT bool CParamSlider::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSlider::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSlider::GetStreamSize(void);
//EQLIB_OBJECT void * CParamSlider::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamSlider::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSlider::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSlider::WriteToStream(class CMemoryStream &);
};

class CParamSliderDrawTemplate
{
public:
EQLIB_OBJECT CParamSliderDrawTemplate::CParamSliderDrawTemplate(void);
EQLIB_OBJECT class CParamSliderDrawTemplate & CParamSliderDrawTemplate::operator=(class CParamSliderDrawTemplate const &);
// virtual
EQLIB_OBJECT CParamSliderDrawTemplate::~CParamSliderDrawTemplate(void);
EQLIB_OBJECT bool CParamSliderDrawTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSliderDrawTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSliderDrawTemplate::GetStreamSize(void);
//EQLIB_OBJECT void * CParamSliderDrawTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamSliderDrawTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSliderDrawTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSliderDrawTemplate::WriteToStream(class CMemoryStream &);
};

class CParamSpellGem
{
public:
EQLIB_OBJECT CParamSpellGem::CParamSpellGem(void);
EQLIB_OBJECT class CParamSpellGem & CParamSpellGem::operator=(class CParamSpellGem const &);
// virtual
EQLIB_OBJECT CParamSpellGem::~CParamSpellGem(void);
EQLIB_OBJECT bool CParamSpellGem::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSpellGem::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSpellGem::GetStreamSize(void);
//EQLIB_OBJECT void * CParamSpellGem::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamSpellGem::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSpellGem::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSpellGem::WriteToStream(class CMemoryStream &);
};

class CParamSpellGemDrawTemplate
{
public:
EQLIB_OBJECT CParamSpellGemDrawTemplate::CParamSpellGemDrawTemplate(void);
EQLIB_OBJECT class CParamSpellGemDrawTemplate & CParamSpellGemDrawTemplate::operator=(class CParamSpellGemDrawTemplate const &);
// virtual
EQLIB_OBJECT CParamSpellGemDrawTemplate::~CParamSpellGemDrawTemplate(void);
EQLIB_OBJECT bool CParamSpellGemDrawTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSpellGemDrawTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSpellGemDrawTemplate::GetStreamSize(void);
//EQLIB_OBJECT void * CParamSpellGemDrawTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamSpellGemDrawTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSpellGemDrawTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSpellGemDrawTemplate::WriteToStream(class CMemoryStream &);
};

class CParamStaticAnimation
{
public:
EQLIB_OBJECT CParamStaticAnimation::CParamStaticAnimation(void);
EQLIB_OBJECT class CParamStaticAnimation & CParamStaticAnimation::operator=(class CParamStaticAnimation const &);
// virtual
EQLIB_OBJECT CParamStaticAnimation::~CParamStaticAnimation(void);
EQLIB_OBJECT bool CParamStaticAnimation::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamStaticAnimation::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamStaticAnimation::GetStreamSize(void);
//EQLIB_OBJECT void * CParamStaticAnimation::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamStaticAnimation::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamStaticAnimation::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamStaticAnimation::WriteToStream(class CMemoryStream &);
};

class CParamStaticFrame
{
public:
EQLIB_OBJECT CParamStaticFrame::CParamStaticFrame(void);
EQLIB_OBJECT class CParamStaticFrame & CParamStaticFrame::operator=(class CParamStaticFrame const &);
// virtual
EQLIB_OBJECT CParamStaticFrame::~CParamStaticFrame(void);
EQLIB_OBJECT bool CParamStaticFrame::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamStaticFrame::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamStaticFrame::GetStreamSize(void);
//EQLIB_OBJECT void * CParamStaticFrame::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamStaticFrame::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamStaticFrame::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamStaticFrame::WriteToStream(class CMemoryStream &);
};

class CParamStaticHeader
{
public:
EQLIB_OBJECT CParamStaticHeader::CParamStaticHeader(void);
EQLIB_OBJECT class CParamStaticHeader & CParamStaticHeader::operator=(class CParamStaticHeader const &);
// virtual
EQLIB_OBJECT CParamStaticHeader::~CParamStaticHeader(void);
EQLIB_OBJECT bool CParamStaticHeader::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamStaticHeader::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamStaticHeader::GetStreamSize(void);
//EQLIB_OBJECT void * CParamStaticHeader::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamStaticHeader::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamStaticHeader::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamStaticHeader::WriteToStream(class CMemoryStream &);
};

class CParamStaticScreenPiece
{
public:
EQLIB_OBJECT CParamStaticScreenPiece::CParamStaticScreenPiece(void);
// virtual
EQLIB_OBJECT CParamStaticScreenPiece::~CParamStaticScreenPiece(void);
EQLIB_OBJECT bool CParamStaticScreenPiece::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamStaticScreenPiece::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamStaticScreenPiece::GetStreamSize(void);
//EQLIB_OBJECT void * CParamStaticScreenPiece::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamStaticScreenPiece::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamStaticScreenPiece::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamStaticScreenPiece::WriteToStream(class CMemoryStream &);
};

class CParamStaticText
{
public:
EQLIB_OBJECT CParamStaticText::CParamStaticText(void);
EQLIB_OBJECT class CParamStaticText & CParamStaticText::operator=(class CParamStaticText const &);
// virtual
EQLIB_OBJECT CParamStaticText::~CParamStaticText(void);
EQLIB_OBJECT bool CParamStaticText::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamStaticText::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamStaticText::GetStreamSize(void);
//EQLIB_OBJECT void * CParamStaticText::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamStaticText::`vector deleting destructor'(unsigned int);
#define SafeYLoc 0
EQLIB_OBJECT void CParamStaticText::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamStaticText::WriteToStream(class CMemoryStream &);
};

class CParamSTMLbox
{
public:
EQLIB_OBJECT CParamSTMLbox::CParamSTMLbox(void);
// virtual
EQLIB_OBJECT CParamSTMLbox::~CParamSTMLbox(void);
EQLIB_OBJECT bool CParamSTMLbox::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSTMLbox::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSTMLbox::GetStreamSize(void);
//EQLIB_OBJECT void * CParamSTMLbox::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamSTMLbox::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSTMLbox::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSTMLbox::WriteToStream(class CMemoryStream &);
};

class CParamSuiteDefaults
{
public:
EQLIB_OBJECT CParamSuiteDefaults::CParamSuiteDefaults(void);
EQLIB_OBJECT class CParamSuiteDefaults & CParamSuiteDefaults::operator=(class CParamSuiteDefaults const &);
// virtual
EQLIB_OBJECT CParamSuiteDefaults::~CParamSuiteDefaults(void);
EQLIB_OBJECT bool CParamSuiteDefaults::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamSuiteDefaults::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamSuiteDefaults::GetStreamSize(void);
//EQLIB_OBJECT void * CParamSuiteDefaults::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamSuiteDefaults::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamSuiteDefaults::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamSuiteDefaults::WriteToStream(class CMemoryStream &);
};

class CParamTabBox
{
public:
EQLIB_OBJECT CParamTabBox::CParamTabBox(void);
EQLIB_OBJECT class CParamTabBox & CParamTabBox::operator=(class CParamTabBox const &);
// virtual
EQLIB_OBJECT CParamTabBox::~CParamTabBox(void);
EQLIB_OBJECT bool CParamTabBox::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamTabBox::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamTabBox::GetStreamSize(void);
//EQLIB_OBJECT void * CParamTabBox::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamTabBox::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamTabBox::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamTabBox::WriteToStream(class CMemoryStream &);
};

class CParamTextureInfo
{
public:
EQLIB_OBJECT CParamTextureInfo::CParamTextureInfo(void);
// virtual
EQLIB_OBJECT CParamTextureInfo::~CParamTextureInfo(void);
EQLIB_OBJECT bool CParamTextureInfo::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamTextureInfo::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamTextureInfo::GetStreamSize(void);
//EQLIB_OBJECT void * CParamTextureInfo::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamTextureInfo::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamTextureInfo::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamTextureInfo::WriteToStream(class CMemoryStream &);
};

class CParamUi2DAnimation
{
public:
EQLIB_OBJECT CParamUi2DAnimation::CParamUi2DAnimation(void);
// virtual
EQLIB_OBJECT CParamUi2DAnimation::~CParamUi2DAnimation(void);
EQLIB_OBJECT bool CParamUi2DAnimation::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamUi2DAnimation::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamUi2DAnimation::GetStreamSize(void);
//EQLIB_OBJECT void * CParamUi2DAnimation::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamUi2DAnimation::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamUi2DAnimation::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamUi2DAnimation::WriteToStream(class CMemoryStream &);
};

class CParamWindowDrawTemplate
{
public:
EQLIB_OBJECT CParamWindowDrawTemplate::CParamWindowDrawTemplate(void);
// virtual
EQLIB_OBJECT CParamWindowDrawTemplate::~CParamWindowDrawTemplate(void);
EQLIB_OBJECT bool CParamWindowDrawTemplate::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CParamWindowDrawTemplate::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CParamWindowDrawTemplate::GetStreamSize(void);
//EQLIB_OBJECT void * CParamWindowDrawTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CParamWindowDrawTemplate::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CParamWindowDrawTemplate::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CParamWindowDrawTemplate::WriteToStream(class CMemoryStream &);
};

class CParseTokensXML
{
public:
EQLIB_OBJECT CParseTokensXML::~CParseTokensXML(void);
//EQLIB_OBJECT bool CParseTokensXML::Accept(enum ETokTypeXML);
EQLIB_OBJECT bool CParseTokensXML::StartFileBased(class CXStr);
EQLIB_OBJECT class CXStr CParseTokensXML::GetCurFile(void);
EQLIB_OBJECT void __cdecl CParseTokensXML::SetError(char const *,...);
};

class CParseTokXML
{
public:
EQLIB_OBJECT CParseTokXML::~CParseTokXML(void);
//EQLIB_OBJECT enum ETokTypeXML CParseTokXML::NextToken(void);
//EQLIB_OBJECT void * CParseTokXML::`scalar deleting destructor'(unsigned int);
// private
EQLIB_OBJECT bool CParseTokXML::GetEntityRef(char &);
};

class CPetInfoWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CPetInfoWnd::CPetInfoWnd(class CXWnd *);
EQLIB_OBJECT class CButtonWnd * CPetInfoWnd::GetButton(int);
EQLIB_OBJECT void CPetInfoWnd::Activate(void);
EQLIB_OBJECT void CPetInfoWnd::SetShowOnSummon(bool);
EQLIB_OBJECT void CPetInfoWnd::Update(void);
// virtual
EQLIB_OBJECT CPetInfoWnd::~CPetInfoWnd(void);
EQLIB_OBJECT int CPetInfoWnd::OnProcessFrame(void);
EQLIB_OBJECT int CPetInfoWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CPetInfoWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CPetInfoWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CPetInfoWnd::Deactivate(void);
// private
EQLIB_OBJECT void CPetInfoWnd::Init(void);
};

class CPetitionQWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CPetitionQWnd::CPetitionQWnd(class CXWnd *);
EQLIB_OBJECT char * CPetitionQWnd::GetCurrentPetitionersName(void);
EQLIB_OBJECT void CPetitionQWnd::Activate(void);
EQLIB_OBJECT void CPetitionQWnd::AddGMText(void);
EQLIB_OBJECT void CPetitionQWnd::CheckedOut(struct petitionQtype const *,int);
EQLIB_OBJECT void CPetitionQWnd::ClearCurrentPet(void);
EQLIB_OBJECT void CPetitionQWnd::FillFields(void);
EQLIB_OBJECT void CPetitionQWnd::LogPetitionText(void);
EQLIB_OBJECT void CPetitionQWnd::SetButtonsForPetition(bool,bool);
EQLIB_OBJECT void CPetitionQWnd::SetPriorityDisplay(void);
EQLIB_OBJECT void CPetitionQWnd::UndoCheckout(void);
EQLIB_OBJECT void CPetitionQWnd::UpdatePetitions(void);
// virtual
EQLIB_OBJECT CPetitionQWnd::~CPetitionQWnd(void);
EQLIB_OBJECT int CPetitionQWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CPetitionQWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CPetitionQWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CPetitionQWnd::Deactivate(void);
};

class CPlayerNotesWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CPlayerNotesWnd::CPlayerNotesWnd(class CXWnd *);
EQLIB_OBJECT void CPlayerNotesWnd::Activate(void);
EQLIB_OBJECT void CPlayerNotesWnd::AppendText(char *);
EQLIB_OBJECT void CPlayerNotesWnd::SaveNotes(void);
// virtual
EQLIB_OBJECT CPlayerNotesWnd::~CPlayerNotesWnd(void);
EQLIB_OBJECT int CPlayerNotesWnd::Draw(void)const;
EQLIB_OBJECT int CPlayerNotesWnd::OnProcessFrame(void);
EQLIB_OBJECT int CPlayerNotesWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CPlayerNotesWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CPlayerNotesWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CPlayerNotesWnd::Deactivate(void);
// private
EQLIB_OBJECT void CPlayerNotesWnd::Init(void);
};

class CPlayerWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CPlayerWnd::CPlayerWnd(class CXWnd *);
EQLIB_OBJECT void CPlayerWnd::Activate(void);
EQLIB_OBJECT void CPlayerWnd::CreateLocalMenu(void);
EQLIB_OBJECT void CPlayerWnd::UpdateContextMenu(void);
// virtual
EQLIB_OBJECT CPlayerWnd::~CPlayerWnd(void);
EQLIB_OBJECT int CPlayerWnd::Draw(void)const;
EQLIB_OBJECT int CPlayerWnd::OnProcessFrame(void);
EQLIB_OBJECT int CPlayerWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CPlayerWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CPlayerWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CPlayerWnd::Deactivate(void);
EQLIB_OBJECT void CPlayerWnd::LoadIniInfo(void);
EQLIB_OBJECT void CPlayerWnd::StoreIniInfo(void);
// private
EQLIB_OBJECT void CPlayerWnd::Init(void);
};

class CPotionBeltWnd : public CSidlScreenWnd
{
public:
// virtual
EQLIB_OBJECT int CPotionBeltWnd::DrawTooltip(class CXWnd const *)const;
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
EQLIB_OBJECT CQuantityWnd::CQuantityWnd(class CXWnd *);
EQLIB_OBJECT void CQuantityWnd::Activate(class CXWnd *,int,int,int,int,bool);
// virtual
EQLIB_OBJECT CQuantityWnd::~CQuantityWnd(void);
EQLIB_OBJECT void CQuantityWnd::Open(class CXWnd *,int,int,int,int,int,int,bool);
EQLIB_OBJECT int CQuantityWnd::Draw(void)const;
EQLIB_OBJECT int CQuantityWnd::OnProcessFrame(void);
EQLIB_OBJECT int CQuantityWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CQuantityWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CQuantityWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CQuantityWnd::Deactivate(void);
// private
//EQLIB_OBJECT void CQuantityWnd::Accept;
EQLIB_OBJECT void CQuantityWnd::CheckMaxEditWnd(void);
EQLIB_OBJECT void CQuantityWnd::UpdateEditWndFromSlider(void);
EQLIB_OBJECT void CQuantityWnd::UpdateSliderFromEditWnd(void);
};

class CRadioGroup
{
public:
EQLIB_OBJECT CRadioGroup::CRadioGroup(class CXStr);
EQLIB_OBJECT class CXStr CRadioGroup::GetName(void)const;
// virtual
EQLIB_OBJECT CRadioGroup::~CRadioGroup(void);
//EQLIB_OBJECT void * CRadioGroup::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CRadioGroup::`vector deleting destructor'(unsigned int);
};

class CRaid
{
public:
EQLIB_OBJECT CRaid::~CRaid(void);
EQLIB_OBJECT CRaid::CRaid(void);
EQLIB_OBJECT bool CRaid::IsInRaid(void);
EQLIB_OBJECT bool CRaid::IsInvited(void);
EQLIB_OBJECT bool CRaid::IsRaidGroupLeader(void);
EQLIB_OBJECT bool CRaid::IsRaidLeader(void);
EQLIB_OBJECT bool CRaid::IsRaidMember(char *);
EQLIB_OBJECT int CRaid::GetLootType(void);
EQLIB_OBJECT int CRaid::GetNumRaidMembers(void);
EQLIB_OBJECT struct RaidMember * CRaid::GetRaidMemberAt(int);
EQLIB_OBJECT void CRaid::AddRaidLooter(void);
EQLIB_OBJECT void CRaid::ClearInvitedState(void);
EQLIB_OBJECT void CRaid::CreateInviteRaid(void);
EQLIB_OBJECT void CRaid::HandleC2SRaidMessage(char *);
EQLIB_OBJECT void CRaid::HandleCreateInviteRaid(struct CSRaidMessage *);
EQLIB_OBJECT void CRaid::HandleS2CRaidMessage(char *);
EQLIB_OBJECT void CRaid::RemoveRaidLooter(void);
EQLIB_OBJECT void CRaid::RemoveRaidMember(void);
EQLIB_OBJECT void CRaid::ResetRaid(void);
EQLIB_OBJECT void CRaid::ResetWindow(void);
EQLIB_OBJECT void CRaid::SendInviteResponse(bool);
EQLIB_OBJECT void CRaid::SendLeadershipChange(char *);
EQLIB_OBJECT void CRaid::SendRaidChat(char *);
EQLIB_OBJECT void CRaid::SetLootType(char *);
EQLIB_OBJECT void CRaid::SetRaidLeader(char *);
EQLIB_OBJECT void CRaid::SetTargetRaidPlayer(char *);
EQLIB_OBJECT void CRaid::UpdateClassColor(int,unsigned long);
EQLIB_OBJECT void CRaid::UpdateOptionsWindow(void);
// private
EQLIB_OBJECT bool CRaid::IsRaidLooter(char *);
EQLIB_OBJECT int CRaid::FindOpenIndex(void);
EQLIB_OBJECT int CRaid::FindPlayerIndex(char *);
EQLIB_OBJECT int CRaid::FindRaidGroupLeader(int);
EQLIB_OBJECT void CRaid::AddRaidMember(struct RaidAddMember *);
EQLIB_OBJECT void CRaid::ChangeLeadership(char *);
EQLIB_OBJECT void CRaid::DeleteRaidMember(struct SCRaidMessage *);
EQLIB_OBJECT void CRaid::DetermineRaidChanges(char *);
EQLIB_OBJECT void CRaid::HandleAddLooter(char *);
EQLIB_OBJECT void CRaid::HandlePositionChange(struct SCRaidMessage *);
EQLIB_OBJECT void CRaid::HandleRemoveLooter(char *);
EQLIB_OBJECT void CRaid::HandleSetLootType(int);
EQLIB_OBJECT void CRaid::InitializeRaid(char *);
EQLIB_OBJECT void CRaid::RaidCreated(struct CreateRaidMessage *);
EQLIB_OBJECT void CRaid::RaidGroupLeaderChange(struct SCRaidMessage *);
EQLIB_OBJECT void CRaid::RenameMember(struct RenameRaidMember *);
EQLIB_OBJECT void CRaid::SendRaidMsg(int,char *,char *,int);
EQLIB_OBJECT void CRaid::SetLootTypeResponse(struct SCRaidMessage *);
EQLIB_OBJECT void CRaid::UpdateLevelAverage(void);
};

class CRaidOptionsWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CRaidOptionsWnd::CRaidOptionsWnd(class CXWnd *);
EQLIB_OBJECT void CRaidOptionsWnd::Activate(void);
EQLIB_OBJECT void CRaidOptionsWnd::AddLooterToList(char *);
EQLIB_OBJECT void CRaidOptionsWnd::ClearLooterList(void);
EQLIB_OBJECT void CRaidOptionsWnd::UpdateComponents(void);
// virtual
EQLIB_OBJECT CRaidOptionsWnd::~CRaidOptionsWnd(void);
EQLIB_OBJECT int CRaidOptionsWnd::OnProcessFrame(void);
EQLIB_OBJECT int CRaidOptionsWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CRaidOptionsWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CRaidOptionsWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CRaidOptionsWnd::Deactivate(void);
// private
EQLIB_OBJECT void CRaidOptionsWnd::Init(void);
EQLIB_OBJECT void CRaidOptionsWnd::InitializeClassColors(void);
};

class CRaidWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CRaidWnd::CRaidWnd(class CXWnd *);
EQLIB_OBJECT void CRaidWnd::Activate(void);
EQLIB_OBJECT void CRaidWnd::AddPlayertoList(char *,char *,char *,char *,int,int,bool);
EQLIB_OBJECT void CRaidWnd::ChangePosition(char *,int,int,int,bool);
EQLIB_OBJECT void CRaidWnd::ChangeRaidGroupLeader(char *,int,char *);
EQLIB_OBJECT void CRaidWnd::ClearPlayerList(void);
EQLIB_OBJECT void CRaidWnd::RemovePlayerFromList(char *,int);
EQLIB_OBJECT void CRaidWnd::SetClassColor(int,unsigned long);
EQLIB_OBJECT void CRaidWnd::SetPlayerClassColor(char *,int,int);
EQLIB_OBJECT void CRaidWnd::SetPlayerClassColor(int,int,int);
EQLIB_OBJECT void CRaidWnd::SetRaidCount(int);
EQLIB_OBJECT void CRaidWnd::SetRaidMemberRank(char *,char *,int);
EQLIB_OBJECT void CRaidWnd::SetRaidTarget(char *,int,char *,int);
EQLIB_OBJECT void CRaidWnd::UpdateButtons(void);
EQLIB_OBJECT void CRaidWnd::UpdateLevelAverage(int);
EQLIB_OBJECT void CRaidWnd::UpdateMemberName(char *,char *,int);
// virtual
EQLIB_OBJECT CRaidWnd::~CRaidWnd(void);
EQLIB_OBJECT int CRaidWnd::OnProcessFrame(void);
EQLIB_OBJECT int CRaidWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CRaidWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CRaidWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CRaidWnd::Deactivate(void);
// private
EQLIB_OBJECT int CRaidWnd::FindIndexNotInGroupList(char *);
EQLIB_OBJECT int CRaidWnd::FindOpenIndexInGroup(int);
EQLIB_OBJECT int CRaidWnd::FindPlayerIndexInGroup(char *,int);
EQLIB_OBJECT void CRaidWnd::AddSeparator(void);
EQLIB_OBJECT void CRaidWnd::Init(void);
EQLIB_OBJECT void CRaidWnd::InitializeClassColors(void);
EQLIB_OBJECT void CRaidWnd::ResortRaidGroupList(int,int);
};

class CRC32Generator
{
public:
EQLIB_OBJECT unsigned int CRC32Generator::generateCRC32(unsigned char const *,unsigned int)const;
EQLIB_OBJECT unsigned int CRC32Generator::updateCRC32(unsigned int,unsigned char const *,unsigned int)const;
// private
EQLIB_OBJECT static unsigned int * CRC32Generator::_crcTable;
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
EQLIB_OBJECT static bool __cdecl CResolutionHandlerBase::IsFullscreenAvailable(void);
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::GetDesktopBitsPerPixel(void);
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::GetDesktopHeight(void);
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::GetDesktopRefreshRate(void);
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::GetDesktopWidth(void);
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::GetHeight(void);
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::GetWidth(void);
EQLIB_OBJECT static int __cdecl CResolutionHandlerBase::Init(void);
EQLIB_OBJECT static void __cdecl CResolutionHandlerBase::ChangeToResolution(int,int,int,int,int);
EQLIB_OBJECT static void __cdecl CResolutionHandlerBase::SaveSettings(void);
EQLIB_OBJECT static void __cdecl CResolutionHandlerBase::Shutdown(void);
EQLIB_OBJECT static void __cdecl CResolutionHandlerBase::ToggleScreenMode(void);
EQLIB_OBJECT static void __cdecl CResolutionHandlerBase::UpdateWindowPosition(void);


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
	EQLIB_OBJECT void UpdateResolution(ResolutionUpdateData& data);
	EQLIB_OBJECT DWORD GetWindowedStyle() const;
};
class CRespawnWnd
{
public:
EQLIB_OBJECT CRespawnWnd::CRespawnWnd(CXWnd *pParent);
// virtual
EQLIB_OBJECT CRespawnWnd::~CRespawnWnd(void);
};

class CScreenTemplate
{
public:
EQLIB_OBJECT CScreenTemplate::CScreenTemplate(class CParamScreen *);
// virtual
EQLIB_OBJECT CScreenTemplate::~CScreenTemplate(void);
//EQLIB_OBJECT void * CScreenTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CScreenTemplate::`vector deleting destructor'(unsigned int);
};

class CScrollbarTemplate
{
public:
EQLIB_OBJECT CScrollbarTemplate::~CScrollbarTemplate(void);
EQLIB_OBJECT CScrollbarTemplate::CScrollbarTemplate(class CScrollbarTemplate const &);
EQLIB_OBJECT CScrollbarTemplate::CScrollbarTemplate(void);
EQLIB_OBJECT class CScrollbarTemplate & CScrollbarTemplate::operator=(class CScrollbarTemplate const &);
};

class CSelectorWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSelectorWnd::CSelectorWnd(class CXWnd *);
EQLIB_OBJECT void CSelectorWnd::Activate(void);
EQLIB_OBJECT void CSelectorWnd::KeyMapUpdated(void);
// virtual
EQLIB_OBJECT CSelectorWnd::~CSelectorWnd(void);
EQLIB_OBJECT int CSelectorWnd::OnProcessFrame(void);
EQLIB_OBJECT int CSelectorWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CSelectorWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CSelectorWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSelectorWnd::Deactivate(void);
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
/*0x1c*/ HashCXStrElement<CXMLDataPtr, 16 * 1024> ClassItemHashes;//size 0x1c
/*0x38*/ ArrayClass2_RO<CXMLDataClass>	XMLDataArray;
/*0x54*/ CXMLSymbolTable				SymbolTable;
/*0x90*/ CXStr							ErrorString;
/*0x94*/ 
EQLIB_OBJECT CXMLDataManager::CXMLDataManager(void);
EQLIB_OBJECT bool CXMLDataManager::IsDerivedFrom(int,int);
EQLIB_OBJECT bool CXMLDataManager::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT class CXMLData * CXMLDataManager::GetXMLData(class CXStr,class CXStr);
EQLIB_OBJECT class CXMLData * CXMLDataManager::GetXMLData(int,int);
EQLIB_OBJECT int CXMLDataManager::GetClassIdx(class CXStr);
EQLIB_OBJECT int CXMLDataManager::GetItemIdx(int,class CXStr);
EQLIB_OBJECT int CXMLDataManager::GetNumClass(void);
EQLIB_OBJECT int CXMLDataManager::GetNumItem(int);
// virtual
EQLIB_OBJECT CXMLDataManager::~CXMLDataManager(void);
EQLIB_OBJECT bool CXMLDataManager::DataValidate(void);
EQLIB_OBJECT bool CXMLDataManager::ReadValidate(class CMemoryStream &);
EQLIB_OBJECT bool CXMLDataManager::WriteValidate(class CMemoryStream &);
EQLIB_OBJECT int CXMLDataManager::GetStreamSize(void);
//EQLIB_OBJECT void * CXMLDataManager::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CXMLDataManager::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CXMLDataManager::IndexAll(void);
EQLIB_OBJECT void CXMLDataManager::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CXMLDataManager::Set(class CXMLDataManager &);
EQLIB_OBJECT void CXMLDataManager::WriteToStream(class CMemoryStream &);
// protected
EQLIB_OBJECT void CXMLDataManager::AddToSuperType(class CXStr,class CXMLDataPtr);
EQLIB_OBJECT void CXMLDataManager::SetEnumHash(void);
};
class CXMLParamManager : public CXMLDataManager
{
public:
// virtual
EQLIB_OBJECT CXMLParamManager::~CXMLParamManager(void);
EQLIB_OBJECT bool CXMLParamManager::XMLDataCopy(class CXMLData *,class CXMLData *);
EQLIB_OBJECT class CXMLData * CXMLParamManager::AllocPtr(class CXMLDataPtr &,int,class CXMLData const *);
//EQLIB_OBJECT void * CXMLParamManager::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CXMLParamManager::`vector deleting destructor'(unsigned int);
};

class CSidlManagerBase
{
#if !defined(TEST) && !defined(LIVE)
/*0x000*/ void *vftable;
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
/*0x000*/ void *vftable;
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
//size 0x200 see 53ED93 in 2019 01 11 eqgame.exe -eqmule
class CSidlManager : public CSidlManagerBase
{
public:
EQLIB_OBJECT CSidlManager::CSidlManager(void);
EQLIB_OBJECT CButtonDrawTemplate *CSidlManager::FindButtonDrawTemplate(const CXStr& Name) const;
EQLIB_OBJECT CButtonDrawTemplate *CSidlManager::FindButtonDrawTemplate(unsigned __int32 ID) const;
EQLIB_OBJECT class CButtonDrawTemplate CSidlManager::GetButtonDrawTemplateFromParamButtonDrawTemplate(class CParamButtonDrawTemplate const &)const;
EQLIB_OBJECT class CGaugeDrawTemplate CSidlManager::GetGaugeDrawTemplateFromParamGaugeDrawTemplate(class CParamGaugeDrawTemplate const &)const;
EQLIB_OBJECT class CScreenPieceTemplate * CSidlManager::CreateScreenPieceTemplateFromParamScreenPiece(class CParamScreenPiece const *)const;
EQLIB_OBJECT class CScreenPieceTemplate * CSidlManager::FindScreenPieceTemplate(class CXStr *)const;
EQLIB_OBJECT class CScreenPieceTemplate * CSidlManager::FindScreenPieceTemplate(char *);
EQLIB_OBJECT class CScreenPieceTemplate * CSidlManager::FindScreenPieceTemplate(unsigned __int32)const;
EQLIB_OBJECT class CScrollbarTemplate CSidlManager::GetScrollbarTemplateFromParamScrollbarTemplate(class CParamScrollbarDrawTemplate const &)const;
EQLIB_OBJECT class CSliderDrawTemplate * CSidlManager::FindSliderDrawTemplate(class CXStr)const;
EQLIB_OBJECT class CSliderDrawTemplate * CSidlManager::FindSliderDrawTemplate(unsigned __int32)const;
EQLIB_OBJECT class CSliderDrawTemplate CSidlManager::GetSliderDrawTemplateFromParamSliderDrawTemplate(class CParamSliderDrawTemplate const &)const;
EQLIB_OBJECT class CSpellGemDrawTemplate CSidlManager::GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate(class CParamSpellGemDrawTemplate const &)const;
EQLIB_OBJECT class CTAFrameDraw * CSidlManager::FindFrameDraw(unsigned __int32)const;
EQLIB_OBJECT class CTAFrameDraw CSidlManager::CreateTAFrameDrawFromSidlFrame(class CParamFrameTemplate const *)const;
EQLIB_OBJECT class CTextureAnimation * CSidlManager::FindAnimation(class CXStr const &)const;
EQLIB_OBJECT class CTextureAnimation * CSidlManager::FindAnimation(unsigned __int32)const;
EQLIB_OBJECT class CTextureAnimation CSidlManager::CreateTextureAnimationFromSidlAnimation(class CParamUi2DAnimation const *)const;
EQLIB_OBJECT class CXStr CSidlManager::GetParsingErrorMsg(void)const;
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT class CXWnd * CSidlManager::CreateXWndFromTemplate(class CXWnd *,class CControlTemplate *, bool bSomething = 0);
#else
EQLIB_OBJECT class CXWnd * CSidlManager::CreateXWndFromTemplate(class CXWnd *,class CControlTemplate *);
#endif
EQLIB_OBJECT CXWnd* CSidlManager::CreateXWnd(CXWnd *pwndParent, CControlTemplate *pControl);
EQLIB_OBJECT CXWnd* CSidlManager::CreateHotButtonWnd(CXWnd* pwndParent, CControlTemplate* pControl);
EQLIB_OBJECT CXWnd * CSidlManager::CreateXWndFromTemplate(CXWnd *,CXStr &);
EQLIB_OBJECT class CXWndDrawTemplate * CSidlManager::FindDrawTemplate(CXStr *)const;
EQLIB_OBJECT class CXWndDrawTemplate * CSidlManager::FindDrawTemplate(unsigned __int32)const;
EQLIB_OBJECT class CXWndDrawTemplate CSidlManager::CreateDrawTemplateFromParamWindowDrawTemplate(class CParamWindowDrawTemplate const *)const;
//EQLIB_OBJECT enum EStaticScreenPieceClasses CSidlManager::GetScreenPieceEnum(class CScreenPieceTemplate *)const;
EQLIB_OBJECT static class CXPoint __cdecl CSidlManager::GetPointFromParamPoint(class CParamPoint const &);
EQLIB_OBJECT static class CXRect __cdecl CSidlManager::GetRectFromParamPointSize(class CParamPoint const &,class CParamSize const &);
EQLIB_OBJECT static class CXSize __cdecl CSidlManager::GetSizeFromParamSize(class CParamSize const &);
EQLIB_OBJECT static class CXStr __cdecl CSidlManager::TranslateString(class CXStr);
EQLIB_OBJECT static unsigned long __cdecl CSidlManager::GetD3DCOLOR(class CParamRGB const &);
EQLIB_OBJECT class CUITextureInfo * CSidlManager::FindTexture(class CXStr)const;
EQLIB_OBJECT class CUITextureInfo * CSidlManager::FindTexture(unsigned __int32)const;
EQLIB_OBJECT void CSidlManager::AddAnimationInOrder(class CTextureAnimation *);
EQLIB_OBJECT void CSidlManager::AddDrawTemplateInOrder(class CXWndDrawTemplate *);
EQLIB_OBJECT void CSidlManager::AddScreenPieceTemplateInOrder(class CScreenPieceTemplate *);
EQLIB_OBJECT void CSidlManager::AddTAFrameDrawInOrder(class CTAFrameDraw *);
EQLIB_OBJECT void CSidlManager::DeleteContents(void);
EQLIB_OBJECT void CSidlManager::LoadSidl(CXStr const &,CXStr const &,CXStr const &,CXStr const &);
// virtual
EQLIB_OBJECT CSidlManager::~CSidlManager(void);
//EQLIB_OBJECT void * CSidlManager::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CSidlManager::`vector deleting destructor'(unsigned int);
};

class CSkillsSelectWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSkillsSelectWnd::CSkillsSelectWnd(class CXWnd *);
EQLIB_OBJECT void CSkillsSelectWnd::Refresh(void);
EQLIB_OBJECT void CSkillsSelectWnd::SetTypesToDisplay(int);
// virtual
EQLIB_OBJECT CSkillsSelectWnd::~CSkillsSelectWnd(void);
EQLIB_OBJECT bool CSkillsSelectWnd::IsActive(void);
EQLIB_OBJECT int CSkillsSelectWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CSkillsSelectWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CSkillsSelectWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSkillsSelectWnd::Activate(void);
EQLIB_OBJECT void CSkillsSelectWnd::Deactivate(void);
// private
EQLIB_OBJECT void CSkillsSelectWnd::UpdateAll(void);
EQLIB_OBJECT void CSkillsSelectWnd::UpdateSkill(int);
};

class CSkillsWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSkillsWnd::CSkillsWnd(class CXWnd *);
EQLIB_OBJECT void CSkillsWnd::Activate(void);
EQLIB_OBJECT void CSkillsWnd::SkillImproveOccurred(int);
// virtual
EQLIB_OBJECT CSkillsWnd::~CSkillsWnd(void);
EQLIB_OBJECT int CSkillsWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CSkillsWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CSkillsWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSkillsWnd::Deactivate(void);
// protected
EQLIB_OBJECT void CSkillsWnd::UpdateAll(void);
EQLIB_OBJECT void CSkillsWnd::UpdateSkill(int);
};

class CSliderDrawTemplate
{
public:
EQLIB_OBJECT CSliderDrawTemplate::~CSliderDrawTemplate(void);
};

class CSliderTemplate
{
public:
EQLIB_OBJECT CSliderTemplate::CSliderTemplate(class CParamSlider *);
// virtual
EQLIB_OBJECT CSliderTemplate::~CSliderTemplate(void);
//EQLIB_OBJECT void * CSliderTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CSliderTemplate::`vector deleting destructor'(unsigned int);
};

class CSliderWnd: public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSliderWnd::CSliderWnd(class CXWnd *,unsigned __int32,class CXRect,class CSliderTemplate *);
EQLIB_OBJECT class CXRect CSliderWnd::GetEndCapLeftRect(void)const;
EQLIB_OBJECT class CXRect CSliderWnd::GetEndCapRightRect(void)const;
EQLIB_OBJECT class CXRect CSliderWnd::GetMiddleRangeRect(void)const;
EQLIB_OBJECT class CXRect CSliderWnd::GetThumbRect(void)const;
EQLIB_OBJECT int CSliderWnd::GetValue(void)const;
EQLIB_OBJECT void CSliderWnd::SetNumTicks(int);
EQLIB_OBJECT void CSliderWnd::SetValue(int);
// virtual
EQLIB_OBJECT CSliderWnd::~CSliderWnd(void);
EQLIB_OBJECT int CSliderWnd::Draw(void)const;
EQLIB_OBJECT int CSliderWnd::HandleKeyboardMsg(unsigned __int32,unsigned __int32,bool);
EQLIB_OBJECT int CSliderWnd::HandleLButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSliderWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSliderWnd::HandleLButtonUpAfterHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSliderWnd::HandleMouseMove(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSliderWnd::OnProcessFrame(void);
//EQLIB_OBJECT void * CSliderWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CSliderWnd::`vector deleting destructor'(unsigned int);
// private
EQLIB_OBJECT int CSliderWnd::DrawEndCapLeft(void)const;
EQLIB_OBJECT int CSliderWnd::DrawEndCapRight(void)const;
EQLIB_OBJECT int CSliderWnd::DrawMiddleRange(void)const;
EQLIB_OBJECT int CSliderWnd::DrawThumb(void)const;
EQLIB_OBJECT void CSliderWnd::SetThumbToOffset(int);
EQLIB_OBJECT void CSliderWnd::UpdateMiddleRange(void);
EQLIB_OBJECT void CSliderWnd::UpdateThumb(void);
};

class CSocialEditWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSocialEditWnd::CSocialEditWnd(class CXWnd *);
EQLIB_OBJECT unsigned long CSocialEditWnd::GetSocialTextColor(int);
EQLIB_OBJECT void CSocialEditWnd::Activate(int);
// virtual
EQLIB_OBJECT CSocialEditWnd::~CSocialEditWnd(void);
EQLIB_OBJECT int CSocialEditWnd::Draw(void)const;
EQLIB_OBJECT int CSocialEditWnd::OnProcessFrame(void);
EQLIB_OBJECT int CSocialEditWnd::OnSetFocus(class CXWnd *);
EQLIB_OBJECT int CSocialEditWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CSocialEditWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CSocialEditWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSocialEditWnd::Deactivate(void);
// private
EQLIB_OBJECT void CSocialEditWnd::ClickedAccept(void);
EQLIB_OBJECT void CSocialEditWnd::ClickedClear(void);
EQLIB_OBJECT void CSocialEditWnd::ClickedTextColorButton(int);
EQLIB_OBJECT void CSocialEditWnd::Init(void);
EQLIB_OBJECT void CSocialEditWnd::UpdateControlsFromSocial(void);
};

class CSoulmarkWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSoulmarkWnd::CSoulmarkWnd(class CXWnd *);
EQLIB_OBJECT void CSoulmarkWnd::Activate(char *,char *);
EQLIB_OBJECT void CSoulmarkWnd::Activate(void);
EQLIB_OBJECT void CSoulmarkWnd::Clear(void);
EQLIB_OBJECT void CSoulmarkWnd::FillFields(void);
EQLIB_OBJECT void CSoulmarkWnd::Inquire(char *);
EQLIB_OBJECT void CSoulmarkWnd::Praise(char *);
EQLIB_OBJECT void CSoulmarkWnd::SaveMarks(void);
EQLIB_OBJECT void CSoulmarkWnd::UpdateList(void);
EQLIB_OBJECT void CSoulmarkWnd::UpdateSoulmarks(struct soulMarkMsg *);
EQLIB_OBJECT void CSoulmarkWnd::Warn(char *);
// virtual
EQLIB_OBJECT CSoulmarkWnd::~CSoulmarkWnd(void);
EQLIB_OBJECT int CSoulmarkWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CSoulmarkWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CSoulmarkWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSoulmarkWnd::Deactivate(void);
// protected
EQLIB_OBJECT void CSoulmarkWnd::AddMark(int,char *,char *,char *);
EQLIB_OBJECT void CSoulmarkWnd::Inquire(char *,char *);
};

class CSpellBookWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSpellBookWnd::CSpellBookWnd(class CXWnd *);
EQLIB_OBJECT bool CSpellBookWnd::StartSpellMemorization(int,int,bool);
EQLIB_OBJECT int CSpellBookWnd::GetSpellMemTicksLeft(void);
EQLIB_OBJECT int CSpellBookWnd::GetSpellScribeTicksLeft(void);
EQLIB_OBJECT static int __cdecl CSpellBookWnd::GetBookSlot(int);
EQLIB_OBJECT void CSpellBookWnd::Activate(void);
EQLIB_OBJECT void CSpellBookWnd::AutoMemSpell(int,int);
EQLIB_OBJECT void CSpellBookWnd::DeleteSpellFromBook(int,int);
EQLIB_OBJECT void CSpellBookWnd::FinishMemorizing(int,int);
EQLIB_OBJECT void CSpellBookWnd::FinishScribing(int,int);
EQLIB_OBJECT void CSpellBookWnd::MemorizeSet(int *,int);
EQLIB_OBJECT void CSpellBookWnd::RequestSpellDeletion(int);
EQLIB_OBJECT void CSpellBookWnd::SwapSpellBookSlots(int,int);
EQLIB_OBJECT void CSpellBookWnd::TurnToPage(int);
// virtual
EQLIB_OBJECT CSpellBookWnd::~CSpellBookWnd(void);
EQLIB_OBJECT int CSpellBookWnd::Draw(void)const;
EQLIB_OBJECT int CSpellBookWnd::HandleKeyboardMsg(unsigned __int32,unsigned __int32,bool);
EQLIB_OBJECT int CSpellBookWnd::OnProcessFrame(void);
EQLIB_OBJECT int CSpellBookWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CSpellBookWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CSpellBookWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSpellBookWnd::Deactivate(void);
// private
EQLIB_OBJECT bool CSpellBookWnd::CanStartMemming(int);
EQLIB_OBJECT void CSpellBookWnd::ContinueSetMem(void);
EQLIB_OBJECT void CSpellBookWnd::DelayedSpellMem(int,int,int);
EQLIB_OBJECT void CSpellBookWnd::DisplaySpellInfo(int);
EQLIB_OBJECT void CSpellBookWnd::EndSetMem(void);
EQLIB_OBJECT void CSpellBookWnd::GetSpellDeletionConfirmation(int);
EQLIB_OBJECT void CSpellBookWnd::HandleLeftClickOnSpell(int);
EQLIB_OBJECT void CSpellBookWnd::HandleRightClickOnSpell(int);
EQLIB_OBJECT void CSpellBookWnd::HandleSpellInfoDisplay(class CXWnd *);
EQLIB_OBJECT void CSpellBookWnd::Init(void);
EQLIB_OBJECT void CSpellBookWnd::StartSpellMemorizationDrag(int,class CButtonWnd *);
EQLIB_OBJECT void CSpellBookWnd::StartSpellScribe(int);
EQLIB_OBJECT void CSpellBookWnd::StopSpellBookAction(void);
EQLIB_OBJECT void CSpellBookWnd::UpdateSpellBookDisplay(void);
};

class CSpellGemDrawTemplate
{
public:
EQLIB_OBJECT CSpellGemDrawTemplate::~CSpellGemDrawTemplate(void);
};

class CSpellGemTemplate
{
public:
EQLIB_OBJECT CSpellGemTemplate::CSpellGemTemplate(class CParamSpellGem *);
// virtual
EQLIB_OBJECT CSpellGemTemplate::~CSpellGemTemplate(void);
//EQLIB_OBJECT void * CSpellGemTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CSpellGemTemplate::`vector deleting destructor'(unsigned int);
};

class CSpellGemWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CSpellGemWnd::CSpellGemWnd(class CXWnd *,unsigned __int32,class CXRect,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,int,int,unsigned long);
EQLIB_OBJECT void CSpellGemWnd::SetCheck(bool);
EQLIB_OBJECT void CSpellGemWnd::SetGemTintStage(int);
EQLIB_OBJECT void CSpellGemWnd::SetSpellGemTint(unsigned long);
EQLIB_OBJECT void CSpellGemWnd::SetSpellIconIndex(int);
// virtual
EQLIB_OBJECT CSpellGemWnd::~CSpellGemWnd(void);
EQLIB_OBJECT int CSpellGemWnd::Draw(void)const;
EQLIB_OBJECT int CSpellGemWnd::HandleLButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSpellGemWnd::HandleLButtonHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSpellGemWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSpellGemWnd::HandleLButtonUpAfterHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSpellGemWnd::HandleRButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSpellGemWnd::HandleRButtonHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSpellGemWnd::HandleRButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSpellGemWnd::HandleRButtonUpAfterHeld(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CSpellGemWnd::OnProcessFrame(void);
//EQLIB_OBJECT void * CSpellGemWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CSpellGemWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CSpellGemWnd::SetAttributesFromSidl(class CParamScreenPiece *);
// protected
EQLIB_OBJECT void CSpellGemWnd::Init(void);
};

class CStaticAnimationTemplate
{
public:
EQLIB_OBJECT CStaticAnimationTemplate::CStaticAnimationTemplate(class CParamStaticAnimation *);
// virtual
EQLIB_OBJECT CStaticAnimationTemplate::~CStaticAnimationTemplate(void);
//EQLIB_OBJECT void * CStaticAnimationTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CStaticAnimationTemplate::`vector deleting destructor'(unsigned int);
};

class CStaticFrameTemplate
{
public:
EQLIB_OBJECT CStaticFrameTemplate::CStaticFrameTemplate(class CParamStaticFrame *);
// virtual
EQLIB_OBJECT CStaticFrameTemplate::~CStaticFrameTemplate(void);
//EQLIB_OBJECT void * CStaticFrameTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CStaticFrameTemplate::`vector deleting destructor'(unsigned int);
};

class CStaticHeaderTemplate
{
public:
EQLIB_OBJECT CStaticHeaderTemplate::CStaticHeaderTemplate(class CParamStaticHeader *);
// virtual
EQLIB_OBJECT CStaticHeaderTemplate::~CStaticHeaderTemplate(void);
//EQLIB_OBJECT void * CStaticHeaderTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CStaticHeaderTemplate::`vector deleting destructor'(unsigned int);
};

class CStaticScreenPieceTemplate
{
public:
EQLIB_OBJECT CStaticScreenPieceTemplate::CStaticScreenPieceTemplate(class CParamStaticScreenPiece *);
// virtual
EQLIB_OBJECT CStaticScreenPieceTemplate::~CStaticScreenPieceTemplate(void);
//EQLIB_OBJECT void * CStaticScreenPieceTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CStaticScreenPieceTemplate::`vector deleting destructor'(unsigned int);
};

class CStaticTextTemplate
{
public:
EQLIB_OBJECT CStaticTextTemplate::CStaticTextTemplate(class CParamStaticText *);
EQLIB_OBJECT class CXStr CStaticTextTemplate::SetText(class CXStr);
// virtual
EQLIB_OBJECT CStaticTextTemplate::~CStaticTextTemplate(void);
//EQLIB_OBJECT void * CStaticTextTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CStaticTextTemplate::`vector deleting destructor'(unsigned int);
};

class CSTMLboxTemplate
{
public:
EQLIB_OBJECT CSTMLboxTemplate::CSTMLboxTemplate(class CParamSTMLbox *);
// virtual
EQLIB_OBJECT CSTMLboxTemplate::~CSTMLboxTemplate(void);
//EQLIB_OBJECT void * CSTMLboxTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CSTMLboxTemplate::`vector deleting destructor'(unsigned int);
};

class CStmlReport
{
public:
EQLIB_OBJECT class CXStr CStmlReport::GetReport(void)const;
EQLIB_OBJECT static class CStmlReport * __cdecl CStmlReport::CreateReport(class CXStr);
// private
EQLIB_OBJECT static unsigned __int32 CStmlReport::LastID;
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
	unsigned __int32 MsgID;
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
	unsigned __int32 Style;
	int	Left;
	int	Right;
	PCXSTR Text;
	__int32	LinkID;
	CTextureAnimation *Texture;
	__int32 TableID;
	__int32 IndexStart;
};

struct STextLine
{
	ArrayClass_RO<_FormattedText> TextPieces;
	int yBottom;
	int yTop;
	__int32	IndexStart;
};

//size is 0x2b8 in sep 11 2017 test see 8DCF69 -eqmule
class CStmlWnd//ok Look... this SHOULD inherit CXWnd but doing so... calls the constructor, and we dont want that... so... : public CXWnd
{
public:
	//we include CXW instead...
/*0x000*/ CXW
/*0x1F0*/ PCXSTR STMLText;
/*0x1F4*/ CircularArrayClass2<STextLine> TextLines;//size 0x24
/*0x21c*/ __int32 TextTotalHeight;
/*0x220*/ __int32 TextTotalWidth;//0x220 see 8F5A6F in sep 11 2017 test - eqmule
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x224*/ __int32 Unknown0x224;//this value was first added in the apr 27 2017 test patch see 8EAB3B, timestamp related? heroic stuff? calendar? something... dont know - eqmule
#endif
/*0x228*/ ArrayClass2_RO<SLinkInfo> Links;//size 0x1c at 0x228 for sure see 8F4487 in Sep 11 2017 test - eqmule
/*0x244*/ ArrayClass_RO<STable>	Tables;
/*0x254*/ bool		bReparseNow;
/*0x255*/ bool		bResized;
/*0x256*/ bool		bAlignCenter;
/*0x258*/ int		LineSpacingAdjust;
/*0x25c*/ __int32	CapturedLinkID;
/*0x260*/ __int32	MousedOverLinkID;
/*0x264*/ COLORREF	BackGroundColor;
/*0x268*/ COLORREF	TextColor;
/*0x26c*/ COLORREF	LinkColor;
/*0x270*/ COLORREF	VLinkColor;
/*0x274*/ COLORREF	ALinkColor;
/*0x278*/ COLORREF	MLinkColor;
/*0x27c*/ eSTMLParseState	CurrentParseState;
/*0x280*/ ArrayClass2_RO<HistoryElement> HistoryArray;
/*0x29c*/ __int32		HistoryIndex;
/*0x2a0*/ CStmlReport	*pStmlReport;
/*0x2a4*/ int		MaxLines;
/*0x2a8*/ int		PlayerContextMenuIndex;
/*0x2ac*/ int		Unknown0x2ac;
/*0x2b0*/ int		Unknown0x2b0;
/*0x2b4*/ int		Unknown0x2b4;
/*0x2b8*/ 
EQLIB_OBJECT CStmlWnd::CStmlWnd(class CXWnd *,unsigned __int32,class CXRect);
EQLIB_OBJECT bool CStmlWnd::CanGoBackward(void);
EQLIB_OBJECT CXSize CStmlWnd::AppendSTML(CXStr); // lax 11-15-2003
EQLIB_OBJECT class CXStr CStmlWnd::GetSTMLText(void)const;
EQLIB_OBJECT class CXStr CStmlWnd::GetVisibleText(class CXStr&,class CXRect)const;
EQLIB_OBJECT static class CXStr __cdecl CStmlWnd::MakeStmlColorTag(unsigned long);
EQLIB_OBJECT static class CXStr __cdecl CStmlWnd::MakeWndNotificationTag(unsigned __int32,class CXStr&,class CXStr&);
EQLIB_OBJECT void CStmlWnd::ActivateLink(SLinkInfo);
EQLIB_OBJECT void CStmlWnd::ForceParseNow(void);
EQLIB_OBJECT void CStmlWnd::GoToBackHistoryLink(void);
//EQLIB_OBJECT void CStmlWnd::LoadPage(class CXStr,enum ESTMLTargetValue,bool);
EQLIB_OBJECT void CStmlWnd::SetSTMLText(class CXStr,bool,SLinkInfo *);
EQLIB_OBJECT void CStmlWnd::SetSTMLTextWithoutHistory(class CXStr);
// virtual
EQLIB_OBJECT CStmlWnd::~CStmlWnd(void);
EQLIB_OBJECT bool CStmlWnd::IsPointTransparent(class CXPoint)const;
EQLIB_OBJECT class CTextureAnimation * CStmlWnd::GetCursorToDisplay(void)const;
EQLIB_OBJECT int CStmlWnd::Draw(void)const;
EQLIB_OBJECT int CStmlWnd::HandleKeyboardMsg(unsigned __int32,unsigned __int32,bool);
EQLIB_OBJECT int CStmlWnd::HandleLButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CStmlWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CStmlWnd::HandleMouseMove(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CStmlWnd::OnHScroll(EScrollCode,int);
EQLIB_OBJECT int CStmlWnd::OnMove(class CXRect);
EQLIB_OBJECT int CStmlWnd::OnProcessFrame(void);
EQLIB_OBJECT int CStmlWnd::OnResize(int,int);
EQLIB_OBJECT int CStmlWnd::OnVScroll(EScrollCode,int);
//EQLIB_OBJECT void * CStmlWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CStmlWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CStmlWnd::SetWindowTextA(class CXStr);
// protected
EQLIB_OBJECT bool CStmlWnd::IsLinkActive(SLinkInfo)const;
EQLIB_OBJECT bool CStmlWnd::ParseAmpersand(class CXStr,char *)const;
EQLIB_OBJECT static bool __cdecl CStmlWnd::CanBreakAtCharacter(unsigned short);
EQLIB_OBJECT static bool __cdecl CStmlWnd::IsCharacterNotASpaceAndNotNULL(unsigned short);
EQLIB_OBJECT static bool __cdecl CStmlWnd::IsCharacterNotEquals(unsigned short);
EQLIB_OBJECT static bool __cdecl CStmlWnd::IsCharacterNotQuotes(unsigned short);
EQLIB_OBJECT unsigned short CStmlWnd::FastForwardPastQuotesAndGetNextTagPiece(class CXStr&,class CXStr *,int *,bool);
EQLIB_OBJECT unsigned short CStmlWnd::FastForwardPastSpaces(class CXStr&,int *);
EQLIB_OBJECT unsigned short CStmlWnd::FastForwardPastSpacesAndQuotes(class CXStr&,int *);
EQLIB_OBJECT unsigned short CStmlWnd::FastForwardToEndOfTag(class CXStr&,class CXStr *,int *,char);
EQLIB_OBJECT unsigned short CStmlWnd::GetNextChar(int *,class CXStr&);
EQLIB_OBJECT unsigned short CStmlWnd::GetNextTagPiece(class CXStr&,class CXStr *,int *,bool (__cdecl*)(unsigned short),bool);
EQLIB_OBJECT unsigned short CStmlWnd::GetThisChar(int,class CXStr&);
EQLIB_OBJECT void CStmlWnd::ActivateLinkFile(SLinkInfo);
EQLIB_OBJECT void CStmlWnd::ActivateLinkMessageId(SLinkInfo);
EQLIB_OBJECT void CStmlWnd::ActivateLinkReport(SLinkInfo,bool);
EQLIB_OBJECT void CStmlWnd::ActivateLinkWndNotify(SLinkInfo);
EQLIB_OBJECT void CStmlWnd::AddLinkToHistory(SLinkInfo,class CXStr);
EQLIB_OBJECT void CStmlWnd::AddTextPieceToLine(class SParseVariables *);
EQLIB_OBJECT void CStmlWnd::CalculateHSBRange(int);
EQLIB_OBJECT void CStmlWnd::CalculateVSBRange(int);
EQLIB_OBJECT void CStmlWnd::CompleteParse(void);
EQLIB_OBJECT void CStmlWnd::InitializeTempVariables(class SParseVariables *,class CXRect);
EQLIB_OBJECT void CStmlWnd::InitializeTextLine(class SParseVariables *,int);
EQLIB_OBJECT void CStmlWnd::InitializeWindowVariables(void);
//EQLIB_OBJECT void CStmlWnd::ParseLinkTarget(class CXStr,enum ESTMLTargetValue *)const;
EQLIB_OBJECT void CStmlWnd::ParseSTMLHead(class CXStr&);
EQLIB_OBJECT void CStmlWnd::ParseSTMLTable(class CXStr&,int *,class CXStr,class SParseVariables *);
EQLIB_OBJECT void CStmlWnd::ParseSTMLTableAttributes(class CXStr&,class STable *);
//EQLIB_OBJECT void CStmlWnd::ParseTagAlign(class CXStr,enum ESTMLAlign *)const;
EQLIB_OBJECT void CStmlWnd::ParseTagColor(class CXStr&,unsigned long *)const;
EQLIB_OBJECT void CStmlWnd::ParseTagFace(class CXStr&,class CTextureFont const * *)const;
EQLIB_OBJECT void CStmlWnd::ResetTempVariablesForNewLine(class SParseVariables *);
EQLIB_OBJECT void CStmlWnd::StripFirstSTMLLines(int);
EQLIB_OBJECT void CStmlWnd::UpdateHistoryString(__int32,class CXStr&);
};

class CStoryWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CStoryWnd::CStoryWnd(class CXWnd *);
EQLIB_OBJECT bool CStoryWnd::HasNew(void);
EQLIB_OBJECT bool CStoryWnd::ShowAuto(void);
EQLIB_OBJECT void CStoryWnd::Activate(void);
EQLIB_OBJECT void CStoryWnd::SaveIni(void);
// virtual
EQLIB_OBJECT CStoryWnd::~CStoryWnd(void);
EQLIB_OBJECT int CStoryWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CStoryWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CStoryWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CStoryWnd::Deactivate(void);
EQLIB_OBJECT void CStoryWnd::LoadIniInfo(void);
// protected
EQLIB_OBJECT void CStoryWnd::SelectIndex(int);
EQLIB_OBJECT void CStoryWnd::SelectOldestNew(void);
// private
EQLIB_OBJECT void CStoryWnd::Init(void);
};

class CTabBoxTemplate
{
public:
EQLIB_OBJECT CTabBoxTemplate::CTabBoxTemplate(class CParamTabBox *);
// virtual
EQLIB_OBJECT CTabBoxTemplate::~CTabBoxTemplate(void);
//EQLIB_OBJECT void * CTabBoxTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CTabBoxTemplate::`vector deleting destructor'(unsigned int);
};

class CTabWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTabWnd::CTabWnd(CXWnd *pParent, UINT uId, RECT *rect, CTabBoxTemplate *pTabContents);
EQLIB_OBJECT class CPageWnd * CTabWnd::GetCurrentPage(void)const;
EQLIB_OBJECT class CXRect CTabWnd::GetPageClientRect(void)const;
EQLIB_OBJECT class CXRect CTabWnd::GetPageInnerRect(void)const;
EQLIB_OBJECT class CXRect CTabWnd::GetTabInnerRect(int)const;
EQLIB_OBJECT class CXRect CTabWnd::GetTabRect(int)const;
EQLIB_OBJECT int CTabWnd::GetCurrentTabIndex(void)const;
EQLIB_OBJECT int CTabWnd::GetNumTabs(void)const;
EQLIB_OBJECT void CTabWnd::InsertPage(class CPageWnd *,int);
EQLIB_OBJECT void CTabWnd::SetPage(class CPageWnd *,bool);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT void CTabWnd::SetPage(int,bool,bool = true);
#else
EQLIB_OBJECT void CTabWnd::SetPage(int,bool);
#endif
EQLIB_OBJECT void CTabWnd::SetPageRect(class CXRect);
EQLIB_OBJECT void CTabWnd::UpdatePage(void);
// virtual
EQLIB_OBJECT CTabWnd::~CTabWnd(void);
EQLIB_OBJECT int CTabWnd::Draw(void)const;
EQLIB_OBJECT int CTabWnd::DrawTooltip(class CXWnd const *);
EQLIB_OBJECT int CTabWnd::HandleLButtonDown(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CTabWnd::HandleLButtonUp(class CXPoint,unsigned __int32);
EQLIB_OBJECT int CTabWnd::OnResize(int,int);
EQLIB_OBJECT int CTabWnd::OnShow(void);
//EQLIB_OBJECT void * CTabWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CTabWnd::`vector deleting destructor'(unsigned int);
// private
EQLIB_OBJECT bool CTabWnd::IndexInBounds(int)const;
EQLIB_OBJECT CPageWnd * CTabWnd::GetPageFromTabIndex(int)const;
EQLIB_OBJECT CPageWnd * CTabWnd::GetPageFromTabPoint(class CXPoint)const;
EQLIB_OBJECT int CTabWnd::DrawCurrentPage(void)const;
EQLIB_OBJECT int CTabWnd::DrawTab(int)const;
};

class CTAFrameDraw
{
public:
EQLIB_OBJECT CTAFrameDraw::~CTAFrameDraw(void);
EQLIB_OBJECT CTAFrameDraw::CTAFrameDraw(class CTAFrameDraw const &);
EQLIB_OBJECT CTAFrameDraw::CTAFrameDraw(class CXStr);
EQLIB_OBJECT bool CTAFrameDraw::IsHorizontal(void)const;
EQLIB_OBJECT bool CTAFrameDraw::IsVertical(void)const;
EQLIB_OBJECT class CTAFrameDraw & CTAFrameDraw::operator=(class CTAFrameDraw const &);
EQLIB_OBJECT class CTextureAnimation * CTAFrameDraw::GetAnimation(int)const;
EQLIB_OBJECT class CXRect CTAFrameDraw::GetHitTestRect(class CXRect,int)const;
EQLIB_OBJECT class CXRect CTAFrameDraw::GetInnerRect(class CXRect)const;
EQLIB_OBJECT class CXRect CTAFrameDraw::GetPieceRect(class CXRect,int)const;
EQLIB_OBJECT class CXSize CTAFrameDraw::GetFrameSize(void)const;
EQLIB_OBJECT class CXStr CTAFrameDraw::GetName(void)const;
EQLIB_OBJECT int CTAFrameDraw::Draw(class CXRect,class CXRect)const;
EQLIB_OBJECT int CTAFrameDraw::Draw(class CXRect,class CXRect,int)const;
EQLIB_OBJECT int CTAFrameDraw::GetExtent(void)const;
EQLIB_OBJECT int CTAFrameDraw::GetMinLength(void)const;
EQLIB_OBJECT void CTAFrameDraw::Set(class CTextureAnimation * * const);
};

class CTargetManager
{
public:
EQLIB_OBJECT void CTargetManager::Update(void);
};

class CTargetRing
{
public:
EQLIB_OBJECT int CTargetRing::Cast(CVector3 *pos);
/*0x00*/	DWORD Gem;//the gem the spell below is memmed in... 0-11
/*0x04*/	PSPELL thespell;
/*0x08*/	ItemGlobalIndex ItemLoc;//size 0xc
/*0x14*/	ItemSpellTypes SpellType;
/*0x18*/	FLOAT SquaredRange;
/*0x1c*/	bool bCursorVisible;
/*0x20*/
};

class CTargetWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTargetWnd::CTargetWnd(class CXWnd *);
EQLIB_OBJECT void CTargetWnd::Activate(void);
// virtual
EQLIB_OBJECT CTargetWnd::~CTargetWnd(void);
EQLIB_OBJECT class CXStr *CTargetWnd::GetBuffCaster(int SpellID);
EQLIB_OBJECT int CTargetWnd::OnProcessFrame(void);
//EQLIB_OBJECT void * CTargetWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CTargetWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTargetWnd::Deactivate(void);
// private
EQLIB_OBJECT void CTargetWnd::Init(void);
EQLIB_OBJECT void CTargetWnd::RefreshTargetBuffs(PBYTE buffer);
EQLIB_OBJECT void CTargetWnd::HandleBuffRemoveRequest(CXWnd *pWnd);
};

class CTaskWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTaskWnd::CTaskWnd(class CXWnd *);
EQLIB_OBJECT int CTaskWnd::UpdateTaskTimers(unsigned long fasttime);
// virtual
EQLIB_OBJECT CTaskWnd::~CTaskWnd(void);
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
} CTaskElement, *PCTaskElement;
typedef struct _CTaskEntry
{
/*0x0000*/ int TaskID;
/*0x0004*/ FLOAT RewardAdjustment;
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
/*0x100C*/ CTaskElement Elements[0x14];//0x168 * 0x14 = 0x1C20
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
	_SharedTaskClientPlayerInfo *pNext;
}SharedTaskClientPlayerInfo,*PSharedTaskClientPlayerInfo;

class CTaskManager// : public PopDialogHandler /*0x000000*/ 
{
public:
/*0x000000*/ PVOID vfTable;
/*0x000004*/ CTaskEntry TaskEntries[1];
/*0x003BF4*/ CTaskEntry QuestEntries[0x1d];//see 51B93B 0x1d * 0x3BF0 = 0x6CA30
/*0x070624*/ CTaskEntry SharedTaskEntries[1];
/*0x074214*/ CTaskEntry QuestHistoryEntries[0x32];
/*0x12F6F4*/ int AddPlayerID;
/*0x12F6F8*/ bool bAddPlayerIsSwap;
/*0x12F6FC*/ CHAR AddPlayerSwapeeName[0x40];
/*0x12F73C*/ SharedTaskClientPlayerInfo *pFirstMember;//51B9D8
/*0x12F740*/
EQLIB_OBJECT CTaskManager::CTaskManager(class CXWnd *);
// virtual
EQLIB_OBJECT CTaskManager::~CTaskManager(void);
EQLIB_OBJECT CTaskEntry *CTaskManager::GetEntry(int Index, int System, bool bCheckEmpty = true);
};
class CTextEntryWnd : public CEditBaseWnd
{
public:
EQLIB_OBJECT void CTextEntryWnd::Open(CXWnd *pwnd, int EditMode, char *Prompt, int MinLength, int MaxLength, const char *InitialText);
EQLIB_OBJECT CTextEntryWnd::CTextEntryWnd(class CXWnd *);
EQLIB_OBJECT class CXStr CTextEntryWnd::GetEntryText(void);
EQLIB_OBJECT void CTextEntryWnd::Activate(class CXWnd *,int,char *,int,int,char *);
EQLIB_OBJECT void CTextEntryWnd::Callback(bool);
// virtual
EQLIB_OBJECT CTextEntryWnd::~CTextEntryWnd(void);
EQLIB_OBJECT int CTextEntryWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CTextEntryWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CTextEntryWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTextEntryWnd::Deactivate(void);
// private
EQLIB_OBJECT void CTextEntryWnd::UpdateButtons(void);

/*0x148*///    DWORD Unknown0x148;
/*0x14C*/// DWORD Unknown0x14c;
/*0x150*/// PCXSTR Data;
/*0x154*/// DWORD Unknown0x154;
/*0x158*/// CSidlScreenWnd *Entry;
/*0x15c*/// CSidlScreenWnd *Prompt;
/*0x160*/// CSidlScreenWnd *OK;
/*0x164*/// CSidlScreenWnd *Cancel;
};

class CUITexturePiece
{
public:
	CUITextureInfo2 TInfo;
    RECT Rect;
EQLIB_OBJECT CUITexturePiece::~CUITexturePiece(void);
EQLIB_OBJECT CUITexturePiece::CUITexturePiece(class CUITexturePiece const &);
EQLIB_OBJECT CUITexturePiece::CUITexturePiece(class CUITextureInfo,class CXRect);
EQLIB_OBJECT CUITexturePiece::CUITexturePiece(void);
EQLIB_OBJECT class CUITexturePiece & CUITexturePiece::operator=(class CUITexturePiece const &);
EQLIB_OBJECT int CUITexturePiece::Draw(class CXRect,class CXRect,class CXRect,unsigned long,unsigned long)const;
EQLIB_OBJECT int CUITexturePiece::Draw(class CXRect,class CXRect,unsigned long,unsigned long)const;
};

struct STextureAnimationFrame
{
    CUITexturePiece TPiece;
    unsigned __int32 Ticks;
    POINT Hotspot;
};
class CTextureAnimation
{
public:
	PVOID vfTable;
	PCXSTR Name;
    ArrayClass_RO<STextureAnimationFrame> Frames;

EQLIB_OBJECT CTextureAnimation::CTextureAnimation(class CXStr);
EQLIB_OBJECT CTextureAnimation::CTextureAnimation(void);
EQLIB_OBJECT class CTextureAnimation & CTextureAnimation::operator=(class CTextureAnimation const &);
EQLIB_OBJECT class CXPoint CTextureAnimation::GetHotspot(void)const;
EQLIB_OBJECT class CXStr CTextureAnimation::GetName(void)const;
EQLIB_OBJECT int CTextureAnimation::AddBlankFrame(unsigned __int32,class CXPoint);
EQLIB_OBJECT int CTextureAnimation::AddFrame(class CUITexturePiece,unsigned __int32,class CXPoint);
EQLIB_OBJECT int CTextureAnimation::AddFrame(class CUITextureInfo const *,class CXRect,unsigned __int32,class CXPoint);
EQLIB_OBJECT int CTextureAnimation::Draw(class CXPoint,class CXRect,unsigned long,unsigned long)const;
EQLIB_OBJECT int CTextureAnimation::Draw(class CXRect,class CXRect,unsigned long,unsigned long)const;
EQLIB_OBJECT int CTextureAnimation::GetCurFrame(void)const;
EQLIB_OBJECT int CTextureAnimation::Preload(void);
EQLIB_OBJECT void CTextureAnimation::Reset(void);
EQLIB_OBJECT void CTextureAnimation::SetCurCell(int);
EQLIB_OBJECT void CTextureAnimation::SetCurFrame(int);
// virtual
EQLIB_OBJECT CTextureAnimation::~CTextureAnimation(void);
//EQLIB_OBJECT void * CTextureAnimation::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CTextureAnimation::`vector deleting destructor'(unsigned int);
// protected
EQLIB_OBJECT static unsigned __int32 CTextureAnimation::MaxID;
};

class CTextureFont
{
public:
EQLIB_OBJECT class CXStr CTextureFont::GetName(void)const;
EQLIB_OBJECT int CTextureFont::DrawWrappedText(class CXStr,class CXRect,class CXRect,unsigned long,unsigned short,int)const;
EQLIB_OBJECT int CTextureFont::DrawWrappedText(CXStr *Str, int x, int y, int Width, CXRect *BoundRect, COLORREF Color, WORD Flags = 0, int StartX = 0)const;
EQLIB_OBJECT int CTextureFont::GetHeight(void)const;
EQLIB_OBJECT int CTextureFont::GetKerning(unsigned short,unsigned short)const;
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT int CTextureFont::GetTextExtent(CXStr *);
#else
EQLIB_OBJECT int CTextureFont::GetTextExtent(void);
#endif
EQLIB_OBJECT int CTextureFont::GetWidth(unsigned short)const;
// virtual
EQLIB_OBJECT CTextureFont::~CTextureFont(void);
//EQLIB_OBJECT void * CTextureFont::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CTextureFont::`vector deleting destructor'(unsigned int);
void  *vftable;
DWORD FontStyle;
};

class CTimeLeftWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTimeLeftWnd::CTimeLeftWnd(long);
EQLIB_OBJECT void CTimeLeftWnd::Activate(void);
// virtual
EQLIB_OBJECT CTimeLeftWnd::~CTimeLeftWnd(void);
EQLIB_OBJECT int CTimeLeftWnd::Draw(void)const;
EQLIB_OBJECT int CTimeLeftWnd::OnProcessFrame(void);
//EQLIB_OBJECT void * CTimeLeftWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CTimeLeftWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTimeLeftWnd::Deactivate(void);
};

class CTipWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTipWnd::CTipWnd(class CXWnd *,int);
EQLIB_OBJECT bool CTipWnd::Activate(int,bool);
EQLIB_OBJECT void CTipWnd::InitializeTipSettings(void);
EQLIB_OBJECT void CTipWnd::UpdateButtons(void);
// virtual
EQLIB_OBJECT CTipWnd::~CTipWnd(void);
EQLIB_OBJECT int CTipWnd::OnProcessFrame(void);
EQLIB_OBJECT int CTipWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CTipWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CTipWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTipWnd::Deactivate(void);
// protected
EQLIB_OBJECT bool CTipWnd::IsRecentTOTD(int);
EQLIB_OBJECT int CTipWnd::SelectRandomTip(void);
EQLIB_OBJECT void CTipWnd::AddContextTip(int);
EQLIB_OBJECT void CTipWnd::LoadINISettings(void);
EQLIB_OBJECT void CTipWnd::SetTOTD(int);
EQLIB_OBJECT void CTipWnd::ShowHistoryTip(int);
// private
EQLIB_OBJECT void CTipWnd::CleanDayTips(void);
EQLIB_OBJECT void CTipWnd::LoadDayTips(void);
};

class CTokenXML
{
public:
EQLIB_OBJECT CTokenXML::~CTokenXML(void);
};

class CTrackingWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTrackingWnd::CTrackingWnd(class CXWnd *);
EQLIB_OBJECT void CTrackingWnd::Activate(void);
EQLIB_OBJECT void CTrackingWnd::DoTrackFilter(bool);
EQLIB_OBJECT void CTrackingWnd::DoTrackSort(bool);
EQLIB_OBJECT void CTrackingWnd::RemovePlayerFromTracking(class EQPlayer *);
EQLIB_OBJECT void CTrackingWnd::SetTrackingList(struct TrackingHit *,int);
// virtual
EQLIB_OBJECT CTrackingWnd::~CTrackingWnd(void);
EQLIB_OBJECT int CTrackingWnd::Draw(void)const;
EQLIB_OBJECT int CTrackingWnd::OnProcessFrame(void);
EQLIB_OBJECT int CTrackingWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CTrackingWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CTrackingWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTrackingWnd::Deactivate(void);
// private
EQLIB_OBJECT int CTrackingWnd::GetListIdByData(unsigned int);
EQLIB_OBJECT unsigned long CTrackingWnd::GetTrackColor(int);
EQLIB_OBJECT void CTrackingWnd::GenerateTrackingList(void);
EQLIB_OBJECT void CTrackingWnd::Init(void);
EQLIB_OBJECT void CTrackingWnd::NotifyServerOfTrackingTarget(int);
EQLIB_OBJECT void CTrackingWnd::RemoveFromListWndByData(unsigned int);
EQLIB_OBJECT void CTrackingWnd::RemovePlayerFromTracking(int);
EQLIB_OBJECT void CTrackingWnd::UpdateTrackingControls(void);
EQLIB_OBJECT void CTrackingWnd::UpdateTrackingList(bool);
};

class CTradeWnd : public CSidlScreenWnd, public WndEventHandler2
{
public:
	UINT NextRefreshTime;
	bool bInventoryWasOpen;
    CButtonWnd *HisMoneyButton[4];
    CButtonWnd *MyMoneyButton[4];
    CButtonWnd *TradeButton;
    CButtonWnd *CancelButton;
	CLabel *HisNameLabel;
	CLabel *MyNameLabel;
	CInvSlotWnd *pInvSlotWnd[16];
	long HisMoney[4];
	long MyMoney[4];
	ItemBaseContainer TradeItems;//16 items
	bool bHisReadyTrade;
	bool bMyReadyTrade;
	bool bIsTrading;

EQLIB_OBJECT CTradeWnd::CTradeWnd(class CXWnd *);
EQLIB_OBJECT bool CTradeWnd::IsMyTradeSlot(int,bool *);
EQLIB_OBJECT void CTradeWnd::Activate(class EQPlayer *,bool);
EQLIB_OBJECT void CTradeWnd::AddContainerToHisTradeArray(class EQ_Container *);
EQLIB_OBJECT void CTradeWnd::AddEquipmentToHisTradeArray(class EQ_Equipment *);
EQLIB_OBJECT void CTradeWnd::AddNoteToHisTradeArray(class EQ_Note *);
EQLIB_OBJECT void CTradeWnd::ClickedCancelButton(void);
EQLIB_OBJECT void CTradeWnd::ClickedMoneyButton(int);
EQLIB_OBJECT void CTradeWnd::ClickedTradeButton(void);
EQLIB_OBJECT void CTradeWnd::CompleteTrade(void);
EQLIB_OBJECT void CTradeWnd::DeleteItemFromHisTradeArray(int);
EQLIB_OBJECT void CTradeWnd::DropItemIntoTrade(void);
EQLIB_OBJECT void CTradeWnd::SetHisMoney(int,long);
EQLIB_OBJECT void CTradeWnd::SetHisReadyTrade(bool);
EQLIB_OBJECT void CTradeWnd::SetMyReadyTrade(bool);
EQLIB_OBJECT void CTradeWnd::TradeItemChanged(int,int);
// virtual
EQLIB_OBJECT CTradeWnd::~CTradeWnd(void);
EQLIB_OBJECT int CTradeWnd::OnProcessFrame(void);
EQLIB_OBJECT int CTradeWnd::PostDraw(void)const;
EQLIB_OBJECT int CTradeWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CTradeWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CTradeWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTradeWnd::Deactivate(void);
// private
EQLIB_OBJECT void CTradeWnd::Init(void);
EQLIB_OBJECT void CTradeWnd::UpdateTradeDisplay(void);
};

class CTrainWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTrainWnd::CTrainWnd(class CXWnd *);
EQLIB_OBJECT void CTrainWnd::SetGMData(int *,unsigned char *,float);
EQLIB_OBJECT void CTrainWnd::SkillChanged(int);
// virtual
EQLIB_OBJECT CTrainWnd::~CTrainWnd(void);
EQLIB_OBJECT int CTrainWnd::OnProcessFrame(void);
EQLIB_OBJECT int CTrainWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CTrainWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CTrainWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CTrainWnd::Deactivate(void);
// protected
EQLIB_OBJECT char * CTrainWnd::SkillName(int);
EQLIB_OBJECT int CTrainWnd::SkillValue(int);
EQLIB_OBJECT void CTrainWnd::Activate(void);
EQLIB_OBJECT void CTrainWnd::SortNames(int);
EQLIB_OBJECT void CTrainWnd::SortSkill(int);
EQLIB_OBJECT void CTrainWnd::SwapSkill(int,int);
EQLIB_OBJECT void CTrainWnd::Train(void);
EQLIB_OBJECT void CTrainWnd::UpdateAll(bool);
EQLIB_OBJECT void CTrainWnd::UpdateRight(void);
EQLIB_OBJECT void CTrainWnd::UpdateSkill(int);
};

class CTreeView : public CListWnd
{
public:
EQLIB_OBJECT CTreeView::CTreeView(class CXWnd *,unsigned __int32,class CXRect,int);
// virtual
EQLIB_OBJECT CTreeView::~CTreeView(void);
};

class CVideoModesWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CVideoModesWnd::CVideoModesWnd(class CXWnd *);
EQLIB_OBJECT void CVideoModesWnd::Activate(void);
EQLIB_OBJECT void CVideoModesWnd::RestoreOldMode(void);
EQLIB_OBJECT void CVideoModesWnd::Update(void);
// virtual
EQLIB_OBJECT CVideoModesWnd::~CVideoModesWnd(void);
EQLIB_OBJECT int CVideoModesWnd::Draw(void)const;
EQLIB_OBJECT int CVideoModesWnd::OnProcessFrame(void);
EQLIB_OBJECT int CVideoModesWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CVideoModesWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CVideoModesWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CVideoModesWnd::Deactivate(void);
// private
EQLIB_OBJECT void CVideoModesWnd::Init(void);
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
EQLIB_OBJECT void NotifyObservers(CNotification *Notification = 0)
{

	Sleep(0);
}

private:
	std::list<IObserver*> ObserverList;
};
class IObserver
{
public:
	//EQLIB_OBJECT virtual void IObserver::Notify(CObservable *Src, const CNotification* const Notification) = 0;
};
class Window
{
public:
	EQLIB_OBJECT float Window::getProgress(bool &bIsLoading);
	EQLIB_OBJECT const wchar_t *Window::getStatus() const;
	EQLIB_OBJECT const char *Window::getURI() const;
};
class CHtmlComponentWnd //: public CXWnd, public mozilla::ICallback, public CObservable
{
public:
	CXW;
};
class CHtmlWnd : public CSidlScreenWnd, public TListNode<CHtmlWnd>
{
public:
	EQLIB_OBJECT void CHtmlWnd::SetClientCallbacks(void* cb);
	EQLIB_OBJECT void CHtmlWnd::AddObserver(IObserver *Observer);
	EQLIB_OBJECT void CHtmlWnd::RemoveObserver(IObserver *Observer);
	CHtmlComponentWnd* pHtmlComponentMain;
	CButtonWnd* pBackBtn;
	CButtonWnd* pForwardBtn;
	CGaugeWnd* pProgressGauge;
	CLabelWnd* pStatusLabel;
	CXStr *WindowID;
};

class CWebManager
{
public:
EQLIB_OBJECT CHtmlWnd* CWebManager::CreateHtmlWnd(const char*Url, const char* IDString, const char* PostString= NULL, bool bBypasFilter = false, const char*OverrideTitle = NULL);
};

class CXFileXML
{
public:
EQLIB_OBJECT CXFileXML::~CXFileXML(void);
EQLIB_OBJECT bool CXFileXML::Load(char *);
};

class CXMLData
{
public:
EQLIB_OBJECT CXMLData::CXMLData(void);
EQLIB_OBJECT class CXMLData & CXMLData::operator=(class CXMLData const &);
// virtual
EQLIB_OBJECT CXMLData::~CXMLData(void);
EQLIB_OBJECT bool CXMLData::ReadFromXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT bool CXMLData::WriteToXMLSOM(class CXMLSOMDocument &);
EQLIB_OBJECT int CXMLData::GetStreamSize(void);
//EQLIB_OBJECT void * CXMLData::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CXMLData::`vector deleting destructor'(unsigned int);
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
EQLIB_OBJECT CXMLDataClass::~CXMLDataClass(void);
EQLIB_OBJECT CXMLDataClass::CXMLDataClass(void);
EQLIB_OBJECT int CXMLDataClass::GetNumLeaf(void);
EQLIB_OBJECT int CXMLDataClass::GetStreamSize(void);
//EQLIB_OBJECT void * CXMLDataClass::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CXMLDataClass::ReadFromStream(class CMemoryStream &,class CXMLDataManager &);
EQLIB_OBJECT void CXMLDataClass::WriteToStream(class CMemoryStream &);
};

class CXMLDataPtr
{
public:
EQLIB_OBJECT CXMLDataPtr::CXMLDataPtr(void);
EQLIB_OBJECT class CXMLDataPtr & CXMLDataPtr::operator=(class CXMLDataPtr const &);
EQLIB_OBJECT void CXMLDataPtr::SetNewPtr(class CXMLData *);
// virtual
EQLIB_OBJECT CXMLDataPtr::~CXMLDataPtr(void);
//EQLIB_OBJECT void * CXMLDataPtr::`vector deleting destructor'(unsigned int);
// protected
EQLIB_OBJECT class CXMLData * CXMLDataPtr::AllocPtr(class CXMLDataPtr &,int,class CXMLData const *);
EQLIB_OBJECT void CXMLDataPtr::Free(void);
};

class CXMLEnumInfo
{
public:
EQLIB_OBJECT CXMLEnumInfo::~CXMLEnumInfo(void);
EQLIB_OBJECT CXMLEnumInfo::CXMLEnumInfo(void);
EQLIB_OBJECT int CXMLEnumInfo::GetStreamSize(void);
EQLIB_OBJECT void CXMLEnumInfo::ReadFromStream(class CMemoryStream &);
EQLIB_OBJECT void CXMLEnumInfo::WriteToStream(class CMemoryStream &);
};

class CXMLSOMAttribute
{
public:
EQLIB_OBJECT CXMLSOMAttribute::~CXMLSOMAttribute(void);
EQLIB_OBJECT CXMLSOMAttribute::CXMLSOMAttribute(void);
EQLIB_OBJECT class CXMLSOMAttribute & CXMLSOMAttribute::operator=(class CXMLSOMAttribute const &);
//EQLIB_OBJECT void * CXMLSOMAttribute::`vector deleting destructor'(unsigned int);
};

class CXMLSOMAttributeType
{
public:
EQLIB_OBJECT CXMLSOMAttributeType::~CXMLSOMAttributeType(void);
EQLIB_OBJECT CXMLSOMAttributeType::CXMLSOMAttributeType(void);
EQLIB_OBJECT class CXMLSOMAttributeType & CXMLSOMAttributeType::operator=(class CXMLSOMAttributeType const &);
//EQLIB_OBJECT void * CXMLSOMAttributeType::`vector deleting destructor'(unsigned int);
};

class CXMLSOMCursor
{
public:
EQLIB_OBJECT CXMLSOMCursor::~CXMLSOMCursor(void);
EQLIB_OBJECT CXMLSOMCursor::CXMLSOMCursor(void);
EQLIB_OBJECT class CXMLSOMCursor & CXMLSOMCursor::operator=(class CXMLSOMCursor const &);
//EQLIB_OBJECT void * CXMLSOMCursor::`vector deleting destructor'(unsigned int);
};

class CXMLSOMCursorSave
{
public:
EQLIB_OBJECT CXMLSOMCursorSave::~CXMLSOMCursorSave(void);
};

class CXMLSOMCursorSaveFast
{
public:
EQLIB_OBJECT CXMLSOMCursorSaveFast::~CXMLSOMCursorSaveFast(void);
};

class CXMLSOMCursorTraverseChildren
{
public:
EQLIB_OBJECT CXMLSOMCursorTraverseChildren::~CXMLSOMCursorTraverseChildren(void);
EQLIB_OBJECT class CXMLSOMCursor & CXMLSOMCursorTraverseChildren::Cursor(void);
};

class CXMLSOMDocument
{
public:
EQLIB_OBJECT bool CXMLSOMDocument::FieldParseItemOfClass(class CXStr,class CXStr,unsigned __int32 &);
EQLIB_OBJECT bool CXMLSOMDocument::GetValueObjectId(class CXStr,class CXStr,unsigned __int32 &);
EQLIB_OBJECT bool CXMLSOMDocument::SetValueObjectId(class CXStr,class CXStr,unsigned __int32);
// virtual
EQLIB_OBJECT CXMLSOMDocument::~CXMLSOMDocument(void);
//EQLIB_OBJECT void * CXMLSOMDocument::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CXMLSOMDocument::`vector deleting destructor'(unsigned int);
};

class CXMLSOMDocumentBase
{
public:
EQLIB_OBJECT bool CXMLSOMDocumentBase::CursorFieldFind(class CXStr);
EQLIB_OBJECT bool CXMLSOMDocumentBase::CursorFind(class CXStr);
EQLIB_OBJECT bool CXMLSOMDocumentBase::CursorNextInOrder(void);
EQLIB_OBJECT bool CXMLSOMDocumentBase::CursorNextSibling(void);
EQLIB_OBJECT bool CXMLSOMDocumentBase::CursorPop(void);
EQLIB_OBJECT bool CXMLSOMDocumentBase::CursorPush(void);
EQLIB_OBJECT bool CXMLSOMDocumentBase::FieldParseClassItem(class CXStr,class CXStr &,class CXStr &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::FieldParseItemOfClass(class CXStr,class CXStr,__int32 &,__int32 &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::GetAttrValueInt(class CXStr,__int32 &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::GetAttrValueStr(class CXStr,class CXStr &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::GetValue(class CXStr,__int32 &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::GetValue(class CXStr,bool &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::GetValue(class CXStr,class CXStr &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::SetValue(class CXStr,__int32);
EQLIB_OBJECT bool CXMLSOMDocumentBase::SetValue(class CXStr,bool);
EQLIB_OBJECT bool CXMLSOMDocumentBase::SetValue(class CXStr,class CXStr);
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateData(void);
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchema(void);
EQLIB_OBJECT bool CXMLSOMDocumentBase::XMLMerge(class CXMLSOMDocumentBase &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::XMLRead(class CXStr*,class CXStr*,class CXStr*);
EQLIB_OBJECT class CXMLSOMCursor & CXMLSOMDocumentBase::Cursor(void);
EQLIB_OBJECT class CXMLSOMCursor & CXMLSOMDocumentBase::CursorParent(void);
EQLIB_OBJECT class CXStr CXMLSOMDocumentBase::GetAttrValueStr(class CXStr);
EQLIB_OBJECT class CXStr CXMLSOMDocumentBase::GetErrorMsg(void)const;
EQLIB_OBJECT int CXMLSOMDocumentBase::XMLReadNoValidate(class CXStr,class CXStr,class CXStr);
EQLIB_OBJECT void CXMLSOMDocumentBase::CursorInit(void);
EQLIB_OBJECT void CXMLSOMDocumentBase::CursorNewChild(void);
EQLIB_OBJECT void CXMLSOMDocumentBase::CursorNewSibling(void);
EQLIB_OBJECT void CXMLSOMDocumentBase::CursorSetPtr(class CXMLSOMNodePtr);
EQLIB_OBJECT void CXMLSOMDocumentBase::Init(void);
EQLIB_OBJECT void CXMLSOMDocumentBase::SetErrorMsg(class CXStr);
EQLIB_OBJECT void CXMLSOMDocumentBase::SetErrorMsgAtCursor(class CXStr);
EQLIB_OBJECT void CXMLSOMDocumentBase::SetErrorMsgAtLine(class CXStr,int,class CXStr);
// virtual
EQLIB_OBJECT CXMLSOMDocumentBase::~CXMLSOMDocumentBase(void);
//EQLIB_OBJECT void * CXMLSOMDocumentBase::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CXMLSOMDocumentBase::`vector deleting destructor'(unsigned int);
// protected
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateDataElements(class CXMLSOMElementType &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchemaCategories(void);
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchemaDefinition(void);
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchemaElementType(void);
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchemaSimpleType(void);
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchemaSimpleTypeNode(class CXMLSOMSimpleType &);
EQLIB_OBJECT bool CXMLSOMDocumentBase::ValidateSchemaTypeRefs(void);
EQLIB_OBJECT bool CXMLSOMDocumentBase::XMLProcessComposite(class CXStr,class CXStr);
};

class CXMLSOMElement
{
public:
EQLIB_OBJECT CXMLSOMElement::~CXMLSOMElement(void);
EQLIB_OBJECT CXMLSOMElement::CXMLSOMElement(void);
EQLIB_OBJECT class CXMLSOMElement & CXMLSOMElement::operator=(class CXMLSOMElement const &);
//EQLIB_OBJECT void * CXMLSOMElement::`vector deleting destructor'(unsigned int);
};

class CXMLSOMElementType
{
public:
EQLIB_OBJECT CXMLSOMElementType::~CXMLSOMElementType(void);
EQLIB_OBJECT CXMLSOMElementType::CXMLSOMElementType(void);
EQLIB_OBJECT int CXMLSOMElementType::GetItemIdx(class CXStr);
//EQLIB_OBJECT void * CXMLSOMElementType::`vector deleting destructor'(unsigned int);
};

class CXMLSOMNode
{
public:
EQLIB_OBJECT static void * __cdecl CXMLSOMNode::operator new(unsigned int);
EQLIB_OBJECT static void __cdecl CXMLSOMNode::FreeAllAllocs(void);
EQLIB_OBJECT static void __cdecl CXMLSOMNode::operator delete(void *);
// protected
EQLIB_OBJECT static char * * CXMLSOMNode::pAllAlloc;
EQLIB_OBJECT static class CMutexSync CXMLSOMNode::mutexAccess;
EQLIB_OBJECT static class CXMLSOMNode * CXMLSOMNode::pFreeHead;
// private
EQLIB_OBJECT CXMLSOMNode::~CXMLSOMNode(void);
EQLIB_OBJECT CXMLSOMNode::CXMLSOMNode(void);
//EQLIB_OBJECT void * CXMLSOMNode::`scalar deleting destructor'(unsigned int);
};

class CXMLSOMNodePtr
{
public:
EQLIB_OBJECT CXMLSOMNodePtr::~CXMLSOMNodePtr(void);
EQLIB_OBJECT CXMLSOMNodePtr::CXMLSOMNodePtr(void);
EQLIB_OBJECT class CXMLSOMNode * CXMLSOMNodePtr::operator->(void)const;
EQLIB_OBJECT class CXMLSOMNodePtr & CXMLSOMNodePtr::operator=(class CXMLSOMNodePtr const &);
//EQLIB_OBJECT void * CXMLSOMNodePtr::`vector deleting destructor'(unsigned int);
// protected
EQLIB_OBJECT void CXMLSOMNodePtr::Assure(void)const;
};

class CXMLSOMParser
{
public:
EQLIB_OBJECT CXMLSOMParser::~CXMLSOMParser(void);
EQLIB_OBJECT bool CXMLSOMParser::ParseFile(class CXStr);
// protected
EQLIB_OBJECT bool CXMLSOMParser::ParseDocument(void);
EQLIB_OBJECT bool CXMLSOMParser::ParseEndTag(class CXStr);
EQLIB_OBJECT bool CXMLSOMParser::ParseNameSpaceToken(class CXStr &);
EQLIB_OBJECT bool CXMLSOMParser::ParseNode(void);
EQLIB_OBJECT bool CXMLSOMParser::ParseNodeList(void);
EQLIB_OBJECT bool CXMLSOMParser::ParseProcess(void);
EQLIB_OBJECT bool CXMLSOMParser::ParseStartTag(bool &);
};

class CXMLSOMSchema
{
public:
EQLIB_OBJECT CXMLSOMSchema::~CXMLSOMSchema(void);
EQLIB_OBJECT CXMLSOMSchema::CXMLSOMSchema(void);
EQLIB_OBJECT bool CXMLSOMSchema::AddItem(class CXStr,class CXStr);
EQLIB_OBJECT bool CXMLSOMSchema::FindElementType(class CXStr);
EQLIB_OBJECT bool CXMLSOMSchema::FindItem(class CXStr,class CXStr);
EQLIB_OBJECT bool CXMLSOMSchema::FindSimpleType(class CXStr);
EQLIB_OBJECT bool CXMLSOMSchema::IsDerivedFrom(class CXStr,class CXStr);
EQLIB_OBJECT int CXMLSOMSchema::GetElementTypeIdx(class CXStr);
};

class CXMLSOMSimpleType
{
public:
EQLIB_OBJECT CXMLSOMSimpleType::~CXMLSOMSimpleType(void);
EQLIB_OBJECT CXMLSOMSimpleType::CXMLSOMSimpleType(void);
//EQLIB_OBJECT void * CXMLSOMSimpleType::`vector deleting destructor'(unsigned int);
};

class CXPoint
{
public:
EQLIB_OBJECT class CXPoint CXPoint::operator=(class CXPoint);
DWORD X,Y;
};

class CXRect
{
public:
EQLIB_OBJECT CXRect::CXRect(int nLeft,int nTop,int nRight,int nBottom)
{
    left=nLeft;
    top=nTop;
    right=nRight;
    bottom=nBottom;
}
EQLIB_OBJECT CXRect::CXRect(void) {};
EQLIB_OBJECT class CXPoint CXRect::CenterPoint(void)const;
EQLIB_OBJECT class CXRect & CXRect::operator=(class CXRect const &);
EQLIB_OBJECT class CXRect CXRect::operator&(class CXRect)const;
EQLIB_OBJECT class CXRect CXRect::operator|(class CXRect)const;
EQLIB_OBJECT int CXRect::Width(void)const;
EQLIB_OBJECT void CXRect::Move(class CXPoint);
EQLIB_OBJECT void CXRect::Normalize(void);
DWORD left,top,right,bottom;
};

class CXStrSingleton
{
public:
EQLIB_OBJECT static int CXStrSingleton::active;
};

class CXWndDrawTemplate
{
public:
EQLIB_OBJECT CXWndDrawTemplate::~CXWndDrawTemplate(void);
EQLIB_OBJECT CXWndDrawTemplate::CXWndDrawTemplate(class CXWndDrawTemplate const &);
EQLIB_OBJECT CXWndDrawTemplate::CXWndDrawTemplate(void);
EQLIB_OBJECT class CXWndDrawTemplate & CXWndDrawTemplate::operator=(class CXWndDrawTemplate const &);
};

class CXWndManager
{
public:
EQLIB_OBJECT CXWndManager::CXWndManager(class CSidlManager *);
EQLIB_OBJECT bool CXWndManager::IsAllValid(void);
EQLIB_OBJECT bool CXWndManager::IsWindowActive(class CXWnd const *)const;
EQLIB_OBJECT bool CXWndManager::IsWindowMovingOrSizing(class CXWnd *)const;
EQLIB_OBJECT bool CXWndManager::IsWindowPieceDown(class CXWnd const *,int)const;
EQLIB_OBJECT bool CXWndManager::OkayToSendMouseMessage(class CXWnd *)const;
EQLIB_OBJECT class CTextureAnimation const * CXWndManager::GetCursorToDisplay(void)const;
//EQLIB_OBJECT class CTextureFont * CXWndManager::GetFont(class CXStr);
EQLIB_OBJECT class CXWnd * CXWndManager::FindWnd(class CXPoint,int *)const;
EQLIB_OBJECT class CXWnd * CXWndManager::GetFirstChildWnd(class CXWnd const *)const;
EQLIB_OBJECT class CXWnd * CXWndManager::GetFocusWnd(void)const;
EQLIB_OBJECT class CXWnd * CXWndManager::GetNextSib(class CXWnd const *)const;
EQLIB_OBJECT class CXWnd * CXWndManager::SetFocusWnd(class CXWnd *);
EQLIB_OBJECT int CXWndManager::ActivateWnd(class CXWnd *);
EQLIB_OBJECT int CXWndManager::AddFont(class CTextureFont *);
EQLIB_OBJECT int CXWndManager::AddWnd(class CXWnd *);
EQLIB_OBJECT int CXWndManager::DrawCursor(void)const;
EQLIB_OBJECT int CXWndManager::DrawWindows(void)const;
EQLIB_OBJECT int CXWndManager::HandleKeyboardMsg(unsigned __int32,bool);
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
EQLIB_OBJECT int CXWndManager::NotifyAllWindows(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT int CXWndManager::OnWindowCloseBox(class CXWnd *);
EQLIB_OBJECT int CXWndManager::OnWindowMinimizeBox(class CXWnd *);
EQLIB_OBJECT int CXWndManager::OnWindowTileBox(class CXWnd *);
EQLIB_OBJECT int CXWndManager::ProcessFrame(void);
EQLIB_OBJECT int CXWndManager::RemoveWnd(class CXWnd *);
EQLIB_OBJECT static class CTextureAnimation CXWndManager::sm_curDefault;
EQLIB_OBJECT static class CTextureAnimation CXWndManager::sm_curDrag;
EQLIB_OBJECT static class CTextureAnimation CXWndManager::sm_curResizeEW;
EQLIB_OBJECT static class CTextureAnimation CXWndManager::sm_curResizeNESW;
EQLIB_OBJECT static class CTextureAnimation CXWndManager::sm_curResizeNS;
EQLIB_OBJECT static class CTextureAnimation CXWndManager::sm_curResizeNWSE;
EQLIB_OBJECT unsigned __int32 CXWndManager::GetDisplayWidth(void)const;
EQLIB_OBJECT unsigned __int32 CXWndManager::GetGlobalFadeDuration(void)const;
EQLIB_OBJECT unsigned __int32 CXWndManager::GetKeyboardFlags(void)const;
EQLIB_OBJECT unsigned char CXWndManager::GetGlobalAlpha(void)const;
EQLIB_OBJECT unsigned char CXWndManager::GetGlobalFadeToAlpha(void)const;
EQLIB_OBJECT unsigned long CXWndManager::GetGlobalFadeDelay(void)const;
EQLIB_OBJECT void CXWndManager::BringWndToTop(class CXWnd *,bool);
EQLIB_OBJECT void CXWndManager::CheckInvalidateLastFoundWnd(void);
EQLIB_OBJECT void CXWndManager::CleanupWindows(void);
EQLIB_OBJECT void CXWndManager::DestroyAllWindows(void);
EQLIB_OBJECT void CXWndManager::FlushKeyboardFlags(void);
EQLIB_OBJECT void CXWndManager::OnWindowShown(class CXWnd *,bool);
EQLIB_OBJECT void CXWndManager::SetGlobalAlpha(unsigned char);
EQLIB_OBJECT void CXWndManager::SetGlobalFadeDelay(unsigned long);
EQLIB_OBJECT void CXWndManager::SetGlobalFadeDuration(unsigned __int32);
EQLIB_OBJECT void CXWndManager::SetGlobalFadeToAlpha(unsigned char);
EQLIB_OBJECT void CXWndManager::SetSystemFont(class CTextureFont *);
EQLIB_OBJECT void CXWndManager::UpdateChildAndSiblingInfo(void);
// virtual
EQLIB_OBJECT CXWndManager::~CXWndManager(void);
EQLIB_OBJECT class CTextureFont *GetFont(int FontIndex) const {
	if (PCXWNDMGR wndmgr = (PCXWNDMGR)this) {
		if (wndmgr->FontsArray.Count >= FontIndex) {
			return (CTextureFont *)wndmgr->FontsArray[FontIndex];
		}
	}
	return 0;
}
EQLIB_OBJECT int CXWndManager::DestroyWnd(CXWnd *wnd);
//EQLIB_OBJECT void * CXWndManager::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CXWndManager::`vector deleting destructor'(unsigned int);
};

class EmitterManager
{
public:
EQLIB_OBJECT EmitterManager::~EmitterManager(void);
EQLIB_OBJECT EmitterManager::EmitterManager(class SoundManager *);
EQLIB_OBJECT float EmitterManager::GetEffectsLevel(void);
EQLIB_OBJECT float EmitterManager::GetVolumeLevel(void);
EQLIB_OBJECT void EmitterManager::Add(class SoundEmitter *);
EQLIB_OBJECT void EmitterManager::GetListenerLocation(float *,float *,float *,float *);
EQLIB_OBJECT void EmitterManager::GiveTime(void);
EQLIB_OBJECT void EmitterManager::Remove(class SoundEmitter *);
EQLIB_OBJECT void EmitterManager::SetEffectsLevel(float);
EQLIB_OBJECT void EmitterManager::SetVolumeLevel(float);
};

class engineInterface
{
public:
EQLIB_OBJECT static class engineInterface * __cdecl engineInterface::get(void);
EQLIB_OBJECT unsigned long * engineInterface::ChangeDag(struct T3D_tagWORLD *,struct T3D_DAG *,char *);
// private
EQLIB_OBJECT engineInterface::engineInterface(void);
EQLIB_OBJECT static class engineInterface * engineInterface::mSelf;
};
typedef struct _SlotData {
	LONG Slot;
	DWORD Value;
} SlotData;
class EQ_Affect
{
public:
EQLIB_OBJECT void EQ_Affect::Reset(void);
EQLIB_OBJECT int EQ_Affect::GetAffectData(int)const;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x00*/	BYTE Type;
/*0x01*/	BYTE CasterLevel;
/*0x02*/	BYTE ChargesRemaining;
/*0x03*/	BYTE Activatable;
/*0x04*/	FLOAT BaseDmgMod;
/*0x08*/	int ID;
/*0x0c*/	int DurationTick;
/*0x10*/	int MaxDuration;
/*0x14*/	int Duration3;
/*0x18*/	EqGuid CasterGuid;
/*0x20*/	int HitCounter;
/*0x24*/	FLOAT HitLocationY;
/*0x28*/	FLOAT HitLocationX;
/*0x2c*/	FLOAT HitLocationZ;
/*0x30*/	UINT Flags;//twincast
/*0x34*/	SlotData Data[NUM_SLOTDATA];
/*0x64*/	DWORD Unknown0x64;
/*0x68*/
#else
/*0x00*/	BYTE Type;
/*0x01*/	BYTE CasterLevel;
/*0x02*/	BYTE ChargesRemaining;
/*0x03*/	BYTE Activatable;
/*0x04*/	FLOAT BaseDmgMod;
/*0x08*/	int ID;
/*0x0c*/	int DurationTick;
/*0x10*/	int CasterID;
/*0x14*/	int HitCounter;
/*0x18*/	FLOAT HitLocationY;
/*0x1c*/	FLOAT HitLocationX;
/*0x20*/	FLOAT HitLocationZ;
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
EQLIB_OBJECT int EQ_Character1::GetHPRegen(bool bIncItemsAndBuffs, bool *bIsBleeding/*no you shouldnt set this, its an OUT value.*/, bool bCombat);
EQLIB_OBJECT int EQ_Character1::GetManaRegen(bool bIncItemsAndBuffs, bool bCombat);
EQLIB_OBJECT int EQ_Character1::Cur_HP(int Spawntype/*PC = 0 NPC=1 and so on*/,bool bCapAtMax=true);
EQLIB_OBJECT int EQ_Character1::Max_Endurance(bool bCapAtMax=true);
EQLIB_OBJECT int EQ_Character1::Max_HP(int SpawnType, bool bCapAtMax=true); 
EQLIB_OBJECT int EQ_Character1::Max_Mana(bool bCapAtMax=true);
EQLIB_OBJECT int const EQ_Character1::GetAACastingTimeModifier(class EQ_Spell const *);
EQLIB_OBJECT int const EQ_Character1::GetFocusCastingTimeModifier(class EQ_Spell const *,class EQ_Equipment * *,int);
EQLIB_OBJECT unsigned char EQ_Character1::CastSpell(unsigned char gemid, int spellid, class EQ_Item * *ppItem, class CEQItemLocation * ppitemloc, enum  ItemSpellTypes slot, unsigned char spell_loc, int arg7, int arg8, int arg9, bool arg10); 
EQLIB_OBJECT void EQ_Character1::SetEffectId(unsigned char,unsigned int);
EQLIB_OBJECT void EQ_Character1::StopSpellCast(unsigned char);
EQLIB_OBJECT void EQ_Character1::StopSpellCast(unsigned char,int);
EQLIB_OBJECT void EQ_Character1::StunMe(unsigned int,bool,bool,bool);
EQLIB_OBJECT void EQ_Character1::UnStunMe(void);
#if defined(ROF2EMU) || defined(UFEMU)
EQLIB_OBJECT void EQ_Character1::UseSkill(unsigned char skill,class EQPlayer *Target);
#else
EQLIB_OBJECT void EQ_Character1::UseSkill(unsigned char skill,class EQPlayer *Target,bool bAuto = false);
#endif
EQLIB_OBJECT int const EQ_Character1::GetFocusRangeModifier(class EQ_Spell const *,class EQ_Equipment * *);
EQLIB_OBJECT int EQ_Character1::IsExpansionFlag(int);
EQLIB_OBJECT int EQ_Character1::TotalEffect(int spaID, bool bIncludeItems = true, int subindex = 0, bool bIncludeAA = true, bool bincludeBuffs = true);
EQLIB_OBJECT int EQ_Character1::GetAdjustedSkill(int);
EQLIB_OBJECT int EQ_Character1::GetBaseSkill(int);
EQLIB_OBJECT bool EQ_Character1::CanUseItem(PCONTENTS *pItem, bool bUseRequiredLvl, bool bOutput);
};

class EQ_Character
{
public:
EQLIB_OBJECT EQ_Character::~EQ_Character(void);
EQLIB_OBJECT EQ_Character::EQ_Character(void);
EQLIB_OBJECT bool EQ_Character::DoesSpellMatchFocusFilters(class EQ_Spell const *,class EQ_Spell const *);
EQLIB_OBJECT bool EQ_Character::IsSpellTooPowerfull(class EQ_Spell *,class EQ_Character *);
EQLIB_OBJECT bool EQ_Character::CanUseMemorizedSpellSlot(int gem);
EQLIB_OBJECT bool EQ_Character::IsValidAffect(int);
EQLIB_OBJECT char * EQ_Character::Class(int);
EQLIB_OBJECT char * EQ_Character::KunarkClass(int,int,int,bool);
EQLIB_OBJECT char * EQ_Character::Race(int);
EQLIB_OBJECT class EQ_Affect & EQ_Character::GetEffect(int);
EQLIB_OBJECT class EQ_Affect * EQ_Character::GetPCSpellAffect(int theaffect,int *slotnum,int *spaslot = NULL) const;
EQLIB_OBJECT class EQ_Equipment * EQ_Character::GetFocusItem(class EQ_Spell const *,int);
EQLIB_OBJECT class EQ_Spell * EQ_Character::GetFocusEffect(class EQ_Spell const *,int);
EQLIB_OBJECT class EQPlayer * EQ_Character::FindClosest(int,int,int,int,int);
EQLIB_OBJECT class EQPlayer * EQ_Character::GetMyPetPlayer(void);
EQLIB_OBJECT float EQ_Character::encum_factor(void);
EQLIB_OBJECT int EQ_Character::ac(bool);
EQLIB_OBJECT int EQ_Character::Agi(void);
EQLIB_OBJECT int EQ_Character::AntiTwinkAdj(class EQ_Equipment *,int,int);
EQLIB_OBJECT int EQ_Character::ApplyDamage(int,struct _EQMissileHitinfo *,bool,class HateListEntry *,bool);
EQLIB_OBJECT int EQ_Character::ApplyFatigue(int);
EQLIB_OBJECT int EQ_Character::AutoEat(unsigned char);
EQLIB_OBJECT int EQ_Character::BaneDamage(class EQ_Equipment *);
EQLIB_OBJECT int EQ_Character::BardCastBard(class EQ_Spell const *,int)const;
EQLIB_OBJECT int EQ_Character::basesave_cold(void);
EQLIB_OBJECT int EQ_Character::basesave_disease(void);
EQLIB_OBJECT int EQ_Character::basesave_fire(void);
EQLIB_OBJECT int EQ_Character::basesave_magic(void);
EQLIB_OBJECT int EQ_Character::basesave_poison(void);
EQLIB_OBJECT int EQ_Character::CalculateBardSongMod(int);
EQLIB_OBJECT int EQ_Character::CapStat(int,int);
EQLIB_OBJECT int EQ_Character::Cha(void);
EQLIB_OBJECT int EQ_Character::CheckFoodAndWater(void);
EQLIB_OBJECT int EQ_Character::compute_defense(void);
EQLIB_OBJECT int EQ_Character::compute_tohit(unsigned char);
EQLIB_OBJECT int EQ_Character::cur_encumbrance(void);
EQLIB_OBJECT int EQ_Character::Cur_Mana(bool bCapAtMax = true);
EQLIB_OBJECT int EQ_Character::defense_agility_bonus(void);
EQLIB_OBJECT int EQ_Character::Dex(void);
EQLIB_OBJECT int EQ_Character::ElementResistDmg(class EQ_Equipment *,int);
EQLIB_OBJECT int EQ_Character::eqspa_change_form(class EQ_Spell *,int,int,class EQ_Affect *);
EQLIB_OBJECT int EQ_Character::eqspa_hp(unsigned int,class EQ_Affect *,int,class EQ_Spell *);
EQLIB_OBJECT int EQ_Character::GetBardInstrumentMod(int);
EQLIB_OBJECT int EQ_Character::GetClassACBonus(int);
EQLIB_OBJECT int EQ_Character::GetFirstEffectSlot(bool);
EQLIB_OBJECT int EQ_Character::GetHPFromStamina(int);
EQLIB_OBJECT int EQ_Character::GetIndexSkillMinDamageMod(int);
EQLIB_OBJECT int EQ_Character::GetLastEffectSlot(bool);
EQLIB_OBJECT int EQ_Character::GetOpenEffectSlot(bool,int);
EQLIB_OBJECT int EQ_Character::HasInnateSkill(unsigned char,int);
EQLIB_OBJECT int EQ_Character::HasSkill(unsigned char);
EQLIB_OBJECT int EQ_Character::HasSpell(int);
EQLIB_OBJECT int EQ_Character::IHaveSkill(unsigned char);
EQLIB_OBJECT int EQ_Character::InSpecialBindSpot(class EQPlayer *);
EQLIB_OBJECT int EQ_Character::Int(void);
EQLIB_OBJECT int EQ_Character::IsMage(void);
EQLIB_OBJECT int EQ_Character::IsSpecialBazaarSpot(class EQPlayer *);
EQLIB_OBJECT int EQ_Character::IsSpellcaster(void);
EQLIB_OBJECT int EQ_Character::ItemSpellAffects(int);
EQLIB_OBJECT int EQ_Character::max_encumbrance(void);
EQLIB_OBJECT int EQ_Character::NoBashMe(int);
EQLIB_OBJECT int EQ_Character::NoMezMe(int,class EQPlayer *,class EQ_Spell *);
EQLIB_OBJECT int EQ_Character::offense(unsigned char);
EQLIB_OBJECT int EQ_Character::ProcessAffects(void);
EQLIB_OBJECT int EQ_Character::save_bash(int);
EQLIB_OBJECT int EQ_Character::save_cold(void);
EQLIB_OBJECT int EQ_Character::save_disease(void);
EQLIB_OBJECT int EQ_Character::save_fire(void);
EQLIB_OBJECT int EQ_Character::save_magic(void);
EQLIB_OBJECT int EQ_Character::save_poison(void);
EQLIB_OBJECT int EQ_Character::SetLocalVar(char *,int);
EQLIB_OBJECT int EQ_Character::Skill(int);
EQLIB_OBJECT int EQ_Character::SpellDuration(class EQ_Spell const *,unsigned char,unsigned char);
EQLIB_OBJECT int EQ_Character::Sta(void);
EQLIB_OBJECT int EQ_Character::Str(void);
EQLIB_OBJECT int EQ_Character::TakeFallDamage(float);
EQLIB_OBJECT int EQ_Character::TotalSpellAffects(unsigned char,bool,int *);
EQLIB_OBJECT int EQ_Character::Wis(void);
EQLIB_OBJECT int const EQ_Character::GetFocusConserveRegChance(class EQ_Spell const *,class EQ_Equipment * *);
EQLIB_OBJECT long EQ_Character::TotalOnPerson(void);
EQLIB_OBJECT static int __cdecl EQ_Character::normal_to_special(int);
EQLIB_OBJECT unsigned char EQ_Character::BarbarianCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::BaseAttr(int,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::CanDoubleAttack(class EQPlayer *,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::CanIBreathe(void);
EQLIB_OBJECT unsigned char EQ_Character::CanISeeInvis(void);
EQLIB_OBJECT unsigned char EQ_Character::CanMedOnHorse(void);
EQLIB_OBJECT unsigned char EQ_Character::CanSecondaryAttack(class EQPlayer *);
EQLIB_OBJECT unsigned char EQ_Character::CanWorship(int,int,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::CastingRequirementsMet(int);
EQLIB_OBJECT unsigned char EQ_Character::CheckClass(int,int);
EQLIB_OBJECT unsigned char EQ_Character::CityCanStart(int,int,int,int);
EQLIB_OBJECT unsigned char EQ_Character::ClassMin(int,int,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::DarkElfCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::DwarfCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::ElfCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::EruditeCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::ExpendItemCharge(int,int);
EQLIB_OBJECT unsigned char EQ_Character::FindItemByClass(int,int *,int *);
EQLIB_OBJECT unsigned char EQ_Character::FindItemQty(int,int);
EQLIB_OBJECT unsigned char EQ_Character::FroglockCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::GetSkillBaseDamage(unsigned char,class EQPlayer *);
EQLIB_OBJECT unsigned char EQ_Character::GnomeCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::HalfElfCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::HalflingCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::HighElfCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::HumanCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::IksarCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::IsSpellAffectingPC(int,int);
EQLIB_OBJECT unsigned char EQ_Character::LaunchSpell(unsigned char,int,class EQ_Item * *);
EQLIB_OBJECT unsigned char EQ_Character::OgreCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::SpellFizzled(unsigned char,class EQ_Spell *);
EQLIB_OBJECT unsigned char EQ_Character::TrollCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::VahShirCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT void EQ_Character::CalcFoodDrinkBonus(int);
EQLIB_OBJECT void EQ_Character::DoFishingEvent(void);
EQLIB_OBJECT void EQ_Character::DoIntimidationEvent(void);
EQLIB_OBJECT void EQ_Character::DoLight(unsigned char);
EQLIB_OBJECT void EQ_Character::DoMeditation(void);
EQLIB_OBJECT void EQ_Character::DoPassageOfTime(void);
EQLIB_OBJECT void EQ_Character::EQ_CharacterResetAllMembers(void);
EQLIB_OBJECT void EQ_Character::EQSPA_Feign_Death(int);
EQLIB_OBJECT void EQ_Character::eqspa_levitation(void);
EQLIB_OBJECT void EQ_Character::eqspa_locate_corpse(void);
EQLIB_OBJECT void EQ_Character::eqspa_movement_rate(int);
EQLIB_OBJECT void EQ_Character::HandleSpecialPCAffects(int);
EQLIB_OBJECT void EQ_Character::HitBySpell(struct _EQMissileHitinfo *);
EQLIB_OBJECT void EQ_Character::IAmDead(struct _EQMissileHitinfo *,int);
EQLIB_OBJECT void EQ_Character::InitInnates(unsigned int,unsigned int);
EQLIB_OBJECT void EQ_Character::InitMyLanguages(void);
EQLIB_OBJECT void EQ_Character::InitSkills(unsigned char,unsigned int);
EQLIB_OBJECT void EQ_Character::ItemSold(long);
#if defined(ROF2EMU) || defined(UFEMU)
EQLIB_OBJECT void EQ_Character::ModifyCurHP(int modification,class PlayerZoneClient *resposibleplayer,int skilltype);
#else
EQLIB_OBJECT void EQ_Character::ModifyCurHP(__int64 modification, class PlayerZoneClient *resposibleplayer,int skilltype);
#endif
EQLIB_OBJECT void EQ_Character::NotifyPCAffectChange(int,int);
EQLIB_OBJECT void EQ_Character::ProcessAllStats(void);
EQLIB_OBJECT void EQ_Character::ProcessEnvironment(void);
EQLIB_OBJECT void EQ_Character::ProcessHungerandThirst(unsigned int);
EQLIB_OBJECT void EQ_Character::RemovePCAffect(class EQ_Affect *);
EQLIB_OBJECT void EQ_Character::RemovePCAffectex(class EQ_Affect *,int);
EQLIB_OBJECT void EQ_Character::ResetCur_HP(int);
EQLIB_OBJECT void EQ_Character::UpdateMyVisibleStatus(void);
//confirmed having only 2 parameters (looks like it has 3 but it doesnt) in apr 21 2016 eqgame.exe (live) - eqmule
EQLIB_OBJECT bool EQ_Character::DoCombatAbility(int spellID, int dummy=1);
EQLIB_OBJECT unsigned long EQ_Character::GetConLevel(class EQPlayer *);
// private
EQLIB_OBJECT int EQ_Character::GetCachEQSPA(int);
EQLIB_OBJECT void EQ_Character::ReCachItemEffects(void);
EQLIB_OBJECT void EQ_Character::ReCachSpellEffects(void);
};

class EQ_CharacterData
{
public:
EQLIB_OBJECT void EQ_CharacterData::EQ_CharacterDataResetAllMembers(void);
};

class EQ_Container
{
public:
EQLIB_OBJECT EQ_Container::~EQ_Container(void);
EQLIB_OBJECT EQ_Container::EQ_Container(void);
EQLIB_OBJECT unsigned char EQ_Container::Close(void);
EQLIB_OBJECT unsigned char EQ_Container::IsOpen(void);
EQLIB_OBJECT unsigned char EQ_Container::Open(void);
};

class EQ_Equipment
{
public:
EQLIB_OBJECT EQ_Equipment::EQ_Equipment(void);
EQLIB_OBJECT int EQ_Equipment::IsInstrument(void);
EQLIB_OBJECT int EQ_Equipment::IsWeapon(void);
EQLIB_OBJECT void EQ_Equipment::SendTextRequestMsg(void);
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
EQLIB_OBJECT bool EQ_Item::IsSpecialNoDrop(void);
EQLIB_OBJECT char * EQ_Item::ValueSBuy(float,long);
EQLIB_OBJECT char * EQ_Item::ValueSRent(void);
EQLIB_OBJECT char * EQ_Item::ValueSSell(float,long);
EQLIB_OBJECT int EQ_Item::Copper(void);
EQLIB_OBJECT int EQ_Item::Gold(void);
EQLIB_OBJECT int EQ_Item::Platinum(void);
EQLIB_OBJECT int EQ_Item::Silver(void);
EQLIB_OBJECT long EQ_Item::ValueSellMerchant(float,long)const;
EQLIB_OBJECT bool EQ_Item::IsStackable(void); // Valerian 12-20-2004 
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT char * EQ_Item::CreateItemTagString(char *, int, bool bFlag = true); // SwiftyMUSE 11-09-2018
#else
EQLIB_OBJECT char * EQ_Item::CreateItemTagString(char *, int); // Lax 11-14-2003
#endif
EQLIB_OBJECT bool EQ_Item::CanDrop(bool bDisplayText = false, bool bIncludeContainedItems = true, bool bAllowOverrideNoDropCheck = false, bool bCantDropIfContainingRealEstate = true) const;
EQLIB_OBJECT int EQ_Item::GetImageNum(void)const;
EQLIB_OBJECT struct  _CONTENTS** __cdecl CreateItemClient(PBYTE*,DWORD);
EQLIB_OBJECT int EQ_Item::GetItemValue(bool)const;
EQLIB_OBJECT bool EQ_Item::IsKeyRingItem(KeyRingType type)const;
EQLIB_OBJECT bool EQ_Item::CanGoInBag(PCONTENTS *pCont, int OutputText = 0, bool mustbefalse = false) const;
EQLIB_OBJECT bool EQ_Item::IsEmpty(void) const;
EQLIB_OBJECT int EQ_Item::GetMaxItemCount(void)const;
EQLIB_OBJECT int EQ_Item::GetAugmentFitBySlot(PCONTENTS *Aug, int Slot, bool bCheckSlot = true, bool bCheckDup = true)const; 
ITEMINFO Data;
};

class EQ_LoadingS
{
public:
EQLIB_OBJECT EQ_LoadingS::~EQ_LoadingS(void);
EQLIB_OBJECT EQ_LoadingS::EQ_LoadingS(void);
EQLIB_OBJECT void EQ_LoadingS::draw(void);
EQLIB_OBJECT void EQ_LoadingS::DrawBackground(struct T3D_XYZ *);
EQLIB_OBJECT void EQ_LoadingS::SetProgressBar(int,char const *);
EQLIB_OBJECT void EQ_LoadingS::WriteTextHD(char *,int,int,int);
// virtual
EQLIB_OBJECT void EQ_LoadingS::Activate(void);
EQLIB_OBJECT void EQ_LoadingS::Deactivate(void);
EQLIB_OBJECT void EQ_LoadingS::DefineImages(void);
};

class EQ_Note
{
public:
EQLIB_OBJECT EQ_Note::~EQ_Note(void);
EQLIB_OBJECT EQ_Note::EQ_Note(void);
EQLIB_OBJECT void EQ_Note::SendTextRequestMsg(void);
};
struct ItemContainingRealEstate
{
	int RealEstateID;
	ItemGlobalIndex ItemLocation;
};
class EQ_PC
{
public:
EQLIB_OBJECT EQ_PC::~EQ_PC(void);
EQLIB_OBJECT EQ_PC::EQ_PC(class EQ_PC *);
EQLIB_OBJECT int EQ_PC::BitchCanTrain(int,int,int);
EQLIB_OBJECT int EQ_PC::CheckDupLoreItems(void);
EQLIB_OBJECT int EQ_PC::checkLang(int);
EQLIB_OBJECT int EQ_PC::CostToTrain(int,float,int);
EQLIB_OBJECT int EQ_PC::DelLoreItemDup(int,int,int,class EQ_Item *);
//EQ_PC::GetAlternateAbilityId checked on May 1 2016 -eqmule only reason why it looks like it takes 2 args(which it doesnt) is cause it pushes another which is meant for AltAdvManager__GetAAById_x see 43BBB7 in eqgame 21 apr 2016 live for an example.
EQLIB_OBJECT int EQ_PC::GetAlternateAbilityId(int);
EQLIB_OBJECT int EQ_PC::GetArmorType(int);
EQLIB_OBJECT int EQ_PC::GetCombatAbility(int);
EQLIB_OBJECT class PcZoneClient *EQ_PC::GetPcZoneClient(void)const;
EQLIB_OBJECT int EQ_PC::HandleMoney(long);
EQLIB_OBJECT int EQ_PC::IsAGroupMember(char *);
EQLIB_OBJECT int EQ_PC::MaxAirSupply(void);
EQLIB_OBJECT int EQ_PC::numInParty(void);
EQLIB_OBJECT static class EQ_PC * EQ_PC::top;
EQLIB_OBJECT unsigned char EQ_PC::AtSkillLimit(int);
EQLIB_OBJECT unsigned char EQ_PC::RemoveMyAffect(int);
EQLIB_OBJECT class MQItemBaseContainer &EQ_PC::GetKeyRingItems(enum KeyRingType);
EQLIB_OBJECT unsigned long EQ_PC::GetArmorTint(int);
EQLIB_OBJECT unsigned long EQ_PC::GetBodyTint(int);
EQLIB_OBJECT void EQ_PC::CheckForGroupChanges(void);
EQLIB_OBJECT void EQ_PC::CheckForLanguageImprovement(unsigned char,unsigned char);
EQLIB_OBJECT void EQ_PC::CheckSkillImprove(int,float);
EQLIB_OBJECT void EQ_PC::ClearSharedVault(void);
EQLIB_OBJECT void EQ_PC::DestroyHeldItemOrMoney(void);
EQLIB_OBJECT void EQ_PC::DetermineQuestExpGained(int);
EQLIB_OBJECT void EQ_PC::EmptyPossessionSlots(void);
EQLIB_OBJECT void EQ_PC::InitializeNewPCVariables(int);
EQLIB_OBJECT void EQ_PC::InitPlayerStart(unsigned int,unsigned char,int);
EQLIB_OBJECT void EQ_PC::PrepareForRepop(int);
EQLIB_OBJECT void EQ_PC::ProcessAirSupply(void);
EQLIB_OBJECT void EQ_PC::ProcessFatigue(void);
EQLIB_OBJECT void EQ_PC::RefitNewbieEQ(void);
EQLIB_OBJECT void EQ_PC::RefreshMe(int);
EQLIB_OBJECT void EQ_PC::SetAltAbilityIndex(int,int);
EQLIB_OBJECT void EQ_PC::SetArmorTint(int,unsigned long);
EQLIB_OBJECT void EQ_PC::SetArmorType(int,int);
EQLIB_OBJECT void EQ_PC::SetFatigue(int);
EQLIB_OBJECT void EQ_PC::UnpackMyNetPC(char *,int);
EQLIB_OBJECT void EQ_PC::AlertInventoryChanged(void);
//EQ_PC::GetCombatAbilityTimer has 2 parameters confirmed apr 21 2016 eqgame.exe (live) -eqmule
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT unsigned long EQ_PC::GetCombatAbilityTimer(int,int);
EQLIB_OBJECT unsigned long EQ_PC::GetItemRecastTimer(class EQ_Item *item,ItemSpellTypes etype);
#else
EQLIB_OBJECT unsigned long EQ_PC::GetCombatAbilityTimer(int);
EQLIB_OBJECT unsigned long EQ_PC::GetItemRecastTimer(class EQ_Item *item);
#endif
EQLIB_OBJECT bool EQ_PC::HasLoreItem(class EQ_Item *,int,int,int,int);
EQLIB_OBJECT void EQ_PC::GetItemContainedRealEstateIds(ArrayClass<ItemContainingRealEstate> &Out, bool bCurrentProfileOnly = false, bool bIncludeAltStorage = true, bool bIncludeArchived = true);
EQLIB_OBJECT void EQ_PC::GetNonArchivedOwnedRealEstates(ArrayClass<int>& output);

};

class ProfileManager
{
public:
EQLIB_OBJECT BaseProfile* ProfileManager::GetCurrentProfile(void);

};

class EQ_Skill
{
public:
EQLIB_OBJECT EQ_Skill::~EQ_Skill(void);
EQLIB_OBJECT EQ_Skill::EQ_Skill(int);
};

class EQ_Spell
{
public:
EQLIB_OBJECT EQ_Spell::~EQ_Spell(void);
EQLIB_OBJECT EQ_Spell::EQ_Spell(char *);
EQLIB_OBJECT bool EQ_Spell::IsStackableDot(void)const;
EQLIB_OBJECT bool EQ_Spell::IsStackable(void) const;
EQLIB_OBJECT int EQ_Spell::IsPermIllusionSpell(void)const;
EQLIB_OBJECT int EQ_Spell::SpellUsesDragonBreathEffect(void);
EQLIB_OBJECT unsigned char EQ_Spell::SpellAffects(int)const;//this one takes an attrib(soe calls it affect) and returns the index for it...
EQLIB_OBJECT unsigned char EQ_Spell::GetSpellLevelNeeded(int)const;//takes a Class, druid for example is 6
EQLIB_OBJECT int EQ_Spell::SpellAffectBase(int)const;//takes a SPA, returns the first matching base it finds for it
EQLIB_OBJECT const PSPELLCALCINFO EQ_Spell::GetSpellAffectBySlot(int Slot) const;
#if !defined(ROF2EMU)
EQLIB_OBJECT const PSPELLCALCINFO EQ_Spell::GetSpellAffectByIndex(int Index) const;
#endif
EQLIB_OBJECT bool EQ_Spell::IsNoRemove(void)const;
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
EQLIB_OBJECT EQAnimation::~EQAnimation(void);
EQLIB_OBJECT EQAnimation::EQAnimation(void);
};

class EQEffect
{
public:
EQLIB_OBJECT EQEffect::~EQEffect(void);
EQLIB_OBJECT EQEffect::EQEffect(class EQEffect *,char *,int,struct _EQLOC *,class EQPlayer *,class EQMissile *,struct _EQRGB *,float,int,int,float,float);
EQLIB_OBJECT static class EQEffect * EQEffect::top;
};

class EqEmitterData
{
public:
EQLIB_OBJECT EqEmitterData::EqEmitterData(void);
EQLIB_OBJECT void EqEmitterData::SetLoadString(char *);
};

class EQHSprite
{
public:
EQLIB_OBJECT EQHSprite::~EQHSprite(void);
EQLIB_OBJECT EQHSprite::EQHSprite(char *,struct T3D_tagACTORINSTANCE *,class EQPlayer *);
EQLIB_OBJECT bool EQHSprite::GetAnimationTrackPtr(char *,char *,int,int,unsigned char,int);
EQLIB_OBJECT class EQHSprite * EQHSprite::get_object(char *);
EQLIB_OBJECT static class EQHSprite * EQHSprite::top;
};

class EQItemList
{
public:
EQLIB_OBJECT EQItemList::~EQItemList(void);
EQLIB_OBJECT EQItemList::EQItemList(void);
EQLIB_OBJECT class EQItemList * EQItemList::get_item(long);
EQLIB_OBJECT class EQItemList * EQItemList::is_item_actor(struct T3D_tagACTORINSTANCE *);
EQLIB_OBJECT static class EQItemList * EQItemList::top;
};

class EQMissile
{
public:
EQLIB_OBJECT EQMissile::~EQMissile(void);
EQLIB_OBJECT EQMissile::EQMissile(class EQ_Equipment *,class EQPlayer *,class EQMissile *,char *,unsigned char,unsigned int);
EQLIB_OBJECT class EQMissile * EQMissile::is_missile_actor(struct T3D_tagACTORINSTANCE *);
EQLIB_OBJECT static class EQMissile * EQMissile::top;
EQLIB_OBJECT void EQMissile::CleanUpMyEffects(void);
EQLIB_OBJECT void EQMissile::HitActor(struct T3D_tagACTORINSTANCE *,bool);
EQLIB_OBJECT void EQMissile::LeaveTrail(void);
EQLIB_OBJECT void EQMissile::MissileAI(void);
EQLIB_OBJECT void EQMissile::ProcessMissile(void);
};

class EqMobileEmitter
{
public:
EQLIB_OBJECT EqMobileEmitter::~EqMobileEmitter(void);
EQLIB_OBJECT EqMobileEmitter::EqMobileEmitter(class EqSoundManager *);
EQLIB_OBJECT void EqMobileEmitter::Move(float,float,float);
EQLIB_OBJECT void EqMobileEmitter::SetNpcHeight(float);
EQLIB_OBJECT void EqMobileEmitter::SetWave(int,char *);
};

class EQMoneyList
{
public:
EQLIB_OBJECT EQMoneyList::~EQMoneyList(void);
EQLIB_OBJECT EQMoneyList::EQMoneyList(void);
EQLIB_OBJECT class EQMoneyList * EQMoneyList::get_money(long);
EQLIB_OBJECT static class EQMoneyList * EQMoneyList::top;
};

class EQNewPlayerAnimation
{
public:
EQLIB_OBJECT static void __cdecl EQNewPlayerAnimation::InitAnimationData(void);
};

class EQObject
{
public:
EQLIB_OBJECT EQObject::~EQObject(void);
EQLIB_OBJECT EQObject::EQObject(class EQObject *,class EQPlayer *,char *,char *);
EQLIB_OBJECT static class EQObject * EQObject::top;
};

class EQOldPlayerAnimation
{
public:
EQLIB_OBJECT EQOldPlayerAnimation::EQOldPlayerAnimation(class EQPlayer *);
EQLIB_OBJECT static void __cdecl EQOldPlayerAnimation::InitAnimationData(void);
// virtual
EQLIB_OBJECT bool EQOldPlayerAnimation::RequestAnimation(unsigned short,bool,bool,float,unsigned char);
EQLIB_OBJECT bool EQOldPlayerAnimation::RequestAnimation(unsigned short,bool,bool,float,unsigned char,unsigned char);
EQLIB_OBJECT int EQOldPlayerAnimation::GetAnimNum(int,int,int,float *,unsigned char);
EQLIB_OBJECT void EQOldPlayerAnimation::InitAnimationTracks(class EQHSprite *,struct T3D_tagACTORINSTANCE *);
EQLIB_OBJECT void EQOldPlayerAnimation::PlayAnimationSound(int);
EQLIB_OBJECT void EQOldPlayerAnimation::ProcessAnimation(bool,bool);
// private
EQLIB_OBJECT bool EQOldPlayerAnimation::AnimationIsAggressive(int);
EQLIB_OBJECT bool EQOldPlayerAnimation::InterruptCurrentAnimation(int,unsigned char);
EQLIB_OBJECT bool EQOldPlayerAnimation::IsIdleAnimation(int);
EQLIB_OBJECT bool EQOldPlayerAnimation::IsSocialAnimation(int);
EQLIB_OBJECT bool EQOldPlayerAnimation::IsStandAnimation(int);
EQLIB_OBJECT static bool * EQOldPlayerAnimation::mAnimAllowsSeparateLower;
EQLIB_OBJECT static bool * EQOldPlayerAnimation::mAnimAllowsSeparateUpper;
EQLIB_OBJECT static bool * EQOldPlayerAnimation::mAnimInterruptable;
EQLIB_OBJECT static char (* EQOldPlayerAnimation::mAnimationPrefix)[20];
EQLIB_OBJECT virtual bool EQOldPlayerAnimation::GetAlternateAnimTag(char *,char *,bool);
EQLIB_OBJECT void EQOldPlayerAnimation::ChangeAttachmentAnimationTrackSpeeds(bool,float);
EQLIB_OBJECT void EQOldPlayerAnimation::PlayAttachmentAnimationTracks(int,int,bool,bool,float,bool,unsigned char);
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
/*0x04*/ EQPlacedItem *pPrev;
/*0x08*/ EQPlacedItem *pNext;
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
/*0x7c*/ FLOAT  Scale;
/*0x80*/ FLOAT  Heading;
/*0x84*/ FLOAT  Angle;
/*0x88*/ FLOAT  Roll;
/*0x8c*/ FLOAT  Y;
/*0x90*/ FLOAT  X;
/*0x94*/ FLOAT  Z;
/*0x98*/ bool	bIgnoreCollisions;
/*0x98*/ bool	bDisablePlacementRotation;
/*0x98*/ bool	bDisableFreePlacement;
/*0x9c*/ ePlacementType  PlacementType;
/*0xa0*/ FLOAT  ScaleRangeMin;
/*0xa4*/ FLOAT  ScaleRangeMax;
/*0xa8*/ FLOAT  DefaultScale;
/*0xac*/ FLOAT  DefaultHeading;
/*0xb0*/ FLOAT  DefaultAngle;
/*0xb4*/ FLOAT  DefaultRoll;
/*0xb8*/ int	LightType;
/*0xbc*/ FLOAT  NPCHeight;
/*0xC0*/
};

class EQPlacedItemManager
{ 
public:
EQLIB_OBJECT static EQPlacedItemManager& Instance();
EQLIB_OBJECT EQPlacedItem* GetItemByGuid(const EqItemGuid& ItemGuid);
EQLIB_OBJECT EQPlacedItem* GetItemByRealEstateAndRealEstateItemIds(int RealEstateID, int RealEstateItemID);

	EQPlacedItem *Top;
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
	FLOAT Heading;
	FLOAT Pitch;
	FLOAT Roll;
	FLOAT Scale;
	FLOAT X;
	FLOAT Y;
	FLOAT Z;
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
	EQLIB_OBJECT static RealEstateManagerClient &RealEstateManagerClient::Instance();
	EQLIB_OBJECT const RealEstateItemClient* GetItemByRealEstateAndItemIds( int RealEstateID, int RealEstateItemID ) const;
};

class FactionManagerClient
{
public:
/*0x00*/ PVOID vftable;
/*0x04*/ //todo: map it
	EQLIB_OBJECT static FactionManagerClient &FactionManagerClient::Instance();
	EQLIB_OBJECT void FactionManagerClient::HandleFactionMessage(UINT MessageID, PCHAR pData, unsigned int DataLength);
};
class EQPlayer
{
public:
EQLIB_OBJECT EQPlayer::~EQPlayer(void);
EQLIB_OBJECT EQPlayer::EQPlayer(class EQPlayer *,unsigned char,unsigned int,unsigned char,char *);
EQLIB_OBJECT bool EQPlayer::AllowedToAttack(class EQPlayer *,int);
EQLIB_OBJECT bool EQPlayer::CanChangeForm(int Race,BYTE Sex,float Height);
EQLIB_OBJECT bool EQPlayer::CanIFitHere(float,float,float);
EQLIB_OBJECT bool EQPlayer::CanIHit(class EQPlayer *,float);
EQLIB_OBJECT bool EQPlayer::CanSee(class EQPlayer *);
EQLIB_OBJECT bool EQPlayer::CanSee(CVector3 *pos);
EQLIB_OBJECT bool EQPlayer::GetBoneCoords(struct T3D_DAG *,struct _EQLOC *);
EQLIB_OBJECT bool EQPlayer::IsAMount(void);
EQLIB_OBJECT bool EQPlayer::IsFlyer(void);
EQLIB_OBJECT bool EQPlayer::IsInvisible(class EQPlayer *);
EQLIB_OBJECT bool EQPlayer::IsInvited(void);
EQLIB_OBJECT bool EQPlayer::IsRoleplaying(void);
EQLIB_OBJECT bool EQPlayer::IsUntexturedHorse(void);
EQLIB_OBJECT bool EQPlayer::IWasHit(struct _EQMissileHitinfo *);
EQLIB_OBJECT bool EQPlayer::MyFeetAreOnGround(void);
EQLIB_OBJECT bool EQPlayer::SetNameSpriteTint(void);
EQLIB_OBJECT bool EQPlayer::UpdatePlayerActor(void);
EQLIB_OBJECT bool const EQPlayer::HasInvalidRiderTexture(void)const;
EQLIB_OBJECT float EQPlayer::GetDefaultHeight(int,unsigned char);
EQLIB_OBJECT float EQPlayer::GetPlayerFloorHeight(float,float,float,unsigned char);
EQLIB_OBJECT int EQPlayer::AimAtTarget(class EQPlayer *,class EQMissile *);
EQLIB_OBJECT int EQPlayer::AttachPlayerToPlayerBone(class EQPlayer *,struct T3D_DAG *);
EQLIB_OBJECT int EQPlayer::CanBeBald(void);
EQLIB_OBJECT int EQPlayer::CheckForJump(void);
#if defined(ROF2EMU) || defined(UFEMU)
	EQLIB_OBJECT bool EQPlayer::DoAttack(BYTE slot, BYTE skill,class EQPlayer *Target);
#else
	EQLIB_OBJECT bool EQPlayer::DoAttack(BYTE slot, BYTE skill, EQPlayer *Target, bool bSomething = false, bool bAuto = false, bool bDontknow = false);
#endif
EQLIB_OBJECT int EQPlayer::GetAlternateTrackNumber(int,unsigned char *);
EQLIB_OBJECT int EQPlayer::GetArmorType(int);
EQLIB_OBJECT int EQPlayer::GetAttachedHelmITNum(int,int *);
EQLIB_OBJECT int EQPlayer::GetGuild(void)const;
EQLIB_OBJECT int EQPlayer::GetRaceSexITOffset(void);
EQLIB_OBJECT bool EQPlayer::IsValidTeleport(float X, float Y, float Z, float Heading, float Distance);
EQLIB_OBJECT int EQPlayer::Levitating(void);
EQLIB_OBJECT int EQPlayer::MountableRace(void);
EQLIB_OBJECT int EQPlayer::MovePlayer(void);
EQLIB_OBJECT int EQPlayer::NotOnSameDeity(class EQPlayer *,class EQ_Spell *);
EQLIB_OBJECT int EQPlayer::ReplaceSpecialCloakMaterials(void);
EQLIB_OBJECT int EQPlayer::SetEyeMaterial(unsigned char,int);
EQLIB_OBJECT int EQPlayer::SetFHEB(unsigned char,unsigned char);
EQLIB_OBJECT int EQPlayer::SetFHEB_Color(unsigned char,unsigned char);
EQLIB_OBJECT int EQPlayer::SetHairOrBeard(int);
EQLIB_OBJECT int EQPlayer::SetNameSpriteState(bool);
EQLIB_OBJECT int EQPlayer::SetPlayerPitchType(void);
EQLIB_OBJECT int EQPlayer::SwapBody(int,int);
EQLIB_OBJECT int EQPlayer::SwapFace(int,int);
EQLIB_OBJECT int EQPlayer::SwapHead(int,int,unsigned long,int);
EQLIB_OBJECT int EQPlayer::SwapMaterial(int,int,int,int,unsigned char);
EQLIB_OBJECT int EQPlayer::SwapNPCMaterials(void);
EQLIB_OBJECT static class EQPlayer * __cdecl EQPlayer::GetClosestPlayerFromPartialName(char *,class EQPlayer *);
EQLIB_OBJECT static class EQPlayer * __cdecl EQPlayer::GetPlayerFromPartialName(char *);
EQLIB_OBJECT static class EQPlayer * __cdecl EQPlayer::IsPlayerActor(struct T3D_tagACTORINSTANCE *);
EQLIB_OBJECT static class EQPlayer * __cdecl EQPlayer::GetPlayerFromName(char const *);
EQLIB_OBJECT static void __cdecl EQPlayer::ComputeSpecialHeights(int,float *,float *,float *,float *,bool);
EQLIB_OBJECT static void __cdecl EQPlayer::GetPCActorTag(char *,unsigned int,unsigned char);
EQLIB_OBJECT static void __cdecl EQPlayer::TackOnNeuterChar(char *,unsigned int);
EQLIB_OBJECT static void __cdecl EQPlayer::UpdateAllPlayersVisibility(void);
EQLIB_OBJECT struct T3D_DAG * EQPlayer::GetBonePointerByITS(int,int);
EQLIB_OBJECT struct T3D_POINTLIGHT * EQPlayer::CreateUserLight(struct T3D_LIGHTDEFINITION *,int);
EQLIB_OBJECT unsigned char EQPlayer::DoTeleport(char *,int);
EQLIB_OBJECT unsigned char EQPlayer::DoTeleportB(int,float,float,float,float,char*,int);
EQLIB_OBJECT unsigned char EQPlayer::GetBaseFaceNbr(int,unsigned char *);
EQLIB_OBJECT unsigned char EQPlayer::GetNearestActorTag(char *,void *);
EQLIB_OBJECT unsigned char EQPlayer::HandleAmmo(void);
EQLIB_OBJECT unsigned char EQPlayer::HasAttachedBeard(void);
EQLIB_OBJECT unsigned char EQPlayer::HasAttachedHair(void);
EQLIB_OBJECT unsigned char EQPlayer::SkillUsed(unsigned char);
EQLIB_OBJECT unsigned char EQPlayer::UpdateItemSlot(unsigned char,char *,int);
EQLIB_OBJECT unsigned int EQPlayer::CalcAnimLength(int);
EQLIB_OBJECT unsigned int EQPlayer::ModifyAttackSpeed(unsigned int,int);
EQLIB_OBJECT unsigned long EQPlayer::GetArmorTint(int);
EQLIB_OBJECT void EQPlayer::BodyEnvironmentChange(unsigned char);
EQLIB_OBJECT void EQPlayer::ChangeHeight(float);
EQLIB_OBJECT void EQPlayer::ChangeLight(void);
EQLIB_OBJECT void EQPlayer::ChangeNoGravity(int);
EQLIB_OBJECT void EQPlayer::ChangePosition(unsigned char);
EQLIB_OBJECT void EQPlayer::CheckForUnderFloor(void);
EQLIB_OBJECT void EQPlayer::CleanUpMyEffects(void);
EQLIB_OBJECT void EQPlayer::CleanUpTarget(void);
EQLIB_OBJECT void EQPlayer::CleanUpVehicle(void);
EQLIB_OBJECT void EQPlayer::DeleteMyMissiles(void);
EQLIB_OBJECT void EQPlayer::Dismount(void);
EQLIB_OBJECT void EQPlayer::DisplayWeaponsAndArmor(void);
EQLIB_OBJECT void EQPlayer::do_change_form(struct chngForm *);
EQLIB_OBJECT void EQPlayer::DoCamAi(void);
EQLIB_OBJECT void EQPlayer::DoClassRandomAnimation(void);
EQLIB_OBJECT void EQPlayer::DoFloorCheck(void);
EQLIB_OBJECT void EQPlayer::DoItemSlot(int);
EQLIB_OBJECT void EQPlayer::DoSwimJump(unsigned char);
EQLIB_OBJECT void EQPlayer::FacePlayer(class EQPlayer *);
EQLIB_OBJECT void EQPlayer::FeetEnvironmentChange(unsigned char);
EQLIB_OBJECT void EQPlayer::FollowPlayerAI(void);
EQLIB_OBJECT void EQPlayer::ForceInvisible(bool);
EQLIB_OBJECT void EQPlayer::GetActorTag(char *);
EQLIB_OBJECT void EQPlayer::GetAllowedHairColorIndexRange(int,int *,int *);
EQLIB_OBJECT void EQPlayer::GetConscious(void);
EQLIB_OBJECT void EQPlayer::HandleMaterialEx(int,unsigned int,unsigned int,unsigned long,int);
EQLIB_OBJECT void EQPlayer::HandoverControlToZoneserver(void);
EQLIB_OBJECT void EQPlayer::HeadEnvironmentChange(unsigned char);
EQLIB_OBJECT void EQPlayer::HideOrShowAttachedHair(void);
EQLIB_OBJECT void EQPlayer::IDied(struct _EQPlayerDeath *);
EQLIB_OBJECT void EQPlayer::IHaveFallen(float);
EQLIB_OBJECT void EQPlayer::InitSneakMod(void);
EQLIB_OBJECT void EQPlayer::KnockedOut(void);
EQLIB_OBJECT void EQPlayer::MakeRiderMountUp(void);
EQLIB_OBJECT void EQPlayer::MountEQPlayer(class EQPlayer *);
EQLIB_OBJECT void EQPlayer::PlaySoundA(int);
EQLIB_OBJECT void EQPlayer::PositionOnFloor(void);
EQLIB_OBJECT void EQPlayer::PushAlongHeading(float);
EQLIB_OBJECT void EQPlayer::PutPlayerOnFloor(void);
EQLIB_OBJECT void EQPlayer::ResetVariables(void);
EQLIB_OBJECT void EQPlayer::SetAccel(float,int);
EQLIB_OBJECT void EQPlayer::SetAfk(int);
EQLIB_OBJECT void EQPlayer::SetAndReserveID(unsigned int);
EQLIB_OBJECT void EQPlayer::SetAnimVariation(void);
EQLIB_OBJECT void EQPlayer::SetArmorTint(int,unsigned long);
EQLIB_OBJECT void EQPlayer::SetArmorType(int,int);
EQLIB_OBJECT void EQPlayer::SetCurrentLoopSound(int);
EQLIB_OBJECT void EQPlayer::SetDefaultFacialFeaturesByFace(int,unsigned char,unsigned char);
EQLIB_OBJECT void EQPlayer::SetDefaultITAttachments(int);
EQLIB_OBJECT void EQPlayer::SetHeights(void);
EQLIB_OBJECT void EQPlayer::SetInvited(bool);
EQLIB_OBJECT void EQPlayer::SetPlayerConstantAmbient(struct T3D_RGB *);
EQLIB_OBJECT void EQPlayer::SetRace(int);
EQLIB_OBJECT void EQPlayer::SetSounds(void);
EQLIB_OBJECT void EQPlayer::SetToRandomRace(void);
EQLIB_OBJECT void EQPlayer::TouchingSwitch(void);
EQLIB_OBJECT void EQPlayer::TriggerSpellEffect(struct _EQMissileHitinfo *);
EQLIB_OBJECT void EQPlayer::TurnOffAutoFollow(void);
EQLIB_OBJECT void EQPlayer::UpdateAppearance(void);
EQLIB_OBJECT void EQPlayer::UpdateBonePointers(void);
EQLIB_OBJECT void EQPlayer::UpdateNameSprite(void);
EQLIB_OBJECT void EQPlayer::UpdatePlayerVisibility(void);
EQLIB_OBJECT bool EQPlayer::HasProperty(unsigned int,int,int);
EQLIB_OBJECT class CLineSegment &EQPlayer::GetVisibilityLineSegment(class CLineSegment&ls, class EQPlayer& pSpawn, unsigned int index = 0);//index MUST be 0
// private
EQLIB_OBJECT int EQPlayer::IdUsed(unsigned int);
EQLIB_OBJECT static class EQPlayer * EQPlayer::mTop;
EQLIB_OBJECT struct S3D_STRINGSPRITE * EQPlayer::ChangeBoneStringSprite(struct T3D_DAG *,char *);
EQLIB_OBJECT unsigned char EQPlayer::GetAlternateAnimVariation(int,unsigned char);
EQLIB_OBJECT unsigned int EQPlayer::GetUnusedID(void);
EQLIB_OBJECT void EQPlayer::FindDefaultEyeMaterialIndexes(void);
EQLIB_OBJECT void EQPlayer::InitializeIDArray(void);
EQLIB_OBJECT BYTE EQPlayer::GetLevel(void) const;

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
	/*0x00*/ void   *vftable;
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
/*0x00*/ void   *vftable;
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

//class PlayerBase : public PlayerBaseVfTable,public TListNode<PlayerBase>
{
public:
/*0x0010*/ FLOAT	JumpStrength;
/*0x0014*/ FLOAT	SwimStrength;
/*0x0018*/ FLOAT	SpeedMultiplier;
/*0x001c*/ FLOAT	AreaFriction;
/*0x0020*/ FLOAT	AccelerationFriction;
/*0x0024*/ EActorType CollidingType; /* ok finally had time to get this one right, when we collide with something this gets set. */
/*0x0028*/ FLOAT	FloorHeight;
/*0x002c*/ bool		bSinksInWater;
/*0x0030*/ UINT		PlayerTimeStamp; /* doesn't update when on a Vehicle (mounts/boats etc) */
/*0x0034*/ UINT		LastTimeIdle;
/*0x0038*/ CHAR		Lastname[0x20];
/*0x0058*/ FLOAT	AreaHPRegenMod; /*from guild hall pools etc. */
/*0x005c*/ FLOAT	AreaEndRegenMod;
/*0x0060*/ FLOAT	AreaManaRegenMod;
/*0x0064*/ FLOAT	Y;
/*0x0068*/ FLOAT	X;
/*0x006c*/ FLOAT	Z;
/*0x0070*/ FLOAT	SpeedY;
/*0x0074*/ FLOAT	SpeedX;
/*0x0078*/ FLOAT	SpeedZ;
/*0x007c*/ FLOAT	SpeedRun;
/*0x0080*/ FLOAT	Heading;
/*0x0084*/ FLOAT	Angle;
/*0x0088*/ FLOAT	AccelAngle;
/*0x008c*/ FLOAT	SpeedHeading;
/*0x0090*/ FLOAT	CameraAngle;
/*0x0094*/ UINT		UnderWater; /*LastHeadEnvironmentType */
/*0x0098*/ UINT		LastBodyEnvironmentType;
/*0x009c*/ UINT		LastFeetEnvironmentType;
/*0x00a0*/ BYTE		HeadWet; /*these really are environment related, like lava as well for example */
/*0x00a1*/ BYTE		FeetWet;
/*0x00a2*/ BYTE		BodyWet;
/*0x00a3*/ BYTE		LastBodyWet;
/*0x00a4*/ CHAR		Name[0x40];             /* ie priest_of_discord00 */
/*0x00e4*/ CHAR		DisplayedName[0x40];    /* ie Priest of Discord*/
/*0x0124*/ BYTE		PossiblyStuck;          /* never seen this be 1 so maybe it was used a a point but not now... */
/*0x0125*/ BYTE		Type;
/*0x0128*/ DWORD**	BodyType;	/* this really should be renamed to charprops or something its broken anyway*/
/*0x012c*/ BYTE		CharPropFiller[0xc]; /* well since the above is a CharacterPropertyHash we have to pad here...*/
/*0x0138*/ FLOAT	AvatarHeight;           /* height of avatar from groundwhen standing*/
/*0x013c*/ FLOAT	Height;
/*0x0140*/ FLOAT	Width;
/*0x0144*/ FLOAT	Length;
/*0x0148*/ DWORD	SpawnID;
/*0x014c*/ DWORD	PlayerState;         /* 0=Idle 1=Open 2=WeaponSheathed 4=Aggressive 8=ForcedAggressive 0x10=InstrumentEquipped 0x20=Stunned 0x40=PrimaryWeaponEquipped 0x80=SecondaryWeaponEquipped */
/*0x0150*/ struct _SPAWNINFO*	Vehicle;    /* NULL until you collide with a vehicle (boat,airship etc) */
/*0x0154*/ struct _SPAWNINFO*	Mount;      /* NULL if no mount present */
/*0x0158*/ struct _SPAWNINFO*	Rider;      /* _SPAWNINFO of mount's rider */
/*0x015c*/ DWORD	Unknown0x015c;
/*0x0160*/ bool		Targetable;	/* true if mob is targetable */
/*0x0161*/ bool		bTargetCyclable;
/*0x0162*/ bool		bClickThrough;
/*0x0163*/ bool		bBeingFlung;
/*0x0164*/ UINT		FlingActiveTimer;
/*0x0168*/ UINT		FlingTimerStart;
/*0x016c*/ bool		bFlingSomething;
/*0x0170*/ FLOAT	FlingY;
/*0x0174*/ FLOAT	FlingX;
/*0x0178*/ FLOAT	FlingZ;
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
/*0x0614*/ TCircularBuffer<SDoCollisionMovementStats, 0x14>MovementStats; /* size (0x74 * 0x14) +8 = 0x918 */
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
/*0x1148*/ PlayerAnimationBase *pAnimation;
/*0x114c*/ FLOAT	MeleeRadius;      // used by GetMeleeRange
/*0x1150*/ UINT		CollisionCounter;
/*0x1154*/ FLOAT	CachedFloorLocationY;
/*0x1158*/ FLOAT	CachedFloorLocationX;
/*0x115c*/ FLOAT	CachedFloorLocationZ;
/*0x1160*/ FLOAT	CachedFloorHeight;
/*0x1164*/ FLOAT	CachedCeilingLocationY;
/*0x1168*/ FLOAT	CachedCeilingLocationX;
/*0x116c*/ FLOAT	CachedCeilingLocationZ;
/*0x1170*/ FLOAT	CachedCeilingHeight;
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
/*0x1198*/ int		Animation; //0x1198 confirmed Apr 24 2017 always on 8 alignment? /* Current Animation Playing. */
/*0x11xx*/ int		NextAnim;
/*0x11xx*/ int		CurrLowerBodyAnim;
/*0x1194*/ int		NextLowerBodyAnim;
/*0x1198*/ int		CurrLowerAnimVariation;
/*0x119c*/ int		CurrAnimVariation;
/*0x11a0*/ int		CurrAnimRndVariation;
/* ********************sound ID's BEGIN ******************* */
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
/* ******************** sound ID's END ****************** */
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
/*0x1288*/ UINT		MercID;    // IT IS 0x1288      //if the spawn is player and has a merc up this is it's spawn ID -eqmule 16 jul 2014
/*0x128c*/ UINT		ContractorID;    //if the spawn is a merc this is its contractor's spawn ID -eqmule 16 jul 2014
/*0x1290*/ FLOAT	CeilingHeightAtCurrLocation;
/*0x1294*/ void		*MobileEmitter;//todo: change and map to EqMobileEmitter*
/*0x1298*/ bool		bInstantHPGaugeChange;
/*0x129c*/ UINT		LastUpdateReceivedTime;
/*0x12a0*/ FLOAT	MaxSpeakDistance;
/*0x12a4*/ FLOAT	WalkSpeed;//how much we will slow down while sneaking
/*0x12a8*/ bool		bHideCorpse;// IT IS 0x12a8
/*0x12a9*/ CHAR		AssistName[0x40];
/*0x12E9*/ bool		InvitedToGroup;//IT IS 12E9!
/*0x12ec*/ int		GroupMemberTargeted;//12ec for sure!    // 0xFFFFFFFF if no target, else 1 through 5
/*0x12f0*/ bool		bRemovalPending;
/*0x12f4*/ void		*pCorpse;//look into 0x12f4 for sure!
/*0x12f8*/ FLOAT	EmitterScalingRadius;//0x12f8 FOR SURE
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
/*0x1E60*/ FLOAT	CampfireY;
/*0x1e64*/ FLOAT	CampfireX;
/*0x1e68*/ FLOAT	CampfireZ;
/*0x1e6c*/ int		CampfireZoneID;         // zone ID where campfire is
/*0x1e70*/ int		CampfireTimestamp;      // CampfireTimestamp-FastTime()=time left on campfire
/*0x1e74*/ int		CampfireTimestamp2;
/*0x1e78*/ int		FellowShipID;
/*0x1e7c*/ int		FellowShipID2;
/*0x1e80*/ int		CampType;
/*0x1e84*/ bool		Campfire;
/*0x1e88*/ TSafeArrayStatic<int,3> SeeInvis;
/*0x1E94*/ struct _EQUIPMENT	Equipment;// size 0xb4
/*0x1F48*/ bool		bIsPlacingItem;
/*0x1f49*/ bool		bGMCreatedNPC;
/*0x1f4c*/ int		ObjectAnimationID;
/*0x1f50*/ bool		bInteractiveObjectCollidable;
/*0x1f54*/ int		InteractiveObjectType;
/*0x1f58*/ int		SoundIDs[0xa];//0x28 bytes
/*0x1f80*/ UINT		LastHistorySentTime;
/*0x1f84*/ ArrayClass2_RO<UINT>	BardTwistSpells;//size 0x1c
/*0x1fA0*/ __int64		CurrentBardTwistIndex;
/*0x1fA8*/ PlayerPhysicsClient mPlayerPhysicsClient;//size 0x28
/*0x1Fd0*/ int		SpawnStatus[6];//todo: look closer at these i think they can show like status of mobs slowed, mezzed etc, but not sure
/*0x1fe8*/ int		BannerIndex0;//guild banners
/*0x1fec*/ int		BannerIndex1;
/*0x1ff0*/ ARGBCOLOR BannerTint0;
/*0x1ff4*/ ARGBCOLOR BannerTint1;
/*0x1ff8*/ int		MountAnimationRelated;
/*0x1ffc*/ bool		bGuildShowAnim;//or sprite? need to check
/*0x1ffd*/ bool		bWaitingForPort;//check this
EQLIB_OBJECT PcClient * PlayerClient::GetPcClient(void)const;//call this using pLocalPlayer->GetPcClient();
inline signed int GetClass()
{
	return mActorClient.Class;
}
inline void*GetCharacter()
{
	return (void*)spawneqc_info;//its a CharacterZoneClient*
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
/*0x00*/ HashTable<EffectCache> *pCachedEffects;
/*0x04*/ bool bCachedSpellEffects;
/*0x08*/ HashTable<AltEffectCache> *pCachedAltAbilityEffects;
/*0x0c*/ bool bCachedAltEffects;
/*0x10*/ HashTable<EffectCache> *pCachedLimitedEffects;
/*0x14*/ bool bCachedLimitedEffects;
/*0x18*/ HashTable<CachedFocusItem, __int64>		CachedFocusItems;
/*0x28*/ HashTable<CachedFocusEffect, __int64>		CachedFocusEffects;
/*0x38*/ HashTable<CachedFocusAbility, __int64>		CachedFocusAbilities;
/*0x48*/ HashTable<CachedFocusMercAbility, __int64>	CachedFocusMercAbilities;
/*0x58*/ 
};
class SomeClass
{
public:
/*0x0000*/ void *CharacterZoneClient_vftable;
};

enum GILocationOption
{
	Bag_Or_Base,
	Socket
};
class CharacterBase
{
public:
/*0x0000*/ void *CharacterBase_vftable;
/*0x0004*/ CProfileManager ProfileManager;//size 0x8
/*0x000C*/ TSafeArrayStatic<BYTE, 0x20>	languages;
/*0x002C*/ FLOAT         X;
/*0x0030*/ FLOAT         Y;
/*0x0034*/ FLOAT         Z;
/*0x0038*/ FLOAT         Heading;
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
	EQLIB_OBJECT unsigned int CharacterBase::GetEffectId(int index);

	EQLIB_OBJECT LONG CharacterBase::GetMemorizedSpell(int gem);//0-0xf this func returns the spellid for whatever is in the gem
	EQLIB_OBJECT ItemGlobalIndex CreateItemGlobalIndex(int Slot0, int Slot1 = -1, int Slot2 = -1);
	EQLIB_OBJECT ItemIndex CreateItemIndex(int Slot0, int Slot1=-1, int Slot2=-1);
	inline const BaseProfile& GetCurrentBaseProfile() const
	{
		//CharacterBase*bp = (CharacterBase*)*this;
		return *ProfileManager.GetCurrentProfile();
	}
	EQLIB_OBJECT BYTE CharacterBase::GetLanguageSkill(int)const;
	EQLIB_OBJECT VePointer<CONTENTS> CharacterBase::GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex) const;
	EQLIB_OBJECT VePointer<CONTENTS> CharacterBase::GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex, GILocationOption Option) const;
	EQLIB_OBJECT VePointer<CONTENTS> CharacterBase::GetItemPossession(const ItemIndex &lIndex) const;
};

EQLIB_OBJECT char * build_token_string_PARAM(char *pBuffer, int token, const char *param0=NULL, const char *param1=NULL,
								const char *param2=NULL, const char *param3=NULL, const char *param4=NULL, const char *param5=NULL, 
								const char *param6=NULL, const char *param7=NULL, const char *param8=NULL);

class CharacterZoneClient : public SomeClass, virtual public CharacterBase
{
public:
union {
/*0x2424*/ PlayerClient *me;//just here for comparing the 2, todo: fix
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
/*0x25e8*/ HashListSet<int, 0x80>   DoomEffectsBySlot;//size 0x10 + (0x80 * 4)
/*0x27f8*/ UINT		LastHitEval;
/*0x27fc*/

EQLIB_OBJECT CharacterZoneClient::CharacterZoneClient(void);
EQLIB_OBJECT int CharacterZoneClient::CalcAffectChange(const EQ_Spell *spell, BYTE casterLevel, BYTE affextIndex, const EQ_Affect *theAffect, int EffectIndex = 0, PlayerZoneClient *pCaster = NULL,bool overrideChangeVal = false, int ChangeVal = -1,bool bCap = true);
EQLIB_OBJECT int CharacterZoneClient::CalcAffectChangeGeneric(const EQ_Spell *spell, BYTE casterLevel, BYTE affextIndex, const EQ_Affect *theAffect, int EffectIndex, bool bCap = true);
EQLIB_OBJECT void CharacterZoneClient::MakeMeVisible(int,bool);
EQLIB_OBJECT int CharacterZoneClient::GetItemCountWorn(int);
EQLIB_OBJECT int CharacterZoneClient::GetItemCountInInventory(int);
EQLIB_OBJECT int CharacterZoneClient::GetCursorItemCount(int);
EQLIB_OBJECT bool CharacterZoneClient::HasSkill(int);
EQLIB_OBJECT EQ_Affect *CharacterZoneClient::FindAffectSlot(int SpellID, PSPAWNINFO Caster, int *slindex, bool bJustTest, int CasterLevel = -1, EQ_Affect* BuffArray = NULL, int BuffArraySize = 0, bool bFailAltAbilities = true);
EQLIB_OBJECT EQ_Affect *CharacterZoneClient::FindAffectSlotMine(int SpellID, PSPAWNINFO Caster, int *slindex, bool bJustTest, int CasterLevel = -1, EQ_Affect* BuffArray = NULL, int BuffArraySize = 0, bool bFailAltAbilities = true);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT bool CharacterZoneClient::IsStackBlocked(const EQ_Spell *pSpell, PSPAWNINFO pCaster, EQ_Affect* pEffecs = NULL, int EffectsSize = 0, bool bMessageOn = false);
#else
EQLIB_OBJECT bool CharacterZoneClient::IsStackBlocked(const EQ_Spell *pSpell, PSPAWNINFO pCaster, EQ_Affect* pEffecs = NULL, int EffectsSize = 0);
#endif
EQLIB_OBJECT int CharacterZoneClient::BardCastBard(const EQ_Spell* pSpell, signed int caster_class) const;
EQLIB_OBJECT unsigned char CharacterZoneClient::GetMaxEffects(void)const;
EQLIB_OBJECT EQ_Affect & CharacterZoneClient::GetEffect(int)const;
EQLIB_OBJECT int CharacterZoneClient::GetOpenEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill, int Index = -1);
EQLIB_OBJECT int CharacterZoneClient::GetFirstEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill);
EQLIB_OBJECT int CharacterZoneClient::GetLastEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill, bool bIsDisplay = false);
EQLIB_OBJECT const int CharacterZoneClient::GetFocusReuseMod(const EQ_Spell *pSpell, VePointer<CONTENTS>&pOutItem);
EQLIB_OBJECT bool CharacterZoneClient::FindItemByGuid(const EqItemGuid& ItemGuid, int *pos_slot, int *con_slot);
EQLIB_OBJECT BYTE CharacterZoneClient::FindItemByRecord(int ItemNumber /*recordnum*/, int *pos_slot, int *con_slot, bool bReverseLookup);
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
	//*0x0008*/void *vfTable_CharacterZoneClient;
//*0x0008*/void *vfTable_CharacterBase;
//*0x000C*/void *vfTable_PcBase;
//last one changed 
/*0x000C*/ virtual void vftableph(void) {};
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
/*0x12a8*/ __int64      GuildID;//GuildID_0
/*0x12b0*/ __int64		FellowshipID;
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
/*0x1320*/ __int64      CareerFavor;
/*0x1328*/ __int64      CurrFavor;
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
/*0x1aa8*/ __int64		RaidId;//could be int
/*0x1ab0*/ __int64		GroupID;//could be int
/*0x1ab8*/ __int64      Exp;//confirmed mar 7 2017 test
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
/*0x1b18*/ __int64      LastTestCopyTime;
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
/*0x1c6c*/ FLOAT        ActivityValue;
/*0x1c70*/ UINT         NextItemId;
/*0x1c74*/ _CXSTR       *SharedBank;
/*0x1c78*/ _CXSTR       *BankBuffer;
/*0x1c7c*/ _CXSTR       *OverflowBuffer;
/*0x1c80*/ _CXSTR       *LimboBuffer;
/*0x1c84*/ _CXSTR       *MercenaryBuffer;
/*0x1c88*/ _CXSTR       *KeyRingBuffer[3];
/*0x1c94*/ _CXSTR       *AltStorageBuffer;
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
/*0x1f50*/ unsigned __int64	CreatedGuildID;
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
/*0x1f98*/ __int64      MercAAExp;// divide this with 3.30f and you get the percent - eqmule
/*0x1fa0*/ DWORD        MercAAPoints;//number of unspent merc AA points
/*0x1fa4*/ DWORD        MercAAPointsSpent;//number of spent merc AA points
/*0x1fa8*/ ArrayClass_RO<MercenaryAbilityInfo*>	MercenaryAbilities;
/*0x1fb8*/ HashTable<CompletedAchievementData, int, ResizePolicyNoShrink> CompletedAchievements;
/*0x1fc8*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> CompletedEventBasedSubComponents;
/*0x1fd8*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> OpenEventBasedSubComponents;
/*0x1fe8*/ int		LastFellowshipJoin;
/*0x1ff0*/ __int64      Vitality;
/*0x1ff8*/ int		    AAVitality;
/*0x1ffc*/ int		    Unknown0x1ffc;
/*0x2000*/ int          FPStuff[0x1c];
/*0x2070*/ //CharacterZoneClient
};
class DebugText
{
public:
	//virtual void vftableph(void) {};
	//void *vfTable_DebugText;
};
class PcZoneClient: public PcBase , public CharacterZoneClient , public DebugText
{
public:
/*0x245c*/ void *vfTable_PcZoneClient;
/*0x2460*/ TSafeArrayStatic<unsigned long, 3> Flags;//hmm
/*0x246C*/ unsigned __int32 TransfersReceived;
/*0x2470*/ int	LastLanguageSpoken;
/*0x2474*/ int CurPowerSourceDrain;
/*0x2478*/ EQList<ALCHEMYBONUSSKILLDATA*> AlchemyBaseSkillBonusList;
/*0x2488*/ UINT MomentumBalance; 
/*0x248C*/ UINT LoyaltyRewardBalance;
/*0x2490*/

EQLIB_OBJECT int PcZoneClient::GetPcSkillLimit(int);
EQLIB_OBJECT bool PcZoneClient::HasCombatAbility(int);
EQLIB_OBJECT void PcZoneClient::RemovePetEffect(int);
EQLIB_OBJECT bool PcZoneClient::CanEquipItem(PCONTENTS *pCont, int slotid, bool bOutputDebug, bool bUseRequiredLevel);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT bool PcZoneClient::HasAlternateAbility(int aaindex, int *, bool, bool);
#else
EQLIB_OBJECT bool PcZoneClient::HasAlternateAbility(int aaindex, int *, bool);
#endif
EQLIB_OBJECT int PcZoneClient::GetCurrentMod(int index);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_OBJECT int PcZoneClient::GetModCap(int index, bool bToggle=false);
#else
EQLIB_OBJECT int PcZoneClient::GetModCap(int index);
#endif
EQLIB_OBJECT void PcZoneClient::RemoveBuffEffect(int Index, int SpawnID);
EQLIB_OBJECT PCONTENTS * PcZoneClient::GetItemByID(PCONTENTS *contOut, int itemid, ItemIndex *itemindex/*out*/);
EQLIB_OBJECT PCONTENTS * PcZoneClient::GetItemByItemClass(PCONTENTS *contOut, int itemclass, ItemIndex *itemindex/*out*/);
EQLIB_OBJECT void PcZoneClient::BandolierSwap(int index);
EQLIB_OBJECT UINT PcZoneClient::GetLinkedSpellReuseTimer(int index);
};

class PcClient// : public PcZoneClient
{
	//has a vftable but we get it from PcZoneClient
public:
	EQLIB_OBJECT PcClient::PcClient();
	BYTE Filler[0x2b10];
};
class tettt
{
/*0x2490*/ ExtendedTargetListClient* pXTargetMgr;
/*0x2494*/ bool bInCombat;
/*0x2498*/ UINT Downtime;
/*0x249c*/ UINT DowntimeStamp;
/*0x24a0*/ bool bOverrideAvatarProximity;
/*0x24a4*/ CGroupClient *pGroup;
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
EQLIB_OBJECT class EQPlayer *EQPlayerManager::GetSpawnByID(int);
EQLIB_OBJECT class EQPlayer *EQPlayerManager::GetSpawnByName(char *);
EQLIB_OBJECT class EQPlayer *EQPlayerManager::GetPlayerFromPartialName(char const *, class PlayerBase *);

EQLIB_OBJECT class EQPlayer *EQPlayerManager::GetSpawnByName2(CXStr *,int);
SPAWNMANAGER Data;
};

class EQPMInfo
{
public:
EQLIB_OBJECT EQPMInfo::~EQPMInfo(void);
EQLIB_OBJECT EQPMInfo::EQPMInfo(char *);
EQLIB_OBJECT void EQPMInfo::SetApplyGravity(bool);
};

class EqSoundManager
{
public:
EQLIB_OBJECT EqSoundManager::~EqSoundManager(void);
//EQLIB_OBJECT EqSoundManager::EqSoundManager(bool,bool,enum SpeakerType);
EQLIB_OBJECT bool EqSoundManager::EmitterLoad(char *);
EQLIB_OBJECT bool EqSoundManager::WaveIsPlaying(int);
EQLIB_OBJECT class SoundAsset * EqSoundManager::WaveGet(int);
//EQLIB_OBJECT enum EnvironmentType EqSoundManager::GetListenerEnvironment(void);
EQLIB_OBJECT void EqSoundManager::EmitterAdd(class EqEmitterData *);
EQLIB_OBJECT void EqSoundManager::EmitterSetIndoors(bool);
EQLIB_OBJECT void EqSoundManager::EmitterSetNight(bool);
EQLIB_OBJECT void EqSoundManager::EmitterSetRaining(bool);
EQLIB_OBJECT void EqSoundManager::EmitterSetUserDisabled(bool);
EQLIB_OBJECT void EqSoundManager::EmitterSetWind(bool);
EQLIB_OBJECT void EqSoundManager::GiveTime(void);
EQLIB_OBJECT void EqSoundManager::SetCurrentZone(char *);
EQLIB_OBJECT void EqSoundManager::SetEffectsLevel(float);
//EQLIB_OBJECT void EqSoundManager::SetListenerEnvironment(enum EnvironmentType);
EQLIB_OBJECT void EqSoundManager::SetListenerEnvironmentHigh(void);
EQLIB_OBJECT void EqSoundManager::SetListenerEnvironmentLow(void);
EQLIB_OBJECT void EqSoundManager::SetListenerEnvironmentOutside(void);
EQLIB_OBJECT void EqSoundManager::SetListenerLocation(float,float,float,float);
EQLIB_OBJECT void EqSoundManager::SetMixAhead(int);
EQLIB_OBJECT void EqSoundManager::SetMusicSelection(int,bool);
EQLIB_OBJECT void EqSoundManager::SetMusicVolume(float);
EQLIB_OBJECT void EqSoundManager::SetWaveVolume(float);
EQLIB_OBJECT void EqSoundManager::WaveLoad(char *,int,bool);
EQLIB_OBJECT void EqSoundManager::WavePlay(int,class SoundControl *);
EQLIB_OBJECT void EqSoundManager::WaveStop(int);
// private
EQLIB_OBJECT class SoundAsset * EqSoundManager::GetAsset(char *);
EQLIB_OBJECT class SoundAsset * EqSoundManager::OldMp3GetSelection(int);
EQLIB_OBJECT class SoundEmitter * EqSoundManager::CreateOldEmitter(int,float,float,float,int,int,int,float,int,int,int);
EQLIB_OBJECT int EqSoundManager::GetMusicId(void);
EQLIB_OBJECT void EqSoundManager::LoadGlobalEmitters(void);
EQLIB_OBJECT void EqSoundManager::LoadGlobalMusic(void);
EQLIB_OBJECT void EqSoundManager::LoadGlobalWaves(void);
EQLIB_OBJECT void EqSoundManager::LoadListOfWaveFiles(char * *,int);
EQLIB_OBJECT void EqSoundManager::LoadOldEmitters(void);
EQLIB_OBJECT void EqSoundManager::OldMp3ClearSelections(void);
EQLIB_OBJECT void EqSoundManager::OldMp3Init(void);
EQLIB_OBJECT void EqSoundManager::OldMp3Terminate(void);
EQLIB_OBJECT void EqSoundManager::PlayScriptMp3(char *Name, float Vol = 1.00f);
EQLIB_OBJECT void EqSoundManager::ReleaseZoneSpecificEmitters(void);
EQLIB_OBJECT void EqSoundManager::ReleaseZoneSpecificMidi(void);
EQLIB_OBJECT void EqSoundManager::ReleaseZoneSpecificWaves(void);
EQLIB_OBJECT void EqSoundManager::UpdateEmitterStates(void);
	Mp3Manager *pMp3Manager;
	SoundManager *pSoundManager;
	EmitterManager *pEmitterManager;
	MusicManager *pMusicManager;
	SoundAsset *pGlobalMidiAsset;
	SoundAsset *pOpenerMidiAsset;
	SoundAsset *pOpenerMp3Asset;
	SoundAsset *pDeathMp3Asset;
	SoundAsset *pCombatMp3Asset;
	SoundAsset *pMerchantMp3Asset;
	SoundAsset *pZoneMidiAsset;
	SoundAsset *pScriptMp3Asset;
	bool bDisabled;
	int NextMusicID;
	SoundEmitter *pEmitters[1000];
	int EmittersCount;
	SoundEmitter *pRainEmitter;
	SoundEmitter *pWindEmitter;
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
EQLIB_OBJECT EQSwitch::~EQSwitch(void);
EQLIB_OBJECT EQSwitch::EQSwitch(char *,bool);
EQLIB_OBJECT EQSwitch::EQSwitch(struct _EQClientSwitch *);
EQLIB_OBJECT EQSwitch::EQSwitch(struct OldDiskSwitch *,bool);
EQLIB_OBJECT float EQSwitch::GetCustomMoveDistance(void);
EQLIB_OBJECT float EQSwitch::TopSpeed(float *);
EQLIB_OBJECT int EQSwitch::GetSwitchDamage(void);
EQLIB_OBJECT unsigned char EQSwitch::SwitchIsNotUsable(int);
EQLIB_OBJECT unsigned char EQSwitch::SwitchWasOpened(int,int,class EQPlayer *,bool *);
EQLIB_OBJECT unsigned char EQSwitch::SwitchWasOpenedActual(int,int,class EQPlayer *,bool *);
EQLIB_OBJECT unsigned int EQSwitch::RepopFrequency(void);
EQLIB_OBJECT void EQSwitch::ChangeState(unsigned char,class EQPlayer *,bool);
EQLIB_OBJECT void EQSwitch::LoadSwitchSounds(int);
EQLIB_OBJECT void EQSwitch::PostInit(void);
EQLIB_OBJECT void EQSwitch::PreInit(void);
EQLIB_OBJECT void EQSwitch::RepopSwitch(void);
EQLIB_OBJECT void EQSwitch::ResetSwitchState(unsigned char);
EQLIB_OBJECT void EQSwitch::UseSwitch(UINT SpawnID,int KeyID,int PickSkill,const CVector3* hitloc = 0);
};

class EqSwitchManager
{
public:
EQLIB_OBJECT EqSwitchManager::~EqSwitchManager(void);
EQLIB_OBJECT EqSwitchManager::EqSwitchManager(void);
EQLIB_OBJECT class EQSwitch * EqSwitchManager::GetSwitch(int);
EQLIB_OBJECT class EQSwitch * EqSwitchManager::GetSwitchByActor(struct T3D_tagACTORINSTANCE *);
EQLIB_OBJECT class EQSwitch * EqSwitchManager::GetSwitchById(int,bool);
EQLIB_OBJECT int EqSwitchManager::GetCount(void);
EQLIB_OBJECT void EqSwitchManager::AddSwitch(class EQSwitch *);
EQLIB_OBJECT void EqSwitchManager::DeleteAll(void);
EQLIB_OBJECT void EqSwitchManager::Load(char *,bool);
// protected
EQLIB_OBJECT void EqSwitchManager::LoadOld(char *,bool);
};

class EQUtil
{
public:
EQLIB_OBJECT static char * __cdecl EQUtil::FormatCharName(char *,char *,int);
};

class EQWorldData
{
public:
EQLIB_OBJECT EQWorldData::EQWorldData(void);
EQLIB_OBJECT bool EQWorldData::GetGeometryNameFromIndex(EQZoneIndex,char *)const;
EQLIB_OBJECT bool EQWorldData::IsFlagSet(EQZoneIndex,unsigned long)const;
EQLIB_OBJECT bool EQWorldData::IsNewbieZone(EQZoneIndex)const;
EQLIB_OBJECT bool EQWorldData::IsNoAirZone(EQZoneIndex)const;
EQLIB_OBJECT bool EQWorldData::IsNoBindZone(EQZoneIndex)const;
EQLIB_OBJECT bool const EQWorldData::AddZone(enum EQExpansion,EQZoneIndex,char const *,char const *,int,unsigned long,int,int);
//EQLIB_OBJECT enum EQExpansion const EQWorldData::ExpansionZone(EQZoneIndex)const;
EQLIB_OBJECT DWORD EQWorldData::GetIndexFromZoneName(char const *); // EQZoneIndex
EQLIB_OBJECT int EQWorldData::GetMinLevel(EQZoneIndex)const;
EQLIB_OBJECT void EQWorldData::AdvanceTime(unsigned int);
EQLIB_OBJECT void EQWorldData::CurrentGameTime(char *);
EQLIB_OBJECT void EQWorldData::GetFullZoneName(EQZoneIndex,char *);
// virtual
EQLIB_OBJECT EQWorldData::~EQWorldData(void);
//EQLIB_OBJECT void * EQWorldData::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * EQWorldData::`vector deleting destructor'(unsigned int);
};

class EQZoneInfo
{
public:
EQLIB_OBJECT EQZoneInfo::EQZoneInfo(enum EQExpansion,EQZoneIndex,char const *,char const *,int,unsigned long,int,int);
// virtual
EQLIB_OBJECT EQZoneInfo::~EQZoneInfo(void);
//EQLIB_OBJECT void * EQZoneInfo::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * EQZoneInfo::`vector deleting destructor'(unsigned int);
};

class FilePath
{
public:
EQLIB_OBJECT FilePath::~FilePath(void);
EQLIB_OBJECT FilePath::FilePath(char const *);
EQLIB_OBJECT FilePath::FilePath(class SharedString const &);
EQLIB_OBJECT FilePath::FilePath(void);
};

class flex_unit
{
public:
EQLIB_OBJECT flex_unit::~flex_unit(void);
EQLIB_OBJECT flex_unit::flex_unit(void);
EQLIB_OBJECT unsigned int flex_unit::get(unsigned int)const;
EQLIB_OBJECT void flex_unit::clear(void);
EQLIB_OBJECT void flex_unit::fast_mul(class flex_unit &,class flex_unit &,unsigned int);
EQLIB_OBJECT void flex_unit::reserve(unsigned int);
EQLIB_OBJECT void flex_unit::set(unsigned int,unsigned int);
};

class GrammarRulesClass
{
public:
EQLIB_OBJECT GrammarRulesClass::GrammarRulesClass(void);
EQLIB_OBJECT char * GrammarRulesClass::Resolve(int,int,char *,char *);
// virtual
EQLIB_OBJECT GrammarRulesClass::~GrammarRulesClass(void);
//EQLIB_OBJECT void * GrammarRulesClass::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * GrammarRulesClass::`vector deleting destructor'(unsigned int);
// private
EQLIB_OBJECT char * GrammarRulesClass::Parse(char *);
EQLIB_OBJECT void GrammarRulesClass::RuleDe1(char *,char *);
EQLIB_OBJECT void GrammarRulesClass::RuleEn1(char *,char *);
EQLIB_OBJECT void GrammarRulesClass::RuleEn2(char *,char *);
EQLIB_OBJECT void GrammarRulesClass::RuleEn3(char *,char *,char *,char *);
EQLIB_OBJECT void GrammarRulesClass::RuleEn4(char *,char *,char *,char *);
EQLIB_OBJECT void GrammarRulesClass::RuleFr1(char *,char *,char *,char *);
EQLIB_OBJECT void GrammarRulesClass::RuleKo1(char *,char *,char *,char *);
};

class GuildMember
{
public:
EQLIB_OBJECT GuildMember::GuildMember(void);
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
EQLIB_OBJECT IconCache::~IconCache(void);
EQLIB_OBJECT IconCache::IconCache(void);
EQLIB_OBJECT class CTextureAnimation * IconCache::GetIcon(int);
};



class JournalNPC
{
public:
EQLIB_OBJECT JournalNPC::~JournalNPC(void);
EQLIB_OBJECT JournalNPC::JournalNPC(void);
EQLIB_OBJECT int JournalNPC::AddEntry(long,float,float,float,char *,int);
EQLIB_OBJECT int JournalNPC::AddEntry(long,float,float,float,int,int);
EQLIB_OBJECT int JournalNPC::DeleteEntryByHash(int);
EQLIB_OBJECT int JournalNPC::DeleteEntryByIndex(int);
EQLIB_OBJECT int JournalNPC::FindThisText(char *,bool,int);
EQLIB_OBJECT int JournalNPC::ReadEntry(struct _iobuf *);
EQLIB_OBJECT static char * __cdecl JournalNPC::GetText(int);
EQLIB_OBJECT struct JournalEntry * JournalNPC::FindEntryByCategory(int,int);
EQLIB_OBJECT struct JournalEntry * JournalNPC::FindEntryByHash(int);
EQLIB_OBJECT struct JournalEntry * JournalNPC::GetEntry(int);
EQLIB_OBJECT void JournalNPC::ConvertCategory(int,int);
// private
EQLIB_OBJECT void JournalNPC::AllocateArray(void);
EQLIB_OBJECT void JournalNPC::CleanEntries(void);
EQLIB_OBJECT void JournalNPC::ComputeLatestTime(void);
};

class KeyCombo
{
public:
EQLIB_OBJECT KeyCombo::KeyCombo(int);
inline EQLIB_OBJECT KeyCombo::KeyCombo(unsigned char keycode,bool alt,bool ctrl,bool shift)
{    
    Data[3]= keycode;
    Data[0]=alt;
    Data[1]=ctrl;
    Data[2]=shift;
}
EQLIB_OBJECT KeyCombo::KeyCombo(unsigned int,unsigned int,bool,bool,bool);
inline EQLIB_OBJECT KeyCombo::KeyCombo(void)
{
    *(unsigned long*)&Data[0]=0;
}
inline void EQLIB_OBJECT KeyCombo::Clear(void)
{
    *(unsigned long*)&Data[0]=0;
}
EQLIB_OBJECT int KeyCombo::operator int(void)const;
EQLIB_OBJECT bool KeyCombo::GetPrintableLetter(unsigned short *)const;
inline EQLIB_OBJECT bool KeyCombo::UsesAlt(void)const
{
    return (Data[0]!=0);
}
inline EQLIB_OBJECT bool KeyCombo::UsesCtrl(void)const
{
    return (Data[1]!=0);
}
inline EQLIB_OBJECT bool KeyCombo::UsesShift(void)const
{
    return (Data[2]!=0);
}
EQLIB_OBJECT class CXStr KeyCombo::GetTextDescription(void)const;
EQLIB_OBJECT class KeyCombo const & KeyCombo::operator=(int);
inline EQLIB_OBJECT int KeyCombo::operator==(class KeyCombo const &Combo)
{
    return ((*(unsigned long*)&Data)==(*(unsigned long*)&Combo.Data));
}
inline EQLIB_OBJECT unsigned int KeyCombo::GetKey(void)const
{
    return Data[3];
}
// private
EQLIB_OBJECT bool KeyCombo::GetPrintableLetterFromScanCode(unsigned char,bool,bool,unsigned short *)const;
EQLIB_OBJECT bool KeyCombo::GetPrintableLetterFromVirtualKey(unsigned int,unsigned int,bool,bool,unsigned short *)const;
EQLIB_OBJECT bool KeyCombo::GetScanCodeFromVirtualKey(unsigned int,unsigned int,unsigned char *)const;
EQLIB_OBJECT bool KeyCombo::GetVirtualKeyFromScanCode(unsigned char,int *)const;
    unsigned char Data[4];
};

class KeypressHandler
{
public:
EQLIB_OBJECT KeypressHandler::~KeypressHandler(void);
EQLIB_OBJECT KeypressHandler::KeypressHandler(void);
EQLIB_OBJECT bool KeypressHandler::AttachAltKeyToEqCommand(class KeyCombo const &,unsigned int);
EQLIB_OBJECT bool KeypressHandler::AttachKeyToEqCommand(class KeyCombo const &,unsigned int);
EQLIB_OBJECT bool KeypressHandler::HandleKeyDown(class KeyCombo const &);
EQLIB_OBJECT bool KeypressHandler::HandleKeyUp(class KeyCombo const &);
EQLIB_OBJECT class KeyCombo const & KeypressHandler::GetAltKeyAttachedToEqCommand(unsigned int)const;
EQLIB_OBJECT class KeyCombo const & KeypressHandler::GetKeyAttachedToEqCommand(unsigned int)const;
EQLIB_OBJECT void KeypressHandler::ResetKeysToEqDefaults(void);
// private
EQLIB_OBJECT bool KeypressHandler::IsReservedKey(class KeyCombo const &)const;
EQLIB_OBJECT bool KeypressHandler::LoadAndConvertOldKeymappingFormat(unsigned int,int,class KeyCombo *);
EQLIB_OBJECT bool KeypressHandler::LoadKeymapping(unsigned int,int,class KeyCombo *);
EQLIB_OBJECT bool KeypressHandler::MapKeyToEqCommand(class KeyCombo const &,int,unsigned int);
EQLIB_OBJECT class CXStr KeypressHandler::GetEqCommandSaveName(unsigned int,int)const;
EQLIB_OBJECT void KeypressHandler::ClearCommandStateArray(void);
EQLIB_OBJECT void KeypressHandler::LoadAndSetKeymappings(void);
EQLIB_OBJECT void KeypressHandler::SaveKeymapping(unsigned int,class KeyCombo const &,int);
/*0x000*/   class KeyCombo NormalKey[nEQMappableCommands];
/*0x2 4*/   class KeyCombo AltKey[nEQMappableCommands];
/*0x5C8*/    char CommandState[nEQMappableCommands];
};

class LogicalPacket
{
public:
EQLIB_OBJECT LogicalPacket::LogicalPacket(void);
// virtual
EQLIB_OBJECT bool LogicalPacket::IsInternalPacket(void)const;
EQLIB_OBJECT int LogicalPacket::GetRefCount(void)const;
EQLIB_OBJECT void LogicalPacket::AddRef(void)const;
EQLIB_OBJECT void LogicalPacket::Release(void)const;
// protected
EQLIB_OBJECT virtual LogicalPacket::~LogicalPacket(void);
//EQLIB_OBJECT virtual void * LogicalPacket::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void * LogicalPacket::`vector deleting destructor'(unsigned int);
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

class EQSpellStrings
{
public:
	EQLIB_OBJECT char* EQSpellStrings::GetString(int SpellID, int StrIndex);
};
class MapViewMap
{
public:
EQLIB_OBJECT MapViewMap::~MapViewMap(void);
EQLIB_OBJECT MapViewMap::MapViewMap(void);
EQLIB_OBJECT bool MapViewMap::DrawClippedLine(struct T3D_XYZ *,struct T3D_RGB,class CXRect);
EQLIB_OBJECT bool MapViewMap::IsLayerVisible(int);
EQLIB_OBJECT bool MapViewMap::LoadEx(char *,int);
EQLIB_OBJECT bool MapViewMap::PointInMapViewArea(class CXPoint,class CXRect);
EQLIB_OBJECT int MapViewMap::GetMaxZ(void);
EQLIB_OBJECT int MapViewMap::GetMinZ(void);
EQLIB_OBJECT unsigned long MapViewMap::GetCurrentColor(void);
EQLIB_OBJECT unsigned long MapViewMap::GetMarkedLineColor(void);
EQLIB_OBJECT void MapViewMap::AddLabel(float,float,float,unsigned long,int,char *);
EQLIB_OBJECT void MapViewMap::AddPoint(float,float,float);
EQLIB_OBJECT void MapViewMap::CalcLabelRenderOffsets(class CXRect);
EQLIB_OBJECT void MapViewMap::Clear(void);
EQLIB_OBJECT void MapViewMap::ClearActiveLayer(void);
EQLIB_OBJECT void MapViewMap::Draw(class CXRect);
EQLIB_OBJECT void MapViewMap::EndLine(float,float,float);
EQLIB_OBJECT void MapViewMap::JoinLinesAtIntersect(bool);
EQLIB_OBJECT void MapViewMap::Load(char *);
EQLIB_OBJECT void MapViewMap::MoveLabel(struct _mapviewlabel *,float,float,float);
EQLIB_OBJECT void MapViewMap::PreCalcRenderValues(void);
EQLIB_OBJECT void MapViewMap::RecalcLabelExtents(struct _mapviewlabel *);
EQLIB_OBJECT void MapViewMap::RemoveLabel(struct _mapviewlabel *);
EQLIB_OBJECT void MapViewMap::RemoveLabel(void);
EQLIB_OBJECT void MapViewMap::RemoveLine(struct _mapviewline *);
EQLIB_OBJECT void MapViewMap::RemoveLine(void);
EQLIB_OBJECT void MapViewMap::Save(char *);
EQLIB_OBJECT void MapViewMap::SaveEx(char *,int);
EQLIB_OBJECT void MapViewMap::SetCurrentColor(unsigned long);
EQLIB_OBJECT void MapViewMap::SetMarkedLine(struct _mapviewline *);
EQLIB_OBJECT void MapViewMap::SetMarkedLineColor(unsigned long);
EQLIB_OBJECT void MapViewMap::SetZoneExtents(int,int,int,int);
EQLIB_OBJECT void MapViewMap::SetZoom(float);
EQLIB_OBJECT void MapViewMap::StartLine(float,float,float);
EQLIB_OBJECT void MapViewMap::TransformPoint(struct T3D_XYZ *);
};

class MemoryPoolManager
{
public:
EQLIB_OBJECT MemoryPoolManager::~MemoryPoolManager(void);
EQLIB_OBJECT MemoryPoolManager::MemoryPoolManager(void);
EQLIB_OBJECT void * MemoryPoolManager::Alloc(int);
EQLIB_OBJECT void MemoryPoolManager::Free(void *);
};

class MidiInstance
{
public:
EQLIB_OBJECT MidiInstance::MidiInstance(class SoundManager *);
// virtual
EQLIB_OBJECT bool MidiInstance::GiveTime(void);
EQLIB_OBJECT enum InstanceType MidiInstance::GetType(void);
EQLIB_OBJECT void MidiInstance::AdjustVolume(float,int);
EQLIB_OBJECT void MidiInstance::GuaranteeStopped(void);
EQLIB_OBJECT void MidiInstance::Move(float,float,float);
EQLIB_OBJECT void MidiInstance::Play(class SoundControl *);
// protected
EQLIB_OBJECT virtual MidiInstance::~MidiInstance(void);
//EQLIB_OBJECT virtual void * MidiInstance::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void * MidiInstance::`vector deleting destructor'(unsigned int);
};

class monty
{
public:
EQLIB_OBJECT monty::~monty(void);
EQLIB_OBJECT monty::monty(class vlong const &);
EQLIB_OBJECT class vlong monty::exp(class vlong const &,class vlong const &);
// private
EQLIB_OBJECT void monty::mul(class vlong &,class vlong const &);
};

class Mp3Manager
{
public:
EQLIB_OBJECT Mp3Manager::~Mp3Manager(void);
//EQLIB_OBJECT Mp3Manager::Entry::~Entry(void);
//EQLIB_OBJECT Mp3Manager::Entry::Entry(char *,char *,int,int);
EQLIB_OBJECT Mp3Manager::Mp3Manager(class SoundManager *,class MusicManager *);
EQLIB_OBJECT char * Mp3Manager::GetName(int);
//EQLIB_OBJECT enum Mp3Manager::SortOrder Mp3Manager::GetSort(void);
//EQLIB_OBJECT enum StreamingStatus Mp3Manager::Status(void);
EQLIB_OBJECT float Mp3Manager::GetVolumeLevel(void);
EQLIB_OBJECT int Mp3Manager::Add(char *);
EQLIB_OBJECT int Mp3Manager::Count(void);
EQLIB_OBJECT int Mp3Manager::GetPosition(void);
EQLIB_OBJECT int Mp3Manager::GetSongLength(void);
EQLIB_OBJECT int Mp3Manager::GetSongPosition(void);
EQLIB_OBJECT void Mp3Manager::Back(void);
EQLIB_OBJECT void Mp3Manager::Delete(int);
EQLIB_OBJECT void Mp3Manager::DeleteAll(void);
EQLIB_OBJECT void Mp3Manager::GiveTime(void);
EQLIB_OBJECT void Mp3Manager::Next(void);
EQLIB_OBJECT void Mp3Manager::Pause(void);
EQLIB_OBJECT void Mp3Manager::Play(void);
EQLIB_OBJECT void Mp3Manager::SaveList(char *);
EQLIB_OBJECT void Mp3Manager::SetPosition(int);
EQLIB_OBJECT void Mp3Manager::SetSongPosition(int);
EQLIB_OBJECT void Mp3Manager::SetVolumeLevel(float);
//EQLIB_OBJECT void Mp3Manager::Sort(enum Mp3Manager::SortOrder);
EQLIB_OBJECT void Mp3Manager::Stop(void);
// private
EQLIB_OBJECT int Mp3Manager::InternalAdd(char *,char *,int);
};

class MusicManager
{
public:
EQLIB_OBJECT MusicManager::~MusicManager(void);
//EQLIB_OBJECT MusicManager::MusicEntry::~MusicEntry(void);
//EQLIB_OBJECT MusicManager::MusicEntry::MusicEntry(int,class SoundAsset *,int,float,int,int,int,int,int,int);
EQLIB_OBJECT MusicManager::MusicManager(void);
EQLIB_OBJECT void MusicManager::Clear(class SoundAsset *);
EQLIB_OBJECT void MusicManager::Clear(int);
EQLIB_OBJECT void MusicManager::Enable(bool);
EQLIB_OBJECT void MusicManager::GiveTime(void);
//EQLIB_OBJECT void MusicManager::MusicEntry::AdjustVolume(float);
//EQLIB_OBJECT void MusicManager::MusicEntry::FadeIn(float);
//EQLIB_OBJECT void MusicManager::MusicEntry::FadeOut(bool);
EQLIB_OBJECT void MusicManager::Play(int);
EQLIB_OBJECT void MusicManager::Set(int,class SoundAsset *,int,float,int,int,int,int,int,int);
EQLIB_OBJECT void MusicManager::SetVolumeLevel(float);
EQLIB_OBJECT void MusicManager::Stop(int);
};

class PacketPacker
{
public:
EQLIB_OBJECT void PacketPacker::Disassociate(void);
EQLIB_OBJECT void PacketPacker::Flush(void);
EQLIB_OBJECT void PacketPacker::SendPacket(unsigned __int32,void *,int,bool);
EQLIB_OBJECT void PacketPacker::SendStatUpdate(struct _statUpdate *,bool);
// private
//EQLIB_OBJECT void PacketPacker::AddPacketToBuffer(struct PacketPacker::PacketBuffer *,unsigned __int32,void *,int);
//EQLIB_OBJECT void PacketPacker::FlushBuffer(struct PacketPacker::PacketBuffer *);
EQLIB_OBJECT void PacketPacker::FlushPositions(void);
EQLIB_OBJECT void PacketPacker::ScheduleUs(void);
};

class PacketPackerManager
{
public:
EQLIB_OBJECT static bool __cdecl PacketPackerManager::UnpackGetFirst(struct PacketPackerState *,unsigned __int32,unsigned char *,int);
EQLIB_OBJECT static bool __cdecl PacketPackerManager::UnpackGetNext(struct PacketPackerState *);
EQLIB_OBJECT static void __cdecl PacketPackerManager::Initialize(void);
EQLIB_OBJECT void PacketPackerManager::RemovePacker(class PacketPacker *);
EQLIB_OBJECT void PacketPackerManager::SetPriority(class PacketPacker *,__int64);
// private
EQLIB_OBJECT static int * PacketPackerManager::sKnownSize;
};

class PackFile
{
public:
EQLIB_OBJECT PackFile::~PackFile(void);
EQLIB_OBJECT int PackFile::length(void)const;
EQLIB_OBJECT int PackFile::read(void * const,int);
EQLIB_OBJECT void PackFile::close(void);
};

class PackFS
{
public:
EQLIB_OBJECT PackFS::PackFS(void);
EQLIB_OBJECT bool PackFS::addFileSystem(class FilePath);
EQLIB_OBJECT bool PackFS::openFile(class FilePath,class PackFile *)const;
EQLIB_OBJECT void PackFS::removeFileSystem(class FilePath);
};

class PooledLogicalPacket
{
public:
EQLIB_OBJECT PooledLogicalPacket::PooledLogicalPacket(class UdpManager *,int);
// virtual
EQLIB_OBJECT int PooledLogicalPacket::GetDataLen(void)const;
EQLIB_OBJECT void * PooledLogicalPacket::GetDataPtr(void);
EQLIB_OBJECT void PooledLogicalPacket::AddRef(void)const;
EQLIB_OBJECT void PooledLogicalPacket::Release(void)const;
EQLIB_OBJECT void PooledLogicalPacket::SetDataLen(int);
EQLIB_OBJECT void const * PooledLogicalPacket::GetDataPtr(void)const;
// protected
EQLIB_OBJECT virtual PooledLogicalPacket::~PooledLogicalPacket(void);
//EQLIB_OBJECT virtual void * PooledLogicalPacket::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void * PooledLogicalPacket::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void PooledLogicalPacket::SetData(void const *,int,void const *,int);
};

class public_key
{
public:
EQLIB_OBJECT public_key::~public_key(void);
EQLIB_OBJECT public_key::public_key(void);
EQLIB_OBJECT class vlong public_key::encrypt(class vlong &);
};

class SAmpersandEntry
{
public:
EQLIB_OBJECT SAmpersandEntry::~SAmpersandEntry(void);
EQLIB_OBJECT SAmpersandEntry::SAmpersandEntry(class CXStr,char);
};

class SFormattedText
{
public:
EQLIB_OBJECT SFormattedText::~SFormattedText(void);
EQLIB_OBJECT SFormattedText::SFormattedText(void);
//EQLIB_OBJECT void * SFormattedText::`vector deleting destructor'(unsigned int);
};

class ShareBase
{
public:
EQLIB_OBJECT void ShareBase::removeRef(void);
// virtual
EQLIB_OBJECT ShareBase::~ShareBase(void);
};

class SharedString
{
public:
EQLIB_OBJECT SharedString::~SharedString(void);
EQLIB_OBJECT SharedString::SharedString(char const *);
EQLIB_OBJECT class SharedString & SharedString::operator=(class SharedString const &);
// protected
EQLIB_OBJECT void SharedString::_updateTag(void)const;
};

class SHistoryElement
{
public:
EQLIB_OBJECT SHistoryElement::~SHistoryElement(void);
EQLIB_OBJECT SHistoryElement::SHistoryElement(void);
//EQLIB_OBJECT void * SHistoryElement::`vector deleting destructor'(unsigned int);
};

class SimpleLogicalPacket
{
public:
EQLIB_OBJECT SimpleLogicalPacket::SimpleLogicalPacket(void const *,int);
// virtual
EQLIB_OBJECT int SimpleLogicalPacket::GetDataLen(void)const;
EQLIB_OBJECT void * SimpleLogicalPacket::GetDataPtr(void);
EQLIB_OBJECT void SimpleLogicalPacket::SetDataLen(int);
EQLIB_OBJECT void const * SimpleLogicalPacket::GetDataPtr(void)const;
// protected
EQLIB_OBJECT virtual SimpleLogicalPacket::~SimpleLogicalPacket(void);
//EQLIB_OBJECT virtual void * SimpleLogicalPacket::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void * SimpleLogicalPacket::`vector deleting destructor'(unsigned int);
};

class SListWndCellEditUpdate
{
public:
EQLIB_OBJECT SListWndCellEditUpdate::~SListWndCellEditUpdate(void);
};


class SListWndSortInfo
{
public:
	int SortCol;
	const SListWndLine&	ListWndLine1;
    PCXSTR	StrLabel1;
    unsigned __int32 Data1;
	const SListWndLine&	ListWndLine2;
    PCXSTR StrLabel2;
    unsigned __int32 Data2;
    int SortResult;
EQLIB_OBJECT SListWndSortInfo::~SListWndSortInfo(void);
};

class SoundAsset
{
public:
EQLIB_OBJECT SoundAsset::SoundAsset(class SoundManager *,char *,char *,int);
EQLIB_OBJECT bool SoundAsset::IsPlaying(void);
EQLIB_OBJECT char * SoundAsset::GetName(void);
EQLIB_OBJECT class SoundInstance * SoundAsset::Play(class SoundControl *);
//EQLIB_OBJECT enum AssetType SoundAsset::GetType(void);
EQLIB_OBJECT void SoundAsset::AdjustVolume(float,int);
EQLIB_OBJECT void SoundAsset::GiveTime(void);
EQLIB_OBJECT void SoundAsset::Stop(void);
// protected
EQLIB_OBJECT virtual SoundAsset::~SoundAsset(void);
//EQLIB_OBJECT virtual void * SoundAsset::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void * SoundAsset::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void SoundAsset::YourManagerDeleted(void);
};

class SoundControl
{
public:
EQLIB_OBJECT SoundControl::SoundControl(void);
};

class SoundEmitter
{
public:
EQLIB_OBJECT SoundEmitter::SoundEmitter(class EmitterManager *,class MusicManager *,int);
EQLIB_OBJECT SoundEmitter::SoundEmitter(class EmitterManager *,class SoundAsset *,int);
EQLIB_OBJECT void SoundEmitter::Enable(bool);
EQLIB_OBJECT void SoundEmitter::GiveTime(void);
EQLIB_OBJECT void SoundEmitter::Move(float,float,float);
EQLIB_OBJECT void SoundEmitter::SetAsset(class SoundAsset *);
// protected
EQLIB_OBJECT virtual SoundEmitter::~SoundEmitter(void);
//EQLIB_OBJECT virtual void * SoundEmitter::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void * SoundEmitter::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void SoundEmitter::Init(void);
EQLIB_OBJECT void SoundEmitter::ReleaseLoopingSound(void);
EQLIB_OBJECT void SoundEmitter::ResetTimer(void);
};

class SoundInstance
{
public:
EQLIB_OBJECT SoundInstance::SoundInstance(class SoundManager *);
// virtual
EQLIB_OBJECT void SoundInstance::SetPoolNumber(int);
EQLIB_OBJECT void SoundInstance::SetSoundAsset(class SoundAsset *);
// protected
EQLIB_OBJECT virtual SoundInstance::~SoundInstance(void);
//EQLIB_OBJECT virtual void * SoundInstance::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void * SoundInstance::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void SoundInstance::YourManagerDeleted(void);
};

class SoundManager
{
public:
EQLIB_OBJECT SoundManager::~SoundManager(void);
//EQLIB_OBJECT SoundManager::SoundManager(int,int,bool,int,int,bool,enum SpeakerType);
EQLIB_OBJECT class SoundAsset * SoundManager::AssetGet(char *);
//EQLIB_OBJECT class SoundInstance * SoundManager::BorrowInstance(enum InstanceType,int);
//EQLIB_OBJECT enum EnvironmentType SoundManager::GetListenerEnvironment(void);
//EQLIB_OBJECT enum StreamingStatus SoundManager::StreamingStatus(void);
EQLIB_OBJECT float SoundManager::StreamingGetVolumeLevel(void);
EQLIB_OBJECT int SoundManager::StreamingGetSongLength(void);
EQLIB_OBJECT int SoundManager::StreamingGetSongPosition(void);
//EQLIB_OBJECT void SoundManager::AddPool(enum InstanceType,int,int);
EQLIB_OBJECT void SoundManager::GetListenerLocation(float *,float *,float *,float *);
EQLIB_OBJECT void SoundManager::GiveTime(void);
EQLIB_OBJECT void SoundManager::ReturnInstance(class SoundInstance *);
//EQLIB_OBJECT void SoundManager::SetListenerEnvironment(enum EnvironmentType);
EQLIB_OBJECT void SoundManager::SetListenerLocation(float,float,float,float);
EQLIB_OBJECT void SoundManager::SetMixAhead(int);
EQLIB_OBJECT void SoundManager::StreamingPause(void);
EQLIB_OBJECT void SoundManager::StreamingPlay(char *);
EQLIB_OBJECT void SoundManager::StreamingSetSongPosition(int);
EQLIB_OBJECT void SoundManager::StreamingSetVolumeLevel(float);
EQLIB_OBJECT void SoundManager::StreamingStop(void);
// protected
EQLIB_OBJECT void SoundManager::AssetAdd(class SoundAsset *);
EQLIB_OBJECT void SoundManager::AssetGiveTime(void);
EQLIB_OBJECT void SoundManager::AssetRemove(class SoundAsset *);
};

class SoundObject
{
public:
EQLIB_OBJECT SoundObject::SoundObject(void);
EQLIB_OBJECT void SoundObject::AddRef(void);
EQLIB_OBJECT void SoundObject::Release(void);
// protected
EQLIB_OBJECT virtual SoundObject::~SoundObject(void);
//EQLIB_OBJECT virtual void * SoundObject::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void * SoundObject::`vector deleting destructor'(unsigned int);
};

class SParseVariables
{
public:
EQLIB_OBJECT SParseVariables::~SParseVariables(void);
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
    FLOAT Gravity[3];
    FLOAT NormalX1;
    FLOAT NormalY1;
    FLOAT NormalZ1;
    FLOAT NormalX2;
    FLOAT NormalY2;
    FLOAT NormalZ2;
	FLOAT NormalX3;
    FLOAT NormalY3;
    FLOAT NormalZ3;
    FLOAT Radius[3];
    FLOAT Angle[3];
    ULONG Lifespan[3];
    FLOAT Velocity[3];
    ULONG Rate[3];
    FLOAT Scale[3];
    EQRGB SpriteRGB[0xc];
    FLOAT RollRate[0xc];
    short HdgOffset[0xc];
    short PitchOffset[0xc];
    FLOAT Distance[0xc];
    short EffectType[12];
    FLOAT ScaleFactor[12];
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
	OldSpellEffect *OldSpellEff;
	NewSpellEffect *NewSpellEff;
};
//Matching stack group ID rules
enum ESpellStackingRules
{
	ESSR_None,//default
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
//but its kinda complicated, maybe another day. -eqmule
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

/*0x00*/ EQLIB_OBJECT SpellManager::SpellManager(char *);
EQLIB_OBJECT const EQ_Spell* SpellManager::GetSpellByGroupAndRank(int Group, int SubGroup, int Rank = -1, bool bLesserRanksOk = false);
};
class ClientSpellManager : public SpellManager
{
public:
/*0x00*/ EQLIB_OBJECT int ClientSpellManager::dSpellManager(void *, bool);
/*0x04*/ EQLIB_OBJECT bool ClientSpellManager::LoadSpells(char const*FileName, char const*AssocFilename, char const*StackingFileName);
/*0x08*/ EQLIB_OBJECT bool ClientSpellManager::LoadSpellStackingData(const char *StackingFileName);
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x0c*/ EQLIB_OBJECT bool ClientSpellManager::DoesMeetRequirement(PlayerZoneClient *pPlayer,int SpellAssocID);
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
EQLIB_OBJECT STable::~STable(void);
EQLIB_OBJECT STable::STable(void);
EQLIB_OBJECT class STable & STable::operator=(class STable const &);
//EQLIB_OBJECT void * STable::`vector deleting destructor'(unsigned int);
};

class STableCell
{
public:
EQLIB_OBJECT STableCell::~STableCell(void);
EQLIB_OBJECT STableCell::STableCell(void);
};

class STempTable
{
public:
EQLIB_OBJECT STempTable::~STempTable(void);
};

class STempTableCell
{
public:
EQLIB_OBJECT STempTableCell::~STempTableCell(void);
EQLIB_OBJECT STempTableCell::STempTableCell(void);
};

class STempTableRow
{
public:
EQLIB_OBJECT STempTableRow::~STempTableRow(void);
EQLIB_OBJECT STempTableRow::STempTableRow(void);
};

class StringItem
{
public:
EQLIB_OBJECT StringItem::~StringItem(void);
EQLIB_OBJECT StringItem::StringItem(void);
EQLIB_OBJECT int StringItem::load(struct _iobuf *,int);
};

class StringTable
{
public:
EQLIB_OBJECT StringTable::~StringTable(void);
EQLIB_OBJECT StringTable::StringTable(void);
EQLIB_OBJECT char * StringTable::getString(unsigned long ID, bool *bFound = NULL);
EQLIB_OBJECT int StringTable::load(char const *,int);
EQLIB_OBJECT void StringTable::addItem(class StringItem *);
// private
EQLIB_OBJECT class StringItem * StringTable::findItem(unsigned long,int,int);
EQLIB_OBJECT void StringTable::checkAlloc(void);
};

class TextFileReader
{
public:
EQLIB_OBJECT TextFileReader::~TextFileReader(void);
EQLIB_OBJECT TextFileReader::TextFileReader(char *,char);
EQLIB_OBJECT bool TextFileReader::IsOpen(void);
EQLIB_OBJECT int TextFileReader::GetNextField(char *,int);
EQLIB_OBJECT int TextFileReader::ReadLine(void);
EQLIB_OBJECT void TextFileReader::GetLine(char *,int);
};

class type_info
{
public:
// virtual
EQLIB_OBJECT type_info::~type_info(void);
//EQLIB_OBJECT void * type_info::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * type_info::`vector deleting destructor'(unsigned int);
};

class UdpConnection
{
public:
//EQLIB_OBJECT bool UdpConnection::Send(enum UdpChannel,void const *,int);
EQLIB_OBJECT int UdpConnection::ConnectionAge(void)const;
EQLIB_OBJECT int UdpConnection::LastReceive(void)const;
EQLIB_OBJECT int UdpConnection::TotalPendingBytes(void)const;
EQLIB_OBJECT void UdpConnection::FlushMultiBuffer(void);
//EQLIB_OBJECT void UdpConnection::GetChannelStatus(enum UdpChannel,struct UdpConnection::ChannelStatus *)const;
EQLIB_OBJECT void UdpConnection::PingStatReset(void);
EQLIB_OBJECT void UdpConnection::Release(void);
EQLIB_OBJECT void UdpConnection::SetSilentDisconnect(bool);
// protected
EQLIB_OBJECT UdpConnection::UdpConnection(class UdpManager *,class UdpIpAddress,int,int);
//EQLIB_OBJECT UdpConnection::UdpConnection(class UdpManager *,class UdpManager::PacketHistoryEntry const *);
EQLIB_OBJECT void UdpConnection::GiveTime(void);
EQLIB_OBJECT void UdpConnection::PortUnreachable(void);
//EQLIB_OBJECT void UdpConnection::ProcessRawPacket(class UdpManager::PacketHistoryEntry const *);
// private
EQLIB_OBJECT UdpConnection::~UdpConnection(void);
//EQLIB_OBJECT bool UdpConnection::InternalSend(enum UdpChannel,unsigned char const *,int,unsigned char const *,int);
EQLIB_OBJECT bool UdpConnection::IsNonEncryptPacket(unsigned char const *)const;
EQLIB_OBJECT int UdpConnection::DecryptNone(unsigned char *,unsigned char const *,int);
EQLIB_OBJECT int UdpConnection::DecryptUserSupplied(unsigned char *,unsigned char const *,int);
EQLIB_OBJECT int UdpConnection::DecryptUserSupplied2(unsigned char *,unsigned char const *,int);
EQLIB_OBJECT int UdpConnection::DecryptXor(unsigned char *,unsigned char const *,int);
EQLIB_OBJECT int UdpConnection::DecryptXorBuffer(unsigned char *,unsigned char const *,int);
EQLIB_OBJECT int UdpConnection::EncryptNone(unsigned char *,unsigned char const *,int);
EQLIB_OBJECT int UdpConnection::EncryptUserSupplied(unsigned char *,unsigned char const *,int);
EQLIB_OBJECT int UdpConnection::EncryptUserSupplied2(unsigned char *,unsigned char const *,int);
EQLIB_OBJECT int UdpConnection::EncryptXor(unsigned char *,unsigned char const *,int);
EQLIB_OBJECT int UdpConnection::EncryptXorBuffer(unsigned char *,unsigned char const *,int);
EQLIB_OBJECT int UdpConnection::ExpireReceiveBin(void);
EQLIB_OBJECT int UdpConnection::ExpireSendBin(void);
EQLIB_OBJECT unsigned char * UdpConnection::BufferedSend(unsigned char const *,int,unsigned char const *,int,bool);
//EQLIB_OBJECT void UdpConnection::CallbackCorruptPacket(unsigned char const *,int,enum UdpCorruptionReason);
EQLIB_OBJECT void UdpConnection::CallbackRoutePacket(unsigned char const *,int);
EQLIB_OBJECT void UdpConnection::Init(class UdpManager *,class UdpIpAddress,int);
//EQLIB_OBJECT void UdpConnection::InternalDisconnect(int,enum UdpConnection::DisconnectReason);
EQLIB_OBJECT void UdpConnection::InternalGiveTime(void);
EQLIB_OBJECT void UdpConnection::PhysicalSend(unsigned char const *,int,bool);
EQLIB_OBJECT void UdpConnection::ProcessCookedPacket(unsigned char const *,int);
EQLIB_OBJECT void UdpConnection::RawSend(unsigned char const *,int);
EQLIB_OBJECT void UdpConnection::ScheduleTimeNow(void);
//EQLIB_OBJECT void UdpConnection::SendTerminatePacket(int,enum UdpConnection::DisconnectReason);
EQLIB_OBJECT void UdpConnection::SetupEncryptModel(void);
};

class UdpConnectionHandler
{
public:
// virtual
EQLIB_OBJECT void UdpConnectionHandler::OnConnectComplete(class UdpConnection *);
EQLIB_OBJECT void UdpConnectionHandler::OnCrcReject(class UdpConnection *,unsigned char const *,int);
//EQLIB_OBJECT void UdpConnectionHandler::OnPacketCorrupt(class UdpConnection *,unsigned char const *,int,enum UdpCorruptionReason);
EQLIB_OBJECT void UdpConnectionHandler::OnTerminated(class UdpConnection *);
};

class UdpIpAddress
{
public:
EQLIB_OBJECT UdpIpAddress::UdpIpAddress(unsigned int);
};

class UdpManager
{
public:
//EQLIB_OBJECT UdpManager::PacketHistoryEntry::~PacketHistoryEntry(void);
//EQLIB_OBJECT UdpManager::PacketHistoryEntry::PacketHistoryEntry(int);
//EQLIB_OBJECT UdpManager::Params::Params(void);
//EQLIB_OBJECT UdpManager::SimulateQueueEntry::~SimulateQueueEntry(void);
//EQLIB_OBJECT UdpManager::SimulateQueueEntry::SimulateQueueEntry(unsigned char const *,int,class UdpIpAddress,int);
//EQLIB_OBJECT UdpManager::UdpManager(struct UdpManager::Params const *);
EQLIB_OBJECT bool UdpManager::GiveTime(int,bool);
EQLIB_OBJECT class LogicalPacket * UdpManager::CreatePacket(void const *,int,void const *,int);
EQLIB_OBJECT class UdpConnection * UdpManager::EstablishConnection(char const *,int,int);
EQLIB_OBJECT void UdpManager::Release(void);
EQLIB_OBJECT void UdpManager::ResetStats(void);
// protected
EQLIB_OBJECT class UdpConnection * UdpManager::AddressGetConnection(class UdpIpAddress,int)const;
EQLIB_OBJECT class UdpConnection * UdpManager::ConnectCodeGetConnection(int)const;
//EQLIB_OBJECT class UdpManager::PacketHistoryEntry * UdpManager::ActualReceive(void);
EQLIB_OBJECT class WrappedLogicalPacket * UdpManager::WrappedBorrow(class LogicalPacket const *);
EQLIB_OBJECT void UdpManager::ActualSend(unsigned char const *,int,class UdpIpAddress,int);
EQLIB_OBJECT void UdpManager::ActualSendHelper(unsigned char const *,int,class UdpIpAddress,int);
EQLIB_OBJECT void UdpManager::AddConnection(class UdpConnection *);
EQLIB_OBJECT void UdpManager::CloseSocket(void);
EQLIB_OBJECT void UdpManager::CreateAndBindSocket(int);
EQLIB_OBJECT void UdpManager::KeepUntilDisconnected(class UdpConnection *);
EQLIB_OBJECT void UdpManager::PoolCreated(class PooledLogicalPacket *);
EQLIB_OBJECT void UdpManager::PoolDestroyed(class PooledLogicalPacket *);
EQLIB_OBJECT void UdpManager::PoolReturn(class PooledLogicalPacket *);
EQLIB_OBJECT void UdpManager::ProcessDisconnectPending(void);
EQLIB_OBJECT void UdpManager::ProcessIcmpErrors(void);
//EQLIB_OBJECT void UdpManager::ProcessRawPacket(class UdpManager::PacketHistoryEntry const *);
EQLIB_OBJECT void UdpManager::RemoveConnection(class UdpConnection *);
EQLIB_OBJECT void UdpManager::SendPortAlive(class UdpIpAddress,int);
EQLIB_OBJECT void UdpManager::WrappedCreated(class WrappedLogicalPacket *);
EQLIB_OBJECT void UdpManager::WrappedDestroyed(class WrappedLogicalPacket *);
EQLIB_OBJECT void UdpManager::WrappedReturn(class WrappedLogicalPacket *);
// private
EQLIB_OBJECT UdpManager::~UdpManager(void);
};

class UdpMisc
{
public:
EQLIB_OBJECT static __int64 __cdecl UdpMisc::Clock(void);
EQLIB_OBJECT static __int64 __cdecl UdpMisc::GetValue64(void const *);
EQLIB_OBJECT static class LogicalPacket * __cdecl UdpMisc::CreateQuickLogicalPacket(void const *,int,void const *,int);
EQLIB_OBJECT static int __cdecl UdpMisc::Crc32(void const *,int,int);
EQLIB_OBJECT static int __cdecl UdpMisc::PutValue24(void *,unsigned int);
EQLIB_OBJECT static int __cdecl UdpMisc::PutValue32(void *,unsigned int);
EQLIB_OBJECT static int __cdecl UdpMisc::PutValue64(void *,__int64);
EQLIB_OBJECT static int __cdecl UdpMisc::Random(int *);
EQLIB_OBJECT static int __cdecl UdpMisc::SyncStampShortDeltaTime(unsigned short,unsigned short);
EQLIB_OBJECT static unsigned int __cdecl UdpMisc::GetValue24(void const *);
EQLIB_OBJECT static unsigned int __cdecl UdpMisc::GetValue32(void const *);
EQLIB_OBJECT static unsigned int __cdecl UdpMisc::GetVariableValue(void const *,unsigned int *);
EQLIB_OBJECT static unsigned int __cdecl UdpMisc::PutVariableValue(void *,unsigned int);
};

class UdpReliableChannel
{
public:
//EQLIB_OBJECT UdpReliableChannel::IncomingQueueEntry::~IncomingQueueEntry(void);
//EQLIB_OBJECT UdpReliableChannel::IncomingQueueEntry::IncomingQueueEntry(void);
//EQLIB_OBJECT UdpReliableChannel::PhysicalPacket::~PhysicalPacket(void);
//EQLIB_OBJECT UdpReliableChannel::PhysicalPacket::PhysicalPacket(void);
//EQLIB_OBJECT void * UdpReliableChannel::IncomingQueueEntry::`vector deleting destructor'(unsigned int);
//EQLIB_OBJECT void * UdpReliableChannel::PhysicalPacket::`vector deleting destructor'(unsigned int);
// protected
EQLIB_OBJECT __int64 UdpReliableChannel::GetReliableIncomingId(int)const;
EQLIB_OBJECT UdpReliableChannel::~UdpReliableChannel(void);
//EQLIB_OBJECT UdpReliableChannel::UdpReliableChannel(int,class UdpConnection *,struct UdpManager::ReliableConfig *);
EQLIB_OBJECT bool UdpReliableChannel::PullDown(int);
EQLIB_OBJECT int UdpReliableChannel::GiveTime(void);
EQLIB_OBJECT void UdpReliableChannel::Ack(__int64);
EQLIB_OBJECT void UdpReliableChannel::AckAllPacket(unsigned char const *,int);
EQLIB_OBJECT void UdpReliableChannel::AckPacket(unsigned char const *,int);
EQLIB_OBJECT void UdpReliableChannel::FlushCoalesce(void);
//EQLIB_OBJECT void UdpReliableChannel::GetChannelStatus(struct UdpConnection::ChannelStatus *)const;
//EQLIB_OBJECT void UdpReliableChannel::ProcessPacket(enum UdpReliableChannel::ReliablePacketMode,unsigned char const *,int);
EQLIB_OBJECT void UdpReliableChannel::QueueLogicalPacket(class LogicalPacket const *);
EQLIB_OBJECT void UdpReliableChannel::ReliablePacket(unsigned char const *,int);
EQLIB_OBJECT void UdpReliableChannel::Send(unsigned char const *,int,unsigned char const *,int);
EQLIB_OBJECT void UdpReliableChannel::SendCoalesce(unsigned char const *,int,unsigned char const *,int);
};

class vlong
{
public:
EQLIB_OBJECT vlong::~vlong(void);
EQLIB_OBJECT vlong::vlong(class vlong const &);
EQLIB_OBJECT vlong::vlong(unsigned __int64);
EQLIB_OBJECT class vlong & vlong::operator+=(class vlong const &);
EQLIB_OBJECT class vlong & vlong::operator-=(class vlong const &);
EQLIB_OBJECT class vlong & vlong::operator=(class vlong);
// private
EQLIB_OBJECT int vlong::cf(class vlong)const;
EQLIB_OBJECT void vlong::docopy(void);
};

class vlong_value
{
public:
EQLIB_OBJECT vlong_value::~vlong_value(void);
EQLIB_OBJECT vlong_value::vlong_value(void);
EQLIB_OBJECT int vlong_value::cf(class vlong_value &)const;
EQLIB_OBJECT int vlong_value::is_zero(void)const;
EQLIB_OBJECT int vlong_value::test(unsigned int)const;
EQLIB_OBJECT unsigned int vlong_value::bits(void)const;
EQLIB_OBJECT void vlong_value::add(class vlong_value &);
EQLIB_OBJECT void vlong_value::copy(class vlong_value &);
EQLIB_OBJECT void vlong_value::divide(class vlong_value &,class vlong_value &,class vlong_value &);
EQLIB_OBJECT void vlong_value::init(unsigned int);
EQLIB_OBJECT void vlong_value::init2(unsigned int,unsigned int);
EQLIB_OBJECT void vlong_value::mul(class vlong_value &,class vlong_value &);
EQLIB_OBJECT void vlong_value::shl(void);
EQLIB_OBJECT void vlong_value::shr(unsigned int);
EQLIB_OBJECT void vlong_value::shr(void);
EQLIB_OBJECT void vlong_value::subtract(class vlong_value &);
};

class Wave3dInstance
{
public:
EQLIB_OBJECT Wave3dInstance::Wave3dInstance(class SoundManager *);
// virtual
EQLIB_OBJECT bool Wave3dInstance::GiveTime(void);
EQLIB_OBJECT enum InstanceType Wave3dInstance::GetType(void);
EQLIB_OBJECT void Wave3dInstance::AdjustVolume(float,int);
EQLIB_OBJECT void Wave3dInstance::GuaranteeStopped(void);
EQLIB_OBJECT void Wave3dInstance::Move(float,float,float);
EQLIB_OBJECT void Wave3dInstance::Play(class SoundControl *);
// protected
EQLIB_OBJECT virtual Wave3dInstance::~Wave3dInstance(void);
//EQLIB_OBJECT virtual void * Wave3dInstance::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void * Wave3dInstance::`vector deleting destructor'(unsigned int);
};

class WaveInstance
{
public:
EQLIB_OBJECT WaveInstance::WaveInstance(class SoundManager *);
// virtual
EQLIB_OBJECT bool WaveInstance::GiveTime(void);
//EQLIB_OBJECT enum InstanceType WaveInstance::GetType(void);
EQLIB_OBJECT void WaveInstance::AdjustVolume(float,int);
EQLIB_OBJECT void WaveInstance::GuaranteeStopped(void);
EQLIB_OBJECT void WaveInstance::Move(float,float,float);
EQLIB_OBJECT void WaveInstance::Play(class SoundControl *);
// protected
EQLIB_OBJECT virtual WaveInstance::~WaveInstance(void);
//EQLIB_OBJECT virtual void * WaveInstance::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void * WaveInstance::`vector deleting destructor'(unsigned int);
};

class WrappedLogicalPacket
{
public:
EQLIB_OBJECT WrappedLogicalPacket::WrappedLogicalPacket(class UdpManager *);
// virtual
EQLIB_OBJECT int WrappedLogicalPacket::GetDataLen(void)const;
EQLIB_OBJECT void * WrappedLogicalPacket::GetDataPtr(void);
EQLIB_OBJECT void WrappedLogicalPacket::AddRef(void)const;
EQLIB_OBJECT void WrappedLogicalPacket::Release(void)const;
EQLIB_OBJECT void WrappedLogicalPacket::SetDataLen(int);
EQLIB_OBJECT void const * WrappedLogicalPacket::GetDataPtr(void)const;
// protected
EQLIB_OBJECT virtual WrappedLogicalPacket::~WrappedLogicalPacket(void);
//EQLIB_OBJECT virtual void * WrappedLogicalPacket::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT virtual void * WrappedLogicalPacket::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void WrappedLogicalPacket::SetLogicalPacket(class LogicalPacket const *);
};

class ZlibUtil
{
public:
EQLIB_OBJECT static int __cdecl ZlibUtil::Compress(char const *,int,char *,int,int);
EQLIB_OBJECT static int __cdecl ZlibUtil::Decompress(char const *,int,char *,int);
// private
EQLIB_OBJECT static class MemoryPoolManager ZlibUtil::sMemoryPoolManager;
EQLIB_OBJECT static int __cdecl ZlibUtil::zcompress(unsigned char *,unsigned long *,unsigned char const *,unsigned long,int);
EQLIB_OBJECT static int __cdecl ZlibUtil::zuncompress(unsigned char *,unsigned long *,unsigned char const *,unsigned long);
EQLIB_OBJECT static void * __cdecl ZlibUtil::zcalloc(void *,unsigned int,unsigned int);
EQLIB_OBJECT static void __cdecl ZlibUtil::zfree(void *,void *);
};

class ZoneNPCLoadTextManager
{
public:
EQLIB_OBJECT ZoneNPCLoadTextManager::~ZoneNPCLoadTextManager(void);
EQLIB_OBJECT ZoneNPCLoadTextManager::ZoneNPCLoadTextManager(char *);
EQLIB_OBJECT char * ZoneNPCLoadTextManager::GetNPCCode(int);
EQLIB_OBJECT char * ZoneNPCLoadTextManager::GetS3DName(int);
EQLIB_OBJECT void ZoneNPCLoadTextManager::LoadText(char *);
};

class CTextOverlay
{
public:
EQLIB_OBJECT void CTextOverlay::DisplayText(char *,int,int,int,int,int,int);
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
EQLIB_OBJECT char *CDBStr::GetString(int, int, int*);
};

class CCombatAbilityWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CCombatAbilityWnd::CCombatAbilityWnd(class CXWnd *);
EQLIB_OBJECT void CCombatAbilityWnd::Activate(int);
EQLIB_OBJECT void CCombatAbilityWnd::Deactivate(void);
EQLIB_OBJECT int CCombatAbilityWnd::OnProcessFrame(void);
EQLIB_OBJECT int CCombatAbilityWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
EQLIB_OBJECT CCombatAbilityWnd::~CCombatAbilityWnd(void);
};

class EQMisc
{
public:
EQLIB_OBJECT int EQMisc::GetActiveFavorCost(void);
};

class CSkillMgr
{
public:
EQLIB_OBJECT unsigned long CSkillMgr::GetNameToken(int);
EQLIB_OBJECT unsigned long CSkillMgr::GetSkillCap(class EQ_Character *,int,int,int,bool,bool,bool);
EQLIB_OBJECT unsigned long CSkillMgr::SkillAvailableAtLevel(int,int);
EQLIB_OBJECT bool CSkillMgr::IsActivatedSkill(int);
EQLIB_OBJECT unsigned long CSkillMgr::GetBaseDamage(int);
EQLIB_OBJECT unsigned long CSkillMgr::GetReuseTime(int);
EQLIB_OBJECT bool CSkillMgr::IsAvailable(int);
EQLIB_OBJECT bool CSkillMgr::IsCombatSkill(int);
};

class CChatService
{
public:
EQLIB_OBJECT int CChatService::GetNumberOfFriends(void);
EQLIB_OBJECT char * CChatService::GetFriendName(int);
};

class PlayerPointManager
{
public:
EQLIB_OBJECT unsigned long PlayerPointManager::GetAltCurrency(unsigned long,unsigned long b=1);
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
	EQZoneIndex ID;
	PCXSTR Name;
	int ContinentIndex;
	int MinLevel;
	int MaxLevel;
	DynamicBitField<unsigned short, short> Types;
	ArrayClass_RO<ZoneGuideConnection> ZoneConnections;
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

class ZoneGuideManagerBase
{
public:
	PVOID vfTable;
	ZoneGuideZone Zones[829];//see 8D35C1 in may 10 2018 exe -eqmule
	ArrayClass_RO<ZoneGuideContinent> Continents;
	ArrayClass_RO<ZoneGuideZoneType> ZoneTypes;
	ArrayClass_RO<ZoneGuideTransferType> TransferTypes;
};
typedef struct _ZonePathData
{
	EQZoneIndex ZoneID;
	int TransferTypeIndex;
}ZonePathData,*PZonePathData;

class ZoneGuideManagerClient : public ZoneGuideManagerBase
{
public:
EQLIB_OBJECT static ZoneGuideManagerClient& ZoneGuideManagerClient::Instance(void);
	bool bZoneGuideDataSet;
	ArrayClass_RO<ZonePathData> ActivePath;
	ArrayClass_RO<ZonePathData> PreviewPath;
	int HerosJourneyIndex;
	bool bIncludeBindZoneInPath;
	bool bAutoFindActivePath;
	bool bFindActivePath;
	EQZoneIndex CurrZone;
};

class CZoneGuideWnd : public CSidlScreenWnd, public WndEventHandler2
{
public:
	void * VerticalLayout;//CVerticalLayoutWnd
	CButtonWnd *FilterMyLevelButton;
	CButtonWnd *FilterAllLevelsButton;
	CButtonWnd *FilterZonesActiveButton;
	CButtonWnd *FilterZonesInactiveButton;
	CButtonWnd *ZoneRunSearchButton;
	CButtonWnd *ZoneClearSearchButton;	
	CButtonWnd *SelectCurrentZoneButton;
	CEditWnd *LevelFilterEdit;
	CEditWnd *ZoneSearchEdit;
	CComboWnd *TypeFilterCombo;
	CComboWnd *ContinentFilterCombo;
	CListWnd *ZonesList;
	CLabelWnd *ViewZoneConnectionsSelectedZoneLabel;
	CLabelWnd *ViewZoneConnectionsPreviewPathLabel;
	CLabelWnd *ViewZoneConnectionsActivePathLabel;
	CLabelWnd *ViewZoneConnectionsDisabledLabel;
	CButtonWnd *ViewZoneConnectionsSelectedZoneButton;
	CButtonWnd *ViewZoneConnectionsPreviewPathButton;
	CButtonWnd *ViewZoneConnectionsActivePathButton;
	CButtonWnd *ViewZoneConnectionsDisabledButton;
	CButtonWnd *DisableConnectionTemplateButton;
	CListWnd *ZoneConnectionsList;
	CButtonWnd *ResetPathStartZoneButton;
	CButtonWnd *SetPathStartZoneButton;
	CButtonWnd *SetPathEndZoneButton;
	CButtonWnd *ShowPathWndButton;
	CButtonWnd *HidePathWndButton;
	CButtonWnd *FindPathButton;
	CButtonWnd *EndFindButton;
	CButtonWnd *ClearPathWndButton;
	CButtonWnd *ActivatePathButton;
	CButtonWnd *IncludeBindZoneInPathGenerationButton;
	CButtonWnd *ShowPathWndOnPathActivationButton;
	CButtonWnd *AutoFindActivePathButton;
	CEditWnd *PathStartZoneEdit;
	CEditWnd *PathEndZoneEdit;
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
/*0x04*/ FLOAT	Y;
/*0x08*/ FLOAT	X;
/*0x0C*/ FLOAT	Z;
/*0x10*/ FLOAT	Heading;
/*0x14*/ int	ZoneId;
/*0x18*/ int    FilterID;
/*0x1C*/ UINT   VehicleID;
/*0x20*/
} tp_coords,*Ptp_coords;
};
using namespace EQClasses;
#pragma pack(pop)
