//
// ISXEQChatWnd
//
#pragma warning(disable:4996)
#include "../ISXEQClient.h"
#include "ISXEQChatWnd.h"

// The mandatory pre-setup function.  Our name is "ISXEQChatWnd", and the class is ISXEQChatWnd.
// This sets up a "ModulePath" variable which contains the path to this module in case we want it,
// and a "PluginLog" variable, which contains the path and filename of what we should use for our
// debug logging if we need it.  It also sets up a variable "pExtension" which is the pointer to
// our instanced class.
ISXPreSetup("ISXEQChatWnd",ISXEQChatWnd);


struct ChatBuffer
{
	CHAR Text[MAX_STRING];
	ChatBuffer *pNext;
	ChatBuffer *pPrev;
};

DWORD bmStripFirstStmlLines=0;
DWORD PendingChatLines=0;
ChatBuffer* pPendingChat=0;
ChatBuffer* pPendingChatTail=0;
CSemaphore ChatS;

#define MAX_CHAT_SIZE 700
#define LINES_PER_FRAME 3
int CMD_MQFont(int argc, char *argv[]);
void SaveChatToXML(PCSIDLWND pWindow);
void CreateChatWindow();
class CMQChatWnd;
CMQChatWnd *MQChatWnd=0;
VOID DoMQ2ChatBind(PCHAR Name,BOOL Down);
class CMQChatWnd : public CCustomWnd
{
public:
	CMQChatWnd():CCustomWnd("ChatWindow")
	{
		DebugSpew("CMQChatWnd()");
		SetWndNotification(CMQChatWnd);
		InputBox=(CTextEntryWnd*)GetChildItem("CWChatInput");
		InputBox->WindowStyle|=0x800C0;
		BitOff(WindowStyle,CWS_CLOSE);
		InputBox->UnknownCW|=0xFFFFFFFF;
		InputBox->SetMaxChars(512);
		OutputBox=(CStmlWnd*)GetChildItem("CWChatOutput");
		OutBoxLines=0;
		*(DWORD*)&(((PCHAR)OutputBox)[0x1C0])=400;
		OutputBox->Clickable=1;
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
					pISInterface->ExecuteCommand(szBuffer);
				}
				((CXWnd*)InputBox)->ClrFocus();
			}
			else
				DebugSpew("InputBox message %Xh, value: %Xh",Message,unknown);
		}
		else if (pWnd==(CXWnd*)OutputBox)
		{
			if (Message==XWM_NEWVALUE)
			{
				SaveChatToXML((PCSIDLWND)MQChatWnd);
			}
			else
				DebugSpew("OutputBox message %Xh, value: %Xh", Message, unknown);
		}
		else if (pWnd==0)
		{
			if (Message==XWM_CLOSE)
			{
				Show=1;
				return 1;
			}
		}
		else
		{
//			DebugSpew("Wnd: 0x%X, Msg: 0x%X, value: %Xh",pWnd,Message,unknown);
		}
		return CSidlScreenWnd::WndNotification(pWnd,Message,unknown);
	};

	CTextEntryWnd *InputBox;
	CStmlWnd *OutputBox;
	DWORD OutBoxLines;
};



// Basic LavishScript datatypes, these get retrieved on startup by our initialize function, so we can
// use them in our Top-Level Objects or custom datatypes
LSType *pStringType=0;
LSType *pIntType=0;
LSType *pBoolType=0;
LSType *pFloatType=0;
LSType *pTimeType=0;
LSType *pByteType=0;

ISInterface *pISInterface=0;
HISXSERVICE hPulseService=0;
HISXSERVICE hMemoryService=0;
HISXSERVICE hServicesService=0;
HISXSERVICE hConsoleService=0;

HISXSERVICE hEQChatService=0;
HISXSERVICE hEQUIService=0;
HISXSERVICE hEQGamestateService=0;
HISXSERVICE hEQSpawnService=0;
HISXSERVICE hEQZoneService=0;

// Forward declarations of callbacks
void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl ServicesService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl ConsoleService(bool Broadcast, unsigned int MSG, void *lpData);

