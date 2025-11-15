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
#include "MQ2Main.h"

#include "MQ2KeyBinds.h"

#include "MQ2DeveloperTools.h"
#include "fmt/format.h"
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"

namespace mq {

using KeybindMap = std::map<std::string, int, ci_less>;

KeybindMap gKeybindMap;
std::vector<std::unique_ptr<MQKeyBind>> gKeyBinds;

void EnumerateKeyBinds(const std::function<void(const MQKeyBind& keyBind)>& func)
{
	for (const auto& [name, id] : gKeybindMap)
	{
		if (id >= 0 && id < static_cast<int>(gKeyBinds.size()))
		{
			auto& keyBind = gKeyBinds[id];
			func(*keyBind);
		}
	}
}

int GetKeyBindsCount()
{
	return static_cast<int>(gKeybindMap.size());
}

static MQKeyBind* KeyBindByName(const char* name)
{
	auto iter = gKeybindMap.find(name);
	if (iter == std::end(gKeybindMap))
		return nullptr;

	return gKeyBinds[iter->second].get();
}

static bool SetEQKeyBindByNumber(int index, bool alternate, KeyCombo& combo)
{
	if (index < nEQMappableCommands)
	{
		if (alternate)
			pKeypressHandler->AltKey[index] = combo;
		else
			pKeypressHandler->NormalKey[index] = combo;

		if (index < nNormalEQMappableCommands)
			pKeypressHandler->SaveKeymapping(index, combo, alternate);

		return true;
	}

	return false;
}

bool SetEQKeyBind(const char* name, bool alternate, KeyCombo& combo)
{
	int num = FindMappableCommand(name);
	if (num >= 0)
		return SetEQKeyBindByNumber(num, alternate, combo);

	return false;
}

bool MQ2HandleKeyDown(const KeyCombo& combo)
{
	bool Ret = false;

	for (int index = 0; index < nEQMappableCommands; index++)
	{
		if (pKeypressHandler->CommandState[index] == 0
			&& (pKeypressHandler->NormalKey[index] == combo || pKeypressHandler->AltKey[index] == combo))
		{
			ExecuteCmd(index, true, nullptr,  &combo);

			pKeypressHandler->CommandState[index] = 1;
			Ret = true;
		}
	}

	for (auto& pKeybind : gKeyBinds)
	{
		if (pKeybind
			&& pKeybind->State == 0
			&& (pKeybind->Normal == combo || pKeybind->Alt == combo))
		{
			pKeybind->Function(pKeybind->Name.c_str(), true);
			pKeybind->State = true;

			Ret = true;
		}
	}

	return Ret;
}

bool MQ2HandleKeyUp(const KeyCombo& combo)
{
	bool Ret = false;

	for (int index = 0; index < nEQMappableCommands; index++)
	{
		if (pKeypressHandler->CommandState[index]
			&& (pKeypressHandler->NormalKey[index].Data[3] == combo.Data[3] || pKeypressHandler->AltKey[index].Data[3] == combo.Data[3]))
		{
			ExecuteCmd(index, false);

			pKeypressHandler->CommandState[index] = 0;
			Ret = true;
		}
	}

	for (auto& pKeybind : gKeyBinds)
	{
		if (pKeybind
			&& pKeybind->State == 1
			&& (pKeybind->Normal.Data[3] == combo.Data[3] || pKeybind->Alt.Data[3] == combo.Data[3]))
		{
			pKeybind->Function(pKeybind->Name.c_str(), false);
			pKeybind->State = false;

			Ret = true;
		}
	}

	return Ret;
}

class KeypressHandlerHook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, ClearCommandStateArray_Trampoline, ())
	void ClearCommandStateArray_Hook()
	{
		for (auto& pKeybind : gKeyBinds)
		{
			if (pKeybind)
			{
				pKeybind->State = false;
			}
		}

		ZeroMemory(&pKeypressHandler->CommandState[0], sizeof(pKeypressHandler->CommandState));
	}

	DETOUR_TRAMPOLINE_DEF(bool, HandleKeyDown_Trampoline, (const KeyCombo&))
	bool HandleKeyDown_Hook(const KeyCombo& combo)
	{
		if (!pWndMgr->HandleKeyboardMsg(combo.Data[3], true))
			return true;

		return (MQ2HandleKeyDown(combo) != 0);
	}

	DETOUR_TRAMPOLINE_DEF(bool, HandleKeyUp_Trampoline, (const KeyCombo&))
	bool HandleKeyUp_Hook(const KeyCombo& combo)
	{
		bool ret = false;
		if (!pWndMgr->HandleKeyboardMsg(combo.Data[3], false))
			ret = true;

		return MQ2HandleKeyUp(combo) || ret;
	}
};

