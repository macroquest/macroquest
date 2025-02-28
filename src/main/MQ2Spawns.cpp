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
#include "MQDataAPI.h"
#include "MQPluginHandler.h"

namespace mq {

static void Spawns_Initialize();
static void Spawns_Shutdown();
static void Spawns_Pulse();
static void Spawns_BeginZone();
static void Spawns_SpawnAdded(PlayerClient* pSpawn);
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
	Spawns_SpawnAdded,            // SpawnAdded
	Spawns_SpawnRemoved,          // SpawnRemoved
	Spawns_BeginZone,             // BeginZone
};
MQModule* GetSpawnsModule() { return &gSpawnsModule; }

// Global spawn array, sorted by distance.
std::vector<MQSpawnArrayItem> gSpawnsArray;

// Our last known combat state
static ECombatState s_combatState = eCombatState_Standing;

static void UpdateNameSpriteTint(PlayerClient* pSpawn);
static bool UpdateNameSpriteState(PlayerClient* pSpawn, bool apply);

#pragma region Combat State Calculation
//----------------------------------------------------------------------------
// Combat State Calculation
//----------------------------------------------------------------------------
static void UpdateCombatState()
{
	ECombatState newState = eCombatState_Standing;

	if (gGameState == GAMESTATE_INGAME && pLocalPC)
	{
		if (pLocalPC->IsInCombat())
		{
			newState = eCombatState_Combat;
		}
		else if (pLocalPC->GetDowntime() > 0)
		{
			newState = eCombatState_Timer;
		}
		else
		{
			// Calculate debuff timer
			bool debuffed = false;

			for (int i = 0; i < pLocalPC->GetMaxEffects(); ++i)
			{
				EQ_Spell* spell = GetSpellByID(pLocalPC->GetEffect(i).SpellID);

				if (spell != nullptr 
					&& !spell->IsBeneficialSpell()
					&& !spell->BypassRegenCheck)
				{
					debuffed = true;
					break;
				}
			}

			if (debuffed)
			{
				newState = eCombatState_Debuff;
			}
			else if (pLocalPC->standstate != STANDSTATE_SIT && !pLocalPC->CanMedOnHorse())
			{
				newState = eCombatState_Standing;
			}
			else
			{
				newState = eCombatState_Regen;
			}
		}
	}

	if (s_combatState != newState)
	{
		s_combatState = newState;
	}
}

ECombatState GetCombatState()
{
	return s_combatState;
}

#pragma endregion

#pragma region Caption Colors
//----------------------------------------------------------------------------
// caption color code
//----------------------------------------------------------------------------

static PlayerClient* pNamingSpawn = nullptr;

static int gMaxSpawnCaptions = 35;
static bool gMQCaptions = true;

static constexpr int CAPTION_UPDATE_FRAMES = 20; // number of frames between caption updates

static char gszSpawnPlayerName[8][MAX_STRING] = {
	/* 0 */ "",
	/* 1 */ "${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}",
	/* 2 */ "${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length}, ${NamingSpawn.Surname},]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}",
	/* 3 */ "${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length}, ${NamingSpawn.Surname},]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}${If[${NamingSpawn.Guild.Length},\\n<${NamingSpawn.Guild}>,]}",
	/* 4 */ "${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.AARank},${NamingSpawn.AATitle} ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length}, ${NamingSpawn.Surname},]}${If[${NamingSpawn.Suffix.Length}~${If[${NamingSpawn.Suffix.Left[1].Equal[,]}~${NamingSpawn.Suffix}~ ${NamingSpawn.Suffix}]}~]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}${If[${NamingSpawn.Guild.Length},\\n<${NamingSpawn.Guild}>,]}",
	/* 5 */ "${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",
	/* 6 */ "${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",
};

