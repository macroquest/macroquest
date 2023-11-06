/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

#include "mq/api/Spawns.h"

#include "MQ2Main.h"

#include "mq/imgui/ImGuiUtils.h"

namespace mq {

static void Spawns_Initialize();
static void Spawns_Shutdown();
static void Spawns_Pulse();
static void Spawns_BeginZone();
static void Spawns_SpawnRemoved(PlayerClient* pSpawn);

static MQModule gSpawnsModule = {
	"Spawns",                     // Name
	false,                        // CanUnload
	Spawns_Initialize,            // Initialize
	Spawns_Shutdown,              // Shutdown
	Spawns_Pulse,                 // Pulse
	nullptr,                      // SetGameState
	nullptr,                      // UpdateImGui
	nullptr,                      // Zoned
	nullptr,                      // WriteChatColor
	nullptr,                      // SpawnAdded
	Spawns_SpawnRemoved,          // SpawnRemoved
	Spawns_BeginZone,             // BeginZone
};
MQModule* GetSpawnsModule() { return &gSpawnsModule; }

// Global spawn array, sorted by distance.
std::vector<MQSpawnArrayItem> gSpawnsArray;


#pragma region Caption Colors

//----------------------------------------------------------------------------
// caption color code
//----------------------------------------------------------------------------

static int gMaxSpawnCaptions = 35;
static bool gMQCaptions = true;

static constexpr int CAPTION_UPDATE_FRAMES = 20; // number of frames between caption updates

static PlayerClient* pNamingSpawn = nullptr;

// TLO used for controlling what we are currently naming.
static bool dataNamingSpawn(const char* szIndex, MQTypeVar& Ret)
{
	if (Ret.Ptr = pNamingSpawn)
	{
		Ret.Type = datatypes::pSpawnType;
		return true;
	}
	return false;
}

static void ConvertCR(std::string& text)
{
	size_t in = 0, out = 0;
	for (; in < text.size(); in++, out++)
	{
		if (text[in] == '\\' && in < text.size() - 1 && text[in + 1] == 'n') {
			text[out] = '\n';
			in++;
		}
		else if (in != out)
			text[out] = text[in];
	}
	text[out] = 0;
	text.resize(out);
}

enum CustomCaptionType
{
	Caption_Player1,
	Caption_Player2,
	Caption_Player3,
	Caption_Player4,
	Caption_Player5,
	Caption_Player6,
	Caption_NPC,
	Caption_Pet,
	Caption_Merc,
	Caption_Corpse,

	CustomCaptions_Max
};

static std::string RenderDefaultCaptionString(CustomCaptionType type, PlayerClient* pSpawn);

class MQCustomCaption
{
public:
	MQCustomCaption(CustomCaptionType type, const char* defaultValue, const char* settingName)
		: type(type)
		, defaultValue(defaultValue)
		, settingName(settingName)
	{
	}

	void Load(bool writeBack = false)
	{
		value = GetPrivateProfileString("Captions", settingName, defaultValue, mq::internal_paths::MQini);
		isDefault = string_equals(defaultValue, value);

		if (writeBack)
		{
			WritePrivateProfileString("Captions", settingName, value.c_str(), mq::internal_paths::MQini);
		}

		ConvertCR(value);
	}

	void SetValue(std::string newValue)
	{
		value = std::move(newValue);
		isDefault = string_equals(defaultValue, value);

		WritePrivateProfileString("Captions", settingName, value, mq::internal_paths::MQini);
		ConvertCR(value);
	}

	void ResetValue()
	{
		SetValue(defaultValue);
	}

	std::string RenderCaption(PlayerClient* pSpawn) const
	{
		if (value.empty() || pSpawn == nullptr)
			return value;

		if (isDefault)
		{
			std::string result = RenderDefaultCaptionString(type, pSpawn);
			if (!result.empty())
				return result;
		}

		pNamingSpawn = pSpawn;

		std::string result = ModifyMacroString(value);

		pNamingSpawn = nullptr;

		return result;
	}

