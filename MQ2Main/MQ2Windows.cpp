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

map<string,unsigned long> WindowMap;

struct _WindowInfo
{
	char Name[128];
	CXWnd *pWnd;
	CXWnd **ppWnd;
};

CIndex <_WindowInfo*> WindowList(10);



bool GenerateMQUI();
void DestroyMQUI();

class SetScreenHook
{
public:
	void SetScreen_Detour(class CXStr *pName)
	{
		CHAR Name[MAX_STRING]={0};
		GetCXStr((PCXSTR)pName,Name,MAX_STRING);
		string WindowName=Name;
		MakeLower((WindowName));

		unsigned long N=WindowMap[WindowName];
		if (N)
		{
			N--;
			_WindowInfo *pWnd = WindowList[N];
			pWnd->pWnd=(CXWnd*)this;
			pWnd->ppWnd=0;
			DebugSpew("Updating WndNotification target '%s'",Name);
		}
		else
		{
			_WindowInfo *pWnd = new _WindowInfo;
			strcpy(pWnd->Name,Name);
			pWnd->pWnd=(CXWnd*)this;
			pWnd->ppWnd=0;
			
			N=WindowList.GetUnused();
			WindowList[N]=pWnd;

			WindowMap[WindowName]=N+1;
			DebugSpew("Adding WndNotification target '%s'",Name);
		}
		SetScreen_Trampoline(pName);
	}
	void SetScreen_Trampoline(class CXStr*);
};
DETOUR_TRAMPOLINE_EMPTY(void SetScreenHook::SetScreen_Trampoline(class CXStr*));

class CXWndManagerHook
{
public:
	int RemoveWnd_Detour(class CXWnd *pWnd)
	{
		if (pWnd)
		{
			for (unsigned long N = 0 ; N < WindowList.Size ; N++)
				if (_WindowInfo* pInfo=WindowList[N])
				{
					if (pWnd==pInfo->pWnd)
					{
						DebugSpew("Removing WndNotification target '%s'",pInfo->Name);
						string Name=pInfo->Name;
						MakeLower(Name);
						WindowMap[Name]=0;
						delete pInfo;
						WindowList[N]=0;
						break;
					}
				}
		}
		return RemoveWnd_Trampoline(pWnd);
	}
	int RemoveWnd_Trampoline(class CXWnd *);

};
DETOUR_TRAMPOLINE_EMPTY(int CXWndManagerHook::RemoveWnd_Trampoline(class CXWnd *));


class CXMLSOMDocumentBaseHook
{
public:
	int XMLRead(CXStr *A, CXStr *B, CXStr *C)
	{
		char Temp[256]={0};
		GetCXStr((PCXSTR)C,Temp,256);
		DebugSpew("XMLRead(%s)",Temp);
		if (!stricmp("EQUI.xml",Temp))
		{
			if (GenerateMQUI())
			{
				SetCXStr((PCXSTR*)&C,"MQUI.xml");
				int Ret=XMLRead_Trampoline(A,B,C);
				DestroyMQUI();
				return Ret;
			}
		}
		return XMLRead_Trampoline(A,B,C);
	}
	int XMLRead_Trampoline(CXStr *A, CXStr *B, CXStr *C);
};
DETOUR_TRAMPOLINE_EMPTY(int CXMLSOMDocumentBaseHook::XMLRead_Trampoline(CXStr *A, CXStr *B, CXStr *C)); 



VOID ListWindows(PSPAWNINFO pChar, PCHAR szLine);
VOID WndNotify(PSPAWNINFO pChar, PCHAR szLine);

void InitializeMQ2Windows()
{
	
	DebugSpew("Initializing MQ2 Windows");

	EasyClassDetour(CXMLSOMDocumentBase__XMLRead,CXMLSOMDocumentBaseHook,XMLRead,int,(CXStr *A, CXStr *B, CXStr *C),XMLRead_Trampoline);

	EasyClassDetour(CSidlScreenWnd__SetScreen,SetScreenHook,SetScreen_Detour,void,(class CXStr *),SetScreen_Trampoline);
	EasyClassDetour(CXWndManager__RemoveWnd,CXWndManagerHook,RemoveWnd_Detour,int,(class CXWnd *),RemoveWnd_Trampoline);

	AddCommand("/windows",ListWindows,false,true,false);
	AddCommand("/notify",WndNotify,false,true,false);
}

void ShutdownMQ2Windows()
{
	DebugSpew("Shutting down MQ2 Windows");
	RemoveCommand("/windows");
	RemoveCommand("/notify");
	RemoveDetour(CXMLSOMDocumentBase__XMLRead);
	RemoveDetour(CSidlScreenWnd__SetScreen);
	RemoveDetour(CXWndManager__RemoveWnd);
	WindowList.Cleanup();
}

