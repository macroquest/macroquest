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
EQLIB_VAR class MQ2CurrentZoneType *pCurrentZoneType;
EQLIB_VAR class MQ2ItemType *pItemType;
EQLIB_VAR class MQ2DeityType *pDeityType;
EQLIB_VAR class MQ2ArgbType *pArgbType;
EQLIB_VAR class MQ2TypeType *pTypeType;
EQLIB_VAR class MQ2TimeType *pTimeType;

EQLIB_VAR class MQ2HeadingType *pHeadingType;

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
		Equal=11,
		NotEqual=12,
		EqualCS=13,
		NotEqualCS=14,
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
		TypeMember(Equal);
		TypeMember(NotEqual);
		TypeMember(EqualCS);
		TypeMember(NotEqualCS);
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
		sprintf(Destination,"%.2f",VarPtr.Float);
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
#define nTicks (VarPtr.DWord)
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
			Dest.DWord=nTicks/600;
			Dest.Type=pIntType;
			return true;
		case Minutes:
			Dest.DWord=(nTicks/10)%60;
			Dest.Type=pIntType;
			return true;
		case Seconds:
			Dest.DWord=(nTicks*6)%60;
			Dest.Type=pIntType;
			return true;
		case Time:
			{
				int Secs=nTicks*6;
				int Mins=Secs/60;
				Secs=Secs%60;
				sprintf(Temp,"%d:%02d",Mins,Secs);
				Dest.Ptr=&Temp[0];
				Dest.Type=pStringType;
			}
			return true;
		case TotalMinutes:
			Dest.DWord=nTicks/10;
			Dest.Type=pIntType;
			return true;
		case TotalSeconds:
			Dest.DWord=nTicks*6;
			Dest.Type=pIntType;
			return true;
		case Ticks:
			Dest.DWord=nTicks;
			Dest.Type=pIntType;
			return true;
		}		
		return false;
