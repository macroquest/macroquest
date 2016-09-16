//
// ISXFullTemplate
//

// Version guideline: YYYYMMDD
// Add lettering to the end to indicate a new version on the same date, such as 20060305a, 20060305b, etc
// You can also use a standard version numbering system such as 1.00, 1.01, etc. 
// Be aware that for the versioning system, this text is simply compared to another version text from the 
// same extension to check for new versions -- if this version text comes before the compared text (in a 
// dictionary), then an update is available.  Equal text means the version is up to date.  After means this 
// is newer than the compared version.  With that said, use whatever version numbering system you'd like.
#define EXTENSION_VERSION "20060617"

#include "ISXFullTemplate.h"
#pragma comment(lib,"isxdk.lib")
// The mandatory pre-setup function.  Our name is "ISXFullTemplate", and the class is ISXFullTemplate.
// This sets up a "ModulePath" variable which contains the path to this module in case we want it,
// and a "PluginLog" variable, which contains the path and filename of what we should use for our
// debug logging if we need it.  It also sets up a variable "pExtension" which is the pointer to
// our instanced class.
ISXPreSetup("ISXFullTemplate",ISXFullTemplate);

// Basic LavishScript datatypes, these get retrieved on startup by our initialize function, so we can
// use them in our Top-Level Objects or custom datatypes
LSType *pStringType=0;
LSType *pIntType=0;
LSType *pUintType=0;
LSType *pBoolType=0;
LSType *pFloatType=0;
LSType *pTimeType=0;
LSType *pByteType=0;
LSType *pIntPtrType=0;
LSType *pBoolPtrType=0;
LSType *pFloatPtrType=0;
LSType *pBytePtrType=0;

ISInterface *pISInterface=0;
HISXSERVICE hPulseService;
HISXSERVICE hMemoryService;
HISXSERVICE hHTTPService;
HISXSERVICE hTriggerService;
HISXSERVICE hSystemService;

char FullTemplate_Version[]=EXTENSION_VERSION;

// Forward declarations of callbacks
void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl TriggerService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl HTTPService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl SystemService(bool Broadcast, unsigned int MSG, void *lpData);


// The constructor of our class.  General initialization cannot be done yet, because we're not given
// the pointer to the Inner Space interface until it is ready for us to initialize.  Just set the
// pointer we have to the interface to 0.  Initialize data members, too.
ISXFullTemplate::ISXFullTemplate(void)
{
}

// Free any remaining resources in the destructor.  This is called when the DLL is unloaded, but
// Inner Space calls the "Shutdown" function first.  Most if not all of the shutdown process should
// be done in Shutdown.
ISXFullTemplate::~ISXFullTemplate(void)
{
}

// Initialize is called by Inner Space when the extension should initialize.
bool ISXFullTemplate::Initialize(ISInterface *p_ISInterface)
{
	/* 
	 * Most of the functionality in Initialize is completely optional and could be removed or
	 * changed if so desired.  The defaults are simply a suggestion that can be easily followed.
	 */

	__try // exception handling. See __except below.
	{
		// Keep a global copy of the ISInterface pointer, which is for calling Inner Space API
		pISInterface=p_ISInterface;

		// Register the extension to make launching and updating the extension easy
		RegisterExtension();

		// retrieve basic LavishScript data types for use in ISXFullTemplate data types
		pStringType=pISInterface->FindLSType("string");
		pIntType=pISInterface->FindLSType("int");
		pUintType=pISInterface->FindLSType("uint");
		pBoolType=pISInterface->FindLSType("bool");
		pFloatType=pISInterface->FindLSType("float");
		pTimeType=pISInterface->FindLSType("time");
		pByteType=pISInterface->FindLSType("byte");
		pIntPtrType=pISInterface->FindLSType("intptr");
		pBoolPtrType=pISInterface->FindLSType("boolptr");
		pFloatPtrType=pISInterface->FindLSType("floatptr");
		pBytePtrType=pISInterface->FindLSType("byteptr");

		// Connect to commonly used Inner Space services
		ConnectServices();

		// Register LavishScript extensions (commands, aliases, data types, objects)
		RegisterCommands();
		RegisterAliases();
		RegisterDataTypes();
		RegisterTopLevelObjects();

		// Register (create) our own services
		RegisterServices();

		// Register any text triggers built into ISXFullTemplate
		RegisterTriggers();

		printf("ISXFullTemplate version %s Loaded",FullTemplate_Version);
		return true;
	}

	// Exception handling sample.  Exception handling should at LEAST be used in functions that
	// are suspected of causing user crashes.  This will help users report the crash and hopefully
	// enable the extension developer to locate and fix the crash condition.
	__except(EzCrashFilter(GetExceptionInformation(),"Crash in initialize routine")) 
	{
		TerminateProcess(GetCurrentProcess(),0);
		return 0;
	}
	/* 
	 * EzCrashFilter takes printf-style formatting after the first parameter.  The above
	 * could look something like this:
	__except(EzCrashFilter(GetExceptionInformation(),"Crash in initialize routine (%s:%d)",__FILE__,__LINE__)) 
	{
		TerminateProcess(GetCurrentProcess(),0);
		return 0;
	}
	 * of course, the FILE and LINE macros would be the location of the exception handler, not the
	 * actual crash, but you should get the idea that extra parameters can be used as if EzCrashFilter
	 * was printf.
	 *
	 * EzCrashFilter will automatically produce a crash log (CrashLog.txt) and open it in notepad for
	 * non-breakpoint exceptions (and hopefully the user will report the crash to the extension developer).  
	 * Your exception handler (the part within the {} under __except) should simply terminate the process 
	 * and return from the function as in the sample.  The return will not be hit, but the compiler will 
	 * whine without it because it doesn't automatically know that the function will not return.  
	 */

}

