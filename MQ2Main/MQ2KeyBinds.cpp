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

#include "MQ2Main.h"

#include <map>
#include <string>
#include <algorithm>

//void InjectMQ2Binds(COptionsWnd* pWnd);
//void EjectMQ2Binds(COptionsWnd* pWnd);

struct MQ2KeyBind
{
	char          Name[32];
	KeyCombo      Normal;
	KeyCombo      Alt;
	fMQExecuteCmd Function;
	bool          State;
};

using KeybindMap = std::map<std::string, int, ci_less>;

CIndex<MQ2KeyBind*> s_keybinds(10);
KeybindMap s_keybindMap;

static MQ2KeyBind* KeyBindByName(const char* name)
{
	auto iter = s_keybindMap.find(name);
	if (iter == std::end(s_keybindMap))
		return nullptr;

	return s_keybinds[iter->second];
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

static bool SetEQKeyBind(const char* name, bool alternate, KeyCombo& combo)
{
	return SetEQKeyBindByNumber(FindMappableCommand(name), alternate, combo);
}

bool MQ2HandleKeyDown(const KeyCombo& combo)
{
	bool Ret = false;

	for (int index = 0; index < nEQMappableCommands; index++)
	{
		if (pKeypressHandler->CommandState[index] == 0
			&& (pKeypressHandler->NormalKey[index] == combo || pKeypressHandler->AltKey[index] == combo))
		{
			ExecuteCmd(index, true);

			pKeypressHandler->CommandState[index] = 1;
			Ret = true;
		}
	}

	for (int index = 0; index < (int)s_keybinds.Size; index++)
	{
		if (MQ2KeyBind* pBind = s_keybinds[index])
		{
			if (pBind->State == 0 && (pBind->Normal == combo || pBind->Alt == combo))
			{
				pBind->Function(pBind->Name, true);
				pBind->State = true;

				Ret = true;
			}
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

	for (int index = 0; index < (int)s_keybinds.Size; index++)
	{
		if (MQ2KeyBind* pBind = s_keybinds[index])
		{
			if (pBind->State == 1 && (pBind->Normal.Data[3] == combo.Data[3] || pBind->Alt.Data[3] == combo.Data[3]))
			{
				pBind->Function(pBind->Name, false);
				pBind->State = false;

				Ret = true;
			}
		}
	}
	return Ret;
}

class KeypressHandlerHook
{
public:
	void ClearCommandStateArray_Hook()
	{
		for (int index = 0; index < (int)s_keybinds.Size; index++)
		{
			if (MQ2KeyBind* pBind = s_keybinds[index])
			{
				pBind->State = false;
			}
		}

		ZeroMemory(&pKeypressHandler->CommandState[0], sizeof(pKeypressHandler->CommandState));
	}
	void ClearCommandStateArray_Trampoline();

	bool HandleKeyDown_Hook(const KeyCombo& combo)
	{
		if (!pWndMgr->HandleKeyboardMsg(combo.Data[3], true))
			return true;

		return (MQ2HandleKeyDown(combo) != 0);
	}
	bool HandleKeyDown_Trampoline(const KeyCombo&);

	bool HandleKeyUp_Hook(const KeyCombo& combo)
	{
		bool ret = false;
		if (!pWndMgr->HandleKeyboardMsg(combo.Data[3], false))
			ret = true;

		return MQ2HandleKeyUp(combo) || ret;
	}
	bool HandleKeyUp_Trampoline(const KeyCombo&);
};

DETOUR_TRAMPOLINE_EMPTY(void KeypressHandlerHook::ClearCommandStateArray_Trampoline());
DETOUR_TRAMPOLINE_EMPTY(bool KeypressHandlerHook::HandleKeyDown_Trampoline(const KeyCombo&));
DETOUR_TRAMPOLINE_EMPTY(bool KeypressHandlerHook::HandleKeyUp_Trampoline(const KeyCombo&));

static void DoRangedBind(const char* Name, bool Down);

void InitializeMQ2KeyBinds()
{
	AddMQ2KeyBind("RANGED", DoRangedBind);

	EzDetourwName(KeypressHandler__ClearCommandStateArray, &KeypressHandlerHook::ClearCommandStateArray_Hook, &KeypressHandlerHook::ClearCommandStateArray_Trampoline, "KeypressHandler__ClearCommandStateArray");
	EzDetourwName(KeypressHandler__HandleKeyDown, &KeypressHandlerHook::HandleKeyDown_Hook, &KeypressHandlerHook::HandleKeyDown_Trampoline, "KeypressHandler__HandleKeyDown");
	EzDetourwName(KeypressHandler__HandleKeyUp, &KeypressHandlerHook::HandleKeyUp_Hook, &KeypressHandlerHook::HandleKeyUp_Trampoline, "KeypressHandler__HandleKeyUp");
}

void ShutdownMQ2KeyBinds()
{
	s_keybinds.Cleanup();

	RemoveDetour(KeypressHandler__ClearCommandStateArray);
	RemoveDetour(KeypressHandler__HandleKeyDown);
	RemoveDetour(KeypressHandler__HandleKeyUp);
}

bool AddMQ2KeyBind(const char* name, fMQExecuteCmd Function)
{
	DebugSpew("AddMQ2KeyBind(%s)", name);

	if (KeyBindByName(name))
	{
		DebugSpew("AddMQ2KeyBind(%s) - Name already in use", name);
		return false;
	}

	MQ2KeyBind* pBind = new MQ2KeyBind;
	pBind->State = false;
	strncpy_s(pBind->Name, name, 32);
	pBind->Name[31] = 0;

	char szName[MAX_STRING] = { 0 };
	char szBuffer[MAX_STRING] = { 0 };

	sprintf_s(szName, "%s_%s", pBind->Name, "Nrm");
	GetPrivateProfileString("Key Binds", szName, "clear", szBuffer, MAX_STRING, gszINIFilename);

	ParseKeyCombo(szBuffer, pBind->Normal);

	sprintf_s(szName, "%s_%s", pBind->Name, "Alt");
	GetPrivateProfileString("Key Binds", szName, "clear", szBuffer, MAX_STRING, gszINIFilename);
	ParseKeyCombo(szBuffer, pBind->Alt);

	pBind->Function = Function;

	int index = s_keybinds.GetUnused();
	s_keybinds[index] = pBind;
	s_keybindMap.insert_or_assign(name, index);

	return true;
}

bool GetMQ2KeyBind(const char* name, bool alt, KeyCombo& combo)
{
	if (MQ2KeyBind* pBind = KeyBindByName(name))
	{
		if (alt)
			combo = pBind->Alt;
		else
			combo = pBind->Normal;

		return true;
	}
	return false;
}

bool RemoveMQ2KeyBind(const char* name)
{
	DebugSpew("RemoveMQ2KeyBind(%s)", name);

	auto iter = s_keybindMap.find(name);
	if (iter == std::end(s_keybindMap))
		return false;

	int index = iter->second;

	if (MQ2KeyBind* pBind = s_keybinds[index])
	{
		s_keybindMap.erase(iter);
		s_keybinds[index] = 0;

		delete pBind;
		return true;
	}

	return false;
}

bool PressMQ2KeyBind(const char* name, bool hold)
{
	if (MQ2KeyBind* pBind = KeyBindByName(name))
	{
		pBind->Function(pBind->Name, true);

		// release the keypress if we aren't asked to hold it.
		if (!hold)
		{
			pBind->Function(pBind->Name, false);
		}

		return true;
	}

	return false;
}

bool SetMQ2KeyBind(const char* name, bool alternate, KeyCombo& combo)
{
	if (MQ2KeyBind* pBind = KeyBindByName(name))
	{
		char szName[MAX_STRING] = { 0 };
		char szBuffer[MAX_STRING] = { 0 };

		if (!alternate)
		{
			sprintf_s(szName, "%s_Nrm", pBind->Name);
			pBind->Normal = combo;
		}
		else
		{
			sprintf_s(szName, "%s_Alt", pBind->Name);
			pBind->Alt = combo;
		}

		WritePrivateProfileString("Key Binds", szName, DescribeKeyCombo(combo, szBuffer, sizeof(szBuffer)), gszINIFilename);
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

void MQ2KeyBindCommand(SPAWNINFO* pChar, char* szLine)
{
	if (szLine[0] == 0)
	{
		WriteChatColor("Usage: /bind <list|eqlist|[~]name <combo|clear>>");
		return;
	}

	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	char* szRest = GetNextArg(szLine);
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

		for (int i = 0; i < (int)s_keybinds.Size; i++)
		{
			if (MQ2KeyBind* pBind = s_keybinds[i])
			{
				WriteChatf("[\ay%s\ax] Nrm:\at%s\ax Alt:\at%s\ax",
					pBind->Name, DescribeKeyCombo(pBind->Normal, szNormal, sizeof(szNormal)),
					DescribeKeyCombo(pBind->Alt, szAlt, sizeof(szAlt)));
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

		//ok first of all, the 0x11111111 constant for ac1 is not even used anymore they stopped using those ones years ago
		//its just left in there, legacy code, I suppose it would cause more problems removing it, than leaving it, and if a eq dev sees this, please
		//just leave that stuff alone because i dont want to have to worry about where it went or if its active again. -eqmule
		//second, even though its not active, now that eqgame uses aslr, we have to take that into account and actually add load address to the constant, thus the line below:

		//anyway... from now on we will just use the size of the image... not reliable to have it hardcoded
		for (int i = 0; i < nEQMappableCommands; i++)
		{
			if (szEQMappableCommands[i] == nullptr || szEQMappableCommands[i] > reinterpret_cast<const char*>(g_eqgameimagesize))
				continue;

			WriteChatf(szArg1, "[\ay%s\ax] Nrm:\at%s\ax Alt:\at%s\ax", szEQMappableCommands[i],
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
		for (int i = 0; i < (int)s_keybinds.Size; i++)
		{
			MQ2KeyBind* pBind = s_keybinds[i];
			if (pBind)
			{
				if (pBind->Alt == newCombo && SetMQ2KeyBind(pBind->Name, true, ClearCombo))
				{
					WriteChatf("Alternate %s cleared", pBind->Name);
				}

				if (pBind->Normal == newCombo && SetMQ2KeyBind(pBind->Name, false, ClearCombo))
				{
					WriteChatf("Normal %s cleared", pBind->Name);
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
		MQ2KeyBind* pBind = KeyBindByName(szArg);

		WriteChatf("%s %s now bound as %s", altKey ? "Alternate" : "Normal", pBind->Name, DescribeKeyCombo(newCombo, szBuffer, sizeof(szBuffer)));
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
			(altKey) ? ("Alternate") : ("Normal"),
			szEQMappableCommands[index],
			DescribeKeyCombo((altKey) ? (pKeypressHandler->AltKey[index]) : (pKeypressHandler->NormalKey[index]), szBuffer, sizeof(szBuffer)));
	}
}

static void DoRangedBind(const char* Name, bool Down)
{
	if (Down && pTarget && gbRangedAttackReady)
	{
		pLocalPlayer->DoAttack(0x0B, 0, pTarget);
		gbRangedAttackReady = 0;
	}
}

bool DumpBinds(const char* Filename)
{
	char szFilename[MAX_STRING] = { 0 };

	sprintf_s(szFilename, "%s\\Configs\\%s", gszINIPath, Filename);
	if (!strchr(Filename, '.'))
		strcat_s(szFilename, ".cfg");

	FILE* file = nullptr;
	errno_t err = fopen_s(&file, szFilename, "wt");
	if (err)
	{
		return false;
	}

	char szBuffer[MAX_STRING] = { 0 };

	for (int index = 0; index < nEQMappableCommands; index++)
	{
		if (szEQMappableCommands[index] == nullptr || szEQMappableCommands[index] > reinterpret_cast<const char*>(g_eqgameimagesize))
			continue;

		fprintf(file, "/bind %s %s\n", szEQMappableCommands[index], DescribeKeyCombo(pKeypressHandler->NormalKey[index], szBuffer, sizeof(szBuffer)));
		fprintf(file, "/bind ~%s %s\n", szEQMappableCommands[index], DescribeKeyCombo(pKeypressHandler->AltKey[index], szBuffer, sizeof(szBuffer)));
	}

	for (int index = 0; index < (int)s_keybinds.Size; index++)
	{
		if (MQ2KeyBind* pBind = s_keybinds[index])
		{
			fprintf(file, "/bind %s %s\n", pBind->Name, DescribeKeyCombo(pBind->Normal, szBuffer, sizeof(szBuffer)));
			fprintf(file, "/bind ~%s %s\n", pBind->Name, DescribeKeyCombo(pBind->Alt, szBuffer, sizeof(szBuffer)));
		}
	}

	fclose(file);
	return true;
}
