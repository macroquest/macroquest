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

// MQ2TargetInfo by EqMule 2018
// 2.1 Added enums for menu and go to menu item
// 2.2 Added fix from dannuic/knightly to stop clearing target when using hotbuttons.
// 2.3 Added a fix for stopping movement by Freezerburn26
// 2.4 FelisMalum: Moved allot of configuration to INI + added some additional, added distance variables/color, updated INI.

// TODO: Update for zone checking since the info is in the file (requires switching storage or map key)
// TODO: Move 2nd aggro%/name to ini. Add true name?. Possible label variables?
// TODO: Cleanup ph loading, no need to load entire file on load or hardcode npc.

#include <mq/Plugin.h>
#include "resource.h"

#include <map>
#include <mutex>
#include <string>

PreSetup("MQ2TargetInfo");
PLUGIN_VERSION(2.4);

enum class eINIOptions
{
	WriteOnly,
	ReadAndWrite,
	ReadOnly
};

std::recursive_mutex s_mutex;

std::string DistanceLabelToolTip = "Target Distance";
char szTargetInfo[128] = { "Target Info" };
char szCanSeeTarget[128] = { "Can See Target" };
char szPHToolTip[128] = { "Target is a Place Holder" };
char szPH[128] = { "PH" };

SPAWNINFO* oldspawn = nullptr;

CLabelWnd* InfoLabel = nullptr;
CLabelWnd* DistanceLabel = nullptr;
CLabelWnd* CanSeeLabel = nullptr;

CButtonWnd* PHButton = nullptr;

CXWnd* Target_BuffWindow = nullptr;
CLabelWnd* Target_AggroPctPlayerLabel = nullptr;
CLabelWnd* Target_AggroNameSecondaryLabel = nullptr;
CLabelWnd* Target_AggroPctSecondaryLabel = nullptr;

//Defaulted on initialize but over-written by INI
int Target_BuffWindow_TopOffset = 76;
int Target_BuffWindow_TopOffsetOld = 50; //Not in ini
int dTopOffset = 60;
int dBottomOffset = 74;
int TargetInfoWindowStyle = 0;
int TargetInfoAnchoredToRight = 0;
std::string ManaLabelName = "Player_ManaLabel";
std::string FatigueLabelName = "Player_FatigueLabel";
std::string TargetInfoLoc = "34,48,0,40";
MQColor TargetInfoColor = MQColor(0, 255, 0);
std::string TargetDistanceLoc = "34,48,90,0";
std::string CanSeeIndicatorLoc = "47,61,50,0";
/* End multiple location defaults */

int Target_AggroPctPlayerLabel_TopOffsetOrg = 33;
int Target_AggroNameSecondaryLabel_TopOffsetOrg = 33;
int Target_AggroPctSecondaryLabel_TopOffsetOrg = 33;
int Target_AggroPctPlayerLabel_BottomOffsetOrg = 47;
int Target_AggroNameSecondaryLabel_BottomOffsetOrg = 47;
int Target_AggroPctSecondaryLabel_BottomOffsetOrg = 47;
MQColor	TargetMeleeRngColor = MQColor(0, 0, 255);
int TargetDistanceShort = 25;
MQColor TargetSpellRngColor = MQColor(0, 255, 0);
int TargetDistanceMedium = 250;
MQColor TargetBowRngColor = MQColor(255, 255, 0);
int TargetDistanceLong = 400;
MQColor TargetFarRngColor = MQColor(255, 0, 0);

bool Initialized = false;
bool bDisablePluginDueToBadUI = false;
bool gbUsePerCharSettings = false;
bool gbShowDistance = true;
bool gbShowPlaceholder = true;
bool gbShowAnon = true;
bool gbShowSight = true;
bool gbShowTargetInfo = true;

DWORD orgTargetWindStyle = 0;

struct PHInfo
{
	std::string Expansion;
	std::string Zone;
	std::string Named;
	std::string Link;
};
std::map<std::string, PHInfo> gPHMap;

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

