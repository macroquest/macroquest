/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2004 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

EQLIB_VAR class MQ2FloatType *pFloatType;
EQLIB_VAR class MQ2StringType *pStringType;
EQLIB_VAR class MQ2IntType *pIntType;
EQLIB_VAR class MQ2ByteType *pByteType;
EQLIB_VAR class MQ2SpawnType *pSpawnType;
EQLIB_VAR class MQ2CharacterType *pCharacterType;
EQLIB_VAR class MQ2BuffType *pBuffType;
EQLIB_VAR class MQ2SpellType *pSpellType;
EQLIB_VAR class MQ2TicksType *pTicksType;

class MQ2FloatType : public MQ2Type
{
public:
	MQ2FloatType():MQ2Type("float")
	{
	}

	~MQ2FloatType()
	{
	}

	// pure type, no members
	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		sprintf(Destination,"%.3f",Ptr);
		return true;
	}
};
class MQ2IntType : public MQ2Type
{
public:
	MQ2IntType():MQ2Type("int")
	{
	}

	~MQ2IntType()
	{
	}

	// pure type, no members
	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		itoa((int)Ptr,Destination,10);
		return true;
	}
};
class MQ2ByteType : public MQ2Type
{
public:
	MQ2ByteType():MQ2Type("byte")
	{
	}

	~MQ2ByteType()
	{
	}

	// pure type, no members
	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		itoa((char)Ptr,Destination,10);
		return true;
	}
};
class MQ2StringType : public MQ2Type
{
public:
	static enum StringMembers
	{
		Arg=1,
		Mid=2,
		Left=3,
		Right=4,
		Find=5,
		Length=6,
		Upper=7,
		Lower=8,
	};

	MQ2StringType():MQ2Type("string")
	{
	}

	~MQ2StringType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}
	 bool ToString(void *Ptr, PCHAR Destination)
	{
		strcpy(Destination,(const char *)Ptr);
		return true;
	}
};

class MQ2TicksType : public MQ2Type
{
public:
	static enum TicksMembers
	{
		Hours=1,
		Minutes=2,
		Seconds=3,
		Time=4
	};
	MQ2TicksType():MQ2Type("ticks")
	{
		AddMember(Hours,"Hours");
		AddMember(Minutes,"Minutes");
		AddMember(Seconds,"Seconds");
		AddMember(Time,"Time");
	}
	inline BOOL AddMember(enum TicksMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2TicksType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		unsigned long N=MemberMap[Member];
		if (!N)
			return false;
		N--;
		PMQ2TYPEMEMBER pMember=Members[N];
		if (!pMember)
			return false;
		static CHAR Temp[128];
		switch((TicksMembers)pMember->ID)
		{
		case Hours:
			Dest.Ptr=(PVOID)(((int)Ptr)/600);
			Dest.Type=pIntType;
			return true;
		case Minutes:
			Dest.Ptr=(PVOID)(((int)Ptr)/10);
			Dest.Type=pIntType;
			return true;
		case Seconds:
			Dest.Ptr=(PVOID)(((int)Ptr)*6);
			Dest.Type=pIntType;
			return true;
		case Time:
			{
				int Secs=(int)Ptr*6;
				int Mins=Secs/60;
				Secs=Secs%60;
				sprintf(Temp,"%d:%02d",Mins,Secs);
				Dest.Ptr=&Temp[0];
				Dest.Type=pStringType;
			}
			return true;
		}		
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		itoa((int)Ptr,Destination,10);
		return true;
	}
};


