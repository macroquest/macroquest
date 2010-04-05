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
        if (GetCXStr(pXMLData->Name.Ptr,Buffer,MAX_STRING) && !stricmp(Buffer,Name)) {
            return pWnd;
        }
        //DebugSpew("RecurseAndFindName looking for %s but found %s", Name, Buffer);
        if (GetCXStr(pXMLData->ScreenID.Ptr,Buffer,MAX_STRING) && !stricmp(Buffer,Name)) {
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

int  CListWnd::AddString(char *p1, unsigned long p2, unsigned __int32 p3, class CTextureAnimation const *p4, const char* p5)
{
    return AddString(&CXStr(p1), p2, p3, p4);
}

// MANUAL IMPORTS
#ifdef CMyInventory__GetSlot
FUNCTION_AT_ADDRESS(struct  _CONTENTS* CMyInventory::GetSlot(int), CMyInventory__GetSlot);
#endif

#ifdef EQ_Item__GetItemLinkHash
FUNCTION_AT_ADDRESS(char * EQ_Item::GetItemLinkHash(char *, int),EQ_Item__GetItemLinkHash); // Lax 11-14-2003
#endif
#ifdef CStmlWnd__AppendSTML
FUNCTION_AT_ADDRESS(class CXSize& CStmlWnd::AppendSTML(class CXSize*,class CXStr),CStmlWnd__AppendSTML);
#endif
#ifdef EQ_Item__CanDrop
FUNCTION_AT_ADDRESS(int EQ_Item::CanDrop(int),EQ_Item__CanDrop); // Lax 4-21-2004
#endif

///////////////////////////////////////////////////////////////////
// gah, i hate sony
#ifdef EQ_Character__Max_Endurance
FUNCTION_AT_ADDRESS(int  EQ_Character1::Max_Endurance(int),EQ_Character__Max_Endurance);
#endif
//fuck virtual
#ifdef EQ_Character__Max_Mana 
FUNCTION_AT_ADDRESS(int EQ_Character1::Max_Mana(int), EQ_Character__Max_Mana);
#endif 
#ifdef EQ_Character__Max_HP
FUNCTION_AT_ADDRESS(int  EQ_Character1::Max_HP(int,int),EQ_Character__Max_HP);
#endif
/////////////////////////////////////////////////////////////////////

#ifdef EQ_Character__doCombatAbility 
FUNCTION_AT_ADDRESS(void EQ_Character::DoCombatAbility(int spellID), EQ_Character__doCombatAbility); 
#endif 


FUNCTION_AT_VIRTUAL_ADDRESS(void CChatWindow::operator delete[](void*),0x04);

FUNCTION_AT_VIRTUAL_ADDRESS(bool CXWnd::IsValid(void)const,0);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::WndNotification(class CXWnd *,unsigned __int32,void *),0x84);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::OnResize(int,int),0x098);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::Show(bool,bool),0x0C8);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::SetVScrollPos(int),0x120);
FUNCTION_AT_VIRTUAL_ADDRESS(void CXWnd::SetWindowTextA(class CXStr &),0x118);

FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleLButtonDown(class CXPoint *,unsigned __int32),0x34);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleLButtonUp(class CXPoint *,unsigned __int32),0x38);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleLButtonHeld(class CXPoint *,unsigned __int32),0x3C);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleLButtonUpAfterHeld(class CXPoint *,unsigned __int32),0x40);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleRButtonDown(class CXPoint *,unsigned __int32),0x44);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleRButtonUp(class CXPoint *,unsigned __int32),0x48);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleRButtonHeld(class CXPoint *,unsigned __int32),0x4C);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleRButtonUpAfterHeld(class CXPoint *,unsigned __int32),0x50);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::OnMinimizeBox(void),0x9c);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::SetFont(void*),0x114);


FUNCTION_AT_VIRTUAL_ADDRESS(void CListWnd::DeleteAll(void),0x15c);


// AUTO IMPORTS

#ifdef CAAWnd__CAAWnd
FUNCTION_AT_ADDRESS( CAAWnd::CAAWnd(class CXWnd *),CAAWnd__CAAWnd);
#endif
#ifdef CAAWnd__Update
FUNCTION_AT_ADDRESS(void  CAAWnd::Update(void),CAAWnd__Update);
#endif
#ifdef CAAWnd__UpdateSelected
FUNCTION_AT_ADDRESS(void  CAAWnd::UpdateSelected(void),CAAWnd__UpdateSelected);
#endif
#ifdef CAAWnd__UpdateTimer
FUNCTION_AT_ADDRESS(void  CAAWnd::UpdateTimer(void),CAAWnd__UpdateTimer);
#endif
#ifdef CAAWnd__Init
FUNCTION_AT_ADDRESS(void  CAAWnd::Init(void),CAAWnd__Init);
#endif
#ifdef CAAWnd__Activate
FUNCTION_AT_ADDRESS(void  CAAWnd::Activate(void),CAAWnd__Activate);
#endif
#ifdef CAAWnd__ShowAbility
FUNCTION_AT_ADDRESS(void  CAAWnd::ShowAbility(int),CAAWnd__ShowAbility);
#endif
#ifdef CAAWnd__SendNewPercent
FUNCTION_AT_ADDRESS(void  CAAWnd::SendNewPercent(void),CAAWnd__SendNewPercent);
#endif
#ifdef CAAWnd__ConfirmAASpend
FUNCTION_AT_ADDRESS(void  CAAWnd::ConfirmAASpend(void),CAAWnd__ConfirmAASpend);
#endif
#ifdef CXStr__CXStr
FUNCTION_AT_ADDRESS( CXStr::CXStr(class CXStr const &),CXStr__CXStr);
#endif
#ifdef CXMLSOMCursor__dCXMLSOMCursor
FUNCTION_AT_ADDRESS( CXMLSOMCursor::~CXMLSOMCursor(void),CXMLSOMCursor__dCXMLSOMCursor);
#endif
#ifdef CKeyCXStrValueInt32__dCKeyCXStrValueInt32
FUNCTION_AT_ADDRESS( CKeyCXStrValueInt32::~CKeyCXStrValueInt32(void),CKeyCXStrValueInt32__dCKeyCXStrValueInt32);
#endif
#ifdef COptionsWnd__KeyboardAssignmentData__dKeyboardAssignmentData
//FUNCTION_AT_ADDRESS( COptionsWnd::KeyboardAssignmentData::~KeyboardAssignmentData(void),COptionsWnd__KeyboardAssignmentData__dKeyboardAssignmentData);
#endif
#ifdef CXStr__dCXStr
FUNCTION_AT_ADDRESS( CXStr::~CXStr(void),CXStr__dCXStr);
#endif
#ifdef CUITextureInfo__CUITextureInfo
FUNCTION_AT_ADDRESS( CUITextureInfo::CUITextureInfo(class CXStr,int),CUITextureInfo__CUITextureInfo);
#endif
#ifdef CXMLSOMNodePtr__dCXMLSOMNodePtr
FUNCTION_AT_ADDRESS( CXMLSOMNodePtr::~CXMLSOMNodePtr(void),CXMLSOMNodePtr__dCXMLSOMNodePtr);
#endif
#ifdef CXMLSOMNode__dCXMLSOMNode
FUNCTION_AT_ADDRESS( CXMLSOMNode::~CXMLSOMNode(void),CXMLSOMNode__dCXMLSOMNode);
#endif
#ifdef CXMLSOMAttribute__dCXMLSOMAttribute
FUNCTION_AT_ADDRESS( CXMLSOMAttribute::~CXMLSOMAttribute(void),CXMLSOMAttribute__dCXMLSOMAttribute);
#endif
#ifdef CActionsWnd__CActionsWnd
FUNCTION_AT_ADDRESS( CActionsWnd::CActionsWnd(class CXWnd *),CActionsWnd__CActionsWnd);
#endif
#ifdef CActionsWnd__Activate
FUNCTION_AT_ADDRESS(void  CActionsWnd::Activate(int),CActionsWnd__Activate);
#endif
#ifdef CActionsWnd__UpdateButtonText
FUNCTION_AT_ADDRESS(void  CActionsWnd::UpdateButtonText(void),CActionsWnd__UpdateButtonText);
#endif
#ifdef CActionsWnd__GetCurrentPageEnum
FUNCTION_AT_ADDRESS(int  CActionsWnd::GetCurrentPageEnum(void)const ,CActionsWnd__GetCurrentPageEnum);
#endif
#ifdef CActionsWnd__KeyMapUpdated
FUNCTION_AT_ADDRESS(void  CActionsWnd::KeyMapUpdated(void),CActionsWnd__KeyMapUpdated);
#endif
#ifdef CActionsWnd__SelectSkillForAbilityBtn
FUNCTION_AT_ADDRESS(void  CActionsWnd::SelectSkillForAbilityBtn(int),CActionsWnd__SelectSkillForAbilityBtn);
#endif
#ifdef CActionsWnd__GetAbilityBtn
FUNCTION_AT_ADDRESS(class CButtonWnd *  CActionsWnd::GetAbilityBtn(int),CActionsWnd__GetAbilityBtn);
#endif
#ifdef CActionsWnd__SelectSkillForCombatBtn
FUNCTION_AT_ADDRESS(void  CActionsWnd::SelectSkillForCombatBtn(int),CActionsWnd__SelectSkillForCombatBtn);
#endif
#ifdef CActionsWnd__GetCombatBtn
FUNCTION_AT_ADDRESS(class CButtonWnd *  CActionsWnd::GetCombatBtn(int),CActionsWnd__GetCombatBtn);
#endif
#ifdef CActionsWnd__GetMenuBtn
FUNCTION_AT_ADDRESS(class CButtonWnd *  CActionsWnd::GetMenuBtn(int),CActionsWnd__GetMenuBtn);
#endif
#ifdef CActionsWnd__RedirectActivateTo
FUNCTION_AT_ADDRESS(int  CActionsWnd::RedirectActivateTo(class CPageWnd *),CActionsWnd__RedirectActivateTo);
#endif
#ifdef CActionsWnd__RedirectDeactivateTo
FUNCTION_AT_ADDRESS(int  CActionsWnd::RedirectDeactivateTo(class CPageWnd *),CActionsWnd__RedirectDeactivateTo);
#endif
#ifdef CActionsWnd__RedirectOnProcessFrameTo
FUNCTION_AT_ADDRESS(int  CActionsWnd::RedirectOnProcessFrameTo(class CPageWnd *),CActionsWnd__RedirectOnProcessFrameTo);
#endif
#ifdef CActionsWnd__RedirectWndNotificationTo
FUNCTION_AT_ADDRESS(int  CActionsWnd::RedirectWndNotificationTo(class CPageWnd *,class CXWnd *,unsigned __int32,void *),CActionsWnd__RedirectWndNotificationTo);
#endif
#ifdef CActionsWnd__MainPageOnProcessFrame
FUNCTION_AT_ADDRESS(int  CActionsWnd::MainPageOnProcessFrame(void),CActionsWnd__MainPageOnProcessFrame);
#endif
#ifdef CActionsWnd__MainPageWndNotification
FUNCTION_AT_ADDRESS(int  CActionsWnd::MainPageWndNotification(class CXWnd *,unsigned __int32,void *),CActionsWnd__MainPageWndNotification);
#endif
#ifdef CActionsWnd__AbilitiesPageActivate
FUNCTION_AT_ADDRESS(int  CActionsWnd::AbilitiesPageActivate(void),CActionsWnd__AbilitiesPageActivate);
#endif
#ifdef CActionsWnd__AbilitiesPageDeactivate
FUNCTION_AT_ADDRESS(int  CActionsWnd::AbilitiesPageDeactivate(void),CActionsWnd__AbilitiesPageDeactivate);
#endif
#ifdef CActionsWnd__AbilitiesPageOnProcessFrame
FUNCTION_AT_ADDRESS(int  CActionsWnd::AbilitiesPageOnProcessFrame(void),CActionsWnd__AbilitiesPageOnProcessFrame);
#endif
#ifdef CActionsWnd__AbilitiesPageWndNotification
FUNCTION_AT_ADDRESS(int  CActionsWnd::AbilitiesPageWndNotification(class CXWnd *,unsigned __int32,void *),CActionsWnd__AbilitiesPageWndNotification);
#endif
#ifdef CActionsWnd__CombatPageActivate
FUNCTION_AT_ADDRESS(int  CActionsWnd::CombatPageActivate(void),CActionsWnd__CombatPageActivate);
#endif
#ifdef CActionsWnd__CombatPageDeactivate
FUNCTION_AT_ADDRESS(int  CActionsWnd::CombatPageDeactivate(void),CActionsWnd__CombatPageDeactivate);
#endif
#ifdef CActionsWnd__CombatPageOnProcessFrame
FUNCTION_AT_ADDRESS(int  CActionsWnd::CombatPageOnProcessFrame(void),CActionsWnd__CombatPageOnProcessFrame);
#endif
#ifdef CActionsWnd__CombatPageWndNotification
FUNCTION_AT_ADDRESS(int  CActionsWnd::CombatPageWndNotification(class CXWnd *,unsigned __int32,void *),CActionsWnd__CombatPageWndNotification);
#endif
#ifdef CActionsWnd__SocialsPageActivate
FUNCTION_AT_ADDRESS(int  CActionsWnd::SocialsPageActivate(void),CActionsWnd__SocialsPageActivate);
#endif
#ifdef CActionsWnd__SocialsPageOnProcessFrame
FUNCTION_AT_ADDRESS(int  CActionsWnd::SocialsPageOnProcessFrame(void),CActionsWnd__SocialsPageOnProcessFrame);
#endif
#ifdef CActionsWnd__SocialsPageWndNotification
FUNCTION_AT_ADDRESS(int  CActionsWnd::SocialsPageWndNotification(class CXWnd *,unsigned __int32,void *),CActionsWnd__SocialsPageWndNotification);
#endif
#ifdef CAlarmWnd__CAlarmWnd
FUNCTION_AT_ADDRESS( CAlarmWnd::CAlarmWnd(class CXWnd *),CAlarmWnd__CAlarmWnd);
#endif
#ifdef CAlarmWnd__Activate
FUNCTION_AT_ADDRESS(void  CAlarmWnd::Activate(void),CAlarmWnd__Activate);
#endif
#ifdef CAlarmWnd__DoNeverButton
FUNCTION_AT_ADDRESS(void  CAlarmWnd::DoNeverButton(void),CAlarmWnd__DoNeverButton);
#endif
#ifdef CEditBaseWnd__SetMaxChars
FUNCTION_AT_ADDRESS(void  CEditBaseWnd::SetMaxChars(int),CEditBaseWnd__SetMaxChars);
#endif
#ifdef CBankWnd__CBankWnd
FUNCTION_AT_ADDRESS( CBankWnd::CBankWnd(class CXWnd *,class CXStr),CBankWnd__CBankWnd);
#endif
#ifdef CBankWnd__Init
FUNCTION_AT_ADDRESS(void  CBankWnd::Init(void),CBankWnd__Init);
#endif
#ifdef CBankWnd__Activate
FUNCTION_AT_ADDRESS(void  CBankWnd::Activate(class EQPlayer *),CBankWnd__Activate);
#endif
#ifdef CBankWnd__Deactivate
FUNCTION_AT_ADDRESS(void  CBankWnd::Deactivate(bool),CBankWnd__Deactivate);
#endif
#ifdef CBankWnd__ClickedMoneyButton
FUNCTION_AT_ADDRESS(void  CBankWnd::ClickedMoneyButton(int,int),CBankWnd__ClickedMoneyButton);
#endif
#ifdef CBankWnd__GetBankQtyFromCoinType
FUNCTION_AT_ADDRESS(long  CBankWnd::GetBankQtyFromCoinType(int),CBankWnd__GetBankQtyFromCoinType);
#endif
#ifdef CBankWnd__UpdateMoneyDisplay
FUNCTION_AT_ADDRESS(void  CBankWnd::UpdateMoneyDisplay(void),CBankWnd__UpdateMoneyDisplay);
#endif
#ifdef CBankWnd__GetNumBankSlots
FUNCTION_AT_ADDRESS(int  CBankWnd::GetNumBankSlots(void)const ,CBankWnd__GetNumBankSlots);
#endif
#ifdef CXRect__CenterPoint
FUNCTION_AT_ADDRESS(class CXPoint  CXRect::CenterPoint(void)const ,CXRect__CenterPoint);
#endif
#ifdef CBazaarSearchWnd__CBazaarSearchWnd
FUNCTION_AT_ADDRESS( CBazaarSearchWnd::CBazaarSearchWnd(class CXWnd *),CBazaarSearchWnd__CBazaarSearchWnd);
#endif
#ifdef CBazaarSearchWnd__InitListArray
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::InitListArray(void),CBazaarSearchWnd__InitListArray);
#endif
#ifdef CBazaarSearchWnd__Init
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::Init(void),CBazaarSearchWnd__Init);
#endif
#ifdef CBazaarSearchWnd__UpdatePlayerUpdateButton
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::UpdatePlayerUpdateButton(bool),CBazaarSearchWnd__UpdatePlayerUpdateButton);
#endif
#ifdef CBazaarSearchWnd__UpdatePlayerCombo
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::UpdatePlayerCombo(void),CBazaarSearchWnd__UpdatePlayerCombo);
#endif
#ifdef CBazaarSearchWnd__Activate
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::Activate(void),CBazaarSearchWnd__Activate);
#endif
#ifdef CBazaarSearchWnd__GetPriceString
FUNCTION_AT_ADDRESS(char *  CBazaarSearchWnd::GetPriceString(unsigned long),CBazaarSearchWnd__GetPriceString);
#endif
#ifdef CBazaarSearchWnd__SortItemList
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::SortItemList(int),CBazaarSearchWnd__SortItemList);
#endif
#ifdef CBazaarSearchWnd__AddItemtoList
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::AddItemtoList(char *,unsigned long,char *,int,int),CBazaarSearchWnd__AddItemtoList);
#endif
#ifdef CBazaarSearchWnd__UpdateComboButtons
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::UpdateComboButtons(void),CBazaarSearchWnd__UpdateComboButtons);
#endif
#ifdef CBazaarSearchWnd__HandleBazaarMsg
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::HandleBazaarMsg(char *,int),CBazaarSearchWnd__HandleBazaarMsg);
#endif
#ifdef CBazaarSearchWnd__doQuery
FUNCTION_AT_ADDRESS(void  CBazaarSearchWnd::doQuery(void),CBazaarSearchWnd__doQuery);
#endif
#ifdef CBazaarWnd__CBazaarWnd
FUNCTION_AT_ADDRESS( CBazaarWnd::CBazaarWnd(class CXWnd *),CBazaarWnd__CBazaarWnd);
#endif
#ifdef CBazaarWnd__Init
FUNCTION_AT_ADDRESS(void  CBazaarWnd::Init(void),CBazaarWnd__Init);
#endif
#ifdef CBazaarWnd__CreateBZRIniFilename
FUNCTION_AT_ADDRESS(void  CBazaarWnd::CreateBZRIniFilename(void),CBazaarWnd__CreateBZRIniFilename);
#endif
#ifdef CBazaarWnd__AddBazaarText
FUNCTION_AT_ADDRESS(void  CBazaarWnd::AddBazaarText(char *,int),CBazaarWnd__AddBazaarText);
#endif
#ifdef CBazaarWnd__ReturnItemByIndex
FUNCTION_AT_ADDRESS(class EQ_Item *  CBazaarWnd::ReturnItemByIndex(int),CBazaarWnd__ReturnItemByIndex);
#endif
#ifdef CBazaarWnd__GetPriceString
FUNCTION_AT_ADDRESS(char *  CBazaarWnd::GetPriceString(unsigned long),CBazaarWnd__GetPriceString);
#endif
#ifdef CBazaarWnd__HandleTraderMsg
FUNCTION_AT_ADDRESS(void  CBazaarWnd::HandleTraderMsg(char *),CBazaarWnd__HandleTraderMsg);
#endif
#ifdef CBazaarWnd__RebuildItemArray
FUNCTION_AT_ADDRESS(void  CBazaarWnd::RebuildItemArray(void),CBazaarWnd__RebuildItemArray);
#endif
#ifdef CBazaarWnd__BuildBazaarItemArray
FUNCTION_AT_ADDRESS(void  CBazaarWnd::BuildBazaarItemArray(void),CBazaarWnd__BuildBazaarItemArray);
#endif
#ifdef CBazaarWnd__AddEquipmentToBazaarArray
FUNCTION_AT_ADDRESS(void  CBazaarWnd::AddEquipmentToBazaarArray(class EQ_Item *,int,unsigned long),CBazaarWnd__AddEquipmentToBazaarArray);
#endif
#ifdef CBazaarWnd__Activate
FUNCTION_AT_ADDRESS(void  CBazaarWnd::Activate(void),CBazaarWnd__Activate);
#endif
#ifdef CBazaarWnd__UpdatePriceButtons
FUNCTION_AT_ADDRESS(void  CBazaarWnd::UpdatePriceButtons(void),CBazaarWnd__UpdatePriceButtons);
#endif
#ifdef CBazaarWnd__StoreSelectedPrice
FUNCTION_AT_ADDRESS(bool  CBazaarWnd::StoreSelectedPrice(void),CBazaarWnd__StoreSelectedPrice);
#endif
#ifdef CBazaarWnd__UpdateButtons
FUNCTION_AT_ADDRESS(void  CBazaarWnd::UpdateButtons(void),CBazaarWnd__UpdateButtons);
#endif
#ifdef CBazaarWnd__SelectBazaarSlotItem
FUNCTION_AT_ADDRESS(void  CBazaarWnd::SelectBazaarSlotItem(int,class CTextureAnimation *),CBazaarWnd__SelectBazaarSlotItem);
#endif
#ifdef CBazaarWnd__SetMoneyButton
FUNCTION_AT_ADDRESS(void  CBazaarWnd::SetMoneyButton(int,int),CBazaarWnd__SetMoneyButton);
#endif
#ifdef CBazaarWnd__GetQtyFromCoinType
FUNCTION_AT_ADDRESS(long  CBazaarWnd::GetQtyFromCoinType(int),CBazaarWnd__GetQtyFromCoinType);
#endif
#ifdef CBazaarWnd__ClickedMoneyButton
FUNCTION_AT_ADDRESS(void  CBazaarWnd::ClickedMoneyButton(int,int),CBazaarWnd__ClickedMoneyButton);
#endif
#ifdef CBazaarWnd__GetPrice
FUNCTION_AT_ADDRESS(unsigned long  CBazaarWnd::GetPrice(void),CBazaarWnd__GetPrice);
#endif
#ifdef CBazaarWnd__UpdateBazaarListtoServer
FUNCTION_AT_ADDRESS(int  CBazaarWnd::UpdateBazaarListtoServer(void),CBazaarWnd__UpdateBazaarListtoServer);
#endif
#ifdef CBazaarWnd__ToggleBzrItemActive
FUNCTION_AT_ADDRESS(void  CBazaarWnd::ToggleBzrItemActive(int,bool),CBazaarWnd__ToggleBzrItemActive);
#endif
#ifdef CXWnd__GetWindowTextA
FUNCTION_AT_ADDRESS(class CXStr  CXWnd::GetWindowTextA(void)const ,CXWnd__GetWindowTextA);
#endif
#ifdef CBodyTintWnd__CBodyTintWnd
FUNCTION_AT_ADDRESS( CBodyTintWnd::CBodyTintWnd(class CXWnd *),CBodyTintWnd__CBodyTintWnd);
#endif
#ifdef CBodyTintWnd__Activate
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::Activate(void),CBodyTintWnd__Activate);
#endif
#ifdef CBodyTintWnd__GetTintChangeCount
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::GetTintChangeCount(void),CBodyTintWnd__GetTintChangeCount);
#endif
#ifdef CBodyTintWnd__GetReagentCount
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::GetReagentCount(void),CBodyTintWnd__GetReagentCount);
#endif
#ifdef CBodyTintWnd__BuildRBGTooltip
FUNCTION_AT_ADDRESS(char *  CBodyTintWnd::BuildRBGTooltip(unsigned long,char * const),CBodyTintWnd__BuildRBGTooltip);
#endif
#ifdef CBodyTintWnd__GetItemTint
FUNCTION_AT_ADDRESS(unsigned long  CBodyTintWnd::GetItemTint(int),CBodyTintWnd__GetItemTint);
#endif
#ifdef CBodyTintWnd__SetSlotLabels
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::SetSlotLabels(bool),CBodyTintWnd__SetSlotLabels);
#endif
#ifdef CBodyTintWnd__UpdateLocalTintColor
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::UpdateLocalTintColor(unsigned long),CBodyTintWnd__UpdateLocalTintColor);
#endif
#ifdef CBodyTintWnd__UpdateMaterialTintLocal
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::UpdateMaterialTintLocal(unsigned long),CBodyTintWnd__UpdateMaterialTintLocal);
#endif
#ifdef CBodyTintWnd__UpdateLabelsAndButtons
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::UpdateLabelsAndButtons(void),CBodyTintWnd__UpdateLabelsAndButtons);
#endif
#ifdef CBodyTintWnd__GetButtonTint
FUNCTION_AT_ADDRESS(unsigned long  CBodyTintWnd::GetButtonTint(int),CBodyTintWnd__GetButtonTint);
#endif
#ifdef CBodyTintWnd__StoreModifiedBodyTints
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::StoreModifiedBodyTints(void),CBodyTintWnd__StoreModifiedBodyTints);
#endif
#ifdef CBodyTintWnd__ResetToOrigBodyTints
FUNCTION_AT_ADDRESS(void  CBodyTintWnd::ResetToOrigBodyTints(void),CBodyTintWnd__ResetToOrigBodyTints);
#endif
#ifdef CXWnd__SetTooltip
FUNCTION_AT_ADDRESS(void  CXWnd::SetTooltip(class CXStr),CXWnd__SetTooltip);
#endif
#ifdef CBookWnd__CBookWnd
FUNCTION_AT_ADDRESS( CBookWnd::CBookWnd(class CXWnd *),CBookWnd__CBookWnd);
#endif
#ifdef CBookWnd__Activate
FUNCTION_AT_ADDRESS(void  CBookWnd::Activate(void),CBookWnd__Activate);
#endif
#ifdef CBookWnd__SetBook
FUNCTION_AT_ADDRESS(void  CBookWnd::SetBook(char *),CBookWnd__SetBook);
#endif
#ifdef CBookWnd__CheckBook
FUNCTION_AT_ADDRESS(bool  CBookWnd::CheckBook(class EQ_Note *),CBookWnd__CheckBook);
#endif
#ifdef CBookWnd__DisplayText
FUNCTION_AT_ADDRESS(void  CBookWnd::DisplayText(void),CBookWnd__DisplayText);
#endif
#ifdef CBookWnd__CleanPages
FUNCTION_AT_ADDRESS(void  CBookWnd::CleanPages(void),CBookWnd__CleanPages);
#endif
#ifdef CBookWnd__ProcessText
FUNCTION_AT_ADDRESS(void  CBookWnd::ProcessText(void),CBookWnd__ProcessText);
#endif
#ifdef CBookWnd__ShowButtons
FUNCTION_AT_ADDRESS(void  CBookWnd::ShowButtons(void),CBookWnd__ShowButtons);
#endif
#ifdef COptionsWnd__KeyboardAssignmentData__KeyboardAssignmentData
//FUNCTION_AT_ADDRESS( COptionsWnd::KeyboardAssignmentData::KeyboardAssignmentData(void),COptionsWnd__KeyboardAssignmentData__KeyboardAssignmentData);
#endif
#ifdef CXStr__CXStr1
FUNCTION_AT_ADDRESS( CXStr::CXStr(void),CXStr__CXStr1);
#endif
#ifdef CBreathWnd__CBreathWnd
FUNCTION_AT_ADDRESS( CBreathWnd::CBreathWnd(class CXWnd *),CBreathWnd__CBreathWnd);
#endif
#ifdef CBreathWnd__Init
FUNCTION_AT_ADDRESS(void  CBreathWnd::Init(void),CBreathWnd__Init);
#endif
#ifdef CBreathWnd__Activate
FUNCTION_AT_ADDRESS(void  CBreathWnd::Activate(void),CBreathWnd__Activate);
#endif
#ifdef CBuffWindow__CBuffWindow
//FUNCTION_AT_ADDRESS( CBuffWindow::CBuffWindow(class CXWnd *,enum BuffWindowType),CBuffWindow__CBuffWindow);
#endif
#ifdef CTextureAnimation__operator_equal
FUNCTION_AT_ADDRESS(class CTextureAnimation &  CTextureAnimation::operator=(class CTextureAnimation const &),CTextureAnimation__operator_equal);
#endif
#ifdef CBuffWindow__Init
FUNCTION_AT_ADDRESS(void  CBuffWindow::Init(void),CBuffWindow__Init);
#endif
#ifdef CBuffWindow__Activate
FUNCTION_AT_ADDRESS(void  CBuffWindow::Activate(void),CBuffWindow__Activate);
#endif
#ifdef CBuffWindow__HandleSpellInfoDisplay
FUNCTION_AT_ADDRESS(void  CBuffWindow::HandleSpellInfoDisplay(class CXWnd *),CBuffWindow__HandleSpellInfoDisplay);
#endif
#ifdef CBuffWindow__RefreshIconArrangement
FUNCTION_AT_ADDRESS(void  CBuffWindow::RefreshIconArrangement(void),CBuffWindow__RefreshIconArrangement);
#endif
#ifdef CBuffWindow__RefreshBuffDisplay
FUNCTION_AT_ADDRESS(void  CBuffWindow::RefreshBuffDisplay(void),CBuffWindow__RefreshBuffDisplay);
#endif
#ifdef CBuffWindow__SetBuffIcon
FUNCTION_AT_ADDRESS(void  CBuffWindow::SetBuffIcon(class CButtonWnd *,int,int),CBuffWindow__SetBuffIcon);
#endif
#ifdef CXRect__Move
FUNCTION_AT_ADDRESS(void  CXRect::Move(class CXPoint),CXRect__Move);
#endif
#ifdef CTAFrameDraw__GetFrameSize
FUNCTION_AT_ADDRESS(class CXSize  CTAFrameDraw::GetFrameSize(void)const ,CTAFrameDraw__GetFrameSize);
#endif
#ifdef STextureAnimationFrame__STextureAnimationFrame
FUNCTION_AT_ADDRESS( STextureAnimationFrame::STextureAnimationFrame(void),STextureAnimationFrame__STextureAnimationFrame);
#endif
#ifdef CUITexturePiece__CUITexturePiece
FUNCTION_AT_ADDRESS( CUITexturePiece::CUITexturePiece(void),CUITexturePiece__CUITexturePiece);
#endif
#ifdef STextureAnimationFrame__operator_equal
FUNCTION_AT_ADDRESS(class STextureAnimationFrame &  STextureAnimationFrame::operator=(class STextureAnimationFrame const &),STextureAnimationFrame__operator_equal);
#endif
#ifdef CUITexturePiece__operator_equal
FUNCTION_AT_ADDRESS(class CUITexturePiece &  CUITexturePiece::operator=(class CUITexturePiece const &),CUITexturePiece__operator_equal);
#endif
#ifdef CBugReportWnd__CBugReportWnd
FUNCTION_AT_ADDRESS( CBugReportWnd::CBugReportWnd(class CXWnd *),CBugReportWnd__CBugReportWnd);
#endif
#ifdef CBugReportWnd__Activate
FUNCTION_AT_ADDRESS(void  CBugReportWnd::Activate(void),CBugReportWnd__Activate);
#endif
#ifdef CBugReportWnd__UpdateLocation
FUNCTION_AT_ADDRESS(void  CBugReportWnd::UpdateLocation(void),CBugReportWnd__UpdateLocation);
#endif
#ifdef CCastingWnd__CCastingWnd
FUNCTION_AT_ADDRESS( CCastingWnd::CCastingWnd(class CXWnd *),CCastingWnd__CCastingWnd);
#endif
#ifdef CCastingWnd__Activate
FUNCTION_AT_ADDRESS(void  CCastingWnd::Activate(void),CCastingWnd__Activate);
#endif
#ifdef CVideoModesWnd__Activate
FUNCTION_AT_ADDRESS(void  CVideoModesWnd::Activate(void),CVideoModesWnd__Activate);
#endif
#ifdef CCastSpellWnd__CCastSpellWnd
FUNCTION_AT_ADDRESS( CCastSpellWnd::CCastSpellWnd(class CXWnd *),CCastSpellWnd__CCastSpellWnd);
#endif
#ifdef CCastSpellWnd__Init
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::Init(void),CCastSpellWnd__Init);
#endif
#ifdef CCastSpellWnd__Activate
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::Activate(void),CCastSpellWnd__Activate);
#endif
#ifdef CCastSpellWnd__HandleSpellInfoDisplay
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::HandleSpellInfoDisplay(class CXWnd *),CCastSpellWnd__HandleSpellInfoDisplay);
#endif
#ifdef CCastSpellWnd__HandleSpellLeftClick
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::HandleSpellLeftClick(int),CCastSpellWnd__HandleSpellLeftClick);
#endif
#ifdef CCastSpellWnd__Unmemorize
FUNCTION_AT_ADDRESS(void __cdecl CCastSpellWnd::Unmemorize(int),CCastSpellWnd__Unmemorize);
#endif
#ifdef CCastSpellWnd__UnmemorizeList
FUNCTION_AT_ADDRESS(void __cdecl CCastSpellWnd::UnmemorizeList(int *,int),CCastSpellWnd__UnmemorizeList);
#endif
#ifdef CCastSpellWnd__HandleSpellRightClick
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::HandleSpellRightClick(int),CCastSpellWnd__HandleSpellRightClick);
#endif
#ifdef CCastSpellWnd__ForgetMemorizedSpell
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::ForgetMemorizedSpell(int),CCastSpellWnd__ForgetMemorizedSpell);
#endif
#ifdef CCastSpellWnd__IsBardSongPlaying
FUNCTION_AT_ADDRESS(bool  CCastSpellWnd::IsBardSongPlaying(void),CCastSpellWnd__IsBardSongPlaying);
#endif
#ifdef CCastSpellWnd__RefreshSpellGemButtons
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::RefreshSpellGemButtons(void),CCastSpellWnd__RefreshSpellGemButtons);
#endif
#ifdef CCastSpellWnd__UpdateSpellGems
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::UpdateSpellGems(int),CCastSpellWnd__UpdateSpellGems);
#endif
#ifdef CCastSpellWnd__UpdateSpellGemTooltips
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::UpdateSpellGemTooltips(int),CCastSpellWnd__UpdateSpellGemTooltips);
#endif
#ifdef CCastSpellWnd__GetSpellGemColor
FUNCTION_AT_ADDRESS(unsigned long  CCastSpellWnd::GetSpellGemColor(class EQ_Spell *),CCastSpellWnd__GetSpellGemColor);
#endif
#ifdef CCastSpellWnd__SpellBookDeactivating
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::SpellBookDeactivating(void),CCastSpellWnd__SpellBookDeactivating);
#endif
#ifdef CCastSpellWnd__KeyMapUpdated
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::KeyMapUpdated(void),CCastSpellWnd__KeyMapUpdated);
#endif
#ifdef CCastSpellWnd__ClearSpellCategories
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::ClearSpellCategories(void),CCastSpellWnd__ClearSpellCategories);
#endif
#ifdef CCastSpellWnd__SpellCategoryMajor__dSpellCategoryMajor
//FUNCTION_AT_ADDRESS( CCastSpellWnd::SpellCategoryMajor::~SpellCategoryMajor(void),CCastSpellWnd__SpellCategoryMajor__dSpellCategoryMajor);
#endif
#ifdef CCastSpellWnd__SpellCategoryMinor__dSpellCategoryMinor
//FUNCTION_AT_ADDRESS( CCastSpellWnd::SpellCategoryMinor::~SpellCategoryMinor(void),CCastSpellWnd__SpellCategoryMinor__dSpellCategoryMinor);
#endif
#ifdef CCastSpellWnd__RecacheCategorizedSpells
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::RecacheCategorizedSpells(void),CCastSpellWnd__RecacheCategorizedSpells);
#endif
#ifdef CCastSpellWnd__MakeSpellSelectMenu
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::MakeSpellSelectMenu(void),CCastSpellWnd__MakeSpellSelectMenu);
#endif
#ifdef CCastSpellWnd__CategorizeSpell
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::CategorizeSpell(int,int,int,int),CCastSpellWnd__CategorizeSpell);
#endif
#ifdef CCastSpellWnd__RecacheLoadoutContextMenu
FUNCTION_AT_ADDRESS(void  CCastSpellWnd::RecacheLoadoutContextMenu(void),CCastSpellWnd__RecacheLoadoutContextMenu);
#endif
#ifdef CCharacterCreation__CCharacterCreation
FUNCTION_AT_ADDRESS( CCharacterCreation::CCharacterCreation(class CXWnd *),CCharacterCreation__CCharacterCreation);
#endif
#ifdef CCharacterCreation__Init
FUNCTION_AT_ADDRESS(void  CCharacterCreation::Init(void),CCharacterCreation__Init);
#endif
#ifdef CCharacterCreation__Activate
FUNCTION_AT_ADDRESS(void  CCharacterCreation::Activate(void),CCharacterCreation__Activate);
#endif
#ifdef CCharacterCreation__NameGenerated
FUNCTION_AT_ADDRESS(void  CCharacterCreation::NameGenerated(char *),CCharacterCreation__NameGenerated);
#endif
#ifdef CCharacterCreation__DoBackButton
FUNCTION_AT_ADDRESS(void  CCharacterCreation::DoBackButton(void),CCharacterCreation__DoBackButton);
#endif
#ifdef CCharacterCreation__DoNextButton
FUNCTION_AT_ADDRESS(void  CCharacterCreation::DoNextButton(void),CCharacterCreation__DoNextButton);
#endif
#ifdef CCharacterCreation__DoStatButton
FUNCTION_AT_ADDRESS(void  CCharacterCreation::DoStatButton(int),CCharacterCreation__DoStatButton);
#endif
#ifdef CCharacterCreation__ActivateScreen
FUNCTION_AT_ADDRESS(void  CCharacterCreation::ActivateScreen(int),CCharacterCreation__ActivateScreen);
#endif
#ifdef CCharacterCreation__RandomizeCharacter
FUNCTION_AT_ADDRESS(void  CCharacterCreation::RandomizeCharacter(bool,bool),CCharacterCreation__RandomizeCharacter);
#endif
#ifdef CCharacterCreation__RandomizeFacialFeatures
FUNCTION_AT_ADDRESS(void  CCharacterCreation::RandomizeFacialFeatures(void),CCharacterCreation__RandomizeFacialFeatures);
#endif
#ifdef CCharacterCreation__InitStats
FUNCTION_AT_ADDRESS(void  CCharacterCreation::InitStats(bool),CCharacterCreation__InitStats);
#endif
#ifdef CCharacterCreation__InitNewPC
FUNCTION_AT_ADDRESS(void  CCharacterCreation::InitNewPC(void),CCharacterCreation__InitNewPC);
#endif
#ifdef CCharacterCreation__InitStartingCities
FUNCTION_AT_ADDRESS(void  CCharacterCreation::InitStartingCities(void),CCharacterCreation__InitStartingCities);
#endif
#ifdef CCharacterCreation__SetNewPCDeityFromBtnIndex
FUNCTION_AT_ADDRESS(void  CCharacterCreation::SetNewPCDeityFromBtnIndex(int),CCharacterCreation__SetNewPCDeityFromBtnIndex);
#endif
#ifdef CCharacterCreation__UpdatePlayerFromNewPC
FUNCTION_AT_ADDRESS(void  CCharacterCreation::UpdatePlayerFromNewPC(void),CCharacterCreation__UpdatePlayerFromNewPC);
#endif
#ifdef CCharacterCreation__UpdateScreenZeroButtons
FUNCTION_AT_ADDRESS(void  CCharacterCreation::UpdateScreenZeroButtons(bool),CCharacterCreation__UpdateScreenZeroButtons);
#endif
#ifdef CCharacterCreation__GetRaceButtonIndex
FUNCTION_AT_ADDRESS(int  CCharacterCreation::GetRaceButtonIndex(int),CCharacterCreation__GetRaceButtonIndex);
#endif
#ifdef CCharacterCreation__GetClassButtonIndex
FUNCTION_AT_ADDRESS(int  CCharacterCreation::GetClassButtonIndex(int),CCharacterCreation__GetClassButtonIndex);
#endif
#ifdef CCharacterCreation__IsLackingExpansion
FUNCTION_AT_ADDRESS(bool  CCharacterCreation::IsLackingExpansion(bool,bool),CCharacterCreation__IsLackingExpansion);
#endif
#ifdef CCharacterCreation__SelectStartingCity
FUNCTION_AT_ADDRESS(void  CCharacterCreation::SelectStartingCity(int),CCharacterCreation__SelectStartingCity);
#endif
#ifdef CCharacterCreation__SelectedRaceButton
FUNCTION_AT_ADDRESS(void  CCharacterCreation::SelectedRaceButton(int),CCharacterCreation__SelectedRaceButton);
#endif
#ifdef CCharacterCreation__SelectedClassButton
FUNCTION_AT_ADDRESS(void  CCharacterCreation::SelectedClassButton(int),CCharacterCreation__SelectedClassButton);
#endif
#ifdef CCharacterCreation__SetPlayerAppearanceFromNewPC
FUNCTION_AT_ADDRESS(void  CCharacterCreation::SetPlayerAppearanceFromNewPC(class EQPlayer *,class EQ_PC *,bool),CCharacterCreation__SetPlayerAppearanceFromNewPC);
#endif
#ifdef CCharacterCreation__HandleNameApprovalResponse
FUNCTION_AT_ADDRESS(void  CCharacterCreation::HandleNameApprovalResponse(int),CCharacterCreation__HandleNameApprovalResponse);
#endif
#ifdef CCharacterCreation__SubmitNameToWorld
FUNCTION_AT_ADDRESS(void  CCharacterCreation::SubmitNameToWorld(void),CCharacterCreation__SubmitNameToWorld);
#endif
#ifdef CCharacterCreation__FinalizeNewPCAndSendToWorld
FUNCTION_AT_ADDRESS(void  CCharacterCreation::FinalizeNewPCAndSendToWorld(void),CCharacterCreation__FinalizeNewPCAndSendToWorld);
#endif
#ifdef CCharacterCreation__GetCharCreateText
FUNCTION_AT_ADDRESS(char *  CCharacterCreation::GetCharCreateText(char *,int,int,int,int),CCharacterCreation__GetCharCreateText);
#endif
#ifdef CCharacterSelect__CCharacterSelect
FUNCTION_AT_ADDRESS( CCharacterSelect::CCharacterSelect(class CXWnd *),CCharacterSelect__CCharacterSelect);
#endif
#ifdef CCharacterSelect__Init
FUNCTION_AT_ADDRESS(void  CCharacterSelect::Init(void),CCharacterSelect__Init);
#endif
#ifdef CCharacterSelect__Activate
FUNCTION_AT_ADDRESS(void  CCharacterSelect::Activate(void),CCharacterSelect__Activate);
#endif
#ifdef CCharacterSelect__EnableButtons
FUNCTION_AT_ADDRESS(void  CCharacterSelect::EnableButtons(bool),CCharacterSelect__EnableButtons);
#endif
#ifdef CCharacterSelect__EnableEqMovementCommands
FUNCTION_AT_ADDRESS(void  CCharacterSelect::EnableEqMovementCommands(bool),CCharacterSelect__EnableEqMovementCommands);
#endif
#ifdef CCharacterSelect__EnterWorld
FUNCTION_AT_ADDRESS(void  CCharacterSelect::EnterWorld(void),CCharacterSelect__EnterWorld);
#endif
#ifdef CCharacterSelect__Quit
FUNCTION_AT_ADDRESS(void  CCharacterSelect::Quit(void),CCharacterSelect__Quit);
#endif
#ifdef CCharacterSelect__EnterExplorationMode
FUNCTION_AT_ADDRESS(void  CCharacterSelect::EnterExplorationMode(void),CCharacterSelect__EnterExplorationMode);
#endif
#ifdef CCharacterSelect__LeaveExplorationMode
FUNCTION_AT_ADDRESS(void  CCharacterSelect::LeaveExplorationMode(void),CCharacterSelect__LeaveExplorationMode);
#endif
#ifdef CCharacterSelect__IsValidCharacterSelected
FUNCTION_AT_ADDRESS(int  CCharacterSelect::IsValidCharacterSelected(void),CCharacterSelect__IsValidCharacterSelected);
#endif
#ifdef CCharacterSelect__IsEmptyCharacterSlot
FUNCTION_AT_ADDRESS(int  CCharacterSelect::IsEmptyCharacterSlot(int),CCharacterSelect__IsEmptyCharacterSlot);
#endif
#ifdef CCharacterSelect__NumberOfCharacters
FUNCTION_AT_ADDRESS(int  CCharacterSelect::NumberOfCharacters(void),CCharacterSelect__NumberOfCharacters);
#endif
#ifdef CCharacterSelect__IsEvil
FUNCTION_AT_ADDRESS(unsigned char  CCharacterSelect::IsEvil(int,int,int),CCharacterSelect__IsEvil);
#endif
#ifdef CCharacterSelect__SelectCharacter
FUNCTION_AT_ADDRESS(void  CCharacterSelect::SelectCharacter(int,int),CCharacterSelect__SelectCharacter);
#endif
#ifdef CCharacterSelect__SetLoadZonePlayerLocation
FUNCTION_AT_ADDRESS(void  CCharacterSelect::SetLoadZonePlayerLocation(void),CCharacterSelect__SetLoadZonePlayerLocation);
#endif
#ifdef CCharacterSelect__DeleteCharacter
FUNCTION_AT_ADDRESS(void  CCharacterSelect::DeleteCharacter(void),CCharacterSelect__DeleteCharacter);
#endif
#ifdef CCharacterSelect__UpdateButtonNames
FUNCTION_AT_ADDRESS(void  CCharacterSelect::UpdateButtonNames(void),CCharacterSelect__UpdateButtonNames);
#endif
#ifdef CCharacterSelect__SetLocationByClass
FUNCTION_AT_ADDRESS(void  CCharacterSelect::SetLocationByClass(class EQPlayer *,bool,int),CCharacterSelect__SetLocationByClass);
#endif
#ifdef CCharacterSelect__CreateExplorationModePlayers
FUNCTION_AT_ADDRESS(void  CCharacterSelect::CreateExplorationModePlayers(void),CCharacterSelect__CreateExplorationModePlayers);
#endif
#ifdef CCharacterSelect__RemoveExplorationModePlayers
FUNCTION_AT_ADDRESS(void  CCharacterSelect::RemoveExplorationModePlayers(void),CCharacterSelect__RemoveExplorationModePlayers);
#endif
#ifdef CCharacterSelect__SetRoomLocationByIndex
FUNCTION_AT_ADDRESS(void  CCharacterSelect::SetRoomLocationByIndex(int,class EQPlayer *),CCharacterSelect__SetRoomLocationByIndex);
#endif
#ifdef CCharacterSelect__SwitchModel
FUNCTION_AT_ADDRESS(void  CCharacterSelect::SwitchModel(class EQPlayer *,unsigned char,int,unsigned char,unsigned char),CCharacterSelect__SwitchModel);
#endif
#ifdef CChatManager__CChatManager
FUNCTION_AT_ADDRESS( CChatManager::CChatManager(void),CChatManager__CChatManager);
#endif
#ifdef CChatManager__dCChatManager
FUNCTION_AT_ADDRESS( CChatManager::~CChatManager(void),CChatManager__dCChatManager);
#endif
#ifdef CBookWnd__Init
FUNCTION_AT_ADDRESS(void  CBookWnd::Init(void),CBookWnd__Init);
#endif
#ifdef CColorPickerWnd__Init
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::Init(void),CColorPickerWnd__Init);
#endif
#ifdef CCompassWnd__Init
FUNCTION_AT_ADDRESS(void  CCompassWnd::Init(void),CCompassWnd__Init);
#endif
#ifdef CContainerWnd__Init
FUNCTION_AT_ADDRESS(void  CContainerWnd::Init(void),CContainerWnd__Init);
#endif
#ifdef CGiveWnd__Init
FUNCTION_AT_ADDRESS(void  CGiveWnd::Init(void),CGiveWnd__Init);
#endif
#ifdef CHelpWnd__Init
FUNCTION_AT_ADDRESS(void  CHelpWnd::Init(void),CHelpWnd__Init);
#endif
#ifdef CMusicPlayerWnd__Init
FUNCTION_AT_ADDRESS(void  CMusicPlayerWnd::Init(void),CMusicPlayerWnd__Init);
#endif
#ifdef CNoteWnd__Init
FUNCTION_AT_ADDRESS(void  CNoteWnd::Init(void),CNoteWnd__Init);
#endif
#ifdef CPetInfoWnd__Init
FUNCTION_AT_ADDRESS(void  CPetInfoWnd::Init(void),CPetInfoWnd__Init);
#endif
#ifdef CPlayerNotesWnd__Init
FUNCTION_AT_ADDRESS(void  CPlayerNotesWnd::Init(void),CPlayerNotesWnd__Init);
#endif
#ifdef CTargetWnd__Init
FUNCTION_AT_ADDRESS(void  CTargetWnd::Init(void),CTargetWnd__Init);
#endif
#ifdef UdpManager__ProcessIcmpErrors
FUNCTION_AT_ADDRESS(void  UdpManager::ProcessIcmpErrors(void),UdpManager__ProcessIcmpErrors);
#endif
#ifdef CRaid__dCRaid
FUNCTION_AT_ADDRESS( CRaid::~CRaid(void),CRaid__dCRaid);
#endif
#ifdef EQ_Note__dEQ_Note
FUNCTION_AT_ADDRESS( EQ_Note::~EQ_Note(void),EQ_Note__dEQ_Note);
#endif
#ifdef EQ_Skill__dEQ_Skill
FUNCTION_AT_ADDRESS( EQ_Skill::~EQ_Skill(void),EQ_Skill__dEQ_Skill);
#endif
#ifdef EQAnimation__dEQAnimation
FUNCTION_AT_ADDRESS( EQAnimation::~EQAnimation(void),EQAnimation__dEQAnimation);
#endif
#ifdef KeypressHandler__dKeypressHandler
FUNCTION_AT_ADDRESS( KeypressHandler::~KeypressHandler(void),KeypressHandler__dKeypressHandler);
#endif
#ifdef EQNewPlayerAnimation__InitAnimationData
FUNCTION_AT_ADDRESS(void __cdecl EQNewPlayerAnimation::InitAnimationData(void),EQNewPlayerAnimation__InitAnimationData);
#endif
#ifdef CAAWnd__CancelAASpend
FUNCTION_AT_ADDRESS(void  CAAWnd::CancelAASpend(void),CAAWnd__CancelAASpend);
#endif
#ifdef CChatManager__Process
FUNCTION_AT_ADDRESS(void  CChatManager::Process(void),CChatManager__Process);
#endif
#ifdef CDisplay__DefineSoloMode
FUNCTION_AT_ADDRESS(void  CDisplay::DefineSoloMode(void),CDisplay__DefineSoloMode);
#endif
#ifdef CEverQuest__InitCommands
FUNCTION_AT_ADDRESS(void  CEverQuest::InitCommands(void),CEverQuest__InitCommands);
#endif
#ifdef CInvSlotMgr__Process
FUNCTION_AT_ADDRESS(void  CInvSlotMgr::Process(void),CInvSlotMgr__Process);
#endif
#ifdef EQMissile__LeaveTrail
FUNCTION_AT_ADDRESS(void  EQMissile::LeaveTrail(void),EQMissile__LeaveTrail);
#endif
#ifdef CChatManager__Activate
FUNCTION_AT_ADDRESS(void  CChatManager::Activate(void),CChatManager__Activate);
#endif
#ifdef CChatManager__Deactivate
FUNCTION_AT_ADDRESS(void  CChatManager::Deactivate(void),CChatManager__Deactivate);
#endif
#ifdef CChatManager__LoadChatInis
FUNCTION_AT_ADDRESS(void  CChatManager::LoadChatInis(void),CChatManager__LoadChatInis);
#endif
#ifdef CChatManager__CreateChatWindow
FUNCTION_AT_ADDRESS(void  CChatManager::CreateChatWindow(void),CChatManager__CreateChatWindow);
#endif
#ifdef CChatManager__CreateChatWindow1
FUNCTION_AT_ADDRESS(void  CChatManager::CreateChatWindow(char *,char *,int,int,int,char *,int),CChatManager__CreateChatWindow1);
#endif
#ifdef CChatManager__FreeChatWindow
FUNCTION_AT_ADDRESS(void  CChatManager::FreeChatWindow(class CChatWindow *),CChatManager__FreeChatWindow);
#endif
#ifdef CChatManager__GetActiveChatWindow
FUNCTION_AT_ADDRESS(class CChatWindow *  CChatManager::GetActiveChatWindow(void),CChatManager__GetActiveChatWindow);
#endif
#ifdef CChatManager__AddText
FUNCTION_AT_ADDRESS(void  CChatManager::AddText(class CXStr,int),CChatManager__AddText);
#endif
#ifdef CChatManager__SetChannelMap
FUNCTION_AT_ADDRESS(void  CChatManager::SetChannelMap(int,class CChatWindow *),CChatManager__SetChannelMap);
#endif
#ifdef CChatManager__ClearChannelMap
FUNCTION_AT_ADDRESS(void  CChatManager::ClearChannelMap(int),CChatManager__ClearChannelMap);
#endif
#ifdef CChatManager__GetChannelFromColor
FUNCTION_AT_ADDRESS(int  CChatManager::GetChannelFromColor(int),CChatManager__GetChannelFromColor);
#endif
#ifdef CChatManager__GetChannelMap
FUNCTION_AT_ADDRESS(class CChatWindow *  CChatManager::GetChannelMap(int),CChatManager__GetChannelMap);
#endif
#ifdef CChatManager__ClearChannelMaps
FUNCTION_AT_ADDRESS(void  CChatManager::ClearChannelMaps(class CChatWindow *),CChatManager__ClearChannelMaps);
#endif
#ifdef CChatManager__SetActiveChatWindow
FUNCTION_AT_ADDRESS(void  CChatManager::SetActiveChatWindow(class CChatWindow *),CChatManager__SetActiveChatWindow);
#endif
#ifdef CChatManager__SetLockedActiveChatWindow
FUNCTION_AT_ADDRESS(void  CChatManager::SetLockedActiveChatWindow(class CChatWindow *),CChatManager__SetLockedActiveChatWindow);
#endif
#ifdef CChatManager__GetRGBAFromIndex
FUNCTION_AT_ADDRESS(unsigned long  CChatManager::GetRGBAFromIndex(int),CChatManager__GetRGBAFromIndex);
#endif
#ifdef CChatManager__InitContextMenu
FUNCTION_AT_ADDRESS(int  CChatManager::InitContextMenu(class CChatWindow *),CChatManager__InitContextMenu);
#endif
#ifdef CChatManager__UpdateContextMenus
FUNCTION_AT_ADDRESS(void  CChatManager::UpdateContextMenus(class CChatWindow *),CChatManager__UpdateContextMenus);
#endif
#ifdef CChatManager__UpdateTellMenus
FUNCTION_AT_ADDRESS(void  CChatManager::UpdateTellMenus(class CChatWindow *),CChatManager__UpdateTellMenus);
#endif
#ifdef CChatManager__GetAllVisibleText
FUNCTION_AT_ADDRESS(class CXStr  CChatManager::GetAllVisibleText(class CXStr),CChatManager__GetAllVisibleText);
#endif
#ifdef CChatWindow__GetOutputWnd
FUNCTION_AT_ADDRESS(class CStmlWnd *  CChatWindow::GetOutputWnd(void),CChatWindow__GetOutputWnd);
#endif
#ifdef CContextMenuManager__GetDefaultMenuIndex
FUNCTION_AT_ADDRESS(int  CContextMenuManager::GetDefaultMenuIndex(void),CContextMenuManager__GetDefaultMenuIndex);
#endif
#ifdef CChatWindow__CChatWindow
FUNCTION_AT_ADDRESS( CChatWindow::CChatWindow(class CXWnd *),CChatWindow__CChatWindow);
#endif
#ifdef CChatWindow__AddOutputText
FUNCTION_AT_ADDRESS(void  CChatWindow::AddOutputText(class CXStr,int),CChatWindow__AddOutputText);
#endif
#ifdef CChatWindow__HistoryBack
FUNCTION_AT_ADDRESS(void  CChatWindow::HistoryBack(void),CChatWindow__HistoryBack);
#endif
#ifdef CChatWindow__HistoryForward
FUNCTION_AT_ADDRESS(void  CChatWindow::HistoryForward(void),CChatWindow__HistoryForward);
#endif
#ifdef CChatWindow__AddHistory
FUNCTION_AT_ADDRESS(void  CChatWindow::AddHistory(class CXStr),CChatWindow__AddHistory);
#endif
#ifdef CChatWindow__GetInputText
FUNCTION_AT_ADDRESS(class CXStr  CChatWindow::GetInputText(void),CChatWindow__GetInputText);
#endif
#ifdef CChatWindow__PageUp
FUNCTION_AT_ADDRESS(void  CChatWindow::PageUp(void),CChatWindow__PageUp);
#endif
#ifdef CChatWindow__PageDown
FUNCTION_AT_ADDRESS(void  CChatWindow::PageDown(void),CChatWindow__PageDown);
#endif
#ifdef CChatWindow__SetChatFont
FUNCTION_AT_ADDRESS(void  CChatWindow::SetChatFont(int),CChatWindow__SetChatFont);
#endif
#ifdef CChatWindow__Clear
FUNCTION_AT_ADDRESS(void  CChatWindow::Clear(void),CChatWindow__Clear);
#endif
#ifdef CStmlWnd__GetSTMLText
FUNCTION_AT_ADDRESS(class CXStr*  CStmlWnd::GetSTMLText(class CXStr*&)const ,CStmlWnd__GetSTMLText);
#endif
#ifdef CChatWindow__GetInputWnd
FUNCTION_AT_ADDRESS(class CEditWnd *  CChatWindow::GetInputWnd(void),CChatWindow__GetInputWnd);
#endif
#ifdef CChatWindow__WndNotification
FUNCTION_AT_ADDRESS(int CChatWindow::WndNotification(class CXWnd *,unsigned __int32,void *),CChatWindow__WndNotification);
#endif
#ifdef CColorPickerWnd__CColorPickerWnd
FUNCTION_AT_ADDRESS( CColorPickerWnd::CColorPickerWnd(class CXWnd *),CColorPickerWnd__CColorPickerWnd);
#endif
#ifdef CColorPickerWnd__SetTemplateColor
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::SetTemplateColor(int,unsigned long),CColorPickerWnd__SetTemplateColor);
#endif
#ifdef CColorPickerWnd__Activate
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::Activate(class CXWnd *,unsigned long),CColorPickerWnd__Activate);
#endif
#ifdef CColorPickerWnd__SetCurrentColor
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::SetCurrentColor(unsigned long),CColorPickerWnd__SetCurrentColor);
#endif
#ifdef CColorPickerWnd__UpdateCurrentColor
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::UpdateCurrentColor(void),CColorPickerWnd__UpdateCurrentColor);
#endif
#ifdef CColorPickerWnd__CheckMaxEditWnd
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::CheckMaxEditWnd(void),CColorPickerWnd__CheckMaxEditWnd);
#endif
#ifdef CColorPickerWnd__UpdateEditWndFromSlider
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::UpdateEditWndFromSlider(class CSliderWnd *,class CEditWnd *,int *),CColorPickerWnd__UpdateEditWndFromSlider);
#endif
#ifdef CColorPickerWnd__UpdateSliderFromEditWnd
FUNCTION_AT_ADDRESS(void  CColorPickerWnd::UpdateSliderFromEditWnd(class CSliderWnd *,class CEditWnd *,int *),CColorPickerWnd__UpdateSliderFromEditWnd);
#endif
#ifdef CCompassWnd__CCompassWnd
FUNCTION_AT_ADDRESS( CCompassWnd::CCompassWnd(class CXWnd *),CCompassWnd__CCompassWnd);
#endif
#ifdef CCompassWnd__Activate
FUNCTION_AT_ADDRESS(void  CCompassWnd::Activate(void),CCompassWnd__Activate);
#endif
#ifdef CCompassWnd__PickNewTarget
FUNCTION_AT_ADDRESS(void  CCompassWnd::PickNewTarget(void),CCompassWnd__PickNewTarget);
#endif
#ifdef CCompassWnd__SetSpeed
FUNCTION_AT_ADDRESS(void  CCompassWnd::SetSpeed(void),CCompassWnd__SetSpeed);
#endif
#ifdef CCompassWnd__SenseHeading
FUNCTION_AT_ADDRESS(void  CCompassWnd::SenseHeading(void),CCompassWnd__SenseHeading);
#endif
#ifdef CConfirmationDialog__CConfirmationDialog
FUNCTION_AT_ADDRESS( CConfirmationDialog::CConfirmationDialog(class CXWnd *),CConfirmationDialog__CConfirmationDialog);
#endif
#ifdef CConfirmationDialog__Init
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::Init(void),CConfirmationDialog__Init);
#endif
#ifdef CConfirmationDialog__Activate
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::Activate(int,unsigned int,char const *,int,int,int,int),CConfirmationDialog__Activate);
#endif
#ifdef CConfirmationDialog__Deactivate
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::Deactivate(void),CConfirmationDialog__Deactivate);
#endif
#ifdef CConfirmationDialog__ExpireCurrentDialog
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::ExpireCurrentDialog(void),CConfirmationDialog__ExpireCurrentDialog);
#endif
#ifdef CConfirmationDialog__HandleButtonYesPressed
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::HandleButtonYesPressed(void),CConfirmationDialog__HandleButtonYesPressed);
#endif
#ifdef CConfirmationDialog__HandleButtonNoPressed
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::HandleButtonNoPressed(void),CConfirmationDialog__HandleButtonNoPressed);
#endif
#ifdef CConfirmationDialog__HandleButtonOkPressed
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::HandleButtonOkPressed(void),CConfirmationDialog__HandleButtonOkPressed);
#endif
#ifdef CConfirmationDialog__ProcessYes
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::ProcessYes(void),CConfirmationDialog__ProcessYes);
#endif
#ifdef CConfirmationDialog__ResetFocusOnClose
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::ResetFocusOnClose(void),CConfirmationDialog__ResetFocusOnClose);
#endif
#ifdef CConfirmationDialog__ProcessNo
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::ProcessNo(int),CConfirmationDialog__ProcessNo);
#endif
#ifdef CConfirmationDialog__SetNameApprovalData
FUNCTION_AT_ADDRESS(void  CConfirmationDialog::SetNameApprovalData(char *,char *,int,int,char *),CConfirmationDialog__SetNameApprovalData);
#endif
#ifdef CConfirmationDialog__WndNotification
FUNCTION_AT_ADDRESS( int CConfirmationDialog::WndNotification(class CXWnd *,unsigned __int32,void *),CConfirmationDialog__WndNotification);
#endif
#ifdef CContainerMgr__GetFreeContainerWnd
FUNCTION_AT_ADDRESS(class CContainerWnd *  CContainerMgr::GetFreeContainerWnd(void),CContainerMgr__GetFreeContainerWnd);
#endif
#ifdef CContainerMgr__CContainerMgr
FUNCTION_AT_ADDRESS( CContainerMgr::CContainerMgr(void),CContainerMgr__CContainerMgr);
#endif
#ifdef CContainerMgr__Process
FUNCTION_AT_ADDRESS(void  CContainerMgr::Process(void),CContainerMgr__Process);
#endif
#ifdef CContainerMgr__OpenWorldContainer
FUNCTION_AT_ADDRESS(void  CContainerMgr::OpenWorldContainer(class EQ_Container *,unsigned long),CContainerMgr__OpenWorldContainer);
#endif
#ifdef CContainerMgr__SetWorldContainerItem
FUNCTION_AT_ADDRESS(void  CContainerMgr::SetWorldContainerItem(class EQ_Item *,int),CContainerMgr__SetWorldContainerItem);
#endif
#ifdef CContainerMgr__GetWorldContainerItem
FUNCTION_AT_ADDRESS(class EQ_Item *  CContainerMgr::GetWorldContainerItem(int),CContainerMgr__GetWorldContainerItem);
#endif
#ifdef CContainerMgr__ClearWorldContainerItems
FUNCTION_AT_ADDRESS(void  CContainerMgr::ClearWorldContainerItems(void),CContainerMgr__ClearWorldContainerItems);
#endif
#ifdef CContainerMgr__OpenContainer
FUNCTION_AT_ADDRESS(void  CContainerMgr::OpenContainer(class EQ_Container *,int),CContainerMgr__OpenContainer);
#endif
#ifdef CContainerMgr__CloseEQContainer
FUNCTION_AT_ADDRESS(void  CContainerMgr::CloseEQContainer(class EQ_Container *),CContainerMgr__CloseEQContainer);
#endif
#ifdef CContainerMgr__CloseContainer
FUNCTION_AT_ADDRESS(void  CContainerMgr::CloseContainer(class EQ_Container *,bool),CContainerMgr__CloseContainer);
#endif
#ifdef CContainerMgr__CloseAllContainers
FUNCTION_AT_ADDRESS(bool  CContainerMgr::CloseAllContainers(void),CContainerMgr__CloseAllContainers);
#endif
#ifdef CContainerWnd__CContainerWnd
FUNCTION_AT_ADDRESS( CContainerWnd::CContainerWnd(class CXWnd *),CContainerWnd__CContainerWnd);
#endif
#ifdef CContainerWnd__Activate
FUNCTION_AT_ADDRESS(void  CContainerWnd::Activate(void),CContainerWnd__Activate);
#endif
#ifdef CHelpWnd__Activate
FUNCTION_AT_ADDRESS(void  CHelpWnd::Activate(void),CHelpWnd__Activate);
#endif
#ifdef CContainerWnd__HandleCombine
FUNCTION_AT_ADDRESS(void  CContainerWnd::HandleCombine(void),CContainerWnd__HandleCombine);
#endif
#ifdef CContainerWnd__SetContainer
FUNCTION_AT_ADDRESS(void  CContainerWnd::SetContainer(class EQ_Container *,int),CContainerWnd__SetContainer);
#endif
#ifdef CContainerWnd__CheckCloseable
FUNCTION_AT_ADDRESS(void  CContainerWnd::CheckCloseable(void),CContainerWnd__CheckCloseable);
#endif
#ifdef CContainerWnd__ContainsNoDrop
FUNCTION_AT_ADDRESS(bool  CContainerWnd::ContainsNoDrop(void),CContainerWnd__ContainsNoDrop);
#endif
#ifdef CXRect__operator_or
FUNCTION_AT_ADDRESS(class CXRect  CXRect::operator|(class CXRect)const ,CXRect__operator_or);
#endif
#ifdef CContextMenu__CContextMenu
FUNCTION_AT_ADDRESS( CContextMenu::CContextMenu(class CXWnd *,unsigned __int32,class CXRect),CContextMenu__CContextMenu);
#endif
#ifdef CContextMenu__AddMenuItem
FUNCTION_AT_ADDRESS(int  CContextMenu::AddMenuItem(class CXStr,unsigned int,bool,unsigned long),CContextMenu__AddMenuItem);
#endif
#ifdef CContextMenu__AddSeparator
FUNCTION_AT_ADDRESS(int  CContextMenu::AddSeparator(void),CContextMenu__AddSeparator);
#endif
#ifdef CContextMenu__RemoveAllMenuItems
FUNCTION_AT_ADDRESS(void  CContextMenu::RemoveAllMenuItems(void),CContextMenu__RemoveAllMenuItems);
#endif
#ifdef CContextMenu__EnableMenuItem
FUNCTION_AT_ADDRESS(void  CContextMenu::EnableMenuItem(int,bool),CContextMenu__EnableMenuItem);
#endif
#ifdef CContextMenu__CheckMenuItem
FUNCTION_AT_ADDRESS(void  CContextMenu::CheckMenuItem(int,bool,bool),CContextMenu__CheckMenuItem);
#endif
#ifdef CContextMenu__Activate
FUNCTION_AT_ADDRESS(void  CContextMenu::Activate(class CXPoint,int,int),CContextMenu__Activate);
#endif
#ifdef CContextMenuManager__CContextMenuManager
FUNCTION_AT_ADDRESS( CContextMenuManager::CContextMenuManager(class CXWnd *,unsigned __int32,class CXRect),CContextMenuManager__CContextMenuManager);
#endif
#ifdef CContextMenuManager__RemoveMenu
FUNCTION_AT_ADDRESS(int  CContextMenuManager::RemoveMenu(int,bool),CContextMenuManager__RemoveMenu);
#endif
#ifdef CContextMenuManager__AddMenu
FUNCTION_AT_ADDRESS(int  CContextMenuManager::AddMenu(class CContextMenu *),CContextMenuManager__AddMenu);
#endif
#ifdef CContextMenuManager__PopupMenu
FUNCTION_AT_ADDRESS(int  CContextMenuManager::PopupMenu(int,class CXPoint,class CXWnd *),CContextMenuManager__PopupMenu);
#endif
#ifdef CContextMenuManager__Flush
FUNCTION_AT_ADDRESS(void  CContextMenuManager::Flush(void),CContextMenuManager__Flush);
#endif
#ifdef CContextMenuManager__CreateDefaultMenu
FUNCTION_AT_ADDRESS(void  CContextMenuManager::CreateDefaultMenu(void),CContextMenuManager__CreateDefaultMenu);
#endif
#ifdef CContextMenuManager__WarnDefaultMenu
FUNCTION_AT_ADDRESS(void  CContextMenuManager::WarnDefaultMenu(class CXWnd *),CContextMenuManager__WarnDefaultMenu);
#endif
#ifdef CContextMenuManager__HandleWindowMenuCommands
FUNCTION_AT_ADDRESS(int  CContextMenuManager::HandleWindowMenuCommands(class CXWnd *,int),CContextMenuManager__HandleWindowMenuCommands);
#endif
#ifdef CXRect__Width
FUNCTION_AT_ADDRESS(int  CXRect::Width(void)const ,CXRect__Width);
#endif
#ifdef CCursorAttachment__CCursorAttachment
FUNCTION_AT_ADDRESS( CCursorAttachment::CCursorAttachment(class CXWnd *),CCursorAttachment__CCursorAttachment);
#endif
#ifdef CCursorAttachment__Init
FUNCTION_AT_ADDRESS(void  CCursorAttachment::Init(void),CCursorAttachment__Init);
#endif
#ifdef CCursorAttachment__Activate
FUNCTION_AT_ADDRESS(void  CCursorAttachment::Activate(class CTextureAnimation *,int,int,int),CCursorAttachment__Activate);
#endif
#ifdef CCursorAttachment__DrawButtonText
FUNCTION_AT_ADDRESS(void  CCursorAttachment::DrawButtonText(void)const ,CCursorAttachment__DrawButtonText);
#endif
#ifdef CCursorAttachment__DrawQuantity
FUNCTION_AT_ADDRESS(void  CCursorAttachment::DrawQuantity(void)const ,CCursorAttachment__DrawQuantity);
#endif
#ifdef CCursorAttachment__IsOkToActivate
FUNCTION_AT_ADDRESS(bool  CCursorAttachment::IsOkToActivate(int),CCursorAttachment__IsOkToActivate);
#endif
#ifdef CCursorAttachment__RemoveAttachment
FUNCTION_AT_ADDRESS(bool  CCursorAttachment::RemoveAttachment(void),CCursorAttachment__RemoveAttachment);
#endif
#ifdef CTextureAnimation__Reset
FUNCTION_AT_ADDRESS(void  CTextureAnimation::Reset(void),CTextureAnimation__Reset);
#endif
#ifdef CEditLabelWnd__CEditLabelWnd
FUNCTION_AT_ADDRESS( CEditLabelWnd::CEditLabelWnd(class CXWnd *),CEditLabelWnd__CEditLabelWnd);
#endif
#ifdef CEditLabelWnd__Activate
FUNCTION_AT_ADDRESS(void  CEditLabelWnd::Activate(class CXWnd *,char *,int,unsigned long),CEditLabelWnd__Activate);
#endif
#ifdef CEQSuiteTextureLoader__dCEQSuiteTextureLoader
FUNCTION_AT_ADDRESS( CEQSuiteTextureLoader::~CEQSuiteTextureLoader(void),CEQSuiteTextureLoader__dCEQSuiteTextureLoader);
#endif
#ifdef CEQSuiteTextureLoader__CreateTexture
FUNCTION_AT_ADDRESS(unsigned int  CEQSuiteTextureLoader::CreateTexture(class CUITextureInfo const &),CEQSuiteTextureLoader__CreateTexture);
#endif
#ifdef CEQSuiteTextureLoader__UnloadAllTextures
FUNCTION_AT_ADDRESS(void  CEQSuiteTextureLoader::UnloadAllTextures(void),CEQSuiteTextureLoader__UnloadAllTextures);
#endif
#ifdef CEQSuiteTextureLoader__GetTexture
FUNCTION_AT_ADDRESS(struct T3D_tagBMINFO *  CEQSuiteTextureLoader::GetTexture(class CUITextureInfo const &),CEQSuiteTextureLoader__GetTexture);
#endif
#ifdef CUITextureInfo__GetName
FUNCTION_AT_ADDRESS(class CXStr  CUITextureInfo::GetName(void)const ,CUITextureInfo__GetName);
#endif
#ifdef CEQSuiteTextureLoader__CEQSuiteTextureLoader
FUNCTION_AT_ADDRESS( CEQSuiteTextureLoader::CEQSuiteTextureLoader(void),CEQSuiteTextureLoader__CEQSuiteTextureLoader);
#endif
#ifdef CExploreModeWnd__CExploreModeWnd
FUNCTION_AT_ADDRESS( CExploreModeWnd::CExploreModeWnd(class CXWnd *),CExploreModeWnd__CExploreModeWnd);
#endif
#ifdef CExploreModeWnd__Activate
FUNCTION_AT_ADDRESS(void  CExploreModeWnd::Activate(void),CExploreModeWnd__Activate);
#endif
#ifdef CFacePick__CFacePick
FUNCTION_AT_ADDRESS( CFacePick::CFacePick(class CXWnd *),CFacePick__CFacePick);
#endif
#ifdef CFacePick__Init
FUNCTION_AT_ADDRESS(void  CFacePick::Init(void),CFacePick__Init);
#endif
#ifdef CFacePick__ShowButtonGroup
FUNCTION_AT_ADDRESS(void  CFacePick::ShowButtonGroup(int,bool),CFacePick__ShowButtonGroup);
#endif
#ifdef CFacePick__Activate
FUNCTION_AT_ADDRESS(void  CFacePick::Activate(void),CFacePick__Activate);
#endif
#ifdef CFacePick__SetFaceSelectionsFromPlayer
FUNCTION_AT_ADDRESS(void  CFacePick::SetFaceSelectionsFromPlayer(void),CFacePick__SetFaceSelectionsFromPlayer);
#endif
#ifdef CFacePick__CycleThroughFHEB
FUNCTION_AT_ADDRESS(void  CFacePick::CycleThroughFHEB(int,int),CFacePick__CycleThroughFHEB);
#endif
#ifdef CFeedbackWnd__CFeedbackWnd
FUNCTION_AT_ADDRESS( CFeedbackWnd::CFeedbackWnd(class CXWnd *),CFeedbackWnd__CFeedbackWnd);
#endif
#ifdef CFeedbackWnd__Activate
FUNCTION_AT_ADDRESS(void  CFeedbackWnd::Activate(void),CFeedbackWnd__Activate);
#endif
#ifdef CFileSelectionWnd__CFileSelectionWnd
FUNCTION_AT_ADDRESS( CFileSelectionWnd::CFileSelectionWnd(class CXWnd *),CFileSelectionWnd__CFileSelectionWnd);
#endif
#ifdef CFileSelectionWnd__Activate
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::Activate(class CXWnd *,int),CFileSelectionWnd__Activate);
#endif
#ifdef CFileSelectionWnd__Callback
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::Callback(bool),CFileSelectionWnd__Callback);
#endif
#ifdef CFileSelectionWnd__MakeFilePath
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::MakeFilePath(void),CFileSelectionWnd__MakeFilePath);
#endif
#ifdef CFileSelectionWnd__GoSubdirectory
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::GoSubdirectory(struct _ITEMIDLIST *),CFileSelectionWnd__GoSubdirectory);
#endif
#ifdef CFileSelectionWnd__UpdateButtons
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::UpdateButtons(void),CFileSelectionWnd__UpdateButtons);
#endif
#ifdef CFileSelectionWnd__DirectoryEmpty
FUNCTION_AT_ADDRESS(bool  CFileSelectionWnd::DirectoryEmpty(struct IShellFolder *,struct _ITEMIDLIST *),CFileSelectionWnd__DirectoryEmpty);
#endif
#ifdef CFileSelectionWnd__UpdateFileList
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::UpdateFileList(void),CFileSelectionWnd__UpdateFileList);
#endif
#ifdef CFileSelectionWnd__ClearFileList
FUNCTION_AT_ADDRESS(void  CFileSelectionWnd::ClearFileList(void),CFileSelectionWnd__ClearFileList);
#endif
#ifdef CFileSelectionWnd__GetPath
FUNCTION_AT_ADDRESS(unsigned long  CFileSelectionWnd::GetPath(struct IShellFolder *,struct _ITEMIDLIST *,bool,class CXStr &),CFileSelectionWnd__GetPath);
#endif
#ifdef CFileSelectionWnd__GetSelectedFileCount
FUNCTION_AT_ADDRESS(int  CFileSelectionWnd::GetSelectedFileCount(void),CFileSelectionWnd__GetSelectedFileCount);
#endif
#ifdef CFileSelectionWnd__GetSelectedFile
FUNCTION_AT_ADDRESS(class CXStr  CFileSelectionWnd::GetSelectedFile(int),CFileSelectionWnd__GetSelectedFile);
#endif
#ifdef CXStr__Left
FUNCTION_AT_ADDRESS(class CXStr  CXStr::Left(int)const ,CXStr__Left);
#endif
#ifdef CXStr__Right
FUNCTION_AT_ADDRESS(class CXStr  CXStr::Right(int)const ,CXStr__Right);
#endif
#ifdef CFriendsWnd__CFriendsWnd
FUNCTION_AT_ADDRESS( CFriendsWnd::CFriendsWnd(class CXWnd *),CFriendsWnd__CFriendsWnd);
#endif
#ifdef CFriendsWnd__UpdateFriendsList
FUNCTION_AT_ADDRESS(void  CFriendsWnd::UpdateFriendsList(void),CFriendsWnd__UpdateFriendsList);
#endif
#ifdef CFriendsWnd__UpdateIgnoreList
FUNCTION_AT_ADDRESS(void  CFriendsWnd::UpdateIgnoreList(void),CFriendsWnd__UpdateIgnoreList);
#endif
#ifdef CFriendsWnd__Activate
FUNCTION_AT_ADDRESS(void  CFriendsWnd::Activate(void),CFriendsWnd__Activate);
#endif
#ifdef CFriendsWnd__AddFriend
FUNCTION_AT_ADDRESS(void  CFriendsWnd::AddFriend(void),CFriendsWnd__AddFriend);
#endif
#ifdef CFriendsWnd__AddIgnore
FUNCTION_AT_ADDRESS(void  CFriendsWnd::AddIgnore(void),CFriendsWnd__AddIgnore);
#endif
#ifdef CFriendsWnd__UpdateButtons
FUNCTION_AT_ADDRESS(void  CFriendsWnd::UpdateButtons(void),CFriendsWnd__UpdateButtons);
#endif
#ifdef CGemsGameWnd__CGemsGameWnd
FUNCTION_AT_ADDRESS( CGemsGameWnd::CGemsGameWnd(class CXWnd *),CGemsGameWnd__CGemsGameWnd);
#endif
#ifdef CGemsGameWnd__Init
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::Init(void),CGemsGameWnd__Init);
#endif
#ifdef CGemsGameWnd__Activate
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::Activate(void),CGemsGameWnd__Activate);
#endif
#ifdef CGemsGameWnd__Restart
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::Restart(void),CGemsGameWnd__Restart);
#endif
#ifdef CGemsGameWnd__AdvanceToNextWave
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::AdvanceToNextWave(void),CGemsGameWnd__AdvanceToNextWave);
#endif
#ifdef CGemsGameWnd__DoMatchScore
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::DoMatchScore(int),CGemsGameWnd__DoMatchScore);
#endif
#ifdef CGemsGameWnd__DrawSpellGem
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::DrawSpellGem(int,class CXRect,int,bool)const ,CGemsGameWnd__DrawSpellGem);
#endif
#ifdef CGemsGameWnd__SetPause
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::SetPause(bool),CGemsGameWnd__SetPause);
#endif
#ifdef CGemsGameWnd__TogglePause
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::TogglePause(void),CGemsGameWnd__TogglePause);
#endif
#ifdef CGemsGameWnd__SetNextUpdate
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::SetNextUpdate(void),CGemsGameWnd__SetNextUpdate);
#endif
#ifdef CGemsGameWnd__GetRndBlockImage
FUNCTION_AT_ADDRESS(int  CGemsGameWnd::GetRndBlockImage(void),CGemsGameWnd__GetRndBlockImage);
#endif
#ifdef CGemsGameWnd__BadSpecial
FUNCTION_AT_ADDRESS(bool  CGemsGameWnd::BadSpecial(int)const ,CGemsGameWnd__BadSpecial);
#endif
#ifdef CGemsGameWnd__ActivateSpecialMode
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::ActivateSpecialMode(int),CGemsGameWnd__ActivateSpecialMode);
#endif
#ifdef CGemsGameWnd__GetNextBlock
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::GetNextBlock(void),CGemsGameWnd__GetNextBlock);
#endif
#ifdef CGemsGameWnd__MoveCurBlock
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::MoveCurBlock(int),CGemsGameWnd__MoveCurBlock);
#endif
#ifdef CGemsGameWnd__ProcessMoveCurBlock
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::ProcessMoveCurBlock(int),CGemsGameWnd__ProcessMoveCurBlock);
#endif
#ifdef CGemsGameWnd__LegalBlockMove
FUNCTION_AT_ADDRESS(bool  CGemsGameWnd::LegalBlockMove(int,int,int,int,bool),CGemsGameWnd__LegalBlockMove);
#endif
#ifdef CGemsGameWnd__MarkHigherBlocksFalling
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::MarkHigherBlocksFalling(int,int),CGemsGameWnd__MarkHigherBlocksFalling);
#endif
#ifdef CGemsGameWnd__ClearBlock
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::ClearBlock(struct _GemsBlock *),CGemsGameWnd__ClearBlock);
#endif
#ifdef CGemsGameWnd__ClearHighScores
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::ClearHighScores(void),CGemsGameWnd__ClearHighScores);
#endif
#ifdef CGemsGameWnd__ReadHighScores
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::ReadHighScores(void),CGemsGameWnd__ReadHighScores);
#endif
#ifdef CGemsGameWnd__WriteHighScores
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::WriteHighScores(void),CGemsGameWnd__WriteHighScores);
#endif
#ifdef CGemsGameWnd__CheckForNewHighScore
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::CheckForNewHighScore(void),CGemsGameWnd__CheckForNewHighScore);
#endif
#ifdef CGemsGameWnd__ProcessMatches
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::ProcessMatches(int),CGemsGameWnd__ProcessMatches);
#endif
#ifdef CGemsGameWnd__CheckForMatches
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::CheckForMatches(int,int),CGemsGameWnd__CheckForMatches);
#endif
#ifdef CGemsGameWnd__MakeBlockDrop
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::MakeBlockDrop(int,int,int),CGemsGameWnd__MakeBlockDrop);
#endif
#ifdef CGemsGameWnd__Update
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::Update(void),CGemsGameWnd__Update);
#endif
#ifdef CGemsGameWnd__UpdateDisplay
FUNCTION_AT_ADDRESS(void  CGemsGameWnd::UpdateDisplay(void),CGemsGameWnd__UpdateDisplay);
#endif
#ifdef CGiveWnd__CGiveWnd
FUNCTION_AT_ADDRESS( CGiveWnd::CGiveWnd(class CXWnd *),CGiveWnd__CGiveWnd);
#endif
#ifdef CGiveWnd__Activate
FUNCTION_AT_ADDRESS(void  CGiveWnd::Activate(void),CGiveWnd__Activate);
#endif
#ifdef CGiveWnd__UpdateGiveDisplay
FUNCTION_AT_ADDRESS(void  CGiveWnd::UpdateGiveDisplay(void),CGiveWnd__UpdateGiveDisplay);
#endif
#ifdef CGroupSearchFiltersWnd__CGroupSearchFiltersWnd
FUNCTION_AT_ADDRESS( CGroupSearchFiltersWnd::CGroupSearchFiltersWnd(class CXWnd *),CGroupSearchFiltersWnd__CGroupSearchFiltersWnd);
#endif
#ifdef CGroupSearchFiltersWnd__Activate
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::Activate(void),CGroupSearchFiltersWnd__Activate);
#endif
#ifdef CGroupSearchFiltersWnd__ClearUiPointers
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::ClearUiPointers(void),CGroupSearchFiltersWnd__ClearUiPointers);
#endif
#ifdef CGroupSearchFiltersWnd__FetchUiPointers
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::FetchUiPointers(void),CGroupSearchFiltersWnd__FetchUiPointers);
#endif
#ifdef CGroupSearchFiltersWnd__InitPieces
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::InitPieces(void),CGroupSearchFiltersWnd__InitPieces);
#endif
#ifdef CGroupSearchFiltersWnd__ShouldFilterPlayer
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::ShouldFilterPlayer(char const *,char const *)const ,CGroupSearchFiltersWnd__ShouldFilterPlayer);
#endif
#ifdef CGroupSearchFiltersWnd__UseExclusiveSearchMode
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::UseExclusiveSearchMode(void)const ,CGroupSearchFiltersWnd__UseExclusiveSearchMode);
#endif
#ifdef CGroupSearchFiltersWnd__HandleUseIgnoreListSelected
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleUseIgnoreListSelected(void),CGroupSearchFiltersWnd__HandleUseIgnoreListSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleUseFriendsListSelected
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleUseFriendsListSelected(void),CGroupSearchFiltersWnd__HandleUseFriendsListSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleExcludeGuildsSelected
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleExcludeGuildsSelected(void),CGroupSearchFiltersWnd__HandleExcludeGuildsSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleDesiredGuildsSelected
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleDesiredGuildsSelected(void),CGroupSearchFiltersWnd__HandleDesiredGuildsSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleAddExcludedGuild
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleAddExcludedGuild(void),CGroupSearchFiltersWnd__HandleAddExcludedGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveExcludedGuild
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleRemoveExcludedGuild(void),CGroupSearchFiltersWnd__HandleRemoveExcludedGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveAllExcludedGuilds
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleRemoveAllExcludedGuilds(void),CGroupSearchFiltersWnd__HandleRemoveAllExcludedGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__HandleAddDesiredGuild
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleAddDesiredGuild(void),CGroupSearchFiltersWnd__HandleAddDesiredGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveDesiredGuild
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleRemoveDesiredGuild(void),CGroupSearchFiltersWnd__HandleRemoveDesiredGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveAllDesiredGuilds
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::HandleRemoveAllDesiredGuilds(void),CGroupSearchFiltersWnd__HandleRemoveAllDesiredGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__UseIgnoreList
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::UseIgnoreList(void)const ,CGroupSearchFiltersWnd__UseIgnoreList);
#endif
#ifdef CGroupSearchFiltersWnd__UseFriendsList
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::UseFriendsList(void)const ,CGroupSearchFiltersWnd__UseFriendsList);
#endif
#ifdef CGroupSearchFiltersWnd__UseExcludedGuilds
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::UseExcludedGuilds(void)const ,CGroupSearchFiltersWnd__UseExcludedGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__UseDesiredGuilds
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::UseDesiredGuilds(void)const ,CGroupSearchFiltersWnd__UseDesiredGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__NameIsInIgnoreList
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::NameIsInIgnoreList(char const *)const ,CGroupSearchFiltersWnd__NameIsInIgnoreList);
#endif
#ifdef CGroupSearchFiltersWnd__NameIsInFriendsList
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::NameIsInFriendsList(char const *)const ,CGroupSearchFiltersWnd__NameIsInFriendsList);
#endif
#ifdef CGroupSearchFiltersWnd__GuildIsInExcludedGuildsList
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::GuildIsInExcludedGuildsList(char const *)const ,CGroupSearchFiltersWnd__GuildIsInExcludedGuildsList);
#endif
#ifdef CGroupSearchFiltersWnd__GuildIsInDesiredGuildsList
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::GuildIsInDesiredGuildsList(char const *)const ,CGroupSearchFiltersWnd__GuildIsInDesiredGuildsList);
#endif
#ifdef CGroupSearchFiltersWnd__Save
FUNCTION_AT_ADDRESS(void  CGroupSearchFiltersWnd::Save(void)const ,CGroupSearchFiltersWnd__Save);
#endif
#ifdef CGroupSearchFiltersWnd__Load
FUNCTION_AT_ADDRESS(bool  CGroupSearchFiltersWnd::Load(void),CGroupSearchFiltersWnd__Load);
#endif
#ifdef CGroupSearchWnd__CGroupSearchWnd
FUNCTION_AT_ADDRESS( CGroupSearchWnd::CGroupSearchWnd(class CXWnd *),CGroupSearchWnd__CGroupSearchWnd);
#endif
#ifdef CGroupSearchWnd__Activate
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::Activate(int),CGroupSearchWnd__Activate);
#endif
#ifdef CGroupSearchWnd__ClearUiPointers
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::ClearUiPointers(void),CGroupSearchWnd__ClearUiPointers);
#endif
#ifdef CGroupSearchWnd__FetchUiPointers
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::FetchUiPointers(void),CGroupSearchWnd__FetchUiPointers);
#endif
#ifdef CGroupSearchWnd__ResetGroupList
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::ResetGroupList(void),CGroupSearchWnd__ResetGroupList);
#endif
#ifdef CGroupSearchWnd__AddGroupResult
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::AddGroupResult(struct LfgGroupResult const *),CGroupSearchWnd__AddGroupResult);
#endif
#ifdef SListWndLine__dSListWndLine
FUNCTION_AT_ADDRESS( SListWndLine::~SListWndLine(void),SListWndLine__dSListWndLine);
#endif
#ifdef CUITextureInfo__dCUITextureInfo
FUNCTION_AT_ADDRESS( CUITextureInfo::~CUITextureInfo(void),CUITextureInfo__dCUITextureInfo);
#endif
#ifdef CUITexturePiece__dCUITexturePiece
FUNCTION_AT_ADDRESS( CUITexturePiece::~CUITexturePiece(void),CUITexturePiece__dCUITexturePiece);
#endif
#ifdef SListWndCell__dSListWndCell
FUNCTION_AT_ADDRESS( SListWndCell::~SListWndCell(void),SListWndCell__dSListWndCell);
#endif
#ifdef STextureAnimationFrame__dSTextureAnimationFrame
FUNCTION_AT_ADDRESS( STextureAnimationFrame::~STextureAnimationFrame(void),STextureAnimationFrame__dSTextureAnimationFrame);
#endif
#ifdef CGroupSearchWnd__ResetPlayerList
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::ResetPlayerList(void),CGroupSearchWnd__ResetPlayerList);
#endif
#ifdef CGroupSearchWnd__AddPlayerResult
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::AddPlayerResult(struct LfgPlayerResult const *),CGroupSearchWnd__AddPlayerResult);
#endif
#ifdef CGroupSearchWnd__InitLfg
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::InitLfg(void),CGroupSearchWnd__InitLfg);
#endif
#ifdef CGroupSearchWnd__InitLfp
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::InitLfp(void),CGroupSearchWnd__InitLfp);
#endif
#ifdef CGroupSearchWnd__UpdatePlayerLabel
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::UpdatePlayerLabel(void),CGroupSearchWnd__UpdatePlayerLabel);
#endif
#ifdef CGroupSearchWnd__UpdateGroupLabel
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::UpdateGroupLabel(void),CGroupSearchWnd__UpdateGroupLabel);
#endif
#ifdef CGroupSearchWnd__RedirectOnProcessFrameTo
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::RedirectOnProcessFrameTo(class CPageWnd *),CGroupSearchWnd__RedirectOnProcessFrameTo);
#endif
#ifdef CGroupSearchWnd__RedirectWndNotificationTo
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::RedirectWndNotificationTo(class CPageWnd *,class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__RedirectWndNotificationTo);
#endif
#ifdef CGroupSearchWnd__PlayerInfoPageWndNotification
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::PlayerInfoPageWndNotification(class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__PlayerInfoPageWndNotification);
#endif
#ifdef CGroupSearchWnd__GroupInfoPageWndNotification
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GroupInfoPageWndNotification(class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__GroupInfoPageWndNotification);
#endif
#ifdef CGroupSearchWnd__PlayerListPageWndNotification
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::PlayerListPageWndNotification(class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__PlayerListPageWndNotification);
#endif
#ifdef CGroupSearchWnd__GroupListPageWndNotification
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GroupListPageWndNotification(class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__GroupListPageWndNotification);
#endif
#ifdef CGroupSearchWnd__PlayerInfoPageOnProcessFrame
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::PlayerInfoPageOnProcessFrame(void),CGroupSearchWnd__PlayerInfoPageOnProcessFrame);
#endif
#ifdef CGroupSearchWnd__GroupInfoPageOnProcessFrame
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GroupInfoPageOnProcessFrame(void),CGroupSearchWnd__GroupInfoPageOnProcessFrame);
#endif
#ifdef CGroupSearchWnd__HandlePlayerInfoPost
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandlePlayerInfoPost(void),CGroupSearchWnd__HandlePlayerInfoPost);
#endif
#ifdef CGroupSearchWnd__HandlePlayerInfoUpdate
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandlePlayerInfoUpdate(void),CGroupSearchWnd__HandlePlayerInfoUpdate);
#endif
#ifdef CGroupSearchWnd__HandlePlayerInfoRemove
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandlePlayerInfoRemove(void),CGroupSearchWnd__HandlePlayerInfoRemove);
#endif
#ifdef CGroupSearchWnd__HandleGroupInfoPost
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleGroupInfoPost(void),CGroupSearchWnd__HandleGroupInfoPost);
#endif
#ifdef CGroupSearchWnd__HandleGroupInfoUpdate
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleGroupInfoUpdate(void),CGroupSearchWnd__HandleGroupInfoUpdate);
#endif
#ifdef CGroupSearchWnd__HandleGroupInfoRemove
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleGroupInfoRemove(void),CGroupSearchWnd__HandleGroupInfoRemove);
#endif
#ifdef CGroupSearchWnd__HandleSelectAllClasses
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleSelectAllClasses(void),CGroupSearchWnd__HandleSelectAllClasses);
#endif
#ifdef CGroupSearchWnd__HandleDeselectAllClasses
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleDeselectAllClasses(void),CGroupSearchWnd__HandleDeselectAllClasses);
#endif
#ifdef CGroupSearchWnd__HandleOpenFiltersWindow
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleOpenFiltersWindow(void),CGroupSearchWnd__HandleOpenFiltersWindow);
#endif
#ifdef CGroupSearchWnd__HandleQueryingForGroups
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleQueryingForGroups(void),CGroupSearchWnd__HandleQueryingForGroups);
#endif
#ifdef CGroupSearchWnd__HandleQueryingForPlayers
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleQueryingForPlayers(void),CGroupSearchWnd__HandleQueryingForPlayers);
#endif
#ifdef CGroupSearchWnd__SendServerLfgOn
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::SendServerLfgOn(void),CGroupSearchWnd__SendServerLfgOn);
#endif
#ifdef CGroupSearchWnd__SendServerLfgOff
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::SendServerLfgOff(void),CGroupSearchWnd__SendServerLfgOff);
#endif
#ifdef CGroupSearchWnd__SendServerLfpOn
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::SendServerLfpOn(void),CGroupSearchWnd__SendServerLfpOn);
#endif
#ifdef CGroupSearchWnd__SendServerLfpOff
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::SendServerLfpOff(void),CGroupSearchWnd__SendServerLfpOff);
#endif
#ifdef CGroupSearchWnd__ShowGroupDetails
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::ShowGroupDetails(struct LfgGroupResult const *),CGroupSearchWnd__ShowGroupDetails);
#endif
#ifdef CGroupSearchWnd__PlayerShouldBeFiltered
FUNCTION_AT_ADDRESS(bool  CGroupSearchWnd::PlayerShouldBeFiltered(struct LfgPlayerData const *)const ,CGroupSearchWnd__PlayerShouldBeFiltered);
#endif
#ifdef CGroupSearchWnd__FilterOutBadWords
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::FilterOutBadWords(char const *,char *)const ,CGroupSearchWnd__FilterOutBadWords);
#endif
#ifdef CGroupSearchWnd__LockQueryButtonAtTime
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::LockQueryButtonAtTime(long),CGroupSearchWnd__LockQueryButtonAtTime);
#endif
#ifdef CGroupSearchWnd__UpdateRemainingQueryLockedTime
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::UpdateRemainingQueryLockedTime(long),CGroupSearchWnd__UpdateRemainingQueryLockedTime);
#endif
#ifdef CGroupSearchWnd__HandleGroupResultColSelected
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleGroupResultColSelected(int),CGroupSearchWnd__HandleGroupResultColSelected);
#endif
#ifdef CGroupSearchWnd__HandlePlayerResultColSelected
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandlePlayerResultColSelected(int),CGroupSearchWnd__HandlePlayerResultColSelected);
#endif
#ifdef CGroupSearchWnd__HandleGroupResultRowSelected
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleGroupResultRowSelected(int),CGroupSearchWnd__HandleGroupResultRowSelected);
#endif
#ifdef CGroupSearchWnd__HandleDoubleClickedOnPlayer
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleDoubleClickedOnPlayer(char const *),CGroupSearchWnd__HandleDoubleClickedOnPlayer);
#endif
#ifdef CGroupSearchWnd__HandleNumericSort
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleNumericSort(class SListWndSortInfo *),CGroupSearchWnd__HandleNumericSort);
#endif
#ifdef CGroupSearchWnd__HandleGroupMakeupChanged
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::HandleGroupMakeupChanged(void),CGroupSearchWnd__HandleGroupMakeupChanged);
#endif
#ifdef CGroupSearchWnd__CheckIfCurrentLfgInfoIsValid
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::CheckIfCurrentLfgInfoIsValid(void)const ,CGroupSearchWnd__CheckIfCurrentLfgInfoIsValid);
#endif
#ifdef CGroupSearchWnd__CheckIfCurrentLfpInfoIsValid
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::CheckIfCurrentLfpInfoIsValid(void)const ,CGroupSearchWnd__CheckIfCurrentLfpInfoIsValid);
#endif
#ifdef CGroupSearchWnd__UpdateLfgPostingStatus
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::UpdateLfgPostingStatus(void),CGroupSearchWnd__UpdateLfgPostingStatus);
#endif
#ifdef CGroupSearchWnd__UpdateLfpPostingStatus
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::UpdateLfpPostingStatus(void),CGroupSearchWnd__UpdateLfpPostingStatus);
#endif
#ifdef CGroupSearchWnd__GetDesiredPlayerMinLevel
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GetDesiredPlayerMinLevel(void)const ,CGroupSearchWnd__GetDesiredPlayerMinLevel);
#endif
#ifdef CGroupSearchWnd__GetDefaultLfgLevelRange
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::GetDefaultLfgLevelRange(class EQ_PC const *,int *,int *)const ,CGroupSearchWnd__GetDefaultLfgLevelRange);
#endif
#ifdef CGroupSearchWnd__GetDefaultLfpLevelRange
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::GetDefaultLfpLevelRange(class EQ_PC const *,int *,int *)const ,CGroupSearchWnd__GetDefaultLfpLevelRange);
#endif
#ifdef CGroupSearchWnd__GetDesiredPlayerMaxLevel
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GetDesiredPlayerMaxLevel(void)const ,CGroupSearchWnd__GetDesiredPlayerMaxLevel);
#endif
#ifdef CGroupSearchWnd__GetDesiredGroupMinLevel
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GetDesiredGroupMinLevel(void)const ,CGroupSearchWnd__GetDesiredGroupMinLevel);
#endif
#ifdef CGroupSearchWnd__GetDesiredGroupMaxLevel
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GetDesiredGroupMaxLevel(void)const ,CGroupSearchWnd__GetDesiredGroupMaxLevel);
#endif
#ifdef CGroupSearchWnd__IsLevelRangeValid
FUNCTION_AT_ADDRESS(bool  CGroupSearchWnd::IsLevelRangeValid(int,int)const ,CGroupSearchWnd__IsLevelRangeValid);
#endif
#ifdef CGroupSearchWnd__GetDesiredClassesFlag
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GetDesiredClassesFlag(void)const ,CGroupSearchWnd__GetDesiredClassesFlag);
#endif
#ifdef CGroupSearchWnd__GetEqClassType
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GetEqClassType(int)const ,CGroupSearchWnd__GetEqClassType);
#endif
#ifdef CGroupSearchWnd__PopUpErrorMessage
FUNCTION_AT_ADDRESS(void  CGroupSearchWnd::PopUpErrorMessage(int)const ,CGroupSearchWnd__PopUpErrorMessage);
#endif
#ifdef Util__SetBit
FUNCTION_AT_ADDRESS(int __cdecl Util::SetBit(int,void *,int),Util__SetBit);
#endif
#ifdef _partyGroup__getNumMembers
FUNCTION_AT_ADDRESS(int  _partyGroup::getNumMembers(void)const ,_partyGroup__getNumMembers);
#endif
#ifdef SListWndCell__SListWndCell
FUNCTION_AT_ADDRESS( SListWndCell::SListWndCell(void),SListWndCell__SListWndCell);
#endif
#ifdef CGroupWnd__CGroupWnd
FUNCTION_AT_ADDRESS( CGroupWnd::CGroupWnd(class CXWnd *),CGroupWnd__CGroupWnd);
#endif
#ifdef CGroupWnd__Init
FUNCTION_AT_ADDRESS(void  CGroupWnd::Init(void),CGroupWnd__Init);
#endif
#ifdef CGroupWnd__Activate
FUNCTION_AT_ADDRESS(void  CGroupWnd::Activate(void),CGroupWnd__Activate);
#endif
#ifdef CGroupWnd__SetInvited
FUNCTION_AT_ADDRESS(void  CGroupWnd::SetInvited(bool),CGroupWnd__SetInvited);
#endif
#ifdef CGroupWnd__UpdateButtons
FUNCTION_AT_ADDRESS(void  CGroupWnd::UpdateButtons(void),CGroupWnd__UpdateButtons);
#endif
#ifdef CGroupWnd__KeyMapUpdated
FUNCTION_AT_ADDRESS(void  CGroupWnd::KeyMapUpdated(void),CGroupWnd__KeyMapUpdated);
#endif
#ifdef CGroupWnd__CreateLocalMenu
FUNCTION_AT_ADDRESS(void  CGroupWnd::CreateLocalMenu(void),CGroupWnd__CreateLocalMenu);
#endif
#ifdef CGroupWnd__UpdateContextMenu
FUNCTION_AT_ADDRESS(void  CGroupWnd::UpdateContextMenu(void),CGroupWnd__UpdateContextMenu);
#endif
#ifdef CGuildMgmtWnd__CGuildMgmtWnd
FUNCTION_AT_ADDRESS( CGuildMgmtWnd::CGuildMgmtWnd(class CXWnd *),CGuildMgmtWnd__CGuildMgmtWnd);
#endif
#ifdef CGuildMgmtWnd__Init
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::Init(void),CGuildMgmtWnd__Init);
#endif
#ifdef CGuildMgmtWnd__UpdateButtons
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::UpdateButtons(void),CGuildMgmtWnd__UpdateButtons);
#endif
#ifdef CGuildMgmtWnd__Clean
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::Clean(void),CGuildMgmtWnd__Clean);
#endif
#ifdef CGuildMgmtWnd__SetMOTD
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::SetMOTD(char *,char *),CGuildMgmtWnd__SetMOTD);
#endif
#ifdef CGuildMgmtWnd__SetPlayerCount
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::SetPlayerCount(int),CGuildMgmtWnd__SetPlayerCount);
#endif
#ifdef CGuildMgmtWnd__CreatePersonalNotesFilename
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::CreatePersonalNotesFilename(void),CGuildMgmtWnd__CreatePersonalNotesFilename);
#endif
#ifdef CGuildMgmtWnd__LoadPersonalNotes
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::LoadPersonalNotes(void),CGuildMgmtWnd__LoadPersonalNotes);
#endif
#ifdef CGuildMgmtWnd__SavePersonalNotes
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::SavePersonalNotes(void),CGuildMgmtWnd__SavePersonalNotes);
#endif
#ifdef CGuildMgmtWnd__GetPersonalNote
FUNCTION_AT_ADDRESS(char *  CGuildMgmtWnd::GetPersonalNote(char *),CGuildMgmtWnd__GetPersonalNote);
#endif
#ifdef CGuildMgmtWnd__SetPersonalNote
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::SetPersonalNote(char *,char *),CGuildMgmtWnd__SetPersonalNote);
#endif
#ifdef CGuildMgmtWnd__AddMember
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::AddMember(class GuildMember *),CGuildMgmtWnd__AddMember);
#endif
#ifdef CGuildMgmtWnd__RemoveMember
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::RemoveMember(class GuildMember *),CGuildMgmtWnd__RemoveMember);
#endif
#ifdef CGuildMgmtWnd__RenameMember
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::RenameMember(char *,char *),CGuildMgmtWnd__RenameMember);
#endif
#ifdef CGuildMgmtWnd__UpdateListMember
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::UpdateListMember(class GuildMember *,int),CGuildMgmtWnd__UpdateListMember);
#endif
#ifdef CGuildMgmtWnd__FindListMember
FUNCTION_AT_ADDRESS(int  CGuildMgmtWnd::FindListMember(class GuildMember *),CGuildMgmtWnd__FindListMember);
#endif
#ifdef CGuildMgmtWnd__Activate
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::Activate(void),CGuildMgmtWnd__Activate);
#endif
#ifdef CGuildMgmtWnd__CleanAndRefillListWnd
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::CleanAndRefillListWnd(bool),CGuildMgmtWnd__CleanAndRefillListWnd);
#endif
#ifdef CGuildMgmtWnd__SortList
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::SortList(int,bool),CGuildMgmtWnd__SortList);
#endif
#ifdef CGuildMgmtWnd__DumpToFile
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::DumpToFile(char *),CGuildMgmtWnd__DumpToFile);
#endif
#ifdef CGuildMgmtWnd__LoadINI
FUNCTION_AT_ADDRESS(void  CGuildMgmtWnd::LoadINI(void),CGuildMgmtWnd__LoadINI);
#endif
#ifdef CGuild__GetGuildMotd
FUNCTION_AT_ADDRESS(char *  CGuild::GetGuildMotd(void),CGuild__GetGuildMotd);
#endif
#ifdef CGuild__GetGuildMotdAuthor
FUNCTION_AT_ADDRESS(char *  CGuild::GetGuildMotdAuthor(void),CGuild__GetGuildMotdAuthor);
#endif
#ifdef EQPlayer__GetGuild
FUNCTION_AT_ADDRESS(int  EQPlayer::GetGuild(void)const ,EQPlayer__GetGuild);
#endif
#ifdef CHelpWnd__CHelpWnd
FUNCTION_AT_ADDRESS( CHelpWnd::CHelpWnd(class CXWnd *),CHelpWnd__CHelpWnd);
#endif
#ifdef CHelpWnd__SetFile
FUNCTION_AT_ADDRESS(void  CHelpWnd::SetFile(char *),CHelpWnd__SetFile);
#endif
#ifdef CHotButtonWnd__CHotButtonWnd
FUNCTION_AT_ADDRESS( CHotButtonWnd::CHotButtonWnd(class CXWnd *),CHotButtonWnd__CHotButtonWnd);
#endif
#ifdef CHotButtonWnd__Init
FUNCTION_AT_ADDRESS(void  CHotButtonWnd::Init(void),CHotButtonWnd__Init);
#endif
#ifdef CHotButtonWnd__Activate
FUNCTION_AT_ADDRESS(void  CHotButtonWnd::Activate(void),CHotButtonWnd__Activate);
#endif
#ifdef CHotButtonWnd__UpdatePage
FUNCTION_AT_ADDRESS(void  CHotButtonWnd::UpdatePage(void),CHotButtonWnd__UpdatePage);
#endif
#ifdef CHotButtonWnd__DoHotButton
FUNCTION_AT_ADDRESS(void  CHotButtonWnd::DoHotButton(int,int),CHotButtonWnd__DoHotButton);
#endif
#ifdef CHotButtonWnd__DoHotButtonRightClick
FUNCTION_AT_ADDRESS(void  CHotButtonWnd::DoHotButtonRightClick(int),CHotButtonWnd__DoHotButtonRightClick);
#endif
#ifdef CInspectWnd__CInspectWnd
FUNCTION_AT_ADDRESS( CInspectWnd::CInspectWnd(class CXWnd *),CInspectWnd__CInspectWnd);
#endif
#ifdef CInspectWnd__Init
FUNCTION_AT_ADDRESS(void  CInspectWnd::Init(void),CInspectWnd__Init);
#endif
#ifdef CInspectWnd__Activate
FUNCTION_AT_ADDRESS(void  CInspectWnd::Activate(struct _inspect *),CInspectWnd__Activate);
#endif
#ifdef CInspectWnd__AcceptInspectText
FUNCTION_AT_ADDRESS(void  CInspectWnd::AcceptInspectText(void),CInspectWnd__AcceptInspectText);
#endif
#ifdef CInspectWnd__PlayerBeingDeleted
FUNCTION_AT_ADDRESS(void  CInspectWnd::PlayerBeingDeleted(class EQPlayer *),CInspectWnd__PlayerBeingDeleted);
#endif
#ifdef CInventoryWnd__CInventoryWnd
FUNCTION_AT_ADDRESS( CInventoryWnd::CInventoryWnd(class CXWnd *),CInventoryWnd__CInventoryWnd);
#endif
#ifdef CInventoryWnd__Init
FUNCTION_AT_ADDRESS(void  CInventoryWnd::Init(void),CInventoryWnd__Init);
#endif
#ifdef CInventoryWnd__Activate
FUNCTION_AT_ADDRESS(void  CInventoryWnd::Activate(void),CInventoryWnd__Activate);
#endif
#ifdef CInventoryWnd__DestroyHeld
FUNCTION_AT_ADDRESS(void  CInventoryWnd::DestroyHeld(void),CInventoryWnd__DestroyHeld);
#endif
#ifdef CInventoryWnd__ClickedMoneyButton
FUNCTION_AT_ADDRESS(void  CInventoryWnd::ClickedMoneyButton(int,int),CInventoryWnd__ClickedMoneyButton);
#endif
#ifdef CInventoryWnd__GetInventoryQtyFromCoinType
FUNCTION_AT_ADDRESS(long  CInventoryWnd::GetInventoryQtyFromCoinType(int),CInventoryWnd__GetInventoryQtyFromCoinType);
#endif
#ifdef CInventoryWnd__UpdateMoneyDisplay
FUNCTION_AT_ADDRESS(void  CInventoryWnd::UpdateMoneyDisplay(void),CInventoryWnd__UpdateMoneyDisplay);
#endif
#ifdef CInvSlot__CInvSlot
FUNCTION_AT_ADDRESS( CInvSlot::CInvSlot(void),CInvSlot__CInvSlot);
#endif
#ifdef CInvSlot__SetInvSlotWnd
FUNCTION_AT_ADDRESS(void  CInvSlot::SetInvSlotWnd(class CInvSlotWnd *),CInvSlot__SetInvSlotWnd);
#endif
#ifdef CInvSlot__SetItem
FUNCTION_AT_ADDRESS(void  CInvSlot::SetItem(class EQ_Item *),CInvSlot__SetItem);
#endif
#ifdef CInvSlot__SliderComplete
FUNCTION_AT_ADDRESS(void  CInvSlot::SliderComplete(int),CInvSlot__SliderComplete);
#endif
#ifdef CInvSlot__HandleLButtonUp
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleLButtonUp(class CXPoint,bool),CInvSlot__HandleLButtonUp);
#endif
#ifdef CInvSlot__HandleLButtonHeld
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleLButtonHeld(class CXPoint),CInvSlot__HandleLButtonHeld);
#endif
#ifdef CInvSlot__DoDrinkEatPoison
FUNCTION_AT_ADDRESS(void  CInvSlot::DoDrinkEatPoison(class EQ_Item *,int),CInvSlot__DoDrinkEatPoison);
#endif
#ifdef CInvSlot__HandleRButtonUp
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleRButtonUp(class CXPoint *),CInvSlot__HandleRButtonUp);
#endif
#ifdef CInvSlot__HandleRButtonHeld
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleRButtonHeld(class CXPoint),CInvSlot__HandleRButtonHeld);
#endif
#ifdef CInvSlot__HandleRButtonUpAfterHeld
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleRButtonUpAfterHeld(class CXPoint),CInvSlot__HandleRButtonUpAfterHeld);
#endif
#ifdef CInvSlot__IllegalBigBank
FUNCTION_AT_ADDRESS(bool  CInvSlot::IllegalBigBank(int),CInvSlot__IllegalBigBank);
#endif
#ifdef CInvSlotMgr__CInvSlotMgr
FUNCTION_AT_ADDRESS( CInvSlotMgr::CInvSlotMgr(void),CInvSlotMgr__CInvSlotMgr);
#endif
#ifdef CInvSlotMgr__MoveItem
FUNCTION_AT_ADDRESS(int  CInvSlotMgr::MoveItem(int,int,int,int),CInvSlotMgr__MoveItem);
#endif
#ifdef CInvSlotMgr__CreateInvSlot
FUNCTION_AT_ADDRESS(class CInvSlot *  CInvSlotMgr::CreateInvSlot(class CInvSlotWnd *),CInvSlotMgr__CreateInvSlot);
#endif
#ifdef CInvSlotMgr__FindInvSlot
FUNCTION_AT_ADDRESS(class CInvSlot *  CInvSlotMgr::FindInvSlot(int),CInvSlotMgr__FindInvSlot);
#endif
#ifdef CInvSlotMgr__SelectSlot
FUNCTION_AT_ADDRESS(void  CInvSlotMgr::SelectSlot(class CInvSlot *),CInvSlotMgr__SelectSlot);
#endif
#ifdef CInvSlotMgr__UpdateSlots
FUNCTION_AT_ADDRESS(void  CInvSlotMgr::UpdateSlots(void),CInvSlotMgr__UpdateSlots);
#endif
#ifdef CItemDisplayWnd__CItemDisplayWnd
FUNCTION_AT_ADDRESS( CItemDisplayWnd::CItemDisplayWnd(class CXWnd *),CItemDisplayWnd__CItemDisplayWnd);
#endif
#ifdef CItemDisplayWnd__UpdateStrings
FUNCTION_AT_ADDRESS(void  CItemDisplayWnd::UpdateStrings(void),CItemDisplayWnd__UpdateStrings);
#endif
#ifdef CItemDisplayWnd__SetItem
FUNCTION_AT_ADDRESS(void  CItemDisplayWnd::SetItem(class EQ_Item *,bool),CItemDisplayWnd__SetItem);
#endif
#ifdef CItemDisplayWnd__SetItemText
FUNCTION_AT_ADDRESS(void  CItemDisplayWnd::SetItemText(char *),CItemDisplayWnd__SetItemText);
#endif
#ifdef CItemDisplayWnd__GetSizeString
FUNCTION_AT_ADDRESS(void  CItemDisplayWnd::GetSizeString(int,char *),CItemDisplayWnd__GetSizeString);
#endif
#ifdef CItemDisplayWnd__CreateRaceString
FUNCTION_AT_ADDRESS(class CXStr  CItemDisplayWnd::CreateRaceString(class EQ_Equipment *),CItemDisplayWnd__CreateRaceString);
#endif
#ifdef CItemDisplayWnd__CreateClassString
FUNCTION_AT_ADDRESS(class CXStr  CItemDisplayWnd::CreateClassString(class EQ_Equipment *),CItemDisplayWnd__CreateClassString);
#endif
#ifdef CItemDisplayWnd__CreateMealSizeString
FUNCTION_AT_ADDRESS(class CXStr  CItemDisplayWnd::CreateMealSizeString(class EQ_Equipment *),CItemDisplayWnd__CreateMealSizeString);
#endif
#ifdef CItemDisplayWnd__CreateModString
FUNCTION_AT_ADDRESS(class CXStr  CItemDisplayWnd::CreateModString(class EQ_Equipment *,int,int,int *),CItemDisplayWnd__CreateModString);
#endif
#ifdef CItemDisplayWnd__CreateEquipmentStatusString
FUNCTION_AT_ADDRESS(class CXStr  CItemDisplayWnd::CreateEquipmentStatusString(class EQ_Item *),CItemDisplayWnd__CreateEquipmentStatusString);
#endif
#ifdef CItemDisplayWnd__SetSpell
FUNCTION_AT_ADDRESS(void  CItemDisplayWnd::SetSpell(int SpellID,bool HasSpellDescr,int),CItemDisplayWnd__SetSpell);
#endif
#ifdef CJournalCatWnd__CJournalCatWnd
FUNCTION_AT_ADDRESS( CJournalCatWnd::CJournalCatWnd(class CXWnd *),CJournalCatWnd__CJournalCatWnd);
#endif
#ifdef CJournalCatWnd__Init
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::Init(void),CJournalCatWnd__Init);
#endif
#ifdef CJournalCatWnd__UpdateAll
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::UpdateAll(bool),CJournalCatWnd__UpdateAll);
#endif
#ifdef CJournalCatWnd__UpdateButtons
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::UpdateButtons(void),CJournalCatWnd__UpdateButtons);
#endif
#ifdef CJournalCatWnd__SelectCategory
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::SelectCategory(int),CJournalCatWnd__SelectCategory);
#endif
#ifdef CJournalCatWnd__Clean
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::Clean(void),CJournalCatWnd__Clean);
#endif
#ifdef CJournalCatWnd__BuildList
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::BuildList(void),CJournalCatWnd__BuildList);
#endif
#ifdef CJournalCatWnd__UpdateListWnd
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::UpdateListWnd(bool),CJournalCatWnd__UpdateListWnd);
#endif
#ifdef CJournalCatWnd__Activate
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::Activate(void),CJournalCatWnd__Activate);
#endif
#ifdef CJournalCatWnd__SortList
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::SortList(int,bool),CJournalCatWnd__SortList);
#endif
#ifdef CJournalCatWnd__LoadINI
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::LoadINI(void),CJournalCatWnd__LoadINI);
#endif
#ifdef CJournalCatWnd__StoreINI
FUNCTION_AT_ADDRESS(void  CJournalCatWnd::StoreINI(void),CJournalCatWnd__StoreINI);
#endif
#ifdef CJournalNPCWnd__CJournalNPCWnd
FUNCTION_AT_ADDRESS( CJournalNPCWnd::CJournalNPCWnd(class CXWnd *),CJournalNPCWnd__CJournalNPCWnd);
#endif
#ifdef CJournalNPCWnd__Init
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::Init(void),CJournalNPCWnd__Init);
#endif
#ifdef CJournalNPCWnd__Activate
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::Activate(void),CJournalNPCWnd__Activate);
#endif
#ifdef CJournalNPCWnd__UpdateAll
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::UpdateAll(bool),CJournalNPCWnd__UpdateAll);
#endif
#ifdef CJournalNPCWnd__UpdateListWnd
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::UpdateListWnd(bool),CJournalNPCWnd__UpdateListWnd);
#endif
#ifdef CJournalNPCWnd__SelectNPCIndex
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::SelectNPCIndex(int),CJournalNPCWnd__SelectNPCIndex);
#endif
#ifdef CJournalNPCWnd__UpdateCategories
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::UpdateCategories(void),CJournalNPCWnd__UpdateCategories);
#endif
#ifdef CJournalNPCWnd__UpdateButtons
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::UpdateButtons(void),CJournalNPCWnd__UpdateButtons);
#endif
#ifdef CJournalNPCWnd__EnterIntoJournal
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::EnterIntoJournal(char *,float,float,float,char *),CJournalNPCWnd__EnterIntoJournal);
#endif
#ifdef CJournalNPCWnd__DoBackups
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::DoBackups(class CXStr),CJournalNPCWnd__DoBackups);
#endif
#ifdef CJournalNPCWnd__LoadJournal
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::LoadJournal(int),CJournalNPCWnd__LoadJournal);
#endif
#ifdef CJournalNPCWnd__SaveJournal
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::SaveJournal(void),CJournalNPCWnd__SaveJournal);
#endif
#ifdef CJournalNPCWnd__BuildList
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::BuildList(void),CJournalNPCWnd__BuildList);
#endif
#ifdef CJournalNPCWnd__SortList
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::SortList(int,bool),CJournalNPCWnd__SortList);
#endif
#ifdef CJournalNPCWnd__GetLogState
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::GetLogState(void),CJournalNPCWnd__GetLogState);
#endif
#ifdef CJournalNPCWnd__StoreLogState
FUNCTION_AT_ADDRESS(void  CJournalNPCWnd::StoreLogState(void),CJournalNPCWnd__StoreLogState);
#endif
#ifdef CJournalTextWnd__CJournalTextWnd
FUNCTION_AT_ADDRESS( CJournalTextWnd::CJournalTextWnd(class CXWnd *),CJournalTextWnd__CJournalTextWnd);
#endif
#ifdef CJournalTextWnd__UpdateAll
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::UpdateAll(bool),CJournalTextWnd__UpdateAll);
#endif
#ifdef CJournalTextWnd__UpdateCategories
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::UpdateCategories(void),CJournalTextWnd__UpdateCategories);
#endif
#ifdef CJournalTextWnd__Activate
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::Activate(void),CJournalTextWnd__Activate);
#endif
#ifdef CJournalTextWnd__SetSearch
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::SetSearch(class CXStr),CJournalTextWnd__SetSearch);
#endif
#ifdef CJournalTextWnd__Clear
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::Clear(void),CJournalTextWnd__Clear);
#endif
#ifdef CJournalTextWnd__UpdateListWnd
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::UpdateListWnd(bool),CJournalTextWnd__UpdateListWnd);
#endif
#ifdef CJournalTextWnd__UpdateButtons
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::UpdateButtons(void),CJournalTextWnd__UpdateButtons);
#endif
#ifdef CJournalTextWnd__DisplayNPC
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::DisplayNPC(class JournalNPC *),CJournalTextWnd__DisplayNPC);
#endif
#ifdef CJournalTextWnd__BuildList
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::BuildList(void),CJournalTextWnd__BuildList);
#endif
#ifdef CJournalTextWnd__SelectEntryIndex
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::SelectEntryIndex(int),CJournalTextWnd__SelectEntryIndex);
#endif
#ifdef CJournalTextWnd__SortList
FUNCTION_AT_ADDRESS(void  CJournalTextWnd::SortList(int,bool),CJournalTextWnd__SortList);
#endif
#ifdef CLoadskinWnd__CLoadskinWnd
FUNCTION_AT_ADDRESS( CLoadskinWnd::CLoadskinWnd(class CXWnd *),CLoadskinWnd__CLoadskinWnd);
#endif
#ifdef CLoadskinWnd__UpdateSkinList
FUNCTION_AT_ADDRESS(void  CLoadskinWnd::UpdateSkinList(void),CLoadskinWnd__UpdateSkinList);
#endif
#ifdef CLoadskinWnd__Activate
FUNCTION_AT_ADDRESS(void  CLoadskinWnd::Activate(void),CLoadskinWnd__Activate);
#endif
#ifdef CLootWnd__CLootWnd
FUNCTION_AT_ADDRESS( CLootWnd::CLootWnd(class CXWnd *),CLootWnd__CLootWnd);
#endif
#ifdef CLootWnd__Init
FUNCTION_AT_ADDRESS(void  CLootWnd::Init(void),CLootWnd__Init);
#endif
#ifdef CLootWnd__Activate
FUNCTION_AT_ADDRESS(void  CLootWnd::Activate(unsigned char,long,long,long,long),CLootWnd__Activate);
#endif
#ifdef CLootWnd__Deactivate1
FUNCTION_AT_ADDRESS(void  CLootWnd::Deactivate(bool),CLootWnd__Deactivate1);
#endif
#ifdef CLootWnd__FinalizeLoot
FUNCTION_AT_ADDRESS(void  CLootWnd::FinalizeLoot(void),CLootWnd__FinalizeLoot);
#endif
#ifdef CLootWnd__AddEquipmentToLootArray
FUNCTION_AT_ADDRESS(void  CLootWnd::AddEquipmentToLootArray(class EQ_Item *),CLootWnd__AddEquipmentToLootArray);
#endif
#ifdef CLootWnd__AddNoteToLootArray
FUNCTION_AT_ADDRESS(void  CLootWnd::AddNoteToLootArray(class EQ_Item *),CLootWnd__AddNoteToLootArray);
#endif
#ifdef CLootWnd__AddContainerToLootArray
FUNCTION_AT_ADDRESS(void  CLootWnd::AddContainerToLootArray(class EQ_Item *),CLootWnd__AddContainerToLootArray);
#endif
#ifdef CLootWnd__RequestLootSlot
FUNCTION_AT_ADDRESS(void  CLootWnd::RequestLootSlot(int,bool),CLootWnd__RequestLootSlot);
#endif
#ifdef CLootWnd__SlotLooted
FUNCTION_AT_ADDRESS(void  CLootWnd::SlotLooted(int),CLootWnd__SlotLooted);
#endif
#ifdef CMapToolbarWnd__CMapToolbarWnd
FUNCTION_AT_ADDRESS( CMapToolbarWnd::CMapToolbarWnd(class CXWnd *),CMapToolbarWnd__CMapToolbarWnd);
#endif
#ifdef CMapToolbarWnd__Activate
FUNCTION_AT_ADDRESS(void  CMapToolbarWnd::Activate(void),CMapToolbarWnd__Activate);
#endif
#ifdef CMapToolbarWnd__SetAutoMapButton
FUNCTION_AT_ADDRESS(void  CMapToolbarWnd::SetAutoMapButton(bool),CMapToolbarWnd__SetAutoMapButton);
#endif
#ifdef CEditLabelWnd__GetLabelText
FUNCTION_AT_ADDRESS(class CXStr  CEditLabelWnd::GetLabelText(void),CEditLabelWnd__GetLabelText);
#endif
#ifdef CMapViewWnd__IsMappingEnabled
FUNCTION_AT_ADDRESS(bool  CMapViewWnd::IsMappingEnabled(void),CMapViewWnd__IsMappingEnabled);
#endif
#ifdef CMapViewWnd__CMapViewWnd
FUNCTION_AT_ADDRESS( CMapViewWnd::CMapViewWnd(class CXWnd *),CMapViewWnd__CMapViewWnd);
#endif
#ifdef CMapViewWnd__Init
FUNCTION_AT_ADDRESS(void  CMapViewWnd::Init(void),CMapViewWnd__Init);
#endif
#ifdef CMapViewWnd__Activate
FUNCTION_AT_ADDRESS(void  CMapViewWnd::Activate(void),CMapViewWnd__Activate);
#endif
#ifdef CMapViewWnd__ActivateAutoMapping
FUNCTION_AT_ADDRESS(void  CMapViewWnd::ActivateAutoMapping(void),CMapViewWnd__ActivateAutoMapping);
#endif
#ifdef CMapViewWnd__DeactivateAutoMapping
FUNCTION_AT_ADDRESS(void  CMapViewWnd::DeactivateAutoMapping(void),CMapViewWnd__DeactivateAutoMapping);
#endif
#ifdef CMapViewWnd__SetCurrentZone
//FUNCTION_AT_ADDRESS(void  CMapViewWnd::SetCurrentZone(enum EQZoneIndex,struct T3D_XYZ *,struct T3D_XYZ *),CMapViewWnd__SetCurrentZone);
#endif
#ifdef MapViewMap__MapViewMap
FUNCTION_AT_ADDRESS( MapViewMap::MapViewMap(void),MapViewMap__MapViewMap);
#endif
#ifdef MapViewMap__dMapViewMap
FUNCTION_AT_ADDRESS( MapViewMap::~MapViewMap(void),MapViewMap__dMapViewMap);
#endif
#ifdef MapViewMap__Clear
FUNCTION_AT_ADDRESS(void  MapViewMap::Clear(void),MapViewMap__Clear);
#endif
#ifdef MapViewMap__StartLine
FUNCTION_AT_ADDRESS(void  MapViewMap::StartLine(float,float,float),MapViewMap__StartLine);
#endif
#ifdef MapViewMap__EndLine
FUNCTION_AT_ADDRESS(void  MapViewMap::EndLine(float,float,float),MapViewMap__EndLine);
#endif
#ifdef MapViewMap__RemoveLine
FUNCTION_AT_ADDRESS(void  MapViewMap::RemoveLine(void),MapViewMap__RemoveLine);
#endif
#ifdef MapViewMap__AddPoint
FUNCTION_AT_ADDRESS(void  MapViewMap::AddPoint(float,float,float),MapViewMap__AddPoint);
#endif
#ifdef MapViewMap__AddLabel
FUNCTION_AT_ADDRESS(void  MapViewMap::AddLabel(float,float,float,unsigned long,int,char *),MapViewMap__AddLabel);
#endif
#ifdef MapViewMap__RecalcLabelExtents
FUNCTION_AT_ADDRESS(void  MapViewMap::RecalcLabelExtents(struct _mapviewlabel *),MapViewMap__RecalcLabelExtents);
#endif
#ifdef MapViewMap__RemoveLabel
FUNCTION_AT_ADDRESS(void  MapViewMap::RemoveLabel(void),MapViewMap__RemoveLabel);
#endif
#ifdef MapViewMap__MoveLabel
FUNCTION_AT_ADDRESS(void  MapViewMap::MoveLabel(struct _mapviewlabel *,float,float,float),MapViewMap__MoveLabel);
#endif
#ifdef MapViewMap__CalcLabelRenderOffsets
FUNCTION_AT_ADDRESS(void  MapViewMap::CalcLabelRenderOffsets(class CXRect),MapViewMap__CalcLabelRenderOffsets);
#endif
#ifdef MapViewMap__IsLayerVisible
FUNCTION_AT_ADDRESS(bool  MapViewMap::IsLayerVisible(int),MapViewMap__IsLayerVisible);
#endif
#ifdef MapViewMap__PointInMapViewArea
FUNCTION_AT_ADDRESS(bool  MapViewMap::PointInMapViewArea(class CXPoint,class CXRect),MapViewMap__PointInMapViewArea);
#endif
#ifdef MapViewMap__PreCalcRenderValues
FUNCTION_AT_ADDRESS(void  MapViewMap::PreCalcRenderValues(void),MapViewMap__PreCalcRenderValues);
#endif
#ifdef MapViewMap__TransformPoint
FUNCTION_AT_ADDRESS(void  MapViewMap::TransformPoint(struct T3D_XYZ *),MapViewMap__TransformPoint);
#endif
#ifdef MapViewMap__Draw
FUNCTION_AT_ADDRESS(void  MapViewMap::Draw(class CXRect),MapViewMap__Draw);
#endif
#ifdef MapViewMap__DrawClippedLine
FUNCTION_AT_ADDRESS(bool  MapViewMap::DrawClippedLine(struct T3D_XYZ *,struct T3D_RGB,class CXRect),MapViewMap__DrawClippedLine);
#endif
#ifdef MapViewMap__Save
FUNCTION_AT_ADDRESS(void  MapViewMap::Save(char *),MapViewMap__Save);
#endif
#ifdef MapViewMap__SaveEx
FUNCTION_AT_ADDRESS(void  MapViewMap::SaveEx(char *,int),MapViewMap__SaveEx);
#endif
#ifdef MapViewMap__Load
FUNCTION_AT_ADDRESS(void  MapViewMap::Load(char *),MapViewMap__Load);
#endif
#ifdef MapViewMap__LoadEx
FUNCTION_AT_ADDRESS(bool  MapViewMap::LoadEx(char *,int),MapViewMap__LoadEx);
#endif
#ifdef MapViewMap__GetCurrentColor
FUNCTION_AT_ADDRESS(unsigned long  MapViewMap::GetCurrentColor(void),MapViewMap__GetCurrentColor);
#endif
#ifdef MapViewMap__SetCurrentColor
FUNCTION_AT_ADDRESS(void  MapViewMap::SetCurrentColor(unsigned long),MapViewMap__SetCurrentColor);
#endif
#ifdef MapViewMap__SetMarkedLine
FUNCTION_AT_ADDRESS(void  MapViewMap::SetMarkedLine(struct _mapviewline *),MapViewMap__SetMarkedLine);
#endif
#ifdef MapViewMap__SetMarkedLineColor
FUNCTION_AT_ADDRESS(void  MapViewMap::SetMarkedLineColor(unsigned long),MapViewMap__SetMarkedLineColor);
#endif
#ifdef MapViewMap__GetMarkedLineColor
FUNCTION_AT_ADDRESS(unsigned long  MapViewMap::GetMarkedLineColor(void),MapViewMap__GetMarkedLineColor);
#endif
#ifdef MapViewMap__ClearActiveLayer
FUNCTION_AT_ADDRESS(void  MapViewMap::ClearActiveLayer(void),MapViewMap__ClearActiveLayer);
#endif
#ifdef MapViewMap__RemoveLine1
FUNCTION_AT_ADDRESS(void  MapViewMap::RemoveLine(struct _mapviewline *),MapViewMap__RemoveLine1);
#endif
#ifdef MapViewMap__RemoveLabel1
FUNCTION_AT_ADDRESS(void  MapViewMap::RemoveLabel(struct _mapviewlabel *),MapViewMap__RemoveLabel1);
#endif
#ifdef CXRect__Normalize
FUNCTION_AT_ADDRESS(void  CXRect::Normalize(void),CXRect__Normalize);
#endif
#ifdef CXRect__operator_and
FUNCTION_AT_ADDRESS(class CXRect  CXRect::operator&(class CXRect)const ,CXRect__operator_and);
#endif
#ifdef MapViewMap__JoinLinesAtIntersect
FUNCTION_AT_ADDRESS(void  MapViewMap::JoinLinesAtIntersect(bool),MapViewMap__JoinLinesAtIntersect);
#endif
#ifdef MapViewMap__SetZoneExtents
FUNCTION_AT_ADDRESS(void  MapViewMap::SetZoneExtents(int,int,int,int),MapViewMap__SetZoneExtents);
#endif
#ifdef MapViewMap__SetZoom
FUNCTION_AT_ADDRESS(void  MapViewMap::SetZoom(float),MapViewMap__SetZoom);
#endif
#ifdef MapViewMap__GetMinZ
FUNCTION_AT_ADDRESS(int  MapViewMap::GetMinZ(void),MapViewMap__GetMinZ);
#endif
#ifdef MapViewMap__GetMaxZ
FUNCTION_AT_ADDRESS(int  MapViewMap::GetMaxZ(void),MapViewMap__GetMaxZ);
#endif
#ifdef CMerchantWnd__CMerchantWnd
FUNCTION_AT_ADDRESS( CMerchantWnd::CMerchantWnd(class CXWnd *),CMerchantWnd__CMerchantWnd);
#endif
#ifdef CMerchantWnd__Init
FUNCTION_AT_ADDRESS(void  CMerchantWnd::Init(void),CMerchantWnd__Init);
#endif
#ifdef CMerchantWnd__Activate
FUNCTION_AT_ADDRESS(void  CMerchantWnd::Activate(class EQPlayer *,float),CMerchantWnd__Activate);
#endif
#ifdef CMerchantWnd__HandleBuy
FUNCTION_AT_ADDRESS(void  CMerchantWnd::HandleBuy(int),CMerchantWnd__HandleBuy);
#endif
#ifdef CMerchantWnd__HandleSell
FUNCTION_AT_ADDRESS(void  CMerchantWnd::HandleSell(int),CMerchantWnd__HandleSell);
#endif
#ifdef CMerchantWnd__UpdateBuySellButtons
FUNCTION_AT_ADDRESS(void  CMerchantWnd::UpdateBuySellButtons(void),CMerchantWnd__UpdateBuySellButtons);
#endif
#ifdef CMerchantWnd__SelectBuySellSlot
FUNCTION_AT_ADDRESS(void  CMerchantWnd::SelectBuySellSlot(int,class CTextureAnimation *),CMerchantWnd__SelectBuySellSlot);
#endif
#ifdef CMerchantWnd__DisplayBuyOrSellPrice
FUNCTION_AT_ADDRESS(void  CMerchantWnd::DisplayBuyOrSellPrice(bool,class EQ_Item *),CMerchantWnd__DisplayBuyOrSellPrice);
#endif
#ifdef CMerchantWnd__RequestBuyItem
FUNCTION_AT_ADDRESS(void  CMerchantWnd::RequestBuyItem(int),CMerchantWnd__RequestBuyItem);
#endif
#ifdef CMerchantWnd__FinishBuyingItem
FUNCTION_AT_ADDRESS(void  CMerchantWnd::FinishBuyingItem(struct _sell_msg *),CMerchantWnd__FinishBuyingItem);
#endif
#ifdef CMerchantWnd__RequestSellItem
FUNCTION_AT_ADDRESS(void  CMerchantWnd::RequestSellItem(int),CMerchantWnd__RequestSellItem);
#endif
#ifdef CMerchantWnd__FinishSellingItem
FUNCTION_AT_ADDRESS(void  CMerchantWnd::FinishSellingItem(struct _sell_msg *),CMerchantWnd__FinishSellingItem);
#endif
#ifdef CMerchantWnd__AddEquipmentToMercArray
FUNCTION_AT_ADDRESS(void  CMerchantWnd::AddEquipmentToMercArray(class EQ_Equipment *),CMerchantWnd__AddEquipmentToMercArray);
#endif
#ifdef CMerchantWnd__AddNoteToMercArray
FUNCTION_AT_ADDRESS(void  CMerchantWnd::AddNoteToMercArray(class EQ_Note *),CMerchantWnd__AddNoteToMercArray);
#endif
#ifdef CMerchantWnd__AddContainerToMercArray
FUNCTION_AT_ADDRESS(void  CMerchantWnd::AddContainerToMercArray(class EQ_Container *),CMerchantWnd__AddContainerToMercArray);
#endif
#ifdef CMerchantWnd__ClearMerchantSlot
FUNCTION_AT_ADDRESS(void  CMerchantWnd::ClearMerchantSlot(int),CMerchantWnd__ClearMerchantSlot);
#endif
#ifdef CMusicPlayerWnd__CMusicPlayerWnd
FUNCTION_AT_ADDRESS( CMusicPlayerWnd::CMusicPlayerWnd(class CXWnd *),CMusicPlayerWnd__CMusicPlayerWnd);
#endif
#ifdef CMusicPlayerWnd__Activate
FUNCTION_AT_ADDRESS(void  CMusicPlayerWnd::Activate(void),CMusicPlayerWnd__Activate);
#endif
#ifdef CMusicPlayerWnd__AutoStart
FUNCTION_AT_ADDRESS(void  CMusicPlayerWnd::AutoStart(void),CMusicPlayerWnd__AutoStart);
#endif
#ifdef CMusicPlayerWnd__Update
FUNCTION_AT_ADDRESS(void  CMusicPlayerWnd::Update(void),CMusicPlayerWnd__Update);
#endif
#ifdef CMusicPlayerWnd__UpdateButtons
FUNCTION_AT_ADDRESS(void  CMusicPlayerWnd::UpdateButtons(void),CMusicPlayerWnd__UpdateButtons);
#endif
#ifdef CNoteWnd__CNoteWnd
FUNCTION_AT_ADDRESS( CNoteWnd::CNoteWnd(class CXWnd *),CNoteWnd__CNoteWnd);
#endif
#ifdef CNoteWnd__Activate
FUNCTION_AT_ADDRESS(void  CNoteWnd::Activate(void),CNoteWnd__Activate);
#endif
#ifdef CNoteWnd__CheckNote
FUNCTION_AT_ADDRESS(bool  CNoteWnd::CheckNote(class EQ_Note *),CNoteWnd__CheckNote);
#endif
#ifdef CNoteWnd__SetNote
FUNCTION_AT_ADDRESS(void  CNoteWnd::SetNote(char *),CNoteWnd__SetNote);
#endif
#ifdef CXStr__operator_lb_rb
FUNCTION_AT_ADDRESS(char  CXStr::operator[](int)const ,CXStr__operator_lb_rb);
#endif
#ifdef COptionsWnd__COptionsWnd
FUNCTION_AT_ADDRESS( COptionsWnd::COptionsWnd(class CXWnd *),COptionsWnd__COptionsWnd);
#endif
#ifdef COptionsWnd__SyncGeneralPage
FUNCTION_AT_ADDRESS(void  COptionsWnd::SyncGeneralPage(void),COptionsWnd__SyncGeneralPage);
#endif
#ifdef COptionsWnd__SyncDisplayPage
FUNCTION_AT_ADDRESS(void  COptionsWnd::SyncDisplayPage(void),COptionsWnd__SyncDisplayPage);
#endif
#ifdef COptionsWnd__SyncMousePage
FUNCTION_AT_ADDRESS(void  COptionsWnd::SyncMousePage(void),COptionsWnd__SyncMousePage);
#endif
#ifdef COptionsWnd__SyncChatPage
FUNCTION_AT_ADDRESS(void  COptionsWnd::SyncChatPage(void),COptionsWnd__SyncChatPage);
#endif
#ifdef COptionsWnd__SyncColorPage
FUNCTION_AT_ADDRESS(void  COptionsWnd::SyncColorPage(void),COptionsWnd__SyncColorPage);
#endif
#ifdef COptionsWnd__InitKeyboardPage
FUNCTION_AT_ADDRESS(void  COptionsWnd::InitKeyboardPage(void),COptionsWnd__InitKeyboardPage);
#endif
#ifdef COptionsWnd__InitKeyboardAssignments
FUNCTION_AT_ADDRESS(void  COptionsWnd::InitKeyboardAssignments(void),COptionsWnd__InitKeyboardAssignments);
#endif
#ifdef COptionsWnd__RefreshCurrentKeyboardAssignmentList
FUNCTION_AT_ADDRESS(void  COptionsWnd::RefreshCurrentKeyboardAssignmentList(void),COptionsWnd__RefreshCurrentKeyboardAssignmentList);
#endif
#ifdef COptionsWnd__AddKeyboardAssignment
FUNCTION_AT_ADDRESS(void  COptionsWnd::AddKeyboardAssignment(int,int,int),COptionsWnd__AddKeyboardAssignment);
#endif
#ifdef COptionsWnd__Activate
FUNCTION_AT_ADDRESS(void  COptionsWnd::Activate(void),COptionsWnd__Activate);
#endif
#ifdef COptionsWnd__ResetKeysToDefault
FUNCTION_AT_ADDRESS(void  COptionsWnd::ResetKeysToDefault(void),COptionsWnd__ResetKeysToDefault);
#endif
#ifdef COptionsWnd__RedirectOnProcessFrameTo
FUNCTION_AT_ADDRESS(int  COptionsWnd::RedirectOnProcessFrameTo(class CPageWnd *),COptionsWnd__RedirectOnProcessFrameTo);
#endif
#ifdef COptionsWnd__RedirectWndNotificationTo
FUNCTION_AT_ADDRESS(int  COptionsWnd::RedirectWndNotificationTo(class CPageWnd *,class CXWnd *,unsigned __int32,void *),COptionsWnd__RedirectWndNotificationTo);
#endif
#ifdef COptionsWnd__RedirectHandleKeyboardMsgTo
FUNCTION_AT_ADDRESS(int  COptionsWnd::RedirectHandleKeyboardMsgTo(class CPageWnd *,unsigned __int32,unsigned __int32,bool),COptionsWnd__RedirectHandleKeyboardMsgTo);
#endif
#ifdef COptionsWnd__RedirectDeactivateTo
FUNCTION_AT_ADDRESS(int  COptionsWnd::RedirectDeactivateTo(class CPageWnd *),COptionsWnd__RedirectDeactivateTo);
#endif
#ifdef COptionsWnd__GeneralPageOnProcessFrame
FUNCTION_AT_ADDRESS(int  COptionsWnd::GeneralPageOnProcessFrame(void),COptionsWnd__GeneralPageOnProcessFrame);
#endif
#ifdef COptionsWnd__GeneralPageWndNotification
FUNCTION_AT_ADDRESS(int  COptionsWnd::GeneralPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__GeneralPageWndNotification);
#endif
#ifdef COptionsWnd__DisplayPageOnProcessFrame
FUNCTION_AT_ADDRESS(int  COptionsWnd::DisplayPageOnProcessFrame(void),COptionsWnd__DisplayPageOnProcessFrame);
#endif
#ifdef COptionsWnd__DisplayPageWndNotification
FUNCTION_AT_ADDRESS(int  COptionsWnd::DisplayPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__DisplayPageWndNotification);
#endif
#ifdef COptionsWnd__MousePageOnProcessFrame
FUNCTION_AT_ADDRESS(int  COptionsWnd::MousePageOnProcessFrame(void),COptionsWnd__MousePageOnProcessFrame);
#endif
#ifdef COptionsWnd__MousePageWndNotification
FUNCTION_AT_ADDRESS(int  COptionsWnd::MousePageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__MousePageWndNotification);
#endif
#ifdef COptionsWnd__KeyboardPageWndNotification
FUNCTION_AT_ADDRESS(int  COptionsWnd::KeyboardPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__KeyboardPageWndNotification);
#endif
#ifdef COptionsWnd__KeyboardPageHandleKeyboardMsg
FUNCTION_AT_ADDRESS(int  COptionsWnd::KeyboardPageHandleKeyboardMsg(unsigned __int32,unsigned __int32,bool),COptionsWnd__KeyboardPageHandleKeyboardMsg);
#endif
#ifdef COptionsWnd__KeyboardPageDeactivate
FUNCTION_AT_ADDRESS(int  COptionsWnd::KeyboardPageDeactivate(void),COptionsWnd__KeyboardPageDeactivate);
#endif
#ifdef COptionsWnd__KeyboardPageCancelKeypressAssignment
FUNCTION_AT_ADDRESS(void  COptionsWnd::KeyboardPageCancelKeypressAssignment(void),COptionsWnd__KeyboardPageCancelKeypressAssignment);
#endif
#ifdef COptionsWnd__ChatPageOnProcessFrame
FUNCTION_AT_ADDRESS(int  COptionsWnd::ChatPageOnProcessFrame(void),COptionsWnd__ChatPageOnProcessFrame);
#endif
#ifdef COptionsWnd__ColorPageOnProcessFrame
FUNCTION_AT_ADDRESS(int  COptionsWnd::ColorPageOnProcessFrame(void),COptionsWnd__ColorPageOnProcessFrame);
#endif
#ifdef COptionsWnd__ChatPageWndNotification
FUNCTION_AT_ADDRESS(int  COptionsWnd::ChatPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__ChatPageWndNotification);
#endif
#ifdef COptionsWnd__ColorPageWndNotification
FUNCTION_AT_ADDRESS(int  COptionsWnd::ColorPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__ColorPageWndNotification);
#endif
#ifdef COptionsWnd__SaveColors
FUNCTION_AT_ADDRESS(void  COptionsWnd::SaveColors(int,int,int,int),COptionsWnd__SaveColors);
#endif
#ifdef COptionsWnd__RestoreDefaultColors
FUNCTION_AT_ADDRESS(void  COptionsWnd::RestoreDefaultColors(void),COptionsWnd__RestoreDefaultColors);
#endif
#ifdef COptionsWnd__SetBagOptions
FUNCTION_AT_ADDRESS(void  COptionsWnd::SetBagOptions(int,int),COptionsWnd__SetBagOptions);
#endif
#ifdef CPetInfoWnd__CPetInfoWnd
FUNCTION_AT_ADDRESS( CPetInfoWnd::CPetInfoWnd(class CXWnd *),CPetInfoWnd__CPetInfoWnd);
#endif
#ifdef CPetInfoWnd__Activate
FUNCTION_AT_ADDRESS(void  CPetInfoWnd::Activate(void),CPetInfoWnd__Activate);
#endif
#ifdef CPetInfoWnd__SetShowOnSummon
FUNCTION_AT_ADDRESS(void  CPetInfoWnd::SetShowOnSummon(bool),CPetInfoWnd__SetShowOnSummon);
#endif
#ifdef CPetInfoWnd__Update
FUNCTION_AT_ADDRESS(void  CPetInfoWnd::Update(void),CPetInfoWnd__Update);
#endif
#ifdef CPetInfoWnd__GetButton
FUNCTION_AT_ADDRESS(class CButtonWnd *  CPetInfoWnd::GetButton(int),CPetInfoWnd__GetButton);
#endif
#ifdef CPetitionQWnd__CPetitionQWnd
FUNCTION_AT_ADDRESS( CPetitionQWnd::CPetitionQWnd(class CXWnd *),CPetitionQWnd__CPetitionQWnd);
#endif
#ifdef CPetitionQWnd__UpdatePetitions
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::UpdatePetitions(void),CPetitionQWnd__UpdatePetitions);
#endif
#ifdef CPetitionQWnd__Activate
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::Activate(void),CPetitionQWnd__Activate);
#endif
#ifdef CPetitionQWnd__SetPriorityDisplay
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::SetPriorityDisplay(void),CPetitionQWnd__SetPriorityDisplay);
#endif
#ifdef CPetitionQWnd__AddGMText
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::AddGMText(void),CPetitionQWnd__AddGMText);
#endif
#ifdef CPetitionQWnd__CheckedOut
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::CheckedOut(struct petitionQtype const *,int),CPetitionQWnd__CheckedOut);
#endif
#ifdef CPetitionQWnd__UndoCheckout
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::UndoCheckout(void),CPetitionQWnd__UndoCheckout);
#endif
#ifdef CPetitionQWnd__ClearCurrentPet
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::ClearCurrentPet(void),CPetitionQWnd__ClearCurrentPet);
#endif
#ifdef CPetitionQWnd__FillFields
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::FillFields(void),CPetitionQWnd__FillFields);
#endif
#ifdef CPetitionQWnd__SetButtonsForPetition
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::SetButtonsForPetition(bool,bool),CPetitionQWnd__SetButtonsForPetition);
#endif
#ifdef CPetitionQWnd__LogPetitionText
FUNCTION_AT_ADDRESS(void  CPetitionQWnd::LogPetitionText(void),CPetitionQWnd__LogPetitionText);
#endif
#ifdef CPetitionQWnd__GetCurrentPetitionersName
FUNCTION_AT_ADDRESS(char *  CPetitionQWnd::GetCurrentPetitionersName(void),CPetitionQWnd__GetCurrentPetitionersName);
#endif
#ifdef CPlayerNotesWnd__CPlayerNotesWnd
FUNCTION_AT_ADDRESS( CPlayerNotesWnd::CPlayerNotesWnd(class CXWnd *),CPlayerNotesWnd__CPlayerNotesWnd);
#endif
#ifdef CPlayerNotesWnd__Activate
FUNCTION_AT_ADDRESS(void  CPlayerNotesWnd::Activate(void),CPlayerNotesWnd__Activate);
#endif
#ifdef CPlayerNotesWnd__SaveNotes
FUNCTION_AT_ADDRESS(void  CPlayerNotesWnd::SaveNotes(void),CPlayerNotesWnd__SaveNotes);
#endif
#ifdef CPlayerNotesWnd__AppendText
FUNCTION_AT_ADDRESS(void  CPlayerNotesWnd::AppendText(char *),CPlayerNotesWnd__AppendText);
#endif
#ifdef CPlayerWnd__CPlayerWnd
FUNCTION_AT_ADDRESS( CPlayerWnd::CPlayerWnd(class CXWnd *),CPlayerWnd__CPlayerWnd);
#endif
#ifdef CPlayerWnd__Init
FUNCTION_AT_ADDRESS(void  CPlayerWnd::Init(void),CPlayerWnd__Init);
#endif
#ifdef CPlayerWnd__Activate
FUNCTION_AT_ADDRESS(void  CPlayerWnd::Activate(void),CPlayerWnd__Activate);
#endif
#ifdef CPlayerWnd__CreateLocalMenu
FUNCTION_AT_ADDRESS(void  CPlayerWnd::CreateLocalMenu(void),CPlayerWnd__CreateLocalMenu);
#endif
#ifdef CPlayerWnd__UpdateContextMenu
FUNCTION_AT_ADDRESS(void  CPlayerWnd::UpdateContextMenu(void),CPlayerWnd__UpdateContextMenu);
#endif
#ifdef CQuantityWnd__CQuantityWnd
FUNCTION_AT_ADDRESS( CQuantityWnd::CQuantityWnd(class CXWnd *),CQuantityWnd__CQuantityWnd);
#endif
#ifdef CQuantityWnd__Activate
FUNCTION_AT_ADDRESS(void  CQuantityWnd::Activate(class CXWnd *,int,int,int,int,bool),CQuantityWnd__Activate);
#endif
#ifdef CQuantityWnd__CheckMaxEditWnd
FUNCTION_AT_ADDRESS(void  CQuantityWnd::CheckMaxEditWnd(void),CQuantityWnd__CheckMaxEditWnd);
#endif
#ifdef CQuantityWnd__UpdateEditWndFromSlider
FUNCTION_AT_ADDRESS(void  CQuantityWnd::UpdateEditWndFromSlider(void),CQuantityWnd__UpdateEditWndFromSlider);
#endif
#ifdef CQuantityWnd__UpdateSliderFromEditWnd
FUNCTION_AT_ADDRESS(void  CQuantityWnd::UpdateSliderFromEditWnd(void),CQuantityWnd__UpdateSliderFromEditWnd);
#endif
#ifdef CRaidOptionsWnd__CRaidOptionsWnd
FUNCTION_AT_ADDRESS( CRaidOptionsWnd::CRaidOptionsWnd(class CXWnd *),CRaidOptionsWnd__CRaidOptionsWnd);
#endif
#ifdef CRaidOptionsWnd__Init
FUNCTION_AT_ADDRESS(void  CRaidOptionsWnd::Init(void),CRaidOptionsWnd__Init);
#endif
#ifdef CRaidOptionsWnd__Activate
FUNCTION_AT_ADDRESS(void  CRaidOptionsWnd::Activate(void),CRaidOptionsWnd__Activate);
#endif
#ifdef CRaidOptionsWnd__AddLooterToList
FUNCTION_AT_ADDRESS(void  CRaidOptionsWnd::AddLooterToList(char *),CRaidOptionsWnd__AddLooterToList);
#endif
#ifdef CRaidOptionsWnd__ClearLooterList
FUNCTION_AT_ADDRESS(void  CRaidOptionsWnd::ClearLooterList(void),CRaidOptionsWnd__ClearLooterList);
#endif
#ifdef CRaidOptionsWnd__UpdateComponents
FUNCTION_AT_ADDRESS(void  CRaidOptionsWnd::UpdateComponents(void),CRaidOptionsWnd__UpdateComponents);
#endif
#ifdef CRaidOptionsWnd__InitializeClassColors
FUNCTION_AT_ADDRESS(void  CRaidOptionsWnd::InitializeClassColors(void),CRaidOptionsWnd__InitializeClassColors);
#endif
#ifdef CRaidWnd__CRaidWnd
FUNCTION_AT_ADDRESS( CRaidWnd::CRaidWnd(class CXWnd *),CRaidWnd__CRaidWnd);
#endif
#ifdef CRaidWnd__Init
FUNCTION_AT_ADDRESS(void  CRaidWnd::Init(void),CRaidWnd__Init);
#endif
#ifdef CRaidWnd__Activate
FUNCTION_AT_ADDRESS(void  CRaidWnd::Activate(void),CRaidWnd__Activate);
#endif
#ifdef CRaidWnd__AddPlayertoList
FUNCTION_AT_ADDRESS(void  CRaidWnd::AddPlayertoList(char *,char *,char *,char *,int,int,bool),CRaidWnd__AddPlayertoList);
#endif
#ifdef CRaidWnd__RemovePlayerFromList
FUNCTION_AT_ADDRESS(void  CRaidWnd::RemovePlayerFromList(char *,int),CRaidWnd__RemovePlayerFromList);
#endif
#ifdef CRaidWnd__SetRaidCount
FUNCTION_AT_ADDRESS(void  CRaidWnd::SetRaidCount(int),CRaidWnd__SetRaidCount);
#endif
#ifdef CRaidWnd__ClearPlayerList
FUNCTION_AT_ADDRESS(void  CRaidWnd::ClearPlayerList(void),CRaidWnd__ClearPlayerList);
#endif
#ifdef CRaidWnd__AddSeparator
FUNCTION_AT_ADDRESS(void  CRaidWnd::AddSeparator(void),CRaidWnd__AddSeparator);
#endif
#ifdef CRaidWnd__SetRaidMemberRank
FUNCTION_AT_ADDRESS(void  CRaidWnd::SetRaidMemberRank(char *,char *,int),CRaidWnd__SetRaidMemberRank);
#endif
#ifdef CRaidWnd__ChangePosition
FUNCTION_AT_ADDRESS(void  CRaidWnd::ChangePosition(char *,int,int,int,bool),CRaidWnd__ChangePosition);
#endif
#ifdef CRaidWnd__ChangeRaidGroupLeader
FUNCTION_AT_ADDRESS(void  CRaidWnd::ChangeRaidGroupLeader(char *,int,char *),CRaidWnd__ChangeRaidGroupLeader);
#endif
#ifdef CRaidWnd__UpdateMemberName
FUNCTION_AT_ADDRESS(void  CRaidWnd::UpdateMemberName(char *,char *,int),CRaidWnd__UpdateMemberName);
#endif
#ifdef CRaidWnd__SetRaidTarget
FUNCTION_AT_ADDRESS(void  CRaidWnd::SetRaidTarget(char *,int,char *,int),CRaidWnd__SetRaidTarget);
#endif
#ifdef CRaidWnd__UpdateLevelAverage
FUNCTION_AT_ADDRESS(void  CRaidWnd::UpdateLevelAverage(int),CRaidWnd__UpdateLevelAverage);
#endif
#ifdef CRaidWnd__UpdateButtons
FUNCTION_AT_ADDRESS(void  CRaidWnd::UpdateButtons(void),CRaidWnd__UpdateButtons);
#endif
#ifdef CRaidWnd__InitializeClassColors
FUNCTION_AT_ADDRESS(void  CRaidWnd::InitializeClassColors(void),CRaidWnd__InitializeClassColors);
#endif
#ifdef CRaidWnd__SetPlayerClassColor
FUNCTION_AT_ADDRESS(void  CRaidWnd::SetPlayerClassColor(int,int,int),CRaidWnd__SetPlayerClassColor);
#endif
#ifdef CRaidWnd__SetPlayerClassColor1
FUNCTION_AT_ADDRESS(void  CRaidWnd::SetPlayerClassColor(char *,int,int),CRaidWnd__SetPlayerClassColor1);
#endif
#ifdef CRaidWnd__SetClassColor
FUNCTION_AT_ADDRESS(void  CRaidWnd::SetClassColor(int,unsigned long),CRaidWnd__SetClassColor);
#endif
#ifdef CRaidWnd__ResortRaidGroupList
FUNCTION_AT_ADDRESS(void  CRaidWnd::ResortRaidGroupList(int,int),CRaidWnd__ResortRaidGroupList);
#endif
#ifdef CRaidWnd__FindOpenIndexInGroup
FUNCTION_AT_ADDRESS(int  CRaidWnd::FindOpenIndexInGroup(int),CRaidWnd__FindOpenIndexInGroup);
#endif
#ifdef CRaidWnd__FindIndexNotInGroupList
FUNCTION_AT_ADDRESS(int  CRaidWnd::FindIndexNotInGroupList(char *),CRaidWnd__FindIndexNotInGroupList);
#endif
#ifdef CRaidWnd__FindPlayerIndexInGroup
FUNCTION_AT_ADDRESS(int  CRaidWnd::FindPlayerIndexInGroup(char *,int),CRaidWnd__FindPlayerIndexInGroup);
#endif
#ifdef CSelectorWnd__CSelectorWnd
FUNCTION_AT_ADDRESS( CSelectorWnd::CSelectorWnd(class CXWnd *),CSelectorWnd__CSelectorWnd);
#endif
#ifdef CSelectorWnd__Activate
FUNCTION_AT_ADDRESS(void  CSelectorWnd::Activate(void),CSelectorWnd__Activate);
#endif
#ifdef CSelectorWnd__KeyMapUpdated
FUNCTION_AT_ADDRESS(void  CSelectorWnd::KeyMapUpdated(void),CSelectorWnd__KeyMapUpdated);
#endif
#ifdef CSkillsSelectWnd__CSkillsSelectWnd
FUNCTION_AT_ADDRESS( CSkillsSelectWnd::CSkillsSelectWnd(class CXWnd *),CSkillsSelectWnd__CSkillsSelectWnd);
#endif
#ifdef CSkillsSelectWnd__Refresh
FUNCTION_AT_ADDRESS(void  CSkillsSelectWnd::Refresh(void),CSkillsSelectWnd__Refresh);
#endif
#ifdef CSkillsSelectWnd__UpdateAll
FUNCTION_AT_ADDRESS(void  CSkillsSelectWnd::UpdateAll(void),CSkillsSelectWnd__UpdateAll);
#endif
#ifdef CSkillsSelectWnd__UpdateSkill
FUNCTION_AT_ADDRESS(void  CSkillsSelectWnd::UpdateSkill(int),CSkillsSelectWnd__UpdateSkill);
#endif
#ifdef CSkillsSelectWnd__SetTypesToDisplay
FUNCTION_AT_ADDRESS(void  CSkillsSelectWnd::SetTypesToDisplay(int),CSkillsSelectWnd__SetTypesToDisplay);
#endif
#ifdef CSkillsWnd__CSkillsWnd
FUNCTION_AT_ADDRESS( CSkillsWnd::CSkillsWnd(class CXWnd *),CSkillsWnd__CSkillsWnd);
#endif
#ifdef CSkillsWnd__Activate
FUNCTION_AT_ADDRESS(void  CSkillsWnd::Activate(void),CSkillsWnd__Activate);
#endif
#ifdef CSkillsWnd__SkillImproveOccurred
FUNCTION_AT_ADDRESS(void  CSkillsWnd::SkillImproveOccurred(int),CSkillsWnd__SkillImproveOccurred);
#endif
#ifdef CSkillsWnd__UpdateAll
FUNCTION_AT_ADDRESS(void  CSkillsWnd::UpdateAll(void),CSkillsWnd__UpdateAll);
#endif
#ifdef CSkillsWnd__UpdateSkill
FUNCTION_AT_ADDRESS(void  CSkillsWnd::UpdateSkill(int),CSkillsWnd__UpdateSkill);
#endif
#ifdef CSocialEditWnd__CSocialEditWnd
FUNCTION_AT_ADDRESS( CSocialEditWnd::CSocialEditWnd(class CXWnd *),CSocialEditWnd__CSocialEditWnd);
#endif
#ifdef CSocialEditWnd__Init
FUNCTION_AT_ADDRESS(void  CSocialEditWnd::Init(void),CSocialEditWnd__Init);
#endif
#ifdef CSocialEditWnd__Activate
FUNCTION_AT_ADDRESS(void  CSocialEditWnd::Activate(int),CSocialEditWnd__Activate);
#endif
#ifdef CSocialEditWnd__ClickedAccept
FUNCTION_AT_ADDRESS(void  CSocialEditWnd::ClickedAccept(void),CSocialEditWnd__ClickedAccept);
#endif
#ifdef CSocialEditWnd__ClickedClear
FUNCTION_AT_ADDRESS(void  CSocialEditWnd::ClickedClear(void),CSocialEditWnd__ClickedClear);
#endif
#ifdef CSocialEditWnd__ClickedTextColorButton
FUNCTION_AT_ADDRESS(void  CSocialEditWnd::ClickedTextColorButton(int),CSocialEditWnd__ClickedTextColorButton);
#endif
#ifdef CSocialEditWnd__GetSocialTextColor
FUNCTION_AT_ADDRESS(unsigned long  CSocialEditWnd::GetSocialTextColor(int),CSocialEditWnd__GetSocialTextColor);
#endif
#ifdef CSocialEditWnd__UpdateControlsFromSocial
FUNCTION_AT_ADDRESS(void  CSocialEditWnd::UpdateControlsFromSocial(void),CSocialEditWnd__UpdateControlsFromSocial);
#endif
#ifdef CSoulmarkWnd__CSoulmarkWnd
FUNCTION_AT_ADDRESS( CSoulmarkWnd::CSoulmarkWnd(class CXWnd *),CSoulmarkWnd__CSoulmarkWnd);
#endif
#ifdef CSoulmarkWnd__UpdateSoulmarks
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::UpdateSoulmarks(struct soulMarkMsg *),CSoulmarkWnd__UpdateSoulmarks);
#endif
#ifdef CSoulmarkWnd__UpdateList
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::UpdateList(void),CSoulmarkWnd__UpdateList);
#endif
#ifdef CSoulmarkWnd__Activate
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Activate(void),CSoulmarkWnd__Activate);
#endif
#ifdef CSoulmarkWnd__Activate1
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Activate(char *,char *),CSoulmarkWnd__Activate1);
#endif
#ifdef CSoulmarkWnd__SaveMarks
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::SaveMarks(void),CSoulmarkWnd__SaveMarks);
#endif
#ifdef CSoulmarkWnd__FillFields
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::FillFields(void),CSoulmarkWnd__FillFields);
#endif
#ifdef CSoulmarkWnd__Clear
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Clear(void),CSoulmarkWnd__Clear);
#endif
#ifdef CSoulmarkWnd__Inquire
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Inquire(char *,char *),CSoulmarkWnd__Inquire);
#endif
#ifdef CSoulmarkWnd__AddMark
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::AddMark(int,char *,char *,char *),CSoulmarkWnd__AddMark);
#endif
#ifdef CSoulmarkWnd__Inquire1
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Inquire(char *),CSoulmarkWnd__Inquire1);
#endif
#ifdef CSoulmarkWnd__Praise
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Praise(char *),CSoulmarkWnd__Praise);
#endif
#ifdef CSoulmarkWnd__Warn
FUNCTION_AT_ADDRESS(void  CSoulmarkWnd::Warn(char *),CSoulmarkWnd__Warn);
#endif
#ifdef CSpellBookWnd__CSpellBookWnd
FUNCTION_AT_ADDRESS( CSpellBookWnd::CSpellBookWnd(class CXWnd *),CSpellBookWnd__CSpellBookWnd);
#endif
#ifdef CSpellBookWnd__Init
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::Init(void),CSpellBookWnd__Init);
#endif
#ifdef CSpellBookWnd__Activate
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::Activate(void),CSpellBookWnd__Activate);
#endif
#ifdef CSpellBookWnd__GetBookSlot
FUNCTION_AT_ADDRESS(int __cdecl CSpellBookWnd::GetBookSlot(int),CSpellBookWnd__GetBookSlot);
#endif
#ifdef CSpellBookWnd__MemorizeSet
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::MemorizeSet(int *,int),CSpellBookWnd__MemorizeSet);
#endif
#ifdef CSpellBookWnd__ContinueSetMem
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::ContinueSetMem(void),CSpellBookWnd__ContinueSetMem);
#endif
#ifdef CSpellBookWnd__DelayedSpellMem
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::DelayedSpellMem(int,int,int),CSpellBookWnd__DelayedSpellMem);
#endif
#ifdef CSpellBookWnd__EndSetMem
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::EndSetMem(void),CSpellBookWnd__EndSetMem);
#endif
#ifdef CSpellBookWnd__AutoMemSpell
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::AutoMemSpell(int,int),CSpellBookWnd__AutoMemSpell);
#endif
#ifdef CSpellBookWnd__HandleLeftClickOnSpell
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::HandleLeftClickOnSpell(int),CSpellBookWnd__HandleLeftClickOnSpell);
#endif
#ifdef CSpellBookWnd__HandleRightClickOnSpell
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::HandleRightClickOnSpell(int),CSpellBookWnd__HandleRightClickOnSpell);
#endif
#ifdef CSpellBookWnd__CanStartMemming
FUNCTION_AT_ADDRESS(bool  CSpellBookWnd::CanStartMemming(int),CSpellBookWnd__CanStartMemming);
#endif
#ifdef CSpellBookWnd__StartSpellMemorizationDrag
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::StartSpellMemorizationDrag(int,class CButtonWnd *),CSpellBookWnd__StartSpellMemorizationDrag);
#endif
#ifdef CSpellBookWnd__StartSpellMemorization
FUNCTION_AT_ADDRESS(bool  CSpellBookWnd::StartSpellMemorization(int,int,bool),CSpellBookWnd__StartSpellMemorization);
#endif
#ifdef CSpellBookWnd__FinishMemorizing
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::FinishMemorizing(int,int),CSpellBookWnd__FinishMemorizing);
#endif
#ifdef CSpellBookWnd__GetSpellMemTicksLeft
FUNCTION_AT_ADDRESS(int  CSpellBookWnd::GetSpellMemTicksLeft(void),CSpellBookWnd__GetSpellMemTicksLeft);
#endif
#ifdef CSpellBookWnd__StartSpellScribe
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::StartSpellScribe(int),CSpellBookWnd__StartSpellScribe);
#endif
#ifdef CSpellBookWnd__FinishScribing
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::FinishScribing(int,int),CSpellBookWnd__FinishScribing);
#endif
#ifdef CSpellBookWnd__GetSpellScribeTicksLeft
FUNCTION_AT_ADDRESS(int  CSpellBookWnd::GetSpellScribeTicksLeft(void),CSpellBookWnd__GetSpellScribeTicksLeft);
#endif
#ifdef CSpellBookWnd__SwapSpellBookSlots
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::SwapSpellBookSlots(int,int),CSpellBookWnd__SwapSpellBookSlots);
#endif
#ifdef CSpellBookWnd__HandleSpellInfoDisplay
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::HandleSpellInfoDisplay(class CXWnd *),CSpellBookWnd__HandleSpellInfoDisplay);
#endif
#ifdef CSpellBookWnd__DisplaySpellInfo
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::DisplaySpellInfo(int),CSpellBookWnd__DisplaySpellInfo);
#endif
#ifdef CSpellBookWnd__TurnToPage
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::TurnToPage(int),CSpellBookWnd__TurnToPage);
#endif
#ifdef CSpellBookWnd__UpdateSpellBookDisplay
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::UpdateSpellBookDisplay(void),CSpellBookWnd__UpdateSpellBookDisplay);
#endif
#ifdef CSpellBookWnd__StopSpellBookAction
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::StopSpellBookAction(void),CSpellBookWnd__StopSpellBookAction);
#endif
#ifdef CSpellBookWnd__GetSpellDeletionConfirmation
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::GetSpellDeletionConfirmation(int),CSpellBookWnd__GetSpellDeletionConfirmation);
#endif
#ifdef CSpellBookWnd__RequestSpellDeletion
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::RequestSpellDeletion(int),CSpellBookWnd__RequestSpellDeletion);
#endif
#ifdef CSpellBookWnd__DeleteSpellFromBook
FUNCTION_AT_ADDRESS(void  CSpellBookWnd::DeleteSpellFromBook(int,int),CSpellBookWnd__DeleteSpellFromBook);
#endif
#ifdef CXStr__Mid
FUNCTION_AT_ADDRESS(class CXStr  CXStr::Mid(int,int)const ,CXStr__Mid);
#endif
#ifdef CTargetWnd__CTargetWnd
FUNCTION_AT_ADDRESS( CTargetWnd::CTargetWnd(class CXWnd *),CTargetWnd__CTargetWnd);
#endif
#ifdef CTargetWnd__Activate
FUNCTION_AT_ADDRESS(void  CTargetWnd::Activate(void),CTargetWnd__Activate);
#endif
#ifdef CTextEntryWnd__CTextEntryWnd
FUNCTION_AT_ADDRESS( CTextEntryWnd::CTextEntryWnd(class CXWnd *),CTextEntryWnd__CTextEntryWnd);
#endif
#ifdef CTextEntryWnd__Activate
FUNCTION_AT_ADDRESS(void  CTextEntryWnd::Activate(class CXWnd *,int,char *,int,int,char *),CTextEntryWnd__Activate);
#endif
#ifdef CTextEntryWnd__Callback
FUNCTION_AT_ADDRESS(void  CTextEntryWnd::Callback(bool),CTextEntryWnd__Callback);
#endif
#ifdef CTextEntryWnd__UpdateButtons
FUNCTION_AT_ADDRESS(void  CTextEntryWnd::UpdateButtons(void),CTextEntryWnd__UpdateButtons);
#endif
#ifdef CTextEntryWnd__GetEntryText
FUNCTION_AT_ADDRESS(class CXStr  CTextEntryWnd::GetEntryText(void),CTextEntryWnd__GetEntryText);
#endif
#ifdef CTimeLeftWnd__CTimeLeftWnd
FUNCTION_AT_ADDRESS( CTimeLeftWnd::CTimeLeftWnd(long),CTimeLeftWnd__CTimeLeftWnd);
#endif
#ifdef CTimeLeftWnd__Activate
FUNCTION_AT_ADDRESS(void  CTimeLeftWnd::Activate(void),CTimeLeftWnd__Activate);
#endif
#ifdef CTipWnd__CTipWnd
FUNCTION_AT_ADDRESS( CTipWnd::CTipWnd(class CXWnd *,int),CTipWnd__CTipWnd);
#endif
#ifdef CTipWnd__Activate
FUNCTION_AT_ADDRESS(bool  CTipWnd::Activate(int,bool),CTipWnd__Activate);
#endif
#ifdef CTipWnd__UpdateButtons
FUNCTION_AT_ADDRESS(void  CTipWnd::UpdateButtons(void),CTipWnd__UpdateButtons);
#endif
#ifdef CTipWnd__InitializeTipSettings
FUNCTION_AT_ADDRESS(void  CTipWnd::InitializeTipSettings(void),CTipWnd__InitializeTipSettings);
#endif
#ifdef CTipWnd__CleanDayTips
FUNCTION_AT_ADDRESS(void  CTipWnd::CleanDayTips(void),CTipWnd__CleanDayTips);
#endif
#ifdef CTipWnd__SelectRandomTip
FUNCTION_AT_ADDRESS(int  CTipWnd::SelectRandomTip(void),CTipWnd__SelectRandomTip);
#endif
#ifdef CTipWnd__SetTOTD
FUNCTION_AT_ADDRESS(void  CTipWnd::SetTOTD(int),CTipWnd__SetTOTD);
#endif
#ifdef CTipWnd__IsRecentTOTD
FUNCTION_AT_ADDRESS(bool  CTipWnd::IsRecentTOTD(int),CTipWnd__IsRecentTOTD);
#endif
#ifdef CTipWnd__AddContextTip
FUNCTION_AT_ADDRESS(void  CTipWnd::AddContextTip(int),CTipWnd__AddContextTip);
#endif
#ifdef CTipWnd__ShowHistoryTip
FUNCTION_AT_ADDRESS(void  CTipWnd::ShowHistoryTip(int),CTipWnd__ShowHistoryTip);
#endif
#ifdef CTipWnd__LoadINISettings
FUNCTION_AT_ADDRESS(void  CTipWnd::LoadINISettings(void),CTipWnd__LoadINISettings);
#endif
#ifdef CTipWnd__LoadDayTips
FUNCTION_AT_ADDRESS(void  CTipWnd::LoadDayTips(void),CTipWnd__LoadDayTips);
#endif
#ifdef CTrackingWnd__CTrackingWnd
FUNCTION_AT_ADDRESS( CTrackingWnd::CTrackingWnd(class CXWnd *),CTrackingWnd__CTrackingWnd);
#endif
#ifdef CTrackingWnd__Init
FUNCTION_AT_ADDRESS(void  CTrackingWnd::Init(void),CTrackingWnd__Init);
#endif
#ifdef CTrackingWnd__Activate
FUNCTION_AT_ADDRESS(void  CTrackingWnd::Activate(void),CTrackingWnd__Activate);
#endif
#ifdef CTrackingWnd__NotifyServerOfTrackingTarget
FUNCTION_AT_ADDRESS(void  CTrackingWnd::NotifyServerOfTrackingTarget(int),CTrackingWnd__NotifyServerOfTrackingTarget);
#endif
#ifdef CTrackingWnd__UpdateTrackingControls
FUNCTION_AT_ADDRESS(void  CTrackingWnd::UpdateTrackingControls(void),CTrackingWnd__UpdateTrackingControls);
#endif
#ifdef CTrackingWnd__GetTrackColor
FUNCTION_AT_ADDRESS(unsigned long  CTrackingWnd::GetTrackColor(int),CTrackingWnd__GetTrackColor);
#endif
#ifdef CTrackingWnd__UpdateTrackingList
FUNCTION_AT_ADDRESS(void  CTrackingWnd::UpdateTrackingList(bool),CTrackingWnd__UpdateTrackingList);
#endif
#ifdef CTrackingWnd__GenerateTrackingList
FUNCTION_AT_ADDRESS(void  CTrackingWnd::GenerateTrackingList(void),CTrackingWnd__GenerateTrackingList);
#endif
#ifdef CTrackingWnd__SetTrackingList
FUNCTION_AT_ADDRESS(void  CTrackingWnd::SetTrackingList(struct TrackingHit *,int),CTrackingWnd__SetTrackingList);
#endif
#ifdef CTrackingWnd__DoTrackSort
FUNCTION_AT_ADDRESS(void  CTrackingWnd::DoTrackSort(bool),CTrackingWnd__DoTrackSort);
#endif
#ifdef CTrackingWnd__DoTrackFilter
FUNCTION_AT_ADDRESS(void  CTrackingWnd::DoTrackFilter(bool),CTrackingWnd__DoTrackFilter);
#endif
#ifdef CTrackingWnd__RemovePlayerFromTracking
FUNCTION_AT_ADDRESS(void  CTrackingWnd::RemovePlayerFromTracking(class EQPlayer *),CTrackingWnd__RemovePlayerFromTracking);
#endif
#ifdef CTrackingWnd__RemovePlayerFromTracking1
FUNCTION_AT_ADDRESS(void  CTrackingWnd::RemovePlayerFromTracking(int),CTrackingWnd__RemovePlayerFromTracking1);
#endif
#ifdef CTrackingWnd__RemoveFromListWndByData
FUNCTION_AT_ADDRESS(void  CTrackingWnd::RemoveFromListWndByData(unsigned int),CTrackingWnd__RemoveFromListWndByData);
#endif
#ifdef CTrackingWnd__GetListIdByData
FUNCTION_AT_ADDRESS(int  CTrackingWnd::GetListIdByData(unsigned int),CTrackingWnd__GetListIdByData);
#endif
#ifdef CTradeWnd__CTradeWnd
FUNCTION_AT_ADDRESS( CTradeWnd::CTradeWnd(class CXWnd *),CTradeWnd__CTradeWnd);
#endif
#ifdef CTradeWnd__Init
FUNCTION_AT_ADDRESS(void  CTradeWnd::Init(void),CTradeWnd__Init);
#endif
#ifdef CTradeWnd__Activate
FUNCTION_AT_ADDRESS(void  CTradeWnd::Activate(class EQPlayer *,bool),CTradeWnd__Activate);
#endif
#ifdef CTradeWnd__ClickedCancelButton
FUNCTION_AT_ADDRESS(void  CTradeWnd::ClickedCancelButton(void),CTradeWnd__ClickedCancelButton);
#endif
#ifdef CTradeWnd__ClickedTradeButton
FUNCTION_AT_ADDRESS(void  CTradeWnd::ClickedTradeButton(void),CTradeWnd__ClickedTradeButton);
#endif
#ifdef CTradeWnd__ClickedMoneyButton
FUNCTION_AT_ADDRESS(void  CTradeWnd::ClickedMoneyButton(int),CTradeWnd__ClickedMoneyButton);
#endif
#ifdef CTradeWnd__UpdateTradeDisplay
FUNCTION_AT_ADDRESS(void  CTradeWnd::UpdateTradeDisplay(void),CTradeWnd__UpdateTradeDisplay);
#endif
#ifdef CTradeWnd__IsMyTradeSlot
FUNCTION_AT_ADDRESS(bool  CTradeWnd::IsMyTradeSlot(int,bool *),CTradeWnd__IsMyTradeSlot);
#endif
#ifdef CTradeWnd__TradeItemChanged
FUNCTION_AT_ADDRESS(void  CTradeWnd::TradeItemChanged(int,int),CTradeWnd__TradeItemChanged);
#endif
#ifdef CTradeWnd__CompleteTrade
FUNCTION_AT_ADDRESS(void  CTradeWnd::CompleteTrade(void),CTradeWnd__CompleteTrade);
#endif
#ifdef CTradeWnd__AddEquipmentToHisTradeArray
FUNCTION_AT_ADDRESS(void  CTradeWnd::AddEquipmentToHisTradeArray(class EQ_Equipment *),CTradeWnd__AddEquipmentToHisTradeArray);
#endif
#ifdef CTradeWnd__AddNoteToHisTradeArray
FUNCTION_AT_ADDRESS(void  CTradeWnd::AddNoteToHisTradeArray(class EQ_Note *),CTradeWnd__AddNoteToHisTradeArray);
#endif
#ifdef CTradeWnd__AddContainerToHisTradeArray
FUNCTION_AT_ADDRESS(void  CTradeWnd::AddContainerToHisTradeArray(class EQ_Container *),CTradeWnd__AddContainerToHisTradeArray);
#endif
#ifdef CTradeWnd__DeleteItemFromHisTradeArray
FUNCTION_AT_ADDRESS(void  CTradeWnd::DeleteItemFromHisTradeArray(int),CTradeWnd__DeleteItemFromHisTradeArray);
#endif
#ifdef CTradeWnd__DropItemIntoTrade
FUNCTION_AT_ADDRESS(void  CTradeWnd::DropItemIntoTrade(void),CTradeWnd__DropItemIntoTrade);
#endif
#ifdef CTradeWnd__DropMoneyIntoTrade
//FUNCTION_AT_ADDRESS(CTradeWnd::DropMoneyIntoTrade(void),CTradeWnd__DropMoneyIntoTrade);
#endif
#ifdef CTradeWnd__SetMyReadyTrade
FUNCTION_AT_ADDRESS(void  CTradeWnd::SetMyReadyTrade(bool),CTradeWnd__SetMyReadyTrade);
#endif
#ifdef CTradeWnd__SetHisReadyTrade
FUNCTION_AT_ADDRESS(void  CTradeWnd::SetHisReadyTrade(bool),CTradeWnd__SetHisReadyTrade);
#endif
#ifdef CTradeWnd__SetHisMoney
FUNCTION_AT_ADDRESS(void  CTradeWnd::SetHisMoney(int,long),CTradeWnd__SetHisMoney);
#endif
#ifdef CTrainWnd__CTrainWnd
FUNCTION_AT_ADDRESS( CTrainWnd::CTrainWnd(class CXWnd *),CTrainWnd__CTrainWnd);
#endif
#ifdef CTrainWnd__Activate
FUNCTION_AT_ADDRESS(void  CTrainWnd::Activate(void),CTrainWnd__Activate);
#endif
#ifdef CTrainWnd__UpdateRight
FUNCTION_AT_ADDRESS(void  CTrainWnd::UpdateRight(void),CTrainWnd__UpdateRight);
#endif
#ifdef CTrainWnd__UpdateAll
FUNCTION_AT_ADDRESS(void  CTrainWnd::UpdateAll(bool),CTrainWnd__UpdateAll);
#endif
#ifdef CTrainWnd__SkillName
FUNCTION_AT_ADDRESS(char *  CTrainWnd::SkillName(int),CTrainWnd__SkillName);
#endif
#ifdef CTrainWnd__SkillValue
FUNCTION_AT_ADDRESS(int  CTrainWnd::SkillValue(int),CTrainWnd__SkillValue);
#endif
#ifdef CTrainWnd__SwapSkill
FUNCTION_AT_ADDRESS(void  CTrainWnd::SwapSkill(int,int),CTrainWnd__SwapSkill);
#endif
#ifdef CTrainWnd__SortNames
FUNCTION_AT_ADDRESS(void  CTrainWnd::SortNames(int),CTrainWnd__SortNames);
#endif
#ifdef CTrainWnd__SortSkill
FUNCTION_AT_ADDRESS(void  CTrainWnd::SortSkill(int),CTrainWnd__SortSkill);
#endif
#ifdef CTrainWnd__UpdateSkill
FUNCTION_AT_ADDRESS(void  CTrainWnd::UpdateSkill(int),CTrainWnd__UpdateSkill);
#endif
#ifdef CTrainWnd__SkillChanged
FUNCTION_AT_ADDRESS(void  CTrainWnd::SkillChanged(int),CTrainWnd__SkillChanged);
#endif
#ifdef CTrainWnd__SetGMData
FUNCTION_AT_ADDRESS(void  CTrainWnd::SetGMData(int *,unsigned char *,float),CTrainWnd__SetGMData);
#endif
#ifdef CTrainWnd__Train
FUNCTION_AT_ADDRESS(void  CTrainWnd::Train(void),CTrainWnd__Train);
#endif
#ifdef CVideoModesWnd__CVideoModesWnd
FUNCTION_AT_ADDRESS( CVideoModesWnd::CVideoModesWnd(class CXWnd *),CVideoModesWnd__CVideoModesWnd);
#endif
#ifdef CVideoModesWnd__Init
FUNCTION_AT_ADDRESS(void  CVideoModesWnd::Init(void),CVideoModesWnd__Init);
#endif
#ifdef CVideoModesWnd__Update
FUNCTION_AT_ADDRESS(void  CVideoModesWnd::Update(void),CVideoModesWnd__Update);
#endif
#ifdef CVideoModesWnd__UpdateSelection
FUNCTION_AT_ADDRESS(void  CVideoModesWnd::UpdateSelection(unsigned int),CVideoModesWnd__UpdateSelection);
#endif
#ifdef CVideoModesWnd__RestoreOldMode
FUNCTION_AT_ADDRESS(void  CVideoModesWnd::RestoreOldMode(void),CVideoModesWnd__RestoreOldMode);
#endif
#ifdef CGuild__CGuild
FUNCTION_AT_ADDRESS( CGuild::CGuild(void),CGuild__CGuild);
#endif
#ifdef CGuild__GetGuildName
FUNCTION_AT_ADDRESS(char *  CGuild::GetGuildName(int),CGuild__GetGuildName);
#endif
#ifdef CGuild__ValidGuildName
FUNCTION_AT_ADDRESS(bool  CGuild::ValidGuildName(int),CGuild__ValidGuildName);
#endif
#ifdef CGuild__GetGuildIndex
FUNCTION_AT_ADDRESS(int  CGuild::GetGuildIndex(char *),CGuild__GetGuildIndex);
#endif
#ifdef CGuild__SendPublicCommentChange
FUNCTION_AT_ADDRESS(void  CGuild::SendPublicCommentChange(char *,char *),CGuild__SendPublicCommentChange);
#endif
#ifdef CGuild__DemoteMember
FUNCTION_AT_ADDRESS(void  CGuild::DemoteMember(class GuildMember *),CGuild__DemoteMember);
#endif
#ifdef CGuild__SetGuildMotd
FUNCTION_AT_ADDRESS(void  CGuild::SetGuildMotd(struct guildmotdSet *),CGuild__SetGuildMotd);
#endif
#ifdef CGuild__HandleGuildMessage
FUNCTION_AT_ADDRESS(void  CGuild::HandleGuildMessage(struct connection_t *,unsigned __int32,char *,unsigned __int32),CGuild__HandleGuildMessage);
#endif
#ifdef CGuild__InitializeFromDump
FUNCTION_AT_ADDRESS(void  CGuild::InitializeFromDump(char *),CGuild__InitializeFromDump);
#endif
#ifdef CGuild__AddGuildMember
FUNCTION_AT_ADDRESS(void  CGuild::AddGuildMember(class GuildMember *),CGuild__AddGuildMember);
#endif
#ifdef CGuild__DeleteAllMembers
FUNCTION_AT_ADDRESS(void  CGuild::DeleteAllMembers(void),CGuild__DeleteAllMembers);
#endif
#ifdef CGuild__HandleGuildInvite
FUNCTION_AT_ADDRESS(void  CGuild::HandleGuildInvite(struct connection_t *,unsigned __int32,char *,unsigned __int32),CGuild__HandleGuildInvite);
#endif
#ifdef CGuild__HandleAddGuildMember
FUNCTION_AT_ADDRESS(void  CGuild::HandleAddGuildMember(char *,int),CGuild__HandleAddGuildMember);
#endif
#ifdef CGuild__HandleRemoveGuildMember
FUNCTION_AT_ADDRESS(void  CGuild::HandleRemoveGuildMember(char *,int),CGuild__HandleRemoveGuildMember);
#endif
#ifdef CGuild__HandleDeleteGuildResponse
FUNCTION_AT_ADDRESS(void  CGuild::HandleDeleteGuildResponse(char *),CGuild__HandleDeleteGuildResponse);
#endif
#ifdef CGuild__UpdatePublicComment
FUNCTION_AT_ADDRESS(void  CGuild::UpdatePublicComment(char *),CGuild__UpdatePublicComment);
#endif
#ifdef CGuild__UpdateMemberStatus
FUNCTION_AT_ADDRESS(void  CGuild::UpdateMemberStatus(char *),CGuild__UpdateMemberStatus);
#endif
#ifdef CGuild__HandleMemberLevelUpdate
FUNCTION_AT_ADDRESS(void  CGuild::HandleMemberLevelUpdate(char *),CGuild__HandleMemberLevelUpdate);
#endif
#ifdef CGuild__UpdateGuildMemberOnWindow
FUNCTION_AT_ADDRESS(void  CGuild::UpdateGuildMemberOnWindow(class GuildMember *),CGuild__UpdateGuildMemberOnWindow);
#endif
#ifdef CGuild__ChangeGuildMemberName
FUNCTION_AT_ADDRESS(void  CGuild::ChangeGuildMemberName(char *),CGuild__ChangeGuildMemberName);
#endif
#ifdef CGuild__FindMemberByName
FUNCTION_AT_ADDRESS(class GuildMember *  CGuild::FindMemberByName(char *),CGuild__FindMemberByName);
#endif
#ifdef GuildMember__GuildMember
FUNCTION_AT_ADDRESS( GuildMember::GuildMember(void),GuildMember__GuildMember);
#endif
#ifdef ChannelServerApi__ChannelServerApi
FUNCTION_AT_ADDRESS( ChannelServerApi::ChannelServerApi(char *,int,char *,char *,class ChannelServerHandler *,bool,bool,char *),ChannelServerApi__ChannelServerApi);
#endif
#ifdef ChannelServerApi__dChannelServerApi
FUNCTION_AT_ADDRESS( ChannelServerApi::~ChannelServerApi(void),ChannelServerApi__dChannelServerApi);
#endif
#ifdef ChannelServerApi__FreeChannelList
FUNCTION_AT_ADDRESS(void  ChannelServerApi::FreeChannelList(void),ChannelServerApi__FreeChannelList);
#endif
#ifdef ChannelServerApi__GetStatus
//FUNCTION_AT_ADDRESS(enum ChannelServerApi::Status  ChannelServerApi::GetStatus(void),ChannelServerApi__GetStatus);
#endif
#ifdef ChannelServerApi__SendMessageA
FUNCTION_AT_ADDRESS(void  ChannelServerApi::SendMessageA(char *),ChannelServerApi__SendMessageA);
#endif
#ifdef ChannelServerApi__SortBuddyList
FUNCTION_AT_ADDRESS(void  ChannelServerApi::SortBuddyList(void),ChannelServerApi__SortBuddyList);
#endif
#ifdef UdpManager__Release
FUNCTION_AT_ADDRESS(void  UdpManager::Release(void),UdpManager__Release);
#endif
#ifdef ChannelServerApi__SetBuddyStatus
//FUNCTION_AT_ADDRESS(void  ChannelServerApi::SetBuddyStatus(char *,enum ChannelServerApi::BuddyStatus),ChannelServerApi__SetBuddyStatus);
#endif
#ifdef UdpConnection__Release
FUNCTION_AT_ADDRESS(void  UdpConnection::Release(void),UdpConnection__Release);
#endif
#ifdef ChannelServerApi__GiveTime
FUNCTION_AT_ADDRESS(void  ChannelServerApi::GiveTime(void),ChannelServerApi__GiveTime);
#endif
#ifdef ChannelServerApi__GetChannelNumber
FUNCTION_AT_ADDRESS(int  ChannelServerApi::GetChannelNumber(char *),ChannelServerApi__GetChannelNumber);
#endif
#ifdef ChannelServerApi__GetChannelName
FUNCTION_AT_ADDRESS(char *  ChannelServerApi::GetChannelName(int),ChannelServerApi__GetChannelName);
#endif
#ifdef ChannelServerApi__Strncpy
FUNCTION_AT_ADDRESS(char * __cdecl ChannelServerApi::Strncpy(char *,char *,int),ChannelServerApi__Strncpy);
#endif
#ifdef ChannelServerApi__SmartResize
FUNCTION_AT_ADDRESS(void * __cdecl ChannelServerApi::SmartResize(void *,int,int),ChannelServerApi__SmartResize);
#endif
#ifdef ChannelServerApi__GetNextField
FUNCTION_AT_ADDRESS(int __cdecl ChannelServerApi::GetNextField(char *,int,char * *,char),ChannelServerApi__GetNextField);
#endif
#ifdef JournalNPC__JournalNPC
FUNCTION_AT_ADDRESS( JournalNPC::JournalNPC(void),JournalNPC__JournalNPC);
#endif
#ifdef JournalNPC__dJournalNPC
FUNCTION_AT_ADDRESS( JournalNPC::~JournalNPC(void),JournalNPC__dJournalNPC);
#endif
#ifdef JournalNPC__AllocateArray
FUNCTION_AT_ADDRESS(void  JournalNPC::AllocateArray(void),JournalNPC__AllocateArray);
#endif
#ifdef JournalNPC__CleanEntries
FUNCTION_AT_ADDRESS(void  JournalNPC::CleanEntries(void),JournalNPC__CleanEntries);
#endif
#ifdef JournalNPC__GetText
FUNCTION_AT_ADDRESS(char * __cdecl JournalNPC::GetText(int),JournalNPC__GetText);
#endif
#ifdef JournalNPC__GetEntry
FUNCTION_AT_ADDRESS(struct JournalEntry *  JournalNPC::GetEntry(int),JournalNPC__GetEntry);
#endif
#ifdef JournalNPC__FindEntryByHash
FUNCTION_AT_ADDRESS(struct JournalEntry *  JournalNPC::FindEntryByHash(int),JournalNPC__FindEntryByHash);
#endif
#ifdef JournalNPC__FindEntryByCategory
FUNCTION_AT_ADDRESS(struct JournalEntry *  JournalNPC::FindEntryByCategory(int,int),JournalNPC__FindEntryByCategory);
#endif
#ifdef JournalNPC__FindThisText
FUNCTION_AT_ADDRESS(int  JournalNPC::FindThisText(char *,bool,int),JournalNPC__FindThisText);
#endif
#ifdef JournalNPC__AddEntry
FUNCTION_AT_ADDRESS(int  JournalNPC::AddEntry(long,float,float,float,int,int),JournalNPC__AddEntry);
#endif
#ifdef JournalNPC__AddEntry1
FUNCTION_AT_ADDRESS(int  JournalNPC::AddEntry(long,float,float,float,char *,int),JournalNPC__AddEntry1);
#endif
#ifdef JournalNPC__DeleteEntryByIndex
FUNCTION_AT_ADDRESS(int  JournalNPC::DeleteEntryByIndex(int),JournalNPC__DeleteEntryByIndex);
#endif
#ifdef JournalNPC__DeleteEntryByHash
FUNCTION_AT_ADDRESS(int  JournalNPC::DeleteEntryByHash(int),JournalNPC__DeleteEntryByHash);
#endif
#ifdef JournalNPC__ConvertCategory
FUNCTION_AT_ADDRESS(void  JournalNPC::ConvertCategory(int,int),JournalNPC__ConvertCategory);
#endif
#ifdef JournalNPC__ComputeLatestTime
FUNCTION_AT_ADDRESS(void  JournalNPC::ComputeLatestTime(void),JournalNPC__ComputeLatestTime);
#endif
#ifdef ConversationJournal__ConversationJournal
FUNCTION_AT_ADDRESS( ConversationJournal::ConversationJournal(void),ConversationJournal__ConversationJournal);
#endif
#ifdef ConversationJournal__dConversationJournal
FUNCTION_AT_ADDRESS( ConversationJournal::~ConversationJournal(void),ConversationJournal__dConversationJournal);
#endif
#ifdef ConversationJournal__Clean
FUNCTION_AT_ADDRESS(void  ConversationJournal::Clean(void),ConversationJournal__Clean);
#endif
#ifdef ConversationJournal__AllocateNPCArray
FUNCTION_AT_ADDRESS(void  ConversationJournal::AllocateNPCArray(void),ConversationJournal__AllocateNPCArray);
#endif
#ifdef ConversationJournal__AllocateCatArray
FUNCTION_AT_ADDRESS(void  ConversationJournal::AllocateCatArray(void),ConversationJournal__AllocateCatArray);
#endif
#ifdef ConversationJournal__GetNPC
FUNCTION_AT_ADDRESS(class JournalNPC *  ConversationJournal::GetNPC(int),ConversationJournal__GetNPC);
#endif
#ifdef ConversationJournal__FindNPCByNameZone
FUNCTION_AT_ADDRESS(class JournalNPC *  ConversationJournal::FindNPCByNameZone(char *,int),ConversationJournal__FindNPCByNameZone);
#endif
#ifdef ConversationJournal__DeleteNPC
FUNCTION_AT_ADDRESS(int  ConversationJournal::DeleteNPC(char *,int),ConversationJournal__DeleteNPC);
#endif
#ifdef ConversationJournal__AddNPC
FUNCTION_AT_ADDRESS(class JournalNPC *  ConversationJournal::AddNPC(char *,int),ConversationJournal__AddNPC);
#endif
#ifdef ConversationJournal__AddEntry
FUNCTION_AT_ADDRESS(int  ConversationJournal::AddEntry(char *,int,long,float,float,float,char *,int),ConversationJournal__AddEntry);
#endif
#ifdef ConversationJournal__AddCategory
FUNCTION_AT_ADDRESS(struct JournalCategory *  ConversationJournal::AddCategory(int),ConversationJournal__AddCategory);
#endif
#ifdef ConversationJournal__FindFreeID
FUNCTION_AT_ADDRESS(int  ConversationJournal::FindFreeID(void),ConversationJournal__FindFreeID);
#endif
#ifdef ConversationJournal__AddCategory1
FUNCTION_AT_ADDRESS(struct JournalCategory *  ConversationJournal::AddCategory(char *,char *,int),ConversationJournal__AddCategory1);
#endif
#ifdef ConversationJournal__DeleteCategory
FUNCTION_AT_ADDRESS(void  ConversationJournal::DeleteCategory(int),ConversationJournal__DeleteCategory);
#endif
#ifdef ConversationJournal__GetCategory
FUNCTION_AT_ADDRESS(struct JournalCategory *  ConversationJournal::GetCategory(int),ConversationJournal__GetCategory);
#endif
#ifdef ConversationJournal__GetCategory1
FUNCTION_AT_ADDRESS(struct JournalCategory *  ConversationJournal::GetCategory(char *),ConversationJournal__GetCategory1);
#endif
#ifdef ConversationJournal__GetCategoryList
FUNCTION_AT_ADDRESS(struct JournalCategory * *  ConversationJournal::GetCategoryList(void),ConversationJournal__GetCategoryList);
#endif
#ifdef ConversationJournal__Save
FUNCTION_AT_ADDRESS(int  ConversationJournal::Save(char *),ConversationJournal__Save);
#endif
#ifdef ConversationJournal__Load
FUNCTION_AT_ADDRESS(int  ConversationJournal::Load(char *),ConversationJournal__Load);
#endif
#ifdef ConversationJournal__ReadCategory
FUNCTION_AT_ADDRESS(void  ConversationJournal::ReadCategory(struct _iobuf *),ConversationJournal__ReadCategory);
#endif
#ifdef JournalNPC__ReadEntry
FUNCTION_AT_ADDRESS(int  JournalNPC::ReadEntry(struct _iobuf *),JournalNPC__ReadEntry);
#endif
#ifdef ConversationJournal__ReadNPC
FUNCTION_AT_ADDRESS(class JournalNPC *  ConversationJournal::ReadNPC(struct _iobuf *),ConversationJournal__ReadNPC);
#endif
#ifdef CRaid__CRaid
FUNCTION_AT_ADDRESS( CRaid::CRaid(void),CRaid__CRaid);
#endif
#ifdef CRaid__HandleS2CRaidMessage
FUNCTION_AT_ADDRESS(void  CRaid::HandleS2CRaidMessage(char *),CRaid__HandleS2CRaidMessage);
#endif
#ifdef CRaid__HandleC2SRaidMessage
FUNCTION_AT_ADDRESS(void  CRaid::HandleC2SRaidMessage(char *),CRaid__HandleC2SRaidMessage);
#endif
#ifdef CRaid__IsInRaid
FUNCTION_AT_ADDRESS(bool  CRaid::IsInRaid(void),CRaid__IsInRaid);
#endif
#ifdef CRaid__IsInvited
FUNCTION_AT_ADDRESS(bool  CRaid::IsInvited(void),CRaid__IsInvited);
#endif
#ifdef CRaid__ClearInvitedState
FUNCTION_AT_ADDRESS(void  CRaid::ClearInvitedState(void),CRaid__ClearInvitedState);
#endif
#ifdef CRaid__IsRaidLeader
FUNCTION_AT_ADDRESS(bool  CRaid::IsRaidLeader(void),CRaid__IsRaidLeader);
#endif
#ifdef CRaid__IsRaidGroupLeader
FUNCTION_AT_ADDRESS(bool  CRaid::IsRaidGroupLeader(void),CRaid__IsRaidGroupLeader);
#endif
#ifdef CRaid__SetTargetRaidPlayer
FUNCTION_AT_ADDRESS(void  CRaid::SetTargetRaidPlayer(char *),CRaid__SetTargetRaidPlayer);
#endif
#ifdef CRaid__InitializeRaid
FUNCTION_AT_ADDRESS(void  CRaid::InitializeRaid(char *),CRaid__InitializeRaid);
#endif
#ifdef CRaid__RaidCreated
FUNCTION_AT_ADDRESS(void  CRaid::RaidCreated(struct CreateRaidMessage *),CRaid__RaidCreated);
#endif
#ifdef CRaid__AddRaidMember
FUNCTION_AT_ADDRESS(void  CRaid::AddRaidMember(struct RaidAddMember *),CRaid__AddRaidMember);
#endif
#ifdef CRaid__DeleteRaidMember
FUNCTION_AT_ADDRESS(void  CRaid::DeleteRaidMember(struct SCRaidMessage *),CRaid__DeleteRaidMember);
#endif
#ifdef CRaid__ChangeLeadership
FUNCTION_AT_ADDRESS(void  CRaid::ChangeLeadership(char *),CRaid__ChangeLeadership);
#endif
#ifdef CRaid__RenameMember
FUNCTION_AT_ADDRESS(void  CRaid::RenameMember(struct RenameRaidMember *),CRaid__RenameMember);
#endif
#ifdef CRaid__HandlePositionChange
FUNCTION_AT_ADDRESS(void  CRaid::HandlePositionChange(struct SCRaidMessage *),CRaid__HandlePositionChange);
#endif
#ifdef CRaid__RaidGroupLeaderChange
FUNCTION_AT_ADDRESS(void  CRaid::RaidGroupLeaderChange(struct SCRaidMessage *),CRaid__RaidGroupLeaderChange);
#endif
#ifdef CRaid__SetLootTypeResponse
FUNCTION_AT_ADDRESS(void  CRaid::SetLootTypeResponse(struct SCRaidMessage *),CRaid__SetLootTypeResponse);
#endif
#ifdef CRaid__HandleSetLootType
FUNCTION_AT_ADDRESS(void  CRaid::HandleSetLootType(int),CRaid__HandleSetLootType);
#endif
#ifdef CRaid__HandleAddLooter
FUNCTION_AT_ADDRESS(void  CRaid::HandleAddLooter(char *),CRaid__HandleAddLooter);
#endif
#ifdef UdpMisc__GetValue32
FUNCTION_AT_ADDRESS(unsigned int __cdecl UdpMisc::GetValue32(void const *),UdpMisc__GetValue32);
#endif
#ifdef Util__GetValue32
//FUNCTION_AT_ADDRESS(unsigned int __cdecl Util::GetValue32(void const *),Util__GetValue32);
#endif
#ifdef CRaid__HandleRemoveLooter
FUNCTION_AT_ADDRESS(void  CRaid::HandleRemoveLooter(char *),CRaid__HandleRemoveLooter);
#endif
#ifdef CRaid__CreateInviteRaid
FUNCTION_AT_ADDRESS(void  CRaid::CreateInviteRaid(void),CRaid__CreateInviteRaid);
#endif
#ifdef CRaid__SendInviteResponse
FUNCTION_AT_ADDRESS(void  CRaid::SendInviteResponse(bool),CRaid__SendInviteResponse);
#endif
#ifdef CRaid__SendLeadershipChange
FUNCTION_AT_ADDRESS(void  CRaid::SendLeadershipChange(char *),CRaid__SendLeadershipChange);
#endif
#ifdef CRaid__RemoveRaidMember
FUNCTION_AT_ADDRESS(void  CRaid::RemoveRaidMember(void),CRaid__RemoveRaidMember);
#endif
#ifdef CRaid__SetLootType
FUNCTION_AT_ADDRESS(void  CRaid::SetLootType(char *),CRaid__SetLootType);
#endif
#ifdef CRaid__GetLootType
FUNCTION_AT_ADDRESS(int  CRaid::GetLootType(void),CRaid__GetLootType);
#endif
#ifdef CRaid__AddRaidLooter
FUNCTION_AT_ADDRESS(void  CRaid::AddRaidLooter(void),CRaid__AddRaidLooter);
#endif
#ifdef CRaid__RemoveRaidLooter
FUNCTION_AT_ADDRESS(void  CRaid::RemoveRaidLooter(void),CRaid__RemoveRaidLooter);
#endif
#ifdef CRaid__SendRaidChat
FUNCTION_AT_ADDRESS(void  CRaid::SendRaidChat(char *),CRaid__SendRaidChat);
#endif
#ifdef CRaid__ResetWindow
FUNCTION_AT_ADDRESS(void  CRaid::ResetWindow(void),CRaid__ResetWindow);
#endif
#ifdef CRaid__UpdateClassColor
FUNCTION_AT_ADDRESS(void  CRaid::UpdateClassColor(int,unsigned long),CRaid__UpdateClassColor);
#endif
#ifdef CRaid__HandleCreateInviteRaid
FUNCTION_AT_ADDRESS(void  CRaid::HandleCreateInviteRaid(struct CSRaidMessage *),CRaid__HandleCreateInviteRaid);
#endif
#ifdef CRaid__GetNumRaidMembers
FUNCTION_AT_ADDRESS(int  CRaid::GetNumRaidMembers(void),CRaid__GetNumRaidMembers);
#endif
#ifdef CRaid__GetRaidMemberAt
FUNCTION_AT_ADDRESS(struct RaidMember *  CRaid::GetRaidMemberAt(int),CRaid__GetRaidMemberAt);
#endif
#ifdef CRaid__SetRaidLeader
FUNCTION_AT_ADDRESS(void  CRaid::SetRaidLeader(char *),CRaid__SetRaidLeader);
#endif
#ifdef CRaid__FindPlayerIndex
FUNCTION_AT_ADDRESS(int  CRaid::FindPlayerIndex(char *),CRaid__FindPlayerIndex);
#endif
#ifdef CRaid__IsRaidMember
FUNCTION_AT_ADDRESS(bool  CRaid::IsRaidMember(char *),CRaid__IsRaidMember);
#endif
#ifdef CRaid__FindOpenIndex
FUNCTION_AT_ADDRESS(int  CRaid::FindOpenIndex(void),CRaid__FindOpenIndex);
#endif
#ifdef CRaid__FindRaidGroupLeader
FUNCTION_AT_ADDRESS(int  CRaid::FindRaidGroupLeader(int),CRaid__FindRaidGroupLeader);
#endif
#ifdef CRaid__ResetRaid
FUNCTION_AT_ADDRESS(void  CRaid::ResetRaid(void),CRaid__ResetRaid);
#endif
#ifdef CRaid__DetermineRaidChanges
FUNCTION_AT_ADDRESS(void  CRaid::DetermineRaidChanges(char *),CRaid__DetermineRaidChanges);
#endif
#ifdef CRaid__SendRaidMsg
FUNCTION_AT_ADDRESS(void  CRaid::SendRaidMsg(int,char *,char *,int),CRaid__SendRaidMsg);
#endif
#ifdef CRaid__UpdateOptionsWindow
FUNCTION_AT_ADDRESS(void  CRaid::UpdateOptionsWindow(void),CRaid__UpdateOptionsWindow);
#endif
#ifdef CRaid__IsRaidLooter
FUNCTION_AT_ADDRESS(bool  CRaid::IsRaidLooter(char *),CRaid__IsRaidLooter);
#endif
#ifdef CRaid__UpdateLevelAverage
FUNCTION_AT_ADDRESS(void  CRaid::UpdateLevelAverage(void),CRaid__UpdateLevelAverage);
#endif
#ifdef CDisplay__CDisplay
FUNCTION_AT_ADDRESS( CDisplay::CDisplay(struct HWND__ *),CDisplay__CDisplay);
#endif
#ifdef CDisplay__dCDisplay
FUNCTION_AT_ADDRESS( CDisplay::~CDisplay(void),CDisplay__dCDisplay);
#endif
#ifdef CDisplay__ResetRenderWindow
FUNCTION_AT_ADDRESS(void  CDisplay::ResetRenderWindow(void),CDisplay__ResetRenderWindow);
#endif
#ifdef CDisplay__SetCCreateCamera
FUNCTION_AT_ADDRESS(void  CDisplay::SetCCreateCamera(int),CDisplay__SetCCreateCamera);
#endif
#ifdef CDisplay__SetBoneSpriteTint
FUNCTION_AT_ADDRESS(int  CDisplay::SetBoneSpriteTint(struct T3D_DAG *,struct T3D_RGB *),CDisplay__SetBoneSpriteTint);
#endif
#ifdef CDisplay__ReplaceMaterial
FUNCTION_AT_ADDRESS(int  CDisplay::ReplaceMaterial(char *,char *,struct T3D_HIERARCHICALSPRITEINSTANCE *,struct T3D_RGB *,int),CDisplay__ReplaceMaterial);
#endif
#ifdef CDisplay__ReplaceCloakMaterials
FUNCTION_AT_ADDRESS(int  CDisplay::ReplaceCloakMaterials(int,struct T3D_HIERARCHICALSPRITEINSTANCE *,struct T3D_RGB *),CDisplay__ReplaceCloakMaterials);
#endif
#ifdef CDisplay__InitEverQuestLocale
//FUNCTION_AT_ADDRESS(void  CDisplay::InitEverQuestLocale(enum EQLocalize::languages),CDisplay__InitEverQuestLocale);
#endif
#ifdef CDisplay__ReloadUI
FUNCTION_AT_ADDRESS(void  CDisplay::ReloadUI(bool),CDisplay__ReloadUI);
#endif
#ifdef CDisplay__HandleMaterial
FUNCTION_AT_ADDRESS(void  CDisplay::HandleMaterial(class EQ_PC *,int,class EQ_Item *,class EQ_Item *),CDisplay__HandleMaterial);
#endif
#ifdef CDisplay__FixHeading
FUNCTION_AT_ADDRESS(float  CDisplay::FixHeading(float),CDisplay__FixHeading);
#endif
#ifdef CDisplay__HeadingDiff
FUNCTION_AT_ADDRESS(float  CDisplay::HeadingDiff(float,float,float *),CDisplay__HeadingDiff);
#endif
#ifdef CDisplay__DeleteParticleCloudInstance
FUNCTION_AT_ADDRESS(void  CDisplay::DeleteParticleCloudInstance(struct T3D_PARTICLECLOUDINSTANCE * *),CDisplay__DeleteParticleCloudInstance);
#endif
#ifdef CDisplay__ProcessParticleEmitter
FUNCTION_AT_ADDRESS(void  CDisplay::ProcessParticleEmitter(class EQSwitch *),CDisplay__ProcessParticleEmitter);
#endif
#ifdef CDisplay__SlideSwitchLeftRight
FUNCTION_AT_ADDRESS(bool  CDisplay::SlideSwitchLeftRight(class EQSwitch *,float,int,float),CDisplay__SlideSwitchLeftRight);
#endif
#ifdef CDisplay__ProcessSwitches
FUNCTION_AT_ADDRESS(void  CDisplay::ProcessSwitches(void),CDisplay__ProcessSwitches);
#endif
#ifdef CDisplay__default_cameras
FUNCTION_AT_ADDRESS(void  CDisplay::default_cameras(void),CDisplay__default_cameras);
#endif
#ifdef CDisplay__is_3dON
FUNCTION_AT_ADDRESS(int  CDisplay::is_3dON(void),CDisplay__is_3dON);
#endif
#ifdef CDisplay__is_ParticleSystemON
FUNCTION_AT_ADDRESS(int  CDisplay::is_ParticleSystemON(void),CDisplay__is_ParticleSystemON);
#endif
#ifdef CDisplay__InitCommonLights
FUNCTION_AT_ADDRESS(void  CDisplay::InitCommonLights(void),CDisplay__InitCommonLights);
#endif
#ifdef CDisplay__GetNewPCIniFlag
FUNCTION_AT_ADDRESS(int  CDisplay::GetNewPCIniFlag(int,int),CDisplay__GetNewPCIniFlag);
#endif
#ifdef CDisplay__ShouldLoadNewPcModel
FUNCTION_AT_ADDRESS(int  CDisplay::ShouldLoadNewPcModel(int,int),CDisplay__ShouldLoadNewPcModel);
#endif
#ifdef CDisplay__GetIniRaceName
FUNCTION_AT_ADDRESS(char *  CDisplay::GetIniRaceName(int),CDisplay__GetIniRaceName);
#endif
#ifdef CDisplay__InitWorld
FUNCTION_AT_ADDRESS(void  CDisplay::InitWorld(void),CDisplay__InitWorld);
#endif
#ifdef CDisplay__InitDDraw
FUNCTION_AT_ADDRESS(void  CDisplay::InitDDraw(void),CDisplay__InitDDraw);
#endif
#ifdef CDisplay__InitNewUI
FUNCTION_AT_ADDRESS(void  CDisplay::InitNewUI(void),CDisplay__InitNewUI);
#endif
#ifdef CXWndDrawTemplate__operator_equal
FUNCTION_AT_ADDRESS(class CXWndDrawTemplate &  CXWndDrawTemplate::operator=(class CXWndDrawTemplate const &),CXWndDrawTemplate__operator_equal);
#endif
#ifdef CButtonDrawTemplate__operator_equal
FUNCTION_AT_ADDRESS(class CButtonDrawTemplate &  CButtonDrawTemplate::operator=(class CButtonDrawTemplate const &),CButtonDrawTemplate__operator_equal);
#endif
#ifdef CScrollbarTemplate__operator_equal
FUNCTION_AT_ADDRESS(class CScrollbarTemplate &  CScrollbarTemplate::operator=(class CScrollbarTemplate const &),CScrollbarTemplate__operator_equal);
#endif
#ifdef CTAFrameDraw__operator_equal
FUNCTION_AT_ADDRESS(class CTAFrameDraw &  CTAFrameDraw::operator=(class CTAFrameDraw const &),CTAFrameDraw__operator_equal);
#endif
#ifdef CDisplay__InitCharSelectUI
FUNCTION_AT_ADDRESS(void  CDisplay::InitCharSelectUI(void),CDisplay__InitCharSelectUI);
#endif
#ifdef CDisplay__InitGameUI
FUNCTION_AT_ADDRESS(void  CDisplay::InitGameUI(void),CDisplay__InitGameUI);
#endif
#ifdef CDisplay__CleanCharSelectUI
FUNCTION_AT_ADDRESS(void  CDisplay::CleanCharSelectUI(void),CDisplay__CleanCharSelectUI);
#endif
#ifdef CDisplay__CleanGameUI
FUNCTION_AT_ADDRESS(void  CDisplay::CleanGameUI(void),CDisplay__CleanGameUI);
#endif
#ifdef CDisplay__CleanUpNewUI
FUNCTION_AT_ADDRESS(void  CDisplay::CleanUpNewUI(void),CDisplay__CleanUpNewUI);
#endif
#ifdef CDisplay__ActivateMainUI
FUNCTION_AT_ADDRESS(void  CDisplay::ActivateMainUI(bool),CDisplay__ActivateMainUI);
#endif
#ifdef CDisplay__DeactivateMainUI
FUNCTION_AT_ADDRESS(void  CDisplay::DeactivateMainUI(void),CDisplay__DeactivateMainUI);
#endif
#ifdef CDisplay__NewUIProcessEscape
FUNCTION_AT_ADDRESS(void  CDisplay::NewUIProcessEscape(void),CDisplay__NewUIProcessEscape);
#endif
#ifdef CDisplay__KeyMapUpdated
FUNCTION_AT_ADDRESS(void  CDisplay::KeyMapUpdated(void),CDisplay__KeyMapUpdated);
#endif
#ifdef CDisplay__GetWorldFilePath
FUNCTION_AT_ADDRESS(bool const  CDisplay::GetWorldFilePath(char *,char const *),CDisplay__GetWorldFilePath);
#endif
#ifdef CDisplay__LoadWorldFile
FUNCTION_AT_ADDRESS(unsigned char  CDisplay::LoadWorldFile(char *,char *,int,unsigned char),CDisplay__LoadWorldFile);
#endif
#ifdef CDisplay__LoadNPCFromS3D
FUNCTION_AT_ADDRESS(unsigned char  CDisplay::LoadNPCFromS3D(char *,char *,char *),CDisplay__LoadNPCFromS3D);
#endif
#ifdef CDisplay__LoadBMPFile
FUNCTION_AT_ADDRESS(unsigned char  CDisplay::LoadBMPFile(void),CDisplay__LoadBMPFile);
#endif
#ifdef CDisplay__StartWorldDisplay
//FUNCTION_AT_ADDRESS(void  CDisplay::StartWorldDisplay(enum EQZoneIndex),CDisplay__StartWorldDisplay);
#endif
#ifdef CDisplay__StartWorldDisplay_Bailout
FUNCTION_AT_ADDRESS(void  CDisplay::StartWorldDisplay_Bailout(char const *),CDisplay__StartWorldDisplay_Bailout);
#endif
#ifdef CDisplay__StopWorldDisplay
FUNCTION_AT_ADDRESS(void  CDisplay::StopWorldDisplay(void),CDisplay__StopWorldDisplay);
#endif
#ifdef CDisplay__SetGammaCorrection
FUNCTION_AT_ADDRESS(void  CDisplay::SetGammaCorrection(float),CDisplay__SetGammaCorrection);
#endif
#ifdef CDisplay__SetPCloudDensity
FUNCTION_AT_ADDRESS(void  CDisplay::SetPCloudDensity(int),CDisplay__SetPCloudDensity);
#endif
#ifdef CDisplay__CleanUpDDraw
FUNCTION_AT_ADDRESS(void  CDisplay::CleanUpDDraw(void),CDisplay__CleanUpDDraw);
#endif
#ifdef CDisplay__IsShield
FUNCTION_AT_ADDRESS(unsigned int  CDisplay::IsShield(int)const ,CDisplay__IsShield);
#endif
#ifdef CDisplay__GetItemType
FUNCTION_AT_ADDRESS(int  CDisplay::GetItemType(int),CDisplay__GetItemType);
#endif
#ifdef CDisplay__GetUserDefinedColor
FUNCTION_AT_ADDRESS(unsigned long __cdecl CDisplay::GetUserDefinedColor(int),CDisplay__GetUserDefinedColor);
#endif
#ifdef CDisplay__SetUserDefinedColor
FUNCTION_AT_ADDRESS(void __cdecl CDisplay::SetUserDefinedColor(int,int,int,int),CDisplay__SetUserDefinedColor);
#endif
#ifdef CDisplay__InitUserDefinedColors
FUNCTION_AT_ADDRESS(void  CDisplay::InitUserDefinedColors(void),CDisplay__InitUserDefinedColors);
#endif
#ifdef CDisplay__WriteTextHD2
FUNCTION_AT_ADDRESS(int __cdecl CDisplay::WriteTextHD2(char const *,int,int,int),CDisplay__WriteTextHD2);
#endif
#ifdef CXWndManager__GetDisplayWidth
FUNCTION_AT_ADDRESS(unsigned __int32  CXWndManager::GetDisplayWidth(void)const ,CXWndManager__GetDisplayWidth);
#endif
#ifdef CXWndManager__GetFont
FUNCTION_AT_ADDRESS(class CTextureFont *  CXWndManager::GetFont(int)const ,CXWndManager__GetFont);
#endif
#ifdef CDisplay__SetActorScaleFactor
FUNCTION_AT_ADDRESS(void  CDisplay::SetActorScaleFactor(struct T3D_tagACTORINSTANCE *,float,unsigned char),CDisplay__SetActorScaleFactor);
#endif
#ifdef CDisplay__ShowDisplay
FUNCTION_AT_ADDRESS(void  CDisplay::ShowDisplay(void),CDisplay__ShowDisplay);
#endif
#ifdef CDisplay__CheckForScreenModeToggle
FUNCTION_AT_ADDRESS(void  CDisplay::CheckForScreenModeToggle(void),CDisplay__CheckForScreenModeToggle);
#endif
#ifdef CDisplay__Render_World
FUNCTION_AT_ADDRESS(void  CDisplay::Render_World(void),CDisplay__Render_World);
#endif
#ifdef CDisplay__SetSpecialEnvironment
//FUNCTION_AT_ADDRESS(void  CDisplay::SetSpecialEnvironment(enum EnvironmentType),CDisplay__SetSpecialEnvironment);
#endif
#ifdef CDisplay__SetGenericEnvironment
FUNCTION_AT_ADDRESS(void  CDisplay::SetGenericEnvironment(void),CDisplay__SetGenericEnvironment);
#endif
#ifdef CDisplay__SetupEmitterEnvironment
FUNCTION_AT_ADDRESS(void  CDisplay::SetupEmitterEnvironment(void),CDisplay__SetupEmitterEnvironment);
#endif
#ifdef CDisplay__UpdateMobileEmitterLocations
FUNCTION_AT_ADDRESS(void  CDisplay::UpdateMobileEmitterLocations(void),CDisplay__UpdateMobileEmitterLocations);
#endif
#ifdef CDisplay__RealRender_World
FUNCTION_AT_ADDRESS(void  CDisplay::RealRender_World(void),CDisplay__RealRender_World);
#endif
#ifdef CDisplay__Render_MinWorld
FUNCTION_AT_ADDRESS(void  CDisplay::Render_MinWorld(void),CDisplay__Render_MinWorld);
#endif
#ifdef CDisplay__StartWeather
FUNCTION_AT_ADDRESS(void  CDisplay::StartWeather(int,unsigned char),CDisplay__StartWeather);
#endif
#ifdef CDisplay__ProcessWeather
FUNCTION_AT_ADDRESS(void  CDisplay::ProcessWeather(void),CDisplay__ProcessWeather);
#endif
#ifdef CDisplay__StopWeather
FUNCTION_AT_ADDRESS(void  CDisplay::StopWeather(int,unsigned char),CDisplay__StopWeather);
#endif
#ifdef CDisplay__LightningStrike
FUNCTION_AT_ADDRESS(void  CDisplay::LightningStrike(void),CDisplay__LightningStrike);
#endif
#ifdef CDisplay__GetNearestPlayerInView
FUNCTION_AT_ADDRESS(class EQPlayer *  CDisplay::GetNearestPlayerInView(float,bool),CDisplay__GetNearestPlayerInView);
#endif
#ifdef CDisplay__ProcessEffects
FUNCTION_AT_ADDRESS(void  CDisplay::ProcessEffects(void),CDisplay__ProcessEffects);
#endif
#ifdef CDisplay__ProcessCloud
FUNCTION_AT_ADDRESS(void  CDisplay::ProcessCloud(void),CDisplay__ProcessCloud);
#endif
#ifdef CDisplay__DDrawUpdateDisplay
FUNCTION_AT_ADDRESS(void  CDisplay::DDrawUpdateDisplay(void),CDisplay__DDrawUpdateDisplay);
#endif
#ifdef CDisplay__SetViewActor
FUNCTION_AT_ADDRESS(void  CDisplay::SetViewActor(struct T3D_tagACTORINSTANCE *),CDisplay__SetViewActor);
#endif
#ifdef CDisplay__SwitchToDefaultCameraMode
FUNCTION_AT_ADDRESS(void  CDisplay::SwitchToDefaultCameraMode(void),CDisplay__SwitchToDefaultCameraMode);
#endif
#ifdef CDisplay__SetYon
FUNCTION_AT_ADDRESS(void  CDisplay::SetYon(float),CDisplay__SetYon);
#endif
#ifdef CDisplay__SetActorYon
FUNCTION_AT_ADDRESS(void  CDisplay::SetActorYon(float),CDisplay__SetActorYon);
#endif
#ifdef CDisplay__SetViewAngle
FUNCTION_AT_ADDRESS(void  CDisplay::SetViewAngle(int),CDisplay__SetViewAngle);
#endif
#ifdef CDisplay__UpdateCameraAfterModeSwitch
FUNCTION_AT_ADDRESS(void  CDisplay::UpdateCameraAfterModeSwitch(void),CDisplay__UpdateCameraAfterModeSwitch);
#endif
#ifdef CDisplay__ChangeVideoMode
FUNCTION_AT_ADDRESS(void  CDisplay::ChangeVideoMode(void),CDisplay__ChangeVideoMode);
#endif
#ifdef CDisplay__ToggleView
FUNCTION_AT_ADDRESS(void  CDisplay::ToggleView(void),CDisplay__ToggleView);
#endif
#ifdef CDisplay__SetFog
FUNCTION_AT_ADDRESS(void  CDisplay::SetFog(bool,float,float,unsigned char,unsigned char,unsigned char),CDisplay__SetFog);
#endif
#ifdef CDisplay__ClearScreen
FUNCTION_AT_ADDRESS(void  CDisplay::ClearScreen(void),CDisplay__ClearScreen);
#endif
#ifdef CDisplay__CreatePlayerActor
FUNCTION_AT_ADDRESS(void  CDisplay::CreatePlayerActor(class EQPlayer *),CDisplay__CreatePlayerActor);
#endif
#ifdef CDisplay__SetActorUserData
FUNCTION_AT_ADDRESS(void  CDisplay::SetActorUserData(struct T3D_tagACTORINSTANCE *,void *),CDisplay__SetActorUserData);
#endif
#ifdef CDisplay__CreateLight
FUNCTION_AT_ADDRESS(struct T3D_POINTLIGHT *  CDisplay::CreateLight(unsigned char,float,float,float,float),CDisplay__CreateLight);
#endif
#ifdef CDisplay__GetIntensity
FUNCTION_AT_ADDRESS(unsigned char  CDisplay::GetIntensity(unsigned char),CDisplay__GetIntensity);
#endif
#ifdef CDisplay__DeleteLight
FUNCTION_AT_ADDRESS(void  CDisplay::DeleteLight(struct T3D_POINTLIGHT *),CDisplay__DeleteLight);
#endif
#ifdef CDisplay__PlaySoundAtLocation
FUNCTION_AT_ADDRESS(void  CDisplay::PlaySoundAtLocation(float,float,float,int),CDisplay__PlaySoundAtLocation);
#endif
#ifdef CDisplay__SetUserRender
FUNCTION_AT_ADDRESS(long  CDisplay::SetUserRender(int),CDisplay__SetUserRender);
#endif
#ifdef CDisplay__GetClickedActor
FUNCTION_AT_ADDRESS(struct T3D_tagACTORINSTANCE *  CDisplay::GetClickedActor(unsigned long,unsigned long,unsigned long,void *,void *),CDisplay__GetClickedActor);
#endif
#ifdef CDisplay__CreateActor
FUNCTION_AT_ADDRESS(struct T3D_tagACTORINSTANCE *  CDisplay::CreateActor(char *,float,float,float,float,float,float,bool,bool),CDisplay__CreateActor);
#endif
#ifdef CDisplay__SetActorBoundingRadius
FUNCTION_AT_ADDRESS(float  CDisplay::SetActorBoundingRadius(struct T3D_tagACTORINSTANCE *,float,float),CDisplay__SetActorBoundingRadius);
#endif
#ifdef CDisplay__DeleteActor
FUNCTION_AT_ADDRESS(void  CDisplay::DeleteActor(struct T3D_tagACTORINSTANCE *),CDisplay__DeleteActor);
#endif
#ifdef CDisplay__dupActorHierarchicalSprite
FUNCTION_AT_ADDRESS(struct T3D_HIERARCHICALSPRITEINSTANCE *  CDisplay::dupActorHierarchicalSprite(struct T3D_tagACTORINSTANCE *),CDisplay__dupActorHierarchicalSprite);
#endif
#ifdef CDisplay__ToggleCharacterNameSprites
FUNCTION_AT_ADDRESS(void  CDisplay::ToggleCharacterNameSprites(bool),CDisplay__ToggleCharacterNameSprites);
#endif
#ifdef CDisplay__ToggleNpcNameSprites
FUNCTION_AT_ADDRESS(void  CDisplay::ToggleNpcNameSprites(bool),CDisplay__ToggleNpcNameSprites);
#endif
#ifdef CDisplay__TurnInfravisionEffectOn
FUNCTION_AT_ADDRESS(int  CDisplay::TurnInfravisionEffectOn(void),CDisplay__TurnInfravisionEffectOn);
#endif
#ifdef CDisplay__TurnInfravisionEffectOff
FUNCTION_AT_ADDRESS(int  CDisplay::TurnInfravisionEffectOff(void),CDisplay__TurnInfravisionEffectOff);
#endif
#ifdef CDisplay__SpurtBloodOnDag
FUNCTION_AT_ADDRESS(void  CDisplay::SpurtBloodOnDag(struct T3D_DAG *),CDisplay__SpurtBloodOnDag);
#endif
#ifdef CDisplay__SetDayPeriod
FUNCTION_AT_ADDRESS(void  CDisplay::SetDayPeriod(unsigned char),CDisplay__SetDayPeriod);
#endif
#ifdef CDisplay__SetSkyLayer
FUNCTION_AT_ADDRESS(void  CDisplay::SetSkyLayer(int),CDisplay__SetSkyLayer);
#endif
#ifdef CDisplay__GetSkyTime
FUNCTION_AT_ADDRESS(int  CDisplay::GetSkyTime(int *,int *),CDisplay__GetSkyTime);
#endif
#ifdef CDisplay__SetSunLight
FUNCTION_AT_ADDRESS(void  CDisplay::SetSunLight(void),CDisplay__SetSunLight);
#endif
#ifdef CDisplay__SetSkyBackground
FUNCTION_AT_ADDRESS(void  CDisplay::SetSkyBackground(void),CDisplay__SetSkyBackground);
#endif
#ifdef CDisplay__ProcessSky
FUNCTION_AT_ADDRESS(void  CDisplay::ProcessSky(void),CDisplay__ProcessSky);
#endif
#ifdef CDisplay__SimpleDistance
FUNCTION_AT_ADDRESS(float  CDisplay::SimpleDistance(float,float,float,float,float,float,float),CDisplay__SimpleDistance);
#endif
#ifdef CDisplay__TrueDistance
FUNCTION_AT_ADDRESS(float  CDisplay::TrueDistance(float,float,float,float,float,float,float),CDisplay__TrueDistance);
#endif
#ifdef CDisplay__PlayerSimpleDistance
FUNCTION_AT_ADDRESS(float  CDisplay::PlayerSimpleDistance(class EQPlayer *,class EQPlayer *,float),CDisplay__PlayerSimpleDistance);
#endif
#ifdef CDisplay__PlayerDistance
FUNCTION_AT_ADDRESS(float  CDisplay::PlayerDistance(class EQPlayer *,class EQPlayer *,float),CDisplay__PlayerDistance);
#endif
#ifdef CDisplay__hideGrassObjects
FUNCTION_AT_ADDRESS(void  CDisplay::hideGrassObjects(void),CDisplay__hideGrassObjects);
#endif
#ifdef CDisplay__updateGrassObjects
FUNCTION_AT_ADDRESS(void  CDisplay::updateGrassObjects(void),CDisplay__updateGrassObjects);
#endif
#ifdef CDisplay__loadGrassObjects
FUNCTION_AT_ADDRESS(void  CDisplay::loadGrassObjects(char *),CDisplay__loadGrassObjects);
#endif
#ifdef CDisplay__SetAmbientLight
FUNCTION_AT_ADDRESS(void  CDisplay::SetAmbientLight(float),CDisplay__SetAmbientLight);
#endif
#ifdef CDisplay__SetViewActorByName
FUNCTION_AT_ADDRESS(void  CDisplay::SetViewActorByName(char *),CDisplay__SetViewActorByName);
#endif
#ifdef CDisplay__SetActorSpriteTint
FUNCTION_AT_ADDRESS(void  CDisplay::SetActorSpriteTint(struct _EQRGB *,struct T3D_tagACTORINSTANCE *),CDisplay__SetActorSpriteTint);
#endif
#ifdef CDisplay__FreeAllItemLists
FUNCTION_AT_ADDRESS(void  CDisplay::FreeAllItemLists(void),CDisplay__FreeAllItemLists);
#endif
#ifdef CActionsWnd__MainPageActivate
FUNCTION_AT_ADDRESS(int  CActionsWnd::MainPageActivate(void),CActionsWnd__MainPageActivate);
#endif
#ifdef CActionsWnd__MainPageDeactivate
FUNCTION_AT_ADDRESS(int  CActionsWnd::MainPageDeactivate(void),CActionsWnd__MainPageDeactivate);
#endif
#ifdef CActionsWnd__SocialsPageDeactivate
FUNCTION_AT_ADDRESS(int  CActionsWnd::SocialsPageDeactivate(void),CActionsWnd__SocialsPageDeactivate);
#endif
#ifdef CGroupSearchWnd__GroupListPageOnProcessFrame
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::GroupListPageOnProcessFrame(void),CGroupSearchWnd__GroupListPageOnProcessFrame);
#endif
#ifdef CGroupSearchWnd__PlayerListPageOnProcessFrame
FUNCTION_AT_ADDRESS(int  CGroupSearchWnd::PlayerListPageOnProcessFrame(void),CGroupSearchWnd__PlayerListPageOnProcessFrame);
#endif
#ifdef COptionsWnd__KeyboardPageOnProcessFrame
FUNCTION_AT_ADDRESS(int  COptionsWnd::KeyboardPageOnProcessFrame(void),COptionsWnd__KeyboardPageOnProcessFrame);
#endif
#ifdef CDisplay__GetFloorHeight
FUNCTION_AT_ADDRESS(float  CDisplay::GetFloorHeight(float,float,float),CDisplay__GetFloorHeight);
#endif
#ifdef CDisplay__GenericSphereColl
FUNCTION_AT_ADDRESS(bool  CDisplay::GenericSphereColl(float,float,float,float,float,float,float *,float *,float *,unsigned char),CDisplay__GenericSphereColl);
#endif
#ifdef CDisplay__FindZoneTopZ
FUNCTION_AT_ADDRESS(float  CDisplay::FindZoneTopZ(float,float,float),CDisplay__FindZoneTopZ);
#endif
#ifdef CDisplay__GetEnvironment
FUNCTION_AT_ADDRESS(unsigned char  CDisplay::GetEnvironment(float,float,float,int *),CDisplay__GetEnvironment);
#endif
#ifdef CDisplay__MoveLocalPlayerToSafeCoords
FUNCTION_AT_ADDRESS(void  CDisplay::MoveLocalPlayerToSafeCoords(void),CDisplay__MoveLocalPlayerToSafeCoords);
#endif
#ifdef CDisplay__SetupEQPlayers
FUNCTION_AT_ADDRESS(void  CDisplay::SetupEQPlayers(void),CDisplay__SetupEQPlayers);
#endif
#ifdef CDisplay__MoveLight
FUNCTION_AT_ADDRESS(void  CDisplay::MoveLight(struct T3D_POINTLIGHT *,struct _physicsinfo *),CDisplay__MoveLight);
#endif
#ifdef ZoneNPCLoadTextManager__ZoneNPCLoadTextManager
FUNCTION_AT_ADDRESS( ZoneNPCLoadTextManager::ZoneNPCLoadTextManager(char *),ZoneNPCLoadTextManager__ZoneNPCLoadTextManager);
#endif
#ifdef ZoneNPCLoadTextManager__dZoneNPCLoadTextManager
FUNCTION_AT_ADDRESS( ZoneNPCLoadTextManager::~ZoneNPCLoadTextManager(void),ZoneNPCLoadTextManager__dZoneNPCLoadTextManager);
#endif
#ifdef ZoneNPCLoadTextManager__LoadText
FUNCTION_AT_ADDRESS(void  ZoneNPCLoadTextManager::LoadText(char *),ZoneNPCLoadTextManager__LoadText);
#endif
#ifdef ZoneNPCLoadTextManager__GetNPCCode
FUNCTION_AT_ADDRESS(char *  ZoneNPCLoadTextManager::GetNPCCode(int),ZoneNPCLoadTextManager__GetNPCCode);
#endif
#ifdef ZoneNPCLoadTextManager__GetS3DName
FUNCTION_AT_ADDRESS(char *  ZoneNPCLoadTextManager::GetS3DName(int),ZoneNPCLoadTextManager__GetS3DName);
#endif
#ifdef public_key__encrypt
FUNCTION_AT_ADDRESS(class vlong  public_key::encrypt(class vlong &),public_key__encrypt);
#endif
#ifdef engineInterface__engineInterface
FUNCTION_AT_ADDRESS( engineInterface::engineInterface(void),engineInterface__engineInterface);
#endif
#ifdef engineInterface__get
FUNCTION_AT_ADDRESS(class engineInterface * __cdecl engineInterface::get(void),engineInterface__get);
#endif
#ifdef engineInterface__ChangeDag
FUNCTION_AT_ADDRESS(unsigned long *  engineInterface::ChangeDag(struct T3D_tagWORLD *,struct T3D_DAG *,char *),engineInterface__ChangeDag);
#endif
#ifdef EQ_AltAbility__EQ_AltAbility
FUNCTION_AT_ADDRESS( EQ_AltAbility::EQ_AltAbility(int),EQ_AltAbility__EQ_AltAbility);
#endif
#ifdef AltAdvManager__AltAdvManager
FUNCTION_AT_ADDRESS( AltAdvManager::AltAdvManager(void),AltAdvManager__AltAdvManager);
#endif
#ifdef AltAdvManager__GetAltAbility
FUNCTION_AT_ADDRESS( struct _ALTABILITY *AltAdvManager::GetAltAbility(int), AltAdvManager__GetAltAbility);
#endif
#ifdef AltAdvManager__IsAbilityReady
FUNCTION_AT_ADDRESS(bool  AltAdvManager::IsAbilityReady(class EQ_PC *,EQData::PALTABILITY,int *),AltAdvManager__IsAbilityReady);
#endif
#ifdef AltAdvManager__CalculateHideTimeReduce
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateHideTimeReduce(class EQ_PC *),AltAdvManager__CalculateHideTimeReduce);
#endif
#ifdef AltAdvManager__GetCalculatedTimer
FUNCTION_AT_ADDRESS(unsigned long  AltAdvManager::GetCalculatedTimer(class EQ_PC *,EQData::PALTABILITY),AltAdvManager__GetCalculatedTimer);
#endif
#ifdef AltAdvManager__GetNextAbilityCost
FUNCTION_AT_ADDRESS(int  AltAdvManager::GetNextAbilityCost(int,int),AltAdvManager__GetNextAbilityCost);
#endif
#ifdef AltAdvManager__TotalPointsInSkill
FUNCTION_AT_ADDRESS(int  AltAdvManager::TotalPointsInSkill(int,int),AltAdvManager__TotalPointsInSkill);
#endif
#ifdef AltAdvManager__CalculateStalwartEnduranceChance
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateStalwartEnduranceChance(class EQ_PC *),AltAdvManager__CalculateStalwartEnduranceChance);
#endif
#ifdef AltAdvManager__CalculateLoHHarmTouchReuseTimer
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateLoHHarmTouchReuseTimer(class EQ_PC *,int),AltAdvManager__CalculateLoHHarmTouchReuseTimer);
#endif
#ifdef AltAdvManager__CalculateSingingMasteryMod
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateSingingMasteryMod(class EQ_PC *,int),AltAdvManager__CalculateSingingMasteryMod);
#endif
#ifdef AltAdvManager__CalculateInstrumentMasteryMod
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateInstrumentMasteryMod(class EQ_PC *),AltAdvManager__CalculateInstrumentMasteryMod);
#endif
#ifdef AltAdvManager__CalculateFleetOfFoot
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateFleetOfFoot(class EQ_PC *),AltAdvManager__CalculateFleetOfFoot);
#endif
#ifdef AltAdvManager__CalculateNimbleEvasionChance
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateNimbleEvasionChance(class EQ_PC *),AltAdvManager__CalculateNimbleEvasionChance);
#endif
#ifdef AltAdvManager__CalculateDoubleAttackChance
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateDoubleAttackChance(class EQ_PC *,int,unsigned char),AltAdvManager__CalculateDoubleAttackChance);
#endif
#ifdef AltAdvManager__CalculateMitigationBoost
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateMitigationBoost(class EQ_PC *,int),AltAdvManager__CalculateMitigationBoost);
#endif
#ifdef AltAdvManager__CalculateSpellCastingMastery
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateSpellCastingMastery(class EQ_PC *),AltAdvManager__CalculateSpellCastingMastery);
#endif
#ifdef AltAdvManager__CalculateMaxHPAA
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateMaxHPAA(class EQ_PC *,int),AltAdvManager__CalculateMaxHPAA);
#endif
#ifdef AltAdvManager__CalculateMaxStatAA
FUNCTION_AT_ADDRESS(int  AltAdvManager::CalculateMaxStatAA(class EQ_PC *,int),AltAdvManager__CalculateMaxStatAA);
#endif
#ifdef AltAdvManager__GetAbilityTitle
FUNCTION_AT_ADDRESS(int  AltAdvManager::GetAbilityTitle(class EQPlayer *),AltAdvManager__GetAbilityTitle);
#endif
#ifdef AltAdvManager__AltSkillReqs
FUNCTION_AT_ADDRESS(int  AltAdvManager::AltSkillReqs(class EQ_PC *,int),AltAdvManager__AltSkillReqs);
#endif
#ifdef AltAdvManager__GetAALevelNeeded
FUNCTION_AT_ADDRESS(int  AltAdvManager::GetAALevelNeeded(class EQ_PC *,int),AltAdvManager__GetAALevelNeeded);
#endif
#ifdef AltAdvManager__MeetsPoPLevelReqs
FUNCTION_AT_ADDRESS(int  AltAdvManager::MeetsPoPLevelReqs(class EQ_PC *,int,int),AltAdvManager__MeetsPoPLevelReqs);
#endif
#ifdef AltAdvManager__CanTrainAbility
FUNCTION_AT_ADDRESS(int  AltAdvManager::CanTrainAbility(class EQ_PC *,int),AltAdvManager__CanTrainAbility);
#endif
#ifdef AltAdvManager__AbilitiesByClass
FUNCTION_AT_ADDRESS(int  AltAdvManager::AbilitiesByClass(int,int),AltAdvManager__AbilitiesByClass);
#endif
#ifdef AltAdvManager__GetAbilityReqs
FUNCTION_AT_ADDRESS(void  AltAdvManager::GetAbilityReqs(char *,int),AltAdvManager__GetAbilityReqs);
#endif
#ifdef EQ_CharacterData__EQ_CharacterDataResetAllMembers
FUNCTION_AT_ADDRESS(void  EQ_CharacterData::EQ_CharacterDataResetAllMembers(void),EQ_CharacterData__EQ_CharacterDataResetAllMembers);
#endif
#ifdef EQ_Affect__Reset
FUNCTION_AT_ADDRESS(void  EQ_Affect::Reset(void),EQ_Affect__Reset);
#endif
#ifdef EQ_Character__EQ_Character
FUNCTION_AT_ADDRESS( EQ_Character::EQ_Character(void),EQ_Character__EQ_Character);
#endif
#ifdef EQ_Character__dEQ_Character
FUNCTION_AT_ADDRESS( EQ_Character::~EQ_Character(void),EQ_Character__dEQ_Character);
#endif
#ifdef EQ_Character__EQ_CharacterResetAllMembers
FUNCTION_AT_ADDRESS(void  EQ_Character::EQ_CharacterResetAllMembers(void),EQ_Character__EQ_CharacterResetAllMembers);
#endif
#ifdef EQ_Character__ModifyCurHP
FUNCTION_AT_ADDRESS(void  EQ_Character::ModifyCurHP(int,class EQPlayer *),EQ_Character__ModifyCurHP);
#endif
#ifdef EQ_Character__normal_to_special
FUNCTION_AT_ADDRESS(int __cdecl EQ_Character::normal_to_special(int),EQ_Character__normal_to_special);
#endif
#ifdef EQ_Character__IsSpellcaster
FUNCTION_AT_ADDRESS(int  EQ_Character::IsSpellcaster(void),EQ_Character__IsSpellcaster);
#endif
#ifdef EQ_Character__DoLight
FUNCTION_AT_ADDRESS(void  EQ_Character::DoLight(unsigned char),EQ_Character__DoLight);
#endif
#ifdef EQ_Character__Skill
FUNCTION_AT_ADDRESS(int  EQ_Character::Skill(int),EQ_Character__Skill);
#endif
#ifdef EQ_Character__HasSpell
FUNCTION_AT_ADDRESS(int  EQ_Character::HasSpell(int),EQ_Character__HasSpell);
#endif
#ifdef EQ_Character__ResetCur_HP
FUNCTION_AT_ADDRESS(void  EQ_Character::ResetCur_HP(int),EQ_Character__ResetCur_HP);
#endif
#ifdef EQ_Character__Cur_HP
FUNCTION_AT_ADDRESS(int  EQ_Character1::Cur_HP(int,unsigned char),EQ_Character__Cur_HP);
#endif
#ifdef EQ_Character__GetHPFromStamina
FUNCTION_AT_ADDRESS(int  EQ_Character::GetHPFromStamina(int),EQ_Character__GetHPFromStamina);
#endif
#ifdef EQ_Character__Cur_Mana
FUNCTION_AT_ADDRESS(int  EQ_Character::Cur_Mana(void),EQ_Character__Cur_Mana);
#endif
#ifdef EQ_Character__IsMage
FUNCTION_AT_ADDRESS(int  EQ_Character::IsMage(void),EQ_Character__IsMage);
#endif
#ifdef EQ_Character__GetClassACBonus
FUNCTION_AT_ADDRESS(int  EQ_Character::GetClassACBonus(int),EQ_Character__GetClassACBonus);
#endif
#ifdef EQ_Character__ac
FUNCTION_AT_ADDRESS(int  EQ_Character::ac(bool),EQ_Character__ac);
#endif
#ifdef EQ_Character__compute_tohit
FUNCTION_AT_ADDRESS(int  EQ_Character::compute_tohit(unsigned char),EQ_Character__compute_tohit);
#endif
#ifdef EQ_Character__defense_agility_bonus
FUNCTION_AT_ADDRESS(int  EQ_Character::defense_agility_bonus(void),EQ_Character__defense_agility_bonus);
#endif
#ifdef EQ_Character__compute_defense
FUNCTION_AT_ADDRESS(int  EQ_Character::compute_defense(void),EQ_Character__compute_defense);
#endif
#ifdef EQ_Character__offense
FUNCTION_AT_ADDRESS(int  EQ_Character::offense(unsigned char),EQ_Character__offense);
#endif
#ifdef EQ_Character__HasSkill
FUNCTION_AT_ADDRESS(int  EQ_Character::HasSkill(unsigned char),EQ_Character__HasSkill);
#endif
#ifdef EQ_Character__HasInnateSkill
FUNCTION_AT_ADDRESS(int  EQ_Character::HasInnateSkill(unsigned char,int),EQ_Character__HasInnateSkill);
#endif
#ifdef EQ_Character__InitMyLanguages
FUNCTION_AT_ADDRESS(void  EQ_Character::InitMyLanguages(void),EQ_Character__InitMyLanguages);
#endif
#ifdef EQ_Character__BaneDamage
FUNCTION_AT_ADDRESS(int  EQ_Character::BaneDamage(class EQ_Equipment *),EQ_Character__BaneDamage);
#endif
#ifdef EQ_Character__ElementResistDmg
FUNCTION_AT_ADDRESS(int  EQ_Character::ElementResistDmg(class EQ_Equipment *,int),EQ_Character__ElementResistDmg);
#endif
#ifdef EQ_Character__save_bash
FUNCTION_AT_ADDRESS(int  EQ_Character::save_bash(int),EQ_Character__save_bash);
#endif
#ifdef EQ_Character__CapStat
FUNCTION_AT_ADDRESS(int  EQ_Character::CapStat(int,int),EQ_Character__CapStat);
#endif
#ifdef EQ_Character__CalcFoodDrinkBonus
FUNCTION_AT_ADDRESS(void  EQ_Character::CalcFoodDrinkBonus(int),EQ_Character__CalcFoodDrinkBonus);
#endif
#ifdef EQ_Character__basesave_magic
FUNCTION_AT_ADDRESS(int  EQ_Character::basesave_magic(void),EQ_Character__basesave_magic);
#endif
#ifdef EQ_Character__save_magic
FUNCTION_AT_ADDRESS(int  EQ_Character::save_magic(void),EQ_Character__save_magic);
#endif
#ifdef EQ_Character__basesave_fire
FUNCTION_AT_ADDRESS(int  EQ_Character::basesave_fire(void),EQ_Character__basesave_fire);
#endif
#ifdef EQ_Character__save_fire
FUNCTION_AT_ADDRESS(int  EQ_Character::save_fire(void),EQ_Character__save_fire);
#endif
#ifdef EQ_Character__basesave_cold
FUNCTION_AT_ADDRESS(int  EQ_Character::basesave_cold(void),EQ_Character__basesave_cold);
#endif
#ifdef EQ_Character__save_cold
FUNCTION_AT_ADDRESS(int  EQ_Character::save_cold(void),EQ_Character__save_cold);
#endif
#ifdef EQ_Character__basesave_disease
FUNCTION_AT_ADDRESS(int  EQ_Character::basesave_disease(void),EQ_Character__basesave_disease);
#endif
#ifdef EQ_Character__save_disease
FUNCTION_AT_ADDRESS(int  EQ_Character::save_disease(void),EQ_Character__save_disease);
#endif
#ifdef EQ_Character__basesave_poison
FUNCTION_AT_ADDRESS(int  EQ_Character::basesave_poison(void),EQ_Character__basesave_poison);
#endif
#ifdef EQ_Character__save_poison
FUNCTION_AT_ADDRESS(int  EQ_Character::save_poison(void),EQ_Character__save_poison);
#endif
#ifdef EQ_Character__Str
FUNCTION_AT_ADDRESS(int  EQ_Character::Str(void),EQ_Character__Str);
#endif
#ifdef EQ_Character__Sta
FUNCTION_AT_ADDRESS(int  EQ_Character::Sta(void),EQ_Character__Sta);
#endif
#ifdef EQ_Character__Cha
FUNCTION_AT_ADDRESS(int  EQ_Character::Cha(void),EQ_Character__Cha);
#endif
#ifdef EQ_Character__Dex
FUNCTION_AT_ADDRESS(int  EQ_Character::Dex(void),EQ_Character__Dex);
#endif
#ifdef EQ_Character__Int
FUNCTION_AT_ADDRESS(int  EQ_Character::Int(void),EQ_Character__Int);
#endif
#ifdef EQ_Character__Agi
FUNCTION_AT_ADDRESS(int  EQ_Character::Agi(void),EQ_Character__Agi);
#endif
#ifdef EQ_Character__Wis
FUNCTION_AT_ADDRESS(int  EQ_Character::Wis(void),EQ_Character__Wis);
#endif
#ifdef EQ_Character__ApplyFatigue
FUNCTION_AT_ADDRESS(int  EQ_Character::ApplyFatigue(int),EQ_Character__ApplyFatigue);
#endif
#ifdef EQ_Character__max_encumbrance
FUNCTION_AT_ADDRESS(int  EQ_Character::max_encumbrance(void),EQ_Character__max_encumbrance);
#endif
#ifdef EQ_Character__CanUseItem
FUNCTION_AT_ADDRESS(int  EQ_Character::CanUseItem(class EQ_Item *),EQ_Character__CanUseItem);
#endif
#ifdef EQ_Character__encum_factor
FUNCTION_AT_ADDRESS(float  EQ_Character::encum_factor(void),EQ_Character__encum_factor);
#endif
#ifdef EQ_Character__cur_encumbrance
FUNCTION_AT_ADDRESS(int  EQ_Character::cur_encumbrance(void),EQ_Character__cur_encumbrance);
#endif
#ifdef EQ_Character__Race
FUNCTION_AT_ADDRESS(char *  EQ_Character::Race(int),EQ_Character__Race);
#endif
#ifdef EQ_Character__Class
FUNCTION_AT_ADDRESS(char *  EQ_Character::Class(int),EQ_Character__Class);
#endif
#ifdef EQ_Character__KunarkClass
FUNCTION_AT_ADDRESS(char *  EQ_Character::KunarkClass(int,int,int,bool),EQ_Character__KunarkClass);
#endif
#ifdef EQ_Character__ClassMin
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::ClassMin(int,int,unsigned char),EQ_Character__ClassMin);
#endif
#ifdef EQ_Character__CheckClass
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CheckClass(int,int),EQ_Character__CheckClass);
#endif
#ifdef EQ_Character__CanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CanWorship(int,int,unsigned char),EQ_Character__CanWorship);
#endif
#ifdef EQ_Character__HumanCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::HumanCanWorship(unsigned char,unsigned char),EQ_Character__HumanCanWorship);
#endif
#ifdef EQ_Character__BarbarianCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::BarbarianCanWorship(unsigned char,unsigned char),EQ_Character__BarbarianCanWorship);
#endif
#ifdef EQ_Character__EruditeCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::EruditeCanWorship(unsigned char,unsigned char),EQ_Character__EruditeCanWorship);
#endif
#ifdef EQ_Character__ElfCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::ElfCanWorship(unsigned char,unsigned char),EQ_Character__ElfCanWorship);
#endif
#ifdef EQ_Character__HighElfCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::HighElfCanWorship(unsigned char,unsigned char),EQ_Character__HighElfCanWorship);
#endif
#ifdef EQ_Character__DarkElfCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::DarkElfCanWorship(unsigned char,unsigned char),EQ_Character__DarkElfCanWorship);
#endif
#ifdef EQ_Character__HalfElfCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::HalfElfCanWorship(unsigned char,unsigned char),EQ_Character__HalfElfCanWorship);
#endif
#ifdef EQ_Character__DwarfCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::DwarfCanWorship(unsigned char,unsigned char),EQ_Character__DwarfCanWorship);
#endif
#ifdef EQ_Character__TrollCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::TrollCanWorship(unsigned char,unsigned char),EQ_Character__TrollCanWorship);
#endif
#ifdef EQ_Character__OgreCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::OgreCanWorship(unsigned char,unsigned char),EQ_Character__OgreCanWorship);
#endif
#ifdef EQ_Character__HalflingCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::HalflingCanWorship(unsigned char,unsigned char),EQ_Character__HalflingCanWorship);
#endif
#ifdef EQ_Character__GnomeCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::GnomeCanWorship(unsigned char,unsigned char),EQ_Character__GnomeCanWorship);
#endif
#ifdef EQ_Character__IksarCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::IksarCanWorship(unsigned char,unsigned char),EQ_Character__IksarCanWorship);
#endif
#ifdef EQ_Character__VahShirCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::VahShirCanWorship(unsigned char,unsigned char),EQ_Character__VahShirCanWorship);
#endif
#ifdef EQ_Character__FroglockCanWorship
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::FroglockCanWorship(unsigned char,unsigned char),EQ_Character__FroglockCanWorship);
#endif
#ifdef EQ_Character__CityCanStart
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CityCanStart(int,int,int,int),EQ_Character__CityCanStart);
#endif
#ifdef EQ_Character__BaseAttr
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::BaseAttr(int,unsigned char),EQ_Character__BaseAttr);
#endif
#ifdef EQ_Character__InitSkills
FUNCTION_AT_ADDRESS(void  EQ_Character::InitSkills(unsigned char,unsigned int),EQ_Character__InitSkills);
#endif
#ifdef EQ_Character__InitInnates
FUNCTION_AT_ADDRESS(void  EQ_Character::InitInnates(unsigned int,unsigned int),EQ_Character__InitInnates);
#endif
#ifdef EQ_Character__IsSpecialBazaarSpot
FUNCTION_AT_ADDRESS(int  EQ_Character::IsSpecialBazaarSpot(class EQPlayer *),EQ_Character__IsSpecialBazaarSpot);
#endif
#ifdef EQ_Character__CanSecondaryAttack
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CanSecondaryAttack(class EQPlayer *),EQ_Character__CanSecondaryAttack);
#endif
#ifdef EQ_Character__CanDoubleAttack
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CanDoubleAttack(class EQPlayer *,unsigned char),EQ_Character__CanDoubleAttack);
#endif
#ifdef EQ_Character__AntiTwinkAdj
FUNCTION_AT_ADDRESS(int  EQ_Character::AntiTwinkAdj(class EQ_Equipment *,int,int),EQ_Character__AntiTwinkAdj);
#endif
#ifdef EQ_Character__GetSkillBaseDamage
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::GetSkillBaseDamage(unsigned char,class EQPlayer *),EQ_Character__GetSkillBaseDamage);
#endif
#ifdef EQ_Character__UseSkill
FUNCTION_AT_ADDRESS(void  EQ_Character1::UseSkill(unsigned char,class EQPlayer *),EQ_Character__UseSkill);
#endif
#ifdef EQ_Character__DoIntimidationEvent
FUNCTION_AT_ADDRESS(void  EQ_Character::DoIntimidationEvent(void),EQ_Character__DoIntimidationEvent);
#endif
#ifdef EQ_Character__DoFishingEvent
FUNCTION_AT_ADDRESS(void  EQ_Character::DoFishingEvent(void),EQ_Character__DoFishingEvent);
#endif
#ifdef EQ_Character__FindClosest
FUNCTION_AT_ADDRESS(class EQPlayer *  EQ_Character::FindClosest(int,int,int,int,int),EQ_Character__FindClosest);
#endif
#ifdef EQ_Character__IAmDead
FUNCTION_AT_ADDRESS(void  EQ_Character::IAmDead(struct _EQMissileHitinfo *,int),EQ_Character__IAmDead);
#endif
#ifdef EQ_Character__TotalOnPerson
FUNCTION_AT_ADDRESS(long  EQ_Character::TotalOnPerson(void),EQ_Character__TotalOnPerson);
#endif
#ifdef EQ_Character__ItemSold
FUNCTION_AT_ADDRESS(void  EQ_Character::ItemSold(long),EQ_Character__ItemSold);
#endif
#ifdef EQ_Character__TakeFallDamage
FUNCTION_AT_ADDRESS(int  EQ_Character::TakeFallDamage(float),EQ_Character__TakeFallDamage);
#endif
#ifdef EQ_Character__IHaveSkill
FUNCTION_AT_ADDRESS(int  EQ_Character::IHaveSkill(unsigned char),EQ_Character__IHaveSkill);
#endif
#ifdef EQ_Character__NoMezMe
FUNCTION_AT_ADDRESS(int  EQ_Character::NoMezMe(int,class EQPlayer *,class EQ_Spell *),EQ_Character__NoMezMe);
#endif
#ifdef EQ_Character__NoBashMe
FUNCTION_AT_ADDRESS(int  EQ_Character::NoBashMe(int),EQ_Character__NoBashMe);
#endif
#ifdef EQ_Character__StunMe
FUNCTION_AT_ADDRESS(void  EQ_Character1::StunMe(unsigned int,unsigned int,unsigned int),EQ_Character__StunMe);
#endif
#ifdef EQ_Character__UnStunMe
FUNCTION_AT_ADDRESS(void  EQ_Character1::UnStunMe(void),EQ_Character__UnStunMe);
#endif
#ifdef EQ_Character__ApplyDamage
FUNCTION_AT_ADDRESS(int  EQ_Character::ApplyDamage(int,struct _EQMissileHitinfo *,bool,class HateListEntry *,bool),EQ_Character__ApplyDamage);
#endif
#ifdef EQ_Character__NotifyPCAffectChange
FUNCTION_AT_ADDRESS(void  EQ_Character::NotifyPCAffectChange(int,int),EQ_Character__NotifyPCAffectChange);
#endif
#ifdef EQ_Character__MakeMeVisible
FUNCTION_AT_ADDRESS(void  EQ_Character::MakeMeVisible(int),EQ_Character__MakeMeVisible);
#endif
#ifdef EQ_Character__UpdateMyVisibleStatus
FUNCTION_AT_ADDRESS(void  EQ_Character::UpdateMyVisibleStatus(void),EQ_Character__UpdateMyVisibleStatus);
#endif
#ifdef EQ_Character__CanISeeInvis
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CanISeeInvis(void),EQ_Character__CanISeeInvis);
#endif
#ifdef EQ_Character__CanIBreathe
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CanIBreathe(void),EQ_Character__CanIBreathe);
#endif
#ifdef EQ_Character__ProcessEnvironment
FUNCTION_AT_ADDRESS(void  EQ_Character::ProcessEnvironment(void),EQ_Character__ProcessEnvironment);
#endif
#ifdef EQ_Character__ProcessHungerandThirst
FUNCTION_AT_ADDRESS(void  EQ_Character::ProcessHungerandThirst(unsigned int),EQ_Character__ProcessHungerandThirst);
#endif
#ifdef EQ_Character__ItemSpellAffects
FUNCTION_AT_ADDRESS(int  EQ_Character::ItemSpellAffects(int),EQ_Character__ItemSpellAffects);
#endif
#ifdef EQ_Character__ProcessAllStats
FUNCTION_AT_ADDRESS(void  EQ_Character::ProcessAllStats(void),EQ_Character__ProcessAllStats);
#endif
#ifdef EQ_Character__DoPassageOfTime
FUNCTION_AT_ADDRESS(void  EQ_Character::DoPassageOfTime(void),EQ_Character__DoPassageOfTime);
#endif
#ifdef EQ_Character__FindItemByClass
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::FindItemByClass(int,int *,int *),EQ_Character__FindItemByClass);
#endif
#ifdef EQ_Character__FindItemByRecord
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::FindItemByRecord(int,int *,int *),EQ_Character__FindItemByRecord);
#endif
#ifdef EQ_Character__FindItemQty
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::FindItemQty(int,int),EQ_Character__FindItemQty);
#endif
#ifdef EQ_Character__CanMedOnHorse
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CanMedOnHorse(void),EQ_Character__CanMedOnHorse);
#endif
#ifdef EQ_Character__ExpendItemCharge
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::ExpendItemCharge(int,int),EQ_Character__ExpendItemCharge);
#endif
#ifdef EQ_Character__AutoEat
FUNCTION_AT_ADDRESS(int  EQ_Character::AutoEat(unsigned char),EQ_Character__AutoEat);
#endif
#ifdef EQ_Character__CheckFoodAndWater
FUNCTION_AT_ADDRESS(int  EQ_Character::CheckFoodAndWater(void),EQ_Character__CheckFoodAndWater);
#endif
#ifdef EQ_Character__DoMeditation
FUNCTION_AT_ADDRESS(void  EQ_Character::DoMeditation(void),EQ_Character__DoMeditation);
#endif
#ifdef EQ_Character__SetLocalVar
FUNCTION_AT_ADDRESS(int  EQ_Character::SetLocalVar(char *,int),EQ_Character__SetLocalVar);
#endif
#ifdef EQ_Character__GetIndexSkillMinDamageMod
FUNCTION_AT_ADDRESS(int  EQ_Character::GetIndexSkillMinDamageMod(int),EQ_Character__GetIndexSkillMinDamageMod);
#endif
#ifdef EQ_Character__GetFocusConserveRegChance
FUNCTION_AT_ADDRESS(int const  EQ_Character::GetFocusConserveRegChance(class EQ_Spell const *,class EQ_Equipment * *),EQ_Character__GetFocusConserveRegChance);
#endif
#ifdef EQ_Character__GetFocusCastingTimeModifier
FUNCTION_AT_ADDRESS(int const  EQ_Character1::GetFocusCastingTimeModifier(class EQ_Spell const *,class EQ_Equipment * *, int),EQ_Character__GetFocusCastingTimeModifier);
#endif
#ifdef EQ_Character__GetFocusRangeModifier
FUNCTION_AT_ADDRESS(int const  EQ_Character1::GetFocusRangeModifier(class EQ_Spell const *,class EQ_Equipment * *),EQ_Character__GetFocusRangeModifier);
#endif
#ifdef EQ_Character__GetFocusItem
FUNCTION_AT_ADDRESS(class EQ_Equipment *  EQ_Character::GetFocusItem(class EQ_Spell const *,int),EQ_Character__GetFocusItem);
#endif
#ifdef EQ_Character__GetFocusEffect
FUNCTION_AT_ADDRESS(class EQ_Spell *  EQ_Character::GetFocusEffect(class EQ_Spell const *,int),EQ_Character__GetFocusEffect);
#endif
#ifdef EQ_Character__DoesSpellMatchFocusFilters
FUNCTION_AT_ADDRESS(bool  EQ_Character::DoesSpellMatchFocusFilters(class EQ_Spell const *,class EQ_Spell const *),EQ_Character__DoesSpellMatchFocusFilters);
#endif
#ifdef EQ_Character__GetMyPetPlayer
FUNCTION_AT_ADDRESS(class EQPlayer *  EQ_Character::GetMyPetPlayer(void),EQ_Character__GetMyPetPlayer);
#endif
#ifdef EQ_Character__GetMaxEffects
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::GetMaxEffects(void)const ,EQ_Character__GetMaxEffects);
#endif
#ifdef EQ_Character__GetEffect
FUNCTION_AT_ADDRESS(class EQ_Affect &  EQ_Character::GetEffect(int),EQ_Character__GetEffect);
#endif
#ifdef EQ_Character__GetEffectId
FUNCTION_AT_ADDRESS(unsigned int EQ_Character::GetEffectId(int),EQ_Character__GetEffectId);
#endif
#ifdef EQ_Character__SetEffectId
FUNCTION_AT_ADDRESS(void  EQ_Character1::SetEffectId(unsigned char,unsigned int),EQ_Character__SetEffectId);
#endif
#ifdef EQ_Character__CastSpell
FUNCTION_AT_ADDRESS(unsigned char EQ_Character1::CastSpell(unsigned char gemid,int spellid,class EQ_Item * *ppItem,int,int slot,int,int,int,int,bool,int),EQ_Character__CastSpell); 
#endif
#ifdef EQ_Character__GetBardInstrumentMod
FUNCTION_AT_ADDRESS(int  EQ_Character::GetBardInstrumentMod(int),EQ_Character__GetBardInstrumentMod);
#endif
#ifdef EQ_Character__CalculateBardSongMod
FUNCTION_AT_ADDRESS(int  EQ_Character::CalculateBardSongMod(int),EQ_Character__CalculateBardSongMod);
#endif
#ifdef EQ_Character__CastingRequirementsMet
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::CastingRequirementsMet(int),EQ_Character__CastingRequirementsMet);
#endif
#ifdef EQ_Character__GetAACastingTimeModifier
FUNCTION_AT_ADDRESS(int const  EQ_Character1::GetAACastingTimeModifier(class EQ_Spell const *),EQ_Character__GetAACastingTimeModifier);
#endif
#ifdef EQ_Character__BardCastBard
FUNCTION_AT_ADDRESS(int  EQ_Character::BardCastBard(class EQ_Spell const *,int)const ,EQ_Character__BardCastBard);
#endif
#ifdef EQ_Character__IsValidAffect
FUNCTION_AT_ADDRESS(bool  EQ_Character::IsValidAffect(int),EQ_Character__IsValidAffect);
#endif
#ifdef EQ_Character__LaunchSpell
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::LaunchSpell(unsigned char,int,class EQ_Item * *),EQ_Character__LaunchSpell);
#endif
#ifdef EQ_Character__HandleSpecialPCAffects
FUNCTION_AT_ADDRESS(void  EQ_Character::HandleSpecialPCAffects(int),EQ_Character__HandleSpecialPCAffects);
#endif
#ifdef EQ_Character__CalcAffectChange
FUNCTION_AT_ADDRESS(int  EQ_Character::CalcAffectChange(class EQ_Spell *,unsigned char,unsigned char,class EQ_Affect *),EQ_Character__CalcAffectChange);
#endif
#ifdef EQ_Character__GetPCSpellAffect
FUNCTION_AT_ADDRESS(class EQ_Affect *  EQ_Character::GetPCSpellAffect(unsigned char,int *),EQ_Character__GetPCSpellAffect);
#endif
#ifdef EQ_Character__TotalSpellAffects
FUNCTION_AT_ADDRESS(int  EQ_Character::TotalSpellAffects(unsigned char,bool,int *),EQ_Character__TotalSpellAffects);
#endif
#ifdef EQ_Character__IsSpellAffectingPC
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::IsSpellAffectingPC(int),EQ_Character__IsSpellAffectingPC);
#endif
#ifdef EQ_Character__SpellFizzled
FUNCTION_AT_ADDRESS(unsigned char  EQ_Character::SpellFizzled(unsigned char,class EQ_Spell *),EQ_Character__SpellFizzled);
#endif
#ifdef EQ_Character__ProcessAffects
FUNCTION_AT_ADDRESS(int  EQ_Character::ProcessAffects(void),EQ_Character__ProcessAffects);
#endif
#ifdef EQ_Character__FindAffectSlot
FUNCTION_AT_ADDRESS(class EQ_Affect *  EQ_Character::FindAffectSlot(int,class EQPlayer *,int *,int),EQ_Character__FindAffectSlot);
#endif
#ifdef EQ_Character__GetOpenEffectSlot
FUNCTION_AT_ADDRESS(int  EQ_Character::GetOpenEffectSlot(bool,int),EQ_Character__GetOpenEffectSlot);
#endif
#ifdef EQ_Character__GetFirstEffectSlot
FUNCTION_AT_ADDRESS(int  EQ_Character::GetFirstEffectSlot(bool),EQ_Character__GetFirstEffectSlot);
#endif
#ifdef EQ_Character__GetLastEffectSlot
FUNCTION_AT_ADDRESS(int  EQ_Character::GetLastEffectSlot(bool),EQ_Character__GetLastEffectSlot);
#endif
#ifdef EQ_Character__IsStackBlocked
FUNCTION_AT_ADDRESS(bool  EQ_Character::IsStackBlocked(class EQ_Spell const *),EQ_Character__IsStackBlocked);
#endif
#ifdef EQ_Character__IsSpellTooPowerfull
FUNCTION_AT_ADDRESS(bool  EQ_Character::IsSpellTooPowerfull(class EQ_Spell *,class EQ_Character *),EQ_Character__IsSpellTooPowerfull);
#endif
#ifdef EQ_Character__HitBySpell
FUNCTION_AT_ADDRESS(void  EQ_Character::HitBySpell(struct _EQMissileHitinfo *),EQ_Character__HitBySpell);
#endif
#ifdef EQ_Spell__IsStackableDot
FUNCTION_AT_ADDRESS(bool  EQ_Spell::IsStackableDot(void)const ,EQ_Spell__IsStackableDot);
#endif
#ifdef EQ_Character__EQSPA_Feign_Death
FUNCTION_AT_ADDRESS(void  EQ_Character::EQSPA_Feign_Death(int),EQ_Character__EQSPA_Feign_Death);
#endif
#ifdef EQ_Character__SpellDuration
FUNCTION_AT_ADDRESS(int  EQ_Character::SpellDuration(class EQ_Spell const *,unsigned char,unsigned char),EQ_Character__SpellDuration);
#endif
#ifdef EQ_Character__eqspa_change_form
FUNCTION_AT_ADDRESS(int  EQ_Character::eqspa_change_form(class EQ_Spell *,int,int,class EQ_Affect *),EQ_Character__eqspa_change_form);
#endif
#ifdef EQ_Character__eqspa_movement_rate
FUNCTION_AT_ADDRESS(void  EQ_Character::eqspa_movement_rate(int),EQ_Character__eqspa_movement_rate);
#endif
#ifdef EQ_Character__eqspa_levitation
FUNCTION_AT_ADDRESS(void  EQ_Character::eqspa_levitation(void),EQ_Character__eqspa_levitation);
#endif
#ifdef EQ_Character__eqspa_hp
FUNCTION_AT_ADDRESS(int  EQ_Character::eqspa_hp(unsigned int,class EQ_Affect *,int,class EQ_Spell *),EQ_Character__eqspa_hp);
#endif
#ifdef EQ_Character__eqspa_locate_corpse
FUNCTION_AT_ADDRESS(void  EQ_Character::eqspa_locate_corpse(void),EQ_Character__eqspa_locate_corpse);
#endif
#ifdef EQ_Character__InSpecialBindSpot
FUNCTION_AT_ADDRESS(int  EQ_Character::InSpecialBindSpot(class EQPlayer *),EQ_Character__InSpecialBindSpot);
#endif
#ifdef EQ_Character__RemovePCAffect
FUNCTION_AT_ADDRESS(void  EQ_Character::RemovePCAffect(class EQ_Affect *),EQ_Character__RemovePCAffect);
#endif
#ifdef EQ_Character__RemovePCAffectex
FUNCTION_AT_ADDRESS(void  EQ_Character::RemovePCAffectex(class EQ_Affect *,int),EQ_Character__RemovePCAffectex);
#endif
#ifdef EQ_Character__StopSpellCast
FUNCTION_AT_ADDRESS(void  EQ_Character1::StopSpellCast(unsigned char),EQ_Character__StopSpellCast);
#endif
#ifdef EQ_Character__StopSpellCast1
FUNCTION_AT_ADDRESS(void  EQ_Character1::StopSpellCast(unsigned char,int),EQ_Character__StopSpellCast1);
#endif
#ifdef EQ_Character__ReCachSpellEffects
FUNCTION_AT_ADDRESS(void  EQ_Character::ReCachSpellEffects(void),EQ_Character__ReCachSpellEffects);
#endif
#ifdef EQ_Character__ReCachItemEffects
FUNCTION_AT_ADDRESS(void  EQ_Character::ReCachItemEffects(void),EQ_Character__ReCachItemEffects);
#endif
#ifdef EQ_Character__GetCachEQSPA
FUNCTION_AT_ADDRESS(int  EQ_Character::GetCachEQSPA(int),EQ_Character__GetCachEQSPA);
#endif
#ifdef EQ_Character__GetConLevel
FUNCTION_AT_ADDRESS(unsigned long EQ_Character::GetConLevel(class EQPlayer *),EQ_Character__GetConLevel);
#endif
#ifdef EQ_Container__EQ_Container
FUNCTION_AT_ADDRESS( EQ_Container::EQ_Container(void),EQ_Container__EQ_Container);
#endif
#ifdef EQ_Container__dEQ_Container
FUNCTION_AT_ADDRESS( EQ_Container::~EQ_Container(void),EQ_Container__dEQ_Container);
#endif
#ifdef EQ_Container__Open
FUNCTION_AT_ADDRESS(unsigned char  EQ_Container::Open(void),EQ_Container__Open);
#endif
#ifdef EQ_Container__Close
FUNCTION_AT_ADDRESS(unsigned char  EQ_Container::Close(void),EQ_Container__Close);
#endif
#ifdef EQ_Container__IsOpen
FUNCTION_AT_ADDRESS(unsigned char  EQ_Container::IsOpen(void),EQ_Container__IsOpen);
#endif
#ifdef EQ_Equipment__EQ_Equipment
FUNCTION_AT_ADDRESS( EQ_Equipment::EQ_Equipment(void),EQ_Equipment__EQ_Equipment);
#endif
#ifdef EQ_Equipment__IsWeapon
FUNCTION_AT_ADDRESS(int  EQ_Equipment::IsWeapon(void),EQ_Equipment__IsWeapon);
#endif
#ifdef EQ_Equipment__IsInstrument
FUNCTION_AT_ADDRESS(int  EQ_Equipment::IsInstrument(void),EQ_Equipment__IsInstrument);
#endif
#ifdef EQ_Equipment__SendTextRequestMsg
FUNCTION_AT_ADDRESS(void  EQ_Equipment::SendTextRequestMsg(void),EQ_Equipment__SendTextRequestMsg);
#endif
#ifdef EQ_Item__Platinum
FUNCTION_AT_ADDRESS(int  EQ_Item::Platinum(void),EQ_Item__Platinum);
#endif
#ifdef EQ_Item__Gold
FUNCTION_AT_ADDRESS(int  EQ_Item::Gold(void),EQ_Item__Gold);
#endif
#ifdef EQ_Item__Silver
FUNCTION_AT_ADDRESS(int  EQ_Item::Silver(void),EQ_Item__Silver);
#endif
#ifdef EQ_Item__Copper
FUNCTION_AT_ADDRESS(int  EQ_Item::Copper(void),EQ_Item__Copper);
#endif
#ifdef EQ_Item__ValueSellMerchant
FUNCTION_AT_ADDRESS(long  EQ_Item::ValueSellMerchant(float,long),EQ_Item__ValueSellMerchant);
#endif
#ifdef EQ_Item__ValueSSell
FUNCTION_AT_ADDRESS(char *  EQ_Item::ValueSSell(float,long),EQ_Item__ValueSSell);
#endif
#ifdef EQ_Item__ValueSBuy
FUNCTION_AT_ADDRESS(char *  EQ_Item::ValueSBuy(float,long),EQ_Item__ValueSBuy);
#endif
#ifdef EQ_Item__ValueSRent
FUNCTION_AT_ADDRESS(char *  EQ_Item::ValueSRent(void),EQ_Item__ValueSRent);
#endif
#ifdef EQ_Item__IsSpecialNoDrop
FUNCTION_AT_ADDRESS(bool  EQ_Item::IsSpecialNoDrop(void),EQ_Item__IsSpecialNoDrop);
#endif
#ifdef EQ_Item__IsStackable 
FUNCTION_AT_ADDRESS(bool  EQ_Item::IsStackable(void),EQ_Item__IsStackable); 
#endif 
#ifdef EQ_LoadingS__EQ_LoadingS
FUNCTION_AT_ADDRESS( EQ_LoadingS::EQ_LoadingS(void),EQ_LoadingS__EQ_LoadingS);
#endif
#ifdef EQ_LoadingS__dEQ_LoadingS
FUNCTION_AT_ADDRESS( EQ_LoadingS::~EQ_LoadingS(void),EQ_LoadingS__dEQ_LoadingS);
#endif
#ifdef EQ_LoadingS__DrawBackground
FUNCTION_AT_ADDRESS(void  EQ_LoadingS::DrawBackground(struct T3D_XYZ *),EQ_LoadingS__DrawBackground);
#endif
#ifdef EQ_LoadingS__draw
FUNCTION_AT_ADDRESS(void  EQ_LoadingS::draw(void),EQ_LoadingS__draw);
#endif
#ifdef EQ_LoadingS__WriteTextHD
FUNCTION_AT_ADDRESS(void  EQ_LoadingS::WriteTextHD(char *,int,int,int),EQ_LoadingS__WriteTextHD);
#endif
#ifdef EQ_LoadingS__SetProgressBar
FUNCTION_AT_ADDRESS(void  EQ_LoadingS::SetProgressBar(int,char const *),EQ_LoadingS__SetProgressBar);
#endif
#ifdef EQ_Note__EQ_Note
FUNCTION_AT_ADDRESS( EQ_Note::EQ_Note(void),EQ_Note__EQ_Note);
#endif
#ifdef EQ_Note__SendTextRequestMsg
FUNCTION_AT_ADDRESS(void  EQ_Note::SendTextRequestMsg(void),EQ_Note__SendTextRequestMsg);
#endif
#ifdef EQ_PC__EQ_PC
FUNCTION_AT_ADDRESS( EQ_PC::EQ_PC(class EQ_PC *),EQ_PC__EQ_PC);
#endif
#ifdef EQ_PC__dEQ_PC
FUNCTION_AT_ADDRESS( EQ_PC::~EQ_PC(void),EQ_PC__dEQ_PC);
#endif
#ifdef EQ_PC__ClearSharedVault
FUNCTION_AT_ADDRESS(void  EQ_PC::ClearSharedVault(void),EQ_PC__ClearSharedVault);
#endif
#ifdef EQ_PC__IsAGroupMember
FUNCTION_AT_ADDRESS(int  EQ_PC::IsAGroupMember(char *),EQ_PC__IsAGroupMember);
#endif
#ifdef EQ_PC__CheckForGroupChanges
FUNCTION_AT_ADDRESS(void  EQ_PC::CheckForGroupChanges(void),EQ_PC__CheckForGroupChanges);
#endif
#ifdef EQ_PC__UnpackMyNetPC
FUNCTION_AT_ADDRESS(void  EQ_PC::UnpackMyNetPC(char *,int),EQ_PC__UnpackMyNetPC);
#endif
#ifdef EQ_PC__InitPlayerStart
FUNCTION_AT_ADDRESS(void  EQ_PC::InitPlayerStart(unsigned int,unsigned char,int),EQ_PC__InitPlayerStart);
#endif
#ifdef EQ_PC__EmptyPossessionSlots
FUNCTION_AT_ADDRESS(void  EQ_PC::EmptyPossessionSlots(void),EQ_PC__EmptyPossessionSlots);
#endif
#ifdef EQ_PC__RefreshMe
FUNCTION_AT_ADDRESS(void  EQ_PC::RefreshMe(int),EQ_PC__RefreshMe);
#endif
#ifdef EQ_PC__PrepareForRepop
FUNCTION_AT_ADDRESS(void  EQ_PC::PrepareForRepop(int),EQ_PC__PrepareForRepop);
#endif
#ifdef EQ_PC__RefitNewbieEQ
FUNCTION_AT_ADDRESS(void  EQ_PC::RefitNewbieEQ(void),EQ_PC__RefitNewbieEQ);
#endif
#ifdef EQ_PC__RemoveMyAffect
FUNCTION_AT_ADDRESS(unsigned char  EQ_PC::RemoveMyAffect(int),EQ_PC__RemoveMyAffect);
#endif
#ifdef EQ_PC__ProcessFatigue
FUNCTION_AT_ADDRESS(void  EQ_PC::ProcessFatigue(void),EQ_PC__ProcessFatigue);
#endif
#ifdef EQ_PC__DelLoreItemDup
FUNCTION_AT_ADDRESS(int  EQ_PC::DelLoreItemDup(int,int,int,class EQ_Item *),EQ_PC__DelLoreItemDup);
#endif
#ifdef EQ_PC__CheckDupLoreItems
FUNCTION_AT_ADDRESS(int  EQ_PC::CheckDupLoreItems(void),EQ_PC__CheckDupLoreItems);
#endif
#ifdef EQ_PC__CostToTrain
FUNCTION_AT_ADDRESS(int  EQ_PC::CostToTrain(int,float,int),EQ_PC__CostToTrain);
#endif
#ifdef EQ_PC__checkLang
FUNCTION_AT_ADDRESS(int  EQ_PC::checkLang(int),EQ_PC__checkLang);
#endif
#ifdef EQ_PC__BitchCanTrain
FUNCTION_AT_ADDRESS(int  EQ_PC::BitchCanTrain(int,int,int),EQ_PC__BitchCanTrain);
#endif
#ifdef EQ_PC__HandleMoney
FUNCTION_AT_ADDRESS(int  EQ_PC::HandleMoney(long),EQ_PC__HandleMoney);
#endif
#ifdef EQ_PC__DetermineQuestExpGained
FUNCTION_AT_ADDRESS(void  EQ_PC::DetermineQuestExpGained(int),EQ_PC__DetermineQuestExpGained);
#endif
#ifdef EQ_PC__ProcessAirSupply
FUNCTION_AT_ADDRESS(void  EQ_PC::ProcessAirSupply(void),EQ_PC__ProcessAirSupply);
#endif
#ifdef EQ_PC__MaxAirSupply
FUNCTION_AT_ADDRESS(int  EQ_PC::MaxAirSupply(void),EQ_PC__MaxAirSupply);
#endif
#ifdef EQ_PC__SetFatigue
FUNCTION_AT_ADDRESS(void  EQ_PC::SetFatigue(int),EQ_PC__SetFatigue);
#endif
#ifdef EQ_PC__numInParty
FUNCTION_AT_ADDRESS(int  EQ_PC::numInParty(void),EQ_PC__numInParty);
#endif
#ifdef EQ_PC__AtSkillLimit
FUNCTION_AT_ADDRESS(unsigned char  EQ_PC::AtSkillLimit(int),EQ_PC__AtSkillLimit);
#endif
#ifdef EQ_PC__GetItemTimerValue
FUNCTION_AT_ADDRESS(unsigned long  EQ_PC::GetItemTimerValue(class EQ_Item *),EQ_PC__GetItemTimerValue);
#endif
#ifdef EQ_PC__GetAltAbilityIndex
FUNCTION_AT_ADDRESS(int  EQ_PC::GetAltAbilityIndex(int),EQ_PC__GetAltAbilityIndex);
#endif
#ifdef EQ_PC__GetCombatAbility
FUNCTION_AT_ADDRESS(int  EQ_PC::GetCombatAbility(int),EQ_PC__GetCombatAbility);
#endif
#ifdef EQ_PC__GetCombatAbilityTimer
FUNCTION_AT_ADDRESS(unsigned long  EQ_PC::GetCombatAbilityTimer(int),EQ_PC__GetCombatAbilityTimer);
#endif
#ifdef EQ_PC__HasLoreItem
FUNCTION_AT_ADDRESS(unsigned long  EQ_PC::HasLoreItem(class EQ_Item *),EQ_PC__HasLoreItem);
#endif
#ifdef CInvSlot__HandleLButtonDown
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleLButtonDown(class CXPoint),CInvSlot__HandleLButtonDown);
#endif
#ifdef CInvSlot__HandleLButtonUpAfterHeld
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleLButtonUpAfterHeld(class CXPoint),CInvSlot__HandleLButtonUpAfterHeld);
#endif
#ifdef CInvSlot__HandleRButtonDown
FUNCTION_AT_ADDRESS(void  CInvSlot::HandleRButtonDown(class CXPoint),CInvSlot__HandleRButtonDown);
#endif
#ifdef EQ_PC__CheckForLanguageImprovement
FUNCTION_AT_ADDRESS(void  EQ_PC::CheckForLanguageImprovement(unsigned char,unsigned char),EQ_PC__CheckForLanguageImprovement);
#endif
#ifdef EQ_PC__CheckSkillImprove
FUNCTION_AT_ADDRESS(void  EQ_PC::CheckSkillImprove(int,float),EQ_PC__CheckSkillImprove);
#endif
#ifdef EQ_PC__GetBodyTint
FUNCTION_AT_ADDRESS(unsigned long  EQ_PC::GetBodyTint(int),EQ_PC__GetBodyTint);
#endif
#ifdef EQ_PC__SetAltAbilityIndex
FUNCTION_AT_ADDRESS(void  EQ_PC::SetAltAbilityIndex(int,int),EQ_PC__SetAltAbilityIndex);
#endif
#ifdef EQ_PC__GetArmorTint
FUNCTION_AT_ADDRESS(unsigned long  EQ_PC::GetArmorTint(int),EQ_PC__GetArmorTint);
#endif
#ifdef EQ_PC__SetArmorTint
FUNCTION_AT_ADDRESS(void  EQ_PC::SetArmorTint(int,unsigned long),EQ_PC__SetArmorTint);
#endif
#ifdef EQ_PC__GetArmorType
FUNCTION_AT_ADDRESS(int  EQ_PC::GetArmorType(int),EQ_PC__GetArmorType);
#endif
#ifdef EQ_PC__SetArmorType
FUNCTION_AT_ADDRESS(void  EQ_PC::SetArmorType(int,int),EQ_PC__SetArmorType);
#endif
#ifdef EQ_PC__InitializeNewPCVariables
FUNCTION_AT_ADDRESS(void  EQ_PC::InitializeNewPCVariables(int),EQ_PC__InitializeNewPCVariables);
#endif
#ifdef EQ_PC__DestroyHeldItemOrMoney
FUNCTION_AT_ADDRESS(void  EQ_PC::DestroyHeldItemOrMoney(void),EQ_PC__DestroyHeldItemOrMoney);
#endif
#ifdef EQ_Skill__EQ_Skill
FUNCTION_AT_ADDRESS( EQ_Skill::EQ_Skill(int),EQ_Skill__EQ_Skill);
#endif
#ifdef EqSoundManager__EqSoundManager
//FUNCTION_AT_ADDRESS( EqSoundManager::EqSoundManager(bool,bool,enum SpeakerType),EqSoundManager__EqSoundManager);
#endif
#ifdef EqSoundManager__dEqSoundManager
FUNCTION_AT_ADDRESS( EqSoundManager::~EqSoundManager(void),EqSoundManager__dEqSoundManager);
#endif
#ifdef EqSoundManager__LoadGlobalEmitters
FUNCTION_AT_ADDRESS(void  EqSoundManager::LoadGlobalEmitters(void),EqSoundManager__LoadGlobalEmitters);
#endif
#ifdef EqSoundManager__GetMusicId
FUNCTION_AT_ADDRESS(int  EqSoundManager::GetMusicId(void),EqSoundManager__GetMusicId);
#endif
#ifdef EqSoundManager__LoadGlobalWaves
FUNCTION_AT_ADDRESS(void  EqSoundManager::LoadGlobalWaves(void),EqSoundManager__LoadGlobalWaves);
#endif
#ifdef EqSoundManager__LoadListOfWaveFiles
FUNCTION_AT_ADDRESS(void  EqSoundManager::LoadListOfWaveFiles(char * *,int),EqSoundManager__LoadListOfWaveFiles);
#endif
#ifdef EqSoundManager__WaveLoad
FUNCTION_AT_ADDRESS(void  EqSoundManager::WaveLoad(char *,int,bool),EqSoundManager__WaveLoad);
#endif
#ifdef EqSoundManager__WaveIsPlaying
FUNCTION_AT_ADDRESS(bool  EqSoundManager::WaveIsPlaying(int),EqSoundManager__WaveIsPlaying);
#endif
#ifdef EqSoundManager__WavePlay
FUNCTION_AT_ADDRESS(void  EqSoundManager::WavePlay(int,class SoundControl *),EqSoundManager__WavePlay);
#endif
#ifdef EqSoundManager__WaveStop
FUNCTION_AT_ADDRESS(void  EqSoundManager::WaveStop(int),EqSoundManager__WaveStop);
#endif
#ifdef EqSoundManager__WaveGet
FUNCTION_AT_ADDRESS(class SoundAsset *  EqSoundManager::WaveGet(int),EqSoundManager__WaveGet);
#endif
#ifdef EqSoundManager__LoadGlobalMusic
FUNCTION_AT_ADDRESS(void  EqSoundManager::LoadGlobalMusic(void),EqSoundManager__LoadGlobalMusic);
#endif
#ifdef EqSoundManager__SetMusicSelection
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetMusicSelection(int,bool),EqSoundManager__SetMusicSelection);
#endif
#ifdef EqSoundManager__GiveTime
FUNCTION_AT_ADDRESS(void  EqSoundManager::GiveTime(void),EqSoundManager__GiveTime);
#endif
#ifdef EqSoundManager__SetCurrentZone
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetCurrentZone(char *),EqSoundManager__SetCurrentZone);
#endif
#ifdef FilePath__FilePath
FUNCTION_AT_ADDRESS( FilePath::FilePath(char const *),FilePath__FilePath);
#endif
#ifdef ShareBase__removeRef
FUNCTION_AT_ADDRESS(void  ShareBase::removeRef(void),ShareBase__removeRef);
#endif
#ifdef SharedString__SharedString
FUNCTION_AT_ADDRESS( SharedString::SharedString(char const *),SharedString__SharedString);
#endif
#ifdef SharedString__operator_equal
FUNCTION_AT_ADDRESS(class SharedString &  SharedString::operator=(class SharedString const &),SharedString__operator_equal);
#endif
#ifdef FilePath__dFilePath
FUNCTION_AT_ADDRESS( FilePath::~FilePath(void),FilePath__dFilePath);
#endif
#ifdef SharedString__dSharedString
FUNCTION_AT_ADDRESS( SharedString::~SharedString(void),SharedString__dSharedString);
#endif
#ifdef FilePath__FilePath1
FUNCTION_AT_ADDRESS( FilePath::FilePath(class SharedString const &),FilePath__FilePath1);
#endif
#ifdef EqSoundManager__LoadOldEmitters
FUNCTION_AT_ADDRESS(void  EqSoundManager::LoadOldEmitters(void),EqSoundManager__LoadOldEmitters);
#endif
#ifdef EqSoundManager__CreateOldEmitter
//FUNCTION_AT_ADDRESS(class SoundEmitter *  EqSoundManager::CreateOldEmitter(int,float,float,float,int,int,int,float,int,int,int),EqSoundManager__CreateOldEmitter);
#endif
#ifdef EqSoundManager__GetAsset
FUNCTION_AT_ADDRESS(class SoundAsset *  EqSoundManager::GetAsset(char *),EqSoundManager__GetAsset);
#endif
#ifdef EqSoundManager__ReleaseZoneSpecificMidi
FUNCTION_AT_ADDRESS(void  EqSoundManager::ReleaseZoneSpecificMidi(void),EqSoundManager__ReleaseZoneSpecificMidi);
#endif
#ifdef EqSoundManager__ReleaseZoneSpecificWaves
FUNCTION_AT_ADDRESS(void  EqSoundManager::ReleaseZoneSpecificWaves(void),EqSoundManager__ReleaseZoneSpecificWaves);
#endif
#ifdef EqSoundManager__ReleaseZoneSpecificEmitters
FUNCTION_AT_ADDRESS(void  EqSoundManager::ReleaseZoneSpecificEmitters(void),EqSoundManager__ReleaseZoneSpecificEmitters);
#endif
#ifdef EqSoundManager__SetEffectsLevel
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetEffectsLevel(float),EqSoundManager__SetEffectsLevel);
#endif
#ifdef EqSoundManager__SetMixAhead
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetMixAhead(int),EqSoundManager__SetMixAhead);
#endif
#ifdef EqSoundManager__SetWaveVolume
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetWaveVolume(float),EqSoundManager__SetWaveVolume);
#endif
#ifdef EqSoundManager__SetMusicVolume
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetMusicVolume(float),EqSoundManager__SetMusicVolume);
#endif
#ifdef EqSoundManager__GetListenerEnvironment
//FUNCTION_AT_ADDRESS(enum EnvironmentType  EqSoundManager::GetListenerEnvironment(void),EqSoundManager__GetListenerEnvironment);
#endif
#ifdef EqSoundManager__SetListenerEnvironment
//FUNCTION_AT_ADDRESS(void  EqSoundManager::SetListenerEnvironment(enum EnvironmentType),EqSoundManager__SetListenerEnvironment);
#endif
#ifdef EqSoundManager__SetListenerEnvironmentLow
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetListenerEnvironmentLow(void),EqSoundManager__SetListenerEnvironmentLow);
#endif
#ifdef EqSoundManager__SetListenerEnvironmentHigh
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetListenerEnvironmentHigh(void),EqSoundManager__SetListenerEnvironmentHigh);
#endif
#ifdef EqSoundManager__SetListenerEnvironmentOutside
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetListenerEnvironmentOutside(void),EqSoundManager__SetListenerEnvironmentOutside);
#endif
#ifdef EqSoundManager__SetListenerLocation
FUNCTION_AT_ADDRESS(void  EqSoundManager::SetListenerLocation(float,float,float,float),EqSoundManager__SetListenerLocation);
#endif
#ifdef EqSoundManager__EmitterSetRaining
FUNCTION_AT_ADDRESS(void  EqSoundManager::EmitterSetRaining(bool),EqSoundManager__EmitterSetRaining);
#endif
#ifdef EqSoundManager__EmitterSetWind
FUNCTION_AT_ADDRESS(void  EqSoundManager::EmitterSetWind(bool),EqSoundManager__EmitterSetWind);
#endif
#ifdef EqSoundManager__EmitterSetNight
FUNCTION_AT_ADDRESS(void  EqSoundManager::EmitterSetNight(bool),EqSoundManager__EmitterSetNight);
#endif
#ifdef EqSoundManager__EmitterSetUserDisabled
FUNCTION_AT_ADDRESS(void  EqSoundManager::EmitterSetUserDisabled(bool),EqSoundManager__EmitterSetUserDisabled);
#endif
#ifdef EqSoundManager__EmitterSetIndoors
FUNCTION_AT_ADDRESS(void  EqSoundManager::EmitterSetIndoors(bool),EqSoundManager__EmitterSetIndoors);
#endif
#ifdef EqSoundManager__UpdateEmitterStates
FUNCTION_AT_ADDRESS(void  EqSoundManager::UpdateEmitterStates(void),EqSoundManager__UpdateEmitterStates);
#endif
#ifdef EqSoundManager__OldMp3ClearSelections
FUNCTION_AT_ADDRESS(void  EqSoundManager::OldMp3ClearSelections(void),EqSoundManager__OldMp3ClearSelections);
#endif
#ifdef EqSoundManager__OldMp3Init
FUNCTION_AT_ADDRESS(void  EqSoundManager::OldMp3Init(void),EqSoundManager__OldMp3Init);
#endif
#ifdef EqSoundManager__OldMp3Terminate
FUNCTION_AT_ADDRESS(void  EqSoundManager::OldMp3Terminate(void),EqSoundManager__OldMp3Terminate);
#endif
#ifdef EqSoundManager__OldMp3GetSelection
FUNCTION_AT_ADDRESS(class SoundAsset *  EqSoundManager::OldMp3GetSelection(int),EqSoundManager__OldMp3GetSelection);
#endif
#ifdef EqSoundManager__EmitterLoad
FUNCTION_AT_ADDRESS(bool  EqSoundManager::EmitterLoad(char *),EqSoundManager__EmitterLoad);
#endif
#ifdef EqSoundManager__EmitterAdd
FUNCTION_AT_ADDRESS(void  EqSoundManager::EmitterAdd(class EqEmitterData *),EqSoundManager__EmitterAdd);
#endif
#ifdef EqMobileEmitter__EqMobileEmitter
FUNCTION_AT_ADDRESS( EqMobileEmitter::EqMobileEmitter(class EqSoundManager *),EqMobileEmitter__EqMobileEmitter);
#endif
#ifdef EqMobileEmitter__dEqMobileEmitter
FUNCTION_AT_ADDRESS( EqMobileEmitter::~EqMobileEmitter(void),EqMobileEmitter__dEqMobileEmitter);
#endif
#ifdef EqMobileEmitter__Move
FUNCTION_AT_ADDRESS(void  EqMobileEmitter::Move(float,float,float),EqMobileEmitter__Move);
#endif
#ifdef EqMobileEmitter__SetWave
FUNCTION_AT_ADDRESS(void  EqMobileEmitter::SetWave(int,char *),EqMobileEmitter__SetWave);
#endif
#ifdef EqMobileEmitter__SetNpcHeight
FUNCTION_AT_ADDRESS(void  EqMobileEmitter::SetNpcHeight(float),EqMobileEmitter__SetNpcHeight);
#endif
#ifdef EqEmitterData__EqEmitterData
FUNCTION_AT_ADDRESS( EqEmitterData::EqEmitterData(void),EqEmitterData__EqEmitterData);
#endif
#ifdef EqEmitterData__SetLoadString
FUNCTION_AT_ADDRESS(void  EqEmitterData::SetLoadString(char *),EqEmitterData__SetLoadString);
#endif
#ifdef EQ_Spell__SpellUsesDragonBreathEffect
FUNCTION_AT_ADDRESS(int  EQ_Spell::SpellUsesDragonBreathEffect(void),EQ_Spell__SpellUsesDragonBreathEffect);
#endif
#ifdef EQ_Spell__EQ_Spell
FUNCTION_AT_ADDRESS( EQ_Spell::EQ_Spell(char *),EQ_Spell__EQ_Spell);
#endif
#ifdef EQ_Spell__dEQ_Spell
FUNCTION_AT_ADDRESS( EQ_Spell::~EQ_Spell(void),EQ_Spell__dEQ_Spell);
#endif
#ifdef EQ_Spell__IsSPAIgnoredByStacking
FUNCTION_AT_ADDRESS(bool __cdecl EQ_Spell::IsSPAIgnoredByStacking(int),EQ_Spell__IsSPAIgnoredByStacking);
#endif
#ifdef EQ_Spell__SpellAffects
FUNCTION_AT_ADDRESS(unsigned char  EQ_Spell::SpellAffects(int)const ,EQ_Spell__SpellAffects);
#endif
#ifdef EQ_Spell__IsPermIllusionSpell
FUNCTION_AT_ADDRESS(int  EQ_Spell::IsPermIllusionSpell(void)const ,EQ_Spell__IsPermIllusionSpell);
#endif
#ifdef EQOldPlayerAnimation__InitAnimationData
FUNCTION_AT_ADDRESS(void __cdecl EQOldPlayerAnimation::InitAnimationData(void),EQOldPlayerAnimation__InitAnimationData);
#endif
#ifdef EQOldPlayerAnimation__PlayAttachmentAnimationTracks
FUNCTION_AT_ADDRESS(void  EQOldPlayerAnimation::PlayAttachmentAnimationTracks(int,int,bool,bool,float,bool,unsigned char),EQOldPlayerAnimation__PlayAttachmentAnimationTracks);
#endif
#ifdef EQOldPlayerAnimation__EQOldPlayerAnimation
FUNCTION_AT_ADDRESS( EQOldPlayerAnimation::EQOldPlayerAnimation(class EQPlayer *),EQOldPlayerAnimation__EQOldPlayerAnimation);
#endif
#ifdef EQOldPlayerAnimation__InterruptCurrentAnimation
FUNCTION_AT_ADDRESS(bool  EQOldPlayerAnimation::InterruptCurrentAnimation(int,unsigned char),EQOldPlayerAnimation__InterruptCurrentAnimation);
#endif
#ifdef EQOldPlayerAnimation__ChangeAttachmentAnimationTrackSpeeds
FUNCTION_AT_ADDRESS(void  EQOldPlayerAnimation::ChangeAttachmentAnimationTrackSpeeds(bool,float),EQOldPlayerAnimation__ChangeAttachmentAnimationTrackSpeeds);
#endif
#ifdef EQOldPlayerAnimation__IsSocialAnimation
FUNCTION_AT_ADDRESS(bool  EQOldPlayerAnimation::IsSocialAnimation(int),EQOldPlayerAnimation__IsSocialAnimation);
#endif
#ifdef EQOldPlayerAnimation__IsStandAnimation
FUNCTION_AT_ADDRESS(bool  EQOldPlayerAnimation::IsStandAnimation(int),EQOldPlayerAnimation__IsStandAnimation);
#endif
#ifdef EQOldPlayerAnimation__IsIdleAnimation
FUNCTION_AT_ADDRESS(bool  EQOldPlayerAnimation::IsIdleAnimation(int),EQOldPlayerAnimation__IsIdleAnimation);
#endif
#ifdef EQOldPlayerAnimation__AnimationIsAggressive
FUNCTION_AT_ADDRESS(bool  EQOldPlayerAnimation::AnimationIsAggressive(int),EQOldPlayerAnimation__AnimationIsAggressive);
#endif
#ifdef EQAnimation__EQAnimation
FUNCTION_AT_ADDRESS( EQAnimation::EQAnimation(void),EQAnimation__EQAnimation);
#endif
#ifdef EQPlayer__DoCamAi
FUNCTION_AT_ADDRESS(void  EQPlayer::DoCamAi(void),EQPlayer__DoCamAi);
#endif
#ifdef CVector3__Normalize
FUNCTION_AT_ADDRESS(void  CVector3::Normalize(void),CVector3__Normalize);
#endif
#ifdef CVector3__GetLength
FUNCTION_AT_ADDRESS(float  CVector3::GetLength(void)const ,CVector3__GetLength);
#endif
#ifdef CVector3__NormalizeAndReturnLength
FUNCTION_AT_ADDRESS(float  CVector3::NormalizeAndReturnLength(void),CVector3__NormalizeAndReturnLength);
#endif
#ifdef EQEffect__EQEffect
FUNCTION_AT_ADDRESS( EQEffect::EQEffect(class EQEffect *,char *,int,struct _EQLOC *,class EQPlayer *,class EQMissile *,struct _EQRGB *,float,int,int,float,float),EQEffect__EQEffect);
#endif
#ifdef EQEffect__dEQEffect
FUNCTION_AT_ADDRESS( EQEffect::~EQEffect(void),EQEffect__dEQEffect);
#endif
#ifdef CEverQuest__msgStartIcon
FUNCTION_AT_ADDRESS(int  CEverQuest::msgStartIcon(void *),CEverQuest__msgStartIcon);
#endif
#ifdef CEverQuest__msgStartInotes
FUNCTION_AT_ADDRESS(int  CEverQuest::msgStartInotes(void *),CEverQuest__msgStartInotes);
#endif
#ifdef CEverQuest__msgStartIeq
FUNCTION_AT_ADDRESS(int  CEverQuest::msgStartIeq(void *),CEverQuest__msgStartIeq);
#endif
#ifdef CEverQuest__HandleItems
FUNCTION_AT_ADDRESS(int  CEverQuest::HandleItems(void *,int),CEverQuest__HandleItems);
#endif
#ifdef CEverQuest__HandleWorldMessage
FUNCTION_AT_ADDRESS(unsigned char  CEverQuest::HandleWorldMessage(struct connection_t *,unsigned __int32,char *,unsigned __int32),CEverQuest__HandleWorldMessage);
#endif
#ifdef EQHSprite__EQHSprite
FUNCTION_AT_ADDRESS( EQHSprite::EQHSprite(char *,struct T3D_tagACTORINSTANCE *,class EQPlayer *),EQHSprite__EQHSprite);
#endif
#ifdef EQHSprite__dEQHSprite
FUNCTION_AT_ADDRESS( EQHSprite::~EQHSprite(void),EQHSprite__dEQHSprite);
#endif
#ifdef EQHSprite__get_object
FUNCTION_AT_ADDRESS(class EQHSprite *  EQHSprite::get_object(char *),EQHSprite__get_object);
#endif
#ifdef EQHSprite__GetAnimationTrackPtr
FUNCTION_AT_ADDRESS(bool  EQHSprite::GetAnimationTrackPtr(char *,char *,int,int,unsigned char,int),EQHSprite__GetAnimationTrackPtr);
#endif
#ifdef EQItemList__EQItemList
FUNCTION_AT_ADDRESS( EQItemList::EQItemList(void),EQItemList__EQItemList);
#endif
#ifdef EQItemList__dEQItemList
FUNCTION_AT_ADDRESS( EQItemList::~EQItemList(void),EQItemList__dEQItemList);
#endif
#ifdef EQItemList__get_item
FUNCTION_AT_ADDRESS(class EQItemList *  EQItemList::get_item(long),EQItemList__get_item);
#endif
#ifdef EQItemList__is_item_actor
FUNCTION_AT_ADDRESS(class EQItemList *  EQItemList::is_item_actor(struct T3D_tagACTORINSTANCE *),EQItemList__is_item_actor);
#endif
#ifdef public_key__dpublic_key
FUNCTION_AT_ADDRESS( public_key::~public_key(void),public_key__dpublic_key);
#endif
#ifdef public_key__public_key
FUNCTION_AT_ADDRESS( public_key::public_key(void),public_key__public_key);
#endif
#ifdef PacketPackerManager__Initialize
FUNCTION_AT_ADDRESS(void __cdecl PacketPackerManager::Initialize(void),PacketPackerManager__Initialize);
#endif
#ifdef EQMissile__EQMissile
FUNCTION_AT_ADDRESS( EQMissile::EQMissile(class EQ_Equipment *,class EQPlayer *,class EQMissile *,char *,unsigned char,unsigned int),EQMissile__EQMissile);
#endif
#ifdef EQMissile__dEQMissile
FUNCTION_AT_ADDRESS( EQMissile::~EQMissile(void),EQMissile__dEQMissile);
#endif
#ifdef EQMissile__CleanUpMyEffects
FUNCTION_AT_ADDRESS(void  EQMissile::CleanUpMyEffects(void),EQMissile__CleanUpMyEffects);
#endif
#ifdef EQMissile__is_missile_actor
FUNCTION_AT_ADDRESS(class EQMissile *  EQMissile::is_missile_actor(struct T3D_tagACTORINSTANCE *),EQMissile__is_missile_actor);
#endif
#ifdef EQMissile__HitActor
FUNCTION_AT_ADDRESS(void  EQMissile::HitActor(struct T3D_tagACTORINSTANCE *,bool),EQMissile__HitActor);
#endif
#ifdef EQMissile__ProcessMissile
FUNCTION_AT_ADDRESS(void  EQMissile::ProcessMissile(void),EQMissile__ProcessMissile);
#endif
#ifdef EQMissile__MissileAI
FUNCTION_AT_ADDRESS(void  EQMissile::MissileAI(void),EQMissile__MissileAI);
#endif
#ifdef EQMoneyList__EQMoneyList
FUNCTION_AT_ADDRESS( EQMoneyList::EQMoneyList(void),EQMoneyList__EQMoneyList);
#endif
#ifdef EQMoneyList__dEQMoneyList
FUNCTION_AT_ADDRESS( EQMoneyList::~EQMoneyList(void),EQMoneyList__dEQMoneyList);
#endif
#ifdef EQMoneyList__get_money
FUNCTION_AT_ADDRESS(class EQMoneyList *  EQMoneyList::get_money(long),EQMoneyList__get_money);
#endif
#ifdef CDisplay__MoveMissile
FUNCTION_AT_ADDRESS(int  CDisplay::MoveMissile(class EQMissile *),CDisplay__MoveMissile);
#endif
#ifdef CDisplay__GetOnActor
FUNCTION_AT_ADDRESS(void  CDisplay::GetOnActor(struct T3D_tagACTORINSTANCE *,class EQPlayer *),CDisplay__GetOnActor);
#endif
#ifdef EQPlayer__CanIFitHere
FUNCTION_AT_ADDRESS(bool  EQPlayer::CanIFitHere(float,float,float),EQPlayer__CanIFitHere);
#endif
#ifdef EQPlayer__MovePlayer
FUNCTION_AT_ADDRESS(int  EQPlayer::MovePlayer(void),EQPlayer__MovePlayer);
#endif
#ifdef bad_word_class__bad_word_class
FUNCTION_AT_ADDRESS( bad_word_class::bad_word_class(char *),bad_word_class__bad_word_class);
#endif
#ifdef EQObject__EQObject
FUNCTION_AT_ADDRESS( EQObject::EQObject(class EQObject *,class EQPlayer *,char *,char *),EQObject__EQObject);
#endif
#ifdef EQObject__dEQObject
FUNCTION_AT_ADDRESS( EQObject::~EQObject(void),EQObject__dEQObject);
#endif
#ifdef EQPlayer__EQPlayer
FUNCTION_AT_ADDRESS( EQPlayer::EQPlayer(class EQPlayer *,unsigned char,unsigned int,unsigned char,char *),EQPlayer__EQPlayer);
#endif
#ifdef EQPlayer__dEQPlayer
FUNCTION_AT_ADDRESS( EQPlayer::~EQPlayer(void),EQPlayer__dEQPlayer);
#endif
#ifdef EQPlayer__ResetVariables
FUNCTION_AT_ADDRESS(void  EQPlayer::ResetVariables(void),EQPlayer__ResetVariables);
#endif
#ifdef EQPlayer__do_change_form
FUNCTION_AT_ADDRESS(void  EQPlayer::do_change_form(struct chngForm *),EQPlayer__do_change_form);
#endif
#ifdef EQPlayer__DisplayWeaponsAndArmor
FUNCTION_AT_ADDRESS(void  EQPlayer::DisplayWeaponsAndArmor(void),EQPlayer__DisplayWeaponsAndArmor);
#endif
#ifdef EQPlayer__CleanUpTarget
FUNCTION_AT_ADDRESS(void  EQPlayer::CleanUpTarget(void),EQPlayer__CleanUpTarget);
#endif
#ifdef EQPlayer__FollowPlayerAI
FUNCTION_AT_ADDRESS(void  EQPlayer::FollowPlayerAI(void),EQPlayer__FollowPlayerAI);
#endif
#ifdef EQPlayer__TurnOffAutoFollow
FUNCTION_AT_ADDRESS(void  EQPlayer::TurnOffAutoFollow(void),EQPlayer__TurnOffAutoFollow);
#endif
#ifdef EQPlayer__AimAtTarget
FUNCTION_AT_ADDRESS(int  EQPlayer::AimAtTarget(class EQPlayer *,class EQMissile *),EQPlayer__AimAtTarget);
#endif
#ifdef EQPlayer__FacePlayer
FUNCTION_AT_ADDRESS(void  EQPlayer::FacePlayer(class EQPlayer *),EQPlayer__FacePlayer);
#endif
#ifdef EQPlayer__CleanUpVehicle
FUNCTION_AT_ADDRESS(void  EQPlayer::CleanUpVehicle(void),EQPlayer__CleanUpVehicle);
#endif
#ifdef EQPlayer__CleanUpMyEffects
FUNCTION_AT_ADDRESS(void  EQPlayer::CleanUpMyEffects(void),EQPlayer__CleanUpMyEffects);
#endif
#ifdef EQPlayer__GetPlayerFromName
FUNCTION_AT_ADDRESS(class EQPlayer *__cdecl EQPlayer::GetPlayerFromName(char const *),EQPlayer__GetPlayerFromName);
#endif
#ifdef EQPlayer__GetPlayerFromPartialName
FUNCTION_AT_ADDRESS(class EQPlayer * __cdecl EQPlayer::GetPlayerFromPartialName(char *),EQPlayer__GetPlayerFromPartialName);
#endif
#ifdef EQPlayer__GetClosestPlayerFromPartialName
FUNCTION_AT_ADDRESS(class EQPlayer * __cdecl EQPlayer::GetClosestPlayerFromPartialName(char *,class EQPlayer *),EQPlayer__GetClosestPlayerFromPartialName);
#endif
#ifdef EQPlayer__IsPlayerActor
FUNCTION_AT_ADDRESS(class EQPlayer * __cdecl EQPlayer::IsPlayerActor(struct T3D_tagACTORINSTANCE *),EQPlayer__IsPlayerActor);
#endif
#ifdef EQPlayer__TackOnNeuterChar
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::TackOnNeuterChar(char *,unsigned int),EQPlayer__TackOnNeuterChar);
#endif
#ifdef EQPlayer__GetActorTag
FUNCTION_AT_ADDRESS(void  EQPlayer::GetActorTag(char *),EQPlayer__GetActorTag);
#endif
#ifdef EQPlayer__GetPCActorTag
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::GetPCActorTag(char *,unsigned int,unsigned char),EQPlayer__GetPCActorTag);
#endif
#ifdef EQPlayer__NotOnSameDeity
FUNCTION_AT_ADDRESS(int  EQPlayer::NotOnSameDeity(class EQPlayer *,class EQ_Spell *),EQPlayer__NotOnSameDeity);
#endif
#ifdef EQPlayer__SetAnimVariation
FUNCTION_AT_ADDRESS(void  EQPlayer::SetAnimVariation(void),EQPlayer__SetAnimVariation);
#endif
#ifdef EQPlayer__SetAfk
FUNCTION_AT_ADDRESS(void  EQPlayer::SetAfk(int),EQPlayer__SetAfk);
#endif
#ifdef EQPlayer__AllowedToAttack
FUNCTION_AT_ADDRESS(bool  EQPlayer::AllowedToAttack(class EQPlayer *,int),EQPlayer__AllowedToAttack);
#endif
#ifdef EQPlayer__CanIHit
FUNCTION_AT_ADDRESS(bool  EQPlayer::CanIHit(class EQPlayer *,float),EQPlayer__CanIHit);
#endif
#ifdef EQPlayer__ModifyAttackSpeed
FUNCTION_AT_ADDRESS(unsigned int  EQPlayer::ModifyAttackSpeed(unsigned int,int),EQPlayer__ModifyAttackSpeed);
#endif
#ifdef EQPlayer__DoAttack
FUNCTION_AT_ADDRESS(int  EQPlayer::DoAttack(unsigned char,unsigned char,class EQPlayer *),EQPlayer__DoAttack);
#endif
#ifdef EQPlayer__HandleAmmo
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::HandleAmmo(void),EQPlayer__HandleAmmo);
#endif
#ifdef EQPlayer__TriggerSpellEffect
FUNCTION_AT_ADDRESS(void  EQPlayer::TriggerSpellEffect(struct _EQMissileHitinfo *),EQPlayer__TriggerSpellEffect);
#endif
#ifdef EQPlayer__IWasHit
FUNCTION_AT_ADDRESS(bool  EQPlayer::IWasHit(struct _EQMissileHitinfo *),EQPlayer__IWasHit);
#endif
#ifdef EQPlayer__GetConscious
FUNCTION_AT_ADDRESS(void  EQPlayer::GetConscious(void),EQPlayer__GetConscious);
#endif
#ifdef EQPlayer__KnockedOut
FUNCTION_AT_ADDRESS(void  EQPlayer::KnockedOut(void),EQPlayer__KnockedOut);
#endif
#ifdef EQPlayer__IDied
FUNCTION_AT_ADDRESS(void  EQPlayer::IDied(struct _EQPlayerDeath *),EQPlayer__IDied);
#endif
#ifdef EQPlayer__HandoverControlToZoneserver
FUNCTION_AT_ADDRESS(void  EQPlayer::HandoverControlToZoneserver(void),EQPlayer__HandoverControlToZoneserver);
#endif
#ifdef EQPlayer__TouchingSwitch
FUNCTION_AT_ADDRESS(void  EQPlayer::TouchingSwitch(void),EQPlayer__TouchingSwitch);
#endif
#ifdef EQPlayer__MyFeetAreOnGround
FUNCTION_AT_ADDRESS(bool  EQPlayer::MyFeetAreOnGround(void),EQPlayer__MyFeetAreOnGround);
#endif
#ifdef EQPlayer__IHaveFallen
FUNCTION_AT_ADDRESS(void  EQPlayer::IHaveFallen(float),EQPlayer__IHaveFallen);
#endif
#ifdef EQPlayer__SkillUsed
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::SkillUsed(unsigned char),EQPlayer__SkillUsed);
#endif
#ifdef EQPlayer__BodyEnvironmentChange
FUNCTION_AT_ADDRESS(void  EQPlayer::BodyEnvironmentChange(unsigned char),EQPlayer__BodyEnvironmentChange);
#endif
#ifdef EQPlayer__FeetEnvironmentChange
FUNCTION_AT_ADDRESS(void  EQPlayer::FeetEnvironmentChange(unsigned char),EQPlayer__FeetEnvironmentChange);
#endif
#ifdef EQPlayer__HeadEnvironmentChange
FUNCTION_AT_ADDRESS(void  EQPlayer::HeadEnvironmentChange(unsigned char),EQPlayer__HeadEnvironmentChange);
#endif
#ifdef EQPlayer__LegalPlayerRace
FUNCTION_AT_ADDRESS(int  EQPlayer::LegalPlayerRace(int),EQPlayer__LegalPlayerRace);
#endif
#ifdef EQPlayer__DeleteMyMissiles
FUNCTION_AT_ADDRESS(void  EQPlayer::DeleteMyMissiles(void),EQPlayer__DeleteMyMissiles);
#endif
#ifdef EQPlayer__ChangePosition
FUNCTION_AT_ADDRESS(void  EQPlayer::ChangePosition(unsigned char),EQPlayer__ChangePosition);
#endif
#ifdef EQPlayer__ChangeHeight
FUNCTION_AT_ADDRESS(void  EQPlayer::ChangeHeight(float),EQPlayer__ChangeHeight);
#endif
#ifdef EQPlayer__PositionOnFloor
FUNCTION_AT_ADDRESS(void  EQPlayer::PositionOnFloor(void),EQPlayer__PositionOnFloor);
#endif
#ifdef EQPlayer__IsRoleplaying
FUNCTION_AT_ADDRESS(bool  EQPlayer::IsRoleplaying(void),EQPlayer__IsRoleplaying);
#endif
#ifdef EQPlayer__IsInvited
FUNCTION_AT_ADDRESS(bool  EQPlayer::IsInvited(void),EQPlayer__IsInvited);
#endif
#ifdef EQPlayer__SetInvited
FUNCTION_AT_ADDRESS(void  EQPlayer::SetInvited(bool),EQPlayer__SetInvited);
#endif
#ifdef EQPlayer__PlaySoundA
FUNCTION_AT_ADDRESS(void  EQPlayer::PlaySoundA(int),EQPlayer__PlaySoundA);
#endif
#ifdef EQPlayer__SetSounds
FUNCTION_AT_ADDRESS(void  EQPlayer::SetSounds(void),EQPlayer__SetSounds);
#endif
#ifdef EQPlayer__SetCurrentLoopSound
FUNCTION_AT_ADDRESS(void  EQPlayer::SetCurrentLoopSound(int),EQPlayer__SetCurrentLoopSound);
#endif
#ifdef EQPlayer__IsFlyer
FUNCTION_AT_ADDRESS(bool  EQPlayer::IsFlyer(void),EQPlayer__IsFlyer);
#endif
#ifdef EQPlayer__InitSneakMod
FUNCTION_AT_ADDRESS(void  EQPlayer::InitSneakMod(void),EQPlayer__InitSneakMod);
#endif
#ifdef EQPlayer__SetHeights
FUNCTION_AT_ADDRESS(void  EQPlayer::SetHeights(void),EQPlayer__SetHeights);
#endif
#ifdef EQPMInfo__SetApplyGravity
FUNCTION_AT_ADDRESS(void  EQPMInfo::SetApplyGravity(bool),EQPMInfo__SetApplyGravity);
#endif
#ifdef EQPlayer__GetDefaultHeight
FUNCTION_AT_ADDRESS(float  EQPlayer::GetDefaultHeight(int,unsigned char),EQPlayer__GetDefaultHeight);
#endif
#ifdef EQPlayer__ComputeSpecialHeights
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::ComputeSpecialHeights(int,float *,float *,float *,float *,bool),EQPlayer__ComputeSpecialHeights);
#endif
#ifdef EQPlayer__IsUntexturedHorse
FUNCTION_AT_ADDRESS(bool  EQPlayer::IsUntexturedHorse(void),EQPlayer__IsUntexturedHorse);
#endif
#ifdef EQPlayer__HasInvalidRiderTexture
FUNCTION_AT_ADDRESS(bool const  EQPlayer::HasInvalidRiderTexture(void)const ,EQPlayer__HasInvalidRiderTexture);
#endif
#ifdef EQPlayer__ForceInvisible
FUNCTION_AT_ADDRESS(void  EQPlayer::ForceInvisible(bool),EQPlayer__ForceInvisible);
#endif
#ifdef EQPlayer__MountableRace
FUNCTION_AT_ADDRESS(int  EQPlayer::MountableRace(void),EQPlayer__MountableRace);
#endif
#ifdef EQPlayer__MakeRiderMountUp
FUNCTION_AT_ADDRESS(void  EQPlayer::MakeRiderMountUp(void),EQPlayer__MakeRiderMountUp);
#endif
#ifdef EQPlayer__MountEQPlayer
FUNCTION_AT_ADDRESS(void  EQPlayer::MountEQPlayer(class EQPlayer *),EQPlayer__MountEQPlayer);
#endif
#ifdef EQPlayer__Dismount
FUNCTION_AT_ADDRESS(void  EQPlayer::Dismount(void),EQPlayer__Dismount);
#endif
#ifdef EQPlayer__GetArmorType
FUNCTION_AT_ADDRESS(int  EQPlayer::GetArmorType(int),EQPlayer__GetArmorType);
#endif
#ifdef EQPlayer__SetArmorType
FUNCTION_AT_ADDRESS(void  EQPlayer::SetArmorType(int,int),EQPlayer__SetArmorType);
#endif
#ifdef EQPlayer__GetArmorTint
FUNCTION_AT_ADDRESS(unsigned long  EQPlayer::GetArmorTint(int),EQPlayer__GetArmorTint);
#endif
#ifdef EQPlayer__SetArmorTint
FUNCTION_AT_ADDRESS(void  EQPlayer::SetArmorTint(int,unsigned long),EQPlayer__SetArmorTint);
#endif
#ifdef EQPlayer__SetAccel
FUNCTION_AT_ADDRESS(void  EQPlayer::SetAccel(float,int),EQPlayer__SetAccel);
#endif
#ifdef EQPlayer__SetToRandomRace
FUNCTION_AT_ADDRESS(void  EQPlayer::SetToRandomRace(void),EQPlayer__SetToRandomRace);
#endif
#ifdef EQPlayer__GetBaseFaceNbr
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::GetBaseFaceNbr(int,unsigned char *),EQPlayer__GetBaseFaceNbr);
#endif
#ifdef EQPlayer__HasAttachedBeard
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::HasAttachedBeard(void),EQPlayer__HasAttachedBeard);
#endif
#ifdef EQPlayer__HasAttachedHair
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::HasAttachedHair(void),EQPlayer__HasAttachedHair);
#endif
#ifdef EQPlayer__SetDefaultFacialFeaturesByFace
FUNCTION_AT_ADDRESS(void  EQPlayer::SetDefaultFacialFeaturesByFace(int,unsigned char,unsigned char),EQPlayer__SetDefaultFacialFeaturesByFace);
#endif
#ifdef EQPlayer__GetAllowedHairColorIndexRange
FUNCTION_AT_ADDRESS(void  EQPlayer::GetAllowedHairColorIndexRange(int,int *,int *),EQPlayer__GetAllowedHairColorIndexRange);
#endif
#ifdef EQPlayer__CanBeBald
FUNCTION_AT_ADDRESS(int  EQPlayer::CanBeBald(void),EQPlayer__CanBeBald);
#endif
#ifdef EQPlayer__ChangeNoGravity
FUNCTION_AT_ADDRESS(void  EQPlayer::ChangeNoGravity(int),EQPlayer__ChangeNoGravity);
#endif
#ifdef EQPlayer__IdUsed
FUNCTION_AT_ADDRESS(int  EQPlayer::IdUsed(unsigned int),EQPlayer__IdUsed);
#endif
#ifdef EQPlayer__GetUnusedID
FUNCTION_AT_ADDRESS(unsigned int  EQPlayer::GetUnusedID(void),EQPlayer__GetUnusedID);
#endif
#ifdef EQPlayer__SetAndReserveID
FUNCTION_AT_ADDRESS(void  EQPlayer::SetAndReserveID(unsigned int),EQPlayer__SetAndReserveID);
#endif
#ifdef EQPlayer__InitializeIDArray
FUNCTION_AT_ADDRESS(void  EQPlayer::InitializeIDArray(void),EQPlayer__InitializeIDArray);
#endif
#ifdef EQPlayer__Levitating
FUNCTION_AT_ADDRESS(int  EQPlayer::Levitating(void),EQPlayer__Levitating);
#endif
#ifdef EQPlayer__SetRace
FUNCTION_AT_ADDRESS(void  EQPlayer::SetRace(int),EQPlayer__SetRace);
#endif
#ifdef EQPlayer__CanChangeForm
FUNCTION_AT_ADDRESS(bool  EQPlayer::CanChangeForm(int,unsigned char),EQPlayer__CanChangeForm);
#endif
#ifdef EQPlayer__SetNameSpriteState
FUNCTION_AT_ADDRESS(int  EQPlayer::SetNameSpriteState(bool),EQPlayer__SetNameSpriteState);
#endif
#ifdef EQPlayer__ChangeBoneStringSprite
FUNCTION_AT_ADDRESS(struct S3D_STRINGSPRITE *  EQPlayer::ChangeBoneStringSprite(struct T3D_DAG *,char *),EQPlayer__ChangeBoneStringSprite);
#endif
#ifdef EQPlayer__SetNameSpriteTint
FUNCTION_AT_ADDRESS(bool  EQPlayer::SetNameSpriteTint(void),EQPlayer__SetNameSpriteTint);
#endif
#ifdef EQPlayer__UpdateNameSprite
FUNCTION_AT_ADDRESS(void  EQPlayer::UpdateNameSprite(void),EQPlayer__UpdateNameSprite);
#endif
#ifdef EQPlayer__UpdateBonePointers
FUNCTION_AT_ADDRESS(void  EQPlayer::UpdateBonePointers(void),EQPlayer__UpdateBonePointers);
#endif
#ifdef EQPlayer__FindDefaultEyeMaterialIndexes
FUNCTION_AT_ADDRESS(void  EQPlayer::FindDefaultEyeMaterialIndexes(void),EQPlayer__FindDefaultEyeMaterialIndexes);
#endif
#ifdef EQPlayer__CalcAnimLength
FUNCTION_AT_ADDRESS(unsigned int  EQPlayer::CalcAnimLength(int),EQPlayer__CalcAnimLength);
#endif
#ifdef EQPlayer__GetAlternateTrackNumber
FUNCTION_AT_ADDRESS(int  EQPlayer::GetAlternateTrackNumber(int,unsigned char *),EQPlayer__GetAlternateTrackNumber);
#endif
#ifdef EQPlayer__GetAlternateAnimVariation
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::GetAlternateAnimVariation(int,unsigned char),EQPlayer__GetAlternateAnimVariation);
#endif
#ifdef EQPlayer__GetRaceSexITOffset
FUNCTION_AT_ADDRESS(int  EQPlayer::GetRaceSexITOffset(void),EQPlayer__GetRaceSexITOffset);
#endif
#ifdef EQPlayer__UpdatePlayerVisibility
FUNCTION_AT_ADDRESS(void  EQPlayer::UpdatePlayerVisibility(void),EQPlayer__UpdatePlayerVisibility);
#endif
#ifdef EQPlayer__UpdateAllPlayersVisibility
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::UpdateAllPlayersVisibility(void),EQPlayer__UpdateAllPlayersVisibility);
#endif
#ifdef EQPlayer__IsBodyType_j
FUNCTION_AT_ADDRESS(bool EQPlayer::IsBodyType(unsigned int,int,int),EQPlayer__IsBodyType_j);
#endif
#ifdef EQPlayer__SetEyeMaterial
FUNCTION_AT_ADDRESS(int  EQPlayer::SetEyeMaterial(unsigned char,int),EQPlayer__SetEyeMaterial);
#endif
#ifdef EQPlayer__HideOrShowAttachedHair
FUNCTION_AT_ADDRESS(void  EQPlayer::HideOrShowAttachedHair(void),EQPlayer__HideOrShowAttachedHair);
#endif
#ifdef EQPlayer__SetFHEB
FUNCTION_AT_ADDRESS(int  EQPlayer::SetFHEB(unsigned char,unsigned char),EQPlayer__SetFHEB);
#endif
#ifdef EQPlayer__SetFHEB_Color
FUNCTION_AT_ADDRESS(int  EQPlayer::SetFHEB_Color(unsigned char,unsigned char),EQPlayer__SetFHEB_Color);
#endif
#ifdef EQPlayer__SetHairOrBeard
FUNCTION_AT_ADDRESS(int  EQPlayer::SetHairOrBeard(int),EQPlayer__SetHairOrBeard);
#endif
#ifdef EQPlayer__GetBonePointerByITS
FUNCTION_AT_ADDRESS(struct T3D_DAG *  EQPlayer::GetBonePointerByITS(int,int),EQPlayer__GetBonePointerByITS);
#endif
#ifdef EQPlayer__UpdateAppearance
FUNCTION_AT_ADDRESS(void  EQPlayer::UpdateAppearance(void),EQPlayer__UpdateAppearance);
#endif
#ifdef EQPlayer__SetDefaultITAttachments
FUNCTION_AT_ADDRESS(void  EQPlayer::SetDefaultITAttachments(int),EQPlayer__SetDefaultITAttachments);
#endif
#ifdef EQPlayer__SwapMaterial
FUNCTION_AT_ADDRESS(int  EQPlayer::SwapMaterial(int,int,int,int,unsigned char),EQPlayer__SwapMaterial);
#endif
#ifdef EQPlayer__SwapFace
FUNCTION_AT_ADDRESS(int  EQPlayer::SwapFace(int,int),EQPlayer__SwapFace);
#endif
#ifdef EQPlayer__GetAttachedHelmITNum
FUNCTION_AT_ADDRESS(int  EQPlayer::GetAttachedHelmITNum(int,int *),EQPlayer__GetAttachedHelmITNum);
#endif
#ifdef EQPlayer__SetPlayerConstantAmbient
FUNCTION_AT_ADDRESS(void  EQPlayer::SetPlayerConstantAmbient(struct T3D_RGB *),EQPlayer__SetPlayerConstantAmbient);
#endif
#ifdef EQPlayer__SwapHead
FUNCTION_AT_ADDRESS(int  EQPlayer::SwapHead(int,int,unsigned long,int),EQPlayer__SwapHead);
#endif
#ifdef EQPlayer__SetPlayerPitchType
FUNCTION_AT_ADDRESS(int  EQPlayer::SetPlayerPitchType(void),EQPlayer__SetPlayerPitchType);
#endif
#ifdef EQPlayer__IsValidTeleport
FUNCTION_AT_ADDRESS(int  EQPlayer::IsValidTeleport(float,float,float,float,float),EQPlayer__IsValidTeleport);
#endif
#ifdef EQPlayer__ReplaceSpecialCloakMaterials
FUNCTION_AT_ADDRESS(int  EQPlayer::ReplaceSpecialCloakMaterials(void),EQPlayer__ReplaceSpecialCloakMaterials);
#endif
#ifdef EQPlayer__SwapBody
FUNCTION_AT_ADDRESS(int  EQPlayer::SwapBody(int,int),EQPlayer__SwapBody);
#endif
#ifdef EQPlayer__HandleMaterialEx
FUNCTION_AT_ADDRESS(void  EQPlayer::HandleMaterialEx(int,unsigned int,unsigned int,unsigned long,int),EQPlayer__HandleMaterialEx);
#endif
#ifdef EQPlayer__UpdateItemSlot
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::UpdateItemSlot(unsigned char,char *,int),EQPlayer__UpdateItemSlot);
#endif
#ifdef EQPlayer__SwapNPCMaterials
FUNCTION_AT_ADDRESS(int  EQPlayer::SwapNPCMaterials(void),EQPlayer__SwapNPCMaterials);
#endif
#ifdef EQPlayer__PutPlayerOnFloor
FUNCTION_AT_ADDRESS(void  EQPlayer::PutPlayerOnFloor(void),EQPlayer__PutPlayerOnFloor);
#endif
#ifdef EQPlayer__CheckForUnderFloor
FUNCTION_AT_ADDRESS(void  EQPlayer::CheckForUnderFloor(void),EQPlayer__CheckForUnderFloor);
#endif
#ifdef EQPlayer__DoFloorCheck
FUNCTION_AT_ADDRESS(void  EQPlayer::DoFloorCheck(void),EQPlayer__DoFloorCheck);
#endif
#ifdef EQPlayer__DoSwimJump
FUNCTION_AT_ADDRESS(void  EQPlayer::DoSwimJump(unsigned char),EQPlayer__DoSwimJump);
#endif
#ifdef EQPlayer__PushAlongHeading
FUNCTION_AT_ADDRESS(void  EQPlayer::PushAlongHeading(float),EQPlayer__PushAlongHeading);
#endif
#ifdef EQPlayer__DoTeleport
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::DoTeleport(char *,int),EQPlayer__DoTeleport);
#endif
#ifdef EQPlayer__DoTeleportB
//FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::DoTeleportB(int,float,float,float,float,char *,enum ZONE_REQ_REASON),EQPlayer__DoTeleportB);
#endif
#ifdef EQPlayer__ChangeLight
FUNCTION_AT_ADDRESS(void  EQPlayer::ChangeLight(void),EQPlayer__ChangeLight);
#endif
#ifdef EQPlayer__GetBoneCoords
FUNCTION_AT_ADDRESS(bool  EQPlayer::GetBoneCoords(struct T3D_DAG *,struct _EQLOC *),EQPlayer__GetBoneCoords);
#endif
#ifdef EQPlayer__CheckForJump
FUNCTION_AT_ADDRESS(int  EQPlayer::CheckForJump(void),EQPlayer__CheckForJump);
#endif
#ifdef EQPlayer__GetPlayerFloorHeight
FUNCTION_AT_ADDRESS(float  EQPlayer::GetPlayerFloorHeight(float,float,float,unsigned char),EQPlayer__GetPlayerFloorHeight);
#endif
#ifdef EQPlayer__UpdatePlayerActor
FUNCTION_AT_ADDRESS(bool  EQPlayer::UpdatePlayerActor(void),EQPlayer__UpdatePlayerActor);
#endif
#ifdef EQPlayer__GetNearestActorTag
FUNCTION_AT_ADDRESS(unsigned char  EQPlayer::GetNearestActorTag(char *,void *),EQPlayer__GetNearestActorTag);
#endif
#ifdef EQPlayer__DoItemSlot
FUNCTION_AT_ADDRESS(void  EQPlayer::DoItemSlot(int),EQPlayer__DoItemSlot);
#endif
#ifdef EQPlayer__DoClassRandomAnimation
FUNCTION_AT_ADDRESS(void  EQPlayer::DoClassRandomAnimation(void),EQPlayer__DoClassRandomAnimation);
#endif
#ifdef EQPlayer__CreateUserLight
FUNCTION_AT_ADDRESS(struct T3D_POINTLIGHT *  EQPlayer::CreateUserLight(struct T3D_LIGHTDEFINITION *,int),EQPlayer__CreateUserLight);
#endif
#ifdef EQPlayer__AttachPlayerToPlayerBone
FUNCTION_AT_ADDRESS(int  EQPlayer::AttachPlayerToPlayerBone(class EQPlayer *,struct T3D_DAG *),EQPlayer__AttachPlayerToPlayerBone);
#endif
#ifdef EQPlayer__IsInvisible
FUNCTION_AT_ADDRESS(bool  EQPlayer::IsInvisible(class EQPlayer *),EQPlayer__IsInvisible);
#endif
#ifdef EQPlayer__IsAMount
FUNCTION_AT_ADDRESS(bool  EQPlayer::IsAMount(void),EQPlayer__IsAMount);
#endif
#ifdef EQPlayerManager__GetSpawnByID
FUNCTION_AT_ADDRESS(class EQPlayer * EQPlayerManager::GetSpawnByID(int),EQPlayerManager__GetSpawnByID);
#endif
#ifdef EQPlayerManager__GetSpawnByName
FUNCTION_AT_ADDRESS(class EQPlayer * EQPlayerManager::GetSpawnByName(char *),EQPlayerManager__GetSpawnByName);
#endif
#ifdef EQPMInfo__EQPMInfo
FUNCTION_AT_ADDRESS( EQPMInfo::EQPMInfo(char *),EQPMInfo__EQPMInfo);
#endif
#ifdef EQPMInfo__dEQPMInfo
FUNCTION_AT_ADDRESS( EQPMInfo::~EQPMInfo(void),EQPMInfo__dEQPMInfo);
#endif
#ifdef EQSwitch__EQSwitch
FUNCTION_AT_ADDRESS( EQSwitch::EQSwitch(char *,bool),EQSwitch__EQSwitch);
#endif
#ifdef EQSwitch__EQSwitch1
FUNCTION_AT_ADDRESS( EQSwitch::EQSwitch(struct OldDiskSwitch *,bool),EQSwitch__EQSwitch1);
#endif
#ifdef EQSwitch__EQSwitch2
FUNCTION_AT_ADDRESS( EQSwitch::EQSwitch(struct _EQClientSwitch *),EQSwitch__EQSwitch2);
#endif
#ifdef EQSwitch__PreInit
FUNCTION_AT_ADDRESS(void  EQSwitch::PreInit(void),EQSwitch__PreInit);
#endif
#ifdef EQSwitch__PostInit
FUNCTION_AT_ADDRESS(void  EQSwitch::PostInit(void),EQSwitch__PostInit);
#endif
#ifdef EQSwitch__dEQSwitch
FUNCTION_AT_ADDRESS( EQSwitch::~EQSwitch(void),EQSwitch__dEQSwitch);
#endif
#ifdef EQSwitch__ResetSwitchState
FUNCTION_AT_ADDRESS(void  EQSwitch::ResetSwitchState(unsigned char),EQSwitch__ResetSwitchState);
#endif
#ifdef EQSwitch__RepopSwitch
FUNCTION_AT_ADDRESS(void  EQSwitch::RepopSwitch(void),EQSwitch__RepopSwitch);
#endif
#ifdef EQSwitch__TopSpeed
FUNCTION_AT_ADDRESS(float  EQSwitch::TopSpeed(float *),EQSwitch__TopSpeed);
#endif
#ifdef EQSwitch__RepopFrequency
FUNCTION_AT_ADDRESS(unsigned int  EQSwitch::RepopFrequency(void),EQSwitch__RepopFrequency);
#endif
#ifdef EQSwitch__GetSwitchDamage
FUNCTION_AT_ADDRESS(int  EQSwitch::GetSwitchDamage(void),EQSwitch__GetSwitchDamage);
#endif
#ifdef EQSwitch__ChangeState
FUNCTION_AT_ADDRESS(void  EQSwitch::ChangeState(unsigned char,class EQPlayer *,bool),EQSwitch__ChangeState);
#endif
#ifdef EQSwitch__SwitchWasOpened
FUNCTION_AT_ADDRESS(unsigned char  EQSwitch::SwitchWasOpened(int,int,class EQPlayer *,bool *),EQSwitch__SwitchWasOpened);
#endif
#ifdef EQSwitch__SwitchWasOpenedActual
FUNCTION_AT_ADDRESS(unsigned char  EQSwitch::SwitchWasOpenedActual(int,int,class EQPlayer *,bool *),EQSwitch__SwitchWasOpenedActual);
#endif
#ifdef EQSwitch__SwitchIsNotUsable
FUNCTION_AT_ADDRESS(unsigned char  EQSwitch::SwitchIsNotUsable(int),EQSwitch__SwitchIsNotUsable);
#endif
#ifdef EQSwitch__UseSwitch
FUNCTION_AT_ADDRESS(void  EQSwitch::UseSwitch(unsigned int,int,int),EQSwitch__UseSwitch);
#endif
#ifdef EQSwitch__LoadSwitchSounds
FUNCTION_AT_ADDRESS(void  EQSwitch::LoadSwitchSounds(int),EQSwitch__LoadSwitchSounds);
#endif
#ifdef EQSwitch__GetCustomMoveDistance
FUNCTION_AT_ADDRESS(float  EQSwitch::GetCustomMoveDistance(void),EQSwitch__GetCustomMoveDistance);
#endif
#ifdef EqSwitchManager__EqSwitchManager
FUNCTION_AT_ADDRESS( EqSwitchManager::EqSwitchManager(void),EqSwitchManager__EqSwitchManager);
#endif
#ifdef EqSwitchManager__dEqSwitchManager
FUNCTION_AT_ADDRESS( EqSwitchManager::~EqSwitchManager(void),EqSwitchManager__dEqSwitchManager);
#endif
#ifdef EqSwitchManager__DeleteAll
FUNCTION_AT_ADDRESS(void  EqSwitchManager::DeleteAll(void),EqSwitchManager__DeleteAll);
#endif
#ifdef EqSwitchManager__Load
FUNCTION_AT_ADDRESS(void  EqSwitchManager::Load(char *,bool),EqSwitchManager__Load);
#endif
#ifdef EqSwitchManager__LoadOld
FUNCTION_AT_ADDRESS(void  EqSwitchManager::LoadOld(char *,bool),EqSwitchManager__LoadOld);
#endif
#ifdef EqSwitchManager__GetCount
FUNCTION_AT_ADDRESS(int  EqSwitchManager::GetCount(void),EqSwitchManager__GetCount);
#endif
#ifdef EqSwitchManager__GetSwitchByActor
FUNCTION_AT_ADDRESS(class EQSwitch *  EqSwitchManager::GetSwitchByActor(struct T3D_tagACTORINSTANCE *),EqSwitchManager__GetSwitchByActor);
#endif
#ifdef EqSwitchManager__GetSwitch
FUNCTION_AT_ADDRESS(class EQSwitch *  EqSwitchManager::GetSwitch(int),EqSwitchManager__GetSwitch);
#endif
#ifdef EqSwitchManager__GetSwitchById
FUNCTION_AT_ADDRESS(class EQSwitch *  EqSwitchManager::GetSwitchById(int,bool),EqSwitchManager__GetSwitchById);
#endif
#ifdef EqSwitchManager__AddSwitch
FUNCTION_AT_ADDRESS(void  EqSwitchManager::AddSwitch(class EQSwitch *),EqSwitchManager__AddSwitch);
#endif
#ifdef Util__GetNextToken
FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextToken(char *,int *,char *),Util__GetNextToken);
#endif
#ifdef Util__GetNextToken1
FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextToken(char *,short *,char *),Util__GetNextToken1);
#endif
#ifdef Util__GetNextToken2
FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextToken(char *,char *,char *),Util__GetNextToken2);
#endif
#ifdef Util__GetNextToken3
FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextToken(char *,unsigned char *,char *),Util__GetNextToken3);
#endif
#ifdef EQUtil__FormatCharName
FUNCTION_AT_ADDRESS(char * __cdecl EQUtil::FormatCharName(char *,char *,int),EQUtil__FormatCharName);
#endif
#ifdef EQWorldData__EQWorldData
FUNCTION_AT_ADDRESS( EQWorldData::EQWorldData(void),EQWorldData__EQWorldData);
#endif
#ifdef EQWorldData__AddZone
//FUNCTION_AT_ADDRESS(bool const  EQWorldData::AddZone(enum EQExpansion,enum EQZoneIndex,char const *,char const *,int,unsigned long,int,int),EQWorldData__AddZone);
#endif
#ifdef EQWorldData__AdvanceTime
FUNCTION_AT_ADDRESS(void  EQWorldData::AdvanceTime(unsigned int),EQWorldData__AdvanceTime);
#endif
#ifdef EQWorldData__CurrentGameTime
FUNCTION_AT_ADDRESS(void  EQWorldData::CurrentGameTime(char *),EQWorldData__CurrentGameTime);
#endif
#ifdef EQWorldData__GetFullZoneName
//FUNCTION_AT_ADDRESS(void  EQWorldData::GetFullZoneName(enum EQZoneIndex,char *),EQWorldData__GetFullZoneName);
#endif
#ifdef EQWorldData__ExpansionZone
//FUNCTION_AT_ADDRESS(enum EQExpansion const  EQWorldData::ExpansionZone(enum EQZoneIndex)const ,EQWorldData__ExpansionZone);
#endif
#ifdef EQWorldData__IsFlagSet
//FUNCTION_AT_ADDRESS(bool  EQWorldData::IsFlagSet(enum EQZoneIndex,unsigned long)const,EQWorldData__IsFlagSet);
#endif
#ifdef EQWorldData__IsNewbieZone
//FUNCTION_AT_ADDRESS(bool  EQWorldData::IsNewbieZone(enum EQZoneIndex)const,EQWorldData__IsNewbieZone);
#endif
#ifdef EQWorldData__IsNoBindZone
//FUNCTION_AT_ADDRESS(bool  EQWorldData::IsNoBindZone(enum EQZoneIndex)const,EQWorldData__IsNoBindZone);
#endif
#ifdef EQWorldData__IsNoAirZone
//FUNCTION_AT_ADDRESS(bool  EQWorldData::IsNoAirZone(enum EQZoneIndex)const,EQWorldData__IsNoAirZone);
#endif
#ifdef EQWorldData__GetMinLevel
//FUNCTION_AT_ADDRESS(int  EQWorldData::GetMinLevel(enum EQZoneIndex)const,EQWorldData__GetMinLevel);
#endif
#ifdef EQWorldData__GetGeometryNameFromIndex
//FUNCTION_AT_ADDRESS(bool  EQWorldData::GetGeometryNameFromIndex(enum EQZoneIndex,char *)const ,EQWorldData__GetGeometryNameFromIndex);
#endif
#ifdef EQWorldData__GetIndexFromZoneName
//FUNCTION_AT_ADDRESS(enum EQZoneIndex  EQWorldData::GetIndexFromZoneName(char const *)const ,EQWorldData__GetIndexFromZoneName);
#endif
#ifdef EQZoneInfo__EQZoneInfo
//FUNCTION_AT_ADDRESS( EQZoneInfo::EQZoneInfo(enum EQExpansion,enum EQZoneIndex,char const *,char const *,int,unsigned long,int,int),EQZoneInfo__EQZoneInfo);
#endif
#ifdef CEverQuest__ChatServerGiveTime
FUNCTION_AT_ADDRESS(void  CEverQuest::ChatServerGiveTime(void),CEverQuest__ChatServerGiveTime);
#endif
#ifdef CEverQuest__ChatServerNotificationAdd
FUNCTION_AT_ADDRESS(void  CEverQuest::ChatServerNotificationAdd(bool,char *,char *,int),CEverQuest__ChatServerNotificationAdd);
#endif
#ifdef CEverQuest__ChatServerNotificationFlush
FUNCTION_AT_ADDRESS(void  CEverQuest::ChatServerNotificationFlush(void),CEverQuest__ChatServerNotificationFlush);
#endif
#ifdef CEverQuest__ChatServerConnect
FUNCTION_AT_ADDRESS(void  CEverQuest::ChatServerConnect(char *,int,char *,char *),CEverQuest__ChatServerConnect);
#endif
#ifdef CEverQuest__ChatServerMessage
FUNCTION_AT_ADDRESS(void  CEverQuest::ChatServerMessage(char *),CEverQuest__ChatServerMessage);
#endif
#ifdef CEverQuest__ChatServerDisconnect
FUNCTION_AT_ADDRESS(void  CEverQuest::ChatServerDisconnect(void),CEverQuest__ChatServerDisconnect);
#endif
#ifdef CEverQuest__ResetVisionRGBs
FUNCTION_AT_ADDRESS(void  CEverQuest::ResetVisionRGBs(void),CEverQuest__ResetVisionRGBs);
#endif
#ifdef CEverQuest__GetMaxLightRadius
FUNCTION_AT_ADDRESS(float  CEverQuest::GetMaxLightRadius(void),CEverQuest__GetMaxLightRadius);
#endif
#ifdef CEverQuest__LoadStringTables
FUNCTION_AT_ADDRESS(void  CEverQuest::LoadStringTables(void),CEverQuest__LoadStringTables);
#endif
#ifdef CEverQuest__CEverQuest
FUNCTION_AT_ADDRESS( CEverQuest::CEverQuest(struct HWND__ *),CEverQuest__CEverQuest);
#endif
#ifdef CEverQuest__dCEverQuest
FUNCTION_AT_ADDRESS( CEverQuest::~CEverQuest(void),CEverQuest__dCEverQuest);
#endif
#ifdef CEverQuest__ProcessMBox
FUNCTION_AT_ADDRESS(int  CEverQuest::ProcessMBox(void),CEverQuest__ProcessMBox);
#endif
#ifdef CEverQuest__UseCharge
FUNCTION_AT_ADDRESS(void  CEverQuest::UseCharge(unsigned long),CEverQuest__UseCharge);
#endif
#ifdef CEverQuest__LeaveGuildMaster
FUNCTION_AT_ADDRESS(void  CEverQuest::LeaveGuildMaster(void),CEverQuest__LeaveGuildMaster);
#endif
#ifdef CEverQuest__LeaveBankMode
FUNCTION_AT_ADDRESS(void  CEverQuest::LeaveBankMode(bool),CEverQuest__LeaveBankMode);
#endif
#ifdef CEverQuest__ReportDeath
FUNCTION_AT_ADDRESS(void  CEverQuest::ReportDeath(struct _EQPlayerDeath *),CEverQuest__ReportDeath);
#endif
#ifdef CEverQuest__SetDefaultDamageDescByRace
FUNCTION_AT_ADDRESS(void  CEverQuest::SetDefaultDamageDescByRace(char *,int,unsigned char),CEverQuest__SetDefaultDamageDescByRace);
#endif
#ifdef CEverQuest__ReportSuccessfulHit
FUNCTION_AT_ADDRESS(void  CEverQuest::ReportSuccessfulHit(struct _EQSuccessfulHit *,unsigned char,int),CEverQuest__ReportSuccessfulHit);
#endif
#ifdef CEverQuest__GetCombatSound
FUNCTION_AT_ADDRESS(int  CEverQuest::GetCombatSound(class EQPlayer *,class EQPlayer *),CEverQuest__GetCombatSound);
#endif
#ifdef CEverQuest__LocalDeath
FUNCTION_AT_ADDRESS(void  CEverQuest::LocalDeath(struct _EQPlayerDeath *,unsigned char),CEverQuest__LocalDeath);
#endif
#ifdef CEverQuest__PrepareLocalPCForRepop
FUNCTION_AT_ADDRESS(void  CEverQuest::PrepareLocalPCForRepop(void),CEverQuest__PrepareLocalPCForRepop);
#endif
#ifdef CEverQuest__SavePCForce
FUNCTION_AT_ADDRESS(void  CEverQuest::SavePCForce(int),CEverQuest__SavePCForce);
#endif
#ifdef CEverQuest__StartCasting
FUNCTION_AT_ADDRESS(void  CEverQuest::StartCasting(void *),CEverQuest__StartCasting);
#endif
#ifdef CEverQuest__Consider
FUNCTION_AT_ADDRESS(void  CEverQuest::Consider(class EQPlayer *,void *),CEverQuest__Consider);
#endif
#ifdef CEverQuest__GetClassDesc
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetClassDesc(int),CEverQuest__GetClassDesc);
#endif
#ifdef CEverQuest__GetClassThreeLetterCode
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetClassThreeLetterCode(int),CEverQuest__GetClassThreeLetterCode);
#endif
#ifdef CEverQuest__GetItemClassDesc
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetItemClassDesc(int),CEverQuest__GetItemClassDesc);
#endif
#ifdef CEverQuest__GetBodyTypeDesc
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetBodyTypeDesc(int),CEverQuest__GetBodyTypeDesc);
#endif
#ifdef CEverQuest__GetLangDesc
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetLangDesc(int),CEverQuest__GetLangDesc);
#endif
#ifdef CEverQuest__GetRaceDesc
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetRaceDesc(int),CEverQuest__GetRaceDesc);
#endif
#ifdef CEverQuest__GetDeityDesc
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetDeityDesc(int),CEverQuest__GetDeityDesc);
#endif
#ifdef CEverQuest__GuildInvite
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildInvite(char *,char *),CEverQuest__GuildInvite);
#endif
#ifdef CEverQuest__GuildRemove
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildRemove(char *),CEverQuest__GuildRemove);
#endif
#ifdef CEverQuest__GuildDelete
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildDelete(void),CEverQuest__GuildDelete);
#endif
#ifdef CEverQuest__GuildStatus
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildStatus(char *),CEverQuest__GuildStatus);
#endif
#ifdef CEverQuest__GuildLeader
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildLeader(char *),CEverQuest__GuildLeader);
#endif
#ifdef CEverQuest__GuildSay
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildSay(char *),CEverQuest__GuildSay);
#endif
#ifdef CEverQuest__Who
FUNCTION_AT_ADDRESS(void  CEverQuest::Who(char *),CEverQuest__Who);
#endif
#ifdef CEverQuest__GetInnateDesc
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetInnateDesc(int),CEverQuest__GetInnateDesc);
#endif
#ifdef CEverQuest__InviteOk
FUNCTION_AT_ADDRESS(void  CEverQuest::InviteOk(char *),CEverQuest__InviteOk);
#endif
#ifdef CEverQuest__doUnInvite
FUNCTION_AT_ADDRESS(void  CEverQuest::doUnInvite(char *),CEverQuest__doUnInvite);
#endif
#ifdef CEverQuest__Invite
FUNCTION_AT_ADDRESS(void  CEverQuest::Invite(int),CEverQuest__Invite);
#endif
#ifdef CEverQuest__doInvite
FUNCTION_AT_ADDRESS(void  CEverQuest::doInvite(unsigned __int32,char *),CEverQuest__doInvite);
#endif
#ifdef CEverQuest__Follow
FUNCTION_AT_ADDRESS(void  CEverQuest::Follow(void),CEverQuest__Follow);
#endif
#ifdef CEverQuest__Disband
FUNCTION_AT_ADDRESS(void  CEverQuest::Disband(void),CEverQuest__Disband);
#endif
#ifdef CEverQuest__GuildWar
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildWar(char *,int),CEverQuest__GuildWar);
#endif
#ifdef CEverQuest__GuildPeace
FUNCTION_AT_ADDRESS(void  CEverQuest::GuildPeace(char *),CEverQuest__GuildPeace);
#endif
#ifdef CEverQuest__Sit
FUNCTION_AT_ADDRESS(void  CEverQuest::Sit(void),CEverQuest__Sit);
#endif
#ifdef CEverQuest__Camp
FUNCTION_AT_ADDRESS(void  CEverQuest::Camp(void),CEverQuest__Camp);
#endif
#ifdef CEverQuest__DropHeldItemOnGround
FUNCTION_AT_ADDRESS(void  CEverQuest::DropHeldItemOnGround(int),CEverQuest__DropHeldItemOnGround);
#endif
#ifdef CEverQuest__MoveMoney
FUNCTION_AT_ADDRESS(int  CEverQuest::MoveMoney(int,int,int,int,int,bool),CEverQuest__MoveMoney);
#endif
#ifdef CEverQuest__DropHeldMoneyOnGround
FUNCTION_AT_ADDRESS(void  CEverQuest::DropHeldMoneyOnGround(int),CEverQuest__DropHeldMoneyOnGround);
#endif
#ifdef CEverQuest__LMouseUp
FUNCTION_AT_ADDRESS(void  CEverQuest::LMouseUp(int,int),CEverQuest__LMouseUp);
#endif
#ifdef CEverQuest__LeftClickedOnPlayer
FUNCTION_AT_ADDRESS(void  CEverQuest::LeftClickedOnPlayer(class EQPlayer *),CEverQuest__LeftClickedOnPlayer);
#endif
#ifdef CEverQuest__DropItemOrMoneyOnPlayer
FUNCTION_AT_ADDRESS(void  CEverQuest::DropItemOrMoneyOnPlayer(class EQPlayer *),CEverQuest__DropItemOrMoneyOnPlayer);
#endif
#ifdef CEverQuest__RightClickedOnPlayer
FUNCTION_AT_ADDRESS(void  CEverQuest::RightClickedOnPlayer(class EQPlayer *),CEverQuest__RightClickedOnPlayer);
#endif
#ifdef CEverQuest__send_social
FUNCTION_AT_ADDRESS(void  CEverQuest::send_social(int,char *,char *),CEverQuest__send_social);
#endif
#ifdef CEverQuest__SavePC
FUNCTION_AT_ADDRESS(void  CEverQuest::SavePC(int,int,unsigned char),CEverQuest__SavePC);
#endif
#ifdef CEverQuest__send_tell
FUNCTION_AT_ADDRESS(void  CEverQuest::send_tell(char *,char *),CEverQuest__send_tell);
#endif
#ifdef CEverQuest__send_petition
FUNCTION_AT_ADDRESS(void  CEverQuest::send_petition(void),CEverQuest__send_petition);
#endif
#ifdef CEverQuest__send_private
FUNCTION_AT_ADDRESS(void  CEverQuest::send_private(void),CEverQuest__send_private);
#endif
#ifdef CEverQuest__WriteIntToClientINI
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteIntToClientINI(int,char *,char *),CEverQuest__WriteIntToClientINI);
#endif
#ifdef CEverQuest__WriteFloatToClientINI
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteFloatToClientINI(float,char *,char *),CEverQuest__WriteFloatToClientINI);
#endif
#ifdef CEverQuest__WriteBoolToClientINI
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteBoolToClientINI(bool,char *,char *),CEverQuest__WriteBoolToClientINI);
#endif
#ifdef CEverQuest__WriteStringToClientINI
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteStringToClientINI(char *,char *,char *),CEverQuest__WriteStringToClientINI);
#endif
#ifdef CEverQuest__ReadClientINIString
FUNCTION_AT_ADDRESS(char *  CEverQuest::ReadClientINIString(char *,char *,char *,char *,int),CEverQuest__ReadClientINIString);
#endif
#ifdef CEverQuest__ReadClientINIInt
FUNCTION_AT_ADDRESS(int  CEverQuest::ReadClientINIInt(char *,char *,int),CEverQuest__ReadClientINIInt);
#endif
#ifdef CEverQuest__ReadClientINIFloat
FUNCTION_AT_ADDRESS(float  CEverQuest::ReadClientINIFloat(char *,char *,float),CEverQuest__ReadClientINIFloat);
#endif
#ifdef CEverQuest__ReadClientINIBool
FUNCTION_AT_ADDRESS(bool  CEverQuest::ReadClientINIBool(char *,char *,bool),CEverQuest__ReadClientINIBool);
#endif
#ifdef CEverQuest__WriteIntToUIINI
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteIntToUIINI(int,char *,char *),CEverQuest__WriteIntToUIINI);
#endif
#ifdef CEverQuest__WriteBoolToUIINI
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteBoolToUIINI(bool,char *,char *),CEverQuest__WriteBoolToUIINI);
#endif
#ifdef CEverQuest__WriteStringToUIINI
FUNCTION_AT_ADDRESS(void  CEverQuest::WriteStringToUIINI(char *,char *,char *),CEverQuest__WriteStringToUIINI);
#endif
#ifdef CEverQuest__ReadUIINIString
FUNCTION_AT_ADDRESS(char *  CEverQuest::ReadUIINIString(char *,char *,char *,char *,int),CEverQuest__ReadUIINIString);
#endif
#ifdef CEverQuest__ReadUIINIInt
FUNCTION_AT_ADDRESS(int  CEverQuest::ReadUIINIInt(char *,char *,int),CEverQuest__ReadUIINIInt);
#endif
#ifdef CEverQuest__ReadUIINIBool
FUNCTION_AT_ADDRESS(bool  CEverQuest::ReadUIINIBool(char *,char *,bool),CEverQuest__ReadUIINIBool);
#endif
#ifdef CEverQuest__SaveCamerasToINI
FUNCTION_AT_ADDRESS(void  CEverQuest::SaveCamerasToINI(void),CEverQuest__SaveCamerasToINI);
#endif
#ifdef CEverQuest__saveOptions
FUNCTION_AT_ADDRESS(void  CEverQuest::saveOptions(void),CEverQuest__saveOptions);
#endif
#ifdef CEverQuest__saveOptions2
FUNCTION_AT_ADDRESS(void  CEverQuest::saveOptions2(void),CEverQuest__saveOptions2);
#endif
#ifdef CEverQuest__send_update_filters
FUNCTION_AT_ADDRESS(void  CEverQuest::send_update_filters(void),CEverQuest__send_update_filters);
#endif
#ifdef CEverQuest__loadOptions
FUNCTION_AT_ADDRESS(void  CEverQuest::loadOptions(void),CEverQuest__loadOptions);
#endif
#ifdef CEverQuest__DoSplit
FUNCTION_AT_ADDRESS(void  CEverQuest::DoSplit(char *),CEverQuest__DoSplit);
#endif
#ifdef CEverQuest__BeingIgnored
FUNCTION_AT_ADDRESS(int  CEverQuest::BeingIgnored(char *),CEverQuest__BeingIgnored);
#endif
#ifdef CEverQuest__IsFriend
FUNCTION_AT_ADDRESS(int  CEverQuest::IsFriend(char const *),CEverQuest__IsFriend);
#endif
#ifdef CEverQuest__ToggleAutoSplit
FUNCTION_AT_ADDRESS(void  CEverQuest::ToggleAutoSplit(void),CEverQuest__ToggleAutoSplit);
#endif
#ifdef CEverQuest__procMouse
FUNCTION_AT_ADDRESS(void  CEverQuest::procMouse(int),CEverQuest__procMouse);
#endif
#ifdef CEverQuest__StripShipName
FUNCTION_AT_ADDRESS(char *  CEverQuest::StripShipName(char *,char *),CEverQuest__StripShipName);
#endif
#ifdef CEverQuest__trimName
FUNCTION_AT_ADDRESS(char *  CEverQuest::trimName(char *),CEverQuest__trimName);
#endif
#ifdef CEverQuest__CancelSneakHide
FUNCTION_AT_ADDRESS(void  CEverQuest::CancelSneakHide(void),CEverQuest__CancelSneakHide);
#endif
#ifdef CEverQuest__stripName
FUNCTION_AT_ADDRESS(char *  CEverQuest::stripName(char *),CEverQuest__stripName);
#endif
#ifdef CEverQuest__clr_chat_input
FUNCTION_AT_ADDRESS(void  CEverQuest::clr_chat_input(void),CEverQuest__clr_chat_input);
#endif
#ifdef CEverQuest__dsp_chat
FUNCTION_AT_ADDRESS(void  CEverQuest::dsp_chat(char const *,int,bool,bool),CEverQuest__dsp_chat);
void CEverQuest::dsp_chat(char const *a, int b, bool c) { dsp_chat(a, b, c, 1); }
#endif
#ifdef CEverQuest__DoTellWindow
FUNCTION_AT_ADDRESS(void CEverQuest::DoTellWindow(char *message,char *name,char *name2,void *unknown,int color,bool b),CEverQuest__DoTellWindow);
#endif
#ifdef CEverQuest__dsp_chat1
FUNCTION_AT_ADDRESS(void  CEverQuest::dsp_chat(char const *),CEverQuest__dsp_chat1);
#endif
#ifdef CEverQuest__DoPercentConvert
FUNCTION_AT_ADDRESS(void  CEverQuest::DoPercentConvert(char *,bool),CEverQuest__DoPercentConvert);
#endif
#ifdef CEverQuest__Emote
FUNCTION_AT_ADDRESS(void  CEverQuest::Emote(void),CEverQuest__Emote);
#endif
#ifdef CEverQuest__send_broadcast
FUNCTION_AT_ADDRESS(void  CEverQuest::send_broadcast(void),CEverQuest__send_broadcast);
#endif
#ifdef CEverQuest__send_chat
FUNCTION_AT_ADDRESS(void  CEverQuest::send_chat(void),CEverQuest__send_chat);
#endif
#ifdef CEverQuest__send_gsay
FUNCTION_AT_ADDRESS(void  CEverQuest::send_gsay(void),CEverQuest__send_gsay);
#endif
#ifdef CEverQuest__reqChannel
FUNCTION_AT_ADDRESS(void  CEverQuest::reqChannel(void),CEverQuest__reqChannel);
#endif
#ifdef CEverQuest__send_shout
FUNCTION_AT_ADDRESS(void  CEverQuest::send_shout(void),CEverQuest__send_shout);
#endif
#ifdef CEverQuest__send_auction
FUNCTION_AT_ADDRESS(void  CEverQuest::send_auction(void),CEverQuest__send_auction);
#endif
#ifdef CEverQuest__send_ooc
FUNCTION_AT_ADDRESS(void  CEverQuest::send_ooc(void),CEverQuest__send_ooc);
#endif
#ifdef CEverQuest__GetCurrentLanguage
FUNCTION_AT_ADDRESS(int  CEverQuest::GetCurrentLanguage(void),CEverQuest__GetCurrentLanguage);
#endif
#ifdef CEverQuest__SendNewText
FUNCTION_AT_ADDRESS(void  CEverQuest::SendNewText(int,char *,char *),CEverQuest__SendNewText);
#endif
#ifdef CEverQuest__DisplayScreen
FUNCTION_AT_ADDRESS(void  CEverQuest::DisplayScreen(char *),CEverQuest__DisplayScreen);
#endif
#ifdef CEverQuest__IsValidName
FUNCTION_AT_ADDRESS(int  CEverQuest::IsValidName(char *),CEverQuest__IsValidName);
#endif
#ifdef CEverQuest__DoNewCharacterCreation
FUNCTION_AT_ADDRESS(void  CEverQuest::DoNewCharacterCreation(void),CEverQuest__DoNewCharacterCreation);
#endif
#ifdef CEverQuest__RemoveCharacterOptionFile
FUNCTION_AT_ADDRESS(void  CEverQuest::RemoveCharacterOptionFile(char *),CEverQuest__RemoveCharacterOptionFile);
#endif
#ifdef CEverQuest__SetDefaultGameValues
FUNCTION_AT_ADDRESS(void  CEverQuest::SetDefaultGameValues(void),CEverQuest__SetDefaultGameValues);
#endif
#ifdef CEverQuest__SetPlayerAppearanceFromPInfo
FUNCTION_AT_ADDRESS(void  CEverQuest::SetPlayerAppearanceFromPInfo(class EQPlayer *,int,bool),CEverQuest__SetPlayerAppearanceFromPInfo);
#endif
#ifdef CEverQuest__DoCharacterSelection
FUNCTION_AT_ADDRESS(void  CEverQuest::DoCharacterSelection(void),CEverQuest__DoCharacterSelection);
#endif
#ifdef CEverQuest__DoLogin
FUNCTION_AT_ADDRESS(int  CEverQuest::DoLogin(struct HWND__ *,struct HINSTANCE__ *),CEverQuest__DoLogin);
#endif
#ifdef CEverQuest__SetupCharSelectCamera
FUNCTION_AT_ADDRESS(void  CEverQuest::SetupCharSelectCamera(void),CEverQuest__SetupCharSelectCamera);
#endif
#ifdef CEverQuest__CreateDataSubdirectories
FUNCTION_AT_ADDRESS(void  CEverQuest::CreateDataSubdirectories(void),CEverQuest__CreateDataSubdirectories);
#endif
#ifdef CEverQuest__CreateFilenameServerCode
FUNCTION_AT_ADDRESS(void  CEverQuest::CreateFilenameServerCode(char *),CEverQuest__CreateFilenameServerCode);
#endif
#ifdef CEverQuest__CreateIniFilenames
FUNCTION_AT_ADDRESS(void  CEverQuest::CreateIniFilenames(void),CEverQuest__CreateIniFilenames);
#endif
#ifdef CEverQuest__StartNetworkGame
FUNCTION_AT_ADDRESS(void  CEverQuest::StartNetworkGame(struct HWND__ *,struct HINSTANCE__ *,char *),CEverQuest__StartNetworkGame);
#endif
#ifdef CEverQuest__GetZoneInfoFromNetwork
FUNCTION_AT_ADDRESS(void  CEverQuest::GetZoneInfoFromNetwork(char *),CEverQuest__GetZoneInfoFromNetwork);
#endif
#ifdef CEverQuest__EnterZone
FUNCTION_AT_ADDRESS(void  CEverQuest::EnterZone(struct HWND__ *),CEverQuest__EnterZone);
#endif
#ifdef CEverQuest__Surname
FUNCTION_AT_ADDRESS(void  CEverQuest::Surname(char *),CEverQuest__Surname);
#endif
#ifdef CEverQuest__Kill
FUNCTION_AT_ADDRESS(void  CEverQuest::Kill(char *,char *),CEverQuest__Kill);
#endif
#ifdef CEverQuest__UpdateMyAppearance
FUNCTION_AT_ADDRESS(void  CEverQuest::UpdateMyAppearance(void),CEverQuest__UpdateMyAppearance);
#endif
#ifdef CEverQuest__IFoundMyVehicle
FUNCTION_AT_ADDRESS(unsigned char  CEverQuest::IFoundMyVehicle(void),CEverQuest__IFoundMyVehicle);
#endif
#ifdef CEverQuest__ProcessLocalPCIni
FUNCTION_AT_ADDRESS(void  CEverQuest::ProcessLocalPCIni(int),CEverQuest__ProcessLocalPCIni);
#endif
#ifdef CEverQuest__DoMainLoop
FUNCTION_AT_ADDRESS(void  CEverQuest::DoMainLoop(struct HWND__ *),CEverQuest__DoMainLoop);
#endif
#ifdef CEverQuest__ProcessControls
FUNCTION_AT_ADDRESS(void  CEverQuest::ProcessControls(void),CEverQuest__ProcessControls);
#endif
#ifdef CEverQuest__TypingMode
FUNCTION_AT_ADDRESS(int  CEverQuest::TypingMode(void),CEverQuest__TypingMode);
#endif
#ifdef CEverQuest__IsInTypingMode
FUNCTION_AT_ADDRESS(bool  CEverQuest::IsInTypingMode(void),CEverQuest__IsInTypingMode);
#endif
#ifdef CEverQuest__doInspect
FUNCTION_AT_ADDRESS(void  CEverQuest::doInspect(class EQPlayer *),CEverQuest__doInspect);
#endif
#ifdef __do_loot
FUNCTION_AT_ADDRESS(void  CEverQuest::doLoot(void),__do_loot);
#endif
#ifdef CEverQuest__SendLightInfo
FUNCTION_AT_ADDRESS(void  CEverQuest::SendLightInfo(class EQPlayer *,unsigned char),CEverQuest__SendLightInfo);
#endif
#ifdef CEverQuest__SetTimedFog
FUNCTION_AT_ADDRESS(void  CEverQuest::SetTimedFog(int),CEverQuest__SetTimedFog);
#endif
#ifdef CEverQuest__ProcessGame
FUNCTION_AT_ADDRESS(void  CEverQuest::ProcessGame(struct HWND__ *,struct HINSTANCE__ *),CEverQuest__ProcessGame);
#endif
#ifdef CEverQuest__DoLoadScreenProgressBar
FUNCTION_AT_ADDRESS(void __cdecl CEverQuest::DoLoadScreenProgressBar(int,char const *,...),CEverQuest__DoLoadScreenProgressBar);
#endif
#ifdef CEverQuest__DoLoadScreen
FUNCTION_AT_ADDRESS(void  CEverQuest::DoLoadScreen(int),CEverQuest__DoLoadScreen);
#endif
#ifdef CEverQuest__CleanupBadFiles
FUNCTION_AT_ADDRESS(void  CEverQuest::CleanupBadFiles(void),CEverQuest__CleanupBadFiles);
#endif
#ifdef CEverQuest__CreateInitialActors
FUNCTION_AT_ADDRESS(void  CEverQuest::CreateInitialActors(void),CEverQuest__CreateInitialActors);
#endif
#ifdef CEverQuest__GetSndDriver
FUNCTION_AT_ADDRESS(void  CEverQuest::GetSndDriver(void),CEverQuest__GetSndDriver);
#endif
#ifdef CEverQuest__InterpretCmd
FUNCTION_AT_ADDRESS(void  CEverQuest::InterpretCmd(class EQPlayer *,char *),CEverQuest__InterpretCmd);
#endif
#ifdef CEverQuest__GrabFirstWord
FUNCTION_AT_ADDRESS(char *  CEverQuest::GrabFirstWord(char *,char *),CEverQuest__GrabFirstWord);
#endif
#ifdef CEverQuest__GrabFirstWord2
FUNCTION_AT_ADDRESS(char *  CEverQuest::GrabFirstWord2(char *,char *,int),CEverQuest__GrabFirstWord2);
#endif
#ifdef CEverQuest__CopyFirstWord
FUNCTION_AT_ADDRESS(void  CEverQuest::CopyFirstWord(char *,char *),CEverQuest__CopyFirstWord);
#endif
#ifdef CEverQuest__ApplyPoison
FUNCTION_AT_ADDRESS(void  CEverQuest::ApplyPoison(unsigned long),CEverQuest__ApplyPoison);
#endif
#ifdef CEverQuest__DeacSpellScreen
FUNCTION_AT_ADDRESS(void  CEverQuest::DeacSpellScreen(void),CEverQuest__DeacSpellScreen);
#endif
#ifdef CEverQuest__IsZoneAvailable
//FUNCTION_AT_ADDRESS(enum ZONE_REQ_STATUS  CEverQuest::IsZoneAvailable(char *,enum EQZoneIndex,enum ZONE_REQ_REASON),CEverQuest__IsZoneAvailable);
#endif
#ifdef CEverQuest__MoveToZone
FUNCTION_AT_ADDRESS(void CEverQuest::MoveToZone(int EQZoneIndex,char *,int,int ZONE_REQ_REASON,float,float,float,int),CEverQuest__MoveToZone);
#endif
#ifdef CEverQuest__MoveToZone1
//FUNCTION_AT_ADDRESS(void  CEverQuest::MoveToZone(char *,char *,int,enum ZONE_REQ_REASON),CEverQuest__MoveToZone1);
#endif
#ifdef CEverQuest__LMouseDown
FUNCTION_AT_ADDRESS(void  CEverQuest::LMouseDown(int,int),CEverQuest__LMouseDown);
#endif
#ifdef CEverQuest__RMouseDown
FUNCTION_AT_ADDRESS(void  CEverQuest::RMouseDown(int,int),CEverQuest__RMouseDown);
#endif
#ifdef CEverQuest__RMouseUp
FUNCTION_AT_ADDRESS(void  CEverQuest::RMouseUp(int,int),CEverQuest__RMouseUp);
#endif
#ifdef CEverQuest__MouseWheelScrolled
FUNCTION_AT_ADDRESS(void  CEverQuest::MouseWheelScrolled(int),CEverQuest__MouseWheelScrolled);
#endif
#ifdef CEverQuest__ClickedSwitch
FUNCTION_AT_ADDRESS(class EQSwitch *  CEverQuest::ClickedSwitch(int,int),CEverQuest__ClickedSwitch);
#endif
#ifdef CEverQuest__ClickedPlayer
FUNCTION_AT_ADDRESS(class EQPlayer *  CEverQuest::ClickedPlayer(int,int),CEverQuest__ClickedPlayer);
#endif
#ifdef CEverQuest__WhatTimeIsIt
FUNCTION_AT_ADDRESS(void  CEverQuest::WhatTimeIsIt(void),CEverQuest__WhatTimeIsIt);
#endif
#ifdef CEverQuest__FreeSwitches
FUNCTION_AT_ADDRESS(void  CEverQuest::FreeSwitches(void),CEverQuest__FreeSwitches);
#endif
#ifdef CEverQuest__LoadSwitchesNonAvatar
//FUNCTION_AT_ADDRESS(void  CEverQuest::LoadSwitchesNonAvatar(enum EQZoneIndex),CEverQuest__LoadSwitchesNonAvatar);
#endif
#ifdef CEverQuest__SetLfgPlayerStatus
FUNCTION_AT_ADDRESS(void  CEverQuest::SetLfgPlayerStatus(struct LfgPlayerStatus *),CEverQuest__SetLfgPlayerStatus);
#endif
#ifdef CEverQuest__SetLfgGroupStatus
FUNCTION_AT_ADDRESS(void  CEverQuest::SetLfgGroupStatus(struct LfgGroupStatus *),CEverQuest__SetLfgGroupStatus);
#endif
#ifdef CEverQuest__IssueLfgPlayerQuery
FUNCTION_AT_ADDRESS(void  CEverQuest::IssueLfgPlayerQuery(struct LfgPlayerQuery *),CEverQuest__IssueLfgPlayerQuery);
#endif
#ifdef CEverQuest__IssueLfgGroupQuery
FUNCTION_AT_ADDRESS(void  CEverQuest::IssueLfgGroupQuery(struct LfgGroupQuery *),CEverQuest__IssueLfgGroupQuery);
#endif
#ifdef CEverQuest__IssuePetCommand
//FUNCTION_AT_ADDRESS(void  CEverQuest::IssuePetCommand(enum PetCommandType,int),CEverQuest__IssuePetCommand);
#endif
#ifdef CEverQuest__LootCorpse
FUNCTION_AT_ADDRESS(int  CEverQuest::LootCorpse(class EQPlayer *,int),CEverQuest__LootCorpse);
#endif
#ifdef CEverQuest__loadSoundsGame
FUNCTION_AT_ADDRESS(void  CEverQuest::loadSoundsGame(void),CEverQuest__loadSoundsGame);
#endif
#ifdef CEverQuest__GetSingleMessage
FUNCTION_AT_ADDRESS(char *  CEverQuest::GetSingleMessage(unsigned __int32,int,int *,char *),CEverQuest__GetSingleMessage);
#endif
#ifdef CEverQuest__SetGameState
FUNCTION_AT_ADDRESS(void  CEverQuest::SetGameState(int),CEverQuest__SetGameState);
#endif
#ifdef CEverQuest__IsOkToTransact
FUNCTION_AT_ADDRESS(bool  CEverQuest::IsOkToTransact(void),CEverQuest__IsOkToTransact);
#endif
#ifdef CEverQuest__SortSpellLoadouts
FUNCTION_AT_ADDRESS(void  CEverQuest::SortSpellLoadouts(void),CEverQuest__SortSpellLoadouts);
#endif
#ifdef CEverQuest__saveCustom
FUNCTION_AT_ADDRESS(void  CEverQuest::saveCustom(void),CEverQuest__saveCustom);
#endif
#ifdef CEverQuest__loadCustomFromINI
FUNCTION_AT_ADDRESS(void  CEverQuest::loadCustomFromINI(char *),CEverQuest__loadCustomFromINI);
#endif
#ifdef CEverQuest__loadCustom
FUNCTION_AT_ADDRESS(void  CEverQuest::loadCustom(void),CEverQuest__loadCustom);
#endif
#ifdef CEverQuest__initCustom
FUNCTION_AT_ADDRESS(void  CEverQuest::initCustom(void),CEverQuest__initCustom);
#endif
#ifdef _EverQuestinfo__SetAutoAttack
FUNCTION_AT_ADDRESS(void  _EverQuestinfo::SetAutoAttack(bool),_EverQuestinfo__SetAutoAttack);
#endif
#ifdef GrammarRulesClass__GrammarRulesClass
FUNCTION_AT_ADDRESS( GrammarRulesClass::GrammarRulesClass(void),GrammarRulesClass__GrammarRulesClass);
#endif
#ifdef GrammarRulesClass__Parse
FUNCTION_AT_ADDRESS(char *  GrammarRulesClass::Parse(char *),GrammarRulesClass__Parse);
#endif
#ifdef GrammarRulesClass__Resolve
FUNCTION_AT_ADDRESS(char *  GrammarRulesClass::Resolve(int,int,char *,char *),GrammarRulesClass__Resolve);
#endif
#ifdef GrammarRulesClass__RuleEn1
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleEn1(char *,char *),GrammarRulesClass__RuleEn1);
#endif
#ifdef GrammarRulesClass__RuleEn2
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleEn2(char *,char *),GrammarRulesClass__RuleEn2);
#endif
#ifdef GrammarRulesClass__RuleEn3
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleEn3(char *,char *,char *,char *),GrammarRulesClass__RuleEn3);
#endif
#ifdef GrammarRulesClass__RuleEn4
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleEn4(char *,char *,char *,char *),GrammarRulesClass__RuleEn4);
#endif
#ifdef GrammarRulesClass__RuleKo1
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleKo1(char *,char *,char *,char *),GrammarRulesClass__RuleKo1);
#endif
#ifdef GrammarRulesClass__RuleFr1
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleFr1(char *,char *,char *,char *),GrammarRulesClass__RuleFr1);
#endif
#ifdef GrammarRulesClass__RuleDe1
FUNCTION_AT_ADDRESS(void  GrammarRulesClass::RuleDe1(char *,char *),GrammarRulesClass__RuleDe1);
#endif
#ifdef KeypressHandler__KeypressHandler
FUNCTION_AT_ADDRESS( KeypressHandler::KeypressHandler(void),KeypressHandler__KeypressHandler);
#endif
#ifdef KeypressHandler__AttachKeyToEqCommand
FUNCTION_AT_ADDRESS(bool  KeypressHandler::AttachKeyToEqCommand(class KeyCombo const &,unsigned int),KeypressHandler__AttachKeyToEqCommand);
#endif
#ifdef KeypressHandler__AttachAltKeyToEqCommand
FUNCTION_AT_ADDRESS(bool  KeypressHandler::AttachAltKeyToEqCommand(class KeyCombo const &,unsigned int),KeypressHandler__AttachAltKeyToEqCommand);
#endif
#ifdef KeypressHandler__HandleKeyDown
FUNCTION_AT_ADDRESS(bool  KeypressHandler::HandleKeyDown(class KeyCombo const &),KeypressHandler__HandleKeyDown);
#endif
#ifdef KeypressHandler__HandleKeyUp
FUNCTION_AT_ADDRESS(bool  KeypressHandler::HandleKeyUp(class KeyCombo const &),KeypressHandler__HandleKeyUp);
#endif
#ifdef KeypressHandler__GetKeyAttachedToEqCommand
FUNCTION_AT_ADDRESS(class KeyCombo const &  KeypressHandler::GetKeyAttachedToEqCommand(unsigned int)const ,KeypressHandler__GetKeyAttachedToEqCommand);
#endif
#ifdef KeypressHandler__GetAltKeyAttachedToEqCommand
FUNCTION_AT_ADDRESS(class KeyCombo const &  KeypressHandler::GetAltKeyAttachedToEqCommand(unsigned int)const ,KeypressHandler__GetAltKeyAttachedToEqCommand);
#endif
#ifdef KeypressHandler__ResetKeysToEqDefaults
FUNCTION_AT_ADDRESS(void  KeypressHandler::ResetKeysToEqDefaults(void),KeypressHandler__ResetKeysToEqDefaults);
#endif
#ifdef KeypressHandler__MapKeyToEqCommand
FUNCTION_AT_ADDRESS(bool  KeypressHandler::MapKeyToEqCommand(class KeyCombo const &,int,unsigned int),KeypressHandler__MapKeyToEqCommand);
#endif
#ifdef KeypressHandler__IsReservedKey
FUNCTION_AT_ADDRESS(bool  KeypressHandler::IsReservedKey(class KeyCombo const &)const ,KeypressHandler__IsReservedKey);
#endif
#ifdef KeypressHandler__LoadAndSetKeymappings
FUNCTION_AT_ADDRESS(void  KeypressHandler::LoadAndSetKeymappings(void),KeypressHandler__LoadAndSetKeymappings);
#endif
#ifdef KeypressHandler__LoadKeymapping
FUNCTION_AT_ADDRESS(bool  KeypressHandler::LoadKeymapping(unsigned int,int,class KeyCombo *),KeypressHandler__LoadKeymapping);
#endif
#ifdef KeypressHandler__SaveKeymapping
FUNCTION_AT_ADDRESS(void  KeypressHandler::SaveKeymapping(unsigned int,class KeyCombo const &,int),KeypressHandler__SaveKeymapping);
#endif
#ifdef KeypressHandler__GetEqCommandSaveName
FUNCTION_AT_ADDRESS(class CXStr  KeypressHandler::GetEqCommandSaveName(unsigned int,int)const ,KeypressHandler__GetEqCommandSaveName);
#endif
#ifdef KeypressHandler__LoadAndConvertOldKeymappingFormat
FUNCTION_AT_ADDRESS(bool  KeypressHandler::LoadAndConvertOldKeymappingFormat(unsigned int,int,class KeyCombo *),KeypressHandler__LoadAndConvertOldKeymappingFormat);
#endif
#ifdef KeypressHandler__ClearCommandStateArray
FUNCTION_AT_ADDRESS(void  KeypressHandler::ClearCommandStateArray(void),KeypressHandler__ClearCommandStateArray);
#endif
#ifdef MemoryPoolManager__MemoryPoolManager
FUNCTION_AT_ADDRESS( MemoryPoolManager::MemoryPoolManager(void),MemoryPoolManager__MemoryPoolManager);
#endif
#ifdef MemoryPoolManager__dMemoryPoolManager
FUNCTION_AT_ADDRESS( MemoryPoolManager::~MemoryPoolManager(void),MemoryPoolManager__dMemoryPoolManager);
#endif
#ifdef MemoryPoolManager__Alloc
FUNCTION_AT_ADDRESS(void *  MemoryPoolManager::Alloc(int),MemoryPoolManager__Alloc);
#endif
#ifdef MemoryPoolManager__Free
FUNCTION_AT_ADDRESS(void  MemoryPoolManager::Free(void *),MemoryPoolManager__Free);
#endif
#ifdef PacketPackerManager__SetPriority
FUNCTION_AT_ADDRESS(void  PacketPackerManager::SetPriority(class PacketPacker *,__int64),PacketPackerManager__SetPriority);
#endif
#ifdef PacketPackerManager__RemovePacker
FUNCTION_AT_ADDRESS(void  PacketPackerManager::RemovePacker(class PacketPacker *),PacketPackerManager__RemovePacker);
#endif
#ifdef PacketPackerManager__UnpackGetFirst
FUNCTION_AT_ADDRESS(bool __cdecl PacketPackerManager::UnpackGetFirst(struct PacketPackerState *,unsigned __int32,unsigned char *,int),PacketPackerManager__UnpackGetFirst);
#endif
#ifdef PacketPackerManager__UnpackGetNext
FUNCTION_AT_ADDRESS(bool __cdecl PacketPackerManager::UnpackGetNext(struct PacketPackerState *),PacketPackerManager__UnpackGetNext);
#endif
#ifdef PacketPacker__SendStatUpdate
FUNCTION_AT_ADDRESS(void  PacketPacker::SendStatUpdate(struct _statUpdate *,bool),PacketPacker__SendStatUpdate);
#endif
#ifdef PacketPacker__FlushPositions
FUNCTION_AT_ADDRESS(void  PacketPacker::FlushPositions(void),PacketPacker__FlushPositions);
#endif
#ifdef PacketPacker__SendPacket
FUNCTION_AT_ADDRESS(void  PacketPacker::SendPacket(unsigned __int32,void *,int,bool),PacketPacker__SendPacket);
#endif
#ifdef PacketPacker__AddPacketToBuffer
//FUNCTION_AT_ADDRESS(void  PacketPacker::AddPacketToBuffer(struct PacketPacker::PacketBuffer *,unsigned __int32,void *,int),PacketPacker__AddPacketToBuffer);
#endif
#ifdef PacketPacker__ScheduleUs
FUNCTION_AT_ADDRESS(void  PacketPacker::ScheduleUs(void),PacketPacker__ScheduleUs);
#endif
#ifdef PacketPacker__Flush
FUNCTION_AT_ADDRESS(void  PacketPacker::Flush(void),PacketPacker__Flush);
#endif
#ifdef PacketPacker__FlushBuffer
//FUNCTION_AT_ADDRESS(void  PacketPacker::FlushBuffer(struct PacketPacker::PacketBuffer *),PacketPacker__FlushBuffer);
#endif
#ifdef PacketPacker__Disassociate
FUNCTION_AT_ADDRESS(void  PacketPacker::Disassociate(void),PacketPacker__Disassociate);
#endif
#ifdef CResolutionHandler__Init
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::Init(void),CResolutionHandler__Init);
#endif
#ifdef CResolutionHandler__Shutdown
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::Shutdown(void),CResolutionHandler__Shutdown);
#endif
#ifdef CResolutionHandler__SaveSettings
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::SaveSettings(void),CResolutionHandler__SaveSettings);
#endif
#ifdef CResolutionHandler__ToggleScreenMode
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::ToggleScreenMode(void),CResolutionHandler__ToggleScreenMode);
#endif
#ifdef CResolutionHandler__ChangeToResolution
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::ChangeToResolution(int,int,int,int,int),CResolutionHandler__ChangeToResolution);
#endif
#ifdef CResolutionHandler__UpdateWindowPosition
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::UpdateWindowPosition(void),CResolutionHandler__UpdateWindowPosition);
#endif
#ifdef CResolutionHandler__GetDesktopWidth
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetDesktopWidth(void),CResolutionHandler__GetDesktopWidth);
#endif
#ifdef CResolutionHandler__GetDesktopHeight
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetDesktopHeight(void),CResolutionHandler__GetDesktopHeight);
#endif
#ifdef CResolutionHandler__GetDesktopBitsPerPixel
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetDesktopBitsPerPixel(void),CResolutionHandler__GetDesktopBitsPerPixel);
#endif
#ifdef CResolutionHandler__GetDesktopRefreshRate
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetDesktopRefreshRate(void),CResolutionHandler__GetDesktopRefreshRate);
#endif
#ifdef CResolutionHandler__GetWidth
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetWidth(void),CResolutionHandler__GetWidth);
#endif
#ifdef CResolutionHandler__GetHeight
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetHeight(void),CResolutionHandler__GetHeight);
#endif
#ifdef CResolutionHandler__IsFullscreenAvailable
FUNCTION_AT_ADDRESS(bool __cdecl CResolutionHandler::IsFullscreenAvailable(void),CResolutionHandler__IsFullscreenAvailable);
#endif
#ifdef Util__AllocateString
FUNCTION_AT_ADDRESS(char * __cdecl Util::AllocateString(char *),Util__AllocateString);
#endif
#ifdef ChannelServerApi__AllocateString
FUNCTION_AT_ADDRESS(char * __cdecl ChannelServerApi::AllocateString(char *),ChannelServerApi__AllocateString);
#endif
#ifdef SoundManager__SoundManager
//FUNCTION_AT_ADDRESS( SoundManager::SoundManager(int,int,bool,int,int,bool,enum SpeakerType),SoundManager__SoundManager);
#endif
#ifdef SoundManager__dSoundManager
FUNCTION_AT_ADDRESS( SoundManager::~SoundManager(void),SoundManager__dSoundManager);
#endif
#ifdef SoundManager__AddPool
//FUNCTION_AT_ADDRESS(void  SoundManager::AddPool(enum InstanceType,int,int),SoundManager__AddPool);
#endif
#ifdef SoundManager__GiveTime
FUNCTION_AT_ADDRESS(void  SoundManager::GiveTime(void),SoundManager__GiveTime);
#endif
#ifdef SoundManager__SetMixAhead
FUNCTION_AT_ADDRESS(void  SoundManager::SetMixAhead(int),SoundManager__SetMixAhead);
#endif
#ifdef SoundManager__GetListenerEnvironment
//FUNCTION_AT_ADDRESS(enum EnvironmentType  SoundManager::GetListenerEnvironment(void),SoundManager__GetListenerEnvironment);
#endif
#ifdef SoundManager__SetListenerEnvironment
//FUNCTION_AT_ADDRESS(void  SoundManager::SetListenerEnvironment(enum EnvironmentType),SoundManager__SetListenerEnvironment);
#endif
#ifdef SoundManager__SetListenerLocation
FUNCTION_AT_ADDRESS(void  SoundManager::SetListenerLocation(float,float,float,float),SoundManager__SetListenerLocation);
#endif
#ifdef SoundManager__GetListenerLocation
FUNCTION_AT_ADDRESS(void  SoundManager::GetListenerLocation(float *,float *,float *,float *),SoundManager__GetListenerLocation);
#endif
#ifdef SoundManager__BorrowInstance
//FUNCTION_AT_ADDRESS(class SoundInstance *  SoundManager::BorrowInstance(enum InstanceType,int),SoundManager__BorrowInstance);
#endif
#ifdef SoundManager__ReturnInstance
FUNCTION_AT_ADDRESS(void  SoundManager::ReturnInstance(class SoundInstance *),SoundManager__ReturnInstance);
#endif
#ifdef SoundManager__AssetGiveTime
FUNCTION_AT_ADDRESS(void  SoundManager::AssetGiveTime(void),SoundManager__AssetGiveTime);
#endif
#ifdef SoundManager__AssetAdd
FUNCTION_AT_ADDRESS(void  SoundManager::AssetAdd(class SoundAsset *),SoundManager__AssetAdd);
#endif
#ifdef SoundManager__AssetRemove
FUNCTION_AT_ADDRESS(void  SoundManager::AssetRemove(class SoundAsset *),SoundManager__AssetRemove);
#endif
#ifdef SoundManager__AssetGet
FUNCTION_AT_ADDRESS(class SoundAsset *  SoundManager::AssetGet(char *),SoundManager__AssetGet);
#endif
#ifdef SoundManager__StreamingPlay
FUNCTION_AT_ADDRESS(void  SoundManager::StreamingPlay(char *),SoundManager__StreamingPlay);
#endif
#ifdef SoundManager__StreamingPause
FUNCTION_AT_ADDRESS(void  SoundManager::StreamingPause(void),SoundManager__StreamingPause);
#endif
#ifdef SoundManager__StreamingStop
FUNCTION_AT_ADDRESS(void  SoundManager::StreamingStop(void),SoundManager__StreamingStop);
#endif
#ifdef SoundManager__StreamingSetVolumeLevel
FUNCTION_AT_ADDRESS(void  SoundManager::StreamingSetVolumeLevel(float),SoundManager__StreamingSetVolumeLevel);
#endif
#ifdef SoundManager__StreamingGetVolumeLevel
FUNCTION_AT_ADDRESS(float  SoundManager::StreamingGetVolumeLevel(void),SoundManager__StreamingGetVolumeLevel);
#endif
#ifdef SoundManager__StreamingSetSongPosition
FUNCTION_AT_ADDRESS(void  SoundManager::StreamingSetSongPosition(int),SoundManager__StreamingSetSongPosition);
#endif
#ifdef SoundManager__StreamingGetSongPosition
FUNCTION_AT_ADDRESS(int  SoundManager::StreamingGetSongPosition(void),SoundManager__StreamingGetSongPosition);
#endif
#ifdef SoundManager__StreamingGetSongLength
FUNCTION_AT_ADDRESS(int  SoundManager::StreamingGetSongLength(void),SoundManager__StreamingGetSongLength);
#endif
#ifdef SoundManager__StreamingStatus
//FUNCTION_AT_ADDRESS(enum StreamingStatus  SoundManager::StreamingStatus(void),SoundManager__StreamingStatus);
#endif
#ifdef MusicManager__MusicEntry__MusicEntry
//FUNCTION_AT_ADDRESS( MusicManager::MusicEntry::MusicEntry(int,class SoundAsset *,int,float,int,int,int,int,int,int),MusicManager__MusicEntry__MusicEntry);
#endif
#ifdef MusicManager__MusicEntry__dMusicEntry
//FUNCTION_AT_ADDRESS( MusicManager::MusicEntry::~MusicEntry(void),MusicManager__MusicEntry__dMusicEntry);
#endif
#ifdef MusicManager__MusicEntry__AdjustVolume
//FUNCTION_AT_ADDRESS(void  MusicManager::MusicEntry::AdjustVolume(float),MusicManager__MusicEntry__AdjustVolume);
#endif
#ifdef MusicManager__MusicEntry__FadeIn
//FUNCTION_AT_ADDRESS(void  MusicManager::MusicEntry::FadeIn(float),MusicManager__MusicEntry__FadeIn);
#endif
#ifdef MusicManager__MusicEntry__FadeOut
//FUNCTION_AT_ADDRESS(void  MusicManager::MusicEntry::FadeOut(bool),MusicManager__MusicEntry__FadeOut);
#endif
#ifdef SoundObject__SoundObject
//FUNCTION_AT_ADDRESS( SoundObject::SoundObject(void),SoundObject__SoundObject);
#endif
#ifdef SoundObject__Release
//FUNCTION_AT_ADDRESS(void  SoundObject::Release(void),SoundObject__Release);
#endif
#ifdef SoundInstance__SoundInstance
//FUNCTION_AT_ADDRESS( SoundInstance::SoundInstance(class SoundManager *),SoundInstance__SoundInstance);
#endif
#ifdef SoundInstance__YourManagerDeleted
//FUNCTION_AT_ADDRESS(void  SoundInstance::YourManagerDeleted(void),SoundInstance__YourManagerDeleted);
#endif
#ifdef flex_unit__clear
FUNCTION_AT_ADDRESS(void  flex_unit::clear(void),flex_unit__clear);
#endif
#ifdef WaveInstance__WaveInstance
FUNCTION_AT_ADDRESS( WaveInstance::WaveInstance(class SoundManager *),WaveInstance__WaveInstance);
#endif
#ifdef Wave3dInstance__Wave3dInstance
FUNCTION_AT_ADDRESS( Wave3dInstance::Wave3dInstance(class SoundManager *),Wave3dInstance__Wave3dInstance);
#endif
#ifdef MidiInstance__MidiInstance
//FUNCTION_AT_ADDRESS( MidiInstance::MidiInstance(class SoundManager *),MidiInstance__MidiInstance);
#endif
#ifdef SoundAsset__SoundAsset
//FUNCTION_AT_ADDRESS( SoundAsset::SoundAsset(class SoundManager *,char *,char *,int),SoundAsset__SoundAsset);
#endif
#ifdef SoundAsset__GetType
//FUNCTION_AT_ADDRESS(enum AssetType  SoundAsset::GetType(void),SoundAsset__GetType);
#endif
#ifdef SoundAsset__YourManagerDeleted
//FUNCTION_AT_ADDRESS(void  SoundAsset::YourManagerDeleted(void),SoundAsset__YourManagerDeleted);
#endif
#ifdef SoundAsset__GiveTime
//FUNCTION_AT_ADDRESS(void  SoundAsset::GiveTime(void),SoundAsset__GiveTime);
#endif
#ifdef SoundAsset__IsPlaying
//FUNCTION_AT_ADDRESS(bool  SoundAsset::IsPlaying(void),SoundAsset__IsPlaying);
#endif
#ifdef SoundAsset__AdjustVolume
//FUNCTION_AT_ADDRESS(void  SoundAsset::AdjustVolume(float,int),SoundAsset__AdjustVolume);
#endif
#ifdef SoundAsset__GetName
//FUNCTION_AT_ADDRESS(char *  SoundAsset::GetName(void),SoundAsset__GetName);
#endif
#ifdef SoundAsset__Play
//FUNCTION_AT_ADDRESS(class SoundInstance *  SoundAsset::Play(class SoundControl *),SoundAsset__Play);
#endif
#ifdef SoundAsset__Stop
//FUNCTION_AT_ADDRESS(void  SoundAsset::Stop(void),SoundAsset__Stop);
#endif
#ifdef SoundControl__SoundControl
FUNCTION_AT_ADDRESS( SoundControl::SoundControl(void),SoundControl__SoundControl);
#endif
#ifdef SoundEmitter__SoundEmitter
//FUNCTION_AT_ADDRESS( SoundEmitter::SoundEmitter(class EmitterManager *,class SoundAsset *,int),SoundEmitter__SoundEmitter);
#endif
#ifdef SoundEmitter__SoundEmitter1
//FUNCTION_AT_ADDRESS( SoundEmitter::SoundEmitter(class EmitterManager *,class MusicManager *,int),SoundEmitter__SoundEmitter1);
#endif
#ifdef SoundEmitter__Init
//FUNCTION_AT_ADDRESS(void  SoundEmitter::Init(void),SoundEmitter__Init);
#endif
#ifdef SoundEmitter__GiveTime
//FUNCTION_AT_ADDRESS(void  SoundEmitter::GiveTime(void),SoundEmitter__GiveTime);
#endif
#ifdef SoundEmitter__ReleaseLoopingSound
//FUNCTION_AT_ADDRESS(void  SoundEmitter::ReleaseLoopingSound(void),SoundEmitter__ReleaseLoopingSound);
#endif
#ifdef SoundEmitter__ResetTimer
//FUNCTION_AT_ADDRESS(void  SoundEmitter::ResetTimer(void),SoundEmitter__ResetTimer);
#endif
#ifdef SoundEmitter__Move
//FUNCTION_AT_ADDRESS(void  SoundEmitter::Move(float,float,float),SoundEmitter__Move);
#endif
#ifdef SoundEmitter__SetAsset
//FUNCTION_AT_ADDRESS(void  SoundEmitter::SetAsset(class SoundAsset *),SoundEmitter__SetAsset);
#endif
#ifdef SoundEmitter__Enable
//FUNCTION_AT_ADDRESS(void  SoundEmitter::Enable(bool),SoundEmitter__Enable);
#endif
#ifdef Mp3Manager__Mp3Manager
FUNCTION_AT_ADDRESS( Mp3Manager::Mp3Manager(class SoundManager *,class MusicManager *),Mp3Manager__Mp3Manager);
#endif
#ifdef Mp3Manager__dMp3Manager
FUNCTION_AT_ADDRESS( Mp3Manager::~Mp3Manager(void),Mp3Manager__dMp3Manager);
#endif
#ifdef Mp3Manager__GetSort
//FUNCTION_AT_ADDRESS(enum Mp3Manager::SortOrder  Mp3Manager::GetSort(void),Mp3Manager__GetSort);
#endif
#ifdef Mp3Manager__Sort
//FUNCTION_AT_ADDRESS(void  Mp3Manager::Sort(enum Mp3Manager::SortOrder),Mp3Manager__Sort);
#endif
#ifdef Mp3Manager__Stop
FUNCTION_AT_ADDRESS(void  Mp3Manager::Stop(void),Mp3Manager__Stop);
#endif
#ifdef Mp3Manager__Play
FUNCTION_AT_ADDRESS(void  Mp3Manager::Play(void),Mp3Manager__Play);
#endif
#ifdef Mp3Manager__Pause
FUNCTION_AT_ADDRESS(void  Mp3Manager::Pause(void),Mp3Manager__Pause);
#endif
#ifdef Mp3Manager__Status
//FUNCTION_AT_ADDRESS(enum StreamingStatus  Mp3Manager::Status(void),Mp3Manager__Status);
#endif
#ifdef Mp3Manager__GiveTime
FUNCTION_AT_ADDRESS(void  Mp3Manager::GiveTime(void),Mp3Manager__GiveTime);
#endif
#ifdef Mp3Manager__Next
FUNCTION_AT_ADDRESS(void  Mp3Manager::Next(void),Mp3Manager__Next);
#endif
#ifdef Mp3Manager__Back
FUNCTION_AT_ADDRESS(void  Mp3Manager::Back(void),Mp3Manager__Back);
#endif
#ifdef Mp3Manager__GetSongLength
FUNCTION_AT_ADDRESS(int  Mp3Manager::GetSongLength(void),Mp3Manager__GetSongLength);
#endif
#ifdef Mp3Manager__GetSongPosition
FUNCTION_AT_ADDRESS(int  Mp3Manager::GetSongPosition(void),Mp3Manager__GetSongPosition);
#endif
#ifdef Mp3Manager__SetSongPosition
FUNCTION_AT_ADDRESS(void  Mp3Manager::SetSongPosition(int),Mp3Manager__SetSongPosition);
#endif
#ifdef Mp3Manager__GetName
FUNCTION_AT_ADDRESS(char *  Mp3Manager::GetName(int),Mp3Manager__GetName);
#endif
#ifdef Mp3Manager__Count
FUNCTION_AT_ADDRESS(int  Mp3Manager::Count(void),Mp3Manager__Count);
#endif
#ifdef Mp3Manager__SetPosition
FUNCTION_AT_ADDRESS(void  Mp3Manager::SetPosition(int),Mp3Manager__SetPosition);
#endif
#ifdef Mp3Manager__SetVolumeLevel
FUNCTION_AT_ADDRESS(void  Mp3Manager::SetVolumeLevel(float),Mp3Manager__SetVolumeLevel);
#endif
#ifdef Mp3Manager__GetVolumeLevel
FUNCTION_AT_ADDRESS(float  Mp3Manager::GetVolumeLevel(void),Mp3Manager__GetVolumeLevel);
#endif
#ifdef Mp3Manager__DeleteAll
FUNCTION_AT_ADDRESS(void  Mp3Manager::DeleteAll(void),Mp3Manager__DeleteAll);
#endif
#ifdef Mp3Manager__Delete
FUNCTION_AT_ADDRESS(void  Mp3Manager::Delete(int),Mp3Manager__Delete);
#endif
#ifdef Mp3Manager__SaveList
FUNCTION_AT_ADDRESS(void  Mp3Manager::SaveList(char *),Mp3Manager__SaveList);
#endif
#ifdef Mp3Manager__Add
FUNCTION_AT_ADDRESS(int  Mp3Manager::Add(char *),Mp3Manager__Add);
#endif
#ifdef Mp3Manager__InternalAdd
FUNCTION_AT_ADDRESS(int  Mp3Manager::InternalAdd(char *,char *,int),Mp3Manager__InternalAdd);
#endif
#ifdef Mp3Manager__Entry__Entry
//FUNCTION_AT_ADDRESS( Mp3Manager::Entry::Entry(char *,char *,int,int),Mp3Manager__Entry__Entry);
#endif
#ifdef Mp3Manager__Entry__dEntry
//FUNCTION_AT_ADDRESS( Mp3Manager::Entry::~Entry(void),Mp3Manager__Entry__dEntry);
#endif
#ifdef EmitterManager__EmitterManager
FUNCTION_AT_ADDRESS( EmitterManager::EmitterManager(class SoundManager *),EmitterManager__EmitterManager);
#endif
#ifdef EmitterManager__dEmitterManager
FUNCTION_AT_ADDRESS( EmitterManager::~EmitterManager(void),EmitterManager__dEmitterManager);
#endif
#ifdef EmitterManager__Add
//FUNCTION_AT_ADDRESS(void  EmitterManager::Add(class SoundEmitter *),EmitterManager__Add);
#endif
#ifdef EmitterManager__Remove
//FUNCTION_AT_ADDRESS(void  EmitterManager::Remove(class SoundEmitter *),EmitterManager__Remove);
#endif
#ifdef EmitterManager__GiveTime
FUNCTION_AT_ADDRESS(void  EmitterManager::GiveTime(void),EmitterManager__GiveTime);
#endif
#ifdef EmitterManager__GetEffectsLevel
FUNCTION_AT_ADDRESS(float  EmitterManager::GetEffectsLevel(void),EmitterManager__GetEffectsLevel);
#endif
#ifdef EmitterManager__GetVolumeLevel
FUNCTION_AT_ADDRESS(float  EmitterManager::GetVolumeLevel(void),EmitterManager__GetVolumeLevel);
#endif
#ifdef EmitterManager__SetEffectsLevel
FUNCTION_AT_ADDRESS(void  EmitterManager::SetEffectsLevel(float),EmitterManager__SetEffectsLevel);
#endif
#ifdef EmitterManager__GetListenerLocation
FUNCTION_AT_ADDRESS(void  EmitterManager::GetListenerLocation(float *,float *,float *,float *),EmitterManager__GetListenerLocation);
#endif
#ifdef MusicManager__MusicManager
FUNCTION_AT_ADDRESS( MusicManager::MusicManager(void),MusicManager__MusicManager);
#endif
#ifdef MusicManager__dMusicManager
FUNCTION_AT_ADDRESS( MusicManager::~MusicManager(void),MusicManager__dMusicManager);
#endif
#ifdef MusicManager__GiveTime
FUNCTION_AT_ADDRESS(void  MusicManager::GiveTime(void),MusicManager__GiveTime);
#endif
#ifdef MusicManager__Clear
FUNCTION_AT_ADDRESS(void  MusicManager::Clear(class SoundAsset *),MusicManager__Clear);
#endif
#ifdef MusicManager__SetVolumeLevel
FUNCTION_AT_ADDRESS(void  MusicManager::SetVolumeLevel(float),MusicManager__SetVolumeLevel);
#endif
#ifdef MusicManager__Clear1
FUNCTION_AT_ADDRESS(void  MusicManager::Clear(int),MusicManager__Clear1);
#endif
#ifdef MusicManager__Set
FUNCTION_AT_ADDRESS(void  MusicManager::Set(int,class SoundAsset *,int,float,int,int,int,int,int,int),MusicManager__Set);
#endif
#ifdef MusicManager__Play
FUNCTION_AT_ADDRESS(void  MusicManager::Play(int),MusicManager__Play);
#endif
#ifdef MusicManager__Stop
FUNCTION_AT_ADDRESS(void  MusicManager::Stop(int),MusicManager__Stop);
#endif
#ifdef MusicManager__Enable
FUNCTION_AT_ADDRESS(void  MusicManager::Enable(bool),MusicManager__Enable);
#endif
#ifdef SpellManager__SpellManager
FUNCTION_AT_ADDRESS( SpellManager::SpellManager(char *),SpellManager__SpellManager);
#endif
#ifdef SpellManager__dSpellManager
FUNCTION_AT_ADDRESS( SpellManager::~SpellManager(void),SpellManager__dSpellManager);
#endif
#ifdef CStoryWnd__CStoryWnd
FUNCTION_AT_ADDRESS( CStoryWnd::CStoryWnd(class CXWnd *),CStoryWnd__CStoryWnd);
#endif
#ifdef CStoryWnd__Init
FUNCTION_AT_ADDRESS(void  CStoryWnd::Init(void),CStoryWnd__Init);
#endif
#ifdef CStoryWnd__SaveIni
FUNCTION_AT_ADDRESS(void  CStoryWnd::SaveIni(void),CStoryWnd__SaveIni);
#endif
#ifdef CStoryWnd__ShowAuto
FUNCTION_AT_ADDRESS(bool  CStoryWnd::ShowAuto(void),CStoryWnd__ShowAuto);
#endif
#ifdef CStoryWnd__HasNew
FUNCTION_AT_ADDRESS(bool  CStoryWnd::HasNew(void),CStoryWnd__HasNew);
#endif
#ifdef CStoryWnd__Activate
FUNCTION_AT_ADDRESS(void  CStoryWnd::Activate(void),CStoryWnd__Activate);
#endif
#ifdef CStoryWnd__SelectOldestNew
FUNCTION_AT_ADDRESS(void  CStoryWnd::SelectOldestNew(void),CStoryWnd__SelectOldestNew);
#endif
#ifdef CStoryWnd__SelectIndex
FUNCTION_AT_ADDRESS(void  CStoryWnd::SelectIndex(int),CStoryWnd__SelectIndex);
#endif
#ifdef StringItem__StringItem
FUNCTION_AT_ADDRESS( StringItem::StringItem(void),StringItem__StringItem);
#endif
#ifdef UdpReliableChannel__IncomingQueueEntry__IncomingQueueEntry
//FUNCTION_AT_ADDRESS( UdpReliableChannel::IncomingQueueEntry::IncomingQueueEntry(void),UdpReliableChannel__IncomingQueueEntry__IncomingQueueEntry);
#endif
#ifdef StringItem__dStringItem
FUNCTION_AT_ADDRESS( StringItem::~StringItem(void),StringItem__dStringItem);
#endif
#ifdef StringItem__load
FUNCTION_AT_ADDRESS(int  StringItem::load(struct _iobuf *,int),StringItem__load);
#endif
#ifdef StringTable__StringTable
FUNCTION_AT_ADDRESS( StringTable::StringTable(void),StringTable__StringTable);
#endif
#ifdef StringTable__dStringTable
FUNCTION_AT_ADDRESS( StringTable::~StringTable(void),StringTable__dStringTable);
#endif
#ifdef StringTable__checkAlloc
FUNCTION_AT_ADDRESS(void  StringTable::checkAlloc(void),StringTable__checkAlloc);
#endif
#ifdef StringTable__getString
FUNCTION_AT_ADDRESS(char *  StringTable::getString(unsigned long,bool *),StringTable__getString);
#endif
#ifdef StringTable__findItem
FUNCTION_AT_ADDRESS(class StringItem *  StringTable::findItem(unsigned long,int,int),StringTable__findItem);
#endif
#ifdef StringTable__load
FUNCTION_AT_ADDRESS(int  StringTable::load(char const *,int),StringTable__load);
#endif
#ifdef StringTable__addItem
FUNCTION_AT_ADDRESS(void  StringTable::addItem(class StringItem *),StringTable__addItem);
#endif
#ifdef UdpIpAddress__UdpIpAddress
FUNCTION_AT_ADDRESS( UdpIpAddress::UdpIpAddress(unsigned int),UdpIpAddress__UdpIpAddress);
#endif
#ifdef UdpManager__Params__Params
//FUNCTION_AT_ADDRESS( UdpManager::Params::Params(void),UdpManager__Params__Params);
#endif
#ifdef UdpManager__UdpManager
//FUNCTION_AT_ADDRESS( UdpManager::UdpManager(struct UdpManager::Params const *),UdpManager__UdpManager);
#endif
#ifdef UdpManager__PoolReturn
//FUNCTION_AT_ADDRESS(void  UdpManager::PoolReturn(class PooledLogicalPacket *),UdpManager__PoolReturn);
#endif
#ifdef UdpManager__dUdpManager
FUNCTION_AT_ADDRESS( UdpManager::~UdpManager(void),UdpManager__dUdpManager);
#endif
#ifdef UdpManager__CreateAndBindSocket
FUNCTION_AT_ADDRESS(void  UdpManager::CreateAndBindSocket(int),UdpManager__CreateAndBindSocket);
#endif
#ifdef UdpManager__CloseSocket
FUNCTION_AT_ADDRESS(void  UdpManager::CloseSocket(void),UdpManager__CloseSocket);
#endif
#ifdef UdpManager__ProcessDisconnectPending
FUNCTION_AT_ADDRESS(void  UdpManager::ProcessDisconnectPending(void),UdpManager__ProcessDisconnectPending);
#endif
#ifdef UdpManager__RemoveConnection
FUNCTION_AT_ADDRESS(void  UdpManager::RemoveConnection(class UdpConnection *),UdpManager__RemoveConnection);
#endif
#ifdef UdpManager__AddConnection
FUNCTION_AT_ADDRESS(void  UdpManager::AddConnection(class UdpConnection *),UdpManager__AddConnection);
#endif
#ifdef UdpManager__GiveTime
FUNCTION_AT_ADDRESS(bool  UdpManager::GiveTime(int,bool),UdpManager__GiveTime);
#endif
#ifdef UdpManager__EstablishConnection
FUNCTION_AT_ADDRESS(class UdpConnection *  UdpManager::EstablishConnection(char const *,int,int),UdpManager__EstablishConnection);
#endif
#ifdef UdpManager__KeepUntilDisconnected
FUNCTION_AT_ADDRESS(void  UdpManager::KeepUntilDisconnected(class UdpConnection *),UdpManager__KeepUntilDisconnected);
#endif
#ifdef UdpManager__ResetStats
FUNCTION_AT_ADDRESS(void  UdpManager::ResetStats(void),UdpManager__ResetStats);
#endif
#ifdef UdpManager__ActualReceive
//FUNCTION_AT_ADDRESS(class UdpManager::PacketHistoryEntry *  UdpManager::ActualReceive(void),UdpManager__ActualReceive);
#endif
#ifdef UdpManager__ActualSend
FUNCTION_AT_ADDRESS(void  UdpManager::ActualSend(unsigned char const *,int,class UdpIpAddress,int),UdpManager__ActualSend);
#endif
#ifdef UdpManager__ActualSendHelper
FUNCTION_AT_ADDRESS(void  UdpManager::ActualSendHelper(unsigned char const *,int,class UdpIpAddress,int),UdpManager__ActualSendHelper);
#endif
#ifdef UdpManager__SendPortAlive
FUNCTION_AT_ADDRESS(void  UdpManager::SendPortAlive(class UdpIpAddress,int),UdpManager__SendPortAlive);
#endif
#ifdef UdpManager__ProcessRawPacket
//FUNCTION_AT_ADDRESS(void  UdpManager::ProcessRawPacket(class UdpManager::PacketHistoryEntry const *),UdpManager__ProcessRawPacket);
#endif
#ifdef UdpManager__AddressGetConnection
FUNCTION_AT_ADDRESS(class UdpConnection *  UdpManager::AddressGetConnection(class UdpIpAddress,int)const ,UdpManager__AddressGetConnection);
#endif
#ifdef UdpManager__ConnectCodeGetConnection
FUNCTION_AT_ADDRESS(class UdpConnection *  UdpManager::ConnectCodeGetConnection(int)const ,UdpManager__ConnectCodeGetConnection);
#endif
#ifdef UdpManager__WrappedBorrow
//FUNCTION_AT_ADDRESS(class WrappedLogicalPacket *  UdpManager::WrappedBorrow(class LogicalPacket const *),UdpManager__WrappedBorrow);
#endif
#ifdef UdpManager__WrappedCreated
//FUNCTION_AT_ADDRESS(void  UdpManager::WrappedCreated(class WrappedLogicalPacket *),UdpManager__WrappedCreated);
#endif
#ifdef UdpManager__WrappedDestroyed
//FUNCTION_AT_ADDRESS(void  UdpManager::WrappedDestroyed(class WrappedLogicalPacket *),UdpManager__WrappedDestroyed);
#endif
#ifdef UdpManager__CreatePacket
FUNCTION_AT_ADDRESS(class LogicalPacket *  UdpManager::CreatePacket(void const *,int,void const *,int),UdpManager__CreatePacket);
#endif
#ifdef UdpManager__PoolCreated
//FUNCTION_AT_ADDRESS(void  UdpManager::PoolCreated(class PooledLogicalPacket *),UdpManager__PoolCreated);
#endif
#ifdef UdpManager__PoolDestroyed
//FUNCTION_AT_ADDRESS(void  UdpManager::PoolDestroyed(class PooledLogicalPacket *),UdpManager__PoolDestroyed);
#endif
#ifdef UdpManager__PacketHistoryEntry__PacketHistoryEntry
//FUNCTION_AT_ADDRESS( UdpManager::PacketHistoryEntry::PacketHistoryEntry(int),UdpManager__PacketHistoryEntry__PacketHistoryEntry);
#endif
#ifdef UdpManager__PacketHistoryEntry__dPacketHistoryEntry
//FUNCTION_AT_ADDRESS( UdpManager::PacketHistoryEntry::~PacketHistoryEntry(void),UdpManager__PacketHistoryEntry__dPacketHistoryEntry);
#endif
#ifdef UdpManager__SimulateQueueEntry__dSimulateQueueEntry
//FUNCTION_AT_ADDRESS( UdpManager::SimulateQueueEntry::~SimulateQueueEntry(void),UdpManager__SimulateQueueEntry__dSimulateQueueEntry);
#endif
#ifdef UdpConnection__UdpConnection
FUNCTION_AT_ADDRESS( UdpConnection::UdpConnection(class UdpManager *,class UdpIpAddress,int,int),UdpConnection__UdpConnection);
#endif
#ifdef UdpConnection__UdpConnection1
//FUNCTION_AT_ADDRESS( UdpConnection::UdpConnection(class UdpManager *,class UdpManager::PacketHistoryEntry const *),UdpConnection__UdpConnection1);
#endif
#ifdef UdpConnection__Init
FUNCTION_AT_ADDRESS(void  UdpConnection::Init(class UdpManager *,class UdpIpAddress,int),UdpConnection__Init);
#endif
#ifdef UdpConnection__dUdpConnection
FUNCTION_AT_ADDRESS( UdpConnection::~UdpConnection(void),UdpConnection__dUdpConnection);
#endif
#ifdef UdpConnection__PortUnreachable
FUNCTION_AT_ADDRESS(void  UdpConnection::PortUnreachable(void),UdpConnection__PortUnreachable);
#endif
#ifdef UdpConnection__InternalDisconnect
//FUNCTION_AT_ADDRESS(void  UdpConnection::InternalDisconnect(int,enum UdpConnection::DisconnectReason),UdpConnection__InternalDisconnect);
#endif
#ifdef UdpConnection__ScheduleTimeNow
FUNCTION_AT_ADDRESS(void  UdpConnection::ScheduleTimeNow(void),UdpConnection__ScheduleTimeNow);
#endif
#ifdef UdpConnection__SendTerminatePacket
//FUNCTION_AT_ADDRESS(void  UdpConnection::SendTerminatePacket(int,enum UdpConnection::DisconnectReason),UdpConnection__SendTerminatePacket);
#endif
#ifdef UdpMisc__PutValue32
FUNCTION_AT_ADDRESS(int __cdecl UdpMisc::PutValue32(void *,unsigned int),UdpMisc__PutValue32);
#endif
#ifdef UdpConnection__SetSilentDisconnect
FUNCTION_AT_ADDRESS(void  UdpConnection::SetSilentDisconnect(bool),UdpConnection__SetSilentDisconnect);
#endif
#ifdef UdpConnection__Send
//FUNCTION_AT_ADDRESS(bool  UdpConnection::Send(enum UdpChannel,void const *,int),UdpConnection__Send);
#endif
#ifdef UdpConnection__InternalSend
//FUNCTION_AT_ADDRESS(bool  UdpConnection::InternalSend(enum UdpChannel,unsigned char const *,int,unsigned char const *,int),UdpConnection__InternalSend);
#endif
#ifdef UdpConnection__PingStatReset
FUNCTION_AT_ADDRESS(void  UdpConnection::PingStatReset(void),UdpConnection__PingStatReset);
#endif
#ifdef UdpConnection__ProcessRawPacket
//FUNCTION_AT_ADDRESS(void  UdpConnection::ProcessRawPacket(class UdpManager::PacketHistoryEntry const *),UdpConnection__ProcessRawPacket);
#endif
#ifdef UdpMisc__GetValue24
FUNCTION_AT_ADDRESS(unsigned int __cdecl UdpMisc::GetValue24(void const *),UdpMisc__GetValue24);
#endif
#ifdef UdpConnection__IsNonEncryptPacket
FUNCTION_AT_ADDRESS(bool  UdpConnection::IsNonEncryptPacket(unsigned char const *)const ,UdpConnection__IsNonEncryptPacket);
#endif
#ifdef UdpConnection__CallbackRoutePacket
FUNCTION_AT_ADDRESS(void  UdpConnection::CallbackRoutePacket(unsigned char const *,int),UdpConnection__CallbackRoutePacket);
#endif
#ifdef UdpConnection__CallbackCorruptPacket
//FUNCTION_AT_ADDRESS(void  UdpConnection::CallbackCorruptPacket(unsigned char const *,int,enum UdpCorruptionReason),UdpConnection__CallbackCorruptPacket);
#endif
#ifdef UdpConnection__ProcessCookedPacket
FUNCTION_AT_ADDRESS(void  UdpConnection::ProcessCookedPacket(unsigned char const *,int),UdpConnection__ProcessCookedPacket);
#endif
#ifdef UdpMisc__PutValue64
FUNCTION_AT_ADDRESS(int __cdecl UdpMisc::PutValue64(void *,__int64),UdpMisc__PutValue64);
#endif
#ifdef UdpMisc__GetValue64
FUNCTION_AT_ADDRESS(__int64 __cdecl UdpMisc::GetValue64(void const *),UdpMisc__GetValue64);
#endif
#ifdef UdpReliableChannel__AckPacket
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::AckPacket(unsigned char const *,int),UdpReliableChannel__AckPacket);
#endif
#ifdef UdpConnection__GiveTime
FUNCTION_AT_ADDRESS(void  UdpConnection::GiveTime(void),UdpConnection__GiveTime);
#endif
#ifdef UdpConnection__InternalGiveTime
FUNCTION_AT_ADDRESS(void  UdpConnection::InternalGiveTime(void),UdpConnection__InternalGiveTime);
#endif
#ifdef UdpConnection__LastReceive
FUNCTION_AT_ADDRESS(int  UdpConnection::LastReceive(void)const ,UdpConnection__LastReceive);
#endif
#ifdef UdpConnection__ConnectionAge
FUNCTION_AT_ADDRESS(int  UdpConnection::ConnectionAge(void)const ,UdpConnection__ConnectionAge);
#endif
#ifdef UdpConnection__TotalPendingBytes
FUNCTION_AT_ADDRESS(int  UdpConnection::TotalPendingBytes(void)const ,UdpConnection__TotalPendingBytes);
#endif
#ifdef UdpConnection__RawSend
FUNCTION_AT_ADDRESS(void  UdpConnection::RawSend(unsigned char const *,int),UdpConnection__RawSend);
#endif
#ifdef UdpConnection__ExpireSendBin
FUNCTION_AT_ADDRESS(int  UdpConnection::ExpireSendBin(void),UdpConnection__ExpireSendBin);
#endif
#ifdef UdpConnection__ExpireReceiveBin
FUNCTION_AT_ADDRESS(int  UdpConnection::ExpireReceiveBin(void),UdpConnection__ExpireReceiveBin);
#endif
#ifdef UdpConnection__PhysicalSend
FUNCTION_AT_ADDRESS(void  UdpConnection::PhysicalSend(unsigned char const *,int,bool),UdpConnection__PhysicalSend);
#endif
#ifdef UdpMisc__PutValue24
FUNCTION_AT_ADDRESS(int __cdecl UdpMisc::PutValue24(void *,unsigned int),UdpMisc__PutValue24);
#endif
#ifdef UdpConnection__BufferedSend
FUNCTION_AT_ADDRESS(unsigned char *  UdpConnection::BufferedSend(unsigned char const *,int,unsigned char const *,int,bool),UdpConnection__BufferedSend);
#endif
#ifdef UdpConnection__FlushMultiBuffer
FUNCTION_AT_ADDRESS(void  UdpConnection::FlushMultiBuffer(void),UdpConnection__FlushMultiBuffer);
#endif
#ifdef UdpConnection__DecryptNone
FUNCTION_AT_ADDRESS(int  UdpConnection::DecryptNone(unsigned char *,unsigned char const *,int),UdpConnection__DecryptNone);
#endif
#ifdef UdpConnection__EncryptNone
FUNCTION_AT_ADDRESS(int  UdpConnection::EncryptNone(unsigned char *,unsigned char const *,int),UdpConnection__EncryptNone);
#endif
#ifdef UdpConnection__EncryptUserSupplied
FUNCTION_AT_ADDRESS(int  UdpConnection::EncryptUserSupplied(unsigned char *,unsigned char const *,int),UdpConnection__EncryptUserSupplied);
#endif
#ifdef UdpConnection__DecryptUserSupplied
FUNCTION_AT_ADDRESS(int  UdpConnection::DecryptUserSupplied(unsigned char *,unsigned char const *,int),UdpConnection__DecryptUserSupplied);
#endif
#ifdef UdpConnection__EncryptUserSupplied2
FUNCTION_AT_ADDRESS(int  UdpConnection::EncryptUserSupplied2(unsigned char *,unsigned char const *,int),UdpConnection__EncryptUserSupplied2);
#endif
#ifdef UdpConnection__DecryptUserSupplied2
FUNCTION_AT_ADDRESS(int  UdpConnection::DecryptUserSupplied2(unsigned char *,unsigned char const *,int),UdpConnection__DecryptUserSupplied2);
#endif
#ifdef UdpConnection__EncryptXorBuffer
FUNCTION_AT_ADDRESS(int  UdpConnection::EncryptXorBuffer(unsigned char *,unsigned char const *,int),UdpConnection__EncryptXorBuffer);
#endif
#ifdef UdpConnection__DecryptXorBuffer
FUNCTION_AT_ADDRESS(int  UdpConnection::DecryptXorBuffer(unsigned char *,unsigned char const *,int),UdpConnection__DecryptXorBuffer);
#endif
#ifdef UdpConnection__EncryptXor
FUNCTION_AT_ADDRESS(int  UdpConnection::EncryptXor(unsigned char *,unsigned char const *,int),UdpConnection__EncryptXor);
#endif
#ifdef UdpConnection__DecryptXor
FUNCTION_AT_ADDRESS(int  UdpConnection::DecryptXor(unsigned char *,unsigned char const *,int),UdpConnection__DecryptXor);
#endif
#ifdef UdpConnection__SetupEncryptModel
FUNCTION_AT_ADDRESS(void  UdpConnection::SetupEncryptModel(void),UdpConnection__SetupEncryptModel);
#endif
#ifdef UdpConnection__GetChannelStatus
//FUNCTION_AT_ADDRESS(void  UdpConnection::GetChannelStatus(enum UdpChannel,struct UdpConnection::ChannelStatus *)const ,UdpConnection__GetChannelStatus);
#endif
#ifdef UdpReliableChannel__UdpReliableChannel
//FUNCTION_AT_ADDRESS( UdpReliableChannel::UdpReliableChannel(int,class UdpConnection *,struct UdpManager::ReliableConfig *),UdpReliableChannel__UdpReliableChannel);
#endif
#ifdef UdpReliableChannel__dUdpReliableChannel
FUNCTION_AT_ADDRESS( UdpReliableChannel::~UdpReliableChannel(void),UdpReliableChannel__dUdpReliableChannel);
#endif
#ifdef UdpReliableChannel__Send
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::Send(unsigned char const *,int,unsigned char const *,int),UdpReliableChannel__Send);
#endif
#ifdef UdpReliableChannel__FlushCoalesce
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::FlushCoalesce(void),UdpReliableChannel__FlushCoalesce);
#endif
#ifdef UdpReliableChannel__SendCoalesce
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::SendCoalesce(unsigned char const *,int,unsigned char const *,int),UdpReliableChannel__SendCoalesce);
#endif
#ifdef UdpReliableChannel__QueueLogicalPacket
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::QueueLogicalPacket(class LogicalPacket const *),UdpReliableChannel__QueueLogicalPacket);
#endif
#ifdef UdpReliableChannel__PullDown
FUNCTION_AT_ADDRESS(bool  UdpReliableChannel::PullDown(int),UdpReliableChannel__PullDown);
#endif
#ifdef UdpReliableChannel__GiveTime
FUNCTION_AT_ADDRESS(int  UdpReliableChannel::GiveTime(void),UdpReliableChannel__GiveTime);
#endif
#ifdef UdpReliableChannel__GetChannelStatus
//FUNCTION_AT_ADDRESS(void  UdpReliableChannel::GetChannelStatus(struct UdpConnection::ChannelStatus *)const ,UdpReliableChannel__GetChannelStatus);
#endif
#ifdef UdpReliableChannel__ReliablePacket
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::ReliablePacket(unsigned char const *,int),UdpReliableChannel__ReliablePacket);
#endif
#ifdef UdpReliableChannel__GetReliableIncomingId
FUNCTION_AT_ADDRESS(__int64  UdpReliableChannel::GetReliableIncomingId(int)const ,UdpReliableChannel__GetReliableIncomingId);
#endif
#ifdef UdpReliableChannel__ProcessPacket
//FUNCTION_AT_ADDRESS(void  UdpReliableChannel::ProcessPacket(enum UdpReliableChannel::ReliablePacketMode,unsigned char const *,int),UdpReliableChannel__ProcessPacket);
#endif
#ifdef UdpReliableChannel__AckAllPacket
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::AckAllPacket(unsigned char const *,int),UdpReliableChannel__AckAllPacket);
#endif
#ifdef UdpReliableChannel__Ack
FUNCTION_AT_ADDRESS(void  UdpReliableChannel::Ack(__int64),UdpReliableChannel__Ack);
#endif
#ifdef UdpReliableChannel__IncomingQueueEntry__dIncomingQueueEntry
//FUNCTION_AT_ADDRESS( UdpReliableChannel::IncomingQueueEntry::~IncomingQueueEntry(void),UdpReliableChannel__IncomingQueueEntry__dIncomingQueueEntry);
#endif
#ifdef UdpReliableChannel__PhysicalPacket__PhysicalPacket
//FUNCTION_AT_ADDRESS( UdpReliableChannel::PhysicalPacket::PhysicalPacket(void),UdpReliableChannel__PhysicalPacket__PhysicalPacket);
#endif
#ifdef UdpReliableChannel__PhysicalPacket__dPhysicalPacket
//FUNCTION_AT_ADDRESS( UdpReliableChannel::PhysicalPacket::~PhysicalPacket(void),UdpReliableChannel__PhysicalPacket__dPhysicalPacket);
#endif
#ifdef LogicalPacket__LogicalPacket
FUNCTION_AT_ADDRESS( LogicalPacket::LogicalPacket(void),LogicalPacket__LogicalPacket);
#endif
#ifdef SoundObject__AddRef
//FUNCTION_AT_ADDRESS(void  SoundObject::AddRef(void),SoundObject__AddRef);
#endif
#ifdef Mp3Manager__GetPosition
FUNCTION_AT_ADDRESS(int  Mp3Manager::GetPosition(void),Mp3Manager__GetPosition);
#endif
#ifdef SimpleLogicalPacket__SimpleLogicalPacket
FUNCTION_AT_ADDRESS( SimpleLogicalPacket::SimpleLogicalPacket(void const *,int),SimpleLogicalPacket__SimpleLogicalPacket);
#endif
#ifdef EmitterManager__SetVolumeLevel
FUNCTION_AT_ADDRESS(void  EmitterManager::SetVolumeLevel(float),EmitterManager__SetVolumeLevel);
#endif
#ifdef PooledLogicalPacket__PooledLogicalPacket
//FUNCTION_AT_ADDRESS( PooledLogicalPacket::PooledLogicalPacket(class UdpManager *,int),PooledLogicalPacket__PooledLogicalPacket);
#endif
#ifdef ChannelServerApi__GetChannelCount
FUNCTION_AT_ADDRESS(int  ChannelServerApi::GetChannelCount(void),ChannelServerApi__GetChannelCount);
#endif
#ifdef PooledLogicalPacket__SetData
//FUNCTION_AT_ADDRESS(void  PooledLogicalPacket::SetData(void const *,int,void const *,int),PooledLogicalPacket__SetData);
#endif
#ifdef WrappedLogicalPacket__WrappedLogicalPacket
//FUNCTION_AT_ADDRESS( WrappedLogicalPacket::WrappedLogicalPacket(class UdpManager *),WrappedLogicalPacket__WrappedLogicalPacket);
#endif
#ifdef UdpManager__WrappedReturn
//FUNCTION_AT_ADDRESS(void  UdpManager::WrappedReturn(class WrappedLogicalPacket *),UdpManager__WrappedReturn);
#endif
#ifdef WrappedLogicalPacket__SetLogicalPacket
//FUNCTION_AT_ADDRESS(void  WrappedLogicalPacket::SetLogicalPacket(class LogicalPacket const *),WrappedLogicalPacket__SetLogicalPacket);
#endif
#ifdef UdpManager__SimulateQueueEntry__SimulateQueueEntry
//FUNCTION_AT_ADDRESS( UdpManager::SimulateQueueEntry::SimulateQueueEntry(unsigned char const *,int,class UdpIpAddress,int),UdpManager__SimulateQueueEntry__SimulateQueueEntry);
#endif
#ifdef UdpMisc__Clock
FUNCTION_AT_ADDRESS(__int64 __cdecl UdpMisc::Clock(void),UdpMisc__Clock);
#endif
#ifdef UdpMisc__SyncStampShortDeltaTime
FUNCTION_AT_ADDRESS(int __cdecl UdpMisc::SyncStampShortDeltaTime(unsigned short,unsigned short),UdpMisc__SyncStampShortDeltaTime);
#endif
#ifdef UdpMisc__Random
FUNCTION_AT_ADDRESS(int __cdecl UdpMisc::Random(int *),UdpMisc__Random);
#endif
#ifdef UdpMisc__Crc32
FUNCTION_AT_ADDRESS(int __cdecl UdpMisc::Crc32(void const *,int,int),UdpMisc__Crc32);
#endif
#ifdef UdpMisc__PutVariableValue
FUNCTION_AT_ADDRESS(unsigned int __cdecl UdpMisc::PutVariableValue(void *,unsigned int),UdpMisc__PutVariableValue);
#endif
#ifdef UdpMisc__GetVariableValue
FUNCTION_AT_ADDRESS(unsigned int __cdecl UdpMisc::GetVariableValue(void const *,unsigned int *),UdpMisc__GetVariableValue);
#endif
#ifdef UdpMisc__CreateQuickLogicalPacket
FUNCTION_AT_ADDRESS(class LogicalPacket * __cdecl UdpMisc::CreateQuickLogicalPacket(void const *,int,void const *,int),UdpMisc__CreateQuickLogicalPacket);
#endif
#ifdef Util__Stristr
//FUNCTION_AT_ADDRESS(char * __cdecl Util::Stristr(char *,char *),Util__Stristr);
#endif
#ifdef Util__StripCharacter
//FUNCTION_AT_ADDRESS(void __cdecl Util::StripCharacter(char *,char),Util__StripCharacter);
#endif
#ifdef Util__ClampLower
//FUNCTION_AT_ADDRESS(bool __cdecl Util::ClampLower(int *,int),Util__ClampLower);
#endif
#ifdef Util__ClampUpper
//FUNCTION_AT_ADDRESS(bool __cdecl Util::ClampUpper(int *,int),Util__ClampUpper);
#endif
#ifdef Util__GetNextStringToken
//FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextStringToken(char *,char *,int,char *,bool),Util__GetNextStringToken);
#endif
#ifdef Util__IsDelimiter
//FUNCTION_AT_ADDRESS(bool __cdecl Util::IsDelimiter(char,char *),Util__IsDelimiter);
#endif
#ifdef Util__Crc32
//FUNCTION_AT_ADDRESS(int __cdecl Util::Crc32(void const *,int,int),Util__Crc32);
#endif
#ifdef Util__GetSavePrivateProfileInt
//FUNCTION_AT_ADDRESS(int __cdecl Util::GetSavePrivateProfileInt(char *,char *,int,char *),Util__GetSavePrivateProfileInt);
#endif
#ifdef Util__PutValueVariable
//FUNCTION_AT_ADDRESS(int __cdecl Util::PutValueVariable(void *,unsigned int),Util__PutValueVariable);
#endif
#ifdef Util__PutValue32
//FUNCTION_AT_ADDRESS(unsigned int __cdecl Util::PutValue32(void *,unsigned int),Util__PutValue32);
#endif
#ifdef Util__GetValueVariable
//FUNCTION_AT_ADDRESS(int __cdecl Util::GetValueVariable(void const *,unsigned int *),Util__GetValueVariable);
#endif
#ifdef TextFileReader__TextFileReader
FUNCTION_AT_ADDRESS( TextFileReader::TextFileReader(char *,char),TextFileReader__TextFileReader);
#endif
#ifdef TextFileReader__dTextFileReader
FUNCTION_AT_ADDRESS( TextFileReader::~TextFileReader(void),TextFileReader__dTextFileReader);
#endif
#ifdef TextFileReader__ReadLine
FUNCTION_AT_ADDRESS(int  TextFileReader::ReadLine(void),TextFileReader__ReadLine);
#endif
#ifdef TextFileReader__GetNextField
FUNCTION_AT_ADDRESS(int  TextFileReader::GetNextField(char *,int),TextFileReader__GetNextField);
#endif
#ifdef TextFileReader__GetLine
FUNCTION_AT_ADDRESS(void  TextFileReader::GetLine(char *,int),TextFileReader__GetLine);
#endif
#ifdef TextFileReader__IsOpen
FUNCTION_AT_ADDRESS(bool  TextFileReader::IsOpen(void),TextFileReader__IsOpen);
#endif
#ifdef flex_unit__get
FUNCTION_AT_ADDRESS(unsigned int  flex_unit::get(unsigned int)const ,flex_unit__get);
#endif
#ifdef flex_unit__flex_unit
FUNCTION_AT_ADDRESS( flex_unit::flex_unit(void),flex_unit__flex_unit);
#endif
#ifdef flex_unit__dflex_unit
FUNCTION_AT_ADDRESS( flex_unit::~flex_unit(void),flex_unit__dflex_unit);
#endif
#ifdef flex_unit__reserve
FUNCTION_AT_ADDRESS(void  flex_unit::reserve(unsigned int),flex_unit__reserve);
#endif
#ifdef flex_unit__set
FUNCTION_AT_ADDRESS(void  flex_unit::set(unsigned int,unsigned int),flex_unit__set);
#endif
#ifdef flex_unit__fast_mul
FUNCTION_AT_ADDRESS(void  flex_unit::fast_mul(class flex_unit &,class flex_unit &,unsigned int),flex_unit__fast_mul);
#endif
#ifdef vlong_value__is_zero
FUNCTION_AT_ADDRESS(int  vlong_value::is_zero(void)const ,vlong_value__is_zero);
#endif
#ifdef vlong_value__test
FUNCTION_AT_ADDRESS(int  vlong_value::test(unsigned int)const ,vlong_value__test);
#endif
#ifdef vlong_value__bits
FUNCTION_AT_ADDRESS(unsigned int  vlong_value::bits(void)const ,vlong_value__bits);
#endif
#ifdef vlong_value__cf
FUNCTION_AT_ADDRESS(int  vlong_value::cf(class vlong_value &)const ,vlong_value__cf);
#endif
#ifdef vlong_value__shl
FUNCTION_AT_ADDRESS(void  vlong_value::shl(void),vlong_value__shl);
#endif
#ifdef vlong_value__shr
FUNCTION_AT_ADDRESS(void  vlong_value::shr(void),vlong_value__shr);
#endif
#ifdef vlong_value__shr1
FUNCTION_AT_ADDRESS(void  vlong_value::shr(unsigned int),vlong_value__shr1);
#endif
#ifdef vlong_value__add
FUNCTION_AT_ADDRESS(void  vlong_value::add(class vlong_value &),vlong_value__add);
#endif
#ifdef vlong_value__subtract
FUNCTION_AT_ADDRESS(void  vlong_value::subtract(class vlong_value &),vlong_value__subtract);
#endif
#ifdef vlong_value__init
FUNCTION_AT_ADDRESS(void  vlong_value::init(unsigned int),vlong_value__init);
#endif
#ifdef vlong_value__init2
FUNCTION_AT_ADDRESS(void  vlong_value::init2(unsigned int,unsigned int),vlong_value__init2);
#endif
#ifdef vlong_value__copy
FUNCTION_AT_ADDRESS(void  vlong_value::copy(class vlong_value &),vlong_value__copy);
#endif
#ifdef vlong_value__vlong_value
FUNCTION_AT_ADDRESS( vlong_value::vlong_value(void),vlong_value__vlong_value);
#endif
#ifdef vlong_value__mul
FUNCTION_AT_ADDRESS(void  vlong_value::mul(class vlong_value &,class vlong_value &),vlong_value__mul);
#endif
#ifdef vlong_value__divide
FUNCTION_AT_ADDRESS(void  vlong_value::divide(class vlong_value &,class vlong_value &,class vlong_value &),vlong_value__divide);
#endif
#ifdef vlong_value__dvlong_value
FUNCTION_AT_ADDRESS( vlong_value::~vlong_value(void),vlong_value__dvlong_value);
#endif
#ifdef vlong__docopy
FUNCTION_AT_ADDRESS(void  vlong::docopy(void),vlong__docopy);
#endif
#ifdef vlong__cf
//FUNCTION_AT_ADDRESS(int  vlong::cf(class vlong)const ,vlong__cf);
#endif
#ifdef vlong__vlong
FUNCTION_AT_ADDRESS( vlong::vlong(unsigned __int64),vlong__vlong);
#endif
#ifdef vlong__vlong1
FUNCTION_AT_ADDRESS( vlong::vlong(class vlong const &),vlong__vlong1);
#endif
#ifdef vlong__operator_equal
FUNCTION_AT_ADDRESS(class vlong &  vlong::operator=(class vlong),vlong__operator_equal);
#endif
#ifdef vlong__dvlong
FUNCTION_AT_ADDRESS( vlong::~vlong(void),vlong__dvlong);
#endif
#ifdef vlong__operator_plus_equal
FUNCTION_AT_ADDRESS(class vlong &  vlong::operator+=(class vlong const &),vlong__operator_plus_equal);
#endif
#ifdef vlong__operator_minus_equal
FUNCTION_AT_ADDRESS(class vlong &  vlong::operator-=(class vlong const &),vlong__operator_minus_equal);
#endif
#ifdef monty__monty
FUNCTION_AT_ADDRESS( monty::monty(class vlong const &),monty__monty);
#endif
#ifdef monty__mul
FUNCTION_AT_ADDRESS(void  monty::mul(class vlong &,class vlong const &),monty__mul);
#endif
#ifdef monty__exp
FUNCTION_AT_ADDRESS(class vlong  monty::exp(class vlong const &,class vlong const &),monty__exp);
#endif
#ifdef monty__dmonty
FUNCTION_AT_ADDRESS( monty::~monty(void),monty__dmonty);
#endif
#ifdef ZlibUtil__zcalloc
FUNCTION_AT_ADDRESS(void * __cdecl ZlibUtil::zcalloc(void *,unsigned int,unsigned int),ZlibUtil__zcalloc);
#endif
#ifdef ZlibUtil__zfree
FUNCTION_AT_ADDRESS(void __cdecl ZlibUtil::zfree(void *,void *),ZlibUtil__zfree);
#endif
#ifdef ZlibUtil__zcompress
FUNCTION_AT_ADDRESS(int __cdecl ZlibUtil::zcompress(unsigned char *,unsigned long *,unsigned char const *,unsigned long,int),ZlibUtil__zcompress);
#endif
#ifdef ZlibUtil__zuncompress
FUNCTION_AT_ADDRESS(int __cdecl ZlibUtil::zuncompress(unsigned char *,unsigned long *,unsigned char const *,unsigned long),ZlibUtil__zuncompress);
#endif
#ifdef ZlibUtil__Compress
FUNCTION_AT_ADDRESS(int __cdecl ZlibUtil::Compress(char const *,int,char *,int,int),ZlibUtil__Compress);
#endif
#ifdef ZlibUtil__Decompress
FUNCTION_AT_ADDRESS(int __cdecl ZlibUtil::Decompress(char const *,int,char *,int),ZlibUtil__Decompress);
#endif
#ifdef PackFS__PackFS
FUNCTION_AT_ADDRESS( PackFS::PackFS(void),PackFS__PackFS);
#endif
#ifdef PackFS__addFileSystem
//FUNCTION_AT_ADDRESS(bool  PackFS::addFileSystem(class FilePath),PackFS__addFileSystem);
#endif
#ifdef PackFS__removeFileSystem
FUNCTION_AT_ADDRESS(void  PackFS::removeFileSystem(class FilePath),PackFS__removeFileSystem);
#endif
#ifdef SharedString___updateTag
FUNCTION_AT_ADDRESS(void  SharedString::_updateTag(void)const ,SharedString___updateTag);
#endif
#ifdef FilePath__FilePath2
FUNCTION_AT_ADDRESS( FilePath::FilePath(void),FilePath__FilePath2);
#endif
#ifdef PackFile__dPackFile
FUNCTION_AT_ADDRESS( PackFile::~PackFile(void),PackFile__dPackFile);
#endif
#ifdef PackFile__close
FUNCTION_AT_ADDRESS(void  PackFile::close(void),PackFile__close);
#endif
#ifdef _PackFileData__d_PackFileData
FUNCTION_AT_ADDRESS( _PackFileData::~_PackFileData(void),_PackFileData__d_PackFileData);
#endif
#ifdef PackFile__length
FUNCTION_AT_ADDRESS(int  PackFile::length(void)const ,PackFile__length);
#endif
#ifdef PackFile__read
FUNCTION_AT_ADDRESS(int  PackFile::read(void * const,int),PackFile__read);
#endif
#ifdef PackFS__openFile
//FUNCTION_AT_ADDRESS(bool  PackFS::openFile(class FilePath,class PackFile *)const ,PackFS__openFile);
#endif
#ifdef CRC32Generator__generateCRC32
FUNCTION_AT_ADDRESS(unsigned int  CRC32Generator::generateCRC32(unsigned char const *,unsigned int)const ,CRC32Generator__generateCRC32);
#endif
#ifdef CRC32Generator__updateCRC32
FUNCTION_AT_ADDRESS(unsigned int  CRC32Generator::updateCRC32(unsigned int,unsigned char const *,unsigned int)const ,CRC32Generator__updateCRC32);
#endif
#ifdef CSidlScreenWnd__dCSidlScreenWnd
FUNCTION_AT_ADDRESS( CSidlScreenWnd::~CSidlScreenWnd(void),CSidlScreenWnd__dCSidlScreenWnd);
#endif
#ifdef CSidlScreenWnd__WndNotification
FUNCTION_AT_ADDRESS( int CSidlScreenWnd::WndNotification(class CXWnd *,unsigned __int32,void *),CSidlScreenWnd__WndNotification);
#endif
#ifdef CSidlScreenWnd__CSidlScreenWnd
FUNCTION_AT_ADDRESS( CSidlScreenWnd::CSidlScreenWnd(class CXWnd *,unsigned __int32,class CXRect,class CXStr),CSidlScreenWnd__CSidlScreenWnd);
#endif
#ifdef CSidlScreenWnd__CSidlScreenWnd1
FUNCTION_AT_ADDRESS( CSidlScreenWnd::CSidlScreenWnd(class CXWnd *x,class CXStr*,int,int,char *),CSidlScreenWnd__CSidlScreenWnd1);
#endif
#ifdef CSidlScreenWnd__CSidlScreenWnd2
FUNCTION_AT_ADDRESS( CSidlScreenWnd::CSidlScreenWnd(class CXWnd *x,class CXStr),CSidlScreenWnd__CSidlScreenWnd2);
#endif
#ifdef CSidlScreenWnd__Init
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::Init(class CXWnd *,unsigned __int32,class CXRect,class CXStr,int,char *),CSidlScreenWnd__Init);
#endif
#ifdef CSidlScreenWnd__Init1
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::Init(int,class CXStr*,int,int,int),CSidlScreenWnd__Init1);
#endif
#ifdef CSidlScreenWnd__SetScreen
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::SetScreen(class CXStr*),CSidlScreenWnd__SetScreen);
#endif
#ifdef CSidlScreenWnd__LoadSidlScreen
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::LoadSidlScreen(void),CSidlScreenWnd__LoadSidlScreen);
#endif
#ifdef CSidlScreenWnd__CalculateVSBRange
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::CalculateVSBRange(void),CSidlScreenWnd__CalculateVSBRange);
#endif
#ifdef CSidlScreenWnd__CalculateHSBRange
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::CalculateHSBRange(void),CSidlScreenWnd__CalculateHSBRange);
#endif
#ifdef CSidlScreenWnd__DrawSidlPiece
FUNCTION_AT_ADDRESS(int  CSidlScreenWnd::DrawSidlPiece(class CScreenPieceTemplate *,class CXRect,class CXRect)const ,CSidlScreenWnd__DrawSidlPiece);
#endif
#ifdef CSidlScreenWnd__GetSidlPiece
FUNCTION_AT_ADDRESS(class CScreenPieceTemplate *  CSidlScreenWnd::GetSidlPiece(class CXStr*)const ,CSidlScreenWnd__GetSidlPiece);
#endif
#ifdef CSidlScreenWnd__GetSidlPieceRect
FUNCTION_AT_ADDRESS(class CXRect  CSidlScreenWnd::GetSidlPieceRect(class CScreenPieceTemplate *,class CXRect)const ,CSidlScreenWnd__GetSidlPieceRect);
#endif
#ifdef CSidlScreenWnd__AddButtonToRadioGroup
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::AddButtonToRadioGroup(class CXStr,class CButtonWnd *),CSidlScreenWnd__AddButtonToRadioGroup);
#endif
#ifdef CRadioGroup__CRadioGroup
FUNCTION_AT_ADDRESS( CRadioGroup::CRadioGroup(class CXStr),CRadioGroup__CRadioGroup);
#endif
#ifdef CRadioGroup__GetName
FUNCTION_AT_ADDRESS(class CXStr  CRadioGroup::GetName(void)const ,CRadioGroup__GetName);
#endif
#ifdef CSidlScreenWnd__CreateChildrenFromSidl
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::CreateChildrenFromSidl(void),CSidlScreenWnd__CreateChildrenFromSidl);
#endif
#ifdef CSidlScreenWnd__StoreIniVis
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::StoreIniVis(void),CSidlScreenWnd__StoreIniVis);
#endif
#ifdef CSidlScreenWnd__EnableIniStorage
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::EnableIniStorage(int,char *),CSidlScreenWnd__EnableIniStorage);
#endif
#ifdef CSidlScreenWnd__ConvertToRes
FUNCTION_AT_ADDRESS(int  CSidlScreenWnd::ConvertToRes(int,int,int,int),CSidlScreenWnd__ConvertToRes);
#endif
#ifdef CSidlScreenWnd__GetChildItem
FUNCTION_AT_ADDRESS(class CXWnd *  CSidlScreenWnd::GetChildItem(CXStr const &),CSidlScreenWnd__GetChildItem);
#endif
#ifdef CSidlScreenWnd__LoadIniListWnd
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::LoadIniListWnd(class CListWnd *,char *),CSidlScreenWnd__LoadIniListWnd);
#endif
#ifdef CSidlScreenWnd__StoreIniListWnd
FUNCTION_AT_ADDRESS(void  CSidlScreenWnd::StoreIniListWnd(class CListWnd const *,char *),CSidlScreenWnd__StoreIniListWnd);
#endif
#ifdef CXWndDrawTemplate__CXWndDrawTemplate
FUNCTION_AT_ADDRESS( CXWndDrawTemplate::CXWndDrawTemplate(void),CXWndDrawTemplate__CXWndDrawTemplate);
#endif
#ifdef CUITextureInfo__CUITextureInfo1
FUNCTION_AT_ADDRESS( CUITextureInfo::CUITextureInfo(void),CUITextureInfo__CUITextureInfo1);
#endif
#ifdef CButtonDrawTemplate__CButtonDrawTemplate
FUNCTION_AT_ADDRESS( CButtonDrawTemplate::CButtonDrawTemplate(void),CButtonDrawTemplate__CButtonDrawTemplate);
#endif
#ifdef CScrollbarTemplate__dCScrollbarTemplate
FUNCTION_AT_ADDRESS( CScrollbarTemplate::~CScrollbarTemplate(void),CScrollbarTemplate__dCScrollbarTemplate);
#endif
#ifdef CXWndDrawTemplate__dCXWndDrawTemplate
FUNCTION_AT_ADDRESS( CXWndDrawTemplate::~CXWndDrawTemplate(void),CXWndDrawTemplate__dCXWndDrawTemplate);
#endif
#ifdef CButtonDrawTemplate__GetSize
FUNCTION_AT_ADDRESS(class CXSize  CButtonDrawTemplate::GetSize(void)const ,CButtonDrawTemplate__GetSize);
#endif
#ifdef CXWnd__CXWnd
FUNCTION_AT_ADDRESS( CXWnd::CXWnd(class CXWnd *,unsigned __int32,class CXRect),CXWnd__CXWnd);
#endif
#ifdef CXWnd__IsType
//FUNCTION_AT_ADDRESS(bool  CXWnd::IsType(enum EWndRuntimeType)const ,CXWnd__IsType);
#endif
#ifdef CXWnd__SetFocus
FUNCTION_AT_ADDRESS(class CXWnd *  CXWnd::SetFocus(void),CXWnd__SetFocus);
#endif
#ifdef CXWnd__ClrFocus
FUNCTION_AT_ADDRESS(void  CXWnd::ClrFocus(void),CXWnd__ClrFocus);
#endif
#ifdef CXWnd__HasFocus
FUNCTION_AT_ADDRESS(bool  CXWnd::HasFocus(void)const ,CXWnd__HasFocus);
#endif
#ifdef CXWnd__Show
FUNCTION_AT_ADDRESS(int  CXWnd::Show(bool,bool),CXWnd__Show);
#endif
#ifdef CXWnd__DrawCloseBox
FUNCTION_AT_ADDRESS(int  CXWnd::DrawCloseBox(void)const ,CXWnd__DrawCloseBox);
#endif
#ifdef CXWnd__DrawMinimizeBox
FUNCTION_AT_ADDRESS(int  CXWnd::DrawMinimizeBox(void)const ,CXWnd__DrawMinimizeBox);
#endif
#ifdef CXWnd__DrawTileBox
FUNCTION_AT_ADDRESS(int  CXWnd::DrawTileBox(void)const ,CXWnd__DrawTileBox);
#endif
#ifdef CXWnd__DrawVScrollbar
FUNCTION_AT_ADDRESS(int  CXWnd::DrawVScrollbar(int,int,int)const ,CXWnd__DrawVScrollbar);
#endif
#ifdef CXRect__CXRect
FUNCTION_AT_ADDRESS( CXRect::CXRect(int,int,int,int),CXRect__CXRect);
#endif
#ifdef CXRect__operator_equal
FUNCTION_AT_ADDRESS(class CXRect &  CXRect::operator=(class CXRect const &),CXRect__operator_equal);
#endif
#ifdef CXWnd__DrawHScrollbar
FUNCTION_AT_ADDRESS(int  CXWnd::DrawHScrollbar(int,int,int)const ,CXWnd__DrawHScrollbar);
#endif
#ifdef CXWnd__Refade
FUNCTION_AT_ADDRESS(void  CXWnd::Refade(void),CXWnd__Refade);
#endif
#ifdef CXWnd__Move
FUNCTION_AT_ADDRESS(int  CXWnd::Move(class CXPoint),CXWnd__Move);
#endif
#ifdef CXWnd__Move1
FUNCTION_AT_ADDRESS(int  CXWnd::Move(class CXRect),CXWnd__Move1);
#endif
#ifdef CXPoint__operator_equal
FUNCTION_AT_ADDRESS(class CXPoint  CXPoint::operator=(class CXPoint),CXPoint__operator_equal);
#endif
#ifdef CXWnd__ProcessTransition
FUNCTION_AT_ADDRESS(int  CXWnd::ProcessTransition(void),CXWnd__ProcessTransition);
#endif
#ifdef CXWnd__BringToTop
FUNCTION_AT_ADDRESS(void  CXWnd::BringToTop(bool),CXWnd__BringToTop);
#endif
#ifdef CXWnd__StartFade
FUNCTION_AT_ADDRESS(void  CXWnd::StartFade(unsigned char,unsigned __int32),CXWnd__StartFade);
#endif
#ifdef CXWnd__Minimize
FUNCTION_AT_ADDRESS(int  CXWnd::Minimize(bool),CXWnd__Minimize);
#endif
#ifdef CXWnd__IsReallyVisible
FUNCTION_AT_ADDRESS(bool  CXWnd::IsReallyVisible(void)const ,CXWnd__IsReallyVisible);
#endif
#ifdef CXWnd__GetNextChildWnd
FUNCTION_AT_ADDRESS(class CXWnd *  CXWnd::GetNextChildWnd(class CXWnd *)const ,CXWnd__GetNextChildWnd);
#endif
#ifdef CXWnd__GetChildWndAt
FUNCTION_AT_ADDRESS(class CXWnd *  CXWnd::GetChildWndAt(class CXPoint)const ,CXWnd__GetChildWndAt);
#endif
#ifdef CXWnd__GetFirstChildWnd
FUNCTION_AT_ADDRESS(class CXWnd *  CXWnd::GetFirstChildWnd(void)const ,CXWnd__GetFirstChildWnd);
#endif
#ifdef CXWnd__GetNextSib
FUNCTION_AT_ADDRESS(class CXWnd *  CXWnd::GetNextSib(void)const ,CXWnd__GetNextSib);
#endif
#ifdef CXWnd__DoAllDrawing
FUNCTION_AT_ADDRESS(int  CXWnd::DoAllDrawing(void)const ,CXWnd__DoAllDrawing);
#endif
#ifdef CXWnd__DrawLasso
FUNCTION_AT_ADDRESS(int __cdecl CXWnd::DrawLasso(class CXRect,unsigned long,class CXRect),CXWnd__DrawLasso);
#endif
#ifdef CXWnd__DrawChildren
FUNCTION_AT_ADDRESS(int  CXWnd::DrawChildren(void)const ,CXWnd__DrawChildren);
#endif
#ifdef CXWnd__BringChildWndToTop
FUNCTION_AT_ADDRESS(void  CXWnd::BringChildWndToTop(class CXWnd *),CXWnd__BringChildWndToTop);
#endif
#ifdef CXWnd__DrawColoredRect
FUNCTION_AT_ADDRESS(int __cdecl CXWnd::DrawColoredRect(class CXRect,unsigned long,class CXRect),CXWnd__DrawColoredRect);
#endif
#ifdef CXWnd__GetTooltipRect
FUNCTION_AT_ADDRESS(class CXRect __cdecl CXWnd::GetTooltipRect(class CXSize),CXWnd__GetTooltipRect);
#endif
#ifdef CXWnd__GetTooltipRect1
FUNCTION_AT_ADDRESS(class CXRect __cdecl CXWnd::GetTooltipRect(class CXPoint,class CXSize),CXWnd__GetTooltipRect1);
#endif
#ifdef CXWnd__DrawTooltipAtPoint
FUNCTION_AT_ADDRESS(void  CXWnd::DrawTooltipAtPoint(class CXPoint)const ,CXWnd__DrawTooltipAtPoint);
#endif
#ifdef CXWnd__Bottom
FUNCTION_AT_ADDRESS(void  CXWnd::Bottom(void),CXWnd__Bottom);
#endif
#ifdef CXWnd__Center
FUNCTION_AT_ADDRESS(void  CXWnd::Center(void),CXWnd__Center);
#endif
#ifdef CXWnd__Right
FUNCTION_AT_ADDRESS(void  CXWnd::Right(void),CXWnd__Right);
#endif
#ifdef CXWnd__Left
FUNCTION_AT_ADDRESS(void  CXWnd::Left(void),CXWnd__Left);
#endif
#ifdef CXWnd__SetLookLikeParent
FUNCTION_AT_ADDRESS(void  CXWnd::SetLookLikeParent(void),CXWnd__SetLookLikeParent);
#endif
#ifdef CXWnd__GetClientClipRect
FUNCTION_AT_ADDRESS(class CXRect  CXWnd::GetClientClipRect(void)const ,CXWnd__GetClientClipRect);
#endif
#ifdef CXWnd__GetScreenClipRect
FUNCTION_AT_ADDRESS(class CXRect  CXWnd::GetScreenClipRect(void)const ,CXWnd__GetScreenClipRect);
#endif
#ifdef CXWnd__IsActive
FUNCTION_AT_ADDRESS(bool  CXWnd::IsActive(void)const ,CXWnd__IsActive);
#endif
#ifdef CXWnd__IsDescendantOf
FUNCTION_AT_ADDRESS(bool  CXWnd::IsDescendantOf(class CXWnd const *)const ,CXWnd__IsDescendantOf);
#endif
#ifdef CXWnd__GetBorderFrame
FUNCTION_AT_ADDRESS(class CTAFrameDraw const *  CXWnd::GetBorderFrame(void)const ,CXWnd__GetBorderFrame);
#endif
#ifdef CXWnd__GetTitlebarHeader
FUNCTION_AT_ADDRESS(class CTAFrameDraw const *  CXWnd::GetTitlebarHeader(void)const ,CXWnd__GetTitlebarHeader);
#endif
#ifdef CXWnd__GetCloseBoxTemplate
FUNCTION_AT_ADDRESS(class CButtonDrawTemplate const *  CXWnd::GetCloseBoxTemplate(void)const ,CXWnd__GetCloseBoxTemplate);
#endif
#ifdef CXWnd__GetMinimizeBoxTemplate
FUNCTION_AT_ADDRESS(class CButtonDrawTemplate const *  CXWnd::GetMinimizeBoxTemplate(void)const ,CXWnd__GetMinimizeBoxTemplate);
#endif
#ifdef CXWnd__GetTileBoxTemplate
FUNCTION_AT_ADDRESS(class CButtonDrawTemplate const *  CXWnd::GetTileBoxTemplate(void)const ,CXWnd__GetTileBoxTemplate);
#endif
#ifdef CXWnd__GetRelativeRect
FUNCTION_AT_ADDRESS(class CXRect  CXWnd::GetRelativeRect(void)const ,CXWnd__GetRelativeRect);
#endif
#ifdef CXWnd__GetScreenRect
FUNCTION_AT_ADDRESS(class CXRect  CXWnd::GetScreenRect(void)const ,CXWnd__GetScreenRect);
#endif
#ifdef CXWnd__Resize
FUNCTION_AT_ADDRESS(int  CXWnd::Resize(int,int),CXWnd__Resize);
#endif
#ifdef CXWnd__GetChildItem
FUNCTION_AT_ADDRESS(class CXWnd *  CXWnd::GetChildItem(CXStr const &),CXWnd__GetChildItem);
#endif
#ifdef CXWnd__SetZLayer
FUNCTION_AT_ADDRESS(void  CXWnd::SetZLayer(int),CXWnd__SetZLayer);
#endif
#ifdef CXWnd__SetFirstChildPointer
FUNCTION_AT_ADDRESS(void  CXWnd::SetFirstChildPointer(class CXWnd *),CXWnd__SetFirstChildPointer);
#endif
#ifdef CXWnd__SetNextSibPointer
FUNCTION_AT_ADDRESS(void  CXWnd::SetNextSibPointer(class CXWnd *),CXWnd__SetNextSibPointer);
#endif
#ifdef CXWnd__SetMouseOver
FUNCTION_AT_ADDRESS(void  CXWnd::SetMouseOver(bool),CXWnd__SetMouseOver);
#endif
#ifdef CXWnd__SetKeyTooltip
FUNCTION_AT_ADDRESS(void  CXWnd::SetKeyTooltip(int,int),CXWnd__SetKeyTooltip);
#endif
#ifdef CXWnd__GetXMLTooltip
FUNCTION_AT_ADDRESS(class CXStr  CXWnd::GetXMLTooltip(void)const ,CXWnd__GetXMLTooltip);
#endif
#ifdef CXWnd__DrawTooltip
FUNCTION_AT_ADDRESS(int CXWnd::DrawTooltip(class CXWnd const *)const,CXWnd__DrawTooltip);
#endif
#ifdef CMutexSyncCounted__CMutexSyncCounted
FUNCTION_AT_ADDRESS( CMutexSyncCounted::CMutexSyncCounted(void),CMutexSyncCounted__CMutexSyncCounted);
#endif
#ifdef CMutexSyncCounted__dCMutexSyncCounted
FUNCTION_AT_ADDRESS( CMutexSyncCounted::~CMutexSyncCounted(void),CMutexSyncCounted__dCMutexSyncCounted);
#endif
#ifdef CMutexLockCounted__dCMutexLockCounted
FUNCTION_AT_ADDRESS( CMutexLockCounted::~CMutexLockCounted(void),CMutexLockCounted__dCMutexLockCounted);
#endif
#ifdef CXStr__AssureCopy
FUNCTION_AT_ADDRESS(void  CXStr::AssureCopy(void),CXStr__AssureCopy);
#endif
#ifdef CXStr__Assure
//FUNCTION_AT_ADDRESS(void  CXStr::Assure(long,enum EStringEncoding),CXStr__Assure);
#endif
#ifdef CXStr__AllocRepNoLock
//FUNCTION_AT_ADDRESS(struct CStrRep *  CXStr::AllocRepNoLock(long,enum EStringEncoding),CXStr__AllocRepNoLock);
#endif
#ifdef CXStr__FreeRep
FUNCTION_AT_ADDRESS(void  CXStr::FreeRep(struct CStrRep *),CXStr__FreeRep);
#endif
#ifdef CXStr__FreeRepNoLock
FUNCTION_AT_ADDRESS(void  CXStr::FreeRepNoLock(struct CStrRep *),CXStr__FreeRepNoLock);
#endif
#ifdef CXStr__CXStr2
FUNCTION_AT_ADDRESS( CXStr::CXStr(char),CXStr__CXStr2);
#endif
#ifdef CXStr__CXStr3
FUNCTION_AT_ADDRESS( CXStr::CXStr(char const *),CXStr__CXStr3);
#endif
#ifdef CXStr__CXStr4
FUNCTION_AT_ADDRESS( CXStr::CXStr(char const *,int),CXStr__CXStr4);
#endif
#ifdef CXStr__CXStr5
FUNCTION_AT_ADDRESS( CXStr::CXStr(unsigned short const *),CXStr__CXStr5);
#endif
#ifdef CXStr__CXStr6
FUNCTION_AT_ADDRESS( CXStr::CXStr(int,int,char),CXStr__CXStr6);
#endif
#ifdef CXStr__operator_equal
FUNCTION_AT_ADDRESS(class CXStr &  CXStr::operator=(class CXStr const &),CXStr__operator_equal);
#endif
#ifdef CXStr__operator_equal1
FUNCTION_AT_ADDRESS(class CXStr &  CXStr::operator=(char const *),CXStr__operator_equal1);
#endif
#ifdef CXStr__GetChar
FUNCTION_AT_ADDRESS(char  CXStr::GetChar(long)const ,CXStr__GetChar);
#endif
#ifdef CXStr__SetChar
FUNCTION_AT_ADDRESS(char  CXStr::SetChar(long,char),CXStr__SetChar);
#endif
#ifdef CXStr__GetUnicode
FUNCTION_AT_ADDRESS(unsigned short  CXStr::GetUnicode(long)const ,CXStr__GetUnicode);
#endif
#ifdef CXStr__SetUnicode
FUNCTION_AT_ADDRESS(unsigned short  CXStr::SetUnicode(long,unsigned short),CXStr__SetUnicode);
#endif
#ifdef CXStr__Compare
//FUNCTION_AT_ADDRESS(int  CXStr::Compare(class CXStr const &,enum CompareCode)const ,CXStr__Compare);
#endif
#ifdef CXStr__CompareN
//FUNCTION_AT_ADDRESS(int  CXStr::CompareN(class CXStr const &,int,enum CompareCode)const ,CXStr__CompareN);
#endif
#ifdef CXStr__operator_equal_equal
FUNCTION_AT_ADDRESS(int  CXStr::operator==(class CXStr const &)const ,CXStr__operator_equal_equal);
#endif
#ifdef CXStr__operator_equal_equal1
FUNCTION_AT_ADDRESS(int  CXStr::operator==(char const *)const ,CXStr__operator_equal_equal1);
#endif
#ifdef CXStr__operatort_
FUNCTION_AT_ADDRESS(int  CXStr::operator>(class CXStr const &)const ,CXStr__operatort_);
#endif
#ifdef CXStr__BlankPreAllocate
FUNCTION_AT_ADDRESS(void  CXStr::BlankPreAllocate(int),CXStr__BlankPreAllocate);
#endif
#ifdef CXStr__operator_plus_equal
FUNCTION_AT_ADDRESS(void  CXStr::operator+=(class CXStr const &),CXStr__operator_plus_equal);
#endif
#ifdef CXStr__operator_plus_equal1
FUNCTION_AT_ADDRESS(void  CXStr::operator+=(char const *),CXStr__operator_plus_equal1);
#endif
#ifdef CXStr__operator_plus_equal2
FUNCTION_AT_ADDRESS(void  CXStr::operator+=(char),CXStr__operator_plus_equal2);
#endif
#ifdef CXStr__operator_plus_equal3
FUNCTION_AT_ADDRESS(void  CXStr::operator+=(unsigned short),CXStr__operator_plus_equal3);
#endif
#ifdef CXStr__Delete
FUNCTION_AT_ADDRESS(void  CXStr::Delete(long,long),CXStr__Delete);
#endif
#ifdef CXStr__Insert
FUNCTION_AT_ADDRESS(void  CXStr::Insert(long,char),CXStr__Insert);
#endif
#ifdef CXStr__Insert1
FUNCTION_AT_ADDRESS(void  CXStr::Insert(long,class CXStr const &),CXStr__Insert1);
#endif
#ifdef CXStr__Copy
FUNCTION_AT_ADDRESS(class CXStr  CXStr::Copy(long,long)const ,CXStr__Copy);
#endif
#ifdef CXStr__CopySelf
FUNCTION_AT_ADDRESS(void  CXStr::CopySelf(long,long),CXStr__CopySelf);
#endif
#ifdef CXStr__StripTrailing
FUNCTION_AT_ADDRESS(void  CXStr::StripTrailing(char),CXStr__StripTrailing);
#endif
#ifdef CXStr__StripLeading
FUNCTION_AT_ADDRESS(void  CXStr::StripLeading(char),CXStr__StripLeading);
#endif
#ifdef CXStr__StripAll
FUNCTION_AT_ADDRESS(void  CXStr::StripAll(char),CXStr__StripAll);
#endif
#ifdef CXStr__Strip
FUNCTION_AT_ADDRESS(void  CXStr::Strip(char),CXStr__Strip);
#endif
#ifdef CXStr__GetEncoding
//FUNCTION_AT_ADDRESS(enum EStringEncoding  CXStr::GetEncoding(void)const ,CXStr__GetEncoding);
#endif
#ifdef CXStr__SetEncoding
//FUNCTION_AT_ADDRESS(void  CXStr::SetEncoding(enum EStringEncoding),CXStr__SetEncoding);
#endif
#ifdef CXStr__operator_char_p
//FUNCTION_AT_ADDRESS( CXStr::operator char *(void)const ,CXStr__operator_char_p);
#endif
#ifdef CXStr__operator_unsigned_short_p
//FUNCTION_AT_ADDRESS( CXStr::operator unsigned short *(void)const ,CXStr__operator_unsigned_short_p);
#endif
#ifdef CXStr__SetUpperCase
FUNCTION_AT_ADDRESS(void  CXStr::SetUpperCase(void),CXStr__SetUpperCase);
#endif
#ifdef CXStr__SetLowerCase
FUNCTION_AT_ADDRESS(void  CXStr::SetLowerCase(void),CXStr__SetLowerCase);
#endif
#ifdef CXStr__ConvertToInt
FUNCTION_AT_ADDRESS(int  CXStr::ConvertToInt(void),CXStr__ConvertToInt);
#endif
#ifdef CXStr__PrintString
FUNCTION_AT_ADDRESS(int __cdecl CXStr::PrintString(char const *,...),CXStr__PrintString);
#endif
#ifdef CXStr__FindLast
FUNCTION_AT_ADDRESS(bool  CXStr::FindLast(char,int &),CXStr__FindLast);
#endif
#ifdef CXStr__Find
FUNCTION_AT_ADDRESS(bool  CXStr::Find(char,int &),CXStr__Find);
#endif
#ifdef CXStr__Find1
FUNCTION_AT_ADDRESS(bool  CXStr::Find(unsigned short,int &),CXStr__Find1);
#endif
#ifdef CXStr__Find2
FUNCTION_AT_ADDRESS(bool  CXStr::Find(class CXStr const &,int &),CXStr__Find2);
#endif
#ifdef CXStr__AddCr
FUNCTION_AT_ADDRESS(void  CXStr::AddCr(void),CXStr__AddCr);
#endif
#ifdef CXStr__Utf8ToUnicode
FUNCTION_AT_ADDRESS(int __cdecl CXStr::Utf8ToUnicode(char const *,unsigned short *,int),CXStr__Utf8ToUnicode);
#endif
#ifdef CXStr__LenUnicodeToUtf8
FUNCTION_AT_ADDRESS(int __cdecl CXStr::LenUnicodeToUtf8(unsigned short const *),CXStr__LenUnicodeToUtf8);
#endif
#ifdef CXStr__UnicodeToUtf8
FUNCTION_AT_ADDRESS(int __cdecl CXStr::UnicodeToUtf8(unsigned short const *,char *,int),CXStr__UnicodeToUtf8);
#endif
#ifdef CListWnd__CListWnd
FUNCTION_AT_ADDRESS( CListWnd::CListWnd(class CXWnd *,unsigned __int32,class CXRect),CListWnd__CListWnd);
#endif
#ifdef CListWnd__GetCurSel
FUNCTION_AT_ADDRESS(int  CListWnd::GetCurSel(void)const,CListWnd__GetCurSel);
#endif
#ifdef CListWnd__GetCurCol
FUNCTION_AT_ADDRESS(int  CListWnd::GetCurCol(void)const ,CListWnd__GetCurCol);
#endif
#ifdef CListWnd__GetItemData
FUNCTION_AT_ADDRESS(unsigned __int32  CListWnd::GetItemData(int)const ,CListWnd__GetItemData);
#endif
#ifdef CListWnd__GetItemText
FUNCTION_AT_ADDRESS(class CXStr *CListWnd::GetItemText(class CXStr *,int,int)const ,CListWnd__GetItemText);
#endif
#ifdef CListWnd__GetItemIcon
FUNCTION_AT_ADDRESS(class CTextureAnimation const *  CListWnd::GetItemIcon(int,int)const ,CListWnd__GetItemIcon);
#endif
#ifdef CListWnd__GetItemColor
FUNCTION_AT_ADDRESS(unsigned long  CListWnd::GetItemColor(int,int)const ,CListWnd__GetItemColor);
#endif
#ifdef CListWnd__GetColumnFlags
FUNCTION_AT_ADDRESS(unsigned __int32  CListWnd::GetColumnFlags(int)const ,CListWnd__GetColumnFlags);
#endif
#ifdef CListWnd__GetColumnWidth
FUNCTION_AT_ADDRESS(int  CListWnd::GetColumnWidth(int)const ,CListWnd__GetColumnWidth);
#endif
#ifdef CListWnd__SetColumnWidth
FUNCTION_AT_ADDRESS(void  CListWnd::SetColumnWidth(int,int),CListWnd__SetColumnWidth);
#endif
#ifdef CListWnd__ShiftColumnSeparator
FUNCTION_AT_ADDRESS(void  CListWnd::ShiftColumnSeparator(int,int),CListWnd__ShiftColumnSeparator);
#endif
#ifdef CListWnd__GetColumnMinWidth
FUNCTION_AT_ADDRESS(int  CListWnd::GetColumnMinWidth(int)const ,CListWnd__GetColumnMinWidth);
#endif
#ifdef CListWnd__GetColumnJustification
FUNCTION_AT_ADDRESS(int  CListWnd::GetColumnJustification(int)const ,CListWnd__GetColumnJustification);
#endif
#ifdef CListWnd__SetColumnJustification
FUNCTION_AT_ADDRESS(void  CListWnd::SetColumnJustification(int,int),CListWnd__SetColumnJustification);
#endif
#ifdef CListWnd__GetColumnLabel
FUNCTION_AT_ADDRESS(class CXStr  CListWnd::GetColumnLabel(int)const ,CListWnd__GetColumnLabel);
#endif
#ifdef CListWnd__GetColumnAnimation
FUNCTION_AT_ADDRESS(class CTextureAnimation const *  CListWnd::GetColumnAnimation(int)const ,CListWnd__GetColumnAnimation);
#endif
#ifdef CListWnd__GetColumnAnimationSelected
FUNCTION_AT_ADDRESS(class CTextureAnimation const *  CListWnd::GetColumnAnimationSelected(int)const ,CListWnd__GetColumnAnimationSelected);
#endif
#ifdef CListWnd__GetColumnAnimationMouseOver
FUNCTION_AT_ADDRESS(class CTextureAnimation const *  CListWnd::GetColumnAnimationMouseOver(int)const ,CListWnd__GetColumnAnimationMouseOver);
#endif
#ifdef CListWnd__AddLine
FUNCTION_AT_ADDRESS(int  CListWnd::AddLine(class SListWndLine const *),CListWnd__AddLine);
#endif
#ifdef CListWnd__AddString
FUNCTION_AT_ADDRESS(int  CListWnd::AddString(class CXStr *,unsigned long,unsigned __int32,class CTextureAnimation const *, const char *),CListWnd__AddString);
#endif
#ifdef CListWnd__RemoveString
FUNCTION_AT_ADDRESS(void  CListWnd::RemoveString(int),CListWnd__RemoveString);
#endif
#ifdef CListWnd__RemoveLine
FUNCTION_AT_ADDRESS(void  CListWnd::RemoveLine(int),CListWnd__RemoveLine);
#endif
#ifdef CListWnd__SetCurSel
FUNCTION_AT_ADDRESS(void  CListWnd::SetCurSel(int),CListWnd__SetCurSel);
#endif
#ifdef CListWnd__ToggleSel
FUNCTION_AT_ADDRESS(void  CListWnd::ToggleSel(int),CListWnd__ToggleSel);
#endif
#ifdef CListWnd__ExtendSel
FUNCTION_AT_ADDRESS(void  CListWnd::ExtendSel(int),CListWnd__ExtendSel);
#endif
#ifdef CListWnd__ClearAllSel
FUNCTION_AT_ADDRESS(void  CListWnd::ClearAllSel(void),CListWnd__ClearAllSel);
#endif
#ifdef CListWnd__ClearSel
FUNCTION_AT_ADDRESS(void  CListWnd::ClearSel(int),CListWnd__ClearSel);
#endif
#ifdef CListWnd__SetItemData
FUNCTION_AT_ADDRESS(void  CListWnd::SetItemData(int,unsigned __int32),CListWnd__SetItemData);
#endif
#ifdef CListWnd__SetItemText
FUNCTION_AT_ADDRESS(void  CListWnd::SetItemText(int,int,class CXStr *),CListWnd__SetItemText);
#endif
#ifdef CListWnd__SetItemColor
FUNCTION_AT_ADDRESS(void  CListWnd::SetItemColor(int,int,unsigned long),CListWnd__SetItemColor);
#endif
#ifdef CListWnd__IsLineEnabled
FUNCTION_AT_ADDRESS(bool  CListWnd::IsLineEnabled(int)const ,CListWnd__IsLineEnabled);
#endif
#ifdef CListWnd__EnableLine
FUNCTION_AT_ADDRESS(void  CListWnd::EnableLine(int,bool),CListWnd__EnableLine);
#endif
#ifdef CListWnd__AddColumn
FUNCTION_AT_ADDRESS(int  CListWnd::AddColumn(class CXStr,int,unsigned __int32,unsigned __int32),CListWnd__AddColumn);
#endif
#ifdef CListWnd__AddColumn1
FUNCTION_AT_ADDRESS(int  CListWnd::AddColumn(class CXStr,class CTextureAnimation *,int,unsigned __int32,unsigned __int32,class CTextureAnimation *,class CTextureAnimation *),CListWnd__AddColumn1);
#endif
#ifdef SListWndColumn__SListWndColumn
FUNCTION_AT_ADDRESS( SListWndColumn::SListWndColumn(class CXStr,int,class CTextureAnimation *,unsigned __int32,unsigned __int32,class CTextureAnimation *,class CTextureAnimation *),SListWndColumn__SListWndColumn);
#endif
#ifdef SLinkInfo__dSLinkInfo
//FUNCTION_AT_ADDRESS( SLinkInfo::~SLinkInfo(void),SLinkInfo__dSLinkInfo);
#endif
#ifdef SListWndCellEditUpdate__dSListWndCellEditUpdate
FUNCTION_AT_ADDRESS( SListWndCellEditUpdate::~SListWndCellEditUpdate(void),SListWndCellEditUpdate__dSListWndCellEditUpdate);
#endif
#ifdef SListWndColumn__dSListWndColumn
FUNCTION_AT_ADDRESS( SListWndColumn::~SListWndColumn(void),SListWndColumn__dSListWndColumn);
#endif
#ifdef CListWnd__SetColumnLabel
FUNCTION_AT_ADDRESS(void  CListWnd::SetColumnLabel(int,class CXStr),CListWnd__SetColumnLabel);
#endif
#ifdef CXRect__CXRect1
FUNCTION_AT_ADDRESS( CXRect::CXRect(void),CXRect__CXRect1);
#endif
#ifdef CListWnd__GetItemHeight
FUNCTION_AT_ADDRESS(int  CListWnd::GetItemHeight(int)const ,CListWnd__GetItemHeight);
#endif
#ifdef CListWnd__CalculateLineHeights
FUNCTION_AT_ADDRESS(void  CListWnd::CalculateLineHeights(void),CListWnd__CalculateLineHeights);
#endif
#ifdef CListWnd__CalculateVSBRange
FUNCTION_AT_ADDRESS(void  CListWnd::CalculateVSBRange(void),CListWnd__CalculateVSBRange);
#endif
#ifdef CListWnd__CalculateFirstVisibleLine
FUNCTION_AT_ADDRESS(void  CListWnd::CalculateFirstVisibleLine(void),CListWnd__CalculateFirstVisibleLine);
#endif
#ifdef CListWnd__EnsureVisible
FUNCTION_AT_ADDRESS(void  CListWnd::EnsureVisible(int),CListWnd__EnsureVisible);
#endif
#ifdef CListWnd__GetItemRect
FUNCTION_AT_ADDRESS(class CXRect  CListWnd::GetItemRect(int,int)const ,CListWnd__GetItemRect);
#endif
#ifdef CListWnd__GetItemAtPoint
FUNCTION_AT_ADDRESS(int  CListWnd::GetItemAtPoint(class CXPoint)const ,CListWnd__GetItemAtPoint);
#endif
#ifdef CListWnd__GetItemAtPoint1
FUNCTION_AT_ADDRESS(void  CListWnd::GetItemAtPoint(class CXPoint,int *,int *)const ,CListWnd__GetItemAtPoint1);
#endif
#ifdef CListWnd__CloseAndUpdateEditWindow
FUNCTION_AT_ADDRESS(void  CListWnd::CloseAndUpdateEditWindow(void),CListWnd__CloseAndUpdateEditWindow);
#endif
#ifdef CListWnd__SetColors
FUNCTION_AT_ADDRESS(void  CListWnd::SetColors(unsigned long,unsigned long,unsigned long),CListWnd__SetColors);
#endif
#ifdef CListWnd__GetSeparatorRect
FUNCTION_AT_ADDRESS(class CXRect  CListWnd::GetSeparatorRect(int)const ,CListWnd__GetSeparatorRect);
#endif
#ifdef SListWndSortInfo__dSListWndSortInfo
FUNCTION_AT_ADDRESS( SListWndSortInfo::~SListWndSortInfo(void),SListWndSortInfo__dSListWndSortInfo);
#endif
#ifdef CListWnd__GetHeaderRect
FUNCTION_AT_ADDRESS(class CXRect  CListWnd::GetHeaderRect(int)const ,CListWnd__GetHeaderRect);
#endif
#ifdef SListWndLine__SListWndLine
FUNCTION_AT_ADDRESS( SListWndLine::SListWndLine(void),SListWndLine__SListWndLine);
#endif
#ifdef SListWndCell__operator_equal
FUNCTION_AT_ADDRESS(struct SListWndCell &  SListWndCell::operator=(struct SListWndCell const &),SListWndCell__operator_equal);
#endif
#ifdef SListWndLine__operator_equal
FUNCTION_AT_ADDRESS(class SListWndLine &  SListWndLine::operator=(class SListWndLine const &),SListWndLine__operator_equal);
#endif
#ifdef CScreenPieceTemplate__CScreenPieceTemplate
FUNCTION_AT_ADDRESS( CScreenPieceTemplate::CScreenPieceTemplate(class CParamScreenPiece *),CScreenPieceTemplate__CScreenPieceTemplate);
#endif
#ifdef CScreenPieceTemplate__IsType
FUNCTION_AT_ADDRESS(bool  CScreenPieceTemplate::IsType(unsigned __int32)const ,CScreenPieceTemplate__IsType);
#endif
#ifdef CStaticScreenPieceTemplate__CStaticScreenPieceTemplate
FUNCTION_AT_ADDRESS( CStaticScreenPieceTemplate::CStaticScreenPieceTemplate(class CParamStaticScreenPiece *),CStaticScreenPieceTemplate__CStaticScreenPieceTemplate);
#endif
#ifdef CStaticAnimationTemplate__CStaticAnimationTemplate
FUNCTION_AT_ADDRESS( CStaticAnimationTemplate::CStaticAnimationTemplate(class CParamStaticAnimation *),CStaticAnimationTemplate__CStaticAnimationTemplate);
#endif
#ifdef CStaticTextTemplate__CStaticTextTemplate
FUNCTION_AT_ADDRESS( CStaticTextTemplate::CStaticTextTemplate(class CParamStaticText *),CStaticTextTemplate__CStaticTextTemplate);
#endif
#ifdef CStaticTextTemplate__SetText
FUNCTION_AT_ADDRESS(class CXStr  CStaticTextTemplate::SetText(class CXStr),CStaticTextTemplate__SetText);
#endif
#ifdef CStaticFrameTemplate__CStaticFrameTemplate
FUNCTION_AT_ADDRESS( CStaticFrameTemplate::CStaticFrameTemplate(class CParamStaticFrame *),CStaticFrameTemplate__CStaticFrameTemplate);
#endif
#ifdef CStaticHeaderTemplate__CStaticHeaderTemplate
FUNCTION_AT_ADDRESS( CStaticHeaderTemplate::CStaticHeaderTemplate(class CParamStaticHeader *),CStaticHeaderTemplate__CStaticHeaderTemplate);
#endif
#ifdef CControlTemplate__CControlTemplate
FUNCTION_AT_ADDRESS( CControlTemplate::CControlTemplate(class CParamControl *),CControlTemplate__CControlTemplate);
#endif
#ifdef CListboxColumnTemplate__CListboxColumnTemplate
FUNCTION_AT_ADDRESS( CListboxColumnTemplate::CListboxColumnTemplate(class CParamListboxColumn *),CListboxColumnTemplate__CListboxColumnTemplate);
#endif
#ifdef CListboxTemplate__CListboxTemplate
FUNCTION_AT_ADDRESS( CListboxTemplate::CListboxTemplate(class CParamListbox *),CListboxTemplate__CListboxTemplate);
#endif
#ifdef CListboxColumnTemplate__dCListboxColumnTemplate
FUNCTION_AT_ADDRESS( CListboxColumnTemplate::~CListboxColumnTemplate(void),CListboxColumnTemplate__dCListboxColumnTemplate);
#endif
#ifdef CButtonTemplate__CButtonTemplate
FUNCTION_AT_ADDRESS( CButtonTemplate::CButtonTemplate(class CParamButton *),CButtonTemplate__CButtonTemplate);
#endif
#ifdef CGaugeTemplate__CGaugeTemplate
FUNCTION_AT_ADDRESS( CGaugeTemplate::CGaugeTemplate(class CParamGauge *),CGaugeTemplate__CGaugeTemplate);
#endif
#ifdef CSpellGemTemplate__CSpellGemTemplate
FUNCTION_AT_ADDRESS( CSpellGemTemplate::CSpellGemTemplate(class CParamSpellGem *),CSpellGemTemplate__CSpellGemTemplate);
#endif
#ifdef CInvSlotTemplate__CInvSlotTemplate
FUNCTION_AT_ADDRESS( CInvSlotTemplate::CInvSlotTemplate(class CParamInvSlot *),CInvSlotTemplate__CInvSlotTemplate);
#endif
#ifdef CEditboxTemplate__CEditboxTemplate
FUNCTION_AT_ADDRESS( CEditboxTemplate::CEditboxTemplate(class CParamEditbox *),CEditboxTemplate__CEditboxTemplate);
#endif
#ifdef CSliderTemplate__CSliderTemplate
FUNCTION_AT_ADDRESS( CSliderTemplate::CSliderTemplate(class CParamSlider *),CSliderTemplate__CSliderTemplate);
#endif
#ifdef CLabelTemplate__CLabelTemplate
FUNCTION_AT_ADDRESS( CLabelTemplate::CLabelTemplate(class CParamLabel *),CLabelTemplate__CLabelTemplate);
#endif
#ifdef CSTMLboxTemplate__CSTMLboxTemplate
FUNCTION_AT_ADDRESS( CSTMLboxTemplate::CSTMLboxTemplate(class CParamSTMLbox *),CSTMLboxTemplate__CSTMLboxTemplate);
#endif
#ifdef CComboboxTemplate__CComboboxTemplate
FUNCTION_AT_ADDRESS( CComboboxTemplate::CComboboxTemplate(class CParamCombobox *),CComboboxTemplate__CComboboxTemplate);
#endif
#ifdef CPageTemplate__CPageTemplate
FUNCTION_AT_ADDRESS( CPageTemplate::CPageTemplate(class CParamPage *),CPageTemplate__CPageTemplate);
#endif
#ifdef CTabBoxTemplate__CTabBoxTemplate
FUNCTION_AT_ADDRESS( CTabBoxTemplate::CTabBoxTemplate(class CParamTabBox *),CTabBoxTemplate__CTabBoxTemplate);
#endif
#ifdef CScreenTemplate__CScreenTemplate
FUNCTION_AT_ADDRESS( CScreenTemplate::CScreenTemplate(class CParamScreen *),CScreenTemplate__CScreenTemplate);
#endif
#ifdef CStmlWnd__CStmlWnd
FUNCTION_AT_ADDRESS( CStmlWnd::CStmlWnd(class CXWnd *,unsigned __int32,class CXRect),CStmlWnd__CStmlWnd);
#endif
#ifdef CStmlWnd__InitializeTextLine
FUNCTION_AT_ADDRESS(void  CStmlWnd::InitializeTextLine(class SParseVariables *,int),CStmlWnd__InitializeTextLine);
#endif
#ifdef CStmlWnd__AddTextPieceToLine
FUNCTION_AT_ADDRESS(void  CStmlWnd::AddTextPieceToLine(class SParseVariables *),CStmlWnd__AddTextPieceToLine);
#endif
#ifdef CStmlWnd__MakeStmlColorTag
FUNCTION_AT_ADDRESS(class CXStr __cdecl CStmlWnd::MakeStmlColorTag(unsigned long),CStmlWnd__MakeStmlColorTag);
#endif
#ifdef CTextureAnimation__GetName
FUNCTION_AT_ADDRESS(class CXStr  CTextureAnimation::GetName(void)const ,CTextureAnimation__GetName);
#endif
#ifdef CStmlWnd__MakeWndNotificationTag
FUNCTION_AT_ADDRESS(class CXStr __cdecl CStmlWnd::MakeWndNotificationTag(unsigned __int32,class CXStr&,class CXStr&),CStmlWnd__MakeWndNotificationTag);
#endif
#ifdef CStmlWnd__ParseTagColor
FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseTagColor(class CXStr,unsigned long *)const ,CStmlWnd__ParseTagColor);
#endif
#ifdef CStmlWnd__ParseTagFace
FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseTagFace(class CXStr,class CTextureFont const * *)const ,CStmlWnd__ParseTagFace);
#endif
#ifdef CStmlWnd__ParseTagAlign
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseTagAlign(class CXStr,enum ESTMLAlign *)const ,CStmlWnd__ParseTagAlign);
#endif
#ifdef SAmpersandEntry__SAmpersandEntry
FUNCTION_AT_ADDRESS( SAmpersandEntry::SAmpersandEntry(class CXStr,char),SAmpersandEntry__SAmpersandEntry);
#endif
#ifdef CButtonDrawTemplate__dCButtonDrawTemplate
FUNCTION_AT_ADDRESS( CButtonDrawTemplate::~CButtonDrawTemplate(void),CButtonDrawTemplate__dCButtonDrawTemplate);
#endif
#ifdef CGaugeDrawTemplate__dCGaugeDrawTemplate
FUNCTION_AT_ADDRESS( CGaugeDrawTemplate::~CGaugeDrawTemplate(void),CGaugeDrawTemplate__dCGaugeDrawTemplate);
#endif
#ifdef CSpellGemDrawTemplate__dCSpellGemDrawTemplate
FUNCTION_AT_ADDRESS( CSpellGemDrawTemplate::~CSpellGemDrawTemplate(void),CSpellGemDrawTemplate__dCSpellGemDrawTemplate);
#endif
#ifdef CTAFrameDraw__dCTAFrameDraw
FUNCTION_AT_ADDRESS( CTAFrameDraw::~CTAFrameDraw(void),CTAFrameDraw__dCTAFrameDraw);
#endif
#ifdef SAmpersandEntry__dSAmpersandEntry
FUNCTION_AT_ADDRESS( SAmpersandEntry::~SAmpersandEntry(void),SAmpersandEntry__dSAmpersandEntry);
#endif
#ifdef STempTableCell__dSTempTableCell
FUNCTION_AT_ADDRESS( STempTableCell::~STempTableCell(void),STempTableCell__dSTempTableCell);
#endif
#ifdef CXStr__Blank
FUNCTION_AT_ADDRESS(void  CXStr::Blank(void),CXStr__Blank);
#endif
#ifdef CStmlWnd__ParseAmpersand
FUNCTION_AT_ADDRESS(bool  CStmlWnd::ParseAmpersand(class CXStr&,char *)const ,CStmlWnd__ParseAmpersand);
#endif
#ifdef CStmlWnd__ParseLinkTarget
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseLinkTarget(class CXStr,enum ESTMLTargetValue *)const ,CStmlWnd__ParseLinkTarget);
#endif
#ifdef CStmlWnd__FastForwardPastSpaces
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::FastForwardPastSpaces(class CXStr&,int *),CStmlWnd__FastForwardPastSpaces);
#endif
#ifdef CStmlWnd__FastForwardPastSpacesAndQuotes
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::FastForwardPastSpacesAndQuotes(class CXStr&,int *),CStmlWnd__FastForwardPastSpacesAndQuotes);
#endif
#ifdef CStmlWnd__GetNextTagPiece
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::GetNextTagPiece(class CXStr&,class CXStr *,int *,bool (__cdecl*)(unsigned short),bool),CStmlWnd__GetNextTagPiece);
#endif
#ifdef CStmlWnd__IsCharacterNotQuotes
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::IsCharacterNotQuotes(unsigned short),CStmlWnd__IsCharacterNotQuotes);
#endif
#ifdef CStmlWnd__FastForwardPastQuotesAndGetNextTagPiece
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::FastForwardPastQuotesAndGetNextTagPiece(class CXStr&,class CXStr *,int *,bool),CStmlWnd__FastForwardPastQuotesAndGetNextTagPiece);
#endif
#ifdef CStmlWnd__FastForwardToEndOfTag
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::FastForwardToEndOfTag(class CXStr&,class CXStr *,int *,char),CStmlWnd__FastForwardToEndOfTag);
#endif
#ifdef CStmlWnd__InitializeTempVariables
FUNCTION_AT_ADDRESS(void  CStmlWnd::InitializeTempVariables(class SParseVariables *,class CXRect),CStmlWnd__InitializeTempVariables);
#endif
#ifdef CStmlWnd__InitializeWindowVariables
FUNCTION_AT_ADDRESS(void  CStmlWnd::InitializeWindowVariables(void),CStmlWnd__InitializeWindowVariables);
#endif
#ifdef CStmlWnd__ResetTempVariablesForNewLine
FUNCTION_AT_ADDRESS(void  CStmlWnd::ResetTempVariablesForNewLine(class SParseVariables *),CStmlWnd__ResetTempVariablesForNewLine);
#endif
#ifdef CStmlWnd__GetNextChar
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::GetNextChar(int *,class CXStr&),CStmlWnd__GetNextChar);
#endif
#ifdef CStmlWnd__GetThisChar
FUNCTION_AT_ADDRESS(unsigned short  CStmlWnd::GetThisChar(int,class CXStr&),CStmlWnd__GetThisChar);
#endif
#ifdef CStmlWnd__IsCharacterNotEquals
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::IsCharacterNotEquals(unsigned short),CStmlWnd__IsCharacterNotEquals);
#endif
#ifdef CStmlWnd__IsCharacterNotASpaceAndNotNULL
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::IsCharacterNotASpaceAndNotNULL(unsigned short),CStmlWnd__IsCharacterNotASpaceAndNotNULL);
#endif
#ifdef SParseVariables__dSParseVariables
FUNCTION_AT_ADDRESS( SParseVariables::~SParseVariables(void),SParseVariables__dSParseVariables);
#endif
#ifdef SFormattedText__dSFormattedText
FUNCTION_AT_ADDRESS( SFormattedText::~SFormattedText(void),SFormattedText__dSFormattedText);
#endif
#ifdef CStmlWnd__ParseSTMLHead
FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseSTMLHead(class CXStr&),CStmlWnd__ParseSTMLHead);
#endif
#ifdef CStmlWnd__ParseSTMLTable
FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseSTMLTable(class CXStr&,int *,class CXStr&,class SParseVariables *),CStmlWnd__ParseSTMLTable);
#endif
#ifdef STempTable__dSTempTable
FUNCTION_AT_ADDRESS( STempTable::~STempTable(void),STempTable__dSTempTable);
#endif
#ifdef STable__STable
FUNCTION_AT_ADDRESS( STable::STable(void),STable__STable);
#endif
#ifdef STable__dSTable
FUNCTION_AT_ADDRESS( STable::~STable(void),STable__dSTable);
#endif
#ifdef STableCell__dSTableCell
FUNCTION_AT_ADDRESS( STableCell::~STableCell(void),STableCell__dSTableCell);
#endif
#ifdef CStmlWnd__ParseSTMLTableAttributes
FUNCTION_AT_ADDRESS(void  CStmlWnd::ParseSTMLTableAttributes(class CXStr,class STable *),CStmlWnd__ParseSTMLTableAttributes);
#endif
#ifdef CStmlWnd__GetVisiableText
FUNCTION_AT_ADDRESS(class CXStr  CStmlWnd::GetVisiableText(class CXStr&,class CXRect)const ,CStmlWnd__GetVisiableText);
#endif
#ifdef CStmlWnd__ForceParseNow
FUNCTION_AT_ADDRESS(void  CStmlWnd::ForceParseNow(void),CStmlWnd__ForceParseNow);
#endif
#ifdef CStmlWnd__CalculateVSBRange
FUNCTION_AT_ADDRESS(void  CStmlWnd::CalculateVSBRange(int),CStmlWnd__CalculateVSBRange);
#endif
#ifdef CStmlWnd__CalculateHSBRange
FUNCTION_AT_ADDRESS(void  CStmlWnd::CalculateHSBRange(int),CStmlWnd__CalculateHSBRange);
#endif
#ifdef CStmlReport__GetReport
FUNCTION_AT_ADDRESS(class CXStr  CStmlReport::GetReport(void)const ,CStmlReport__GetReport);
#endif
#ifdef CStmlWnd__CompleteParse
FUNCTION_AT_ADDRESS(void  CStmlWnd::CompleteParse(void),CStmlWnd__CompleteParse);
#endif
#ifdef CStmlWnd__StripFirstSTMLLines
FUNCTION_AT_ADDRESS(void  CStmlWnd::StripFirstSTMLLines(int),CStmlWnd__StripFirstSTMLLines);
#endif
#ifdef CStmlWnd__ActivateLink
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ActivateLink(class SLinkInfo),CStmlWnd__ActivateLink);
#endif
#ifdef SLinkInfo__SLinkInfo
//FUNCTION_AT_ADDRESS( SLinkInfo::SLinkInfo(class SLinkInfo const &),SLinkInfo__SLinkInfo);
#endif
#ifdef CStmlWnd__CanBreakAtCharacter
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::CanBreakAtCharacter(unsigned short),CStmlWnd__CanBreakAtCharacter);
#endif
#ifdef CStmlWnd__ActivateLinkFile
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ActivateLinkFile(class SLinkInfo),CStmlWnd__ActivateLinkFile);
#endif
#ifdef CStmlWnd__ActivateLinkMessageId
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ActivateLinkMessageId(class SLinkInfo),CStmlWnd__ActivateLinkMessageId);
#endif
#ifdef CStmlWnd__ActivateLinkReport
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ActivateLinkReport(class SLinkInfo,bool),CStmlWnd__ActivateLinkReport);
#endif
#ifdef CStmlWnd__ActivateLinkWndNotify
//FUNCTION_AT_ADDRESS(void  CStmlWnd::ActivateLinkWndNotify(class SLinkInfo),CStmlWnd__ActivateLinkWndNotify);
#endif
#ifdef CStmlWnd__LoadPage
//FUNCTION_AT_ADDRESS(void  CStmlWnd::LoadPage(class CXStr,enum ESTMLTargetValue,bool),CStmlWnd__LoadPage);
#endif
#ifdef CStmlWnd__AddLinkToHistory
//FUNCTION_AT_ADDRESS(void  CStmlWnd::AddLinkToHistory(class SLinkInfo,class CXStr),CStmlWnd__AddLinkToHistory);
#endif
#ifdef SLinkInfo__operator_equal
//FUNCTION_AT_ADDRESS(class SLinkInfo &  SLinkInfo::operator=(class SLinkInfo const &),SLinkInfo__operator_equal);
#endif
#ifdef CStmlWnd__UpdateHistoryString
FUNCTION_AT_ADDRESS(void  CStmlWnd::UpdateHistoryString(__int32,class CXStr&),CStmlWnd__UpdateHistoryString);
#endif
#ifdef CStmlWnd__SetSTMLText
FUNCTION_AT_ADDRESS(void  CStmlWnd::SetSTMLText(class CXStr &,bool,class SLinkInfo *),CStmlWnd__SetSTMLText);
#endif
#ifdef SLinkInfo__SLinkInfo1
//FUNCTION_AT_ADDRESS( SLinkInfo::SLinkInfo(void),SLinkInfo__SLinkInfo1);
#endif
#ifdef CStmlWnd__SetSTMLTextWithoutHistory
FUNCTION_AT_ADDRESS(void  CStmlWnd::SetSTMLTextWithoutHistory(class CXStr),CStmlWnd__SetSTMLTextWithoutHistory);
#endif
#ifdef CStmlWnd__GoToBackHistoryLink
FUNCTION_AT_ADDRESS(void  CStmlWnd::GoToBackHistoryLink(void),CStmlWnd__GoToBackHistoryLink);
#endif
#ifdef CStmlWnd__CanGoBackward
FUNCTION_AT_ADDRESS(bool  CStmlWnd::CanGoBackward(void),CStmlWnd__CanGoBackward);
#endif
#ifdef CStmlWnd__IsLinkActive
//FUNCTION_AT_ADDRESS(bool  CStmlWnd::IsLinkActive(class SLinkInfo)const,CStmlWnd__IsLinkActive);
#endif
#ifdef CXStr__GetLength
FUNCTION_AT_ADDRESS(long  CXStr::GetLength(void)const ,CXStr__GetLength);
#endif
#ifdef STextLine__STextLine
FUNCTION_AT_ADDRESS( STextLine::STextLine(void),STextLine__STextLine);
#endif
#ifdef STextLine__dSTextLine
FUNCTION_AT_ADDRESS( STextLine::~STextLine(void),STextLine__dSTextLine);
#endif
#ifdef STempTableCell__STempTableCell
FUNCTION_AT_ADDRESS( STempTableCell::STempTableCell(void),STempTableCell__STempTableCell);
#endif
#ifdef STempTableRow__STempTableRow
FUNCTION_AT_ADDRESS( STempTableRow::STempTableRow(void),STempTableRow__STempTableRow);
#endif
#ifdef STempTableRow__dSTempTableRow
FUNCTION_AT_ADDRESS( STempTableRow::~STempTableRow(void),STempTableRow__dSTempTableRow);
#endif
#ifdef STextLine__operator_equal
FUNCTION_AT_ADDRESS(class STextLine &  STextLine::operator=(class STextLine const &),STextLine__operator_equal);
#endif
#ifdef SHistoryElement__SHistoryElement
FUNCTION_AT_ADDRESS( SHistoryElement::SHistoryElement(void),SHistoryElement__SHistoryElement);
#endif
#ifdef SHistoryElement__dSHistoryElement
FUNCTION_AT_ADDRESS( SHistoryElement::~SHistoryElement(void),SHistoryElement__dSHistoryElement);
#endif
#ifdef SFormattedText__SFormattedText
FUNCTION_AT_ADDRESS( SFormattedText::SFormattedText(void),SFormattedText__SFormattedText);
#endif
#ifdef STable__operator_equal
FUNCTION_AT_ADDRESS(class STable &  STable::operator=(class STable const &),STable__operator_equal);
#endif
#ifdef STableCell__STableCell
FUNCTION_AT_ADDRESS( STableCell::STableCell(void),STableCell__STableCell);
#endif
#ifdef CTabWnd__CTabWnd
FUNCTION_AT_ADDRESS( CTabWnd::CTabWnd(class CXWnd *,unsigned __int32,class CXRect,class CTabBoxTemplate *),CTabWnd__CTabWnd);
#endif
#ifdef CTabWnd__GetNumTabs
FUNCTION_AT_ADDRESS(int  CTabWnd::GetNumTabs(void)const ,CTabWnd__GetNumTabs);
#endif
#ifdef CTabWnd__GetCurrentTabIndex
FUNCTION_AT_ADDRESS(int  CTabWnd::GetCurrentTabIndex(void)const ,CTabWnd__GetCurrentTabIndex);
#endif
#ifdef CTabWnd__GetCurrentPage
FUNCTION_AT_ADDRESS(class CPageWnd *  CTabWnd::GetCurrentPage(void)const ,CTabWnd__GetCurrentPage);
#endif
#ifdef CTabWnd__GetTabRect
FUNCTION_AT_ADDRESS(class CXRect  CTabWnd::GetTabRect(int)const ,CTabWnd__GetTabRect);
#endif
#ifdef CTabWnd__GetTabInnerRect
FUNCTION_AT_ADDRESS(class CXRect  CTabWnd::GetTabInnerRect(int)const ,CTabWnd__GetTabInnerRect);
#endif
#ifdef CTabWnd__GetPageClientRect
FUNCTION_AT_ADDRESS(class CXRect  CTabWnd::GetPageClientRect(void)const ,CTabWnd__GetPageClientRect);
#endif
#ifdef CTabWnd__GetPageInnerRect
FUNCTION_AT_ADDRESS(class CXRect  CTabWnd::GetPageInnerRect(void)const ,CTabWnd__GetPageInnerRect);
#endif
#ifdef CTabWnd__SetPage
FUNCTION_AT_ADDRESS(void  CTabWnd::SetPage(int,bool),CTabWnd__SetPage);
#endif
#ifdef CTabWnd__SetPage1
FUNCTION_AT_ADDRESS(void  CTabWnd::SetPage(class CPageWnd *,bool),CTabWnd__SetPage1);
#endif
#ifdef CTabWnd__InsertPage
FUNCTION_AT_ADDRESS(void  CTabWnd::InsertPage(class CPageWnd *,int),CTabWnd__InsertPage);
#endif
#ifdef CTabWnd__SetPageRect
FUNCTION_AT_ADDRESS(void  CTabWnd::SetPageRect(class CXRect),CTabWnd__SetPageRect);
#endif
#ifdef CXWnd__Tile
FUNCTION_AT_ADDRESS(int  CXWnd::Tile(bool),CXWnd__Tile);
#endif
#ifdef CTabWnd__UpdatePage
FUNCTION_AT_ADDRESS(void  CTabWnd::UpdatePage(void),CTabWnd__UpdatePage);
#endif
#ifdef CTabWnd__IndexInBounds
FUNCTION_AT_ADDRESS(bool  CTabWnd::IndexInBounds(int)const ,CTabWnd__IndexInBounds);
#endif
#ifdef CTabWnd__GetPageFromTabIndex
FUNCTION_AT_ADDRESS(class CPageWnd *  CTabWnd::GetPageFromTabIndex(int)const ,CTabWnd__GetPageFromTabIndex);
#endif
#ifdef CTabWnd__GetPageFromTabPoint
FUNCTION_AT_ADDRESS(class CPageWnd *  CTabWnd::GetPageFromTabPoint(class CXPoint)const ,CTabWnd__GetPageFromTabPoint);
#endif
#ifdef CTabWnd__DrawTab
FUNCTION_AT_ADDRESS(int  CTabWnd::DrawTab(int)const ,CTabWnd__DrawTab);
#endif
#ifdef CPageWnd__GetTabText
FUNCTION_AT_ADDRESS(class CXStr  CPageWnd::GetTabText(void)const ,CPageWnd__GetTabText);
#endif
#ifdef CTabWnd__DrawCurrentPage
FUNCTION_AT_ADDRESS(int  CTabWnd::DrawCurrentPage(void)const ,CTabWnd__DrawCurrentPage);
#endif
#ifdef CXMLSOMDocumentBase__Init
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::Init(void),CXMLSOMDocumentBase__Init);
#endif
#ifdef CXMLSOMNodePtr__Assure
FUNCTION_AT_ADDRESS(void  CXMLSOMNodePtr::Assure(void)const ,CXMLSOMNodePtr__Assure);
#endif
#ifdef CXMLSOMDocumentBase__CursorInit
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::CursorInit(void),CXMLSOMDocumentBase__CursorInit);
#endif
#ifdef CXMLSOMNode__CXMLSOMNode
FUNCTION_AT_ADDRESS( CXMLSOMNode::CXMLSOMNode(void),CXMLSOMNode__CXMLSOMNode);
#endif
#ifdef CXMLSOMDocumentBase__Cursor
FUNCTION_AT_ADDRESS(class CXMLSOMCursor &  CXMLSOMDocumentBase::Cursor(void),CXMLSOMDocumentBase__Cursor);
#endif
#ifdef CXMLSOMDocumentBase__CursorParent
FUNCTION_AT_ADDRESS(class CXMLSOMCursor &  CXMLSOMDocumentBase::CursorParent(void),CXMLSOMDocumentBase__CursorParent);
#endif
#ifdef CXMLSOMDocumentBase__CursorNewChild
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::CursorNewChild(void),CXMLSOMDocumentBase__CursorNewChild);
#endif
#ifdef CXMLSOMDocumentBase__CursorNewSibling
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::CursorNewSibling(void),CXMLSOMDocumentBase__CursorNewSibling);
#endif
#ifdef CXMLSOMNodePtr__operator_equal
FUNCTION_AT_ADDRESS(class CXMLSOMNodePtr &  CXMLSOMNodePtr::operator=(class CXMLSOMNodePtr const &),CXMLSOMNodePtr__operator_equal);
#endif
#ifdef CXMLSOMDocumentBase__CursorSetPtr
//FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::CursorSetPtr(class CXMLSOMNodePtr),CXMLSOMDocumentBase__CursorSetPtr);
#endif
#ifdef CXMLSOMNodePtr__operator_minust_
FUNCTION_AT_ADDRESS(class CXMLSOMNode *  CXMLSOMNodePtr::operator->(void)const ,CXMLSOMNodePtr__operator_minust_);
#endif
#ifdef CXMLSOMDocumentBase__CursorPush
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::CursorPush(void),CXMLSOMDocumentBase__CursorPush);
#endif
#ifdef CXMLSOMDocumentBase__CursorPop
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::CursorPop(void),CXMLSOMDocumentBase__CursorPop);
#endif
#ifdef CXMLSOMDocumentBase__CursorNextSibling
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::CursorNextSibling(void),CXMLSOMDocumentBase__CursorNextSibling);
#endif
#ifdef CXMLSOMDocumentBase__CursorNextInOrder
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::CursorNextInOrder(void),CXMLSOMDocumentBase__CursorNextInOrder);
#endif
#ifdef CXMLSOMDocumentBase__CursorFind
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::CursorFind(class CXStr),CXMLSOMDocumentBase__CursorFind);
#endif
#ifdef CXMLSOMDocumentBase__GetAttrValueStr
FUNCTION_AT_ADDRESS(class CXStr  CXMLSOMDocumentBase::GetAttrValueStr(class CXStr),CXMLSOMDocumentBase__GetAttrValueStr);
#endif
#ifdef CXMLSOMDocumentBase__GetAttrValueStr1
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::GetAttrValueStr(class CXStr,class CXStr &),CXMLSOMDocumentBase__GetAttrValueStr1);
#endif
#ifdef CXMLSOMDocumentBase__GetAttrValueInt
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::GetAttrValueInt(class CXStr,__int32 &),CXMLSOMDocumentBase__GetAttrValueInt);
#endif
#ifdef CXMLSOMCursorSave__dCXMLSOMCursorSave
FUNCTION_AT_ADDRESS( CXMLSOMCursorSave::~CXMLSOMCursorSave(void),CXMLSOMCursorSave__dCXMLSOMCursorSave);
#endif
#ifdef CXMLSOMDocumentBase__CursorFieldFind
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::CursorFieldFind(class CXStr),CXMLSOMDocumentBase__CursorFieldFind);
#endif
#ifdef CXMLSOMDocumentBase__GetValue
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::GetValue(class CXStr,class CXStr &),CXMLSOMDocumentBase__GetValue);
#endif
#ifdef CXMLSOMDocumentBase__GetValue1
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::GetValue(class CXStr,__int32 &),CXMLSOMDocumentBase__GetValue1);
#endif
#ifdef CXMLSOMDocumentBase__GetValue2
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::GetValue(class CXStr,bool &),CXMLSOMDocumentBase__GetValue2);
#endif
#ifdef CXMLSOMDocumentBase__FieldParseClassItem
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::FieldParseClassItem(class CXStr,class CXStr &,class CXStr &),CXMLSOMDocumentBase__FieldParseClassItem);
#endif
#ifdef CXMLSOMDocumentBase__FieldParseItemOfClass
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::FieldParseItemOfClass(class CXStr,class CXStr,__int32 &,__int32 &),CXMLSOMDocumentBase__FieldParseItemOfClass);
#endif
#ifdef CXMLSOMDocumentBase__SetValue
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::SetValue(class CXStr,class CXStr),CXMLSOMDocumentBase__SetValue);
#endif
#ifdef CXMLSOMDocumentBase__SetValue1
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::SetValue(class CXStr,__int32),CXMLSOMDocumentBase__SetValue1);
#endif
#ifdef CXMLSOMDocumentBase__SetValue2
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::SetValue(class CXStr,bool),CXMLSOMDocumentBase__SetValue2);
#endif
#ifdef CXMLSOMDocumentBase__XMLReadNoValidate
FUNCTION_AT_ADDRESS(int  CXMLSOMDocumentBase::XMLReadNoValidate(class CXStr,class CXStr,class CXStr),CXMLSOMDocumentBase__XMLReadNoValidate);
#endif
#ifdef CXMLSOMDocumentBase__XMLRead
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::XMLRead(class CXStr*,class CXStr*,class CXStr*),CXMLSOMDocumentBase__XMLRead);
#endif
#ifdef CXMLSOMDocumentBase__XMLProcessComposite
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::XMLProcessComposite(class CXStr,class CXStr),CXMLSOMDocumentBase__XMLProcessComposite);
#endif
#ifdef CXMLSOMDocumentBase__SetErrorMsg
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::SetErrorMsg(class CXStr),CXMLSOMDocumentBase__SetErrorMsg);
#endif
#ifdef CXMLSOMDocumentBase__GetErrorMsg
FUNCTION_AT_ADDRESS(class CXStr  CXMLSOMDocumentBase::GetErrorMsg(void)const ,CXMLSOMDocumentBase__GetErrorMsg);
#endif
#ifdef CXMLSOMSchema__CXMLSOMSchema
FUNCTION_AT_ADDRESS( CXMLSOMSchema::CXMLSOMSchema(void),CXMLSOMSchema__CXMLSOMSchema);
#endif
#ifdef CXMLSOMSchema__dCXMLSOMSchema
FUNCTION_AT_ADDRESS( CXMLSOMSchema::~CXMLSOMSchema(void),CXMLSOMSchema__dCXMLSOMSchema);
#endif
#ifdef CXMLSOMCursorTraverseChildren__dCXMLSOMCursorTraverseChildren
FUNCTION_AT_ADDRESS( CXMLSOMCursorTraverseChildren::~CXMLSOMCursorTraverseChildren(void),CXMLSOMCursorTraverseChildren__dCXMLSOMCursorTraverseChildren);
#endif
#ifdef CXMLSOMDocumentBase__XMLMerge
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::XMLMerge(class CXMLSOMDocumentBase &),CXMLSOMDocumentBase__XMLMerge);
#endif
#ifdef CXMLSOMCursorTraverseChildren__Cursor
FUNCTION_AT_ADDRESS(class CXMLSOMCursor &  CXMLSOMCursorTraverseChildren::Cursor(void),CXMLSOMCursorTraverseChildren__Cursor);
#endif
#ifdef CXMLSOMDocumentBase__SetErrorMsgAtLine
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::SetErrorMsgAtLine(class CXStr,int,class CXStr),CXMLSOMDocumentBase__SetErrorMsgAtLine);
#endif
#ifdef CXMLSOMDocumentBase__SetErrorMsgAtCursor
FUNCTION_AT_ADDRESS(void  CXMLSOMDocumentBase::SetErrorMsgAtCursor(class CXStr),CXMLSOMDocumentBase__SetErrorMsgAtCursor);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaSimpleTypeNode
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchemaSimpleTypeNode(class CXMLSOMSimpleType &),CXMLSOMDocumentBase__ValidateSchemaSimpleTypeNode);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaElementType
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchemaElementType(void),CXMLSOMDocumentBase__ValidateSchemaElementType);
#endif
#ifdef CXMLSOMElementType__dCXMLSOMElementType
FUNCTION_AT_ADDRESS( CXMLSOMElementType::~CXMLSOMElementType(void),CXMLSOMElementType__dCXMLSOMElementType);
#endif
#ifdef CXMLSOMElement__dCXMLSOMElement
FUNCTION_AT_ADDRESS( CXMLSOMElement::~CXMLSOMElement(void),CXMLSOMElement__dCXMLSOMElement);
#endif
#ifdef CXMLSOMAttributeType__dCXMLSOMAttributeType
FUNCTION_AT_ADDRESS( CXMLSOMAttributeType::~CXMLSOMAttributeType(void),CXMLSOMAttributeType__dCXMLSOMAttributeType);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaSimpleType
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchemaSimpleType(void),CXMLSOMDocumentBase__ValidateSchemaSimpleType);
#endif
#ifdef CXMLSOMSimpleType__dCXMLSOMSimpleType
FUNCTION_AT_ADDRESS( CXMLSOMSimpleType::~CXMLSOMSimpleType(void),CXMLSOMSimpleType__dCXMLSOMSimpleType);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaDefinition
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchemaDefinition(void),CXMLSOMDocumentBase__ValidateSchemaDefinition);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaCategories
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchemaCategories(void),CXMLSOMDocumentBase__ValidateSchemaCategories);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaTypeRefs
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchemaTypeRefs(void),CXMLSOMDocumentBase__ValidateSchemaTypeRefs);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchema
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateSchema(void),CXMLSOMDocumentBase__ValidateSchema);
#endif
#ifdef CXMLSOMDocumentBase__ValidateDataElements
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateDataElements(class CXMLSOMElementType &),CXMLSOMDocumentBase__ValidateDataElements);
#endif
#ifdef CXMLSOMDocumentBase__ValidateData
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocumentBase::ValidateData(void),CXMLSOMDocumentBase__ValidateData);
#endif
#ifdef CXMLSOMElementType__GetItemIdx
FUNCTION_AT_ADDRESS(int  CXMLSOMElementType::GetItemIdx(class CXStr),CXMLSOMElementType__GetItemIdx);
#endif
#ifdef CXMLSOMSchema__GetElementTypeIdx
FUNCTION_AT_ADDRESS(int  CXMLSOMSchema::GetElementTypeIdx(class CXStr),CXMLSOMSchema__GetElementTypeIdx);
#endif
#ifdef CXMLSOMSchema__IsDerivedFrom
FUNCTION_AT_ADDRESS(bool  CXMLSOMSchema::IsDerivedFrom(class CXStr,class CXStr),CXMLSOMSchema__IsDerivedFrom);
#endif
#ifdef CXMLSOMSchema__FindElementType
FUNCTION_AT_ADDRESS(bool  CXMLSOMSchema::FindElementType(class CXStr),CXMLSOMSchema__FindElementType);
#endif
#ifdef CXMLSOMSchema__FindSimpleType
FUNCTION_AT_ADDRESS(bool  CXMLSOMSchema::FindSimpleType(class CXStr),CXMLSOMSchema__FindSimpleType);
#endif
#ifdef CXMLSOMSchema__FindItem
FUNCTION_AT_ADDRESS(bool  CXMLSOMSchema::FindItem(class CXStr,class CXStr),CXMLSOMSchema__FindItem);
#endif
#ifdef CXMLSOMSchema__AddItem
FUNCTION_AT_ADDRESS(bool  CXMLSOMSchema::AddItem(class CXStr,class CXStr),CXMLSOMSchema__AddItem);
#endif
#ifdef CXMLSOMNode__FreeAllAllocs
FUNCTION_AT_ADDRESS(void __cdecl CXMLSOMNode::FreeAllAllocs(void),CXMLSOMNode__FreeAllAllocs);
#endif
#ifdef CXMLSOMNode__operator_new
FUNCTION_AT_ADDRESS(void * __cdecl CXMLSOMNode::operator new(unsigned int),CXMLSOMNode__operator_new);
#endif
#ifdef CMutexLock__dCMutexLock
FUNCTION_AT_ADDRESS( CMutexLock::~CMutexLock(void),CMutexLock__dCMutexLock);
#endif
#ifdef CXMLSOMNode__operator_delete
FUNCTION_AT_ADDRESS(void __cdecl CXMLSOMNode::operator delete(void *),CXMLSOMNode__operator_delete);
#endif
#ifdef CKeyCXStrValueInt32__CKeyCXStrValueInt32
FUNCTION_AT_ADDRESS( CKeyCXStrValueInt32::CKeyCXStrValueInt32(void),CKeyCXStrValueInt32__CKeyCXStrValueInt32);
#endif
#ifdef CXMLSOMCursor__CXMLSOMCursor
FUNCTION_AT_ADDRESS( CXMLSOMCursor::CXMLSOMCursor(void),CXMLSOMCursor__CXMLSOMCursor);
#endif
#ifdef CXMLSOMNodePtr__CXMLSOMNodePtr
FUNCTION_AT_ADDRESS( CXMLSOMNodePtr::CXMLSOMNodePtr(void),CXMLSOMNodePtr__CXMLSOMNodePtr);
#endif
#ifdef CXMLSOMAttribute__operator_equal
FUNCTION_AT_ADDRESS(class CXMLSOMAttribute &  CXMLSOMAttribute::operator=(class CXMLSOMAttribute const &),CXMLSOMAttribute__operator_equal);
#endif
#ifdef CXMLSOMCursor__operator_equal
FUNCTION_AT_ADDRESS(class CXMLSOMCursor &  CXMLSOMCursor::operator=(class CXMLSOMCursor const &),CXMLSOMCursor__operator_equal);
#endif
#ifdef CXMLSOMAttribute__CXMLSOMAttribute
FUNCTION_AT_ADDRESS( CXMLSOMAttribute::CXMLSOMAttribute(void),CXMLSOMAttribute__CXMLSOMAttribute);
#endif
#ifdef CXMLSOMSimpleType__CXMLSOMSimpleType
FUNCTION_AT_ADDRESS( CXMLSOMSimpleType::CXMLSOMSimpleType(void),CXMLSOMSimpleType__CXMLSOMSimpleType);
#endif
#ifdef CXMLSOMElementType__CXMLSOMElementType
FUNCTION_AT_ADDRESS( CXMLSOMElementType::CXMLSOMElementType(void),CXMLSOMElementType__CXMLSOMElementType);
#endif
#ifdef CXMLSOMAttributeType__operator_equal
FUNCTION_AT_ADDRESS(class CXMLSOMAttributeType &  CXMLSOMAttributeType::operator=(class CXMLSOMAttributeType const &),CXMLSOMAttributeType__operator_equal);
#endif
#ifdef CXMLSOMElement__operator_equal
FUNCTION_AT_ADDRESS(class CXMLSOMElement &  CXMLSOMElement::operator=(class CXMLSOMElement const &),CXMLSOMElement__operator_equal);
#endif
#ifdef CXMLSOMAttributeType__CXMLSOMAttributeType
FUNCTION_AT_ADDRESS( CXMLSOMAttributeType::CXMLSOMAttributeType(void),CXMLSOMAttributeType__CXMLSOMAttributeType);
#endif
#ifdef CXMLSOMElement__CXMLSOMElement
FUNCTION_AT_ADDRESS( CXMLSOMElement::CXMLSOMElement(void),CXMLSOMElement__CXMLSOMElement);
#endif
#ifdef KeyCombo__KeyCombo
FUNCTION_AT_ADDRESS( KeyCombo::KeyCombo(void),KeyCombo__KeyCombo);
#endif
#ifdef KeyCombo__KeyCombo1
FUNCTION_AT_ADDRESS( KeyCombo::KeyCombo(unsigned char,bool,bool,bool),KeyCombo__KeyCombo1);
#endif
#ifdef KeyCombo__KeyCombo2
FUNCTION_AT_ADDRESS( KeyCombo::KeyCombo(int),KeyCombo__KeyCombo2);
#endif
#ifdef KeyCombo__KeyCombo3
FUNCTION_AT_ADDRESS( KeyCombo::KeyCombo(unsigned int,unsigned int,bool,bool,bool),KeyCombo__KeyCombo3);
#endif
#ifdef KeyCombo__GetKey
FUNCTION_AT_ADDRESS(unsigned int  KeyCombo::GetKey(void)const ,KeyCombo__GetKey);
#endif
#ifdef KeyCombo__UsesCtrl
FUNCTION_AT_ADDRESS(bool  KeyCombo::UsesCtrl(void)const ,KeyCombo__UsesCtrl);
#endif
#ifdef KeyCombo__UsesShift
FUNCTION_AT_ADDRESS(bool  KeyCombo::UsesShift(void)const ,KeyCombo__UsesShift);
#endif
#ifdef KeyCombo__UsesAlt
FUNCTION_AT_ADDRESS(bool  KeyCombo::UsesAlt(void)const ,KeyCombo__UsesAlt);
#endif
#ifdef KeyCombo__GetTextDescription
FUNCTION_AT_ADDRESS(class CXStr  KeyCombo::GetTextDescription(void)const ,KeyCombo__GetTextDescription);
#endif
#ifdef KeyCombo__GetPrintableLetter
FUNCTION_AT_ADDRESS(bool  KeyCombo::GetPrintableLetter(unsigned short *)const ,KeyCombo__GetPrintableLetter);
#endif
#ifdef KeyCombo__operator_equal_equal
FUNCTION_AT_ADDRESS(int  KeyCombo::operator==(class KeyCombo const &)const ,KeyCombo__operator_equal_equal);
#endif
#ifdef KeyCombo__operator_equal
FUNCTION_AT_ADDRESS(class KeyCombo const &  KeyCombo::operator=(int),KeyCombo__operator_equal);
#endif
#ifdef KeyCombo__operator_int
//FUNCTION_AT_ADDRESS( KeyCombo::operator int(void)const ,KeyCombo__operator_int);
#endif
#ifdef KeyCombo__GetVirtualKeyFromScanCode
FUNCTION_AT_ADDRESS(bool  KeyCombo::GetVirtualKeyFromScanCode(unsigned char,int *)const ,KeyCombo__GetVirtualKeyFromScanCode);
#endif
#ifdef KeyCombo__GetPrintableLetterFromScanCode
FUNCTION_AT_ADDRESS(bool  KeyCombo::GetPrintableLetterFromScanCode(unsigned char,bool,bool,unsigned short *)const ,KeyCombo__GetPrintableLetterFromScanCode);
#endif
#ifdef KeyCombo__GetScanCodeFromVirtualKey
FUNCTION_AT_ADDRESS(bool  KeyCombo::GetScanCodeFromVirtualKey(unsigned int,unsigned int,unsigned char *)const ,KeyCombo__GetScanCodeFromVirtualKey);
#endif
#ifdef KeyCombo__GetPrintableLetterFromVirtualKey
FUNCTION_AT_ADDRESS(bool  KeyCombo::GetPrintableLetterFromVirtualKey(unsigned int,unsigned int,bool,bool,unsigned short *)const ,KeyCombo__GetPrintableLetterFromVirtualKey);
#endif
#ifdef CButtonWnd__CButtonWnd
FUNCTION_AT_ADDRESS( CButtonWnd::CButtonWnd(class CXWnd *,unsigned __int32,class CXRect,class CXPoint,class CXSize,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *),CButtonWnd__CButtonWnd);
#endif
#ifdef CXWnd__IsEnabled
FUNCTION_AT_ADDRESS(bool  CXWnd::IsEnabled(void)const ,CXWnd__IsEnabled);
#endif
#ifdef CButtonWnd__SetCheck
FUNCTION_AT_ADDRESS(void  CButtonWnd::SetCheck(bool),CButtonWnd__SetCheck);
#endif
#ifdef CComboWnd__CComboWnd
//FUNCTION_AT_ADDRESS( CComboWnd::CComboWnd(class CXWnd *,unsigned __int32,class CXRect,int,class CButtonDrawTemplate,class CListWnd *),CComboWnd__CComboWnd);
#endif
#ifdef CXWnd__GetWidth
FUNCTION_AT_ADDRESS(int  CXWnd::GetWidth(void)const ,CXWnd__GetWidth);
#endif
#ifdef CComboWnd__GetListRect
FUNCTION_AT_ADDRESS(class CXRect  CComboWnd::GetListRect(void)const ,CComboWnd__GetListRect);
#endif
#ifdef CComboWnd__SetColors
FUNCTION_AT_ADDRESS(void  CComboWnd::SetColors(unsigned long,unsigned long,unsigned long),CComboWnd__SetColors);
#endif
#ifdef CComboWnd__InsertChoice
FUNCTION_AT_ADDRESS(void  CComboWnd::InsertChoice(class CXStr *, unsigned long),CComboWnd__InsertChoice);
#endif
#ifdef CComboWnd__SetChoice
FUNCTION_AT_ADDRESS(void  CComboWnd::SetChoice(int),CComboWnd__SetChoice);
#endif
#ifdef CComboWnd__GetItemCount
FUNCTION_AT_ADDRESS(int  CComboWnd::GetItemCount(void),CComboWnd__GetItemCount);
#endif
#ifdef CComboWnd__GetCurChoice
FUNCTION_AT_ADDRESS(int  CComboWnd::GetCurChoice(void)const ,CComboWnd__GetCurChoice);
#endif
#ifdef CComboWnd__GetCurChoiceText
FUNCTION_AT_ADDRESS(class CXStr  CComboWnd::GetCurChoiceText(void)const ,CComboWnd__GetCurChoiceText);
#endif
#ifdef CComboWnd__DeleteAll
FUNCTION_AT_ADDRESS(void  CComboWnd::DeleteAll(void),CComboWnd__DeleteAll);
#endif
#ifdef CComboWnd__GetButtonRect
FUNCTION_AT_ADDRESS(class CXRect  CComboWnd::GetButtonRect(void)const ,CComboWnd__GetButtonRect);
#endif
#ifdef CComboWnd__GetTextRect
FUNCTION_AT_ADDRESS(class CXRect  CComboWnd::GetTextRect(void)const ,CComboWnd__GetTextRect);
#endif
#ifdef CXWndManager__CXWndManager
FUNCTION_AT_ADDRESS( CXWndManager::CXWndManager(class CSidlManager *),CXWndManager__CXWndManager);
#endif
#ifdef CXWndManager__DestroyAllWindows
FUNCTION_AT_ADDRESS(void  CXWndManager::DestroyAllWindows(void),CXWndManager__DestroyAllWindows);
#endif
#ifdef CXWndManager__DrawWindows
FUNCTION_AT_ADDRESS(int  CXWndManager::DrawWindows(void)const ,CXWndManager__DrawWindows);
#endif
#ifdef CXWndManager__DrawCursor
FUNCTION_AT_ADDRESS(int  CXWndManager::DrawCursor(void)const ,CXWndManager__DrawCursor);
#endif
#ifdef CXWndManager__AddWnd
FUNCTION_AT_ADDRESS(int  CXWndManager::AddWnd(class CXWnd *),CXWndManager__AddWnd);
#endif
#ifdef CXWndManager__RemoveWnd
FUNCTION_AT_ADDRESS(int  CXWndManager::RemoveWnd(class CXWnd *),CXWndManager__RemoveWnd);
#endif
#ifdef CXWndManager__CheckInvalidateLastFoundWnd
FUNCTION_AT_ADDRESS(void  CXWndManager::CheckInvalidateLastFoundWnd(void),CXWndManager__CheckInvalidateLastFoundWnd);
#endif
#ifdef CXWndManager__GetKeyboardFlags
FUNCTION_AT_ADDRESS(unsigned __int32  CXWndManager::GetKeyboardFlags(void)const ,CXWndManager__GetKeyboardFlags);
#endif
#ifdef CXWndManager__FlushKeyboardFlags
FUNCTION_AT_ADDRESS(void  CXWndManager::FlushKeyboardFlags(void),CXWndManager__FlushKeyboardFlags);
#endif
#ifdef CXWndManager__UpdateChildAndSiblingInfo
FUNCTION_AT_ADDRESS(void  CXWndManager::UpdateChildAndSiblingInfo(void),CXWndManager__UpdateChildAndSiblingInfo);
#endif
#ifdef CXWndManager__HandleKeyboardMsg
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleKeyboardMsg(unsigned __int32,bool),CXWndManager__HandleKeyboardMsg);
#endif
#ifdef CXWndManager__OkayToSendMouseMessage
FUNCTION_AT_ADDRESS(bool  CXWndManager::OkayToSendMouseMessage(class CXWnd *)const,CXWndManager__OkayToSendMouseMessage);
#endif
#ifdef CXWndManager__HandleMouseMove
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleMouseMove(class CXPoint),CXWndManager__HandleMouseMove);
#endif
#ifdef CXWndManager__HandleWheelMove
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleWheelMove(int),CXWndManager__HandleWheelMove);
#endif
#ifdef CXWndManager__HandleLButtonDown
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleLButtonDown(class CXPoint),CXWndManager__HandleLButtonDown);
#endif
#ifdef CXWndManager__IsWindowPieceDown
FUNCTION_AT_ADDRESS(bool  CXWndManager::IsWindowPieceDown(class CXWnd const *,int)const ,CXWndManager__IsWindowPieceDown);
#endif
#ifdef CXWndManager__OnWindowCloseBox
FUNCTION_AT_ADDRESS(int  CXWndManager::OnWindowCloseBox(class CXWnd *),CXWndManager__OnWindowCloseBox);
#endif
#ifdef CXWndManager__OnWindowMinimizeBox
FUNCTION_AT_ADDRESS(int  CXWndManager::OnWindowMinimizeBox(class CXWnd *),CXWndManager__OnWindowMinimizeBox);
#endif
#ifdef CXWndManager__OnWindowTileBox
FUNCTION_AT_ADDRESS(int  CXWndManager::OnWindowTileBox(class CXWnd *),CXWndManager__OnWindowTileBox);
#endif
#ifdef CXWndManager__HandleLButtonHeld
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleLButtonHeld(class CXPoint),CXWndManager__HandleLButtonHeld);
#endif
#ifdef CXWndManager__HandleLButtonUpAfterHeld
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleLButtonUpAfterHeld(class CXPoint),CXWndManager__HandleLButtonUpAfterHeld);
#endif
#ifdef CXWndManager__HandleRButtonHeld
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleRButtonHeld(class CXPoint),CXWndManager__HandleRButtonHeld);
#endif
#ifdef CXWndManager__HandleRButtonUpAfterHeld
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleRButtonUpAfterHeld(class CXPoint),CXWndManager__HandleRButtonUpAfterHeld);
#endif
#ifdef CXWndManager__HandleLButtonUp
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleLButtonUp(class CXPoint),CXWndManager__HandleLButtonUp);
#endif
#ifdef CXWndManager__HandleRButtonDown
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleRButtonDown(class CXPoint),CXWndManager__HandleRButtonDown);
#endif
#ifdef CXWndManager__HandleRButtonUp
FUNCTION_AT_ADDRESS(int  CXWndManager::HandleRButtonUp(class CXPoint),CXWndManager__HandleRButtonUp);
#endif
#ifdef CXWndManager__FindWnd
FUNCTION_AT_ADDRESS(class CXWnd *  CXWndManager::FindWnd(class CXPoint,int *)const,CXWndManager__FindWnd);
#endif
#ifdef CXWndManager__GetCursorToDisplay
FUNCTION_AT_ADDRESS(class CTextureAnimation const *  CXWndManager::GetCursorToDisplay(void)const ,CXWndManager__GetCursorToDisplay);
#endif
#ifdef CXWndManager__SetFocusWnd
FUNCTION_AT_ADDRESS(class CXWnd *  CXWndManager::SetFocusWnd(class CXWnd *),CXWndManager__SetFocusWnd);
#endif
#ifdef CXWndManager__GetFocusWnd
FUNCTION_AT_ADDRESS(class CXWnd *  CXWndManager::GetFocusWnd(void)const ,CXWndManager__GetFocusWnd);
#endif
#ifdef CXWndManager__ProcessFrame
FUNCTION_AT_ADDRESS(int  CXWndManager::ProcessFrame(void),CXWndManager__ProcessFrame);
#endif
#ifdef CXWndManager__OnWindowShown
FUNCTION_AT_ADDRESS(void  CXWndManager::OnWindowShown(class CXWnd *,bool),CXWndManager__OnWindowShown);
#endif
#ifdef CXWndManager__BringWndToTop
FUNCTION_AT_ADDRESS(void  CXWndManager::BringWndToTop(class CXWnd *,bool),CXWndManager__BringWndToTop);
#endif
#ifdef CXWndManager__NotifyAllWindows
FUNCTION_AT_ADDRESS(int  CXWndManager::NotifyAllWindows(class CXWnd *,unsigned __int32,void *),CXWndManager__NotifyAllWindows);
#endif
#ifdef CXWndManager__CleanupWindows
FUNCTION_AT_ADDRESS(void  CXWndManager::CleanupWindows(void),CXWndManager__CleanupWindows);
#endif
#ifdef CXWndManager__GetFirstChildWnd
FUNCTION_AT_ADDRESS(class CXWnd *  CXWndManager::GetFirstChildWnd(class CXWnd const *)const ,CXWndManager__GetFirstChildWnd);
#endif
#ifdef CXWndManager__GetNextSib
FUNCTION_AT_ADDRESS(class CXWnd *  CXWndManager::GetNextSib(class CXWnd const *)const ,CXWndManager__GetNextSib);
#endif
#ifdef CXWndManager__ActivateWnd
FUNCTION_AT_ADDRESS(int  CXWndManager::ActivateWnd(class CXWnd *),CXWndManager__ActivateWnd);
#endif
#ifdef CXWndManager__IsWindowActive
FUNCTION_AT_ADDRESS(bool  CXWndManager::IsWindowActive(class CXWnd const *)const ,CXWndManager__IsWindowActive);
#endif
#ifdef CXWndManager__IsWindowMovingOrSizing
FUNCTION_AT_ADDRESS(bool  CXWndManager::IsWindowMovingOrSizing(class CXWnd *)const ,CXWndManager__IsWindowMovingOrSizing);
#endif
#ifdef CXWndManager__AddFont
FUNCTION_AT_ADDRESS(int  CXWndManager::AddFont(class CTextureFont *),CXWndManager__AddFont);
#endif
#ifdef CXWndManager__GetFont1
FUNCTION_AT_ADDRESS(class CTextureFont *  CXWndManager::GetFont(class CXStr),CXWndManager__GetFont1);
#endif
#ifdef CXWndManager__SetSystemFont
FUNCTION_AT_ADDRESS(void  CXWndManager::SetSystemFont(class CTextureFont *),CXWndManager__SetSystemFont);
#endif
#ifdef CXWndManager__SetGlobalFadeDuration
FUNCTION_AT_ADDRESS(void  CXWndManager::SetGlobalFadeDuration(unsigned __int32),CXWndManager__SetGlobalFadeDuration);
#endif
#ifdef CXWndManager__GetGlobalFadeDuration
FUNCTION_AT_ADDRESS(unsigned __int32  CXWndManager::GetGlobalFadeDuration(void)const ,CXWndManager__GetGlobalFadeDuration);
#endif
#ifdef CXWndManager__SetGlobalFadeDelay
FUNCTION_AT_ADDRESS(void  CXWndManager::SetGlobalFadeDelay(unsigned long),CXWndManager__SetGlobalFadeDelay);
#endif
#ifdef CXWndManager__GetGlobalFadeDelay
FUNCTION_AT_ADDRESS(unsigned long  CXWndManager::GetGlobalFadeDelay(void)const ,CXWndManager__GetGlobalFadeDelay);
#endif
#ifdef CXWndManager__SetGlobalAlpha
FUNCTION_AT_ADDRESS(void  CXWndManager::SetGlobalAlpha(unsigned char),CXWndManager__SetGlobalAlpha);
#endif
#ifdef CXWndManager__GetGlobalAlpha
FUNCTION_AT_ADDRESS(unsigned char  CXWndManager::GetGlobalAlpha(void)const ,CXWndManager__GetGlobalAlpha);
#endif
#ifdef CXWndManager__SetGlobalFadeToAlpha
FUNCTION_AT_ADDRESS(void  CXWndManager::SetGlobalFadeToAlpha(unsigned char),CXWndManager__SetGlobalFadeToAlpha);
#endif
#ifdef CXWndManager__GetGlobalFadeToAlpha
FUNCTION_AT_ADDRESS(unsigned char  CXWndManager::GetGlobalFadeToAlpha(void)const ,CXWndManager__GetGlobalFadeToAlpha);
#endif
#ifdef CXWndManager__IsAllValid
FUNCTION_AT_ADDRESS(bool  CXWndManager::IsAllValid(void),CXWndManager__IsAllValid);
#endif
#ifdef CEditWnd__CEditWnd
//FUNCTION_AT_ADDRESS( CEditWnd::CEditWnd(class CXWnd *,unsigned __int32,class CXRect,unsigned __int32),CEditWnd__CEditWnd);
#endif
#ifdef CEditWnd__GetLineForPrintableChar
FUNCTION_AT_ADDRESS(int  CEditWnd::GetLineForPrintableChar(int)const ,CEditWnd__GetLineForPrintableChar);
#endif
#ifdef CEditWnd__GetLineLength
FUNCTION_AT_ADDRESS(int  CEditWnd::GetLineLength(int)const ,CEditWnd__GetLineLength);
#endif
#ifdef CEditWnd__FillIndexArray
FUNCTION_AT_ADDRESS(void  CEditWnd::FillIndexArray(class CXStr)const ,CEditWnd__FillIndexArray);
#endif
#ifdef CEditWnd__SelectableCharFromPoint
FUNCTION_AT_ADDRESS(int  CEditWnd::SelectableCharFromPoint(class CXPoint)const ,CEditWnd__SelectableCharFromPoint);
#endif
#ifdef CEditWnd__AddItemTag
FUNCTION_AT_ADDRESS(void  CEditWnd::AddItemTag(int,char *,int),CEditWnd__AddItemTag);
#endif
#ifdef CEditWnd__ProcessText
FUNCTION_AT_ADDRESS(void  CEditWnd::ProcessText(void),CEditWnd__ProcessText);
#endif
#ifdef CEditWnd__GetCharIndexPt
FUNCTION_AT_ADDRESS(class CXPoint  CEditWnd::GetCharIndexPt(int)const ,CEditWnd__GetCharIndexPt);
#endif
#ifdef CEditWnd__GetSelStartPt
FUNCTION_AT_ADDRESS(class CXPoint  CEditWnd::GetSelStartPt(void)const ,CEditWnd__GetSelStartPt);
#endif
#ifdef CEditWnd__GetSelEndPt
FUNCTION_AT_ADDRESS(class CXPoint  CEditWnd::GetSelEndPt(void)const ,CEditWnd__GetSelEndPt);
#endif
#ifdef CEditWnd__FilterInputStr
FUNCTION_AT_ADDRESS(void  CEditWnd::FilterInputStr(class CXStr &),CEditWnd__FilterInputStr);
#endif
#ifdef CEditWnd__ReplaceSelection
FUNCTION_AT_ADDRESS(void  CEditWnd::ReplaceSelection(class CXStr,bool),CEditWnd__ReplaceSelection);
#endif
#ifdef CEditWnd__ReplaceSelection1
FUNCTION_AT_ADDRESS(void  CEditWnd::ReplaceSelection(char,bool),CEditWnd__ReplaceSelection1);
#endif
#ifdef CEditWnd__CalculateScrollRange
FUNCTION_AT_ADDRESS(void  CEditWnd::CalculateScrollRange(void),CEditWnd__CalculateScrollRange);
#endif
#ifdef CEditWnd__EnsureCaretVisible
FUNCTION_AT_ADDRESS(void  CEditWnd::EnsureCaretVisible(void),CEditWnd__EnsureCaretVisible);
#endif
#ifdef CEditWnd__SetEditable
FUNCTION_AT_ADDRESS(void  CEditWnd::SetEditable(bool),CEditWnd__SetEditable);
#endif
#ifdef CEditWnd__GetSTMLSafeText
FUNCTION_AT_ADDRESS(class CXStr  CEditWnd::GetSTMLSafeText(void),CEditWnd__GetSTMLSafeText);
#endif
#ifdef CEditWnd__ConvertIndexPrintableToTagged
FUNCTION_AT_ADDRESS(int  CEditWnd::ConvertIndexPrintableToTagged(int),CEditWnd__ConvertIndexPrintableToTagged);
#endif
#ifdef CEditWnd__ConvertIndexTaggedToPrintable
FUNCTION_AT_ADDRESS(int  CEditWnd::ConvertIndexTaggedToPrintable(int),CEditWnd__ConvertIndexTaggedToPrintable);
#endif
#ifdef CTextureFont__GetWidth
FUNCTION_AT_ADDRESS(int  CTextureFont::GetWidth(unsigned short)const ,CTextureFont__GetWidth);
#endif
#ifdef CTextureFont__GetKerning
FUNCTION_AT_ADDRESS(int  CTextureFont::GetKerning(unsigned short,unsigned short)const ,CTextureFont__GetKerning);
#endif
#ifdef CTextureFont__GetTextExtent
FUNCTION_AT_ADDRESS(int  CTextureFont::GetTextExtent(class CXStr)const ,CTextureFont__GetTextExtent);
#endif
#ifdef CTextureFont__GetHeight
FUNCTION_AT_ADDRESS(int  CTextureFont::GetHeight(void)const ,CTextureFont__GetHeight);
#endif
#ifdef CTextureFont__GetName
FUNCTION_AT_ADDRESS(class CXStr  CTextureFont::GetName(void)const ,CTextureFont__GetName);
#endif
#ifdef CTextureFont__DrawWrappedText
FUNCTION_AT_ADDRESS(int  CTextureFont::DrawWrappedText(class CXStr *,int,int,int,class CXRect *,unsigned long,unsigned short,int)const ,CTextureFont__DrawWrappedText);
#endif
#ifdef CTextureFont__DrawWrappedText1
FUNCTION_AT_ADDRESS(int  CTextureFont::DrawWrappedText(class CXStr,class CXRect,class CXRect,unsigned long,unsigned short,int)const ,CTextureFont__DrawWrappedText1);
#endif
#ifdef CTextureAnimation__CTextureAnimation
FUNCTION_AT_ADDRESS( CTextureAnimation::CTextureAnimation(void),CTextureAnimation__CTextureAnimation);
#endif
#ifdef CTextureAnimation__CTextureAnimation1
FUNCTION_AT_ADDRESS( CTextureAnimation::CTextureAnimation(class CXStr),CTextureAnimation__CTextureAnimation1);
#endif
#ifdef CUITexturePiece__CUITexturePiece1
FUNCTION_AT_ADDRESS( CUITexturePiece::CUITexturePiece(class CUITexturePiece const &),CUITexturePiece__CUITexturePiece1);
#endif
#ifdef CTextureAnimation__AddFrame
FUNCTION_AT_ADDRESS(int  CTextureAnimation::AddFrame(class CUITextureInfo const *,class CXRect,unsigned __int32,class CXPoint),CTextureAnimation__AddFrame);
#endif
#ifdef CUITexturePiece__CUITexturePiece2
//FUNCTION_AT_ADDRESS( CUITexturePiece::CUITexturePiece(class CUITextureInfo,class CXRect),CUITexturePiece__CUITexturePiece2);
#endif
#ifdef CUITextureInfo__CUITextureInfo2
FUNCTION_AT_ADDRESS( CUITextureInfo::CUITextureInfo(class CUITextureInfo const &),CUITextureInfo__CUITextureInfo2);
#endif
#ifdef CTextureAnimation__AddFrame1
//FUNCTION_AT_ADDRESS(int  CTextureAnimation::AddFrame(class CUITexturePiece,unsigned __int32,class CXPoint),CTextureAnimation__AddFrame1);
#endif
#ifdef STextureAnimationFrame__STextureAnimationFrame1
FUNCTION_AT_ADDRESS( STextureAnimationFrame::STextureAnimationFrame(class CUITexturePiece,unsigned __int32,class CXPoint),STextureAnimationFrame__STextureAnimationFrame1);
#endif
#ifdef CUITextureInfo__CUITextureInfo3
FUNCTION_AT_ADDRESS( CUITextureInfo::CUITextureInfo(unsigned __int32,int),CUITextureInfo__CUITextureInfo3);
#endif
#ifdef CTextureAnimation__AddBlankFrame
FUNCTION_AT_ADDRESS(int  CTextureAnimation::AddBlankFrame(unsigned __int32,class CXPoint),CTextureAnimation__AddBlankFrame);
#endif
#ifdef CTextureAnimation__SetCurFrame
FUNCTION_AT_ADDRESS(void  CTextureAnimation::SetCurFrame(int),CTextureAnimation__SetCurFrame);
#endif
#ifdef CTextureAnimation__GetCurFrame
FUNCTION_AT_ADDRESS(int  CTextureAnimation::GetCurFrame(void)const ,CTextureAnimation__GetCurFrame);
#endif
#ifdef CTextureAnimation__Draw
FUNCTION_AT_ADDRESS(int  CTextureAnimation::Draw(class CXRect,class CXRect,unsigned long,unsigned long)const ,CTextureAnimation__Draw);
#endif
#ifdef CTextureAnimation__Draw1
FUNCTION_AT_ADDRESS(int  CTextureAnimation::Draw(class CXPoint,class CXRect,unsigned long,unsigned long)const ,CTextureAnimation__Draw1);
#endif
#ifdef CTextureAnimation__GetHotspot
FUNCTION_AT_ADDRESS(class CXPoint  CTextureAnimation::GetHotspot(void)const ,CTextureAnimation__GetHotspot);
#endif
#ifdef CTextureAnimation__SetCurCell
FUNCTION_AT_ADDRESS(void  CTextureAnimation::SetCurCell(int),CTextureAnimation__SetCurCell);
#endif
#ifdef CTextureAnimation__Preload
FUNCTION_AT_ADDRESS(int  CTextureAnimation::Preload(void),CTextureAnimation__Preload);
#endif
#ifdef CUITextureInfo__operator_equal
FUNCTION_AT_ADDRESS(class CUITextureInfo &  CUITextureInfo::operator=(class CUITextureInfo const &),CUITextureInfo__operator_equal);
#endif
#ifdef CSidlManager__CSidlManager
FUNCTION_AT_ADDRESS( CSidlManager::CSidlManager(void),CSidlManager__CSidlManager);
#endif
#ifdef CSidlManager__GetPointFromParamPoint
FUNCTION_AT_ADDRESS(class CXPoint __cdecl CSidlManager::GetPointFromParamPoint(class CParamPoint const &),CSidlManager__GetPointFromParamPoint);
#endif
#ifdef CSidlManager__GetSizeFromParamSize
FUNCTION_AT_ADDRESS(class CXSize __cdecl CSidlManager::GetSizeFromParamSize(class CParamSize const &),CSidlManager__GetSizeFromParamSize);
#endif
#ifdef CSidlManager__GetRectFromParamPointSize
FUNCTION_AT_ADDRESS(class CXRect __cdecl CSidlManager::GetRectFromParamPointSize(class CParamPoint const &,class CParamSize const &),CSidlManager__GetRectFromParamPointSize);
#endif
#ifdef CSidlManager__GetD3DCOLOR
FUNCTION_AT_ADDRESS(unsigned long __cdecl CSidlManager::GetD3DCOLOR(class CParamRGB const &),CSidlManager__GetD3DCOLOR);
#endif
#ifdef CSidlManager__GetButtonDrawTemplateFromParamButtonDrawTemplate
FUNCTION_AT_ADDRESS(class CButtonDrawTemplate  CSidlManager::GetButtonDrawTemplateFromParamButtonDrawTemplate(class CParamButtonDrawTemplate const &)const ,CSidlManager__GetButtonDrawTemplateFromParamButtonDrawTemplate);
#endif
#ifdef CSidlManager__GetGaugeDrawTemplateFromParamGaugeDrawTemplate
FUNCTION_AT_ADDRESS(class CGaugeDrawTemplate  CSidlManager::GetGaugeDrawTemplateFromParamGaugeDrawTemplate(class CParamGaugeDrawTemplate const &)const ,CSidlManager__GetGaugeDrawTemplateFromParamGaugeDrawTemplate);
#endif
#ifdef CSidlManager__GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate
FUNCTION_AT_ADDRESS(class CSpellGemDrawTemplate  CSidlManager::GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate(class CParamSpellGemDrawTemplate const &)const ,CSidlManager__GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate);
#endif
#ifdef CSidlManager__DeleteContents
FUNCTION_AT_ADDRESS(void  CSidlManager::DeleteContents(void),CSidlManager__DeleteContents);
#endif
#ifdef CParamScrollbarDrawTemplate__operator_equal
FUNCTION_AT_ADDRESS(class CParamScrollbarDrawTemplate &  CParamScrollbarDrawTemplate::operator=(class CParamScrollbarDrawTemplate const &),CParamScrollbarDrawTemplate__operator_equal);
#endif
#ifdef CParamFrameTemplate__operator_equal
FUNCTION_AT_ADDRESS(class CParamFrameTemplate &  CParamFrameTemplate::operator=(class CParamFrameTemplate const &),CParamFrameTemplate__operator_equal);
#endif
#ifdef CParamButtonDrawTemplate__operator_equal
FUNCTION_AT_ADDRESS(class CParamButtonDrawTemplate &  CParamButtonDrawTemplate::operator=(class CParamButtonDrawTemplate const &),CParamButtonDrawTemplate__operator_equal);
#endif
#ifdef CParamClass__operator_equal
FUNCTION_AT_ADDRESS(class CParamClass &  CParamClass::operator=(class CParamClass const &),CParamClass__operator_equal);
#endif
#ifdef CParamRGB__operator_equal
FUNCTION_AT_ADDRESS(class CParamRGB &  CParamRGB::operator=(class CParamRGB const &),CParamRGB__operator_equal);
#endif
#ifdef CParam__operator_equal
FUNCTION_AT_ADDRESS(class CParam &  CParam::operator=(class CParam const &),CParam__operator_equal);
#endif
#ifdef CXMLData__operator_equal
FUNCTION_AT_ADDRESS(class CXMLData &  CXMLData::operator=(class CXMLData const &),CXMLData__operator_equal);
#endif
#ifdef CTAFrameDraw__GetName
FUNCTION_AT_ADDRESS(class CXStr  CTAFrameDraw::GetName(void)const ,CTAFrameDraw__GetName);
#endif
#ifdef CScreenPieceTemplate__GetName
FUNCTION_AT_ADDRESS(class CXStr  CScreenPieceTemplate::GetName(void)const ,CScreenPieceTemplate__GetName);
#endif
#ifdef CSidlManager__LoadSidl
FUNCTION_AT_ADDRESS(void  CSidlManager::LoadSidl(class CXStr,class CXStr,class CXStr),CSidlManager__LoadSidl);
#endif
#ifdef CUITextureInfo__CUITextureInfo4
FUNCTION_AT_ADDRESS( CUITextureInfo::CUITextureInfo(class CXStr,class CXSize),CUITextureInfo__CUITextureInfo4);
#endif
#ifdef CSidlManager__CreateTextureAnimationFromSidlAnimation
FUNCTION_AT_ADDRESS(class CTextureAnimation  CSidlManager::CreateTextureAnimationFromSidlAnimation(class CParamUi2DAnimation const *)const ,CSidlManager__CreateTextureAnimationFromSidlAnimation);
#endif
#ifdef CSidlManager__CreateTAFrameDrawFromSidlFrame
FUNCTION_AT_ADDRESS(class CTAFrameDraw  CSidlManager::CreateTAFrameDrawFromSidlFrame(class CParamFrameTemplate const *)const ,CSidlManager__CreateTAFrameDrawFromSidlFrame);
#endif
#ifdef CSidlManager__GetScrollbarTemplateFromParamScrollbarTemplate
FUNCTION_AT_ADDRESS(class CScrollbarTemplate  CSidlManager::GetScrollbarTemplateFromParamScrollbarTemplate(class CParamScrollbarDrawTemplate const &)const ,CSidlManager__GetScrollbarTemplateFromParamScrollbarTemplate);
#endif
#ifdef CScrollbarTemplate__CScrollbarTemplate
FUNCTION_AT_ADDRESS( CScrollbarTemplate::CScrollbarTemplate(class CScrollbarTemplate const &),CScrollbarTemplate__CScrollbarTemplate);
#endif
#ifdef CSidlManager__GetSliderDrawTemplateFromParamSliderDrawTemplate
FUNCTION_AT_ADDRESS(class CSliderDrawTemplate  CSidlManager::GetSliderDrawTemplateFromParamSliderDrawTemplate(class CParamSliderDrawTemplate const &)const ,CSidlManager__GetSliderDrawTemplateFromParamSliderDrawTemplate);
#endif
#ifdef CButtonDrawTemplate__CButtonDrawTemplate1
FUNCTION_AT_ADDRESS( CButtonDrawTemplate::CButtonDrawTemplate(class CButtonDrawTemplate const &),CButtonDrawTemplate__CButtonDrawTemplate1);
#endif
#ifdef CSliderDrawTemplate__dCSliderDrawTemplate
FUNCTION_AT_ADDRESS( CSliderDrawTemplate::~CSliderDrawTemplate(void),CSliderDrawTemplate__dCSliderDrawTemplate);
#endif
#ifdef CSidlManager__CreateDrawTemplateFromParamWindowDrawTemplate
FUNCTION_AT_ADDRESS(class CXWndDrawTemplate  CSidlManager::CreateDrawTemplateFromParamWindowDrawTemplate(class CParamWindowDrawTemplate const *)const ,CSidlManager__CreateDrawTemplateFromParamWindowDrawTemplate);
#endif
#ifdef CScrollbarTemplate__CScrollbarTemplate1
FUNCTION_AT_ADDRESS( CScrollbarTemplate::CScrollbarTemplate(void),CScrollbarTemplate__CScrollbarTemplate1);
#endif
#ifdef CXWndDrawTemplate__CXWndDrawTemplate1
FUNCTION_AT_ADDRESS( CXWndDrawTemplate::CXWndDrawTemplate(class CXWndDrawTemplate const &),CXWndDrawTemplate__CXWndDrawTemplate1);
#endif
#ifdef CTAFrameDraw__CTAFrameDraw
FUNCTION_AT_ADDRESS( CTAFrameDraw::CTAFrameDraw(class CTAFrameDraw const &),CTAFrameDraw__CTAFrameDraw);
#endif
#ifdef CSidlManager__CreateScreenPieceTemplateFromParamScreenPiece
FUNCTION_AT_ADDRESS(class CScreenPieceTemplate *  CSidlManager::CreateScreenPieceTemplateFromParamScreenPiece(class CParamScreenPiece const *)const ,CSidlManager__CreateScreenPieceTemplateFromParamScreenPiece);
#endif
#ifdef CSidlManager__GetParsingErrorMsg
FUNCTION_AT_ADDRESS(class CXStr  CSidlManager::GetParsingErrorMsg(void)const ,CSidlManager__GetParsingErrorMsg);
#endif
#ifdef CSidlManager__GetScreenPieceEnum
//FUNCTION_AT_ADDRESS(enum EStaticScreenPieceClasses  CSidlManager::GetScreenPieceEnum(class CScreenPieceTemplate *)const ,CSidlManager__GetScreenPieceEnum);
#endif
#ifdef CSidlManager__FindAnimation
FUNCTION_AT_ADDRESS(class CTextureAnimation *  CSidlManager::FindAnimation(unsigned __int32)const ,CSidlManager__FindAnimation);
#endif
#ifdef CSidlManager__FindAnimation1
FUNCTION_AT_ADDRESS(class CTextureAnimation *  CSidlManager::FindAnimation(class CXStr)const ,CSidlManager__FindAnimation1);
#endif
#ifdef CSidlManager__FindFrameDraw
FUNCTION_AT_ADDRESS(class CTAFrameDraw *  CSidlManager::FindFrameDraw(unsigned __int32)const ,CSidlManager__FindFrameDraw);
#endif
#ifdef CSidlManager__FindDrawTemplate
FUNCTION_AT_ADDRESS(class CXWndDrawTemplate *  CSidlManager::FindDrawTemplate(unsigned __int32)const ,CSidlManager__FindDrawTemplate);
#endif
#ifdef CSidlManager__FindDrawTemplate1
FUNCTION_AT_ADDRESS(class CXWndDrawTemplate *  CSidlManager::FindDrawTemplate(class CXStr)const ,CSidlManager__FindDrawTemplate1);
#endif
#ifdef CSidlManager__FindScreenPieceTemplate
FUNCTION_AT_ADDRESS(class CScreenPieceTemplate *  CSidlManager::FindScreenPieceTemplate(unsigned __int32)const ,CSidlManager__FindScreenPieceTemplate);
#endif
#ifdef CSidlManager__FindScreenPieceTemplate1
FUNCTION_AT_ADDRESS(class CScreenPieceTemplate *  CSidlManager::FindScreenPieceTemplate(class CXStr *)const ,CSidlManager__FindScreenPieceTemplate1);
#endif
#ifdef CSidlManager__AddAnimationInOrder
FUNCTION_AT_ADDRESS(void  CSidlManager::AddAnimationInOrder(class CTextureAnimation *),CSidlManager__AddAnimationInOrder);
#endif
#ifdef CSidlManager__AddDrawTemplateInOrder
FUNCTION_AT_ADDRESS(void  CSidlManager::AddDrawTemplateInOrder(class CXWndDrawTemplate *),CSidlManager__AddDrawTemplateInOrder);
#endif
#ifdef CSidlManager__AddTAFrameDrawInOrder
FUNCTION_AT_ADDRESS(void  CSidlManager::AddTAFrameDrawInOrder(class CTAFrameDraw *),CSidlManager__AddTAFrameDrawInOrder);
#endif
#ifdef CSidlManager__AddScreenPieceTemplateInOrder
FUNCTION_AT_ADDRESS(void  CSidlManager::AddScreenPieceTemplateInOrder(class CScreenPieceTemplate *),CSidlManager__AddScreenPieceTemplateInOrder);
#endif
#ifdef CSidlManager__FindTexture
FUNCTION_AT_ADDRESS(class CUITextureInfo *  CSidlManager::FindTexture(class CXStr)const ,CSidlManager__FindTexture);
#endif
#ifdef CSidlManager__FindTexture1
FUNCTION_AT_ADDRESS(class CUITextureInfo *  CSidlManager::FindTexture(unsigned __int32)const ,CSidlManager__FindTexture1);
#endif
#ifdef CSidlManager__FindButtonDrawTemplate
FUNCTION_AT_ADDRESS(class CButtonDrawTemplate *  CSidlManager::FindButtonDrawTemplate(unsigned __int32)const ,CSidlManager__FindButtonDrawTemplate);
#endif
#ifdef CSidlManager__FindSliderDrawTemplate
FUNCTION_AT_ADDRESS(class CSliderDrawTemplate *  CSidlManager::FindSliderDrawTemplate(class CXStr)const ,CSidlManager__FindSliderDrawTemplate);
#endif
#ifdef CSidlManager__FindSliderDrawTemplate1
FUNCTION_AT_ADDRESS(class CSliderDrawTemplate *  CSidlManager::FindSliderDrawTemplate(unsigned __int32)const ,CSidlManager__FindSliderDrawTemplate1);
#endif
#ifdef CSidlManager__CreateXWndFromTemplate
FUNCTION_AT_ADDRESS(class CXWnd *  CSidlManager::CreateXWndFromTemplate(class CXWnd *,class CControlTemplate *),CSidlManager__CreateXWndFromTemplate);
#endif
#ifdef CTAFrameDraw__GetAnimation
FUNCTION_AT_ADDRESS(class CTextureAnimation *  CTAFrameDraw::GetAnimation(int)const ,CTAFrameDraw__GetAnimation);
#endif
#ifdef CXWnd__SetXMLTooltip
FUNCTION_AT_ADDRESS(void  CXWnd::SetXMLTooltip(class CXStr),CXWnd__SetXMLTooltip);
#endif
#ifdef CSidlManager__TranslateString
FUNCTION_AT_ADDRESS(class CXStr __cdecl CSidlManager::TranslateString(class CXStr),CSidlManager__TranslateString);
#endif
#ifdef CXMLEnumInfo__dCXMLEnumInfo
FUNCTION_AT_ADDRESS( CXMLEnumInfo::~CXMLEnumInfo(void),CXMLEnumInfo__dCXMLEnumInfo);
#endif
#ifdef CXMLDataClass__dCXMLDataClass
FUNCTION_AT_ADDRESS( CXMLDataClass::~CXMLDataClass(void),CXMLDataClass__dCXMLDataClass);
#endif
#ifdef CTAFrameDraw__CTAFrameDraw1
FUNCTION_AT_ADDRESS( CTAFrameDraw::CTAFrameDraw(class CXStr),CTAFrameDraw__CTAFrameDraw1);
#endif
#ifdef CTAFrameDraw__Set
FUNCTION_AT_ADDRESS(void  CTAFrameDraw::Set(class CTextureAnimation * * const),CTAFrameDraw__Set);
#endif
#ifdef CTAFrameDraw__Draw
FUNCTION_AT_ADDRESS(int  CTAFrameDraw::Draw(class CXRect,class CXRect)const ,CTAFrameDraw__Draw);
#endif
#ifdef CTAFrameDraw__Draw1
FUNCTION_AT_ADDRESS(int  CTAFrameDraw::Draw(class CXRect,class CXRect,int)const ,CTAFrameDraw__Draw1);
#endif
#ifdef CTAFrameDraw__GetHitTestRect
FUNCTION_AT_ADDRESS(class CXRect  CTAFrameDraw::GetHitTestRect(class CXRect,int)const ,CTAFrameDraw__GetHitTestRect);
#endif
#ifdef CTAFrameDraw__GetPieceRect
FUNCTION_AT_ADDRESS(class CXRect  CTAFrameDraw::GetPieceRect(class CXRect,int)const ,CTAFrameDraw__GetPieceRect);
#endif
#ifdef CTAFrameDraw__IsHorizontal
FUNCTION_AT_ADDRESS(bool  CTAFrameDraw::IsHorizontal(void)const ,CTAFrameDraw__IsHorizontal);
#endif
#ifdef CTAFrameDraw__IsVertical
FUNCTION_AT_ADDRESS(bool  CTAFrameDraw::IsVertical(void)const ,CTAFrameDraw__IsVertical);
#endif
#ifdef CTAFrameDraw__GetExtent
FUNCTION_AT_ADDRESS(int  CTAFrameDraw::GetExtent(void)const ,CTAFrameDraw__GetExtent);
#endif
#ifdef CTAFrameDraw__GetMinLength
FUNCTION_AT_ADDRESS(int  CTAFrameDraw::GetMinLength(void)const ,CTAFrameDraw__GetMinLength);
#endif
#ifdef CTAFrameDraw__GetInnerRect
FUNCTION_AT_ADDRESS(class CXRect  CTAFrameDraw::GetInnerRect(class CXRect)const ,CTAFrameDraw__GetInnerRect);
#endif
#ifdef CSpellGemWnd__CSpellGemWnd
FUNCTION_AT_ADDRESS( CSpellGemWnd::CSpellGemWnd(class CXWnd *,unsigned __int32,class CXRect,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,int,int,unsigned long),CSpellGemWnd__CSpellGemWnd);
#endif
#ifdef CSpellGemWnd__Init
FUNCTION_AT_ADDRESS(void  CSpellGemWnd::Init(void),CSpellGemWnd__Init);
#endif
#ifdef CSpellGemWnd__SetSpellIconIndex
FUNCTION_AT_ADDRESS(void  CSpellGemWnd::SetSpellIconIndex(int),CSpellGemWnd__SetSpellIconIndex);
#endif
#ifdef CSpellGemWnd__SetSpellGemTint
FUNCTION_AT_ADDRESS(void  CSpellGemWnd::SetSpellGemTint(unsigned long),CSpellGemWnd__SetSpellGemTint);
#endif
#ifdef CSpellGemWnd__SetGemTintStage
FUNCTION_AT_ADDRESS(void  CSpellGemWnd::SetGemTintStage(int),CSpellGemWnd__SetGemTintStage);
#endif
#ifdef CSpellGemWnd__SetCheck
FUNCTION_AT_ADDRESS(void  CSpellGemWnd::SetCheck(bool),CSpellGemWnd__SetCheck);
#endif
#ifdef CSliderWnd__CSliderWnd
FUNCTION_AT_ADDRESS( CSliderWnd::CSliderWnd(class CXWnd *,unsigned __int32,class CXRect,class CSliderTemplate *),CSliderWnd__CSliderWnd);
#endif
#ifdef CSliderWnd__SetValue
FUNCTION_AT_ADDRESS(void  CSliderWnd::SetValue(int),CSliderWnd__SetValue);
#endif
#ifdef CSliderWnd__SetNumTicks
FUNCTION_AT_ADDRESS(void  CSliderWnd::SetNumTicks(int),CSliderWnd__SetNumTicks);
#endif
#ifdef CSliderWnd__UpdateThumb
FUNCTION_AT_ADDRESS(void  CSliderWnd::UpdateThumb(void),CSliderWnd__UpdateThumb);
#endif
#ifdef CSliderWnd__UpdateMiddleRange
FUNCTION_AT_ADDRESS(void  CSliderWnd::UpdateMiddleRange(void),CSliderWnd__UpdateMiddleRange);
#endif
#ifdef CSliderWnd__GetValue
FUNCTION_AT_ADDRESS(int  CSliderWnd::GetValue(void)const,CSliderWnd__GetValue);
#endif
#ifdef CSliderWnd__GetMiddleRangeRect
FUNCTION_AT_ADDRESS(class CXRect  CSliderWnd::GetMiddleRangeRect(void)const ,CSliderWnd__GetMiddleRangeRect);
#endif
#ifdef CSliderWnd__GetEndCapLeftRect
FUNCTION_AT_ADDRESS(class CXRect  CSliderWnd::GetEndCapLeftRect(void)const ,CSliderWnd__GetEndCapLeftRect);
#endif
#ifdef CSliderWnd__GetEndCapRightRect
FUNCTION_AT_ADDRESS(class CXRect  CSliderWnd::GetEndCapRightRect(void)const ,CSliderWnd__GetEndCapRightRect);
#endif
#ifdef CSliderWnd__GetThumbRect
FUNCTION_AT_ADDRESS(class CXRect  CSliderWnd::GetThumbRect(void)const ,CSliderWnd__GetThumbRect);
#endif
#ifdef CSliderWnd__SetThumbToOffset
FUNCTION_AT_ADDRESS(void  CSliderWnd::SetThumbToOffset(int),CSliderWnd__SetThumbToOffset);
#endif
#ifdef CSliderWnd__DrawMiddleRange
FUNCTION_AT_ADDRESS(int  CSliderWnd::DrawMiddleRange(void)const ,CSliderWnd__DrawMiddleRange);
#endif
#ifdef CSliderWnd__DrawEndCapLeft
FUNCTION_AT_ADDRESS(int  CSliderWnd::DrawEndCapLeft(void)const ,CSliderWnd__DrawEndCapLeft);
#endif
#ifdef CSliderWnd__DrawEndCapRight
FUNCTION_AT_ADDRESS(int  CSliderWnd::DrawEndCapRight(void)const ,CSliderWnd__DrawEndCapRight);
#endif
#ifdef CSliderWnd__DrawThumb
FUNCTION_AT_ADDRESS(int  CSliderWnd::DrawThumb(void)const ,CSliderWnd__DrawThumb);
#endif
#ifdef CXWnd__DrawRaisedRect
FUNCTION_AT_ADDRESS(int __cdecl CXWnd::DrawRaisedRect(class CXRect,class CXRect),CXWnd__DrawRaisedRect);
#endif
#ifdef CXWnd__DrawSunkenRect
FUNCTION_AT_ADDRESS(int __cdecl CXWnd::DrawSunkenRect(class CXRect,class CXRect),CXWnd__DrawSunkenRect);
#endif
#ifdef CEditBaseWnd__SetSel
FUNCTION_AT_ADDRESS(void  CEditBaseWnd::SetSel(int,int),CEditBaseWnd__SetSel);
#endif
#ifdef CInvSlotWnd__CInvSlotWnd
FUNCTION_AT_ADDRESS( CInvSlotWnd::CInvSlotWnd(class CXWnd *,unsigned __int32,class CXRect,class CTextureAnimation *,int,int,int),CInvSlotWnd__CInvSlotWnd);
#endif
#ifdef CInvSlotWnd__SetInvSlot
FUNCTION_AT_ADDRESS(void  CInvSlotWnd::SetInvSlot(class CInvSlot *),CInvSlotWnd__SetInvSlot);
#endif
#ifdef CInvSlotWnd__DrawTooltip
FUNCTION_AT_ADDRESS(int CInvSlotWnd::DrawTooltip(class CXWnd const *)const,CInvSlotWnd__DrawTooltip);
#endif
#ifdef CLabel__CLabel
FUNCTION_AT_ADDRESS( CLabel::CLabel(class CXWnd *,unsigned __int32,class CXRect,int),CLabel__CLabel);
#endif
#ifdef CLabel__SetNoWrap
FUNCTION_AT_ADDRESS(void  CLabel::SetNoWrap(bool),CLabel__SetNoWrap);
#endif
#ifdef CLabel__SetAlignRight
FUNCTION_AT_ADDRESS(void  CLabel::SetAlignRight(bool),CLabel__SetAlignRight);
#endif
#ifdef CLabel__SetAlignCenter
FUNCTION_AT_ADDRESS(void  CLabel::SetAlignCenter(bool),CLabel__SetAlignCenter);
#endif
#ifdef CIMEManager__CIMEManager
FUNCTION_AT_ADDRESS( CIMEManager::CIMEManager(struct HWND__ *),CIMEManager__CIMEManager);
#endif
#ifdef CIMEManager__dCIMEManager
FUNCTION_AT_ADDRESS( CIMEManager::~CIMEManager(void),CIMEManager__dCIMEManager);
#endif
#ifdef CIMEManager__handleWndProc
FUNCTION_AT_ADDRESS(int  CIMEManager::handleWndProc(unsigned int,unsigned int,long),CIMEManager__handleWndProc);
#endif
#ifdef CIMEManager__handleAddChar
FUNCTION_AT_ADDRESS(int  CIMEManager::handleAddChar(unsigned short),CIMEManager__handleAddChar);
#endif
#ifdef CIMEManager__handleInputComposition
FUNCTION_AT_ADDRESS(int  CIMEManager::handleInputComposition(long),CIMEManager__handleInputComposition);
#endif
#ifdef CIMEManager__handleEndComposition
FUNCTION_AT_ADDRESS(int  CIMEManager::handleEndComposition(void),CIMEManager__handleEndComposition);
#endif
#ifdef CIMEManager__handleStartComposition
FUNCTION_AT_ADDRESS(int  CIMEManager::handleStartComposition(void),CIMEManager__handleStartComposition);
#endif
#ifdef CIMEManager__handleOpenCandidates
FUNCTION_AT_ADDRESS(int  CIMEManager::handleOpenCandidates(void),CIMEManager__handleOpenCandidates);
#endif
#ifdef CIMEManager__handleChangeCandidates
FUNCTION_AT_ADDRESS(int  CIMEManager::handleChangeCandidates(void),CIMEManager__handleChangeCandidates);
#endif
#ifdef CIMEManager__handleCloseCandidates
FUNCTION_AT_ADDRESS(int  CIMEManager::handleCloseCandidates(void),CIMEManager__handleCloseCandidates);
#endif
#ifdef CIMEManager__handleImeStatusChanged
FUNCTION_AT_ADDRESS(int  CIMEManager::handleImeStatusChanged(void),CIMEManager__handleImeStatusChanged);
#endif
#ifdef CIMEManager__handleImeChanged
FUNCTION_AT_ADDRESS(int  CIMEManager::handleImeChanged(void),CIMEManager__handleImeChanged);
#endif
#ifdef CIMEManager__setInputEditWnd
FUNCTION_AT_ADDRESS(int  CIMEManager::setInputEditWnd(class CEditWnd *),CIMEManager__setInputEditWnd);
#endif
#ifdef CIMEManager__turnImeOn
FUNCTION_AT_ADDRESS(void  CIMEManager::turnImeOn(void),CIMEManager__turnImeOn);
#endif
#ifdef CIMEManager__turnImeOff
FUNCTION_AT_ADDRESS(void  CIMEManager::turnImeOff(void),CIMEManager__turnImeOff);
#endif
#ifdef CIMEManager__imeIsOn
FUNCTION_AT_ADDRESS(bool  CIMEManager::imeIsOn(void)const ,CIMEManager__imeIsOn);
#endif
#ifdef CIMEManager__imeIsOff
FUNCTION_AT_ADDRESS(bool  CIMEManager::imeIsOff(void)const ,CIMEManager__imeIsOff);
#endif
#ifdef CIMEManager__enableIme
FUNCTION_AT_ADDRESS(void  CIMEManager::enableIme(bool),CIMEManager__enableIme);
#endif
#ifdef CIMEManager__queryImeLanguage
FUNCTION_AT_ADDRESS(int  CIMEManager::queryImeLanguage(void)const ,CIMEManager__queryImeLanguage);
#endif
#ifdef CIMEManager__queryImeProperties
FUNCTION_AT_ADDRESS(int  CIMEManager::queryImeProperties(void)const ,CIMEManager__queryImeProperties);
#endif
#ifdef CIMEManager__setInputState
FUNCTION_AT_ADDRESS(void  CIMEManager::setInputState(int),CIMEManager__setInputState);
#endif
#ifdef CIMEManager__getInputState
FUNCTION_AT_ADDRESS(int  CIMEManager::getInputState(void)const ,CIMEManager__getInputState);
#endif
#ifdef CIMEManager__getInputLanguage
FUNCTION_AT_ADDRESS(int  CIMEManager::getInputLanguage(void)const ,CIMEManager__getInputLanguage);
#endif
#ifdef CIMEManager__getImeProperties
FUNCTION_AT_ADDRESS(int  CIMEManager::getImeProperties(void)const ,CIMEManager__getImeProperties);
#endif
#ifdef CIMEManager__getWindowHandle
FUNCTION_AT_ADDRESS(struct HWND__ *  CIMEManager::getWindowHandle(void)const ,CIMEManager__getWindowHandle);
#endif
#ifdef CUITextureInfo__Draw
FUNCTION_AT_ADDRESS(int  CUITextureInfo::Draw(class CXRect,class CXRect,class CXRect,unsigned long,unsigned long)const ,CUITextureInfo__Draw);
#endif
#ifdef CUITextureInfo__Draw1
FUNCTION_AT_ADDRESS(int  CUITextureInfo::Draw(class CXRect,class CXRect,class CXRect,unsigned long *,unsigned long *)const ,CUITextureInfo__Draw1);
#endif
#ifdef CUITexturePiece__Draw
FUNCTION_AT_ADDRESS(int  CUITexturePiece::Draw(class CXRect,class CXRect,unsigned long,unsigned long)const ,CUITexturePiece__Draw);
#endif
#ifdef CUITexturePiece__Draw1
FUNCTION_AT_ADDRESS(int  CUITexturePiece::Draw(class CXRect,class CXRect,class CXRect,unsigned long,unsigned long)const ,CUITexturePiece__Draw1);
#endif
#ifdef CUITextureInfo__Tile
FUNCTION_AT_ADDRESS(int  CUITextureInfo::Tile(class CXRect,unsigned long,unsigned long)const ,CUITextureInfo__Tile);
#endif
#ifdef CUITextureInfo__Tile1
FUNCTION_AT_ADDRESS(int  CUITextureInfo::Tile(class CXRect,unsigned long *,unsigned long *)const ,CUITextureInfo__Tile1);
#endif
#ifdef CUITextureInfo__Preload
FUNCTION_AT_ADDRESS(int  CUITextureInfo::Preload(void),CUITextureInfo__Preload);
#endif
#ifdef CXMLDataPtr__SetNewPtr
FUNCTION_AT_ADDRESS(void  CXMLDataPtr::SetNewPtr(class CXMLData *),CXMLDataPtr__SetNewPtr);
#endif
#ifdef CXMLEnumInfo__GetStreamSize
FUNCTION_AT_ADDRESS(int  CXMLEnumInfo::GetStreamSize(void),CXMLEnumInfo__GetStreamSize);
#endif
#ifdef CXMLEnumInfo__ReadFromStream
FUNCTION_AT_ADDRESS(void  CXMLEnumInfo::ReadFromStream(class CMemoryStream &),CXMLEnumInfo__ReadFromStream);
#endif
#ifdef CMemoryStream__GetString
FUNCTION_AT_ADDRESS(void  CMemoryStream::GetString(class CXStr &),CMemoryStream__GetString);
#endif
#ifdef CXMLEnumInfo__WriteToStream
FUNCTION_AT_ADDRESS(void  CXMLEnumInfo::WriteToStream(class CMemoryStream &),CXMLEnumInfo__WriteToStream);
#endif
#ifdef CXMLDataClass__GetNumLeaf
FUNCTION_AT_ADDRESS(int  CXMLDataClass::GetNumLeaf(void),CXMLDataClass__GetNumLeaf);
#endif
#ifdef CXMLDataClass__GetStreamSize
FUNCTION_AT_ADDRESS(int  CXMLDataClass::GetStreamSize(void),CXMLDataClass__GetStreamSize);
#endif
#ifdef CXMLDataClass__ReadFromStream
FUNCTION_AT_ADDRESS(void  CXMLDataClass::ReadFromStream(class CMemoryStream &,class CXMLDataManager &),CXMLDataClass__ReadFromStream);
#endif
#ifdef CXMLDataClass__WriteToStream
FUNCTION_AT_ADDRESS(void  CXMLDataClass::WriteToStream(class CMemoryStream &),CXMLDataClass__WriteToStream);
#endif
#ifdef CXMLDataManager__CXMLDataManager
FUNCTION_AT_ADDRESS( CXMLDataManager::CXMLDataManager(void),CXMLDataManager__CXMLDataManager);
#endif
#ifdef CXMLDataManager__GetXMLData
FUNCTION_AT_ADDRESS(class CXMLData *  CXMLDataManager::GetXMLData(int,int),CXMLDataManager__GetXMLData);
#endif
#ifdef CXMLDataManager__GetXMLData1
FUNCTION_AT_ADDRESS(class CXMLData *  CXMLDataManager::GetXMLData(class CXStr,class CXStr),CXMLDataManager__GetXMLData1);
#endif
#ifdef CXMLDataManager__GetNumClass
FUNCTION_AT_ADDRESS(int  CXMLDataManager::GetNumClass(void),CXMLDataManager__GetNumClass);
#endif
#ifdef CXMLDataManager__GetNumItem
FUNCTION_AT_ADDRESS(int  CXMLDataManager::GetNumItem(int),CXMLDataManager__GetNumItem);
#endif
#ifdef CXMLDataManager__GetClassIdx
FUNCTION_AT_ADDRESS(int  CXMLDataManager::GetClassIdx(class CXStr),CXMLDataManager__GetClassIdx);
#endif
#ifdef CXMLDataManager__GetItemIdx
FUNCTION_AT_ADDRESS(int  CXMLDataManager::GetItemIdx(int,class CXStr),CXMLDataManager__GetItemIdx);
#endif
#ifdef CXMLDataPtr__Free
FUNCTION_AT_ADDRESS(void  CXMLDataPtr::Free(void),CXMLDataPtr__Free);
#endif
#ifdef CXMLDataManager__AddToSuperType
//FUNCTION_AT_ADDRESS(void  CXMLDataManager::AddToSuperType(class CXStr,class CXMLDataPtr),CXMLDataManager__AddToSuperType);
#endif
#ifdef CXMLDataPtr__operator_equal
FUNCTION_AT_ADDRESS(class CXMLDataPtr &  CXMLDataPtr::operator=(class CXMLDataPtr const &),CXMLDataPtr__operator_equal);
#endif
#ifdef CXMLDataManager__IsDerivedFrom
FUNCTION_AT_ADDRESS(bool  CXMLDataManager::IsDerivedFrom(int,int),CXMLDataManager__IsDerivedFrom);
#endif
#ifdef CXMLDataManager__SetEnumHash
FUNCTION_AT_ADDRESS(void  CXMLDataManager::SetEnumHash(void),CXMLDataManager__SetEnumHash);
#endif
#ifdef CXMLDataManager__ReadFromXMLSOM
FUNCTION_AT_ADDRESS(bool  CXMLDataManager::ReadFromXMLSOM(class CXMLSOMDocument &),CXMLDataManager__ReadFromXMLSOM);
#endif
#ifdef CXMLDataPtr__CXMLDataPtr
FUNCTION_AT_ADDRESS( CXMLDataPtr::CXMLDataPtr(void),CXMLDataPtr__CXMLDataPtr);
#endif
#ifdef CXMLDataClass__CXMLDataClass
FUNCTION_AT_ADDRESS( CXMLDataClass::CXMLDataClass(void),CXMLDataClass__CXMLDataClass);
#endif
#ifdef CXMLEnumInfo__CXMLEnumInfo
FUNCTION_AT_ADDRESS( CXMLEnumInfo::CXMLEnumInfo(void),CXMLEnumInfo__CXMLEnumInfo);
#endif
#ifdef CStmlReport__CreateReport
FUNCTION_AT_ADDRESS(class CStmlReport * __cdecl CStmlReport::CreateReport(class CXStr),CStmlReport__CreateReport);
#endif
#ifdef CXFileXML__Load
FUNCTION_AT_ADDRESS(bool  CXFileXML::Load(char *),CXFileXML__Load);
#endif
#ifdef CParseTokXML__GetEntityRef
FUNCTION_AT_ADDRESS(bool  CParseTokXML::GetEntityRef(char &),CParseTokXML__GetEntityRef);
#endif
#ifdef CParseTokXML__NextToken
//FUNCTION_AT_ADDRESS(enum ETokTypeXML  CParseTokXML::NextToken(void),CParseTokXML__NextToken);
#endif
#ifdef CParseTokensXML__SetError
FUNCTION_AT_ADDRESS(void __cdecl CParseTokensXML::SetError(char const *,...),CParseTokensXML__SetError);
#endif
#ifdef CParseTokensXML__GetCurFile
FUNCTION_AT_ADDRESS(class CXStr  CParseTokensXML::GetCurFile(void),CParseTokensXML__GetCurFile);
#endif
#ifdef CParseTokensXML__Accept
//FUNCTION_AT_ADDRESS(bool  CParseTokensXML::Accept(enum ETokTypeXML),CParseTokensXML__Accept);
#endif
#ifdef CXMLSOMParser__ParseProcess
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseProcess(void),CXMLSOMParser__ParseProcess);
#endif
#ifdef CXMLSOMParser__ParseNameSpaceToken
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseNameSpaceToken(class CXStr &),CXMLSOMParser__ParseNameSpaceToken);
#endif
#ifdef CXMLSOMParser__ParseStartTag
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseStartTag(bool &),CXMLSOMParser__ParseStartTag);
#endif
#ifdef CXMLSOMParser__ParseEndTag
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseEndTag(class CXStr),CXMLSOMParser__ParseEndTag);
#endif
#ifdef CXMLSOMParser__ParseNodeList
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseNodeList(void),CXMLSOMParser__ParseNodeList);
#endif
#ifdef CXMLSOMParser__ParseNode
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseNode(void),CXMLSOMParser__ParseNode);
#endif
#ifdef CXMLSOMParser__ParseDocument
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseDocument(void),CXMLSOMParser__ParseDocument);
#endif
#ifdef CParseTokensXML__StartFileBased
FUNCTION_AT_ADDRESS(bool  CParseTokensXML::StartFileBased(class CXStr),CParseTokensXML__StartFileBased);
#endif
#ifdef CXFileXML__dCXFileXML
FUNCTION_AT_ADDRESS( CXFileXML::~CXFileXML(void),CXFileXML__dCXFileXML);
#endif
#ifdef CTokenXML__dCTokenXML
FUNCTION_AT_ADDRESS( CTokenXML::~CTokenXML(void),CTokenXML__dCTokenXML);
#endif
#ifdef CXMLSOMParser__ParseFile
FUNCTION_AT_ADDRESS(bool  CXMLSOMParser::ParseFile(class CXStr),CXMLSOMParser__ParseFile);
#endif
#ifdef CParseTokensXML__dCParseTokensXML
FUNCTION_AT_ADDRESS( CParseTokensXML::~CParseTokensXML(void),CParseTokensXML__dCParseTokensXML);
#endif
#ifdef CXMLSOMParser__dCXMLSOMParser
FUNCTION_AT_ADDRESS( CXMLSOMParser::~CXMLSOMParser(void),CXMLSOMParser__dCXMLSOMParser);
#endif
#ifdef CParseTokXML__dCParseTokXML
FUNCTION_AT_ADDRESS( CParseTokXML::~CParseTokXML(void),CParseTokXML__dCParseTokXML);
#endif
#ifdef CClickStickInfo__CClickStickInfo
FUNCTION_AT_ADDRESS( CClickStickInfo::CClickStickInfo(void),CClickStickInfo__CClickStickInfo);
#endif
#ifdef CDIMap__CDIMap
FUNCTION_AT_ADDRESS( CDIMap::CDIMap(void),CDIMap__CDIMap);
#endif
#ifdef CXStr__CheckNoLock
FUNCTION_AT_ADDRESS(void  CXStr::CheckNoLock(void),CXStr__CheckNoLock);
#endif
#ifdef CDIMap__dCDIMap
FUNCTION_AT_ADDRESS( CDIMap::~CDIMap(void),CDIMap__dCDIMap);
#endif
#ifdef CIMECandidateList__dCIMECandidateList
FUNCTION_AT_ADDRESS( CIMECandidateList::~CIMECandidateList(void),CIMECandidateList__dCIMECandidateList);
#endif
#ifdef CDIMap__LoadMappingFromFile
FUNCTION_AT_ADDRESS(void  CDIMap::LoadMappingFromFile(char *),CDIMap__LoadMappingFromFile);
#endif
#ifdef CHashCXStrInt32__CHashCXStrInt32
FUNCTION_AT_ADDRESS( CHashCXStrInt32::CHashCXStrInt32(void),CHashCXStrInt32__CHashCXStrInt32);
#endif
#ifdef CHashCXStrInt32__dCHashCXStrInt32
FUNCTION_AT_ADDRESS( CHashCXStrInt32::~CHashCXStrInt32(void),CHashCXStrInt32__dCHashCXStrInt32);
#endif
#ifdef CHashCXStrInt32__KeyToBin
FUNCTION_AT_ADDRESS(int  CHashCXStrInt32::KeyToBin(class CXStr const &)const ,CHashCXStrInt32__KeyToBin);
#endif
#ifdef CHashCXStrInt32__LookUp
FUNCTION_AT_ADDRESS(bool  CHashCXStrInt32::LookUp(class CXStr const &,int &)const ,CHashCXStrInt32__LookUp);
#endif
#ifdef CHashCXStrInt32__Insert
FUNCTION_AT_ADDRESS(bool  CHashCXStrInt32::Insert(class CXStr const &,int),CHashCXStrInt32__Insert);
#endif
#ifdef CHashCXStrInt32__Reset
FUNCTION_AT_ADDRESS(void  CHashCXStrInt32::Reset(void),CHashCXStrInt32__Reset);
#endif
#ifdef CParamPoint__operator_equal
FUNCTION_AT_ADDRESS(class CParamPoint &  CParamPoint::operator=(class CParamPoint const &),CParamPoint__operator_equal);
#endif
#ifdef CParamSize__operator_equal
FUNCTION_AT_ADDRESS(class CParamSize &  CParamSize::operator=(class CParamSize const &),CParamSize__operator_equal);
#endif
#ifdef CParamGaugeDrawTemplate__operator_equal
FUNCTION_AT_ADDRESS(class CParamGaugeDrawTemplate &  CParamGaugeDrawTemplate::operator=(class CParamGaugeDrawTemplate const &),CParamGaugeDrawTemplate__operator_equal);
#endif
#ifdef CParamSpellGemDrawTemplate__operator_equal
FUNCTION_AT_ADDRESS(class CParamSpellGemDrawTemplate &  CParamSpellGemDrawTemplate::operator=(class CParamSpellGemDrawTemplate const &),CParamSpellGemDrawTemplate__operator_equal);
#endif
#ifdef CParamScreenPiece__operator_equal
FUNCTION_AT_ADDRESS(class CParamScreenPiece &  CParamScreenPiece::operator=(class CParamScreenPiece const &),CParamScreenPiece__operator_equal);
#endif
#ifdef CParamControl__operator_equal
FUNCTION_AT_ADDRESS(class CParamControl &  CParamControl::operator=(class CParamControl const &),CParamControl__operator_equal);
#endif
#ifdef CParamSliderDrawTemplate__operator_equal
FUNCTION_AT_ADDRESS(class CParamSliderDrawTemplate &  CParamSliderDrawTemplate::operator=(class CParamSliderDrawTemplate const &),CParamSliderDrawTemplate__operator_equal);
#endif
#ifdef CParamStaticText__operator_equal
FUNCTION_AT_ADDRESS(class CParamStaticText &  CParamStaticText::operator=(class CParamStaticText const &),CParamStaticText__operator_equal);
#endif
#ifdef CParamStaticAnimation__operator_equal
FUNCTION_AT_ADDRESS(class CParamStaticAnimation &  CParamStaticAnimation::operator=(class CParamStaticAnimation const &),CParamStaticAnimation__operator_equal);
#endif
#ifdef CParamStaticFrame__operator_equal
FUNCTION_AT_ADDRESS(class CParamStaticFrame &  CParamStaticFrame::operator=(class CParamStaticFrame const &),CParamStaticFrame__operator_equal);
#endif
#ifdef CParamStaticHeader__operator_equal
FUNCTION_AT_ADDRESS(class CParamStaticHeader &  CParamStaticHeader::operator=(class CParamStaticHeader const &),CParamStaticHeader__operator_equal);
#endif
#ifdef CParamListboxColumn__operator_equal
FUNCTION_AT_ADDRESS(class CParamListboxColumn &  CParamListboxColumn::operator=(class CParamListboxColumn const &),CParamListboxColumn__operator_equal);
#endif
#ifdef CParamListbox__operator_equal
FUNCTION_AT_ADDRESS(class CParamListbox &  CParamListbox::operator=(class CParamListbox const &),CParamListbox__operator_equal);
#endif
#ifdef CParamButton__operator_equal
FUNCTION_AT_ADDRESS(class CParamButton &  CParamButton::operator=(class CParamButton const &),CParamButton__operator_equal);
#endif
#ifdef CParamGauge__operator_equal
FUNCTION_AT_ADDRESS(class CParamGauge &  CParamGauge::operator=(class CParamGauge const &),CParamGauge__operator_equal);
#endif
#ifdef CParamSpellGem__operator_equal
FUNCTION_AT_ADDRESS(class CParamSpellGem &  CParamSpellGem::operator=(class CParamSpellGem const &),CParamSpellGem__operator_equal);
#endif
#ifdef CParamInvSlot__operator_equal
FUNCTION_AT_ADDRESS(class CParamInvSlot &  CParamInvSlot::operator=(class CParamInvSlot const &),CParamInvSlot__operator_equal);
#endif
#ifdef CParamEditbox__operator_equal
FUNCTION_AT_ADDRESS(class CParamEditbox &  CParamEditbox::operator=(class CParamEditbox const &),CParamEditbox__operator_equal);
#endif
#ifdef CParamSlider__operator_equal
FUNCTION_AT_ADDRESS(class CParamSlider &  CParamSlider::operator=(class CParamSlider const &),CParamSlider__operator_equal);
#endif
#ifdef CParamLabel__operator_equal
FUNCTION_AT_ADDRESS(class CParamLabel &  CParamLabel::operator=(class CParamLabel const &),CParamLabel__operator_equal);
#endif
#ifdef CParamCombobox__operator_equal
FUNCTION_AT_ADDRESS(class CParamCombobox &  CParamCombobox::operator=(class CParamCombobox const &),CParamCombobox__operator_equal);
#endif
#ifdef CParamPage__operator_equal
FUNCTION_AT_ADDRESS(class CParamPage &  CParamPage::operator=(class CParamPage const &),CParamPage__operator_equal);
#endif
#ifdef CParamTabBox__operator_equal
FUNCTION_AT_ADDRESS(class CParamTabBox &  CParamTabBox::operator=(class CParamTabBox const &),CParamTabBox__operator_equal);
#endif
#ifdef CParamScreen__operator_equal
FUNCTION_AT_ADDRESS(class CParamScreen &  CParamScreen::operator=(class CParamScreen const &),CParamScreen__operator_equal);
#endif
#ifdef CParamSuiteDefaults__operator_equal
FUNCTION_AT_ADDRESS(class CParamSuiteDefaults &  CParamSuiteDefaults::operator=(class CParamSuiteDefaults const &),CParamSuiteDefaults__operator_equal);
#endif
#ifdef CParamClass__CParamClass
FUNCTION_AT_ADDRESS( CParamClass::CParamClass(void),CParamClass__CParamClass);
#endif
#ifdef CParamRGB__CParamRGB
FUNCTION_AT_ADDRESS( CParamRGB::CParamRGB(void),CParamRGB__CParamRGB);
#endif
#ifdef CParamPoint__CParamPoint
FUNCTION_AT_ADDRESS( CParamPoint::CParamPoint(void),CParamPoint__CParamPoint);
#endif
#ifdef CParamSize__CParamSize
FUNCTION_AT_ADDRESS( CParamSize::CParamSize(void),CParamSize__CParamSize);
#endif
#ifdef CParamTextureInfo__CParamTextureInfo
FUNCTION_AT_ADDRESS( CParamTextureInfo::CParamTextureInfo(void),CParamTextureInfo__CParamTextureInfo);
#endif
#ifdef CXMLSOMCursorSaveFast__dCXMLSOMCursorSaveFast
FUNCTION_AT_ADDRESS( CXMLSOMCursorSaveFast::~CXMLSOMCursorSaveFast(void),CXMLSOMCursorSaveFast__dCXMLSOMCursorSaveFast);
#endif
#ifdef CParamFrame__CParamFrame
FUNCTION_AT_ADDRESS( CParamFrame::CParamFrame(void),CParamFrame__CParamFrame);
#endif
#ifdef CParamUi2DAnimation__CParamUi2DAnimation
FUNCTION_AT_ADDRESS( CParamUi2DAnimation::CParamUi2DAnimation(void),CParamUi2DAnimation__CParamUi2DAnimation);
#endif
#ifdef CParamButtonDrawTemplate__CParamButtonDrawTemplate
FUNCTION_AT_ADDRESS( CParamButtonDrawTemplate::CParamButtonDrawTemplate(void),CParamButtonDrawTemplate__CParamButtonDrawTemplate);
#endif
#ifdef CParamGaugeDrawTemplate__CParamGaugeDrawTemplate
FUNCTION_AT_ADDRESS( CParamGaugeDrawTemplate::CParamGaugeDrawTemplate(void),CParamGaugeDrawTemplate__CParamGaugeDrawTemplate);
#endif
#ifdef CParamSpellGemDrawTemplate__CParamSpellGemDrawTemplate
FUNCTION_AT_ADDRESS( CParamSpellGemDrawTemplate::CParamSpellGemDrawTemplate(void),CParamSpellGemDrawTemplate__CParamSpellGemDrawTemplate);
#endif
#ifdef CParamFrameTemplate__CParamFrameTemplate
FUNCTION_AT_ADDRESS( CParamFrameTemplate::CParamFrameTemplate(void),CParamFrameTemplate__CParamFrameTemplate);
#endif
#ifdef CParamScrollbarDrawTemplate__CParamScrollbarDrawTemplate
FUNCTION_AT_ADDRESS( CParamScrollbarDrawTemplate::CParamScrollbarDrawTemplate(void),CParamScrollbarDrawTemplate__CParamScrollbarDrawTemplate);
#endif
#ifdef CParamWindowDrawTemplate__CParamWindowDrawTemplate
FUNCTION_AT_ADDRESS( CParamWindowDrawTemplate::CParamWindowDrawTemplate(void),CParamWindowDrawTemplate__CParamWindowDrawTemplate);
#endif
#ifdef CParamSliderDrawTemplate__CParamSliderDrawTemplate
FUNCTION_AT_ADDRESS( CParamSliderDrawTemplate::CParamSliderDrawTemplate(void),CParamSliderDrawTemplate__CParamSliderDrawTemplate);
#endif
#ifdef CParamScreenPiece__CParamScreenPiece
FUNCTION_AT_ADDRESS( CParamScreenPiece::CParamScreenPiece(void),CParamScreenPiece__CParamScreenPiece);
#endif
#ifdef CParamStaticScreenPiece__CParamStaticScreenPiece
FUNCTION_AT_ADDRESS( CParamStaticScreenPiece::CParamStaticScreenPiece(void),CParamStaticScreenPiece__CParamStaticScreenPiece);
#endif
#ifdef CParamStaticAnimation__CParamStaticAnimation
FUNCTION_AT_ADDRESS( CParamStaticAnimation::CParamStaticAnimation(void),CParamStaticAnimation__CParamStaticAnimation);
#endif
#ifdef CParamStaticText__CParamStaticText
FUNCTION_AT_ADDRESS( CParamStaticText::CParamStaticText(void),CParamStaticText__CParamStaticText);
#endif
#ifdef CParamStaticFrame__CParamStaticFrame
FUNCTION_AT_ADDRESS( CParamStaticFrame::CParamStaticFrame(void),CParamStaticFrame__CParamStaticFrame);
#endif
#ifdef CParamStaticHeader__CParamStaticHeader
FUNCTION_AT_ADDRESS( CParamStaticHeader::CParamStaticHeader(void),CParamStaticHeader__CParamStaticHeader);
#endif
#ifdef CParamControl__CParamControl
FUNCTION_AT_ADDRESS( CParamControl::CParamControl(void),CParamControl__CParamControl);
#endif
#ifdef CParamListboxColumn__CParamListboxColumn
FUNCTION_AT_ADDRESS( CParamListboxColumn::CParamListboxColumn(void),CParamListboxColumn__CParamListboxColumn);
#endif
#ifdef CParamListbox__CParamListbox
FUNCTION_AT_ADDRESS( CParamListbox::CParamListbox(void),CParamListbox__CParamListbox);
#endif
#ifdef CParamButton__CParamButton
FUNCTION_AT_ADDRESS( CParamButton::CParamButton(void),CParamButton__CParamButton);
#endif
#ifdef CParamGauge__CParamGauge
FUNCTION_AT_ADDRESS( CParamGauge::CParamGauge(void),CParamGauge__CParamGauge);
#endif
#ifdef CParamSpellGem__CParamSpellGem
FUNCTION_AT_ADDRESS( CParamSpellGem::CParamSpellGem(void),CParamSpellGem__CParamSpellGem);
#endif
#ifdef CParamInvSlot__CParamInvSlot
FUNCTION_AT_ADDRESS( CParamInvSlot::CParamInvSlot(void),CParamInvSlot__CParamInvSlot);
#endif
#ifdef CParamEditbox__CParamEditbox
FUNCTION_AT_ADDRESS( CParamEditbox::CParamEditbox(void),CParamEditbox__CParamEditbox);
#endif
#ifdef CParamSlider__CParamSlider
FUNCTION_AT_ADDRESS( CParamSlider::CParamSlider(void),CParamSlider__CParamSlider);
#endif
#ifdef CParamLabel__CParamLabel
FUNCTION_AT_ADDRESS( CParamLabel::CParamLabel(void),CParamLabel__CParamLabel);
#endif
#ifdef CParamSTMLbox__CParamSTMLbox
FUNCTION_AT_ADDRESS( CParamSTMLbox::CParamSTMLbox(void),CParamSTMLbox__CParamSTMLbox);
#endif
#ifdef CParamCombobox__CParamCombobox
FUNCTION_AT_ADDRESS( CParamCombobox::CParamCombobox(void),CParamCombobox__CParamCombobox);
#endif
#ifdef CParamPage__CParamPage
FUNCTION_AT_ADDRESS( CParamPage::CParamPage(void),CParamPage__CParamPage);
#endif
#ifdef CParamTabBox__CParamTabBox
FUNCTION_AT_ADDRESS( CParamTabBox::CParamTabBox(void),CParamTabBox__CParamTabBox);
#endif
#ifdef CParamScreen__CParamScreen
FUNCTION_AT_ADDRESS( CParamScreen::CParamScreen(void),CParamScreen__CParamScreen);
#endif
#ifdef CParamSuiteDefaults__CParamSuiteDefaults
FUNCTION_AT_ADDRESS( CParamSuiteDefaults::CParamSuiteDefaults(void),CParamSuiteDefaults__CParamSuiteDefaults);
#endif
#ifdef CXMLData__CXMLData
FUNCTION_AT_ADDRESS( CXMLData::CXMLData(void),CXMLData__CXMLData);
#endif
#ifdef CPageWnd__CPageWnd
FUNCTION_AT_ADDRESS( CPageWnd::CPageWnd(class CXWnd *,unsigned __int32,class CXRect,class CXStr,class CPageTemplate *),CPageWnd__CPageWnd);
#endif
#ifdef CGaugeWnd__CGaugeWnd
FUNCTION_AT_ADDRESS( CGaugeWnd::CGaugeWnd(class CXWnd *,unsigned __int32,class CXRect,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,int,unsigned long,unsigned long,bool,int,int,int,int),CGaugeWnd__CGaugeWnd);
#endif
#ifdef CGaugeWnd__CalcFillRect
FUNCTION_AT_ADDRESS(class CXRect  CGaugeWnd::CalcFillRect(class CXRect *,int)const ,CGaugeWnd__CalcFillRect);
#endif
#ifdef CGaugeWnd__CalcLinesFillRect
FUNCTION_AT_ADDRESS(class CXRect  CGaugeWnd::CalcLinesFillRect(class CXRect *,int)const ,CGaugeWnd__CalcLinesFillRect);
#endif
#ifdef CGaugeWnd__SpecialToolTip
FUNCTION_AT_ADDRESS(void  CGaugeWnd::SpecialToolTip(void),CGaugeWnd__SpecialToolTip);
#endif
#ifdef CCheckBoxWnd__CCheckBoxWnd
FUNCTION_AT_ADDRESS( CCheckBoxWnd::CCheckBoxWnd(class CXWnd *,unsigned __int32,class CXRect,class CXPoint,class CXSize,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *),CCheckBoxWnd__CCheckBoxWnd);
#endif
#ifdef CCheckBoxWnd__SetRadioLook
FUNCTION_AT_ADDRESS(void  CCheckBoxWnd::SetRadioLook(void),CCheckBoxWnd__SetRadioLook);
#endif
#ifdef CIMEStatusBar__CIMEStatusBar
FUNCTION_AT_ADDRESS( CIMEStatusBar::CIMEStatusBar(class CIMEManager *),CIMEStatusBar__CIMEStatusBar);
#endif
#ifdef CIMEStatusBar__show
FUNCTION_AT_ADDRESS(int  CIMEStatusBar::show(class CIMEComposition const *),CIMEStatusBar__show);
#endif
#ifdef CIMEStatusBar__update
FUNCTION_AT_ADDRESS(int  CIMEStatusBar::update(void),CIMEStatusBar__update);
#endif
#ifdef CIMEStatusBar__hide
FUNCTION_AT_ADDRESS(int  CIMEStatusBar::hide(void),CIMEStatusBar__hide);
#endif
#ifdef CIMEStatusBar__handleChineseSimplifiedStatusChange
FUNCTION_AT_ADDRESS(void  CIMEStatusBar::handleChineseSimplifiedStatusChange(unsigned long),CIMEStatusBar__handleChineseSimplifiedStatusChange);
#endif
#ifdef CIMEStatusBar__handleChineseTraditionalStatusChange
FUNCTION_AT_ADDRESS(void  CIMEStatusBar::handleChineseTraditionalStatusChange(unsigned long),CIMEStatusBar__handleChineseTraditionalStatusChange);
#endif
#ifdef CIMEStatusBar__handleJapaneseStatusChange
FUNCTION_AT_ADDRESS(void  CIMEStatusBar::handleJapaneseStatusChange(unsigned long),CIMEStatusBar__handleJapaneseStatusChange);
#endif
#ifdef CIMEStatusBar__handleKoreanStatusChange
FUNCTION_AT_ADDRESS(void  CIMEStatusBar::handleKoreanStatusChange(unsigned long),CIMEStatusBar__handleKoreanStatusChange);
#endif
#ifdef CIMEStatusBar__repositionStatusWindow
FUNCTION_AT_ADDRESS(int  CIMEStatusBar::repositionStatusWindow(void),CIMEStatusBar__repositionStatusWindow);
#endif
#ifdef CIMECandidateList__CIMECandidateList
FUNCTION_AT_ADDRESS( CIMECandidateList::CIMECandidateList(class CIMEManager *),CIMECandidateList__CIMECandidateList);
#endif
#ifdef CIMECandidateList__show
FUNCTION_AT_ADDRESS(int  CIMECandidateList::show(class CIMEComposition const *)const ,CIMECandidateList__show);
#endif
#ifdef CIMECandidateList__repositionImeCandidateList
FUNCTION_AT_ADDRESS(int  CIMECandidateList::repositionImeCandidateList(int,int)const ,CIMECandidateList__repositionImeCandidateList);
#endif
#ifdef CIMEComposition__CIMEComposition
FUNCTION_AT_ADDRESS( CIMEComposition::CIMEComposition(class CIMEManager *),CIMEComposition__CIMEComposition);
#endif
#ifdef CIMEComposition__dCIMEComposition
FUNCTION_AT_ADDRESS( CIMEComposition::~CIMEComposition(void),CIMEComposition__dCIMEComposition);
#endif
#ifdef CIMEComposition__addInputChar
FUNCTION_AT_ADDRESS(int  CIMEComposition::addInputChar(unsigned short),CIMEComposition__addInputChar);
#endif
#ifdef CIMEComposition__addInputString
FUNCTION_AT_ADDRESS(int  CIMEComposition::addInputString(unsigned short *,int),CIMEComposition__addInputString);
#endif
#ifdef CIMEComposition__addInputString1
FUNCTION_AT_ADDRESS(int  CIMEComposition::addInputString(class CXStr const &,int),CIMEComposition__addInputString1);
#endif
#ifdef CIMEComposition__addStringFromIme
FUNCTION_AT_ADDRESS(int  CIMEComposition::addStringFromIme(long),CIMEComposition__addStringFromIme);
#endif
#ifdef CIMEComposition__directToEditWnd
FUNCTION_AT_ADDRESS(void  CIMEComposition::directToEditWnd(class CEditWnd *),CIMEComposition__directToEditWnd);
#endif
#ifdef CIMEComposition__getCursorPoint
FUNCTION_AT_ADDRESS(class CXPoint  CIMEComposition::getCursorPoint(void)const ,CIMEComposition__getCursorPoint);
#endif
#ifdef CIMEComposition__getCompositionArea
FUNCTION_AT_ADDRESS(class CXRect  CIMEComposition::getCompositionArea(void)const ,CIMEComposition__getCompositionArea);
#endif
#ifdef CIMEComposition__repositionImeCompositionWindow
FUNCTION_AT_ADDRESS(int  CIMEComposition::repositionImeCompositionWindow(int,int)const ,CIMEComposition__repositionImeCompositionWindow);
#endif
#ifdef CIMEComposition__allocateImeCompositionString
FUNCTION_AT_ADDRESS(unsigned short *  CIMEComposition::allocateImeCompositionString(long)const ,CIMEComposition__allocateImeCompositionString);
#endif
#ifdef CIMEComposition__allocateImeCompositionAttributes
FUNCTION_AT_ADDRESS(struct CompAttr *  CIMEComposition::allocateImeCompositionAttributes(void)const ,CIMEComposition__allocateImeCompositionAttributes);
#endif
#ifdef CIMEComposition__getCompositionInsertIndex
FUNCTION_AT_ADDRESS(int  CIMEComposition::getCompositionInsertIndex(void)const ,CIMEComposition__getCompositionInsertIndex);
#endif
#ifdef CIMEComposition__handleImeComposing
FUNCTION_AT_ADDRESS(int  CIMEComposition::handleImeComposing(void),CIMEComposition__handleImeComposing);
#endif
#ifdef CIMEComposition__applyJapaneseComposingRules
FUNCTION_AT_ADDRESS(int  CIMEComposition::applyJapaneseComposingRules(class CXStr *),CIMEComposition__applyJapaneseComposingRules);
#endif
#ifdef CIMEComposition__applyChineseComposingRules
FUNCTION_AT_ADDRESS(int  CIMEComposition::applyChineseComposingRules(class CXStr *),CIMEComposition__applyChineseComposingRules);
#endif
#ifdef CIMEComposition__applyKoreanComposingRules
FUNCTION_AT_ADDRESS(int  CIMEComposition::applyKoreanComposingRules(class CXStr *),CIMEComposition__applyKoreanComposingRules);
#endif
#ifdef CIMEComposition__addCompositionHighlights
FUNCTION_AT_ADDRESS(int  CIMEComposition::addCompositionHighlights(void),CIMEComposition__addCompositionHighlights);
#endif
#ifdef CIMEComposition__handleImeResult
FUNCTION_AT_ADDRESS(int  CIMEComposition::handleImeResult(void),CIMEComposition__handleImeResult);
#endif
#ifdef CIMEComposition__backupCurrentText
FUNCTION_AT_ADDRESS(void  CIMEComposition::backupCurrentText(void),CIMEComposition__backupCurrentText);
#endif
#ifdef CIMEComposition__revertToBackupText
FUNCTION_AT_ADDRESS(void  CIMEComposition::revertToBackupText(void),CIMEComposition__revertToBackupText);
#endif
#ifdef CMemoryStream__GetStringSize
FUNCTION_AT_ADDRESS(int __cdecl CMemoryStream::GetStringSize(class CXStr &),CMemoryStream__GetStringSize);
#endif
#ifdef CMemoryStream__PutString
FUNCTION_AT_ADDRESS(void  CMemoryStream::PutString(class CXStr &),CMemoryStream__PutString);
#endif
#ifdef CMemoryStream__GetString1
FUNCTION_AT_ADDRESS(class CXStr  CMemoryStream::GetString(void),CMemoryStream__GetString1);
#endif
#ifdef CXMLSOMDocument__GetValueObjectId
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocument::GetValueObjectId(class CXStr,class CXStr,unsigned __int32 &),CXMLSOMDocument__GetValueObjectId);
#endif
#ifdef CXMLSOMDocument__SetValueObjectId
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocument::SetValueObjectId(class CXStr,class CXStr,unsigned __int32),CXMLSOMDocument__SetValueObjectId);
#endif
#ifdef CXMLSOMDocument__FieldParseItemOfClass
FUNCTION_AT_ADDRESS(bool  CXMLSOMDocument::FieldParseItemOfClass(class CXStr,class CXStr,unsigned __int32 &),CXMLSOMDocument__FieldParseItemOfClass);
#endif
#ifdef EQOldPlayerAnimation__mAnimationPrefix
FUNCTION_AT_ADDRESS(char (* EQOldPlayerAnimation::mAnimationPrefix)[20],EQOldPlayerAnimation__mAnimationPrefix);
#endif
#ifdef CTextOverlay__DisplayText
FUNCTION_AT_ADDRESS(void CTextOverlay::DisplayText(char *,int,int,int,int,int,int),CTextOverlay__DisplayText);
#endif
#ifdef CDBStr__GetString
// GetString(index, subindex, &success)
FUNCTION_AT_ADDRESS(char *CDBStr::GetString(int, int, int *), CDBStr__GetString);
#endif
#ifdef EQMisc__GetActiveFavorCost
FUNCTION_AT_ADDRESS(int EQMisc::GetActiveFavorCost(void),EQMisc__GetActiveFavorCost);
#endif
#ifdef CSkillMgr__GetStrNumber
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::GetStrNumber(int),CSkillMgr__GetStrNumber);
#endif
#ifdef CSkillMgr__GetSkillCap
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::GetSkillCap(class EQ_Character *,int,int,int,bool,bool,bool),CSkillMgr__GetSkillCap)
#endif
#ifdef CSkillMgr__SkillAvailableAtLevel
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::SkillAvailableAtLevel(int,int),CSkillMgr__SkillAvailableAtLevel);
#endif
#ifdef CSkillMgr__IsActivatableSkill
FUNCTION_AT_ADDRESS(bool CSkillMgr::IsActivatableSkill(int),CSkillMgr__IsActivatableSkill);
#endif
#ifdef CSkillMgr__GetBaseDamage
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::GetBaseDamage(int),CSkillMgr__GetBaseDamage);
#endif
#ifdef CSkillMgr__GetReuseTime
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::GetReuseTime(int),CSkillMgr__GetReuseTime);
#endif
#ifdef CChatService__GetNumberOfFriends
FUNCTION_AT_ADDRESS(int CChatService::GetNumberOfFriends(void),CChatService__GetNumberOfFriends);
#endif
#ifdef CChatService__GetFriendName
FUNCTION_AT_ADDRESS(char *CChatService::GetFriendName(int),CChatService__GetFriendName);
#endif
#ifdef OtherCharData__GetAltCurrency
FUNCTION_AT_ADDRESS(unsigned long OtherCharData::GetAltCurrency(unsigned long,unsigned long),OtherCharData__GetAltCurrency);
#endif

void bogus()
{
EQ_Character1 *crap = NULL;
crap->UseSkill(0, NULL);
}
