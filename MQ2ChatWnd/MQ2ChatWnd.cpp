// MQ2ChatWnd.cpp : Defines the entry point for the DLL application.
//

// Single-window MQ Chat

//#define DEBUG_TRY 1
#include "../MQ2Plugin.h"

void SaveChatToINI(PCSIDLWND pWindow);
void CreateChatWindow();
class CMQChatWnd;
CMQChatWnd *MQChatWnd=0;
VOID DoMQ2ChatBind(PCHAR Name,BOOL Down);
class CMQChatWnd : public CCustomWnd
{
public:
	CMQChatWnd():CCustomWnd("ChatWindow")
	{
		SetWndNotification(CMQChatWnd);
		InputBox=(CTextEntryWnd*)GetChildItem("CWChatInput");
		InputBox->WindowStyle|=0x800C0;
		BitOff(WindowStyle,CWS_CLOSE);
		InputBox->Unknown0x06c|=0xFFFFFFFF;
		InputBox->SetMaxChars(512);
		OutputBox=(CStmlWnd*)GetChildItem("CWChatOutput");
	}

	~CMQChatWnd()
	{
	}

	int WndNotification(CXWnd *pWnd, unsigned int Message, void *unknown)
	{	
		if (pWnd==(CXWnd*)InputBox)
		{
			if (Message==XWM_HITENTER)
			{
				CXSize Whatever; 
				char szBuffer[2048];
				GetCXStr((PCXSTR)InputBox->InputText,szBuffer,2047);
				if (szBuffer[0])
				{
					OutputBox->AppendSTML(&Whatever,szBuffer);
					SetCXStr(&InputBox->InputText,"");
					DoCommand(((PCHARINFO)pCharData)->pSpawn,szBuffer);
				}
				((CXWnd*)InputBox)->ClrFocus();
			}
			else
				DebugSpew("InputBox message %Xh, value: %Xh",Message,unknown);
		}
//		else if (pWnd==(CXWnd*)OutputBox)
//		{
//			DebugSpew("OutputBox message %Xh, value: %Xh",Message,unknown);
//		}
		else if (pWnd==0)
		{
			if (Message==XWM_CLOSE)
			{
				Show=1;
				return 1;
				//SaveChatToINI((PCSIDLWND)MQChatWnd);
				//MQChatWnd=0;
				// automatically gets deleted, dont try to delete it here..

//				DoCommand((PSPAWNINFO)pCharSpawn,"/plugin mq2chatwnd unload");
			}
			else
			DebugSpew("CMQChatWnd message %Xh, value: %Xh",Message,unknown);
		}
		else
		{
//			DebugSpew("Wnd: 0x%X, Msg: 0x%X, value: %Xh",pWnd,Message,unknown);
		}
		return CSidlScreenWnd::WndNotification(pWnd,Message,unknown);
	};

	CTextEntryWnd *InputBox;
	CStmlWnd *OutputBox;
};


PLUGIN_API VOID OnCleanUI(VOID);
PLUGIN_API VOID SetGameState(DWORD GameState);

PreSetup("MQ2ChatWnd");


CHAR szChatINISection[MAX_STRING] = {0};
void LoadChatFromINI(PCSIDLWND pWindow)
{
	
	CHAR Buffer[MAX_STRING] = {0};
    sprintf(szChatINISection,"%s.%s",((PCHARINFO)pCharData)->Server,((PCHARINFO)pCharData)->Name);
	pWindow->Location.top		= GetPrivateProfileInt(szChatINISection,"ChatTop",    10,INIFileName);
	pWindow->Location.bottom	= GetPrivateProfileInt(szChatINISection,"ChatBottom",210,INIFileName);
	pWindow->Location.left		= GetPrivateProfileInt(szChatINISection,"ChatLeft",   10,INIFileName);
	pWindow->Location.right 	= GetPrivateProfileInt(szChatINISection,"ChatRight", 410,INIFileName);
	pWindow->Locked			 	= GetPrivateProfileInt(szChatINISection,"Locked",	   0,INIFileName);
//	MQChatWnd->FontSize			= GetPrivateProfileInt(szChatINISection,"FontSize",	   4,INIFileName);

	pWindow->Fades			 	= GetPrivateProfileInt(szChatINISection,"Fades",	   1,INIFileName);
	pWindow->TimeMouseOver	 	= GetPrivateProfileInt(szChatINISection,"Delay",	 2000,INIFileName);
	pWindow->FadeDuration	 	= GetPrivateProfileInt(szChatINISection,"Duration",	   500,INIFileName);
	pWindow->Alpha				= GetPrivateProfileInt(szChatINISection,"Alpha",	   255,INIFileName);
	pWindow->FadeToAlpha		= GetPrivateProfileInt(szChatINISection,"FadeToAlpha",	   255,INIFileName);
	pWindow->BGType				= GetPrivateProfileInt(szChatINISection,"BGType",	   1,INIFileName);
	pWindow->BGColor.R				= GetPrivateProfileInt(szChatINISection,"BGTint.red",	   255,INIFileName);
	pWindow->BGColor.G				= GetPrivateProfileInt(szChatINISection,"BGTint.green",	   255,INIFileName);
	pWindow->BGColor.B				= GetPrivateProfileInt(szChatINISection,"BGTint.blue",	   255,INIFileName);

	GetPrivateProfileString(szChatINISection,"WindowTitle","MQ",Buffer,MAX_STRING,INIFileName);
	SetCXStr(&pWindow->WindowText,Buffer);
	/**/
}

