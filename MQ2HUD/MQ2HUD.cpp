// MQ2HUD.cpp : Defines the entry point for the DLL application.
//
// Cr4zyb4rd patch: 1/7/2005

#include "../MQ2Plugin.h"

bool bEQHasFocus=true;
HMODULE EQWhMod=0; // Module handle used to check for eqw
typedef HWND   (__stdcall *fEQW_GetDisplayWindow)(VOID);
fEQW_GetDisplayWindow EQW_GetDisplayWindow=0;

typedef struct _HUDELEMENT {
    DWORD Type;
    DWORD Size;
    LONG X;
    LONG Y;
    DWORD Color;
    CHAR Text[MAX_STRING];
    CHAR PreParsed[MAX_STRING];
    struct _HUDELEMENT *pNext;
} HUDELEMENT, *PHUDELEMENT;

#define HUDTYPE_NORMAL      1
#define HUDTYPE_FULLSCREEN   2
#define HUDTYPE_CURSOR      4
#define HUDTYPE_CHARSELECT  8

PreSetup("MQ2HUD");

PHUDELEMENT pHud=0;
struct _stat LastRead;

char HUDNames[MAX_STRING]="Elements";
char HUDSection[MAX_STRING]="MQ2HUD";
int SkipParse=1;
int CheckINI=10;
bool bBGUpdate = true;
bool bClassHUD = true;
bool bZoneHUD = true;
bool bUseFontSize = false;

BOOL Stat(PCHAR Filename, struct _stat &Dest)
{
    int client = _open(Filename,_O_RDONLY);
    if (client == -1) {
        return FALSE;
    }
    _fstat(client,&Dest);
    _close(client);
    return TRUE;
}

VOID ClearElements()
{
    while(pHud)
    {
        PHUDELEMENT pNext=pHud->pNext;
        delete pHud;
        pHud=pNext;
    }
}

VOID AddElement(PCHAR IniString)
{
    LONG X;
    LONG Y;
    DWORD Type;
    ARGBCOLOR Color;
    Color.A=0xFF;
    // x,y,color,string
    PCHAR pComma;
    DWORD Size;

    pComma=strchr(IniString,',');
    if (!pComma)
        return;
    *pComma=0;
    Type=atoi(IniString);
    IniString=&pComma[1];

    if(bUseFontSize)
    {
        pComma=strchr(IniString,',');
        if (!pComma)
            return;
        *pComma=0;
        Size=atoi(IniString);
        IniString=&pComma[1];
    }
    else
    {
        Size=2;
    }

    pComma=strchr(IniString,',');
    if (!pComma)
        return;
    *pComma=0;
    X=atoi(IniString);
    IniString=&pComma[1];

    //y
    pComma=strchr(IniString,',');
    if (!pComma)
        return;
    *pComma=0;
    Y=atoi(IniString);
    IniString=&pComma[1];

    //color R
    pComma=strchr(IniString,',');
    if (!pComma)
        return;
    *pComma=0;
    Color.R=atoi(IniString);
    IniString=&pComma[1];

    //color G
    pComma=strchr(IniString,',');
    if (!pComma)
        return;
    *pComma=0;
    Color.G=atoi(IniString);
    IniString=&pComma[1];

    //color B
    pComma=strchr(IniString,',');
    if (!pComma)
        return;
    *pComma=0;
    Color.B=atoi(IniString);
    IniString=&pComma[1];

    //string
    if (!IniString[0])
        return;
    PHUDELEMENT pElement=new HUDELEMENT;
    pElement->pNext=pHud;
    pHud=pElement;
    pElement->Type=Type;
    pElement->Color=Color.ARGB;
    pElement->X=X;
    pElement->Y=Y;
    strcpy(pElement->Text,IniString);
    pElement->Size=Size;

    DebugSpew("New element '%s' in color %X",pElement->Text,pElement->Color);
}

