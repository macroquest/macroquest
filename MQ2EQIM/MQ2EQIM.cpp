// MQ2EQIM.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.

#include "../MQ2Plugin.h"

PreSetup("MQ2EQIM");

// TODO: Buddy list window.

#define BUDDY_OFFLINE   1
#define BUDDY_EQIM      2
#define BUDDY_EQIMAFK   3
#define BUDDY_ONLINE    5
#define BUDDY_ONLINEAFK 6

PCHAR szBuddyStatus[]=
{
	"\a-wRemoved from list\ax",
	"\a-wOffline\ax",
	"\atEQIM\ax",
	"\a-tEQIM (AFK)\ax",
	"Unknown Status(4)",
	"\agPlaying\ax",
	"\a-gPlaying (AFK)\ax",
};

PCHAR szBuddyStatusNC[]=
{
	"Removed from list",
	"Offline",
	"EQIM",
	"EQIM (AFK)",
	"Unknown Status(4)",
	"Playing",
	"Playing (AFK)",
};

struct EQIMBuddy
{
	CHAR Name[MAX_STRING];
	DWORD Status;
};


CIndex<EQIMBuddy*> BuddyList(10);

int FindEQIMBuddy(PCHAR Name)
{
	for (unsigned long N = 0 ; N < BuddyList.Size ; N++)
	{
		if (EQIMBuddy *pBuddy=BuddyList[N])
		{
			if (!stricmp(pBuddy->Name,Name))
				return N;
		}
	}
	return -1;
}

class MQ2BuddyType : public MQ2Type
{
public:
	enum BuddyMembers
	{
		Name=1,
		Status=2,
		StatusID=3,
	};

	MQ2BuddyType():MQ2Type("buddy")
	{
		AddMember((DWORD)Name,"Name");
		AddMember((DWORD)Status,"Status");
		AddMember((DWORD)StatusID,"StatusID");
	}

	~MQ2BuddyType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		if (!VarPtr.Ptr)
			return false;
		EQIMBuddy *pBuddy = (EQIMBuddy*)VarPtr.Ptr;
		PMQ2TYPEMEMBER pMember=MQ2BuddyType::FindMember(Member);
		if (!pMember)
			return false;
		switch((BuddyMembers)pMember->ID)
		{
		case Name:
			Dest.Ptr=pBuddy->Name;
			Dest.Type=pStringType;
			return true;
		case Status:
			Dest.Ptr=szBuddyStatusNC[pBuddy->Status];
			Dest.Type=pStringType;
			return true;
		case StatusID:
			Dest.DWord=pBuddy->Status;
			Dest.Type=pIntType;
			return true;
		}

		return false;
	}

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		if (!VarPtr.Ptr)
			return false;
		strcpy(Destination,((EQIMBuddy*)VarPtr.Ptr)->Name);
		return true;
	}

	bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
	{
		return false;
	}
	bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
	{
		return false;
	}
};

class MQ2BuddyType *pBuddyType=0;


BOOL dataBuddies(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	Ret.DWord=BuddyList.Size;
	Ret.Type=pIntType;
	return true;
}

BOOL dataBuddy(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0]>='0' && szIndex[0]<='9')
	{
		// by number
		unsigned long N=atoi(szIndex)-1;
		if (N<BuddyList.Size && BuddyList[N])
		{
			Ret.Ptr=BuddyList[N];
			Ret.Type=pBuddyType;
			return true;
		}
	}
	else
	{
		// by name
		int N=FindEQIMBuddy(szIndex);
		if (N>=0)
		{
			Ret.Ptr=BuddyList[N];
			Ret.Type=pBuddyType;
			return true;
		}
	}
	return false;
}

VOID OnBuddyStatusChange(char *Buddy, DWORD Status);
DWORD PreDetour[10]={0};
BOOL Detoured=false;
// Called once, when the plugin is to initialize

void SetVTable(DWORD index, DWORD value)
{
	DWORD oldperm=0;
	DWORD Address=(DWORD)&(*((DWORD**)pEverQuest))[index];
	DebugSpewAlways("SetVTable writing at address %X to %X",Address,value);
  VirtualProtectEx(GetCurrentProcess(), (LPVOID)Address, 4,PAGE_EXECUTE_READWRITE, &oldperm);
 WriteProcessMemory(
  GetCurrentProcess(),
  (LPVOID)Address,
  (LPVOID)&value,
  4,
  NULL);
 VirtualProtectEx(GetCurrentProcess(), (LPVOID)Address, 4, oldperm, &oldperm);
}

DWORD GetVTable(DWORD index)
{
	DWORD Ret=(*((DWORD**)pEverQuest))[index];
	DebugSpewAlways("GetVTable(%d)=%X",index,Ret);
	return Ret;
}



PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2EQIM");

	// Add commands, macro parameters, hooks, etc.
	// AddCommand("/mycommand",MyCommand);
	// AddParm("$myparm(x)",MyParm);
	pBuddyType = new MQ2BuddyType;		
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2EQIM");

	// Remove commands, macro parameters, hooks, etc.
	// RemoveParm("$myparm(x)");
	// RemoveCommand("/mycommand");
	if (Detoured && pEverQuest)
		SetVTable(8,PreDetour[8]);
	BuddyList.Cleanup();
	delete pBuddyType;
}

// Called once directly after initialization, and then every time the gamestate changes

PLUGIN_API VOID SetGameState(DWORD GameState)
{
//	DebugSpewAlways("MQ2EQIM::SetGameState()");
	if (GameState==GAMESTATE_INGAME && !Detoured)
	{
		PreDetour[8]=GetVTable(8);
		SetVTable(8,(DWORD)OnBuddyStatusChange);
		GetVTable(8);
		Detoured=true;
	}
	else if (GameState==GAMESTATE_CHARSELECT)
	{
		BuddyList.Cleanup();
	}
}

VOID OnBuddyStatusChange(char *Buddy, DWORD Status)
{
	int N=FindEQIMBuddy(Buddy);
	if (N==-1)
	{
		EQIMBuddy *pBuddy = new EQIMBuddy;
		strcpy(pBuddy->Name,Buddy);
		pBuddy->Status=Status;
		BuddyList+=pBuddy;
	}
	else
	{
		BuddyList[N]->Status=Status;
		if (Status==0) // removed from list
		{
			delete BuddyList[N];
			BuddyList[N]=0;
		}
	}


	char out[MAX_STRING]={0};
	if (Status<=6)
	{
		sprintf(out,"\ar*\ax %s: %s",Buddy,szBuddyStatus[Status]);
	}
	else
		sprintf(out,"\ar*\ax %s: Unknown Status(%d)",Status);
	WriteChatColor(out);
}