// shutdown sequence
void ISXFullTemplate::Shutdown()
{
	// Disconnect from services we connected to
	DisconnectServices();

	// Unregister (destroy) services we created
	UnRegisterServices();

	// Remove LavishScript extensions (commands, aliases, data types, objects)
	UnRegisterTopLevelObjects();
	UnRegisterDataTypes();
	UnRegisterAliases();
	UnRegisterCommands();
}

/*
 * Note that Initialize and Shutdown are the only two REQUIRED functions in your ISXInterface class.
 * All others are for suggested breakdown of routines, and for example purposes.
 */

void ISXFullTemplate::RegisterExtension()
{
	// add this extension to, or update this extension's info in, InnerSpace.xml.
	// This accomplishes a few things.  A) The extension can be loaded by name (ISXFullTemplate)
	// no matter where it resides on the system.  B) A script or extension can
	// check a repository to determine if there is an update available (and update
	// if necessary)

	unsigned int ExtensionSetGUID=pISInterface->GetExtensionSetGUID("ISXFullTemplate");
	if (!ExtensionSetGUID)
	{
		ExtensionSetGUID=pISInterface->CreateExtensionSet("ISXFullTemplate");
		if (!ExtensionSetGUID)
			return;
	}
	pISInterface->SetSetting(ExtensionSetGUID,"Filename",ModuleFileName);
	pISInterface->SetSetting(ExtensionSetGUID,"Path",ModulePath);
	pISInterface->SetSetting(ExtensionSetGUID,"Version",FullTemplate_Version);
}

void ISXFullTemplate::ConnectServices()
{
	// connect to any services.  Here we connect to "Pulse" which receives a
	// message every frame (after the frame is displayed) and "Memory" which
	// wraps "detours" and memory modifications
	hPulseService=pISInterface->ConnectService(this,"Pulse",PulseService);
	hMemoryService=pISInterface->ConnectService(this,"Memory",MemoryService);

	// The HTTP service handles URL retrieval
	hHTTPService=pISInterface->ConnectService(this,"HTTP",HTTPService);

	// The Triggers service handles trigger-related functions, including the
	// ability to pass text TO the trigger parser, as well as the ability to
	// add triggers.
	hTriggerService=pISInterface->ConnectService(this,"Triggers",TriggerService);

	// The System service provides general system-related services, including
	// a diagnostics message that allows the extension to insert diagnostic
	// information for the "diagnostics" command, and extension crash logs.
	hSystemService=pISInterface->ConnectService(this,"System",SystemService);
}
void ISXFullTemplate::RegisterCommands()
{
	// add any commands
//	pISInterface->AddCommand("ISXFullTemplate",CMD_ISXFullTemplate,true,false);
#define COMMAND(name,cmd,parse,hide) pISInterface->AddCommand(name,cmd,parse,hide);
#include "Commands.h"
#undef COMMAND
}

void ISXFullTemplate::RegisterAliases()
{
	// add any aliases
}

void ISXFullTemplate::RegisterDataTypes()
{
	// add any datatypes
	// pMyType = new MyType;
	// pISInterface->AddLSType(*pMyType);


#define DATATYPE(_class_,_variable_,_inherits_) _variable_ = new _class_; pISInterface->AddLSType(*_variable_); _variable_->SetInheritance(_inherits_);
#include "DataTypeList.h"
#undef DATATYPE
}