#undef nTicks
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
		Casting=43,
		Mount=44,
		Swimming=45,
		Underwater=46,
		FeetWet=47,
		Animation=48,
		Holding=49,
		Look=50,
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
		TypeMember(Casting);
		TypeMember(Mount);
		TypeMember(Swimming);
		TypeMember(Underwater);
		TypeMember(FeetWet);
		TypeMember(Animation);
		TypeMember(Holding);
		TypeMember(Look);
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
		Gem=44,
		SpellReady=45,
		GroupLeaderExp=46,
		RaidLeaderExp=47,
		GroupLeaderPoints=48,
		RaidLeaderPoints=49,
		Drunk=50,
		STR=51,
		STA=52,
		CHA=53,
		DEX=54,
		INT=55,
		AGI=56,
		WIS=57,
		svMagic=58,
		svFire=59,
		svCold=60,
		svPoison=61,
		svDisease=62,
		Hunger=63,
		Thirst=64,
		BaseSTR=65,
		BaseSTA=66,
		BaseCHA=67,
		BaseDEX=68,
		BaseINT=69,
		BaseAGI=70,
		BaseWIS=71,
		PracticePoints=72,
		PctExp=73,
		PctAAExp=74,
		Moving=75,
		AbilityReady=76,
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
		TypeMember(Gem);
		TypeMember(SpellReady);
		TypeMember(GroupLeaderExp);
		TypeMember(RaidLeaderExp);
		TypeMember(GroupLeaderPoints);
		TypeMember(RaidLeaderPoints);
		TypeMember(Drunk);
		TypeMember(STR);//51,
		TypeMember(STA);//52,
		TypeMember(CHA);//53,
		TypeMember(DEX);//54,
		TypeMember(INT);//55,
		TypeMember(AGI);//56,
		TypeMember(WIS);//57,
		TypeMember(svMagic);//58,
		TypeMember(svFire);//59,
		TypeMember(svCold);//60,
		TypeMember(svPoison);//61,
		TypeMember(svDisease);//62
		TypeMember(Hunger);
		TypeMember(Thirst);
		TypeMember(BaseSTR);//51,
		TypeMember(BaseSTA);//52,
		TypeMember(BaseCHA);//53,
		TypeMember(BaseDEX);//54,
		TypeMember(BaseINT);//55,
		TypeMember(BaseAGI);//56,
		TypeMember(BaseWIS);//57,
		TypeMember(PracticePoints);
		TypeMember(PctExp);
		TypeMember(PctAAExp);
		TypeMember(Moving);
		TypeMember(AbilityReady);
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
		Dar=6
	};
	MQ2BuffType():MQ2Type("buff")
	{
		TypeMember(ID);
		TypeMember(Level);
		TypeMember(Spell);
		TypeMember(Mod);
		TypeMember(Duration);
		TypeMember(Dar);
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
		Price=15,
		Haste=16,
		Endurance=17,
		Attack=18,
		HPRegen=19,
		ManaRegen=20,
		DamShield=21,
		WeightReduction=22,
		SizeCapacity=23,
		Combinable=24,
		Skill=25,
		Avoidance=26,
		SpellShield=27,
		StrikeThrough=28,
		StunResist=29,
		Shielding=30,
		FocusID=31,
		ProcRate=32,
		Quality=33,
		LDoNCost=34,
		AugRestrictions=35,
		AugType=36,
		AugSlot1=37,
		AugSlot2=38,
		AugSlot3=39,
		AugSlot4=40,
		AugSlot5=41,
		Damage=42,
		Range=43,
		DMGBonus=44,
		RecommendedLevel=45,
		RecommendedSkill=46,
		Delay=47,
		Light=48,
		Level=49,
		BaneDMG=50,
		Proc=51,
		SkillModValue=52,
		InstrumentType=53,
		InstrumentMod=54,
		RequiredLevel=55,
		BaneDMGType=56,
		AC=57,
		HP=58,
		Mana=59,
		STR=60,
		STA=61,
		AGI=62,
		DEX=63,
		CHA=64,
		INT=65,
		WIS=66,
		svCold=67,
		svFire=68,
		svMagic=69,
		svDisease=70,
		svPoison=71,
		Summoned=72,
		Artifact=73,
		PendingLore=74,
		LoreText=75,
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
		TypeMember(Price);//15,
		TypeMember(Haste);//16,
		TypeMember(Endurance);//17,
		TypeMember(Attack);//18,
		TypeMember(HPRegen);//19,
		TypeMember(ManaRegen);//20,
		TypeMember(DamShield);//21,
		TypeMember(WeightReduction);//22,
		TypeMember(SizeCapacity);//23,
		TypeMember(Combinable);//24,
		TypeMember(Skill);//25,
		TypeMember(Avoidance);//26,
		TypeMember(SpellShield);//27,
		TypeMember(StrikeThrough);//28,
		TypeMember(StunResist);//29,
		TypeMember(Shielding);//30,
		TypeMember(FocusID);//31,
		TypeMember(ProcRate);//32,
		TypeMember(Quality);//33,
		TypeMember(LDoNCost);//34,
		TypeMember(AugRestrictions);//35,
		TypeMember(AugType);//36,
		TypeMember(AugSlot1);//37,
		TypeMember(AugSlot2);//38,
		TypeMember(AugSlot3);//39,
		TypeMember(AugSlot4);//40,
		TypeMember(AugSlot5);//41,
		TypeMember(Damage);//42,
		TypeMember(Range);//43,
		TypeMember(DMGBonus);//44,
		TypeMember(RecommendedLevel);//45,
		TypeMember(RecommendedSkill);//46,
		TypeMember(Delay);//47,
		TypeMember(Light);//48,
		TypeMember(Level);//49,
		TypeMember(BaneDMG);//50,
		TypeMember(Proc);//51,
		TypeMember(SkillModValue);//52,
		TypeMember(InstrumentType);//53,
		TypeMember(InstrumentMod);//54,
		TypeMember(RequiredLevel);//55,
		TypeMember(BaneDMGType);//56,
		TypeMember(AC);//57,
		TypeMember(HP);//58,
		TypeMember(Mana);//59,
		TypeMember(STR);//60,
		TypeMember(STA);//61,
		TypeMember(AGI);//62,
		TypeMember(DEX);//63,
		TypeMember(CHA);//64,
		TypeMember(INT);//65,
		TypeMember(WIS);//66,
		TypeMember(svCold);//67,
		TypeMember(svFire);//68,
		TypeMember(svMagic);//69,
		TypeMember(svDisease);//70,
		TypeMember(svPoison);//71,
		TypeMember(Summoned);//72,
		TypeMember(Artifact);//73,
		TypeMember(PendingLore);//74,
		TypeMember(LoreText);//75,
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
		HeadingTo=8,
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
		TypeMember(HeadingTo);
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
		Return=4,
	};
	MQ2MacroType():MQ2Type("macro")
	{
		TypeMember(Name);
		TypeMember(RunTime);
		TypeMember(Return);
	}

	~MQ2MacroType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		if (gRunning)
		{
			strcpy(Destination,gszMacroName);
			return true;
		}
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
      ID=3,
   };
   MQ2ZoneType():MQ2Type("zone")
   {
      TypeMember(Name);
      TypeMember(ShortName);//2,
      TypeMember(ID);//3,
   }

   ~MQ2ZoneType()
   {
   }

   bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
   {
      strcpy(Destination,&((PZONELIST)VarPtr.Int)->LongName[0]);
      return true;
   }
}; 

