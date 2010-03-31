//
// ISXEQ
//

#include "..\MQ2Main.h"

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
void __cdecl ProtectionRequest(ISXInterface *pClient, unsigned long MSG, void *lpData);
HISXSERVICE hEQProtectionService=0;


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
	HookMemChecker(TRUE);

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
	hEQProtectionService=pISInterface->RegisterService(this,"EQ Memory Protection Service",ProtectionRequest);
	pISInterface->ServiceRequest(this,hMemoryService,MEM_ENABLEPROTECTION,"EQ Memory Protection Service");

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
	if (hEQProtectionService)
	{
		pISInterface->ServiceRequest(this,hMemoryService,MEM_DISABLEPROTECTION,"EQ Memory Protection Service");
		pISInterface->ShutdownService(this,hEQProtectionService);
	}
}

bool CISXEQ::Protect(unsigned long Address, unsigned long Size)
{
   for (unsigned long i = 0 ; i < ProtectedList.Size ; i++)
   if (EQProtected *pProtected=ProtectedList[i])
   {
      if (pProtected->Address==Address)
      {
         return false; // conflict
      }
   }

   // assumed to be safe
   EQProtected *pProtected = new EQProtected(Address,Size);
   ProtectedList+=pProtected;
   return true; 
}

bool CISXEQ::UnProtect(unsigned long Address)
{
   for (unsigned long i = 0 ; i < ProtectedList.Size ; i++)
   if (EQProtected *pProtected=ProtectedList[i])
   {
      if (pProtected->Address==Address)
      {
         delete pProtected;
         ProtectedList[i]=0;
         return true;
      }
   }
   return false; 
}

extern int __cdecl memcheck0(unsigned char *buffer, int count);
extern int __cdecl memcheck1(unsigned char *buffer, int count, struct mckey key);
extern int __cdecl memcheck2(unsigned char *buffer, int count, struct mckey key);
extern int __cdecl memcheck3(unsigned char *buffer, int count, struct mckey key);
extern int __cdecl memcheck4(unsigned char *buffer, int count, struct mckey key);
extern VOID memchecks_tramp(PVOID,DWORD,PCHAR,DWORD,BOOL);
extern int (__cdecl *memcheck0_tramp)(unsigned char *buffer, int count);
extern int (__cdecl *memcheck1_tramp)(unsigned char *buffer, int count, struct mckey key);
extern int (__cdecl *memcheck2_tramp)(unsigned char *buffer, int count, struct mckey key);
extern int (__cdecl *memcheck3_tramp)(unsigned char *buffer, int count, struct mckey key);
extern int (__cdecl *memcheck4_tramp)(unsigned char *buffer, int count, struct mckey key);

VOID CISXEQ::HookMemChecker(BOOL Patch)
{
    if (Patch) {

		EzDetour(__MemChecker0,memcheck0,memcheck0_tramp);
		EzDetour(__MemChecker2,memcheck2,memcheck2_tramp);
		EzDetour(__MemChecker3,memcheck3,memcheck3_tramp);
		EzDetour(__MemChecker4,memcheck4,memcheck4_tramp);
		EzDetour(__SendMessage,memchecks,memchecks_tramp);
    } else {
		EzUnDetour(__MemChecker0);
		EzUnDetour(__MemChecker2);
		EzUnDetour(__MemChecker3);
		EzUnDetour(__MemChecker4);
		EzUnDetour(__SendMessage);
    }
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

void __cdecl ProtectionRequest(ISXInterface *pClient, unsigned long MSG, void *lpData)
{
   switch(MSG)
   {
   case MEMPROTECT_PROTECT:
#define pData ((MemProtect*)lpData)
	   pData->Success=pExtension->Protect(pData->Address,pData->Length);
#undef pData
	   break;
   case MEMPROTECT_UNPROTECT:
		pExtension->UnProtect((unsigned long)lpData);
	   break;
   }
}
