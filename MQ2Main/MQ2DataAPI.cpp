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
#ifndef ISXEQ

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW


#include "MQ2Main.h"



map<string, DWORD> MQ2DataTypeMap;
CIndex<MQ2Type*> MQ2DataTypes;

/*inline/**/ MQ2Type *FindMQ2DataType(PCHAR Name)
{
	unsigned long N = MQ2DataTypeMap[Name];
	if (!N)
		return 0;
	N--;
	return MQ2DataTypes[N];
}

namespace MQ2Internal
{
	BOOL AddMQ2Type(MQ2Type &Type)
	{
		if (FindMQ2DataType(Type.GetName()))
			return false;
		unsigned long N = MQ2DataTypes.GetUnused();
		MQ2DataTypes[N] = &Type;
		MQ2DataTypeMap[Type.GetName()] = N + 1;
		return true;
	}

	BOOL RemoveMQ2Type(MQ2Type &Type)
	{
		unsigned long N = MQ2DataTypeMap[Type.GetName()];
		if (!N)
			return 0;
		N--;
		if (MQ2Type *pType = MQ2DataTypes[N])
		{
			MQ2DataTypes[N] = 0;
			return false;
		}
		MQ2DataTypeMap[Type.GetName()] = 0;
		return true;
	}
};

map<string, DWORD> MQ2DataMap;
CIndex<PMQ2DATAITEM> MQ2DataItems;

inline PMQ2DATAITEM FindMQ2Data(PCHAR szName)
{
	unsigned long N = MQ2DataMap[szName];
	if (!N)
		return 0;
	N--;
	return MQ2DataItems[N];
}

BOOL AddMQ2Data(PCHAR szName, fMQData Function)
{
	if (FindMQ2Data(szName))
		return false;
	unsigned long N = MQ2DataItems.GetUnused();
	PMQ2DATAITEM pNew = new MQ2DATAITEM;
	strcpy(pNew->Name, szName);
	pNew->Function = Function;
	MQ2DataItems[N] = pNew;
	MQ2DataMap[szName] = N + 1;
	return true;
}

BOOL RemoveMQ2Data(PCHAR szName)
{
	unsigned long N = MQ2DataMap[szName];
	if (!N)
		return 0;
	N--;
	if (PMQ2DATAITEM pItem = MQ2DataItems[N])
	{
		MQ2DataItems[N] = 0;
		delete pItem;
	}
	MQ2DataMap[szName] = 0;
	return true;
}

BOOL dataType(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (MQ2Type* pType = FindMQ2DataType(szIndex))
	{
		Ret.Ptr = pType;
		Ret.Type = pTypeType;
		return true;
	}
	return false;
}

