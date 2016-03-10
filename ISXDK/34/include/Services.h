#pragma once
#pragma warning( push )
#pragma warning( disable : 4505 )

#define ISXSERVICE_MSG (1000)

// Services Messages - General (used for all services)
#define ISXSERVICE_CLIENTADDED					1
#define ISXSERVICE_CLIENTREMOVED				2
#define ISXSERVICE_DISCONNECTED					3

// Service Messages - Service-specific (will be reused for other services)
// System Service "Pulse"
#define PULSE_PULSE								(ISXSERVICE_MSG+1)
#define PULSE_PREFRAME							(ISXSERVICE_MSG+2)

// System Service "Console"
#define CONSOLE_OUTPUT							(ISXSERVICE_MSG+1)
#define CONSOLE_OUTPUT_WITHCODES				(ISXSERVICE_MSG+2)

// System Service "Memory"
#define MEM_DETOUR								((ISXSERVICE_MSG)+1)
#define MEM_MODIFY								((ISXSERVICE_MSG)+2)
#define MEM_RELEASEDETOUR						((ISXSERVICE_MSG)+3)
#define MEM_RELEASEMODIFY						((ISXSERVICE_MSG)+4)
#define MEM_ISDETOURED							((ISXSERVICE_MSG)+5)
#define MEM_ISMODIFIED							((ISXSERVICE_MSG)+6)
#define MEM_ENABLEPROTECTION					((ISXSERVICE_MSG)+7)
#define MEM_DISABLEPROTECTION					((ISXSERVICE_MSG)+8)
#define MEM_DETOURAPI							((ISXSERVICE_MSG)+9)
#define MEM_RELEASEAPIDETOUR					((ISXSERVICE_MSG)+10)
#define MEM_ISAPIDETOURED						((ISXSERVICE_MSG)+11)

// Custom Service for memory protection
#define MEMPROTECT_PROTECT							((ISXSERVICE_MSG)+1)
#define MEMPROTECT_UNPROTECT						((ISXSERVICE_MSG)+2)

// System Service "HTTP"
#define HTTPSERVICE_REQUEST							((ISXSERVICE_MSG)+1)
#define HTTPSERVICE_FAILURE							((ISXSERVICE_MSG)+2)
#define HTTPSERVICE_SUCCESS							((ISXSERVICE_MSG)+3)

// System Service "Services"
#define SERVICES_ADDED							((ISXSERVICE_MSG)+1)
#define SERVICES_REMOVED						((ISXSERVICE_MSG)+2)

// System Service "Extensions"
#define EXTENSIONS_ADDED							((ISXSERVICE_MSG)+1)
#define EXTENSIONS_REMOVED							((ISXSERVICE_MSG)+2)

// System Service "Triggers"
#define TRIGGERS_ADD									((ISXSERVICE_MSG)+1)
#define TRIGGERS_REMOVE									((ISXSERVICE_MSG)+2)
#define TRIGGERS_PROCESS								((ISXSERVICE_MSG)+3)
#define TRIGGERS_GETLINE								((ISXSERVICE_MSG)+4)

// System Service "Files"
#define FILES_OPEN									((ISXSERVICE_MSG)+1)
#define FILES_TRACKEDREAD							((ISXSERVICE_MSG)+2)
#define FILES_TRACKEDWRITE							((ISXSERVICE_MSG)+3)
#define FILES_TRACKEDCLOSE							((ISXSERVICE_MSG)+4)
#define FILES_OVERLAPPEDREAD						((ISXSERVICE_MSG)+5)
#define FILES_OVERLAPPEDWRITE						((ISXSERVICE_MSG)+6)


// System Service "Scripts"
#define SCRIPTS_ADDED								((ISXSERVICE_MSG)+1)
#define SCRIPTS_REMOVED								((ISXSERVICE_MSG)+2)

// System Service "Software Cursor"
#define SOFTWARECURSOR_ENABLE						((ISXSERVICE_MSG)+1)
#define SOFTWARECURSOR_DISABLE						((ISXSERVICE_MSG)+2)

// System Service "Script Engines"
#define SCRIPTENGINE_ADD							((ISXSERVICE_MSG)+1)
#define SCRIPTENGINE_REMOVE							((ISXSERVICE_MSG)+2)
#define SCRIPTENGINE_ADDFILEEXT						((ISXSERVICE_MSG)+3)
#define SCRIPTENGINE_REMOVEFILEEXT					((ISXSERVICE_MSG)+4)
#define SCRIPTENGINE_SCRIPTBEGINS					((ISXSERVICE_MSG)+5)
#define SCRIPTENGINE_SCRIPTENDS						((ISXSERVICE_MSG)+6)
#define SCRIPTENGINE_ADDED							((ISXSERVICE_MSG)+7)
#define SCRIPTENGINE_REMOVED						((ISXSERVICE_MSG)+8)