// Initialize is called by Inner Space when the extension should initialize.
bool ISXEQChatWnd::Initialize(ISInterface *p_ISInterface)
{	pISInterface=p_ISInterface;

	// retrieve basic ISData types
	pStringType=pISInterface->FindLSType("string");
	pIntType=pISInterface->FindLSType("int");
	pBoolType=pISInterface->FindLSType("bool");
	pFloatType=pISInterface->FindLSType("float");
	pTimeType=pISInterface->FindLSType("time");
	pByteType=pISInterface->FindLSType("byte");


	pISInterface->OpenSettings(XMLFileName);
	LoadSettings();

	ConnectServices();

	RegisterCommands();
	RegisterAliases();
	RegisterDataTypes();
	RegisterTopLevelObjects();
    RegisterServices();

	AddMQ2KeyBind("MQ2CHAT",DoMQ2ChatBind);

	WriteChatf("ISXEQChatWnd Loaded");
	return true;
}

// shutdown sequence
void ISXEQChatWnd::Shutdown()
{
	// save settings, if you changed them and want to save them now.  You should normally save
	// changes immediately.
	//pISInterface->SaveSettings(XMLFileName);
	if (MQChatWnd)
	{
		SaveChatToXML((PCSIDLWND)MQChatWnd);
		delete MQChatWnd;
		MQChatWnd=0;
	}

	pISInterface->UnloadSettings(XMLFileName);

	DisconnectServices();

	UnRegisterServices();
	UnRegisterTopLevelObjects();
	UnRegisterDataTypes();
	UnRegisterAliases();
	UnRegisterCommands();

	while(pPendingChat)
	{
		ChatBuffer *pNext=pPendingChat->pNext;
		delete pPendingChat;
		pPendingChat=pNext;
	}
	pPendingChatTail=0;
	PendingChatLines=0;
	RemoveMQ2KeyBind("MQ2CHAT");


}


void ISXEQChatWnd::ConnectServices()
{
	// connect to any services.  Here we connect to "Pulse" which receives a
	// message every frame (after the frame is displayed) and "Memory" which
	// wraps "detours" and memory modifications
	hPulseService=pISInterface->ConnectService(this,"Pulse",PulseService);
	hMemoryService=pISInterface->ConnectService(this,"Memory",MemoryService);
	hServicesService=pISInterface->ConnectService(this,"Services",ServicesService);
	hConsoleService=pISInterface->ConnectService(this,"Console",ConsoleService);

}

void ISXEQChatWnd::RegisterCommands()
{
	// add any commands
//	pISInterface->AddCommand("MyCommand",MyCommand,true,false);
	pISInterface->AddCommand("MQFont",CMD_MQFont,true,false);
}

void ISXEQChatWnd::RegisterAliases()
{
	// add any aliases
}

void ISXEQChatWnd::RegisterDataTypes()
{
	// add any datatypes
	// pMyType = new MyType;
	// pISInterface->AddLSType(*pMyType);
}

void ISXEQChatWnd::RegisterTopLevelObjects()
{
	// add any Top-Level Objects
//	pISInterface->AddTopLevelObject("MapSpawn",tloMapSpawn);
}

void ISXEQChatWnd::RegisterServices()
{
	// register any services.  Here we demonstrate a service that does not use a
	// callback
	// set up a 1-way service (broadcast only)
//	hISXEQChatWndService=pISInterface->RegisterService(this,"ISXEQChatWnd Service",0);
	// broadcast a message, which is worthless at this point because nobody will receive it
	// (nobody has had a chance to connect)
//	pISInterface->ServiceBroadcast(this,hISXEQChatWndService,ISXSERVICE_MSG+1,0);

}

void ISXEQChatWnd::DisconnectServices()
{
	// gracefully disconnect from services
	if (hConsoleService)
		pISInterface->DisconnectService(this,hConsoleService);
	if (hPulseService)
		pISInterface->DisconnectService(this,hPulseService);
	if (hMemoryService)
	{
		pISInterface->DisconnectService(this,hMemoryService);
		// memory modifications are automatically undone when disconnecting
		// also, since this service accepts messages from clients we should reset our handle to
		// 0 to make sure we dont try to continue using it
		hMemoryService=0; 
	}
	if (hServicesService)
		pISInterface->DisconnectService(this,hServicesService);
}

