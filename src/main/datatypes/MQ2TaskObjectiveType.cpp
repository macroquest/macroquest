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
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2TaskObjectiveType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	int Elementindex = VarPtr.HighPart;
	if (Elementindex == -1)
		return false;

	if (!pTaskManager)
		return false;

	if (VarPtr.Int == -1)
		return false;
	int index = HIWORD(VarPtr.DWord);
	if (index == -1)
		return false;
	int type = LOWORD(VarPtr.DWord);

	MQTypeMember* pMember = MQ2TaskObjectiveType::FindMember(Member);
	if (!pMember)
		return false;

	PCTaskStatus* ts = nullptr;
	CTaskEntry* entry = nullptr;

	switch (type)
	{
	case cTaskSystemTypeSoloQuest:
		ts = pTaskManager->GetTaskStatus(pPCData, index, cTaskSystemTypeSoloQuest);
		entry = &pTaskManager->QuestEntries[index];
		break;

	case cTaskSystemTypeSharedQuest:
		ts = pTaskManager->GetTaskStatus(pPCData, 0, cTaskSystemTypeSharedQuest);
		entry = &pTaskManager->SharedTaskEntries[0];
		break;
	};

	if (!entry)
		return false;

	switch (static_cast<TaskObjectiveTypeMembers>(pMember->ID))
	{
		case Instruction:
			pTaskManager->GetElementDescription(&entry->Elements[Elementindex], DataTypeTemp);
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			break;

		case Status:
			if (ts->CurrentCounts[Elementindex] == entry->Elements[Elementindex].RequiredCount)
			{
				strcpy_s(DataTypeTemp,"Done");
			}
			else
			{
				sprintf_s(DataTypeTemp, "%d/%d", ts->CurrentCounts[Elementindex], entry->Elements[Elementindex].RequiredCount);
			}

			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case Zone: {
			int zid = GetIntFromString(entry->Elements[Elementindex].TargetZoneID, 0) & 0x7FFF;

			if (zid == 0)
			{
				strcpy_s(DataTypeTemp, "ALL");

				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			}

			if (zid < MAX_ZONES)
			{
				if (PZONELIST pZList = ((PWORLDDATA)pWorldData)->ZoneArray[zid])
				{
					Dest.Type = pZoneType;
					Dest.Ptr = pZList;
					return true;
				}
			}
			break;
		}

		case xIndex:
			Dest.Int = Elementindex + 1;
			Dest.Type = pIntType;
			return true;

		case Type: {
			switch (entry->Elements[Elementindex].Type)
			{
			case cTaskTypeUnknown:
				strcpy_s(DataTypeTemp, "Unknown");
				break;
			case cTaskTypeNone:
				strcpy_s(DataTypeTemp, "None");
				break;
			case cTaskTypeDeliver:
				strcpy_s(DataTypeTemp, "Deliver");
				break;
			case cTaskTypeKill:
				strcpy_s(DataTypeTemp, "Kill");
				break;
			case cTaskTypeLoot:
				strcpy_s(DataTypeTemp, "Loot");
				break;
			case cTaskTypeHail:
				strcpy_s(DataTypeTemp, "Hail");
				break;
			case cTaskTypeExplore:
				strcpy_s(DataTypeTemp, "Explore");
				break;
			case cTaskTypeTradeskill:
				strcpy_s(DataTypeTemp, "Tradeskill");
				break;
			case cTaskTypeFishing:
				strcpy_s(DataTypeTemp, "Fishing");
				break;
			case cTaskTypeForaging:
				strcpy_s(DataTypeTemp, "Foraging");
				break;
			case cTaskTypeCast:
				strcpy_s(DataTypeTemp, "Cast");
				break;
			case cTaskTypeUseSkill:
				strcpy_s(DataTypeTemp, "UseSkill");
				break;
			case cTaskTypeDZSwitch:
				strcpy_s(DataTypeTemp, "DZSwitch");
				break;
			case cTaskTypeDestroyObject:
				strcpy_s(DataTypeTemp, "DestroyObject");
				break;
			case cTaskTypeCollect:
				strcpy_s(DataTypeTemp, "Collect");
				break;
			case cTaskTypeDialogue:
				strcpy_s(DataTypeTemp, "Dialogue");
				break;
			default:
				strcpy_s(DataTypeTemp, "NULL");
				break;
			};

			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}

		case CurrentCount:
			Dest.Int = ts->CurrentCounts[Elementindex];
			Dest.Type = pIntType;
			return true;

		case RequiredCount:
			Dest.Int = entry->Elements[Elementindex].RequiredCount;
			Dest.Type = pIntType;
			return true;

		case Optional:
			Dest.DWord = entry->Elements[Elementindex].bOptional;
			Dest.Type = pBoolType;
			return true;

		case RequiredItem:
			strcpy_s(DataTypeTemp, entry->Elements[Elementindex].ItemNameList.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case RequiredSkill:
			strcpy_s(DataTypeTemp, entry->Elements[Elementindex].SkillIDList.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case RequiredSpell:
			strcpy_s(DataTypeTemp, entry->Elements[Elementindex].SpellIDList.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case DZSwitchID:
			Dest.DWord = entry->Elements[Elementindex].DZSwitchID;
			Dest.Type = pIntType;
			return true;

		default: break;
	}

	return false;
}

bool MQ2TaskObjectiveType::ToString(MQVarPtr VarPtr, char* Destination)
{
	const int Elementindex = VarPtr.HighPart;
	if (Elementindex == -1)
		return false;

	if (!pTaskManager)
		return false;

	if (VarPtr.Int == -1)
		return false;

	const DWORD index = HIWORD(VarPtr.DWord);
	if (index == 0xFFFFFFFF)
		return false;

	const int type = LOWORD(VarPtr.DWord);

	CTaskEntry* entry = nullptr;
	switch (type)
	{
	case cTaskSystemTypeSoloQuest:
		entry = &pTaskManager->QuestEntries[index];
		break;
	case cTaskSystemTypeSharedQuest:
		entry = &pTaskManager->SharedTaskEntries[0];
		break;
	};

	char szOut[MAX_STRING] = { 0 };
	if (entry)
	{
		pTaskManager->GetElementDescription(&entry->Elements[Elementindex], szOut);
	}

	if (szOut[0] != 0)
	{
		strcpy_s(Destination, MAX_STRING, szOut);
		return true;
	}

	return false;
}

