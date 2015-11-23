/*****************************************************************************
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

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

#ifdef ISXEQ
#define ISINDEX() (argc>0)
#define ISNUMBER() (IsNumber(argv[0]))
#define GETNUMBER() (atoi(argv[0]))
#define GETFIRST()    argv[0]
#else
#define ISINDEX() (szIndex[0])
#define ISNUMBER() (IsNumber(szIndex))
#define GETNUMBER() (atoi(szIndex))
#define GETFIRST() szIndex
#endif

#include "MQ2Main.h"
#ifndef ISXEQ
#define TLO(funcname) BOOL funcname(PCHAR szIndex, MQ2TYPEVAR &Ret)
#else
#define TLO(funcname) bool funcname(int argc, char *argv[], LSTYPEVAR &Ret)
#endif


TLO(dataSpawn)
{
	if (ISINDEX())
	{
		if (ISNUMBER())
		{
			if (Ret.Ptr = GetSpawnByID(GETNUMBER()))
			{
				Ret.Type = pSpawnType;
				return true;
			}
		}
		else
		{
			// set up search spawn
			SEARCHSPAWN ssSpawn;
			ClearSearchSpawn(&ssSpawn);
#ifndef ISXEQ
			ParseSearchSpawn(szIndex, &ssSpawn);
#else
			ParseSearchSpawn(0, argc, argv, ssSpawn);
#endif
			if (Ret.Ptr = SearchThroughSpawns(&ssSpawn, (PSPAWNINFO)pCharSpawn))
			{
				Ret.Type = pSpawnType;
				return true;
			}
		}
	}
	// No spawn

	return false;
}

#ifndef ISXEQ
TLO(dataSelect)
{
	if (!szIndex[0])
		return false;

	// I hate this GetArg shit - Lax
	CHAR szArg[MAX_STRING] = { 0 };
	CHAR szArg1[MAX_STRING] = { 0 };
	int N = 2;
	GetArg(szArg1, szIndex, 1, FALSE, FALSE, TRUE);
	while (1)
	{
		GetArg(szArg, szIndex, N, FALSE, FALSE, TRUE);
		N++;
		if (!szArg[0])
		{
			Ret.DWord = 0;
			Ret.Type = pIntType;
			return true;
		}
		if (!_stricmp(szArg1, szArg))
		{
			Ret.DWord = N - 2;
			Ret.Type = pIntType;
			return true;
		}
	}
}
#endif

TLO(dataTarget)
{
	if (pTarget)
	{
		Ret.Ptr = pTarget;
		Ret.Type = pTargetType;
		return true;
	}
	return false;
}

TLO(dataCharacter)
{
	if (pCharData)
	{
		Ret.Ptr = pCharData;
		Ret.Type = pCharacterType;
		return true;
	}
	return false;
}

TLO(dataSpell)
{
	if (ISINDEX())
	{
		if (ISNUMBER())
		{
			if (Ret.Ptr = GetSpellByID(GETNUMBER()))
			{
				Ret.Type = pSpellType;
				return true;
			}
		}
		else
		{
			if (Ret.Ptr = GetSpellByName(GETFIRST()))
			{
				Ret.Type = pSpellType;
				return true;
			}
			//is it an AA?
			if (Ret.Ptr = GetSpellByAAName(GETFIRST()))
			{
				Ret.Type = pSpellType;
				return true;
			}
		}
	}
	return false;
}

TLO(dataSwitch)
{
	if (pDoorTarget)
	{
		Ret.Ptr = pDoorTarget;
		Ret.Type = pSwitchType;
		return true;
	}
	return false;
}

TLO(dataGroundItem)
{
	if (pGroundTarget)
	{
		Ret.Ptr = pGroundTarget;
		Ret.Type = pGroundType;
		return true;
	}
	return false;
}

TLO(dataMerchant)
{
	if (pActiveMerchant)
	{
		Ret.Ptr = pActiveMerchant;
		Ret.Type = pMerchantType;
		return true;
	}
	return false;
}
TLO(dataMercenary)
{
	if (pMercInfo && pMercInfo->MercSpawnId)
	{
		Ret.Ptr = GetSpawnByID(pMercInfo->MercSpawnId);
		Ret.Type = pMercenaryType;
		return true;
	}
	else if (pMercInfo) {
		ZeroMemory(&MercenarySpawn, sizeof(MercenarySpawn));
		if (pMercInfo->HaveMerc == 1) {
			switch (pMercInfo->MercState)
			{
			case 0:
				strcpy_s(MercenarySpawn.Name, "DEAD");
				break;
			case 1:
				strcpy_s(MercenarySpawn.Name, "SUSPENDED");
				break;
			default:
				strcpy_s(MercenarySpawn.Name, "UNKNOWN");
				break;
			}
			Ret.Ptr = &MercenarySpawn;
			Ret.Type = pMercenaryType;
			return true;
		}
		else {
			if (pMercInfo->MercenaryCount >= 1) {
				strcpy_s(MercenarySpawn.Name, "SUSPENDED");
				Ret.Ptr = &MercenarySpawn;
				Ret.Type = pMercenaryType;
				return true;
			}
			else {
				strcpy_s(MercenarySpawn.Name, "NOT FOUND");
				Ret.Ptr = &MercenarySpawn;
				Ret.Type = pMercenaryType;
				return true;
			}
		}
	}
	return false;//we need to return true always to be able to get other members out
}
TLO(dataPet)
{
	PSPAWNINFO pSpawn = GetCharInfo()->pSpawn;
	if (pSpawn && pSpawn->PetID != 0xFFFFFFFF)
	{
		Ret.Ptr = GetSpawnByID(pSpawn->PetID);
		Ret.Type = pPetType;
		return true;
	}
	else if (pSpawn) {
		ZeroMemory(&PetSpawn, sizeof(PetSpawn));
		strcpy_s(PetSpawn.Name, "NO PET");
		Ret.Ptr = &PetSpawn;
		Ret.Type = pPetType;
		return true;
	}
	return false;//we need to return true always to be able to get other members out
}

TLO(dataCorpse)
{
	if (pLootWnd)
	{
		Ret.Ptr = pLootWnd;
		Ret.Type = pCorpseType;
		return true;
	}
	return false;
}

TLO(dataWindow)
{
	if (ISINDEX())
	{
		if (Ret.Ptr = FindMQ2Window(GETFIRST()))
		{
			Ret.Type = pWindowType;
			return true;
		}
	}
	return false;
}

#ifndef ISXEQ
TLO(dataMacro)
{
	if (gRunning)
	{
		Ret.Ptr = 0;
		Ret.Type = pMacroType;
		return true;
	}
	return false;
}
#endif

TLO(dataMacroQuest)
{
	Ret.Ptr = 0;
	Ret.Type = pMacroQuestType;
	return true;
}

TLO(dataEverQuest)
{
	Ret.Ptr = 0;
	Ret.Type = pEverQuestType;
	return true;
}
#ifndef ISXEQ
TLO(dataMath)
{
	Ret.Ptr = 0;
	Ret.Type = pMathType;
	return true;
}
#endif

TLO(dataZone)
{
	int nIndex = 0;
	PZONELIST pZone = NULL;

	if (!ISINDEX())
	{
		Ret.DWord = instEQZoneInfo;
		Ret.Type = pCurrentZoneType;
		return true;
	}
	else if (ISNUMBER())
	{
		if (nIndex = (GETNUMBER() & 0x7FFF))
		{
			if ((GetCharInfo()->zoneId & 0x7FFF) == nIndex)
			{
				Ret.DWord = instEQZoneInfo;
				Ret.Type = pCurrentZoneType;
			}
			else if (nIndex < MAX_ZONES)
			{
				Ret.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[nIndex];
				Ret.Type = pZoneType;
			}
			if (!Ret.Ptr)
				return false;
			return true;
		}
	}
	else if ((nIndex = GetZoneID(GETFIRST())) != -1)
	{
		if (GetCharInfo()->zoneId == nIndex)
		{
			Ret.DWord = instEQZoneInfo;
			Ret.Type = pCurrentZoneType;
		}
		else
		{
			Ret.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[nIndex];
			Ret.Type = pZoneType;
		}
		return true;
	}
	return false;
}


#ifndef ISXEQ
TLO(dataInt)
{
	if (!ISINDEX())
		return false;
	Ret.DWord = atol(szIndex);
	Ret.Type = pIntType;
	return true;
}

TLO(dataString)
{
	WriteChatf("Due to complete misuse of the String Top-Level Object, it has been removed.");
	return false;
	/*
	if (!ISINDEX())
	return false;
	strcpy(DataTypeTemp,szIndex);
	Ret.Ptr=&DataTypeTemp[0];
	Ret.Type=pStringType;
	return true;
	/**/
}