void ISXEQChatWnd::UnRegisterCommands()
{
	// remove commands
//	pISInterface->RemoveCommand("MyCommand");
	pISInterface->RemoveCommand("MQFont");
}
void ISXEQChatWnd::UnRegisterAliases()
{
	// remove aliases
}
void ISXEQChatWnd::UnRegisterDataTypes()
{
	// remove data types
	//if (pMyType)
	//{
	//	pISInterface->RemoveLSType(*pMyType);
	//	delete pMyType;
	//}
}
void ISXEQChatWnd::UnRegisterTopLevelObjects()
{
	// remove Top-Level Objects
//	pISInterface->RemoveTopLevelObject("MapSpawn");
}
void ISXEQChatWnd::UnRegisterServices()
{
	// shutdown our own services
//	if (hISXEQChatWndService)
//		pISInterface->ShutdownService(this,hISXEQChatWndService);
}

void ISXEQChatWnd::LoadSettings()
{
}


void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData)
{
	if (MSG==PULSE_PULSE)
	{
		// Same as OnPulse
		if (gGameState==GAMESTATE_CHARSELECT && !MQChatWnd)
		{
			CreateChatWindow();
		}
		if (MQChatWnd && PendingChatLines)
		{
			DWORD ThisPulse=PendingChatLines;
			if (ThisPulse>LINES_PER_FRAME)
				ThisPulse=LINES_PER_FRAME;
			PendingChatLines-=ThisPulse;
			MQChatWnd->OutBoxLines+=ThisPulse;
			if (MQChatWnd->OutBoxLines>MAX_CHAT_SIZE)
			{
				DWORD Diff=(MQChatWnd->OutBoxLines-MAX_CHAT_SIZE)+LINES_PER_FRAME;
				MQChatWnd->OutBoxLines-=Diff;
				Benchmark(bmStripFirstStmlLines,MQChatWnd->OutputBox->StripFirstSTMLLines(Diff));
			}

			CXSize Whatever;
			for (DWORD N = 0 ; N < ThisPulse ; N++)
			{
				DebugTry(MQChatWnd->OutputBox->AppendSTML(&Whatever,pPendingChat->Text));
				ChatBuffer *pNext=pPendingChat->pNext;
				delete pPendingChat;
				pPendingChat=pNext;
			}
			if (!pPendingChat)
				pPendingChatTail=0;
			DebugTry(((CXWnd*)MQChatWnd->OutputBox)->SetVScrollPos(MQChatWnd->OutputBox->VScrollMax));
		}

	}
}

void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData)
{
	// no messages are currently associated with this service (other than
	// system messages such as client disconnect), so do nothing.
}

void __cdecl EQUIService(bool Broadcast, unsigned int MSG, void *lpData)
{
	switch(MSG)
	{
	case UISERVICE_CLEANUP:
		// same as OnCleanUI
		if (MQChatWnd)
		{
			SaveChatToXML((PCSIDLWND)MQChatWnd);
			delete MQChatWnd;
			MQChatWnd=0;
		}
		break;
	case UISERVICE_RELOAD:
		// same as OnReloadUI
		break;
	}
}
void __cdecl EQGamestateService(bool Broadcast, unsigned int MSG, void *lpData)
{
#define GameState ((unsigned int)lpData)
	if (MSG==GAMESTATESERVICE_CHANGED)
	{
		// same as SetGameState
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
				DebugTry(CreateChatWindow());
			}
		}
	}
