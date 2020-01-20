#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2MacroType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
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
		case Undeclared:
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
	case Name:
		Dest.Ptr = &gszMacroName[0];
		Dest.Type = pStringType;
		return true;

	case RunTime:
		Dest.UInt64 = ((MQGetTickCount64() - gRunning) / 1000);
		Dest.Type = pInt64Type;
		return true;

	case Paused:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (MQMacroBlockPtr pBlock = GetCurrentMacroBlock())
		{
			Dest.DWord = pBlock->Paused;
		}
		return true;

	case Return:
		Dest.Ptr = &DataTypeTemp[0];
		strcpy_s(DataTypeTemp, gMacroStack->Return.c_str());
		Dest.Type = pStringType;
		return true;

	case IsTLO:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (FindMQ2Data(Index))
			Dest.DWord = 1;
		return true;

	case IsOuterVariable:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VariableMap.find(Index) != VariableMap.end())
			Dest.DWord = 1;
		return true;

	case StackSize: {
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

	case Params:
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

	case CurLine:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (gMacroBlock)
		{
			Dest.DWord = gMacroBlock->Line.at(gMacroBlock->CurrIndex).LineNumber;
			return true;
		}
		break;

	case CurSub:
		if (gMacroBlock)
		{
			GetSubFromLine(gMacroBlock->Line.at(gMacroBlock->CurrIndex).LineNumber, DataTypeTemp, MAX_STRING);
			Dest.Ptr = DataTypeTemp;
			Dest.Type = pStringType;
			return true;
		}
		return false;

	case CurCommand:
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

	case MemUse:
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
