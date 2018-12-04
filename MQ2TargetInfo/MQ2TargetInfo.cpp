// MQ2TargetInfo.cpp : Defines the entry point for the DLL application.
// by EqMule 2018

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.

#include "../MQ2Plugin.h"
#include "resource.h"

PreSetup("MQ2TargetInfo");
PLUGIN_VERSION(2.0);

bool bDisablePluginDueToBadUI = false;
CHAR szTargetInfo[128] = { "Target Info" };
CHAR szTargetDistance[128] = { "Target Distance" };
CHAR szGroupDistance[128] = { "Member Distance" };
CHAR szCanSeeTarget[128] = { "Can See Target" };
CHAR szPHToolTip[128] = { "Target is a Place Holder" };
CHAR szPH[128] = { "PH" };
CHAR szNavToolTip[MAX_STRING] = { 0 };
CHAR szNavCommand[MAX_STRING] = { 0 };
CHAR szNav[128] = { 0 };
CHAR szFollowMeToolTip[MAX_STRING] = { 0 };
CHAR szFollowMe[128] = { 0 };
CHAR szFollowMeCommand[MAX_STRING] = { 0 };
CHAR szMimicMeToolTip[128] = { "Everyone do what I do, I target something, they do as well, I hail, they hail, etc." };
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

