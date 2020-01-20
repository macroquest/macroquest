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

#pragma once

#include "../MQ2Main.h"

namespace mq::datatypes {

// non-mq2data TODO
// command to clear macro return value
// networking
// macro line continuation e.g. \
// command to set raid class colors
// /cast list
// #chat tell
//
// mq2data todo:
// -------------
// "bind" type (key binds)
// Friend TLO
// Ignore TLO
// key state (ctrl/shift/alt)
// spawn count

#define TypeMember(name) AddMember(static_cast<int>(name), #name)
#define TypeMethod(name) AddMethod(static_cast<int>(name), #name)

//----------------------------------------------------------------------------
// Datatype Declarations

// class MQBoolType;
// MQ2BoolType* pBoolType
#define DATATYPE(Class, Var, Inherits, PersistentClass)              \
	class Class;                                                     \
	MQLIB_VAR Class* Var;

#include "DataTypeList.h"

#undef DATATYPE

//============================================================================
// MQ2Type

class MQ2Type
{
public:
	MQLIB_OBJECT MQ2Type(const char* NewName);
	MQLIB_OBJECT virtual ~MQ2Type();

	MQLIB_OBJECT void InitializeMembers(MQTypeMember* MemberArray);

	virtual bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) { return false; }
	virtual bool FromString(MQVarPtr& VarPtr, char* Source) { return false; }

	virtual void InitVariable(MQVarPtr& VarPtr)
	{
		VarPtr.Ptr = nullptr;
		VarPtr.HighPart = 0;
	}

	virtual void FreeVariable(MQVarPtr& VarPtr) {}

	virtual bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) = 0;

	virtual bool ToString(MQVarPtr VarPtr, char* Destination)
	{
		strcpy_s(Destination, MAX_STRING, TypeName);
		return true;
	}

	MQLIB_OBJECT const char* GetName() const;
	MQLIB_OBJECT const char* GetMemberName(int ID) const;

	MQLIB_OBJECT bool GetMemberID(const char* Name, int& Result) const;

	MQLIB_OBJECT MQTypeMember* FindMember(const char* Name);
	MQLIB_OBJECT MQTypeMember* FindMethod(const char* Name);

	bool InheritedMember(const char* Name)
	{
		if (!pInherits || !pInherits->FindMember(Name))
			return false;

		return true;
	}

	void SetInheritance(MQ2Type* pNewInherit)
	{
		pInherits = pNewInherit;
	}

protected:
	MQLIB_OBJECT bool AddMember(int id, const char* Name);
	MQLIB_OBJECT bool RemoveMember(const char* Name);
	MQLIB_OBJECT bool AddMethod(int ID, const char* Name);
	MQLIB_OBJECT bool RemoveMethod(const char* Name);

	char TypeName[32];
	bool m_owned = false;
	MQ2Type* pInherits = nullptr;
	mutable std::mutex m_mutex;

private:
	std::vector<std::unique_ptr<MQTypeMember>> Members;
	std::vector<std::unique_ptr<MQTypeMember>> Methods;
	std::unordered_map<std::string, int> MemberMap;
	std::unordered_map<std::string, int> MethodMap;
};

//============================================================================
// CDataArray

class CDataArray
{
public:
	CDataArray() = default;
	CDataArray(MQ2Type* Type, char* Index, const char* Default, bool ByData = false)
	{
		m_nExtents = 1;
		m_totalElements = 1;

		// count number of , 's
		if (const char* pComma = strchr(Index, ','))
		{
			m_nExtents++;
			while (pComma = strchr(&pComma[1], ','))
			{
				m_nExtents++;
			}
		}

		// allocate extents
		m_pExtents = new int[m_nExtents];

		// read extents
		char* pStart = Index;
		for (int index = 0; index < m_nExtents; index++)
		{
			char* pComma = strchr(pStart, ',');
			if (pComma)
				*pComma = 0;

			m_pExtents[index] = GetIntFromString(pStart, 0);
			m_totalElements *= m_pExtents[index];

			if (pComma)
			{
				*pComma = ',';
				pStart = &pComma[1];
			}
		}

		m_pData = new MQVarPtr[m_totalElements];
		m_pType = Type;
		if (m_pType != nullptr)
		{
			for (int index = 0; index < m_totalElements; index++)
			{
				m_pType->InitVariable(m_pData[index]);

				if (ByData)
					m_pType->FromData(m_pData[index], *(MQTypeVar*)Default);
				else
					m_pType->FromString(m_pData[index], (char*)Default);
			}
		}
	}

	~CDataArray()
	{
		if (m_pType && m_pData)
		{
			for (int index = 0; index < m_totalElements; index++)
			{
				m_pType->FreeVariable(m_pData[index]);
			}
		}

		delete[] m_pExtents;
		delete[] m_pData;
	}

	void Delete()
	{
		if (m_pType && m_pData)
		{
			for (int index = 0; index < m_totalElements; index++)
			{
				m_pType->FreeVariable(m_pData[index]);
			}
		}

		delete[] m_pExtents;
		delete[] m_pData;

		m_pExtents = nullptr;
		m_pType = nullptr;
		m_pData = nullptr;
		m_nExtents = 0;
		m_totalElements = 0;
	}

	int GetElement(char* Index)
	{
		int Element = 0;
		if (m_nExtents == 1)
		{
			if (strchr(Index, ','))
				return -1;

			Element = GetIntFromString(Index, Element) - 1;
			if (Element >= m_totalElements)
				return -1;

			return Element;
		}

		int nGetExtents = 1;

		if (char* pComma = strchr(Index, ','))
		{
			nGetExtents++;
			while (pComma = strchr(&pComma[1], ','))
			{
				nGetExtents++;
			}
		}

		if (nGetExtents != m_nExtents)
			return -1;

		// read extents
		char* pStart = Index;
		for (int index = 0; index < m_nExtents; index++)
		{
			char* pComma = strchr(pStart, ',');
			if (pComma)
				*pComma = 0;

			int Temp = GetIntFromString(pStart, 0) - 1;
			if (Temp >= m_pExtents[index] || Temp < 0)
				return -1;

			for (int i = index + 1; i < m_nExtents; i++)
				Temp *= m_pExtents[i];
			Element += Temp;

			if (pComma)
			{
				*pComma = ',';
				pStart = &pComma[1];
			}
		}

		return Element;
	}

	bool GetElement(char* Index, MQTypeVar& Dest)
	{
		if (m_nExtents == 1)
		{
			if (strchr(Index, ','))
				return false;

			int Element = GetIntFromString(Index, 0) - 1;
			if (Element >= m_totalElements || Element < 0)
				return false;

			Dest.Type = m_pType;
			Dest.VarPtr = m_pData[Element];

			return true;
		}

		int nGetExtents = 1;

		if (char* pComma = strchr(Index, ','))
		{
			nGetExtents++;
			while (pComma = strchr(&pComma[1], ','))
			{
				nGetExtents++;
			}
		}

		if (nGetExtents != m_nExtents)
			return false;

		// read extents
		char* pStart = Index;
		int Element = 0;

		for (int index = 0; index < m_nExtents; index++)
		{
			char* pComma = strchr(pStart, ',');
			if (pComma)
				*pComma = 0;

			int Temp = GetIntFromString(pStart, 0) - 1;
			if (Temp >= m_pExtents[index] || Temp < 0)
				return false;

			for (int i = index + 1; i < m_nExtents; i++)
				Temp *= m_pExtents[i];

			Element += Temp;
			if (pComma)
			{
				*pComma = ',';
				pStart = &pComma[1];
			}
		}

		Dest.Type = m_pType;
		Dest.VarPtr = m_pData[Element];
		return true;
	}

	MQ2Type* GetType() { return m_pType; }
	MQVarPtr& GetData(int index) { return m_pData[index]; }
	int GetExtents(int index) const { return m_pExtents[index]; }
	int GetNumExtents() const { return m_nExtents; }
	int GetTotalElements() const { return m_totalElements; }

private:
	MQ2Type* m_pType = nullptr;
	MQVarPtr* m_pData = nullptr;
	int* m_pExtents = nullptr;
	int m_nExtents = 0;
	int m_totalElements = 0;
};



//============================================================================
// MQ2BoolType

class MQ2BoolType : public MQ2Type
{
public:
	MQ2BoolType() : MQ2Type("bool")
	{
	}

	// pure type, no members
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override
	{
		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (VarPtr.DWord)
			strcpy_s(Destination, MAX_STRING, "TRUE");
		else
			strcpy_s(Destination, MAX_STRING, "FALSE");
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.DWord = Source.DWord;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.DWord = 0;
		if (!_stricmp(Source, "TRUE"))
			VarPtr.DWord = 1;
		else if (GetFloatFromString(Source, 0) != 0)
			VarPtr.DWord = 1;
		return true;
	}
};

//============================================================================
// MQ2IntType

class MQ2IntType : public MQ2Type
{
public:
	enum IntMembers
	{
		Float = 1,
		Double = 2,
		Hex = 3,
		Reverse = 4,
		LowPart = 5,
		HighPart = 6,
	};

	MQ2IntType() : MQ2Type("int")
	{
		TypeMember(Float);
		TypeMember(Double);
		TypeMember(Hex);
		TypeMember(Reverse);
		TypeMember(LowPart);
		TypeMember(HighPart);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		_itoa_s(VarPtr.Int, Destination, MAX_STRING, 10);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.Int = Source.Int;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.Int = GetIntFromString(Source, -1);
		return true;
	}
};

//============================================================================
// MQ2Int64Type

class MQ2Int64Type : public MQ2Type
{
public:
	enum Int64Members
	{
		Float = 1,
		Double = 2,
		Hex = 3,
		Reverse = 4,
		LowPart = 5,
		HighPart = 6,
	};

	MQ2Int64Type() : MQ2Type("int64")
	{
		TypeMember(Float);
		TypeMember(Double);
		TypeMember(Hex);
		TypeMember(Reverse);
		TypeMember(LowPart);
		TypeMember(HighPart);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		_i64toa_s(VarPtr.Int64, Destination, MAX_STRING, 10);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.Int64 = Source.Int64;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.Int64 = _atoi64(Source);
		return true;
	}
};

//============================================================================
// MQ2ArgbType

class MQ2ArgbType : public MQ2Type
{
public:
	enum ArgbMembers
	{
		A = 0,
		R = 1,
		G = 2,
		B = 3,
		Int = 4,
	};

	MQ2ArgbType() : MQ2Type("argb")
	{
		TypeMember(A);
		TypeMember(R);
		TypeMember(G);
		TypeMember(B);
		TypeMember(Int);
	}

	~MQ2ArgbType()
	{
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		sprintf_s(Destination, MAX_STRING, "%x", VarPtr.Int);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.DWord = Source.DWord;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		if (sscanf_s(Source, "%x", &VarPtr.Int))
		{
			return true;
		}
		return false;
	}
};

//============================================================================
// MQ2ByteType

class MQ2ByteType : public MQ2Type
{
public:
	MQ2ByteType() : MQ2Type("byte")
	{
	}

	// pure type, no members
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override
	{
		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		_itoa_s(VarPtr.Int, Destination, MAX_STRING, 10);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.DWord = Source.DWord % 0xFF;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.DWord = GetIntFromString(Source, 0) % 0xFF;
		return true;
	}
};

//============================================================================
// MQ2StringType

class MQ2StringType : public MQ2Type
{
public:
	enum StringMembers
	{
		Arg = 1,
		Mid = 2,
		Left = 3,
		Right = 4,
		Find = 5,
		Length = 6,
		Upper = 7,
		Lower = 8,
		Compare = 9,
		CompareCS = 10,
		Equal = 11,
		NotEqual = 12,
		EqualCS = 13,
		NotEqualCS = 14,
		Count = 15,
		Token = 16,
		Replace = 17
	};

	MQ2StringType() : MQ2Type("string")
	{
		TypeMember(Arg);
		TypeMember(Mid);
		TypeMember(Left);
		TypeMember(Right);
		TypeMember(Find);
		TypeMember(Length);
		TypeMember(Upper);
		TypeMember(Lower);
		TypeMember(Compare);
		TypeMember(CompareCS);
		TypeMember(Equal);
		TypeMember(NotEqual);
		TypeMember(EqualCS);
		TypeMember(NotEqualCS);
		TypeMember(Count);
		TypeMember(Token);
		TypeMember(Replace);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, static_cast<const char*>(VarPtr.Ptr));
		return true;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
		VarPtr.Ptr = LocalAlloc(LPTR, MAX_STRING);
		VarPtr.HighPart = 0;
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		LocalFree(VarPtr.Ptr);
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pStringType)
			return false;

		strcpy_s(static_cast<char*>(VarPtr.Ptr), MAX_STRING, static_cast<const char*>(Source.Ptr));
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		strcpy_s(static_cast<char*>(VarPtr.Ptr), MAX_STRING, Source);
		return true;
	}
};

//============================================================================
// MQ2FloatType

class MQ2FloatType : public MQ2Type
{
public:
	enum FloatMembers
	{
		Deci = 1,
		Centi = 2,
		Milli = 3,
		Int = 4,
		Precision = 5,
		Raw = 6,
	};

	MQ2FloatType() : MQ2Type("float")
	{
		TypeMember(Deci);
		TypeMember(Centi);
		TypeMember(Milli);
		TypeMember(Int);
		TypeMember(Precision);
		TypeMember(Raw);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		sprintf_s(Destination, MAX_STRING, "%.2f", VarPtr.Float);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pFloatType && Source.Type != (MQ2Type*)pHeadingType)
			VarPtr.Float = (float)Source.DWord;
		else
			VarPtr.Float = Source.Float;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.Float = GetFloatFromString(Source, 0);
		return true;
	}
};

//============================================================================
// MQ2DoubleType

class MQ2DoubleType : public MQ2Type
{
public:
	enum DoubleMembers
	{
		Deci = 1,
		Centi = 2,
		Milli = 3,
		Int = 4,
		Precision = 5,
	};

	MQ2DoubleType() : MQ2Type("double")
	{
		TypeMember(Deci);
		TypeMember(Centi);
		TypeMember(Milli);
		TypeMember(Int);
		TypeMember(Precision);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		sprintf_s(Destination, MAX_STRING, "%.2f", VarPtr.Double);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pDoubleType && Source.Type != (MQ2Type*)pHeadingType)
			VarPtr.Double = Source.Double;
		else
			VarPtr.Double = Source.Double;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.Double = GetDoubleFromString(Source, 0);
		return true;
	}
};

//============================================================================
// MQ2TicksType

class MQ2TicksType : public MQ2Type
{
public:
	enum TicksMembers
	{
		Hours = 1,
		Minutes = 2,
		Seconds = 3,
		Time = 4,
		TotalMinutes = 5,
		TotalSeconds = 6,
		Ticks = 7,
		TimeHMS = 8,
	};

	MQ2TicksType() : MQ2Type("ticks")
	{
		TypeMember(Hours);
		TypeMember(Minutes);
		TypeMember(Seconds);
		TypeMember(Time);
		TypeMember(TotalMinutes);
		TypeMember(TotalSeconds);
		TypeMember(Ticks);
		TypeMember(TimeHMS);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;


	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		_itoa_s(VarPtr.DWord, Destination, MAX_STRING, 10);
		return true;
	}
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.DWord = Source.DWord;
		return true;
	}
	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.DWord = GetIntFromString(Source, 0);
		return true;
	}
};

//============================================================================
// MQ2TimeStampType

class MQ2TimeStampType : public MQ2Type
{
public:
	enum TimeStampMembers
	{
		Hours = 1,
		Minutes = 2,
		Seconds = 3,
		Time = 4,
		TotalMinutes = 5,
		TotalSeconds = 6,
		Raw = 7,
		Ticks = 8,
		TimeHMS = 9,
		Float = 10,
	};

	MQ2TimeStampType() : MQ2Type("timestamp")
	{
		TypeMember(Hours);
		TypeMember(Minutes);
		TypeMember(Seconds);
		TypeMember(Time);
		TypeMember(TotalMinutes);
		TypeMember(TotalSeconds);
		TypeMember(Raw);
		TypeMember(Ticks);
		TypeMember(TimeHMS);
		TypeMember(Float);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		_i64toa_s(VarPtr.UInt64, Destination, MAX_STRING, 10);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.UInt64 = Source.UInt64;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.UInt64 = _atoi64(Source);
		return true;
	}
};

//============================================================================
// MQ2SpawnType

