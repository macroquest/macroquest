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
#include "CrashHandler.h"

#include "imgui/ImGuiUtils.h"

#include <algorithm>
#include <string>
#include <unordered_map>

namespace mq {

char* szClickNotification[] = {
	"leftmouse",        // 0
	"leftmouseup",      // 1
	"leftmouseheld",    // 2
	"leftmouseheldup",  // 3
	"rightmouse",       // 4
	"rightmouseup",     // 5
	"rightmouseheld",   // 6
	"rightmouseheldup", // 7
};

struct WindowInfo
{
	std::string Name;
	CXWnd* pWnd = nullptr;
	CXWnd** ppWnd = nullptr;

	WindowInfo(std::string Name, CXWnd* pWnd, CXWnd** ppWnd)
		: Name(std::move(Name))
		, pWnd(pWnd)
		, ppWnd(ppWnd)
	{}
	WindowInfo() = default;
};

std::unordered_map<CXWnd*, WindowInfo> WindowList;
std::unordered_map<std::string, CXWnd*> WindowMap;
std::vector<std::string> XmlFiles;

int WinCount = 0;

bool GenerateMQUI();
void DestroyMQUI();

inline void AddWindowToList(const CXStr& Name, CXWnd* pWnd, bool log)
{
	std::string WindowName{ Name };
	MakeLower(WindowName);

	auto iter = WindowMap.find(WindowName);
	if (iter != WindowMap.end())
	{
		WindowList[pWnd] = { std::move(WindowName), pWnd, nullptr };

		if (log)
		{
			DebugSpew("Updating WndNotification target '%s'", Name.c_str());
		}
	}
	else
	{
		WindowList[pWnd] = { WindowName, pWnd, nullptr };
		WindowMap.emplace(std::move(WindowName), pWnd);

		if (log)
		{
			if (!Name.empty())
				DebugSpew("Adding WndNotification target '%s'", Name.c_str());
			else
				DebugSpew("Adding WndNotification target FAILED");
		}
	}
}

class CSidlInitHook
{
public:
	void Init_Trampoline(const CXStr& Name, int A);
	void Init_Detour(const CXStr& Name, int A)
	{
		AddWindowToList(Name, reinterpret_cast<CXWnd*>(this), true);

		Init_Trampoline(Name, A);
	}

	// FIXME: Maybe this should go elsewhere? Isn't really related to what we're doing here...
	int CTargetWnd__WndNotification_Tramp(CXWnd*, uint32_t, void*);
	int CTargetWnd__WndNotification_Detour(CXWnd* pWnd, uint32_t uiMessage, void* pData)
	{
		if (gUseTradeOnTarget)
		{
			if (uiMessage == XWM_LCLICK)
			{
				if (PcProfile* pProfile = GetPcProfile())
				{
					if (pTarget && pLocalPlayer
						&& ((SPAWNINFO*)pTarget)->SpawnID != ((SPAWNINFO*)pLocalPlayer)->SpawnID
						&& pEverQuest && pProfile->pInventoryArray
						&& (pProfile->pInventoryArray->Inventory.Cursor
							|| pProfile->CursorPlat || pProfile->CursorGold || pProfile->CursorSilver || pProfile->CursorCopper))
					{
						// player has a item or coin on his cursor and clicked targetwindow, he wants to trade with target...
						pEverQuest->LeftClickedOnPlayer(pTarget);
						WeDidStuff();
					}
				}
			}
		}
		return CTargetWnd__WndNotification_Tramp(pWnd, uiMessage, pData);
	}
};
DETOUR_TRAMPOLINE_EMPTY(void CSidlInitHook::Init_Trampoline(const CXStr&, int));
DETOUR_TRAMPOLINE_EMPTY(int CSidlInitHook::CTargetWnd__WndNotification_Tramp(CXWnd*, uint32_t, void*));

class CXWndManagerHook
{
public:
	int RemoveWnd_Trampoline(CXWnd*);
	int RemoveWnd_Detour(CXWnd* pWnd)
	{
		if (pWnd)
		{
			auto windowListIter = WindowList.find(pWnd);
			if (windowListIter != WindowList.end())
			{
				std::string Name{ windowListIter->second.Name };
				MakeLower(Name);

				auto windowMapIter = WindowMap.find(Name);
				if (windowMapIter != WindowMap.end())
				{
					WindowMap.erase(windowMapIter);
				}

				WindowList.erase(windowListIter);
			}
		}

		return RemoveWnd_Trampoline(pWnd);
	}
};
DETOUR_TRAMPOLINE_EMPTY(int CXWndManagerHook::RemoveWnd_Trampoline(class CXWnd*));

static void InitializeWindowList()
{
	if (!pWndMgr)
		return;

	for (int i = 0; i < pWndMgr->pWindows.Count; i++)
	{
		CXWnd* pWnd = pWndMgr->pWindows[i];
		if (!pWnd)
			continue;

		CXMLData* pXMLData = pWnd->GetXMLData();
		if (!pXMLData)
			continue;

		if (pXMLData->Type == UI_Screen)
		{
			AddWindowToList(pXMLData->Name, pWnd, false);
		}
	}
}

class CXMLSOMDocumentBaseHook
{
public:
	bool XMLRead(
		const CXStr& strPath,
		const CXStr& strDefaultPath,
		const CXStr& strFileName,
		const CXStr& strDefaultPath2)
	{
		DebugSpew("XMLRead(%s)", strFileName.c_str());

		// When EQ tries to read EQUI.xml, generate MQUI.xml instead
		// and redirect the read to that file.
		if (!_stricmp("EQUI.xml", strFileName.c_str()))
		{
			if (GenerateMQUI())
			{
				bool result = XMLRead_Trampoline(strPath,
					strDefaultPath,
					"MQUI.xml",
					strDefaultPath2);

				DestroyMQUI();
				return result;
			}
		}

		return XMLRead_Trampoline(strPath, strDefaultPath, strFileName, strDefaultPath2);
	}
	bool XMLRead_Trampoline(const CXStr& A, const CXStr& B, const CXStr& C, const CXStr& D);
};
DETOUR_TRAMPOLINE_EMPTY(bool CXMLSOMDocumentBaseHook::XMLRead_Trampoline(const CXStr& A, const CXStr& B, const CXStr& C, const CXStr& D));

bool DoesFileExist(const char* filename)
{
	std::filesystem::path localfile = filename;

	if (std::filesystem::exists(mq::internal_paths::Resources / localfile))
		return true;

	return std::filesystem::exists(localfile);
}
DETOUR_TRAMPOLINE_EMPTY(bool DoesFileExist_Trampoline(const char*));

class CMemoryMappedFile
{
public:
	bool SetFile_Detour(const char* filename, bool unk8, unsigned int unkC)
	{
		std::filesystem::path localfile = filename;

		if (std::filesystem::exists(mq::internal_paths::Resources / localfile))
		{
			localfile = mq::internal_paths::Resources / localfile;
			return SetFile_Trampoline(localfile.string().c_str(), unk8, unkC);
		}

		return SetFile_Trampoline(filename, unk8, unkC);
	}