TLO(dataFloat)
{
	if (!ISINDEX())
		return false;
	Ret.Float = (FLOAT)atof(szIndex);
	Ret.Type = pFloatType;
	return true;
}
#endif

TLO(dataHeading)
{
#ifndef ISXEQ
	if (!ISINDEX())
		return false;
	if (PCHAR pComma = strchr(szIndex, ','))
	{
		*pComma = 0;
		FLOAT Y = (FLOAT)atof(szIndex);
		*pComma = ',';
		FLOAT X = (FLOAT)atof(&pComma[1]);
		Ret.Float = (FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - Y, X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
		if (Ret.Float<0.0f)
			Ret.Float += 360.0f;
		else if (Ret.Float >= 360.0f)
			Ret.Float -= 360.0f;
		Ret.Type = pHeadingType;
		return true;
	}

	Ret.Float = (FLOAT)atof(szIndex);
	Ret.Type = pHeadingType;
	return true;
#else
	if (!argc)
		return false;
	if (argc == 2)
	{
		FLOAT Y = (FLOAT)atof(argv[0]);
		FLOAT X = (FLOAT)atof(argv[1]);
		Ret.Float = (FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - Y, X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
		if (Ret.Float<0.0f)
			Ret.Float += 360.0f;
		else if (Ret.Float >= 360.0f)
			Ret.Float -= 360.0f;
		Ret.Type = pHeadingType;
		return true;
	}

	Ret.Float = (FLOAT)atof(argv[0]);
	Ret.Type = pHeadingType;
	return true;
#endif
}


#ifndef ISXEQ
TLO(dataBool)
{
	if (!ISINDEX())
		return false;
	Ret.DWord = (stricmp(szIndex, "NULL") &&
		stricmp(szIndex, "FALSE") &&
		strcmp(szIndex, "0"));
	Ret.Type = pBoolType;
	return true;
}
#endif
/*
TLO(dataGroupLeader)
{
if (!GroupLeader[0] || !_stricmp(GroupLeader,GetCharInfo()->pSpawn->Name))
{
Ret.Ptr=GetCharInfo()->pSpawn;
Ret.Type=pSpawnType;
return true;
}
for (unsigned long N = 0 ; N < 5 ; N++)
{
if (EQADDR_GROUPCOUNT[N])
{
if (PSPAWNINFO pSpawn=(PSPAWNINFO)ppGroup[N])
{
if (!_stricmp(pSpawn->Name,GroupLeader))
{
Ret.Ptr=pSpawn;
Ret.Type=pSpawnType;
return true;
}
}
}
}
return false;
}
/**/
/*
TLO(dataGroupLeaderName)
{
if (!GroupLeader[0])
{
Ret.Ptr=GetCharInfo()->pSpawn->Name;
Ret.Type=pStringType;
return true;
}
Ret.Ptr=&GroupLeader[0];
Ret.Type=pStringType;
return true;
}
/**/

TLO(dataGroup)
{
	Ret.DWord = 1;
	Ret.Type = pGroupType;
	return true;
	/*
	if (ISINDEX())
	{
	DWORD N=GETNUMBER();
	if (N==0)
	{
	#ifndef ISXEQ
	return dataCharacter("",Ret);
	#else
	return dataCharacter(0,0,Ret);
	#endif
	}
	if (N>5)
	return false;
	for (unsigned long i=0; i<5 ; i++)
	{
	if (EQADDR_GROUPCOUNT[i])
	{
	N--;
	if (N==0)
	{
	Ret.Ptr=ppGroup[i];
	Ret.Type=pSpawnType;
	return true;
	}
	}
	}
	return false;
	}
	else
	{
	Ret.DWord=0;
	for (int index=0;index<5;index++)
	if (EQADDR_GROUPCOUNT[index])
	Ret.DWord++;
	Ret.Type=pIntType;
	return true;
	}
	return false;
	/**/
}
#ifndef ISXEQ
TLO(dataIf)
{
	if (ISINDEX())
	{
		INT nDelimiter = 0;
		PCHAR pDelimiter = strchr(szIndex, gIfAltDelimiter);

		while (pDelimiter != NULL)
		{
			nDelimiter++;
			pDelimiter = strchr(pDelimiter + 1, gIfAltDelimiter);
		}

		// condition| whentrue| whenfalse
		if (nDelimiter == 2)
		{
			if (PCHAR pTrue = strchr(szIndex, gIfAltDelimiter))
			{
				*pTrue = 0;
				pTrue++;
				if (PCHAR pFalse = strchr(pTrue, gIfAltDelimiter))
				{
					*pFalse = 0;
					pFalse++;
					DOUBLE CalcResult;
					if (!Calculate(szIndex, CalcResult))
						return false;

					if (CalcResult != 0.0f)
					{
						strcpy(DataTypeTemp, pTrue);
						Ret.Ptr = &DataTypeTemp[0];
						Ret.Type = pStringType;
						return true;
					}
					else
					{
						strcpy(DataTypeTemp, pFalse);
						Ret.Ptr = &DataTypeTemp[0];
						Ret.Type = pStringType;
						return true;
					}
				}
			}
		}

		// condition, whentrue, whenfalse
		if (PCHAR pTrue = strchr(szIndex, gIfDelimiter))
		{
			*pTrue = 0;
			pTrue++;
			if (PCHAR pFalse = strchr(pTrue, gIfDelimiter))
			{
				*pFalse = 0;
				pFalse++;
				DOUBLE CalcResult;
				if (!Calculate(szIndex, CalcResult))
					return false;

				if (CalcResult != 0.0f)
				{
					strcpy(DataTypeTemp, pTrue);
					Ret.Ptr = &DataTypeTemp[0];
					Ret.Type = pStringType;
					return true;
				}
				else
				{
					strcpy(DataTypeTemp, pFalse);
					Ret.Ptr = &DataTypeTemp[0];
					Ret.Type = pStringType;
					return true;
				}
			}
		}
	}
	return false;
}
#endif
TLO(dataCursor)
{
	if (Ret.Ptr = GetCharInfo2()->pInventoryArray->Inventory.Cursor)
	{
		Ret.Type = pItemType;
		return true;
	}
	return false;
}

TLO(dataLastSpawn)
{
	if (ISINDEX())
	{
		if (GETFIRST()[0] == '-')
		{
			unsigned long N = atoi(&GETFIRST()[1]) - 1;
			if (PSPAWNINFO pSpawn = (PSPAWNINFO)pLocalPlayer)
			{
				while (N)
				{
					pSpawn = pSpawn->pPrev;
					if (!pSpawn)
						return false;
					N--;
				}
				Ret.Ptr = pSpawn;
				Ret.Type = pSpawnType;
				return true;
			}
		}
		else if (ISNUMBER())
		{
			unsigned long N = GETNUMBER() - 1;
			if (PSPAWNINFO pSpawn = (PSPAWNINFO)pSpawnList)
			{
				while (N)
				{
					pSpawn = pSpawn->pNext;
					if (!pSpawn)
						return false;
					N--;
				}
				Ret.Ptr = pSpawn;
				Ret.Type = pSpawnType;
				return true;
			}
		}
	}
	else
	{
		Ret.Ptr = pSpawnList;
		Ret.Type = pSpawnType;
		return true;
	}
	return false;
}

TLO(dataNearestSpawn)
{
	if (ISINDEX())
	{
		unsigned long nth;
		SEARCHSPAWN ssSpawn;
		ClearSearchSpawn(&ssSpawn);
		ssSpawn.FRadius = 999999.0f;
#ifndef ISXEQ
		PCHAR pSearch;
		if (pSearch = strchr(szIndex, ','))
		{
			*pSearch = 0;
			++pSearch;
			ParseSearchSpawn(pSearch, &ssSpawn);
			nth = GETNUMBER();
		}
		else
		{
			if (IsNumberToComma(szIndex))
			{
				nth = GETNUMBER();
			}
			else
			{
				nth = 1;
				ParseSearchSpawn(szIndex, &ssSpawn);
			}
		}
#else
		if (!ISNUMBER()) {
			nth = 1;
			ParseSearchSpawn(0, argc, argv, ssSpawn);
		}
		else {
			nth = GETNUMBER();
			ParseSearchSpawn(1, argc, argv, ssSpawn);
		}
#endif
		for (unsigned long N = 0; N < gSpawnCount; N++)
		{
			if (EQP_DistArray[N].Value.Float>ssSpawn.FRadius && !ssSpawn.bKnownLocation)
				return false;
			if (SpawnMatchesSearch(&ssSpawn, (PSPAWNINFO)pCharSpawn, (PSPAWNINFO)EQP_DistArray[N].VarPtr.Ptr))
			{
				if (--nth == 0)
				{
					Ret.Ptr = EQP_DistArray[N].VarPtr.Ptr;
					Ret.Type = pSpawnType;
					return true;
				}
			}
		}
	}
	// No spawn
	return false;
}

TLO(dataSpawnCount)
{
	if (ISINDEX())
	{
		SEARCHSPAWN ssSpawn;
		ClearSearchSpawn(&ssSpawn);
#ifndef ISXEQ
		ParseSearchSpawn(szIndex, &ssSpawn);
#else
		ParseSearchSpawn(0, argc, argv, ssSpawn);
#endif
		Ret.DWord = CountMatchingSpawns(&ssSpawn, GetCharInfo()->pSpawn, TRUE);
		Ret.Type = pIntType;
		return true;
	}
	else
	{
		Ret.DWord = gSpawnCount;
		Ret.Type = pIntType;
		return true;
	}
}

TLO(dataTime)
{
	time_t CurTime;
	time(&CurTime);
	Ret.Ptr = localtime(&CurTime);
	Ret.Type = pTimeType;
	return true;
}
TLO(dataGameTime)
{
	struct tm* pTime = (struct tm*)&DataTypeTemp[0];
	ZeroMemory(pTime, sizeof(struct tm));
	pTime->tm_mday = ((PWORLDDATA)pWorldData)->Day;
	pTime->tm_hour = ((PWORLDDATA)pWorldData)->Hour - 1;
	pTime->tm_min = ((PWORLDDATA)pWorldData)->Minute;
	pTime->tm_mon = ((PWORLDDATA)pWorldData)->Month;
	pTime->tm_year = ((PWORLDDATA)pWorldData)->Year - 1900;
	Ret.Ptr = pTime;
	Ret.Type = pTimeType;
	return true;
}
TLO(dataIni)
{
#ifndef ISXEQ /* CONVERT */
	if (!szIndex)
		return false;
	if (szIndex[0] == '\0')
		return false;
	int count = 0;
	std::string IniFile;
	std::string Section;
	std::string Key;
	std::string Default;
	std::map<DWORD, DWORD>argmap;
	std::string sTemp = szIndex;
	//lets see how many commas are in the string
	for (std::string::iterator i = sTemp.begin(); i != sTemp.end(); i++) {
		if (i[0] == ',' && i + 1 != sTemp.end() && i[1] != ' ') {
			argmap[count] = std::distance(sTemp.begin(), i);
			count++;
		}
	}
	IniFile = sTemp;
	if (argmap.size() >= 1) {
		IniFile.erase(argmap[0]);
		Section = sTemp.substr(argmap[0] + 1);
		if (argmap.size() >= 2) {
			Section.erase(argmap[1] - argmap[0] - 1);
			Key = sTemp.substr(argmap[1] + 1);
			if (argmap.size() >= 3) {
				Key.erase(argmap[2] - argmap[1] - 1);
				Default = sTemp.substr(argmap[2] + 1);
			}
		}
	}
	if (IniFile.size() == 0)
		return false;
	CHAR FileName[MAX_STRING] = { 0 };
	std::replace(IniFile.begin(), IniFile.end(), '/', '\\');

	if (IniFile.size() && IniFile[0] != '\\' && IniFile.find(":") == IniFile.npos)
		sprintf_s(FileName, "%s\\%s", gszMacroPath, IniFile.c_str());
	else
		strcpy_s(FileName, IniFile.c_str());

	IniFile = FileName;
	if (IniFile.find(".") == IniFile.npos) {
		IniFile.append(".ini");
	}

	if (!_FileExists(IniFile.c_str()))
	{
		if (Default.size())
		{
			strcpy_s(DataTypeTemp, Default.c_str());
			Ret.Ptr = &DataTypeTemp[0];
			Ret.Type = pStringType;
			return true;
		}
		return false;
	}
	DWORD nSize = 0;
	if (Section.size() && Key.size()) {
		nSize = GetPrivateProfileString(Section.c_str(), Key.c_str(), Default.c_str(), DataTypeTemp, MAX_STRING, IniFile.c_str());
	}
	else if (Section.size() && Key.size() == 0) {
		nSize = GetPrivateProfileString(Section.c_str(), NULL, Default.c_str(), DataTypeTemp, MAX_STRING, IniFile.c_str());
	}
	else if (Section.size() == 0 && Key.size()) {
		nSize = GetPrivateProfileString(NULL, Key.c_str(), Default.c_str(), DataTypeTemp, MAX_STRING, IniFile.c_str());
	}
	else if (Section.size() == 0 && Key.size() == 0) {
		nSize = GetPrivateProfileString(NULL, NULL, Default.c_str(), DataTypeTemp, MAX_STRING, IniFile.c_str());
	}
	if (nSize)
	{
		if (nSize>2)
			for (unsigned long N = 0; N < nSize - 2; N++)
				if (DataTypeTemp[N] == 0)
					DataTypeTemp[N] = '|';
		if ((Section.size() == 0 || Key.size() == 0) && (nSize<MAX_STRING - 3))
			strcat_s(DataTypeTemp, "||");

		Ret.Ptr = &DataTypeTemp[0];
		Ret.Type = pStringType;
		return true;
	}
	if (Default.size())
	{
		strcpy_s(DataTypeTemp, Default.c_str());
		Ret.Ptr = &DataTypeTemp[0];
		Ret.Type = pStringType;
		return true;
	}
#endif
	return false;
}

#ifndef ISXEQ
TLO(dataDefined)
{
	if (!ISINDEX())
		return false;
	Ret.DWord = (FindMQ2DataVariable(szIndex) != 0);
	Ret.Type = pBoolType;
	return true;
}
#endif

TLO(dataSelectedItem)
{
	if (((PEQINVSLOTMGR)pInvSlotMgr)->pSelectedItem && ((PEQINVSLOTMGR)pInvSlotMgr)->pSelectedItem->InvSlot)
	{
		class CInvSlot *pCIS = NULL;
		struct _CONTENTS *pC = NULL;

		pCIS = (class CInvSlot *) ((PEQINVSLOTMGR)pInvSlotMgr)->pSelectedItem;
		pCIS->GetItemBase(&pC);

		if (pC) {
			Ret.Ptr = pC;
			Ret.Type = pItemType;
			return true;
		}
		else {//im working on this -eqmule 2013 dec 14
			PCONTENTS pItem = FindItemByName("Worn Totem");
			if (pItem) {
				CInvSlot *pSlot = pInvSlotMgr->FindInvSlot(pItem->ItemSlot);
				Sleep(0);
			}
		}
	}
	return false;
}

TLO(dataFindItemBank)
{
	if (!ISINDEX())
		return false;
	DWORD N = 1;
	PCHAR pName = GETFIRST();
	BOOL bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}
	CHAR Name[MAX_STRING] = { 0 };
	CHAR Temp[MAX_STRING] = { 0 };
	strlwr(strcpy(Name, pName));
	PCHARINFO pCharInfo = GetCharInfo();
	unsigned long nPack;


	for (nPack = 0; nPack < NUM_BANK_SLOTS; nPack++)
	{
		PCHARINFO pCharInfo = GetCharInfo();
		PCONTENTS pPack;

		if (pCharInfo->pBankArray && (pPack = pCharInfo->pBankArray->Bank[nPack]))
		{
			if (bExact)
			{
				if (!_stricmp(Name, GetItemFromContents(pPack)->Name))
				{
					Ret.Ptr = pPack;
					Ret.Type = pItemType;
					return true;
				}
			}
			else
			{
				if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pPack)->Name)), Name))
				{
					Ret.Ptr = pPack;
					Ret.Type = pItemType;
					return true;
				}
			}
			if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->pContentsArray)
			{
				for (unsigned long nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
				{
					PCONTENTS pItem;
					if (pPack->pContentsArray && (pItem = pPack->pContentsArray->Contents[nItem]))
					{
						if (bExact)
						{
							if (!_stricmp(Name, GetItemFromContents(pItem)->Name))
							{
								Ret.Ptr = pItem;
								Ret.Type = pItemType;
								return true;
							}
						}
						else
						{
							if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pItem)->Name)), Name))
							{
								Ret.Ptr = pItem;
								Ret.Type = pItemType;
								return true;
							}
						}
					}
				}
			}
		}
	}
	for (nPack = 0; nPack < NUM_SHAREDBANK_SLOTS; nPack++)
	{
		PCHARINFO pCharInfo = GetCharInfo();
		PCONTENTS pPack;
		if (pCharInfo->pSharedBankArray && (pPack = pCharInfo->pSharedBankArray->SharedBank[nPack]))
		{
			if (bExact)
			{
				if (!_stricmp(Name, GetItemFromContents(pPack)->Name))
				{
					Ret.Ptr = pPack;
					Ret.Type = pItemType;
					return true;
				}
			}
			else
			{
				if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pPack)->Name)), Name))
				{
					Ret.Ptr = pPack;
					Ret.Type = pItemType;
					return true;
				}
			}
			if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->pContentsArray)
			{
				for (unsigned long nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
				{
					PCONTENTS pItem;
					if (pPack->pContentsArray && (pItem = pPack->pContentsArray->Contents[nItem]))
					{
						if (bExact)
						{
							if (!_stricmp(Name, GetItemFromContents(pItem)->Name))
							{
								Ret.Ptr = pItem;
								Ret.Type = pItemType;
								return true;
							}
						}
						else
						{
							if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pItem)->Name)), Name))
							{
								Ret.Ptr = pItem;
								Ret.Type = pItemType;
								return true;
							}
						}
					}
				}
			}
		}
	}


	return false;
}