class MyCTargetWnd
{
public:
	// we can safely use this as its always called when a user leftclicks the target window.
	// also the upside here is that we dont collide with the trade with target detour in mq2windows...
	DETOUR_TRAMPOLINE_DEF(void, HandleBuffRemoveRequest_Tramp, (CXWnd*))
	void HandleBuffRemoveRequest_Detour(CXWnd* pWnd)
	{
		if (PHButton && pWnd == PHButton)
		{
			if (pTarget)
			{
				PHInfo pinf;
				if (GetPhMap((SPAWNINFO*)pTarget, &pinf))
				{
					ShellExecute(nullptr, "open", pinf.Link.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
				}
			}
		}
		HandleBuffRemoveRequest_Tramp(pWnd);
	}
};

void LoadPHs(char* szMyName)
{
	// well we have it, lets fill in the map...
	// Chief Librarian Lars^a shissar arbiter, a shissar defiler^tds^kattacastrumdeluge^https://tds.eqresource.com/chieflibrarianlars.php
	PHInfo phinf;
	std::string phs;
	size_t commapos = 0;
	char szBuffer[MAX_STRING] = { 0 };
	FILE* fp = _fsopen(szMyName, "rb", _SH_DENYNO);
	if (fp != nullptr)
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

			// FIXME:  Why is this hardcoded?
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
		pLabel->SetTooltip(DistanceLabelToolTip.c_str());
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

CXRect GetCXRectTBLRFromString(const std::string& Input, int defaultTop, int defaultBottom, int defaultLeft, int defaultRight)
{
	auto splitString = split(Input, ',');
	if (splitString.size() == 4)
	{
		defaultTop = GetIntFromString(splitString[0], defaultTop);
		defaultBottom = GetIntFromString(splitString[1], defaultBottom);
		defaultLeft = GetIntFromString(splitString[2], defaultLeft);
		defaultRight = GetIntFromString(splitString[3], defaultRight);
	}
	return CXRect(defaultLeft, defaultTop, defaultRight, defaultBottom);
}

MQColor ParseColorString(MQColor defaultValue, const std::string& colorString)
{
	auto splitString = split_view(colorString, ',');
	if (splitString.size() == 3)
	{
		return MQColor(GetIntFromString(splitString[0], defaultValue.Red), GetIntFromString(splitString[1], defaultValue.Green), GetIntFromString(splitString[2], defaultValue.Blue));
	}
	return defaultValue;
}

std::string FormatColorString(MQColor color)
{
	std::string s = fmt::format("{},{},{}", color.Red, color.Green, color.Blue);
	return s;
}

void CleanUp()
{
	bDisablePluginDueToBadUI = false;

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

	if (GetGameState() == GAMESTATE_INGAME)
	{
		// Check that our controls still exist.
		CXWnd* pBuffWindow = pTargetWnd->GetChildItem("Target_BuffWindow");
		if (Target_BuffWindow && pBuffWindow == Target_BuffWindow)
		{
			Target_BuffWindow->SetTopOffset(Target_BuffWindow_TopOffsetOld);
		}

		CLabelWnd* pAggroPctPlayerLabel = (CLabelWnd*)pTargetWnd->GetChildItem("Target_AggroPctPlayerLabel");
		if (Target_AggroPctPlayerLabel && pAggroPctPlayerLabel == Target_AggroPctPlayerLabel)
		{
			Target_AggroPctPlayerLabel->SetTopOffset(Target_AggroPctPlayerLabel_TopOffsetOrg);
			Target_AggroPctPlayerLabel->SetBottomOffset(Target_AggroPctPlayerLabel_BottomOffsetOrg);
		}

		CLabelWnd* pAggroNameSecondaryLabel = (CLabelWnd*)pTargetWnd->GetChildItem("Target_AggroNameSecondaryLabel");
		if (Target_AggroNameSecondaryLabel && pAggroNameSecondaryLabel == Target_AggroNameSecondaryLabel)
		{
			Target_AggroNameSecondaryLabel->SetTopOffset(Target_AggroNameSecondaryLabel_TopOffsetOrg);
			Target_AggroNameSecondaryLabel->SetBottomOffset(Target_AggroNameSecondaryLabel_BottomOffsetOrg);
		}

		CLabelWnd* pAggroPctSecondaryLabel = (CLabelWnd*)pTargetWnd->GetChildItem("Target_AggroPctSecondaryLabel");
		if (Target_AggroPctSecondaryLabel && pAggroPctSecondaryLabel == Target_AggroPctSecondaryLabel)
		{
			Target_AggroPctSecondaryLabel->SetTopOffset(Target_AggroPctSecondaryLabel_TopOffsetOrg);
			Target_AggroPctSecondaryLabel->SetBottomOffset(Target_AggroPctSecondaryLabel_BottomOffsetOrg);
		}
	}
	Target_BuffWindow = nullptr;
	Target_AggroPctPlayerLabel = nullptr;
	Target_AggroNameSecondaryLabel = nullptr;
	Target_AggroPctSecondaryLabel = nullptr;

	if (pTargetWnd)
	{
		pTargetWnd->UpdateLayout();
	}
}

void UnpackIni()
{
	HMODULE hMe = nullptr;
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)UnpackIni, &hMe);