bool AddMQ2KeyBind(const char* name, fMQExecuteCmd function)
{
	DebugSpew("AddMQ2KeyBind(%s)", name);

	if (KeyBindByName(name))
	{
		DebugSpew("AddMQ2KeyBind(%s) - Name already in use", name);
		return false;
	}

	auto pKeybind = std::make_unique<MQKeyBind>(name, function);

	std::string primarySettingName = fmt::format("{}_Nrm", pKeybind->Name);
	std::string primaryBind = GetPrivateProfileString("Key Binds", primarySettingName, "clear", mq::internal_paths::MQini);

	std::string altSettingName = fmt::format("{}_Alt", pKeybind->Name);
	std::string altBind = GetPrivateProfileString("Key Binds", altSettingName, "clear", mq::internal_paths::MQini);

	ParseKeyCombo(primaryBind.c_str(), pKeybind->Normal);
	ParseKeyCombo(altBind.c_str(), pKeybind->Alt);

	// Find an unused index.
	int index = -1;
	for (int i = 0; i < (int)gKeyBinds.size(); ++i)
	{
		if (gKeyBinds[i] == nullptr)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		gKeyBinds.emplace_back();
		index = static_cast<int>(gKeyBinds.size()) - 1;
	}

	pKeybind->Id = index;
	gKeyBinds[index] = std::move(pKeybind);
	gKeybindMap.insert_or_assign(name, index);

	return true;
}

bool GetMQ2KeyBind(const char* name, bool alt, KeyCombo& combo)
{
	if (MQKeyBind* pKeybind = KeyBindByName(name))
	{
		combo = alt ? pKeybind->Alt : pKeybind->Normal;
		return true;
	}
	return false;
}

bool RemoveMQ2KeyBind(const char* name)
{
	DebugSpew("RemoveMQ2KeyBind(%s)", name);

	auto iter = gKeybindMap.find(name);
	if (iter == std::end(gKeybindMap))
		return false;

	gKeyBinds[iter->second].reset();
	gKeybindMap.erase(iter);

	return true;
}

bool PressMQ2KeyBind(const char* name, bool hold)
{
	if (MQKeyBind* pKeybind = KeyBindByName(name))
	{
		pKeybind->Function(pKeybind->Name.c_str(), true);

		// release the keypress if we aren't asked to hold it.
		if (!hold)
		{
			pKeybind->Function(pKeybind->Name.c_str(), false);
		}

		return true;
	}

	return false;
}

bool SetMQ2KeyBind(const char* name, bool alternate, KeyCombo& combo)
{
	if (MQKeyBind* pKeybind = KeyBindByName(name))
	{
		std::string settingName;

		if (!alternate)
		{
			settingName = fmt::format("{}_Nrm", pKeybind->Name);
			pKeybind->Normal = combo;
		}
		else
		{
			settingName = fmt::format("{}_Alt", pKeybind->Name);
			pKeybind->Alt = combo;
		}

		char szBuffer[MAX_STRING] = { 0 };

		WritePrivateProfileString("Key Binds", settingName,
			DescribeKeyCombo(combo, szBuffer, sizeof(szBuffer)), mq::internal_paths::MQini);
		return true;
	}

	return false;
}

int FindMappableCommand(const char* name)
{
	for (int i = 0; i < nEQMappableCommands; i++)
	{
		if (szEQMappableCommands[i] == nullptr || szEQMappableCommands[i] > reinterpret_cast<const char*>(g_eqgameimagesize))
			continue;

		if (!_stricmp(name, szEQMappableCommands[i]))
			return i;
	}

	return -1;
}

