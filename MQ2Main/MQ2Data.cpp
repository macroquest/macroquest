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

BOOL dataSpawn(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0])
	{
		if (szIndex[0]>='0' && szIndex[0]<='9')
		{
			if (Ret.Ptr=GetSpawnByID(atoi(szIndex)))
			{
				Ret.Type=pSpawnType;
				return true;
			}
		}
		else
		{
			// set up search spawn
			SEARCHSPAWN ssSpawn;
			ClearSearchSpawn(&ssSpawn);
			ParseSearchSpawn(szIndex,&ssSpawn);
			if (Ret.Ptr=SearchThroughSpawns(&ssSpawn,(PSPAWNINFO)pCharSpawn))
			{
				Ret.Type=pSpawnType;
				return true;
			}
		}
	}
	// No spawn

	return false;
}

BOOL dataTarget(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (pTarget)
	{
		Ret.Ptr=pTarget;
		Ret.Type=pSpawnType;
		return true;
	}
	return false;
}

BOOL dataCharacter(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (pCharData)
	{
		Ret.Ptr=pCharData;
		Ret.Type=pCharacterType;
		return true;
	}
	return false;
}

BOOL dataSpell(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0])
	{
		if (szIndex[0]>='0' && szIndex[0]<='9')
		{
			if (Ret.Ptr=GetSpellByID(atoi(szIndex)))
			{
				Ret.Type=pSpellType;
				return true;
			}
		}
		else
		{
			if (Ret.Ptr=GetSpellByName(szIndex))
			{
				Ret.Type=pSpellType;
				return true;
			}
		}
	}
   return false;
}

BOOL dataSwitch(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (pDoorTarget)
	{
		Ret.Ptr=pDoorTarget;
		Ret.Type=pSwitchType;
		return true;
	}
	return false;
}

BOOL dataGroundItem(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (pGroundTarget)
	{
		Ret.Ptr=pGroundTarget;
		Ret.Type=pGroundType;
		return true;
	}
	return false;
}

BOOL dataMerchant(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (pActiveMerchant)
	{
		Ret.Ptr=pActiveMerchant;
		Ret.Type=pMerchantType;
		return true;
	}
	return false;
}

BOOL dataCorpse(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (pLootWnd)
	{
		Ret.Ptr=pLootWnd;
		Ret.Type=pCorpseType;
		return true;
	}
	return false;
}

BOOL dataWindow(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0])
	{
		if (Ret.Ptr=FindMQ2Window(szIndex))
		{
			Ret.Type=pWindowType;
			return true;
		}
	}
	return false;
}

BOOL dataMacro(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (gRunning)
	{
		Ret.Ptr=0;
		Ret.Type=pMacroType;
		return true;
	}
	return false;
}

BOOL dataMacroQuest(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	Ret.Ptr=0;
	Ret.Type=pMacroQuestType;
	return true;
}

BOOL dataMath(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	Ret.Ptr=0;
	Ret.Type=pMathType;
	return true;
}

BOOL dataZone(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
   int nIndex=0;
   PZONELIST pZone = NULL;

   if (szIndex[0]==0) 
   {
      Ret.DWord = instEQZoneInfo;
      Ret.Type=pCurrentZoneType;
      return true;
   } 
   else if (szIndex[0]>='0' && szIndex[0]<='9')
   {
	   if (nIndex = atoi(szIndex))
	   {
		if (GetCharInfo()->zoneId==nIndex)
		{
			Ret.DWord = instEQZoneInfo;
			Ret.Type=pCurrentZoneType;
		}
		else
		{
				Ret.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[nIndex];
				Ret.Type=pZoneType;
		}
		return true;
	   }
   } 
   else if (-1 != (nIndex=GetZoneID(szIndex))) 
   {
	   if (GetCharInfo()->zoneId==nIndex)
	   {
		   Ret.DWord = instEQZoneInfo;
		   Ret.Type=pCurrentZoneType;
	   }
	   else
	   {
			Ret.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[nIndex];
			Ret.Type=pZoneType;
	   }
      return true;
   }   
   return false; 
}

BOOL dataInt(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	Ret.DWord=atol(szIndex);
	Ret.Type=pIntType;
	return true;
}