class MQ2CurrentZoneType : public MQ2Type
{
public:
	static enum CurrentZoneMembers
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
		ID=11,
	};
	MQ2CurrentZoneType():MQ2Type("currentzone")
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

	~MQ2CurrentZoneType()
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
		Merchant=6,
		Corpse=7,
		TradeTarget=8,
		Banker=9,

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
		Distance=13,
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
		TypeMember(Distance);
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

class MQ2TimeType : public MQ2Type
{
public:
	static enum TimeMembers
	{
		Hour=1,
		Minute=2,
		Second=3,
		DayOfWeek=4,
		Day=5,
		Month=6,
		Year=7,
		Time12=8,
		Time24=9,
		Date=10,
		Night=11
	};
	MQ2TimeType():MQ2Type("time")
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
	}

	~MQ2TimeType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		struct tm *Now=(struct tm*)VarPtr.Ptr;
		sprintf(Destination,"%02d:%02d:%02d",Now->tm_hour,Now->tm_min, Now->tm_sec);
		return true;
	}
};

class MQ2TypeType : public MQ2Type
{
public:
   static enum TypeMembers
   {
      Name=1,
	  TypeMember=2,
   };
   MQ2TypeType():MQ2Type("type")
   {
      TypeMember(Name);
	  AddMember((DWORD)TypeMember,"Member");
   }

   ~MQ2TypeType()
   {
   }

   bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

   bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
   {
	  strcpy(Destination,((MQ2Type*)VarPtr.Ptr)->GetName());
      return true;
   }
}; 

class MQ2HeadingType : public MQ2Type
{
public:
   static enum HeadingMembers
   {
      Name=1,
	  ShortName=2,
	  Degrees=3,
	  Clock=4,
   };
   MQ2HeadingType():MQ2Type("heading")
   {
      TypeMember(Name);
	  TypeMember(ShortName);
	  TypeMember(Degrees);
	  TypeMember(Clock);
   }

   ~MQ2HeadingType()
   {
   }

   bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest);

   bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
   {
	  strcpy(Destination,szHeadingShort[(INT)(VarPtr.Float/ 22.5f + 0.5f)%16]);
      return true;
   }
}; 


#undef TypeMember