void MQ2KeyBindCommand(PlayerClient* pChar, const char* szLine)
{
	if (szLine[0] == 0)
	{
		WriteChatColor("Usage: /bind <list|eqlist|[~]name <combo|clear>>");
		return;
	}

	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	const char* szRest = GetNextArg(szLine);
	char* szArg = &szArg1[0];

	bool altKey = false;

	if (szArg[0] == '~')
	{
		altKey = true;
		szArg = &szArg1[1];
	}

	if (!_stricmp(szArg, "list"))
	{
		// list binds
		char szNormal[MAX_STRING] = { 0 };
		char szAlt[MAX_STRING] = { 0 };
		WriteChatColor("MQ2 Binds");
		WriteChatColor("--------------");

		for (auto& pKeybind : gKeyBinds)
		{
			if (pKeybind)
			{
				WriteChatf("[\ay%s\ax] Nrm:\at%s\ax Alt:\at%s\ax",
					pKeybind->Name.c_str(), DescribeKeyCombo(pKeybind->Normal, szNormal, sizeof(szNormal)),
					DescribeKeyCombo(pKeybind->Alt, szAlt, sizeof(szAlt)));
			}
		}

		WriteChatColor("--------------");
		WriteChatColor("End MQ2 Binds");
		return;
	}

	if (!_stricmp(szArg, "eqlist"))
	{
		char szNormal[MAX_STRING] = { 0 };
		char szAlt[MAX_STRING] = { 0 };

		// list eq binds
		WriteChatColor("EQ Binds");
		WriteChatColor("--------------");

		for (int i = 0; i < nEQMappableCommands; i++)
		{
			if (szEQMappableCommands[i] == nullptr)
				continue;

			WriteChatf("[\ay%s\ax] Nrm:\at%s\ax Alt:\at%s\ax", szEQMappableCommands[i],
				DescribeKeyCombo(pKeypressHandler->NormalKey[i], szNormal, sizeof(szNormal)),
				DescribeKeyCombo(pKeypressHandler->AltKey[i], szAlt, sizeof(szAlt)));
		}

		WriteChatColor("--------------");
		WriteChatColor("End EQ Binds");
		return;
	}

	KeyCombo newCombo;

	if (!ParseKeyCombo(szRest, newCombo))
	{
		WriteChatColor("Invalid key combination");
		return;
	}

	if (!_stricmp(szArg, "clearcombo"))
	{
		KeyCombo ClearCombo;

		// mq2 binds
		for (auto& pKeybind : gKeyBinds)
		{
			if (pKeybind)
			{
				if (pKeybind->Alt == newCombo && SetMQ2KeyBind(pKeybind->Name.c_str(), true, ClearCombo))
				{
					WriteChatf("Alternate %s cleared", pKeybind->Name.c_str());
				}

				if (pKeybind->Normal == newCombo && SetMQ2KeyBind(pKeybind->Name.c_str(), false, ClearCombo))
				{
					WriteChatf("Normal %s cleared", pKeybind->Name.c_str());
				}
			}
		}

		// eq binds
		for (int i = 0; i < nEQMappableCommands; i++)
		{
			if (szEQMappableCommands[i] == nullptr || szEQMappableCommands[i] > reinterpret_cast<const char*>(g_eqgameimagesize))
				continue;

			if (pKeypressHandler->AltKey[i] == newCombo && SetEQKeyBindByNumber(i, true, ClearCombo))
			{
				WriteChatf( "Alternate %s cleared", szEQMappableCommands[i]);
			}
			if (pKeypressHandler->NormalKey[i] == newCombo && SetEQKeyBindByNumber(i, false, ClearCombo))
			{
				WriteChatf("Normal %s cleared", szEQMappableCommands[i]);
			}
		}

		return;
	}

	char szBuffer[MAX_STRING] = { 0 };
	if (SetMQ2KeyBind(szArg, altKey, newCombo))
	{
		MQKeyBind* pKeybind = KeyBindByName(szArg);

		WriteChatf("%s %s now bound as %s",
			altKey ? "Alternate" : "Normal",
			pKeybind->Name.c_str(),
			DescribeKeyCombo(newCombo, szBuffer, sizeof(szBuffer)));
		return;
	}

	int index = FindMappableCommand(szArg);
	if (index < 0)
	{
		WriteChatColor("Unknown bind command name");
		return;
	}

	if (index > nNormalEQMappableCommands)
	{
		WriteChatColor("Unmappable bind command name");
		return;
	}

	if (SetEQKeyBindByNumber(index, altKey, newCombo))
	{
		WriteChatf("%s %s now bound as %s",
			altKey ? "Alternate" : "Normal",
			szEQMappableCommands[index],
			DescribeKeyCombo(altKey ? pKeypressHandler->AltKey[index] : pKeypressHandler->NormalKey[index], szBuffer, sizeof(szBuffer)));
	}
}