	const char* const defaultValue;
	const char* const settingName;
	std::string value;
	CustomCaptionType type;
	bool isDefault = true;
};

static MQCustomCaption CustomPlayerCaptions[CustomCaptions_Max] = {
	{
		Caption_Player1,
		"${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}",
		"Player1",
	},
	{
		Caption_Player2,
		"${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length}, ${NamingSpawn.Surname},]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}",
		"Player2",
	},
	{
		Caption_Player3,
		"${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length}, ${NamingSpawn.Surname},]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}${If[${NamingSpawn.Guild.Length},\\n<${NamingSpawn.Guild}>,]}",
		"Player3",
	},
	{
		Caption_Player4,
		"${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.AARank},${NamingSpawn.AATitle} ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length}, ${NamingSpawn.Surname},]}${If[${NamingSpawn.Suffix.Length}~${If[${NamingSpawn.Suffix.Left[1].Equal[,]}~${NamingSpawn.Suffix}~ ${NamingSpawn.Suffix}]}~]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}${If[${NamingSpawn.Guild.Length},\\n<${NamingSpawn.Guild}>,]}",
		"Player4",
	},
	{
		Caption_Player5,
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",
		"Player5",
	},
	{
		Caption_Player6,
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",
		"Player6",
	},
	{
		Caption_NPC,
		"${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Assist},>> ,]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist}, - ${NamingSpawn.PctHPs}%<<,]}${If[${NamingSpawn.Surname.Length},\\n(${NamingSpawn.Surname}),]}",
		"NPC",
	},
	{
		Caption_Pet,
		"${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Assist},>> ,]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist}, - ${NamingSpawn.PctHPs}%<<,]}${If[${NamingSpawn.Master.Type.Equal[PC]},\\n(${NamingSpawn.Master}),]}",
		"Pet",
	},
	{
		Caption_Merc,
		"${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Assist},>> ,]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist}, - ${NamingSpawn.PctHPs}%<<,]}${If[${NamingSpawn.Owner.Type.Equal[PC]},\\n(${NamingSpawn.Owner}),]}",
		"Merc",
	},
	{
		Caption_Corpse,
		"${NamingSpawn.DisplayName}'s corpse",
		"Corpse",
	},
};

static std::string RenderDefaultCaptionString(CustomCaptionType type, PlayerClient* pSpawn)
{
	fmt::memory_buffer buffer;
	auto buf = fmt::appender(buffer);

	switch (type)
	{
	case Caption_Player1:
	case Caption_Player2:
	case Caption_Player3:
	case Caption_Player4:
	case Caption_Player5:
	case Caption_Player6: {
		/*

		${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}
		${If[${NamingSpawn.Trader},Trader ,]}

		// Player4,Player5,Player6
		${If[${NamingSpawn.AARank},${NamingSpawn.AATitle} ,]}

		${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}

		// 2, 3, 4, 6
		${If[${NamingSpawn.Surname.Length}, ${NamingSpawn.Surname},]}

		// 4, 5, 6
		${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}

		${If[${NamingSpawn.AFK}, AFK,]}
		${If[${NamingSpawn.Linkdead}, LD,]}
		${If[${NamingSpawn.LFG}, LFG,]}
		${If[${NamingSpawn.GroupLeader}, LDR,]}

		// 3,4
		${If[${NamingSpawn.Guild.Length},\\n<${NamingSpawn.Guild}>,]}",

		*/
		int showNamesLevel = type - Caption_Player1 + 1;

		if (int mark = GetNPCMarkNumber(pSpawn))
			fmt::format_to(buf, "{} - ", mark);

		if (pSpawn->Trader != 0)
			fmt::format_to(buf, "Trader ");

		if (showNamesLevel > 3 && pSpawn->Title[0] != 0)
			fmt::format_to(buf, pSpawn->Title);

		bool invis = pSpawn->HideMode != 0;

		if (invis)
			fmt::format_to(buf, "({})", pSpawn->DisplayedName);
		else
			fmt::format_to(buf, "{}", pSpawn->DisplayedName);

		if (showNamesLevel > 1 && pSpawn->Lastname[0] != 0)
			fmt::format_to(buf, " {}", pSpawn->Lastname);

		if (showNamesLevel > 3 && pSpawn->Suffix[0] != 0)
			fmt::format_to(buf, " {}", pSpawn->Suffix);

		if (pSpawn->LFG)
			fmt::format_to(buf, " LFG");
		if (pSpawn->AFK != 0)
			fmt::format_to(buf, " AFK");
		if (pSpawn->Linkdead)
			fmt::format_to(buf, " LD");

		if (pSpawn == pTarget)
			fmt::format_to(buf, " - {}%", static_cast<int>(pSpawn->HPMax == 0 ? 0 : pSpawn->HPCurrent * 100 / pSpawn->HPMax));
		
		if (showNamesLevel == 3 || showNamesLevel == 4)
		{
			if (pSpawn->GuildID != -1)
			{
				const char* szGuild = GetGuildByID(pSpawn->GuildID);
				if (szGuild)
				{
					fmt::format_to(buf, "\n<{}>", szGuild);
				}
			}
		}

		break;
	}

	case Caption_NPC:
	case Caption_Pet:
	case Caption_Merc: {
		int mark = GetNPCMarkNumber(pSpawn);
		if (mark != 0)
			fmt::format_to(buf, "{} - ", mark);

		bool assist = IsAssistNPC(pSpawn);

		if (assist)
			fmt::format_to(buf, " >> ");

		fmt::format_to(buf, "{}", pSpawn->DisplayedName);

		if (pSpawn == pTarget || assist || mark != 0)
			fmt::format_to(buf, " - {}%", static_cast<int>(pSpawn->HPMax == 0 ? 0 : pSpawn->HPCurrent * 100 / pSpawn->HPMax));

		if (assist)
			fmt::format_to(buf, " <<");

		if (pSpawn->Lastname[0] != 0)
		{
			fmt::format_to(buf, "\n({})", pSpawn->Lastname);
		}
		break;
	}

	case Caption_Corpse:
		fmt::format_to(buf, "{}'s corpse", pSpawn->DisplayedName);
		break;

	default:
		return {};
	};

	return fmt::to_string(buffer);
}

enum eCaptionColor
{
	CC_PC,
	CC_PCConColor,
	CC_PCRaidColor,
	CC_PCClassColor,
	CC_PCGroupColor,
	CC_PCTrader,
	CC_NPC,
	CC_NPCConColor,
	CC_NPCClassColor,
	CC_NPCMerchant,
	CC_NPCBanker,
	CC_NPCAssist,
	CC_NPCMark,
	CC_PetNPC,
	CC_PetPC,
	CC_PetConColor,
	CC_PetClassColor,
	CC_Mercenary,
	CC_Corpse,
	CC_CorpseClassColor,
};

struct MQCaptionColor
{
	const char*   szName;
	const char*   szDescription;
	bool          Enabled;
	bool          DefaultEnabled;
	bool          ToggleOnly;
	const MQColor DefaultColor;
	MQColor       Color;

