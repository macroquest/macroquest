/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2004 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW
#include "MQ2Main.h"
#include <map>
#include <string>
#include <algorithm>
using namespace std;

void InjectMQ2Binds(COptionsWnd *pWnd);
void EjectMQ2Binds(COptionsWnd *pWnd);

struct MQ2KeyBind
{
	char Name[32];
	KeyCombo Normal;
	KeyCombo Alt;
	fMQExecuteCmd Function;
};

CIndex<MQ2KeyBind*> BindList(10);
map<string,unsigned long> BindNameMap;

inline MQ2KeyBind *KeyBindByName(char *Name)
{
	string Lwr=Name;
	MakeLower(Lwr);
	unsigned long N=BindNameMap[Lwr];
	if (!N)
		return 0;
	return BindList[--N];
}

inline void SetKeyBindNameMap(char *Name, unsigned long Number)
{
	string Lwr=Name;
	MakeLower(Lwr);
	BindNameMap[Lwr]=Number+1;
}

inline void RemoveKeyBindNameMap(char *Name)
{
	string Lwr=Name;
	MakeLower(Lwr);
	BindNameMap[Lwr]=0;
}

class KeyPressHandlerHook
{
public:
//	bool AttachAltKeyToEqCommand_Trampoline(class KeyCombo const &,unsigned int);
//	bool AttachKeyToEqCommand_Trampoline(class KeyCombo const &,unsigned int);
//	class KeyCombo const & GetAltKeyAttachedToEqCommand_Trampoline(unsigned int);
//	class KeyCombo const & GetKeyAttachedToEqCommand_Trampoline(unsigned int);
	bool HandleKeyDown_Trampoline(class KeyCombo const &);
	bool HandleKeyUp_Trampoline(class KeyCombo const &);

	bool HandleKeyDown_Hook(class KeyCombo const &Combo)
	{
		if (!pWndMgr->HandleKeyboardMsg(Combo.Data[3],1))
			return true;
		unsigned long N;
		bool Ret=false;
		for ( N = 0 ; N < nEQMappableCommands ; N++)
		{
			if (!pKeypressHandler->CommandState[N] && (pKeypressHandler->NormalKey[N]==Combo ||		
				pKeypressHandler->AltKey[N]==Combo))
			{
				ExecuteCmd(N,1,0);
				Ret=true;
			}
		}
		for ( N = 0 ; N < BindList.Size ; N++)
		{
			if (MQ2KeyBind *pBind=BindList[N])
			{
				if (pBind->Normal==Combo || pBind->Alt==Combo)
				{
					pBind->Function(pBind->Name,true);
					Ret=true;
				}
			}
		}
		return Ret;
	}
	bool HandleKeyUp_Hook(class KeyCombo const &Combo)
	{
		if (!pWndMgr->HandleKeyboardMsg(Combo.Data[3],0))
			return true;
		unsigned long N;
		bool Ret=false;
		for ( N = 0 ; N < nEQMappableCommands ; N++)
		{
			if (pKeypressHandler->NormalKey[N]==Combo ||		
				pKeypressHandler->AltKey[N]==Combo)
			{
				ExecuteCmd(N,0,0);
				Ret=true;
			}
		}
		for ( N = 0 ; N < BindList.Size ; N++)
		{
			if (MQ2KeyBind *pBind=BindList[N])
			{
				if (pBind->Normal==Combo || pBind->Alt==Combo)
				{
					pBind->Function(pBind->Name,false);
					Ret=true;
				}
			}
		}
		return Ret;
	}
/*
	bool AttachAltKeyToEqCommand_Hook(class KeyCombo const &Combo,unsigned int nCommand)
	{
		return AttachAltKeyToEqCommand_Trampoline(Combo,nCommand);
	}
	bool AttachKeyToEqCommand_Hook(class KeyCombo const &Combo,unsigned int nCommand)
	{
		return AttachKeyToEqCommand_Trampoline(Combo,nCommand);
	}
	class KeyCombo const & GetAltKeyAttachedToEqCommand_Hook(unsigned int nCommand)
	{
		return GetAltKeyAttachedToEqCommand_Trampoline(nCommand);
	}
	class KeyCombo const & GetKeyAttachedToEqCommand_Hook(unsigned int nCommand)
	{
		return GetKeyAttachedToEqCommand_Trampoline(nCommand);
	}
/**/
};

DETOUR_TRAMPOLINE_EMPTY(bool KeyPressHandlerHook::HandleKeyDown_Trampoline(class KeyCombo const &));
DETOUR_TRAMPOLINE_EMPTY(bool KeyPressHandlerHook::HandleKeyUp_Trampoline(class KeyCombo const &));


/*
class COptionsWndHook
{
public:
	void RefreshCurrentKeyboardAssignmentList_Trampoline();
	void RefreshCurrentKeyboardAssignmentList_Hook()
	{
		RefreshCurrentKeyboardAssignmentList_Trampoline();
	}

	void InitKeyboardAssignments_Trampoline();
	void InitKeyboardAssignments_Hook()
	{
		InitKeyboardAssignments_Trampoline();
		InjectMQ2Binds((COptionsWnd*)this);
	}
};
/**/
VOID DoRangedBind(PCHAR Name,BOOL Down);

