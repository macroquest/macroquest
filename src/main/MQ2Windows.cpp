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
#include "CrashHandler.h"
#include "MQPluginHandler.h"
#include "MQ2DeveloperTools.h"

#include <algorithm>
#include <string>
#include <unordered_map>

#include <spdlog/spdlog.h>

namespace mq {

static void Windows_Initialize();
static void Windows_Shutdown();
static void Windows_Pulse();
static void Windows_UpdateImGui();

static MQModule gWindowsModule = {
	"Windows",                  // Name
	false,                      // CanUnload
	Windows_Initialize,
	Windows_Shutdown,
	Windows_Pulse,
	nullptr,
	Windows_UpdateImGui,
};
MQModule* GetWindowsModule() { return &gWindowsModule; }

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

ci_unordered::multimap<std::string_view, CXWnd*> WindowMap;
std::unordered_map<CXWnd*, CXStr> WindowList;
std::vector<std::string> XmlFiles;

int WinCount = 0;

static bool GenerateMQUI(const CXStr& strPath, const CXStr& strPathDefault);
static void DestroyMQUI(const CXStr& strPath);

static void DropWindowFromMap(std::string_view Name, CXWnd* pWnd)
{
	auto range = WindowMap.equal_range(Name);
	for (auto it = range.first; it != range.second;)
	{
		if (pWnd == it->second)
		{
			it = WindowMap.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void AddWindowToList(const CXStr& WindowName, CXWnd* pWnd)
{
	// if the window changes names, then we will be changing the entry in WindowList, so deal with that before setting the WindowList entry
	auto listIt = WindowList.find(pWnd);
	if (listIt != WindowList.end())
	{
		if (!ci_equals(WindowName, listIt->second))
		{
			// we only want to do this operation if the window names are different
			DropWindowFromMap(listIt->second, pWnd);
			listIt->second = WindowName;
		}
	}
	else
	{
		listIt = WindowList.emplace(std::make_pair(pWnd, WindowName)).first;
	}

	auto range = WindowMap.equal_range(WindowName);

	// it won't matter if the range is empty here, this will detect if the window is in the map already
	auto it = std::find_if(range.first, range.second, [pWnd](const auto& window)
	{
		return pWnd == window.second;
	});

	if (it == range.second)
	{
		// not found in the multimap, we can add it
		WindowMap.emplace(listIt->second, pWnd);
	}
}

class CSidlInitHook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, Init_Trampoline, (const CXStr& Name, int A))
	void Init_Detour(const CXStr& Name, int A)
	{
		AddWindowToList(Name, reinterpret_cast<CXWnd*>(this));

		Init_Trampoline(Name, A);
	}

	// FIXME: Maybe this should go elsewhere? Isn't really related to what we're doing here...
	DETOUR_TRAMPOLINE_DEF(int, CTargetWnd__WndNotification_Tramp, (CXWnd*, uint32_t, void*))
	int CTargetWnd__WndNotification_Detour(CXWnd* pWnd, uint32_t uiMessage, void* pData)
	{
		if (gUseTradeOnTarget && pTarget && uiMessage == XWM_LCLICK)
		{
			PcProfile* pProfile = GetPcProfile();

			if (pTarget->SpawnID != pLocalPlayer->SpawnID
				&& (pProfile->GetInventorySlot(InvSlot_Cursor) != nullptr
					|| pProfile->CursorPlat || pProfile->CursorGold || pProfile->CursorSilver || pProfile->CursorCopper))
			{
				// player has a item or coin on his cursor and clicked targetwindow, he wants to trade with target...
				pEverQuest->LeftClickedOnPlayer(pTarget);
				WeDidStuff();
			}
		}

		return CTargetWnd__WndNotification_Tramp(pWnd, uiMessage, pData);
	}
};

class CXWndManagerHook
{
public:
	// This serves as the effective destructor of the window. Every CXWnd will call this in its
	// destructor, so this means we do not need to detour the destructor, too.
	DETOUR_TRAMPOLINE_DEF(int, RemoveWnd_Trampoline, (CXWnd*))
	int RemoveWnd_Detour(CXWnd* pWnd)
	{
		if (pWnd)
		{
			auto windowListIter = WindowList.find(pWnd);
			if (windowListIter != WindowList.end())
			{
				DropWindowFromMap(windowListIter->second, pWnd);
				WindowList.erase(windowListIter);
			}

			DeveloperTools_WindowInspector_RemoveWindow(pWnd);
		}

		return RemoveWnd_Trampoline(pWnd);
	}
};

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
			AddWindowToList(pXMLData->Name, pWnd);
		}
	}
}