void InitializeMQ2Data()
{
	AddMQ2Data("Spawn", dataSpawn);
	AddMQ2Data("Target", dataTarget);
	AddMQ2Data("Me", dataCharacter);
	AddMQ2Data("Spell", dataSpell);
	AddMQ2Data("Switch", dataSwitch);
	AddMQ2Data("Ground", dataGroundItem);
	AddMQ2Data("Merchant", dataMerchant);
	AddMQ2Data("Mercenary", dataMercenary);
	AddMQ2Data("Pet", dataPet);
	AddMQ2Data("Window", dataWindow);
	AddMQ2Data("Macro", dataMacro);
	AddMQ2Data("EverQuest", dataEverQuest);
	AddMQ2Data("MacroQuest", dataMacroQuest);
	AddMQ2Data("Math", dataMath);
	AddMQ2Data("Zone", dataZone);
	AddMQ2Data("Group", dataGroup);
	AddMQ2Data("String", dataString);
	AddMQ2Data("Int", dataInt);
	AddMQ2Data("Bool", dataBool);
	AddMQ2Data("Float", dataFloat);
	AddMQ2Data("Corpse", dataCorpse);
	AddMQ2Data("If", dataIf);
	AddMQ2Data("Cursor", dataCursor);
	AddMQ2Data("NearestSpawn", dataNearestSpawn);
	AddMQ2Data("Type", dataType);
	AddMQ2Data("Time", dataTime);
	AddMQ2Data("GameTime", dataGameTime);
	AddMQ2Data("Ini", dataIni);
	AddMQ2Data("Heading", dataHeading);
	AddMQ2Data("Defined", dataDefined);
	AddMQ2Data("LastSpawn", dataLastSpawn);
	AddMQ2Data("FindItem", dataFindItem);
	AddMQ2Data("FindItemBank", dataFindItemBank);
	AddMQ2Data("InvSlot", dataInvSlot);
	AddMQ2Data("SelectedItem", dataSelectedItem);
	AddMQ2Data("FindItemCount", dataFindItemCount);
	AddMQ2Data("FindItemBankCount", dataFindItemBankCount);
	//AddMQ2Data("GroupLeader",dataGroupLeader);    
	//AddMQ2Data("GroupLeaderName",dataGroupLeaderName);
	AddMQ2Data("Skill", dataSkill);
	AddMQ2Data("AltAbility", dataAltAbility);
	AddMQ2Data("Raid", dataRaid);
	AddMQ2Data("NamingSpawn", dataNamingSpawn);
	AddMQ2Data("SpawnCount", dataSpawnCount);
	AddMQ2Data("LineOfSight", dataLineOfSight);
	AddMQ2Data("Plugin", dataPlugin);
	AddMQ2Data("Select", dataSelect);
	AddMQ2Data("DoorTarget", dataDoorTarget);
	AddMQ2Data("ItemTarget", dataItemTarget);
	AddMQ2Data("DynamicZone", dataDynamicZone);
	AddMQ2Data("Friends", dataFriends);
	AddMQ2Data("Task", dataTask);
	AddMQ2Data("Mount", dataMount);
	AddMQ2Data("Alias", dataAlias);
#ifndef EMU
	AddMQ2Data("AdvLoot", dataAdvLoot);
#endif
	AddMQ2Data("Alert", dataAlert);
}



void ShutdownMQ2Data()
{
	MQ2DataItems.Cleanup();
}