BOOL dataString(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	strcpy(DataTypeTemp,szIndex);
	Ret.Ptr=&DataTypeTemp[0];
	Ret.Type=pStringType;
	return true;
}

BOOL dataFloat(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	Ret.Float=(FLOAT)atof(szIndex);
	Ret.Type=pFloatType;
	return true;
}

BOOL dataHeading(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	if (PCHAR pComma=strchr(szIndex,','))
	{
		*pComma=0;
		FLOAT Y=(FLOAT)atof(szIndex);
		*pComma=',';
		FLOAT X=(FLOAT)atof(&pComma[1]);
        Ret.Float=(FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - Y, X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
        if (Ret.Float<0.0f) 
			Ret.Float += 360.0f;
		else if (Ret.Float>=360.0f) 
			Ret.Float -= 360.0f;
		Ret.Type=pHeadingType;
		return true;
	}

	Ret.Float=(FLOAT)atof(szIndex);
	Ret.Type=pHeadingType;
	return true;
}

BOOL dataBool(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	Ret.DWord=(stricmp(szIndex,"NULL") && 
				stricmp(szIndex,"FALSE") &&
				strcmp(szIndex,"0"));
	Ret.Type=pBoolType;
	return true;
}

BOOL dataGroupLeader(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!GroupLeader[0] || !stricmp(GroupLeader,GetCharInfo()->pSpawn->Name))
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
				if (!stricmp(pSpawn->Name,GroupLeader))
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

BOOL dataGroupLeaderName(PCHAR szIndex, MQ2TYPEVAR &Ret)
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

BOOL dataGroup(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0])
	{
		DWORD N=atoi(szIndex);
		if (N==0)
		{
			return dataCharacter("",Ret);
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
}

BOOL dataIf(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0])
	{
		// condition, whentrue, whenfalse
		if (PCHAR pTrue=strchr(szIndex,','))
		{
			*pTrue=0;
			pTrue++;
			if (PCHAR pFalse=strchr(pTrue,','))
			{
				*pFalse=0;
				pFalse++;
				DOUBLE CalcResult;
				if (!Calculate(szIndex,CalcResult))
					return false;

				if (CalcResult!=0.0f)
				{
					strcpy(DataTypeTemp,pTrue);
					Ret.Ptr=&DataTypeTemp[0];
					Ret.Type=pStringType;
					return true;
				}
				else
				{
					strcpy(DataTypeTemp,pFalse);
					Ret.Ptr=&DataTypeTemp[0];
					Ret.Type=pStringType;
					return true;				
				}
			}
		}
	}
	return false;
}

BOOL dataCursor(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (Ret.Ptr=((PCHARINFO)pCharData)->Cursor)
	{
		Ret.Type=pItemType;
		return true;
	}
	return false;
}

BOOL dataLastSpawn(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0])
	{
		if (szIndex[0]>='0' && szIndex[0]<='9')
		{
			unsigned long N=atoi(szIndex)-1;
			if (PSPAWNINFO pSpawn=(PSPAWNINFO)pSpawnList)
			{
				while(N)
				{
					pSpawn=pSpawn->pNext;
					if (!pSpawn)
						return false;
					N--;
				}
				Ret.Ptr=pSpawn;
				Ret.Type=pSpawnType;
				return true;
			}
		}
		else if (szIndex[0]=='-')
		{
			unsigned long N=atoi(&szIndex[1])-1;
			if (PSPAWNINFO pSpawn=(PSPAWNINFO)pLocalPlayer)
			{
				while(N)
				{
					pSpawn=pSpawn->pPrev;
					if (!pSpawn)
						return false;
					N--;
				}
				Ret.Ptr=pSpawn;
				Ret.Type=pSpawnType;
				return true;
			}
		}
	}
	else
	{
		Ret.Ptr=pSpawnList;
		Ret.Type=pSpawnType;
		return true;
	}
	return false;
}