void ReinitializeWindowList()
{
	WindowList.clear();
	WindowMap.clear();

	InitializeWindowList();
}

class CXMLSOMDocumentBaseHook
{
public:
	DETOUR_TRAMPOLINE_DEF(bool, XMLRead_Trampoline, (const CXStr& A, const CXStr& B, const CXStr& C, const CXStr& D))
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
			if (GenerateMQUI(strPath, strDefaultPath))
			{
				const bool result = XMLRead_Trampoline(strPath,
					strDefaultPath,
					"MQUI.xml",
					strDefaultPath2);

				DestroyMQUI(strPath);
				return result;
			}
		}

		return XMLRead_Trampoline(strPath, strDefaultPath, strFileName, strDefaultPath2);
	}
};

DETOUR_TRAMPOLINE_DEF(bool, DoesFileExist_Trampoline, (const char*))
bool DoesFileExist(const char* filename)
{
	const std::filesystem::path localfile = filename;
	std::error_code ec_exists;

	if (std::filesystem::exists(mq::internal_paths::Resources / localfile, ec_exists))
		return true;

	return std::filesystem::exists(localfile, ec_exists);
}

class CMemoryMappedFile
{
public:
	DETOUR_TRAMPOLINE_DEF(bool, SetFile_Trampoline, (const char*, bool, unsigned int))
	bool SetFile_Detour(const char* filename, bool unk8, unsigned int unkC)
	{
		std::filesystem::path localfile = filename;
		std::error_code ec_exists;

		if (std::filesystem::exists(mq::internal_paths::Resources / localfile, ec_exists))
		{
			localfile = mq::internal_paths::Resources / localfile;
			return SetFile_Trampoline(localfile.string().c_str(), unk8, unkC);
		}

		return SetFile_Trampoline(filename, unk8, unkC);
	}

};