	MQCaptionColor(const char* name, const char* description, bool defaultEnabled, bool toggleOnly, MQColor defaultColor)
		: szName(name), szDescription(description), DefaultEnabled(defaultEnabled), Enabled(defaultEnabled)
		, ToggleOnly(toggleOnly), DefaultColor(defaultColor), Color(defaultColor)
	{
	}

	void Save()
	{
		WritePrivateProfileString("Caption Colors", szName, Enabled ? "ON" : "OFF", mq::internal_paths::MQini);

		if (!ToggleOnly)
		{
			char key[24], value[64];
			sprintf_s(key, "%x", Color.ARGB);
			sprintf_s(value, "%s-Color", szName);

			WritePrivateProfileString("CaptionColors", key, value, mq::internal_paths::MQini);
		}
	}

	void Load()
	{
		char value[24];
		if (GetPrivateProfileString("Caption Colors", szName, "", value, sizeof(value), mq::internal_paths::MQini))
		{
			Enabled = GetBoolFromString(value, false);
		}

		if (!ToggleOnly)
		{
			char key[64];
			sprintf_s(key, "%s-Color", szName);

			if (GetPrivateProfileString("Caption Colors", key, "", value, sizeof(value), mq::internal_paths::MQini))
			{
				if (!sscanf_s(value, "%x", &Color.ARGB))
					Color = DefaultColor;
			}
		}
	}
};

static MQCaptionColor CaptionColors[] =
{
	// name          description                              defaultEnabled  toggle    defaultColor
	{ "PC",          "Default color for PCs",                 false,          false,    0x003D68DC, },
	{ "PCCon",       "PCs by con color",                      false,          true,     MQColor(),  },
	{ "PCRaid",      "Raid members",                          false,          false,    0x0000FF7F, },
	{ "PCClass",     "PCs by class color (raid settings)",    false,          true,     MQColor(),  },
	{ "PCGroup",     "Group members",                         false,          false,    0x00FFFF00, },
	{ "PCTrader",    "Traders",                               true,           false,    0x00FF7F00, },
	{ "NPC",         "NPC default color",                     false,          false,    0x00FF0000, },
	{ "NPCCon",      "NPCs by con color",                     true,           true,     MQColor(),  },
	{ "NPCClass",    "NPCs by class color (raid settings)",   false,          true,     MQColor(),  },
	{ "NPCMerchant", "NPC Merchants",                         true,           false,    0x00FF7F00, },
	{ "NPCBanker",   "NPC Bankers",                           true,           false,    0x00C800FF, },
	{ "NPCAssist",   "NPCs from main assist",                 true,           false,    0x00FFFF00, },
	{ "NPCMark",     "Marked NPCs",                           true,           false,    0x00FFFF00, },
	{ "PetNPC",      "Pet with NPC owner",                    false,          false,    0x00FF0000, },
	{ "PetPC",       "Pet with PC owner",                     false,          false,    0x0017B8AD, },
	{ "PetConColor", "Pet by con color",                      false,          true,     MQColor(),  },
	{ "PetClass",    "Pet by class color (raid settings)",    false,          true,     MQColor(),  },
	{ "Mercenary",   "Mercenaries",                           false,          false,    0x00FFB511, },
	{ "Corpse",      "Corpses",                               false,          false,    0x00FF0000, },
	{ "CorpseClass", "Corpse by class color (raid settings)", false,          true,     MQColor(),  },
};


static void CaptionCmd(PlayerClient* pChar, char* szLine)
{
	char Arg1[MAX_STRING] = { 0 };
	GetArg(Arg1, szLine, 1);

	if (!Arg1[0])
	{
		SyntaxError("Usage: /caption <settings|list|type <value>|update #|MQCaptions <on|off>>");
		return;
	}

	if (ci_equals(Arg1, "settings"))
	{
		EzCommand("/mqsettings captions");
		return;
	}

	if (ci_equals(Arg1, "list"))
	{
		for (auto& caption : CustomPlayerCaptions)
		{
			WriteChatf("\ayPlayer1\ax: \ag%s\ax", caption.settingName, caption.value.c_str());
		}
		return;
	}

	if (ci_equals(Arg1, "Update"))
	{
		gMaxSpawnCaptions = std::clamp(GetIntFromString(GetNextArg(szLine), 0), 8, 70);

		WritePrivateProfileInt("Captions", "Update", gMaxSpawnCaptions, mq::internal_paths::MQini);
		WriteChatf("\ay%d\ax nearest spawns will have their caption updated each pass.", gMaxSpawnCaptions);
		return;
	}

	if (ci_equals(Arg1, "MQCaptions"))
	{
		gMQCaptions = GetBoolFromString(GetNextArg(szLine), false);
		WritePrivateProfileBool("Captions", "MQCaptions", gMQCaptions, mq::internal_paths::MQini);

		WriteChatf("MQCaptions are now \ay%s\ax.", (gMQCaptions ? "On" : "Off"));
		return;
	}

	if (ci_equals(Arg1, "reload"))
	{
		for (auto& caption : CustomPlayerCaptions)
		{
			caption.Load();
		}

		WriteChatf("Updated Captions from INI.");
		return;
	}
	
	if (ci_equals(Arg1, "anon"))
	{
		MacroError("Anon is no longer accessed through /caption, please use /mqanon");
		return;
	}

	MQCustomCaption* caption = nullptr;
	for (auto& capt : CustomPlayerCaptions)
	{
		if (ci_equals(Arg1, capt.settingName))
			caption = &capt;
	}

	if (caption == nullptr)
	{
		MacroError("Invalid caption type '%s'", Arg1);
		return;
	}

	caption->SetValue(GetNextArg(szLine));
	WriteChatf("\ay%s\ax caption set.", caption->settingName);
}

static void CaptionColorCmd(PlayerClient* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /captioncolor <list|<name off|on|#>>");
		return;
	}