static void DoRangedBind(const char* Name, bool Down)
{
	if (Down)
	{
		AttackRanged(pTarget);
	}
}

bool DumpBinds(const char* Filename)
{
	std::filesystem::path pathFilename = Filename;
	if (!strchr(Filename, '.'))
		pathFilename = std::string(Filename) + ".cfg";

	if (pathFilename.is_relative())
	{
		pathFilename = mq::internal_paths::Config / pathFilename;
	}

	FILE* file = _fsopen(pathFilename.string().c_str(), "wt", _SH_DENYWR);
	if (file == nullptr)
	{
		return false;
	}

	char szBuffer[MAX_STRING] = { 0 };

	for (int index = 0; index < nEQMappableCommands; index++)
	{
		if (szEQMappableCommands[index] == nullptr || szEQMappableCommands[index] > reinterpret_cast<const char*>(g_eqgameimagesize))
			continue;

		fprintf(file, "/bind %s %s\n", szEQMappableCommands[index],
			DescribeKeyCombo(pKeypressHandler->NormalKey[index], szBuffer, sizeof(szBuffer)));
		fprintf(file, "/bind ~%s %s\n", szEQMappableCommands[index],
			DescribeKeyCombo(pKeypressHandler->AltKey[index], szBuffer, sizeof(szBuffer)));
	}

	for (auto& pKeybind : gKeyBinds)
	{
		if (pKeybind)
		{
			fprintf(file, "/bind %s %s\n", pKeybind->Name.c_str(),
				DescribeKeyCombo(pKeybind->Normal, szBuffer, sizeof(szBuffer)));
			fprintf(file, "/bind ~%s %s\n", pKeybind->Name.c_str(),
				DescribeKeyCombo(pKeybind->Alt, szBuffer, sizeof(szBuffer)));
		}
	}

	fclose(file);
	return true;
}

//============================================================================
// KeyBinds Settings
//============================================================================

static ImVec4 GetKeyBindColor(bool empty, bool hovered)
{
	if (hovered)
		return ImVec4(1.0f, 1.0f, 0.0f, 1.0f);
	if (empty)
		return ImVec4(1.0f, 1.0f, 1.0f, 0.5f);

	return ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
}

static bool sEditKeyBind = false;
static std::string sEditKeyBindName;
static bool sEditKeyBindAlt = false;
static bool sEditKeyBindEQ = false;
static char sEditKeyCombo[64];

void DoEditKeyCombo(const std::string& name, const std::string& keyCombo, bool alt, bool eq)
{
	sEditKeyBindName = name;
	sEditKeyBindAlt = alt;
	sEditKeyBindEQ = eq;
	strcpy_s(sEditKeyCombo, keyCombo.c_str());

	ImGui::OpenPopup("Edit Key Binding");
}

int DoEditKeyComboTextEditCallback(ImGuiInputTextCallbackData* data)
{
	return 1;
}