	if (HRSRC hRes = FindResource(hMe, MAKEINTRESOURCE(IDR_INI1), "INI"))
	{
		if (const HGLOBAL bin = LoadResource(hMe, hRes))
		{
			if (void* pMyBinaryData = LockResource(bin))
			{
				std::size_t ressize = SizeofResource(hMe, hRes);
				FILE* File = _fsopen(INIFileName, "wb", _SH_DENYWR);
				if (File != nullptr)
				{
					fwrite(pMyBinaryData, ressize, 1, File);
					fclose(File);
				}
			}
		}
	}
}

void HandleINI(eINIOptions Operation)
{
	std::error_code ec;
	// If the INI doesn't exist, create it and switch our operation to read.
	if (!std::filesystem::exists(INIFileName, ec))
	{
		UnpackIni();
		Operation = eINIOptions::ReadOnly;
	}

	char szSettingINISection[MAX_STRING] = "Default";

	if (!Initialized)
	{
		gbUsePerCharSettings = GetPrivateProfileBool(szSettingINISection, "UsePerCharSettings", gbUsePerCharSettings, INIFileName);
	}

	if (gbUsePerCharSettings && pLocalPlayer && GetServerShortName()[0] != '\0')
	{
		sprintf_s(szSettingINISection, "%s_%s", GetServerShortName(), pLocalPlayer->Name);
	}

	std::string strUISection = "UI_";
	strUISection.append(szSettingINISection);

	//Reads from INI
	if (Operation == eINIOptions::ReadOnly || Operation == eINIOptions::ReadAndWrite)
	{
		gbShowDistance = GetPrivateProfileBool(szSettingINISection, "ShowDistance", gbShowDistance, INIFileName);
		gbShowTargetInfo = GetPrivateProfileBool(szSettingINISection, "ShowTargetInfo", gbShowTargetInfo, INIFileName);
		gbShowPlaceholder = GetPrivateProfileBool(szSettingINISection, "ShowPlaceholder", gbShowPlaceholder, INIFileName);
		gbShowAnon = GetPrivateProfileBool(szSettingINISection, "ShowAnon", gbShowAnon, INIFileName);
		gbShowSight = GetPrivateProfileBool(szSettingINISection, "ShowSight", gbShowSight, INIFileName);
		DistanceLabelToolTip = GetPrivateProfileString(szSettingINISection, "DistanceLabelToolTip", DistanceLabelToolTip, INIFileName);
		ManaLabelName = GetPrivateProfileString(szSettingINISection, "ManaLabelName", ManaLabelName, INIFileName);
		FatigueLabelName = GetPrivateProfileString(szSettingINISection, "FatigueLabelName", FatigueLabelName, INIFileName);

		Target_BuffWindow_TopOffset = GetPrivateProfileInt(strUISection, "Target_BuffWindow_TopOffset", Target_BuffWindow_TopOffset, INIFileName);
		dTopOffset = GetPrivateProfileInt(strUISection, "dTopOffset", dTopOffset, INIFileName);
		dBottomOffset = GetPrivateProfileInt(strUISection, "dBottomOffset", dBottomOffset, INIFileName);
		TargetInfoWindowStyle = GetPrivateProfileInt(strUISection, "TargetInfoWindowStyle", TargetInfoWindowStyle, INIFileName);
		TargetInfoAnchoredToRight = GetPrivateProfileInt(strUISection, "TargetInfoAnchoredToRight", TargetInfoAnchoredToRight, INIFileName);

		TargetDistanceLoc = GetPrivateProfileString(strUISection, "TargetDistanceLoc", TargetDistanceLoc, INIFileName);
		TargetInfoLoc = GetPrivateProfileString(strUISection, "TargetInfoLoc", TargetInfoLoc, INIFileName);
		TargetInfoColor = ParseColorString(TargetInfoColor, GetPrivateProfileString(strUISection, "TargetInfoColor", "0,255,0", INIFileName));
		CanSeeIndicatorLoc = GetPrivateProfileString(strUISection, "CanSeeIndicatorLoc", CanSeeIndicatorLoc, INIFileName);
		TargetMeleeRngColor = ParseColorString(TargetMeleeRngColor, GetPrivateProfileString(strUISection, "TargetMeleeRngColor", "0,0,255", INIFileName));
		TargetDistanceShort = GetPrivateProfileInt(strUISection, "TargetDistanceShort", TargetDistanceShort, INIFileName);
		TargetSpellRngColor = ParseColorString(TargetSpellRngColor, GetPrivateProfileString(strUISection, "TargetSpellRngColor", "0,255,0", INIFileName));
		TargetDistanceMedium = GetPrivateProfileInt(strUISection, "TargetDistanceMedium", TargetDistanceMedium, INIFileName);
		TargetBowRngColor = ParseColorString(TargetBowRngColor, GetPrivateProfileString(strUISection, "TargetBowRngColor", "255,255,0", INIFileName));
		TargetDistanceLong = GetPrivateProfileInt(strUISection, "TargetDistanceLong", TargetDistanceLong, INIFileName);
		TargetFarRngColor = ParseColorString(TargetFarRngColor, GetPrivateProfileString(strUISection, "TargetFarRngColor", "255,0,0", INIFileName));
		/* End multiple location defaults */
	}
	//Writes to INI
	if (Operation == eINIOptions::WriteOnly || Operation == eINIOptions::ReadAndWrite)
	{
		WritePrivateProfileBool("Default", "UsePerCharSettings", gbUsePerCharSettings, INIFileName);

		WritePrivateProfileBool(szSettingINISection, "ShowDistance", gbShowDistance, INIFileName);
		WritePrivateProfileBool(szSettingINISection, "ShowTargetInfo", gbShowTargetInfo, INIFileName);
		WritePrivateProfileBool(szSettingINISection, "ShowPlaceholder", gbShowPlaceholder, INIFileName);
		WritePrivateProfileBool(szSettingINISection, "ShowAnon", gbShowAnon, INIFileName);
		WritePrivateProfileBool(szSettingINISection, "ShowSight", gbShowSight, INIFileName);

		WritePrivateProfileString(szSettingINISection, "DistanceLabelToolTip", DistanceLabelToolTip, INIFileName);
		WritePrivateProfileString(szSettingINISection, "ManaLabelName", ManaLabelName, INIFileName);
		WritePrivateProfileString(szSettingINISection, "FatigueLabelName", FatigueLabelName, INIFileName);

		WritePrivateProfileInt(strUISection, "Target_BuffWindow_TopOffset", Target_BuffWindow_TopOffset, INIFileName);
		WritePrivateProfileInt(strUISection, "dTopOffset", dTopOffset, INIFileName);
		WritePrivateProfileInt(strUISection, "dBottomOffset", dBottomOffset, INIFileName);
		WritePrivateProfileInt(strUISection, "TargetInfoWindowStyle", TargetInfoWindowStyle, INIFileName);
		WritePrivateProfileInt(strUISection, "TargetInfoAnchoredToRight", TargetInfoAnchoredToRight, INIFileName);

		WritePrivateProfileString(strUISection, "TargetDistanceLoc", TargetDistanceLoc, INIFileName);
		WritePrivateProfileString(strUISection, "TargetInfoLoc", TargetInfoLoc, INIFileName);
		WritePrivateProfileString(strUISection, "TargetInfoColor", FormatColorString(TargetInfoColor), INIFileName);
		WritePrivateProfileString(strUISection, "CanSeeIndicatorLoc", CanSeeIndicatorLoc, INIFileName);
		WritePrivateProfileString(strUISection, "TargetMeleeRngColor", FormatColorString(TargetMeleeRngColor), INIFileName);
		WritePrivateProfileInt(strUISection, "TargetDistanceShort", TargetDistanceShort, INIFileName);
		WritePrivateProfileString(strUISection, "TargetSpellRngColor", FormatColorString(TargetSpellRngColor), INIFileName);
		WritePrivateProfileInt(strUISection, "TargetDistanceMedium", TargetDistanceMedium, INIFileName);
		WritePrivateProfileString(strUISection, "TargetBowRngColor", FormatColorString(TargetBowRngColor), INIFileName);
		WritePrivateProfileInt(strUISection, "TargetDistanceLong", TargetDistanceLong, INIFileName);
		WritePrivateProfileString(strUISection, "TargetFarRngColor", FormatColorString(TargetFarRngColor), INIFileName);
	}
}

