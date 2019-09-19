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

 // 2.0 - May 14 2016 - Added code to allow anonymizing labels, for streaming/video recording. - eqmule
 // MQ2 Custom Labels

#include <mq/Plugin.h>

PLUGIN_VERSION(2.0);

PreSetup("MQ2Labels");

// PLEASE keep this array limited.  Recommend using 9999 and tooltips.
struct {
	int ID;
	const char* PMP;
} Id_PMP[] = {
	// 1000-1999: $char()
	{1000,   "${Me.CurrentMana}"},
	{1001,   "${Me.MaxMana}"},
	{1002,   "${Me.State}"},
	{1003,   "${Me.Speed}"},
	{1004,   "${Me.Heading}"},
	{1005,   "${Me.X}"},
	{1006,   "${Me.Y}"},
	{1007,   "${Me.Z}"},
	{1008,   "${Me.Dar}"},
	{1009,   "${Me.Cash}"},
	{1010,   "${Me.CashBank})"},
	{1011,   "${Me.PlatinumBank}"},
	{1012,   "${Me.PlatinumShared}"},
	{1013,   "${Me.GoldBank}"},
	{1014,   "${Me.SilverBank}"},
	{1015,   "${Me.CopperBank}"},

	// 2000-2999: $target()
	{2000,   "${Target.Level}"},
	{2001,   "${Target.Class}"},
	{2002,   "${Target.Race}"},
	{2003,   "${Target.Distance}"},
	{2004,   "$target(lastattacked)"},
	{2005,   "${Target.State}"},
	{2006,   "${Target.X}"},
	{2007,   "${Target.Y}"},
	{2008,   "${Target.Z}"},
	{2009,   "${Target.Heading}"},
	{2010,   "${Target.Speed}"},
	{2011,  "${Target.ID}"},

	// 3000-3999: misc
	{3000,   "${Zone}"},
	{3001,   "---"},
	{3002,   "${Me.Bound}"},
	{3003,   "${Time.Time24}"},
	{3004,   "${Time.Hour}"},
	{3005,   "${Time.Minute}"},
	{3006,   "${Time.Second}"},
	{3007,   "${Time.Date}"},
	{3008,   "${Time.Year}"},
	{3009,   "${Time.Month}"},
	{3010,   "${Time.Day}"},
	{3011,   "${If[${Spawn[gm].ID},TRUE,FALSE]}"},
	{3012,   "${Me.FreeInventory}"},

	// 9999: custom (TooltipReference)
	{9999,   "BrokenParser" },

	{-1,     nullptr}
};

// CSidlManager::CreateLabel 0x5F2470

// the tool tip is already copied out of the in class CControlTemplate. Use this struct
// to mock up the class, so we don't have to worry about class instatiation and crap
CComboWnd* Advlootcombo = nullptr;
bool gAnonMasterLooterName = true;

class CSidlManagerHook
{
public:
	CLabel* CreateLabel_Trampoline(CXWnd*, CControlTemplate*);
	CLabel* CreateLabel_Detour(CXWnd* CWin, CControlTemplate* CControl)
	{
		auto pLabel = CreateLabel_Trampoline(CWin, CControl);
		pLabel->EQType = atoi(CControl->strController.c_str());
		return pLabel;
	}
};
DETOUR_TRAMPOLINE_EMPTY(CLabel* CSidlManagerHook::CreateLabel_Trampoline(CXWnd*, CControlTemplate*));

int GetGaugeValueFromEQ_Trampoline(int, CXStr&, bool*, unsigned long*);
int GetGaugeValueFromEQ_Detour(int EQType, CXStr& out, bool* arg3, unsigned long* colorout)
{
	int ret = GetGaugeValueFromEQ_Trampoline(EQType, out, arg3, colorout);
	if (gAnonymize)
		Anonymize2(out);
	return ret;
}

int GetLabelFromEQ_Trampoline(int, CXStr&, bool*, unsigned long*);
int GetLabelFromEQ_Detour(int EQType, CXStr& out, bool* arg3, unsigned long* colorout)
{
	int ret = GetLabelFromEQ_Trampoline(EQType, out, arg3, colorout);
	if (gAnonymize)
		Anonymize2(out);
	return ret;
}

bool bTrimnames = false;

// Anonymized -> Normal
std::map<CXStr, CXStr> lootcombo;

bool gweareaddingpeople = false;