	char Arg1[MAX_STRING] = { 0 };
	GetArg(Arg1, szLine, 1);

	char Arg2[MAX_STRING] = { 0 };
	GetArg(Arg2, szLine, 2);

	if (ci_equals(Arg1, "list"))
	{
		WriteChatColor("Caption Color Settings");
		WriteChatColor("----------------------");

		for (auto& CaptionColor : CaptionColors)
		{
			if (!CaptionColor.Enabled || CaptionColor.ToggleOnly)
			{
				WriteChatf("%s %s (%s)", CaptionColor.szName, CaptionColor.Enabled ? "ON" : "OFF", CaptionColor.szDescription);
			}
			else
			{
				auto& color = CaptionColor.Color;
				WriteChatf("%s ON Color: %d %d %d. (%s)", CaptionColor.szName, color.Red, color.Green, color.Blue, CaptionColor.szDescription);
			}
		}

		return;
	}

	for (auto& CaptionColor : CaptionColors)
	{
		if (ci_equals(Arg1, CaptionColor.szName))
		{
			if (Arg2[0])
			{
				if (ci_equals(Arg2, "on"))
					CaptionColor.Enabled = true;
				else if (ci_equals(Arg2, "off"))
					CaptionColor.Enabled = false;
				else if (CaptionColor.Enabled && !CaptionColor.ToggleOnly)
				{
					MQColor NewColor;
					NewColor.Alpha = 0;
					NewColor.Red = GetIntFromString(Arg2, 0);
					NewColor.Green = GetIntFromString(GetArg(Arg2, szLine, 3), 0);
					NewColor.Blue = GetIntFromString(GetArg(Arg2, szLine, 4), 0);
					CaptionColor.Color = NewColor;
				}
				else
				{
					MacroError("Invalid option '%s' while '%s' is off.", Arg2, Arg1);
					return;
				}
			}

			if (!CaptionColor.Enabled || CaptionColor.ToggleOnly)
			{
				WriteChatf("%s %s (%s)", CaptionColor.szName, CaptionColor.Enabled ? "ON" : "OFF", CaptionColor.szDescription);
			}
			else
			{
				auto& Color = CaptionColor.Color;
				WriteChatf("%s ON Color: %d %d %d. (%s)", CaptionColor.szName, Color.Red, Color.Green, Color.Blue, CaptionColor.szDescription);
			}

			CaptionColor.Save();
			return;
		}
	}
}

void SetNameSpriteTint(PlayerClient* pSpawn);

class PlayerManagerBaseHook : public eqlib::PlayerManagerBase
{
public:
	DETOUR_TRAMPOLINE_DEF(PlayerClient*, PrepForDestroyPlayer_Trampoline, (PlayerClient*))
	PlayerClient* PrepForDestroyPlayer_Detour(PlayerClient* spawn)
	{
		// PrepForDestroyPlayer can be called twice through the same code path
		static unsigned int lastSpawnID = 0;
		if (lastSpawnID != spawn->GetId())
		{
			lastSpawnID = spawn->GetId();
			PluginsRemoveSpawn(spawn);
		}
		return PrepForDestroyPlayer_Trampoline(spawn);
	}

#if !IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
	DETOUR_TRAMPOLINE_DEF(void, DestroyAllPlayers_Trampoline, ())
		void DestroyAllPlayers_Detour()
	{
		PlayerClient* pSpawn = FirstSpawn;
		while (pSpawn)
		{
			PluginsRemoveSpawn(pSpawn);
			pSpawn = pSpawn->pNext;
		}

		return DestroyAllPlayers_Trampoline();
	}
#endif
};


class PlayerManagerClientHook
{
public:
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
	DETOUR_TRAMPOLINE_DEF(PlayerClient*, CreatePlayer_Trampoline, (CUnSerializeBuffer*, void*, void*, void*, void*, void*, void*, void*, void*))
	PlayerClient* CreatePlayer_Detour(CUnSerializeBuffer* buf, void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h)
	{
		PlayerClient* spawn = CreatePlayer_Trampoline(buf, a, b, c, d, e, f, g, h);
		PluginsAddSpawn(spawn);
		return spawn;
	}
#else
	DETOUR_TRAMPOLINE_DEF(PlayerClient*, CreatePlayer_Trampoline, (CUnSerializeBuffer*, void*, void*, void*, void*, void*, void*, void*))
		PlayerClient* CreatePlayer_Detour(CUnSerializeBuffer* buf, void* a, void* b, void* c, void* d, void* e, void* f, void* g)
	{
		PlayerClient* spawn = CreatePlayer_Trampoline(buf, a, b, c, d, e, f, g);
		PluginsAddSpawn(spawn);
		return spawn;
	}
#endif
};

