// MQ2XTarInfo.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup.

#include <mq/Plugin.h>
#include "resource.h"

PreSetup("MQ2XTarInfo");
PLUGIN_VERSION(0.1);

bool gBShowExtDistance = true;
bool gBUsePerCharSettings = false;
bool Initialized = false;
bool bDisablePluginDueToBadUI = false;

// TODO: This should probably be a map of UI settings
/* Also defaulted in HandleINI() for INI reads and in the .ini resource */
bool gbUseExtLayoutBox = false; // see note above
std::string BaseLabelName = "Player_ManaLabel"; // see note above
std::string ExtDistanceLoc = "0,-20,70,0"; // see note above
/* End multiple location defaults */

std::string DistanceLabelToolTip = "XTarget Distance";

CGaugeWnd* ETW_Gauge[MAX_EXTENDED_TARGET_SIZE] = { nullptr };
CLabelWnd* ETW_DistLabel[MAX_EXTENDED_TARGET_SIZE] = { nullptr };

DWORD orgExtTargetWindStyle = 0;

enum class eINIOptions
{
	WriteOnly,
	ReadAndWrite,
	ReadOnly
};

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
		gBUsePerCharSettings = GetPrivateProfileBool("Default", "UsePerCharSettings", gBUsePerCharSettings, INIFileName);
	}

	if (gBUsePerCharSettings && pLocalPlayer && GetServerShortName()[0] != '\0')
	{
		sprintf_s(szSettingINISection, "%s_%s", GetServerShortName(), pLocalPlayer->Name);
	}

	std::string strUISection = "UI_";
	strUISection.append(gUISkin);

	if (Operation == eINIOptions::ReadOnly || Operation == eINIOptions::ReadAndWrite)
	{
		gBShowExtDistance = GetPrivateProfileBool(szSettingINISection, "ShowDistance", gBShowExtDistance, INIFileName);
		DistanceLabelToolTip = GetPrivateProfileString(szSettingINISection, "DistanceLabelToolTip", DistanceLabelToolTip, INIFileName);

		/* Also defaulted on the global and in the .ini resource */
		gbUseExtLayoutBox = GetPrivateProfileBool(strUISection, "UseExtLayoutBox", false, INIFileName); // see note above
		BaseLabelName = GetPrivateProfileString(strUISection, "LabelBaseXT", "Player_ManaLabel", INIFileName); // see note above
		ExtDistanceLoc = GetPrivateProfileString(strUISection, "ExtDistanceLoc", "0,-20,70,0", INIFileName); // see note above
		/* End multiple location defaults */
	}
	if (Operation == eINIOptions::WriteOnly || Operation == eINIOptions::ReadAndWrite)
	{
		WritePrivateProfileBool("Default", "UsePerCharSettings", gBUsePerCharSettings, INIFileName);

		WritePrivateProfileBool(szSettingINISection, "ShowDistance", gBShowExtDistance, INIFileName);
		WritePrivateProfileString(szSettingINISection, "DistanceLabelToolTip", DistanceLabelToolTip, INIFileName);

		WritePrivateProfileBool(strUISection, "UseExtLayoutBox", gbUseExtLayoutBox, INIFileName);
		WritePrivateProfileString(strUISection, "LabelBaseXT", BaseLabelName, INIFileName);
		WritePrivateProfileString(strUISection, "ExtDistanceLoc", ExtDistanceLoc, INIFileName);
	}
}