void DoEditKeyComboPopup()
{
	bool unused_open = true;
	if (ImGui::BeginPopupModal("Edit Key Binding", &unused_open))
	{
		ImGui::Text("Editing %s key binding for \"%s\"",
			sEditKeyBindAlt ? "alt" : "normal", sEditKeyBindName.c_str());

		ImGui::InputText("", sEditKeyCombo, sizeof(sEditKeyCombo), 0, DoEditKeyComboTextEditCallback);

		eqlib::KeyCombo keyCombo;
		bool valid = ParseKeyCombo(sEditKeyCombo, keyCombo);

		if (!valid)
		{
			ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
			ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.5f);
		}

		if (ImGui::Button("Save", ImVec2(80, 0)))
		{
			if (sEditKeyBindEQ)
				SetEQKeyBind(sEditKeyBindName.c_str(), sEditKeyBindAlt, keyCombo);
			else
				SetMQ2KeyBind(sEditKeyBindName.c_str(), sEditKeyBindAlt, keyCombo);

			ImGui::CloseCurrentPopup();
		}

		if (!valid)
		{
			ImGui::PopItemFlag();
			ImGui::PopStyleVar();
		}

		ImGui::SameLine();
		if (ImGui::Button("Cancel", ImVec2(80, 0)))
		{
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
}

void DoKeybindSettings()
{
	ImGui::Text("Clicking a binding will allow you to change it.");

	std::string clickedName;
	bool clickedAlt = false;
	bool clickedEQ = false;
	std::string clickedCombo;
	bool clicked = false;

	if (ImGui::BeginTabBar("Keybinds"))
	{
		char label[64];
		sprintf_s(label, "MacroQuest Key Bindings (%d)###MQKeyBindings", GetKeyBindsCount());

		if (ImGui::BeginTabItem(label))
		{
			static int sHoveredIndex = -1;
			static bool sHoveredAlt = false;
			bool isAnyHovered = false;

			if (ImGui::BeginTable("##MQKeybindTable", 3, ImGuiTableFlags_Resizable | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_ScrollY))
			{
				ImGui::TableSetupScrollFreeze(0, 1);
				ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch);
				ImGui::TableSetupColumn("Bind", ImGuiTableColumnFlags_WidthFixed);
				ImGui::TableSetupColumn("Alt", ImGuiTableColumnFlags_WidthFixed);
				ImGui::TableSetupScrollFreeze(0, 1);
				ImGui::TableHeadersRow();

				bool hovered = false;

				EnumerateKeyBinds(
					[&](const mq::MQKeyBind& keyBind)
					{
						char keyComboDesc[64];

						ImGui::TableNextRow();

						ImGui::TableNextColumn();
						ImGui::Text(keyBind.Name.c_str());

						ImGui::TableNextColumn();

						DescribeKeyCombo(keyBind.Normal, keyComboDesc, sizeof(keyComboDesc));
						hovered = (sHoveredIndex == keyBind.Id && sHoveredAlt == false);
						ImGui::TextColored(GetKeyBindColor(ci_equals("clear", keyComboDesc), hovered), "%s", keyComboDesc);
						if (ImGui::IsItemHovered()) { sHoveredAlt = false; sHoveredIndex = keyBind.Id; isAnyHovered = true; }
						if (ImGui::IsItemClicked()) { clickedName = keyBind.Name; clickedAlt = false; clickedEQ = false; clickedCombo = keyComboDesc; clicked = true; }

						ImGui::TableNextColumn();
						DescribeKeyCombo(keyBind.Alt, keyComboDesc, sizeof(keyComboDesc));
						hovered = (sHoveredIndex == keyBind.Id && sHoveredAlt == true);
						ImGui::TextColored(GetKeyBindColor(ci_equals("clear", keyComboDesc), hovered), "%s", keyComboDesc);
						if (ImGui::IsItemHovered()) { sHoveredAlt = true; sHoveredIndex = keyBind.Id; isAnyHovered = true; }
						if (ImGui::IsItemClicked()) { clickedName = keyBind.Name; clickedAlt = true; clickedEQ = false; clickedCombo = keyComboDesc; clicked = true; }
					});

				ImGui::EndTable();
			}

			if (!isAnyHovered)
			{
				sHoveredIndex = -1;
				sHoveredAlt = false;
			}

			ImGui::EndTabItem();
		}

		// Count the keybinds.
		int eqCount = 0;
		for (auto& szEQMappableCommand : szEQMappableCommands)
		{
			if (szEQMappableCommand == nullptr)
				continue;

			eqCount++;
		}
		sprintf_s(label, "EverQuest Key Bindings (%d)###EQKeyBindings", eqCount);

		if (ImGui::BeginTabItem(label))
		{
			static int sHoveredIndex = -1;
			static bool sHoveredAlt = false;
			bool isAnyHovered = false;

			if (ImGui::BeginTable("##EQKeybindTable", 3, ImGuiTableFlags_Resizable | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_ScrollY))
			{
				ImGui::TableSetupScrollFreeze(0, 1);
				ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch);
				ImGui::TableSetupColumn("Bind", ImGuiTableColumnFlags_WidthFixed);
				ImGui::TableSetupColumn("Alt", ImGuiTableColumnFlags_WidthFixed);
				ImGui::TableSetupScrollFreeze(0, 1);
				ImGui::TableHeadersRow();

				bool hovered = false;

				for (int i = 0; i < nEQMappableCommands; ++i)
				{
					if (szEQMappableCommands[i] == nullptr)
						continue;

					char keyComboDesc[64];

					ImGui::TableNextRow();

					ImGui::TableNextColumn();
					ImGui::Text(szEQMappableCommands[i]);

					ImGui::TableNextColumn();

					DescribeKeyCombo(pKeypressHandler->NormalKey[i], keyComboDesc, sizeof(keyComboDesc));
					hovered = (sHoveredIndex == i && sHoveredAlt == false);
					ImGui::TextColored(GetKeyBindColor(ci_equals("clear", keyComboDesc), hovered), "%s", keyComboDesc);
					if (ImGui::IsItemHovered()) { sHoveredAlt = false; sHoveredIndex = i; isAnyHovered = true; }
					if (ImGui::IsItemClicked()) { clickedName = szEQMappableCommands[i]; clickedAlt = false; clickedEQ = true; clickedCombo = keyComboDesc; clicked = true; }

					ImGui::TableNextColumn();
					DescribeKeyCombo(pKeypressHandler->AltKey[i], keyComboDesc, sizeof(keyComboDesc));
					hovered = (sHoveredIndex == i && sHoveredAlt == true);
					ImGui::TextColored(GetKeyBindColor(ci_equals("clear", keyComboDesc), hovered), "%s", keyComboDesc);
					if (ImGui::IsItemHovered()) { sHoveredAlt = true; sHoveredIndex = i; isAnyHovered = true; }
					if (ImGui::IsItemClicked()) { clickedName = szEQMappableCommands[i]; clickedAlt = true; clickedEQ = true; clickedCombo = keyComboDesc; clicked = true; }
				}

				ImGui::EndTable();
			}

			if (!isAnyHovered)
			{
				sHoveredIndex = -1;
				sHoveredAlt = false;
			}

			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}

	if (clicked)
	{
		DoEditKeyCombo(clickedName, clickedCombo, clickedAlt, clickedEQ);
	}

	DoEditKeyComboPopup();
}

