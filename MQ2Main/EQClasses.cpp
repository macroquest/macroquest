/*****************************************************************************
    eqlib.dll: MacroQuest's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic

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

#include "stdafx.h"
#include "MQ2Main.h"

// CEverQuest
REVERSE_DETOUR(void CEverQuest::dsp_chat(char const *,int,bool),CEverQuest__dsp_chat);
REVERSE_DETOUR(char * CEverQuest::GetClassDesc(int),CEverQuest__GetClassDesc);
REVERSE_DETOUR(class EQPlayer * CEverQuest::ClickedPlayer(int,int),CEverQuest__ClickedPlayer);
//REVERSE_DETOUR(void CEverQuest::EnterZone(struct HWND__ *),CEverQuest__EnterZone);
REVERSE_DETOUR(void CEverQuest::InterpretCmd(class EQPlayer *,char *),CEverQuest__InterpretCmd);
REVERSE_DETOUR(void CEverQuest::RightClickedOnPlayer(class EQPlayer *),CEverQuest__RightClickedOnPlayer);
REVERSE_DETOUR(void CEverQuest::LeftClickedOnPlayer(class EQPlayer *),CEverQuest__LeftClickedOnPlayer);
REVERSE_DETOUR(char * CEverQuest::GetRaceDesc(int),CEverQuest__GetRaceDesc);
REVERSE_DETOUR(char * CEverQuest::GetDeityDesc(int),CEverQuest__GetDeityDesc);
REVERSE_DETOUR(char * CEverQuest::GetBodyTypeDesc(int),CEverQuest__GetBodyTypeDesc);
//REVERSE_DETOUR(void CEverQuest::SetGameState(int),CEverQuest__SetGameState);

// CEQCharacter
REVERSE_DETOUR(int EQ_Character::Cur_HP(int),EQ_Character__Cur_HP);
REVERSE_DETOUR(int EQ_Character::Max_HP(int),EQ_Character__Max_HP);
REVERSE_DETOUR(int EQ_Character::Max_Mana(void),EQ_Character__Max_Mana);
REVERSE_DETOUR(int const EQ_Character::GetFocusCastingTimeModifier(class EQ_Spell const *,class EQ_Equipment * *),EQ_Character__GetFocusCastingTimeModifier);
REVERSE_DETOUR(int const EQ_Character::GetAACastingTimeModifier(class EQ_Spell const *),EQ_Character__GetAACastingTimeModifier);
REVERSE_DETOUR(unsigned char EQ_Character::CastSpell(unsigned char,int,class EQ_Item * *,int),EQ_Character__CastSpell);

// CXWnd
REVERSE_VIRTUAL_DETOUR(bool CXWnd::IsValid(void)const,0);
REVERSE_VIRTUAL_DETOUR(int CXWnd::Show(bool,bool),0x0C0);
REVERSE_VIRTUAL_DETOUR(int CXWnd::SetVScrollPos(int),0x0FC);
REVERSE_VIRTUAL_DETOUR(void CXWnd::SetWindowTextA(class CXStr),0x108);
// ^^ requires CXStr de/constructors

// CItemDisplayWnd
REVERSE_DETOUR(void CItemDisplayWnd::SetItem(class EQ_Item *,bool),CItemDisplayWnd__SetItem);

// CXStr
REVERSE_DETOUR(void CXStr::operator+=(char const *),[CXStr__operator_plus_equal1]);
REVERSE_DETOUR(class CXStr & CXStr::operator=(char const *),[CXStr__operator_equal1]);
REVERSE_DETOUR(CXStr::CXStr(char const *),[CXStr__CXStr3]);
REVERSE_DETOUR(CXStr::~CXStr(void),[CXStr__dCXStr]);
REVERSE_DETOUR(CXStr::CXStr(class CXStr const &),[CXStr__CXStr]);

// CChatManager
REVERSE_DETOUR(unsigned long CChatManager::GetRGBAFromIndex(int),CChatManager__GetRGBAFromIndex);
REVERSE_DETOUR(int CChatManager::InitContextMenu(class CChatWindow *),CChatManager__InitContextMenu);

// CChatWindow
REVERSE_DETOUR(CChatWindow::CChatWindow(class CXWnd *),CChatWindow__CChatWindow);
REVERSE_DETOUR(CChatWindow::~CChatWindow(void),CChatWindow__dCChatWindow);

// CStmlWnd
REVERSE_DETOUR(class CXSize CStmlWnd::AppendSTML(class CXStr),CStmlWnd__AppendSTML);

// CDisplay
REVERSE_DETOUR(void CDisplay::CleanGameUI(void),CDisplay__CleanGameUI);
REVERSE_DETOUR(struct T3D_tagACTORINSTANCE * CDisplay::GetClickedActor(unsigned long,unsigned long,bool),CDisplay__GetClickedActor);

// EQ_Item
REVERSE_DETOUR(char * EQ_Item::GetItemLinkHash(char *),EQ_Item__GetItemLinkHash); // Lax 11-14-2003

// CMerchantWnd
REVERSE_DETOUR(void CMerchantWnd::SelectBuySellSlot(int,class CTextureAnimation *),CMerchantWnd__SelectBuySellSlot);
REVERSE_DETOUR(void CMerchantWnd::RequestBuyItem(int),CMerchantWnd__RequestBuyItem);
REVERSE_DETOUR(void CMerchantWnd::RequestSellItem(int),CMerchantWnd__RequestSellItem);

// CBankWnd
REVERSE_DETOUR(int CBankWnd::GetNumBankSlots(void)const,CBankWnd__GetNumBankSlots);

// CSpellBookWnd
REVERSE_DETOUR(void CSpellBookWnd::MemorizeSet(int *,int),CSpellBookWnd__MemorizeSet);

// CLabel
REVERSE_DETOUR(int CLabel::Draw()const,CLabel__Draw);

// MapViewMap
REVERSE_DETOUR(void MapViewMap::SaveEx(char *,int),MapViewMap__SaveEx);

