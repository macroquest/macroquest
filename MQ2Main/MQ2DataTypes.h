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
EQLIB_VAR class MQ2BoolType *pBoolType;
EQLIB_VAR class MQ2SpawnType *pSpawnType;
EQLIB_VAR class MQ2CharacterType *pCharacterType;
EQLIB_VAR class MQ2BuffType *pBuffType;
EQLIB_VAR class MQ2SpellType *pSpellType;
EQLIB_VAR class MQ2TicksType *pTicksType;

EQLIB_VAR class MQ2ClassType *pClassType;
EQLIB_VAR class MQ2RaceType *pRaceType;
EQLIB_VAR class MQ2BodyType *pBodyType;

EQLIB_VAR class MQ2GroundType *pGroundType;
EQLIB_VAR class MQ2SwitchType *pSwitchType;

EQLIB_VAR class MQ2MacroType *pMacroType;
EQLIB_VAR class MQ2MacroQuestType *pMacroQuestType;
EQLIB_VAR class MQ2MathType *pMathType;

EQLIB_VAR class MQ2CorpseType *pCorpseType;
EQLIB_VAR class MQ2WindowType *pWindowType;
EQLIB_VAR class MQ2MerchantType *pMerchantType;
EQLIB_VAR class MQ2ZoneType *pZoneType;
EQLIB_VAR class MQ2ItemType *pItemType;
EQLIB_VAR class MQ2DeityType *pDeityType;
EQLIB_VAR class MQ2ArgbType *pArgbType;

#define UseTemp(mystring) strcpy(DataTypeTemp,mystring)
#define TypeMember(name) AddMember((DWORD)name,""#name)

class MQ2BoolType : public MQ2Type
{
public:
	MQ2BoolType():MQ2Type("bool")
	{
	}

	~MQ2BoolType()
	{
	}

	// pure type, no members
	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		if (VarPtr.DWord)
			strcpy(Destination,"TRUE");
		else
			strcpy(Destination,"FALSE");
		return true;
	}
};
class MQ2IntType : public MQ2Type
{
public:
	static enum IntMembers
	{
		Float=1,
		Hex=2,
		Reverse=3,
	};
	MQ2IntType():MQ2Type("int")
	{
		TypeMember(Float);
		TypeMember(Hex);
		TypeMember(Reverse);
	}

	~MQ2IntType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		itoa(VarPtr.Int,Destination,10);
		return true;
	}
};
class MQ2ArgbType : public MQ2Type
{
public:
	static enum ArgbMembers
	{
		A=0,
		R=1,
		G=2,
		B=3,
		Int=4,
	};
	MQ2ArgbType():MQ2Type("argb")
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


	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		unsigned long N=MemberMap[Member];
		if (!N)
			return false;
		N--;
		PMQ2TYPEMEMBER pMember=Members[N];
		if (!pMember)
			return false;
		switch((ArgbMembers)pMember->ID)
		{
		case A:
			Dest.DWord=VarPtr.Argb.A;
			Dest.Type=pIntType;
			return true;
		case R:
			Dest.DWord=VarPtr.Argb.R;
			Dest.Type=pIntType;
			return true;
		case G:
			Dest.DWord=VarPtr.Argb.G;
			Dest.Type=pIntType;
			return true;
		case B:
			Dest.DWord=VarPtr.Argb.B;
			Dest.Type=pIntType;
			return true;
		case Int:
			Dest.DWord=VarPtr.DWord;
			Dest.Type=pIntType;
			return true;
		}
		return false;
	}

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		sprintf(Destination,"%x",VarPtr.Int);
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
	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		return false;
	}

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		itoa(VarPtr.Int,Destination,10);
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
		Compare=9,
		CompareCS=10,
	};

	MQ2StringType():MQ2Type("string")
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
	}

	~MQ2StringType()
	{
	}
	bool MQ2StringType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);
	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		strcpy(Destination,(const char *)VarPtr.Ptr);
		return true;
	}
};
class MQ2FloatType : public MQ2Type
{
public:
	static enum FloatMembers
	{
		Deci=1,
		Centi=2,
		Milli=3,
		Int=4,
		Precision=5,
	};

	MQ2FloatType():MQ2Type("float")
	{
		TypeMember(Deci);
		TypeMember(Centi);
		TypeMember(Milli);
		TypeMember(Int);
		TypeMember(Precision);
	}

