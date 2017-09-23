//
// ISXEQChat
//
#pragma warning(disable:4996)
#include "../ISXEQClient.h"
#include "ISXEQChat.h"

// The mandatory pre-setup function.  Our name is "ISXEQChat", and the class is ISXEQChat.
// This sets up a "ModulePath" variable which contains the path to this module in case we want it,
// and a "PluginLog" variable, which contains the path and filename of what we should use for our
// debug logging if we need it.  It also sets up a variable "pExtension" which is the pointer to
// our instanced class.
ISXPreSetup("ISXEQChat", ISXEQChat);

// Basic LavishScript datatypes, these get retrieved on startup by our initialize function, so we can
// use them in our Top-Level Objects or custom datatypes
LSType *pStringType = 0;
LSType *pIntType = 0;
LSType *pBoolType = 0;
LSType *pFloatType = 0;
LSType *pTimeType = 0;
LSType *pByteType = 0;

ISInterface *pISInterface = 0;
HISXSERVICE hPulseService = 0;
HISXSERVICE hMemoryService = 0;
HISXSERVICE hServicesService = 0;

HISXSERVICE hEQChatService = 0;
HISXSERVICE hEQUIService = 0;
HISXSERVICE hEQGamestateService = 0;
HISXSERVICE hEQSpawnService = 0;
HISXSERVICE hEQZoneService = 0;

// Forward declarations of callbacks
//void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData);
//void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl ServicesService(bool Broadcast, unsigned int MSG, void *lpData);


// Initialize is called by Inner Space when the extension should initialize.
bool ISXEQChat::Initialize(ISInterface *p_ISInterface)
{
	pISInterface = p_ISInterface;

	// retrieve basic ISData types
	pStringType = pISInterface->FindLSType("string");
	pIntType = pISInterface->FindLSType("int");
	pBoolType = pISInterface->FindLSType("bool");
	pFloatType = pISInterface->FindLSType("float");
	pTimeType = pISInterface->FindLSType("time");
	pByteType = pISInterface->FindLSType("byte");


	pISInterface->OpenSettings(XMLFileName);
	LoadSettings();

	ConnectServices();

	RegisterCommands();
	RegisterAliases();
	RegisterDataTypes();
	RegisterTopLevelObjects();
	RegisterServices();

	WriteChatf("ISXEQChat Loaded");
	return true;
}

// shutdown sequence
void ISXEQChat::Shutdown()
{
	// save settings, if you changed them and want to save them now.  You should normally save
	// changes immediately.
	//pISInterface->SaveSettings(XMLFileName);

	pISInterface->UnloadSettings(XMLFileName);

	DisconnectServices();

	UnRegisterServices();
	UnRegisterTopLevelObjects();
	UnRegisterDataTypes();
	UnRegisterAliases();
	UnRegisterCommands();
}


void ISXEQChat::ConnectServices()
{
	// connect to any services.  Here we connect to "Pulse" which receives a
	// message every frame (after the frame is displayed) and "Memory" which
	// wraps "detours" and memory modifications
	//    hPulseService=pISInterface->ConnectService(this,"Pulse",PulseService);
	//    hMemoryService=pISInterface->ConnectService(this,"Memory",MemoryService);
	hServicesService = pISInterface->ConnectService(this, "Services", ServicesService);


}

void ISXEQChat::RegisterCommands()
{
	// add any commands
	//    pISInterface->AddCommand("MyCommand",MyCommand,true,false);

}

void ISXEQChat::RegisterAliases()
{
	// add any aliases
}

void ISXEQChat::RegisterDataTypes()
{
	// add any datatypes
	// pMyType = new MyType;
	// pISInterface->AddLSType(*pMyType);
}

void ISXEQChat::RegisterTopLevelObjects()
{
	// add any Top-Level Objects
	//    pISInterface->AddTopLevelObject("MapSpawn",tloMapSpawn);
}

void ISXEQChat::RegisterServices()
{
	// register any services.  Here we demonstrate a service that does not use a
	// callback
	// set up a 1-way service (broadcast only)
	//    hISXEQChatService=pISInterface->RegisterService(this,"ISXEQChat Service",0);
	// broadcast a message, which is worthless at this point because nobody will receive it
	// (nobody has had a chance to connect)
	//    pISInterface->ServiceBroadcast(this,hISXEQChatService,ISXSERVICE_MSG+1,0);

}

void ISXEQChat::DisconnectServices()
{
	// gracefully disconnect from services
	if (hServicesService)
		pISInterface->DisconnectService(this, hServicesService);
}

void ISXEQChat::UnRegisterCommands()
{
	// remove commands
	//    pISInterface->RemoveCommand("MyCommand");
}
void ISXEQChat::UnRegisterAliases()
{
	// remove aliases
}
void ISXEQChat::UnRegisterDataTypes()
{
	// remove data types
	//if (pMyType)
	//{
	//    pISInterface->RemoveLSType(*pMyType);
	//    delete pMyType;
	//}
}
void ISXEQChat::UnRegisterTopLevelObjects()
{
	// remove Top-Level Objects
	//    pISInterface->RemoveTopLevelObject("MapSpawn");
}
void ISXEQChat::UnRegisterServices()
{
	// shutdown our own services
	//    if (hISXEQChatService)
	//        pISInterface->ShutdownService(this,hISXEQChatService);
}

void ISXEQChat::LoadSettings()
{
}



void __cdecl EQChatService(bool Broadcast, unsigned int MSG, void *lpData)
{
#define pChat ((_EQChat*)lpData)
	switch (MSG)
	{
	case CHATSERVICE_OUTGOING:
		// same as OnWriteChatColor
		CHAR Stripped[MAX_STRING];
		StripMQChat(pChat->Line, Stripped);
		if (gFilterMacro == FILTERMACRO_NONE)
			return;
		if (!ppEverQuest)
			return;
		if (gGameState != GAMESTATE_INGAME)
			return;

		if (!pEverQuest)
			return;
		dsp_chat_no_events(Stripped, pChat->Color, 1);
		break;
	case CHATSERVICE_INCOMING:
		// same as OnIncomingChat
		break;
	}
#undef pChat
}

// This uses the Services service to connect to ISXEQ services
void __cdecl ServicesService(bool Broadcast, unsigned int MSG, void *lpData)
{
#define Name ((char*)lpData)
	switch (MSG)
	{
	case SERVICES_ADDED:
		if (!stricmp(Name, "EQ Chat Service"))
		{
			hEQChatService = pISInterface->ConnectService(pExtension, Name, EQChatService);
		}
		break;
	case SERVICES_REMOVED:
		if (!stricmp(Name, "EQ Chat Service"))
		{
			if (hEQChatService)
			{
				pISInterface->DisconnectService(pExtension, hEQChatService);
				hEQChatService = 0;
			}
		}
		break;
	}
#undef Name
}