class MQ2SpawnType : public MQ2Type
{
public:
	enum SpawnMembers
	{
		ID = 1,
		Name = 2,
		Level = 3,
		X = 4,
		Y = 5,
		Z = 6,
		DistanceX = 7,
		DistanceY = 8,
		DistanceZ = 9,
		Distance = 10,
		Distance3D = 11,
		DistancePredict = 12,
		Next = 13,
		Prev = 14,
		Heading = 15,
		Speed = 16,
		Levitating = 17,
		Sneaking = 18,
		HeadingTo = 19,
		Light = 20,
		Body = 21,
		State = 22,
		CurrentHPs = 23,
		MaxHPs = 24,
		PctHPs = 25,
		Deity = 26,
		Type = 28,
		CleanName = 29,
		Surname = 30,
		Guild = 31,
		GuildStatus = 32,
		Master = 33,
		Pet = 34,
		Race = 35,
		Class = 36,
		Gender = 38,
		GM = 39,
		Height = 40,
		MaxRange = 41,
		AARank = 42,
		Casting = 43,
		Mount = 44,
		FeetWet = 45,
		Underwater = 46,
		Animation = 48,
		Holding = 49,
		Look = 50,
		N = 51,
		W = 52,
		U = 53,
		S = 54,
		E = 55,
		D = 56,
		DistanceN = 57,
		DistanceW = 58,
		DistanceU = 59,
		Invis = 60,
		Linkdead = 61,
		LFG = 62,
		Trader = 63,
		AFK = 64,
		xConColor = 65,
		Standing = 67,
		Sitting = 68,
		Ducking = 69,
		Feigning = 70,
		Binding = 71,
		Invited = 72,
		NearestSpawn = 73,
		MaxRangeTo = 74,
		DisplayName = 75,
		AATitle = 76,
		xGroupLeader = 77,
		Mark = 78,
		Assist = 79,
		Anonymous = 80,
		Roleplaying = 81,
		xLineOfSight = 82,
		HeadingToLoc = 83,
		Title = 84,
		Suffix = 85,
		Fleeing = 86,
		Named = 87,
		Buyer = 88,
		Moving = 89,
		StandState = 90,
		Dead = 91,
		Stunned = 92,
		Hovering = 93,
		CurrentMana = 94,
		MaxMana = 95,
		CurrentEndurance = 96,
		PctEndurance = 97,
		MaxEndurance = 98,
		Loc = 99,
		LocYX = 100,
		LocYXZ = 101,
		Owner = 102,
		Following = 103,
		Address = 104,
		Inviter = 105,
		MercID = 106,
		ContractorID = 107,
		PctMana = 108,
		Primary = 109,
		Secondary = 110,
		Equipment = 111,
		xTargetable = 112,
		PlayerState = 113,
		Stuck = 114,
		Aggressive = 115,
		CanSplashLand = 116,
		IsBerserk = 117,
		pTouchingSwitch = 118,
		bShowHelm = 119,
		CorpseDragCount = 120,
		bBetaBuffed = 121,
		CombatSkillTicks = 122,
		FD = 123,
		InPvPArea = 124,
		bAlwaysShowAura = 125,
		GMRank = 126,
		WarCry = 127,
		IsPassenger = 128,
		LastCastTime = 129,
		DragNames = 130,
		DraggingPlayer = 131,
		bStationary = 132,
		BearingToTarget = 133,
		bTempPet = 134,
		HoldingAnimation = 135,
		Blind = 136,
		LastCastNum = 137,
		CollisionCounter = 138,
		CeilingHeightAtCurrLocation = 139,
		AssistName = 140,
		SeeInvis = 141,
		SpawnStatus = 142,
		bWaitingForPort = 143,
		EQLoc = 144,
		MQLoc = 145,
		TimeBeenDead = 146,
		FloorZ = 147,
		IsSummoned = 148,
		TargetOfTarget = 149,
		ActorDef = 150,
		CachedBuff = 151,
		CachedBuffCount = 152,
	};

	enum SpawnMethods
	{
		DoTarget = 1,
		DoFace = 2,
		DoAssist = 4,
		LeftClick = 5,
		RightClick = 6,
	};

	MQ2SpawnType() : MQ2Type("spawn")
	{
		TypeMember(ID);
		TypeMember(Name);
		TypeMember(Level);
		TypeMember(X);
		TypeMember(Y);
		TypeMember(Z);
		TypeMember(DistanceX);
		TypeMember(DistanceY);
		TypeMember(DistanceZ);
		TypeMember(Distance);
		TypeMember(Distance3D);
		TypeMember(DistancePredict);
		TypeMember(Next);
		TypeMember(Prev);
		TypeMember(Heading);
		TypeMember(Speed);
		TypeMember(Levitating);
		TypeMember(Sneaking);
		TypeMember(HeadingTo);
		TypeMember(Light);
		TypeMember(Body);
		TypeMember(State);
		TypeMember(CurrentHPs);
		TypeMember(MaxHPs);
		TypeMember(PctHPs);
		TypeMember(Deity);
		TypeMember(Type);
		TypeMember(CleanName);
		TypeMember(Surname);
		TypeMember(Guild);
		TypeMember(GuildStatus);
		TypeMember(Master);
		TypeMember(Pet);
		TypeMember(Race);
		TypeMember(Class);
		TypeMember(Gender);
		TypeMember(GM);
		TypeMember(Height);
		TypeMember(MaxRange);
		TypeMember(AARank);
		TypeMember(Casting);
		TypeMember(Mount);
		TypeMember(FeetWet);
		TypeMember(Underwater);
		TypeMember(Animation);
		TypeMember(Holding);
		TypeMember(Look);
		TypeMember(N);
		TypeMember(W);
		TypeMember(U);
		TypeMember(S);
		TypeMember(E);
		TypeMember(D);
		TypeMember(DistanceN);
		TypeMember(DistanceW);
		TypeMember(DistanceU);
		TypeMember(Invis);
		TypeMember(Linkdead);
		TypeMember(LFG);
		TypeMember(Trader);
		TypeMember(AFK);
		AddMember(xConColor, "ConColor");
		TypeMember(Standing);
		TypeMember(Sitting);
		TypeMember(Ducking);
		TypeMember(Feigning);
		TypeMember(Binding);
		TypeMember(Invited);
		TypeMember(NearestSpawn);
		TypeMember(MaxRangeTo);
		TypeMember(DisplayName);
		TypeMember(AATitle);
		AddMember(xGroupLeader, "GroupLeader");
		TypeMember(Assist);
		TypeMember(Mark);
		TypeMember(Anonymous);
		TypeMember(Roleplaying);
		AddMember(xLineOfSight, "LineOfSight");
		TypeMember(HeadingToLoc);
		TypeMember(Title);
		TypeMember(Suffix);
		TypeMember(Fleeing);
		TypeMember(Named);
		TypeMember(Buyer);
		TypeMember(Moving);
		TypeMember(StandState);
		TypeMember(Dead);
		TypeMember(Stunned);
		TypeMember(Hovering);
		TypeMember(CurrentMana);
		TypeMember(MaxMana);
		TypeMember(CurrentEndurance);
		TypeMember(PctEndurance);
		TypeMember(MaxEndurance);
		TypeMember(Loc);
		TypeMember(LocYX);
		TypeMember(LocYXZ);
		TypeMember(Owner);
		TypeMember(Following);
		TypeMember(Address);
		TypeMember(Inviter);
		TypeMember(MercID);
		TypeMember(ContractorID);
		TypeMember(PctMana);
		TypeMember(Primary);
		TypeMember(Secondary);
		TypeMember(Equipment);
		AddMember(xTargetable, "Targetable");
		TypeMember(PlayerState);
		TypeMember(Stuck);
		TypeMember(Aggressive);
		TypeMember(CanSplashLand);
		TypeMember(IsBerserk);
		TypeMember(pTouchingSwitch);
		TypeMember(bShowHelm);
		TypeMember(CorpseDragCount);
		TypeMember(bBetaBuffed);
		TypeMember(CombatSkillTicks);
		TypeMember(FD);
		TypeMember(InPvPArea);
		TypeMember(bAlwaysShowAura);
		TypeMember(GMRank);
		TypeMember(WarCry);
		TypeMember(IsPassenger);
		TypeMember(LastCastTime);
		TypeMember(DragNames);
		TypeMember(DraggingPlayer);
		TypeMember(bStationary);
		TypeMember(BearingToTarget);
		TypeMember(bTempPet);
		TypeMember(HoldingAnimation);
		TypeMember(Blind);
		TypeMember(LastCastNum);
		TypeMember(CollisionCounter);
		TypeMember(CeilingHeightAtCurrLocation);
		TypeMember(AssistName);
		TypeMember(SeeInvis);
		TypeMember(SpawnStatus);
		TypeMember(bWaitingForPort);
		TypeMember(EQLoc);
		TypeMember(MQLoc);
		TypeMember(TimeBeenDead);
		TypeMember(FloorZ);
		TypeMember(IsSummoned);
		TypeMember(TargetOfTarget);
		TypeMember(ActorDef);
		TypeMember(CachedBuff);
		TypeMember(CachedBuffCount);

		TypeMethod(DoTarget);
		TypeMethod(DoFace);
		TypeMethod(DoAssist);
		TypeMethod(LeftClick);
		TypeMethod(RightClick);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (!VarPtr.Ptr)
			return false;

		SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
		strcpy_s(Destination, MAX_STRING, pSpawn->Name);
		return true;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not Allocate a SPAWNINFO
		VarPtr.Ptr = new SPAWNINFO();
		VarPtr.HighPart = 0;

		// FIXME: Do not ZeroMemory a SPAWNINFO
		ZeroMemory(VarPtr.Ptr, sizeof(SPAWNINFO));
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Find way to not allocate SPAWNINFO
		SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
		delete pSpawn;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type == pSpawnType)
		{
			memcpy(VarPtr.Ptr, Source.Ptr, sizeof(SPAWNINFO));
			return true;
		}
		else
		{
			if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(Source.DWord))
			{
				memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
				return true;
			}
		}
		return false;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(GetIntFromString(Source, 0)))
		{
			memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
			return true;
		}
		return false;
	}
};

//============================================================================
// MQ2CharacterType

class MQ2CharacterType : public MQ2Type
{
public:
	enum CharacterMembers
	{
		CountSongs = 2,
		MaxBuffSlots = 3,
		Exp = 4,
		Spawn = 5,
		Dar = 6,
		AAExp = 7,
		AAPoints = 8,
		CurrentHPs = 10,
		MaxHPs = 11,
		HPRegen = 12,
		PctHPs = 13,
		CurrentMana = 14,
		MaxMana = 15,
		ManaRegen = 16,
		PctMana = 17,
		Buff = 18,
		Song = 19,
		Book = 20,
		Skill = 21,
		Ability = 22,
		Cash = 24,
		CashBank = 25,
		PlatinumShared = 26,
		Grouped = 27,
		HPBonus = 28,
		ManaBonus = 29,
		GukEarned = 30,
		MMEarned = 31,
		RujEarned = 32,
		TakEarned = 33,
		MirEarned = 34,
		LDoNPoints = 35,
		CurrentFavor = 36,
		CareerFavor = 37,
		Endurance = 38,
		Inventory = 39,
		Bank = 40,
		Combat = 42,
		FreeInventory = 43,
		Gem = 44,
		SpellReady = 45,
		Drunk = 50,
		STR = 51,
		STA = 52,
		CHA = 53,
		DEX = 54,
		INT = 55,
		AGI = 56,
		WIS = 57,
		svMagic = 58,
		svFire = 59,
		svCold = 60,
		svPoison = 61,
		svDisease = 62,
		Hunger = 63,
		Thirst = 64,
		BaseSTR = 65,
		BaseSTA = 66,
		BaseCHA = 67,
		BaseDEX = 68,
		BaseINT = 69,
		BaseAGI = 70,
		BaseWIS = 71,
		PracticePoints = 72,
		PctExp = 73,
		PctAAExp = 74,
		Moving = 75,
		AbilityReady = 76,
		PetBuff = 77,
		Platinum = 78,
		Gold = 79,
		Silver = 80,
		Copper = 81,
		PlatinumBank = 82,
		GoldBank = 83,
		SilverBank = 84,
		CopperBank = 85,
		Stunned = 88,
		RangedReady = 89,
		AltTimerReady = 90,
		MaxEndurance = 91,
		PctEndurance = 92,
		AltAbility = 93,
		AltAbilityReady = 94,
		AltAbilityTimer = 95,
		CombatAbility = 96,
		CombatAbilityTimer = 97,
		LargestFreeInventory = 98,
		TargetOfTarget = 99,
		RaidAssistTarget = 100,
		GroupAssistTarget = 101,
		RaidMarkNPC = 102,
		GroupMarkNPC = 103,
		CountBuffs = 104,
		LanguageSkill = 105,
		EnduranceBonus = 106,
		CombatEffectsBonus = 107,
		ShieldingBonus = 108,
		SpellShieldBonus = 109,
		AvoidanceBonus = 110,
		AccuracyBonus = 111,
		StunResistBonus = 112,
		StrikeThroughBonus = 113,
		AttackBonus = 114,
		HPRegenBonus = 115,
		ManaRegenBonus = 116,
		DamageShieldBonus = 117,
		DoTShieldBonus = 118,
		AttackSpeed = 119,
		GroupList = 120,
		AmIGroupLeader = 121,
		CurrentEndurance = 122,
		EnduranceRegen = 123,
		FreeBuffSlots = 124,
		CurrentWeight = 125,
		AAPointsSpent = 126,
		AAPointsTotal = 127,
		TributeActive = 128,
		CombatAbilityReady = 129,
		Running = 130,
		GroupSize = 131,
		TributeTimer = 132,
		RadiantCrystals = 133,
		EbonCrystals = 134,
		Shrouded = 135,
		AutoFire = 136,
		Language = 137,
		Aura = 138,
		LAMarkNPC = 139,
		LANPCHealth = 140,
		LADelegateMA = 141,
		LADelegateMarkNPC = 142,
		LAInspectBuffs = 143,
		LASpellAwareness = 144,
		LAOffenseEnhancement = 145,
		LAManaEnhancement = 146,
		LAHealthEnhancement = 147,
		LAHealthRegen = 148,
		LAFindPathPC = 149,
		LAHoTT = 150,
		ActiveFavorCost = 151,
		CombatState = 152,
		svCorruption = 153,
		svPrismatic = 154,
		svChromatic = 155,
		Doubloons = 156,
		Orux = 157,
		Phosphenes = 158,
		Phosphites = 159,
		Fellowship = 160,
		Downtime = 161,
		DamageShieldMitigationBonus = 162,
		HeroicSTRBonus = 163,
		HeroicINTBonus = 164,
		HeroicWISBonus = 165,
		HeroicAGIBonus = 166,
		HeroicDEXBonus = 167,
		HeroicSTABonus = 168,
		HeroicCHABonus = 169,
		HealAmountBonus = 170,
		SpellDamageBonus = 171,
		ClairvoyanceBonus = 172,
		EnduranceRegenBonus = 173,
		TotalCounters = 174,
		Faycites = 175,
		Chronobines = 176,
		Mercenary = 177,
		XTarget = 178,
		Haste = 179,
		MercenaryStance = 180,
		SkillCap = 181,
		GemTimer = 182,
		HaveExpansion = 183,
		PctAggro = 184,
		SecondaryPctAggro = 185,
		SecondaryAggroPlayer = 186,
		AggroLock = 187,
		ZoneBound = 188,
		ZoneBoundX = 189,
		ZoneBoundY = 190,
		ZoneBoundZ = 191,
		PctMercAAExp = 192,
		MercAAExp = 193,
		Subscription = 194,
		AAPointsAssigned = 195,
		AltCurrency = 196,
		ActiveDisc = 197,
		Commemoratives = 198,
		Nobles = 199,
		Zoning = 200,
		InInstance = 201,
		Instance = 202,
		MercListInfo = 203,
		UseAdvancedLooting = 204,
		Fists = 205,
		EnergyCrystals = 206,
		PiecesofEight = 207,
		SpellInCooldown = 208,
		Slowed = 209,
		Rooted = 210,
		Mezzed = 211,
		Crippled = 212,
		Maloed = 213,
		Tashed = 214,
		Snared = 215,
		Hasted = 216,
		Aego = 217,
		Skin = 218,
		Focus = 219,
		Regen = 220,
		Symbol = 221,
		Clarity = 222,
		Pred = 223,
		Strength = 224,
		Brells = 225,
		SV = 226,
		SE = 227,
		HybridHP = 228,
		Growth = 229,
		Shining = 230,
		Beneficial = 231,
		DSed = 232,
		RevDSed = 233,
		Charmed = 234,
		CursorPlatinum = 235,
		CursorGold = 236,
		CursorSilver = 237,
		CursorCopper = 238,
		Diseased = 239,
		Poisoned = 240,
		Cursed = 241,
		Corrupted = 242,
		Krono = 243,
		XTargetSlots = 244,
		AssistComplete = 245,
		ItemReady = 246,
		NumGems = 247,
		Vitality = 248,
		PctVitality = 249,
		AAVitality = 250,
		PctAAVitality = 251,
		GuildID = 252,
		ExpansionFlags = 253,
		SPA = 254,
		BoundLocation = 255,
		SkillBase = 256,
		Name = 257,
		AutoSkill = 258,
		CursorKrono = 259,
		BardSongPlaying = 260,
		XTAggroCount = 261,
		MercAAPoints = 262,
		MercAAPointsSpent = 263,
		PctExpToAA = 264,
		XTHaterCount = 265,
		CountersDisease = 266,
		CountersPoison = 267,
		CountersCurse = 268,
		CountersCorruption = 269,
		Bandolier = 270,
		LCK = 271,
		Feared = 272,
		Silenced = 273,
		Invulnerable = 274,
		Dotted = 275,
		BlockedBuff = 276,
		BlockedPetBuff = 277,
		LastZoned = 278,
		Origin = 279,
		SubscriptionDays = 280,
		SilverTokens = 281,
		GoldTokens = 282,
		McKenzie = 283,
		Bayle = 284,
		Reclamation = 285,
		Brellium = 286,
		Motes = 287,
		RebellionChits = 288,
		DiamondCoins = 289,
		BronzeFiats = 290,
		Voucher = 291,
		VeliumShards = 292,
		CrystallizedFear = 293,
		ShadowStones = 294,
		DreadStones = 295,
		MarksOfValor = 296,
		MedalsOfHeroism = 297,
		RemnantOfTranquility = 298,
		BifurcatedCoin = 299,
		AdoptiveCoin = 300,
		SathirsTradeGems = 301,
		AncientSebilisianCoins = 302,
		BathezidTradeGems = 303,
		AncientDraconicCoin = 304,
		FetterredIfritCoins = 305,
		EntwinedDjinnCoins = 306,
		CrystallizedLuck = 307,
		Spell = 308,
	};

