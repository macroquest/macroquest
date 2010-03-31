//
// ISXEQ
//

#include <windows.h>
#include "ISXEQ.h"

// The mandatory pre-setup function.  Our name is "ISXEQ", and the class is ISXEQ.
// This sets up a "ModulePath" variable which contains the path to this module in case we want it,
// and a "PluginLog" variable, which contains the path and filename of what we should use for our
// debug logging if we need it.  It also sets up a variable "pExtension" which is the pointer to
// our instanced class.
ISXPreSetup("ISXEQ",CISXEQ);

// Basic IS datatypes, these get retrieved on startup by our initialize function, so we can use them in
// our Top-Level Objects or custom datatypes
ISType *pStringType=0;
ISType *pIntType=0;
ISType *pBoolType=0;
ISType *pFloatType=0;
ISType *pTimeType=0;
ISType *pByteType=0;

ISInterface *pISInterface=0;
HISXSERVICE hPulseService;
HISXSERVICE hMemoryService;
HISXSERVICE hHTTPService;

// Forward declarations of callbacks
void __cdecl PulseService(bool Broadcast, unsigned long MSG, void *lpData);
void __cdecl MemoryService(bool Broadcast, unsigned long MSG, void *lpData);
void __cdecl HTTPService(bool Broadcast, unsigned long MSG, void *lpData);
int __cdecl MyCommand(int argc, char *argv[]);
bool __cdecl ISXEQData(int argc, char *argv[], ISTYPEVAR &Dest);


// The constructor of our class.  General initialization cannot be done yet, because we're not given
// the pointer to the Inner Space interface until it is ready for us to initialize.  Just set the
// pointer we have to the interface to 0.  Initialize data members, too.
CISXEQ::CISXEQ(void)
{
}

// Free any remaining resources in the destructor.  This is called when the DLL is unloaded, but
// Inner Space calls the "Shutdown" function first.  Most if not all of the shutdown process should
// be done in Shutdown.
CISXEQ::~CISXEQ(void)
{
}

// Initialize is called by Inner Space when the extension should initialize.
bool CISXEQ::Initialize(ISInterface *p_ISInterface)
{
	pISInterface=p_ISInterface;

	// retrieve basic ISData types
	pStringType=pISInterface->FindISType("string");
	pIntType=pISInterface->FindISType("int");
	pBoolType=pISInterface->FindISType("bool");
	pFloatType=pISInterface->FindISType("float");
	pTimeType=pISInterface->FindISType("time");
	pByteType=pISInterface->FindISType("byte");

	ConnectServices();

	RegisterCommands();
	RegisterAliases();
	RegisterDataTypes();
	RegisterTopLevelObjects();
    RegisterServices();

	printf("ISXEQ Loaded");
	return true;
}

// shutdown sequence
void CISXEQ::Shutdown()
{
	DisconnectServices();

	UnRegisterServices();
	UnRegisterTopLevelObjects();
	UnRegisterDataTypes();
	UnRegisterAliases();
	UnRegisterCommands();
}



void CISXEQ::ConnectServices()
{
	// connect to any services.  Here we connect to "Pulse" which receives a
	// message every frame (after the frame is displayed) and "Memory" which
	// wraps "detours" and memory modifications
	hPulseService=pISInterface->ConnectService(this,"Pulse",PulseService);
	hMemoryService=pISInterface->ConnectService(this,"Memory",MemoryService);
	hHTTPService=pISInterface->ConnectService(this,"HTTP",HTTPService);
}
void CISXEQ::RegisterCommands()
{
	// add any commands
//	pISInterface->AddCommand("MyCommand",MyCommand,true,false);
}

void CISXEQ::RegisterAliases()
{
	// add any aliases
}

void CISXEQ::RegisterDataTypes()
{
	// add any datatypes
	// pMyType = new MyType;
	// pISInterface->AddISType(*pMyType);
}

void CISXEQ::RegisterTopLevelObjects()
{
	// add any data items (Top-Level Objects)
	//pISInterface->AddISData("ISXEQ",ISXEQData);
}

void CISXEQ::RegisterServices()
{
	// register any services.  Here we demonstrate a service that does not use a
	// callback
	// set up a 1-way service (broadcast only)
//	hISXEQService=pISInterface->RegisterService(this,"ISXEQ Service",0);
	// broadcast a message, which is worthless at this point because nobody will receive it
	// (nobody has had a chance to connect)
//	pISInterface->ServiceBroadcast(this,hISXEQService,ISXSERVICE_MSG+1,0);

}

void CISXEQ::DisconnectServices()
{
	// gracefully disconnect from services
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
	if (hHTTPService)
	{
		pISInterface->DisconnectService(this,hHTTPService);
	}
}

void CISXEQ::UnRegisterCommands()
{
	// remove commands
//	pISInterface->RemoveCommand("MyCommand");
}
void CISXEQ::UnRegisterAliases()
{
	// remove aliases
}
void CISXEQ::UnRegisterDataTypes()
{
	// remove data types

}
void CISXEQ::UnRegisterTopLevelObjects()
{
	// remove data items
//	pISInterface->RemoveISData("ISXEQ");
}
void CISXEQ::UnRegisterServices()
{
	// shutdown our own services
//	if (hISXEQService)
//		pISInterface->ShutdownService(this,hISXEQService);
}

// Our command, which does pretty much nothing.  It displays a message, and returns
// the success code.
int __cdecl MyCommand(int argc, char *argv[])
{
	printf("ISXEQ MyCommand");
	return 0;
}

// Our Top-Level Object, a string that says Hello World.  Used like so: ${ISXEQ}
bool __cdecl ISXEQData(int argc, char *argv[], ISTYPEVAR &Dest)
{
	Dest.Ptr="Hello World";
	Dest.Type=pStringType;
	return true;
}

void __cdecl PulseService(bool Broadcast, unsigned long MSG, void *lpData)
{
	if (MSG==PULSE_PULSE)
	{
		// "OnPulse"
	}
}

void __cdecl MemoryService(bool Broadcast, unsigned long MSG, void *lpData)
{
	// no messages are currently associated with this service (other than
	// system messages such as client disconnect), so do nothing.
}

void __cdecl HTTPService(bool Broadcast, unsigned long MSG, void *lpData)
{
	switch(MSG)
	{
#define pReq ((HttpFile*)lpData)
	case HTTPSERVICE_FAILURE:
		// HTTP request failed to retrieve document
		printf("ISXEQ URL %s failed",pReq->URL);
		break;
	case HTTPSERVICE_SUCCESS:
		// HTTP request successfully retrieved document
		printf("ISXEQ URL %s -- %d bytes",pReq->URL,pReq->Size);
		// Retrieved data buffer is pReq->pBuffer and is null-terminated
		break;
#undef pReq
	}
}