void Initialize()
{
	if (Initialized)
		return;

	if (GetGameState() == GAMESTATE_INGAME && !bDisablePluginDueToBadUI)
	{
		if (CXWnd* pExtWnd = FindMQ2Window("ExtendedTargetWnd"))
		{
			HandleINI(eINIOptions::ReadAndWrite);
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

			CControlTemplate* DistLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate(BaseLabelName.c_str());
			if (DistLabelTemplate)
			{
				int oldfont = DistLabelTemplate->nFont;
				const std::string OldBaseLabelController = DistLabelTemplate->strController.c_str();

				DistLabelTemplate->strController = "0";

				const CXRect rect = GetCXRectTBLRFromString(ExtDistanceLoc, 0, -20, 70, 0);

				int max_targets = MAX_EXTENDED_TARGET_SIZE;
				if (CHARINFO* pChar = GetCharInfo())
				{
					if (ExtendedTargetList* xtm = pChar->pXTargetMgr)
					{
						max_targets = xtm->XTargetSlots.Count;
					}
				}

				for (int i = 0; i < max_targets; i++)
				{
					char szTemp[MAX_STRING] = { 0 };
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

						if (gbUseExtLayoutBox)
						{
							ETW_DistLabel[i] = CreateDistLabel(ETW_Gauge[i], DistLabelTemplate, szTemp, 2, CXRect(left + rect.left, top + rect.top, right + rect.right, bottom + rect.bottom), true, gBShowExtDistance);
						}
						else
						{
							ETW_DistLabel[i] = CreateDistLabel(pExtWnd, DistLabelTemplate, szTemp, 2, CXRect(left + rect.left, top + rect.top, right + rect.right, bottom + rect.bottom), true, gBShowExtDistance);
						}
					}
				}

				DistLabelTemplate->nFont = oldfont;
				// now set the template values back
				DistLabelTemplate->strController = OldBaseLabelController;
			}
			else
			{
				bDisablePluginDueToBadUI = true;
				WriteChatf("MQ2XTarInfo has been disabled due to an incompatible UI, let a developer know.");
				return;
			}
			Initialized = true;
		}
	}
}

void UpdatedExtDistance()
{
	if (!pLocalPC)
		return;

	ExtendedTargetList* xtm = pLocalPC->pXTargetMgr;

	for (int i = 0; i < xtm->GetNumSlots(); i++)
	{
		if (CLabelWnd* pWnd = ETW_DistLabel[i])
		{
			const ExtendedTargetSlot& xts = *xtm->GetSlot(i);
			uint32_t spID = xts.SpawnID;

			if (spID)
			{
				if (SPAWNINFO* pSpawn = GetSpawnByID(spID))
				{
					char szTargetDist[EQ_MAX_NAME] = { 0 };
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

void CleanUp()
{
	bDisablePluginDueToBadUI = false;

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
}

void ShowHelp()
{
	WriteChatf("\ayMQ2XTarInfo Usage (green indicates your current setting):");
	WriteChatf("     \ay/xtarinfo perchar [%sOn\ay|%sOff\ay]\aw will toggle splitting settings by character.\ax.", gBUsePerCharSettings ? "\ag" : "", gBUsePerCharSettings ? "" : "\ag");
	WriteChatf("     \ay/xtarinfo distance [%sOn\ay|%sOff\ay]\aw will toggle showing distance to target.\ax.", gBShowExtDistance ? "\ag" : "", gBShowExtDistance ? "" : "\ag");
	WriteChatf("     \ay/xtarinfo reset\ax will reset all settings to default.");
	WriteChatf("     \ay/xtarinfo reload\ax will reload all settings.\ax.");
}

void CMD_XTarInfo(SPAWNINFO* pPlayer, char* szLine)
{
	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);

	bool WriteIni = false;

	if (ci_equals(szArg1, "perchar"))
	{
		GetArg(szArg1, szLine, 2);
		gBUsePerCharSettings = GetBoolFromString(szArg1, !gBUsePerCharSettings);
		WriteIni = true;
	}
	else if (ci_equals(szArg1, "distance"))
	{
		GetArg(szArg1, szLine, 2);
		gBShowExtDistance = GetBoolFromString(szArg1, !gBShowExtDistance);
		for (auto& label : ETW_DistLabel)
		{
			if (label)
			{
				label->SetVisible(gBShowExtDistance);
			}
		}
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
	AddCommand("/xtarinfo", CMD_XTarInfo);
	Initialize();
}

PLUGIN_API void ShutdownPlugin()
{
	CleanUp();
	RemoveCommand("/xtarinfo");
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
	if (GetGameState() != GAMESTATE_INGAME || !pLocalPC)
		return;

	static uint64_t lastPulseUpdate = MQGetTickCount64();
	uint64_t currentTime = MQGetTickCount64();

	if (currentTime - lastPulseUpdate > 500) // 500ms
	{
		lastPulseUpdate = currentTime;
		Initialize();

		if (gBShowExtDistance && ETW_DistLabel[0] && pExtendedTargetWnd && pExtendedTargetWnd->IsVisible())
		{
			UpdatedExtDistance();
		}
	}
}
