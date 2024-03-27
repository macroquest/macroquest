/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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
	{2011,   "${Target.ID}"},

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

// the tool tip is already copied out of the in class CControlTemplate. Use this struct
// to mock up the class, so we don't have to worry about class instatiation and crap

class CSidlManagerHook
{
public:
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
	DETOUR_TRAMPOLINE_DEF(CXWnd*, CreateXWnd_Trampoline, (CXWnd*, CControlTemplate*, bool bValue))
	CXWnd* CreateXWnd_Detour(CXWnd* pParent, CControlTemplate* pTemplate, bool bValue)
	{
		CXWnd* newXWnd = CreateXWnd_Trampoline(pParent, pTemplate, bValue);

		if (pTemplate->GetUltimateType() == UI_Label)
		{
			CLabel* pLabel = static_cast<CLabel*>(newXWnd);
			pLabel->EQType = GetIntFromString(pTemplate->strController, pLabel->EQType);
		}

		return newXWnd;
	}
#else
	DETOUR_TRAMPOLINE_DEF(CXWnd*, CreateXWnd_Trampoline, (CXWnd*, CControlTemplate*))
		CXWnd* CreateXWnd_Detour(CXWnd* pParent, CControlTemplate* pTemplate)
	{
		CXWnd* newXWnd = CreateXWnd_Trampoline(pParent, pTemplate);

		if (pTemplate->GetUltimateType() == UI_Label)
		{
			CLabel* pLabel = static_cast<CLabel*>(newXWnd);
			pLabel->EQType = GetIntFromString(pTemplate->strController, pLabel->EQType);
		}

		return newXWnd;
	}
#endif // IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
};

class CLabelHook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, UpdateText_Trampoline, ())
	void UpdateText_Detour()
	{
		UpdateText_Trampoline();
		CLabel* pThis = (CLabel*)this;

		if (pThis->EQType == 9999)
		{
			auto tooltip = pThis->GetXMLTooltip();
			char buffer[MAX_STRING] = { 0 };

			if (!tooltip.empty())
			{
				STMLToPlainText(tooltip.mutable_data(), buffer);

				ParseMacroParameter(buffer, MAX_STRING);
				if (strcmp(buffer, "NULL") == 0)
					buffer[0] = 0;
			}
			else
			{
				strcpy_s(buffer, "BadCustom");
			}

			pThis->SetWindowText(buffer);
			return;
		}

		if ((pThis->EQType >= 1000 && pThis->EQType <= 1015) || (pThis->EQType >= 2000 && pThis->EQType <= 2011) || (pThis->EQType >= 3000 && pThis->EQType <= 3012))
		{
			for (int index = 0; Id_PMP[index].ID > 0; index++)
			{
				if (Id_PMP[index].ID == pThis->EQType)
				{
					char buffer[MAX_STRING] = { 0 };
					strcpy_s(buffer, Id_PMP[index].PMP);

					ParseMacroParameter(buffer, MAX_STRING);
					if (strcmp(buffer, "NULL") == 0)
						buffer[0] = 0;

					pThis->SetWindowText(buffer);
					return;
				}
			}
			return;
		}
	}
};

// Called once, when the plugin is to initialize
PLUGIN_API void InitializePlugin()
{
	// Add commands, macro parameters, hooks, etc.
	EzDetour(CLabel__UpdateText, &CLabelHook::UpdateText_Detour, &CLabelHook::UpdateText_Trampoline);
	EzDetour(CSidlManager__CreateXWnd, &CSidlManagerHook::CreateXWnd_Detour, &CSidlManagerHook::CreateXWnd_Trampoline);
}

// Called once, when the plugin is to shutdown
PLUGIN_API void ShutdownPlugin()
{
	// Remove commands, macro parameters, hooks, etc.
	RemoveDetour(CSidlManager__CreateXWnd);
	RemoveDetour(CLabel__UpdateText);
}
