/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

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
    BOOL State;
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

BOOL SetEQKeyBindByNumber(DWORD N, BOOL Alternate, KeyCombo &Combo)
{
    if (N<nEQMappableCommands)
    {
        if (Alternate)
            pKeypressHandler->AltKey[N] = Combo;
        else
            pKeypressHandler->NormalKey[N] = Combo;

        if(N < nNormalEQMappableCommands)
            pKeypressHandler->SaveKeymapping( N, Combo, Alternate );
        return TRUE;
    }
    return FALSE;
}

inline BOOL SetEQKeyBind(PCHAR name, BOOL Alternate, KeyCombo &Combo )
{
    return SetEQKeyBindByNumber(FindMappableCommand(name),Alternate,Combo);
} 

BOOL MQ2HandleKeyDown(class KeyCombo const &Combo)
{
    unsigned long N;
    bool Ret=false;
    for ( N = 0 ; N < nEQMappableCommands ; N++)
    {
        if (pKeypressHandler->CommandState[N]==0 && (pKeypressHandler->NormalKey[N]==Combo ||        
            pKeypressHandler->AltKey[N]==Combo))
        {
            ExecuteCmd(N,1,0);
            pKeypressHandler->CommandState[N]=1;
            Ret=true;
        }
    }
    for ( N = 0 ; N < BindList.Size ; N++)
    {
        if (MQ2KeyBind *pBind=BindList[N])
        {
            if (pBind->State==0 && (pBind->Normal==Combo || pBind->Alt==Combo))
            {
                pBind->Function(pBind->Name,true);
                pBind->State=1;
                Ret=true;
            }
        }
    }
    return Ret;
}

BOOL MQ2HandleKeyUp(class KeyCombo const &Combo)
{
    unsigned long N;
    bool Ret=false;
    for ( N = 0 ; N < nEQMappableCommands ; N++)
    {
        if (pKeypressHandler->CommandState[N] && (pKeypressHandler->NormalKey[N].Data[3]==Combo.Data[3] ||        
            pKeypressHandler->AltKey[N].Data[3]==Combo.Data[3]))
        {
            ExecuteCmd(N,0,0);
            pKeypressHandler->CommandState[N]=0;
            Ret=true;
        }
    }
    for ( N = 0 ; N < BindList.Size ; N++)
    {
        if (MQ2KeyBind *pBind=BindList[N])
        {
            if (pBind->State==1 && (pBind->Normal.Data[3]==Combo.Data[3] || pBind->Alt.Data[3]==Combo.Data[3]))
            {
                pBind->Function(pBind->Name,false);
                pBind->State=0;
                Ret=true;
            }
        }
    }
    return Ret;
}

class KeypressHandlerHook
{
public:
    void ClearCommandStateArray_Trampoline();
    void ClearCommandStateArray_Hook()
    {
        unsigned long N;
        for (N = 0 ; N < BindList.Size ; N++)
            if (MQ2KeyBind *pBind=BindList[N])
            {
                pBind->State=false;
            }
            ZeroMemory(&pKeypressHandler->CommandState[0],sizeof(pKeypressHandler->CommandState));
    }


    bool HandleKeyDown_Trampoline(class KeyCombo const &);
    bool HandleKeyUp_Trampoline(class KeyCombo const &);

    bool HandleKeyDown_Hook(class KeyCombo const &Combo)
    {
        if (!pWndMgr->HandleKeyboardMsg(Combo.Data[3],1))
            return true;
        return (MQ2HandleKeyDown(Combo)!=0);
    }
    bool HandleKeyUp_Hook(class KeyCombo const &Combo)
    {
        bool Ret=false;
        if (!pWndMgr->HandleKeyboardMsg(Combo.Data[3],0))
            Ret=true;
        return (MQ2HandleKeyUp(Combo) || Ret);
    }
};

DETOUR_TRAMPOLINE_EMPTY(void KeypressHandlerHook::ClearCommandStateArray_Trampoline());
DETOUR_TRAMPOLINE_EMPTY(bool KeypressHandlerHook::HandleKeyDown_Trampoline(class KeyCombo const &));
DETOUR_TRAMPOLINE_EMPTY(bool KeypressHandlerHook::HandleKeyUp_Trampoline(class KeyCombo const &));


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
void DoRangedBind(PCHAR Name,BOOL Down);

