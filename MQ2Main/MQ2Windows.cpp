/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003 Lax

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

bool GenerateMQUI();
void DestroyMQUI();

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




void InitializeMQ2Windows()
{
	DebugSpew("Initializing MQ2 Windows");
	/*
	int (CXMLSOMDocumentBaseHook::*pfDetour)(CXStr *A, CXStr *B, CXStr *C) = CXMLSOMDocumentBaseHook::XMLRead; 
	int (CXMLSOMDocumentBaseHook::*pfTrampoline)(CXStr *A, CXStr *B, CXStr *C) = CXMLSOMDocumentBaseHook::XMLRead_Trampoline; 
	AddDetour(CXMLSOMDocumentBase__XMLRead,*(PBYTE*)&pfDetour,*(PBYTE*)&pfTrampoline);
	/**/
	EasyClassDetour(CXMLSOMDocumentBase__XMLRead,CXMLSOMDocumentBaseHook,XMLRead,int,(CXStr *A, CXStr *B, CXStr *C),XMLRead_Trampoline);
}

void ShutdownMQ2Windows()
{
	DebugSpew("Shutting down MQ2 Windows");
	RemoveDetour(CXMLSOMDocumentBase__XMLRead);
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