static char gszSpawnNPCName[MAX_STRING] = "${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Assist},>> ,]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist}, - ${NamingSpawn.PctHPs}%<<,]}${If[${NamingSpawn.Surname.Length},\\n(${NamingSpawn.Surname}),]}";
static char gszSpawnPetName[MAX_STRING] = "${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Assist},>> ,]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist}, - ${NamingSpawn.PctHPs}%<<,]}${If[${NamingSpawn.Master.Type.Equal[PC]},\\n(${NamingSpawn.Master}),]}";
static char gszSpawnMercName[MAX_STRING] = "${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Assist},>> ,]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist}, - ${NamingSpawn.PctHPs}%<<,]}${If[${NamingSpawn.Owner.Type.Equal[PC]},\\n(${NamingSpawn.Owner}),]}";
static char gszSpawnCorpseName[MAX_STRING] = "${NamingSpawn.DisplayName}'s corpse";

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

enum eCaptionColor
{
	CC_PC = 0,
	CC_PCConColor = 1,
	CC_PCPVPTeamColor = 2,
	CC_PCRaidColor = 3,
	CC_PCClassColor = 4,
	CC_PCGroupColor = 5,
	CC_PCTrader = 6,
	CC_NPC = 7,
	CC_NPCConColor = 8,
	CC_NPCClassColor = 9,
	CC_NPCMerchant = 10,
	CC_NPCBanker = 11,
	CC_NPCAssist = 12,
	CC_NPCMark = 13,
	CC_PetNPC = 14,
	CC_PetPC = 15,
	CC_PetConColor = 16,
	CC_PetClassColor = 17,
	CC_Corpse = 18,
	CC_CorpseClassColor = 19,
};

struct CAPTIONCOLOR
{
	char* szName;
	char* szDescription;
	bool       Enabled;
	bool       ToggleOnly;
	DWORD      Color;
};

static CAPTIONCOLOR CaptionColors[] =
{
	// name          // description                           // enable // toggle // color
	{ "PC",          "Default color for PCs",                 false,    false,    0x00FF00FF },
	{ "PCCon",       "PCs by con color",                      false,    true,     0          },
	{ "PCPVPTeam",   "PCs by PVP team color",                 false,    true,     0          },
	{ "PCRaid",      "Raid members",                          false,    false,    0x0000FF7F },
	{ "PCClass",     "PCs by class color (raid settings)",    false,    true,     0          },
	{ "PCGroup",     "Group members",                         false,    false,    0x00FFFF00 },
	{ "PCTrader",    "Traders",                               true,     false,    0x00FF7F00 },
	{ "NPC",         "NPC default color",                     false,    false,    0x00FF0000 },
	{ "NPCCon",      "NPCs by con color",                     true,     true,     0          },
	{ "NPCClass",    "NPCs by class color (raid settings)",   false,    true,     0          },
	{ "NPCMerchant", "NPC Merchants",                         true,     false,    0x00FF7F00 },
	{ "NPCBanker",   "NPC Bankers",                           true,     false,    0x00C800FF },
	{ "NPCAssist",   "NPCs from main assist",                 true,     false,    0x00FFFF00 },
	{ "NPCMark",     "Marked NPCs",                           true,     false,    0x00FFFF00 },
	{ "PetNPC",      "Pet with NPC owner",                    false,    false,    0x00FF0000 },
	{ "PetPC",       "Pet with PC owner",                     false,    false,    0x00FFFF00 },
	{ "PetClass",    "Pet by class color (raid settings)",    false,    false,    0x00FF0000 },
	{ "Corpse",      "Corpses",                               false,    false,    0x00FF0000 },
	{ "CorpseClass", "Corpse by class color (raid settings)", false,    false,    0x00FF0000 },
	{ "",            "",                                      false,    false,    0          },
};


