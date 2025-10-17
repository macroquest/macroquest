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

#include "pch.h"
#include "emu/EmuExtensions.h"

#include "MQ2Main.h"
#include "MQPluginHandler.h"

#include "eqlib/WindowOverride.h"

#include "imgui/ImGuiUtils.h"

#if IS_EMU_CLIENT
namespace mq {

static void EmuExtensions_Initialize();
static void EmuExtensions_Shutdown();
static void EmuExtensions_Pulse();
static void EmuExtensions_UpdateImGui();
static void EmuExtensions_CleanUI();
static void EmuExtensions_ReloadUI();

static MQModule gEmuExtensionsModule = {
	"EmuExtensions",              // Name
	true,                         // CanUnload
	EmuExtensions_Initialize,     // Initialize
	EmuExtensions_Shutdown,       // Shutdown
	EmuExtensions_Pulse,          // Pulse
	nullptr,                      // SetGameState
	EmuExtensions_UpdateImGui,    // UpdateImGui
	nullptr,                      // Zoned
	nullptr,                      // WriteChatColor
	nullptr,                      // SpawnAdded
	nullptr,                      // SpawnRemoved
	nullptr,                      // BeginZone
	nullptr,                      // EndZone
	nullptr,                      // LoadPlugin
	nullptr,                      // UnloadPlugin
	EmuExtensions_CleanUI,        // CleanUI
	EmuExtensions_ReloadUI        // ReloadUI
};
MQModule* GetEmuExtensionsModule() { return &gEmuExtensionsModule; }


//--------------------------------------------------------------------------
// Emu Spell Link Support
//--------------------------------------------------------------------------

#if EMU_SPELL_LINKS_ENABLED

static bool ParsePartialSpellLink(std::string_view sv, SpellLinkInfo& linkInfo)
{
	// Repackage the data back up in a link then re-parse it (to re-use code).
	// Need to figure out how to simplify this and still have code re-use.
	char tempStr[256] = { 0 };
	sprintf_s(tempStr, "%c%c%.*s%c", ITEM_TAG_CHAR, '0' + ETAG_SPELL,
		(int)sv.length(), sv.data(), ITEM_TAG_CHAR);

	return ParseSpellLink(tempStr, linkInfo);
}

static void DispatchSpellLink(const char* linkData)
{
	SpellLinkInfo linkInfo;
	if (ParsePartialSpellLink(linkData, linkInfo))
	{
		// Check that it is a valid spell
		EQ_Spell* pSpell = GetSpellByID(linkInfo.spellID);

		if (pSpell != nullptr && pSpellDisplayManager != nullptr)
		{
			pSpellDisplayManager->ShowSpell(pSpell->ID, true, true, SpellDisplayType_SpellBookWnd);
		}
	}
}

DETOUR_TRAMPOLINE_DEF(void, ConvertItemTags_Trampoline, (CXStr&, bool));
void ConvertItemTags_Detour(CXStr& text, bool canDisplay)
{
	char* p = &text[0];

	// Fast scan for spell links.
	while (*p)
	{
		// Look ahead for item tag character that identify spell links. If it isn't
		// a spell link, we want to skip to the end of the tag and keep looking. There
		// might be multiple tags in the same string.
		if (*p == ITEM_TAG_CHAR)
		{
			if (p[1] == '6')
			{
				TextTagInfo tagInfo = ExtractLink(p);

				size_t linkLength = tagInfo.link.length();
				size_t linkPos = tagInfo.link.data() - &text[0];

				size_t pos = tagInfo.link.find("'");
				if (pos != std::string::npos)
				{
					tagInfo.link = tagInfo.link.substr(2, pos - 2);
				}

				std::string wndNotification = fmt::format("<a WndNotify=\"{},{}\">{}</a>", XWM_SPELL_LINK, tagInfo.link, tagInfo.text);

				// Replace the tag with the new notification string
				text.replace(linkPos, linkLength, wndNotification);
			}

			// Skip to the next item tag character
			++p;
			while (*p && *p != ITEM_TAG_CHAR)
			{
				++p;
			}
		}
		
		++p;
	}

	ConvertItemTags_Trampoline(text, canDisplay);
}

class CChatWindowHook : public CChatWindow
{
public:
	DETOUR_TRAMPOLINE_DEF(int, WndNotification_Trampoline, (CXWnd*, uint32_t, void*));
	int WndNotification_Detour(CXWnd* sender, uint32_t message, void* data)
	{
		if (message == XWM_SPELL_LINK)
		{
			if (sender == OutputWnd)
			{
				DispatchSpellLink(static_cast<char*>(data));
			}
			return 1;
		}

		return WndNotification_Trampoline(sender, message, data);
	}
};

class CSpellDisplayWndOverride : public WindowOverride<CSpellDisplayWndOverride, CSpellDisplayWnd>
{
public:
	static void OnHooked(CSpellDisplayWndOverride* pWnd) { pWnd->OnHooked(); }
	static void OnAboutToUnhook(CSpellDisplayWndOverride* pWnd) { pWnd->OnAboutToUnhook(); }

