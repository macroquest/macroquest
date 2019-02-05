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

#include <memory>
#include <unordered_map>

std::unordered_map<std::string, MQ2Type*> MQ2DataTypeMap;

MQ2Type *FindMQ2DataType(PCHAR Name)
{
	lockit lk(ghVariableLock);
	auto iter = MQ2DataTypeMap.find(Name);
	if (iter == MQ2DataTypeMap.end())
		return nullptr;

	return iter->second;
}

BOOL MQ2Internal::AddMQ2Type(MQ2Type &Type)
{
	lockit lk(ghVariableLock);
	// returns pair with iterator pointing to the constructed
	// element, and a bool indicating if it was actually inserted.
	// this will not replace existing elements.
	auto result = MQ2DataTypeMap.emplace(Type.GetName(), &Type);
	return result.second;
}

BOOL MQ2Internal::RemoveMQ2Type(MQ2Type &Type)
{
	lockit lk(ghVariableLock);
	// use iterator to erase. allows us to check for existence
	// and erase it without any waste
	PCHAR thetypename = Type.GetName();
	if (!thetypename)
		return false;
	auto iter = MQ2DataTypeMap.find(thetypename);
	if (iter == MQ2DataTypeMap.end())
		return false;

	// The type existed. Erase it.
	MQ2DataTypeMap.erase(iter);
	return true;
}

inline PMQ2DATAITEM FindMQ2Data(PCHAR szName)
{
	lockit lk(ghVariableLock);
	auto iter = MQ2DataMap.find(szName);
	if (iter == MQ2DataMap.end())
		return nullptr;

	return iter->second.get();
}

BOOL AddMQ2Data(PCHAR szName, fMQData Function)
{
	lockit lk(ghVariableLock);
	// check if the item exists first, so we don't construct
	// something we don't actually need.
	if (MQ2DataMap.find(szName) != MQ2DataMap.end())
		return false;

	// create new MQ2DATAITEM inside a unique_ptr
	auto newItem = std::make_unique<MQ2DATAITEM>();
	strcpy_s(newItem->Name, szName);
	newItem->Function = Function;

	// put the new item into the map
	MQ2DataMap.emplace(szName, std::move(newItem));
	return true;
}

BOOL RemoveMQ2Data(PCHAR szName)
{
	lockit lk(ghVariableLock);
	auto iter = MQ2DataMap.find(szName);
	if (iter == MQ2DataMap.end())
		return false;

	MQ2DataMap.erase(iter);
	return true;
}

std::unordered_map<std::string, std::vector<MQ2Type*>> MQ2DataExtensions;

bool AddMQ2TypeExtension(const char* szName, MQ2Type* extension)
{
	// get the extension record for this type name
	auto& record = MQ2DataExtensions[szName];

	// check if we already have this extension added
	if (std::find(record.begin(), record.end(), extension) != record.end())
		return false;

	// insert extension into the record
	record.push_back(extension);
	return true;
}

bool RemoveMQ2TypeExtension(const char* szName, MQ2Type* extension)
{
	// check if we have a record for this type name
	auto iter = MQ2DataExtensions.find(szName);
	if (iter == MQ2DataExtensions.end())
		return false;

	// check if this extension is registered in this record
	auto& record = iter->second;
	auto iter2 = std::find(record.begin(), record.end(), extension);
	if (iter2 == record.end())
		return false;

	// delete the existing record
	record.erase(iter2);

	// if the record is empty, remove it
	if (record.empty())
		MQ2DataExtensions.erase(iter);

	return true;
}