CHotButton*GroupHotButton[3] = { 0 };

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
void CleanUp(bool bUnload);
std::map<DWORD, bool>FollowMeMap;
void ResetIni()
{
	CopyFile(INIFileName, "MQ2TargetInfo.bak", FALSE);
	DeleteFile(INIFileName);
	HMODULE hMe = 0;
	CHAR szMyIniName[2048] = { 0 };
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)ResetIni, &hMe);
	void* pMyBinaryData = 0;
	GetModuleFileName(hMe, szMyIniName, 2048);
	if (char *pDest = strrchr(szMyIniName, '.')) {
		pDest[0] = '\0';
		strcat_s(szMyIniName, ".ini");
	}
	if (HRSRC hRes = FindResource(hMe, MAKEINTRESOURCE(IDR_INI1), "INI")) {
		if (HGLOBAL bin = LoadResource(hMe, hRes)) {
			BOOL bResult = 0;
			if (pMyBinaryData = LockResource(bin)) {
				//save it...
				DWORD ressize = SizeofResource(hMe, hRes);
				FILE *File = 0;
				errno_t err = fopen_s(&File, szMyIniName, "wb");
				if (!err) {
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

CGaugeWnd *ETW_Gauge[23] = { 0 };
CLabelWnd *ETW_DistLabel[23] = { 0 };
#define WSF_AUTOSTRETCHH	0x00400000
#define WSF_CLIENTMOVABLE	0x00200000
#define WSF_NOHITTEST		0x00008000
#define WSF_USEMYALPHA		0x00000800
#define WSF_TRANSPARENT		0x00000400
#define WSF_SIZABLE			0x00000200
#define WSF_AUTOSTRETCHV	0x00000100
#define WSF_RELATIVERECT	0x00000080
#define WSF_BORDER			0x00000040
#define WSF_TITLEBAR		0x00000004

DWORD orgwstyle = 0;
DWORD orgTargetWindStyle = 0;
DWORD orgExtTargetWindStyle = 0;
//RECT orgloc = { 0,0,0,0 };
//RECT orglocation = { 0,0,0,0 };

bool CreateDistLabel(CGroupWnd *pGwnd, CControlTemplate *DistLabelTemplate, CLabelWnd **labelwnd, char *label, int font, int top, int bottom,int left,int right, bool bAlignRight, bool bShow)
{
	SetCXStr(&DistLabelTemplate->Name, label);
	SetCXStr(&DistLabelTemplate->ScreenID, label);
	int oldfont = DistLabelTemplate->Font;
	DWORD oldstyle = DistLabelTemplate->StyleBits;


	bool bRelativePositionOld = DistLabelTemplate->bRelativePosition;
	bool bAutoStretchVerticalOld = DistLabelTemplate->bAutoStretchVertical;
	bool bAutoStretchHorizontalOld = DistLabelTemplate->bAutoStretchHorizontal;
	bool bRightAnchorToLeftOld = DistLabelTemplate->bRightAnchorToLeft;
/*/new stuff
	DistLabelTemplate->bRelativePosition = true;
	DistLabelTemplate->bAutoStretchVertical = true;
	DistLabelTemplate->bAutoStretchHorizontal = true;
	DistLabelTemplate->bRightAnchorToLeft = false;
//*/
	DistLabelTemplate->Font = font;
	DistLabelTemplate->StyleBits = WSF_AUTOSTRETCHH|WSF_AUTOSTRETCHV|WSF_RELATIVERECT;
	if (*labelwnd = (CLabelWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)pGwnd, DistLabelTemplate)) {
/*new stuff
		(*labelwnd)->Location.bottom = 0;
		(*labelwnd)->Location.left = 0;
		(*labelwnd)->Location.right = 0;
		(*labelwnd)->Location.top = 0;
*/
		(*labelwnd)->TopOffset = top;
		(*labelwnd)->BottomOffset = bottom;
		(*labelwnd)->LeftOffset = left;
		(*labelwnd)->RightOffset = right;
		(*labelwnd)->CRNormal = 0xFF00FF00;//green
		(*labelwnd)->BGColor = 0xFFFFFFFF;
		SetCXStr(&(*labelwnd)->Tooltip, szGroupDistance);
		(*labelwnd)->dShow = bShow;
		(*labelwnd)->bNoWrap = true;
		(*labelwnd)->bLeftAnchoredToLeft = true;
		(*labelwnd)->bRightAnchoredToLeft;
		(*labelwnd)->WindowStyle;
/*new stuff
		(*labelwnd)->bNoWrap = true;
		(*labelwnd)->bLeftAnchoredToLeft = true;
		(*labelwnd)->bRightAnchoredToLeft = false;
		(*labelwnd)->WindowStyle = WSF_AUTOSTRETCHH | WSF_TRANSPARENT | WSF_AUTOSTRETCHV | WSF_RELATIVERECT;// 0x00400580;
*/
		DistLabelTemplate->bRightAnchorToLeft = bRightAnchorToLeftOld;
		DistLabelTemplate->bRelativePosition = bRelativePositionOld;
		DistLabelTemplate->bAutoStretchVertical = bAutoStretchVerticalOld;
		DistLabelTemplate->bAutoStretchHorizontal = bAutoStretchHorizontalOld;
		(*labelwnd)->bAlignRight = bAlignRight;
		(*labelwnd)->bAlignCenter = false;
		DistLabelTemplate->Font = oldfont;
		DistLabelTemplate->StyleBits = oldstyle;
		return true;
	}
	DistLabelTemplate->bRelativePosition = bRelativePositionOld;
	DistLabelTemplate->bAutoStretchVertical = bAutoStretchVerticalOld;
	DistLabelTemplate->bAutoStretchHorizontal = bAutoStretchHorizontalOld;
	DistLabelTemplate->StyleBits = oldstyle;
	DistLabelTemplate->Font = oldfont;
	return false;
}
int navmenuid = 0;
int separatorid = 0;
int separatorid2 = 0;
int groundmenuid = 0;
int doormenuid = 0;
int switchtomenuid = 0;
int followmenuid = 0;

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
bool gBShowHotButtons = TRUE;
bool gBShowDistance = TRUE;
bool gBShowExtDistance = TRUE;

void CreateGroupHotButton(CGroupWnd*pGwnd, CControlTemplate *Template, CHotButton **button, int top, int bottom, int left, int right, int buttonindex)
{
	(*button) = (CHotButton *)pSidlMgr->CreateHotButtonWnd((CXWnd*)pGwnd, Template);
	(*button)->BarIndex = 9;
	(*button)->ButtonIndex = buttonindex;
	(*button)->SetButtonSize(100, true);
	(*button)->bUseInLayoutVertical = true;
					
	(*button)->WindowStyle = WSF_AUTOSTRETCHH|WSF_TRANSPARENT|WSF_AUTOSTRETCHV|WSF_RELATIVERECT;
	(*button)->bClipToParent = true;
	(*button)->bUseInLayoutHorizontal = true;
	(*button)->bLeftAnchoredToLeft = true;
	(*button)->bRightAnchoredToLeft = true;
	(*button)->bTopAnchoredToTop = false;
	(*button)->bBottomAnchoredToTop = false;
					
	(*button)->TopOffset = top;
	(*button)->BottomOffset = bottom;
	(*button)->LeftOffset = left;
	(*button)->RightOffset = right;

	(*button)->CRNormal = 0xFF00FFFF;
	(*button)->BGColor = 0xFFFFFFFF;
	(*button)->dShow = gBShowHotButtons;
}

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
			pGwnd->GroupContextMenu->RemoveMenuItem(followmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(switchtomenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(doormenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(groundmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(navmenuid);
			pGwnd->GroupContextMenu->RemoveMenuItem(separatorid2);
			followmenuid = 0;
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
void AddOurMenu(CGroupWnd*pGwnd,bool bMemberClicked, int index)
{
	//if (pGwnd->GroupContextMenu && (!distanceoptionmenuid || bMemberClicked))
	if (pGwnd->GroupContextMenu)
	{
		RemoveOurMenu(pGwnd);
		separatorid = pGwnd->GroupContextMenu->AddSeparator();
		cometomeoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Come to Me Button", 59, gBShowComeToMeButton);
		mimicmeoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Mimic Me Button", 60, gBShowMimicMeButton);
		followmeoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Follow Button", 61, gBShowFollowMeButton);
		hotoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Hot Buttons", 62, gBShowHotButtons);
		distanceoptionmenuid = pGwnd->GroupContextMenu->AddMenuItem("Show Distance", 63, gBShowDistance);

		//
		if (bMemberClicked)
		{
			separatorid2 = pGwnd->GroupContextMenu->AddSeparator();
			navmenuid = pGwnd->GroupContextMenu->AddMenuItem("Nav to Me", 54);
			groundmenuid = pGwnd->GroupContextMenu->AddMenuItem("Pick Up Nearest Ground Item", 55);
			doormenuid = pGwnd->GroupContextMenu->AddMenuItem("Click Nearest Door", 56);
			switchtomenuid = pGwnd->GroupContextMenu->AddMenuItem("Switch to...", 57);
			if (FollowMeMap.find(index) != FollowMeMap.end())
			{
				if (FollowMeMap[index] == true)
				{
					followmenuid = pGwnd->GroupContextMenu->AddMenuItem("Stop Following Me", 58);
				}
				else
				{
					followmenuid = pGwnd->GroupContextMenu->AddMenuItem("Follow Me", 58);
				}
			}
			else
			{
				followmenuid = pGwnd->GroupContextMenu->AddMenuItem("Follow Me", 58);
			}
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
void WriteUIStringSetting(const char*Key, const char*value)
{
	CHAR szSettingINISection[MAX_STRING] = { 0 };
	CHAR szUI[MAX_STRING] = { 0 };
	CHAR szFilename[MAX_STRING] = { 0 };
	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0')
	{
		return;//better not mess with this if we are not ingame...
	}
	else
	{
		sprintf_s(szFilename, "%s\\UI_%s_%s.ini", gszEQPath, ((PSPAWNINFO)pLocalPlayer)->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "Unknown", szUI, MAX_STRING, szFilename);
		sprintf_s(szSettingINISection, "UI_%s", szUI);
	}
	WritePrivateProfileString(szSettingINISection, Key, value, INIFileName);
	int ival = atoi(value);
	WriteChatf("\ayMQ2TargetInfo\ax::\am%s is now %s\ax.",Key, ival ? "\aoON" : "\agOFF");
}
template <unsigned int _Size>LPSTR ReadUIStringSetting(char*Key,char *defaultval,char(&_Out)[_Size])
{
	CHAR szSettingINISection[MAX_STRING] = { 0 };
	CHAR szUI[MAX_STRING] = { 0 };
	CHAR szFilename[MAX_STRING] = { 0 };
			
	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0')
	{
		strcpy_s(_Out, _Size, defaultval);
		return _Out;//better not mess with this if we are not ingame...
	}
	else
	{
		sprintf_s(szFilename, "%s\\UI_%s_%s.ini", gszEQPath, ((PSPAWNINFO)pLocalPlayer)->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "Unknown", szUI, MAX_STRING, szFilename);
		sprintf_s(szSettingINISection, "UI_%s", szUI);
	}
	int ret = GetPrivateProfileString(szSettingINISection, Key, "",_Out,_Size, INIFileName);
	if (_Out[0] == '\0')
	{
		if (!_stricmp(Key, "DynamicUI"))
		{
			//first time they are running this version, reset all their stuff.
			WritePrivateProfileString(szSettingINISection, "GroupWindowLoc",NULL, INIFileName);
			WritePrivateProfileString(szSettingINISection, "TargetInfoLoc",NULL, INIFileName);
			WritePrivateProfileString(szSettingINISection, "TargetDistanceLoc",NULL, INIFileName);
			WritePrivateProfileString(szSettingINISection, "ExtDistanceLoc", NULL, INIFileName);
			WritePrivateProfileString(szSettingINISection, "GroupDistanceLoc", NULL, INIFileName);
		}
		WritePrivateProfileString(szSettingINISection, Key,defaultval, INIFileName);
		strcpy_s(_Out, _Size, defaultval);
	}
	return _Out;
}

bool ReadUILocSetting(char*Key,int top, int bottom, int left, int right,RECT *RCOut)
{
	CHAR szSettingINISection[MAX_STRING] = { 0 };
	CHAR szUI[MAX_STRING] = { 0 };
	CHAR szFilename[MAX_STRING] = { 0 };
			
	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0')
	{
		(*RCOut).top = top;
		(*RCOut).bottom = bottom;
		(*RCOut).left = left;
		(*RCOut).right = right;
		return false;
	}
	else
	{
		sprintf_s(szFilename, "%s\\UI_%s_%s.ini", gszEQPath, ((PSPAWNINFO)pLocalPlayer)->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "Unknown", szUI, MAX_STRING, szFilename);
		sprintf_s(szSettingINISection, "UI_%s", szUI);
	}
	sprintf_s(szUI,"%d,%d,%d,%d", top, bottom, left, right);
	int ret = GetPrivateProfileString(szSettingINISection, Key, "",szFilename,MAX_STRING, INIFileName);
	if (szFilename[0] == '\0')
	{
		WritePrivateProfileString(szSettingINISection, Key,szUI, INIFileName);
		(*RCOut).top = top;
		(*RCOut).bottom = bottom;
		(*RCOut).left = left;
		(*RCOut).right = right;
		return false;
	}
	char *token1 = NULL;
	char *next_token1 = NULL;
	CHAR szLocs[4][8];
	token1 = strtok_s(szFilename, ",", &next_token1);
	int j = 0;
	while (token1 != NULL)
	{
		if (token1 != NULL)
		{
			strcpy_s(szLocs[j], token1);
			token1 = strtok_s(NULL, ",", &next_token1);
			j++;
		}
	}
	(*RCOut).top = atoi(szLocs[0]);
	(*RCOut).bottom = atoi(szLocs[1]);
	(*RCOut).left = atoi(szLocs[2]);
	(*RCOut).right = atoi(szLocs[3]);
	return true;
}
template <unsigned int _Size>LPSTR ReadStringSetting(char*Key,char *defaultval,char(&_Out)[_Size])
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
	int ret = GetPrivateProfileString(szSettingINISection, Key, "",_Out,_Size, INIFileName);
	if (_Out[0] == '\0')
	{
		WritePrivateProfileString(szSettingINISection, Key,defaultval, INIFileName);
		strcpy_s(_Out, _Size, defaultval);
	}
	return _Out;
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
		} else if (!_stricmp(Key, "MimicMeTop"))
		{
			if (ret == 102)
			{
				WriteChatf("MQ2TargetInfo.ini changed: Setting MimicMeTop to %d because it was 102 and that is no longer the default.",defaultval);
				CHAR szTemp[MAX_STRING] = { 0 };
				WritePrivateProfileString(szSettingINISection, Key, SafeItoa(64,szTemp,10), INIFileName);
				WritePrivateProfileString(szSettingINISection, "MimicMeBottom", SafeItoa(31,szTemp,10), INIFileName);
				WritePrivateProfileString(szSettingINISection, "MimicMeLeft", SafeItoa(92,szTemp,10), INIFileName);
				WritePrivateProfileString(szSettingINISection, "MimicMeRight", SafeItoa(132,szTemp,10), INIFileName);
				return defaultval;
			}
		}
	}
	return ret;
}
void ReadIniSettings()
{
	CHAR szSettingINISection[MAX_STRING] = { 0 };
	CHAR szVersion[MAX_STRING] = { 0 };
	int ret = GetPrivateProfileString("Default", "PluginVersion", "",szVersion,MAX_STRING, INIFileName);
	if (szVersion[0] == '\0')
	{
		ResetIni();
		CHAR szTemp[MAX_STRING] = { 0 };
		sprintf_s(szTemp, "%.1f", MQ2Version);
		WritePrivateProfileString("Default", "PluginVersion", szTemp, INIFileName);
	}
	else {
		CHAR szTemp[MAX_STRING] = { 0 };
		sprintf_s(szTemp, "%.1f", MQ2Version);
		//they match do nothing
		if (_stricmp(szTemp, szVersion))
		{
			//they dont match update ini.
			ResetIni();
		}
	}
	ret = GetPrivateProfileInt("Default", "UsePerCharSettings", -1, INIFileName);
	gBUsePerCharSettings = (ret == 0 ? FALSE : TRUE);
	if (ret == -1)
	{
		gBUsePerCharSettings = 0;
		WritePrivateProfileString("Default", "UsePerCharSettings", "0", INIFileName);
	}

	if (!pLocalPlayer || EQADDR_SERVERNAME[0] == '\0' || gBUsePerCharSettings == FALSE)
	{
		strcpy_s(szSettingINISection, "Default");
	}
	else
	{
		sprintf_s(szSettingINISection, "%s_%s", EQADDR_SERVERNAME, ((PSPAWNINFO)pLocalPlayer)->Name);
	}
		//cleanup old crap
	WritePrivateProfileString(szSettingINISection, "ComeToMeTop", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "ComeToMeBottom", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "ComeToMeLeft", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "ComeToMeRight", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "FollowMeTop", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "FollowMeBottom", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "FollowMeLeft", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "FollowMeRight", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "MimicMeTop", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "MimicMeBottom", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "MimicMeLeft", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "MimicMeRight", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton0Top", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton0Bottom", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton0Left", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton0Right", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton1Top", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton1Bottom", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton1Left", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton1Right", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton2Top", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton2Bottom", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton2Left", NULL, INIFileName);
	WritePrivateProfileString(szSettingINISection, "HotButton2Right", NULL, INIFileName);

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
	ret = GetPrivateProfileInt(szSettingINISection, "ShowHotButtons", -1, INIFileName);
	gBShowHotButtons = (ret == 0 ? FALSE : TRUE);
	if (ret == -1)
	{
		ret = GetPrivateProfileInt(szSettingINISection, "ShowHotButton", -1, INIFileName);

		WritePrivateProfileString(szSettingINISection, "HotButtonTop", NULL, INIFileName);
		WritePrivateProfileString(szSettingINISection, "HotButtonBottom", NULL, INIFileName);
		WritePrivateProfileString(szSettingINISection, "HotButtonLeft", NULL, INIFileName);
		WritePrivateProfileString(szSettingINISection, "HotButtonRight", NULL, INIFileName);
		WritePrivateProfileString(szSettingINISection, "ShowHotButton", NULL, INIFileName);
		if (ret == 0)
		{
			WritePrivateProfileString(szSettingINISection, "ShowHotButtons", "0", INIFileName);
			gBShowHotButtons = 0;
		}
		else
		{
			WritePrivateProfileString(szSettingINISection, "ShowHotButtons", "1", INIFileName);
		}
	}
	ret = GetPrivateProfileInt(szSettingINISection, "ShowDistance", -1, INIFileName);
	gBShowDistance = (ret == 0 ? FALSE : TRUE);
	if (ret == -1)
	{
		WritePrivateProfileString(szSettingINISection, "ShowDistance", "1", INIFileName);
	}
	ret = GetPrivateProfileInt(szSettingINISection, "ShowExtDistance", -1, INIFileName);
	gBShowExtDistance = (ret == 0 ? FALSE : TRUE);
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
		
		//Player_ManaLabel ManaLabel 20
		//Player_FatigueLabel FatigueLabel 21
		CHAR OldName1[2048] = { "Player_ManaLabel" };
		CHAR OldScreenName1[2048] = { "ManaLabel" };
		CHAR OldController1[2048] = { "20" };
			
		CHAR OldName2[2048] = { "Player_FatigueLabel" };
		CHAR OldScreenName2[2048] = { "FatigueLabel" };
		CHAR OldController2[2048] = { "21" };
		ReadUIStringSetting("Label1", "Player_ManaLabel", OldName1);
		ReadUIStringSetting("Label2", "Player_FatigueLabel", OldName2);
		/*CHAR OldName1[2048] = { "TargetOfTarget_HPLabel" };
		CHAR OldScreenName1[2048] = { "TargetOfTarget_HPLabel" };
		CHAR OldController1[2048] = { "120" };
			
		CHAR OldName2[2048] = { "TargetOfTarget_HPPercLabel" };
		CHAR OldScreenName2[2048] = { "TargetOfTarget_HPPercLabel" };
		CHAR OldController2[2048] = { "0" };
		
/*		CHAR OldName1[2048] = { "SL_DestNameLabel" };
		CHAR OldScreenName1[2048] = { "SL_DestNameLabel" };
		CHAR OldController1[2048] = { "0" };
			
		CHAR OldName2[2048] = { "SL_ServerListPrompt" };
		CHAR OldScreenName2[2048] = { "SL_ServerListPrompt" };
		CHAR OldController2[2048] = { "0" };
*/
		CHAR szDynamic[MAX_STRING] = { 0 };
		ReadUIStringSetting("DynamicUI", "1", szDynamic);
		int isDynamic = atoi(szDynamic);
		//setup the group info
		if (CGroupWnd*pGwnd = (CGroupWnd*)pGroupWnd) {
			//for default ui style is 0xa44
			//this was a stupid idea, lets not mess with the location
			//orgloc.top = pGwnd->TopOffset;
			//orgloc.right = pGwnd->RightOffset;
			//orgloc.bottom = pGwnd->BottomOffset;
			//orgloc.left = pGwnd->LeftOffset;
			//orglocation = pGwnd->Location;
			//CHAR szLoc[MAX_STRING] = { 0 };
			//CHAR szOutLoc[MAX_STRING] = { 0 };
			//sprintf_s(szLoc, "%d,%d,%d,%d", 135,438,953,1098);
			//lets not.
			/*ReadUIStringSetting("GroupWindowLoc", szLoc, szOutLoc);
			char *token1 = NULL;
			char *next_token1 = NULL;
			CHAR szLocs[4][8];
			token1 = strtok_s(szOutLoc, ",", &next_token1);
			int j = 0;
			while (token1 != NULL)
			{
				if (token1 != NULL)
				{
					strcpy_s(szLocs[j], token1);
					token1 = strtok_s(NULL, ",", &next_token1);
					j++;
				}
			}

			pGwnd->Location.top = atoi(szLocs[0]);
			pGwnd->Location.bottom = atoi(szLocs[1]);
			pGwnd->Location.left = atoi(szLocs[2]);
			pGwnd->Location.right = atoi(szLocs[3]);
			*/
			orgwstyle = pGwnd->WindowStyle;
			if (orgwstyle & WSF_TITLEBAR)
			{
				pGwnd->WindowStyle |= ( WSF_SIZABLE | WSF_BORDER );
			}
			else {
				pGwnd->WindowStyle |= (WSF_CLIENTMOVABLE | WSF_SIZABLE | WSF_BORDER);
			}
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
			GW_Gauge1 = (CGaugeWnd*)((CXWnd*)pGwnd)->GetChildItem("Gauge1");
			GW_Gauge2 = (CGaugeWnd*)((CXWnd*)pGwnd)->GetChildItem("Gauge2");
			GW_Gauge3 = (CGaugeWnd*)((CXWnd*)pGwnd)->GetChildItem("Gauge3");
			GW_Gauge4 = (CGaugeWnd*)((CXWnd*)pGwnd)->GetChildItem("Gauge4");
			GW_Gauge5 = (CGaugeWnd*)((CXWnd*)pGwnd)->GetChildItem("Gauge5");

			//
			//CControlTemplate *DistLabelTemplateOrg = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("Target_AggroPctSecondaryLabel");
			CControlTemplate *DistLabelTemplateOrg = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("SL_DestNameLabel");
			CControlTemplate *DistLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate(OldName1);
			CControlTemplate *NavButtonTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("GW_InviteButton");//borrowing this...
			CControlTemplate *HBButtonTemplate1 = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("HB_Button1");
			CControlTemplate *HBButtonTemplate2 = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("HB_Button2");
			CControlTemplate *HBButtonTemplate3= (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("HB_Button3");
			//
			if (GW_Gauge1 && DistLabelTemplate) {
				GetCXStr(DistLabelTemplate->Name, OldName1);
				GetCXStr(DistLabelTemplate->ScreenID, OldScreenName1);
				GetCXStr(DistLabelTemplate->Controller, OldController1);

				SetCXStr(&DistLabelTemplate->Controller, "0");
				//create the distance label 1
				CHAR szLoc[MAX_STRING] = { 0 };
				CHAR szOutLoc[MAX_STRING] = { 0 };
				
				ReadUIStringSetting("GroupDistanceFontSize", "2", szOutLoc);
				int GroupDistanceFontSize = atoi(szOutLoc);
				ReadUIStringSetting("UseGroupLayoutBox", "0", szOutLoc);
				int UseLayoutBox = atoi(szOutLoc);
				sprintf_s(szLoc, "%d,%d,%d,%d",0,-20,70,0);
				ReadUIStringSetting("GroupDistanceLoc", szLoc, szOutLoc);
				char *token1 = NULL;
				char *next_token1 = NULL;
				CHAR szLocs[4][8];
				token1 = strtok_s(szOutLoc, ",", &next_token1);
				int j = 0;
				while (token1 != NULL)
				{
					if (token1 != NULL)
					{
						strcpy_s(szLocs[j], token1);
						token1 = strtok_s(NULL, ",", &next_token1);
						j++;
					}
				}
				int ttop = atoi(szLocs[0]);
				int tbottom = atoi(szLocs[1]);
				int tleft = atoi(szLocs[2]);
				int tright = atoi(szLocs[3]);
				if (UseLayoutBox)//they have a weird UI like sars that uses a layout box these UI's dont have any locations we can read
				{
					ReadUIStringSetting("GroupDistanceOffset", "0", szOutLoc);
					int GroupDistanceOffset = atoi(szOutLoc);
					ReadUIStringSetting("GroupDistanceElementPrefix", "GW_Gauge", szOutLoc);
					sprintf_s(szLoc, "%s1",szOutLoc);
					if (CXWnd*wnd = (CXWnd*)((CXWnd*)pGwnd)->GetChildItem(szLoc))
					{
						CreateDistLabel((CGroupWnd*)wnd, DistLabelTemplate, &GroupDistLabel1, "Group_DistLabel1", GroupDistanceFontSize, wnd->Location.top + ttop + GroupDistanceOffset, wnd->Location.bottom + tbottom, wnd->Location.left + tleft, wnd->Location.right + tright, true, gBShowDistance);
					}
					sprintf_s(szLoc, "%s2", szOutLoc);
					GroupDistanceOffset += GroupDistanceOffset;
					if (CXWnd*wnd = (CXWnd*)((CXWnd*)pGwnd)->GetChildItem(szLoc))
					{
						CreateDistLabel((CGroupWnd*)wnd, DistLabelTemplate, &GroupDistLabel2, "Group_DistLabel2", GroupDistanceFontSize, wnd->Location.top + ttop + GroupDistanceOffset, wnd->Location.bottom + tbottom, wnd->Location.left + tleft, wnd->Location.right + tright, true, gBShowDistance);
					}
					sprintf_s(szLoc, "%s3", szOutLoc);
					GroupDistanceOffset += GroupDistanceOffset;
					if (CXWnd*wnd = (CXWnd*)((CXWnd*)pGwnd)->GetChildItem(szLoc))
					{
						CreateDistLabel((CGroupWnd*)wnd, DistLabelTemplate, &GroupDistLabel3, "Group_DistLabel3", GroupDistanceFontSize, wnd->Location.top + ttop + GroupDistanceOffset, wnd->Location.bottom + tbottom, wnd->Location.left + tleft, wnd->Location.right + tright, true, gBShowDistance);
					}
					sprintf_s(szLoc, "%s4", szOutLoc);
					GroupDistanceOffset += GroupDistanceOffset;
					if (CXWnd*wnd = (CXWnd*)((CXWnd*)pGwnd)->GetChildItem(szLoc))
					{
						CreateDistLabel((CGroupWnd*)wnd, DistLabelTemplate, &GroupDistLabel4, "Group_DistLabel4", GroupDistanceFontSize, wnd->Location.top + ttop + GroupDistanceOffset, wnd->Location.bottom + tbottom, wnd->Location.left + tleft, wnd->Location.right + tright, true, gBShowDistance);
					}
					sprintf_s(szLoc, "%s5", szOutLoc);
					GroupDistanceOffset += GroupDistanceOffset;
					if (CXWnd*wnd = (CXWnd*)((CXWnd*)pGwnd)->GetChildItem(szLoc))
					{
						CreateDistLabel((CGroupWnd*)wnd, DistLabelTemplate, &GroupDistLabel5, "Group_DistLabel5", GroupDistanceFontSize, wnd->Location.top + ttop + GroupDistanceOffset, wnd->Location.bottom + tbottom, wnd->Location.left + tleft, wnd->Location.right + tright, true, gBShowDistance);
					}
				}
				else {
					if (isDynamic)
					{
						CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel1, "Group_DistLabel1", GroupDistanceFontSize, GW_Gauge1->TopOffset + ttop, GW_Gauge1->BottomOffset + tbottom, GW_Gauge1->LeftOffset + tleft, GW_Gauge1->RightOffset + tright, true, gBShowDistance);
						CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel2, "Group_DistLabel2", GroupDistanceFontSize, GW_Gauge2->TopOffset + ttop, GW_Gauge2->BottomOffset + tbottom, GW_Gauge2->LeftOffset + tleft, GW_Gauge2->RightOffset + tright, true, gBShowDistance);
						CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel3, "Group_DistLabel3", GroupDistanceFontSize, GW_Gauge3->TopOffset + ttop, GW_Gauge3->BottomOffset + tbottom, GW_Gauge3->LeftOffset + tleft, GW_Gauge3->RightOffset + tright, true, gBShowDistance);
						CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel4, "Group_DistLabel4", GroupDistanceFontSize, GW_Gauge4->TopOffset + ttop, GW_Gauge4->BottomOffset + tbottom, GW_Gauge4->LeftOffset + tleft, GW_Gauge4->RightOffset + tright, true, gBShowDistance);
						CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel5, "Group_DistLabel5", GroupDistanceFontSize, GW_Gauge5->TopOffset + ttop, GW_Gauge5->BottomOffset + tbottom, GW_Gauge5->LeftOffset + tleft, GW_Gauge5->RightOffset + tright, true, gBShowDistance);
					}
					else
					{
						CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel1, "Group_DistLabel1", GroupDistanceFontSize, GW_Gauge1->Location.top + ttop, GW_Gauge1->Location.bottom + tbottom, GW_Gauge1->Location.left + tleft, GW_Gauge1->Location.right + tright, true, gBShowDistance);
						CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel2, "Group_DistLabel2", GroupDistanceFontSize, GW_Gauge2->Location.top + ttop, GW_Gauge2->Location.bottom + tbottom, GW_Gauge2->Location.left + tleft, GW_Gauge2->Location.right + tright, true, gBShowDistance);
						CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel3, "Group_DistLabel3", GroupDistanceFontSize, GW_Gauge3->Location.top + ttop, GW_Gauge3->Location.bottom + tbottom, GW_Gauge3->Location.left + tleft, GW_Gauge3->Location.right + tright, true, gBShowDistance);
						CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel4, "Group_DistLabel4", GroupDistanceFontSize, GW_Gauge4->Location.top + ttop, GW_Gauge4->Location.bottom + tbottom, GW_Gauge4->Location.left + tleft, GW_Gauge4->Location.right + tright, true, gBShowDistance);
						CreateDistLabel(pGwnd, DistLabelTemplate, &GroupDistLabel5, "Group_DistLabel5", GroupDistanceFontSize, GW_Gauge5->Location.top + ttop, GW_Gauge5->Location.bottom + tbottom, GW_Gauge5->Location.left + tleft, GW_Gauge5->Location.right + tright, true, gBShowDistance);
					}
				}

				//create Nav All to Me Button
				if (NavButtonTemplate)
				{
					int oldfont = NavButtonTemplate->Font;
					bool oldbRelativePosition = NavButtonTemplate->bRelativePosition;
					bool oldbAutoStretchVertical = NavButtonTemplate->bAutoStretchVertical;
					bool oldbAutoStretchHorizontal = NavButtonTemplate->bAutoStretchHorizontal;
					bool oldbTopAnchorToTop = NavButtonTemplate->bTopAnchorToTop;
					bool oldbBottomAnchorToTop = NavButtonTemplate->bBottomAnchorToTop;
					bool oldbLeftAnchorToLeft = NavButtonTemplate->bLeftAnchorToLeft;
					bool oldbRightAnchorToLeft = NavButtonTemplate->bRightAnchorToLeft;
					DWORD oldStyleBits = NavButtonTemplate->StyleBits;
					
					//setup our template the way we want it:
					NavButtonTemplate->StyleBits = WSF_AUTOSTRETCHH | WSF_AUTOSTRETCHV | WSF_RELATIVERECT;
					NavButtonTemplate->bRightAnchorToLeft = true;
					NavButtonTemplate->bLeftAnchorToLeft = true;
					NavButtonTemplate->bBottomAnchorToTop = false;
					NavButtonTemplate->bTopAnchorToTop = false;
					NavButtonTemplate->bAutoStretchHorizontal = true;
					NavButtonTemplate->bAutoStretchVertical = true;
					NavButtonTemplate->bRelativePosition = true;

					CButtonWnd*Butt = (CButtonWnd*)((CXWnd*)pGwnd)->GetChildItem("GW_InviteButton");
					//Come To Me button
					//We let people customize what this button does:
					ReadStringSetting("ComeToMeText","Come To Me",szNav);
					ReadStringSetting("ComeToMeCommand","/bcg //nav id ${Me.ID}",szNavCommand);
					ReadStringSetting("ComeToMeToolTip",szNavCommand,szNavToolTip);

					RECT rc = { 0 };
					ReadUILocSetting("ComeToMeLoc", 61,27,6,46,&rc);
					CreateAButton(pGwnd, NavButtonTemplate, &NavButton, "GW_NavButton", "NavButton", 1, rc.top, rc.bottom, rc.left, rc.right, 0xFF00FFFF, 0xFFFFFFFF, szNavToolTip, szNav,gBShowComeToMeButton);
					
					//Follow Me button
					ReadStringSetting("FollowMeText","Follow Me",szFollowMe);
					ReadStringSetting("FollowMeCommand","/bcg //afollow spawn ${Me.ID}",szFollowMeCommand);
					ReadStringSetting("FollowMeeToolTip",szFollowMeCommand,szFollowMeToolTip);
					
					ReadUILocSetting("FollowMeLoc", 61,27,48,88,&rc);
					CreateAButton(pGwnd, NavButtonTemplate, &FollowMeButton, "GW_FollowMeButton", "FollowMeButton", 1, rc.top, rc.bottom, rc.left, rc.right, 0xFF00FFFF, 0xFFFFFFFF, szFollowMeToolTip, szFollowMe,gBShowFollowMeButton);
					
					//Mimic Me button
					ReadUILocSetting("MimicMeLoc", 61,27,90,130,&rc);
					CreateAButton(pGwnd, NavButtonTemplate, &MimicMeButton, "GW_MimicMeButton", "MimicMeButton", 1, rc.top, rc.bottom, rc.left, rc.right, 0xFF00FFFF, 0xFFFFFFFF, szMimicMeToolTip, szMimicMe,gBShowMimicMeButton);
					
					//Hotbutton0
					ReadUILocSetting("HotButton0Loc", 97,64,6,46,&rc);
					CreateGroupHotButton(pGwnd, HBButtonTemplate1, &GroupHotButton[0], rc.top, rc.bottom, rc.left, rc.right,0);
					//Hotbutton1
					ReadUILocSetting("HotButton1Loc", 97,64,49,89,&rc);
					CreateGroupHotButton(pGwnd, HBButtonTemplate2, &GroupHotButton[1], rc.top, rc.bottom, rc.left, rc.right,1);
					//Hotbutton2
					ReadUILocSetting("HotButton2Loc", 97,64,92,132,&rc);
					CreateGroupHotButton(pGwnd, HBButtonTemplate3, &GroupHotButton[2], rc.top, rc.bottom, rc.left, rc.right,2);
					
					
					//
					//now set the template values back
					SetCXStr(&NavButtonTemplate->Name, "GW_InviteButton");
					SetCXStr(&NavButtonTemplate->ScreenID, "InviteButton");
					NavButtonTemplate->bRelativePosition = oldbRelativePosition;
					NavButtonTemplate->bAutoStretchVertical = oldbAutoStretchVertical;
					NavButtonTemplate->bAutoStretchHorizontal = oldbAutoStretchHorizontal;
					NavButtonTemplate->bTopAnchorToTop = oldbTopAnchorToTop;
					NavButtonTemplate->bBottomAnchorToTop = oldbBottomAnchorToTop;
					NavButtonTemplate->bLeftAnchorToLeft = oldbLeftAnchorToLeft;
					NavButtonTemplate->bRightAnchorToLeft = oldbRightAnchorToLeft;
					NavButtonTemplate->StyleBits = oldStyleBits;
					NavButtonTemplate->Font = oldfont;
				}
				//
				//now set the template values back
				SetCXStr(&DistLabelTemplate->Name, OldName1);
				SetCXStr(&DistLabelTemplate->ScreenID, OldScreenName1);
				SetCXStr(&DistLabelTemplate->Controller, OldController1);
			}
			else {
				bDisablePluginDueToBadUI = true;
				WriteChatf("MQ2TargetInfo has been disabled due to an incompatible UI, let eqmule know.");
				return;
			}
		}
		//setup the targetinfo
		if (PCTARGETWND pTwnd = (PCTARGETWND)pTargetWnd) {
			orgTargetWindStyle = pTwnd->Wnd.WindowStyle;
			//org style for default ui is 0x00200a40
			if (orgTargetWindStyle & WSF_TITLEBAR)
			{
				pTwnd->Wnd.WindowStyle |= (WSF_SIZABLE | WSF_BORDER);
			}
			else {
				pTwnd->Wnd.WindowStyle |= (WSF_CLIENTMOVABLE | WSF_SIZABLE | WSF_BORDER);
			}
			if (Target_AggroPctPlayerLabel = (CLabelWnd*)((CXWnd*)pTwnd)->GetChildItem("Target_AggroPctPlayerLabel"))
			{
				Target_AggroPctPlayerLabel->BGColor = 0xFF00000;
				Target_AggroPctPlayerLabel->TopOffset = dTopOffset;
				Target_AggroPctPlayerLabel->BottomOffset = dBottomOffset;
			}
			if (Target_AggroNameSecondaryLabel = (CLabelWnd*)((CXWnd*)pTwnd)->GetChildItem("Target_AggroNameSecondaryLabel"))
			{
				Target_AggroNameSecondaryLabel->BGColor = 0xFF00000;
				Target_AggroNameSecondaryLabel->TopOffset = dTopOffset;
				Target_AggroNameSecondaryLabel->BottomOffset = dBottomOffset;
			}
			if (Target_AggroPctSecondaryLabel = (CLabelWnd*)((CXWnd*)pTwnd)->GetChildItem("Target_AggroPctSecondaryLabel"))
			{
				Target_AggroPctSecondaryLabel->BGColor = 0xFF00000;
				Target_AggroPctSecondaryLabel->TopOffset = dTopOffset;
				Target_AggroPctSecondaryLabel->BottomOffset = dBottomOffset;
			}
			if (Target_BuffWindow = (CSidlScreenWnd*)((CXWnd*)pTwnd)->GetChildItem("Target_BuffWindow"))
			{
				Target_BuffWindow->BGColor = 0xFF000000;
				Target_BuffWindow->TopOffset = Target_BuffWindow_TopOffset;
			}
			

			CControlTemplate *DistLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate(OldName1);
			CControlTemplate *CanSeeLabelTemplateOrg = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("Player_FatigueLabel");
			CControlTemplate *CanSeeLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate(OldName2);
			
			CControlTemplate *PHButtonTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("IDW_ModButton");//borrowing this...
			
			if (PHButtonTemplate && CanSeeLabelTemplate && DistLabelTemplate)
			{
				int oldphfont = PHButtonTemplate->Font;
				GetCXStr(DistLabelTemplate->Name, OldName1);
				GetCXStr(DistLabelTemplate->ScreenID, OldScreenName1);
				GetCXStr(DistLabelTemplate->Controller, OldController1);
				GetCXStr(CanSeeLabelTemplate->Name, OldName2);
				GetCXStr(CanSeeLabelTemplate->ScreenID, OldScreenName2);
				GetCXStr(CanSeeLabelTemplate->Controller, OldController2);
				int oldfont = DistLabelTemplate->Font;
				DistLabelTemplate->Font = 2;
				SetCXStr(&DistLabelTemplate->Controller, "0");
				SetCXStr(&CanSeeLabelTemplate->Controller, "0");
				//create the info label
				SetCXStr(&DistLabelTemplate->Name, "Target_InfoLabel");
				SetCXStr(&DistLabelTemplate->ScreenID, "Target_InfoLabel");
				if (InfoLabel = (CLabelWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)pTwnd, DistLabelTemplate)) {
					CHAR szLoc[MAX_STRING] = { 0 };
					CHAR szOutLoc[MAX_STRING] = { 0 };
					ReadUIStringSetting("TargetInfoAnchoredToRight", "0", szOutLoc);
					int anchoredright = atoi(szOutLoc);
					if (anchoredright)
					{
						InfoLabel->bRightAnchoredToLeft = true;
						InfoLabel->bLeftAnchoredToLeft = false;
					}
					else {
						InfoLabel->bRightAnchoredToLeft = false;
						InfoLabel->bLeftAnchoredToLeft = true;
					}
					InfoLabel->dShow = true;
					InfoLabel->bUseInLayoutVertical = true;
					InfoLabel->WindowStyle = WSF_AUTOSTRETCHH|WSF_TRANSPARENT|WSF_AUTOSTRETCHV|WSF_RELATIVERECT;
					InfoLabel->bClipToParent = true;
					InfoLabel->bUseInLayoutHorizontal = true;
					InfoLabel->bAlignCenter = false;
					InfoLabel->bAlignRight = false;
					sprintf_s(szLoc, "%d,%d,%d,%d",34,48,0,40);
					ReadUIStringSetting("TargetInfoLoc", szLoc, szOutLoc);
					char *token1 = NULL;
					char *next_token1 = NULL;
					CHAR szLocs[4][8];
					token1 = strtok_s(szOutLoc, ",", &next_token1);
					int j = 0;
					while (token1 != NULL)
					{
						if (token1 != NULL)
						{
							strcpy_s(szLocs[j], token1);
							token1 = strtok_s(NULL, ",", &next_token1);
							j++;
						}
					}
					InfoLabel->TopOffset = atoi(szLocs[0]);
					InfoLabel->BottomOffset = atoi(szLocs[1]);
					InfoLabel->LeftOffset = atoi(szLocs[2]);
					InfoLabel->RightOffset = atoi(szLocs[3]);

					InfoLabel->CRNormal = 0xFF00FF00;//green
					InfoLabel->BGColor = 0xFFFFFFFF;
					SetCXStr(&InfoLabel->Tooltip, szTargetInfo);
				}
				//create the distance label
				SetCXStr(&DistLabelTemplate->Name, "Target_DistLabel");
				SetCXStr(&DistLabelTemplate->ScreenID, "Target_DistLabel");
				CHAR szLoc[MAX_STRING] = { 0 };
				CHAR szOutLoc[MAX_STRING] = { 0 };
				sprintf_s(szLoc, "%d,%d,%d,%d",34,48,90,0);
				ReadUIStringSetting("TargetDistanceLoc", szLoc, szOutLoc);
				char *token1 = NULL;
				char *next_token1 = NULL;
				CHAR szLocs[4][8];
				token1 = strtok_s(szOutLoc, ",", &next_token1);
				int j = 0;
				while (token1 != NULL)
				{
					if (token1 != NULL)
					{
						strcpy_s(szLocs[j], token1);
						token1 = strtok_s(NULL, ",", &next_token1);
						j++;
					}
				}
				int ttop = atoi(szLocs[0]);
				int tbottom = atoi(szLocs[1]);
				int tleft = atoi(szLocs[2]);
				int tright = atoi(szLocs[3]);
				CreateDistLabel((CGroupWnd*)pTwnd, DistLabelTemplate, &DistanceLabel, "Target_DistLabel", 2, ttop,tbottom,tleft,tright,true, gBShowExtDistance);
				
				//create can see label
				CanSeeLabelTemplateOrg;
				int oldfont2 = CanSeeLabelTemplate->Font;
				CanSeeLabelTemplate->Font = 2;
				SetCXStr(&CanSeeLabelTemplate->Name, "Target_CanSeeLabel");
				SetCXStr(&CanSeeLabelTemplate->ScreenID, "Target_CanSeeLabel");
				if (CanSeeLabel = (CLabelWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)pTwnd, CanSeeLabelTemplate)) {
					CanSeeLabel->dShow = true;
					CanSeeLabel->bNoWrap = true;
					CanSeeLabel->WindowStyle = WSF_AUTOSTRETCHH|WSF_TRANSPARENT|WSF_AUTOSTRETCHV|WSF_RELATIVERECT;
					CanSeeLabel->bLeftAnchoredToLeft = true;
					CanSeeLabel->bRightAnchoredToLeft = false;
					CanSeeLabel->bBottomAnchoredToTop = true;
					CanSeeLabel->bTopAnchoredToTop = true;
					CanSeeLabel->bAlignCenter = true;
					CanSeeLabel->bAlignRight = false;
					CanSeeLabel->TopOffset = InfoTopOffset;
					CanSeeLabel->TopOffset += 10;
					CanSeeLabel->BottomOffset = InfoBottomOffset;
					CanSeeLabel->BottomOffset += 10;
					CanSeeLabel->LeftOffset = dLeftOffset;
					CanSeeLabel->RightOffset = dLeftOffset;
					CanSeeLabel->CRNormal = 0xFF00FF00;//green
					CanSeeLabel->BGColor = 0xFFFFFFFF;
					SetCXStr(&CanSeeLabel->Tooltip, szCanSeeTarget);
				}
				//create PHButton
				PHButtonTemplate->Font = 0;
				if (PHButton = (CButtonWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)pTwnd, PHButtonTemplate)) {
					PHButton->dShow = false;
					PHButton->bBottomAnchoredToTop = true;
					PHButton->bLeftAnchoredToLeft = true;
					PHButton->bRightAnchoredToLeft = false;
					PHButton->bTopAnchoredToTop = true;
					PHButton->TopOffset = InfoTopOffset + 1;
					PHButton->BottomOffset = dTopOffset - 1;
					PHButton->LeftOffset = 0;
					PHButton->RightOffset = 0;
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
				DistLabelTemplate->Font = oldfont;
				CanSeeLabelTemplate->Font = oldfont2;
				PHButtonTemplate->Font = oldphfont;
				SetCXStr(&DistLabelTemplate->Name, OldName1);
				SetCXStr(&DistLabelTemplate->ScreenID, OldScreenName1);
				SetCXStr(&DistLabelTemplate->Controller, OldController1);

				SetCXStr(&CanSeeLabelTemplate->Name, OldName2);
				SetCXStr(&CanSeeLabelTemplate->ScreenID, OldScreenName2);
				SetCXStr(&CanSeeLabelTemplate->Controller, OldController2);
			}
			else {
				bDisablePluginDueToBadUI = true;
				WriteChatf("MQ2TargetInfo has been disabled due to an incompatible UI, let eqmule know.");
				return;
			}
		}
		if (CXWnd*pExtWnd = FindMQ2Window("ExtendedTargetWnd"))
		{
			orgExtTargetWindStyle = pExtWnd->WindowStyle;
			//org style for default ui is 0xe44
			if (orgExtTargetWindStyle & WSF_TITLEBAR)
			{
				pExtWnd->WindowStyle |= (WSF_SIZABLE | WSF_BORDER);
			}
			else {
				pExtWnd->WindowStyle |= (WSF_CLIENTMOVABLE | WSF_SIZABLE | WSF_BORDER);
			}
			CControlTemplate *DistLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate(OldName1);
			if (DistLabelTemplate) {
				int oldfont = DistLabelTemplate->Font;
				GetCXStr(DistLabelTemplate->Name, OldName1);
				GetCXStr(DistLabelTemplate->ScreenID, OldScreenName1);
				GetCXStr(DistLabelTemplate->Controller, OldController1);
				CHAR szTemp[MAX_STRING] = { 0 };
				CHAR szLoc[MAX_STRING] = { 0 };
				CHAR szOutLoc[MAX_STRING] = { 0 };
				ReadUIStringSetting("UseExtLayoutBox", "0", szOutLoc);
				int UseExtLayoutBox = atoi(szOutLoc);

				SetCXStr(&DistLabelTemplate->Controller, "0");
				sprintf_s(szLoc, "%d,%d,%d,%d", 0,-20,70,0);
				
				ReadUIStringSetting("ExtDistanceLoc", szLoc, szOutLoc);
				char *token1 = NULL;
				char *next_token1 = NULL;
				CHAR szLocs[4][8];
				token1 = strtok_s(szOutLoc, ",", &next_token1);
				int j = 0;
				while (token1 != NULL)
				{
					if (token1 != NULL)
					{
						strcpy_s(szLocs[j], token1);
						token1 = strtok_s(NULL, ",", &next_token1);
						j++;
					}
				}
				int ttop = atoi(szLocs[0]);
				int tbottom = atoi(szLocs[1]);
				int tleft = atoi(szLocs[2]);
				int tright = atoi(szLocs[3]);
				for (int i = 0; i < 13; i++)
				{
					sprintf_s(szTemp, "ETW_Gauge%d", i);
					if (ETW_Gauge[i] = (CGaugeWnd*)pExtWnd->GetChildItem(szTemp))
					{
						sprintf_s(szTemp, "ETW_DistLabel%d", i);
						int top = ETW_Gauge[i]->TopOffset;
						int bottom = ETW_Gauge[i]->BottomOffset;
						int left = ETW_Gauge[i]->LeftOffset;
						int right = ETW_Gauge[i]->RightOffset;

						if (left==0 && top==0)//weird UI...
						{
							top = ETW_Gauge[i]->Location.top;
							bottom = ETW_Gauge[i]->Location.bottom;
							left = ETW_Gauge[i]->Location.left;
							right = ETW_Gauge[i]->Location.right;
						}
						if (UseExtLayoutBox)
						{
							CreateDistLabel((CGroupWnd*)ETW_Gauge[i], DistLabelTemplate, &ETW_DistLabel[i], szTemp, 2, top + ttop, bottom + tbottom, left + tleft, right + tright, true, gBShowExtDistance);
						}
						else
						{
							CreateDistLabel((CGroupWnd*)pExtWnd, DistLabelTemplate, &ETW_DistLabel[i], szTemp, 2, top + ttop, bottom + tbottom, left + tleft, right + tright, true, gBShowExtDistance);
						}
					}
				}
				DistLabelTemplate->Font = oldfont;
				SetCXStr(&DistLabelTemplate->Name, OldName1);
				SetCXStr(&DistLabelTemplate->ScreenID, OldScreenName1);
				SetCXStr(&DistLabelTemplate->Controller, OldController1);
			}
			else {
				bDisablePluginDueToBadUI = true;
				WriteChatf("MQ2TargetInfo has been disabled due to an incompatible UI, let eqmule know.");
				return;
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
					AddOurMenu(pGwnd,true,index);
					return true;
				}
				AddOurMenu(pGwnd,false,-1);
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
			if (pWnd && (
				pWnd->pParentWindow == (PCSIDLWND)GroupHotButton[0]
				|| pWnd->pParentWindow == (PCSIDLWND)GroupHotButton[1]
				|| pWnd->pParentWindow == (PCSIDLWND)GroupHotButton[2]
				|| pWnd == (CXWnd*)GroupHotButton[0]
				|| pWnd == (CXWnd*)GroupHotButton[1]
				|| pWnd == (CXWnd*)GroupHotButton[2]
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
			if (pWnd && (
				pWnd->pParentWindow == (PCSIDLWND)GroupHotButton[0]
				|| pWnd->pParentWindow == (PCSIDLWND)GroupHotButton[1]
				|| pWnd->pParentWindow == (PCSIDLWND)GroupHotButton[2]
				|| pWnd == (CXWnd*)GroupHotButton[0]
				|| pWnd == (CXWnd*)GroupHotButton[1]
				|| pWnd == (CXWnd*)GroupHotButton[2]
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
						WriteChatf("%s only works if mq2eqbc is loaded and eqbcs is started, Please run /plugin mq2eqbc and then /bccmd connect", szNav);
						return 1;
					}
				}
				StopMovement();
				CHAR szMe[MAX_STRING] = { 0 };
				strcpy_s(szMe, szNavCommand);
				ParseMacroData(szMe, MAX_STRING);
				DoCommand((PSPAWNINFO)pLocalPlayer, szMe);
				return 1;
			} else if (pWnd == FollowMeButton)
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
					if(!bConnectedtoEqBCs)
					{
						WriteChatf("%s only works if mq2eqbc is loaded and eqbcs is started, Please run /plugin mq2eqbc and then /bccmd connect", szFollowMe);
						return 1;
					}
				}
				if(!FollowMeButton->Checked)
					StopMovement(false);
				gbFollowme ^= true;
				FollowMeButton->Checked = gbFollowme;
				CHAR szMe[MAX_STRING] = { 0 };
				strcpy_s(szMe, szFollowMeCommand);
				ParseMacroData(szMe, MAX_STRING);
				if (gbFollowme)
				{
					if (strstr(szMe, "//afollow"))
					{
						if (!GetModuleHandle("mq2advpath"))
						{
							WriteChatf("%s only works if mq2advpath is loaded, Please run /plugin mq2advpath",szFollowMe);
							StopMovement();
							return 1;
						}
					}
					else if (strstr(szMe, "//stick"))
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
				case 58://follow me
				{
					PSPAWNINFO pSpawn = GetSpawnFromRightClickIndex();
					if (pSpawn)
					{
						if (FollowMeMap.find(rightclickindex) != FollowMeMap.end())
						{
							if (FollowMeMap[rightclickindex] == true)
							{
								DoCommandf("/bct %s //afollow off",pSpawn->Name);
								FollowMeMap[rightclickindex] = false;
							}
							else
							{
								DoCommandf("/bct %s //afollow spawn %d", pSpawn->Name, ((PSPAWNINFO)pLocalPlayer)->SpawnID);
								FollowMeMap[rightclickindex] = true;
							}
						}
						else
						{
							DoCommandf("/bct %s //afollow spawn %d", pSpawn->Name, ((PSPAWNINFO)pLocalPlayer)->SpawnID);
							FollowMeMap[rightclickindex] = true;
						}
					}
					return 1;
				}
				case 59://gBShowComeToMeButton
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
				case 60://gBShowMimicMeButton
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
				case 61://gBShowFollowMeButton
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
				case 62://gBShowHotButtons
				{
					CContextMenu* pContextMenu = (CContextMenu*)pWnd;
					POINT pt;
					pt.x = ((PCXWNDMGR)pWndMgr)->MousePoint.x;
					pt.y = ((PCXWNDMGR)pWndMgr)->MousePoint.y;
					int iItemID = ((CListWnd*)pContextMenu)->GetItemAtPoint(&pt);
					gBShowHotButtons ^= true;
					pContextMenu->CheckMenuItem(iItemID,gBShowHotButtons);
					GroupHotButton[0]->dShow = gBShowHotButtons;
					GroupHotButton[1]->dShow = gBShowHotButtons;
					GroupHotButton[2]->dShow = gBShowHotButtons;
					if(gBShowHotButtons)
						WriteSetting("ShowHotButtons", "1");
					else
						WriteSetting("ShowHotButtons", "0");
					return 1;
				}
				case 63://gBShowDistance
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
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide extdistance\ax\am(it's currently set to: %s)\ax.", gBShowExtDistance ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide distance\ax\am(it's currently set to: %s)\ax.", GroupDistLabel1->dShow ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide hot\ax\am(it's currently set to: %s)\ax.", gBShowHotButtons ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide followme\ax\am(it's currently set to: %s)\ax.", FollowMeButton->dShow ? "\aoON" : "\agOFF");
		WriteChatf("\ayMQ2TargetInfo\ax Usage: \ag/groupinfo show/hide cometome\ax\am(it's currently set to: %s)\ax.", NavButton->dShow ? "\aoON" : "\agOFF");
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
		CHAR szArg2[MAX_STRING] = { 0 };
		GetArg(szArg2, szLine, 2);
		if (!_stricmp(szArg2, "mimicme"))
		{
			MimicMeButton->dShow = true;
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
			GroupDistLabel1->dShow = true;
			GroupDistLabel2->dShow = true;
			GroupDistLabel3->dShow = true;
			GroupDistLabel4->dShow = true;
			GroupDistLabel5->dShow = true;
			WriteSetting("ShowDistance", "1");
		}
		else if (!_stricmp(szArg2, "hot"))
		{
			gBShowHotButtons = true;
			GroupHotButton[0]->dShow = true;
			GroupHotButton[1]->dShow = true;
			GroupHotButton[2]->dShow = true;
			WriteSetting("ShowHotButtons", "1");
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
	}
	else if (!_stricmp(szArg1, "hide"))
	{
		CHAR szArg2[MAX_STRING] = { 0 };
		GetArg(szArg2, szLine, 2);
		if (!_stricmp(szArg2, "mimicme"))
		{
			gBShowMimicMeButton = false;
			MimicMeButton->dShow = false;
			WriteSetting("ShowMimicMeButton", "0");
		}
		else if (!_stricmp(szArg2, "extdistance"))
		{
			gBShowExtDistance = false;
			for (int i = 0; i < 23; i++)
			{
				if (ETW_DistLabel[i])
				{
					ETW_DistLabel[i]->dShow = false;
				}
			}
			WriteSetting("ShowExtDistance", "0");
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
			gBShowHotButtons = false;
			GroupHotButton[0]->dShow = false;
			GroupHotButton[1]->dShow = false;
			GroupHotButton[2]->dShow = false;
			WriteSetting("ShowHotButtons", "0");
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
	else if (!_stricmp(szArg1, "mimicme"))
	{
		CHAR szArg2[MAX_STRING] = { 0 };
		GetArg(szArg2, szLine, 2);
		if (!_stricmp(szArg2, "off"))
		{
			gbMimicme = false;
			MimicMeButton->Checked = false;
		}
		else {
			gbMimicme = true;
			MimicMeButton->Checked = true;
		}
	}
	else if (!_stricmp(szArg1, "followme"))
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
				WriteChatf("%s only works if mq2eqbc is loaded and eqbcs is started, Please run /plugin mq2eqbc and then /bccmd connect", szFollowMe);
				return;
			}
		}
		CHAR szArg2[MAX_STRING] = { 0 };
		GetArg(szArg2, szLine, 2);
		if (!FollowMeButton->Checked)
			StopMovement(false);
		if (!_stricmp(szArg2, "off"))
		{
			gbFollowme = false;
			FollowMeButton->Checked = false;
		}
		else {
			gbFollowme = true;
			FollowMeButton->Checked = true;
		}
		CHAR szMe[MAX_STRING] = { 0 };
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
		DoCommand((PSPAWNINFO)pLocalPlayer, szMe);
		return;
	}
	else if (!_stricmp(szArg1, "cometome"))
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
				WriteChatf("%s only works if mq2eqbc is loaded and eqbcs is started, Please run /plugin mq2eqbc and then /bccmd connect", szNav);
				return;
			}
		}
		StopMovement();
		CHAR szMe[MAX_STRING] = { 0 };
		strcpy_s(szMe, szNavCommand);
		ParseMacroData(szMe, MAX_STRING);
		DoCommand((PSPAWNINFO)pLocalPlayer, szMe);
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
	CHAR szMyIniName[2048] = { 0 };
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)InitializePlugin, &hMe);
	void* pMyBinaryData = 0;
	GetModuleFileName(hMe, szMyName, 2048);
	if (char *pDest = strrchr(szMyName, '.')) {
		pDest[0] = '\0';
		strcpy_s(szMyIniName, szMyName);
		strcat_s(szMyIniName, ".ini");
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
	hSearch = FindFirstFile(szMyIniName, &FindFile);
	if (hSearch == INVALID_HANDLE_VALUE) {
		//need to unpack our resource.
		if (HRSRC hRes = FindResource(hMe, MAKEINTRESOURCE(IDR_INI1), "INI")) {
			if (HGLOBAL bin = LoadResource(hMe, hRes)) {
				BOOL bResult = 0;
				if (pMyBinaryData = LockResource(bin)) {
					//save it...
					DWORD ressize = SizeofResource(hMe, hRes);
					FILE *File = 0;
					errno_t err = fopen_s(&File, szMyIniName, "wb");
					if (!err) {
						fwrite(pMyBinaryData, ressize, 1, File);
						fclose(File);
					}
					bResult = UnlockResource(hRes);
				}
				bResult = FreeResource(hRes);
			}
		}
	}
	else {
		FindClose(hSearch);
	}
	EzDetourwName(CTargetWnd__HandleBuffRemoveRequest, &MyCTargetWnd::HandleBuffRemoveRequest_Detour, &MyCTargetWnd::HandleBuffRemoveRequest_Tramp, "CTargetWnd__HandleBuffRemoveRequest");
	DebugSpewAlways("Initializing MQ2TargetInfo");
	Initialize();
}

