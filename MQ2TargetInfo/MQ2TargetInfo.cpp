// MQ2TargetInfo.cpp : Defines the entry point for the DLL application.
// by EqMule 2018

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.

#include "../MQ2Plugin.h"
#include "resource.h"

PreSetup("MQ2TargetInfo");
CHAR szTargetInfo[128] = { "Target Info" };
CHAR szTargetDistance[128] = { "Target Distance" };
CHAR szGroupDistance[128] = { "Member Distance" };
CHAR szCanSeeTarget[128] = { "Can See Target" };
CHAR szPHToolTip[128] = { "Target is a Place Holder" };
CHAR szPH[128] = { "PH" };
CHAR szNavToolTip[128] = { "ALL will Nav to Me" };
CHAR szNav[128] = { "Come to Me" };
CHAR szFollowMeToolTip[128] = { "Follow Me around." };
CHAR szFollowMe[128] = { "Follow Me" };
CHAR szMimicMeToolTip[128] = { "Everyone does what I do, I target something, they do as well, I hail, they hail, etc." };
CHAR szMimicMe[128] = { "Mimic Me" };
CHAR szMMainTip[128] = { "MQ2TargetInfo is Active: Type /groupinfo help or rightclick this window to see a menu" };

HANDLE hLockphmap = 0;

CLabelWnd*InfoLabel = 0;
CLabelWnd*DistanceLabel = 0;
CLabelWnd*CanSeeLabel = 0;

CButtonWnd*PHButton = 0;
CButtonWnd*NavButton = 0;
CButtonWnd*FollowMeButton = 0;
CButtonWnd*MimicMeButton = 0;

CHotButton*GroupHotButton = 0;

bool gbFollowme = false;
bool gbMimicme = false;

CSidlScreenWnd*Target_BuffWindow = 0;
CLabelWnd*Target_AggroPctPlayerLabel = 0;
CLabelWnd*Target_AggroNameSecondaryLabel = 0;
CLabelWnd*Target_AggroPctSecondaryLabel = 0;

typedef struct _phinfo
{
	std::string Expansion;
	std::string Zone;
	std::string Named;
	std::string Link;
}phinfo,*pphinfo;

std::map<std::string, phinfo> phmap;
bool GetPhMap(PSPAWNINFO pSpawn, phinfo *pinf);
class MyCTargetWnd
{
public:
	//we can safely use this as its always called when a user leftclicks the target window.
	//also the upside here is that we dont collide with the trade with target detour in mq2windows...
	void MyCTargetWnd::HandleBuffRemoveRequest_Tramp(CXWnd *);
	void MyCTargetWnd::HandleBuffRemoveRequest_Detour(CXWnd *pWnd)
	{
		if(PHButton && pWnd==PHButton)
		{
			if (pTarget) {
				phinfo pinf;
				if (GetPhMap((PSPAWNINFO)pTarget, &pinf)) {
					std::string url = "https://webproxy.to/browse.php?b=4&u=";
					url.append(pinf.Link);// https://eqresource.com&b=4";
					//std::string url = "https://www.google.com/search?q=";
					//std::string url = "http://everquest.allakhazam.com/search.html?q=";
					//url.append(pinf.Named);
					if (CHtmlWnd *ItemHtmlwnd = pCWebManager->CreateHtmlWnd(url.c_str(), pinf.Named.c_str(), NULL, true, pinf.Named.c_str()))
					{
						//Beep(1000, 100);
					}
				}
			}
		}
		HandleBuffRemoveRequest_Tramp(pWnd);
	}
};
DETOUR_TRAMPOLINE_EMPTY(void MyCTargetWnd::HandleBuffRemoveRequest_Tramp(CXWnd*));
void LoadPHs(char*szMyName) {
	//well we have it, lets fill in the map...
	//Chief Librarian Lars^a shissar arbiter, a shissar defiler^tds^kattacastrumdeluge^https://tds.eqresource.com/chieflibrarianlars.php
	phinfo phinf;
	std::string phs;
	int commapos = 0;
	CHAR szBuffer[2048] = { 0 };
	FILE *fp = 0;
	errno_t err = fopen_s(&fp, szMyName, "rb");
	if (!err) {
		while (fgets(szBuffer, 2048, fp) != 0) {
			if (char *pDest = strchr(szBuffer, '^')) {
				pDest[0] = '\0';
				phinf.Named = szBuffer;
				pDest++;
				if (char *pDest2 = strchr(pDest, '^')) {
					pDest2[0] = '\0';
					phs = pDest;
					*pDest2++;
					if (pDest = strchr(pDest2, '^')) {
						pDest[0] = '\0';
						phinf.Expansion = pDest2;
						pDest++;
						if (pDest2 = strchr(pDest, '^')) {
							pDest2[0] = '\0';
							phinf.Zone = pDest;
							pDest2++;
							if (pDest = strchr(pDest2, '\r')) {
								pDest[0] = '\0';
							}
							phinf.Link = pDest2;
						}
					}
				}
			}
			if (phs.find(",") != phs.npos && phs.find("Yikkarvi,") == phs.npos &&
				phs.find("Furg,") == phs.npos && phs.find("Tykronar,") == phs.npos &&
				phs.find("Ejarld,") == phs.npos && phs.find("Grald,") == phs.npos &&
				phs.find("Graluk,") == phs.npos) {
				while ((commapos = phs.find_last_of(",")) != phs.npos) {
					//more than one...
					std::string temp = phs.substr(commapos + 2, -1);
					phs.erase(commapos, -1);
					phmap[temp] = phinf;
				}
				phmap[phs] = phinf;
			}
			else {
				phmap[phs] = phinf;
			}
		}
		fclose(fp);
	}
}
/*#define Target_BuffWindow_TopOffset 62;
#define dTopOffset 46;
#define dBottomOffset 60;
#define InfoTopOffset 33;
#define dLeftOffset 50;
#define InfoBottomOffset 47;
*/
#define Target_BuffWindow_TopOffset 62+14;
#define dTopOffset 46+14;
#define dBottomOffset 60+14;
#define InfoTopOffset 33+14;
#define dLeftOffset 50;
#define InfoBottomOffset 47+14;
CGaugeWnd *GW_Gauge1 = 0;
CGaugeWnd *GW_Gauge2 = 0;
CGaugeWnd *GW_Gauge3 = 0;
CGaugeWnd *GW_Gauge4 = 0;
CGaugeWnd *GW_Gauge5 = 0;
CLabelWnd *GroupDistLabel1 = 0;
CLabelWnd *GroupDistLabel2 = 0;
CLabelWnd *GroupDistLabel3 = 0;
CLabelWnd *GroupDistLabel4 = 0;
CLabelWnd *GroupDistLabel5 = 0;
bool CreateDistLabel(CGroupWnd*pGwnd,CControlTemplate *DistLabelTemplate,CLabelWnd **labelwnd,char*label,int top, int bottom, int right,bool bShow)
{
	SetCXStr(&DistLabelTemplate->Name, label);
	SetCXStr(&DistLabelTemplate->ScreenID, label);
	if (*labelwnd = (CLabelWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)pGwnd, DistLabelTemplate)) {
		(*labelwnd)->dShow = true;
		(*labelwnd)->TopOffset = top;
		(*labelwnd)->BottomOffset = top+12;
		(*labelwnd)->LeftOffset = 70;
		(*labelwnd)->RightOffset = 0;
		(*labelwnd)->CRNormal = 0xFF00FF00;//green
		(*labelwnd)->BGColor = 0xFFFFFFFF;
		SetCXStr(&(*labelwnd)->Tooltip, szGroupDistance);
		(*labelwnd)->dShow = bShow;
		return true;
	}
	return false;
}
int navmenuid = 0;
int separatorid = 0;
int separatorid2 = 0;
int groundmenuid = 0;
int doormenuid = 0;
int switchtomenuid = 0;
int cometomeoptionmenuid = 0;
int mimicmeoptionmenuid = 0;
int followmeoptionmenuid = 0;
int hotoptionmenuid = 0;
int distanceoptionmenuid = 0;