// System Service "Modules"
#define MODULESERVICE_LOADLIBRARY					((ISXSERVICE_MSG)+1)
#define MODULESERVICE_FREELIBRARY					((ISXSERVICE_MSG)+2)

// System Service "System"
#define SYSTEMSERVICE_DIAGNOSTICS					((ISXSERVICE_MSG)+1)
#define SYSTEMSERVICE_CRASHLOG						((ISXSERVICE_MSG)+2)

struct _SystemCrashLog
{
	_EXCEPTION_POINTERS *pExceptionInfo;
	const char *Identifier;
};

static bool IS_SystemCrashLog(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hSystemService, _EXCEPTION_POINTERS *pExceptionInfo, const char *CrashIdentifier)
{
	_SystemCrashLog Data;
	Data.pExceptionInfo=pExceptionInfo;
	Data.Identifier=CrashIdentifier;
	return pISInterface->ServiceRequest(pClient,hSystemService,SYSTEMSERVICE_CRASHLOG,&Data);
}


struct _ModuleServiceLibrary
{
	const char *Library;
	HMODULE hModule;
};

struct _ScriptEngineScriptBegins
{
	class ISXScriptEngine *pInterface;
	const char *ScriptName;
};
struct _ScriptEngineScriptEnds
{
	class ISXScriptEngine *pInterface;
	const char *ScriptName;
};

struct _ScriptEngineFileExt
{
	class ISXScriptEngine *pInterface;
	const char *Extension;
};


static bool IS_ScriptEngineAdd(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hScriptEngineService, class ISXScriptEngine *pInterface)
{
	return pISInterface->ServiceRequest(pClient,hScriptEngineService,SCRIPTENGINE_ADD,pInterface);
}
static bool IS_ScriptEngineRemove(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hScriptEngineService, class ISXScriptEngine *pInterface)
{
	return pISInterface->ServiceRequest(pClient,hScriptEngineService,SCRIPTENGINE_REMOVE,pInterface);
}
static bool IS_ScriptEngineScriptBegins(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hScriptEngineService, class ISXScriptEngine *pInterface, const char *Name)
{
	_ScriptEngineScriptBegins Data;
	Data.pInterface=pInterface;
	Data.ScriptName=Name;
	return pISInterface->ServiceRequest(pClient,hScriptEngineService,SCRIPTENGINE_SCRIPTBEGINS,&Data);
}
static bool IS_ScriptEngineScriptEnds(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hScriptEngineService, class ISXScriptEngine *pInterface, const char *Name)
{
	_ScriptEngineScriptBegins Data;
	Data.pInterface=pInterface;
	Data.ScriptName=Name;
	return pISInterface->ServiceRequest(pClient,hScriptEngineService,SCRIPTENGINE_SCRIPTENDS,&Data);
}
static bool IS_ScriptEngineAddFileExt(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hScriptEngineService, class ISXScriptEngine *pInterface, const char *Ext)
{
	_ScriptEngineFileExt Data;
	Data.pInterface=pInterface;
	Data.Extension=Ext;
	return pISInterface->ServiceRequest(pClient,hScriptEngineService,SCRIPTENGINE_ADDFILEEXT,&Data);
}
static bool IS_ScriptEngineRemoveFileExt(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hScriptEngineService, class ISXScriptEngine *pInterface, const char *Ext)
{
	_ScriptEngineFileExt Data;
	Data.pInterface=pInterface;
	Data.Extension=Ext;
	return pISInterface->ServiceRequest(pClient,hScriptEngineService,SCRIPTENGINE_REMOVEFILEEXT,&Data);
}



static bool IS_SoftwareCursorEnable(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hSoftwareCursorService, class ISXSoftwareCursorInterface *pInterface)
{
   return pISInterface->ServiceRequest(pClient,hSoftwareCursorService,SOFTWARECURSOR_ENABLE,pInterface);
}

static bool IS_SoftwareCursorDisable(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hSoftwareCursorService)
{
   return pISInterface->ServiceRequest(pClient,hSoftwareCursorService,SOFTWARECURSOR_DISABLE,0);
}

struct _FileOpen
{
	// out
	const char *FileName;

	// in
	bool bTrack;
};

