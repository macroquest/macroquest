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
#define ScopedTypeMember(scope, name) AddMember(static_cast<int>(scope::name), #name)
#define TypeMethod(name) AddMethod(static_cast<int>(name), #name)
#define ScopedTypeMethod(scope, name) AddMethod(static_cast<int>(scope::name), #name)

//----------------------------------------------------------------------------
// Datatype Declarations

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
		return pInherits && pInherits->FindMember(Name);
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
	CDataArray(MQ2Type* Type, char* Index, const char* Default, bool ByData = false);
	~CDataArray();
	void Delete();
	int GetElement(char* Index);
	bool GetElement(char* Index, MQTypeVar& Dest);

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
	MQ2BoolType() : MQ2Type("bool") {}
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, char* Source) override;
	static bool dataBool(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2IntType

class MQ2IntType : public MQ2Type
{
public:
	MQ2IntType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, char* Source) override;
	static bool dataInt(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2Int64Type

class MQ2Int64Type : public MQ2Type
{
public:
	MQ2Int64Type();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, char* Source) override;
};

//============================================================================
// MQ2ArgbType

class MQ2ArgbType : public MQ2Type
{
public:
	MQ2ArgbType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, char* Source) override;
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
	MQ2TicksType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, char* Source) override;
};

//============================================================================
// MQ2TimeStampType

class MQ2TimeStampType : public MQ2Type
{
public:
	MQ2TimeStampType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, char* Source) override;
};

//============================================================================
// MQ2SpawnType

class MQ2SpawnType : public MQ2Type
{
public:
	MQ2SpawnType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, char* Source) override;
	static bool dataSpawn(const char* szIndex, MQTypeVar& Ret);
	static bool dataSpawnCount(const char* szIndex, MQTypeVar& Ret);
	static bool dataLastSpawn(const char* szIndex, MQTypeVar& Ret);
	static bool dataNearestSpawn(const char* szIndex, MQTypeVar& Ret);
	static bool dataDoorTarget(const char* szIndex, MQTypeVar& Ret);
	static bool dataItemTarget(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2CharacterType

class MQ2CharacterType : public MQ2Type
{
public:
	MQ2CharacterType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	static bool dataCharacter(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2SpellType

class MQ2SpellType : public MQ2Type
{
public:
	MQ2SpellType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	static bool dataSpell(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2BuffType

class MQ2BuffType : public MQ2Type
{
public:
	MQ2BuffType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
};

//============================================================================
// MQ2CachedBuffType

class MQ2CachedBuffType : public MQ2Type
{
public:
	MQ2CachedBuffType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
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
	MQ2ItemType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
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
		Size = 36,
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
		TypeMember(Size);

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
	MQ2TargetType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, char* Source) override;
	static bool dataTarget(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// Mq2TaskObjectiveType

class MQ2TaskObjectiveType : public MQ2Type
{
public:
	MQ2TaskObjectiveType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2TaskMemberType

class MQ2TaskMemberType : public MQ2Type
{
public:
	MQ2TaskMemberType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2TaskType

class MQ2TaskType : public MQ2Type
{
public:
	MQ2TaskType();
	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	static bool dataTask(const char* szIndex, MQTypeVar& Ret);
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