	enum CharacterMethods
	{
		Stand,
		Sit,
		Dismount,
		StopCast,
	};

	MQ2CharacterType() : MQ2Type("character")
	{
		TypeMember(Exp);
		TypeMember(Spawn);
		TypeMember(Dar);
		TypeMember(AAExp);
		TypeMember(AAPoints);
		TypeMember(CurrentHPs);
		TypeMember(MaxHPs);
		TypeMember(HPRegen);
		TypeMember(PctHPs);
		TypeMember(CurrentMana);
		TypeMember(MaxMana);
		TypeMember(ManaRegen);
		TypeMember(PctMana);
		TypeMember(Buff);
		TypeMember(Song);
		TypeMember(Book);
		TypeMember(Skill);
		TypeMember(Ability);
		TypeMember(Cash);
		TypeMember(CashBank);
		TypeMember(PlatinumShared);
		TypeMember(Grouped);
		TypeMember(HPBonus);
		TypeMember(ManaBonus);
		TypeMember(GukEarned);
		TypeMember(MMEarned);
		TypeMember(RujEarned);
		TypeMember(TakEarned);
		TypeMember(MirEarned);
		TypeMember(LDoNPoints);
		TypeMember(CurrentFavor);
		TypeMember(CareerFavor);
		TypeMember(Endurance);
		TypeMember(Inventory);
		TypeMember(Bank);
		TypeMember(Combat);
		TypeMember(FreeInventory);
		TypeMember(Gem);
		TypeMember(SpellReady);
		TypeMember(Drunk);
		TypeMember(STR);
		TypeMember(STA);
		TypeMember(CHA);
		TypeMember(DEX);
		TypeMember(INT);
		TypeMember(AGI);
		TypeMember(WIS);
		TypeMember(svMagic);
		TypeMember(svFire);
		TypeMember(svCold);
		TypeMember(svPoison);
		TypeMember(svDisease);
		TypeMember(Hunger);
		TypeMember(Thirst);
		TypeMember(BaseSTR);
		TypeMember(BaseSTA);
		TypeMember(BaseCHA);
		TypeMember(BaseDEX);
		TypeMember(BaseINT);
		TypeMember(BaseAGI);
		TypeMember(BaseWIS);
		TypeMember(PracticePoints);
		TypeMember(PctExp);
		TypeMember(PctAAExp);
		TypeMember(Moving);
		TypeMember(AbilityReady);
		TypeMember(PetBuff);
		TypeMember(Platinum);
		TypeMember(Gold);
		TypeMember(Silver);
		TypeMember(Copper);
		TypeMember(PlatinumBank);
		TypeMember(GoldBank);
		TypeMember(SilverBank);
		TypeMember(CopperBank);
		TypeMember(Stunned);
		TypeMember(RangedReady);
		TypeMember(AltTimerReady);
		TypeMember(MaxEndurance);
		TypeMember(PctEndurance);
		TypeMember(AltAbility);
		TypeMember(AltAbilityReady);
		TypeMember(AltAbilityTimer);
		TypeMember(CombatAbility);
		TypeMember(CombatAbilityTimer);
		TypeMember(LargestFreeInventory);
		TypeMember(TargetOfTarget);
		TypeMember(RaidAssistTarget);
		TypeMember(GroupAssistTarget);
		TypeMember(RaidMarkNPC);
		TypeMember(GroupMarkNPC);
		TypeMember(CountBuffs);
		TypeMember(LanguageSkill);
		TypeMember(EnduranceBonus);
		TypeMember(CombatEffectsBonus);
		TypeMember(ShieldingBonus);
		TypeMember(SpellShieldBonus);
		TypeMember(AvoidanceBonus);
		TypeMember(AccuracyBonus);
		TypeMember(StunResistBonus);
		TypeMember(StrikeThroughBonus);
		TypeMember(AttackBonus);
		TypeMember(HPRegenBonus);
		TypeMember(ManaRegenBonus);
		TypeMember(DamageShieldBonus);
		TypeMember(DoTShieldBonus);
		TypeMember(AttackSpeed);
		TypeMember(GroupList);
		TypeMember(AmIGroupLeader);
		TypeMember(CurrentEndurance);
		TypeMember(EnduranceRegen);
		TypeMember(FreeBuffSlots);
		TypeMember(CurrentWeight);
		TypeMember(AAPointsSpent);
		TypeMember(AAPointsTotal);
		TypeMember(TributeActive);
		TypeMember(CombatAbilityReady);
		TypeMember(Running);
		TypeMember(GroupSize);
		TypeMember(TributeTimer);
		TypeMember(RadiantCrystals);
		TypeMember(EbonCrystals);
		TypeMember(Shrouded);
		TypeMember(AutoFire);
		TypeMember(Language);
		TypeMember(Aura);
		TypeMember(LAMarkNPC);
		TypeMember(LANPCHealth);
		TypeMember(LADelegateMA);
		TypeMember(LADelegateMarkNPC);
		TypeMember(LAInspectBuffs);
		TypeMember(LASpellAwareness);
		TypeMember(LAOffenseEnhancement);
		TypeMember(LAManaEnhancement);
		TypeMember(LAHealthEnhancement);
		TypeMember(LAHealthRegen);
		TypeMember(LAFindPathPC);
		TypeMember(LAHoTT);
		TypeMember(ActiveFavorCost);
		TypeMember(CombatState);
		TypeMember(svCorruption);
		TypeMember(svPrismatic);
		TypeMember(svChromatic);
		TypeMember(Doubloons);
		TypeMember(Orux);
		TypeMember(Phosphenes);
		TypeMember(Phosphites);
		TypeMember(Fellowship);
		TypeMember(Downtime);
		TypeMember(DamageShieldMitigationBonus);
		TypeMember(HeroicSTRBonus);
		TypeMember(HeroicINTBonus);
		TypeMember(HeroicWISBonus);
		TypeMember(HeroicAGIBonus);
		TypeMember(HeroicDEXBonus);
		TypeMember(HeroicSTABonus);
		TypeMember(HeroicCHABonus);
		TypeMember(HealAmountBonus);
		TypeMember(SpellDamageBonus);
		TypeMember(ClairvoyanceBonus);
		TypeMember(EnduranceRegenBonus);
		TypeMember(TotalCounters);
		TypeMember(Faycites);
		TypeMember(Chronobines);
		TypeMember(Mercenary);
		TypeMember(XTarget);
		TypeMember(Haste);
		TypeMember(MercenaryStance);
		TypeMember(SkillCap);
		TypeMember(GemTimer);
		TypeMember(HaveExpansion);
		TypeMember(PctAggro);
		TypeMember(SecondaryPctAggro);
		TypeMember(SecondaryAggroPlayer);
		TypeMember(AggroLock);
		TypeMember(ZoneBound);
		TypeMember(ZoneBoundX);
		TypeMember(ZoneBoundY);
		TypeMember(ZoneBoundZ);
		TypeMember(PctMercAAExp);
		TypeMember(MercAAExp);
		TypeMember(Subscription);
		TypeMember(AAPointsAssigned);
		TypeMember(AltCurrency);
		TypeMember(ActiveDisc);
		TypeMember(CountSongs);
		TypeMember(MaxBuffSlots);
		TypeMember(Commemoratives);
		TypeMember(Nobles);
		TypeMember(Zoning);
		TypeMember(InInstance);
		TypeMember(Instance);
		TypeMember(MercListInfo);
		TypeMember(UseAdvancedLooting);
		TypeMember(Fists);
		TypeMember(EnergyCrystals);
		TypeMember(PiecesofEight);
		TypeMember(SilverTokens);
		TypeMember(GoldTokens);
		TypeMember(McKenzie);
		TypeMember(Bayle);
		TypeMember(Reclamation);
		TypeMember(Brellium);
		TypeMember(Motes);
		TypeMember(RebellionChits);
		TypeMember(DiamondCoins);
		TypeMember(BronzeFiats);
		TypeMember(Voucher);
		TypeMember(VeliumShards);
		TypeMember(CrystallizedFear);
		TypeMember(ShadowStones);
		TypeMember(DreadStones);
		TypeMember(MarksOfValor);
		TypeMember(MedalsOfHeroism);
		TypeMember(RemnantOfTranquility);
		TypeMember(BifurcatedCoin);
		TypeMember(AdoptiveCoin);
		TypeMember(SathirsTradeGems);
		TypeMember(AncientSebilisianCoins);
		TypeMember(BathezidTradeGems);
		TypeMember(AncientDraconicCoin);
		TypeMember(FetterredIfritCoins);
		TypeMember(EntwinedDjinnCoins);
		TypeMember(CrystallizedLuck);
		TypeMember(SpellInCooldown);
		TypeMember(Slowed);
		TypeMember(Rooted);
		TypeMember(Mezzed);
		TypeMember(Crippled);
		TypeMember(Maloed);
		TypeMember(Tashed);
		TypeMember(Snared);
		TypeMember(Hasted);
		TypeMember(Aego);
		TypeMember(Skin);
		TypeMember(Focus);
		TypeMember(Regen);
		TypeMember(Symbol);
		TypeMember(Clarity);
		TypeMember(Pred);
		TypeMember(Strength);
		TypeMember(Brells);
		TypeMember(SV);
		TypeMember(SE);
		TypeMember(HybridHP);
		TypeMember(Growth);
		TypeMember(Shining);
		TypeMember(Beneficial);
		TypeMember(DSed);
		TypeMember(RevDSed);
		TypeMember(Charmed);
		TypeMember(CursorPlatinum);
		TypeMember(CursorGold);
		TypeMember(CursorSilver);
		TypeMember(CursorCopper);
		TypeMember(Diseased);
		TypeMember(Poisoned);
		TypeMember(Cursed);
		TypeMember(Corrupted);
		TypeMember(Krono);
		TypeMember(XTargetSlots);
		TypeMember(AssistComplete);
		TypeMember(ItemReady);
		TypeMember(NumGems);
		TypeMember(Vitality);
		TypeMember(PctVitality);
		TypeMember(AAVitality);
		TypeMember(PctAAVitality);
		TypeMember(GuildID);
		TypeMember(ExpansionFlags);
		TypeMember(SPA);
		TypeMember(BoundLocation);
		TypeMember(SkillBase);
		TypeMember(Name);
		TypeMember(AutoSkill);
		TypeMember(CursorKrono);
		TypeMember(BardSongPlaying);
		TypeMember(XTAggroCount);
		TypeMember(MercAAPoints);
		TypeMember(MercAAPointsSpent);
		TypeMember(PctExpToAA);
		TypeMember(XTHaterCount);
		TypeMember(CountersDisease);
		TypeMember(CountersPoison);
		TypeMember(CountersCurse);
		TypeMember(CountersCorruption);
		TypeMember(Bandolier);
		TypeMember(LCK);
		TypeMember(Feared);
		TypeMember(Silenced);
		TypeMember(Invulnerable);
		TypeMember(Dotted);
		TypeMember(BlockedBuff);
		TypeMember(BlockedPetBuff);
		TypeMember(LastZoned);
		TypeMember(Origin);
		TypeMember(SubscriptionDays);
		TypeMember(Spell);

		TypeMethod(Stand);
		TypeMethod(Sit);
		TypeMethod(Dismount);
		TypeMethod(StopCast);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (!pLocalPlayer)
			return false;

		CHARINFO* pCharInfo = static_cast<CHARINFO*>(VarPtr.Ptr);
		strcpy_s(Destination, MAX_STRING, pCharInfo->Name);
		return true;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate a CHARINFO
		VarPtr.Ptr = new CHARINFO();
		VarPtr.HighPart = 0;

		// FIXME: Do not ZeroMemory a CHARINFO
		ZeroMemory(VarPtr.Ptr, sizeof(CHARINFO));
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Remove need to allocate a CHARINFO
		CHARINFO* pCharInfo = static_cast<CHARINFO*>(VarPtr.Ptr);
		delete pCharInfo;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pCharacterType)
			return false;

		// TODO: Find way to remove this.
		memcpy(VarPtr.Ptr, Source.Ptr, sizeof(CHARINFO));
		return true;
	}
};

//============================================================================
// MQ2SpellType

class MQ2SpellType : public MQ2Type
{
public:
	enum SpellMembers
	{
		ID = 1,
		Name = 2,
		Level = 3,
		Skill = 4,
		Mana = 5,
		ResistAdj = 6,
		Range = 7,
		AERange = 8,
		PushBack = 9,
		CastTime = 10,
		FizzleTime = 11,
		MyCastTime = 12,
		RecoveryTime = 13,
		RecastTime = 14,
		Duration = 15,
		SpellType = 16,
		TargetType = 17,
		ResistType = 18,
		CastOnYou = 19,
		CastOnAnother = 20,
		WearOff = 21,
		CounterType = 22,
		CounterNumber = 23,
		Stacks = 24,
		StacksPet = 25,
		WillStack = 26,
		MyRange = 27,
		Address = 28,
		EnduranceCost = 29,
		MaxLevel = 30,
		Category = 31,
		Subcategory = 32,
		Restrictions = 33,
		Base = 34,
		Base2 = 35,
		Max = 36,
		Calc = 37,
		Attrib = 38,
		AutoCast = 39,
		Extra = 40,
		RecastTimerID = 41,
		SPA = 42,
		ReagentID = 43,
		ReagentCount = 44,
		CastByOther = 45,
		TimeOfDay = 46,
		DurationWindow = 47,
		CanMGB = 48,
		Deletable = 49,
		BookIcon = 50,
		Target = 51,
		Description = 52,
		StacksWith = 53,
		Caster = 54,
		Rank = 55,
		RankName = 56,
		SpellGroup = 57,
		SubSpellGroup = 58,
		Beneficial = 59,
		xIsActiveAA = 60,
		CalcIndex = 61,
		NumEffects = 62,
		Location = 63,
		IsSwarmSpell = 64,
		IsSkill = 65,
		DurationValue1 = 66,
		NewStacks = 67,
		NewStacksWith = 68,
		StacksTarget = 69,
		StacksWithDiscs = 70,
		IllusionOkWhenMounted = 71,
		EQSpellDuration = 72,
		CastByMe = 73,
		HasSPA = 74,
		Trigger = 75,
		BaseName = 76,
		NoExpendReagentID = 77,
		StacksSpawn = 78,
		SpellIcon = 79,
		GemIcon = 80,
		SlowPct = 81,
		HastePct = 82,
	};

	enum SpellMethods
	{
	};

	MQ2SpellType() : MQ2Type("spell")
	{
		TypeMember(ID);
		TypeMember(Name);
		TypeMember(Level);
		TypeMember(Skill);
		TypeMember(Mana);
		TypeMember(ResistAdj);
		TypeMember(Range);
		TypeMember(AERange);
		TypeMember(PushBack);
		TypeMember(CastTime);
		TypeMember(FizzleTime);
		TypeMember(MyCastTime);
		TypeMember(RecoveryTime);
		TypeMember(RecastTime);
		TypeMember(Duration);
		TypeMember(SpellType);
		TypeMember(TargetType);
		TypeMember(ResistType);
		TypeMember(CastOnYou);
		TypeMember(CastOnAnother);
		TypeMember(WearOff);
		TypeMember(CounterType);
		TypeMember(CounterNumber);
		TypeMember(Stacks);
		TypeMember(StacksPet);
		TypeMember(WillStack);
		TypeMember(MyRange);
		TypeMember(Address);
		TypeMember(EnduranceCost);
		TypeMember(MaxLevel);
		TypeMember(Category);
		TypeMember(Subcategory);
		TypeMember(Restrictions);
		TypeMember(Base);
		TypeMember(Base2);
		TypeMember(Max);
		TypeMember(Calc);
		TypeMember(Attrib);
		TypeMember(AutoCast);
		TypeMember(Extra);
		TypeMember(RecastTimerID);
		TypeMember(SPA);
		TypeMember(ReagentID);
		TypeMember(ReagentCount);
		TypeMember(CastByOther);
		TypeMember(TimeOfDay);
		TypeMember(DurationWindow);
		TypeMember(CanMGB);
		TypeMember(Deletable);
		TypeMember(BookIcon);
		TypeMember(Target);
		TypeMember(Description);
		TypeMember(StacksWith);
		TypeMember(Caster);
		TypeMember(Rank);
		TypeMember(RankName);
		TypeMember(SpellGroup);
		TypeMember(SubSpellGroup);
		TypeMember(Beneficial);
		AddMember(xIsActiveAA, "IsActiveAA");
		TypeMember(CalcIndex);
		TypeMember(NumEffects);
		TypeMember(Location);
		TypeMember(IsSwarmSpell);
		TypeMember(IsSkill);
		TypeMember(DurationValue1);
		TypeMember(NewStacks);
		TypeMember(NewStacksWith);
		TypeMember(StacksTarget);
		TypeMember(StacksWithDiscs);
		TypeMember(IllusionOkWhenMounted);
		TypeMember(EQSpellDuration);
		TypeMember(CastByMe);
		TypeMember(HasSPA);
		TypeMember(Trigger);
		TypeMember(BaseName);
		TypeMember(NoExpendReagentID);
		TypeMember(StacksSpawn);
		TypeMember(SpellIcon);
		TypeMember(GemIcon);
		TypeMember(SlowPct);
		TypeMember(HastePct);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (!VarPtr.Ptr)
			return false;

		SPELL* pSpell = static_cast<SPELL*>(VarPtr.Ptr);
		strcpy_s(Destination, MAX_STRING, pSpell->Name);
		return true;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate a SPELL
		VarPtr.Ptr = new SPELL();
		VarPtr.HighPart = 0;
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate a SPELL
		SPELL* pSpell = static_cast<SPELL*>(VarPtr.Ptr);
		delete pSpell;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pSpellType)
			return false;