TLO(dataFindItem)
{
	if (!ISINDEX())
		return false;
	DWORD N = 1;
	PCHAR pName = GETFIRST();
	BOOL bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}
	CHAR Name[MAX_STRING] = { 0 };
	CHAR Temp[MAX_STRING] = { 0 };
	strlwr(strcpy(Name, pName));
	PCHARINFO pCharInfo = GetCharInfo();
	PCHARINFO2 pChar2 = GetCharInfo2();
	//check toplevel slots
	if (pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
		for (unsigned long nSlot = 0; nSlot < NUM_INV_SLOTS; nSlot++)
		{
			if (PCONTENTS pItem = pChar2->pInventoryArray->InventoryArray[nSlot])
			{
				if (bExact)
				{
					if (!_stricmp(Name, GetItemFromContents(pItem)->Name))
					{
						Ret.Ptr = pItem;
						Ret.Type = pItemType;
						return true;
					}
				}
				else
				{
					if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pItem)->Name)), Name))
					{
						Ret.Ptr = pItem;
						Ret.Type = pItemType;
						return true;
					}
				}
			}
		}
	}
	//check cursor
	if (pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->Inventory.Cursor) {
		if (PCONTENTS pItem = pChar2->pInventoryArray->Inventory.Cursor) {
			if (bExact) {
				if (!_stricmp(Name, GetItemFromContents(pItem)->Name)) {
					Ret.Ptr = pItem;
					Ret.Type = pItemType;
					return true;
				}
			}
			else {
				if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pItem)->Name)), Name)) {
					Ret.Ptr = pItem;
					Ret.Type = pItemType;
					return true;
				}
			}
		}
	}
	//check inside bags
	if (pChar2 && pChar2->pInventoryArray) {
		for (unsigned long nPack = 0; nPack < 10; nPack++)
		{
			if (PCONTENTS pPack = pChar2->pInventoryArray->Inventory.Pack[nPack])
			{
				if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->pContentsArray)
				{
					for (unsigned long nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
					{
						if (PCONTENTS pItem = pPack->pContentsArray->Contents[nItem])
						{
							if (bExact)
							{
								if (!_stricmp(Name, GetItemFromContents(pItem)->Name))
								{
									Ret.Ptr = pItem;
									Ret.Type = pItemType;
									return true;
								}
							}
							else
							{
								if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pItem)->Name)), Name))
								{
									Ret.Ptr = pItem;
									Ret.Type = pItemType;
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
#ifndef EMU
	//still not found? fine... check mount keyring
	PCHARINFO pChar = GetCharInfo();
	if (pChar && pChar->pMountsArray && pChar->pMountsArray->Mounts) {
		for (unsigned long nSlot = 0; nSlot < MAX_KEYRINGITEMS; nSlot++)
		{
			if (PCONTENTS pItem = pChar->pMountsArray->Mounts[nSlot])
			{
				if (bExact)
				{
					if (!_stricmp(Name, GetItemFromContents(pItem)->Name))
					{
						Ret.Ptr = pItem;
						Ret.Type = pItemType;
						return true;
					}
				}
				else
				{
					if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pItem)->Name)), Name))
					{
						Ret.Ptr = pItem;
						Ret.Type = pItemType;
						return true;
					}
				}
			}
		}
	}
	//still not found? fine... check illusions keyring
	if (pChar && pChar->pIllusionsArray && pChar->pIllusionsArray->Illusions) {
		for (unsigned long nSlot = 0; nSlot < MAX_KEYRINGITEMS; nSlot++)
		{
			if (PCONTENTS pItem = pChar->pIllusionsArray->Illusions[nSlot])
			{
				if (bExact)
				{
					if (!_stricmp(Name, GetItemFromContents(pItem)->Name))
					{
						Ret.Ptr = pItem;
						Ret.Type = pItemType;
						return true;
					}
				}
				else
				{
					if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pItem)->Name)), Name))
					{
						Ret.Ptr = pItem;
						Ret.Type = pItemType;
						return true;
					}
				}
			}
		}
	}