void ISXFullTemplate::RegisterTopLevelObjects()
{
	// add any Top-Level Objects
	//pISInterface->AddTopLevelObject("ISXFullTemplate",TLO_ISXFullTemplate);
#define TOPLEVELOBJECT(name,funcname) pISInterface->AddTopLevelObject(name,funcname);
#include "TopLevelObjects.h"
#undef TOPLEVELOBJECT
}

void ISXFullTemplate::RegisterServices()
{
	// register any services.  Here we demonstrate a service that does not use a
	// callback
	// set up a 1-way service (broadcast only)
//	hISXFullTemplateService=pISInterface->RegisterService(this,"ISXFullTemplate Service",0);
	// broadcast a message, which is worthless at this point because nobody will receive it
	// (nobody has had a chance to connect)
//	pISInterface->ServiceBroadcast(this,hISXFullTemplateService,ISXSERVICE_MSG+1,0);

#define SERVICE(_name_,_callback_,_variable_) _variable_=pISInterface->RegisterService(this,_name_,_callback_);
#include "Services.h"
#undef SERVICE
}

void ISXFullTemplate::RegisterTriggers()
{
	// add any Triggers
}

void ISXFullTemplate::DisconnectServices()
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
	if (hTriggerService)
	{
		pISInterface->DisconnectService(this,hTriggerService);
	}
	if (hSystemService)
	{
		pISInterface->DisconnectService(this,hSystemService);
	}
}

void ISXFullTemplate::UnRegisterCommands()
{
	// remove commands
//	pISInterface->RemoveCommand("ISXFullTemplate");
#define COMMAND(name,cmd,parse,hide) pISInterface->RemoveCommand(name);
#include "Commands.h"
#undef COMMAND
}
void ISXFullTemplate::UnRegisterAliases()
{
	// remove aliases
}
void ISXFullTemplate::UnRegisterDataTypes()
{
	// remove data types
#define DATATYPE(_class_,_variable_,_inherits_) pISInterface->RemoveLSType(*_variable_); delete _variable_;
#include "DataTypeList.h"
#undef DATATYPE

}
void ISXFullTemplate::UnRegisterTopLevelObjects()
{
	// remove Top-Level Objects
//	pISInterface->RemoveTopLevelObject("ISXFullTemplate");
#define TOPLEVELOBJECT(name,funcname) pISInterface->RemoveTopLevelObject(name);
#include "TopLevelObjects.h"
#undef TOPLEVELOBJECT
}
void ISXFullTemplate::UnRegisterServices()
{
	// shutdown our own services
//	if (hISXFullTemplateService)
//		pISInterface->ShutdownService(this,hISXFullTemplateService);

#define SERVICE(_name_,_callback_,_variable_) _variable_=pISInterface->ShutdownService(this,_variable_);
#include "Services.h"
#undef SERVICE
}

void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData)
{
	if (MSG==PULSE_PULSE)
	{
		/*
		 * "OnPulse"
		 * This message is received by the extension before each frame is
		 * displayed by the game.  This is the place to put any repeating
		 * tasks.
		 */
	}
}

void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData)
{
	// no messages are currently associated with this service (other than
	// system messages such as client disconnect), so do nothing.
}

void __cdecl TriggerService(bool Broadcast, unsigned int MSG, void *lpData)
{
	// no messages are currently associated with this service (other than
	// system messages such as client disconnect), so do nothing.
}

void __cdecl SystemService(bool Broadcast, unsigned int MSG, void *lpData)
{
	if (MSG==SYSTEMSERVICE_DIAGNOSTICS)
	{
		// Diagnostics sample
		/*
		FILE *file=(FILE*)lpData;
		fprintf(file,"ISXFullTemplate version %s\n",EXTENSION_VERSION);
		fprintf(file,"------------------------------------\n",EXTENSION_VERSION);
		fprintf(file,"Any ISXFullTemplate diagnostic information here\n");
		fprintf(file,"\n");// extra spacing for making the crash log look nice
		/**/
	}
}

void __cdecl HTTPService(bool Broadcast, unsigned int MSG, void *lpData)
{
	switch(MSG)
	{
#define pReq ((HttpFile*)lpData)
	case HTTPSERVICE_FAILURE:
		// HTTP request failed to retrieve document
		printf("ISXFullTemplate URL %s failed",pReq->URL);
		break;
	case HTTPSERVICE_SUCCESS:
		// HTTP request successfully retrieved document
		printf("ISXFullTemplate URL %s -- %d bytes",pReq->URL,pReq->Size);
		// Retrieved data buffer is pReq->pBuffer and is null-terminated
		break;
#undef pReq
	}
}