class MQ2SpawnType : public MQ2Type
{
public:
	static enum SpawnMembers
	{
		ID=1,
		Name=2,
		Level=3,
		X=4,
		Y=5,
		Z=6,
		DistanceX=7,
		DistanceY=8,
		DistanceZ=9,
		Distance=10,
		Distance3D=11,
		DistancePredict=12,
		Next=13,
		Prev=14,
		Heading=15,
		Speed=16,
		Levitating=17,
		Sneaking=18,
		HeadingTo=19,
		Light=20,
		Body=21,
		State=22,
		CurrentHPs=23,
		MaxHPs=24,
		PctHPs=25,
		Deity=26,
		DeityTeam=27,
		Type=28,
		CleanName=29,
		Surname=30,
		Guild=31,
		GuildStatus=32,
		Master=33,
		Pet=34,
		Race=35,
		Class=36,
		ShortClass=37,
		Gender=38,
		GM=39,
		Height=40,
		MaxRange=41,
	};
	MQ2SpawnType():MQ2Type("spawn")
	{
		AddMember(ID,"ID");
		AddMember(Name,"Name");
		AddMember(Level,"Level");
	}
	inline BOOL AddMember(enum SpawnMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2SpawnType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		strcpy(Destination,((PSPAWNINFO)Ptr)->Name);
		return true;
	}
};

class MQ2CharacterType : public MQ2Type
{
public:
	static enum CharacterMembers
	{
		ID=1,
		Name=2,
		Level=3,
		Exp=4,
		Spawn=5,
		Dar=6,
		AAExp=7,
		AAPoints=8,
		AARank=9,
		CurrentHPs=10,
		MaxHPs=11,
		HPRegen=12,
		PctHPs=13,
		CurrentMana=14,
		MaxMana=15,
		ManaRegen=16,
		PctMana=17,
		Buff=18,
		Song=19,
		Book=20,
		Skill=21,
		Ability=22,
		Surname=23,
		Cash=24,
		CashBank=25,
		PlatShared=26,
		Grouped=27,
		HPBonus=28,
		ManaBonus=29,
		GukEarned=30,
		MMEarned=31,
		RujEarned=32,
		TakEarned=33,
		LDonPoints=34,
		CurrentFavor=35,
		CareerFavor=36,
		Endurance=37,
	};
	MQ2CharacterType():MQ2Type("character")
	{
		AddMember(ID,"ID");
		AddMember(Name,"Name");
		AddMember(Level,"Level");
	}
	inline BOOL AddMember(enum CharacterMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2CharacterType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		strcpy(Destination,((PCHARINFO)Ptr)->Name);
		return true;
	}
};

class MQ2BuffType : public MQ2Type
{
public:
	static enum BuffMembers
	{
		ID=1,
		Level=2,
		Spell=3,
		Mod=4,
		Duration=5,
	};
	MQ2BuffType():MQ2Type("buff")
	{
		AddMember(ID,"ID");
		AddMember(Spell,"Spell");
		AddMember(Level,"Level");
		AddMember(Mod,"Mod");
		AddMember(Duration,"Duration");
	}
	inline BOOL AddMember(enum BuffMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2BuffType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		return false;
	}
};

class MQ2SpellType : public MQ2Type
{
public:
	static enum SpellMembers
	{
		ID=1,
		Name=2,
		Level=3,
		Skill=4,
		Mana=5,
		ResistAdj=6,
		Range=7,
		AERange=8,
		PushBack=9,
		CastTime=10,
		FizzleTime=11,
		MyCastTime=12,
		RecoveryTime=13,
		RecastTime=14,
		Duration=15,
		SpellType=16,
		TargetType=17,
		ResistType=18,
	};
	MQ2SpellType():MQ2Type("spell")
	{
		AddMember(ID,"ID");
	}
	inline BOOL AddMember(enum SpellMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2SpellType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		return false;
	}
};

class MQ2ItemType : public MQ2Type
{
public:
	static enum ItemMembers
	{
		ID=1,
		Name=2,
		Lore=3,
		NoDrop=4,
		NoRent=5,
		Magic=6,
		Value=7,
		Size=8,
		Weight=9,
		Stack=10,
		Type=11,
		Charges=12,
		LDoNTheme=13,
		DMGBonusType=14,
	};
	MQ2ItemType():MQ2Type("Item")
	{
		AddMember(ID,"ID");
	}
	inline BOOL AddMember(enum ItemMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2ItemType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		return false;
	}
};