#endif
	return false;
}

TLO(dataFindItemCount)
{
	if (!ISINDEX())
		return false;
	DWORD N = 1;
	PCHAR pName = GETFIRST();
	BOOL bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}
	CHAR Name[MAX_STRING] = { 0 };
	CHAR Temp[MAX_STRING] = { 0 };
	strlwr(strcpy(Name, pName));
	PCHARINFO pCharInfo = GetCharInfo();

	unsigned long Count = 0;
	DWORD nAug = 0;
	PCHARINFO2 pChar2 = GetCharInfo2();
	if (pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
		for (unsigned long nSlot = 0; nSlot < NUM_INV_SLOTS; nSlot++)
		{
			if (PCONTENTS pItem = pChar2->pInventoryArray->InventoryArray[nSlot])
			{
				if (bExact)
				{
					if (!_stricmp(Name, GetItemFromContents(pItem)->Name))
					{
						if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
							(((EQ_Item*)pItem)->IsStackable() != 1))
							Count++;
						else
							Count += pItem->StackCount;
					}
					else // for augs
					{
						if (pItem->pContentsArray && pItem->NumOfSlots2)
							for (nAug = 0; nAug < pItem->NumOfSlots2; nAug++)
							{
								if (pItem->pContentsArray->Contents[nAug] && GetItemFromContents(pItem->pContentsArray->Contents[nAug])->Type == ITEMTYPE_NORMAL && GetItemFromContents(pItem->pContentsArray->Contents[nAug])->AugType &&
									!_stricmp(Name, GetItemFromContents(pItem->pContentsArray->Contents[nAug])->Name))
									Count++;
							}
					}
				}
				else
				{
					if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pItem)->Name)), Name))
					{
						if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
							(((EQ_Item*)pItem)->IsStackable() != 1))
							Count++;
						else
							Count += pItem->StackCount;
					}
					else // for augs
					{
						if (pItem->pContentsArray && pItem->NumOfSlots2)
							for (nAug = 0; nAug < pItem->NumOfSlots2; nAug++)
							{
								if (pItem->pContentsArray->Contents[nAug] && GetItemFromContents(pItem->pContentsArray->Contents[nAug])->Type == ITEMTYPE_NORMAL && GetItemFromContents(pItem->pContentsArray->Contents[nAug])->AugType &&
									strstr(strlwr(strcpy(Temp, GetItemFromContents(pItem->pContentsArray->Contents[nAug])->Name)), Name))
									Count++;
							}
					}
				}
			}
		}
	}
	if (pChar2 && pChar2->pInventoryArray) {
		for (unsigned long nPack = 0; nPack < 10; nPack++)
		{
			if (PCONTENTS pPack = pChar2->pInventoryArray->Inventory.Pack[nPack])
			{
				if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->pContentsArray)
				{
					for (unsigned long nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
					{
						if (PCONTENTS pItem = pPack->pContentsArray->Contents[nItem])
						{
							if (bExact)
							{
								if (!_stricmp(Name, GetItemFromContents(pItem)->Name))
								{
									if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
										(((EQ_Item*)pItem)->IsStackable() != 1))
										Count++;
									else
										Count += pItem->StackCount;
								}
								else // for augs
								{
									if (pItem->pContentsArray && pItem->NumOfSlots2)
										for (nAug = 0; nAug < pItem->NumOfSlots2; nAug++)
										{
											if (pItem->pContentsArray->Contents[nAug] && GetItemFromContents(pItem->pContentsArray->Contents[nAug])->Type == ITEMTYPE_NORMAL && GetItemFromContents(pItem->pContentsArray->Contents[nAug])->AugType &&
												!_stricmp(Name, GetItemFromContents(pItem->pContentsArray->Contents[nAug])->Name))
												Count++;
										}
								}
							}
							else
							{
								if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pItem)->Name)), Name))
								{
									if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
										(((EQ_Item*)pItem)->IsStackable() != 1))
										Count++;
									else
										Count += pItem->StackCount;
								}
								else // for augs
								{
									if (pItem->pContentsArray && pItem->NumOfSlots2)
										for (nAug = 0; nAug < pItem->NumOfSlots2; nAug++)
										{
											if (pItem->pContentsArray->Contents[nAug] && GetItemFromContents(pItem->pContentsArray->Contents[nAug])->Type == ITEMTYPE_NORMAL && GetItemFromContents(pItem->pContentsArray->Contents[nAug])->AugType &&
												strstr(strlwr(strcpy(Temp, GetItemFromContents(pItem->pContentsArray->Contents[nAug])->Name)), Name))
												Count++;
										}
								}
							}
						}
					}
				}
			}
		}
	}

	Ret.DWord = Count;
	Ret.Type = pIntType;

	return true;
}