void SaveChatToINI(PCSIDLWND pWindow)
{
	
	CHAR szTemp[MAX_STRING] = {0};
	if (pWindow->Minimized)
	{
		WritePrivateProfileString(szChatINISection,"ChatTop",	itoa(pWindow->OldLocation.top,		szTemp,10),INIFileName);
		WritePrivateProfileString(szChatINISection,"ChatBottom",itoa(pWindow->OldLocation.bottom,	szTemp,10),INIFileName);
		WritePrivateProfileString(szChatINISection,"ChatLeft",	itoa(pWindow->OldLocation.left,		szTemp,10),INIFileName);
		WritePrivateProfileString(szChatINISection,"ChatRight",	itoa(pWindow->OldLocation.right,	szTemp,10),INIFileName);
	}
	else
	{
		WritePrivateProfileString(szChatINISection,"ChatTop",	itoa(pWindow->Location.top,		szTemp,10),INIFileName);
		WritePrivateProfileString(szChatINISection,"ChatBottom",itoa(pWindow->Location.bottom,	szTemp,10),INIFileName);
		WritePrivateProfileString(szChatINISection,"ChatLeft",	itoa(pWindow->Location.left,	szTemp,10),INIFileName);
		WritePrivateProfileString(szChatINISection,"ChatRight",	itoa(pWindow->Location.right,	szTemp,10),INIFileName);
	}
	WritePrivateProfileString(szChatINISection,"Locked",	itoa(pWindow->Locked,			szTemp,10),INIFileName);

	GetCXStr(pWindow->WindowText,szTemp);
	WritePrivateProfileString(szChatINISection,"WindowTitle",	szTemp				  ,INIFileName);

	WritePrivateProfileString(szChatINISection,"Fades",	itoa(pWindow->Fades,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"Delay",	itoa(pWindow->MouseOver,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"Duration",	itoa(pWindow->FadeDuration,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"Alpha",	itoa(pWindow->Alpha,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"FadeToAlpha",	itoa(pWindow->FadeToAlpha,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"BGType",	itoa(pWindow->BGType,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"BGTint.red",	itoa(pWindow->BGColor.R,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"BGTint.green",	itoa(pWindow->BGColor.G,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"BGTint.blue",	itoa(pWindow->BGColor.B,			szTemp,10),INIFileName);

//	WritePrivateProfileString(szChatINISection,"FontSize",	itoa(MQChatWnd->FontSize,			szTemp,10),INIFileName);
	/**/
}


VOID Style(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine || szLine[0]==0)
	{
		char out[256];
		sprintf(out,"Style 0x%X",MQChatWnd->WindowStyle);
		WriteChatColor(out);
		return;
	}
	if (szLine[0]=='!')
	{
		int TurnOff;
		sscanf(&szLine[1],"%x",&TurnOff);
		BitOff(MQChatWnd->WindowStyle,TurnOff);
	}
	else
	{
		int TurnOn;
		sscanf(&szLine[0],"%x",&TurnOn);
		BitOn(MQChatWnd->WindowStyle,TurnOn);
	}
	char out[256];
	sprintf(out,"Style 0x%X",MQChatWnd->WindowStyle);
	WriteChatColor(out);
}

PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2ChatWnd");

	// Add commands, macro parameters, hooks, etc.
	AddCommand("/style",Style,0,1,0);

	AddMQ2KeyBind("MQ2CHAT",DoMQ2ChatBind);
}

PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2ChatWnd");

	// Remove commands, macro parameters, hooks, etc.
	RemoveCommand("/style");
	RemoveMQ2KeyBind("MQ2CHAT");
	OnCleanUI();
}


// This is called every time WriteChatColor is called by MQ2Main or any plugin,
// IGNORING FILTERS, IF YOU NEED THEM MAKE SURE TO IMPLEMENT THEM. IF YOU DONT
// CALL CEverQuest::dsp_chat MAKE SURE TO IMPLEMENT EVENTS HERE
PLUGIN_API DWORD OnWriteChatColor(PCHAR Line, DWORD Color, DWORD Filter)
{
//	DebugSpewAlways("MQ2ChatWnd::OnWriteChatColor(%s)",Line);
	
	if (!MQChatWnd)
	{
		if (gGameState==GAMESTATE_INGAME)
		{
			SetGameState(gGameState);
		}
		if (!MQChatWnd)
			return 0; 
	}
	MQChatWnd->Show=1;

	PFILTER pFilter = gpFilters; 

	while (pFilter) { 
		if (!pFilter->pEnabled || (*pFilter->pEnabled)) { 
			if (!strnicmp(Line,pFilter->FilterText,pFilter->Length)) {return 0;}
		} 
		pFilter = pFilter->pNext; 
	} 
	Color=pChatManager->GetRGBAFromIndex(Color);

	CHAR szProcessed[MAX_STRING];
	StripMQChat(Line,szProcessed);
	CheckChatForEvent(szProcessed);
	MQToSTML(Line,szProcessed,MAX_STRING,Color);
	strcat(szProcessed,"<br>");
	CXStr NewText(szProcessed);
	DebugTry(ConvertItemTags(NewText));
	CXSize Whatever;
	DebugTry(MQChatWnd->OutputBox->AppendSTML(&Whatever,NewText));
	DebugTry(((CXWnd*)MQChatWnd->OutputBox)->SetVScrollPos(MQChatWnd->OutputBox->VScrollMax));
	/**/
	return 0;
}

// Called once directly before shutdown of the cleanui system, and also
// every time the game calls CDisplay::CleanGameUI()
PLUGIN_API VOID OnCleanUI(VOID)
{
	DebugSpewAlways("MQ2ChatWnd::OnCleanUI()");
	if (MQChatWnd)
	{
		SaveChatToINI((PCSIDLWND)MQChatWnd);
		delete MQChatWnd;
		MQChatWnd=0;
	}
}

// Called once directly after initialization, and then every time the gamestate changes
PLUGIN_API VOID SetGameState(DWORD GameState)
{
	if (GameState==GAMESTATE_CHARSELECT)
	{
		AddMQ2KeyBind("MQ2CSCHAT",DoMQ2ChatBind);
		KeyCombo Combo;
		ParseKeyCombo("/",Combo);
		SetMQ2KeyBind("MQ2CSCHAT",0,Combo);
	}
	else
	{
		RemoveMQ2KeyBind("MQ2CSCHAT");
		if (GameState==GAMESTATE_INGAME && !MQChatWnd)
		{
			// we entered the game, set up shop
			CreateChatWindow();
		}
	}
}
// todo
VOID MQChatFont(PSPAWNINFO pChar, PCHAR Line)
{
}

PLUGIN_API VOID OnPulse(VOID)
{
	if (gGameState==GAMESTATE_CHARSELECT && !MQChatWnd)
	{
		CreateChatWindow();
	}
}

void CreateChatWindow()
{
	if (MQChatWnd)
		return;
	MQChatWnd = new CMQChatWnd();
	if (!MQChatWnd)
		return;
	LoadChatFromINI((PCSIDLWND)MQChatWnd);
	SaveChatToINI((PCSIDLWND)MQChatWnd); // A) we're masochists, B) this creates the file if its not there..
}

VOID DoMQ2ChatBind(PCHAR Name,BOOL Down)
{
	if (!Down)
	{
		if (MQChatWnd)
		{
			CXRect rect= ((CXWnd*)MQChatWnd->InputBox)->GetScreenRect();
			CXPoint pt=rect.CenterPoint();
			((CXWnd*)MQChatWnd->InputBox)->SetWindowTextA(CXStr("/"));
			((CXWnd*)MQChatWnd->InputBox)->HandleLButtonDown(&pt,0);
//			((CXWnd*)MQChatWnd->InputBox)->SetFocus();
		}
	}
}
