// MQ2HUD.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.



#include "../MQ2Plugin.h"

typedef struct _HUDELEMENT {
	DWORD Type;
	LONG X;
	LONG Y;
	DWORD Color;
	CHAR Text[MAX_STRING];
	struct _HUDELEMENT *pNext;
} HUDELEMENT, *PHUDELEMENT;

#define HUDTYPE_NORMAL		1
#define HUDTYPE_FULLSCREEN	2
#define HUDTYPE_CURSOR		4
#define HUDTYPE_CHARSELECT  8

PreSetup("MQ2HUD");

PHUDELEMENT pHud=0;
struct _stat LastRead;

char HUDName[MAX_STRING]="Elements";

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
		
		
	pComma=strchr(IniString,',');
	if (!pComma)
		return;
	*pComma=0;
	Type=atoi(IniString);
	IniString=&pComma[1];
		
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

	DebugSpew("New element '%s' in color %X",pElement->Text,pElement->Color);
}

VOID LoadElements()
{
	ClearElements();
	CHAR ElementList[MAX_STRING*10] = {0};
    CHAR szBuffer[MAX_STRING] = {0};
	GetPrivateProfileString(HUDName,NULL,"",ElementList,MAX_STRING*10,INIFileName);
    PCHAR pElementList = ElementList;
    while (pElementList[0]!=0) {
        GetPrivateProfileString(HUDName,pElementList,"",szBuffer,MAX_STRING,INIFileName);
        if (szBuffer[0]!=0) {
			AddElement(szBuffer);
        }
        pElementList+=strlen(pElementList)+1;
    }	


	if (!Stat(INIFileName,LastRead))
		ZeroMemory(&LastRead,sizeof(struct _stat));
}

VOID DefaultHUD(PSPAWNINFO pChar, PCHAR szline)
{
   strcpy(HUDName, "Elements");
   WritePrivateProfileString("MQ2HUD","Last",HUDName,INIFileName);
   LoadElements();
} 

VOID ChangeHUD(PSPAWNINFO pChar, PCHAR szLine) 
{
	strcpy(HUDName,szLine);
    WritePrivateProfileString("MQ2HUD","Last",HUDName,INIFileName);
	LoadElements();
}

BOOL dataHUD(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	Ret.Ptr=HUDName;
	Ret.Type=pStringType;
	return true;
}

// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2HUD");
	GetPrivateProfileString("MQ2HUD","Last","Elements",HUDName,MAX_STRING,INIFileName); 
	LoadElements();
	AddCommand("/defaulthud",DefaultHUD);
	AddCommand("/loadhud",ChangeHUD);
	AddMQ2Data("HUD",dataHUD);
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2HUD");
	ClearElements();
	RemoveCommand("/loadhud");
	RemoveCommand("/defaulthud");
	RemoveMQ2Data("HUD");
}

// Called every frame that the "HUD" is drawn -- e.g. net status / packet loss bar
PLUGIN_API VOID OnDrawHUD(VOID)
{
	static int N=0;
	if (++N>10)
	{
		N=0;
		struct _stat now;
		if (Stat(INIFileName,now) && now.st_mtime!=LastRead.st_mtime)
		{
			LoadElements();
		}
	}

	DWORD SX=0;
	DWORD SY=0;
	if (pScreenX && pScreenY)
	{
		SX=ScreenX;
		SY=ScreenY;
	}	
	CHAR szBuffer[MAX_STRING]={0};
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
			strcpy(szBuffer,pElement->Text);
			ParseMacroParameter(GetCharInfo()->pSpawn,szBuffer);		
			if (szBuffer[0] && strcmp(szBuffer,"NULL"))
			{
				DrawHUDText(szBuffer,X,Y,pElement->Color);
			}
		}

		pElement=pElement->pNext;
	}
}