class PlayerClientHook
{
public:
	DETOUR_TRAMPOLINE_DEF(int, SetNameSpriteState_Trampoline, (bool Show))
	int SetNameSpriteState_Detour(bool Show)
	{
		if (gGameState != GAMESTATE_INGAME || !Show || !gMQCaptions)
			return SetNameSpriteState_Trampoline(Show);

		return 1;
	}

	DETOUR_TRAMPOLINE_DEF(bool, SetNameSpriteTint_Trampoline, ())
	bool SetNameSpriteTint_Detour()
	{
		if (gGameState != GAMESTATE_INGAME || !gMQCaptions)
			return SetNameSpriteTint_Trampoline();

		return true;
	}
};

static void SetNameSpriteTint(PlayerClient* pSpawn)
{
	if (!gMQCaptions)
		return;

	MQColor NewColor;
	PlayerClientHook* pHook = (PlayerClientHook*)pSpawn;

	switch (GetSpawnType(pSpawn))
	{
	case PC:
		if (pSpawn->Trader && CaptionColors[CC_PCTrader].Enabled)
			NewColor = CaptionColors[CC_PCTrader].Color;
		else if (CaptionColors[CC_PCGroupColor].Enabled && IsGroupMember(pSpawn))
			NewColor = CaptionColors[CC_PCGroupColor].Color;
		else if (CaptionColors[CC_PCClassColor].Enabled)
			NewColor = pRaidWnd->ClassColors[ClassInfo[pSpawn->GetClass()].RaidColorOrder];
		else if (CaptionColors[CC_PCRaidColor].Enabled && IsRaidMember(pSpawn))
			NewColor = CaptionColors[CC_PCRaidColor].Color;
		else if (CaptionColors[CC_PCConColor].Enabled)
			NewColor = ConColorToARGB(ConColor(pSpawn));
		else if (CaptionColors[CC_PC].Enabled)
			NewColor = CaptionColors[CC_PC].Color;
		else
		{
			pHook->SetNameSpriteTint_Trampoline();
			return;
		}
		break;

	case NPC:
		if (CaptionColors[CC_NPCMark].Enabled && IsMarkedNPC(pSpawn))
			NewColor = CaptionColors[CC_NPCMark].Color;
		if (CaptionColors[CC_NPCAssist].Enabled && IsAssistNPC(pSpawn))
			NewColor = CaptionColors[CC_NPCAssist].Color;
		else if (CaptionColors[CC_NPCBanker].Enabled && pSpawn->GetClass() == Class_Banker)
			NewColor = CaptionColors[CC_NPCBanker].Color;
		else if (CaptionColors[CC_NPCMerchant].Enabled && (pSpawn->GetClass() == Class_Merchant || pSpawn->GetClass() == Class_AdventureMerchant))
			NewColor = CaptionColors[CC_NPCMerchant].Color;
		else if (CaptionColors[CC_NPCClassColor].Enabled && pSpawn->GetClass() < TotalPlayerClasses)
			NewColor = pRaidWnd->ClassColors[ClassInfo[pSpawn->GetClass()].RaidColorOrder];
		else if (CaptionColors[CC_NPCConColor].Enabled)
			NewColor = ConColorToARGB(ConColor(pSpawn));
		else if (CaptionColors[CC_NPC].Enabled)
			NewColor = CaptionColors[CC_NPC].Color;
		else
		{
			pHook->SetNameSpriteTint_Trampoline();
			return;
		}
		break;

	case CORPSE:
		if (CaptionColors[CC_CorpseClassColor].Enabled)
			NewColor = pRaidWnd->ClassColors[ClassInfo[pSpawn->GetClass()].RaidColorOrder];
		else if (CaptionColors[CC_Corpse].Enabled)
			NewColor = CaptionColors[CC_Corpse].Color;
		else
		{
			pHook->SetNameSpriteTint_Trampoline();
			return;
		}
		break;

	case PET:
		if (CaptionColors[CC_PetClassColor].Enabled)
			NewColor = pRaidWnd->ClassColors[ClassInfo[pSpawn->GetClass()].RaidColorOrder];
		else if (CaptionColors[CC_PetConColor].Enabled)
			NewColor = ConColorToARGB(ConColor(pSpawn));
		else if (CaptionColors[CC_PetNPC].Enabled && GetSpawnByID(pSpawn->MasterID)->Type == SPAWN_NPC)
			NewColor = CaptionColors[CC_PetNPC].Color;
		else if (CaptionColors[CC_PetPC].Enabled && GetSpawnByID(pSpawn->MasterID)->Type == SPAWN_PLAYER)
			NewColor = CaptionColors[CC_PetPC].Color;
		else
		{
			pHook->SetNameSpriteTint_Trampoline();
			return;
		}
		break;

	case MERCENARY:
		if (CaptionColors[CC_Mercenary].Enabled)
			NewColor = CaptionColors[CC_Mercenary].Color;
		else
		{
			pHook->SetNameSpriteTint_Trampoline();
			return;
		}
		break;

	case OBJECT:
	case UNTARGETABLE:
		pHook->SetNameSpriteTint_Trampoline();
		return;
	}

	if (pSpawn->GetActor())
		pSpawn->GetActor()->SetStringSpriteTint((RGB*)&NewColor);
}