static void CaptionCmd(PlayerClient*, const char* szLine)
{
	char Arg1[MAX_STRING] = { 0 };
	GetArg(Arg1, szLine, 1);

	if (!Arg1[0])
	{
		SyntaxError("Usage: /caption <list|type <value>|update #|MQCaptions <on|off>>");
		return;
	}

	if (!_stricmp(Arg1, "list"))
	{
		WriteChatf("\ayPlayer1\ax: \ag%s\ax", gszSpawnPlayerName[1]);
		WriteChatf("\ayPlayer2\ax: \ag%s\ax", gszSpawnPlayerName[2]);
		WriteChatf("\ayPlayer3\ax: \ag%s\ax", gszSpawnPlayerName[3]);
		WriteChatf("\ayPlayer4\ax: \ag%s\ax", gszSpawnPlayerName[4]);
		WriteChatf("\ayPlayer5\ax: \ag%s\ax", gszSpawnPlayerName[5]);
		WriteChatf("\ayPlayer6\ax: \ag%s\ax", gszSpawnPlayerName[6]);

		WriteChatf("\ayNPC\ax: \ag%s\ax", gszSpawnNPCName);
		WriteChatf("\ayPet\ax: \ag%s\ax", gszSpawnPetName);
		WriteChatf("\ayMerc\ax: \ag%s\ax", gszSpawnMercName);
		WriteChatf("\ayCorpse\ax: \ag%s\ax", gszSpawnCorpseName);
		return;
	}

	char* pCaption = nullptr;

	if (!_stricmp(Arg1, "Player1"))
	{
		pCaption = gszSpawnPlayerName[1];
	}
	else if (!_stricmp(Arg1, "Player2"))
	{
		pCaption = gszSpawnPlayerName[2];
	}
	else if (!_stricmp(Arg1, "Player3"))
	{
		pCaption = gszSpawnPlayerName[3];
	}
	else if (!_stricmp(Arg1, "Player4"))
	{
		pCaption = gszSpawnPlayerName[4];
	}
	else if (!_stricmp(Arg1, "Player5"))
	{
		pCaption = gszSpawnPlayerName[5];
	}
	else if (!_stricmp(Arg1, "Player6"))
	{
		pCaption = gszSpawnPlayerName[6];
	}
	else if (!_stricmp(Arg1, "Pet"))
	{
		pCaption = gszSpawnPetName;
	}
	else if (!_stricmp(Arg1, "Merc"))
	{
		pCaption = gszSpawnMercName;
	}
	else if (!_stricmp(Arg1, "NPC"))
	{
		pCaption = gszSpawnNPCName;
	}
	else if (!_stricmp(Arg1, "Corpse"))
	{
		pCaption = gszSpawnCorpseName;
	}
	else if (!_stricmp(Arg1, "Update"))
	{
		gMaxSpawnCaptions = std::clamp(GetIntFromString(GetNextArg(szLine), 0), 8, 70);
		_itoa_s(gMaxSpawnCaptions, Arg1, 10);

		WritePrivateProfileString("Captions", "Update", Arg1, mq::internal_paths::MQini);
		WriteChatf("\ay%d\ax nearest spawns will have their caption updated each pass.", gMaxSpawnCaptions);
		return;
	}
	else if (!_stricmp(Arg1, "MQCaptions"))
	{
		gMQCaptions = (!_stricmp(GetNextArg(szLine), "On"));
		WritePrivateProfileBool("Captions", "MQCaptions", gMQCaptions, mq::internal_paths::MQini);
		WriteChatf("MQCaptions are now \ay%s\ax.", (gMQCaptions ? "On" : "Off"));
		return;
	}
	else if (!_stricmp(Arg1, "reload"))
	{
		GetPrivateProfileString("Captions", "NPC", gszSpawnNPCName, gszSpawnNPCName, MAX_STRING, mq::internal_paths::MQini);
		GetPrivateProfileString("Captions", "Player1", gszSpawnPlayerName[1], gszSpawnPlayerName[1], MAX_STRING, mq::internal_paths::MQini);
		GetPrivateProfileString("Captions", "Player2", gszSpawnPlayerName[2], gszSpawnPlayerName[2], MAX_STRING, mq::internal_paths::MQini);
		GetPrivateProfileString("Captions", "Player3", gszSpawnPlayerName[3], gszSpawnPlayerName[3], MAX_STRING, mq::internal_paths::MQini);
		GetPrivateProfileString("Captions", "Player4", gszSpawnPlayerName[4], gszSpawnPlayerName[4], MAX_STRING, mq::internal_paths::MQini);
		GetPrivateProfileString("Captions", "Player5", gszSpawnPlayerName[5], gszSpawnPlayerName[5], MAX_STRING, mq::internal_paths::MQini);
		GetPrivateProfileString("Captions", "Player6", gszSpawnPlayerName[6], gszSpawnPlayerName[6], MAX_STRING, mq::internal_paths::MQini);
		GetPrivateProfileString("Captions", "Corpse", gszSpawnCorpseName, gszSpawnCorpseName, MAX_STRING, mq::internal_paths::MQini);
		GetPrivateProfileString("Captions", "Pet", gszSpawnPetName, gszSpawnPetName, MAX_STRING, mq::internal_paths::MQini);
		GetPrivateProfileString("Captions", "Merc", gszSpawnMercName, gszSpawnMercName, MAX_STRING, mq::internal_paths::MQini);

		ConvertCR(gszSpawnNPCName, MAX_STRING);
		ConvertCR(gszSpawnPlayerName[1], MAX_STRING);
		ConvertCR(gszSpawnPlayerName[2], MAX_STRING);
		ConvertCR(gszSpawnPlayerName[3], MAX_STRING);
		ConvertCR(gszSpawnPlayerName[4], MAX_STRING);
		ConvertCR(gszSpawnPlayerName[5], MAX_STRING);
		ConvertCR(gszSpawnPlayerName[6], MAX_STRING);
		ConvertCR(gszSpawnCorpseName, MAX_STRING);
		ConvertCR(gszSpawnPetName, MAX_STRING);
		ConvertCR(gszSpawnMercName, MAX_STRING);

		WriteChatf("Updated Captions from INI.");
		return;
	}
	else if (ci_equals(Arg1, "anon"))
	{
		MacroError("Anon is no longer accessed through /caption, please use /mqanon");
		return;
	}
	else
	{
		MacroError("Invalid caption type '%s'", Arg1);
		return;
	}

	strcpy_s(pCaption, MAX_STRING, GetNextArg(szLine));
	WritePrivateProfileString("Captions", Arg1, pCaption, mq::internal_paths::MQini);
	ConvertCR(pCaption, MAX_STRING);
	WriteChatf("\ay%s\ax caption set.", Arg1);
}

