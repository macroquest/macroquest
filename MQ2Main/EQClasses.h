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

namespace EQClasses
{
// Other
class CXSize
{
    DWORD A,B,C,D,E,F;
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
class CCharacterSelect;
class CChatManager;
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
class CHashCXStrInt32;
class CHelpWnd;
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
class CListboxColumnTemplate;
class CListboxTemplate;
class CListWnd;
class CLoadskinWnd;
class CLootWnd;
class CMapToolbarWnd;
class CMapViewWnd;
class CMemoryStream;
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
class CTargetWnd;
class CTaskWnd;
class CTaskSomething;
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
class ActorClient;
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
class JournalNPC;
class KeyCombo;
class KeypressHandler;
class LogicalPacket;
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
class SAmpersandEntry;
class SFormattedText;
class ShareBase;
class SharedString;
class SHistoryElement;
class SimpleLogicalPacket;
class SLinkInfo;
class SListWndCell;
class SListWndCellEditUpdate;
class SListWndColumn;
class SListWndLine;
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
class STextLine;
class STextureAnimationFrame;
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
// Class declarations
class CXStr
{
public:
EQLIB_OBJECT CXStr::~CXStr(void);
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

    PCXSTR Ptr;

};

class CXWnd
{
public:
EQLIB_OBJECT enum UIType CXWnd::GetType();
EQLIB_OBJECT class CXMLData * CXWnd::GetXMLData();
EQLIB_OBJECT class CXWnd * CXWnd::GetChildItem(PCHAR Name);
EQLIB_OBJECT CXWnd::CXWnd(class CXWnd *,unsigned __int32,class CXRect);
EQLIB_OBJECT bool CXWnd::HasFocus(void)const;
EQLIB_OBJECT bool CXWnd::IsActive(void)const;
EQLIB_OBJECT bool CXWnd::IsDescendantOf(class CXWnd const *)const;
EQLIB_OBJECT bool CXWnd::IsEnabled(void)const;
EQLIB_OBJECT bool CXWnd::IsReallyVisible(void)const;
//EQLIB_OBJECT bool CXWnd::IsType(enum EWndRuntimeType)const;
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
EQLIB_OBJECT class CXWnd * CXWnd::GetChildWndAt(class CXPoint)const;
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
#ifndef EMU
EQLIB_OBJECT int CXWnd::Move(class CXPoint const &);
#else
EQLIB_OBJECT int CXWnd::Move(class CXPoint);
#endif
#ifndef EMU
EQLIB_OBJECT int CXWnd::Move(class CXRect const &);
#else
EQLIB_OBJECT int CXWnd::Move(class CXRect);
#endif
EQLIB_OBJECT int CXWnd::ProcessTransition(void);
EQLIB_OBJECT int CXWnd::Resize(int,int);
EQLIB_OBJECT int CXWnd::Show(bool,bool,bool mq_c = 1);
EQLIB_OBJECT int CXWnd::Tile(bool);
EQLIB_OBJECT static class CXRect __cdecl CXWnd::GetTooltipRect(class CXPoint,class CXSize);
EQLIB_OBJECT static class CXRect __cdecl CXWnd::GetTooltipRect(class CXSize);
EQLIB_OBJECT static class CXWndDrawTemplate CXWnd::sm_wdtDefaults;
EQLIB_OBJECT static int __cdecl CXWnd::DrawColoredRect(class CXRect,unsigned long,class CXRect);
EQLIB_OBJECT static int __cdecl CXWnd::DrawLasso(class CXRect,unsigned long,class CXRect);
EQLIB_OBJECT static int __cdecl CXWnd::DrawRaisedRect(class CXRect,class CXRect);
EQLIB_OBJECT static int __cdecl CXWnd::DrawSunkenRect(class CXRect,class CXRect);
EQLIB_OBJECT void CXWnd::Bottom(void);
EQLIB_OBJECT void CXWnd::BringChildWndToTop(class CXWnd *);
EQLIB_OBJECT void CXWnd::BringToTop(bool);
EQLIB_OBJECT void CXWnd::Center(void);
EQLIB_OBJECT void CXWnd::ClrFocus(void);
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

CXW;

};
#define ZoneToGoTo 0

class CSidlScreenWnd
{
public:
EQLIB_OBJECT enum UIType CSidlScreenWnd::GetType();
EQLIB_OBJECT class CXMLData * CSidlScreenWnd::GetXMLData();
EQLIB_OBJECT class CXWnd * CSidlScreenWnd::GetChildItem(PCHAR Name);
EQLIB_OBJECT CSidlScreenWnd::CSidlScreenWnd() {};
EQLIB_OBJECT CSidlScreenWnd::CSidlScreenWnd(class CXWnd *,class CXStr);
EQLIB_OBJECT CSidlScreenWnd::CSidlScreenWnd(class CXWnd *pWnd,class CXStr *Template,int Flags,int unknown4, char *unknown5);
EQLIB_OBJECT CSidlScreenWnd::CSidlScreenWnd(class CXWnd *,unsigned __int32,class CXRect,class CXStr);
EQLIB_OBJECT class CScreenPieceTemplate * CSidlScreenWnd::GetSidlPiece(class CXStr*, int dummy=1)const;
EQLIB_OBJECT class CXRect CSidlScreenWnd::GetSidlPieceRect(class CScreenPieceTemplate *,class CXRect)const;
EQLIB_OBJECT class CXWnd * CSidlScreenWnd::GetChildItem(CXStr const &);
EQLIB_OBJECT int CSidlScreenWnd::DrawSidlPiece(class CScreenPieceTemplate *,class CXRect,class CXRect)const;
EQLIB_OBJECT void CSidlScreenWnd::AddButtonToRadioGroup(class CXStr,class CButtonWnd *);
EQLIB_OBJECT void CSidlScreenWnd::CalculateHSBRange(void);
EQLIB_OBJECT void CSidlScreenWnd::CalculateVSBRange(void);
EQLIB_OBJECT void CSidlScreenWnd::CreateChildrenFromSidl(void);
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
EQLIB_OBJECT bool AltAdvManager::IsAbilityReady(class EQ_PC *,EQData::PALTABILITY,int *,int mq2_dummy = 0);
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
EQLIB_OBJECT int AltAdvManager::CanTrainAbility(class EQ_PC *,int);
EQLIB_OBJECT int AltAdvManager::GetAALevelNeeded(class EQ_PC *,int);
EQLIB_OBJECT int AltAdvManager::GetAbilityTitle(class EQPlayer *);
EQLIB_OBJECT int AltAdvManager::GetNextAbilityCost(int,int);
EQLIB_OBJECT int AltAdvManager::MeetsPoPLevelReqs(class EQ_PC *,int,int);
EQLIB_OBJECT int AltAdvManager::TotalPointsInSkill(int,int);
EQLIB_OBJECT unsigned long AltAdvManager::GetCalculatedTimer(class EQ_PC *,EQData::PALTABILITY);
EQLIB_OBJECT void AltAdvManager::GetAbilityReqs(char *,int);
#ifndef EMU
EQLIB_OBJECT struct _ALTABILITY *AltAdvManager::GetAAById(int index, int unknown = -1);//could it be level?
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

class CBankWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CBankWnd::CBankWnd(class CXWnd *,class CXStr);
EQLIB_OBJECT int CBankWnd::GetNumBankSlots(void)const;
EQLIB_OBJECT void CBankWnd::Activate(class EQPlayer *);
EQLIB_OBJECT void CBankWnd::Deactivate(bool);
// virtual
EQLIB_OBJECT CBankWnd::~CBankWnd(void);
EQLIB_OBJECT int CBankWnd::OnProcessFrame(void);
EQLIB_OBJECT int CBankWnd::PostDraw(void)const;
EQLIB_OBJECT int CBankWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
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

class CButtonWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CButtonWnd::CButtonWnd(class CXWnd *,unsigned __int32,class CXRect,class CXPoint,class CXSize,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *);
EQLIB_OBJECT void CButtonWnd::SetCheck(bool);
// virtual
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

class CCharacterSelect : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CCharacterSelect::CCharacterSelect(class CXWnd *);
EQLIB_OBJECT int CCharacterSelect::IsEmptyCharacterSlot(int);
EQLIB_OBJECT int CCharacterSelect::IsValidCharacterSelected(void);
EQLIB_OBJECT int CCharacterSelect::NumberOfCharacters(void);
EQLIB_OBJECT unsigned char CCharacterSelect::IsEvil(int,int,int);
EQLIB_OBJECT void CCharacterSelect::Activate(void);
EQLIB_OBJECT void CCharacterSelect::DeleteCharacter(void);
EQLIB_OBJECT void CCharacterSelect::EnterExplorationMode(void);
EQLIB_OBJECT void CCharacterSelect::EnterWorld(void);
EQLIB_OBJECT void CCharacterSelect::LeaveExplorationMode(void);
EQLIB_OBJECT void CCharacterSelect::Quit(void);
EQLIB_OBJECT void CCharacterSelect::SelectCharacter(int,int);
EQLIB_OBJECT void CCharacterSelect::SetLoadZonePlayerLocation(void);
EQLIB_OBJECT void CCharacterSelect::SwitchModel(class EQPlayer *,unsigned char,int,unsigned char,unsigned char);
EQLIB_OBJECT void CCharacterSelect::UpdateButtonNames(void);
// virtual
EQLIB_OBJECT CCharacterSelect::~CCharacterSelect(void);
EQLIB_OBJECT int CCharacterSelect::Draw(void)const;
EQLIB_OBJECT int CCharacterSelect::OnProcessFrame(void);
EQLIB_OBJECT int CCharacterSelect::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CCharacterSelect::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CCharacterSelect::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CCharacterSelect::Deactivate(void);
// private
EQLIB_OBJECT void CCharacterSelect::CreateExplorationModePlayers(void);
EQLIB_OBJECT void CCharacterSelect::EnableButtons(bool);
EQLIB_OBJECT void CCharacterSelect::EnableEqMovementCommands(bool);
EQLIB_OBJECT void CCharacterSelect::Init(void);
EQLIB_OBJECT void CCharacterSelect::RemoveExplorationModePlayers(void);
EQLIB_OBJECT void CCharacterSelect::SetLocationByClass(class EQPlayer *,bool,int);
EQLIB_OBJECT void CCharacterSelect::SetRoomLocationByIndex(int,class EQPlayer *);
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
EQLIB_OBJECT void CChatManager::SetLockedActiveChatWindow(class CChatWindow *);
EQLIB_OBJECT void CChatManager::UpdateContextMenus(class CChatWindow *);
EQLIB_OBJECT void CChatManager::UpdateTellMenus(class CChatWindow *);
};

class CChatWindow : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CChatWindow::CChatWindow(class CXWnd *);
EQLIB_OBJECT class CEditWnd * CChatWindow::GetInputWnd(void);
EQLIB_OBJECT class CStmlWnd * CChatWindow::GetOutputWnd(void);
EQLIB_OBJECT class CXStr CChatWindow::GetInputText(void);
EQLIB_OBJECT void CChatWindow::AddHistory(class CXStr);
EQLIB_OBJECT void CChatWindow::AddOutputText(class CXStr,int);
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

/*0x188*/ struct _EQCHATMGR *ChatManager; 
/*0x18c*/ struct _CSIDLWND* InputWnd;
/*0x190*/ struct _CSIDLWND* OutputWnd;
/*0x194*/ DWORD Unknown0x194;
/*0x198*/ DWORD Unknown0x198;// need to update locations..
/*0x19c*/ BYTE Unknown0x19c;
/*0x19d*/ BYTE Unknown0x19d[0x3f];
/*0x1dc*/ DWORD Unknown0x1dc;
/*0x1e0*/ DWORD Unknown0x1e0;
/*0x1e4*/ struct _CXSTR *CommandHistory[0x28]; // ->0x198
/*0x284*/ DWORD Unknown0x284; // CChatWindow::HistoryBack/forward .. maybe total or current history lines
/*0x288*/ DWORD Unknown0x288; // CChatWindow::HistoryBack/forward .. maybe total or current history lines
/*0x28c*/ DWORD FontSize; //
/*0x290*/ DWORD Unknown0x290;

//EQLIB_OBJECT void *CChatWindow::operator new(size_t stAllocateBlock) {return malloc(sizeof(EQCHATWINDOW));} // 11-15-2003 lax
};

class CCheckBoxWnd : public CSidlScreenWnd
{
public:
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
};

class CColorPickerWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CColorPickerWnd::CColorPickerWnd(class CXWnd *);
EQLIB_OBJECT void CColorPickerWnd::Activate(class CXWnd *,unsigned long);
EQLIB_OBJECT void CColorPickerWnd::CheckMaxEditWnd(void);
EQLIB_OBJECT void CColorPickerWnd::SetCurrentColor(unsigned long);
EQLIB_OBJECT void CColorPickerWnd::SetTemplateColor(int,unsigned long);
EQLIB_OBJECT void CColorPickerWnd::UpdateCurrentColor(void);
EQLIB_OBJECT void CColorPickerWnd::UpdateEditWndFromSlider(class CSliderWnd *,class CEditWnd *,int *);
EQLIB_OBJECT void CColorPickerWnd::UpdateSliderFromEditWnd(class CSliderWnd *,class CEditWnd *,int *);
// virtual
EQLIB_OBJECT CColorPickerWnd::~CColorPickerWnd(void);
EQLIB_OBJECT int CColorPickerWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
//EQLIB_OBJECT void * CColorPickerWnd::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CColorPickerWnd::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CColorPickerWnd::Deactivate(void);
// private
EQLIB_OBJECT void CColorPickerWnd::Init(void);
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

class CComboWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CComboWnd::CComboWnd(class CXWnd *,unsigned __int32,class CXRect,int,class CButtonDrawTemplate,class CListWnd *);
EQLIB_OBJECT class CXRect CComboWnd::GetButtonRect(void)const;
EQLIB_OBJECT class CXRect CComboWnd::GetListRect(void)const;
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

class CContainerMgr
{
public:
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
};

class CContainerWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CContainerWnd::CContainerWnd(class CXWnd *);
EQLIB_OBJECT void CContainerWnd::Activate(void);
EQLIB_OBJECT void CContainerWnd::CheckCloseable(void);
EQLIB_OBJECT void CContainerWnd::SetContainer(class EQ_Container *,int);
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
};