BOOL dataNearestSpawn(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0])
	{
		PCHAR pSearch;
		unsigned long nth;
		SEARCHSPAWN ssSpawn;
		ClearSearchSpawn(&ssSpawn);
		ssSpawn.FRadius=999999.0f;
		if (pSearch=strchr(szIndex,','))
		{
			*pSearch=0;
			++pSearch;
			ParseSearchSpawn(pSearch,&ssSpawn);
			nth=atoi(szIndex);
		}
		else
		{
			if (szIndex[0]>='0' && szIndex[0]<='9')
			{
				nth=atoi(szIndex);
			}
			else
			{
				nth=1;
				ParseSearchSpawn(szIndex,&ssSpawn);
			}
		}

		for (unsigned long N = 0 ; N < gSpawnCount ; N++)
		{
			if (EQP_DistArray[N].Value.Float>ssSpawn.FRadius)
				return false;
			if (SpawnMatchesSearch(&ssSpawn,(PSPAWNINFO)pCharSpawn,(PSPAWNINFO)EQP_DistArray[N].VarPtr.Ptr))
			{
				if (--nth==0)
				{
					Ret.Ptr=EQP_DistArray[N].VarPtr.Ptr;
					Ret.Type=pSpawnType;
					return true;
				}
			}
		}
	}
	// No spawn
	return false;
}

BOOL dataSpawnCount(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0])
	{
		SEARCHSPAWN ssSpawn;
		ClearSearchSpawn(&ssSpawn);
		ParseSearchSpawn(szIndex,&ssSpawn);
		
		Ret.DWord=CountMatchingSpawns(&ssSpawn,GetCharInfo()->pSpawn,TRUE);
		Ret.Type=pIntType;
		return true;
	}
	else
	{
		Ret.DWord=gSpawnCount;
		Ret.Type=pIntType;
		return true;
	}
}

BOOL dataTime(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
    time_t CurTime;
    time(&CurTime);
    Ret.Ptr= localtime( &CurTime ); 	
	Ret.Type=pTimeType;
	return true;
}
BOOL dataGameTime(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	struct tm* pTime=(struct tm*)&DataTypeTemp[0];
	ZeroMemory(pTime,sizeof(struct tm));
	pTime->tm_mday=((PWORLDDATA)pWorldData)->Day;
	pTime->tm_hour=((PWORLDDATA)pWorldData)->Hour-1;
	pTime->tm_min=((PWORLDDATA)pWorldData)->Minute;
	pTime->tm_mon=((PWORLDDATA)pWorldData)->Month;
	pTime->tm_year=((PWORLDDATA)pWorldData)->Year-1900;
	Ret.Ptr=pTime;
	Ret.Type=pTimeType;
	return true;
}

BOOL dataIni(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	PCHAR pIniFile=0;
	PCHAR pSection=0;
	PCHAR pKey=0;
	PCHAR pDefault="";
	if (pIniFile=strtok(szIndex,","))
	{
		if (pSection=strtok(NULL,","))
		{
			if (!strcmp(pSection,"-1"))
				pSection=0;
			if (pKey=strtok(NULL,","))
			{
				if (!strcmp(pKey,"-1"))
					pKey=0;
				pDefault=strtok(NULL,"¦");
				if (!pDefault)
					pDefault="";
			}
		}
	}
	else
		return false;
	CHAR FileName[MAX_STRING]={0};

	PCHAR pTemp=pIniFile;
	while(pTemp[0])
	{
		if (pTemp[0]=='/')
			pTemp[0]='\\';
		pTemp++;
	}

	if (pIniFile[0]!='\\' && !strchr(pIniFile,':'))
		sprintf(FileName,"%s\\%s",gszMacroPath,pIniFile);
	else
		strcpy(FileName,pIniFile);

	if (!strchr(pIniFile,'.'))
		strcat(FileName,".ini");

	if (!_FileExists(FileName))
	{
		if (pDefault[0])
		{
			strcpy(DataTypeTemp,pDefault);
			Ret.Ptr=&DataTypeTemp[0];
			Ret.Type=pStringType;
			return true;
		}
		return false;
	}

	if (DWORD nSize=GetPrivateProfileString(pSection,pKey,pDefault,DataTypeTemp,MAX_STRING,FileName))
	{
		if (nSize>2)
		for (unsigned long N = 0 ; N < nSize-2 ; N++)
			if (DataTypeTemp[N]==0)
				DataTypeTemp[N]='|';
		if ((!pSection || !pKey) && (nSize<MAX_STRING-3))
			strcat(DataTypeTemp,"||");

		Ret.Ptr=&DataTypeTemp[0];
		Ret.Type=pStringType;
		return true;
	}
	if (pDefault[0])
	{
		strcpy(DataTypeTemp,pDefault);
		Ret.Ptr=&DataTypeTemp[0];
		Ret.Type=pStringType;
		return true;
	}
	return false;
}

