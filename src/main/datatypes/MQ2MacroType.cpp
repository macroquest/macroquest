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

namespace mq::datatypes {

enum class MacroMembers
{
	Name = 1,
	RunTime,
	Paused,
	Return,
	Params,
	Param,
	CurLine,
	MemUse,
	CurCommand,
	StackSize,
	IsTLO,
	IsOuterVariable,
	CurSub,
};

enum class MacroMethods
{
	Undeclared = 1,
};

MQ2MacroType::MQ2MacroType()
	: MQ2Type("macro")
{
	ScopedTypeMember(MacroMembers, Name);
	ScopedTypeMember(MacroMembers, RunTime);
	ScopedTypeMember(MacroMembers, Paused);
	ScopedTypeMember(MacroMembers, Return);
	ScopedTypeMember(MacroMembers, Params);
	ScopedTypeMember(MacroMembers, Param);
	ScopedTypeMember(MacroMembers, CurLine);
	ScopedTypeMember(MacroMembers, MemUse);
	ScopedTypeMember(MacroMembers, CurCommand);
	ScopedTypeMember(MacroMembers, StackSize);
	ScopedTypeMember(MacroMembers, IsTLO);
	ScopedTypeMember(MacroMembers, IsOuterVariable);
	ScopedTypeMember(MacroMembers, CurSub);

	ScopedTypeMethod(MacroMethods, Undeclared);
}

bool MQ2MacroType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!gMacroStack)
		return false;

	//------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2MacroType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<MacroMethods>(pMethod->ID))
		{
		case MacroMethods::Undeclared:
			if (gMacroBlock && !gUndeclaredVars.empty())
			{
				WriteChatf("----------- Undeclared Variables (bad) -----------");
				int count = 1;

				for (auto& [name, index] : gUndeclaredVars)
				{
					const MQMacroLine& ml = gMacroBlock->Line.at(index);

					WriteChatf("[%d] %s see: %d@%s: %s", count++, name.c_str(),
						ml.LineNumber, ml.SourceFile.c_str(), ml.Command.c_str());
				}
			}
			else
			{
				WriteChatf("No Undeclared Variables Found. (good)");
			}
			return true;

		default:
			return false;
		}
	}

	//------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2MacroType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<MacroMembers>(pMember->ID))
	{
	case MacroMembers::Name:
		Dest.Ptr = &gszMacroName[0];
		Dest.Type = pStringType;
		return true;

	case MacroMembers::RunTime:
		Dest.UInt64 = ((MQGetTickCount64() - gRunning) / 1000);
		Dest.Type = pInt64Type;
		return true;

	case MacroMembers::Paused:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (MQMacroBlockPtr pBlock = GetCurrentMacroBlock())
		{
			Dest.Set(pBlock->Paused);
		}
		return true;

	case MacroMembers::Return:
		Dest.Ptr = &DataTypeTemp[0];
		strcpy_s(DataTypeTemp, gMacroStack->Return.c_str());
		Dest.Type = pStringType;
		return true;

	case MacroMembers::IsTLO:
		Dest.Type = pBoolType;
		Dest.Set(FindMQ2Data(Index) != nullptr);
		return true;

	case MacroMembers::IsOuterVariable:
		Dest.Type = pBoolType;
		Dest.Set(VariableMap.find(Index) != VariableMap.end());
		return true;

	case MacroMembers::StackSize: {
		Dest.DWord = 0;
		Dest.Type = pIntType;
		MQMacroStack* pStack = gMacroStack;
		while (pStack)
		{
			Dest.DWord++;
			pStack = pStack->pNext;
		}
		return true;
	}

	case MacroMembers::Params:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		{
			MQDataVar* pVar = gMacroStack->Parameters;
			while (pVar)
			{
				Dest.DWord++;
				pVar = pVar->pNext;
			}
		}
		return true;

	case MacroMembers::CurLine:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (gMacroBlock)
		{
			Dest.DWord = gMacroBlock->Line.at(gMacroBlock->CurrIndex).LineNumber;
			return true;
		}
		break;

	case MacroMembers::CurSub:
		if (gMacroBlock && gMacroStack)
		{
			GetSubFromLine(gMacroStack->LocationIndex, DataTypeTemp, MAX_STRING);
			Dest.Ptr = DataTypeTemp;
			Dest.Type = pStringType;
			return true;
		}
		return false;

	case MacroMembers::CurCommand:
		Dest.Type = pStringType;
		if (gMacroBlock)
		{
			auto& line = gMacroBlock->Line.at(gMacroStack->LocationIndex);

			sprintf_s(DataTypeTemp, "%d@%s -> %s", line.LineNumber, line.SourceFile.c_str(), line.Command.c_str());
			std::replace(std::begin(DataTypeTemp), std::begin(DataTypeTemp) + strlen(DataTypeTemp), '$', '#');

			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		break;

	case MacroMembers::MemUse:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		{
			int size = 0;
			if (gMacroStack)
			{
				MQMacroStack* pStack = gMacroStack;
				while (pStack)
				{
					size += sizeof(pStack);
					pStack = pStack->pNext;
				}
			}

			if (gMacroBlock)
			{
				MQMacroBlockPtr pBlock = gMacroBlock;
				size += sizeof(pBlock);
			}

			if (gEventQueue)
			{
				MQEventQueue* pQueue = gEventQueue;
				while (pQueue)
				{
					size += sizeof(pQueue);
					pQueue = pQueue->pNext;
				}
			}

			Dest.DWord = size;
			return true;
		}

	default: break;
	}

	return false;
}

bool MQ2MacroType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (gRunning)
	{
		strcpy_s(Destination, MAX_STRING, gszMacroName);
		return true;
	}

	return false;
}

} // namespace mq::datatypes