		memcpy(VarPtr.Ptr, Source.Ptr, sizeof(SPELL));
		return true;
	}
};

//============================================================================
// MQ2BuffType

class MQ2BuffType : public MQ2Type
{
public:
	enum BuffMembers
	{
		Address = 1,
		ID = 2,
		Level = 3,
		Spell = 4,
		Mod = 5,
		Duration = 6,
		Dar = 7,
		TotalCounters = 8,
		HitCount = 9,
		CountersDisease = 10,
		CountersPoison = 11,
		CountersCurse = 12,
		CountersCorruption = 13,
	};

	enum BuffMethods
	{
		Remove = 1,
	};

	MQ2BuffType() : MQ2Type("buff")
	{
		TypeMember(Address);
		TypeMember(ID);
		TypeMember(Level);
		TypeMember(Spell);
		TypeMember(Mod);
		TypeMember(Duration);
		TypeMember(Dar);
		TypeMember(TotalCounters);
		TypeMember(HitCount);
		TypeMember(CountersDisease);
		TypeMember(CountersPoison);
		TypeMember(CountersCurse);
		TypeMember(CountersCorruption);

		TypeMethod(Remove);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (!VarPtr.Ptr)
			return false;

		SPELLBUFF* pSpellBuff = static_cast<SPELLBUFF*>(VarPtr.Ptr);

		if (pSpellBuff->SpellID > 0)
		{
			if (SPELL* pSpell = GetSpellByID(pSpellBuff->SpellID))
			{
				strcpy_s(Destination, MAX_STRING, pSpell->Name);
				return true;
			}
		}
		return false;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate a SPELLBUFF
		VarPtr.Ptr = new SPELLBUFF();
		VarPtr.HighPart = 0;
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate a SPELLBUFF
		SPELLBUFF* pSpellBuff = static_cast<SPELLBUFF*>(VarPtr.Ptr);
		delete pSpellBuff;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pBuffType)
			return false;

		memcpy(VarPtr.Ptr, Source.Ptr, sizeof(SPELLBUFF));
		return true;
	}
};

//============================================================================
// MQ2TargetBuffType

class MQ2TargetBuffType : public MQ2Type
{
public:
	enum TargetBuffMembers
	{
		Address = 1,
		xIndex = 2,
		Duration = 3,
	};

	MQ2TargetBuffType() : MQ2Type("targetbuff")
	{
		TypeMember(Address);
		AddMember(xIndex, "Index");
		TypeMember(Duration);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (VarPtr.Int == -1)
			return false;

		int buffid = pTargetWnd->BuffSpellID[VarPtr.Int];
		if (buffid > 0)
		{
			if (PSPELL pSpell = GetSpellByID(buffid))
			{
				strcpy_s(Destination, MAX_STRING, pSpell->Name);
				return true;
			}
		}

		return false;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.Int = Source.Int;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.Int = GetIntFromString(Source, 0);
		return true;
	}
};

//============================================================================
// MQ2CachedBuffType

class MQ2CachedBuffType : public MQ2Type
{
public:
	enum CachedBuffMembers
	{
		CasterName = 1,
		Count = 2,
		Slot = 3,
		SpellID = 4,
		Duration = 5,
	};

	MQ2CachedBuffType() : MQ2Type("cachedbuff")
	{
		TypeMember(CasterName);
		TypeMember(Count);
		TypeMember(Slot);
		TypeMember(SpellID);
		TypeMember(Duration);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		TargetBuff* pcTB = (TargetBuff*)VarPtr.Ptr;
		if (!pcTB)
			return false;
		if (PSPELL pSpell = GetSpellByID(pcTB->spellId))
		{
			strcpy_s(Destination, MAX_STRING, pSpell->Name);
			return true;
		}
		return false;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.Ptr = Source.Ptr;
		return true;
	}
};

//============================================================================
// MQ2ItemSpellType

class MQ2ItemSpellType : public MQ2Type
{
public:
	enum ItemSpellMembers
	{
		SpellID = 1,
		RequiredLevel = 2,
		EffectType = 3,
		EffectiveCasterLevel = 4,
		MaxCharges = 5,
		CastTime = 6,
		TimerID = 7,
		RecastType = 8,
		ProcRate = 9,
		OtherName = 10,
		OtherID = 11,
		Spell = 12,
	};

	MQ2ItemSpellType() : MQ2Type("itemspell")
	{
		TypeMember(SpellID);
		TypeMember(RequiredLevel);
		TypeMember(EffectType);
		TypeMember(EffectiveCasterLevel);
		TypeMember(MaxCharges);
		TypeMember(CastTime);
		TypeMember(TimerID);
		TypeMember(RecastType);
		TypeMember(ProcRate);
		TypeMember(OtherName);
		TypeMember(OtherID);
		TypeMember(Spell);
	};

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (!VarPtr.Ptr)
			return false;

		ITEMSPELLS* pItemSpells = static_cast<ITEMSPELLS*>(VarPtr.Ptr);
		if (int spellid = pItemSpells->SpellID)
		{
			if (SPELL* pSpell = GetSpellByID(spellid))
			{
				strcpy_s(Destination, MAX_STRING, pSpell->Name);
				return true;
			}
		}
		return false;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate an ITEMSPELLS
		VarPtr.Ptr = new ITEMSPELLS();
		VarPtr.HighPart = 0;
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate an ITEMSPELLS
		ITEMSPELLS* pItemSpells = static_cast<ITEMSPELLS*>(VarPtr.Ptr);
		delete pItemSpells;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pItemSpellType)
			return false;

		memcpy(VarPtr.Ptr, Source.Ptr, sizeof(ITEMSPELLS));
		return true;
	}
};

//============================================================================
// MQ2ItemType

class MQ2ItemType : public MQ2Type
{
public:
	enum ItemMembers
	{
		ID = 1,
		Name = 2,
		Lore = 3,
		NoDrop = 4,
		NoRent = 5,
		Magic = 6,
		Value = 7,
		Size = 8,
		Weight = 9,
		Stack = 10,
		Type = 11,
		Charges = 12,
		LDoNTheme = 13,
		DMGBonusType = 14,
		BuyPrice = 15,
		Haste = 16,
		Endurance = 17,
		Attack = 18,
		HPRegen = 19,
		ManaRegen = 20,
		DamShield = 21,
		WeightReduction = 22,
		SizeCapacity = 23,
		Combinable = 24,
		Skill = 25,
		Avoidance = 26,
		SpellShield = 27,
		StrikeThrough = 28,
		StunResist = 29,
		Shielding = 30,
		FocusID = 31,
		ProcRate = 32,
		Quality = 33,
		LDoNCost = 34,
		AugRestrictions = 35,
		AugType = 36,
		AugSlot1 = 37,
		AugSlot2 = 38,
		AugSlot3 = 39,
		AugSlot4 = 40,
		AugSlot5 = 41,
		AugSlot6 = 42,
		Damage = 43,
		Range = 44,
		DMGBonus = 45,
		RecommendedLevel = 46,
		RecommendedSkill = 47,
		Delay = 48,
		Light = 49,
		Level = 50,
		BaneDMG = 51,
		SkillModValue = 52,
		InstrumentType = 53,
		InstrumentMod = 54,
		RequiredLevel = 55,
		BaneDMGType = 56,
		AC = 57,
		HP = 58,
		Mana = 59,
		STR = 60,
		STA = 61,
		AGI = 62,
		DEX = 63,
		CHA = 64,
		INT = 65,
		WIS = 66,
		svCold = 67,
		svFire = 68,
		svMagic = 69,
		svDisease = 70,
		svPoison = 71,
		Summoned = 72,
		Artifact = 73,
		PendingLore = 74,
		LoreText = 75,
		Items = 76,
		Item = 77,
		Container = 78,
		Stackable = 79,
		InvSlot = 80,
		SellPrice = 81,
		WornSlot = 82,
		WornSlots = 83,
		CastTime = 84,
		Spell = 85,
		EffectType = 86,
		Tribute = 87,
		Attuneable = 88,
		Timer = 89,
		ItemDelay = 90,
		TimerReady = 91,
		StackSize = 92,
		Stacks = 93,
		StackCount = 94,
		FreeStack = 95,
		MerchQuantity = 96,
		Classes = 97,
		Class = 98,
		Races = 99,
		Race = 100,
		Deities = 101,
		Deity = 102,
		Evolving = 103,
		svCorruption = 104,
		Power = 105,
		MaxPower = 106,
		Purity = 107,
		Accuracy = 108,
		CombatEffects = 109,
		DoTShielding = 110,
		HeroicSTR = 111,
		HeroicINT = 112,
		HeroicWIS = 113,
		HeroicAGI = 114,
		HeroicDEX = 115,
		HeroicSTA = 116,
		HeroicCHA = 117,
		HeroicSvMagic = 118,
		HeroicSvFire = 119,
		HeroicSvCold = 120,
		HeroicSvDisease = 121,
		HeroicSvPoison = 122,
		HeroicSvCorruption = 123,
		EnduranceRegen = 124,
		HealAmount = 125,
		Clairvoyance = 126,
		DamageShieldMitigation = 127,
		SpellDamage = 128,
		Augs = 129,
		Tradeskills = 130,
		ItemSlot = 131,
		ItemSlot2 = 132,
		Address = 133,
		PctPower = 134,
		Prestige = 135,
		FirstFreeSlot = 136,
		SlotsUsedByItem = 137,
		Heirloom = 138,
		Collectible = 139,
		NoDestroy = 140,
		Quest = 141,
		Expendable = 142,
		ContAddress = 143,
		ItemLink = 144,
		Icon = 145,
		SkillModMax = 146,
		OrnamentationIcon = 147,
		ContentSize = 148,
		Open = 149,
		NoTrade = 150,
		AugSlot = 151,
		Clicky = 152,
		Proc = 153,
		Worn = 154,
		Focus = 155,
		Scroll = 156,
		Focus2 = 157,
		Mount = 158,
		Illusion = 159,
		Familiar = 160,
		CanUse = 161,
		LoreEquipped = 162,
		Luck = 163,
		MinLuck = 164,
		MaxLuck = 165,
	};

	enum ItemMethods
	{
	};

	MQ2ItemType() : MQ2Type("item")
	{
		TypeMember(ID);
		TypeMember(Name);
		TypeMember(Lore);
		TypeMember(NoDrop);
		TypeMember(NoRent);
		TypeMember(Magic);
		TypeMember(Value);
		TypeMember(Size);
		TypeMember(Weight);
		TypeMember(Stack);
		TypeMember(Type);
		TypeMember(Charges);
		TypeMember(LDoNTheme);
		TypeMember(DMGBonusType);
		TypeMember(BuyPrice);
		TypeMember(Haste);
		TypeMember(Endurance);
		TypeMember(Attack);
		TypeMember(HPRegen);
		TypeMember(ManaRegen);
		TypeMember(DamShield);
		TypeMember(WeightReduction);
		TypeMember(SizeCapacity);
		TypeMember(Combinable);
		TypeMember(Skill);
		TypeMember(Avoidance);
		TypeMember(SpellShield);
		TypeMember(StrikeThrough);
		TypeMember(StunResist);
		TypeMember(Shielding);
		TypeMember(FocusID);
		TypeMember(ProcRate);
		TypeMember(Quality);
		TypeMember(LDoNCost);
		TypeMember(AugRestrictions);
		TypeMember(AugType);
		TypeMember(AugSlot1);
		TypeMember(AugSlot2);
		TypeMember(AugSlot3);
		TypeMember(AugSlot4);
		TypeMember(AugSlot5);
		TypeMember(AugSlot6);
		TypeMember(Damage);
		TypeMember(Range);
		TypeMember(DMGBonus);
		TypeMember(RecommendedLevel);
		TypeMember(RecommendedSkill);
		TypeMember(Delay);
		TypeMember(Light);
		TypeMember(Level);
		TypeMember(BaneDMG);
		TypeMember(SkillModValue);
		TypeMember(InstrumentType);
		TypeMember(InstrumentMod);
		TypeMember(RequiredLevel);
		TypeMember(BaneDMGType);
		TypeMember(AC);
		TypeMember(HP);
		TypeMember(Mana);
		TypeMember(STR);
		TypeMember(STA);
		TypeMember(AGI);
		TypeMember(DEX);
		TypeMember(CHA);
		TypeMember(INT);
		TypeMember(WIS);
		TypeMember(svCold);
		TypeMember(svFire);
		TypeMember(svMagic);
		TypeMember(svDisease);
		TypeMember(svPoison);
		TypeMember(Summoned);
		TypeMember(Artifact);
		TypeMember(PendingLore);
		TypeMember(LoreText);
		TypeMember(Items);
		TypeMember(Item);
		TypeMember(Container);
		TypeMember(Stackable);
		TypeMember(InvSlot);
		TypeMember(SellPrice);
		TypeMember(WornSlot);
		TypeMember(WornSlots);
		TypeMember(CastTime);
		TypeMember(Spell);
		TypeMember(EffectType);
		TypeMember(Tribute);
		TypeMember(Attuneable);
		TypeMember(Timer);
		TypeMember(ItemDelay);
		TypeMember(TimerReady);
		TypeMember(StackSize);
		TypeMember(Stacks);
		TypeMember(StackCount);
		TypeMember(FreeStack);
		TypeMember(MerchQuantity);
		TypeMember(Classes);
		TypeMember(Class);
		TypeMember(Races);
		TypeMember(Race);
		TypeMember(Deities);
		TypeMember(Deity);
		TypeMember(Evolving);
		TypeMember(svCorruption);
		TypeMember(Power);
		TypeMember(MaxPower);
		TypeMember(Purity);
		TypeMember(Accuracy);
		TypeMember(CombatEffects);
		TypeMember(DoTShielding);
		TypeMember(HeroicSTR);
		TypeMember(HeroicINT);
		TypeMember(HeroicWIS);
		TypeMember(HeroicAGI);
		TypeMember(HeroicDEX);
		TypeMember(HeroicSTA);
		TypeMember(HeroicCHA);
		TypeMember(HeroicSvMagic);
		TypeMember(HeroicSvFire);
		TypeMember(HeroicSvCold);
		TypeMember(HeroicSvDisease);
		TypeMember(HeroicSvPoison);
		TypeMember(HeroicSvCorruption);
		TypeMember(EnduranceRegen);
		TypeMember(HealAmount);
		TypeMember(Clairvoyance);
		TypeMember(DamageShieldMitigation);
		TypeMember(SpellDamage);
		TypeMember(Augs);
		TypeMember(Tradeskills);
		TypeMember(ItemSlot);
		TypeMember(ItemSlot2);
		TypeMember(Address);
		TypeMember(PctPower);
		TypeMember(Prestige);
		TypeMember(FirstFreeSlot);
		TypeMember(SlotsUsedByItem);
		TypeMember(Heirloom);
		TypeMember(Collectible);
		TypeMember(NoDestroy);
		TypeMember(Quest);
		TypeMember(Expendable);
		TypeMember(ContAddress);
		TypeMember(ItemLink);
		TypeMember(Icon);
		TypeMember(SkillModMax);
		TypeMember(OrnamentationIcon);
		TypeMember(ContentSize);
		TypeMember(Open);
		TypeMember(NoTrade);
		TypeMember(AugSlot);
		TypeMember(Clicky);
		TypeMember(Proc);
		TypeMember(Worn);
		TypeMember(Focus);
		TypeMember(Scroll);
		TypeMember(Focus2);
		TypeMember(Mount);
		TypeMember(Illusion);
		TypeMember(Familiar);
		TypeMember(CanUse);
		TypeMember(LoreEquipped);
		TypeMember(Luck);
		TypeMember(MinLuck);
		TypeMember(MaxLuck);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	void InitVariable(MQVarPtr& VarPtr) override
	{
		CONTENTS* pContents = eqNew<CONTENTS>();
		pContents->IncrementRefCount();

		VarPtr.Ptr = pContents;
		VarPtr.HighPart = 0;
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		CONTENTS* pContents = static_cast<CONTENTS*>(VarPtr.Ptr);
		pContents->DecrementRefCount();
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pItemType)
			return false;

		CONTENTS* pNewContents = static_cast<CONTENTS*>(Source.Ptr);
		if (pNewContents)
			pNewContents->IncrementRefCount();

		CONTENTS* pOldContents = static_cast<CONTENTS*>(VarPtr.Ptr);
		if (pOldContents)
			pOldContents->DecrementRefCount();

		VarPtr.Ptr = pNewContents;
		return true;
	}
};