// Hook for fopen in eqgraphics.dll
DETOUR_TRAMPOLINE_DEF(FILE*, fopen_eqgraphics_trampoline, (const char* filename, const char* mode))
FILE* fopen_eqgraphics_detour(const char* filename, const char* mode)
{
	// Only intercept reads
	if (strstr(mode, "r"))
	{
		std::filesystem::path localfile = filename;
		std::error_code ec_exists;

		// Find the file in our local filesystem.
		std::filesystem::path overridePath = mq::internal_paths::Resources / localfile;
		if (overridePath != localfile && std::filesystem::exists(overridePath, ec_exists))
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

bool GenerateMQUI(const CXStr& strPath, const CXStr& strPathDefault)
{
	strcpy_s(gUISkin, GetCurrentUI().c_str());

	if (XmlFiles.empty())
	{
		DebugSpew("GenerateMQUI::Not Generating MQUI.xml, no files in our list");
		return false;
	}

	std::error_code ec;
	std::filesystem::path pathEQUI = fmt::format("{}\\{}EQUI.xml", mq::internal_paths::EverQuest, strPath);
	if (!std::filesystem::exists(pathEQUI, ec))
	{
		pathEQUI = fmt::format("{}\\{}{}", mq::internal_paths::EverQuest, strPathDefault, "EQUI.xml");
	}

	const std::filesystem::path pathMQUI = fmt::format("{}\\{}MQUI.xml", mq::internal_paths::Resources, strPath);

	if (std::filesystem::exists(pathEQUI, ec) && (std::filesystem::exists(pathMQUI.parent_path(), ec) || std::filesystem::create_directories(pathMQUI.parent_path(), ec)))
	{
		DebugSpew("GenerateMQUI::Generating %s", pathMQUI.string().c_str());

		FILE* forig = _fsopen(pathEQUI.string().c_str(), "rt", _SH_DENYNO);
		if (forig == nullptr)
		{
			DebugSpew("GenerateMQUI::could not open %s", pathEQUI.string().c_str());
		}
		else
		{
			FILE* fnew = _fsopen(pathMQUI.string().c_str(), "wt", _SH_DENYWR);
			if (fnew == nullptr)
			{
				DebugSpew("GenerateMQUI::could not open %s", pathMQUI.string().c_str());
				fclose(forig);
			}
			else
			{
				char Buffer[MAX_STRING] = { 0 };
				while (fgets(Buffer, MAX_STRING, forig))
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
				fclose(forig);
				return true;
			}
		}
	}
	return false;
}

// DEPRECATED
bool IsXMLFilePresent(const char* filename)
{
	// check default location.
	char szFilename[MAX_PATH] = { 0 };

	sprintf_s(szFilename, "uifiles\\default\\%s", filename);

	// this will check both MQ and EQ dirs
	if (DoesFileExist(szFilename))
		return true;

	// check current ui
	if (pLocalPC)
	{
		char UISkin[256] = { 0 };

		sprintf_s(szFilename, "%s\\UI_%s_%s.ini", mq::internal_paths::EverQuest.c_str(), pLocalPC->Name, GetServerShortName());
		GetPrivateProfileString("Main", "UISkin", "default", UISkin, 256, szFilename);

		sprintf_s(szFilename, "uifiles\\%s\\%s", UISkin, filename);

		// this will check both MQ and EQ dirs
		return DoesFileExist(szFilename);
	}

	return false;
}

void DestroyMQUI(const CXStr& strPath)
{
	// delete MQUI.xml files.
	const std::filesystem::path pathMQUI = fmt::format("{}\\{}MQUI.xml", mq::internal_paths::Resources, strPath);
	std::error_code ec;

	DebugSpew("DestroyMQUI: removing file %s", pathMQUI.string().c_str());
	std::filesystem::remove(pathMQUI, ec);
}

void AddXMLFile(const char* filename)
{
	for (const std::string& file : XmlFiles)
	{
		if (!_stricmp(file.c_str(), filename))
			return; // we already added this file
	}

	char szBuffer[MAX_STRING] = { 0 };

	sprintf_s(szBuffer, "uifiles\\%s\\%s", gUISkin, filename);

	if (!DoesFileExist(szBuffer))
	{
		sprintf_s(szBuffer, "uifiles\\default\\%s", filename);
		if (!DoesFileExist(szBuffer))
		{
			WriteChatf("UI file %s not found in either uifiles\\%s or uifiles\\default.  Please copy it there, reload the UI, and reload this plugin.", filename, gUISkin);
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

CXWnd* FindMQ2WindowPath(const char* WindowName)
{
	char nameBuffer[256];
	strcpy_s(nameBuffer, WindowName);

	char* head = nameBuffer;
	char* context = nullptr;

	head = strtok_s(head, "/", &context);

	CXWnd* pWindow = FindMQ2Window(head);
	if (!pWindow) return nullptr;

	while (head = strtok_s(nullptr, "/", &context))
	{
		pWindow = pWindow->GetChildItem(head);
		if (!pWindow) break;
	}

	return pWindow;
}

CXWnd* FindMQ2Window(const char* Name)
{
	if (strchr(Name, '/'))
	{
		return FindMQ2WindowPath(Name);
	}

	std::string_view WindowName{ Name };

	// check toplevel windows first
	auto range = WindowMap.equal_range(WindowName);
	if (range.first != range.second)
	{
		// TODO: add predicates here
		auto iter = std::find_if(range.first, range.second, [](const auto& window)
		{
			return window.second && window.second->IsVisible();
		});

		if (iter != range.second)
			return iter->second;

		return range.first->second;
	}

	// If we're in game, we'll have a profile We can check for some specially named windows.
	if (gGameState == GAMESTATE_INGAME)
	{
		// didnt find one, is it a container?
		ItemPtr pPack;
		if (ci_starts_with(WindowName, "bank"))
		{
			int nPack = GetIntFromString(&WindowName[4], 0) - 1;
			if (nPack >= 0 && nPack < GetAvailableBankSlots())
			{
				pPack = pLocalPC->BankItems.GetItem(nPack - 1);
			}
		}
		else if (ci_starts_with(WindowName, "pack"))
		{
			int nPack = GetIntFromString(&WindowName[4], 0) + InvSlot_FirstBagSlot - 1;

			if (nPack >= InvSlot_FirstBagSlot && nPack <= GetHighestAvailableBagSlot())
			{
				pPack = GetPcProfile()->GetInventorySlot(nPack);
			}
		}
		else if (ci_equals(WindowName, "enviro"))
		{
			pPack = pContainerMgr->GetWorldContainerItem();
		}

		if (pPack)
		{
			return FindContainerForContents(pPack.get());
		}
	}

	return nullptr;
}

bool IsScreenPieceLoaded(const char* screenPiece)
{
	return pSidlMgr && pSidlMgr->FindScreenPieceTemplate(screenPiece) != nullptr;
}

bool SendWndClick2(CXWnd* pWnd, const char* ClickNotification)
{
	if (!pWnd)
		return false;

	for (size_t i = 0; i < lengthof(szClickNotification); i++)
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

		// Selecting an item is a two step process:
		// 1. Change the current selection
		// 2. Emit a notification so that the parent can react.

		if (pWnd->GetType() == UI_Listbox || pWnd->GetType() == UI_TreeView)
		{
			CListWnd* listWnd = static_cast<CListWnd*>(pWnd);
			listWnd->SetCurSel(Value);

			int index = listWnd->GetCurSel();
#pragma warning(suppress : 4312)
			listWnd->ParentWndNotification(listWnd, XWM_LCLICK, (void*)index);

			// Make the new selection visible for the user.
			listWnd->EnsureVisible(index);

			WeDidStuff();
			return true;
		}

		if (pWnd->GetType() == UI_Combobox)
		{
			CComboWnd* comboWnd = static_cast<CComboWnd*>(pWnd);
			comboWnd->SetChoice(Value);

			CListWnd* listWnd = comboWnd->pListWnd;
			int index = listWnd->GetCurSel();
#pragma warning(suppress : 4312)
			listWnd->ParentWndNotification(listWnd, XWM_LCLICK, (void*)index);

			WeDidStuff();
			return true;
		}

		MacroError("Window '%s' child '%s' cannot accept this notification.", WindowName, ScreenID);
		return false;
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

	if (pWnd->GetType() == UI_Listbox || pWnd->GetType() == UI_TreeView)
	{
		CListWnd* listWnd = static_cast<CListWnd*>(pWnd);

		if (ListIndex < listWnd->ItemsArray.Count)
		{
			CListWnd* listWnd = static_cast<CListWnd*>(pWnd);
			listWnd->SetCurSel(ListIndex);

			int index = listWnd->GetCurSel();
#pragma warning(suppress : 4312)
			listWnd->ParentWndNotification(listWnd, XWM_LCLICK, (void*)index);

			// Make the new selection visible for the user.
			listWnd->EnsureVisible(index);

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
			if (ListIndex < listWnd->ItemsArray.Count)
			{
				CComboWnd* comboWnd = static_cast<CComboWnd*>(pWnd);
				comboWnd->SetChoice(ListIndex);

				CListWnd* listWnd = comboWnd->pListWnd;
				int index = listWnd->GetCurSel();
#pragma warning(suppress : 4312)
				listWnd->ParentWndNotification(listWnd, XWM_LCLICK, (void*)index);

				WeDidStuff();
				return true;
			}

			MacroError("Index Out of Bounds in SendListSelect2");
			return false;
		}

		MacroError("Invalid combobox in SendListSelect2");
		return false;
	}

	MacroError("Can only listselect a listbox or combobox.");
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
			comboWnd->SetChoice(Value);

			CListWnd* listWnd = comboWnd->pListWnd;
			int index = listWnd->GetCurSel();
#pragma warning(suppress : 4312)
			listWnd->ParentWndNotification(listWnd, XWM_LCLICK, (void*)index);

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
#pragma warning(suppress : 4311 4302)
		sliderWnd->SetValue(reinterpret_cast<int>(Data));
	}

	pWnd->WndNotification(pChild, Notification, Data);
	WeDidStuff();
	return true;
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

		for (auto& [pWnd, Name] : WindowList)
		{
			if (bOpen)
			{
				if (pWnd && pWnd->IsVisible() && pWnd->GetParentWindow() == nullptr)
				{
					if (bPartial)
					{
						if (Name.find(szArg2) != Name.npos)
						{
							WriteChatf("[PARTIAL MATCH][OPEN] %s", Name.c_str());
							RecurseAndListWindows(pWnd);
							Count++;
						}
					}
					else
					{
						WriteChatf("[OPEN] %s", Name.c_str());
						Count++;
					}
				}
			}
			else
			{
				if (bPartial)
				{
					if (Name.find(szArg2) != Name.npos)
					{
						WriteChatf("[PARTIAL MATCH] %s", Name.c_str());
						RecurseAndListWindows(pWnd);
						Count++;
					}
				}
				else
				{
					WriteChatf("%s", Name.c_str());
					Count++;
				}
			}
		}

		WriteChatf("%d window(s) found with %s in the name", Count, szArg2);
	}
	else
	{
		// list children of..
		CXWnd* pWnd = FindMQ2Window(szLine);
		if (pWnd == nullptr)
		{
			WriteChatf("Window '%s' not available", szLine);
			return;
		}

		WriteChatf("Listing child windows of '%s'", szLine);
		WriteChatColor("-------------------------");

		pWnd = pWnd->GetFirstChildWnd();
		if (pWnd != nullptr)
		{
			Count = RecurseAndListWindows(pWnd);
		}

		WriteChatf("%d child windows", Count);
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
#pragma warning(suppress : 4312)
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

	if (!_stricmp(szArg3, "listselect"))
	{
		if (Data <= 0)
		{
			WriteChatf("\arWndNotify: listselect index out of bounds: %s", szLine);
			return;
		}

		SendListSelect(szArg1, szArg2, Data - 1);
		return;
	}

	if (!_stricmp(szArg3, "comboselect"))
	{
		if (Data <= 0)
		{
			WriteChatf("\arWndNotify: comboselect index out of bounds: %s", szLine);
			return;
		}

		SendComboSelect(szArg1, szArg2, Data - 1);
		return;
	}

	if (!_stricmp(szArg3, "tabselect"))
	{
		if (Data <= 0)
		{
			WriteChatf("\arWndNotify: tabselect index out of bounds: %s", szLine);
			return;
		}

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
#pragma warning(suppress : 4312)
				if (!SendWndNotification(szArg1, nullptr, i, reinterpret_cast<void*>(Data)))
				{
					MacroError("Could not send notification to %s %s", szArg1, szArg2);
				}
			}
#pragma warning(suppress : 4312)
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

	char* szNotification = &szArg2[0];
	CInvSlot* pSlot = nullptr;

	if (!_stricmp(szArg1, "in"))
	{
		if (!szArg4[0])
		{
			WriteChatColor("Syntax: /itemnotify in <bag slot> <slot # in bag> <notification>");
			return;
		}

		ItemGlobalIndex globalIndex;

		if (!_strnicmp(szArg2, "bank", 4))
		{
			int invslot = GetIntFromString(&szArg2[4], 0) - 1;
			int bagslot = GetIntFromString(szArg3, 0) - 1;
			if (invslot >= 0 && invslot < GetAvailableBankSlots())
				globalIndex = ItemGlobalIndex(eItemContainerBank, ItemIndex(invslot, bagslot));
		}
		else if (!_strnicmp(szArg2, "sharedbank", 10))
		{
			int invslot = GetIntFromString(&szArg2[10], 0) - 1;
			int bagslot = GetIntFromString(szArg3, 0) - 1;
			if (invslot >= 0 && invslot < GetAvailableSharedBankSlots())
				globalIndex = ItemGlobalIndex(eItemContainerSharedBank, ItemIndex(invslot, bagslot));
		}
		else if (!_strnicmp(szArg2, "pack", 4))
		{
			int invslot = GetIntFromString(&szArg2[4], 0) - 1;
			int bagslot = GetIntFromString(szArg3, 0) - 1;
			if (invslot >= 0 && invslot < GetAvailableBagSlots())
				globalIndex = ItemGlobalIndex(eItemContainerPossessions, ItemIndex(invslot + InvSlot_FirstBagSlot, bagslot));
		}

		pSlot = pInvSlotMgr->FindInvSlot(globalIndex, false);
		szNotification = &szArg4[0];

		if (!pSlot && globalIndex.IsValidIndex())
		{
			// pSlot was not found (so bag is closed) BUT if we are doing a leftmouseup, we can
			// simulate a click by moving the item to the cursor.
			if (_strnicmp(szNotification, "leftmouseup", 11) == 0)
			{
				// this is the "in" command, so we know the user is trying to locate an item in
				// a bag. Look up the top level bag.
				ItemContainer* itemContainer = GetItemContainerByType(globalIndex.GetLocation());
				if (!itemContainer)
				{
					// We didn't get a valid container. Maybe an invalid parameter?
					WriteChatf("Invalid item container at location %s", GetNameForContainerInstance(globalIndex.GetLocation()));
					return;
				}

				// Find the bag in the item container.
				ItemPtr pContainer = itemContainer->GetItem(globalIndex.GetTopSlot());
				if (!pContainer)
				{
					WriteChatf("There was no container in slot %d", globalIndex.GetTopSlot());
					return;
				}

				if (!pContainer->IsContainer())
				{
					WriteChatf("There was no container in slot %d", globalIndex.GetTopSlot());
					return;
				}

				// Ensure that the specified bagslot is within the proper range
				if (!pContainer->GetHeldItems().IsValidIndex(globalIndex.GetIndex().GetSlot(1)))
				{
					WriteChatf("%d is not a valid slot for this container.", globalIndex.GetIndex().GetSlot(1));
					return;
				}

				// Either drop the item or pick it up, depending on whether we have an item on the cursor or not.
				if (ItemOnCursor())
				{
					DropItem(globalIndex);
				}
				else
				{
					PickupItem(globalIndex);
				}

				return;
			}

			if (_strnicmp(szNotification, "rightmouseup", 12) == 0)
			{
				ItemPtr pItem = FindItemByGlobalIndex(globalIndex);
				if (!pItem)
				{
					WriteChatf("Item '%s' not found.", szArg2);
					return;
				}

				if (globalIndex.GetLocation() != eItemContainerPossessions)
				{
					WriteChatf("Cannot use '%s' because it is not in your inventory.", pItem->GetName());
					return;
				}

				// we fake it with /useitem
				if (pItem->GetItemDefinition()->Clicky.SpellID > 0)
				{
					DoCommandf("/useitem \"%s\"", pItem->GetName());
					return;
				}
			}
		}

		// If we still continue beyond this point, we may have set a pSlot which
		// will be handled below at the end of the function.
	}
	else
	{
		// user didnt specify "in" so it should be outside a container
		// OR it's an item, either way we can "click" it
		int slotNum = -1;
		if (IsNumber(szArg1))
		{
			slotNum = GetIntFromString(szArg1, -1);

			// Check if slotNum falls into the range of inventory slots.
			if (slotNum >= 0 && slotNum < InvSlot_NumInvSlots)
			{
				pSlot = pInvSlotMgr->FindInvSlot(slotNum, -1, eItemContainerPossessions, false);
			}
		}

		// The argument wasn't a number. Check if it is a named slot
		if (slotNum == -1)
		{
			_strlwr_s(szArg1);

			// Check if its a character sheet slot ("charm", "neck", etc...)
			auto iter = ItemSlotMap.find(szArg1);
			if (iter != ItemSlotMap.end())
			{
				int mappedSlot = iter->second;
				pSlot = pInvSlotMgr->FindInvSlot(mappedSlot, -1, eItemContainerPossessions, false);
			}

			// Check if its another type of named container slot
			if (!pSlot)
			{
				ItemGlobalIndex globalIndex;

				if (!_strnicmp(szArg1, "loot", 4))
				{
					int invslot = GetIntFromString(&szArg1[4], 0) - 1;
					globalIndex = ItemGlobalIndex(eItemContainerCorpse, ItemIndex(invslot));
				}
				else if (!_strnicmp(szArg1, "enviro", 6))
				{
					int invslot = GetIntFromString(&szArg1[6], 0) - 1;
					globalIndex = ItemGlobalIndex(eItemContainerWorld, ItemIndex(invslot));
				}
				else if (!_strnicmp(szArg1, "pack", 4))
				{
					int invslot = GetIntFromString(&szArg1[4], 0) - 1 + InvSlot_FirstBagSlot;
					globalIndex = ItemGlobalIndex(eItemContainerPossessions, ItemIndex(invslot));
				}
				else if (!_strnicmp(szArg1, "bank", 4))
				{
					int invslot = GetIntFromString(&szArg1[4], 0) - 1;
					globalIndex = ItemGlobalIndex(eItemContainerBank, ItemIndex(invslot));
				}
				else if (!_strnicmp(szArg1, "sharedbank", 10))
				{
					int invslot = GetIntFromString(&szArg1[10], 0) - 1;
					globalIndex = ItemGlobalIndex(eItemContainerSharedBank, ItemIndex(invslot));
				}
				else if (!_strnicmp(szArg1, "trade", 5))
				{
					int invslot = GetIntFromString(&szArg1[5], 0) - 1;
					globalIndex = ItemGlobalIndex(eItemContainerTrade, ItemIndex(invslot));
				}

				pSlot = GetInvSlot(globalIndex);
			}

			ItemClient* pItem = nullptr;

			// Check if its the name or id of an item.
			if (!pSlot)
			{
				// Starts with #, its an item id
				if (szArg1[0] == '#')
				{
					int id = GetIntFromString(szArg1 + 1, -1);
					if (id > 0)
					{
						pItem = FindItemByID(id);
					}
				}
				else
				{
					pItem = FindItemByName(szArg1, true);
				}

				// Try to get a slot from the item.
				if (pItem)
				{
					pSlot = GetInvSlot(pItem->GetItemLocation());
				}

			}

			// At this point, if we don't have a slot, but we do have an item, there is a chance
			// that we can do something with it.
			if (!pSlot && pItem)
			{
				if (!_strnicmp(szNotification, "leftmouseup", 11))
				{
					if (ItemOnCursor())
					{
						DropItem(pItem->GetItemLocation());
					}
					else
					{
						PickupItem(pItem->GetItemLocation());
					}
				}
				else if (!_strnicmp(szNotification, "rightmouseup", 12))
				{
					if (pItem->GetItemClass() == ItemClass_Spell)
					{
						bool needsClose = false;
						ItemClient* pContainer = nullptr;

						if (IsItemInsideContainer(pItem))
						{
							if (pContainer = FindItemByGlobalIndex(pItem->GetItemLocation().GetParent()))
								needsClose = OpenContainer(pContainer, true);
						}

						CInvSlot* pInvSlot = GetInvSlot(pItem->GetItemLocation());

						if (!pInvSlot || !pInvSlot->pInvSlotWnd || !SendWndClick2(pInvSlot->pInvSlotWnd, szNotification))
						{
							WriteChatf("Could not mem spell, most likely cause bag wasnt open and i didnt find it");
						}

						if (needsClose)
						{
							CloseContainer(pContainer);
						}
						return;
					}

					if (pItem->GetItemDefinition()->Clicky.SpellID != -1)
					{
						DoCommandf("/useitem \"%s\"", pItem->GetName());
						return;
					}

					if (pItem->IsContainer())
					{
						// its a pack, so just open it
						if (pItem->Open)
						{
							CloseContainer(pItem);
						}
						else
						{
							OpenContainer(pItem, false);
						}
					}
				}

				return;
			}

			if (!pSlot)
			{
				WriteChatf("Invalid item slot '%s'", szArg1);
				return;
			}
		}
	}

	if (!pSlot)
	{
		WriteChatf("Could not find slot to send notification to %s %s", szArg1, szArg2);
		return;
	}

	DebugSpew("ItemNotify: Calling SendWndClick");

	if (!pSlot->pInvSlotWnd || !SendWndClick2(pSlot->pInvSlotWnd, szNotification))
	{
		WriteChatf("Could not send notification to %s %s", szArg1, szArg2);
	}
}

void ListItemSlots(SPAWNINFO* pChar, char* szLine)
{
	WriteChatColor("List of available item slots");
	WriteChatColor("-------------------------");

	int count = 0;
	for (int index = 0; index < MAX_INV_SLOTS; index++)
	{
		if (CInvSlot* pSlot = pInvSlotMgr->SlotArray[index])
		{
			if (pSlot->pInvSlotWnd)
			{
				WriteChatf("%d: %d %d", index, pSlot->pInvSlotWnd->ItemLocation.GetLocation(), pSlot->Index);
				count++;
			}
			else if (pSlot->Index)
			{
				WriteChatf("%d: %d", index, pSlot->Index);
			}
		}
	}

	WriteChatf("%d available item slots", count);
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

DETOUR_TRAMPOLINE_DEF(CascadeItemArray*, CreateCascadeMenuItems_Trampoline, ())
CascadeItemArray* CreateCascadeMenuItems_Detour()
{
	CascadeItemArray* array = CreateCascadeMenuItems_Trampoline();

	if (gCascadeItemData.empty())
		return array;

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

//============================================================================

class CDisplay_Detours
{
public:
	void ZoneMainUI_Detour()
	{
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
		if (GetServerIDFromServerName(GetServerShortName()) == ServerID::Invalid)
		{
			// unload
			WriteChatf("MQ does not function on this server: %s -- UNLOADING", GetServerShortName());
			DoCommand("/unload", false);
		}
#endif

		PluginsEndZone();
		ZoneMainUI_Trampoline();
	}

	DETOUR_TRAMPOLINE_DEF(void, ZoneMainUI_Trampoline, ())

		void PreZoneMainUI_Detour()
	{
		PluginsBeginZone();
		PreZoneMainUI_Trampoline();
	}

	DETOUR_TRAMPOLINE_DEF(void, PreZoneMainUI_Trampoline, ())
};

//============================================================================

static void Windows_Initialize()
{
	DebugSpew("Initializing MQ2 Windows");

	strcpy_s(gUISkin, GetCurrentUI().c_str());

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
	EzDetour(__CreateCascadeMenuItems, CreateCascadeMenuItems_Detour, CreateCascadeMenuItems_Trampoline);
	EzDetour(CDisplay__ZoneMainUI, &CDisplay_Detours::ZoneMainUI_Detour, &CDisplay_Detours::ZoneMainUI_Trampoline);
	EzDetour(CDisplay__PreZoneMainUI, &CDisplay_Detours::PreZoneMainUI_Detour, &CDisplay_Detours::PreZoneMainUI_Trampoline);

	AddCommand("/windows", ListWindows);
	AddCommand("/notify", WndNotify);
	AddCommand("/itemnotify", ItemNotify, false, true, true);
	AddCommand("/itemslots", ListItemSlots, false, true, true);

	InitializeWindowList();

	UpdateCascadeMenu();
}

static void Windows_Shutdown()
{
	DebugSpew("Shutting down MQ2 Windows");

	RemoveCascadeMenuItem("Toggle Overlay UI");

	gCascadeItemData.clear();
	UpdateCascadeMenu();

	RemoveCommand("/windows");
	RemoveCommand("/notify");
	RemoveCommand("/itemnotify");
	RemoveCommand("/itemslots");

	RemoveDetour(CDisplay__ZoneMainUI);
	RemoveDetour(CDisplay__PreZoneMainUI);
	RemoveDetour(CXMLSOMDocumentBase__XMLRead);
	RemoveDetour(CSidlScreenWnd__Init1);
	RemoveDetour(CTargetWnd__WndNotification);
	RemoveDetour(CXWndManager__RemoveWnd);
	RemoveDetour(__DoesFileExist);
	RemoveDetour(CMemoryMappedFile__SetFile);
	RemoveDetour(__eqgraphics_fopen);
	RemoveDetour(__CreateCascadeMenuItems);
}

static void Windows_Pulse()
{
	if (gbCascadeMenuNeedsUpdate)
	{
		UpdateCascadeMenu();
	}
}

static void Windows_UpdateImGui()
{
}

} // namespace mq