// CLabelHook::Draw_Detour
void CleanupLootCombo(bool bupdatemasterlooter);
class CLabelHook
{
public:
	int CListWnd__AddString_Trampoline(const CXStr& Str, COLORREF Color, uint64_t Data, const CTextureAnimation* pTa, const char* TooltipStr);
	int CListWnd__AddString_Detour(const CXStr& Str, COLORREF Color, uint64_t Data, const CTextureAnimation* pTa, const char* TooltipStr)
	{
		if (gAnonymize)
		{
			CXStr anonymized = Str;
			Anonymize2(anonymized, true);
			return CListWnd__AddString_Trampoline(anonymized, Color, Data, pTa, TooltipStr);
		}
		return CListWnd__AddString_Trampoline(Str, Color, Data, pTa, TooltipStr);
	}

	void CAdvancedLootWnd__UpdateMasterLooter_Trampoline(const CXStr& Name, bool bChanged);
	void CAdvancedLootWnd__UpdateMasterLooter_Detour(const CXStr& Name, bool bChanged)
	{
		CAdvancedLootWnd__UpdateMasterLooter_Trampoline(Name, bChanged);
		if (gAnonymize && gAnonMasterLooterName)
		{
			UpdatedMasterLooterLabel();
		}
	}

	CXStr CComboWnd__GetChoiceText_Trampoline(int index) const;
	CXStr CComboWnd__GetChoiceText_Detour(int index) const
	{
		CXStr ret = CComboWnd__GetChoiceText_Trampoline(index);
		if (gAnonymize && lootcombo.find(ret) != lootcombo.end())
			ret = lootcombo[ret];
		return ret;
	}

	void CListWnd__SetItemText_Trampoline(int ID, int SubItem, const CXStr& Str);
	void CListWnd__SetItemText_Detour(int ID, int SubItem, const CXStr& Str)
	{
		CListWnd__SetItemText_Trampoline(ID, SubItem, Str);
	}

	int CComboWnd__InsertChoiceAtIndex_Trampoline(const CXStr& Str, uint32_t index);
	int CComboWnd__InsertChoiceAtIndex_Detour(const CXStr& Str, uint32_t index)
	{
		if (gAnonymize && gweareaddingpeople) {
			Advlootcombo = (CComboWnd*)this;

			// If we've already anonymized this string, use the cached version
			for (const auto& [key, val] : lootcombo)
				if (val == Str)
					return CComboWnd__InsertChoiceAtIndex_Trampoline(key, index);

			// Otherwise, anonymize & cache it
			CXStr anonymized = Str;
			Anonymize2(anonymized, true);
			lootcombo[anonymized] = Str;

			return CComboWnd__InsertChoiceAtIndex_Trampoline(anonymized, index);
		}
		return CComboWnd__InsertChoiceAtIndex_Trampoline(Str, index);
	}

	void CAdvancedLootWnd__AddPlayerToList_Trampoline(CGroupMemberBase*);
	void CAdvancedLootWnd__AddPlayerToList_Detour(CGroupMemberBase* base)
	{
		gweareaddingpeople = true;
		CAdvancedLootWnd__AddPlayerToList_Trampoline(base);
		gweareaddingpeople = false;
	}

	int CComboWnd__InsertChoice_Trampoline(const CXStr& Str, uint32_t index);
	int CComboWnd__InsertChoice_Detour(const CXStr& Str, uint32_t index)
	{
		return CComboWnd__InsertChoice_Trampoline(Str, index);
	}

	char* CEverQuest__trimName_Trampoline(char*);
	char* CEverQuest__trimName_Detour(char* arg1)
	{
		char* ret = CEverQuest__trimName_Trampoline(arg1);
		if (gAnonymize) {
			Anonymize(ret, strlen(ret));
		}
		return ret;
	}