BOOL ParseMQ2DataPortion(PCHAR szOriginal, MQ2TYPEVAR &Result)
{
	Result.Type = 0;
	Result.DWord = 0;
	// Find [] before a . or null
	PCHAR pPos = &szOriginal[0];
	PCHAR pStart = pPos;
	CHAR Index[MAX_STRING] = { 0 };
	PCHAR pIndex = &Index[0];
	BOOL Quote = FALSE;
	while (1)
	{
		if (*pPos == 0)
		{
			// end completely. process
			if (pStart == pPos)
			{
				if (!Result.Type)
				{
					MQ2DataError("Nothing to parse");
					return FALSE;
				}
				//Result.Type->ToString(Result.VarPtr,szCurrent);
				return TRUE;
			}
			else
			{
				if (!Result.Type)
				{
					if (PMQ2DATAITEM DataItem = FindMQ2Data(pStart))
					{
						if (!DataItem->Function(pIndex, Result))
						{
							return FALSE;
						}
					}
					else if (PDATAVAR DataVar = FindMQ2DataVariable(pStart))
					{
						if (pIndex[0])
						{
							if (DataVar->Var.Type == pArrayType)
							{
								if (!((CDataArray*)DataVar->Var.Ptr)->GetElement(pIndex, Result))
								{
									return FALSE;
								}
							}
						}
						else
							Result = DataVar->Var;
					}
					else
					{
						//MQ2DataError("No such Top-Level Object '%s'",pStart);
						return FALSE;
					}
				}
				else
				{
					if (!Result.Type->GetMember(Result.VarPtr, pStart, pIndex, Result))
					{
						if (!Result.Type->FindMember(pStart) && !Result.Type->InheritedMember(pStart))
						{
							MQ2DataError("No such '%s' member '%s'", Result.Type->GetName(), pStart);
						}
						return FALSE;
					}
				}
			}
			//Result.Type->ToString(Result.VarPtr,szCurrent);

			// done processing
			return TRUE;
		}
		if (*pPos == '(')
		{
			*pPos = 0;
			if (pStart == pPos)
			{
				if (!Result.Type)
				{
					MQ2DataError("Encountered typecast without object to cast");
					return FALSE;
				}
				//Result.Type->ToString(Result.VarPtr,szCurrent);
				return TRUE;
			}
			else
			{
				if (!Result.Type)
				{
					if (PMQ2DATAITEM DataItem = FindMQ2Data(pStart))
					{
						if (!DataItem->Function(pIndex, Result))
						{
							return FALSE;
						}
					}
					else if (PDATAVAR DataVar = FindMQ2DataVariable(pStart))
					{
						if (pIndex[0])
						{
							if (DataVar->Var.Type == pArrayType)
							{
								if (!((CDataArray*)DataVar->Var.Ptr)->GetElement(pIndex, Result))
								{
									return FALSE;
								}
							}
						}
						else
							Result = DataVar->Var;
					}
					else
					{
						//MQ2DataError("No such Top-Level Object '%s'",pStart);
						return FALSE;
					}

				}
				else
				{
					if (!Result.Type->GetMember(Result.VarPtr, pStart, pIndex, Result))
					{
						if (!Result.Type->FindMember(pStart) && !Result.Type->InheritedMember(pStart))
						{
							MQ2DataError("No such '%s' member '%s'", Result.Type->GetName(), pStart);
						}
						return FALSE;
					}
				}
			}
			if (!Result.Type)
			{
				// error
				return FALSE;
			}
			*pPos = 0;
			++pPos;
			PCHAR pType = pPos;
			while (*pPos != ')')
			{
				if (!*pPos)
				{
					// error
					MQ2DataError("Encountered unmatched parenthesis");
					return FALSE;
				}
				++pPos;
			}
			*pPos = 0;
			MQ2Type *pNewType = FindMQ2DataType(pType);
			if (!pNewType)
			{
				// error
				MQ2DataError("Unknown type '%s'", pType);
				return FALSE;
			}
			if (pNewType == pTypeType)
			{
				Result.Ptr = Result.Type;
				Result.Type = pTypeType;
			}
			else
				Result.Type = pNewType;

			if (pPos[1] == '.')
			{
				++pPos;
				pStart = &pPos[1];
			}
			else if (!pPos[1])
			{
				//Result.Type->ToString(Result.VarPtr,szCurrent);
				return TRUE;
			}
			else
			{
				MQ2DataError("Invalid character found after typecast ')%s'", &pPos[1]);
				return FALSE;
			}
		}
		else
			if (*pPos == '[')
			{
				// index
				*pPos = 0;
				++pPos;

				Quote = false;
				BOOL BeginParam = true;
				while (1)
				{
					if (*pPos == 0)
					{
						MQ2DataError("Unmatched bracket or invalid character following bracket found in index: '%s'", pIndex);
						return FALSE;
					}

					if (BeginParam)
					{
						BeginParam = false;
						if (*pPos == '\"')
						{
							Quote = true;
							++pPos;
							continue;
						}
					}
					if (Quote)
					{
						if (*pPos == '\"')
						{
							if (pPos[1] == ']' || pPos[1] == ',')
							{
								Quote = false;
								++pPos;
								continue;
							}
						}
					}
					else
					{
						if (*pPos == ']')
						{
							if (pPos[1] == '.' || pPos[1] == '(' || pPos[1] == 0)
								break;// valid end
						}
						else if (*pPos == ',')
							BeginParam = true;
					}
					*pIndex = *pPos;
					++pIndex;
					++pPos;
				}

				*pIndex = 0;
				pIndex = &Index[0];
				*pPos = 0;
			}
			else
				if (*pPos == '.')
				{
					// end of this one, but more to come!
					*pPos = 0;
					if (pStart == pPos)
					{
						if (!Result.Type)
						{
							MQ2DataError("Encountered member access without object");
							return FALSE;
						}
						//Result.Type->ToString(Result.VarPtr,szCurrent);
						return TRUE;
					}
					else
					{
						if (!Result.Type)
						{
							if (PMQ2DATAITEM DataItem = FindMQ2Data(pStart))
							{
								if (!DataItem->Function(pIndex, Result))
								{
									return FALSE;
								}
							}
							else if (PDATAVAR DataVar = FindMQ2DataVariable(pStart))
							{
								if (pIndex[0])
								{
									if (DataVar->Var.Type == pArrayType)
									{
										if (!((CDataArray*)DataVar->Var.Ptr)->GetElement(pIndex, Result))
										{
											return FALSE;
										}
									}
								}
								else
									Result = DataVar->Var;
							}
							else
							{
								//MQ2DataError("No such Top-Level Object '%s'",pStart);
								return FALSE;
							}

						}
						else
						{
							if (!Result.Type->GetMember(Result.VarPtr, pStart, pIndex, Result))
							{
								if (!Result.Type->FindMember(pStart) && !Result.Type->InheritedMember(pStart))
								{
									MQ2DataError("No such '%s' member '%s'", Result.Type->GetName(), pStart);
								}
								return FALSE;
							}
						}
					}
					pStart = &pPos[1];
					Index[0] = 0;
				}
		++pPos;
	}

}