bool GenerateMQUI()
{
	// create EverQuest\uifiles\default\MQUI.xml
	if (!pXMLFiles)
	{
		DebugSpew("GenerateMQUI::Not Generating MQUI.xml, no files in our list");
		return false;
	}
	DebugSpew("GenerateMQUI::Generating MQUI.xml");
	CHAR szOrgFilename[MAX_PATH]={0};
	CHAR szFilename[MAX_PATH]={0};
	sprintf(szOrgFilename,"%s\\uifiles\\default\\EQUI.xml",gszEQPath);
	sprintf(szFilename,"%s\\uifiles\\default\\MQUI.xml",gszEQPath);
	char Buffer[2048];
	FILE *forg=fopen(szOrgFilename,"rt");
	if (!forg)
	{
		DebugSpew("GenerateMQUI::could not open %s",szOrgFilename);
		return false;
	}
	FILE *fnew=fopen(szFilename,"wt");
	if (!fnew)
	{
		DebugSpew("GenerateMQUI::could not open %s",szFilename);
		fclose(forg);
		return false;
	}
	while(fgets(Buffer,2048,forg))
	{
		if (strstr(Buffer,"</Composite>"))
		{
//			DebugSpew("GenerateMQUI::Inserting our xml files");
			PMQXMLFILE pFile=pXMLFiles;
			while(pFile)
			{
//				DebugSpew("GenerateMQUI::Inserting %s",pFile->szFilename);
				fprintf(fnew,"<Include>%s</Include>\n",pFile->szFilename);
				pFile=pFile->pNext;
			}
		}
		fprintf(fnew,"%s",Buffer);
	}
	fclose(fnew);
	fclose(forg);
	return true;
}

void DestroyMQUI()
{
	// delete EverQuest\uifiles\default\MQUI.xml
	CHAR szFilename[MAX_PATH];
	sprintf(szFilename,"%s\\uifiles\\default\\MQUI.xml",gszEQPath);
	remove(szFilename);
}

void AddXMLFile(const char *filename)
{
	PMQXMLFILE pFile=pXMLFiles;
	PMQXMLFILE pLast=0;
	while(pFile)
	{
		if (!stricmp(pFile->szFilename,filename))
			return; // already there.
		pLast=pFile;
		pFile=pFile->pNext;
	}
	CHAR szFilename[MAX_PATH]={0};
	sprintf(szFilename,"%s\\uifiles\\default\\%s",gszEQPath,filename);
	if (_access(szFilename,0)==-1)
	{
		DebugSpew("Not adding XML File %s because it does not exist in default folder",filename,szFilename);
		return;
	}

	DebugSpew("Adding XML File %s",filename);
	pFile = new MQXMLFILE;
	pFile->pLast=pLast;
	if (pLast)
		pLast->pNext=pFile;
	else
		pXMLFiles=pFile;
	pFile->pNext=0;
	strcpy(pFile->szFilename,filename);
}

void RemoveXMLFile(const char *filename)
{
	PMQXMLFILE pFile=pXMLFiles;
	while(pFile)
	{
		if (!stricmp(pFile->szFilename,filename))
		{
			DebugSpew("Removing XML File %s",filename);
			if (pFile->pLast)
				pFile->pLast->pNext=pFile->pNext;
			else
				pXMLFiles=pFile->pNext;
			if (pFile->pNext)
				pFile->pNext=pFile->pLast->pNext;
			delete pFile;
			return;
		}
		pFile=pFile->pNext;
	}
}

bool SendWndNotification(PCHAR WindowName, PCHAR ScreenID, DWORD Notification, VOID *Data)
{
	CHAR szOut[MAX_STRING] = {0};

	string Name=WindowName;
	MakeLower(Name);

	unsigned long N = WindowMap[Name];
	if (!N)
	{
		sprintf(szOut,"Window '%s' not available.",WindowName);
		WriteChatColor(szOut,USERCOLOR_DEFAULT);
		return false;
	}
	N--;

	_WindowInfo *pInfo=WindowList[N];
	if (!pInfo)
	{
		WindowMap[Name]=0;
		sprintf(szOut,"Window '%s' not available.",WindowName);
		WriteChatColor(szOut,USERCOLOR_DEFAULT);
		return false;
	}
	
	CXWnd *pWnd;
	if (pInfo->pWnd)
	{
		pWnd=pInfo->pWnd;
	}
	else
	{
		if (pInfo->ppWnd)
		{
			pWnd=*pInfo->ppWnd;
			if (!pWnd)
			{
				sprintf(szOut,"Window '%s' not available.",WindowName);
				WriteChatColor(szOut,USERCOLOR_DEFAULT);
				return false;
			}
		}
		else
		{
			WindowMap[Name]=0;
			delete pInfo;
			WindowList[N]=0;
			WindowMap[Name]=0;
			sprintf(szOut,"Window '%s' not available.",WindowName);
			WriteChatColor(szOut,USERCOLOR_DEFAULT);
			return false;
		}
	}



	CXWnd *pButton=0;
	if (ScreenID && ScreenID[0])
	{
		pButton=((CSidlScreenWnd*)(pWnd))->GetChildItem(CXStr(ScreenID));
		if (!pButton)
		{
			sprintf(szOut,"Window '%s' child '%s' not found.",WindowName,ScreenID);
			WriteChatColor(szOut,USERCOLOR_DEFAULT);
			return false;
		}
	}
	
	((CXWnd*)(pWnd))->WndNotification(pButton,Notification,Data);

	return true;
}