static void CaptionColorCmd(PlayerClient*, const char* szLine)
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

	if (!_stricmp(Arg1, "list"))
	{
		WriteChatColor("Caption Color Settings");
		WriteChatColor("----------------------");

		for (int index = 0; CaptionColors[index].szName[0]; index++)
		{
			if (!CaptionColors[index].Enabled || CaptionColors[index].ToggleOnly)
				WriteChatf("%s %s (%s)", CaptionColors[index].szName, CaptionColors[index].Enabled ? "ON" : "OFF", CaptionColors[index].szDescription);
			else
			{
				ARGBCOLOR Color;
				Color.ARGB = CaptionColors[index].Color;
				WriteChatf("%s ON Color: %d %d %d. (%s)", CaptionColors[index].szName, Color.R, Color.G, Color.B, CaptionColors[index].szDescription);
			}
		}

		return;
	}

	for (int index = 0; CaptionColors[index].szName[0]; index++)
	{
		if (!_stricmp(Arg1, CaptionColors[index].szName))
		{
			if (Arg2[0])
			{
				if (!_stricmp(Arg2, "on"))
					CaptionColors[index].Enabled = true;
				else if (!_stricmp(Arg2, "off"))
					CaptionColors[index].Enabled = false;
				else if (CaptionColors[index].Enabled && !CaptionColors[index].ToggleOnly)
				{
					ARGBCOLOR NewColor;
					NewColor.A = 0;
					NewColor.R = GetIntFromString(Arg2, 0);
					NewColor.G = GetIntFromString(GetArg(Arg2, szLine, 3), 0);
					NewColor.B = GetIntFromString(GetArg(Arg2, szLine, 4), 0);
					CaptionColors[index].Color = NewColor.ARGB;
				}
				else
				{
					MacroError("Invalid option '%s' while '%s' is off.", Arg2, Arg1);
					return;
				}
			}

			if (!CaptionColors[index].Enabled || CaptionColors[index].ToggleOnly)
			{
				WriteChatf("%s %s (%s)", CaptionColors[index].szName, CaptionColors[index].Enabled ? "ON" : "OFF", CaptionColors[index].szDescription);
			}
			else
			{
				ARGBCOLOR Color;
				Color.ARGB = CaptionColors[index].Color;
				WriteChatf("%s ON Color: %d %d %d. (%s)", CaptionColors[index].szName, Color.R, Color.G, Color.B, CaptionColors[index].szDescription);
			}

			WritePrivateProfileString("Caption Colors", CaptionColors[index].szName, CaptionColors[index].Enabled ? "ON" : "OFF", mq::internal_paths::MQini);

			if (!CaptionColors[index].ToggleOnly)
			{
				sprintf_s(Arg2, "%x", CaptionColors[index].Color);
				sprintf_s(Arg1, "%s-Color", CaptionColors[index].szName);
				WritePrivateProfileString("Caption Colors", Arg1, Arg2, mq::internal_paths::MQini);
			}

			return;
		}
	}
}