void Initialize()
{
	if (Initialized)
		return;

	if (GetGameState() == GAMESTATE_INGAME && !bDisablePluginDueToBadUI && pTargetWnd)
	{
		HandleINI(eINIOptions::ReadAndWrite);
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

		CControlTemplate* DistLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate(ManaLabelName.c_str());
		CControlTemplate* CanSeeLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate(FatigueLabelName.c_str());
		CControlTemplate* PHButtonTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("IDW_ModButton"); // borrowing this...

		if (PHButtonTemplate && CanSeeLabelTemplate && DistLabelTemplate)
		{
			const int oldphfont = PHButtonTemplate->nFont;

			const std::string OldManaLabelName = DistLabelTemplate->strName.c_str();
			const std::string OldManaLabelScreenName = DistLabelTemplate->strScreenId.c_str();
			const std::string OldManaLabelController = DistLabelTemplate->strController.c_str();

			const int oldfont = DistLabelTemplate->nFont;

			const std::string OldFatigueLabelName = CanSeeLabelTemplate->strName.c_str();
			const std::string OldFatigueLabelScreenName = CanSeeLabelTemplate->strScreenId.c_str();
			const std::string OldFatigueLabelController = CanSeeLabelTemplate->strController.c_str();

			DistLabelTemplate->nFont = 2;
			DistLabelTemplate->strController = "0";
			CanSeeLabelTemplate->strController = "0";

			// create the info label
			DistLabelTemplate->strName = "Target_InfoLabel";
			DistLabelTemplate->strScreenId = "Target_InfoLabel";

			if (InfoLabel = (CLabelWnd*)pSidlMgr->CreateXWndFromTemplate(pTargetWnd, DistLabelTemplate))
			{
				if (TargetInfoAnchoredToRight)
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

				const CXRect rectInfo = GetCXRectTBLRFromString(TargetInfoLoc, 34, 48, 0, 40);

				InfoLabel->SetTopOffset(rectInfo.top);
				InfoLabel->SetBottomOffset(rectInfo.bottom);
				InfoLabel->SetLeftOffset(rectInfo.left);
				InfoLabel->SetRightOffset(rectInfo.right);

				InfoLabel->SetCRNormal(TargetInfoColor);
				InfoLabel->SetBGColor(MQColor(255, 255, 255));
				InfoLabel->SetTooltip(szTargetInfo);
			}

			DistanceLabel = CreateDistLabel(pTargetWnd, DistLabelTemplate,"Target_DistLabel", 2, GetCXRectTBLRFromString(TargetDistanceLoc, 34, 48, 90, 0), true, gbShowDistance);

			//create can see label
			int oldfont2 = CanSeeLabelTemplate->nFont;
			CanSeeLabelTemplate->nFont = 2;
			CanSeeLabelTemplate->strName = "Target_CanSeeLabel";
			CanSeeLabelTemplate->strScreenId = "Target_CanSeeLabel";
			const CXRect rectCanSee = GetCXRectTBLRFromString(CanSeeIndicatorLoc, 47, 61, 50, 0);

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
				CanSeeLabel->SetTopOffset(rectCanSee.top);
				CanSeeLabel->SetTopOffset(CanSeeLabel->GetTopOffset() + 10);
				CanSeeLabel->SetBottomOffset(rectCanSee.bottom);
				CanSeeLabel->SetBottomOffset(CanSeeLabel->GetBottomOffset() + 10);
				CanSeeLabel->SetLeftOffset(rectCanSee.left);
				CanSeeLabel->SetRightOffset(rectCanSee.right);
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
				PHButton->SetTopOffset(rectCanSee.top + 1);
				PHButton->SetBottomOffset(dTopOffset - 1);
				PHButton->SetLeftOffset(0);
				PHButton->SetRightOffset(0);
				// left top right bottom
				PHButton->SetLocation({ 2, rectCanSee.top + 1, 20, PHButton->GetBottomOffset() });

				PHButton->SetCRNormal(0xFF00FFFF); // cyan
				PHButton->SetBGColor(0xFFFFFFFF);
				PHButton->SetTooltip(szPHToolTip);
				PHButton->SetWindowText(szPH);
			}

			// now set the template values back
			DistLabelTemplate->nFont = oldfont;
			CanSeeLabelTemplate->nFont = oldfont2;
			PHButtonTemplate->nFont = oldphfont;
			DistLabelTemplate->strName = OldManaLabelName;
			DistLabelTemplate->strScreenId = OldManaLabelScreenName;
			DistLabelTemplate->strController = OldManaLabelController;
			CanSeeLabelTemplate->strName = OldFatigueLabelName;
			CanSeeLabelTemplate->strScreenId = OldFatigueLabelScreenName;
			CanSeeLabelTemplate->strController = OldFatigueLabelController;
		}
		else
		{
			bDisablePluginDueToBadUI = true;
			WriteChatf("MQ2TargetInfo has been disabled due to an incompatible UI, let a developer know.");
			return;
		}

		if (!(InfoLabel && DistanceLabel && CanSeeLabel && PHButton))
		{
			WriteChatf("MQ2TargetInfo has failed to initialize, try toggling the plugin.");
		}
		Initialized = true;
	}
}