void InitializeMQ2KeyBinds()
{
/*
	if (pOptionsWnd)
	{
		InjectMQ2Binds(pOptionsWnd);
	}
/**/
	AddMQ2KeyBind("RANGED",DoRangedBind);

	EasyClassDetour(KeyPressHandler__HandleKeyDown,KeyPressHandlerHook,HandleKeyDown_Hook,bool,(class KeyCombo const &Combo),HandleKeyDown_Trampoline);
	EasyClassDetour(KeyPressHandler__HandleKeyUp,KeyPressHandlerHook,HandleKeyUp_Hook,bool,(class KeyCombo const &Combo),HandleKeyUp_Trampoline);
}

void ShutdownMQ2KeyBinds()
{
	BindList.Cleanup();
	RemoveDetour(KeyPressHandler__HandleKeyDown);
	RemoveDetour(KeyPressHandler__HandleKeyUp);
}

BOOL AddMQ2KeyBind(PCHAR name, fMQExecuteCmd Function)
{
	DebugSpew("AddMQ2KeyBind(%s)",name);
	if (KeyBindByName(name))
	{
		DebugSpew("AddMQ2KeyBind(%s) - Name already in use",name);
		return false;
	}

	MQ2KeyBind* pBind = new MQ2KeyBind;
	strncpy(pBind->Name,name,32);
	pBind->Name[31]=0;
	CHAR szBuffer[MAX_STRING]={0};
	CHAR szName[MAX_STRING]={0};
	
	sprintf(szName,"%s_%s",pBind->Name,"Nrm");
	GetPrivateProfileString("Key Binds",szName,"clear",szBuffer,MAX_STRING,gszINIFilename);	
	ParseKeyCombo(szBuffer,pBind->Normal);
	sprintf(szName,"%s_%s",pBind->Name,"Alt");
	GetPrivateProfileString("Key Binds",szName,"clear",szBuffer,MAX_STRING,gszINIFilename);	
	ParseKeyCombo(szBuffer,pBind->Alt);

	pBind->Function=Function;

	unsigned long N=BindList.GetUnused();
	BindList[N]=pBind;
	SetKeyBindNameMap(name,N);
	
	return true;
}

BOOL GetMQ2KeyBind(PCHAR name, BOOL Alt, KeyCombo &Combo)
{
	if (MQ2KeyBind *pBind=KeyBindByName(name))
	{
		if (Alt)
			Combo=pBind->Alt;
		else
			Combo=pBind->Normal;
		return true;
	}
	return false;
}

BOOL RemoveMQ2KeyBind(PCHAR name)
{
	DebugSpew("RemoveMQ2KeyBind(%s)",name);
	string Lwr=name;
	MakeLower(Lwr);
	unsigned long N=BindNameMap[Lwr];
	if (!N)
		return false;
	--N;
	if (MQ2KeyBind* pBind=BindList[N])
	{
		BindNameMap[Lwr]=0;
		BindList[N]=0;
		delete pBind;
		return true;
	}
	return false;
}

BOOL PressMQ2KeyBind(PCHAR name, BOOL Hold)
{
	if (MQ2KeyBind *pBind=KeyBindByName(name))
	{
		pBind->Function(pBind->Name,true);
		if (!Hold)
			pBind->Function(pBind->Name,false);
		return true;
	}
	return false;
}

BOOL SetMQ2KeyBind(PCHAR name, BOOL Alternate, KeyCombo &Combo)
{
	if (MQ2KeyBind *pBind=KeyBindByName(name))
	{
		CHAR szName[MAX_STRING]={0};
		CHAR szBuffer[MAX_STRING]={0};
		if (!Alternate)
		{
			sprintf(szName,"%s_Nrm",pBind->Name);
			pBind->Normal=Combo;
		}
		else
		{
			sprintf(szName,"%s_Alt",pBind->Name);
			pBind->Alt=Combo;
		}
		WritePrivateProfileString("Key Binds",szName,DescribeKeyCombo(Combo,szBuffer),gszINIFilename);
		return true;
	}
	return false;
}