static unsigned int lastRemovedSpawnID = 0;

class PlayerManagerBaseHook : public eqlib::PlayerManagerBase
{
public:
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_LS)
	DETOUR_TRAMPOLINE_DEF(PlayerClient*, PrepForDestroyPlayer_Trampoline, (PlayerClient*, bool b))
		PlayerClient* PrepForDestroyPlayer_Detour(PlayerClient* spawn, bool b)
	{
		// PrepForDestroyPlayer can be called twice through the same code path
		if (lastRemovedSpawnID != spawn->GetId())
		{
			lastRemovedSpawnID = spawn->GetId();
			PluginsRemoveSpawn(spawn);
		}
		return PrepForDestroyPlayer_Trampoline(spawn, b);
	}
#else
	DETOUR_TRAMPOLINE_DEF(PlayerClient*, PrepForDestroyPlayer_Trampoline, (PlayerClient*))
	PlayerClient* PrepForDestroyPlayer_Detour(PlayerClient* spawn)
	{
		// PrepForDestroyPlayer can be called twice through the same code path
		if (lastRemovedSpawnID != spawn->GetId())
		{
			lastRemovedSpawnID = spawn->GetId();
			PluginsRemoveSpawn(spawn);
		}
		return PrepForDestroyPlayer_Trampoline(spawn);
	}
#endif

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
		// Set the last removed spawn to zero if the ID was reused
		if (lastRemovedSpawnID == spawn->GetId())
		{
			lastRemovedSpawnID = 0;
		}
		return spawn;
	}
#else
	DETOUR_TRAMPOLINE_DEF(PlayerClient*, CreatePlayer_Trampoline, (CUnSerializeBuffer*, void*, void*, void*, void*, void*, void*, void*))
		PlayerClient* CreatePlayer_Detour(CUnSerializeBuffer* buf, void* a, void* b, void* c, void* d, void* e, void* f, void* g)
	{
		PlayerClient* spawn = CreatePlayer_Trampoline(buf, a, b, c, d, e, f, g);
		PluginsAddSpawn(spawn);
		// Set the last removed spawn to zero if the ID was reused
		if (lastRemovedSpawnID == spawn->GetId())
		{
			lastRemovedSpawnID = 0;
		}
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

	static int SetNameSpriteState(PlayerClient* pSpawn, bool show)
	{
		return reinterpret_cast<PlayerClientHook*>(pSpawn)->SetNameSpriteState_Trampoline(show);
	}

	DETOUR_TRAMPOLINE_DEF(bool, SetNameSpriteTint_Trampoline, ())
	bool SetNameSpriteTint_Detour()
	{
		if (gGameState != GAMESTATE_INGAME || !gMQCaptions)
			return SetNameSpriteTint_Trampoline();

		return true;
	}
};

static void UpdateNameSpriteTint(PlayerClient* pSpawn)
{
	if (!gMQCaptions)
		return;

	DWORD NewColor;
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
		else if (CaptionColors[CC_PCPVPTeamColor].Enabled)
		{
			// TODO
		}
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

	case OBJECT:
	case MERCENARY:
	case UNTARGETABLE:
		pHook->SetNameSpriteTint_Trampoline();
		return;
	}

	if (pSpawn->GetActor())
		pSpawn->GetActor()->SetStringSpriteTint((RGB*)&NewColor);
}

