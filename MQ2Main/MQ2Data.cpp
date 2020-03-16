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
	std::map<FLOAT, GROUNDOBJECT>itemmap;
	//if they did ${Ground[name]}
	if (ISINDEX()) {
		if (ISNUMBER())
		{
			int id = GETNUMBER();
			id--;
			if (id < 0)
				id = 0;
			if (pItemList && pItemList->Top)
			{
				PGROUNDITEM pItem = *(PGROUNDITEM*)pItemList;
				while (pItem) {
					FLOAT X = ((PSPAWNINFO)pCharSpawn)->X - pItem->X;
					FLOAT Y = ((PSPAWNINFO)pCharSpawn)->Y - pItem->Y;
					FLOAT Z = 0;
					if (pItem->pSwitch)
						Z = ((PSPAWNINFO)pCharSpawn)->Z - pItem->pSwitch->Z;
					else
						Z = ((PSPAWNINFO)pCharSpawn)->Z - pItem->Z;
					float dist = sqrtf(X*X + Y * Y + Z * Z);
					itemmap[dist].Type = GO_GroundType;
					itemmap[dist].pGroundItem = pItem;
					pItem = pItem->pNext;
				}
			}
			//lets see if there are any objects that match as well:
			RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
			if (&manager)
			{
				if (EQPlacedItemManager *pPIM = &EQPlacedItemManager::Instance())
				{
					for (EQPlacedItem *pObj = pPIM->Top; pObj != NULL; pObj = pObj->pNext)
					{
						const RealEstateItemClient* pRealEstateItem = manager.GetItemByRealEstateAndItemIds(pObj->RealEstateID, pObj->RealEstateItemID);
						if (pRealEstateItem)
						{
							if (PCONTENTS pCont = pRealEstateItem->Object.pItemBase.pObject)
							{
								if (PITEMINFO pItem = GetItemFromContents(pCont))
								{
									FLOAT X = ((PSPAWNINFO)pCharSpawn)->X - pObj->X;
									FLOAT Y = ((PSPAWNINFO)pCharSpawn)->Y - pObj->Y;
									FLOAT Z = ((PSPAWNINFO)pCharSpawn)->Z - pObj->Z;
									float dist = sqrtf(X*X + Y * Y + Z * Z);
									itemmap[dist].Type = GO_ObjectType;
									itemmap[dist].ObjPtr = pObj;
								}
							}
						}
					}
				}
			}
			if ((int)itemmap.size() > id)
			{
				std::map<FLOAT, GROUNDOBJECT>::iterator it = itemmap.begin();
				std::advance(it, id);
				if (it != itemmap.end())
				{
					memcpy(&GroundObject, &it->second, sizeof(GROUNDOBJECT));
					Ret.Ptr = &GroundObject;
					Ret.Type = pGroundType;
					return true;
				}
			}
			return false;
		}
		else
		{
			CHAR szSearch[MAX_STRING] = { 0 };
			strcpy_s(szSearch, GETFIRST());
			_strlwr_s(szSearch);
			CHAR szName[MAX_STRING] = { 0 };
			if (pItemList && pItemList->Top)
			{
				PGROUNDITEM pItem = *(PGROUNDITEM*)pItemList;
				while (pItem) {
					GetFriendlyNameForGroundItem(pItem, szName, sizeof(szName));
					_strlwr_s(szName);
					if (strstr(szName, szSearch)) {
						FLOAT X = ((PSPAWNINFO)pCharSpawn)->X - pItem->X;
						FLOAT Y = ((PSPAWNINFO)pCharSpawn)->Y - pItem->Y;
						FLOAT Z = 0;
						if (pItem->pSwitch)
							Z = ((PSPAWNINFO)pCharSpawn)->Z - pItem->pSwitch->Z;
						else
							Z = ((PSPAWNINFO)pCharSpawn)->Z - pItem->Z;
						float dist = sqrtf(X*X + Y * Y + Z * Z);
						itemmap[dist].Type = GO_GroundType;
						itemmap[dist].pGroundItem = pItem;
					}
					pItem = pItem->pNext;
				}
			}
			//lets see if there are any objects that match as well:
			RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
			if (&manager)
			{
				if (EQPlacedItemManager *pPIM = &EQPlacedItemManager::Instance())
				{
					for (EQPlacedItem *pObj = pPIM->Top; pObj != NULL; pObj = pObj->pNext)
					{
						const RealEstateItemClient* pRealEstateItem = manager.GetItemByRealEstateAndItemIds(pObj->RealEstateID, pObj->RealEstateItemID);
						if (pRealEstateItem)
						{
							if (PCONTENTS pCont = pRealEstateItem->Object.pItemBase.pObject)
							{
								if (PITEMINFO pItem = GetItemFromContents(pCont))
								{
									strcpy_s(szName, pItem->Name);
									_strlwr_s(szName);
									if (strstr(szName, szSearch)) {
										FLOAT X = ((PSPAWNINFO)pCharSpawn)->X - pObj->X;
										FLOAT Y = ((PSPAWNINFO)pCharSpawn)->Y - pObj->Y;
										FLOAT Z = ((PSPAWNINFO)pCharSpawn)->Z - pObj->Z;
										float dist = sqrtf(X*X + Y * Y + Z * Z);
										itemmap[dist].Type = GO_ObjectType;
										itemmap[dist].ObjPtr = pObj;
									}
								}
							}
						}
					}
				}
			}
		}
		//we got some objects return the closest
		if (itemmap.size()) {
			memcpy(&GroundObject, &itemmap.begin()->second, sizeof(GROUNDOBJECT));
			Ret.Ptr = &GroundObject;
			Ret.Type = pGroundType;
			return true;
		}
		return false;
	}
	else if (GroundObject.Type!=GO_None)//they already did /itemtarget so return that.
	{
		Ret.Ptr = &GroundObject;
		Ret.Type = pGroundType;
		return true;
	}
	//well they didn't specify a name and they have not done /itemtarget
	//so we just return first closest entry found
	float grounddist = 100000.0f;
	float objectdist = 100000.0f;
	if (PGROUNDITEM pItem = *(PGROUNDITEM*)pItemList)
	{
		FLOAT X = ((PSPAWNINFO)pCharSpawn)->X - pItem->X;
		FLOAT Y = ((PSPAWNINFO)pCharSpawn)->Y - pItem->Y;
		FLOAT Z = 0;
		if (pItem->pSwitch)
			Z = ((PSPAWNINFO)pCharSpawn)->Z - pItem->pSwitch->Z;
		else
			Z = ((PSPAWNINFO)pCharSpawn)->Z - pItem->Z;
		grounddist = sqrtf(X*X + Y * Y + Z * Z);
		GroundObject.pGroundItem = pItem;
		GroundObject.Type = GO_GroundType;
	}
	RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
	if (&manager)
	{
		if (EQPlacedItemManager *pPIM = &EQPlacedItemManager::Instance())
		{
			if (EQPlacedItem *top = pPIM->Top)
			{
				FLOAT X = ((PSPAWNINFO)pCharSpawn)->X - top->X;
				FLOAT Y = ((PSPAWNINFO)pCharSpawn)->Y - top->Y;
				FLOAT Z = ((PSPAWNINFO)pCharSpawn)->Z - top->Z;
				objectdist = sqrtf(X*X + Y * Y + Z * Z);
				GroundObject.ObjPtr = (void*)top;
				GroundObject.Type = GO_ObjectType;
			}
		}
	}
	if (GroundObject.Type!=GO_None)
	{
		if (objectdist > grounddist)
		{
			GroundObject.Type = GO_GroundType;
		}
		else {
			GroundObject.Type = GO_ObjectType;
		}
		Ret.Ptr = &GroundObject;
		Ret.Type = pGroundType;
		return true;
	}
	return false;
}
TLO(dataGroundItemCount)
{
	Ret.DWord = 0;
	Ret.Type = pIntType;
	if (!pItemList)
		return true;
	if (PGROUNDITEM pItem = *(PGROUNDITEM*)pItemList)
	{
		DWORD Count = 0;
		if (ISINDEX()) {
			CHAR szSearch[MAX_STRING] = { 0 };
			strcpy_s(szSearch, GETFIRST());
			_strlwr_s(szSearch);
			CHAR szName[MAX_STRING] = { 0 };
			while (pItem) {
				GetFriendlyNameForGroundItem(pItem, szName, sizeof(szName));
				_strlwr_s(szName);
				if (strstr(szName, szSearch)) {
					Count++;
				}
				pItem = pItem->pNext;
			}
			Ret.DWord = Count;
		}
		else {
			while (pItem) {
				Count++;
				pItem = pItem->pNext;
			}
			Ret.DWord = Count;
		}
	}
	return true;
}
TLO(dataMerchant)
{
	Ret.Ptr = pActiveMerchant;
	Ret.Type = pMerchantType;
	return true;
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

TLO(dataMenu)
{
	if (CContextMenuManager*pMrg = pContextMenuManager)
	{
		if (Ret.Ptr = pMrg)
		{
			Ret.Type = pMenuType;
			return true;
		}
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
			if (PCHARINFO pChar = GetCharInfo()) {
				if ((pChar->zoneId & 0x7FFF) == nIndex)
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
	}
	else if ((nIndex = GetZoneID(GETFIRST())) != -1)
	{
		if (PCHARINFO pChar = GetCharInfo()) {
			if ((pChar->zoneId & 0x7FFF) == nIndex)
			{
				Ret.DWord = instEQZoneInfo;
				Ret.Type = pCurrentZoneType;
			}
			else if (nIndex < MAX_ZONES)
			{
				Ret.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[nIndex];
				Ret.Type = pZoneType;
			}
			return true;
		}
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
	strcpy_s(DataTypeTemp,szIndex);
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
		//changed
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
		Ret.Float = (FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - Y, X - ((PSPAWNINFO)pLocalPlayer)->X) * 180.0f / PI + 90.0f);
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
	Ret.DWord = (_stricmp(szIndex, "NULL") && _stricmp(szIndex, "FALSE") &&	strcmp(szIndex, "0"));
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
						strcpy_s(DataTypeTemp, pTrue);
						Ret.Ptr = &DataTypeTemp[0];
						Ret.Type = pStringType;
						return true;
					}
					else
					{
						strcpy_s(DataTypeTemp, pFalse);
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
					strcpy_s(DataTypeTemp, pTrue);
					Ret.Ptr = &DataTypeTemp[0];
					Ret.Type = pStringType;
					return true;
				}
				else
				{
					strcpy_s(DataTypeTemp, pFalse);
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
	if (PCHARINFO2 pChar2 = GetCharInfo2()) {
		if (pChar2->pInventoryArray) {
			if (Ret.Ptr = pChar2->pInventoryArray->Inventory.Cursor)
			{
				Ret.Type = pItemType;
				return true;
			}
		}
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
			int N = GETNUMBER() - 1;
			if (N < 0)
				N = 0;
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
	time_t CurTime = { 0 };
	time(&CurTime);
	struct tm* pTime = (struct tm*)&DataTypeTemp[0];
	ZeroMemory(pTime, sizeof(struct tm));
	localtime_s(pTime,&CurTime);
	Ret.Ptr = pTime;
	Ret.Type = pTimeType;
	return true;
}
TLO(dataGameTime)
{
	struct tm* pTime = (struct tm*)&DataTypeTemp[0];
	ZeroMemory(pTime, sizeof(struct tm));
	pTime->tm_sec = 0;
	pTime->tm_min = ((PWORLDDATA)pWorldData)->Minute;
	pTime->tm_hour = ((PWORLDDATA)pWorldData)->Hour - 1;
	pTime->tm_mday = ((PWORLDDATA)pWorldData)->Day;
	pTime->tm_mon = ((PWORLDDATA)pWorldData)->Month - 1;
	pTime->tm_year = ((PWORLDDATA)pWorldData)->Year - 1900;
	pTime->tm_wday = (((PWORLDDATA)pWorldData)->Day - 1) % 7;
	pTime->tm_isdst = 0;

	Ret.Ptr = pTime;
	Ret.Type = pTimeType;
	return true;
}

TLO(dataRange)
{
	Ret.DWord = 1;
	Ret.Type = pRangeType;
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
	bool bNoParse = false;
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
				if (argmap.size() >= 4) {
					Default.erase(argmap[3] - argmap[2] - 1);
					std::string Parse = sTemp.substr(argmap[3] + 1);
					if (Parse == "noparse")
						bNoParse = true;
				}
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
			if (bNoParse) {
				if (gdwParserEngineVer == 2) {
					// If we're set not to parse and there's a ${
					if (Default.find("${") != std::string::npos) {
						// Modify Macro String with parameter 0 to wrap Parse Zero
						Default = ModifyMacroString(Default, true, 0);
					}
				}
				// I think the below is actually wrong, since it's checking whatever was stored in
				// DataTypeTemp BEFORE instead of checking what's in Default, but I didn't track it down
				// to see if DataTypeTemp was getting set to default somewhere else and this is how
				// it was originally in parser v1. So I left it.  -- Knightly
				else if (strchr(DataTypeTemp, '$')) {
					bAllowCommandParse = false;
				}
			}
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
		if (bNoParse) {
				if (gdwParserEngineVer == 2) {			
					// If we are not supposed to parse and there is a ${
					if (strstr(DataTypeTemp, "${"))
					{
						// Modify Macro String with parameter 0 to wrap Parse Zero
						strcpy_s(DataTypeTemp, ModifyMacroString(DataTypeTemp, true, 0).c_str());
					}
				}
				else if (strchr(DataTypeTemp, '$'))
				{
					bAllowCommandParse = false;
				}
		}
		Ret.Ptr = &DataTypeTemp[0];
		Ret.Type = pStringType;
		return true;
	}
	if (Default.size())
	{
		if (bNoParse) {
			if (gdwParserEngineVer == 2) {
				// If we're set not to parse and there's a ${
				if (Default.find("${") != std::string::npos) {
					// Modify Macro String with parameter 0 to wrap Parse Zero
					Default = ModifyMacroString(Default, true, 0);
				}
			}
			// I think the below is actually wrong, since it's checking whatever was stored in
			// DataTypeTemp BEFORE instead of checking what's in Default, but I didn't track it down
			// to see if DataTypeTemp was getting set to default somewhere else and this is how
			// it was originally in parser v1. So I left it.  -- Knightly
			else if (strchr(DataTypeTemp, '$')) {
				bAllowCommandParse = false;
			}
		}		
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
TLO(dataSubDefined)
{
    if (!ISINDEX())
        return false;
    Ret.DWord = gMacroBlock && (gMacroSubLookupMap.find(szIndex) != gMacroSubLookupMap.end());
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
			if (pItem && pInvSlotMgr) {
				CInvSlot *pSlot = pInvSlotMgr->FindInvSlot(pItem->GetGlobalIndex().Index.Slot1);
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
	PCONTENTS pItem = 0;
	if (ISNUMBER()) {
		if (pItem = FindBankItemByID(GETNUMBER())) {
			Ret.Ptr = pItem;
			Ret.Type = pItemType;
			return true;
		}
		return false;
	}
	PCHAR pName = GETFIRST();
	BOOL bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}

	if (pItem = FindBankItemByName(pName, bExact)) {
		Ret.Ptr = pItem;
		Ret.Type = pItemType;
		return true;
	}
	return false;
}

TLO(dataFindItem)
{
	if (!ISINDEX())
		return false;
	PCONTENTS pItem = 0;
	if (ISNUMBER()) {
		if (pItem = FindItemByID(GETNUMBER())) {
			Ret.Ptr = pItem;
			Ret.Type = pItemType;
			return true;
		}
		return false;
	}
	PCHAR pName = GETFIRST();
	BOOL bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}
	if (pItem = FindItemByName(pName, bExact)) {
		Ret.Ptr = pItem;
		Ret.Type = pItemType;
		return true;
	}
	return false;
}

TLO(dataFindItemCount)
{
	if (!ISINDEX())
		return false;
	if (ISNUMBER()) {
		Ret.DWord = FindItemCountByID(GETNUMBER());
		Ret.Type = pIntType;
		return true;
	}
	PCHAR pName = GETFIRST();
	BOOL bExact = false;
	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}
	Ret.DWord = FindItemCountByName(pName, bExact);
	Ret.Type = pIntType;
	return true;
}

TLO(dataFindItemBankCount)
{
	if (!ISINDEX())
		return false;
	if (ISNUMBER()) {
		Ret.DWord = FindBankItemCountByID(GETNUMBER());
		Ret.Type = pIntType;
		return true;
	}
	PCHAR pName = GETFIRST();
	BOOL bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}
	Ret.DWord = FindBankItemCountByName(pName, bExact);
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
		strcpy_s(Temp, GETFIRST());
		_strlwr_s(Temp);
		Ret.DWord = 0;
		if (ItemSlotMap.find(Temp) != ItemSlotMap.end())
		{
			Ret.DWord = ItemSlotMap[Temp];
		}
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
		int N = GETNUMBER() - 1;
		if (N < 0)
			N = 0;
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
		int nSkill = GETNUMBER() - 1;
		if (nSkill < 0)
			nSkill = 0;
		if (nSkill > NUM_SKILLS)
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
			if (PALTABILITY pAbility = GetAAByIdWrapper(nAbility))
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
		//we need to get the level appropriate one if they just supplied a name
		int level = -1;
		if (PSPAWNINFO pMe = (PSPAWNINFO)pLocalPlayer) {
			level = pMe->Level;
		}
		for (unsigned long nAbility = 0; nAbility<NUM_ALT_ABILITIES; nAbility++)
		{
			if (PALTABILITY pAbility = GetAAByIdWrapper(nAbility, level))
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
	Ret.Type = pTaskType;
	Ret.DWord = (int)MAKELPARAM(TST_SoloQuest, 0xFFFFFFFF);
	if (CTaskManager*tm = ppTaskManager)
	{
		if (ISINDEX())
		{
			CTaskEntry * sharedentry = (CTaskEntry *)&tm->SharedTaskEntries[0];
			if (ISNUMBER())
			{
				int n = GETNUMBER();
				n--;
				if (n < 0)
					n = 0;
				if (n > 28)
					n = 28;

				//well, if it is 0, and we have a shared quest, then we need to return that...
				//people really should not use index by number it's stupid and lazy.
				if (n==0 && sharedentry && sharedentry->TaskID)
				{
					Ret.DWord = (int)MAKELPARAM(TST_SharedQuest, 0);
					return true;
				}
				else
				{
					if (CTaskEntry * entry = &tm->QuestEntries[n])
					{
						if (entry->TaskID)
						{
							Ret.DWord = (int)MAKELPARAM(TST_SoloQuest, n);
							return true;
						}
					}
				}
			}
			else
			{
				CHAR szOut[MAX_STRING] = { 0 };
				CHAR szTemp[MAX_STRING] = { 0 };
				strcpy_s(szTemp, GETFIRST());
				_strlwr_s(szTemp);
				PCHAR pName = &szTemp[0];
				bool bExact = false;
				if (*pName == '=')
				{
					bExact = true;
					pName++;
				}
				//need to check this first
				if(sharedentry && sharedentry->TaskID)
				{
					if (bExact)
					{
						if (!_stricmp(sharedentry->TaskTitle, pName))
						{
							Ret.DWord = (int)MAKELPARAM(TST_SharedQuest, 0);
							return true;
						}
					}
					else
					{
						strcpy_s(szOut, sharedentry->TaskTitle);
						_strlwr_s(szOut);
						if (strstr(szOut, pName))
						{
							//ok we actually do have one, and its always index 0 but 0 can also be a valid
							//index for solo quests so we need to se it to something else
							Ret.DWord = (int)MAKELPARAM(TST_SharedQuest, 0);
							return true;
						}
					}
				}
				//lets roll through solo quests if we got this far...
				for (int i = 0; i < 29; i++)
				{
					if (CTaskEntry * entry = &tm->QuestEntries[i])
					{
						if (bExact)
						{
							if (!_stricmp(entry->TaskTitle, pName))
							{
								Ret.DWord = (int)MAKELPARAM(TST_SoloQuest, i);
								return true;
							}
						}
						else
						{
							strcpy_s(szOut, entry->TaskTitle);
							_strlwr_s(szOut);
							if (strstr(szOut, pName)) {
								Ret.DWord = (int)MAKELPARAM(TST_SoloQuest, i);
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
				int numitems = clist->ItemsArray.Count;
				if (numitems >= n) {
					CXStr Str;
					clist->GetItemText(&Str, n, 2);
					CHAR szOut[MAX_STRING] = { 0 };
					GetCXStr(Str.Ptr, szOut, MAX_STRING);
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
				int numitems = clist->ItemsArray.Count;
				if (numitems >= n) {
					CXStr Str;
					clist->GetItemText(&Str, n, 2);
					CHAR szOut[MAX_STRING] = { 0 };
					GetCXStr(Str.Ptr, szOut, MAX_STRING);
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
TLO(dataFamiliar)
{
	if (!ISINDEX())
		return false;
	if (ISNUMBER()) {
		int n = GETNUMBER();
		if (n <= 0)
			return false;
		n--;
		if (CXWnd *krwnd = FindMQ2Window(KeyRingWindowParent)) {
			if (CListWnd *clist = (CListWnd*)krwnd->GetChildItem(FamiliarWindowList)) {
				int numitems = clist->ItemsArray.Count;
				if (numitems >= n) {
					CXStr Str;
					clist->GetItemText(&Str, n, 2);
					CHAR szOut[MAX_STRING] = { 0 };
					GetCXStr(Str.Ptr, szOut, MAX_STRING);
					if (szOut[0] != '\0') {
						Ret.DWord = MAKELPARAM(n, 2);
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
		if (DWORD n = GetKeyRingIndex(2, pName, bExact)) {
			n--;
			Ret.DWord = MAKELPARAM(n, 2);
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
		std::string sName = GETFIRST();
		std::transform(sName.begin(), sName.end(), sName.begin(), tolower);
		if (mAliases.find(sName) != mAliases.end()) {
			Ret.DWord = 1;
			Ret.Type = pBoolType;
			return true;
		}
	}
	return false;
}
#if !defined(ROF2EMU) && !defined(UFEMU)
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
TLO(dataPointMerchant)
{
#if !defined(ROF2EMU) && !defined(UFEMU)
	if (pMerchantWnd)
	{
		Ret.Ptr = pMerchantWnd;
#else
	if (pPointMerchantWnd)
	{
		Ret.Ptr = pPointMerchantWnd;
#endif
		Ret.Type = pPointMerchantType;
		return true;
	}
	return false;
}