#undef GameState
}
void __cdecl EQSpawnService(bool Broadcast, unsigned int MSG, void *lpData)
{
	switch(MSG)
	{
#define pSpawn ((PSPAWNINFO)lpData)
	case SPAWNSERVICE_ADDSPAWN:
		// same as OnAddSpawn
		break;
	case SPAWNSERVICE_REMOVESPAWN:
		// same as OnRemoveSpawn
		break;
#undef pSpawn
#define pGroundItem ((PGROUNDITEM)lpData)
	case SPAWNSERVICE_ADDITEM:
		// same as OnAddGroundItem
		break;
	case SPAWNSERVICE_REMOVEITEM:
		// same as OnRemoveGroundItem
		break;
#undef pGroundItem
	}
}

void __cdecl EQZoneService(bool Broadcast, unsigned int MSG, void *lpData)
{
	switch(MSG)
	{
	case ZONESERVICE_BEGINZONE:
		// same as OnBeginZone
		break;
	case ZONESERVICE_ENDZONE:
		// same as OnEndZone
		break;
	case ZONESERVICE_ZONED:
		// same as OnZoned
		break;
	}
}

void __cdecl EQChatService(bool Broadcast, unsigned int MSG, void *lpData)
{
#define pChat ((_EQChat*)lpData)
	switch(MSG)
	{
	case CHATSERVICE_OUTGOING:
		{
			// same as OnWriteChatColor
			if (!MQChatWnd)
			{
				EQGamestateService(false,GAMESTATESERVICE_CHANGED,(void*)gGameState);
				if (!MQChatWnd)
					return; 
			}
			MQChatWnd->Show=1;

			PFILTER pFilter = gpFilters; 

			while (pFilter) { 
				if (!pFilter->pEnabled || (*pFilter->pEnabled)) { 
					if (!strnicmp(pChat->Line,pFilter->FilterText,pFilter->Length)) 
					{
						return;
					}
				} 
				pFilter = pFilter->pNext; 
			} 
			DWORD Color=pChatManager->GetRGBAFromIndex(pChat->Color);

			CHAR szProcessed[MAX_STRING];
			MQToSTML(pChat->Line,szProcessed,MAX_STRING,Color);
			strcat(szProcessed,"<br>");
			CXStr NewText(szProcessed);
			DebugTry(ConvertItemTags(NewText,0));

			CLock L(&ChatS,1);
			ChatBuffer *pNewBuffer = new ChatBuffer;
			GetCXStr(NewText.Ptr,pNewBuffer->Text,MAX_STRING);
			pNewBuffer->pPrev=pPendingChatTail;
			pNewBuffer->pNext=0;
			if (pPendingChatTail)
				pPendingChatTail->pNext=pNewBuffer;
			else
				pPendingChat=pNewBuffer;
			pPendingChatTail=pNewBuffer;
			PendingChatLines++;
		}
		break;
	case CHATSERVICE_INCOMING:
		// same as OnIncomingChat
		break;
	}
#undef pChat
}

void __cdecl ConsoleService(bool Broadcast, unsigned int MSG, void *lpData)
{
#define pConsOutput ((char *)lpData)
	if (MSG!=CONSOLE_OUTPUT)
		return;
	// same as OnWriteChatColor
	if (!MQChatWnd)
	{
		EQGamestateService(false,GAMESTATESERVICE_CHANGED,(void*)gGameState);
		if (!MQChatWnd)
			return;
	}
	MQChatWnd->Show=1;

	PFILTER pFilter = gpFilters;

	while (pFilter) 
	{
		if (!pFilter->pEnabled || (*pFilter->pEnabled))
		{
			if (!strnicmp(pConsOutput,pFilter->FilterText,pFilter->Length))
				return;
		}
		pFilter = pFilter->pNext;
	}
	DWORD Color=pChatManager->GetRGBAFromIndex(USERCOLOR_DEFAULT);

	CHAR szProcessed[MAX_STRING];
	MQToSTML(pConsOutput,szProcessed,MAX_STRING,Color);
	strcat(szProcessed,"<br>");
	CXStr NewText(szProcessed);
	DebugTry(ConvertItemTags(NewText,0));
	
	CLock L(&ChatS,1);

	ChatBuffer *pNewBuffer = new ChatBuffer;
	GetCXStr(NewText.Ptr,pNewBuffer->Text,MAX_STRING);
	pNewBuffer->pPrev=pPendingChatTail;
	pNewBuffer->pNext=0;
	if (pPendingChatTail)
		pPendingChatTail->pNext=pNewBuffer;
	else
		pPendingChat=pNewBuffer;
	pPendingChatTail=pNewBuffer;
	PendingChatLines++;
}
#undef pConsOutput 