static bool SetCaption(PlayerClient* pSpawn, const char* CaptionString)
{
	if (CaptionString[0])
	{
		pNamingSpawn = pSpawn;

		std::string str = ModifyMacroString(CaptionString);

		if (MaybeAnonymize(str))
		{
			pSpawn->ChangeBoneStringSprite(0, Anonymize(CXStr{ str }).c_str());
		}
		else
		{
			pSpawn->ChangeBoneStringSprite(0, str.c_str());
		}

		pNamingSpawn = nullptr;
		return true;
	}

	return false;
}

static bool UpdateNameSpriteState(PlayerClient* pSpawn, bool apply)
{
	if (!apply || !gMQCaptions)
	{
		return PlayerClientHook::SetNameSpriteState(pSpawn, apply) != 0;
	}

	if (!pSpawn->GetActor() || !pSpawn->GetActor()->IsBoneSet(0))
	{
		return true;
	}

	switch (GetSpawnType(pSpawn))
	{
	case NPC:
		if (SetCaption(pSpawn, gszSpawnNPCName))
			return true;
		break;

	case PC:
		if (!pEverQuestInfo->gOpt.pcNames && pSpawn != pTarget)
			return false;
		if (SetCaption(pSpawn, gszSpawnPlayerName[IsAnonymized() ? 1 : pEverQuestInfo->iShowNamesLevel]))
			return true;
		break;

	case CORPSE:
		if (SetCaption(pSpawn, gszSpawnCorpseName))
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
		if (SetCaption(pSpawn, gszSpawnPetName))
			return true;
		break;

	case MERCENARY:
		if (SetCaption(pSpawn, gszSpawnMercName))
			return true;
		break;
	}

	return PlayerClientHook::SetNameSpriteState(pSpawn, apply) != 0;
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

		if (UpdateNameSpriteState(pSpawn, true))
		{
			UpdateNameSpriteTint(pSpawn);
			++count;
		}

		if (count >= gMaxSpawnCaptions)
			break;
	}
}