void ShowHelp()
{
	WriteChatf("\ayMQ2TargetInfo Usage (green indicates your current setting):");
	WriteChatf("     \ay/targetinfo perchar [%sOn\ay|%sOff\ay]\aw will toggle splitting settings by character.", gbUsePerCharSettings ? "\ag" : "", gbUsePerCharSettings ? "" : "\ag");
	WriteChatf("     \ay/targetinfo distance [%sOn\ay|%sOff\ay]\aw will toggle showing distance to target.", gbShowDistance ? "\ag" : "", gbShowDistance ? "" : "\ag");
	WriteChatf("     \ay/targetinfo info [%sOn\ay|%sOff\ay]\aw will toggle showing detailed target info.", gbShowTargetInfo ? "\ag" : "", gbShowTargetInfo ? "" : "\ag");
	WriteChatf("     \ay/targetinfo placeholder [%sOn\ay|%sOff\ay]\aw will toggle showing placeholder/named info.", gbShowPlaceholder ? "\ag" : "", gbShowPlaceholder ? "" : "\ag");
	WriteChatf("     \ay/targetinfo anon [%sOn\ay|%sOff\ay]\aw will toggle showing anon/roleplaying in the target display.", gbShowAnon ? "\ag" : "", gbShowAnon ? "" : "\ag");
	WriteChatf("     \ay/targetinfo sight [%sOn\ay|%sOff\ay]\aw will toggle showing O/X based on your line of sight to target.", gbShowSight ? "\ag" : "", gbShowSight ? "" : "\ag");
	WriteChatf("     \ay/targetinfo reset\aw will reset all settings to default.");
	WriteChatf("     \ay/targetinfo reload\aw will reload all settings.");
}