VOID LoadElements()
{
    ClearElements();
    CHAR ElementList[MAX_STRING*10] = {0};
    CHAR szBuffer[MAX_STRING], CurrentHUD[MAX_STRING] = {0};
    CHAR ClassDesc[MAX_STRING], ZoneName[MAX_STRING] = {0};
    int argn=1;
    GetArg(CurrentHUD,HUDNames,argn,0,0,0,',');
    while (*CurrentHUD) {
        GetPrivateProfileString(CurrentHUD,NULL,"",ElementList,MAX_STRING*10,INIFileName);
        PCHAR pElementList = ElementList;
        while (pElementList[0]!=0) {
            GetPrivateProfileString(CurrentHUD,pElementList,"",szBuffer,MAX_STRING,INIFileName);
            if (szBuffer[0]!=0) {
                AddElement(szBuffer);
            }
            pElementList+=strlen(pElementList)+1;
        }
        GetArg(CurrentHUD,HUDNames,++argn,0,0,0,',');
    }
    if (gGameState==GAMESTATE_INGAME) {
        if (bClassHUD && ((ppCharData) && (pCharData))) {
            sprintf(ClassDesc,"%s",GetClassDesc(GetCharInfo2()->Class));
            GetPrivateProfileString(ClassDesc,NULL,"",ElementList,MAX_STRING*10,INIFileName);
            PCHAR pElementList = ElementList;
            while (pElementList[0]!=0) {
                GetPrivateProfileString(ClassDesc,pElementList,"",szBuffer,MAX_STRING,INIFileName);
                if (szBuffer[0]!=0) {
                    AddElement(szBuffer);
                }
                pElementList+=strlen(pElementList)+1;
            }
        }
        if (bZoneHUD && (pZoneInfo)) {
            sprintf(ZoneName,"%s",((PZONEINFO)pZoneInfo)->LongName);
            GetPrivateProfileString(ZoneName,NULL,"",ElementList,MAX_STRING*10,INIFileName);
            PCHAR pElementList = ElementList;
            while (pElementList[0]!=0) {
                GetPrivateProfileString(ZoneName,pElementList,"",szBuffer,MAX_STRING,INIFileName);
                if (szBuffer[0]!=0) {
                    AddElement(szBuffer);
                }
                pElementList+=strlen(pElementList)+1;
            }
        }
    }

    if (!Stat(INIFileName,LastRead))
        ZeroMemory(&LastRead,sizeof(struct _stat));
}

VOID HandleINI()
{
    CHAR szBuffer[MAX_STRING] = {0};
    WritePrivateProfileString(HUDSection,"Last",HUDNames,INIFileName);
    SkipParse = GetPrivateProfileInt(HUDSection,"SkipParse",1,INIFileName);
    SkipParse = SkipParse < 1 ? 1 : SkipParse;
    CheckINI = GetPrivateProfileInt(HUDSection,"CheckINI",10,INIFileName);
    CheckINI = CheckINI < 10 ? 10 : CheckINI;
    GetPrivateProfileString(HUDSection,"UpdateInBackground","on",szBuffer,MAX_STRING,INIFileName);
    bBGUpdate = strnicmp(szBuffer,"on",2)?false:true;
    GetPrivateProfileString(HUDSection,"ClassHUD","on",szBuffer,MAX_STRING,INIFileName);
    bClassHUD = strnicmp(szBuffer,"on",2)?false:true;
    GetPrivateProfileString(HUDSection,"ZoneHUD","on",szBuffer,MAX_STRING,INIFileName);
    bZoneHUD = strnicmp(szBuffer,"on",2)?false:true;
    GetPrivateProfileString("MQ2HUD","UseFontSize","off",szBuffer,MAX_STRING,INIFileName);
    bUseFontSize = strnicmp(szBuffer,"on",2)?false:true;
    // Write the SkipParse and CheckINI section, in case they didn't have one
    WritePrivateProfileString(HUDSection,"SkipParse",itoa(SkipParse,szBuffer,10),INIFileName);
    WritePrivateProfileString(HUDSection,"CheckINI",itoa(CheckINI,szBuffer,10),INIFileName);
    WritePrivateProfileString(HUDSection,"UpdateInBackground",bBGUpdate?"on":"off",INIFileName);
    WritePrivateProfileString(HUDSection,"ClassHUD",bClassHUD?"on":"off",INIFileName);
    WritePrivateProfileString(HUDSection,"ZoneHUD",bZoneHUD?"on":"off",INIFileName);
    WritePrivateProfileString("MQ2HUD","UseFontSize",bUseFontSize?"on":"off",INIFileName);

    LoadElements();
}