class MQ2SwitchType : public MQ2Type
{
public:
	static enum SwitchMembers
	{
		ID=1,
		Distance=2,
		X=3,
		Y=4,
		Z=5,
		Heading=6,
		DefaultX=7,
		DefaultY=8,
		DefaultZ=9,
		DefaultHeading=10,
		Open=11,
		HeadingTo=12,
		Name=13,
	};
	MQ2SwitchType():MQ2Type("switch")
	{
		AddMember(ID,"ID");
	}
	inline BOOL AddMember(enum SwitchMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2SwitchType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		return false;
	}
};

class MQ2GroundType : public MQ2Type
{
public:
	static enum GroundMembers
	{
		ID=1,
		Distance=2,
		X=3,
		Y=4,
		Z=5,
		Heading=6,
		Name=7,
	};
	MQ2GroundType():MQ2Type("ground")
	{
		AddMember(ID,"ID");
	}
	inline BOOL AddMember(enum GroundMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2GroundType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		return false;
	}
};


class MQ2CorpseType : public MQ2Type
{
public:
	static enum CorpseMembers
	{
		ID=1,
	};
	MQ2CorpseType():MQ2Type("corpse")
	{
		AddMember(ID,"ID");
	}
	inline BOOL AddMember(enum CorpseMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2CorpseType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		return false;
	}
};

class MQ2MerchantType : public MQ2Type
{
public:
	static enum MerchantMembers
	{
		ID=1,
	};
	MQ2MerchantType():MQ2Type("merchant")
	{
		AddMember(ID,"ID");
	}
	inline BOOL AddMember(enum MerchantMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2MerchantType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		return false;
	}
};

class MQ2WindowType : public MQ2Type
{
public:
	static enum WindowMembers
	{
		Open=1,
	};
	MQ2WindowType():MQ2Type("window")
	{
		AddMember(Open,"Open");
	}
	inline BOOL AddMember(enum WindowMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2WindowType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		return false;
	}
};


class MQ2MacroType : public MQ2Type
{
public:
	static enum MacroMembers
	{
		Name=1,
	};
	MQ2MacroType():MQ2Type("macro")
	{
		AddMember(Name,"Name");
	}
	inline BOOL AddMember(enum MacroMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2MacroType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		return false;
	}
};

class MQ2ZoneType : public MQ2Type
{
public:
	static enum ZoneMembers
	{
		Name=1,
	};
	MQ2ZoneType():MQ2Type("zone")
	{
		AddMember(Name,"Name");
	}
	inline BOOL AddMember(enum ZoneMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2ZoneType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		return false;
	}
};

class MQ2MacroQuestType : public MQ2Type
{
public:
	static enum MacroQuestMembers
	{
		Name=1,
	};
	MQ2MacroQuestType():MQ2Type("macroquest")
	{
		AddMember(Name,"Name");
	}
	inline BOOL AddMember(enum MacroQuestMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2MacroQuestType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		return false;
	}
};

class MQ2MathType : public MQ2Type
{
public:
	static enum MathMembers
	{
		Abs=1,
		Rand=2,
		Calc=3,
		Sin=4,
		Cos=5,
		Tan=6,
		Asin=7,
		Acos=8,
		Atan=9,
		Hex=10,
		Dec=11,
		Not=12,
	};
	MQ2MathType():MQ2Type("math")
	{
		AddMember(Abs,"Abs");
	}
	inline BOOL AddMember(enum MathMembers ID, PCHAR Name)
	{
		return MQ2Type::AddMember((DWORD)ID,Name);
	}

	~MQ2MathType()
	{
	}

	bool GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(void *Ptr, PCHAR Destination)
	{
		return false;
	}
};