class CContextMenuManager
{
public:
EQLIB_OBJECT CContextMenuManager::CContextMenuManager(class CXWnd *,unsigned __int32,class CXRect);
EQLIB_OBJECT int CContextMenuManager::AddMenu(class CContextMenu *);
EQLIB_OBJECT int CContextMenuManager::GetDefaultMenuIndex(void);
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

class CControlTemplate
{
public:
EQLIB_OBJECT CControlTemplate::CControlTemplate(class CParamControl *);
// virtual
EQLIB_OBJECT CControlTemplate::~CControlTemplate(void);
//EQLIB_OBJECT void * CControlTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CControlTemplate::`vector deleting destructor'(unsigned int);
};

class CCursorAttachment
{
public:
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

class CDisplay
{
public:
EQLIB_OBJECT CDisplay::~CDisplay(void);
EQLIB_OBJECT CDisplay::CDisplay(struct HWND__ *);
EQLIB_OBJECT bool CDisplay::GenericSphereColl(float,float,float,float,float,float,float *,float *,float *,unsigned char);
EQLIB_OBJECT bool CDisplay::SlideSwitchLeftRight(class EQSwitch *,float,int,float);
EQLIB_OBJECT bool const CDisplay::GetWorldFilePath(char *,char const *);
EQLIB_OBJECT char * CDisplay::GetIniRaceName(int);
EQLIB_OBJECT class EQPlayer * CDisplay::GetNearestPlayerInView(float,bool);
EQLIB_OBJECT float CDisplay::FindZoneTopZ(float,float,float);
EQLIB_OBJECT float CDisplay::FixHeading(float);
EQLIB_OBJECT float CDisplay::GetFloorHeight(float,float,float);
EQLIB_OBJECT float CDisplay::HeadingDiff(float,float,float *);
EQLIB_OBJECT float CDisplay::PlayerDistance(class EQPlayer *,class EQPlayer *,float);
EQLIB_OBJECT float CDisplay::PlayerSimpleDistance(class EQPlayer *,class EQPlayer *,float);
EQLIB_OBJECT float CDisplay::SetActorBoundingRadius(struct T3D_tagACTORINSTANCE *,float,float);
EQLIB_OBJECT float CDisplay::SimpleDistance(float,float,float,float,float,float,float);
EQLIB_OBJECT float CDisplay::TrueDistance(float,float,float,float,float,float,float);
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

class CEditBaseWnd : public CSidlScreenWnd
{
public:
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

class CEditWnd : public CEditBaseWnd
{
public:
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
EQLIB_OBJECT virtual int CEditWnd::GetHorzOffset(void)const;
EQLIB_OBJECT void CEditWnd::FillIndexArray(class CXStr)const;
EQLIB_OBJECT void CEditWnd::FilterInputStr(class CXStr &);
EQLIB_OBJECT void CEditWnd::ProcessText(void);
};

class CEQSuiteTextureLoader
{
public:
EQLIB_OBJECT CEQSuiteTextureLoader::~CEQSuiteTextureLoader(void);
EQLIB_OBJECT CEQSuiteTextureLoader::CEQSuiteTextureLoader(void);
EQLIB_OBJECT struct T3D_tagBMINFO * CEQSuiteTextureLoader::GetTexture(class CUITextureInfo const &);
EQLIB_OBJECT unsigned int CEQSuiteTextureLoader::CreateTexture(class CUITextureInfo const &);
EQLIB_OBJECT void CEQSuiteTextureLoader::UnloadAllTextures(void);
};

class CEverQuest
{
public:
EQLIB_OBJECT CEverQuest::~CEverQuest(void);
EQLIB_OBJECT CEverQuest::CEverQuest(struct HWND__ *);
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
EQLIB_OBJECT int CEverQuest::GetCurrentLanguage(void);
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
EQLIB_OBJECT void CEverQuest::DoPercentConvert(char *,bool);
EQLIB_OBJECT void CEverQuest::DoSplit(char *);
EQLIB_OBJECT void CEverQuest::DoTellWindow(char *,char *,char *,void *,int,bool);
EQLIB_OBJECT void CEverQuest::doUnInvite(char *);
EQLIB_OBJECT void CEverQuest::DropHeldItemOnGround(int);
EQLIB_OBJECT void CEverQuest::DropHeldMoneyOnGround(int);
EQLIB_OBJECT void CEverQuest::DropItemOrMoneyOnPlayer(class EQPlayer *);
EQLIB_OBJECT void CEverQuest::dsp_chat(char const *);
EQLIB_OBJECT void CEverQuest::dsp_chat(char const *,int,bool,bool);
EQLIB_OBJECT void CEverQuest::dsp_chat(char const *,int,bool);
EQLIB_OBJECT void CEverQuest::Emote(void);
EQLIB_OBJECT void CEverQuest::EnterZone(struct HWND__ *);
#ifndef EMU
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
EQLIB_OBJECT void CEverQuest::IssuePetCommand(enum PetCommandType,int,int);
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
EQLIB_OBJECT void CEverQuest::ReportSuccessfulHit(struct _EQSuccessfulHit *,unsigned char,int);
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
EQLIB_OBJECT bool CFileSelectionWnd::DirectoryEmpty(struct IShellFolder *,struct _ITEMIDLIST *);
EQLIB_OBJECT unsigned long CFileSelectionWnd::GetPath(struct IShellFolder *,struct _ITEMIDLIST *,bool,class CXStr &);
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

class CGaugeWnd : public CSidlScreenWnd
{
public:
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

class CGiveWnd : public CSidlScreenWnd
{
public:
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

class CGroupWnd : public CSidlScreenWnd
{
public:
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
EQLIB_OBJECT char * CGuild::GetGuildName(int);
EQLIB_OBJECT int CGuild::GetGuildIndex(char *);
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

class CHotButtonWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CHotButtonWnd::CHotButtonWnd(class CXWnd *);
EQLIB_OBJECT void CHotButtonWnd::Activate(void);
EQLIB_OBJECT void CHotButtonWnd::DoHotButton(int Button,int AllowAutoRightClick);
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
};

class CInvSlot
{
public:
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
// virtual
EQLIB_OBJECT CInvSlot::~CInvSlot(void);
//EQLIB_OBJECT void * CInvSlot::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CInvSlot::`vector deleting destructor'(unsigned int);
};

class CMoveItemData
{
public:
    unsigned short InventoryType;   // 0 = regular inventory slots, 1 = bank slots, 2 = shared bank slots
    unsigned short Unknown0x02;        // always 0?
    unsigned short InvSlot;
    unsigned short BagSlot;         // 0xFFFF if not in a bag, otherwise the bag slot number (0 through 9, or 0 through 19 if it's a 20-slot bag, etc)
    unsigned short GlobalSlot;
    unsigned short RandomNum;
    unsigned long  Selection;
};

class CInvSlotMgr
{
public:
EQLIB_OBJECT CInvSlotMgr::CInvSlotMgr(void);
EQLIB_OBJECT class CInvSlot * CInvSlotMgr::CreateInvSlot(class CInvSlotWnd *);
EQLIB_OBJECT class CInvSlot * CInvSlotMgr::FindInvSlot(int,int x=-1);
EQLIB_OBJECT bool CInvSlotMgr::MoveItem(CMoveItemData*,CMoveItemData*,int valueOne,int valueOne2,int valueZero,int valueZero2);
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

class CInvSlotWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CInvSlotWnd::CInvSlotWnd(class CXWnd *,unsigned __int32,class CXRect,class CTextureAnimation *,int,int,int);
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

class CItemDisplayWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CItemDisplayWnd::CItemDisplayWnd(class CXWnd *);
EQLIB_OBJECT class CXStr CItemDisplayWnd::CreateEquipmentStatusString(class EQ_Item *);
EQLIB_OBJECT void CItemDisplayWnd::SetItem(class EQ_Item *,bool);
EQLIB_OBJECT void CItemDisplayWnd::SetItemText(char *);
EQLIB_OBJECT void CItemDisplayWnd::SetSpell(int SpellID,bool HasSpellDescr,int);
EQLIB_OBJECT void CItemDisplayWnd::UpdateStrings(void);
// virtual
EQLIB_OBJECT CItemDisplayWnd::~CItemDisplayWnd(void);
EQLIB_OBJECT int CItemDisplayWnd::HandleKeyboardMsg(unsigned __int32,unsigned __int32,bool);
EQLIB_OBJECT int CItemDisplayWnd::OnProcessFrame(void);
EQLIB_OBJECT int CItemDisplayWnd::WndNotification(class CXWnd *,unsigned __int32,void *);
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

class CLabel
{
public:
EQLIB_OBJECT CLabel::CLabel(class CXWnd *,unsigned __int32,class CXRect,int);
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

class CListWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CListWnd::CListWnd(class CXWnd *,unsigned __int32,class CXRect const &);
EQLIB_OBJECT CListWnd::CListWnd() {};
EQLIB_OBJECT bool CListWnd::IsLineEnabled(int)const;
EQLIB_OBJECT class CTextureAnimation const * CListWnd::GetColumnAnimation(int)const;
EQLIB_OBJECT class CTextureAnimation const * CListWnd::GetColumnAnimationMouseOver(int)const;
EQLIB_OBJECT class CTextureAnimation const * CListWnd::GetColumnAnimationSelected(int)const;
EQLIB_OBJECT class CTextureAnimation const * CListWnd::GetItemIcon(int,int)const;
EQLIB_OBJECT class CXRect CListWnd::GetHeaderRect(int)const;
EQLIB_OBJECT class CXRect CListWnd::GetItemRect(int,int)const;
EQLIB_OBJECT class CXRect CListWnd::GetSeparatorRect(int)const;
EQLIB_OBJECT class CXStr CListWnd::GetColumnLabel(int)const;
EQLIB_OBJECT class CXStr *CListWnd::GetItemText(class CXStr *,int,int)const;
EQLIB_OBJECT int CListWnd::AddColumn(class CXStr,class CTextureAnimation *,int,unsigned __int32,unsigned __int32,class CTextureAnimation *,class CTextureAnimation *);
EQLIB_OBJECT int CListWnd::AddColumn(class CXStr,int,unsigned __int32,unsigned __int32);
EQLIB_OBJECT int CListWnd::AddLine(class SListWndLine const *);
EQLIB_OBJECT int CListWnd::AddString(class CXStr *,unsigned long,unsigned __int32,class CTextureAnimation const *, const char* p5 = 0);
EQLIB_OBJECT int CListWnd::AddString(char *,unsigned long,unsigned __int32,class CTextureAnimation const *, const char* p5 = 0);
EQLIB_OBJECT int CListWnd::GetColumnJustification(int)const;
EQLIB_OBJECT int CListWnd::GetColumnMinWidth(int)const;
EQLIB_OBJECT int CListWnd::GetColumnWidth(int)const;
EQLIB_OBJECT int CListWnd::GetCurCol(void)const;
EQLIB_OBJECT int CListWnd::GetCurSel(void)const;
EQLIB_OBJECT int CListWnd::GetItemAtPoint(class CXPoint)const;
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
EQLIB_OBJECT void CListWnd::EnableLine(int,bool);
EQLIB_OBJECT void CListWnd::EnsureVisible(int);
EQLIB_OBJECT void CListWnd::ExtendSel(int);
EQLIB_OBJECT void CListWnd::GetItemAtPoint(class CXPoint,int *,int *)const;
EQLIB_OBJECT void CListWnd::RemoveLine(int);
EQLIB_OBJECT void CListWnd::RemoveString(int);
EQLIB_OBJECT void CListWnd::SetColors(unsigned long,unsigned long,unsigned long);
EQLIB_OBJECT void CListWnd::SetColumnJustification(int,int);
EQLIB_OBJECT void CListWnd::SetColumnLabel(int,class CXStr);
EQLIB_OBJECT void CListWnd::SetColumnWidth(int,int);
EQLIB_OBJECT void CListWnd::SetCurSel(int);
EQLIB_OBJECT void CListWnd::SetItemColor(int,int,unsigned long);
EQLIB_OBJECT void CListWnd::SetItemData(int,unsigned __int32);
EQLIB_OBJECT void CListWnd::SetItemText(int,int,class CXStr *);
EQLIB_OBJECT void CListWnd::ShiftColumnSeparator(int,int);
EQLIB_OBJECT void CListWnd::ToggleSel(int);
// virtual
EQLIB_OBJECT CListWnd::~CListWnd(void);
EQLIB_OBJECT class CTextureAnimation * CListWnd::GetCursorToDisplay(void)const;
EQLIB_OBJECT int CListWnd::Compare(class SListWndLine const &,class SListWndLine const &)const;
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
};

class CContextMenu : public CListWnd
{
public:
EQLIB_OBJECT CContextMenu::CContextMenu(class CXWnd *,unsigned __int32,class CXRect const &);
EQLIB_OBJECT int CContextMenu::AddMenuItem(class CXStr const &str,unsigned long menuid,unsigned __int32 arg3,unsigned __int32 arg4,bool arg5);
EQLIB_OBJECT int CContextMenu::AddSeparator(void);
EQLIB_OBJECT void CContextMenu::Activate(class CXPoint,int,int);
EQLIB_OBJECT void CContextMenu::CheckMenuItem(int,bool,bool);
EQLIB_OBJECT void CContextMenu::EnableMenuItem(int,bool);
EQLIB_OBJECT void CContextMenu::RemoveAllMenuItems(void);
// virtual
EQLIB_OBJECT CContextMenu::~CContextMenu(void);
EQLIB_OBJECT int CContextMenu::OnKillFocus(class CXWnd *);
//EQLIB_OBJECT void * CContextMenu::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CContextMenu::`vector deleting destructor'(unsigned int);
EQLIB_OBJECT void CContextMenu::Deactivate(void);
CONTEXTTAIL
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
EQLIB_OBJECT void CLootWnd::RequestLootSlot(int,bool);
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

class CMapViewWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CMapViewWnd::CMapViewWnd(class CXWnd *);
EQLIB_OBJECT bool CMapViewWnd::IsMappingEnabled(void);
EQLIB_OBJECT void CMapViewWnd::Activate(void);
EQLIB_OBJECT void CMapViewWnd::ActivateAutoMapping(void);
EQLIB_OBJECT void CMapViewWnd::DeactivateAutoMapping(void);
//EQLIB_OBJECT void CMapViewWnd::SetCurrentZone(EQZoneIndex,struct T3D_XYZ *,struct T3D_XYZ *);
// virtual
EQLIB_OBJECT CMapViewWnd::~CMapViewWnd(void);
EQLIB_OBJECT int CMapViewWnd::HandleLButtonDown(class CXPoint,unsigned __int32);
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

class CMerchantWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CMerchantWnd::CMerchantWnd(class CXWnd *);
EQLIB_OBJECT void CMerchantWnd::Activate(class EQPlayer *,float);
EQLIB_OBJECT void CMerchantWnd::AddContainerToMercArray(class EQ_Container *);
EQLIB_OBJECT void CMerchantWnd::AddEquipmentToMercArray(class EQ_Equipment *);
EQLIB_OBJECT void CMerchantWnd::AddNoteToMercArray(class EQ_Note *);
EQLIB_OBJECT void CMerchantWnd::ClearMerchantSlot(int);
EQLIB_OBJECT void CMerchantWnd::FinishBuyingItem(struct _sell_msg *);
EQLIB_OBJECT void CMerchantWnd::FinishSellingItem(struct _sell_msg *);
EQLIB_OBJECT void CMerchantWnd::SelectBuySellSlot(int,class CTextureAnimation *);
EQLIB_OBJECT int CMerchantWnd::ActualSelect(CMoveItemData *);
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
EQLIB_OBJECT void CMerchantWnd::RequestBuyItem(int);
EQLIB_OBJECT void CMerchantWnd::RequestSellItem(int);
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
EQLIB_OBJECT void COptionsWnd::SaveColors(int,int,int,int);
EQLIB_OBJECT void COptionsWnd::SetBagOptions(int,int);
EQLIB_OBJECT void COptionsWnd::SyncChatPage(void);
EQLIB_OBJECT void COptionsWnd::SyncColorPage(void);
EQLIB_OBJECT void COptionsWnd::SyncDisplayPage(void);
EQLIB_OBJECT void COptionsWnd::SyncGeneralPage(void);
EQLIB_OBJECT void COptionsWnd::SyncMousePage(void);
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

class CResolutionHandler
{
public:
EQLIB_OBJECT static bool __cdecl CResolutionHandler::IsFullscreenAvailable(void);
EQLIB_OBJECT static int __cdecl CResolutionHandler::GetDesktopBitsPerPixel(void);
EQLIB_OBJECT static int __cdecl CResolutionHandler::GetDesktopHeight(void);
EQLIB_OBJECT static int __cdecl CResolutionHandler::GetDesktopRefreshRate(void);
EQLIB_OBJECT static int __cdecl CResolutionHandler::GetDesktopWidth(void);
EQLIB_OBJECT static int __cdecl CResolutionHandler::GetHeight(void);
EQLIB_OBJECT static int __cdecl CResolutionHandler::GetWidth(void);
EQLIB_OBJECT static int __cdecl CResolutionHandler::Init(void);
EQLIB_OBJECT static void __cdecl CResolutionHandler::ChangeToResolution(int,int,int,int,int);
EQLIB_OBJECT static void __cdecl CResolutionHandler::SaveSettings(void);
EQLIB_OBJECT static void __cdecl CResolutionHandler::Shutdown(void);
EQLIB_OBJECT static void __cdecl CResolutionHandler::ToggleScreenMode(void);
EQLIB_OBJECT static void __cdecl CResolutionHandler::UpdateWindowPosition(void);
// private
EQLIB_OBJECT static bool CResolutionHandler::ms_isFullscreen;
EQLIB_OBJECT static int CResolutionHandler::ms_fullscreenBitsPerPixel;
EQLIB_OBJECT static int CResolutionHandler::ms_fullscreenRefreshRate;
EQLIB_OBJECT static int CResolutionHandler::ms_height;
EQLIB_OBJECT static int CResolutionHandler::ms_width;
EQLIB_OBJECT static int CResolutionHandler::ms_windowedOffsetX;
EQLIB_OBJECT static int CResolutionHandler::ms_windowedOffsetY;
};

class CScreenPieceTemplate
{
public:
EQLIB_OBJECT CScreenPieceTemplate::CScreenPieceTemplate(class CParamScreenPiece *);
EQLIB_OBJECT bool CScreenPieceTemplate::IsType(unsigned __int32)const;
EQLIB_OBJECT class CXStr CScreenPieceTemplate::GetName(void)const;
// virtual
EQLIB_OBJECT CScreenPieceTemplate::~CScreenPieceTemplate(void);
//EQLIB_OBJECT void * CScreenPieceTemplate::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CScreenPieceTemplate::`vector deleting destructor'(unsigned int);
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

class CSidlManager
{
public:
EQLIB_OBJECT CSidlManager::CSidlManager(void);
EQLIB_OBJECT class CButtonDrawTemplate * CSidlManager::FindButtonDrawTemplate(unsigned __int32)const;
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
EQLIB_OBJECT class CXWnd * CSidlManager::CreateXWndFromTemplate(class CXWnd *,class CControlTemplate *);
EQLIB_OBJECT class CXWndDrawTemplate * CSidlManager::FindDrawTemplate(class CXStr)const;
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
EQLIB_OBJECT static unsigned __int32 CStmlReport::m_uLastId;
};

class CStmlWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CStmlWnd::CStmlWnd(class CXWnd *,unsigned __int32,class CXRect);
EQLIB_OBJECT bool CStmlWnd::CanGoBackward(void);
EQLIB_OBJECT class CXSize CStmlWnd::AppendSTML(class CXStr); // lax 11-15-2003
EQLIB_OBJECT class CXStr CStmlWnd::GetSTMLText(void)const;
EQLIB_OBJECT class CXStr CStmlWnd::GetVisibleText(class CXStr&,class CXRect)const;
EQLIB_OBJECT static class CXStr __cdecl CStmlWnd::MakeStmlColorTag(unsigned long);
EQLIB_OBJECT static class CXStr __cdecl CStmlWnd::MakeWndNotificationTag(unsigned __int32,class CXStr&,class CXStr&);
EQLIB_OBJECT void CStmlWnd::ActivateLink(class SLinkInfo);
EQLIB_OBJECT void CStmlWnd::ForceParseNow(void);
EQLIB_OBJECT void CStmlWnd::GoToBackHistoryLink(void);
//EQLIB_OBJECT void CStmlWnd::LoadPage(class CXStr,enum ESTMLTargetValue,bool);
EQLIB_OBJECT void CStmlWnd::SetSTMLText(class CXStr,bool,class SLinkInfo *);
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
EQLIB_OBJECT bool CStmlWnd::IsLinkActive(class SLinkInfo)const;
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
EQLIB_OBJECT void CStmlWnd::ActivateLinkFile(class SLinkInfo);
EQLIB_OBJECT void CStmlWnd::ActivateLinkMessageId(class SLinkInfo);
EQLIB_OBJECT void CStmlWnd::ActivateLinkReport(class SLinkInfo,bool);
EQLIB_OBJECT void CStmlWnd::ActivateLinkWndNotify(class SLinkInfo);
EQLIB_OBJECT void CStmlWnd::AddLinkToHistory(class SLinkInfo,class CXStr);
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
EQLIB_OBJECT CTabWnd::CTabWnd(class CXWnd *,unsigned __int32,class CXRect,class CTabBoxTemplate *);
EQLIB_OBJECT class CPageWnd * CTabWnd::GetCurrentPage(void)const;
EQLIB_OBJECT class CXRect CTabWnd::GetPageClientRect(void)const;
EQLIB_OBJECT class CXRect CTabWnd::GetPageInnerRect(void)const;
EQLIB_OBJECT class CXRect CTabWnd::GetTabInnerRect(int)const;
EQLIB_OBJECT class CXRect CTabWnd::GetTabRect(int)const;
EQLIB_OBJECT int CTabWnd::GetCurrentTabIndex(void)const;
EQLIB_OBJECT int CTabWnd::GetNumTabs(void)const;
EQLIB_OBJECT void CTabWnd::InsertPage(class CPageWnd *,int);
EQLIB_OBJECT void CTabWnd::SetPage(class CPageWnd *,bool);
EQLIB_OBJECT void CTabWnd::SetPage(int,bool,bool);
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
EQLIB_OBJECT class CPageWnd * CTabWnd::GetPageFromTabIndex(int)const;
EQLIB_OBJECT class CPageWnd * CTabWnd::GetPageFromTabPoint(class CXPoint)const;
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
};

class CTaskWnd : public CSidlScreenWnd
{
public:
EQLIB_OBJECT CTaskWnd::CTaskWnd(class CXWnd *);
EQLIB_OBJECT int CTaskWnd::UpdateTaskTimers(unsigned long fasttime);
// virtual
EQLIB_OBJECT CTaskWnd::~CTaskWnd(void);
};
class CTaskSomething
{
public:
EQLIB_OBJECT CTaskSomething::CTaskSomething(class CXWnd *);
// virtual
EQLIB_OBJECT CTaskSomething::~CTaskSomething(void);
EQLIB_OBJECT DWORD CTaskSomething::GetTaskByIndex(DWORD arg1,DWORD arg2,DWORD arg3);
};
class CTextEntryWnd : public CEditBaseWnd
{
public:
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

class CTextureAnimation
{
public:
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
EQLIB_OBJECT static unsigned __int32 CTextureAnimation::sm_uMaxId;
};

class CTextureFont
{
public:
EQLIB_OBJECT class CXStr CTextureFont::GetName(void)const;
EQLIB_OBJECT int CTextureFont::DrawWrappedText(class CXStr,class CXRect,class CXRect,unsigned long,unsigned short,int)const;
EQLIB_OBJECT int CTextureFont::DrawWrappedText(class CXStr *,int,int,int,class CXRect *,unsigned long,unsigned short,int)const;
EQLIB_OBJECT int CTextureFont::GetHeight(void)const;
EQLIB_OBJECT int CTextureFont::GetKerning(unsigned short,unsigned short)const;
EQLIB_OBJECT int CTextureFont::GetTextExtent(class CXStr)const;
EQLIB_OBJECT int CTextureFont::GetWidth(unsigned short)const;
// virtual
EQLIB_OBJECT CTextureFont::~CTextureFont(void);
//EQLIB_OBJECT void * CTextureFont::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CTextureFont::`vector deleting destructor'(unsigned int);
void  *Unknown0x0;
DWORD Font;
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

class CTradeWnd : public CSidlScreenWnd
{
public:
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

class CUITexturePiece
{
public:
EQLIB_OBJECT CUITexturePiece::~CUITexturePiece(void);
EQLIB_OBJECT CUITexturePiece::CUITexturePiece(class CUITexturePiece const &);
EQLIB_OBJECT CUITexturePiece::CUITexturePiece(class CUITextureInfo,class CXRect);
EQLIB_OBJECT CUITexturePiece::CUITexturePiece(void);
EQLIB_OBJECT class CUITexturePiece & CUITexturePiece::operator=(class CUITexturePiece const &);
EQLIB_OBJECT int CUITexturePiece::Draw(class CXRect,class CXRect,class CXRect,unsigned long,unsigned long)const;
EQLIB_OBJECT int CUITexturePiece::Draw(class CXRect,class CXRect,unsigned long,unsigned long)const;
};

class CVector3
{
public:
EQLIB_OBJECT float CVector3::GetLength(void)const;
EQLIB_OBJECT float CVector3::NormalizeAndReturnLength(void);
EQLIB_OBJECT void CVector3::Normalize(void);
	float X;
	float Y;
	float Z;
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

class CXMLDataManager
{
public:
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

class CXMLParamManager
{
public:
// virtual
EQLIB_OBJECT CXMLParamManager::~CXMLParamManager(void);
EQLIB_OBJECT bool CXMLParamManager::XMLDataCopy(class CXMLData *,class CXMLData *);
EQLIB_OBJECT class CXMLData * CXMLParamManager::AllocPtr(class CXMLDataPtr &,int,class CXMLData const *);
//EQLIB_OBJECT void * CXMLParamManager::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CXMLParamManager::`vector deleting destructor'(unsigned int);
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
DWORD A,B;
};

class CXRect
{
public:
EQLIB_OBJECT CXRect::CXRect(int nA,int nB,int nC,int nD)
{
    A=nA;
    B=nB;
    C=nC;
    D=nD;
}
EQLIB_OBJECT CXRect::CXRect(void)
{
}
EQLIB_OBJECT class CXPoint CXRect::CenterPoint(void)const;
EQLIB_OBJECT class CXRect & CXRect::operator=(class CXRect const &);
EQLIB_OBJECT class CXRect CXRect::operator&(class CXRect)const;
EQLIB_OBJECT class CXRect CXRect::operator|(class CXRect)const;
EQLIB_OBJECT int CXRect::Width(void)const;
EQLIB_OBJECT void CXRect::Move(class CXPoint);
EQLIB_OBJECT void CXRect::Normalize(void);
DWORD A,B,C,D;
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
EQLIB_OBJECT class CTextureFont * CXWndManager::GetFont(class CXStr);
EQLIB_OBJECT class CTextureFont * CXWndManager::GetFont(int)const;
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
//EQLIB_OBJECT void * CXWndManager::`scalar deleting destructor'(unsigned int);
//EQLIB_OBJECT void * CXWndManager::`vector deleting destructor'(unsigned int);
};

class ActorClient
{
	//CVector3 *

public:
EQLIB_OBJECT class CVector3 const & ActorClient::GetPosition(void)const;
EQLIB_OBJECT void ActorClient::GetPosition(class CVector3 *)const;
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

class EQ_Affect
{
public:
EQLIB_OBJECT void EQ_Affect::Reset(void);
};

class EQ_AltAbility
{
public:
EQLIB_OBJECT EQ_AltAbility::EQ_AltAbility(int);
};

class EQ_Character1
{
public:
EQLIB_OBJECT int EQ_Character1::Cur_HP(int,unsigned char y=1);
EQLIB_OBJECT int EQ_Character1::Max_Endurance(int y=1); // lax 4-25-2004
EQLIB_OBJECT int EQ_Character1::Max_HP(int,int y=1); 
EQLIB_OBJECT int EQ_Character1::Max_Mana(int y=1);
EQLIB_OBJECT int const EQ_Character1::GetAACastingTimeModifier(class EQ_Spell const *);
EQLIB_OBJECT int const EQ_Character1::GetFocusCastingTimeModifier(class EQ_Spell const *,class EQ_Equipment * *,int);
EQLIB_OBJECT unsigned char EQ_Character1::CastSpell(unsigned char,int,class EQ_Item * *,int,int slot,int,int,int,int,bool,int y=1); 
EQLIB_OBJECT void EQ_Character1::SetEffectId(unsigned char,unsigned int);
EQLIB_OBJECT void EQ_Character1::StopSpellCast(unsigned char);
EQLIB_OBJECT void EQ_Character1::StopSpellCast(unsigned char,int);
EQLIB_OBJECT void EQ_Character1::StunMe(unsigned int,bool,bool,bool);
EQLIB_OBJECT void EQ_Character1::UnStunMe(void);
EQLIB_OBJECT void EQ_Character1::UseSkill(unsigned char,class EQPlayer *);
EQLIB_OBJECT int const EQ_Character1::GetFocusRangeModifier(class EQ_Spell const *,class EQ_Equipment * *);
EQLIB_OBJECT int EQ_Character1::IsExpansionFlag(int);
EQLIB_OBJECT int EQ_Character1::TotalEffect(int,bool,int,bool,bool);
};

class EQ_Character
{
public:
EQLIB_OBJECT EQ_Character::~EQ_Character(void);
EQLIB_OBJECT EQ_Character::EQ_Character(void);
EQLIB_OBJECT bool EQ_Character::DoesSpellMatchFocusFilters(class EQ_Spell const *,class EQ_Spell const *);
EQLIB_OBJECT bool EQ_Character::IsSpellTooPowerfull(class EQ_Spell *,class EQ_Character *);
#ifndef EMU
EQLIB_OBJECT bool EQ_Character::IsStackBlocked(class EQ_Spell const *, DWORD, DWORD, DWORD, bool);
#else
EQLIB_OBJECT bool EQ_Character::IsStackBlocked(class EQ_Spell const *, DWORD,DWORD,DWORD);
#endif
EQLIB_OBJECT bool EQ_Character::IsValidAffect(int);
EQLIB_OBJECT char * EQ_Character::Class(int);
EQLIB_OBJECT char * EQ_Character::KunarkClass(int,int,int,bool);
EQLIB_OBJECT char * EQ_Character::Race(int);
EQLIB_OBJECT class EQ_Affect & EQ_Character::GetEffect(int);
EQLIB_OBJECT class EQ_Affect * EQ_Character::FindAffectSlot(int,class EQPlayer *,int *,int);
EQLIB_OBJECT class EQ_Affect * EQ_Character::GetPCSpellAffect(unsigned char,int *);
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
EQLIB_OBJECT int EQ_Character::CanUseItem(class EQ_Item *);
EQLIB_OBJECT int EQ_Character::CapStat(int,int);
EQLIB_OBJECT int EQ_Character::Cha(void);
EQLIB_OBJECT int EQ_Character::CheckFoodAndWater(void);
EQLIB_OBJECT int EQ_Character::compute_defense(void);
EQLIB_OBJECT int EQ_Character::compute_tohit(unsigned char);
EQLIB_OBJECT int EQ_Character::cur_encumbrance(void);
EQLIB_OBJECT int EQ_Character::Cur_Mana(void);
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
EQLIB_OBJECT unsigned char EQ_Character::FindItemByRecord(int,int *,int *);
EQLIB_OBJECT unsigned char EQ_Character::FindItemQty(int,int);
EQLIB_OBJECT unsigned char EQ_Character::FroglockCanWorship(unsigned char,unsigned char);
EQLIB_OBJECT unsigned char EQ_Character::GetMaxEffects(void)const;
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
EQLIB_OBJECT unsigned int EQ_Character::GetEffectId(int);
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
EQLIB_OBJECT void EQ_Character::ModifyCurHP(int,class EQPlayer *);
EQLIB_OBJECT void EQ_Character::NotifyPCAffectChange(int,int);
EQLIB_OBJECT void EQ_Character::ProcessAllStats(void);
EQLIB_OBJECT void EQ_Character::ProcessEnvironment(void);
EQLIB_OBJECT void EQ_Character::ProcessHungerandThirst(unsigned int);
EQLIB_OBJECT void EQ_Character::RemovePCAffect(class EQ_Affect *);
EQLIB_OBJECT void EQ_Character::RemovePCAffectex(class EQ_Affect *,int);
EQLIB_OBJECT void EQ_Character::ResetCur_HP(int);
EQLIB_OBJECT void EQ_Character::UpdateMyVisibleStatus(void);
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
EQLIB_OBJECT char * EQ_Item::CreateItemTagString(char *, int); // Lax 11-14-2003
EQLIB_OBJECT int EQ_Item::CanDrop(bool,int,int mq2_dummy=0, int mq2_dummy2=1);
EQLIB_OBJECT int EQ_Item::GetImageNum(void)const;
EQLIB_OBJECT struct  _CONTENTS** __cdecl CreateItemClient(PBYTE*,DWORD);
EQLIB_OBJECT int EQ_Item::GetItemValue(bool)const;
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
EQLIB_OBJECT unsigned long EQ_PC::GetCombatAbilityTimer(int,int);
EQLIB_OBJECT unsigned long EQ_PC::GetItemTimerValue(class EQ_Item *);
EQLIB_OBJECT unsigned long EQ_PC::HasLoreItem(class EQ_Item *);
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
EQLIB_OBJECT int EQ_Spell::IsPermIllusionSpell(void)const;
EQLIB_OBJECT int EQ_Spell::SpellUsesDragonBreathEffect(void);
EQLIB_OBJECT static bool __cdecl EQ_Spell::IsSPAIgnoredByStacking(int);
EQLIB_OBJECT unsigned char EQ_Spell::SpellAffects(int)const;//this one takes an attrib(soe calls it affect) and returns the index for it...
EQLIB_OBJECT unsigned char EQ_Spell::GetSpellLevelNeeded(int)const;//takes a Class, druid for example is 6
EQLIB_OBJECT LONG EQ_Spell::GetSpellBaseByAttrib(int)const;//takes a attrib, returns the baseval for it.
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

class EQPlayer
{
public:
EQLIB_OBJECT EQPlayer::~EQPlayer(void);
EQLIB_OBJECT EQPlayer::EQPlayer(class EQPlayer *,unsigned char,unsigned int,unsigned char,char *);
EQLIB_OBJECT bool EQPlayer::AllowedToAttack(class EQPlayer *,int);
EQLIB_OBJECT bool EQPlayer::CanChangeForm(int,unsigned char);
EQLIB_OBJECT bool EQPlayer::CanIFitHere(float,float,float);
EQLIB_OBJECT bool EQPlayer::CanIHit(class EQPlayer *,float);
EQLIB_OBJECT bool EQPlayer::CanSee(class EQPlayer *);
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
EQLIB_OBJECT int EQPlayer::DoAttack(unsigned char,unsigned char,class EQPlayer *);
EQLIB_OBJECT int EQPlayer::GetAlternateTrackNumber(int,unsigned char *);
EQLIB_OBJECT int EQPlayer::GetArmorType(int);
EQLIB_OBJECT int EQPlayer::GetAttachedHelmITNum(int,int *);
EQLIB_OBJECT int EQPlayer::GetGuild(void)const;
EQLIB_OBJECT int EQPlayer::GetRaceSexITOffset(void);
EQLIB_OBJECT int EQPlayer::IsValidTeleport(float,float,float,float,float);
EQLIB_OBJECT int EQPlayer::LegalPlayerRace(int);
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
EQLIB_OBJECT bool EQPlayer::IsBodyType(unsigned int,int,int);
// private
EQLIB_OBJECT int EQPlayer::IdUsed(unsigned int);
EQLIB_OBJECT static class EQPlayer * EQPlayer::mTop;
EQLIB_OBJECT struct S3D_STRINGSPRITE * EQPlayer::ChangeBoneStringSprite(struct T3D_DAG *,char *);
EQLIB_OBJECT unsigned char EQPlayer::GetAlternateAnimVariation(int,unsigned char);
EQLIB_OBJECT unsigned int EQPlayer::GetUnusedID(void);
EQLIB_OBJECT void EQPlayer::FindDefaultEyeMaterialIndexes(void);
EQLIB_OBJECT void EQPlayer::InitializeIDArray(void);
SPAWNINFO Data;
};


class EQPlayerManager
{
public:
EQLIB_OBJECT class EQPlayer *EQPlayerManager::GetSpawnByID(int);
EQLIB_OBJECT class EQPlayer *EQPlayerManager::GetSpawnByName(char *);
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
EQLIB_OBJECT void EqSoundManager::ReleaseZoneSpecificEmitters(void);
EQLIB_OBJECT void EqSoundManager::ReleaseZoneSpecificMidi(void);
EQLIB_OBJECT void EqSoundManager::ReleaseZoneSpecificWaves(void);
EQLIB_OBJECT void EqSoundManager::UpdateEmitterStates(void);
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
EQLIB_OBJECT void EQSwitch::UseSwitch(DWORD,DWORD,DWORD,DWORD);
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

class IconCache
{
public:
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

class SLinkInfo
{
public:
EQLIB_OBJECT SLinkInfo::~SLinkInfo(void);
EQLIB_OBJECT SLinkInfo::SLinkInfo(class SLinkInfo const &);
EQLIB_OBJECT SLinkInfo::SLinkInfo(void);
EQLIB_OBJECT class SLinkInfo & SLinkInfo::operator=(class SLinkInfo const &);
};

class SListWndCell
{
public:
EQLIB_OBJECT SListWndCell::~SListWndCell(void);
EQLIB_OBJECT SListWndCell::SListWndCell(void);
EQLIB_OBJECT class SListWndCell & SListWndCell::operator=(class SListWndCell const &);
//EQLIB_OBJECT void * SListWndCell::`vector deleting destructor'(unsigned int);
};

class SListWndCellEditUpdate
{
public:
EQLIB_OBJECT SListWndCellEditUpdate::~SListWndCellEditUpdate(void);
};

class SListWndColumn
{
public:
EQLIB_OBJECT SListWndColumn::~SListWndColumn(void);
EQLIB_OBJECT SListWndColumn::SListWndColumn(class CXStr,int,class CTextureAnimation *,unsigned __int32,unsigned __int32,class CTextureAnimation *,class CTextureAnimation *);
//EQLIB_OBJECT void SListWndColumn::`default constructor closure'(void);
};

class SListWndLine
{
public:
EQLIB_OBJECT SListWndLine::~SListWndLine(void);
EQLIB_OBJECT SListWndLine::SListWndLine(void);
EQLIB_OBJECT class SListWndLine & SListWndLine::operator=(class SListWndLine const &);
};

class SListWndSortInfo
{
public:
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

class SpellManager
{
public:
EQLIB_OBJECT SpellManager::~SpellManager(void);
EQLIB_OBJECT SpellManager::SpellManager(char *);
SPELLMGR Data;
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

class STextLine
{
public:
EQLIB_OBJECT STextLine::~STextLine(void);
EQLIB_OBJECT STextLine::STextLine(void);
EQLIB_OBJECT class STextLine & STextLine::operator=(class STextLine const &);
//EQLIB_OBJECT void * STextLine::`vector deleting destructor'(unsigned int);
};

class STextureAnimationFrame
{
public:
EQLIB_OBJECT STextureAnimationFrame::~STextureAnimationFrame(void);
EQLIB_OBJECT STextureAnimationFrame::STextureAnimationFrame(class CUITexturePiece,unsigned __int32,class CXPoint);
EQLIB_OBJECT STextureAnimationFrame::STextureAnimationFrame(void);
EQLIB_OBJECT class STextureAnimationFrame & STextureAnimationFrame::operator=(class STextureAnimationFrame const &);
//EQLIB_OBJECT void * STextureAnimationFrame::`vector deleting destructor'(unsigned int);
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
EQLIB_OBJECT char * StringTable::getString(unsigned long,bool *);
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
EQLIB_OBJECT bool CSkillMgr::IsActivatableSkill(int);
EQLIB_OBJECT unsigned long CSkillMgr::GetBaseDamage(int);
EQLIB_OBJECT unsigned long CSkillMgr::GetReuseTime(int);
EQLIB_OBJECT bool CSkillMgr::IsAvailable(int);
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

class CharacterZoneClient
{
public:
EQLIB_OBJECT int CharacterZoneClient::CalcAffectChange(class EQ_Spell *,unsigned char,unsigned char,class EQ_Affect *,DWORD,DWORD);
EQLIB_OBJECT void CharacterZoneClient::MakeMeVisible(int,bool);
    bool HasSkill(int);
};

class PcZoneClient
{
public:
EQLIB_OBJECT int PcZoneClient::GetPcSkillLimit(int);
EQLIB_OBJECT bool PcZoneClient::HasCombatAbility(int);
EQLIB_OBJECT void PcZoneClient::RemovePetEffect(int);
};

};
using namespace EQClasses;
