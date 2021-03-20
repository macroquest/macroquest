/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

	virtual bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) { return false; }
	virtual bool FromString(MQVarPtr& VarPtr, const char* Source) { return false; }

	virtual void InitVariable(MQVarPtr& VarPtr)
	{
		VarPtr.Ptr = nullptr;
	}

	virtual void FreeVariable(MQVarPtr& VarPtr) {}

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) = 0;

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

	inline bool InheritsFrom(MQ2Type* testType)
	{
		MQ2Type* parentType = m_parent;
		int limit = 10; // arbitrary limit to avoid infinite looping with cyclical references
		while (parentType)
		{
			if (parentType == testType)
				return true;

			if (--limit == 0)
				return false;
			parentType = parentType->m_parent;
		}
		return false;
	}

	inline bool InheritedMember(const char* Name)
	{
		return m_parent && m_parent->FindMember(Name);
	}

	inline void SetInheritance(MQ2Type* pNewInherit)
	{
		m_parent = pNewInherit;
	}

	// Override this function to convert this type to the requested type. Return true if the conversion is successful. The
	// Result should be placed in VarPtr and its type should match that of toType.
	virtual bool Downcast(MQVarPtr& VarPtr, MQ2Type* toType) { return false; }

	//----------------------------------------------------------------------------
	// deprecated virtual functions

	// If you encounter an error here, you've derived from MQ2Type using a non-const Source. Change
	// your FromString function to take a const char* as the second parameter.
	virtual bool FromString(MQVarPtr& VarPtr, char* Source) final {
		return FromString(VarPtr, (const char*)Source);
	}

	// If you encounter an error here, you've derived from MQ2Type and implemented GetMember using a non-const Member. Change
	// your GetMember function to take a const char* as the second parameter.
	virtual bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) final {
		return GetMember(VarPtr, (const char*)Member, Index, Dest);
	}

	// If you encounter an error here, you've derived from MQ2Type and implemented FromData using a non-const Source. Change
	// your FromData function to take a const MQTypeVar& as the second parameter.
	virtual bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) final {
		return FromData(VarPtr, (const MQTypeVar&)Source);
	}

protected:
	MQLIB_OBJECT bool AddMember(int id, const char* Name);
	MQLIB_OBJECT bool RemoveMember(const char* Name);
	MQLIB_OBJECT bool AddMethod(int ID, const char* Name);
	MQLIB_OBJECT bool RemoveMethod(const char* Name);

	char TypeName[32];
	bool m_owned = false;
	MQ2Type* m_parent = nullptr;
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
	CDataArray(MQ2Type* Type, const char* Index);
	~CDataArray();

	void Delete();
	int GetElement(char* Index);
	bool GetElement(char* Index, MQTypeVar& Dest);

	MQ2Type* GetType() { return m_pType; }
	MQVarPtr& GetData(int index) { return m_pData[index]; }
	int GetExtents(int index) const { return m_pExtents[index]; }
	int GetNumExtents() const { return m_nExtents; }
	int GetTotalElements() const { return m_totalElements; }

	void Initialize(const char* defaultValue);
	void Initialize(const MQTypeVar& defaultValue);

private:
	MQ2Type* m_pType = nullptr;
	MQVarPtr* m_pData = nullptr;
	int* m_pExtents = nullptr;
	int m_nExtents = 0;
	int m_totalElements = 0;
};

#pragma region Basic Types

//============================================================================
// MQ2BoolType

class MQ2BoolType : public MQ2Type
{
public:
	MQ2BoolType() : MQ2Type("bool") {}
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;