TLO(dataFindItemBankCount)
{
	if (!ISINDEX())
		return false;
	DWORD N = 1;
	PCHAR pName = GETFIRST();
	BOOL bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}
	CHAR Name[MAX_STRING] = { 0 };
	CHAR Temp[MAX_STRING] = { 0 };
	strlwr(strcpy(Name, pName));
	PCHARINFO pCharInfo = GetCharInfo();

	unsigned long Count = 0;
	unsigned long nPack = 0;

	for (nPack = 0; nPack < NUM_BANK_SLOTS; nPack++)
	{
		PCHARINFO pCharInfo = GetCharInfo();
		PCONTENTS pPack;
		if (pCharInfo->pBankArray && (pPack = pCharInfo->pBankArray->Bank[nPack]))
		{
			if (bExact)
			{
				if (!_stricmp(Name, GetItemFromContents(pPack)->Name))
				{
					if ((GetItemFromContents(pPack)->Type != ITEMTYPE_NORMAL) ||
						(((EQ_Item*)pPack)->IsStackable() != 1))
						Count++;
					else
						Count += pPack->StackCount;
				}
			}
			else
			{
				if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pPack)->Name)), Name))
				{
					if ((GetItemFromContents(pPack)->Type != ITEMTYPE_NORMAL) ||
						(((EQ_Item*)pPack)->IsStackable() != 1))
						Count++;
					else
						Count += pPack->StackCount;
				}
			}
			if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->pContentsArray)
			{
				for (unsigned long nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
				{
					if (PCONTENTS pItem = pPack->pContentsArray->Contents[nItem])
					{
						if (bExact)
						{
							if (!_stricmp(Name, GetItemFromContents(pItem)->Name))
							{
								if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
									(((EQ_Item*)pItem)->IsStackable() != 1))
									Count++;
								else
									Count += pItem->StackCount;
							}
						}
						else
						{
							if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pItem)->Name)), Name))
							{
								if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
									(((EQ_Item*)pItem)->IsStackable() != 1))
									Count++;
								else
									Count += pItem->StackCount;
							}
						}
					}
				}
			}
		}
	}
	for (nPack = 0; nPack < NUM_SHAREDBANK_SLOTS; nPack++)
	{
		PCHARINFO pCharInfo = GetCharInfo();
		PCONTENTS pPack;
		if (pCharInfo->pSharedBankArray && (pPack = pCharInfo->pSharedBankArray->SharedBank[nPack]))
		{
			if (bExact)
			{
				if (!_stricmp(Name, GetItemFromContents(pPack)->Name))
				{
					if ((GetItemFromContents(pPack)->Type != ITEMTYPE_NORMAL) ||
						(((EQ_Item*)pPack)->IsStackable() != 1))
						Count++;
					else
						Count += pPack->StackCount;
				}
			}
			else
			{
				if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pPack)->Name)), Name))
				{
					if ((GetItemFromContents(pPack)->Type != ITEMTYPE_NORMAL) ||
						(((EQ_Item*)pPack)->IsStackable() != 1))
						Count++;
					else
						Count += pPack->StackCount;
				}
			}
			if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->pContentsArray)
			{
				for (unsigned long nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
				{
					if (PCONTENTS pItem = pPack->pContentsArray->Contents[nItem])
					{
						if (bExact)
						{
							if (!_stricmp(Name, GetItemFromContents(pItem)->Name))
							{
								if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
									(((EQ_Item*)pItem)->IsStackable() != 1))
									Count++;
								else
									Count += pItem->StackCount;
							}
						}
						else
						{
							if (strstr(strlwr(strcpy(Temp, GetItemFromContents(pItem)->Name)), Name))
							{
								if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
									(((EQ_Item*)pItem)->IsStackable() != 1))
									Count++;
								else
									Count += pItem->StackCount;
							}
						}
					}
				}
			}
		}
	}

	Ret.DWord = Count;
	Ret.Type = pIntType;

	return true;
}