//============================================================================
// MQ2SwitchType

class MQ2SwitchType : public MQ2Type
{
public:
	enum SwitchMembers
	{
		ID = 1,
		Distance = 2,
		X = 3,
		Y = 4,
		Z = 5,
		Heading = 6,
		DefaultX = 7,
		DefaultY = 8,
		DefaultZ = 9,
		DefaultHeading = 10,
		Open = 11,
		HeadingTo = 12,
		Name = 13,
		N = 14,
		W = 15,
		U = 16,
		DefaultN = 17,
		DefaultW = 18,
		DefaultU = 19,
		xLineOfSight = 20,
		Address = 21,
		Distance3D = 22,
	};

	enum SwitchMethods
	{
		Toggle = 1,
	};

	MQ2SwitchType() : MQ2Type("switch")
	{
		TypeMember(ID);
		TypeMember(Distance);
		TypeMember(X);
		TypeMember(Y);
		TypeMember(Z);
		TypeMember(Heading);
		TypeMember(DefaultX);
		TypeMember(DefaultY);
		TypeMember(DefaultZ);
		TypeMember(DefaultHeading);
		TypeMember(Open);
		TypeMember(HeadingTo);
		TypeMember(Name);
		AddMember(xLineOfSight, "LineOfSight");
		TypeMember(Address);
		TypeMember(Distance3D);

		TypeMethod(Toggle);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (!VarPtr.Ptr)
			return false;

		DOOR* pDoor = static_cast<DOOR*>(VarPtr.Ptr);
		_itoa_s(pDoor->ID, Destination, MAX_STRING, 10);
		return true;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate a DOOR
		VarPtr.Ptr = new DOOR();
		VarPtr.HighPart = 0;
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate a DOOR
		DOOR* pDoor = static_cast<DOOR*>(VarPtr.Ptr);
		delete pDoor;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pSwitchType)
			return false;

		memcpy(VarPtr.Ptr, Source.Ptr, sizeof(DOOR));
		return true;
	}
};

//============================================================================
// MQ2GroundType

class MQ2GroundType : public MQ2Type
{
public:
	enum GroundMembers
	{
		ID = 1,
		Distance = 2,
		X = 3,
		Y = 4,
		Z = 5,
		Heading = 6,
		Name = 7,
		HeadingTo = 8,
		N = 9,
		W = 10,
		U = 11,
		xLineOfSight = 12,
		Address = 13,
		DisplayName = 14,
		Distance3D = 15,
		SubID = 16,
		ZoneID = 17,
		First = 18,
		Last = 19,
		Next = 20,
		Prev = 21,
	};

	enum GroundMethods
	{
		Grab = 1,
		DoTarget = 2,
		DoFace = 3,
	};

	MQ2GroundType() : MQ2Type("ground")
	{
		TypeMember(ID);
		TypeMember(Distance);
		TypeMember(X);
		TypeMember(Y);
		TypeMember(Z);
		TypeMember(Heading);
		TypeMember(Name);
		TypeMember(HeadingTo);
		AddMember(xLineOfSight, "LineOfSight");
		TypeMember(Address);
		TypeMember(DisplayName);
		TypeMember(Distance3D);
		TypeMember(SubID);
		TypeMember(ZoneID);
		TypeMember(First);
		TypeMember(Last);
		TypeMember(Next);
		TypeMember(Prev);

		// methods
		TypeMethod(Grab);
		TypeMethod(DoTarget);
		TypeMethod(DoFace);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	void InitVariable(MQVarPtr& VarPtr) override
	{
		VarPtr.Ptr = new MQGroundObject();
		VarPtr.HighPart = 0;
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		MQGroundObject* pGroundObject = static_cast<MQGroundObject*>(VarPtr.Ptr);
		delete pGroundObject;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pGroundType)
			return false;

		memcpy(VarPtr.Ptr, Source.Ptr, sizeof(MQGroundObject));
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override;
};

//============================================================================
// MQ2CorpseType

class MQ2CorpseType : public MQ2Type
{
public:
	enum CorpseMembers
	{
		Open = 1,
		Item = 2,
		Items = 3,
	};

	enum CorpseMethods
	{
	};

	MQ2CorpseType() : MQ2Type("corpse")
	{
		TypeMember(Open);
		TypeMember(Item);
		TypeMember(Items);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (pActiveCorpse && pLootWnd)
		{
			strcpy_s(Destination, MAX_STRING, "TRUE");
		}
		else
		{
			strcpy_s(Destination, MAX_STRING, "FALSE");
		}
		return true;
	}
};

//============================================================================
// MQ2MerchantType

class MQ2MerchantType : public MQ2Type
{
public:
	enum MerchantMembers
	{
		Markup = 1,
		Item = 2,
		Items = 3,
		Open = 4,
		Full = 5,
		ItemsReceived = 6,
		SelectedItem = 7,
	};

	enum MerchantMethods
	{
		SelectItem = 1,
		Buy = 2,
		Sell = 3,
		OpenWindow = 4,
		CloseWindow = 5,
	};

	MQ2MerchantType() : MQ2Type("merchant")
	{
		TypeMember(Markup);
		TypeMember(Item);
		TypeMember(Items);
		TypeMember(Open);
		TypeMember(Full);
		TypeMember(ItemsReceived);
		TypeMember(SelectedItem);

		TypeMethod(SelectItem);
		TypeMethod(Buy);
		TypeMethod(Sell);
		TypeMethod(OpenWindow);
		TypeMethod(CloseWindow);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (pActiveMerchant && pMerchantWnd)
		{
			strcpy_s(Destination, MAX_STRING, "TRUE");
		}
		else
		{
			strcpy_s(Destination, MAX_STRING, "FALSE");
		}
		return true;
	}
};

//============================================================================
// MQ2PointMerchantItemType

class MQ2PointMerchantItemType : public MQ2Type
{
public:
	enum PointMerchantItemMembers
	{
		Name = 1,
		ItemID = 2,
		Price = 3,
		ThemeID = 4,
		IsStackable = 5,
		IsLore = 6,
		RaceMask = 7,
		ClassMask = 8,
		CanUse = 9,
	};

	enum PointMerchantMethods
	{
	};

	MQ2PointMerchantItemType() : MQ2Type("pointmerchantitem")
	{
		TypeMember(Name);
		TypeMember(ItemID);
		TypeMember(Price);
		TypeMember(ThemeID);
		TypeMember(IsStackable);
		TypeMember(IsLore);
		TypeMember(RaceMask);
		TypeMember(ClassMask);
		TypeMember(CanUse);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (pMerchantWnd)
		{
			int sz = pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer.GetSize();
			if (sz)
			{
				if (VarPtr.Int >= 0 && VarPtr.Int < sz)
				{
					strcpy_s(Destination, MAX_STRING,
						pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer[VarPtr.Int].pCont->Item2->Name);
					return true;
				}
			}
		}
		return false;
	}
};

//============================================================================
// MQ2PointMerchantType

class MQ2PointMerchantType : public MQ2Type
{
public:
	enum PointMerchantMembers
	{
		Item = 1,
	};

	enum PointMerchantMethods
	{
	};

	MQ2PointMerchantType() : MQ2Type("pointmerchant")
	{
		TypeMember(Item);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (pMerchantWnd && pMerchantWnd->IsVisible())
		{
			strcpy_s(Destination, MAX_STRING, "TRUE");
		}
		else
		{
			strcpy_s(Destination, MAX_STRING, "FALSE");
		}
		return true;
	}
};

//============================================================================
// MQ2MercenaryType

class MQ2MercenaryType : public MQ2Type
{
public:
	enum MercenaryMembers
	{
		AAPoints = 1,
		Stance = 2,
		State = 3,
		StateID = 4,
		xIndex = 5,
#ifdef MULETESTING
		CurrentHPs = 6,
		MaxHPs = 7,
		PctHPs = 8,
		CurrentMana = 9,
		MaxMana = 10,
		PctMana = 11,
		AC = 12,
		AGI = 13,
		Attack = 14,
		CHA = 15,
		CombatEnduranceRegen = 16,
		CombatHPRegen = 17,
		CurrentEndurance = 18,
		MaxEndurance = 19,
		PctEndurance = 20,
		DEX = 21,
		Haste = 22,
		HealAmount = 23,
		INT = 24,
		SpellDamage = 25,
		STA = 26,
		STR = 27,
		WIS = 28,
#endif
	};

	enum MercenaryMethods
	{
	};

	MQ2MercenaryType() : MQ2Type("mercenary")
	{
		TypeMember(AAPoints);
		TypeMember(Stance);
		TypeMember(State);
		TypeMember(StateID);
		AddMember(xIndex, "Index");
#ifdef MULETESTING
		TypeMember(CurrentHPs);
		TypeMember(MaxHPs);
		TypeMember(PctHPs);
		TypeMember(CurrentMana);
		TypeMember(MaxMana);
		TypeMember(PctMana);
		TypeMember(AC);
		TypeMember(AGI);
		TypeMember(Attack);
		TypeMember(CHA);
		TypeMember(CombatEnduranceRegen);
		TypeMember(CombatHPRegen);
		TypeMember(CurrentEndurance);
		TypeMember(MaxEndurance);
		TypeMember(PctEndurance);
		TypeMember(DEX);
		TypeMember(Haste);
		TypeMember(HealAmount);
		TypeMember(INT);
		TypeMember(SpellDamage);
		TypeMember(STA);
		TypeMember(STR);
		TypeMember(WIS);
#endif
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (!VarPtr.Ptr)
			return false;

		SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
		strcpy_s(Destination, MAX_STRING, pSpawn->Name);
		return true;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not Allocate a SPAWNINFO
		VarPtr.Ptr = new SPAWNINFO();
		VarPtr.HighPart = 0;

		// FIXME: Do not ZeroMemory a SPAWNINFO
		ZeroMemory(VarPtr.Ptr, sizeof(SPAWNINFO));
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not Allocate a SPAWNINFO
		SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
		delete pSpawn;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type == pSpawnType)
		{
			memcpy(VarPtr.Ptr, Source.Ptr, sizeof(SPAWNINFO));
			return true;
		}
		else
		{
			if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(Source.DWord))
			{
				memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
				return true;
			}
		}
		return false;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(GetIntFromString(Source, 0)))
		{
			memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
			return true;
		}
		return false;
	}
};

//============================================================================
// MQ2PetType

class MQ2PetType : public MQ2Type
{
public:
	enum PetMembers
	{
		Buff = 1,
		Combat = 2,
		GHold = 3,
		Hold = 4,
		ReGroup = 5,
		Stance = 6,
		Stop = 7,
		Target = 8,
		Taunt = 9,
		BuffDuration = 10,
	};

	enum PetMethods
	{
	};

	MQ2PetType() : MQ2Type("pet")
	{
		TypeMember(Buff);
		TypeMember(Combat);
		TypeMember(GHold);
		TypeMember(Hold);
		TypeMember(ReGroup);
		TypeMember(Stance);
		TypeMember(Stop);
		TypeMember(Target);
		TypeMember(Taunt);
		TypeMember(BuffDuration);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (!VarPtr.Ptr)
			return false;

		SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
		strcpy_s(Destination, MAX_STRING, pSpawn->Name);
		return true;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate a SPAWNINFO
		VarPtr.Ptr = new SPAWNINFO();
		VarPtr.HighPart = 0;

		// FIXME: Do not ZeroMemory a SPAWNINFO
		ZeroMemory(VarPtr.Ptr, sizeof(SPAWNINFO));
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate a SPAWNINFO
		SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
		delete pSpawn;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type == pSpawnType)
		{
			memcpy(VarPtr.Ptr, Source.Ptr, sizeof(SPAWNINFO));
			return true;
		}
		else
		{
			if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(Source.DWord))
			{
				memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
				return true;
			}
		}
		return false;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(GetIntFromString(Source, 0)))
		{
			memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
			return true;
		}
		return false;
	}
};

//============================================================================
// MQ2WindowType

class MQ2WindowType : public MQ2Type
{
public:
	enum WindowMembers
	{
		Open = 1,
		Child = 2,
		VScrollMax = 3,
		VScrollPos = 4,
		VScrollPct = 5,
		HScrollMax = 6,
		HScrollPos = 7,
		HScrollPct = 8,
		Children = 9,
		Siblings = 10,
		Parent = 11,
		FirstChild = 12,
		Next = 13,
		Minimized = 14,
		X = 15,
		Y = 16,
		Height = 17,
		Width = 18,
		MouseOver = 19,
		BGColor = 20,
		Text = 21,
		Tooltip = 22,
		List = 23,
		Checked = 24,
		Style = 25,
		Enabled = 26,
		Highlighted = 27,
		Name = 28,
		ScreenID = 29,
		Type = 30,
		Items = 31,
		HisTradeReady = 32,
		MyTradeReady = 33,
		GetCurSel = 34,
		Address = 35,
	};

	enum WindowMethods
	{
		LeftMouseDown = 1,
		LeftMouseUp = 2,
		LeftMouseHeld = 3,
		LeftMouseHeldUp = 4,
		RightMouseDown = 5,
		RightMouseUp = 6,
		RightMouseHeld = 7,
		RightMouseHeldUp = 8,
		DoOpen = 9,
		DoClose = 10,
		Select = 11,
	};

	MQ2WindowType() : MQ2Type("window")
	{
		TypeMember(Open);
		TypeMember(Child);
		TypeMember(VScrollMax);
		TypeMember(VScrollPos);
		TypeMember(VScrollPct);
		TypeMember(HScrollMax);
		TypeMember(HScrollPos);
		TypeMember(HScrollPct);
		TypeMember(Children);
		TypeMember(Parent);
		TypeMember(Siblings);
		TypeMember(FirstChild);
		TypeMember(Next);
		TypeMember(Minimized);
		TypeMember(X);
		TypeMember(Y);
		TypeMember(Height);
		TypeMember(Width);
		TypeMember(MouseOver);
		TypeMember(BGColor);
		TypeMember(Text);
		TypeMember(Tooltip);
		TypeMember(List);
		TypeMember(Checked);
		TypeMember(Style);
		TypeMember(Enabled);
		TypeMember(Highlighted);
		TypeMember(Name);
		TypeMember(ScreenID);
		TypeMember(Type);
		TypeMember(Items);
		TypeMember(HisTradeReady);
		TypeMember(MyTradeReady);
		TypeMember(GetCurSel);
		TypeMember(Address);

		TypeMethod(LeftMouseDown);
		TypeMethod(LeftMouseUp);
		TypeMethod(LeftMouseHeld);
		TypeMethod(LeftMouseHeldUp);
		TypeMethod(RightMouseDown);
		TypeMethod(RightMouseUp);
		TypeMethod(RightMouseHeld);
		TypeMethod(RightMouseHeldUp);
		TypeMethod(DoOpen);
		TypeMethod(DoClose);
		TypeMethod(Select);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		CXWnd* pWnd = static_cast<CXWnd*>(VarPtr.Ptr);

		if (pWnd)
		{
			if (VarPtr.HighPart == 24) // ???
			{
				if (CXMLData* pXMLData = pWnd->GetXMLData())
				{
					strcpy_s(Destination, MAX_STRING, pXMLData->Name.c_str());
					return true;
				}

				return false;
			}

			if (pWnd->IsVisible())
				strcpy_s(Destination, MAX_STRING, "TRUE");
			else
				strcpy_s(Destination, MAX_STRING, "FALSE");
		}
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pWindowType)
			return false;
		VarPtr.Ptr = Source.Ptr;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override;
};

//============================================================================
// MQ2MenuType

class MQ2MenuType : public MQ2Type
{
public:
	enum MenuMembers
	{
		Address = 1,
		NumVisibleMenus = 2,
		CurrMenu = 3,
		Name = 4,
		NumItems = 5,
		Items = 6,
	};

	enum MenuMethods
	{
		Select = 1,
	};

	MQ2MenuType() : MQ2Type("menu")
	{
		TypeMember(Address);
		TypeMember(NumVisibleMenus);
		TypeMember(CurrMenu);
		TypeMember(Name);
		TypeMember(NumItems);
		TypeMember(Items);

		TypeMethod(Select);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, "No Menu Open");
		if (VarPtr.Ptr && ((CContextMenuManager*)VarPtr.Ptr)->NumVisibleMenus == 1)
		{
			CContextMenuManager* pMgr = (CContextMenuManager*)VarPtr.Ptr;
			if (pMgr->CurrMenu < 8)
			{
				int currmen = pMgr->CurrMenu;
				if (CContextMenu* menu = pMgr->pCurrMenus[currmen])
				{
					strcpy_s(Destination, MAX_STRING, menu->GetItemText(0, 1).c_str());
				}
			}
		}
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pMenuType)
			return false;
		VarPtr.Ptr = Source.Ptr;
		return true;
	}
};

//============================================================================
// MQ2MacroType

class MQ2MacroType : public MQ2Type
{
public:
	enum MacroMembers
	{
		Name = 1,
		RunTime = 2,
		Paused = 3,
		Return = 4,
		Params = 5,
		Param = 6,
		CurLine = 7,
		MemUse = 8,
		CurCommand = 9,
		StackSize = 10,
		IsTLO = 11,
		IsOuterVariable = 12,
		CurSub = 13,
	};

