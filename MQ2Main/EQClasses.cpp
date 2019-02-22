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

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW


#include "MQ2Main.h"
enum UIType CXWnd::GetType()
{
    if (CXMLData *pXMLData=GetXMLData())
    return pXMLData->Type;
    return UI_Unknown;
}

enum UIType CSidlScreenWnd::GetType()
{
    if (CXMLData *pXMLData=GetXMLData())
    return pXMLData->Type;
    return UI_Unknown;
}

class CXMLData * CXWnd::GetXMLData()
{
    if (XMLIndex)
        return ((CXMLDataManager*)&((PCSIDLMGR)pSidlMgr)->pXMLDataMgr)->GetXMLData(XMLIndex>>16,XMLIndex&0xFFFF);
    //DebugSpew("CXWnd::GetXMLData()=0");
    return 0;
}
class CXMLData * CSidlScreenWnd::GetXMLData()
{
    if (XMLIndex)
        return ((CXMLDataManager*)&((PCSIDLMGR)pSidlMgr)->pXMLDataMgr)->GetXMLData(XMLIndex>>16,XMLIndex&0xFFFF);
    //DebugSpew("CSidlScreenWnd::GetXMLData()=0");
    return 0;
}

// fuck -- if you try to use the native GetChildItem, then
// it fails to find things without a ScreenID

class CXWnd *RecurseAndFindName(class CXWnd *pWnd, PCHAR Name)
{
    CHAR Buffer[MAX_STRING]={0};
    class CXWnd *tmp;

    if (!pWnd) return pWnd;

    if (CXMLData *pXMLData=pWnd->GetXMLData()) {
        if (GetCXStr(pXMLData->Name.Ptr,Buffer,MAX_STRING) && !_stricmp(Buffer,Name)) {
            return pWnd;
        }
        //DebugSpew("RecurseAndFindName looking for %s but found %s", Name, Buffer);
        if (GetCXStr(pXMLData->ScreenID.Ptr,Buffer,MAX_STRING) && !_stricmp(Buffer,Name)) {
            return pWnd;
        }
    }

    if (pWnd->pFirstChildWnd) {
        tmp = RecurseAndFindName((class CXWnd *)pWnd->pFirstChildWnd, Name);
        if (tmp)
            return tmp;
    }
    return RecurseAndFindName((class CXWnd *)pWnd->pNextSiblingWnd, Name);
}

class CXWnd * CXWnd::GetChildItem(PCHAR Name)
{
    //return GetChildItem(CXStr(Name));
    return RecurseAndFindName(this, Name);
}

class CXWnd * CSidlScreenWnd::GetChildItem(PCHAR Name)
{
    return RecurseAndFindName((class CXWnd *)this, Name);
}

class CScreenPieceTemplate *  CSidlManager::FindScreenPieceTemplate(char *str)
{
    return FindScreenPieceTemplate(&CXStr(str));
}
void  CComboWnd::InsertChoice(char *str)
{
    InsertChoice(&CXStr(str),0);
}

int  CListWnd::AddString(char *p1, unsigned long p2, unsigned __int32 p3, CTextureAnimation *p4, const char* p5)
{
    return AddString(&CXStr(p1), p2, p3, p4);
}

void CEditBaseWnd::SetMaxChars(int maxChars)
{
    this->MaxChars = maxChars;
    int len = 0;

    if(this->InputText)
    {
        len = this->InputText->Length;
		if(len > maxChars)
		{
			((CXWnd*)this)->SetWindowTextA(CXStr(this->InputText->Text));
		}
	}
}

CXPoint CXRect::CenterPoint()const
{
    CXPoint p;

    p.X = this->left + ((this->right - this->left) / 2);
    p.Y = this->top + ((this->bottom - this->top) / 2); // (bottom - top / 2) + top

    return p;
}
#pragma warning( push )
#pragma warning( disable:4740 ) // warning C4740: flow in or out of inline asm code suppresses global optimization
// MANUAL IMPORTS
#ifdef CMyInventory__GetSlot_x
FUNCTION_AT_ADDRESS(struct  _CONTENTS* CMyInventory::GetSlot(int), CMyInventory__GetSlot);
#endif

#ifdef EQ_Item__CreateItemTagString_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(char * EQ_Item::CreateItemTagString(char *, int, bool), EQ_Item__CreateItemTagString); // SwiftyMUSE 11-09-2018
#else
FUNCTION_AT_ADDRESS(char * EQ_Item::CreateItemTagString(char *, int), EQ_Item__CreateItemTagString); // Lax 11-14-2003
#endif
#endif
#ifdef EQ_Item__GetImageNum_x
FUNCTION_AT_ADDRESS(int EQ_Item::GetImageNum(void)const,EQ_Item__GetImageNum); // Eqmule 02-07-2014
#endif
#ifdef EQ_Item__CreateItemClient_x
FUNCTION_AT_ADDRESS(_CONTENTS** __cdecl EQ_Item::CreateItemClient(PBYTE*,DWORD),EQ_Item__CreateItemClient); // Eqmule 08-27-2015
#endif
#ifdef CStmlWnd__AppendSTML_x
FUNCTION_AT_ADDRESS(CXSize CStmlWnd::AppendSTML(CXStr),CStmlWnd__AppendSTML);
#endif
#ifdef EQ_Item__CanDrop_x
FUNCTION_AT_ADDRESS(bool EQ_Item::CanDrop(bool,bool,bool,bool) const,EQ_Item__CanDrop);
#endif
///////////////////////////////////////////////////////////////////
#ifdef EQ_Character__Max_Endurance_x
FUNCTION_AT_ADDRESS(int  EQ_Character1::Max_Endurance(bool),EQ_Character__Max_Endurance);
#endif
#ifdef EQ_Character__Max_Mana_x
FUNCTION_AT_ADDRESS(int EQ_Character1::Max_Mana(bool), EQ_Character__Max_Mana);
#endif 
#ifdef EQ_Character__Max_HP_x
FUNCTION_AT_ADDRESS(int  EQ_Character1::Max_HP(int,bool),EQ_Character__Max_HP);
#endif
/////////////////////////////////////////////////////////////////////

#ifdef EQ_Character__doCombatAbility_x
FUNCTION_AT_ADDRESS(bool EQ_Character::DoCombatAbility(int spellID, int dummy), EQ_Character__doCombatAbility); 
#endif 
FUNCTION_AT_VIRTUAL_ADDRESS(float ActorBase::GetBoundingRadius(), 0x60);

FUNCTION_AT_VIRTUAL_ADDRESS(bool CXWnd::IsValid(void)const,0);
FUNCTION_AT_VIRTUAL_ADDRESS(void CChatWindow::operator delete[](void*),0x4);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleLButtonDown(class CXPoint *,unsigned __int32),0x38);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleLButtonUp(class CXPoint *,unsigned __int32),0x3c);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleLButtonHeld(class CXPoint *,unsigned __int32),0x40);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleLButtonUpAfterHeld(class CXPoint *,unsigned __int32),0x44);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleRButtonDown(class CXPoint *,unsigned __int32),0x48);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleRButtonUp(class CXPoint *,unsigned __int32),0x4c);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleRButtonHeld(class CXPoint *,unsigned __int32),0x50);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleRButtonUpAfterHeld(class CXPoint *,unsigned __int32),0x54);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::WndNotification(class CXWnd *,unsigned __int32,void *),0x88);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::OnResize(int,int),0x0a0);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::OnMinimizeBox(void),0xac);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::Show(bool, bool, bool),0x0d8);
#if defined(ROF2EMU) || defined(UFEMU)
FUNCTION_AT_VIRTUAL_ADDRESS(class CXRect CXWnd::GetClientRect(void)const,0xf8);
FUNCTION_AT_VIRTUAL_ADDRESS(void CXWnd::SetWindowTextA(class CXStr &),0x124);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::SetVScrollPos(int),0x134);
FUNCTION_AT_VIRTUAL_ADDRESS(void CListWnd::DeleteAll(void),0x17c);//see CComboWnd__DeleteAll_x
FUNCTION_AT_VIRTUAL_ADDRESS(void CListWnd::Sort(void),0x184);
FUNCTION_AT_VIRTUAL_ADDRESS(UINT CButtonWnd::GetCoolDownTotalDuration() const,0x18c);
FUNCTION_AT_VIRTUAL_ADDRESS(UINT CButtonWnd::GetCoolDownTimeRemaining() const,0x190);
#else
FUNCTION_AT_VIRTUAL_ADDRESS(class CXRect CXWnd::GetClientRect(void)const,0xfc);
FUNCTION_AT_VIRTUAL_ADDRESS(void CXWnd::SetWindowTextA(class CXStr &),0x128);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::SetVScrollPos(int),0x138);//don't ever doubt this one, double check CXWnd__CXWnd vftable and count
FUNCTION_AT_VIRTUAL_ADDRESS(void CListWnd::DeleteAll(void),0x180);//see CComboWnd__DeleteAll_x
FUNCTION_AT_VIRTUAL_ADDRESS(void CListWnd::Sort(void),0x188);
FUNCTION_AT_VIRTUAL_ADDRESS(UINT CButtonWnd::GetCoolDownTotalDuration() const,0x190);
FUNCTION_AT_VIRTUAL_ADDRESS(UINT CButtonWnd::GetCoolDownTimeRemaining() const,0x194);
#endif

//ClientSpellManager
FUNCTION_AT_VIRTUAL_ADDRESS(int ClientSpellManager::dSpellManager(void *, bool), 0x00);
FUNCTION_AT_VIRTUAL_ADDRESS(bool ClientSpellManager::LoadSpells(char const*, char const*, char const*), 0x04);
FUNCTION_AT_VIRTUAL_ADDRESS(bool ClientSpellManager::LoadSpellStackingData(const char *), 0x08);
#if defined(ROF2EMU) || defined(UFEMU)
FUNCTION_AT_VIRTUAL_ADDRESS( void ClientSpellManager::PrintFailedRequirementString(int, int), 0x0c);
FUNCTION_AT_VIRTUAL_ADDRESS( int ClientSpellManager::GetSpellStackingGroupID(int), 0x10);
FUNCTION_AT_VIRTUAL_ADDRESS( int ClientSpellManager::GetSpellStackingGroupRank(int), 0x14);
FUNCTION_AT_VIRTUAL_ADDRESS( ESpellStackingRules ClientSpellManager::GetSpellStackingGroupRule(int), 0x18);
FUNCTION_AT_VIRTUAL_ADDRESS( PSPELL ClientSpellManager::GetSpellByID(int), 0x1c);
FUNCTION_AT_VIRTUAL_ADDRESS( struct _SPELLCALCINFO* ClientSpellManager::GetSpellAffect(int), 0x20);
FUNCTION_AT_VIRTUAL_ADDRESS( bool ClientSpellManager::GetSpellAffectEmpty(bool), 0x24);
#else
FUNCTION_AT_VIRTUAL_ADDRESS( bool ClientSpellManager::DoesMeetRequirement(PlayerZoneClient *,int), 0x0c);
FUNCTION_AT_VIRTUAL_ADDRESS( void ClientSpellManager::PrintFailedRequirementString(int, int), 0x10);
FUNCTION_AT_VIRTUAL_ADDRESS( int ClientSpellManager::GetSpellStackingGroupID(int), 0x14);
FUNCTION_AT_VIRTUAL_ADDRESS( int ClientSpellManager::GetSpellStackingGroupRank(int), 0x18);
FUNCTION_AT_VIRTUAL_ADDRESS( ESpellStackingRules ClientSpellManager::GetSpellStackingGroupRule(int), 0x1c);
FUNCTION_AT_VIRTUAL_ADDRESS( PSPELL ClientSpellManager::GetSpellByID(int), 0x20);
FUNCTION_AT_VIRTUAL_ADDRESS( struct _SPELLCALCINFO* ClientSpellManager::GetSpellAffect(int), 0x24);
FUNCTION_AT_VIRTUAL_ADDRESS( bool ClientSpellManager::GetSpellAffectEmpty(bool), 0x28);
#endif

// AUTO IMPORTS

#ifdef CAAWnd__CAAWnd_x
FUNCTION_AT_ADDRESS( CAAWnd::CAAWnd(class CXWnd *),CAAWnd__CAAWnd);
#endif
#ifdef CAAWnd__Update_x
FUNCTION_AT_ADDRESS(void  CAAWnd::Update(void),CAAWnd__Update);
#endif
#ifdef CAAWnd__UpdateSelected_x
FUNCTION_AT_ADDRESS(void  CAAWnd::UpdateSelected(void),CAAWnd__UpdateSelected);
#endif
#ifdef CAAWnd__UpdateTimer_x
FUNCTION_AT_ADDRESS(void  CAAWnd::UpdateTimer(void),CAAWnd__UpdateTimer);
#endif
#ifdef CAAWnd__Init_x
FUNCTION_AT_ADDRESS(void  CAAWnd::Init(void),CAAWnd__Init);
#endif
#ifdef CAAWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CAAWnd::Activate(void),CAAWnd__Activate);
#endif
#ifdef CAAWnd__ShowAbility_x
FUNCTION_AT_ADDRESS(void  CAAWnd::ShowAbility(int),CAAWnd__ShowAbility);
#endif
#ifdef CAAWnd__SendNewPercent_x
FUNCTION_AT_ADDRESS(void  CAAWnd::SendNewPercent(void),CAAWnd__SendNewPercent);
#endif
#ifdef CAAWnd__ConfirmAASpend_x
FUNCTION_AT_ADDRESS(void  CAAWnd::ConfirmAASpend(void),CAAWnd__ConfirmAASpend);
#endif
#ifdef CXStr__CXStr_x
FUNCTION_AT_ADDRESS( CXStr::CXStr(class CXStr const &),CXStr__CXStr);
#endif
#ifdef CXMLSOMCursor__dCXMLSOMCursor_x
FUNCTION_AT_ADDRESS( CXMLSOMCursor::~CXMLSOMCursor(void),CXMLSOMCursor__dCXMLSOMCursor);
#endif
#ifdef CKeyCXStrValueInt32__dCKeyCXStrValueInt32_x
FUNCTION_AT_ADDRESS( CKeyCXStrValueInt32::~CKeyCXStrValueInt32(void),CKeyCXStrValueInt32__dCKeyCXStrValueInt32);
#endif
#ifdef COptionsWnd__KeyboardAssignmentData__dKeyboardAssignmentData_x
//FUNCTION_AT_ADDRESS( COptionsWnd::KeyboardAssignmentData::~KeyboardAssignmentData(void),COptionsWnd__KeyboardAssignmentData__dKeyboardAssignmentData);
#endif
#ifdef CXStr__dCXStr_x
FUNCTION_AT_ADDRESS(CXStr::~CXStr(),CXStr__dCXStr);
#endif
#ifdef CUITextureInfo__CUITextureInfo_x
FUNCTION_AT_ADDRESS( CUITextureInfo::CUITextureInfo(class CXStr,int),CUITextureInfo__CUITextureInfo);
#endif
#ifdef CXMLSOMNodePtr__dCXMLSOMNodePtr_x
FUNCTION_AT_ADDRESS( CXMLSOMNodePtr::~CXMLSOMNodePtr(void),CXMLSOMNodePtr__dCXMLSOMNodePtr);
#endif
#ifdef CXMLSOMNode__dCXMLSOMNode_x
FUNCTION_AT_ADDRESS( CXMLSOMNode::~CXMLSOMNode(void),CXMLSOMNode__dCXMLSOMNode);
#endif
#ifdef CXMLSOMAttribute__dCXMLSOMAttribute_x
FUNCTION_AT_ADDRESS( CXMLSOMAttribute::~CXMLSOMAttribute(void),CXMLSOMAttribute__dCXMLSOMAttribute);
#endif
#ifdef CActionsWnd__CActionsWnd_x
FUNCTION_AT_ADDRESS( CActionsWnd::CActionsWnd(class CXWnd *),CActionsWnd__CActionsWnd);
#endif
#ifdef CActionsWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CActionsWnd::Activate(int),CActionsWnd__Activate);
#endif
#ifdef CActionsWnd__UpdateButtonText_x
FUNCTION_AT_ADDRESS(void  CActionsWnd::UpdateButtonText(void),CActionsWnd__UpdateButtonText);
#endif
#ifdef CActionsWnd__GetCurrentPageEnum_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::GetCurrentPageEnum(void)const ,CActionsWnd__GetCurrentPageEnum);
#endif
#ifdef CActionsWnd__KeyMapUpdated_x
FUNCTION_AT_ADDRESS(void  CActionsWnd::KeyMapUpdated(void),CActionsWnd__KeyMapUpdated);
#endif
#ifdef CActionsWnd__SelectSkillForAbilityBtn_x
FUNCTION_AT_ADDRESS(void  CActionsWnd::SelectSkillForAbilityBtn(int),CActionsWnd__SelectSkillForAbilityBtn);
#endif
#ifdef CActionsWnd__GetAbilityBtn_x
FUNCTION_AT_ADDRESS(class CButtonWnd *  CActionsWnd::GetAbilityBtn(int),CActionsWnd__GetAbilityBtn);
#endif
#ifdef CActionsWnd__SelectSkillForCombatBtn_x
FUNCTION_AT_ADDRESS(void  CActionsWnd::SelectSkillForCombatBtn(int),CActionsWnd__SelectSkillForCombatBtn);
#endif
#ifdef CActionsWnd__GetCombatBtn_x
FUNCTION_AT_ADDRESS(class CButtonWnd *  CActionsWnd::GetCombatBtn(int),CActionsWnd__GetCombatBtn);
#endif
#ifdef CActionsWnd__GetMenuBtn_x
FUNCTION_AT_ADDRESS(class CButtonWnd *  CActionsWnd::GetMenuBtn(int),CActionsWnd__GetMenuBtn);
#endif
#ifdef CActionsWnd__RedirectActivateTo_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::RedirectActivateTo(class CPageWnd *),CActionsWnd__RedirectActivateTo);
#endif
#ifdef CActionsWnd__RedirectDeactivateTo_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::RedirectDeactivateTo(class CPageWnd *),CActionsWnd__RedirectDeactivateTo);
#endif
#ifdef CActionsWnd__RedirectOnProcessFrameTo_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::RedirectOnProcessFrameTo(class CPageWnd *),CActionsWnd__RedirectOnProcessFrameTo);
#endif
#ifdef CActionsWnd__RedirectWndNotificationTo_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::RedirectWndNotificationTo(class CPageWnd *,class CXWnd *,unsigned __int32,void *),CActionsWnd__RedirectWndNotificationTo);
#endif
#ifdef CActionsWnd__MainPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::MainPageOnProcessFrame(void),CActionsWnd__MainPageOnProcessFrame);
#endif
#ifdef CActionsWnd__MainPageWndNotification_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::MainPageWndNotification(class CXWnd *,unsigned __int32,void *),CActionsWnd__MainPageWndNotification);
#endif
#ifdef CActionsWnd__AbilitiesPageActivate_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::AbilitiesPageActivate(void),CActionsWnd__AbilitiesPageActivate);
#endif
#ifdef CActionsWnd__AbilitiesPageDeactivate_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::AbilitiesPageDeactivate(void),CActionsWnd__AbilitiesPageDeactivate);
#endif
#ifdef CActionsWnd__AbilitiesPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::AbilitiesPageOnProcessFrame(void),CActionsWnd__AbilitiesPageOnProcessFrame);
#endif
#ifdef CActionsWnd__AbilitiesPageWndNotification_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::AbilitiesPageWndNotification(class CXWnd *,unsigned __int32,void *),CActionsWnd__AbilitiesPageWndNotification);
#endif
#ifdef CActionsWnd__CombatPageActivate_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::CombatPageActivate(void),CActionsWnd__CombatPageActivate);
#endif
#ifdef CActionsWnd__CombatPageDeactivate_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::CombatPageDeactivate(void),CActionsWnd__CombatPageDeactivate);
#endif
#ifdef CActionsWnd__CombatPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::CombatPageOnProcessFrame(void),CActionsWnd__CombatPageOnProcessFrame);
#endif
#ifdef CActionsWnd__CombatPageWndNotification_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::CombatPageWndNotification(class CXWnd *,unsigned __int32,void *),CActionsWnd__CombatPageWndNotification);
#endif
#ifdef CActionsWnd__SocialsPageActivate_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::SocialsPageActivate(void),CActionsWnd__SocialsPageActivate);
#endif
#ifdef CActionsWnd__SocialsPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::SocialsPageOnProcessFrame(void),CActionsWnd__SocialsPageOnProcessFrame);
#endif
#ifdef CActionsWnd__SocialsPageWndNotification_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::SocialsPageWndNotification(class CXWnd *,unsigned __int32,void *),CActionsWnd__SocialsPageWndNotification);
#endif
#ifdef CAlarmWnd__CAlarmWnd_x
FUNCTION_AT_ADDRESS( CAlarmWnd::CAlarmWnd(class CXWnd *),CAlarmWnd__CAlarmWnd);
#endif
#ifdef CAlarmWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CAlarmWnd::Activate(void),CAlarmWnd__Activate);
#endif
#ifdef CAlarmWnd__DoNeverButton_x
FUNCTION_AT_ADDRESS(void  CAlarmWnd::DoNeverButton(void),CAlarmWnd__DoNeverButton);
#endif
#ifdef CEditBaseWnd__SetMaxChars_x
FUNCTION_AT_ADDRESS(void  CEditBaseWnd::SetMaxChars(int),CEditBaseWnd__SetMaxChars);
#endif
#ifdef CBankWnd__CBankWnd_x
FUNCTION_AT_ADDRESS( CBankWnd::CBankWnd(class CXWnd *,class CXStr),CBankWnd__CBankWnd);
#endif
#ifdef CBankWnd__Init_x
FUNCTION_AT_ADDRESS(void  CBankWnd::Init(void),CBankWnd__Init);
#endif
#ifdef CBankWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CBankWnd::Activate(class EQPlayer *),CBankWnd__Activate);
#endif
#ifdef CBankWnd__Deactivate_x
FUNCTION_AT_ADDRESS(void  CBankWnd::Deactivate(bool),CBankWnd__Deactivate);
#endif
#ifdef CBankWnd__ClickedMoneyButton_x
FUNCTION_AT_ADDRESS(void  CBankWnd::ClickedMoneyButton(int,int),CBankWnd__ClickedMoneyButton);
#endif
#ifdef CBankWnd__GetBankQtyFromCoinType_x
FUNCTION_AT_ADDRESS(long  CBankWnd::GetBankQtyFromCoinType(int),CBankWnd__GetBankQtyFromCoinType);
#endif
#ifdef CBankWnd__UpdateMoneyDisplay_x
FUNCTION_AT_ADDRESS(void  CBankWnd::UpdateMoneyDisplay(void),CBankWnd__UpdateMoneyDisplay);
#endif
#ifdef CBankWnd__GetNumBankSlots_x
FUNCTION_AT_ADDRESS(int  CBankWnd::GetNumBankSlots(void)const ,CBankWnd__GetNumBankSlots);
#endif
#ifdef CXRect__CenterPoint_x
FUNCTION_AT_ADDRESS(class CXPoint  CXRect::CenterPoint(void)const ,CXRect__CenterPoint);
#endif
#ifdef CBazaarSearchWnd__CBazaarSearchWnd_x
FUNCTION_AT_ADDRESS( CBazaarSearchWnd::CBazaarSearchWnd(class CXWnd *),CBazaarSearchWnd__CBazaarSearchWnd);
#endif
#ifdef CBazaarSearchWnd__InitListArray_x
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::InitListArray(void),CBazaarSearchWnd__InitListArray);
#endif
#ifdef CBazaarSearchWnd__Init_x
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::Init(void),CBazaarSearchWnd__Init);
#endif
#ifdef CBazaarSearchWnd__UpdatePlayerUpdateButton_x
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::UpdatePlayerUpdateButton(bool),CBazaarSearchWnd__UpdatePlayerUpdateButton);
#endif
#ifdef CBazaarSearchWnd__UpdatePlayerCombo_x
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::UpdatePlayerCombo(void),CBazaarSearchWnd__UpdatePlayerCombo);
#endif
#ifdef CBazaarSearchWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::Activate(void),CBazaarSearchWnd__Activate);
#endif
#ifdef CBazaarSearchWnd__GetPriceString_x
FUNCTION_AT_ADDRESS(char *  CBazaarSearchWnd::GetPriceString(unsigned long),CBazaarSearchWnd__GetPriceString);
#endif
#ifdef CBazaarSearchWnd__SortItemList_x
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::SortItemList(int),CBazaarSearchWnd__SortItemList);
#endif
#ifdef CBazaarSearchWnd__AddItemtoList_x
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::AddItemtoList(char *,unsigned long,char *,int,int),CBazaarSearchWnd__AddItemtoList);
#endif
#ifdef CBazaarSearchWnd__UpdateComboButtons_x
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::UpdateComboButtons(void),CBazaarSearchWnd__UpdateComboButtons);
#endif
#ifdef CBazaarSearchWnd__HandleBazaarMsg_x
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::HandleBazaarMsg(char *,int),CBazaarSearchWnd__HandleBazaarMsg);
#endif
#ifdef CBazaarSearchWnd__doQuery_x
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::doQuery(void),CBazaarSearchWnd__doQuery);
#endif
#ifdef CBazaarWnd__CBazaarWnd_x
FUNCTION_AT_ADDRESS( CBazaarWnd::CBazaarWnd(class CXWnd *),CBazaarWnd__CBazaarWnd);
#endif
#ifdef CBazaarWnd__Init_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::Init(void),CBazaarWnd__Init);
#endif
#ifdef CBazaarWnd__CreateBZRIniFilename_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::CreateBZRIniFilename(void),CBazaarWnd__CreateBZRIniFilename);
#endif
#ifdef CBazaarWnd__AddBazaarText_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::AddBazaarText(char *,int),CBazaarWnd__AddBazaarText);
#endif
#ifdef CBazaarWnd__ReturnItemByIndex_x
FUNCTION_AT_ADDRESS(class EQ_Item *  CBazaarWnd::ReturnItemByIndex(int),CBazaarWnd__ReturnItemByIndex);
#endif
#ifdef CBazaarWnd__GetPriceString_x
FUNCTION_AT_ADDRESS(char *  CBazaarWnd::GetPriceString(unsigned long),CBazaarWnd__GetPriceString);
#endif
#ifdef CBazaarWnd__HandleTraderMsg_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::HandleTraderMsg(char *),CBazaarWnd__HandleTraderMsg);
#endif
#ifdef CBazaarWnd__RebuildItemArray_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::RebuildItemArray(void),CBazaarWnd__RebuildItemArray);
#endif
#ifdef CBazaarWnd__BuildBazaarItemArray_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::BuildBazaarItemArray(void),CBazaarWnd__BuildBazaarItemArray);
#endif
#ifdef CBazaarWnd__AddEquipmentToBazaarArray_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::AddEquipmentToBazaarArray(class EQ_Item *,int,unsigned long),CBazaarWnd__AddEquipmentToBazaarArray);
#endif
#ifdef CBazaarWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::Activate(void),CBazaarWnd__Activate);
#endif
#ifdef CBazaarWnd__UpdatePriceButtons_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::UpdatePriceButtons(void),CBazaarWnd__UpdatePriceButtons);
#endif
#ifdef CBazaarWnd__StoreSelectedPrice_x
FUNCTION_AT_ADDRESS(bool  CBazaarWnd::StoreSelectedPrice(void),CBazaarWnd__StoreSelectedPrice);
#endif
#ifdef CBazaarWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::UpdateButtons(void),CBazaarWnd__UpdateButtons);
#endif
#ifdef CBazaarWnd__SelectBazaarSlotItem_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::SelectBazaarSlotItem(int,class CTextureAnimation *),CBazaarWnd__SelectBazaarSlotItem);
#endif
#ifdef CBazaarWnd__SetMoneyButton_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::SetMoneyButton(int,int),CBazaarWnd__SetMoneyButton);
#endif
#ifdef CBazaarWnd__GetQtyFromCoinType_x
FUNCTION_AT_ADDRESS(long  CBazaarWnd::GetQtyFromCoinType(int),CBazaarWnd__GetQtyFromCoinType);
#endif
#ifdef CBazaarWnd__ClickedMoneyButton_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::ClickedMoneyButton(int,int),CBazaarWnd__ClickedMoneyButton);
#endif
#ifdef CBazaarWnd__GetPrice_x
FUNCTION_AT_ADDRESS(unsigned long  CBazaarWnd::GetPrice(void),CBazaarWnd__GetPrice);
#endif
#ifdef CBazaarWnd__UpdateBazaarListtoServer_x
FUNCTION_AT_ADDRESS(int  CBazaarWnd::UpdateBazaarListtoServer(void),CBazaarWnd__UpdateBazaarListtoServer);
#endif
#ifdef CBazaarWnd__ToggleBzrItemActive_x
FUNCTION_AT_ADDRESS(void  CBazaarWnd::ToggleBzrItemActive(int,bool),CBazaarWnd__ToggleBzrItemActive);
#endif
#ifdef CXWnd__GetWindowTextA_x
FUNCTION_AT_ADDRESS(class CXStr  CXWnd::GetWindowTextA(void)const ,CXWnd__GetWindowTextA);
#endif
#ifdef CBodyTintWnd__CBodyTintWnd_x
FUNCTION_AT_ADDRESS( CBodyTintWnd::CBodyTintWnd(class CXWnd *),CBodyTintWnd__CBodyTintWnd);
#endif
#ifdef CBodyTintWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::Activate(void),CBodyTintWnd__Activate);
#endif
#ifdef CBodyTintWnd__GetTintChangeCount_x
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::GetTintChangeCount(void),CBodyTintWnd__GetTintChangeCount);
#endif
#ifdef CBodyTintWnd__GetReagentCount_x
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::GetReagentCount(void),CBodyTintWnd__GetReagentCount);
#endif
#ifdef CBodyTintWnd__BuildRBGTooltip_x
FUNCTION_AT_ADDRESS(char *  CBodyTintWnd::BuildRBGTooltip(unsigned long,char * const),CBodyTintWnd__BuildRBGTooltip);
#endif
#ifdef CBodyTintWnd__GetItemTint_x
FUNCTION_AT_ADDRESS(unsigned long  CBodyTintWnd::GetItemTint(int),CBodyTintWnd__GetItemTint);
#endif
#ifdef CBodyTintWnd__SetSlotLabels_x
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::SetSlotLabels(bool),CBodyTintWnd__SetSlotLabels);
#endif
#ifdef CBodyTintWnd__UpdateLocalTintColor_x
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::UpdateLocalTintColor(unsigned long),CBodyTintWnd__UpdateLocalTintColor);
#endif
#ifdef CBodyTintWnd__UpdateMaterialTintLocal_x
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::UpdateMaterialTintLocal(unsigned long),CBodyTintWnd__UpdateMaterialTintLocal);
#endif
#ifdef CBodyTintWnd__UpdateLabelsAndButtons_x
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::UpdateLabelsAndButtons(void),CBodyTintWnd__UpdateLabelsAndButtons);
#endif
#ifdef CBodyTintWnd__GetButtonTint_x
FUNCTION_AT_ADDRESS(unsigned long  CBodyTintWnd::GetButtonTint(int),CBodyTintWnd__GetButtonTint);
#endif
#ifdef CBodyTintWnd__StoreModifiedBodyTints_x
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::StoreModifiedBodyTints(void),CBodyTintWnd__StoreModifiedBodyTints);
#endif
#ifdef CBodyTintWnd__ResetToOrigBodyTints_x
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::ResetToOrigBodyTints(void),CBodyTintWnd__ResetToOrigBodyTints);
#endif
#ifdef CXWnd__SetTooltip_x
FUNCTION_AT_ADDRESS(void  CXWnd::SetTooltip(class CXStr),CXWnd__SetTooltip);
#endif
#ifdef CBookWnd__CBookWnd_x
FUNCTION_AT_ADDRESS( CBookWnd::CBookWnd(class CXWnd *),CBookWnd__CBookWnd);
#endif
#ifdef CBookWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CBookWnd::Activate(void),CBookWnd__Activate);
#endif
#ifdef CBookWnd__SetBook_x
FUNCTION_AT_ADDRESS(void  CBookWnd::SetBook(char *),CBookWnd__SetBook);
#endif
#ifdef CBookWnd__CheckBook_x
FUNCTION_AT_ADDRESS(bool  CBookWnd::CheckBook(class EQ_Note *),CBookWnd__CheckBook);
#endif
#ifdef CBookWnd__DisplayText_x
FUNCTION_AT_ADDRESS(void  CBookWnd::DisplayText(void),CBookWnd__DisplayText);
#endif
#ifdef CBookWnd__CleanPages_x
FUNCTION_AT_ADDRESS(void  CBookWnd::CleanPages(void),CBookWnd__CleanPages);
#endif
#ifdef CBookWnd__ProcessText_x
FUNCTION_AT_ADDRESS(void  CBookWnd::ProcessText(void),CBookWnd__ProcessText);
#endif
#ifdef CBookWnd__ShowButtons_x
FUNCTION_AT_ADDRESS(void  CBookWnd::ShowButtons(void),CBookWnd__ShowButtons);
#endif
#ifdef COptionsWnd__KeyboardAssignmentData__KeyboardAssignmentData_x
//FUNCTION_AT_ADDRESS( COptionsWnd::KeyboardAssignmentData::KeyboardAssignmentData(void),COptionsWnd__KeyboardAssignmentData__KeyboardAssignmentData);
#endif
#ifdef CXStr__CXStr1_x
FUNCTION_AT_ADDRESS( CXStr::CXStr(void),CXStr__CXStr1);
#endif
#ifdef CBreathWnd__CBreathWnd_x
FUNCTION_AT_ADDRESS( CBreathWnd::CBreathWnd(class CXWnd *),CBreathWnd__CBreathWnd);
#endif
#ifdef CBreathWnd__Init_x
FUNCTION_AT_ADDRESS(void  CBreathWnd::Init(void),CBreathWnd__Init);
#endif
#ifdef CBreathWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CBreathWnd::Activate(void),CBreathWnd__Activate);
#endif
#ifdef CBuffWindow__CBuffWindow_x
//FUNCTION_AT_ADDRESS( CBuffWindow::CBuffWindow(class CXWnd *,enum BuffWindowType),CBuffWindow__CBuffWindow);
#endif
#ifdef CTextureAnimation__operator_equal_x
FUNCTION_AT_ADDRESS(class CTextureAnimation &  CTextureAnimation::operator=(class CTextureAnimation const &),CTextureAnimation__operator_equal);
#endif
#ifdef CBuffWindow__Init_x
FUNCTION_AT_ADDRESS(void  CBuffWindow::Init(void),CBuffWindow__Init);
#endif
#ifdef CBuffWindow__Activate_x
FUNCTION_AT_ADDRESS(void  CBuffWindow::Activate(void),CBuffWindow__Activate);
#endif
#ifdef CBuffWindow__HandleSpellInfoDisplay_x
FUNCTION_AT_ADDRESS(void  CBuffWindow::HandleSpellInfoDisplay(class CXWnd *),CBuffWindow__HandleSpellInfoDisplay);
#endif
#ifdef CBuffWindow__RefreshIconArrangement_x
FUNCTION_AT_ADDRESS(void  CBuffWindow::RefreshIconArrangement(void),CBuffWindow__RefreshIconArrangement);
#endif
#ifdef CBuffWindow__RefreshBuffDisplay_x
FUNCTION_AT_ADDRESS(void  CBuffWindow::RefreshBuffDisplay(void),CBuffWindow__RefreshBuffDisplay);
#endif
#ifdef CBuffWindow__SetBuffIcon_x
FUNCTION_AT_ADDRESS(void  CBuffWindow::SetBuffIcon(class CButtonWnd *,int,int),CBuffWindow__SetBuffIcon);
#endif
#ifdef CXRect__Move_x
FUNCTION_AT_ADDRESS(void  CXRect::Move(class CXPoint),CXRect__Move);
#endif
#ifdef CTreeView__CTreeView_x
FUNCTION_AT_ADDRESS(void CTreeView::GetFrameSize(class CXWnd *,unsigned __int32,class CXRect,int) ,CTreeView__CTreeView);
#endif
#ifdef CTreeView__dTreeView_x
FUNCTION_AT_ADDRESS(void CTreeView:~CTreeView(void) ,CTreeView__dTreeView);
#endif
#ifdef CTAFrameDraw__GetFrameSize_x
FUNCTION_AT_ADDRESS(class CXSize  CTAFrameDraw::GetFrameSize(void)const ,CTAFrameDraw__GetFrameSize);
#endif
#ifdef STextureAnimationFrame__STextureAnimationFrame_x
FUNCTION_AT_ADDRESS( STextureAnimationFrame::STextureAnimationFrame(void),STextureAnimationFrame__STextureAnimationFrame);
#endif
#ifdef CUITexturePiece__CUITexturePiece_x
FUNCTION_AT_ADDRESS( CUITexturePiece::CUITexturePiece(void),CUITexturePiece__CUITexturePiece);
#endif
#ifdef STextureAnimationFrame__operator_equal_x
FUNCTION_AT_ADDRESS(STextureAnimationFrame &  STextureAnimationFrame::operator=(class STextureAnimationFrame const &),STextureAnimationFrame__operator_equal);
#endif
#ifdef CUITexturePiece__operator_equal_x
FUNCTION_AT_ADDRESS(class CUITexturePiece &  CUITexturePiece::operator=(class CUITexturePiece const &),CUITexturePiece__operator_equal);
#endif
#ifdef CBugReportWnd__CBugReportWnd_x
FUNCTION_AT_ADDRESS( CBugReportWnd::CBugReportWnd(class CXWnd *),CBugReportWnd__CBugReportWnd);
#endif
#ifdef CBugReportWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CBugReportWnd::Activate(void),CBugReportWnd__Activate);
#endif
#ifdef CBugReportWnd__UpdateLocation_x
FUNCTION_AT_ADDRESS(void  CBugReportWnd::UpdateLocation(void),CBugReportWnd__UpdateLocation);
#endif
#ifdef CCastingWnd__CCastingWnd_x
FUNCTION_AT_ADDRESS( CCastingWnd::CCastingWnd(class CXWnd *),CCastingWnd__CCastingWnd);
#endif
#ifdef CCastingWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CCastingWnd::Activate(void),CCastingWnd__Activate);
#endif
#ifdef CVideoModesWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CVideoModesWnd::Activate(void),CVideoModesWnd__Activate);
#endif
#ifdef CCastSpellWnd__CCastSpellWnd_x
FUNCTION_AT_ADDRESS( CCastSpellWnd::CCastSpellWnd(class CXWnd *),CCastSpellWnd__CCastSpellWnd);
#endif
#ifdef CCastSpellWnd__Init_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::Init(void),CCastSpellWnd__Init);
#endif
#ifdef CCastSpellWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::Activate(void),CCastSpellWnd__Activate);
#endif
#ifdef CCastSpellWnd__HandleSpellInfoDisplay_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::HandleSpellInfoDisplay(class CXWnd *),CCastSpellWnd__HandleSpellInfoDisplay);
#endif
#ifdef CCastSpellWnd__HandleSpellLeftClick_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::HandleSpellLeftClick(int),CCastSpellWnd__HandleSpellLeftClick);
#endif
#ifdef CCastSpellWnd__Unmemorize_x
FUNCTION_AT_ADDRESS(void __cdecl CCastSpellWnd::Unmemorize(int),CCastSpellWnd__Unmemorize);
#endif
#ifdef CCastSpellWnd__UnmemorizeList_x
FUNCTION_AT_ADDRESS(void __cdecl CCastSpellWnd::UnmemorizeList(int *,int),CCastSpellWnd__UnmemorizeList);
#endif
#ifdef CCastSpellWnd__HandleSpellRightClick_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::HandleSpellRightClick(int),CCastSpellWnd__HandleSpellRightClick);
#endif
#ifdef CCastSpellWnd__ForgetMemorizedSpell_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::ForgetMemorizedSpell(int),CCastSpellWnd__ForgetMemorizedSpell);
#endif
#ifdef CCastSpellWnd__IsBardSongPlaying_x
FUNCTION_AT_ADDRESS(bool  CCastSpellWnd::IsBardSongPlaying(void),CCastSpellWnd__IsBardSongPlaying);
#endif
#ifdef CCastSpellWnd__RefreshSpellGemButtons_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::RefreshSpellGemButtons(void),CCastSpellWnd__RefreshSpellGemButtons);
#endif
#ifdef CCastSpellWnd__UpdateSpellGems_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::UpdateSpellGems(int),CCastSpellWnd__UpdateSpellGems);
#endif
#ifdef CCastSpellWnd__UpdateSpellGemTooltips_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::UpdateSpellGemTooltips(int),CCastSpellWnd__UpdateSpellGemTooltips);
#endif
#ifdef CCastSpellWnd__GetSpellGemColor_x
FUNCTION_AT_ADDRESS(unsigned long  CCastSpellWnd::GetSpellGemColor(class EQ_Spell *),CCastSpellWnd__GetSpellGemColor);
#endif
#ifdef CCastSpellWnd__SpellBookDeactivating_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::SpellBookDeactivating(void),CCastSpellWnd__SpellBookDeactivating);
#endif
#ifdef CCastSpellWnd__KeyMapUpdated_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::KeyMapUpdated(void),CCastSpellWnd__KeyMapUpdated);
#endif
#ifdef CCastSpellWnd__ClearSpellCategories_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::ClearSpellCategories(void),CCastSpellWnd__ClearSpellCategories);
#endif
#ifdef CCastSpellWnd__SpellCategoryMajor__dSpellCategoryMajor_x
//FUNCTION_AT_ADDRESS( CCastSpellWnd::SpellCategoryMajor::~SpellCategoryMajor(void),CCastSpellWnd__SpellCategoryMajor__dSpellCategoryMajor);
#endif
#ifdef CCastSpellWnd__SpellCategoryMinor__dSpellCategoryMinor_x
//FUNCTION_AT_ADDRESS( CCastSpellWnd::SpellCategoryMinor::~SpellCategoryMinor(void),CCastSpellWnd__SpellCategoryMinor__dSpellCategoryMinor);
#endif
#ifdef CCastSpellWnd__RecacheCategorizedSpells_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::RecacheCategorizedSpells(void),CCastSpellWnd__RecacheCategorizedSpells);
#endif
#ifdef CCastSpellWnd__MakeSpellSelectMenu_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::MakeSpellSelectMenu(void),CCastSpellWnd__MakeSpellSelectMenu);
#endif
#ifdef CCastSpellWnd__CategorizeSpell_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::CategorizeSpell(int,int,int,int),CCastSpellWnd__CategorizeSpell);
#endif
#ifdef CCastSpellWnd__RecacheLoadoutContextMenu_x
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::RecacheLoadoutContextMenu(void),CCastSpellWnd__RecacheLoadoutContextMenu);
#endif
#ifdef CCharacterCreation__CCharacterCreation_x
FUNCTION_AT_ADDRESS( CCharacterCreation::CCharacterCreation(class CXWnd *),CCharacterCreation__CCharacterCreation);
#endif
#ifdef CCharacterCreation__Init_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::Init(void),CCharacterCreation__Init);
#endif
#ifdef CCharacterCreation__Activate_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::Activate(void),CCharacterCreation__Activate);
#endif
#ifdef CCharacterCreation__NameGenerated_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::NameGenerated(char *),CCharacterCreation__NameGenerated);
#endif
#ifdef CCharacterCreation__DoBackButton_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::DoBackButton(void),CCharacterCreation__DoBackButton);
#endif
#ifdef CCharacterCreation__DoNextButton_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::DoNextButton(void),CCharacterCreation__DoNextButton);
#endif
#ifdef CCharacterCreation__DoStatButton_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::DoStatButton(int),CCharacterCreation__DoStatButton);
#endif
#ifdef CCharacterCreation__ActivateScreen_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::ActivateScreen(int),CCharacterCreation__ActivateScreen);
#endif
#ifdef CCharacterCreation__RandomizeCharacter_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::RandomizeCharacter(bool,bool),CCharacterCreation__RandomizeCharacter);
#endif
#ifdef CCharacterCreation__RandomizeFacialFeatures_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::RandomizeFacialFeatures(void),CCharacterCreation__RandomizeFacialFeatures);
#endif
#ifdef CCharacterCreation__InitStats_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::InitStats(bool),CCharacterCreation__InitStats);
#endif
#ifdef CCharacterCreation__InitNewPC_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::InitNewPC(void),CCharacterCreation__InitNewPC);
#endif
#ifdef CCharacterCreation__InitStartingCities_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::InitStartingCities(void),CCharacterCreation__InitStartingCities);
#endif
#ifdef CCharacterCreation__SetNewPCDeityFromBtnIndex_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::SetNewPCDeityFromBtnIndex(int),CCharacterCreation__SetNewPCDeityFromBtnIndex);
#endif
#ifdef CCharacterCreation__UpdatePlayerFromNewPC_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::UpdatePlayerFromNewPC(void),CCharacterCreation__UpdatePlayerFromNewPC);
#endif
#ifdef CCharacterCreation__UpdateScreenZeroButtons_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::UpdateScreenZeroButtons(bool),CCharacterCreation__UpdateScreenZeroButtons);
#endif
#ifdef CCharacterCreation__GetRaceButtonIndex_x
FUNCTION_AT_ADDRESS(int  CCharacterCreation::GetRaceButtonIndex(int),CCharacterCreation__GetRaceButtonIndex);
#endif
#ifdef CCharacterCreation__GetClassButtonIndex_x
FUNCTION_AT_ADDRESS(int  CCharacterCreation::GetClassButtonIndex(int),CCharacterCreation__GetClassButtonIndex);
#endif
#ifdef CCharacterCreation__IsLackingExpansion_x
FUNCTION_AT_ADDRESS(bool  CCharacterCreation::IsLackingExpansion(bool,bool),CCharacterCreation__IsLackingExpansion);
#endif
#ifdef CCharacterCreation__SelectStartingCity_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::SelectStartingCity(int),CCharacterCreation__SelectStartingCity);
#endif
#ifdef CCharacterCreation__SelectedRaceButton_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::SelectedRaceButton(int),CCharacterCreation__SelectedRaceButton);
#endif
#ifdef CCharacterCreation__SelectedClassButton_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::SelectedClassButton(int),CCharacterCreation__SelectedClassButton);
#endif
#ifdef CCharacterCreation__SetPlayerAppearanceFromNewPC_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::SetPlayerAppearanceFromNewPC(class EQPlayer *,class EQ_PC *,bool),CCharacterCreation__SetPlayerAppearanceFromNewPC);
#endif
#ifdef CCharacterCreation__HandleNameApprovalResponse_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::HandleNameApprovalResponse(int),CCharacterCreation__HandleNameApprovalResponse);
#endif
#ifdef CCharacterCreation__SubmitNameToWorld_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::SubmitNameToWorld(void),CCharacterCreation__SubmitNameToWorld);
#endif
#ifdef CCharacterCreation__FinalizeNewPCAndSendToWorld_x
FUNCTION_AT_ADDRESS(void  CCharacterCreation::FinalizeNewPCAndSendToWorld(void),CCharacterCreation__FinalizeNewPCAndSendToWorld);
#endif
#ifdef CCharacterCreation__GetCharCreateText_x
FUNCTION_AT_ADDRESS(char *  CCharacterCreation::GetCharCreateText(char *,int,int,int,int),CCharacterCreation__GetCharCreateText);
#endif
#ifdef CCharacterListWnd__CCharacterListWnd_x
FUNCTION_AT_ADDRESS( CCharacterListWnd::CCharacterListWnd(class CXWnd *),CCharacterListWnd__CCharacterListWnd);
#endif
#ifdef CCharacterListWnd__Init_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::Init(void),CCharacterListWnd__Init);
#endif
#ifdef CCharacterListWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::Activate(void),CCharacterListWnd__Activate);
#endif
#ifdef CCharacterListWnd__EnableButtons_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::EnableButtons(bool),CCharacterListWnd__EnableButtons);
#endif
#ifdef CCharacterListWnd__EnableEqMovementCommands_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::EnableEqMovementCommands(bool),CCharacterListWnd__EnableEqMovementCommands);
#endif
#ifdef CCharacterListWnd__EnterWorld_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::EnterWorld(void),CCharacterListWnd__EnterWorld);
#endif
#ifdef CCharacterListWnd__Quit_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::Quit(void),CCharacterListWnd__Quit);
#endif
#ifdef CCharacterListWnd__UpdateList_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::UpdateList(bool),CCharacterListWnd__UpdateList);
#endif
#ifdef CCharacterListWnd__EnterExplorationMode_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::EnterExplorationMode(void),CCharacterListWnd__EnterExplorationMode);
#endif
#ifdef CCharacterListWnd__LeaveExplorationMode_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::LeaveExplorationMode(void),CCharacterListWnd__LeaveExplorationMode);
#endif
#ifdef CCharacterListWnd__IsValidCharacterSelected_x
FUNCTION_AT_ADDRESS(int  CCharacterListWnd::IsValidCharacterSelected(void),CCharacterListWnd__IsValidCharacterSelected);
#endif
#ifdef CCharacterListWnd__IsEmptyCharacterSlot_x
FUNCTION_AT_ADDRESS(int  CCharacterListWnd::IsEmptyCharacterSlot(int),CCharacterListWnd__IsEmptyCharacterSlot);
#endif
#ifdef CCharacterListWnd__NumberOfCharacters_x
FUNCTION_AT_ADDRESS(int  CCharacterListWnd::NumberOfCharacters(void),CCharacterListWnd__NumberOfCharacters);
#endif
#ifdef CCharacterListWnd__IsEvil_x
FUNCTION_AT_ADDRESS(unsigned char  CCharacterListWnd::IsEvil(int,int,int),CCharacterListWnd__IsEvil);
#endif
#ifdef CCharacterListWnd__SelectCharacter_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::SelectCharacter(int,bool,bool),CCharacterListWnd__SelectCharacter);
#endif
#ifdef CCharacterListWnd__SetLoadZonePlayerLocation_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::SetLoadZonePlayerLocation(void),CCharacterListWnd__SetLoadZonePlayerLocation);
#endif
#ifdef CCharacterListWnd__DeleteCharacter_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::DeleteCharacter(void),CCharacterListWnd__DeleteCharacter);
#endif
#ifdef CCharacterListWnd__UpdateButtonNames_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::UpdateButtonNames(void),CCharacterListWnd__UpdateButtonNames);
#endif
#ifdef CCharacterListWnd__SetLocationByClass_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::SetLocationByClass(class EQPlayer *,bool,int),CCharacterListWnd__SetLocationByClass);
#endif
#ifdef CCharacterListWnd__CreateExplorationModePlayers_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::CreateExplorationModePlayers(void),CCharacterListWnd__CreateExplorationModePlayers);
#endif
#ifdef CCharacterListWnd__RemoveExplorationModePlayers_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::RemoveExplorationModePlayers(void),CCharacterListWnd__RemoveExplorationModePlayers);
#endif
#ifdef CCharacterListWnd__SetRoomLocationByIndex_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::SetRoomLocationByIndex(int,class EQPlayer *),CCharacterListWnd__SetRoomLocationByIndex);
#endif
#ifdef CCharacterListWnd__SwitchModel_x
FUNCTION_AT_ADDRESS(void  CCharacterListWnd::SwitchModel(class EQPlayer *,unsigned char,int,unsigned char,unsigned char),CCharacterListWnd__SwitchModel);
#endif
#ifdef CChatManager__CChatManager_x
FUNCTION_AT_ADDRESS( CChatManager::CChatManager(void),CChatManager__CChatManager);
#endif
#ifdef CChatManager__dCChatManager_x
FUNCTION_AT_ADDRESS( CChatManager::~CChatManager(void),CChatManager__dCChatManager);
#endif
#ifdef CBookWnd__Init_x
FUNCTION_AT_ADDRESS(void  CBookWnd::Init(void),CBookWnd__Init);
#endif
#ifdef CColorPickerWnd__Init_x
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::Init(void),CColorPickerWnd__Init);
#endif
#ifdef CCompassWnd__Init_x
FUNCTION_AT_ADDRESS(void  CCompassWnd::Init(void),CCompassWnd__Init);
#endif
#ifdef CContainerWnd__Init_x
FUNCTION_AT_ADDRESS(void  CContainerWnd::Init(void),CContainerWnd__Init);
#endif
#ifdef CGiveWnd__Init_x
FUNCTION_AT_ADDRESS(void  CGiveWnd::Init(void),CGiveWnd__Init);
#endif
#ifdef CHelpWnd__Init_x
FUNCTION_AT_ADDRESS(void  CHelpWnd::Init(void),CHelpWnd__Init);
#endif
#ifdef CMusicPlayerWnd__Init_x
FUNCTION_AT_ADDRESS(void  CMusicPlayerWnd::Init(void),CMusicPlayerWnd__Init);
#endif
#ifdef CNoteWnd__Init_x
FUNCTION_AT_ADDRESS(void  CNoteWnd::Init(void),CNoteWnd__Init);
#endif
#ifdef CPetInfoWnd__Init_x
FUNCTION_AT_ADDRESS(void  CPetInfoWnd::Init(void),CPetInfoWnd__Init);
#endif
#ifdef CPlayerNotesWnd__Init_x
FUNCTION_AT_ADDRESS(void  CPlayerNotesWnd::Init(void),CPlayerNotesWnd__Init);
#endif
#ifdef CTargetWnd__Init_x
FUNCTION_AT_ADDRESS(void  CTargetWnd::Init(void),CTargetWnd__Init);
#endif
#ifdef CTargetWnd__RefreshTargetBuffs_x
FUNCTION_AT_ADDRESS(void  CTargetWnd::RefreshTargetBuffs(PBYTE),CTargetWnd__RefreshTargetBuffs);
#endif
#ifdef CTargetWnd__HandleBuffRemoveRequest_x
FUNCTION_AT_ADDRESS(void CTargetWnd::HandleBuffRemoveRequest(CXWnd*),CTargetWnd__HandleBuffRemoveRequest);
#endif
#ifdef UdpManager__ProcessIcmpErrors_x
FUNCTION_AT_ADDRESS(void  UdpManager::ProcessIcmpErrors(void),UdpManager__ProcessIcmpErrors);
#endif
#ifdef CRaid__dCRaid_x
FUNCTION_AT_ADDRESS( CRaid::~CRaid(void),CRaid__dCRaid);
#endif
#ifdef EQ_Note__dEQ_Note_x
FUNCTION_AT_ADDRESS( EQ_Note::~EQ_Note(void),EQ_Note__dEQ_Note);
#endif
#ifdef EQ_Skill__dEQ_Skill_x
FUNCTION_AT_ADDRESS( EQ_Skill::~EQ_Skill(void),EQ_Skill__dEQ_Skill);
#endif
#ifdef EQAnimation__dEQAnimation_x
FUNCTION_AT_ADDRESS( EQAnimation::~EQAnimation(void),EQAnimation__dEQAnimation);
#endif
#ifdef KeypressHandler__dKeypressHandler_x
FUNCTION_AT_ADDRESS( KeypressHandler::~KeypressHandler(void),KeypressHandler__dKeypressHandler);
#endif
#ifdef EQNewPlayerAnimation__InitAnimationData_x
FUNCTION_AT_ADDRESS(void __cdecl EQNewPlayerAnimation::InitAnimationData(void),EQNewPlayerAnimation__InitAnimationData);
#endif
#ifdef CAAWnd__CancelAASpend_x
FUNCTION_AT_ADDRESS(void  CAAWnd::CancelAASpend(void),CAAWnd__CancelAASpend);
#endif
#ifdef CChatManager__Process_x
FUNCTION_AT_ADDRESS(void  CChatManager::Process(void),CChatManager__Process);
#endif
#ifdef CDisplay__DefineSoloMode_x
FUNCTION_AT_ADDRESS(void  CDisplay::DefineSoloMode(void),CDisplay__DefineSoloMode);
#endif
#ifdef CEverQuest__InitCommands_x
FUNCTION_AT_ADDRESS(void  CEverQuest::InitCommands(void),CEverQuest__InitCommands);
#endif
#ifdef CInvSlotMgr__Process_x
FUNCTION_AT_ADDRESS(void  CInvSlotMgr::Process(void),CInvSlotMgr__Process);
#endif
#ifdef EQMissile__LeaveTrail_x
FUNCTION_AT_ADDRESS(void  EQMissile::LeaveTrail(void),EQMissile__LeaveTrail);
#endif
#ifdef CChatManager__Activate_x
FUNCTION_AT_ADDRESS(void  CChatManager::Activate(void),CChatManager__Activate);
#endif
#ifdef CChatManager__Deactivate_x
FUNCTION_AT_ADDRESS(void  CChatManager::Deactivate(void),CChatManager__Deactivate);
#endif
#ifdef CChatManager__LoadChatInis_x
FUNCTION_AT_ADDRESS(void  CChatManager::LoadChatInis(void),CChatManager__LoadChatInis);
#endif
#ifdef CChatManager__CreateChatWindow_x
FUNCTION_AT_ADDRESS(void  CChatManager::CreateChatWindow(void),CChatManager__CreateChatWindow);
#endif
#ifdef CChatManager__CreateChatWindow1_x
FUNCTION_AT_ADDRESS(void  CChatManager::CreateChatWindow(char *,char *,int,int,int,char *,int),CChatManager__CreateChatWindow1);
#endif
#ifdef CChatManager__FreeChatWindow_x
FUNCTION_AT_ADDRESS(void CChatManager::FreeChatWindow(CChatWindow *),CChatManager__FreeChatWindow);
#endif
#ifdef CChatManager__GetActiveChatWindow_x
FUNCTION_AT_ADDRESS(class CChatWindow *  CChatManager::GetActiveChatWindow(void),CChatManager__GetActiveChatWindow);
#endif
#ifdef CChatManager__AddText_x
FUNCTION_AT_ADDRESS(void  CChatManager::AddText(class CXStr,int),CChatManager__AddText);
#endif
#ifdef CChatManager__SetChannelMap_x
FUNCTION_AT_ADDRESS(void  CChatManager::SetChannelMap(int,class CChatWindow *),CChatManager__SetChannelMap);
#endif
#ifdef CChatManager__ClearChannelMap_x
FUNCTION_AT_ADDRESS(void  CChatManager::ClearChannelMap(int),CChatManager__ClearChannelMap);
#endif
#ifdef CChatManager__GetChannelFromColor_x
FUNCTION_AT_ADDRESS(int  CChatManager::GetChannelFromColor(int),CChatManager__GetChannelFromColor);
#endif
#ifdef CChatManager__GetChannelMap_x
FUNCTION_AT_ADDRESS(class CChatWindow *  CChatManager::GetChannelMap(int),CChatManager__GetChannelMap);
#endif
#ifdef CChatManager__ClearChannelMaps_x
FUNCTION_AT_ADDRESS(void  CChatManager::ClearChannelMaps(class CChatWindow *),CChatManager__ClearChannelMaps);
#endif
#ifdef CChatManager__SetActiveChatWindow_x
FUNCTION_AT_ADDRESS(void  CChatManager::SetActiveChatWindow(class CChatWindow *),CChatManager__SetActiveChatWindow);
#endif
#ifdef CChatManager__GetRGBAFromIndex_x
FUNCTION_AT_ADDRESS(unsigned long  CChatManager::GetRGBAFromIndex(int),CChatManager__GetRGBAFromIndex);
#endif
#ifdef CChatManager__InitContextMenu_x
FUNCTION_AT_ADDRESS(int  CChatManager::InitContextMenu(class CChatWindow *),CChatManager__InitContextMenu);
#endif
#ifdef CChatManager__UpdateContextMenus_x
FUNCTION_AT_ADDRESS(void  CChatManager::UpdateContextMenus(class CChatWindow *),CChatManager__UpdateContextMenus);
#endif
#ifdef CChatManager__UpdateTellMenus_x
FUNCTION_AT_ADDRESS(void  CChatManager::UpdateTellMenus(class CChatWindow *),CChatManager__UpdateTellMenus);
#endif
#ifdef CChatManager__GetAllVisibleText_x
FUNCTION_AT_ADDRESS(class CXStr  CChatManager::GetAllVisibleText(class CXStr),CChatManager__GetAllVisibleText);
#endif
#ifdef CChatManager__GetLockedActiveChatWindow_x
FUNCTION_AT_ADDRESS(CChatWindow *CChatManager::GetLockedActiveChatWindow(void),CChatManager__GetLockedActiveChatWindow);
#endif
#ifdef CChatManager__SetLockedActiveChatWindow_x
FUNCTION_AT_ADDRESS(void CChatManager::SetLockedActiveChatWindow(CChatWindow *),CChatManager__SetLockedActiveChatWindow);
#endif
#ifdef CChatWindow__GetOutputWnd_x
FUNCTION_AT_ADDRESS(class CStmlWnd *  CChatWindow::GetOutputWnd(void),CChatWindow__GetOutputWnd);
#endif
#ifdef CContextMenuManager__GetDefaultMenuIndex_x
FUNCTION_AT_ADDRESS(int  CContextMenuManager::GetDefaultMenuIndex(void),CContextMenuManager__GetDefaultMenuIndex);
#endif
#ifdef CContextMenuManager__GetMenu_x
FUNCTION_AT_ADDRESS(CContextMenu *CContextMenuManager::GetMenu(int), CContextMenuManager__GetMenu);
#endif
#ifdef CChatWindow__CChatWindow_x
FUNCTION_AT_ADDRESS( CChatWindow::CChatWindow(CXWnd *),CChatWindow__CChatWindow);
#endif
#ifdef CChatWindow__AddOutputText_x
FUNCTION_AT_ADDRESS(void  CChatWindow::AddOutputText(PCXSTR,int),CChatWindow__AddOutputText);
#endif
#ifdef CChatWindow__HistoryBack_x
FUNCTION_AT_ADDRESS(void  CChatWindow::HistoryBack(void),CChatWindow__HistoryBack);
#endif
#ifdef CChatWindow__HistoryForward_x
FUNCTION_AT_ADDRESS(void  CChatWindow::HistoryForward(void),CChatWindow__HistoryForward);
#endif
#ifdef CChatWindow__AddHistory_x
FUNCTION_AT_ADDRESS(void  CChatWindow::AddHistory(CXStr *pText),CChatWindow__AddHistory);
#endif
#ifdef CChatWindow__GetInputText_x
FUNCTION_AT_ADDRESS(class CXStr  CChatWindow::GetInputText(void),CChatWindow__GetInputText);
#endif
#ifdef CChatWindow__PageUp_x
FUNCTION_AT_ADDRESS(void  CChatWindow::PageUp(void),CChatWindow__PageUp);
#endif
#ifdef CChatWindow__PageDown_x
FUNCTION_AT_ADDRESS(void  CChatWindow::PageDown(void),CChatWindow__PageDown);
#endif
#ifdef CChatWindow__SetChatFont_x
FUNCTION_AT_ADDRESS(void  CChatWindow::SetChatFont(int),CChatWindow__SetChatFont);
#endif
#ifdef CChatWindow__Clear_x
FUNCTION_AT_ADDRESS(void  CChatWindow::Clear(void),CChatWindow__Clear);
#endif
#ifdef CStmlWnd__GetSTMLText_x
FUNCTION_AT_ADDRESS(class CXStr CStmlWnd::GetSTMLText(void)const, CStmlWnd__GetSTMLText);
#endif
#ifdef CChatWindow__GetInputWnd_x
FUNCTION_AT_ADDRESS(class CEditWnd *  CChatWindow::GetInputWnd(void),CChatWindow__GetInputWnd);
#endif
#ifdef CChatWindow__WndNotification_x
FUNCTION_AT_ADDRESS(int CChatWindow::WndNotification(class CXWnd *,unsigned __int32,void *),CChatWindow__WndNotification);
#endif
#ifdef CColorPickerWnd__CColorPickerWnd_x
FUNCTION_AT_ADDRESS( CColorPickerWnd::CColorPickerWnd(class CXWnd *),CColorPickerWnd__CColorPickerWnd);
#endif
#ifdef CColorPickerWnd__SetTemplateColor_x
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::SetTemplateColor(int,unsigned long),CColorPickerWnd__SetTemplateColor);
#endif
#ifdef CColorPickerWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::Activate(class CXWnd *,unsigned long),CColorPickerWnd__Activate);
#endif
#ifdef CColorPickerWnd__SetCurrentColor_x
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::SetCurrentColor(unsigned long),CColorPickerWnd__SetCurrentColor);
#endif
#ifdef CColorPickerWnd__UpdateCurrentColor_x
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::UpdateCurrentColor(void),CColorPickerWnd__UpdateCurrentColor);
#endif
#ifdef CColorPickerWnd__CheckMaxEditWnd_x
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::CheckMaxEditWnd(void),CColorPickerWnd__CheckMaxEditWnd);
#endif
#ifdef CColorPickerWnd__UpdateEditWndFromSlider_x
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::UpdateEditWndFromSlider(class CSliderWnd *,class CEditWnd *,int *),CColorPickerWnd__UpdateEditWndFromSlider);
#endif
#ifdef CColorPickerWnd__UpdateSliderFromEditWnd_x
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::UpdateSliderFromEditWnd(class CSliderWnd *,class CEditWnd *,int *),CColorPickerWnd__UpdateSliderFromEditWnd);
#endif
#ifdef CColorPickerWnd__Open_x
FUNCTION_AT_ADDRESS(int CColorPickerWnd::Open(CXWnd* pwndCaller, D3DCOLOR CurrentColor),CColorPickerWnd__Open);
#endif
#ifdef CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x
FUNCTION_AT_ADDRESS(bool  CCombatSkillsSelectWnd::ShouldDisplayThisSkill(int),CCombatSkillsSelectWnd__ShouldDisplayThisSkill);
#endif
#ifdef CCompassWnd__CCompassWnd_x
FUNCTION_AT_ADDRESS( CCompassWnd::CCompassWnd(class CXWnd *),CCompassWnd__CCompassWnd);
#endif
#ifdef CCompassWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CCompassWnd::Activate(void),CCompassWnd__Activate);
#endif
#ifdef CCompassWnd__PickNewTarget_x
FUNCTION_AT_ADDRESS(void  CCompassWnd::PickNewTarget(void),CCompassWnd__PickNewTarget);
#endif
#ifdef CCompassWnd__SetSpeed_x
FUNCTION_AT_ADDRESS(void  CCompassWnd::SetSpeed(void),CCompassWnd__SetSpeed);
#endif
#ifdef CCompassWnd__SenseHeading_x
FUNCTION_AT_ADDRESS(void  CCompassWnd::SenseHeading(void),CCompassWnd__SenseHeading);
#endif
#ifdef CConfirmationDialog__CConfirmationDialog_x
FUNCTION_AT_ADDRESS( CConfirmationDialog::CConfirmationDialog(class CXWnd *),CConfirmationDialog__CConfirmationDialog);
#endif
#ifdef CConfirmationDialog__Init_x
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::Init(void),CConfirmationDialog__Init);
#endif
#ifdef CConfirmationDialog__Activate_x
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::Activate(int,unsigned int,char const *,int,int,int,int),CConfirmationDialog__Activate);
#endif
#ifdef CConfirmationDialog__Deactivate_x
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::Deactivate(void),CConfirmationDialog__Deactivate);
#endif
#ifdef CConfirmationDialog__ExpireCurrentDialog_x
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::ExpireCurrentDialog(void),CConfirmationDialog__ExpireCurrentDialog);
#endif
#ifdef CConfirmationDialog__HandleButtonYesPressed_x
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::HandleButtonYesPressed(void),CConfirmationDialog__HandleButtonYesPressed);
#endif
#ifdef CConfirmationDialog__HandleButtonNoPressed_x
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::HandleButtonNoPressed(void),CConfirmationDialog__HandleButtonNoPressed);
#endif
#ifdef CConfirmationDialog__HandleButtonOkPressed_x
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::HandleButtonOkPressed(void),CConfirmationDialog__HandleButtonOkPressed);
#endif
#ifdef CConfirmationDialog__ProcessYes_x
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::ProcessYes(void),CConfirmationDialog__ProcessYes);
#endif
#ifdef CConfirmationDialog__ResetFocusOnClose_x
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::ResetFocusOnClose(void),CConfirmationDialog__ResetFocusOnClose);
#endif
#ifdef CConfirmationDialog__ProcessNo_x
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::ProcessNo(int),CConfirmationDialog__ProcessNo);
#endif
#ifdef CConfirmationDialog__SetNameApprovalData_x
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::SetNameApprovalData(char *,char *,int,int,char *),CConfirmationDialog__SetNameApprovalData);
#endif
#ifdef CConfirmationDialog__WndNotification_x
FUNCTION_AT_ADDRESS( int CConfirmationDialog::WndNotification(class CXWnd *,unsigned __int32,void *),CConfirmationDialog__WndNotification);
#endif
#ifdef CContainerMgr__GetFreeContainerWnd_x
FUNCTION_AT_ADDRESS(class CContainerWnd *  CContainerMgr::GetFreeContainerWnd(void),CContainerMgr__GetFreeContainerWnd);
#endif
#ifdef CContainerMgr__OpenExperimentContainer_x
FUNCTION_AT_ADDRESS(void CContainerMgr::OpenExperimentContainer(const VePointer<CONTENTS>& pCont, const ItemGlobalIndex& Location),CContainerMgr__OpenExperimentContainer);
#endif
#ifdef CContainerMgr__CContainerMgr_x
FUNCTION_AT_ADDRESS( CContainerMgr::CContainerMgr(void),CContainerMgr__CContainerMgr);
#endif
#ifdef CContainerMgr__Process_x
FUNCTION_AT_ADDRESS(void  CContainerMgr::Process(void),CContainerMgr__Process);
#endif
#ifdef CContainerMgr__OpenWorldContainer_x
FUNCTION_AT_ADDRESS(void  CContainerMgr::OpenWorldContainer(class EQ_Container *,unsigned long),CContainerMgr__OpenWorldContainer);
#endif
#ifdef CContainerMgr__SetWorldContainerItem_x
FUNCTION_AT_ADDRESS(void  CContainerMgr::SetWorldContainerItem(class EQ_Item *,int),CContainerMgr__SetWorldContainerItem);
#endif
#ifdef CContainerMgr__GetWorldContainerItem_x
FUNCTION_AT_ADDRESS(class EQ_Item *  CContainerMgr::GetWorldContainerItem(int),CContainerMgr__GetWorldContainerItem);
#endif
#ifdef CContainerMgr__ClearWorldContainerItems_x
FUNCTION_AT_ADDRESS(void  CContainerMgr::ClearWorldContainerItems(void),CContainerMgr__ClearWorldContainerItems);
#endif
#ifdef CContainerMgr__OpenContainer_x
FUNCTION_AT_ADDRESS(void  CContainerMgr::OpenContainer(class EQ_Container *,int,bool),CContainerMgr__OpenContainer);
#endif
#ifdef CContainerMgr__CloseEQContainer_x
FUNCTION_AT_ADDRESS(void  CContainerMgr::CloseEQContainer(class EQ_Container *),CContainerMgr__CloseEQContainer);
#endif
#ifdef CContainerMgr__CloseContainer_x
FUNCTION_AT_ADDRESS(void  CContainerMgr::CloseContainer(class EQ_Container *,bool),CContainerMgr__CloseContainer);
#endif
#ifdef CContainerMgr__CloseAllContainers_x
FUNCTION_AT_ADDRESS(bool  CContainerMgr::CloseAllContainers(void),CContainerMgr__CloseAllContainers);
#endif
#ifdef CContainerWnd__CContainerWnd_x
FUNCTION_AT_ADDRESS( CContainerWnd::CContainerWnd(class CXWnd *),CContainerWnd__CContainerWnd);
#endif
#ifdef CContainerWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CContainerWnd::Activate(void),CContainerWnd__Activate);
#endif
#ifdef CHelpWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CHelpWnd::Activate(void),CHelpWnd__Activate);
#endif
#ifdef CContainerWnd__HandleCombine_x
FUNCTION_AT_ADDRESS(void  CContainerWnd::HandleCombine(void),CContainerWnd__HandleCombine);
#endif
#ifdef CContainerWnd__SetContainer_x
FUNCTION_AT_ADDRESS(void CContainerWnd::SetContainer(PCONTENTS &pContainer, const ItemGlobalIndex& location),CContainerWnd__SetContainer);
#endif
#ifdef CContainerWnd__CheckCloseable_x
FUNCTION_AT_ADDRESS(void  CContainerWnd::CheckCloseable(void),CContainerWnd__CheckCloseable);
#endif
#ifdef CContainerWnd__ContainsNoDrop_x
FUNCTION_AT_ADDRESS(bool  CContainerWnd::ContainsNoDrop(void),CContainerWnd__ContainsNoDrop);
#endif
#ifdef CXRect__operator_or_x
FUNCTION_AT_ADDRESS(class CXRect  CXRect::operator|(class CXRect)const ,CXRect__operator_or);
#endif
#ifdef CContextMenu__CContextMenu_x
FUNCTION_AT_ADDRESS( CContextMenu::CContextMenu(CXWnd *pParent, unsigned __int32 MenuID, const CXRect& rect),CContextMenu__CContextMenu);
#endif
#ifdef CContextMenu__dCContextMenu_x
FUNCTION_AT_ADDRESS( CContextMenu::~CContextMenu(void),CContextMenu__dCContextMenu);
#endif
#ifdef CContextMenu__AddMenuItem_x
FUNCTION_AT_ADDRESS(int  CContextMenu::AddMenuItem(CXStr const &,unsigned int,bool,COLORREF,bool),CContextMenu__AddMenuItem);
#endif
#ifdef CContextMenu__AddSeparator_x
FUNCTION_AT_ADDRESS(int CContextMenu::AddSeparator(void),CContextMenu__AddSeparator);
#endif
#ifdef CContextMenu__RemoveAllMenuItems_x
FUNCTION_AT_ADDRESS(void CContextMenu::RemoveAllMenuItems(void),CContextMenu__RemoveAllMenuItems);
#endif
#ifdef CContextMenu__RemoveMenuItem_x
FUNCTION_AT_ADDRESS(void CContextMenu::RemoveMenuItem(int),CContextMenu__RemoveMenuItem);
#endif
#ifdef CContextMenu__EnableMenuItem_x
FUNCTION_AT_ADDRESS(void  CContextMenu::EnableMenuItem(int,bool),CContextMenu__EnableMenuItem);
#endif
#ifdef CContextMenu__CheckMenuItem_x
FUNCTION_AT_ADDRESS(void CContextMenu::CheckMenuItem(int,bool,bool),CContextMenu__CheckMenuItem);
#endif
#ifdef CContextMenu__Activate_x
FUNCTION_AT_ADDRESS(void  CContextMenu::Activate(class CXPoint,int,int),CContextMenu__Activate);
#endif
#ifdef CContextMenu__SetMenuItem_x
FUNCTION_AT_ADDRESS(void CContextMenu::SetMenuItem(int, const CXStr&, bool, COLORREF, bool),CContextMenu__SetMenuItem);
#endif
#ifdef CContextMenuManager__CContextMenuManager_x
FUNCTION_AT_ADDRESS( CContextMenuManager::CContextMenuManager(class CXWnd *,unsigned __int32,class CXRect),CContextMenuManager__CContextMenuManager);
#endif
#ifdef CContextMenuManager__RemoveMenu_x
FUNCTION_AT_ADDRESS(int  CContextMenuManager::RemoveMenu(int,bool),CContextMenuManager__RemoveMenu);
#endif
#ifdef CContextMenuManager__AddMenu_x
FUNCTION_AT_ADDRESS(int CContextMenuManager::AddMenu(class CContextMenu *),CContextMenuManager__AddMenu);
#endif
#ifdef CContextMenuManager__PopupMenu_x
FUNCTION_AT_ADDRESS(int  CContextMenuManager::PopupMenu(int,class CXPoint const &,class CXWnd *),CContextMenuManager__PopupMenu);
#endif
#ifdef CContextMenuManager__Flush_x
FUNCTION_AT_ADDRESS(void  CContextMenuManager::Flush(void),CContextMenuManager__Flush);
#endif
#ifdef CContextMenuManager__CreateDefaultMenu_x
FUNCTION_AT_ADDRESS(void CContextMenuManager::CreateDefaultMenu(void),CContextMenuManager__CreateDefaultMenu);
#endif
#ifdef CContextMenuManager__WarnDefaultMenu_x
FUNCTION_AT_ADDRESS(void  CContextMenuManager::WarnDefaultMenu(class CXWnd *),CContextMenuManager__WarnDefaultMenu);
#endif
#ifdef CContextMenuManager__HandleWindowMenuCommands_x
FUNCTION_AT_ADDRESS(int  CContextMenuManager::HandleWindowMenuCommands(class CXWnd *,int),CContextMenuManager__HandleWindowMenuCommands);
#endif
#ifdef CXRect__Width_x
FUNCTION_AT_ADDRESS(int  CXRect::Width(void)const ,CXRect__Width);
#endif
#ifdef CCursorAttachment__CCursorAttachment_x
FUNCTION_AT_ADDRESS( CCursorAttachment::CCursorAttachment(class CXWnd *),CCursorAttachment__CCursorAttachment);
#endif
#ifdef CCursorAttachment__Init_x
FUNCTION_AT_ADDRESS(void  CCursorAttachment::Init(void),CCursorAttachment__Init);
#endif
#ifdef CCursorAttachment__Activate_x
FUNCTION_AT_ADDRESS(void  CCursorAttachment::Activate(class CTextureAnimation *,int,int,int),CCursorAttachment__Activate);
#endif
#ifdef CCursorAttachment__DrawButtonText_x
FUNCTION_AT_ADDRESS(void  CCursorAttachment::DrawButtonText(void)const ,CCursorAttachment__DrawButtonText);
#endif
#ifdef CCursorAttachment__DrawQuantity_x
FUNCTION_AT_ADDRESS(void  CCursorAttachment::DrawQuantity(void)const ,CCursorAttachment__DrawQuantity);
#endif
#ifdef CCursorAttachment__IsOkToActivate_x
FUNCTION_AT_ADDRESS(bool  CCursorAttachment::IsOkToActivate(int),CCursorAttachment__IsOkToActivate);
#endif
#ifdef CCursorAttachment__RemoveAttachment_x
FUNCTION_AT_ADDRESS(bool  CCursorAttachment::RemoveAttachment(void),CCursorAttachment__RemoveAttachment);
#endif
#ifdef CCursorAttachment__AttachToCursor_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void CCursorAttachment::AttachToCursor(CTextureAnimation *Overlay, CTextureAnimation *pTABG, int Type, int Index, const char  *Assigned_Name, const char *Name, int Qty,int IconID),CCursorAttachment__AttachToCursor);
#else
FUNCTION_AT_ADDRESS(void CCursorAttachment::AttachToCursor(CTextureAnimation *Overlay, CTextureAnimation *pTABG, int Type, int Index, const char *Name, int Qty),CCursorAttachment__AttachToCursor);
#endif
#endif
#ifdef CCursorAttachment__AttachToCursor1_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void CCursorAttachment::AttachToCursor(CTextureAnimation *Overlay, class CTextureAnimation *pTABG, int Type, int Index, const EqItemGuid& ItemGuid, int ItemID, const char  *Assigned_Name, const char *Name, int Qty, int IconID),CCursorAttachment__AttachToCursor1);
#else
FUNCTION_AT_ADDRESS(void CCursorAttachment::AttachToCursor(CTextureAnimation *Overlay, CTextureAnimation *pTABG, int Type, int Index, const EqItemGuid &ItemGuid, int ItemID, const char *Name, int Qty),CCursorAttachment__AttachToCursor1);
#endif
#endif
#ifdef CCursorAttachment__Deactivate_x
FUNCTION_AT_ADDRESS(void CCursorAttachment::Deactivate(void),CCursorAttachment__Deactivate);
#endif
#ifdef CTextureAnimation__Reset_x
FUNCTION_AT_ADDRESS(void  CTextureAnimation::Reset(void),CTextureAnimation__Reset);
#endif
#ifdef CEditLabelWnd__CEditLabelWnd_x
FUNCTION_AT_ADDRESS( CEditLabelWnd::CEditLabelWnd(class CXWnd *),CEditLabelWnd__CEditLabelWnd);
#endif
#ifdef CEditLabelWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CEditLabelWnd::Activate(class CXWnd *,char *,int,unsigned long),CEditLabelWnd__Activate);
#endif
#ifdef CEQSuiteTextureLoader__dCEQSuiteTextureLoader_x
FUNCTION_AT_ADDRESS( CEQSuiteTextureLoader::~CEQSuiteTextureLoader(void),CEQSuiteTextureLoader__dCEQSuiteTextureLoader);
#endif
#ifdef CEQSuiteTextureLoader__CreateTexture_x
FUNCTION_AT_ADDRESS(unsigned int  CEQSuiteTextureLoader::CreateTexture(class CUITextureInfo const &),CEQSuiteTextureLoader__CreateTexture);
#endif
#ifdef CEQSuiteTextureLoader__UnloadAllTextures_x
FUNCTION_AT_ADDRESS(void  CEQSuiteTextureLoader::UnloadAllTextures(void),CEQSuiteTextureLoader__UnloadAllTextures);
#endif
#ifdef CEQSuiteTextureLoader__GetTexture_x
FUNCTION_AT_ADDRESS(BMI *CEQSuiteTextureLoader::GetTexture(const CUITextureInfo2 &ti),CEQSuiteTextureLoader__GetTexture);
#endif
#ifdef CEQSuiteTextureLoader__GetDefaultUIPath_x
FUNCTION_AT_ADDRESS(const CXStr& CEQSuiteTextureLoader::GetDefaultUIPath(int DirType) const,CEQSuiteTextureLoader__GetDefaultUIPath);
#endif
#ifdef CUITextureInfo__GetName_x
FUNCTION_AT_ADDRESS(class CXStr  CUITextureInfo::GetName(void)const ,CUITextureInfo__GetName);
#endif
#ifdef CEQSuiteTextureLoader__CEQSuiteTextureLoader_x
FUNCTION_AT_ADDRESS( CEQSuiteTextureLoader::CEQSuiteTextureLoader(void),CEQSuiteTextureLoader__CEQSuiteTextureLoader);
#endif
#ifdef CExploreModeWnd__CExploreModeWnd_x
FUNCTION_AT_ADDRESS( CExploreModeWnd::CExploreModeWnd(class CXWnd *),CExploreModeWnd__CExploreModeWnd);
#endif
#ifdef CExploreModeWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CExploreModeWnd::Activate(void),CExploreModeWnd__Activate);
#endif
#ifdef CFacePick__CFacePick_x
FUNCTION_AT_ADDRESS( CFacePick::CFacePick(class CXWnd *),CFacePick__CFacePick);
#endif
#ifdef CFacePick__Init_x
FUNCTION_AT_ADDRESS(void  CFacePick::Init(void),CFacePick__Init);
#endif
#ifdef CFacePick__ShowButtonGroup_x
FUNCTION_AT_ADDRESS(void  CFacePick::ShowButtonGroup(int,bool),CFacePick__ShowButtonGroup);
#endif
#ifdef CFacePick__Activate_x
FUNCTION_AT_ADDRESS(void  CFacePick::Activate(void),CFacePick__Activate);
#endif
#ifdef CFacePick__SetFaceSelectionsFromPlayer_x
FUNCTION_AT_ADDRESS(void  CFacePick::SetFaceSelectionsFromPlayer(void),CFacePick__SetFaceSelectionsFromPlayer);
#endif
#ifdef CFacePick__CycleThroughFHEB_x
FUNCTION_AT_ADDRESS(void  CFacePick::CycleThroughFHEB(int,int),CFacePick__CycleThroughFHEB);
#endif
#ifdef CFactionWnd__CFactionWnd1_x
FUNCTION_AT_ADDRESS( CFactionWnd::CFactionWnd(class CXWnd *),CFactionWnd__CFactionWnd);
#endif
#ifdef CFindItemWnd__CFindItemWnd_x
FUNCTION_AT_ADDRESS( CFindItemWnd::CFindItemWnd(CXWnd *),CFindItemWnd__CFindItemWnd);
#endif
#ifdef CFindItemWnd__Update_x
FUNCTION_AT_ADDRESS(void CFindItemWnd::Update(),CFindItemWnd__Update);
#endif
#ifdef CFindItemWnd__PickupSelectedItem_x
FUNCTION_AT_ADDRESS(void CFindItemWnd::PickupSelectedItem(),CFindItemWnd__PickupSelectedItem);
#endif
#ifdef IString__Append_x
FUNCTION_AT_ADDRESS(void IString2::Append(char *c),IString__Append);
#endif
#ifdef LootFiltersManager__AddItemLootFilter_x
FUNCTION_AT_ADDRESS(bool LootFiltersManager::AddItemLootFilter(int, int, const char*, int, bool),LootFiltersManager__AddItemLootFilter);
#endif
#ifdef LootFiltersManager__GetItemFilterData_x
FUNCTION_AT_ADDRESS(const PItemFilterData LootFiltersManager::GetItemFilterData(int),LootFiltersManager__GetItemFilterData);
#endif
#ifdef LootFiltersManager__RemoveItemLootFilter_x
FUNCTION_AT_ADDRESS(bool LootFiltersManager::RemoveItemLootFilter(int,int),LootFiltersManager__RemoveItemLootFilter);
#endif
#ifdef LootFiltersManager__SetItemLootFilter_x
FUNCTION_AT_ADDRESS(bool LootFiltersManager::SetItemLootFilter(int, int, const char*, int, bool, bool),LootFiltersManager__SetItemLootFilter);
#endif
#ifdef CFeedbackWnd__CFeedbackWnd_x
FUNCTION_AT_ADDRESS( CFeedbackWnd::CFeedbackWnd(class CXWnd *),CFeedbackWnd__CFeedbackWnd);
#endif
#ifdef CFeedbackWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CFeedbackWnd::Activate(void),CFeedbackWnd__Activate);
#endif
#ifdef CFileSelectionWnd__CFileSelectionWnd_x
FUNCTION_AT_ADDRESS( CFileSelectionWnd::CFileSelectionWnd(class CXWnd *),CFileSelectionWnd__CFileSelectionWnd);
#endif
#ifdef CFileSelectionWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::Activate(class CXWnd *,int),CFileSelectionWnd__Activate);
#endif
#ifdef CFileSelectionWnd__Callback_x
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::Callback(bool),CFileSelectionWnd__Callback);
#endif
#ifdef CFileSelectionWnd__MakeFilePath_x
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::MakeFilePath(void),CFileSelectionWnd__MakeFilePath);
#endif
#ifdef CFileSelectionWnd__GoSubdirectory_x
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::GoSubdirectory(struct _ITEMIDLIST *),CFileSelectionWnd__GoSubdirectory);
#endif
#ifdef CFileSelectionWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::UpdateButtons(void),CFileSelectionWnd__UpdateButtons);
#endif
#ifdef CFileSelectionWnd__DirectoryEmpty_x
FUNCTION_AT_ADDRESS(bool  CFileSelectionWnd::DirectoryEmpty(IShellFolder *,struct _ITEMIDLIST *),CFileSelectionWnd__DirectoryEmpty);
#endif
#ifdef CFileSelectionWnd__UpdateFileList_x
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::UpdateFileList(void),CFileSelectionWnd__UpdateFileList);
#endif
#ifdef CFileSelectionWnd__ClearFileList_x
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::ClearFileList(void),CFileSelectionWnd__ClearFileList);
#endif
#ifdef CFileSelectionWnd__GetPath_x
FUNCTION_AT_ADDRESS(unsigned long  CFileSelectionWnd::GetPath(IShellFolder *,struct _ITEMIDLIST *,bool,class CXStr &),CFileSelectionWnd__GetPath);
#endif
#ifdef CFileSelectionWnd__GetSelectedFileCount_x
FUNCTION_AT_ADDRESS(int  CFileSelectionWnd::GetSelectedFileCount(void),CFileSelectionWnd__GetSelectedFileCount);
#endif
#ifdef CFileSelectionWnd__GetSelectedFile_x
FUNCTION_AT_ADDRESS(class CXStr  CFileSelectionWnd::GetSelectedFile(int),CFileSelectionWnd__GetSelectedFile);
#endif
#ifdef CXStr__Left_x
FUNCTION_AT_ADDRESS(class CXStr  CXStr::Left(int)const ,CXStr__Left);
#endif
#ifdef CXStr__Right_x
FUNCTION_AT_ADDRESS(class CXStr  CXStr::Right(int)const ,CXStr__Right);
#endif
#ifdef CFriendsWnd__CFriendsWnd_x
FUNCTION_AT_ADDRESS( CFriendsWnd::CFriendsWnd(class CXWnd *),CFriendsWnd__CFriendsWnd);
#endif
#ifdef CFriendsWnd__UpdateFriendsList_x
FUNCTION_AT_ADDRESS(void  CFriendsWnd::UpdateFriendsList(void),CFriendsWnd__UpdateFriendsList);
#endif
#ifdef CFriendsWnd__UpdateIgnoreList_x
FUNCTION_AT_ADDRESS(void  CFriendsWnd::UpdateIgnoreList(void),CFriendsWnd__UpdateIgnoreList);
#endif
#ifdef CFriendsWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CFriendsWnd::Activate(void),CFriendsWnd__Activate);
#endif
#ifdef CFriendsWnd__AddFriend_x
FUNCTION_AT_ADDRESS(void  CFriendsWnd::AddFriend(void),CFriendsWnd__AddFriend);
#endif
#ifdef CFriendsWnd__AddIgnore_x
FUNCTION_AT_ADDRESS(void  CFriendsWnd::AddIgnore(void),CFriendsWnd__AddIgnore);
#endif
#ifdef CFriendsWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void  CFriendsWnd::UpdateButtons(void),CFriendsWnd__UpdateButtons);
#endif
#ifdef CGemsGameWnd__CGemsGameWnd_x
FUNCTION_AT_ADDRESS( CGemsGameWnd::CGemsGameWnd(class CXWnd *),CGemsGameWnd__CGemsGameWnd);
#endif
#ifdef CGemsGameWnd__Init_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::Init(void),CGemsGameWnd__Init);
#endif
#ifdef CGemsGameWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::Activate(void),CGemsGameWnd__Activate);
#endif
#ifdef CGemsGameWnd__Restart_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::Restart(void),CGemsGameWnd__Restart);
#endif
#ifdef CGemsGameWnd__AdvanceToNextWave_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::AdvanceToNextWave(void),CGemsGameWnd__AdvanceToNextWave);
#endif
#ifdef CGemsGameWnd__DoMatchScore_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::DoMatchScore(int),CGemsGameWnd__DoMatchScore);
#endif
#ifdef CGemsGameWnd__DrawSpellGem_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::DrawSpellGem(int,class CXRect,int,bool)const ,CGemsGameWnd__DrawSpellGem);
#endif
#ifdef CGemsGameWnd__SetPause_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::SetPause(bool),CGemsGameWnd__SetPause);
#endif
#ifdef CGemsGameWnd__TogglePause_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::TogglePause(void),CGemsGameWnd__TogglePause);
#endif
#ifdef CGemsGameWnd__SetNextUpdate_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::SetNextUpdate(void),CGemsGameWnd__SetNextUpdate);
#endif
#ifdef CGemsGameWnd__GetRndBlockImage_x
FUNCTION_AT_ADDRESS(int  CGemsGameWnd::GetRndBlockImage(void),CGemsGameWnd__GetRndBlockImage);
#endif
#ifdef CGemsGameWnd__BadSpecial_x
FUNCTION_AT_ADDRESS(bool  CGemsGameWnd::BadSpecial(int)const ,CGemsGameWnd__BadSpecial);
#endif
#ifdef CGemsGameWnd__ActivateSpecialMode_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::ActivateSpecialMode(int),CGemsGameWnd__ActivateSpecialMode);
#endif
#ifdef CGemsGameWnd__GetNextBlock_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::GetNextBlock(void),CGemsGameWnd__GetNextBlock);
#endif
#ifdef CGemsGameWnd__MoveCurBlock_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::MoveCurBlock(int),CGemsGameWnd__MoveCurBlock);
#endif
#ifdef CGemsGameWnd__ProcessMoveCurBlock_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::ProcessMoveCurBlock(int),CGemsGameWnd__ProcessMoveCurBlock);
#endif
#ifdef CGemsGameWnd__LegalBlockMove_x
FUNCTION_AT_ADDRESS(bool  CGemsGameWnd::LegalBlockMove(int,int,int,int,bool),CGemsGameWnd__LegalBlockMove);
#endif
#ifdef CGemsGameWnd__MarkHigherBlocksFalling_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::MarkHigherBlocksFalling(int,int),CGemsGameWnd__MarkHigherBlocksFalling);
#endif
#ifdef CGemsGameWnd__ClearBlock_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::ClearBlock(struct _GemsBlock *),CGemsGameWnd__ClearBlock);
#endif
#ifdef CGemsGameWnd__ClearHighScores_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::ClearHighScores(void),CGemsGameWnd__ClearHighScores);
#endif
#ifdef CGemsGameWnd__ReadHighScores_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::ReadHighScores(void),CGemsGameWnd__ReadHighScores);
#endif
#ifdef CGemsGameWnd__WriteHighScores_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::WriteHighScores(void),CGemsGameWnd__WriteHighScores);
#endif
#ifdef CGemsGameWnd__CheckForNewHighScore_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::CheckForNewHighScore(void),CGemsGameWnd__CheckForNewHighScore);
#endif
#ifdef CGemsGameWnd__ProcessMatches_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::ProcessMatches(int),CGemsGameWnd__ProcessMatches);
#endif
#ifdef CGemsGameWnd__CheckForMatches_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::CheckForMatches(int,int),CGemsGameWnd__CheckForMatches);
#endif
#ifdef CGemsGameWnd__MakeBlockDrop_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::MakeBlockDrop(int,int,int),CGemsGameWnd__MakeBlockDrop);
#endif
#ifdef CGemsGameWnd__Update_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::Update(void),CGemsGameWnd__Update);
#endif
#ifdef CGemsGameWnd__UpdateDisplay_x
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::UpdateDisplay(void),CGemsGameWnd__UpdateDisplay);
#endif
#ifdef CGiveWnd__CGiveWnd_x
FUNCTION_AT_ADDRESS( CGiveWnd::CGiveWnd(class CXWnd *),CGiveWnd__CGiveWnd);
#endif
#ifdef CGiveWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CGiveWnd::Activate(void),CGiveWnd__Activate);
#endif
#ifdef CGiveWnd__UpdateGiveDisplay_x
FUNCTION_AT_ADDRESS(void  CGiveWnd::UpdateGiveDisplay(void),CGiveWnd__UpdateGiveDisplay);
#endif
#ifdef CGroupSearchFiltersWnd__CGroupSearchFiltersWnd_x
FUNCTION_AT_ADDRESS( CGroupSearchFiltersWnd::CGroupSearchFiltersWnd(class CXWnd *),CGroupSearchFiltersWnd__CGroupSearchFiltersWnd);
#endif
#ifdef CGroupSearchFiltersWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::Activate(void),CGroupSearchFiltersWnd__Activate);
#endif
#ifdef CGroupSearchFiltersWnd__ClearUiPointers_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::ClearUiPointers(void),CGroupSearchFiltersWnd__ClearUiPointers);
#endif
#ifdef CGroupSearchFiltersWnd__FetchUiPointers_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::FetchUiPointers(void),CGroupSearchFiltersWnd__FetchUiPointers);
#endif
#ifdef CGroupSearchFiltersWnd__InitPieces_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::InitPieces(void),CGroupSearchFiltersWnd__InitPieces);
#endif
#ifdef CGroupSearchFiltersWnd__ShouldFilterPlayer_x
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::ShouldFilterPlayer(char const *,char const *)const ,CGroupSearchFiltersWnd__ShouldFilterPlayer);
#endif
#ifdef CGroupSearchFiltersWnd__UseExclusiveSearchMode_x
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::UseExclusiveSearchMode(void)const ,CGroupSearchFiltersWnd__UseExclusiveSearchMode);
#endif
#ifdef CGroupSearchFiltersWnd__HandleUseIgnoreListSelected_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleUseIgnoreListSelected(void),CGroupSearchFiltersWnd__HandleUseIgnoreListSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleUseFriendsListSelected_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleUseFriendsListSelected(void),CGroupSearchFiltersWnd__HandleUseFriendsListSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleExcludeGuildsSelected_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleExcludeGuildsSelected(void),CGroupSearchFiltersWnd__HandleExcludeGuildsSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleDesiredGuildsSelected_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleDesiredGuildsSelected(void),CGroupSearchFiltersWnd__HandleDesiredGuildsSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleAddExcludedGuild_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleAddExcludedGuild(void),CGroupSearchFiltersWnd__HandleAddExcludedGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveExcludedGuild_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleRemoveExcludedGuild(void),CGroupSearchFiltersWnd__HandleRemoveExcludedGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveAllExcludedGuilds_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleRemoveAllExcludedGuilds(void),CGroupSearchFiltersWnd__HandleRemoveAllExcludedGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__HandleAddDesiredGuild_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleAddDesiredGuild(void),CGroupSearchFiltersWnd__HandleAddDesiredGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveDesiredGuild_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleRemoveDesiredGuild(void),CGroupSearchFiltersWnd__HandleRemoveDesiredGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveAllDesiredGuilds_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleRemoveAllDesiredGuilds(void),CGroupSearchFiltersWnd__HandleRemoveAllDesiredGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__UseIgnoreList_x
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::UseIgnoreList(void)const ,CGroupSearchFiltersWnd__UseIgnoreList);
#endif
#ifdef CGroupSearchFiltersWnd__UseFriendsList_x
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::UseFriendsList(void)const ,CGroupSearchFiltersWnd__UseFriendsList);
#endif
#ifdef CGroupSearchFiltersWnd__UseExcludedGuilds_x
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::UseExcludedGuilds(void)const ,CGroupSearchFiltersWnd__UseExcludedGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__UseDesiredGuilds_x
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::UseDesiredGuilds(void)const ,CGroupSearchFiltersWnd__UseDesiredGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__NameIsInIgnoreList_x
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::NameIsInIgnoreList(char const *)const ,CGroupSearchFiltersWnd__NameIsInIgnoreList);
#endif
#ifdef CGroupSearchFiltersWnd__NameIsInFriendsList_x
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::NameIsInFriendsList(char const *)const ,CGroupSearchFiltersWnd__NameIsInFriendsList);
#endif
#ifdef CGroupSearchFiltersWnd__GuildIsInExcludedGuildsList_x
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::GuildIsInExcludedGuildsList(char const *)const ,CGroupSearchFiltersWnd__GuildIsInExcludedGuildsList);
#endif
#ifdef CGroupSearchFiltersWnd__GuildIsInDesiredGuildsList_x
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::GuildIsInDesiredGuildsList(char const *)const ,CGroupSearchFiltersWnd__GuildIsInDesiredGuildsList);
#endif
#ifdef CGroupSearchFiltersWnd__Save_x
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::Save(void)const ,CGroupSearchFiltersWnd__Save);
#endif
#ifdef CGroupSearchFiltersWnd__Load_x
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::Load(void),CGroupSearchFiltersWnd__Load);
#endif
#ifdef CGroupSearchWnd__CGroupSearchWnd_x
FUNCTION_AT_ADDRESS( CGroupSearchWnd::CGroupSearchWnd(class CXWnd *),CGroupSearchWnd__CGroupSearchWnd);
#endif
#ifdef CGroupSearchWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::Activate(int),CGroupSearchWnd__Activate);
#endif
#ifdef CGroupSearchWnd__ClearUiPointers_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::ClearUiPointers(void),CGroupSearchWnd__ClearUiPointers);
#endif
#ifdef CGroupSearchWnd__FetchUiPointers_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::FetchUiPointers(void),CGroupSearchWnd__FetchUiPointers);
#endif
#ifdef CGroupSearchWnd__ResetGroupList_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::ResetGroupList(void),CGroupSearchWnd__ResetGroupList);
#endif
#ifdef CGroupSearchWnd__AddGroupResult_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::AddGroupResult(struct LfgGroupResult const *),CGroupSearchWnd__AddGroupResult);
#endif
#ifdef CUITextureInfo__dCUITextureInfo_x
FUNCTION_AT_ADDRESS( CUITextureInfo::~CUITextureInfo(void),CUITextureInfo__dCUITextureInfo);
#endif
#ifdef CUITexturePiece__dCUITexturePiece_x
FUNCTION_AT_ADDRESS( CUITexturePiece::~CUITexturePiece(void),CUITexturePiece__dCUITexturePiece);
#endif
#ifdef STextureAnimationFrame__dSTextureAnimationFrame_x
FUNCTION_AT_ADDRESS( STextureAnimationFrame::~STextureAnimationFrame(void),STextureAnimationFrame__dSTextureAnimationFrame);
#endif
#ifdef CGroupSearchWnd__ResetPlayerList_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::ResetPlayerList(void),CGroupSearchWnd__ResetPlayerList);
#endif
#ifdef CGroupSearchWnd__AddPlayerResult_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::AddPlayerResult(struct LfgPlayerResult const *),CGroupSearchWnd__AddPlayerResult);
#endif
#ifdef CGroupSearchWnd__InitLfg_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::InitLfg(void),CGroupSearchWnd__InitLfg);
#endif
#ifdef CGroupSearchWnd__InitLfp_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::InitLfp(void),CGroupSearchWnd__InitLfp);
#endif
#ifdef CGroupSearchWnd__UpdatePlayerLabel_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::UpdatePlayerLabel(void),CGroupSearchWnd__UpdatePlayerLabel);
#endif
#ifdef CGroupSearchWnd__UpdateGroupLabel_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::UpdateGroupLabel(void),CGroupSearchWnd__UpdateGroupLabel);
#endif
#ifdef CGroupSearchWnd__RedirectOnProcessFrameTo_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::RedirectOnProcessFrameTo(class CPageWnd *),CGroupSearchWnd__RedirectOnProcessFrameTo);
#endif
#ifdef CGroupSearchWnd__RedirectWndNotificationTo_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::RedirectWndNotificationTo(class CPageWnd *,class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__RedirectWndNotificationTo);
#endif
#ifdef CGroupSearchWnd__PlayerInfoPageWndNotification_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::PlayerInfoPageWndNotification(class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__PlayerInfoPageWndNotification);
#endif
#ifdef CGroupSearchWnd__GroupInfoPageWndNotification_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GroupInfoPageWndNotification(class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__GroupInfoPageWndNotification);
#endif
#ifdef CGroupSearchWnd__PlayerListPageWndNotification_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::PlayerListPageWndNotification(class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__PlayerListPageWndNotification);
#endif
#ifdef CGroupSearchWnd__GroupListPageWndNotification_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GroupListPageWndNotification(class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__GroupListPageWndNotification);
#endif
#ifdef CGroupSearchWnd__PlayerInfoPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::PlayerInfoPageOnProcessFrame(void),CGroupSearchWnd__PlayerInfoPageOnProcessFrame);
#endif
#ifdef CGroupSearchWnd__GroupInfoPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GroupInfoPageOnProcessFrame(void),CGroupSearchWnd__GroupInfoPageOnProcessFrame);
#endif
#ifdef CGroupSearchWnd__HandlePlayerInfoPost_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandlePlayerInfoPost(void),CGroupSearchWnd__HandlePlayerInfoPost);
#endif
#ifdef CGroupSearchWnd__HandlePlayerInfoUpdate_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandlePlayerInfoUpdate(void),CGroupSearchWnd__HandlePlayerInfoUpdate);
#endif
#ifdef CGroupSearchWnd__HandlePlayerInfoRemove_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandlePlayerInfoRemove(void),CGroupSearchWnd__HandlePlayerInfoRemove);
#endif
#ifdef CGroupSearchWnd__HandleGroupInfoPost_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleGroupInfoPost(void),CGroupSearchWnd__HandleGroupInfoPost);
#endif
#ifdef CGroupSearchWnd__HandleGroupInfoUpdate_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleGroupInfoUpdate(void),CGroupSearchWnd__HandleGroupInfoUpdate);
#endif
#ifdef CGroupSearchWnd__HandleGroupInfoRemove_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleGroupInfoRemove(void),CGroupSearchWnd__HandleGroupInfoRemove);
#endif
#ifdef CGroupSearchWnd__HandleSelectAllClasses_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleSelectAllClasses(void),CGroupSearchWnd__HandleSelectAllClasses);
#endif
#ifdef CGroupSearchWnd__HandleDeselectAllClasses_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleDeselectAllClasses(void),CGroupSearchWnd__HandleDeselectAllClasses);
#endif
#ifdef CGroupSearchWnd__HandleOpenFiltersWindow_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleOpenFiltersWindow(void),CGroupSearchWnd__HandleOpenFiltersWindow);
#endif
#ifdef CGroupSearchWnd__HandleQueryingForGroups_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleQueryingForGroups(void),CGroupSearchWnd__HandleQueryingForGroups);
#endif
#ifdef CGroupSearchWnd__HandleQueryingForPlayers_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleQueryingForPlayers(void),CGroupSearchWnd__HandleQueryingForPlayers);
#endif
#ifdef CGroupSearchWnd__SendServerLfgOn_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::SendServerLfgOn(void),CGroupSearchWnd__SendServerLfgOn);
#endif
#ifdef CGroupSearchWnd__SendServerLfgOff_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::SendServerLfgOff(void),CGroupSearchWnd__SendServerLfgOff);
#endif
#ifdef CGroupSearchWnd__SendServerLfpOn_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::SendServerLfpOn(void),CGroupSearchWnd__SendServerLfpOn);
#endif
#ifdef CGroupSearchWnd__SendServerLfpOff_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::SendServerLfpOff(void),CGroupSearchWnd__SendServerLfpOff);
#endif
#ifdef CGroupSearchWnd__ShowGroupDetails_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::ShowGroupDetails(struct LfgGroupResult const *),CGroupSearchWnd__ShowGroupDetails);
#endif
#ifdef CGroupSearchWnd__PlayerShouldBeFiltered_x
FUNCTION_AT_ADDRESS(bool  CGroupSearchWnd::PlayerShouldBeFiltered(struct LfgPlayerData const *)const ,CGroupSearchWnd__PlayerShouldBeFiltered);
#endif
#ifdef CGroupSearchWnd__FilterOutBadWords_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::FilterOutBadWords(char const *,char *)const ,CGroupSearchWnd__FilterOutBadWords);
#endif
#ifdef CGroupSearchWnd__LockQueryButtonAtTime_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::LockQueryButtonAtTime(long),CGroupSearchWnd__LockQueryButtonAtTime);
#endif
#ifdef CGroupSearchWnd__UpdateRemainingQueryLockedTime_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::UpdateRemainingQueryLockedTime(long),CGroupSearchWnd__UpdateRemainingQueryLockedTime);
#endif
#ifdef CGroupSearchWnd__HandleGroupResultColSelected_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleGroupResultColSelected(int),CGroupSearchWnd__HandleGroupResultColSelected);
#endif
#ifdef CGroupSearchWnd__HandlePlayerResultColSelected_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandlePlayerResultColSelected(int),CGroupSearchWnd__HandlePlayerResultColSelected);
#endif
#ifdef CGroupSearchWnd__HandleGroupResultRowSelected_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleGroupResultRowSelected(int),CGroupSearchWnd__HandleGroupResultRowSelected);
#endif
#ifdef CGroupSearchWnd__HandleDoubleClickedOnPlayer_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleDoubleClickedOnPlayer(char const *),CGroupSearchWnd__HandleDoubleClickedOnPlayer);
#endif
#ifdef CGroupSearchWnd__HandleNumericSort_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleNumericSort(class SListWndSortInfo *),CGroupSearchWnd__HandleNumericSort);
#endif
#ifdef CGroupSearchWnd__HandleGroupMakeupChanged_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleGroupMakeupChanged(void),CGroupSearchWnd__HandleGroupMakeupChanged);
#endif
#ifdef CGroupSearchWnd__CheckIfCurrentLfgInfoIsValid_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::CheckIfCurrentLfgInfoIsValid(void)const ,CGroupSearchWnd__CheckIfCurrentLfgInfoIsValid);
#endif
#ifdef CGroupSearchWnd__CheckIfCurrentLfpInfoIsValid_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::CheckIfCurrentLfpInfoIsValid(void)const ,CGroupSearchWnd__CheckIfCurrentLfpInfoIsValid);
#endif
#ifdef CGroupSearchWnd__UpdateLfgPostingStatus_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::UpdateLfgPostingStatus(void),CGroupSearchWnd__UpdateLfgPostingStatus);
#endif
#ifdef CGroupSearchWnd__UpdateLfpPostingStatus_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::UpdateLfpPostingStatus(void),CGroupSearchWnd__UpdateLfpPostingStatus);
#endif
#ifdef CGroupSearchWnd__GetDesiredPlayerMinLevel_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GetDesiredPlayerMinLevel(void)const ,CGroupSearchWnd__GetDesiredPlayerMinLevel);
#endif
#ifdef CGroupSearchWnd__GetDefaultLfgLevelRange_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::GetDefaultLfgLevelRange(class EQ_PC const *,int *,int *)const ,CGroupSearchWnd__GetDefaultLfgLevelRange);
#endif
#ifdef CGroupSearchWnd__GetDefaultLfpLevelRange_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::GetDefaultLfpLevelRange(class EQ_PC const *,int *,int *)const ,CGroupSearchWnd__GetDefaultLfpLevelRange);
#endif
#ifdef CGroupSearchWnd__GetDesiredPlayerMaxLevel_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GetDesiredPlayerMaxLevel(void)const ,CGroupSearchWnd__GetDesiredPlayerMaxLevel);
#endif
#ifdef CGroupSearchWnd__GetDesiredGroupMinLevel_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GetDesiredGroupMinLevel(void)const ,CGroupSearchWnd__GetDesiredGroupMinLevel);
#endif
#ifdef CGroupSearchWnd__GetDesiredGroupMaxLevel_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GetDesiredGroupMaxLevel(void)const ,CGroupSearchWnd__GetDesiredGroupMaxLevel);
#endif
#ifdef CGroupSearchWnd__IsLevelRangeValid_x
FUNCTION_AT_ADDRESS(bool  CGroupSearchWnd::IsLevelRangeValid(int,int)const ,CGroupSearchWnd__IsLevelRangeValid);
#endif
#ifdef CGroupSearchWnd__GetDesiredClassesFlag_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GetDesiredClassesFlag(void)const ,CGroupSearchWnd__GetDesiredClassesFlag);
#endif
#ifdef CGroupSearchWnd__GetEqClassType_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GetEqClassType(int)const ,CGroupSearchWnd__GetEqClassType);
#endif
#ifdef CGroupSearchWnd__PopUpErrorMessage_x
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::PopUpErrorMessage(int)const ,CGroupSearchWnd__PopUpErrorMessage);
#endif
#ifdef Util__SetBit_x
FUNCTION_AT_ADDRESS(int __cdecl Util::SetBit(int,void *,int),Util__SetBit);
#endif
#ifdef _partyGroup__getNumMembers_x
FUNCTION_AT_ADDRESS(int  _partyGroup::getNumMembers(void)const ,_partyGroup__getNumMembers);
#endif
#ifdef CGroupWnd__CGroupWnd_x
FUNCTION_AT_ADDRESS( CGroupWnd::CGroupWnd(class CXWnd *),CGroupWnd__CGroupWnd);
#endif
#ifdef CGroupWnd__Init_x
FUNCTION_AT_ADDRESS(void  CGroupWnd::Init(void),CGroupWnd__Init);
#endif
#ifdef CGroupWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CGroupWnd::Activate(void),CGroupWnd__Activate);
#endif
#ifdef CGroupWnd__SetInvited_x
FUNCTION_AT_ADDRESS(void  CGroupWnd::SetInvited(bool),CGroupWnd__SetInvited);
#endif
#ifdef CGroupWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void  CGroupWnd::UpdateButtons(void),CGroupWnd__UpdateButtons);
#endif
#ifdef CGroupWnd__UpdateDisplay_x
FUNCTION_AT_ADDRESS(void CGroupWnd::UpdateDisplay(int Index, PSPAWNINFO groupmember, COLORREF NameColor, UINT RoleBits),CGroupWnd__UpdateDisplay);
#endif
#ifdef CGroupWnd__KeyMapUpdated_x
FUNCTION_AT_ADDRESS(void  CGroupWnd::KeyMapUpdated(void),CGroupWnd__KeyMapUpdated);
#endif
#ifdef CGroupWnd__CreateLocalMenu_x
FUNCTION_AT_ADDRESS(void  CGroupWnd::CreateLocalMenu(void),CGroupWnd__CreateLocalMenu);
#endif
#ifdef CGroupWnd__UpdateContextMenu_x
FUNCTION_AT_ADDRESS(void  CGroupWnd::UpdateContextMenu(void),CGroupWnd__UpdateContextMenu);
#endif
#ifdef CGuildMgmtWnd__CGuildMgmtWnd_x
FUNCTION_AT_ADDRESS( CGuildMgmtWnd::CGuildMgmtWnd(class CXWnd *),CGuildMgmtWnd__CGuildMgmtWnd);
#endif
#ifdef CGuildMgmtWnd__Init_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::Init(void),CGuildMgmtWnd__Init);
#endif
#ifdef CGuildMgmtWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::UpdateButtons(void),CGuildMgmtWnd__UpdateButtons);
#endif
#ifdef CGuildMgmtWnd__Clean_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::Clean(void),CGuildMgmtWnd__Clean);
#endif
#ifdef CGuildMgmtWnd__SetMOTD_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::SetMOTD(char *,char *),CGuildMgmtWnd__SetMOTD);
#endif
#ifdef CGuildMgmtWnd__SetPlayerCount_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::SetPlayerCount(int),CGuildMgmtWnd__SetPlayerCount);
#endif
#ifdef CGuildMgmtWnd__CreatePersonalNotesFilename_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::CreatePersonalNotesFilename(void),CGuildMgmtWnd__CreatePersonalNotesFilename);
#endif
#ifdef CGuildMgmtWnd__LoadPersonalNotes_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::LoadPersonalNotes(void),CGuildMgmtWnd__LoadPersonalNotes);
#endif
#ifdef CGuildMgmtWnd__SavePersonalNotes_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::SavePersonalNotes(void),CGuildMgmtWnd__SavePersonalNotes);
#endif
#ifdef CGuildMgmtWnd__GetPersonalNote_x
FUNCTION_AT_ADDRESS(char *  CGuildMgmtWnd::GetPersonalNote(char *),CGuildMgmtWnd__GetPersonalNote);
#endif
#ifdef CGuildMgmtWnd__SetPersonalNote_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::SetPersonalNote(char *,char *),CGuildMgmtWnd__SetPersonalNote);
#endif
#ifdef CGuildMgmtWnd__AddMember_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::AddMember(class GuildMember *),CGuildMgmtWnd__AddMember);
#endif
#ifdef CGuildMgmtWnd__RemoveMember_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::RemoveMember(class GuildMember *),CGuildMgmtWnd__RemoveMember);
#endif
#ifdef CGuildMgmtWnd__RenameMember_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::RenameMember(char *,char *),CGuildMgmtWnd__RenameMember);
#endif
#ifdef CGuildMgmtWnd__UpdateListMember_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::UpdateListMember(class GuildMember *,int),CGuildMgmtWnd__UpdateListMember);
#endif
#ifdef CGuildMgmtWnd__FindListMember_x
FUNCTION_AT_ADDRESS(int  CGuildMgmtWnd::FindListMember(class GuildMember *),CGuildMgmtWnd__FindListMember);
#endif
#ifdef CGuildMgmtWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::Activate(void),CGuildMgmtWnd__Activate);
#endif
#ifdef CGuildMgmtWnd__CleanAndRefillListWnd_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::CleanAndRefillListWnd(bool),CGuildMgmtWnd__CleanAndRefillListWnd);
#endif
#ifdef CGuildMgmtWnd__SortList_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::SortList(int,bool),CGuildMgmtWnd__SortList);
#endif
#ifdef CGuildMgmtWnd__DumpToFile_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::DumpToFile(char *),CGuildMgmtWnd__DumpToFile);
#endif
#ifdef CGuildMgmtWnd__LoadINI_x
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::LoadINI(void),CGuildMgmtWnd__LoadINI);
#endif
#ifdef CGuild__GetGuildMotd_x
FUNCTION_AT_ADDRESS(char *  CGuild::GetGuildMotd(void),CGuild__GetGuildMotd);
#endif
#ifdef CGuild__GetGuildMotdAuthor_x
FUNCTION_AT_ADDRESS(char *  CGuild::GetGuildMotdAuthor(void),CGuild__GetGuildMotdAuthor);
#endif
#ifdef EQPlayer__GetGuild_x
FUNCTION_AT_ADDRESS(int  EQPlayer::GetGuild(void)const ,EQPlayer__GetGuild);
#endif
#ifdef CHelpWnd__CHelpWnd_x
FUNCTION_AT_ADDRESS( CHelpWnd::CHelpWnd(class CXWnd *),CHelpWnd__CHelpWnd);
#endif
#ifdef CHelpWnd__SetFile_x
FUNCTION_AT_ADDRESS(void  CHelpWnd::SetFile(class CXStr),CHelpWnd__SetFile);
#endif
#ifdef CHotButtonWnd__CHotButtonWnd_x
FUNCTION_AT_ADDRESS( CHotButtonWnd::CHotButtonWnd(class CXWnd *),CHotButtonWnd__CHotButtonWnd);
#endif
#ifdef CHotButtonWnd__Init_x
FUNCTION_AT_ADDRESS(void  CHotButtonWnd::Init(void),CHotButtonWnd__Init);
#endif
#ifdef CHotButtonWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CHotButtonWnd::Activate(void),CHotButtonWnd__Activate);
#endif
#ifdef CHotButtonWnd__UpdatePage_x
FUNCTION_AT_ADDRESS(void  CHotButtonWnd::UpdatePage(void),CHotButtonWnd__UpdatePage);
#endif
#ifdef CHotButtonWnd__DoHotButton_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void  CHotButtonWnd::DoHotButton(int,int,int),CHotButtonWnd__DoHotButton);
#else
FUNCTION_AT_ADDRESS(void  CHotButtonWnd::DoHotButton(int,int),CHotButtonWnd__DoHotButton);
#endif
#endif
#ifdef CHotButton__SetButtonSize_x
FUNCTION_AT_ADDRESS(void CHotButton::SetButtonSize(int percent, bool bUpdateParent),CHotButton__SetButtonSize);
#endif
#ifdef CHotButtonWnd__DoHotButtonRightClick_x
FUNCTION_AT_ADDRESS(void  CHotButtonWnd::DoHotButtonRightClick(int),CHotButtonWnd__DoHotButtonRightClick);
#endif
#ifdef CInspectWnd__CInspectWnd_x
FUNCTION_AT_ADDRESS( CInspectWnd::CInspectWnd(class CXWnd *),CInspectWnd__CInspectWnd);
#endif
#ifdef CInspectWnd__Init_x
FUNCTION_AT_ADDRESS(void  CInspectWnd::Init(void),CInspectWnd__Init);
#endif
#ifdef CInspectWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CInspectWnd::Activate(struct _inspect *),CInspectWnd__Activate);
#endif
#ifdef CInspectWnd__AcceptInspectText_x
FUNCTION_AT_ADDRESS(void  CInspectWnd::AcceptInspectText(void),CInspectWnd__AcceptInspectText);
#endif
#ifdef CInspectWnd__PlayerBeingDeleted_x
FUNCTION_AT_ADDRESS(void  CInspectWnd::PlayerBeingDeleted(class EQPlayer *),CInspectWnd__PlayerBeingDeleted);
#endif
#ifdef CInventoryWnd__CInventoryWnd_x
FUNCTION_AT_ADDRESS( CInventoryWnd::CInventoryWnd(class CXWnd *),CInventoryWnd__CInventoryWnd);
#endif
#ifdef CInventoryWnd__Init_x
FUNCTION_AT_ADDRESS(void  CInventoryWnd::Init(void),CInventoryWnd__Init);
#endif
#ifdef CInventoryWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CInventoryWnd::Activate(void),CInventoryWnd__Activate);
#endif
#ifdef CInventoryWnd__DestroyHeld_x
FUNCTION_AT_ADDRESS(void  CInventoryWnd::DestroyHeld(void),CInventoryWnd__DestroyHeld);
#endif
#ifdef CInventoryWnd__ClickedMoneyButton_x
FUNCTION_AT_ADDRESS(void  CInventoryWnd::ClickedMoneyButton(int,int),CInventoryWnd__ClickedMoneyButton);
#endif
#ifdef CInventoryWnd__GetInventoryQtyFromCoinType_x
FUNCTION_AT_ADDRESS(long  CInventoryWnd::GetInventoryQtyFromCoinType(int),CInventoryWnd__GetInventoryQtyFromCoinType);
#endif
#ifdef CInventoryWnd__UpdateMoneyDisplay_x
FUNCTION_AT_ADDRESS(void  CInventoryWnd::UpdateMoneyDisplay(void),CInventoryWnd__UpdateMoneyDisplay);
#endif
#ifdef CInvSlot__CInvSlot_x
FUNCTION_AT_ADDRESS( CInvSlot::CInvSlot(void),CInvSlot__CInvSlot);
#endif
#ifdef CInvSlot__GetItemBase_x
FUNCTION_AT_ADDRESS( void CInvSlot::GetItemBase(struct _CONTENTS **), CInvSlot__GetItemBase );
#endif
#ifdef CInvSlot__UpdateItem_x
FUNCTION_AT_ADDRESS(void CInvSlot::UpdateItem(void), CInvSlot__UpdateItem);
#endif
#ifdef CInvSlot__SetInvSlotWnd_x
FUNCTION_AT_ADDRESS(void  CInvSlot::SetInvSlotWnd(class CInvSlotWnd *),CInvSlot__SetInvSlotWnd);
#endif
#ifdef CInvSlot__SetItem_x
FUNCTION_AT_ADDRESS(void  CInvSlot::SetItem(class EQ_Item *),CInvSlot__SetItem);
#endif
#ifdef CInvSlot__SliderComplete_x
FUNCTION_AT_ADDRESS(void  CInvSlot::SliderComplete(int),CInvSlot__SliderComplete);
#endif
#ifdef CInvSlot__HandleLButtonUp_x
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleLButtonUp(class CXPoint,bool),CInvSlot__HandleLButtonUp);
#endif
#ifdef CInvSlot__HandleLButtonHeld_x
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleLButtonHeld(class CXPoint),CInvSlot__HandleLButtonHeld);
#endif
#ifdef CInvSlot__DoDrinkEatPoison_x
FUNCTION_AT_ADDRESS(void  CInvSlot::DoDrinkEatPoison(class EQ_Item *,int),CInvSlot__DoDrinkEatPoison);
#endif
#ifdef CInvSlot__HandleRButtonUp_x
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleRButtonUp(class CXPoint *),CInvSlot__HandleRButtonUp);
#endif
#ifdef CInvSlot__HandleRButtonHeld_x
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleRButtonHeld(class CXPoint),CInvSlot__HandleRButtonHeld);
#endif
#ifdef CInvSlot__HandleRButtonUpAfterHeld_x
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleRButtonUpAfterHeld(class CXPoint),CInvSlot__HandleRButtonUpAfterHeld);
#endif
#ifdef CInvSlot__IllegalBigBank_x
FUNCTION_AT_ADDRESS(bool  CInvSlot::IllegalBigBank(int),CInvSlot__IllegalBigBank);
#endif
#ifdef CInvSlotMgr__CInvSlotMgr_x
FUNCTION_AT_ADDRESS( CInvSlotMgr::CInvSlotMgr(void),CInvSlotMgr__CInvSlotMgr);
#endif
#ifdef CInvSlotMgr__MoveItem_x
FUNCTION_AT_ADDRESS(bool  CInvSlotMgr::MoveItem(ItemGlobalIndex *from, ItemGlobalIndex *to, bool bDebugOut, bool CombineIsOk, bool MoveFromIntoToBag, bool MoveToIntoFromBag),CInvSlotMgr__MoveItem);
#endif
#ifdef CInvSlotMgr__CreateInvSlot_x
FUNCTION_AT_ADDRESS(class CInvSlot *  CInvSlotMgr::CreateInvSlot(class CInvSlotWnd *),CInvSlotMgr__CreateInvSlot);
#endif
#ifdef CInvSlotMgr__FindInvSlot_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(class CInvSlot *  CInvSlotMgr::FindInvSlot(int,int,int,bool),CInvSlotMgr__FindInvSlot);
#else
FUNCTION_AT_ADDRESS(class CInvSlot *  CInvSlotMgr::FindInvSlot(int,int),CInvSlotMgr__FindInvSlot);
#endif
#endif
#ifdef CInvSlotMgr__SelectSlot_x
FUNCTION_AT_ADDRESS(void  CInvSlotMgr::SelectSlot(class CInvSlot *),CInvSlotMgr__SelectSlot);
#endif
#ifdef CInvSlotMgr__UpdateSlots_x
FUNCTION_AT_ADDRESS(void  CInvSlotMgr::UpdateSlots(void),CInvSlotMgr__UpdateSlots);
#endif
#ifdef CItemDisplayWnd__UpdateStrings_x
FUNCTION_AT_ADDRESS(void  CItemDisplayWnd::UpdateStrings(void),CItemDisplayWnd__UpdateStrings);
#endif
#ifdef CItemDisplayWnd__InsertAugmentRequest_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::InsertAugmentRequest(int AugSlot),CItemDisplayWnd__InsertAugmentRequest);
#endif
#ifdef CItemDisplayWnd__RemoveAugmentRequest_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::RemoveAugmentRequest(int AugSlot),CItemDisplayWnd__RemoveAugmentRequest);
#endif
#ifdef CItemDisplayWnd__RequestConvertItem_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::RequestConvertItem(void),CItemDisplayWnd__RequestConvertItem);
#endif
#ifdef CItemDisplayWnd__CItemDisplayWnd_x
FUNCTION_AT_ADDRESS(CItemDisplayWnd::CItemDisplayWnd(CXWnd *),CItemDisplayWnd__CItemDisplayWnd);
#endif
#ifdef CItemDisplayWnd__dCItemDisplayWnd_x
FUNCTION_AT_ADDRESS(CItemDisplayWnd::~CItemDisplayWnd(),CItemDisplayWnd__dCItemDisplayWnd);
#endif
#ifdef CItemDisplayWnd__SetItem_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::SetItem(PCONTENTS *pCont, int flags),CItemDisplayWnd__SetItem);
#endif
#ifdef CItemDisplayWnd__AboutToShow_x
FUNCTION_AT_ADDRESS(bool CItemDisplayWnd::AboutToShow(void),CItemDisplayWnd__AboutToShow);
#endif
#ifdef CItemDisplayWnd__WndNotification_x
FUNCTION_AT_ADDRESS(int CItemDisplayWnd::WndNotification(CXWnd *, unsigned __int32, void *),CItemDisplayWnd__WndNotification);
#endif
#ifdef CItemDisplayWnd__SetItemText_x
FUNCTION_AT_ADDRESS(void  CItemDisplayWnd::SetItemText(char *),CItemDisplayWnd__SetItemText);
#endif
#ifdef CItemDisplayWnd__GetSizeString_x
FUNCTION_AT_ADDRESS(void  CItemDisplayWnd::GetSizeString(int,char *),CItemDisplayWnd__GetSizeString);
#endif
#ifdef CItemDisplayWnd__CreateRaceString_x
FUNCTION_AT_ADDRESS(class CXStr  CItemDisplayWnd::CreateRaceString(class EQ_Equipment *),CItemDisplayWnd__CreateRaceString);
#endif
#ifdef CItemDisplayWnd__CreateClassString_x
FUNCTION_AT_ADDRESS(class CXStr  CItemDisplayWnd::CreateClassString(class EQ_Equipment *),CItemDisplayWnd__CreateClassString);
#endif
#ifdef CItemDisplayWnd__CreateMealSizeString_x
FUNCTION_AT_ADDRESS(class CXStr  CItemDisplayWnd::CreateMealSizeString(class EQ_Equipment *),CItemDisplayWnd__CreateMealSizeString);
#endif
#ifdef CItemDisplayWnd__CreateModString_x
FUNCTION_AT_ADDRESS(class CXStr  CItemDisplayWnd::CreateModString(class EQ_Equipment *,int,int,int *),CItemDisplayWnd__CreateModString);
#endif
#ifdef CItemDisplayWnd__CreateEquipmentStatusString_x
FUNCTION_AT_ADDRESS(class CXStr  CItemDisplayWnd::CreateEquipmentStatusString(class EQ_Item *),CItemDisplayWnd__CreateEquipmentStatusString);
#endif
#ifdef CItemDisplayWnd__SetSpell_x
FUNCTION_AT_ADDRESS(void  CItemDisplayWnd::SetSpell(int SpellID,bool HasSpellDescr,int),CItemDisplayWnd__SetSpell);
#endif
#ifdef CJournalCatWnd__CJournalCatWnd_x
FUNCTION_AT_ADDRESS( CJournalCatWnd::CJournalCatWnd(class CXWnd *),CJournalCatWnd__CJournalCatWnd);
#endif
#ifdef CJournalCatWnd__Init_x
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::Init(void),CJournalCatWnd__Init);
#endif
#ifdef CJournalCatWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::UpdateAll(bool),CJournalCatWnd__UpdateAll);
#endif
#ifdef CJournalCatWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::UpdateButtons(void),CJournalCatWnd__UpdateButtons);
#endif
#ifdef CJournalCatWnd__SelectCategory_x
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::SelectCategory(int),CJournalCatWnd__SelectCategory);
#endif
#ifdef CJournalCatWnd__Clean_x
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::Clean(void),CJournalCatWnd__Clean);
#endif
#ifdef CJournalCatWnd__BuildList_x
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::BuildList(void),CJournalCatWnd__BuildList);
#endif
#ifdef CJournalCatWnd__UpdateListWnd_x
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::UpdateListWnd(bool),CJournalCatWnd__UpdateListWnd);
#endif
#ifdef CJournalCatWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::Activate(void),CJournalCatWnd__Activate);
#endif
#ifdef CJournalCatWnd__SortList_x
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::SortList(int,bool),CJournalCatWnd__SortList);
#endif
#ifdef CJournalCatWnd__LoadINI_x
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::LoadINI(void),CJournalCatWnd__LoadINI);
#endif
#ifdef CJournalCatWnd__StoreINI_x
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::StoreINI(void),CJournalCatWnd__StoreINI);
#endif
#ifdef CJournalNPCWnd__CJournalNPCWnd_x
FUNCTION_AT_ADDRESS( CJournalNPCWnd::CJournalNPCWnd(class CXWnd *),CJournalNPCWnd__CJournalNPCWnd);
#endif
#ifdef CJournalNPCWnd__Init_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::Init(void),CJournalNPCWnd__Init);
#endif
#ifdef CJournalNPCWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::Activate(void),CJournalNPCWnd__Activate);
#endif
#ifdef CJournalNPCWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::UpdateAll(bool),CJournalNPCWnd__UpdateAll);
#endif
#ifdef CJournalNPCWnd__UpdateListWnd_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::UpdateListWnd(bool),CJournalNPCWnd__UpdateListWnd);
#endif
#ifdef CJournalNPCWnd__SelectNPCIndex_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::SelectNPCIndex(int),CJournalNPCWnd__SelectNPCIndex);
#endif
#ifdef CJournalNPCWnd__UpdateCategories_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::UpdateCategories(void),CJournalNPCWnd__UpdateCategories);
#endif
#ifdef CJournalNPCWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::UpdateButtons(void),CJournalNPCWnd__UpdateButtons);
#endif
#ifdef CJournalNPCWnd__EnterIntoJournal_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::EnterIntoJournal(char *,float,float,float,char *),CJournalNPCWnd__EnterIntoJournal);
#endif
#ifdef CJournalNPCWnd__DoBackups_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::DoBackups(class CXStr),CJournalNPCWnd__DoBackups);
#endif
#ifdef CJournalNPCWnd__LoadJournal_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::LoadJournal(int),CJournalNPCWnd__LoadJournal);
#endif
#ifdef CJournalNPCWnd__SaveJournal_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::SaveJournal(void),CJournalNPCWnd__SaveJournal);
#endif
#ifdef CJournalNPCWnd__BuildList_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::BuildList(void),CJournalNPCWnd__BuildList);
#endif
#ifdef CJournalNPCWnd__SortList_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::SortList(int,bool),CJournalNPCWnd__SortList);
#endif
#ifdef CJournalNPCWnd__GetLogState_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::GetLogState(void),CJournalNPCWnd__GetLogState);
#endif
#ifdef CJournalNPCWnd__StoreLogState_x
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::StoreLogState(void),CJournalNPCWnd__StoreLogState);
#endif
#ifdef CJournalTextWnd__CJournalTextWnd_x
FUNCTION_AT_ADDRESS( CJournalTextWnd::CJournalTextWnd(class CXWnd *),CJournalTextWnd__CJournalTextWnd);
#endif
#ifdef CJournalTextWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::UpdateAll(bool),CJournalTextWnd__UpdateAll);
#endif
#ifdef CJournalTextWnd__UpdateCategories_x
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::UpdateCategories(void),CJournalTextWnd__UpdateCategories);
#endif
#ifdef CJournalTextWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::Activate(void),CJournalTextWnd__Activate);
#endif
#ifdef CJournalTextWnd__SetSearch_x
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::SetSearch(class CXStr),CJournalTextWnd__SetSearch);
#endif
#ifdef CJournalTextWnd__Clear_x
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::Clear(void),CJournalTextWnd__Clear);
#endif
#ifdef CJournalTextWnd__UpdateListWnd_x
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::UpdateListWnd(bool),CJournalTextWnd__UpdateListWnd);
#endif
#ifdef CJournalTextWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::UpdateButtons(void),CJournalTextWnd__UpdateButtons);
#endif
#ifdef CJournalTextWnd__DisplayNPC_x
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::DisplayNPC(class JournalNPC *),CJournalTextWnd__DisplayNPC);
#endif
#ifdef CJournalTextWnd__BuildList_x
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::BuildList(void),CJournalTextWnd__BuildList);
#endif
#ifdef CJournalTextWnd__SelectEntryIndex_x
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::SelectEntryIndex(int),CJournalTextWnd__SelectEntryIndex);
#endif
#ifdef CJournalTextWnd__SortList_x
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::SortList(int,bool),CJournalTextWnd__SortList);
#endif
#ifdef CLoadskinWnd__CLoadskinWnd_x
FUNCTION_AT_ADDRESS( CLoadskinWnd::CLoadskinWnd(class CXWnd *),CLoadskinWnd__CLoadskinWnd);
#endif
#ifdef CLoadskinWnd__UpdateSkinList_x
FUNCTION_AT_ADDRESS(void  CLoadskinWnd::UpdateSkinList(void),CLoadskinWnd__UpdateSkinList);
#endif
#ifdef CLoadskinWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CLoadskinWnd::Activate(void),CLoadskinWnd__Activate);
#endif
#ifdef CLootWnd__CLootWnd_x
FUNCTION_AT_ADDRESS( CLootWnd::CLootWnd(class CXWnd *),CLootWnd__CLootWnd);
#endif
#ifdef CLootWnd__Init_x
FUNCTION_AT_ADDRESS(void  CLootWnd::Init(void),CLootWnd__Init);
#endif
#ifdef CLootWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CLootWnd::Activate(unsigned char,long,long,long,long),CLootWnd__Activate);
#endif
#ifdef CLootWnd__Deactivate1_x
FUNCTION_AT_ADDRESS(void  CLootWnd::Deactivate(bool),CLootWnd__Deactivate1);
#endif
#ifdef CLootWnd__LootAll_x
FUNCTION_AT_ADDRESS(void  CLootWnd::LootAll(bool),CLootWnd__LootAll);
#endif
#ifdef CLootWnd__FinalizeLoot_x
FUNCTION_AT_ADDRESS(void  CLootWnd::FinalizeLoot(void),CLootWnd__FinalizeLoot);
#endif
#ifdef CLootWnd__AddEquipmentToLootArray_x
FUNCTION_AT_ADDRESS(void  CLootWnd::AddEquipmentToLootArray(class EQ_Item *),CLootWnd__AddEquipmentToLootArray);
#endif
#ifdef CLootWnd__AddNoteToLootArray_x
FUNCTION_AT_ADDRESS(void  CLootWnd::AddNoteToLootArray(class EQ_Item *),CLootWnd__AddNoteToLootArray);
#endif
#ifdef CLootWnd__AddContainerToLootArray_x
FUNCTION_AT_ADDRESS(void  CLootWnd::AddContainerToLootArray(class EQ_Item *),CLootWnd__AddContainerToLootArray);
#endif
#ifdef CLootWnd__RequestLootSlot_x
FUNCTION_AT_ADDRESS(void  CLootWnd::RequestLootSlot(int,bool),CLootWnd__RequestLootSlot);
#endif
#ifdef CLootWnd__SlotLooted_x
FUNCTION_AT_ADDRESS(void  CLootWnd::SlotLooted(int),CLootWnd__SlotLooted);
#endif
#ifdef CMapToolbarWnd__CMapToolbarWnd_x
FUNCTION_AT_ADDRESS( CMapToolbarWnd::CMapToolbarWnd(class CXWnd *),CMapToolbarWnd__CMapToolbarWnd);
#endif
#ifdef CMapToolbarWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CMapToolbarWnd::Activate(void),CMapToolbarWnd__Activate);
#endif
#ifdef CMapToolbarWnd__SetAutoMapButton_x
FUNCTION_AT_ADDRESS(void  CMapToolbarWnd::SetAutoMapButton(bool),CMapToolbarWnd__SetAutoMapButton);
#endif
#ifdef CEditLabelWnd__GetLabelText_x
FUNCTION_AT_ADDRESS(class CXStr  CEditLabelWnd::GetLabelText(void),CEditLabelWnd__GetLabelText);
#endif
#ifdef CMapViewWnd__IsMappingEnabled_x
FUNCTION_AT_ADDRESS(bool  CMapViewWnd::IsMappingEnabled(void),CMapViewWnd__IsMappingEnabled);
#endif
#ifdef CMapViewWnd__CMapViewWnd_x
FUNCTION_AT_ADDRESS( CMapViewWnd::CMapViewWnd(class CXWnd *),CMapViewWnd__CMapViewWnd);
#endif
#ifdef CMapViewWnd__Init_x
FUNCTION_AT_ADDRESS(void  CMapViewWnd::Init(void),CMapViewWnd__Init);
#endif
#ifdef CMapViewWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CMapViewWnd::Activate(void),CMapViewWnd__Activate);
#endif
#ifdef CMapViewWnd__ActivateAutoMapping_x
FUNCTION_AT_ADDRESS(void  CMapViewWnd::ActivateAutoMapping(void),CMapViewWnd__ActivateAutoMapping);
#endif
#ifdef CMapViewWnd__DeactivateAutoMapping_x
FUNCTION_AT_ADDRESS(void  CMapViewWnd::DeactivateAutoMapping(void),CMapViewWnd__DeactivateAutoMapping);
#endif
#ifdef CMapViewWnd__HandleLButtonDown_x
FUNCTION_AT_ADDRESS(int CMapViewWnd::HandleLButtonDown(class CXPoint&, unsigned __int32),CMapViewWnd__HandleLButtonDown);
#endif
#ifdef CMapViewWnd__GetWorldCoordinates_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::GetWorldCoordinates(float*),CMapViewWnd__GetWorldCoordinates);
#endif
#ifdef CMapViewWnd__SetCurrentZone_x
//FUNCTION_AT_ADDRESS(void  CMapViewWnd::SetCurrentZone(enum EQZoneIndex,struct T3D_XYZ *,struct T3D_XYZ *),CMapViewWnd__SetCurrentZone);
#endif
#ifdef MapViewMap__MapViewMap_x
FUNCTION_AT_ADDRESS( MapViewMap::MapViewMap(void),MapViewMap__MapViewMap);
#endif
#ifdef MapViewMap__dMapViewMap_x
FUNCTION_AT_ADDRESS( MapViewMap::~MapViewMap(void),MapViewMap__dMapViewMap);
#endif
#ifdef MapViewMap__Clear_x
FUNCTION_AT_ADDRESS(void  MapViewMap::Clear(void),MapViewMap__Clear);
#endif
#ifdef MapViewMap__StartLine_x
FUNCTION_AT_ADDRESS(void  MapViewMap::StartLine(float,float,float),MapViewMap__StartLine);
#endif
#ifdef MapViewMap__EndLine_x
FUNCTION_AT_ADDRESS(void  MapViewMap::EndLine(float,float,float),MapViewMap__EndLine);
#endif
#ifdef MapViewMap__RemoveLine_x
FUNCTION_AT_ADDRESS(void  MapViewMap::RemoveLine(void),MapViewMap__RemoveLine);
#endif
#ifdef MapViewMap__AddPoint_x
FUNCTION_AT_ADDRESS(void  MapViewMap::AddPoint(float,float,float),MapViewMap__AddPoint);
#endif
#ifdef MapViewMap__AddLabel_x
FUNCTION_AT_ADDRESS(void  MapViewMap::AddLabel(float,float,float,unsigned long,int,char *),MapViewMap__AddLabel);
#endif
#ifdef MapViewMap__RecalcLabelExtents_x
FUNCTION_AT_ADDRESS(void  MapViewMap::RecalcLabelExtents(struct _mapviewlabel *),MapViewMap__RecalcLabelExtents);
#endif
#ifdef MapViewMap__RemoveLabel_x
FUNCTION_AT_ADDRESS(void  MapViewMap::RemoveLabel(void),MapViewMap__RemoveLabel);
#endif
#ifdef MapViewMap__MoveLabel_x
FUNCTION_AT_ADDRESS(void  MapViewMap::MoveLabel(struct _mapviewlabel *,float,float,float),MapViewMap__MoveLabel);
#endif
#ifdef MapViewMap__CalcLabelRenderOffsets_x
FUNCTION_AT_ADDRESS(void  MapViewMap::CalcLabelRenderOffsets(class CXRect),MapViewMap__CalcLabelRenderOffsets);
#endif
#ifdef MapViewMap__IsLayerVisible_x
FUNCTION_AT_ADDRESS(bool  MapViewMap::IsLayerVisible(int),MapViewMap__IsLayerVisible);
#endif
#ifdef MapViewMap__PointInMapViewArea_x
FUNCTION_AT_ADDRESS(bool  MapViewMap::PointInMapViewArea(class CXPoint,class CXRect),MapViewMap__PointInMapViewArea);
#endif
#ifdef MapViewMap__PreCalcRenderValues_x
FUNCTION_AT_ADDRESS(void  MapViewMap::PreCalcRenderValues(void),MapViewMap__PreCalcRenderValues);
#endif
#ifdef MapViewMap__TransformPoint_x
FUNCTION_AT_ADDRESS(void  MapViewMap::TransformPoint(struct T3D_XYZ *),MapViewMap__TransformPoint);
#endif
#ifdef MapViewMap__Draw_x
FUNCTION_AT_ADDRESS(void  MapViewMap::Draw(class CXRect),MapViewMap__Draw);
#endif
#ifdef MapViewMap__DrawClippedLine_x
FUNCTION_AT_ADDRESS(bool  MapViewMap::DrawClippedLine(struct T3D_XYZ *,struct T3D_RGB,class CXRect),MapViewMap__DrawClippedLine);
#endif
#ifdef MapViewMap__Save_x
FUNCTION_AT_ADDRESS(void  MapViewMap::Save(char *),MapViewMap__Save);
#endif
#ifdef MapViewMap__SaveEx_x
FUNCTION_AT_ADDRESS(void  MapViewMap::SaveEx(char *,int),MapViewMap__SaveEx);
#endif
#ifdef MapViewMap__Load_x
FUNCTION_AT_ADDRESS(void  MapViewMap::Load(char *),MapViewMap__Load);
#endif
#ifdef MapViewMap__LoadEx_x
FUNCTION_AT_ADDRESS(bool  MapViewMap::LoadEx(char *,int),MapViewMap__LoadEx);
#endif
#ifdef MapViewMap__GetCurrentColor_x
FUNCTION_AT_ADDRESS(unsigned long  MapViewMap::GetCurrentColor(void),MapViewMap__GetCurrentColor);
#endif
#ifdef MapViewMap__SetCurrentColor_x
FUNCTION_AT_ADDRESS(void  MapViewMap::SetCurrentColor(unsigned long),MapViewMap__SetCurrentColor);
#endif
#ifdef MapViewMap__SetMarkedLine_x
FUNCTION_AT_ADDRESS(void  MapViewMap::SetMarkedLine(struct _mapviewline *),MapViewMap__SetMarkedLine);
#endif
#ifdef MapViewMap__SetMarkedLineColor_x
FUNCTION_AT_ADDRESS(void  MapViewMap::SetMarkedLineColor(unsigned long),MapViewMap__SetMarkedLineColor);
#endif
#ifdef MapViewMap__GetMarkedLineColor_x
FUNCTION_AT_ADDRESS(unsigned long  MapViewMap::GetMarkedLineColor(void),MapViewMap__GetMarkedLineColor);
#endif
#ifdef MapViewMap__ClearActiveLayer_x
FUNCTION_AT_ADDRESS(void  MapViewMap::ClearActiveLayer(void),MapViewMap__ClearActiveLayer);
#endif
#ifdef MapViewMap__RemoveLine1_x
FUNCTION_AT_ADDRESS(void  MapViewMap::RemoveLine(struct _mapviewline *),MapViewMap__RemoveLine1);
#endif
#ifdef MapViewMap__RemoveLabel1_x
FUNCTION_AT_ADDRESS(void  MapViewMap::RemoveLabel(struct _mapviewlabel *),MapViewMap__RemoveLabel1);
#endif
#ifdef CXRect__Normalize_x
FUNCTION_AT_ADDRESS(void  CXRect::Normalize(void),CXRect__Normalize);
#endif
#ifdef CXRect__operator_and_x
FUNCTION_AT_ADDRESS(class CXRect  CXRect::operator&(class CXRect)const ,CXRect__operator_and);
#endif
#ifdef MapViewMap__JoinLinesAtIntersect_x
FUNCTION_AT_ADDRESS(void  MapViewMap::JoinLinesAtIntersect(bool),MapViewMap__JoinLinesAtIntersect);
#endif
#ifdef MapViewMap__SetZoneExtents_x
FUNCTION_AT_ADDRESS(void  MapViewMap::SetZoneExtents(int,int,int,int),MapViewMap__SetZoneExtents);
#endif
#ifdef MapViewMap__SetZoom_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetZoom(float),MapViewMap__SetZoom);
#endif
#ifdef MapViewMap__GetMinZ_x
FUNCTION_AT_ADDRESS(int  MapViewMap::GetMinZ(void),MapViewMap__GetMinZ);
#endif
#ifdef MapViewMap__GetMaxZ_x
FUNCTION_AT_ADDRESS(int  MapViewMap::GetMaxZ(void),MapViewMap__GetMaxZ);
#endif
#ifdef CMerchantWnd__CMerchantWnd_x
FUNCTION_AT_ADDRESS( CMerchantWnd::CMerchantWnd(class CXWnd *),CMerchantWnd__CMerchantWnd);
#endif
#ifdef CMerchantWnd__Init_x
FUNCTION_AT_ADDRESS(void  CMerchantWnd::Init(void),CMerchantWnd__Init);
#endif
#ifdef CMerchantWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CMerchantWnd::Activate(class EQPlayer *,float),CMerchantWnd__Activate);
#endif
#ifdef CMerchantWnd__HandleBuy_x
FUNCTION_AT_ADDRESS(void  CMerchantWnd::HandleBuy(int),CMerchantWnd__HandleBuy);
#endif
#ifdef CMerchantWnd__HandleSell_x
FUNCTION_AT_ADDRESS(void  CMerchantWnd::HandleSell(int),CMerchantWnd__HandleSell);
#endif
#ifdef CMerchantWnd__UpdateBuySellButtons_x
FUNCTION_AT_ADDRESS(void  CMerchantWnd::UpdateBuySellButtons(void),CMerchantWnd__UpdateBuySellButtons);
#endif
#ifdef CMerchantWnd__SelectBuySellSlot_x
//FUNCTION_AT_ADDRESS(void  CMerchantWnd::SelectBuySellSlot(int,class CTextureAnimation *),CMerchantWnd__SelectBuySellSlot);
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(int  CMerchantWnd::SelectBuySellSlot(class ItemGlobalIndex *, int Unknown), CMerchantWnd__SelectBuySellSlot);
#else
FUNCTION_AT_ADDRESS(int  CMerchantWnd::SelectBuySellSlot(class ItemGlobalIndex *), CMerchantWnd__SelectBuySellSlot);
#endif
#endif
#ifdef CMerchantWnd__DisplayBuyOrSellPrice_x
FUNCTION_AT_ADDRESS(void  CMerchantWnd::DisplayBuyOrSellPrice(bool,class EQ_Item *),CMerchantWnd__DisplayBuyOrSellPrice);
#endif
#ifdef CMerchantWnd__PurchasePageHandler__RequestGetItem_x
FUNCTION_AT_ADDRESS(bool CMerchantWnd::PurchasePageHandler::RequestGetItem(int), CMerchantWnd__PurchasePageHandler__RequestGetItem);
#endif
#ifdef CMerchantWnd__FinishBuyingItem_x
FUNCTION_AT_ADDRESS(void  CMerchantWnd::FinishBuyingItem(struct _sell_msg *),CMerchantWnd__FinishBuyingItem);
#endif
#ifdef CMerchantWnd__PurchasePageHandler__RequestPutItem_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::PurchasePageHandler::RequestPutItem(int), CMerchantWnd__PurchasePageHandler__RequestPutItem);
#endif
#ifdef CMerchantWnd__FinishSellingItem_x
FUNCTION_AT_ADDRESS(void  CMerchantWnd::FinishSellingItem(struct _sell_msg *),CMerchantWnd__FinishSellingItem);
#endif
#ifdef CMerchantWnd__AddEquipmentToMercArray_x
FUNCTION_AT_ADDRESS(void  CMerchantWnd::AddEquipmentToMercArray(class EQ_Equipment *),CMerchantWnd__AddEquipmentToMercArray);
#endif
#ifdef CMerchantWnd__AddNoteToMercArray_x
FUNCTION_AT_ADDRESS(void  CMerchantWnd::AddNoteToMercArray(class EQ_Note *),CMerchantWnd__AddNoteToMercArray);
#endif
#ifdef CMerchantWnd__AddContainerToMercArray_x
FUNCTION_AT_ADDRESS(void  CMerchantWnd::AddContainerToMercArray(class EQ_Container *),CMerchantWnd__AddContainerToMercArray);
#endif
#ifdef CMerchantWnd__ClearMerchantSlot_x
FUNCTION_AT_ADDRESS(void  CMerchantWnd::ClearMerchantSlot(int),CMerchantWnd__ClearMerchantSlot);
#endif
#ifdef CMusicPlayerWnd__CMusicPlayerWnd_x
FUNCTION_AT_ADDRESS( CMusicPlayerWnd::CMusicPlayerWnd(class CXWnd *),CMusicPlayerWnd__CMusicPlayerWnd);
#endif
#ifdef CMusicPlayerWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CMusicPlayerWnd::Activate(void),CMusicPlayerWnd__Activate);
#endif
#ifdef CMusicPlayerWnd__AutoStart_x
FUNCTION_AT_ADDRESS(void  CMusicPlayerWnd::AutoStart(void),CMusicPlayerWnd__AutoStart);
#endif
#ifdef CMusicPlayerWnd__Update_x
FUNCTION_AT_ADDRESS(void  CMusicPlayerWnd::Update(void),CMusicPlayerWnd__Update);
#endif
#ifdef CMusicPlayerWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void  CMusicPlayerWnd::UpdateButtons(void),CMusicPlayerWnd__UpdateButtons);
#endif
#ifdef CNoteWnd__CNoteWnd_x
FUNCTION_AT_ADDRESS( CNoteWnd::CNoteWnd(class CXWnd *),CNoteWnd__CNoteWnd);
#endif
#ifdef CNoteWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CNoteWnd::Activate(void),CNoteWnd__Activate);
#endif
#ifdef CNoteWnd__CheckNote_x
FUNCTION_AT_ADDRESS(bool  CNoteWnd::CheckNote(class EQ_Note *),CNoteWnd__CheckNote);
#endif
#ifdef CNoteWnd__SetNote_x
FUNCTION_AT_ADDRESS(void  CNoteWnd::SetNote(char *),CNoteWnd__SetNote);
#endif
#ifdef CXStr__operator_lb_rb_x
FUNCTION_AT_ADDRESS(char  CXStr::operator[](int)const ,CXStr__operator_lb_rb);
#endif
#ifdef COptionsWnd__FillChatFilterList_x
FUNCTION_AT_ADDRESS(void COptionsWnd::FillChatFilterList(void),COptionsWnd__FillChatFilterList);
#endif
#ifdef COptionsWnd__COptionsWnd_x
FUNCTION_AT_ADDRESS( COptionsWnd::COptionsWnd(class CXWnd *),COptionsWnd__COptionsWnd);
#endif
#ifdef COptionsWnd__SyncGeneralPage_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::SyncGeneralPage(void),COptionsWnd__SyncGeneralPage);
#endif
#ifdef COptionsWnd__SyncDisplayPage_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::SyncDisplayPage(void),COptionsWnd__SyncDisplayPage);
#endif
#ifdef COptionsWnd__SyncMousePage_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::SyncMousePage(void),COptionsWnd__SyncMousePage);
#endif
#ifdef COptionsWnd__SyncChatPage_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::SyncChatPage(void),COptionsWnd__SyncChatPage);
#endif
#ifdef COptionsWnd__SyncColorPage_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::SyncColorPage(void),COptionsWnd__SyncColorPage);
#endif
#ifdef COptionsWnd__InitKeyboardPage_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::InitKeyboardPage(void),COptionsWnd__InitKeyboardPage);
#endif
#ifdef COptionsWnd__InitKeyboardAssignments_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::InitKeyboardAssignments(void),COptionsWnd__InitKeyboardAssignments);
#endif
#ifdef COptionsWnd__RefreshCurrentKeyboardAssignmentList_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::RefreshCurrentKeyboardAssignmentList(void),COptionsWnd__RefreshCurrentKeyboardAssignmentList);
#endif
#ifdef COptionsWnd__AddKeyboardAssignment_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::AddKeyboardAssignment(int,int,int),COptionsWnd__AddKeyboardAssignment);
#endif
#ifdef COptionsWnd__Activate_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::Activate(void),COptionsWnd__Activate);
#endif
#ifdef COptionsWnd__ResetKeysToDefault_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::ResetKeysToDefault(void),COptionsWnd__ResetKeysToDefault);
#endif
#ifdef COptionsWnd__RedirectOnProcessFrameTo_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::RedirectOnProcessFrameTo(class CPageWnd *),COptionsWnd__RedirectOnProcessFrameTo);
#endif
#ifdef COptionsWnd__RedirectWndNotificationTo_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::RedirectWndNotificationTo(class CPageWnd *,class CXWnd *,unsigned __int32,void *),COptionsWnd__RedirectWndNotificationTo);
#endif
#ifdef COptionsWnd__RedirectHandleKeyboardMsgTo_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::RedirectHandleKeyboardMsgTo(class CPageWnd *,unsigned __int32,unsigned __int32,bool),COptionsWnd__RedirectHandleKeyboardMsgTo);
#endif
#ifdef COptionsWnd__RedirectDeactivateTo_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::RedirectDeactivateTo(class CPageWnd *),COptionsWnd__RedirectDeactivateTo);
#endif
#ifdef COptionsWnd__GeneralPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::GeneralPageOnProcessFrame(void),COptionsWnd__GeneralPageOnProcessFrame);
#endif
#ifdef COptionsWnd__GeneralPageWndNotification_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::GeneralPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__GeneralPageWndNotification);
#endif
#ifdef COptionsWnd__DisplayPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::DisplayPageOnProcessFrame(void),COptionsWnd__DisplayPageOnProcessFrame);
#endif
#ifdef COptionsWnd__DisplayPageWndNotification_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::DisplayPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__DisplayPageWndNotification);
#endif
#ifdef COptionsWnd__MousePageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::MousePageOnProcessFrame(void),COptionsWnd__MousePageOnProcessFrame);
#endif
#ifdef COptionsWnd__MousePageWndNotification_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::MousePageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__MousePageWndNotification);
#endif
#ifdef COptionsWnd__KeyboardPageWndNotification_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::KeyboardPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__KeyboardPageWndNotification);
#endif
#ifdef COptionsWnd__KeyboardPageHandleKeyboardMsg_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::KeyboardPageHandleKeyboardMsg(unsigned __int32,unsigned __int32,bool),COptionsWnd__KeyboardPageHandleKeyboardMsg);
#endif
#ifdef COptionsWnd__KeyboardPageDeactivate_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::KeyboardPageDeactivate(void),COptionsWnd__KeyboardPageDeactivate);
#endif
#ifdef COptionsWnd__KeyboardPageCancelKeypressAssignment_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::KeyboardPageCancelKeypressAssignment(void),COptionsWnd__KeyboardPageCancelKeypressAssignment);
#endif
#ifdef COptionsWnd__ChatPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::ChatPageOnProcessFrame(void),COptionsWnd__ChatPageOnProcessFrame);
#endif
#ifdef COptionsWnd__ColorPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::ColorPageOnProcessFrame(void),COptionsWnd__ColorPageOnProcessFrame);
#endif
#ifdef COptionsWnd__ChatPageWndNotification_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::ChatPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__ChatPageWndNotification);
#endif
#ifdef COptionsWnd__ColorPageWndNotification_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::ColorPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__ColorPageWndNotification);
#endif
#ifdef COptionsWnd__RestoreDefaultColors_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::RestoreDefaultColors(void),COptionsWnd__RestoreDefaultColors);
#endif
#ifdef COptionsWnd__SetBagOptions_x
FUNCTION_AT_ADDRESS(void  COptionsWnd::SetBagOptions(int,int),COptionsWnd__SetBagOptions);
#endif
#ifdef CPetInfoWnd__CPetInfoWnd_x
FUNCTION_AT_ADDRESS( CPetInfoWnd::CPetInfoWnd(class CXWnd *),CPetInfoWnd__CPetInfoWnd);
#endif
#ifdef CPetInfoWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CPetInfoWnd::Activate(void),CPetInfoWnd__Activate);
#endif
#ifdef CPetInfoWnd__SetShowOnSummon_x
FUNCTION_AT_ADDRESS(void  CPetInfoWnd::SetShowOnSummon(bool),CPetInfoWnd__SetShowOnSummon);
#endif
#ifdef CPetInfoWnd__Update_x
FUNCTION_AT_ADDRESS(void  CPetInfoWnd::Update(void),CPetInfoWnd__Update);
#endif
#ifdef CPetInfoWnd__GetButton_x
FUNCTION_AT_ADDRESS(class CButtonWnd *  CPetInfoWnd::GetButton(int),CPetInfoWnd__GetButton);
#endif
#ifdef CPetitionQWnd__CPetitionQWnd_x
FUNCTION_AT_ADDRESS( CPetitionQWnd::CPetitionQWnd(class CXWnd *),CPetitionQWnd__CPetitionQWnd);
#endif
#ifdef CPetitionQWnd__UpdatePetitions_x
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::UpdatePetitions(void),CPetitionQWnd__UpdatePetitions);
#endif
#ifdef CPetitionQWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::Activate(void),CPetitionQWnd__Activate);
#endif
#ifdef CPetitionQWnd__SetPriorityDisplay_x
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::SetPriorityDisplay(void),CPetitionQWnd__SetPriorityDisplay);
#endif
#ifdef CPetitionQWnd__AddGMText_x
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::AddGMText(void),CPetitionQWnd__AddGMText);
#endif
#ifdef CPetitionQWnd__CheckedOut_x
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::CheckedOut(struct petitionQtype const *,int),CPetitionQWnd__CheckedOut);
#endif
#ifdef CPetitionQWnd__UndoCheckout_x
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::UndoCheckout(void),CPetitionQWnd__UndoCheckout);
#endif
#ifdef CPetitionQWnd__ClearCurrentPet_x
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::ClearCurrentPet(void),CPetitionQWnd__ClearCurrentPet);
#endif
#ifdef CPetitionQWnd__FillFields_x
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::FillFields(void),CPetitionQWnd__FillFields);
#endif
#ifdef CPetitionQWnd__SetButtonsForPetition_x
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::SetButtonsForPetition(bool,bool),CPetitionQWnd__SetButtonsForPetition);
#endif
#ifdef CPetitionQWnd__LogPetitionText_x
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::LogPetitionText(void),CPetitionQWnd__LogPetitionText);
#endif
#ifdef CPetitionQWnd__GetCurrentPetitionersName_x
FUNCTION_AT_ADDRESS(char *  CPetitionQWnd::GetCurrentPetitionersName(void),CPetitionQWnd__GetCurrentPetitionersName);
#endif
#ifdef CPlayerNotesWnd__CPlayerNotesWnd_x
FUNCTION_AT_ADDRESS( CPlayerNotesWnd::CPlayerNotesWnd(class CXWnd *),CPlayerNotesWnd__CPlayerNotesWnd);
#endif
#ifdef CPlayerNotesWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CPlayerNotesWnd::Activate(void),CPlayerNotesWnd__Activate);
#endif
#ifdef CPlayerNotesWnd__SaveNotes_x
FUNCTION_AT_ADDRESS(void  CPlayerNotesWnd::SaveNotes(void),CPlayerNotesWnd__SaveNotes);
#endif
#ifdef CPlayerNotesWnd__AppendText_x
FUNCTION_AT_ADDRESS(void  CPlayerNotesWnd::AppendText(char *),CPlayerNotesWnd__AppendText);
#endif
#ifdef CPlayerWnd__CPlayerWnd_x
FUNCTION_AT_ADDRESS( CPlayerWnd::CPlayerWnd(class CXWnd *),CPlayerWnd__CPlayerWnd);
#endif
#ifdef CPlayerWnd__Init_x
FUNCTION_AT_ADDRESS(void  CPlayerWnd::Init(void),CPlayerWnd__Init);
#endif
#ifdef CPlayerWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CPlayerWnd::Activate(void),CPlayerWnd__Activate);
#endif
#ifdef CPlayerWnd__CreateLocalMenu_x
FUNCTION_AT_ADDRESS(void  CPlayerWnd::CreateLocalMenu(void),CPlayerWnd__CreateLocalMenu);
#endif
#ifdef CPlayerWnd__UpdateContextMenu_x
FUNCTION_AT_ADDRESS(void  CPlayerWnd::UpdateContextMenu(void),CPlayerWnd__UpdateContextMenu);
#endif
#ifdef CQuantityWnd__CQuantityWnd_x
FUNCTION_AT_ADDRESS( CQuantityWnd::CQuantityWnd(class CXWnd *),CQuantityWnd__CQuantityWnd);
#endif
#ifdef CQuantityWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CQuantityWnd::Activate(class CXWnd *,int,int,int,int,bool),CQuantityWnd__Activate);
#endif
#ifdef CQuantityWnd__CheckMaxEditWnd_x
FUNCTION_AT_ADDRESS(void  CQuantityWnd::CheckMaxEditWnd(void),CQuantityWnd__CheckMaxEditWnd);
#endif
#ifdef CQuantityWnd__Open_x
FUNCTION_AT_ADDRESS(void  CQuantityWnd::Open(class CXWnd *,int,int,int,int,int,int,bool),CQuantityWnd__Open);
#endif
#ifdef CQuantityWnd__UpdateEditWndFromSlider_x
FUNCTION_AT_ADDRESS(void  CQuantityWnd::UpdateEditWndFromSlider(void),CQuantityWnd__UpdateEditWndFromSlider);
#endif
#ifdef CQuantityWnd__UpdateSliderFromEditWnd_x
FUNCTION_AT_ADDRESS(void  CQuantityWnd::UpdateSliderFromEditWnd(void),CQuantityWnd__UpdateSliderFromEditWnd);
#endif
#ifdef CRaidOptionsWnd__CRaidOptionsWnd_x
FUNCTION_AT_ADDRESS( CRaidOptionsWnd::CRaidOptionsWnd(class CXWnd *),CRaidOptionsWnd__CRaidOptionsWnd);
#endif
#ifdef CRaidOptionsWnd__Init_x
FUNCTION_AT_ADDRESS(void  CRaidOptionsWnd::Init(void),CRaidOptionsWnd__Init);
#endif
#ifdef CRaidOptionsWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CRaidOptionsWnd::Activate(void),CRaidOptionsWnd__Activate);
#endif
#ifdef CRaidOptionsWnd__AddLooterToList_x
FUNCTION_AT_ADDRESS(void  CRaidOptionsWnd::AddLooterToList(char *),CRaidOptionsWnd__AddLooterToList);
#endif
#ifdef CRaidOptionsWnd__ClearLooterList_x
FUNCTION_AT_ADDRESS(void  CRaidOptionsWnd::ClearLooterList(void),CRaidOptionsWnd__ClearLooterList);
#endif
#ifdef CRaidOptionsWnd__UpdateComponents_x
FUNCTION_AT_ADDRESS(void  CRaidOptionsWnd::UpdateComponents(void),CRaidOptionsWnd__UpdateComponents);
#endif
#ifdef CRaidOptionsWnd__InitializeClassColors_x
FUNCTION_AT_ADDRESS(void  CRaidOptionsWnd::InitializeClassColors(void),CRaidOptionsWnd__InitializeClassColors);
#endif
#ifdef CRaidWnd__CRaidWnd_x
FUNCTION_AT_ADDRESS( CRaidWnd::CRaidWnd(class CXWnd *),CRaidWnd__CRaidWnd);
#endif
#ifdef CRaidWnd__Init_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::Init(void),CRaidWnd__Init);
#endif
#ifdef CRaidWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::Activate(void),CRaidWnd__Activate);
#endif
#ifdef CRaidWnd__AddPlayertoList_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::AddPlayertoList(char *,char *,char *,char *,int,int,bool),CRaidWnd__AddPlayertoList);
#endif
#ifdef CRaidWnd__RemovePlayerFromList_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::RemovePlayerFromList(char *,int),CRaidWnd__RemovePlayerFromList);
#endif
#ifdef CRaidWnd__SetRaidCount_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::SetRaidCount(int),CRaidWnd__SetRaidCount);
#endif
#ifdef CRaidWnd__ClearPlayerList_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::ClearPlayerList(void),CRaidWnd__ClearPlayerList);
#endif
#ifdef CRaidWnd__AddSeparator_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::AddSeparator(void),CRaidWnd__AddSeparator);
#endif
#ifdef CRaidWnd__SetRaidMemberRank_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::SetRaidMemberRank(char *,char *,int),CRaidWnd__SetRaidMemberRank);
#endif
#ifdef CRaidWnd__ChangePosition_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::ChangePosition(char *,int,int,int,bool),CRaidWnd__ChangePosition);
#endif
#ifdef CRaidWnd__ChangeRaidGroupLeader_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::ChangeRaidGroupLeader(char *,int,char *),CRaidWnd__ChangeRaidGroupLeader);
#endif
#ifdef CRaidWnd__UpdateMemberName_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::UpdateMemberName(char *,char *,int),CRaidWnd__UpdateMemberName);
#endif
#ifdef CRaidWnd__SetRaidTarget_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::SetRaidTarget(char *,int,char *,int),CRaidWnd__SetRaidTarget);
#endif
#ifdef CRaidWnd__UpdateLevelAverage_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::UpdateLevelAverage(int),CRaidWnd__UpdateLevelAverage);
#endif
#ifdef CRaidWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::UpdateButtons(void),CRaidWnd__UpdateButtons);
#endif
#ifdef CRaidWnd__InitializeClassColors_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::InitializeClassColors(void),CRaidWnd__InitializeClassColors);
#endif
#ifdef CRaidWnd__SetPlayerClassColor_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::SetPlayerClassColor(int,int,int),CRaidWnd__SetPlayerClassColor);
#endif
#ifdef CRaidWnd__SetPlayerClassColor1_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::SetPlayerClassColor(char *,int,int),CRaidWnd__SetPlayerClassColor1);
#endif
#ifdef CRaidWnd__SetClassColor_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::SetClassColor(int,unsigned long),CRaidWnd__SetClassColor);
#endif
#ifdef CRaidWnd__ResortRaidGroupList_x
FUNCTION_AT_ADDRESS(void  CRaidWnd::ResortRaidGroupList(int,int),CRaidWnd__ResortRaidGroupList);
#endif
#ifdef CRaidWnd__FindOpenIndexInGroup_x
FUNCTION_AT_ADDRESS(int  CRaidWnd::FindOpenIndexInGroup(int),CRaidWnd__FindOpenIndexInGroup);
#endif
#ifdef CRaidWnd__FindIndexNotInGroupList_x
FUNCTION_AT_ADDRESS(int  CRaidWnd::FindIndexNotInGroupList(char *),CRaidWnd__FindIndexNotInGroupList);
#endif
#ifdef CRaidWnd__FindPlayerIndexInGroup_x
FUNCTION_AT_ADDRESS(int  CRaidWnd::FindPlayerIndexInGroup(char *,int),CRaidWnd__FindPlayerIndexInGroup);
#endif
#ifdef CSelectorWnd__CSelectorWnd_x
FUNCTION_AT_ADDRESS( CSelectorWnd::CSelectorWnd(class CXWnd *),CSelectorWnd__CSelectorWnd);
#endif
#ifdef CSelectorWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CSelectorWnd::Activate(void),CSelectorWnd__Activate);
#endif
#ifdef CSelectorWnd__KeyMapUpdated_x
FUNCTION_AT_ADDRESS(void  CSelectorWnd::KeyMapUpdated(void),CSelectorWnd__KeyMapUpdated);
#endif
#ifdef CSkillsSelectWnd__CSkillsSelectWnd_x
FUNCTION_AT_ADDRESS( CSkillsSelectWnd::CSkillsSelectWnd(class CXWnd *),CSkillsSelectWnd__CSkillsSelectWnd);
#endif
#ifdef CSkillsSelectWnd__Refresh_x
FUNCTION_AT_ADDRESS(void  CSkillsSelectWnd::Refresh(void),CSkillsSelectWnd__Refresh);
#endif
#ifdef CSkillsSelectWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void  CSkillsSelectWnd::UpdateAll(void),CSkillsSelectWnd__UpdateAll);
#endif
#ifdef CSkillsSelectWnd__UpdateSkill_x
FUNCTION_AT_ADDRESS(void  CSkillsSelectWnd::UpdateSkill(int),CSkillsSelectWnd__UpdateSkill);
#endif
#ifdef CSkillsSelectWnd__SetTypesToDisplay_x
FUNCTION_AT_ADDRESS(void  CSkillsSelectWnd::SetTypesToDisplay(int),CSkillsSelectWnd__SetTypesToDisplay);
#endif
#ifdef CSkillsWnd__CSkillsWnd_x
FUNCTION_AT_ADDRESS( CSkillsWnd::CSkillsWnd(class CXWnd *),CSkillsWnd__CSkillsWnd);
#endif
#ifdef CSkillsWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CSkillsWnd::Activate(void),CSkillsWnd__Activate);
#endif
#ifdef CSkillsWnd__SkillImproveOccurred_x
FUNCTION_AT_ADDRESS(void  CSkillsWnd::SkillImproveOccurred(int),CSkillsWnd__SkillImproveOccurred);
#endif
#ifdef CSkillsWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void  CSkillsWnd::UpdateAll(void),CSkillsWnd__UpdateAll);
#endif
#ifdef CSkillsWnd__UpdateSkill_x
FUNCTION_AT_ADDRESS(void  CSkillsWnd::UpdateSkill(int),CSkillsWnd__UpdateSkill);
#endif
#ifdef CSocialEditWnd__CSocialEditWnd_x
FUNCTION_AT_ADDRESS( CSocialEditWnd::CSocialEditWnd(class CXWnd *),CSocialEditWnd__CSocialEditWnd);
#endif
#ifdef CSocialEditWnd__Init_x
FUNCTION_AT_ADDRESS(void  CSocialEditWnd::Init(void),CSocialEditWnd__Init);
#endif
#ifdef CSocialEditWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CSocialEditWnd::Activate(int),CSocialEditWnd__Activate);
#endif
#ifdef CSocialEditWnd__ClickedAccept_x
FUNCTION_AT_ADDRESS(void  CSocialEditWnd::ClickedAccept(void),CSocialEditWnd__ClickedAccept);
#endif
#ifdef CSocialEditWnd__ClickedClear_x
FUNCTION_AT_ADDRESS(void  CSocialEditWnd::ClickedClear(void),CSocialEditWnd__ClickedClear);
#endif
#ifdef CSocialEditWnd__ClickedTextColorButton_x
FUNCTION_AT_ADDRESS(void  CSocialEditWnd::ClickedTextColorButton(int),CSocialEditWnd__ClickedTextColorButton);
#endif
#ifdef CSocialEditWnd__GetSocialTextColor_x
FUNCTION_AT_ADDRESS(unsigned long  CSocialEditWnd::GetSocialTextColor(int),CSocialEditWnd__GetSocialTextColor);
#endif
#ifdef CSocialEditWnd__UpdateControlsFromSocial_x
FUNCTION_AT_ADDRESS(void  CSocialEditWnd::UpdateControlsFromSocial(void),CSocialEditWnd__UpdateControlsFromSocial);
#endif
#ifdef CSoulmarkWnd__CSoulmarkWnd_x
FUNCTION_AT_ADDRESS( CSoulmarkWnd::CSoulmarkWnd(class CXWnd *),CSoulmarkWnd__CSoulmarkWnd);
#endif
#ifdef CSoulmarkWnd__UpdateSoulmarks_x
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::UpdateSoulmarks(struct soulMarkMsg *),CSoulmarkWnd__UpdateSoulmarks);
#endif
#ifdef CSoulmarkWnd__UpdateList_x
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::UpdateList(void),CSoulmarkWnd__UpdateList);
#endif
#ifdef CSoulmarkWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Activate(void),CSoulmarkWnd__Activate);
#endif
#ifdef CSoulmarkWnd__Activate1_x
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Activate(char *,char *),CSoulmarkWnd__Activate1);
#endif
#ifdef CSoulmarkWnd__SaveMarks_x
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::SaveMarks(void),CSoulmarkWnd__SaveMarks);
#endif
#ifdef CSoulmarkWnd__FillFields_x
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::FillFields(void),CSoulmarkWnd__FillFields);
#endif
#ifdef CSoulmarkWnd__Clear_x
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Clear(void),CSoulmarkWnd__Clear);
#endif
#ifdef CSoulmarkWnd__Inquire_x
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Inquire(char *,char *),CSoulmarkWnd__Inquire);
#endif
#ifdef CSoulmarkWnd__AddMark_x
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::AddMark(int,char *,char *,char *),CSoulmarkWnd__AddMark);
#endif
#ifdef CSoulmarkWnd__Inquire1_x
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Inquire(char *),CSoulmarkWnd__Inquire1);
#endif
#ifdef CSoulmarkWnd__Praise_x
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Praise(char *),CSoulmarkWnd__Praise);
#endif
#ifdef CSoulmarkWnd__Warn_x
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Warn(char *),CSoulmarkWnd__Warn);
#endif
#ifdef CSpellBookWnd__CSpellBookWnd_x
FUNCTION_AT_ADDRESS( CSpellBookWnd::CSpellBookWnd(class CXWnd *),CSpellBookWnd__CSpellBookWnd);
#endif
#ifdef CSpellBookWnd__Init_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::Init(void),CSpellBookWnd__Init);
#endif
#ifdef CSpellBookWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::Activate(void),CSpellBookWnd__Activate);
#endif
#ifdef CSpellBookWnd__GetBookSlot_x
FUNCTION_AT_ADDRESS(int __cdecl CSpellBookWnd::GetBookSlot(int),CSpellBookWnd__GetBookSlot);
#endif
#ifdef CSpellBookWnd__MemorizeSet_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::MemorizeSet(int *,int),CSpellBookWnd__MemorizeSet);
#endif
#ifdef CSpellBookWnd__ContinueSetMem_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::ContinueSetMem(void),CSpellBookWnd__ContinueSetMem);
#endif
#ifdef CSpellBookWnd__DelayedSpellMem_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::DelayedSpellMem(int,int,int),CSpellBookWnd__DelayedSpellMem);
#endif
#ifdef CSpellBookWnd__EndSetMem_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::EndSetMem(void),CSpellBookWnd__EndSetMem);
#endif
#ifdef CSpellBookWnd__AutoMemSpell_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::AutoMemSpell(int,int),CSpellBookWnd__AutoMemSpell);
#endif
#ifdef CSpellBookWnd__HandleLeftClickOnSpell_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::HandleLeftClickOnSpell(int),CSpellBookWnd__HandleLeftClickOnSpell);
#endif
#ifdef CSpellBookWnd__HandleRightClickOnSpell_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::HandleRightClickOnSpell(int),CSpellBookWnd__HandleRightClickOnSpell);
#endif
#ifdef CSpellBookWnd__CanStartMemming_x
FUNCTION_AT_ADDRESS(bool  CSpellBookWnd::CanStartMemming(int),CSpellBookWnd__CanStartMemming);
#endif
#ifdef CSpellBookWnd__StartSpellMemorizationDrag_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::StartSpellMemorizationDrag(int,class CButtonWnd *),CSpellBookWnd__StartSpellMemorizationDrag);
#endif
#ifdef CSpellBookWnd__StartSpellMemorization_x
FUNCTION_AT_ADDRESS(bool  CSpellBookWnd::StartSpellMemorization(int,int,bool),CSpellBookWnd__StartSpellMemorization);
#endif
#ifdef CSpellBookWnd__FinishMemorizing_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::FinishMemorizing(int,int),CSpellBookWnd__FinishMemorizing);
#endif
#ifdef CSpellBookWnd__GetSpellMemTicksLeft_x
FUNCTION_AT_ADDRESS(int  CSpellBookWnd::GetSpellMemTicksLeft(void),CSpellBookWnd__GetSpellMemTicksLeft);
#endif
#ifdef CSpellBookWnd__StartSpellScribe_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::StartSpellScribe(int),CSpellBookWnd__StartSpellScribe);
#endif
#ifdef CSpellBookWnd__FinishScribing_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::FinishScribing(int,int),CSpellBookWnd__FinishScribing);
#endif
#ifdef CSpellBookWnd__GetSpellScribeTicksLeft_x
FUNCTION_AT_ADDRESS(int  CSpellBookWnd::GetSpellScribeTicksLeft(void),CSpellBookWnd__GetSpellScribeTicksLeft);
#endif
#ifdef CSpellBookWnd__SwapSpellBookSlots_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::SwapSpellBookSlots(int,int),CSpellBookWnd__SwapSpellBookSlots);
#endif
#ifdef CSpellBookWnd__HandleSpellInfoDisplay_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::HandleSpellInfoDisplay(class CXWnd *),CSpellBookWnd__HandleSpellInfoDisplay);
#endif
#ifdef CSpellBookWnd__DisplaySpellInfo_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::DisplaySpellInfo(int),CSpellBookWnd__DisplaySpellInfo);
#endif
#ifdef CSpellBookWnd__TurnToPage_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::TurnToPage(int),CSpellBookWnd__TurnToPage);
#endif
#ifdef CSpellBookWnd__UpdateSpellBookDisplay_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::UpdateSpellBookDisplay(void),CSpellBookWnd__UpdateSpellBookDisplay);
#endif
#ifdef CSpellBookWnd__StopSpellBookAction_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::StopSpellBookAction(void),CSpellBookWnd__StopSpellBookAction);
#endif
#ifdef CSpellBookWnd__GetSpellDeletionConfirmation_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::GetSpellDeletionConfirmation(int),CSpellBookWnd__GetSpellDeletionConfirmation);
#endif
#ifdef CSpellBookWnd__RequestSpellDeletion_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::RequestSpellDeletion(int),CSpellBookWnd__RequestSpellDeletion);
#endif
#ifdef CSpellBookWnd__DeleteSpellFromBook_x
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::DeleteSpellFromBook(int,int),CSpellBookWnd__DeleteSpellFromBook);
#endif
#ifdef CXStr__Mid_x
FUNCTION_AT_ADDRESS(class CXStr  CXStr::Mid(int,int)const ,CXStr__Mid);
#endif
#ifdef CTargetRing__Cast_x
FUNCTION_AT_ADDRESS(int CTargetRing::Cast(CVector3 *), CTargetRing__Cast);
#endif
#ifdef CTargetWnd__CTargetWnd_x
FUNCTION_AT_ADDRESS(CTargetWnd::CTargetWnd(class CXWnd *), CTargetWnd__CTargetWnd);
#endif
#ifdef CTargetWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CTargetWnd::Activate(void),CTargetWnd__Activate);
#endif
#ifdef CTargetWnd__GetBuffCaster_x
FUNCTION_AT_ADDRESS(class CXStr *CTargetWnd::GetBuffCaster(int),CTargetWnd__GetBuffCaster);
#endif
#ifdef CTaskWnd__UpdateTaskTimers_x
FUNCTION_AT_ADDRESS(int CTaskWnd::UpdateTaskTimers(unsigned long),CTaskWnd__UpdateTaskTimers);
#endif
#ifdef CTaskManager__GetEntry_x
FUNCTION_AT_ADDRESS(CTaskEntry *CTaskManager::GetEntry(int Index, int System, bool bCheckEmpty), CTaskManager__GetEntry);
#endif
#ifdef CTextEntryWnd__CTextEntryWnd_x
FUNCTION_AT_ADDRESS( CTextEntryWnd::CTextEntryWnd(class CXWnd *),CTextEntryWnd__CTextEntryWnd);
#endif
#ifdef CTextEntryWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CTextEntryWnd::Activate(class CXWnd *,int,char *,int,int,char *),CTextEntryWnd__Activate);
#endif
#ifdef CTextEntryWnd__Callback_x
FUNCTION_AT_ADDRESS(void  CTextEntryWnd::Callback(bool),CTextEntryWnd__Callback);
#endif
#ifdef CTextEntryWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void  CTextEntryWnd::UpdateButtons(void),CTextEntryWnd__UpdateButtons);
#endif
#ifdef CTextEntryWnd__GetEntryText_x
FUNCTION_AT_ADDRESS(class CXStr  CTextEntryWnd::GetEntryText(void),CTextEntryWnd__GetEntryText);
#endif
#ifdef CTimeLeftWnd__CTimeLeftWnd_x
FUNCTION_AT_ADDRESS( CTimeLeftWnd::CTimeLeftWnd(long),CTimeLeftWnd__CTimeLeftWnd);
#endif
#ifdef CTimeLeftWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CTimeLeftWnd::Activate(void),CTimeLeftWnd__Activate);
#endif
#ifdef CTipWnd__CTipWnd_x
FUNCTION_AT_ADDRESS( CTipWnd::CTipWnd(class CXWnd *,int),CTipWnd__CTipWnd);
#endif
#ifdef CTipWnd__Activate_x
FUNCTION_AT_ADDRESS(bool  CTipWnd::Activate(int,bool),CTipWnd__Activate);
#endif
#ifdef CTipWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void  CTipWnd::UpdateButtons(void),CTipWnd__UpdateButtons);
#endif
#ifdef CTipWnd__InitializeTipSettings_x
FUNCTION_AT_ADDRESS(void  CTipWnd::InitializeTipSettings(void),CTipWnd__InitializeTipSettings);
#endif
#ifdef CTipWnd__CleanDayTips_x
FUNCTION_AT_ADDRESS(void  CTipWnd::CleanDayTips(void),CTipWnd__CleanDayTips);
#endif
#ifdef CTipWnd__SelectRandomTip_x
FUNCTION_AT_ADDRESS(int  CTipWnd::SelectRandomTip(void),CTipWnd__SelectRandomTip);
#endif
#ifdef CTipWnd__SetTOTD_x
FUNCTION_AT_ADDRESS(void  CTipWnd::SetTOTD(int),CTipWnd__SetTOTD);
#endif
#ifdef CTipWnd__IsRecentTOTD_x
FUNCTION_AT_ADDRESS(bool  CTipWnd::IsRecentTOTD(int),CTipWnd__IsRecentTOTD);
#endif
#ifdef CTipWnd__AddContextTip_x
FUNCTION_AT_ADDRESS(void  CTipWnd::AddContextTip(int),CTipWnd__AddContextTip);
#endif
#ifdef CTipWnd__ShowHistoryTip_x
FUNCTION_AT_ADDRESS(void  CTipWnd::ShowHistoryTip(int),CTipWnd__ShowHistoryTip);
#endif
#ifdef CTipWnd__LoadINISettings_x
FUNCTION_AT_ADDRESS(void  CTipWnd::LoadINISettings(void),CTipWnd__LoadINISettings);
#endif
#ifdef CTipWnd__LoadDayTips_x
FUNCTION_AT_ADDRESS(void  CTipWnd::LoadDayTips(void),CTipWnd__LoadDayTips);
#endif
#ifdef CTrackingWnd__CTrackingWnd_x
FUNCTION_AT_ADDRESS( CTrackingWnd::CTrackingWnd(class CXWnd *),CTrackingWnd__CTrackingWnd);
#endif
#ifdef CTrackingWnd__Init_x
FUNCTION_AT_ADDRESS(void  CTrackingWnd::Init(void),CTrackingWnd__Init);
#endif
#ifdef CTrackingWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CTrackingWnd::Activate(void),CTrackingWnd__Activate);
#endif
#ifdef CTrackingWnd__NotifyServerOfTrackingTarget_x
FUNCTION_AT_ADDRESS(void  CTrackingWnd::NotifyServerOfTrackingTarget(int),CTrackingWnd__NotifyServerOfTrackingTarget);
#endif
#ifdef CTrackingWnd__UpdateTrackingControls_x
FUNCTION_AT_ADDRESS(void  CTrackingWnd::UpdateTrackingControls(void),CTrackingWnd__UpdateTrackingControls);
#endif
#ifdef CTrackingWnd__GetTrackColor_x
FUNCTION_AT_ADDRESS(unsigned long  CTrackingWnd::GetTrackColor(int),CTrackingWnd__GetTrackColor);
#endif
#ifdef CTrackingWnd__UpdateTrackingList_x
FUNCTION_AT_ADDRESS(void  CTrackingWnd::UpdateTrackingList(bool),CTrackingWnd__UpdateTrackingList);
#endif
#ifdef CTrackingWnd__GenerateTrackingList_x
FUNCTION_AT_ADDRESS(void  CTrackingWnd::GenerateTrackingList(void),CTrackingWnd__GenerateTrackingList);
#endif
#ifdef CTrackingWnd__SetTrackingList_x
FUNCTION_AT_ADDRESS(void  CTrackingWnd::SetTrackingList(struct TrackingHit *,int),CTrackingWnd__SetTrackingList);
#endif
#ifdef CTrackingWnd__DoTrackSort_x
FUNCTION_AT_ADDRESS(void  CTrackingWnd::DoTrackSort(bool),CTrackingWnd__DoTrackSort);
#endif
#ifdef CTrackingWnd__DoTrackFilter_x
FUNCTION_AT_ADDRESS(void  CTrackingWnd::DoTrackFilter(bool),CTrackingWnd__DoTrackFilter);
#endif
#ifdef CTrackingWnd__RemovePlayerFromTracking_x
FUNCTION_AT_ADDRESS(void  CTrackingWnd::RemovePlayerFromTracking(class EQPlayer *),CTrackingWnd__RemovePlayerFromTracking);
#endif
#ifdef CTrackingWnd__RemovePlayerFromTracking1_x
FUNCTION_AT_ADDRESS(void  CTrackingWnd::RemovePlayerFromTracking(int),CTrackingWnd__RemovePlayerFromTracking1);
#endif
#ifdef CTrackingWnd__RemoveFromListWndByData_x
FUNCTION_AT_ADDRESS(void  CTrackingWnd::RemoveFromListWndByData(unsigned int),CTrackingWnd__RemoveFromListWndByData);
#endif
#ifdef CTrackingWnd__GetListIdByData_x
FUNCTION_AT_ADDRESS(int  CTrackingWnd::GetListIdByData(unsigned int),CTrackingWnd__GetListIdByData);
#endif
#ifdef CTradeWnd__CTradeWnd_x
FUNCTION_AT_ADDRESS( CTradeWnd::CTradeWnd(class CXWnd *),CTradeWnd__CTradeWnd);
#endif
#ifdef CTradeWnd__Init_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::Init(void),CTradeWnd__Init);
#endif
#ifdef CTradeWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::Activate(class EQPlayer *,bool),CTradeWnd__Activate);
#endif
#ifdef CTradeWnd__ClickedCancelButton_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::ClickedCancelButton(void),CTradeWnd__ClickedCancelButton);
#endif
#ifdef CTradeWnd__ClickedTradeButton_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::ClickedTradeButton(void),CTradeWnd__ClickedTradeButton);
#endif
#ifdef CTradeWnd__ClickedMoneyButton_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::ClickedMoneyButton(int),CTradeWnd__ClickedMoneyButton);
#endif
#ifdef CTradeWnd__UpdateTradeDisplay_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::UpdateTradeDisplay(void),CTradeWnd__UpdateTradeDisplay);
#endif
#ifdef CTradeWnd__IsMyTradeSlot_x
FUNCTION_AT_ADDRESS(bool  CTradeWnd::IsMyTradeSlot(int,bool *),CTradeWnd__IsMyTradeSlot);
#endif
#ifdef CTradeWnd__TradeItemChanged_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::TradeItemChanged(int,int),CTradeWnd__TradeItemChanged);
#endif
#ifdef CTradeWnd__CompleteTrade_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::CompleteTrade(void),CTradeWnd__CompleteTrade);
#endif
#ifdef CTradeWnd__AddEquipmentToHisTradeArray_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::AddEquipmentToHisTradeArray(class EQ_Equipment *),CTradeWnd__AddEquipmentToHisTradeArray);
#endif
#ifdef CTradeWnd__AddNoteToHisTradeArray_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::AddNoteToHisTradeArray(class EQ_Note *),CTradeWnd__AddNoteToHisTradeArray);
#endif
#ifdef CTradeWnd__AddContainerToHisTradeArray_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::AddContainerToHisTradeArray(class EQ_Container *),CTradeWnd__AddContainerToHisTradeArray);
#endif
#ifdef CTradeWnd__DeleteItemFromHisTradeArray_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::DeleteItemFromHisTradeArray(int),CTradeWnd__DeleteItemFromHisTradeArray);
#endif
#ifdef CTradeWnd__DropItemIntoTrade_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::DropItemIntoTrade(void),CTradeWnd__DropItemIntoTrade);
#endif
#ifdef CTradeWnd__DropMoneyIntoTrade_x
//FUNCTION_AT_ADDRESS(CTradeWnd::DropMoneyIntoTrade(void),CTradeWnd__DropMoneyIntoTrade);
#endif
#ifdef CTradeWnd__SetMyReadyTrade_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::SetMyReadyTrade(bool),CTradeWnd__SetMyReadyTrade);
#endif
#ifdef CTradeWnd__SetHisReadyTrade_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::SetHisReadyTrade(bool),CTradeWnd__SetHisReadyTrade);
#endif
#ifdef CTradeWnd__SetHisMoney_x
FUNCTION_AT_ADDRESS(void  CTradeWnd::SetHisMoney(int,long),CTradeWnd__SetHisMoney);
#endif
#ifdef CTrainWnd__CTrainWnd_x
FUNCTION_AT_ADDRESS( CTrainWnd::CTrainWnd(class CXWnd *),CTrainWnd__CTrainWnd);
#endif
#ifdef CTrainWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CTrainWnd::Activate(void),CTrainWnd__Activate);
#endif
#ifdef CTrainWnd__UpdateRight_x
FUNCTION_AT_ADDRESS(void  CTrainWnd::UpdateRight(void),CTrainWnd__UpdateRight);
#endif
#ifdef CTrainWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void  CTrainWnd::UpdateAll(bool),CTrainWnd__UpdateAll);
#endif
#ifdef CTrainWnd__SkillName_x
FUNCTION_AT_ADDRESS(char *  CTrainWnd::SkillName(int),CTrainWnd__SkillName);
#endif
#ifdef CTrainWnd__SkillValue_x
FUNCTION_AT_ADDRESS(int  CTrainWnd::SkillValue(int),CTrainWnd__SkillValue);
#endif
#ifdef CTrainWnd__SwapSkill_x
FUNCTION_AT_ADDRESS(void  CTrainWnd::SwapSkill(int,int),CTrainWnd__SwapSkill);
#endif
#ifdef CTrainWnd__SortNames_x
FUNCTION_AT_ADDRESS(void  CTrainWnd::SortNames(int),CTrainWnd__SortNames);
#endif
#ifdef CTrainWnd__SortSkill_x
FUNCTION_AT_ADDRESS(void  CTrainWnd::SortSkill(int),CTrainWnd__SortSkill);
#endif
#ifdef CTrainWnd__UpdateSkill_x
FUNCTION_AT_ADDRESS(void  CTrainWnd::UpdateSkill(int),CTrainWnd__UpdateSkill);
#endif
#ifdef CTrainWnd__SkillChanged_x
FUNCTION_AT_ADDRESS(void  CTrainWnd::SkillChanged(int),CTrainWnd__SkillChanged);
#endif
#ifdef CTrainWnd__SetGMData_x
FUNCTION_AT_ADDRESS(void  CTrainWnd::SetGMData(int *,unsigned char *,float),CTrainWnd__SetGMData);
#endif
#ifdef CTrainWnd__Train_x
FUNCTION_AT_ADDRESS(void  CTrainWnd::Train(void),CTrainWnd__Train);
#endif
#ifdef CVideoModesWnd__CVideoModesWnd_x
FUNCTION_AT_ADDRESS( CVideoModesWnd::CVideoModesWnd(class CXWnd *),CVideoModesWnd__CVideoModesWnd);
#endif
#ifdef CVideoModesWnd__Init_x
FUNCTION_AT_ADDRESS(void  CVideoModesWnd::Init(void),CVideoModesWnd__Init);
#endif
#ifdef CVideoModesWnd__Update_x
FUNCTION_AT_ADDRESS(void  CVideoModesWnd::Update(void),CVideoModesWnd__Update);
#endif
#ifdef CVideoModesWnd__UpdateSelection_x
FUNCTION_AT_ADDRESS(void  CVideoModesWnd::UpdateSelection(unsigned int),CVideoModesWnd__UpdateSelection);
#endif
#ifdef CVideoModesWnd__RestoreOldMode_x
FUNCTION_AT_ADDRESS(void  CVideoModesWnd::RestoreOldMode(void),CVideoModesWnd__RestoreOldMode);
#endif
#ifdef CGuild__CGuild_x
FUNCTION_AT_ADDRESS( CGuild::CGuild(void),CGuild__CGuild);
#endif
#ifdef CGuild__GetGuildName_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(char * CGuild::GetGuildName(__int64),CGuild__GetGuildName);
#else
FUNCTION_AT_ADDRESS(char * CGuild::GetGuildName(DWORD), CGuild__GetGuildName);
#endif
#endif
#ifdef CGuild__GetGuildIndex_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(__int64 CGuild::GetGuildIndex(char *),CGuild__GetGuildIndex);
#else
FUNCTION_AT_ADDRESS(int CGuild::GetGuildIndex(char *),CGuild__GetGuildIndex);
#endif
#endif
#ifdef CGuild__ValidGuildName_x
FUNCTION_AT_ADDRESS(bool  CGuild::ValidGuildName(int),CGuild__ValidGuildName);
#endif
#ifdef CGuild__SendPublicCommentChange_x
FUNCTION_AT_ADDRESS(void  CGuild::SendPublicCommentChange(char *,char *),CGuild__SendPublicCommentChange);
#endif
#ifdef CGuild__DemoteMember_x
FUNCTION_AT_ADDRESS(void  CGuild::DemoteMember(class GuildMember *),CGuild__DemoteMember);
#endif
#ifdef CGuild__SetGuildMotd_x
FUNCTION_AT_ADDRESS(void  CGuild::SetGuildMotd(struct guildmotdSet *),CGuild__SetGuildMotd);
#endif
#ifdef CGuild__HandleGuildMessage_x
FUNCTION_AT_ADDRESS(void  CGuild::HandleGuildMessage(struct connection_t *,unsigned __int32,char *,unsigned __int32),CGuild__HandleGuildMessage);
#endif
#ifdef CGuild__InitializeFromDump_x
FUNCTION_AT_ADDRESS(void  CGuild::InitializeFromDump(char *),CGuild__InitializeFromDump);
#endif
#ifdef CGuild__AddGuildMember_x
FUNCTION_AT_ADDRESS(void  CGuild::AddGuildMember(class GuildMember *),CGuild__AddGuildMember);
#endif
#ifdef CGuild__DeleteAllMembers_x
FUNCTION_AT_ADDRESS(void  CGuild::DeleteAllMembers(void),CGuild__DeleteAllMembers);
#endif
#ifdef CGuild__HandleGuildInvite_x
FUNCTION_AT_ADDRESS(void  CGuild::HandleGuildInvite(struct connection_t *,unsigned __int32,char *,unsigned __int32),CGuild__HandleGuildInvite);
#endif
#ifdef CGuild__HandleAddGuildMember_x
FUNCTION_AT_ADDRESS(void  CGuild::HandleAddGuildMember(char *,int),CGuild__HandleAddGuildMember);
#endif
#ifdef CGuild__HandleRemoveGuildMember_x
FUNCTION_AT_ADDRESS(void  CGuild::HandleRemoveGuildMember(char *,int),CGuild__HandleRemoveGuildMember);
#endif
#ifdef CGuild__HandleDeleteGuildResponse_x
FUNCTION_AT_ADDRESS(void  CGuild::HandleDeleteGuildResponse(char *),CGuild__HandleDeleteGuildResponse);
#endif
#ifdef CGuild__UpdatePublicComment_x
FUNCTION_AT_ADDRESS(void  CGuild::UpdatePublicComment(char *),CGuild__UpdatePublicComment);
#endif
#ifdef CGuild__UpdateMemberStatus_x
FUNCTION_AT_ADDRESS(void  CGuild::UpdateMemberStatus(char *),CGuild__UpdateMemberStatus);
#endif
#ifdef CGuild__HandleMemberLevelUpdate_x
FUNCTION_AT_ADDRESS(void  CGuild::HandleMemberLevelUpdate(char *),CGuild__HandleMemberLevelUpdate);
#endif
#ifdef CGuild__UpdateGuildMemberOnWindow_x
FUNCTION_AT_ADDRESS(void  CGuild::UpdateGuildMemberOnWindow(class GuildMember *),CGuild__UpdateGuildMemberOnWindow);
#endif
#ifdef CGuild__ChangeGuildMemberName_x
FUNCTION_AT_ADDRESS(void  CGuild::ChangeGuildMemberName(char *),CGuild__ChangeGuildMemberName);
#endif
#ifdef CGuild__FindMemberByName_x
FUNCTION_AT_ADDRESS(class GuildMember *  CGuild::FindMemberByName(char *),CGuild__FindMemberByName);
#endif
#ifdef GuildMember__GuildMember_x
FUNCTION_AT_ADDRESS( GuildMember::GuildMember(void),GuildMember__GuildMember);
#endif
#ifdef ChannelServerApi__ChannelServerApi_x
FUNCTION_AT_ADDRESS( ChannelServerApi::ChannelServerApi(char *,int,char *,char *,class ChannelServerHandler *,bool,bool,char *),ChannelServerApi__ChannelServerApi);
#endif
#ifdef ChannelServerApi__dChannelServerApi_x
FUNCTION_AT_ADDRESS( ChannelServerApi::~ChannelServerApi(void),ChannelServerApi__dChannelServerApi);
#endif
#ifdef ChannelServerApi__FreeChannelList_x
FUNCTION_AT_ADDRESS(void  ChannelServerApi::FreeChannelList(void),ChannelServerApi__FreeChannelList);
#endif
#ifdef ChannelServerApi__GetStatus_x
//FUNCTION_AT_ADDRESS(enum ChannelServerApi::Status  ChannelServerApi::GetStatus(void),ChannelServerApi__GetStatus);
#endif
#ifdef ChannelServerApi__SendMessageA_x
FUNCTION_AT_ADDRESS(void  ChannelServerApi::SendMessageA(char *),ChannelServerApi__SendMessageA);
#endif
#ifdef ChannelServerApi__SortBuddyList_x
FUNCTION_AT_ADDRESS(void  ChannelServerApi::SortBuddyList(void),ChannelServerApi__SortBuddyList);
#endif
#ifdef UdpManager__Release_x
FUNCTION_AT_ADDRESS(void  UdpManager::Release(void),UdpManager__Release);
#endif
#ifdef ChannelServerApi__SetBuddyStatus_x
//FUNCTION_AT_ADDRESS(void  ChannelServerApi::SetBuddyStatus(char *,enum ChannelServerApi::BuddyStatus),ChannelServerApi__SetBuddyStatus);
#endif
#ifdef UdpConnection__Release_x
FUNCTION_AT_ADDRESS(void  UdpConnection::Release(void),UdpConnection__Release);
#endif
#ifdef ChannelServerApi__GiveTime_x
FUNCTION_AT_ADDRESS(void  ChannelServerApi::GiveTime(void),ChannelServerApi__GiveTime);
#endif
#ifdef ChannelServerApi__GetChannelNumber_x
FUNCTION_AT_ADDRESS(int  ChannelServerApi::GetChannelNumber(char *),ChannelServerApi__GetChannelNumber);
#endif
#ifdef ChannelServerApi__GetChannelName_x
FUNCTION_AT_ADDRESS(char *  ChannelServerApi::GetChannelName(int),ChannelServerApi__GetChannelName);
#endif
#ifdef ChannelServerApi__Strncpy_x
FUNCTION_AT_ADDRESS(char * __cdecl ChannelServerApi::Strncpy(char *,char *,int),ChannelServerApi__Strncpy);
#endif
#ifdef ChannelServerApi__SmartResize_x
FUNCTION_AT_ADDRESS(void * __cdecl ChannelServerApi::SmartResize(void *,int,int),ChannelServerApi__SmartResize);
#endif
#ifdef ChannelServerApi__GetNextField_x
FUNCTION_AT_ADDRESS(int __cdecl ChannelServerApi::GetNextField(char *,int,char * *,char),ChannelServerApi__GetNextField);
#endif
#ifdef CharacterBase__GetMemorizedSpell_x
FUNCTION_AT_ADDRESS(LONG CharacterBase::GetMemorizedSpell(int),CharacterBase__GetMemorizedSpell);
#endif
#ifdef CharacterBase__CreateItemGlobalIndex_x
FUNCTION_AT_ADDRESS(ItemGlobalIndex CharacterBase::CreateItemGlobalIndex(int, int, int), CharacterBase__CreateItemGlobalIndex);
#endif
#ifdef CharacterBase__CreateItemIndex_x
FUNCTION_AT_ADDRESS(ItemIndex CharacterBase::CreateItemIndex(int,int,int), CharacterBase__CreateItemIndex);
#endif
#ifdef CharacterBase__GetItemByGlobalIndex_x
FUNCTION_AT_ADDRESS(VePointer<CONTENTS> CharacterBase::GetItemByGlobalIndex(const ItemGlobalIndex &GlobalIndex) const, CharacterBase__GetItemByGlobalIndex);
#endif
#ifdef CharacterBase__GetItemByGlobalIndex1_x
FUNCTION_AT_ADDRESS(VePointer<CONTENTS> CharacterBase::GetItemByGlobalIndex(const ItemGlobalIndex &GlobalIndex, GILocationOption Option) const, CharacterBase__GetItemByGlobalIndex1);
#endif
#ifdef CharacterBase__GetItemPossession_x
FUNCTION_AT_ADDRESS(VePointer<CONTENTS> CharacterBase::GetItemPossession(const ItemIndex &lIndex) const, CharacterBase__GetItemPossession);
#endif
#ifdef BaseProfile__GetItemPossession_x
FUNCTION_AT_ADDRESS(VePointer<CONTENTS> BaseProfile::GetItemPossession(const ItemIndex &lIndex) const,BaseProfile__GetItemPossession);
#endif
#ifdef ArrayClass__DeleteElement_x
FUNCTION_AT_ADDRESS(void ArrayClass_RO<SListWndColumn_RO>::DeleteElement(int index), ArrayClass__DeleteElement);
#endif
#if !defined(ROF2EMU) && !defined(UFEMU)
#ifdef ItemBase__IsLoreEquipped_x
FUNCTION_AT_ADDRESS(bool ItemBase::IsLoreEquipped(bool bIncludeSockets) const, ItemBase__IsLoreEquipped);
#endif
#endif
#ifdef ItemBase__IsLore_x
FUNCTION_AT_ADDRESS(bool ItemBase::IsLore(bool bIncludeSockets) const, ItemBase__IsLore);
#endif
#ifdef ItemGlobalIndex__IsKeyRingLocation_x
FUNCTION_AT_ADDRESS(bool ItemGlobalIndex::IsKeyRingLocation(void), ItemGlobalIndex__IsKeyRingLocation);
#endif
#ifdef ItemGlobalIndex__IsEquippedLocation_x
FUNCTION_AT_ADDRESS(bool ItemGlobalIndex::IsEquippedLocation(void), ItemGlobalIndex__IsEquippedLocation);
#endif
#ifdef ItemGlobalIndex__IsValidIndex_x
FUNCTION_AT_ADDRESS(bool ItemGlobalIndex::IsValidIndex(void), ItemGlobalIndex__IsValidIndex);
#endif
#ifdef ItemGlobalIndex__ItemGlobalIndex_x
FUNCTION_AT_ADDRESS(ItemGlobalIndex::ItemGlobalIndex(void), ItemGlobalIndex__ItemGlobalIndex);
#endif
#ifdef IconCache__IconCache_x
FUNCTION_AT_ADDRESS( IconCache::IconCache(void),IconCache__IconCache);
#endif
#ifdef IconCache__dIconCache_x
FUNCTION_AT_ADDRESS( IconCache::~IconCache(void),IconCache__dIconCache);
#endif
#ifdef IconCache__GetIcon_x
FUNCTION_AT_ADDRESS(class CTextureAnimation * IconCache::GetIcon(int),IconCache__GetIcon);
#endif
#ifdef JournalNPC__JournalNPC_x
FUNCTION_AT_ADDRESS( JournalNPC::JournalNPC(void),JournalNPC__JournalNPC);
#endif
#ifdef JournalNPC__dJournalNPC_x
FUNCTION_AT_ADDRESS( JournalNPC::~JournalNPC(void),JournalNPC__dJournalNPC);
#endif
#ifdef JournalNPC__AllocateArray_x
FUNCTION_AT_ADDRESS(void  JournalNPC::AllocateArray(void),JournalNPC__AllocateArray);
#endif
#ifdef JournalNPC__CleanEntries_x
FUNCTION_AT_ADDRESS(void  JournalNPC::CleanEntries(void),JournalNPC__CleanEntries);
#endif
#ifdef JournalNPC__GetText_x
FUNCTION_AT_ADDRESS(char * __cdecl JournalNPC::GetText(int),JournalNPC__GetText);
#endif
#ifdef JournalNPC__GetEntry_x
FUNCTION_AT_ADDRESS(struct JournalEntry *  JournalNPC::GetEntry(int),JournalNPC__GetEntry);
#endif
#ifdef JournalNPC__FindEntryByHash_x
FUNCTION_AT_ADDRESS(struct JournalEntry *  JournalNPC::FindEntryByHash(int),JournalNPC__FindEntryByHash);
#endif
#ifdef JournalNPC__FindEntryByCategory_x
FUNCTION_AT_ADDRESS(struct JournalEntry *  JournalNPC::FindEntryByCategory(int,int),JournalNPC__FindEntryByCategory);
#endif
#ifdef JournalNPC__FindThisText_x
FUNCTION_AT_ADDRESS(int  JournalNPC::FindThisText(char *,bool,int),JournalNPC__FindThisText);
#endif
#ifdef JournalNPC__AddEntry_x
FUNCTION_AT_ADDRESS(int  JournalNPC::AddEntry(long,float,float,float,int,int),JournalNPC__AddEntry);
#endif
#ifdef JournalNPC__AddEntry1_x
FUNCTION_AT_ADDRESS(int  JournalNPC::AddEntry(long,float,float,float,char *,int),JournalNPC__AddEntry1);
#endif
#ifdef JournalNPC__DeleteEntryByIndex_x
FUNCTION_AT_ADDRESS(int  JournalNPC::DeleteEntryByIndex(int),JournalNPC__DeleteEntryByIndex);
#endif
#ifdef JournalNPC__DeleteEntryByHash_x
FUNCTION_AT_ADDRESS(int  JournalNPC::DeleteEntryByHash(int),JournalNPC__DeleteEntryByHash);
#endif
#ifdef JournalNPC__ConvertCategory_x
FUNCTION_AT_ADDRESS(void  JournalNPC::ConvertCategory(int,int),JournalNPC__ConvertCategory);
#endif
#ifdef JournalNPC__ComputeLatestTime_x
FUNCTION_AT_ADDRESS(void  JournalNPC::ComputeLatestTime(void),JournalNPC__ComputeLatestTime);
#endif
#ifdef ConversationJournal__ConversationJournal_x
FUNCTION_AT_ADDRESS( ConversationJournal::ConversationJournal(void),ConversationJournal__ConversationJournal);
#endif
#ifdef ConversationJournal__dConversationJournal_x
FUNCTION_AT_ADDRESS( ConversationJournal::~ConversationJournal(void),ConversationJournal__dConversationJournal);
#endif
#ifdef ConversationJournal__Clean_x
FUNCTION_AT_ADDRESS(void  ConversationJournal::Clean(void),ConversationJournal__Clean);
#endif
#ifdef ConversationJournal__AllocateNPCArray_x
FUNCTION_AT_ADDRESS(void  ConversationJournal::AllocateNPCArray(void),ConversationJournal__AllocateNPCArray);
#endif
#ifdef ConversationJournal__AllocateCatArray_x
FUNCTION_AT_ADDRESS(void  ConversationJournal::AllocateCatArray(void),ConversationJournal__AllocateCatArray);
#endif
#ifdef ConversationJournal__GetNPC_x
FUNCTION_AT_ADDRESS(class JournalNPC *  ConversationJournal::GetNPC(int),ConversationJournal__GetNPC);
#endif
#ifdef ConversationJournal__FindNPCByNameZone_x
FUNCTION_AT_ADDRESS(class JournalNPC *  ConversationJournal::FindNPCByNameZone(char *,int),ConversationJournal__FindNPCByNameZone);
#endif
#ifdef ConversationJournal__DeleteNPC_x
FUNCTION_AT_ADDRESS(int  ConversationJournal::DeleteNPC(char *,int),ConversationJournal__DeleteNPC);
#endif
#ifdef ConversationJournal__AddNPC_x
FUNCTION_AT_ADDRESS(class JournalNPC *  ConversationJournal::AddNPC(char *,int),ConversationJournal__AddNPC);
#endif
#ifdef ConversationJournal__AddEntry_x
FUNCTION_AT_ADDRESS(int  ConversationJournal::AddEntry(char *,int,long,float,float,float,char *,int),ConversationJournal__AddEntry);
#endif
#ifdef ConversationJournal__AddCategory_x
FUNCTION_AT_ADDRESS(struct JournalCategory *  ConversationJournal::AddCategory(int),ConversationJournal__AddCategory);
#endif
#ifdef ConversationJournal__FindFreeID_x
FUNCTION_AT_ADDRESS(int  ConversationJournal::FindFreeID(void),ConversationJournal__FindFreeID);
#endif
#ifdef ConversationJournal__AddCategory1_x
FUNCTION_AT_ADDRESS(struct JournalCategory *  ConversationJournal::AddCategory(char *,char *,int),ConversationJournal__AddCategory1);
#endif
#ifdef ConversationJournal__DeleteCategory_x
FUNCTION_AT_ADDRESS(void  ConversationJournal::DeleteCategory(int),ConversationJournal__DeleteCategory);
#endif
#ifdef ConversationJournal__GetCategory_x
FUNCTION_AT_ADDRESS(struct JournalCategory *  ConversationJournal::GetCategory(int),ConversationJournal__GetCategory);
#endif
#ifdef ConversationJournal__GetCategory1_x
FUNCTION_AT_ADDRESS(struct JournalCategory *  ConversationJournal::GetCategory(char *),ConversationJournal__GetCategory1);
#endif
#ifdef ConversationJournal__GetCategoryList_x
FUNCTION_AT_ADDRESS(struct JournalCategory * *  ConversationJournal::GetCategoryList(void),ConversationJournal__GetCategoryList);
#endif
#ifdef ConversationJournal__Save_x
FUNCTION_AT_ADDRESS(int  ConversationJournal::Save(char *),ConversationJournal__Save);
#endif
#ifdef ConversationJournal__Load_x
FUNCTION_AT_ADDRESS(int  ConversationJournal::Load(char *),ConversationJournal__Load);
#endif
#ifdef ConversationJournal__ReadCategory_x
FUNCTION_AT_ADDRESS(void  ConversationJournal::ReadCategory(struct _iobuf *),ConversationJournal__ReadCategory);
#endif
#ifdef JournalNPC__ReadEntry_x
FUNCTION_AT_ADDRESS(int  JournalNPC::ReadEntry(struct _iobuf *),JournalNPC__ReadEntry);
#endif
#ifdef ConversationJournal__ReadNPC_x
FUNCTION_AT_ADDRESS(class JournalNPC *  ConversationJournal::ReadNPC(struct _iobuf *),ConversationJournal__ReadNPC);
#endif
#ifdef CRaid__CRaid_x
FUNCTION_AT_ADDRESS( CRaid::CRaid(void),CRaid__CRaid);
#endif
#ifdef CRaid__HandleS2CRaidMessage_x
FUNCTION_AT_ADDRESS(void  CRaid::HandleS2CRaidMessage(char *),CRaid__HandleS2CRaidMessage);
#endif
#ifdef CRaid__HandleC2SRaidMessage_x
FUNCTION_AT_ADDRESS(void  CRaid::HandleC2SRaidMessage(char *),CRaid__HandleC2SRaidMessage);
#endif
#ifdef CRaid__IsInRaid_x
FUNCTION_AT_ADDRESS(bool  CRaid::IsInRaid(void),CRaid__IsInRaid);
#endif
#ifdef CRaid__IsInvited_x
FUNCTION_AT_ADDRESS(bool  CRaid::IsInvited(void),CRaid__IsInvited);
#endif
#ifdef CRaid__ClearInvitedState_x
FUNCTION_AT_ADDRESS(void  CRaid::ClearInvitedState(void),CRaid__ClearInvitedState);
#endif
#ifdef CRaid__IsRaidLeader_x
FUNCTION_AT_ADDRESS(bool  CRaid::IsRaidLeader(void),CRaid__IsRaidLeader);
#endif
#ifdef CRaid__IsRaidGroupLeader_x
FUNCTION_AT_ADDRESS(bool  CRaid::IsRaidGroupLeader(void),CRaid__IsRaidGroupLeader);
#endif
#ifdef CRaid__SetTargetRaidPlayer_x
FUNCTION_AT_ADDRESS(void  CRaid::SetTargetRaidPlayer(char *),CRaid__SetTargetRaidPlayer);
#endif
#ifdef CRaid__InitializeRaid_x
FUNCTION_AT_ADDRESS(void  CRaid::InitializeRaid(char *),CRaid__InitializeRaid);
#endif
#ifdef CRaid__RaidCreated_x
FUNCTION_AT_ADDRESS(void  CRaid::RaidCreated(struct CreateRaidMessage *),CRaid__RaidCreated);
#endif
#ifdef CRaid__AddRaidMember_x
FUNCTION_AT_ADDRESS(void  CRaid::AddRaidMember(struct RaidAddMember *),CRaid__AddRaidMember);
#endif
#ifdef CRaid__DeleteRaidMember_x
FUNCTION_AT_ADDRESS(void  CRaid::DeleteRaidMember(struct SCRaidMessage *),CRaid__DeleteRaidMember);
#endif
#ifdef CRaid__ChangeLeadership_x
FUNCTION_AT_ADDRESS(void  CRaid::ChangeLeadership(char *),CRaid__ChangeLeadership);
#endif
#ifdef CRaid__RenameMember_x
FUNCTION_AT_ADDRESS(void  CRaid::RenameMember(struct RenameRaidMember *),CRaid__RenameMember);
#endif
#ifdef CRaid__HandlePositionChange_x
FUNCTION_AT_ADDRESS(void  CRaid::HandlePositionChange(struct SCRaidMessage *),CRaid__HandlePositionChange);
#endif
#ifdef CRaid__RaidGroupLeaderChange_x
FUNCTION_AT_ADDRESS(void  CRaid::RaidGroupLeaderChange(struct SCRaidMessage *),CRaid__RaidGroupLeaderChange);
#endif
#ifdef CRaid__SetLootTypeResponse_x
FUNCTION_AT_ADDRESS(void  CRaid::SetLootTypeResponse(struct SCRaidMessage *),CRaid__SetLootTypeResponse);
#endif
#ifdef CRaid__HandleSetLootType_x
FUNCTION_AT_ADDRESS(void  CRaid::HandleSetLootType(int),CRaid__HandleSetLootType);
#endif
#ifdef CRaid__HandleAddLooter_x
FUNCTION_AT_ADDRESS(void  CRaid::HandleAddLooter(char *),CRaid__HandleAddLooter);
#endif
#ifdef UdpMisc__GetValue32_x
FUNCTION_AT_ADDRESS(unsigned int __cdecl UdpMisc::GetValue32(void const *),UdpMisc__GetValue32);
#endif
#ifdef Util__GetValue32_x
//FUNCTION_AT_ADDRESS(unsigned int __cdecl Util::GetValue32(void const *),Util__GetValue32);
#endif
#ifdef CRaid__HandleRemoveLooter_x
FUNCTION_AT_ADDRESS(void  CRaid::HandleRemoveLooter(char *),CRaid__HandleRemoveLooter);
#endif
#ifdef CRaid__CreateInviteRaid_x
FUNCTION_AT_ADDRESS(void  CRaid::CreateInviteRaid(void),CRaid__CreateInviteRaid);
#endif
#ifdef CRaid__SendInviteResponse_x
FUNCTION_AT_ADDRESS(void  CRaid::SendInviteResponse(bool),CRaid__SendInviteResponse);
#endif
#ifdef CRaid__SendLeadershipChange_x
FUNCTION_AT_ADDRESS(void  CRaid::SendLeadershipChange(char *),CRaid__SendLeadershipChange);
#endif
#ifdef CRaid__RemoveRaidMember_x
FUNCTION_AT_ADDRESS(void  CRaid::RemoveRaidMember(void),CRaid__RemoveRaidMember);
#endif
#ifdef CRaid__SetLootType_x
FUNCTION_AT_ADDRESS(void  CRaid::SetLootType(char *),CRaid__SetLootType);
#endif
#ifdef CRaid__GetLootType_x
FUNCTION_AT_ADDRESS(int  CRaid::GetLootType(void),CRaid__GetLootType);
#endif
#ifdef CRaid__AddRaidLooter_x
FUNCTION_AT_ADDRESS(void  CRaid::AddRaidLooter(void),CRaid__AddRaidLooter);
#endif
#ifdef CRaid__RemoveRaidLooter_x
FUNCTION_AT_ADDRESS(void  CRaid::RemoveRaidLooter(void),CRaid__RemoveRaidLooter);
#endif
#ifdef CRaid__SendRaidChat_x
FUNCTION_AT_ADDRESS(void  CRaid::SendRaidChat(char *),CRaid__SendRaidChat);
#endif
#ifdef CRaid__ResetWindow_x
FUNCTION_AT_ADDRESS(void  CRaid::ResetWindow(void),CRaid__ResetWindow);
#endif
#ifdef CRaid__UpdateClassColor_x
FUNCTION_AT_ADDRESS(void  CRaid::UpdateClassColor(int,unsigned long),CRaid__UpdateClassColor);
#endif
#ifdef CRaid__HandleCreateInviteRaid_x
FUNCTION_AT_ADDRESS(void  CRaid::HandleCreateInviteRaid(struct CSRaidMessage *),CRaid__HandleCreateInviteRaid);
#endif
#ifdef CRaid__GetNumRaidMembers_x
FUNCTION_AT_ADDRESS(int  CRaid::GetNumRaidMembers(void),CRaid__GetNumRaidMembers);
#endif
#ifdef CRaid__GetRaidMemberAt_x
FUNCTION_AT_ADDRESS(struct RaidMember *  CRaid::GetRaidMemberAt(int),CRaid__GetRaidMemberAt);
#endif
#ifdef CRaid__SetRaidLeader_x
FUNCTION_AT_ADDRESS(void  CRaid::SetRaidLeader(char *),CRaid__SetRaidLeader);
#endif
#ifdef CRaid__FindPlayerIndex_x
FUNCTION_AT_ADDRESS(int  CRaid::FindPlayerIndex(char *),CRaid__FindPlayerIndex);
#endif
#ifdef CRaid__IsRaidMember_x
FUNCTION_AT_ADDRESS(bool  CRaid::IsRaidMember(char *),CRaid__IsRaidMember);
#endif
#ifdef CRaid__FindOpenIndex_x
FUNCTION_AT_ADDRESS(int  CRaid::FindOpenIndex(void),CRaid__FindOpenIndex);
#endif
#ifdef CRaid__FindRaidGroupLeader_x
FUNCTION_AT_ADDRESS(int  CRaid::FindRaidGroupLeader(int),CRaid__FindRaidGroupLeader);
#endif
#ifdef CRaid__ResetRaid_x
FUNCTION_AT_ADDRESS(void  CRaid::ResetRaid(void),CRaid__ResetRaid);
#endif
#ifdef CRaid__DetermineRaidChanges_x
FUNCTION_AT_ADDRESS(void  CRaid::DetermineRaidChanges(char *),CRaid__DetermineRaidChanges);
#endif
#ifdef CRaid__SendRaidMsg_x
FUNCTION_AT_ADDRESS(void  CRaid::SendRaidMsg(int,char *,char *,int),CRaid__SendRaidMsg);
#endif
#ifdef CRaid__UpdateOptionsWindow_x
FUNCTION_AT_ADDRESS(void  CRaid::UpdateOptionsWindow(void),CRaid__UpdateOptionsWindow);
#endif
#ifdef CRaid__IsRaidLooter_x
FUNCTION_AT_ADDRESS(bool  CRaid::IsRaidLooter(char *),CRaid__IsRaidLooter);
#endif
#ifdef CRaid__UpdateLevelAverage_x
FUNCTION_AT_ADDRESS(void  CRaid::UpdateLevelAverage(void),CRaid__UpdateLevelAverage);
#endif
#ifdef CDisplay__CDisplay_x
FUNCTION_AT_ADDRESS( CDisplay::CDisplay(struct HWND__ *),CDisplay__CDisplay);
#endif
#ifdef CDisplay__dCDisplay_x
FUNCTION_AT_ADDRESS( CDisplay::~CDisplay(void),CDisplay__dCDisplay);
#endif
#ifdef CDisplay__ResetRenderWindow_x
FUNCTION_AT_ADDRESS(void  CDisplay::ResetRenderWindow(void),CDisplay__ResetRenderWindow);
#endif
#ifdef CDisplay__SetCCreateCamera_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetCCreateCamera(int),CDisplay__SetCCreateCamera);
#endif
#ifdef CDisplay__SetBoneSpriteTint_x
FUNCTION_AT_ADDRESS(int  CDisplay::SetBoneSpriteTint(struct T3D_DAG *,struct T3D_RGB *),CDisplay__SetBoneSpriteTint);
#endif
#ifdef CDisplay__ReplaceMaterial_x
FUNCTION_AT_ADDRESS(int  CDisplay::ReplaceMaterial(char *,char *,struct T3D_HIERARCHICALSPRITEINSTANCE *,struct T3D_RGB *,int),CDisplay__ReplaceMaterial);
#endif
#ifdef CDisplay__ReplaceCloakMaterials_x
FUNCTION_AT_ADDRESS(int  CDisplay::ReplaceCloakMaterials(int,struct T3D_HIERARCHICALSPRITEINSTANCE *,struct T3D_RGB *),CDisplay__ReplaceCloakMaterials);
#endif
#ifdef CDisplay__InitEverQuestLocale_x
//FUNCTION_AT_ADDRESS(void  CDisplay::InitEverQuestLocale(enum EQLocalize::languages),CDisplay__InitEverQuestLocale);
#endif
#ifdef CDisplay__ReloadUI_x
FUNCTION_AT_ADDRESS(void  CDisplay::ReloadUI(bool),CDisplay__ReloadUI);
#endif
#ifdef CDisplay__HandleMaterial_x
FUNCTION_AT_ADDRESS(void  CDisplay::HandleMaterial(class EQ_PC *,int,class EQ_Item *,class EQ_Item *),CDisplay__HandleMaterial);
#endif
#ifdef CDisplay__FixHeading_x
FUNCTION_AT_ADDRESS(float  CDisplay::FixHeading(float),CDisplay__FixHeading);
#endif
#ifdef CDisplay__GetFloorHeight_x
FUNCTION_AT_ADDRESS(float CDisplay::GetFloorHeight(float, float, float, float, CVector3&, CActorApplicationData*, EActorType, float), CDisplay__GetFloorHeight);
#endif
#ifdef CDisplay__HeadingDiff_x
FUNCTION_AT_ADDRESS(float  CDisplay::HeadingDiff(float,float,float *),CDisplay__HeadingDiff);
#endif
#ifdef CDisplay__DeleteParticleCloudInstance_x
FUNCTION_AT_ADDRESS(void  CDisplay::DeleteParticleCloudInstance(struct T3D_PARTICLECLOUDINSTANCE * *),CDisplay__DeleteParticleCloudInstance);
#endif
#ifdef CDisplay__ProcessParticleEmitter_x
FUNCTION_AT_ADDRESS(void  CDisplay::ProcessParticleEmitter(class EQSwitch *),CDisplay__ProcessParticleEmitter);
#endif
#ifdef CDisplay__SlideSwitchLeftRight_x
FUNCTION_AT_ADDRESS(bool  CDisplay::SlideSwitchLeftRight(class EQSwitch *,float,int,float),CDisplay__SlideSwitchLeftRight);
#endif
#ifdef CDisplay__ProcessSwitches_x
FUNCTION_AT_ADDRESS(void  CDisplay::ProcessSwitches(void),CDisplay__ProcessSwitches);
#endif
#ifdef CDisplay__default_cameras_x
FUNCTION_AT_ADDRESS(void  CDisplay::default_cameras(void),CDisplay__default_cameras);
#endif
#ifdef CDisplay__is_3dON_x
FUNCTION_AT_ADDRESS(int  CDisplay::is_3dON(void),CDisplay__is_3dON);
#endif
#ifdef CDisplay__is_ParticleSystemON_x
FUNCTION_AT_ADDRESS(int  CDisplay::is_ParticleSystemON(void),CDisplay__is_ParticleSystemON);
#endif
#ifdef CDisplay__InitCommonLights_x
FUNCTION_AT_ADDRESS(void  CDisplay::InitCommonLights(void),CDisplay__InitCommonLights);
#endif
#ifdef CDisplay__GetNewPCIniFlag_x
FUNCTION_AT_ADDRESS(int  CDisplay::GetNewPCIniFlag(int,int),CDisplay__GetNewPCIniFlag);
#endif
#ifdef CDisplay__ShouldLoadNewPcModel_x
FUNCTION_AT_ADDRESS(int  CDisplay::ShouldLoadNewPcModel(int,int),CDisplay__ShouldLoadNewPcModel);
#endif
#ifdef CDisplay__GetIniRaceName_x
FUNCTION_AT_ADDRESS(char *  CDisplay::GetIniRaceName(int),CDisplay__GetIniRaceName);
#endif
#ifdef CDisplay__InitWorld_x
FUNCTION_AT_ADDRESS(void  CDisplay::InitWorld(void),CDisplay__InitWorld);
#endif
#ifdef CDisplay__InitDDraw_x
FUNCTION_AT_ADDRESS(void  CDisplay::InitDDraw(void),CDisplay__InitDDraw);
#endif
#ifdef CDisplay__InitNewUI_x
FUNCTION_AT_ADDRESS(void  CDisplay::InitNewUI(void),CDisplay__InitNewUI);
#endif
#ifdef CXWndDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(class CXWndDrawTemplate &  CXWndDrawTemplate::operator=(class CXWndDrawTemplate const &),CXWndDrawTemplate__operator_equal);
#endif
#ifdef CButtonDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(class CButtonDrawTemplate &  CButtonDrawTemplate::operator=(class CButtonDrawTemplate const &),CButtonDrawTemplate__operator_equal);
#endif
#ifdef CScrollbarTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(class CScrollbarTemplate &  CScrollbarTemplate::operator=(class CScrollbarTemplate const &),CScrollbarTemplate__operator_equal);
#endif
#ifdef CTAFrameDraw__operator_equal_x
FUNCTION_AT_ADDRESS(class CTAFrameDraw &  CTAFrameDraw::operator=(class CTAFrameDraw const &),CTAFrameDraw__operator_equal);
#endif
#ifdef CDisplay__InitCharSelectUI_x
FUNCTION_AT_ADDRESS(void  CDisplay::InitCharSelectUI(void),CDisplay__InitCharSelectUI);
#endif
#ifdef CDisplay__InitGameUI_x
FUNCTION_AT_ADDRESS(void  CDisplay::InitGameUI(void),CDisplay__InitGameUI);
#endif
#ifdef CDisplay__CleanCharSelectUI_x
FUNCTION_AT_ADDRESS(void  CDisplay::CleanCharSelectUI(void),CDisplay__CleanCharSelectUI);
#endif
#ifdef CDisplay__CleanGameUI_x
FUNCTION_AT_ADDRESS(void  CDisplay::CleanGameUI(void),CDisplay__CleanGameUI);
#endif
#ifdef CDisplay__CleanUpNewUI_x
FUNCTION_AT_ADDRESS(void  CDisplay::CleanUpNewUI(void),CDisplay__CleanUpNewUI);
#endif
#ifdef CDisplay__ActivateMainUI_x
FUNCTION_AT_ADDRESS(void  CDisplay::ActivateMainUI(bool),CDisplay__ActivateMainUI);
#endif
#ifdef CDisplay__DeactivateMainUI_x
FUNCTION_AT_ADDRESS(void  CDisplay::DeactivateMainUI(void),CDisplay__DeactivateMainUI);
#endif
#ifdef CDisplay__NewUIProcessEscape_x
FUNCTION_AT_ADDRESS(void  CDisplay::NewUIProcessEscape(void),CDisplay__NewUIProcessEscape);
#endif
#ifdef CDisplay__KeyMapUpdated_x
FUNCTION_AT_ADDRESS(void  CDisplay::KeyMapUpdated(void),CDisplay__KeyMapUpdated);
#endif
#ifdef CDisplay__GetWorldFilePath_x
FUNCTION_AT_ADDRESS(bool const  CDisplay::GetWorldFilePath(char *,char const *),CDisplay__GetWorldFilePath);
#endif
#ifdef CDisplay__LoadWorldFile_x
FUNCTION_AT_ADDRESS(unsigned char  CDisplay::LoadWorldFile(char *,char *,int,unsigned char),CDisplay__LoadWorldFile);
#endif
#ifdef CDisplay__LoadNPCFromS3D_x
FUNCTION_AT_ADDRESS(unsigned char  CDisplay::LoadNPCFromS3D(char *,char *,char *),CDisplay__LoadNPCFromS3D);
#endif
#ifdef CDisplay__LoadBMPFile_x
FUNCTION_AT_ADDRESS(unsigned char  CDisplay::LoadBMPFile(void),CDisplay__LoadBMPFile);
#endif
#ifdef CDisplay__StartWorldDisplay_x
//FUNCTION_AT_ADDRESS(void  CDisplay::StartWorldDisplay(enum EQZoneIndex),CDisplay__StartWorldDisplay);
#endif
#ifdef CDisplay__StartWorldDisplay_Bailout_x
FUNCTION_AT_ADDRESS(void  CDisplay::StartWorldDisplay_Bailout(char const *),CDisplay__StartWorldDisplay_Bailout);
#endif
#ifdef CDisplay__StopWorldDisplay_x
FUNCTION_AT_ADDRESS(void  CDisplay::StopWorldDisplay(void),CDisplay__StopWorldDisplay);
#endif
#ifdef CDisplay__SetGammaCorrection_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetGammaCorrection(float),CDisplay__SetGammaCorrection);
#endif
#ifdef CDisplay__SetPCloudDensity_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetPCloudDensity(int),CDisplay__SetPCloudDensity);
#endif
#ifdef CDisplay__CleanUpDDraw_x
FUNCTION_AT_ADDRESS(void  CDisplay::CleanUpDDraw(void),CDisplay__CleanUpDDraw);
#endif
#ifdef CDisplay__IsShield_x
FUNCTION_AT_ADDRESS(unsigned int  CDisplay::IsShield(int)const ,CDisplay__IsShield);
#endif
#ifdef CDisplay__GetItemType_x
FUNCTION_AT_ADDRESS(int  CDisplay::GetItemType(int),CDisplay__GetItemType);
#endif
#ifdef CDisplay__GetUserDefinedColor_x
FUNCTION_AT_ADDRESS(unsigned long __cdecl CDisplay::GetUserDefinedColor(int),CDisplay__GetUserDefinedColor);
#endif
#ifdef CDisplay__SetUserDefinedColor_x
FUNCTION_AT_ADDRESS(void __cdecl CDisplay::SetUserDefinedColor(int,int,int,int),CDisplay__SetUserDefinedColor);
#endif
#ifdef CDisplay__InitUserDefinedColors_x
FUNCTION_AT_ADDRESS(void  CDisplay::InitUserDefinedColors(void),CDisplay__InitUserDefinedColors);
#endif
#ifdef CDisplay__WriteTextHD2_x
FUNCTION_AT_ADDRESS(int __cdecl CDisplay::WriteTextHD2(char const *,int,int,int),CDisplay__WriteTextHD2);
#endif
#ifdef CXWndManager__GetDisplayWidth_x
FUNCTION_AT_ADDRESS(unsigned __int32  CXWndManager::GetDisplayWidth(void)const ,CXWndManager__GetDisplayWidth);
#endif
#ifdef CXWndManager__GetFont_x
FUNCTION_AT_ADDRESS(class CTextureFont *  CXWndManager::GetFont(int)const ,CXWndManager__GetFont);
#endif
#ifdef CDisplay__SetActorScaleFactor_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetActorScaleFactor(struct T3D_tagACTORINSTANCE *,float,unsigned char),CDisplay__SetActorScaleFactor);
#endif
#ifdef CDisplay__ShowDisplay_x
FUNCTION_AT_ADDRESS(void  CDisplay::ShowDisplay(void),CDisplay__ShowDisplay);
#endif
#ifdef CDisplay__CheckForScreenModeToggle_x
FUNCTION_AT_ADDRESS(void  CDisplay::CheckForScreenModeToggle(void),CDisplay__CheckForScreenModeToggle);
#endif
#ifdef CDisplay__Render_World_x
FUNCTION_AT_ADDRESS(void  CDisplay::Render_World(void),CDisplay__Render_World);
#endif
#ifdef CDisplay__SetSpecialEnvironment_x
//FUNCTION_AT_ADDRESS(void  CDisplay::SetSpecialEnvironment(enum EnvironmentType),CDisplay__SetSpecialEnvironment);
#endif
#ifdef CDisplay__SetGenericEnvironment_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetGenericEnvironment(void),CDisplay__SetGenericEnvironment);
#endif
#ifdef CDisplay__SetupEmitterEnvironment_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetupEmitterEnvironment(void),CDisplay__SetupEmitterEnvironment);
#endif
#ifdef CDisplay__UpdateMobileEmitterLocations_x
FUNCTION_AT_ADDRESS(void  CDisplay::UpdateMobileEmitterLocations(void),CDisplay__UpdateMobileEmitterLocations);
#endif
#ifdef CDisplay__RealRender_World_x
FUNCTION_AT_ADDRESS(void  CDisplay::RealRender_World(void),CDisplay__RealRender_World);
#endif
#ifdef CDisplay__Render_MinWorld_x
FUNCTION_AT_ADDRESS(void  CDisplay::Render_MinWorld(void),CDisplay__Render_MinWorld);
#endif
#ifdef CDisplay__StartWeather_x
FUNCTION_AT_ADDRESS(void  CDisplay::StartWeather(int,unsigned char),CDisplay__StartWeather);
#endif
#ifdef CDisplay__ProcessWeather_x
FUNCTION_AT_ADDRESS(void  CDisplay::ProcessWeather(void),CDisplay__ProcessWeather);
#endif
#ifdef CDisplay__StopWeather_x
FUNCTION_AT_ADDRESS(void  CDisplay::StopWeather(int,unsigned char),CDisplay__StopWeather);
#endif
#ifdef CDisplay__LightningStrike_x
FUNCTION_AT_ADDRESS(void  CDisplay::LightningStrike(void),CDisplay__LightningStrike);
#endif
#ifdef CDisplay__GetNearestPlayerInView_x
FUNCTION_AT_ADDRESS(class EQPlayer *  CDisplay::GetNearestPlayerInView(float,bool),CDisplay__GetNearestPlayerInView);
#endif
#ifdef CDisplay__ProcessEffects_x
FUNCTION_AT_ADDRESS(void  CDisplay::ProcessEffects(void),CDisplay__ProcessEffects);
#endif
#ifdef CDisplay__ProcessCloud_x
FUNCTION_AT_ADDRESS(void  CDisplay::ProcessCloud(void),CDisplay__ProcessCloud);
#endif
#ifdef CDisplay__DDrawUpdateDisplay_x
FUNCTION_AT_ADDRESS(void  CDisplay::DDrawUpdateDisplay(void),CDisplay__DDrawUpdateDisplay);
#endif
#ifdef CDisplay__SetViewActor_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetViewActor(struct T3D_tagACTORINSTANCE *),CDisplay__SetViewActor);
#endif
#ifdef CDisplay__SetRenderWindow_x
FUNCTION_AT_ADDRESS(void CDisplay::SetRenderWindow(int mode),CDisplay__SetRenderWindow);
#endif
#ifdef CDisplay__ToggleScreenshotMode_x
FUNCTION_AT_ADDRESS(void CDisplay::ToggleScreenshotMode(void),CDisplay__ToggleScreenshotMode);
#endif
#ifdef CDisplay__SwitchToDefaultCameraMode_x
FUNCTION_AT_ADDRESS(void  CDisplay::SwitchToDefaultCameraMode(void),CDisplay__SwitchToDefaultCameraMode);
#endif
#ifdef CDisplay__SetYon_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetYon(float),CDisplay__SetYon);
#endif
#ifdef CDisplay__SetActorYon_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetActorYon(float),CDisplay__SetActorYon);
#endif
#ifdef CDisplay__SetViewAngle_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetViewAngle(int),CDisplay__SetViewAngle);
#endif
#ifdef CDisplay__UpdateCameraAfterModeSwitch_x
FUNCTION_AT_ADDRESS(void  CDisplay::UpdateCameraAfterModeSwitch(void),CDisplay__UpdateCameraAfterModeSwitch);
#endif
#ifdef CDisplay__ChangeVideoMode_x
FUNCTION_AT_ADDRESS(void  CDisplay::ChangeVideoMode(void),CDisplay__ChangeVideoMode);
#endif
#ifdef CDisplay__ToggleView_x
FUNCTION_AT_ADDRESS(void  CDisplay::ToggleView(void),CDisplay__ToggleView);
#endif
#ifdef CDisplay__SetFog_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetFog(bool,float,float,unsigned char,unsigned char,unsigned char),CDisplay__SetFog);
#endif
#ifdef CDisplay__ClearScreen_x
FUNCTION_AT_ADDRESS(void  CDisplay::ClearScreen(void),CDisplay__ClearScreen);
#endif
#ifdef CDisplay__CreatePlayerActor_x
FUNCTION_AT_ADDRESS(void  CDisplay::CreatePlayerActor(class EQPlayer *),CDisplay__CreatePlayerActor);
#endif
#ifdef CDisplay__SetActorUserData_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetActorUserData(struct T3D_tagACTORINSTANCE *,void *),CDisplay__SetActorUserData);
#endif
#ifdef CDisplay__CreateLight_x
FUNCTION_AT_ADDRESS(struct T3D_POINTLIGHT *  CDisplay::CreateLight(unsigned char,float,float,float,float),CDisplay__CreateLight);
#endif
#ifdef CDisplay__GetIntensity_x
FUNCTION_AT_ADDRESS(unsigned char  CDisplay::GetIntensity(unsigned char),CDisplay__GetIntensity);
#endif
#ifdef CDisplay__DeleteLight_x
FUNCTION_AT_ADDRESS(void  CDisplay::DeleteLight(struct T3D_POINTLIGHT *),CDisplay__DeleteLight);
#endif
#ifdef CDisplay__PlaySoundAtLocation_x
FUNCTION_AT_ADDRESS(void  CDisplay::PlaySoundAtLocation(float,float,float,int),CDisplay__PlaySoundAtLocation);
#endif
#ifdef CDisplay__SetUserRender_x
FUNCTION_AT_ADDRESS(long  CDisplay::SetUserRender(int),CDisplay__SetUserRender);
#endif
#ifdef CDisplay__GetClickedActor_x
FUNCTION_AT_ADDRESS(struct T3D_tagACTORINSTANCE *  CDisplay::GetClickedActor(unsigned long,unsigned long,unsigned long,void *,void *),CDisplay__GetClickedActor);
#endif
#ifdef CDisplay__CreateActor_x
FUNCTION_AT_ADDRESS(struct T3D_tagACTORINSTANCE *  CDisplay::CreateActor(char *,float,float,float,float,float,float,bool,bool),CDisplay__CreateActor);
#endif
#ifdef CDisplay__SetActorBoundingRadius_x
FUNCTION_AT_ADDRESS(float  CDisplay::SetActorBoundingRadius(struct T3D_tagACTORINSTANCE *,float,float),CDisplay__SetActorBoundingRadius);
#endif
#ifdef CDisplay__DeleteActor_x
FUNCTION_AT_ADDRESS(void  CDisplay::DeleteActor(struct T3D_tagACTORINSTANCE *),CDisplay__DeleteActor);
#endif
#ifdef CDisplay__dupActorHierarchicalSprite_x
FUNCTION_AT_ADDRESS(struct T3D_HIERARCHICALSPRITEINSTANCE *  CDisplay::dupActorHierarchicalSprite(struct T3D_tagACTORINSTANCE *),CDisplay__dupActorHierarchicalSprite);
#endif
#ifdef CDisplay__ToggleCharacterNameSprites_x
FUNCTION_AT_ADDRESS(void  CDisplay::ToggleCharacterNameSprites(bool),CDisplay__ToggleCharacterNameSprites);
#endif
#ifdef CDisplay__ToggleNpcNameSprites_x
FUNCTION_AT_ADDRESS(void  CDisplay::ToggleNpcNameSprites(bool),CDisplay__ToggleNpcNameSprites);
#endif
#ifdef CDisplay__TurnInfravisionEffectOn_x
FUNCTION_AT_ADDRESS(int  CDisplay::TurnInfravisionEffectOn(void),CDisplay__TurnInfravisionEffectOn);
#endif
#ifdef CDisplay__TurnInfravisionEffectOff_x
FUNCTION_AT_ADDRESS(int  CDisplay::TurnInfravisionEffectOff(void),CDisplay__TurnInfravisionEffectOff);
#endif
#ifdef CDisplay__SpurtBloodOnDag_x
FUNCTION_AT_ADDRESS(void  CDisplay::SpurtBloodOnDag(struct T3D_DAG *),CDisplay__SpurtBloodOnDag);
#endif
#ifdef CDisplay__SetDayPeriod_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetDayPeriod(unsigned char),CDisplay__SetDayPeriod);
#endif
#ifdef CDisplay__SetSkyLayer_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetSkyLayer(int),CDisplay__SetSkyLayer);
#endif
#ifdef CDisplay__GetSkyTime_x
FUNCTION_AT_ADDRESS(int  CDisplay::GetSkyTime(int *,int *),CDisplay__GetSkyTime);
#endif
#ifdef CDisplay__SetSunLight_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetSunLight(void),CDisplay__SetSunLight);
#endif
#ifdef CDisplay__SetSkyBackground_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetSkyBackground(void),CDisplay__SetSkyBackground);
#endif
#ifdef CDisplay__ProcessSky_x
FUNCTION_AT_ADDRESS(void  CDisplay::ProcessSky(void),CDisplay__ProcessSky);
#endif
#ifdef CDisplay__SimpleDistance_x
FUNCTION_AT_ADDRESS(float  CDisplay::SimpleDistance(float,float,float,float,float,float,float),CDisplay__SimpleDistance);
#endif
#ifdef CDisplay__TrueDistance_x
FUNCTION_AT_ADDRESS(float  CDisplay::TrueDistance(float,float,float,float,float,float,float),CDisplay__TrueDistance);
#endif
#ifdef CDisplay__PlayerSimpleDistance_x
FUNCTION_AT_ADDRESS(float  CDisplay::PlayerSimpleDistance(class EQPlayer *,class EQPlayer *,float),CDisplay__PlayerSimpleDistance);
#endif
#ifdef CDisplay__PlayerDistance_x
FUNCTION_AT_ADDRESS(float  CDisplay::PlayerDistance(class EQPlayer *,class EQPlayer *,float),CDisplay__PlayerDistance);
#endif
#ifdef CDisplay__hideGrassObjects_x
FUNCTION_AT_ADDRESS(void  CDisplay::hideGrassObjects(void),CDisplay__hideGrassObjects);
#endif
#ifdef CDisplay__updateGrassObjects_x
FUNCTION_AT_ADDRESS(void  CDisplay::updateGrassObjects(void),CDisplay__updateGrassObjects);
#endif
#ifdef CDisplay__loadGrassObjects_x
FUNCTION_AT_ADDRESS(void  CDisplay::loadGrassObjects(char *),CDisplay__loadGrassObjects);
#endif
#ifdef CDisplay__SetAmbientLight_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetAmbientLight(float),CDisplay__SetAmbientLight);
#endif
#ifdef CDisplay__SetViewActorByName_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetViewActorByName(char *),CDisplay__SetViewActorByName);
#endif
#ifdef CDisplay__SetActorSpriteTint_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetActorSpriteTint(struct _EQRGB *,struct T3D_tagACTORINSTANCE *),CDisplay__SetActorSpriteTint);
#endif
#ifdef CDisplay__FreeAllItemLists_x
FUNCTION_AT_ADDRESS(void  CDisplay::FreeAllItemLists(void),CDisplay__FreeAllItemLists);
#endif
#ifdef CActionsWnd__MainPageActivate_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::MainPageActivate(void),CActionsWnd__MainPageActivate);
#endif
#ifdef CActionsWnd__MainPageDeactivate_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::MainPageDeactivate(void),CActionsWnd__MainPageDeactivate);
#endif
#ifdef CActionsWnd__SocialsPageDeactivate_x
FUNCTION_AT_ADDRESS(int  CActionsWnd::SocialsPageDeactivate(void),CActionsWnd__SocialsPageDeactivate);
#endif
#ifdef CGroupSearchWnd__GroupListPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GroupListPageOnProcessFrame(void),CGroupSearchWnd__GroupListPageOnProcessFrame);
#endif
#ifdef CGroupSearchWnd__PlayerListPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::PlayerListPageOnProcessFrame(void),CGroupSearchWnd__PlayerListPageOnProcessFrame);
#endif
#ifdef COptionsWnd__KeyboardPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int  COptionsWnd::KeyboardPageOnProcessFrame(void),COptionsWnd__KeyboardPageOnProcessFrame);
#endif
#ifdef CDisplay__GenericSphereColl_x
FUNCTION_AT_ADDRESS(bool  CDisplay::GenericSphereColl(float,float,float,float,float,float,float *,float *,float *,unsigned char),CDisplay__GenericSphereColl);
#endif
#ifdef CDisplay__FindZoneTopZ_x
FUNCTION_AT_ADDRESS(float  CDisplay::FindZoneTopZ(float,float,float),CDisplay__FindZoneTopZ);
#endif
#ifdef CDisplay__GetEnvironment_x
FUNCTION_AT_ADDRESS(unsigned char  CDisplay::GetEnvironment(float,float,float,int *),CDisplay__GetEnvironment);
#endif
#ifdef CDisplay__MoveLocalPlayerToSafeCoords_x
FUNCTION_AT_ADDRESS(void  CDisplay::MoveLocalPlayerToSafeCoords(void),CDisplay__MoveLocalPlayerToSafeCoords);
#endif
#ifdef CDisplay__SetupEQPlayers_x
FUNCTION_AT_ADDRESS(void  CDisplay::SetupEQPlayers(void),CDisplay__SetupEQPlayers);
#endif
#ifdef CDisplay__MoveLight_x
FUNCTION_AT_ADDRESS(void  CDisplay::MoveLight(struct T3D_POINTLIGHT *,struct _physicsinfo *),CDisplay__MoveLight);
#endif
#ifdef CDistillerInfo__GetIDFromRecordNum_x
FUNCTION_AT_ADDRESS(int CDistillerInfo::GetIDFromRecordNum(int ID, bool bWhat),CDistillerInfo__GetIDFromRecordNum);
#endif
#ifdef ZoneNPCLoadTextManager__ZoneNPCLoadTextManager_x
FUNCTION_AT_ADDRESS( ZoneNPCLoadTextManager::ZoneNPCLoadTextManager(char *),ZoneNPCLoadTextManager__ZoneNPCLoadTextManager);
#endif
#ifdef ZoneNPCLoadTextManager__dZoneNPCLoadTextManager_x
FUNCTION_AT_ADDRESS( ZoneNPCLoadTextManager::~ZoneNPCLoadTextManager(void),ZoneNPCLoadTextManager__dZoneNPCLoadTextManager);
#endif
#ifdef ZoneNPCLoadTextManager__LoadText_x
FUNCTION_AT_ADDRESS(void  ZoneNPCLoadTextManager::LoadText(char *),ZoneNPCLoadTextManager__LoadText);
#endif
#ifdef ZoneNPCLoadTextManager__GetNPCCode_x
FUNCTION_AT_ADDRESS(char *  ZoneNPCLoadTextManager::GetNPCCode(int),ZoneNPCLoadTextManager__GetNPCCode);
#endif
#ifdef ZoneNPCLoadTextManager__GetS3DName_x
FUNCTION_AT_ADDRESS(char *  ZoneNPCLoadTextManager::GetS3DName(int),ZoneNPCLoadTextManager__GetS3DName);
#endif
#ifdef public_key__encrypt_x
FUNCTION_AT_ADDRESS(class vlong  public_key::encrypt(class vlong &),public_key__encrypt);
#endif
#ifdef engineInterface__engineInterface_x
FUNCTION_AT_ADDRESS( engineInterface::engineInterface(void),engineInterface__engineInterface);
#endif
#ifdef engineInterface__get_x
FUNCTION_AT_ADDRESS(class engineInterface * __cdecl engineInterface::get(void),engineInterface__get);
#endif
#ifdef engineInterface__ChangeDag_x
FUNCTION_AT_ADDRESS(unsigned long *  engineInterface::ChangeDag(struct T3D_tagWORLD *,struct T3D_DAG *,char *),engineInterface__ChangeDag);
#endif
#ifdef CAdvancedLootWnd__DoAdvLootAction_x
FUNCTION_AT_ADDRESS(DWORD CAdvancedLootWnd::DoAdvLootAction(DWORD, CXStr*, DWORD, DWORD), CAdvancedLootWnd__DoAdvLootAction);
#endif
#ifdef CAdvancedLootWnd__DoSharedAdvLootAction_x
FUNCTION_AT_ADDRESS(DWORD CAdvancedLootWnd::DoSharedAdvLootAction(PLOOTITEM pLootItem, CXStr *Assignee, DWORD Action, DWORD Quantity), CAdvancedLootWnd__DoSharedAdvLootAction);
#endif
#ifdef CAltAbilityData__GetMercCurrentRank_x
FUNCTION_AT_ADDRESS(int CAltAbilityData::GetMercCurrentRank(int),CAltAbilityData__GetMercCurrentRank);
#endif
#ifdef CAltAbilityData__GetMercMaxRank_x
FUNCTION_AT_ADDRESS(int CAltAbilityData::GetMercMaxRank(int),CAltAbilityData__GetMercMaxRank);
#endif
#ifdef CAltAbilityData__GetMaxRank_x
FUNCTION_AT_ADDRESS(int CAltAbilityData::GetMaxRank(void),CAltAbilityData__GetMaxRank);
#endif
#ifdef EQ_AltAbility__EQ_AltAbility_x
FUNCTION_AT_ADDRESS( EQ_AltAbility::EQ_AltAbility(int),EQ_AltAbility__EQ_AltAbility);
#endif
#ifdef AltAdvManager__AltAdvManager_x
FUNCTION_AT_ADDRESS( AltAdvManager::AltAdvManager(void),AltAdvManager__AltAdvManager);
#endif
#ifdef AltAdvManager__GetAAById_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS( struct _ALTABILITY *AltAdvManager::GetAAById(int,int), AltAdvManager__GetAAById);
#else
FUNCTION_AT_ADDRESS(struct _ALTABILITY *AltAdvManager::GetAAById(int), AltAdvManager__GetAAById);
#endif
#endif
#ifdef AltAdvManager__IsAbilityReady_x
FUNCTION_AT_ADDRESS(bool  AltAdvManager::IsAbilityReady(class EQ_PC *,EQData::PALTABILITY,int *,int *),AltAdvManager__IsAbilityReady);
#endif
#ifdef AltAdvManager__CalculateHideTimeReduce_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateHideTimeReduce(class EQ_PC *),AltAdvManager__CalculateHideTimeReduce);
#endif
#ifdef AltAdvManager__GetCalculatedTimer_x
FUNCTION_AT_ADDRESS(unsigned long  AltAdvManager::GetCalculatedTimer(class EQ_PC *,EQData::PALTABILITY),AltAdvManager__GetCalculatedTimer);
#endif
#ifdef AltAdvManager__GetNextAbilityCost_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::GetNextAbilityCost(int,int),AltAdvManager__GetNextAbilityCost);
#endif
#ifdef AltAdvManager__TotalPointsInSkill_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::TotalPointsInSkill(int,int),AltAdvManager__TotalPointsInSkill);
#endif
#ifdef AltAdvManager__CalculateStalwartEnduranceChance_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateStalwartEnduranceChance(class EQ_PC *),AltAdvManager__CalculateStalwartEnduranceChance);
#endif
#ifdef AltAdvManager__CalculateLoHHarmTouchReuseTimer_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateLoHHarmTouchReuseTimer(class EQ_PC *,int),AltAdvManager__CalculateLoHHarmTouchReuseTimer);
#endif
#ifdef AltAdvManager__CalculateSingingMasteryMod_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateSingingMasteryMod(class EQ_PC *,int),AltAdvManager__CalculateSingingMasteryMod);
#endif
#ifdef AltAdvManager__CalculateInstrumentMasteryMod_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateInstrumentMasteryMod(class EQ_PC *),AltAdvManager__CalculateInstrumentMasteryMod);
#endif
#ifdef AltAdvManager__CalculateFleetOfFoot_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateFleetOfFoot(class EQ_PC *),AltAdvManager__CalculateFleetOfFoot);
#endif
#ifdef AltAdvManager__CalculateNimbleEvasionChance_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateNimbleEvasionChance(class EQ_PC *),AltAdvManager__CalculateNimbleEvasionChance);
#endif
#ifdef AltAdvManager__CalculateDoubleAttackChance_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateDoubleAttackChance(class EQ_PC *,int,unsigned char),AltAdvManager__CalculateDoubleAttackChance);
#endif
#ifdef AltAdvManager__CalculateMitigationBoost_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateMitigationBoost(class EQ_PC *,int),AltAdvManager__CalculateMitigationBoost);
#endif
#ifdef AltAdvManager__CalculateSpellCastingMastery_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateSpellCastingMastery(class EQ_PC *),AltAdvManager__CalculateSpellCastingMastery);
#endif
#ifdef AltAdvManager__CalculateMaxHPAA_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateMaxHPAA(class EQ_PC *,int),AltAdvManager__CalculateMaxHPAA);
#endif
#ifdef AltAdvManager__CalculateMaxStatAA_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateMaxStatAA(class EQ_PC *,int),AltAdvManager__CalculateMaxStatAA);
#endif
#ifdef AltAdvManager__GetAbilityTitle_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::GetAbilityTitle(class EQPlayer *),AltAdvManager__GetAbilityTitle);
#endif
#ifdef AltAdvManager__AltSkillReqs_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::AltSkillReqs(class EQ_PC *,int),AltAdvManager__AltSkillReqs);
#endif
#ifdef AltAdvManager__GetAALevelNeeded_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::GetAALevelNeeded(class EQ_PC *,int),AltAdvManager__GetAALevelNeeded);
#endif
#ifdef AltAdvManager__MeetsPoPLevelReqs_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::MeetsPoPLevelReqs(class EQ_PC *,int,int),AltAdvManager__MeetsPoPLevelReqs);
#endif
#ifdef AltAdvManager__CanTrainAbility_x
FUNCTION_AT_ADDRESS(bool AltAdvManager::CanTrainAbility(class PcZoneClient *, class CAltAbilityData *, bool, bool, bool), AltAdvManager__CanTrainAbility);
#endif
#ifdef AltAdvManager__CanSeeAbility_x
FUNCTION_AT_ADDRESS(bool AltAdvManager::CanSeeAbility(class PcZoneClient *, class CAltAbilityData *), AltAdvManager__CanSeeAbility);
#endif
#ifdef AltAdvManager__AbilitiesByClass_x
FUNCTION_AT_ADDRESS(int  AltAdvManager::AbilitiesByClass(int,int),AltAdvManager__AbilitiesByClass);
#endif
#ifdef AltAdvManager__GetAbilityReqs_x
FUNCTION_AT_ADDRESS(void  AltAdvManager::GetAbilityReqs(char *,int),AltAdvManager__GetAbilityReqs);
#endif
#ifdef EQ_CharacterData__EQ_CharacterDataResetAllMembers_x
FUNCTION_AT_ADDRESS(void  EQ_CharacterData::EQ_CharacterDataResetAllMembers(void),EQ_CharacterData__EQ_CharacterDataResetAllMembers);
#endif
#ifdef EQ_Affect__Reset_x
FUNCTION_AT_ADDRESS(void EQ_Affect::Reset(void),EQ_Affect__Reset);
#endif
#ifdef EQ_Affect__GetAffectData_x
FUNCTION_AT_ADDRESS(int EQ_Affect::GetAffectData(int)const,EQ_Affect__GetAffectData);
#endif
#ifdef EQ_Character__EQ_Character_x
FUNCTION_AT_ADDRESS( EQ_Character::EQ_Character(void),EQ_Character__EQ_Character);
#endif
#ifdef EQ_Character__dEQ_Character_x
FUNCTION_AT_ADDRESS( EQ_Character::~EQ_Character(void),EQ_Character__dEQ_Character);
#endif
#ifdef EQ_Character__EQ_CharacterResetAllMembers_x
FUNCTION_AT_ADDRESS(void  EQ_Character::EQ_CharacterResetAllMembers(void),EQ_Character__EQ_CharacterResetAllMembers);
#endif
#ifdef EQ_Character__ModifyCurHP_x
#if defined(ROF2EMU) || defined(UFEMU)
FUNCTION_AT_ADDRESS(void  EQ_Character::ModifyCurHP(__int modification, class PlayerZoneClient *resposibleplayer,int skilltype),EQ_Character__ModifyCurHP);
#else
FUNCTION_AT_ADDRESS(void  EQ_Character::ModifyCurHP(__int64 modification, class PlayerZoneClient *resposibleplayer,int skilltype),EQ_Character__ModifyCurHP);
#endif
#endif
#ifdef EQ_Character__normal_to_special_x
FUNCTION_AT_ADDRESS(int __cdecl EQ_Character::normal_to_special(int),EQ_Character__normal_to_special);
#endif
#ifdef EQ_Character__IsSpellcaster_x
FUNCTION_AT_ADDRESS(int  EQ_Character::IsSpellcaster(void),EQ_Character__IsSpellcaster);
#endif
#ifdef EQ_Character__DoLight_x
FUNCTION_AT_ADDRESS(void  EQ_Character::DoLight(unsigned char),EQ_Character__DoLight);
#endif
#ifdef EQ_Character__Skill_x
FUNCTION_AT_ADDRESS(int  EQ_Character::Skill(int),EQ_Character__Skill);
#endif
#ifdef EQ_Character__HasSpell_x
FUNCTION_AT_ADDRESS(int  EQ_Character::HasSpell(int),EQ_Character__HasSpell);
#endif
#ifdef EQ_Character__ResetCur_HP_x
FUNCTION_AT_ADDRESS(void  EQ_Character::ResetCur_HP(int),EQ_Character__ResetCur_HP);
#endif
#ifdef EQ_Character__GetEnduranceRegen_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetEnduranceRegen(bool bIncItemsAndBuffs, bool bCombat),EQ_Character__GetEnduranceRegen);
#endif
#ifdef EQ_Character__GetHPRegen_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetHPRegen(bool bIncItemsAndBuffs, bool *bIsBleeding, bool bCombat),EQ_Character__GetHPRegen);
#endif
#ifdef EQ_Character__GetManaRegen_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetManaRegen(bool bincItemsAndBuffs, bool bCombat),EQ_Character__GetManaRegen);
#endif
#ifdef EQ_Character__Cur_HP_x
FUNCTION_AT_ADDRESS(int  EQ_Character1::Cur_HP(int SpawnType, bool bCapAtMax),EQ_Character__Cur_HP);
#endif
#ifdef EQ_Character__GetHPFromStamina_x
FUNCTION_AT_ADDRESS(int  EQ_Character::GetHPFromStamina(int),EQ_Character__GetHPFromStamina);
#endif
#ifdef EQ_Character__Cur_Mana_x
FUNCTION_AT_ADDRESS(int  EQ_Character::Cur_Mana(bool bCapAtMax),EQ_Character__Cur_Mana);
#endif
#ifdef EQ_Character__IsMage_x
FUNCTION_AT_ADDRESS(int  EQ_Character::IsMage(void),EQ_Character__IsMage);
#endif
#ifdef EQ_Character__GetClassACBonus_x
FUNCTION_AT_ADDRESS(int  EQ_Character::GetClassACBonus(int),EQ_Character__GetClassACBonus);
#endif
#ifdef EQ_Character__ac_x
FUNCTION_AT_ADDRESS(int  EQ_Character::ac(bool),EQ_Character__ac);
#endif
#ifdef EQ_Character__compute_tohit_x
FUNCTION_AT_ADDRESS(int  EQ_Character::compute_tohit(unsigned char),EQ_Character__compute_tohit);
#endif
#ifdef EQ_Character__defense_agility_bonus_x
FUNCTION_AT_ADDRESS(int  EQ_Character::defense_agility_bonus(void),EQ_Character__defense_agility_bonus);
#endif
#ifdef EQ_Character__compute_defense_x
FUNCTION_AT_ADDRESS(int  EQ_Character::compute_defense(void),EQ_Character__compute_defense);
#endif
#ifdef EQ_Character__offense_x
FUNCTION_AT_ADDRESS(int  EQ_Character::offense(unsigned char),EQ_Character__offense);
#endif
#ifdef EQ_Character__HasSkill_x
FUNCTION_AT_ADDRESS(int  EQ_Character::HasSkill(unsigned char),EQ_Character__HasSkill);
#endif
#ifdef EQ_Character__HasInnateSkill_x
FUNCTION_AT_ADDRESS(int  EQ_Character::HasInnateSkill(unsigned char,int),EQ_Character__HasInnateSkill);
#endif
#ifdef EQ_Character__InitMyLanguages_x
FUNCTION_AT_ADDRESS(void  EQ_Character::InitMyLanguages(void),EQ_Character__InitMyLanguages);
#endif
#ifdef EQ_Character__BaneDamage_x
FUNCTION_AT_ADDRESS(int  EQ_Character::BaneDamage(class EQ_Equipment *),EQ_Character__BaneDamage);
#endif
#ifdef EQ_Character__ElementResistDmg_x
FUNCTION_AT_ADDRESS(int  EQ_Character::ElementResistDmg(class EQ_Equipment *,int),EQ_Character__ElementResistDmg);
#endif
#ifdef EQ_Character__save_bash_x
FUNCTION_AT_ADDRESS(int  EQ_Character::save_bash(int),EQ_Character__save_bash);
#endif
#ifdef EQ_Character__CapStat_x
FUNCTION_AT_ADDRESS(int  EQ_Character::CapStat(int,int),EQ_Character__CapStat);
#endif
#ifdef EQ_Character__CalcFoodDrinkBonus_x
FUNCTION_AT_ADDRESS(void  EQ_Character::CalcFoodDrinkBonus(int),EQ_Character__CalcFoodDrinkBonus);
#endif
#ifdef EQ_Character__basesave_magic_x
FUNCTION_AT_ADDRESS(int  EQ_Character::basesave_magic(void),EQ_Character__basesave_magic);
#endif
#ifdef EQ_Character__save_magic_x
FUNCTION_AT_ADDRESS(int  EQ_Character::save_magic(void),EQ_Character__save_magic);
#endif
#ifdef EQ_Character__basesave_fire_x
FUNCTION_AT_ADDRESS(int  EQ_Character::basesave_fire(void),EQ_Character__basesave_fire);
#endif
#ifdef EQ_Character__save_fire_x
FUNCTION_AT_ADDRESS(int  EQ_Character::save_fire(void),EQ_Character__save_fire);
#endif
#ifdef EQ_Character__basesave_cold_x
FUNCTION_AT_ADDRESS(int  EQ_Character::basesave_cold(void),EQ_Character__basesave_cold);
#endif
#ifdef EQ_Character__save_cold_x
FUNCTION_AT_ADDRESS(int  EQ_Character::save_cold(void),EQ_Character__save_cold);
#endif
#ifdef EQ_Character__basesave_disease_x
FUNCTION_AT_ADDRESS(int  EQ_Character::basesave_disease(void),EQ_Character__basesave_disease);
#endif
#ifdef EQ_Character__save_disease_x
FUNCTION_AT_ADDRESS(int  EQ_Character::save_disease(void),EQ_Character__save_disease);
#endif
#ifdef EQ_Character__basesave_poison_x
FUNCTION_AT_ADDRESS(int  EQ_Character::basesave_poison(void),EQ_Character__basesave_poison);
#endif
#ifdef EQ_Character__save_poison_x
FUNCTION_AT_ADDRESS(int  EQ_Character::save_poison(void),EQ_Character__save_poison);
#endif
#ifdef EQ_Character__Str_x
FUNCTION_AT_ADDRESS(int  EQ_Character::Str(void),EQ_Character__Str);
#endif
#ifdef EQ_Character__Sta_x
FUNCTION_AT_ADDRESS(int  EQ_Character::Sta(void),EQ_Character__Sta);
#endif
#ifdef EQ_Character__Cha_x
FUNCTION_AT_ADDRESS(int  EQ_Character::Cha(void),EQ_Character__Cha);
#endif
#ifdef EQ_Character__Dex_x
FUNCTION_AT_ADDRESS(int  EQ_Character::Dex(void),EQ_Character__Dex);
#endif
#ifdef EQ_Character__Int_x
FUNCTION_AT_ADDRESS(int  EQ_Character::Int(void),EQ_Character__Int);
#endif
#ifdef EQ_Character__Agi_x
FUNCTION_AT_ADDRESS(int  EQ_Character::Agi(void),EQ_Character__Agi);
#endif
#ifdef EQ_Character__Wis_x
FUNCTION_AT_ADDRESS(int  EQ_Character::Wis(void),EQ_Character__Wis);
#endif
#ifdef EQ_Character__ApplyFatigue_x
FUNCTION_AT_ADDRESS(int  EQ_Character::ApplyFatigue(int),EQ_Character__ApplyFatigue);
#endif
#ifdef EQ_Character__max_encumbrance_x
FUNCTION_AT_ADDRESS(int  EQ_Character::max_encumbrance(void),EQ_Character__max_encumbrance);
#endif
#ifdef EQ_Character__CanUseItem_x
FUNCTION_AT_ADDRESS(bool EQ_Character1::CanUseItem(PCONTENTS *, bool, bool),EQ_Character__CanUseItem);
#endif
#ifdef EQ_Character__encum_factor_x
FUNCTION_AT_ADDRESS(float  EQ_Character::encum_factor(void),EQ_Character__encum_factor);
#endif
#ifdef EQ_Character__cur_encumbrance_x
FUNCTION_AT_ADDRESS(int  EQ_Character::cur_encumbrance(void),EQ_Character__cur_encumbrance);
#endif
#ifdef EQ_Character__Race_x
FUNCTION_AT_ADDRESS(char *  EQ_Character::Race(int),EQ_Character__Race);
#endif
#ifdef EQ_Character__Class_x
FUNCTION_AT_ADDRESS(char *  EQ_Character::Class(int),EQ_Character__Class);
#endif
#ifdef EQ_Character__KunarkClass_x
FUNCTION_AT_ADDRESS(char *  EQ_Character::KunarkClass(int,int,int,bool),EQ_Character__KunarkClass);
#endif
#ifdef EQ_Character__ClassMin_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::ClassMin(int,int,unsigned char),EQ_Character__ClassMin);
#endif
#ifdef EQ_Character__CheckClass_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CheckClass(int,int),EQ_Character__CheckClass);
#endif
#ifdef EQ_Character__CanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CanWorship(int,int,unsigned char),EQ_Character__CanWorship);
#endif
#ifdef EQ_Character__HumanCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::HumanCanWorship(unsigned char,unsigned char),EQ_Character__HumanCanWorship);
#endif
#ifdef EQ_Character__BarbarianCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::BarbarianCanWorship(unsigned char,unsigned char),EQ_Character__BarbarianCanWorship);
#endif
#ifdef EQ_Character__EruditeCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::EruditeCanWorship(unsigned char,unsigned char),EQ_Character__EruditeCanWorship);
#endif
#ifdef EQ_Character__ElfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::ElfCanWorship(unsigned char,unsigned char),EQ_Character__ElfCanWorship);
#endif
#ifdef EQ_Character__HighElfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::HighElfCanWorship(unsigned char,unsigned char),EQ_Character__HighElfCanWorship);
#endif
#ifdef EQ_Character__DarkElfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::DarkElfCanWorship(unsigned char,unsigned char),EQ_Character__DarkElfCanWorship);
#endif
#ifdef EQ_Character__HalfElfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::HalfElfCanWorship(unsigned char,unsigned char),EQ_Character__HalfElfCanWorship);
#endif
#ifdef EQ_Character__DwarfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::DwarfCanWorship(unsigned char,unsigned char),EQ_Character__DwarfCanWorship);
#endif
#ifdef EQ_Character__TrollCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::TrollCanWorship(unsigned char,unsigned char),EQ_Character__TrollCanWorship);
#endif
#ifdef EQ_Character__OgreCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::OgreCanWorship(unsigned char,unsigned char),EQ_Character__OgreCanWorship);
#endif
#ifdef EQ_Character__HalflingCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::HalflingCanWorship(unsigned char,unsigned char),EQ_Character__HalflingCanWorship);
#endif
#ifdef EQ_Character__GnomeCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::GnomeCanWorship(unsigned char,unsigned char),EQ_Character__GnomeCanWorship);
#endif
#ifdef EQ_Character__IksarCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::IksarCanWorship(unsigned char,unsigned char),EQ_Character__IksarCanWorship);
#endif
#ifdef EQ_Character__VahShirCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::VahShirCanWorship(unsigned char,unsigned char),EQ_Character__VahShirCanWorship);
#endif
#ifdef EQ_Character__FroglockCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::FroglockCanWorship(unsigned char,unsigned char),EQ_Character__FroglockCanWorship);
#endif
#ifdef EQ_Character__CityCanStart_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CityCanStart(int,int,int,int),EQ_Character__CityCanStart);
#endif
#ifdef EQ_Character__BaseAttr_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::BaseAttr(int,unsigned char),EQ_Character__BaseAttr);
#endif
#ifdef EQ_Character__InitSkills_x
FUNCTION_AT_ADDRESS(void  EQ_Character::InitSkills(unsigned char,unsigned int),EQ_Character__InitSkills);
#endif
#ifdef EQ_Character__InitInnates_x
FUNCTION_AT_ADDRESS(void  EQ_Character::InitInnates(unsigned int,unsigned int),EQ_Character__InitInnates);
#endif
#ifdef EQ_Character__IsSpecialBazaarSpot_x
FUNCTION_AT_ADDRESS(int  EQ_Character::IsSpecialBazaarSpot(class EQPlayer *),EQ_Character__IsSpecialBazaarSpot);
#endif
#ifdef EQ_Character__CanSecondaryAttack_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CanSecondaryAttack(class EQPlayer *),EQ_Character__CanSecondaryAttack);
#endif
#ifdef EQ_Character__CanDoubleAttack_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CanDoubleAttack(class EQPlayer *,unsigned char),EQ_Character__CanDoubleAttack);
#endif
#ifdef EQ_Character__AntiTwinkAdj_x
FUNCTION_AT_ADDRESS(int  EQ_Character::AntiTwinkAdj(class EQ_Equipment *,int,int),EQ_Character__AntiTwinkAdj);
#endif
#ifdef EQ_Character__GetSkillBaseDamage_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::GetSkillBaseDamage(unsigned char,class EQPlayer *),EQ_Character__GetSkillBaseDamage);
#endif
#ifdef EQ_Character__UseSkill_x
#if defined(ROF2EMU) || defined(UFEMU)
FUNCTION_AT_ADDRESS(void  EQ_Character1::UseSkill(unsigned char skill,class EQPlayer *target),EQ_Character__UseSkill);
#else
FUNCTION_AT_ADDRESS(void  EQ_Character1::UseSkill(unsigned char skill,class EQPlayer *Target,bool bAuto),EQ_Character__UseSkill);
#endif
#endif
#ifdef EQ_Character__DoIntimidationEvent_x
FUNCTION_AT_ADDRESS(void  EQ_Character::DoIntimidationEvent(void),EQ_Character__DoIntimidationEvent);
#endif
#ifdef EQ_Character__DoFishingEvent_x
FUNCTION_AT_ADDRESS(void  EQ_Character::DoFishingEvent(void),EQ_Character__DoFishingEvent);
#endif
#ifdef EQ_Character__FindClosest_x
FUNCTION_AT_ADDRESS(class EQPlayer *  EQ_Character::FindClosest(int,int,int,int,int),EQ_Character__FindClosest);
#endif
#ifdef EQ_Character__IAmDead_x
FUNCTION_AT_ADDRESS(void  EQ_Character::IAmDead(struct _EQMissileHitinfo *,int),EQ_Character__IAmDead);
#endif
#ifdef EQ_Character__TotalOnPerson_x
FUNCTION_AT_ADDRESS(long  EQ_Character::TotalOnPerson(void),EQ_Character__TotalOnPerson);
#endif
#ifdef EQ_Character__ItemSold_x
FUNCTION_AT_ADDRESS(void  EQ_Character::ItemSold(long),EQ_Character__ItemSold);
#endif
#ifdef EQ_Character__TakeFallDamage_x
FUNCTION_AT_ADDRESS(int  EQ_Character::TakeFallDamage(float),EQ_Character__TakeFallDamage);
#endif
#ifdef EQ_Character__IHaveSkill_x
FUNCTION_AT_ADDRESS(int  EQ_Character::IHaveSkill(unsigned char),EQ_Character__IHaveSkill);
#endif
#ifdef EQ_Character__NoMezMe_x
FUNCTION_AT_ADDRESS(int  EQ_Character::NoMezMe(int,class EQPlayer *,class EQ_Spell *),EQ_Character__NoMezMe);
#endif
#ifdef EQ_Character__NoBashMe_x
FUNCTION_AT_ADDRESS(int  EQ_Character::NoBashMe(int),EQ_Character__NoBashMe);
#endif
#ifdef EQ_Character__StunMe_x
FUNCTION_AT_ADDRESS(void  EQ_Character1::StunMe(unsigned int,bool,bool,bool),EQ_Character__StunMe);
#endif
#ifdef EQ_Character__UnStunMe_x
FUNCTION_AT_ADDRESS(void  EQ_Character1::UnStunMe(void),EQ_Character__UnStunMe);
#endif
#ifdef EQ_Character__ApplyDamage_x
FUNCTION_AT_ADDRESS(int  EQ_Character::ApplyDamage(int,struct _EQMissileHitinfo *,bool,class HateListEntry *,bool),EQ_Character__ApplyDamage);
#endif
#ifdef EQ_Character__NotifyPCAffectChange_x
FUNCTION_AT_ADDRESS(void  EQ_Character::NotifyPCAffectChange(int,int),EQ_Character__NotifyPCAffectChange);
#endif
#ifdef EQ_Character__UpdateMyVisibleStatus_x
FUNCTION_AT_ADDRESS(void  EQ_Character::UpdateMyVisibleStatus(void),EQ_Character__UpdateMyVisibleStatus);
#endif
#ifdef EQ_Character__CanISeeInvis_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CanISeeInvis(void),EQ_Character__CanISeeInvis);
#endif
#ifdef EQ_Character__CanIBreathe_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CanIBreathe(void),EQ_Character__CanIBreathe);
#endif
#ifdef EQ_Character__ProcessEnvironment_x
FUNCTION_AT_ADDRESS(void  EQ_Character::ProcessEnvironment(void),EQ_Character__ProcessEnvironment);
#endif
#ifdef EQ_Character__ProcessHungerandThirst_x
FUNCTION_AT_ADDRESS(void  EQ_Character::ProcessHungerandThirst(unsigned int),EQ_Character__ProcessHungerandThirst);
#endif
#ifdef EQ_Character__ItemSpellAffects_x
FUNCTION_AT_ADDRESS(int  EQ_Character::ItemSpellAffects(int),EQ_Character__ItemSpellAffects);
#endif
#ifdef EQ_Character__ProcessAllStats_x
FUNCTION_AT_ADDRESS(void  EQ_Character::ProcessAllStats(void),EQ_Character__ProcessAllStats);
#endif
#ifdef EQ_Character__DoPassageOfTime_x
FUNCTION_AT_ADDRESS(void  EQ_Character::DoPassageOfTime(void),EQ_Character__DoPassageOfTime);
#endif
#ifdef EQ_Character__FindItemByClass_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::FindItemByClass(int,int *,int *),EQ_Character__FindItemByClass);
#endif
#ifdef CharacterZoneClient__FindItemByGuid_x
FUNCTION_AT_ADDRESS(bool CharacterZoneClient::FindItemByGuid(const EqItemGuid& ItemGuid, int *pos_slot, int *con_slot),CharacterZoneClient__FindItemByGuid);
#endif
#ifdef CharacterZoneClient__FindItemByRecord_x
FUNCTION_AT_ADDRESS(BYTE CharacterZoneClient::FindItemByRecord(int ItemNumber /*recordnum*/, int *pos_slot, int *con_slot, bool bReverseLookup),CharacterZoneClient__FindItemByRecord);
#endif
#ifdef EQ_Character__FindItemQty_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::FindItemQty(int,int),EQ_Character__FindItemQty);
#endif
#ifdef EQ_Character__CanMedOnHorse_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CanMedOnHorse(void),EQ_Character__CanMedOnHorse);
#endif
#ifdef EQ_Character__ExpendItemCharge_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::ExpendItemCharge(int,int),EQ_Character__ExpendItemCharge);
#endif
#ifdef EQ_Character__AutoEat_x
FUNCTION_AT_ADDRESS(int  EQ_Character::AutoEat(unsigned char),EQ_Character__AutoEat);
#endif
#ifdef EQ_Character__CheckFoodAndWater_x
FUNCTION_AT_ADDRESS(int  EQ_Character::CheckFoodAndWater(void),EQ_Character__CheckFoodAndWater);
#endif
#ifdef EQ_Character__DoMeditation_x
FUNCTION_AT_ADDRESS(void  EQ_Character::DoMeditation(void),EQ_Character__DoMeditation);
#endif
#ifdef EQ_Character__SetLocalVar_x
FUNCTION_AT_ADDRESS(int  EQ_Character::SetLocalVar(char *,int),EQ_Character__SetLocalVar);
#endif
#ifdef EQ_Character__GetIndexSkillMinDamageMod_x
FUNCTION_AT_ADDRESS(int  EQ_Character::GetIndexSkillMinDamageMod(int),EQ_Character__GetIndexSkillMinDamageMod);
#endif
#ifdef EQ_Character__GetFocusConserveRegChance_x
FUNCTION_AT_ADDRESS(int const  EQ_Character::GetFocusConserveRegChance(class EQ_Spell const *,class EQ_Equipment * *),EQ_Character__GetFocusConserveRegChance);
#endif
#ifdef EQ_Character__GetFocusCastingTimeModifier_x
FUNCTION_AT_ADDRESS(int const  EQ_Character1::GetFocusCastingTimeModifier(class EQ_Spell const *,class EQ_Equipment * *, int),EQ_Character__GetFocusCastingTimeModifier);
#endif
#ifdef EQ_Character__GetFocusRangeModifier_x
FUNCTION_AT_ADDRESS(int const  EQ_Character1::GetFocusRangeModifier(class EQ_Spell const *,class EQ_Equipment * *),EQ_Character__GetFocusRangeModifier);
#endif
#ifdef EQ_Character__IsExpansionFlag_x
FUNCTION_AT_ADDRESS(int EQ_Character1::IsExpansionFlag(int),EQ_Character__IsExpansionFlag);
#endif
#ifdef EQ_Character__GetFocusItem_x
FUNCTION_AT_ADDRESS(class EQ_Equipment *  EQ_Character::GetFocusItem(class EQ_Spell const *,int),EQ_Character__GetFocusItem);
#endif
#ifdef EQ_Character__GetFocusEffect_x
FUNCTION_AT_ADDRESS(class EQ_Spell *  EQ_Character::GetFocusEffect(class EQ_Spell const *,int),EQ_Character__GetFocusEffect);
#endif
#ifdef EQ_Character__DoesSpellMatchFocusFilters_x
FUNCTION_AT_ADDRESS(bool  EQ_Character::DoesSpellMatchFocusFilters(class EQ_Spell const *,class EQ_Spell const *),EQ_Character__DoesSpellMatchFocusFilters);
#endif
#ifdef EQ_Character__GetMyPetPlayer_x
FUNCTION_AT_ADDRESS(class EQPlayer *  EQ_Character::GetMyPetPlayer(void),EQ_Character__GetMyPetPlayer);
#endif
#ifdef CharacterZoneClient__GetMaxEffects_x
FUNCTION_AT_ADDRESS(unsigned char CharacterZoneClient::GetMaxEffects(void)const ,CharacterZoneClient__GetMaxEffects);
#endif
#ifdef CharacterZoneClient__GetEffect_x
FUNCTION_AT_ADDRESS(EQ_Affect & CharacterZoneClient::GetEffect(int)const,CharacterZoneClient__GetEffect);
#endif
#ifdef CharacterZoneClient__GetOpenEffectSlot_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetOpenEffectSlot(bool, bool, int),CharacterZoneClient__GetOpenEffectSlot);
#endif
#ifdef CharacterZoneClient__GetFirstEffectSlot_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetFirstEffectSlot(bool, bool),CharacterZoneClient__GetFirstEffectSlot);
#endif
#ifdef CharacterZoneClient__GetLastEffectSlot_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetLastEffectSlot(bool, bool, bool),CharacterZoneClient__GetLastEffectSlot);
#endif
#ifdef CharacterBase__GetEffectId_x
FUNCTION_AT_ADDRESS(unsigned int CharacterBase::GetEffectId(int),CharacterBase__GetEffectId);
#endif
#ifdef EQ_Character__SetEffectId_x
FUNCTION_AT_ADDRESS(void  EQ_Character1::SetEffectId(unsigned char,unsigned int),EQ_Character__SetEffectId);
#endif
#ifdef EQ_Character__CastSpell_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character1::CastSpell(unsigned char gemid, int spellid, class EQ_Item * *ppItem, class CEQItemLocation * ppitemloc, enum  ItemSpellTypes slot, unsigned char spell_loc, int arg7, int arg8, int arg9, bool arg10),EQ_Character__CastSpell); 
#endif
#ifdef EQ_Character__GetBardInstrumentMod_x
FUNCTION_AT_ADDRESS(int  EQ_Character::GetBardInstrumentMod(int),EQ_Character__GetBardInstrumentMod);
#endif
#ifdef EQ_Character__CalculateBardSongMod_x
FUNCTION_AT_ADDRESS(int  EQ_Character::CalculateBardSongMod(int),EQ_Character__CalculateBardSongMod);
#endif
#ifdef EQ_Character__CastingRequirementsMet_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CastingRequirementsMet(int),EQ_Character__CastingRequirementsMet);
#endif
#ifdef EQ_Character__GetAACastingTimeModifier_x
FUNCTION_AT_ADDRESS(int const  EQ_Character1::GetAACastingTimeModifier(class EQ_Spell const *),EQ_Character__GetAACastingTimeModifier);
#endif
#ifdef CharacterZoneClient__BardCastBard_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::BardCastBard(const EQ_Spell*, signed int)const ,CharacterZoneClient__BardCastBard);
#endif
#ifdef EQ_Character__IsValidAffect_x
FUNCTION_AT_ADDRESS(bool  EQ_Character::IsValidAffect(int),EQ_Character__IsValidAffect);
#endif
#ifdef EQ_Character__LaunchSpell_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::LaunchSpell(unsigned char,int,class EQ_Item * *),EQ_Character__LaunchSpell);
#endif
#ifdef EQ_Character__HandleSpecialPCAffects_x
FUNCTION_AT_ADDRESS(void  EQ_Character::HandleSpecialPCAffects(int),EQ_Character__HandleSpecialPCAffects);
#endif
#ifdef CharacterZoneClient__CalcAffectChange_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::CalcAffectChange(const EQ_Spell *spell, BYTE, BYTE, const EQ_Affect *, int, PlayerZoneClient *,bool, int,bool),CharacterZoneClient__CalcAffectChange);
#endif
#ifdef CharacterZoneClient__CalcAffectChangeGeneric_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::CalcAffectChangeGeneric(const EQ_Spell *spell, BYTE, BYTE, const EQ_Affect *, int, bool),CharacterZoneClient__CalcAffectChangeGeneric);
#endif
#ifdef CharacterZoneClient__GetFocusReuseMod_x
FUNCTION_AT_ADDRESS(const int CharacterZoneClient::GetFocusReuseMod(const EQ_Spell *pSpell, VePointer<CONTENTS>&pOutItem),CharacterZoneClient__GetFocusReuseMod);
#endif
#ifdef EQ_Character__GetPCSpellAffect_x
FUNCTION_AT_ADDRESS(class EQ_Affect * EQ_Character::GetPCSpellAffect(int theaffect,int *slotnum,int *spaslot) const,EQ_Character__GetPCSpellAffect);
#endif
#ifdef EQ_Character__TotalSpellAffects_x
FUNCTION_AT_ADDRESS(int  EQ_Character::TotalSpellAffects(unsigned char,bool,int *),EQ_Character__TotalSpellAffects);
#endif
#ifdef EQ_Character__IsSpellAffectingPC_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::IsSpellAffectingPC(int,int),EQ_Character__IsSpellAffectingPC);
#endif
#ifdef EQ_Character__SpellFizzled_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::SpellFizzled(unsigned char,class EQ_Spell *),EQ_Character__SpellFizzled);
#endif
#ifdef EQ_Character__ProcessAffects_x
FUNCTION_AT_ADDRESS(int  EQ_Character::ProcessAffects(void),EQ_Character__ProcessAffects);
#endif
#ifdef CharacterZoneClient__FindAffectSlot_x
FUNCTION_AT_ADDRESS(EQ_Affect *CharacterZoneClient::FindAffectSlot(int, PSPAWNINFO, int *, bool, int, EQ_Affect*, int, bool),CharacterZoneClient__FindAffectSlot);
#endif
#ifdef EQ_Character__GetOpenEffectSlot_x
FUNCTION_AT_ADDRESS(int  EQ_Character::GetOpenEffectSlot(bool,int),EQ_Character__GetOpenEffectSlot);
#endif
#ifdef EQ_Character__GetFirstEffectSlot_x
FUNCTION_AT_ADDRESS(int  EQ_Character::GetFirstEffectSlot(bool),EQ_Character__GetFirstEffectSlot);
#endif
#ifdef EQ_Character__GetLastEffectSlot_x
FUNCTION_AT_ADDRESS(int  EQ_Character::GetLastEffectSlot(bool),EQ_Character__GetLastEffectSlot);
#endif
#ifdef CharacterZoneClient__IsStackBlocked_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(bool CharacterZoneClient::IsStackBlocked(const EQ_Spell *, PSPAWNINFO, EQ_Affect*, int, bool), CharacterZoneClient__IsStackBlocked);
#else
FUNCTION_AT_ADDRESS(bool CharacterZoneClient::IsStackBlocked(const EQ_Spell *, PSPAWNINFO, EQ_Affect*,int),CharacterZoneClient__IsStackBlocked);
#endif
#endif
#ifdef CharacterZoneClient__CanUseMemorizedSpellSlot_x
FUNCTION_AT_ADDRESS(bool EQ_Character::CanUseMemorizedSpellSlot(int),CharacterZoneClient__CanUseMemorizedSpellSlot);
#endif
#ifdef EQ_Character__IsSpellTooPowerfull_x
FUNCTION_AT_ADDRESS(bool  EQ_Character::IsSpellTooPowerfull(class EQ_Spell *,class EQ_Character *),EQ_Character__IsSpellTooPowerfull);
#endif
#ifdef EQ_Character__HitBySpell_x
FUNCTION_AT_ADDRESS(void  EQ_Character::HitBySpell(struct _EQMissileHitinfo *),EQ_Character__HitBySpell);
#endif
#ifdef EQ_Spell__IsStackableDot_x
FUNCTION_AT_ADDRESS(bool  EQ_Spell::IsStackableDot(void)const ,EQ_Spell__IsStackableDot);
#endif
#ifdef EQ_Spell__IsStackable_x
FUNCTION_AT_ADDRESS(bool EQ_Spell::IsStackable(void)const ,EQ_Spell__IsStackable);
#endif
#ifdef EQ_Spell__GetSpellAffectBySlot_x
FUNCTION_AT_ADDRESS(const PSPELLCALCINFO EQ_Spell::GetSpellAffectBySlot(int)const ,EQ_Spell__GetSpellAffectBySlot);
#endif
#ifdef EQ_Spell__GetSpellAffectByIndex_x
FUNCTION_AT_ADDRESS(const PSPELLCALCINFO EQ_Spell::GetSpellAffectByIndex(int)const ,EQ_Spell__GetSpellAffectByIndex);
#endif
#ifdef EQ_Spell__IsSPAStacking_x
FUNCTION_AT_ADDRESS(bool EQ_Spell::IsSPAStacking(int) ,EQ_Spell__IsSPAStacking);
#endif
#ifdef EQ_Spell__IsSPAIgnoredByStacking_x
FUNCTION_AT_ADDRESS(bool EQ_Spell::IsSPAIgnoredByStacking(int) ,EQ_Spell__IsSPAIgnoredByStacking);
#endif
#ifdef EQ_Spell__IsNoRemove_x
FUNCTION_AT_ADDRESS(bool EQ_Spell::IsNoRemove(void)const ,EQ_Spell__IsNoRemove);
#endif
#ifdef EQ_Spell__IsDegeneratingLevelMod_x
FUNCTION_AT_ADDRESS(bool EQ_Spell::IsDegeneratingLevelMod(int) ,EQ_Spell__IsDegeneratingLevelMod);
#endif
#ifdef EQ_Character__EQSPA_Feign_Death_x
FUNCTION_AT_ADDRESS(void  EQ_Character::EQSPA_Feign_Death(int),EQ_Character__EQSPA_Feign_Death);
#endif
#ifdef EQ_Character__SpellDuration_x
FUNCTION_AT_ADDRESS(int  EQ_Character::SpellDuration(class EQ_Spell const *,unsigned char,unsigned char),EQ_Character__SpellDuration);
#endif
#ifdef EQ_Character__eqspa_change_form_x
FUNCTION_AT_ADDRESS(int  EQ_Character::eqspa_change_form(class EQ_Spell *,int,int,class EQ_Affect *),EQ_Character__eqspa_change_form);
#endif
#ifdef EQ_Character__eqspa_movement_rate_x
FUNCTION_AT_ADDRESS(void  EQ_Character::eqspa_movement_rate(int),EQ_Character__eqspa_movement_rate);
#endif
#ifdef EQ_Character__eqspa_levitation_x
FUNCTION_AT_ADDRESS(void  EQ_Character::eqspa_levitation(void),EQ_Character__eqspa_levitation);
#endif
#ifdef EQ_Character__eqspa_hp_x
FUNCTION_AT_ADDRESS(int  EQ_Character::eqspa_hp(unsigned int,class EQ_Affect *,int,class EQ_Spell *),EQ_Character__eqspa_hp);
#endif
#ifdef EQ_Character__eqspa_locate_corpse_x
FUNCTION_AT_ADDRESS(void  EQ_Character::eqspa_locate_corpse(void),EQ_Character__eqspa_locate_corpse);
#endif
#ifdef EQ_Character__InSpecialBindSpot_x
FUNCTION_AT_ADDRESS(int  EQ_Character::InSpecialBindSpot(class EQPlayer *),EQ_Character__InSpecialBindSpot);
#endif
#ifdef EQ_Character__RemovePCAffect_x
FUNCTION_AT_ADDRESS(void  EQ_Character::RemovePCAffect(class EQ_Affect *),EQ_Character__RemovePCAffect);
#endif
#ifdef EQ_Character__RemovePCAffectex_x
FUNCTION_AT_ADDRESS(void  EQ_Character::RemovePCAffectex(class EQ_Affect *,int),EQ_Character__RemovePCAffectex);
#endif
#ifdef EQ_Character__StopSpellCast_x
FUNCTION_AT_ADDRESS(void  EQ_Character1::StopSpellCast(unsigned char),EQ_Character__StopSpellCast);
#endif
#ifdef EQ_Character__StopSpellCast1_x
FUNCTION_AT_ADDRESS(void  EQ_Character1::StopSpellCast(unsigned char,int),EQ_Character__StopSpellCast1);
#endif
#ifdef EQ_Character__ReCachSpellEffects_x
FUNCTION_AT_ADDRESS(void  EQ_Character::ReCachSpellEffects(void),EQ_Character__ReCachSpellEffects);
#endif
#ifdef EQ_Character__ReCachItemEffects_x
FUNCTION_AT_ADDRESS(void  EQ_Character::ReCachItemEffects(void),EQ_Character__ReCachItemEffects);
#endif
#ifdef EQ_Character__GetCachEQSPA_x
FUNCTION_AT_ADDRESS(int  EQ_Character::GetCachEQSPA(int),EQ_Character__GetCachEQSPA);
#endif
#ifdef EQ_Character__GetConLevel_x
FUNCTION_AT_ADDRESS(unsigned long EQ_Character::GetConLevel(class EQPlayer *),EQ_Character__GetConLevel);
#endif
#ifdef EQ_Character__TotalEffect_x
FUNCTION_AT_ADDRESS(int EQ_Character1::TotalEffect(int, bool, int, bool, bool), EQ_Character__TotalEffect);
#endif
#ifdef EQ_Character__GetAdjustedSkill_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetAdjustedSkill(int), EQ_Character__GetAdjustedSkill);
#endif
#ifdef EQ_Character__GetBaseSkill_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetBaseSkill(int), EQ_Character__GetBaseSkill);
#endif
#ifdef EQ_Container__EQ_Container_x
FUNCTION_AT_ADDRESS( EQ_Container::EQ_Container(void),EQ_Container__EQ_Container);
#endif
#ifdef EQ_Container__dEQ_Container_x
FUNCTION_AT_ADDRESS( EQ_Container::~EQ_Container(void),EQ_Container__dEQ_Container);
#endif
#ifdef EQ_Container__Open_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Container::Open(void),EQ_Container__Open);
#endif
#ifdef EQ_Container__Close_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Container::Close(void),EQ_Container__Close);
#endif
#ifdef EQ_Container__IsOpen_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Container::IsOpen(void),EQ_Container__IsOpen);
#endif
#ifdef EQ_Equipment__EQ_Equipment_x
FUNCTION_AT_ADDRESS( EQ_Equipment::EQ_Equipment(void),EQ_Equipment__EQ_Equipment);
#endif
#ifdef EQ_Equipment__IsWeapon_x
FUNCTION_AT_ADDRESS(int  EQ_Equipment::IsWeapon(void),EQ_Equipment__IsWeapon);
#endif
#ifdef EQ_Equipment__IsInstrument_x
FUNCTION_AT_ADDRESS(int  EQ_Equipment::IsInstrument(void),EQ_Equipment__IsInstrument);
#endif
#ifdef EQ_Equipment__SendTextRequestMsg_x
FUNCTION_AT_ADDRESS(void  EQ_Equipment::SendTextRequestMsg(void),EQ_Equipment__SendTextRequestMsg);
#endif
#ifdef EQ_Item__Platinum_x
FUNCTION_AT_ADDRESS(int  EQ_Item::Platinum(void),EQ_Item__Platinum);
#endif
#ifdef EQ_Item__Gold_x
FUNCTION_AT_ADDRESS(int  EQ_Item::Gold(void),EQ_Item__Gold);
#endif
#ifdef EQ_Item__Silver_x
FUNCTION_AT_ADDRESS(int  EQ_Item::Silver(void),EQ_Item__Silver);
#endif
#ifdef EQ_Item__Copper_x
FUNCTION_AT_ADDRESS(int  EQ_Item::Copper(void),EQ_Item__Copper);
#endif
#ifdef EQ_Item__GetItemValue_x
FUNCTION_AT_ADDRESS(int EQ_Item::GetItemValue(bool)const,EQ_Item__GetItemValue); 
#endif
#ifdef EQ_Item__IsKeyRingItem_x
FUNCTION_AT_ADDRESS(bool EQ_Item::IsKeyRingItem(KeyRingType)const,EQ_Item__IsKeyRingItem); 
#endif
#ifdef EQ_Item__CanGoInBag_x
FUNCTION_AT_ADDRESS(bool EQ_Item::CanGoInBag(PCONTENTS *pCont,int unused,bool mustbefalse)const,EQ_Item__CanGoInBag); 
#endif
#ifdef EQ_Item__IsEmpty_x
FUNCTION_AT_ADDRESS(bool EQ_Item::IsEmpty(void) const,EQ_Item__IsEmpty); 
#endif
#ifdef EQ_Item__ValueSellMerchant_x
FUNCTION_AT_ADDRESS(long  EQ_Item::ValueSellMerchant(float,long)const,EQ_Item__ValueSellMerchant);
#endif
#ifdef EQ_Item__GetAugmentFitBySlot_x
FUNCTION_AT_ADDRESS(int EQ_Item::GetAugmentFitBySlot(PCONTENTS *, int, bool, bool index)const,EQ_Item__GetAugmentFitBySlot); 
#endif
#ifdef EQ_Item__ValueSSell_x
FUNCTION_AT_ADDRESS(char *  EQ_Item::ValueSSell(float,long),EQ_Item__ValueSSell);
#endif
#ifdef EQ_Item__ValueSBuy_x
FUNCTION_AT_ADDRESS(char *  EQ_Item::ValueSBuy(float,long),EQ_Item__ValueSBuy);
#endif
#ifdef EQ_Item__ValueSRent_x
FUNCTION_AT_ADDRESS(char *  EQ_Item::ValueSRent(void),EQ_Item__ValueSRent);
#endif
#ifdef EQ_Item__IsSpecialNoDrop_x
FUNCTION_AT_ADDRESS(bool  EQ_Item::IsSpecialNoDrop(void),EQ_Item__IsSpecialNoDrop);
#endif
#ifdef EQ_Item__IsStackable_x
FUNCTION_AT_ADDRESS(bool  EQ_Item::IsStackable(void),EQ_Item__IsStackable); 
#endif 
#ifdef EQ_LoadingS__EQ_LoadingS_x
FUNCTION_AT_ADDRESS( EQ_LoadingS::EQ_LoadingS(void),EQ_LoadingS__EQ_LoadingS);
#endif
#ifdef EQ_LoadingS__dEQ_LoadingS_x
FUNCTION_AT_ADDRESS( EQ_LoadingS::~EQ_LoadingS(void),EQ_LoadingS__dEQ_LoadingS);
#endif
#ifdef EQ_LoadingS__DrawBackground_x
FUNCTION_AT_ADDRESS(void  EQ_LoadingS::DrawBackground(struct T3D_XYZ *),EQ_LoadingS__DrawBackground);
#endif
#ifdef EQ_LoadingS__draw_x
FUNCTION_AT_ADDRESS(void  EQ_LoadingS::draw(void),EQ_LoadingS__draw);
#endif
#ifdef EQ_LoadingS__WriteTextHD_x
FUNCTION_AT_ADDRESS(void  EQ_LoadingS::WriteTextHD(char *,int,int,int),EQ_LoadingS__WriteTextHD);
#endif
#ifdef EQ_LoadingS__SetProgressBar_x
FUNCTION_AT_ADDRESS(void  EQ_LoadingS::SetProgressBar(int,char const *),EQ_LoadingS__SetProgressBar);
#endif
#ifdef EQ_Note__EQ_Note_x
FUNCTION_AT_ADDRESS( EQ_Note::EQ_Note(void),EQ_Note__EQ_Note);
#endif
#ifdef EQ_Note__SendTextRequestMsg_x
FUNCTION_AT_ADDRESS(void  EQ_Note::SendTextRequestMsg(void),EQ_Note__SendTextRequestMsg);
#endif
#ifdef EQ_PC__EQ_PC_x
FUNCTION_AT_ADDRESS( EQ_PC::EQ_PC(class EQ_PC *),EQ_PC__EQ_PC);
#endif
#ifdef EQ_PC__dEQ_PC_x
FUNCTION_AT_ADDRESS( EQ_PC::~EQ_PC(void),EQ_PC__dEQ_PC);
#endif
#ifdef EQ_PC__ClearSharedVault_x
FUNCTION_AT_ADDRESS(void  EQ_PC::ClearSharedVault(void),EQ_PC__ClearSharedVault);
#endif
#ifdef EQ_PC__IsAGroupMember_x
FUNCTION_AT_ADDRESS(int  EQ_PC::IsAGroupMember(char *),EQ_PC__IsAGroupMember);
#endif
#ifdef EQ_PC__CheckForGroupChanges_x
FUNCTION_AT_ADDRESS(void  EQ_PC::CheckForGroupChanges(void),EQ_PC__CheckForGroupChanges);
#endif
#ifdef EQ_PC__UnpackMyNetPC_x
FUNCTION_AT_ADDRESS(void  EQ_PC::UnpackMyNetPC(char *,int),EQ_PC__UnpackMyNetPC);
#endif
#ifdef EQ_PC__AlertInventoryChanged_x
FUNCTION_AT_ADDRESS(void  EQ_PC::AlertInventoryChanged(void),EQ_PC__AlertInventoryChanged);
#endif
#ifdef EQ_PC__InitPlayerStart_x
FUNCTION_AT_ADDRESS(void  EQ_PC::InitPlayerStart(unsigned int,unsigned char,int),EQ_PC__InitPlayerStart);
#endif
#ifdef EQ_PC__EmptyPossessionSlots_x
FUNCTION_AT_ADDRESS(void  EQ_PC::EmptyPossessionSlots(void),EQ_PC__EmptyPossessionSlots);
#endif
#ifdef EQ_PC__RefreshMe_x
FUNCTION_AT_ADDRESS(void  EQ_PC::RefreshMe(int),EQ_PC__RefreshMe);
#endif
#ifdef EQ_PC__PrepareForRepop_x
FUNCTION_AT_ADDRESS(void  EQ_PC::PrepareForRepop(int),EQ_PC__PrepareForRepop);
#endif
#ifdef EQ_PC__RefitNewbieEQ_x
FUNCTION_AT_ADDRESS(void  EQ_PC::RefitNewbieEQ(void),EQ_PC__RefitNewbieEQ);
#endif
#ifdef EQ_PC__RemoveMyAffect_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_PC::RemoveMyAffect(int),EQ_PC__RemoveMyAffect);
#endif
#ifdef EQ_PC__ProcessFatigue_x
FUNCTION_AT_ADDRESS(void  EQ_PC::ProcessFatigue(void),EQ_PC__ProcessFatigue);
#endif
#ifdef EQ_PC__DelLoreItemDup_x
FUNCTION_AT_ADDRESS(int  EQ_PC::DelLoreItemDup(int,int,int,class EQ_Item *),EQ_PC__DelLoreItemDup);
#endif
#ifdef EQ_PC__CheckDupLoreItems_x
FUNCTION_AT_ADDRESS(int  EQ_PC::CheckDupLoreItems(void),EQ_PC__CheckDupLoreItems);
#endif
#ifdef EQ_PC__CostToTrain_x
FUNCTION_AT_ADDRESS(int  EQ_PC::CostToTrain(int,float,int),EQ_PC__CostToTrain);
#endif
#ifdef EQ_PC__checkLang_x
FUNCTION_AT_ADDRESS(int  EQ_PC::checkLang(int),EQ_PC__checkLang);
#endif
#ifdef EQ_PC__BitchCanTrain_x
FUNCTION_AT_ADDRESS(int  EQ_PC::BitchCanTrain(int,int,int),EQ_PC__BitchCanTrain);
#endif
#ifdef EQ_PC__HandleMoney_x
FUNCTION_AT_ADDRESS(int  EQ_PC::HandleMoney(long),EQ_PC__HandleMoney);
#endif
#ifdef EQ_PC__DetermineQuestExpGained_x
FUNCTION_AT_ADDRESS(void  EQ_PC::DetermineQuestExpGained(int),EQ_PC__DetermineQuestExpGained);
#endif
#ifdef EQ_PC__ProcessAirSupply_x
FUNCTION_AT_ADDRESS(void  EQ_PC::ProcessAirSupply(void),EQ_PC__ProcessAirSupply);
#endif
#ifdef EQ_PC__MaxAirSupply_x
FUNCTION_AT_ADDRESS(int  EQ_PC::MaxAirSupply(void),EQ_PC__MaxAirSupply);
#endif
#ifdef EQ_PC__SetFatigue_x
FUNCTION_AT_ADDRESS(void  EQ_PC::SetFatigue(int),EQ_PC__SetFatigue);
#endif
#ifdef EQ_PC__numInParty_x
FUNCTION_AT_ADDRESS(int  EQ_PC::numInParty(void),EQ_PC__numInParty);
#endif
#ifdef EQ_PC__AtSkillLimit_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_PC::AtSkillLimit(int),EQ_PC__AtSkillLimit);
#endif
#ifdef EQ_PC__GetItemRecastTimer_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(unsigned long  EQ_PC::GetItemRecastTimer(class EQ_Item *item,ItemSpellTypes etype),EQ_PC__GetItemRecastTimer);
#else
FUNCTION_AT_ADDRESS(unsigned long  EQ_PC::GetItemRecastTimer(class EQ_Item *item),EQ_PC__GetItemRecastTimer);
#endif
#endif
#ifdef EQ_PC__GetAlternateAbilityId_x
FUNCTION_AT_ADDRESS(int  EQ_PC::GetAlternateAbilityId(int),EQ_PC__GetAlternateAbilityId);
#endif
#ifdef EQ_PC__GetCombatAbility_x
FUNCTION_AT_ADDRESS(int  EQ_PC::GetCombatAbility(int),EQ_PC__GetCombatAbility);
#endif
#ifdef EQ_PC__GetPcZoneClient_x
FUNCTION_AT_ADDRESS(class PcZoneClient *EQ_PC::GetPcZoneClient(void)const,EQ_PC__GetPcZoneClient);
#endif
#ifdef EQ_PC__GetCombatAbilityTimer_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(unsigned long  EQ_PC::GetCombatAbilityTimer(int,int),EQ_PC__GetCombatAbilityTimer);
#else
FUNCTION_AT_ADDRESS(unsigned long  EQ_PC::GetCombatAbilityTimer(int),EQ_PC__GetCombatAbilityTimer);
#endif
#endif
#ifdef EQ_PC__HasLoreItem_x
FUNCTION_AT_ADDRESS(bool EQ_PC::HasLoreItem(class EQ_Item *,int,int,int,int),EQ_PC__HasLoreItem);
#endif
#ifdef EQ_PC__GetItemContainedRealEstateIds_x
FUNCTION_AT_ADDRESS(void EQ_PC::GetItemContainedRealEstateIds(ArrayClass<ItemContainingRealEstate>&, bool, bool, bool),EQ_PC__GetItemContainedRealEstateIds);
#endif
#ifdef EQ_PC__GetNonArchivedOwnedRealEstates_x
FUNCTION_AT_ADDRESS(void EQ_PC::GetNonArchivedOwnedRealEstates(ArrayClass<int>&),EQ_PC__GetNonArchivedOwnedRealEstates);
#endif
#ifdef CInvSlot__HandleLButtonDown_x
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleLButtonDown(class CXPoint),CInvSlot__HandleLButtonDown);
#endif
#ifdef CInvSlot__HandleLButtonUpAfterHeld_x
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleLButtonUpAfterHeld(class CXPoint),CInvSlot__HandleLButtonUpAfterHeld);
#endif
#ifdef CInvSlot__HandleRButtonDown_x
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleRButtonDown(class CXPoint),CInvSlot__HandleRButtonDown);
#endif
#ifdef EQ_PC__CheckForLanguageImprovement_x
FUNCTION_AT_ADDRESS(void  EQ_PC::CheckForLanguageImprovement(unsigned char,unsigned char),EQ_PC__CheckForLanguageImprovement);
#endif
#ifdef EQ_PC__CheckSkillImprove_x
FUNCTION_AT_ADDRESS(void  EQ_PC::CheckSkillImprove(int,float),EQ_PC__CheckSkillImprove);
#endif
#ifdef EQ_PC__GetBodyTint_x
FUNCTION_AT_ADDRESS(unsigned long  EQ_PC::GetBodyTint(int),EQ_PC__GetBodyTint);
#endif
#ifdef EQ_PC__SetAltAbilityIndex_x
FUNCTION_AT_ADDRESS(void  EQ_PC::SetAltAbilityIndex(int,int),EQ_PC__SetAltAbilityIndex);
#endif
#ifdef EQ_PC__GetArmorTint_x
FUNCTION_AT_ADDRESS(unsigned long  EQ_PC::GetArmorTint(int),EQ_PC__GetArmorTint);
#endif
#ifdef EQ_PC__SetArmorTint_x
FUNCTION_AT_ADDRESS(void  EQ_PC::SetArmorTint(int,unsigned long),EQ_PC__SetArmorTint);
#endif
#ifdef EQ_PC__GetArmorType_x
FUNCTION_AT_ADDRESS(int  EQ_PC::GetArmorType(int),EQ_PC__GetArmorType);
#endif
#ifdef EQ_PC__SetArmorType_x
FUNCTION_AT_ADDRESS(void  EQ_PC::SetArmorType(int,int),EQ_PC__SetArmorType);
#endif
#ifdef EQ_PC__InitializeNewPCVariables_x
FUNCTION_AT_ADDRESS(void  EQ_PC::InitializeNewPCVariables(int),EQ_PC__InitializeNewPCVariables);
#endif
#ifdef EQ_PC__DestroyHeldItemOrMoney_x
FUNCTION_AT_ADDRESS(void  EQ_PC::DestroyHeldItemOrMoney(void),EQ_PC__DestroyHeldItemOrMoney);
#endif
#ifdef ProfileManager__GetCurrentProfile_x
FUNCTION_AT_ADDRESS(BaseProfile *ProfileManager::GetCurrentProfile(void),ProfileManager__GetCurrentProfile);
#endif
#ifdef EQ_Skill__EQ_Skill_x
FUNCTION_AT_ADDRESS( EQ_Skill::EQ_Skill(int),EQ_Skill__EQ_Skill);
#endif
#ifdef EqSoundManager__EqSoundManager_x
//FUNCTION_AT_ADDRESS( EqSoundManager::EqSoundManager(bool,bool,enum SpeakerType),EqSoundManager__EqSoundManager);
#endif
#ifdef EqSoundManager__dEqSoundManager_x
FUNCTION_AT_ADDRESS( EqSoundManager::~EqSoundManager(void),EqSoundManager__dEqSoundManager);
#endif
#ifdef EqSoundManager__LoadGlobalEmitters_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::LoadGlobalEmitters(void),EqSoundManager__LoadGlobalEmitters);
#endif
#ifdef EqSoundManager__GetMusicId_x
FUNCTION_AT_ADDRESS(int  EqSoundManager::GetMusicId(void),EqSoundManager__GetMusicId);
#endif
#ifdef EqSoundManager__LoadGlobalWaves_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::LoadGlobalWaves(void),EqSoundManager__LoadGlobalWaves);
#endif
#ifdef EqSoundManager__LoadListOfWaveFiles_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::LoadListOfWaveFiles(char * *,int),EqSoundManager__LoadListOfWaveFiles);
#endif
#ifdef EqSoundManager__WaveLoad_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::WaveLoad(char *,int,bool),EqSoundManager__WaveLoad);
#endif
#ifdef EqSoundManager__WaveIsPlaying_x
FUNCTION_AT_ADDRESS(bool  EqSoundManager::WaveIsPlaying(int),EqSoundManager__WaveIsPlaying);
#endif
#ifdef EqSoundManager__WavePlay_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::WavePlay(int,class SoundControl *),EqSoundManager__WavePlay);
#endif
#ifdef EqSoundManager__WaveStop_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::WaveStop(int),EqSoundManager__WaveStop);
#endif
#ifdef EqSoundManager__WaveGet_x
FUNCTION_AT_ADDRESS(class SoundAsset *  EqSoundManager::WaveGet(int),EqSoundManager__WaveGet);
#endif
#ifdef EqSoundManager__LoadGlobalMusic_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::LoadGlobalMusic(void),EqSoundManager__LoadGlobalMusic);
#endif
#ifdef EqSoundManager__SetMusicSelection_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetMusicSelection(int,bool),EqSoundManager__SetMusicSelection);
#endif
#ifdef EqSoundManager__GiveTime_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::GiveTime(void),EqSoundManager__GiveTime);
#endif
#ifdef EqSoundManager__SetCurrentZone_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetCurrentZone(char *),EqSoundManager__SetCurrentZone);
#endif
#ifdef FilePath__FilePath_x
FUNCTION_AT_ADDRESS( FilePath::FilePath(char const *),FilePath__FilePath);
#endif
#ifdef ShareBase__removeRef_x
FUNCTION_AT_ADDRESS(void  ShareBase::removeRef(void),ShareBase__removeRef);
#endif
#ifdef SharedString__SharedString_x
FUNCTION_AT_ADDRESS( SharedString::SharedString(char const *),SharedString__SharedString);
#endif
#ifdef SharedString__operator_equal_x
FUNCTION_AT_ADDRESS(class SharedString &  SharedString::operator=(class SharedString const &),SharedString__operator_equal);
#endif
#ifdef FilePath__dFilePath_x
FUNCTION_AT_ADDRESS( FilePath::~FilePath(void),FilePath__dFilePath);
#endif
#ifdef SharedString__dSharedString_x
FUNCTION_AT_ADDRESS( SharedString::~SharedString(void),SharedString__dSharedString);
#endif
#ifdef FilePath__FilePath1_x
FUNCTION_AT_ADDRESS( FilePath::FilePath(class SharedString const &),FilePath__FilePath1);
#endif
#ifdef EqSoundManager__LoadOldEmitters_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::LoadOldEmitters(void),EqSoundManager__LoadOldEmitters);
#endif
#ifdef EqSoundManager__CreateOldEmitter_x
//FUNCTION_AT_ADDRESS(class SoundEmitter *  EqSoundManager::CreateOldEmitter(int,float,float,float,int,int,int,float,int,int,int),EqSoundManager__CreateOldEmitter);
#endif
#ifdef EqSoundManager__GetAsset_x
FUNCTION_AT_ADDRESS(class SoundAsset *  EqSoundManager::GetAsset(char *),EqSoundManager__GetAsset);
#endif
#ifdef EqSoundManager__ReleaseZoneSpecificMidi_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::ReleaseZoneSpecificMidi(void),EqSoundManager__ReleaseZoneSpecificMidi);
#endif
#ifdef EqSoundManager__ReleaseZoneSpecificWaves_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::ReleaseZoneSpecificWaves(void),EqSoundManager__ReleaseZoneSpecificWaves);
#endif
#ifdef EqSoundManager__ReleaseZoneSpecificEmitters_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::ReleaseZoneSpecificEmitters(void),EqSoundManager__ReleaseZoneSpecificEmitters);
#endif
#ifdef EqSoundManager__SetEffectsLevel_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetEffectsLevel(float),EqSoundManager__SetEffectsLevel);
#endif
#ifdef EqSoundManager__SetMixAhead_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetMixAhead(int),EqSoundManager__SetMixAhead);
#endif
#ifdef EqSoundManager__SetWaveVolume_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetWaveVolume(float),EqSoundManager__SetWaveVolume);
#endif
#ifdef EqSoundManager__SetMusicVolume_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetMusicVolume(float),EqSoundManager__SetMusicVolume);
#endif
#ifdef EqSoundManager__GetListenerEnvironment_x
//FUNCTION_AT_ADDRESS(enum EnvironmentType  EqSoundManager::GetListenerEnvironment(void),EqSoundManager__GetListenerEnvironment);
#endif
#ifdef EqSoundManager__SetListenerEnvironment_x
//FUNCTION_AT_ADDRESS(void  EqSoundManager::SetListenerEnvironment(enum EnvironmentType),EqSoundManager__SetListenerEnvironment);
#endif
#ifdef EqSoundManager__SetListenerEnvironmentLow_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetListenerEnvironmentLow(void),EqSoundManager__SetListenerEnvironmentLow);
#endif
#ifdef EqSoundManager__SetListenerEnvironmentHigh_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetListenerEnvironmentHigh(void),EqSoundManager__SetListenerEnvironmentHigh);
#endif
#ifdef EqSoundManager__SetListenerEnvironmentOutside_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetListenerEnvironmentOutside(void),EqSoundManager__SetListenerEnvironmentOutside);
#endif
#ifdef EqSoundManager__SetListenerLocation_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetListenerLocation(float,float,float,float),EqSoundManager__SetListenerLocation);
#endif
#ifdef EqSoundManager__EmitterSetRaining_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::EmitterSetRaining(bool),EqSoundManager__EmitterSetRaining);
#endif
#ifdef EqSoundManager__EmitterSetWind_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::EmitterSetWind(bool),EqSoundManager__EmitterSetWind);
#endif
#ifdef EqSoundManager__EmitterSetNight_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::EmitterSetNight(bool),EqSoundManager__EmitterSetNight);
#endif
#ifdef EqSoundManager__EmitterSetUserDisabled_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::EmitterSetUserDisabled(bool),EqSoundManager__EmitterSetUserDisabled);
#endif
#ifdef EqSoundManager__EmitterSetIndoors_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::EmitterSetIndoors(bool),EqSoundManager__EmitterSetIndoors);
#endif
#ifdef EqSoundManager__UpdateEmitterStates_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::UpdateEmitterStates(void),EqSoundManager__UpdateEmitterStates);
#endif
#ifdef EqSoundManager__OldMp3ClearSelections_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::OldMp3ClearSelections(void),EqSoundManager__OldMp3ClearSelections);
#endif
#ifdef EqSoundManager__OldMp3Init_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::OldMp3Init(void),EqSoundManager__OldMp3Init);
#endif
#ifdef EqSoundManager__OldMp3Terminate_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::OldMp3Terminate(void),EqSoundManager__OldMp3Terminate);
#endif
#ifdef EqSoundManager__OldMp3GetSelection_x
FUNCTION_AT_ADDRESS(class SoundAsset *  EqSoundManager::OldMp3GetSelection(int),EqSoundManager__OldMp3GetSelection);
#endif
#ifdef EqSoundManager__PlayScriptMp3_x
FUNCTION_AT_ADDRESS(void EqSoundManager::PlayScriptMp3(char *Name, float Vol),EqSoundManager__PlayScriptMp3);
#endif
#ifdef EqSoundManager__EmitterLoad_x
FUNCTION_AT_ADDRESS(bool  EqSoundManager::EmitterLoad(char *),EqSoundManager__EmitterLoad);
#endif
#ifdef EqSoundManager__EmitterAdd_x
FUNCTION_AT_ADDRESS(void  EqSoundManager::EmitterAdd(class EqEmitterData *),EqSoundManager__EmitterAdd);
#endif
#ifdef EqMobileEmitter__EqMobileEmitter_x
FUNCTION_AT_ADDRESS( EqMobileEmitter::EqMobileEmitter(class EqSoundManager *),EqMobileEmitter__EqMobileEmitter);
#endif
#ifdef EqMobileEmitter__dEqMobileEmitter_x
FUNCTION_AT_ADDRESS( EqMobileEmitter::~EqMobileEmitter(void),EqMobileEmitter__dEqMobileEmitter);
#endif
#ifdef EqMobileEmitter__Move_x
FUNCTION_AT_ADDRESS(void  EqMobileEmitter::Move(float,float,float),EqMobileEmitter__Move);
#endif
#ifdef EqMobileEmitter__SetWave_x
FUNCTION_AT_ADDRESS(void  EqMobileEmitter::SetWave(int,char *),EqMobileEmitter__SetWave);
#endif
#ifdef EqMobileEmitter__SetNpcHeight_x
FUNCTION_AT_ADDRESS(void  EqMobileEmitter::SetNpcHeight(float),EqMobileEmitter__SetNpcHeight);
#endif
#ifdef EqEmitterData__EqEmitterData_x
FUNCTION_AT_ADDRESS( EqEmitterData::EqEmitterData(void),EqEmitterData__EqEmitterData);
#endif
#ifdef EqEmitterData__SetLoadString_x
FUNCTION_AT_ADDRESS(void  EqEmitterData::SetLoadString(char *),EqEmitterData__SetLoadString);
#endif
#ifdef EQ_Spell__SpellUsesDragonBreathEffect_x
FUNCTION_AT_ADDRESS(int  EQ_Spell::SpellUsesDragonBreathEffect(void),EQ_Spell__SpellUsesDragonBreathEffect);
#endif
#ifdef EQ_Spell__EQ_Spell_x
FUNCTION_AT_ADDRESS( EQ_Spell::EQ_Spell(char *),EQ_Spell__EQ_Spell);
#endif
#ifdef EQ_Spell__dEQ_Spell_x
FUNCTION_AT_ADDRESS( EQ_Spell::~EQ_Spell(void),EQ_Spell__dEQ_Spell);
#endif
#ifdef EQ_Spell__SpellAffects_x
FUNCTION_AT_ADDRESS(unsigned char  EQ_Spell::SpellAffects(int)const ,EQ_Spell__SpellAffects);
#endif
#ifdef EQ_Spell__IsPermIllusionSpell_x
FUNCTION_AT_ADDRESS(int  EQ_Spell::IsPermIllusionSpell(void)const ,EQ_Spell__IsPermIllusionSpell);
#endif
#ifdef EQ_Spell__GetSpellLevelNeeded_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Spell::GetSpellLevelNeeded(int)const ,EQ_Spell__GetSpellLevelNeeded);
#endif
#ifdef EQ_Spell__SpellAffectBase_x
FUNCTION_AT_ADDRESS(int EQ_Spell::SpellAffectBase(int)const ,EQ_Spell__SpellAffectBase);
#endif
#ifdef EQOldPlayerAnimation__InitAnimationData_x
FUNCTION_AT_ADDRESS(void __cdecl EQOldPlayerAnimation::InitAnimationData(void),EQOldPlayerAnimation__InitAnimationData);
#endif
#ifdef EQOldPlayerAnimation__PlayAttachmentAnimationTracks_x
FUNCTION_AT_ADDRESS(void  EQOldPlayerAnimation::PlayAttachmentAnimationTracks(int,int,bool,bool,float,bool,unsigned char),EQOldPlayerAnimation__PlayAttachmentAnimationTracks);
#endif
#ifdef EQOldPlayerAnimation__EQOldPlayerAnimation_x
FUNCTION_AT_ADDRESS( EQOldPlayerAnimation::EQOldPlayerAnimation(class EQPlayer *),EQOldPlayerAnimation__EQOldPlayerAnimation);
#endif
#ifdef EQOldPlayerAnimation__InterruptCurrentAnimation_x
FUNCTION_AT_ADDRESS(bool  EQOldPlayerAnimation::InterruptCurrentAnimation(int,unsigned char),EQOldPlayerAnimation__InterruptCurrentAnimation);
#endif
#ifdef EQOldPlayerAnimation__ChangeAttachmentAnimationTrackSpeeds_x
FUNCTION_AT_ADDRESS(void  EQOldPlayerAnimation::ChangeAttachmentAnimationTrackSpeeds(bool,float),EQOldPlayerAnimation__ChangeAttachmentAnimationTrackSpeeds);
#endif
#ifdef EQOldPlayerAnimation__IsSocialAnimation_x
FUNCTION_AT_ADDRESS(bool  EQOldPlayerAnimation::IsSocialAnimation(int),EQOldPlayerAnimation__IsSocialAnimation);
#endif
#ifdef EQOldPlayerAnimation__IsStandAnimation_x
FUNCTION_AT_ADDRESS(bool  EQOldPlayerAnimation::IsStandAnimation(int),EQOldPlayerAnimation__IsStandAnimation);
#endif
#ifdef EQOldPlayerAnimation__IsIdleAnimation_x
FUNCTION_AT_ADDRESS(bool  EQOldPlayerAnimation::IsIdleAnimation(int),EQOldPlayerAnimation__IsIdleAnimation);
#endif
#ifdef EQOldPlayerAnimation__AnimationIsAggressive_x
FUNCTION_AT_ADDRESS(bool  EQOldPlayerAnimation::AnimationIsAggressive(int),EQOldPlayerAnimation__AnimationIsAggressive);
#endif
#ifdef EQAnimation__EQAnimation_x
FUNCTION_AT_ADDRESS( EQAnimation::EQAnimation(void),EQAnimation__EQAnimation);
#endif
#ifdef EQPlayer__DoCamAi_x
FUNCTION_AT_ADDRESS(void  EQPlayer::DoCamAi(void),EQPlayer__DoCamAi);
#endif
#ifdef CVector3__Normalize_x
FUNCTION_AT_ADDRESS(void  CVector3::Normalize(void),CVector3__Normalize);
#endif
#ifdef CVector3__GetLength_x
FUNCTION_AT_ADDRESS(float  CVector3::GetLength(void)const ,CVector3__GetLength);
#endif
#ifdef CVector3__NormalizeAndReturnLength_x
FUNCTION_AT_ADDRESS(float  CVector3::NormalizeAndReturnLength(void),CVector3__NormalizeAndReturnLength);
#endif
#ifdef EQEffect__EQEffect_x
FUNCTION_AT_ADDRESS( EQEffect::EQEffect(class EQEffect *,char *,int,struct _EQLOC *,class EQPlayer *,class EQMissile *,struct _EQRGB *,float,int,int,float,float),EQEffect__EQEffect);
#endif
#ifdef EQEffect__dEQEffect_x
FUNCTION_AT_ADDRESS( EQEffect::~EQEffect(void),EQEffect__dEQEffect);
#endif
#ifdef CEverQuest__msgStartIcon_x
FUNCTION_AT_ADDRESS(int  CEverQuest::msgStartIcon(void *),CEverQuest__msgStartIcon);
#endif
#ifdef CEverQuest__msgStartInotes_x
FUNCTION_AT_ADDRESS(int  CEverQuest::msgStartInotes(void *),CEverQuest__msgStartInotes);
#endif
#ifdef CEverQuest__msgStartIeq_x
FUNCTION_AT_ADDRESS(int  CEverQuest::msgStartIeq(void *),CEverQuest__msgStartIeq);
#endif
#ifdef CEverQuest__HandleItems_x
FUNCTION_AT_ADDRESS(int  CEverQuest::HandleItems(void *,int),CEverQuest__HandleItems);
#endif
#ifdef CEverQuest__HandleWorldMessage_x
FUNCTION_AT_ADDRESS(unsigned char  CEverQuest::HandleWorldMessage(struct connection_t *,unsigned __int32,char *,unsigned __int32),CEverQuest__HandleWorldMessage);
#endif
#ifdef EQHSprite__EQHSprite_x
FUNCTION_AT_ADDRESS( EQHSprite::EQHSprite(char *,struct T3D_tagACTORINSTANCE *,class EQPlayer *),EQHSprite__EQHSprite);
#endif
#ifdef EQHSprite__dEQHSprite_x
FUNCTION_AT_ADDRESS( EQHSprite::~EQHSprite(void),EQHSprite__dEQHSprite);
#endif
#ifdef EQHSprite__get_object_x
FUNCTION_AT_ADDRESS(class EQHSprite *  EQHSprite::get_object(char *),EQHSprite__get_object);
#endif
#ifdef EQHSprite__GetAnimationTrackPtr_x
FUNCTION_AT_ADDRESS(bool  EQHSprite::GetAnimationTrackPtr(char *,char *,int,int,unsigned char,int),EQHSprite__GetAnimationTrackPtr);
#endif
#ifdef EQItemList__EQItemList_x
FUNCTION_AT_ADDRESS( EQItemList::EQItemList(void),EQItemList__EQItemList);
#endif
#ifdef EQItemList__dEQItemList_x
FUNCTION_AT_ADDRESS( EQItemList::~EQItemList(void),EQItemList__dEQItemList);
#endif
#ifdef EQItemList__get_item_x
FUNCTION_AT_ADDRESS(class EQItemList *  EQItemList::get_item(long),EQItemList__get_item);
#endif
#ifdef EQItemList__is_item_actor_x
FUNCTION_AT_ADDRESS(class EQItemList *  EQItemList::is_item_actor(struct T3D_tagACTORINSTANCE *),EQItemList__is_item_actor);
#endif
#ifdef public_key__dpublic_key_x
FUNCTION_AT_ADDRESS( public_key::~public_key(void),public_key__dpublic_key);
#endif
#ifdef public_key__public_key_x
FUNCTION_AT_ADDRESS( public_key::public_key(void),public_key__public_key);
#endif
#ifdef PacketPackerManager__Initialize_x
FUNCTION_AT_ADDRESS(void __cdecl PacketPackerManager::Initialize(void),PacketPackerManager__Initialize);
#endif
#ifdef EQMissile__EQMissile_x
FUNCTION_AT_ADDRESS( EQMissile::EQMissile(class EQ_Equipment *,class EQPlayer *,class EQMissile *,char *,unsigned char,unsigned int),EQMissile__EQMissile);
#endif
#ifdef EQMissile__dEQMissile_x
FUNCTION_AT_ADDRESS( EQMissile::~EQMissile(void),EQMissile__dEQMissile);
#endif
#ifdef EQMissile__CleanUpMyEffects_x
FUNCTION_AT_ADDRESS(void  EQMissile::CleanUpMyEffects(void),EQMissile__CleanUpMyEffects);
#endif
#ifdef EQMissile__is_missile_actor_x
FUNCTION_AT_ADDRESS(class EQMissile *  EQMissile::is_missile_actor(struct T3D_tagACTORINSTANCE *),EQMissile__is_missile_actor);
#endif
#ifdef EQMissile__HitActor_x
FUNCTION_AT_ADDRESS(void  EQMissile::HitActor(struct T3D_tagACTORINSTANCE *,bool),EQMissile__HitActor);
#endif
#ifdef EQMissile__ProcessMissile_x
FUNCTION_AT_ADDRESS(void  EQMissile::ProcessMissile(void),EQMissile__ProcessMissile);
#endif
#ifdef EQMissile__MissileAI_x
FUNCTION_AT_ADDRESS(void  EQMissile::MissileAI(void),EQMissile__MissileAI);
#endif
#ifdef EQMoneyList__EQMoneyList_x
FUNCTION_AT_ADDRESS( EQMoneyList::EQMoneyList(void),EQMoneyList__EQMoneyList);
#endif
#ifdef EQMoneyList__dEQMoneyList_x
FUNCTION_AT_ADDRESS( EQMoneyList::~EQMoneyList(void),EQMoneyList__dEQMoneyList);
#endif
#ifdef EQMoneyList__get_money_x
FUNCTION_AT_ADDRESS(class EQMoneyList *  EQMoneyList::get_money(long),EQMoneyList__get_money);
#endif
#ifdef CDisplay__MoveMissile_x
FUNCTION_AT_ADDRESS(int  CDisplay::MoveMissile(class EQMissile *),CDisplay__MoveMissile);
#endif
#ifdef CDisplay__GetOnActor_x
FUNCTION_AT_ADDRESS(void  CDisplay::GetOnActor(struct T3D_tagACTORINSTANCE *,class EQPlayer *),CDisplay__GetOnActor);
#endif
#ifdef EQPlayer__CanIFitHere_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::CanIFitHere(float,float,float),EQPlayer__CanIFitHere);
#endif
#ifdef EQPlayer__MovePlayer_x
FUNCTION_AT_ADDRESS(int  EQPlayer::MovePlayer(void),EQPlayer__MovePlayer);
#endif
#ifdef bad_word_class__bad_word_class_x
FUNCTION_AT_ADDRESS( bad_word_class::bad_word_class(char *),bad_word_class__bad_word_class);
#endif
#ifdef EQObject__EQObject_x
FUNCTION_AT_ADDRESS( EQObject::EQObject(class EQObject *,class EQPlayer *,char *,char *),EQObject__EQObject);
#endif
#ifdef EQObject__dEQObject_x
FUNCTION_AT_ADDRESS( EQObject::~EQObject(void),EQObject__dEQObject);
#endif
#ifdef EQPlacedItemManager__Instance_x
FUNCTION_AT_ADDRESS(EQPlacedItemManager& EQPlacedItemManager::Instance(),EQPlacedItemManager__Instance);
#endif
#ifdef EQPlacedItemManager__GetItemByGuid_x
FUNCTION_AT_ADDRESS(EQPlacedItem * EQPlacedItemManager::GetItemByGuid(const EqItemGuid& ItemGuid),EQPlacedItemManager__GetItemByGuid);
#endif
#ifdef EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x
FUNCTION_AT_ADDRESS(EQPlacedItem * EQPlacedItemManager::GetItemByRealEstateAndRealEstateItemIds(int RealEstateID, int RealEstateItemID),EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds);
#endif
#ifdef RealEstateManagerClient__Instance_x
FUNCTION_AT_ADDRESS(RealEstateManagerClient &RealEstateManagerClient::Instance(),RealEstateManagerClient__Instance)
#endif
#ifdef RealEstateManagerClient__GetItemByRealEstateAndItemIds_x
FUNCTION_AT_ADDRESS(const RealEstateItemClient *RealEstateManagerClient::GetItemByRealEstateAndItemIds(int realEstateID, int realEstateItemID) const,RealEstateManagerClient__GetItemByRealEstateAndItemIds)
#endif
#ifdef FactionManagerClient__Instance_x
FUNCTION_AT_ADDRESS(FactionManagerClient &FactionManagerClient::Instance(),FactionManagerClient__Instance)
#endif
#ifdef FactionManagerClient__HandleFactionMessage_x
FUNCTION_AT_ADDRESS(void FactionManagerClient::HandleFactionMessage(UINT MessageID, PCHAR pData, unsigned int DataLength),FactionManagerClient__HandleFactionMessage)
#endif
#ifdef EQPlayer__EQPlayer_x
FUNCTION_AT_ADDRESS( EQPlayer::EQPlayer(class EQPlayer *,unsigned char,unsigned int,unsigned char,char *),EQPlayer__EQPlayer);
#endif
#ifdef EQPlayer__dEQPlayer_x
FUNCTION_AT_ADDRESS( EQPlayer::~EQPlayer(void),EQPlayer__dEQPlayer);
#endif
#ifdef EQPlayer__ResetVariables_x
FUNCTION_AT_ADDRESS(void  EQPlayer::ResetVariables(void),EQPlayer__ResetVariables);
#endif
#ifdef EQPlayer__do_change_form_x
FUNCTION_AT_ADDRESS(void  EQPlayer::do_change_form(struct chngForm *),EQPlayer__do_change_form);
#endif
#ifdef EQPlayer__DisplayWeaponsAndArmor_x
FUNCTION_AT_ADDRESS(void  EQPlayer::DisplayWeaponsAndArmor(void),EQPlayer__DisplayWeaponsAndArmor);
#endif
#ifdef EQPlayer__CleanUpTarget_x
FUNCTION_AT_ADDRESS(void  EQPlayer::CleanUpTarget(void),EQPlayer__CleanUpTarget);
#endif
#ifdef EQPlayer__FollowPlayerAI_x
FUNCTION_AT_ADDRESS(void  EQPlayer::FollowPlayerAI(void),EQPlayer__FollowPlayerAI);
#endif
#ifdef EQPlayer__TurnOffAutoFollow_x
FUNCTION_AT_ADDRESS(void  EQPlayer::TurnOffAutoFollow(void),EQPlayer__TurnOffAutoFollow);
#endif
#ifdef EQPlayer__AimAtTarget_x
FUNCTION_AT_ADDRESS(int  EQPlayer::AimAtTarget(class EQPlayer *,class EQMissile *),EQPlayer__AimAtTarget);
#endif
#ifdef EQPlayer__FacePlayer_x
FUNCTION_AT_ADDRESS(void  EQPlayer::FacePlayer(class EQPlayer *),EQPlayer__FacePlayer);
#endif
#ifdef EQPlayer__CleanUpVehicle_x
FUNCTION_AT_ADDRESS(void  EQPlayer::CleanUpVehicle(void),EQPlayer__CleanUpVehicle);
#endif
#ifdef EQPlayer__CleanUpMyEffects_x
FUNCTION_AT_ADDRESS(void  EQPlayer::CleanUpMyEffects(void),EQPlayer__CleanUpMyEffects);
#endif
#ifdef EQPlayer__GetPlayerFromName_x
FUNCTION_AT_ADDRESS(class EQPlayer *__cdecl EQPlayer::GetPlayerFromName(char const *),EQPlayer__GetPlayerFromName);
#endif
#ifdef EQPlayer__GetPlayerFromPartialName_x
FUNCTION_AT_ADDRESS(class EQPlayer * __cdecl EQPlayer::GetPlayerFromPartialName(char *),EQPlayer__GetPlayerFromPartialName);
#endif
#ifdef EQPlayer__GetClosestPlayerFromPartialName_x
FUNCTION_AT_ADDRESS(class EQPlayer * __cdecl EQPlayer::GetClosestPlayerFromPartialName(char *,class EQPlayer *),EQPlayer__GetClosestPlayerFromPartialName);
#endif
#ifdef EQPlayer__IsPlayerActor_x
FUNCTION_AT_ADDRESS(class EQPlayer * __cdecl EQPlayer::IsPlayerActor(struct T3D_tagACTORINSTANCE *),EQPlayer__IsPlayerActor);
#endif
#ifdef EQPlayer__TackOnNeuterChar_x
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::TackOnNeuterChar(char *,unsigned int),EQPlayer__TackOnNeuterChar);
#endif
#ifdef EQPlayer__GetActorTag_x
FUNCTION_AT_ADDRESS(void  EQPlayer::GetActorTag(char *),EQPlayer__GetActorTag);
#endif
#ifdef EQPlayer__GetPCActorTag_x
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::GetPCActorTag(char *,unsigned int,unsigned char),EQPlayer__GetPCActorTag);
#endif
#ifdef EQPlayer__NotOnSameDeity_x
FUNCTION_AT_ADDRESS(int  EQPlayer::NotOnSameDeity(class EQPlayer *,class EQ_Spell *),EQPlayer__NotOnSameDeity);
#endif
#ifdef EQPlayer__SetAnimVariation_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetAnimVariation(void),EQPlayer__SetAnimVariation);
#endif
#ifdef EQPlayer__SetAfk_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetAfk(int),EQPlayer__SetAfk);
#endif
#ifdef EQPlayer__AllowedToAttack_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::AllowedToAttack(class EQPlayer *,int),EQPlayer__AllowedToAttack);
#endif
#ifdef EQPlayer__CanIHit_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::CanIHit(class EQPlayer *,float),EQPlayer__CanIHit);
#endif
#ifdef EQPlayer__CanSee_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::CanSee(class EQPlayer *), EQPlayer__CanSee);
#endif
#ifdef EQPlayer__CanSee1_x
FUNCTION_AT_ADDRESS(bool EQPlayer::CanSee(CVector3 *pos), EQPlayer__CanSee1);
#endif
#ifdef EQPlayer__ModifyAttackSpeed_x
FUNCTION_AT_ADDRESS(unsigned int  EQPlayer::ModifyAttackSpeed(unsigned int,int),EQPlayer__ModifyAttackSpeed);
#endif
#ifdef EQPlayer__DoAttack_x
	#if defined(ROF2EMU) || defined(UFEMU)
		FUNCTION_AT_ADDRESS(bool EQPlayer::DoAttack(BYTE,BYTE,EQPlayer *),EQPlayer__DoAttack);
	#else
		FUNCTION_AT_ADDRESS(bool EQPlayer::DoAttack(BYTE,BYTE,EQPlayer *,bool,bool,bool),EQPlayer__DoAttack);
	#endif
#endif
#ifdef EQPlayer__HandleAmmo_x
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::HandleAmmo(void),EQPlayer__HandleAmmo);
#endif
#ifdef EQPlayer__TriggerSpellEffect_x
FUNCTION_AT_ADDRESS(void  EQPlayer::TriggerSpellEffect(struct _EQMissileHitinfo *),EQPlayer__TriggerSpellEffect);
#endif
#ifdef EQPlayer__IWasHit_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::IWasHit(struct _EQMissileHitinfo *),EQPlayer__IWasHit);
#endif
#ifdef EQPlayer__GetConscious_x
FUNCTION_AT_ADDRESS(void  EQPlayer::GetConscious(void),EQPlayer__GetConscious);
#endif
#ifdef EQPlayer__KnockedOut_x
FUNCTION_AT_ADDRESS(void  EQPlayer::KnockedOut(void),EQPlayer__KnockedOut);
#endif
#ifdef EQPlayer__IDied_x
FUNCTION_AT_ADDRESS(void  EQPlayer::IDied(struct _EQPlayerDeath *),EQPlayer__IDied);
#endif
#ifdef EQPlayer__HandoverControlToZoneserver_x
FUNCTION_AT_ADDRESS(void  EQPlayer::HandoverControlToZoneserver(void),EQPlayer__HandoverControlToZoneserver);
#endif
#ifdef EQPlayer__TouchingSwitch_x
FUNCTION_AT_ADDRESS(void  EQPlayer::TouchingSwitch(void),EQPlayer__TouchingSwitch);
#endif
#ifdef EQPlayer__MyFeetAreOnGround_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::MyFeetAreOnGround(void),EQPlayer__MyFeetAreOnGround);
#endif
#ifdef EQPlayer__IHaveFallen_x
FUNCTION_AT_ADDRESS(void  EQPlayer::IHaveFallen(float),EQPlayer__IHaveFallen);
#endif
#ifdef EQPlayer__SkillUsed_x
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::SkillUsed(unsigned char),EQPlayer__SkillUsed);
#endif
#ifdef EQPlayer__BodyEnvironmentChange_x
FUNCTION_AT_ADDRESS(void  EQPlayer::BodyEnvironmentChange(unsigned char),EQPlayer__BodyEnvironmentChange);
#endif
#ifdef EQPlayer__FeetEnvironmentChange_x
FUNCTION_AT_ADDRESS(void  EQPlayer::FeetEnvironmentChange(unsigned char),EQPlayer__FeetEnvironmentChange);
#endif
#ifdef EQPlayer__HeadEnvironmentChange_x
FUNCTION_AT_ADDRESS(void  EQPlayer::HeadEnvironmentChange(unsigned char),EQPlayer__HeadEnvironmentChange);
#endif
#ifdef PlayerZoneClient__LegalPlayerRace_x
FUNCTION_AT_ADDRESS(int PlayerZoneClient::LegalPlayerRace(int),PlayerZoneClient__LegalPlayerRace);
#endif
#ifdef EQPlayer__DeleteMyMissiles_x
FUNCTION_AT_ADDRESS(void  EQPlayer::DeleteMyMissiles(void),EQPlayer__DeleteMyMissiles);
#endif
#ifdef EQPlayer__ChangePosition_x
FUNCTION_AT_ADDRESS(void  EQPlayer::ChangePosition(unsigned char),EQPlayer__ChangePosition);
#endif
#ifdef EQPlayer__ChangeHeight_x
FUNCTION_AT_ADDRESS(void  EQPlayer::ChangeHeight(float),EQPlayer__ChangeHeight);
#endif
#ifdef EQPlayer__PositionOnFloor_x
FUNCTION_AT_ADDRESS(void  EQPlayer::PositionOnFloor(void),EQPlayer__PositionOnFloor);
#endif
#ifdef EQPlayer__IsRoleplaying_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::IsRoleplaying(void),EQPlayer__IsRoleplaying);
#endif
#ifdef EQPlayer__IsInvited_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::IsInvited(void),EQPlayer__IsInvited);
#endif
#ifdef EQPlayer__SetInvited_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetInvited(bool),EQPlayer__SetInvited);
#endif
#ifdef EQPlayer__PlaySoundA_x
FUNCTION_AT_ADDRESS(void  EQPlayer::PlaySoundA(int),EQPlayer__PlaySoundA);
#endif
#ifdef EQPlayer__SetSounds_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetSounds(void),EQPlayer__SetSounds);
#endif
#ifdef EQPlayer__SetCurrentLoopSound_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetCurrentLoopSound(int),EQPlayer__SetCurrentLoopSound);
#endif
#ifdef EQPlayer__IsFlyer_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::IsFlyer(void),EQPlayer__IsFlyer);
#endif
#ifdef EQPlayer__InitSneakMod_x
FUNCTION_AT_ADDRESS(void  EQPlayer::InitSneakMod(void),EQPlayer__InitSneakMod);
#endif
#ifdef EQPlayer__SetHeights_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetHeights(void),EQPlayer__SetHeights);
#endif
#ifdef EQPMInfo__SetApplyGravity_x
FUNCTION_AT_ADDRESS(void  EQPMInfo::SetApplyGravity(bool),EQPMInfo__SetApplyGravity);
#endif
#ifdef EQPlayer__GetDefaultHeight_x
FUNCTION_AT_ADDRESS(float  EQPlayer::GetDefaultHeight(int,unsigned char),EQPlayer__GetDefaultHeight);
#endif
#ifdef EQPlayer__ComputeSpecialHeights_x
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::ComputeSpecialHeights(int,float *,float *,float *,float *,bool),EQPlayer__ComputeSpecialHeights);
#endif
#ifdef EQPlayer__IsUntexturedHorse_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::IsUntexturedHorse(void),EQPlayer__IsUntexturedHorse);
#endif
#ifdef EQPlayer__HasInvalidRiderTexture_x
FUNCTION_AT_ADDRESS(bool const  EQPlayer::HasInvalidRiderTexture(void)const ,EQPlayer__HasInvalidRiderTexture);
#endif
#ifdef EQPlayer__ForceInvisible_x
FUNCTION_AT_ADDRESS(void  EQPlayer::ForceInvisible(bool),EQPlayer__ForceInvisible);
#endif
#ifdef EQPlayer__MountableRace_x
FUNCTION_AT_ADDRESS(int  EQPlayer::MountableRace(void),EQPlayer__MountableRace);
#endif
#ifdef EQPlayer__MakeRiderMountUp_x
FUNCTION_AT_ADDRESS(void  EQPlayer::MakeRiderMountUp(void),EQPlayer__MakeRiderMountUp);
#endif
#ifdef EQPlayer__MountEQPlayer_x
FUNCTION_AT_ADDRESS(void  EQPlayer::MountEQPlayer(class EQPlayer *),EQPlayer__MountEQPlayer);
#endif
#ifdef EQPlayer__Dismount_x
FUNCTION_AT_ADDRESS(void  EQPlayer::Dismount(void),EQPlayer__Dismount);
#endif
#ifdef EQPlayer__GetArmorType_x
FUNCTION_AT_ADDRESS(int  EQPlayer::GetArmorType(int),EQPlayer__GetArmorType);
#endif
#ifdef EQPlayer__SetArmorType_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetArmorType(int,int),EQPlayer__SetArmorType);
#endif
#ifdef EQPlayer__GetArmorTint_x
FUNCTION_AT_ADDRESS(unsigned long  EQPlayer::GetArmorTint(int),EQPlayer__GetArmorTint);
#endif
#ifdef EQPlayer__SetArmorTint_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetArmorTint(int,unsigned long),EQPlayer__SetArmorTint);
#endif
#ifdef EQPlayer__SetAccel_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetAccel(float,int),EQPlayer__SetAccel);
#endif
#ifdef EQPlayer__SetToRandomRace_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetToRandomRace(void),EQPlayer__SetToRandomRace);
#endif
#ifdef EQPlayer__GetBaseFaceNbr_x
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::GetBaseFaceNbr(int,unsigned char *),EQPlayer__GetBaseFaceNbr);
#endif
#ifdef EQPlayer__HasAttachedBeard_x
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::HasAttachedBeard(void),EQPlayer__HasAttachedBeard);
#endif
#ifdef EQPlayer__HasAttachedHair_x
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::HasAttachedHair(void),EQPlayer__HasAttachedHair);
#endif
#ifdef EQPlayer__SetDefaultFacialFeaturesByFace_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetDefaultFacialFeaturesByFace(int,unsigned char,unsigned char),EQPlayer__SetDefaultFacialFeaturesByFace);
#endif
#ifdef EQPlayer__GetAllowedHairColorIndexRange_x
FUNCTION_AT_ADDRESS(void  EQPlayer::GetAllowedHairColorIndexRange(int,int *,int *),EQPlayer__GetAllowedHairColorIndexRange);
#endif
#ifdef EQPlayer__CanBeBald_x
FUNCTION_AT_ADDRESS(int  EQPlayer::CanBeBald(void),EQPlayer__CanBeBald);
#endif
#ifdef EQPlayer__ChangeNoGravity_x
FUNCTION_AT_ADDRESS(void  EQPlayer::ChangeNoGravity(int),EQPlayer__ChangeNoGravity);
#endif
#ifdef EQPlayer__IdUsed_x
FUNCTION_AT_ADDRESS(int  EQPlayer::IdUsed(unsigned int),EQPlayer__IdUsed);
#endif
#ifdef EQPlayer__GetUnusedID_x
FUNCTION_AT_ADDRESS(unsigned int  EQPlayer::GetUnusedID(void),EQPlayer__GetUnusedID);
#endif
#ifdef EQPlayer__SetAndReserveID_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetAndReserveID(unsigned int),EQPlayer__SetAndReserveID);
#endif
#ifdef EQPlayer__InitializeIDArray_x
FUNCTION_AT_ADDRESS(void  EQPlayer::InitializeIDArray(void),EQPlayer__InitializeIDArray);
#endif
#ifdef PlayerZoneClient__GetLevel_x
FUNCTION_AT_ADDRESS(BYTE EQPlayer::GetLevel(void) const,PlayerZoneClient__GetLevel);
#endif
#ifdef EQPlayer__Levitating_x
FUNCTION_AT_ADDRESS(int  EQPlayer::Levitating(void),EQPlayer__Levitating);
#endif
#ifdef EQPlayer__SetRace_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetRace(int),EQPlayer__SetRace);
#endif
#ifdef EQPlayer__CanChangeForm_x
FUNCTION_AT_ADDRESS(bool EQPlayer::CanChangeForm(int Race,BYTE Sex,float Height),EQPlayer__CanChangeForm);
#endif
#ifdef EQPlayer__SetNameSpriteState_x
FUNCTION_AT_ADDRESS(int  EQPlayer::SetNameSpriteState(bool),EQPlayer__SetNameSpriteState);
#endif
#ifdef EQPlayer__ChangeBoneStringSprite_x
FUNCTION_AT_ADDRESS(struct S3D_STRINGSPRITE *  EQPlayer::ChangeBoneStringSprite(struct T3D_DAG *,char *),EQPlayer__ChangeBoneStringSprite);
#endif
#ifdef EQPlayer__SetNameSpriteTint_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::SetNameSpriteTint(void),EQPlayer__SetNameSpriteTint);
#endif
#ifdef PlayerClient__GetPcClient_x
FUNCTION_AT_ADDRESS(PcClient *PlayerClient::GetPcClient(void)const,PlayerClient__GetPcClient);
#endif
#ifdef PcClient__PcClient_x
FUNCTION_AT_ADDRESS(PcClient::PcClient(void),PcClient__PcClient);
#endif
#ifdef EQPlayer__UpdateNameSprite_x
FUNCTION_AT_ADDRESS(void  EQPlayer::UpdateNameSprite(void),EQPlayer__UpdateNameSprite);
#endif
#ifdef EQPlayer__UpdateBonePointers_x
FUNCTION_AT_ADDRESS(void  EQPlayer::UpdateBonePointers(void),EQPlayer__UpdateBonePointers);
#endif
#ifdef EQPlayer__FindDefaultEyeMaterialIndexes_x
FUNCTION_AT_ADDRESS(void  EQPlayer::FindDefaultEyeMaterialIndexes(void),EQPlayer__FindDefaultEyeMaterialIndexes);
#endif
#ifdef EQPlayer__CalcAnimLength_x
FUNCTION_AT_ADDRESS(unsigned int  EQPlayer::CalcAnimLength(int),EQPlayer__CalcAnimLength);
#endif
#ifdef EQPlayer__GetAlternateTrackNumber_x
FUNCTION_AT_ADDRESS(int  EQPlayer::GetAlternateTrackNumber(int,unsigned char *),EQPlayer__GetAlternateTrackNumber);
#endif
#ifdef EQPlayer__GetAlternateAnimVariation_x
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::GetAlternateAnimVariation(int,unsigned char),EQPlayer__GetAlternateAnimVariation);
#endif
#ifdef EQPlayer__GetRaceSexITOffset_x
FUNCTION_AT_ADDRESS(int  EQPlayer::GetRaceSexITOffset(void),EQPlayer__GetRaceSexITOffset);
#endif
#ifdef EQPlayer__UpdatePlayerVisibility_x
FUNCTION_AT_ADDRESS(void  EQPlayer::UpdatePlayerVisibility(void),EQPlayer__UpdatePlayerVisibility);
#endif
#ifdef EQPlayer__UpdateAllPlayersVisibility_x
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::UpdateAllPlayersVisibility(void),EQPlayer__UpdateAllPlayersVisibility);
#endif
#ifdef PlayerBase__HasProperty_j_x
FUNCTION_AT_ADDRESS(bool EQPlayer::HasProperty(unsigned int,int,int),PlayerBase__HasProperty_j);
#endif
#ifdef PlayerBase__GetVisibilityLineSegment_x
FUNCTION_AT_ADDRESS(class CLineSegment &EQPlayer::GetVisibilityLineSegment(class CLineSegment&, class EQPlayer&,unsigned int),PlayerBase__GetVisibilityLineSegment);
#endif
#ifdef EQPlayer__SetEyeMaterial_x
FUNCTION_AT_ADDRESS(int  EQPlayer::SetEyeMaterial(unsigned char,int),EQPlayer__SetEyeMaterial);
#endif
#ifdef EQPlayer__HideOrShowAttachedHair_x
FUNCTION_AT_ADDRESS(void  EQPlayer::HideOrShowAttachedHair(void),EQPlayer__HideOrShowAttachedHair);
#endif
#ifdef EQPlayer__SetFHEB_x
FUNCTION_AT_ADDRESS(int  EQPlayer::SetFHEB(unsigned char,unsigned char),EQPlayer__SetFHEB);
#endif
#ifdef EQPlayer__SetFHEB_Color_x
FUNCTION_AT_ADDRESS(int  EQPlayer::SetFHEB_Color(unsigned char,unsigned char),EQPlayer__SetFHEB_Color);
#endif
#ifdef EQPlayer__SetHairOrBeard_x
FUNCTION_AT_ADDRESS(int  EQPlayer::SetHairOrBeard(int),EQPlayer__SetHairOrBeard);
#endif
#ifdef EQPlayer__GetBonePointerByITS_x
FUNCTION_AT_ADDRESS(struct T3D_DAG *  EQPlayer::GetBonePointerByITS(int,int),EQPlayer__GetBonePointerByITS);
#endif
#ifdef EQPlayer__UpdateAppearance_x
FUNCTION_AT_ADDRESS(void  EQPlayer::UpdateAppearance(void),EQPlayer__UpdateAppearance);
#endif
#ifdef EQPlayer__SetDefaultITAttachments_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetDefaultITAttachments(int),EQPlayer__SetDefaultITAttachments);
#endif
#ifdef EQPlayer__SwapMaterial_x
FUNCTION_AT_ADDRESS(int  EQPlayer::SwapMaterial(int,int,int,int,unsigned char),EQPlayer__SwapMaterial);
#endif
#ifdef EQPlayer__SwapFace_x
FUNCTION_AT_ADDRESS(int  EQPlayer::SwapFace(int,int),EQPlayer__SwapFace);
#endif
#ifdef EQPlayer__GetAttachedHelmITNum_x
FUNCTION_AT_ADDRESS(int  EQPlayer::GetAttachedHelmITNum(int,int *),EQPlayer__GetAttachedHelmITNum);
#endif
#ifdef EQPlayer__SetPlayerConstantAmbient_x
FUNCTION_AT_ADDRESS(void  EQPlayer::SetPlayerConstantAmbient(struct T3D_RGB *),EQPlayer__SetPlayerConstantAmbient);
#endif
#ifdef EQPlayer__SwapHead_x
FUNCTION_AT_ADDRESS(int  EQPlayer::SwapHead(int,int,unsigned long,int),EQPlayer__SwapHead);
#endif
#ifdef EQPlayer__SetPlayerPitchType_x
FUNCTION_AT_ADDRESS(int  EQPlayer::SetPlayerPitchType(void),EQPlayer__SetPlayerPitchType);
#endif
#ifdef PlayerZoneClient__IsValidTeleport_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IsValidTeleport(float X, float Y, float Z, float Heading, float Distance),PlayerZoneClient__IsValidTeleport);
#endif
#ifdef EQPlayer__ReplaceSpecialCloakMaterials_x
FUNCTION_AT_ADDRESS(int  EQPlayer::ReplaceSpecialCloakMaterials(void),EQPlayer__ReplaceSpecialCloakMaterials);
#endif
#ifdef EQPlayer__SwapBody_x
FUNCTION_AT_ADDRESS(int  EQPlayer::SwapBody(int,int),EQPlayer__SwapBody);
#endif
#ifdef EQPlayer__HandleMaterialEx_x
FUNCTION_AT_ADDRESS(void  EQPlayer::HandleMaterialEx(int,unsigned int,unsigned int,unsigned long,int),EQPlayer__HandleMaterialEx);
#endif
#ifdef EQPlayer__UpdateItemSlot_x
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::UpdateItemSlot(unsigned char,char *,int),EQPlayer__UpdateItemSlot);
#endif
#ifdef EQPlayer__SwapNPCMaterials_x
FUNCTION_AT_ADDRESS(int  EQPlayer::SwapNPCMaterials(void),EQPlayer__SwapNPCMaterials);
#endif
#ifdef EQPlayer__PutPlayerOnFloor_x
FUNCTION_AT_ADDRESS(void  EQPlayer::PutPlayerOnFloor(void),EQPlayer__PutPlayerOnFloor);
#endif
#ifdef EQPlayer__CheckForUnderFloor_x
FUNCTION_AT_ADDRESS(void  EQPlayer::CheckForUnderFloor(void),EQPlayer__CheckForUnderFloor);
#endif
#ifdef EQPlayer__DoFloorCheck_x
FUNCTION_AT_ADDRESS(void  EQPlayer::DoFloorCheck(void),EQPlayer__DoFloorCheck);
#endif
#ifdef EQPlayer__DoSwimJump_x
FUNCTION_AT_ADDRESS(void  EQPlayer::DoSwimJump(unsigned char),EQPlayer__DoSwimJump);
#endif
#ifdef EQPlayer__PushAlongHeading_x
FUNCTION_AT_ADDRESS(void  EQPlayer::PushAlongHeading(float),EQPlayer__PushAlongHeading);
#endif
#ifdef EQPlayer__DoTeleport_x
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::DoTeleport(char *,int),EQPlayer__DoTeleport);
#endif
#ifdef EQPlayer__DoTeleportB_x
//FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::DoTeleportB(int,float,float,float,float,char *,enum ZONE_REQ_REASON),EQPlayer__DoTeleportB);
#endif
#ifdef EQPlayer__ChangeLight_x
FUNCTION_AT_ADDRESS(void  EQPlayer::ChangeLight(void),EQPlayer__ChangeLight);
#endif
#ifdef EQPlayer__GetBoneCoords_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::GetBoneCoords(struct T3D_DAG *,struct _EQLOC *),EQPlayer__GetBoneCoords);
#endif
#ifdef EQPlayer__CheckForJump_x
FUNCTION_AT_ADDRESS(int  EQPlayer::CheckForJump(void),EQPlayer__CheckForJump);
#endif
#ifdef EQPlayer__GetPlayerFloorHeight_x
FUNCTION_AT_ADDRESS(float  EQPlayer::GetPlayerFloorHeight(float,float,float,unsigned char),EQPlayer__GetPlayerFloorHeight);
#endif
#ifdef EQPlayer__UpdatePlayerActor_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::UpdatePlayerActor(void),EQPlayer__UpdatePlayerActor);
#endif
#ifdef EQPlayer__GetNearestActorTag_x
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::GetNearestActorTag(char *,void *),EQPlayer__GetNearestActorTag);
#endif
#ifdef EQPlayer__DoItemSlot_x
FUNCTION_AT_ADDRESS(void  EQPlayer::DoItemSlot(int),EQPlayer__DoItemSlot);
#endif
#ifdef EQPlayer__DoClassRandomAnimation_x
FUNCTION_AT_ADDRESS(void  EQPlayer::DoClassRandomAnimation(void),EQPlayer__DoClassRandomAnimation);
#endif
#ifdef EQPlayer__CreateUserLight_x
FUNCTION_AT_ADDRESS(struct T3D_POINTLIGHT *  EQPlayer::CreateUserLight(struct T3D_LIGHTDEFINITION *,int),EQPlayer__CreateUserLight);
#endif
#ifdef EQPlayer__AttachPlayerToPlayerBone_x
FUNCTION_AT_ADDRESS(int  EQPlayer::AttachPlayerToPlayerBone(class EQPlayer *,struct T3D_DAG *),EQPlayer__AttachPlayerToPlayerBone);
#endif
#ifdef EQPlayer__IsInvisible_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::IsInvisible(class EQPlayer *),EQPlayer__IsInvisible);
#endif
#ifdef EQPlayer__IsAMount_x
FUNCTION_AT_ADDRESS(bool  EQPlayer::IsAMount(void),EQPlayer__IsAMount);
#endif
#ifdef EQPlayerManager__GetSpawnByID_x
FUNCTION_AT_ADDRESS(class EQPlayer * EQPlayerManager::GetSpawnByID(int),EQPlayerManager__GetSpawnByID);
#endif
#ifdef EQPlayerManager__GetSpawnByName_x
FUNCTION_AT_ADDRESS(class EQPlayer * EQPlayerManager::GetSpawnByName(char *),EQPlayerManager__GetSpawnByName);
#endif
#ifdef EQPlayerManager__GetPlayerFromPartialName_x
FUNCTION_AT_ADDRESS(class EQPlayer * EQPlayerManager::GetPlayerFromPartialName(char const*,class PlayerBase *),EQPlayerManager__GetPlayerFromPartialName);
#endif
#ifdef EQPlayerManager__GetSpawnByName2_x
FUNCTION_AT_ADDRESS(class EQPlayer * EQPlayerManager::GetSpawnByName2(CXStr *,int),EQPlayerManager__GetSpawnByName2);
#endif
#ifdef EQPMInfo__EQPMInfo_x
FUNCTION_AT_ADDRESS( EQPMInfo::EQPMInfo(char *),EQPMInfo__EQPMInfo);
#endif
#ifdef EQPMInfo__dEQPMInfo_x
FUNCTION_AT_ADDRESS( EQPMInfo::~EQPMInfo(void),EQPMInfo__dEQPMInfo);
#endif
#ifdef EQSwitch__EQSwitch_x
FUNCTION_AT_ADDRESS( EQSwitch::EQSwitch(char *,bool),EQSwitch__EQSwitch);
#endif
#ifdef EQSwitch__EQSwitch1_x
FUNCTION_AT_ADDRESS( EQSwitch::EQSwitch(struct OldDiskSwitch *,bool),EQSwitch__EQSwitch1);
#endif
#ifdef EQSwitch__EQSwitch2_x
FUNCTION_AT_ADDRESS( EQSwitch::EQSwitch(struct _EQClientSwitch *),EQSwitch__EQSwitch2);
#endif
#ifdef EQSwitch__PreInit_x
FUNCTION_AT_ADDRESS(void  EQSwitch::PreInit(void),EQSwitch__PreInit);
#endif
#ifdef EQSwitch__PostInit_x
FUNCTION_AT_ADDRESS(void  EQSwitch::PostInit(void),EQSwitch__PostInit);
#endif
#ifdef EQSwitch__dEQSwitch_x
FUNCTION_AT_ADDRESS( EQSwitch::~EQSwitch(void),EQSwitch__dEQSwitch);
#endif
#ifdef EQSwitch__ResetSwitchState_x
FUNCTION_AT_ADDRESS(void  EQSwitch::ResetSwitchState(unsigned char),EQSwitch__ResetSwitchState);
#endif
#ifdef EQSwitch__RepopSwitch_x
FUNCTION_AT_ADDRESS(void  EQSwitch::RepopSwitch(void),EQSwitch__RepopSwitch);
#endif
#ifdef EQSwitch__TopSpeed_x
FUNCTION_AT_ADDRESS(float  EQSwitch::TopSpeed(float *),EQSwitch__TopSpeed);
#endif
#ifdef EQSwitch__RepopFrequency_x
FUNCTION_AT_ADDRESS(unsigned int  EQSwitch::RepopFrequency(void),EQSwitch__RepopFrequency);
#endif
#ifdef EQSwitch__GetSwitchDamage_x
FUNCTION_AT_ADDRESS(int  EQSwitch::GetSwitchDamage(void),EQSwitch__GetSwitchDamage);
#endif
#ifdef EQSwitch__ChangeState_x
FUNCTION_AT_ADDRESS(void  EQSwitch::ChangeState(unsigned char,class EQPlayer *,bool),EQSwitch__ChangeState);
#endif
#ifdef EQSwitch__SwitchWasOpened_x
FUNCTION_AT_ADDRESS(unsigned char  EQSwitch::SwitchWasOpened(int,int,class EQPlayer *,bool *),EQSwitch__SwitchWasOpened);
#endif
#ifdef EQSwitch__SwitchWasOpenedActual_x
FUNCTION_AT_ADDRESS(unsigned char  EQSwitch::SwitchWasOpenedActual(int,int,class EQPlayer *,bool *),EQSwitch__SwitchWasOpenedActual);
#endif
#ifdef EQSwitch__SwitchIsNotUsable_x
FUNCTION_AT_ADDRESS(unsigned char  EQSwitch::SwitchIsNotUsable(int),EQSwitch__SwitchIsNotUsable);
#endif
#ifdef EQSwitch__UseSwitch_x
FUNCTION_AT_ADDRESS(void  EQSwitch::UseSwitch(UINT,int,int,const CVector3*),EQSwitch__UseSwitch);
#endif
#ifdef EQSwitch__LoadSwitchSounds_x
FUNCTION_AT_ADDRESS(void  EQSwitch::LoadSwitchSounds(int),EQSwitch__LoadSwitchSounds);
#endif
#ifdef EQSwitch__GetCustomMoveDistance_x
FUNCTION_AT_ADDRESS(float  EQSwitch::GetCustomMoveDistance(void),EQSwitch__GetCustomMoveDistance);
#endif
#ifdef EqSwitchManager__EqSwitchManager_x
FUNCTION_AT_ADDRESS( EqSwitchManager::EqSwitchManager(void),EqSwitchManager__EqSwitchManager);
#endif
#ifdef EqSwitchManager__dEqSwitchManager_x
FUNCTION_AT_ADDRESS( EqSwitchManager::~EqSwitchManager(void),EqSwitchManager__dEqSwitchManager);
#endif
#ifdef EqSwitchManager__DeleteAll_x
FUNCTION_AT_ADDRESS(void  EqSwitchManager::DeleteAll(void),EqSwitchManager__DeleteAll);
#endif
#ifdef EqSwitchManager__Load_x
FUNCTION_AT_ADDRESS(void  EqSwitchManager::Load(char *,bool),EqSwitchManager__Load);
#endif
#ifdef EqSwitchManager__LoadOld_x
FUNCTION_AT_ADDRESS(void  EqSwitchManager::LoadOld(char *,bool),EqSwitchManager__LoadOld);
#endif
#ifdef EqSwitchManager__GetCount_x
FUNCTION_AT_ADDRESS(int  EqSwitchManager::GetCount(void),EqSwitchManager__GetCount);
#endif
#ifdef EqSwitchManager__GetSwitchByActor_x
FUNCTION_AT_ADDRESS(class EQSwitch *  EqSwitchManager::GetSwitchByActor(struct T3D_tagACTORINSTANCE *),EqSwitchManager__GetSwitchByActor);
#endif
#ifdef EqSwitchManager__GetSwitch_x
FUNCTION_AT_ADDRESS(class EQSwitch *  EqSwitchManager::GetSwitch(int),EqSwitchManager__GetSwitch);
#endif
#ifdef EqSwitchManager__GetSwitchById_x
FUNCTION_AT_ADDRESS(class EQSwitch *  EqSwitchManager::GetSwitchById(int,bool),EqSwitchManager__GetSwitchById);
#endif
#ifdef EqSwitchManager__AddSwitch_x
FUNCTION_AT_ADDRESS(void  EqSwitchManager::AddSwitch(class EQSwitch *),EqSwitchManager__AddSwitch);
#endif
#ifdef Util__GetNextToken_x
FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextToken(char *,int *,char *),Util__GetNextToken);
#endif
#ifdef Util__GetNextToken1_x
FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextToken(char *,short *,char *),Util__GetNextToken1);
#endif
#ifdef Util__GetNextToken2_x
FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextToken(char *,char *,char *),Util__GetNextToken2);
#endif
#ifdef Util__GetNextToken3_x
FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextToken(char *,unsigned char *,char *),Util__GetNextToken3);
#endif
#ifdef EQUtil__FormatCharName_x
FUNCTION_AT_ADDRESS(char * __cdecl EQUtil::FormatCharName(char *,char *,int),EQUtil__FormatCharName);
#endif
#ifdef EQWorldData__EQWorldData_x
FUNCTION_AT_ADDRESS( EQWorldData::EQWorldData(void),EQWorldData__EQWorldData);
#endif
#ifdef EQWorldData__AddZone_x
//FUNCTION_AT_ADDRESS(bool const  EQWorldData::AddZone(enum EQExpansion,enum EQZoneIndex,char const *,char const *,int,unsigned long,int,int),EQWorldData__AddZone);
#endif
#ifdef EQWorldData__AdvanceTime_x
FUNCTION_AT_ADDRESS(void  EQWorldData::AdvanceTime(unsigned int),EQWorldData__AdvanceTime);
#endif
#ifdef EQWorldData__CurrentGameTime_x
FUNCTION_AT_ADDRESS(void  EQWorldData::CurrentGameTime(char *),EQWorldData__CurrentGameTime);
#endif
#ifdef EQWorldData__GetFullZoneName_x
//FUNCTION_AT_ADDRESS(void  EQWorldData::GetFullZoneName(enum EQZoneIndex,char *),EQWorldData__GetFullZoneName);
#endif
#ifdef EQWorldData__ExpansionZone_x
//FUNCTION_AT_ADDRESS(enum EQExpansion const  EQWorldData::ExpansionZone(enum EQZoneIndex)const ,EQWorldData__ExpansionZone);
#endif
#ifdef EQWorldData__IsFlagSet_x
//FUNCTION_AT_ADDRESS(bool  EQWorldData::IsFlagSet(enum EQZoneIndex,unsigned long)const,EQWorldData__IsFlagSet);
#endif
#ifdef EQWorldData__IsNewbieZone_x
//FUNCTION_AT_ADDRESS(bool  EQWorldData::IsNewbieZone(enum EQZoneIndex)const,EQWorldData__IsNewbieZone);
#endif
#ifdef EQWorldData__IsNoBindZone_x
//FUNCTION_AT_ADDRESS(bool  EQWorldData::IsNoBindZone(enum EQZoneIndex)const,EQWorldData__IsNoBindZone);
#endif
#ifdef EQWorldData__IsNoAirZone_x
//FUNCTION_AT_ADDRESS(bool  EQWorldData::IsNoAirZone(enum EQZoneIndex)const,EQWorldData__IsNoAirZone);
#endif
#ifdef EQWorldData__GetMinLevel_x
//FUNCTION_AT_ADDRESS(int  EQWorldData::GetMinLevel(enum EQZoneIndex)const,EQWorldData__GetMinLevel);
#endif
#ifdef EQWorldData__GetGeometryNameFromIndex_x
//FUNCTION_AT_ADDRESS(bool  EQWorldData::GetGeometryNameFromIndex(enum EQZoneIndex,char *)const ,EQWorldData__GetGeometryNameFromIndex);
#endif
#ifdef EQWorldData__GetIndexFromZoneName_x
//FUNCTION_AT_ADDRESS(enum EQZoneIndex  EQWorldData::GetIndexFromZoneName(char const *)const ,EQWorldData__GetIndexFromZoneName);
#endif
#ifdef EQZoneInfo__EQZoneInfo_x
//FUNCTION_AT_ADDRESS( EQZoneInfo::EQZoneInfo(enum EQExpansion,enum EQZoneIndex,char const *,char const *,int,unsigned long,int,int),EQZoneInfo__EQZoneInfo);
#endif
#ifdef CEverQuest__ChatServerGiveTime_x
FUNCTION_AT_ADDRESS(void  CEverQuest::ChatServerGiveTime(void),CEverQuest__ChatServerGiveTime);
#endif
#ifdef CEverQuest__ChatServerNotificationAdd_x
FUNCTION_AT_ADDRESS(void  CEverQuest::ChatServerNotificationAdd(bool,char *,char *,int),CEverQuest__ChatServerNotificationAdd);
#endif
#ifdef CEverQuest__ChatServerNotificationFlush_x
FUNCTION_AT_ADDRESS(void  CEverQuest::ChatServerNotificationFlush(void),CEverQuest__ChatServerNotificationFlush);
#endif
#ifdef CEverQuest__ChatServerConnect_x
FUNCTION_AT_ADDRESS(void  CEverQuest::ChatServerConnect(char *,int,char *,char *),CEverQuest__ChatServerConnect);
#endif
#ifdef CEverQuest__ChatServerMessage_x
FUNCTION_AT_ADDRESS(void  CEverQuest::ChatServerMessage(char *),CEverQuest__ChatServerMessage);
#endif
#ifdef CEverQuest__ChatServerDisconnect_x
FUNCTION_AT_ADDRESS(void  CEverQuest::ChatServerDisconnect(void),CEverQuest__ChatServerDisconnect);
#endif
#ifdef CEverQuest__ResetVisionRGBs_x
FUNCTION_AT_ADDRESS(void  CEverQuest::ResetVisionRGBs(void),CEverQuest__ResetVisionRGBs);
#endif
#ifdef CEverQuest__GetMaxLightRadius_x
FUNCTION_AT_ADDRESS(float  CEverQuest::GetMaxLightRadius(void),CEverQuest__GetMaxLightRadius);
#endif
#ifdef CEverQuest__LoadStringTables_x
FUNCTION_AT_ADDRESS(void  CEverQuest::LoadStringTables(void),CEverQuest__LoadStringTables);
#endif
#ifdef CEverQuest__CEverQuest_x
FUNCTION_AT_ADDRESS( CEverQuest::CEverQuest(struct HWND__ *),CEverQuest__CEverQuest);
#endif
#ifdef CEverQuest__dCEverQuest_x
FUNCTION_AT_ADDRESS( CEverQuest::~CEverQuest(void),CEverQuest__dCEverQuest);
#endif
#ifdef CEverQuest__ProcessMBox_x
FUNCTION_AT_ADDRESS(int  CEverQuest::ProcessMBox(void),CEverQuest__ProcessMBox);
#endif
#ifdef CEverQuest__UseCharge_x
FUNCTION_AT_ADDRESS(void  CEverQuest::UseCharge(unsigned long),CEverQuest__UseCharge);
#endif
#ifdef CEverQuest__LeaveGuildMaster_x
FUNCTION_AT_ADDRESS(void  CEverQuest::LeaveGuildMaster(void),CEverQuest__LeaveGuildMaster);
#endif
#ifdef CEverQuest__LeaveBankMode_x
FUNCTION_AT_ADDRESS(void  CEverQuest::LeaveBankMode(bool),CEverQuest__LeaveBankMode);
#endif
#ifdef CEverQuest__ReportDeath_x
FUNCTION_AT_ADDRESS(void  CEverQuest::ReportDeath(struct _EQPlayerDeath *),CEverQuest__ReportDeath);
#endif
#ifdef CEverQuest__SetDefaultDamageDescByRace_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SetDefaultDamageDescByRace(char *,int,unsigned char),CEverQuest__SetDefaultDamageDescByRace);
#endif
#ifdef CEverQuest__ReportSuccessfulHit_x
FUNCTION_AT_ADDRESS(void CEverQuest::ReportSuccessfulHit(EQSuccessfulHit *pHit,unsigned char bOutputText,int ActualHeal),CEverQuest__ReportSuccessfulHit);
#endif
#ifdef CEverQuest__GetCombatSound_x
FUNCTION_AT_ADDRESS(int  CEverQuest::GetCombatSound(class EQPlayer *,class EQPlayer *),CEverQuest__GetCombatSound);
#endif
#ifdef CEverQuest__LocalDeath_x
FUNCTION_AT_ADDRESS(void  CEverQuest::LocalDeath(struct _EQPlayerDeath *,unsigned char),CEverQuest__LocalDeath);
#endif
#ifdef CEverQuest__PrepareLocalPCForRepop_x
FUNCTION_AT_ADDRESS(void  CEverQuest::PrepareLocalPCForRepop(void),CEverQuest__PrepareLocalPCForRepop);
#endif
#ifdef CEverQuest__SavePCForce_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SavePCForce(int),CEverQuest__SavePCForce);
#endif
#ifdef CEverQuest__StartCasting_x
FUNCTION_AT_ADDRESS(void  CEverQuest::StartCasting(void *),CEverQuest__StartCasting);
#endif
#ifdef CEverQuest__Consider_x
FUNCTION_AT_ADDRESS(void  CEverQuest::Consider(class EQPlayer *,void *),CEverQuest__Consider);
#endif
#ifdef CEverQuest__GetClassDesc_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetClassDesc(int),CEverQuest__GetClassDesc);
#endif
#ifdef CEverQuest__GetClassThreeLetterCode_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetClassThreeLetterCode(int),CEverQuest__GetClassThreeLetterCode);
#endif
#ifdef CEverQuest__GetItemClassDesc_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetItemClassDesc(int),CEverQuest__GetItemClassDesc);
#endif
#ifdef CEverQuest__GetBodyTypeDesc_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetBodyTypeDesc(int),CEverQuest__GetBodyTypeDesc);
#endif
#ifdef CEverQuest__GetLangDesc_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetLangDesc(int),CEverQuest__GetLangDesc);
#endif
#ifdef CEverQuest__GetRaceDesc_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetRaceDesc(int),CEverQuest__GetRaceDesc);
#endif
#ifdef CEverQuest__GetDeityDesc_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetDeityDesc(int),CEverQuest__GetDeityDesc);
#endif
#ifdef CEverQuest__GuildInvite_x
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildInvite(char *,char *),CEverQuest__GuildInvite);
#endif
#ifdef CEverQuest__GuildRemove_x
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildRemove(char *),CEverQuest__GuildRemove);
#endif
#ifdef CEverQuest__GuildDelete_x
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildDelete(void),CEverQuest__GuildDelete);
#endif
#ifdef CEverQuest__GuildStatus_x
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildStatus(char *),CEverQuest__GuildStatus);
#endif
#ifdef CEverQuest__GuildLeader_x
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildLeader(char *),CEverQuest__GuildLeader);
#endif
#ifdef CEverQuest__GuildSay_x
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildSay(char *),CEverQuest__GuildSay);
#endif
#ifdef CEverQuest__Who_x
FUNCTION_AT_ADDRESS(void  CEverQuest::Who(char *),CEverQuest__Who);
#endif
#ifdef CEverQuest__GetInnateDesc_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetInnateDesc(int),CEverQuest__GetInnateDesc);
#endif
#ifdef CEverQuest__InviteOk_x
FUNCTION_AT_ADDRESS(void  CEverQuest::InviteOk(char *),CEverQuest__InviteOk);
#endif
#ifdef CEverQuest__doUnInvite_x
FUNCTION_AT_ADDRESS(void  CEverQuest::doUnInvite(char *),CEverQuest__doUnInvite);
#endif
#ifdef CEverQuest__Invite_x
FUNCTION_AT_ADDRESS(void  CEverQuest::Invite(int),CEverQuest__Invite);
#endif
#ifdef CEverQuest__doInvite_x
FUNCTION_AT_ADDRESS(void  CEverQuest::doInvite(unsigned __int32,char *),CEverQuest__doInvite);
#endif
#ifdef CEverQuest__Follow_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(int  CEverQuest::Follow(int), CEverQuest__Follow);
#else
FUNCTION_AT_ADDRESS(int  CEverQuest::Follow(void),CEverQuest__Follow);
#endif
#endif
#ifdef CEverQuest__Disband_x
FUNCTION_AT_ADDRESS(void  CEverQuest::Disband(void),CEverQuest__Disband);
#endif
#ifdef CEverQuest__GuildWar_x
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildWar(char *,int),CEverQuest__GuildWar);
#endif
#ifdef CEverQuest__GuildPeace_x
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildPeace(char *),CEverQuest__GuildPeace);
#endif
#ifdef CEverQuest__Sit_x
FUNCTION_AT_ADDRESS(void  CEverQuest::Sit(void),CEverQuest__Sit);
#endif
#ifdef CEverQuest__Camp_x
FUNCTION_AT_ADDRESS(void  CEverQuest::Camp(void),CEverQuest__Camp);
#endif
#ifdef CEverQuest__DropHeldItemOnGround_x
FUNCTION_AT_ADDRESS(void  CEverQuest::DropHeldItemOnGround(int),CEverQuest__DropHeldItemOnGround);
#endif
#ifdef CEverQuest__MoveMoney_x
FUNCTION_AT_ADDRESS(int  CEverQuest::MoveMoney(int,int,int,int,int,bool),CEverQuest__MoveMoney);
#endif
#ifdef CEverQuest__DropHeldMoneyOnGround_x
FUNCTION_AT_ADDRESS(void  CEverQuest::DropHeldMoneyOnGround(int),CEverQuest__DropHeldMoneyOnGround);
#endif
#ifdef CEverQuest__LMouseUp_x
FUNCTION_AT_ADDRESS(void  CEverQuest::LMouseUp(int,int),CEverQuest__LMouseUp);
#endif
#ifdef CEverQuest__LeftClickedOnPlayer_x
FUNCTION_AT_ADDRESS(void  CEverQuest::LeftClickedOnPlayer(class EQPlayer *),CEverQuest__LeftClickedOnPlayer);
#endif
#ifdef CEverQuest__DropItemOrMoneyOnPlayer_x
FUNCTION_AT_ADDRESS(void  CEverQuest::DropItemOrMoneyOnPlayer(class EQPlayer *),CEverQuest__DropItemOrMoneyOnPlayer);
#endif
#ifdef CEverQuest__RightClickedOnPlayer_x
FUNCTION_AT_ADDRESS(void  CEverQuest::RightClickedOnPlayer(class EQPlayer *, int),CEverQuest__RightClickedOnPlayer);
#endif
#ifdef CEverQuest__send_social_x
FUNCTION_AT_ADDRESS(void  CEverQuest::send_social(int,char *,char *),CEverQuest__send_social);
#endif
#ifdef CEverQuest__SavePC_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SavePC(int,int,unsigned char),CEverQuest__SavePC);
#endif
#ifdef CEverQuest__send_tell_x
FUNCTION_AT_ADDRESS(void  CEverQuest::send_tell(char *,char *),CEverQuest__send_tell);
#endif
#ifdef CEverQuest__send_petition_x
FUNCTION_AT_ADDRESS(void  CEverQuest::send_petition(void),CEverQuest__send_petition);
#endif
#ifdef CEverQuest__send_private_x
FUNCTION_AT_ADDRESS(void  CEverQuest::send_private(void),CEverQuest__send_private);
#endif
#ifdef CEverQuest__WriteIntToClientINI_x
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteIntToClientINI(int,char *,char *),CEverQuest__WriteIntToClientINI);
#endif
#ifdef CEverQuest__WriteFloatToClientINI_x
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteFloatToClientINI(float,char *,char *),CEverQuest__WriteFloatToClientINI);
#endif
#ifdef CEverQuest__WriteBoolToClientINI_x
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteBoolToClientINI(bool,char *,char *),CEverQuest__WriteBoolToClientINI);
#endif
#ifdef CEverQuest__WriteStringToClientINI_x
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteStringToClientINI(char *,char *,char *),CEverQuest__WriteStringToClientINI);
#endif
#ifdef CEverQuest__ReadClientINIString_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::ReadClientINIString(char *,char *,char *,char *,int),CEverQuest__ReadClientINIString);
#endif
#ifdef CEverQuest__ReadClientINIInt_x
FUNCTION_AT_ADDRESS(int  CEverQuest::ReadClientINIInt(char *,char *,int),CEverQuest__ReadClientINIInt);
#endif
#ifdef CEverQuest__ReadClientINIFloat_x
FUNCTION_AT_ADDRESS(float  CEverQuest::ReadClientINIFloat(char *,char *,float),CEverQuest__ReadClientINIFloat);
#endif
#ifdef CEverQuest__ReadClientINIBool_x
FUNCTION_AT_ADDRESS(bool  CEverQuest::ReadClientINIBool(char *,char *,bool),CEverQuest__ReadClientINIBool);
#endif
#ifdef CEverQuest__WriteIntToUIINI_x
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteIntToUIINI(int,char *,char *),CEverQuest__WriteIntToUIINI);
#endif
#ifdef CEverQuest__WriteBoolToUIINI_x
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteBoolToUIINI(bool,char *,char *),CEverQuest__WriteBoolToUIINI);
#endif
#ifdef CEverQuest__WriteStringToUIINI_x
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteStringToUIINI(char *,char *,char *),CEverQuest__WriteStringToUIINI);
#endif
#ifdef CEverQuest__ReadUIINIString_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::ReadUIINIString(char *,char *,char *,char *,int),CEverQuest__ReadUIINIString);
#endif
#ifdef CEverQuest__ReadUIINIInt_x
FUNCTION_AT_ADDRESS(int  CEverQuest::ReadUIINIInt(char *,char *,int),CEverQuest__ReadUIINIInt);
#endif
#ifdef CEverQuest__ReadUIINIBool_x
FUNCTION_AT_ADDRESS(bool  CEverQuest::ReadUIINIBool(char *,char *,bool),CEverQuest__ReadUIINIBool);
#endif
#ifdef CEverQuest__SaveCamerasToINI_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SaveCamerasToINI(void),CEverQuest__SaveCamerasToINI);
#endif
#ifdef CEverQuest__saveOptions_x
FUNCTION_AT_ADDRESS(void  CEverQuest::saveOptions(void),CEverQuest__saveOptions);
#endif
#ifdef CEverQuest__saveOptions2_x
FUNCTION_AT_ADDRESS(void  CEverQuest::saveOptions2(void),CEverQuest__saveOptions2);
#endif
#ifdef CEverQuest__send_update_filters_x
FUNCTION_AT_ADDRESS(void  CEverQuest::send_update_filters(void),CEverQuest__send_update_filters);
#endif
#ifdef CEverQuest__loadOptions_x
FUNCTION_AT_ADDRESS(void  CEverQuest::loadOptions(void),CEverQuest__loadOptions);
#endif
#ifdef CEverQuest__DoSplit_x
FUNCTION_AT_ADDRESS(void  CEverQuest::DoSplit(char *),CEverQuest__DoSplit);
#endif
#ifdef CEverQuest__BeingIgnored_x
FUNCTION_AT_ADDRESS(int  CEverQuest::BeingIgnored(char *),CEverQuest__BeingIgnored);
#endif
#ifdef CEverQuest__IsFriend_x
FUNCTION_AT_ADDRESS(int  CEverQuest::IsFriend(char const *),CEverQuest__IsFriend);
#endif
#ifdef CEverQuest__ToggleAutoSplit_x
FUNCTION_AT_ADDRESS(void  CEverQuest::ToggleAutoSplit(void),CEverQuest__ToggleAutoSplit);
#endif
#ifdef CEverQuest__procMouse_x
FUNCTION_AT_ADDRESS(void  CEverQuest::procMouse(int),CEverQuest__procMouse);
#endif
#ifdef CEverQuest__StripShipName_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::StripShipName(char *,char *),CEverQuest__StripShipName);
#endif
#ifdef CEverQuest__trimName_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::trimName(char *),CEverQuest__trimName);
#endif
#ifdef CEverQuest__CancelSneakHide_x
FUNCTION_AT_ADDRESS(void  CEverQuest::CancelSneakHide(void),CEverQuest__CancelSneakHide);
#endif
#ifdef CEverQuest__stripName_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::stripName(char *),CEverQuest__stripName);
#endif
#ifdef CEverQuest__clr_chat_input_x
FUNCTION_AT_ADDRESS(void  CEverQuest::clr_chat_input(void),CEverQuest__clr_chat_input);
#endif
#ifdef CEverQuest__dsp_chat_x
FUNCTION_AT_ADDRESS(void  CEverQuest::dsp_chat(char const *,int,bool,bool),CEverQuest__dsp_chat);
void CEverQuest::dsp_chat(char const *line, int color, bool bLogisok) { dsp_chat(line, color, bLogisok, true); }
#endif
#ifdef CEverQuest__OutputTextToLog_x
FUNCTION_AT_ADDRESS(void CEverQuest::OutputTextToLog(const char*Text),CEverQuest__OutputTextToLog);
#endif
#ifdef CEverQuest__DoTellWindow_x
FUNCTION_AT_ADDRESS(void CEverQuest::DoTellWindow(char *message,char *name,char *name2,void *unknown,int color,bool b),CEverQuest__DoTellWindow);
#endif
#ifdef CEverQuest__dsp_chat1_x
FUNCTION_AT_ADDRESS(void  CEverQuest::dsp_chat(char const *),CEverQuest__dsp_chat1);
#endif
#ifdef CEverQuest__DoPercentConvert_x
FUNCTION_AT_ADDRESS(void  CEverQuest::DoPercentConvert(char *,bool),CEverQuest__DoPercentConvert);
#endif
#ifdef CEverQuest__Emote_x
FUNCTION_AT_ADDRESS(void  CEverQuest::Emote(void),CEverQuest__Emote);
#endif
#ifdef CEverQuest__send_broadcast_x
FUNCTION_AT_ADDRESS(void  CEverQuest::send_broadcast(void),CEverQuest__send_broadcast);
#endif
#ifdef CEverQuest__send_chat_x
FUNCTION_AT_ADDRESS(void  CEverQuest::send_chat(void),CEverQuest__send_chat);
#endif
#ifdef CEverQuest__send_gsay_x
FUNCTION_AT_ADDRESS(void  CEverQuest::send_gsay(void),CEverQuest__send_gsay);
#endif
#ifdef CEverQuest__reqChannel_x
FUNCTION_AT_ADDRESS(void  CEverQuest::reqChannel(void),CEverQuest__reqChannel);
#endif
#ifdef CEverQuest__send_shout_x
FUNCTION_AT_ADDRESS(void  CEverQuest::send_shout(void),CEverQuest__send_shout);
#endif
#ifdef CEverQuest__send_auction_x
FUNCTION_AT_ADDRESS(void  CEverQuest::send_auction(void),CEverQuest__send_auction);
#endif
#ifdef CEverQuest__send_ooc_x
FUNCTION_AT_ADDRESS(void  CEverQuest::send_ooc(void),CEverQuest__send_ooc);
#endif
#ifdef CEverQuest__GetCurrentLanguage_x
FUNCTION_AT_ADDRESS(int  CEverQuest::GetCurrentLanguage(void)const,CEverQuest__GetCurrentLanguage);
#endif
#ifdef CEverQuest__SendNewText_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SendNewText(int,char *,char *),CEverQuest__SendNewText);
#endif
#ifdef CEverQuest__DisplayScreen_x
FUNCTION_AT_ADDRESS(void  CEverQuest::DisplayScreen(char *),CEverQuest__DisplayScreen);
#endif
#ifdef CEverQuest__IsValidName_x
FUNCTION_AT_ADDRESS(int  CEverQuest::IsValidName(char *),CEverQuest__IsValidName);
#endif
#ifdef CEverQuest__DoNewCharacterCreation_x
FUNCTION_AT_ADDRESS(void  CEverQuest::DoNewCharacterCreation(void),CEverQuest__DoNewCharacterCreation);
#endif
#ifdef CEverQuest__RemoveCharacterOptionFile_x
FUNCTION_AT_ADDRESS(void  CEverQuest::RemoveCharacterOptionFile(char *),CEverQuest__RemoveCharacterOptionFile);
#endif
#ifdef CEverQuest__SetDefaultGameValues_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SetDefaultGameValues(void),CEverQuest__SetDefaultGameValues);
#endif
#ifdef CEverQuest__SetPlayerAppearanceFromPInfo_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SetPlayerAppearanceFromPInfo(class EQPlayer *,int,bool),CEverQuest__SetPlayerAppearanceFromPInfo);
#endif
#ifdef CEverQuest__DoCharacterSelection_x
FUNCTION_AT_ADDRESS(void  CEverQuest::DoCharacterSelection(void),CEverQuest__DoCharacterSelection);
#endif
#ifdef CEverQuest__DoLogin_x
FUNCTION_AT_ADDRESS(int  CEverQuest::DoLogin(struct HWND__ *,struct HINSTANCE__ *),CEverQuest__DoLogin);
#endif
#ifdef CEverQuest__SetupCharSelectCamera_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SetupCharSelectCamera(void),CEverQuest__SetupCharSelectCamera);
#endif
#ifdef CEverQuest__CreateDataSubdirectories_x
FUNCTION_AT_ADDRESS(void  CEverQuest::CreateDataSubdirectories(void),CEverQuest__CreateDataSubdirectories);
#endif
#ifdef CEverQuest__CreateFilenameServerCode_x
FUNCTION_AT_ADDRESS(void  CEverQuest::CreateFilenameServerCode(char *),CEverQuest__CreateFilenameServerCode);
#endif
#ifdef CEverQuest__CreateIniFilenames_x
FUNCTION_AT_ADDRESS(void  CEverQuest::CreateIniFilenames(void),CEverQuest__CreateIniFilenames);
#endif
#ifdef CEverQuest__StartNetworkGame_x
FUNCTION_AT_ADDRESS(void  CEverQuest::StartNetworkGame(struct HWND__ *,struct HINSTANCE__ *,char *),CEverQuest__StartNetworkGame);
#endif
#ifdef CEverQuest__GetZoneInfoFromNetwork_x
FUNCTION_AT_ADDRESS(void  CEverQuest::GetZoneInfoFromNetwork(char *),CEverQuest__GetZoneInfoFromNetwork);
#endif
#ifdef CEverQuest__EnterZone_x
FUNCTION_AT_ADDRESS(void  CEverQuest::EnterZone(struct HWND__ *),CEverQuest__EnterZone);
#endif
#ifdef CEverQuest__Surname_x
FUNCTION_AT_ADDRESS(void  CEverQuest::Surname(char *),CEverQuest__Surname);
#endif
#ifdef CEverQuest__Kill_x
FUNCTION_AT_ADDRESS(void  CEverQuest::Kill(char *,char *),CEverQuest__Kill);
#endif
#ifdef CEverQuest__UpdateMyAppearance_x
FUNCTION_AT_ADDRESS(void  CEverQuest::UpdateMyAppearance(void),CEverQuest__UpdateMyAppearance);
#endif
#ifdef CEverQuest__IFoundMyVehicle_x
FUNCTION_AT_ADDRESS(unsigned char  CEverQuest::IFoundMyVehicle(void),CEverQuest__IFoundMyVehicle);
#endif
#ifdef CEverQuest__ProcessLocalPCIni_x
FUNCTION_AT_ADDRESS(void  CEverQuest::ProcessLocalPCIni(int),CEverQuest__ProcessLocalPCIni);
#endif
#ifdef CEverQuest__DoMainLoop_x
FUNCTION_AT_ADDRESS(void  CEverQuest::DoMainLoop(struct HWND__ *),CEverQuest__DoMainLoop);
#endif
#ifdef CEverQuest__ProcessControls_x
FUNCTION_AT_ADDRESS(void  CEverQuest::ProcessControls(void),CEverQuest__ProcessControls);
#endif
#ifdef CEverQuest__TypingMode_x
FUNCTION_AT_ADDRESS(int  CEverQuest::TypingMode(void),CEverQuest__TypingMode);
#endif
#ifdef CEverQuest__IsInTypingMode_x
FUNCTION_AT_ADDRESS(bool  CEverQuest::IsInTypingMode(void),CEverQuest__IsInTypingMode);
#endif
#ifdef CEverQuest__doInspect_x
FUNCTION_AT_ADDRESS(void  CEverQuest::doInspect(class EQPlayer *),CEverQuest__doInspect);
#endif
#ifdef __do_loot_x
FUNCTION_AT_ADDRESS(void  CEverQuest::doLoot(void),__do_loot);
#endif
#ifdef CEverQuest__SendLightInfo_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SendLightInfo(class EQPlayer *,unsigned char),CEverQuest__SendLightInfo);
#endif
#ifdef CEverQuest__SetTimedFog_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SetTimedFog(int),CEverQuest__SetTimedFog);
#endif
#ifdef CEverQuest__ProcessGame_x
FUNCTION_AT_ADDRESS(void  CEverQuest::ProcessGame(struct HWND__ *,struct HINSTANCE__ *),CEverQuest__ProcessGame);
#endif
#ifdef CEverQuest__DoLoadScreenProgressBar_x
FUNCTION_AT_ADDRESS(void __cdecl CEverQuest::DoLoadScreenProgressBar(int,char const *,...),CEverQuest__DoLoadScreenProgressBar);
#endif
#ifdef CEverQuest__DoLoadScreen_x
FUNCTION_AT_ADDRESS(void  CEverQuest::DoLoadScreen(int),CEverQuest__DoLoadScreen);
#endif
#ifdef CEverQuest__CleanupBadFiles_x
FUNCTION_AT_ADDRESS(void  CEverQuest::CleanupBadFiles(void),CEverQuest__CleanupBadFiles);
#endif
#ifdef CEverQuest__CreateInitialActors_x
FUNCTION_AT_ADDRESS(void  CEverQuest::CreateInitialActors(void), CEverQuest__CreateInitialActors);
#endif
#ifdef CEverQuest__CreateTargetIndicator_x
FUNCTION_AT_ADDRESS(void CEverQuest::CreateTargetIndicator(int Slot, PSPELL pSpell, const ItemGlobalIndex& ItemLoc, ItemSpellTypes spelltype), CEverQuest__CreateTargetIndicator);
#endif
#ifdef CEverQuest__DeleteTargetIndicator_x
FUNCTION_AT_ADDRESS(int CEverQuest::DeleteTargetIndicator(void), CEverQuest__DeleteTargetIndicator);
#endif
#ifdef CEverQuest__GetSndDriver_x
FUNCTION_AT_ADDRESS(void  CEverQuest::GetSndDriver(void),CEverQuest__GetSndDriver);
#endif
#ifdef CEverQuest__InterpretCmd_x
FUNCTION_AT_ADDRESS(void  CEverQuest::InterpretCmd(class EQPlayer *,char *),CEverQuest__InterpretCmd);
#endif
#ifdef CEverQuest__GrabFirstWord_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::GrabFirstWord(char *,char *),CEverQuest__GrabFirstWord);
#endif
#ifdef CEverQuest__GrabFirstWord2_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::GrabFirstWord2(char *,char *,int),CEverQuest__GrabFirstWord2);
#endif
#ifdef CEverQuest__CopyFirstWord_x
FUNCTION_AT_ADDRESS(void  CEverQuest::CopyFirstWord(char *,char *),CEverQuest__CopyFirstWord);
#endif
#ifdef CEverQuest__ApplyPoison_x
FUNCTION_AT_ADDRESS(void  CEverQuest::ApplyPoison(unsigned long),CEverQuest__ApplyPoison);
#endif
#ifdef CEverQuest__DeacSpellScreen_x
FUNCTION_AT_ADDRESS(void  CEverQuest::DeacSpellScreen(void),CEverQuest__DeacSpellScreen);
#endif
#ifdef CEverQuest__IsZoneAvailable_x
//FUNCTION_AT_ADDRESS(enum ZONE_REQ_STATUS  CEverQuest::IsZoneAvailable(char *,enum EQZoneIndex,enum ZONE_REQ_REASON),CEverQuest__IsZoneAvailable);
#endif
#ifdef CEverQuest__MoveToZone_x
FUNCTION_AT_ADDRESS(void CEverQuest::MoveToZone(int EQZoneIndex,char *,int,int ZONE_REQ_REASON,float,float,float,int),CEverQuest__MoveToZone);
#endif
#ifdef CEverQuest__MoveToZone1_x
//FUNCTION_AT_ADDRESS(void  CEverQuest::MoveToZone(char *,char *,int,enum ZONE_REQ_REASON),CEverQuest__MoveToZone1);
#endif
#ifdef CEverQuest__LMouseDown_x
FUNCTION_AT_ADDRESS(void  CEverQuest::LMouseDown(int,int),CEverQuest__LMouseDown);
#endif
#ifdef CEverQuest__RMouseDown_x
FUNCTION_AT_ADDRESS(void  CEverQuest::RMouseDown(int,int),CEverQuest__RMouseDown);
#endif
#ifdef CEverQuest__RMouseUp_x
FUNCTION_AT_ADDRESS(void CEverQuest::RMouseUp(int,int),CEverQuest__RMouseUp);
#endif
#ifdef CEverQuest__MouseWheelScrolled_x
FUNCTION_AT_ADDRESS(void CEverQuest::MouseWheelScrolled(int),CEverQuest__MouseWheelScrolled);
#endif
#ifdef CEverQuest__ClickedSwitch_x
FUNCTION_AT_ADDRESS(class EQSwitch *  CEverQuest::ClickedSwitch(int,int),CEverQuest__ClickedSwitch);
#endif
#ifdef CEverQuest__ClickedPlayer_x
FUNCTION_AT_ADDRESS(class EQPlayer *  CEverQuest::ClickedPlayer(int,int),CEverQuest__ClickedPlayer);
#endif
#ifdef CEverQuest__WhatTimeIsIt_x
FUNCTION_AT_ADDRESS(void  CEverQuest::WhatTimeIsIt(void),CEverQuest__WhatTimeIsIt);
#endif
#ifdef CEverQuest__FreeSwitches_x
FUNCTION_AT_ADDRESS(void  CEverQuest::FreeSwitches(void),CEverQuest__FreeSwitches);
#endif
#ifdef CEverQuest__LoadSwitchesNonAvatar_x
//FUNCTION_AT_ADDRESS(void  CEverQuest::LoadSwitchesNonAvatar(enum EQZoneIndex),CEverQuest__LoadSwitchesNonAvatar);
#endif
#ifdef CEverQuest__SetLfgPlayerStatus_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SetLfgPlayerStatus(struct LfgPlayerStatus *),CEverQuest__SetLfgPlayerStatus);
#endif
#ifdef CEverQuest__SetLfgGroupStatus_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SetLfgGroupStatus(struct LfgGroupStatus *),CEverQuest__SetLfgGroupStatus);
#endif
#ifdef CEverQuest__IssueLfgPlayerQuery_x
FUNCTION_AT_ADDRESS(void  CEverQuest::IssueLfgPlayerQuery(struct LfgPlayerQuery *),CEverQuest__IssueLfgPlayerQuery);
#endif
#ifdef CEverQuest__IssueLfgGroupQuery_x
FUNCTION_AT_ADDRESS(void  CEverQuest::IssueLfgGroupQuery(struct LfgGroupQuery *),CEverQuest__IssueLfgGroupQuery);
#endif
#ifdef CEverQuest__IssuePetCommand_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void  CEverQuest::IssuePetCommand(ePetCommandType,int,bool,bool),CEverQuest__IssuePetCommand);
#else
FUNCTION_AT_ADDRESS(void  CEverQuest::IssuePetCommand(ePetCommandType,int,bool),CEverQuest__IssuePetCommand);
#endif
#endif
#ifdef CEverQuest__LootCorpse_x
FUNCTION_AT_ADDRESS(int  CEverQuest::LootCorpse(class EQPlayer *,int),CEverQuest__LootCorpse);
#endif
#ifdef CEverQuest__loadSoundsGame_x
FUNCTION_AT_ADDRESS(void  CEverQuest::loadSoundsGame(void),CEverQuest__loadSoundsGame);
#endif
#ifdef CEverQuest__GetSingleMessage_x
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetSingleMessage(unsigned __int32,int,int *,char *),CEverQuest__GetSingleMessage);
#endif
#ifdef CEverQuest__SetGameState_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SetGameState(int),CEverQuest__SetGameState);
#endif
#ifdef CEverQuest__IsOkToTransact_x
FUNCTION_AT_ADDRESS(bool  CEverQuest::IsOkToTransact(void),CEverQuest__IsOkToTransact);
#endif
#ifdef CEverQuest__SortSpellLoadouts_x
FUNCTION_AT_ADDRESS(void  CEverQuest::SortSpellLoadouts(void),CEverQuest__SortSpellLoadouts);
#endif
#ifdef CEverQuest__saveCustom_x
FUNCTION_AT_ADDRESS(void  CEverQuest::saveCustom(void),CEverQuest__saveCustom);
#endif
#ifdef CEverQuest__loadCustomFromINI_x
FUNCTION_AT_ADDRESS(void  CEverQuest::loadCustomFromINI(char *),CEverQuest__loadCustomFromINI);
#endif
#ifdef CEverQuest__loadCustom_x
FUNCTION_AT_ADDRESS(void  CEverQuest::loadCustom(void),CEverQuest__loadCustom);
#endif
#ifdef CEverQuest__initCustom_x
FUNCTION_AT_ADDRESS(void  CEverQuest::initCustom(void),CEverQuest__initCustom);
#endif
#ifdef _EverQuestinfo__SetAutoAttack_x
FUNCTION_AT_ADDRESS(void  _EverQuestinfo::SetAutoAttack(bool),_EverQuestinfo__SetAutoAttack);
#endif
#ifdef GrammarRulesClass__GrammarRulesClass_x
FUNCTION_AT_ADDRESS( GrammarRulesClass::GrammarRulesClass(void),GrammarRulesClass__GrammarRulesClass);
#endif
#ifdef GrammarRulesClass__Parse_x
FUNCTION_AT_ADDRESS(char *  GrammarRulesClass::Parse(char *),GrammarRulesClass__Parse);
#endif
#ifdef GrammarRulesClass__Resolve_x
FUNCTION_AT_ADDRESS(char *  GrammarRulesClass::Resolve(int,int,char *,char *),GrammarRulesClass__Resolve);
#endif
#ifdef GrammarRulesClass__RuleEn1_x
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleEn1(char *,char *),GrammarRulesClass__RuleEn1);
#endif
#ifdef GrammarRulesClass__RuleEn2_x
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleEn2(char *,char *),GrammarRulesClass__RuleEn2);
#endif
#ifdef GrammarRulesClass__RuleEn3_x
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleEn3(char *,char *,char *,char *),GrammarRulesClass__RuleEn3);
#endif
#ifdef GrammarRulesClass__RuleEn4_x
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleEn4(char *,char *,char *,char *),GrammarRulesClass__RuleEn4);
#endif
#ifdef GrammarRulesClass__RuleKo1_x
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleKo1(char *,char *,char *,char *),GrammarRulesClass__RuleKo1);
#endif
#ifdef GrammarRulesClass__RuleFr1_x
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleFr1(char *,char *,char *,char *),GrammarRulesClass__RuleFr1);
#endif
#ifdef GrammarRulesClass__RuleDe1_x
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleDe1(char *,char *),GrammarRulesClass__RuleDe1);
#endif
#ifdef KeypressHandler__KeypressHandler_x
FUNCTION_AT_ADDRESS( KeypressHandler::KeypressHandler(void),KeypressHandler__KeypressHandler);
#endif
#ifdef KeypressHandler__AttachKeyToEqCommand_x
FUNCTION_AT_ADDRESS(bool  KeypressHandler::AttachKeyToEqCommand(class KeyCombo const &,unsigned int),KeypressHandler__AttachKeyToEqCommand);
#endif
#ifdef KeypressHandler__AttachAltKeyToEqCommand_x
FUNCTION_AT_ADDRESS(bool  KeypressHandler::AttachAltKeyToEqCommand(class KeyCombo const &,unsigned int),KeypressHandler__AttachAltKeyToEqCommand);
#endif
#ifdef KeypressHandler__HandleKeyDown_x
FUNCTION_AT_ADDRESS(bool  KeypressHandler::HandleKeyDown(class KeyCombo const &),KeypressHandler__HandleKeyDown);
#endif
#ifdef KeypressHandler__HandleKeyUp_x
FUNCTION_AT_ADDRESS(bool  KeypressHandler::HandleKeyUp(class KeyCombo const &),KeypressHandler__HandleKeyUp);
#endif
#ifdef KeypressHandler__GetKeyAttachedToEqCommand_x
FUNCTION_AT_ADDRESS(class KeyCombo const &  KeypressHandler::GetKeyAttachedToEqCommand(unsigned int)const ,KeypressHandler__GetKeyAttachedToEqCommand);
#endif
#ifdef KeypressHandler__GetAltKeyAttachedToEqCommand_x
FUNCTION_AT_ADDRESS(class KeyCombo const &  KeypressHandler::GetAltKeyAttachedToEqCommand(unsigned int)const ,KeypressHandler__GetAltKeyAttachedToEqCommand);
#endif
#ifdef KeypressHandler__ResetKeysToEqDefaults_x
FUNCTION_AT_ADDRESS(void  KeypressHandler::ResetKeysToEqDefaults(void),KeypressHandler__ResetKeysToEqDefaults);
#endif
#ifdef KeypressHandler__MapKeyToEqCommand_x
FUNCTION_AT_ADDRESS(bool  KeypressHandler::MapKeyToEqCommand(class KeyCombo const &,int,unsigned int),KeypressHandler__MapKeyToEqCommand);
#endif
#ifdef KeypressHandler__IsReservedKey_x
FUNCTION_AT_ADDRESS(bool  KeypressHandler::IsReservedKey(class KeyCombo const &)const ,KeypressHandler__IsReservedKey);
#endif
#ifdef KeypressHandler__LoadAndSetKeymappings_x
FUNCTION_AT_ADDRESS(void  KeypressHandler::LoadAndSetKeymappings(void),KeypressHandler__LoadAndSetKeymappings);
#endif
#ifdef KeypressHandler__LoadKeymapping_x
FUNCTION_AT_ADDRESS(bool  KeypressHandler::LoadKeymapping(unsigned int,int,class KeyCombo *),KeypressHandler__LoadKeymapping);
#endif
#ifdef KeypressHandler__SaveKeymapping_x
FUNCTION_AT_ADDRESS(void  KeypressHandler::SaveKeymapping(unsigned int,class KeyCombo const &,int),KeypressHandler__SaveKeymapping);
#endif
#ifdef KeypressHandler__GetEqCommandSaveName_x
FUNCTION_AT_ADDRESS(class CXStr  KeypressHandler::GetEqCommandSaveName(unsigned int,int)const ,KeypressHandler__GetEqCommandSaveName);
#endif
#ifdef KeypressHandler__LoadAndConvertOldKeymappingFormat_x
FUNCTION_AT_ADDRESS(bool  KeypressHandler::LoadAndConvertOldKeymappingFormat(unsigned int,int,class KeyCombo *),KeypressHandler__LoadAndConvertOldKeymappingFormat);
#endif
#ifdef KeypressHandler__ClearCommandStateArray_x
FUNCTION_AT_ADDRESS(void  KeypressHandler::ClearCommandStateArray(void),KeypressHandler__ClearCommandStateArray);
#endif
#ifdef MemoryPoolManager__MemoryPoolManager_x
FUNCTION_AT_ADDRESS( MemoryPoolManager::MemoryPoolManager(void),MemoryPoolManager__MemoryPoolManager);
#endif
#ifdef MemoryPoolManager__dMemoryPoolManager_x
FUNCTION_AT_ADDRESS( MemoryPoolManager::~MemoryPoolManager(void),MemoryPoolManager__dMemoryPoolManager);
#endif
#ifdef MemoryPoolManager__Alloc_x
FUNCTION_AT_ADDRESS(void *  MemoryPoolManager::Alloc(int),MemoryPoolManager__Alloc);
#endif
#ifdef MemoryPoolManager__Free_x
FUNCTION_AT_ADDRESS(void  MemoryPoolManager::Free(void *),MemoryPoolManager__Free);
#endif
#ifdef PacketPackerManager__SetPriority_x
FUNCTION_AT_ADDRESS(void  PacketPackerManager::SetPriority(class PacketPacker *,__int64),PacketPackerManager__SetPriority);
#endif
#ifdef PacketPackerManager__RemovePacker_x
FUNCTION_AT_ADDRESS(void  PacketPackerManager::RemovePacker(class PacketPacker *),PacketPackerManager__RemovePacker);
#endif
#ifdef PacketPackerManager__UnpackGetFirst_x
FUNCTION_AT_ADDRESS(bool __cdecl PacketPackerManager::UnpackGetFirst(struct PacketPackerState *,unsigned __int32,unsigned char *,int),PacketPackerManager__UnpackGetFirst);
#endif
#ifdef PacketPackerManager__UnpackGetNext_x
FUNCTION_AT_ADDRESS(bool __cdecl PacketPackerManager::UnpackGetNext(struct PacketPackerState *),PacketPackerManager__UnpackGetNext);
#endif
#ifdef PacketPacker__SendStatUpdate_x
FUNCTION_AT_ADDRESS(void  PacketPacker::SendStatUpdate(struct _statUpdate *,bool),PacketPacker__SendStatUpdate);
#endif
#ifdef PacketPacker__FlushPositions_x
FUNCTION_AT_ADDRESS(void  PacketPacker::FlushPositions(void),PacketPacker__FlushPositions);
#endif
#ifdef PacketPacker__SendPacket_x
FUNCTION_AT_ADDRESS(void  PacketPacker::SendPacket(unsigned __int32,void *,int,bool),PacketPacker__SendPacket);
#endif
#ifdef PacketPacker__AddPacketToBuffer_x
//FUNCTION_AT_ADDRESS(void  PacketPacker::AddPacketToBuffer(struct PacketPacker::PacketBuffer *,unsigned __int32,void *,int),PacketPacker__AddPacketToBuffer);
#endif
#ifdef PacketPacker__ScheduleUs_x
FUNCTION_AT_ADDRESS(void  PacketPacker::ScheduleUs(void),PacketPacker__ScheduleUs);
#endif
#ifdef PacketPacker__Flush_x
FUNCTION_AT_ADDRESS(void  PacketPacker::Flush(void),PacketPacker__Flush);
#endif
#ifdef PacketPacker__FlushBuffer_x
//FUNCTION_AT_ADDRESS(void  PacketPacker::FlushBuffer(struct PacketPacker::PacketBuffer *),PacketPacker__FlushBuffer);
#endif
#ifdef PacketPacker__Disassociate_x
FUNCTION_AT_ADDRESS(void  PacketPacker::Disassociate(void),PacketPacker__Disassociate);
#endif
#ifdef CResolutionHandler__Init_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::Init(void),CResolutionHandler__Init);
#endif
#ifdef CResolutionHandler__Shutdown_x
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::Shutdown(void),CResolutionHandler__Shutdown);
#endif
#ifdef CResolutionHandler__SaveSettings_x
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::SaveSettings(void),CResolutionHandler__SaveSettings);
#endif
#ifdef CResolutionHandler__ToggleScreenMode_x
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::ToggleScreenMode(void),CResolutionHandler__ToggleScreenMode);
#endif
#ifdef CResolutionHandler__ChangeToResolution_x
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::ChangeToResolution(int,int,int,int,int),CResolutionHandler__ChangeToResolution);
#endif
#ifdef CResolutionHandler__UpdateWindowPosition_x
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::UpdateWindowPosition(void),CResolutionHandler__UpdateWindowPosition);
#endif
#ifdef CResolutionHandler__UpdateResolution_x
FUNCTION_AT_ADDRESS(void CResolutionHandler::UpdateResolution(ResolutionUpdateData& data),CResolutionHandler__UpdateResolution);
#endif
#ifdef CResolutionHandler__GetWindowedStyle_x
FUNCTION_AT_ADDRESS(DWORD CResolutionHandler::GetWindowedStyle() const,CResolutionHandler__GetWindowedStyle);
#endif
#ifdef CResolutionHandler__GetDesktopWidth_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetDesktopWidth(void),CResolutionHandler__GetDesktopWidth);
#endif
#ifdef CResolutionHandler__GetDesktopHeight_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetDesktopHeight(void),CResolutionHandler__GetDesktopHeight);
#endif
#ifdef CResolutionHandler__GetDesktopBitsPerPixel_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetDesktopBitsPerPixel(void),CResolutionHandler__GetDesktopBitsPerPixel);
#endif
#ifdef CResolutionHandler__GetDesktopRefreshRate_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetDesktopRefreshRate(void),CResolutionHandler__GetDesktopRefreshRate);
#endif
#ifdef CResolutionHandler__GetWidth_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetWidth(void),CResolutionHandler__GetWidth);
#endif
#ifdef CResolutionHandler__GetHeight_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetHeight(void),CResolutionHandler__GetHeight);
#endif
#ifdef CResolutionHandler__IsFullscreenAvailable_x
FUNCTION_AT_ADDRESS(bool __cdecl CResolutionHandler::IsFullscreenAvailable(void),CResolutionHandler__IsFullscreenAvailable);
#endif
#ifdef Util__AllocateString_x
FUNCTION_AT_ADDRESS(char * __cdecl Util::AllocateString(char *),Util__AllocateString);
#endif
#ifdef ChannelServerApi__AllocateString_x
FUNCTION_AT_ADDRESS(char * __cdecl ChannelServerApi::AllocateString(char *),ChannelServerApi__AllocateString);
#endif
#ifdef SoundManager__SoundManager_x
//FUNCTION_AT_ADDRESS( SoundManager::SoundManager(int,int,bool,int,int,bool,enum SpeakerType),SoundManager__SoundManager);
#endif
#ifdef SoundManager__dSoundManager_x
FUNCTION_AT_ADDRESS( SoundManager::~SoundManager(void),SoundManager__dSoundManager);
#endif
#ifdef SoundManager__AddPool_x
//FUNCTION_AT_ADDRESS(void  SoundManager::AddPool(enum InstanceType,int,int),SoundManager__AddPool);
#endif
#ifdef SoundManager__GiveTime_x
FUNCTION_AT_ADDRESS(void  SoundManager::GiveTime(void),SoundManager__GiveTime);
#endif
#ifdef SoundManager__SetMixAhead_x
FUNCTION_AT_ADDRESS(void  SoundManager::SetMixAhead(int),SoundManager__SetMixAhead);
#endif
#ifdef SoundManager__GetListenerEnvironment_x
//FUNCTION_AT_ADDRESS(enum EnvironmentType  SoundManager::GetListenerEnvironment(void),SoundManager__GetListenerEnvironment);
#endif
#ifdef SoundManager__SetListenerEnvironment_x
//FUNCTION_AT_ADDRESS(void  SoundManager::SetListenerEnvironment(enum EnvironmentType),SoundManager__SetListenerEnvironment);
#endif
#ifdef SoundManager__SetListenerLocation_x
FUNCTION_AT_ADDRESS(void  SoundManager::SetListenerLocation(float,float,float,float),SoundManager__SetListenerLocation);
#endif
#ifdef SoundManager__GetListenerLocation_x
FUNCTION_AT_ADDRESS(void  SoundManager::GetListenerLocation(float *,float *,float *,float *),SoundManager__GetListenerLocation);
#endif
#ifdef SoundManager__BorrowInstance_x
//FUNCTION_AT_ADDRESS(class SoundInstance *  SoundManager::BorrowInstance(enum InstanceType,int),SoundManager__BorrowInstance);
#endif
#ifdef SoundManager__ReturnInstance_x
FUNCTION_AT_ADDRESS(void  SoundManager::ReturnInstance(class SoundInstance *),SoundManager__ReturnInstance);
#endif
#ifdef SoundManager__AssetGiveTime_x
FUNCTION_AT_ADDRESS(void  SoundManager::AssetGiveTime(void),SoundManager__AssetGiveTime);
#endif
#ifdef SoundManager__AssetAdd_x
FUNCTION_AT_ADDRESS(void  SoundManager::AssetAdd(class SoundAsset *),SoundManager__AssetAdd);
#endif
#ifdef SoundManager__AssetRemove_x
FUNCTION_AT_ADDRESS(void  SoundManager::AssetRemove(class SoundAsset *),SoundManager__AssetRemove);
#endif
#ifdef SoundManager__AssetGet_x
FUNCTION_AT_ADDRESS(class SoundAsset *  SoundManager::AssetGet(char *),SoundManager__AssetGet);
#endif
#ifdef SoundManager__StreamingPlay_x
FUNCTION_AT_ADDRESS(void  SoundManager::StreamingPlay(char *),SoundManager__StreamingPlay);
#endif
#ifdef SoundManager__StreamingPause_x
FUNCTION_AT_ADDRESS(void  SoundManager::StreamingPause(void),SoundManager__StreamingPause);
#endif
#ifdef SoundManager__StreamingStop_x
FUNCTION_AT_ADDRESS(void  SoundManager::StreamingStop(void),SoundManager__StreamingStop);
#endif
#ifdef SoundManager__StreamingSetVolumeLevel_x
FUNCTION_AT_ADDRESS(void  SoundManager::StreamingSetVolumeLevel(float),SoundManager__StreamingSetVolumeLevel);
#endif
#ifdef SoundManager__StreamingGetVolumeLevel_x
FUNCTION_AT_ADDRESS(float  SoundManager::StreamingGetVolumeLevel(void),SoundManager__StreamingGetVolumeLevel);
#endif
#ifdef SoundManager__StreamingSetSongPosition_x
FUNCTION_AT_ADDRESS(void  SoundManager::StreamingSetSongPosition(int),SoundManager__StreamingSetSongPosition);
#endif
#ifdef SoundManager__StreamingGetSongPosition_x
FUNCTION_AT_ADDRESS(int  SoundManager::StreamingGetSongPosition(void),SoundManager__StreamingGetSongPosition);
#endif
#ifdef SoundManager__StreamingGetSongLength_x
FUNCTION_AT_ADDRESS(int  SoundManager::StreamingGetSongLength(void),SoundManager__StreamingGetSongLength);
#endif
#ifdef SoundManager__StreamingStatus_x
//FUNCTION_AT_ADDRESS(enum StreamingStatus  SoundManager::StreamingStatus(void),SoundManager__StreamingStatus);
#endif
#ifdef MusicManager__MusicEntry__MusicEntry_x
//FUNCTION_AT_ADDRESS( MusicManager::MusicEntry::MusicEntry(int,class SoundAsset *,int,float,int,int,int,int,int,int),MusicManager__MusicEntry__MusicEntry);
#endif
#ifdef MusicManager__MusicEntry__dMusicEntry_x
//FUNCTION_AT_ADDRESS( MusicManager::MusicEntry::~MusicEntry(void),MusicManager__MusicEntry__dMusicEntry);
#endif
#ifdef MusicManager__MusicEntry__AdjustVolume_x
//FUNCTION_AT_ADDRESS(void  MusicManager::MusicEntry::AdjustVolume(float),MusicManager__MusicEntry__AdjustVolume);
#endif
#ifdef MusicManager__MusicEntry__FadeIn_x
//FUNCTION_AT_ADDRESS(void  MusicManager::MusicEntry::FadeIn(float),MusicManager__MusicEntry__FadeIn);
#endif
#ifdef MusicManager__MusicEntry__FadeOut_x
//FUNCTION_AT_ADDRESS(void  MusicManager::MusicEntry::FadeOut(bool),MusicManager__MusicEntry__FadeOut);
#endif
#ifdef SoundObject__SoundObject_x
//FUNCTION_AT_ADDRESS( SoundObject::SoundObject(void),SoundObject__SoundObject);
#endif
#ifdef SoundObject__Release_x
//FUNCTION_AT_ADDRESS(void  SoundObject::Release(void),SoundObject__Release);
#endif
#ifdef SoundInstance__SoundInstance_x
//FUNCTION_AT_ADDRESS( SoundInstance::SoundInstance(class SoundManager *),SoundInstance__SoundInstance);
#endif
#ifdef SoundInstance__YourManagerDeleted_x
//FUNCTION_AT_ADDRESS(void  SoundInstance::YourManagerDeleted(void),SoundInstance__YourManagerDeleted);
#endif
#ifdef flex_unit__clear_x
FUNCTION_AT_ADDRESS(void  flex_unit::clear(void),flex_unit__clear);
#endif
#ifdef WaveInstance__WaveInstance_x
FUNCTION_AT_ADDRESS( WaveInstance::WaveInstance(class SoundManager *),WaveInstance__WaveInstance);
#endif
#ifdef Wave3dInstance__Wave3dInstance_x
FUNCTION_AT_ADDRESS( Wave3dInstance::Wave3dInstance(class SoundManager *),Wave3dInstance__Wave3dInstance);
#endif
#ifdef MidiInstance__MidiInstance_x
//FUNCTION_AT_ADDRESS( MidiInstance::MidiInstance(class SoundManager *),MidiInstance__MidiInstance);
#endif
#ifdef SoundAsset__SoundAsset_x
//FUNCTION_AT_ADDRESS( SoundAsset::SoundAsset(class SoundManager *,char *,char *,int),SoundAsset__SoundAsset);
#endif
#ifdef SoundAsset__GetType_x
//FUNCTION_AT_ADDRESS(enum AssetType  SoundAsset::GetType(void),SoundAsset__GetType);
#endif
#ifdef SoundAsset__YourManagerDeleted_x
//FUNCTION_AT_ADDRESS(void  SoundAsset::YourManagerDeleted(void),SoundAsset__YourManagerDeleted);
#endif
#ifdef SoundAsset__GiveTime_x
//FUNCTION_AT_ADDRESS(void  SoundAsset::GiveTime(void),SoundAsset__GiveTime);
#endif
#ifdef SoundAsset__IsPlaying_x
//FUNCTION_AT_ADDRESS(bool  SoundAsset::IsPlaying(void),SoundAsset__IsPlaying);
#endif
#ifdef SoundAsset__AdjustVolume_x
//FUNCTION_AT_ADDRESS(void  SoundAsset::AdjustVolume(float,int),SoundAsset__AdjustVolume);
#endif
#ifdef SoundAsset__GetName_x
//FUNCTION_AT_ADDRESS(char *  SoundAsset::GetName(void),SoundAsset__GetName);
#endif
#ifdef SoundAsset__Play_x
//FUNCTION_AT_ADDRESS(class SoundInstance *  SoundAsset::Play(class SoundControl *),SoundAsset__Play);
#endif
#ifdef SoundAsset__Stop_x
//FUNCTION_AT_ADDRESS(void  SoundAsset::Stop(void),SoundAsset__Stop);
#endif
#ifdef SoundControl__SoundControl_x
FUNCTION_AT_ADDRESS( SoundControl::SoundControl(void),SoundControl__SoundControl);
#endif
#ifdef SoundEmitter__SoundEmitter_x
//FUNCTION_AT_ADDRESS( SoundEmitter::SoundEmitter(class EmitterManager *,class SoundAsset *,int),SoundEmitter__SoundEmitter);
#endif
#ifdef SoundEmitter__SoundEmitter1_x
//FUNCTION_AT_ADDRESS( SoundEmitter::SoundEmitter(class EmitterManager *,class MusicManager *,int),SoundEmitter__SoundEmitter1);
#endif
#ifdef SoundEmitter__Init_x
//FUNCTION_AT_ADDRESS(void  SoundEmitter::Init(void),SoundEmitter__Init);
#endif
#ifdef SoundEmitter__GiveTime_x
//FUNCTION_AT_ADDRESS(void  SoundEmitter::GiveTime(void),SoundEmitter__GiveTime);
#endif
#ifdef SoundEmitter__ReleaseLoopingSound_x
//FUNCTION_AT_ADDRESS(void  SoundEmitter::ReleaseLoopingSound(void),SoundEmitter__ReleaseLoopingSound);
#endif
#ifdef SoundEmitter__ResetTimer_x
//FUNCTION_AT_ADDRESS(void  SoundEmitter::ResetTimer(void),SoundEmitter__ResetTimer);
#endif
#ifdef SoundEmitter__Move_x
//FUNCTION_AT_ADDRESS(void  SoundEmitter::Move(float,float,float),SoundEmitter__Move);
#endif
#ifdef SoundEmitter__SetAsset_x
//FUNCTION_AT_ADDRESS(void  SoundEmitter::SetAsset(class SoundAsset *),SoundEmitter__SetAsset);
#endif
#ifdef SoundEmitter__Enable_x
//FUNCTION_AT_ADDRESS(void  SoundEmitter::Enable(bool),SoundEmitter__Enable);
#endif
#ifdef Mp3Manager__Mp3Manager_x
FUNCTION_AT_ADDRESS( Mp3Manager::Mp3Manager(class SoundManager *,class MusicManager *),Mp3Manager__Mp3Manager);
#endif
#ifdef Mp3Manager__dMp3Manager_x
FUNCTION_AT_ADDRESS( Mp3Manager::~Mp3Manager(void),Mp3Manager__dMp3Manager);
#endif
#ifdef Mp3Manager__GetSort_x
//FUNCTION_AT_ADDRESS(enum Mp3Manager::SortOrder  Mp3Manager::GetSort(void),Mp3Manager__GetSort);
#endif
#ifdef Mp3Manager__Sort_x
//FUNCTION_AT_ADDRESS(void  Mp3Manager::Sort(enum Mp3Manager::SortOrder),Mp3Manager__Sort);
#endif
#ifdef Mp3Manager__Stop_x
FUNCTION_AT_ADDRESS(void  Mp3Manager::Stop(void),Mp3Manager__Stop);
#endif
#ifdef Mp3Manager__Play_x
FUNCTION_AT_ADDRESS(void  Mp3Manager::Play(void),Mp3Manager__Play);
#endif
#ifdef Mp3Manager__Pause_x
FUNCTION_AT_ADDRESS(void  Mp3Manager::Pause(void),Mp3Manager__Pause);
#endif
#ifdef Mp3Manager__Status_x
//FUNCTION_AT_ADDRESS(enum StreamingStatus  Mp3Manager::Status(void),Mp3Manager__Status);
#endif
#ifdef Mp3Manager__GiveTime_x
FUNCTION_AT_ADDRESS(void  Mp3Manager::GiveTime(void),Mp3Manager__GiveTime);
#endif
#ifdef Mp3Manager__Next_x
FUNCTION_AT_ADDRESS(void  Mp3Manager::Next(void),Mp3Manager__Next);
#endif
#ifdef Mp3Manager__Back_x
FUNCTION_AT_ADDRESS(void  Mp3Manager::Back(void),Mp3Manager__Back);
#endif
#ifdef Mp3Manager__GetSongLength_x
FUNCTION_AT_ADDRESS(int  Mp3Manager::GetSongLength(void),Mp3Manager__GetSongLength);
#endif
#ifdef Mp3Manager__GetSongPosition_x
FUNCTION_AT_ADDRESS(int  Mp3Manager::GetSongPosition(void),Mp3Manager__GetSongPosition);
#endif
#ifdef Mp3Manager__SetSongPosition_x
FUNCTION_AT_ADDRESS(void  Mp3Manager::SetSongPosition(int),Mp3Manager__SetSongPosition);
#endif
#ifdef Mp3Manager__GetName_x
FUNCTION_AT_ADDRESS(char *  Mp3Manager::GetName(int),Mp3Manager__GetName);
#endif
#ifdef Mp3Manager__Count_x
FUNCTION_AT_ADDRESS(int  Mp3Manager::Count(void),Mp3Manager__Count);
#endif
#ifdef Mp3Manager__SetPosition_x
FUNCTION_AT_ADDRESS(void  Mp3Manager::SetPosition(int),Mp3Manager__SetPosition);
#endif
#ifdef Mp3Manager__SetVolumeLevel_x
FUNCTION_AT_ADDRESS(void  Mp3Manager::SetVolumeLevel(float),Mp3Manager__SetVolumeLevel);
#endif
#ifdef Mp3Manager__GetVolumeLevel_x
FUNCTION_AT_ADDRESS(float  Mp3Manager::GetVolumeLevel(void),Mp3Manager__GetVolumeLevel);
#endif
#ifdef Mp3Manager__DeleteAll_x
FUNCTION_AT_ADDRESS(void  Mp3Manager::DeleteAll(void),Mp3Manager__DeleteAll);
#endif
#ifdef Mp3Manager__Delete_x
FUNCTION_AT_ADDRESS(void  Mp3Manager::Delete(int),Mp3Manager__Delete);
#endif
#ifdef Mp3Manager__SaveList_x
FUNCTION_AT_ADDRESS(void  Mp3Manager::SaveList(char *),Mp3Manager__SaveList);
#endif
#ifdef Mp3Manager__Add_x
FUNCTION_AT_ADDRESS(int  Mp3Manager::Add(char *),Mp3Manager__Add);
#endif
#ifdef Mp3Manager__InternalAdd_x
FUNCTION_AT_ADDRESS(int  Mp3Manager::InternalAdd(char *,char *,int),Mp3Manager__InternalAdd);
#endif
#ifdef Mp3Manager__Entry__Entry_x
//FUNCTION_AT_ADDRESS( Mp3Manager::Entry::Entry(char *,char *,int,int),Mp3Manager__Entry__Entry);
#endif
#ifdef Mp3Manager__Entry__dEntry_x
//FUNCTION_AT_ADDRESS( Mp3Manager::Entry::~Entry(void),Mp3Manager__Entry__dEntry);
#endif
#ifdef ActorClient__GetPosition_x
FUNCTION_AT_ADDRESS(class  CVector3 const &ActorClient::GetPosition(void)const,ActorClient__GetPosition);
#endif
#ifdef ActorClient__GetPosition1_x
FUNCTION_AT_ADDRESS(void  ActorClient::GetPosition(class CVector3 *)const,ActorClient__GetPosition1);
#endif
#ifdef EmitterManager__EmitterManager_x
FUNCTION_AT_ADDRESS( EmitterManager::EmitterManager(class SoundManager *),EmitterManager__EmitterManager);
#endif
#ifdef EmitterManager__dEmitterManager_x
FUNCTION_AT_ADDRESS( EmitterManager::~EmitterManager(void),EmitterManager__dEmitterManager);
#endif
#ifdef EmitterManager__Add_x
//FUNCTION_AT_ADDRESS(void  EmitterManager::Add(class SoundEmitter *),EmitterManager__Add);
#endif
#ifdef EmitterManager__Remove_x
//FUNCTION_AT_ADDRESS(void  EmitterManager::Remove(class SoundEmitter *),EmitterManager__Remove);
#endif
#ifdef EmitterManager__GiveTime_x
FUNCTION_AT_ADDRESS(void  EmitterManager::GiveTime(void),EmitterManager__GiveTime);
#endif
#ifdef EmitterManager__GetEffectsLevel_x
FUNCTION_AT_ADDRESS(float  EmitterManager::GetEffectsLevel(void),EmitterManager__GetEffectsLevel);
#endif
#ifdef EmitterManager__GetVolumeLevel_x
FUNCTION_AT_ADDRESS(float  EmitterManager::GetVolumeLevel(void),EmitterManager__GetVolumeLevel);
#endif
#ifdef EmitterManager__SetEffectsLevel_x
FUNCTION_AT_ADDRESS(void  EmitterManager::SetEffectsLevel(float),EmitterManager__SetEffectsLevel);
#endif
#ifdef EmitterManager__GetListenerLocation_x
FUNCTION_AT_ADDRESS(void  EmitterManager::GetListenerLocation(float *,float *,float *,float *),EmitterManager__GetListenerLocation);
#endif
#ifdef MusicManager__MusicManager_x
FUNCTION_AT_ADDRESS( MusicManager::MusicManager(void),MusicManager__MusicManager);
#endif
#ifdef MusicManager__dMusicManager_x
FUNCTION_AT_ADDRESS( MusicManager::~MusicManager(void),MusicManager__dMusicManager);
#endif
#ifdef MusicManager__GiveTime_x
FUNCTION_AT_ADDRESS(void  MusicManager::GiveTime(void),MusicManager__GiveTime);
#endif
#ifdef MusicManager__Clear_x
FUNCTION_AT_ADDRESS(void  MusicManager::Clear(class SoundAsset *),MusicManager__Clear);
#endif
#ifdef MusicManager__SetVolumeLevel_x
FUNCTION_AT_ADDRESS(void  MusicManager::SetVolumeLevel(float),MusicManager__SetVolumeLevel);
#endif
#ifdef MusicManager__Clear1_x
FUNCTION_AT_ADDRESS(void  MusicManager::Clear(int),MusicManager__Clear1);
#endif
#ifdef MusicManager__Set_x
FUNCTION_AT_ADDRESS(void  MusicManager::Set(int,class SoundAsset *,int,float,int,int,int,int,int,int),MusicManager__Set);
#endif
#ifdef MusicManager__Play_x
FUNCTION_AT_ADDRESS(void  MusicManager::Play(int),MusicManager__Play);
#endif
#ifdef MusicManager__Stop_x
FUNCTION_AT_ADDRESS(void  MusicManager::Stop(int),MusicManager__Stop);
#endif
#ifdef MusicManager__Enable_x
FUNCTION_AT_ADDRESS(void  MusicManager::Enable(bool),MusicManager__Enable);
#endif
#ifdef SpellManager__SpellManager_x
FUNCTION_AT_ADDRESS( SpellManager::SpellManager(char *),SpellManager__SpellManager);
#endif
#ifdef SpellManager__dSpellManager_x
FUNCTION_AT_ADDRESS( SpellManager::~SpellManager(void),SpellManager__dSpellManager);
#endif
#ifdef SpellManager__GetSpellByGroupAndRank_x
FUNCTION_AT_ADDRESS(const EQ_Spell* SpellManager::GetSpellByGroupAndRank(int Group, int SubGroup, int Rank, bool bLesserRanksOk),SpellManager__GetSpellByGroupAndRank);
#endif
#ifdef CStoryWnd__CStoryWnd_x
FUNCTION_AT_ADDRESS( CStoryWnd::CStoryWnd(class CXWnd *),CStoryWnd__CStoryWnd);
#endif
#ifdef CStoryWnd__Init_x
FUNCTION_AT_ADDRESS(void  CStoryWnd::Init(void),CStoryWnd__Init);
#endif
#ifdef CStoryWnd__SaveIni_x
FUNCTION_AT_ADDRESS(void  CStoryWnd::SaveIni(void),CStoryWnd__SaveIni);
#endif
#ifdef CStoryWnd__ShowAuto_x
FUNCTION_AT_ADDRESS(bool  CStoryWnd::ShowAuto(void),CStoryWnd__ShowAuto);
#endif
#ifdef CStoryWnd__HasNew_x
FUNCTION_AT_ADDRESS(bool  CStoryWnd::HasNew(void),CStoryWnd__HasNew);
#endif
#ifdef CStoryWnd__Activate_x
FUNCTION_AT_ADDRESS(void  CStoryWnd::Activate(void),CStoryWnd__Activate);
#endif
#ifdef CStoryWnd__SelectOldestNew_x
FUNCTION_AT_ADDRESS(void  CStoryWnd::SelectOldestNew(void),CStoryWnd__SelectOldestNew);
#endif
#ifdef CStoryWnd__SelectIndex_x
FUNCTION_AT_ADDRESS(void  CStoryWnd::SelectIndex(int),CStoryWnd__SelectIndex);
#endif
#ifdef StringItem__StringItem_x
FUNCTION_AT_ADDRESS( StringItem::StringItem(void),StringItem__StringItem);
#endif
#ifdef UdpReliableChannel__IncomingQueueEntry__IncomingQueueEntry_x
//FUNCTION_AT_ADDRESS( UdpReliableChannel::IncomingQueueEntry::IncomingQueueEntry(void),UdpReliableChannel__IncomingQueueEntry__IncomingQueueEntry);
#endif
#ifdef StringItem__dStringItem_x
FUNCTION_AT_ADDRESS( StringItem::~StringItem(void),StringItem__dStringItem);
#endif
#ifdef StringItem__load_x
FUNCTION_AT_ADDRESS(int  StringItem::load(struct _iobuf *,int),StringItem__load);
#endif
#ifdef StringTable__StringTable_x
FUNCTION_AT_ADDRESS( StringTable::StringTable(void),StringTable__StringTable);
#endif
#ifdef StringTable__dStringTable_x
FUNCTION_AT_ADDRESS( StringTable::~StringTable(void),StringTable__dStringTable);
#endif
#ifdef StringTable__checkAlloc_x
FUNCTION_AT_ADDRESS(void  StringTable::checkAlloc(void),StringTable__checkAlloc);
#endif
#ifdef StringTable__getString_x
FUNCTION_AT_ADDRESS(char *  StringTable::getString(unsigned long,bool *),StringTable__getString);
#endif
#ifdef StringTable__findItem_x
FUNCTION_AT_ADDRESS(class StringItem *  StringTable::findItem(unsigned long,int,int),StringTable__findItem);
#endif
#ifdef StringTable__load_x
FUNCTION_AT_ADDRESS(int  StringTable::load(char const *,int),StringTable__load);
#endif
#ifdef StringTable__addItem_x
FUNCTION_AT_ADDRESS(void  StringTable::addItem(class StringItem *),StringTable__addItem);
#endif
#ifdef UdpIpAddress__UdpIpAddress_x
FUNCTION_AT_ADDRESS( UdpIpAddress::UdpIpAddress(unsigned int),UdpIpAddress__UdpIpAddress);
#endif
#ifdef UdpManager__Params__Params_x
//FUNCTION_AT_ADDRESS( UdpManager::Params::Params(void),UdpManager__Params__Params);
#endif
#ifdef UdpManager__UdpManager_x
//FUNCTION_AT_ADDRESS( UdpManager::UdpManager(struct UdpManager::Params const *),UdpManager__UdpManager);
#endif
#ifdef UdpManager__PoolReturn_x
//FUNCTION_AT_ADDRESS(void  UdpManager::PoolReturn(class PooledLogicalPacket *),UdpManager__PoolReturn);
#endif
#ifdef UdpManager__dUdpManager_x
FUNCTION_AT_ADDRESS( UdpManager::~UdpManager(void),UdpManager__dUdpManager);
#endif
#ifdef UdpManager__CreateAndBindSocket_x
FUNCTION_AT_ADDRESS(void  UdpManager::CreateAndBindSocket(int),UdpManager__CreateAndBindSocket);
#endif
#ifdef UdpManager__CloseSocket_x
FUNCTION_AT_ADDRESS(void  UdpManager::CloseSocket(void),UdpManager__CloseSocket);
#endif
#ifdef UdpManager__ProcessDisconnectPending_x
FUNCTION_AT_ADDRESS(void  UdpManager::ProcessDisconnectPending(void),UdpManager__ProcessDisconnectPending);
#endif
#ifdef UdpManager__RemoveConnection_x
FUNCTION_AT_ADDRESS(void  UdpManager::RemoveConnection(class UdpConnection *),UdpManager__RemoveConnection);
#endif
#ifdef UdpManager__AddConnection_x
FUNCTION_AT_ADDRESS(void  UdpManager::AddConnection(class UdpConnection *),UdpManager__AddConnection);
#endif
#ifdef UdpManager__GiveTime_x
FUNCTION_AT_ADDRESS(bool  UdpManager::GiveTime(int,bool),UdpManager__GiveTime);
#endif
#ifdef UdpManager__EstablishConnection_x
FUNCTION_AT_ADDRESS(class UdpConnection *  UdpManager::EstablishConnection(char const *,int,int),UdpManager__EstablishConnection);
#endif
#ifdef UdpManager__KeepUntilDisconnected_x
FUNCTION_AT_ADDRESS(void  UdpManager::KeepUntilDisconnected(class UdpConnection *),UdpManager__KeepUntilDisconnected);
#endif
#ifdef UdpManager__ResetStats_x
FUNCTION_AT_ADDRESS(void  UdpManager::ResetStats(void),UdpManager__ResetStats);
#endif
#ifdef UdpManager__ActualReceive_x
//FUNCTION_AT_ADDRESS(class UdpManager::PacketHistoryEntry *  UdpManager::ActualReceive(void),UdpManager__ActualReceive);
#endif
#ifdef UdpManager__ActualSend_x
FUNCTION_AT_ADDRESS(void  UdpManager::ActualSend(unsigned char const *,int,class UdpIpAddress,int),UdpManager__ActualSend);
#endif
#ifdef UdpManager__ActualSendHelper_x
FUNCTION_AT_ADDRESS(void  UdpManager::ActualSendHelper(unsigned char const *,int,class UdpIpAddress,int),UdpManager__ActualSendHelper);
#endif
#ifdef UdpManager__SendPortAlive_x
FUNCTION_AT_ADDRESS(void  UdpManager::SendPortAlive(class UdpIpAddress,int),UdpManager__SendPortAlive);
#endif
#ifdef UdpManager__ProcessRawPacket_x
//FUNCTION_AT_ADDRESS(void  UdpManager::ProcessRawPacket(class UdpManager::PacketHistoryEntry const *),UdpManager__ProcessRawPacket);
#endif
#ifdef UdpManager__AddressGetConnection_x
FUNCTION_AT_ADDRESS(class UdpConnection *  UdpManager::AddressGetConnection(class UdpIpAddress,int)const ,UdpManager__AddressGetConnection);
#endif
#ifdef UdpManager__ConnectCodeGetConnection_x
FUNCTION_AT_ADDRESS(class UdpConnection *  UdpManager::ConnectCodeGetConnection(int)const ,UdpManager__ConnectCodeGetConnection);
#endif
#ifdef UdpManager__WrappedBorrow_x
//FUNCTION_AT_ADDRESS(class WrappedLogicalPacket *  UdpManager::WrappedBorrow(class LogicalPacket const *),UdpManager__WrappedBorrow);
#endif
#ifdef UdpManager__WrappedCreated_x
//FUNCTION_AT_ADDRESS(void  UdpManager::WrappedCreated(class WrappedLogicalPacket *),UdpManager__WrappedCreated);
#endif
#ifdef UdpManager__WrappedDestroyed_x
//FUNCTION_AT_ADDRESS(void  UdpManager::WrappedDestroyed(class WrappedLogicalPacket *),UdpManager__WrappedDestroyed);
#endif
#ifdef UdpManager__CreatePacket_x
FUNCTION_AT_ADDRESS(class LogicalPacket *  UdpManager::CreatePacket(void const *,int,void const *,int),UdpManager__CreatePacket);
#endif
#ifdef UdpManager__PoolCreated_x
//FUNCTION_AT_ADDRESS(void  UdpManager::PoolCreated(class PooledLogicalPacket *),UdpManager__PoolCreated);
#endif
#ifdef UdpManager__PoolDestroyed_x
//FUNCTION_AT_ADDRESS(void  UdpManager::PoolDestroyed(class PooledLogicalPacket *),UdpManager__PoolDestroyed);
#endif
#ifdef UdpManager__PacketHistoryEntry__PacketHistoryEntry_x
//FUNCTION_AT_ADDRESS( UdpManager::PacketHistoryEntry::PacketHistoryEntry(int),UdpManager__PacketHistoryEntry__PacketHistoryEntry);
#endif
#ifdef UdpManager__PacketHistoryEntry__dPacketHistoryEntry_x
//FUNCTION_AT_ADDRESS( UdpManager::PacketHistoryEntry::~PacketHistoryEntry(void),UdpManager__PacketHistoryEntry__dPacketHistoryEntry);
#endif
#ifdef UdpManager__SimulateQueueEntry__dSimulateQueueEntry_x
//FUNCTION_AT_ADDRESS( UdpManager::SimulateQueueEntry::~SimulateQueueEntry(void),UdpManager__SimulateQueueEntry__dSimulateQueueEntry);
#endif
#ifdef UdpConnection__UdpConnection_x
FUNCTION_AT_ADDRESS( UdpConnection::UdpConnection(class UdpManager *,class UdpIpAddress,int,int),UdpConnection__UdpConnection);
#endif
#ifdef UdpConnection__UdpConnection1_x
//FUNCTION_AT_ADDRESS( UdpConnection::UdpConnection(class UdpManager *,class UdpManager::PacketHistoryEntry const *),UdpConnection__UdpConnection1);
#endif
#ifdef UdpConnection__Init_x
FUNCTION_AT_ADDRESS(void  UdpConnection::Init(class UdpManager *,class UdpIpAddress,int),UdpConnection__Init);
#endif
#ifdef UdpConnection__dUdpConnection_x
FUNCTION_AT_ADDRESS( UdpConnection::~UdpConnection(void),UdpConnection__dUdpConnection);
#endif
#ifdef UdpConnection__PortUnreachable_x
FUNCTION_AT_ADDRESS(void  UdpConnection::PortUnreachable(void),UdpConnection__PortUnreachable);
#endif
#ifdef UdpConnection__InternalDisconnect_x
//FUNCTION_AT_ADDRESS(void  UdpConnection::InternalDisconnect(int,enum UdpConnection::DisconnectReason),UdpConnection__InternalDisconnect);
#endif
#ifdef UdpConnection__ScheduleTimeNow_x
FUNCTION_AT_ADDRESS(void  UdpConnection::ScheduleTimeNow(void),UdpConnection__ScheduleTimeNow);
#endif
#ifdef UdpConnection__SendTerminatePacket_x
//FUNCTION_AT_ADDRESS(void  UdpConnection::SendTerminatePacket(int,enum UdpConnection::DisconnectReason),UdpConnection__SendTerminatePacket);
#endif
#ifdef UdpMisc__PutValue32_x
FUNCTION_AT_ADDRESS(int __cdecl UdpMisc::PutValue32(void *,unsigned int),UdpMisc__PutValue32);
#endif
#ifdef UdpConnection__SetSilentDisconnect_x
FUNCTION_AT_ADDRESS(void  UdpConnection::SetSilentDisconnect(bool),UdpConnection__SetSilentDisconnect);
#endif
#ifdef UdpConnection__Send_x
//FUNCTION_AT_ADDRESS(bool  UdpConnection::Send(enum UdpChannel,void const *,int),UdpConnection__Send);
#endif
#ifdef UdpConnection__InternalSend_x
//FUNCTION_AT_ADDRESS(bool  UdpConnection::InternalSend(enum UdpChannel,unsigned char const *,int,unsigned char const *,int),UdpConnection__InternalSend);
#endif
#ifdef UdpConnection__PingStatReset_x
FUNCTION_AT_ADDRESS(void  UdpConnection::PingStatReset(void),UdpConnection__PingStatReset);
#endif
#ifdef UdpConnection__ProcessRawPacket_x
//FUNCTION_AT_ADDRESS(void  UdpConnection::ProcessRawPacket(class UdpManager::PacketHistoryEntry const *),UdpConnection__ProcessRawPacket);
#endif
#ifdef UdpMisc__GetValue24_x
FUNCTION_AT_ADDRESS(unsigned int __cdecl UdpMisc::GetValue24(void const *),UdpMisc__GetValue24);
#endif
#ifdef UdpConnection__IsNonEncryptPacket_x
FUNCTION_AT_ADDRESS(bool  UdpConnection::IsNonEncryptPacket(unsigned char const *)const ,UdpConnection__IsNonEncryptPacket);
#endif
#ifdef UdpConnection__CallbackRoutePacket_x
FUNCTION_AT_ADDRESS(void  UdpConnection::CallbackRoutePacket(unsigned char const *,int),UdpConnection__CallbackRoutePacket);
#endif
#ifdef UdpConnection__CallbackCorruptPacket_x
//FUNCTION_AT_ADDRESS(void  UdpConnection::CallbackCorruptPacket(unsigned char const *,int,enum UdpCorruptionReason),UdpConnection__CallbackCorruptPacket);
#endif
#ifdef UdpConnection__ProcessCookedPacket_x
FUNCTION_AT_ADDRESS(void  UdpConnection::ProcessCookedPacket(unsigned char const *,int),UdpConnection__ProcessCookedPacket);
#endif
#ifdef UdpMisc__PutValue64_x
FUNCTION_AT_ADDRESS(int __cdecl UdpMisc::PutValue64(void *,__int64),UdpMisc__PutValue64);
#endif
#ifdef UdpMisc__GetValue64_x
FUNCTION_AT_ADDRESS(__int64 __cdecl UdpMisc::GetValue64(void const *),UdpMisc__GetValue64);
#endif
#ifdef UdpReliableChannel__AckPacket_x
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::AckPacket(unsigned char const *,int),UdpReliableChannel__AckPacket);
#endif
#ifdef UdpConnection__GiveTime_x
FUNCTION_AT_ADDRESS(void  UdpConnection::GiveTime(void),UdpConnection__GiveTime);
#endif
#ifdef UdpConnection__InternalGiveTime_x
FUNCTION_AT_ADDRESS(void  UdpConnection::InternalGiveTime(void),UdpConnection__InternalGiveTime);
#endif
#ifdef UdpConnection__LastReceive_x
FUNCTION_AT_ADDRESS(int  UdpConnection::LastReceive(void)const ,UdpConnection__LastReceive);
#endif
#ifdef UdpConnection__ConnectionAge_x
FUNCTION_AT_ADDRESS(int  UdpConnection::ConnectionAge(void)const ,UdpConnection__ConnectionAge);
#endif
#ifdef UdpConnection__TotalPendingBytes_x
FUNCTION_AT_ADDRESS(int  UdpConnection::TotalPendingBytes(void)const ,UdpConnection__TotalPendingBytes);
#endif
#ifdef UdpConnection__RawSend_x
FUNCTION_AT_ADDRESS(void  UdpConnection::RawSend(unsigned char const *,int),UdpConnection__RawSend);
#endif
#ifdef UdpConnection__ExpireSendBin_x
FUNCTION_AT_ADDRESS(int  UdpConnection::ExpireSendBin(void),UdpConnection__ExpireSendBin);
#endif
#ifdef UdpConnection__ExpireReceiveBin_x
FUNCTION_AT_ADDRESS(int  UdpConnection::ExpireReceiveBin(void),UdpConnection__ExpireReceiveBin);
#endif
#ifdef UdpConnection__PhysicalSend_x
FUNCTION_AT_ADDRESS(void  UdpConnection::PhysicalSend(unsigned char const *,int,bool),UdpConnection__PhysicalSend);
#endif
#ifdef UdpMisc__PutValue24_x
FUNCTION_AT_ADDRESS(int __cdecl UdpMisc::PutValue24(void *,unsigned int),UdpMisc__PutValue24);
#endif
#ifdef UdpConnection__BufferedSend_x
FUNCTION_AT_ADDRESS(unsigned char *  UdpConnection::BufferedSend(unsigned char const *,int,unsigned char const *,int,bool),UdpConnection__BufferedSend);
#endif
#ifdef UdpConnection__FlushMultiBuffer_x
FUNCTION_AT_ADDRESS(void  UdpConnection::FlushMultiBuffer(void),UdpConnection__FlushMultiBuffer);
#endif
#ifdef UdpConnection__DecryptNone_x
FUNCTION_AT_ADDRESS(int  UdpConnection::DecryptNone(unsigned char *,unsigned char const *,int),UdpConnection__DecryptNone);
#endif
#ifdef UdpConnection__EncryptNone_x
FUNCTION_AT_ADDRESS(int  UdpConnection::EncryptNone(unsigned char *,unsigned char const *,int),UdpConnection__EncryptNone);
#endif
#ifdef UdpConnection__EncryptUserSupplied_x
FUNCTION_AT_ADDRESS(int  UdpConnection::EncryptUserSupplied(unsigned char *,unsigned char const *,int),UdpConnection__EncryptUserSupplied);
#endif
#ifdef UdpConnection__DecryptUserSupplied_x
FUNCTION_AT_ADDRESS(int  UdpConnection::DecryptUserSupplied(unsigned char *,unsigned char const *,int),UdpConnection__DecryptUserSupplied);
#endif
#ifdef UdpConnection__EncryptUserSupplied2_x
FUNCTION_AT_ADDRESS(int  UdpConnection::EncryptUserSupplied2(unsigned char *,unsigned char const *,int),UdpConnection__EncryptUserSupplied2);
#endif
#ifdef UdpConnection__DecryptUserSupplied2_x
FUNCTION_AT_ADDRESS(int  UdpConnection::DecryptUserSupplied2(unsigned char *,unsigned char const *,int),UdpConnection__DecryptUserSupplied2);
#endif
#ifdef UdpConnection__EncryptXorBuffer_x
FUNCTION_AT_ADDRESS(int  UdpConnection::EncryptXorBuffer(unsigned char *,unsigned char const *,int),UdpConnection__EncryptXorBuffer);
#endif
#ifdef UdpConnection__DecryptXorBuffer_x
FUNCTION_AT_ADDRESS(int  UdpConnection::DecryptXorBuffer(unsigned char *,unsigned char const *,int),UdpConnection__DecryptXorBuffer);
#endif
#ifdef UdpConnection__EncryptXor_x
FUNCTION_AT_ADDRESS(int  UdpConnection::EncryptXor(unsigned char *,unsigned char const *,int),UdpConnection__EncryptXor);
#endif
#ifdef UdpConnection__DecryptXor_x
FUNCTION_AT_ADDRESS(int  UdpConnection::DecryptXor(unsigned char *,unsigned char const *,int),UdpConnection__DecryptXor);
#endif
#ifdef UdpConnection__SetupEncryptModel_x
FUNCTION_AT_ADDRESS(void  UdpConnection::SetupEncryptModel(void),UdpConnection__SetupEncryptModel);
#endif
#ifdef UdpConnection__GetChannelStatus_x
//FUNCTION_AT_ADDRESS(void  UdpConnection::GetChannelStatus(enum UdpChannel,struct UdpConnection::ChannelStatus *)const ,UdpConnection__GetChannelStatus);
#endif
#ifdef UdpReliableChannel__UdpReliableChannel_x
//FUNCTION_AT_ADDRESS( UdpReliableChannel::UdpReliableChannel(int,class UdpConnection *,struct UdpManager::ReliableConfig *),UdpReliableChannel__UdpReliableChannel);
#endif
#ifdef UdpReliableChannel__dUdpReliableChannel_x
FUNCTION_AT_ADDRESS( UdpReliableChannel::~UdpReliableChannel(void),UdpReliableChannel__dUdpReliableChannel);
#endif
#ifdef UdpReliableChannel__Send_x
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::Send(unsigned char const *,int,unsigned char const *,int),UdpReliableChannel__Send);
#endif
#ifdef UdpReliableChannel__FlushCoalesce_x
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::FlushCoalesce(void),UdpReliableChannel__FlushCoalesce);
#endif
#ifdef UdpReliableChannel__SendCoalesce_x
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::SendCoalesce(unsigned char const *,int,unsigned char const *,int),UdpReliableChannel__SendCoalesce);
#endif
#ifdef UdpReliableChannel__QueueLogicalPacket_x
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::QueueLogicalPacket(class LogicalPacket const *),UdpReliableChannel__QueueLogicalPacket);
#endif
#ifdef UdpReliableChannel__PullDown_x
FUNCTION_AT_ADDRESS(bool  UdpReliableChannel::PullDown(int),UdpReliableChannel__PullDown);
#endif
#ifdef UdpReliableChannel__GiveTime_x
FUNCTION_AT_ADDRESS(int  UdpReliableChannel::GiveTime(void),UdpReliableChannel__GiveTime);
#endif
#ifdef UdpReliableChannel__GetChannelStatus_x
//FUNCTION_AT_ADDRESS(void  UdpReliableChannel::GetChannelStatus(struct UdpConnection::ChannelStatus *)const ,UdpReliableChannel__GetChannelStatus);
#endif
#ifdef UdpReliableChannel__ReliablePacket_x
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::ReliablePacket(unsigned char const *,int),UdpReliableChannel__ReliablePacket);
#endif
#ifdef UdpReliableChannel__GetReliableIncomingId_x
FUNCTION_AT_ADDRESS(__int64  UdpReliableChannel::GetReliableIncomingId(int)const ,UdpReliableChannel__GetReliableIncomingId);
#endif
#ifdef UdpReliableChannel__ProcessPacket_x
//FUNCTION_AT_ADDRESS(void  UdpReliableChannel::ProcessPacket(enum UdpReliableChannel::ReliablePacketMode,unsigned char const *,int),UdpReliableChannel__ProcessPacket);
#endif
#ifdef UdpReliableChannel__AckAllPacket_x
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::AckAllPacket(unsigned char const *,int),UdpReliableChannel__AckAllPacket);
#endif
#ifdef UdpReliableChannel__Ack_x
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::Ack(__int64),UdpReliableChannel__Ack);
#endif
#ifdef UdpReliableChannel__IncomingQueueEntry__dIncomingQueueEntry_x
//FUNCTION_AT_ADDRESS( UdpReliableChannel::IncomingQueueEntry::~IncomingQueueEntry(void),UdpReliableChannel__IncomingQueueEntry__dIncomingQueueEntry);
#endif
#ifdef UdpReliableChannel__PhysicalPacket__PhysicalPacket_x
//FUNCTION_AT_ADDRESS( UdpReliableChannel::PhysicalPacket::PhysicalPacket(void),UdpReliableChannel__PhysicalPacket__PhysicalPacket);
#endif
#ifdef UdpReliableChannel__PhysicalPacket__dPhysicalPacket_x
//FUNCTION_AT_ADDRESS( UdpReliableChannel::PhysicalPacket::~PhysicalPacket(void),UdpReliableChannel__PhysicalPacket__dPhysicalPacket);
#endif
#ifdef LogicalPacket__LogicalPacket_x
FUNCTION_AT_ADDRESS( LogicalPacket::LogicalPacket(void),LogicalPacket__LogicalPacket);
#endif
#ifdef SoundObject__AddRef_x
//FUNCTION_AT_ADDRESS(void  SoundObject::AddRef(void),SoundObject__AddRef);
#endif
#ifdef Mp3Manager__GetPosition_x
FUNCTION_AT_ADDRESS(int  Mp3Manager::GetPosition(void),Mp3Manager__GetPosition);
#endif
#ifdef SimpleLogicalPacket__SimpleLogicalPacket_x
FUNCTION_AT_ADDRESS( SimpleLogicalPacket::SimpleLogicalPacket(void const *,int),SimpleLogicalPacket__SimpleLogicalPacket);
#endif
#ifdef EmitterManager__SetVolumeLevel_x
FUNCTION_AT_ADDRESS(void  EmitterManager::SetVolumeLevel(float),EmitterManager__SetVolumeLevel);
#endif
#ifdef PooledLogicalPacket__PooledLogicalPacket_x
//FUNCTION_AT_ADDRESS( PooledLogicalPacket::PooledLogicalPacket(class UdpManager *,int),PooledLogicalPacket__PooledLogicalPacket);
#endif
#ifdef ChannelServerApi__GetChannelCount_x
FUNCTION_AT_ADDRESS(int  ChannelServerApi::GetChannelCount(void),ChannelServerApi__GetChannelCount);
#endif
#ifdef PooledLogicalPacket__SetData_x
//FUNCTION_AT_ADDRESS(void  PooledLogicalPacket::SetData(void const *,int,void const *,int),PooledLogicalPacket__SetData);
#endif
#ifdef WrappedLogicalPacket__WrappedLogicalPacket_x
//FUNCTION_AT_ADDRESS( WrappedLogicalPacket::WrappedLogicalPacket(class UdpManager *),WrappedLogicalPacket__WrappedLogicalPacket);
#endif
#ifdef UdpManager__WrappedReturn_x
//FUNCTION_AT_ADDRESS(void  UdpManager::WrappedReturn(class WrappedLogicalPacket *),UdpManager__WrappedReturn);
#endif
#ifdef WrappedLogicalPacket__SetLogicalPacket_x
//FUNCTION_AT_ADDRESS(void  WrappedLogicalPacket::SetLogicalPacket(class LogicalPacket const *),WrappedLogicalPacket__SetLogicalPacket);
#endif
#ifdef UdpManager__SimulateQueueEntry__SimulateQueueEntry_x
//FUNCTION_AT_ADDRESS( UdpManager::SimulateQueueEntry::SimulateQueueEntry(unsigned char const *,int,class UdpIpAddress,int),UdpManager__SimulateQueueEntry__SimulateQueueEntry);
#endif
#ifdef UdpMisc__Clock_x
FUNCTION_AT_ADDRESS(__int64 __cdecl UdpMisc::Clock(void),UdpMisc__Clock);
#endif
#ifdef UdpMisc__SyncStampShortDeltaTime_x
FUNCTION_AT_ADDRESS(int __cdecl UdpMisc::SyncStampShortDeltaTime(unsigned short,unsigned short),UdpMisc__SyncStampShortDeltaTime);
#endif
#ifdef UdpMisc__Random_x
FUNCTION_AT_ADDRESS(int __cdecl UdpMisc::Random(int *),UdpMisc__Random);
#endif
#ifdef UdpMisc__Crc32_x
FUNCTION_AT_ADDRESS(int __cdecl UdpMisc::Crc32(void const *,int,int),UdpMisc__Crc32);
#endif
#ifdef UdpMisc__PutVariableValue_x
FUNCTION_AT_ADDRESS(unsigned int __cdecl UdpMisc::PutVariableValue(void *,unsigned int),UdpMisc__PutVariableValue);
#endif
#ifdef UdpMisc__GetVariableValue_x
FUNCTION_AT_ADDRESS(unsigned int __cdecl UdpMisc::GetVariableValue(void const *,unsigned int *),UdpMisc__GetVariableValue);
#endif
#ifdef UdpMisc__CreateQuickLogicalPacket_x
FUNCTION_AT_ADDRESS(class LogicalPacket * __cdecl UdpMisc::CreateQuickLogicalPacket(void const *,int,void const *,int),UdpMisc__CreateQuickLogicalPacket);
#endif
#ifdef Util__Stristr_x
//FUNCTION_AT_ADDRESS(char * __cdecl Util::Stristr(char *,char *),Util__Stristr);
#endif
#ifdef Util__StripCharacter_x
//FUNCTION_AT_ADDRESS(void __cdecl Util::StripCharacter(char *,char),Util__StripCharacter);
#endif
#ifdef Util__ClampLower_x
//FUNCTION_AT_ADDRESS(bool __cdecl Util::ClampLower(int *,int),Util__ClampLower);
#endif
#ifdef Util__ClampUpper_x
//FUNCTION_AT_ADDRESS(bool __cdecl Util::ClampUpper(int *,int),Util__ClampUpper);
#endif
#ifdef Util__GetNextStringToken_x
//FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextStringToken(char *,char *,int,char *,bool),Util__GetNextStringToken);
#endif
#ifdef Util__IsDelimiter_x
//FUNCTION_AT_ADDRESS(bool __cdecl Util::IsDelimiter(char,char *),Util__IsDelimiter);
#endif
#ifdef Util__Crc32_x
//FUNCTION_AT_ADDRESS(int __cdecl Util::Crc32(void const *,int,int),Util__Crc32);
#endif
#ifdef Util__GetSavePrivateProfileInt_x
//FUNCTION_AT_ADDRESS(int __cdecl Util::GetSavePrivateProfileInt(char *,char *,int,char *),Util__GetSavePrivateProfileInt);
#endif
#ifdef Util__PutValueVariable_x
//FUNCTION_AT_ADDRESS(int __cdecl Util::PutValueVariable(void *,unsigned int),Util__PutValueVariable);
#endif
#ifdef Util__PutValue32_x
//FUNCTION_AT_ADDRESS(unsigned int __cdecl Util::PutValue32(void *,unsigned int),Util__PutValue32);
#endif
#ifdef Util__GetValueVariable_x
//FUNCTION_AT_ADDRESS(int __cdecl Util::GetValueVariable(void const *,unsigned int *),Util__GetValueVariable);
#endif
#ifdef TextFileReader__TextFileReader_x
FUNCTION_AT_ADDRESS( TextFileReader::TextFileReader(char *,char),TextFileReader__TextFileReader);
#endif
#ifdef TextFileReader__dTextFileReader_x
FUNCTION_AT_ADDRESS( TextFileReader::~TextFileReader(void),TextFileReader__dTextFileReader);
#endif
#ifdef TextFileReader__ReadLine_x
FUNCTION_AT_ADDRESS(int  TextFileReader::ReadLine(void),TextFileReader__ReadLine);
#endif
#ifdef TextFileReader__GetNextField_x
FUNCTION_AT_ADDRESS(int  TextFileReader::GetNextField(char *,int),TextFileReader__GetNextField);
#endif
#ifdef TextFileReader__GetLine_x
FUNCTION_AT_ADDRESS(void  TextFileReader::GetLine(char *,int),TextFileReader__GetLine);
#endif
#ifdef TextFileReader__IsOpen_x
FUNCTION_AT_ADDRESS(bool  TextFileReader::IsOpen(void),TextFileReader__IsOpen);
#endif
#ifdef flex_unit__get_x
FUNCTION_AT_ADDRESS(unsigned int  flex_unit::get(unsigned int)const ,flex_unit__get);
#endif
#ifdef flex_unit__flex_unit_x
FUNCTION_AT_ADDRESS( flex_unit::flex_unit(void),flex_unit__flex_unit);
#endif
#ifdef flex_unit__dflex_unit_x
FUNCTION_AT_ADDRESS( flex_unit::~flex_unit(void),flex_unit__dflex_unit);
#endif
#ifdef flex_unit__reserve_x
FUNCTION_AT_ADDRESS(void  flex_unit::reserve(unsigned int),flex_unit__reserve);
#endif
#ifdef flex_unit__set_x
FUNCTION_AT_ADDRESS(void  flex_unit::set(unsigned int,unsigned int),flex_unit__set);
#endif
#ifdef flex_unit__fast_mul_x
FUNCTION_AT_ADDRESS(void  flex_unit::fast_mul(class flex_unit &,class flex_unit &,unsigned int),flex_unit__fast_mul);
#endif
#ifdef vlong_value__is_zero_x
FUNCTION_AT_ADDRESS(int  vlong_value::is_zero(void)const ,vlong_value__is_zero);
#endif
#ifdef vlong_value__test_x
FUNCTION_AT_ADDRESS(int  vlong_value::test(unsigned int)const ,vlong_value__test);
#endif
#ifdef vlong_value__bits_x
FUNCTION_AT_ADDRESS(unsigned int  vlong_value::bits(void)const ,vlong_value__bits);
#endif
#ifdef vlong_value__cf_x
FUNCTION_AT_ADDRESS(int  vlong_value::cf(class vlong_value &)const ,vlong_value__cf);
#endif
#ifdef vlong_value__shl_x
FUNCTION_AT_ADDRESS(void  vlong_value::shl(void),vlong_value__shl);
#endif
#ifdef vlong_value__shr_x
FUNCTION_AT_ADDRESS(void  vlong_value::shr(void),vlong_value__shr);
#endif
#ifdef vlong_value__shr1_x
FUNCTION_AT_ADDRESS(void  vlong_value::shr(unsigned int),vlong_value__shr1);
#endif
#ifdef vlong_value__add_x
FUNCTION_AT_ADDRESS(void  vlong_value::add(class vlong_value &),vlong_value__add);
#endif
#ifdef vlong_value__subtract_x
FUNCTION_AT_ADDRESS(void  vlong_value::subtract(class vlong_value &),vlong_value__subtract);
#endif
#ifdef vlong_value__init_x
FUNCTION_AT_ADDRESS(void  vlong_value::init(unsigned int),vlong_value__init);
#endif
#ifdef vlong_value__init2_x
FUNCTION_AT_ADDRESS(void  vlong_value::init2(unsigned int,unsigned int),vlong_value__init2);
#endif
#ifdef vlong_value__copy_x
FUNCTION_AT_ADDRESS(void  vlong_value::copy(class vlong_value &),vlong_value__copy);
#endif
#ifdef vlong_value__vlong_value_x
FUNCTION_AT_ADDRESS( vlong_value::vlong_value(void),vlong_value__vlong_value);
#endif
#ifdef vlong_value__mul_x
FUNCTION_AT_ADDRESS(void  vlong_value::mul(class vlong_value &,class vlong_value &),vlong_value__mul);
#endif
#ifdef vlong_value__divide_x
FUNCTION_AT_ADDRESS(void  vlong_value::divide(class vlong_value &,class vlong_value &,class vlong_value &),vlong_value__divide);
#endif
#ifdef vlong_value__dvlong_value_x
FUNCTION_AT_ADDRESS( vlong_value::~vlong_value(void),vlong_value__dvlong_value);
#endif
#ifdef vlong__docopy_x
FUNCTION_AT_ADDRESS(void  vlong::docopy(void),vlong__docopy);
#endif
#ifdef vlong__cf_x
//FUNCTION_AT_ADDRESS(int  vlong::cf(class vlong)const ,vlong__cf);
#endif
#ifdef vlong__vlong_x
FUNCTION_AT_ADDRESS( vlong::vlong(unsigned __int64),vlong__vlong);
#endif
#ifdef vlong__vlong1_x
FUNCTION_AT_ADDRESS( vlong::vlong(class vlong const &),vlong__vlong1);
#endif
#ifdef vlong__operator_equal_x
FUNCTION_AT_ADDRESS(class vlong &  vlong::operator=(class vlong),vlong__operator_equal);
#endif
#ifdef vlong__dvlong_x
FUNCTION_AT_ADDRESS( vlong::~vlong(void),vlong__dvlong);
#endif
#ifdef vlong__operator_plus_equal_x
FUNCTION_AT_ADDRESS(class vlong &  vlong::operator+=(class vlong const &),vlong__operator_plus_equal);
#endif
#ifdef vlong__operator_minus_equal_x
FUNCTION_AT_ADDRESS(class vlong &  vlong::operator-=(class vlong const &),vlong__operator_minus_equal);
#endif
#ifdef monty__monty_x
FUNCTION_AT_ADDRESS( monty::monty(class vlong const &),monty__monty);
#endif
#ifdef monty__mul_x
FUNCTION_AT_ADDRESS(void  monty::mul(class vlong &,class vlong const &),monty__mul);
#endif
#ifdef monty__exp_x
FUNCTION_AT_ADDRESS(class vlong  monty::exp(class vlong const &,class vlong const &),monty__exp);
#endif
#ifdef monty__dmonty_x
FUNCTION_AT_ADDRESS( monty::~monty(void),monty__dmonty);
#endif
#ifdef ZlibUtil__zcalloc_x
FUNCTION_AT_ADDRESS(void * __cdecl ZlibUtil::zcalloc(void *,unsigned int,unsigned int),ZlibUtil__zcalloc);
#endif
#ifdef ZlibUtil__zfree_x
FUNCTION_AT_ADDRESS(void __cdecl ZlibUtil::zfree(void *,void *),ZlibUtil__zfree);
#endif
#ifdef ZlibUtil__zcompress_x
FUNCTION_AT_ADDRESS(int __cdecl ZlibUtil::zcompress(unsigned char *,unsigned long *,unsigned char const *,unsigned long,int),ZlibUtil__zcompress);
#endif
#ifdef ZlibUtil__zuncompress_x
FUNCTION_AT_ADDRESS(int __cdecl ZlibUtil::zuncompress(unsigned char *,unsigned long *,unsigned char const *,unsigned long),ZlibUtil__zuncompress);
#endif
#ifdef ZlibUtil__Compress_x
FUNCTION_AT_ADDRESS(int __cdecl ZlibUtil::Compress(char const *,int,char *,int,int),ZlibUtil__Compress);
#endif
#ifdef ZlibUtil__Decompress_x
FUNCTION_AT_ADDRESS(int __cdecl ZlibUtil::Decompress(char const *,int,char *,int),ZlibUtil__Decompress);
#endif
#ifdef PackFS__PackFS_x
FUNCTION_AT_ADDRESS( PackFS::PackFS(void),PackFS__PackFS);
#endif
#ifdef PackFS__addFileSystem_x
//FUNCTION_AT_ADDRESS(bool  PackFS::addFileSystem(class FilePath),PackFS__addFileSystem);
#endif
#ifdef PackFS__removeFileSystem_x
FUNCTION_AT_ADDRESS(void  PackFS::removeFileSystem(class FilePath),PackFS__removeFileSystem);
#endif
#ifdef SharedString___updateTag_x
FUNCTION_AT_ADDRESS(void  SharedString::_updateTag(void)const ,SharedString___updateTag);
#endif
#ifdef FilePath__FilePath2_x
FUNCTION_AT_ADDRESS( FilePath::FilePath(void),FilePath__FilePath2);
#endif
#ifdef PackFile__dPackFile_x
FUNCTION_AT_ADDRESS( PackFile::~PackFile(void),PackFile__dPackFile);
#endif
#ifdef PackFile__close_x
FUNCTION_AT_ADDRESS(void  PackFile::close(void),PackFile__close);
#endif
#ifdef _PackFileData__d_PackFileData_x
FUNCTION_AT_ADDRESS( _PackFileData::~_PackFileData(void),_PackFileData__d_PackFileData);
#endif
#ifdef PackFile__length_x
FUNCTION_AT_ADDRESS(int  PackFile::length(void)const ,PackFile__length);
#endif
#ifdef PackFile__read_x
FUNCTION_AT_ADDRESS(int  PackFile::read(void * const,int),PackFile__read);
#endif
#ifdef PackFS__openFile_x
//FUNCTION_AT_ADDRESS(bool  PackFS::openFile(class FilePath,class PackFile *)const ,PackFS__openFile);
#endif
#ifdef CRC32Generator__generateCRC32_x
FUNCTION_AT_ADDRESS(unsigned int  CRC32Generator::generateCRC32(unsigned char const *,unsigned int)const ,CRC32Generator__generateCRC32);
#endif
#ifdef CRC32Generator__updateCRC32_x
FUNCTION_AT_ADDRESS(unsigned int  CRC32Generator::updateCRC32(unsigned int,unsigned char const *,unsigned int)const ,CRC32Generator__updateCRC32);
#endif
#ifdef CSidlScreenWnd__dCSidlScreenWnd_x
FUNCTION_AT_ADDRESS( CSidlScreenWnd::~CSidlScreenWnd(void),CSidlScreenWnd__dCSidlScreenWnd);
#endif
#ifdef CSidlScreenWnd__WndNotification_x
FUNCTION_AT_ADDRESS( int CSidlScreenWnd::WndNotification(class CXWnd *,unsigned __int32,void *),CSidlScreenWnd__WndNotification);
#endif
#ifdef CSidlScreenWnd__CSidlScreenWnd_x
FUNCTION_AT_ADDRESS( CSidlScreenWnd::CSidlScreenWnd(class CXWnd *,unsigned __int32,class CXRect,class CXStr),CSidlScreenWnd__CSidlScreenWnd);
#endif
#ifdef CSidlScreenWnd__CSidlScreenWnd1_x
FUNCTION_AT_ADDRESS( CSidlScreenWnd::CSidlScreenWnd(class CXWnd *x,class CXStr*,int,int,char *),CSidlScreenWnd__CSidlScreenWnd1);
#endif
#ifdef CSidlScreenWnd__CSidlScreenWnd2_x
FUNCTION_AT_ADDRESS( CSidlScreenWnd::CSidlScreenWnd(CXWnd *x,CXStr),CSidlScreenWnd__CSidlScreenWnd2);
#endif
#ifdef CSidlScreenWnd__Init_x
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::Init(class CXWnd *,unsigned __int32,class CXRect,class CXStr,int,char *),CSidlScreenWnd__Init);
#endif
#ifdef CSidlScreenWnd__Init1_x
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::Init(int,class CXStr*,int,int,int),CSidlScreenWnd__Init1);
#endif
#ifdef CSidlScreenWnd__SetScreen_x
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::SetScreen(class CXStr*),CSidlScreenWnd__SetScreen);
#endif
#ifdef CSidlScreenWnd__LoadSidlScreen_x
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::LoadSidlScreen(void),CSidlScreenWnd__LoadSidlScreen);
#endif
#ifdef CSidlScreenWnd__CalculateVSBRange_x
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::CalculateVSBRange(void),CSidlScreenWnd__CalculateVSBRange);
#endif
#ifdef CSidlScreenWnd__CalculateHSBRange_x
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::CalculateHSBRange(void),CSidlScreenWnd__CalculateHSBRange);
#endif
#ifdef CSidlScreenWnd__DrawSidlPiece_x
FUNCTION_AT_ADDRESS(int  CSidlScreenWnd::DrawSidlPiece(class CScreenPieceTemplate *,class CXRect,class CXRect)const ,CSidlScreenWnd__DrawSidlPiece);
#endif
#ifdef CSidlScreenWnd__GetSidlPiece_x
FUNCTION_AT_ADDRESS(class CScreenPieceTemplate *  CSidlScreenWnd::GetSidlPiece(class CXStr*, bool bTopLevel)const ,CSidlScreenWnd__GetSidlPiece);
#endif
#ifdef CSidlScreenWnd__GetSidlPieceRect_x
FUNCTION_AT_ADDRESS(class CXRect  CSidlScreenWnd::GetSidlPieceRect(class CScreenPieceTemplate *,class CXRect)const ,CSidlScreenWnd__GetSidlPieceRect);
#endif
#ifdef CSidlScreenWnd__AddButtonToRadioGroup_x
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::AddButtonToRadioGroup(class CXStr,class CButtonWnd *),CSidlScreenWnd__AddButtonToRadioGroup);
#endif
#ifdef CRadioGroup__CRadioGroup_x
FUNCTION_AT_ADDRESS( CRadioGroup::CRadioGroup(class CXStr),CRadioGroup__CRadioGroup);
#endif
#ifdef CRadioGroup__GetName_x
FUNCTION_AT_ADDRESS(class CXStr  CRadioGroup::GetName(void)const ,CRadioGroup__GetName);
#endif
#ifdef CSidlScreenWnd__CreateChildrenFromSidl_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::CreateChildrenFromSidl(DWORD), CSidlScreenWnd__CreateChildrenFromSidl);
#else
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::CreateChildrenFromSidl(void), CSidlScreenWnd__CreateChildrenFromSidl);
#endif
#endif
#ifdef CSidlScreenWnd__StoreIniVis_x
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::StoreIniVis(void),CSidlScreenWnd__StoreIniVis);
#endif
#ifdef CSidlScreenWnd__EnableIniStorage_x
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::EnableIniStorage(int,char *),CSidlScreenWnd__EnableIniStorage);
#endif
#ifdef CSidlScreenWnd__ConvertToRes_x
FUNCTION_AT_ADDRESS(int  CSidlScreenWnd::ConvertToRes(int,int,int,int),CSidlScreenWnd__ConvertToRes);
#endif
#ifdef CSidlScreenWnd__GetChildItem_x
FUNCTION_AT_ADDRESS(class CXWnd * CSidlScreenWnd::GetChildItem(CXStr const &, bool bDebug),CSidlScreenWnd__GetChildItem);
#endif
#ifdef CSidlScreenWnd__HandleLButtonUp_x
FUNCTION_AT_ADDRESS(int  CSidlScreenWnd::HandleLButtonUp(class CXPoint,unsigned __int32),CSidlScreenWnd__HandleLButtonUp);
#endif
#ifdef CSidlScreenWnd__LoadIniListWnd_x
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::LoadIniListWnd(class CListWnd *,char *),CSidlScreenWnd__LoadIniListWnd);
#endif
#ifdef CSidlScreenWnd__StoreIniListWnd_x
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::StoreIniListWnd(class CListWnd const *,char *),CSidlScreenWnd__StoreIniListWnd);
#endif
#ifdef CXWndDrawTemplate__CXWndDrawTemplate_x
FUNCTION_AT_ADDRESS( CXWndDrawTemplate::CXWndDrawTemplate(void),CXWndDrawTemplate__CXWndDrawTemplate);
#endif
#ifdef CUITextureInfo__CUITextureInfo1_x
FUNCTION_AT_ADDRESS( CUITextureInfo::CUITextureInfo(void),CUITextureInfo__CUITextureInfo1);
#endif
#ifdef CButtonDrawTemplate__CButtonDrawTemplate_x
FUNCTION_AT_ADDRESS( CButtonDrawTemplate::CButtonDrawTemplate(void),CButtonDrawTemplate__CButtonDrawTemplate);
#endif
#ifdef CScrollbarTemplate__dCScrollbarTemplate_x
FUNCTION_AT_ADDRESS( CScrollbarTemplate::~CScrollbarTemplate(void),CScrollbarTemplate__dCScrollbarTemplate);
#endif
#ifdef CXWndDrawTemplate__dCXWndDrawTemplate_x
FUNCTION_AT_ADDRESS( CXWndDrawTemplate::~CXWndDrawTemplate(void),CXWndDrawTemplate__dCXWndDrawTemplate);
#endif
#ifdef CButtonDrawTemplate__GetSize_x
FUNCTION_AT_ADDRESS(class CXSize  CButtonDrawTemplate::GetSize(void)const ,CButtonDrawTemplate__GetSize);
#endif
#ifdef CXWnd__CXWnd_x
FUNCTION_AT_ADDRESS( CXWnd::CXWnd(class CXWnd *,unsigned __int32,class CXRect),CXWnd__CXWnd);
#endif
#ifdef CXWnd__IsType_x
FUNCTION_AT_ADDRESS(bool CXWnd::IsType(enum EWndRuntimeType)const ,CXWnd__IsType);
#endif
#ifdef CXWnd__SetFocus_x
FUNCTION_AT_ADDRESS(class CXWnd *  CXWnd::SetFocus(void),CXWnd__SetFocus);
#endif
#ifdef CXWnd__ClrFocus_x
FUNCTION_AT_ADDRESS(void  CXWnd::ClrFocus(void),CXWnd__ClrFocus);
#endif
#ifdef CXWnd__Destroy_x
FUNCTION_AT_ADDRESS(int CXWnd::Destroy(void),CXWnd__Destroy);
#endif
#ifdef CXWnd__HasFocus_x
FUNCTION_AT_ADDRESS(bool  CXWnd::HasFocus(void)const ,CXWnd__HasFocus);
#endif
#ifdef CXWnd__Show_x
FUNCTION_AT_ADDRESS(int  CXWnd::Show(bool,bool),CXWnd__Show);
#endif
#ifdef CXWnd__DrawCloseBox_x
FUNCTION_AT_ADDRESS(int  CXWnd::DrawCloseBox(void)const ,CXWnd__DrawCloseBox);
#endif
#ifdef CXWnd__DrawMinimizeBox_x
FUNCTION_AT_ADDRESS(int  CXWnd::DrawMinimizeBox(void)const ,CXWnd__DrawMinimizeBox);
#endif
#ifdef CXWnd__DrawTileBox_x
FUNCTION_AT_ADDRESS(int  CXWnd::DrawTileBox(void)const ,CXWnd__DrawTileBox);
#endif
#ifdef CXWnd__DrawVScrollbar_x
FUNCTION_AT_ADDRESS(int  CXWnd::DrawVScrollbar(int,int,int)const ,CXWnd__DrawVScrollbar);
#endif
#ifdef CXRect__CXRect_x
FUNCTION_AT_ADDRESS( CXRect::CXRect(int,int,int,int),CXRect__CXRect);
#endif
#ifdef CXRect__operator_equal_x
FUNCTION_AT_ADDRESS(class CXRect &  CXRect::operator=(class CXRect const &),CXRect__operator_equal);
#endif
#ifdef CXWnd__DrawHScrollbar_x
FUNCTION_AT_ADDRESS(int  CXWnd::DrawHScrollbar(int,int,int)const ,CXWnd__DrawHScrollbar);
#endif
#ifdef CXWnd__Refade_x
FUNCTION_AT_ADDRESS(void  CXWnd::Refade(void),CXWnd__Refade);
#endif
#ifdef CXWnd__Move_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(int  CXWnd::Move(class CXPoint const &), CXWnd__Move);
#else
FUNCTION_AT_ADDRESS(int  CXWnd::Move(class CXPoint),CXWnd__Move);
#endif
#endif
#ifdef CXWnd__Move1_x
FUNCTION_AT_ADDRESS(int CXWnd::Move(class CXRect *, bool, bool, bool, bool), CXWnd__Move1);
#endif
#ifdef CXPoint__operator_equal_x
FUNCTION_AT_ADDRESS(class CXPoint  CXPoint::operator=(class CXPoint),CXPoint__operator_equal);
#endif
#ifdef CXWnd__ProcessTransition_x
FUNCTION_AT_ADDRESS(int  CXWnd::ProcessTransition(void),CXWnd__ProcessTransition);
#endif
#ifdef CXWnd__BringToTop_x
FUNCTION_AT_ADDRESS(void  CXWnd::BringToTop(bool),CXWnd__BringToTop);
#endif
#ifdef CXWnd__StartFade_x
FUNCTION_AT_ADDRESS(void  CXWnd::StartFade(unsigned char,unsigned __int32),CXWnd__StartFade);
#endif
#ifdef CXWnd__Minimize_x
FUNCTION_AT_ADDRESS(int  CXWnd::Minimize(bool),CXWnd__Minimize);
#endif
#ifdef CXWnd__IsReallyVisible_x
FUNCTION_AT_ADDRESS(bool  CXWnd::IsReallyVisible(void)const ,CXWnd__IsReallyVisible);
#endif
#ifdef CXWnd__GetNextChildWnd_x
FUNCTION_AT_ADDRESS(class CXWnd *  CXWnd::GetNextChildWnd(class CXWnd *)const ,CXWnd__GetNextChildWnd);
#endif
#ifdef CXWnd__GetChildWndAt_x
FUNCTION_AT_ADDRESS(class CXWnd * CXWnd::GetChildWndAt(class CXPoint *,int,int)const ,CXWnd__GetChildWndAt);
#endif
#ifdef CXWnd__GetFirstChildWnd_x
FUNCTION_AT_ADDRESS(class CXWnd *  CXWnd::GetFirstChildWnd(void)const ,CXWnd__GetFirstChildWnd);
#endif
#ifdef CXWnd__GetNextSib_x
FUNCTION_AT_ADDRESS(class CXWnd *  CXWnd::GetNextSib(void)const ,CXWnd__GetNextSib);
#endif
#ifdef CXWnd__DoAllDrawing_x
FUNCTION_AT_ADDRESS(int  CXWnd::DoAllDrawing(void)const ,CXWnd__DoAllDrawing);
#endif
#ifdef CXWnd__DrawLasso_x
FUNCTION_AT_ADDRESS(int __cdecl CXWnd::DrawLasso(class CXRect,unsigned long,class CXRect),CXWnd__DrawLasso);
#endif
#ifdef CXWnd__DrawChildren_x
FUNCTION_AT_ADDRESS(int  CXWnd::DrawChildren(void)const ,CXWnd__DrawChildren);
#endif
#ifdef CXWnd__BringChildWndToTop_x
FUNCTION_AT_ADDRESS(void  CXWnd::BringChildWndToTop(class CXWnd *),CXWnd__BringChildWndToTop);
#endif
#ifdef CXWnd__DrawColoredRect_x
FUNCTION_AT_ADDRESS(int __cdecl CXWnd::DrawColoredRect(class CXRect,unsigned long,class CXRect),CXWnd__DrawColoredRect);
#endif
#ifdef CXWnd__GetTooltipRect_x
FUNCTION_AT_ADDRESS(class CXRect *__cdecl CXWnd::GetTooltipRect(class CXRect *),CXWnd__GetTooltipRect);
#endif
#ifdef CXWnd__GetTooltipRect1_x
FUNCTION_AT_ADDRESS(class CXRect __cdecl CXWnd::GetTooltipRect(class CXPoint,class CXSize),CXWnd__GetTooltipRect1);
#endif
#ifdef CXWnd__DrawTooltipAtPoint_x
FUNCTION_AT_ADDRESS(void  CXWnd::DrawTooltipAtPoint(class CXPoint)const ,CXWnd__DrawTooltipAtPoint);
#endif
#ifdef CXWnd__Bottom_x
FUNCTION_AT_ADDRESS(void  CXWnd::Bottom(void),CXWnd__Bottom);
#endif
#ifdef CXWnd__Center_x
FUNCTION_AT_ADDRESS(void  CXWnd::Center(void),CXWnd__Center);
#endif
#ifdef CXWnd__Right_x
FUNCTION_AT_ADDRESS(void  CXWnd::Right(void),CXWnd__Right);
#endif
#ifdef CXWnd__Left_x
FUNCTION_AT_ADDRESS(void  CXWnd::Left(void),CXWnd__Left);
#endif
#ifdef CXWnd__SetLookLikeParent_x
FUNCTION_AT_ADDRESS(void  CXWnd::SetLookLikeParent(void),CXWnd__SetLookLikeParent);
#endif
#ifdef CXWnd__GetClientClipRect_x
FUNCTION_AT_ADDRESS(class CXRect  CXWnd::GetClientClipRect(void)const ,CXWnd__GetClientClipRect);
#endif
#ifdef CXWnd__GetScreenClipRect_x
FUNCTION_AT_ADDRESS(class CXRect  CXWnd::GetScreenClipRect(void)const ,CXWnd__GetScreenClipRect);
#endif
#ifdef CXWnd__IsActive_x
FUNCTION_AT_ADDRESS(bool  CXWnd::IsActive(void)const ,CXWnd__IsActive);
#endif
#ifdef CXWnd__IsDescendantOf_x
FUNCTION_AT_ADDRESS(bool  CXWnd::IsDescendantOf(class CXWnd const *)const ,CXWnd__IsDescendantOf);
#endif
#ifdef CXWnd__GetBorderFrame_x
FUNCTION_AT_ADDRESS(class CTAFrameDraw const *  CXWnd::GetBorderFrame(void)const ,CXWnd__GetBorderFrame);
#endif
#ifdef CXWnd__GetTitlebarHeader_x
FUNCTION_AT_ADDRESS(class CTAFrameDraw const *  CXWnd::GetTitlebarHeader(void)const ,CXWnd__GetTitlebarHeader);
#endif
#ifdef CXWnd__GetCloseBoxTemplate_x
FUNCTION_AT_ADDRESS(class CButtonDrawTemplate const *  CXWnd::GetCloseBoxTemplate(void)const ,CXWnd__GetCloseBoxTemplate);
#endif
#ifdef CXWnd__GetMinimizeBoxTemplate_x
FUNCTION_AT_ADDRESS(class CButtonDrawTemplate const *  CXWnd::GetMinimizeBoxTemplate(void)const ,CXWnd__GetMinimizeBoxTemplate);
#endif
#ifdef CXWnd__GetTileBoxTemplate_x
FUNCTION_AT_ADDRESS(class CButtonDrawTemplate const *  CXWnd::GetTileBoxTemplate(void)const ,CXWnd__GetTileBoxTemplate);
#endif
#ifdef CXWnd__GetRelativeRect_x
FUNCTION_AT_ADDRESS(class CXRect  CXWnd::GetRelativeRect(void)const ,CXWnd__GetRelativeRect);
#endif
#ifdef CXWnd__GetScreenRect_x
FUNCTION_AT_ADDRESS(class CXRect  CXWnd::GetScreenRect(void)const ,CXWnd__GetScreenRect);
#endif
#ifdef CXWnd__Resize_x
FUNCTION_AT_ADDRESS(int  CXWnd::Resize(int, int, bool, bool, bool),CXWnd__Resize);
#endif
#ifdef CXWnd__GetChildItem_x
FUNCTION_AT_ADDRESS(class CXWnd *  CXWnd::GetChildItem(CXStr const &),CXWnd__GetChildItem);
#endif
#ifdef CXWnd__SetParent_x
FUNCTION_AT_ADDRESS(CXWnd * CXWnd::SetParent(CXWnd *),CXWnd__SetParent);
#endif
#ifdef CXWnd__SetZLayer_x
FUNCTION_AT_ADDRESS(void  CXWnd::SetZLayer(int),CXWnd__SetZLayer);
#endif
#ifdef CXWnd__SetFirstChildPointer_x
FUNCTION_AT_ADDRESS(void  CXWnd::SetFirstChildPointer(class CXWnd *),CXWnd__SetFirstChildPointer);
#endif
#ifdef CXWnd__SetNextSibPointer_x
FUNCTION_AT_ADDRESS(void  CXWnd::SetNextSibPointer(class CXWnd *),CXWnd__SetNextSibPointer);
#endif
#ifdef CXWnd__SetMouseOver_x
FUNCTION_AT_ADDRESS(void  CXWnd::SetMouseOver(bool),CXWnd__SetMouseOver);
#endif
#ifdef CXWnd__SetKeyTooltip_x
FUNCTION_AT_ADDRESS(void  CXWnd::SetKeyTooltip(int,int),CXWnd__SetKeyTooltip);
#endif
#ifdef CXWnd__GetXMLTooltip_x
FUNCTION_AT_ADDRESS(class CXStr  CXWnd::GetXMLTooltip(void)const ,CXWnd__GetXMLTooltip);
#endif
#ifdef CXWnd__DrawTooltip_x
FUNCTION_AT_ADDRESS(int CXWnd::DrawTooltip(class CXWnd const *)const,CXWnd__DrawTooltip);
#endif
#ifdef CMutexSyncCounted__CMutexSyncCounted_x
FUNCTION_AT_ADDRESS( CMutexSyncCounted::CMutexSyncCounted(void),CMutexSyncCounted__CMutexSyncCounted);
#endif
#ifdef CMutexSyncCounted__dCMutexSyncCounted_x
FUNCTION_AT_ADDRESS( CMutexSyncCounted::~CMutexSyncCounted(void),CMutexSyncCounted__dCMutexSyncCounted);
#endif
#ifdef CMutexLockCounted__dCMutexLockCounted_x
FUNCTION_AT_ADDRESS( CMutexLockCounted::~CMutexLockCounted(void),CMutexLockCounted__dCMutexLockCounted);
#endif
#ifdef CXStr__AssureCopy_x
FUNCTION_AT_ADDRESS(void  CXStr::AssureCopy(void),CXStr__AssureCopy);
#endif
#ifdef CXStr__Assure_x
//FUNCTION_AT_ADDRESS(void  CXStr::Assure(long,enum EStringEncoding),CXStr__Assure);
#endif
#ifdef CXStr__AllocRepNoLock_x
//FUNCTION_AT_ADDRESS(struct CStrRep *  CXStr::AllocRepNoLock(long,enum EStringEncoding),CXStr__AllocRepNoLock);
#endif
#ifdef CXStr__FreeRep_x
FUNCTION_AT_ADDRESS(void  CXStr::FreeRep(struct CStrRep *),CXStr__FreeRep);
#endif
#ifdef CXStr__FreeRepNoLock_x
FUNCTION_AT_ADDRESS(void  CXStr::FreeRepNoLock(struct CStrRep *),CXStr__FreeRepNoLock);
#endif
#ifdef CXStr__CXStr2_x
FUNCTION_AT_ADDRESS( CXStr::CXStr(char),CXStr__CXStr2);
#endif
#ifdef CXStr__CXStr3_x
FUNCTION_AT_ADDRESS( CXStr::CXStr(char const *),CXStr__CXStr3);
#endif
#ifdef CXStr__CXStr4_x
FUNCTION_AT_ADDRESS( CXStr::CXStr(char const *,int),CXStr__CXStr4);
#endif
#ifdef CXStr__CXStr5_x
FUNCTION_AT_ADDRESS( CXStr::CXStr(unsigned short const *),CXStr__CXStr5);
#endif
#ifdef CXStr__CXStr6_x
FUNCTION_AT_ADDRESS( CXStr::CXStr(int,int,char),CXStr__CXStr6);
#endif
#ifdef CXStr__operator_equal_x
FUNCTION_AT_ADDRESS(class CXStr &  CXStr::operator=(class CXStr const &),CXStr__operator_equal);
#endif
#ifdef CXStr__operator_equal1_x
FUNCTION_AT_ADDRESS(class CXStr &  CXStr::operator=(char const *),CXStr__operator_equal1);
#endif
#ifdef CXStr__GetChar_x
FUNCTION_AT_ADDRESS(char  CXStr::GetChar(long)const ,CXStr__GetChar);
#endif
#ifdef CXStr__SetChar_x
FUNCTION_AT_ADDRESS(char  CXStr::SetChar(long,char),CXStr__SetChar);
#endif
#ifdef CXStr__GetUnicode_x
FUNCTION_AT_ADDRESS(unsigned short  CXStr::GetUnicode(long)const ,CXStr__GetUnicode);
#endif
#ifdef CXStr__SetUnicode_x
FUNCTION_AT_ADDRESS(unsigned short  CXStr::SetUnicode(long,unsigned short),CXStr__SetUnicode);
#endif
#ifdef CXStr__Compare_x
//FUNCTION_AT_ADDRESS(int  CXStr::Compare(class CXStr const &,enum CompareCode)const ,CXStr__Compare);
#endif
#ifdef CXStr__CompareN_x
//FUNCTION_AT_ADDRESS(int  CXStr::CompareN(class CXStr const &,int,enum CompareCode)const ,CXStr__CompareN);
#endif
#ifdef CXStr__operator_equal_equal_x
FUNCTION_AT_ADDRESS(int  CXStr::operator==(class CXStr const &)const ,CXStr__operator_equal_equal);
#endif
#ifdef CXStr__operator_equal_equal1_x
FUNCTION_AT_ADDRESS(int  CXStr::operator==(char const *)const ,CXStr__operator_equal_equal1);
#endif
#ifdef CXStr__operatort__x
FUNCTION_AT_ADDRESS(int  CXStr::operator>(class CXStr const &)const ,CXStr__operatort_);
#endif
#ifdef CXStr__BlankPreAllocate_x
FUNCTION_AT_ADDRESS(void  CXStr::BlankPreAllocate(int),CXStr__BlankPreAllocate);
#endif
#ifdef CXStr__operator_plus_equal_x
FUNCTION_AT_ADDRESS(void  CXStr::operator+=(class CXStr const &),CXStr__operator_plus_equal);
#endif
#ifdef CXStr__operator_plus_equal1_x
FUNCTION_AT_ADDRESS(void  CXStr::operator+=(char const *),CXStr__operator_plus_equal1);
#endif
#ifdef CXStr__operator_plus_equal2_x
FUNCTION_AT_ADDRESS(void  CXStr::operator+=(char),CXStr__operator_plus_equal2);
#endif
#ifdef CXStr__operator_plus_equal3_x
FUNCTION_AT_ADDRESS(void  CXStr::operator+=(unsigned short),CXStr__operator_plus_equal3);
#endif
#ifdef CXStr__Delete_x
FUNCTION_AT_ADDRESS(void  CXStr::Delete(long,long),CXStr__Delete);
#endif
#ifdef CXStr__Insert_x
FUNCTION_AT_ADDRESS(void  CXStr::Insert(long,char),CXStr__Insert);
#endif
#ifdef CXStr__Insert1_x
FUNCTION_AT_ADDRESS(void  CXStr::Insert(long,class CXStr const &),CXStr__Insert1);
#endif
#ifdef CXStr__Copy_x
FUNCTION_AT_ADDRESS(class CXStr  CXStr::Copy(long,long)const ,CXStr__Copy);
#endif
#ifdef CXStr__CopySelf_x
FUNCTION_AT_ADDRESS(void  CXStr::CopySelf(long,long),CXStr__CopySelf);
#endif
#ifdef CXStr__SetString_x
FUNCTION_AT_ADDRESS(void CXStr::SetString(const char* Str, long len),CXStr__SetString);
#endif
#ifdef CXStr__StripTrailing_x
FUNCTION_AT_ADDRESS(void  CXStr::StripTrailing(char),CXStr__StripTrailing);
#endif
#ifdef CXStr__StripLeading_x
FUNCTION_AT_ADDRESS(void  CXStr::StripLeading(char),CXStr__StripLeading);
#endif
#ifdef CXStr__StripAll_x
FUNCTION_AT_ADDRESS(void  CXStr::StripAll(char),CXStr__StripAll);
#endif
#ifdef CXStr__Strip_x
FUNCTION_AT_ADDRESS(void  CXStr::Strip(char),CXStr__Strip);
#endif
#ifdef CXStr__GetEncoding_x
//FUNCTION_AT_ADDRESS(enum EStringEncoding  CXStr::GetEncoding(void)const ,CXStr__GetEncoding);
#endif
#ifdef CXStr__SetEncoding_x
//FUNCTION_AT_ADDRESS(void  CXStr::SetEncoding(enum EStringEncoding),CXStr__SetEncoding);
#endif
#ifdef CXStr__operator_char_p_x
//FUNCTION_AT_ADDRESS( CXStr::operator char *(void)const ,CXStr__operator_char_p);
#endif
#ifdef CXStr__operator_unsigned_short_p_x
//FUNCTION_AT_ADDRESS( CXStr::operator unsigned short *(void)const ,CXStr__operator_unsigned_short_p);
#endif
#ifdef CXStr__SetUpperCase_x
FUNCTION_AT_ADDRESS(void  CXStr::SetUpperCase(void),CXStr__SetUpperCase);
#endif
#ifdef CXStr__SetLowerCase_x
FUNCTION_AT_ADDRESS(void  CXStr::SetLowerCase(void),CXStr__SetLowerCase);
#endif
#ifdef CXStr__ConvertToInt_x
FUNCTION_AT_ADDRESS(int  CXStr::ConvertToInt(void),CXStr__ConvertToInt);
#endif
#ifdef CXStr__PrintString_x
FUNCTION_AT_ADDRESS(int __cdecl CXStr::PrintString(char const *,...),CXStr__PrintString);
#endif
#ifdef CXStr__FindLast_x
FUNCTION_AT_ADDRESS(bool  CXStr::FindLast(char,int &),CXStr__FindLast);
#endif
#ifdef CXStr__Find_x
FUNCTION_AT_ADDRESS(bool  CXStr::Find(char,int &),CXStr__Find);
#endif
#ifdef CXStr__Find1_x
FUNCTION_AT_ADDRESS(bool  CXStr::Find(unsigned short,int &),CXStr__Find1);
#endif
#ifdef CXStr__Find2_x
FUNCTION_AT_ADDRESS(bool  CXStr::Find(class CXStr const &,int &),CXStr__Find2);
#endif
#ifdef CXStr__AddCr_x
FUNCTION_AT_ADDRESS(void  CXStr::AddCr(void),CXStr__AddCr);
#endif
#ifdef CXStr__Utf8ToUnicode_x
FUNCTION_AT_ADDRESS(int __cdecl CXStr::Utf8ToUnicode(char const *,unsigned short *,int),CXStr__Utf8ToUnicode);
#endif
#ifdef CXStr__LenUnicodeToUtf8_x
FUNCTION_AT_ADDRESS(int __cdecl CXStr::LenUnicodeToUtf8(unsigned short const *),CXStr__LenUnicodeToUtf8);
#endif
#ifdef CXStr__UnicodeToUtf8_x
FUNCTION_AT_ADDRESS(int __cdecl CXStr::UnicodeToUtf8(unsigned short const *,char *,int),CXStr__UnicodeToUtf8);
#endif
#ifdef CListWnd__CListWnd_x
FUNCTION_AT_ADDRESS( CListWnd::CListWnd(class CXWnd *,unsigned __int32,class CXRect const &),CListWnd__CListWnd);
#endif
#ifdef CListWnd__dCListWnd_x
FUNCTION_AT_ADDRESS( CListWnd::~CListWnd(void),CListWnd__dCListWnd);
#endif
#ifdef CListWnd__GetCurSel_x
FUNCTION_AT_ADDRESS(int  CListWnd::GetCurSel(void)const,CListWnd__GetCurSel);
#endif
#ifdef CListWnd__GetCurCol_x
FUNCTION_AT_ADDRESS(int  CListWnd::GetCurCol(void)const ,CListWnd__GetCurCol);
#endif
#ifdef CListWnd__GetItemData_x
FUNCTION_AT_ADDRESS(unsigned __int32  CListWnd::GetItemData(int)const ,CListWnd__GetItemData);
#endif
#ifdef CListWnd__GetItemText_x
FUNCTION_AT_ADDRESS(class CXStr *CListWnd::GetItemText(class CXStr *,int,int)const ,CListWnd__GetItemText);
#endif
#ifdef CListWnd__GetItemIcon_x
FUNCTION_AT_ADDRESS(class CTextureAnimation const *CListWnd::GetItemIcon(int,int)const ,CListWnd__GetItemIcon);
#endif
#ifdef CListWnd__GetItemColor_x
FUNCTION_AT_ADDRESS(unsigned long  CListWnd::GetItemColor(int,int)const ,CListWnd__GetItemColor);
#endif
#ifdef CListWnd__GetColumnFlags_x
FUNCTION_AT_ADDRESS(unsigned __int32  CListWnd::GetColumnFlags(int)const ,CListWnd__GetColumnFlags);
#endif
#ifdef CListWnd__GetColumnWidth_x
FUNCTION_AT_ADDRESS(int  CListWnd::GetColumnWidth(int)const ,CListWnd__GetColumnWidth);
#endif
#ifdef CListWnd__SetColumnWidth_x
FUNCTION_AT_ADDRESS(void  CListWnd::SetColumnWidth(int,int),CListWnd__SetColumnWidth);
#endif
#ifdef CListWnd__ShiftColumnSeparator_x
FUNCTION_AT_ADDRESS(void  CListWnd::ShiftColumnSeparator(int,int),CListWnd__ShiftColumnSeparator);
#endif
#ifdef CListWnd__GetColumnMinWidth_x
FUNCTION_AT_ADDRESS(int CListWnd::GetColumnMinWidth(int)const ,CListWnd__GetColumnMinWidth);
#endif
#ifdef CListWnd__GetColumnTooltip_x
FUNCTION_AT_ADDRESS(CXStr CListWnd::GetColumnTooltip(int) const ,CListWnd__GetColumnTooltip);
#endif
#ifdef CListWnd__GetColumnJustification_x
FUNCTION_AT_ADDRESS(int  CListWnd::GetColumnJustification(int)const ,CListWnd__GetColumnJustification);
#endif
#ifdef CListWnd__SetColumnJustification_x
FUNCTION_AT_ADDRESS(void  CListWnd::SetColumnJustification(int,int),CListWnd__SetColumnJustification);
#endif
#ifdef CListWnd__GetColumnLabel_x
FUNCTION_AT_ADDRESS(class CXStr  CListWnd::GetColumnLabel(int)const ,CListWnd__GetColumnLabel);
#endif
#ifdef CListWnd__GetColumnAnimation_x
FUNCTION_AT_ADDRESS(class CTextureAnimation const *  CListWnd::GetColumnAnimation(int)const ,CListWnd__GetColumnAnimation);
#endif
#ifdef CListWnd__GetColumnAnimationSelected_x
FUNCTION_AT_ADDRESS(class CTextureAnimation const *  CListWnd::GetColumnAnimationSelected(int)const ,CListWnd__GetColumnAnimationSelected);
#endif
#ifdef CListWnd__GetColumnAnimationMouseOver_x
FUNCTION_AT_ADDRESS(class CTextureAnimation const *  CListWnd::GetColumnAnimationMouseOver(int)const ,CListWnd__GetColumnAnimationMouseOver);
#endif
#ifdef CListWnd__AddLine_x
FUNCTION_AT_ADDRESS(int  CListWnd::AddLine(SListWndLine *),CListWnd__AddLine);
#endif
#ifdef CListWnd__AddString_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(int CListWnd::AddString(CXStr *, COLORREF, unsigned __int32, CTextureAnimation *, char*, bool),CListWnd__AddString);
#else
FUNCTION_AT_ADDRESS(int CListWnd::AddString(class CXStr *str,COLORREF cref, unsigned __int32 data,class CTextureAnimation const *p5, const char * pstr),CListWnd__AddString);
#endif
#endif
#ifdef CListWnd__RemoveString_x
FUNCTION_AT_ADDRESS(void  CListWnd::RemoveString(int),CListWnd__RemoveString);
#endif
#ifdef CListWnd__InsertLine_x
FUNCTION_AT_ADDRESS(void CListWnd::InsertLine(int ID, SListWndLine *rEntry),CListWnd__InsertLine);
#endif
#ifdef CListWnd__RemoveLine_x
FUNCTION_AT_ADDRESS(void  CListWnd::RemoveLine(int),CListWnd__RemoveLine);
#endif
#ifdef CListWnd__SetCurSel_x
FUNCTION_AT_ADDRESS(void  CListWnd::SetCurSel(int),CListWnd__SetCurSel);
#endif
#ifdef CListWnd__ToggleSel_x
FUNCTION_AT_ADDRESS(void  CListWnd::ToggleSel(int),CListWnd__ToggleSel);
#endif
#ifdef CListWnd__ExtendSel_x
FUNCTION_AT_ADDRESS(void  CListWnd::ExtendSel(int),CListWnd__ExtendSel);
#endif
#ifdef CListWnd__ClearAllSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ClearAllSel(void),CListWnd__ClearAllSel);
#endif
#ifdef CListWnd__ClearSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ClearSel(int),CListWnd__ClearSel);
#endif
#ifdef CListWnd__DrawColumnSeparators_x
FUNCTION_AT_ADDRESS(int CListWnd::DrawColumnSeparators(void)const,CListWnd__DrawColumnSeparators);
#endif
#ifdef CListWnd__SetColumnsSizable_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColumnsSizable(bool),CListWnd__SetColumnsSizable);
#endif
#ifdef CListWnd__GetItemWnd_x
FUNCTION_AT_ADDRESS(CXWnd *CListWnd::GetItemWnd(int Index, int SubItem) const,CListWnd__GetItemWnd);
#endif
#ifdef CListWnd__SetItemIcon_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemIcon(int Index, int SubItem, const CTextureAnimation *pTA),CListWnd__SetItemIcon);
#endif
#ifdef CListWnd__CalculateCustomWindowPositions_x
FUNCTION_AT_ADDRESS(void CListWnd::CalculateCustomWindowPositions(),CListWnd__CalculateCustomWindowPositions);
#endif
#ifdef CListWnd__SetItemWnd_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemWnd(int Index, int SubItem, CXWnd *pWnd),CListWnd__SetItemWnd);
#endif
#ifdef CListWnd__SetItemData_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void  CListWnd::SetItemData(int,unsigned __int32,BOOL),CListWnd__SetItemData);
#else
FUNCTION_AT_ADDRESS(void  CListWnd::SetItemData(int,unsigned __int32),CListWnd__SetItemData);
#endif
#endif
#ifdef CListWnd__SetItemText_x
FUNCTION_AT_ADDRESS(void  CListWnd::SetItemText(int,int,class CXStr *),CListWnd__SetItemText);
#endif
#ifdef CListWnd__SetItemColor_x
FUNCTION_AT_ADDRESS(void  CListWnd::SetItemColor(int,int,unsigned long),CListWnd__SetItemColor);
#endif
#ifdef CListWnd__IsLineEnabled_x
FUNCTION_AT_ADDRESS(bool  CListWnd::IsLineEnabled(int)const ,CListWnd__IsLineEnabled);
#endif
#ifdef CListWnd__EnableLine_x
FUNCTION_AT_ADDRESS(void CListWnd::EnableLine(int,bool),CListWnd__EnableLine);
#endif
#ifdef CListWnd__AddColumn_x
FUNCTION_AT_ADDRESS(int CListWnd::AddColumn(const CXStr *, int, unsigned __int32, unsigned __int32),CListWnd__AddColumn);
#endif
#ifdef CListWnd__AddColumn1_x
FUNCTION_AT_ADDRESS(int CListWnd::AddColumn(const CXStr *Label, CTextureAnimation*pTA, int Width,unsigned __int32 Flags, CXStr Tooltip, unsigned __int32 Type, CTextureAnimation *pTASelected, CTextureAnimation *pTAMouseOver, bool bResizeable, tagSIZE TextureSize, tagPOINT TextureOffset),CListWnd__AddColumn1);
#endif
#ifdef SLinkInfo__dSLinkInfo_x
//FUNCTION_AT_ADDRESS( SLinkInfo::~SLinkInfo(void),SLinkInfo__dSLinkInfo);
#endif
#ifdef SListWndCellEditUpdate__dSListWndCellEditUpdate_x
FUNCTION_AT_ADDRESS( SListWndCellEditUpdate::~SListWndCellEditUpdate(void),SListWndCellEditUpdate__dSListWndCellEditUpdate);
#endif
#ifdef CListWnd__SetColumnLabel_x
FUNCTION_AT_ADDRESS(void  CListWnd::SetColumnLabel(int,class CXStr),CListWnd__SetColumnLabel);
#endif
#ifdef CXRect__CXRect1_x
FUNCTION_AT_ADDRESS( CXRect::CXRect(void),CXRect__CXRect1);
#endif
#ifdef CListWnd__GetItemHeight_x
FUNCTION_AT_ADDRESS(int  CListWnd::GetItemHeight(int)const ,CListWnd__GetItemHeight);
#endif
#ifdef CListWnd__CalculateLineHeights_x
FUNCTION_AT_ADDRESS(void  CListWnd::CalculateLineHeights(void),CListWnd__CalculateLineHeights);
#endif
#ifdef CListWnd__CalculateVSBRange_x
FUNCTION_AT_ADDRESS(void  CListWnd::CalculateVSBRange(void),CListWnd__CalculateVSBRange);
#endif
#ifdef CListWnd__CalculateFirstVisibleLine_x
FUNCTION_AT_ADDRESS(void  CListWnd::CalculateFirstVisibleLine(void),CListWnd__CalculateFirstVisibleLine);
#endif
#ifdef CListWnd__EnsureVisible_x
FUNCTION_AT_ADDRESS(void  CListWnd::EnsureVisible(int),CListWnd__EnsureVisible);
#endif
#ifdef CListWnd__GetItemRect_x
FUNCTION_AT_ADDRESS(class CXRect  CListWnd::GetItemRect(int,int)const ,CListWnd__GetItemRect);
#endif
#ifdef CListWnd__GetItemAtPoint_x
FUNCTION_AT_ADDRESS(int CListWnd::GetItemAtPoint(POINT *)const ,CListWnd__GetItemAtPoint);
#endif
#ifdef CListWnd__GetItemAtPoint1_x
FUNCTION_AT_ADDRESS(void  CListWnd::GetItemAtPoint(CXPoint *,int *,int *)const ,CListWnd__GetItemAtPoint1);
#endif
#ifdef CListWnd__CloseAndUpdateEditWindow_x
FUNCTION_AT_ADDRESS(void  CListWnd::CloseAndUpdateEditWindow(void),CListWnd__CloseAndUpdateEditWindow);
#endif
#ifdef CListWnd__SetColors_x
FUNCTION_AT_ADDRESS(void  CListWnd::SetColors(unsigned long,unsigned long,unsigned long),CListWnd__SetColors);
#endif
#ifdef CListWnd__GetSeparatorRect_x
FUNCTION_AT_ADDRESS(class CXRect  CListWnd::GetSeparatorRect(int)const ,CListWnd__GetSeparatorRect);
#endif
#ifdef SListWndSortInfo__dSListWndSortInfo_x
FUNCTION_AT_ADDRESS( SListWndSortInfo::~SListWndSortInfo(void),SListWndSortInfo__dSListWndSortInfo);
#endif
#ifdef CListWnd__GetHeaderRect_x
FUNCTION_AT_ADDRESS(class CXRect  CListWnd::GetHeaderRect(int)const ,CListWnd__GetHeaderRect);
#endif
#ifdef CScreenPieceTemplate__CScreenPieceTemplate_x
FUNCTION_AT_ADDRESS( CScreenPieceTemplate::CScreenPieceTemplate(class CParamScreenPiece *),CScreenPieceTemplate__CScreenPieceTemplate);
#endif
#ifdef CScreenPieceTemplate__IsType_x
FUNCTION_AT_ADDRESS(bool CScreenPieceTemplate::IsType(unsigned __int32)const ,CScreenPieceTemplate__IsType);
#endif
#ifdef CStaticScreenPieceTemplate__CStaticScreenPieceTemplate_x
FUNCTION_AT_ADDRESS( CStaticScreenPieceTemplate::CStaticScreenPieceTemplate(class CParamStaticScreenPiece *),CStaticScreenPieceTemplate__CStaticScreenPieceTemplate);
#endif
#ifdef CStaticAnimationTemplate__CStaticAnimationTemplate_x
FUNCTION_AT_ADDRESS( CStaticAnimationTemplate::CStaticAnimationTemplate(class CParamStaticAnimation *),CStaticAnimationTemplate__CStaticAnimationTemplate);
#endif
#ifdef CStaticTextTemplate__CStaticTextTemplate_x
FUNCTION_AT_ADDRESS( CStaticTextTemplate::CStaticTextTemplate(class CParamStaticText *),CStaticTextTemplate__CStaticTextTemplate);
#endif
#ifdef CStaticTextTemplate__SetText_x
FUNCTION_AT_ADDRESS(class CXStr  CStaticTextTemplate::SetText(class CXStr),CStaticTextTemplate__SetText);
#endif
#ifdef CStaticFrameTemplate__CStaticFrameTemplate_x
FUNCTION_AT_ADDRESS( CStaticFrameTemplate::CStaticFrameTemplate(class CParamStaticFrame *),CStaticFrameTemplate__CStaticFrameTemplate);
#endif
#ifdef CStaticHeaderTemplate__CStaticHeaderTemplate_x
FUNCTION_AT_ADDRESS( CStaticHeaderTemplate::CStaticHeaderTemplate(class CParamStaticHeader *),CStaticHeaderTemplate__CStaticHeaderTemplate);
#endif
#ifdef CControlTemplate__CControlTemplate_x
FUNCTION_AT_ADDRESS( CControlTemplate::CControlTemplate(class CParamControl *),CControlTemplate__CControlTemplate);
#endif
#ifdef CListboxColumnTemplate__CListboxColumnTemplate_x
FUNCTION_AT_ADDRESS( CListboxColumnTemplate::CListboxColumnTemplate(class CParamListboxColumn *),CListboxColumnTemplate__CListboxColumnTemplate);
#endif
#ifdef CListboxTemplate__CListboxTemplate_x
FUNCTION_AT_ADDRESS( CListboxTemplate::CListboxTemplate(class CParamListbox *),CListboxTemplate__CListboxTemplate);
#endif
#ifdef CListboxColumnTemplate__dCListboxColumnTemplate_x
FUNCTION_AT_ADDRESS( CListboxColumnTemplate::~CListboxColumnTemplate(void),CListboxColumnTemplate__dCListboxColumnTemplate);
#endif
#ifdef CButtonTemplate__CButtonTemplate_x
FUNCTION_AT_ADDRESS( CButtonTemplate::CButtonTemplate(class CParamButton *),CButtonTemplate__CButtonTemplate);
#endif
#ifdef CGaugeTemplate__CGaugeTemplate_x
FUNCTION_AT_ADDRESS( CGaugeTemplate::CGaugeTemplate(class CParamGauge *),CGaugeTemplate__CGaugeTemplate);
#endif
#ifdef CSpellGemTemplate__CSpellGemTemplate_x
FUNCTION_AT_ADDRESS( CSpellGemTemplate::CSpellGemTemplate(class CParamSpellGem *),CSpellGemTemplate__CSpellGemTemplate);
#endif
#ifdef CInvSlotTemplate__CInvSlotTemplate_x
FUNCTION_AT_ADDRESS( CInvSlotTemplate::CInvSlotTemplate(class CParamInvSlot *),CInvSlotTemplate__CInvSlotTemplate);
#endif
#ifdef CEditboxTemplate__CEditboxTemplate_x
FUNCTION_AT_ADDRESS( CEditboxTemplate::CEditboxTemplate(class CParamEditbox *),CEditboxTemplate__CEditboxTemplate);
#endif
#ifdef CSliderTemplate__CSliderTemplate_x
FUNCTION_AT_ADDRESS( CSliderTemplate::CSliderTemplate(class CParamSlider *),CSliderTemplate__CSliderTemplate);
#endif
#ifdef CLabelTemplate__CLabelTemplate_x
FUNCTION_AT_ADDRESS( CLabelTemplate::CLabelTemplate(class CParamLabel *),CLabelTemplate__CLabelTemplate);
#endif
#ifdef CLargeDialogWnd__Open_x
FUNCTION_AT_ADDRESS(void CLargeDialogWnd::Open(bool bYesNoEnabled, class CXStr DialogText, unsigned long closeTimer/*0 means never*/, CXStr DialogTitle, bool bShowVolumeControls, class CXStr YesText, class CXStr NoText),CLargeDialogWnd__Open);
#endif
#ifdef CWndDisplayManager__FindWindowA_x
FUNCTION_AT_ADDRESS(int CWndDisplayManager::FindWindowA(bool bNewWnd),CWndDisplayManager__FindWindowA);
#endif
#ifdef CItemDisplayManager__CreateWindowInstance_x
FUNCTION_AT_ADDRESS(int CItemDisplayManager::CreateWindowInstance(void),CItemDisplayManager__CreateWindowInstance);
#endif
#ifdef CSTMLboxTemplate__CSTMLboxTemplate_x
FUNCTION_AT_ADDRESS( CSTMLboxTemplate::CSTMLboxTemplate(class CParamSTMLbox *),CSTMLboxTemplate__CSTMLboxTemplate);
#endif
#ifdef CComboboxTemplate__CComboboxTemplate_x
FUNCTION_AT_ADDRESS( CComboboxTemplate::CComboboxTemplate(class CParamCombobox *),CComboboxTemplate__CComboboxTemplate);
#endif
#ifdef CPageTemplate__CPageTemplate_x
FUNCTION_AT_ADDRESS( CPageTemplate::CPageTemplate(class CParamPage *),CPageTemplate__CPageTemplate);
#endif
#ifdef CTabBoxTemplate__CTabBoxTemplate_x
FUNCTION_AT_ADDRESS( CTabBoxTemplate::CTabBoxTemplate(class CParamTabBox *),CTabBoxTemplate__CTabBoxTemplate);
#endif
#ifdef CScreenTemplate__CScreenTemplate_x
FUNCTION_AT_ADDRESS( CScreenTemplate::CScreenTemplate(class CParamScreen *),CScreenTemplate__CScreenTemplate);
#endif
#ifdef CStmlWnd__CStmlWnd_x
FUNCTION_AT_ADDRESS( CStmlWnd::CStmlWnd(class CXWnd *,unsigned __int32,class CXRect),CStmlWnd__CStmlWnd);
#endif
#ifdef CStmlWnd__InitializeTextLine_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::InitializeTextLine(class SParseVariables *,int),CStmlWnd__InitializeTextLine);
#endif
#ifdef CStmlWnd__AddTextPieceToLine_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::AddTextPieceToLine(class SParseVariables *),CStmlWnd__AddTextPieceToLine);
#endif
#ifdef CStmlWnd__MakeStmlColorTag_x
FUNCTION_AT_ADDRESS(class CXStr __cdecl CStmlWnd::MakeStmlColorTag(unsigned long),CStmlWnd__MakeStmlColorTag);
#endif
#ifdef CTextureAnimation__GetName_x
FUNCTION_AT_ADDRESS(class CXStr  CTextureAnimation::GetName(void)const ,CTextureAnimation__GetName);
#endif
#ifdef CStmlWnd__MakeWndNotificationTag_x
FUNCTION_AT_ADDRESS(class CXStr __cdecl CStmlWnd::MakeWndNotificationTag(unsigned __int32,class CXStr&,class CXStr&),CStmlWnd__MakeWndNotificationTag);
#endif
#ifdef CStmlWnd__ParseTagColor_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseTagColor(class CXStr,unsigned long *)const ,CStmlWnd__ParseTagColor);
#endif
#ifdef CStmlWnd__ParseTagFace_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseTagFace(class CXStr,class CTextureFont const * *)const ,CStmlWnd__ParseTagFace);
#endif
#ifdef CStmlWnd__ParseTagAlign_x
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseTagAlign(class CXStr,enum ESTMLAlign *)const ,CStmlWnd__ParseTagAlign);
#endif
#ifdef SAmpersandEntry__SAmpersandEntry_x
FUNCTION_AT_ADDRESS( SAmpersandEntry::SAmpersandEntry(class CXStr,char),SAmpersandEntry__SAmpersandEntry);
#endif
#ifdef CButtonDrawTemplate__dCButtonDrawTemplate_x
FUNCTION_AT_ADDRESS( CButtonDrawTemplate::~CButtonDrawTemplate(void),CButtonDrawTemplate__dCButtonDrawTemplate);
#endif
#ifdef CGaugeDrawTemplate__dCGaugeDrawTemplate_x
FUNCTION_AT_ADDRESS( CGaugeDrawTemplate::~CGaugeDrawTemplate(void),CGaugeDrawTemplate__dCGaugeDrawTemplate);
#endif
#ifdef CSpellGemDrawTemplate__dCSpellGemDrawTemplate_x
FUNCTION_AT_ADDRESS( CSpellGemDrawTemplate::~CSpellGemDrawTemplate(void),CSpellGemDrawTemplate__dCSpellGemDrawTemplate);
#endif
#ifdef CTAFrameDraw__dCTAFrameDraw_x
FUNCTION_AT_ADDRESS( CTAFrameDraw::~CTAFrameDraw(void),CTAFrameDraw__dCTAFrameDraw);
#endif
#ifdef SAmpersandEntry__dSAmpersandEntry_x
FUNCTION_AT_ADDRESS( SAmpersandEntry::~SAmpersandEntry(void),SAmpersandEntry__dSAmpersandEntry);
#endif
#ifdef STempTableCell__dSTempTableCell_x
FUNCTION_AT_ADDRESS( STempTableCell::~STempTableCell(void),STempTableCell__dSTempTableCell);
#endif
#ifdef CXStr__Blank_x
FUNCTION_AT_ADDRESS(void  CXStr::Blank(void),CXStr__Blank);
#endif
#ifdef CStmlWnd__ParseAmpersand_x
FUNCTION_AT_ADDRESS(bool  CStmlWnd::ParseAmpersand(class CXStr&,char *)const ,CStmlWnd__ParseAmpersand);
#endif
#ifdef CStmlWnd__ParseLinkTarget_x
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseLinkTarget(class CXStr,enum ESTMLTargetValue *)const ,CStmlWnd__ParseLinkTarget);
#endif
#ifdef CStmlWnd__FastForwardPastSpaces_x
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::FastForwardPastSpaces(class CXStr&,int *),CStmlWnd__FastForwardPastSpaces);
#endif
#ifdef CStmlWnd__FastForwardPastSpacesAndQuotes_x
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::FastForwardPastSpacesAndQuotes(class CXStr&,int *),CStmlWnd__FastForwardPastSpacesAndQuotes);
#endif
#ifdef CStmlWnd__GetNextTagPiece_x
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::GetNextTagPiece(class CXStr&,class CXStr *,int *,bool (__cdecl*)(unsigned short),bool),CStmlWnd__GetNextTagPiece);
#endif
#ifdef CStmlWnd__IsCharacterNotQuotes_x
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::IsCharacterNotQuotes(unsigned short),CStmlWnd__IsCharacterNotQuotes);
#endif
#ifdef CStmlWnd__FastForwardPastQuotesAndGetNextTagPiece_x
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::FastForwardPastQuotesAndGetNextTagPiece(class CXStr&,class CXStr *,int *,bool),CStmlWnd__FastForwardPastQuotesAndGetNextTagPiece);
#endif
#ifdef CStmlWnd__FastForwardToEndOfTag_x
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::FastForwardToEndOfTag(class CXStr&,class CXStr *,int *,char),CStmlWnd__FastForwardToEndOfTag);
#endif
#ifdef CStmlWnd__InitializeTempVariables_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::InitializeTempVariables(class SParseVariables *,class CXRect),CStmlWnd__InitializeTempVariables);
#endif
#ifdef CStmlWnd__InitializeWindowVariables_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::InitializeWindowVariables(void),CStmlWnd__InitializeWindowVariables);
#endif
#ifdef CStmlWnd__ResetTempVariablesForNewLine_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::ResetTempVariablesForNewLine(class SParseVariables *),CStmlWnd__ResetTempVariablesForNewLine);
#endif
#ifdef CStmlWnd__GetNextChar_x
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::GetNextChar(int *,class CXStr&),CStmlWnd__GetNextChar);
#endif
#ifdef CStmlWnd__GetThisChar_x
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::GetThisChar(int,class CXStr&),CStmlWnd__GetThisChar);
#endif
#ifdef CStmlWnd__IsCharacterNotEquals_x
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::IsCharacterNotEquals(unsigned short),CStmlWnd__IsCharacterNotEquals);
#endif
#ifdef CStmlWnd__IsCharacterNotASpaceAndNotNULL_x
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::IsCharacterNotASpaceAndNotNULL(unsigned short),CStmlWnd__IsCharacterNotASpaceAndNotNULL);
#endif
#ifdef SParseVariables__dSParseVariables_x
FUNCTION_AT_ADDRESS( SParseVariables::~SParseVariables(void),SParseVariables__dSParseVariables);
#endif
#ifdef SFormattedText__dSFormattedText_x
FUNCTION_AT_ADDRESS( SFormattedText::~SFormattedText(void),SFormattedText__dSFormattedText);
#endif
#ifdef CStmlWnd__ParseSTMLHead_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseSTMLHead(class CXStr&),CStmlWnd__ParseSTMLHead);
#endif
#ifdef CStmlWnd__ParseSTMLTable_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseSTMLTable(class CXStr&,int *,class CXStr&,class SParseVariables *),CStmlWnd__ParseSTMLTable);
#endif
#ifdef STempTable__dSTempTable_x
FUNCTION_AT_ADDRESS( STempTable::~STempTable(void),STempTable__dSTempTable);
#endif
#ifdef STable__STable_x
FUNCTION_AT_ADDRESS( STable::STable(void),STable__STable);
#endif
#ifdef STable__dSTable_x
FUNCTION_AT_ADDRESS( STable::~STable(void),STable__dSTable);
#endif
#ifdef STableCell__dSTableCell_x
FUNCTION_AT_ADDRESS( STableCell::~STableCell(void),STableCell__dSTableCell);
#endif
#ifdef CStmlWnd__ParseSTMLTableAttributes_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseSTMLTableAttributes(class CXStr,class STable *),CStmlWnd__ParseSTMLTableAttributes);
#endif
#ifdef CStmlWnd__GetVisibleText_x
FUNCTION_AT_ADDRESS(class CXStr  CStmlWnd::GetVisibleText(class CXStr&,class CXRect)const ,CStmlWnd__GetVisibleText);
#endif
#ifdef CStmlWnd__ForceParseNow_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::ForceParseNow(void),CStmlWnd__ForceParseNow);
#endif
#ifdef CStmlWnd__CalculateVSBRange_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::CalculateVSBRange(int),CStmlWnd__CalculateVSBRange);
#endif
#ifdef CStmlWnd__CalculateHSBRange_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::CalculateHSBRange(int),CStmlWnd__CalculateHSBRange);
#endif
#ifdef CStmlReport__GetReport_x
FUNCTION_AT_ADDRESS(class CXStr  CStmlReport::GetReport(void)const ,CStmlReport__GetReport);
#endif
#ifdef CStmlWnd__CompleteParse_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::CompleteParse(void),CStmlWnd__CompleteParse);
#endif
#ifdef CStmlWnd__StripFirstSTMLLines_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::StripFirstSTMLLines(int),CStmlWnd__StripFirstSTMLLines);
#endif
#ifdef CStmlWnd__ActivateLink_x
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ActivateLink(SLinkInfo),CStmlWnd__ActivateLink);
#endif
#ifdef SLinkInfo__SLinkInfo_x
//FUNCTION_AT_ADDRESS( SLinkInfo::SLinkInfo(SLinkInfo const &),SLinkInfo__SLinkInfo);
#endif
#ifdef CStmlWnd__CanBreakAtCharacter_x
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::CanBreakAtCharacter(unsigned short),CStmlWnd__CanBreakAtCharacter);
#endif
#ifdef CStmlWnd__ActivateLinkFile_x
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ActivateLinkFile(class SLinkInfo),CStmlWnd__ActivateLinkFile);
#endif
#ifdef CStmlWnd__ActivateLinkMessageId_x
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ActivateLinkMessageId(class SLinkInfo),CStmlWnd__ActivateLinkMessageId);
#endif
#ifdef CStmlWnd__ActivateLinkReport_x
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ActivateLinkReport(class SLinkInfo,bool),CStmlWnd__ActivateLinkReport);
#endif
#ifdef CStmlWnd__ActivateLinkWndNotify_x
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ActivateLinkWndNotify(class SLinkInfo),CStmlWnd__ActivateLinkWndNotify);
#endif
#ifdef CStmlWnd__LoadPage_x
//FUNCTION_AT_ADDRESS(void  CStmlWnd::LoadPage(class CXStr,enum ESTMLTargetValue,bool),CStmlWnd__LoadPage);
#endif
#ifdef CStmlWnd__AddLinkToHistory_x
//FUNCTION_AT_ADDRESS(void  CStmlWnd::AddLinkToHistory(class SLinkInfo,class CXStr),CStmlWnd__AddLinkToHistory);
#endif
#ifdef SLinkInfo__operator_equal_x
//FUNCTION_AT_ADDRESS(class SLinkInfo &  SLinkInfo::operator=(class SLinkInfo const &),SLinkInfo__operator_equal);
#endif
#ifdef CStmlWnd__UpdateHistoryString_x
FUNCTION_AT_ADDRESS(void CStmlWnd::UpdateHistoryString(__int32, CXStr&),CStmlWnd__UpdateHistoryString);
#endif
#ifdef CStmlWnd__SetSTMLText_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::SetSTMLText( CXStr,bool,SLinkInfo *),CStmlWnd__SetSTMLText);
#endif
#ifdef SLinkInfo__SLinkInfo1_x
//FUNCTION_AT_ADDRESS( SLinkInfo::SLinkInfo(void),SLinkInfo__SLinkInfo1);
#endif
#ifdef CStmlWnd__SetSTMLTextWithoutHistory_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::SetSTMLTextWithoutHistory(class CXStr),CStmlWnd__SetSTMLTextWithoutHistory);
#endif
#ifdef CStmlWnd__GoToBackHistoryLink_x
FUNCTION_AT_ADDRESS(void  CStmlWnd::GoToBackHistoryLink(void),CStmlWnd__GoToBackHistoryLink);
#endif
#ifdef CStmlWnd__CanGoBackward_x
FUNCTION_AT_ADDRESS(bool  CStmlWnd::CanGoBackward(void),CStmlWnd__CanGoBackward);
#endif
#ifdef CStmlWnd__IsLinkActive_x
//FUNCTION_AT_ADDRESS(bool  CStmlWnd::IsLinkActive(class SLinkInfo)const,CStmlWnd__IsLinkActive);
#endif
#ifdef CXStr__GetLength_x
FUNCTION_AT_ADDRESS(long  CXStr::GetLength(void)const ,CXStr__GetLength);
#endif
#ifdef STextLine__STextLine_x
FUNCTION_AT_ADDRESS( STextLine::STextLine(void),STextLine__STextLine);
#endif
#ifdef STextLine__dSTextLine_x
FUNCTION_AT_ADDRESS( STextLine::~STextLine(void),STextLine__dSTextLine);
#endif
#ifdef STempTableCell__STempTableCell_x
FUNCTION_AT_ADDRESS( STempTableCell::STempTableCell(void),STempTableCell__STempTableCell);
#endif
#ifdef STempTableRow__STempTableRow_x
FUNCTION_AT_ADDRESS( STempTableRow::STempTableRow(void),STempTableRow__STempTableRow);
#endif
#ifdef STempTableRow__dSTempTableRow_x
FUNCTION_AT_ADDRESS( STempTableRow::~STempTableRow(void),STempTableRow__dSTempTableRow);
#endif
#ifdef STextLine__operator_equal_x
FUNCTION_AT_ADDRESS(class STextLine &  STextLine::operator=(class STextLine const &),STextLine__operator_equal);
#endif
#ifdef SHistoryElement__SHistoryElement_x
FUNCTION_AT_ADDRESS( SHistoryElement::SHistoryElement(void),SHistoryElement__SHistoryElement);
#endif
#ifdef SHistoryElement__dSHistoryElement_x
FUNCTION_AT_ADDRESS( SHistoryElement::~SHistoryElement(void),SHistoryElement__dSHistoryElement);
#endif
#ifdef SFormattedText__SFormattedText_x
FUNCTION_AT_ADDRESS( SFormattedText::SFormattedText(void),SFormattedText__SFormattedText);
#endif
#ifdef STable__operator_equal_x
FUNCTION_AT_ADDRESS(class STable &  STable::operator=(class STable const &),STable__operator_equal);
#endif
#ifdef STableCell__STableCell_x
FUNCTION_AT_ADDRESS( STableCell::STableCell(void),STableCell__STableCell);
#endif
#ifdef CTabWnd__CTabWnd_x
FUNCTION_AT_ADDRESS( CTabWnd::CTabWnd(CXWnd *pParent, UINT uId, RECT *rect, CTabBoxTemplate *pTabContents),CTabWnd__CTabWnd);
#endif
#ifdef CTabWnd__GetNumTabs_x
FUNCTION_AT_ADDRESS(int  CTabWnd::GetNumTabs(void)const ,CTabWnd__GetNumTabs);
#endif
#ifdef CTabWnd__GetCurrentPage_x
FUNCTION_AT_ADDRESS(class CPageWnd *  CTabWnd::GetCurrentPage(void)const ,CTabWnd__GetCurrentPage);
#endif
#ifdef CTabWnd__GetTabRect_x
FUNCTION_AT_ADDRESS(class CXRect  CTabWnd::GetTabRect(int)const ,CTabWnd__GetTabRect);
#endif
#ifdef CTabWnd__GetTabInnerRect_x
FUNCTION_AT_ADDRESS(class CXRect  CTabWnd::GetTabInnerRect(int)const ,CTabWnd__GetTabInnerRect);
#endif
#ifdef CTabWnd__GetPageClientRect_x
FUNCTION_AT_ADDRESS(class CXRect  CTabWnd::GetPageClientRect(void)const ,CTabWnd__GetPageClientRect);
#endif
#ifdef CTabWnd__GetPageInnerRect_x
FUNCTION_AT_ADDRESS(class CXRect  CTabWnd::GetPageInnerRect(void)const ,CTabWnd__GetPageInnerRect);
#endif
#ifdef CTabWnd__SetPage_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void  CTabWnd::SetPage(int,bool,bool),CTabWnd__SetPage);
#else
FUNCTION_AT_ADDRESS(void  CTabWnd::SetPage(int,bool),CTabWnd__SetPage);
#endif
#endif
#ifdef CTabWnd__SetPage1_x
FUNCTION_AT_ADDRESS(void  CTabWnd::SetPage(class CPageWnd *,bool),CTabWnd__SetPage1);
#endif
#ifdef CTabWnd__InsertPage_x
FUNCTION_AT_ADDRESS(void  CTabWnd::InsertPage(class CPageWnd *,int),CTabWnd__InsertPage);
#endif
#ifdef CTabWnd__SetPageRect_x
FUNCTION_AT_ADDRESS(void  CTabWnd::SetPageRect(class CXRect),CTabWnd__SetPageRect);
#endif
#ifdef CXWnd__Tile_x
FUNCTION_AT_ADDRESS(int  CXWnd::Tile(bool),CXWnd__Tile);
#endif
#ifdef CTabWnd__UpdatePage_x
FUNCTION_AT_ADDRESS(void CTabWnd::UpdatePage(void),CTabWnd__UpdatePage);
#endif
#ifdef CTabWnd__GetPageFromTabIndex_x
FUNCTION_AT_ADDRESS(CPageWnd *CTabWnd::GetPageFromTabIndex(int)const,CTabWnd__GetPageFromTabIndex);
#endif
#ifdef CTabWnd__GetCurrentTabIndex_x
FUNCTION_AT_ADDRESS(int CTabWnd::GetCurrentTabIndex(void)const,CTabWnd__GetCurrentTabIndex);
#endif
#ifdef CTabWnd__IndexInBounds_x
FUNCTION_AT_ADDRESS(bool  CTabWnd::IndexInBounds(int)const ,CTabWnd__IndexInBounds);
#endif
#ifdef CTabWnd__GetPageFromTabPoint_x
FUNCTION_AT_ADDRESS(class CPageWnd *  CTabWnd::GetPageFromTabPoint(class CXPoint)const ,CTabWnd__GetPageFromTabPoint);
#endif
#ifdef CTabWnd__DrawTab_x
FUNCTION_AT_ADDRESS(int  CTabWnd::DrawTab(int)const ,CTabWnd__DrawTab);
#endif
#ifdef CTabWnd__DrawCurrentPage_x
FUNCTION_AT_ADDRESS(int  CTabWnd::DrawCurrentPage(void)const ,CTabWnd__DrawCurrentPage);
#endif
#ifdef CPageWnd__GetTabText_x
FUNCTION_AT_ADDRESS(class CXStr  CPageWnd::GetTabText(void)const ,CPageWnd__GetTabText);
#endif
#ifdef CPageWnd__SetTabText_x
FUNCTION_AT_ADDRESS(void CPageWnd::SetTabText(CXStr &)const,CPageWnd__SetTabText);
#endif
#ifdef CWebManager__CreateHtmlWnd_x
FUNCTION_AT_ADDRESS(CHtmlWnd* CWebManager::CreateHtmlWnd(const char*, const char*, const char*, bool, const char*),CWebManager__CreateHtmlWnd);
#endif
#ifdef CHtmlWnd__SetClientCallbacks_x
FUNCTION_AT_ADDRESS(void CHtmlWnd::SetClientCallbacks(void*),CHtmlWnd__SetClientCallbacks);
#endif
#ifdef CHtmlWnd__AddObserver_x
FUNCTION_AT_ADDRESS(void CHtmlWnd::AddObserver(IObserver *),CHtmlWnd__AddObserver);
#endif
#ifdef CHtmlWnd__RemoveObserver_x
FUNCTION_AT_ADDRESS(void CHtmlWnd::RemoveObserver(IObserver *),CHtmlWnd__RemoveObserver);
#endif
#ifdef Window__getProgress_x
FUNCTION_AT_ADDRESS(float Window::getProgress(bool &bIsLoading), Window__getProgress);
#endif
#ifdef Window__getStatus_x
FUNCTION_AT_ADDRESS(const wchar_t *Window::getStatus() const, Window__getStatus);
#endif
#ifdef Window__getURI_x
FUNCTION_AT_ADDRESS(const char *Window::getURI() const, Window__getURI);
#endif
#ifdef CXMLSOMDocumentBase__Init_x
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::Init(void),CXMLSOMDocumentBase__Init);
#endif
#ifdef CXMLSOMNodePtr__Assure_x
FUNCTION_AT_ADDRESS(void  CXMLSOMNodePtr::Assure(void)const ,CXMLSOMNodePtr__Assure);
#endif
#ifdef CXMLSOMDocumentBase__CursorInit_x
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::CursorInit(void),CXMLSOMDocumentBase__CursorInit);
#endif
#ifdef CXMLSOMNode__CXMLSOMNode_x
FUNCTION_AT_ADDRESS( CXMLSOMNode::CXMLSOMNode(void),CXMLSOMNode__CXMLSOMNode);
#endif
#ifdef CXMLSOMDocumentBase__Cursor_x
FUNCTION_AT_ADDRESS(class CXMLSOMCursor &  CXMLSOMDocumentBase::Cursor(void),CXMLSOMDocumentBase__Cursor);
#endif
#ifdef CXMLSOMDocumentBase__CursorParent_x
FUNCTION_AT_ADDRESS(class CXMLSOMCursor &  CXMLSOMDocumentBase::CursorParent(void),CXMLSOMDocumentBase__CursorParent);
#endif
#ifdef CXMLSOMDocumentBase__CursorNewChild_x
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::CursorNewChild(void),CXMLSOMDocumentBase__CursorNewChild);
#endif
#ifdef CXMLSOMDocumentBase__CursorNewSibling_x
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::CursorNewSibling(void),CXMLSOMDocumentBase__CursorNewSibling);
#endif
#ifdef CXMLSOMNodePtr__operator_equal_x
FUNCTION_AT_ADDRESS(class CXMLSOMNodePtr &  CXMLSOMNodePtr::operator=(class CXMLSOMNodePtr const &),CXMLSOMNodePtr__operator_equal);
#endif
#ifdef CXMLSOMDocumentBase__CursorSetPtr_x
//FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::CursorSetPtr(class CXMLSOMNodePtr),CXMLSOMDocumentBase__CursorSetPtr);
#endif
#ifdef CXMLSOMNodePtr__operator_minust__x
FUNCTION_AT_ADDRESS(class CXMLSOMNode *  CXMLSOMNodePtr::operator->(void)const ,CXMLSOMNodePtr__operator_minust_);
#endif
#ifdef CXMLSOMDocumentBase__CursorPush_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::CursorPush(void),CXMLSOMDocumentBase__CursorPush);
#endif
#ifdef CXMLSOMDocumentBase__CursorPop_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::CursorPop(void),CXMLSOMDocumentBase__CursorPop);
#endif
#ifdef CXMLSOMDocumentBase__CursorNextSibling_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::CursorNextSibling(void),CXMLSOMDocumentBase__CursorNextSibling);
#endif
#ifdef CXMLSOMDocumentBase__CursorNextInOrder_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::CursorNextInOrder(void),CXMLSOMDocumentBase__CursorNextInOrder);
#endif
#ifdef CXMLSOMDocumentBase__CursorFind_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::CursorFind(class CXStr),CXMLSOMDocumentBase__CursorFind);
#endif
#ifdef CXMLSOMDocumentBase__GetAttrValueStr_x
FUNCTION_AT_ADDRESS(class CXStr  CXMLSOMDocumentBase::GetAttrValueStr(class CXStr),CXMLSOMDocumentBase__GetAttrValueStr);
#endif
#ifdef CXMLSOMDocumentBase__GetAttrValueStr1_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::GetAttrValueStr(class CXStr,class CXStr &),CXMLSOMDocumentBase__GetAttrValueStr1);
#endif
#ifdef CXMLSOMDocumentBase__GetAttrValueInt_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::GetAttrValueInt(class CXStr,__int32 &),CXMLSOMDocumentBase__GetAttrValueInt);
#endif
#ifdef CXMLSOMCursorSave__dCXMLSOMCursorSave_x
FUNCTION_AT_ADDRESS( CXMLSOMCursorSave::~CXMLSOMCursorSave(void),CXMLSOMCursorSave__dCXMLSOMCursorSave);
#endif
#ifdef CXMLSOMDocumentBase__CursorFieldFind_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::CursorFieldFind(class CXStr),CXMLSOMDocumentBase__CursorFieldFind);
#endif
#ifdef CXMLSOMDocumentBase__GetValue_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::GetValue(class CXStr,class CXStr &),CXMLSOMDocumentBase__GetValue);
#endif
#ifdef CXMLSOMDocumentBase__GetValue1_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::GetValue(class CXStr,__int32 &),CXMLSOMDocumentBase__GetValue1);
#endif
#ifdef CXMLSOMDocumentBase__GetValue2_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::GetValue(class CXStr,bool &),CXMLSOMDocumentBase__GetValue2);
#endif
#ifdef CXMLSOMDocumentBase__FieldParseClassItem_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::FieldParseClassItem(class CXStr,class CXStr &,class CXStr &),CXMLSOMDocumentBase__FieldParseClassItem);
#endif
#ifdef CXMLSOMDocumentBase__FieldParseItemOfClass_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::FieldParseItemOfClass(class CXStr,class CXStr,__int32 &,__int32 &),CXMLSOMDocumentBase__FieldParseItemOfClass);
#endif
#ifdef CXMLSOMDocumentBase__SetValue_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::SetValue(class CXStr,class CXStr),CXMLSOMDocumentBase__SetValue);
#endif
#ifdef CXMLSOMDocumentBase__SetValue1_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::SetValue(class CXStr,__int32),CXMLSOMDocumentBase__SetValue1);
#endif
#ifdef CXMLSOMDocumentBase__SetValue2_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::SetValue(class CXStr,bool),CXMLSOMDocumentBase__SetValue2);
#endif
#ifdef CXMLSOMDocumentBase__XMLReadNoValidate_x
FUNCTION_AT_ADDRESS(int  CXMLSOMDocumentBase::XMLReadNoValidate(class CXStr,class CXStr,class CXStr),CXMLSOMDocumentBase__XMLReadNoValidate);
#endif
#ifdef CXMLSOMDocumentBase__XMLRead_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::XMLRead(class CXStr*,class CXStr*,class CXStr*),CXMLSOMDocumentBase__XMLRead);
#endif
#ifdef CXMLSOMDocumentBase__XMLProcessComposite_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::XMLProcessComposite(class CXStr,class CXStr),CXMLSOMDocumentBase__XMLProcessComposite);
#endif
#ifdef CXMLSOMDocumentBase__SetErrorMsg_x
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::SetErrorMsg(class CXStr),CXMLSOMDocumentBase__SetErrorMsg);
#endif
#ifdef CXMLSOMDocumentBase__GetErrorMsg_x
FUNCTION_AT_ADDRESS(class CXStr  CXMLSOMDocumentBase::GetErrorMsg(void)const ,CXMLSOMDocumentBase__GetErrorMsg);
#endif
#ifdef CXMLSOMSchema__CXMLSOMSchema_x
FUNCTION_AT_ADDRESS( CXMLSOMSchema::CXMLSOMSchema(void),CXMLSOMSchema__CXMLSOMSchema);
#endif
#ifdef CXMLSOMSchema__dCXMLSOMSchema_x
FUNCTION_AT_ADDRESS( CXMLSOMSchema::~CXMLSOMSchema(void),CXMLSOMSchema__dCXMLSOMSchema);
#endif
#ifdef CXMLSOMCursorTraverseChildren__dCXMLSOMCursorTraverseChildren_x
FUNCTION_AT_ADDRESS( CXMLSOMCursorTraverseChildren::~CXMLSOMCursorTraverseChildren(void),CXMLSOMCursorTraverseChildren__dCXMLSOMCursorTraverseChildren);
#endif
#ifdef CXMLSOMDocumentBase__XMLMerge_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::XMLMerge(class CXMLSOMDocumentBase &),CXMLSOMDocumentBase__XMLMerge);
#endif
#ifdef CXMLSOMCursorTraverseChildren__Cursor_x
FUNCTION_AT_ADDRESS(class CXMLSOMCursor &  CXMLSOMCursorTraverseChildren::Cursor(void),CXMLSOMCursorTraverseChildren__Cursor);
#endif
#ifdef CXMLSOMDocumentBase__SetErrorMsgAtLine_x
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::SetErrorMsgAtLine(class CXStr,int,class CXStr),CXMLSOMDocumentBase__SetErrorMsgAtLine);
#endif
#ifdef CXMLSOMDocumentBase__SetErrorMsgAtCursor_x
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::SetErrorMsgAtCursor(class CXStr),CXMLSOMDocumentBase__SetErrorMsgAtCursor);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaSimpleTypeNode_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchemaSimpleTypeNode(class CXMLSOMSimpleType &),CXMLSOMDocumentBase__ValidateSchemaSimpleTypeNode);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaElementType_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchemaElementType(void),CXMLSOMDocumentBase__ValidateSchemaElementType);
#endif
#ifdef CXMLSOMElementType__dCXMLSOMElementType_x
FUNCTION_AT_ADDRESS( CXMLSOMElementType::~CXMLSOMElementType(void),CXMLSOMElementType__dCXMLSOMElementType);
#endif
#ifdef CXMLSOMElement__dCXMLSOMElement_x
FUNCTION_AT_ADDRESS( CXMLSOMElement::~CXMLSOMElement(void),CXMLSOMElement__dCXMLSOMElement);
#endif
#ifdef CXMLSOMAttributeType__dCXMLSOMAttributeType_x
FUNCTION_AT_ADDRESS( CXMLSOMAttributeType::~CXMLSOMAttributeType(void),CXMLSOMAttributeType__dCXMLSOMAttributeType);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaSimpleType_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchemaSimpleType(void),CXMLSOMDocumentBase__ValidateSchemaSimpleType);
#endif
#ifdef CXMLSOMSimpleType__dCXMLSOMSimpleType_x
FUNCTION_AT_ADDRESS( CXMLSOMSimpleType::~CXMLSOMSimpleType(void),CXMLSOMSimpleType__dCXMLSOMSimpleType);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaDefinition_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchemaDefinition(void),CXMLSOMDocumentBase__ValidateSchemaDefinition);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaCategories_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchemaCategories(void),CXMLSOMDocumentBase__ValidateSchemaCategories);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaTypeRefs_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchemaTypeRefs(void),CXMLSOMDocumentBase__ValidateSchemaTypeRefs);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchema_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchema(void),CXMLSOMDocumentBase__ValidateSchema);
#endif
#ifdef CXMLSOMDocumentBase__ValidateDataElements_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateDataElements(class CXMLSOMElementType &),CXMLSOMDocumentBase__ValidateDataElements);
#endif
#ifdef CXMLSOMDocumentBase__ValidateData_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateData(void),CXMLSOMDocumentBase__ValidateData);
#endif
#ifdef CXMLSOMElementType__GetItemIdx_x
FUNCTION_AT_ADDRESS(int  CXMLSOMElementType::GetItemIdx(class CXStr),CXMLSOMElementType__GetItemIdx);
#endif
#ifdef CXMLSOMSchema__GetElementTypeIdx_x
FUNCTION_AT_ADDRESS(int  CXMLSOMSchema::GetElementTypeIdx(class CXStr),CXMLSOMSchema__GetElementTypeIdx);
#endif
#ifdef CXMLSOMSchema__IsDerivedFrom_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMSchema::IsDerivedFrom(class CXStr,class CXStr),CXMLSOMSchema__IsDerivedFrom);
#endif
#ifdef CXMLSOMSchema__FindElementType_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMSchema::FindElementType(class CXStr),CXMLSOMSchema__FindElementType);
#endif
#ifdef CXMLSOMSchema__FindSimpleType_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMSchema::FindSimpleType(class CXStr),CXMLSOMSchema__FindSimpleType);
#endif
#ifdef CXMLSOMSchema__FindItem_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMSchema::FindItem(class CXStr,class CXStr),CXMLSOMSchema__FindItem);
#endif
#ifdef CXMLSOMSchema__AddItem_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMSchema::AddItem(class CXStr,class CXStr),CXMLSOMSchema__AddItem);
#endif
#ifdef CXMLSOMNode__FreeAllAllocs_x
FUNCTION_AT_ADDRESS(void __cdecl CXMLSOMNode::FreeAllAllocs(void),CXMLSOMNode__FreeAllAllocs);
#endif
#ifdef CXMLSOMNode__operator_new_x
FUNCTION_AT_ADDRESS(void * __cdecl CXMLSOMNode::operator new(unsigned int),CXMLSOMNode__operator_new);
#endif
#ifdef CMutexLock__dCMutexLock_x
FUNCTION_AT_ADDRESS( CMutexLock::~CMutexLock(void),CMutexLock__dCMutexLock);
#endif
#ifdef CXMLSOMNode__operator_delete_x
FUNCTION_AT_ADDRESS(void __cdecl CXMLSOMNode::operator delete(void *),CXMLSOMNode__operator_delete);
#endif
#ifdef CKeyCXStrValueInt32__CKeyCXStrValueInt32_x
FUNCTION_AT_ADDRESS( CKeyCXStrValueInt32::CKeyCXStrValueInt32(void),CKeyCXStrValueInt32__CKeyCXStrValueInt32);
#endif
#ifdef CXMLSOMCursor__CXMLSOMCursor_x
FUNCTION_AT_ADDRESS( CXMLSOMCursor::CXMLSOMCursor(void),CXMLSOMCursor__CXMLSOMCursor);
#endif
#ifdef CXMLSOMNodePtr__CXMLSOMNodePtr_x
FUNCTION_AT_ADDRESS( CXMLSOMNodePtr::CXMLSOMNodePtr(void),CXMLSOMNodePtr__CXMLSOMNodePtr);
#endif
#ifdef CXMLSOMAttribute__operator_equal_x
FUNCTION_AT_ADDRESS(class CXMLSOMAttribute &  CXMLSOMAttribute::operator=(class CXMLSOMAttribute const &),CXMLSOMAttribute__operator_equal);
#endif
#ifdef CXMLSOMCursor__operator_equal_x
FUNCTION_AT_ADDRESS(class CXMLSOMCursor &  CXMLSOMCursor::operator=(class CXMLSOMCursor const &),CXMLSOMCursor__operator_equal);
#endif
#ifdef CXMLSOMAttribute__CXMLSOMAttribute_x
FUNCTION_AT_ADDRESS( CXMLSOMAttribute::CXMLSOMAttribute(void),CXMLSOMAttribute__CXMLSOMAttribute);
#endif
#ifdef CXMLSOMSimpleType__CXMLSOMSimpleType_x
FUNCTION_AT_ADDRESS( CXMLSOMSimpleType::CXMLSOMSimpleType(void),CXMLSOMSimpleType__CXMLSOMSimpleType);
#endif
#ifdef CXMLSOMElementType__CXMLSOMElementType_x
FUNCTION_AT_ADDRESS( CXMLSOMElementType::CXMLSOMElementType(void),CXMLSOMElementType__CXMLSOMElementType);
#endif
#ifdef CXMLSOMAttributeType__operator_equal_x
FUNCTION_AT_ADDRESS(class CXMLSOMAttributeType &  CXMLSOMAttributeType::operator=(class CXMLSOMAttributeType const &),CXMLSOMAttributeType__operator_equal);
#endif
#ifdef CXMLSOMElement__operator_equal_x
FUNCTION_AT_ADDRESS(class CXMLSOMElement &  CXMLSOMElement::operator=(class CXMLSOMElement const &),CXMLSOMElement__operator_equal);
#endif
#ifdef CXMLSOMAttributeType__CXMLSOMAttributeType_x
FUNCTION_AT_ADDRESS( CXMLSOMAttributeType::CXMLSOMAttributeType(void),CXMLSOMAttributeType__CXMLSOMAttributeType);
#endif
#ifdef CXMLSOMElement__CXMLSOMElement_x
FUNCTION_AT_ADDRESS( CXMLSOMElement::CXMLSOMElement(void),CXMLSOMElement__CXMLSOMElement);
#endif
#ifdef KeyCombo__KeyCombo_x
FUNCTION_AT_ADDRESS( KeyCombo::KeyCombo(void),KeyCombo__KeyCombo);
#endif
#ifdef KeyCombo__KeyCombo1_x
FUNCTION_AT_ADDRESS( KeyCombo::KeyCombo(unsigned char,bool,bool,bool),KeyCombo__KeyCombo1);
#endif
#ifdef KeyCombo__KeyCombo2_x
FUNCTION_AT_ADDRESS( KeyCombo::KeyCombo(int),KeyCombo__KeyCombo2);
#endif
#ifdef KeyCombo__KeyCombo3_x
FUNCTION_AT_ADDRESS( KeyCombo::KeyCombo(unsigned int,unsigned int,bool,bool,bool),KeyCombo__KeyCombo3);
#endif
#ifdef KeyCombo__GetKey_x
FUNCTION_AT_ADDRESS(unsigned int  KeyCombo::GetKey(void)const ,KeyCombo__GetKey);
#endif
#ifdef KeyCombo__UsesCtrl_x
FUNCTION_AT_ADDRESS(bool  KeyCombo::UsesCtrl(void)const ,KeyCombo__UsesCtrl);
#endif
#ifdef KeyCombo__UsesShift_x
FUNCTION_AT_ADDRESS(bool  KeyCombo::UsesShift(void)const ,KeyCombo__UsesShift);
#endif
#ifdef KeyCombo__UsesAlt_x
FUNCTION_AT_ADDRESS(bool  KeyCombo::UsesAlt(void)const ,KeyCombo__UsesAlt);
#endif
#ifdef KeyCombo__GetTextDescription_x
FUNCTION_AT_ADDRESS(class CXStr  KeyCombo::GetTextDescription(void)const ,KeyCombo__GetTextDescription);
#endif
#ifdef KeyCombo__GetPrintableLetter_x
FUNCTION_AT_ADDRESS(bool  KeyCombo::GetPrintableLetter(unsigned short *)const ,KeyCombo__GetPrintableLetter);
#endif
#ifdef KeyCombo__operator_equal_equal_x
FUNCTION_AT_ADDRESS(int  KeyCombo::operator==(class KeyCombo const &)const ,KeyCombo__operator_equal_equal);
#endif
#ifdef KeyCombo__operator_equal_x
FUNCTION_AT_ADDRESS(class KeyCombo const &  KeyCombo::operator=(int),KeyCombo__operator_equal);
#endif
#ifdef KeyCombo__operator_int_x
//FUNCTION_AT_ADDRESS( KeyCombo::operator int(void)const ,KeyCombo__operator_int);
#endif
#ifdef KeyCombo__GetVirtualKeyFromScanCode_x
FUNCTION_AT_ADDRESS(bool  KeyCombo::GetVirtualKeyFromScanCode(unsigned char,int *)const ,KeyCombo__GetVirtualKeyFromScanCode);
#endif
#ifdef KeyCombo__GetPrintableLetterFromScanCode_x
FUNCTION_AT_ADDRESS(bool  KeyCombo::GetPrintableLetterFromScanCode(unsigned char,bool,bool,unsigned short *)const ,KeyCombo__GetPrintableLetterFromScanCode);
#endif
#ifdef KeyCombo__GetScanCodeFromVirtualKey_x
FUNCTION_AT_ADDRESS(bool  KeyCombo::GetScanCodeFromVirtualKey(unsigned int,unsigned int,unsigned char *)const ,KeyCombo__GetScanCodeFromVirtualKey);
#endif
#ifdef KeyCombo__GetPrintableLetterFromVirtualKey_x
FUNCTION_AT_ADDRESS(bool  KeyCombo::GetPrintableLetterFromVirtualKey(unsigned int,unsigned int,bool,bool,unsigned short *)const ,KeyCombo__GetPrintableLetterFromVirtualKey);
#endif
//#ifdef CButtonWnd__CButtonWnd_x
//FUNCTION_AT_ADDRESS( CButtonWnd::CButtonWnd(class CXWnd *,unsigned __int32,class CXRect,class CXPoint,class CXSize,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *),CButtonWnd__CButtonWnd);
//#endif
#ifdef CXWnd__IsEnabled_x
FUNCTION_AT_ADDRESS(bool  CXWnd::IsEnabled(void)const ,CXWnd__IsEnabled);
#endif
#ifdef CButtonWnd__SetCheck_x
FUNCTION_AT_ADDRESS(void  CButtonWnd::SetCheck(bool),CButtonWnd__SetCheck);
#endif
#ifdef CComboWnd__CComboWnd_x
//FUNCTION_AT_ADDRESS( CComboWnd::CComboWnd(class CXWnd *,unsigned __int32,class CXRect,int,class CButtonDrawTemplate,class CListWnd *),CComboWnd__CComboWnd);
#endif
#ifdef CXWnd__GetWidth_x
FUNCTION_AT_ADDRESS(int  CXWnd::GetWidth(void)const ,CXWnd__GetWidth);
#endif
#ifdef CComboWnd__GetListRect_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(class CXRect  CComboWnd::GetListRect(bool)const ,CComboWnd__GetListRect);
#else
FUNCTION_AT_ADDRESS(class CXRect  CComboWnd::GetListRect(void)const ,CComboWnd__GetListRect);
#endif
#endif
#ifdef CComboWnd__SetColors_x
FUNCTION_AT_ADDRESS(void  CComboWnd::SetColors(unsigned long,unsigned long,unsigned long),CComboWnd__SetColors);
#endif
#ifdef CComboWnd__InsertChoice_x
FUNCTION_AT_ADDRESS(void  CComboWnd::InsertChoice(class CXStr *, unsigned long),CComboWnd__InsertChoice);
#endif
#ifdef CComboWnd__SetChoice_x
FUNCTION_AT_ADDRESS(void  CComboWnd::SetChoice(int),CComboWnd__SetChoice);
#endif
#ifdef CComboWnd__GetItemCount_x
FUNCTION_AT_ADDRESS(int  CComboWnd::GetItemCount(void),CComboWnd__GetItemCount);
#endif
#ifdef CComboWnd__GetCurChoice_x
FUNCTION_AT_ADDRESS(int  CComboWnd::GetCurChoice(void)const ,CComboWnd__GetCurChoice);
#endif
#ifdef CComboWnd__GetCurChoiceText_x
FUNCTION_AT_ADDRESS(class CXStr CComboWnd::GetCurChoiceText(void)const ,CComboWnd__GetCurChoiceText);
#endif
#ifdef CComboWnd__DeleteAll_x
FUNCTION_AT_ADDRESS(void  CComboWnd::DeleteAll(void),CComboWnd__DeleteAll);
#endif
#ifdef CComboWnd__GetButtonRect_x
FUNCTION_AT_ADDRESS(class CXRect  CComboWnd::GetButtonRect(void)const ,CComboWnd__GetButtonRect);
#endif
#ifdef CComboWnd__GetTextRect_x
FUNCTION_AT_ADDRESS(class CXRect  CComboWnd::GetTextRect(void)const ,CComboWnd__GetTextRect);
#endif
#ifdef CXWndManager__CXWndManager_x
FUNCTION_AT_ADDRESS( CXWndManager::CXWndManager(class CSidlManager *),CXWndManager__CXWndManager);
#endif
#ifdef CXWndManager__DestroyAllWindows_x
FUNCTION_AT_ADDRESS(void  CXWndManager::DestroyAllWindows(void),CXWndManager__DestroyAllWindows);
#endif
#ifdef CXWndManager__DrawWindows_x
FUNCTION_AT_ADDRESS(int  CXWndManager::DrawWindows(void)const ,CXWndManager__DrawWindows);
#endif
#ifdef CXWndManager__DrawCursor_x
FUNCTION_AT_ADDRESS(int  CXWndManager::DrawCursor(void)const ,CXWndManager__DrawCursor);
#endif
#ifdef CXWndManager__AddWnd_x
FUNCTION_AT_ADDRESS(int  CXWndManager::AddWnd(class CXWnd *),CXWndManager__AddWnd);
#endif
#ifdef CXWndManager__RemoveWnd_x
FUNCTION_AT_ADDRESS(int  CXWndManager::RemoveWnd(class CXWnd *),CXWndManager__RemoveWnd);
#endif
#ifdef CXWndManager__CheckInvalidateLastFoundWnd_x
FUNCTION_AT_ADDRESS(void  CXWndManager::CheckInvalidateLastFoundWnd(void),CXWndManager__CheckInvalidateLastFoundWnd);
#endif
#ifdef CXWndManager__GetKeyboardFlags_x
FUNCTION_AT_ADDRESS(unsigned __int32  CXWndManager::GetKeyboardFlags(void)const ,CXWndManager__GetKeyboardFlags);
#endif
#ifdef CXWndManager__FlushKeyboardFlags_x
FUNCTION_AT_ADDRESS(void  CXWndManager::FlushKeyboardFlags(void),CXWndManager__FlushKeyboardFlags);
#endif
#ifdef CXWndManager__UpdateChildAndSiblingInfo_x
FUNCTION_AT_ADDRESS(void  CXWndManager::UpdateChildAndSiblingInfo(void),CXWndManager__UpdateChildAndSiblingInfo);
#endif
#ifdef CXWndManager__HandleKeyboardMsg_x
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleKeyboardMsg(unsigned __int32,bool),CXWndManager__HandleKeyboardMsg);
#endif
#ifdef CXWndManager__OkayToSendMouseMessage_x
FUNCTION_AT_ADDRESS(bool  CXWndManager::OkayToSendMouseMessage(class CXWnd *)const,CXWndManager__OkayToSendMouseMessage);
#endif
#ifdef CXWndManager__HandleMouseMove_x
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleMouseMove(class CXPoint),CXWndManager__HandleMouseMove);
#endif
#ifdef CXWndManager__HandleWheelMove_x
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleWheelMove(int),CXWndManager__HandleWheelMove);
#endif
#ifdef CXWndManager__HandleLButtonDown_x
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleLButtonDown(class CXPoint),CXWndManager__HandleLButtonDown);
#endif
#ifdef CXWndManager__IsWindowPieceDown_x
FUNCTION_AT_ADDRESS(bool  CXWndManager::IsWindowPieceDown(class CXWnd const *,int)const ,CXWndManager__IsWindowPieceDown);
#endif
#ifdef CXWndManager__OnWindowCloseBox_x
FUNCTION_AT_ADDRESS(int  CXWndManager::OnWindowCloseBox(class CXWnd *),CXWndManager__OnWindowCloseBox);
#endif
#ifdef CXWndManager__OnWindowMinimizeBox_x
FUNCTION_AT_ADDRESS(int  CXWndManager::OnWindowMinimizeBox(class CXWnd *),CXWndManager__OnWindowMinimizeBox);
#endif
#ifdef CXWndManager__OnWindowTileBox_x
FUNCTION_AT_ADDRESS(int  CXWndManager::OnWindowTileBox(class CXWnd *),CXWndManager__OnWindowTileBox);
#endif
#ifdef CXWndManager__HandleLButtonHeld_x
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleLButtonHeld(class CXPoint),CXWndManager__HandleLButtonHeld);
#endif
#ifdef CXWndManager__HandleLButtonUpAfterHeld_x
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleLButtonUpAfterHeld(class CXPoint),CXWndManager__HandleLButtonUpAfterHeld);
#endif
#ifdef CXWndManager__HandleRButtonHeld_x
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleRButtonHeld(class CXPoint),CXWndManager__HandleRButtonHeld);
#endif
#ifdef CXWndManager__HandleRButtonUpAfterHeld_x
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleRButtonUpAfterHeld(class CXPoint),CXWndManager__HandleRButtonUpAfterHeld);
#endif
#ifdef CXWndManager__HandleLButtonUp_x
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleLButtonUp(class CXPoint),CXWndManager__HandleLButtonUp);
#endif
#ifdef CXWndManager__HandleRButtonDown_x
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleRButtonDown(class CXPoint),CXWndManager__HandleRButtonDown);
#endif
#ifdef CXWndManager__HandleRButtonUp_x
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleRButtonUp(class CXPoint),CXWndManager__HandleRButtonUp);
#endif
#ifdef CXWndManager__FindWnd_x
FUNCTION_AT_ADDRESS(class CXWnd *  CXWndManager::FindWnd(class CXPoint,int *)const,CXWndManager__FindWnd);
#endif
#ifdef CXWndManager__GetCursorToDisplay_x
FUNCTION_AT_ADDRESS(class CTextureAnimation const *  CXWndManager::GetCursorToDisplay(void)const ,CXWndManager__GetCursorToDisplay);
#endif
#ifdef CXWndManager__SetFocusWnd_x
FUNCTION_AT_ADDRESS(class CXWnd *  CXWndManager::SetFocusWnd(class CXWnd *),CXWndManager__SetFocusWnd);
#endif
#ifdef CXWndManager__GetFocusWnd_x
FUNCTION_AT_ADDRESS(class CXWnd *  CXWndManager::GetFocusWnd(void)const ,CXWndManager__GetFocusWnd);
#endif
#ifdef CXWndManager__ProcessFrame_x
FUNCTION_AT_ADDRESS(int  CXWndManager::ProcessFrame(void),CXWndManager__ProcessFrame);
#endif
#ifdef CXWndManager__OnWindowShown_x
FUNCTION_AT_ADDRESS(void  CXWndManager::OnWindowShown(class CXWnd *,bool),CXWndManager__OnWindowShown);
#endif
#ifdef CXWndManager__BringWndToTop_x
FUNCTION_AT_ADDRESS(void  CXWndManager::BringWndToTop(class CXWnd *,bool),CXWndManager__BringWndToTop);
#endif
#ifdef CXWndManager__NotifyAllWindows_x
FUNCTION_AT_ADDRESS(int  CXWndManager::NotifyAllWindows(class CXWnd *,unsigned __int32,void *),CXWndManager__NotifyAllWindows);
#endif
#ifdef CXWndManager__CleanupWindows_x
FUNCTION_AT_ADDRESS(void  CXWndManager::CleanupWindows(void),CXWndManager__CleanupWindows);
#endif
#ifdef CXWndManager__GetFirstChildWnd_x
FUNCTION_AT_ADDRESS(class CXWnd *  CXWndManager::GetFirstChildWnd(class CXWnd const *)const ,CXWndManager__GetFirstChildWnd);
#endif
#ifdef CXWndManager__GetNextSib_x
FUNCTION_AT_ADDRESS(class CXWnd *  CXWndManager::GetNextSib(class CXWnd const *)const ,CXWndManager__GetNextSib);
#endif
#ifdef CXWndManager__ActivateWnd_x
FUNCTION_AT_ADDRESS(int  CXWndManager::ActivateWnd(class CXWnd *),CXWndManager__ActivateWnd);
#endif
#ifdef CXWndManager__IsWindowActive_x
FUNCTION_AT_ADDRESS(bool  CXWndManager::IsWindowActive(class CXWnd const *)const ,CXWndManager__IsWindowActive);
#endif
#ifdef CXWndManager__IsWindowMovingOrSizing_x
FUNCTION_AT_ADDRESS(bool  CXWndManager::IsWindowMovingOrSizing(class CXWnd *)const ,CXWndManager__IsWindowMovingOrSizing);
#endif
#ifdef CXWndManager__AddFont_x
FUNCTION_AT_ADDRESS(int  CXWndManager::AddFont(class CTextureFont *),CXWndManager__AddFont);
#endif
#ifdef CXWndManager__GetFont1_x
FUNCTION_AT_ADDRESS(class CTextureFont *  CXWndManager::GetFont(class CXStr),CXWndManager__GetFont1);
#endif
#ifdef CXWndManager__SetSystemFont_x
FUNCTION_AT_ADDRESS(void  CXWndManager::SetSystemFont(class CTextureFont *),CXWndManager__SetSystemFont);
#endif
#ifdef CXWndManager__SetGlobalFadeDuration_x
FUNCTION_AT_ADDRESS(void  CXWndManager::SetGlobalFadeDuration(unsigned __int32),CXWndManager__SetGlobalFadeDuration);
#endif
#ifdef CXWndManager__GetGlobalFadeDuration_x
FUNCTION_AT_ADDRESS(unsigned __int32  CXWndManager::GetGlobalFadeDuration(void)const ,CXWndManager__GetGlobalFadeDuration);
#endif
#ifdef CXWndManager__SetGlobalFadeDelay_x
FUNCTION_AT_ADDRESS(void  CXWndManager::SetGlobalFadeDelay(unsigned long),CXWndManager__SetGlobalFadeDelay);
#endif
#ifdef CXWndManager__GetGlobalFadeDelay_x
FUNCTION_AT_ADDRESS(unsigned long  CXWndManager::GetGlobalFadeDelay(void)const ,CXWndManager__GetGlobalFadeDelay);
#endif
#ifdef CXWndManager__SetGlobalAlpha_x
FUNCTION_AT_ADDRESS(void  CXWndManager::SetGlobalAlpha(unsigned char),CXWndManager__SetGlobalAlpha);
#endif
#ifdef CXWndManager__GetGlobalAlpha_x
FUNCTION_AT_ADDRESS(unsigned char  CXWndManager::GetGlobalAlpha(void)const ,CXWndManager__GetGlobalAlpha);
#endif
#ifdef CXWndManager__SetGlobalFadeToAlpha_x
FUNCTION_AT_ADDRESS(void  CXWndManager::SetGlobalFadeToAlpha(unsigned char),CXWndManager__SetGlobalFadeToAlpha);
#endif
#ifdef CXWndManager__GetGlobalFadeToAlpha_x
FUNCTION_AT_ADDRESS(unsigned char  CXWndManager::GetGlobalFadeToAlpha(void)const ,CXWndManager__GetGlobalFadeToAlpha);
#endif
#ifdef CXWndManager__IsAllValid_x
FUNCTION_AT_ADDRESS(bool  CXWndManager::IsAllValid(void),CXWndManager__IsAllValid);
#endif
#ifdef CEditWnd__CEditWnd_x
//FUNCTION_AT_ADDRESS( CEditWnd::CEditWnd(class CXWnd *,unsigned __int32,class CXRect,unsigned __int32),CEditWnd__CEditWnd);
#endif
#ifdef CEditWnd__GetLineForPrintableChar_x
FUNCTION_AT_ADDRESS(int  CEditWnd::GetLineForPrintableChar(int)const ,CEditWnd__GetLineForPrintableChar);
#endif
#ifdef CEditWnd__GetLineLength_x
FUNCTION_AT_ADDRESS(int  CEditWnd::GetLineLength(int)const ,CEditWnd__GetLineLength);
#endif
#ifdef CEditWnd__FillIndexArray_x
FUNCTION_AT_ADDRESS(void  CEditWnd::FillIndexArray(class CXStr)const ,CEditWnd__FillIndexArray);
#endif
#ifdef CEditWnd__SelectableCharFromPoint_x
FUNCTION_AT_ADDRESS(int  CEditWnd::SelectableCharFromPoint(class CXPoint)const ,CEditWnd__SelectableCharFromPoint);
#endif
#ifdef CEditWnd__AddItemTag_x
FUNCTION_AT_ADDRESS(void  CEditWnd::AddItemTag(int,char *,int),CEditWnd__AddItemTag);
#endif
#ifdef CEditWnd__ProcessText_x
FUNCTION_AT_ADDRESS(void  CEditWnd::ProcessText(void),CEditWnd__ProcessText);
#endif
#ifdef CEditWnd__GetCharIndexPt_x
FUNCTION_AT_ADDRESS(class CXPoint  CEditWnd::GetCharIndexPt(int)const ,CEditWnd__GetCharIndexPt);
#endif
#ifdef CEditWnd__GetSelStartPt_x
FUNCTION_AT_ADDRESS(class CXPoint  CEditWnd::GetSelStartPt(void)const ,CEditWnd__GetSelStartPt);
#endif
#ifdef CEditWnd__GetSelEndPt_x
FUNCTION_AT_ADDRESS(class CXPoint  CEditWnd::GetSelEndPt(void)const ,CEditWnd__GetSelEndPt);
#endif
#ifdef CEditWnd__FilterInputStr_x
FUNCTION_AT_ADDRESS(void  CEditWnd::FilterInputStr(class CXStr &),CEditWnd__FilterInputStr);
#endif
#ifdef CEditWnd__ReplaceSelection_x
FUNCTION_AT_ADDRESS(void  CEditWnd::ReplaceSelection(class CXStr,bool),CEditWnd__ReplaceSelection);
#endif
#ifdef CEditWnd__ReplaceSelection1_x
FUNCTION_AT_ADDRESS(void  CEditWnd::ReplaceSelection(char,bool),CEditWnd__ReplaceSelection1);
#endif
#ifdef CEditWnd__CalculateScrollRange_x
FUNCTION_AT_ADDRESS(void  CEditWnd::CalculateScrollRange(void),CEditWnd__CalculateScrollRange);
#endif
#ifdef CEditWnd__EnsureCaretVisible_x
FUNCTION_AT_ADDRESS(void  CEditWnd::EnsureCaretVisible(void),CEditWnd__EnsureCaretVisible);
#endif
#ifdef CEditWnd__SetEditable_x
FUNCTION_AT_ADDRESS(void  CEditWnd::SetEditable(bool),CEditWnd__SetEditable);
#endif
#ifdef CEditWnd__GetSTMLSafeText_x
FUNCTION_AT_ADDRESS(class CXStr  CEditWnd::GetSTMLSafeText(void),CEditWnd__GetSTMLSafeText);
#endif
#ifdef CEditWnd__ConvertIndexPrintableToTagged_x
FUNCTION_AT_ADDRESS(int  CEditWnd::ConvertIndexPrintableToTagged(int),CEditWnd__ConvertIndexPrintableToTagged);
#endif
#ifdef CEditWnd__ConvertIndexTaggedToPrintable_x
FUNCTION_AT_ADDRESS(int  CEditWnd::ConvertIndexTaggedToPrintable(int),CEditWnd__ConvertIndexTaggedToPrintable);
#endif
#ifdef CTextureFont__GetWidth_x
FUNCTION_AT_ADDRESS(int  CTextureFont::GetWidth(unsigned short)const ,CTextureFont__GetWidth);
#endif
#ifdef CTextureFont__GetKerning_x
FUNCTION_AT_ADDRESS(int  CTextureFont::GetKerning(unsigned short,unsigned short)const ,CTextureFont__GetKerning);
#endif
#ifdef CTextureFont__GetTextExtent_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(int CTextureFont::GetTextExtent(CXStr *),CTextureFont__GetTextExtent);
#else
FUNCTION_AT_ADDRESS(int CTextureFont::GetTextExtent(void),CTextureFont__GetTextExtent);
#endif
#endif
#ifdef CTextureFont__GetHeight_x
FUNCTION_AT_ADDRESS(int  CTextureFont::GetHeight(void)const ,CTextureFont__GetHeight);
#endif
#ifdef CTextureFont__GetName_x
FUNCTION_AT_ADDRESS(class CXStr  CTextureFont::GetName(void)const ,CTextureFont__GetName);
#endif
#ifdef CTextureFont__DrawWrappedText_x
FUNCTION_AT_ADDRESS(int  CTextureFont::DrawWrappedText(CXStr *, int, int, int, CXRect *, COLORREF, WORD, int)const ,CTextureFont__DrawWrappedText);
#endif
#ifdef CTextureFont__DrawWrappedText1_x
FUNCTION_AT_ADDRESS(int  CTextureFont::DrawWrappedText(class CXStr,class CXRect,class CXRect,unsigned long,unsigned short,int)const ,CTextureFont__DrawWrappedText1);
#endif
#ifdef CTextureAnimation__CTextureAnimation_x
FUNCTION_AT_ADDRESS( CTextureAnimation::CTextureAnimation(void),CTextureAnimation__CTextureAnimation);
#endif
#ifdef CTextureAnimation__CTextureAnimation1_x
FUNCTION_AT_ADDRESS( CTextureAnimation::CTextureAnimation(class CXStr),CTextureAnimation__CTextureAnimation1);
#endif
#ifdef CUITexturePiece__CUITexturePiece1_x
FUNCTION_AT_ADDRESS( CUITexturePiece::CUITexturePiece(class CUITexturePiece const &),CUITexturePiece__CUITexturePiece1);
#endif
#ifdef CTextureAnimation__AddFrame_x
FUNCTION_AT_ADDRESS(int  CTextureAnimation::AddFrame(class CUITextureInfo const *,class CXRect,unsigned __int32,class CXPoint),CTextureAnimation__AddFrame);
#endif
#ifdef CUITexturePiece__CUITexturePiece2_x
//FUNCTION_AT_ADDRESS( CUITexturePiece::CUITexturePiece(class CUITextureInfo,class CXRect),CUITexturePiece__CUITexturePiece2);
#endif
#ifdef CUITextureInfo__CUITextureInfo2_x
FUNCTION_AT_ADDRESS( CUITextureInfo::CUITextureInfo(class CUITextureInfo const &),CUITextureInfo__CUITextureInfo2);
#endif
#ifdef CTextureAnimation__AddFrame1_x
//FUNCTION_AT_ADDRESS(int  CTextureAnimation::AddFrame(class CUITexturePiece,unsigned __int32,class CXPoint),CTextureAnimation__AddFrame1);
#endif
#ifdef STextureAnimationFrame__STextureAnimationFrame1_x
FUNCTION_AT_ADDRESS( STextureAnimationFrame::STextureAnimationFrame(class CUITexturePiece,unsigned __int32,class CXPoint),STextureAnimationFrame__STextureAnimationFrame1);
#endif
#ifdef CUITextureInfo__CUITextureInfo3_x
FUNCTION_AT_ADDRESS( CUITextureInfo::CUITextureInfo(unsigned __int32,int),CUITextureInfo__CUITextureInfo3);
#endif
#ifdef CTextureAnimation__AddBlankFrame_x
FUNCTION_AT_ADDRESS(int  CTextureAnimation::AddBlankFrame(unsigned __int32,class CXPoint),CTextureAnimation__AddBlankFrame);
#endif
#ifdef CTextureAnimation__SetCurFrame_x
FUNCTION_AT_ADDRESS(void  CTextureAnimation::SetCurFrame(int),CTextureAnimation__SetCurFrame);
#endif
#ifdef CTextureAnimation__GetCurFrame_x
FUNCTION_AT_ADDRESS(int  CTextureAnimation::GetCurFrame(void)const ,CTextureAnimation__GetCurFrame);
#endif
#ifdef CTextureAnimation__Draw_x
FUNCTION_AT_ADDRESS(int  CTextureAnimation::Draw(class CXRect,class CXRect,unsigned long,unsigned long)const ,CTextureAnimation__Draw);
#endif
#ifdef CTextureAnimation__Draw1_x
FUNCTION_AT_ADDRESS(int  CTextureAnimation::Draw(class CXPoint,class CXRect,unsigned long,unsigned long)const ,CTextureAnimation__Draw1);
#endif
#ifdef CTextureAnimation__GetHotspot_x
FUNCTION_AT_ADDRESS(class CXPoint  CTextureAnimation::GetHotspot(void)const ,CTextureAnimation__GetHotspot);
#endif
#ifdef CTextureAnimation__SetCurCell_x
FUNCTION_AT_ADDRESS(void  CTextureAnimation::SetCurCell(int),CTextureAnimation__SetCurCell);
#endif
#ifdef CTextureAnimation__Preload_x
FUNCTION_AT_ADDRESS(int  CTextureAnimation::Preload(void),CTextureAnimation__Preload);
#endif
#ifdef CUITextureInfo__operator_equal_x
FUNCTION_AT_ADDRESS(class CUITextureInfo &  CUITextureInfo::operator=(class CUITextureInfo const &),CUITextureInfo__operator_equal);
#endif
#ifdef CSidlManager__CSidlManager_x
FUNCTION_AT_ADDRESS( CSidlManager::CSidlManager(void),CSidlManager__CSidlManager);
#endif
#ifdef CSidlManager__GetPointFromParamPoint_x
FUNCTION_AT_ADDRESS(class CXPoint __cdecl CSidlManager::GetPointFromParamPoint(class CParamPoint const &),CSidlManager__GetPointFromParamPoint);
#endif
#ifdef CSidlManager__GetSizeFromParamSize_x
FUNCTION_AT_ADDRESS(class CXSize __cdecl CSidlManager::GetSizeFromParamSize(class CParamSize const &),CSidlManager__GetSizeFromParamSize);
#endif
#ifdef CSidlManager__GetRectFromParamPointSize_x
FUNCTION_AT_ADDRESS(class CXRect __cdecl CSidlManager::GetRectFromParamPointSize(class CParamPoint const &,class CParamSize const &),CSidlManager__GetRectFromParamPointSize);
#endif
#ifdef CSidlManager__GetD3DCOLOR_x
FUNCTION_AT_ADDRESS(unsigned long __cdecl CSidlManager::GetD3DCOLOR(class CParamRGB const &),CSidlManager__GetD3DCOLOR);
#endif
#ifdef CSidlManager__GetButtonDrawTemplateFromParamButtonDrawTemplate_x
FUNCTION_AT_ADDRESS(class CButtonDrawTemplate  CSidlManager::GetButtonDrawTemplateFromParamButtonDrawTemplate(class CParamButtonDrawTemplate const &)const ,CSidlManager__GetButtonDrawTemplateFromParamButtonDrawTemplate);
#endif
#ifdef CSidlManager__GetGaugeDrawTemplateFromParamGaugeDrawTemplate_x
FUNCTION_AT_ADDRESS(class CGaugeDrawTemplate  CSidlManager::GetGaugeDrawTemplateFromParamGaugeDrawTemplate(class CParamGaugeDrawTemplate const &)const ,CSidlManager__GetGaugeDrawTemplateFromParamGaugeDrawTemplate);
#endif
#ifdef CSidlManager__GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate_x
FUNCTION_AT_ADDRESS(class CSpellGemDrawTemplate  CSidlManager::GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate(class CParamSpellGemDrawTemplate const &)const ,CSidlManager__GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate);
#endif
#ifdef CSidlManager__DeleteContents_x
FUNCTION_AT_ADDRESS(void  CSidlManager::DeleteContents(void),CSidlManager__DeleteContents);
#endif
#ifdef CParamScrollbarDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamScrollbarDrawTemplate &  CParamScrollbarDrawTemplate::operator=(class CParamScrollbarDrawTemplate const &),CParamScrollbarDrawTemplate__operator_equal);
#endif
#ifdef CParamFrameTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamFrameTemplate &  CParamFrameTemplate::operator=(class CParamFrameTemplate const &),CParamFrameTemplate__operator_equal);
#endif
#ifdef CParamButtonDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamButtonDrawTemplate &  CParamButtonDrawTemplate::operator=(class CParamButtonDrawTemplate const &),CParamButtonDrawTemplate__operator_equal);
#endif
#ifdef CParamClass__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamClass &  CParamClass::operator=(class CParamClass const &),CParamClass__operator_equal);
#endif
#ifdef CParamRGB__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamRGB &  CParamRGB::operator=(class CParamRGB const &),CParamRGB__operator_equal);
#endif
#ifdef CParam__operator_equal_x
FUNCTION_AT_ADDRESS(class CParam &  CParam::operator=(class CParam const &),CParam__operator_equal);
#endif
#ifdef CXMLData__operator_equal_x
FUNCTION_AT_ADDRESS(class CXMLData &  CXMLData::operator=(class CXMLData const &),CXMLData__operator_equal);
#endif
#ifdef CTAFrameDraw__GetName_x
FUNCTION_AT_ADDRESS(class CXStr  CTAFrameDraw::GetName(void)const ,CTAFrameDraw__GetName);
#endif
#ifdef CScreenPieceTemplate__GetName_x
FUNCTION_AT_ADDRESS(class CXStr  CScreenPieceTemplate::GetName(void)const ,CScreenPieceTemplate__GetName);
#endif
#ifdef CSidlManager__LoadSidl_x
FUNCTION_AT_ADDRESS(void CSidlManager::LoadSidl(CXStr const &,CXStr const &,CXStr const &,CXStr const &),CSidlManager__LoadSidl);
#endif
#ifdef CUITextureInfo__CUITextureInfo4_x
FUNCTION_AT_ADDRESS( CUITextureInfo::CUITextureInfo(class CXStr,class CXSize),CUITextureInfo__CUITextureInfo4);
#endif
#ifdef CSidlManager__CreateTextureAnimationFromSidlAnimation_x
FUNCTION_AT_ADDRESS(class CTextureAnimation  CSidlManager::CreateTextureAnimationFromSidlAnimation(class CParamUi2DAnimation const *)const ,CSidlManager__CreateTextureAnimationFromSidlAnimation);
#endif
#ifdef CSidlManager__CreateTAFrameDrawFromSidlFrame_x
FUNCTION_AT_ADDRESS(class CTAFrameDraw  CSidlManager::CreateTAFrameDrawFromSidlFrame(class CParamFrameTemplate const *)const ,CSidlManager__CreateTAFrameDrawFromSidlFrame);
#endif
#ifdef CSidlManager__GetScrollbarTemplateFromParamScrollbarTemplate_x
FUNCTION_AT_ADDRESS(class CScrollbarTemplate  CSidlManager::GetScrollbarTemplateFromParamScrollbarTemplate(class CParamScrollbarDrawTemplate const &)const ,CSidlManager__GetScrollbarTemplateFromParamScrollbarTemplate);
#endif
#ifdef CScrollbarTemplate__CScrollbarTemplate_x
FUNCTION_AT_ADDRESS( CScrollbarTemplate::CScrollbarTemplate(class CScrollbarTemplate const &),CScrollbarTemplate__CScrollbarTemplate);
#endif
#ifdef CSidlManager__GetSliderDrawTemplateFromParamSliderDrawTemplate_x
FUNCTION_AT_ADDRESS(class CSliderDrawTemplate  CSidlManager::GetSliderDrawTemplateFromParamSliderDrawTemplate(class CParamSliderDrawTemplate const &)const ,CSidlManager__GetSliderDrawTemplateFromParamSliderDrawTemplate);
#endif
#ifdef CButtonDrawTemplate__CButtonDrawTemplate1_x
FUNCTION_AT_ADDRESS( CButtonDrawTemplate::CButtonDrawTemplate(class CButtonDrawTemplate const &),CButtonDrawTemplate__CButtonDrawTemplate1);
#endif
#ifdef CSliderDrawTemplate__dCSliderDrawTemplate_x
FUNCTION_AT_ADDRESS( CSliderDrawTemplate::~CSliderDrawTemplate(void),CSliderDrawTemplate__dCSliderDrawTemplate);
#endif
#ifdef CSidlManager__CreateDrawTemplateFromParamWindowDrawTemplate_x
FUNCTION_AT_ADDRESS(class CXWndDrawTemplate  CSidlManager::CreateDrawTemplateFromParamWindowDrawTemplate(class CParamWindowDrawTemplate const *)const ,CSidlManager__CreateDrawTemplateFromParamWindowDrawTemplate);
#endif
#ifdef CScrollbarTemplate__CScrollbarTemplate1_x
FUNCTION_AT_ADDRESS( CScrollbarTemplate::CScrollbarTemplate(void),CScrollbarTemplate__CScrollbarTemplate1);
#endif
#ifdef CXWndDrawTemplate__CXWndDrawTemplate1_x
FUNCTION_AT_ADDRESS( CXWndDrawTemplate::CXWndDrawTemplate(class CXWndDrawTemplate const &),CXWndDrawTemplate__CXWndDrawTemplate1);
#endif
#ifdef CTAFrameDraw__CTAFrameDraw_x
FUNCTION_AT_ADDRESS( CTAFrameDraw::CTAFrameDraw(class CTAFrameDraw const &),CTAFrameDraw__CTAFrameDraw);
#endif
#ifdef CSidlManager__CreateScreenPieceTemplateFromParamScreenPiece_x
FUNCTION_AT_ADDRESS(class CScreenPieceTemplate *  CSidlManager::CreateScreenPieceTemplateFromParamScreenPiece(class CParamScreenPiece const *)const ,CSidlManager__CreateScreenPieceTemplateFromParamScreenPiece);
#endif
#ifdef CSidlManager__GetParsingErrorMsg_x
FUNCTION_AT_ADDRESS(class CXStr  CSidlManager::GetParsingErrorMsg(void)const ,CSidlManager__GetParsingErrorMsg);
#endif
#ifdef CSidlManager__GetScreenPieceEnum_x
//FUNCTION_AT_ADDRESS(enum EStaticScreenPieceClasses  CSidlManager::GetScreenPieceEnum(class CScreenPieceTemplate *)const ,CSidlManager__GetScreenPieceEnum);
#endif
#ifdef CSidlManager__FindAnimation_x
FUNCTION_AT_ADDRESS(class CTextureAnimation *  CSidlManager::FindAnimation(unsigned __int32)const ,CSidlManager__FindAnimation);
#endif
#ifdef CSidlManager__FindAnimation1_x
FUNCTION_AT_ADDRESS(class CTextureAnimation * CSidlManager::FindAnimation(class CXStr const &)const ,CSidlManager__FindAnimation1);
#endif
#ifdef CSidlManager__FindFrameDraw_x
FUNCTION_AT_ADDRESS(class CTAFrameDraw *  CSidlManager::FindFrameDraw(unsigned __int32)const ,CSidlManager__FindFrameDraw);
#endif
#ifdef CSidlManager__FindDrawTemplate_x
FUNCTION_AT_ADDRESS(class CXWndDrawTemplate *  CSidlManager::FindDrawTemplate(unsigned __int32)const ,CSidlManager__FindDrawTemplate);
#endif
#ifdef CSidlManager__FindDrawTemplate1_x
FUNCTION_AT_ADDRESS(class CXWndDrawTemplate *  CSidlManager::FindDrawTemplate(class CXStr)const ,CSidlManager__FindDrawTemplate1);
#endif
#ifdef CSidlManager__FindScreenPieceTemplate_x
FUNCTION_AT_ADDRESS(class CScreenPieceTemplate * CSidlManager::FindScreenPieceTemplate(unsigned __int32)const ,CSidlManager__FindScreenPieceTemplate);
#endif
#ifdef CSidlManager__FindScreenPieceTemplate1_x
FUNCTION_AT_ADDRESS(class CScreenPieceTemplate *  CSidlManager::FindScreenPieceTemplate(class CXStr *)const ,CSidlManager__FindScreenPieceTemplate1);
#endif
#ifdef CSidlManager__AddAnimationInOrder_x
FUNCTION_AT_ADDRESS(void  CSidlManager::AddAnimationInOrder(class CTextureAnimation *),CSidlManager__AddAnimationInOrder);
#endif
#ifdef CSidlManager__AddDrawTemplateInOrder_x
FUNCTION_AT_ADDRESS(void  CSidlManager::AddDrawTemplateInOrder(class CXWndDrawTemplate *),CSidlManager__AddDrawTemplateInOrder);
#endif
#ifdef CSidlManager__AddTAFrameDrawInOrder_x
FUNCTION_AT_ADDRESS(void  CSidlManager::AddTAFrameDrawInOrder(class CTAFrameDraw *),CSidlManager__AddTAFrameDrawInOrder);
#endif
#ifdef CSidlManager__AddScreenPieceTemplateInOrder_x
FUNCTION_AT_ADDRESS(void  CSidlManager::AddScreenPieceTemplateInOrder(class CScreenPieceTemplate *),CSidlManager__AddScreenPieceTemplateInOrder);
#endif
#ifdef CSidlManager__FindTexture_x
FUNCTION_AT_ADDRESS(class CUITextureInfo *  CSidlManager::FindTexture(class CXStr)const ,CSidlManager__FindTexture);
#endif
#ifdef CSidlManager__FindTexture1_x
FUNCTION_AT_ADDRESS(class CUITextureInfo *  CSidlManager::FindTexture(unsigned __int32)const ,CSidlManager__FindTexture1);
#endif
#ifdef CSidlManagerBase__FindButtonDrawTemplate_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate * CSidlManager::FindButtonDrawTemplate(unsigned __int32) const ,CSidlManagerBase__FindButtonDrawTemplate);
#endif
#ifdef CSidlManagerBase__FindButtonDrawTemplate1_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate *CSidlManager::FindButtonDrawTemplate(const CXStr& Name) const ,CSidlManagerBase__FindButtonDrawTemplate1);
#endif
#ifdef CSidlManager__FindSliderDrawTemplate_x
FUNCTION_AT_ADDRESS(class CSliderDrawTemplate *  CSidlManager::FindSliderDrawTemplate(class CXStr)const ,CSidlManager__FindSliderDrawTemplate);
#endif
#ifdef CSidlManager__FindSliderDrawTemplate1_x
FUNCTION_AT_ADDRESS(class CSliderDrawTemplate *  CSidlManager::FindSliderDrawTemplate(unsigned __int32)const ,CSidlManager__FindSliderDrawTemplate1);
#endif
#ifdef CSidlManager__CreateXWndFromTemplate_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(class CXWnd *  CSidlManager::CreateXWndFromTemplate(class CXWnd *,class CControlTemplate *, bool),CSidlManager__CreateXWndFromTemplate);
#else
FUNCTION_AT_ADDRESS(class CXWnd *  CSidlManager::CreateXWndFromTemplate(class CXWnd *,class CControlTemplate *),CSidlManager__CreateXWndFromTemplate);
#endif
#endif
#ifdef CSidlManager__CreateXWndFromTemplate1_x
FUNCTION_AT_ADDRESS(class CXWnd * CSidlManager::CreateXWndFromTemplate(CXWnd *,CXStr &),CSidlManager__CreateXWndFromTemplate1);
#endif
#ifdef CSidlManager__CreateXWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlManager::CreateXWnd(CXWnd *pwndParent, CControlTemplate *pControl),CSidlManager__CreateXWnd);
#endif
#ifdef CSidlManager__CreateHotButtonWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlManager::CreateHotButtonWnd(CXWnd* pwndParent, CControlTemplate* pControl),CSidlManager__CreateHotButtonWnd);
#endif
#ifdef CTAFrameDraw__GetAnimation_x
FUNCTION_AT_ADDRESS(class CTextureAnimation *  CTAFrameDraw::GetAnimation(int)const ,CTAFrameDraw__GetAnimation);
#endif
#ifdef CXWnd__SetXMLTooltip_x
FUNCTION_AT_ADDRESS(void  CXWnd::SetXMLTooltip(class CXStr),CXWnd__SetXMLTooltip);
#endif
#ifdef CSidlManager__TranslateString_x
FUNCTION_AT_ADDRESS(class CXStr __cdecl CSidlManager::TranslateString(class CXStr),CSidlManager__TranslateString);
#endif
#ifdef CXMLEnumInfo__dCXMLEnumInfo_x
FUNCTION_AT_ADDRESS( CXMLEnumInfo::~CXMLEnumInfo(void),CXMLEnumInfo__dCXMLEnumInfo);
#endif
#ifdef CXMLDataClass__dCXMLDataClass_x
FUNCTION_AT_ADDRESS( CXMLDataClass::~CXMLDataClass(void),CXMLDataClass__dCXMLDataClass);
#endif
#ifdef CTAFrameDraw__CTAFrameDraw1_x
FUNCTION_AT_ADDRESS( CTAFrameDraw::CTAFrameDraw(class CXStr),CTAFrameDraw__CTAFrameDraw1);
#endif
#ifdef CTAFrameDraw__Set_x
FUNCTION_AT_ADDRESS(void  CTAFrameDraw::Set(class CTextureAnimation * * const),CTAFrameDraw__Set);
#endif
#ifdef CTAFrameDraw__Draw_x
FUNCTION_AT_ADDRESS(int  CTAFrameDraw::Draw(class CXRect,class CXRect)const ,CTAFrameDraw__Draw);
#endif
#ifdef CTAFrameDraw__Draw1_x
FUNCTION_AT_ADDRESS(int  CTAFrameDraw::Draw(class CXRect,class CXRect,int)const ,CTAFrameDraw__Draw1);
#endif
#ifdef CTAFrameDraw__GetHitTestRect_x
FUNCTION_AT_ADDRESS(class CXRect  CTAFrameDraw::GetHitTestRect(class CXRect,int)const ,CTAFrameDraw__GetHitTestRect);
#endif
#ifdef CTAFrameDraw__GetPieceRect_x
FUNCTION_AT_ADDRESS(class CXRect  CTAFrameDraw::GetPieceRect(class CXRect,int)const ,CTAFrameDraw__GetPieceRect);
#endif
#ifdef CTAFrameDraw__IsHorizontal_x
FUNCTION_AT_ADDRESS(bool  CTAFrameDraw::IsHorizontal(void)const ,CTAFrameDraw__IsHorizontal);
#endif
#ifdef CTAFrameDraw__IsVertical_x
FUNCTION_AT_ADDRESS(bool  CTAFrameDraw::IsVertical(void)const ,CTAFrameDraw__IsVertical);
#endif
#ifdef CTAFrameDraw__GetExtent_x
FUNCTION_AT_ADDRESS(int  CTAFrameDraw::GetExtent(void)const ,CTAFrameDraw__GetExtent);
#endif
#ifdef CTAFrameDraw__GetMinLength_x
FUNCTION_AT_ADDRESS(int  CTAFrameDraw::GetMinLength(void)const ,CTAFrameDraw__GetMinLength);
#endif
#ifdef CTAFrameDraw__GetInnerRect_x
FUNCTION_AT_ADDRESS(class CXRect  CTAFrameDraw::GetInnerRect(class CXRect)const ,CTAFrameDraw__GetInnerRect);
#endif
#ifdef CSpellGemWnd__CSpellGemWnd_x
FUNCTION_AT_ADDRESS( CSpellGemWnd::CSpellGemWnd(class CXWnd *,unsigned __int32,class CXRect,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,int,int,unsigned long),CSpellGemWnd__CSpellGemWnd);
#endif
#ifdef CSpellGemWnd__Init_x
FUNCTION_AT_ADDRESS(void  CSpellGemWnd::Init(void),CSpellGemWnd__Init);
#endif
#ifdef CSpellGemWnd__SetSpellIconIndex_x
FUNCTION_AT_ADDRESS(void  CSpellGemWnd::SetSpellIconIndex(int),CSpellGemWnd__SetSpellIconIndex);
#endif
#ifdef CSpellGemWnd__SetSpellGemTint_x
FUNCTION_AT_ADDRESS(void  CSpellGemWnd::SetSpellGemTint(unsigned long),CSpellGemWnd__SetSpellGemTint);
#endif
#ifdef CSpellGemWnd__SetGemTintStage_x
FUNCTION_AT_ADDRESS(void  CSpellGemWnd::SetGemTintStage(int),CSpellGemWnd__SetGemTintStage);
#endif
#ifdef CSpellGemWnd__SetCheck_x
FUNCTION_AT_ADDRESS(void  CSpellGemWnd::SetCheck(bool),CSpellGemWnd__SetCheck);
#endif
#ifdef CSliderWnd__CSliderWnd_x
FUNCTION_AT_ADDRESS( CSliderWnd::CSliderWnd(class CXWnd *,unsigned __int32,class CXRect,class CSliderTemplate *),CSliderWnd__CSliderWnd);
#endif
#ifdef CSliderWnd__SetValue_x
FUNCTION_AT_ADDRESS(void  CSliderWnd::SetValue(int),CSliderWnd__SetValue);
#endif
#ifdef CSliderWnd__SetNumTicks_x
FUNCTION_AT_ADDRESS(void  CSliderWnd::SetNumTicks(int),CSliderWnd__SetNumTicks);
#endif
#ifdef CSliderWnd__UpdateThumb_x
FUNCTION_AT_ADDRESS(void  CSliderWnd::UpdateThumb(void),CSliderWnd__UpdateThumb);
#endif
#ifdef CSliderWnd__UpdateMiddleRange_x
FUNCTION_AT_ADDRESS(void  CSliderWnd::UpdateMiddleRange(void),CSliderWnd__UpdateMiddleRange);
#endif
#ifdef CSliderWnd__GetValue_x
FUNCTION_AT_ADDRESS(int  CSliderWnd::GetValue(void)const,CSliderWnd__GetValue);
#endif
#ifdef CSliderWnd__GetMiddleRangeRect_x
FUNCTION_AT_ADDRESS(class CXRect  CSliderWnd::GetMiddleRangeRect(void)const ,CSliderWnd__GetMiddleRangeRect);
#endif
#ifdef CSliderWnd__GetEndCapLeftRect_x
FUNCTION_AT_ADDRESS(class CXRect  CSliderWnd::GetEndCapLeftRect(void)const ,CSliderWnd__GetEndCapLeftRect);
#endif
#ifdef CSliderWnd__GetEndCapRightRect_x
FUNCTION_AT_ADDRESS(class CXRect  CSliderWnd::GetEndCapRightRect(void)const ,CSliderWnd__GetEndCapRightRect);
#endif
#ifdef CSliderWnd__GetThumbRect_x
FUNCTION_AT_ADDRESS(class CXRect  CSliderWnd::GetThumbRect(void)const ,CSliderWnd__GetThumbRect);
#endif
#ifdef CSliderWnd__SetThumbToOffset_x
FUNCTION_AT_ADDRESS(void  CSliderWnd::SetThumbToOffset(int),CSliderWnd__SetThumbToOffset);
#endif
#ifdef CSliderWnd__DrawMiddleRange_x
FUNCTION_AT_ADDRESS(int  CSliderWnd::DrawMiddleRange(void)const ,CSliderWnd__DrawMiddleRange);
#endif
#ifdef CSliderWnd__DrawEndCapLeft_x
FUNCTION_AT_ADDRESS(int  CSliderWnd::DrawEndCapLeft(void)const ,CSliderWnd__DrawEndCapLeft);
#endif
#ifdef CSliderWnd__DrawEndCapRight_x
FUNCTION_AT_ADDRESS(int  CSliderWnd::DrawEndCapRight(void)const ,CSliderWnd__DrawEndCapRight);
#endif
#ifdef CSliderWnd__DrawThumb_x
FUNCTION_AT_ADDRESS(int  CSliderWnd::DrawThumb(void)const ,CSliderWnd__DrawThumb);
#endif
#ifdef CXWnd__DrawRaisedRect_x
FUNCTION_AT_ADDRESS(int __cdecl CXWnd::DrawRaisedRect(class CXRect,class CXRect),CXWnd__DrawRaisedRect);
#endif
#ifdef CXWnd__DrawSunkenRect_x
FUNCTION_AT_ADDRESS(int __cdecl CXWnd::DrawSunkenRect(class CXRect,class CXRect),CXWnd__DrawSunkenRect);
#endif
#ifdef CEditBaseWnd__SetSel_x
FUNCTION_AT_ADDRESS(void  CEditBaseWnd::SetSel(int,int),CEditBaseWnd__SetSel);
#endif
#ifdef CInvSlotWnd__CInvSlotWnd_x
FUNCTION_AT_ADDRESS(CInvSlotWnd::CInvSlotWnd(CXWnd *pParent, unsigned __int32 ID, CXRect rect,	CTextureAnimation *ptaBackground, ItemGlobalIndex *itemLocation, int ItemOffsetX, int ItemOffsetY),CInvSlotWnd__CInvSlotWnd);
#endif
#ifdef CInvSlotWnd__SetInvSlot_x
FUNCTION_AT_ADDRESS(void  CInvSlotWnd::SetInvSlot(class CInvSlot *),CInvSlotWnd__SetInvSlot);
#endif
#ifdef CInvSlotWnd__DrawTooltip_x
FUNCTION_AT_ADDRESS(int CInvSlotWnd::DrawTooltip(class CXWnd const *)const,CInvSlotWnd__DrawTooltip);
#endif
#ifdef CLabel__CLabel_x
FUNCTION_AT_ADDRESS(CLabel::CLabel(CXWnd *, unsigned __int32, CXRect *, int),CLabel__CLabel);
#endif
#ifdef CLabel__SetNoWrap_x
FUNCTION_AT_ADDRESS(void  CLabel::SetNoWrap(bool),CLabel__SetNoWrap);
#endif
#ifdef CLabel__SetAlignRight_x
FUNCTION_AT_ADDRESS(void  CLabel::SetAlignRight(bool),CLabel__SetAlignRight);
#endif
#ifdef CLabel__SetAlignCenter_x
FUNCTION_AT_ADDRESS(void  CLabel::SetAlignCenter(bool),CLabel__SetAlignCenter);
#endif
#ifdef CIMEManager__CIMEManager_x
FUNCTION_AT_ADDRESS( CIMEManager::CIMEManager(struct HWND__ *),CIMEManager__CIMEManager);
#endif
#ifdef CIMEManager__dCIMEManager_x
FUNCTION_AT_ADDRESS( CIMEManager::~CIMEManager(void),CIMEManager__dCIMEManager);
#endif
#ifdef CIMEManager__handleWndProc_x
FUNCTION_AT_ADDRESS(int  CIMEManager::handleWndProc(unsigned int,unsigned int,long),CIMEManager__handleWndProc);
#endif
#ifdef CIMEManager__handleAddChar_x
FUNCTION_AT_ADDRESS(int  CIMEManager::handleAddChar(unsigned short),CIMEManager__handleAddChar);
#endif
#ifdef CIMEManager__handleInputComposition_x
FUNCTION_AT_ADDRESS(int  CIMEManager::handleInputComposition(long),CIMEManager__handleInputComposition);
#endif
#ifdef CIMEManager__handleEndComposition_x
FUNCTION_AT_ADDRESS(int  CIMEManager::handleEndComposition(void),CIMEManager__handleEndComposition);
#endif
#ifdef CIMEManager__handleStartComposition_x
FUNCTION_AT_ADDRESS(int  CIMEManager::handleStartComposition(void),CIMEManager__handleStartComposition);
#endif
#ifdef CIMEManager__handleOpenCandidates_x
FUNCTION_AT_ADDRESS(int  CIMEManager::handleOpenCandidates(void),CIMEManager__handleOpenCandidates);
#endif
#ifdef CIMEManager__handleChangeCandidates_x
FUNCTION_AT_ADDRESS(int  CIMEManager::handleChangeCandidates(void),CIMEManager__handleChangeCandidates);
#endif
#ifdef CIMEManager__handleCloseCandidates_x
FUNCTION_AT_ADDRESS(int  CIMEManager::handleCloseCandidates(void),CIMEManager__handleCloseCandidates);
#endif
#ifdef CIMEManager__handleImeStatusChanged_x
FUNCTION_AT_ADDRESS(int  CIMEManager::handleImeStatusChanged(void),CIMEManager__handleImeStatusChanged);
#endif
#ifdef CIMEManager__handleImeChanged_x
FUNCTION_AT_ADDRESS(int  CIMEManager::handleImeChanged(void),CIMEManager__handleImeChanged);
#endif
#ifdef CIMEManager__setInputEditWnd_x
FUNCTION_AT_ADDRESS(int  CIMEManager::setInputEditWnd(class CEditWnd *),CIMEManager__setInputEditWnd);
#endif
#ifdef CIMEManager__turnImeOn_x
FUNCTION_AT_ADDRESS(void  CIMEManager::turnImeOn(void),CIMEManager__turnImeOn);
#endif
#ifdef CIMEManager__turnImeOff_x
FUNCTION_AT_ADDRESS(void  CIMEManager::turnImeOff(void),CIMEManager__turnImeOff);
#endif
#ifdef CIMEManager__imeIsOn_x
FUNCTION_AT_ADDRESS(bool  CIMEManager::imeIsOn(void)const ,CIMEManager__imeIsOn);
#endif
#ifdef CIMEManager__imeIsOff_x
FUNCTION_AT_ADDRESS(bool  CIMEManager::imeIsOff(void)const ,CIMEManager__imeIsOff);
#endif
#ifdef CIMEManager__enableIme_x
FUNCTION_AT_ADDRESS(void  CIMEManager::enableIme(bool),CIMEManager__enableIme);
#endif
#ifdef CIMEManager__queryImeLanguage_x
FUNCTION_AT_ADDRESS(int  CIMEManager::queryImeLanguage(void)const ,CIMEManager__queryImeLanguage);
#endif
#ifdef CIMEManager__queryImeProperties_x
FUNCTION_AT_ADDRESS(int  CIMEManager::queryImeProperties(void)const ,CIMEManager__queryImeProperties);
#endif
#ifdef CIMEManager__setInputState_x
FUNCTION_AT_ADDRESS(void  CIMEManager::setInputState(int),CIMEManager__setInputState);
#endif
#ifdef CIMEManager__getInputState_x
FUNCTION_AT_ADDRESS(int  CIMEManager::getInputState(void)const ,CIMEManager__getInputState);
#endif
#ifdef CIMEManager__getInputLanguage_x
FUNCTION_AT_ADDRESS(int  CIMEManager::getInputLanguage(void)const ,CIMEManager__getInputLanguage);
#endif
#ifdef CIMEManager__getImeProperties_x
FUNCTION_AT_ADDRESS(int  CIMEManager::getImeProperties(void)const ,CIMEManager__getImeProperties);
#endif
#ifdef CIMEManager__getWindowHandle_x
FUNCTION_AT_ADDRESS(struct HWND__ *  CIMEManager::getWindowHandle(void)const ,CIMEManager__getWindowHandle);
#endif
#ifdef CUITextureInfo__Draw_x
FUNCTION_AT_ADDRESS(int  CUITextureInfo::Draw(class CXRect,class CXRect,class CXRect,unsigned long,unsigned long)const ,CUITextureInfo__Draw);
#endif
#ifdef CUITextureInfo__Draw1_x
FUNCTION_AT_ADDRESS(int  CUITextureInfo::Draw(class CXRect,class CXRect,class CXRect,unsigned long *,unsigned long *)const ,CUITextureInfo__Draw1);
#endif
#ifdef CUITexturePiece__Draw_x
FUNCTION_AT_ADDRESS(int  CUITexturePiece::Draw(class CXRect,class CXRect,unsigned long,unsigned long)const ,CUITexturePiece__Draw);
#endif
#ifdef CUITexturePiece__Draw1_x
FUNCTION_AT_ADDRESS(int  CUITexturePiece::Draw(class CXRect,class CXRect,class CXRect,unsigned long,unsigned long)const ,CUITexturePiece__Draw1);
#endif
#ifdef CUITextureInfo__Tile_x
FUNCTION_AT_ADDRESS(int  CUITextureInfo::Tile(class CXRect,unsigned long,unsigned long)const ,CUITextureInfo__Tile);
#endif
#ifdef CUITextureInfo__Tile1_x
FUNCTION_AT_ADDRESS(int  CUITextureInfo::Tile(class CXRect,unsigned long *,unsigned long *)const ,CUITextureInfo__Tile1);
#endif
#ifdef CUITextureInfo__Preload_x
FUNCTION_AT_ADDRESS(int  CUITextureInfo::Preload(void),CUITextureInfo__Preload);
#endif
#ifdef CXMLDataPtr__SetNewPtr_x
FUNCTION_AT_ADDRESS(void  CXMLDataPtr::SetNewPtr(class CXMLData *),CXMLDataPtr__SetNewPtr);
#endif
#ifdef CXMLEnumInfo__GetStreamSize_x
FUNCTION_AT_ADDRESS(int  CXMLEnumInfo::GetStreamSize(void),CXMLEnumInfo__GetStreamSize);
#endif
#ifdef CXMLEnumInfo__ReadFromStream_x
FUNCTION_AT_ADDRESS(void  CXMLEnumInfo::ReadFromStream(class CMemoryStream &),CXMLEnumInfo__ReadFromStream);
#endif
#ifdef CMemoryStream__GetString_x
FUNCTION_AT_ADDRESS(void  CMemoryStream::GetString(class CXStr &),CMemoryStream__GetString);
#endif
#ifdef CXMLEnumInfo__WriteToStream_x
FUNCTION_AT_ADDRESS(void  CXMLEnumInfo::WriteToStream(class CMemoryStream &),CXMLEnumInfo__WriteToStream);
#endif
#ifdef CXMLDataClass__GetNumLeaf_x
FUNCTION_AT_ADDRESS(int  CXMLDataClass::GetNumLeaf(void),CXMLDataClass__GetNumLeaf);
#endif
#ifdef CXMLDataClass__GetStreamSize_x
FUNCTION_AT_ADDRESS(int  CXMLDataClass::GetStreamSize(void),CXMLDataClass__GetStreamSize);
#endif
#ifdef CXMLDataClass__ReadFromStream_x
FUNCTION_AT_ADDRESS(void  CXMLDataClass::ReadFromStream(class CMemoryStream &,class CXMLDataManager &),CXMLDataClass__ReadFromStream);
#endif
#ifdef CXMLDataClass__WriteToStream_x
FUNCTION_AT_ADDRESS(void  CXMLDataClass::WriteToStream(class CMemoryStream &),CXMLDataClass__WriteToStream);
#endif
#ifdef CXMLDataManager__CXMLDataManager_x
FUNCTION_AT_ADDRESS( CXMLDataManager::CXMLDataManager(void),CXMLDataManager__CXMLDataManager);
#endif
#ifdef CXMLDataManager__GetXMLData_x
FUNCTION_AT_ADDRESS(class CXMLData *  CXMLDataManager::GetXMLData(int,int),CXMLDataManager__GetXMLData);
#endif
#ifdef CXMLDataManager__GetXMLData1_x
FUNCTION_AT_ADDRESS(class CXMLData *  CXMLDataManager::GetXMLData(class CXStr,class CXStr),CXMLDataManager__GetXMLData1);
#endif
#ifdef CXMLDataManager__GetNumClass_x
FUNCTION_AT_ADDRESS(int  CXMLDataManager::GetNumClass(void),CXMLDataManager__GetNumClass);
#endif
#ifdef CXMLDataManager__GetNumItem_x
FUNCTION_AT_ADDRESS(int  CXMLDataManager::GetNumItem(int),CXMLDataManager__GetNumItem);
#endif
#ifdef CXMLDataManager__GetClassIdx_x
FUNCTION_AT_ADDRESS(int  CXMLDataManager::GetClassIdx(class CXStr),CXMLDataManager__GetClassIdx);
#endif
#ifdef CXMLDataManager__GetItemIdx_x
FUNCTION_AT_ADDRESS(int  CXMLDataManager::GetItemIdx(int,class CXStr),CXMLDataManager__GetItemIdx);
#endif
#ifdef CXMLDataPtr__Free_x
FUNCTION_AT_ADDRESS(void  CXMLDataPtr::Free(void),CXMLDataPtr__Free);
#endif
#ifdef CXMLDataManager__AddToSuperType_x
//FUNCTION_AT_ADDRESS(void  CXMLDataManager::AddToSuperType(class CXStr,class CXMLDataPtr),CXMLDataManager__AddToSuperType);
#endif
#ifdef CXMLDataPtr__operator_equal_x
FUNCTION_AT_ADDRESS(class CXMLDataPtr &  CXMLDataPtr::operator=(class CXMLDataPtr const &),CXMLDataPtr__operator_equal);
#endif
#ifdef CXMLDataManager__IsDerivedFrom_x
FUNCTION_AT_ADDRESS(bool  CXMLDataManager::IsDerivedFrom(int,int),CXMLDataManager__IsDerivedFrom);
#endif
#ifdef CXMLDataManager__SetEnumHash_x
FUNCTION_AT_ADDRESS(void  CXMLDataManager::SetEnumHash(void),CXMLDataManager__SetEnumHash);
#endif
#ifdef CXMLDataManager__ReadFromXMLSOM_x
FUNCTION_AT_ADDRESS(bool  CXMLDataManager::ReadFromXMLSOM(class CXMLSOMDocument &),CXMLDataManager__ReadFromXMLSOM);
#endif
#ifdef CXMLDataPtr__CXMLDataPtr_x
FUNCTION_AT_ADDRESS( CXMLDataPtr::CXMLDataPtr(void),CXMLDataPtr__CXMLDataPtr);
#endif
#ifdef CXMLDataClass__CXMLDataClass_x
FUNCTION_AT_ADDRESS( CXMLDataClass::CXMLDataClass(void),CXMLDataClass__CXMLDataClass);
#endif
#ifdef CXMLEnumInfo__CXMLEnumInfo_x
FUNCTION_AT_ADDRESS( CXMLEnumInfo::CXMLEnumInfo(void),CXMLEnumInfo__CXMLEnumInfo);
#endif
#ifdef CStmlReport__CreateReport_x
FUNCTION_AT_ADDRESS(class CStmlReport * __cdecl CStmlReport::CreateReport(class CXStr),CStmlReport__CreateReport);
#endif
#ifdef CXFileXML__Load_x
FUNCTION_AT_ADDRESS(bool  CXFileXML::Load(char *),CXFileXML__Load);
#endif
#ifdef CParseTokXML__GetEntityRef_x
FUNCTION_AT_ADDRESS(bool  CParseTokXML::GetEntityRef(char &),CParseTokXML__GetEntityRef);
#endif
#ifdef CParseTokXML__NextToken_x
//FUNCTION_AT_ADDRESS(enum ETokTypeXML  CParseTokXML::NextToken(void),CParseTokXML__NextToken);
#endif
#ifdef CParseTokensXML__SetError_x
FUNCTION_AT_ADDRESS(void __cdecl CParseTokensXML::SetError(char const *,...),CParseTokensXML__SetError);
#endif
#ifdef CParseTokensXML__GetCurFile_x
FUNCTION_AT_ADDRESS(class CXStr  CParseTokensXML::GetCurFile(void),CParseTokensXML__GetCurFile);
#endif
#ifdef CParseTokensXML__Accept_x
//FUNCTION_AT_ADDRESS(bool  CParseTokensXML::Accept(enum ETokTypeXML),CParseTokensXML__Accept);
#endif
#ifdef CXMLSOMParser__ParseProcess_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseProcess(void),CXMLSOMParser__ParseProcess);
#endif
#ifdef CXMLSOMParser__ParseNameSpaceToken_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseNameSpaceToken(class CXStr &),CXMLSOMParser__ParseNameSpaceToken);
#endif
#ifdef CXMLSOMParser__ParseStartTag_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseStartTag(bool &),CXMLSOMParser__ParseStartTag);
#endif
#ifdef CXMLSOMParser__ParseEndTag_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseEndTag(class CXStr),CXMLSOMParser__ParseEndTag);
#endif
#ifdef CXMLSOMParser__ParseNodeList_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseNodeList(void),CXMLSOMParser__ParseNodeList);
#endif
#ifdef CXMLSOMParser__ParseNode_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseNode(void),CXMLSOMParser__ParseNode);
#endif
#ifdef CXMLSOMParser__ParseDocument_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseDocument(void),CXMLSOMParser__ParseDocument);
#endif
#ifdef CParseTokensXML__StartFileBased_x
FUNCTION_AT_ADDRESS(bool  CParseTokensXML::StartFileBased(class CXStr),CParseTokensXML__StartFileBased);
#endif
#ifdef CXFileXML__dCXFileXML_x
FUNCTION_AT_ADDRESS( CXFileXML::~CXFileXML(void),CXFileXML__dCXFileXML);
#endif
#ifdef CTokenXML__dCTokenXML_x
FUNCTION_AT_ADDRESS( CTokenXML::~CTokenXML(void),CTokenXML__dCTokenXML);
#endif
#ifdef CXMLSOMParser__ParseFile_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseFile(class CXStr),CXMLSOMParser__ParseFile);
#endif
#ifdef CParseTokensXML__dCParseTokensXML_x
FUNCTION_AT_ADDRESS( CParseTokensXML::~CParseTokensXML(void),CParseTokensXML__dCParseTokensXML);
#endif
#ifdef CXMLSOMParser__dCXMLSOMParser_x
FUNCTION_AT_ADDRESS( CXMLSOMParser::~CXMLSOMParser(void),CXMLSOMParser__dCXMLSOMParser);
#endif
#ifdef CParseTokXML__dCParseTokXML_x
FUNCTION_AT_ADDRESS( CParseTokXML::~CParseTokXML(void),CParseTokXML__dCParseTokXML);
#endif
#ifdef CClickStickInfo__CClickStickInfo_x
FUNCTION_AT_ADDRESS( CClickStickInfo::CClickStickInfo(void),CClickStickInfo__CClickStickInfo);
#endif
#ifdef CDIMap__CDIMap_x
FUNCTION_AT_ADDRESS( CDIMap::CDIMap(void),CDIMap__CDIMap);
#endif
#ifdef CXStr__CheckNoLock_x
FUNCTION_AT_ADDRESS(void  CXStr::CheckNoLock(void),CXStr__CheckNoLock);
#endif
#ifdef CDIMap__dCDIMap_x
FUNCTION_AT_ADDRESS( CDIMap::~CDIMap(void),CDIMap__dCDIMap);
#endif
#ifdef CIMECandidateList__dCIMECandidateList_x
FUNCTION_AT_ADDRESS( CIMECandidateList::~CIMECandidateList(void),CIMECandidateList__dCIMECandidateList);
#endif
#ifdef CDIMap__LoadMappingFromFile_x
FUNCTION_AT_ADDRESS(void  CDIMap::LoadMappingFromFile(char *),CDIMap__LoadMappingFromFile);
#endif
#ifdef CHashCXStrInt32__CHashCXStrInt32_x
FUNCTION_AT_ADDRESS( CHashCXStrInt32::CHashCXStrInt32(void),CHashCXStrInt32__CHashCXStrInt32);
#endif
#ifdef CHashCXStrInt32__dCHashCXStrInt32_x
FUNCTION_AT_ADDRESS( CHashCXStrInt32::~CHashCXStrInt32(void),CHashCXStrInt32__dCHashCXStrInt32);
#endif
#ifdef CHashCXStrInt32__KeyToBin_x
FUNCTION_AT_ADDRESS(int  CHashCXStrInt32::KeyToBin(class CXStr const &)const ,CHashCXStrInt32__KeyToBin);
#endif
#ifdef CHashCXStrInt32__LookUp_x
FUNCTION_AT_ADDRESS(bool  CHashCXStrInt32::LookUp(class CXStr const &,int &)const ,CHashCXStrInt32__LookUp);
#endif
#ifdef CHashCXStrInt32__Insert_x
FUNCTION_AT_ADDRESS(bool  CHashCXStrInt32::Insert(class CXStr const &,int),CHashCXStrInt32__Insert);
#endif
#ifdef CHashCXStrInt32__Reset_x
FUNCTION_AT_ADDRESS(void  CHashCXStrInt32::Reset(void),CHashCXStrInt32__Reset);
#endif
#ifdef CParamPoint__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamPoint &  CParamPoint::operator=(class CParamPoint const &),CParamPoint__operator_equal);
#endif
#ifdef CParamSize__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamSize &  CParamSize::operator=(class CParamSize const &),CParamSize__operator_equal);
#endif
#ifdef CParamGaugeDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamGaugeDrawTemplate &  CParamGaugeDrawTemplate::operator=(class CParamGaugeDrawTemplate const &),CParamGaugeDrawTemplate__operator_equal);
#endif
#ifdef CParamSpellGemDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamSpellGemDrawTemplate &  CParamSpellGemDrawTemplate::operator=(class CParamSpellGemDrawTemplate const &),CParamSpellGemDrawTemplate__operator_equal);
#endif
#ifdef CParamScreenPiece__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamScreenPiece &  CParamScreenPiece::operator=(class CParamScreenPiece const &),CParamScreenPiece__operator_equal);
#endif
#ifdef CParamControl__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamControl &  CParamControl::operator=(class CParamControl const &),CParamControl__operator_equal);
#endif
#ifdef CParamSliderDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamSliderDrawTemplate &  CParamSliderDrawTemplate::operator=(class CParamSliderDrawTemplate const &),CParamSliderDrawTemplate__operator_equal);
#endif
#ifdef CParamStaticText__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamStaticText &  CParamStaticText::operator=(class CParamStaticText const &),CParamStaticText__operator_equal);
#endif
#ifdef CParamStaticAnimation__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamStaticAnimation &  CParamStaticAnimation::operator=(class CParamStaticAnimation const &),CParamStaticAnimation__operator_equal);
#endif
#ifdef CParamStaticFrame__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamStaticFrame &  CParamStaticFrame::operator=(class CParamStaticFrame const &),CParamStaticFrame__operator_equal);
#endif
#ifdef CParamStaticHeader__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamStaticHeader &  CParamStaticHeader::operator=(class CParamStaticHeader const &),CParamStaticHeader__operator_equal);
#endif
#ifdef CParamListboxColumn__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamListboxColumn &  CParamListboxColumn::operator=(class CParamListboxColumn const &),CParamListboxColumn__operator_equal);
#endif
#ifdef CParamListbox__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamListbox &  CParamListbox::operator=(class CParamListbox const &),CParamListbox__operator_equal);
#endif
#ifdef CParamButton__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamButton &  CParamButton::operator=(class CParamButton const &),CParamButton__operator_equal);
#endif
#ifdef CParamGauge__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamGauge &  CParamGauge::operator=(class CParamGauge const &),CParamGauge__operator_equal);
#endif
#ifdef CParamSpellGem__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamSpellGem &  CParamSpellGem::operator=(class CParamSpellGem const &),CParamSpellGem__operator_equal);
#endif
#ifdef CParamInvSlot__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamInvSlot &  CParamInvSlot::operator=(class CParamInvSlot const &),CParamInvSlot__operator_equal);
#endif
#ifdef CParamEditbox__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamEditbox &  CParamEditbox::operator=(class CParamEditbox const &),CParamEditbox__operator_equal);
#endif
#ifdef CParamSlider__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamSlider &  CParamSlider::operator=(class CParamSlider const &),CParamSlider__operator_equal);
#endif
#ifdef CParamLabel__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamLabel &  CParamLabel::operator=(class CParamLabel const &),CParamLabel__operator_equal);
#endif
#ifdef CParamCombobox__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamCombobox &  CParamCombobox::operator=(class CParamCombobox const &),CParamCombobox__operator_equal);
#endif
#ifdef CParamPage__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamPage &  CParamPage::operator=(class CParamPage const &),CParamPage__operator_equal);
#endif
#ifdef CParamTabBox__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamTabBox &  CParamTabBox::operator=(class CParamTabBox const &),CParamTabBox__operator_equal);
#endif
#ifdef CParamScreen__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamScreen &  CParamScreen::operator=(class CParamScreen const &),CParamScreen__operator_equal);
#endif
#ifdef CParamSuiteDefaults__operator_equal_x
FUNCTION_AT_ADDRESS(class CParamSuiteDefaults &  CParamSuiteDefaults::operator=(class CParamSuiteDefaults const &),CParamSuiteDefaults__operator_equal);
#endif
#ifdef CParamClass__CParamClass_x
FUNCTION_AT_ADDRESS( CParamClass::CParamClass(void),CParamClass__CParamClass);
#endif
#ifdef CParamRGB__CParamRGB_x
FUNCTION_AT_ADDRESS( CParamRGB::CParamRGB(void),CParamRGB__CParamRGB);
#endif
#ifdef CParamPoint__CParamPoint_x
FUNCTION_AT_ADDRESS( CParamPoint::CParamPoint(void),CParamPoint__CParamPoint);
#endif
#ifdef CParamSize__CParamSize_x
FUNCTION_AT_ADDRESS( CParamSize::CParamSize(void),CParamSize__CParamSize);
#endif
#ifdef CParamTextureInfo__CParamTextureInfo_x
FUNCTION_AT_ADDRESS( CParamTextureInfo::CParamTextureInfo(void),CParamTextureInfo__CParamTextureInfo);
#endif
#ifdef CXMLSOMCursorSaveFast__dCXMLSOMCursorSaveFast_x
FUNCTION_AT_ADDRESS( CXMLSOMCursorSaveFast::~CXMLSOMCursorSaveFast(void),CXMLSOMCursorSaveFast__dCXMLSOMCursorSaveFast);
#endif
#ifdef CParamFrame__CParamFrame_x
FUNCTION_AT_ADDRESS( CParamFrame::CParamFrame(void),CParamFrame__CParamFrame);
#endif
#ifdef CParamUi2DAnimation__CParamUi2DAnimation_x
FUNCTION_AT_ADDRESS( CParamUi2DAnimation::CParamUi2DAnimation(void),CParamUi2DAnimation__CParamUi2DAnimation);
#endif
#ifdef CParamButtonDrawTemplate__CParamButtonDrawTemplate_x
FUNCTION_AT_ADDRESS( CParamButtonDrawTemplate::CParamButtonDrawTemplate(void),CParamButtonDrawTemplate__CParamButtonDrawTemplate);
#endif
#ifdef CParamGaugeDrawTemplate__CParamGaugeDrawTemplate_x
FUNCTION_AT_ADDRESS( CParamGaugeDrawTemplate::CParamGaugeDrawTemplate(void),CParamGaugeDrawTemplate__CParamGaugeDrawTemplate);
#endif
#ifdef CParamSpellGemDrawTemplate__CParamSpellGemDrawTemplate_x
FUNCTION_AT_ADDRESS( CParamSpellGemDrawTemplate::CParamSpellGemDrawTemplate(void),CParamSpellGemDrawTemplate__CParamSpellGemDrawTemplate);
#endif
#ifdef CParamFrameTemplate__CParamFrameTemplate_x
FUNCTION_AT_ADDRESS( CParamFrameTemplate::CParamFrameTemplate(void),CParamFrameTemplate__CParamFrameTemplate);
#endif
#ifdef CParamScrollbarDrawTemplate__CParamScrollbarDrawTemplate_x
FUNCTION_AT_ADDRESS( CParamScrollbarDrawTemplate::CParamScrollbarDrawTemplate(void),CParamScrollbarDrawTemplate__CParamScrollbarDrawTemplate);
#endif
#ifdef CParamWindowDrawTemplate__CParamWindowDrawTemplate_x
FUNCTION_AT_ADDRESS( CParamWindowDrawTemplate::CParamWindowDrawTemplate(void),CParamWindowDrawTemplate__CParamWindowDrawTemplate);
#endif
#ifdef CParamSliderDrawTemplate__CParamSliderDrawTemplate_x
FUNCTION_AT_ADDRESS( CParamSliderDrawTemplate::CParamSliderDrawTemplate(void),CParamSliderDrawTemplate__CParamSliderDrawTemplate);
#endif
#ifdef CParamScreenPiece__CParamScreenPiece_x
FUNCTION_AT_ADDRESS( CParamScreenPiece::CParamScreenPiece(void),CParamScreenPiece__CParamScreenPiece);
#endif
#ifdef CParamStaticScreenPiece__CParamStaticScreenPiece_x
FUNCTION_AT_ADDRESS( CParamStaticScreenPiece::CParamStaticScreenPiece(void),CParamStaticScreenPiece__CParamStaticScreenPiece);
#endif
#ifdef CParamStaticAnimation__CParamStaticAnimation_x
FUNCTION_AT_ADDRESS( CParamStaticAnimation::CParamStaticAnimation(void),CParamStaticAnimation__CParamStaticAnimation);
#endif
#ifdef CParamStaticText__CParamStaticText_x
FUNCTION_AT_ADDRESS( CParamStaticText::CParamStaticText(void),CParamStaticText__CParamStaticText);
#endif
#ifdef CParamStaticFrame__CParamStaticFrame_x
FUNCTION_AT_ADDRESS( CParamStaticFrame::CParamStaticFrame(void),CParamStaticFrame__CParamStaticFrame);
#endif
#ifdef CParamStaticHeader__CParamStaticHeader_x
FUNCTION_AT_ADDRESS( CParamStaticHeader::CParamStaticHeader(void),CParamStaticHeader__CParamStaticHeader);
#endif
#ifdef CParamControl__CParamControl_x
FUNCTION_AT_ADDRESS( CParamControl::CParamControl(void),CParamControl__CParamControl);
#endif
#ifdef CParamListboxColumn__CParamListboxColumn_x
FUNCTION_AT_ADDRESS( CParamListboxColumn::CParamListboxColumn(void),CParamListboxColumn__CParamListboxColumn);
#endif
#ifdef CParamListbox__CParamListbox_x
FUNCTION_AT_ADDRESS( CParamListbox::CParamListbox(void),CParamListbox__CParamListbox);
#endif
#ifdef CParamButton__CParamButton_x
FUNCTION_AT_ADDRESS( CParamButton::CParamButton(void),CParamButton__CParamButton);
#endif
#ifdef CParamGauge__CParamGauge_x
FUNCTION_AT_ADDRESS( CParamGauge::CParamGauge(void),CParamGauge__CParamGauge);
#endif
#ifdef CParamSpellGem__CParamSpellGem_x
FUNCTION_AT_ADDRESS( CParamSpellGem::CParamSpellGem(void),CParamSpellGem__CParamSpellGem);
#endif
#ifdef CParamInvSlot__CParamInvSlot_x
FUNCTION_AT_ADDRESS( CParamInvSlot::CParamInvSlot(void),CParamInvSlot__CParamInvSlot);
#endif
#ifdef CParamEditbox__CParamEditbox_x
FUNCTION_AT_ADDRESS( CParamEditbox::CParamEditbox(void),CParamEditbox__CParamEditbox);
#endif
#ifdef CParamSlider__CParamSlider_x
FUNCTION_AT_ADDRESS( CParamSlider::CParamSlider(void),CParamSlider__CParamSlider);
#endif
#ifdef CParamLabel__CParamLabel_x
FUNCTION_AT_ADDRESS( CParamLabel::CParamLabel(void),CParamLabel__CParamLabel);
#endif
#ifdef CParamSTMLbox__CParamSTMLbox_x
FUNCTION_AT_ADDRESS( CParamSTMLbox::CParamSTMLbox(void),CParamSTMLbox__CParamSTMLbox);
#endif
#ifdef CParamCombobox__CParamCombobox_x
FUNCTION_AT_ADDRESS( CParamCombobox::CParamCombobox(void),CParamCombobox__CParamCombobox);
#endif
#ifdef CParamPage__CParamPage_x
FUNCTION_AT_ADDRESS( CParamPage::CParamPage(void),CParamPage__CParamPage);
#endif
#ifdef CParamTabBox__CParamTabBox_x
FUNCTION_AT_ADDRESS( CParamTabBox::CParamTabBox(void),CParamTabBox__CParamTabBox);
#endif
#ifdef CParamScreen__CParamScreen_x
FUNCTION_AT_ADDRESS( CParamScreen::CParamScreen(void),CParamScreen__CParamScreen);
#endif
#ifdef CParamSuiteDefaults__CParamSuiteDefaults_x
FUNCTION_AT_ADDRESS( CParamSuiteDefaults::CParamSuiteDefaults(void),CParamSuiteDefaults__CParamSuiteDefaults);
#endif
#ifdef CXMLData__CXMLData_x
FUNCTION_AT_ADDRESS( CXMLData::CXMLData(void),CXMLData__CXMLData);
#endif
#ifdef CPageWnd__CPageWnd_x
FUNCTION_AT_ADDRESS( CPageWnd::CPageWnd(class CXWnd *,unsigned __int32,class CXRect,class CXStr,class CPageTemplate *),CPageWnd__CPageWnd);
#endif
#ifdef CGaugeWnd__CGaugeWnd_x
FUNCTION_AT_ADDRESS( CGaugeWnd::CGaugeWnd(class CXWnd *,unsigned __int32,class CXRect,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,int,unsigned long,unsigned long,bool,int,int,int,int),CGaugeWnd__CGaugeWnd);
#endif
#ifdef CGaugeWnd__CalcFillRect_x
FUNCTION_AT_ADDRESS(class CXRect  CGaugeWnd::CalcFillRect(class CXRect *,int)const ,CGaugeWnd__CalcFillRect);
#endif
#ifdef CGaugeWnd__CalcLinesFillRect_x
FUNCTION_AT_ADDRESS(class CXRect  CGaugeWnd::CalcLinesFillRect(class CXRect *,int)const ,CGaugeWnd__CalcLinesFillRect);
#endif
#ifdef CGaugeWnd__SpecialToolTip_x
FUNCTION_AT_ADDRESS(void  CGaugeWnd::SpecialToolTip(void),CGaugeWnd__SpecialToolTip);
#endif
#ifdef CCheckBoxWnd__CCheckBoxWnd_x
FUNCTION_AT_ADDRESS( CCheckBoxWnd::CCheckBoxWnd(class CXWnd *,unsigned __int32,class CXRect,class CXPoint,class CXSize,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *),CCheckBoxWnd__CCheckBoxWnd);
#endif
#ifdef CCheckBoxWnd__SetRadioLook_x
FUNCTION_AT_ADDRESS(void  CCheckBoxWnd::SetRadioLook(void),CCheckBoxWnd__SetRadioLook);
#endif
#ifdef CIMEStatusBar__CIMEStatusBar_x
FUNCTION_AT_ADDRESS( CIMEStatusBar::CIMEStatusBar(class CIMEManager *),CIMEStatusBar__CIMEStatusBar);
#endif
#ifdef CIMEStatusBar__show_x
FUNCTION_AT_ADDRESS(int  CIMEStatusBar::show(class CIMEComposition const *),CIMEStatusBar__show);
#endif
#ifdef CIMEStatusBar__update_x
FUNCTION_AT_ADDRESS(int  CIMEStatusBar::update(void),CIMEStatusBar__update);
#endif
#ifdef CIMEStatusBar__hide_x
FUNCTION_AT_ADDRESS(int  CIMEStatusBar::hide(void),CIMEStatusBar__hide);
#endif
#ifdef CIMEStatusBar__handleChineseSimplifiedStatusChange_x
FUNCTION_AT_ADDRESS(void  CIMEStatusBar::handleChineseSimplifiedStatusChange(unsigned long),CIMEStatusBar__handleChineseSimplifiedStatusChange);
#endif
#ifdef CIMEStatusBar__handleChineseTraditionalStatusChange_x
FUNCTION_AT_ADDRESS(void  CIMEStatusBar::handleChineseTraditionalStatusChange(unsigned long),CIMEStatusBar__handleChineseTraditionalStatusChange);
#endif
#ifdef CIMEStatusBar__handleJapaneseStatusChange_x
FUNCTION_AT_ADDRESS(void  CIMEStatusBar::handleJapaneseStatusChange(unsigned long),CIMEStatusBar__handleJapaneseStatusChange);
#endif
#ifdef CIMEStatusBar__handleKoreanStatusChange_x
FUNCTION_AT_ADDRESS(void  CIMEStatusBar::handleKoreanStatusChange(unsigned long),CIMEStatusBar__handleKoreanStatusChange);
#endif
#ifdef CIMEStatusBar__repositionStatusWindow_x
FUNCTION_AT_ADDRESS(int  CIMEStatusBar::repositionStatusWindow(void),CIMEStatusBar__repositionStatusWindow);
#endif
#ifdef CIMECandidateList__CIMECandidateList_x
FUNCTION_AT_ADDRESS( CIMECandidateList::CIMECandidateList(class CIMEManager *),CIMECandidateList__CIMECandidateList);
#endif
#ifdef CIMECandidateList__show_x
FUNCTION_AT_ADDRESS(int  CIMECandidateList::show(class CIMEComposition const *)const ,CIMECandidateList__show);
#endif
#ifdef CIMECandidateList__repositionImeCandidateList_x
FUNCTION_AT_ADDRESS(int  CIMECandidateList::repositionImeCandidateList(int,int)const ,CIMECandidateList__repositionImeCandidateList);
#endif
#ifdef CIMEComposition__CIMEComposition_x
FUNCTION_AT_ADDRESS( CIMEComposition::CIMEComposition(class CIMEManager *),CIMEComposition__CIMEComposition);
#endif
#ifdef CIMEComposition__dCIMEComposition_x
FUNCTION_AT_ADDRESS( CIMEComposition::~CIMEComposition(void),CIMEComposition__dCIMEComposition);
#endif
#ifdef CIMEComposition__addInputChar_x
FUNCTION_AT_ADDRESS(int  CIMEComposition::addInputChar(unsigned short),CIMEComposition__addInputChar);
#endif
#ifdef CIMEComposition__addInputString_x
FUNCTION_AT_ADDRESS(int  CIMEComposition::addInputString(unsigned short *,int),CIMEComposition__addInputString);
#endif
#ifdef CIMEComposition__addInputString1_x
FUNCTION_AT_ADDRESS(int  CIMEComposition::addInputString(class CXStr const &,int),CIMEComposition__addInputString1);
#endif
#ifdef CIMEComposition__addStringFromIme_x
FUNCTION_AT_ADDRESS(int  CIMEComposition::addStringFromIme(long),CIMEComposition__addStringFromIme);
#endif
#ifdef CIMEComposition__directToEditWnd_x
FUNCTION_AT_ADDRESS(void  CIMEComposition::directToEditWnd(class CEditWnd *),CIMEComposition__directToEditWnd);
#endif
#ifdef CIMEComposition__getCursorPoint_x
FUNCTION_AT_ADDRESS(class CXPoint  CIMEComposition::getCursorPoint(void)const ,CIMEComposition__getCursorPoint);
#endif
#ifdef CIMEComposition__getCompositionArea_x
FUNCTION_AT_ADDRESS(class CXRect  CIMEComposition::getCompositionArea(void)const ,CIMEComposition__getCompositionArea);
#endif
#ifdef CIMEComposition__repositionImeCompositionWindow_x
FUNCTION_AT_ADDRESS(int  CIMEComposition::repositionImeCompositionWindow(int,int)const ,CIMEComposition__repositionImeCompositionWindow);
#endif
#ifdef CIMEComposition__allocateImeCompositionString_x
FUNCTION_AT_ADDRESS(unsigned short *  CIMEComposition::allocateImeCompositionString(long)const ,CIMEComposition__allocateImeCompositionString);
#endif
#ifdef CIMEComposition__allocateImeCompositionAttributes_x
FUNCTION_AT_ADDRESS(struct CompAttr *  CIMEComposition::allocateImeCompositionAttributes(void)const ,CIMEComposition__allocateImeCompositionAttributes);
#endif
#ifdef CIMEComposition__getCompositionInsertIndex_x
FUNCTION_AT_ADDRESS(int  CIMEComposition::getCompositionInsertIndex(void)const ,CIMEComposition__getCompositionInsertIndex);
#endif
#ifdef CIMEComposition__handleImeComposing_x
FUNCTION_AT_ADDRESS(int  CIMEComposition::handleImeComposing(void),CIMEComposition__handleImeComposing);
#endif
#ifdef CIMEComposition__applyJapaneseComposingRules_x
FUNCTION_AT_ADDRESS(int  CIMEComposition::applyJapaneseComposingRules(class CXStr *),CIMEComposition__applyJapaneseComposingRules);
#endif
#ifdef CIMEComposition__applyChineseComposingRules_x
FUNCTION_AT_ADDRESS(int  CIMEComposition::applyChineseComposingRules(class CXStr *),CIMEComposition__applyChineseComposingRules);
#endif
#ifdef CIMEComposition__applyKoreanComposingRules_x
FUNCTION_AT_ADDRESS(int  CIMEComposition::applyKoreanComposingRules(class CXStr *),CIMEComposition__applyKoreanComposingRules);
#endif
#ifdef CIMEComposition__addCompositionHighlights_x
FUNCTION_AT_ADDRESS(int  CIMEComposition::addCompositionHighlights(void),CIMEComposition__addCompositionHighlights);
#endif
#ifdef CIMEComposition__handleImeResult_x
FUNCTION_AT_ADDRESS(int  CIMEComposition::handleImeResult(void),CIMEComposition__handleImeResult);
#endif
#ifdef CIMEComposition__backupCurrentText_x
FUNCTION_AT_ADDRESS(void  CIMEComposition::backupCurrentText(void),CIMEComposition__backupCurrentText);
#endif
#ifdef CIMEComposition__revertToBackupText_x
FUNCTION_AT_ADDRESS(void  CIMEComposition::revertToBackupText(void),CIMEComposition__revertToBackupText);
#endif
#ifdef CMemoryStream__GetStringSize_x
FUNCTION_AT_ADDRESS(int __cdecl CMemoryStream::GetStringSize(class CXStr &),CMemoryStream__GetStringSize);
#endif
#ifdef CMemoryStream__PutString_x
FUNCTION_AT_ADDRESS(void  CMemoryStream::PutString(class CXStr &),CMemoryStream__PutString);
#endif
#ifdef CMemoryStream__GetString1_x
FUNCTION_AT_ADDRESS(class CXStr  CMemoryStream::GetString(void),CMemoryStream__GetString1);
#endif
#ifdef CXMLSOMDocument__GetValueObjectId_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocument::GetValueObjectId(class CXStr,class CXStr,unsigned __int32 &),CXMLSOMDocument__GetValueObjectId);
#endif
#ifdef CXMLSOMDocument__SetValueObjectId_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocument::SetValueObjectId(class CXStr,class CXStr,unsigned __int32),CXMLSOMDocument__SetValueObjectId);
#endif
#ifdef CXMLSOMDocument__FieldParseItemOfClass_x
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocument::FieldParseItemOfClass(class CXStr,class CXStr,unsigned __int32 &),CXMLSOMDocument__FieldParseItemOfClass);
#endif
#ifdef EQOldPlayerAnimation__mAnimationPrefix_x
FUNCTION_AT_ADDRESS(char (* EQOldPlayerAnimation::mAnimationPrefix)[20],EQOldPlayerAnimation__mAnimationPrefix);
#endif
#ifdef CTextOverlay__DisplayText_x
FUNCTION_AT_ADDRESS(void CTextOverlay::DisplayText(char *,int,int,int,int,int,int),CTextOverlay__DisplayText);
#endif
#ifdef CDBStr__GetString_x
// GetString(index, subindex, &success)
FUNCTION_AT_ADDRESS(char *CDBStr::GetString(int, int, int *), CDBStr__GetString);
#endif
#ifdef EQMisc__GetActiveFavorCost_x
FUNCTION_AT_ADDRESS(int EQMisc::GetActiveFavorCost(void),EQMisc__GetActiveFavorCost);
#endif
#ifdef CSkillMgr__GetNameToken_x
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::GetNameToken(int),CSkillMgr__GetNameToken);
#endif
#ifdef CSkillMgr__IsCombatSkill_x
FUNCTION_AT_ADDRESS(bool CSkillMgr::IsCombatSkill(int),CSkillMgr__IsCombatSkill);
#endif
#ifdef CSkillMgr__GetSkillCap_x
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::GetSkillCap(class EQ_Character *,int,int,int,bool,bool,bool),CSkillMgr__GetSkillCap)
#endif
#ifdef CSkillMgr__SkillAvailableAtLevel_x
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::SkillAvailableAtLevel(int,int),CSkillMgr__SkillAvailableAtLevel);
#endif
#ifdef CSkillMgr__IsActivatedSkill_x
FUNCTION_AT_ADDRESS(bool CSkillMgr::IsActivatedSkill(int),CSkillMgr__IsActivatedSkill);
#endif
#ifdef CSkillMgr__GetBaseDamage_x
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::GetBaseDamage(int),CSkillMgr__GetBaseDamage);
#endif
#ifdef CSkillMgr__GetReuseTime_x
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::GetReuseTime(int),CSkillMgr__GetReuseTime);
#endif
#ifdef CSkillMgr__IsAvailable_x
FUNCTION_AT_ADDRESS(bool CSkillMgr::IsAvailable(int),CSkillMgr__IsAvailable);
#endif
#ifdef CChatService__GetNumberOfFriends_x
FUNCTION_AT_ADDRESS(int CChatService::GetNumberOfFriends(void),CChatService__GetNumberOfFriends);
#endif
#ifdef CChatService__GetFriendName_x
FUNCTION_AT_ADDRESS(char *CChatService::GetFriendName(int),CChatService__GetFriendName);
#endif
#ifdef PlayerPointManager__GetAltCurrency_x
FUNCTION_AT_ADDRESS(unsigned long PlayerPointManager::GetAltCurrency(unsigned long,unsigned long),PlayerPointManager__GetAltCurrency);
#endif
#ifdef CharacterZoneClient__CharacterZoneClient_x
FUNCTION_AT_ADDRESS(CharacterZoneClient::CharacterZoneClient(void), CharacterZoneClient__CharacterZoneClient);
#endif
#ifdef CharacterZoneClient__HasSkill_x
FUNCTION_AT_ADDRESS(bool CharacterZoneClient::HasSkill(int), CharacterZoneClient__HasSkill);
#endif
#ifdef CharacterZoneClient__MakeMeVisible_x
FUNCTION_AT_ADDRESS(void  CharacterZoneClient::MakeMeVisible(int,bool),CharacterZoneClient__MakeMeVisible);
#endif
#ifdef CharacterZoneClient__GetItemCountWorn_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetItemCountWorn(int),CharacterZoneClient__GetItemCountWorn);
#endif
#ifdef CharacterZoneClient__GetItemCountInInventory_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetItemCountInInventory(int),CharacterZoneClient__GetItemCountInInventory);
#endif
#ifdef CharacterZoneClient__GetCursorItemCount_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetCursorItemCount(int),CharacterZoneClient__GetCursorItemCount);
#endif
#ifdef CharacterZoneClient__ApplyDamage_x
FUNCTION_AT_ADDRESS(int  CharacterZoneClient::ApplyDamage(int,int,int,int,int,int),CharacterZoneClient__ApplyDamage);
#endif
#ifdef PcZoneClient__GetPcSkillLimit_x
FUNCTION_AT_ADDRESS(int PcZoneClient::GetPcSkillLimit(int), PcZoneClient__GetPcSkillLimit);
#endif
#ifdef PcZoneClient__HasCombatAbility_x
FUNCTION_AT_ADDRESS(bool PcZoneClient::HasCombatAbility(int), PcZoneClient__HasCombatAbility);
#endif
#ifdef PcZoneClient__RemovePetEffect_x
FUNCTION_AT_ADDRESS(void PcZoneClient::RemovePetEffect(int), PcZoneClient__RemovePetEffect);
#endif
#ifdef PcZoneClient__HasAlternateAbility_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(bool PcZoneClient::HasAlternateAbility(int aaindex, int *, bool, bool), PcZoneClient__HasAlternateAbility);
#else
FUNCTION_AT_ADDRESS(bool PcZoneClient::HasAlternateAbility(int aaindex, int *, bool), PcZoneClient__HasAlternateAbility);
#endif
#endif
#ifdef PcZoneClient__GetItemByID_x
FUNCTION_AT_ADDRESS(PCONTENTS * PcZoneClient::GetItemByID(PCONTENTS *contOut, int itemid, ItemIndex */*out*/), PcZoneClient__GetItemByID);
#endif
#ifdef PcZoneClient__GetItemByItemClass_x
FUNCTION_AT_ADDRESS(PCONTENTS * PcZoneClient::GetItemByItemClass(PCONTENTS *contOut, int itemclass, ItemIndex */*out*/), PcZoneClient__GetItemByItemClass);
#endif
#ifdef PcZoneClient__CanEquipItem_x
FUNCTION_AT_ADDRESS(bool PcZoneClient::CanEquipItem(PCONTENTS *pCont, int slotid, bool bOutputDebug, bool bUseRequiredLevel), PcZoneClient__CanEquipItem);
#endif
#ifdef PcZoneClient__GetCurrentMod_x
FUNCTION_AT_ADDRESS(int PcZoneClient::GetCurrentMod(int index), PcZoneClient__GetCurrentMod);
#endif
#ifdef PcZoneClient__GetModCap_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(int PcZoneClient::GetModCap(int index, bool bToggle), PcZoneClient__GetModCap);
#else
FUNCTION_AT_ADDRESS(int PcZoneClient::GetModCap(int index), PcZoneClient__GetModCap);
#endif
#endif
#ifdef PcZoneClient__RemoveBuffEffect_x
FUNCTION_AT_ADDRESS(void PcZoneClient::RemoveBuffEffect(int Index, int SpawnID), PcZoneClient__RemoveBuffEffect);
#endif
#ifdef PcZoneClient__BandolierSwap_x
FUNCTION_AT_ADDRESS(void PcZoneClient::BandolierSwap(int index), PcZoneClient__BandolierSwap);
#endif
#ifdef PcZoneClient__GetLinkedSpellReuseTimer_x
FUNCTION_AT_ADDRESS(UINT PcZoneClient::GetLinkedSpellReuseTimer(int index), PcZoneClient__GetLinkedSpellReuseTimer);
#endif
#ifdef CXWnd__SetFont_x
FUNCTION_AT_ADDRESS(int CXWnd::SetFont(void*), CXWnd__SetFont);
#endif
#ifdef CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x
FUNCTION_AT_ADDRESS(CCollisionInfoTargetVisibility::CCollisionInfoTargetVisibility(class CLineSegment *, class EQPlayer *, class EQPlayer *), CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility);
#endif
#ifdef EQSpellStrings__GetString_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(char* EQSpellStrings::GetString(int SpellID, int StrIndex), EQSpellStrings__GetString);
#endif
#endif
#pragma warning( pop )