// -1 = no exists, 0 = fail, 1 = success
int FindMacroDataMember(MQ2Type* type, MQ2TYPEVAR& Result, PCHAR pStart, PCHAR pIndex,
	bool checkFirst = false)
{
	// search for extensions on this type
	auto extIter = MQ2DataExtensions.find(type->GetName());
	if (extIter != MQ2DataExtensions.end())
	{
		// we have at least one extension. process each one until a match is found
		for (MQ2Type* ext : extIter->second)
		{
			// optimize for failure case, check if exists first
			int result = FindMacroDataMember(ext, Result, pStart, pIndex, true);
			if (result != -1)
				return result;
		}
	}

	// the difference between these two branches is whether we check for existence
	// first or not. Because we assume extensions aren't going to be the common case,
	// we will check for existence first to avoid multiple lookups in failure cases.

	if (checkFirst)
	{
		if (!type->FindMember(pStart) && !type->InheritedMember(pStart))
		{
			return -1;
		}

		return type->GetMember(Result.VarPtr, pStart, pIndex, Result) ? 1 : 0;
	}

	if (type->GetMember(Result.VarPtr, pStart, pIndex, Result))
		return 1;

	if (!type->FindMember(pStart) && !type->InheritedMember(pStart))
	{
		return -1;
	}

	return 0;
}
void DumpWarning(PCHAR pStart, int index)
{
	if (PMACROBLOCK pBlock = GetCurrentMacroBlock())
	{
		MACROLINE ml = pBlock->Line[index];
		BOOL oldbAllErrorsDumpStack = bAllErrorsDumpStack;
		BOOL oldbAllErrorsFatal = bAllErrorsFatal;
		bAllErrorsDumpStack = FALSE;
		bAllErrorsFatal = FALSE;
		WriteChatf("\arWARNING: \awUndefined Variable \ag%s\aw used on line %d@%s \ay%s\ax\nMacro Paused.", pStart, ml.LineNumber, ml.SourceFile.c_str(), ml.Command.c_str());
		pBlock->Paused = 1;
		bAllErrorsDumpStack = oldbAllErrorsDumpStack;
		bAllErrorsFatal = oldbAllErrorsFatal;
	}
}

static bool function_exists(const PCHAR name)
{
	return (gMacroBlock &&
		(gMacroSubLookupMap.find(name) != gMacroSubLookupMap.end()));
}

static bool call_function(const PCHAR name, const PCHAR args)
{
	std::list<std::string>csvColumn;
	const char *mystart=args;
	bool instring{false};        
	std::string str;
	for (const char* p=mystart; *p; p++) {
		if (*p==',') {
			str = std::string(mystart, p - mystart);
			trim(str);//remove leading and trailing spaces
			//str = std::regex_replace(str, std::regex("^ +| +$|( ) +"), "$1");//remove leading and trailing spaces
			str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());//remove double quotes
			csvColumn.push_back(str);
			mystart=p+1;
		}
	}
	str = mystart;
	if (str.size()) {
		trim(str);//remove leading and trailing spaces
		//str = std::regex_replace(str, std::regex("^ +| +$|( ) +"), "$1");//remove leading and trailing spaces
		str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());//remove double quotes
		csvColumn.push_back(str);
	}
	const auto saved_block = gMacroBlock->CurrIndex;
	const auto pChar = (PSPAWNINFO)pCharSpawn;
	CHAR sub_line[MAX_STRING];
	strcpy_s(sub_line, name);
	if (csvColumn.size()) {
		strcat_s(sub_line, " ");
		for (std::list<std::string>::iterator i = csvColumn.begin(); i != csvColumn.end();i++) {
			strcat_s(sub_line, "\"");
			strcat_s(sub_line, (*i).c_str());
			strcat_s(sub_line, "\"");
			std::list<std::string>::iterator j = i;
			j++;
			if(j!=csvColumn.end())
				strcat_s(sub_line, " ");
		}
	}
	Call(pChar, sub_line);
	auto sub_block = gMacroBlock->Line.find(gMacroBlock->CurrIndex);
	sub_block++;
	gMacroBlock->CurrIndex = sub_block->first;
	while (gMacroBlock && sub_block != gMacroBlock->Line.end())
	{
		gMacroStack->LocationIndex = gMacroBlock->CurrIndex;
		DoCommand(pChar, (PCHAR)sub_block->second.Command.c_str());//we are in a while loop here, if they do stuff like /mpq or /delay those get thrown out the window.
		if (!gMacroBlock)//it doesnt matter, this is for quick evaluations, if they are using it in any other way its wrong.
			break;
		if (gMacroBlock->CurrIndex == saved_block)
			return true; // /return happened
		sub_block = gMacroBlock->Line.find(gMacroBlock->CurrIndex);
		sub_block++;
		gMacroBlock->CurrIndex = sub_block->first;
	}
	FatalError("No /return in Subroutine %s", name);
	return false;
}