	virtual int WndNotification(CXWnd* sender, uint32_t message, void* data) override
	{
		DebugSpewAlways("WndNotification: %p -> %d", sender, message);
		if (sender == nullptr)
		{
			if (message == XWM_SPELL_LINK)
			{
				DispatchSpellLink(static_cast<char*>(data));
			}
		}
		else if (message == XWM_LCLICK && sender == pIcon)
		{
			EQ_Spell* pSpell = GetSpellByID(SpellID);
			CEditWnd* inputWnd = pChatManager->GetActiveChatWindow()->InputWnd;

			if (pSpell && inputWnd)
			{
				char Buffer[256] = { 0 };
				FormatSpellLink(Buffer, lengthof(Buffer), pSpell);
				
				inputWnd->ReplaceSelection(CXStr(Buffer), false);
				inputWnd->SetFocus();
			}
		}

		return Super::WndNotification(sender, message, data);
	}

private:
	void OnHooked()
	{
	}

	void OnAboutToUnhook()
	{
	}
};

#endif // EMU_SPELL_LINKS_ENABLED

//--------------------------------------------------------------------------
// Emu Constant CPU Affinity Support
//--------------------------------------------------------------------------

#if EMU_CONSTANT_AFFINITY_ENABLED

static bool s_setCpuConstantAffinity = true;
static bool s_hasSetCpuAffinity = false;

void EmuInitCpuAffinity()
{
	s_setCpuConstantAffinity = GetPrivateProfileBool("MacroQuest", "SetConstantAffinity", true, mq::internal_paths::MQini);
	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("MacroQuest", "SetConstantAffinity", s_setCpuConstantAffinity, mq::internal_paths::MQini);
	}
}

void EmuSetCpuAffinity()
{
	if (s_setCpuConstantAffinity)
	{
		SYSTEM_INFO SystemInfo;
		HANDLE processHandle = GetCurrentProcess();
		GetSystemInfo(&SystemInfo);
		int cores = SystemInfo.dwNumberOfProcessors;
		intptr_t m = 0;

		if (cores >= sizeof(DWORD_PTR) * 8)
		{
			// If we have more cores than bits in the mask, we can't set affinity.
			// This is a limitation of the API.
			m = -1;
		}
		else
		{
			m = static_cast<intptr_t>(pow(2, cores) - 1);
		}

		DebugSpewAlways("Setting processor affinity to %d (%d logical cores)", m, cores);

		if (!SetProcessAffinityMask(processHandle, static_cast<DWORD_PTR>(m)))
		{
			DebugSpewAlways("Failed to set processor affinity: %d", GetLastError());
		}
	}
}

#endif // EMU_CONSTANT_AFFINITY_ENABLED

//--------------------------------------------------------------------------
// Emu Exception Handler "Fix"
//--------------------------------------------------------------------------

#if EMU_FIX_EXCEPTION_HANDLER_ENABLED

static bool s_hasFixedExceptionHandlerChain = false;

// This a workaround for the EMU client having a global __try/__catch block wrapping
// the main game loop, which causes exceptions that we want to catch to be swallowed
// up instead of going to our unhandled exception filter.

// Structure for the exception registration record
struct EXCEPTION_REGISTRATION_RECORD {
	EXCEPTION_REGISTRATION_RECORD* Next;
	PVOID ExceptionHandler;
};

#pragma warning(push)
#pragma warning(disable: 4733)
static EXCEPTION_REGISTRATION_RECORD* GetExceptionRegistrationRecords()
{
	EXCEPTION_REGISTRATION_RECORD* result;

	__asm {
		mov eax, dword ptr fs : [0]
		mov result, eax
	}

	return result;
}

bool EmuFixExceptionHandler()
{
	EXCEPTION_REGISTRATION_RECORD* pRecord = GetExceptionRegistrationRecords();
	EXCEPTION_REGISTRATION_RECORD* pPrevRecord = nullptr;

	while (reinterpret_cast<uintptr_t>(pRecord) != 0xffffffff)
	{
		if (reinterpret_cast<uintptr_t>(pRecord->ExceptionHandler) == __ExceptionFilter)
		{
			DebugSpewAlways("Removing exception handler: 0x%p", pRecord);

			if (pPrevRecord)
			{
				pPrevRecord->Next = pRecord->Next;
			}
			else
			{
				EXCEPTION_REGISTRATION_RECORD* pNextRecord = pRecord->Next;
				__asm {
					mov eax, pNextRecord
					mov dword ptr fs:[0], eax
				}
			}
			return true;
		}

		pPrevRecord = pRecord;
		pRecord = pRecord->Next;
	}

	return false;
}

