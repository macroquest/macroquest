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

#include "pch.h"
#include "MQ2Main.h"

namespace mq {

bool dataSpawn(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		if (IsNumber(szIndex))
		{
			if ((Ret.Ptr = GetSpawnByID(GetIntFromString(szIndex, 0))))
			{
				Ret.Type = pSpawnType;
				return true;
			}
		}
		else
		{
			// set up search spawn
			MQSpawnSearch ssSpawn;
			ClearSearchSpawn(&ssSpawn);
			ParseSearchSpawn(szIndex, &ssSpawn);
			if (Ret.Ptr = SearchThroughSpawns(&ssSpawn, (SPAWNINFO*)pCharSpawn))
			{
				Ret.Type = pSpawnType;
				return true;
			}
		}
	}
	// No spawn

	return false;
}

bool dataSelect(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	// I hate this GetArg shit - Lax
	char szArg[MAX_STRING] = { 0 };
	char szArg1[MAX_STRING] = { 0 };
	int N = 2;
	// FIXME: const
	GetArg(szArg1, (char*)szIndex, 1, false, false, false);
	while (true)
	{
		// FIXME: const
		GetArg(szArg, (char*)szIndex, N, false, false, true);
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

bool dataTarget(const char* szIndex, MQTypeVar& Ret)
{
	if (pTarget)
	{
		Ret.Ptr = pTarget;
		Ret.Type = pTargetType;
		return true;
	}
	return false;
}

bool dataCharacter(const char* szIndex, MQTypeVar& Ret)
{
	if (pCharData)
	{
		Ret.Ptr = pCharData;
		Ret.Type = pCharacterType;
		return true;
	}
	return false;
}

bool dataSpell(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		if (IsNumber(szIndex))
		{
			if ((Ret.Ptr = GetSpellByID(GetIntFromString(szIndex, 0))))
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

bool dataSwitch(const char* szIndex, MQTypeVar& Ret)
{
	if (pDoorTarget)
	{
		Ret.Ptr = pDoorTarget;
		Ret.Type = pSwitchType;
		return true;
	}
	return false;
}

bool dataGroundItem(const char* szIndex, MQTypeVar& Ret)
{
	SPAWNINFO* pSpawn = (SPAWNINFO*)pCharSpawn;

	// if they did ${Ground[name]}
	if (szIndex[0])
	{
		// holds a list of items stored by distance squared.
		std::map<float, GROUNDOBJECT> itemMap;

		if (IsNumber(szIndex))
		{
			int index = std::max(GetIntFromString(szIndex, 0) - 1, 0);

			if (pItemList && pItemList->Top)
			{
				GROUNDITEM* pItem = *(GROUNDITEM**)pItemList;

				while (pItem)
				{
					float X = pSpawn->X - pItem->X;
					float Y = pSpawn->Y - pItem->Y;
					float Z = pSpawn->Z - (pItem->pSwitch ? pItem->pSwitch->Z : pItem->Z);

					float distSq = X * X + Y * Y + Z * Z;

					itemMap[distSq].Type = GO_GroundType;
					itemMap[distSq].pGroundItem = pItem;
					pItem = pItem->pNext;
				}
			}

			// lets see if there are any objects that match as well:
			RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
			EQPlacedItemManager& pPIM = EQPlacedItemManager::Instance();

			for (EQPlacedItem* pObj = pPIM.Top; pObj != nullptr; pObj = pObj->pNext)
			{
				const RealEstateItemClient* pRealEstateItem = manager.GetItemByRealEstateAndItemIds(
					pObj->RealEstateID, pObj->RealEstateItemID);
				if (!pRealEstateItem)
					continue;

				CONTENTS* pCont = pRealEstateItem->Object.pItemBase.pObject;
				if (!pCont)
					continue;

				ITEMINFO* pItem = GetItemFromContents(pCont);
				if (!pItem)
					continue;

				float X = pSpawn->X - pObj->X;
				float Y = pSpawn->Y - pObj->Y;
				float Z = pSpawn->Z - pObj->Z;

				float distSq = X * X + Y * Y + Z * Z;
				itemMap[distSq].Type = GO_ObjectType;
				itemMap[distSq].ObjPtr = pObj;
			}

			if (index < (int)itemMap.size())
			{
				auto it = itemMap.begin();
				std::advance(it, index);

				if (it != itemMap.end())
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
			char szName[MAX_STRING] = { 0 };
			if (pItemList && pItemList->Top)
			{
				GROUNDITEM* pItem = *(GROUNDITEM**)pItemList;
				while (pItem)
				{
					GetFriendlyNameForGroundItem(pItem, szName, sizeof(szName));

					if (ci_find_substr(szName, szIndex) != -1)
					{
						float X = pSpawn->X - pItem->X;
						float Y = pSpawn->Y - pItem->Y;
						float Z = pSpawn->Z - (pItem->pSwitch ? pItem->pSwitch->Z : pItem->Z);

						float distSq = X * X + Y * Y + Z * Z;
						itemMap[distSq].Type = GO_GroundType;
						itemMap[distSq].pGroundItem = pItem;
					}

					pItem = pItem->pNext;
				}
			}

			// lets see if there are any objects that match as well:
			RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
			EQPlacedItemManager& pPIM = EQPlacedItemManager::Instance();

			for (EQPlacedItem* pObj = pPIM.Top; pObj != nullptr; pObj = pObj->pNext)
			{
				const RealEstateItemClient* pRealEstateItem = manager.GetItemByRealEstateAndItemIds(
					pObj->RealEstateID, pObj->RealEstateItemID);
				if (!pRealEstateItem)
					continue;

				CONTENTS* pCont = pRealEstateItem->Object.pItemBase.pObject;
				if (!pCont)
					continue;

				ITEMINFO* pItem = GetItemFromContents(pCont);
				if (!pItem)
					continue;

				if (ci_find_substr(pItem->Name, szIndex) != -1)
				{
					float X = pSpawn->X - pObj->X;
					float Y = pSpawn->Y - pObj->Y;
					float Z = pSpawn->Z - pObj->Z;

					float distSq = X * X + Y * Y + Z * Z;
					itemMap[distSq].Type = GO_ObjectType;
					itemMap[distSq].ObjPtr = pObj;
				}
			}
		}

		// we got some objects return the closest
		if (!itemMap.empty())
		{
			// FIXME: Don't copy with memcpy
			memcpy(&GroundObject, &itemMap.begin()->second, sizeof(GROUNDOBJECT));
			Ret.Ptr = &GroundObject;
			Ret.Type = pGroundType;
			return true;
		}
	}
	else if (GroundObject.Type != GO_None) // they already did /itemtarget so return that.
	{
		Ret.Ptr = &GroundObject;
		Ret.Type = pGroundType;
		return true;
	}

	// well they didn't specify a name and they have not done /itemtarget
	// so we just return first closest entry found
	float groundDist = 100000.0f;
	float objectDist = 100000.0f;

	if (PGROUNDITEM pItem = *(PGROUNDITEM*)pItemList)
	{
		float X = pSpawn->X - pItem->X;
		float Y = pSpawn->Y - pItem->Y;
		float Z = pSpawn->Z - (pItem->pSwitch ? pItem->pSwitch->Z : pItem->Z);

		groundDist = sqrtf(X * X + Y * Y + Z * Z);
		GroundObject.pGroundItem = pItem;
		GroundObject.Type = GO_GroundType;
	}

	EQPlacedItemManager& pPIM = EQPlacedItemManager::Instance();

	if (EQPlacedItem* top = pPIM.Top)
	{
		float X = pSpawn->X - top->X;
		float Y = pSpawn->Y - top->Y;
		float Z = pSpawn->Z - top->Z;

		objectDist = sqrtf(X * X + Y * Y + Z * Z);
		GroundObject.ObjPtr = (void*)top;
		GroundObject.Type = GO_ObjectType;
	}

	if (GroundObject.Type != GO_None)
	{
		GroundObject.Type = objectDist > groundDist ? GO_GroundType : GO_ObjectType;

		Ret.Ptr = &GroundObject;
		Ret.Type = pGroundType;
		return true;
	}

	return false;
}

bool dataGroundItemCount(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pIntType;
	if (!pItemList)
		return true;

	PGROUNDITEM pItem = *(PGROUNDITEM*)pItemList;
	if (!pItem)
		return true;

	int Count = 0;

	if (szIndex[0])
	{
		char szName[MAX_STRING] = { 0 };
		while (pItem)
		{
			GetFriendlyNameForGroundItem(pItem, szName, sizeof(szName));

			if (ci_find_substr(szName, szIndex) != -1)
			{
				Count++;
			}

			pItem = pItem->pNext;
		}

		Ret.DWord = Count;
	}
	else
	{
		while (pItem)
		{
			Count++;
			pItem = pItem->pNext;
		}

		Ret.DWord = Count;
	}

	return true;
}

bool dataMerchant(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = pActiveMerchant;
	Ret.Type = pMerchantType;
	return true;
}

bool dataMercenary(const char* szIndex, MQTypeVar& Ret)
{
	if (pMercInfo && pMercInfo->MercSpawnId)
	{
		Ret.Ptr = GetSpawnByID(pMercInfo->MercSpawnId);
		Ret.Type = pMercenaryType;
		return true;
	}

	if (pMercInfo)
	{
		// FIXME: Do not ZeroMemory a SPAWNINFO
		ZeroMemory(&MercenarySpawn, sizeof(MercenarySpawn));

		if (pMercInfo->HaveMerc == 1)
		{
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
		else
		{
			if (pMercInfo->MercenaryCount >= 1)
			{
				strcpy_s(MercenarySpawn.Name, "SUSPENDED");
				Ret.Ptr = &MercenarySpawn;
				Ret.Type = pMercenaryType;
				return true;
			}
			else
			{
				strcpy_s(MercenarySpawn.Name, "NOT FOUND");
				Ret.Ptr = &MercenarySpawn;
				Ret.Type = pMercenaryType;
				return true;
			}
		}
	}

	// we need to return true always to be able to get other members out
	return false;
}

bool dataPet(const char* szIndex, MQTypeVar& Ret)
{
	SPAWNINFO* pSpawn = GetCharInfo()->pSpawn;

	if (pSpawn && pSpawn->PetID != 0xFFFFFFFF)
	{
		Ret.Ptr = GetSpawnByID(pSpawn->PetID);
		Ret.Type = pPetType;
		return true;
	}
	else if (pSpawn)
	{
		// FIXME: Do not ZeroMemory a SPAWNINFO
		ZeroMemory(&PetSpawn, sizeof(PetSpawn));

		strcpy_s(PetSpawn.Name, "NO PET");

		Ret.Ptr = &PetSpawn;
		Ret.Type = pPetType;
		return true;
	}

	// we need to return true always to be able to get other members out
	return false;
}

bool dataCorpse(const char* szIndex, MQTypeVar& Ret)
{
	if (pLootWnd)
	{
		Ret.Ptr = pLootWnd;
		Ret.Type = pCorpseType;
		return true;
	}
	return false;
}

bool dataMenu(const char* szIndex, MQTypeVar& Ret)
{
	if (CContextMenuManager* pMrg = pContextMenuManager)
	{
		if (Ret.Ptr = pMrg)
		{
			Ret.Type = pMenuType;
			return true;
		}
	}

	return false;
}

bool dataWindow(const char* szIndex, MQTypeVar& Ret)
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

bool dataMacro(const char* szIndex, MQTypeVar& Ret)
{
	if (gRunning)
	{
		Ret.Ptr = 0;
		Ret.Type = pMacroType;
		return true;
	}

	return false;
}

bool dataMacroQuest(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = 0;
	Ret.Type = pMacroQuestType;
	return true;
}

bool dataEverQuest(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = 0;
	Ret.Type = pEverQuestType;
	return true;
}

bool dataMath(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = 0;
	Ret.Type = pMathType;
	return true;
}

bool dataZone(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
	{
		Ret.DWord = instEQZoneInfo;
		Ret.Type = pCurrentZoneType;
		return true;
	}
	if (IsNumber(szIndex))
	{
		PZONELIST pZone = nullptr;

		if (int nIndex = (GetIntFromString(szIndex, 0) & 0x7FFF))
		{
			if (CHARINFO* pChar = GetCharInfo()) {
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

		return false;
	}

	int nIndex = GetZoneID(szIndex);
	if (nIndex != -1)
	{
		if (CHARINFO* pChar = GetCharInfo())
		{
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

bool dataInt(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	Ret.DWord = GetIntFromString(szIndex, 0);
	Ret.Type = pIntType;
	return true;
}

bool dataFloat(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	Ret.Float = GetFloatFromString(szIndex, 0);
	Ret.Type = pFloatType;
	return true;
}

bool dataHeading(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	char szInput[256];
	strcpy_s(szInput, szIndex);

	if (char* pComma = strchr(szInput, ','))
	{
		*pComma = 0;
		float Y = GetFloatFromString(szInput, 0);
		*pComma = ',';
		float X = GetFloatFromString(&pComma[1], 0);

		Ret.Float = static_cast<float>(atan2f(reinterpret_cast<SPAWNINFO*>(pCharSpawn)->Y - Y,
		                                      X - reinterpret_cast<SPAWNINFO*>(pCharSpawn)->X) * 180.0f / PI + 90.0f);
		if (Ret.Float < 0.0f)
			Ret.Float += 360.0f;
		else if (Ret.Float >= 360.0f)
			Ret.Float -= 360.0f;
		Ret.Type = pHeadingType;
		return true;
	}

	Ret.Float = GetFloatFromString(szIndex, 0);
	Ret.Type = pHeadingType;
	return true;
}

bool dataBool(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	Ret.Type = pBoolType;
	Ret.DWord = 1;
	if (IsNumber(szIndex))
	{
		Ret.DWord = GetFloatFromString(szIndex, 0.0) == 0.0 ? 0 : 1;
	}
	else
	{
		if (_stricmp(szIndex, "NULL") == 0 || _stricmp(szIndex, "FALSE") == 0)
		{
			Ret.DWord = 0;
		}
	}

	return true;
}

bool dataGroup(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 1;
	Ret.Type = pGroupType;
	return true;
}

bool dataIf(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		int nDelimiter = 0;
		const char* pDelimiter = strchr(szIndex, gIfAltDelimiter);

		while (pDelimiter != nullptr)
		{
			nDelimiter++;
			pDelimiter = strchr(pDelimiter + 1, gIfAltDelimiter);
		}

		char szTemp[MAX_STRING];
		strcpy_s(szTemp, szIndex);

		// condition| whentrue| whenfalse
		if (nDelimiter == 2)
		{
			if (char* pTrue = strchr(szTemp, gIfAltDelimiter))
			{
				*pTrue = 0;
				pTrue++;
				if (char* pFalse = strchr(pTrue, gIfAltDelimiter))
				{
					*pFalse = 0;
					pFalse++;
					double CalcResult;
					if (!Calculate(szTemp, CalcResult))
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
		if (char* pTrue = strchr(szTemp, gIfDelimiter))
		{
			*pTrue = 0;
			pTrue++;
			if (char* pFalse = strchr(pTrue, gIfDelimiter))
			{
				*pFalse = 0;
				pFalse++;
				double CalcResult;
				if (!Calculate(szTemp, CalcResult))
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

bool dataCursor(const char* szIndex, MQTypeVar& Ret)
{
	if (PcProfile* pChar2 = GetPcProfile())
	{
		if (pChar2->pInventoryArray)
		{
			if (Ret.Ptr = pChar2->pInventoryArray->Inventory.Cursor)
			{
				Ret.Type = pItemType;
				return true;
			}
		}
	}

	return false;
}

bool dataLastSpawn(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		if (IsNumber(szIndex))
		{
			bool bPosIndex = true;
			int index = GetIntFromString(szIndex, 0);
			if (index < 0)
			{
				bPosIndex = false;
				index *= -1;
			}
			else if (index == 0)
			{
				index = 1;
			}
			index--;

			if (SPAWNINFO* pSpawn = bPosIndex ? static_cast<SPAWNINFO*>pSpawnList : reinterpret_cast<SPAWNINFO*>(pLocalPlayer))
			{
				while (index)
				{
					pSpawn = bPosIndex ? pSpawn->pNext : pSpawn->pPrev;
					if (!pSpawn)
						return false;
					index--;
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

bool dataNearestSpawn(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		MQSpawnSearch ssSpawn;
		ClearSearchSpawn(&ssSpawn);
		ssSpawn.FRadius = 999999.0f;

		int nth = 0;

		if (strchr(szIndex, ',') != nullptr)
		{
			char szTemp[MAX_STRING];
			strcpy_s(szTemp, szIndex);

			char* pSearch = strchr(szTemp, ',');
			*pSearch = 0;
			++pSearch;

			ParseSearchSpawn(pSearch, &ssSpawn);
			nth = GetIntFromString(szIndex, nth);
		}
		else
		{
			if (IsNumberToComma(szIndex))
			{
				nth = GetIntFromString(szIndex, nth);
			}
			else
			{
				nth = 1;
				ParseSearchSpawn(szIndex, &ssSpawn);
			}
		}

		for (size_t index = 0; index < gSpawnCount; index++)
		{
			if (EQP_DistArray[index].Value.Float > ssSpawn.FRadius && !ssSpawn.bKnownLocation)
				return false;

			if (SpawnMatchesSearch(&ssSpawn, (SPAWNINFO*)pCharSpawn, (SPAWNINFO*)EQP_DistArray[index].VarPtr.Ptr))
			{
				if (--nth == 0)
				{
					Ret.Ptr = EQP_DistArray[index].VarPtr.Ptr;
					Ret.Type = pSpawnType;
					return true;
				}
			}
		}
	}

	// No spawn
	return false;
}

bool dataSpawnCount(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		MQSpawnSearch ssSpawn;
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

bool dataTime(const char* szIndex, MQTypeVar& Ret)
{
	time_t CurTime = { 0 };
	time(&CurTime);
	struct tm* pTime = (struct tm*) & DataTypeTemp[0];
	ZeroMemory(pTime, sizeof(struct tm));
	localtime_s(pTime, &CurTime);
	Ret.Ptr = pTime;
	Ret.Type = pTimeType;
	return true;
}

bool dataGameTime(const char* szIndex, MQTypeVar& Ret)
{
	struct tm* pTime = (struct tm*) & DataTypeTemp[0];
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

bool dataRange(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 1;
	Ret.Type = pRangeType;
	return true;
}

bool dataIni(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex || szIndex[0] == 0)
		return false;

	std::string sTemp = szIndex;

	int count = 0;
	std::map<int, DWORD> argMap;

	// lets see how many commas are in the string
	for (auto i = sTemp.begin(); i != sTemp.end(); i++)
	{
		if (i[0] == ',' && i + 1 != sTemp.end() && i[1] != ' ')
		{
			argMap[count] = std::distance(sTemp.begin(), i);
			count++;
		}
	}

	std::string IniFile = sTemp;
	bool bNoParse = false;

	std::string Section;
	std::string Key;
	std::string Default;

	if (!argMap.empty())
	{
		IniFile.erase(argMap[0]);
		Section = sTemp.substr(argMap[0] + 1);
		if (argMap.size() >= 2)
		{
			Section.erase(argMap[1] - argMap[0] - 1);
			Key = sTemp.substr(argMap[1] + 1);
			if (argMap.size() >= 3)
			{
				Key.erase(argMap[2] - argMap[1] - 1);
				Default = sTemp.substr(argMap[2] + 1);
				if (argMap.size() >= 4)
				{
					Default.erase(argMap[3] - argMap[2] - 1);
					std::string Parse = sTemp.substr(argMap[3] + 1);

					if (Parse == "noparse")
						bNoParse = true;
				}
			}
		}
	}

	if (IniFile.empty())
		return false;

	if (IniFile.find('.') == std::string::npos)
	{
		IniFile.append(".ini");
	}

	std::filesystem::path pathIniFile = IniFile;

	if (pathIniFile.is_relative())
	{
		pathIniFile = mq::internal_paths::Config / pathIniFile;
	}

	if (std::filesystem::exists(pathIniFile))
	{
		const int nSize = GetPrivateProfileString(Section, Key, Default, DataTypeTemp, MAX_STRING, pathIniFile.string());

		if (nSize)
		{
			if (nSize > 2)
			{
				for (int index = 0; index < nSize - 2; index++)
				{
					if (DataTypeTemp[index] == 0)
						DataTypeTemp[index] = '|';
				}
			}

			if ((Section.empty() || Key.empty()) && (nSize < MAX_STRING - 3))
				strcat_s(DataTypeTemp, "||");

			if (bNoParse)
			{
				if (gParserVersion == 2)
				{
					// If we are not supposed to parse and there is a ${
					if (strstr(DataTypeTemp, "${"))
					{
						// Modify Macro String with parameter to wrap Parse Zero
						strcpy_s(DataTypeTemp, ModifyMacroString(DataTypeTemp, true, ModifyMacroMode::Wrap).data());
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
	}

	if (!Default.empty())
	{
		if (bNoParse)
		{
			if (gParserVersion == 2)
			{
				// If we're set not to parse and there's a ${
				if (Default.find("${") != std::string::npos)
				{

					// Modify Macro String with parameter to wrap Parse Zero
					Default = ModifyMacroString(Default, true, ModifyMacroMode::Wrap);
				}
			}

			// I think the below is actually wrong, since it's checking whatever was stored in
			// DataTypeTemp BEFORE instead of checking what's in Default, but I didn't track it down
			// to see if DataTypeTemp was getting set to default somewhere else and this is how
			// it was originally in parser v1. So I left it.  -- Knightly
			else if (strchr(DataTypeTemp, '$'))
			{
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

bool dataDefined(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;
	Ret.DWord = (FindMQ2DataVariable(szIndex) != 0);
	Ret.Type = pBoolType;
	return true;
}

bool dataSubDefined(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;
	Ret.DWord = gMacroBlock && (gMacroSubLookupMap.find(szIndex) != gMacroSubLookupMap.end());
	Ret.Type = pBoolType;
	return true;
}

bool dataSelectedItem(const char* szIndex, MQTypeVar& Ret)
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
	}

	return false;
}

bool dataFindItemBank(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	CONTENTS* pItem = nullptr;

	if (IsNumber(szIndex))
	{
		if ((pItem = FindBankItemByID(GetIntFromString(szIndex, 0))))
		{
			Ret.Ptr = pItem;
			Ret.Type = pItemType;
			return true;
		}

		return false;
	}

	const char* pName = szIndex;
	bool bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}

	if (pItem = FindBankItemByName(pName, bExact))
	{
		Ret.Ptr = pItem;
		Ret.Type = pItemType;
		return true;
	}
	return false;
}

bool dataFindItem(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		if (CONTENTS* pItem = FindItemByID(GetIntFromString(szIndex, 0)))
		{
			Ret.Ptr = pItem;
			Ret.Type = pItemType;
			return true;
		}
		return false;
	}

	const char* pName = szIndex;
	bool bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}

	if (CONTENTS* pItem = FindItemByName(pName, bExact))
	{
		Ret.Ptr = pItem;
		Ret.Type = pItemType;
		return true;
	}

	return false;
}

bool dataFindItemCount(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		Ret.DWord = FindItemCountByID(GetIntFromString(szIndex, 0));
		Ret.Type = pIntType;
		return true;
	}

	const char* pName = szIndex;
	bool bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}

	Ret.DWord = FindItemCountByName(pName, bExact);
	Ret.Type = pIntType;
	return true;
}

bool dataFindItemBankCount(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		Ret.DWord = FindBankItemCountByID(GetIntFromString(szIndex, 0));
		Ret.Type = pIntType;
		return true;
	}

	const char* pName = szIndex;
	bool bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}

	Ret.DWord = FindBankItemCountByName(pName, bExact);
	Ret.Type = pIntType;
	return true;
}

bool dataInvSlot(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		Ret.DWord = GetIntFromString(szIndex, 0);
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

bool dataPlugin(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;
	if (IsNumber(szIndex))
	{
		int index = GetIntFromString(szIndex, 0) - 1;
		if (index < 0)
			index = 0;

		MQPlugin* pPlugin = pPlugins;
		while (index)
		{
			pPlugin = pPlugin->pNext;
			if (!pPlugin)
				return false;
			index--;
		}

		Ret.Ptr = pPlugin;
		Ret.Type = pPluginType;
		return true;
	}
	else
	{
		// name
		MQPlugin* pPlugin = pPlugins;
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

bool dataSkill(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		int nSkill = GetIntFromString(szIndex, 0) - 1;
		if (nSkill < 0)
			nSkill = 0;

		if (nSkill > NUM_SKILLS)
			return false;

		Ret.Ptr = &pSkillMgr->pSkill[nSkill];
		Ret.Type = pSkillType;
		return true;
	}

	for (int nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
	{
		if (SKILL* pSkill = pSkillMgr->pSkill[nSkill])
		{
			if (const char* pName = pStringTable->getString(pSkill->nName))
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

	return false;
}

bool dataAltAbility(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
		{
			if (ALTABILITY* pAbility = GetAAByIdWrapper(nAbility))
			{
				if (pAbility->ID == GetIntFromString(szIndex, 0))
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
		// we need to get the level appropriate one if they just supplied a name
		int level = -1;
		if (SPAWNINFO* pMe = (SPAWNINFO*)pLocalPlayer)
		{
			level = pMe->Level;
		}

		for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
		{
			if (PALTABILITY pAbility = GetAAByIdWrapper(nAbility, level))
			{
				if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
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

bool dataRaid(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pRaidType;
	return true;
}

bool dataLineOfSight(const char* szIndex, MQTypeVar& Ret)
{
	if (!GetCharInfo() && !GetCharInfo()->pSpawn)
		return false;

	if (szIndex[0])
	{
		float P1[3];
		float P2[3];
		P1[0] = P2[0] = ((SPAWNINFO*)pCharSpawn)->Y;
		P1[1] = P2[1] = ((SPAWNINFO*)pCharSpawn)->X;
		P1[2] = P2[2] = ((SPAWNINFO*)pCharSpawn)->Z;

		char szTemp[MAX_STRING];
		strcpy_s(szTemp, szIndex);

		// TODO:  This code appears in MQ2MathType Distance, possibly clean and combine
		if (char* pColon = strchr(szTemp, ':'))
		{
			*pColon = 0;
			if (char* pComma = strchr(&pColon[1], ','))
			{
				*pComma = 0;
				P2[0] = GetFloatFromString(&pColon[1], P2[0]);
				*pComma = ',';
				if (char* pComma2 = strchr(&pComma[1], ','))
				{
					*pComma2 = 0;
					P2[1] = GetFloatFromString(&pComma[1], P2[1]);
					*pComma2 = ',';
					P2[2] = GetFloatFromString(&pComma2[1], P2[2]);
				}
				else
				{
					P2[1] = GetFloatFromString(&pComma[1], P2[1]);
				}
			}
			else
				P2[0] = GetFloatFromString(&pColon[1], P2[0]);
		}

		if (char* pComma = strchr(szTemp, ','))
		{
			*pComma = 0;
			P1[0] = GetFloatFromString(szTemp, P1[0]);
			*pComma = ',';
			if (char* pComma2 = strchr(&pComma[1], ','))
			{
				*pComma2 = 0;
				P1[1] = GetFloatFromString(&pComma[1], P1[1]);
				*pComma2 = ',';
				P1[2] = GetFloatFromString(&pComma2[1], P1[2]);
			}
			else
			{
				P1[1] = GetFloatFromString(&pComma[1], P1[1]);
			}
		}
		else
			P1[0] = GetFloatFromString(szTemp, P1[0]);

		// FIXME: Can't copy data like this. Refactor to use line of sight calculation
		// without using a SPAWNINFO.
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

bool dataDoorTarget(const char* szIndex, MQTypeVar& Ret)
{
	if (Ret.Ptr = &DoorEnviroTarget)
	{
		Ret.Type = pSpawnType;
		return true;
	}
	return false;
}

bool dataItemTarget(const char* szIndex, MQTypeVar& Ret)
{
	if (Ret.Ptr = &EnviroTarget)
	{
		Ret.Type = pSpawnType;
		return true;
	}
	return false;
}

bool dataDynamicZone(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pDynamicZoneType;
	return true;
}

bool dataFriends(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pFriendsType;
	return true;
}

bool dataTask(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Type = pTaskType;
	Ret.DWord = (int)MAKELPARAM(cTaskSystemTypeSoloQuest, 0xFFFFFFFF);

	if (CTaskManager* tm = ppTaskManager)
	{
		if (szIndex[0])
		{
			CTaskEntry* sharedEntry = (CTaskEntry*)&tm->SharedTaskEntries[0];
			if (IsNumber(szIndex))
			{
				int n = std::clamp(GetIntFromString(szIndex, 0) - 1, 0, MAX_QUEST_ENTRIES - 1);

				// If it is 0, and we have a shared quest, then we need to return that
				if (n == 0 && sharedEntry && sharedEntry->TaskID)
				{
					Ret.DWord = (int)MAKELPARAM(cTaskSystemTypeSharedQuest, 0);
					return true;
				}
				else
				{
					if (CTaskEntry* entry = &tm->QuestEntries[n])
					{
						if (entry->TaskID)
						{
							Ret.DWord = (int)MAKELPARAM(cTaskSystemTypeSoloQuest, n);
							return true;
						}
					}
				}
			}
			else
			{
				if (sharedEntry && sharedEntry->TaskID)
				{
					if (MaybeExactCompare(sharedEntry->TaskTitle, szIndex))
					{
						Ret.DWord = (int)MAKELPARAM(cTaskSystemTypeSharedQuest, 0);
						return true;
					}
				}

				for (int i = 0; i < MAX_QUEST_ENTRIES; i++)
				{
					if (CTaskEntry* entry = &tm->QuestEntries[i])
					{
						if (MaybeExactCompare(entry->TaskTitle, szIndex))
						{
							Ret.DWord = (int)MAKELPARAM(cTaskSystemTypeSoloQuest, 0);
							return true;
						}
					}
				}
			}
		}
	}

	return false;
}

bool dataMount(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;
	if (IsNumber(szIndex))
	{
		int n = GetIntFromString(szIndex, 0) - 1;
		if (n < 0)
			return false;

		if (CXWnd* krwnd = FindMQ2Window(KeyRingWindowParent))
		{
			if (CListWnd* clist = (CListWnd*)krwnd->GetChildItem(MountWindowList))
			{
				int numitems = clist->ItemsArray.GetCount();
				if (n <= numitems)
				{
					CXStr Str = clist->GetItemText(n, 2);
					if (!Str.empty())
					{
						Ret.DWord = MAKELPARAM(n, eMount);
						Ret.Type = pKeyRingType;
						return true;
					}
				}
			}
		}
	}
	else if (const char* pName = szIndex)
	{
		bool bExact = false;

		if (*pName == '=')
		{
			bExact = true;
			pName++;
		}

		if (int n = GetKeyRingIndex(eMount, pName, bExact))
		{
			Ret.DWord = MAKELPARAM(n - 1, eMount);
			Ret.Type = pKeyRingType;
			return true;
		}
	}

	return false;
}

bool dataIllusion(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		int n = GetIntFromString(szIndex, 0) - 1;
		if (n < 0)
			return false;

		if (CXWnd* krwnd = FindMQ2Window(KeyRingWindowParent))
		{
			if (CListWnd* clist = (CListWnd*)krwnd->GetChildItem(IllusionWindowList))
			{
				int numitems = clist->ItemsArray.GetCount();
				if (n <= numitems)
				{
					CXStr Str = clist->GetItemText(n, 2);
					if (!Str.empty())
					{
						Ret.DWord = MAKELPARAM(n, eIllusion);
						Ret.Type = pKeyRingType;
						return true;
					}
				}
			}
		}
	}
	else if (const char* pName = szIndex)
	{
		bool bExact = false;

		if (*pName == '=')
		{
			bExact = true;
			pName++;
		}

		if (int n = GetKeyRingIndex(eIllusion, pName, bExact))
		{
			Ret.DWord = MAKELPARAM(n - 1, eIllusion);
			Ret.Type = pKeyRingType;
			return true;
		}
	}
	return false;
}

bool dataFamiliar(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		int n = GetIntFromString(szIndex, 0) - 1;
		if (n < 0)
			return false;

		if (CXWnd* krwnd = FindMQ2Window(KeyRingWindowParent))
		{
			if (CListWnd* clist = (CListWnd*)krwnd->GetChildItem(FamiliarWindowList))
			{
				int numitems = clist->ItemsArray.GetCount();
				if (n <= numitems)
				{
					CXStr Str = clist->GetItemText(n, 2);
					if (!Str.empty())
					{
						Ret.DWord = MAKELPARAM(n, eFamiliar);
						Ret.Type = pKeyRingType;
						return true;
					}
				}
			}
		}
	}
	else if (const char* pName = szIndex)
	{
		bool bExact = false;

		if (*pName == '=')
		{
			bExact = true;
			pName++;
		}

		if (int n = GetKeyRingIndex(eFamiliar, pName, bExact))
		{
			Ret.DWord = MAKELPARAM(n - 1, eFamiliar);
			Ret.Type = pKeyRingType;
			return true;
		}
	}
	return false;
}

bool dataAlias(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		if (IsAlias(szIndex))
		{
			Ret.DWord = 1;
			Ret.Type = pBoolType;
			return true;
		}
	}
	return false;
}

bool dataAdvLoot(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pAdvLootType;
	return true;
}

bool dataAlert(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
	{
		char szTemp[2048] = { 0 };

		if (CAlerts.ListAlerts(szTemp, 2048))
		{
			strcpy_s(DataTypeTemp, szTemp);
			Ret.Ptr = &DataTypeTemp[0];
			Ret.Type = pStringType;
			return true;
		}

		return false;
	}

	if (IsNumber(szIndex))
	{
		Ret.DWord = GetIntFromString(szIndex, 0);
		Ret.Type = pAlertType;
		return true;
	}

	return false;
}

bool dataPointMerchant(const char* szIndex, MQTypeVar& Ret)
{
	if (pMerchantWnd)
	{
		Ret.Ptr = pMerchantWnd;
		Ret.Type = pPointMerchantType;
		return true;
	}

	return false;
}

} // namespace mq