static bool SetCaption(PlayerClient* pSpawn, const MQCustomCaption& caption)
{
	std::string result = caption.RenderCaption(pSpawn);

	if (!result.empty())
	{
		if (MaybeAnonymize(result))
		{
			pSpawn->ChangeBoneStringSprite(0, Anonymize(CXStr{ result }).c_str());
		}
		else
		{
			pSpawn->ChangeBoneStringSprite(0, result.c_str());
		}

		return true;
	}

	return false;
}

bool SetNameSpriteState(PlayerClient* pSpawn, bool Show)
{
	if (!Show || !gMQCaptions)
	{
		return reinterpret_cast<PlayerClientHook*>(pSpawn)->SetNameSpriteState_Trampoline(Show) != 0;
	}

	if (!pSpawn->GetActor() || !pSpawn->GetActor()->IsBoneSet(0))
	{
		return true;
	}

	switch (GetSpawnType(pSpawn))
	{
	case NPC:
		if (SetCaption(pSpawn, CustomPlayerCaptions[Caption_NPC]))
			return true;
		break;

	case PC:
		if (!pEverQuestInfo->gOpt.pcNames && pSpawn != pTarget)
			return false;

		if (SetCaption(pSpawn, CustomPlayerCaptions[Caption_Player1 + (IsAnonymized() ? 1 : pEverQuestInfo->iShowNamesLevel) - 1]))
			return true;
		break;

	case CORPSE:
		if (SetCaption(pSpawn, CustomPlayerCaptions[Caption_Corpse]))
			return true;
		break;

	case CHEST:
	case UNTARGETABLE:
	case TRAP:
	case TIMER:
	case TRIGGER: // trigger names make it crash!
		return false;

	case MOUNT: //mount names make it crash!
		return false;

	case PET:
		if (SetCaption(pSpawn, CustomPlayerCaptions[Caption_Pet]))
			return true;
		break;

	case MERCENARY:
		if (SetCaption(pSpawn, CustomPlayerCaptions[Caption_Merc]))
			return true;
		break;
	}

	return reinterpret_cast<PlayerClientHook*>(pSpawn)->SetNameSpriteState_Trampoline(Show) != 0;
}

static void UpdateSpawnCaptions()
{
	if (!gMQCaptions)
		return;

	int count = 0;
	for (const MQSpawnArrayItem& item : gSpawnsArray)
	{
		PlayerClient* pSpawn = item.GetSpawn();

		if (!pSpawn || pSpawn == pTarget)
			continue;

		if (SetNameSpriteState(pSpawn, true))
		{
			SetNameSpriteTint(pSpawn);
			++count;
		}

		if (count >= gMaxSpawnCaptions)
			break;
	}
}

static void LoadCaptionSettings()
{
	const auto& iniFile = mq::internal_paths::MQini;

	for (auto& caption : CustomPlayerCaptions)
	{
		caption.Load(gbWriteAllConfig);
	}

	gMaxSpawnCaptions = GetPrivateProfileInt("Captions", "Update", gMaxSpawnCaptions, iniFile);
	gMQCaptions = GetPrivateProfileBool("Captions", "MQCaptions", gMQCaptions, iniFile);

	if (gbWriteAllConfig)
	{
		WritePrivateProfileInt("Captions", "Update", gMaxSpawnCaptions, iniFile);
		WritePrivateProfileBool("Captions", "MQCaptions", gMQCaptions, iniFile);
	}
}

void CaptionsSettingsPanel()
{
	bool changed = false;

	changed |= ImGui::Checkbox("Enable MQ Captions", &gMQCaptions);

	// Colors
	//----------------------------------------------------------------------------
	ImGui::NewLine();
	ImGui::Text("Custom Caption Colors");
	ImGui::Separator();

	bool colorsChanged = false;

	for (auto& CaptionColor : CaptionColors)
	{
		ImGui::PushID(&CaptionColor);

		ImColor color = CaptionColor.Color.ToImColor();

		if (ImGui::Checkbox("##Enable", &CaptionColor.Enabled))
		{
			colorsChanged = true;
		}
		ImGui::SameLine();


		ImGui::SetNextItemWidth(
			ImGui::GetContentRegionAvailWidth() - 130);

		ImGui::BeginDisabled(CaptionColor.ToggleOnly);
		if (ImGui::ColorEdit3("##Color", &color.Value.x))
		{
			CaptionColor.Color = MQColor(color);
			CaptionColor.Color.Alpha = 0;
			colorsChanged = true;
		}
		ImGui::EndDisabled();

		ImGui::SameLine();
		ImGui::Text("%s", CaptionColor.szName);
		ImGui::SameLine();
		mq::imgui::HelpMarker(CaptionColor.szDescription);

		ImGui::PopID();
	}

	if (ImGui::Button("Reset to Default"))
	{
		for (auto& CaptionColor : CaptionColors)
		{
			CaptionColor.Color = CaptionColor.DefaultColor;
			CaptionColor.Enabled = CaptionColor.DefaultEnabled;
		}

		colorsChanged = true;
	}
}