//============================================================================
// KeyBinds Inspector
//============================================================================


class KeyBindsInspector : public ImGuiWindowBase
{
public:
	KeyBindsInspector() : ImGuiWindowBase("Key Bindings Inspector")
	{
		SetDefaultSize(ImVec2(600, 400));
	}

	virtual  ~KeyBindsInspector() override
	{
	}

	bool IsEnabled() const override
	{
		return true;
	}

	void Draw() override
	{
		std::string clickedName;
		bool clickedAlt = false;
		bool clickedEQ = false;
		std::string clickedCombo;
		bool clicked = false;

		static int sHoveredIndex = -1;
		static bool sHoveredAlt = false;
		bool isAnyHovered = false;

		if (ImGui::BeginTable("##EQKeybindTable", 7, ImGuiTableFlags_Resizable | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_ScrollY))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthFixed, 20.0f);
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Bind", ImGuiTableColumnFlags_WidthFixed);
			ImGui::TableSetupColumn("Alt", ImGuiTableColumnFlags_WidthFixed);
			ImGui::TableSetupColumn("State", ImGuiTableColumnFlags_WidthFixed, 40.0f);
			ImGui::TableSetupColumn("KeyDown", ImGuiTableColumnFlags_WidthFixed, 40.0f);
			ImGui::TableSetupColumn("Enabled", ImGuiTableColumnFlags_WidthFixed, 40.0f);
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();
	