bool EvaluateDataExpression(MQ2TYPEVAR& Result, PCHAR pStart, PCHAR pIndex, bool function_allowed = false)
{
	if (!Result.Type)
	{
		if (!gWarning) {//if they have warnings turned on in the macro, we will disregard checking the map
			if (gUndeclaredVars.find(pStart) != gUndeclaredVars.end())
				return false;//its a undefined variable no point in moving on further.
		}
		if (PMQ2DATAITEM DataItem = FindMQ2Data(pStart))
		{
			if (!DataItem->Function(pIndex, Result))
			{
				return false;
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
						return false;
					}
				}
			}
			else
				Result = DataVar->Var;
		}
		else if (function_allowed && function_exists(pStart))
		{
			if (!call_function(pStart, pIndex))
				return false;
			strcpy_s(DataTypeTemp, gMacroStack->Return);
			Result.Ptr = &DataTypeTemp[0];
			Result.Type = pStringType;
		}
		else
		{
			if (gMacroBlock) {
				if (gWarning) {
					DumpWarning(pStart,gMacroBlock->CurrIndex);
				}
				gUndeclaredVars[pStart] = gMacroBlock->CurrIndex;
			}
			return false;
		}
	}
	else
	{
		int result = FindMacroDataMember(Result.Type, Result, pStart, pIndex);
		if (result < 0)
		{
			MQ2DataError("No such '%s' member '%s'", Result.Type->GetName(), pStart);
		}
		if (result <= 0)
			return false;
	}
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
	AddMQ2Data("GroundItemCount", dataGroundItemCount);
	AddMQ2Data("Merchant", dataMerchant);
	AddMQ2Data("PointMerchant", dataPointMerchant);
	AddMQ2Data("Mercenary", dataMercenary);
	AddMQ2Data("Pet", dataPet);
	AddMQ2Data("Window", dataWindow);
	AddMQ2Data("Menu", dataMenu);
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
	AddMQ2Data("Illusion", dataIllusion);
	AddMQ2Data("Familiar", dataFamiliar);
	AddMQ2Data("Alias", dataAlias);
#if !defined(ROF2EMU) && !defined(UFEMU)
	AddMQ2Data("AdvLoot", dataAdvLoot);
#endif
	AddMQ2Data("Alert", dataAlert);
	AddMQ2Data("Range", dataRange);
}

void ShutdownMQ2Data()
{
	lockit lk(ghVariableLock);
	MQ2DataMap.clear();
}

BOOL ParseMQ2DataPortion(PCHAR szOriginal, MQ2TYPEVAR &Result)
{
	Result.Type = 0;
	Result.Int64 = 0;
	// Find [] before a . or null
	PCHAR pPos = &szOriginal[0];
	PCHAR pStart = pPos;
	CHAR Index[MAX_STRING] = { 0 };
	PCHAR pIndex = &Index[0];
	BOOL Quote = FALSE;
	bool function_allowed = false;
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
				return TRUE;
			}

			if (!EvaluateDataExpression(Result, pStart, pIndex, function_allowed))
				return FALSE;

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

				return TRUE;
			}
			else
			{
				if (!EvaluateDataExpression(Result, pStart, pIndex))
					return FALSE;
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
		{
			if (*pPos == '[')
			{
				// index
				*pPos = 0;
				++pPos;
				function_allowed = true;
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
			{
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

						return TRUE;
					}

					if (!EvaluateDataExpression(Result, pStart, pIndex))
						return FALSE;

					pStart = &pPos[1];
					Index[0] = 0;
				}
			}
		}
		++pPos;
	}

}

BOOL ParseMacroData(PCHAR szOriginal, SIZE_T BufferSize)
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
	MQ2TYPEVAR Result = { 0 };
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
		strcpy_s(szCurrent, &pBrace[2]);
		if (szCurrent[0] == 0)
		{
			goto pmdbottom;
		}
		if (ParseMacroData(szCurrent, sizeof(szCurrent)))
		{
			unsigned long NewLength = strlen(szCurrent);
			memmove(&pBrace[NewLength + 1], &pEnd[1], strlen(&pEnd[1]) + 1);
			int addrlen = (int)(pBrace - szOriginal);
			memcpy_s(pBrace, BufferSize - addrlen, szCurrent, NewLength);
			pEnd = &pBrace[NewLength];
			*pEnd = 0;
		}
		ZeroMemory(&Result, sizeof(Result));
		Result.Type = 0;
		Result.Int64 = 0;
		if (!ParseMQ2DataPortion(szCurrent, Result) || !Result.Type || !Result.Type->ToString(Result.VarPtr, szCurrent)) {
			strcpy_s(szCurrent, "NULL");
		}
		NewLength = strlen(szCurrent);
		memmove(&pBrace[NewLength], &pEnd[1], strlen(&pEnd[1]) + 1);
		int addrlen = (int)(pBrace - szOriginal);
		memcpy_s(pBrace, BufferSize - addrlen, szCurrent, NewLength);
		if (bAllowCommandParse == false) {
			bAllowCommandParse = true;
			Changed = false;
			break;
		}
		else {
			Changed = true;
		}
	pmdbottom:;
	} while (pBrace = strstr(&pBrace[1], "${"));
	if (Changed)
		while (ParseMacroData(szOriginal, BufferSize))
		{
		}
	return Changed;
}

#endif