void CMD_TargetInfo(SPAWNINFO* pPlayer, char* szLine)
{
	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);

	bool WriteIni = false;

	if (ci_equals(szArg1, "perchar"))
	{
		GetArg(szArg1, szLine, 2);
		gbUsePerCharSettings = GetBoolFromString(szArg1, !gbUsePerCharSettings);
		WriteIni = true;
	}
	else if (ci_equals(szArg1, "distance"))
	{
		GetArg(szArg1, szLine, 2);
		gbShowDistance = GetBoolFromString(szArg1, !gbShowDistance);
		WriteIni = true;
	}
	else if (ci_equals(szArg1, "info"))
	{
		GetArg(szArg1, szLine, 2);
		gbShowTargetInfo = GetBoolFromString(szArg1, !gbShowTargetInfo);
		WriteIni = true;
	}
	else if (ci_equals(szArg1, "placeholder"))
	{
		GetArg(szArg1, szLine, 2);
		gbShowPlaceholder = GetBoolFromString(szArg1, !gbShowPlaceholder);
		WriteIni = true;
	}
	else if (ci_equals(szArg1, "anon"))
	{
		GetArg(szArg1, szLine, 2);
		gbShowAnon = GetBoolFromString(szArg1, !gbShowAnon);
		WriteIni = true;
	}
	else if (ci_equals(szArg1, "sight"))
	{
		GetArg(szArg1, szLine, 2);
		gbShowSight = GetBoolFromString(szArg1, !gbShowSight);
		WriteIni = true;
	}
	else if (ci_equals(szArg1, "reset"))
	{
		UnpackIni();
		CleanUp();
		Initialized=false;
	}
	else if (ci_equals(szArg1, "reload"))
	{
		CleanUp();
		Initialized=false;
	}
	else
	{
		ShowHelp();
	}

	if (WriteIni)
	{
		HandleINI(eINIOptions::WriteOnly);
	}
}