			for (int i = 0; i < nEQMappableCommands; ++i)
			{
				ImGui::PushID(i);
				char keyComboDesc[64];

				ImGui::TableNextRow();

				// ID
				ImGui::TableNextColumn();
				ImGui::Text("%d", i);

				// Name
				ImGui::TableNextColumn();
				if (szEQMappableCommands[i])
					ImGui::Text("%s", szEQMappableCommands[i]);
				else
					ImGui::TextColored(ImColor(255, 0, 0), "(Unmapped:%d)", i);

				// Bind
				ImGui::TableNextColumn();
				DescribeKeyCombo(pKeypressHandler->NormalKey[i], keyComboDesc, sizeof(keyComboDesc));
				bool hovered = (sHoveredIndex == i && sHoveredAlt == false);
				ImGui::TextColored(GetKeyBindColor(ci_equals("clear", keyComboDesc), hovered), "%s", keyComboDesc);
				if (ImGui::IsItemHovered()) { sHoveredAlt = false; sHoveredIndex = i; isAnyHovered = true; }
				if (ImGui::IsItemClicked()) { clickedName = szEQMappableCommands[i]; clickedAlt = false; clickedEQ = true; clickedCombo = keyComboDesc; clicked = true; }

				// Alt Bind
				ImGui::TableNextColumn();
				DescribeKeyCombo(pKeypressHandler->AltKey[i], keyComboDesc, sizeof(keyComboDesc));
				hovered = (sHoveredIndex == i && sHoveredAlt == true);
				ImGui::TextColored(GetKeyBindColor(ci_equals("clear", keyComboDesc), hovered), "%s", keyComboDesc);
				if (ImGui::IsItemHovered()) { sHoveredAlt = true; sHoveredIndex = i; isAnyHovered = true; }
				if (ImGui::IsItemClicked()) { clickedName = szEQMappableCommands[i]; clickedAlt = true; clickedEQ = true; clickedCombo = keyComboDesc; clicked = true; }

				// State
				ImGui::TableNextColumn();
				bool state = pKeypressHandler->CommandState[i];
				ImGui::TextColored(state ? ImColor(0, 255, 0) : ImColor(255, 0, 0), "%s", state ? "ON" : "OFF");

				// KeyDown
				ImGui::TableNextColumn();
				state = pEverQuestInfo->keyDown[i];
				ImGui::TextColored(state ? ImColor(0, 255, 0) : ImColor(255, 0, 0), "%s", state ? "ON" : "OFF");

				// Enabled
				ImGui::TableNextColumn();
				state = EQbCommandStates[i] != 0;
				ImGui::TextColored(state ? ImColor(0, 255, 0) : ImColor(255, 0, 0), "%s", state ? "ON" : "OFF");

				ImGui::PopID();
			}

			ImGui::EndTable();
		}

		if (!isAnyHovered)
		{
			sHoveredIndex = -1;
			sHoveredAlt = false;
		}

		if (clicked)
		{
			DoEditKeyCombo(clickedName, clickedCombo, clickedAlt, clickedEQ);
		}

		DoEditKeyComboPopup();
	}
};
static KeyBindsInspector* s_inspector = nullptr;


//============================================================================
//============================================================================

void InitializeMQ2KeyBinds()
{
	AddMQ2KeyBind("RANGED", DoRangedBind);
	AddSettingsPanel("Key Bindings", DoKeybindSettings);

	s_inspector = new KeyBindsInspector();
	DeveloperTools_RegisterMenuItem(s_inspector, "Key Bindings", s_menuNameInspectors);

	EzDetour(KeypressHandler__ClearCommandStateArray, &KeypressHandlerHook::ClearCommandStateArray_Hook, &KeypressHandlerHook::ClearCommandStateArray_Trampoline);
	EzDetour(KeypressHandler__HandleKeyDown, &KeypressHandlerHook::HandleKeyDown_Hook, &KeypressHandlerHook::HandleKeyDown_Trampoline);
	EzDetour(KeypressHandler__HandleKeyUp, &KeypressHandlerHook::HandleKeyUp_Hook, &KeypressHandlerHook::HandleKeyUp_Trampoline);

	// Validate that our constants are correct
	assert(ci_equals(szEQMappableCommands[CMD_AUTORUN], "autorun"));
	assert(ci_equals(szEQMappableCommands[CMD_JUMP], "jump"));
	assert(ci_equals(szEQMappableCommands[CMD_FORWARD], "forward"));
	assert(ci_equals(szEQMappableCommands[CMD_BACK], "back"));
	assert(ci_equals(szEQMappableCommands[CMD_RIGHT], "right"));
	assert(ci_equals(szEQMappableCommands[CMD_LEFT], "left"));
	assert(ci_equals(szEQMappableCommands[CMD_STRAFE_LEFT], "strafe_left"));
	assert(ci_equals(szEQMappableCommands[CMD_STRAFE_RIGHT], "strafe_right"));
	assert(ci_equals(szEQMappableCommands[CMD_DUCK], "duck"));
	assert(ci_equals(szEQMappableCommands[CMD_RUN_WALK], "run_walk"));
}

void ShutdownMQ2KeyBinds()
{
	gKeyBinds.clear();
	gKeybindMap.clear();

	RemoveSettingsPanel("Key Bindings");

	DeveloperTools_UnregisterMenuItem(s_inspector);
	delete s_inspector; s_inspector = nullptr;

	RemoveDetour(KeypressHandler__ClearCommandStateArray);
	RemoveDetour(KeypressHandler__HandleKeyDown);
	RemoveDetour(KeypressHandler__HandleKeyUp);
}

} // namespace mq