TLO(dataInvSlot)
{
	if (!ISINDEX())
		return false;
	if (ISNUMBER())
	{
		Ret.DWord = GETNUMBER();
		Ret.Type = pInvSlotType;
		return true;
	}
	else
	{
		CHAR Temp[MAX_STRING] = { 0 };
		strlwr(strcpy(Temp, GETFIRST()));
		Ret.DWord = ItemSlotMap[Temp];
		if (Ret.DWord || !_stricmp(Temp, "charm"))
		{
			Ret.Type = pInvSlotType;
			return true;
		}
	}
	return false;
}

#ifndef ISXEQ
TLO(dataPlugin)
{
	if (!ISINDEX())
		return false;
	if (ISNUMBER())
	{
		unsigned long N = GETNUMBER() - 1;
		PMQPLUGIN pPlugin = pPlugins;
		while (N)
		{
			pPlugin = pPlugin->pNext;
			if (!pPlugin)
				return false;
			N--;
		}
		Ret.Ptr = pPlugin;
		Ret.Type = pPluginType;
		return true;
	}
	else
	{
		// name
		PMQPLUGIN pPlugin = pPlugins;
		while (pPlugin)
		{
			if (!_stricmp(pPlugin->szFilename, szIndex))
			{
				Ret.Ptr = pPlugin;
				Ret.Type = pPluginType;
				return true;
			}
			pPlugin = pPlugin->pNext;
		}
	}
	return false;
}
#endif