PLUGIN_API void InitializePlugin()
{
	AddCommand("/targetinfo", CMD_TargetInfo);

	std::filesystem::path curFilepath = gPathResources;
	curFilepath /= "MQ2TargetInfoPHs.txt";

	std::error_code ec_exists;

	if (!std::filesystem::exists(curFilepath, ec_exists))
	{
		HMODULE hMe = nullptr;
		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)InitializePlugin, &hMe);

		// need to unpack our resource.
		if (HRSRC hRes = FindResource(hMe, MAKEINTRESOURCE(IDR_DB1), "DB"))
		{
			if (const HGLOBAL bin = LoadResource(hMe, hRes))
			{
				if (void* pMyBinaryData = LockResource(bin))
				{
					std::size_t ressize = SizeofResource(hMe, hRes);
					FILE* File = _fsopen(curFilepath.string().c_str(), "wb", _SH_DENYWR);
					if (File != nullptr)
					{
						fwrite(pMyBinaryData, ressize, 1, File);
						fclose(File);
					}
				}
			}
		}
	}

	LoadPHs(curFilepath.string().data());

	EzDetour(CTargetWnd__HandleBuffRemoveRequest, &MyCTargetWnd::HandleBuffRemoveRequest_Detour, &MyCTargetWnd::HandleBuffRemoveRequest_Tramp);
}