	enum MacroMethods
	{
		Undeclared = 1,
	};

	MQ2MacroType() : MQ2Type("macro")
	{
		TypeMember(Name);
		TypeMember(RunTime);
		TypeMember(Paused);
		TypeMember(Return);
		TypeMember(Params);
		TypeMember(Param);
		TypeMember(CurLine);
		TypeMember(MemUse);
		TypeMember(CurCommand);
		TypeMember(StackSize);
		TypeMember(IsTLO);
		TypeMember(IsOuterVariable);
		TypeMember(CurSub);

		TypeMethod(Undeclared);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (gRunning)
		{
			strcpy_s(Destination, MAX_STRING, gszMacroName);
			return true;
		}

		return false;
	}
};

//============================================================================
// MQ2ZoneType

class MQ2ZoneType : public MQ2Type
{
public:
	enum ZoneMembers
	{
		Name = 1,
		ShortName = 2,
		ID = 3,
		Address = 4,
		ZoneFlags = 5,
	};

	MQ2ZoneType() : MQ2Type("zone")
	{
		TypeMember(Name);
		TypeMember(ShortName);
		TypeMember(ID);
		TypeMember(Address);
		TypeMember(ZoneFlags);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, &((PZONELIST)VarPtr.Int)->LongName[0]);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type == pZoneType)
		{
			VarPtr.Ptr = Source.Ptr;
			return true;
		}
		if (Source.Type == (MQ2Type*)pCurrentZoneType)
		{
			if (CHARINFO* pChar = GetCharInfo())
			{
				int zoneid = (pChar->zoneId & 0x7FFF);
				if (zoneid <= MAX_ZONES)
				{
					VarPtr.Ptr = &((PWORLDDATA)pWorldData)->ZoneArray[zoneid];
					return true;
				}
			}
		}
		return false;
	}
};

//============================================================================
// MQ2CurrentZoneType

class MQ2CurrentZoneType : public MQ2Type
{
public:
	enum CurrentZoneMembers
	{
		Name = 1,
		ShortName = 2,
		Type = 3,
		Gravity = 4,
		SkyType = 5,
		SafeY = 6,
		SafeX = 7,
		SafeZ = 8,
		MinClip = 9,
		MaxClip = 10,
		ID = 11,
		SafeN = 12,
		SafeW = 13,
		SafeU = 14,
		Address = 15,
		ZoneType = 16,
		Dungeon = 17,
		Indoor = 18,
		Outdoor = 19,
		NoBind = 20,
	};

	MQ2CurrentZoneType() : MQ2Type("currentzone")
	{
		TypeMember(Name);
		TypeMember(ShortName);
		TypeMember(Type);
		TypeMember(Gravity);
		TypeMember(SkyType);
		TypeMember(SafeY);
		TypeMember(SafeX);
		TypeMember(SafeZ);
		TypeMember(MinClip);
		TypeMember(MaxClip);
		TypeMember(ID);
		TypeMember(SafeN);
		TypeMember(SafeW);
		TypeMember(SafeU);
		TypeMember(Address);
		TypeMember(ZoneType);
		TypeMember(Dungeon);
		TypeMember(Indoor);
		TypeMember(Outdoor);
		TypeMember(NoBind);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, &((PZONEINFO)pZoneInfo)->LongName[0]);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pCurrentZoneType)
			return false;
		VarPtr.Ptr = Source.Ptr;
		return true;
	}
};

//============================================================================
// MQ2CharSelectListType

class MQ2CharSelectListType : public MQ2Type
{
public:
	enum CharSelectListMembers
	{
		Name = 1,
		Level = 2,
		ZoneID = 3,
		Count = 4,
		Class = 5,
		Race = 6,
	};

	enum CharSelectListMethods
	{
	};

	MQ2CharSelectListType() : MQ2Type("charselectlist")
	{
		TypeMember(Name);
		TypeMember(Level);
		TypeMember(ZoneID);
		TypeMember(Count);
		TypeMember(Class);
		TypeMember(Race);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		return false;
	}
};

//============================================================================
// MQ2EverQuestType

class MQ2EverQuestType : public MQ2Type
{
public:
	enum EverQuestMembers
	{
		GameState = 1,
		LoginName = 2,
		Server = 3,
		LastCommand = 4,
		LastTell = 5,
		Running = 6,
		MouseX = 7,
		MouseY = 8,
		Ping = 9,
		LClickedObject = 10,
		WinTitle = 11,
		PID = 12,
		PPriority = 13,
		ChatChannels = 14,
		ChatChannel = 15,
		ViewportX = 16,
		ViewportY = 17,
		ViewportXMax = 18,
		ViewportYMax = 19,
		ViewportXCenter = 20,
		ViewportYCenter = 21,
		xScreenMode = 22,
		LayoutCopyInProgress = 23,
		LastMouseOver = 24,
		CharSelectList = 25,
		CurrentUI = 26,
		IsDefaultUILoaded = 27,
		xHWND = 28,
		Foreground = 29,
		ValidLoc = 30,
	};

	enum EverQuestMethods
	{
	};

	MQ2EverQuestType() : MQ2Type("everquest")
	{
		TypeMember(GameState);
		TypeMember(LoginName);
		TypeMember(Server);
		TypeMember(LastCommand);
		TypeMember(LastTell);
		TypeMember(Running);
		TypeMember(MouseX);
		TypeMember(MouseY);
		TypeMember(Ping);
		TypeMember(ChatChannels);
		TypeMember(ChatChannel);
		TypeMember(ViewportX);
		TypeMember(ViewportY);
		TypeMember(ViewportXMax);
		TypeMember(ViewportYMax);
		TypeMember(ViewportXCenter);
		TypeMember(ViewportYCenter);
		TypeMember(LClickedObject);
		TypeMember(WinTitle);
		TypeMember(PID);
		TypeMember(PPriority);
		AddMember(xScreenMode, "ScreenMode");
		TypeMember(LayoutCopyInProgress);
		TypeMember(LastMouseOver);
		TypeMember(CharSelectList);
		TypeMember(CurrentUI);
		TypeMember(IsDefaultUILoaded);
		AddMember(xHWND, "HWND");
		TypeMember(Foreground);
		TypeMember(ValidLoc);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		return false;
	}
};

//============================================================================
// MQ2MacroQuestType

class MQ2MacroQuestType : public MQ2Type
{
public:
	enum MacroQuestMembers
	{
		Error = 1,
		SyntaxError = 2,
		MQ2DataError = 3,
		BuildDate = 4,
		Build = 5,
		Path = 6,
		Version = 7,
		InternalName = 8,
		Parser = 9,
	};

	MQ2MacroQuestType() : MQ2Type("macroquest")
	{
		TypeMember(Error);
		TypeMember(SyntaxError);
		TypeMember(MQ2DataError);
		TypeMember(BuildDate);
		TypeMember(Build);
		TypeMember(Path);
		TypeMember(Version);
		TypeMember(InternalName);
		TypeMember(Parser);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		return false;
	}
};

class MQ2MathType : public MQ2Type
{
public:
	enum MathMembers
	{
		Abs = 1,
		Rand = 2,
		Calc = 3,
		Sin = 4,
		Cos = 5,
		Tan = 6,
		Asin = 7,
		Acos = 8,
		Atan = 9,
		Hex = 10,
		Dec = 11,
		Not = 12,
		Distance = 13,
		Sqrt = 14,
		Clamp = 15,
	};

	MQ2MathType() : MQ2Type("math")
	{
		TypeMember(Abs);
		TypeMember(Rand);
		TypeMember(Calc);
		TypeMember(Sin);
		TypeMember(Cos);
		TypeMember(Tan);
		TypeMember(Asin);
		TypeMember(Acos);
		TypeMember(Atan);
		TypeMember(Hex);
		TypeMember(Dec);
		TypeMember(Not);
		TypeMember(Distance);
		TypeMember(Sqrt);
		TypeMember(Clamp);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		return false;
	}
};

//============================================================================
// MQ2RaceType

class MQ2RaceType : public MQ2Type
{
public:
	enum RaceMembers
	{
		Name = 1,
		ID = 2,
	};

	MQ2RaceType() : MQ2Type("race")
	{
		TypeMember(Name);
		TypeMember(ID);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		const char* pDesc = pEverQuest->GetRaceDesc(VarPtr.DWord);
		strcpy_s(Destination, MAX_STRING, pDesc);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.DWord = Source.DWord;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.DWord = GetIntFromString(Source, 0);
		return true;
	}
};

//============================================================================
// MQ2ClassType

class MQ2ClassType : public MQ2Type
{
public:
	enum ClassMembers
	{
		Name = 1,
		ShortName = 2,
		ID = 3,
		PureCaster = 4,
		CanCast = 5,
		DruidType = 6,
		NecromancerType = 7,
		ShamanType = 8,
		ClericType = 9,
		PetClass = 10,
		HealerType = 11,
		MercType = 12,
	};

	MQ2ClassType() : MQ2Type("class")
	{
		TypeMember(Name);
		TypeMember(ShortName);
		TypeMember(ID);
		TypeMember(PureCaster);
		TypeMember(CanCast);
		TypeMember(DruidType);
		TypeMember(NecromancerType);
		TypeMember(ShamanType);
		TypeMember(ClericType);
		TypeMember(PetClass);
		TypeMember(HealerType);
		TypeMember(MercType);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		const char* pDesc = GetClassDesc(VarPtr.DWord);
		strcpy_s(Destination, MAX_STRING, pDesc);

		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.DWord = Source.DWord;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.DWord = GetIntFromString(Source, 0);
		return true;
	}
};

//============================================================================
// MQ2BodyType

class MQ2BodyType : public MQ2Type
{
public:
	enum BodyMembers
	{
		Name = 1,
		ID = 2
	};

	MQ2BodyType() : MQ2Type("body")
	{
		TypeMember(Name);
		TypeMember(ID);
	}

	~MQ2BodyType()
	{
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		const char* pDesc = GetBodyTypeDesc(VarPtr.DWord);
		strcpy_s(Destination, MAX_STRING, pDesc);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.DWord = Source.DWord;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.DWord = GetIntFromString(Source, 0);
		return true;
	}
};

//============================================================================
// MQ2DeityType

class MQ2DeityType : public MQ2Type
{
public:
	enum DeityMembers
	{
		Name = 1,
		Team = 2,
		ID = 3
	};

	MQ2DeityType() : MQ2Type("Deity")
	{
		TypeMember(Name);
		TypeMember(Team);
		TypeMember(ID);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		char* pDesc = pEverQuest->GetDeityDesc(VarPtr.DWord);
		strcpy_s(Destination, MAX_STRING, pDesc);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.DWord = Source.DWord;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.DWord = GetIntFromString(Source, 0);
		return true;
	}
};

//============================================================================
// MQ2TimeType

class MQ2TimeType : public MQ2Type
{
public:
	enum TimeMembers
	{
		Hour = 1,
		Minute = 2,
		Second = 3,
		DayOfWeek = 4,
		Day = 5,
		Month = 6,
		Year = 7,
		Time12 = 8,
		Time24 = 9,
		Date = 10,
		Night = 11,
		SecondsSinceMidnight = 12,
		Hour12 = 13,
	};

	MQ2TimeType() : MQ2Type("time")
	{
		TypeMember(Hour);
		TypeMember(Minute);
		TypeMember(Second);
		TypeMember(DayOfWeek);
		TypeMember(Day);
		TypeMember(Month);
		TypeMember(Year);
		TypeMember(Time12);
		TypeMember(Time24);
		TypeMember(Date);
		TypeMember(Night);
		TypeMember(SecondsSinceMidnight);
		TypeMember(Hour12);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		tm* Now = static_cast<tm*>(VarPtr.Ptr);

		sprintf_s(Destination, MAX_STRING, "%02d:%02d:%02d", Now->tm_hour, Now->tm_min, Now->tm_sec);
		return true;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
		VarPtr.Ptr = new tm();
		VarPtr.HighPart = 0;

		ZeroMemory(VarPtr.Ptr, sizeof(tm));
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		tm* Now = static_cast<tm*>(VarPtr.Ptr);
		delete Now;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pTimeType)
			return false;

		memcpy(VarPtr.Ptr, Source.Ptr, sizeof(tm));
		return true;
	}
};

//============================================================================
// MQ2TypeType

class MQ2TypeType : public MQ2Type
{
public:
	enum TypeMembers
	{
		xName = 1,
		xTypeMember = 2,
	};

	MQ2TypeType();

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, char* Source) override;
};

//============================================================================
// MQ2HeadingType

class MQ2HeadingType : public MQ2Type
{
public:
	enum HeadingMembers
	{
		Name = 1,
		ShortName = 2,
		Degrees = 3,
		Clock = 4,
		DegreesCCW = 5,
	};

	enum HeadingMethods
	{
	};

	MQ2HeadingType() : MQ2Type("heading")
	{
		TypeMember(Name);
		TypeMember(ShortName);
		TypeMember(Degrees);
		TypeMember(Clock);
		TypeMember(DegreesCCW);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, szHeadingNormalShort[(INT)((360.0f - VarPtr.Float) / 22.5f + 0.5f) % 16]);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		VarPtr.Float = GetFloatFromString(Source, 0);
		return true;
	}
};

//============================================================================
// MQ2InvSlotType

class MQ2InvSlotType : public MQ2Type
{
public:
	enum InvSlotMembers
	{
		Pack = 1,
		Slot = 2,
		ID = 3,
		Name = 4,
		Item = 5,
	};

	enum InvSlotMethods
	{
	};

	MQ2InvSlotType() : MQ2Type("invslot")
	{
		TypeMember(Pack);
		TypeMember(Slot);
		TypeMember(ID);
		TypeMember(Name);
		TypeMember(Item);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		_itoa_s(VarPtr.Int, Destination, MAX_STRING, 10);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.DWord = Source.DWord;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		if (IsNumber(Source))
		{
			VarPtr.DWord = GetIntFromString(Source, 0);
			return true;
		}
		else
		{
			char Temp[MAX_STRING] = { 0 };
			strcpy_s(Temp, Source);
			_strlwr_s(Temp);
			VarPtr.DWord = ItemSlotMap[Temp];
			if (VarPtr.DWord || !_stricmp(Temp, "charm"))
			{
				return true;
			}
		}
		return false;
	}
};

//============================================================================
// MQ2PluginType

class MQ2PluginType : public MQ2Type
{
public:
	enum PluginMembers
	{
		Name = 1,
		Version = 2,
	};

	MQ2PluginType() : MQ2Type("plugin")
	{
		TypeMember(Name);
		TypeMember(Version);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (VarPtr.Ptr)
		{
			strcpy_s(Destination, MAX_STRING, ((MQPlugin*)VarPtr.Ptr)->szFilename);
			return true;
		}
		return false;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pPluginType)
			return false;
		VarPtr.Ptr = Source.Ptr;
		return true;
	}
};

//============================================================================
// MQ2BenchmarkType

class MQ2BenchmarkType : public MQ2Type
{
public:
	enum BenchmarkMembers
	{
		Name = 1,
		ID = 2,
		Iterations = 3,
		TimeSpent = 4,
		AvgTimeSpent = 5,
	};

	MQ2BenchmarkType() : MQ2Type("benchmark")
	{
		TypeMember(Name);
		TypeMember(ID);
		TypeMember(Iterations);
		TypeMember(TimeSpent);
		TypeMember(AvgTimeSpent);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		return false;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.DWord = Source.DWord;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		if (IsNumber(Source))
		{
			VarPtr.DWord = GetIntFromString(Source, 0);
			return true;
		}
		return false;
	}
};

//============================================================================
// MQ2SkillType

class MQ2SkillType : public MQ2Type
{
public:
	enum SkillMembers
	{
		Name = 1,
		ID = 2,
		ReuseTime = 3,
		MinLevel = 4,
		SkillCap = 5,
		AltTimer = 6,
		Activated = 7,
		Auto = 8,
	};

	enum SkillMethods
	{
	};

	MQ2SkillType() : MQ2Type("skill")
	{
		TypeMember(Name);
		TypeMember(ID);
		TypeMember(ReuseTime);
		TypeMember(MinLevel);
		TypeMember(SkillCap);
		TypeMember(AltTimer);
		TypeMember(Activated);
		TypeMember(Auto);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (!VarPtr.Ptr)
			return false;
		if (PSKILL pSkill = *(PSKILL*)VarPtr.Ptr)
			if (const char* pName = pStringTable->getString(pSkill->nName))
			{
				strcpy_s(Destination, MAX_STRING, pName);
				return true;
			}
		return false;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pSkillType)
			return false;
		VarPtr.Ptr = Source.Ptr;
		return true;
	}
};

//============================================================================
// MQ2AltAbilityType

class MQ2AltAbilityType : public MQ2Type
{
public:
	enum AltAbilityMembers
	{
		Name = 1,
		ShortName = 2,
		Description = 3,
		MinLevel = 4,
		Cost = 5,
		RequiresAbility = 6,
		RequiresAbilityPoints = 7,
		MaxRank = 8,
		AARankRequired = 9,
		Spell = 10,
		Type = 11,
		ReuseTime = 12,
		ID = 13,
		MyReuseTime = 14,
		Flags = 15,
		Expansion = 16,
		Passive = 17,
		PointsSpent = 18,
		Rank = 19,
		xIndex = 20,
		CanTrain = 21,
		NextIndex = 22,
	};