void CleanUp(bool bUnload)
{
	if (CGroupWnd*pGwnd = (CGroupWnd*)pGroupWnd) {
		if (orgwstyle)
		{
			//CHAR szSize[MAX_STRING] = { 0 };
			//sprintf_s(szSize, "%d,%d,%d,%d", pGwnd->Location.top, pGwnd->Location.bottom, pGwnd->Location.left, pGwnd->Location.right);
			//WriteUIStringSetting("GroupWindowLoc", szSize);
			//we dont need to do this, they might want to move the window after we unload...
			//pGwnd->WindowStyle = orgwstyle;
			if (bUnload)
			{
				/*pGwnd->Location = orglocation;
				pGwnd->TopOffset = orgloc.top;
				pGwnd->BottomOffset = orgloc.bottom;
				pGwnd->LeftOffset = orgloc.left;
				pGwnd->RightOffset = orgloc.right;
				pGwnd->bNeedsSaving = true;
				pGwnd->bClientRectChanged = true;*/
			}
			orgwstyle = 0;
		}
		if (pGwnd->GroupContextMenu && separatorid)
		{
			RemoveOurMenu(pGwnd);
		}
	}
	if (PCTARGETWND pTwnd = (PCTARGETWND)pTargetWnd) {
		if (orgTargetWindStyle)
		{
			//pTwnd->Wnd.WindowStyle = orgTargetWindStyle;
			pTwnd->Wnd.bNeedsSaving = true;
			pTwnd->Wnd.bClientRectChanged = true;
			orgTargetWindStyle = 0;
		}
	}
	if (CXWnd*pExtWnd = FindMQ2Window("ExtendedTargetWnd"))
	{
		if (orgExtTargetWindStyle)
		{
			//pExtWnd->WindowStyle = orgExtTargetWindStyle;
			pExtWnd->bNeedsSaving = true;
			pExtWnd->bClientRectChanged = true;
			orgExtTargetWindStyle = 0;
		}
	}
	if (ETW_DistLabel[0])
	{
		for (int i = 0; i < 23; i++)
		{
			if (ETW_DistLabel[i])
			{
				((CButtonWnd*)ETW_DistLabel[i])->Destroy();
				ETW_DistLabel[i] = 0;
			}
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
	if (GroupHotButton[0]) {
		((CXWnd*)GroupHotButton[0])->Destroy();
		GroupHotButton[0] = 0;
	}
	if (GroupHotButton[1]) {
		((CXWnd*)GroupHotButton[1])->Destroy();
		GroupHotButton[1] = 0;
	}
	if (GroupHotButton[2]) {
		((CXWnd*)GroupHotButton[2])->Destroy();
		GroupHotButton[2] = 0;
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
	bDisablePluginDueToBadUI = false;
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
			sprintf_s(szTargetDist, "%.2f", dist);
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


void UpdatedExtDistance()
{
	if (PCHARINFO pChar = GetCharInfo())
	{
		CLabelWnd *pWnd = 0;
		if (ExtendedTargetList *xtm = pChar->pXTargetMgr) {
			for (int i = 0; i < xtm->XTargetSlots.Count; i++) {
				if (pWnd = ETW_DistLabel[i])
				{
					XTARGETSLOT xts = xtm->XTargetSlots[i];
					DWORD spID = xts.SpawnID;
					if (spID) {
						if (PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByID(spID)) {
							float dist = Distance3DToSpawn(pLocalPlayer, pSpawn);
							sprintf_s(szTargetDist, "%.2f", dist);
							if (dist < 250) {
								pWnd->CRNormal = 0xFF00FF00;//green
							}
							else {
								pWnd->CRNormal = 0xFFFF0000;//red
							}
							SetCXStr(&pWnd->WindowText, szTargetDist);
							pWnd->dShow = true;
						}
						else {
							pWnd->dShow = false;
						}
					}
					else {
						pWnd->dShow = false;
					}
				}
			}
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
			if (!_strnicmp(szLine, "Hail, ", 6))
			{
				DoCommandf("/bcg //keypress HAIL");
			}
			else {
				DoCommandf("/bcg //say %s", szLine);
			}
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
			if (gBShowExtDistance && ETW_DistLabel[0])
			{
				if (CExtendedTargetWnd *pEXTwnd = (CExtendedTargetWnd*)pExtendedTargetWnd) {
					if (pEXTwnd->dShow)
					{
						UpdatedExtDistance();
					}
				}
			}
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
							{
								if (pInfo->Type==SPAWN_PLAYER)
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
						SetCXStr(&InfoLabel->WindowText, szTargetDist);
						//then distance
						float dist = Distance3DToSpawn(pLocalPlayer, pTarget);
						sprintf_s(szTargetDist, "%.2f", dist);
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