VOID MQ2KeyBindCommand(PSPAWNINFO pChar, PCHAR szLine)
{
	if (szLine[0]==0)
	{
		WriteChatColor("Usage: /bind <list|eqlist|[~]name <combo|clear>>");
		return;
	}
	CHAR szBuffer[MAX_STRING];
    CHAR szArg1[MAX_STRING] = {0};
    GetArg(szArg1,szLine,1);
    PCHAR szRest = GetNextArg(szLine);
	PCHAR szArg=&szArg1[0];
	bool AltKey=false;
	if (szArg[0]=='~')
	{
		AltKey=true;
		szArg=&szArg1[1];
	}

	if (!stricmp(szArg,"list"))
	{
		// list binds
		CHAR szNormal[MAX_STRING]={0};
		CHAR szAlt[MAX_STRING]={0};
		WriteChatColor("MQ2 Binds");
		WriteChatColor("--------------");
		for (unsigned long i = 0 ; i < BindList.Size ; i++)
		{
			if (MQ2KeyBind *pBind = BindList[i])
			{
				sprintf(szArg1,"[\ay%s\ax] Nrm:\at%s\ax Alt:\at%s\ax",pBind->Name,DescribeKeyCombo(pBind->Normal,szNormal),DescribeKeyCombo(pBind->Alt,szAlt));
				WriteChatColor(szArg1);			
			}
		}
		WriteChatColor("--------------");
		WriteChatColor("End MQ2 Binds");
		return;
	}
	if (!stricmp(szArg,"eqlist"))
	{
		CHAR szNormal[MAX_STRING]={0};
		CHAR szAlt[MAX_STRING]={0};
		// list eq binds
		WriteChatColor("EQ Binds");
		WriteChatColor("--------------");
		for (unsigned long i = 0 ; i < nEQMappableCommands ; i++)
		{
			sprintf(szArg1,"[\ay%s\ax] Nrm:\at%s\ax Alt:\at%s\ax",szEQMappableCommands[i],DescribeKeyCombo(pKeypressHandler->NormalKey[i],szNormal),DescribeKeyCombo(pKeypressHandler->AltKey[i],szAlt));
			WriteChatColor(szArg1);			
		}
		WriteChatColor("--------------");
		WriteChatColor("End EQ Binds");
		return;
	}
	KeyCombo NewCombo;
	if (!ParseKeyCombo(szRest,NewCombo))
	{
		WriteChatColor("Invalid key combination");
		return;
	}

	if (SetMQ2KeyBind(szArg,AltKey,NewCombo))
	{
		MQ2KeyBind *pBind=KeyBindByName(szArg);
		sprintf(szArg1,"%s %s now bound as %s",AltKey?"Alternate":"Normal",pBind->Name,DescribeKeyCombo(NewCombo,szBuffer));
		WriteChatColor(szArg1);			
		return;
	}

	int N=FindMappableCommand(szArg);
	if (N<0)
	{
		WriteChatColor("Unknown bind command name");
		return;
	}
	// set eq bind
	if (AltKey)
	{
		//pKeypressHandler->AttachAltKeyToEqCommand(NewCombo,N);
		pKeypressHandler->AltKey[N]=NewCombo;
		if (N<gnNormalEQMappableCommands)
			pKeypressHandler->SaveKeymapping(N,NewCombo,1);
		sprintf(szArg1,"Alternate %s now bound as %s",szEQMappableCommands[N],DescribeKeyCombo(pKeypressHandler->AltKey[N],szBuffer));
		WriteChatColor(szArg1);		
	}
	else
	{
		//pKeypressHandler->AttachKeyToEqCommand(NewCombo,N);
		pKeypressHandler->NormalKey[N]=NewCombo;
		if (N<gnNormalEQMappableCommands)
			pKeypressHandler->SaveKeymapping(N,NewCombo,0);
		sprintf(szArg1,"Normal %s now bound as %s",szEQMappableCommands[N],DescribeKeyCombo(pKeypressHandler->NormalKey[N],szBuffer));
		WriteChatColor(szArg1);		
	}
}

VOID DoRangedBind(PCHAR Name,BOOL Down)
{
	if (Down && pTarget && gbRangedAttackReady)
	{
		pSpawnListTail->DoAttack(0x0B,0,pTarget);
		gbRangedAttackReady=0;
	}
}

BOOL DumpBinds(PCHAR Filename)
{
	CHAR szFilename[MAX_STRING]={0};
	sprintf(szFilename,"%s\\Configs\\%s",gszINIPath,Filename);
	if (!strchr(Filename,'.'))
		strcat(szFilename,".cfg");
	FILE *file=fopen(szFilename,"wt");
	if (!file)
	{
		return false;
	}
	CHAR szBuffer[MAX_STRING]={0};
	unsigned long N;
	for ( N = 0 ; N < nEQMappableCommands ; N++)
	{
		fprintf(file,"/bind %s %s\n",szEQMappableCommands[N],DescribeKeyCombo(pKeypressHandler->NormalKey[N],szBuffer));
		fprintf(file,"/bind ~%s %s\n",szEQMappableCommands[N],DescribeKeyCombo(pKeypressHandler->AltKey[N],szBuffer));
	}
	for ( N = 0 ; N < BindList.Size ; N++)
	{
		if (MQ2KeyBind *pBind=BindList[N])
		{
			fprintf(file,"/bind %s %s\n",pBind->Name,DescribeKeyCombo(pBind->Normal,szBuffer));
			fprintf(file,"/bind ~%s %s\n",pBind->Name,DescribeKeyCombo(pBind->Alt,szBuffer));
		}
	}
	fclose(file);
	return true;
}

/*
inline void InsertBind(COptionsWnd *pWnd, MQ2KeyBind &KeyBind)
{
}

inline void RemoveBind(COptionsWnd *pWnd, MQ2KeyBind &KeyBind)
{
}


void InjectMQ2Binds(COptionsWnd *pWnd)
{
}

void EjectMQ2Binds(COptionsWnd *pWnd)
{
}

/**/