	enum AltAbilityMethods
	{
	};

	MQ2AltAbilityType() : MQ2Type("altability")
	{
		TypeMember(Name);
		TypeMember(ShortName);
		TypeMember(Description);
		TypeMember(MinLevel);
		TypeMember(Cost);
		TypeMember(RequiresAbility);
		TypeMember(RequiresAbilityPoints);
		TypeMember(MaxRank);
		TypeMember(AARankRequired);
		TypeMember(Spell);
		TypeMember(Type);
		TypeMember(ReuseTime);
		TypeMember(ID);
		TypeMember(MyReuseTime);
		TypeMember(Flags);
		TypeMember(Expansion);
		TypeMember(Passive);
		TypeMember(PointsSpent);
		TypeMember(Rank);
		AddMember(xIndex, "Index");
		TypeMember(CanTrain);
		TypeMember(NextIndex);

	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pAltAbilityType)
			return false;
		VarPtr.Ptr = Source.Ptr;
		return true;
	}
};

//============================================================================
// MQ2TimerType

class MQ2TimerType : public MQ2Type
{
public:
	enum TimerMembers
	{
		Value = 1,
		OriginalValue = 2,
	};

	enum TimerMethods
	{
		Reset = 1,
		Expire = 2,
		Set = 3,
	};

	MQ2TimerType() : MQ2Type("timer")
	{
		TypeMember(Value);
		TypeMember(OriginalValue);

		TypeMethod(Reset);
		TypeMethod(Expire);
		TypeMethod(Set);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		MQTimer* pTimer = reinterpret_cast<MQTimer*>(VarPtr.Ptr);
		_ultoa_s(pTimer->Current, Destination, MAX_STRING, 10);
		return true;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
		MQTimer* pVar = new MQTimer();
		pVar->pNext = gTimer;

		if (gTimer)
			gTimer->pPrev = pVar;
		gTimer = pVar;

		VarPtr.Ptr = pVar;
		VarPtr.HighPart = 0;
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		if (MQTimer* pVar = reinterpret_cast<MQTimer*>(VarPtr.Ptr))
		{
			if (pVar->pPrev)
				pVar->pPrev->pNext = pVar->pNext;
			else
				gTimer = pVar->pNext;
			if (pVar->pNext)
				pVar->pNext->pPrev = pVar->pPrev;

			delete pVar;
		}
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		MQTimer* pTimer = reinterpret_cast<MQTimer*>(VarPtr.Ptr);
		if (Source.Type == pFloatType)
		{
			pTimer->Current = (DWORD)Source.Float;
			pTimer->Original = pTimer->Current;
		}
		else
		{
			pTimer->Current = Source.DWord;
			pTimer->Original = pTimer->Current;
		}
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		MQTimer* pTimer = reinterpret_cast<MQTimer*>(VarPtr.Ptr);

		float VarValue = GetFloatFromString(Source, 0);
		switch (Source[strlen(Source) - 1])
		{
		case 'm':
		case 'M':
			VarValue *= 60;
		case 's':
		case 'S':
			VarValue *= 10;
		}
		pTimer->Current = (DWORD)VarValue;
		pTimer->Original = pTimer->Current;
		return true;
	}
};

//============================================================================
// MQ2ArrayType

class MQ2ArrayType : public MQ2Type
{
public:
	enum ArrayMembers
	{
		Dimensions = 1,
		Size = 2,
	};
	MQ2ArrayType() : MQ2Type("array")
	{
		TypeMember(Dimensions);
		TypeMember(Size);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		return false;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		CDataArray* pArray = (CDataArray*)VarPtr.Ptr;
		delete pArray;
	}
};

//============================================================================
// MQ2GroupType

class MQ2GroupType : public MQ2Type
{
public:
	enum GroupMembers
	{
		Address = 1,
		xMember = 2,
		Members = 3,
		Leader = 4,
		GroupSize = 5,
		MainTank = 6,
		MainAssist = 7,
		Puller = 8,
		MarkNpc = 9,
		MasterLooter = 10,
		AnyoneMissing = 11,
		Present = 12,
		MercenaryCount = 13,
		TankMercCount = 14,
		HealerMercCount = 15,
		MeleeMercCount = 16,
		CasterMercCount = 17,
		MouseOver = 18,
		AvgHPs = 19,
		Injured = 20,
		XCleric = 21,
	};

	enum GroupMethods
	{
	};

	MQ2GroupType() : MQ2Type("group")
	{
		TypeMember(Address);
		AddMember(xMember, "Member");
		TypeMember(Members);
		TypeMember(Leader);
		TypeMember(GroupSize);
		TypeMember(MainTank);
		TypeMember(MainAssist);
		TypeMember(Puller);
		TypeMember(MarkNpc);
		TypeMember(MasterLooter);
		TypeMember(AnyoneMissing);
		TypeMember(Present);
		TypeMember(MercenaryCount);
		TypeMember(TankMercCount);
		TypeMember(HealerMercCount);
		TypeMember(MeleeMercCount);
		TypeMember(CasterMercCount);
		TypeMember(MouseOver);
		TypeMember(AvgHPs);
		TypeMember(Injured);
		AddMember(XCleric, "Cleric");
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2GroupMemberType

class MQ2GroupMemberType : public MQ2Type
{
public:
	enum GroupMemberMembers
	{
		Address = 1,
		Name = 2,
		Leader = 3,
		Spawn = 4,
		Level = 5,
		MainTank = 6,
		MainAssist = 7,
		Puller = 8,
		MarkNpc = 9,
		MasterLooter = 10,
		Mercenary = 11,
		PctAggro = 12,
		xIndex = 13,
		Offline = 14,
		OtherZone = 15,
		Present = 16,
		Type = 17,
	};

	enum GroupMemberMethods
	{
	};

	MQ2GroupMemberType() : MQ2Type("groupmember")
	{
		TypeMember(Address);
		TypeMember(Name);
		TypeMember(Leader);
		TypeMember(Spawn);
		TypeMember(Level);
		TypeMember(MainTank);
		TypeMember(MainAssist);
		TypeMember(Puller);
		TypeMember(MarkNpc);
		TypeMember(MasterLooter);
		TypeMember(Mercenary);
		TypeMember(PctAggro);
		AddMember(xIndex, "Index");
		TypeMember(Offline);
		TypeMember(OtherZone);
		TypeMember(Present);
		TypeMember(Type);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pGroupMemberType)
			return false;
		VarPtr.Ptr = Source.Ptr;
		return true;
	}
};

//============================================================================
// MQ2RaidType

class MQ2RaidType : public MQ2Type
{
public:
	enum RaidMembers
	{
		xMember = 1,
		Members = 2,
		Target = 3,
		Leader = 4,
		TotalLevels = 5,
		AverageLevel = 6,
		LootType = 7,
		Looter = 8,
		Looters = 9,
		Locked = 10,
		Invited = 11,
		MainAssist = 12,
		MasterLooter = 13,
	};

	enum RaidMethods
	{
	};

	MQ2RaidType() : MQ2Type("raid")
	{
		AddMember(xMember, "Member");
		TypeMember(Members);
		TypeMember(Target);
		TypeMember(Leader);
		TypeMember(TotalLevels);
		TypeMember(AverageLevel);
		TypeMember(LootType);
		TypeMember(Looter);
		TypeMember(Looters);
		TypeMember(Locked);
		TypeMember(Invited);
		TypeMember(MainAssist);
		TypeMember(MasterLooter);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		return false;
	}
};

//============================================================================
// MQ2RaidMemberType

class MQ2RaidMemberType : public MQ2Type
{
public:
	enum RaidMemberMembers
	{
		Name = 1,
		Group = 3,
		GroupLeader = 4,
		RaidLeader = 5,
		Spawn = 6,
		Looter = 7,
		Class = 8,
		Level = 9,
	};

	enum RaidMemberMethods
	{
	};

	MQ2RaidMemberType() : MQ2Type("raidmember")
	{
		TypeMember(Name);
		TypeMember(Group);
		TypeMember(GroupLeader);
		TypeMember(RaidLeader);
		TypeMember(Spawn);
		TypeMember(Looter);
		TypeMember(Class);
		TypeMember(Level);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		DWORD nRaidMember = VarPtr.DWord - 1;
		if (VarPtr.DWord >= 72)
			return false;
		if (!pRaid->RaidMemberUsed[nRaidMember])
			return false;
		PEQRAIDMEMBER pRaidMember = &pRaid->RaidMember[nRaidMember];
		strcpy_s(Destination, MAX_STRING, pRaidMember->Name);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pRaidMemberType)
			return false;
		VarPtr.Ptr = Source.Ptr;
		return true;
	}
};

//============================================================================
// MQ2EvolvingItemType

class MQ2EvolvingItemType : public MQ2Type
{
public:
	enum EvolvingItemMembers
	{
		ExpPct = 1,
		ExpOn = 2,
		Level = 3,
		MaxLevel = 4,
	};

	MQ2EvolvingItemType() : MQ2Type("Evolving")
	{
		TypeMember(ExpPct);
		TypeMember(ExpOn);
		TypeMember(Level);
		TypeMember(MaxLevel);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (VarPtr.Ptr && IsEvolvingItem((CONTENTS*)VarPtr.Ptr))
			strcpy_s(Destination, MAX_STRING, "TRUE");
		else
			strcpy_s(Destination, MAX_STRING, "FALSE");
		return true;
	}
};

//============================================================================
// MQ2DynamicZoneType

class MQ2DynamicZoneType : public MQ2Type
{
public:
	enum DynamicZoneMembers
	{
		Name = 1,
		Members = 2,
		MaxMembers = 3,
		xMember = 4,
		Leader = 5,
		InRaid = 6,
		LeaderFlagged = 7,
	};

	MQ2DynamicZoneType() : MQ2Type("dynamiczone")
	{
		TypeMember(Name);
		TypeMember(Members);
		TypeMember(MaxMembers);
		AddMember(xMember, "Member");
		TypeMember(Leader);
		TypeMember(InRaid);
		TypeMember(LeaderFlagged);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (pDZMember)
		{
			strcpy_s(Destination, MAX_STRING, pDynamicZone->DZName);
			return true;
		}
		return false;
	}
};

//============================================================================
// MQ2DZMemberType

class MQ2DZMemberType : public MQ2Type
{
public:
	enum DZMemberTypeMembers
	{
		Name = 1,
		Status = 2,
		Flagged = 3,
	};

	MQ2DZMemberType() : MQ2Type("dzmember")
	{
		TypeMember(Name);
		TypeMember(Status);
		TypeMember(Flagged);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, ((DZMEMBER*)VarPtr.Ptr)->Name);
		return true;
	}
};

//============================================================================
// MQ2FellowshipType

class MQ2FellowshipType : public MQ2Type
{
public:
	enum FellowshipTypeMembers
	{
		ID = 1,
		Leader = 2,
		MotD = 3,
		Members = 4,
		xMember = 5,
		CampfireDuration = 6,
		CampfireY = 7,
		CampfireX = 8,
		CampfireZ = 9,
		CampfireZone = 10,
		Campfire = 11,
	};

	MQ2FellowshipType() : MQ2Type("fellowship")
	{
		TypeMember(ID);
		TypeMember(Leader);
		TypeMember(MotD);
		TypeMember(Members);
		AddMember(xMember, "Member");
		TypeMember(CampfireDuration);
		TypeMember(CampfireY);
		TypeMember(CampfireX);
		TypeMember(CampfireZ);
		TypeMember(CampfireZone);
		TypeMember(Campfire);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (VarPtr.Ptr && ((FELLOWSHIPINFO*)VarPtr.Ptr)->FellowshipID)
			strcpy_s(Destination, MAX_STRING, "TRUE");
		else
			strcpy_s(Destination, MAX_STRING, "FALSE");
		return true;
	}
};

//============================================================================
// MQ2FellowshipMemberType

class MQ2FellowshipMemberType : public MQ2Type
{
public:
	enum FMTypeMembers
	{
		Zone = 1,
		Level = 2,
		Class = 3,
		LastOn = 4,
		Name = 5,
	};

	MQ2FellowshipMemberType() : MQ2Type("fellowshipmember")
	{
		TypeMember(Zone);
		TypeMember(Level);
		TypeMember(Class);
		TypeMember(LastOn);
		TypeMember(Name);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, ((FELLOWSHIPMEMBER*)VarPtr.Ptr)->Name);
		return true;
	}
};

//============================================================================
// MQ2FriendsType

class MQ2FriendsType : public MQ2Type
{
public:
	enum FriendsMembers
	{
		xFriend = 1
	};

	enum FriendsMethods
	{
	};

	MQ2FriendsType() : MQ2Type("friend")
	{
		AddMember(xFriend, "Friend");
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		// return the number of friends here...
		if (((EVERQUEST*)pEverQuest)->ChatService)
		{
			class CChatService* pChat = (class CChatService*) ((EVERQUEST*)pEverQuest)->ChatService;
			sprintf_s(Destination, MAX_STRING, "%d", pChat->GetNumberOfFriends());
			return true;
		}
		return false;
	}
};

//============================================================================
// MQ2TargetType

class MQ2TargetType : public MQ2Type
{
public:
	enum TargetMembers
	{
		Buff = 1,
		BuffCount = 2,
		BuffDuration = 3,
		PctAggro = 4,
		SecondaryPctAggro = 5,
		SecondaryAggroPlayer = 6,
		AggroHolder = 7,
		Slowed = 8,
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
		Corrupted = 37,
		BuffsPopulated = 38,
		MyBuff = 39,
		MyBuffCount = 40,
		MyBuffDuration = 41,
		Feared = 42,
		Silenced = 43,
		Invulnerable = 44,
		Dotted = 45,
		MaxMeleeTo = 46,
	};

	MQ2TargetType() : MQ2Type("target")
	{
		TypeMember(Buff);
		TypeMember(BuffCount);
		TypeMember(BuffDuration);
		TypeMember(PctAggro);
		TypeMember(SecondaryPctAggro);
		TypeMember(SecondaryAggroPlayer);
		TypeMember(AggroHolder);
		TypeMember(Slowed);
		TypeMember(Rooted);
		TypeMember(Mezzed);
		TypeMember(Crippled);
		TypeMember(Maloed);
		TypeMember(Tashed);
		TypeMember(Snared);
		TypeMember(Hasted);
		TypeMember(Aego);
		TypeMember(Skin);
		TypeMember(Focus);
		TypeMember(Regen);
		TypeMember(Symbol);
		TypeMember(Clarity);
		TypeMember(Pred);
		TypeMember(Strength);
		TypeMember(Brells);
		TypeMember(SV);
		TypeMember(SE);
		TypeMember(HybridHP);
		TypeMember(Growth);
		TypeMember(Shining);
		TypeMember(Beneficial);
		TypeMember(DSed);
		TypeMember(RevDSed);
		TypeMember(Charmed);
		TypeMember(Diseased);
		TypeMember(Poisoned);
		TypeMember(Cursed);
		TypeMember(Corrupted);
		TypeMember(BuffsPopulated);
		TypeMember(MyBuff);
		TypeMember(MyBuffCount);
		TypeMember(MyBuffDuration);
		TypeMember(Feared);
		TypeMember(Silenced);
		TypeMember(Invulnerable);
		TypeMember(Dotted);
		TypeMember(MaxMeleeTo);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (!VarPtr.Ptr)
			return false;

		SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
		strcpy_s(Destination, MAX_STRING, pSpawn->Name);
		return true;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate a SPAWNINFO
		VarPtr.Ptr = new SPAWNINFO();
		VarPtr.HighPart = 0;

		// FIXME: Do not ZeroMemory a SPAWNINFO
		ZeroMemory(VarPtr.Ptr, sizeof(SPAWNINFO));
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate a SPAWNINFO
		SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
		delete pSpawn;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type == pSpawnType)
		{
			memcpy(VarPtr.Ptr, Source.Ptr, sizeof(SPAWNINFO));
			return true;
		}
		else
		{
			if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(Source.DWord))
			{
				memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
				return true;
			}
		}
		return false;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(GetIntFromString(Source, 0)))
		{
			memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
			return true;
		}
		return false;
	}
};

//============================================================================
// Mq2TaskObjectiveType

class MQ2TaskObjectiveType : public MQ2Type
{
public:
	enum TaskObjectiveTypeMembers
	{
		Instruction = 1,
		Status = 2,
		Zone = 3,
		xIndex = 4,
		Type = 5,
		RequiredCount = 6,
		Optional = 7,
		RequiredItem = 8,
		RequiredSkill = 9,
		RequiredSpell = 10,
		DZSwitchID = 11,
		CurrentCount = 12,
	};