	// ${Bool[...]}
	static bool dataBool(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2IntType

class MQ2IntType : public MQ2Type
{
public:
	MQ2IntType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;

	// ${Int[...]}
	static bool dataInt(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2Int64Type

class MQ2Int64Type : public MQ2Type
{
public:
	MQ2Int64Type();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2ArgbType

class MQ2ArgbType : public MQ2Type
{
public:
	MQ2ArgbType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2ByteType

class MQ2ByteType : public MQ2Type
{
public:
	MQ2ByteType();

	// pure type, no members
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2StringType

class MQ2StringType : public MQ2Type
{
public:
	MQ2StringType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2FloatType

class MQ2FloatType : public MQ2Type
{
public:
	MQ2FloatType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;

	static bool dataFloat(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2DoubleType

class MQ2DoubleType : public MQ2Type
{
public:
	MQ2DoubleType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2TicksType

class MQ2TicksType : public MQ2Type
{
public:
	MQ2TicksType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2TimeStampType

class MQ2TimeStampType : public MQ2Type
{
public:
	MQ2TimeStampType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2ArrayType

class MQ2ArrayType : public MQ2Type
{
public:
	MQ2ArrayType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
};

//============================================================================
// MQ2RangeType

class MQ2RangeType : public MQ2Type
{
public:
	MQ2RangeType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;

	static bool dataRange(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2TypeType

class MQ2TypeType : public MQ2Type
{
public:
	MQ2TypeType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;

	static bool dataType(const char* szIndex, MQTypeVar& Ret);
};


//============================================================================
// MQ2TimeType

class MQ2TimeType : public MQ2Type
{
public:
	MQ2TimeType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;

	static bool dataTime(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2HeadingType

class MQ2HeadingType : public MQ2Type
{
public:
	MQ2HeadingType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;

	static bool dataHeading(const char* szIndex, MQTypeVar& Ret);
};

#pragma endregion

#pragma region MQ Types
//============================================================================
// MQ2AlertType

class MQ2AlertType : public MQ2Type
{
public:
	MQ2AlertType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataAlert(const char* szIndex, MQTypeVar& Ret);
};

#pragma endregion

//============================================================================
// MQ2SpawnType

class MQ2SpawnType : public MQ2Type
{
public:
	MQ2SpawnType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;

	static bool dataSpawn(const char* szIndex, MQTypeVar& Ret);
	static bool dataSpawnCount(const char* szIndex, MQTypeVar& Ret);
	static bool dataLastSpawn(const char* szIndex, MQTypeVar& Ret);
	static bool dataNearestSpawn(const char* szIndex, MQTypeVar& Ret);

	// This is for use in retrieving the spawn that is pointed to by the MQVarPtr.
	static SPAWNINFO* GetSpawnPtr(const MQVarPtr& VarPtr);
	MQLIB_OBJECT MQTypeVar MakeTypeVar(SPAWNINFO* pSpawn);

	static inline MQVarPtr MakeVarPtr(SPAWNINFO* pSpawn)
	{
		if (pSpawn)
		{
			return MQVarPtr::Create(ObserveEQObject(pSpawn));
		}

		return MQVarPtr{};

	}

	bool GetMember(SPAWNINFO* pSpawn, const char* Member, char* Index, MQTypeVar& Dest);
};

//============================================================================
// MQ2TargetType

class MQ2TargetType : public MQ2Type
{
public:
	MQ2TargetType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataTarget(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2CharacterType

class MQ2CharacterType : public MQ2Type
{
public:
	MQ2CharacterType();

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	virtual bool ToString(MQVarPtr VarPtr, char* Destination) override;
	virtual bool Downcast(MQVarPtr& VarPtr, MQ2Type* toType) override;

	static bool dataCharacter(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2SpellType

class MQ2SpellType : public MQ2Type
{
public:
	MQ2SpellType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;

	static bool dataSpell(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2BuffType

class MQ2BuffType : public MQ2Type
{
public:
	MQ2BuffType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
};

//============================================================================
// MQ2CachedBuffType

class MQ2CachedBuffType : public MQ2Type
{
public:
	MQ2CachedBuffType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
};

//============================================================================
// MQ2ItemSpellType

class MQ2ItemSpellType : public MQ2Type
{
public:
	MQ2ItemSpellType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
};

//============================================================================
// MQ2ItemType

class MQ2ItemType : public MQ2Type
{
public:
	MQ2ItemType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;

	static bool dataCursor(const char* szIndex, MQTypeVar& Ret);
	static bool dataSelectedItem(const char* szIndex, MQTypeVar& Ret);
	static bool dataFindItemBank(const char* szIndex, MQTypeVar& Ret);
	static bool dataFindItem(const char* szIndex, MQTypeVar& Ret);
	static bool dataFindItemCount(const char* szIndex, MQTypeVar& Ret);
	static bool dataFindItemBankCount(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2SwitchType

class MQ2SwitchType : public MQ2Type
{
public:
	MQ2SwitchType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;

	static bool dataSwitch(const char* szIndex, MQTypeVar& Ret);
	static bool dataSwitchTarget(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2GroundType

class MQ2GroundType : public MQ2Type
{
public:
	MQ2GroundType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;

	static bool dataGroundItem(const char* szIndex, MQTypeVar& Ret);
	static bool dataGroundItemCount(const char* szIndex, MQTypeVar& Ret);
	static bool dataItemTarget(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2CorpseType

class MQ2CorpseType : public MQ2Type
{
public:
	MQ2CorpseType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataCorpse(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2MerchantType

class MQ2MerchantType : public MQ2Type
{
public:
	MQ2MerchantType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataMerchant(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2PointMerchantType

class MQ2PointMerchantType : public MQ2Type
{
public:
	MQ2PointMerchantType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataPointMerchant(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2PointMerchantItemType

class MQ2PointMerchantItemType : public MQ2Type
{
public:
	MQ2PointMerchantItemType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2MercenaryType

class MQ2MercenaryType : public MQ2Type
{
public:
	MQ2MercenaryType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataMercenary(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2PetType

class MQ2PetType : public MQ2Type
{
public:
	MQ2PetType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataPet(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2PetBuffType

class MQ2PetBuffType : public MQ2Type
{
public:
	MQ2PetBuffType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2WindowType

class MQ2WindowType : public MQ2Type
{
public:
	MQ2WindowType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;

	static bool dataWindow(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2MenuType

class MQ2MenuType : public MQ2Type
{
public:
	MQ2MenuType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;

	static bool dataMenu(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2MacroType

class MQ2MacroType : public MQ2Type
{
public:
	MQ2MacroType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataMacro(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2ZoneType

class MQ2ZoneType : public MQ2Type
{
public:
	MQ2ZoneType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;

	static bool dataZone(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2CurrentZoneType

class MQ2CurrentZoneType : public MQ2Type
{
public:
	MQ2CurrentZoneType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
};

//============================================================================
// MQ2CharSelectListType

class MQ2CharSelectListType : public MQ2Type
{
public:
	MQ2CharSelectListType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2EverQuestType

class MQ2EverQuestType : public MQ2Type
{
public:
	MQ2EverQuestType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataEverQuest(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2MacroQuestType

class MQ2MacroQuestType : public MQ2Type
{
public:
	MQ2MacroQuestType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataMacroQuest(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2MathType

class MQ2MathType : public MQ2Type
{
public:
	MQ2MathType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataMath(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2RaceType

class MQ2RaceType : public MQ2Type
{
public:
	MQ2RaceType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2ClassType

class MQ2ClassType : public MQ2Type
{
public:
	MQ2ClassType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2BodyType

class MQ2BodyType : public MQ2Type
{
public:
	MQ2BodyType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2DeityType

class MQ2DeityType : public MQ2Type
{
public:
	MQ2DeityType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2InvSlotType

class MQ2InvSlotType : public MQ2Type
{
public:
	MQ2InvSlotType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;

	static bool dataInvSlot(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2PluginType

class MQ2PluginType : public MQ2Type
{
public:
	MQ2PluginType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;

	static bool dataPlugin(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2SkillType

class MQ2SkillType : public MQ2Type
{
public:
	MQ2SkillType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;

	static bool dataSkill(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2AltAbilityType

class MQ2AltAbilityType : public MQ2Type
{
public:
	MQ2AltAbilityType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;

	static bool dataAltAbility(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2TimerType

class MQ2TimerType : public MQ2Type
{
public:
	MQ2TimerType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2GroupType

class MQ2GroupType : public MQ2Type
{
public:
	MQ2GroupType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataGroup(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2GroupMemberType

class MQ2GroupMemberType : public MQ2Type
{
public:
	MQ2GroupMemberType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
};

//============================================================================
// MQ2RaidType

class MQ2RaidType : public MQ2Type
{
public:
	MQ2RaidType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataRaid(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2RaidMemberType

class MQ2RaidMemberType : public MQ2Type
{
public:
	MQ2RaidMemberType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
};

//============================================================================
// MQ2EvolvingItemType

class MQ2EvolvingItemType : public MQ2Type
{
public:
	MQ2EvolvingItemType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2DynamicZoneType

class MQ2DynamicZoneType : public MQ2Type
{
public:
	MQ2DynamicZoneType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataDynamicZone(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2DZMemberType

class MQ2DZMemberType : public MQ2Type
{
public:
	MQ2DZMemberType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2FellowshipType

class MQ2FellowshipType : public MQ2Type
{
public:
	MQ2FellowshipType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2FellowshipMemberType

class MQ2FellowshipMemberType : public MQ2Type
{
public:
	MQ2FellowshipMemberType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2FriendsType

class MQ2FriendsType : public MQ2Type
{
public:
	MQ2FriendsType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataFriends(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// Mq2TaskObjectiveType

class MQ2TaskObjectiveType : public MQ2Type
{
public:
	MQ2TaskObjectiveType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2TaskMemberType

class MQ2TaskMemberType : public MQ2Type
{
public:
	MQ2TaskMemberType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2TaskType

class MQ2TaskType : public MQ2Type
{
public:
	MQ2TaskType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataTask(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2XTargetType

class MQ2XTargetType : public MQ2Type
{
public:
	MQ2XTargetType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2KeyRingType

class MQ2KeyRingType : public MQ2Type
{
public:
	MQ2KeyRingType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataMount(const char* szIndex, MQTypeVar& Ret);
	static bool dataIllusion(const char* szIndex, MQTypeVar& Ret);
	static bool dataFamiliar(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2ItemFilterDataType

class MQ2ItemFilterDataType : public MQ2Type
{
public:
	MQ2ItemFilterDataType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
};

//============================================================================
// MQ2AdvLootType

class MQ2AdvLootType : public MQ2Type
{
public:
	MQ2AdvLootType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override { return false; }

	static bool dataAdvLoot(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2AdvLootItemType

class MQ2AdvLootItemType : public MQ2Type
{
public:
	MQ2AdvLootItemType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
};

//============================================================================
// MQ2AlertListType

class MQ2AlertListType : public MQ2Type
{
public:
	MQ2AlertListType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2WorldLocationType

class MQ2WorldLocationType : public MQ2Type
{
public:
	MQ2WorldLocationType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2SolventType

class MQ2SolventType : public MQ2Type
{
public:
	MQ2SolventType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2AugType

class MQ2AugType : public MQ2Type
{
public:
	MQ2AugType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2AuraType

class MQ2AuraType : public MQ2Type
{
public:
	MQ2AuraType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2BandolierItemType

class MQ2BandolierItemType : public MQ2Type
{
public:
	MQ2BandolierItemType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2BandolierType

class MQ2BandolierType : public MQ2Type
{
public:
	MQ2BandolierType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2FrameLimiterType

class MQ2FrameLimiterType : public MQ2Type
{
public:
	MQ2FrameLimiterType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;

	static bool dataFrameLimiter(const char* szIndex, MQTypeVar& Ret);
};

//----------------------------------------------------------------------------

bool dataIf(const char* szIndex, MQTypeVar& Ret);
bool dataGameTime(const char* szIndex, MQTypeVar& Ret);
bool dataIni(const char* szIndex, MQTypeVar& Ret);
bool dataDefined(const char* szIndex, MQTypeVar& Ret);
bool dataSubDefined(const char* szIndex, MQTypeVar& Ret);
bool dataLineOfSight(const char* szIndex, MQTypeVar& Ret);
bool dataSelect(const char* szIndex, MQTypeVar& Ret);
bool dataAlias(const char* szIndex, MQTypeVar& Ret);

} // namespace mq::datatypes