static void LoadCaptionSettings()
{
	const auto& iniFile = mq::internal_paths::MQini;

	GetPrivateProfileString("Captions", "NPC", gszSpawnNPCName, gszSpawnNPCName, MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Player1", gszSpawnPlayerName[1], gszSpawnPlayerName[1], MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Player2", gszSpawnPlayerName[2], gszSpawnPlayerName[2], MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Player3", gszSpawnPlayerName[3], gszSpawnPlayerName[3], MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Player4", gszSpawnPlayerName[4], gszSpawnPlayerName[4], MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Player5", gszSpawnPlayerName[5], gszSpawnPlayerName[5], MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Player6", gszSpawnPlayerName[6], gszSpawnPlayerName[6], MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Corpse", gszSpawnCorpseName, gszSpawnCorpseName, MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Pet", gszSpawnPetName, gszSpawnPetName, MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Merc", gszSpawnMercName, gszSpawnMercName, MAX_STRING, iniFile);

	gMaxSpawnCaptions = GetPrivateProfileInt("Captions", "Update", gMaxSpawnCaptions, iniFile);
	gMQCaptions = GetPrivateProfileBool("Captions", "MQCaptions", gMQCaptions, iniFile);

	if (gbWriteAllConfig)
	{
		WritePrivateProfileString("Captions", "NPC", gszSpawnNPCName, iniFile);
		WritePrivateProfileString("Captions", "Player1", gszSpawnPlayerName[1], iniFile);
		WritePrivateProfileString("Captions", "Player2", gszSpawnPlayerName[2], iniFile);
		WritePrivateProfileString("Captions", "Player3", gszSpawnPlayerName[3], iniFile);
		WritePrivateProfileString("Captions", "Player4", gszSpawnPlayerName[4], iniFile);
		WritePrivateProfileString("Captions", "Player5", gszSpawnPlayerName[5], iniFile);
		WritePrivateProfileString("Captions", "Player6", gszSpawnPlayerName[6], iniFile);
		WritePrivateProfileString("Captions", "Corpse", gszSpawnCorpseName, iniFile);
		WritePrivateProfileString("Captions", "Pet", gszSpawnPetName, iniFile);
		WritePrivateProfileString("Captions", "Merc", gszSpawnMercName, iniFile);

		WritePrivateProfileInt("Captions", "Update", gMaxSpawnCaptions, iniFile);
		WritePrivateProfileBool("Captions", "MQCaptions", gMQCaptions, iniFile);
	}

	ConvertCR(gszSpawnNPCName, MAX_STRING);
	ConvertCR(gszSpawnPlayerName[1], MAX_STRING);
	ConvertCR(gszSpawnPlayerName[2], MAX_STRING);
	ConvertCR(gszSpawnPlayerName[3], MAX_STRING);
	ConvertCR(gszSpawnPlayerName[4], MAX_STRING);
	ConvertCR(gszSpawnPlayerName[5], MAX_STRING);
	ConvertCR(gszSpawnPlayerName[6], MAX_STRING);
	ConvertCR(gszSpawnCorpseName, MAX_STRING);
	ConvertCR(gszSpawnPetName, MAX_STRING);
	ConvertCR(gszSpawnMercName, MAX_STRING);
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
	for (int index = 0; CaptionColors[index].szName[0]; index++)
	{
		if (GetPrivateProfileString("Caption Colors", CaptionColors[index].szName, "", Temp, MAX_STRING, mq::internal_paths::MQini))
		{
			if (!_stricmp(Temp, "on") || !_stricmp(Temp, "1"))
				CaptionColors[index].Enabled = true;
			else
				CaptionColors[index].Enabled = false;
		}

		sprintf_s(Name, "%s-Color", CaptionColors[index].szName);

		if (GetPrivateProfileString("Caption Colors", Name, "", Temp, MAX_STRING, mq::internal_paths::MQini))
		{
			if (!sscanf_s(Temp, "%x", &CaptionColors[index].Color))
			{
				// should handle this i guess
				continue;
			}
		}
	}

	// write custom spawn caption colors
	for (int index = 0; CaptionColors[index].szName[0]; index++)
	{
		WritePrivateProfileString("Caption Colors", CaptionColors[index].szName, CaptionColors[index].Enabled ? "ON" : "OFF", mq::internal_paths::MQini);

		if (!CaptionColors[index].ToggleOnly)
		{
			sprintf_s(Temp, "%x", CaptionColors[index].Color);
			sprintf_s(Name, "%s-Color", CaptionColors[index].szName);
			WritePrivateProfileString("Caption Colors", Name, Temp, mq::internal_paths::MQini);
		}
	}

	pDataAPI->AddTopLevelObject("NamingSpawn", dataNamingSpawn);

	AddCommand("/caption", CaptionCmd, false, false);
	AddCommand("/captioncolor", CaptionColorCmd, false, false);
}

static void Spawns_Shutdown()
{
	DebugSpew("Shutting Down Spawn-related Hooks");

	pDataAPI->RemoveTopLevelObject("NamingSpawn");

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
	UpdateCombatState();

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
				UpdateNameSpriteState(pSpawnTarget, false);
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
		UpdateNameSpriteState(pTarget, true);
	}

	ProcessPendingGroundItems();
}

static void Spawns_BeginZone()
{
	gSpawnsArray.clear();
}

void Spawns_SpawnAdded(PlayerClient* pNewSpawn)
{
	if (!gMQCaptions)
		return;

	UpdateNameSpriteState(pNewSpawn, true);
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

//----------------------------------------------------------------------------
// Utility Functions
//----------------------------------------------------------------------------

PlayerClient* GetClosestBanker(bool forInteraction)
{
	// gSpawnsArray is sorted by distance from the player, so the first banker we find will be the closest
	for (const auto& spawn : gSpawnsArray)
	{
		if (forInteraction && spawn.GetDistanceSquared() > MAX_INTERACT_DISTANCE_SQUARED)
			break;

		if (auto pSpawn = spawn.GetSpawn())
		{
			if (pSpawn->GetClass() == Class_Banker)
				return pSpawn;
		}
	}

	return nullptr;
}

} // namespace mq