void InitializeMQ2KeyBinds()
{
    /*
    if (pOptionsWnd)
    {
    InjectMQ2Binds(pOptionsWnd);
    }
    /**/
    AddMQ2KeyBind("RANGED",DoRangedBind);

    EzDetourwName(KeypressHandler__ClearCommandStateArray,&KeypressHandlerHook::ClearCommandStateArray_Hook,&KeypressHandlerHook::ClearCommandStateArray_Trampoline,"KeypressHandler__ClearCommandStateArray");
    EzDetourwName(KeypressHandler__HandleKeyDown,&KeypressHandlerHook::HandleKeyDown_Hook,&KeypressHandlerHook::HandleKeyDown_Trampoline,"KeypressHandler__HandleKeyDown");
    EzDetourwName(KeypressHandler__HandleKeyUp,&KeypressHandlerHook::HandleKeyUp_Hook,&KeypressHandlerHook::HandleKeyUp_Trampoline,"KeypressHandler__HandleKeyUp");
}

void ShutdownMQ2KeyBinds()
{
    BindList.Cleanup();
    RemoveDetour(KeypressHandler__ClearCommandStateArray);
    RemoveDetour(KeypressHandler__HandleKeyDown);
    RemoveDetour(KeypressHandler__HandleKeyUp);
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
    pBind->State=false;
    strncpy_s(pBind->Name,name,32);
    pBind->Name[31]=0;
    char szBuffer[MAX_STRING]={0};
    char szName[MAX_STRING]={0};

    sprintf_s(szName,"%s_%s",pBind->Name,"Nrm");
    GetPrivateProfileString("Key Binds",szName,"clear",szBuffer,MAX_STRING,gszINIFilename);    
    ParseKeyCombo(szBuffer,pBind->Normal);
    sprintf_s(szName,"%s_%s",pBind->Name,"Alt");
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
        char szName[MAX_STRING]={0};
        char szBuffer[MAX_STRING]={0};
        if (!Alternate)
        {
            sprintf_s(szName,"%s_Nrm",pBind->Name);
            pBind->Normal=Combo;
        }
        else
        {
            sprintf_s(szName,"%s_Alt",pBind->Name);
            pBind->Alt=Combo;
        }
        WritePrivateProfileString("Key Binds",szName,DescribeKeyCombo(Combo,szBuffer, sizeof(szBuffer)),gszINIFilename);
        return true;
    }
    return false;
}