BOOL ParseMacroData(PCHAR szOriginal)
{
	// find each {}
	PCHAR pBrace = strstr(szOriginal, "${");
	if (!pBrace)
		return false;
	unsigned long NewLength;
	BOOL Changed = false;
	//PCHAR pPos;
	//PCHAR pStart;
	//PCHAR pIndex;
	CHAR szCurrent[MAX_STRING] = { 0 };

	do
	{
		// find this brace's end
		PCHAR pEnd = &pBrace[1];
		BOOL Quote = false;
		BOOL BeginParam = false;
		int nBrace = 1;
		while (nBrace)
		{
			++pEnd;
			if (BeginParam)
			{
				BeginParam = false;
				if (*pEnd == '\"')
				{
					Quote = true;
				}
				continue;
			}
			if (*pEnd == 0)
			{// unmatched brace or quote
				goto pmdbottom;
			}
			if (Quote)
			{
				if (*pEnd == '\"')
				{
					if (pEnd[1] == ']' || pEnd[1] == ',')
					{
						Quote = false;
					}
				}
			}
			else
			{
				if (*pEnd == '}')
				{
					nBrace--;
				}
				else if (*pEnd == '{')
				{
					nBrace++;
				}
				else if (*pEnd == '[' || *pEnd == ',')
					BeginParam = true;
			}

		}
		*pEnd = 0;
		strcpy(szCurrent, &pBrace[2]);
		if (szCurrent[0] == 0)
		{
			goto pmdbottom;
		}
		if (ParseMacroData(szCurrent))
		{
			unsigned long NewLength = strlen(szCurrent);
			memmove(&pBrace[NewLength + 1], &pEnd[1], strlen(&pEnd[1]) + 1);
			strncpy(pBrace, szCurrent, NewLength);
			pEnd = &pBrace[NewLength];
			*pEnd = 0;
		}
		MQ2TYPEVAR Result;
		if (!ParseMQ2DataPortion(szCurrent, Result) || !Result.Type || !Result.Type->ToString(Result.VarPtr, szCurrent))
			strcpy(szCurrent, "NULL");

		NewLength = strlen(szCurrent);

		memmove(&pBrace[NewLength], &pEnd[1], strlen(&pEnd[1]) + 1);
		strncpy(pBrace, szCurrent, NewLength);
		Changed = true;

	pmdbottom:;
	} while (pBrace = strstr(&pBrace[1], "${"));
	if (Changed)
		while (ParseMacroData(szOriginal))
		{
		}
	return Changed;
}

#endif