	MQ2TaskObjectiveType() : MQ2Type("taskobjectivemember")
	{
		TypeMember(Instruction);
		TypeMember(Status);
		TypeMember(Zone);
		AddMember(xIndex, "Index");
		TypeMember(Type);
		TypeMember(RequiredCount);
		TypeMember(Optional);
		TypeMember(RequiredItem);
		TypeMember(RequiredSkill);
		TypeMember(RequiredSpell);
		TypeMember(DZSwitchID);
		TypeMember(CurrentCount);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2TaskMemberType

class MQ2TaskMemberType : public MQ2Type
{
public:
	enum TaskMemberTypeMembers
	{
		Name = 1,
		Leader = 2,
		xIndex = 3,
	};

	MQ2TaskMemberType() : MQ2Type("taskmember")
	{
		TypeMember(Name);
		TypeMember(Leader);
		AddMember(xIndex, "Index");
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, static_cast<TASKMEMBER*>(VarPtr.Ptr)->Name);
		return true;
	}
};

//============================================================================
// MQ2TaskType

class MQ2TaskType : public MQ2Type
{
public:
	enum TaskTypeMembers
	{
		Address = 1,
		xIndex = 2,
		Title = 3,
		Timer = 4,
		xMember = 5,
		Members = 6,
		Leader = 7,
		Step = 8,
		Objective = 9,
		Type = 10,
		MemberList = 11,
		ID = 12,
		WindowIndex = 13,
	};

	enum TaskMethods
	{
		Select = 1,
	};

	MQ2TaskType() : MQ2Type("task")
	{
		TypeMember(Address);
		AddMember(xIndex, "Index");
		TypeMember(Title);
		TypeMember(Timer);
		AddMember(xMember, "Member");
		TypeMember(Members);
		TypeMember(Leader);
		TypeMember(Step);
		TypeMember(Objective);
		TypeMember(Type);
		TypeMember(MemberList);
		TypeMember(ID);
		TypeMember(WindowIndex);

		TypeMethod(Select);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2XTargetType

class MQ2XTargetType : public MQ2Type
{
public:
	enum xTargetMembers
	{
		xAddress = 1,
		TargetType = 2,
		ID = 3,
		Name = 4,
		PctAggro = 5,
	};

	MQ2XTargetType() : MQ2Type("xtarget")
	{
		TypeMember(xAddress);
		TypeMember(TargetType);
		TypeMember(ID);
		TypeMember(Name);
		TypeMember(PctAggro);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		int index = VarPtr.DWord;

		if (CHARINFO* pChar = GetCharInfo())
		{
			if (index <= 23 && pChar->pXTargetMgr && pChar->pXTargetMgr->XTargetSlots.Count)
			{
				XTARGETSLOT xtd = GetCharInfo()->pXTargetMgr->XTargetSlots[index];
				strcpy_s(Destination, MAX_STRING, xtd.Name);
			}
		}
		else
		{
			strcpy_s(Destination, MAX_STRING, "NULL");
		}

		return true;
	}

	void InitVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate a SPAWNINFO
		VarPtr.Ptr = new SPAWNINFO();
		VarPtr.HighPart = 0;

		ZeroMemory(VarPtr.Ptr, sizeof(SPAWNINFO));
	}

	void FreeVariable(MQVarPtr& VarPtr) override
	{
		// FIXME: Do not allocate a SPAWNINFO
		SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
		delete pSpawn;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type == pSpawnType)
		{
			memcpy(VarPtr.Ptr, Source.Ptr, sizeof(SPAWNINFO));
			return true;
		}
		else
		{
			int index = Source.DWord;

			if (CHARINFO* pChar = GetCharInfo())
			{
				if (index <= 23 && pChar->pXTargetMgr && pChar->pXTargetMgr->XTargetSlots.Count)
				{
					XTARGETSLOT xtd = GetCharInfo()->pXTargetMgr->XTargetSlots[index];

					if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(xtd.SpawnID))
					{
						memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
						return true;
					}
				}
			}
		}

		return false;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		int index = GetIntFromString(Source, 0);

		if (CHARINFO* pChar = GetCharInfo())
		{
			if (index <= 23 && pChar->pXTargetMgr && pChar->pXTargetMgr->XTargetSlots.Count)
			{
				XTARGETSLOT xtd = GetCharInfo()->pXTargetMgr->XTargetSlots[index];

				if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(xtd.SpawnID))
				{
					memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
					return true;
				}
			}
		}
		return false;
	}
};

//============================================================================
// MQ2KeyRingType

class MQ2KeyRingType : public MQ2Type
{
public:
	enum KeyRingTypeMembers
	{
		xIndex = 1,
		xName = 2,
	};

	MQ2KeyRingType();

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2ItemFilterDataType

class MQ2ItemFilterDataType : public MQ2Type
{
public:
	enum ItemFilterDataMembers
	{
		Name = 1,
		ID = 2,
		IconID = 3,
		AutoRoll = 4,
		Need = 5,
		Greed = 6,
		Never = 7,
		Types = 8,
	};

	enum MQ2ItemFilterDataMethods
	{
	};

	MQ2ItemFilterDataType() : MQ2Type("itemfilterdata")
	{
		TypeMember(Name);
		TypeMember(ID);
		TypeMember(IconID);
		TypeMember(AutoRoll);
		TypeMember(Need);
		TypeMember(Greed);
		TypeMember(Never);
		TypeMember(Types);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (ItemFilterData* pitem = (ItemFilterData*)VarPtr.Ptr)
		{
			strcpy_s(Destination, 64, pitem->Name);
			return true;
		}
		return false;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pItemFilterDataType)
			return false;
		VarPtr.Ptr = Source.Ptr;
		return true;
	}
};

//============================================================================
// MQ2AdvLootItemType

class MQ2AdvLootItemType : public MQ2Type
{
public:
	enum AdvLootItemMembers
	{
		Address = 1,
		xIndex = 2,
		Name = 3,
		ID = 4,
		StackSize = 5,
		Corpse = 6,
		AutoRoll = 7,
		Need = 8,
		Greed = 9,
		No = 10,
		AlwaysNeed = 11,
		AlwaysGreed = 12,
		Never = 13,
		IconID = 14,
		xNoDrop = 15,
	};

	enum MQ2AdvLootItemMethods
	{
	};

	MQ2AdvLootItemType() : MQ2Type("advlootitem")
	{
		TypeMember(Address);
		AddMember(xIndex, "Index");
		TypeMember(Name);
		TypeMember(ID);
		TypeMember(StackSize);
		TypeMember(Corpse);
		TypeMember(AutoRoll);
		TypeMember(Need);
		TypeMember(Greed);
		TypeMember(No);
		TypeMember(AlwaysNeed);
		TypeMember(AlwaysGreed);
		TypeMember(Never);
		TypeMember(IconID);
		AddMember(xNoDrop, "NoDrop");
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (AdvancedLootItem* pitem = (AdvancedLootItem*)VarPtr.Ptr)
		{
			strcpy_s(Destination, 64, pitem->Name);
			return true;
		}

		return false;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pAdvLootItemType)
			return false;

		VarPtr.Ptr = Source.Ptr;
		return true;
	}
};

//============================================================================
// MQ2AdvLootType

class MQ2AdvLootType : public MQ2Type
{
public:
	enum AdvLootTypeMembers
	{
		PList = 1,
		PCount = 2,
		SList = 3,
		SCount = 4,
		PWantCount = 5,
		SWantCount = 6,
		xLootInProgress = 7,
		Filter = 8,
	};

	MQ2AdvLootType() : MQ2Type("advloot")
	{
		TypeMember(PList);
		TypeMember(PCount);
		TypeMember(SList);
		TypeMember(SCount);
		TypeMember(PWantCount);
		TypeMember(SWantCount);
		AddMember(xLootInProgress, "LootInProgress");
		TypeMember(Filter);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override { return false; }
};

//============================================================================
// MQ2AlertType

class MQ2AlertType : public MQ2Type
{
public:
	enum AlertTypeMembers
	{
		List = 1,
		Size = 2,
	};

	MQ2AlertType();

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2AlertListType

class MQ2AlertListType : public MQ2Type
{
public:
	enum AlertListTypeMembers
	{
		MinLevel = 1,
		MaxLevel = 2,
		SpawnType = 3,
		SpawnID = 4,
		FromSpawnID = 5,
		Radius = 6,
		Name = 7,
		BodyType = 8,
		Race = 9,
		Class = 10,
		Light = 11,
		GuildID = 12,
		bSpawnID = 13,
		bNotNearAlert = 14,
		bNearAlert = 15,
		bNoAlert = 16,
		bAlert = 17,
		bLFG = 18,
		bTrader = 19,
		bLight = 20,
		bTargNext = 21,
		bTargPrev = 22,
		bGroup = 23,
		bNoGroup = 24,
		bRaid = 25,
		bGM = 26,
		bNamed = 27,
		bMerchant = 28,
		bTributeMaster = 29,
		bKnight = 30,
		bTank = 31,
		bHealer = 32,
		bDps = 33,
		bSlower = 34,
		bAura = 35,
		bBanner = 36,
		bCampfire = 37,
		NotID = 38,
		NotNearAlertList = 39,
		NearAlertList = 40,
		NoAlertList = 41,
		AlertList = 42,
		ZRadius = 43,
		FRadius = 44,
		xLoc = 45,
		yLoc = 46,
		bKnownLocation = 47,
		bNoPet = 48,
		SortBy = 49,
		bNoGuild = 50,
		bLoS = 51,
		bExactName = 52,
		bTargetable = 53,
		PlayerState = 54,
		Spawn = 55,
		bFellowship = 56,
		bBanker = 57,
	};

	MQ2AlertListType() : MQ2Type("alertlist")
	{
		TypeMember(MinLevel);
		TypeMember(MaxLevel);
		TypeMember(SpawnType);
		TypeMember(SpawnID);
		TypeMember(FromSpawnID);
		TypeMember(Radius);
		TypeMember(Name);
		TypeMember(BodyType);
		TypeMember(Race);
		TypeMember(Class);
		TypeMember(Light);
		TypeMember(GuildID);
		TypeMember(bSpawnID);
		TypeMember(bNotNearAlert);
		TypeMember(bNearAlert);
		TypeMember(bNoAlert);
		TypeMember(bAlert);
		TypeMember(bLFG);
		TypeMember(bTrader);
		TypeMember(bLight);
		TypeMember(bTargNext);
		TypeMember(bTargPrev);
		TypeMember(bGroup);
		TypeMember(bNoGroup);
		TypeMember(bRaid);
		TypeMember(bGM);
		TypeMember(bNamed);
		TypeMember(bMerchant);
		TypeMember(bTributeMaster);
		TypeMember(bKnight);
		TypeMember(bTank);
		TypeMember(bHealer);
		TypeMember(bDps);
		TypeMember(bSlower);
		TypeMember(bAura);
		TypeMember(bBanner);
		TypeMember(bCampfire);
		TypeMember(NotID);
		TypeMember(NotNearAlertList);
		TypeMember(NearAlertList);
		TypeMember(NoAlertList);
		TypeMember(AlertList);
		TypeMember(ZRadius);
		TypeMember(FRadius);
		TypeMember(xLoc);
		TypeMember(yLoc);
		TypeMember(bKnownLocation);
		TypeMember(bNoPet);
		TypeMember(SortBy);
		TypeMember(bNoGuild);
		TypeMember(bLoS);
		TypeMember(bExactName);
		TypeMember(bTargetable);
		TypeMember(PlayerState);
		TypeMember(Spawn);
		TypeMember(bFellowship);
		TypeMember(bBanker);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		DWORD theindex = LOWORD(VarPtr.DWord);
		DWORD theitem = HIWORD(VarPtr.DWord);
		sprintf_s(Destination, 128, "${Alert[%d].List[%d].Name}", (int)theindex, (int)theitem);
		return true;
	}
};

//============================================================================
// MQ2WorldLocationType

class MQ2WorldLocationType : public MQ2Type
{
public:
	enum WorldLocationTypeMembers
	{
		ID = 1,
		Y = 2,
		X = 3,
		Z = 4,
		Heading = 5,
		Zone = 6,
	};

	MQ2WorldLocationType() : MQ2Type("worldlocation")
	{
		TypeMember(ID);
		TypeMember(Y);
		TypeMember(X);
		TypeMember(Z);
		TypeMember(Heading);
		TypeMember(Zone);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination)
	{
		if (PcProfile* pProfile = GetPcProfile())
		{
			int index = std::clamp(VarPtr.Int, 0, 4);

			int zindex = pProfile->BoundLocations[index].ZoneBoundID & 0x7FFF;
			if (zindex < MAX_ZONES)
			{
				if (ZONELIST* pList = ((WORLDDATA*)pWorldData)->ZoneArray[zindex])
				{
					strcpy_s(Destination, MAX_STRING, pList->ShortName);
					return true;
				}
			}
		}
		return false;
	}
};

//============================================================================
// MQ2SolventType

class MQ2SolventType : public MQ2Type
{
public:
	enum SolventTypeMembers
	{
		Name = 1,
		ID = 2,
		Item = 3,
		Count = 4,
	};

	MQ2SolventType() : MQ2Type("solventtype")
	{
		TypeMember(Name);
		TypeMember(ID);
		TypeMember(Item);
		TypeMember(Count);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	// TODO: Move this to a global
	static const char* GetAugmentNameByID(int itemid)
	{
		switch (itemid)
		{
		case 47001:
			return "Class I Augmentation Distiller";
		case 47002:
			return "Class II Augmentation Distiller";
		case 47003:
			return "Class III Augmentation Distiller";
		case 47004:
			return "Class IV Augmentation Distiller";
		case 47005:
			return "Class V Augmentation Distiller";
		case 47006:
			return "Class VI Augmentation Distiller";
		case 47007:
			return "Class VII Augmentation Distiller";
		case 47008:
			return "Class VIII Augmentation Distiller";
		case 47009:
			return "Class IX Augmentation Distiller";
		case 47010:
			return "Class X Augmentation Distiller";
		case 47011:
			return "Class XI Augmentation Distiller";
		case 47012:
			return "Class XII Augmentation Distiller";
		case 47013:
			return "Class XIII Augmentation Distiller";
		case 47014:
			return "Class XIV Augmentation Distiller";
		case 47015:
			return "Class XV Augmentation Distiller";
		case 47016:
			return "Class XVI Augmentation Distiller";
		case 47017:
			return "Class XVII Augmentation Distiller";
		case 47018:
			return "Class XVIII Augmentation Distiller";
		case 47019:
			return "Class XIX Augmentation Distiller";
		case 47020:
			return "Class XX Augmentation Distiller";
		case 47021:
			return "Class XXI Augmentation Distiller";
		default:
			return "Perfected Augmentation Distiller";
		};
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (const char* pstr = GetAugmentNameByID(VarPtr.DWord)) {
			strcpy_s(Destination, MAX_STRING, pstr);
			return true;
		}
		return false;
	}
};

//============================================================================
// MQ2AugType

class MQ2AugType : public MQ2Type
{
public:
	enum AugTypeMembers
	{
		Slot = 1,
		Type = 2,
		Visible = 3,
		Infusable = 4,
		Empty = 5,
		Name = 6,
		Item = 7,
		Solvent = 8,
	};

	MQ2AugType();

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2RangeType

class MQ2RangeType : public MQ2Type
{
public:
	enum RangeMembers
	{
		Between = 1,
		Inside = 2,
	};

	MQ2RangeType() : MQ2Type("Range")
	{
		TypeMember(Between);
		TypeMember(Inside);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		return false;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pRangeType)
			return false;

		VarPtr.Ptr = Source.Ptr;
		return true;
	}
};

//============================================================================
// MQ2AuraType

class MQ2AuraType : public MQ2Type
{
public:
	enum AuraTypeMembers
	{
		ID = 1,
		Name = 2,
		SpawnID = 3,
		Find = 4,
	};

	enum AuraTypeMethods
	{
		Remove = 1,
	};

	MQ2AuraType() : MQ2Type("auratype")
	{
		TypeMember(ID);
		TypeMember(Name);
		TypeMember(SpawnID);
		TypeMember(Find);

		TypeMethod(Remove);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (AURAINFO* pAura = (AURAINFO*)VarPtr.Ptr) {
			strcpy_s(Destination, MAX_STRING, pAura->Name);
			return true;
		}
		return false;
	}
};

//============================================================================
// MQ2BandolierItemType

class MQ2BandolierItemType : public MQ2Type
{
public:
	enum BandolierItemTypeMembers
	{
		xIndex = 1,
		ID = 2,
		IconID = 3,
		Name = 4,
	};

	MQ2BandolierItemType() : MQ2Type("bandolieritem")
	{
		AddMember(xIndex, "Index");
		TypeMember(ID);
		TypeMember(IconID);
		TypeMember(Name);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (BandolierItemInfo* ptr = (BandolierItemInfo*)VarPtr.Ptr)
		{
			strcpy_s(Destination, MAX_STRING, ptr->Name);
			return true;
		}
		return false;
	}
};

//============================================================================
// MQ2BandolierType

class MQ2BandolierType : public MQ2Type
{
public:
	enum BandolierTypeMembers
	{
		xIndex = 1,
		Active = 2,
		Name = 3,
		Item = 4,
	};

	enum BandolierTypeMethods
	{
		Activate = 1,
	};

	MQ2BandolierType() : MQ2Type("bandolier")
	{
		AddMember(xIndex, "Index");
		TypeMember(Active);
		TypeMember(Name);
		TypeMember(Item);

		TypeMethod(Activate);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (PcProfile* pProfile = GetPcProfile())
		{
			int index = std::clamp(VarPtr.Int, 0, MAX_BANDOLIER_ITEMS - 1);
			strcpy_s(Destination, MAX_STRING, pProfile->Bandolier[index].Name);
			return true;
		}
		return false;
	}
};

} // namespace mq