TLO(dataSkill)
{
	if (!ISINDEX())
		return false;
	if (ISNUMBER())
	{
		unsigned long nSkill = GETNUMBER() - 1;
		if (nSkill >= NUM_SKILLS)
			return false;
		if (Ret.Ptr = &pSkillMgr->pSkill[nSkill])
		{
			Ret.Type = pSkillType;
			return true;
		}
	}
	else
	{
		for (unsigned long nSkill = 0; nSkill<NUM_SKILLS; nSkill++)
		{
			if (PSKILL pSkill = pSkillMgr->pSkill[nSkill])
			{
				if (PCHAR pName = pStringTable->getString(pSkill->nName, 0))
				{
					if (!_stricmp(GETFIRST(), pName))
					{
						Ret.Ptr = &pSkillMgr->pSkill[nSkill];
						Ret.Type = pSkillType;
						return true;
					}
				}
			}
		}
	}

	return false;
}

TLO(dataAltAbility)
{
	if (!ISINDEX())
		return false;
	if (ISNUMBER())
	{
		for (unsigned long nAbility = 0; nAbility<NUM_ALT_ABILITIES; nAbility++)
		{
			if (PALTABILITY pAbility = pAltAdvManager->GetAAById(nAbility))
			{
				if (pAbility->ID == GETNUMBER())
				{
					Ret.Ptr = pAbility;
					Ret.Type = pAltAbilityType;
					return true;
				}
			}
		}
	}
	else
	{
		for (unsigned long nAbility = 0; nAbility<NUM_ALT_ABILITIES; nAbility++)
		{
			if (PALTABILITY pAbility = pAltAdvManager->GetAAById(nAbility))
			{
				
				if (PCHAR pName = pCDBStr->GetString(pAbility->nName, 1, NULL))
				{
					if (!_stricmp(GETFIRST(), pName))
					{
						Ret.Ptr = pAbility;
						Ret.Type = pAltAbilityType;
						return true;
					}
				}
			}
		}
	}

	return false;
}

TLO(dataRaid)
{
	Ret.DWord = 0;
	Ret.Type = pRaidType;
	return true;
}