	void Draw_Trampoline();
	void Draw_Detour()
	{
		CLabel* pThisLabel = (CLabel*)this;
		bool Found = false;
		DWORD index;

		CXStr buffer;

		if (gAnonymize)
		{
			if (!bTrimnames)
			{
				EzDetourwName(CAdvancedLootWnd__UpdateMasterLooter, &CLabelHook::CAdvancedLootWnd__UpdateMasterLooter_Detour, &CLabelHook::CAdvancedLootWnd__UpdateMasterLooter_Trampoline, "CAdvancedLootWnd__UpdateMasterLooter");
				EzDetourwName(CComboWnd__GetChoiceText, &CLabelHook::CComboWnd__GetChoiceText_Detour, &CLabelHook::CComboWnd__GetChoiceText_Trampoline, "CComboWnd__GetChoiceText");
				EzDetourwName(CComboWnd__InsertChoiceAtIndex, &CLabelHook::CComboWnd__InsertChoiceAtIndex_Detour, &CLabelHook::CComboWnd__InsertChoiceAtIndex_Trampoline, "CComboWnd__InsertChoiceAtIndex");
				EzDetourwName(CAdvancedLootWnd__AddPlayerToList, &CLabelHook::CAdvancedLootWnd__AddPlayerToList_Detour, &CLabelHook::CAdvancedLootWnd__AddPlayerToList_Trampoline, "CAdvancedLootWnd__AddPlayerToList");
				if (pAdvancedLootWnd && GetGameState() == GAMESTATE_INGAME)
				{
					CleanupLootCombo(true);
				}

				EzDetourwName(CListWnd__AddString, &CLabelHook::CListWnd__AddString_Detour, &CLabelHook::CListWnd__AddString_Trampoline, "CListWnd__AddString");
				EzDetourwName(CEverQuest__trimName, &CLabelHook::CEverQuest__trimName_Detour, &CLabelHook::CEverQuest__trimName_Trampoline, "CEverQuest__trimName");
				EzDetourwName(__GetGaugeValueFromEQ, GetGaugeValueFromEQ_Detour, GetGaugeValueFromEQ_Trampoline, "__GetGaugeValueFromEQ");
				EzDetourwName(__GetLabelFromEQ, GetLabelFromEQ_Detour, GetLabelFromEQ_Trampoline, "__GetLabelFromEQ");
				bTrimnames = 1;
			}

			if (pThisLabel)
			{
				buffer = pThisLabel->GetWindowText();
				Anonymize2(buffer);
			}
		}
		else
		{
			if (bTrimnames)
			{
				bTrimnames = false;
				RemoveDetour(CComboWnd__GetChoiceText);
				RemoveDetour(CComboWnd__InsertChoiceAtIndex);
				RemoveDetour(CAdvancedLootWnd__AddPlayerToList);
				RemoveDetour(CListWnd__AddString);
				RemoveDetour(CEverQuest__trimName);
				RemoveDetour(__GetGaugeValueFromEQ);
				RemoveDetour(__GetLabelFromEQ);
				CleanupLootCombo(false);
				RemoveDetour(CAdvancedLootWnd__UpdateMasterLooter);
			}
		}

		Draw_Trampoline();
	
		if (pThisLabel->EQType == 9999)
		{
			auto tooltip = pThisLabel->GetXMLTooltip();

			if (!tooltip.empty())
			{
				buffer.reserve(tooltip.length());
				STMLToPlainText(tooltip.mutable_data(), buffer.mutable_data());

				buffer.reserve(MAX_STRING);
				ParseMacroParameter(((CHARINFO*)pCharData)->pSpawn, buffer.mutable_data(), MAX_STRING);
				if (buffer == "NULL")
					buffer = "";
				Found = true;
			}
			else
			{
				buffer = "BadCustom";
				Found = true;
			}
		}
		else if (pThisLabel->EQType == 1000)
		{
			for (index = 0; Id_PMP[index].ID > 0 && !Found; index++)
			{
				if (Id_PMP[index].ID == pThisLabel->EQType)
				{
					buffer = Id_PMP[index].PMP;
					buffer.reserve(MAX_STRING);

					ParseMacroParameter(((CHARINFO*)pCharData)->pSpawn, buffer.mutable_data(), MAX_STRING);
					if (buffer == "NULL")
						buffer = "";
					Found = true;
				}
			}
		}
		if (Found)
			pThisLabel->SetWindowText(buffer);
	}
};

DETOUR_TRAMPOLINE_EMPTY(int CLabelHook::CListWnd__AddString_Trampoline(const CXStr& Str, COLORREF Color, uint64_t Data, const CTextureAnimation* pTa, const char* TooltipStr));
DETOUR_TRAMPOLINE_EMPTY(void CLabelHook::CAdvancedLootWnd__UpdateMasterLooter_Trampoline(const CXStr& Name, bool bChanged));
DETOUR_TRAMPOLINE_EMPTY(CXStr CLabelHook::CComboWnd__GetChoiceText_Trampoline(int index) const);
DETOUR_TRAMPOLINE_EMPTY(void CLabelHook::CListWnd__SetItemText_Trampoline(int ID, int SubItem, const CXStr& Str));
DETOUR_TRAMPOLINE_EMPTY(int CLabelHook::CComboWnd__InsertChoiceAtIndex_Trampoline(const CXStr& Str, uint32_t index));
DETOUR_TRAMPOLINE_EMPTY(void CLabelHook::CAdvancedLootWnd__AddPlayerToList_Trampoline(CGroupMemberBase*));
DETOUR_TRAMPOLINE_EMPTY(int CLabelHook::CComboWnd__InsertChoice_Trampoline(const CXStr& Str, uint32_t Data));
DETOUR_TRAMPOLINE_EMPTY(void CLabelHook::Draw_Trampoline());
DETOUR_TRAMPOLINE_EMPTY(char* CLabelHook::CEverQuest__trimName_Trampoline(char*));
DETOUR_TRAMPOLINE_EMPTY(int GetGaugeValueFromEQ_Trampoline(int, CXStr&, bool*, unsigned long*));
DETOUR_TRAMPOLINE_EMPTY(int GetLabelFromEQ_Trampoline(int, CXStr&, bool*, unsigned long*));