#pragma endregion

#pragma region Ground Item Management
//----------------------------------------------------------------------------
// ground item management
//----------------------------------------------------------------------------

static MQGroundPending* pPendingGrounds = nullptr;
static bool ProcessPending = false;
static std::recursive_mutex s_groundsMutex;

static void AddGroundItem()
{
	if (EQGroundItem* pGroundItem = pItemList->Top)
	{
		std::scoped_lock lock(s_groundsMutex);

		MQGroundPending* pPending = new MQGroundPending;
		pPending->pGroundItem = pGroundItem;
		pPending->pNext = pPendingGrounds;
		pPending->pLast = nullptr;
		if (pPendingGrounds)
			pPendingGrounds->pLast = pPending;
		pPendingGrounds = pPending;
	}
}

static void RemoveGroundItem(EQGroundItem* pGroundItem)
{
	InvalidateObservedEQObject(pGroundItem);

	if (pPendingGrounds)
	{
		std::scoped_lock lock(s_groundsMutex);

		MQGroundPending* pPending = pPendingGrounds;
		while (pPending)
		{
			if (pGroundItem == pPending->pGroundItem)
			{
				if (pPending->pNext)
					pPending->pNext->pLast = pPending->pLast;
				if (pPending->pLast)
					pPending->pLast->pNext = pPending->pNext;
				else
					pPendingGrounds = pPending->pNext;

				delete pPending;
				break;
			}
			pPending = pPending->pNext;
		}
	}

	PluginsRemoveGroundItem(pGroundItem);
}

class MyEQGroundItemListManager
{
public:
	GROUNDITEM* m_pGroundItemList;

	DETOUR_TRAMPOLINE_DEF(void, FreeItemList_Trampoline, ())
	void FreeItemList_Detour()
	{
		EQGroundItem* pItem = pItemList->Top;

		while (pItem)
		{
			RemoveGroundItem(pItem);

			pItem = pItem->pNext;
		}

		FreeItemList_Trampoline();
	}

	DETOUR_TRAMPOLINE_DEF(void, Add_Trampoline, (EQGroundItem*))
	void Add_Detour(EQGroundItem* pItem)
	{
		if (m_pGroundItemList)
		{
			m_pGroundItemList->pPrev = pItem;
			pItem->pNext = m_pGroundItemList;
		}
		m_pGroundItemList = pItem;

		// if you drop something on the ground and this doesnt get called... you have the wrong offset

		// dont call the trampoline, we just did the exact same thing the trampoline would do.
		// for some reason, if we call the trampoline we will crash. and nobody has figured out why.
		AddGroundItem();
	}

	DETOUR_TRAMPOLINE_DEF(void, DeleteItem_Trampoline, (EQGroundItem*))
	void DeleteItem_Detour(EQGroundItem* pItem)
	{
		RemoveGroundItem(pItem);
		return DeleteItem_Trampoline(pItem);
	}
};

static void ProcessPendingGroundItems()
{
	if (!ProcessPending)
		return;

	std::scoped_lock lock(s_groundsMutex);

	while (pPendingGrounds)
	{
		MQGroundPending* pNext = pPendingGrounds->pNext;
		PluginsAddGroundItem(pPendingGrounds->pGroundItem);

		delete pPendingGrounds;
		pPendingGrounds = pNext;
	}
}

#pragma endregion

void UpdateMQ2SpawnSort()
{
	EnterMQ2Benchmark(bmUpdateSpawnSort);

	EQP_DistArray = nullptr;
	gSpawnCount = 0;
	gSpawnsArray.clear();

	float myX = 0, myY = 0;
	if (pControlledPlayer)
	{
		myX = pControlledPlayer->X;
		myY = pControlledPlayer->Y;
	}

	// we need to make sure the spawn manager is valid here because this can get called from login pulse before the spawn manager is valid
	if (pSpawnManager)
	{
		PlayerClient* pSpawn = pSpawnManager->FirstSpawn;
		while (pSpawn)
		{
			float distSq = GetDistanceSquared(myX, myY, pSpawn->X, pSpawn->Y);

			gSpawnsArray.emplace_back(pSpawn, distSq);
			pSpawn = pSpawn->pNext;
		}
	}

	std::sort(std::begin(gSpawnsArray), std::end(gSpawnsArray), MQRankFloatCompare);

	gSpawnCount = static_cast<int>(gSpawnsArray.size());
	EQP_DistArray = gSpawnCount > 0 ? &gSpawnsArray[0] : nullptr;

	ExitMQ2Benchmark(bmUpdateSpawnSort);
}

bool IsTargetable(PlayerClient* pSpawn)
{
	return pSpawn && pSpawn->IsTargetable();
}

bool AreNameSpritesCustomized()
{
	return gMQCaptions;
}