	~MQ2FloatType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		sprintf(Destination,"%.3f",VarPtr.Float);
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
		Time=4,
		TotalMinutes=5,
		TotalSeconds=6,
		Ticks=7,
	};
	MQ2TicksType():MQ2Type("ticks")
	{
		TypeMember(Hours);
		TypeMember(Minutes);
		TypeMember(Seconds);
		TypeMember(Time);
		TypeMember(TotalMinutes);
		TypeMember(TotalSeconds);
		TypeMember(Ticks);
	}

	~MQ2TicksType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
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
			Dest.DWord=(VarPtr.DWord)/600;
			Dest.Type=pIntType;
			return true;
		case Minutes:
			Dest.DWord=(VarPtr.DWord/10)%60;
			Dest.Type=pIntType;
			return true;
		case Seconds:
			Dest.DWord=(VarPtr.DWord*6)%60;
			Dest.Type=pIntType;
			return true;
		case Time:
			{
				int Secs=VarPtr.DWord*6;
				int Mins=Secs/60;
				Secs=Secs%60;
				sprintf(Temp,"%d:%02d",Mins,Secs);
				Dest.Ptr=&Temp[0];
				Dest.Type=pStringType;
			}
			return true;
		case TotalMinutes:
			Dest.DWord=VarPtr.DWord/10;
			Dest.Type=pIntType;
			return true;
		case TotalSeconds:
			Dest.DWord=VarPtr.DWord*6;
			Dest.Type=pIntType;
			return true;
		case Ticks:
			Dest.DWord=VarPtr.DWord;
			Dest.Type=pIntType;
			return true;
		}		
		return false;
	}

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		itoa(VarPtr.DWord,Destination,10);
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
		Type=28,
		CleanName=29,
		Surname=30,
		Guild=31,
		GuildStatus=32,
		Master=33,
		Pet=34,
		Race=35,
		Class=36,
		Gender=38,
		GM=39,
		Height=40,
		MaxRange=41,
		AARank=42,
	};
	MQ2SpawnType():MQ2Type("spawn")
	{
		TypeMember(ID);//1,
		TypeMember(Name);//2,
		TypeMember(Level);//3,
		TypeMember(X);//4,
		TypeMember(Y);//5,
		TypeMember(Z);//6,
		TypeMember(DistanceX);//7,
		TypeMember(DistanceY);//8,
		TypeMember(DistanceZ);//9,
		TypeMember(Distance);//10,
		TypeMember(Distance3D);//11,
		TypeMember(DistancePredict);//12,
		TypeMember(Next);//13,
		TypeMember(Prev);//14,
		TypeMember(Heading);//15,
		TypeMember(Speed);//16,
		TypeMember(Levitating);//17,
		TypeMember(Sneaking);//18,
		TypeMember(HeadingTo);//19,
		TypeMember(Light);//20,
		TypeMember(Body);//21,
		TypeMember(State);//22,
		TypeMember(CurrentHPs);//23,
		TypeMember(MaxHPs);//24,
		TypeMember(PctHPs);//25,
		TypeMember(Deity);//26,
		TypeMember(Type);//28,
		TypeMember(CleanName);//29,
		TypeMember(Surname);//30,
		TypeMember(Guild);//31,
		TypeMember(GuildStatus);//32,
		TypeMember(Master);//33,
		TypeMember(Pet);//34,
		TypeMember(Race);//35,
		TypeMember(Class);//36,
		TypeMember(Gender);//38,
		TypeMember(GM);//39,
		TypeMember(Height);//40,
		TypeMember(MaxRange);//41,
		TypeMember(AARank);
	}

	~MQ2SpawnType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		if (!VarPtr.Ptr)
			return false;
		strcpy(Destination,((PSPAWNINFO)VarPtr.Ptr)->Name);
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
		MirEarned=34,
		LDoNPoints=35,
		CurrentFavor=36,
		CareerFavor=37,
		Endurance=38,
		Inventory=39,
		Bank=40,
		Bound=41,
		Combat=42,
		FreeInventory=43,
	};
	MQ2CharacterType():MQ2Type("character")
	{
		TypeMember(ID);//1,
		TypeMember(Name);//2,
		TypeMember(Level);//3,
		TypeMember(Exp);//4,
		TypeMember(Spawn);//5,
		TypeMember(Dar);//6,
		TypeMember(AAExp);//7,
		TypeMember(AAPoints);//8,
		TypeMember(CurrentHPs);//10,
		TypeMember(MaxHPs);//11,
		TypeMember(HPRegen);//12,
		TypeMember(PctHPs);//13,
		TypeMember(CurrentMana);//14,
		TypeMember(MaxMana);//15,
		TypeMember(ManaRegen);//16,
		TypeMember(PctMana);//17,
		TypeMember(Buff);//18,
		TypeMember(Song);//19,
		TypeMember(Book);//20,
		TypeMember(Skill);//21,
		TypeMember(Ability);//22,
		TypeMember(Surname);//23,
		TypeMember(Cash);//24,
		TypeMember(CashBank);//25,
		TypeMember(PlatShared);//26,
		TypeMember(Grouped);//27,
		TypeMember(HPBonus);//28,
		TypeMember(ManaBonus);//29,
		TypeMember(GukEarned);//30,
		TypeMember(MMEarned);//31,
		TypeMember(RujEarned);//32,
		TypeMember(TakEarned);//33,
		TypeMember(MirEarned);//34,
		TypeMember(LDoNPoints);//35,
		TypeMember(CurrentFavor);//36,
		TypeMember(CareerFavor);//37,
		TypeMember(Endurance);//38,
		TypeMember(Inventory);
		TypeMember(Bank);
		TypeMember(Bound);
		TypeMember(Combat);
		TypeMember(FreeInventory);
	}

	~MQ2CharacterType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		if (!VarPtr.Ptr)
			return false;
		strcpy(Destination,((PCHARINFO)VarPtr.Ptr)->Name);
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
		TypeMember(ID);
		TypeMember(Level);
		TypeMember(Spell);
		TypeMember(Mod);
		TypeMember(Duration);
	}

	~MQ2BuffType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		if (!VarPtr.Ptr)
			return false;
		if ((int)((PSPELLBUFF)VarPtr.Ptr)->SpellID>0)
		{
			if (PSPELL pSpell=GetSpellByID(((PSPELLBUFF)VarPtr.Ptr)->SpellID))
			{
				strcpy(Destination,pSpell->Name);
				return true;
			}
		}
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
		TypeMember(ID);//1,
		TypeMember(Name);//2,
		TypeMember(Level);//3,
		TypeMember(Skill);//4,
		TypeMember(Mana);//5,
		TypeMember(ResistAdj);//6,
		TypeMember(Range);//7,
		TypeMember(AERange);//8,
		TypeMember(PushBack);//9,
		TypeMember(CastTime);//10,
		TypeMember(FizzleTime);//11,
		TypeMember(MyCastTime);//12,
		TypeMember(RecoveryTime);//13,
		TypeMember(RecastTime);//14,
		TypeMember(Duration);//15,
		TypeMember(SpellType);//16,
		TypeMember(TargetType);//17,
		TypeMember(ResistType);//18,
	}

	~MQ2SpellType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		if (!VarPtr.Ptr)
			return false;
		strcpy(Destination,((PSPELL)VarPtr.Ptr)->Name);
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
		TypeMember(ID);//1,
		TypeMember(Name);//2,
		TypeMember(Lore);//3,
		TypeMember(NoDrop);//4,
		TypeMember(NoRent);//5,
		TypeMember(Magic);//6,
		TypeMember(Value);//7,
		TypeMember(Size);//8,
		TypeMember(Weight);//9,
		TypeMember(Stack);//10,
		TypeMember(Type);//11,
		TypeMember(Charges);//12,
		TypeMember(LDoNTheme);//13,
		TypeMember(DMGBonusType);//14,
	}

	~MQ2ItemType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		if (!VarPtr.Ptr)
			return false;
		strcpy(Destination,((PITEMINFO)VarPtr.Ptr)->Name);
		return true;
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
		TypeMember(ID);//1,
		TypeMember(Distance);//2,
		TypeMember(X);//3,
		TypeMember(Y);//4,
		TypeMember(Z);//5,
		TypeMember(Heading);//6,
		TypeMember(DefaultX);//7,
		TypeMember(DefaultY);//8,
		TypeMember(DefaultZ);//9,
		TypeMember(DefaultHeading);//10,
		TypeMember(Open);//11,
		TypeMember(HeadingTo);//12,
		TypeMember(Name);//13,
	}

	~MQ2SwitchType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		if (VarPtr.Ptr)
		{
			itoa(((PDOOR)VarPtr.Ptr)->ID,Destination,10);
			return true;
		}
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
		TypeMember(ID);//1,
		TypeMember(Distance);//2,
		TypeMember(X);//3,
		TypeMember(Y);//4,
		TypeMember(Z);//5,
		TypeMember(Heading);//6,
		TypeMember(Name);//7,
	}

	~MQ2GroundType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		if (VarPtr.Ptr)
		{
			itoa(((PGROUNDITEM)VarPtr.Ptr)->ID,Destination,10);
			return true;
		}
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
		TypeMember(ID);
	}

	~MQ2CorpseType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
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
		TypeMember(ID);
	}

	~MQ2MerchantType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
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
		Child=2,
		VScrollMax=3,
		VScrollPos=4,
		VScrollPct=5,
		HScrollMax=6,
		HScrollPos=7,
		HScrollPct=8,
		Children=9,
		Siblings=10,
		Parent=11,
		FirstChild=12,
		Next=13,
		Minimized=14,
		X=15,
		Y=16,
		Height=17,
		Width=18,
		MouseOver=19,
		BGColor=20,
		Text=21,
		Tooltip=22,
	};
	MQ2WindowType():MQ2Type("window")
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
		TypeMember(Siblings);
		TypeMember(FirstChild);
		TypeMember(Next);
		TypeMember(Minimized);//14,
		TypeMember(X);//15,
		TypeMember(Y);//16,
		TypeMember(Height);//17,
		TypeMember(Width);//18,
		TypeMember(MouseOver);//19,
		TypeMember(BGColor);//20,
		TypeMember(Text);//21,
		TypeMember(Tooltip);//22,
 	}

	~MQ2WindowType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		if (VarPtr.Ptr)
			strcpy(Destination,"TRUE");
		else
			strcpy(Destination,"FALSE");
		return true;
	}
};