VOID DefaultHUD(PSPAWNINFO pChar, PCHAR szline)
{
    strcpy(HUDNames, "Elements");
    HandleINI();
}

VOID LoadHUD(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR HUDTemp[MAX_STRING] = {0};
    CHAR CurrentHUD[MAX_STRING];
    int argn=1;
    GetArg(CurrentHUD,HUDNames,argn,0,0,0,',');
    while (*CurrentHUD) {
        if (!strcmp(CurrentHUD,szLine)) {
            WriteChatf("Hud \"%s\" already loaded",szLine);
            return;
        }
        if (HUDTemp[0]) strcat(HUDTemp,",");
        strcat(HUDTemp,CurrentHUD);
        GetArg(CurrentHUD,HUDNames,++argn,0,0,0,',');
    }
    if (HUDTemp[0]) strcat(HUDTemp,",");
    strcat(HUDTemp,szLine);
    strcpy(HUDNames,HUDTemp);
    HandleINI();
}

VOID UnLoadHUD(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR HUDTemp[MAX_STRING] = {0};
    CHAR CurrentHUD[MAX_STRING];
    bool found=false;
    int argn=1;
    GetArg(CurrentHUD,HUDNames,argn,0,0,0,',');
    while (*CurrentHUD) {
        if (!strcmp(CurrentHUD,szLine)) {
            found=true;
        } else {
            if (HUDTemp[0]) strcat(HUDTemp,",");
            strcat(HUDTemp,CurrentHUD);
        }
        GetArg(CurrentHUD,HUDNames,++argn,0,0,0,',');
    }
    strcpy(HUDNames,HUDTemp);

    if (!found) WriteChatf("Hud \"%s\" not loaded",szLine);

    HandleINI();
}

VOID BackgroundHUD(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!_stricmp(szLine,"off"))
    {
        WritePrivateProfileString(HUDSection,"UpdateInBackground","off",INIFileName);
        WriteChatColor("MQ2HUD::Background updates are OFF");
    }
    else if (!_stricmp(szLine,"on"))
    {
        WritePrivateProfileString(HUDSection,"UpdateInBackground","on",INIFileName);
        WriteChatColor("MQ2HUD::Background updates are ON");
    }
    else
    {
        WriteChatColor("Usage: /backgroundhud [on|off]");
        return;
    }
    HandleINI();
}

VOID ClassHUD(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!_stricmp(szLine,"off"))
    {
        WritePrivateProfileString(HUDSection,"ClassHUD","off",INIFileName);
        WriteChatColor("MQ2HUD::Auto-include HUD per class description is OFF");
    }
    else if (!_stricmp(szLine,"on"))
    {
        WritePrivateProfileString(HUDSection,"ClassHUD","on",INIFileName);
        WriteChatColor("MQ2HUD::Auto-include HUD per class description is ON");
    }
    else
    {
        WriteChatColor("Usage: /classhud [on|off]");
        return;
    }
    HandleINI();
}

VOID ZoneHUD(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!_stricmp(szLine,"off"))
    {
        WritePrivateProfileString(HUDSection,"ZoneHUD","off",INIFileName);
        WriteChatColor("MQ2HUD::Auto-include HUD per zone name is OFF");
    }
    else if (!_stricmp(szLine,"on"))
    {
        WritePrivateProfileString(HUDSection,"ZoneHUD","on",INIFileName);
        WriteChatColor("MQ2HUD::Auto-include HUD per zone name is ON");
    }
    else
    {
        WriteChatColor("Usage: /zonehud [on|off]");
        return;
    }
    HandleINI();
}

BOOL dataHUD(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
    Ret.Ptr=HUDNames;
    Ret.Type=pStringType;
    return true;
}

// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
    CHAR szBuffer[MAX_STRING] = {0};
    // check for eqw running, and steal its function to check the foreground window if available
    if (EQWhMod=GetModuleHandle("eqw.dll"))
    {
        EQW_GetDisplayWindow=(fEQW_GetDisplayWindow)GetProcAddress(EQWhMod,"EQW_GetDisplayWindow");
    }
    DebugSpewAlways("Initializing MQ2HUD");

    GetPrivateProfileString(HUDSection,"Last","Elements",HUDNames,MAX_STRING,INIFileName);
    HandleINI();

    AddCommand("/defaulthud",DefaultHUD);
    AddCommand("/loadhud",LoadHUD);
    AddCommand("/unloadhud",UnLoadHUD);
    AddCommand("/backgroundhud",BackgroundHUD);
    AddCommand("/classhud",ClassHUD);
    AddCommand("/zonehud",ZoneHUD);
    AddMQ2Data("HUD",dataHUD);
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
    DebugSpewAlways("Shutting down MQ2HUD");
    ClearElements();
    RemoveCommand("/loadhud");
    RemoveCommand("/unloadhud");
    RemoveCommand("/defaulthud");
    RemoveCommand("/backgroundhud");
    RemoveCommand("/classhud");
    RemoveCommand("/zonehud");
    RemoveMQ2Data("HUD");
}

PLUGIN_API VOID SetGameState(DWORD GameState)
{
    if (GameState==GAMESTATE_INGAME)
        sprintf(HUDSection,"%s_%s",GetCharInfo()->Name,EQADDR_SERVERNAME);
    else 
        strcpy(HUDSection,"MQ2HUD");
    GetPrivateProfileString(HUDSection,"Last","Elements",HUDNames,MAX_STRING,INIFileName);
    HandleINI();
}

// Called after entering a new zone
PLUGIN_API VOID OnZoned(VOID)
{
    if (bZoneHUD) HandleINI();
}

// Called every frame that the "HUD" is drawn -- e.g. net status / packet loss bar
PLUGIN_API VOID OnDrawHUD(VOID)
{
    static int N=0;
    CHAR szBuffer[MAX_STRING]={0};

    if (++N>CheckINI)
    {
        N=0;
        struct _stat now;
        if (Stat(INIFileName,now) && now.st_mtime!=LastRead.st_mtime)
            HandleINI();

        // check for EQ in foreground
        HWND EQhWnd = *(HWND*)EQADDR_HWND;
        if (EQW_GetDisplayWindow) EQhWnd=EQW_GetDisplayWindow();
        if (!bBGUpdate && GetForegroundWindow()!=EQhWnd)
            bEQHasFocus = false;
        else
            bEQHasFocus = true;
    }
    if (!bEQHasFocus) return;

    DWORD SX=0;
    DWORD SY=0;
    if (pScreenX && pScreenY)
    {
        SX=ScreenX;
        SY=ScreenY;
    }   
    PHUDELEMENT pElement=pHud;

    DWORD X,Y;
    while(pElement)
    {
        if ((gGameState==GAMESTATE_CHARSELECT && pElement->Type&HUDTYPE_CHARSELECT) ||
            (gGameState==GAMESTATE_INGAME && (
            (pElement->Type&HUDTYPE_NORMAL && ScreenMode!=3) ||
            (pElement->Type&HUDTYPE_FULLSCREEN && ScreenMode==3))))
        {
            if (pElement->Type&HUDTYPE_CURSOR)
            {
                PMOUSEINFO pMouse = (PMOUSEINFO)EQADDR_MOUSE;
                X=pMouse->X+pElement->X;
                Y=pMouse->Y+pElement->Y;
            }
            else
            {
                X=SX+pElement->X;
                Y=SX+pElement->Y;
            }
            if (!(N%SkipParse)) {
                strcpy(pElement->PreParsed,pElement->Text);
                ParseMacroParameter(GetCharInfo()->pSpawn,pElement->PreParsed);
            }
            strcpy(szBuffer,pElement->PreParsed);
            if (szBuffer[0] && strcmp(szBuffer,"NULL"))
            {
                DrawHUDText(szBuffer,X,Y,pElement->Color,pElement->Size);
            }
        }
        pElement=pElement->pNext;
    }
}