// This uses the Services service to connect to ISXEQ services
void __cdecl ServicesService(bool Broadcast, unsigned int MSG, void *lpData)
{
#define Name ((char*)lpData)
	switch(MSG)
	{
	case SERVICES_ADDED:
		if (!stricmp(Name,"EQ UI Service"))
		{
			hEQUIService=pISInterface->ConnectService(pExtension,Name,EQUIService);
		}
		else if (!stricmp(Name,"EQ Gamestate Service"))
		{
			hEQGamestateService=pISInterface->ConnectService(pExtension,Name,EQGamestateService);
		}
		else if (!stricmp(Name,"EQ Spawn Service"))
		{
			hEQSpawnService=pISInterface->ConnectService(pExtension,Name,EQSpawnService);
		}
		else if (!stricmp(Name,"EQ Zone Service"))
		{
			hEQZoneService=pISInterface->ConnectService(pExtension,Name,EQZoneService);
		}
		else if (!stricmp(Name,"EQ Chat Service"))
		{
			hEQChatService=pISInterface->ConnectService(pExtension,Name,EQChatService);
		}
		break;
	case SERVICES_REMOVED:
		if (!stricmp(Name,"EQ UI Service"))
		{
			if (hEQUIService)
			{
				pISInterface->DisconnectService(pExtension,hEQUIService);
				hEQUIService=0;
			}
		}
		else if (!stricmp(Name,"EQ Gamestate Service"))
		{
			if (hEQGamestateService)
			{
				pISInterface->DisconnectService(pExtension,hEQGamestateService);
				hEQGamestateService=0;
			}
		}
		else if (!stricmp(Name,"EQ Spawn Service"))
		{
			if (hEQSpawnService)
			{
				pISInterface->DisconnectService(pExtension,hEQSpawnService);
				hEQSpawnService=0;
			}
		}
		else if (!stricmp(Name,"EQ Zone Service"))
		{
			if (hEQZoneService)
			{
				pISInterface->DisconnectService(pExtension,hEQZoneService);
				hEQZoneService=0;
			}
		}
		else if (!stricmp(Name,"EQ Chat Service"))
		{
			if (hEQChatService)
			{
				pISInterface->DisconnectService(pExtension,hEQChatService);
				hEQChatService=0;
			}
		}
		break;
	}
#undef Name
}

CHAR szChatXMLSection[MAX_STRING] = {0};

#define GetIntSetting(name,var,_default_) if (pISInterface->GetSettingi(XMLFileName,szChatXMLSection,name,iTemp)) {var=iTemp;} else {var=_default_;pISInterface->SetSettingi(XMLFileName,szChatXMLSection,name,_default_);}
void LoadChatFromXML(PCSIDLWND pWindow)
{
	sprintf(szChatXMLSection,"%s.%s",EQADDR_SERVERNAME,((PCHARINFO)pCharData)->Name);

	int iTemp=0;
	GetIntSetting("Top",pWindow->Location.top,10);
	GetIntSetting("Bottom",pWindow->Location.bottom,210);
	if (pWindow->Location.top==pWindow->Location.bottom)
	{
		pWindow->Location.bottom+=200;
		pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Bottom",pWindow->Location.bottom);
	}
	GetIntSetting("Left",pWindow->Location.left,10);
	GetIntSetting("Right",pWindow->Location.right,410);
	if (pWindow->Location.left==pWindow->Location.right)
	{
		pWindow->Location.right+=400;
		pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Right",pWindow->Location.right);
	}
	
	GetIntSetting("Locked",pWindow->Locked,0);
	GetIntSetting("FontSize",*(DWORD*)&(((PCHAR)MQChatWnd->OutputBox)[0x174]),4);

	GetIntSetting("Fades",pWindow->Fades,1);
	GetIntSetting("Delay",pWindow->TimeMouseOver,2000);
	GetIntSetting("Duration",pWindow->FadeDuration,500);
	GetIntSetting("Alpha",pWindow->Alpha,255);
	GetIntSetting("FadeToAlpha",pWindow->FadeToAlpha,255);
	GetIntSetting("BGType",pWindow->BGType,1);
	GetIntSetting("BGTint.red",pWindow->BGColor.R,255);
	GetIntSetting("BGTint.green",pWindow->BGColor.G,255);
	GetIntSetting("BGTint.blue",pWindow->BGColor.B,255);

	char Buffer[MAX_STRING]={0};
	if (!pISInterface->GetSetting(XMLFileName,szChatXMLSection,"Title",Buffer,sizeof(Buffer)))
	{
		strcpy(Buffer,"ISXEQ");
		pISInterface->SetSetting(XMLFileName,szChatXMLSection,"Title","ISXEQ");
	}

	SetCXStr(&pWindow->WindowText,Buffer);

	pISInterface->SaveSettings(XMLFileName);
	/**/
}

