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

namespace mq {

//----------------------------------------------------------------------------
// Datatype Definitions

// MQ2ArrayType* pArrayType = nullptr;

#define DATATYPE(Class, Var, Inherits, PersistentClass)              \
	Class* Var = nullptr;
#include "DataTypeList.h"
#undef DATATYPE

//----------------------------------------------------------------------------
// DataType Initializations
void InitializeMQ2DataTypes()
{
	// pCharacterType = new MQ2CharacterType();
	// if (pSpawnType != nullptr) {
	//     pCharacterType->SetInheritance(pSpawnType);
	// }

#define DATATYPE(Class, Var, Inherits, PersistentClass)              \
	Var = new Class();                                               \
	if (Inherits != nullptr) {                                       \
		Var->SetInheritance(Inherits);                               \
	}
#include "DataTypeList.h"
#undef DATATYPE
}

//----------------------------------------------------------------------------
// DataType Shutdown
void ShutdownMQ2DataTypes()
{
	// delete pSpawnType;
#define DATATYPE(Class, Var, Inherits, PersistentClass)              \
	delete Var;
#include "DataTypeList.h"
#undef DATATYPE
}

//----------------------------------------------------------------------------
// MQ2Type

MQ2Type::MQ2Type(const char* newName)
{
	strcpy_s(TypeName, newName);
	m_owned = AddMQ2Type(*this);
}

MQ2Type::~MQ2Type()
{
	if (m_owned)
	{
		RemoveMQ2Type(*this);
	}
}

void MQ2Type::InitializeMembers(MQTypeMember* memberArray)
{
	for (int i = 0; memberArray[i].ID; i++)
	{
		AddMember(memberArray[i].ID, memberArray[i].Name);
	}
}

const char* MQ2Type::GetName() const
{
	if (TypeName)
		return &TypeName[0];

	return nullptr;
}

const char* MQ2Type::GetMemberName(int ID) const
{
	for (const auto& pMember : Members)
	{
		if (pMember && pMember->ID == ID)
		{
			return &pMember->Name[0];
		}
	}

	return nullptr;
}

bool MQ2Type::GetMemberID(const char* Name, int& result) const
{
	std::scoped_lock lock(m_mutex);

	auto iter = MemberMap.find(Name);
	if (iter == MemberMap.end())
		return false;

	int index = iter->second;
	result = Members[index]->ID;
	return true;
}

MQTypeMember* MQ2Type::FindMember(const char* Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MemberMap.find(Name);
	if (iter == MemberMap.end())
		return nullptr;

	int index = MemberMap[Name];
	return Members[index].get();
}

MQTypeMember* MQ2Type::FindMethod(const char* Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MethodMap.find(Name);
	if (iter == MethodMap.end())
		return nullptr;

	int index = iter->second;
	return Methods[index].get();
}

bool MQ2Type::AddMember(int id, const char* Name)
{
	std::scoped_lock lock(m_mutex);

	if (MemberMap.find(Name) != MemberMap.end())
		return false;

	// find an unused index from members.
	int index = -1;
	for (size_t i = 0; i < Members.size(); ++i)
	{
		if (Members[i] == nullptr)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		Members.emplace_back();
		index = Members.size() - 1;
	}

	auto pMember = std::make_unique<MQTypeMember>();
	pMember->Name = Name;
	pMember->ID = id;
	pMember->Type = 0;
	Members[index] = std::move(pMember);
	MemberMap[Name] = index;
	return true;
}

bool MQ2Type::RemoveMember(const char* Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MemberMap.find(Name);
	if (iter == MemberMap.end())
		return false;

	int index = iter->second;
	MemberMap.erase(iter);

	if (index < 0)
		return false;
	Members[index].reset();
	return true;
}

bool MQ2Type::AddMethod(int ID, const char* Name)
{
	std::scoped_lock lock(m_mutex);

	if (MethodMap.find(Name) != MethodMap.end())
		return false;

	// find an unused index from members.
	int index = -1;
	for (size_t i = 0; i < Methods.size(); ++i)
	{
		if (Methods[i] == nullptr)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		Methods.emplace_back();
		index = Methods.size() - 1;
	}

	auto pMethod = std::make_unique<MQTypeMember>();
	pMethod->Name = Name;
	pMethod->ID = ID;
	pMethod->Type = 1;
	Methods[index] = std::move(pMethod);
	MethodMap[Name] = index;
	return true;
}

bool MQ2Type::RemoveMethod(const char* Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MethodMap.find(Name);
	if (iter == MethodMap.end())
		return false;

	int index = iter->second;
	MethodMap.erase(iter);

	if (index < 0)
		return false;
	Methods[index].reset();
	return true;
}

//----------------------------------------------------------------------------
// MQ2TypeType

MQ2TypeType::MQ2TypeType() : MQ2Type("type")
{
	AddMember(xName, "Name");
	AddMember(xTypeMember, "Member");
}

bool MQ2TypeType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQ2Type* pType = static_cast<MQ2Type*>(VarPtr.Ptr);
	if (!pType)
		return false;

	MQTypeMember* pMember = MQ2TypeType::FindMember(Member);
	if (!pMember)
		return false;


	switch (static_cast<TypeMembers>(pMember->ID))
	{
	case xName:
		strcpy_s(DataTypeTemp, pType->GetName());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case xTypeMember:
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// name by number
			if (Dest.Ptr = (void*)pType->GetMemberName(GetIntFromString(Index, 0)))
			{
				Dest.Type = pStringType;
				return true;
			}
		}
		else
		{
			// number by name
			if (pType->GetMemberID(Index, (int&)Dest.DWord))
			{
				Dest.Type = pIntType;
				return true;
			}
		}

		return false;

	default: break;
	}

	return false;
}

bool MQ2TypeType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, ((MQ2Type*)VarPtr.Ptr)->GetName());
	return true;
}
bool MQ2TypeType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	VarPtr.Ptr = Source.Type;
	return true;
}

bool MQ2TypeType::FromString(MQVarPtr& VarPtr, char* Source)
{
	if (VarPtr.Ptr = FindMQ2DataType(Source))
		return true;

	return false;
}

//----------------------------------------------------------------------------
// MQ2PluginType

bool MQ2PluginType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQPlugin* pPlugin = reinterpret_cast<MQPlugin*>(VarPtr.Ptr);
	if (!pPlugin)
		return false;

	MQTypeMember* pMember = MQ2PluginType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<PluginMembers>(pMember->ID))
	{
	case Name:
		Dest.Ptr = pPlugin->szFilename;
		Dest.Type = pStringType;
		return true;

	case Version:
		Dest.Float = pPlugin->fpVersion;
		Dest.Type = pFloatType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2FloatType

bool MQ2FloatType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2FloatType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<FloatMembers>(pMember->ID))
	{
	case Deci:
		sprintf_s(DataTypeTemp, "%.1f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Centi:
		sprintf_s(DataTypeTemp, "%.2f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Milli:
		sprintf_s(DataTypeTemp, "%.3f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Int:
		Dest.Type = pIntType;
		Dest.Int = (int)(VarPtr.Float);
		return true;

	case Precision:
		Dest.Type = pStringType;
		if (IsNumber(Index))
		{
			sprintf_s(DataTypeTemp, "%.*f", GetIntFromString(Index, 3), VarPtr.Float);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Raw:
		Dest.Type = pIntType;
		Dest.DWord = VarPtr.DWord;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2DoubleType

bool MQ2DoubleType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2DoubleType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<DoubleMembers>(pMember->ID))
	{
	case Deci:
		sprintf_s(DataTypeTemp, "%.1f", VarPtr.Double);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Centi:
		sprintf_s(DataTypeTemp, "%.2f", VarPtr.Double);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Milli:
		sprintf_s(DataTypeTemp, "%.3f", VarPtr.Double);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Int:
		Dest.Type = pIntType;
		Dest.Int = (int)(VarPtr.Double);
		return true;

	case Precision:
		Dest.Type = pStringType;
		if (IsNumber(Index))
		{
			sprintf_s(DataTypeTemp, "%.*f", GetIntFromString(Index, 3), VarPtr.Double);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2IntType

bool MQ2IntType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2IntType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<IntMembers>(pMember->ID))
	{
	case Float:
		Dest.Float = (float)1.0f * (VarPtr.Int);
		Dest.Type = pFloatType;
		return true;

	case Double:
		Dest.Double = (double)1.0f * (VarPtr.Int);
		Dest.Type = pDoubleType;
		return true;

	case Hex:
		sprintf_s(DataTypeTemp, "0x%X", VarPtr.Int);
		Dest.Ptr = &DataTypeTemp[0],
			Dest.Type = pStringType;
		return true;

	case Reverse:
		Dest.Array[0] = VarPtr.Array[3];
		Dest.Array[1] = VarPtr.Array[2];
		Dest.Array[2] = VarPtr.Array[1];
		Dest.Array[3] = VarPtr.Array[0];
		Dest.Type = pIntType;
		return true;

	case LowPart:
		Dest.DWord = LOWORD(VarPtr.DWord);
		Dest.Type = pIntType;
		return true;

	case HighPart:
		Dest.DWord = HIWORD(VarPtr.DWord);
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2Int64Type

bool MQ2Int64Type::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2Int64Type::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<Int64Members>(pMember->ID))
	{
	case Float:
		Dest.Float = (float)1.0f * (VarPtr.Int64);
		Dest.Type = pFloatType;
		return true;

	case Double:
		Dest.Double = (double)1.0f * (VarPtr.Int64);
		Dest.Type = pDoubleType;
		return true;

	case Hex:
		sprintf_s(DataTypeTemp, "0x%llX", VarPtr.Int64);
		Dest.Ptr = &DataTypeTemp[0],
			Dest.Type = pStringType;
		return true;

	case Reverse:
		Dest.FullArray[0] = VarPtr.FullArray[7];
		Dest.FullArray[1] = VarPtr.FullArray[6];
		Dest.FullArray[2] = VarPtr.FullArray[5];
		Dest.FullArray[3] = VarPtr.FullArray[4];
		Dest.FullArray[4] = VarPtr.FullArray[3];
		Dest.FullArray[5] = VarPtr.FullArray[2];
		Dest.FullArray[6] = VarPtr.FullArray[1];
		Dest.FullArray[7] = VarPtr.FullArray[0];
		Dest.Type = pInt64Type;
		return true;

	case LowPart:
		Dest.DWord = LODWORD(VarPtr.UInt64);
		Dest.Type = pIntType;
		return true;

	case HighPart:
		Dest.DWord = HIDWORD(VarPtr.UInt64);
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2StringType

bool MQ2StringType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	const char* szString = static_cast<const char*>(VarPtr.Ptr);
	if (!szString)
		return false;

	MQTypeMember* pMember = MQ2StringType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<StringMembers>(pMember->ID))
	{
	case Length:
		Dest.DWord = strlen(szString);
		Dest.Type = pIntType;
		return true;

	case Left:
		Dest.Type = pStringType;

		if (!Index[0])
			return false;

		{
			size_t StrLen = strlen(szString);

			int Len = GetIntFromString(Index, 0);
			if (Len == 0)
				return false;

			if (Len > MAX_STRING - 1)
				Len = MAX_STRING - 1;

			if (Len > 0)
			{
				if (static_cast<size_t>(Len) > StrLen)
					Len = StrLen;

				memmove(DataTypeTemp, szString, Len);

				DataTypeTemp[Len] = 0;
				Dest.Ptr = &DataTypeTemp[0];
			}
			else
			{
				Len = -Len;

				if (static_cast<size_t>(Len) > StrLen)
				{
					strcpy_s(DataTypeTemp, "");
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}

				memmove(DataTypeTemp, szString, StrLen - Len);
				DataTypeTemp[StrLen - Len] = 0;
				Dest.Ptr = &DataTypeTemp[0];
			}
		}
		return true;

	case Right:
		Dest.Type = pStringType;

		if (!Index[0])
			return false;

		{
			size_t StrLen = strlen(szString);
			const char* pStart = szString;

			int Len = GetIntFromString(Index, 0);

			if (Len == 0)
				return false;

			if (Len < 0)
			{
				Len = -Len;

				if (static_cast<size_t>(Len) >= StrLen)
				{
					strcpy_s(DataTypeTemp, "");
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}

				pStart = &pStart[Len];
				Len = StrLen - Len;

				memmove(DataTypeTemp, pStart, Len + 1);
				Dest.Ptr = &DataTypeTemp[0];
			}
			else
			{
				pStart = &pStart[strlen(pStart) - Len];

				if (pStart < szString)
					pStart = szString;

				memmove(DataTypeTemp, pStart, Len + 1);
				Dest.Ptr = &DataTypeTemp[0];
			}
		}
		return true;

	case Find:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		{
			int pos = ci_find_substr(szString, Index);
			if (pos)
			{
				Dest.DWord = pos;
				return true;
			}

			return false;
		}
		return false;

	case Replace: {
		Dest.Type = pStringType;

		if (!Index[0])
			return false;

		if (char* pComma = strchr(Index, ','))
		{
			// TODO: This could be optimized to reduce copies and side effects
			std::string subject = szString;

			*pComma = 0;
			const std::string search = (char*)Index;
			*pComma = ',';

			const std::string replace = (char*)&pComma[1];

			if (subject.empty() || search.empty())
				return false;

			size_t pos = 0;

			while ((pos = subject.find(search, pos)) != std::string::npos)
			{
				subject.replace(pos, search.length(), replace);
				pos += replace.length();
			}

			strcpy_s(DataTypeTemp, subject.c_str());

			if (Dest.Ptr = DataTypeTemp)
			{
				return true;
			}
		}

		return false;
	}

	case Upper:
		strcpy_s(DataTypeTemp, szString);
		_strupr_s(DataTypeTemp);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Lower:
		strcpy_s(DataTypeTemp, szString);
		_strlwr_s(DataTypeTemp);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Compare:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (Index[0])
		{
			Dest.Int = _stricmp(szString, Index);
			return true;
		}
		return false;

	case CompareCS:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (Index[0])
		{
			Dest.Int = strcmp(szString, Index);
			return true;
		}
		return false;

	case Mid:
		Dest.Type = pStringType;
		if (char* pComma = strchr(Index, ','))
		{
			*pComma = 0;
			pComma++;

			const char* pStr = szString;
			int nStart = GetIntFromString(Index, 0) - 1;
			if (nStart < 0)
			{
				nStart = 0;
			}

			int StrLen = strlen(pStr);
			int Len = GetIntFromString(pComma, StrLen);

			if (nStart >= StrLen)
			{
				strcpy_s(DataTypeTemp, "");
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}

			pStr += nStart;

			if (Len > StrLen || Len < 0)
			{
				Len = StrLen;
			}

			memmove(DataTypeTemp, pStr, Len);
			DataTypeTemp[Len] = '\0';
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Equal:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (Index[0])
		{
			Dest.DWord = _stricmp(szString, Index) == 0;
			return true;
		}
		return false;

	case NotEqual:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (Index[0])
		{
			Dest.DWord = _stricmp(szString, Index) != 0;
			return true;
		}
		return false;

	case EqualCS:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (Index[0])
		{
			Dest.DWord = strcmp(szString, Index) == 0;
			return true;
		}
		return false;

	case NotEqualCS:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (Index[0])
		{
			Dest.DWord = strcmp(szString, Index) != 0;
			return true;
		}
		return false;

	case Count:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (Index[0])
		{
			Dest.DWord = 0;
			const char* pLast = szString - 1;

			while (pLast = strchr(&pLast[1], Index[0]))
				Dest.DWord++;

			return true;
		}
		return false;

	case Arg:
		Dest.Type = pStringType;

		if (IsNumberToComma(Index))
		{
			char Temp[MAX_STRING] = { 0 };
			strcpy_s(Temp, szString);

			if (char* pComma = strchr(Index, ','))
			{
				*pComma = 0;
				GetArg(DataTypeTemp, Temp, GetIntFromString(Index, 0), false, false, false, pComma[1]);
				*pComma = ',';

				if (DataTypeTemp[0])
				{
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
			else
			{
				GetArg(DataTypeTemp, Temp, GetIntFromString(Index, 0));

				if (DataTypeTemp[0])
				{
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		return false;

	case Token:
		Dest.Type = pStringType;
		if (IsNumberToComma(Index))
		{
			size_t index = GetIntFromString(Index, 0);
			if (!index)
				return false;

			if (char* pComma = strchr(Index, ','))
			{
				const char* pPos = szString;
				*pComma = 0;
				index--;

				while (index && pPos)
				{
					pPos = strchr(&pPos[1], pComma[1]);
					index--;
				}

				*pComma = ',';

				if (pPos)
				{
					if (pPos != (char*)VarPtr.Ptr)
						pPos++;

					const char* pEnd = strchr(&pPos[0], pComma[1]);

					if (pEnd)
					{
						if (pEnd != pPos)
						{
							strncpy_s(DataTypeTemp, pPos, pEnd - pPos);
							DataTypeTemp[pEnd - pPos] = 0;
						}
						else
							DataTypeTemp[0] = 0;
					}
					else
						strcpy_s(DataTypeTemp, pPos);

					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		return false;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2ArrayType

bool MQ2ArrayType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CDataArray* pArray = static_cast<CDataArray*>(VarPtr.Ptr);
	if (!pArray)
		return false;

	MQTypeMember* pMember = MQ2ArrayType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ArrayMembers>(pMember->ID))
	{
	case Dimensions:
		Dest.DWord = pArray->GetNumExtents();
		Dest.Type = pIntType;
		return true;

	case Size:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index < 0)
				return false;
			if (index < pArray->GetNumExtents())
			{
				Dest.DWord = pArray->GetExtents(index);
				return true;
			}
		}
		else
		{
			Dest.DWord = pArray->GetTotalElements();
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2MathType

bool MQ2MathType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2MathType::FindMember(Member);
	if (!pMember)
		return false;

	if (!Index[0])
		return false;

	double CalcResult = 0;

	switch (static_cast<MathMembers>(pMember->ID))
	{
	case Abs:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)CalcResult;
			if (Dest.Float < 0)
				Dest.Float *= -1;
			return true;
		}
		return false;

	case Rand:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (char* Arg = Index)
		{
			char szMin[MAX_STRING] = { 0 };
			char szMax[MAX_STRING] = { 0 };
			int Min = 0;
			int Max = 0;

			if (char* pDest = strchr(Arg, ','))
			{
				pDest[0] = '\0';
				Min = GetIntFromString(Arg, Min);
				pDest++;
				Max = GetIntFromString(pDest, Max);
			}
			else
			{
				Max = GetIntFromString(Arg, Max);
			}

			if (Max == 0 || Max > RAND_MAX)
				return false;

			Dest.DWord = RangeRandom(Min, Max);
			return true;
		}
		return false;

	case Sqrt:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)sqrt(CalcResult);
			return true;
		}
		return false;

	case Calc:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)CalcResult;
			return true;
		}
		return false;

	case Sin:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)sin(CalcResult / DegToRad);
			return true;
		}
		return false;

	case Cos:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)cos(CalcResult / DegToRad);
			return true;
		}
		return false;

	case Tan:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)tan(CalcResult / DegToRad);
			return true;
		}
		return false;

	case Asin:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)(asin(CalcResult) * DegToRad);
			return true;
		}
		return false;

	case Acos:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)(acos(CalcResult) * DegToRad);
			return true;
		}
		return false;

	case Atan:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)(atan(CalcResult) * DegToRad);
			return true;
		}
		return false;

	case Not:
		Dest.DWord = ~GetIntFromString(Index, 0);
		Dest.Type = pIntType;
		return true;

	case Hex:
		sprintf_s(DataTypeTemp, "0x%X", GetIntFromString(Index, 0));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Dec:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (sscanf_s(Index, "%x", &Dest.DWord)) {
			return true;
		}
		return false;

	case Clamp:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (char* Arg = Index)
		{
			// TODO:  Should probably add some error checking here to make sure good data went in
			char szN[MAX_STRING] = { 0 };
			GetArg(szN, Arg, 1, false, false, true);
			int n = GetIntFromString(szN, 0);

			char szMin[MAX_STRING] = { 0 };
			GetArg(szMin, Arg, 2, false, false, true);
			int Min = GetIntFromString(szMin, 0);

			char szMax[MAX_STRING] = { 0 };
			GetArg(szMax, Arg, 3, false, false, true);
			int Max = GetIntFromString(szMax, 0);

			Dest.Int = std::max(Min, std::min(n, Max));
			return true;
		}
		return false;

	case Distance:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		// TODO: This code appears in LineOfSight function, possibly clean and combine
		if (Index[0])
		{
			float P1[3];
			float P2[3];
			P1[0] = P2[0] = ((SPAWNINFO*)pCharSpawn)->Y;
			P1[1] = P2[1] = ((SPAWNINFO*)pCharSpawn)->X;
			P1[2] = P2[2] = ((SPAWNINFO*)pCharSpawn)->Z;

			if (char* pColon = strchr(Index, ':'))
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
				{
					P2[0] = GetFloatFromString(&pColon[1], P2[0]);
				}
			}

			if (char* pComma = strchr(Index, ','))
			{
				*pComma = 0;
				P1[0] = GetFloatFromString(Index, P1[0]);
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
			{
				P1[0] = GetFloatFromString(Index, P1[0]);
			}

			Dest.Float = (float)GetDistance3D(P1[0], P1[1], P1[2], P2[0], P2[1], P2[2]);
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2MacroType

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
					const MQMacroLine& ml = gMacroBlock->Line[index];

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
			Dest.DWord = gMacroBlock->Line[gMacroBlock->CurrIndex].LineNumber;
			return true;
		}
		break;

	case CurSub:
		if (gMacroBlock)
		{
			GetSubFromLine(gMacroBlock->Line[gMacroBlock->CurrIndex].LineNumber, DataTypeTemp, MAX_STRING);
			Dest.Ptr = DataTypeTemp;
			Dest.Type = pStringType;
			return true;
		}
		return false;

	case CurCommand:
		Dest.Type = pStringType;
		if (gMacroBlock)
		{
			auto& line = gMacroBlock->Line[gMacroStack->LocationIndex];

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

//----------------------------------------------------------------------------
// MQ2TicksType

bool MQ2TicksType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	uint32_t nTicks = VarPtr.DWord;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TicksMembers>(pMember->ID))
	{
	case Hours:
		Dest.DWord = nTicks / 600;
		Dest.Type = pIntType;
		return true;

	case Minutes:
		Dest.DWord = (nTicks / 10) % 60;
		Dest.Type = pIntType;
		return true;

	case Seconds:
		Dest.DWord = (nTicks * 6) % 60;
		Dest.Type = pIntType;
		return true;

	case TimeHMS: {
		Dest.Type = pStringType;
		int Secs = nTicks * 6;
		int Mins = (Secs / 60) % 60;
		int Hrs = (Secs / 3600);
		Secs = Secs % 60;
		if (Secs < 0)
			sprintf_s(DataTypeTemp, "Perm");
		else if (Hrs)
			sprintf_s(DataTypeTemp, "%d:%02d:%02d", Hrs, Mins, Secs);
		else
			sprintf_s(DataTypeTemp, "%d:%02d", Mins, Secs);
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case Time: {
		Dest.Type = pStringType;
		int Secs = nTicks * 6;
		int Mins = (Secs / 60);
		Secs = Secs % 60;
		if (Secs < 0)
			sprintf_s(DataTypeTemp, "Perm");
		else
			sprintf_s(DataTypeTemp, "%d:%02d", Mins, Secs);
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case TotalMinutes:
		Dest.DWord = nTicks / 10;
		Dest.Type = pIntType;
		return true;

	case TotalSeconds:
		Dest.DWord = nTicks * 6;
		Dest.Type = pIntType;
		return true;

	case Ticks:
		Dest.DWord = nTicks;
		Dest.Type = pIntType;
		return true;
	}

	return false;
}

bool MQ2TimeStampType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	uint64_t nTimeStamp = VarPtr.UInt64;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TimeStampMembers>(pMember->ID))
	{
	case Hours:
		Dest.UInt64 = (nTimeStamp / 1000) / 3600;
		Dest.Type = pInt64Type;
		return true;

	case Minutes:
		Dest.UInt64 = ((nTimeStamp / 1000) / 60) % 60;
		Dest.Type = pInt64Type;
		return true;

	case Seconds:
		Dest.UInt64 = (nTimeStamp / 1000) % 60;
		Dest.Type = pInt64Type;
		return true;

	case TimeHMS: {
		Dest.Type = pStringType;
		uint64_t Secs = nTimeStamp / 1000;
		uint64_t Mins = (Secs / 60) % 60;
		uint64_t Hrs = (Secs / 3600);

		Secs = Secs % 60;
		if (Secs < 0)
			sprintf_s(DataTypeTemp, "Perm");
		else if (Hrs)
			sprintf_s(DataTypeTemp, "%d:%02u:%02u", (unsigned int)Hrs, (unsigned int)Mins, (unsigned int)Secs);
		else
			sprintf_s(DataTypeTemp, "%d:%02u", (unsigned int)Mins, (unsigned int)Secs);
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case Time: {
		Dest.Type = pStringType;
		uint64_t Secs = nTimeStamp / 1000;
		uint64_t Mins = Secs / 60;
		Secs = Secs % 60;
		if (Secs < 0)
			sprintf_s(DataTypeTemp, "Perm");
		else
			sprintf_s(DataTypeTemp, "%d:%02u", (unsigned int)Mins, (unsigned int)Secs);
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case TotalMinutes:
		Dest.UInt64 = (nTimeStamp / 1000) / 60;
		Dest.Type = pInt64Type;
		return true;

	case TotalSeconds:
		Dest.UInt64 = nTimeStamp / 1000;
		Dest.Type = pInt64Type;
		return true;

	case Raw:
		Dest.UInt64 = nTimeStamp;
		Dest.Type = pInt64Type;
		return true;

	case Float:
		Dest.Float = (float)nTimeStamp / 1000;
		Dest.Type = pFloatType;
		return true;

	case Ticks:
		Dest.UInt64 = ((nTimeStamp / 1000) + 5) / 6;
		Dest.Type = pInt64Type;
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2ArgbType

bool MQ2ArgbType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ArgbMembers>(pMember->ID))
	{
	case A:
		Dest.DWord = VarPtr.Argb.A;
		Dest.Type = pIntType;
		return true;

	case R:
		Dest.DWord = VarPtr.Argb.R;
		Dest.Type = pIntType;
		return true;

	case G:
		Dest.DWord = VarPtr.Argb.G;
		Dest.Type = pIntType;
		return true;

	case B:
		Dest.DWord = VarPtr.Argb.B;
		Dest.Type = pIntType;
		return true;

	case Int:
		Dest.DWord = VarPtr.DWord;
		Dest.Type = pIntType;
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2SpawnType

bool MQ2SpawnType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!VarPtr.Ptr)
		return false;

	SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
	SPAWNINFO* pMySpawn = reinterpret_cast<SPAWNINFO*>(pLocalPlayer);
	SPAWNINFO* pControlledSpawn = reinterpret_cast<SPAWNINFO*>(pCharSpawn);
	PlayerClient* pPlayerClient = reinterpret_cast<PlayerClient*>(pSpawn);

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2SpawnType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<SpawnMethods>(pMethod->ID))
		{
		case DoTarget:
			pTarget = pPlayerClient;
			return true;

		case DoFace: {
			char szOut[256] = { 0 };
			sprintf_s(szOut, "id %d", pSpawn->SpawnID);
			Face(pMySpawn, szOut);
			return true;
		}

		case LeftClick:
			pEverQuest->LeftClickedOnPlayer(pPlayerClient);
			WeDidStuff();
			return true;

		case RightClick:
			pEverQuest->RightClickedOnPlayer(pPlayerClient, 0);
			WeDidStuff();
			return true;

		case DoAssist: {
			char szOut[256] = { 0 };
			sprintf_s(szOut, "%s", pSpawn->DisplayedName);
			AssistCmd(pMySpawn, szOut);
			return true;
		}

		default: return false;
		}
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2SpawnType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<SpawnMembers>(pMember->ID))
	{
	case Address:
		// This is for debugging purposes/correcting struct on patchday
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case Level:
		Dest.DWord = pSpawn->Level;
		Dest.Type = pIntType;
		return true;

	case ID:
		Dest.Type = pIntType;
		Dest.DWord = pSpawn->SpawnID;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, pSpawn->Name);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Surname:
		strcpy_s(DataTypeTemp, pSpawn->Lastname);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case CleanName:
		strcpy_s(DataTypeTemp, pSpawn->Name);
		CleanupName(DataTypeTemp, sizeof(DataTypeTemp), false, false);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case DisplayName:
		strcpy_s(DataTypeTemp, pSpawn->DisplayedName);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case E:
		Dest.Type = pFloatType;
		Dest.Float = -pSpawn->X;
		return true;

	case W:
	case X:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->X;
		return true;

	case S:
		Dest.Type = pFloatType;
		Dest.Float = -pSpawn->Y;
		return true;

	case N:
	case Y:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->Y;
		return true;

	case D:
		Dest.Type = pFloatType;
		Dest.Float = -pSpawn->Z;
		return true;

	case U:
	case Z:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->Z;
		return true;

	case FloorZ:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->FloorHeight;
		return true;

	case Next:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->pNext)
		{
			return true;
		}
		return false;

	case Prev:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->pPrev)
		{
			return true;
		}
		return false;

	case CurrentHPs:
		Dest.Type = pInt64Type;
		Dest.Int64 = pSpawn->HPCurrent;
		return true;

	case MaxHPs:
		Dest.Type = pInt64Type;
		Dest.Int64 = pSpawn->HPMax;
		return true;

	case PctHPs:
		// avoid dividing by zero!
		Dest.Int64 = pSpawn->HPMax == 0 ? 0 : pSpawn->HPCurrent / pSpawn->HPMax * 100;
		Dest.Type = pInt64Type;
		return true;

	case AARank:
		Dest.Type = pIntType;
		Dest.Int = 0;
		if (pSpawn->AARank != 0xFF)
			Dest.Int = pSpawn->AARank;
		return true;

	case Speed:
		Dest.Float = FindSpeed(pSpawn);
		Dest.Type = pFloatType;
		return true;

	case Heading:
		Dest.Float = pSpawn->Heading * 0.703125f; // Convert from EQ heading to degrees (180 / 250)
		Dest.Type = pHeadingType;
		return true;

	case Pet:
		Dest.Type = pPetType;
		Dest.Ptr = GetSpawnByID(pSpawn->PetID);
		if (!Dest.Ptr)
		{
			// FIXME: Do not ZeroMemory a SPAWNINFO
			ZeroMemory(&PetSpawn, sizeof(PetSpawn));
			strcpy_s(PetSpawn.Name, "NO PET");
			Dest.Ptr = &PetSpawn;
		}
		return true;

	case Master:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = GetSpawnByID(pSpawn->MasterID))
		{
			return true;
		}
		return false;

	case Gender:
		strcpy_s(DataTypeTemp, szGender[pSpawn->mActorClient.Gender]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Race:
		Dest.DWord = pSpawn->mActorClient.Race;
		Dest.Type = pRaceType;
		return true;

	case Class:
		Dest.DWord = 0;
		Dest.Type = pClassType;

		if (GetSpawnType(pSpawn) != AURA && GetSpawnType(pSpawn) != BANNER && GetSpawnType(pSpawn) != CAMPFIRE)
		{
			Dest.DWord = pSpawn->mActorClient.Class;
		}
		else
		{
			if (GetSpawnType(pSpawn) == AURA)
				Dest.DWord = 0xFF;
			else if (GetSpawnType(pSpawn) == BANNER)
				Dest.DWord = 0xFE;
			else
				Dest.DWord = 0xFD;
		}
		return true;

	case Body:
		Dest.DWord = GetBodyType(pSpawn);
		Dest.Type = pBodyType;
		return true;

	case GM:
		Dest.DWord = pSpawn->GM;
		Dest.Type = pBoolType;
		return true;

	case Levitating:
		Dest.DWord = (pSpawn->mPlayerPhysicsClient.Levitate == 2);
		Dest.Type = pBoolType;
		return true;

	case Sneaking:
		Dest.DWord = pSpawn->Sneak;
		Dest.Type = pBoolType;
		return true;

	case Invis:
		Dest.DWord = pSpawn->HideMode;
		Dest.Type = pBoolType;
		return true;

	case Height:
		Dest.Float = pSpawn->AvatarHeight;
		Dest.Type = pFloatType;
		return true;

	case MaxRange:
		Dest.Float = 0;
		Dest.Type = pFloatType;
		if (GetSpawnType(pSpawn) != ITEM)
		{
			Dest.Float = get_melee_range((PlayerClient*)pSpawn, (PlayerClient*)pSpawn);
			return true;
		}
		return false;

	case MaxRangeTo:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (GetSpawnType(pSpawn) != ITEM)
		{
			Dest.Float = get_melee_range(pCharSpawn, (PlayerClient*)pSpawn);
			return true;
		}
		return false;

	case Guild:
		Dest.Type = pStringType;
		if (pSpawn->GuildID != -1 && pSpawn->GuildID != 0)
		{
			const char* szGuild = GetGuildByID(pSpawn->GuildID);
			if (szGuild)
			{
				strcpy_s(DataTypeTemp, szGuild);
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;

	case Type:
		DataTypeTemp[0] = 0;
		Dest.Type = pStringType;

		switch (GetSpawnType(pSpawn))
		{
		case MOUNT:
			strcpy_s(DataTypeTemp, "Mount");
			break;
		case UNTARGETABLE:
			strcpy_s(DataTypeTemp, "Untargetable");
			break;
		case NPC:
			strcpy_s(DataTypeTemp, "NPC");
			break;
		case PC:
			strcpy_s(DataTypeTemp, "PC");
			break;
		case CHEST:
			strcpy_s(DataTypeTemp, "Chest");
			break;
		case TRAP:
			strcpy_s(DataTypeTemp, "Trap");
			break;
		case TRIGGER:
			strcpy_s(DataTypeTemp, "Trigger");
			break;
		case TIMER:
			strcpy_s(DataTypeTemp, "Timer");
			break;
		case PET:
			strcpy_s(DataTypeTemp, "Pet");
			break;
		case ITEM:
			strcpy_s(DataTypeTemp, "Item");
			break;
		case CORPSE:
			strcpy_s(DataTypeTemp, "Corpse");
			break;
		case AURA:
			strcpy_s(DataTypeTemp, "Aura");
			break;
		case OBJECT:
			strcpy_s(DataTypeTemp, "Object");
			break;
		case BANNER:
			strcpy_s(DataTypeTemp, "Banner");
			break;
		case CAMPFIRE:
			strcpy_s(DataTypeTemp, "Campfire");
			break;
		case MERCENARY:
			strcpy_s(DataTypeTemp, "Mercenary");
			break;
		case FLYER:
			strcpy_s(DataTypeTemp, "Flyer");
			break;
		}

		if (DataTypeTemp[0] != 0)
		{
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Light:
		strcpy_s(DataTypeTemp, GetLightForSpawn(pSpawn));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case StandState:
		Dest.Int = pSpawn->StandState;
		Dest.Type = pIntType;
		return true;

	case State:
		DataTypeTemp[0] = '\0';
		Dest.Type = pStringType;

		if (pSpawn->PlayerState & 0x20)
		{
			strcpy_s(DataTypeTemp, "STUN");
		}
		else if (pSpawn == (SPAWNINFO*)pLocalPlayer && pSpawn->RespawnTimer)
		{
			strcpy_s(DataTypeTemp, "HOVER");
		}
		else if (pSpawn->Mount)
		{
			strcpy_s(DataTypeTemp, "MOUNT");
		}
		else
		{
			switch (pSpawn->StandState)
			{
			case STANDSTATE_STAND:
				strcpy_s(DataTypeTemp, "STAND");
				break;
			case STANDSTATE_SIT:
				strcpy_s(DataTypeTemp, "SIT");
				break;
			case STANDSTATE_DUCK:
				strcpy_s(DataTypeTemp, "DUCK");
				break;
			case STANDSTATE_BIND:
				strcpy_s(DataTypeTemp, "BIND");
				break;
			case STANDSTATE_FEIGN:
				strcpy_s(DataTypeTemp, "FEIGN");
				break;
			case STANDSTATE_DEAD:
				strcpy_s(DataTypeTemp, "DEAD");
				break;
			default:
				strcpy_s(DataTypeTemp, "UNKNOWN");
				break;
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Standing:
		Dest.DWord = pSpawn->StandState == STANDSTATE_STAND;
		Dest.Type = pBoolType;
		return true;

	case Sitting:
		Dest.DWord = pSpawn->StandState == STANDSTATE_SIT;
		Dest.Type = pBoolType;
		return true;

	case TimeBeenDead:
		Dest.DWord = EQGetTime() - pSpawn->RespawnTimer;
		Dest.Type = pTimeStampType;
		return true;

	case IsSummoned: // if its a summoned being (pet for example)
		Dest.DWord = pSpawn->bSummoned;
		Dest.Type = pBoolType;
		return true;

	case TargetOfTarget:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = GetSpawnByID(pSpawn->TargetOfTarget))
		{
			return true;
		}
		return false;

	case Ducking:
		Dest.DWord = pSpawn->StandState == STANDSTATE_DUCK;
		Dest.Type = pBoolType;
		return true;

	case Feigning:
		Dest.DWord = pSpawn->StandState == STANDSTATE_FEIGN;
		Dest.Type = pBoolType;
		return true;

	case Binding:
		Dest.DWord = pSpawn->StandState == STANDSTATE_BIND;
		Dest.Type = pBoolType;
		return true;

	case Dead:
		Dest.DWord = pSpawn->StandState == STANDSTATE_DEAD;
		Dest.Type = pBoolType;
		return true;

	case Stunned:
		Dest.DWord = false;
		if (pSpawn->PlayerState & 0x20)
			Dest.DWord = true;
		Dest.Type = pBoolType;
		return true;

	case Aggressive:
		Dest.DWord = false;
		if (pSpawn->PlayerState & 0x4 || pSpawn->PlayerState & 0x8)
			Dest.DWord = true;
		Dest.Type = pBoolType;
		return true;

	case Hovering:
		Dest.DWord = (pSpawn->RespawnTimer);
		Dest.Type = pBoolType;
		return true;

	case Deity:
		Dest.DWord = pSpawn->Deity;
		Dest.Type = pDeityType;
		return true;

	case Distance:
		Dest.Float = GetDistance(pSpawn->X, pSpawn->Y);
		Dest.Type = pFloatType;
		return true;

	case Distance3D:
		Dest.Float = DistanceToSpawn3D(pControlledSpawn, pSpawn);
		Dest.Type = pFloatType;
		return true;

	case DistancePredict:
		Dest.Float = EstimatedDistanceToSpawn(pControlledSpawn, pSpawn);
		Dest.Type = pFloatType;
		return true;

	case DistanceW:
	case DistanceX:
		Dest.Float = (float)fabs(pControlledSpawn->X - pSpawn->X);
		Dest.Type = pFloatType;
		return true;

	case DistanceN:
	case DistanceY:
		Dest.Float = (float)fabs(pControlledSpawn->Y - pSpawn->Y);
		Dest.Type = pFloatType;
		return true;

	case DistanceU:
	case DistanceZ:
		Dest.Float = (float)fabs(pControlledSpawn->Z - pSpawn->Z);
		Dest.Type = pFloatType;
		return true;

	case HeadingTo:
		Dest.Float = (float)(atan2f(pControlledSpawn->Y - pSpawn->Y, pSpawn->X - pControlledSpawn->X) * 180.0f / PI + 90.0f);
		if (Dest.Float < 0.0f)
			Dest.Float += 360.0f;
		else if (Dest.Float >= 360.0f)
			Dest.Float -= 360.0f;
		Dest.Type = pHeadingType;
		return true;

	case Casting:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(pSpawn->CastingData.SpellID))
		{
			return true;
		}
		return false;

	case Mount:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->Mount)
		{
			return true;
		}
		return false;

	case Underwater:
		Dest.DWord = (pSpawn->UnderWater == 5);
		Dest.Type = pBoolType;
		return true;

	case FeetWet:
		Dest.DWord = (pSpawn->FeetWet == 5);
		Dest.Type = pBoolType;
		return true;

	case PlayerState:
		Dest.DWord = pSpawn->PlayerState;
		Dest.Type = pIntType;
		return true;

	case Stuck:
		Dest.DWord = pSpawn->PossiblyStuck;
		Dest.Type = pBoolType;
		return true;

	case Animation:
		Dest.DWord = pSpawn->Animation;
		Dest.Type = pIntType;
		return true;

	case Holding:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (pSpawn->LeftHolding || pSpawn->RightHolding)
		{
			Dest.DWord = true;
		}
		return true;

	case Look:
		Dest.Float = pSpawn->CameraAngle;
		Dest.Type = pFloatType;
		return true;

	case xConColor:
		Dest.Type = pStringType;

		switch (ConColor(pSpawn))
		{
		case CONCOLOR_GREY:
			strcpy_s(DataTypeTemp, "GREY");
			break;
		case CONCOLOR_GREEN:
			strcpy_s(DataTypeTemp, "GREEN");
			break;
		case CONCOLOR_LIGHTBLUE:
			strcpy_s(DataTypeTemp, "LIGHT BLUE");
			break;
		case CONCOLOR_BLUE:
			strcpy_s(DataTypeTemp, "BLUE");
			break;
		case CONCOLOR_WHITE:
			strcpy_s(DataTypeTemp, "WHITE");
			break;
		case CONCOLOR_YELLOW:
			strcpy_s(DataTypeTemp, "YELLOW");
			break;
		case CONCOLOR_RED:

		default:
			strcpy_s(DataTypeTemp, "RED");
			break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Invited:
		Dest.DWord = (pSpawn->InvitedToGroup);
		Dest.Type = pBoolType;
		return true;

	case Inviter:
		strcpy_s(DataTypeTemp, (char*)__Inviter);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case NearestSpawn:
		Dest.Type = pSpawnType;
		if (pSpawn == pControlledSpawn)
		{
			return (dataNearestSpawn(Index, Dest) != 0); // use top-level object if it's you
		}

		if (Index[0])
		{
			MQSpawnSearch ssSpawn;
			ClearSearchSpawn(&ssSpawn);
			ssSpawn.FRadius = 999999.0f;

			size_t nth = 0;

			if (char* pSearch = strchr(Index, ','))
			{
				*pSearch = 0;
				++pSearch;
				ParseSearchSpawn(pSearch, &ssSpawn);

				nth = GetIntFromString(Index, nth);
			}
			else
			{
				if (IsNumber(Index))
				{
					nth = GetIntFromString(Index, nth);
				}
				else
				{
					nth = 1;
					ParseSearchSpawn(Index, &ssSpawn);
				}
			}

			if (Dest.Ptr = NthNearestSpawn(&ssSpawn, nth, pSpawn))
			{
				return true;
			}
		}
		return false;

	case Trader:
		Dest.DWord = pSpawn->Trader;
		Dest.Type = pBoolType;
		return true;

	case AFK:
		Dest.DWord = pSpawn->AFK;
		Dest.Type = pBoolType;
		return true;

	case LFG:
		Dest.DWord = pSpawn->LFG;
		Dest.Type = pBoolType;
		return true;

	case Linkdead:
		Dest.DWord = pSpawn->Linkdead;
		Dest.Type = pBoolType;
		return true;

	case AATitle:  // Leaving this in for older macros/etc.."Title" should be used instead.
	case Title:
		strcpy_s(DataTypeTemp, pSpawn->Title);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp;
		return true;

	case Suffix:
		strcpy_s(DataTypeTemp, pSpawn->Suffix);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case xGroupLeader:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (CHARINFO* pCharInfo = GetCharInfo())
		{
			if (pCharInfo->pGroupInfo && pCharInfo->pGroupInfo->pLeader)
			{
				Dest.DWord = pSpawn->Type == SPAWN_PLAYER
					&& !_stricmp(pCharInfo->pGroupInfo->pLeader->Name.c_str(), pSpawn->Name);
				return true;
			}
		}
		return false;

	case Assist:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (gGameState == GAMESTATE_INGAME && GetCharInfo()->pSpawn && pSpawn)
		{
			if (DWORD AssistID = GetGroupMainAssistTargetID())
			{
				if (AssistID == pSpawn->SpawnID)
				{
					Dest.DWord = 1;
					return true;
				}
			}

			for (int nAssist = 0; nAssist < 3; nAssist++)
			{
				if (DWORD AssistID = GetRaidMainAssistTargetID(nAssist))
				{
					if (AssistID == pSpawn->SpawnID) {
						Dest.DWord = 1;
						return true;
					}
				}
			}
		}
		return true;

	case Mark:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (gGameState == GAMESTATE_INGAME && GetCharInfo()->pSpawn && pSpawn)
		{
			for (int nMark = 0; nMark < 3; nMark++)
			{
				if (GetCharInfo()->pSpawn->RaidMarkNPC[nMark] == pSpawn->SpawnID)
				{
					Dest.DWord = nMark + 1;
					return true;
				}
			}

			for (int nMark = 0; nMark < 3; nMark++)
			{
				if (GetCharInfo()->pSpawn->GroupMarkNPC[nMark] == pSpawn->SpawnID)
				{
					Dest.DWord = nMark + 1;
					return true;
				}
			}
		}
		return false;

	case Anonymous:
		Dest.DWord = (pSpawn->Anon == 1);
		Dest.Type = pBoolType;
		return true;

	case Roleplaying:
		Dest.DWord = (pSpawn->Anon == 2);
		Dest.Type = pBoolType;
		return true;

	case xLineOfSight:
		Dest.DWord = pCharSpawn->CanSee(*pPlayerClient);
		Dest.Type = pBoolType;
		return true;

	case HeadingToLoc:
		Dest.Float = 0.0;
		Dest.Type = pHeadingType;

		if (!Index[0])
			return false;

		if (char* pComma = strchr(Index, ','))
		{
			*pComma = 0;
			float Y = GetFloatFromString(Index, 0);

			*pComma = ',';
			float X = GetFloatFromString(&pComma[1], 0);

			Dest.Float = (float)(atan2f(pSpawn->Y - Y, X - pSpawn->X) * 180.0f / PI + 90.0f);

			if (Dest.Float < 0.0f)
				Dest.Float += 360.0f;
			else if (Dest.Float >= 360.0f)
				Dest.Float -= 360.0f;
			return true;
		}
		return false;

	case Fleeing:
		Dest.DWord = IsMobFleeing(GetCharInfo()->pSpawn, pSpawn);
		Dest.Type = pBoolType;
		return true;

	case Named:
		Dest.DWord = IsNamed(pSpawn);
		Dest.Type = pBoolType;
		return true;

	case Buyer:
		Dest.DWord = pSpawn->Buyer;
		Dest.Type = pBoolType;
		return true;

	case Moving:
		Dest.DWord = fabs(pSpawn->SpeedRun) > 0.0f;
		Dest.Type = pBoolType;
		return true;

	case CurrentMana:
		Dest.DWord = pSpawn->GetCurrentMana();
		Dest.Type = pIntType;
		return true;

	case MaxMana:
		Dest.DWord = pSpawn->GetMaxMana();
		Dest.Type = pIntType;
		return true;

	case PctMana:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (int maxmana = pSpawn->GetMaxMana())
			Dest.Int = pSpawn->GetCurrentMana() * 100 / maxmana;
		return true;

	case CurrentEndurance:
		Dest.DWord = pSpawn->GetCurrentEndurance();
		Dest.Type = pIntType;
		return true;

	case PctEndurance:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (int maxend = pSpawn->GetMaxEndurance())
			Dest.Int = pSpawn->GetCurrentEndurance() * 100 / maxend;
		return true;

	case MaxEndurance:
		Dest.DWord = pSpawn->GetMaxEndurance();
		Dest.Type = pIntType;
		return true;

	case Loc:
		sprintf_s(DataTypeTemp, "%.2f, %.2f", pSpawn->Y, pSpawn->X);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case LocYX:
		sprintf_s(DataTypeTemp, "%.0f, %.0f", pSpawn->Y, pSpawn->X);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case LocYXZ:
		sprintf_s(DataTypeTemp, "%.2f, %.2f, %.2f", pSpawn->Y, pSpawn->X, pSpawn->Z);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case EQLoc:
		sprintf_s(DataTypeTemp, "%.2f, %.2f, %.2f", pSpawn->X, pSpawn->Y, pSpawn->Z);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case MQLoc:
		sprintf_s(DataTypeTemp, "%.2f, %.2f, %.2f", pSpawn->Y, pSpawn->X, pSpawn->Z);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Owner:
		Dest.Type = pSpawnType;
		if (pSpawn->Mercenary)
		{
			size_t pos = strchr(pSpawn->Lastname, '\'') - &pSpawn->Lastname[0];
			strncpy_s(DataTypeTemp, pSpawn->Lastname, pos);

			DataTypeTemp[pos] = 0;

			if (SPAWNINFO* pOwner = (SPAWNINFO*)GetSpawnByName(DataTypeTemp))
			{
				Dest.Ptr = pOwner;
				return true;
			}
		}
		return false;

	case Following:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->WhoFollowing)
		{
			return true;
		}
		return false;

	case MercID:
		Dest.DWord = pSpawn->MercID;
		Dest.Type = pIntType;
		return true;

	case ContractorID:
		Dest.DWord = pSpawn->ContractorID;
		Dest.Type = pIntType;
		return true;

	case Primary:
		Dest.DWord = pSpawn->Equipment.Primary.ID;
		Dest.Type = pIntType;
		return true;

	case Secondary:
		Dest.DWord = pSpawn->Equipment.Offhand.ID;
		Dest.Type = pIntType;
		return true;

	case Equipment:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nSlot = GetIntFromString(Index, 0);
				int size = sizeof(EQUIPMENT) / 4;

				if (nSlot < 9)
				{
					Dest.DWord = pSpawn->Equipment.Item[nSlot].ID;
					return true;
				}
			}
			else
			{
				for (int nSlot = 0; szEquipmentSlot[nSlot]; nSlot++)
				{
					if (!_stricmp(Index, szEquipmentSlot[nSlot]))
					{
						Dest.DWord = pSpawn->Equipment.Item[nSlot].ID;
						return true;
					}
				}
			}
		}
		return false;

	case xTargetable:
		Dest.DWord = pSpawn->Targetable;
		Dest.Type = pBoolType;
		return true;

	case CanSplashLand: {
		CVector3 sv3;
		sv3.X = pSpawn->Y;
		sv3.Y = pSpawn->X;
		sv3.Z = pSpawn->Z;
		Dest.DWord = pCharSpawn->CanSee(sv3);
		Dest.Type = pBoolType;
		return true;
	}

	case IsBerserk:
		Dest.DWord = pSpawn->berserker;
		Dest.Type = pIntType;
		return true;

	case pTouchingSwitch:
		Dest.DWord = (DWORD)pSpawn->pTouchingSwitch;
		Dest.Type = pIntType;
		return true;

	case bShowHelm:
		Dest.DWord = pSpawn->bShowHelm;
		Dest.Type = pBoolType;
		return true;

	case CorpseDragCount:
		Dest.DWord = pSpawn->CorpseDragCount;
		Dest.Type = pIntType;
		return true;

	case bBetaBuffed:
		Dest.DWord = pSpawn->bBetaBuffed;
		Dest.Type = pBoolType;
		return true;

	case CombatSkillTicks:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0);
			if (index < 0)
				index = 0;
			if (index > 1)
				index = 1;
			Dest.DWord = pSpawn->CombatSkillTicks[index];
			return true;
		}
		return false;

	case FD:
		Dest.DWord = pSpawn->FD;
		Dest.Type = pIntType;
		return true;

	case InPvPArea:
		Dest.DWord = pSpawn->InPvPArea;
		Dest.Type = pIntType;
		return true;

	case bAlwaysShowAura:
		Dest.DWord = pSpawn->bAlwaysShowAura;
		Dest.Type = pBoolType;
		return true;

	case GMRank:
		Dest.DWord = pSpawn->GMRank;
		Dest.Type = pIntType;
		return true;

	case WarCry:
		Dest.DWord = pSpawn->WarCry;
		Dest.Type = pIntType;
		return true;

	case IsPassenger:
		Dest.DWord = pSpawn->IsPassenger;
		Dest.Type = pIntType;
		return true;

	case LastCastTime:
		Dest.DWord = pSpawn->LastCastTime;
		Dest.Type = pIntType;
		return true;

	case DragNames:
		Dest.Type = pStringType;

		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0);
			if (index < 0)
				index = 0;
			if (index > 1)
				index = 1;
			strcpy_s(DataTypeTemp, pSpawn->DragNames[index]);
			Dest.Ptr = DataTypeTemp;
			return true;
		}
		return false;

	case DraggingPlayer:
		strcpy_s(DataTypeTemp, pSpawn->DraggingPlayer);
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;

	case bStationary:
		Dest.DWord = pSpawn->bStationary;
		Dest.Type = pBoolType;
		return true;

	case BearingToTarget:
		Dest.Float = pSpawn->BearingToTarget;
		Dest.Type = pFloatType;
		return true;

	case bTempPet:
		Dest.DWord = pSpawn->bTempPet;
		Dest.Type = pBoolType;
		return true;

	case HoldingAnimation:
		Dest.DWord = pSpawn->HoldingAnimation;
		Dest.Type = pIntType;
		return true;

	case Blind:
		Dest.DWord = pSpawn->Blind;
		Dest.Type = pIntType;
		return true;

	case LastCastNum:
		Dest.DWord = pSpawn->LastCastNum;
		Dest.Type = pIntType;
		return true;

	case CollisionCounter:
		Dest.DWord = pSpawn->CollisionCounter;
		Dest.Type = pIntType;
		return true;

	case CeilingHeightAtCurrLocation:
		Dest.Float = pSpawn->CeilingHeightAtCurrLocation;
		Dest.Type = pFloatType;
		return true;

	case AssistName:
		strcpy_s(DataTypeTemp, pSpawn->AssistName);
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case SeeInvis:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0);
			if (index < 0)
				index = 0;
			if (index > 2)
				index = 2;
			Dest.DWord = pSpawn->SeeInvis[index];
			return true;
		}
		return false;

	case SpawnStatus:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0);
			if (index < 0)
				index = 0;
			if (index > 5)
				index = 5;
			Dest.DWord = pSpawn->SpawnStatus[index];
			return true;
		}
		return false;

	case bWaitingForPort:
		Dest.DWord = pSpawn->bWaitingForPort;
		Dest.Type = pBoolType;
		return true;

	case ActorDef:
		strcpy_s(DataTypeTemp, pSpawn->mActorClient.ActorDef);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CachedBuff: {
		// TODO: Extract to a function
		Dest.Type = pCachedBuffType;

		if (CachedBuffsMap.empty())
			return false;

		int SpellID = 0;
		bool bBySlot = false;
		bool bByIndex = false;
		bool bByKeyword = false;
		char* pIndex = Index;

		if (pIndex[0])
		{
			if (IsNumber(Index))
			{
				// by spell ID
				SpellID = GetIntFromString(Index, SpellID);
			}
			else
			{
				bool bExact = false;
				if (*pIndex == '#')
				{
					// by buff slot
					bBySlot = true;
					pIndex++;
				}
				else if (*pIndex == '*')
				{
					// by buff index
					bByIndex = true;
					pIndex++;
				}
				else if (*pIndex == '^')
				{
					// by keyword
					bByKeyword = true;
					pIndex++;
				}
				else
				{
					// by spell name
					if (SPELL* pSpell = GetSpellByName(pIndex))
					{
						SpellID = pSpell->ID;
					}
				}
			}

			if (SpellID)
			{
				auto ps = CachedBuffsMap.find(pSpawn->SpawnID);
				if (ps != CachedBuffsMap.end())
				{
					for (auto& [buffSpellId, targetBuff] : ps->second)
					{
						if (buffSpellId == SpellID)
						{
							TargetBuffTemp = targetBuff;
							return true;
						}
					}
				}
			}
			else if (bBySlot)
			{
				int idx = GetIntFromString(pIndex, 0) - 1;

				auto ps = CachedBuffsMap.find(pSpawn->SpawnID);
				if (ps != CachedBuffsMap.end())
				{
					const auto& buffs = ps->second;
					idx = std::clamp(idx, 0, NUM_BUFF_SLOTS);

					for (auto& [buffSpellId, targetBuff] : buffs)
					{
						if (targetBuff.slot == idx)
						{
							TargetBuffTemp = targetBuff;
							Dest.Ptr = &TargetBuffTemp;
							return true;
						}
					}
				}
			}
			else if (bByIndex)
			{
				int idx = GetIntFromString(pIndex, 0) - 1;

				auto ps = CachedBuffsMap.find(pSpawn->SpawnID);
				if (ps != CachedBuffsMap.end())
				{
					if (idx < 0)
						idx = 0;

					if (idx >= (int)ps->second.size())
					{
						return false;
					}

					auto iter = ps->second.begin();
					std::advance(iter, idx);

					if (iter != ps->second.end())
					{
						TargetBuffTemp = iter->second;
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
				}
			}
			else if (bByKeyword)
			{
				/*Slowed = 8,
				Rooted = 9,
				Mezzed = 10,
				Crippled = 11,
				Maloed = 12,
				Tashed = 13,
				Snared = 14,
				Hasted = 15,
				Aego = 16,
				Skin = 17,
				Focus = 18,
				Regen = 19,
				Symbol = 20,
				Clarity = 21,
				Pred = 22,
				Strength = 23,
				Brells = 24,
				SV = 25,
				SE = 26,
				HybridHP = 27,
				Growth = 28,
				Shining = 29,
				Beneficial = 30,
				DSed = 31,
				RevDSed = 32,
				Charmed = 33,
				Diseased = 34,
				Poisoned = 35,
				Cursed = 36,
				Corrupted
				*/

				// TODO: Replace SPA constants with enum values

				int type = -1;
				if (!_stricmp(pIndex, "Slowed"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;

					if (HasCachedTargetBuffSPA(11, false, pSpawn, &TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Rooted"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSPA(99, false, pSpawn, &TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Mezzed"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSPA(31, false, pSpawn, &TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Crippled"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSubCat("Disempowering", pSpawn, &TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Maloed"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					//GetTargetBuffBySubCat("Resist Debuffs", (1 << Shaman) + (1 << Mage));
					if (HasCachedTargetBuffSubCat("Resist Debuffs", pSpawn, &TargetBuffTemp, (1 << Shaman) + (1 << Mage)))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Tashed"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSubCat("Resist Debuffs", pSpawn, &TargetBuffTemp, 1 << Enchanter))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Snared"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSPA(3, false, pSpawn, &TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Beneficial"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;

					auto ps = CachedBuffsMap.find(pSpawn->SpawnID);
					if (ps != CachedBuffsMap.end())
					{
						for (const auto& [spellId, buff] : ps->second)
						{
							if (SPELL* pSpell = GetSpellByID(spellId))
							{
								if (pSpell->SpellType != 0)
								{
									// targetwindow has a leak in it player buffs shows up in it
									// so we need to make sure its not a "leaked buff"
									if (SPAWNINFO* pPlayer = (SPAWNINFO*)GetSpawnByName(buff.casterName))
									{
										if (pPlayer->Type == SPAWN_PLAYER)
										{
											continue;
										}
									}

									TargetBuffTemp = buff;
									Dest.Ptr = &TargetBuffTemp;
									return true;
								}
							}
						}
					}
					return false;
				}
			}
		}
		return false;
	}

	case CachedBuffCount: {
		Dest.Type = pIntType;
		Dest.DWord = -1;
		auto ps = CachedBuffsMap.find(pSpawn->SpawnID);
		if (ps != CachedBuffsMap.end())
		{
			Dest.DWord = ps->second.size();
		}
		return true;
	}

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2BuffType

bool MQ2BuffType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	SPELLBUFF* pBuff = static_cast<SPELLBUFF*>(VarPtr.Ptr);
	if (!pBuff)
		return false;
	if (pBuff->SpellID <= 0)
		return false;

	//----------------------------------------------------------------------------
	// methods

	if (MQTypeMember* pMethod = MQ2BuffType::FindMethod(Member))
	{
		switch (static_cast<BuffMethods>(pMethod->ID))
		{
		case Remove:
			if (SPELL* pSpell = GetSpellByID(pBuff->SpellID))
			{
				RemoveBuff((SPAWNINFO*)pLocalPlayer, pSpell->Name);
				return true;
			}
			break;
		}
		return false;
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2BuffType::FindMember(Member);
	if (!pMember)
	{
		if (SPELL* pSpell = GetSpellByID(pBuff->SpellID))
		{
			MQVarPtr data;
			data.Ptr = pSpell;

			return pSpellType->GetMember(data, Member, Index, Dest);
		}

		return false;
	}

	static char Temp[128];
	switch (static_cast<BuffMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case ID:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (GetBuffID(pBuff, Dest.Int))
			return true;
		if (GetShortBuffID(pBuff, Dest.Int))
			return true;

		return false;

	case Level:
		Dest.DWord = pBuff->Level;
		Dest.Type = pIntType;
		return true;

	case Spell:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(pBuff->SpellID))
		{
			return true;
		}
		return false;

	case Mod:
		Dest.Float = pBuff->Modifier;
		Dest.Type = pFloatType;
		if (Dest.Float != 1.0f)
		{
			return true;
		}
		return false;

	case Duration:
		Dest.UInt64 = GetSpellBuffTimer(pBuff->SpellID);
		Dest.Type = pTimeStampType;
		return true;

	case Dar:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (SPELL* pSpell = GetSpellByID(pBuff->SpellID))
		{
			if (pSpell->SpellType != 0)
			{
				int slots = GetSpellNumEffects(pSpell);
				for (int i = 0; i < slots; i++)
				{
					int attrib = GetSpellAttrib(pSpell, i);

					if (IsDamageAbsorbSPA(attrib))
					{
						for (auto& slotData : pBuff->SlotData)
						{
							if (slotData.Slot == i)
							{
								Dest.DWord += slotData.Value;
							}
						}
					}
				}
				return true;
			}
		}
		return false;

	case TotalCounters:
		Dest.DWord = GetTotalSpellCounters(pBuff);
		Dest.Type = pIntType;
		return true;

	case CountersDisease:
		Dest.DWord = GetSpellCounters(SPA_DISEASE, pBuff);
		Dest.Type = pIntType;
		return true;

	case CountersPoison:
		Dest.DWord = GetSpellCounters(SPA_POISON, pBuff);
		Dest.Type = pIntType;
		return true;

	case CountersCurse:
		Dest.DWord = GetSpellCounters(SPA_CURSE, pBuff);
		Dest.Type = pIntType;
		return true;

	case CountersCorruption:
		Dest.DWord = GetSpellCounters(SPA_CURSE, pBuff);
		Dest.Type = pIntType;
		return true;

	case HitCount:
		Dest.DWord = pBuff->HitCount;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2TargetBuffType

bool MQ2TargetBuffType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (VarPtr.Int == -1)
		return false;

	int buffid = pTargetWnd->BuffSpellID[VarPtr.Int];
	if (buffid <= 0)
		return false;

	MQTypeMember* pMember = MQ2TargetBuffType::FindMember(Member);
	if (!pMember)
	{
		if (SPELL* pSpell = GetSpellByID(buffid))
		{
			return pSpellType->GetMember(*(MQVarPtr*)& pSpell, Member, Index, Dest);
		}
		return false;
	}

	static char Temp[128];
	switch (static_cast<TargetBuffMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)&pTargetWnd->BuffSpellID[VarPtr.Int];
		Dest.Type = pIntType;
		return true;

	case xIndex:
		Dest.Int = VarPtr.Int;
		Dest.Type = pIntType;
		return true;

	case Duration:
		Dest.UInt64 = pTargetWnd->BuffTimer[VarPtr.Int];
		Dest.Type = pTimeStampType;
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2CachedBuffType

bool MQ2CachedBuffType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	TargetBuff* pcTB = (TargetBuff*)VarPtr.Ptr;
	if (!pcTB)
		return false;

	int buffid = pcTB->spellId;
	if (buffid <= 0)
		return false;

	MQTypeMember* pMember = MQ2CachedBuffType::FindMember(Member);
	if (!pMember)
	{
		if (SPELL* pSpell = GetSpellByID(buffid))
		{
			return pSpellType->GetMember(*(MQVarPtr*)& pSpell, Member, Index, Dest);
		}
		return false;
	}

	switch (static_cast<CachedBuffMembers>(pMember->ID))
	{
	case CasterName:
		strcpy_s(DataTypeTemp, pcTB->casterName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Count:
		Dest.Int = pcTB->count;
		Dest.Type = pIntType;
		return true;

	case Slot:
		Dest.Int = pcTB->slot;
		Dest.Type = pIntType;
		return true;

	case SpellID:
		Dest.Int = pcTB->spellId;
		Dest.Type = pIntType;
		return true;

	case Duration:
		int calcedduration = (pcTB->timeStamp + (pcTB->duration * 6000)) - EQGetTime();
		if (calcedduration < 0)
			calcedduration = 0;
		Dest.Int = calcedduration;
		Dest.Type = pTimeStampType;

		return true;
	}
	return false;
}

//----------------------------------------------------------------------------
// MQ2CharacterType

bool MQ2CharacterType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CHARINFO* pChar = static_cast<CHARINFO*>(VarPtr.Ptr);
	if (!pChar)
		return false;

	const PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return false;

	PlayerClient* pPlayerClient = reinterpret_cast<PlayerClient*>(pChar->pSpawn);


	//------------------------------------------------------------------------
	// methods

	if (MQTypeMember* pMethod = MQ2CharacterType::FindMethod(Member))
	{
		switch (static_cast<CharacterMethods>(pMethod->ID))
		{
		case Stand:
			pEverQuest->InterpretCmd(pPlayerClient, "/stand on");
			return true;

		case Sit:
			pEverQuest->InterpretCmd(pPlayerClient, "/sit on");
			return true;

		case Dismount:
			pEverQuest->InterpretCmd(pPlayerClient, "/dismount");
			return true;

		case StopCast:
			pEverQuest->InterpretCmd(pPlayerClient, "/stopcast");
			return true;

		default: break;
		}

		return false;
	}

	MQTypeMember* pMember = MQ2CharacterType::FindMember(Member);
	if (!pMember)
	{
		// call into parent
		MQVarPtr data;
		data.Ptr = pLocalPlayer;

		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<CharacterMembers>(pMember->ID))
	{
	case Name:
		strcpy_s(DataTypeTemp, ((SPAWNINFO*)pLocalPlayer)->Name);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Origin:
		Dest.Type = pZoneType;
		if (pChar->StartingCity > 0 && pChar->StartingCity < MAX_ZONES)
		{
			Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[pChar->StartingCity];
			return true;
		}
		return false;

	case SubscriptionDays:
		Dest.Int = pChar->SubscriptionDays;
		Dest.Type = pIntType;
		return true;

	case Exp:
		Dest.Int64 = pChar->Exp;
		Dest.Type = pInt64Type;
		return true;

	case PctExp:
		Dest.Float = (float)pChar->Exp / 1000.0f;
		Dest.Type = pFloatType;
		return true;

	case PctExpToAA:
		Dest.Int = (int)pChar->PercentEXPtoAA;
		Dest.Type = pIntType;
		return true;

	case PctAAExp:
		Dest.Float = (float)pChar->AAExp / 1000.0f;
		Dest.Type = pFloatType;
		return true;

	case Vitality:
		Dest.Int64 = pChar->Vitality;
		Dest.Type = pInt64Type;
		return true;

	case PctVitality: {
		Dest.Float = 0;
		Dest.Type = pFloatType;
		int64_t vitality = pChar->Vitality;
		int64_t cap = pInventoryWnd->VitalityCap;
		if (vitality > cap)
			vitality = cap;
		if (cap > 0)
			Dest.Float = (float)vitality * 100 / cap;
		return true;
	}

	case AAVitality:
		Dest.Int = pChar->AAVitality;
		Dest.Type = pIntType;
		return true;

	case PctAAVitality: {
		Dest.Float = 0;
		Dest.Type = pFloatType;
		int aavitality = pChar->AAVitality;
		int aacap = pInventoryWnd->AAVitalityCap;
		if (aavitality > aacap)
			aavitality = aacap;
		if (aacap > 0)
			Dest.Float = (float)aavitality * 100 / aacap;
		return true;
	}

	case Spawn:
		Dest.Ptr = pLocalPlayer;
		Dest.Type = pSpawnType;
		return true;

	case CurrentHPs:
		Dest.DWord = GetCurHPS();
		Dest.Type = pIntType;
		return true;

	case MaxHPs:
		Dest.Type = pIntType;
		Dest.Int = GetMaxHPS();
		return true;

	case PctHPs: {
		Dest.Int = 0;
		Dest.Type = pIntType;
		LONG maxhp = GetMaxHPS();
		if (maxhp != 0)
			Dest.Int = GetCurHPS() * 100 / maxhp;
		return true;
	}

	case CurrentMana:
		Dest.DWord = pProfile->Mana;
		Dest.Type = pIntType;
		return true;

	case MaxMana:
		Dest.DWord = GetMaxMana();
		Dest.Type = pIntType;
		return true;

	case PctMana:
		if (int maxMana = GetMaxMana())
			Dest.DWord = pProfile->Mana * 100 / maxMana;
		else
			Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case CountBuffs:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (const auto& buff : pProfile->Buff)
		{
			if (buff.SpellID > 0)
			{
				Dest.DWord++;
			}
		}
		return true;

	case CountSongs:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (const auto& buff : pProfile->ShortBuff)
		{
			if (buff.SpellID > 0)
			{
				Dest.DWord++;
			}
		}
		return true;

	case BlockedPetBuff:
		// Fall through to BlockedBuff
	case BlockedBuff:
		Dest.Type = pSpellType;
		if (!Index[0])
			return false;

		// TODO:  Move this into a function for both BlockedPetBuff and BlockedBuff
		if (CHARINFONEW* pCharnew = reinterpret_cast<CHARINFONEW*>(GetCharInfo()))
		{
			int iMaxBlockedSpells = (static_cast<CharacterMembers>(pMember->ID) == BlockedBuff ? MAX_BLOCKED_SPELLS : MAX_BLOCKED_SPELLS_PET);
			if (IsNumber(Index))
			{
				int nBuff = GetIntFromString(Index, iMaxBlockedSpells + 2) - 1;
				if (nBuff < 0)
					nBuff = 0;
				if (nBuff > iMaxBlockedSpells)
					return false;

				if (int spellId = (static_cast<CharacterMembers>(pMember->ID) == BlockedBuff) ? pCharnew->BlockedSpell[nBuff] : pCharnew->BlockedPetSpell[nBuff])
				{
					if (SPELL* pSpell = GetSpellByID(spellId))
					{
						Dest.Ptr = pSpell;
						return true;
					}
				}
			}
			else
			{
				for (auto i = 0; i < iMaxBlockedSpells; ++i)
				{
					if (int spellId = (static_cast<CharacterMembers>(pMember->ID) == BlockedBuff) ? pCharnew->BlockedSpell[i] : pCharnew->BlockedPetSpell[i])
					{
						if (SPELL* pSpell = GetSpellByID(spellId))
						{
							if (!_strnicmp(Index, pSpell->Name, strlen(Index)))
							{
								Dest.Ptr = pSpell;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	// TODO:  Move this to a function for both Buff and Song since code is identical except for Short vs Long Buff.
	case Buff:
		Dest.Type = pBuffType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0)
				return false;
			if (nBuff >= NUM_LONG_BUFFS)
				return false;
			if (pProfile->Buff[nBuff].SpellID <= 0)
				return false;

			Dest.Ptr = (SPELLBUFF*)&pProfile->Buff[nBuff];
			Dest.HighPart = nBuff;
			return true;
		}

		for (int nBuff = 0; nBuff < NUM_LONG_BUFFS; ++nBuff)
		{
			if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
			{
				if (!_strnicmp(Index, pSpell->Name, strlen(Index)))
				{
					Dest.Ptr = (SPELLBUFF*)&pProfile->Buff[nBuff];
					Dest.HighPart = nBuff;
					return true;
				}
			}
		}
		return false;

	case Song:
		Dest.Type = pBuffType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0)
				return false;
			if (nBuff >= NUM_SHORT_BUFFS)
				return false;
			if (pProfile->ShortBuff[nBuff].SpellID <= 0)
				return false;

			Dest.Ptr = (SPELLBUFF*)&pProfile->ShortBuff[nBuff];
			Dest.HighPart = nBuff;
			return true;
		}

		for (int nBuff = 0; nBuff < NUM_SHORT_BUFFS; nBuff++)
		{
			if (SPELL* pSpell = GetSpellByID(pProfile->ShortBuff[nBuff].SpellID))
			{
				if (!_strnicmp(Index, pSpell->Name, strlen(Index)))
				{
					Dest.Ptr = (SPELLBUFF*)&pProfile->ShortBuff[nBuff];
					Dest.HighPart = nBuff;
					return true;
				}
			}
		}
		return false;

	case HPBonus:
		Dest.DWord = pChar->HPBonus;
		Dest.Type = pIntType;
		return true;

	case ManaBonus:
		Dest.DWord = pChar->ManaBonus;
		Dest.Type = pIntType;
		return true;

	case EnduranceBonus:
		Dest.DWord = pChar->EnduranceBonus;
		Dest.Type = pIntType;
		return true;

	case CombatEffectsBonus: {
		int CombatEffectsCap = GetModCap(HEROIC_MOD_COMBAT_EFFECTS);
		Dest.DWord = (pChar->CombatEffectsBonus > CombatEffectsCap ? CombatEffectsCap : pChar->CombatEffectsBonus);
		Dest.Type = pIntType;
		return true;
	}

	case ShieldingBonus: {
		int ShieldingCap = GetModCap(HEROIC_MOD_MELEE_SHIELDING);
		Dest.DWord = (pChar->ShieldingBonus > ShieldingCap ? ShieldingCap : pChar->ShieldingBonus);
		Dest.Type = pIntType;
		return true;
	}

	case SpellShieldBonus: {
		int SpellShieldCap = GetModCap(HEROIC_MOD_SPELL_SHIELDING);
		Dest.DWord = (pChar->SpellShieldBonus > SpellShieldCap ? SpellShieldCap : pChar->SpellShieldBonus);
		Dest.Type = pIntType;
		return true;
	}

	case AvoidanceBonus: {
		int AvoidanceCap = GetModCap(HEROIC_MOD_AVOIDANCE);
		Dest.DWord = (pChar->AvoidanceBonus > AvoidanceCap ? AvoidanceCap : pChar->AvoidanceBonus);
		Dest.Type = pIntType;
		return true;
	}

	case AccuracyBonus: {
		int AccuracyCap = GetModCap(HEROIC_MOD_ACCURACY);
		Dest.DWord = (pChar->AccuracyBonus > AccuracyCap ? AccuracyCap : pChar->AccuracyBonus);
		Dest.Type = pIntType;
		return true;
	}

	case StunResistBonus: {
		int StunResistCap = GetModCap(HEROIC_MOD_STUN_RESIST);
		Dest.DWord = (pChar->StunResistBonus > StunResistCap ? StunResistCap : pChar->StunResistBonus);
		Dest.Type = pIntType;
		return true;
	}

	case StrikeThroughBonus: {
		int StrikeThroughCap = GetModCap(HEROIC_MOD_STRIKETHROUGH);
		Dest.DWord = (pChar->StrikeThroughBonus > StrikeThroughCap ? StrikeThroughCap : pChar->StrikeThroughBonus);
		Dest.Type = pIntType;
		return true;
	}

	case DoTShieldBonus: {
		int DoTShieldCap = GetModCap(HEROIC_MOD_DOT_SHIELDING);
		Dest.DWord = (pChar->DoTShieldBonus > DoTShieldCap ? DoTShieldCap : pChar->DoTShieldBonus);
		Dest.Type = pIntType;
		return true;
	}

	case AttackBonus:
		Dest.DWord = pChar->AttackBonus;
		Dest.Type = pIntType;
		return true;

	case HPRegenBonus:
		Dest.DWord = pChar->HPRegenBonus;
		Dest.Type = pIntType;
		return true;

	case ManaRegenBonus:
		Dest.DWord = pChar->ManaRegenBonus;
		Dest.Type = pIntType;
		return true;

	case DamageShieldBonus: {
		int DamageShieldCap = GetModCap(HEROIC_MOD_DAMAGE_SHIELDING);
		Dest.DWord = (pChar->DamageShieldBonus > DamageShieldCap ? DamageShieldCap : pChar->DamageShieldBonus);
		Dest.Type = pIntType;
		return true;
	}

	case DamageShieldMitigationBonus: {
		int DamageShieldMitigationCap = GetModCap(HEROIC_MOD_DAMAGE_SHIELD_MITIG);
		Dest.DWord = (pChar->DamageShieldMitigationBonus > DamageShieldMitigationCap ? DamageShieldMitigationCap : pChar->DamageShieldMitigationBonus);
		Dest.Type = pIntType;
		return true;
	}

	case HeroicSTRBonus:
		Dest.DWord = pChar->HeroicSTRBonus;
		Dest.Type = pIntType;
		return true;

	case HeroicINTBonus:
		Dest.DWord = pChar->HeroicINTBonus;
		Dest.Type = pIntType;
		return true;

	case HeroicWISBonus:
		Dest.DWord = pChar->HeroicWISBonus;
		Dest.Type = pIntType;
		return true;

	case HeroicAGIBonus:
		Dest.DWord = pChar->HeroicAGIBonus;
		Dest.Type = pIntType;
		return true;

	case HeroicDEXBonus:
		Dest.DWord = pChar->HeroicDEXBonus;
		Dest.Type = pIntType;
		return true;

	case HeroicSTABonus:
		Dest.DWord = pChar->HeroicSTABonus;
		Dest.Type = pIntType;
		return true;

	case HeroicCHABonus:
		Dest.DWord = pChar->HeroicCHABonus;
		Dest.Type = pIntType;
		return true;

	case HealAmountBonus:
		Dest.DWord = pChar->HealAmountBonus;
		Dest.Type = pIntType;
		return true;

	case SpellDamageBonus:
		Dest.DWord = pChar->SpellDamageBonus;
		Dest.Type = pIntType;
		return true;

	case ClairvoyanceBonus:
		Dest.DWord = pChar->ClairvoyanceBonus;
		Dest.Type = pIntType;
		return true;

	case EnduranceRegenBonus:
		Dest.DWord = pChar->EnduranceRegenBonus;
		Dest.Type = pIntType;
		return true;

	case AttackSpeed:
		Dest.DWord = pChar->AttackSpeed;
		Dest.Type = pIntType;
		return true;

	case Endurance: // Backwards compat, CurrentEndurance should be used instead.
	case CurrentEndurance:
		Dest.DWord = pProfile->Endurance;
		Dest.Type = pIntType;
		return true;

	case MaxEndurance:
		Dest.DWord = GetMaxEndurance();
		Dest.Type = pIntType;
		return true;

	case PctEndurance:
		if (int maxEndurance = GetMaxEndurance())
			Dest.DWord = pProfile->Endurance * 100 / maxEndurance;
		else
			Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case GukEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_DeepGuk].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case MMEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Mistmoore].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case RujEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Rujarkian].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case TakEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Takish].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case MirEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Miraguls].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case LDoNPoints:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.AdventurePointsAvailable;
		}
		Dest.Type = pIntType;
		return true;

	case CurrentFavor:
		Dest.Int64 = pChar->CurrFavor;
		Dest.Type = pInt64Type;
		return true;

	case CareerFavor:
		Dest.Int64 = pChar->CareerFavor;
		Dest.Type = pInt64Type;
		return true;

	case Inventory:
		Dest.Type = pItemType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nSlot = GetIntFromString(Index, NUM_INV_SLOTS);
				if (nSlot < NUM_INV_SLOTS)
				{
					if (pProfile->pInventoryArray && ((Dest.Ptr = pProfile->pInventoryArray->InventoryArray[nSlot])))
					{
						return true;
					}
				}
			}
			else
			{
				for (int nSlot = 0; szItemSlot[nSlot]; nSlot++)
				{
					if (!_stricmp(Index, szItemSlot[nSlot]))
					{
						if (pProfile->pInventoryArray && ((Dest.Ptr = pProfile->pInventoryArray->InventoryArray[nSlot])))
						{
							return true;
						}
					}
				}
			}
		}
		return false;

	case Bank:
		Dest.Type = pItemType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nSlot = GetIntFromString(Index, 0) - 1;
				if (nSlot < 0)
					return false;

				if (nSlot < NUM_BANK_SLOTS)
				{
					if (pChar && pChar->pBankArray)
					{
						if (Dest.Ptr = pChar->pBankArray->Bank[nSlot])
						{
							return true;
						}
					}
				}
				else
				{
					nSlot -= NUM_BANK_SLOTS;
					if (nSlot < NUM_SHAREDBANK_SLOTS)
					{
						if (pChar && pChar->pSharedBankArray)
						{
							if (Dest.Ptr = pChar->pSharedBankArray->SharedBank[nSlot])
							{
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case PlatinumShared:
		Dest.DWord = pChar->BankSharedPlat;
		Dest.Type = pIntType;
		return true;

	case Cash:
		Dest.DWord = pProfile->Plat * 1000 + pProfile->Gold * 100 + pProfile->Silver * 10 + pProfile->Copper;
		Dest.Type = pIntType;
		return true;

	case Platinum:
		Dest.DWord = pProfile->Plat;
		Dest.Type = pIntType;
		return true;

	case CursorPlatinum:
		Dest.DWord = pProfile->CursorPlat;
		Dest.Type = pIntType;
		return true;

	case Gold:
		Dest.DWord = pProfile->Gold;
		Dest.Type = pIntType;
		return true;

	case CursorGold:
		Dest.DWord = 0;
		if (const PcProfile* pProfile = GetPcProfile())
		{
			Dest.DWord = pProfile->CursorGold;
		}
		Dest.Type = pIntType;
		return true;

	case Silver:
		Dest.DWord = pProfile->Silver;
		Dest.Type = pIntType;
		return true;

	case CursorSilver:
		Dest.DWord = pProfile->CursorSilver;
		Dest.Type = pIntType;
		return true;

	case Copper:
		Dest.DWord = pProfile->Copper;
		Dest.Type = pIntType;
		return true;

	case CursorCopper:
		Dest.DWord = pProfile->CursorCopper;
		Dest.Type = pIntType;
		return true;

	case CashBank:
		Dest.DWord = pChar->BankPlat * 1000 + pChar->BankGold * 100 + pChar->BankSilver * 10 + pChar->BankCopper;
		Dest.Type = pIntType;
		return true;

	case PlatinumBank:
		Dest.DWord = pChar->BankPlat;
		Dest.Type = pIntType;
		return true;

	case GoldBank:
		Dest.DWord = pChar->BankGold;
		Dest.Type = pIntType;
		return true;

	case SilverBank:
		Dest.DWord = pChar->BankSilver;
		Dest.Type = pIntType;
		return true;

	case CopperBank:
		Dest.DWord = pChar->BankCopper;
		Dest.Type = pIntType;
		return true;

	case AAExp:
		Dest.DWord = pChar->AAExp;
		Dest.Type = pIntType;
		return true;

	case AAPoints:
		Dest.DWord = pProfile->AAPoints;
		Dest.Type = pIntType;
		return true;

	case Combat:
		Dest.DWord = *EQADDR_ATTACK;
		Dest.Type = pBoolType;
		return true;

	case HPRegen:
		Dest.DWord = GetHPRegen();
		Dest.Type = pIntType;
		return true;

	case ManaRegen:
		Dest.DWord = GetManaRegen();
		Dest.Type = pIntType;
		return true;

	case EnduranceRegen:
		Dest.DWord = GetEnduranceRegen();
		Dest.Type = pIntType;
		return true;

	case Grouped:
		Dest.Type = pBoolType;
		if (!pChar->pGroupInfo)
			return false;

		Dest.DWord = pChar->pGroupInfo->pMember[1]
			|| pChar->pGroupInfo->pMember[2]
			|| pChar->pGroupInfo->pMember[3]
			|| pChar->pGroupInfo->pMember[4]
			|| pChar->pGroupInfo->pMember[5];
		return true;

	case GroupList: { // This isn't really working as intended just yet
		Dest.Type = pStringType;
		if (!pChar->pGroupInfo)
			return false;
		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				strcpy_s(DataTypeTemp, pChar->pGroupInfo->pMember[i]->Name.c_str());
				if (i < 5 && pChar->pGroupInfo->pMember[i + 1])
					strcat_s(DataTypeTemp, " ");
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case AmIGroupLeader:
		Dest.Type = pStringType;
		if (!pChar->pGroupInfo) return false;
		if (!pChar->pGroupInfo->pLeader) return false;

		if (!_stricmp(pChar->pGroupInfo->pLeader->Name.c_str(), pChar->Name))
			strcpy_s(DataTypeTemp, "TRUE");
		else
			strcpy_s(DataTypeTemp, "FALSE");
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case MaxBuffSlots:
		Dest.DWord = GetCharMaxBuffSlots();
		Dest.Type = pIntType;
		return true;

	case FreeBuffSlots:
		Dest.DWord = GetCharMaxBuffSlots();
		Dest.Type = pIntType;

		for (const auto& buff : pProfile->Buff)
		{
			if (buff.SpellID > 0)
				Dest.DWord--;
		}
		return true;

	case Gem:
		Dest.Type = pSpellType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// number
			int nGem = GetIntFromString(Index, 0) - 1;
			if (nGem < 0)
				return false;

			if (nGem < NUM_SPELL_GEMS)
			{
				if (Dest.Ptr = GetSpellByID(GetMemorizedSpell(nGem)))
				{
					Dest.Type = pSpellType;
					return true;
				}
			}
		}
		else
		{
			// name
			for (unsigned long nGem = 0; nGem < NUM_SPELL_GEMS; nGem++)
			{
				if (SPELL* pSpell = GetSpellByID(GetMemorizedSpell(nGem)))
				{
					if (!_stricmp(Index, pSpell->Name))
					{
						Dest.DWord = nGem + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
			}
		}
		return false;

	case LanguageSkill: {
		Dest.DWord = 0;
		Dest.Type = pIntType;
		int nLang = 0;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			nLang = GetIntFromString(Index, nLang) - 1;
			if (nLang < 0)
				return false;
		}
		else
		{
			nLang = GetLanguageIDByName(Index) - 1;
		}
		if (nLang < 0 || nLang >= 25)
			return false;

		Dest.DWord = pChar->languages[nLang];
		return true;
	}

	case CombatAbility:
		Dest.Type = pSpellType;
		if (!Index[0])
			return false;
		if (IsNumber(Index))
		{
			// number
			int abnum = GetIntFromString(Index, 0);
			if (abnum <= 0)
				abnum = 1;
			int nCombatAbility = abnum - 1;
			if (nCombatAbility < NUM_COMBAT_ABILITIES)
			{
				if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
				{
					if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
					{
						Dest.Ptr = pSpell;
						Dest.Type = pSpellType;
						return true;
					}
				}
			}
		}
		else
		{
			// name
			for (unsigned long nCombatAbility = 0; nCombatAbility < NUM_COMBAT_ABILITIES; nCombatAbility++)
			{
				if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
				{
					if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
					{
						if (!_stricmp(Index, pSpell->Name))
						{
							Dest.DWord = nCombatAbility + 1;
							Dest.Type = pIntType;
							return true;
						}
					}
				}
			}
		}
		return false;

	case CombatAbilityTimer:
		Dest.Int = 0;
		Dest.Type = pTicksType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// number
				int nCombatAbility = GetIntFromString(Index, 0) - 1;
				if (nCombatAbility < 0)
					return false;
				if (nCombatAbility < NUM_COMBAT_ABILITIES)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
					{
						if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							uint32_t timeNow = static_cast<uint32_t>(time(nullptr));

							if (pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup) > timeNow)
							{
								Dest.Int = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup) - timeNow + 6;
								Dest.Int /= 6;
							}

							return true;
						}
					}
				}
			}
			else
			{
				// by name
				for (int nCombatAbility = 0; nCombatAbility < NUM_COMBAT_ABILITIES; nCombatAbility++)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility)) {
						if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							if (!_stricmp(Index, pSpell->Name))
							{
								uint32_t timeNow = static_cast<uint32_t>(time(nullptr));
								uint32_t timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);

								if (timer > timeNow)
								{
									Dest.Int = timer - timeNow + 6;
									Dest.Int /= 6;
								}
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case CombatAbilityReady:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// number
				int nCombatAbility = GetIntFromString(Index, 0) - 1;
				if (nCombatAbility < 0)
					return false;

				if (nCombatAbility < NUM_COMBAT_ABILITIES)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
					{
						if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							uint32_t timeNow = static_cast<uint32_t>(time(nullptr));
							uint32_t timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);

							if (timer < timeNow)
							{
								Dest.DWord = 1;
								return true;
							}
						}
					}
				}
			}
			else
			{
				// by name
				for (unsigned long nCombatAbility = 0; nCombatAbility < NUM_COMBAT_ABILITIES; nCombatAbility++)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
					{
						if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							if (!_stricmp(Index, pSpell->Name))
							{
								uint32_t timeNow = static_cast<uint32_t>(time(nullptr));
								uint32_t timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);

								if (timer < timeNow)
								{
									Dest.DWord = 1;
									return true;
								}
							}
						}
					}
				}
			}
		}
		return true;

	case ActiveDisc:
		Dest.Type = pSpellType;

		if (pCombatAbilityWnd)
		{
			if (CXWnd* Child = pCombatAbilityWnd->GetChildItem("CAW_CombatEffectLabel"))
			{
				CXStr name = Child->GetWindowText();
				if (!name.empty())
				{
					if (Dest.Ptr = GetSpellByName(name.c_str()))
					{
						return true;
					}
				}
			}
		}
		return false;

	case Moving:
		Dest.DWord = false;
		if (pCharSpawn && pChar && pChar->pSpawn)
		{
			Dest.DWord =
				((gbMoving
					&& (pChar->pSpawn->SpeedRun == 0.0f)
					&& (pChar->pSpawn->Mount == nullptr))
				|| (fabs(FindSpeed(pChar->pSpawn) > 0.0f)));
		}
		Dest.Type = pBoolType;
		return true;

	case Hunger:
		Dest.DWord = pProfile->hungerlevel;
		Dest.Type = pIntType;
		return true;

	case Thirst:
		Dest.DWord = pProfile->thirstlevel;
		Dest.Type = pIntType;
		return true;

	case AltAbilityTimer:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;

		if (Index[0]) {
			if (IsNumber(Index))
			{
				// numeric
				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility)))
					{
						if (pAbility->ID == GetIntFromString(Index, 0))
						{
							int reusetimer = 0;
							pAltAdvManager->IsAbilityReady(pPCData, pAbility, &reusetimer);
							if (reusetimer < 0)
							{
								reusetimer = 0;
							}

							Dest.UInt64 = reusetimer * 1000;
							return true;
						}
					}
				}
			}
			else
			{
				// by name so we ned to take level into account
				int level = -1;
				if (pChar->pSpawn)
				{
					level = pChar->pSpawn->Level;
				}

				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility), level))
					{
						if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
						{
							if (!_stricmp(Index, pName))
							{
								int reusetimer = 0;
								pAltAdvManager->IsAbilityReady(pPCData, pAbility, &reusetimer);
								if (reusetimer < 0)
								{
									reusetimer = 0;
								}

								Dest.UInt64 = reusetimer * 1000;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case AltAbilityReady:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility)))
					{
						if (pAbility->ID == GetIntFromString(Index, 0))
						{
							if (pAbility->SpellID != -1)
								Dest.DWord = pAltAdvManager->IsAbilityReady(pPCData, pAbility, 0);

							return true;
						}
					}
				}
			}
			else
			{
				// by name so we need to take their level into account
				int level = -1;
				if (pChar->pSpawn)
				{
					level = pChar->pSpawn->Level;
				}

				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility), level))
					{
						if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
						{
							if (!_stricmp(Index, pName))
							{
								if (pAbility->SpellID != -1)
									Dest.DWord = pAltAdvManager->IsAbilityReady(pPCData, pAbility, 0);

								return true;
							}
						}
					}
				}
			}
		}
		return true;

	case AltAbility:
		Dest.Type = pAltAbilityType;
		if (Index[0])

		{
			if (IsNumber(Index))
			{
				// numeric
				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility)))
					{
						if (pAbility->ID == GetIntFromString(Index, 0))
						{
							Dest.Ptr = pAbility;
							return true;
						}
					}
				}
			}
			else
			{
				// by name so we need to take their level into account
				int level = -1;
				if (pChar->pSpawn)
				{
					level = pChar->pSpawn->Level;
				}

				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility), level))
					{
						if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
						{
							if (!_stricmp(Index, pName))
							{
								Dest.Ptr = pAbility;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case Skill:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			int nSkill = 0;

			if (IsNumber(Index))
			{
				// numeric
				nSkill = GetIntFromString(Index, nSkill) - 1;
				if (nSkill < 0)
					return false;
			}
			else
			{
				// name
				for (nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
				{
					if (!_stricmp(Index, szSkills[nSkill]))
						break;
				}
			}

			if (nSkill < NUM_SKILLS)
			{
				if (pProfile->Skill[nSkill])
				{
					Dest.DWord = GetAdjustedSkill(nSkill);
				}
				return true;
			}
		}
		return false;

	case SkillBase:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			int nSkill = 0;

			if (IsNumber(Index))
			{
				// numeric
				nSkill = GetIntFromString(Index, nSkill) - 1;
				if (nSkill < 0)
					return false;
			}
			else
			{
				// name
				for (nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
				{
					if (!_stricmp(Index, szSkills[nSkill]))
						break;
				}
			}

			if (nSkill < NUM_SKILLS)
			{
				if (pProfile->Skill[nSkill])
				{
					Dest.DWord = GetBaseSkill(nSkill);
				}
				return true;
			}
		}
		return false;

	case SkillCap:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			int nSkill = 0;

			if (IsNumber(Index))
			{
				// numeric
				nSkill = GetIntFromString(Index, nSkill) - 1;
				if (nSkill < 0)
					return false;
			}
			else
			{
				// name
				for (nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
				{
					if (!_stricmp(Index, szSkills[nSkill]))
						break;
				}
			}

			if (nSkill < NUM_SKILLS)
			{
				if (pCharData)
				{
					Dest.DWord = pCSkillMgr->GetSkillCap(pCharData, pProfile->Level, pProfile->Class, nSkill, true, true, true);
					return true;
				}
			}
		}
		return false;

	case Ability:
		Dest.Type = pStringType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				if (int nSkill = GetIntFromString(Index, 0))
				{
					if (bool bActivated = pCSkillMgr->IsActivatedSkill(nSkill))
					{
						int nToken = pCSkillMgr->GetNameToken(nSkill);

						if (const char* thename = pStringTable->getString(nToken))
						{
							strcpy_s(DataTypeTemp, thename);
							Dest.Ptr = &DataTypeTemp[0];
							Dest.Type = pStringType;
							return true;
						}
					}
				}
				return false;
			}

			// name
			for (int i = 0; i < NUM_SKILLS; i++)
			{
				int nToken = pCSkillMgr->GetNameToken(i);

				if (const char* thename = pStringTable->getString(nToken))
				{
					if (!_stricmp(Index, thename))
					{
						if (bool bActivated = pCSkillMgr->IsActivatedSkill(i))
						{
							Dest.DWord = i;
							Dest.Type = pIntType;
							return true;
						}

						break;
					}
				}
			}
		}
		return false;

	case AbilityReady:
		Dest.DWord = false;
		Dest.Type = pBoolType;

		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// numeric
			if (int nSkill = GetIntFromString(Index, 0))
			{
				if (bool bActivated = pCSkillMgr->IsActivatedSkill(nSkill))
				{
					Dest.DWord = pCSkillMgr->IsAvailable(nSkill);
				}
			}
			return true;
		}

		// name
		for (int i = 0; i < NUM_SKILLS; i++)
		{
			int nToken = pCSkillMgr->GetNameToken(i);

			if (const char* thename = pStringTable->getString(nToken))
			{
				if (!_stricmp(Index, thename))
				{
					if (bool bActivated = pCSkillMgr->IsActivatedSkill(i))
					{
						Dest.DWord = pCSkillMgr->IsAvailable(i);
					}
					break;
				}
			}
		}

		return true;

	case RangedReady:
		Dest.DWord = gbRangedAttackReady;
		Dest.Type = pBoolType;
		return true;

	case AltTimerReady:
		Dest.DWord = 1; // this is broken and should be fixed or removed.
		Dest.Type = pBoolType;
		return true;

	case Book:
		Dest.Type = pSpellType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				int nSpell = GetIntFromString(Index, 0) - 1;
				if (nSpell < 0)
					return false;

				if (nSpell < NUM_BOOK_SLOTS)
				{
					if (Dest.Ptr = GetSpellByID(pProfile->SpellBook[nSpell]))
					{
						Dest.Type = pSpellType;
						return true;
					}
				}
			}
			else
			{
				// name
				for (int nSpell = 0; nSpell < NUM_BOOK_SLOTS; nSpell++)
				{
					if (pProfile->SpellBook[nSpell] != -1)
					{
						if (!_stricmp(GetSpellNameByID(pProfile->SpellBook[nSpell]), Index))
						{
							Dest.DWord = nSpell + 1;
							Dest.Type = pIntType;
							return true;
						}
					}
				}
			}
		}
		return false;

	case ItemReady: {
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		CONTENTS* pCont = nullptr;

		if (pDisplay && pLocalPlayer && Index[0])
		{
			if (IsNumber(Index))
			{
				pCont = FindItemByID(GetIntFromString(Index, 0));
			}
			else
			{
				if (char* pName = Index)
				{
					bool bExact = false;
					if (*pName == '=')
					{
						bExact = true;
						pName++;
					}

					pCont = FindItemByName(pName, bExact);
				}
			}

			if (pCont)
			{
				if (PITEMINFO pIteminf = GetItemFromContents(pCont))
				{
					if (pIteminf->Clicky.TimerID != -1)
					{
						uint32_t timer = GetItemTimer(pCont);
						if (timer == 0)
							Dest.DWord = 1;
					}
					else if (pIteminf->Clicky.SpellID != -1)
					{
						Dest.DWord = 1; // insta-click or instant recast
					}
				}
			}
		}
		return true;
	}

	case BardSongPlaying:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pCastSpellWnd && pCastSpellWnd->IsBardSongPlaying())
		{
			Dest.DWord = 1;
		}
		return true;

	case SpellReady:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pCastingWnd && pCastingWnd->IsVisible())
		{
			return true;
		}

		if (pCastSpellWnd && pCastSpellWnd->IsBardSongPlaying())
		{
			Dest.DWord = 1;
			return true;
		}

		if (pDisplay && pLocalPlayer && Index[0])
		{
			CDISPLAY* pDisp = reinterpret_cast<CDISPLAY*>(pDisplay);

			if (IsNumber(Index))
			{
				// numeric
				int nGem = GetIntFromString(Index, 0) - 1;
				if (nGem < 0 || nGem > NUM_SPELL_GEMS)
					return false;

				if (GetSpellByID(GetMemorizedSpell(nGem)))
				{
					if (pDisp->TimeStamp > pChar->pSpawn->SpellGemETA[nGem]
						&& (int)pDisp->TimeStamp > pChar->pSpawn->GetSpellCooldownETA())
					{
						Dest.DWord = 1;
					}
					return true;
				}
			}
			else
			{
				for (int nGem = 0; nGem < NUM_SPELL_GEMS; nGem++)
				{
					if (SPELL* pSpell = GetSpellByID(GetMemorizedSpell(nGem)))
					{
						if (!_stricmp(Index, pSpell->Name))
						{
							if (pDisp->TimeStamp > pChar->pSpawn->SpellGemETA[nGem]
								&& (int)pDisp->TimeStamp > pChar->pSpawn->GetSpellCooldownETA())
							{
								Dest.DWord = 1;
							}
							return true;
						}
					}
				}
			}
		}
		return true;

	case PetBuff:
		Dest.Type = pSpellType;
		if (!Index[0] || !pPetInfoWnd)
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0)
				return false;
			if (nBuff > NUM_BUFF_SLOTS)
				return false;

			if (pPetInfoWnd->Buff[nBuff] == -1 || pPetInfoWnd->Buff[nBuff] == 0)
				return false;

			if (Dest.Ptr = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
			{
				Dest.Type = pSpellType;
				return true;
			}
		}
		else
		{
			for (int nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
			{
				if (SPELL* pSpell = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
				{
					if (!_stricmp(Index, pSpell->Name))
					{
						Dest.DWord = nBuff + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
			}
		}
		return false;

	case Stunned:
		Dest.DWord = (pChar->Stunned == 1);
		Dest.Type = pBoolType;
		return true;

	case LargestFreeInventory:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pProfile->pInventoryArray && pProfile->pInventoryArray->InventoryArray)
		{
			for (int slot = BAG_SLOT_START; slot < NUM_INV_SLOTS; slot++)
			{
				if (CONTENTS* pItem = pProfile->pInventoryArray->InventoryArray[slot])
				{
					if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK
						&& GetItemFromContents(pItem)->SizeCapacity > Dest.DWord)
					{
						for (int pslot = 0; pslot < (GetItemFromContents(pItem)->Slots); pslot++)
						{
							if (!pItem->Contents.ContainedItems.pItems || !pItem->GetContent(pslot))
							{
								Dest.DWord = GetItemFromContents(pItem)->SizeCapacity;
								break; // break the loop for this pack
							}
						}
					}
				}
				else
				{
					Dest.DWord = 4;
					return true;
				}
			}
		}
		return true;
	}

	case FreeInventory:
	{
		int nSize = 0;
		if (Index[0])
		{
			nSize = GetIntFromString(Index, 0);
			if (nSize > 4)
				nSize = 4;
		}

		Dest.DWord = GetFreeInventory(nSize);
		Dest.Type = pIntType;
		return true;
	}

	case Drunk:
		Dest.DWord = pProfile->Drunkenness;
		Dest.Type = pIntType;
		return true;

	case TargetOfTarget:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pLocalPlayer && pChar->pSpawn)
		{
			if (Dest.Ptr = GetSpawnByID(pChar->pSpawn->TargetOfTarget))
			{
				return true;
			}
		}
		return false;

	case RaidAssistTarget:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pLocalPlayer)
		{
			if (Index[0] && IsNumber(Index))
			{
				int index = GetIntFromString(Index, 0) - 1;
				if (index < 0)
					return false;
				if (index >= 3)
					return false;

				if (Dest.Ptr = (SPAWNINFO*)GetSpawnByID(GetRaidMainAssistTargetID(index)))
				{
					return true;
				}
			}
		}
		return false;

	case GroupAssistTarget:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && GetCharInfo()->pSpawn)
		{
			if (Dest.Ptr = (SPAWNINFO*)GetSpawnByID(GetGroupMainAssistTargetID()))
			{
				return true;
			}
		}
		return false;

	case RaidMarkNPC:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pChar->pSpawn)
		{
			if (Index[0] && IsNumber(Index))
			{
				int index = GetIntFromString(Index, 0) - 1;
				if (index < 0)
					return false;
				if (index >= 3)
					return false;
				if (Dest.Ptr = GetSpawnByID(pChar->pSpawn->RaidMarkNPC[index]))
				{
					return true;
				}
			}
		}
		return false;

	case GroupMarkNPC:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pChar->pSpawn)
		{
			if (Index[0] && IsNumber(Index))
			{
				int index = GetIntFromString(Index, 0) - 1;
				if (index < 0)
					return false;
				if (index >= 3)
					return false;

				if (Dest.Ptr = GetSpawnByID(pChar->pSpawn->GroupMarkNPC[index]))
				{
					return true;
				}
			}
		}
		return false;

	case STR:
		Dest.DWord = pChar->STR;
		Dest.Type = pIntType;
		return true;

	case STA:
		Dest.DWord = pChar->STA;
		Dest.Type = pIntType;
		return true;

	case AGI:
		Dest.DWord = pChar->AGI;
		Dest.Type = pIntType;
		return true;

	case DEX:
		Dest.DWord = pChar->DEX;
		Dest.Type = pIntType;
		return true;

	case WIS:
		Dest.DWord = pChar->WIS;
		Dest.Type = pIntType;
		return true;

	case INT:
		Dest.DWord = pChar->INT;
		Dest.Type = pIntType;
		return true;

	case CHA:
		Dest.DWord = pChar->CHA;
		Dest.Type = pIntType;
		return true;

	case LCK:
		Dest.DWord = pChar->LCK;
		Dest.Type = pIntType;
		return true;

	case svMagic:
		Dest.DWord = pChar->SaveMagic;
		Dest.Type = pIntType;
		return true;

	case svFire:
		Dest.DWord = pChar->SaveFire;
		Dest.Type = pIntType;
		return true;

	case svCold:
		Dest.DWord = pChar->SaveCold;
		Dest.Type = pIntType;
		return true;

	case svPoison:
		Dest.DWord = pChar->SavePoison;
		Dest.Type = pIntType;
		return true;

	case svDisease:
		Dest.DWord = pChar->SaveDisease;
		Dest.Type = pIntType;
		return true;

	case CurrentWeight:
		Dest.DWord = pChar->CurrWeight;
		Dest.Type = pIntType;
		return true;

	case AAPointsSpent:
		Dest.DWord = pProfile->AAPointsSpent;
		Dest.Type = pIntType;
		return true;

	case AAPointsTotal:
		Dest.DWord = pProfile->AAPointsSpent + pProfile->AAPoints;
		Dest.Type = pIntType;
		return true;

	case AAPointsAssigned:
		Dest.DWord = pProfile->AAPointsAssigned[0];
		Dest.Type = pIntType;
		return true;

	case TributeActive:
		Dest.DWord = *pTributeActive;
		Dest.Type = pBoolType;
		return true;

	case Running:
		Dest.DWord = (*EQADDR_RUNWALKSTATE);
		Dest.Type = pBoolType;
		return true;

	case GroupSize:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!pChar->pGroupInfo)
			return false;

		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
				Dest.DWord++;
		}

		// if we have at least one other group member, count self.
		if (Dest.DWord)
			Dest.DWord++;
		return true;

	case TributeTimer:
		Dest.DWord = pChar->TributeTimer / 60 / 100;
		Dest.Type = pTicksType;
		return true;

	case RadiantCrystals:
		Dest.DWord = pChar->RadiantCrystals;
		Dest.Type = pIntType;
		return true;

	case EbonCrystals:
		Dest.DWord = pChar->EbonCrystals;
		Dest.Type = pIntType;
		return true;

	case Shrouded:
		Dest.DWord = pProfile->Shrouded;
		Dest.Type = pBoolType;
		return true;

	case AutoFire:
		Dest.DWord = gAutoFire;
		Dest.Type = pBoolType;
		return true;

	case Language: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		int nLang = 0;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			nLang = GetIntFromString(Index, 0) - 1;
			if (nLang < 0)
				return false;
			strcpy_s(DataTypeTemp, pEverQuest->GetLangDesc(nLang));
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}
		else
		{
			nLang = GetLanguageIDByName(Index) - 1;
		}

		if (nLang < 0 || nLang >= 25)
			return false;
		Dest.DWord = nLang;
		return true;
	}

	case Aura:
		Dest.Type = pAuraType;

		if (!pAuraMgr)
			return false;

		if (pAuraMgr->Auras.IsEmpty())
			return false;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int n = GetIntFromString(Index, pAuraMgr->Auras.GetLength() + 1);
				if (n > pAuraMgr->Auras.GetLength())
					return false;
				n--;
				Dest.Ptr = &pAuraMgr->Auras[n];
				Dest.HighPart = n;
				return true;
			}

			for (int n = 0; n < pAuraMgr->Auras.GetLength(); n++)
			{
				if (!_strnicmp(Index, pAuraMgr->Auras[n].Name, strlen(Index)))
				{
					Dest.Ptr = &pAuraMgr->Auras[n];
					Dest.HighPart = n;
					return true;
				}
			}
		}
		else
		{
			Dest.Ptr = &pAuraMgr->Auras[0];
			Dest.HighPart = 0;
			return true;
		}
		return false;

	case LAMarkNPC:
		Dest.DWord = 3;
		Dest.Type = pIntType;
		return true;

	case LANPCHealth:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case LADelegateMA:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case LADelegateMarkNPC:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case LAInspectBuffs:
		Dest.DWord = 2;
		Dest.Type = pIntType;
		return true;

	case LASpellAwareness:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case LAOffenseEnhancement:
		Dest.DWord = 5;
		Dest.Type = pIntType;
		return true;

	case LAManaEnhancement:
		Dest.DWord = 3;
		Dest.Type = pIntType;
		return true;

	case LAHealthEnhancement:
		Dest.DWord = 3;
		Dest.Type = pIntType;
		return true;

	case LAHealthRegen:
		Dest.DWord = 3;
		Dest.Type = pIntType;
		return true;

	case LAFindPathPC:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case LAHoTT:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case ActiveFavorCost:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (*pTributeActive)
		{
			Dest.Int = pEQMisc->GetActiveFavorCost();
			return true;
		}
		return false;

	case CombatState:
		Dest.Type = pStringType;
		if (!pPlayerWnd)
			return false;

		switch (pPlayerWnd->CombatState)
		{
		case eCombatState_Combat:
			if (pPlayerWnd->GetChildItem("PW_CombatStateAnim"))
			{
				strcpy_s(DataTypeTemp, "COMBAT");
				break;
			}
			strcpy_s(DataTypeTemp, "NULL");
			break;

		case eCombatState_Debuff:
			strcpy_s(DataTypeTemp, "DEBUFFED");
			break;

		case eCombatState_Timer:
			strcpy_s(DataTypeTemp, "COOLDOWN");
			break;

		case eCombatState_Standing:
			strcpy_s(DataTypeTemp, "ACTIVE");
			break;

		case eCombatState_Regen:
			strcpy_s(DataTypeTemp, "RESTING");
			break;

		default:
			strcpy_s(DataTypeTemp, "UNKNOWN");
			break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case svCorruption:
		Dest.DWord = pChar->SaveCorruption;
		Dest.Type = pIntType;
		return true;

	case svPrismatic:
		Dest.DWord = (pChar->SaveMagic + pChar->SaveFire + pChar->SaveCold + pChar->SavePoison + pChar->SaveDisease) / 5;
		Dest.Type = pIntType;
		return true;

	case svChromatic: {
		int lowSave;
		lowSave = pChar->SaveMagic;
		if (lowSave > pChar->SaveFire)
			lowSave = pChar->SaveFire;
		if (lowSave > pChar->SaveCold)
			lowSave = pChar->SaveCold;
		if (lowSave > pChar->SavePoison)
			lowSave = pChar->SavePoison;
		if (lowSave > pChar->SaveDisease)
			lowSave = pChar->SaveDisease;

		Dest.Int = lowSave;
		Dest.Type = pIntType;
		return true;
	}

	case Doubloons:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DOUBLOONS);
		Dest.Type = pIntType;
		return true;

	case Orux:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ORUX);
		Dest.Type = pIntType;
		return true;

	case Phosphenes:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PHOSPHENES);
		Dest.Type = pIntType;
		return true;

	case Phosphites:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PHOSPHITES);
		Dest.Type = pIntType;
		return true;

	case Faycites:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FAYCITES);
		Dest.Type = pIntType;
		return true;

	case Chronobines:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CHRONOBINES);
		Dest.Type = pIntType;
		return true;

	case Commemoratives:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_COMMEMORATIVE_COINS);
		Dest.Type = pIntType;
		return true;

	case Nobles:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_NOBLES);
		Dest.Type = pIntType;
		return true;

	case Fists:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FISTSOFBAYLE);
		Dest.Type = pIntType;
		return true;

	case EnergyCrystals:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ENERGYCRYSTALS);
		Dest.Type = pIntType;
		return true;

	case PiecesofEight:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PIECESOFEIGHT);
		Dest.Type = pIntType;
		return true;

	case SilverTokens:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SILVERTOKENS);
		Dest.Type = pIntType;
		return true;

	case GoldTokens:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_GOLDTOKENS);
		Dest.Type = pIntType;
		return true;

	case McKenzie:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MCKENZIE);
		Dest.Type = pIntType;
		return true;

	case Bayle:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BAYLE);
		Dest.Type = pIntType;
		return true;

	case Reclamation:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_RECLAMATION);
		Dest.Type = pIntType;
		return true;

	case Brellium:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BRELLIUM);
		Dest.Type = pIntType;
		return true;

	case Motes:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MOTES);
		Dest.Type = pIntType;
		return true;

	case RebellionChits:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_REBELLIONCHITS);
		Dest.Type = pIntType;
		return true;

	case DiamondCoins:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DIAMONDCOINS);
		Dest.Type = pIntType;
		return true;

	case BronzeFiats:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BRONZEFIATS);
		Dest.Type = pIntType;
		return true;

	case Voucher:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_VOUCHER);
		Dest.Type = pIntType;
		return true;

	case VeliumShards:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_VELIUMSHARDS);
		Dest.Type = pIntType;
		return true;

	case CrystallizedFear:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CRYSTALLIZEDFEAR);
		Dest.Type = pIntType;
		return true;

	case ShadowStones:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SHADOWSTONES);
		Dest.Type = pIntType;
		return true;

	case DreadStones:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DREADSTONES);
		Dest.Type = pIntType;
		return true;

	case MarksOfValor:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MARKSOFVALOR);
		Dest.Type = pIntType;
		return true;

	case MedalsOfHeroism:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MEDALSOFHEROISM);
		Dest.Type = pIntType;
		return true;

	case RemnantOfTranquility:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_REMNANTSOFTRANQUILITY);
		Dest.Type = pIntType;
		return true;

	case BifurcatedCoin:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BIFURCATEDCOIN);
		Dest.Type = pIntType;
		return true;

	case AdoptiveCoin:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ADOPTIVE);
		Dest.Type = pIntType;
		return true;

	case SathirsTradeGems:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SATHIRSTRADEGEMS);
		Dest.Type = pIntType;
		return true;

	case AncientSebilisianCoins:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ANCIENTSEBILISIANCOINS);
		Dest.Type = pIntType;
		return true;

	case BathezidTradeGems:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BATHEZIDTRADEGEMS);
		Dest.Type = pIntType;
		return true;

	case AncientDraconicCoin:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ANCIENTDRACONICCOIN);
		Dest.Type = pIntType;
		return true;

	case FetterredIfritCoins:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FETTERREDIFRITCOINS);
		Dest.Type = pIntType;
		return true;

	case EntwinedDjinnCoins:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ENTWINEDDJINNCOINS);
		Dest.Type = pIntType;
		return true;

	case CrystallizedLuck:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CRYSTALLIZEDLUCK);
		Dest.Type = pIntType;
		return true;

	case Fellowship:
		Dest.Type = pFellowshipType;
		if (pChar->pSpawn)
		{
			Dest.Ptr = &pChar->pSpawn->Fellowship;
			return true;
		}
		return false;

	case Downtime:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (pChar->DowntimeStamp)
			Dest.DWord = ((pChar->Downtime - (GetFastTime() - pChar->DowntimeStamp)) / 6) + 1;
		return true;

		// returns combined number of spell and damage "absorbment"
		// should probably split these into spell vs melee
	case Dar:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (const auto& buff : pProfile->Buff)
		{
			if (SPELL* pSpell = GetSpellByID(buff.SpellID))
			{
				if (pSpell->SpellType != 0)
				{
					int slots = GetSpellNumEffects(pSpell);

					for (int i = 0; i < slots; i++)
					{
						int attrib = GetSpellAttrib(pSpell, i);

						if (IsDamageAbsorbSPA(attrib))
						{
							for (auto buffData : buff.SlotData)
							{
								if (buffData.Slot == i)
								{
									Dest.DWord += buffData.Value;
								}
							}
						}
					}
				}
			}
		}
		return true;

		// this case adds all resist Counters and returns that, why is this useful?
		// should we split these into 4? one for each debuff?
	case TotalCounters:
		Dest.DWord = GetMyTotalSpellCounters();
		Dest.Type = pIntType;
		return true;

	case CountersDisease:
		Dest.DWord += GetMySpellCounters(SPA_DISEASE);
		Dest.Type = pIntType;
		return true;

	case CountersPoison:
		Dest.DWord = GetMySpellCounters(SPA_POISON);
		Dest.Type = pIntType;
		return true;

	case CountersCurse:
		Dest.DWord = GetMySpellCounters(SPA_CURSE);
		Dest.Type = pIntType;
		return true;

	case CountersCorruption:
		Dest.DWord = GetMySpellCounters(SPA_CORRUPTION);
		Dest.Type = pIntType;
		return true;

	case Mercenary:
		Dest.Type = pMercenaryType;
		if (pMercInfo && pMercInfo->MercSpawnId)
		{
			Dest.Ptr = GetSpawnByID(pMercInfo->MercSpawnId);
			return true;
		}
		else if (pMercInfo)
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
					strcpy_s(MercenarySpawn.Name, "NULL");
					break;
				}

				Dest.Ptr = &MercenarySpawn;
				return true;
			}
			else
			{
				if (pMercInfo->MercenaryCount >= 1)
				{
					strcpy_s(MercenarySpawn.Name, "SUSPENDED");
					Dest.Ptr = &MercenarySpawn;
					return true;
				}
				else
				{
					strcpy_s(MercenarySpawn.Name, "NULL");
					Dest.Ptr = &MercenarySpawn;
					return true;
				}
			}
		}

		return false;

	case XTargetSlots:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ExtendedTargetList* xtm = pChar->pXTargetMgr)
		{
			Dest.DWord = xtm->XTargetSlots.Count;
		}
		return true;

	case XTAggroCount:
		Dest.DWord = 0;
		if (ExtendedTargetList* xtm = pChar->pXTargetMgr)
		{
			int AggroPct = 100;
			if (IsNumber(Index))
			{
				AggroPct = GetIntFromString(Index, AggroPct);
				if (AggroPct < 1 || AggroPct > 100)
				{
					AggroPct = 100;
				}
			}

			if (pAggroInfo)
			{
				for (int i = 0; i < xtm->XTargetSlots.Count; i++)
				{
					XTARGETSLOT xts = xtm->XTargetSlots[i];
					uint32_t spID = xts.SpawnID;

					if (spID && xts.xTargetType == XTARGET_AUTO_HATER)
					{
						if (SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(spID))
						{
							if (pTarget && ((SPAWNINFO*)pTarget)->SpawnID == pSpawn->SpawnID)
								continue;

							if (pSpawn->Type == SPAWN_NPC)
							{
								uint16_t aggropct = pAggroInfo->aggroData[AD_xTarget1 + i].AggroPct;

								if (aggropct < AggroPct)
								{
									Dest.DWord++;
								}
							}
						}
					}
				}
			}
		}

		Dest.Type = pIntType;
		return true;

	case XTHaterCount:
		Dest.DWord = 0;
		if (ExtendedTargetList* xtm = pChar->pXTargetMgr)
		{
			if (pAggroInfo)
			{
				for (int i = 0; i < xtm->XTargetSlots.Count; i++)
				{
					XTARGETSLOT xts = xtm->XTargetSlots[i];
					uint32_t spID = xts.SpawnID;

					if (spID && xts.xTargetType == XTARGET_AUTO_HATER)
					{
						if (SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(spID))
						{
							if (pTarget && ((SPAWNINFO*)pTarget)->SpawnID == pSpawn->SpawnID)
								continue;

							if (pSpawn->Type == SPAWN_NPC)
							{
								Dest.DWord++;
							}
						}
					}
				}
			}
		}

		Dest.Type = pIntType;
		return true;

	case XTarget:
		Dest.DWord = 0;
		Dest.Type = pXTargetType;

		if (ExtendedTargetList* xtm = pChar->pXTargetMgr)
		{
			if (xtm->XTargetSlots.Count)
			{
				if (Index[0])
				{
					if (IsNumber(Index))
					{
						int index = GetIntFromString(Index, 0) - 1;
						if (index >= 0 && index < (int)xtm->XTargetSlots.Count)
						{
							Dest.DWord = index;
							Dest.Type = pXTargetType;
							return true;
						}
					}
					else
					{
						for (int n = 0; n < xtm->XTargetSlots.Count; n++)
						{
							XTARGETSLOT& xts = xtm->XTargetSlots[n];

							if (xts.xTargetType && xts.XTargetSlotStatus && !_stricmp(Index, xts.Name))
							{
								Dest.DWord = n;
								Dest.Type = pXTargetType;
								return true;
							}
						}
					}
				}
				else
				{
					int count = 0;
					for (int n = 0; n < xtm->XTargetSlots.Count; n++)
					{
						XTARGETSLOT& xts = xtm->XTargetSlots[n];
						if (xts.xTargetType && xts.XTargetSlotStatus)
						{
							count++;
						}
					}

					Dest.DWord = count;
					Dest.Type = pIntType;
					return true;
				}
			}
		}
		return false;

	case Haste: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		// TODO: Is this GetCharInfo Redundant? Remove if so.
		if (CHARINFO* pCharInfo = GetCharInfo())
		{
			// TODO: Replace magic constant with enum
			Dest.DWord = pCharData->TotalEffect(0xb, true, 0, true, true);
			return true;
		}
		return false;
	}

	case SPA: {
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// TODO: Is this GetCharInfo Redundant? Remove if so.
			if (CHARINFO* pCharInfo = GetCharInfo())
			{
				if (pCharInfo->vtable2) {
					Dest.DWord = pCharData->TotalEffect(GetIntFromString(Index, 0), true, 0, true, true);
					return true;
				}
			}
		}
		return false;
	}

	case MercenaryStance:
		strcpy_s(DataTypeTemp, "NULL");
		if (pMercInfo->HaveMerc)
		{
			for (int n = 0; n < pMercInfo->NumStances; n++)
			{
				if (pMercInfo->pMercStanceData[n]->nStance == pMercInfo->ActiveStance)
				{
					strcpy_s(DataTypeTemp, pCDBStr->GetString(pMercInfo->pMercStanceData[n]->nDbStance, eMercenaryStanceName));
					break;
				}
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case GemTimer:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// number
			int nGem = GetIntFromString(Index, 0) - 1;
			if (nGem < 0)
				return false;

			if (nGem < NUM_SPELL_GEMS)
			{
				if (GetMemorizedSpell(nGem) != 0xFFFFFFFF)
				{
					Dest.UInt64 = GetSpellGemTimer(nGem);
					return true;
				}
			}
		}
		else
		{
			// name
			for (int nGem = 0; nGem < NUM_SPELL_GEMS; nGem++)
			{
				if (SPELL* pSpell = GetSpellByID(GetMemorizedSpell(nGem)))
				{
					if (!_stricmp(Index, pSpell->Name))
					{
						Dest.UInt64 = GetSpellGemTimer(nGem);
						return true;
					}
				}
			}
		}
		return false;

	case HaveExpansion:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nExpansion = GetIntFromString(Index, 0);
			if (nExpansion > NUM_EXPANSIONS)
				return true;
			Dest.DWord = GetCharInfo()->ExpansionFlags & EQ_EXPANSION(nExpansion);
		}
		else
		{
			for (int n = 0; n < NUM_EXPANSIONS; n++)
			{
				if (!_stricmp(Index, szExpansions[n]))
				{
					Dest.DWord = GetCharInfo()->ExpansionFlags & EQ_EXPANSION(n + 1);
					return true;
				}
			}
		}
		return true;

	case PctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Player].AggroPct;
			return true;
		}
		return false;

	case SecondaryPctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Secondary].AggroPct;
			return true;
		}
		return false;

	case SecondaryAggroPlayer:
		Dest.Type = pSpawnType;
		if (pAggroInfo && pAggroInfo->AggroSecondaryID)
		{
			Dest.Ptr = GetSpawnByID(pAggroInfo->AggroSecondaryID);
			return true;
		}
		return false;

	case AggroLock:
		Dest.Type = pSpawnType;
		if (pAggroInfo && pAggroInfo->AggroLockID)
		{
			Dest.Ptr = GetSpawnByID(pAggroInfo->AggroLockID);
			return true;
		}
		return false;

	case ZoneBound:
		Dest.Type = pZoneType;
		if (const PcProfile* pProfile = GetPcProfile())
		{
			if (pProfile->BoundLocations[0].ZoneBoundID)
			{
				Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[pProfile->BoundLocations[0].ZoneBoundID];
				return true;
			}
		}
		return false;

	case ZoneBoundX:
		Dest.Float = 0;
		Dest.Type = pFloatType;
		if (const PcProfile* pProfile = GetPcProfile())
		{
			Dest.Float = pProfile->BoundLocations[0].ZoneBoundX;
		}
		return true;

	case ZoneBoundY:
		Dest.Float = 0;
		Dest.Type = pFloatType;
		if (const PcProfile* pProfile = GetPcProfile())
		{
			Dest.Float = pProfile->BoundLocations[0].ZoneBoundY;
		}
		return true;

	case ZoneBoundZ:
		Dest.Float = 0;
		Dest.Type = pFloatType;
		if (const PcProfile* pProfile = GetPcProfile())
		{
			Dest.Float = pProfile->BoundLocations[0].ZoneBoundZ;
		}
		return true;

	case PctMercAAExp:
		// this is how it looks like the client is doing it in the disasm...
		Dest.Float = (float)((pChar->MercAAExp + 5) / 10);
		Dest.Type = pFloatType;
		return true;

	case MercAAExp:
		Dest.Int64 = pChar->MercAAExp;
		Dest.Type = pInt64Type;
		return true;

	case Krono:
		Dest.DWord = pChar->Krono;
		Dest.Type = pIntType;
		return true;

	case Subscription:
		strcpy_s(DataTypeTemp, "UNKNOWN");

		// TODO: Fix this. Its a struct not an int*
		if (EQADDR_SUBSCRIPTIONTYPE && *EQADDR_SUBSCRIPTIONTYPE)
		{
			int dwsubtype = *(int*)EQADDR_SUBSCRIPTIONTYPE;
			if (dwsubtype)
			{
				uint8_t subtype = *(uint8_t*)dwsubtype;
				switch (subtype)
				{
				case MembershipFreeToPlay:
					strcpy_s(DataTypeTemp, "FREE");
					break;
				case MembershipSilver:
					strcpy_s(DataTypeTemp, "SILVER");
					break;
				case MembershipGold:
					strcpy_s(DataTypeTemp, "GOLD");
					break;
				}
			}
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case AltCurrency:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			Dest.DWord = pPlayerPointManager->GetAltCurrency(GetIntFromString(Index, 0));
			return true;
		}
		else
		{
			int nCurrency = GetCurrencyIDByName(Index);
			if (nCurrency < 0)
				return false;
			Dest.DWord = pPlayerPointManager->GetAltCurrency(nCurrency);
			return true;
		}
		return false;

	case Slowed:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(11, false)) != -1) // Slowed
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Rooted:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(99, false)) != -1) // Root
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Mezzed:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(31, false)) != -1)//Entrall
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Crippled:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySubCat("Disempowering")) != -1)
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Maloed:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySubCat("Resist Debuffs", (1 << Shaman) + (1 << Mage))) != -1)
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Tashed:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySubCat("Resist Debuffs", 1 << Enchanter)) != -1)
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Snared:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(3, false)) != -1) // Movement Rate
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Hasted:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(11, true)) != -1) // Haste
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case LastZoned:
		Dest.UInt64 = LastEnteredZone;
		Dest.Type = pTimeStampType;
		return true;

	case Zoning: {
		if (LastEnteredZone == 0) // when people reload mq
		{
			LastEnteredZone = MQGetTickCount64();
			OldLastEnteredZone = LastEnteredZone;
		}

		// FIXME: SIDE EFFECTS
		bool bZoning = false;
		if (OldLastEnteredZone != LastEnteredZone)
		{
			OldLastEnteredZone = LastEnteredZone;
			bZoning = true;
		}

		Dest.DWord = bZoning;
		Dest.Type = pBoolType;
		return true;
	}

	case DSed:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(59, true)) != -1) // Damage Shield
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case RevDSed:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(121, true)) != -1) // Reverse Damage Shield
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Charmed:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(22, false)) != -1) // Charm
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Aego:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			for (int nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
			{
				if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
				{
					if (IsAegoSpell(pSpell))
					{
						Dest.Ptr = &pProfile->Buff[nBuff];
						return true;
					}
				}
			}
		}
		return false;

	case Skin:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Druid)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 46)
						{
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Druid, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Focus:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = 0;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Shaman)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 87)
						{
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Shaman, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Regen:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(0, true)) != -1) // HP Regen
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if ((((EQ_Spell*)pSpell)->SpellAffectBase(0) > 0) && (!IsSpellUsableForClass(pSpell, 1 << Beastlord)))
						{
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffBySPA(0, true, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Diseased:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(35, false)) != -1) // Disease Counter
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Poisoned:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(36, false)) != -1) // Poison Counter
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Cursed:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(116, false)) != -1) // Curse Counter
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Corrupted:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(369, false)) != -1)//Corruption Counter
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Symbol:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Cleric)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 112)
						{
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Cleric, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Clarity:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(15, true)) != -1) // Mana Regen
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if ((((EQ_Spell*)pSpell)->SpellAffectBase(15) > 0) && (IsSpellUsableForClass(pSpell, 1 << Enchanter)))
						{
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffBySPA(15, true, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Pred:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(95, 1 << Ranger)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 7)
						{
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((Dest.Int = GetSelfBuffByCategory(95, 1 << Ranger, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Strength:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Ranger)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 47)
						{
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Ranger, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Brells:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Paladin)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 47)
						{
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Paladin, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case SV:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(79, 1 << Beastlord)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 59)
						{
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(79, 1 << Beastlord, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case SE:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(79, 1 << Beastlord)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 44)
						{
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(79, 1 << Beastlord, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case HybridHP:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Ranger)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 46)
						{
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Ranger, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Growth:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Druid)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 141)
						{
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Druid, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Shining:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(125, 1 << Cleric)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 62)
						{
							if (((EQ_Spell*)pSpell)->SpellAffectBase(162))
							{
								Dest.Ptr = &pProfile->Buff[nBuff];
								return true;
							}
						}
					}

					if ((nBuff = GetSelfBuffByCategory(125, 1 << Cleric, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case InInstance:
		Dest.DWord = 0;
		if (pChar->pSpawn)
		{
			if (int zoneid = pChar->pSpawn->GetZoneID())
			{
				if (uint16_t instance = HIWORD(zoneid))
					Dest.DWord = true;
			}
		}
		Dest.Type = pBoolType;
		return true;

	case Instance:
		Dest.DWord = 0;
		if (pChar->pSpawn)
			Dest.DWord = HIWORD(pChar->pSpawn->GetZoneID());
		Dest.Type = pIntType;
		return true;

	case MercListInfo: {
		Dest.Type = pStringType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, pMercInfo->MercenaryCount + 1);
			if (nIndex > pMercInfo->MercenaryCount)
				return false;

			std::map<int, MercDesc> mercDescMap;
			GetAllMercDesc(mercDescMap);

			if (mercDescMap.find(nIndex - 1) != mercDescMap.end())
			{
				strcpy_s(DataTypeTemp, mercDescMap[nIndex - 1].Type.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			}
		}
		else
		{
			std::map<int, MercDesc> descmap;
			GetAllMercDesc(descmap);

			for (auto& [index, desc] : descmap)
			{
				if (!_stricmp(Index, desc.Type.c_str()))
				{
					Dest.DWord = index + 1;
					Dest.Type = pIntType;
					return true;
				}
			}
		}
		return false;
	}

	case UseAdvancedLooting:
		Dest.DWord = pChar->UseAdvancedLooting;
		Dest.Type = pBoolType;
		return true;

	case SpellInCooldown:
		Dest.DWord = (int)((CDISPLAY*)pDisplay)->TimeStamp <= ((SPAWNINFO*)pLocalPlayer)->GetSpellCooldownETA();
		Dest.Type = pBoolType;
		return true;

	case AssistComplete:
		Dest.DWord = gbAssistComplete == AS_AssistReceived;
		Dest.Type = pBoolType;
		return true;

	case NumGems:
		Dest.DWord = 8;
		if (pCastSpellWnd)
		{
			char szWnd[32] = { 0 };
			for (int i = 8; i < NUM_SPELL_GEMS; i++)
			{
				sprintf_s(szWnd, "CSPW_Spell%d", i);
				if (CXWnd* wnd = pCastSpellWnd->GetChildItem(szWnd))
				{
					if (wnd->IsVisible() == 1)
					{
						Dest.DWord++;
					}
				}
			}
		}

		Dest.Type = pIntType;
		return true;

	case GuildID:
		Dest.UInt64 = pChar->GuildID;
		Dest.Type = pInt64Type;
		return true;

	case ExpansionFlags:
		Dest.DWord = pChar->ExpansionFlags;
		Dest.Type = pIntType;
		return true;

	case BoundLocation:
		Dest.DWord = 0;
		Dest.Type = pWorldLocationType;

		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0);
			if (index < 0)
				index = 0;
			if (index > 4)
				index = 4;
			Dest.DWord = index;
			return true;
		}
		return false;

	case AutoSkill:
		Dest.Type = pSkillType;
		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index < 0)
				index = 0;
			if (index > 1)
				index = 1;

			int skillid = gAutoSkill.Skill[index];
			if (skillid > 0 && skillid < NUM_SKILLS)
			{
				Dest.Ptr = &pSkillMgr->pSkill[skillid];
				return true;
			}
		}
		return false;

	case BaseSTR:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			Dest.DWord = pProfile->BaseSTR;
			return true;
		}
		return false;

	case BaseSTA:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			Dest.DWord = pProfile->BaseSTA;
			return true;
		}
		return false;

	case BaseAGI:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			Dest.DWord = pProfile->BaseAGI;
			return true;
		}
		return false;

	case BaseDEX:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			Dest.DWord = pProfile->BaseDEX;
			return true;
		}
		return false;

	case BaseWIS:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			Dest.DWord = pProfile->BaseWIS;
			return true;
		}
		return false;

	case BaseINT:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			Dest.DWord = pProfile->BaseINT;
			return true;
		}
		return false;

	case BaseCHA:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			Dest.DWord = pProfile->BaseCHA;
			return true;
		}
		return false;

	case Beneficial:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			for (int i = 0; i < NUM_BUFF_SLOTS; i++)
			{
				if ((pProfile->Buff[i].SpellID == -1) || (pProfile->Buff[i].SpellID == 0))
					continue;

				if (SPELL* pSpell = GetSpellByID(pProfile->Buff[i].SpellID))
				{
					if (pSpell->SpellType != 0)
					{
						Dest.Int = i;
						return true;
					}
				}
			}
		}
		return false;

	case CursorKrono:
		Dest.DWord = pChar->CursorKrono;
		Dest.Type = pIntType;
		return true;

	case MercAAPoints:
		Dest.DWord = pChar->MercAAPoints;
		Dest.Type = pIntType;
		return true;

	case MercAAPointsSpent:
		Dest.DWord = pChar->MercAAPointsSpent;
		Dest.Type = pIntType;
		return true;

	case Bandolier:
		Dest.DWord = 0;
		Dest.Type = pBandolierType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			if (IsNumber(Index)) {
				int index = GetIntFromString(Index, 0);
				index--;
				if (index < 0)
					index = 0;
				if (index > 19)
					index = 19;
				Dest.DWord = index;
				return true;
			}
			else
			{
				for (int index = 0; index < 20; index++)
				{
					if (!_stricmp(Index, pProfile->Bandolier[index].Name))
					{
						Dest.DWord = index;
						return true;
					}
				}
			}
		}
		return false;

	case Feared:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(23, false)) != -1) // Feared
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Silenced:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(96, false)) != -1) // Silenced
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Invulnerable:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(40, false)) != -1) // Invulnerable
			{
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}

			if ((nBuff = GetSelfShortBuffBySPA(40, false)) != -1) // Invulnerable
			{
				Dest.Ptr = &pProfile->ShortBuff[nBuff];
				return true;
			}
		}
		return false;

	case Dotted:
		Dest.Type = pBuffType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(0, false)) != -1) // HP Mod
			{
				int slotnum = nBuff;
				while (slotnum < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[nBuff]))
					{
						if (((EQ_Spell*)pSpell)->IsDetrimentalSpell() && ((EQ_Spell*)pSpell)->IsDoTSpell())
						{
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetTargetBuffBySPA(0, false, ++slotnum)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

		//end of MQ2CharacterType
	}
	return false;
}

//----------------------------------------------------------------------------
// MQ2SpellType

bool MQ2SpellType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	SPELL* pSpell = static_cast<SPELL*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	// FIXME: Remove this!! We shouldn't ever need it!!!
	if (IsBadReadPtr((void*)pSpell, 4))
		return false;

	MQTypeMember* pMember = MQ2SpellType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<SpellMembers>(pMember->ID))
	{
	case ID:
		Dest.DWord = pSpell->ID;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, pSpell->Name);
		Dest.Ptr = &DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case Level:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (!Index[0] && GetCharInfo()->pSpawn)
		{
			Dest.DWord = pSpell->ClassLevel[GetCharInfo()->pSpawn->mActorClient.Class];
			return true;
		}
		else
		{
			if (IsNumber(Index))
			{
				unsigned long nIndex = GetIntFromString(Index, 0);
				Dest.DWord = pSpell->ClassLevel[nIndex];
				return true;
			}
		}
		return false;

	case Mana:
		Dest.DWord = pSpell->ManaCost;
		Dest.Type = pIntType;
		return true;

	case ResistAdj:
		Dest.DWord = pSpell->ResistAdj;
		Dest.Type = pIntType;
		return true;

	case Range:
		Dest.Float = pSpell->Range;
		Dest.Type = pFloatType;
		return true;

	case AERange:
		Dest.Float = pSpell->AERange;
		Dest.Type = pFloatType;
		return true;

	case PushBack:
		Dest.Float = pSpell->PushBack;
		Dest.Type = pFloatType;
		return true;

	case CastTime:
		Dest.UInt64 = pSpell->CastTime;
		Dest.Type = pTimeStampType;
		return true;

	case RecoveryTime:
	case FizzleTime:
		Dest.UInt64 = pSpell->RecoveryTime;
		Dest.Type = pTimeStampType;
		return true;

	case RecastTime:
		Dest.UInt64 = pSpell->RecastTime;
		Dest.Type = pTimeStampType;
		return true;

	case ResistType:
		switch (pSpell->Resist)
		{
		case ResistType_Corruption: strcpy_s(DataTypeTemp, "Corruption"); break;
		case ResistType_Physical:	strcpy_s(DataTypeTemp, "Physical"); break;
		case ResistType_Prismatic: strcpy_s(DataTypeTemp, "Prismatic"); break;
		case ResistType_Chromatic: strcpy_s(DataTypeTemp, "Chromatic"); break;
		case ResistType_Disease: strcpy_s(DataTypeTemp, "Disease"); break;
		case ResistType_Poison: strcpy_s(DataTypeTemp, "Poison"); break;
		case ResistType_Cold: strcpy_s(DataTypeTemp, "Cold"); break;
		case ResistType_Fire: strcpy_s(DataTypeTemp, "Fire"); break;
		case ResistType_Magic: strcpy_s(DataTypeTemp, "Magic"); break;
		case ResistType_None: strcpy_s(DataTypeTemp, "Unresistable"); break;
		default: strcpy_s(DataTypeTemp, "Unknown"); break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellType:
		switch (pSpell->SpellType)
		{
		case SpellType_BeneficialGroupOnly: strcpy_s(DataTypeTemp, "Beneficial(Group)"); break;
		case SpellType_Beneficial: strcpy_s(DataTypeTemp, "Beneficial"); break;
		case SpellType_Detrimental: strcpy_s(DataTypeTemp, "Detrimental"); break;
		default: strcpy_s(DataTypeTemp, "Unknown"); break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TargetType:
		switch (pSpell->TargetType)
		{
		case 50: strcpy_s(DataTypeTemp, "Target_AE_No_Players_Pets"); break; // blanket of forgetfullness. beneficial, AE mem blur, with max targets
		case 47: strcpy_s(DataTypeTemp, "Pet Owner"); break;
		case 46: strcpy_s(DataTypeTemp, "Target of Target"); break;
		case 45: strcpy_s(DataTypeTemp, "Free Target"); break;
		case 44: strcpy_s(DataTypeTemp, "Beam"); break;
		case 43: strcpy_s(DataTypeTemp, "Single in Group"); break;
		case 42: strcpy_s(DataTypeTemp, "Directional AE"); break;
		case 41: strcpy_s(DataTypeTemp, "Group v2"); break;
		case 40: strcpy_s(DataTypeTemp, "AE PC v2"); break;
		case 39: strcpy_s(DataTypeTemp, "No Pets"); break;
		case 38: strcpy_s(DataTypeTemp, "Pet2"); break;
		case 37: strcpy_s(DataTypeTemp, "Caster PB NPC"); break;
		case 36: strcpy_s(DataTypeTemp, "Caster PB PC"); break;
		case 35: strcpy_s(DataTypeTemp, "Special Muramites"); break;
		case 34: strcpy_s(DataTypeTemp, "Chest"); break;
		case 33: strcpy_s(DataTypeTemp, "Hatelist2"); break;
		case 32: strcpy_s(DataTypeTemp, "Hatelist"); break;
		case 25: strcpy_s(DataTypeTemp, "AE Summoned"); break;
		case 24: strcpy_s(DataTypeTemp, "AE Undead"); break;
		case 20: strcpy_s(DataTypeTemp, "Targeted AE Tap"); break;
		case 18: strcpy_s(DataTypeTemp, "Uber Dragons"); break;
		case 17: strcpy_s(DataTypeTemp, "Uber Giants"); break;
		case 16: strcpy_s(DataTypeTemp, "Plant"); break;
		case 15: strcpy_s(DataTypeTemp, "Corpse"); break;
		case 14: strcpy_s(DataTypeTemp, "Pet"); break;
		case 13: strcpy_s(DataTypeTemp, "LifeTap"); break;
		case 11: strcpy_s(DataTypeTemp, "Summoned"); break;
		case 10: strcpy_s(DataTypeTemp, "Undead"); break;
		case  9: strcpy_s(DataTypeTemp, "Animal"); break;
		case  8: strcpy_s(DataTypeTemp, "Targeted AE"); break;
		case  6: strcpy_s(DataTypeTemp, "Self"); break;
		case  5: strcpy_s(DataTypeTemp, "Single"); break;
		case  4: strcpy_s(DataTypeTemp, "PB AE"); break;
		case  3: strcpy_s(DataTypeTemp, "Group v1"); break;
		case  2: strcpy_s(DataTypeTemp, "AE PC v1"); break;
		case  1: strcpy_s(DataTypeTemp, "Line of Sight"); break;
		default: strcpy_s(DataTypeTemp, "Unknown"); break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Skill:
		strcpy_s(DataTypeTemp, szSkills[pSpell->Skill]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case MyCastTime: {
		int64_t myaacastingtime = (int64_t)GetCastingTimeModifier((EQ_Spell*)pSpell);

		VePointer<CONTENTS> pc;
		int myfocuscastingtime = GetFocusCastingTimeModifier((EQ_Spell*)pSpell, pc, false);

		int64_t mycasttime = (int64_t)pSpell->CastTime;
		int64_t mct = myaacastingtime + myfocuscastingtime + mycasttime;

		if (pSpell->CastTime > 0 && mct < (pSpell->CastTime / 2))
			Dest.UInt64 = pSpell->CastTime / 2;
		else
			Dest.UInt64 = mct;

		Dest.Type = pTimeStampType;
		return true;
	}

	case Duration:
		Dest.DWord = GetSpellDuration(pSpell, (SPAWNINFO*)pLocalPlayer);
		Dest.Type = pTicksType;
		return true;

	case EQSpellDuration:
		Dest.DWord = EQGetSpellDuration(pSpell, NULL, false);
		Dest.Type = pTicksType;
		return true;

	case CastByMe:
		strcpy_s(DataTypeTemp, " casts Unknown Spell.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringCastByMe))
		{
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CastByOther:
		strcpy_s(DataTypeTemp, " casts Unknown Spell.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringCastByOther))
		{
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CastOnYou:
		strcpy_s(DataTypeTemp, "You feel bogus as an unknown spell accosts you.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringCastOnYou))
		{
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CastOnAnother:
		strcpy_s(DataTypeTemp, " is the victim of an unknown spell.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringCastOnAnother))
		{
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case WearOff:
		strcpy_s(DataTypeTemp, "An unknown spell is gone.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringWearOff))
		{
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CounterType:
		strcpy_s(DataTypeTemp, "None");
		for (int i = 0; i < GetSpellNumEffects(pSpell); i++)
		{
			switch (GetSpellAttrib(pSpell, i))
			{
			case SPA_DISEASE:
				strcpy_s(DataTypeTemp, "Disease");
				break;
			case SPA_POISON:
				strcpy_s(DataTypeTemp, "Poison");
				break;
			case SPA_CURSE:
				strcpy_s(DataTypeTemp, "Curse");
				break;
			case SPA_CORRUPTION:
				strcpy_s(DataTypeTemp, "Corruption");
				break;
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CounterNumber:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (int i = 0; i < GetSpellNumEffects(pSpell); i++)
		{
			int attrib = GetSpellAttrib(pSpell, i);

			if (IsSpellCountersSPA(attrib))
			{
				Dest.DWord = GetSpellBase(pSpell, i);
				return true;
			}
		}
		return true;

	case Stacks:
	case NewStacks: // stacks on self
	{
		int buffduration;
		int duration = 99999;
		duration = GetIntFromString(Index, duration);

		SPELL* thespell = pSpell;
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pLocalPlayer)
		{
			SPAWNINFO* pPlayer = (SPAWNINFO*)pLocalPlayer;
			PcClient* pPc = pPlayer->GetPcClient();
			if (pPc)
			{
				int SlotIndex = -1;
				EQ_Affect* ret = pPc->FindAffectSlot(thespell->ID, pPlayer, &SlotIndex, true, pPlayer->Level);

				if (!ret || SlotIndex == -1)
				{
					Dest.DWord = false;
				}
				else
				{
					Dest.DWord = true;
					buffduration = ret->DurationTick;

					if (GetSpellDuration(thespell, pPlayer) >= -2)
					{
						buffduration = 99999 + 1;
					}

					if (buffduration > duration)
						Dest.DWord = false;
				}
			}
		}
		return true;
	}

	case WillStack:
	case NewStacksWith: // if a spell stack with another spell
	{
		Dest.DWord = false;
		Dest.Type = pBoolType;

		if (!Index[0])
			return true;
		SPELL* tmpSpell = nullptr;

		if (IsNumber(Index))
			tmpSpell = GetSpellByID(GetIntFromString(Index, 0));
		else
			tmpSpell = GetSpellByName(Index);
		if (!tmpSpell)
			return true;

		SPELL* thespell = pSpell;
		if (pLocalPlayer)
		{
			SPAWNINFO* pPlayer = (SPAWNINFO*)pLocalPlayer;
			PcClient* pPc = pPlayer->GetPcClient();
			if (pPc)
			{
				EQ_Affect eff = { 0 };
				eff.ID = tmpSpell->ID;
				eff.CasterLevel = pPlayer->Level;
				eff.Type = 2;
				eff.BaseDmgMod = 1.0;
				int SlotIndex = -1;

				EQ_Affect* ret = pPc->FindAffectSlot(thespell->ID, pPlayer, &SlotIndex, true, pPlayer->Level, &eff, 1, false);

				// call below is correct but it always seem to return false so i don't
				// think its useful to clientside... also call above calls it...
				// Dest.DWord = pCZC->IsStackBlocked((EQ_Spell*)thespell, (SPAWNINFO*)pLocalPlayer, &eff, 1);
				if (!ret || SlotIndex == -1)
					Dest.DWord = false;
				else
					Dest.DWord = true;
			}
		}
		return true;
	}

	case StacksSpawn:
	{
		Dest.DWord = false;
		Dest.Type = pBoolType;

		if (!Index[0])
			return true;
		if (CachedBuffsMap.empty())
			return true;

		SPAWNINFO* pSpawn = (SPAWNINFO*)(IsNumber(Index) ? GetSpawnByID(GetIntFromString(Index, 0)) : GetSpawnByName(Index));

		if (pSpawn)
		{
			SPAWNINFO* pPlayer = (SPAWNINFO*)pLocalPlayer;
			PcClient* pPc = pSpawn->GetPcClient();
			if (pPc)
			{
				EQ_Affect pAffects[NUM_BUFF_SLOTS] = { 0 };
				int j = 0;

				auto i = CachedBuffsMap.find(pSpawn->SpawnID);
				if (i != CachedBuffsMap.end())
				{
					for (auto k = i->second.begin(); k != i->second.end(); k++)
					{
						if (SPELL* pBuff = GetSpellByID(k->first))
						{
							pAffects[j].Type = 2;
							pAffects[j].ID = pBuff->ID;
							pAffects[j].Activatable = 0; // pBuff->Activated;
							pAffects[j].CasterLevel = pPlayer->Level;
							pAffects[j].BaseDmgMod = 1.0;
							j++;
						}
					}
				}

				int SlotIndex = -1;
				EQ_Affect* ret = pPc->FindAffectSlot(pSpell->ID, pPlayer, &SlotIndex, true, pPlayer->Level, pAffects, j, false);
				if (!ret || SlotIndex == -1)
					Dest.DWord = false;
				else
					Dest.DWord = true;
			}
		}
		return true;
	}

	case StacksTarget:
	{
		Dest.DWord = false;
		Dest.Type = pBoolType;

		if (pLocalPlayer)
		{
			SPAWNINFO* pPlayer = (SPAWNINFO*)pLocalPlayer;
			PcClient* pPc = pPlayer->GetPcClient();
			if (pPc)
			{
				if (pTarget)
				{
					if (CHARINFO* pMe = GetCharInfo())
					{
						EQ_Affect pAffects[NUM_BUFF_SLOTS] = { 0 };
						int j = 0;

						auto i = CachedBuffsMap.find(pTarget->SpawnID);
						if (i != CachedBuffsMap.end())
						{
							// lets grab it from the cache so we get songs as well...
							for (auto k = i->second.begin(); k != i->second.end(); k++)
							{
								if (SPELL* pBuff = GetSpellByID(k->first))
								{
									pAffects[j].Type = 2;
									pAffects[j].ID = pBuff->ID;
									pAffects[j].Activatable = 0;// pBuff->Activated;
									pAffects[j].CasterGuid = pMe->Guid;
									pAffects[j].CasterLevel = ((SPAWNINFO*)pLocalPlayer)->Level;
									pAffects[j].BaseDmgMod = 1.0;
									j++;
								}
							}
						}
						else
						{
							int buffID = 0;
							for (int i = 0; i < NUM_BUFF_SLOTS; i++)
							{
								if (buffID = pTargetWnd->BuffSpellID[i])
								{
									if (SPELL* pBuff = GetSpellByID((DWORD)buffID))
									{
										pAffects[j].Type = 2;
										pAffects[j].ID = pBuff->ID;
										pAffects[j].Activatable = 0 ;// pBuff->Activated;
										pAffects[j].CasterGuid = pMe->Guid;
										pAffects[j].CasterLevel = ((SPAWNINFO*)pLocalPlayer)->Level;
										pAffects[j].BaseDmgMod = 1.0;
										j++;
									}
								}
							}
						}

						int SlotIndex = -1;
						EQ_Affect* ret = pPc->FindAffectSlot(pSpell->ID, (SPAWNINFO*)pLocalPlayer, &SlotIndex, true, ((SPAWNINFO*)pLocalPlayer)->Level, pAffects, j, false);
						if (!ret || SlotIndex == -1)
							Dest.DWord = false;
						else
							Dest.DWord = true;
					}
				}
			}
		}
		return true;
	}

	case StacksPet: {
		int duration = 99999;
		duration = GetIntFromString(Index, duration);

		Dest.DWord = true;
		Dest.Type = pBoolType;

		for (int nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
		{
			if (pPetInfoWnd->Buff[nBuff] > 0 && !(pPetInfoWnd->Buff[nBuff] == -1 || pPetInfoWnd->Buff[nBuff] == 0))
			{
				if (SPELL* buffSpell = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
				{
					int petBuffDuration = ((pPetInfoWnd->PetBuffTimer[nBuff] + 5999) / 1000) / 6;
					if (GetSpellDuration(buffSpell, (SPAWNINFO*)pLocalPlayer) >= -2)
					{
						petBuffDuration = 99999 + 1;
					}

					if (!BuffStackTest(pSpell, buffSpell, true) || ((buffSpell == pSpell) && (petBuffDuration > duration)))
					{
						Dest.DWord = false;
						return true;
					}
				}
			}
		}
		return true;
	}

	case StacksWith: {
		Dest.DWord = false;
		Dest.Type = pBoolType;

		if (!Index[0])
			return true;

		SPELL* tmpSpell = nullptr;
		if (IsNumber(Index))
			tmpSpell = GetSpellByID(GetIntFromString(Index, 0));
		else
			tmpSpell = GetSpellByName(Index);

		if (!tmpSpell)
			return true;

		Dest.DWord = BuffStackTest(pSpell, tmpSpell, true);
		return true;
	}

	case MyRange: {
		VePointer<CONTENTS> n;
		Dest.Float = pSpell->Range + (float)GetFocusRangeModifier((EQ_Spell*)pSpell, n);
		Dest.Type = pFloatType;
		return true;
	}

		// This is for debugging purposes/correcting struct on patchday
	case Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case EnduranceCost:
		Dest.DWord = pSpell->EnduranceCost;
		Dest.Type = pIntType;
		return true;

	case MaxLevel:
		Dest.DWord = GetSpellMax(pSpell, 0);
		Dest.Type = pIntType;
		return true;

	case Category:
		strcpy_s(DataTypeTemp, "Unknown");
		if (int cat = GetSpellCategory(pSpell))
		{
			if (const char* ptr = pCDBStr->GetString(cat, eSpellCategory))
			{
				strcpy_s(DataTypeTemp, ptr);
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Subcategory:
		strcpy_s(DataTypeTemp, "Unknown");
		if (int cat = GetSpellSubcategory(pSpell))
		{
			if (const char* ptr = pCDBStr->GetString(cat, eSpellCategory))
			{
				strcpy_s(DataTypeTemp, ptr);
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Restrictions:
		Dest.Type = pStringType;
		if (!Index[0])
			return false;

		strcpy_s(DataTypeTemp, "Unknown");
		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;

			char* ptr = GetSpellRestrictions(pSpell, nIndex, DataTypeTemp, sizeof(DataTypeTemp));
			if (!ptr)
				strcpy_s(DataTypeTemp, "Unknown");
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Base:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.Int = GetSpellBase(pSpell, nIndex);
		}
		return true;

	case Base2:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.Int = GetSpellBase2(pSpell, nIndex);
		}
		return true;

	case Max:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			Dest.Int = GetSpellMax(pSpell, nIndex);
		}
		return true;

	case Calc:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.Int = GetSpellCalc(pSpell, nIndex);
		}
		return true;

	case Attrib:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.Int = GetSpellAttrib(pSpell, nIndex);
		}
		return true;

	case CalcIndex:
		Dest.Int = pSpell->CalcIndex;
		Dest.Type = pIntType;
		return true;

	case NumEffects:
		Dest.Int = GetSpellNumEffects(pSpell);
		Dest.Type = pIntType;
		return true;

	case AutoCast:
		Dest.DWord = pSpell->Autocast;
		Dest.Type = pIntType;
		return true;

	case Extra:
		strcpy_s(DataTypeTemp, pSpell->Extra);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case RecastTimerID:
		Dest.DWord = pSpell->ReuseTimerIndex;
		Dest.Type = pIntType;
		return true;

	case SPA:
		Dest.DWord = pSpell->spaindex;
		Dest.Type = pIntType;
		return true;

	case ReagentID:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.DWord = pSpell->ReagentID[nIndex];
		}
		return true;

	case NoExpendReagentID:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;
		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.DWord = pSpell->NoExpendReagent[nIndex];
		}
		return true;

	case ReagentCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;
		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.DWord = pSpell->ReagentCount[nIndex];
		}
		return true;

	case TimeOfDay:
		Dest.DWord = pSpell->TimeOfDay;
		Dest.Type = pIntType;
		return true;

	case DurationWindow:
		Dest.DWord = pSpell->DurationWindow;
		Dest.Type = pIntType;
		return true;

	case CanMGB:
		Dest.DWord = pSpell->CanMGB;
		Dest.Type = pBoolType;
		return true;

	case IsSkill:
		Dest.DWord = pSpell->IsSkill;
		Dest.Type = pBoolType;
		return true;

	case Deletable:
		Dest.DWord = pSpell->Deletable;
		Dest.Type = pBoolType;
		return true;

	case BookIcon:
		Dest.DWord = pSpell->BookIcon;
		Dest.Type = pIntType;
		return true;

	case SpellIcon:
		Dest.DWord = pSpell->SpellIcon;
		Dest.Type = pIntType;
		return true;

	case GemIcon:
		Dest.DWord = pSpell->GemIcon;
		Dest.Type = pIntType;
		return true;

	case Target:
		strcpy_s(DataTypeTemp, pSpell->Target);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Description:
		Dest.Type = pStringType;
		if (const char* ptr = pCDBStr->GetString(pSpell->DescriptionIndex, eSpellDescription))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Caster: {
		Dest.Type = pStringType;
		auto iter = targetBuffSlotToCasterMap.find(VarPtr.HighPart);
		if (iter != targetBuffSlotToCasterMap.end())
		{
			strcpy_s(DataTypeTemp, iter->second.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	}

	case BaseName:
	{
		strcpy_s(DataTypeTemp, pSpell->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;

		int SpellRank = pSpell->SpellRank;

		switch (pSpell->SpellRank)
		{
		case 1: // Original
			SpellRank = 1;
			break;
		case 5: // Rk. II
			SpellRank = 2;
			break;
		case 10: // Rk. III
			SpellRank = 3;
			break;
		}

		if (!SpellRank)
		{
			SpellRank = GetSpellRankByName(pSpell->Name);
		}

		if (SpellRank > 1)
		{
			TruncateSpellRankName(DataTypeTemp);
		}
		return true;
	}

	case Rank:
		// well I haven't checked all spells, but im pretty sure if it's 0 its not a spell a
		// player can scribe/or not intentional, i.e a eq bug, time will tell - eqmule

		Dest.DWord = pSpell->SpellRank;
		Dest.Type = pIntType;

		switch (pSpell->SpellRank)
		{
		case 1: // Original
			Dest.DWord = 1;
			break;
		case 5: // Rk. II
			Dest.DWord = 2;
			break;
		case 10: // Rk. III
			Dest.DWord = 3;
			break;
		}

		if (Dest.DWord == 0)
		{
			// didn't have a rank, lets see if we can get it from the name
			Dest.DWord = GetSpellRankByName(pSpell->Name);
		}

		return true;

	case RankName: {
		Dest.Type = pSpellType;

		int level = -1;
		if (SPAWNINFO* pMe = (SPAWNINFO*)pLocalPlayer)
		{
			level = pMe->Level;
		}

		SPELL* thespell = pSpell;
		if (PcProfile* pProfile = GetPcProfile())
		{
			// is it a altability?
			for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
			{
				if (ALTABILITY* pAbility = GetAAByIdWrapper(nAbility, level))
				{
					if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
					{
						if (!_strnicmp(thespell->Name, pName, strlen(thespell->Name)))
						{
							if (pAbility->SpellID != -1)
							{
								if (SPELL* pFoundSpell = GetSpellByID(pAbility->SpellID))
								{
									if (pFoundSpell->SpellGroup == thespell->SpellGroup)
									{
										Dest.Ptr = pFoundSpell;
										return true;
									}
								}
							}
						}
					}
				}
			}

			// so if we got here we should check if its a combatability
			for (DWORD dwIndex = 0; dwIndex < NUM_COMBAT_ABILITIES; dwIndex++)
			{
				if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(dwIndex))
				{
					if (SPELL* pFoundSpell = GetSpellByID(pPCData->GetCombatAbility(dwIndex)))
					{
						if (pFoundSpell->SpellGroup == thespell->SpellGroup
							&& !_strnicmp(thespell->Name, pFoundSpell->Name, strlen(thespell->Name)))
						{
							Dest.Ptr = pFoundSpell;
							return true;
						}
					}
				}
			}

			// well AA should be used first so lets search spells last...
			for (int nSpell = 0; nSpell < NUM_BOOK_SLOTS; nSpell++)
			{
				if (pProfile->SpellBook[nSpell] != -1)
				{
					if (SPELL* pFoundSpell = GetSpellByID(pProfile->SpellBook[nSpell]))
					{
						if (pFoundSpell->ID == thespell->ID)
						{
							Dest.Ptr = pFoundSpell;
							return true;
						}
					}
				}
			}

			for (int nSpell = 0; nSpell < NUM_BOOK_SLOTS; nSpell++)
			{
				if (pProfile->SpellBook[nSpell] != -1)
				{
					if (SPELL* pFoundSpell = GetSpellByID(pProfile->SpellBook[nSpell]))
					{
						if (pFoundSpell->SpellGroup == thespell->SpellGroup
							&& !_strnicmp(thespell->Name, pFoundSpell->Name, strlen(thespell->Name)))
						{
							Dest.Ptr = pFoundSpell;
							return true;
						}
					}
				}
			}
		}
		Dest.Ptr = thespell;
		return true;
	}

	case SpellGroup:
		Dest.DWord = pSpell->SpellGroup;
		Dest.Type = pIntType;
		return true;

	case SubSpellGroup:
		Dest.DWord = pSpell->SpellSubGroup;
		Dest.Type = pIntType;
		return true;

	case Beneficial:
		Dest.DWord = pSpell->SpellType != 0;
		Dest.Type = pBoolType;
		return true;

	case xIsActiveAA:
		Dest.DWord = IsActiveAA(pSpell->Name);
		Dest.Type = pBoolType;
		return true;

	case Location:
		Dest.DWord = pSpell->ZoneType;
		Dest.Type = pIntType;
		return true;

	case IsSwarmSpell: {
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		int slots = GetSpellNumEffects(pSpell);

		for (int i = 0; i < slots; i++)
		{
			int attrib = GetSpellAttrib(pSpell, i);
			if (attrib == SPA_PET_SWARM || attrib == SPA_DOPPELGANGER)
			{
				Dest.DWord = 1;
				break;
			}
		}
		return true;
	}

	case DurationValue1:
		Dest.DWord = pSpell->DurationCap;
		Dest.Type = pIntType;
		return true;

	case StacksWithDiscs:
		Dest.DWord = pSpell->bStacksWithDiscs;
		Dest.Type = pBoolType;
		return true;

	case IllusionOkWhenMounted:
		Dest.DWord = true;
		Dest.Type = pBoolType;

		if (uint8_t spellIndex = ((EQ_Spell*)pSpell)->SpellAffects(SPA_CHANGE_FORM))
		{
			if (EQ_Affect* aff = pCharData->GetPCSpellAffect(SPA_SUMMON_MOUNT, nullptr))
			{
				if (PlayerClient* pc = pLocalPlayer)
				{
					for (int i = 0; i < GetSpellNumEffects(pSpell); ++i)
					{
						if (const SpellAffectData* pSpellAffect = ((EQ_Spell*)pSpell)->GetSpellAffectByIndex(i))
						{
							if (pSpellAffect->Attrib == SPA_CHANGE_FORM)
							{
								int islegal = pc->LegalPlayerRace(pSpellAffect->Base);

								if (!islegal && pSpellAffect->Base != EQR_SKELETON
									&& pSpellAffect->Base != EQR_SKELETON_NEW
									&& pSpellAffect->Base != EQR_OEQ_SKELETON
									&& pSpellAffect->Base != EQR_SOL_SKELETON)
								{
									// can't change into this illusion cause you are on a mount...
									Dest.DWord = false;
									break;
								}
							}
						}
					}
				}
			}
		}
		return true;

	case HasSPA:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int spa = GetIntFromString(Index, 0);
				if (IsSPAEffect(pSpell, spa))
				{
					Dest.DWord = true;
				}
			}
		}
		return true;

	case Trigger:
	{
		Dest.Type = pSpellType;
		SPELL* pmyspell = pSpell;
		int spafound = 0;

		if (IsSPAEffect(pSpell, SPA_TRIGGER_BEST_IN_SPELL_GROUP))
		{
			spafound = SPA_TRIGGER_BEST_IN_SPELL_GROUP;
		}
		else if (IsSPAEffect(pSpell, 374))
		{
			spafound = 374;
		}

		if (pSpellMgr && spafound)
		{
			int index = 0;
			if (Index[0])
			{
				if (IsNumber(Index))
				{
					index = GetIntFromString(Index, index);
					if (index > 0)
						index--;
					else
						index = 0;
				}
			}

			int numeffects = GetSpellNumEffects(pSpell);
			if (numeffects > index)
			{
				SPELL* pTrigger = nullptr;
				if (int groupid = GetSpellBase2(pmyspell, index))
				{
					if (spafound == SPA_TRIGGER_BEST_IN_SPELL_GROUP)
						pTrigger = (SPELL*)pSpellMgr->GetSpellByGroupAndRank(groupid, pmyspell->SpellSubGroup, pmyspell->SpellRank, true);
					else if (spafound == SPA_TRIGGER_SPELL)
						pTrigger = (SPELL*)pSpellMgr->GetSpellByID(groupid);
					Dest.Ptr = pTrigger;
					return true;
				}
			}
		}
		return false;
	}
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2ItemSpellType

bool MQ2ItemSpellType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	ITEMSPELLS* pItemSpell = static_cast<ITEMSPELLS*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	MQTypeMember* pMember = MQ2ItemSpellType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ItemSpellMembers>(pMember->ID))
	{
	case SpellID:
		Dest.DWord = pItemSpell->SpellID;
		Dest.Type = pIntType;
		return true;

	case RequiredLevel:
		Dest.DWord = pItemSpell->RequiredLevel;
		Dest.Type = pIntType;
		return true;

	case EffectType:
		Dest.DWord = pItemSpell->EffectType;
		Dest.Type = pIntType;
		return true;

	case EffectiveCasterLevel:
		Dest.DWord = pItemSpell->EffectiveCasterLevel;
		Dest.Type = pIntType;
		return true;

	case MaxCharges:
		Dest.DWord = pItemSpell->MaxCharges;
		Dest.Type = pIntType;
		return true;

	case CastTime:
		Dest.DWord = pItemSpell->CastTime;
		Dest.Type = pIntType;
		return true;

	case TimerID:
		Dest.DWord = pItemSpell->TimerID;
		Dest.Type = pIntType;
		return true;

	case RecastType:
		Dest.DWord = pItemSpell->RecastType;
		Dest.Type = pIntType;
		return true;

	case ProcRate:
		Dest.DWord = pItemSpell->ProcRate;
		Dest.Type = pIntType;
		return true;

	case OtherName:
		strcpy_s(DataTypeTemp, pItemSpell->OtherName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case OtherID:
		Dest.DWord = pItemSpell->OtherID;
		Dest.Type = pIntType;
		return true;

	case Spell:
		Dest.Ptr = GetSpellByID(pItemSpell->SpellID);
		Dest.Type = pSpellType;
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2ItemType

bool MQ2ItemType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CONTENTS* pItem = static_cast<CONTENTS*>(VarPtr.Ptr);
	if (!pItem)
		return false;

	PITEMINFO pItemInfo = GetItemFromContents(pItem);
	if (!pItemInfo)
		return false;

	MQTypeMember* pMember = MQ2ItemType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ItemMembers>(pMember->ID))
	{
	case ID:
		Dest.DWord = GetItemFromContents(pItem)->ItemNumber;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, GetItemFromContents(pItem)->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Lore:
		Dest.DWord = ((ItemBase*)pItem)->IsLore(false);
		Dest.Type = pBoolType;
		return true;
	case LoreEquipped:
		Dest.DWord = ((ItemBase*)pItem)->IsLoreEquipped(false);
		Dest.Type = pBoolType;
		return true;

	case NoDrop:
	case NoTrade:
		Dest.DWord = !((EQ_Item*)pItem)->CanDrop(0, 1);
		Dest.Type = pBoolType;
		return true;

	case NoRent:
		Dest.DWord = !GetItemFromContents(pItem)->NoRent;
		Dest.Type = pBoolType;
		return true;

	case Magic:
		Dest.DWord = ((GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL) && (GetItemFromContents(pItem)->Magic));
		Dest.Type = pBoolType;
		return true;

	case Value:
		Dest.DWord = GetItemFromContents(pItem)->Cost;
		Dest.Type = pIntType;
		return true;

	case Size:
		Dest.DWord = GetItemFromContents(pItem)->Size;
		Dest.Type = pIntType;
		return true;

	case SizeCapacity:
		Dest.DWord = GetItemFromContents(pItem)->SizeCapacity;
		Dest.Type = pIntType;
		return true;

	case Weight:
		Dest.DWord = GetItemFromContents(pItem)->Weight;
		Dest.Type = pIntType;
		return true;

	case Stack:
		if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) || (((EQ_Item*)pItem)->IsStackable() != 1))
			Dest.DWord = 1;
		else
			Dest.DWord = pItem->StackCount;
		Dest.Type = pIntType;
		return true;

	case Type:
		DataTypeTemp[0] = '\0';
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL)
		{
			if ((GetItemFromContents(pItem)->ItemType < MAX_ITEMTYPES) && (szItemTypes[GetItemFromContents(pItem)->ItemType] != nullptr))
			{
				strcpy_s(DataTypeTemp, szItemTypes[GetItemFromContents(pItem)->ItemType]);
			}
			else
			{
				sprintf_s(DataTypeTemp, "*UnknownType%d", GetItemFromContents(pItem)->ItemType);
			}
		}
		else if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			if ((GetItemFromContents(pItem)->Combine < MAX_COMBINES) && (szCombineTypes[GetItemFromContents(pItem)->Combine] != nullptr))
			{
				strcpy_s(DataTypeTemp, szCombineTypes[GetItemFromContents(pItem)->Combine]);
			}
			else
			{
				sprintf_s(DataTypeTemp, "*UnknownCombine%d", GetItemFromContents(pItem)->Combine);
			}
		}
		else if (GetItemFromContents(pItem)->Type == ITEMTYPE_BOOK)
		{
			strcpy_s(DataTypeTemp, "Book");
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Charges:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->Charges;
		Dest.Type = pIntType;
		return true;

	case LDoNTheme:
		strcpy_s(DataTypeTemp, GetLDoNTheme(GetItemFromContents(pItem)->LDTheme));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

		// we go to keep this for backward compatibility
		// but really it should be called case ElementalFlag:
	case DMGBonusType:
		strcpy_s(DataTypeTemp, szDmgBonusType[GetItemFromContents(pItem)->ElementalFlag]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Container:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			Dest.DWord = GetItemFromContents(pItem)->Slots;
		}
		return true;

	case Open:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			Dest.DWord = pItem->Open;
		}
		return true;

	case Items:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			if (pItem->Contents.ContainedItems.pItems) {
				for (unsigned long N = 0; N < GetItemFromContents(pItem)->Slots; N++) {
					if (pItem->GetContent(N))
						Dest.DWord++;
				}
			}
			return true;
		}
		return false;

	case Clicky:
		Dest.Ptr = &GetItemFromContents(pItem)->Clicky;
		Dest.Type = pItemSpellType;
		return true;

	case Proc:
		Dest.Ptr = &GetItemFromContents(pItem)->Proc;
		Dest.Type = pItemSpellType;
		return true;

	case Worn:
		Dest.Ptr = &GetItemFromContents(pItem)->Worn;
		Dest.Type = pItemSpellType;
		return true;

	case Focus:
		Dest.Ptr = &GetItemFromContents(pItem)->Focus;
		Dest.Type = pItemSpellType;
		return true;

	case Scroll:
		Dest.Ptr = &GetItemFromContents(pItem)->Scroll;
		Dest.Type = pItemSpellType;
		return true;

	case Focus2:
		Dest.Ptr = &GetItemFromContents(pItem)->Focus2;
		Dest.Type = pItemSpellType;
		return true;

	case Mount:
		Dest.Ptr = &GetItemFromContents(pItem)->Mount;
		Dest.Type = pItemSpellType;
		return true;

	case Illusion:
		Dest.Ptr = &GetItemFromContents(pItem)->Illusion;
		Dest.Type = pItemSpellType;
		return true;

	case Familiar:
		Dest.Ptr = &GetItemFromContents(pItem)->Familiar;
		Dest.Type = pItemSpellType;
		return true;

	case Item: {
		Dest.Type = pItemType;
		CONTENTS* pCont = (CONTENTS*)pItem;

		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK && IsNumber(Index))
		{
			// FIXME:  Add some safety checks here for bad conversion
			int num = GetIntFromString(Index, 1) - 1;
			if (num < GetItemFromContents(pItem)->Slots)
			{
				if (pItem->Contents.ContainedItems.pItems)
				{
					if (Dest.Ptr = pItem->GetContent(num))
					{
						return true;
					}
				}
			}
		}
		else if (GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL && IsNumber(Index))
		{
			// FIXME:  Add some safety checks here for bad conversion
			int num = GetIntFromString(Index, 1) - 1;
			Dest.Ptr = nullptr;

			if (pItem->Contents.ContainedItems.pItems)
			{
				if (GetItemFromContents(pItem)->AugData.Sockets[num].Type)
					Dest.Ptr = pItem->Contents.ContainedItems.pItems->Item[num];
			}

			if (Dest.Ptr)
				return true;
		}
		return false;
	}
	case Stackable:
		Dest.DWord = ((EQ_Item*)pItem)->IsStackable();
		Dest.Type = pBoolType;
		return true;

	case InvSlot:
		Dest.Int = FindInvSlotForContents(pItem);
		if (Dest.Int >= 0)
		{
			Dest.Type = pInvSlotType;
			return true;
		}
		return false;

	case ItemSlot:
		Dest.Int = pItem->GetGlobalIndex().GetIndex().GetSlot(0);
		Dest.Type = pIntType;
		return true;

	case ItemSlot2:
		Dest.Int = pItem->GetGlobalIndex().GetIndex().GetSlot(1);
		Dest.Type = pIntType;
		return true;

	case BuyPrice:
		Dest.Int64 = 0;
		Dest.Type = pInt64Type;
		if (pActiveMerchant && pItem->MerchantSlot)
		{
			Dest.Int64 = pItem->Price;
			return true;
		}
		return false;

	case SellPrice:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pActiveMerchant)
		{
			Dest.DWord = static_cast<int>(
				static_cast<float>(GetItemFromContents(pItem)->Cost) * (1.0f / pMerchantWnd->MerchantGreed));
			return true;
		}
		return false;

	case WornSlot:
		Dest.DWord = 0;
		Dest.Type = pInvSlotType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count)
					return false;

				int cmp = GetItemFromContents(pItem)->EquipSlots;
				for (int num = 0; num < 32; num++)
				{
					if (cmp & (1 << num))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = num;
							Dest.Type = pInvSlotType;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				uint32_t nInvSlot = ItemSlotMap[Index];
				if ((nInvSlot || !_stricmp(Index, "charm")) && nInvSlot < 32)
				{
					Dest.DWord = (GetItemFromContents(pItem)->EquipSlots & (1 << nInvSlot));
					Dest.Type = pBoolType;
					return true;
				}
			}
		}
		return false;

	case WornSlots: {
		Dest.DWord = 0;

		// count bits
		int cmp = GetItemFromContents(pItem)->EquipSlots;
		for (int num = 0; num < 32; num++)
		{
			if (cmp & (1 << num))
				Dest.DWord++;
		}
		Dest.Type = pIntType;
		return true;
	}

	case CastTime:
		Dest.UInt64 = GetItemFromContents(pItem)->Clicky.CastTime;
		Dest.Type = pTimeStampType;
		return true;

	case Spell:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Clicky.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Scroll.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Proc.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Focus.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Worn.SpellID))
			return true;
		return false;

	case EffectType:
		Dest.Type = pStringType;
		// 0 Proc
		// 1 Clickable from inventory (any class)
		// 2 Worn effect (haste, cleave)
		// 3 Unknown
		// 4 Clickable must be worn
		// 5 Clickable from inventory (class restricted)
		// 6 Focus effect
		// 7 Memmable spell scroll

		// This used to return an int type with a case statment, items could have
		// only one effect. For backwards compatibility we return based on a hierarchy.
		// A zero in any field indicates no effect (others will also be zero)
		if (!GetItemFromContents(pItem)->Clicky.SpellID)
		{
			return false;
		}
		else if (GetItemFromContents(pItem)->Scroll.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Spell Scroll");
		}
		else if (GetItemFromContents(pItem)->Clicky.SpellID != -1)
		{
			// code to detect must-be-worn etc here
			switch (GetItemFromContents(pItem)->Clicky.EffectType)
			{
			case ItemEffectClickyWorn:
				strcpy_s(DataTypeTemp, "Click Worn");
				break;
			case ItemEffectClicky:
			case ItemEffectClickyRestricted:
				strcpy_s(DataTypeTemp, "Click Inventory");
				break;
			default:
				strcpy_s(DataTypeTemp, "Click Unknown");
				break;
			}
		}
		else if (GetItemFromContents(pItem)->Focus.SpellID != -1 || GetItemFromContents(pItem)->Worn.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Worn");
		}
		else if (GetItemFromContents(pItem)->Proc.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Combat");
		}
		else
		{
			return false;
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case InstrumentMod:
		Dest.Float = ((float)GetItemFromContents(pItem)->InstrumentMod) / 10.0f;
		Dest.Type = pFloatType;
		return true;

	case Tribute:
		Dest.DWord = GetItemFromContents(pItem)->Favor;
		Dest.Type = pIntType;
		return true;

	case Attuneable:
		Dest.DWord = GetItemFromContents(pItem)->Attuneable;
		Dest.Type = pBoolType;
		return true;

	case Timer:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (GetItemFromContents(pItem)->Clicky.TimerID != -1)
		{
			Dest.DWord = (GetItemTimer(pItem) + 5) / 6;
			return true;
		}
		if (GetItemFromContents(pItem)->Clicky.SpellID != -1)
		{
			Dest.DWord = 0; // insta-clicky
			return true;
		}
		return false;

	case Damage:
		Dest.DWord = GetItemFromContents(pItem)->Damage;
		Dest.Type = pIntType;
		return true;

	case ItemDelay:
		Dest.DWord = GetItemFromContents(pItem)->Delay;
		Dest.Type = pIntType;
		return true;

	case TimerReady:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Clicky.TimerID != -1)
		{
			Dest.DWord = GetItemTimer(pItem);
			return true;
		}
		if (GetItemFromContents(pItem)->Clicky.SpellID != -1)
		{
			Dest.DWord = 0; // insta-click or instant recast
			return true;
		}
		return false;

	case StackSize:
		// This returns the MAX size of a stack for the item
		// If this was properly named it should be called MaxStack.
		Dest.DWord = 1; //we know its at least 1
		Dest.Type = pIntType;

		if (pItem)
		{
			if ((pItem->GetItemDefinition()->Type == ITEMTYPE_NORMAL) && (((EQ_Item*)pItem)->IsStackable()))
			{
				Dest.DWord = pItem->GetItemDefinition()->StackSize;
			}
		}
		return true;

	case Stacks:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (PcProfile* pProfile = GetPcProfile())
		{
			if (!((EQ_Item*)pItem)->IsStackable())
				return true;

			for (int slot = BAG_SLOT_START; slot < NUM_INV_SLOTS; slot++)
			{
				if (pProfile->pInventoryArray && pProfile->pInventoryArray->InventoryArray[slot])
				{
					if (CONTENTS* pTempItem = pProfile->pInventoryArray->InventoryArray[slot])
					{
						if (GetItemFromContents(pTempItem)->Type == ITEMTYPE_PACK && pTempItem->Contents.ContainedItems.pItems)
						{
							for (int pslot = 0; pslot < (GetItemFromContents(pTempItem)->Slots); pslot++)
							{
								if (pTempItem->Contents.ContainedItems.pItems->Item[pslot])
								{
									if (CONTENTS* pSlotItem = pTempItem->Contents.ContainedItems.pItems->Item[pslot])
									{
										if (GetItemFromContents(pSlotItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
										{
											Dest.DWord++;
										}
									}
								}
							}
						}
						else
						{
							if (GetItemFromContents(pTempItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
							{
								Dest.DWord++;
							}
						}
					}
				}
			}
		}
		return true;

	case StackCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (PcProfile* pProfile = GetPcProfile())
		{
			if (!((EQ_Item*)pItem)->IsStackable())
				return true;

			for (int slot = BAG_SLOT_START; slot < NUM_INV_SLOTS; slot++)
			{
				if (pProfile->pInventoryArray && pProfile->pInventoryArray->InventoryArray[slot])
				{
					if (CONTENTS* pTempItem = pProfile->pInventoryArray->InventoryArray[slot])
					{
						if (GetItemFromContents(pTempItem)->Type == ITEMTYPE_PACK && pTempItem->Contents.ContainedItems.pItems)
						{
							for (int pslot = 0; pslot < (GetItemFromContents(pTempItem)->Slots); pslot++)
							{
								if (pTempItem->Contents.ContainedItems.pItems->Item[pslot])
								{
									if (CONTENTS* pSlotItem = pTempItem->Contents.ContainedItems.pItems->Item[pslot])
									{
										if (GetItemFromContents(pSlotItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
										{
											Dest.DWord += pSlotItem->StackCount;
										}
									}
								}
							}
						}
						else
						{
							if (GetItemFromContents(pTempItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
							{
								Dest.DWord += pTempItem->StackCount;
							}
						}
					}
				}
			}
		}
		return true;

	case FreeStack:
		Dest.DWord = GetFreeStack(pItem);
		Dest.Type = pIntType;
		return true;

	case MerchQuantity:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pActiveMerchant && pItem->MerchantSlot)
		{
			Dest.DWord = pItem->MerchantQuantity;
			return true;
		}
		return false;

	case Classes: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		// count bits
		int cmp = GetItemFromContents(pItem)->Classes;
		for (int num = 0; num < TotalPlayerClasses; num++)
		{
			if (cmp & (1 << num))
				Dest.DWord++;
		}
		return true;
	}

	case Class:
		Dest.DWord = 0;
		Dest.Type = pClassType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count)
					return false;

				int cmp = GetItemFromContents(pItem)->Classes;
				for (int num = 0; num < TotalPlayerClasses; num++)
				{
					if (cmp & (1 << num))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = num + 1;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				int cmp = GetItemFromContents(pItem)->Classes;
				for (int num = 0; num < TotalPlayerClasses; num++)
				{
					if (cmp & (1 << num))
					{
						if (!_stricmp(Index, GetClassDesc(num + 1))
							|| !_stricmp(Index, pEverQuest->GetClassThreeLetterCode(num + 1)))
						{
							Dest.DWord = num + 1;
							return true;
						}
					}
				}
				return false;
			}
		}
		return false;

	case Races: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		// count bits
		int cmp = GetItemFromContents(pItem)->Races;
		for (int num = 0; num < NUM_RACES; num++)
		{
			if (cmp & (1 << num))
				Dest.DWord++;
		}
		return true;
	}

	case Race:
		Dest.DWord = 0;
		Dest.Type = pRaceType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count)
					return false;

				int cmp = GetItemFromContents(pItem)->Races;
				for (int num = 0; num < NUM_RACES; num++)
				{
					if (cmp & (1 << num))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = num + 1;
							switch (num)
							{
							case 12:
								Dest.DWord = 128;   // IKS
								break;
							case 13:
								Dest.DWord = 130;   // VAH
								break;
							case 14:
								Dest.DWord = 330;   // FRG
								break;
							case 15:
								Dest.DWord = 522;   // DRK
								break;
							}
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				int cmp = GetItemFromContents(pItem)->Races;
				for (int num = 0; num < NUM_RACES; num++)
				{
					if (cmp & (1 << num))
					{
						int tmp = num + 1;
						switch (num)
						{
						case 12:
							tmp = 128;   // IKS
							break;
						case 13:
							tmp = 130;   // VAH
							break;
						case 14:
							tmp = 330;   // FRG
							break;
						case 15:
							tmp = 522;   // DRK
							break;
						}

						if (!_stricmp(Index, pEverQuest->GetRaceDesc(tmp)))
						{
							Dest.DWord = tmp;
							return true;
						}
					}
				}
				return false;
			}
		}
		return false;

	case Deities: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		// count bits
		int cmp = GetItemFromContents(pItem)->Diety;
		for (int num = 0; num < NUM_DEITIES; num++)
		{
			if (cmp & (1 << num))
				Dest.DWord++;
		}
		return true;
	}

	case Deity:
		Dest.DWord = 0;
		Dest.Type = pDeityType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count)
					return false;
				int cmp = GetItemFromContents(pItem)->Diety;
				for (int num = 0; num < NUM_DEITIES; num++)
				{
					if (cmp & (1 << num))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = num + 200;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				int cmp = GetItemFromContents(pItem)->Diety;
				for (int num = 0; num < NUM_DEITIES; num++)
				{
					if (cmp & (1 << num))
					{
						if (!_stricmp(Index, pEverQuest->GetDeityDesc(num + 200)))
						{
							Dest.DWord = num + 200;
							return true;
						}
					}
				}
				return false;
			}
		}
		return false;

	case RequiredLevel:
		Dest.DWord = GetItemFromContents(pItem)->RequiredLevel;
		Dest.Type = pIntType;
		return true;

	case SkillModValue:
		Dest.DWord = GetItemFromContents(pItem)->SkillModValue;
		Dest.Type = pIntType;
		return true;

	case SkillModMax:
		Dest.DWord = GetItemFromContents(pItem)->SkillModMax;
		Dest.Type = pIntType;
		return true;

	case Evolving:
		Dest.Ptr = pItem;
		Dest.Type = pEvolvingItemType;
		return true;

	case AC:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AC;
		Dest.Type = pIntType;
		return true;

	case HP:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HP;
		Dest.Type = pIntType;
		return true;

	case STR:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->STR;
		Dest.Type = pIntType;
		return true;

	case STA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->STA;
		Dest.Type = pIntType;
		return true;

	case AGI:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AGI;
		Dest.Type = pIntType;
		return true;

	case DEX:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->DEX;
		Dest.Type = pIntType;
		return true;

	case CHA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->CHA;
		Dest.Type = pIntType;
		return true;

	case INT:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->INT;
		Dest.Type = pIntType;
		return true;

	case WIS:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->WIS;
		Dest.Type = pIntType;
		return true;

	case Mana:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Mana;
		Dest.Type = pIntType;
		return true;

	case ManaRegen:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->ManaRegen;
		Dest.Type = pIntType;
		return true;

	case HPRegen:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HPRegen;
		Dest.Type = pIntType;
		return true;

	case Endurance:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Endurance;
		Dest.Type = pIntType;
		return true;

	case Attack:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Attack;
		Dest.Type = pIntType;
		return true;

	case svCold:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvCold;
		Dest.Type = pIntType;
		return true;

	case svFire:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvFire;
		Dest.Type = pIntType;
		return true;

	case svMagic:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvMagic;
		Dest.Type = pIntType;
		return true;

	case svDisease:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvDisease;
		Dest.Type = pIntType;
		return true;

	case svPoison:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvPoison;
		Dest.Type = pIntType;
		return true;

	case svCorruption:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvCorruption;
		Dest.Type = pIntType;
		return true;

	case Haste:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Haste;
		Dest.Type = pIntType;
		return true;

	case DamShield:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case AugType:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugType;
		Dest.Type = pIntType;
		return true;

	case AugRestrictions:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugRestrictions;
		Dest.Type = pIntType;
		return true;

	case AugSlot:
		Dest.DWord = 0;
		Dest.Type = pAugType;
		if (IsNumber(Index))
		{
			if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			{
				Dest.DWord = 0;
			}
			else
			{
				int index = std::clamp(GetIntFromString(Index, 0), 0, 5);
				Dest.DWord = index;
				Dest.HighPart = (LONG)pItem;
			}
			return true;
		}
		return false;

	case AugSlot1:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[0].Type;
		Dest.Type = pIntType;
		return true;

	case AugSlot2:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[1].Type;
		Dest.Type = pIntType;
		return true;

	case AugSlot3:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[2].Type;
		Dest.Type = pIntType;
		return true;

	case AugSlot4:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[3].Type;
		Dest.Type = pIntType;
		return true;

	case AugSlot5:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[4].Type;
		Dest.Type = pIntType;
		return true;

	case AugSlot6:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[5].Type;
		Dest.Type = pIntType;
		return true;

	case Power:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->Power;
		Dest.Type = pIntType;
		return true;

	case PctPower:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
		{
			Dest.Float = 0;
		}
		else
		{
			if (int maxpower = GetItemFromContents(pItem)->MaxPower)
			{
				Dest.Float = (float)((pItem->Power * 100) / maxpower);
			}
			else
			{
				Dest.Float = 0;
			}
		}
		Dest.Type = pFloatType;
		return true;

	case MaxPower:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) {
			Dest.DWord = 0;
		}
		else {
			Dest.DWord = GetItemFromContents(pItem)->MaxPower;
		}
		Dest.Type = pIntType;
		return true;

	case Purity:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Purity;
		Dest.Type = pIntType;
		return true;

	case Range:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Range;
		Dest.Type = pIntType;
		return true;

	case Avoidance:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case SpellShield:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case StrikeThrough:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case StunResist:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case Shielding:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case Accuracy:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case CombatEffects:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case DoTShielding:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case HeroicSTR:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSTR;
		Dest.Type = pIntType;
		return true;

	case HeroicINT:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicINT;
		Dest.Type = pIntType;
		return true;

	case HeroicWIS:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicWIS;
		Dest.Type = pIntType;
		return true;

	case HeroicAGI:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicAGI;
		Dest.Type = pIntType;
		return true;

	case HeroicDEX:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicDEX;
		Dest.Type = pIntType;
		return true;

	case HeroicSTA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSTA;
		Dest.Type = pIntType;
		return true;

	case HeroicCHA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicCHA;
		Dest.Type = pIntType;
		return true;

	case EnduranceRegen:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->EnduranceRegen;
		Dest.Type = pIntType;
		return true;

	case HealAmount:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HealAmount;
		Dest.Type = pIntType;
		return true;

	case Clairvoyance:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Clairvoyance;
		Dest.Type = pIntType;
		return true;

	case DamageShieldMitigation:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case SpellDamage:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				Dest.DWord = pII->SpellDamage;
			}
		}
		Dest.Type = pIntType;
		return true;

	case Augs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ITEMINFO* pitem = GetItemFromContents(pItem))
		{
			if (pitem->Type == ITEMTYPE_NORMAL)
			{
				for (int i = 0; i < MAX_AUG_SOCKETS; ++i)
				{
					if (pitem->AugData.Sockets[i].Type > 0 && pitem->AugData.Sockets[i].Type < 20 && pitem->AugData.Sockets[i].bVisible)
						Dest.DWord++;
				}

				Dest.Type = pIntType;
			}
		}
		return true;

	case Tradeskills:
		Dest.DWord = GetItemFromContents(pItem)->TradeSkills;
		Dest.Type = pBoolType;
		return true;

	case Address:
		Dest.DWord = (DWORD)GetItemFromContents(pItem);
		Dest.Type = pIntType;
		return true;

	case ContAddress:
		Dest.DWord = (DWORD)pItem;
		Dest.Type = pIntType;
		return true;

	case Prestige:
		Dest.DWord = GetItemFromContents(pItem)->Prestige;
		Dest.Type = pBoolType;
		return true;

	case FirstFreeSlot: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		CONTENTS* pTheCont = pItem;
		if (ITEMINFO* pTheItem = GetItemFromContents(pItem))
		{
			if (pTheItem->Type == ITEMTYPE_PACK || (pTheItem->Type == ITEMTYPE_NORMAL && pTheCont->Item1)) //a worldcontainer has its item in Item1
			{
				Dest.DWord = -1;
				if (pTheCont->Contents.ContainedItems.pItems)
				{
					for (int num = 0; num < pTheItem->Slots; num++)
					{
						if (!pTheCont->Contents.ContainedItems.pItems->Item[num])
						{
							Dest.DWord = num;
							break;
						}
					}
				}
				return true;
			}
		}
		return false;
	}

	case SlotsUsedByItem:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;
		CONTENTS* pTheCont = pItem;
		if (ITEMINFO* pTheItem = GetItemFromContents(pItem))
		{
			if (pTheItem->Type == ITEMTYPE_PACK || (pTheItem->Type == ITEMTYPE_NORMAL && pTheCont->Item1))
			{
				Dest.DWord = 0;
				bool bExact = false;
				char* pName1 = Index;
				if (*pName1 == '=')
				{
					bExact = true;
					pName1++;
				}

				if (pTheCont->Contents.ContainedItems.pItems)
				{
					for (int nSlot = 0; nSlot < pTheItem->Slots; nSlot++)
					{
						if (pTheCont->Contents.ContainedItems.pItems->Item[nSlot])
						{
							if (ITEMINFO* bagitem = GetItemFromContents(pTheCont->Contents.ContainedItems.pItems->Item[nSlot]))
							{
								if (bExact)
								{
									if (ci_equals(bagitem->Name, pName1))
									{
										Dest.DWord++;
									}
								}
								else
								{
									if (ci_find_substr(bagitem->Name, pName1) != -1)
									{
										Dest.DWord++;
									}
								}
							}
						}
					}
					return true;
				}
			}
		}
		return false;
	}

	case Heirloom:
		Dest.DWord = GetItemFromContents(pItem)->Heirloom;
		Dest.Type = pBoolType;
		return true;

	case Collectible:
		Dest.DWord = GetItemFromContents(pItem)->Collectible;
		Dest.Type = pBoolType;
		return true;

	case NoDestroy:
		Dest.DWord = GetItemFromContents(pItem)->NoDestroy;
		Dest.Type = pBoolType;
		return true;

	case Quest:
		Dest.DWord = GetItemFromContents(pItem)->QuestItem;
		Dest.Type = pBoolType;
		return true;

	case Expendable:
		Dest.DWord = GetItemFromContents(pItem)->Expendable;
		Dest.Type = pBoolType;
		return true;

	case ItemLink:
		Dest.Type = pStringType;
		if (GetItemLink(pItem, DataTypeTemp, false))
		{
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Icon:
		Dest.DWord = GetItemFromContents(pItem)->IconNumber;
		Dest.Type = pIntType;
		return true;

	case OrnamentationIcon:
		Dest.DWord = pItem->OrnamentationIcon;
		Dest.Type = pIntType;
		return true;

	case ContentSize:
		Dest.DWord = pItem->Contents.ContentSize;
		Dest.Type = pIntType;
		return true;

	case CanUse:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (CONTENTS* pCont = pItem)
		{
			Dest.DWord = pCharData->CanUseItem(&pCont, false, false);
			return true;
		}
		return false;

	case Luck:
		Dest.DWord = pItem->Luck;
		Dest.Type = pIntType;
		return true;

	case MinLuck:
		Dest.DWord = GetItemFromContents(pItem)->MinLuck;
		Dest.Type = pIntType;
		return true;

	case MaxLuck:
		Dest.DWord = GetItemFromContents(pItem)->MaxLuck;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2ItemType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!VarPtr.Ptr)
		return false;

	CONTENTS* pContents = static_cast<CONTENTS*>(VarPtr.Ptr);
	strcpy_s(Destination, MAX_STRING, GetItemFromContents(pContents)->Name);
	return true;
}

//----------------------------------------------------------------------------
// MQ2WindowType

bool MQ2WindowType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CXWnd* pWnd = static_cast<CXWnd*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2WindowType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<WindowMethods>(pMethod->ID))
		{
		case LeftMouseDown:
			SendWndClick2(pWnd, "leftmousedown");
			return true;

		case LeftMouseUp:
			SendWndClick2(pWnd, "leftmouseup");
			return true;

		case LeftMouseHeld:
			SendWndClick2(pWnd, "leftmouseheld");
			return true;

		case LeftMouseHeldUp:
			SendWndClick2(pWnd, "leftmouseheldup");
			return true;

		case RightMouseDown:
			SendWndClick2(pWnd, "rightmousedown");
			return true;

		case RightMouseUp:
			SendWndClick2(pWnd, "rightmouseup");
			return true;

		case RightMouseHeld:
			SendWndClick2(pWnd, "rightmouseheld");
			return true;

		case RightMouseHeldUp:
			SendWndClick2(pWnd, "rightmouseheldup");
			return true;

		case DoOpen:
			pWnd->Show(true, true);
			return true;

		case DoClose:
			pWnd->Show(false, true);
			return true;

		case Select: {
			int ListIndex = GetIntFromString(Index, 0) - 1;
			if (ListIndex < 0)
				ListIndex = 0;

			if (pWnd->GetType() == UI_Listbox)
			{
				CListWnd* listWnd = static_cast<CListWnd*>(pWnd);
				if (listWnd->ItemsArray.Count < ListIndex)
					return false;

				listWnd->SetCurSel(ListIndex);
				int index = listWnd->GetCurSel();

				listWnd->EnsureVisible(index);
				CXPoint pt = listWnd->GetItemRect(index, 0).CenterPoint();

				pWnd->HandleLButtonDown(pt, 0);
				pWnd->HandleLButtonUp(pt, 0);
				WeDidStuff();
				return true;
			}

			if (pWnd->GetType() == UI_Combobox)
			{
				CComboWnd* comboWnd = static_cast<CComboWnd*>(pWnd);

				if (CListWnd* pListWnd = comboWnd->pListWnd)
				{
					if (pListWnd->ItemsArray.Count < ListIndex)
						return false;

					CXPoint combopt = pWnd->GetScreenRect().CenterPoint();
					comboWnd->SetChoice(ListIndex);
					comboWnd->HandleLButtonDown(combopt, 0);

					int index = pListWnd->GetCurSel();
					CXPoint listpt = pListWnd->GetItemRect(index, 0).CenterPoint();
					pListWnd->HandleLButtonDown(listpt, 0);
					pListWnd->HandleLButtonUp(listpt, 0);

					WeDidStuff();
					return true;
				}
			}
			return false;
		}

		default: break;
		}

		return false;
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2WindowType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<WindowMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = reinterpret_cast<uint32_t>(pWnd);
		Dest.Type = pIntType;
		return true;

	case Open:
		Dest.DWord = pWnd->IsVisible();
		Dest.Type = pBoolType;
		return true;

	case Child:
		if (Dest.Ptr = pWnd->GetChildItem(Index))
		{
			Dest.Type = pWindowType;
			return true;
		}
		Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case Parent:
		if (Dest.Ptr = pWnd->GetParentWindow())
		{
			Dest.Type = pWindowType;
			return true;
		}
		Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case FirstChild:
		if (Dest.Ptr = pWnd->GetFirstChildWnd())
		{
			Dest.Type = pWindowType;
			return true;
		}
		Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case Next:
		if (Dest.Ptr = pWnd->GetNextSiblingWnd())
		{
			Dest.Type = pWindowType;
			return true;
		}
		Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case VScrollMax:
		Dest.DWord = pWnd->GetVScrollMax();
		Dest.Type = pIntType;
		return true;

	case VScrollPos:
		Dest.DWord = pWnd->GetVScrollPos();
		Dest.Type = pIntType;
		return true;

	case VScrollPct:
		Dest.DWord = (pWnd->GetVScrollPos() * 100) / pWnd->GetVScrollMax();
		Dest.Type = pIntType;
		return true;

	case HScrollMax:
		Dest.DWord = pWnd->GetHScrollMax();
		Dest.Type = pIntType;
		return true;

	case HScrollPos:
		Dest.DWord = pWnd->GetHScrollPos();
		Dest.Type = pIntType;
		return true;

	case HScrollPct:
		Dest.DWord = (pWnd->GetHScrollPos() * 100) / pWnd->GetHScrollMax();
		Dest.Type = pIntType;
		return true;

	case Children:
		Dest.DWord = pWnd->GetFirstChildWnd() != nullptr;
		Dest.Type = pBoolType;
		return true;

	case Siblings:
		Dest.DWord = pWnd->GetNextSiblingWnd() != nullptr;
		Dest.Type = pBoolType;
		return true;

	case Minimized:
		Dest.DWord = pWnd->IsMinimized();
		Dest.Type = pBoolType;
		return true;

	case MouseOver:
		Dest.DWord = pWnd->IsMouseOver();
		Dest.Type = pBoolType;
		return true;

	case X:
		Dest.DWord = pWnd->GetLocation().left;
		Dest.Type = pIntType;
		return true;

	case Y:
		Dest.DWord = pWnd->GetLocation().top;
		Dest.Type = pIntType;
		return true;

	case Width:
		Dest.DWord = pWnd->GetLocation().right - pWnd->GetLocation().left;
		Dest.Type = pIntType;
		return true;

	case Height:
		Dest.DWord = pWnd->GetLocation().bottom - pWnd->GetLocation().top;
		Dest.Type = pIntType;
		return true;

	case BGColor:
		Dest.DWord = pWnd->GetBGColor();
		Dest.Type = pArgbType;
		return true;

	case Text:
		if (pWnd->GetType() == UI_STMLBox)
		{
			CStmlWnd* cstmlwnd = static_cast<CStmlWnd*>(pWnd);
			strcpy_s(DataTypeTemp, cstmlwnd->STMLText.c_str());
		}
		else
		{
			strcpy_s(DataTypeTemp, pWnd->GetWindowText().c_str());
		}
		DataTypeTemp[MAX_STRING - 1] = '\0';
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Tooltip:
		strcpy_s(DataTypeTemp, pWnd->GetTooltip().c_str());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Checked:
		Dest.Int = ((CButtonWnd*)pWnd)->bChecked;
		Dest.Type = pBoolType;
		return true;

	case Highlighted: // if the window in question has focus...
		Dest.Int = false;
		Dest.Type = pBoolType;
		if (pWndMgr)
		{
			if (pWnd == pWndMgr->FocusWindow)
				Dest.Int = true;
		}
		return true;

	case Enabled:
		Dest.Int = pWnd->IsEnabled();
		Dest.Type = pBoolType;
		return true;

	case Style:
		Dest.DWord = pWnd->GetWindowStyle();
		Dest.Type = pIntType;
		return true;

	case List: {
		Dest.Type = pStringType;
		CListWnd* pListWnd = nullptr;

		if (pWnd->GetType() == UI_Combobox)
		{
			CComboWnd* combownd = static_cast<CComboWnd*>(pWnd);
			pListWnd = combownd->pListWnd;
		}
		else if (pWnd->GetType() == UI_Listbox)
		{
			pListWnd = static_cast<CListWnd*>(pWnd);
		}
		else
		{
			return false;
		}

		int n = 0;
		if (char* pComma = strchr(Index, ','))
		{
			n = GetIntFromString(&pComma[1], n) - 1;
			if (n < 0) n = 0;
			*pComma = '\0';
		}

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0);
			if (!nIndex)
				return false;

			CXStr Str = pListWnd->GetItemText(nIndex - 1, n);
			strcpy_s(DataTypeTemp, Str.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}
		else
		{
			// name
			bool bEqual = false;
			std::string_view sv;

			if (Index[0] == '=')
			{
				bEqual = true;
				sv = &Index[1];
			}
			else
			{
				sv = Index;
			}

			int nIndex = 0;
			while (true)
			{
				CXStr Str = pListWnd->GetItemText(nIndex, n);
				if (Str.empty())
					return false;

				if (bEqual)
				{
					if (ci_equals(Str, sv))
					{
						Dest.DWord = nIndex + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
				else
				{
					if (ci_find_substr(Str, sv) != -1)
					{
						Dest.DWord = nIndex + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
				nIndex++;
			}
		}
		return false;
	}

	case Name:
		Dest.Type = pStringType;
		if (CXMLData* pXMLData = pWnd->GetXMLData())
		{
			if (!pXMLData->Name.empty())
			{
				strcpy_s(DataTypeTemp, pXMLData->Name.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;

	case ScreenID:
		Dest.Type = pStringType;
		if (CXMLData* pXMLData = pWnd->GetXMLData())
		{
			if (!pXMLData->ScreenID.empty())
			{
				strcpy_s(DataTypeTemp, pXMLData->ScreenID.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;

	case Type:
		Dest.Type = pStringType;
		if (CXMLData* pXMLData = pWnd->GetXMLData())
		{
			if (!pXMLData->TypeName.empty())
			{
				strcpy_s(DataTypeTemp, pXMLData->TypeName.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;

	case Items:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pWnd->GetType() == UI_Listbox)
		{
			CListWnd* clist = static_cast<CListWnd*>(pWnd);
			Dest.DWord = clist->ItemsArray.Count;
		}
		else if (pWnd->GetType() == UI_Combobox)
		{
			CComboWnd* ccombo = static_cast<CComboWnd*>(pWnd);
			if (ccombo->pListWnd)
			{
				Dest.DWord = ccombo->pListWnd->ItemsArray.Count;
			}
		}
		return true;

	case HisTradeReady:
		Dest.Int = 0;
		Dest.Type = pBoolType;
		if (pTradeWnd)
		{
			Dest.Int = pTradeWnd->bHisReadyTrade;
		}
		return true;

	case MyTradeReady:
		Dest.Int = 0;
		Dest.Type = pBoolType;
		if (pTradeWnd)
		{
			Dest.Int = pTradeWnd->bMyReadyTrade;
		}
		return true;

	case GetCurSel: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		CListWnd* pListWnd = nullptr;

		if (pWnd->GetType() == UI_Combobox)
		{
			CComboWnd* combo = static_cast<CComboWnd*>(pWnd);
			Dest.DWord = combo->pListWnd ? combo->pListWnd->GetCurSel() + 1 : 0;
			return true;
		}

		if (pWnd->GetType() == UI_Listbox)
		{
			CListWnd* list = static_cast<CListWnd*>(pWnd);
			Dest.DWord = list->GetCurSel() + 1;
			return true;
		}

		return false;
	}

	default: break;
	}

	return false;
}

bool MQ2WindowType::FromString(MQVarPtr& VarPtr, char* Source)
{
	if (VarPtr.Ptr = FindMQ2Window(Source))
		return true;

	return false;
}

//----------------------------------------------------------------------------
// MQ2MenuType

bool MQ2MenuType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CContextMenuManager* pMgr = static_cast<CContextMenuManager*>(VarPtr.Ptr);
	if (!pMgr)
		return false;

	//------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2MenuType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<MenuMethods>(pMethod->ID))
		{
		case Select: {
			if (Index[0])
			{
				if (pMgr->NumVisibleMenus == 1)
				{
					if (pMgr->CurrMenu < MAX_CONTEXT_MENU_DEPTH)
					{
						int currItem = pMgr->CurrMenu;
						if (CContextMenu* menu = pMgr->pCurrMenus[currItem])
						{
							for (int i = 0; i < menu->NumItems; i++)
							{
								CXStr Str = menu->GetItemText(i, 1);
								if (!Str.empty())
								{
									if (ci_find_substr(Str, Index))
									{
										WriteChatf("\ay[${Menu.Select}] SUCCESS\ax: Clicking \"%s\" at position %d in the menu.", Str.c_str(), i);

										pMgr->WndNotification(menu, XWM_LMOUSEUP, (void*)i);
										Dest.DWord = 1;
										Dest.Type = pBoolType;
										return true;
									}
								}
							}

							WriteChatf("\ar[${Menu.Select}] FAILED\ax: No Menu item was found with the word %s in it", Index);
						}
					}
				}
			}
			break;
		}

		default: break;
		}

		Dest.DWord = 0;
		Dest.Type = pBoolType;
		return true;
	}

	//------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2MenuType::FindMember(Member);
	if (!pMember)
	{
		if (pMgr->NumVisibleMenus == 1)
		{
			if (CContextMenu* pMenu = pMgr->pCurrMenus[pMgr->CurrMenu])
			{
				MQVarPtr data;
				data.Ptr = pMenu;

				return pWindowType->GetMember(data, Member, Index, Dest);
			}
		}
		return false;
	}

	switch (static_cast<MenuMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pMgr->NumVisibleMenus == 1)
		{
			if (CContextMenu* pMenu = pMgr->pCurrMenus[pMgr->CurrMenu])
			{
				Dest.DWord = (uint32_t)pMenu;
				return true;
			}
		}
		return false;

	case NumVisibleMenus:
		Dest.DWord = pMgr->NumVisibleMenus;
		Dest.Type = pIntType;
		return true;

	case CurrMenu:
		Dest.DWord = pMgr->CurrMenu;
		Dest.Type = pIntType;
		return true;

	case Name:
		Dest.Type = pStringType;
		if (pMgr->NumVisibleMenus == 1)
		{
			if (pMgr->CurrMenu < MAX_CONTEXT_MENU_DEPTH)
			{
				int currMenu = pMgr->CurrMenu;
				if (CContextMenu* menu = pMgr->pCurrMenus[currMenu])
				{
					CXStr Str = menu->GetItemText(0, 1);
					if (!Str.empty())
					{
						strcpy_s(DataTypeTemp, Str.c_str());
						Dest.Ptr = &DataTypeTemp[0];
						return true;
					}
				}
			}
		}
		return false;

	case NumItems:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pMgr->NumVisibleMenus == 1)
		{
			if (pMgr->CurrMenu < MAX_CONTEXT_MENU_DEPTH)
			{
				int currmen = pMgr->CurrMenu;
				if (CContextMenu* menu = pMgr->pCurrMenus[currmen])
				{
					Dest.DWord = menu->NumItems;
					return true;
				}
			}
		}
		return false;

	case Items:
		Dest.Type = pStringType;
		if (IsNumber(Index))
		{
			if (pMgr->NumVisibleMenus == 1)
			{
				if (pMgr->CurrMenu < MAX_CONTEXT_MENU_DEPTH)
				{
					int index = GetIntFromString(Index, 0);
					int currmen = pMgr->CurrMenu;

					if (CContextMenu* menu = pMgr->pCurrMenus[currmen])
					{
						if (index < menu->NumItems)
						{
							CXStr Str = menu->GetItemText(index, 1);
							strcpy_s(DataTypeTemp, Str.c_str());
							Dest.Ptr = &DataTypeTemp[0];
							return true;
						}
					}
				}
			}
			return false;
		}

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2CurrentZoneType

bool MQ2CurrentZoneType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	ZONEINFO* pCurrentZone = reinterpret_cast<ZONEINFO*>(pZoneInfo);

	MQTypeMember* pMember = MQ2CurrentZoneType::FindMember(Member);
	if (!pMember)
	{
		int zid = pCurrentZone->ZoneID & 0x7FFF;
		if (zid < MAX_ZONES)
		{
			if (ZONELIST* pZList = ((PWORLDDATA)pWorldData)->ZoneArray[zid])
			{
				MQVarPtr data;
				data.Ptr = &pZList;

				return pZoneType->GetMember(data, Member, Index, Dest);
			}
		}

		return false;
	}

	switch (static_cast<CurrentZoneMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (uint32_t)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case ID:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (CHARINFO* pChar = GetCharInfo())
		{
			Dest.Int = (pChar->zoneId & 0x7FFF);
			Dest.Type = pIntType;
			return true;
		}
		return false;

	case Name:
		strcpy_s(DataTypeTemp, pCurrentZone->LongName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ShortName:
		strcpy_s(DataTypeTemp, pCurrentZone->ShortName);
		Dest.Ptr = &DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case Type:
		Dest.DWord = pCurrentZone->OutDoor;
		Dest.Type = pIntType;
		return true;

	case Gravity:
		Dest.Float = pCurrentZone->ZoneGravity;
		Dest.Type = pFloatType;
		return true;

	case SkyType:
		Dest.DWord = pCurrentZone->SkyType;
		Dest.Type = pIntType;
		return true;

	case MinClip:
		Dest.Float = pCurrentZone->MinClip;
		Dest.Type = pFloatType;
		return true;

	case MaxClip:
		Dest.Float = pCurrentZone->MaxClip;
		Dest.Type = pFloatType;
		return true;

	case ZoneType:
		Dest.DWord = (*EQADDR_ZONETYPE);
		Dest.Type = pIntType;
		return true;

	case Dungeon:
	case Indoor:
		Dest.DWord = indoor;
		Dest.Type = pBoolType;
		return true;

	case Outdoor:
		Dest.DWord = outdoor;
		Dest.Type = pBoolType;
		return true;

	case NoBind:
		Dest.DWord = !bindable;
		Dest.Type = pBoolType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2ZoneType

bool MQ2ZoneType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	ZONELIST* pZone = static_cast<ZONELIST*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	MQTypeMember* pMember = MQ2ZoneType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ZoneMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, pZone->LongName);
		Dest.Ptr = &DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case ShortName:
		strcpy_s(DataTypeTemp, pZone->ShortName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ID:
		Dest.Int = pZone->Id & 0x7FFF;
		Dest.Type = pIntType;
		return true;

	case ZoneFlags:
		Dest.Int = pZone->ZoneFlags;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2BodyType

bool MQ2BodyType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2BodyType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<BodyMembers>(pMember->ID))
	{
	case ID:
		Dest.Ptr = VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, GetBodyTypeDesc(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2DeityType

bool MQ2DeityType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2DeityType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<DeityMembers>(pMember->ID))
	{
	case ID:
		Dest.Ptr = VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, pEverQuest->GetDeityDesc(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Team:
		strcpy_s(DataTypeTemp, szDeityTeam[GetDeityTeamByID(VarPtr.DWord)]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2ClassType

bool MQ2ClassType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2ClassType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ClassMembers>(pMember->ID))
	{
	case ID:
		Dest.Ptr = VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, GetClassDesc(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ShortName:
		strcpy_s(DataTypeTemp, pEverQuest->GetClassThreeLetterCode(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CanCast:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].CanCast;
			return true;
		}
		return false;

	case PureCaster:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].PureCaster;
			return true;
		}
		return false;

	case PetClass:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].PetClass;
			return true;
		}
		return false;

	case DruidType:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].DruidType;
			return true;
		}
		return false;

	case ShamanType:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].ShamanType;
			return true;
		}
		return false;

	case NecromancerType:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].NecroType;
			return true;
		}
		return false;

	case ClericType:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].ClericType;
			return true;
		}
		return false;

	case HealerType:
		Dest.DWord = (VarPtr.DWord == 2 || VarPtr.DWord == 6 || VarPtr.DWord == 10);
		Dest.Type = pBoolType;
		return true;

	case MercType:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 17)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].MercType;
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2RaceType

bool MQ2RaceType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2RaceType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<RaceMembers>(pMember->ID))
	{
	case ID:
		Dest.Ptr = VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, pEverQuest->GetRaceDesc(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2SwitchType

bool MQ2SwitchType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	DOOR* pTheSwitch = static_cast<DOOR*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2SwitchType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<SwitchMethods>(pMethod->ID))
		{
		case Toggle: {
			int KeyID = 0;
			int Skill = 0;

			if (PcProfile* pProfile = GetPcProfile())
			{
				if (pProfile->pInventoryArray && pProfile->pInventoryArray->Inventory.Cursor)
				{
					if (ITEMINFO* pItem = GetItemFromContents(pProfile->pInventoryArray->Inventory.Cursor))
					{
						if (pItem->Type != ITEMTYPE_NORMAL)
						{
							switch (pItem->Type)
							{
							case 33: // EQIC_KEY
								KeyID = pItem->ItemNumber;
								Skill = 0;
								break;
							case 35: // EQIC_LOCKPICK
								KeyID = pItem->ItemNumber;
								Skill = GetAdjustedSkill(SKILL_PICKLOCK);
								break;

							default:
								KeyID = pItem->ItemNumber;
								Skill = 0;
								break;
							}
						}
					}
				}
			}

			((EQSwitch*)pTheSwitch->pSwitch)->UseSwitch(((SPAWNINFO*)pLocalPlayer)->SpawnID, KeyID, Skill);
			return true;
		}

		default: break;
		}
		return false;
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2SwitchType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<SwitchMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (uint32_t)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case ID:
		Dest.DWord = pTheSwitch->ID;
		Dest.Type = pIntType;
		return true;

	case W:
	case X:
		Dest.Float = pTheSwitch->X;
		Dest.Type = pFloatType;
		return true;

	case N:
	case Y:
		Dest.Float = pTheSwitch->Y;
		Dest.Type = pFloatType;
		return true;

	case U:
	case Z:
		Dest.Float = pTheSwitch->Z;
		Dest.Type = pFloatType;
		return true;

	case DefaultW:
	case DefaultX:
		Dest.Float = pTheSwitch->DefaultX;
		Dest.Type = pFloatType;
		return true;

	case DefaultN:
	case DefaultY:
		Dest.Float = pTheSwitch->DefaultY;
		Dest.Type = pFloatType;
		return true;

	case DefaultU:
	case DefaultZ:
		Dest.Float = pTheSwitch->DefaultZ;
		Dest.Type = pFloatType;
		return true;

	case Heading:
		Dest.Float = pTheSwitch->Heading * 0.703125f;
		Dest.Type = pHeadingType;
		return true;

	case DefaultHeading:
		Dest.Float = pTheSwitch->DefaultHeading * 0.703125f;
		Dest.Type = pHeadingType;
		return true;

	case Open:
		Dest.DWord = (pTheSwitch->State == 1);
		Dest.Type = pBoolType;
		return true;

	case HeadingTo:
		Dest.Float = (float)(atan2f(((SPAWNINFO*)pCharSpawn)->Y - pTheSwitch->Y, pTheSwitch->X - ((SPAWNINFO*)pCharSpawn)->X) * 180.0f / PI + 90.0f);
		if (Dest.Float < 0.0f)
			Dest.Float += 360.0f;
		else if (Dest.Float >= 360.0f)
			Dest.Float -= 360.0f;
		Dest.Type = pHeadingType;
		return true;

	case Name:
		Dest.Ptr = &pTheSwitch->Name[0];
		Dest.Type = pStringType;
		return true;

	case Distance: {
		float BoundingRadius = 0;
		if (ActorBase* pBase = (ActorBase*)pTheSwitch->pSwitch)
		{
			BoundingRadius = pBase->GetBoundingRadius();
		}
		else
		{
			BoundingRadius = pTheSwitch->ScaleFactor * 0.01f;
		}

		if (BoundingRadius)
		{
			float thedist = GetDistance(pTheSwitch->X, pTheSwitch->Y) - (BoundingRadius / 2);
			if (thedist < 0.0f)
				thedist = 0.0f;
			Dest.Float = thedist;
		}
		else
		{
			Dest.Float = GetDistance(pTheSwitch->X, pTheSwitch->Y);
		}
		Dest.Type = pFloatType;
		return true;
	}

	case Distance3D: {
		float X = ((SPAWNINFO*)pCharSpawn)->X - pTheSwitch->X;
		float Y = ((SPAWNINFO*)pCharSpawn)->Y - pTheSwitch->Y;
		float Z = ((SPAWNINFO*)pCharSpawn)->Z - pTheSwitch->Z;

		float BoundingRadius = 0;
		float thedist = 0;

		if (ActorBase* pBase = (ActorBase*)pTheSwitch->pSwitch)
		{
			BoundingRadius = pBase->GetBoundingRadius();
		}
		else
		{
			BoundingRadius = pTheSwitch->ScaleFactor * 0.01f;
		}

		if (BoundingRadius)
		{
			thedist = sqrtf(X * X + Y * Y + Z * Z) - (BoundingRadius / 2);
			if (thedist < 0.0f)
				thedist = 0.0f;
			Dest.Float = thedist;
		}
		else
		{
			Dest.Float = sqrtf(X * X + Y * Y + Z * Z);
		}
		Dest.Type = pFloatType;
		return true;
	}

	case xLineOfSight:
		Dest.DWord = CastRay(GetCharInfo()->pSpawn, pTheSwitch->Y, pTheSwitch->X, pTheSwitch->Z);
		Dest.Type = pBoolType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2GroundType

bool MQ2GroundType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	GROUNDOBJECT* pGroundObject = static_cast<GROUNDOBJECT*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	if (pGroundObject->Type == GO_None)
		return false;

	SPAWNINFO* pMySpawn = reinterpret_cast<SPAWNINFO*>(pLocalPlayer);
	SPAWNINFO* pControlledSpawn = reinterpret_cast<SPAWNINFO*>(pCharSpawn);

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2GroundType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<GroundMethods>(pMethod->ID))
		{
		case Grab: {
			Dest.DWord = 0;
			Dest.Type = pBoolType;

			EQSWITCH* pSwitch = nullptr;

			if (pGroundObject->Type == GO_GroundType)
			{
				pSwitch = pGroundObject->pGroundItem->pSwitch;
			}

			if (pSwitch)
			{
				if (GROUNDITEM* pGround = pGroundObject->pGroundItem)
				{
					char szName[256] = { 0 };
					GetFriendlyNameForGroundItem(pGround, szName, sizeof(szName));

					float dist3d = Get3DDistance(pControlledSpawn->X, pControlledSpawn->Y, pControlledSpawn->Z, pGround->X, pGround->Y, pGround->Z);
					if (dist3d <= 20.0f)
					{
						// FIXME: Do not ZeroMemory SPAWNINFO
						SPAWNINFO tSpawn;
						ZeroMemory(&tSpawn, sizeof(tSpawn));
						strcpy_s(tSpawn.Name, szName);
						strcpy_s(tSpawn.DisplayedName, szName);
						tSpawn.Y = pGround->Y;
						tSpawn.X = pGround->X;
						tSpawn.Z = pGround->pSwitch->Z;
						tSpawn.Type = SPAWN_NPC;
						tSpawn.HPCurrent = 1;
						tSpawn.HPMax = 1;
						tSpawn.Heading = pGround->Heading;
						tSpawn.mActorClient.Race = pGround->DropID;
						tSpawn.StandState = STANDSTATE_STAND; // im using this for /clicked left item -eqmule

						memcpy(&EnviroTarget, &tSpawn, sizeof(EnviroTarget));
						pGroundTarget = pGround;

						*((DWORD*)__LMouseHeldTime) = ((CDISPLAY*)pDisplay)->TimeStamp - 0x45;
						pEverQuest->LMouseUp(-10000, -10000);

						ZeroMemory(&EnviroTarget, sizeof(EnviroTarget));
						ZeroMemory(&GroundObject, sizeof(GroundObject));

						pGroundTarget = nullptr;
						Dest.DWord = 1;
						return true;
					}
					else
					{
						MacroError("You are %.2f away from the %s, move within 20 feet of it to Grab it.", dist3d, szName);
					}
				}
			}

			return true;
		}

		case DoTarget:
		{
			char szName[256] = { 0 };

			// FIXME: Do not ZeroMemory SPAWNINFO
			SPAWNINFO tSpawn;
			ZeroMemory(&tSpawn, sizeof(tSpawn));

			if (pGroundObject->Type == GO_GroundType)
			{
				GetFriendlyNameForGroundItem(pGroundObject->pGroundItem, szName, sizeof(szName));
				tSpawn.Y = pGroundObject->pGroundItem->Y;
				tSpawn.X = pGroundObject->pGroundItem->X;
				tSpawn.Z = pGroundObject->pGroundItem->Z;
				tSpawn.Heading = pGroundObject->pGroundItem->Heading;
				tSpawn.mActorClient.Race = pGroundObject->pGroundItem->DropID;

				pGroundTarget = pGroundObject->pGroundItem;
				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pGroundTarget;
			}
			else
			{
				if (EQPlacedItem* Placed = static_cast<EQPlacedItem*>(pGroundObject->ObjPtr))
				{
					strcpy_s(szName, Placed->Name);
					tSpawn.Y = Placed->Y;
					tSpawn.X = Placed->X;
					tSpawn.Z = Placed->Z;
					tSpawn.Heading = Placed->Heading;
					tSpawn.mActorClient.Race = Placed->RealEstateItemID;
					GroundObject.Type = GO_ObjectType;
					GroundObject.ObjPtr = Placed;

					GroundObject.GroundItem.DropID = Placed->RealEstateItemID;
					GroundObject.GroundItem.DropSubID = Placed->RealEstateID;
					GroundObject.GroundItem.Expires = 0;
					GroundObject.GroundItem.Heading = Placed->Heading;
					GroundObject.GroundItem.ID = nullptr;
					strcpy_s(GroundObject.GroundItem.Name, Placed->Name);
					GroundObject.GroundItem.Pitch = Placed->Angle;
					GroundObject.GroundItem.pNext = nullptr;
					GroundObject.GroundItem.pPrev = nullptr;
					GroundObject.GroundItem.pSwitch = reinterpret_cast<EQSWITCH*>(Placed->pActor);
					GroundObject.GroundItem.Roll = Placed->Roll;
					GroundObject.GroundItem.Scale = Placed->Scale;
					GroundObject.GroundItem.Weight = 0;
					GroundObject.GroundItem.X = Placed->X;
					GroundObject.GroundItem.Y = Placed->Y;
					GroundObject.GroundItem.Z = Placed->Z;
					GroundObject.GroundItem.ZoneID = pMySpawn->GetZoneID() & 0x7FFF;
					pGroundTarget = &GroundObject.GroundItem;
				}
			}

			strcpy_s(tSpawn.Name, szName);
			strcpy_s(tSpawn.DisplayedName, szName);
			tSpawn.Type = SPAWN_NPC;
			tSpawn.HPCurrent = 1;
			tSpawn.HPMax = 1;
			tSpawn.StandState = STANDSTATE_STAND; // im using this for /clicked left item -eqmule
			memcpy(&EnviroTarget, &tSpawn, sizeof(EnviroTarget));
			Dest.Ptr = pGroundObject;
			Dest.Type = pGroundType;
			return true;
		}

		case DoFace: {
			float theDistance = 100000.0f;

			if (pGroundObject->Type == GO_GroundType)
			{
				gFaceAngle = atan2(
					pGroundObject->pGroundItem->X - pControlledSpawn->X,
					pGroundObject->pGroundItem->Y - pControlledSpawn->Y) * 256.0f / PI;

				theDistance = Get3DDistance(
					pControlledSpawn->X,
					pControlledSpawn->Y,
					pControlledSpawn->Z,
					pGroundObject->pGroundItem->X,
					pGroundObject->pGroundItem->Y,
					pGroundObject->pGroundItem->Z);

				gLookAngle = atan2(
					pGroundObject->pGroundItem->Z - pControlledSpawn->Z - pControlledSpawn->AvatarHeight * StateHeightMultiplier(pControlledSpawn->StandState),
					static_cast<float>(theDistance)) * 256.0f / PI;
			}
			else
			{
				if (EQPlacedItem* Placed = reinterpret_cast<EQPlacedItem*>(pGroundObject->ObjPtr))
				{
					gFaceAngle = atan2(
						Placed->X - pControlledSpawn->X,
						Placed->Y - pControlledSpawn->Y) * 256.0f / PI;

					theDistance = Get3DDistance(
						pControlledSpawn->X,
						pControlledSpawn->Y,
						pControlledSpawn->Z,
						Placed->X,
						Placed->Y,
						Placed->Z);

					gLookAngle = atan2(Placed->Z - pControlledSpawn->Z - pControlledSpawn->AvatarHeight * StateHeightMultiplier(pControlledSpawn->StandState),
						static_cast<float>(theDistance)) * 256.0f / PI;
				}
			}

			if (gFaceAngle >= 512.0f)
				gFaceAngle -= 512.0f;
			if (gFaceAngle < 0.0f)
				gFaceAngle += 512.0f;

			Dest.Ptr = pGroundObject;
			Dest.Type = pGroundType;
			return true;
		}

		}

		return false;
	}

	//----------------------------------------------------------------------------
	// member

	MQTypeMember* pMember = MQ2GroundType::FindMember(Member);
	if (!pMember)
		return false;

	if (pGroundObject->Type == GO_GroundType)
	{
		GROUNDITEM* pGround = pGroundObject->pGroundItem;
		switch (static_cast<GroundMembers>(pMember->ID))
		{
		case Address:
			Dest.DWord = (DWORD)VarPtr.Ptr;
			Dest.Type = pIntType;
			return true;

		case ID:
			Dest.DWord = pGround->DropID;
			Dest.Type = pIntType;
			return true;

		case SubID:
			Dest.DWord = pGround->DropSubID;
			Dest.Type = pIntType;
			return true;

		case ZoneID:
			Dest.DWord = (pGround->ZoneID & 0x7FFF);
			Dest.Type = pIntType;
			return true;

		case W:
		case X:
			Dest.Float = pGround->X;
			Dest.Type = pFloatType;
			return true;

		case N:
		case Y:
			Dest.Float = pGround->Y;
			Dest.Type = pFloatType;
			return true;

		case U:
		case Z:
			Dest.Float = pGround->Z;
			Dest.Type = pFloatType;
			return true;

		case Name:
			strcpy_s(DataTypeTemp, pGround->Name);
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case DisplayName: {
			DataTypeTemp[0] = '\0';
			GetFriendlyNameForGroundItem(pGround, DataTypeTemp, sizeof(DataTypeTemp));
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}

		case Heading:
			Dest.Float = pGround->Heading * 0.703125f;
			Dest.Type = pHeadingType;
			return true;

		case Distance:
			Dest.Float = GetDistance(pGround->X, pGround->Y);
			Dest.Type = pFloatType;
			return true;
		case Distance3D: {
			float X = pControlledSpawn->X - pGround->X;
			float Y = pControlledSpawn->Y - pGround->Y;
			float Z = 0;

			if (pGround->pSwitch)
				Z = pControlledSpawn->Z - pGround->pSwitch->Z;
			else
				Z = pControlledSpawn->Z - pGround->Z;

			Dest.Float = sqrtf(X * X + Y * Y + Z * Z);
			Dest.Type = pFloatType;
			return true;
		}

		case HeadingTo:
			Dest.Float = static_cast<float>(atan2f(
				pControlledSpawn->Y - pGround->Y,
				pGround->X - pControlledSpawn->X) * 180.0f / PI + 90.0f);

			if (Dest.Float < 0.0f)
				Dest.Float += 360.0f;
			else if (Dest.Float >= 360.0f)
				Dest.Float -= 360.0f;

			Dest.Type = pHeadingType;
			return true;

		case xLineOfSight:
			Dest.DWord = CastRay(GetCharInfo()->pSpawn, pGround->Y, pGround->X, pGround->Z);
			Dest.Type = pBoolType;
			return true;

		case First:
			Dest.Type = pGroundType;

			if (GROUNDITEM* pItem = pGround)
			{
				while (pItem->pPrev)
				{
					pItem = pItem->pPrev;
				}

				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pItem;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;

		case Last:
			Dest.Type = pGroundType;

			if (GROUNDITEM* pItem = pGround)
			{
				while (pItem->pNext)
				{
					pItem = pItem->pNext;
				}

				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pItem;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;

		case Next:
			Dest.Type = pGroundType;
			if (pGround->pNext)
			{
				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pGround->pNext;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;

		case Prev:
			Dest.Type = pGroundType;
			if (pGround->pPrev)
			{
				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pGround->pPrev;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;

		default: break;
		}

		return false;
	}

	//----------------------------------------------------------------------------
	// members

	EQPlacedItem* pGround = (EQPlacedItem*)pGroundObject->ObjPtr;

	switch (static_cast<GroundMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case ID:
		Dest.DWord = pGround->RealEstateItemID;
		Dest.Type = pIntType;
		return true;

	case SubID:
		Dest.DWord = pGround->RealEstateID;
		Dest.Type = pIntType;
		return true;

	case ZoneID:
		Dest.DWord = pMySpawn->GetZoneID() & 0x7FFF;
		Dest.Type = pIntType;
		return true;

	case W:
	case X:
		Dest.Float = pGround->X;
		Dest.Type = pFloatType;
		return true;

	case N:
	case Y:
		Dest.Float = pGround->Y;
		Dest.Type = pFloatType;
		return true;

	case U:
	case Z:
		Dest.Float = pGround->Z;
		Dest.Type = pFloatType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, pGround->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case DisplayName: {
		Dest.Type = pStringType;

		RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
		const RealEstateItemClient* pRealEstateItem = manager.GetItemByRealEstateAndItemIds(pGround->RealEstateID, pGround->RealEstateItemID);
		if (pRealEstateItem)
		{
			if (VePointer<CONTENTS> pCont = pRealEstateItem->Object.pItemBase)
			{
				if (ITEMINFO* pItem = pCont->GetItemDefinition())
				{
					strcpy_s(DataTypeTemp, pItem->Name);
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		return false;
	}

	case Heading:
		Dest.Float = pGround->Heading * 0.703125f;
		Dest.Type = pHeadingType;
		return true;

	case Distance:
		Dest.Float = GetDistance(pGround->X, pGround->Y);
		Dest.Type = pFloatType;
		return true;

	case Distance3D: {
		float X = pControlledSpawn->X - pGround->X;
		float Y = pControlledSpawn->Y - pGround->Y;
		float Z = pControlledSpawn->Z - pGround->Z;
		Dest.Float = sqrtf(X * X + Y * Y + Z * Z);
		Dest.Type = pFloatType;
		return true;
	}
	case HeadingTo:
		Dest.Float = static_cast<float>(atan2f(
			pControlledSpawn->Y - pGround->Y,
			pGround->X - pControlledSpawn->X) * 180.0f / PI + 90.0f);

		if (Dest.Float < 0.0f)
			Dest.Float += 360.0f;
		else if (Dest.Float >= 360.0f)
			Dest.Float -= 360.0f;

		Dest.Type = pHeadingType;
		return true;

	case xLineOfSight:
		Dest.DWord = CastRay(GetCharInfo()->pSpawn, pGround->Y, pGround->X, pGround->Z);
		Dest.Type = pBoolType;
		return true;

	case First:
		Dest.Type = pGroundType;
		if (EQPlacedItem* pItem = pGround)
		{
			while (pItem->pPrev)
			{
				pItem = pItem->pPrev;
			}
			GroundObject.Type = GO_ObjectType;
			GroundObject.ObjPtr = (void*)pItem;
			Dest.Ptr = &GroundObject;
			return true;
		}
		return false;

	case Last:
		Dest.Type = pGroundType;
		if (EQPlacedItem* pItem = pGround)
		{
			while (pItem->pNext)
			{
				pItem = pItem->pNext;
			}
			GroundObject.Type = GO_ObjectType;
			GroundObject.ObjPtr = (void*)pItem;
			Dest.Ptr = &GroundObject;
			return true;
		}
		return false;

	case Next:
		Dest.Type = pGroundType;
		if (pGround->pNext)
		{
			GroundObject.Type = GO_ObjectType;
			GroundObject.ObjPtr = (void*)pGround->pNext;
			Dest.Ptr = &GroundObject;
			return true;
		}
		return false;

	case Prev:
		Dest.Type = pGroundType;
		if (pGround->pPrev)
		{
			GroundObject.Type = GO_ObjectType;
			GroundObject.ObjPtr = (void*)pGround->pPrev;
			Dest.Ptr = &GroundObject;
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

bool MQ2GroundType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!VarPtr.Ptr)
		return false;

	GROUNDOBJECT* pObj = static_cast<GROUNDOBJECT*>(VarPtr.Ptr);

	if (pObj->Type == GO_GroundType)
	{
		GetFriendlyNameForGroundItem(pObj->pGroundItem, Destination, MAX_STRING);
		return true;
	}

	if (pObj->Type == GO_ObjectType)
	{
		RealEstateManagerClient& manager = RealEstateManagerClient::Instance();

		if (EQPlacedItem* pPlaced = (EQPlacedItem*)pObj->ObjPtr)
		{
			const RealEstateItemClient* pRealEstateItem = manager.GetItemByRealEstateAndItemIds(pPlaced->RealEstateID, pPlaced->RealEstateItemID);
			if (pRealEstateItem)
			{
				if (VePointer<CONTENTS> pCont = pRealEstateItem->Object.pItemBase)
				{
					if (ITEMINFO* pItem = pCont->GetItemDefinition())
					{
						strcpy_s(Destination, MAX_STRING, pItem->Name);
						return true;
					}
				}
			}
		}
	}

	return true;
}

bool MQ2GroundType::FromString(MQVarPtr& VarPtr, char* Source)
{
	int id = GetIntFromString(Source, 0);

	PGROUNDITEM pGroundItem = *(PGROUNDITEM*)pItemList;
	GROUNDOBJECT go;

	while (pGroundItem)
	{
		if (pGroundItem->DropID == id)
		{
			go.pGroundItem = pGroundItem;
			go.Type = GO_GroundType;
			memcpy(VarPtr.Ptr, &go, sizeof(GROUNDOBJECT));
			return true;
		}
		pGroundItem = pGroundItem->pNext;
	}

	// didn't find one, check objects...
	RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
	EQPlacedItemManager& pPIM = EQPlacedItemManager::Instance();

	if (EQPlacedItem* top = pPIM.Top)
	{
		while (top)
		{
			if (top->RealEstateItemID == id)
			{
				go.ObjPtr = (void*)top;
				go.Type = GO_ObjectType;
				memcpy(VarPtr.Ptr, &go, sizeof(GROUNDOBJECT));
				return true;
			}
			top = top->pNext;
		}
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2MacroQuestType

bool MQ2MacroQuestType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2MacroQuestType::FindMember(Member);
	if (!pMember)
		return pEverQuestType->GetMember(*(MQVarPtr*)& VarPtr.Ptr, Member, Index, Dest);

	switch (static_cast<MacroQuestMembers>(pMember->ID))
	{
	case Error:
		if (gszLastNormalError[0]) // QUIT SETTING THIS MANUALLY, USE MacroError, FatalError, ETC
		{
			Dest.Ptr = &gszLastNormalError[0];
			Dest.Type = pStringType;
			return true;
		}
		return false;

	case SyntaxError:
		if (gszLastSyntaxError[0])
		{
			Dest.Ptr = &gszLastSyntaxError[0];
			Dest.Type = pStringType;
			return true;
		}
		return false;

	case MQ2DataError:
		if (gszLastMQ2DataError[0])
		{
			Dest.Ptr = &gszLastMQ2DataError[0];
			Dest.Type = pStringType;
			return true;
		}
		return false;

	case BuildDate: {
		SYSTEMTIME st;
		HANDLE hFile;
		WIN32_FIND_DATA FileData;
		std::filesystem::path pathMQ2Main = std::filesystem::path(mq::internal_paths::MQRoot) / "MQ2Main.dll";
		hFile = FindFirstFile(pathMQ2Main.string().c_str(), &FileData);
		// Convert the creation time time to local time.
		FileTimeToSystemTime(&FileData.ftLastWriteTime, &st);
		FindClose(hFile);
		sprintf_s(DataTypeTemp, "%04d%02d%02d", st.wYear, st.wMonth, st.wDay);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}

	case Build:
		Dest.DWord = gBuild;
		Dest.Type = pIntType;
		return true;

	case Path:
		strcpy_s(DataTypeTemp, mq::internal_paths::MQRoot.c_str());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Version: {
		// Read the version resource and produce a version number

		// Get module handle to MQ2Main.dll
		HMODULE hMq2Main = nullptr;
		char szModulePath[2048];
		DataTypeTemp[0] = 0;

		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			reinterpret_cast<const char*>(&DataTypeTemp), &hMq2Main);
		GetModuleFileName(hMq2Main, szModulePath, 2048);

		// Get the size of the version information
		DWORD dwVerHnd = 0;
		uint32_t dwVerInfoSize = GetFileVersionInfoSizeA(szModulePath, &dwVerHnd);

		if (dwVerInfoSize)
		{
			// Retrieve the version information
			std::unique_ptr<uint8_t[]> pVersionInfo = std::make_unique<uint8_t[]>(dwVerInfoSize);
			GetFileVersionInfoA(szModulePath, dwVerHnd, dwVerInfoSize, pVersionInfo.get());

			uint32_t uVersionLen = 0;
			char* lpVersion = nullptr;
			bool bRetCode = VerQueryValueA(pVersionInfo.get(), "\\VarFileInfo\\Translation", (void**)&lpVersion, (uint32_t*)&uVersionLen);

			char szTranslation[20];
			if (bRetCode && uVersionLen && lpVersion)
			{
				sprintf_s(szTranslation, "%04x%04x", LOWORD(*lpVersion), HIWORD(*lpVersion));
			}
			else
			{
				strcpy_s(szTranslation, "041904b0");
			}

			char szGetName[256];
			sprintf_s(szGetName, "\\StringFileInfo\\%s\\FileVersion", szTranslation);

			uVersionLen = 0;
			char* lpString = nullptr;

			bRetCode = VerQueryValue((void*)pVersionInfo.get(), szGetName, (void**)& lpString, (uint32_t*)&uVersionLen);
			if (bRetCode && uVersionLen && lpString)
			{
				strcpy_s(DataTypeTemp, lpString);
			}
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}

	case InternalName: {
		// Read the version resource and produce an internal name string

		// Get module handle to MQ2Main.dll
		HMODULE hMq2Main = nullptr;
		char szModulePath[2048];
		DataTypeTemp[0] = 0;

		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			reinterpret_cast<const char*>(&DataTypeTemp), &hMq2Main);
		GetModuleFileName(hMq2Main, szModulePath, 2048);

		// Get the size of the version information
		DWORD dwVerHnd = 0;
		uint32_t dwVerInfoSize = GetFileVersionInfoSizeA(szModulePath, &dwVerHnd);

		if (dwVerInfoSize)
		{
			// Retrieve the version information
			std::unique_ptr<uint8_t[]> pVersionInfo = std::make_unique<uint8_t[]>(dwVerInfoSize);
			GetFileVersionInfoA(szModulePath, dwVerHnd, dwVerInfoSize, pVersionInfo.get());

			uint32_t uVersionLen = 0;
			uint32_t* lpVersion = nullptr;
			bool bRetCode = VerQueryValueA(pVersionInfo.get(), "\\VarFileInfo\\Translation", (void**)&lpVersion, (uint32_t*)&uVersionLen);

			char szTranslation[10];
			if (bRetCode && uVersionLen && lpVersion)
			{
				sprintf_s(szTranslation, "%04x%04x", LOWORD(*lpVersion), HIWORD(*lpVersion));
			}
			else
			{
				strcpy_s(szTranslation, "041904b0");
			}

			char szGetName[64];
			sprintf_s(szGetName, "\\StringFileInfo\\%s\\InternalName", szTranslation);

			uVersionLen = 0;
			char* lpString = nullptr;

			bRetCode = VerQueryValue((void*)pVersionInfo.get(), szGetName, (void**)& lpString, (uint32_t*)&uVersionLen);
			if (bRetCode && uVersionLen && lpString)
			{
				strcpy_s(DataTypeTemp, lpString);
			}
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}

	case Parser:
		Dest.DWord = gParserVersion;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2CharSelectListType

bool MQ2CharSelectListType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2CharSelectListType::FindMember(Member);
	if (!pMember)
		return false;

	EVERQUEST* pEQ = reinterpret_cast<EVERQUEST*>(pEverQuest);

	switch (static_cast<CharSelectListMembers>(pMember->ID))
	{
	case Name:
		Dest.Type = pStringType;
		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			strcpy_s(DataTypeTemp, pEQ->pCharSelectPlayerArray[VarPtr.Int].Name);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Level:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			Dest.DWord = pEQ->pCharSelectPlayerArray[VarPtr.Int].Level;
			return true;
		}
		return false;

	case Class:
		Dest.DWord = 0;
		Dest.Type = pStringType;

		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			strcpy_s(DataTypeTemp, GetClassDesc(pEQ->pCharSelectPlayerArray[VarPtr.Int].Class));
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Race:
		Dest.DWord = 0;
		Dest.Type = pStringType;

		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			strcpy_s(DataTypeTemp, pEverQuest->GetRaceDesc(pEQ->pCharSelectPlayerArray[VarPtr.Int].Race));
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ZoneID:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			int zoneid = pEQ->pCharSelectPlayerArray[VarPtr.Int].CurZoneID;
			Dest.DWord = (zoneid & 0x7FFF);

			return true;
		}
		return false;

	case Count:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pEQ)
		{
			Dest.DWord = pEQ->pCharSelectPlayerArray.Count;
		}
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2EverQuestType

bool MQ2EverQuestType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2EverQuestType::FindMember(Member);
	if (!pMember)
		return false;

	EVERQUEST* pEQ = (EVERQUEST*)pEverQuest;

	switch (static_cast<EverQuestMembers>(pMember->ID))
	{
	case xHWND:
		if (EQW_GetDisplayWindow)
			Dest.DWord = (DWORD)EQW_GetDisplayWindow();
		else
			Dest.DWord = *(DWORD*)EQADDR_HWND;
		Dest.Type = pIntType;
		return true;

	case GameState:
		if (gGameState == GAMESTATE_CHARSELECT)
			strcpy_s(DataTypeTemp, "CHARSELECT");
		else if (gGameState == GAMESTATE_INGAME)
			strcpy_s(DataTypeTemp, "INGAME");
		else if (GetGameState() == GAMESTATE_PRECHARSELECT)
			strcpy_s(DataTypeTemp, "PRECHARSELECT");
		else
			strcpy_s(DataTypeTemp, "UNKNOWN");

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case LoginName:
		Dest.Type = pStringType;
		if (const char* pTemp = GetLoginName())
		{
			strcpy_s(DataTypeTemp, pTemp);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Server:
		Dest.Type = pStringType;
		if (EQADDR_SERVERNAME[0])
		{
			strcpy_s(DataTypeTemp, EQADDR_SERVERNAME);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case LastCommand:
		Dest.Type = pStringType;
		if (szLastCommand[0])
		{
			Dest.Ptr = &szLastCommand[0];
			return true;
		}
		return false;

	case LastTell:
		Dest.Type = pStringType;
		if (EQADDR_LASTTELL[0])
		{
			strcpy_s(DataTypeTemp, EQADDR_LASTTELL);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Running:
		Dest.DWord = (DWORD)clock();
		Dest.Type = pIntType;
		return true;

	case MouseX:
		Dest.DWord = EQADDR_MOUSE->X;
		Dest.Type = pIntType;
		return true;

	case MouseY:
		Dest.DWord = EQADDR_MOUSE->Y;
		Dest.Type = pIntType;
		return true;

	case Ping:
		Dest.DWord = pConnection->Last;
		Dest.Type = pIntType;
		return true;

	case ChatChannels:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pEQ->ChatService)
		{
			Dest.DWord = pEQ->ChatService->ActiveChannels;
			return true;
		}
		return false;

	case ChatChannel:
		Dest.Type = pStringType;
		if (pEQ->ChatService)
		{
			CHATSERVICE* pChat = pEQ->ChatService;
			if (IsNumber(Index))
			{
				int index = GetIntFromString(Index, 0) - 1;
				if (pChat->ActiveChannels && index >= 0 && index < pChat->ActiveChannels)
				{
					strcpy_s(DataTypeTemp, pChat->ChannelList->ChannelName[index]);
					Dest.Ptr = &DataTypeTemp[0];
					Dest.Type = pStringType;
					return true;
				}
			}
			else
			{
				char Name[MAX_STRING] = { 0 };
				strcpy_s(Name, Index);

				for (int i = 0; i < pChat->ActiveChannels; i++)
				{
					if (!_stricmp(Name, pChat->ChannelList->ChannelName[i]))
					{
						Dest.DWord = 1;
						Dest.Type = pBoolType;
						return true;
					}
				}
			}
		}
		return false;

	case ViewportX:
		Dest.DWord = ScreenX;
		Dest.Type = pIntType;
		return true;

	case ViewportY:
		Dest.DWord = ScreenY;
		Dest.Type = pIntType;
		return true;

	case ViewportXMax:
		Dest.DWord = ScreenXMax;
		Dest.Type = pIntType;
		return true;

	case ViewportYMax:
		Dest.DWord = ScreenYMax;
		Dest.Type = pIntType;
		return true;

	case ViewportXCenter:
		Dest.DWord = ScreenXMax / 2;
		Dest.Type = pIntType;
		return true;

	case ViewportYCenter:
		Dest.DWord = ScreenYMax / 2;
		Dest.Type = pIntType;
		return true;

	case LClickedObject:
		Dest.DWord = gLClickedObject;
		Dest.Type = pBoolType;
		return true;

	case WinTitle: {
		HWND hEQWnd = GetEQWindowHandle();
		if (hEQWnd)
		{
			GetWindowTextA(hEQWnd, DataTypeTemp, MAX_STRING);

			if (DataTypeTemp[0] != 0)
			{
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}

		return false;
	}

	case PID:
		Dest.DWord = GetCurrentProcessId();
		Dest.Type = pIntType;
		return true;

	case xScreenMode:
		Dest.DWord = ScreenMode;
		Dest.Type = pIntType;
		return true;

	case PPriority:
		strcpy_s(DataTypeTemp, "NORMAL");

		if (HANDLE heqg = OpenProcess(PROCESS_QUERY_INFORMATION, false, GetCurrentProcessId()))
		{
			DWORD prio = GetPriorityClass(heqg);
			switch (prio)
			{
			case IDLE_PRIORITY_CLASS:
				strcpy_s(DataTypeTemp, "LOW");
				break;
			case BELOW_NORMAL_PRIORITY_CLASS:
				strcpy_s(DataTypeTemp, "BELOW NORMAL");
				break;
			case NORMAL_PRIORITY_CLASS:
				prio = NORMAL_PRIORITY_CLASS;
				strcpy_s(DataTypeTemp, "NORMAL");
				break;
			case ABOVE_NORMAL_PRIORITY_CLASS:
				strcpy_s(DataTypeTemp, "ABOVE NORMAL");
				break;
			case HIGH_PRIORITY_CLASS:
				strcpy_s(DataTypeTemp, "HIGH");
				break;
			case REALTIME_PRIORITY_CLASS:
				strcpy_s(DataTypeTemp, "REALTIME");
				break;
			default:
				break;
			}

			CloseHandle(heqg);
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case LayoutCopyInProgress:
		Dest.DWord = *(BYTE*)CSidlScreenWnd__m_layoutCopy;
		Dest.Type = pBoolType;
		return true;

	case LastMouseOver:
		Dest.Type = pWindowType;
		if (pWndMgr)
		{
			Dest.Ptr = pWndMgr->LastMouseOver;
			Dest.HighPart = 24; // ??
			return true;
		}
		return false;

	case CharSelectList:
		Dest.DWord = 0;
		Dest.Type = pCharSelectListType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int num = GetIntFromString(Index, 0) - 1;
				if (num < 0)
					num = 0;

				if (pEQ)
				{
					if (num <= pEQ->pCharSelectPlayerArray.Count)
					{
						Dest.DWord = num;
						return true;
					}
				}
			}
			else
			{
				char szName[256] = { 0 };
				if (pEQ)
				{
					for (int i = 0; i < pEQ->pCharSelectPlayerArray.Count; i++)
					{
						strcpy_s(szName, pEQ->pCharSelectPlayerArray[i].Name);
						if (!_stricmp(Index, szName))
						{
							Dest.DWord = i;
							return true;
						}
					}
				}
			}
		}
		return false;

	case CurrentUI:
		Dest.Type = pStringType;
		if (CHARINFO* pCharInfo = GetCharInfo())
		{
			char szFilename[MAX_STRING] = { 0 };
			sprintf_s(szFilename, "UI_%s_%s.ini", pCharInfo->Name, EQADDR_SERVERNAME);
			GetPrivateProfileString("Main", "UISkin", "default", DataTypeTemp, MAX_STRING, szFilename);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case IsDefaultUILoaded:
		Dest.DWord = 1;
		Dest.Type = pBoolType;

		if (CHARINFO* pCharInfo = GetCharInfo())
		{
			char szFilename[MAX_STRING] = { 0 };
			sprintf_s(szFilename, "UI_%s_%s.ini", pCharInfo->Name, EQADDR_SERVERNAME);
			GetPrivateProfileString("Main", "UISkin", "default", DataTypeTemp, MAX_STRING, szFilename);

			if (_stricmp(DataTypeTemp, "default"))
			{
				Dest.DWord = 0;
			}
		}
		return true;

	case Foreground:
		Dest.DWord = gbInForeground;
		Dest.Type = pBoolType;
		return true;

	case ValidLoc: {
		//usage /echo ${EverQuest.ValidLoc[123 456 789]}

		auto szLoc = std::make_unique<char[]>(MAX_STRING);
		GetArg(szLoc.get(), Index, 1);
		float X = GetFloatFromString(szLoc.get(), 0);
		GetArg(szLoc.get(), Index, 2);
		float Y = GetFloatFromString(szLoc.get(), 0);
		GetArg(szLoc.get(), Index, 3);
		float Z = GetFloatFromString(szLoc.get(), 0);

		Dest.DWord = pLocalPlayer->IsValidTeleport(Y, X, Z, 0, 0);
		Dest.Type = pBoolType;
		return true;
	}

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2TimeType

bool MQ2TimeType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	tm* pTime = reinterpret_cast<tm*>(VarPtr.Ptr);
	if (!pTime)
		return false;

	MQTypeMember* pMember = MQ2TimeType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TimeMembers>(pMember->ID))
	{
	case Hour:
		Dest.DWord = pTime->tm_hour;
		Dest.Type = pIntType;
		return true;

	case Hour12: {
		unsigned long Hour = pTime->tm_hour % 12;
		if (!Hour)
			Hour = 12;
		sprintf_s(DataTypeTemp, "%d %s", Hour, pTime->tm_hour > 12 ? "PM" : "AM");
		Dest.Ptr = &DataTypeTemp[0],
			Dest.Type = pStringType;
		return true;
	}

	case Minute:
		Dest.DWord = pTime->tm_min;
		Dest.Type = pIntType;
		return true;

	case Second:
		Dest.DWord = pTime->tm_sec;
		Dest.Type = pIntType;
		return true;

	case DayOfWeek:
		Dest.DWord = pTime->tm_wday + 1;
		Dest.Type = pIntType;
		return true;

	case Day:
		Dest.DWord = pTime->tm_mday;
		Dest.Type = pIntType;
		return true;

	case Month:
		Dest.DWord = pTime->tm_mon + 1;
		Dest.Type = pIntType;
		return true;

	case Year:
		Dest.DWord = pTime->tm_year + 1900;
		Dest.Type = pIntType;
		return true;

	case Time12: {
		uint32_t Hour = pTime->tm_hour % 12;
		if (!Hour)
			Hour = 12;

		sprintf_s(DataTypeTemp, "%02d:%02d:%02d", Hour, pTime->tm_min, pTime->tm_sec);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	case Time24:
		sprintf_s(DataTypeTemp, "%02d:%02d:%02d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Date:
		sprintf_s(DataTypeTemp, "%02d/%02d/%04d", pTime->tm_mon + 1, pTime->tm_mday, pTime->tm_year + 1900);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Night:
		Dest.DWord = ((pTime->tm_hour < 7) || (pTime->tm_hour > 20));
		Dest.Type = pBoolType;
		return true;

	case SecondsSinceMidnight:
		Dest.DWord = pTime->tm_hour * 3600 + pTime->tm_min * 60 + pTime->tm_sec;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2HeadingType

bool MQ2HeadingType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2HeadingType::FindMember(Member);
	if (!pMember)
		return false;

	float Heading = 360.0f - VarPtr.Float;
	switch (static_cast<HeadingMembers>(pMember->ID))
	{
	case Clock:
		Dest.DWord = ((static_cast<int>(Heading) + 15) / 30) % 12;
		if (Dest.DWord == 0)
			Dest.DWord = 12;
		Dest.Type = pIntType;
		return true;

	case Degrees:
		Dest.Float = Heading;
		Dest.Type = pFloatType;
		return true;

	case DegreesCCW:
		Dest.Float = VarPtr.Float;
		Dest.Type = pFloatType;
		return true;

	case ShortName:
		strcpy_s(DataTypeTemp, szHeadingNormalShort[static_cast<int>(Heading / 22.5f + 0.5f) % 16]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, szHeadingNormal[static_cast<int>(Heading / 22.5f + 0.5f) % 16]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2HeadingType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pHeadingType && Source.Type != pFloatType)
		VarPtr.Float = (float)Source.DWord;
	else
		VarPtr.Float = Source.Float;

	return true;
}

//----------------------------------------------------------------------------
// MQ2CorpseType

bool MQ2CorpseType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pActiveCorpse || !pLootWnd)
		return false;

	MQTypeMember* pMember = MQ2CorpseType::FindMember(Member);
	if (!pMember)
	{
		MQVarPtr data;
		data.Ptr = pActiveCorpse;
		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<CorpseMembers>(pMember->ID))
	{
	case Open:
		Dest.DWord = 1; // obviously, since we're this far
		Dest.Type = pBoolType;
		return true;

	case Item:
		Dest.Type = pItemType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nIndex = GetIntFromString(Index, 0) - 1;
				if (nIndex < 0 || nIndex >= NUM_INV_SLOTS)
					return false;

				if (Dest.Ptr = pLootWnd->pInventoryArray->InventoryArray[nIndex])
				{
					return true;
				}
			}
			else
			{
				// name
				bool bExact = false;
				char* pName1 = Index;
				if (*pName1 == '=')
				{
					bExact = true;
					pName1++;
				}

				for (int nIndex = 0; nIndex < NUM_INV_SLOTS; nIndex++)
				{
					if (CONTENTS* pContents = pLootWnd->pInventoryArray->InventoryArray[nIndex])
					{
						const char* itemName = GetItemFromContents(pContents)->Name;

						if (bExact)
						{
							if (ci_equals(itemName, pName1))
							{
								Dest.Ptr = pContents;
								return true;
							}
						}
						else
						{
							if (ci_find_substr(itemName, pName1) != -1)
							{
								Dest.Ptr = pContents;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case Items:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (int index = 0; index < 31; index++)
		{
			if (pLootWnd->pInventoryArray->InventoryArray[index])
				Dest.DWord++;
		}
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2MerchantType

bool MQ2MerchantType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pMerchantWnd)
		return false;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2MerchantType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<MerchantMethods>(pMethod->ID))
		{
		case SelectItem: {
			if (pMerchantWnd->IsVisible())
			{
				bool bFound = false;
				int listIndex = 0;
				CONTENTS* pCont = nullptr;
				ITEMINFO* pItem = nullptr;

				for (int i = 0; i < pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer.GetSize(); i++)
				{
					if (pCont = pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer[i].pCont)
					{
						if (pItem = GetItemFromContents(pCont))
						{
							if (MaybeExactCompare(pItem->Name, Index))
							{
								listIndex = i;
								bFound = true;
								break;
							}
						}
					}
				}

				if (bFound)
				{
					// TODO: Maybe this should just be a straight global index copy.
					ItemGlobalIndex To;
					To.Location = eItemContainerMerchant;
					To.GetIndex().SetSlot(0, pCont->GetGlobalIndex().GetTopSlot());
					To.GetIndex().SetSlot(1, pCont->GetGlobalIndex().GetIndex().GetSlot(1));

					for (int i = 0; i < pMerchantWnd->ItemsList->ItemsArray.GetLength(); i++)
					{
						CXStr Str = pMerchantWnd->ItemsList->GetItemText(i, 1);

						if (ci_equals(Str, pItem->Name))
						{
							pMerchantWnd->ItemsList->SetCurSel(i);
						}
					}

					pMerchantWnd->SelectBuySellSlot(To, listIndex);
					return true;
				}
			}
			return true;
		}

		case Buy: {
			if (pMerchantWnd->IsVisible())
			{
				int Qty = GetIntFromString(Index, 0);
				if (Qty < 1)
					return false;

				if (pMerchantWnd->pSelectedItem
					&& pMerchantWnd->pSelectedItem->GetGlobalIndex().GetLocation() == eItemContainerMerchant)
				{
					pMerchantWnd->PageHandlers[RegularMerchantPage]->RequestGetItem(Qty);
					return true;
				}
			}
			return true;
		}

		case Sell: {
			if (pMerchantWnd->IsVisible())
			{
				int Qty = GetIntFromString(Index, 0);
				if (Qty < 1)
					return false;

				if (pMerchantWnd->pSelectedItem
					&& pMerchantWnd->pSelectedItem->GetGlobalIndex().GetLocation() == eItemContainerPossessions)
				{
					pMerchantWnd->PageHandlers[RegularMerchantPage]->RequestPutItem(Qty);
					return true;
				}
			}
			return true;
		}

		case OpenWindow: {
			MQSpawnSearch SearchSpawn;
			ClearSearchSpawn(&SearchSpawn);
			SearchSpawn.FRadius = 999999.0f;
			SearchSpawn.bMerchant = true;

			if (pTarget && ((SPAWNINFO*)pTarget)->mActorClient.Class == 41)
			{
				pEverQuest->RightClickedOnPlayer(pTarget, 0);
				return true;
			}
			else if (SPAWNINFO* pSpawn = SearchThroughSpawns(&SearchSpawn, (SPAWNINFO*)pLocalPlayer))
			{
				*ppTarget = (PlayerClient*)pSpawn;
				pEverQuest->RightClickedOnPlayer((PlayerClient*)pSpawn, 0);
				return true;
			}
			return true;
		}

		case CloseWindow:
			if (pMerchantWnd->IsVisible())
			{
				// Need to call deactivate here.
				WriteChatf("Not implemented yet");
				return true;
			}
			return true;

		default: break;
		}

		return false;
	}

	if (!pActiveMerchant)
		return false;

	MQTypeMember* pMember = MQ2MerchantType::FindMember(Member);
	if (!pMember)
	{
		MQVarPtr data;
		data.Ptr = pActiveMerchant;

		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<MerchantMembers>(pMember->ID))
	{
	case Open:
		Dest.DWord = pMerchantWnd->IsVisible();
		Dest.Type = pBoolType;
		return true;

	case ItemsReceived:
		Dest.DWord = gItemsReceived;
		Dest.Type = pBoolType;
		return true;

	case Item:
		Dest.Type = pItemType;

		if (Index[0])
		{
			if (pMerchantWnd)
			{
				VePointer<MerchantPageHandler>& page = pMerchantWnd->PageHandlers[RegularMerchantPage];

				if (IsNumber(Index))
				{
					// by index
					int nIndex = GetIntFromString(Index, 0) - 1;
					if (nIndex < 0)
						return false;

					if (nIndex < page->MaxItems)
					{
						if (Dest.Ptr = page->ItemContainer[nIndex].pCont)
						{
							return true;
						}
					}
				}
				else
				{
					// by name
					for (int nIndex = 0; nIndex < page->MaxItems; nIndex++)
					{
						if (CONTENTS* pContents = page->ItemContainer[nIndex].pCont)
						{
							const char* itemName = GetItemFromContents(pContents)->Name;

							if (MaybeExactCompare(itemName, Index))
							{
								Dest.Ptr = pContents;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case Items:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pMerchantWnd)
		{
			Dest.DWord = pMerchantWnd->PageHandlers[RegularMerchantPage]->MaxItems;
		}
		return true;

	case SelectedItem:
		if (pMerchantWnd)
		{
			Dest.Ptr = pMerchantWnd->pSelectedItem.get();
			Dest.Type = pItemType;
			return true;
		}

	case Markup: {
		Dest.Float = pMerchantWnd->MerchantGreed;
		Dest.Type = pFloatType;
		return true;
	}

	case Full:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pMerchantWnd)
		{
			VePointer<MerchantPageHandler>& page = pMerchantWnd->PageHandlers[RegularMerchantPage];
			Dest.DWord = 1;

			// is it possible to hit this? max is 200 i think?
			if (page->MaxItems < 128)
			{
				Dest.DWord = 0;
				return true;
			}

			for (int index = 0; index < page->MaxItems; index++)
			{
				if (!page->ItemContainer[index].pCont)
				{
					Dest.DWord = 0;
					break;
				}
			}

			return true;
		}
		return false;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2PointMerchantItemType

bool MQ2PointMerchantItemType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pMerchantWnd)
		return false;

	if (VarPtr.Int < 0 || VarPtr.Int > pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer.GetSize())
		return false;

	int index = VarPtr.Int;
	MQTypeMember* pMember = MQ2PointMerchantItemType::FindMember(Member);

	if (!pMember)
		return false;

	ITEMINFO* pItem = nullptr;
	CONTENTS* pCont = nullptr;
	if (pCont = pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer[index].pCont)
	{
		pItem = GetItemFromContents(pCont);
	}

	if (!pItem)
		return false;

	switch (static_cast<PointMerchantItemMembers>(pMember->ID))
	{
	case Name:
		strcpy_s(DataTypeTemp, pItem->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ItemID:
		Dest.Int = pCont->ID;
		Dest.Type = pIntType;
		return true;

	case Price:
		if (pItem->LDTheme)
			Dest.Int64 = pItem->LDCost;
		else
			Dest.Int64 = pCont->Price;
		Dest.Type = pInt64Type;
		return true;

	case ThemeID:
		Dest.Int = pItem->LDTheme;
		Dest.Type = pIntType;
		return true;

	case IsStackable:
		Dest.Int = ((EQ_Item*)pCont)->IsStackable();
		Dest.Type = pBoolType;
		return true;

	case IsLore:
		Dest.Int = pItem->Lore;
		Dest.Type = pBoolType;
		return true;

	case RaceMask:
		Dest.Int = pItem->Races;
		Dest.Type = pIntType;
		return true;

	case ClassMask:
		Dest.Int = pItem->Classes;
		Dest.Type = pIntType;
		return true;

	case CanUse:
		Dest.Int = pCharData->CanUseItem(&pCont, false, false);
		Dest.Type = pBoolType;
		return true;
	}
	return false;
}

//----------------------------------------------------------------------------
// MQ2PointMerchantType

bool MQ2PointMerchantType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pMerchantWnd)
		return false;

	MQTypeMember* pMember = MQ2PointMerchantType::FindMember(Member);
	if (!pMember)
	{
		MQVarPtr data;
		data.Ptr = pActiveMerchant;

		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<PointMerchantMembers>(pMember->ID))
	{
	case Item:
		Dest.Int = 0;
		Dest.Type = pPointMerchantItemType;
		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index >= 0 && index < pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer.GetSize())
			{
				Dest.Int = index;
				return true;
			}
		}
		else
		{
			if (Index[0] != '\0')
			{
				for (int i = 0; i < pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer.GetSize(); i++)
				{
					auto name = GetItemFromContents(pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer[i].pCont)->Name;
					if (!_stricmp(name, Index))
					{
						Dest.Int = i;
						return true;
					}
				}
			}
		}

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2MercenaryType

bool MQ2MercenaryType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	SPAWNINFO* pSpawn = reinterpret_cast<SPAWNINFO*>(VarPtr.Ptr);
	if (!pSpawn)
		return false;

	MQTypeMember* pMember = MQ2MercenaryType::FindMember(Member);
	if (!pMember)
	{
		if (!pSpawn->SpawnID)
			return false;

		return pSpawnType->GetMember(VarPtr, Member, Index, Dest);
	}

	switch (static_cast<MercenaryMembers>(pMember->ID))
	{
	case AAPoints:
		Dest.DWord = GetCharInfo()->MercAAPoints;
		Dest.Type = pIntType;
		return true;

	case Stance:
		strcpy_s(DataTypeTemp, "NULL");
		if (pMercInfo->HaveMerc)
		{
			for (int n = 0; n < pMercInfo->NumStances; n++)
			{
				if (pMercInfo->pMercStanceData[n]->nStance == pMercInfo->ActiveStance)
				{
					strcpy_s(DataTypeTemp, pCDBStr->GetString(pMercInfo->pMercStanceData[n]->nDbStance, eMercenaryStanceName));
					break;
				}
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case State:
		switch (pMercInfo->MercState)
		{
		case 0:
			strcpy_s(DataTypeTemp, "DEAD");
			break;

		case 1:
			strcpy_s(DataTypeTemp, "SUSPENDED");
			break;

		case 5:
			if (pMercInfo->HaveMerc) {
				strcpy_s(DataTypeTemp, "ACTIVE");
			}
			else {
				strcpy_s(DataTypeTemp, "NOMERC");
			}
			break;

		default:
			strcpy_s(DataTypeTemp, "UNKNOWN");
			break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case StateID:
		Dest.DWord = pMercInfo->MercState;
		Dest.Type = pIntType;
		return true;

	case xIndex:
		Dest.DWord = pMercInfo->CurrentMercIndex + 1;
		Dest.Type = pIntType;
		return true;

#ifdef MULETESTING
		//work in progress -eqmule Aug 03 2015
	case CurrentHPs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->CurrHP;
			return true;
		}
		return false;
	case MaxHPs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->MaxHP;
			return true;
		}
		return false;
	case PctHPs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			LONG maxhp = pStats->MaxHP;
			if (maxhp != 0)
				Dest.Int = pStats->CurrHP * 100 / maxhp;
			return true;
		}
		return false;
	case CurrentMana:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->CurrMana;
			return true;
		}
		return false;
	case MaxMana:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->MaxMana;
			return true;
		}
		return false;
	case PctMana:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			if (unsigned long Temp = pStats->MaxMana) {
				Dest.Int = pStats->CurrMana * 100 / Temp;
				return true;
			}
		}
		return false;
	case AC:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->AC;
			return true;
		}
		return false;
	case AGI:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->AGI;
			return true;
		}
		return false;
	case Attack:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->Attack;
			return true;
		}
		return false;
	case CHA:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->CHA;
			return true;
		}
		return false;
	case CombatEnduranceRegen:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->CombatEnduranceRegen;
			return true;
		}
		return false;
	case CombatHPRegen:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->CombatHPRegen;
			return true;
		}
		return false;
	case CurrentEndurance:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->CurrEndurance;
			return true;
		}
		return false;
	case MaxEndurance:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->MaxEndurance;
			return true;
		}
		return false;
	case PctEndurance:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			if (unsigned long Temp = pStats->MaxEndurance)
				Dest.Int = (pStats->CurrEndurance * 100) / Temp;
			return true;
		}
		return false;
	case DEX:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->DEX;
			return true;
		}
		return false;
	case Haste:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->Haste;
			return true;
		}
		return false;
	case HealAmount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->HealAmount;
			return true;
		}
		return false;
	case INT:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->INT;
			return true;
		}
		return false;
	case SpellDamage:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->SpellDamage;
			return true;
		}
		return false;
	case STA:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->STA;
			return true;
		}
		return false;
	case STR:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->STR;
			return true;
		}
		return false;
	case WIS:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->WIS;
			return true;
		}
		return false;
#endif
	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2PetType

bool MQ2PetType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	SPAWNINFO* pSpawn = reinterpret_cast<SPAWNINFO*>(VarPtr.Ptr);
	if (!pSpawn)
		return false;

	MQTypeMember* pMember = MQ2PetType::FindMember(Member);
	if (!pMember)
	{
		if (!pSpawn->SpawnID)
			return false;

		return pSpawnType->GetMember(VarPtr, Member, Index, Dest);
	}

	if (!pPetInfoWnd)
		return false;

	switch (static_cast<PetMembers>(pMember->ID))
	{
	case Buff:
		Dest.Type = pSpellType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0)
				return false;

			if (nBuff >= NUM_BUFF_SLOTS)
				return false;

			if (pPetInfoWnd->Buff[nBuff] == -1 || pPetInfoWnd->Buff[nBuff] == 0)
				return false;

			if (Dest.Ptr = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
			{
				Dest.Type = pSpellType;
				return true;
			}
		}
		else
		{
			for (int nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
			{
				if (SPELL* pSpell = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
				{
					if (!_strnicmp(Index, pSpell->Name, strlen(Index)))
					{
						Dest.DWord = nBuff + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
			}
		}
		return false;

	case BuffDuration:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0)
				return false;

			if (nBuff >= NUM_BUFF_SLOTS)
				return false;

			if (pPetInfoWnd->Buff[nBuff] == -1 || pPetInfoWnd->Buff[nBuff] == 0)
				return false;

			Dest.UInt64 = pPetInfoWnd->PetBuffTimer[nBuff];
			return true;
		}
		else
		{
			for (int nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
			{
				if (SPELL* pSpell = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
				{
					if (!_strnicmp(Index, pSpell->Name, strlen(Index)))
					{
						Dest.UInt64 = pPetInfoWnd->PetBuffTimer[nBuff];
						return true;
					}
				}
			}
		}
		return false;

	case Combat:
		Dest.DWord = pSpawn->WhoFollowing != nullptr;
		Dest.Type = pBoolType;
		return true;

	case GHold:
		Dest.DWord = pPetInfoWnd->GHold;
		Dest.Type = pBoolType;
		return true;

	case Hold:
		Dest.DWord = pPetInfoWnd->Hold;
		Dest.Type = pBoolType;
		return true;

	case ReGroup:
		Dest.DWord = pPetInfoWnd->ReGroup;
		Dest.Type = pBoolType;
		return true;

	case Stance:
		if (pPetInfoWnd->Follow)
			strcpy_s(DataTypeTemp, "FOLLOW");
		else
			strcpy_s(DataTypeTemp, "GUARD");
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Stop:
		Dest.DWord = pPetInfoWnd->Stop;
		Dest.Type = pBoolType;
		return true;

	case Target:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->WhoFollowing)
		{
			return true;
		}
		return false;

	case Taunt:
		Dest.DWord = pPetInfoWnd->Taunt;
		Dest.Type = pBoolType;
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2InvSlotType

// item slots:
// 2000-2015 bank window
// 2500-2503 shared bank
// 5000-5031 loot window
// 3000-3015 trade window (including npc) 3000-3007 are your slots, 3008-3015 are other character's slots
// 4000-4010 world container window
// 6000-6080 merchant window
// 7000-7080 bazaar window
// 8000-8031 inspect window
bool MQ2InvSlotType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2InvSlotType::FindMember(Member);
	if (!pMember)
		return false;

	int nInvSlot = VarPtr.Int;

	switch (static_cast<InvSlotMembers>(pMember->ID))
	{
	case ID:
		Dest.DWord = VarPtr.Int;
		Dest.Type = pIntType;
		return true;

	case Item:
		Dest.Type = pItemType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			if (pProfile->pInventoryArray && nInvSlot >= 0)
			{
				if (nInvSlot < NUM_INV_SLOTS)
				{
					if (Dest.Ptr = pProfile->pInventoryArray->InventoryArray[nInvSlot])
					{
						return true;
					}
				}
				else
				{
					if (CHARINFO* pCharInfo = GetCharInfo())
					{
						if (nInvSlot >= 262 && nInvSlot < 342)
						{
							int nPack = (nInvSlot - 262) / 10;
							int nSlot = (nInvSlot - 262) % 10;

							if (CONTENTS* pPack = pProfile->pInventoryArray->Inventory.Pack[nPack])
							{
								if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && nSlot < GetItemFromContents(pPack)->Slots)
								{
									if (pPack->Contents.ContainedItems.pItems)
									{
										if (Dest.Ptr = pPack->Contents.ContainedItems.pItems->Item[nSlot])
										{
											return true;
										}
									}
								}
							}
						}
						else if (nInvSlot >= 2032 && nInvSlot < 2272)
						{
							unsigned long nPack = (nInvSlot - 2032) / 10;
							unsigned long nSlot = (nInvSlot - 2) % 10;
							CONTENTS* pPack = nullptr;

							if (pCharInfo && pCharInfo->pBankArray)
								pPack = pCharInfo->pBankArray->Bank[nPack];

							if (pPack)
							{
								if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && nSlot < GetItemFromContents(pPack)->Slots)
								{
									if (pPack->Contents.ContainedItems.pItems)
									{
										if (Dest.Ptr = pPack->Contents.ContainedItems.pItems->Item[nSlot])
										{
											return true;
										}
									}
								}
							}
						}
						else if (nInvSlot >= 2532 && nInvSlot < 2552)
						{
							unsigned long nPack = 23 + ((nInvSlot - 2532) / 10);
							unsigned long nSlot = (nInvSlot - 2) % 10;
							CONTENTS* pPack = nullptr;

							if (pCharInfo && pCharInfo->pBankArray)
								pPack = pCharInfo->pBankArray->Bank[nPack];

							if (pPack)
							{
								if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && nSlot < GetItemFromContents(pPack)->Slots)
								{
									if (pPack->Contents.ContainedItems.pItems)
									{
										if (Dest.Ptr = pPack->Contents.ContainedItems.pItems->Item[nSlot])
										{
											return true;
										}
									}
								}
							}
						}
						else if (nInvSlot >= 2000 && nInvSlot < 2024)
						{
							if (pCharInfo && pCharInfo->pBankArray)
							{
								if (Dest.Ptr = pCharInfo->pBankArray->Bank[nInvSlot - 2000])
								{
									return true;
								}
							}
						}
						else if (nInvSlot == 2500 || nInvSlot == 2501)
						{
							if (pCharInfo && pCharInfo->pBankArray)
							{
								if (Dest.Ptr = pCharInfo->pBankArray->Bank[nInvSlot - 2500 + 22])
								{
									if (Dest.Ptr)
									{
										return true;
									}
								}
							}
						}
						else if (nInvSlot > 2999 && nInvSlot < 3016)
						{
							CInvSlotWnd* pInvSlotWnd = nullptr;

							if (pGiveWnd && pGiveWnd->IsVisible())
							{
								int slot = std::min(nInvSlot - 3000, MAX_GIVE_SLOTS);
								if (slot >= MAX_TRADE_SLOTS)
									slot = 0;

								pInvSlotWnd = pGiveWnd->pInvSlotWnd[slot];
							}
							else if (pTradeWnd && pTradeWnd->IsVisible())
							{
								int slot = std::min(nInvSlot - 3000, MAX_TRADE_SLOTS);
								if (slot >= MAX_TRADE_SLOTS)
									slot = 0;

								pInvSlotWnd = pTradeWnd->pInvSlotWnd[slot];
							}

							if (pInvSlotWnd)
							{
								if (CInvSlot* pInvSlot = pInvSlotWnd->pInvSlot)
								{
									CONTENTS* pC = nullptr;
									pInvSlot->GetItemBase(&pC);
									if (pC)
									{
										Dest.Ptr = pC;
										return true;
									}
								}
							}
						}
						else if (nInvSlot > 3999 && nInvSlot < 4011) // enviro slots
						{
							if (pContainerMgr)
							{
								uint32_t index = nInvSlot - 4000;
								if (CONTENTS* pContents = pContainerMgr->pWorldContainer.get())
								{
									if (index < pContents->Contents.ContainedItems.Size
										&& pContents->Contents.ContainedItems.pItems)
									{
										Dest.Ptr = pContents->Contents.ContainedItems.pItems->Item[index];
										return true;
									}
								}
							}
						}
						else if (nInvSlot == 4100) // enviro
						{
							if ( pContainerMgr)
							{
								if (pContainerMgr->pWorldContainer)
								{
									Dest.Ptr = pContainerMgr->pWorldContainer.get();
									return true;
								}
							}
						}
					}
				}
			}
		}
		return false;

	case Pack:
		Dest.DWord = 0;
		Dest.Type = pInvSlotType;
		if (nInvSlot >= 262 && nInvSlot < 342)
		{
			Dest.DWord = ((nInvSlot - 262) / 10) + BAG_SLOT_START;
			return true;
		}

		if (nInvSlot >= 2032 && nInvSlot < 2272)
		{
			Dest.DWord = ((nInvSlot - 2032) / 10) + 2000;
			return true;
		}

		if (nInvSlot >= 2532 && nInvSlot < 2552)
		{
			Dest.DWord = ((nInvSlot - 2532) / 10) + 2500;
			return true;
		}
		return false;

	case Slot:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (nInvSlot >= 262 && nInvSlot < 342)
		{
			Dest.DWord = (nInvSlot - 262) % 10;
			return true;
		}

		if (nInvSlot >= 2032 && nInvSlot < 2272)
		{
			Dest.DWord = (nInvSlot - 2032) % 10;
			return true;
		}

		if (nInvSlot >= 2532 && nInvSlot < 2552)
		{
			Dest.DWord = (nInvSlot - 2532) % 10;
			return true;
		}
		return false;

	case Name:
		Dest.Type = pStringType;
		if (nInvSlot >= 0 && nInvSlot < NUM_INV_SLOTS)
		{
			strcpy_s(DataTypeTemp, szItemSlot[nInvSlot]);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= BAG_SLOT_START && nInvSlot < NUM_INV_SLOTS)
		{
			sprintf_s(DataTypeTemp, "pack%d", nInvSlot - 21);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 2000 && nInvSlot < 2024)
		{
			sprintf_s(DataTypeTemp, "bank%d", nInvSlot - 1999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 2500 && nInvSlot < 2502)
		{
			sprintf_s(DataTypeTemp, "sharedbank%d", nInvSlot - 2499);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 5000 && nInvSlot < 5032)
		{
			sprintf_s(DataTypeTemp, "loot%d", nInvSlot - 4999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 3000 && nInvSlot < 3009)
		{
			sprintf_s(DataTypeTemp, "trade%d", nInvSlot - 2999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 4000 && nInvSlot < 4009)
		{
			sprintf_s(DataTypeTemp, "enviro%d", nInvSlot - 3999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot == 4100) // its the worldcontainer
		{
			if (pContainerMgr)
			{
				if (ITEMINFO* pItemInfo = pContainerMgr->pWorldContainer->GetItemDefinition())
				{
					strcpy_s(DataTypeTemp, pItemInfo->Name);
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}

			return false;
		}

		if (nInvSlot >= 6000 && nInvSlot < 6080)
		{
			sprintf_s(DataTypeTemp, "merchant%d", nInvSlot - 5999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 7000 && nInvSlot < 7089)
		{
			sprintf_s(DataTypeTemp, "bazaar%d", nInvSlot - 6999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 8000 && nInvSlot < 8031)
		{
			sprintf_s(DataTypeTemp, "inspect%d", nInvSlot - 7999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2TimerType

bool MQ2TimerType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar & Dest)
{
	MQTimer* pTimer = static_cast<MQTimer*>(VarPtr.Ptr);
	if (!pTimer)
		return false;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2TimerType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<TimerMethods>(pMethod->ID))
		{
		case Expire:
			pTimer->Current = 0;
			return true;

		case Reset:
			pTimer->Current = pTimer->Original;
			return true;

		case Set:
			FromString(VarPtr, Index);
			return true;

		default: break;
		}
		return false;
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2TimerType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TimerMembers>(pMember->ID))
	{
	case Value:
		Dest.DWord = pTimer->Current;
		Dest.Type = pIntType;
		return true;

	case OriginalValue:
		Dest.DWord = pTimer->Original;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2SkillType

bool MQ2SkillType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar & Dest)
{
	if (!VarPtr.Ptr)
		return false;
	SKILL* pSkill = *(SKILL**)VarPtr.Ptr;
	if (!pSkill)
		return false;

	MQTypeMember* pMember = MQ2SkillType::FindMember(Member);
	if (!pMember)
		return false;

	if (PcProfile* pProfile = GetPcProfile())
	{
		int nIndex = pProfile->Class;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// class by number
				nIndex = GetIntFromString(Index, nIndex);
			}
			else
			{
				// class by name or shortname
				for (int index = 1; index < 17; index++)
				{
					if (ci_equals(Index, GetClassDesc(index))
						|| ci_equals(Index, pEverQuest->GetClassThreeLetterCode(index)))
					{
						nIndex = index;
						break;
					}
				}
			}
		}

		switch (static_cast<SkillMembers>(pMember->ID))
		{
		case Name:
			Dest.Type = pStringType;
			if (const char* ptr = pStringTable->getString(pSkill->nName))
			{
				strcpy_s(DataTypeTemp, ptr);
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
			return false;

		case ID:
			Dest.DWord = GetSkillIDFromName(pStringTable->getString(pSkill->nName));
			Dest.Type = pIntType;
			return true;

		case ReuseTime:
			Dest.DWord = pSkill->ReuseTimer;
			Dest.Type = pIntType;
			return true;

		case MinLevel:
			Dest.DWord = pSkill->MinLevel[nIndex];
			Dest.Type = pIntType;
			return true;

		case SkillCap:
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (pCharData)
			{
				int i = GetSkillIDFromName(pStringTable->getString(pSkill->nName));
				Dest.DWord = pCSkillMgr->GetSkillCap(pCharData, pProfile->Level, pProfile->Class, i, true, true, true);
				return true;
			}
			return false;

		case AltTimer:
			Dest.DWord = pSkill->SkillCombatType;
			Dest.Type = pIntType;
			return true;

		case Activated:
			Dest.DWord = pSkill->Activated;
			Dest.Type = pBoolType;
			return true;

		case Auto: { // return a bool representing if a skill has /autoskill on or off.
			Dest.DWord = false;
			Dest.Type = pBoolType;
			int id = GetSkillIDFromName(pStringTable->getString(pSkill->nName));
			if (gAutoSkill.Skill[0] == id || gAutoSkill.Skill[1] == id)
			{
				Dest.DWord = true;
			}
			return true;
		}

		default: break;
		}
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2AltAbilityType

bool MQ2AltAbilityType::ToString(MQVarPtr VarPtr, char* Destination)
{
	ALTABILITY* pAbility = static_cast<ALTABILITY*>(VarPtr.Ptr);
	if (!pAbility)
		return false;

	_itoa_s(pAbility->ID, Destination, MAX_STRING, 10);
	return true;
}

bool MQ2AltAbilityType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar & Dest)
{
	ALTABILITY* pAbility = static_cast<ALTABILITY*>(VarPtr.Ptr);
	if (!pAbility)
		return false;

	MQTypeMember* pMember = MQ2AltAbilityType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AltAbilityMembers>(pMember->ID))
	{
	case Name:
		Dest.Type = pStringType;
		if (const char* ptr = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ShortName:
		// What is this even for? Need to check -eqmule
		Dest.Type = pStringType;
		if (const char* ptr = pCDBStr->GetString(pAbility->nName, eAltAbilityButton1))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Description:
		Dest.Type = pStringType;
		if (const char* ptr = pCDBStr->GetString(pAbility->nName, eAltAbilityDescription))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ID:
		Dest.DWord = pAbility->ID;
		Dest.Type = pIntType;
		return true;

	case ReuseTime:
		Dest.DWord = pAbility->ReuseTimer;
		Dest.Type = pIntType;
		return true;

	case MyReuseTime:
		Dest.DWord = pAltAdvManager->GetCalculatedTimer(pPCData, pAbility);
		Dest.Type = pIntType;
		return true;

	case MinLevel:
		Dest.DWord = pAbility->MinLevel;
		Dest.Type = pIntType;
		return true;

	case Cost:
		Dest.DWord = pAbility->Cost;
		Dest.Type = pIntType;
		return true;

	case Spell:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(pAbility->SpellID))
		{
			return true;
		}
		return false;

	case RequiresAbility:
		Dest.Type = pAltAbilityType;
		if (pAbility->RequiredGroupLevels && *pAbility->RequiredGroupLevels > 0)
		{
			for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
			{
				if (ALTABILITY* tmppAbility = GetAAByIdWrapper(nAbility))
				{
					if (tmppAbility->ID == *pAbility->RequiredGroupLevels)
					{
						Dest.Ptr = tmppAbility;
						return true;
					}
				}
			}
		}

		if (pAbility)
			DebugSpew("ability %d not found\n", pAbility->RequiredGroupLevels);
		return false;

	case RequiresAbilityPoints:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pAbility->RequiresAbilityPoints)
		{
			Dest.DWord = *pAbility->RequiresAbilityPoints;
			return true;
		}
		return false;

	case MaxRank:
		Dest.DWord = pAbility->MaxRank;
		Dest.Type = pIntType;
		return true;

	case Rank: // th current rank...
	case AARankRequired: // kept this for legacy reasons...
		Dest.DWord = pAbility->CurrentRank;
		Dest.Type = pIntType;
		return true;

	case Type:
		Dest.DWord = pAbility->Type;
		Dest.Type = pIntType;
		return true;

	case Flags:
		Dest.DWord = pAbility->bShowInAbilityWindow;
		Dest.Type = pIntType;
		return true;

	case Expansion:
		Dest.DWord = pAbility->Expansion;
		Dest.Type = pIntType;
		return true;

	case Passive:
		Dest.DWord = 1;
		Dest.Type = pBoolType;
		if (pAbility->SpellID != -1)
			Dest.DWord = 0;
		return true;

	case PointsSpent:
		Dest.DWord = pAbility->TotalPoints;
		Dest.Type = pIntType;
		return true;

	case xIndex:
		Dest.DWord = pAbility->Index;
		Dest.Type = pIntType;
		return true;

	case CanTrain: {
		if (ALTABILITY* pNextAbility = GetAAByIdWrapper(pAbility->NextGroupAbilityId))
			pAbility = pNextAbility;

		Dest.DWord = pAltAdvManager->CanTrainAbility((PcZoneClient*)pPCData, pAbility, 0, 0, 0);
		Dest.Type = pBoolType;
		return true;
	}

	case NextIndex:
		Dest.DWord = pAbility->NextGroupAbilityId;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2GroupType

bool MQ2GroupType::ToString(MQVarPtr VarPtr, char* Destination)
{
	CHARINFO* pChar = GetCharInfo();
	if (!pChar || !pChar->pGroupInfo) return false;

	int nMembers = 0;
	for (int index = 1; index < 6; index++)
	{
		if (pChar->pGroupInfo->pMember[index])
			nMembers++;
	}

	_itoa_s(nMembers, Destination, MAX_STRING, 10);
	return true;
}

bool MQ2GroupType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar & Dest)
{
	MQTypeMember* pMember = MQ2GroupType::FindMember(Member);
	CHARINFO* pChar = GetCharInfo();

	if (!pMember || !pChar || !pChar->pGroupInfo)
		return false;

	switch (static_cast<GroupMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (uint32_t)pChar->pGroupInfo;
		Dest.Type = pIntType;
		return true;

	case xMember:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;
		if (!Index[0])
			return false;
		if (IsNumber(Index))
		{
			// by number
			Dest.DWord = GetIntFromString(Index, 0);
			return true;
		}
		else
		{
			// by name
			if (pChar->pSpawn)
			{
				Dest.DWord = 0;
				if (ci_equals(pChar->pSpawn->Name, Index))
				{
					Dest.DWord = 0;
					return true;
				}

				for (int i = 1; i < 6; i++)
				{
					if (pChar->pGroupInfo->pMember[i])
					{
						Dest.DWord++;
						char Name[MAX_STRING] = { 0 };
						strcpy_s(Name, pChar->pGroupInfo->pMember[i]->Name.c_str());

						CleanupName(Name, sizeof(Name), false, false); // we do this to fix the mercenaryname bug

						if (Index[0] != 0 && ci_equals(Name, Index))
						{
							return true;
						}
					}
				}
			}
			return false;
		}
		return false;

	case Members:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
				Dest.DWord++;
		}
		return true;

	case Leader: {
		Dest.Type = pGroupMemberType;
		if (!pChar->pGroupInfo->pLeader || !pChar->pSpawn)
			return false;
		Dest.DWord = 0;

		if (ci_equals(pChar->pSpawn->Name, pChar->pGroupInfo->pLeader->Name))
		{
			return true;
		}

		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;

				if (ci_equals(pChar->pGroupInfo->pMember[i]->Name, pChar->pGroupInfo->pLeader->Name))
				{
					return true;
				}
			}
		}

		if (!Dest.DWord)
		{
			// group has no members
			return true;
		}
		return false;
	}

	case GroupSize:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
				Dest.DWord++;
		}

		if (Dest.DWord)
			Dest.DWord++;
		return true;

	case MainTank:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (pChar->pGroupInfo->pMember[0]->MainTank)
		{
			return true;
		}

		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->MainTank)
				{
					return true;
				}
			}
		}
		return false;

	case MainAssist:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (pChar->pGroupInfo->pMember[0]->MainAssist)
		{
			return true;
		}

		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->MainAssist)
				{
					return true;
				}
			}
		}
		return false;

	case Puller:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (pChar->pGroupInfo->pMember[0]->Puller)
		{
			return true;
		}

		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->Puller)
				{
					return true;
				}
			}
		}
		return false;

	case MarkNpc:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (pChar->pGroupInfo->pMember[0]->MarkNpc)
		{
			return true;
		}

		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->MarkNpc)
				{
					return true;
				}
			}
		}
		return false;

	case MasterLooter:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (pChar->pGroupInfo->pMember[0]->MasterLooter)
		{
			return true;
		}

		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->MasterLooter)
				{
					return true;
				}
			}
		}
		return false;

	case AnyoneMissing:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i]
				&& (pChar->pGroupInfo->pMember[i]->Offline
					|| (pChar->pGroupInfo->pMember[i]->Offline == 0
						&& pChar->pGroupInfo->pMember[i]->pSpawn == nullptr)
					|| (pChar->pGroupInfo->pMember[i]->pSpawn
						&& pChar->pGroupInfo->pMember[i]->pSpawn->Type == SPAWN_CORPSE)))
			{
				Dest.DWord = 1;
				break;
			}
		}
		return true;

	case Present:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i]
				&& pChar->pGroupInfo->pMember[i]->pSpawn
				&& pChar->pGroupInfo->pMember[i]->pSpawn->Type != SPAWN_CORPSE)
			{
				Dest.DWord++;
			}
		}
		return true;

	case MercenaryCount:
		Dest.DWord = GetGroupMercenaryCount(AllClassesMASK);
		Dest.Type = pIntType;
		return true;

	case TankMercCount:
		Dest.DWord = GetGroupMercenaryCount(WarriorMASK);
		Dest.Type = pIntType;
		return true;

	case HealerMercCount:
		Dest.DWord = GetGroupMercenaryCount(ClericMASK);
		Dest.Type = pIntType;
		return true;

	case MeleeMercCount:
		Dest.DWord = GetGroupMercenaryCount(RogueMASK);
		Dest.Type = pIntType;
		return true;

	case CasterMercCount:
		Dest.DWord = GetGroupMercenaryCount(WizardMASK);
		Dest.Type = pIntType;
		return true;

	case AvgHPs:
	{
		Dest.DWord = 100;
		Dest.Type = pIntType;

		int nummembers = 1;
		int64_t hps = 0;

		if (pChar->pSpawn && pChar->pSpawn->HPCurrent && pChar->pSpawn->HPMax)
		{
			hps = (pChar->pSpawn->HPCurrent / pChar->pSpawn->HPMax) * 100;
		}

		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i]
				&& pChar->pGroupInfo->pMember[i]->pSpawn
				&& pChar->pGroupInfo->pMember[i]->pSpawn->Type != SPAWN_CORPSE)
			{
				hps += pChar->pGroupInfo->pMember[i]->pSpawn->HPCurrent;
				nummembers++;
			}
		}

		if (hps != 0 && nummembers != 0)
		{
			Dest.Int64 = hps / nummembers;
		}
		return true;
	}

	case Injured:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (int threshold = GetIntFromString(Index, 0))
		{
			int64_t hps = 0;
			for (int i = 0; i < 6; i++)
			{
				if (pChar->pGroupInfo->pMember[i]
					&& pChar->pGroupInfo->pMember[i]->pSpawn
					&& pChar->pGroupInfo->pMember[i]->pSpawn->Type != SPAWN_CORPSE
					&& pChar->pGroupInfo->pMember[i]->Offline == 0)
				{
					if (i == 0)
					{
						if (pChar->pGroupInfo->pMember[i]->pSpawn->HPCurrent
							&& pChar->pGroupInfo->pMember[i]->pSpawn->HPMax)
						{
							float fhpc = (float)pChar->pGroupInfo->pMember[i]->pSpawn->HPCurrent;
							float fhpm = (float)pChar->pGroupInfo->pMember[i]->pSpawn->HPMax;
							hps = (int64_t)(fhpc * 100 / fhpm);
						}
					}
					else
					{
						hps = pChar->pGroupInfo->pMember[i]->pSpawn->HPCurrent;
					}

					if (hps > 0 && hps < threshold)
					{
						Dest.DWord++;
					}
				}
			}

		}
		return true;

	case XCleric:
		Dest.Ptr = nullptr;
		Dest.Type = pSpawnType;

		for (auto& member : pChar->pGroupInfo->pMember)
		{
			if (member
				&& member->Type == EQP_PC
				&& member->pSpawn
				&& member->pSpawn->GetClass() == Cleric)
			{
				Dest.Ptr = member->pSpawn;
				return true;
			}
		}
		return false;

	case MouseOver:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (pWndMgr)
		{
			if (CXWnd* pWnd = pWndMgr->LastMouseOver)
			{
				if (CXMLData* pXMLData = pWnd->GetXMLData())
				{
					CXStr Str = pXMLData->Name;
					if (ci_find_substr(pXMLData->Name, "GW_Gauge") == 0)
					{
						// ok they are actually hovering a groupmember, but which one?
						std::string_view digit{ pXMLData->Name };
						digit = digit.substr(8);

						if (digit.length() > 0)
						{
							// GW_Gauge1 -> GWGauge5
							int i = digit[0] - '0';
							if (i > 0 && i < MAX_GROUP_SIZE && pChar->pGroupInfo->pMember[i])
							{
								Dest.DWord = i;
								return true;
							}
						}
					}
					else if (ci_find_substr(pXMLData->Name, "Player_HP") == 0)
					{
						// ok they are actually hovering myself
						Dest.DWord = 0;
						return true;
					}
				}
			}
		}
		return false;
	}
	return false;
}

//----------------------------------------------------------------------------
// MQ2GroupMemberType

bool MQ2GroupMemberType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (int index = VarPtr.Int)
	{
		if (index > 5)
			return false;

		CHARINFO* pChar = GetCharInfo();
		if (!pChar->pGroupInfo) return false;

		// members 1 to 5. Count to the nth member.
		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			GROUPMEMBER* pMember = pChar->pGroupInfo->pMember[i];
			if (pMember)
			{
				index--;
				if (index == 0)
				{
					char Name[MAX_STRING] = { 0 };
					strcpy_s(Name, pMember->Name.c_str());

					strcpy_s(Destination, MAX_STRING, CleanupName(Name, MAX_STRING, false, false));
					return true;
				}
			}
		}
	}
	else
	{
		strcpy_s(Destination, MAX_STRING, GetCharInfo()->pSpawn->DisplayedName);
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2GroupMemberType

bool MQ2GroupMemberType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CHARINFO* pChar = GetCharInfo();
	if (!pChar || !pChar->pGroupInfo)
		return false;

	SPAWNINFO* pGroupMember = nullptr;
	GROUPMEMBER* pGroupMemberData = nullptr;

	char MemberName[MAX_STRING] = { 0 };
	char LeaderName[MAX_STRING] = { 0 };

	int nMember = VarPtr.Int;

	if (int index = nMember)
	{
		if (index >= MAX_GROUP_SIZE)
			return false;

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			GROUPMEMBER* pMember = pChar->pGroupInfo->pMember[i];

			if (pMember)
			{
				index--;
				if (index == 0)
				{
					strcpy_s(MemberName, pMember->Name.c_str());

					if (pMember->pSpawn)
					{
						pGroupMember = pMember->pSpawn;
					}

					pGroupMemberData = pMember;
					break;
				}
			}
		}
		if (!MemberName)
			return false;
	}
	else
	{
		if (pGroupMember = pChar->pSpawn)
		{
			strcpy_s(MemberName, pGroupMember->Name);
		}

		pGroupMemberData = pChar->pGroupInfo->pMember[0];
	}

	MQTypeMember* pMember = MQ2GroupMemberType::FindMember(Member);
	if (!pMember)
	{
		if (!pGroupMember)
			return false;

		MQVarPtr data;
		data.Ptr = pGroupMember;

		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<GroupMemberMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)pGroupMemberData;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, CleanupName(MemberName, sizeof(MemberName), FALSE, FALSE));
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Leader:
		Dest.Type = pBoolType;
		if (!pChar->pGroupInfo->pLeader)
			return false;

		strcpy_s(LeaderName, pChar->pGroupInfo->pLeader->Name.c_str());
		Dest.DWord = !_stricmp(MemberName, LeaderName);
		return true;

	case Spawn:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pGroupMember)
		{
			return true;
		}
		return false;

	case Level:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pGroupMember)
		{
			Dest.DWord = pGroupMember->Level;
			return true;
		}
		else if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->Level;
			return true;
		}
		return false;

	case MainTank:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->MainTank;
			return true;
		}
		return false;

	case MainAssist:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->MainAssist;
			return true;
		}
		return false;

	case MarkNpc:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->MarkNpc;
			return true;
		}
		return false;

	case MasterLooter:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->MasterLooter;
			return true;
		}
		return false;

	case Puller:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->Puller;
			return true;
		}
		return false;

	case Mercenary:
	case Type:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->Type;
			return true;
		}
		return false;

	case PctAggro:
		Dest.Type = pIntType;
		if (GROUPAGGRO* pAggrp = (GROUPAGGRO*)EQADDR_GROUPAGGRO)
		{
			if (nMember == 0) // Player is always nMember 0 but in the GroupMemberAggro struct its always 5..
				Dest.DWord = pAggrp->GroupMemberAggro[5];
			else
				Dest.DWord = pAggrp->GroupMemberAggro[nMember - 1];
			return true;
		}
		return false;

	case xIndex:
		Dest.DWord = nMember;
		Dest.Type = pIntType;
		return true;

	case Offline:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->Offline;
			return true;
		}
		return false;

	case Present:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->pSpawn ? 1 : 0;
			Dest.Type = pBoolType;
			return true;
		}
		return false;

	case OtherZone:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pGroupMemberData && pGroupMemberData->Offline == 0 && pGroupMemberData->pSpawn == 0)
			Dest.DWord = 1;
		return true;
	}
	return false;
}

bool MQ2RaidType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar & Dest)
{
	if (!pRaid)
		return false;

	MQTypeMember* pMember = MQ2RaidType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<RaidMembers>(pMember->ID))
	{
	case Locked:
		Dest.DWord = pRaid->Locked;
		Dest.Type = pBoolType;
		return true;

	case Invited:
		Dest.DWord = pRaid->Invited == 2;
		Dest.Type = pBoolType;
		return true;

	case xMember:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count || Count > pRaid->RaidMemberCount)
					return false;

				for (int nMember = 0; nMember < MAX_RAID_SIZE; nMember++)
				{
					if (pRaid->RaidMemberUsed[nMember])
					{
						Count--;
						if (!Count)
						{
							Dest.DWord = nMember + 1;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				for (int nMember = 0; nMember < MAX_RAID_SIZE; nMember++)
				{
					if (pRaid->RaidMemberUsed[nMember] && ci_equals(pRaid->RaidMember[nMember].Name, Index))
					{
						Dest.DWord = nMember + 1;
						return true;
					}
				}
			}
		}
		return false;

	case Members:
		Dest.DWord = pRaid->RaidMemberCount;
		Dest.Type = pIntType;
		return true;

	case Target:
		Dest.DWord = pRaid->RaidTarget + 1;
		Dest.Type = pRaidMemberType;
		return true;

	case Leader:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;
		for (int nMember = 0; nMember < MAX_RAID_SIZE; nMember++)
		{
			if (pRaid->RaidMemberUsed[nMember] && ci_equals(pRaid->RaidMember[nMember].Name, pRaid->RaidLeaderName))
			{
				Dest.DWord = nMember + 1;
				return true;
			}
		}
		return false;

	case TotalLevels:
		Dest.DWord = pRaid->TotalRaidMemberLevels;
		Dest.Type = pIntType;
		return true;

	case AverageLevel:
		Dest.Float = (float)pRaid->TotalRaidMemberLevels / (float)pRaid->RaidMemberCount;
		Dest.Type = pFloatType;
		return true;

	case LootType:
		Dest.DWord = pRaid->LootType;
		Dest.Type = pIntType;
		return true;

	case Looters:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (int index = 0; index < MAX_RAID_LOOTERS; index++)
		{
			if (pRaid->RaidLooters[index][0])
				Dest.DWord++;
		}
		return true;

	case Looter:
		Dest.Type = pStringType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count)
					return false;

				for (int nLooter = 0; nLooter < MAX_RAID_LOOTERS; nLooter++)
				{
					if (pRaid->RaidLooters[nLooter][0])
					{
						Count--;
						if (Count == 0)
						{
							strcpy_s(DataTypeTemp, pRaid->RaidLooters[nLooter]);
							Dest.Ptr = &DataTypeTemp[0];
							return true;
						}
					}
				}
			}
			// by name?
		}
		return false;

	case MainAssist:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;
		for (int i = 0; i < MAX_RAID_SIZE; i++)
		{
			if (pRaid->RaidMemberUsed[i] && pRaid->RaidMember[i].RaidMainAssist)
			{
				Dest.DWord = i + 1;
				return true;
			}
		}
		return false;

	case MasterLooter:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;
		for (int i = 0; i < 72; i++)
		{
			if (pRaid->RaidMemberUsed[i] && pRaid->RaidMember[i].MasterLooter)
			{
				Dest.DWord = i + 1;
				return true;
			}
		}
		return false;
	}
	return false;
}

bool MQ2RaidMemberType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	int nRaidMember = VarPtr.Int - 1;
	if (nRaidMember < 0 || nRaidMember >= MAX_RAID_SIZE)
		return false;

	if (!pRaid->RaidMemberUsed[nRaidMember])
		return false;

	EQRAIDMEMBER* pRaidMember = &pRaid->RaidMember[nRaidMember];
	MQTypeMember* pMember = MQ2RaidMemberType::FindMember(Member);

	if (!pMember)
	{
		SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByName(pRaidMember->Name);
		if (!pSpawn)
			return false;

		MQVarPtr data;
		data.Ptr = pSpawn;
		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<RaidMemberMembers>(pMember->ID))
	{
	case Name:
		strcpy_s(DataTypeTemp, pRaidMember->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Group:
		Dest.DWord = pRaidMember->GroupNumber + 1;
		Dest.Type = pIntType;
		return true;

	case GroupLeader:
		Dest.DWord = pRaidMember->GroupLeader;
		Dest.Type = pBoolType;
		return true;

	case RaidLeader:
		Dest.DWord = pRaidMember->RaidLeader;
		Dest.Type = pBoolType;
		return true;

	case Looter:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pRaidMember->RaidLeader)
		{
			Dest.DWord = 1;
			return true;
		}

		if (pRaid->LootType == RaidLootLeaderAndGroupLeader)
		{
			Dest.DWord = pRaidMember->GroupLeader;
			return true;
		}

		if (pRaid->LootType == RaidLootAssignments)
		{
			for (int index = 0; index < MAX_RAID_LOOTERS; index++)
			{
				if (ci_equals(pRaid->RaidLooters[index], pRaidMember->Name))
				{
					Dest.DWord = 1;
					return true;
				}
			}
		}
		return true;

	case Spawn:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = (SPAWNINFO*)GetSpawnByName(pRaidMember->Name))
		{
			return true;
		}
		return false;

	case Level:
		Dest.DWord = pRaidMember->nLevel;
		Dest.Type = pIntType;
		return true;

	case Class:
		Dest.DWord = pRaidMember->nClass;
		Dest.Type = pClassType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2EvolvingItemType

bool MQ2EvolvingItemType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CONTENTS* pItem = reinterpret_cast<CONTENTS*>(VarPtr.Ptr);
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2EvolvingItemType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<EvolvingItemMembers>(pMember->ID))
	{
	case ExpPct:
		Dest.Float = (float)pItem->EvolvingExpPct;
		Dest.Type = pFloatType;
		return true;

	case ExpOn:
		Dest.DWord = true; // its always on after 2019-02-14 test patch
		Dest.Type = pBoolType;
		return true;

	case Level:
		Dest.DWord = pItem->EvolvingCurrentLevel;
		Dest.Type = pIntType;
		return true;

	case MaxLevel:
		Dest.DWord = pItem->EvolvingMaxLevel;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2DynamicZoneType

bool MQ2DynamicZoneType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2DynamicZoneType::FindMember(Member);
	if (!pMember)
		return false;

	DynamicZoneMembers dataMember = static_cast<DynamicZoneMembers>(pMember->ID);
	if (!pDZMember && dataMember != LeaderFlagged)
		return false;

	switch (dataMember)
	{
	case Name:
		strcpy_s(DataTypeTemp, pDynamicZone->ExpeditionName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Members: {
		Dest.DWord = 0;
		Dest.Type = pIntType;
		DynamicZonePlayerInfo* pDynamicZoneMember = pDynamicZone->pFirstMember;

		while (pDynamicZoneMember)
		{
			Dest.DWord++;
			pDynamicZoneMember = pDynamicZoneMember->pNext;
		}
		return true;
	}

	case LeaderFlagged:
		Dest.DWord = pDynamicZone && pDynamicZone->pFirstMember && pDynamicZone->pFirstMember->bFlagged;
		Dest.Type = pBoolType;

	case MaxMembers:
		Dest.DWord = pDynamicZone->MaxPlayers;
		Dest.Type = pIntType;
		return true;

	case xMember:
		Dest.Type = pDZMemberType;
		if (Index[0])
		{
			DynamicZonePlayerInfo* pDynamicZoneMember = pDynamicZone->pFirstMember;
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0) - 1;
				if (Count < 0 || Count >= pDynamicZone->MaxPlayers)
					return false;

				for (int i = 0; pDynamicZoneMember != nullptr; i++)
				{
					if (i == Count)
					{
						Dest.Ptr = pDynamicZoneMember;
						return true;
					}
					pDynamicZoneMember = pDynamicZoneMember->pNext;
				}
			}
			else
			{
				while (pDynamicZoneMember)
				{
					if (ci_equals(pDynamicZoneMember->Name, Index))
					{
						Dest.Ptr = pDynamicZoneMember;
						return true;
					}
					pDynamicZoneMember = pDynamicZoneMember->pNext;
				}
			}
		}
		return false;

	case Leader: {
		Dest.Type = pDZMemberType;
		DynamicZonePlayerInfo* pDynamicZoneMember = pDynamicZone->pMemberList;

		for (int i = 0; i < pDynamicZone->MaxPlayers && pDynamicZoneMember; i++)
		{
			if (!strcmp(pDynamicZoneMember->Name, (char*)instExpeditionLeader))
			{
				Dest.Ptr = pDynamicZoneMember;
				return true;
			}
			pDynamicZoneMember = pDynamicZoneMember->pNext;
		}
		return false;
	}

	case InRaid:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pDynamicZone && pDynamicZone->LeaderName[0])
		{
			Dest.DWord = 1;
		}
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2DzMemberType

bool MQ2DZMemberType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	auto* pDynamicZoneMember = reinterpret_cast<DynamicZonePlayerInfo*>(VarPtr.Ptr);
	if (pDynamicZoneMember)
		return false;

	MQTypeMember* pMember = MQ2DZMemberType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<DZMemberTypeMembers>(pMember->ID))
	{
	case Name:
		strcpy_s(DataTypeTemp, pDynamicZoneMember->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Flagged:
		Dest.DWord = pDynamicZoneMember->bFlagged;
		Dest.Type = pBoolType;

	case Status:
		strcpy_s(DataTypeTemp, "Unknown");
		switch (pDynamicZoneMember->Status)
		{
		case 0:
			strcpy_s(DataTypeTemp, "Unknown");
			break;
		case 1:
			strcpy_s(DataTypeTemp, "Online");
			break;
		case 2:
			strcpy_s(DataTypeTemp, "Offline");
			break;
		case 3:
			strcpy_s(DataTypeTemp, "In Dynamic Zone");
			break;
		case 4:
			strcpy_s(DataTypeTemp, "Link Dead");
			break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2FellowshipType

bool MQ2FellowshipType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	FELLOWSHIPINFO* pFellowship = reinterpret_cast<FELLOWSHIPINFO*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	MQTypeMember* pMember = MQ2FellowshipType::FindMember(Member);
	if (!pMember)
		return false;

	SPAWNINFO* pMySpawn = reinterpret_cast<SPAWNINFO*>(pLocalPlayer);

	switch (static_cast<FellowshipTypeMembers>(pMember->ID))
	{
	case ID:
		Dest.DWord = pFellowship->FellowshipID;
		Dest.Type = pIntType;
		return true;

	case Leader:
		strcpy_s(DataTypeTemp, pFellowship->Leader);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case MotD:
		strcpy_s(DataTypeTemp, pFellowship->MotD);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Members:
		Dest.DWord = pFellowship->Members;
		Dest.Type = pIntType;
		return true;

	case xMember:
		Dest.Type = pFellowshipMemberType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int i = GetIntFromString(Index, 0) - 1;
				if (i < 0 || i >= pFellowship->Members)
					return false;

				Dest.Ptr = &pFellowship->FellowshipMember[i];
				return true;
			}
			else
			{
				for (int i = 0; i < pFellowship->Members; i++)
				{
					if (ci_equals(pFellowship->FellowshipMember[i].Name, Index))
					{
						Dest.Ptr = &pFellowship->FellowshipMember[i];
						return true;
					}
				}
			}
		}
		return false;

	case CampfireDuration:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (pMySpawn->CampfireTimestamp)
		{
			Dest.DWord = (pMySpawn->CampfireTimestamp - GetFastTime()) / 6;
			return true;
		}
		return false;

	case CampfireY:
		Dest.Float = pMySpawn->CampfireY;
		Dest.Type = pFloatType;
		return true;
	case CampfireX:
		Dest.Float = pMySpawn->CampfireX;
		Dest.Type = pFloatType;
		return true;

	case CampfireZ:
		Dest.Float = pMySpawn->CampfireZ;
		Dest.Type = pFloatType;
		return true;

	case CampfireZone:
		Dest.Type = pZoneType;
		if (int zoneID = (pMySpawn->CampfireZoneID & 0x7FFF))
		{
			if (zoneID < MAX_ZONES && pWorldData)
			{
				Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[zoneID];
				return true;
			}
		}
		return false;

	case Campfire:
		Dest.Int = pMySpawn->Campfire;
		Dest.Type = pBoolType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2FellowshipMemberType

bool MQ2FellowshipMemberType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	FELLOWSHIPMEMBER* pFellowshipMember = reinterpret_cast<FELLOWSHIPMEMBER*>(VarPtr.Ptr);
	if (!pFellowshipMember)
		return false;

	MQTypeMember* pMember = MQ2FellowshipMemberType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<FMTypeMembers>(pMember->ID))
	{
	case Zone:
		if (int zoneID = (pFellowshipMember->ZoneID & 0x7FFF))
		{
			if (zoneID < MAX_ZONES && pWorldData)
			{
				Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[zoneID];
				Dest.Type = pZoneType;
				return true;
			}
		}
		return false;

	case Level:
		Dest.DWord = pFellowshipMember->Level;
		Dest.Type = pIntType;
		return true;

	case Class:
		Dest.DWord = pFellowshipMember->Class;
		Dest.Type = pClassType;
		return true;

	case LastOn:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (pFellowshipMember->LastOn)
		{
			Dest.DWord = (GetFastTime() - pFellowshipMember->LastOn) / 6;
			return true;
		}
		return false;

	case Name:
		strcpy_s(DataTypeTemp, pFellowshipMember->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2FriendsType

bool MQ2FriendsType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2FriendsType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<FriendsMembers>(pMember->ID))
	{
	case xFriend:
		Dest.Type = pStringType;
		if (Index[0] && pChatService)
		{
			CChatService* pChat = pChatService;
			if (IsNumber(Index))
			{
				int i = GetIntFromString(Index, 0) - 1;
				if (i < 0 || i >= pChat->GetNumberOfFriends())
					return false;

				if (const char* ptr = pChat->GetFriendName(i))
				{
					strcpy_s(DataTypeTemp, ptr);
					Dest.Ptr = &DataTypeTemp[0];
					Dest.Type = pStringType;
					return true;
				}
			}
			else
			{
				for (int i = 0; i < pChat->GetNumberOfFriends(); i++)
				{
					if (ci_equals(pChat->GetFriendName(i), Index))
					{
						Dest.DWord = 1;
						Dest.Type = pBoolType;
						return true;
					}
				}
				return false;
			}
		}
		return false;

	default: break;
	};

	return false;
}

//----------------------------------------------------------------------------
// MQ2TargetType

bool MQ2TargetType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!VarPtr.Ptr)
		return false;

	MQTypeMember* pMember = MQ2TargetType::FindMember(Member);
	if (!pMember)
	{
		return pSpawnType->GetMember(VarPtr, Member, Index, Dest);
	}

	if (!GetCharInfo())
		return false;

	switch (static_cast<TargetMembers>(pMember->ID))
	{
	case BuffsPopulated:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (gTargetbuffs && pTarget)
			Dest.DWord = gTargetbuffs;
		return true;

	case Buff:
		Dest.Type = pSpellType;
		if (pTargetWnd->Type <= 0)
			return false;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nBuff = GetIntFromString(Index, NUM_BUFF_SLOTS + 1);
				if (nBuff > NUM_BUFF_SLOTS)
					return false;
				if (nBuff >= 1)
					nBuff--;

				int buffID = pTargetWnd->BuffSpellID[nBuff];
				if (buffID && buffID != -1)
				{
					if (Dest.Ptr = GetSpellByID(buffID))
					{
						Dest.HighPart = nBuff;
						Dest.Type = pSpellType;
						return true;
					}
				}
			}
			else
			{
				for (int i = 0; i < NUM_BUFF_SLOTS; i++)
				{
					int buffID = pTargetWnd->BuffSpellID[i];
					if (buffID && ci_starts_with(GetSpellNameByID(buffID), Index))
					{
						if (Dest.Ptr = GetSpellByID(buffID))
						{
							Dest.HighPart = i;
							Dest.Type = pSpellType;
							return true;
						}
					}
				}
			}
		}
		else
		{
			// return first buff
			for (int i = 0; i < NUM_BUFF_SLOTS; i++)
			{
				if (int buffID = pTargetWnd->BuffSpellID[i])
				{
					if (SPELL* pSpell = GetSpellByID(buffID))
					{
						strcpy_s(DataTypeTemp, pSpell->Name);
						Dest.Ptr = &DataTypeTemp[0];
						Dest.Type = pStringType;
						return true;
					}
				}
			}
		}
		return false;

	case MyBuff:
		Dest.Type = pSpellType;
		if (pTargetWnd->Type <= 0)
			return false;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nBuff = GetIntFromString(Index, NUM_BUFF_SLOTS + 1);
				if (nBuff > NUM_BUFF_SLOTS)
					return false;
				if (nBuff >= 1)
					nBuff--;

				int buffID = pTargetWnd->BuffSpellID[nBuff];
				if (buffID > 0)
				{
					if (!targetBuffSlotToCasterMap.empty() && targetBuffSlotToCasterMap.find(nBuff) != targetBuffSlotToCasterMap.end())
					{
						if (string_equals(GetCharInfo()->Name, targetBuffSlotToCasterMap[nBuff]))
						{
							if (Dest.Ptr = GetSpellByID(buffID))
							{
								Dest.HighPart = nBuff;
								Dest.Type = pSpellType;
								return true;
							}
						}
					}

				}
			}
			else
			{
				if (!targetBuffSlotToCasterMap.empty())
				{
					for (int i = 0; i < NUM_BUFF_SLOTS; i++)
					{
						if (targetBuffSlotToCasterMap.find(i) != targetBuffSlotToCasterMap.end()
							&& string_equals(GetCharInfo()->Name, targetBuffSlotToCasterMap[i]))
						{
							int buffID = pTargetWnd->BuffSpellID[i];
							if (buffID && ci_starts_with(GetSpellNameByID(buffID), Index))
							{
								if (Dest.Ptr = GetSpellByID(buffID))
								{
									Dest.HighPart = i;
									Dest.Type = pSpellType;
									return true;
								}
							}
						}
					}
				}
			}
		}
		else
		{
			// return first buff
			if (!targetBuffSlotToCasterMap.empty())
			{
				for (int i = 0; i < NUM_BUFF_SLOTS; i++)
				{
					if (targetBuffSlotToCasterMap.find(i) != targetBuffSlotToCasterMap.end()
						&& string_equals(GetCharInfo()->Name, targetBuffSlotToCasterMap[i]))
					{
						int buffID = pTargetWnd->BuffSpellID[i];
						if (buffID)
						{
							if (SPELL* pSpell = GetSpellByID(buffID))
							{
								strcpy_s(DataTypeTemp, pSpell->Name);
								Dest.Ptr = &DataTypeTemp[0];
								Dest.Type = pStringType;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case BuffCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pTargetWnd->Type <= 0)
			return false;

		for (int i = 0; i < NUM_BUFF_SLOTS; i++)
		{
			if (pTargetWnd->BuffSpellID[i])
				Dest.DWord++;
		}
		return true;

	case MyBuffCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pTargetWnd->Type <= 0)
			return false;

		if (!targetBuffSlotToCasterMap.empty())
		{
			for (int i = 0; i < NUM_BUFF_SLOTS; i++)
			{
				if (targetBuffSlotToCasterMap.find(i) != targetBuffSlotToCasterMap.end()
					&& string_equals(GetCharInfo()->Name, targetBuffSlotToCasterMap[i]))
				{
					int buffID = pTargetWnd->BuffSpellID[i];
					if (buffID)
					{
						Dest.DWord++;
					}
				}
			}
		}
		return true;

	case MyBuffDuration:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (pTargetWnd->Type <= 0)
			return false;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nBuff = GetIntFromString(Index, NUM_BUFF_SLOTS + 1);
				if (nBuff > NUM_BUFF_SLOTS)
					return false;
				if (nBuff >= 1)
					nBuff--;

				int buffID = pTargetWnd->BuffSpellID[nBuff];
				if (buffID > 0)
				{
					if (!targetBuffSlotToCasterMap.empty()
						&& targetBuffSlotToCasterMap.find(nBuff) != targetBuffSlotToCasterMap.end())
					{
						if (string_equals(GetCharInfo()->Name, targetBuffSlotToCasterMap[nBuff]))
						{
							Dest.UInt64 = pTargetWnd->BuffTimer[nBuff];
							return true;
						}
					}

				}
			}
			else
			{
				if (!targetBuffSlotToCasterMap.empty() && GetCharInfo())
				{
					for (int i = 0; i < NUM_BUFF_SLOTS; i++)
					{
						if (targetBuffSlotToCasterMap.find(i) != targetBuffSlotToCasterMap.end()
							&& !strcmp(GetCharInfo()->Name, targetBuffSlotToCasterMap[i].c_str()))
						{
							int buffID = pTargetWnd->BuffSpellID[i];
							if (buffID && ci_starts_with(GetSpellNameByID(buffID), Index))
							{
								Dest.UInt64 = pTargetWnd->BuffTimer[i];
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case BuffDuration:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (pTargetWnd->Type <= 0)
			return false;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nBuff = GetIntFromString(Index, NUM_BUFF_SLOTS + 1);
				if (nBuff > NUM_BUFF_SLOTS)
					return false;
				if (nBuff >= 1)
					nBuff--;

				int buffID = pTargetWnd->BuffSpellID[nBuff];
				if (buffID > 0)
				{
					Dest.UInt64 = pTargetWnd->BuffTimer[nBuff];
					return true;
				}
			}
			else
			{
				int duration = 0;
				for (int i = 0; i < NUM_BUFF_SLOTS; i++)
				{
					int buffID = pTargetWnd->BuffSpellID[i];

					// I strncmp them to take ranked buffs into account
					// so if the user specifies ${Target.BuffDuration[Pyromancy]} for example
					// its still gonna work if it finds Pyromancy XV
					if (buffID > 0 && ci_starts_with(GetSpellNameByID(buffID), Index))
					{
						if (pTargetWnd->BuffTimer[i] > duration)
						{
							duration = pTargetWnd->BuffTimer[i];
							// we always want to return the buff with the longest duration
							// cause thats the one that landed last on the mob
							// otherwize we could just break; out of here at this point
							// but anyway thats the reason we keep rolling through all them... -eqmule
						}
					}

					if (duration > 0)
					{
						Dest.UInt64 = duration;
						return true;
					}
				}
			}
		}
		return false;

	case PctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Player].AggroPct;
			return true;
		}
		return false;

	case SecondaryPctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Secondary].AggroPct;
			return true;
		}
		return false;

	case SecondaryAggroPlayer:
		Dest.Type = pSpawnType;

		if (pAggroInfo && pAggroInfo->AggroSecondaryID)
		{
			Dest.Ptr = GetSpawnByID(pAggroInfo->AggroSecondaryID);
			return true;
		}
		return false;

	case AggroHolder: {
		Dest.Type = pSpawnType;
		// who the Target has the MOST aggro on
		char* pTargetAggroHolder = EQADDR_TARGETAGGROHOLDER;
		if (pTargetAggroHolder[0] != '\0')
		{
			SPAWNINFO* pAggroHolder = (SPAWNINFO*)GetSpawnByName(pTargetAggroHolder);
			if (pAggroHolder)
			{
				Dest.Ptr = pAggroHolder;
				return true;
			}
			else
			{
				// ok no spawn was found for the name given, this can only mean one thing... its a pet or a mercenary
				MQSpawnSearch SearchSpawn;
				ClearSearchSpawn(&SearchSpawn);
				SearchSpawn.FRadius = 999999.0f;
				strcpy_s(SearchSpawn.szName, pTargetAggroHolder);
				pAggroHolder = SearchThroughSpawns(&SearchSpawn, (SPAWNINFO*)pLocalPlayer);
				if (pAggroHolder)
				{
					Dest.Ptr = pAggroHolder;
					return true;
				}
			}
		}
		else
		{
			// it could be me...
			// lets check
			if (pTarget && EQADDR_GROUPAGGRO)
			{
				if (*(DWORD*)(EQADDR_GROUPAGGRO + 0x78) >= 100)
				{
					if (Dest.Ptr = GetSpawnByID(((SPAWNINFO*)pLocalPlayer)->TargetOfTarget))
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	case Slowed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(11, 0)) != -1)
		{
			return true;
		}
		return false;

	case Rooted:
		Dest.Int = 0;

		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(99, 0)) != -1) // Root
		{
			return true;
		}
		return false;

	case Mezzed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(31, 0)) != -1) // Entrall
		{
			return true;
		}
		return false;

	case Crippled:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySubCat("Disempowering")) != -1)
		{
			return true;
		}
		return false;

	case Maloed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySubCat("Resist Debuffs", (1 << Shaman) + (1 << Mage))) != -1)
		{
			return true;
		}
		return false;

	case Tashed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySubCat("Resist Debuffs", 1 << Enchanter)) != -1)
		{
			return true;
		}
		return false;

	case Snared:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(3, 0)) != -1) // Movement Rate
		{
			return true;
		}
		return false;

	case Hasted:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(11, 1)) != -1)
		{
			return true;
		}
		return false;

	case Beneficial:
	{
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if (pTargetWnd->Type <= 0)
			return false;

		for (int i = 0; i < NUM_BUFF_SLOTS; i++)
		{
			if (pTargetWnd->BuffSpellID[i] == -1 || pTargetWnd->BuffSpellID[i] == 0)
				continue;

			if (SPELL * pSpell = GetSpellByID(pTargetWnd->BuffSpellID[i]))
			{
				if (pSpell->SpellType != 0)
				{
					//targetwindow has a leak in it player buffs shows up in it
					//so we need to make sure its not a "leaked buff"
					if (CXStr* str = pTargetWnd->GetBuffCaster(pSpell->ID))
					{
						if (SPAWNINFO* pPlayer = (SPAWNINFO*)GetSpawnByName(str->c_str()))
						{
							if (pPlayer->Type == SPAWN_PLAYER)
							{
								continue;
							}
						}
					}
					Dest.Int = i;
					return true;
				}
			}
		}
		return false;
	}

	case DSed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(59, 1)) != -1) // Damage Shield
		{
			return true;
		}
		return false;

	case RevDSed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(121, 1)) != -1) // Reverse Damage Shield
		{
			return true;
		}
		return false;

	case Charmed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(22, 0)) != -1) // Charm
		{
			return true;
		}
		return false;

	case Aego:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Cleric)) != -1) // Aegolism Line
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if ((GetSpellSubcategory(pSpell) == 1) || (GetSpellSubcategory(pSpell) == 112))
					{
						if (((EQ_Spell*)pSpell)->SpellAffectBase(1))
						{
							return true;
						}
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Cleric, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Skin:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Druid)) != -1) //
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 46)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Druid, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Focus:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Shaman)) != -1)//
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 87)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Shaman, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Regen:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(0, 1)) != -1) // HP Regen
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if ((((EQ_Spell*)pSpell)->SpellAffectBase(0) > 0) && (!IsSpellUsableForClass(pSpell, 1 << Beastlord)))
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffBySPA(0, 1, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Diseased:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(35, 0)) != -1) // Disease Counter
		{
			return true;
		}
		return false;

	case Poisoned:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(36, 0)) != -1) // Poison Counter
		{
			return true;
		}
		return false;

	case Cursed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(116, 0)) != -1) // Curse Counter
		{
			return true;
		}
		return false;

	case Corrupted:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(369, 0)) != -1) // Corruption Counter
		{
			return true;
		}
		return false;

	case Symbol:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Cleric)) != -1) //
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 112)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Cleric, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Clarity:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(15, 1)) != -1) // Mana Regen
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if ((((EQ_Spell*)pSpell)->SpellAffectBase(15) > 0) && (IsSpellUsableForClass(pSpell, 1 << Enchanter)))
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffBySPA(15, 1, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Pred:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(95, 1 << Ranger)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 7)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(95, 1 << Ranger, ++slotnum)) == -1)
				{
					break;
				}
			}
		}

		return false;
	case Strength:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Ranger)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 47)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Ranger, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Brells:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Paladin)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 47)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Paladin, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case SV:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(79, 1 << Beastlord)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 59)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(79, 1 << Beastlord, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case SE:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(79, 1 << Beastlord)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 44)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(79, 1 << Beastlord, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case HybridHP:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Ranger)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 46)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Ranger, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Growth:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Druid)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 141)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Druid, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Shining:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(125, 1 << Cleric)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 62)
					{
						if (((EQ_Spell*)pSpell)->SpellAffectBase(162))
						{
							return true;
						}
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(125, 1 << Cleric, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Feared:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(23, 0)) != -1) // Feared
		{
			return true;
		}
		return false;

	case Silenced:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(96, 0)) != -1) // Silenced
		{
			return true;
		}
		return false;

	case Invulnerable:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(40, 0)) != -1) // Invulnerable
		{
			return true;
		}
		return false;

	case Dotted:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(0, 0)) != -1) // HP Mod
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (((EQ_Spell*)pSpell)->IsDetrimentalSpell() && ((EQ_Spell*)pSpell)->IsDoTSpell())
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffBySPA(0, 0, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case MaxMeleeTo: {
		Dest.Float = get_melee_range(pCharSpawn, pTarget);
		Dest.Type = pFloatType;
		return true;
	}

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2TaskObjectiveType

bool MQ2TaskObjectiveType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	int Elementindex = VarPtr.HighPart;
	if (Elementindex == -1)
		return false;

	CTaskManager* tm = ppTaskManager;
	if (!tm)
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
		ts = tm->GetTaskStatus(pPCData, index, cTaskSystemTypeSoloQuest);
		entry = &tm->QuestEntries[index];
		break;

	case cTaskSystemTypeSharedQuest:
		ts = tm->GetTaskStatus(pPCData, 0, cTaskSystemTypeSharedQuest);
		entry = &tm->SharedTaskEntries[0];
		break;
	};

	if (!entry)
		return false;

	switch (static_cast<TaskObjectiveTypeMembers>(pMember->ID))
	{
		case Instruction:
			tm->GetElementDescription(&entry->Elements[Elementindex], DataTypeTemp);
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

	CTaskManager* tm = ppTaskManager;
	if (!tm)
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
		entry = &tm->QuestEntries[index];
		break;
	case cTaskSystemTypeSharedQuest:
		entry = &tm->SharedTaskEntries[0];
		break;
	};

	char szOut[MAX_STRING] = { 0 };
	if (entry)
	{
		tm->GetElementDescription(&entry->Elements[Elementindex], szOut);
	}

	if (szOut[0] != 0)
	{
		strcpy_s(Destination, MAX_STRING, szOut);
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2TaskMemberType

bool MQ2TaskMemberType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	TASKMEMBER* pTaskMemberData = static_cast<TASKMEMBER*>(VarPtr.Ptr);
	if (!pTaskMemberData)
		return false;

	MQTypeMember* pMember = MQ2TaskMemberType::FindMember(Member);
	if (!pMember)
	{
		return false;
	}

	DataTypeTemp[0] = 0;

	switch (static_cast<TaskMemberTypeMembers>(pMember->ID))
	{
	case Name:
		strcpy_s(DataTypeTemp, pTaskMemberData->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Leader:
		Dest.Type = pBoolType;
		if (pTaskMemberData->IsLeader)
			return true;

		return false;

	case xIndex: {
		Dest.DWord = 0;
		Dest.Type = pIntType;
		TASKMEMBER* pTaskmember = pTaskMember;
		for (int i = 1; pTaskmember; pTaskmember = pTaskmember->pNext, i++)
		{
			if (ci_equals(pTaskmember->Name, pTaskMemberData->Name))
			{
				Dest.DWord = i;
				return true;
			}
		}
		return false;
	}

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2TaskType

bool MQ2TaskType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CTaskManager* tm = ppTaskManager;
	if (!tm)
		return false;
	if (!pTaskWnd)
		return false;

	int index = VarPtr.HighPart;
	if (index == -1)
		return false;

	int type = VarPtr.LowPart;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2TaskType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<TaskMethods>(pMethod->ID))
		{
		case Select: {
			Dest.DWord = 0;
			Dest.Type = pBoolType;

			char szTask[MAX_STRING] = { 0 };

			switch (type)
			{
			case cTaskSystemTypeSoloQuest:
				if (CTaskEntry* entry = &tm->QuestEntries[index])
				{
					strcpy_s(szTask, entry->TaskTitle);
				}
				break;
			case cTaskSystemTypeSharedQuest:
				if (CTaskEntry* entry = &tm->SharedTaskEntries[0])
				{
					strcpy_s(szTask, entry->TaskTitle);
				}
				break;
			};

			if (szTask[0])
			{
				char szOut[MAX_STRING] = { 0 };

				if (CListWnd* clist = (CListWnd*)pTaskWnd->GetChildItem("TASK_TaskList"))
				{
					CXStr str;
					for (int i = 0; i < clist->ItemsArray.Count; i++)
					{
						CXStr str = clist->GetItemText(i, 2);

						if (ci_equals(szTask, str))
						{
							if (SendListSelect2(clist, i))
							{
								Dest.DWord = 1;
							}
						}
					}
				}
				return true;
			}
		}

		default: break;
		}

		return false;
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2TaskType::FindMember(Member);
	if (!pMember)
		return false;

	TASKMEMBER* pTaskmember = (TASKMEMBER*)pTaskMember;
	switch (static_cast<TaskTypeMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)pTaskmember;
		Dest.Type = pIntType;
		return true;

	case Type: {
		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			strcpy_s(DataTypeTemp, "Quest");
			break;
		case cTaskSystemTypeSharedQuest:
			strcpy_s(DataTypeTemp, "Shared");
			break;
		default:
			strcpy_s(DataTypeTemp, "Unknown");
			break;
		}

		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case xIndex:
		Dest.Int = VarPtr.Int + 1;
		Dest.Type = pIntType;
		return true;

	case Leader:
		strcpy_s(DataTypeTemp, "NULL");

		for (int i = 1; pTaskmember && i <= MAX_GROUP_SIZE; pTaskmember = pTaskmember->pNext, i++)
		{
			if (pTaskmember->IsLeader)
			{
				strcpy_s(DataTypeTemp, pTaskmember->Name);
				break;
			}
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Title:
		strcpy_s(DataTypeTemp, "NULL");

		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			if (CTaskEntry* entry = &tm->QuestEntries[index])
			{
				strcpy_s(DataTypeTemp, entry->TaskTitle);
			}
			break;

		case cTaskSystemTypeSharedQuest:
			if (CTaskEntry* entry = &tm->SharedTaskEntries[0])
			{
				strcpy_s(DataTypeTemp, entry->TaskTitle);
			}
			break;

		default:
			break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Timer: {
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;

		PCTaskStatus* ts = nullptr;
		CTaskEntry* entry = nullptr;

		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			ts = tm->GetTaskStatus(static_cast<PcClient*>(*ppPCData), index, cTaskSystemTypeSoloQuest);
			entry = &tm->QuestEntries[index];
			break;

		case cTaskSystemTypeSharedQuest:
			ts = tm->GetTaskStatus(static_cast<PcClient*>(*ppPCData), 0, cTaskSystemTypeSharedQuest);
			entry = &tm->SharedTaskEntries[0];
			break;

		default:
			break;
		}

		if (ts && entry)
		{
			const int ft = static_cast<int>(GetFastTime());
			int timer = 0;
			if (ts->MovingStartTime + entry->DurationSeconds > ft)
			{
				timer = (ts->MovingStartTime + entry->DurationSeconds) - ft;
			}

			Dest.UInt64 = static_cast<uint64_t>(timer) * 1000;
			return true;
		}

		return false;
	}

	case xMember:
		Dest.Type = pTaskMemberType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int pos = GetIntFromString(Index, 0);
			for (int i = 1; pTaskmember && i <= MAX_GROUP_SIZE; pTaskmember = pTaskmember->pNext, i++)
			{
				if (i == pos)
				{
					Dest.Ptr = pTaskmember;
					return true;
				}
			}
		}
		else
		{
			for (; pTaskmember; pTaskmember = pTaskmember->pNext)
			{
				if (!_stricmp(pTaskmember->Name, Index))
				{
					Dest.Ptr = pTaskmember;
					return true;
				}
			}
		}
		return false;

	case Members:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (; pTaskmember && Dest.DWord < MAX_GROUP_SIZE; pTaskmember = pTaskmember->pNext, Dest.DWord++)
		{
		}
		return true;

	case ID: {
		Dest.Int = 0;
		Dest.Type = pIntType;

		CTaskEntry* entry = nullptr;
		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			entry = &tm->QuestEntries[index];
			break;

		case cTaskSystemTypeSharedQuest:
			entry = &tm->SharedTaskEntries[0];
			break;

		default:
			break;
		}

		if (entry)
		{
			Dest.Int = entry->TaskID;
		}
		return true;
	}

	case Objective: {
		Dest.Int = 0;
		Dest.Type = pTaskObjectiveType;

		PCTaskStatus* ts = nullptr;
		CTaskEntry* entry = nullptr;

		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			ts = tm->GetTaskStatus(pPCData, index, cTaskSystemTypeSoloQuest);
			entry = &tm->QuestEntries[index];
			break;

		case cTaskSystemTypeSharedQuest:
			ts = tm->GetTaskStatus(pPCData, 0, cTaskSystemTypeSharedQuest);
			entry = &tm->SharedTaskEntries[0];
			break;

		default: break;
		}

		if (ts && entry)
		{
			int stepIndex = -1;

			if (IsNumber(Index))
			{
				stepIndex = std::clamp(GetIntFromString(Index, stepIndex) - 1, 0, MAX_TASK_ELEMENTS - 1);
			}
			else
			{
				char szOut[MAX_STRING] = { 0 };

				for (int i = 0; i < MAX_TASK_ELEMENTS; i++)
				{
					tm->GetElementDescription(&entry->Elements[i], szOut);

					if (ci_find_substr(szOut, Index))
					{
						stepIndex = i;
						break;
					}
				}
			}

			// FIXME: Search Dword = (int)MAKELPARAM and fix through this whole commit.
			Dest.DWord = (int)MAKELPARAM(type, index);
			Dest.HighPart = stepIndex;
			return true;
		}

		return false;
	}

	case Step: { // gets the first step that's not Done in the task objective.
		Dest.Int = 0;
		Dest.Type = pTaskObjectiveType;

		PCTaskStatus* ts = nullptr;
		CTaskEntry* entry = nullptr;

		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			ts = tm->GetTaskStatus(pPCData, index, cTaskSystemTypeSoloQuest);
			entry = &tm->QuestEntries[index];
			break;
		case cTaskSystemTypeSharedQuest:
			ts = tm->GetTaskStatus(pPCData, 0, cTaskSystemTypeSharedQuest);
			entry = &tm->SharedTaskEntries[0];
			break;
		}

		if (ts && entry)
		{
			int reqCount = 0;
			int curCount = 0;

			for (int i = 0; i < MAX_TASK_ELEMENTS; i++)
			{
				reqCount = entry->Elements[i].RequiredCount;
				curCount = ts->CurrentCounts[i];

				if (curCount < reqCount && !entry->Elements[i].bOptional)
				{
					Dest.DWord = (int)MAKELPARAM(type, index);
					Dest.HighPart = i;
					return true;
				}
			}
		}
		return false;
	}

	case WindowIndex: {
		char szTask[MAX_STRING] = { 0 };
		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			if (CTaskEntry* entry = &tm->QuestEntries[index])
			{
				strcpy_s(szTask, entry->TaskTitle);
			}
			break;

		case cTaskSystemTypeSharedQuest:
			if (CTaskEntry* entry = &tm->SharedTaskEntries[0])
			{
				strcpy_s(szTask, entry->TaskTitle);
			}
			break;
		};

		if (CListWnd* clist = (CListWnd*)pTaskWnd->GetChildItem("TASK_TaskList"))
		{
			for (int i = 0; i < clist->ItemsArray.Count; i++)
			{
				CXStr str = clist->GetItemText(i, 2);

				if (ci_equals(szTask, str))
				{
					Dest.DWord = i + 1;
					Dest.Type = pIntType;
					return true;
				}
			}
		}
		return false;
	}

	default: break;
	}

	return false;
}

bool MQ2TaskType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, "NULL");

	int index = HIWORD(VarPtr.DWord);
	int type = LOWORD(VarPtr.DWord);

	if (CTaskManager* tm = ppTaskManager)
	{
		CTaskEntry* entry = nullptr;

		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			entry = &tm->QuestEntries[index];
			break;

		case cTaskSystemTypeSharedQuest:
			entry = &tm->SharedTaskEntries[0];
			break;
		};

		strcpy_s(Destination, MAX_STRING, entry->TaskTitle);
	}

	return true;
}

//----------------------------------------------------------------------------
// MQ2XTargetType

bool MQ2XTargetType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!GetCharInfo() || !GetCharInfo()->pXTargetMgr || VarPtr.DWord >= MAX_EXTENDED_TARGETS)
		return false;

	if (MQTypeMember* pMember = MQ2XTargetType::FindMember(Member))
	{
		const XTARGETSLOT& xts = GetCharInfo()->pXTargetMgr->XTargetSlots[VarPtr.DWord];

		switch (static_cast<xTargetMembers>(pMember->ID))
		{
		case xAddress:
			Dest.DWord = (uint32_t)GetCharInfo()->pXTargetMgr;
			Dest.Type = pIntType;
			return true;

		case TargetType:
			if (const char* ptr = GetXtargetType(xts.xTargetType))
				strcpy_s(DataTypeTemp, ptr);
			else
				strcpy_s(DataTypeTemp, "UNKNOWN");
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case ID:
			Dest.DWord = xts.SpawnID;
			Dest.Type = pIntType;
			return true;

		case Name:
			if (xts.Name[0] != 0)
				strcpy_s(DataTypeTemp, xts.Name);
			else
				strcpy_s(DataTypeTemp, "NULL");
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case PctAggro:
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (pAggroInfo)
			{
				int index = AD_xTarget1 + VarPtr.DWord;
				if (index >= MAX_AGGRO_METER_SIZE)
					return false;

				Dest.DWord = pAggroInfo->aggroData[AD_xTarget1 + VarPtr.DWord].AggroPct;
				return true;
			}
			return false;

		default: break;
		}
	}
	else
	{
		if (VarPtr.DWord >= MAX_EXTENDED_TARGETS)
			return false;

		XTARGETSLOT xts = GetCharInfo()->pXTargetMgr->XTargetSlots[VarPtr.DWord];
		SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(xts.SpawnID);
		if (pSpawn)
		{
			MQVarPtr data;
			data.Ptr = pSpawn;

			return pSpawnType->GetMember(data, Member, Index, Dest);
		}
	}
	return false;
};

//----------------------------------------------------------------------------
// MQ2KeyRingType

MQ2KeyRingType::MQ2KeyRingType() : MQ2Type("keyring")
{
	AddMember(xIndex, "Index");
	AddMember(xName, "Name");
}

bool MQ2KeyRingType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2KeyRingType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<KeyRingTypeMembers>(pMember->ID))
	{
	case xIndex:
		Dest.DWord = LOWORD(VarPtr.DWord) + 1;
		Dest.Type = pIntType;
		return true;

	case xName:
		Dest.Type = pStringType;
		if (CXWnd* krwnd = FindMQ2Window(KeyRingWindowParent))
		{
			CListWnd* clist = nullptr;
			int16_t n = LOWORD(VarPtr.DWord);
			int16_t type = HIWORD(VarPtr.DWord);

			if (type == 2)
				clist = (CListWnd*)krwnd->GetChildItem(FamiliarWindowList);
			else if (type == 1)
				clist = (CListWnd*)krwnd->GetChildItem(IllusionWindowList);
			else
				clist = (CListWnd*)krwnd->GetChildItem(MountWindowList);

			if (clist)
			{
				CXStr Str = clist->GetItemText(n, 2);
				if (!Str.empty())
				{
					strcpy_s(DataTypeTemp, Str.c_str());
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		return false;
	}
	return false;
}

bool MQ2KeyRingType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (CXWnd* krwnd = FindMQ2Window(KeyRingWindowParent))
	{
		CListWnd* clist = nullptr;

		WORD n = LOWORD(VarPtr.DWord);
		WORD type = HIWORD(VarPtr.DWord);

		if (type == 2)
			clist = (CListWnd*)krwnd->GetChildItem(FamiliarWindowList);
		else if (type == 1)
			clist = (CListWnd*)krwnd->GetChildItem(IllusionWindowList);
		else
			clist = (CListWnd*)krwnd->GetChildItem(MountWindowList);

		if (clist)
		{
			CXStr Str = clist->GetItemText(n, 2);
			if (!Str.empty())
			{
				strcpy_s(Destination, MAX_STRING, Str.c_str());
				return true;
			}
		}
	}
	return false;
}

//----------------------------------------------------------------------------
// MQ2ItemFilterDataType

bool MQ2ItemFilterDataType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	ItemFilterData* pItem = (ItemFilterData*)VarPtr.Ptr;
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2ItemFilterDataType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ItemFilterDataMembers>(pMember->ID))
	{
	case Name:
		Dest.Type = pStringType;
		if (pItem && pItem->Name[0])
		{
			strcpy_s(DataTypeTemp, pItem->Name);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ID:
		Dest.DWord = pItem->ID;
		Dest.Type = pIntType;
		return true;

	case AutoRoll:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bAutoRoll = (pItem->Types & (1 << 0)) != 0;
			Dest.DWord = bAutoRoll;
		}
		return true;

	case Need:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bNeed = (pItem->Types & (1 << 1)) != 0;
			Dest.DWord = bNeed;
		}
		return true;

	case Greed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bGreed = (pItem->Types & (1 << 2)) != 0;
			Dest.DWord = bGreed;
		}
		return true;

	case Never:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bNever = (pItem->Types & (1 << 3)) != 0;
			Dest.DWord = bNever;
		}
		return true;

	case IconID:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem)
		{
			Dest.DWord = pItem->Icon;
			return true;
		}
		return false;

	case Types:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem)
		{
			Dest.DWord = pItem->Types;
			return true;
		}
		return false;

	default: break;
	}
	return false;
}

//----------------------------------------------------------------------------
// MQ2AdvLootItemType

bool MQ2AdvLootItemType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	AdvancedLootItem* pItem = (AdvancedLootItem*)VarPtr.Ptr;
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2AdvLootItemType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AdvLootItemMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)pItem;
		Dest.Type = pIntType;
		return true;

	case xIndex:
		Dest.DWord = VarPtr.HighPart;
		Dest.Type = pIntType;
		return true;

	case Name:
		Dest.Type = pStringType;
		if (pItem && pItem->Name[0])
		{
			strcpy_s(DataTypeTemp, pItem->Name);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ID:
		Dest.Int64 = pItem->ItemID;
		Dest.Type = pInt64Type;
		return true;

	case StackSize:
		Dest.DWord = 1;
		Dest.Type = pIntType;

		if (pItem && pItem->LootDetails.GetSize() && pItem->LootDetails[0].StackCount >= 1)
		{
			Dest.DWord = pItem->LootDetails[0].StackCount;
		}
		return true;

	case Corpse:
		Dest.Type = pSpawnType;
		if (pItem && pItem->LootDetails.GetSize())
		{
			if (SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(pItem->LootDetails[0].CorpseID))
			{
				Dest.Ptr = pSpawn;
				return true;
			}
		}
		return false;

	case AutoRoll:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->AutoRoll;
		}
		return true;

	case Need:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->Need;
		}
		return true;

	case Greed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->Greed;
		}
		return true;

	case No:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->No;
		}
		return true;

	case AlwaysNeed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->AlwaysNeed;
		}
		return true;

	case AlwaysGreed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem)
		{
			Dest.DWord = pItem->AlwaysGreed;
		}
		return true;

	case Never:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->Never;
		}
		return true;

	case IconID:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pItem)
		{
			Dest.DWord = pItem->IconID;
			return true;
		}
		return false;

	case xNoDrop:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->NoDrop;
		}
		return true;

	default: break;
	}
	return false;
}

//----------------------------------------------------------------------------
// MQ2AdvLootType

bool MQ2AdvLootType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pAdvancedLootWnd)
		return false;

	MQTypeMember* pMember = MQ2AdvLootType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AdvLootTypeMembers>(pMember->ID))
	{
	case PCount:
		Dest.Int = pAdvancedLootWnd->pPLootList->Items.GetSize();
		Dest.Type = pIntType;
		return true;

	case PList:
		Dest.Type = pAdvLootItemType;
		if (int index = GetIntFromString(Index, 0))
		{
			index--;
			if (index < 0)
				index = 0;
			if (CListWnd* clist = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_PLLList"))
			{
				int listindex = (int)clist->GetItemData(index);
				if (pAdvancedLootWnd->pPLootList && listindex != -1)
				{
					AdvancedLootItem* pItem = &pAdvancedLootWnd->pPLootList->Items[listindex];
					Dest.Ptr = pItem;
					Dest.HighPart = listindex;
					return true;
				}
			}
		}
		return false;

	case SCount:
		Dest.Int = pAdvancedLootWnd->pCLootList->Items.GetSize();
		Dest.Type = pIntType;
		return true;

	case SList:
		Dest.Type = pAdvLootItemType;
		if (int index = GetIntFromString(Index, 0))
		{
			index--;
			if (index < 0)
				index = 0;

			if (CListWnd* clist = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_CLLList"))
			{
				int listindex = (int)clist->GetItemData(index);
				if (pAdvancedLootWnd->pCLootList && listindex != -1)
				{
					AdvancedLootItem* pItem = &pAdvancedLootWnd->pCLootList->Items[listindex];
					Dest.Ptr = pItem;
					Dest.HighPart = listindex;
					return true;
				}
			}
		}
		return false;

	case PWantCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (CListWnd* clist = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_PLLList"))
		{
			for (int i = 0; i < clist->ItemsArray.Count; i++)
			{
				int listindex = (int)clist->GetItemData(i);
				if (pAdvancedLootWnd->pPLootList && listindex != -1)
				{
					AdvancedLootItem& pItem = pAdvancedLootWnd->pPLootList->Items[listindex];
					if (pItem.AlwaysNeed || pItem.AlwaysGreed || pItem.Need || pItem.Greed)
					{
						Dest.DWord++;
					}
				}
			}
		}
		return true;

	case SWantCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (CListWnd* clist = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_CLLList"))
		{
			for (int i = 0; i < clist->ItemsArray.Count; i++)
			{
				int listindex = (int)clist->GetItemData(i);
				if (pAdvancedLootWnd->pCLootList && listindex != -1)
				{
					AdvancedLootItem& pItem = pAdvancedLootWnd->pCLootList->Items[listindex];
					if (pItem.AlwaysNeed || pItem.AlwaysGreed || pItem.Need || pItem.Greed)
					{
						Dest.DWord++;
					}
				}
			}
		}
		return true;

	case xLootInProgress:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (CListWnd* pPersonalList = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_PLLList"))
		{
			if (pAdvancedLootWnd->pCLootList)
			{
				CListWnd* pSharedList = (CListWnd*)pAdvancedLootWnd->pCLootList->SharedLootList;
				Dest.DWord = LootInProgress(pAdvancedLootWnd, pPersonalList, pSharedList);
			}
		}
		return true;

	case Filter:
		Dest.Type = pItemFilterDataType;
		if (pLootFiltersManager)
		{
			if (int id = GetIntFromString(Index, 0))
			{
				if (const ItemFilterData* pifd = pLootFiltersManager->GetItemFilterData(id))
				{
					Dest.Ptr = (ItemFilterData*)pifd; // but its const ....
					return true;
				}
			}
		}
		return false;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2AlertType

MQ2AlertType::MQ2AlertType() : MQ2Type("alert")
{
	TypeMember(List);
	TypeMember(Size);
}

// /echo ${Alert[a].List[b].bGM}
// /echo ${Alert[a].Size}
// /echo ${Alert}
bool MQ2AlertType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!CAlerts.AlertExist(VarPtr.DWord))
		return false;

	MQTypeMember* pMember = MQ2AlertType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AlertTypeMembers>(pMember->ID))
	{
	case List:
		if (IsNumber(Index))
		{
			Dest.DWord = MAKELONG(VarPtr.DWord, GetIntFromString(Index, 0));
			Dest.Type = pAlertListType;
			return true;
		}
		break;

	case Size:
		Dest.Type = pIntType;
		Dest.DWord = CAlerts.GetCount(VarPtr.DWord);
		return true;

	default: break;
	}

	return false;
}

bool MQ2AlertType::ToString(MQVarPtr VarPtr, char* Destination)
{
	std::vector<MQSpawnSearch> ss;

	if (CAlerts.GetAlert(VarPtr.DWord, ss))
	{
		_itoa_s(ss.size(), Destination, MAX_STRING, 10);
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2AlertListType

bool MQ2AlertListType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2AlertListType::FindMember(Member);
	if (!pMember)
		return false;

	uint16_t theindex = LOWORD(VarPtr.DWord);
	uint16_t itemIndex = HIWORD(VarPtr.DWord);

	std::vector<MQSpawnSearch> ss;
	if (CAlerts.GetAlert(theindex, ss))
	{
		if (itemIndex < ss.size())
		{
			MQSpawnSearch& search = ss[itemIndex];

			switch (static_cast<AlertListTypeMembers>(pMember->ID))
			{
			case MinLevel:
				Dest.DWord = search.MinLevel;
				Dest.Type = pIntType;
				return true;

			case MaxLevel:
				Dest.DWord = search.MaxLevel;
				Dest.Type = pIntType;
				return true;

			case SpawnType:
				Dest.DWord = search.SpawnType;
				Dest.Type = pIntType;
				return true;

			case SpawnID:
				Dest.DWord = search.SpawnID;
				Dest.Type = pIntType;
				return true;

			case FromSpawnID:
				Dest.DWord = search.FromSpawnID;
				Dest.Type = pIntType;
				return true;

			case Radius:
				Dest.Float = search.Radius;
				Dest.Type = pFloatType;
				return true;

			case Name:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szName);
				if (DataTypeTemp[0])
				{
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case BodyType:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szBodyType);
				if (DataTypeTemp[0]) {
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case Race:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szRace);
				if (DataTypeTemp[0]) {
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case Class:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szClass);
				if (DataTypeTemp[0]) {
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case Light:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szLight);
				if (DataTypeTemp[0])
				{
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case GuildID:
				Dest.UInt64 = search.GuildID;
				Dest.Type = pInt64Type;
				return true;

			case bSpawnID:
				Dest.DWord = search.bSpawnID;
				Dest.Type = pBoolType;
				return true;

			case bNotNearAlert:
				Dest.DWord = search.bNotNearAlert;
				Dest.Type = pBoolType;
				return true;

			case bNearAlert:
				Dest.DWord = search.bNearAlert;
				Dest.Type = pBoolType;
				return true;

			case bNoAlert:
				Dest.DWord = search.bNoAlert;
				Dest.Type = pBoolType;
				return true;

			case bAlert:
				Dest.DWord = search.bAlert;
				Dest.Type = pBoolType;
				return true;

			case bLFG:
				Dest.DWord = search.bLFG;
				Dest.Type = pBoolType;
				return true;

			case bTrader:
				Dest.DWord = search.bTrader;
				Dest.Type = pBoolType;
				return true;

			case bLight:
				Dest.DWord = search.bLight;
				Dest.Type = pBoolType;
				return true;

			case bTargNext:
				Dest.DWord = search.bTargNext;
				Dest.Type = pBoolType;
				return true;

			case bTargPrev:
				Dest.DWord = search.bTargPrev;
				Dest.Type = pBoolType;
				return true;

			case bGroup:
				Dest.DWord = search.bGroup;
				Dest.Type = pBoolType;
				return true;

			case bFellowship:
				Dest.DWord = search.bFellowship;
				Dest.Type = pBoolType;
				return true;

			case bNoGroup:
				Dest.DWord = search.bNoGroup;
				Dest.Type = pBoolType;
				return true;

			case bRaid:
				Dest.DWord = search.bRaid;
				Dest.Type = pBoolType;
				return true;

			case bGM:
				Dest.DWord = search.bGM;
				Dest.Type = pBoolType;
				return true;

			case bNamed:
				Dest.DWord = search.bNamed;
				Dest.Type = pBoolType;
				return true;

			case bMerchant:
				Dest.DWord = search.bMerchant;
				Dest.Type = pBoolType;
				return true;

			case bBanker:
				Dest.DWord = search.bBanker;
				Dest.Type = pBoolType;
				return true;

			case bTributeMaster:
				Dest.DWord = search.bTributeMaster;
				Dest.Type = pBoolType;
				return true;

			case bKnight:
				Dest.DWord = search.bKnight;
				Dest.Type = pBoolType;
				return true;

			case bTank:
				Dest.DWord = search.bTank;
				Dest.Type = pBoolType;
				return true;

			case bHealer:
				Dest.DWord = search.bHealer;
				Dest.Type = pBoolType;
				return true;

			case bDps:
				Dest.DWord = search.bDps;
				Dest.Type = pBoolType;
				return true;

			case bSlower:
				Dest.DWord = search.bSlower;
				Dest.Type = pBoolType;
				return true;

			case bAura:
				Dest.DWord = search.bAura;
				Dest.Type = pBoolType;
				return true;

			case bBanner:
				Dest.DWord = search.bBanner;
				Dest.Type = pBoolType;
				return true;

			case bCampfire:
				Dest.DWord = search.bCampfire;
				Dest.Type = pBoolType;
				return true;

			case NotID:
				Dest.DWord = search.NotID;
				Dest.Type = pIntType;
				return true;

			case NotNearAlertList:
				Dest.DWord = search.NotNearAlertList;
				Dest.Type = pIntType;
				return true;

			case NearAlertList:
				Dest.DWord = search.NearAlertList;
				Dest.Type = pIntType;
				return true;

			case NoAlertList:
				Dest.DWord = search.NoAlertList;
				Dest.Type = pIntType;
				return true;

			case AlertList:
				Dest.DWord = search.AlertList;
				Dest.Type = pIntType;
				return true;

			case ZRadius:
				Dest.Double = search.ZRadius;
				Dest.Type = pDoubleType;
				return true;

			case FRadius:
				Dest.Double = search.FRadius;
				Dest.Type = pDoubleType;
				return true;

			case xLoc:
				Dest.Float = search.xLoc;
				Dest.Type = pFloatType;
				return true;

			case yLoc:
				Dest.Float = search.yLoc;
				Dest.Type = pFloatType;
				return true;

			case bKnownLocation:
				Dest.DWord = search.bKnownLocation;
				Dest.Type = pBoolType;
				return true;

			case bNoPet:
				Dest.DWord = search.bNoPet;
				Dest.Type = pBoolType;
				return true;

			case SortBy:
				Dest.DWord = static_cast<unsigned int>(search.SortBy);
				Dest.Type = pIntType;
				return true;

			case bNoGuild:
				Dest.DWord = search.bNoGuild;
				Dest.Type = pBoolType;
				return true;

			case bLoS:
				Dest.DWord = search.bLoS;
				Dest.Type = pBoolType;
				return true;

			case bExactName:
				Dest.DWord = search.bExactName;
				Dest.Type = pBoolType;
				return true;

			case bTargetable:
				Dest.DWord = search.bTargetable;
				Dest.Type = pBoolType;
				return true;

			case PlayerState:
				Dest.DWord = search.PlayerState;
				Dest.Type = pIntType;
				return true;

			case Spawn:
				Dest.Type = pSpawnType;
				if (uint32_t spawnid = search.SpawnID)
				{
					if (SPAWNINFO* psp = (SPAWNINFO*)GetSpawnByID(spawnid))
					{
						Dest.Ptr = psp;
						return true;
					}
				}

				if (search.szName[0])
				{
					if (SPAWNINFO* psp = (SPAWNINFO*)GetSpawnByName(search.szName))
					{
						Dest.Ptr = psp;
						return true;
					}
				}
				return false;
			}
		}
	}
	return false;
}

//----------------------------------------------------------------------------
// MQ2WorldLocationType

bool MQ2WorldLocationType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2WorldLocationType::FindMember(Member);
	if (!pMember)
		return false;

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return false;

	uint32_t index = VarPtr.DWord;

	switch (static_cast<WorldLocationTypeMembers>(pMember->ID))
	{
	case ID: {
		int zindex = pProfile->BoundLocations[index].ZoneBoundID;
		Dest.DWord = zindex;
		Dest.Type = pIntType;
		return true;
	}

	case Zone: {
		Dest.Type = pZoneType;

		int zindex = pProfile->BoundLocations[index].ZoneBoundID & 0x7FFF;
		if (zindex < MAX_ZONES)
		{
			Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[zindex];
		}

		if (!Dest.Ptr)
			return false;
		return true;
	}

	case Y:
		Dest.Float = pProfile->BoundLocations[index].ZoneBoundY;
		Dest.Type = pFloatType;
		return true;

	case X:
		Dest.Float = pProfile->BoundLocations[index].ZoneBoundX;
		Dest.Type = pFloatType;
		return true;

	case Z:
		Dest.Float = pProfile->BoundLocations[index].ZoneBoundZ;
		Dest.Type = pFloatType;
		return true;

	case Heading:
		Dest.Float = pProfile->BoundLocations[index].ZoneBoundHeading;
		Dest.Type = pFloatType;
		return true;

	default: break;
	};

	return false;
}

//----------------------------------------------------------------------------
// MQ2SolventType

bool MQ2SolventType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	int itemid = VarPtr.DWord;
	if (itemid == -1)
		itemid = 52023;

	MQTypeMember* pMember = MQ2SolventType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<SolventTypeMembers>(pMember->ID))
	{
	case Name:
		strcpy_s(DataTypeTemp, GetAugmentNameByID(itemid));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ID:
		Dest.DWord = itemid;
		Dest.Type = pIntType;
		return true;

	case Item: // do we have this solvent?
		Dest.Type = pItemType;
		if (CONTENTS* pItem = FindItemByID(itemid))
		{
			Dest.Ptr = pItem;
			return true;
		}
		return false;

	case Count: // do we have this solvent and if so how many?
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (CONTENTS* pCont = FindItemByID(itemid))
		{
			if (PITEMINFO pItem = GetItemFromContents(pCont))
			{
				Dest.DWord = FindItemCountByName(pItem->Name);
			}
		}
		return true;

	default: break;
	};

	return false;
}

//----------------------------------------------------------------------------
// MQ2AugType

MQ2AugType::MQ2AugType() : MQ2Type("augtype")
{
	TypeMember(Slot);
	TypeMember(Type);
	TypeMember(Visible);
	TypeMember(Infusable);
	TypeMember(Empty);
	TypeMember(Name);
	TypeMember(Item);
	TypeMember(Solvent);
}

bool MQ2AugType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CONTENTS* pCont = (CONTENTS*)VarPtr.HighPart;
	if (!pCont)
		return false;

	PITEMINFO pItem = GetItemFromContents(pCont);
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2AugType::FindMember(Member);
	if (!pMember)
		return false;

	DWORD index = VarPtr.DWord;

	switch (static_cast<AugTypeMembers>(pMember->ID))
	{
	case Slot:
		Dest.DWord = index + 1;
		Dest.Type = pIntType;
		return true;

	case Type:
		Dest.DWord = pItem->AugData.Sockets[index].Type;
		Dest.Type = pIntType;
		return true;

	case Visible:
		Dest.DWord = pItem->AugData.Sockets[index].bVisible;
		Dest.Type = pBoolType;
		return true;

	case Infusable:
		Dest.DWord = pItem->AugData.Sockets[index].bInfusible;
		Dest.Type = pBoolType;
		return true;

	case Empty:
		Dest.DWord = true;
		Dest.Type = pBoolType;
		if (CONTENTS* pCret = pCont->GetContent(index))
			Dest.DWord = false;
		return true;

	case Name:
		Dest.Type = pStringType;
		if (CONTENTS* pCret = pCont->GetContent(index))
		{
			if (ITEMINFO* pAug = GetItemFromContents(pCret))
			{
				strcpy_s(DataTypeTemp, pAug->Name);
				Dest.Ptr = DataTypeTemp;
				return true;
			}
		}
		return false;

	case Item:
		Dest.Type = pItemType;
		if (CONTENTS* pCret = pCont->GetContent(index))
		{
			Dest.Ptr = pCret;
			return true;
		}
		return false;

	case Solvent:
		Dest.DWord = 0;
		Dest.Type = pSolventType;
		if (CONTENTS* pCret = pCont->GetContent(index))
		{
			if (ITEMINFO* ptheAug = GetItemFromContents(pCret))
			{
				Dest.DWord = ptheAug->SolventItemID;
				return true;
			}
		}
		return false;

	default: break;
	};

	return false;
}

bool MQ2AugType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (CONTENTS* pCont = (CONTENTS*)VarPtr.HighPart)
	{
		if (CONTENTS* pAug = pCont->GetContent(VarPtr.DWord))
		{
			if (ITEMINFO* pAugItem = GetItemFromContents(pAug))
			{
				strcpy_s(Destination, MAX_STRING, pAugItem->Name);
				return true;
			}
		}
	}
	return false;
}

//----------------------------------------------------------------------------
// MQ2RangeType

bool MQ2RangeType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2RangeType::FindMember(Member);
	if (!pMember)
		return false;
	if (!Index[0])
		return false;

	int P1 = 0;
	int P2 = 0;
	int P3 = 0;

	switch (static_cast<RangeMembers>(pMember->ID))
	{
	case Inside:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (Index[0])
		{
			if (char* pColon = strchr(Index, ':'))
			{
				*pColon = 0;
				P3 = GetIntFromString(&pColon[1], P3);
				if (char* pComma = strchr(Index, ','))
				{
					*pComma = 0;
					P2 = GetIntFromString(&pComma[1], P2);
					P1 = GetIntFromString(Index, P1);

					if (P3 > P1 && P3 < P2)
					{
						Dest.DWord = true;
						return true;
					}
				}
			}
		}
		return true;

	case Between:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (Index[0]) {
			if (char* pColon = strchr(Index, ':'))
			{
				*pColon = 0;
				P3 = GetIntFromString(&pColon[1], P3);
				if (char* pComma = strchr(Index, ','))
				{
					*pComma = 0;
					P2 = GetIntFromString(&pComma[1], P2);
					P1 = GetIntFromString(Index, P1);

					if (P3 >= P1 && P3 <= P2)
					{
						Dest.DWord = true;
						return true;
					}
				}
			}
		}
		return true;

	default: break;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2AuraType

bool MQ2AuraType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	AURAINFO* pAura = (AURAINFO*)VarPtr.Ptr;
	if (!pAura)
		return false;

	int index = VarPtr.HighPart;

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2AuraType::FindMember(Member);
	if (pMember)
	{
		switch (static_cast<AuraTypeMembers>(pMember->ID))
		{
		case ID:
			Dest.DWord = index + 1;
			Dest.Type = pIntType;
			return true;

		case Find: {
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (!Index[0])
				return false;

			int pos = ci_find_substr(pAura->Name, Index);
			if (pos != -1)
			{
				Dest.DWord = pos + 1;
				return true;
			}

			return false;
		}

		case Name:
			strcpy_s(DataTypeTemp, pAura->Name);
			Dest.Ptr = DataTypeTemp;
			Dest.Type = pStringType;
			return true;

		case SpawnID:
			Dest.DWord = pAura->SpawnID;
			Dest.Type = pIntType;
			return true;

		default: break;
		};

		return false;
	}

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2AuraType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<AuraTypeMethods>(pMethod->ID))
		{
		case Remove:
			if (!pAuraWnd)
				break;

			if (CListWnd* clist = (CListWnd*)pAuraWnd->GetChildItem("AuraList"))
			{
				if (index > clist->ItemsArray.Count)
					break;

				clist->SetCurSel(index);
				pAuraWnd->WndNotification(clist, XWM_MENUSELECT, (void*)1);
				return true;
			}
			break;
		}
		return false;
	}

	return false;
}

//----------------------------------------------------------------------------
// MQ2BandolierItemType

bool MQ2BandolierItemType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (BandolierItemInfo* ptr = (BandolierItemInfo*)VarPtr.Ptr)
	{
		MQTypeMember* pMember = MQ2BandolierItemType::FindMember(Member);
		if (pMember)
		{
			switch (static_cast<BandolierItemTypeMembers>(pMember->ID))
			{
			case xIndex:
				Dest.DWord = VarPtr.HighPart;
				Dest.Type = pIntType;
				return true;

			case IconID:
				Dest.DWord = ptr->IconID;
				Dest.Type = pIntType;
				return true;

			case ID:
				Dest.DWord = ptr->ItemID;
				Dest.Type = pIntType;
				return true;

			case Name:
				strcpy_s(DataTypeTemp, ptr->Name);
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;

			default: break;
			};

			return false;
		}
	}
	return false;
}

//----------------------------------------------------------------------------
// MQ2BandolierType

bool MQ2BandolierType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	PcProfile* pcProfile = GetPcProfile();
	if (!pcProfile)
		return false;

	const int index = std::clamp<int>(VarPtr.DWord, 0, MAX_BANDOLIER_ITEMS - 1);

	BandolierSet* pBand = &pcProfile->Bandolier[index];
	if (!pBand)
		return false;

	if (!pBand->Name[0])
		return false;

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2BandolierType::FindMember(Member);
	if (pMember)
	{
		switch (static_cast<BandolierTypeMembers>(pMember->ID))
		{
		case Active:
			Dest.DWord = 0;
			Dest.Type = pBoolType;

			// TODO: Fix duplication
			if (pcProfile->pInventoryArray && pcProfile->pInventoryArray->InventoryArray[0])
			{
				if (pBand->Items[0].ItemID)
				{
					if (!pcProfile->pInventoryArray->Inventory.Primary)
						return true;

					if (pcProfile->pInventoryArray->Inventory.Primary->ID != pBand->Items[0].ItemID)
						return true;
				}
				else if (pcProfile->pInventoryArray->Inventory.Primary)
				{
					return true;
				}

				if (pBand->Items[1].ItemID)
				{
					if (!pcProfile->pInventoryArray->Inventory.Secondary)
						return true;

					if (pcProfile->pInventoryArray->Inventory.Secondary->ID != pBand->Items[1].ItemID)
						return true;
				}
				else if (pcProfile->pInventoryArray->Inventory.Secondary)
				{
					return true;
				}

				if (pBand->Items[2].ItemID)
				{
					if (!pcProfile->pInventoryArray->Inventory.Range)
						return true;

					if (pcProfile->pInventoryArray->Inventory.Range->ID != pBand->Items[2].ItemID)
						return true;
				}
				else if (pcProfile->pInventoryArray->Inventory.Range)
				{
					return true;
				}

				if (pBand->Items[3].ItemID)
				{
					if (!pcProfile->pInventoryArray->Inventory.Ammo)
						return true;

					if (pcProfile->pInventoryArray->Inventory.Ammo->ID != pBand->Items[3].ItemID)
						return true;
				}
				else if (pcProfile->pInventoryArray->Inventory.Ammo)
				{
					return true;
				}

				Dest.DWord = 1;
			}
			return true;

		case xIndex:
			Dest.DWord = index + 1;
			Dest.Type = pIntType;
			return true;

		case Item: {
			Dest.Type = pBandolierItemType;
			if (!Index[0])
				return false;

			const int indexItem = std::clamp(GetIntFromString(Index, 0) - 1, 0, MAX_BANDOLIER_SLOTS - 1);
			Dest.HighPart = indexItem;
			Dest.Ptr = (void*)&pBand->Items[indexItem];
			return true;
		}

		case Name:
			strcpy_s(DataTypeTemp, pBand->Name);
			Dest.Ptr = DataTypeTemp;
			Dest.Type = pStringType;
			return true;

		default: break;
		};

		return false;
	}

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2BandolierType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<BandolierTypeMethods>(pMethod->ID))
		{
		case Activate:
			pPCData->BandolierSwap(index);

			if (pBandolierWnd)
			{
				if (pBandolierWnd->pWeaponSetList)
				{
					pBandolierWnd->pWeaponSetList->SetCurSel(index);
				}
			}

			Dest.DWord = 1;
			Dest.Type = pBoolType;
			return true;
		}
		return false;
	}

	return false;
}

} // namespace mq