struct _FileIO
{
	// out
	const char *FileName;
	const void *Buffer;
	unsigned int Length;
	unsigned int Position;
};

struct _FileOverlappedIO
{
	// out
	HANDLE hFile;
	const void *Buffer;
	DWORD nLength;
	DWORD *nActualTransfer;
	LPOVERLAPPED lpOverlapped;
};

struct _EventSet
{
	char *Name;
	char *Command; // may be NULL
};

struct _TriggerAdd
{
	// in
	const char *Text;
	fBlechCallback Callback;
	void *pUserData;

	// out
	unsigned int ID;
};

struct _TriggerGetLine
{
	// out
	const char *Text;
};

struct HttpRequest
{
	const char *URL;
	void *pData;
};

struct HttpFile
{
	const char *URL;
	char *pBuffer;
	size_t Size;
	void *pData;
};

static bool IS_HttpRequest(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hHttpService, const char *URL, void *pData)
{
	HttpRequest Temp;
	Temp.URL=URL;
	Temp.pData=pData;
   return pISInterface->ServiceRequest(pClient,hHttpService,HTTPSERVICE_REQUEST,&Temp);
}

struct MemIs
{
	UINT_PTR Address;
	bool Is;
};

struct MemProtect
{// this struct is used only by memory protection extensions, and only for MEMPROTECT_PROTECT
	UINT_PTR Address;  // in
	size_t Length;	// in
	bool Success;			// out
	const void *OriginalData;    // in
};

struct MemDetour
{
   UINT_PTR Address;   // in
   void *Detour;         // in
   void *Trampoline;      // in
   bool Success;         // out
};

struct MemDetourAPI
{
	void *Detour;		// in
	const char *DLLName;		// in
	const char *FunctionName; // in
	unsigned int FunctionOrdinal;	// in
	bool Success; // out
};

struct MemModify
{
   UINT_PTR Address;   // in
   void *NewData;         // in
   size_t Length;   // in
   bool Reverse;         // in
   bool Success;         // out
};

#define ISDetourAPI(_hMemoryService_,_Detour_,_DLLName_,_FunctionName_,_FunctionOrdinal_) IS_DetourAPI(this,pISInterface,_hMemoryService_,_Detour_,_DLLName_,_FunctionName_,_FunctionOrdinal_)
static bool IS_DetourAPI(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hMemoryService, ...)
{
	va_list ap;
	int nArgs = 0;
	int i = 0;
	unsigned int Args[5];

	va_start(ap, hMemoryService);
	while (i != -1)
	{
		if (nArgs < 5)
		{
			Args[nArgs] = i;
			nArgs++;
		}
		
		i = va_arg(ap, int);
	}
	va_end(ap);
	void *Detour;
	char *DLLName;
	char *FunctionName;
	unsigned int FunctionOrdinal;
	if (nArgs == 5)
	{
		Detour = (PBYTE)Args[1];
		DLLName = (char *)Args[2];
		FunctionName = (char *)Args[3];
		FunctionOrdinal = (unsigned int)Args[4];
	}
	else 
	{
		return false;
	}

   MemDetourAPI data;
   data.Detour=Detour;
   data.DLLName=DLLName;
   data.FunctionName=FunctionName;
   data.FunctionOrdinal=FunctionOrdinal;
   data.Success=false;
   return pISInterface->ServiceRequest(pClient,hMemoryService,MEM_DETOURAPI,&data) && data.Success;
}

#define ISUnDetourAPI(_hMemoryService_,Address) IS_UnDetourAPI(this,pISInterface,_hMemoryService_,(UINT_PTR)Address)
static inline void IS_UnDetourAPI(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hMemoryService, UINT_PTR Address)
{
   pISInterface->ServiceRequest(pClient,hMemoryService,MEM_RELEASEAPIDETOUR,(void*)Address);
}

