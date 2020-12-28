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

// MQ2TargetInfo by EqMule 2018
// 2.1 Added enums for menu and go to menu item
// 2.2 Added fix from dannuic/knightly to stop clearing target when using hotbuttons.
// 2.3 Added a fix for stopping movement by Freezerburn26

#include <mq/Plugin.h>
#include "resource.h"

#include <map>
#include <mutex>
#include <string>

PreSetup("MQ2TargetInfo");
PLUGIN_VERSION(2.3);

// TODO:  Break the group window stuff into its own plugin
// TODO:  Break the specific hotbuttons out into commands that can be used independently

enum TI_MenuCommands
{
	TIMC_MakeMeLeader = 54,
	TIMC_NavToMe = 55,
	TIMC_Runto = 56,
	TIMC_PickupGroundItem = 57,
	TIMC_ClickNearestDoor = 58,
	TIMC_SwitchTo = 59,
	TIMC_FollowMe = 60,
	//show/hide
	TIMC_ComeToMeButton = 61,
	TIMC_MimicMeButton = 62,
	TIMC_FollowMeButton = 63,
	TIMC_HotButtons = 64,
	TIMC_Distance = 65,
};

std::recursive_mutex s_mutex;

bool bDisablePluginDueToBadUI = false;
char szTargetInfo[128] = { "Target Info" };
char szTargetDistance[128] = { "Target Distance" };
char szGroupDistance[128] = { "Member Distance" };
char szCanSeeTarget[128] = { "Can See Target" };
char szPHToolTip[128] = { "Target is a Place Holder" };
char szPH[128] = { "PH" };
char szNavToolTip[MAX_STRING] = { 0 };
char szNavCommand[MAX_STRING] = { 0 };
char szNav[128] = { 0 };
char szFollowMeToolTip[MAX_STRING] = { 0 };
char szFollowMe[128] = { 0 };
char szFollowMeCommand[MAX_STRING] = { 0 };
char szMimicMeToolTip[128] = { "Everyone do what I do, I target something, they do as well, I hail, they hail, etc." };
char szMimicMe[128] = { "Mimic Me" };
char szMMainTip[128] = { "MQ2TargetInfo is Active: Type /groupinfo help or rightclick this window to see a menu" };
char szMimicMeHailCommand[MAX_STRING] = { 0 };
char szMimicMeSayCommand[MAX_STRING] = { 0 };

CLabelWnd* InfoLabel = nullptr;
CLabelWnd* DistanceLabel = nullptr;
CLabelWnd* CanSeeLabel = nullptr;

CButtonWnd* PHButton = nullptr;
CButtonWnd* NavButton = nullptr;
CButtonWnd* FollowMeButton = nullptr;
CButtonWnd* MimicMeButton = nullptr;

CHotButton* GroupHotButton[3] = { nullptr, nullptr, nullptr };

bool gbFollowme = false;
bool gbMimicMe = false;

CXWnd* Target_BuffWindow = nullptr;
CLabelWnd* Target_AggroPctPlayerLabel = nullptr;
CLabelWnd* Target_AggroNameSecondaryLabel = nullptr;
CLabelWnd* Target_AggroPctSecondaryLabel = nullptr;


int Target_BuffWindow_TopOffset = 62 + 14;
int Target_BuffWindow_TopOffsetOld = 50;
int dTopOffset = 46 + 14;
int Target_AggroPctPlayerLabel_TopOffsetOrg = 33;
int Target_AggroNameSecondaryLabel_TopOffsetOrg = 33;
int Target_AggroPctSecondaryLabel_TopOffsetOrg = 33;
int Target_AggroPctPlayerLabel_BottomOffsetOrg = 47;
int Target_AggroNameSecondaryLabel_BottomOffsetOrg = 47;
int Target_AggroPctSecondaryLabel_BottomOffsetOrg = 47;
int dBottomOffset = 60 + 14;
int dBottomOffsetOld = 0;
int CanSeeTopOffset = 33 + 14;
int dLeftOffset = 50;
int dLeftOffsetOld = 0;
int CanSeeBottomOffset = 47 + 14;
int TargetInfoWindowStyle = 0;

constexpr size_t NUM_GROUPWND_CONTROLS = 5;
CGaugeWnd* GW_Gauges[NUM_GROUPWND_CONTROLS] = { nullptr };
CLabelWnd* GroupDistLabels[NUM_GROUPWND_CONTROLS] = { nullptr };

CGaugeWnd* ETW_Gauge[MAX_EXTENDED_TARGET_SIZE] = { nullptr };
CLabelWnd* ETW_DistLabel[MAX_EXTENDED_TARGET_SIZE] = { nullptr };

bool gBUsePerCharSettings = false;
bool gBShowMimicMeButton = true;
bool gBShowComeToMeButton = true;
bool gBShowFollowMeButton = true;
bool gBShowHotButtons = true;
bool gBShowDistance = true;
bool gBShowExtDistance = true;

int rightclickindex = -1;

DWORD orgwstyle = 0;
DWORD orgTargetWindStyle = 0;
DWORD orgExtTargetWindStyle = 0;

int mmlmenuid = 0;
int navmenuid = 0;
int separatorId = 0;
int separatorid2 = 0;
int groundmenuid = 0;
int doormenuid = 0;
int switchtomenuid = 0;
int followmenuid = 0;
int gotomenuid = 0;

int cometomeoptionmenuid = 0;
int mimicmeoptionmenuid = 0;
int followmeoptionmenuid = 0;
int hotoptionmenuid = 0;
int distanceoptionmenuid = 0;

std::map<DWORD, bool> FollowMeMap;

struct PHInfo
{
	std::string Expansion;
	std::string Zone;
	std::string Named;
	std::string Link;
};
std::map<std::string, PHInfo> gPHMap;
bool GetPhMap(SPAWNINFO* pSpawn, PHInfo* pinf);

void CleanUp(bool bUnload);

void ResetIni()
{
	HMODULE hMe = 0;
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)ResetIni, &hMe);
	void* pMyBinaryData = nullptr;

	if (HRSRC hRes = FindResource(hMe, MAKEINTRESOURCE(IDR_INI1), "INI"))
	{
		if (HGLOBAL bin = LoadResource(hMe, hRes))
		{
			bool bResult = false;
			if (pMyBinaryData = LockResource(bin))
			{
				//save it...
				DWORD ressize = SizeofResource(hMe, hRes);
				FILE* File = 0;
				errno_t err = fopen_s(&File, INIFileName, "wb");
				if (!err)
				{
					fwrite(pMyBinaryData, ressize, 1, File);
					fclose(File);
				}
				bResult = UnlockResource(hRes);
			}
			bResult = FreeResource(hRes);
		}
	}

	CleanUp(true);
	bDisablePluginDueToBadUI = false;
}

class MyCTargetWnd
{
public:
	// we can safely use this as its always called when a user leftclicks the target window.
	// also the upside here is that we dont collide with the trade with target detour in mq2windows...
	void HandleBuffRemoveRequest_Tramp(CXWnd*);
	void HandleBuffRemoveRequest_Detour(CXWnd* pWnd)
	{
		if (PHButton && pWnd == PHButton)
		{
			if (pTarget)
			{
				PHInfo pinf;
				if (GetPhMap((SPAWNINFO*)pTarget, &pinf))
				{
					std::string url = "https://webproxy.to/browse.php?b=4&u=";
					url.append(pinf.Link);// https://eqresource.com&b=4";
					//std::string url = "https://www.google.com/search?q=";
					//std::string url = "http://everquest.allakhazam.com/search.html?q=";
					//url.append(pinf.Named);
					if (CHtmlWnd* ItemHtmlwnd = pCWebManager->CreateHtmlWnd(url.c_str(), pinf.Named.c_str(), nullptr, true, pinf.Named.c_str()))
					{
					}
				}
			}
		}
		HandleBuffRemoveRequest_Tramp(pWnd);
	}
};
DETOUR_TRAMPOLINE_EMPTY(void MyCTargetWnd::HandleBuffRemoveRequest_Tramp(CXWnd*));

void LoadPHs(char* szMyName)
{
	// well we have it, lets fill in the map...
	// Chief Librarian Lars^a shissar arbiter, a shissar defiler^tds^kattacastrumdeluge^https://tds.eqresource.com/chieflibrarianlars.php
	PHInfo phinf;
	std::string phs;
	int commapos = 0;
	char szBuffer[MAX_STRING] = { 0 };
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, szMyName, "rb");
	if (!err)
	{
		while (fgets(szBuffer, MAX_STRING, fp) != nullptr)
		{
			if (char* pDest = strchr(szBuffer, '^'))
			{
				pDest[0] = '\0';
				phinf.Named = szBuffer;
				pDest++;

				if (char* pDest2 = strchr(pDest, '^'))
				{
					pDest2[0] = '\0';
					phs = pDest;
					*pDest2++;

					if (pDest = strchr(pDest2, '^'))
					{
						pDest[0] = '\0';
						phinf.Expansion = pDest2;
						pDest++;

						if (pDest2 = strchr(pDest, '^'))
						{
							pDest2[0] = '\0';
							phinf.Zone = pDest;
							pDest2++;

							if (pDest = strchr(pDest2, '\r'))
							{
								pDest[0] = '\0';
							}

							if (pDest = strchr(pDest2, '\n'))
							{
								pDest[0] = '\0';
							}
							phinf.Link = pDest2;
						}
					}
				}
			}

			if (phs.find(",") != phs.npos && phs.find("Yikkarvi,") == phs.npos
				&& phs.find("Furg,") == phs.npos && phs.find("Tykronar,") == phs.npos
				&& phs.find("Ejarld,") == phs.npos && phs.find("Grald,") == phs.npos
				&& phs.find("Graluk,") == phs.npos)
			{
				while ((commapos = phs.find_last_of(",")) != phs.npos)
				{
					// more than one...
					std::string temp = phs.substr(commapos + 2, -1);
					phs.erase(commapos, -1);
					gPHMap[temp] = phinf;
				}
				gPHMap[phs] = phinf;
			}
			else
			{
				gPHMap[phs] = phinf;
			}
		}
		fclose(fp);
	}
}

CLabelWnd* CreateDistLabel(CXWnd* parent, CControlTemplate* DistLabelTemplate, const CXStr& label,
	int font, const CXRect& rect, bool bAlignRight, bool bShow)
{
	uint32_t oldfont = DistLabelTemplate->nFont;
	uint32_t oldstyle = DistLabelTemplate->uStyleBits;
	CXStr oldName = DistLabelTemplate->strName;
	CXStr oldScreenId = DistLabelTemplate->strScreenId;

	DistLabelTemplate->nFont = font;
	DistLabelTemplate->uStyleBits = WSF_AUTOSTRETCHH | WSF_AUTOSTRETCHV | WSF_RELATIVERECT;
	DistLabelTemplate->strName = label;
	DistLabelTemplate->strScreenId = label;

	CLabelWnd* pLabel = (CLabelWnd*)pSidlMgr->CreateXWndFromTemplate(parent, DistLabelTemplate);
	if (pLabel)
	{
		pLabel->SetTopOffset(rect.top);
		pLabel->SetBottomOffset(rect.bottom);
		pLabel->SetLeftOffset(rect.left);
		pLabel->SetRightOffset(rect.right);
		pLabel->SetCRNormal(MQColor(0, 255, 0)); // green
		pLabel->SetBGColor(MQColor(255, 255, 255));
		pLabel->SetTooltip(szGroupDistance);
		pLabel->SetVisible(bShow);
		pLabel->bNoWrap = true;
		pLabel->SetLeftAnchoredToLeft(true);
		pLabel->bAlignRight = bAlignRight;
		pLabel->bAlignCenter = false;
	}

	DistLabelTemplate->uStyleBits = oldstyle;
	DistLabelTemplate->nFont = oldfont;
	DistLabelTemplate->strName = oldName;
	DistLabelTemplate->strScreenId = oldScreenId;

	return pLabel;
}

CLabelWnd* CreateDistLabel(CXWnd* pGwnd, CControlTemplate* DistLabelTemplate, const CXStr& label,
	int font, int top, int bottom, int left, int right, bool bAlignRight, bool bShow)
{
	return CreateDistLabel(pGwnd, DistLabelTemplate, label, font, CXRect(left, top, right, bottom), bAlignRight, bShow);
}

CButtonWnd* CreateAButton(CGroupWnd* pGwnd, CControlTemplate* Template,
	const char* label, const char* labelscreen, int fontsize, const CXRect& rect,
	COLORREF color, COLORREF bgcolor, const char* tooltip, const char* text, bool bShow)
{
	uint32_t oldFont = Template->nFont;
	CXStr oldName = Template->strName;
	CXStr oldScreenID = Template->strScreenId;

	Template->nFont = 1;
	Template->strName = label;
	Template->strScreenId = labelscreen;

	CButtonWnd* pButton = (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pGwnd, Template);
	if (pButton)
	{
		pButton->SetVisible(true);
		pButton->SetTopOffset(rect.top);
		pButton->SetBottomOffset(rect.bottom);
		pButton->SetLeftOffset(rect.left);
		pButton->SetRightOffset(rect.right);
		pButton->SetCRNormal(color);
		pButton->SetBGColor(bgcolor);
		pButton->SetWindowText(text);
		pButton->SetTooltip(tooltip);
		pButton->SetVisible(bShow);
	}

	Template->nFont = oldFont;
	Template->strName = oldName;
	Template->strScreenId = oldScreenID;

	return pButton;
}

