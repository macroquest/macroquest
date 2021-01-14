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

	bool InheritedMember(const char* Name)
	{
		return pInherits && pInherits->FindMember(Name);
	}

	void SetInheritance(MQ2Type* pNewInherit)
	{
		pInherits = pNewInherit;
	}

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
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
	static bool dataBool(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2IntType

class MQ2IntType : public MQ2Type
{
	enum class IntMembers
	{
		Float = 1,
		Double,
		Hex,
		Reverse,
		LowPart,
		HighPart,
		Prettify,
	};

public:
	MQ2IntType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;

	static bool dataInt(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2Int64Type

class MQ2Int64Type : public MQ2Type
{
	enum class Int64Members
	{
		Float = 1,
		Double,
		Hex,
		Reverse,
		LowPart,
		HighPart,
		Prettify,
	};

public:
	MQ2Int64Type();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
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
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
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
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
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

	bool FromString(MQVarPtr& VarPtr, const char* Source) override
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
	MQ2StringType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2FloatType

class MQ2FloatType : public MQ2Type
{
	enum class FloatMembers
	{
		Deci = 1,
		Centi,
		Milli,
		Int,
		Precision,
		Raw,
		Prettify,
	};

public:
	MQ2FloatType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;

	static bool dataFloat(const char* szIndex, MQTypeVar& Ret);
};

//============================================================================
// MQ2DoubleType

class MQ2DoubleType : public MQ2Type
{
	enum class DoubleMembers
	{
		Deci = 1,
		Centi,
		Milli,
		Int,
		Precision,
		Prettify,
	};

public:
	MQ2DoubleType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
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
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
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
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2SpawnType

class MQ2SpawnType : public MQ2Type
{
public:
	MQ2SpawnType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
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
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
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
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
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
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
};

//============================================================================
// MQ2CachedBuffType

class MQ2CachedBuffType : public MQ2Type
{
public:
	MQ2CachedBuffType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
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
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
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
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
};

//============================================================================
// MQ2SwitchType

class MQ2SwitchType : public MQ2Type
{
public:
	MQ2SwitchType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
};

//============================================================================
// MQ2GroundType

class MQ2GroundType : public MQ2Type
{
public:
	MQ2GroundType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
	static bool dataGroundItem(const char* szIndex, MQTypeVar& Ret);
	static bool dataGroundItemCount(const char* szIndex, MQTypeVar& Ret);
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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
	MQ2PointMerchantItemType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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
	MQ2MercenaryType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
};

//============================================================================
// MQ2PetType

class MQ2PetType : public MQ2Type
{
public:
	MQ2PetType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
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
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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
	MQ2MacroType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//============================================================================
// MQ2ZoneType

class MQ2ZoneType : public MQ2Type
{
	enum class ZoneMembers
	{
		Name = 1,
		ShortName = 2,
		ID = 3,
		Address = 4,
		ZoneFlags = 5,
	};

public:
	MQ2ZoneType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, pZoneInfo->LongName);
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool FromString(MQVarPtr& VarPtr, const char* Source) override
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool FromString(MQVarPtr& VarPtr, const char* Source) override
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool FromString(MQVarPtr& VarPtr, const char* Source) override
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool FromString(MQVarPtr& VarPtr, const char* Source) override
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
	MQ2TimeType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
};

//============================================================================
// MQ2TypeType

class MQ2TypeType : public MQ2Type
{
public:
	MQ2TypeType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, szHeadingNormalShort[(INT)((360.0f - VarPtr.Float) / 22.5f + 0.5f) % 16]);
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;

	bool FromString(MQVarPtr& VarPtr, const char* Source) override
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
	MQ2InvSlotType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool FromString(MQVarPtr& VarPtr, const char* Source) override
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		return false;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		VarPtr.DWord = Source.DWord;
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, const char* Source) override
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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
	MQ2TimerType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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
	MQ2RaidType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (VarPtr.Ptr && IsEvolvingItem((ItemClient*)VarPtr.Ptr))
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, reinterpret_cast<DynamicZonePlayerInfo*>(VarPtr.Ptr)->Name);
		return true;
	}
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	void InitVariable(MQVarPtr& VarPtr) override;
	void FreeVariable(MQVarPtr& VarPtr) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
	bool FromString(MQVarPtr& VarPtr, const char* Source) override;
	static bool dataTarget(const char* szIndex, MQTypeVar& Ret);
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
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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
	MQ2AdvLootItemType();

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override;

	enum {
		CList = 1,
		PList = 2,
	};
};

//============================================================================
// MQ2AdvLootType

class MQ2AdvLootType : public MQ2Type
{
public:
	MQ2AdvLootType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (PcProfile* pProfile = GetPcProfile())
		{
			int index = std::clamp(VarPtr.Int, 0, 4);

			int zindex = pProfile->BoundLocations[index].ZoneBoundID & 0x7FFF;
			if (zindex < MAX_ZONES)
			{
				if (EQZoneInfo* pList = pWorldData->ZoneArray[zindex])
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (AuraData* pAura = reinterpret_cast<AuraData*>(VarPtr.Ptr))
		{
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (BandolierItemInfo* ptr = reinterpret_cast<BandolierItemInfo*>(VarPtr.Ptr))
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

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;

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

//============================================================================
// MQ2FrameLimiterType

class MQ2FrameLimiterType : public MQ2Type
{
public:
	MQ2FrameLimiterType();
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

} // namespace mq