bool StealNextGauge = false;
DWORD NextGauge = 0;

// Called once, when the plugin is to initialize
PLUGIN_API void InitializePlugin()
{
	// Add commands, macro parameters, hooks, etc.
	EzDetourwName(CLabel__Draw, &CLabelHook::Draw_Detour, &CLabelHook::Draw_Trampoline, "CLabel__Draw");
	EzDetourwName(CSidlManagerBase__CreateLabel, &CSidlManagerHook::CreateLabel_Detour, &CSidlManagerHook::CreateLabel_Trampoline, "CSidlManager__CreateLabel");

	if (gAnonymize)
	{
		// advloot anonymizing
		EzDetourwName(CAdvancedLootWnd__UpdateMasterLooter, &CLabelHook::CAdvancedLootWnd__UpdateMasterLooter_Detour, &CLabelHook::CAdvancedLootWnd__UpdateMasterLooter_Trampoline, "CAdvancedLootWnd__UpdateMasterLooter");
		EzDetourwName(CComboWnd__GetChoiceText, &CLabelHook::CComboWnd__GetChoiceText_Detour, &CLabelHook::CComboWnd__GetChoiceText_Trampoline, "CComboWnd__GetChoiceText");
		EzDetourwName(CComboWnd__InsertChoiceAtIndex, &CLabelHook::CComboWnd__InsertChoiceAtIndex_Detour, &CLabelHook::CComboWnd__InsertChoiceAtIndex_Trampoline, "CComboWnd__InsertChoiceAtIndex");
		EzDetourwName(CAdvancedLootWnd__AddPlayerToList, &CLabelHook::CAdvancedLootWnd__AddPlayerToList_Detour, &CLabelHook::CAdvancedLootWnd__AddPlayerToList_Trampoline, "CAdvancedLootWnd__AddPlayerToList");
		if (pAdvancedLootWnd && GetGameState() == GAMESTATE_INGAME)
		{
			CleanupLootCombo(true);
		}

		EzDetourwName(CListWnd__AddString, &CLabelHook::CListWnd__AddString_Detour, &CLabelHook::CListWnd__AddString_Trampoline, "CListWnd__AddString");
		EzDetourwName(CEverQuest__trimName, &CLabelHook::CEverQuest__trimName_Detour, &CLabelHook::CEverQuest__trimName_Trampoline, "CEverQuest__trimName");
		EzDetourwName(__GetGaugeValueFromEQ, GetGaugeValueFromEQ_Detour, GetGaugeValueFromEQ_Trampoline, "__GetGaugeValueFromEQ");
		EzDetourwName(__GetLabelFromEQ, GetLabelFromEQ_Detour, GetLabelFromEQ_Trampoline, "__GetLabelFromEQ");
		bTrimnames = 1;
	}
}

void CleanupLootCombo(bool bupdatemasterlooter)
{
	if (CHARINFO* pChar = GetCharInfo())
	{
		if (pChar->pGroupInfo)
		{
			for (int i = 0; i < 6; i++)
			{
				if (pChar->pGroupInfo->pMember && pChar->pGroupInfo->pMember[i] && pChar->pGroupInfo->pMember[i]->MasterLooter)
				{
					gAnonMasterLooterName = bupdatemasterlooter;
					((CLabelHook*)pAdvancedLootWnd)->CAdvancedLootWnd__UpdateMasterLooter_Detour(pChar->pGroupInfo->pMember[i]->Name, true);
					gAnonMasterLooterName = true;
					break;
				}
			}
		}
	}
}

// Called once, when the plugin is to shutdown
PLUGIN_API void ShutdownPlugin()
{
	// Remove commands, macro parameters, hooks, etc.
	if (bTrimnames)
	{
		bTrimnames = false;
		RemoveDetour(CComboWnd__GetChoiceText);
		RemoveDetour(CComboWnd__InsertChoiceAtIndex);
		RemoveDetour(CAdvancedLootWnd__AddPlayerToList);
		RemoveDetour(CListWnd__AddString);
		RemoveDetour(CEverQuest__trimName);
		RemoveDetour(__GetGaugeValueFromEQ);
		RemoveDetour(__GetLabelFromEQ);
		CleanupLootCombo(false);
		RemoveDetour(CAdvancedLootWnd__UpdateMasterLooter);
	}

	RemoveDetour(CSidlManagerBase__CreateLabel);
	RemoveDetour(CLabel__Draw);
}

PLUGIN_API void OnCleanUI()
{
	if (Advlootcombo)
	{
		Advlootcombo = 0;
		lootcombo.clear();
	}
}