#define ISDetour(_hMemoryService_, Address, Detour, Trampoline) IS_Detour(this,pISInterface,_hMemoryService_,(UINT_PTR)Address,Detour,Trampoline)
static bool IS_Detour(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hMemoryService, UINT_PTR Address,...)
{
	va_list ap;
	int nArgs = 0;
	int i = 0;
	unsigned int Args[3];

	va_start(ap, Address);
	while (i != -1)
	{
		if (nArgs < 3)
		{
			Args[nArgs] = i;
			nArgs++;
		}
		
		i = va_arg(ap, int);
	}
	va_end(ap);
	void *Detour;
	void *Trampoline;
	if (nArgs == 3)
	{
		Detour = (PBYTE)Args[1];
		Trampoline = (PBYTE)Args[2];
	}
	else 
	{
		return false;
	}

   MemDetour data;
   data.Address=Address;
   data.Detour=Detour;
   data.Trampoline=Trampoline;
   data.Success=false;
   return pISInterface->ServiceRequest(pClient,hMemoryService,MEM_DETOUR,&data) && data.Success;
}
#define MemoryModify(_hMemoryService_,Address,NewData,Length,Reverse) Memory_Modify(this,pISInterface,_hMemoryService_,(UINT_PTR)Address,NewData,Length,Reverse)
static inline bool Memory_Modify(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hMemoryService, UINT_PTR Address, void *NewData, size_t Length, bool Reverse)
{
   MemModify data;
   data.Address=Address;
   data.NewData=NewData;
   data.Length=Length;
   data.Reverse=Reverse;
   data.Success=false;
   return pISInterface->ServiceRequest(pClient,hMemoryService,MEM_MODIFY,&data) && data.Success;
}
#define ISUnDetour(_hMemoryService_,Address) IS_UnDetour(this,pISInterface,_hMemoryService_,(UINT_PTR)Address)
static inline void IS_UnDetour(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hMemoryService, UINT_PTR Address)
{
   pISInterface->ServiceRequest(pClient,hMemoryService,MEM_RELEASEDETOUR,(void*)Address);
}
#define MemoryUnModify(_hMemoryService_,Address) Memory_UnModify(this,pISInterface,_hMemoryService_,(UINT_PTR)Address)
static inline void Memory_UnModify(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hMemoryService, UINT_PTR Address)
{
   pISInterface->ServiceRequest(pClient,hMemoryService,MEM_RELEASEMODIFY,(void*)Address);
}

#define ISAddTrigger(_hTriggerService_,Text,Callback,pUserData) IS_AddTrigger(this,pISInterface,_hTriggerService_,Text,Callback,pUserData)
static inline unsigned int IS_AddTrigger(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hTriggerService, const char *Text, fBlechCallback Callback, void *pUserData=0)
{
	_TriggerAdd data;
	data.Callback=Callback;
	data.ID=0;
	data.pUserData=pUserData;
	data.Text=Text;
	pISInterface->ServiceRequest(pClient,hTriggerService,TRIGGERS_ADD,&data);
	return data.ID;
}

#define ISRemoveTrigger(_hTriggerService_,ID) IS_RemoveTrigger(this,pISInterface,_hTriggerService_,ID)
static inline void IS_RemoveTrigger(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hTriggerService, unsigned int ID)
{
	pISInterface->ServiceRequest(pClient,hTriggerService,TRIGGERS_REMOVE,(void*)ID);
}

#define ISCheckTriggers(_hTriggerService_,Text) IS_CheckTriggers(this,pISInterface,_hTriggerService_,Text)
static inline void IS_CheckTriggers(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hTriggerService, const char *Text)
{
	pISInterface->ServiceRequest(pClient,hTriggerService,TRIGGERS_PROCESS,(void*)Text);
}

#define ISGetTriggerLine(_hTriggerService_) IS_GetTriggerLine(this,pISInterface,_hTriggerService_)
static inline const char *IS_GetTriggerLine(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hTriggerService)
{
	_TriggerGetLine data;
	data.Text=0;
	if (!pISInterface->ServiceRequest(pClient,hTriggerService,TRIGGERS_GETLINE,&data))
		return "";
	return data.Text;
}

/*
#define ISSetEvent(_hEventService_,Name,Command) IS_SetEvent(this,pISInterface,_hEventService_,Name,Command)
static inline void IS_SetEvent(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hEventService, char *Name, char *Command)
{
	_EventSet data;
	data.Command=Command;
	data.Name=Name;
	pISInterface->ServiceRequest(pClient,hEventService,EVENTS_SET,&data);
}

#define ISRemoveEvent(_hEventService_,Name) IS_RemoveEvent(this,pISInterface,_hEventService_,Name)
static inline void IS_RemoveEvent(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hEventService, char *Name)
{
	pISInterface->ServiceRequest(pClient,hEventService,EVENTS_REMOVE,(void*)Name);
}

#define ISExecuteEvent(_hEventService_,Name) IS_ExecuteEvent(this,pISInterface,_hEventService_,Name)
static inline void IS_ExecuteEvent(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hEventService, char *Name)
{
	pISInterface->ServiceRequest(pClient,hEventService,EVENTS_EXECUTE,(void*)Name);
}
/**/

#pragma warning( pop )