static void Spawns_Initialize()
{
	DebugSpew("Initializing Spawn-related Hooks");

	bmUpdateSpawnSort = AddMQ2Benchmark("UpdateSpawnSort");
	bmUpdateSpawnCaptions = AddMQ2Benchmark("UpdateSpawnCaptions");

	EzDetour(PlayerManagerClient__CreatePlayer, &PlayerManagerClientHook::CreatePlayer_Detour, &PlayerManagerClientHook::CreatePlayer_Trampoline);
	EzDetour(PlayerManagerBase__PrepForDestroyPlayer, &PlayerManagerBaseHook::PrepForDestroyPlayer_Detour, &PlayerManagerBaseHook::PrepForDestroyPlayer_Trampoline);
#if !IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
	EzDetour(PlayerManagerBase__DestroyAllPlayers, &PlayerManagerBaseHook::DestroyAllPlayers_Detour, &PlayerManagerBaseHook::DestroyAllPlayers_Trampoline);
#endif
	EzDetour(PlayerClient__SetNameSpriteState, &PlayerClientHook::SetNameSpriteState_Detour, &PlayerClientHook::SetNameSpriteState_Trampoline);
	EzDetour(PlayerClient__SetNameSpriteTint, &PlayerClientHook::SetNameSpriteTint_Detour, &PlayerClientHook::SetNameSpriteTint_Trampoline);
	EzDetour(EQItemList__FreeItemList, &MyEQGroundItemListManager::FreeItemList_Detour, &MyEQGroundItemListManager::FreeItemList_Trampoline);
	EzDetour(EQItemList__add_item, &MyEQGroundItemListManager::Add_Detour, &MyEQGroundItemListManager::Add_Trampoline);
	EzDetour(EQItemList__delete_item, &MyEQGroundItemListManager::DeleteItem_Detour, &MyEQGroundItemListManager::DeleteItem_Trampoline);

	// Load Settings
	LoadCaptionSettings();

	ProcessPending = true;

	EQP_DistArray = nullptr;
	gSpawnCount = 0;
	gSpawnsArray.reserve(4096);

	char Temp[MAX_STRING] = { 0 };
	char Name[MAX_STRING] = { 0 };

	// load custom spawn caption colors
	for (auto& CaptionColor : CaptionColors)
	{
		CaptionColor.Load();
	}

	// write custom spawn caption colors
	for (auto& CaptionColor : CaptionColors)
	{
		CaptionColor.Save();
	}

	AddMQ2Data("NamingSpawn", dataNamingSpawn);

	AddCommand("/caption", CaptionCmd, false, false);
	AddCommand("/captioncolor", CaptionColorCmd, false, false);

	AddSettingsPanel("Captions", CaptionsSettingsPanel);
}

static void Spawns_Shutdown()
{
	DebugSpew("Shutting Down Spawn-related Hooks");

	RemoveSettingsPanel("Captions");

	RemoveMQ2Data("NamingSpawn");

	RemoveCommand("/caption");
	RemoveCommand("/captioncolor");

	RemoveDetour(PlayerManagerClient__CreatePlayer);
	RemoveDetour(PlayerManagerBase__PrepForDestroyPlayer);
#if !IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
	RemoveDetour(PlayerManagerBase__DestroyAllPlayers);
#endif
	RemoveDetour(PlayerClient__SetNameSpriteState);
	RemoveDetour(PlayerClient__SetNameSpriteTint);
	RemoveDetour(EQItemList__FreeItemList);
	RemoveDetour(EQItemList__add_item);
	RemoveDetour(EQItemList__delete_item);

	ProcessPending = false;

	{
		std::scoped_lock lock(s_groundsMutex);

		while (pPendingGrounds)
		{
			MQGroundPending* pNext = pPendingGrounds->pNext;
			delete pPendingGrounds;
			pPendingGrounds = pNext;
		}
	}

	EQP_DistArray = nullptr;
	gSpawnCount = 0;
	gSpawnsArray.clear();

	RemoveMQ2Benchmark(bmUpdateSpawnSort);
	RemoveMQ2Benchmark(bmUpdateSpawnCaptions);
}

static void Spawns_Pulse()
{
	if (gGameState != GAMESTATE_INGAME)
		return;

	// update captions
	static unsigned long nCaptions = 100;
	static unsigned long LastTarget = 0;
	++nCaptions;

	if (LastTarget)
	{
		if (auto pSpawnTarget = GetSpawnByID(LastTarget))
		{
			if (pSpawnTarget != pTarget)
			{
				SetNameSpriteState(pSpawnTarget, false);
			}
		}

		LastTarget = 0;
	}

	if (nCaptions > CAPTION_UPDATE_FRAMES)
	{
		MQScopedBenchmark bm(bmUpdateSpawnCaptions);
		nCaptions = 0;
		
		UpdateSpawnCaptions();
	}

	if (pTarget)
	{
		LastTarget = pTarget->SpawnID;
		pTarget.get_as<PlayerClientHook>()->SetNameSpriteTint_Trampoline();
		SetNameSpriteState(pTarget, true);
	}

	ProcessPendingGroundItems();
}

static void Spawns_BeginZone()
{
	gSpawnsArray.clear();
}

static void Spawns_SpawnRemoved(PlayerClient* pSpawn)
{
	if (gSpawnsArray.empty())
		return;

	gSpawnsArray.erase(
		std::remove_if(std::begin(gSpawnsArray), std::end(gSpawnsArray),
			[pSpawn](const MQSpawnArrayItem& item) { return item.GetSpawn() == pSpawn; }),
		std::end(gSpawnsArray));
}

} // namespace mq