void SaveChatToXML(PCSIDLWND pWindow)
{	
	if (pWindow->Minimized)
	{
		pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Top",pWindow->OldLocation.top);
		pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Bottom",pWindow->OldLocation.bottom);
		pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Left",pWindow->OldLocation.left);
		pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Right",pWindow->OldLocation.right);
	}
	else
	{
		pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Top",pWindow->Location.top);
		pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Bottom",pWindow->Location.bottom);
		pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Left",pWindow->Location.left);
		pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Right",pWindow->Location.right);
	}
	pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Locked",pWindow->Locked);

	char szTemp[MAX_STRING]={0};
	GetCXStr(pWindow->WindowText,szTemp);
	pISInterface->SetSetting(XMLFileName,szChatXMLSection,"Title",szTemp);

	pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Fades",pWindow->Fades);
	pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Delay",pWindow->TimeMouseOver);
	pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Duration",pWindow->FadeDuration);
	pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"Alpha",pWindow->Alpha);
	pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"FadeToAlpha",pWindow->FadeToAlpha);
	pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"BGType",pWindow->BGType);
	pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"BGTint.red",pWindow->BGColor.R);
	pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"BGTint.green",pWindow->BGColor.G);
	pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"BGTint.blue",pWindow->BGColor.B);
	pISInterface->SetSettingi(XMLFileName,szChatXMLSection,"FontSize",*(DWORD*)&(((PCHAR)MQChatWnd->OutputBox)[0x174]));

	pISInterface->SaveSettings(XMLFileName);
}

void CreateChatWindow()
{
	DebugSpew("MQ2ChatWnd::CreateChatWindow()");
	if (MQChatWnd)
		return;
	MQChatWnd = new CMQChatWnd();
	if (!MQChatWnd)
		return;
	LoadChatFromXML((PCSIDLWND)MQChatWnd);
//	SaveChatToXML((PCSIDLWND)MQChatWnd); // A) we're masochists, B) this creates the file if its not there..
}

VOID DoMQ2ChatBind(PCHAR Name,BOOL Down)
{
	if (!Down)
	{
		if (MQChatWnd)
		{
			CXRect rect= ((CXWnd*)MQChatWnd->InputBox)->GetScreenRect();
			CXPoint pt=rect.CenterPoint();
			((CXWnd*)MQChatWnd->InputBox)->SetWindowTextA(CXStr(""));
			((CXWnd*)MQChatWnd->InputBox)->HandleLButtonDown(&pt,0);
		}
	}
}

int CMD_MQFont(int argc, char *argv[])
{
	if (MQChatWnd)
	{
		if (argc)
		{
			*(DWORD*)&(((PCHAR)MQChatWnd->OutputBox)[0x174])=atoi(argv[0]);
			SaveChatToXML((PCSIDLWND)MQChatWnd);
		}
		WriteChatf("MQ2ChatWnd Font Size=%d",*(DWORD*)&(((PCHAR)MQChatWnd->OutputBox)[0x174]));
	}
	return 0;
}