static void Command_PrintSEHChain(PlayerClient*, const char*)
{
	EXCEPTION_REGISTRATION_RECORD* pRecord = GetExceptionRegistrationRecords();

	WriteChatf("SEH Chain:");
	while (reinterpret_cast<uintptr_t>(pRecord) != 0xffffffff)
	{
		const char* color = "\ag";
		if (reinterpret_cast<uintptr_t>(pRecord->ExceptionHandler) == __ExceptionFilter)
			color = "\ar";
		WriteChatf("%s%p: Next: %p, Handler: %p", color, pRecord, pRecord->Next, pRecord->ExceptionHandler);
		pRecord = pRecord->Next;
	}
}
#pragma warning(pop)

#endif // EMU_POP_EXCEPTION_HANDLER_ENABLED

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

static void EmuExtensions_SettingsPanel()
{
#if EMU_CONSTANT_AFFINITY_ENABLED
	if (ImGui::Checkbox("Set CPU Affinity", &s_setCpuConstantAffinity))
	{
		WritePrivateProfileBool("MacroQuest", "SetConstantAffinity", s_setCpuConstantAffinity, mq::internal_paths::MQini);

		EmuSetCpuAffinity();
	}
	ImGui::SameLine();
	mq::imgui::HelpMarker("When enabled, the client will be able to use all cores (RECOMMENDED). Disabling this option will require a client restart to apply.");
#endif
}

static void EmuExtensions_Initialize()
{
#if EMU_CONSTANT_AFFINITY_ENABLED
	EmuInitCpuAffinity();
#endif

#if EMU_SPELL_LINKS_ENABLED
	EzDetour(__ConvertItemTags, &ConvertItemTags_Detour, &ConvertItemTags_Trampoline);
	EzDetour(CChatWindow__WndNotification, &CChatWindowHook::WndNotification_Detour, &CChatWindowHook::WndNotification_Trampoline);
#endif

#if EMU_FIX_EXCEPTION_HANDLER_ENABLED
	AddCommand("/printsehchain", Command_PrintSEHChain);
#endif

	AddSettingsPanel("Emu Extensions", EmuExtensions_SettingsPanel);
}

static void EmuExtensions_Shutdown()
{
#if EMU_SPELL_LINKS_ENABLED
	RemoveDetour(__ConvertItemTags);
	RemoveDetour(CChatWindow__WndNotification);
#endif

#if EMU_FIX_EXCEPTION_HANDLER_ENABLED
	RemoveCommand("/printsehchain");
#endif
}

static void EmuExtensions_Pulse()
{
#if EMU_CONSTANT_AFFINITY_ENABLED
	// Wait for first pulse to set affinity, to ensure that we always set this after EQ messes it up.
	if (!s_hasSetCpuAffinity)
	{
		EmuSetCpuAffinity();
		s_hasSetCpuAffinity = true;
	}
#endif // EMU_CONSTANT_AFFINITY_ENABLED

#if EMU_FIX_EXCEPTION_HANDLER_ENABLED
	if (gGameState >= GAMESTATE_CHARSELECT && gGameState <= GAMESTATE_INGAME)
	{
		if (!s_hasFixedExceptionHandlerChain)
		{
			EmuFixExceptionHandler();
			s_hasFixedExceptionHandlerChain = true;
		}
	}
	else if (s_hasFixedExceptionHandlerChain)
	{
		// We'll need to fix it again when we're back in game
		s_hasFixedExceptionHandlerChain = false;
	}
#endif // EMU_FIX_EXCEPTION_HANDLER_ENABLED

#if EMU_SPELL_LINKS_ENABLED
	if (gGameState == GAMESTATE_INGAME)
	{
		// Check if we're able to hook the SpellDisplayWnd yet. We only need one instance.
		// These are created dynamically so we need to wait for it to exist before we can hook it.
		if (!CSpellDisplayWndOverride::IsHooked()
			&& pSpellDisplayManager
			&& pSpellDisplayManager->GetCount() > 0)
		{
			CSpellDisplayWndOverride::InstallHooks(pSpellDisplayManager->GetWindow(0));
		}

		if (CSpellDisplayWndOverride::IsHooked()
			&& pSpellDisplayManager
			&& pSpellDisplayManager->GetCount() > 1)
		{
			// Replicate hooks to other windows
			for (int i = 1; i < pSpellDisplayManager->GetCount(); ++i)
			{
				CSpellDisplayWndOverride::InstallAdditionalHook(pSpellDisplayManager->GetWindow(i));
			}
		}
	}
#endif // EMU_SPELL_LINKS_ENABLED
}

static void EmuExtensions_UpdateImGui()
{
}

static void EmuExtensions_CleanUI()
{
#if EMU_SPELL_LINKS_ENABLED
	if (pSpellDisplayManager && pSpellDisplayManager->GetCount() > 0)
	{
		for (int i = 0; i < pSpellDisplayManager->GetCount(); ++i)
		{
			CSpellDisplayWndOverride::RestoreVFTable(pSpellDisplayManager->GetWindow(i));
		}

		CSpellDisplayWndOverride::RemoveHooks(pSpellDisplayManager->GetWindow(0));
	}
#endif // EMU_SPELL_LINKS_ENABLED
}

void EmuExtensions_ReloadUI()
{
	
}

} // namespace mq
#endif // IS_EMU_CLIENT