class MQ2MacroType : public MQ2Type
{
public:
	static enum MacroMembers
	{
		Name=1,
		RunTime=2,
		Defined=3,
		Return=4,
	};
	MQ2MacroType():MQ2Type("macro")
	{
		TypeMember(Name);
		TypeMember(RunTime);
		TypeMember(Defined);
		TypeMember(Return);
	}

	~MQ2MacroType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
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
		ShortName=2,
		Type=3,
		Gravity=4,
		SkyType=5,
		SafeY=6,
		SafeX=7,
		SafeZ=8,
		MinClip=9,
		MaxClip=10,
	};
	MQ2ZoneType():MQ2Type("zone")
	{
		TypeMember(Name);
		TypeMember(ShortName);//2,
		TypeMember(Type);//3,
		TypeMember(Gravity);//4,
		TypeMember(SkyType);//5,
		TypeMember(SafeY);//6,
		TypeMember(SafeX);//7,
		TypeMember(SafeZ);//8,
		TypeMember(MinClip);//9,
		TypeMember(MaxClip);//10,
	}

	~MQ2ZoneType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		strcpy(Destination,&((PZONEINFO)pZoneInfo)->LongName[0]);
		return true;
	}
};

class MQ2MacroQuestType : public MQ2Type
{
public:
	static enum MacroQuestMembers
	{
		GameState=1,
		LoginName=2,
		Server=3,
		LastCommand=4,
		LastTell=5,

	};
	MQ2MacroQuestType():MQ2Type("macroquest")
	{
		TypeMember(GameState);
	}