BOOL dataDefined(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	Ret.DWord=(FindMQ2DataVariable(szIndex)!=0);
	Ret.Type=pBoolType;
	return true;
}

BOOL dataSelectedItem(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (pSelectedItem && ((PEQCURRENTSELECTION)pSelectedItem)->TextureAnim)
	{
		Ret.Ptr=*(PCONTENTS *)((PEQCURRENTSELECTION)pSelectedItem)->TextureAnim;
		Ret.Type=pItemType;
		return true;
	}
	return false;
}

BOOL dataFindItemBank(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	DWORD N=1;
	PCHAR pName=&szIndex[0];
	BOOL bExact=false;

	if (*pName=='=')
	{
		bExact=true;
		pName++;
	}
	CHAR Name[MAX_STRING]={0};
	CHAR Temp[MAX_STRING]={0};
	strlwr(strcpy(Name,pName));
	PCHARINFO pCharInfo=GetCharInfo();


	for (unsigned long nPack=0 ; nPack < NUM_BANK_SLOTS ; nPack++)
	{
		PCHARINFO pCharInfo=GetCharInfo();
		if (PCONTENTS pPack=pCharInfo->Bank[nPack])
		{
			if (bExact)
			{
				if (!stricmp(Name,pPack->Item->Name))
				{
					Ret.Ptr=pPack;
					Ret.Type=pItemType;
					return true;
				}
			}
			else 
			{
				if(strstr(strlwr(strcpy(Temp,pPack->Item->Name)),Name))
				{
					Ret.Ptr=pPack;
					Ret.Type=pItemType;
					return true;
				}
			}
			if (pPack->Item->Type==ITEMTYPE_PACK)
			{
				for (unsigned long nItem=0 ; nItem < pPack->Item->Slots ; nItem++)
				{
					if (PCONTENTS pItem=pPack->Contents[nItem])
					{
						if (bExact)
						{
							if (!stricmp(Name,pItem->Item->Name))
							{
								Ret.Ptr=pItem;
								Ret.Type=pItemType;
								return true;
							}
						}
						else 
						{
							if(strstr(strlwr(strcpy(Temp,pItem->Item->Name)),Name))
							{
								Ret.Ptr=pItem;
								Ret.Type=pItemType;
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

BOOL dataFindItem(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	DWORD N=1;
	PCHAR pName=&szIndex[0];
	BOOL bExact=false;

	if (*pName=='=')
	{
		bExact=true;
		pName++;
	}
	CHAR Name[MAX_STRING]={0};
	CHAR Temp[MAX_STRING]={0};
	strlwr(strcpy(Name,pName));
	PCHARINFO pCharInfo=GetCharInfo();

	for (unsigned long nSlot=0 ; nSlot < 0x1E ; nSlot++)
	{
		if (PCONTENTS pItem=pCharInfo->InventoryArray[nSlot])
		{
			if (bExact)
			{
				if (!stricmp(Name,pItem->Item->Name))
				{
					Ret.Ptr=pItem;
					Ret.Type=pItemType;
					return true;
				}
			}
			else 
			{
				if(strstr(strlwr(strcpy(Temp,pItem->Item->Name)),Name))
				{
					Ret.Ptr=pItem;
					Ret.Type=pItemType;
					return true;
				}
			}
		}
	}

	for (unsigned long nPack=0 ; nPack < 8 ; nPack++)
	{
		if (PCONTENTS pPack=pCharInfo->Inventory.Pack[nPack])
		{
			if (pPack->Item->Type==ITEMTYPE_PACK)
			{
				for (unsigned long nItem=0 ; nItem < pPack->Item->Slots ; nItem++)
				{
					if (PCONTENTS pItem=pPack->Contents[nItem])
					{
						if (bExact)
						{
							if (!stricmp(Name,pItem->Item->Name))
							{
								Ret.Ptr=pItem;
								Ret.Type=pItemType;
								return true;
							}
						}
						else 
						{
							if(strstr(strlwr(strcpy(Temp,pItem->Item->Name)),Name))
							{
								Ret.Ptr=pItem;
								Ret.Type=pItemType;
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

BOOL dataFindItemCount(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	DWORD N=1;
	PCHAR pName=&szIndex[0];
	BOOL bExact=false;

	if (*pName=='=')
	{
		bExact=true;
		pName++;
	}
	CHAR Name[MAX_STRING]={0};
	CHAR Temp[MAX_STRING]={0};
	strlwr(strcpy(Name,pName));
	PCHARINFO pCharInfo=GetCharInfo();

	unsigned long Count=0;

	for (unsigned long nSlot=0 ; nSlot < 0x1E ; nSlot++)
	{
		if (PCONTENTS pItem=pCharInfo->InventoryArray[nSlot])
		{
			if (bExact)
			{
				if (!stricmp(Name,pItem->Item->Name))
				{
                    if ((pItem->Item->Type != ITEMTYPE_NORMAL) ||
                        (pItem->Item->Stackable != 1))
						Count++;
                    else
                        Count+=pItem->StackCount;
				}
			}
			else 
			{
				if(strstr(strlwr(strcpy(Temp,pItem->Item->Name)),Name))
				{
                    if ((pItem->Item->Type != ITEMTYPE_NORMAL) ||
                        (pItem->Item->Stackable != 1))
						Count++;
                    else
                        Count+=pItem->StackCount;
				}
			}
		}
	}

	for (unsigned long nPack=0 ; nPack < 8 ; nPack++)
	{
		if (PCONTENTS pPack=pCharInfo->Inventory.Pack[nPack])
		{
			if (pPack->Item->Type==ITEMTYPE_PACK)
			{
				for (unsigned long nItem=0 ; nItem < pPack->Item->Slots ; nItem++)
				{
					if (PCONTENTS pItem=pPack->Contents[nItem])
					{
						if (bExact)
						{
							if (!stricmp(Name,pItem->Item->Name))
							{
                                if ((pItem->Item->Type != ITEMTYPE_NORMAL) ||
                                    (pItem->Item->Stackable != 1))
								    Count++;
                                else
                                    Count+=pItem->StackCount;
							}
						}
						else 
						{
							if(strstr(strlwr(strcpy(Temp,pItem->Item->Name)),Name))
							{
                                if ((pItem->Item->Type != ITEMTYPE_NORMAL) ||
                                    (pItem->Item->Stackable != 1))
								    Count++;
                                else
                                    Count+=pItem->StackCount;
							}
						}
					}
				}
			}
		}
	}

	Ret.DWord=Count;
	Ret.Type=pIntType;

	return true;
}

BOOL dataFindItemBankCount(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	DWORD N=1;
	PCHAR pName=&szIndex[0];
	BOOL bExact=false;

	if (*pName=='=')
	{
		bExact=true;
		pName++;
	}
	CHAR Name[MAX_STRING]={0};
	CHAR Temp[MAX_STRING]={0};
	strlwr(strcpy(Name,pName));
	PCHARINFO pCharInfo=GetCharInfo();

	unsigned long Count=0;

	for (unsigned long nPack=0 ; nPack < NUM_BANK_SLOTS ; nPack++)
	{
		PCHARINFO pCharInfo=GetCharInfo();
		if (PCONTENTS pPack=pCharInfo->Bank[nPack])
		{
			if (bExact)
			{
				if (!stricmp(Name,pPack->Item->Name))
				{
                    if ((pPack->Item->Type != ITEMTYPE_NORMAL) ||
                        (pPack->Item->Stackable != 1))
						Count++;
                    else
                        Count+=pPack->StackCount;
				}
			}
			else 
			{
				if(strstr(strlwr(strcpy(Temp,pPack->Item->Name)),Name))
				{
                    if ((pPack->Item->Type != ITEMTYPE_NORMAL) ||
                        (pPack->Item->Stackable != 1))
						Count++;
                    else
                        Count+=pPack->StackCount;
				}
			}
			if (pPack->Item->Type==ITEMTYPE_PACK)
			{
				for (unsigned long nItem=0 ; nItem < pPack->Item->Slots ; nItem++)
				{
					if (PCONTENTS pItem=pPack->Contents[nItem])
					{
						if (bExact)
						{
							if (!stricmp(Name,pItem->Item->Name))
							{
                                if ((pItem->Item->Type != ITEMTYPE_NORMAL) ||
                                    (pItem->Item->Stackable != 1))
								    Count++;
                                else
                                    Count+=pItem->StackCount;
							}
						}
						else 
						{
							if(strstr(strlwr(strcpy(Temp,pItem->Item->Name)),Name))
							{
                                if ((pItem->Item->Type != ITEMTYPE_NORMAL) ||
                                    (pItem->Item->Stackable != 1))
								    Count++;
                                else
                                    Count+=pItem->StackCount;
							}
						}
					}
				}
			}
		}
	}

	Ret.DWord=Count;
	Ret.Type=pIntType;

	return true;
}


BOOL dataInvSlot(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	if (szIndex[0]>='0' && szIndex[0]<='9')
	{
		Ret.DWord=atoi(szIndex);
		Ret.Type=pInvSlotType;
		return true;
	}
	else
	{
		CHAR Temp[MAX_STRING]={0};
		strlwr(strcpy(Temp,szIndex));
		Ret.DWord=ItemSlotMap[Temp];
		if (Ret.DWord || !stricmp(Temp,"charm"))
		{
			Ret.Type=pInvSlotType;
			return true;
		}
	}
	return false;
}

BOOL dataPlugin(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	if (szIndex[0]>='0' && szIndex[0]<='9')
	{
		unsigned long N = atoi(szIndex)-1;
		PMQPLUGIN pPlugin=pPlugins;
		while(N)
		{
			pPlugin=pPlugin->pNext;
			if (!pPlugin)
				return false;
			N--;
		}
		Ret.Ptr=pPlugin;
		Ret.Type=pPluginType;
		return true;
	}
	else
	{
		// name
		PMQPLUGIN pPlugin=pPlugins;
		while(pPlugin)
		{
			if (!stricmp(pPlugin->szFilename,szIndex))
			{
				Ret.Ptr=pPlugin;
				Ret.Type=pPluginType;
				return true;
			}
			pPlugin=pPlugin->pNext;
		}
	}
	return false;
}

BOOL dataSkill(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	if (IsNumber(szIndex))
	{
		unsigned long nSkill=atoi(szIndex)-1;
		if (nSkill>=100)
			return false;
		if (Ret.Ptr=&SkillDict[nSkill])
		{
			Ret.Type=pSkillType;
			return true;
		}
	}
	else
	{
		for (unsigned long nSkill=0 ; nSkill<100 ; nSkill++)
		{
			if (PSKILL pSkill=SkillDict[nSkill])
			{
				if (PCHAR pName=pStringTable->getString(pSkill->nName,0))
				{
					if (!stricmp(szIndex,pName))
					{
						Ret.Ptr=&SkillDict[nSkill];
						Ret.Type=pSkillType;
						return true;
					}
				}
			}
		}
	}

	return false;
}

BOOL dataAltAbility(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (!szIndex[0])
		return false;
	if (IsNumber(szIndex))
	{
		unsigned long nAbility=atoi(szIndex);
		if (nAbility>=NUM_ALT_ABILITIES || !nAbility)
			return false;
		if (Ret.Ptr=&((PALTADVMGR)pAltAdvManager)->Abilities[nAbility])
		{
			Ret.Type=pAltAbilityType;
			return true;
		}
	}
	else
	{
		for (unsigned long nAbility=1 ; nAbility<NUM_ALT_ABILITIES ; nAbility++)
		{
			if (PALTABILITY pAbility=((PALTADVMGR)pAltAdvManager)->Abilities[nAbility])
			{
				if (PCHAR pName=pStringTable->getString(pAbility->nName,0))
				{
					if (!stricmp(szIndex,pName))
					{
						Ret.Ptr=&((PALTADVMGR)pAltAdvManager)->Abilities[nAbility];
						Ret.Type=pAltAbilityType;
						return true;
					}
				}
			}
		}
	}

	return false;
}

BOOL dataRaid(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	Ret.DWord=0;
	Ret.Type=pRaidType;
	return true;
}

BOOL dataNamingSpawn(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (Ret.Ptr=pNamingSpawn)
	{
		Ret.Type=pSpawnType;
		return true;
	}
	return false;
}