PLUGIN_API void ShutdownPlugin()
{
	CleanUp();
	RemoveCommand("/targetinfo");
	RemoveDetour(CTargetWnd__HandleBuffRemoveRequest);
}

PLUGIN_API void OnCleanUI()
{
	CleanUp();
}

PLUGIN_API void OnReloadUI()
{
	Initialized = false;
}

PLUGIN_API void OnPulse()
{
	if (GetGameState() != GAMESTATE_INGAME || !pLocalPlayer)
		return;

	static uint64_t lastPulseUpdate = MQGetTickCount64();
	const uint64_t currentTime = MQGetTickCount64();

	if (currentTime - lastPulseUpdate > 500) // 500ms
	{
		lastPulseUpdate = currentTime;

		if (pTargetWnd && pTargetWnd->IsVisible())
		{
			Initialize();
			if (InfoLabel && DistanceLabel && CanSeeLabel && PHButton)
			{
				if (pTarget)
				{
					if (gbShowPlaceholder)
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
					}
					else
					{
						PHButton->SetVisible(false);
					}

					char szTargetDist[EQ_MAX_NAME] = { 0 };

					if (gbShowTargetInfo)
					{
						switch (pTarget->Anon)
						{
							case 1:
								if (gbShowAnon)
								{
									strcpy_s(szTargetDist, "Anonymous");
									break;
								}
							case 2:
								if (gbShowAnon)
								{
									strcpy_s(szTargetDist, "Roleplaying");
									break;
								}
							default:
							{
								if (pTarget->Type == SPAWN_PLAYER)
								{
									sprintf_s(szTargetDist, "%d %s %s", pTarget->Level, pTarget->GetRaceString(), pTarget->GetClassThreeLetterCode());
								}
								else
								{
									sprintf_s(szTargetDist, "%d %s %s", pTarget->Level, pTarget->GetRaceString(),pTarget->GetClassString());
								}
							}
						}

						InfoLabel->SetWindowText(szTargetDist);
					}
					InfoLabel->SetVisible(gbShowTargetInfo);

					// then distance
					if(gbShowDistance)
					{
						float dist = Distance3DToSpawn(pLocalPlayer, pTarget);
						sprintf_s(szTargetDist, "%.0f", dist);

						if (dist < TargetDistanceShort)
						{
							DistanceLabel->SetCRNormal(TargetMeleeRngColor);
						}
						else if (dist >= TargetDistanceShort && dist < TargetDistanceMedium)
						{
							DistanceLabel->SetCRNormal(TargetSpellRngColor);
						}
						else if (dist >= TargetDistanceMedium && dist < TargetDistanceLong)
						{
							DistanceLabel->SetCRNormal(TargetBowRngColor);
						}
						else
						{
							DistanceLabel->SetCRNormal(TargetFarRngColor);
						}

						DistanceLabel->SetWindowText(szTargetDist);
					}
					DistanceLabel->SetVisible(gbShowDistance);

					// now do can see
					if (gbShowSight)
					{
						if (pLocalPlayer->CanSee(*(PlayerClient*)pTarget))
						{
							strcpy_s(szTargetDist, "O");
							CanSeeLabel->SetCRNormal(MQColor(0, 255, 0)); // green
						}
						else
						{
							strcpy_s(szTargetDist, "X");
							CanSeeLabel->SetCRNormal(MQColor(255, 0, 0)); // red
						}
						CanSeeLabel->SetWindowText(szTargetDist);
					}

					CanSeeLabel->SetVisible(gbShowSight);

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