void AddWindow(char *WindowName, CXWnd **ppWindow)
{
	string Name=WindowName;
	MakeLower(Name);

	unsigned long N=WindowMap[Name];
	if (N)
	{
		N--;
		_WindowInfo *pWnd = WindowList[N];
		pWnd->pWnd=0;
		pWnd->ppWnd=ppWindow;
		DebugSpew("Updating WndNotification target '%s'",WindowName);
	}
	else
	{
		_WindowInfo *pWnd = new _WindowInfo;
		strcpy(pWnd->Name,WindowName);
		pWnd->pWnd=0;
		pWnd->ppWnd=ppWindow;
		
		N=WindowList.GetUnused();
		WindowList[N]=pWnd;

		WindowMap[WindowName]=N+1;
		DebugSpew("Adding WndNotification target '%s'",Name);
	}

}

void RemoveWindow(char *WindowName)
{
	string Name=WindowName;
	MakeLower(Name);

	unsigned long N=WindowMap[Name];
	if (N)
	{
		N--;
		WindowMap[Name]=0;
		if (_WindowInfo *pInfo=WindowList[N])
		{
			delete pInfo;
			WindowList[N]=0;
		}
	}
}

VOID ListWindows(PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szOut[MAX_STRING]={0};
	if (!szLine || !szLine[0])
	{
		unsigned long Count=0;
		WriteChatColor("List of available windows");
		WriteChatColor("-------------------------");
		for (unsigned long N = 0 ; N < WindowList.Size ; N++)
			if (_WindowInfo *pInfo=WindowList[N])
			{
				sprintf(szOut,"%s",pInfo->Name);
				WriteChatColor(szOut);
				Count++;
			}
		sprintf(szOut,"%d available windows",Count);
		WriteChatColor(szOut);
	}
	else
	{
		// list children of..
		string WindowName=szLine;
		MakeLower(WindowName);
		unsigned long N = WindowMap[WindowName];
		if (!N)
		{
			sprintf(szOut,"Window '%s' not available",szLine);
			WriteChatColor(szOut);
			return;
		}
		WriteChatColor("Listing of child windows not yet implemented");
	}
}

PCHAR szWndNotification[] = { 
	0,			//0 
	"leftmouse",	//1
	"leftmouseup",	//2
	"rightmouse",		//3
	0,		//4
	0,		//5
	"enter",		//6
	0,		//7
	0,		//8
	0,		//9
	"close",		//10
	0,		//11
	0,		//12
	0,		//13
	"newvalue",		//14
	0,		//15
	0,		//16
	0,		//17
	0,		//18
	0,		//19
	0,		//20
	"mouseover",	//21
	"history",		//22
	"leftmousehold",	//23
	0,		//24
	0,		//25
	0,		//26
	0,		//27
	0,		//28
	0,		//29
}; 

VOID WndNotify(PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szArg1[MAX_STRING] = {0}; 
	CHAR szArg2[MAX_STRING] = {0}; 
	CHAR szArg3[MAX_STRING] = {0}; 
	CHAR szArg4[MAX_STRING] = {0}; 
	CHAR szOut[MAX_STRING] = {0};

	GetArg(szArg1, szLine, 1);
	GetArg(szArg2, szLine, 2);
	GetArg(szArg3, szLine, 3);
	GetArg(szArg4, szLine, 4);

	if (!szArg3[0])
	{
		WriteChatColor("Syntax: /notify <window> <control|0> <notification> [notification data]");
		return;
	}
	unsigned long Data=0;
	if (szArg4[0])
		Data=atoi(szArg4);

	for (unsigned long i = 0 ; i < 30 ; i++)
	{
		if (szWndNotification[i] && !stricmp(szWndNotification[i],szArg3))
		{
			if (szArg2[0]=='0')
			{
				if (!SendWndNotification(szArg1,0,i,(void*)Data))
				{
					sprintf(szOut,"Could not send notification to %s %s",szArg1,szArg2);
					WriteChatColor(szOut);
				}
			}
			else if (!SendWndNotification(szArg1,szArg2,i,(void*)Data))
			{
				sprintf(szOut,"Could not send notification to %s %s",szArg1,szArg2);
				WriteChatColor(szOut);
			}
			return;
		}
	}
	sprintf(szOut,"Invalid notification '%s'",szArg3);
	WriteChatColor(szOut);
//bool SendWndNotification(PCHAR WindowName, PCHAR ScreenID, DWORD Notification, VOID *Data)
	


}