CButtonWnd* CreateAButton(CGroupWnd* pGwnd, CControlTemplate* Template,
	const char* label, const char* labelscreen, int fontsize, int top, int bottom, int left, int right,
	COLORREF color, COLORREF bgcolor, const char* tooltip, const char* text, bool bShow)
{
	return CreateAButton(pGwnd, Template, label, labelscreen, fontsize, CXRect(left, top, right, bottom),
		color, bgcolor, tooltip, text, bShow);
}

CHotButton* CreateGroupHotButton(CGroupWnd* pGwnd, CControlTemplate* Template, const CXStr& name,
	const CXRect& rect, int buttonIndex)
{
	CXStr oldName = Template->strName;
	CXStr oldScreenId = Template->strScreenId;

	Template->strName = name;
	Template->strScreenId = name;

	CHotButton* pButton = (CHotButton*)pSidlMgr->CreateHotButtonWnd(pGwnd, Template);
	pButton->BarIndex = 9;
	pButton->ButtonIndex = buttonIndex;
	pButton->SetButtonSize(100, true);
	pButton->SetUseInLayoutVertical(true);

	pButton->SetWindowStyle(WSF_AUTOSTRETCHH | WSF_TRANSPARENT | WSF_AUTOSTRETCHV | WSF_RELATIVERECT);
	pButton->SetClipToParent(true);
	pButton->SetUseInLayoutHorizontal(true);
	pButton->SetLeftAnchoredToLeft(true);
	pButton->SetRightAnchoredToLeft(true);
	pButton->SetTopAnchoredToTop(false);
	pButton->SetBottomAnchoredToTop(false);

	pButton->SetTopOffset(rect.top);
	pButton->SetBottomOffset(rect.bottom);
	pButton->SetLeftOffset(rect.left);
	pButton->SetRightOffset(rect.right);

	pButton->SetCRNormal(MQColor(0, 255, 255));
	pButton->SetBGColor(MQColor(255, 255, 255));
	pButton->SetVisible(gBShowHotButtons);

	Template->strName = oldName;
	Template->strScreenId = oldScreenId;

	return pButton;
}

CHotButton* CreateGroupHotButton(CGroupWnd* pGwnd, CControlTemplate* Template, const CXStr& name,
	int top, int bottom, int left, int right, int buttonindex)
{
	return CreateGroupHotButton(pGwnd, Template, name, CXRect(left, top, bottom, right), buttonindex);
}