TLO(dataNamingSpawn)
{
	if (Ret.Ptr = pNamingSpawn)
	{
		Ret.Type = pSpawnType;
		return true;
	}
	return false;
}
//Updated by Red-One Jan 2014
TLO(dataLineOfSight)
{
	if (!GetCharInfo() && !GetCharInfo()->pSpawn)
		return FALSE;
	if (ISINDEX())
	{
		FLOAT P1[3];
		FLOAT P2[3];
		P1[0] = P2[0] = ((PSPAWNINFO)pCharSpawn)->Y;
		P1[1] = P2[1] = ((PSPAWNINFO)pCharSpawn)->X;
		P1[2] = P2[2] = ((PSPAWNINFO)pCharSpawn)->Z;
#ifdef ISXEQ
		if (argc != 6)
			return false;
		P1[0] = (FLOAT)atof(argv[0]);
		P1[1] = (FLOAT)atof(argv[1]);
		P1[2] = (FLOAT)atof(argv[2]);
		P2[0] = (FLOAT)atof(argv[3]);
		P2[1] = (FLOAT)atof(argv[4]);
		P2[2] = (FLOAT)atof(argv[5]);
#else
		if (PCHAR pColon = strchr(szIndex, ':'))
		{
			*pColon = 0;
			if (PCHAR pComma = strchr(&pColon[1], ','))
			{
				*pComma = 0;
				P2[0] = (FLOAT)atof(&pColon[1]);
				*pComma = ',';
				if (PCHAR pComma2 = strchr(&pComma[1], ','))
				{
					*pComma2 = 0;
					P2[1] = (FLOAT)atof(&pComma[1]);
					*pComma2 = ',';
					P2[2] = (FLOAT)atof(&pComma2[1]);
				}
				else
				{
					P2[1] = (FLOAT)atof(&pComma[1]);
				}
			}
			else
				P2[0] = (FLOAT)atof(&pColon[1]);
		}


		if (PCHAR pComma = strchr(szIndex, ','))
		{
			*pComma = 0;
			P1[0] = (FLOAT)atof(szIndex);
			*pComma = ',';
			if (PCHAR pComma2 = strchr(&pComma[1], ','))
			{
				*pComma2 = 0;
				P1[1] = (FLOAT)atof(&pComma[1]);
				*pComma2 = ',';
				P1[2] = (FLOAT)atof(&pComma2[1]);
			}
			else
			{
				P1[1] = (FLOAT)atof(&pComma[1]);
			}
		}
		else
			P1[0] = (FLOAT)atof(szIndex);
#endif

		//DebugSpew("GetDistance3D(%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f)",P1[0],P1[1],P1[2],P2[0],P2[1],P2[2]);
		SPAWNINFO Temp = *GetCharInfo()->pSpawn;
		Temp.Y = P2[0];
		Temp.X = P2[1];
		Temp.Z = P2[2];
		SPAWNINFO Temp2 = *GetCharInfo()->pSpawn;
		Temp2.Y = P1[0];
		Temp2.X = P1[1];
		Temp2.Z = P1[2];
		Ret.DWord = LineOfSight(&Temp, &Temp2);
		Ret.Type = pBoolType;
		return true;
	}

	return false;
}

TLO(dataDoorTarget)
{
	if (Ret.Ptr = &DoorEnviroTarget)
	{
		Ret.Type = pSpawnType;
		return true;
	}
	return false;
}

TLO(dataItemTarget)
{
	if (Ret.Ptr = &EnviroTarget)
	{
		Ret.Type = pSpawnType;
		return true;
	}
	return false;
}

TLO(dataDynamicZone)
{
	Ret.DWord = 0;
	Ret.Type = pDynamicZoneType;
	return true;
}

TLO(dataFriends)
{
	Ret.DWord = 0;
	Ret.Type = pFriendsType;
	return true;
}

TLO(dataTask)
{
	if (Ret.Ptr = pTaskMember)
	{
		Ret.Type = pTaskType;
		return true;
	}
	return false;
}

TLO(dataMount)
{
	if (!ISINDEX())
		return false;
	if (ISNUMBER()) {
		int n = GETNUMBER();
		if (n <= 0)
			return false;
		n--;
		if (CXWnd *krwnd = FindMQ2Window(KeyRingWindowParent)) {
			if (CListWnd *clist = (CListWnd*)krwnd->GetChildItem(MountWindowList)) {
				int numitems = (int)((CSidlScreenWnd*)clist)->Items;
				if (numitems >= n) {
					CXStr Str;
					clist->GetItemText(&Str, n, 2);
					CHAR szOut[255] = { 0 };
					GetCXStr(Str.Ptr, szOut, 254);
					if (szOut[0] != '\0') {
						Ret.DWord = MAKELPARAM(n, 0);
						Ret.Type = pKeyRingType;
						return true;
					}
				}
			}
		}
	}
	else if (PCHAR pName = GETFIRST()) {
		bool bExact = false;
		if (*pName == '=')
		{
			bExact = true;
			pName++;
		}
		if (DWORD n = GetKeyRingIndex(0,pName, bExact)) {
			n--;
			Ret.DWord = MAKELPARAM(n, 0);
			Ret.Type = pKeyRingType;
			return true;
		}
	}
	return false;
}
TLO(dataIllusion)
{
	if (!ISINDEX())
		return false;
	if (ISNUMBER()) {
		int n = GETNUMBER();
		if (n <= 0)
			return false;
		n--;
		if (CXWnd *krwnd = FindMQ2Window(KeyRingWindowParent)) {
			if (CListWnd *clist = (CListWnd*)krwnd->GetChildItem(IllusionWindowList)) {
				int numitems = (int)((CSidlScreenWnd*)clist)->Items;
				if (numitems >= n) {
					CXStr Str;
					clist->GetItemText(&Str, n, 2);
					CHAR szOut[255] = { 0 };
					GetCXStr(Str.Ptr, szOut, 254);
					if (szOut[0] != '\0') {
						Ret.DWord = MAKELPARAM(n, 1);
						Ret.Type = pKeyRingType;
						return true;
					}
				}
			}
		}
	}
	else if (PCHAR pName = GETFIRST()) {
		bool bExact = false;
		if (*pName == '=')
		{
			bExact = true;
			pName++;
		}
		if (DWORD n = GetKeyRingIndex(1, pName, bExact)) {
			n--;
			Ret.DWord = MAKELPARAM(n, 1);
			Ret.Type = pKeyRingType;
			return true;
		}
	}
	return false;
}
TLO(dataAlias)
{
	if (ISINDEX())
	{
		PALIAS pLoop = pAliases;
		while (pLoop)
		{
			if (!_stricmp(pLoop->szName, GETFIRST()))
			{
				Ret.DWord = 1;
				Ret.Type = pBoolType;
				return true;
			}
			pLoop = pLoop->pNext;
		}
	}
	return false;
}
#ifndef EMU
TLO(dataAdvLoot)
{
	Ret.DWord = 0;
	Ret.Type = pAdvLootType;
	return true;
}
#endif
TLO(dataAlert)
{
	if (!ISINDEX()) {
		CHAR szTemp[2048] = { 0 };
		if (CAlerts.ListAlerts(szTemp, 2048)) {
			strcpy_s(DataTypeTemp, szTemp);
			Ret.Ptr = &DataTypeTemp[0];
			Ret.Type = pStringType;
			return true;
		}
		return false;
	}

	if (ISNUMBER()) {
		Ret.DWord = GETNUMBER();
		Ret.Type = pAlertType;
		return true;
	}
	return false;
}