void CreateAButton(CGroupWnd*pGwnd,CControlTemplate *Template,CButtonWnd **button,char*label,char*labelscreen, int fontsize, int top, int bottom, int left, int right, COLORREF color, COLORREF bgcolor, char*tooltip, char*text,bool bShow)
{
	Template->Font = 1;
	SetCXStr(&Template->Name, label);
	SetCXStr(&Template->ScreenID, labelscreen);
	if (*button = (CButtonWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)pGwnd, Template)) {

		(*button)->dShow = true;
		(*button)->TopOffset = top;
		(*button)->BottomOffset = bottom;
		(*button)->LeftOffset = left;
		(*button)->RightOffset = right;
		(*button)->CRNormal = color;
		(*button)->BGColor = bgcolor;
		SetCXStr(&(*button)->WindowText, text);
		SetCXStr(&(*button)->Tooltip, tooltip);
		(*button)->dShow = bShow;
	}
}

bool gBUsePerCharSettings = FALSE;
bool gBShowMimicMeButton = TRUE;
bool gBShowComeToMeButton = TRUE;
bool gBShowFollowMeButton = TRUE;
bool gBShowHotButton = TRUE;
bool gBShowDistance = TRUE;

void RemoveOurMenu(CGroupWnd*pGwnd)
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
			pGwnd->GroupContextMenu->RemoveMenuItem(switchtomenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(doormenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(groundmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(navmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(separatorid2);
			switchtomenuid = 0;
			doormenuid = 0;
			groundmenuid = 0;
			navmenuid = 0;
			separatorid2 = 0;
		}
		if (separatorid)
		{
			pGwnd->GroupContextMenu->RemoveMenuItem(distanceoptionmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(hotoptionmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(followmeoptionmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(mimicmeoptionmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(cometomeoptionmenuid);

			pGwnd->GroupContextMenu->RemoveMenuItem(separatorid);

			distanceoptionmenuid = 0;
			hotoptionmenuid = 0;
			followmeoptionmenuid = 0;
			mimicmeoptionmenuid = 0;
			cometomeoptionmenuid = 0;
			separatorid = 0;
		}
	}
}
void AddOurMenu(CGroupWnd*pGwnd,bool bMemberClicked)
{
	//if (pGwnd->GroupContextMenu && (!distanceoptionmenuid || bMemberClicked))
	if (pGwnd->GroupContextMenu)
	{
		RemoveOurMenu(pGwnd);
		separatorid = pGwnd->GroupContextMenu->AddSeparator();
		cometomeoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Come to Me Button", 58, gBShowComeToMeButton);
		mimicmeoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Mimic Me Button", 59, gBShowMimicMeButton);
		followmeoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Follow Button", 60, gBShowFollowMeButton);
		hotoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Hot Button", 61, gBShowHotButton);
		distanceoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Distance", 62, gBShowDistance);

		//
		if (bMemberClicked)
		{
			separatorid2 = pGwnd->GroupContextMenu->AddSeparator();
			navmenuid = pGwnd->GroupContextMenu->AddMenuItem("Nav to Me", 54);
			groundmenuid = pGwnd->GroupContextMenu->AddMenuItem("Pick Up Nearest Ground Item", 55);
			doormenuid = pGwnd->GroupContextMenu->AddMenuItem("Click Nearest Door", 56);
			switchtomenuid = pGwnd->GroupContextMenu->AddMenuItem("Switch to...", 57);
		}
		pContextMenuManager->Flush();
	}
}

template <unsigned int _Size>LPSTR SafeItoa(int _Value,char(&_Buffer)[_Size], int _Radix)
{
	errno_t err = _itoa_s(_Value, _Buffer, _Radix);
	if (!err) {
		return _Buffer;
	}
	return "";
}

void WriteSetting(const char*Key, const char*value)
{
	CHAR szSettingINISection[MAX_STRING] = { 0 };
	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0' || !gBUsePerCharSettings)
	{
		strcpy_s(szSettingINISection, "Default");
	}
	else
	{
		sprintf_s(szSettingINISection, "%s_%s", EQADDR_SERVERNAME, ((PSPAWNINFO)pLocalPlayer)->Name);
	}
	WritePrivateProfileString(szSettingINISection, Key, value, INIFileName);
	int ival = atoi(value);
	WriteChatf("\ayMQ2TargetInfo\ax::\am%s is now %s\ax.",Key, ival ? "\aoON" : "\agOFF");
}
int ReadSetting(char*Key,int defaultval)
{
	CHAR szSettingINISection[MAX_STRING] = { 0 };
	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0' || !gBUsePerCharSettings)
	{
		strcpy_s(szSettingINISection, "Default");
	}
	else
	{
		sprintf_s(szSettingINISection, "%s_%s", EQADDR_SERVERNAME, ((PSPAWNINFO)pLocalPlayer)->Name);
	}
	int ret = GetPrivateProfileInt(szSettingINISection, Key, -1, INIFileName);
	if (ret == -1)
	{
		CHAR szTemp[MAX_STRING] = { 0 };
		WritePrivateProfileString(szSettingINISection, Key, SafeItoa(defaultval,szTemp,10), INIFileName);
		return defaultval;
	}
	else {
		if (!_stricmp(Key, "HotButtonBottom"))
		{
			if (ret == 7)
			{
				WriteChatf("MQ2TargetInfo.ini changed: Setting HotButtonBottom to %d because it was 7 and that makes it cover the disband button so it can't be clicked.",defaultval);
				CHAR szTemp[MAX_STRING] = { 0 };
				WritePrivateProfileString(szSettingINISection, Key, SafeItoa(defaultval,szTemp,10), INIFileName);
				return defaultval;
			}
		}
	}
	return ret;
}
void ReadIniSettings()
{
	CHAR szSettingINISection[MAX_STRING] = { 0 };
	int ret = GetPrivateProfileInt("Default", "UsePerCharSettings", -1, INIFileName);
	gBUsePerCharSettings = (ret == 0 ? FALSE : TRUE);
	if (ret == -1)
	{
		gBUsePerCharSettings = 0;
		WritePrivateProfileString("Default", "UsePerCharSettings", "0", INIFileName);
		//first run we need to fix a bug with hotbutton covering disband button in old inifiles
		if (pLocalPlayer && EQADDR_SERVERNAME[0] != '\0')
		{
			sprintf_s(szSettingINISection, "%s_%s", EQADDR_SERVERNAME, ((PSPAWNINFO)pLocalPlayer)->Name);
			ret = GetPrivateProfileInt(szSettingINISection, "HotButtonBottom", -1, INIFileName);
			if (ret == 7)
			{
				WritePrivateProfileString(szSettingINISection, "HotButtonBottom", "24", INIFileName);
			}
		}
	}
	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0' || gBUsePerCharSettings == FALSE)
	{
		strcpy_s(szSettingINISection, "Default");
	}
	else
	{
		sprintf_s(szSettingINISection, "%s_%s", EQADDR_SERVERNAME, ((PSPAWNINFO)pLocalPlayer)->Name);
	}
	ret = GetPrivateProfileInt(szSettingINISection, "ShowMimicMeButton", -1, INIFileName);
	gBShowMimicMeButton = (ret == 0 ? FALSE : TRUE);
	if (ret == -1)
	{
		WritePrivateProfileString(szSettingINISection, "ShowMimicMeButton", "1", INIFileName);
	}
	ret = GetPrivateProfileInt(szSettingINISection, "ShowComeToMeButton", -1, INIFileName);
	gBShowComeToMeButton = (ret == 0 ? FALSE : TRUE);
	if (ret == -1)
	{
		WritePrivateProfileString(szSettingINISection, "ShowComeToMeButton", "1", INIFileName);
	}
	ret = GetPrivateProfileInt(szSettingINISection, "ShowFollowMeButton", -1, INIFileName);
	gBShowFollowMeButton = (ret == 0 ? FALSE : TRUE);
	if (ret == -1)
	{
		WritePrivateProfileString(szSettingINISection, "ShowFollowMeButton", "1", INIFileName);
	}
	ret = GetPrivateProfileInt(szSettingINISection, "ShowHotButton", -1, INIFileName);
	gBShowHotButton = (ret == 0 ? FALSE : TRUE);
	if (ret == -1)
	{
		WritePrivateProfileString(szSettingINISection, "ShowHotButton", "1", INIFileName);
	}
	ret = GetPrivateProfileInt(szSettingINISection, "ShowDistance", -1, INIFileName);
	gBShowDistance = (ret == 0 ? FALSE : TRUE);
	if (ret == -1)
	{
		WritePrivateProfileString(szSettingINISection, "ShowDistance", "1", INIFileName);
	}
}
void Initialize()
{
	if (!PHButton && GetGameState() == GAMESTATE_INGAME)
	{
		ReadIniSettings();
		//setup the group info
		if (CGroupWnd*pGwnd = (CGroupWnd*)pGroupWnd) {
			SetCXStr(&pGwnd->Tooltip, szMMainTip);
			if (pGwnd->GroupContextMenu)
			{
				pGwnd->GroupContextMenu->CRNormal = 0xFF000000;
#if !defined(ROF2EMU) && !defined(UFEMU)
				pGwnd->GroupContextMenu->DisabledBackground = 0xFF000000;
#endif
				pGwnd->GroupContextMenu->BGColor = 0xFF000000;
			}
			//AddOurMenu(pGwnd);
			GW_Gauge1 = (CGaugeWnd*)((CXWnd*)pGwnd)->GetChildItem("GW_Gauge1");
			GW_Gauge2 = (CGaugeWnd*)((CXWnd*)pGwnd)->GetChildItem("GW_Gauge2");
			GW_Gauge3 = (CGaugeWnd*)((CXWnd*)pGwnd)->GetChildItem("GW_Gauge3");
			GW_Gauge4 = (CGaugeWnd*)((CXWnd*)pGwnd)->GetChildItem("GW_Gauge4");
			GW_Gauge5 = (CGaugeWnd*)((CXWnd*)pGwnd)->GetChildItem("GW_Gauge5");

			//
			CControlTemplate *DistLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("Target_AggroPctSecondaryLabel");
			CControlTemplate *NavButtonTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("GW_InviteButton");//borrowing this...
			CControlTemplate *HBButtonTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("HB_Button1");
			//
			if (GW_Gauge1 && DistLabelTemplate) {

				SetCXStr(&DistLabelTemplate->Controller, "0");
					//create the distance label 1

				bool ther = CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel1, "Group_DistLabel1", GW_Gauge1->TopOffset, GW_Gauge1->BottomOffset, GW_Gauge1->RightOffset,gBShowDistance);
				ther = CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel2, "Group_DistLabel2", GW_Gauge2->TopOffset, GW_Gauge2->BottomOffset, GW_Gauge2->RightOffset,gBShowDistance);
				ther = CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel3, "Group_DistLabel3", GW_Gauge3->TopOffset, GW_Gauge3->BottomOffset, GW_Gauge3->RightOffset,gBShowDistance);
				ther = CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel4, "Group_DistLabel4", GW_Gauge4->TopOffset, GW_Gauge4->BottomOffset, GW_Gauge4->RightOffset,gBShowDistance);
				ther = CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel5, "Group_DistLabel5", GW_Gauge5->TopOffset, GW_Gauge5->BottomOffset, GW_Gauge5->RightOffset,gBShowDistance);
				//create Nav All to Me Button
				if (NavButtonTemplate)
				{
					CButtonWnd*Butt = (CButtonWnd*)((CXWnd*)pGwnd)->GetChildItem("GW_InviteButton");
					//Come To Me button
					int top = ReadSetting("ComeToMeTop", Butt->TopOffset + 39);
					int bottom = ReadSetting("ComeToMeBottom", Butt->BottomOffset + 26);
					int left = ReadSetting("ComeToMeLeft", 6);
					int right = ReadSetting("ComeToMeRight", 44);
					CreateAButton(pGwnd, NavButtonTemplate, &NavButton, "GW_NavButton", "NavButton", 1, top, bottom, left, right, 0xFF00FFFF, 0xFFFFFFFF, szNavToolTip, szNav,gBShowComeToMeButton);
					
					//Follow Me button
					top = ReadSetting("FollowMeTop", Butt->TopOffset + 39);
					bottom = ReadSetting("FollowMeBottom", Butt->BottomOffset + 26);
					left = ReadSetting("FollowMeLeft", 48);
					right = ReadSetting("FollowMeRight", 88);
					CreateAButton(pGwnd, NavButtonTemplate, &FollowMeButton, "GW_FollowMeButton", "FollowMeButton", 1, top, bottom, left, right, 0xFF00FFFF, 0xFFFFFFFF, szFollowMeToolTip, szFollowMe,gBShowFollowMeButton);
					
					//Mimic Me button
					top = ReadSetting("MimicMeTop", Butt->TopOffset + 77);
					bottom = ReadSetting("MimicMeBottom", Butt->BottomOffset + 64);
					left = ReadSetting("MimicMeLeft", 6);
					right = ReadSetting("MimicMeRight", 44);
					CreateAButton(pGwnd, NavButtonTemplate, &MimicMeButton, "GW_MimicMeButton", "MimicMeButton", 1, top, bottom, left, right, 0xFF00FFFF, 0xFFFFFFFF, szMimicMeToolTip, szMimicMe,gBShowMimicMeButton);
					//
					GroupHotButton = (CHotButton *)pSidlMgr->CreateHotButtonWnd((CXWnd*)pGwnd, HBButtonTemplate);
					GroupHotButton->BarIndex = 9;
					GroupHotButton->ButtonIndex = 0;
					GroupHotButton->SetButtonSize(100, true);
					GroupHotButton->bUseInLayoutVertical = true;
					//WSF_AUTOSTRETCHH		0x00400000
					//WSF_TRANSPARENT		0x00000400
					//WSF_AUTOSTRETCHV		0x00000100
					//WSF_RELATIVERECT	    0x00000080
					GroupHotButton->WindowStyle = 0x00400580;
					GroupHotButton->bClipToParent = true;
					GroupHotButton->bUseInLayoutHorizontal = true;
					//GroupHotButton->bResizableMask = 0;
					GroupHotButton->bLeftAnchoredToLeft = Butt->bLeftAnchoredToLeft;
					GroupHotButton->bRightAnchoredToLeft = Butt->bRightAnchoredToLeft;
					GroupHotButton->bTopAnchoredToTop = Butt->bTopAnchoredToTop;
					GroupHotButton->bBottomAnchoredToTop = Butt->bBottomAnchoredToTop;
					
					top = ReadSetting("HotButtonTop", Butt->TopOffset + 39);
					bottom = ReadSetting("HotButtonBottom", top-40);
					
					left = ReadSetting("HotButtonLeft", 92);
					right = ReadSetting("HotButtonRight", 132);
					GroupHotButton->TopOffset = top;
					GroupHotButton->BottomOffset = bottom;
					GroupHotButton->LeftOffset = left;
					GroupHotButton->RightOffset = right;

					GroupHotButton->CRNormal = 0xFF00FFFF;
					GroupHotButton->BGColor = 0xFFFFFFFF;
					GroupHotButton->dShow = gBShowHotButton;
					/*GroupHotButton->Location.bottom = 120;
					GroupHotButton->Location.left = 0;
					GroupHotButton->Location.right = 60;
					GroupHotButton->Location.top = 0;*/
					//
					//now set the template values back
					SetCXStr(&NavButtonTemplate->Name, "GW_InviteButton");
					SetCXStr(&NavButtonTemplate->ScreenID, "InviteButton");
					NavButtonTemplate->Font = 2;
				}
				//
				//now set the template values back
				SetCXStr(&DistLabelTemplate->Name, "Target_AggroPctSecondaryLabel");
				SetCXStr(&DistLabelTemplate->ScreenID, "Target_AggroPctSecondaryLabel");
				SetCXStr(&DistLabelTemplate->Controller, "308");
			}
		}
		//setup the targetinfo
		if (PCTARGETWND pTwnd = (PCTARGETWND)pTargetWnd) {
			//
			Target_AggroPctPlayerLabel = (CLabelWnd*)((CXWnd*)pTwnd)->GetChildItem("Target_AggroPctPlayerLabel");
			Target_AggroNameSecondaryLabel = (CLabelWnd*)((CXWnd*)pTwnd)->GetChildItem("Target_AggroNameSecondaryLabel");
			Target_AggroPctSecondaryLabel = (CLabelWnd*)((CXWnd*)pTwnd)->GetChildItem("Target_AggroPctSecondaryLabel");
			Target_BuffWindow = (CSidlScreenWnd*)((CXWnd*)pTwnd)->GetChildItem("Target_BuffWindow");

			CControlTemplate *DistLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("Target_AggroPctSecondaryLabel");
			CControlTemplate *CanSeeLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("Target_AggroNameSecondaryLabel");
			CControlTemplate *PHButtonTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("IDW_ModButton");//borrowing this...
			if (PHButtonTemplate && Target_BuffWindow && CanSeeLabelTemplate && Target_AggroNameSecondaryLabel && Target_AggroPctSecondaryLabel && Target_AggroPctPlayerLabel && DistLabelTemplate) {
				Target_BuffWindow->BGColor = 0xFF000000;
				Target_BuffWindow->TopOffset = Target_BuffWindow_TopOffset;
				Target_AggroPctPlayerLabel->BGColor = 0xFF00000;
				Target_AggroNameSecondaryLabel->BGColor = 0xFF00000;
				Target_AggroPctSecondaryLabel->BGColor = 0xFF00000;
				Target_AggroPctPlayerLabel->TopOffset = dTopOffset;
				Target_AggroPctPlayerLabel->BottomOffset = dBottomOffset;
				Target_AggroNameSecondaryLabel->TopOffset = dTopOffset;
				Target_AggroNameSecondaryLabel->BottomOffset = dBottomOffset;
				Target_AggroPctSecondaryLabel->TopOffset = dTopOffset;
				Target_AggroPctSecondaryLabel->BottomOffset = dBottomOffset;
				//CHAR szTemp[16];
				//sprintf_s(szTemp, "\xE2\x8C\x96");// , 0xE2, 0x8C, 0x96);

				SetCXStr(&DistLabelTemplate->Controller, "0");
				SetCXStr(&CanSeeLabelTemplate->Controller, "0");
				//create the info label
				SetCXStr(&DistLabelTemplate->Name, "Target_InfoLabel");
				SetCXStr(&DistLabelTemplate->ScreenID, "Target_InfoLabel");
				if (InfoLabel = (CLabelWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)pTwnd, DistLabelTemplate)) {
					InfoLabel->dShow = true;
					InfoLabel->bAlignCenter = false;
					InfoLabel->bAlignRight = false;
					InfoLabel->bLeftAnchoredToLeft = true;
					InfoLabel->TopOffset = 33;
					InfoLabel->BottomOffset = 47;
					InfoLabel->LeftOffset = 2;
					InfoLabel->RightOffset = 60;
					InfoLabel->CRNormal = 0xFF00FF00;//green
					InfoLabel->BGColor = 0xFFFFFFFF;
					SetCXStr(&InfoLabel->Tooltip, szTargetInfo);
				}
				//create the distance label
				SetCXStr(&DistLabelTemplate->Name, "Target_DistLabel");
				SetCXStr(&DistLabelTemplate->ScreenID, "Target_DistLabel");
				if (DistanceLabel = (CLabelWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)pTwnd, DistLabelTemplate)) {
					DistanceLabel->dShow = true;
					DistanceLabel->TopOffset = InfoTopOffset;
					DistanceLabel->BottomOffset = InfoBottomOffset;
					DistanceLabel->LeftOffset = dLeftOffset;
					DistanceLabel->RightOffset = 2;
					DistanceLabel->CRNormal = 0xFF00FF00;//green
					DistanceLabel->BGColor = 0xFFFFFFFF;
					SetCXStr(&DistanceLabel->Tooltip, szTargetDistance);
				}
				//create can see label
				SetCXStr(&CanSeeLabelTemplate->Name, "Target_CanSeeLabel");
				SetCXStr(&CanSeeLabelTemplate->ScreenID, "Target_CanSeeLabel");
				if (CanSeeLabel = (CLabelWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)pTwnd, CanSeeLabelTemplate)) {
					CanSeeLabel->dShow = true;
					CanSeeLabel->TopOffset = InfoTopOffset;
					CanSeeLabel->BottomOffset = InfoBottomOffset;
					CanSeeLabel->LeftOffset = dLeftOffset;
					CanSeeLabel->RightOffset = dLeftOffset;
					CanSeeLabel->CRNormal = 0xFF00FF00;//green
					CanSeeLabel->BGColor = 0xFFFFFFFF;
					SetCXStr(&CanSeeLabel->Tooltip, szCanSeeTarget);
				}
				//create PHButton
				PHButtonTemplate->Font = 0;
				if (PHButton = (CButtonWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)pTwnd, PHButtonTemplate)) {
					PHButton->dShow = true;
					PHButton->bBottomAnchoredToTop = Target_AggroPctPlayerLabel->bBottomAnchoredToTop;
					PHButton->bLeftAnchoredToLeft = Target_AggroPctPlayerLabel->bLeftAnchoredToLeft;
					PHButton->bRightAnchoredToLeft = Target_AggroPctPlayerLabel->bRightAnchoredToLeft;
					PHButton->bTopAnchoredToTop = Target_AggroPctPlayerLabel->bTopAnchoredToTop;
					PHButton->TopOffset = InfoTopOffset + 1;
					PHButton->BottomOffset = dTopOffset - 1;
					PHButton->LeftOffset = Target_AggroPctPlayerLabel->LeftOffset;
					PHButton->RightOffset = Target_AggroPctPlayerLabel->RightOffset;
					PHButton->Location.top = InfoTopOffset + 1;
					PHButton->Location.bottom = PHButton->BottomOffset;
					PHButton->Location.left = 2;
					PHButton->Location.right = 20;
					PHButton->CRNormal = 0xFF00FFFF;//cyan
					PHButton->BGColor = 0xFFFFFFFF;
					SetCXStr(&PHButton->Tooltip, szPHToolTip);
					SetCXStr(&PHButton->WindowText, szPH);
				}
				//
				//now set the template values back
				PHButtonTemplate->Font = 2;
				SetCXStr(&DistLabelTemplate->Name, "Target_AggroPctSecondaryLabel");
				SetCXStr(&DistLabelTemplate->ScreenID, "Target_AggroPctSecondaryLabel");
				SetCXStr(&DistLabelTemplate->Controller, "308");
				SetCXStr(&CanSeeLabelTemplate->Name, "Target_AggroNameSecondaryLabel");
				SetCXStr(&CanSeeLabelTemplate->ScreenID, "Target_AggroNameSecondaryLabel");
				SetCXStr(&CanSeeLabelTemplate->Controller, "304");
			}
		}
	}
}
void DoCommandf(PCHAR szFormat,...)
{
	va_list vaList;
	va_start(vaList, szFormat);
	int len = _vscprintf(szFormat, vaList) + 1;// _vscprintf doesn't count // terminating '\0'  
	if (char *szOutput = (char *)LocalAlloc(LPTR, len + 32)) {
		vsprintf_s(szOutput, len, szFormat, vaList);
		HideDoCommand((PSPAWNINFO)pLocalPlayer,szOutput,false);
		LocalFree(szOutput);
	}
}
int rightclickindex = -1;
void StopMovement(bool bChange = true)
{
	if (GetModuleHandle("mq2advpath"))
	{
		DoCommandf("/squelch /bcg //squelch /afollow off");
	}
	if (GetModuleHandle("mq2moveutils"))
	{
		DoCommandf("/squelch /bcg //squelch /stick off");
	}
	if (GetModuleHandle("mq2nav"))
	{
		DoCommandf("/squelch /bcg //squelch /nav stop");
	}
	if (bChange)
	{
		FollowMeButton->Checked = false;
		gbFollowme = false;
	}
}