	~MQ2MacroQuestType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
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
		TypeMember(Abs);
		TypeMember(Rand);//2,
		TypeMember(Calc);//3,
		TypeMember(Sin);//4,
		TypeMember(Cos);//5,
		TypeMember(Tan);//6,
		TypeMember(Asin);//7,
		TypeMember(Acos);//8,
		TypeMember(Atan);//9,
		TypeMember(Hex);//10,
		TypeMember(Dec);//11,
		TypeMember(Not);//12,
	}

	~MQ2MathType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		return false;
	}
};

class MQ2RaceType : public MQ2Type
{
public:
	static enum RaceMembers
	{
		Name=1,
		ID=2,
	};
	MQ2RaceType():MQ2Type("race")
	{
		TypeMember(Name);
		TypeMember(ID);
	}

	~MQ2RaceType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		PCHAR pDesc=pEverQuest->GetRaceDesc(VarPtr.DWord);
		strcpy(Destination,pDesc);
		return true;
	}
};

class MQ2ClassType : public MQ2Type
{
public:
	static enum ClassMembers
	{
		Name=1,
		ShortName=2,
		ID=3
	};
	MQ2ClassType():MQ2Type("class")
	{
		TypeMember(Name);
		TypeMember(ShortName);
		TypeMember(ID);
	}

	~MQ2ClassType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		PCHAR pDesc=pEverQuest->GetClassDesc(VarPtr.DWord);
		strcpy(Destination,pDesc);
		return true;
	}
};
class MQ2BodyType : public MQ2Type
{
public:
	static enum BodyMembers
	{
		Name=1,
		ID=2
	};
	MQ2BodyType():MQ2Type("body")
	{
		TypeMember(Name);
		TypeMember(ID);
	}

	~MQ2BodyType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		PCHAR pDesc=pEverQuest->GetBodyTypeDesc(VarPtr.DWord);
		strcpy(Destination,pDesc);
		return true;
	}
};
class MQ2DeityType : public MQ2Type
{
public:
	static enum DeityMembers
	{
		Name=1,
		Team=2,
		ID=3
	};
	MQ2DeityType():MQ2Type("Deity")
	{
		TypeMember(Name);
		TypeMember(Team);
		TypeMember(ID);
	}

	~MQ2DeityType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		PCHAR pDesc=pEverQuest->GetDeityDesc(VarPtr.DWord);
		strcpy(Destination,pDesc);
		return true;
	}
};

#undef TypeMember