void RemoveOurMenu(CGroupWnd* pGwnd)
{
	if (pGwnd->GroupContextMenu)
	{
		pContextMenuManager->Flush();

		if (pGwnd->RoleSelectMenuID)
		{
			pGwnd->GroupContextMenu->RemoveMenuItem(pGwnd->RoleSelectMenuID);
			pGwnd->GroupContextMenu->RemoveMenuItem(pGwnd->RoleSeparatorID);
			pGwnd->RoleSelectMenuID = 0;
			pGwnd->RoleSeparatorID = 0;
		}

		if (separatorid2)
		{
			pGwnd->GroupContextMenu->RemoveMenuItem(followmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(switchtomenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(doormenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(groundmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(gotomenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(navmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(mmlmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(separatorid2);
			followmenuid = 0;
			switchtomenuid = 0;
			doormenuid = 0;
			groundmenuid = 0;
			gotomenuid = 0;
			navmenuid = 0;
			mmlmenuid = 0;
			separatorid2 = 0;
		}

		if (separatorId)
		{
			pGwnd->GroupContextMenu->RemoveMenuItem(distanceoptionmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(hotoptionmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(followmeoptionmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(mimicmeoptionmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(cometomeoptionmenuid);

			pGwnd->GroupContextMenu->RemoveMenuItem(separatorId);

			distanceoptionmenuid = 0;
			hotoptionmenuid = 0;
			followmeoptionmenuid = 0;
			mimicmeoptionmenuid = 0;
			cometomeoptionmenuid = 0;
			separatorId = 0;
		}
	}
}

void AddOurMenu(CGroupWnd* pGwnd, bool bMemberClicked, int index)
{
	if (pGwnd->GroupContextMenu)
	{
		RemoveOurMenu(pGwnd);
		separatorId = pGwnd->GroupContextMenu->AddSeparator();
		cometomeoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Come to Me Button", TIMC_ComeToMeButton, gBShowComeToMeButton);
		mimicmeoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Mimic Me Button", TIMC_MimicMeButton, gBShowMimicMeButton);
		followmeoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Follow Button", TIMC_FollowMeButton, gBShowFollowMeButton);
		hotoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Hot Buttons", TIMC_HotButtons, gBShowHotButtons);
		distanceoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Distance", TIMC_Distance, gBShowDistance);

		if (bMemberClicked)
		{
			separatorid2 = pGwnd->GroupContextMenu->AddSeparator();
			mmlmenuid = pGwnd->GroupContextMenu->AddMenuItem("Make Me Leader", TIMC_MakeMeLeader);
			navmenuid = pGwnd->GroupContextMenu->AddMenuItem("Run To Me", TIMC_NavToMe);
			gotomenuid = pGwnd->GroupContextMenu->AddMenuItem("Run To...", TIMC_Runto);
			groundmenuid = pGwnd->GroupContextMenu->AddMenuItem("Pick Up Nearest Ground Item", TIMC_PickupGroundItem);
			doormenuid = pGwnd->GroupContextMenu->AddMenuItem("Click Nearest Door", TIMC_ClickNearestDoor);
			switchtomenuid = pGwnd->GroupContextMenu->AddMenuItem("Switch to...", TIMC_SwitchTo);

			if (FollowMeMap.find(index) != FollowMeMap.end())
			{
				if (FollowMeMap[index] == true)
				{
					followmenuid = pGwnd->GroupContextMenu->AddMenuItem("Stop Following Me", TIMC_FollowMe);
				}
				else
				{
					followmenuid = pGwnd->GroupContextMenu->AddMenuItem("Follow Me", TIMC_FollowMe);
				}
			}
			else
			{
				followmenuid = pGwnd->GroupContextMenu->AddMenuItem("Follow Me", TIMC_FollowMe);
			}
		}
		pContextMenuManager->Flush();
	}
}

bool CheckNavCommand()
{
	if (strstr(szNavCommand, "/bc"))
	{
		bool bConnectedtoEqBCs = false;
		if (HMODULE hMod = GetModuleHandle("mq2eqbc"))
		{
			unsigned short(*fisConnected)();
			if (fisConnected = (unsigned short(*)())GetProcAddress(hMod, "isConnected"))
			{
				if (fisConnected())
				{
					bConnectedtoEqBCs = true;
				}
			}
		}
		if (!bConnectedtoEqBCs)
		{
			WriteChatf("%s only works if mq2eqbc is loaded and eqbcs is started, Please run /plugin mq2eqbc and then /bccmd connect", szNavCommand);
			return false;
		}
	}
	else if (strstr(szNavCommand, "/dg"))
	{
		bool bConnectedtoEqBCs = false;
		if (!GetModuleHandle("mq2dannet"))
		{
			WriteChatf("%s only works if mq2dannet is loaded, Please run /plugin mq2dannet", szNavCommand);
			return false;
		}
	}

	return true;
}

void WriteSetting(const char* Key, const char* value)
{
	char szSettingINISection[MAX_STRING] = { 0 };

	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0' || !gBUsePerCharSettings)
	{
		strcpy_s(szSettingINISection, "Default");
	}
	else
	{
		sprintf_s(szSettingINISection, "%s_%s", EQADDR_SERVERNAME, ((SPAWNINFO*)pLocalPlayer)->Name);
	}

	WritePrivateProfileString(szSettingINISection, Key, value, INIFileName);
	int ival = GetIntFromString(value, 0);
	WriteChatf("\ayMQ2TargetInfo\ax::\am%s is now %s\ax.", Key, ival ? "\aoON" : "\agOFF");
}

void WriteUIStringSetting(const char* Key, const char* value)
{
	char szSettingINISection[MAX_STRING] = { 0 };
	char szUI[MAX_STRING] = { 0 };
	char szFilename[MAX_STRING] = { 0 };

	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0')
	{
		return; // better not mess with this if we are not ingame...
	}
	else
	{
		sprintf_s(szFilename, "UI_%s_%s.ini", ((SPAWNINFO*)pLocalPlayer)->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "Unknown", szUI, MAX_STRING, szFilename);
		sprintf_s(szSettingINISection, "UI_%s", szUI);
	}

	WritePrivateProfileString(szSettingINISection, Key, value, INIFileName);
	int ival = GetIntFromString(value, 0);
	WriteChatf("\ayMQ2TargetInfo\ax::\am%s is now %s\ax.", Key, ival ? "\aoON" : "\agOFF");
}

template <unsigned int _Size>
LPSTR ReadUIStringSetting(char* Key, char* defaultval, char(&_Out)[_Size])
{
	char szSettingINISection[MAX_STRING] = { 0 };
	char szUI[MAX_STRING] = { 0 };
	char szFilename[MAX_STRING] = { 0 };

	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0')
	{
		strcpy_s(_Out, _Size, defaultval);
		return _Out;//better not mess with this if we are not ingame...
	}
	else
	{
		sprintf_s(szFilename, "UI_%s_%s.ini", ((SPAWNINFO*)pLocalPlayer)->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "Unknown", szUI, MAX_STRING, szFilename);
		sprintf_s(szSettingINISection, "UI_%s", szUI);
	}

	int ret = GetPrivateProfileString(szSettingINISection, Key, "", _Out, _Size, INIFileName);
	if (_Out[0] == '\0')
	{
		if (!_stricmp(Key, "DynamicUI"))
		{
			// first time they are running this version, reset all their stuff.
			WritePrivateProfileString(szSettingINISection, "GroupWindowLoc", nullptr, INIFileName);
			WritePrivateProfileString(szSettingINISection, "TargetInfoLoc", nullptr, INIFileName);
			WritePrivateProfileString(szSettingINISection, "TargetDistanceLoc", nullptr, INIFileName);
			WritePrivateProfileString(szSettingINISection, "ExtDistanceLoc", nullptr, INIFileName);
			WritePrivateProfileString(szSettingINISection, "GroupDistanceLoc", nullptr, INIFileName);
		}

		WritePrivateProfileString(szSettingINISection, Key, defaultval, INIFileName);
		strcpy_s(_Out, _Size, defaultval);
	}

	return _Out;
}

bool ReadUILocSetting(char* Key, int top, int bottom, int left, int right, CXRect& rect)
{
	char szSettingINISection[MAX_STRING] = { 0 };
	char szUI[MAX_STRING] = { 0 };
	char szFilename[MAX_STRING] = { 0 };

	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0')
	{
		rect.top = top;
		rect.bottom = bottom;
		rect.left = left;
		rect.right = right;
		return false;
	}
	else
	{
		sprintf_s(szFilename, "UI_%s_%s.ini", ((SPAWNINFO*)pLocalPlayer)->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "Unknown", szUI, MAX_STRING, szFilename);
		sprintf_s(szSettingINISection, "UI_%s", szUI);
	}

	sprintf_s(szUI, "%d,%d,%d,%d", top, bottom, left, right);
	int ret = GetPrivateProfileString(szSettingINISection, Key, "", szFilename, MAX_STRING, INIFileName);

	if (szFilename[0] == '\0')
	{
		WritePrivateProfileString(szSettingINISection, Key, szUI, INIFileName);
		rect.top = top;
		rect.bottom = bottom;
		rect.left = left;
		rect.right = right;
		return false;
	}

	char* token1 = nullptr;
	char* next_token1 = nullptr;
	char szLocs[4][8];
	token1 = strtok_s(szFilename, ",", &next_token1);
	int j = 0;
	while (token1 != nullptr)
	{
		if (token1 != nullptr)
		{
			strcpy_s(szLocs[j], token1);
			token1 = strtok_s(nullptr, ",", &next_token1);
			j++;
		}
	}

	rect.top = GetIntFromString(szLocs[0], rect.top);
	rect.bottom = GetIntFromString(szLocs[1], rect.bottom);
	rect.left = GetIntFromString(szLocs[2], rect.left);
	rect.right = GetIntFromString(szLocs[3], rect.right);
	return true;
}

template <unsigned int _Size>
LPSTR ReadStringSetting(char* Key, char* defaultval, char(&_Out)[_Size])
{
	char szSettingINISection[MAX_STRING] = { 0 };
	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0' || !gBUsePerCharSettings)
	{
		strcpy_s(szSettingINISection, "Default");
	}
	else
	{
		sprintf_s(szSettingINISection, "%s_%s", EQADDR_SERVERNAME, ((SPAWNINFO*)pLocalPlayer)->Name);
	}

	int ret = GetPrivateProfileString(szSettingINISection, Key, "", _Out, _Size, INIFileName);
	if (_Out[0] == '\0')
	{
		WritePrivateProfileString(szSettingINISection, Key, defaultval, INIFileName);
		strcpy_s(_Out, _Size, defaultval);
	}

	return _Out;
}

int ReadSetting(char* Key, int defaultval)
{
	char szSettingINISection[MAX_STRING] = { 0 };
	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0' || !gBUsePerCharSettings)
	{
		strcpy_s(szSettingINISection, "Default");
	}
	else
	{
		sprintf_s(szSettingINISection, "%s_%s", EQADDR_SERVERNAME, ((SPAWNINFO*)pLocalPlayer)->Name);
	}

	int ret = GetPrivateProfileInt(szSettingINISection, Key, -1, INIFileName);
	if (ret == -1)
	{
		WritePrivateProfileString(szSettingINISection, Key, std::to_string(defaultval), INIFileName);
		return defaultval;
	}
	else
	{
		if (!_stricmp(Key, "HotButtonBottom"))
		{
			if (ret == 7)
			{
				WriteChatf("MQ2TargetInfo.ini changed: Setting HotButtonBottom to %d because it was 7 and that makes it cover the disband button so it can't be clicked.", defaultval);
				WritePrivateProfileString(szSettingINISection, Key, std::to_string(defaultval), INIFileName);
				return defaultval;
			}
		}
		else if (!_stricmp(Key, "MimicMeTop"))
		{
			if (ret == 102)
			{
				WriteChatf("MQ2TargetInfo.ini changed: Setting MimicMeTop to %d because it was 102 and that is no longer the default.", defaultval);
				WritePrivateProfileString(szSettingINISection, Key, "64", INIFileName);
				WritePrivateProfileString(szSettingINISection, "MimicMeBottom", "31", INIFileName);
				WritePrivateProfileString(szSettingINISection, "MimicMeLeft", "92", INIFileName);
				WritePrivateProfileString(szSettingINISection, "MimicMeRight", "132", INIFileName);
				return defaultval;
			}
		}
	}

	return ret;
}

void ReadIniSettings()
{
	char szSettingINISection[MAX_STRING] = { 0 };
	char szVersion[MAX_STRING] = { 0 };
	int ret = GetPrivateProfileString("Default", "PluginVersion", "", szVersion, MAX_STRING, INIFileName);

	if (szVersion[0] == '\0')
	{
		ResetIni();
		char szTemp[MAX_STRING] = { 0 };
		sprintf_s(szTemp, "%.1f", MQ2Version);
		WritePrivateProfileString("Default", "PluginVersion", szTemp, INIFileName);
	}

	ret = GetPrivateProfileInt("Default", "UsePerCharSettings", -1, INIFileName);
	gBUsePerCharSettings = (ret == 0 ? false : true);
	if (ret == -1)
	{
		gBUsePerCharSettings = 0;
		WritePrivateProfileString("Default", "UsePerCharSettings", "0", INIFileName);
	}

	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0' || gBUsePerCharSettings == false)
	{
		strcpy_s(szSettingINISection, "Default");
	}
	else
	{
		sprintf_s(szSettingINISection, "%s_%s", EQADDR_SERVERNAME, ((SPAWNINFO*)pLocalPlayer)->Name);
	}

	// cleanup old crap
	WritePrivateProfileString(szSettingINISection, "ComeToMeTop", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "ComeToMeBottom", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "ComeToMeLeft", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "ComeToMeRight", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "FollowMeTop", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "FollowMeBottom", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "FollowMeLeft", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "FollowMeRight", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "MimicMeTop", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "MimicMeBottom", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "MimicMeLeft", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "MimicMeRight", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton0Top", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton0Bottom", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton0Left", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton0Right", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton1Top", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton1Bottom", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton1Left", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton1Right", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton2Top", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton2Bottom", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton2Left", nullptr, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton2Right", nullptr, INIFileName);

	ret = GetPrivateProfileInt(szSettingINISection, "ShowMimicMeButton", -1, INIFileName);
	gBShowMimicMeButton = (ret == 0 ? false : true);
	if (ret == -1)
	{
		WritePrivateProfileString(szSettingINISection, "ShowMimicMeButton", "1", INIFileName);
	}

	ret = GetPrivateProfileInt(szSettingINISection, "ShowComeToMeButton", -1, INIFileName);
	gBShowComeToMeButton = (ret == 0 ? false : true);
	if (ret == -1)
	{
		WritePrivateProfileString(szSettingINISection, "ShowComeToMeButton", "1", INIFileName);
	}

	ret = GetPrivateProfileInt(szSettingINISection, "ShowFollowMeButton", -1, INIFileName);
	gBShowFollowMeButton = (ret == 0 ? false : true);
	if (ret == -1)
	{
		WritePrivateProfileString(szSettingINISection, "ShowFollowMeButton", "1", INIFileName);
	}

	ret = GetPrivateProfileInt(szSettingINISection, "ShowHotButtons", -1, INIFileName);
	gBShowHotButtons = (ret == 0 ? false : true);
	if (ret == -1)
	{
		ret = GetPrivateProfileInt(szSettingINISection, "ShowHotButton", -1, INIFileName);

		WritePrivateProfileString(szSettingINISection, "HotButtonTop", nullptr, INIFileName);
		WritePrivateProfileString(szSettingINISection, "HotButtonBottom", nullptr, INIFileName);
		WritePrivateProfileString(szSettingINISection, "HotButtonLeft", nullptr, INIFileName);
		WritePrivateProfileString(szSettingINISection, "HotButtonRight", nullptr, INIFileName);
		WritePrivateProfileString(szSettingINISection, "ShowHotButton", nullptr, INIFileName);
		if (ret == 0)
		{
			WritePrivateProfileString(szSettingINISection, "ShowHotButtons", "0", INIFileName);
			gBShowHotButtons = false;
		}
		else
		{
			WritePrivateProfileString(szSettingINISection, "ShowHotButtons", "1", INIFileName);
		}
	}

	ret = GetPrivateProfileInt(szSettingINISection, "ShowDistance", -1, INIFileName);
	gBShowDistance = (ret == 0 ? false : true);
	if (ret == -1)
	{
		WritePrivateProfileString(szSettingINISection, "ShowDistance", "1", INIFileName);
	}

	ret = GetPrivateProfileInt(szSettingINISection, "ShowExtDistance", -1, INIFileName);
	gBShowExtDistance = (ret == 0 ? false : true);
	if (ret == -1)
	{
		WritePrivateProfileString(szSettingINISection, "ShowExtDistance", "1", INIFileName);
	}
}

void Initialize()
{
	if (!PHButton && GetGameState() == GAMESTATE_INGAME && !bDisablePluginDueToBadUI)
	{
		ReadIniSettings();
		char szBuff[MAX_STRING] = { 0 };
		ReadUIStringSetting("Target_BuffWindow_TopOffset", "76", szBuff);
		Target_BuffWindow_TopOffset = GetIntFromString(szBuff, 76);
		ReadUIStringSetting("dTopOffset", "60", szBuff);
		dTopOffset = GetIntFromString(szBuff, 60);
		ReadUIStringSetting("dBottomOffset", "74", szBuff);
		dBottomOffset = GetIntFromString(szBuff, 74);
		ReadUIStringSetting("CanSeeTopOffset", "47", szBuff);
		CanSeeTopOffset = GetIntFromString(szBuff, 47);
		ReadUIStringSetting("CanSeeBottomOffset", "61", szBuff);
		CanSeeBottomOffset = GetIntFromString(szBuff, 61);
		ReadUIStringSetting("dLeftOffset", "50", szBuff);
		dLeftOffset = GetIntFromString(szBuff, 50);
		ReadUIStringSetting("TargetInfoWindowStyle", "0", szBuff);
		TargetInfoWindowStyle = GetIntFromString(szBuff, 0);

		// Player_ManaLabel ManaLabel 20
		// Player_FatigueLabel FatigueLabel 21
		char OldName1[128] = { "Player_ManaLabel" };
		char OldScreenName1[128] = { "ManaLabel" };
		char OldController1[128] = { "20" };
		char OldName2[128] = { "Player_FatigueLabel" };
		char OldScreenName2[128] = { "FatigueLabel" };
		char OldController2[128] = { "21" };

		ReadUIStringSetting("Label1", "Player_ManaLabel", OldName1);
		ReadUIStringSetting("Label2", "Player_FatigueLabel", OldName2);

		char szDynamic[MAX_STRING] = { 0 };
		ReadUIStringSetting("DynamicUI", "1", szDynamic);
		int isDynamic = GetIntFromString(szDynamic, 1);

		// setup the group info
		if (pGroupWnd)
		{
			orgwstyle = pGroupWnd->GetWindowStyle();
			if (orgwstyle & WSF_TITLEBAR)
			{
				pGroupWnd->AddStyle(WSF_SIZABLE | WSF_BORDER);
			}
			else
			{
				pGroupWnd->AddStyle(WSF_CLIENTMOVABLE | WSF_SIZABLE | WSF_BORDER);
			}

			pGroupWnd->SetTooltip(szMMainTip);

			if (pGroupWnd->GroupContextMenu)
			{
				pGroupWnd->GroupContextMenu->SetCRNormal(0xFF000000);
				pGroupWnd->GroupContextMenu->SetDisabledBackground(0xFF000000);
				pGroupWnd->GroupContextMenu->SetBGColor(0xFF000000);
			}

			// AddOurMenu(pGwnd);
			for (size_t i = 0; i < NUM_GROUPWND_CONTROLS; ++i)
			{
				char szName[32] = { 0 };
				sprintf_s(szName, "Gauge%d", i + 1);

				GW_Gauges[i] = (CGaugeWnd*)pGroupWnd->GetChildItem(szName);
			}

			CControlTemplate* DistLabelTemplateOrg = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("SL_DestNameLabel");
			CControlTemplate* DistLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate(OldName1);
			CControlTemplate* NavButtonTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("GW_InviteButton"); // borrowing this...
			CControlTemplate* HBButtonTemplate1 = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("HB_Button1");
			CControlTemplate* HBButtonTemplate2 = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("HB_Button2");
			CControlTemplate* HBButtonTemplate3 = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("HB_Button3");

			if (GW_Gauges[0] && DistLabelTemplate)
			{
				strcpy_s(OldName1, DistLabelTemplate->strName.c_str());
				strcpy_s(OldScreenName1, DistLabelTemplate->strScreenId.c_str());
				strcpy_s(OldController1, DistLabelTemplate->strController.c_str());

				DistLabelTemplate->strController = "0";

				// create the distance label 1
				char szLoc[MAX_STRING] = { 0 };
				char szOutLoc[MAX_STRING] = { 0 };

				ReadUIStringSetting("GroupDistanceFontSize", "2", szOutLoc);
				int GroupDistanceFontSize = GetIntFromString(szOutLoc, 2);
				ReadUIStringSetting("UseGroupLayoutBox", "0", szOutLoc);
				int UseLayoutBox = GetIntFromString(szOutLoc, 0);
				sprintf_s(szLoc, "%d,%d,%d,%d", 0, -20, 70, 0);
				ReadUIStringSetting("GroupDistanceLoc", szLoc, szOutLoc);
				char* token1 = nullptr;
				char* next_token1 = nullptr;
				char szLocs[4][8];
				token1 = strtok_s(szOutLoc, ",", &next_token1);
				int j = 0;

				while (token1 != nullptr)
				{
					if (token1 != nullptr)
					{
						strcpy_s(szLocs[j], token1);
						token1 = strtok_s(nullptr, ",", &next_token1);
						j++;
					}
				}

				int ttop = GetIntFromString(szLocs[0], 0);
				int tbottom = GetIntFromString(szLocs[1], 0);
				int tleft = GetIntFromString(szLocs[2], 0);
				int tright = GetIntFromString(szLocs[3], 0);
				CXRect tPos{ tleft, ttop, tright, tbottom };

				if (UseLayoutBox) // they have a weird UI like sars that uses a layout box these UI's dont have any locations we can read
				{
					ReadUIStringSetting("GroupDistanceOffset", "0", szOutLoc);
					int GroupDistanceOffset = GetIntFromString(szOutLoc, 0);
					tPos.top += GroupDistanceOffset;

					ReadUIStringSetting("GroupDistanceElementPrefix", "GW_Gauge", szOutLoc);

					for (size_t i = 0; i < NUM_GROUPWND_CONTROLS; ++i)
					{
						sprintf_s(szLoc, "%s%d", szOutLoc, i + 1);
						if (CXWnd* wnd = pGroupWnd->GetChildItem(szLoc))
						{
							char labelName[20] = { 0 };
							sprintf_s(labelName, "Group_DistLabel%d", i + 1);

							GroupDistLabels[i] = CreateDistLabel(wnd, DistLabelTemplate, labelName, GroupDistanceFontSize,
								wnd->GetLocation() + tPos, true, gBShowDistance);
						}
					}
				}
				else
				{
					if (isDynamic)
					{
						for (size_t i = 0; i < NUM_GROUPWND_CONTROLS; ++i)
						{
							char labelName[20] = { 0 };
							sprintf_s(labelName, "Group_DistLabel%d", i + 1);

							CXRect rect(GW_Gauges[i]->GetLeftOffset(), GW_Gauges[i]->GetTopOffset(), GW_Gauges[i]->GetRightOffset(), GW_Gauges[i]->GetBottomOffset());

							GroupDistLabels[i] = CreateDistLabel(pGroupWnd, DistLabelTemplate, "Group_DistLabel1", GroupDistanceFontSize, rect + tPos, true, gBShowDistance);
						}
					}
					else
					{
						for (size_t i = 0; i < NUM_GROUPWND_CONTROLS; ++i)
						{
							char labelName[20] = { 0 };
							sprintf_s(labelName, "Group_DistLabel%d", i + 1);

							CXRect rect = GW_Gauges[i]->GetLocation() + tPos;
							GroupDistLabels[i] = CreateDistLabel(pGroupWnd, DistLabelTemplate, "Group_DistLabel1", GroupDistanceFontSize, rect, true, gBShowDistance);
						}
					}
				}

				// create Nav All to Me Button
				if (NavButtonTemplate)
				{
					int oldfont = NavButtonTemplate->nFont;
					bool oldbRelativePosition = NavButtonTemplate->bRelativePosition;
					bool oldbAutoStretchVertical = NavButtonTemplate->bAutoStretchVertical;
					bool oldbAutoStretchHorizontal = NavButtonTemplate->bAutoStretchHorizontal;
					bool oldbTopAnchorToTop = NavButtonTemplate->bTopAnchorToTop;
					bool oldbBottomAnchorToTop = NavButtonTemplate->bBottomAnchorToTop;
					bool oldbLeftAnchorToLeft = NavButtonTemplate->bLeftAnchorToLeft;
					bool oldbRightAnchorToLeft = NavButtonTemplate->bRightAnchorToLeft;
					DWORD oldStyleBits = NavButtonTemplate->uStyleBits;

					// setup our template the way we want it:
					NavButtonTemplate->uStyleBits = WSF_AUTOSTRETCHH | WSF_AUTOSTRETCHV | WSF_RELATIVERECT;
					NavButtonTemplate->bRightAnchorToLeft = true;
					NavButtonTemplate->bLeftAnchorToLeft = true;
					NavButtonTemplate->bBottomAnchorToTop = false;
					NavButtonTemplate->bTopAnchorToTop = false;
					NavButtonTemplate->bAutoStretchHorizontal = true;
					NavButtonTemplate->bAutoStretchVertical = true;
					NavButtonTemplate->bRelativePosition = true;

					CButtonWnd* Butt = (CButtonWnd*)pGroupWnd->GetChildItem("GW_InviteButton");

					// Come To Me button
					// We let people customize what this button does:
					ReadStringSetting("ComeToMeText", "Come To Me", szNav);
					ReadStringSetting("ComeToMeCommand", "/bcg //nav id ${Me.ID}", szNavCommand);
					ReadStringSetting("ComeToMeToolTip", szNavCommand, szNavToolTip);

					CXRect rc;
					ReadUILocSetting("ComeToMeLoc", 61, 27, 6, 46, rc);
					NavButton = CreateAButton(pGroupWnd, NavButtonTemplate, "GW_NavButton", "NavButton", 1, rc, 0xFF00FFFF, 0xFFFFFFFF, szNavToolTip, szNav, gBShowComeToMeButton);

					// Follow Me button
					ReadStringSetting("FollowMeText", "Follow Me", szFollowMe);
					ReadStringSetting("FollowMeCommand", "/bcg //afollow spawn ${Me.ID}", szFollowMeCommand);
					ReadStringSetting("FollowMeeToolTip", szFollowMeCommand, szFollowMeToolTip);

					ReadUILocSetting("FollowMeLoc", 61, 27, 48, 88, rc);
					FollowMeButton = CreateAButton(pGroupWnd, NavButtonTemplate, "GW_FollowMeButton", "FollowMeButton", 1, rc, 0xFF00FFFF, 0xFFFFFFFF, szFollowMeToolTip, szFollowMe, gBShowFollowMeButton);

					// Mimic Me button
					ReadUILocSetting("MimicMeLoc", 61, 27, 90, 130, rc);
					MimicMeButton = CreateAButton(pGroupWnd, NavButtonTemplate, "GW_MimicMeButton", "MimicMeButton", 1, rc, 0xFF00FFFF, 0xFFFFFFFF, szMimicMeToolTip, szMimicMe, gBShowMimicMeButton);

					ReadStringSetting("MimicMeSayCommand", "/bcg //say", szMimicMeSayCommand);
					ReadStringSetting("MimicMeHailCommand", "/bcg //keypress HAIL", szMimicMeHailCommand);

					// Hotbutton0
					ReadUILocSetting("HotButton0Loc", 97, 64, 6, 46, rc);
					GroupHotButton[0] = CreateGroupHotButton(pGroupWnd, HBButtonTemplate1, "GW_HotButton1", rc, 0);

					// Hotbutton1
					ReadUILocSetting("HotButton1Loc", 97, 64, 49, 89, rc);
					GroupHotButton[1] = CreateGroupHotButton(pGroupWnd, HBButtonTemplate2, "GW_HotButton2", rc, 1);

					// Hotbutton2
					ReadUILocSetting("HotButton2Loc", 97, 64, 92, 132, rc);
					GroupHotButton[2] = CreateGroupHotButton(pGroupWnd, HBButtonTemplate3, "GW_HotButton3", rc, 2);

					// now set the template values back
					NavButtonTemplate->strName = "GW_InviteButton";
					NavButtonTemplate->strScreenId = "InviteButton";
					NavButtonTemplate->bRelativePosition = oldbRelativePosition;
					NavButtonTemplate->bAutoStretchVertical = oldbAutoStretchVertical;
					NavButtonTemplate->bAutoStretchHorizontal = oldbAutoStretchHorizontal;
					NavButtonTemplate->bTopAnchorToTop = oldbTopAnchorToTop;
					NavButtonTemplate->bBottomAnchorToTop = oldbBottomAnchorToTop;
					NavButtonTemplate->bLeftAnchorToLeft = oldbLeftAnchorToLeft;
					NavButtonTemplate->bRightAnchorToLeft = oldbRightAnchorToLeft;
					NavButtonTemplate->uStyleBits = oldStyleBits;
					NavButtonTemplate->nFont = oldfont;
				}

				// now set the template values back
				DistLabelTemplate->strName = OldName1;
				DistLabelTemplate->strScreenId = OldScreenName1;
				DistLabelTemplate->strController = OldController1;
			}
			else
{
				bDisablePluginDueToBadUI = true;
				WriteChatf("MQ2TargetInfo has been disabled due to an incompatible UI, let a developer know.");
				return;
			}
		}

		// setup the targetinfo
		if (pTargetWnd)
		{
			orgTargetWindStyle = pTargetWnd->GetWindowStyle();

			// orig style for default ui is 0x00200a40
			if (orgTargetWindStyle & WSF_TITLEBAR)
			{
				pTargetWnd->AddStyle(WSF_SIZABLE | WSF_BORDER);
			}
			else
			{
				if (TargetInfoWindowStyle == 0)
				{
					pTargetWnd->AddStyle(WSF_CLIENTMOVABLE | WSF_SIZABLE | WSF_BORDER);
				}
				else
				{
					pTargetWnd->SetWindowStyle(TargetInfoWindowStyle);
				}
			}

			if (Target_AggroPctPlayerLabel = (CLabelWnd*)pTargetWnd->GetChildItem("Target_AggroPctPlayerLabel"))
			{
				Target_AggroPctPlayerLabel->SetBGColor(0xFF00000);
				Target_AggroPctPlayerLabel_TopOffsetOrg = Target_AggroPctPlayerLabel->GetTopOffset();
				Target_AggroPctPlayerLabel->SetTopOffset(dTopOffset);
				Target_AggroPctPlayerLabel_BottomOffsetOrg = Target_AggroPctPlayerLabel->GetBottomOffset();
				Target_AggroPctPlayerLabel->SetBottomOffset(dBottomOffset);
			}

			if (Target_AggroNameSecondaryLabel = (CLabelWnd*)pTargetWnd->GetChildItem("Target_AggroNameSecondaryLabel"))
			{
				Target_AggroNameSecondaryLabel->SetBGColor(0xFF00000);
				Target_AggroNameSecondaryLabel_TopOffsetOrg = Target_AggroNameSecondaryLabel->GetTopOffset();
				Target_AggroNameSecondaryLabel->SetTopOffset(dTopOffset);
				Target_AggroNameSecondaryLabel_BottomOffsetOrg = Target_AggroNameSecondaryLabel->GetBottomOffset();
				Target_AggroNameSecondaryLabel->SetBottomOffset(dBottomOffset);
			}

			if (Target_AggroPctSecondaryLabel = (CLabelWnd*)pTargetWnd->GetChildItem("Target_AggroPctSecondaryLabel"))
			{
				Target_AggroPctSecondaryLabel->SetBGColor(0xFF00000);
				Target_AggroPctSecondaryLabel_TopOffsetOrg = Target_AggroPctSecondaryLabel->GetTopOffset();
				Target_AggroPctSecondaryLabel->SetTopOffset(dTopOffset);
				Target_AggroPctSecondaryLabel_BottomOffsetOrg = Target_AggroPctSecondaryLabel->GetBottomOffset();
				Target_AggroPctSecondaryLabel->SetBottomOffset(dBottomOffset);
			}

			if (Target_BuffWindow = pTargetWnd->GetChildItem("Target_BuffWindow"))
			{
				Target_BuffWindow->SetBGColor(0xFF000000);
				Target_BuffWindow_TopOffsetOld = Target_BuffWindow->GetTopOffset();
				Target_BuffWindow->SetTopOffset(Target_BuffWindow_TopOffset);
			}

			CControlTemplate* DistLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate(OldName1);
			CControlTemplate* CanSeeLabelTemplateOrg = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("Player_FatigueLabel");
			CControlTemplate* CanSeeLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate(OldName2);
			CControlTemplate* PHButtonTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("IDW_ModButton"); // borrowing this...

			if (PHButtonTemplate && CanSeeLabelTemplate && DistLabelTemplate)
			{
				int oldphfont = PHButtonTemplate->nFont;

				strcpy_s(OldName1, DistLabelTemplate->strName.c_str());
				strcpy_s(OldScreenName1, DistLabelTemplate->strScreenId.c_str());
				strcpy_s(OldController1, DistLabelTemplate->strController.c_str());
				int oldfont = DistLabelTemplate->nFont;
				strcpy_s(OldName2, CanSeeLabelTemplate->strName.c_str());
				strcpy_s(OldScreenName2, CanSeeLabelTemplate->strScreenId.c_str());
				strcpy_s(OldController2, CanSeeLabelTemplate->strController.c_str());
				DistLabelTemplate->nFont = 2;
				DistLabelTemplate->strController = "0";
				CanSeeLabelTemplate->strController = "0";

				// create the info label
				DistLabelTemplate->strName = "Target_InfoLabel";
				DistLabelTemplate->strScreenId = "Target_InfoLabel";

				if (InfoLabel = (CLabelWnd*)pSidlMgr->CreateXWndFromTemplate(pTargetWnd, DistLabelTemplate))
				{
					char szLoc[MAX_STRING] = { 0 };
					char szOutLoc[MAX_STRING] = { 0 };

					ReadUIStringSetting("TargetInfoAnchoredToRight", "0", szOutLoc);

					int anchoredright = GetIntFromString(szOutLoc, 0);
					if (anchoredright)
					{
						InfoLabel->SetRightAnchoredToLeft(true);
						InfoLabel->SetLeftAnchoredToLeft(false);
					}
					else
					{
						InfoLabel->SetRightAnchoredToLeft(false);
						InfoLabel->SetLeftAnchoredToLeft(true);
					}

					InfoLabel->SetVisible(true);
					InfoLabel->SetUseInLayoutVertical(true);
					InfoLabel->SetWindowStyle(WSF_AUTOSTRETCHH | WSF_TRANSPARENT | WSF_AUTOSTRETCHV | WSF_RELATIVERECT);
					InfoLabel->SetClipToParent(true);
					InfoLabel->SetUseInLayoutHorizontal(true);
					InfoLabel->bAlignCenter = false;
					InfoLabel->bAlignRight = false;

					sprintf_s(szLoc, "%d,%d,%d,%d", 34, 48, 0, 40);
					ReadUIStringSetting("TargetInfoLoc", szLoc, szOutLoc);
					char* token1 = nullptr;
					char* next_token1 = nullptr;
					char szLocs[4][8];
					token1 = strtok_s(szOutLoc, ",", &next_token1);
					int j = 0;
					while (token1 != nullptr)
					{
						if (token1 != nullptr)
						{
							strcpy_s(szLocs[j], token1);
							token1 = strtok_s(nullptr, ",", &next_token1);
							j++;
						}
					}

					InfoLabel->SetTopOffset(GetIntFromString(szLocs[0], 0));
					InfoLabel->SetBottomOffset(GetIntFromString(szLocs[1], 0));
					InfoLabel->SetLeftOffset(GetIntFromString(szLocs[2], 0));
					InfoLabel->SetRightOffset(GetIntFromString(szLocs[3], 0));

					InfoLabel->SetCRNormal(MQColor(0, 255, 0));//green
					InfoLabel->SetBGColor(MQColor(255, 255, 255));
					InfoLabel->SetTooltip(szTargetInfo);
				}

				// create the distance label
				char szLoc[MAX_STRING] = { 0 };
				char szOutLoc[MAX_STRING] = { 0 };
				sprintf_s(szLoc, "%d,%d,%d,%d", 34, 48, 90, 0);
				ReadUIStringSetting("TargetDistanceLoc", szLoc, szOutLoc);
				char* token1 = nullptr;
				char* next_token1 = nullptr;
				char szLocs[4][8];
				token1 = strtok_s(szOutLoc, ",", &next_token1);
				int j = 0;
				while (token1 != nullptr)
				{
					if (token1 != nullptr)
					{
						strcpy_s(szLocs[j], token1);
						token1 = strtok_s(nullptr, ",", &next_token1);
						j++;
					}
				}

				int ttop = GetIntFromString(szLocs[0], 0);
				int tbottom = GetIntFromString(szLocs[1], 0);
				int tleft = GetIntFromString(szLocs[2], 0);
				int tright = GetIntFromString(szLocs[3], 0);
				DistanceLabel = CreateDistLabel(pTargetWnd, DistLabelTemplate,"Target_DistLabel", 2, ttop, tbottom, tleft, tright, true, gBShowExtDistance);

				//create can see label
				int oldfont2 = CanSeeLabelTemplate->nFont;
				CanSeeLabelTemplate->nFont = 2;
				CanSeeLabelTemplate->strName = "Target_CanSeeLabel";
				CanSeeLabelTemplate->strScreenId = "Target_CanSeeLabel";

				if (CanSeeLabel = (CLabelWnd*)pSidlMgr->CreateXWndFromTemplate(pTargetWnd, CanSeeLabelTemplate))
				{
					CanSeeLabel->SetVisible(true);
					CanSeeLabel->bNoWrap = true;
					CanSeeLabel->SetWindowStyle(WSF_AUTOSTRETCHH | WSF_TRANSPARENT | WSF_AUTOSTRETCHV | WSF_RELATIVERECT);
					CanSeeLabel->SetLeftAnchoredToLeft(true);
					CanSeeLabel->SetRightAnchoredToLeft(false);
					CanSeeLabel->SetBottomAnchoredToTop(true);
					CanSeeLabel->SetTopAnchoredToTop(true);
					CanSeeLabel->bAlignCenter = true;
					CanSeeLabel->bAlignRight = false;
					CanSeeLabel->SetTopOffset(CanSeeTopOffset);
					CanSeeLabel->SetTopOffset(CanSeeLabel->GetTopOffset() + 10);
					CanSeeLabel->SetBottomOffset(CanSeeBottomOffset);
					CanSeeLabel->SetBottomOffset(CanSeeLabel->GetBottomOffset() + 10);
					CanSeeLabel->SetLeftOffset(dLeftOffset);
					CanSeeLabel->SetRightOffset(dLeftOffset);
					CanSeeLabel->SetCRNormal(0xFF00FF00); // green
					CanSeeLabel->SetBGColor(0xFFFFFFFF);
					CanSeeLabel->SetTooltip(szCanSeeTarget);
				}

				// create PHButton
				PHButtonTemplate->nFont = 0;
				if (PHButton = (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pTargetWnd, PHButtonTemplate))
				{
					PHButton->SetVisible(false);
					PHButton->SetBottomAnchoredToTop(true);
					PHButton->SetLeftAnchoredToLeft(true);
					PHButton->SetRightAnchoredToLeft(false);
					PHButton->SetTopAnchoredToTop(true);
					PHButton->SetTopOffset(CanSeeTopOffset + 1);
					PHButton->SetBottomOffset(dTopOffset - 1);
					PHButton->SetLeftOffset(0);
					PHButton->SetRightOffset(0);
					// left top right bottom
					PHButton->SetLocation({ 2, CanSeeTopOffset + 1, 20, PHButton->GetBottomOffset() });

					PHButton->SetCRNormal(0xFF00FFFF); // cyan
					PHButton->SetBGColor(0xFFFFFFFF);
					PHButton->SetTooltip(szPHToolTip);
					PHButton->SetWindowText(szPH);
				}

				// now set the template values back
				DistLabelTemplate->nFont = oldfont;
				CanSeeLabelTemplate->nFont = oldfont2;
				PHButtonTemplate->nFont = oldphfont;
				DistLabelTemplate->strName = OldName1;
				DistLabelTemplate->strScreenId = OldScreenName1;
				DistLabelTemplate->strController = OldController1;
				CanSeeLabelTemplate->strName = OldName2;
				CanSeeLabelTemplate->strScreenId = OldScreenName2;
				CanSeeLabelTemplate->strController = OldController2;
			}
			else
			{
				bDisablePluginDueToBadUI = true;
				WriteChatf("MQ2TargetInfo has been disabled due to an incompatible UI, let a developer know.");
				return;
			}
		}

		if (CXWnd* pExtWnd = FindMQ2Window("ExtendedTargetWnd"))
		{
			orgExtTargetWindStyle = pExtWnd->GetWindowStyle();

			// orig style for default ui is 0xe44
			if (orgExtTargetWindStyle & WSF_TITLEBAR)
			{
				pExtWnd->AddStyle(WSF_SIZABLE | WSF_BORDER);
			}
			else
			{
				pExtWnd->AddStyle(WSF_CLIENTMOVABLE | WSF_SIZABLE | WSF_BORDER);
			}

			CControlTemplate* DistLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate(OldName1);
			if (DistLabelTemplate)
			{
				int oldfont = DistLabelTemplate->nFont;
				strcpy_s(OldName1, DistLabelTemplate->strName.c_str());
				strcpy_s(OldScreenName1, DistLabelTemplate->strScreenId.c_str());
				strcpy_s(OldController1, DistLabelTemplate->strController.c_str());

				char szTemp[MAX_STRING] = { 0 };
				char szLoc[MAX_STRING] = { 0 };
				char szOutLoc[MAX_STRING] = { 0 };

				ReadUIStringSetting("UseExtLayoutBox", "0", szOutLoc);
				int UseExtLayoutBox = GetIntFromString(szOutLoc, 0);

				DistLabelTemplate->strController = "0";
				sprintf_s(szLoc, "%d,%d,%d,%d", 0, -20, 70, 0);

				ReadUIStringSetting("ExtDistanceLoc", szLoc, szOutLoc);
				char* token1 = nullptr;
				char* next_token1 = nullptr;
				char szLocs[4][8];
				token1 = strtok_s(szOutLoc, ",", &next_token1);
				int j = 0;
				while (token1 != nullptr)
				{
					if (token1 != nullptr)
					{
						strcpy_s(szLocs[j], token1);
						token1 = strtok_s(nullptr, ",", &next_token1);
						j++;
					}
				}
				int ttop = GetIntFromString(szLocs[0], 0);
				int tbottom = GetIntFromString(szLocs[1], 0);
				int tleft = GetIntFromString(szLocs[2], 0);
				int tright = GetIntFromString(szLocs[3], 0);
				for (int i = 0; i < MAX_EXTENDED_TARGET_SIZE; i++)
				{
					sprintf_s(szTemp, "ETW_Gauge%d", i);

					if (ETW_Gauge[i] = (CGaugeWnd*)pExtWnd->GetChildItem(szTemp))
					{
						sprintf_s(szTemp, "ETW_DistLabel%d", i);
						int top = ETW_Gauge[i]->GetTopOffset();
						int bottom = ETW_Gauge[i]->GetBottomOffset();
						int left = ETW_Gauge[i]->GetLeftOffset();
						int right = ETW_Gauge[i]->GetRightOffset();

						if (left == 0 && top == 0)//weird UI...
						{
							top = ETW_Gauge[i]->GetLocation().top;
							bottom = ETW_Gauge[i]->GetLocation().bottom;
							left = ETW_Gauge[i]->GetLocation().left;
							right = ETW_Gauge[i]->GetLocation().right;
						}

						if (UseExtLayoutBox)
						{
							ETW_DistLabel[i] = CreateDistLabel(ETW_Gauge[i], DistLabelTemplate, szTemp, 2, top + ttop, bottom + tbottom, left + tleft, right + tright, true, gBShowExtDistance);
						}
						else
						{
							ETW_DistLabel[i] = CreateDistLabel(pExtWnd, DistLabelTemplate, szTemp, 2, top + ttop, bottom + tbottom, left + tleft, right + tright, true, gBShowExtDistance);
						}
					}
				}

				DistLabelTemplate->nFont = oldfont;
				DistLabelTemplate->strName = OldName1;
				DistLabelTemplate->strScreenId = OldScreenName1;
				DistLabelTemplate->strController = OldController1;
			}
			else
			{
				bDisablePluginDueToBadUI = true;
				WriteChatf("MQ2TargetInfo has been disabled due to an incompatible UI, let a developer know.");
				return;
			}
		}
	}
}

void StopMovement(bool bChange = true, bool bStopNav = false)
{
	if (bChange)
	{
		// FIXME: This should just be a user setting instead of guessing which the user wants to use.
		if (GetModuleHandle("mq2advpath"))
		{
			if (GetModuleHandle("mq2dannet"))
				DoCommandf("/squelch /dgge /squelch /afollow off");
			else if (GetModuleHandle("mq2eqbc"))
				DoCommandf("/squelch /bcg //squelch /afollow off");
		}

		if (GetModuleHandle("mq2moveutils"))
		{
			if (GetModuleHandle("mq2dannet"))
				DoCommandf("/squelch /dgge /squelch /stick off");
			else if (GetModuleHandle("mq2eqbc"))
				DoCommandf("/squelch /bcg //squelch /stick off");
		}

		if (bStopNav)
		{
			if (GetModuleHandle("mq2nav"))
			{
				if (GetModuleHandle("mq2dannet"))
					DoCommandf("/squelch /dgge /squelch /nav stop");
				else if (GetModuleHandle("mq2eqbc"))
					DoCommandf("/squelch /bcg //squelch /nav stop");
			}
		}

		FollowMeButton->bChecked = false;
		gbFollowme = false;
	}
}

class CGroupWnd2
{
public:
	void UpdateDisplay_Tramp(int, SPAWNINFO*, COLORREF, unsigned int);
	void UpdateDisplay_Detour(int Index, SPAWNINFO* groupmember, COLORREF NameColor, unsigned int RoleBits)
	{
		if (CHARINFO* pChar = GetCharInfo())
		{
			if (CGroupClient* group = (CGroupClient*)pChar->pGroupInfo)
			{
				int ind = rightclickindex; // group->GroupSelectID;
				if (Index == ind)
				{
					// NameColor = 0xFF0040FF;
				}
			}
		}

		return UpdateDisplay_Tramp(Index, groupmember, NameColor, RoleBits);
	}

	int CGroupWnd2::GetSelectedGroupIndex(CXWnd* pWnd)
	{
		CLabel* lab = (CLabel*)pWnd;
		int index = -1;

		if (CHARINFO* pChar = GetCharInfo())
		{
			if (CGroupClient* group = (CGroupClient*)pChar->pGroupInfo)
			{
				// index = group->GroupSelectID;
				for (int i = 1; i < 6; i++)
				{
					if (pWnd == ((CGroupWnd*)this)->HPGauge[i]
						|| pWnd == ((CGroupWnd*)this)->PetGauge[i]
						|| pWnd == ((CGroupWnd*)this)->ManaGauge[i]
						|| pWnd == ((CGroupWnd*)this)->EnduranceGauge[i]
						|| lab == ((CGroupWnd*)this)->HPLabel[i]
						|| lab == ((CGroupWnd*)this)->HPPercLabel[i]
						|| lab == ((CGroupWnd*)this)->ManaLabel[i]
						|| lab == ((CGroupWnd*)this)->ManaPercLabel[i]
						|| lab == ((CGroupWnd*)this)->EnduranceLabel[i]
						|| lab == ((CGroupWnd*)this)->EndurancePercLabel[i]
						|| lab == ((CGroupWnd*)this)->EnduranceLabel[i]
						|| pWnd == ((CGroupWnd*)this)->GroupTankButton[i]
						|| pWnd == ((CGroupWnd*)this)->GroupAssistButton[i]
						|| pWnd == ((CGroupWnd*)this)->GroupPullerButton[i]
						|| pWnd == ((CGroupWnd*)this)->GroupMarkNPCButton[i]
						|| lab == ((CGroupWnd*)this)->AggroPercLabel[i])
					{
						if (group->pMembers[i] && group->pMembers[i]->pSpawn && group->pMembers[i]->Type == 0)
						{
							return i;
						}
					}
				}
			}
		}
		return index;
	}

	SPAWNINFO* GetSpawnFromRightClickIndex()
	{
		char szMe[MAX_STRING] = { 0 };
		SPAWNINFO* pSpawn = nullptr;

		if (CHARINFO* pChar = GetCharInfo())
		{
			if (CGroupClient* group = (CGroupClient*)pChar->pGroupInfo)
			{
				int ind = rightclickindex; // group->GroupSelectID;
				if (ind != -1 && ind < 6)
				{
					if (group->pMembers[ind] && group->pMembers[ind]->pSpawn && group->pMembers[ind]->Type != 1)
					{
						pSpawn = group->pMembers[ind]->pSpawn;
					}
				}
			}
		}

		return pSpawn;
	}

	bool UpdateOurMenu(int index)
	{
		if (CGroupWnd* pGwnd = (CGroupWnd*)this)
		{
			if (pGwnd->GroupContextMenu)
			{
				if (index != -1)
				{
					//WriteChatf("User Rightclicked group member number %d", index);
					AddOurMenu(pGwnd, true, index);
					return true;
				}
				AddOurMenu(pGwnd, false, -1);
				return true;
				//RemoveOurMenu(pGwnd);
			}
		}
		return false;
	}

	int WndNotification_Trampoline(CXWnd*, uint32_t, void*);
	int WndNotification_Detour(CXWnd* pWnd, uint32_t Message, void* pData)
	{
		if (Message == XWM_OUTPUT_TEXT)
		{
			if (pWnd && (
				pWnd->GetParentWindow() == GroupHotButton[0]
				|| pWnd->GetParentWindow() == GroupHotButton[1]
				|| pWnd->GetParentWindow() == GroupHotButton[2]
				|| pWnd == GroupHotButton[0]
				|| pWnd == GroupHotButton[1]
				|| pWnd == GroupHotButton[2]
				|| pWnd == NavButton
				|| pWnd == MimicMeButton
				|| pWnd == FollowMeButton))
			{
				// we dont want to show the menu here.
				pContextMenuManager->Flush();
			}
		}
		else if (Message == XWM_RCLICK || Message == XWM_RSELITEM_DOWN)
		{
			if (pWnd && (pWnd->GetParentWindow() == GroupHotButton[0]
				|| pWnd->GetParentWindow() == GroupHotButton[1]
				|| pWnd->GetParentWindow() == GroupHotButton[2]
				|| pWnd == GroupHotButton[0]
				|| pWnd == GroupHotButton[1]
				|| pWnd == GroupHotButton[2]
				|| pWnd == NavButton
				|| pWnd == MimicMeButton
				|| pWnd == FollowMeButton))
			{
				// we dont want to show the menu here.
				pContextMenuManager->Flush();
				return 1;
			}

			rightclickindex = this->GetSelectedGroupIndex(pWnd);
			UpdateOurMenu(rightclickindex);
			// dont return here or group roles wont be filled in //return 1;
		}
		else if (Message == XWM_LCLICK)
		{

			if (pWnd == MimicMeButton)
			{
				gbMimicMe = !gbMimicMe;
				MimicMeButton->bChecked = gbMimicMe;
				return 1;
			}

			if (pWnd == NavButton)
			{
				if (!CheckNavCommand())
					return 1;

				StopMovement(true, true);

				char szMe[MAX_STRING] = { 0 };
				strcpy_s(szMe, szNavCommand);
				ParseMacroData(szMe, MAX_STRING);
				DoCommand((SPAWNINFO*)pLocalPlayer, szMe);
				return 1;
			}

			if (pWnd == FollowMeButton)
			{
				if (!CheckNavCommand())
					return 1;

				if (!FollowMeButton->bChecked)
					StopMovement(false);

				gbFollowme = !gbFollowme;
				FollowMeButton->bChecked = gbFollowme;

				char szMe[MAX_STRING] = { 0 };
				strcpy_s(szMe, szFollowMeCommand);
				ParseMacroData(szMe, MAX_STRING);

				if (gbFollowme)
				{
					// FIXME:  These should be by setting, not by loaded module.
					if ((GetModuleHandle("mq2eqbc") && strstr(szMe, "//afollow")) || (GetModuleHandle("mq2dannet") && strstr(szMe, "/afollow")))
					{
						if (!GetModuleHandle("mq2advpath"))
						{
							WriteChatf("%s only works if mq2advpath is loaded, Please run /plugin mq2advpath", szFollowMe);
							StopMovement();
							return 1;
						}
					}
					else if ( (GetModuleHandle("mq2eqbc") && strstr(szMe, "//stick")) || (GetModuleHandle("mq2dannet") && strstr(szMe, "/stick")))
					{
						if (!GetModuleHandle("mq2moveutils"))
						{
							WriteChatf("%s only works if mq2moveutils is loaded, Please run /plugin mq2moveutils", szFollowMe);
							StopMovement();
							return 1;
						}
					}
				}
				else
				{
					WriteChatf("\ayMQ2TargetInfo\ax : Group stopped following you.");
					StopMovement();
					return 1;
				}

				WriteChatf("\ayMQ2TargetInfo\ax : Group now follow you around.");
				DoCommand((SPAWNINFO*)pLocalPlayer, szMe);
				return 1;
			}

			if (pWnd
				&& (pWnd->GetParentWindow() == GroupHotButton[0]
					|| pWnd->GetParentWindow() == GroupHotButton[1]
					|| pWnd->GetParentWindow() == GroupHotButton[2]
					|| pWnd == GroupHotButton[0]
					|| pWnd == GroupHotButton[1]
					|| pWnd == GroupHotButton[2]))
			{
				return 1; // catches the hotbuttons
			}
		}
		else if (Message == XWM_MENUSELECT)
		{
			switch ((int)pData)
			{
			case TIMC_MakeMeLeader:
			{
				SPAWNINFO* pSpawn = GetSpawnFromRightClickIndex();
				if (pSpawn)
				{
					if (GetModuleHandle("mq2dannet"))
						DoCommandf("/dex %s /makeleader %s", pSpawn->Name, ((SPAWNINFO*)pLocalPlayer)->Name);
					else if (GetModuleHandle("mq2eqbc"))
						DoCommandf("/bct %s //makeleader %s", pSpawn->Name, ((SPAWNINFO*)pLocalPlayer)->Name);
				}
				return 1;
			}

			case TIMC_NavToMe: // our nav menu id
			{
				SPAWNINFO* pSpawn = GetSpawnFromRightClickIndex();
				if (pSpawn)
				{
					StopMovement(gbFollowme);
					if (GetModuleHandle("mq2dannet"))
						DoCommandf("/dex %s /nav id %d", pSpawn->Name, ((SPAWNINFO*)pLocalPlayer)->SpawnID);
					else if (GetModuleHandle("mq2eqbc"))
						DoCommandf("/bct %s //nav id %d", pSpawn->Name, ((SPAWNINFO*)pLocalPlayer)->SpawnID);
				}
				return 1; // we dont need to call the tramp, its our message...
			}

			case TIMC_Runto: // our Run To menu id
			{
				SPAWNINFO* pSpawn = GetSpawnFromRightClickIndex();
				if (pSpawn)
				{
					StopMovement(gbFollowme);
					DoCommandf("/nav id %d", pSpawn->SpawnID);
				}
				return 1; // we dont need to call the tramp, its our message...
			}

			case TIMC_PickupGroundItem: // ground
			{
				SPAWNINFO* pSpawn = GetSpawnFromRightClickIndex();
				if (pSpawn)
				{
					if (GetModuleHandle("mq2dannet"))
					{
						DoCommandf("/dex %s /itemtarget", pSpawn->Name);
						DoCommandf("/dex %s /click left item", pSpawn->Name);
					}
					else if (GetModuleHandle("mq2eqbc"))
					{
						DoCommandf("/bct %s //itemtarget", pSpawn->Name);
						DoCommandf("/bct %s //click left item", pSpawn->Name);
					}
				}
				return 1;
			}

			case TIMC_ClickNearestDoor: // door
			{
				SPAWNINFO* pSpawn = GetSpawnFromRightClickIndex();
				if (pSpawn)
				{
					if (GetModuleHandle("mq2dannet"))
					{
						DoCommandf("/dex %s /doortarget", pSpawn->Name);
						DoCommandf("/dex %s /click left door", pSpawn->Name);
					}
					else if (GetModuleHandle("mq2eqbc"))
					{
						DoCommandf("/bct %s //doortarget", pSpawn->Name);
						DoCommandf("/bct %s //click left door", pSpawn->Name);
					}
				}
				return 1;
			}

			case TIMC_SwitchTo: // switchto
			{
				SPAWNINFO* pSpawn = GetSpawnFromRightClickIndex();
				if (pSpawn)
				{
					if (GetModuleHandle("mq2dannet"))
					{
						DoCommandf("/dex %s /foreground", pSpawn->Name);
					}
					else if (GetModuleHandle("mq2eqbc"))
					{
						DoCommandf("/bct %s //foreground", pSpawn->Name);
					}
				}
				return 1;
			}

			case TIMC_FollowMe: // follow me
			{
				SPAWNINFO* pSpawn = GetSpawnFromRightClickIndex();
				if (pSpawn)
				{
					if (FollowMeMap.find(rightclickindex) != FollowMeMap.end())
					{
						if (FollowMeMap[rightclickindex])
						{
							if (GetModuleHandle("mq2dannet"))
								DoCommandf("/dex %s /afollow off", pSpawn->Name);
							else if (GetModuleHandle("mq2eqbc"))
								DoCommandf("/bct %s //afollow off", pSpawn->Name);
							FollowMeMap[rightclickindex] = false;
						}
						else
						{
							if (GetModuleHandle("mq2dannet"))
								DoCommandf("/dex %s /afollow spawn %d", pSpawn->Name, ((SPAWNINFO*)pLocalPlayer)->SpawnID);
							else if (GetModuleHandle("mq2eqbc"))
								DoCommandf("/bct %s //afollow spawn %d", pSpawn->Name, ((SPAWNINFO*)pLocalPlayer)->SpawnID);
							FollowMeMap[rightclickindex] = true;
						}
					}
					else
					{
						if (GetModuleHandle("mq2dannet"))
							DoCommandf("/dex %s /afollow spawn %d", pSpawn->Name, ((SPAWNINFO*)pLocalPlayer)->SpawnID);
						else if (GetModuleHandle("mq2eqbc"))
							DoCommandf("/bct %s //afollow spawn %d", pSpawn->Name, ((SPAWNINFO*)pLocalPlayer)->SpawnID);
						FollowMeMap[rightclickindex] = true;
					}
				}
				return 1;
			}

			case TIMC_ComeToMeButton: // gBShowComeToMeButton
			{
				CContextMenu* pContextMenu = (CContextMenu*)pWnd;

				int iItemID = pContextMenu->GetItemAtPoint(pWndMgr->MousePoint);
				gBShowComeToMeButton = !gBShowComeToMeButton;

				pContextMenu->CheckMenuItem(iItemID, gBShowComeToMeButton);
				NavButton->SetVisible(gBShowComeToMeButton);

				if (gBShowComeToMeButton)
					WriteSetting("ShowComeToMeButton", "1");
				else
					WriteSetting("ShowComeToMeButton", "0");

				return 1;
			}

			case TIMC_MimicMeButton: // gBShowMimicMeButton
			{
				CContextMenu* pContextMenu = (CContextMenu*)pWnd;

				int iItemID = ((CListWnd*)pContextMenu)->GetItemAtPoint(pWndMgr->MousePoint);
				gBShowMimicMeButton = !gBShowMimicMeButton;
				pContextMenu->CheckMenuItem(iItemID, gBShowMimicMeButton);
				MimicMeButton->SetVisible(gBShowMimicMeButton);

				if (gBShowMimicMeButton)
					WriteSetting("ShowMimicMeButton", "1");
				else
					WriteSetting("ShowMimicMeButton", "0");

				return 1;
			}

			case TIMC_FollowMeButton: // gBShowFollowMeButton
			{
				CContextMenu* pContextMenu = (CContextMenu*)pWnd;

				int iItemID = ((CListWnd*)pContextMenu)->GetItemAtPoint(pWndMgr->MousePoint);
				gBShowFollowMeButton = !gBShowFollowMeButton ;
				pContextMenu->CheckMenuItem(iItemID, gBShowFollowMeButton);
				FollowMeButton->SetVisible(gBShowFollowMeButton);

				if (gBShowFollowMeButton)
					WriteSetting("ShowFollowMeButton", "1");
				else
					WriteSetting("ShowFollowMeButton", "0");

				return 1;
			}

			case TIMC_HotButtons: // gBShowHotButtons
			{
				CContextMenu* pContextMenu = (CContextMenu*)pWnd;

				int iItemID = ((CListWnd*)pContextMenu)->GetItemAtPoint(pWndMgr->MousePoint);
				gBShowHotButtons = !gBShowHotButtons;
				pContextMenu->CheckMenuItem(iItemID, gBShowHotButtons);
				GroupHotButton[0]->SetVisible(gBShowHotButtons);
				GroupHotButton[1]->SetVisible(gBShowHotButtons);
				GroupHotButton[2]->SetVisible(gBShowHotButtons);

				if (gBShowHotButtons)
					WriteSetting("ShowHotButtons", "1");
				else
					WriteSetting("ShowHotButtons", "0");

				return 1;
			}

			case TIMC_Distance: // gBShowDistance
			{
				CContextMenu* pContextMenu = (CContextMenu*)pWnd;

				int iItemID = ((CListWnd*)pContextMenu)->GetItemAtPoint(pWndMgr->MousePoint);
				gBShowDistance = !gBShowDistance;
				pContextMenu->CheckMenuItem(iItemID, gBShowDistance);

				for (auto& GroupDistLabel : GroupDistLabels)
					GroupDistLabel->SetVisible(gBShowDistance);

				if (gBShowDistance)
					WriteSetting("ShowDistance", "1");
				else
					WriteSetting("ShowDistance", "0");

				return 1;
			}

			}
		}
		return WndNotification_Trampoline(pWnd, Message, pData);
	}

	CXWnd* CSidlManager_CreateHotButtonWnd_Tramp(CXWnd*, CControlTemplate*);
	CXWnd* CSidlManager_CreateHotButtonWnd_Detour(CXWnd* pwndParent, CControlTemplate* pControl)
	{
		CHotButton* ret = (CHotButton*)CSidlManager_CreateHotButtonWnd_Tramp(pwndParent, pControl);
		return ret;
	}
};

DETOUR_TRAMPOLINE_EMPTY(CXWnd* CGroupWnd2::CSidlManager_CreateHotButtonWnd_Tramp(CXWnd*, CControlTemplate*));
DETOUR_TRAMPOLINE_EMPTY(int CGroupWnd2::WndNotification_Trampoline(CXWnd*, uint32_t, void*));
DETOUR_TRAMPOLINE_EMPTY(void CGroupWnd2::UpdateDisplay_Tramp(int, SPAWNINFO*, COLORREF, UINT));

void CMD_GroupInfo(SPAWNINFO* pPlayer, char* szLine)
{
	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);

	if (!_stricmp(szArg1, "help"))
	{
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide mimicme\ax\am(it's currently set to: %s)\ax.", MimicMeButton->IsVisible() ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide extdistance\ax\am(it's currently set to: %s)\ax.", gBShowExtDistance ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide distance\ax\am(it's currently set to: %s)\ax.", GroupDistLabels[0]->IsVisible() ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide hot\ax\am(it's currently set to: %s)\ax.", gBShowHotButtons ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide followme\ax\am(it's currently set to: %s)\ax.", FollowMeButton->IsVisible() ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide cometome\ax\am(it's currently set to: %s)\ax.", NavButton->IsVisible() ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo reset will reset all settings to default. Old settings will be in MQ2TargetInfo.bak\ax.");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo reload will reload all settings.\ax.");
		return;
	}
	else if (!_stricmp(szArg1, "reset"))
	{
		ResetIni();
		return;
	}
	else if (!_stricmp(szArg1, "reload"))
	{
		CleanUp(true);
		bDisablePluginDueToBadUI = false;
		return;
	}
	else if (!_stricmp(szArg1, "show"))
	{
		char szArg2[MAX_STRING] = { 0 };
		GetArg(szArg2, szLine, 2);

		if (!_stricmp(szArg2, "mimicme"))
		{
			MimicMeButton->SetVisible(true);
			gBShowMimicMeButton = true;
			WriteSetting("ShowMimicMeButton", "1");
		}
		else if (!_stricmp(szArg2, "extdistance"))
		{
			gBShowExtDistance = true;
			WriteSetting("ShowExtDistance", "1");
		}
		else if (!_stricmp(szArg2, "distance"))
		{
			gBShowDistance = true;
			for (auto& GroupDistLabel : GroupDistLabels)
				GroupDistLabel->SetVisible(true);
			WriteSetting("ShowDistance", "1");
		}
		else if (!_stricmp(szArg2, "hot"))
		{
			gBShowHotButtons = true;
			for (auto& button : GroupHotButton)
				button->SetVisible(true);
			WriteSetting("ShowHotButtons", "1");
		}
		else if (!_stricmp(szArg2, "followme"))
		{
			gBShowFollowMeButton = true;
			FollowMeButton->SetVisible(true);
			WriteSetting("ShowFollowMeButton", "1");
		}
		else if (!_stricmp(szArg2, "cometome"))
		{
			gBShowComeToMeButton = true;
			NavButton->SetVisible(true);
			WriteSetting("ShowComeToMeButton", "1");
		}
	}
	else if (!_stricmp(szArg1, "hide"))
	{
		char szArg2[MAX_STRING] = { 0 };
		GetArg(szArg2, szLine, 2);
		if (!_stricmp(szArg2, "mimicme"))
		{
			gBShowMimicMeButton = false;
			MimicMeButton->SetVisible(false);
			WriteSetting("ShowMimicMeButton", "0");
		}
		else if (!_stricmp(szArg2, "extdistance"))
		{
			gBShowExtDistance = false;
			for (auto& label : ETW_DistLabel)
			{
				if (label) label->SetVisible(false);
			}
			WriteSetting("ShowExtDistance", "0");
		}
		else if (!_stricmp(szArg2, "distance"))
		{
			gBShowDistance = false;
			for (auto& GroupDistLabel : GroupDistLabels)
				GroupDistLabel->SetVisible(false);
			WriteSetting("ShowDistance", "0");
		}
		else if (!_stricmp(szArg2, "hot"))
		{
			gBShowHotButtons = false;
			for (auto& button : GroupHotButton)
				button->SetVisible(false);
			WriteSetting("ShowHotButtons", "0");
		}
		else if (!_stricmp(szArg2, "followme"))
		{
			gBShowFollowMeButton = false;
			FollowMeButton->SetVisible(false);
			WriteSetting("ShowFollowMeButton", "0");
		}
		else if (!_stricmp(szArg2, "cometome"))
		{
			gBShowComeToMeButton = false;
			NavButton->SetVisible(false);
			WriteSetting("ShowComeToMeButton", "0");
		}
	}
	else if (!_stricmp(szArg1, "mimicme"))
	{
		char szArg2[MAX_STRING] = { 0 };
		GetArg(szArg2, szLine, 2);

		bool show = _stricmp(szArg2, "off");
		gbMimicMe = show;
		MimicMeButton->bChecked = show;
	}
	else if (!_stricmp(szArg1, "followme"))
	{
		if (!CheckNavCommand())
			return;

		char szArg2[MAX_STRING] = { 0 };
		GetArg(szArg2, szLine, 2);
		if (!FollowMeButton->bChecked)
			StopMovement(false);

		if (!_stricmp(szArg2, "off"))
		{
			gbFollowme = false;
			FollowMeButton->bChecked = false;
		}
		else
		{
			gbFollowme = true;
			FollowMeButton->bChecked = true;
		}

		char szMe[MAX_STRING] = { 0 };
		strcpy_s(szMe, szFollowMeCommand);
		ParseMacroData(szMe, MAX_STRING);

		if (gbFollowme)
		{
			if (strstr(szMe, "//afollow"))
			{
				if (!GetModuleHandle("mq2advpath"))
				{
					WriteChatf("%s only works if mq2advpath is loaded, Please run /plugin mq2advpath", szFollowMe);
					StopMovement();
					return;
				}
			}
			else if (strstr(szMe, "//stick"))
			{
				if (!GetModuleHandle("mq2moveutils"))
				{
					WriteChatf("%s only works if mq2moveutils is loaded, Please run /plugin mq2moveutils", szFollowMe);
					StopMovement();
					return;
				}
			}
		}
		else
		{
			WriteChatf("\ayMQ2TargetInfo\ax : Group stopped following you.");
			StopMovement();
			return;
		}

		WriteChatf("\ayMQ2TargetInfo\ax : Group now follow you around.");
		DoCommand((SPAWNINFO*)pLocalPlayer, szMe);
		return;
	}
	else if (!_stricmp(szArg1, "cometome"))
	{
		if (!CheckNavCommand())
			return;

		StopMovement(true, true);
		char szMe[MAX_STRING] = { 0 };
		strcpy_s(szMe, szNavCommand);
		ParseMacroData(szMe, MAX_STRING);
		DoCommand((SPAWNINFO*)pLocalPlayer, szMe);
	}
}

PLUGIN_API void InitializePlugin()
{
	AddCommand("/groupinfo", CMD_GroupInfo);
	EzDetour(CSidlManager__CreateHotButtonWnd, &CGroupWnd2::CSidlManager_CreateHotButtonWnd_Detour, &CGroupWnd2::CSidlManager_CreateHotButtonWnd_Tramp);
	EzDetour(CGroupWnd__UpdateDisplay, &CGroupWnd2::UpdateDisplay_Detour, &CGroupWnd2::UpdateDisplay_Tramp);
	EzDetour(CGroupWnd__WndNotification, &CGroupWnd2::WndNotification_Detour, &CGroupWnd2::WndNotification_Trampoline);

	std::filesystem::path curFilepath = gPathResources;
	curFilepath /= "MQ2TargetInfoPHs.txt";

	std::error_code ec_exists;

	if (!std::filesystem::exists(curFilepath, ec_exists))
	{
		HMODULE hMe = nullptr;
		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)InitializePlugin, &hMe);
		void* pMyBinaryData = nullptr;

		// need to unpack our resource.
		if (HRSRC hRes = FindResource(hMe, MAKEINTRESOURCE(IDR_DB1), "DB"))
		{
			if (HGLOBAL bin = LoadResource(hMe, hRes))
			{
				bool bResult = false;
				if (pMyBinaryData = LockResource(bin))
				{
					// save it...
					DWORD ressize = SizeofResource(hMe, hRes);
					FILE* File = nullptr;
					errno_t err = fopen_s(&File, curFilepath.string().c_str(), "wb");
					if (!err)
					{
						fwrite(pMyBinaryData, ressize, 1, File);
						fclose(File);
					}
					bResult = UnlockResource(hRes);
				}
				bResult = FreeResource(hRes);
			}
		}
	}

	LoadPHs(curFilepath.string().data());

	curFilepath = INIFileName;
	if (!std::filesystem::exists(curFilepath, ec_exists))
	{
		ResetIni();
	}

	EzDetour(CTargetWnd__HandleBuffRemoveRequest, &MyCTargetWnd::HandleBuffRemoveRequest_Detour, &MyCTargetWnd::HandleBuffRemoveRequest_Tramp);
	Initialize();
}

void CleanUp(bool bUnload)
{
	if (pGroupWnd)
	{
		if (orgwstyle)
		{
			orgwstyle = 0;
		}

		if (pGroupWnd->GroupContextMenu && separatorId)
		{
			RemoveOurMenu(pGroupWnd);
		}
	}

	if (pTargetWnd)
	{
		if (orgTargetWindStyle)
		{
			pTargetWnd->SetWindowStyle(orgTargetWindStyle);
			pTargetWnd->SetNeedsSaving(true);
			pTargetWnd->SetClientRectChanged(true);
			orgTargetWindStyle = 0;
		}
	}

	if (CXWnd* pExtWnd = FindMQ2Window("ExtendedTargetWnd"))
	{
		if (orgExtTargetWindStyle)
		{
			pExtWnd->SetNeedsSaving(true);
			pExtWnd->SetClientRectChanged(true);
			orgExtTargetWindStyle = 0;
		}
	}

	for (auto& label : ETW_DistLabel)
	{
		if (label)
		{
			label->Destroy();
			label = nullptr;
		}
	}

	for (auto& label : GroupDistLabels)
	{
		if (label)
		{
			label->Destroy();
			label = nullptr;
		}
	}

	if (InfoLabel)
	{
		InfoLabel->Destroy();
		InfoLabel = nullptr;
	}

	if (DistanceLabel)
	{
		DistanceLabel->Destroy();
		DistanceLabel = nullptr;
	}

	if (CanSeeLabel)
	{
		CanSeeLabel->Destroy();
		CanSeeLabel = nullptr;
	}

	if (PHButton)
	{
		PHButton->Destroy();
		PHButton = nullptr;
	}

	if (NavButton)
	{
		NavButton->Destroy();
		NavButton = nullptr;
	}

	if (FollowMeButton)
	{
		FollowMeButton->Destroy();
		FollowMeButton = nullptr;
	}

	if (MimicMeButton)
	{
		MimicMeButton->Destroy();
		MimicMeButton = nullptr;
	}

	for (auto& button : GroupHotButton)
	{
		if (button)
		{
			button->Destroy();
			button = nullptr;
		}
	}

	if (GetGameState() == GAMESTATE_INGAME)
	{
		if (bUnload)
		{
			// Check that our controls still exist.
			CXWnd* pBuffWindow = pTargetWnd->GetChildItem("Target_BuffWindow");
			if (Target_BuffWindow && Target_BuffWindow == Target_BuffWindow)
			{
				Target_BuffWindow->SetTopOffset(Target_BuffWindow_TopOffsetOld);
			}
			Target_BuffWindow = nullptr;

			CLabelWnd* pAggroPctPlayerLabel = (CLabelWnd*)pTargetWnd->GetChildItem("Target_AggroPctPlayerLabel");
			if (Target_AggroPctPlayerLabel && pAggroPctPlayerLabel == Target_AggroPctPlayerLabel)
			{
				Target_AggroPctPlayerLabel->SetTopOffset(Target_AggroPctPlayerLabel_TopOffsetOrg);
				Target_AggroPctPlayerLabel->SetBottomOffset(Target_AggroPctPlayerLabel_BottomOffsetOrg);
			}
			Target_AggroPctPlayerLabel = nullptr;

			CLabelWnd* pAggroNameSecondaryLabel = (CLabelWnd*)pTargetWnd->GetChildItem("Target_AggroNameSecondaryLabel");
			if (Target_AggroNameSecondaryLabel && pAggroNameSecondaryLabel == Target_AggroNameSecondaryLabel)
			{
				Target_AggroNameSecondaryLabel->SetTopOffset(Target_AggroNameSecondaryLabel_TopOffsetOrg);
				Target_AggroNameSecondaryLabel->SetBottomOffset(Target_AggroNameSecondaryLabel_BottomOffsetOrg);
			}
			Target_AggroNameSecondaryLabel = nullptr;

			CLabelWnd* pAggroPctSecondaryLabel = (CLabelWnd*)pTargetWnd->GetChildItem("Target_AggroPctSecondaryLabel");
			if (Target_AggroPctSecondaryLabel && pAggroPctSecondaryLabel == Target_AggroPctSecondaryLabel)
			{
				Target_AggroPctSecondaryLabel->SetTopOffset(Target_AggroPctSecondaryLabel_TopOffsetOrg);
				Target_AggroPctSecondaryLabel->SetBottomOffset(Target_AggroPctSecondaryLabel_BottomOffsetOrg);
			}
			Target_AggroPctSecondaryLabel = nullptr;
		}
	}

	if (pTargetWnd)
	{
		pTargetWnd->UpdateLayout();
	}
}

// Called once, when the plugin is to shutdown
PLUGIN_API void ShutdownPlugin()
{
	if (CTargetWnd__HandleBuffRemoveRequest)
		RemoveDetour(CTargetWnd__HandleBuffRemoveRequest);

	CleanUp(true);

	RemoveCommand("/groupinfo");
	RemoveDetour(CGroupWnd__WndNotification);
	RemoveDetour(CGroupWnd__UpdateDisplay);
	RemoveDetour(CSidlManager__CreateHotButtonWnd);
}

// Called after entering a new zone
PLUGIN_API void OnZoned()
{
	gbMimicMe = false;

	if (MimicMeButton)
		MimicMeButton->bChecked = false;
	gbFollowme = false;

	if (FollowMeButton)
		FollowMeButton->bChecked = false;
}

// Called once directly before shutdown of the new ui system, and also
// every time the game calls CDisplay::CleanGameUI()
PLUGIN_API void OnCleanUI()
{
	// destroy custom windows, etc
	CleanUp(false);
	bDisablePluginDueToBadUI = false;
}

bool IsPlaceHolder(SPAWNINFO* pSpawn)
{
	std::scoped_lock lock(s_mutex); // is this even needed?

	if (pSpawn && gPHMap.find(pSpawn->DisplayedName) != gPHMap.end())
	{
		return true;
	}

	return false;
}

bool GetPhMap(SPAWNINFO* pSpawn, PHInfo* pinf)
{
	std::scoped_lock lock(s_mutex); // is this even needed?

	if (pSpawn && gPHMap.find(pSpawn->DisplayedName) != gPHMap.end())
	{
		*pinf = gPHMap[pSpawn->DisplayedName];
		return true;
	}
	return false;
}

// This is called every time MQ pulses
static char szTargetDist[64] = { 0 };
SPAWNINFO* oldspawn = nullptr;

void UpdateGroupDist(CHARINFO* pChar, int index)
{
	if (index < 1 || index > NUM_GROUPWND_CONTROLS)
		return;

	if (CLabelWnd* pWnd = GroupDistLabels[index - 1])
	{
		if (pChar->pGroupInfo->pMember[index] && pChar->pGroupInfo->pMember[index]->pSpawn)
		{
			float dist = Distance3DToSpawn(pLocalPlayer, pChar->pGroupInfo->pMember[index]->pSpawn);
			sprintf_s(szTargetDist, "%.2f", dist);

			if (dist < 250)
			{
				pWnd->SetCRNormal(MQColor(0, 255, 0)); // green
			}
			else
			{
				pWnd->SetCRNormal(MQColor(255, 0, 0)); // red
			}

			pWnd->SetWindowText(szTargetDist);
			pWnd->SetVisible(true);
		}
		else
		{
			pWnd->SetVisible(false);
		}
	}
}

void UpdatedExtDistance()
{
	CHARINFO* pChar = GetCharInfo();
	if (!pChar)
		return;

	ExtendedTargetList* xtm = pChar->pXTargetMgr;
	if (!xtm)
		return;

	for (int i = 0; i < xtm->XTargetSlots.Count; i++)
	{
		if (CLabelWnd* pWnd = ETW_DistLabel[i])
		{
			const XTARGETSLOT& xts = xtm->XTargetSlots[i];
			uint32_t spID = xts.SpawnID;

			if (spID)
			{
				if (SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(spID))
				{
					float dist = Distance3DToSpawn(pLocalPlayer, pSpawn);
					sprintf_s(szTargetDist, "%.2f", dist);

					if (dist < 250)
					{
						pWnd->SetCRNormal(MQColor(0, 255, 0)); // green
					}
					else
					{
						pWnd->SetCRNormal(MQColor(255, 0, 0)); // red
					}

					pWnd->SetWindowText(szTargetDist);
					pWnd->SetVisible(true);
					continue;
				}
			}

			pWnd->SetVisible(false);
		}
	}
}

static DWORD LastTargetID = 0;

void DidTargetChange()
{
	if (pTarget && ((SPAWNINFO*)pTarget)->SpawnID != LastTargetID)
	{
		// yes it changed
		LastTargetID = ((SPAWNINFO*)pTarget)->SpawnID;
		if (GetModuleHandle("mq2dannet"))
			DoCommandf("/dgge /target id %d", LastTargetID);
		else if (GetModuleHandle("mq2eqbc"))
			DoCommandf("/bcg //target id %d", LastTargetID);
		WriteChatf("Letting group know target changed");
	}
}

void MimicMeFunc()
{
	SPAWNINFO* pSpawn = (SPAWNINFO*)pLocalPlayer;
	DidTargetChange();

	if (pSpawn->AssistName[0])
	{
		pSpawn->GroupAssistNPC;
	}
}

PLUGIN_API DWORD OnIncomingChat(char* Line, DWORD Color)
{
	if (gbMimicMe)
	{
		int linelen = strlen(Line);
		char* szLine = (char*)LocalAlloc(LPTR, linelen + 32);
		char* szLineOrg = szLine;
		strcpy_s(szLine, linelen + 32, Line);

		if (!_strnicmp(szLine, "You say, '", 10))
		{
			szLine += 10;
			if (char* pDest = strrchr(szLine, '\''))
			{
				pDest[0] = '\0';
			}

			if (!_strnicmp(szLine, "Hail, ", 6))
			{
				DoCommandf("%s", szMimicMeHailCommand);
			}
			else
			{
				DoCommandf("%s %s", szMimicMeSayCommand, szLine);
			}
		}

		LocalFree(szLineOrg);
	}
	return 0;
}

PLUGIN_API DWORD OnWriteChatColor(char* Line, DWORD Color, DWORD Filter)
{
	if (gbMimicMe)
	{
		//MQ2EasyFind: Going to (Group) -> Annera
		int linelen = strlen(Line);
		char* szLine = (char*)LocalAlloc(LPTR, linelen + 32);
		char* szLineOrg = szLine;
		strcpy_s(szLine, linelen + 32, Line);

		if (!_strnicmp(szLine, "MQ2EasyFind: Going to ", 22))
		{
			//szLine += 22;
			if (char* pDest = strstr(szLine, "-> "))
			{
				szLine = pDest;
				szLine += 3;
			}
			if (char* pDest = strchr(szLine, '('))
			{
				pDest--;
				pDest[0] = '\0';

			}
			StopMovement();

			if (GetModuleHandle("mq2dannet"))
				DoCommandf("/dgge /easyfind \"%s\"", szLine);
			else if (GetModuleHandle("mq2eqbc"))
				DoCommandf("/bcg //easyfind \"%s\"", szLine);
			else
				WriteChatf("Either mq2eqbc or mq2dannet needs to be loaded to go to %s", szLine);
		}

		LocalFree(szLineOrg);
	}
	return 0;
}

PLUGIN_API void OnPulse()
{
	static uint64_t lastPulseUpdate = MQGetTickCount64();
	uint64_t currentTime = MQGetTickCount64();

	if (currentTime - lastPulseUpdate > 500) // 500ms
	{
		lastPulseUpdate = currentTime;

		if (GetGameState() == GAMESTATE_INGAME)
		{
			Initialize();

			if (gbMimicMe)
			{
				MimicMeFunc();
			}

			if (gBShowExtDistance && ETW_DistLabel[0])
			{
				if (pExtendedTargetWnd)
				{
					if (pExtendedTargetWnd->IsVisible())
					{
						UpdatedExtDistance();
					}
				}
			}

			if (pGroupWnd)
			{
				if (pContextMenuManager->NumVisibleMenus == 0 && separatorId)
				{
					RemoveOurMenu(pGroupWnd);
				}

				if (CHARINFO* pChar = GetCharInfo())
				{
					if (pChar->pGroupInfo)
					{
						if (gBShowDistance)
						{
							for (int i = 0; i < NUM_GROUPWND_CONTROLS; ++i)
								UpdateGroupDist(pChar, i + 1);
						}

						if (!gBShowMimicMeButton && MimicMeButton && MimicMeButton->IsVisible())
							MimicMeButton->SetVisible(true);
						if (!gBShowFollowMeButton && FollowMeButton && FollowMeButton->IsVisible())
							FollowMeButton->SetVisible(true);
						if (!gBShowComeToMeButton && NavButton && NavButton->IsVisible())
							NavButton->SetVisible(true);
					}
					else
					{
						if (GroupDistLabels[0] && GroupDistLabels[0]->IsVisible())
						{
							for (auto& label : GroupDistLabels)
							{
								if (label) label->SetVisible(false);
							}
						}
						if (MimicMeButton && MimicMeButton->IsVisible())
							MimicMeButton->SetVisible(false);
						if (FollowMeButton && FollowMeButton->IsVisible())
							FollowMeButton->SetVisible(false);
						if (NavButton && NavButton->IsVisible())
							NavButton->SetVisible(false);
					}
				}
			}

			if (pTargetWnd)
			{
				if (InfoLabel && DistanceLabel && CanSeeLabel && PHButton)
				{
					if (pTarget && pCharSpawn)
					{
						if (oldspawn != pTarget)
						{
							oldspawn = pTarget;

							PHInfo pinf;
							if (GetPhMap(pTarget, &pinf))
							{
								PHButton->SetTooltip(CXStr{ pinf.Named });
								PHButton->SetVisible(true);
							}
							else
							{
								PHButton->SetVisible(false);
							}
						}

						// set info
						SPAWNINFO* pInfo = (SPAWNINFO*)pTarget;

						switch (pInfo->Anon)
						{
						case 1:
							sprintf_s(szTargetDist, "Anonymous");
							break;
						case 2:
							sprintf_s(szTargetDist, "Roleplaying");
							break;
						default:
							{
								if (pInfo->Type == SPAWN_PLAYER)
								{
									sprintf_s(szTargetDist, "%d %s %s", pInfo->Level, pEverQuest->GetRaceDesc(pInfo->mActorClient.Race), pEverQuest->GetClassThreeLetterCode(pInfo->mActorClient.Class));
								}
								else
								{
									sprintf_s(szTargetDist, "%d %s %s", pInfo->Level, pEverQuest->GetRaceDesc(pInfo->mActorClient.Race), GetClassDesc(pInfo->mActorClient.Class));
								}
								break;
							}
						}

						InfoLabel->SetWindowText(szTargetDist);

						// then distance
						float dist = Distance3DToSpawn(pLocalPlayer, pTarget);
						sprintf_s(szTargetDist, "%.2f", dist);

						if (dist < 250)
						{
							DistanceLabel->SetCRNormal(MQColor(0, 255, 0)); // green
						}
						else
						{
							DistanceLabel->SetCRNormal(MQColor(255, 0, 0)); // red
						}

						DistanceLabel->SetWindowText(szTargetDist);

						// now do can see
						bool cansee = pCharSpawn->CanSee(*(PlayerClient*)pTarget);
						sprintf_s(szTargetDist, "%s", cansee ? "O" : "X");

						if (cansee)
						{
							CanSeeLabel->SetCRNormal(MQColor(0, 255, 0)); // green
						}
						else
						{
							CanSeeLabel->SetCRNormal(MQColor(255, 0, 0)); // red
						}

						CanSeeLabel->SetWindowText(szTargetDist);
					}
					else
					{
						InfoLabel->SetWindowText(CXStr());
						DistanceLabel->SetWindowText(CXStr());
						CanSeeLabel->SetWindowText(CXStr());
						PHButton->SetVisible(false);
					}
				}
			}
		}
	}
}