	bool SetFile_Trampoline(const char*, bool, unsigned int);
};
DETOUR_TRAMPOLINE_EMPTY(bool CMemoryMappedFile::SetFile_Trampoline(const char*, bool, unsigned int));

// Hook for fopen in eqgraphics.dll
DETOUR_TRAMPOLINE_EMPTY(FILE* fopen_eqgraphics_trampoline(const char* filename, const char* mode));
FILE* fopen_eqgraphics_detour(const char* filename, const char* mode)
{
	// Only intercept reads
	if (strstr(mode, "r"))
	{
		std::filesystem::path localfile = filename;

		// Find the file in our local filesystem.
		std::filesystem::path overridePath = mq::internal_paths::Resources / localfile;
		if (overridePath != localfile && std::filesystem::exists(overridePath))
		{
			auto overrideString = overridePath.string();

			return fopen_eqgraphics_trampoline(overrideString.c_str(), mode);
		}
	}

	return fopen_eqgraphics_trampoline(filename, mode);
}

void ListWindows(PSPAWNINFO pChar, char* szLine);
void WndNotify(PSPAWNINFO pChar, char* szLine);
void ItemNotify(PSPAWNINFO pChar, char* szLine);
void ListItemSlots(PSPAWNINFO pChar, char* szLine);
void ReloadUI(PSPAWNINFO pChar, char* szLine);

#define WSF_AUTOSTRETCHH    0x00400000
#define WSF_CLIENTMOVABLE   0x00200000
#define WSF_NOHITTEST       0x00008000
#define WSF_USEMYALPHA      0x00000800
#define WSF_TRANSPARENT     0x00000400
#define WSF_SIZABLE         0x00000200
#define WSF_AUTOSTRETCHV    0x00000100
#define WSF_RELATIVERECT    0x00000080
#define WSF_BORDER          0x00000040
#define WSF_MINIMIZEBOX     0x00000020
#define WSF_CLOSEBOX        0x00000008
#define WSF_TITLEBAR        0x00000004

bool GenerateMQUI()
{
	// create EverQuest\uifiles\default\MQUI.xml
	CHARINFO* pCharInfo = GetCharInfo();
	char szFilename[MAX_PATH] = { 0 };
	char szOrgFilename[MAX_PATH] = { 0 };
	char UISkin[256] = { 0 };
	char Buffer[2048];

	if (XmlFiles.empty())
	{
		DebugSpew("GenerateMQUI::Not Generating MQUI.xml, no files in our list");
		return false;
	}
	sprintf_s(UISkin, "default");
	sprintf_s(szOrgFilename, "uifiles\\%s\\EQUI.xml", UISkin);
	sprintf_s(szFilename, "uifiles\\%s\\MQUI.xml", UISkin);

	DebugSpew("GenerateMQUI::Generating %s", szFilename);

	FILE* forg = nullptr;
	errno_t err = fopen_s(&forg, szOrgFilename, "rt");
	if (err)
	{
		DebugSpew("GenerateMQUI::could not open %s", szOrgFilename);
		return false;
	}

	FILE* fnew = nullptr;
	err = fopen_s(&fnew, szFilename, "wt");
	if (err)
	{
		DebugSpew("GenerateMQUI::could not open %s", szFilename);
		fclose(forg);
		return false;
	}

	while (fgets(Buffer, 2048, forg))
	{
		if (strstr(Buffer, "</Composite>"))
		{
			DebugSpew("GenerateMQUI::Inserting our xml files");

			for (const std::string& file : XmlFiles)
			{
				DebugSpew("GenerateMQUI::Inserting %s", file.c_str());
				fprintf(fnew, "<Include>%s</Include>\n", file.c_str());
			}
		}
		fprintf(fnew, "%s", Buffer);
	}
	fclose(fnew);
	fclose(forg);

	if (pCharInfo != nullptr)
	{
		sprintf_s(szFilename, "UI_%s_%s.ini", pCharInfo->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "default", UISkin, 256, szFilename);

		if (strcmp(UISkin, "default") != 0)
		{
			sprintf_s(szOrgFilename, "uifiles\\%s\\EQUI.xml", UISkin);
			sprintf_s(szFilename, "uifiles\\%s\\MQUI.xml", UISkin);

			DebugSpew("GenerateMQUI::Generating %s", szFilename);

			err = fopen_s(&forg, szOrgFilename, "rt");
			if (err)
			{
				DebugSpew("GenerateMQUI::could not open %s (non-fatal)", szOrgFilename);
				sprintf_s(szOrgFilename, "uifiles\\default\\EQUI.xml");
				err = fopen_s(&forg, szOrgFilename, "rt");
				if (err)
				{
					DebugSpew("GenerateMQUI::could not open %s", szOrgFilename);
					DebugSpew("GenerateMQUI::giving up");
					return false;
				}
			}

			err = fopen_s(&fnew, szFilename, "wt");
			if (err || fnew == nullptr)
			{
				DebugSpew("GenerateMQUI::could not open %s", szFilename);
				fclose(forg);
				return false;
			}

			while (fgets(Buffer, 2048, forg))
			{
				if (strstr(Buffer, "</Composite>"))
				{
					for (const std::string& file : XmlFiles)
					{
						fprintf(fnew, "<Include>%s</Include>\n", file.c_str());
					}
				}

				fprintf(fnew, "%s", Buffer);
			}
			fclose(fnew);
			fclose(forg);
		}
	}
	return true;
}

bool IsXMLFilePresent(const char* filename)
{
	// check default location.
	char szFilename[MAX_PATH] = { 0 };

	sprintf_s(szFilename, "uifiles\\default\\%s", filename);

	// this will check both MQ and EQ dirs
	if (DoesFileExist(szFilename))
		return true;

	// check current ui
	if (CHARINFO* pCharInfo = GetCharInfo())
	{
		char UISkin[256] = { 0 };

		sprintf_s(szFilename, "UI_%s_%s.ini", pCharInfo->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "default", UISkin, 256, szFilename);

		sprintf_s(szFilename, "uifiles\\%s\\%s", UISkin, filename);

		// this will check both MQ and EQ dirs
		return DoesFileExist(szFilename);
	}

	return false;
}

void DestroyMQUI()
{
	// delete MQUI.xml files.
	CHARINFO* pCharInfo = GetCharInfo();
	char szFilename[MAX_PATH] = { 0 };
	char UISkin[256] = { 0 };

	sprintf_s(szFilename, "uifiles\\default\\MQUI.xml");
	DebugSpew("DestroyMQUI: removing file %s", szFilename);
	remove(szFilename);

	if (pCharInfo != nullptr)
	{
		sprintf_s(szFilename, "UI_%s_%s.ini", pCharInfo->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "default", UISkin, 256, szFilename);

		sprintf_s(szFilename, "uifiles\\%s\\MQUI.xml", UISkin);
		DebugSpew("DestroyMQUI: removing file %s", szFilename);
		remove(szFilename);
	}
}

void AddXMLFile(const char* filename)
{
	for (const std::string& file : XmlFiles)
	{
		if (!_stricmp(file.c_str(), filename))
			return; // we already added this file
	}

	char szBuffer[MAX_PATH] = { 0 };
	CHARINFO* pCharInfo = GetCharInfo();
	char szFilename[MAX_PATH] = { 0 };
	char UISkin[256] = { 0 };
	sprintf_s(UISkin, "default");

	// grab the name of the ui skin
	if (pCharInfo != nullptr)
	{
		sprintf_s(szFilename, "UI_%s_%s.ini", pCharInfo->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "default", UISkin, 256, szFilename);
	}

	sprintf_s(szBuffer, "uifiles\\%s\\%s", UISkin, filename);

	if (!DoesFileExist(szBuffer))
	{
		sprintf_s(szBuffer, "uifiles\\default\\%s", filename);
		if (!DoesFileExist(szBuffer))
		{
			WriteChatf("UI file %s not found in either uifiles\\%s or uifiles\\default.  Please copy it there, reload the UI, and reload this plugin.", filename, UISkin);
			return;
		}
	}

	DebugSpew("Adding XML File %s", filename);
	if (gGameState == GAMESTATE_INGAME)
	{
		WriteChatf("UI file %s added, you must reload your UI for this to take effect.", filename);
	}

	XmlFiles.emplace_back(filename);
}

void RemoveXMLFile(const char* filename)
{
	// Remove all file(s) that match the given filename. Should only ever be one.
	XmlFiles.erase(
		std::remove_if(std::begin(XmlFiles), std::end(XmlFiles),
			[filename](const std::string & file) { return !_stricmp(filename, file.c_str()); }),
		std::end(XmlFiles));
}

CXWnd* FindMQ2Window(const char* WindowName)
{
	WindowInfo Info;
	std::string Name = WindowName;
	MakeLower(Name);

	// check toplevel windows first
	if (WindowMap.find(Name) != WindowMap.end())
	{
		//found it no need to look further...
		return WindowMap[Name];
	}

	// didnt find one, is it a container?
	CONTENTS* pPack = nullptr;
	if (!_strnicmp(WindowName, "bank", 4))
	{
		unsigned long nPack = GetIntFromString(&WindowName[4], 0);
		if (nPack && nPack <= NUM_BANK_SLOTS)
		{
#ifdef NEWCHARINFO
			if (pCharData && ((CHARINFO*)pCharData)->BankItems.Items.Size > nPack - 1)
			{
				pPack = ((CHARINFO*)pCharData)->BankItems.Items[nPack - 1].get();
			}
#else
			if (pCharData && ((CHARINFO*)pCharData)->pBankArray)
			{
				pPack = ((CHARINFO*)pCharData)->pBankArray->Bank[nPack - 1];
			}
#endif
		}
	}
	else if (!_strnicmp(WindowName, "pack", 4))
	{
		unsigned long nPack = GetIntFromString(&WindowName[4], 0);
		if (nPack && nPack <= 10)
		{
			if (PcProfile* pProfile = GetPcProfile())
			{
				if (pProfile->pInventoryArray)
				{
					pPack = pProfile->pInventoryArray->Inventory.Pack[nPack - 1];
				}
			}
		}
	}
	else if (!_stricmp(WindowName, "enviro"))
	{
		pPack = pContainerMgr->pWorldContainer.get();
	}

	if (pPack)
	{
		return (CXWnd*)FindContainerForContents(pPack);
	}

	// didnt find a toplevel window, is it a child then?
	bool namefound = false;
	for (auto& N : WindowList)
	{
		if (N.second.Name == Name)
		{
			namefound = true;
			Info = N.second;
			break;
		}
	}

	if (!namefound)
	{
		WindowMap.erase(Name);
		return nullptr;
	}

	if (Info.pWnd)
	{
		return Info.pWnd;
	}

	if (Info.ppWnd)
	{
		return *Info.ppWnd;
	}


	WindowMap.erase(Name);
	WindowList.erase(Info.pWnd);
	return nullptr;
}

bool SendWndClick2(CXWnd* pWnd, const char* ClickNotification)
{
	if (!pWnd)
		return false;

	for (unsigned long i = 0; i < 8; i++)
	{
		if (!_stricmp(szClickNotification[i], ClickNotification))
		{
			CXRect rect = pWnd->GetScreenRect();
			CXPoint pt = rect.CenterPoint();

			switch (i)
			{
			case 0:
				DebugTry(pWnd->HandleLButtonDown(pt, 0));
				break;
			case 1:
				DebugTry(pWnd->HandleLButtonDown(pt, 0));
				DebugTry(pWnd->HandleLButtonUp(pt, 0));
				break;
			case 2:
				DebugTry(pWnd->HandleLButtonDown(pt, 0));
				DebugTry(pWnd->HandleLButtonHeld(pt, 0));
				break;
			case 3:
				DebugTry(pWnd->HandleLButtonDown(pt, 0));
				DebugTry(pWnd->HandleLButtonHeld(pt, 0));
				DebugTry(pWnd->HandleLButtonUpAfterHeld(pt, 0));
				break;
			case 4:
				DebugTry(pWnd->HandleRButtonDown(pt, 0));
				break;
			case 5:
				DebugTry(pWnd->HandleRButtonDown(pt, 0));
				DebugTry(pWnd->HandleRButtonUp(pt, 0));
				break;
			case 6:
				DebugTry(pWnd->HandleRButtonDown(pt, 0));
				DebugTry(pWnd->HandleRButtonHeld(pt, 0));
				break;
			case 7:
				DebugTry(pWnd->HandleRButtonDown(pt, 0));
				DebugTry(pWnd->HandleRButtonHeld(pt, 0));
				DebugTry(pWnd->HandleRButtonUpAfterHeld(pt, 0));
				break;
			default:
				return false;
			};

			WeDidStuff();
			return true;
		}
	}
	return false;
}

CXWnd* GetChildByIndex(CXWnd* pWnd, const char* Name, int index)
{
	if (!pWnd) return pWnd;

	if (CXMLData* pXMLData = pWnd->GetXMLData())
	{
		if (!_stricmp(pXMLData->Name.c_str(), Name))
		{
			WinCount++;
		}
		else if (!_stricmp(pXMLData->ScreenID.c_str(), Name))
		{
			WinCount++;
		}
	}

	if (WinCount == index)
		return pWnd;

	if (pWnd->GetFirstChildWnd())
	{
		if (CXWnd* tmp = GetChildByIndex(pWnd->GetFirstChildWnd(), Name, index))
			return tmp;
	}

	return GetChildByIndex(pWnd->GetNextSiblingWnd(), Name, index);
}

bool SendWndClick(const char* WindowName, const char* ScreenID, const char* ClickNotification)
{
	CXWnd* pWnd = FindMQ2Window(WindowName);
	if (!_stricmp(WindowName, "RewardSelectionWnd"))
	{
		//     Parent    TabWindow         PageTemplate
		pWnd = pWnd->GetFirstChildWnd()->GetFirstChildWnd();

		while (pWnd)
		{
			if (pWnd->IsVisible())
			{
				break;
			}
			pWnd = pWnd->GetNextSiblingWnd();
		}
	}

	if (!pWnd)
	{
		MacroError("Window '%s' not available.", WindowName);
		return false;
	}

	if (ScreenID && ScreenID[0] && ScreenID[0] != '0')
	{
		CXWnd* pButton = nullptr;

		if (!_stricmp(WindowName, "bartersearchwnd") && !_stricmp(ScreenID, "sellbutton"))
		{
			if (CListWnd* pList = (CListWnd*)pWnd->GetChildItem("BuyLineList"))
			{
				int selection = pList->GetCurSel();
				if (selection == -1)
				{
					MacroError("Please select a Listitem in '%s' before issuing a '%s' Click", WindowName, ScreenID);
					return false;
				}

				int buttonindex = (int)pList->GetItemData(selection);
				WinCount = 0;
				pButton = GetChildByIndex(pWnd, ScreenID, buttonindex + 1);
			}
		}
		else if (!_stricmp(WindowName, "bazaarsearchwnd") && !_stricmp(ScreenID, "BZR_BuyButton"))
		{
			if (CListWnd* pList = (CListWnd*)pWnd->GetChildItem("BZR_ItemList"))
			{
				int selection = pList->GetCurSel();
				if (selection == -1)
				{
					MacroError("Please select a Listitem in '%s' before issuing a '%s' Click", WindowName, ScreenID);
					return false;
				}

				int buttonindex = (int)pList->GetItemData(selection);
				WinCount = 0;
				pButton = GetChildByIndex(pWnd, ScreenID, buttonindex + 1);
			}
		}
		else
		{
			pButton = pWnd->GetChildItem(ScreenID);
		}

		if (!pButton)
		{
			MacroError("Window '%s' child '%s' not found.", WindowName, ScreenID);
			return false;
		}

		pWnd = pButton;
	}

	for (int i = 0; i < 8; i++)
	{
		if (!_stricmp(szClickNotification[i], ClickNotification))
		{
			CXRect rect = pWnd->GetScreenRect();
			CXPoint pt = rect.CenterPoint();

			switch (i)
			{
			case 0:
				pWnd->HandleLButtonDown(pt, 0);
				break;
			case 1:
				pWnd->HandleLButtonDown(pt, 0);
				pWnd->HandleLButtonUp(pt, 0);
				break;
			case 2:
				pWnd->HandleLButtonHeld(pt, 0);
				break;
			case 3:
				pWnd->HandleLButtonDown(pt, 0);
				pWnd->HandleLButtonHeld(pt, 0);
				pWnd->HandleLButtonUpAfterHeld(pt, 0);
				break;
			case 4:
				pWnd->HandleRButtonDown(pt, 0);
				break;
			case 5:
				pWnd->HandleRButtonDown(pt, 0);
				pWnd->HandleRButtonUp(pt, 0);
				break;
			case 6:
				pWnd->HandleRButtonDown(pt, 0);
				pWnd->HandleRButtonHeld(pt, 0);
				break;
			case 7:
				pWnd->HandleRButtonDown(pt, 0);
				pWnd->HandleRButtonHeld(pt, 0);
				pWnd->HandleRButtonUpAfterHeld(pt, 0);
				break;
			default:
				return false;
			};

			WeDidStuff();
			return true;
		}
	}

	return false;
}

bool SendListSelect(const char* WindowName, const char* ScreenID, int Value)
{
	CXWnd* pWnd = FindMQ2Window(WindowName);
	if (!_stricmp(WindowName, "RewardSelectionWnd"))
	{
		//           TabWindow           PageTemplate
		pWnd = pWnd->GetFirstChildWnd()->GetFirstChildWnd();
		while (pWnd)
		{
			if (pWnd->IsVisible())
			{
				break;
			}

			pWnd = pWnd->GetNextSiblingWnd();
		}
	}

	if (!pWnd)
	{
		MacroError("Window '%s' not available.", WindowName);
		return false;
	}

	if (ScreenID && ScreenID[0] && ScreenID[0] != '0')
	{
		pWnd = pWnd->GetChildItem(ScreenID);
		if (!pWnd)
		{
			MacroError("Window '%s' child '%s' not found.", WindowName, ScreenID);
			return false;
		}

		if (pWnd->GetType() == UI_Listbox)
		{
			CListWnd* listWnd = static_cast<CListWnd*>(pWnd);

			listWnd->SetCurSel(Value);
			int index = listWnd->GetCurSel();
			listWnd->EnsureVisible(index);

			CXRect rect = listWnd->GetItemRect(index, 0);
			CXPoint pt = rect.CenterPoint();
			listWnd->HandleLButtonDown(pt, 0);
			listWnd->HandleLButtonUp(pt, 0);

			WeDidStuff();
		}
		else if (pWnd->GetType() == UI_Combobox)
		{
			CComboWnd* comboWnd = static_cast<CComboWnd*>(pWnd);

			CXRect comborect = comboWnd->GetScreenRect();
			CXPoint combopt = comborect.CenterPoint();

			comboWnd->SetChoice(Value);
			comboWnd->HandleLButtonDown(combopt, 0);

			CListWnd* pListWnd = comboWnd->pListWnd;

			int index = pListWnd->GetCurSel();
			CXRect listrect = pListWnd->GetItemRect(index, 0);
			CXPoint listpt = listrect.CenterPoint();
			pListWnd->HandleLButtonDown(listpt, 0);
			pListWnd->HandleLButtonUp(listpt, 0);

			WeDidStuff();
		}
		else
		{
			MacroError("Window '%s' child '%s' cannot accept this notification.", WindowName, ScreenID);
			return false;
		}

		return true;
	}

	return false;
}

bool SendListSelect2(CXWnd* pWnd, int ListIndex)
{
	if (!pWnd)
	{
		MacroError("Window %x not available.", pWnd);
		return false;
	}

	if (pWnd->GetType() == UI_Listbox)
	{
		CListWnd* listWnd = static_cast<CListWnd*>(pWnd);

		if (listWnd->ItemsArray.Count >= ListIndex)
		{
			listWnd->SetCurSel(ListIndex);
			int index = listWnd->GetCurSel();

			listWnd->EnsureVisible(index);

			CXPoint pt = listWnd->GetItemRect(index, 0).CenterPoint();

			listWnd->HandleLButtonDown(pt, 0);
			listWnd->HandleLButtonUp(pt, 0);

			WeDidStuff();
			return true;
		}

		MacroError("Index Out of Bounds in SendListSelect2");
		return false;
	}

	if (pWnd->GetType() == UI_Combobox)
	{
		CComboWnd* comboWnd = static_cast<CComboWnd*>(pWnd);

		if (CListWnd* listWnd = comboWnd->pListWnd)
		{
			if (listWnd->ItemsArray.Count >= ListIndex)
			{
				CXRect comborect = listWnd->GetScreenRect();
				CXPoint combopt = comborect.CenterPoint();

				comboWnd->SetChoice(ListIndex);
				comboWnd->HandleLButtonDown(combopt, 0);

				int index = listWnd->GetCurSel();

				CXPoint pt = listWnd->GetItemRect(index, 0).CenterPoint();
				listWnd->HandleLButtonDown(pt, 0);
				listWnd->HandleLButtonUp(pt, 0);

				WeDidStuff();
				return true;
			}

			MacroError("Index Out of Bounds in SendListSelect2");
			return false;
		}

		MacroError("Invalid combobox in SendListSelect2");
		return false;
	}

	MacroError("Window was neiter a UI_Listbox nor a UI_Combobox");
	return false;
}

bool SendComboSelect(const char* WindowName, const char* ScreenID, int Value)
{
	CXWnd* pWnd = FindMQ2Window(WindowName);
	if (!_stricmp(WindowName, "RewardSelectionWnd"))
	{
		//     Parent    TabWindow          PageTemplate
		pWnd = pWnd->GetFirstChildWnd()->GetFirstChildWnd();
		while (pWnd)
		{
			if (pWnd->IsVisible())
			{
				break;
			}

			pWnd = pWnd->GetNextSiblingWnd();
		}
	}

	if (!pWnd)
	{
		MacroError("Window '%s' not available.", WindowName);
		return false;
	}

	if (ScreenID && ScreenID[0] && ScreenID[0] != '0')
	{
		pWnd = pWnd->GetChildItem(ScreenID);
		if (!pWnd)
		{
			MacroError("Window '%s' child '%s' not found.", WindowName, ScreenID);
			return false;
		}

		if (pWnd->GetType() == UI_Combobox)
		{
			CComboWnd* comboWnd = static_cast<CComboWnd*>(pWnd);

			CXPoint comboPt = comboWnd->GetScreenRect().CenterPoint();
			comboWnd->SetChoice(Value);
			comboWnd->HandleLButtonDown(comboPt, 0);

			CListWnd* pListWnd = comboWnd->pListWnd;
			int index = pListWnd->GetCurSel();

			CXPoint listPt = pListWnd->GetItemRect(index, 0).CenterPoint();

			comboWnd->HandleLButtonDown(listPt, 0);
			comboWnd->HandleLButtonUp(listPt, 0);

			WeDidStuff();
			return true;
		}

		MacroError("Window '%s' child '%s' cannot accept this notification.", WindowName, ScreenID);
		return false;
	}

	return false;
}

bool SendTabSelect(const char* WindowName, const char* ScreenID, int Value)
{
	CXWnd* pWnd = FindMQ2Window(WindowName);
	if (!_stricmp(WindowName, "RewardSelectionWnd"))
	{
		//          TabWindow           PageTemplate
		pWnd = pWnd->GetFirstChildWnd()->GetFirstChildWnd();
		while (pWnd)
		{
			if (pWnd->IsVisible())
			{
				break;
			}
			pWnd = pWnd->GetNextSiblingWnd();
		}
	}

	if (!pWnd)
	{
		MacroError("Window '%s' not available.", WindowName);
		return false;
	}

	if (ScreenID && ScreenID[0] && ScreenID[0] != '0')
	{
		CTabWnd* pTab = (CTabWnd*)pWnd->GetChildItem(ScreenID);
		if (!pTab)
		{
			MacroError("Window '%s' child '%s' not found.", WindowName, ScreenID);
			return false;
		}

		int uitype = pTab->GetType();
		if (uitype == UI_TabBox)
		{
			pTab->SetPage(Value, true);

			WeDidStuff();
			return true;
		}

		MacroError("Window '%s' child '%s' cannot accept this notification.", WindowName, ScreenID);
		return false;
	}

	return false;
}

bool SendWndNotification(const char* WindowName, const char* ScreenID, int Notification, void* Data)
{
	CXWnd* pWnd = FindMQ2Window(WindowName);
	if (!pWnd)
	{
		WriteChatf("Window '%s' not available.", WindowName);
		return false;
	}

	CXWnd* pChild = nullptr;
	if (ScreenID && ScreenID[0])
	{
		pChild = pWnd->GetChildItem(ScreenID);
		if (!pChild)
		{
			WriteChatf("Window '%s' child '%s' not found.", WindowName, ScreenID);
			return false;
		}
	}

	if (Notification == XWM_NEWVALUE && pChild)
	{
		CSliderWnd* sliderWnd = static_cast<CSliderWnd*>(pChild);
		sliderWnd->SetValue(reinterpret_cast<int>(Data));
	}

	pWnd->WndNotification(pChild, Notification, Data);
	WeDidStuff();
	return true;
}

void AddWindow(char* WindowName, CXWnd** ppWindow)
{
	std::string Name = WindowName;
	MakeLower(Name);

	if (WindowMap.find(Name) != WindowMap.end())
	{
		WindowInfo pWnd;

		for (auto& N : WindowList)
		{
			if (N.second.Name == Name)
			{
				pWnd = N.second;
				break;
			}
		}

		pWnd.pWnd = nullptr;
		pWnd.ppWnd = ppWindow;
	}
	else
	{
		WindowInfo pWnd;
		pWnd.Name = Name;
		pWnd.pWnd = nullptr;
		pWnd.ppWnd = ppWindow;

		WindowList[*ppWindow] = pWnd;
		WindowMap[Name] = *ppWindow;
	}
}

void RemoveWindow(char* WindowName)
{
	std::string Name = WindowName;
	MakeLower(Name);

	if (WindowMap.find(Name) != WindowMap.end())
	{
		WindowMap.erase(Name);
		for (auto N = WindowList.begin(); N != WindowList.end(); N++)
		{
			if (N->second.Name == Name)
			{
				WindowList.erase(N);
				break;
			}
		}
	}
}

int RecurseAndListWindows(CXWnd* pWnd)
{
	int Count = 0;

	if (CXMLData* pXMLData = pWnd->GetXMLData())
	{
		Count++;

		if (!pXMLData->ScreenID.empty()
			&& _stricmp(pXMLData->Name.c_str(), pXMLData->ScreenID.c_str()))
		{
			if (pWnd->GetParentWindow() && pWnd->GetParentWindow()->GetParentWindow())
			{
				WriteChatf("[0x%08X][P:0x%08X][PP:0x%08X] [\ay%s\ax] [\at%s\ax] [Custom UI-specific: \at%s\ax]",
					pWnd,
					pWnd->GetParentWindow(),
					pWnd->GetParentWindow()->GetParentWindow(),
					pXMLData->TypeName.c_str(),
					pXMLData->Name.c_str(),
					pXMLData->ScreenID.c_str());
			}
			else
			{
				WriteChatf("[0x%08X][P:0x%08X] [\ay%s\ax] [\at%s\ax] [Custom UI-specific: \at%s\ax]",
					pWnd,
					pWnd->GetParentWindow(),
					pXMLData->TypeName.c_str(),
					pXMLData->Name.c_str(),
					pXMLData->ScreenID.c_str());
			}
		}
		else
		{
			WriteChatf("[0x%08X][P:0x%08X] [\ay%s\ax] [\at%s\ax]",
				pWnd,
				pWnd->GetParentWindow(),
				pXMLData->TypeName.c_str(),
				pXMLData->Name.c_str());
		}
	}

	if (pWnd->GetFirstChildWnd())
		Count += RecurseAndListWindows(pWnd->GetFirstChildWnd());

	if (pWnd->GetNextSiblingWnd())
		Count += RecurseAndListWindows(pWnd->GetNextSiblingWnd());

	return Count;
}

void ListWindows(PSPAWNINFO pChar, char* szLine)
{
	char szArg1[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	char szArg3[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	GetArg(szArg2, szLine, 2);
	GetArg(szArg3, szLine, 3);

	bool bOpen = false;
	bool bPartial = false;

	if (!_stricmp(szArg1, "open"))
	{
		bOpen = true;
		szLine[0] = '\0';
		szLine = nullptr;
		if (!_stricmp(szArg2, "partial"))
		{
			bPartial = true;
			strcpy_s(szArg2, szArg3);
		}
	}
	else if (!_stricmp(szArg1, "partial"))
	{
		bPartial = true;
		szLine[0] = '\0';
		szLine = nullptr;
	}

	int Count = 0;
	if (!szLine || !szLine[0])
	{
		if (bOpen)
			WriteChatColor("List of available OPEN windows");
		else
			WriteChatColor("List of available windows");
		WriteChatColor("-------------------------");

		for (auto& N : WindowList)
		{
			WindowInfo Info = N.second;
			if (bOpen)
			{
				if (Info.pWnd && Info.pWnd->IsVisible() && Info.pWnd->GetParentWindow() == nullptr)
				{
					if (bPartial)
					{
						if (Info.Name.find(szArg2) != Info.Name.npos)
						{
							WriteChatf("[PARTIAL MATCH][OPEN] %s", Info.Name.c_str());
							RecurseAndListWindows(Info.pWnd);
							Count++;
						}
					}
					else
					{
						WriteChatf("[OPEN] %s", Info.Name.c_str());
						Count++;
					}
				}
			}
			else
			{
				if (bPartial)
				{
					if (Info.Name.find(szArg2) != Info.Name.npos)
					{
						WriteChatf("[PARTIAL MATCH] %s", Info.Name.c_str());
						RecurseAndListWindows(Info.pWnd);
						Count++;
					}
				}
				else
				{
					WriteChatf("%s", Info.Name.c_str());
					Count++;
				}
			}
		}

		WriteChatf("%d window(s) found with %s in the name", Count, szArg2);
	}
	else
	{
		// list children of..
		std::string WindowName = szLine;
		MakeLower(WindowName);

		if (WindowMap.find(WindowName) == WindowMap.end())
		{
			if (CXWnd* pWnd = FindMQ2Window(szLine))
			{
				Count = RecurseAndListWindows(pWnd);

				WriteChatf("%d child windows", Count);
				return;
			}

			WriteChatf("Window '%s' not available", WindowName.c_str());
			return;
		}

		WriteChatf("Listing child windows of '%s'", WindowName.c_str());
		WriteChatColor("-------------------------");

		for (auto& N : WindowList)
		{
			WindowInfo& Info = N.second;

			if (Info.Name == WindowName && Info.pWnd)
			{
				if (CXWnd* pWnd = Info.pWnd->GetFirstChildWnd())
				{
					Count = RecurseAndListWindows(pWnd);
				}
				WriteChatf("%d child windows", Count);
			}
		}
	}
}

const char* szWndNotification[] = {
	nullptr,                  // 0
	"leftmouse",              // 1
	"leftmouseup",            // 2
	"rightmouse",             // 3
	nullptr,                  // 4
	nullptr,                  // 5
	"enter",                  // 6
	nullptr,                  // 7
	nullptr,                  // 8
	"help",                   // 9
	"close",                  // 10
	nullptr,                  // 11
	nullptr,                  // 12
	nullptr,                  // 13
	"newvalue",               // 14
	nullptr,                  // 15
	nullptr,                  // 16
	nullptr,                  // 17
	nullptr,                  // 18
	nullptr,                  // 19
	"contextmenu",            // 20
	"mouseover",              // 21
	"history",                // 22
	"leftmousehold",          // 23
	nullptr,                  // 24
	nullptr,                  // 25
	nullptr,                  // 26
	"link",                   // 27
	nullptr,                  // 28
	"resetdefaultposition",   // 29
};

void WndNotify(PSPAWNINFO pChar, char* szLine)
{
	int Data = 0;

	char szArg1[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	char szArg3[MAX_STRING] = { 0 };
	char szArg4[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	GetArg(szArg2, szLine, 2);
	GetArg(szArg3, szLine, 3);
	GetArg(szArg4, szLine, 4);

	if (!szArg3[0] && !IsNumber(szArg1) && !ci_equals(szArg2, "menuselect"))
	{
		SyntaxError("Syntax: /notify <window|\"item\"> <control|menuselect|0> <notification> [notification data]");
		return;
	}

	if (szArg4[0])
	{
		Data = GetIntFromString(szArg4, Data);
	}

	if (ci_equals(szArg2, "menuselect"))
	{
		if (pContextMenuManager->NumVisibleMenus == 1)
		{
			const int currMenu = pContextMenuManager->CurrMenu;

			if (pContextMenuManager->CurrMenu < MAX_CONTEXT_MENU_DEPTH)
			{
				if (CContextMenu* menu = pContextMenuManager->pCurrMenus[currMenu])
				{
					for (int i = 0; i < menu->NumItems; ++i)
					{
						CXStr Str = menu->GetItemText(i, 1);

						if (!Str.empty() && ci_find_substr(Str, szArg1) != -1)
						{
							WriteChatf("\ay[/notify] SUCCESS\ax: Clicking \"%s\" at position %d in the menu.", Str.c_str(), i);
							pContextMenuManager->WndNotification(menu, XWM_LMOUSEUP, reinterpret_cast<void*>(i));
							return;
						}
					}

					WriteChatf("\ar[/notify] FAILED\ax: No Menu item was found with the word %s in it", szArg1);
				}
			}
		}
		else
		{
			WriteChatf("\ar[/notify] FAILED\ax: No Menu is currently open.");
		}

		return;
	}

	if (ci_equals(szArg3, "link"))
	{
		DebugSpewAlways("WndNotify: link found, Data = 1");
		Data = 1;
	}

	if (IsNumber(szArg1))
	{
		// we have a number. it means the user want us to click a window he has found the address for...
		const int addr = GetIntFromString(szArg1, 0);
		if (ci_equals(szArg2, "listselect"))
		{
			SendListSelect2(reinterpret_cast<CXWnd*>(addr), GetIntFromString(szArg3, 0));
		}
		else
		{
			SendWndClick2(reinterpret_cast<CXWnd*>(addr), szArg2);
		}

		return;
	}

	if (!_stricmp(szArg3, "listselect"))
	{
		SendListSelect(szArg1, szArg2, Data - 1);
		return;
	}

	if (!_stricmp(szArg3, "comboselect"))
	{
		SendComboSelect(szArg1, szArg2, Data - 1);
		return;
	}

	if (!_stricmp(szArg3, "tabselect"))
	{
		SendTabSelect(szArg1, szArg2, Data - 1);
		return;
	}

	if (Data == 0 && SendWndClick(szArg1, szArg2, szArg3))
	{
		return;
	}

	for (int i = 0; i < sizeof(szWndNotification) / sizeof(szWndNotification[0]); ++i)
	{
		if (szWndNotification[i] && ci_equals(szWndNotification[i], szArg3))
		{
			if (i == XWM_LINK)
			{
				if (!SendWndNotification(szArg1, szArg2, i, static_cast<void*>(szArg4)))
				{
					MacroError("Could not send notification to %s %s", szArg1, szArg2);
				}
			}
			else if (szArg2[0] == '0')
			{
				if (!SendWndNotification(szArg1, nullptr, i, reinterpret_cast<void*>(Data)))
				{
					MacroError("Could not send notification to %s %s", szArg1, szArg2);
				}
			}
			else if (!SendWndNotification(szArg1, szArg2, i, reinterpret_cast<void*>(Data)))
			{
				MacroError("Could not send notification to %s %s", szArg1, szArg2);
			}
			return;
		}
	}

	MacroError("Invalid notification '%s'", szArg3);
}

bool IsCtrlKey()
{
	return (pWndMgr->GetKeyboardFlags() & 0x00000002) != 0;
}

// item slots:
// 2000-2015 bank window
// 2500-2503 shared bank
// 5000-5031 loot window
// 3000-3015 trade window (including npc) 3000-3007 are your slots, 3008-3015 are other character's slots
// 4000-4010 world container window
// 6000-6080 merchant window
// 7000-7080 bazaar window
// 8000-8031 inspect window
bool CheckLootArg(char* arg, char* search, int argcnt, int* slot)
{
	if (!_strnicmp(arg, search, argcnt))
	{
		char* numptr = arg + argcnt;
		int theslot = -1;
		if (IsNumber(numptr))
		{
			theslot = GetIntFromString(numptr, 0) - 1;
			if (theslot < 0)
				theslot = 0;
			*slot = theslot;
			return true;
		}
	}
	return false;
}

void ItemNotify(PSPAWNINFO pChar, char* szLine)
{
	char szArg1[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	char szArg3[MAX_STRING] = { 0 };
	char szArg4[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	GetArg(szArg2, szLine, 2);
	GetArg(szArg3, szLine, 3);
	GetArg(szArg4, szLine, 4);

	if (!szArg2[0])
	{
		WriteChatColor("Syntax: /itemnotify <slot|#> <notification>");
		WriteChatColor("     or /itemnotify in <bag slot> <slot # in bag> <notification>");
		WriteChatColor("     or /itemnotify <itemname> <notification>");
		return;
	}

	char* pNotification = &szArg2[0];
	CInvSlot* pSlot = nullptr;
	int i = 0;
	CInvSlotMgr* pInvMgr = pInvSlotMgr;
	short bagslot = -1;
	short invslot = -1;
	ItemContainerInstance type = eItemContainerInvalid;

	if (!_stricmp(szArg1, "in"))
	{
		if (!szArg4[0])
		{
			WriteChatColor("Syntax: /itemnotify in <bag slot> <slot # in bag> <notification>");
			return;
		}

		if (!_strnicmp(szArg2, "bank", 4))
		{
			invslot = GetIntFromString(&szArg2[4], invslot) - 1;
			bagslot = GetIntFromString(szArg3, bagslot) - 1;
			type = eItemContainerBank;
		}
		else if (!_strnicmp(szArg2, "sharedbank", 10))
		{
			invslot = GetIntFromString(&szArg2[10], invslot) - 1;
			bagslot = GetIntFromString(szArg3, bagslot) - 1;
			type = eItemContainerSharedBank;
		}
		else if (!_strnicmp(szArg2, "pack", 4))
		{
			invslot = GetIntFromString(&szArg2[4], invslot) - 1 + BAG_SLOT_START;
			bagslot = GetIntFromString(szArg3, bagslot) - 1;
			type = eItemContainerPossessions;
		}

		// I wish I could just call:
		// pSlot = (PEQINVSLOT)pInvSlotMgr->FindInvSlot(invslot,bagslot);
		// BUT it returns HB_InvSlot as well as containers AND it doesn't take "type" into account...
		// which is why I use GetInvSlot instead...
		pSlot = GetInvSlot(type, invslot, bagslot);
		pNotification = &szArg4[0];

		if (!pSlot && type != -1)
		{
			// pSlot was not found (so bag is closed) BUT we can "click" it anyway with moveitem
			// so lets just do that if pNotification is leftmoseup
			if (invslot < 0 || invslot > NUM_INV_SLOTS)
			{
				WriteChatf("%d is not a valid invslot. (itemnotify)", invslot);
				return;
			}

			if (pNotification && !_strnicmp(pNotification, "leftmouseup", 11))
			{
				// we dont care about the bagslot here
				// and we dont care if the user has something
				// on cursor either, cause we know they
				// specified "in" so a container MUST exist... -eqmule
				CONTENTS* pContainer = FindItemBySlot(invslot);
				if (!pContainer)
				{
					WriteChatf("There was no container in slot %d", invslot);
					return;
				}

				if (bagslot < 0 && bagslot >= (int)pContainer->Contents.ContentSize)
				{
					WriteChatf("%d is not a valid slot for this container.", bagslot);
					return;
				}

				if (GetItemFromContents(pContainer)->Type != ITEMTYPE_PACK)
				{
					WriteChatf("There was no container in slot %d", invslot);
					return;
				}

				if (ItemOnCursor())
				{
					DropItem(type, invslot, bagslot);
				}
				else
				{
					PickupItem(type, FindItemBySlot(invslot, bagslot));
				}

				return;
			}

			if (pNotification && !_strnicmp(pNotification, "rightmouseup", 12))
			{
				// we fake it with /useitem
				if (HasExpansion(EXPANSION_VoA))
				{
					CONTENTS* pItem = FindItemBySlot(invslot, bagslot);
					if (pItem)
					{
						if (GetItemFromContents(pItem)->Clicky.SpellID > 0 && GetItemFromContents(pItem)->Clicky.SpellID != -1)
						{
							char cmd[MAX_STRING] = { 0 };
							sprintf_s(cmd, "/useitem \"%s\"", GetItemFromContents(pItem)->Name);
							EzCommand(cmd);
							return;
						}
					}
					else
					{
						// it doesnt matter if its a bag, since the user specified "in"
						// we cant open bags inside bags so lets just return...
						WriteChatf("Item '%s' not found.", szArg2);
						return;
					}
				}
			}
		}
	}
	else
	{
		// user didnt specify "in" so it should be outside a container
		// OR it's an item, either way we can "click" it -eqmule
		int Slot = GetIntFromString(szArg1, 0);
		if (Slot == 0)
		{
			_strlwr_s(szArg1);
			Slot = ItemSlotMap[szArg1];
			if (Slot < NUM_INV_SLOTS && pInvSlotMgr)
			{
				DebugTry(pSlot = pInvSlotMgr->FindInvSlot(Slot));
			}
			else
			{
				if (!_strnicmp(szArg1, "loot", 4))
				{
					invslot = GetIntFromString(&szArg1[4], invslot) - 1;
					type = eItemContainerCorpse;
				}
				else if (!_strnicmp(szArg1, "enviro", 6))
				{
					invslot = GetIntFromString(&szArg1[6], invslot) - 1;
					type = eItemContainerWorld;
				}
				else if (!_strnicmp(szArg1, "pack", 4))
				{
					invslot = GetIntFromString(&szArg1[4], invslot) - 1 + BAG_SLOT_START;
					type = eItemContainerPossessions;
				}
				else if (!_strnicmp(szArg1, "bank", 4))
				{
					invslot = GetIntFromString(&szArg1[4], invslot) - 1;
					type = eItemContainerBank;
				}
				else if (!_strnicmp(szArg1, "sharedbank", 10))
				{
					invslot = GetIntFromString(&szArg1[10], invslot) - 1;
					type = eItemContainerSharedBank;
				}
				else if (!_strnicmp(szArg1, "trade", 5))
				{
					invslot = GetIntFromString(&szArg1[5], invslot) - 1;
					type = eItemContainerTrade;
				}

				for (i = 0; i < pInvMgr->TotalSlots; i++)
				{
					pSlot = pInvMgr->SlotArray[i];
					if (pSlot
						&& pSlot->bEnabled
						&& pSlot->pInvSlotWnd
						&& pSlot->pInvSlotWnd->ItemLocation.GetLocation() == type
						&& pSlot->pInvSlotWnd->ItemLocation.GetTopSlot() == invslot)
					{
						CXMLData* pXMLData = pSlot->pInvSlotWnd->GetXMLData();
						if (pXMLData)
						{
							if (!_stricmp(pXMLData->ScreenID.c_str(), "HB_InvSlot"))
							{
								continue;
							}
						}

						Slot = 1;
						break;
					}
				}

				if (i == pInvMgr->TotalSlots)
					Slot = 0;
			}
		}

		if (Slot == 0 && szArg1[0] != '0' && _stricmp(szArg1, "charm"))
		{
			// could it be an itemname?
			// lets check:
			CONTENTS* ptheitem = nullptr;

			if (szArg1[0] == '#')
			{
				int id = GetIntFromString(&szArg1[1], 0);
				ptheitem = FindItemByID(id);
			}
			else
			{
				ptheitem = FindItemByName(szArg1, true);
			}

			if (ptheitem)
			{
				if (pNotification && !_strnicmp(pNotification, "leftmouseup", 11))
				{
					if (ItemOnCursor())
					{
						DropItem(eItemContainerPossessions, bagslot, invslot);
					}
					else
					{
						PickupItem(eItemContainerPossessions, ptheitem);
					}
				}
				else if (pNotification && !_strnicmp(pNotification, "rightmouseup", 12))
				{
					// we fake it with /useitem
					// better check if its a spell cause then it means we should mem it
					PITEMINFO pClicky = GetItemFromContents(ptheitem);

					if (pClicky && pClicky->ItemType == ITEMITEMTYPE_SCROLL)
					{
						if (IsItemInsideContainer(ptheitem))
						{
							OpenContainer(ptheitem, true);
						}

						if (pInvSlotMgr)
						{
							pSlot = pInvSlotMgr->FindInvSlot(ptheitem->GetGlobalIndex().GetTopSlot(),
								ptheitem->GetGlobalIndex().GetIndex().GetSlot(1));
						}

						if (!pSlot || !pSlot->pInvSlotWnd || !SendWndClick2(pSlot->pInvSlotWnd, pNotification))
						{
							WriteChatf("Could not mem spell, most likely cause bag wasnt open and i didnt find it");
						}

						return;
					}

					if (pClicky && pClicky->Clicky.SpellID != -1)
					{
						char cmd[512] = { 0 };
						sprintf_s(cmd, "/useitem \"%s\"", GetItemFromContents(ptheitem)->Name);
						EzCommand(cmd);

						return;
					}

					if (pClicky->Type == ITEMTYPE_PACK)
					{
						// its a pack, so just open it
						if (ptheitem->Open)
						{
							CloseContainer(ptheitem);
						}
						else {
							OpenContainer(ptheitem, false);
						}
					}
				}

				return;
			}

			WriteChatf("[/itemnotify] Invalid item slot '%s'", szArg1);
			return;
		}

		if (Slot > 0 && Slot < MAX_INV_SLOTS && !pSlot)
		{
			pSlot = pInvMgr->SlotArray[Slot];
		}
	}

	if (!pSlot)
	{
		WriteChatf("SLOT IS NULL: Could not send notification to %s %s", szArg1, szArg2);
		return;
	}

	DebugSpew("ItemNotify: Calling SendWndClick");

	if (!pSlot->pInvSlotWnd || !SendWndClick2(pSlot->pInvSlotWnd, pNotification))
	{
		WriteChatf("Could not send notification to %s %s", szArg1, szArg2);
	}
}

void ListItemSlots(PSPAWNINFO pChar, char* szLine)
{
	CInvSlotMgr* pMgr = pInvSlotMgr;
	if (!pMgr)
		return;
	unsigned long Count = 0;

	WriteChatColor("List of available item slots");
	WriteChatColor("-------------------------");

	for (int N = 0; N < MAX_INV_SLOTS; N++)
	{
		if (CInvSlot* pSlot = pMgr->SlotArray[N])
		{
			if (pSlot->pInvSlotWnd)
			{
				WriteChatf("%d %d %d", N, pSlot->pInvSlotWnd->ItemLocation.GetLocation(), pSlot->Index);
				Count++;
			}
			else if (pSlot->Index)
			{
				WriteChatf("%d %d", N, pSlot->Index);
			}
		}
	}

	WriteChatf("%d available item slots", Count);
}

void ReloadUI(SPAWNINFO* pChar, char* szLine)
{
	CHARINFO* pCharInfo = GetCharInfo();
	if (!pCharInfo) return;

	char szFilename[MAX_PATH];
	char UISkin[256];

	sprintf_s(szFilename, "UI_%s_%s.ini", pCharInfo->Name, EQADDR_SERVERNAME);
	GetPrivateProfileString("Main", "UISkin", "default", UISkin, 256, szFilename);

	char szBuffer[50];
	sprintf_s(szBuffer, "/loadskin %s 1", UISkin);

	DoCommand(pChar, szBuffer);
}

//============================================================================

class CascadeItemKeyBind : public CascadeItemCommandBase
{
public:
	CascadeItemKeyBind(const char* text, const char* keybind)
	{
		m_text = text;
		m_keyBind = keybind;

		KeyCombo combo;
		if (GetMQ2KeyBind(keybind, false, combo) && !combo.IsEmpty())
		{
			m_text = m_text + " <" + combo.GetTextDescription() + ">";
		}
	}

	~CascadeItemKeyBind()
	{

	}

	void ExecuteCommand() override
	{
		PressMQ2KeyBind(m_keyBind, false);
	}

	CXStr GetTooltip() const override { return m_text; }

private:
	const char* m_keyBind;
};

class CascadeItemCallback : public CascadeItemCommandBase
{
public:
	CascadeItemCallback(const char* text, const std::function<void()>& callback)
	{
		m_text = text;
		m_callback = callback;
	}

	~CascadeItemCallback()
	{
	}

	void ExecuteCommand() override
	{
		if (m_callback)
			m_callback();
	}

	CXStr GetTooltip() const override { return m_text; }

private:
	std::function<void()> m_callback;
};

struct CascadeItemData
{
	std::string name;
	int icon = -1;

	// keybind name
	std::string keyBind;

	// callback
	fCascadeItemFunction callback = nullptr;

	CascadeItemData(const char* name, const char* keybind, int icon = -1)
		: name(name)
		, keyBind(keybind)
		, icon(icon)
	{}

	CascadeItemData(const char* name, fCascadeItemFunction callback, int icon = -1)
		: name(name)
		, callback(callback)
		, icon(icon)
	{}
};

static std::vector<CascadeItemData> gCascadeItemData;
static bool gbCascadeMenuNeedsUpdate = false;

static void AddCascadeMenuItem(CascadeItemData newData)
{
	for (const auto& data : gCascadeItemData)
	{
		if (data.name == newData.name)
			return;
	}

	gCascadeItemData.push_back(std::move(newData));

	// Schedule an update to the menu
	gbCascadeMenuNeedsUpdate = true;
}

void AddCascadeMenuItem(const char* name, const char* keyBind, int icon)
{
	AddCascadeMenuItem({ name, keyBind, icon });
}

void AddCascadeMenuItem(const char* name, fCascadeItemFunction function, int icon)
{
	AddCascadeMenuItem({ name, function, icon });
}

void RemoveCascadeMenuItem(const char* name)
{
	gCascadeItemData.erase(
		std::remove_if(std::begin(gCascadeItemData), std::end(gCascadeItemData),
			[name](const CascadeItemData& data) { return data.name == name; }),
		std::end(gCascadeItemData));

	gbCascadeMenuNeedsUpdate = true;
}

static CascadeItemSubMenu* GetOrCreateSubMenuFromName(CascadeItemSubMenu* root, std::string_view name)
{
	size_t pos = name.find_first_of("/");
	if (pos == std::string::npos)
		return root;

	std::string head{ name.substr(0, pos) };
	std::string_view tail = name.substr(pos + 1);

	trim(head);

	// Find a sub-menu with this name.
	CascadeItemArray* items = root->GetItems();
	CascadeItemSubMenu* found = nullptr;

	for (int i = 0; i < items->GetCount(); ++i)
	{
		CascadeItemBase* item = items->Get(i);

		if (item->GetType() == CascadeItemBase::eTypeSubMenu)
		{
			CascadeItemSubMenu* subMenu = static_cast<CascadeItemSubMenu*>(item);

			if (subMenu->GetText() == head)
			{
				found = subMenu;
				break;
			}
		}
	}

	if (!found)
	{
		// Sub-menu was not found. we create and insert into items.
		found = eqNew<CascadeItemSubMenu>();
		found->SetText(CXStr{ head });
		found->SetItems(eqNew<CascadeItemArray>());

		items->Add(found);
	}

	return GetOrCreateSubMenuFromName(found, tail);
}

DETOUR_TRAMPOLINE_EMPTY(CascadeItemArray* CreateCascadeMenuItems_Trampoline());
CascadeItemArray* CreateCascadeMenuItems_Detour()
{
	CascadeItemArray* array = CreateCascadeMenuItems_Trampoline();

	// Create Submenu Item that holds all of our custom items
	CascadeItemSubMenu* mq2Menu = eqNew<CascadeItemSubMenu>();
	mq2Menu->SetIcon(21); // TODO: Custom Icon
	mq2Menu->SetText("MacroQuest");

	CascadeItemArray* itemArray = eqNew<CascadeItemArray>();
	mq2Menu->SetItems(itemArray);

	//----------------------------------------------------------------------------
	// TODO: Implement cascade items from data

	for (const CascadeItemData& data : gCascadeItemData)
	{
		CascadeItemBase* base = nullptr;

		std::string name = data.name;
		CascadeItemSubMenu* parent = GetOrCreateSubMenuFromName(mq2Menu, name);

		if (parent != mq2Menu)
		{
			// if we changed the menu, find and strip out the /
			name = name.substr(name.find_last_of("/") + 1);
			trim(name);
		}

		if (!data.keyBind.empty())
		{
			// its a keybind thing.
			auto item = eqNew<CascadeItemKeyBind>(name.c_str(), data.keyBind.c_str());
			item->SetIcon(data.icon);

			base = item;
		}
		else
		{
			auto item = eqNew<CascadeItemCallback>(name.c_str(), data.callback);
			item->SetIcon(data.icon);

			base = item;
		}

		parent->GetItems()->Add(base);
	}

	//----------------------------------------------------------------------------
	// Prepend our MQ2 Menu Item to the cascade menu.

	array->InsertElement(0, mq2Menu);

	CascadeItemSeparator* sep = eqNew<CascadeItemSeparator>();
	array->InsertElement(1, sep);

	return array;
}

void UpdateCascadeMenu()
{
	if (pEQMainWnd)
	{
		pEQMainWnd->UpdateCascadeMenuItems();
	}

	gbCascadeMenuNeedsUpdate = false;
}

void InstallCascadeMenuItems()
{
	EzDetour(__CreateCascadeMenuItems, CreateCascadeMenuItems_Detour, CreateCascadeMenuItems_Trampoline);

	UpdateCascadeMenu();
}

void RemoveCascadeMenuItems()
{
	RemoveDetour(__CreateCascadeMenuItems);
	RemoveCascadeMenuItem("Toggle Overlay UI");

	gCascadeItemData.clear();

	UpdateCascadeMenu();
}

//============================================================================

struct ImGuiWindowDebugPanel
{
	CXWnd* m_pSelectedWnd = nullptr;
	CXWnd* m_pHoveredWnd = nullptr;

	// Never dereference this. the window might be deleted. We just use it to track
	// what is selected.
	CXWnd* m_pLastSelected = nullptr;
	bool m_foundSelected = false;

	float m_topPaneSize = -1.0f;
	float m_bottomPaneSize = -1.0f;

	bool m_picking = false;
	CXWnd* m_pPickingWnd = nullptr;

	void Draw()
	{
		ImGuiTableFlags tableFlags = ImGuiTableFlags_ScrollFreezeTopRow | ImGuiTableFlags_ScrollY | ImGuiTableFlags_BordersV | ImGuiTableFlags_BordersHOuter | ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg;

		// This is so we can reset the selected window if it is not found.
		m_foundSelected = false;
		m_pHoveredWnd = nullptr;
		m_pPickingWnd = nullptr;

		ImVec2 availSize = ImGui::GetContentRegionAvail();
		if (m_topPaneSize == -1.0f)
			m_topPaneSize = availSize.y * .75f;
		if (m_bottomPaneSize == -1.0f)
			m_bottomPaneSize = availSize.y - m_topPaneSize - 1;

		if (m_picking)
		{
			ImGui::Text("Picking...");

			m_pPickingWnd = pWndMgr->LastMouseOver;
		}

		imgui::DrawSplitter(true, 9.0f, &m_topPaneSize, &m_bottomPaneSize, 50, 50);

		if (ImGui::BeginTable("##WindowTable", 2, tableFlags, ImVec2(0, m_topPaneSize)))
		{
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_NoHide | ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Type");
			ImGui::TableAutoHeaders();

			if (pWndMgr)
			{
				for (CXWnd* pWnd : pWndMgr->ParentAndContextMenuWindows)
				{
					DisplayWindowTreeNode(pWnd);
				}
			}

			ImGui::EndTable();
		}

		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 9);

		// if the selected window was not found, then clear it. This might mess up if we didn't
		// draw the table node. FIXME
		if (!m_foundSelected)
		{
			m_pSelectedWnd = nullptr;
		}

		if (m_pSelectedWnd)
		{
			ImGui::Text("Selected Window: %s", m_pSelectedWnd->GetXMLName().c_str());

			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImDrawList* drawList = ImGui::GetBackgroundDrawList(viewport);

			//CXRect clientRect = m_pSelectedWnd->GetClientRect();
			//drawList->AddRect(
			//	ImVec2(clientRect.left + viewport->Pos.x, clientRect.top + viewport->Pos.y),
			//	ImVec2(clientRect.right + viewport->Pos.x, clientRect.bottom + viewport->Pos.y),
			//	m_pSelectedWnd->IsReallyVisible() ? IM_COL32(255, 255, 50, 255) : IM_COL32(255, 200, 200, 255));
		}
		else
		{
			ImGui::Text("Selected Window: None");
		}

		if (ImGui::Button("Pick"))
		{
			m_picking = !m_picking;
		}

		if (m_pPickingWnd)
		{
			m_pHoveredWnd = m_pPickingWnd;
		}

		if (m_pHoveredWnd)
		{
			ImGui::Text("Hovered Window: %s", m_pHoveredWnd->GetXMLName().c_str());

			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImDrawList* drawList = ImGui::GetBackgroundDrawList(viewport);

			CXRect clientRect = m_pHoveredWnd->GetClientRect();
			drawList->AddRect(
				ImVec2(clientRect.left + viewport->Pos.x, clientRect.top + viewport->Pos.y),
				ImVec2(clientRect.right + viewport->Pos.x, clientRect.bottom + viewport->Pos.y),
				m_pHoveredWnd->IsReallyVisible() ? IM_COL32(50, 255, 50, 255) : IM_COL32(255, 50, 50, 255));
		}
		else
		{
			ImGui::Text("Hovered Window: None");
		}

		// update last selected to remember selection for next iteration
		m_pLastSelected = m_pSelectedWnd;
	}

	void DisplayWindowTreeNode(CXWnd* pWnd)
	{
		if (pWnd->GetType() == UI_Unknown)
			return;
		ImGui::TableNextRow();
		const bool hasChildren = pWnd->GetFirstChildWnd() != nullptr;

		CXStr pName = pWnd->GetXMLName();
		CXMLData* pXMLData = pWnd->GetXMLData();
		CXStr typeName = pWnd->GetTypeName();
		//const char* szWindowName = pName ? pName->c_str() : "";
		//const char* szXmlName = pXMLData ? pXMLData->Name.c_str() : "";
		//const char* szXmlScreenID = pXMLData ? pXMLData->ScreenID.c_str() : "";
		//if (strlen(szWindowName) == 0)
		//	szWindowName = szXmlName;

		ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_SpanFullWidth;
		bool open = false;
		bool selected = (m_pLastSelected == pWnd);
		bool selectPicking = false;

		if (m_picking)
		{
			if (m_pPickingWnd == pWnd)
			{
				selected = true;
				selectPicking = true;
			}
		}

		if (selected)
		{
			flags |= ImGuiTreeNodeFlags_Selected;
			m_foundSelected = true;
		}

		if (!hasChildren)
		{
			flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
		}

		if (hasChildren)
		{
			if (m_pPickingWnd)
			{
				if (m_pPickingWnd->IsDescendantOf(pWnd))
					flags |= ImGuiTreeNodeFlags_DefaultOpen;
			}

			open = ImGui::TreeNodeEx(pWnd, flags, "%s", pName.c_str());
		}
		else
		{
			ImGui::TreeNodeEx(pWnd, flags, "%s", pName.c_str());
		}

		if (selectPicking)
		{
			ImGui::SetScrollHere();
		}

		if (ImGui::IsItemHovered())
		{
			m_pHoveredWnd = pWnd;
		}
		if (ImGui::IsItemClicked())
		{
			m_pSelectedWnd = pWnd;
			m_foundSelected = true;
		}

		ImGui::TableNextCell();
		ImGui::Text("%s", typeName.c_str());

		if (open)
		{
			CXWnd* pChild = pWnd->GetFirstChildWnd();
			while (pChild)
			{
				DisplayWindowTreeNode(pChild);
				pChild = pChild->GetNextSiblingWnd();
			}

			ImGui::TreePop();
		}
	}
};

static ImGuiWindowDebugPanel s_windowDebugPanel;

static void WindowsDebugPanel()
{
	s_windowDebugPanel.Draw();
}

void InitializeMQ2Windows()
{
	DebugSpew("Initializing MQ2 Windows");

	for (int i = 0; i < NUM_INV_SLOTS; i++)
		ItemSlotMap[szItemSlot[i]] = i;

	char szOut[MAX_STRING] = { 0 };

#define AddSlotArray(name, count, start)     \
	for (int i = 0; i < count; i++)          \
	{                                        \
		sprintf_s(szOut, #name"%d", i + 1);  \
		ItemSlotMap[szOut] = start + i;      \
	}
	AddSlotArray(bank, 24, 2000);
	AddSlotArray(sharedbank, 4, 2500);
	AddSlotArray(trade, 16, 3000);
	AddSlotArray(world, 10, 4000);
	AddSlotArray(enviro, 10, 4000);
	ItemSlotMap["enviro"] = 4100;
	AddSlotArray(loot, 31, 5000);
	AddSlotArray(merchant, 80, 6000);
	AddSlotArray(bazaar, 80, 7000);
	AddSlotArray(inspect, 31, 8000);
#undef AddSlotArray

	EzDetour(CXMLSOMDocumentBase__XMLRead,
		&CXMLSOMDocumentBaseHook::XMLRead,
		&CXMLSOMDocumentBaseHook::XMLRead_Trampoline);
	EzDetour(CSidlScreenWnd__Init1,
		&CSidlInitHook::Init_Detour,
		&CSidlInitHook::Init_Trampoline);
	EzDetour(CTargetWnd__WndNotification,
		&CSidlInitHook::CTargetWnd__WndNotification_Detour,
		&CSidlInitHook::CTargetWnd__WndNotification_Tramp);
	EzDetour(CXWndManager__RemoveWnd,
		&CXWndManagerHook::RemoveWnd_Detour,
		&CXWndManagerHook::RemoveWnd_Trampoline);
	EzDetour(CMemoryMappedFile__SetFile,
		&CMemoryMappedFile::SetFile_Detour,
		&CMemoryMappedFile::SetFile_Trampoline);
	EzDetour(__DoesFileExist,
		&DoesFileExist,
		&DoesFileExist_Trampoline);
	EzDetour(__eqgraphics_fopen, fopen_eqgraphics_detour, fopen_eqgraphics_trampoline);

	AddCommand("/windows", ListWindows);
	AddCommand("/notify", WndNotify);
	AddCommand("/itemnotify", ItemNotify);
	AddCommand("/itemslots", ListItemSlots);
	AddCommand("/reloadui", ReloadUI);

	InitializeWindowList();
	InstallCascadeMenuItems();

	AddDebugPanel("Windows", WindowsDebugPanel);
}

void ShutdownMQ2Windows()
{
	DebugSpew("Shutting down MQ2 Windows");
	RemoveCascadeMenuItems();

	RemoveCommand("/windows");
	RemoveCommand("/notify");
	RemoveCommand("/itemnotify");
	RemoveCommand("/itemslots");
	RemoveCommand("/reloadui");

	RemoveDetour(CXMLSOMDocumentBase__XMLRead);
	RemoveDetour(CSidlScreenWnd__Init1);
	RemoveDetour(CTargetWnd__WndNotification);
	RemoveDetour(CXWndManager__RemoveWnd);
	RemoveDetour(__DoesFileExist);
	RemoveDetour(CMemoryMappedFile__SetFile);
	RemoveDetour(__eqgraphics_fopen);

	RemoveDebugPanel("Windows");
}

void PulseMQ2Windows()
{
	if (gbCascadeMenuNeedsUpdate)
	{
		UpdateCascadeMenu();
	}
}

} // namespace mq
