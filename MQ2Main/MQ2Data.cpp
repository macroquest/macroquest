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

#include "MQ2Main.h"

BOOL dataSpawn(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (szIndex[0])
	{
		if (IsNumber(szIndex))
		{
			if (Ret.Ptr = GetSpawnByID(atoi(szIndex)))
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
			ParseSearchSpawn(szIndex, &ssSpawn);
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

BOOL dataSelect(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;

	// I hate this GetArg shit - Lax
	char szArg[MAX_STRING] = { 0 };
	char szArg1[MAX_STRING] = { 0 };
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

BOOL dataTarget(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (pTarget)
	{
		Ret.Ptr = pTarget;
		Ret.Type = pTargetType;
		return true;
	}
	return false;
}

BOOL dataCharacter(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (pCharData)
	{
		Ret.Ptr = pCharData;
		Ret.Type = pCharacterType;
		return true;
	}
	return false;
}

BOOL dataSpell(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (szIndex[0])
	{
		if (IsNumber(szIndex))
		{
			if (Ret.Ptr = GetSpellByID(atoi(szIndex)))
			{
				Ret.Type = pSpellType;
				return true;
			}
		}
		else
		{
			if (Ret.Ptr = GetSpellByName(szIndex))
			{
				Ret.Type = pSpellType;
				return true;
			}
			//is it an AA?
			if (Ret.Ptr = GetSpellByAAName(szIndex))
			{
				Ret.Type = pSpellType;
				return true;
			}
		}
	}
	return false;
}

BOOL dataSwitch(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (pDoorTarget)
	{
		Ret.Ptr = pDoorTarget;
		Ret.Type = pSwitchType;
		return true;
	}
	return false;
}

BOOL dataGroundItem(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	std::map<float, GROUNDOBJECT>itemmap;
	//if they did ${Ground[name]}
	if (szIndex[0]) {
		char szSearch[MAX_STRING] = { 0 };
		strcpy_s(szSearch, szIndex);
		_strlwr_s(szSearch);
		char szName[MAX_STRING] = { 0 };
		if (pItemList && pItemList->Top)
		{
			PGROUNDITEM pItem = *(PGROUNDITEM*)pItemList;
			while (pItem) {
				GetFriendlyNameForGroundItem(pItem, szName, sizeof(szName));
				_strlwr_s(szName);
				if (strstr(szName, szSearch)) {
					float X = ((PSPAWNINFO)pCharSpawn)->X - pItem->X;
					float Y = ((PSPAWNINFO)pCharSpawn)->Y - pItem->Y;
					float Z = 0;
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
						if (CONTENTS* pCont = pRealEstateItem->Object.pItemBase.pObject)
						{
							if (PITEMINFO pItem = GetItemFromContents(pCont))
							{
								strcpy_s(szName, pItem->Name);
								_strlwr_s(szName);
								if (strstr(szName, szSearch)) {
									float X = ((PSPAWNINFO)pCharSpawn)->X - pObj->X;
									float Y = ((PSPAWNINFO)pCharSpawn)->Y - pObj->Y;
									float Z = ((PSPAWNINFO)pCharSpawn)->Z - pObj->Z;
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
		//we got some objects return the closest
		if (itemmap.size()) {
			memcpy(&GroundObject, &itemmap.begin()->second, sizeof(GROUNDOBJECT));
			Ret.Ptr = &GroundObject;
			Ret.Type = pGroundType;
			return true;
		}
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
		float X = ((PSPAWNINFO)pCharSpawn)->X - pItem->X;
		float Y = ((PSPAWNINFO)pCharSpawn)->Y - pItem->Y;
		float Z = 0;
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
				float X = ((PSPAWNINFO)pCharSpawn)->X - top->X;
				float Y = ((PSPAWNINFO)pCharSpawn)->Y - top->Y;
				float Z = ((PSPAWNINFO)pCharSpawn)->Z - top->Z;
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
BOOL dataGroundItemCount(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pIntType;
	if (!pItemList)
		return true;
	if (PGROUNDITEM pItem = *(PGROUNDITEM*)pItemList)
	{
		DWORD Count = 0;
		if (szIndex[0]) {
			char szSearch[MAX_STRING] = { 0 };
			strcpy_s(szSearch, szIndex);
			_strlwr_s(szSearch);
			char szName[MAX_STRING] = { 0 };
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
BOOL dataMerchant(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	Ret.Ptr = pActiveMerchant;
	Ret.Type = pMerchantType;
	return true;
}
BOOL dataMercenary(PCHAR szIndex, MQ2TYPEVAR& Ret)
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
BOOL dataPet(PCHAR szIndex, MQ2TYPEVAR& Ret)
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

BOOL dataCorpse(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (pLootWnd)
	{
		Ret.Ptr = pLootWnd;
		Ret.Type = pCorpseType;
		return true;
	}
	return false;
}

BOOL dataMenu(PCHAR szIndex, MQ2TYPEVAR& Ret)
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
BOOL dataWindow(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (szIndex[0])
	{
		if (Ret.Ptr = FindMQ2Window(szIndex))
		{
			Ret.Type = pWindowType;
			return true;
		}
	}
	return false;
}

BOOL dataMacro(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (gRunning)
	{
		Ret.Ptr = 0;
		Ret.Type = pMacroType;
		return true;
	}
	return false;
}

BOOL dataMacroQuest(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	Ret.Ptr = 0;
	Ret.Type = pMacroQuestType;
	return true;
}

BOOL dataEverQuest(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	Ret.Ptr = 0;
	Ret.Type = pEverQuestType;
	return true;
}

BOOL dataMath(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	Ret.Ptr = 0;
	Ret.Type = pMathType;
	return true;
}

BOOL dataZone(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	int nIndex = 0;
	PZONELIST pZone = NULL;

	if (!szIndex[0])
	{
		Ret.DWord = instEQZoneInfo;
		Ret.Type = pCurrentZoneType;
		return true;
	}
	else if (IsNumber(szIndex))
	{
		if (nIndex = (atoi(szIndex) & 0x7FFF))
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
	else if ((nIndex = GetZoneID(szIndex)) != -1)
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

BOOL dataInt(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	Ret.DWord = atol(szIndex);
	Ret.Type = pIntType;
	return true;
}

BOOL dataString(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	WriteChatf("Due to complete misuse of the String Top-Level Object, it has been removed.");
	return false;
	/*
	if (!szIndex[0])
	return false;
	strcpy_s(DataTypeTemp,szIndex);
	Ret.Ptr=&DataTypeTemp[0];
	Ret.Type=pStringType;
	return true;
	/**/
}

BOOL dataFloat(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	Ret.Float = (float)atof(szIndex);
	Ret.Type = pFloatType;
	return true;
}

BOOL dataHeading(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	if (PCHAR pComma = strchr(szIndex, ','))
	{
		*pComma = 0;
		float Y = (float)atof(szIndex);
		*pComma = ',';
		float X = (float)atof(&pComma[1]);
		//changed
		Ret.Float = (float)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - Y, X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
		if (Ret.Float<0.0f)
			Ret.Float += 360.0f;
		else if (Ret.Float >= 360.0f)
			Ret.Float -= 360.0f;
		Ret.Type = pHeadingType;
		return true;
	}

	Ret.Float = (float)atof(szIndex);
	Ret.Type = pHeadingType;
	return true;
}

BOOL dataBool(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	Ret.DWord = (_stricmp(szIndex, "NULL") && _stricmp(szIndex, "FALSE") &&	strcmp(szIndex, "0"));
	Ret.Type = pBoolType;
	return true;
}

/*
BOOL dataGroupLeader(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!GroupLeader[0] || !_stricmp(GroupLeader, GetCharInfo()->pSpawn->Name))
	{
		Ret.Ptr = GetCharInfo()->pSpawn;
		Ret.Type = pSpawnType;
		return true;
	}
	for (unsigned long N = 0; N < 5; N++)
	{
		if (EQADDR_GROUPCOUNT[N])
		{
			if (PSPAWNINFO pSpawn = (PSPAWNINFO)ppGroup[N])
			{
				if (!_stricmp(pSpawn->Name, GroupLeader))
				{
					Ret.Ptr = pSpawn;
					Ret.Type = pSpawnType;
					return true;
				}
			}
		}
	}
	return false;
}
/**/

/*
BOOL dataGroupLeaderName(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!GroupLeader[0])
	{
		Ret.Ptr = GetCharInfo()->pSpawn->Name;
		Ret.Type = pStringType;
		return true;
	}
	Ret.Ptr = &GroupLeader[0];
	Ret.Type = pStringType;
	return true;
}
/**/

BOOL dataGroup(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	Ret.DWord = 1;
	Ret.Type = pGroupType;
	return true;

	/*
	if (szIndex[0])
	{
		DWORD N = atoi(szIndex);
		if (N == 0)
		{
			return dataCharacter("", Ret);
		}
		if (N > 5)
			return false;
		for (unsigned long i = 0; i < 5; i++)
		{
			if (EQADDR_GROUPCOUNT[i])
			{
				N--;
				if (N == 0)
				{
					Ret.Ptr = ppGroup[i];
					Ret.Type = pSpawnType;
					return true;
				}
			}
		}
		return false;
	}
	else
	{
		Ret.DWord = 0;
		for (int index = 0; index < 5; index++)
			if (EQADDR_GROUPCOUNT[index])
				Ret.DWord++;
		Ret.Type = pIntType;
		return true;
	}
	return false;
	/**/
}

BOOL dataIf(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (szIndex[0])
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
					double CalcResult;
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
				double CalcResult;
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

BOOL dataCursor(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (CHARINFO2* pChar2 = GetCharInfo2()) {
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

BOOL dataLastSpawn(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (szIndex[0])
	{
		if (szIndex[0] == '-')
		{
			unsigned long N = atoi(&szIndex[1]) - 1;
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
		else if (IsNumber(szIndex))
		{
			int N = atoi(szIndex) - 1;
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

BOOL dataNearestSpawn(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (szIndex[0])
	{
		unsigned long nth;
		SEARCHSPAWN ssSpawn;
		ClearSearchSpawn(&ssSpawn);
		ssSpawn.FRadius = 999999.0f;
		PCHAR pSearch;
		if (pSearch = strchr(szIndex, ','))
		{
			*pSearch = 0;
			++pSearch;
			ParseSearchSpawn(pSearch, &ssSpawn);
			nth = atoi(szIndex);
		}
		else
		{
			if (IsNumberToComma(szIndex))
			{
				nth = atoi(szIndex);
			}
			else
			{
				nth = 1;
				ParseSearchSpawn(szIndex, &ssSpawn);
			}
		}

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

BOOL dataSpawnCount(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (szIndex[0])
	{
		SEARCHSPAWN ssSpawn;
		ClearSearchSpawn(&ssSpawn);
		ParseSearchSpawn(szIndex, &ssSpawn);
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

BOOL dataTime(PCHAR szIndex, MQ2TYPEVAR& Ret)
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
BOOL dataGameTime(PCHAR szIndex, MQ2TYPEVAR& Ret)
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

BOOL dataRange(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	Ret.DWord = 1;
	Ret.Type = pRangeType;
	return true;
}

BOOL dataIni(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
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
	char FileName[MAX_STRING] = { 0 };
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
			if (gknightlyparse)
			{
				// If we're set not to parse and there's a ${
				if (bNoParse && Default.find("${") != std::string::npos)
				{
					// Wrap this in a $Parse[0 so it doesn't get parsed
					Default = PARSE_PARAM_BEG + "0," + Default + PARSE_PARAM_END;
				}
			}
			else
			{
				// I think the below is actually wrong, since it's checking whatever was stored in
				// DataTypeTemp BEFORE instead of checking what's in Default, but I didn't track it down
				// to see if DataTypeTemp was getting set to default somewhere else. --Knightly
				if (bNoParse && strchr(DataTypeTemp, '$'))
					bAllowCommandParse = false;
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
		if (gknightlyparse)
		{
			// If we are not supposed to parse and there is a ${
			if (bNoParse && strstr(DataTypeTemp, "${"))
			{
				// Modify Macro String with parameter 0 to wrap Parse Zero
				strcpy_s(DataTypeTemp, ModifyMacroString(DataTypeTemp, true, 0).c_str());
			}
		}
		else
		{
			if (bNoParse && strchr(DataTypeTemp, '$'))
				bAllowCommandParse = false;
		}
		Ret.Ptr = &DataTypeTemp[0];
		Ret.Type = pStringType;
		return true;
	}
	if (Default.size())
	{
		if (gknightlyparse)
		{
			// If we're set not to parse and there's a ${
			if (bNoParse && Default.find("${") != std::string::npos)
			{
				// Modify Macro String with parameter 0 to wrap Parse Zero
				Default = ModifyMacroString(Default, true, 0);
			}
		}
		else
		{
			// I think the below is actually wrong, since it's checking whatever was stored in
			// DataTypeTemp BEFORE instead of checking what's in Default, but I didn't track it down
			// to see if DataTypeTemp was getting set to default somewhere else. --Knightly
			if (bNoParse && strchr(DataTypeTemp, '$'))
				bAllowCommandParse = false;
		}
		strcpy_s(DataTypeTemp, Default.c_str());
		Ret.Ptr = &DataTypeTemp[0];
		Ret.Type = pStringType;
		return true;
	}

	return false;
}

BOOL dataDefined(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	Ret.DWord = (FindMQ2DataVariable(szIndex) != 0);
	Ret.Type = pBoolType;
	return true;
}

BOOL dataSubDefined(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	Ret.DWord = gMacroBlock && (gMacroSubLookupMap.find(szIndex) != gMacroSubLookupMap.end());
	Ret.Type = pBoolType;
	return true;
}

BOOL dataSelectedItem(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (pInvSlotMgr->pSelectedItem && pInvSlotMgr->pSelectedItem->Index)
	{
		CInvSlot* pCIS = pInvSlotMgr->pSelectedItem;

		CONTENTS* pC = nullptr;
		pCIS->GetItemBase(&pC);

		if (pC)
		{
			Ret.Ptr = pC;
			Ret.Type = pItemType;
			return true;
		}
		else
		{
			CONTENTS* pItem = FindItemByName("Worn Totem");

			if (pItem && pInvSlotMgr)
			{
				CInvSlot* pSlot = pInvSlotMgr->FindInvSlot(pItem->GetGlobalIndex().GetTopSlot());
				Sleep(0);
			}
		}
	}
	return false;
}

BOOL dataFindItemBank(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	CONTENTS* pItem = 0;
	if (IsNumber(szIndex)) {
		if (pItem = FindBankItemByID(atoi(szIndex))) {
			Ret.Ptr = pItem;
			Ret.Type = pItemType;
			return true;
		}
		return false;
	}
	PCHAR pName = szIndex;
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

BOOL dataFindItem(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	CONTENTS* pItem = 0;
	if (IsNumber(szIndex)) {
		if (pItem = FindItemByID(atoi(szIndex))) {
			Ret.Ptr = pItem;
			Ret.Type = pItemType;
			return true;
		}
		return false;
	}
	PCHAR pName = szIndex;
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

BOOL dataFindItemCount(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	if (IsNumber(szIndex)) {
		Ret.DWord = FindItemCountByID(atoi(szIndex));
		Ret.Type = pIntType;
		return true;
	}
	PCHAR pName = szIndex;
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

BOOL dataFindItemBankCount(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	if (IsNumber(szIndex)) {
		Ret.DWord = FindBankItemCountByID(atoi(szIndex));
		Ret.Type = pIntType;
		return true;
	}
	PCHAR pName = szIndex;
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


BOOL dataInvSlot(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	if (IsNumber(szIndex))
	{
		Ret.DWord = atoi(szIndex);
		Ret.Type = pInvSlotType;
		return true;
	}
	else
	{
		char Temp[MAX_STRING] = { 0 };
		strcpy_s(Temp, szIndex);
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

BOOL dataPlugin(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	if (IsNumber(szIndex))
	{
		int N = atoi(szIndex) - 1;
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

BOOL dataSkill(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	if (IsNumber(szIndex))
	{
		int nSkill = atoi(szIndex) - 1;
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
					if (!_stricmp(szIndex, pName))
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

BOOL dataAltAbility(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	if (IsNumber(szIndex))
	{
		for (unsigned long nAbility = 0; nAbility<NUM_ALT_ABILITIES; nAbility++)
		{
			if (PALTABILITY pAbility = GetAAByIdWrapper(nAbility))
			{
				if (pAbility->ID == atoi(szIndex))
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
				if (const char* pName = pCDBStr->GetString(pAbility->nName, 1, NULL))
				{
					if (!_stricmp(szIndex, pName))
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

BOOL dataRaid(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pRaidType;
	return true;
}

BOOL dataNamingSpawn(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (Ret.Ptr = pNamingSpawn)
	{
		Ret.Type = pSpawnType;
		return true;
	}
	return false;
}
//Updated by Red-One Jan 2014
BOOL dataLineOfSight(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!GetCharInfo() && !GetCharInfo()->pSpawn)
		return FALSE;
	if (szIndex[0])
	{
		float P1[3];
		float P2[3];
		P1[0] = P2[0] = ((PSPAWNINFO)pCharSpawn)->Y;
		P1[1] = P2[1] = ((PSPAWNINFO)pCharSpawn)->X;
		P1[2] = P2[2] = ((PSPAWNINFO)pCharSpawn)->Z;

		if (PCHAR pColon = strchr(szIndex, ':'))
		{
			*pColon = 0;
			if (PCHAR pComma = strchr(&pColon[1], ','))
			{
				*pComma = 0;
				P2[0] = (float)atof(&pColon[1]);
				*pComma = ',';
				if (PCHAR pComma2 = strchr(&pComma[1], ','))
				{
					*pComma2 = 0;
					P2[1] = (float)atof(&pComma[1]);
					*pComma2 = ',';
					P2[2] = (float)atof(&pComma2[1]);
				}
				else
				{
					P2[1] = (float)atof(&pComma[1]);
				}
			}
			else
				P2[0] = (float)atof(&pColon[1]);
		}

		if (PCHAR pComma = strchr(szIndex, ','))
		{
			*pComma = 0;
			P1[0] = (float)atof(szIndex);
			*pComma = ',';
			if (PCHAR pComma2 = strchr(&pComma[1], ','))
			{
				*pComma2 = 0;
				P1[1] = (float)atof(&pComma[1]);
				*pComma2 = ',';
				P1[2] = (float)atof(&pComma2[1]);
			}
			else
			{
				P1[1] = (float)atof(&pComma[1]);
			}
		}
		else
			P1[0] = (float)atof(szIndex);

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

BOOL dataDoorTarget(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (Ret.Ptr = &DoorEnviroTarget)
	{
		Ret.Type = pSpawnType;
		return true;
	}
	return false;
}

BOOL dataItemTarget(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (Ret.Ptr = &EnviroTarget)
	{
		Ret.Type = pSpawnType;
		return true;
	}
	return false;
}

BOOL dataDynamicZone(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pDynamicZoneType;
	return true;
}

BOOL dataFriends(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pFriendsType;
	return true;
}

BOOL dataTask(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	Ret.Int = -1;
	if (ppTaskManager)
	{
		if (szIndex[0])
		{
			if (IsNumber(szIndex))
			{
				int n = atoi(szIndex);
				n--;
				if (n < 0)
					n = 0;
				Ret.Int = n;
			}
			else
			{
				char szOut[MAX_STRING] = { 0 };
				char szTemp[MAX_STRING] = { 0 };
				strcpy_s(szTemp, szIndex);
				_strlwr_s(szTemp);
				//todo: finish this, we can get this stuff done without taskwindow being open.
				for (int i = 0; i < 29; i++)
				{
					if (CTaskEntry* entry = &pTaskManager.QuestEntries[i])
					{
						strcpy_s(szOut, entry->TaskTitle);
						_strlwr_s(szOut);
						if (strstr(szOut, szTemp)) {
							//Ret.Int = i;
							break;
						}
					}
				}
				if (CListWnd* clist = (CListWnd*)pTaskWnd->GetChildItem("TASK_TaskList"))
				{
					CXStr Str;
					strcpy_s(szTemp, szIndex);
					_strlwr_s(szTemp);

					for (int i = 0; i < clist->ItemsArray.GetCount(); i++)
					{
						CXStr Str = clist->GetItemText(i, 2);
						strcpy_s(szOut, Str.c_str());
						_strlwr_s(szOut);
						if (strstr(szOut, szTemp))
						{
							Ret.Int = i;
							break;
						}
					}
				}
			}
		}
	}
	Ret.Type = pTaskType;
	return true;
}

BOOL dataMount(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;
	if (IsNumber(szIndex))
	{
		int n = atoi(szIndex);
		if (n <= 0)
			return false;
		n--;

		if (CXWnd* krwnd = FindMQ2Window(KeyRingWindowParent))
		{
			if (CListWnd* clist = (CListWnd*)krwnd->GetChildItem(MountWindowList))
			{
				int numitems = clist->ItemsArray.GetCount();
				if (numitems >= n)
				{
					CXStr Str = clist->GetItemText(n, 2);
					if (!Str.empty())
					{
						Ret.DWord = MAKELPARAM(n, 0);
						Ret.Type = pKeyRingType;
						return true;
					}
				}
			}
		}
	}
	else if (char* pName = szIndex)
	{
		bool bExact = false;

		if (*pName == '=')
		{
			bExact = true;
			pName++;
		}

		if (DWORD n = GetKeyRingIndex(0, pName, bExact))
		{
			n--;
			Ret.DWord = MAKELPARAM(n, 0);
			Ret.Type = pKeyRingType;
			return true;
		}
	}
	return false;
}

BOOL dataIllusion(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		int n = atoi(szIndex);
		if (n <= 0)
			return false;
		n--;

		if (CXWnd* krwnd = FindMQ2Window(KeyRingWindowParent))
		{
			if (CListWnd* clist = (CListWnd*)krwnd->GetChildItem(IllusionWindowList))
			{
				int numitems = clist->ItemsArray.GetCount();
				if (numitems >= n)
				{
					CXStr Str = clist->GetItemText(n, 2);
					if (!Str.empty())
					{
						Ret.DWord = MAKELPARAM(n, 1);
						Ret.Type = pKeyRingType;
						return true;
					}
				}
			}
		}
	}
	else if (PCHAR pName = szIndex)
	{
		bool bExact = false;

		if (*pName == '=')
		{
			bExact = true;
			pName++;
		}

		if (DWORD n = GetKeyRingIndex(1, pName, bExact))
		{
			n--;
			Ret.DWord = MAKELPARAM(n, 1);
			Ret.Type = pKeyRingType;
			return true;
		}
	}
	return false;
}

BOOL dataFamiliar(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		int n = atoi(szIndex);
		if (n <= 0)
			return false;
		n--;

		if (CXWnd* krwnd = FindMQ2Window(KeyRingWindowParent))
		{
			if (CListWnd* clist = (CListWnd*)krwnd->GetChildItem(FamiliarWindowList))
			{
				int numitems = clist->ItemsArray.GetCount();
				if (numitems >= n)
				{
					CXStr Str = clist->GetItemText(n, 2);
					if (!Str.empty()) {
						Ret.DWord = MAKELPARAM(n, 2);
						Ret.Type = pKeyRingType;
						return true;
					}
				}
			}
		}
	}
	else if (char* pName = szIndex)
	{
		bool bExact = false;

		if (*pName == '=')
		{
			bExact = true;
			pName++;
		}

		if (DWORD n = GetKeyRingIndex(2, pName, bExact))
		{
			n--;
			Ret.DWord = MAKELPARAM(n, 2);
			Ret.Type = pKeyRingType;
			return true;
		}
	}
	return false;
}

BOOL dataAlias(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (szIndex[0])
	{
		std::string sName = szIndex;
		std::transform(sName.begin(), sName.end(), sName.begin(), tolower);
		if (mAliases.find(sName) != mAliases.end()) {
			Ret.DWord = 1;
			Ret.Type = pBoolType;
			return true;
		}
	}
	return false;
}

BOOL dataAdvLoot(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pAdvLootType;
	return true;
}

BOOL dataAlert(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (!szIndex[0]) {
		char szTemp[2048] = { 0 };
		if (CAlerts.ListAlerts(szTemp, 2048)) {
			strcpy_s(DataTypeTemp, szTemp);
			Ret.Ptr = &DataTypeTemp[0];
			Ret.Type = pStringType;
			return true;
		}
		return false;
	}

	if (IsNumber(szIndex)) {
		Ret.DWord = atoi(szIndex);
		Ret.Type = pAlertType;
		return true;
	}
	return false;
}
BOOL dataPointMerchant(PCHAR szIndex, MQ2TYPEVAR& Ret)
{
	if (pMerchantWnd)
	{
		Ret.Ptr = pMerchantWnd;
		Ret.Type = pPointMerchantType;
		return true;
	}
	return false;
}