void MQ2KeyBindCommand(PSPAWNINFO pChar, PCHAR szLine)
{
    if (szLine[0]==0)
    {
        WriteChatColor("Usage: /bind <list|eqlist|[~]name <combo|clear>>");
        return;
    }
	char szArg1[MAX_STRING] = { 0 };
    GetArg(szArg1,szLine,1);
    PCHAR szRest = GetNextArg(szLine);
    PCHAR szArg=&szArg1[0];
    bool AltKey=false;
    if (szArg[0]=='~')
    {
        AltKey=true;
        szArg=&szArg1[1];
    }
    unsigned long i;
    if (!_stricmp(szArg,"list"))
    {
        // list binds
        char szNormal[MAX_STRING]={0};
        char szAlt[MAX_STRING]={0};
        WriteChatColor("MQ2 Binds");
        WriteChatColor("--------------");
        for (i = 0 ; i < BindList.Size ; i++)
        {
            if (MQ2KeyBind *pBind = BindList[i])
            {
                sprintf_s(szArg1,"[\ay%s\ax] Nrm:\at%s\ax Alt:\at%s\ax",pBind->Name,DescribeKeyCombo(pBind->Normal,szNormal, sizeof(szNormal)),DescribeKeyCombo(pBind->Alt,szAlt, sizeof(szAlt)));
                WriteChatColor(szArg1);            
            }
        }
        WriteChatColor("--------------");
        WriteChatColor("End MQ2 Binds");
        return;
    }
    if (!_stricmp(szArg,"eqlist"))
    {
        char szNormal[MAX_STRING]={0};
        char szAlt[MAX_STRING]={0};
        // list eq binds
        WriteChatColor("EQ Binds");
        WriteChatColor("--------------");
		//ok first of all, the 0x11111111 constant for ac1 is not even used anymore they stopped using those ones years ago
		//its just left in there, legacy code, I suppose it would cause more problems removing it, than leaving it, and if a eq dev sees this, please
		//just leave that stuff alone because i dont want to have to worry about where it went or if its active again. -eqmule
		//second, even though its not active, now that eqgame uses aslr, we have to take that into account and actually add load address to the constant, thus the line below:

		//anyway... from now on we will just use the size of the image... not reliable to have it hardcoded
        for (i = 0 ; i < nEQMappableCommands ; i++)
        {
            if((DWORD)szEQMappableCommands[i] == 0 || (DWORD)szEQMappableCommands[i] > g_eqgameimagesize)
                continue;
            sprintf_s(szArg1,"[\ay%s\ax] Nrm:\at%s\ax Alt:\at%s\ax",szEQMappableCommands[i],DescribeKeyCombo(pKeypressHandler->NormalKey[i],szNormal, sizeof(szNormal)),DescribeKeyCombo(pKeypressHandler->AltKey[i],szAlt, sizeof(szAlt)));
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

    if (!_stricmp(szArg,"clearcombo")) 
    {
        KeyCombo ClearCombo;
        // mq2 binds
        for (i = 0; i < BindList.Size; i++) 
        {
            MQ2KeyBind* pBind = BindList[i];
            if (pBind) 
            {
                if (pBind->Alt == NewCombo && SetMQ2KeyBind(pBind->Name,true,ClearCombo)) 
                {
                    sprintf_s(szArg1,"Alternate %s cleared",pBind->Name);
                    WriteChatColor(szArg1);
                }
                if (pBind->Normal == NewCombo && SetMQ2KeyBind(pBind->Name,false,ClearCombo))
                {
                    sprintf_s(szArg1,"Normal %s cleared",pBind->Name);
                    WriteChatColor(szArg1);
                }
            }
        }
        // eq binds
        for (i = 0; i < nEQMappableCommands; i++) 
        {
            if((DWORD)szEQMappableCommands[i] == 0 || (DWORD)szEQMappableCommands[i] > g_eqgameimagesize)
                continue;
            if (pKeypressHandler->AltKey[i] == NewCombo && SetEQKeyBindByNumber(i,true,ClearCombo)) 
            {
                sprintf_s(szArg1,"Alternate %s cleared",szEQMappableCommands[i] );
                WriteChatColor(szArg1);
            }
            if (pKeypressHandler->NormalKey[i] == NewCombo && SetEQKeyBindByNumber(i,false,ClearCombo))
            {
                sprintf_s(szArg1,"Normal %s cleared", szEQMappableCommands[i]);
                WriteChatColor(szArg1);
            }
        }
        return;
    } 


	char szBuffer[MAX_STRING] = { 0 };
    if (SetMQ2KeyBind(szArg,AltKey,NewCombo))
    {
        MQ2KeyBind *pBind=KeyBindByName(szArg);
        sprintf_s(szArg1,"%s %s now bound as %s",AltKey?"Alternate":"Normal",pBind->Name,DescribeKeyCombo(NewCombo,szBuffer, sizeof(szBuffer)));
        WriteChatColor(szArg1);            
        return;
    }

    int N=FindMappableCommand(szArg);
    if (N<0)
    {
        WriteChatColor("Unknown bind command name");
        return;
    }
	else if (N>nNormalEQMappableCommands)
	{
		WriteChatColor("Unmappable bind command name");
		return;
	}


    if (SetEQKeyBindByNumber(N,AltKey,NewCombo))
    {
        sprintf_s( szArg1,"%s %s now bound as %s", 
        (AltKey)?("Alternate"):("Normal"), 
        szEQMappableCommands[N],
        DescribeKeyCombo((AltKey)?(pKeypressHandler->AltKey[N]):(pKeypressHandler->NormalKey[N]),szBuffer, sizeof(szBuffer)));
    }
}

void DoRangedBind(PCHAR Name,BOOL Down)
{
    if (Down && pTarget && gbRangedAttackReady)
    {
        pLocalPlayer->DoAttack(0x0B,0,pTarget);
        gbRangedAttackReady=0;
    }
}

BOOL DumpBinds(PCHAR Filename)
{
    char szFilename[MAX_STRING]={0};
    sprintf_s(szFilename,"%s\\Configs\\%s",gszINIPath,Filename);
    if (!strchr(Filename,'.'))
        strcat_s(szFilename,".cfg");
	FILE *file = 0;
	errno_t err = fopen_s(&file,szFilename, "wt");
    if (err)
    {
        return false;
    }
    char szBuffer[MAX_STRING]={0};
    unsigned long N;
    for ( N = 0 ; N < nEQMappableCommands ; N++)
    {
        if((DWORD)szEQMappableCommands[N] == 0 || (DWORD)szEQMappableCommands[N] > g_eqgameimagesize)
            continue;
        fprintf(file,"/bind %s %s\n",szEQMappableCommands[N],DescribeKeyCombo(pKeypressHandler->NormalKey[N],szBuffer, sizeof(szBuffer)));
        fprintf(file,"/bind ~%s %s\n",szEQMappableCommands[N],DescribeKeyCombo(pKeypressHandler->AltKey[N],szBuffer, sizeof(szBuffer)));
    }
    for ( N = 0 ; N < BindList.Size ; N++)
    {
        if (MQ2KeyBind *pBind=BindList[N])
        {
            fprintf(file,"/bind %s %s\n",pBind->Name,DescribeKeyCombo(pBind->Normal,szBuffer, sizeof(szBuffer)));
            fprintf(file,"/bind ~%s %s\n",pBind->Name,DescribeKeyCombo(pBind->Alt,szBuffer, sizeof(szBuffer)));
        }
    }
    fclose(file);
    return true;
}