class CGroupWnd2
{
public:
	void UpdateDisplay_Tramp(int, PSPAWNINFO, COLORREF, UINT);
	void UpdateDisplay_Detour(int Index, PSPAWNINFO groupmember, COLORREF NameColor, UINT RoleBits)
	{
		if (PCHARINFO pChar = GetCharInfo())
		{
			if (CGroupClient *group = (CGroupClient *)pChar->pGroupInfo)
			{
				int ind = rightclickindex;// group->GroupSelectID;
				if (Index == ind)
				{
					//NameColor = 0xFF0040FF;
				}
			}
		}
		/*if (NameColor == 0xFF00FF00)
		{
			NameColor = 0xFF0000FF;
		}*/
		return UpdateDisplay_Tramp(Index, groupmember, NameColor, RoleBits);
	}
	int CGroupWnd2::GetSelectedGroupIndex(CXWnd* pWnd)
	{
		CLabel* lab = (CLabel*)pWnd;
		int index = -1;
		if (PCHARINFO pChar = GetCharInfo())
		{
			if (CGroupClient *group = (CGroupClient *)pChar->pGroupInfo)
			{
				//index = group->GroupSelectID;
				for (int i = 1;i < 6; i++)
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
						|| lab == ((CGroupWnd*)this)->AggroPercLabel[i]
						)
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
	PSPAWNINFO GetSpawnFromRightClickIndex()
	{
		CHAR szMe[MAX_STRING] = { 0 };
		PSPAWNINFO pSpawn = 0;
		if (PCHARINFO pChar = GetCharInfo())
		{
			if (CGroupClient *group = (CGroupClient *)pChar->pGroupInfo)
			{
				int ind = rightclickindex;// group->GroupSelectID;
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
		if (CGroupWnd*pGwnd = (CGroupWnd*)this)
		{
			if (pGwnd->GroupContextMenu)
			{
				if (index != -1)
				{
					//WriteChatf("User Rightclicked group member number %d", index);
					AddOurMenu(pGwnd,true);
					return true;
				}
				AddOurMenu(pGwnd,false);
				return true;
				//RemoveOurMenu(pGwnd);
			}
		}
		return false;
	}
	int WndNotification_Trampoline(CXWnd*, unsigned __int32, void*);
	int WndNotification_Detour(CXWnd* pWnd, unsigned __int32 Message, void* pData)
	{
		if (Message==XWN_OUTPUT_TEXT)
		{
			if (pWnd && (pWnd->pParentWindow == (PCSIDLWND)GroupHotButton
				|| pWnd == (CXWnd*)GroupHotButton
				|| pWnd == (CXWnd*)NavButton
				|| pWnd == (CXWnd*)MimicMeButton
				|| pWnd == (CXWnd*)FollowMeButton))
			{
				//we dont want to show the menu here.
				pContextMenuManager->Flush();
			}
		}
		else if (Message == XWM_RCLICK || Message == XWM_RSELITEM_DOWN)
		{
			
			
			//return 1;
			if (pWnd && (pWnd->pParentWindow == (PCSIDLWND)GroupHotButton
				|| pWnd == (CXWnd*)GroupHotButton
				|| pWnd == (CXWnd*)NavButton
				|| pWnd == (CXWnd*)MimicMeButton
				|| pWnd == (CXWnd*)FollowMeButton))
			{
				//we dont want to show the menu here.
				pContextMenuManager->Flush();
				return 1;
			}
			rightclickindex = this->GetSelectedGroupIndex(pWnd);
			UpdateOurMenu(rightclickindex);
			//dont return here or group roles wont be filled in //return 1;
		}
		else if (Message == XWM_LCLICK)
		{

			if (pWnd == MimicMeButton)
			{
				gbMimicme ^= true;
				MimicMeButton->Checked = gbMimicme;
				return 1;
			}
			else if (pWnd == NavButton)
			{
				StopMovement();
				CHAR szMe[MAX_STRING] = { 0 };
				sprintf_s(szMe, "/bcg //nav id %d", ((PSPAWNINFO)pLocalPlayer)->SpawnID);
				DoCommand((PSPAWNINFO)pLocalPlayer, szMe);
				return 1;
			} else if (pWnd == FollowMeButton)
			{
				if(!FollowMeButton->Checked)
					StopMovement(false);
				gbFollowme ^= true;
				FollowMeButton->Checked = gbFollowme;
				CHAR szMe[MAX_STRING] = { 0 };
				if (gbFollowme)
				{
					if (GetModuleHandle("mq2advpath"))
					{
						sprintf_s(szMe, "/bcg //afollow spawn %d", ((PSPAWNINFO)pLocalPlayer)->SpawnID);
					}
					else if (GetModuleHandle("mq2moveutils"))
					{
						sprintf_s(szMe, "/bcg //stick id %d 5 uw", ((PSPAWNINFO)pLocalPlayer)->SpawnID);
					}
					else
					{
						WriteChatf("Please do /plugin mq2advpath or /plugin mq2moveutils.");
						StopMovement();
						return 1;
					}
				}
				else
				{
					WriteChatf("\ayMQ2TargetInfo\ax : Group stopped following you.");
					StopMovement();
					return 1;
				}
				WriteChatf("\ayMQ2TargetInfo\ax : Group now follow you around.");
				DoCommand((PSPAWNINFO)pLocalPlayer, szMe);
				return 1;
			}
		}
		else if (Message == XWM_MENUSELECT)
		{
			
			switch ((int)pData)
			{
				case 54://our nav menu id
				{
					PSPAWNINFO pSpawn = GetSpawnFromRightClickIndex();
					if (pSpawn)
					{
						StopMovement(gbFollowme);
						DoCommandf("/bct %s //nav id %d", pSpawn->Name, ((PSPAWNINFO)pLocalPlayer)->SpawnID);
					}
					return 1;//we dont need to call the tramp, its our message...
				}
				case 55://ground
				{
					PSPAWNINFO pSpawn = GetSpawnFromRightClickIndex();
					if (pSpawn)
					{
						DoCommandf("/bct %s //itemtarget", pSpawn->Name);
						DoCommandf("/bct %s //click left item", pSpawn->Name);
					}
					return 1;
				}
				case 56://door
				{
					PSPAWNINFO pSpawn = GetSpawnFromRightClickIndex();
					if (pSpawn)
					{
						DoCommandf("/bct %s //doortarget", pSpawn->Name);
						DoCommandf("/bct %s //click left door", pSpawn->Name);
					}
					return 1;
				}
				case 57://switchto
				{
					PSPAWNINFO pSpawn = GetSpawnFromRightClickIndex();
					if (pSpawn)
					{
						DoCommandf("/bct %s //foreground", pSpawn->Name);
					}
					return 1;
				}
				case 58://gBShowComeToMeButton
				{
					CContextMenu* pContextMenu = (CContextMenu*)pWnd;
					POINT pt;
					pt.x = ((PCXWNDMGR)pWndMgr)->MousePoint.x;
					pt.y = ((PCXWNDMGR)pWndMgr)->MousePoint.y;
					int iItemID = ((CListWnd*)pContextMenu)->GetItemAtPoint(&pt);
					gBShowComeToMeButton ^= true;
					pContextMenu->CheckMenuItem(iItemID,gBShowComeToMeButton);
					NavButton->dShow = gBShowComeToMeButton;
					if(gBShowComeToMeButton)
						WriteSetting("ShowComeToMeButton", "1");
					else
						WriteSetting("ShowComeToMeButton", "0");
					return 1;
				}
				case 59://gBShowMimicMeButton
				{
					CContextMenu* pContextMenu = (CContextMenu*)pWnd;
					POINT pt;
					pt.x = ((PCXWNDMGR)pWndMgr)->MousePoint.x;
					pt.y = ((PCXWNDMGR)pWndMgr)->MousePoint.y;
					int iItemID = ((CListWnd*)pContextMenu)->GetItemAtPoint(&pt);
					gBShowMimicMeButton ^= true;
					pContextMenu->CheckMenuItem(iItemID,gBShowMimicMeButton);
					MimicMeButton->dShow = gBShowMimicMeButton;
					if(gBShowMimicMeButton)
						WriteSetting("ShowMimicMeButton", "1");
					else
						WriteSetting("ShowMimicMeButton", "0");
					return 1;
				}
				case 60://gBShowFollowMeButton
				{
					CContextMenu* pContextMenu = (CContextMenu*)pWnd;
					POINT pt;
					pt.x = ((PCXWNDMGR)pWndMgr)->MousePoint.x;
					pt.y = ((PCXWNDMGR)pWndMgr)->MousePoint.y;
					int iItemID = ((CListWnd*)pContextMenu)->GetItemAtPoint(&pt);
					gBShowFollowMeButton ^= true;
					pContextMenu->CheckMenuItem(iItemID,gBShowFollowMeButton);
					FollowMeButton->dShow = gBShowFollowMeButton;
					if(gBShowFollowMeButton)
						WriteSetting("ShowFollowMeButton", "1");
					else
						WriteSetting("ShowFollowMeButton", "0");
					return 1;
				}
				case 61://gBShowHotButton
				{
					CContextMenu* pContextMenu = (CContextMenu*)pWnd;
					POINT pt;
					pt.x = ((PCXWNDMGR)pWndMgr)->MousePoint.x;
					pt.y = ((PCXWNDMGR)pWndMgr)->MousePoint.y;
					int iItemID = ((CListWnd*)pContextMenu)->GetItemAtPoint(&pt);
					gBShowHotButton ^= true;
					pContextMenu->CheckMenuItem(iItemID,gBShowHotButton);
					GroupHotButton->dShow = gBShowHotButton;
					if(gBShowHotButton)
						WriteSetting("ShowHotButton", "1");
					else
						WriteSetting("ShowHotButton", "0");
					return 1;
				}
				case 62://gBShowDistance
				{
					CContextMenu* pContextMenu = (CContextMenu*)pWnd;
					POINT pt;
					pt.x = ((PCXWNDMGR)pWndMgr)->MousePoint.x;
					pt.y = ((PCXWNDMGR)pWndMgr)->MousePoint.y;
					int iItemID = ((CListWnd*)pContextMenu)->GetItemAtPoint(&pt);
					gBShowDistance ^= true;
					pContextMenu->CheckMenuItem(iItemID,gBShowDistance);

					GroupDistLabel1->dShow = gBShowDistance;
					GroupDistLabel2->dShow = gBShowDistance;
					GroupDistLabel3->dShow = gBShowDistance;
					GroupDistLabel4->dShow = gBShowDistance;
					GroupDistLabel5->dShow = gBShowDistance;
					if(gBShowDistance)
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
		CHotButton* ret = (CHotButton*)CSidlManager_CreateHotButtonWnd_Tramp(pwndParent,pControl);
		
		Sleep(0);
		return (CXWnd*)ret;
	}
};
DETOUR_TRAMPOLINE_EMPTY(CXWnd* CGroupWnd2::CSidlManager_CreateHotButtonWnd_Tramp(CXWnd*, CControlTemplate*));
DETOUR_TRAMPOLINE_EMPTY(int CGroupWnd2::WndNotification_Trampoline(CXWnd*, unsigned __int32, void*));
DETOUR_TRAMPOLINE_EMPTY(void CGroupWnd2::UpdateDisplay_Tramp(int, PSPAWNINFO, COLORREF, UINT));

void CMD_GroupInfo(PSPAWNINFO pPlayer, char* szLine)
{
	CHAR szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	if (!_stricmp(szArg1, "help"))
	{
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide mimicme\ax\am(it's currently set to: %s)\ax.", MimicMeButton->dShow ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide distance\ax\am(it's currently set to: %s)\ax.", GroupDistLabel1->dShow ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide hot\ax\am(it's currently set to: %s)\ax.", GroupHotButton->dShow ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide followme\ax\am(it's currently set to: %s)\ax.", FollowMeButton->dShow ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide cometome\ax\am(it's currently set to: %s)\ax.", NavButton->dShow ? "\aoON" : "\agOFF");
		return;
	}
	else if (!_stricmp(szArg1, "show"))
	{
		CHAR szArg2[MAX_STRING] = { 0 };
		GetArg(szArg2, szLine, 2);
		if (!_stricmp(szArg2, "mimicme"))
		{
			MimicMeButton->dShow = true;
			gBShowMimicMeButton = true;
			WriteSetting("ShowMimicMeButton", "1");
		} 
		else if (!_stricmp(szArg2, "distance"))
		{
			gBShowDistance = true;
			GroupDistLabel1->dShow = true;
			GroupDistLabel2->dShow = true;
			GroupDistLabel3->dShow = true;
			GroupDistLabel4->dShow = true;
			GroupDistLabel5->dShow = true;
			WriteSetting("ShowDistance", "1");
		}
		else if (!_stricmp(szArg2, "hot"))
		{
			gBShowHotButton = true;
			GroupHotButton->dShow = true;
			WriteSetting("ShowHotButton", "1");
		}
		else if (!_stricmp(szArg2, "followme"))
		{
			gBShowFollowMeButton = true;
			FollowMeButton->dShow = true;
			WriteSetting("ShowFollowMeButton", "1");
		}
		else if (!_stricmp(szArg2, "cometome"))
		{
			gBShowComeToMeButton = true;
			NavButton->dShow = true;
			WriteSetting("ShowComeToMeButton", "1");
		}
	} else if (!_stricmp(szArg1, "hide"))
	{
		CHAR szArg2[MAX_STRING] = { 0 };
		GetArg(szArg2, szLine, 2);
		if (!_stricmp(szArg2, "mimicme"))
		{
			gBShowMimicMeButton = false;
			MimicMeButton->dShow = false;
			WriteSetting("ShowMimicMeButton", "0");
		}
		else if (!_stricmp(szArg2, "distance"))
		{
			gBShowDistance = false;
			GroupDistLabel1->dShow = false;
			GroupDistLabel2->dShow = false;
			GroupDistLabel3->dShow = false;
			GroupDistLabel4->dShow = false;
			GroupDistLabel5->dShow = false;
			WriteSetting("ShowDistance", "0");
		}
		else if (!_stricmp(szArg2, "hot"))
		{
			gBShowHotButton = false;
			GroupHotButton->dShow = false;
			WriteSetting("ShowHotButton", "0");
		}
		else if (!_stricmp(szArg2, "followme"))
		{
			gBShowFollowMeButton = false;
			FollowMeButton->dShow = false;
			WriteSetting("ShowFollowMeButton", "0");
		}
		else if (!_stricmp(szArg2, "cometome"))
		{
			gBShowComeToMeButton = false;
			NavButton->dShow = false;
			WriteSetting("ShowComeToMeButton", "0");
		}
	}

}

PLUGIN_API VOID InitializePlugin(VOID)
{
	if (!hLockphmap)
		hLockphmap = CreateMutex(NULL, FALSE, NULL);
	AddCommand("/groupinfo", CMD_GroupInfo);
	EzDetourwName(CSidlManager__CreateHotButtonWnd, &CGroupWnd2::CSidlManager_CreateHotButtonWnd_Detour, &CGroupWnd2::CSidlManager_CreateHotButtonWnd_Tramp, "CHB");
	EzDetourwName(CGroupWnd__UpdateDisplay, &CGroupWnd2::UpdateDisplay_Detour, &CGroupWnd2::UpdateDisplay_Tramp, "GUD");
	EzDetourwName(CGroupWnd__WndNotification, &CGroupWnd2::WndNotification_Detour, &CGroupWnd2::WndNotification_Trampoline, "GWW");
	HMODULE hMe = 0;
	CHAR szMyName[2048] = { 0 };
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)InitializePlugin, &hMe);
	void* pMyBinaryData = 0;
	GetModuleFileName(hMe, szMyName, 2048);
	if (char *pDest = strrchr(szMyName, '.')) {
		pDest[0] = '\0';
		strcat_s(szMyName, ".txt");
	}
	WIN32_FIND_DATA FindFile = { 0 };
	HANDLE hSearch = FindFirstFile(szMyName, &FindFile);
	if (hSearch == INVALID_HANDLE_VALUE) {
		//need to unpack our resource.
		
		if (HRSRC hRes = FindResource(hMe, MAKEINTRESOURCE(IDR_DB1), "DB")) {
			if (HGLOBAL bin = LoadResource(hMe, hRes)) {
				BOOL bResult = 0;
				if (pMyBinaryData = LockResource(bin)) {
					//save it...
					DWORD ressize = SizeofResource(hMe, hRes);
					FILE *File = 0;
					errno_t err = fopen_s(&File, szMyName, "wb");
					if (!err) {
						fwrite(pMyBinaryData, ressize, 1, File);
						fclose(File);
					}
					bResult = UnlockResource(hRes);
				}
				bResult = FreeResource(hRes);
			}
		}
		LoadPHs(szMyName);
	}
	else {
		FindClose(hSearch);
		LoadPHs(szMyName);
	}
	EzDetourwName(CTargetWnd__HandleBuffRemoveRequest, &MyCTargetWnd::HandleBuffRemoveRequest_Detour, &MyCTargetWnd::HandleBuffRemoveRequest_Tramp, "CTargetWnd__HandleBuffRemoveRequest");
	DebugSpewAlways("Initializing MQ2TargetInfo");
	Initialize();
}
void CleanUp(bool bUnload)
{
	if (CGroupWnd*pGwnd = (CGroupWnd*)pGroupWnd) {
		if (pGwnd->GroupContextMenu && separatorid)
		{
			RemoveOurMenu(pGwnd);
		}
	}
	if (GroupDistLabel1) {
		((CButtonWnd*)GroupDistLabel1)->Destroy();
		GroupDistLabel1 = 0;
	}
	if (GroupDistLabel2) {
		((CButtonWnd*)GroupDistLabel2)->Destroy();
		GroupDistLabel2 = 0;
	}
	if (GroupDistLabel3) {
		((CButtonWnd*)GroupDistLabel3)->Destroy();
		GroupDistLabel3 = 0;
	}
	if (GroupDistLabel4) {
		((CButtonWnd*)GroupDistLabel4)->Destroy();
		GroupDistLabel4 = 0;
	}
	if (GroupDistLabel5) {
		((CButtonWnd*)GroupDistLabel5)->Destroy();
		GroupDistLabel5 = 0;
	}
	if (InfoLabel) {
		((CButtonWnd*)InfoLabel)->Destroy();
		InfoLabel = 0;
	}
	if (DistanceLabel) {
		((CButtonWnd*)DistanceLabel)->Destroy();
		DistanceLabel = 0;
	}
	if (CanSeeLabel) {
		((CButtonWnd*)CanSeeLabel)->Destroy();
		CanSeeLabel = 0;
	}
	if (PHButton) {
		((CButtonWnd*)PHButton)->Destroy();
		PHButton = 0;
	}
	if (NavButton) {
		((CButtonWnd*)NavButton)->Destroy();
		NavButton = 0;
	}
	if (FollowMeButton) {
		((CButtonWnd*)FollowMeButton)->Destroy();
		FollowMeButton = 0;
	}
	if (MimicMeButton) {
		((CButtonWnd*)MimicMeButton)->Destroy();
		MimicMeButton = 0;
	}
	if (GroupHotButton) {
		((CXWnd*)GroupHotButton)->Destroy();
		GroupHotButton = 0;
	}
	
	if (GetGameState() == GAMESTATE_INGAME) {
		if (bUnload) {
			if (!IsBadReadPtr(Target_BuffWindow, 4)) {
				Target_BuffWindow->TopOffset = 50;
			}

			if (!IsBadReadPtr(Target_AggroPctPlayerLabel, 4)) {
				Target_AggroPctPlayerLabel->TopOffset = 33;
				Target_AggroPctPlayerLabel->BottomOffset = 47;
			}
			if (!IsBadReadPtr(Target_AggroNameSecondaryLabel, 4)) {
				Target_AggroNameSecondaryLabel->TopOffset = 33;
				Target_AggroNameSecondaryLabel->BottomOffset = 47;
			}
			if (!IsBadReadPtr(Target_AggroPctSecondaryLabel, 4)) {
				Target_AggroPctSecondaryLabel->TopOffset = 33;
				Target_AggroPctSecondaryLabel->BottomOffset = 47;
			}
		}
	}
}
// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2TargetInfo");
	if(CTargetWnd__HandleBuffRemoveRequest)
		RemoveDetour(CTargetWnd__HandleBuffRemoveRequest);
	CleanUp(true);
	if (hLockphmap) {
		ReleaseMutex(hLockphmap);
		CloseHandle(hLockphmap);
		hLockphmap = 0;
	}
	RemoveCommand("/groupinfo");
	RemoveDetour(CGroupWnd__WndNotification);
	RemoveDetour(CGroupWnd__UpdateDisplay);
	RemoveDetour(CSidlManager__CreateHotButtonWnd);
	
}

// Called after entering a new zone
PLUGIN_API VOID OnZoned(VOID)
{
	DebugSpewAlways("MQ2TargetInfo::OnZoned()");
}

// Called once directly before shutdown of the new ui system, and also
// every time the game calls CDisplay::CleanGameUI()
PLUGIN_API VOID OnCleanUI(VOID)
{
	DebugSpewAlways("MQ2TargetInfo::OnCleanUI()");
	// destroy custom windows, etc
	CleanUp(false);
}

bool IsPlaceHolder(PSPAWNINFO pSpawn)
{
	lockit lk(hLockphmap,"IsPlaceHolder");
	if (pSpawn && phmap.find(pSpawn->DisplayedName) != phmap.end()) {
		return true;
	}
	return false;
}
bool GetPhMap(PSPAWNINFO pSpawn, phinfo *pinf)
{
	lockit lk(hLockphmap,"IsPlaceHolder");
	if (pSpawn && phmap.find(pSpawn->DisplayedName) != phmap.end()) {
		*pinf = phmap[pSpawn->DisplayedName];
		return true;
	}
	return false;
}
// This is called every time MQ pulses
CHAR szTargetDist[64] = { 0 };
int looper = 0;
PSPAWNINFO oldspawn = 0;
void UpdateGroupDist(PCHARINFO pChar, int index)
{
	CLabelWnd *pWnd = 0;
	switch (index)
	{
	case 1:
		pWnd = GroupDistLabel1;
		break;
	case 2:
		pWnd = GroupDistLabel2;
		break;
	case 3:
		pWnd = GroupDistLabel3;
		break;
	case 4:
		pWnd = GroupDistLabel4;
		break;
	case 5:
		pWnd = GroupDistLabel5;
		break;
	};
	if (pWnd)
	{
		if (pChar->pGroupInfo->pMember[index] && pChar->pGroupInfo->pMember[index]->pSpawn)
		{
			float dist = Distance3DToSpawn(pLocalPlayer, pChar->pGroupInfo->pMember[index]->pSpawn);
			sprintf_s(szTargetDist, "Dist: %.2f", dist);
			if (dist < 250) {
				pWnd->CRNormal = 0xFF00FF00;//green
			}
			else {
				pWnd->CRNormal = 0xFFFF0000;//red
			}
			SetCXStr(&pWnd->WindowText, szTargetDist);
			pWnd->dShow = true;
		}
		else
		{
			pWnd->dShow = false;
		}
	}
}

DWORD LastTargetID = 0;
void DidTargetChange()
{
	if (pTarget && ((PSPAWNINFO)pTarget)->SpawnID != LastTargetID)
	{
		//yes it changed
		LastTargetID = ((PSPAWNINFO)pTarget)->SpawnID;
		//DoCommandf((PSPAWNINFO)pLocalPlayer, "/squelch /bcg //target id %d",LastTargetID);
		DoCommandf("/bcg //target id %d",LastTargetID);
		WriteChatf("Letting group know target changed");
	}
}
void MimicMeFunc()
{
	PSPAWNINFO pSpawn = (PSPAWNINFO)pLocalPlayer;
	DidTargetChange();

	if (pSpawn->AssistName[0])
	{
		pSpawn->GroupAssistNPC;
		Sleep(0);
	}
	Sleep(0);
}
PLUGIN_API DWORD OnIncomingChat(PCHAR Line, DWORD Color)
{
	if (gbMimicme)
	{
		int linelen = strlen(Line);
		PCHAR szLine = (PCHAR)LocalAlloc(LPTR, linelen + 32);
		PCHAR szLineOrg = szLine;
		strcpy_s(szLine, linelen + 32, Line);
		if (!_strnicmp(szLine, "You say, '",10))
		{
			szLine += 10;
			if (char*pDest = strrchr(szLine, '\''))
			{
				pDest[0] = '\0';
			}
			DoCommandf("/bcg //say %s", szLine);
		}
		LocalFree(szLineOrg);
		OutputDebugString("OnIncomingChat: ");
		OutputDebugString(Line);
		OutputDebugString("\n");
	}
	return 0;
}
PLUGIN_API DWORD OnWriteChatColor(PCHAR Line, DWORD Color, DWORD Filter)
{
	if (gbMimicme)
	{
		//MQ2EasyFind: Going to (Group) -> Annera
		int linelen = strlen(Line);
		PCHAR szLine = (PCHAR)LocalAlloc(LPTR, linelen + 32);
		PCHAR szLineOrg = szLine;
		strcpy_s(szLine, linelen + 32, Line);
		if (!_strnicmp(szLine, "MQ2EasyFind: Going to ",22))
		{
			//szLine += 22;
			if (char*pDest = strstr(szLine, "-> "))
			{
				szLine = pDest;
				szLine += 3;
			}
			if (char*pDest = strchr(szLine, '('))
			{
				pDest--;
				pDest[0] = '\0';
				
			}
			StopMovement();
			DoCommandf("/bcg //easyfind \"%s\"", szLine);
		}
		LocalFree(szLineOrg);
		OutputDebugString("OnWriteChatColor: ");
		OutputDebugString(Line);
		OutputDebugString("\n");
	}
	return 0;
}
PLUGIN_API VOID OnPulse(VOID)
{
	// DONT leave in this debugspew, even if you leave in all the others
	//DebugSpewAlways("MQ2TargetInfo::OnPulse()");
	looper++;
	if (looper > 40) {
		looper = 0;
		if (GetGameState() == GAMESTATE_INGAME) {
			Initialize();
			//
			if (gbMimicme)
			{
				MimicMeFunc();
			}
			//
			if (CGroupWnd *pGwnd = (CGroupWnd*)pGroupWnd) {
				if (pContextMenuManager->NumVisibleMenus==0 && separatorid)
				{
					RemoveOurMenu(pGwnd);
				}
				if (PCHARINFO pChar = GetCharInfo())
				{
					if (pChar->pGroupInfo)
					{
						if (gBShowDistance && GroupDistLabel1 && GroupDistLabel2 && GroupDistLabel3 && GroupDistLabel4 && GroupDistLabel5)
						{
							UpdateGroupDist(pChar, 1);
							UpdateGroupDist(pChar, 2);
							UpdateGroupDist(pChar, 3);
							UpdateGroupDist(pChar, 4);
							UpdateGroupDist(pChar, 5);
						}
						  
						if(gBShowMimicMeButton && MimicMeButton && MimicMeButton->dShow==false)
							MimicMeButton->dShow = true;
						if(gBShowFollowMeButton && FollowMeButton && FollowMeButton->dShow==false)
							FollowMeButton->dShow = true;
						if(gBShowComeToMeButton && NavButton && NavButton->dShow==false)
							NavButton->dShow = true;
						//if(gBShowHotButton && GroupHotButton && GroupHotButton->dShow==false)
						//	GroupHotButton->dShow = true;
					}
					else {
						if (GroupDistLabel1 && GroupDistLabel2 && GroupDistLabel3 && GroupDistLabel4 && GroupDistLabel5 && GroupDistLabel1->dShow)
						{
							GroupDistLabel1->dShow = false;
							GroupDistLabel2->dShow = false;
							GroupDistLabel3->dShow = false;
							GroupDistLabel4->dShow = false;
							GroupDistLabel5->dShow = false;
						}
						if(MimicMeButton && MimicMeButton->dShow==true)
							MimicMeButton->dShow = false;
						if(FollowMeButton && FollowMeButton->dShow==true)
							FollowMeButton->dShow = false;
						if(NavButton && NavButton->dShow==true)
							NavButton->dShow = false;
						//if(GroupHotButton && GroupHotButton->dShow==true)
						//	GroupHotButton->dShow = false;
					}
				}
			}
			if (PCTARGETWND pTwnd = (PCTARGETWND)pTargetWnd) {
				if (InfoLabel && DistanceLabel && CanSeeLabel && PHButton) {
					if (pTarget && pCharSpawn) {
						if (oldspawn != (PSPAWNINFO)pTarget) {
							oldspawn = (PSPAWNINFO)pTarget;
							phinfo pinf;
							if (GetPhMap((PSPAWNINFO)pTarget, &pinf)) {
								SetCXStr(&PHButton->Tooltip, (char*)pinf.Named.c_str());
								PHButton->dShow = true;
							}
							else {
								PHButton->dShow = false;
							}
						}
						//set info
						PSPAWNINFO pInfo = (PSPAWNINFO)pTarget;
						switch (pInfo->Anon)
						{
						case 1:
							sprintf_s(szTargetDist, "Anonymous");
							break;
						case 2:
							sprintf_s(szTargetDist, "Roleplaying");
							break;
						default:
							sprintf_s(szTargetDist, "Lvl: %d %s %s", pInfo->Level, pEverQuest->GetRaceDesc(pInfo->mActorClient.Race), GetClassDesc(pInfo->mActorClient.Class));
							break;
						}
						SetCXStr(&InfoLabel->WindowText, szTargetDist);
						//then distance
						float dist = Distance3DToSpawn(pLocalPlayer, pTarget);
						sprintf_s(szTargetDist, "Dist: %.2f", dist);
						if (dist < 250) {
							DistanceLabel->CRNormal = 0xFF00FF00;//green
						}
						else {
							DistanceLabel->CRNormal = 0xFFFF0000;//red
						}
						SetCXStr(&DistanceLabel->WindowText, szTargetDist);
						//now do can see
						bool cansee = pCharSpawn->CanSee((EQPlayer*)pTarget);
						sprintf_s(szTargetDist, "%s", cansee ? "O" : "X");
						if (cansee) {
							CanSeeLabel->CRNormal = 0xFF00FF00;//green
						}
						else {
							CanSeeLabel->CRNormal = 0xFFFF0000;//red
						}
						SetCXStr(&CanSeeLabel->WindowText, szTargetDist);
					}
					else {
						SetCXStr(&InfoLabel->WindowText, "");
						SetCXStr(&DistanceLabel->WindowText, "");
						SetCXStr(&CanSeeLabel->WindowText, "");
						PHButton->dShow = false;
					}
				}
			}
		}
	}
}