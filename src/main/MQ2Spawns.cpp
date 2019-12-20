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

#include "pch.h"
#include "MQ2Main.h"

namespace mq {

#pragma region Caption Colors
//----------------------------------------------------------------------------
// caption color code
//----------------------------------------------------------------------------

static SPAWNINFO* pNamingSpawn = nullptr;

static int gMaxSpawnCaptions = 30;
static bool gMQCaptions = true;

static char gszSpawnPlayerName[8][MAX_STRING] = {
	/* 0 */ "",
	/* 1 */ "${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}",
	/* 2 */ "${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length}, ${NamingSpawn.Surname},]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}",
	/* 3 */ "${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length}, ${NamingSpawn.Surname},]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}${If[${NamingSpawn.Guild.Length},\n<${If[${NamingSpawn.GuildStatus.NotEqual[member]},${NamingSpawn.GuildStatus} of ,]}${NamingSpawn.Guild}>,]}",
	/* 4 */ "${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.AARank},${NamingSpawn.AATitle} ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length}, ${NamingSpawn.Surname},]}${If[${NamingSpawn.Suffix.Length}~${If[${NamingSpawn.Suffix.Left[1].Equal[,]}~${NamingSpawn.Suffix}~ ${NamingSpawn.Suffix}]}~]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}${If[${NamingSpawn.Guild.Length},\n<${If[${NamingSpawn.GuildStatus.NotEqual[member]},${NamingSpawn.GuildStatus} of ,]}${NamingSpawn.Guild}>,]}",
	/* 5 */ "${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",
	/* 6 */ "${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",
};

static char gszSpawnNPCName[MAX_STRING] = "${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Assist},>> ,]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist}, - ${NamingSpawn.PctHPs}%<<,]}${If[${NamingSpawn.Surname.Length},\n(${NamingSpawn.Surname}),]}";
static char gszSpawnPetName[MAX_STRING] = "${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Assist},>> ,]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist}, - ${NamingSpawn.PctHPs}%<<,]}${If[${NamingSpawn.Master.Type.Equal[PC]},\n(${NamingSpawn.Master}),]}";
static char gszSpawnCorpseName[MAX_STRING] = "${NamingSpawn.DisplayName}'s corpse";
static char gszAnonCaption[MAX_STRING] = "[${NamingSpawn.Level}] ${NamingSpawn.Race} ${NamingSpawn.Class} ${NamingSpawn.Type}";

// TLO used for controlling what we are currently naming.
static bool dataNamingSpawn(const char* szIndex, MQTypeVar& Ret)
{
	if (Ret.Ptr = pNamingSpawn)
	{
		Ret.Type = pSpawnType;
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


static void CaptionCmd(SPAWNINFO* pChar, char* szLine)
{
	char Arg1[MAX_STRING] = { 0 };
	GetArg(Arg1, szLine, 1);

	if (!Arg1[0])
	{
		SyntaxError("Usage: /caption <list|type <value>|update #|MQCaptions <on|off>|Anon <on|off>>");
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
		WritePrivateProfileString("Captions", "MQCaptions", (gMQCaptions ? "1" : "0"), mq::internal_paths::MQini);
		WriteChatf("MQCaptions are now \ay%s\ax.", (gMQCaptions ? "On" : "Off"));
		return;
	}
	else if (!_stricmp(Arg1, "Anon"))
	{
		gAnonymize = (!_stricmp(GetNextArg(szLine), "On"));
		UpdatedMasterLooterLabel();
		WritePrivateProfileString("Captions", "Anonymize", (gAnonymize ? "1" : "0"), mq::internal_paths::MQini);
		WriteChatf("Anonymize is now \ay%s\ax.", (gAnonymize ? "On" : "Off"));
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
		GetPrivateProfileString("Captions", "AnonCaption", gszAnonCaption, gszAnonCaption, MAX_STRING, mq::internal_paths::MQini);

		ConvertCR(gszSpawnNPCName, MAX_STRING);
		ConvertCR(gszSpawnPlayerName[1], MAX_STRING);
		ConvertCR(gszSpawnPlayerName[2], MAX_STRING);
		ConvertCR(gszSpawnPlayerName[3], MAX_STRING);
		ConvertCR(gszSpawnPlayerName[4], MAX_STRING);
		ConvertCR(gszSpawnPlayerName[5], MAX_STRING);
		ConvertCR(gszSpawnPlayerName[6], MAX_STRING);
		ConvertCR(gszSpawnCorpseName, MAX_STRING);
		ConvertCR(gszSpawnPetName, MAX_STRING);
		ConvertCR(gszAnonCaption, MAX_STRING);

		WriteChatf("Updated Captions from INI.");
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

static void CaptionColorCmd(SPAWNINFO* pChar, char* szLine)
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
					CaptionColors[index].Enabled = 1;
				else if (!_stricmp(Arg2, "off"))
					CaptionColors[index].Enabled = 0;
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

void SetNameSpriteTint(SPAWNINFO* pSpawn);

class EQPlayerHook
{
public:
	void EQPlayer_ExtraDetour(SPAWNINFO* pSpawn)
	{
		// note: we need to keep the original registers.
		__asm push eax;
		__asm push ebx;
		__asm push ecx;
		__asm push edx;
		__asm push esi;
		__asm push edi;

		PluginsAddSpawn(pSpawn);

		__asm pop edi;
		__asm pop esi;
		__asm pop edx;
		__asm pop ecx;
		__asm pop ebx;
		__asm pop eax;
	}

	void EQPlayer_Trampoline(void*, int, int, int, char*, char*, char*);
	void EQPlayer_Detour(void* pNetPlayer, int Sex, int Race, int Class, char* PlayerName, char* GroupName, char* ReplaceName)
	{
		SPAWNINFO* pSpawn = (SPAWNINFO*)this;

		__asm mov [pSpawn], ecx;

		EQPlayer_Trampoline(pNetPlayer, Sex, Race, Class, PlayerName, GroupName, ReplaceName);
		EQPlayer_ExtraDetour(pSpawn);
	}

	void dEQPlayer_Trampoline();
	void dEQPlayer_Detour()
	{
		void (EQPlayerHook::*tmp)() = &EQPlayerHook::dEQPlayer_Trampoline;

		__asm {
			push ecx;
			push ecx;

			call PluginsRemoveSpawn;

			pop ecx;
			pop ecx;

			call [tmp];
		};
	}

	int SetNameSpriteState_Trampoline(bool Show);
	int SetNameSpriteState_Detour(bool Show)
	{
		if (!gAnonymize && (gGameState != GAMESTATE_INGAME || !Show || !gMQCaptions))
			return SetNameSpriteState_Trampoline(Show);

		return 1;
	}

	bool SetNameSpriteTint_Trampoline();
	bool SetNameSpriteTint_Detour()
	{
		if (!gAnonymize && (gGameState != GAMESTATE_INGAME || !gMQCaptions))
			return SetNameSpriteTint_Trampoline();

		return true;
	}

	// FIXME: Move to the correct class
	bool IsTargetable();

};
FUNCTION_AT_ADDRESS(bool EQPlayerHook::IsTargetable(), EQPlayer__IsTargetable);

class CActorEx
{
public:
	bool CanSetName(DWORD);
	void SetNameColor(DWORD& Color);
	void ChangeBoneStringSprite(int, int, char*);
};

FUNCTION_AT_VIRTUAL_ADDRESS(void CActorEx::ChangeBoneStringSprite(int, int, char*), 0x190);
FUNCTION_AT_VIRTUAL_ADDRESS(void CActorEx::SetNameColor(DWORD& Color), 0x194);
FUNCTION_AT_VIRTUAL_ADDRESS(bool CActorEx::CanSetName(DWORD), 0x1a8);

static void SetNameSpriteTint(SPAWNINFO* pSpawn)
{
	if (!gMQCaptions)
		return;

	DWORD NewColor;
	EQPlayerHook* pHook = (EQPlayerHook*)pSpawn;

	switch (GetSpawnType(pSpawn))
	{
	case PC:
		if (pSpawn->Trader && CaptionColors[CC_PCTrader].Enabled)
			NewColor = CaptionColors[CC_PCTrader].Color;
		else if (CaptionColors[CC_PCGroupColor].Enabled && IsGroupMember(pSpawn))
			NewColor = CaptionColors[CC_PCGroupColor].Color;
		else if (CaptionColors[CC_PCClassColor].Enabled)
			NewColor = pRaidWnd->ClassColors[ClassInfo[pSpawn->mActorClient.Class].RaidColorOrder];
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
		else if (CaptionColors[CC_NPCBanker].Enabled && pSpawn->mActorClient.Class == 40)
			NewColor = CaptionColors[CC_NPCBanker].Color;
		else if (CaptionColors[CC_NPCMerchant].Enabled && (pSpawn->mActorClient.Class == 41 || pSpawn->mActorClient.Class == 61))
			NewColor = CaptionColors[CC_NPCMerchant].Color;
		else if (CaptionColors[CC_NPCClassColor].Enabled && pSpawn->mActorClient.Class < 0x10)
			NewColor = pRaidWnd->ClassColors[ClassInfo[pSpawn->mActorClient.Class].RaidColorOrder];
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
			NewColor = pRaidWnd->ClassColors[ClassInfo[pSpawn->mActorClient.Class].RaidColorOrder];
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
			NewColor = pRaidWnd->ClassColors[ClassInfo[pSpawn->mActorClient.Class].RaidColorOrder];
		else if (CaptionColors[CC_PetConColor].Enabled)
			NewColor = ConColorToARGB(ConColor(pSpawn));
		else if (CaptionColors[CC_PetNPC].Enabled && ((SPAWNINFO*)GetSpawnByID(pSpawn->MasterID))->Type == SPAWN_NPC)
			NewColor = CaptionColors[CC_PetNPC].Color;
		else if (CaptionColors[CC_PetPC].Enabled && ((SPAWNINFO*)GetSpawnByID(pSpawn->MasterID))->Type == SPAWN_PLAYER)
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

	if (pSpawn->mActorClient.pcactorex)
		DebugTry(((CActorEx*)pSpawn->mActorClient.pcactorex)->SetNameColor(NewColor));
	else
	{
#ifdef _DEBUG
		WriteChatf("We got an Empty pSpawn->pcactorex at %x class = 0x%x ", pSpawn, pSpawn->mActorClient.Class);
#endif
	}
}

static bool SetCaption(SPAWNINFO* pSpawn, const char* CaptionString, eSpawnType type)
{
	char NewCaption[MAX_STRING] = { 0 };

	if (CaptionString[0] || gAnonymize)
	{
		if (CHARINFO* pChar = GetCharInfo())
		{
			strcpy_s(NewCaption, CaptionString);
			pNamingSpawn = pSpawn;

			if (gAnonymize)
			{
				char szType[64] = { 0 };
				bool okToAnon = false;

				switch (type)
				{
				case MERCENARY:
					okToAnon = true;
					strcpy_s(szType, "Mercenary");
					break;

				case NPC:
					ParseMacroParameter(pChar->pSpawn, NewCaption);
					break;

				case PC:
					okToAnon = true;
					strcpy_s(szType, "Player");
					break;

				case PET:
					if (pSpawn->MasterID)
					{
						SPAWNINFO* petMaster = (SPAWNINFO*)GetSpawnByID(pSpawn->MasterID);

						if (petMaster && petMaster->Type == SPAWN_PLAYER)
						{
							okToAnon = true;
							strcpy_s(szType, "PET");
						}
						else
						{
							ParseMacroParameter(pChar->pSpawn, NewCaption);
						}
					}
					break;

				case CORPSE:
					if (pSpawn->Deity)
					{
						okToAnon = true;
						strcpy_s(szType, "CORPSE");
					}
					else
					{
						ParseMacroParameter(pChar->pSpawn, NewCaption);
					}
					break;
				};

				if (okToAnon)
				{
					if (!gszAnonCaption[0])
					{
						const char* theRace = pEverQuest->GetRaceDesc(pSpawn->mActorClient.Race);
						const char* theClass = pEverQuest->GetClassDesc(pSpawn->mActorClient.Class);

						sprintf_s(NewCaption, "[%d] %s %s %s", pSpawn->Level, theRace, theClass, szType);
					}
					else
					{
						strcpy_s(NewCaption, gszAnonCaption);
						ParseMacroParameter(pChar->pSpawn, NewCaption);
					}
				}
			}
			else
			{
				ParseMacroParameter(pChar->pSpawn, NewCaption);
			}

			pNamingSpawn = nullptr;
		}

		((PlayerClient*)pSpawn)->ChangeBoneStringSprite(0, NewCaption);
		return true;
	}
	return false;
}

static bool SetNameSpriteState(SPAWNINFO* pSpawn, bool Show)
{
	//DebugSpew("SetNameSpriteState(%s) --race %d body %d)",pSpawn->Name,pSpawn->Race,GetBodyType(pSpawn));
	if (!Show)
	{
		((EQPlayerHook*)pSpawn)->SetNameSpriteState_Trampoline(Show);
	}

	if (!gMQCaptions && !gAnonymize)
	{
		return ((EQPlayerHook*)pSpawn)->SetNameSpriteState_Trampoline(Show);
	}

	if (!pSpawn->mActorClient.pcactorex || !((CActorEx*)pSpawn->mActorClient.pcactorex)->CanSetName(0))
	{
		return true;
	}

	switch (GetSpawnType(pSpawn))
	{
	case MERCENARY:
		if (gAnonymize)
		{
			if (SetCaption(pSpawn, "", MERCENARY))
				return true;
		}
		break;

	case NPC:
		if (SetCaption(pSpawn, gszSpawnNPCName, NPC))
			return true;
		break;

	case PC:
		if (!gPCNames && pSpawn != (SPAWNINFO*)pTarget)
			return false;
		if (SetCaption(pSpawn, gszSpawnPlayerName[gShowNames], PC))
			return true;
		break;

	case CORPSE:
		if (SetCaption(pSpawn, gszSpawnCorpseName, CORPSE))
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
		if (SetCaption(pSpawn, gszSpawnPetName, PET))
			return true;
		break;
	}

	return ((EQPlayerHook*)pSpawn)->SetNameSpriteState_Trampoline(Show) != 0;
}

static void UpdateSpawnCaptions()
{
	int Count = 0;
	for (int index = 0; index < 120; index++)
	{
		SPAWNINFO* pSpawn = (SPAWNINFO*)EQP_DistArray[index].VarPtr.Ptr;
		if (!pSpawn || pSpawn == (SPAWNINFO*)pTarget)
			continue;

		if (gAnonymize || (EQP_DistArray[index].Value.Float <= 80.0f && gMQCaptions))
		{
			if (SetNameSpriteState(pSpawn, true))
			{
				SetNameSpriteTint(pSpawn);
				Count++;

				if (Count >= gMaxSpawnCaptions)
				{
					return;
				}
			}
		}
		else
		{
			return;
		}
	}
}

DETOUR_TRAMPOLINE_EMPTY(bool EQPlayerHook::SetNameSpriteTint_Trampoline());
DETOUR_TRAMPOLINE_EMPTY(int EQPlayerHook::SetNameSpriteState_Trampoline(bool Show));
DETOUR_TRAMPOLINE_EMPTY(void EQPlayerHook::dEQPlayer_Trampoline());
DETOUR_TRAMPOLINE_EMPTY(void EQPlayerHook::EQPlayer_Trampoline(void*, int, int, int, char*, char*, char*));

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

	gMaxSpawnCaptions = GetPrivateProfileInt("Captions", "Update", gMaxSpawnCaptions, iniFile);
	gMQCaptions = GetPrivateProfileBool("Captions", "MQCaptions", gMQCaptions, iniFile);

	GetPrivateProfileString("Captions", "AnonCaption", gszAnonCaption, gszAnonCaption, MAX_STRING, iniFile);

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

		WritePrivateProfileString("Captions", "Update", std::to_string(gMaxSpawnCaptions), iniFile);
		WritePrivateProfileString("Captions", "MQCaptions", std::to_string(gMQCaptions), iniFile);

		WritePrivateProfileString("Captions", "AnonCaption", gszAnonCaption, iniFile);
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
	ConvertCR(gszAnonCaption, MAX_STRING);
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
	if (GROUNDITEM* pGroundItem = *(GROUNDITEM**)pItemList)
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

static void RemoveGroundItem(GROUNDITEM* pGroundItem)
{
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

	void FreeItemList_Trampoline();
	void FreeItemList_Detour()
	{
		GROUNDITEM* pItem = *(GROUNDITEM**)pItemList;

		while (pItem)
		{
			RemoveGroundItem(pItem);

			pItem = pItem->pNext;
		}

		FreeItemList_Trampoline();
	}

	void Add_Trampoline(GROUNDITEM*);
	void Add_Detour(GROUNDITEM* pItem)
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

	void DeleteItem_Trampoline(GROUNDITEM*);
	void DeleteItem_Detour(GROUNDITEM* pItem)
	{
		RemoveGroundItem(pItem);
		return DeleteItem_Trampoline(pItem);
	}
};
DETOUR_TRAMPOLINE_EMPTY(void MyEQGroundItemListManager::FreeItemList_Trampoline());
DETOUR_TRAMPOLINE_EMPTY(void MyEQGroundItemListManager::Add_Trampoline(GROUNDITEM*));
DETOUR_TRAMPOLINE_EMPTY(void MyEQGroundItemListManager::DeleteItem_Trampoline(GROUNDITEM*));

void ProcessPendingGroundItems()
{
	if (gGameState != GAMESTATE_INGAME)
		return;
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
	if (gGameState != GAMESTATE_INGAME)
		return;

	EnterMQ2Benchmark(bmUpdateSpawnSort);
	ZeroMemory(EQP_DistArray, sizeof(EQP_DistArray));
	gSpawnCount = 0;

	SPAWNINFO* pSpawn = (SPAWNINFO*)pSpawnList;
	while (pSpawn)
	{
		EQP_DistArray[gSpawnCount].VarPtr.Ptr = pSpawn;
		EQP_DistArray[gSpawnCount].Value.Float = GetDistance(pSpawn->X, pSpawn->Y);
		gSpawnCount++;
		pSpawn = pSpawn->pNext;
	}

	std::sort(EQP_DistArray, EQP_DistArray + gSpawnCount, MQRankFloatCompare);
	ExitMQ2Benchmark(bmUpdateSpawnSort);

	static unsigned long nCaptions = 100;
	static unsigned long LastTarget = 0;
	++nCaptions;

	if (LastTarget)
	{
		if (SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(LastTarget))
		{
			if (pSpawn != (SPAWNINFO*)pTarget)
			{
				SetNameSpriteState(pSpawn, false);
			}
		}
		LastTarget = 0;
	}

	if (nCaptions > 7)
	{
		nCaptions = 0;
		Benchmark(bmUpdateSpawnCaptions, UpdateSpawnCaptions());
	}

	if (pTarget)
	{
		LastTarget = ((SPAWNINFO*)pTarget)->SpawnID;
		((EQPlayerHook*)pTarget)->SetNameSpriteTint_Trampoline();
		SetNameSpriteState((SPAWNINFO*)pTarget, true);
	}
}

void InitializeMQ2Spawns()
{
	DebugSpew("Initializing Spawn-related Hooks");

	bmUpdateSpawnSort = AddMQ2Benchmark("UpdateSpawnSort");
	bmUpdateSpawnCaptions = AddMQ2Benchmark("UpdateSpawnCaptions");

	EzDetourwName(EQPlayer__EQPlayer, &EQPlayerHook::EQPlayer_Detour, &EQPlayerHook::EQPlayer_Trampoline, "EQPlayer__EQPlayer");
	EzDetourwName(EQPlayer__dEQPlayer, &EQPlayerHook::dEQPlayer_Detour, &EQPlayerHook::dEQPlayer_Trampoline, "EQPlayer__dEQPlayer");
	EzDetourwName(EQPlayer__SetNameSpriteState, &EQPlayerHook::SetNameSpriteState_Detour, &EQPlayerHook::SetNameSpriteState_Trampoline, "EQPlayer__SetNameSpriteState");
	EzDetourwName(EQPlayer__SetNameSpriteTint, &EQPlayerHook::SetNameSpriteTint_Detour, &EQPlayerHook::SetNameSpriteTint_Trampoline, "EQPlayer__SetNameSpriteTint");
	EzDetourwName(EQItemList__FreeItemList, &MyEQGroundItemListManager::FreeItemList_Detour, &MyEQGroundItemListManager::FreeItemList_Trampoline, "EQItemList__FreeItemList");
	EzDetourwName(EQItemList__add_item, &MyEQGroundItemListManager::Add_Detour, &MyEQGroundItemListManager::Add_Trampoline, "EQGroundItemListManager__add");
	EzDetourwName(EQItemList__delete_item, &MyEQGroundItemListManager::DeleteItem_Detour, &MyEQGroundItemListManager::DeleteItem_Trampoline, "EQItemList__delete_item");

	// Load Settings
	LoadCaptionSettings();

	ProcessPending = true;
	ZeroMemory(&EQP_DistArray, sizeof(EQP_DistArray));
	gSpawnCount = 0;

	char Temp[MAX_STRING] = { 0 };
	char Name[MAX_STRING] = { 0 };

	// load custom spawn caption colors
	for (int index = 0; CaptionColors[index].szName[0]; index++)
	{
		if (GetPrivateProfileString("Caption Colors", CaptionColors[index].szName, "", Temp, MAX_STRING, mq::internal_paths::MQini))
		{
			if (!_stricmp(Temp, "on") || !_stricmp(Temp, "1"))
				CaptionColors[index].Enabled = 1;
			else
				CaptionColors[index].Enabled = 0;
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

	AddMQ2Data("NamingSpawn", dataNamingSpawn);

	AddCommand("/caption", CaptionCmd, false, false);
	AddCommand("/captioncolor", CaptionColorCmd, true, false);
}

void ShutdownMQ2Spawns()
{
	DebugSpew("Shutting Down Spawn-related Hooks");

	RemoveMQ2Data("NamingSpawn");

	RemoveCommand("/caption");
	RemoveCommand("/captioncolor");

	RemoveDetour(EQPlayer__EQPlayer);
	RemoveDetour(EQPlayer__dEQPlayer);
	RemoveDetour(EQPlayer__SetNameSpriteState);
	RemoveDetour(EQPlayer__SetNameSpriteTint);
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

	ZeroMemory(EQP_DistArray, sizeof(EQP_DistArray));
	gSpawnCount = 0;

	RemoveMQ2Benchmark(bmUpdateSpawnSort);
	RemoveMQ2Benchmark(bmUpdateSpawnCaptions);
}

bool IsTargetable(SPAWNINFO* pSpawn)
{
	return ((EQPlayerHook*)pSpawn)->IsTargetable();
}

} // namespace mq
