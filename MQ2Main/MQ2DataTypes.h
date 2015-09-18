/*****************************************************************************
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
******************************************************************************/

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

#ifdef ISXEQ
#pragma warning(disable:4996)
#endif
#ifdef ISXEQ_LEGACY
#pragma warning(disable:4996)
#endif

#ifndef ISXEQ
#define pIntPtrType pIntType
#define pInt64PtrType pInt64Type
#define pBytePtrType pByteType
#define pBoolPtrType pBoolType
#define pFloatPtrType pFloatType
#define pDoublePtrType pDoubleType

#define INTPTR(x) Dest.DWord=x
#define INT64PTR(x) Dest.Int64=x
#define BYTEPTR(x) Dest.Byte=x
#define BOOLPTR(x) Dest.DWord=x
#define FLOATPTR(x) Dest.Float=x
#define DOUBLEPTR(x) Dest.Double=x

#define TypeMember(name) AddMember((DWORD)name,""#name)
#define TypeMethod(x)
#define AddMethod(x,y)
#else
#define INTPTR(x) Dest.Ptr=&x
#define BYTEPTR(x) Dest.Ptr=&x
#define BOOLPTR(x) Dest.Ptr=&x
#define FLOATPTR(x) Dest.Ptr=&x

#define Argb RGB
#define MQ2VARPTR LSVARPTR
#endif

// Datatype Declarations
#define DATATYPE(_class_, _var_, _inherits_, _persistentclass_) LEGACY_VAR class _class_ *_var_;
#include "DataTypeList.h"
#undef DATATYPE

#ifndef ISXEQ
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
    bool GETMEMBER()
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

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.DWord=Source.DWord;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        VarPtr.DWord=0;
        if (!stricmp(Source,"TRUE"))
            VarPtr.DWord=1;
        else if (atof(Source)!=0.0f)
            VarPtr.DWord=1;
        return true;
    }
};
class MQ2IntType : public MQ2Type
{
public:
    static enum IntMembers
    {
        Float=1,
        Double=2,
        Hex=3,
        Reverse=4,
    };
    MQ2IntType():MQ2Type("int")
    {
        TypeMember(Float);
        TypeMember(Double);
        TypeMember(Hex);
        TypeMember(Reverse);
    }

    ~MQ2IntType()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        itoa(VarPtr.Int,Destination,10);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.Int=Source.Int;
        return true;
    }

    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        VarPtr.Int=atoi(Source);
        return true;
    }
};

class MQ2Int64Type : public MQ2Type
{
public:
    static enum Int64Members
    {
        Float=1,
        Double=2,
        Hex=3,
        Reverse=4,
    };
    MQ2Int64Type():MQ2Type("int64")
    {
        TypeMember(Float);
        TypeMember(Double);
        TypeMember(Hex);
        TypeMember(Reverse);
    }

    ~MQ2Int64Type()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        _i64toa(VarPtr.Int64,Destination,10);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.Int64=Source.Int64;
        return true;
    }

    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        VarPtr.Int64=_atoi64(Source);
        return true;
    }
};

#endif
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


    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        sprintf(Destination,"%x",VarPtr.Int);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.DWord=Source.DWord;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        sscanf(Source,"%x",&VarPtr.Int);
        return true;
    }
};
#ifndef ISXEQ
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
    bool GETMEMBER()
    {
        return false;
    }

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        itoa(VarPtr.Int,Destination,10);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.DWord=Source.DWord%0xFF;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        VarPtr.DWord=atoi(Source)%0xFF;
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
        Count=15,
        Token=16,
        Replace=17
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
        TypeMember(Count);
        TypeMember(Token);
        TypeMember(Replace);
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
    void InitVariable(MQ2VARPTR &VarPtr) 
    {
        VarPtr.Ptr=malloc(MAX_STRING);
        ZeroMemory(VarPtr.Ptr,MAX_STRING);
    }
    void FreeVariable(MQ2VARPTR &VarPtr)
    {
        free(VarPtr.Ptr);
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pStringType)
            return false;
        strcpy((char*)VarPtr.Ptr,(char*)Source.Ptr);
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        strcpy((char*)VarPtr.Ptr,Source);
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
        Raw=6,
    };

    MQ2FloatType():MQ2Type("float")
    {
        TypeMember(Deci);
        TypeMember(Centi);
        TypeMember(Milli);
        TypeMember(Int);
        TypeMember(Precision);
        TypeMember(Raw);
    }

    ~MQ2FloatType()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        sprintf(Destination,"%.2f",VarPtr.Float);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pFloatType && Source.Type!=(MQ2Type*)pHeadingType)
            VarPtr.Float=(FLOAT)Source.DWord;
        else
            VarPtr.Float=Source.Float;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        VarPtr.Float=(FLOAT)atof(Source);
        return true;
    }
};
class MQ2DoubleType : public MQ2Type
{
public:
    static enum DoubleMembers
    {
        Deci=1,
        Centi=2,
        Milli=3,
        Int=4,
        Precision=5,
    };

    MQ2DoubleType():MQ2Type("double")
    {
        TypeMember(Deci);
        TypeMember(Centi);
        TypeMember(Milli);
        TypeMember(Int);
        TypeMember(Precision);
    }

    ~MQ2DoubleType()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        sprintf(Destination,"%.2f",VarPtr.Double);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pDoubleType && Source.Type!=(MQ2Type*)pHeadingType)
            VarPtr.Double=Source.Double;
        else
			VarPtr.Double=Source.Double;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
		VarPtr.Double=atof(Source);
        return true;
    }
};
#endif

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
        TimeHMS=8,
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
        TypeMember(TimeHMS);
    }

    ~MQ2TicksType()
    {
    }

    bool GETMEMBER();


    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        itoa(VarPtr.DWord,Destination,10);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.DWord=Source.DWord;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        VarPtr.DWord=atoi(Source);
        return true;
    }
};
class MQ2TimeStampType : public MQ2Type
{
public:
    static enum TimeStampMembers
    {
        Hours=1,
        Minutes=2,
        Seconds=3,
        Time=4,
        TotalMinutes=5,
        TotalSeconds=6,
        Ticks=7,
        TimeHMS=8,
    };
    MQ2TimeStampType():MQ2Type("timestamp")
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

    ~MQ2TimeStampType()
    {
    }

    bool GETMEMBER();


    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
		/* Note -- if you get an error compiling this for ISXSDK,  
			error C2039 : 'UInt64' : is not a member of '_LSVarPtr' 
			Then add "unsigned __int64 UInt64;" under the Int64 definition in _LSVarPtr and _LSTypeVar in ISXDK\include\LavishScript\LSType.h 
			This should be fixed in ISXDK35 or higher. 
		*/ 
		_i64toa(VarPtr.UInt64,Destination,10); 
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.UInt64=Source.UInt64;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        VarPtr.UInt64=_atoi64(Source);
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
        FeetWet=45,
        Underwater=46,
        Animation=48,
        Holding=49,
        Look=50,
        N=51,
        W=52,
        U=53,
        S=54,
        E=55,
        D=56,
        DistanceN=57,
        DistanceW=58,
        DistanceU=59,
        Invis=60,
        Linkdead=61,
        LFG=62,
        Trader=63,
        AFK=64,
        xConColor=65,
        Standing=67,
        Sitting=68,
        Ducking=69,
        Feigning=70,
        Binding=71,
        Invited=72,
        NearestSpawn=73,
        MaxRangeTo=74,
        DisplayName=75,
        AATitle=76,
        xGroupLeader=77,
        Mark=78,
        Assist=79,
        Anonymous=80,
        Roleplaying=81,
        xLineOfSight=82,
        HeadingToLoc=83,
        Title=84,
        Suffix=85,
        Fleeing=86,
        Named=87,
        Buyer=88,
        Moving=89,
        StandState=90,
        Dead=91,
        Stunned=92,
        Hovering=93,
        CurrentMana=94,
        MaxMana=95,
        CurrentEndurance=96,
		PctEndurance=97,
        MaxEndurance=98,
        Loc=99,
        LocYX=100,
		LocYXZ=101,
        Owner=102,
        Following=103,
		Address=104,
		Inviter=105,
		MercID=106,
		ContractorID=107,
		PctMana=108,
		Primary=109,
		Secondary=110,
		Equipment=111,
		xTargetable=112,
		PlayerState=113,
		Stuck=114,
		Aggressive=115,
	};
    static enum SpawnMethods
    {
        Target=1,
        Face=2,
        xAssist=4,
        LeftClick=5,
        RightClick=6,
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
        TypeMember(DistanceN);//7,
        TypeMember(DistanceW);//8,
        TypeMember(DistanceU);//9,
        TypeMember(Invis);
        TypeMember(Linkdead);
        TypeMember(LFG);
        TypeMember(Trader);
        TypeMember(AFK);
        AddMember(xConColor,"ConColor");
        TypeMember(Standing);//=67,
        TypeMember(Sitting);//68,
        TypeMember(Ducking);//=69,
        TypeMember(Feigning);//=70,
        TypeMember(Binding);//=71,
        TypeMember(Invited);
        TypeMember(NearestSpawn);
        TypeMember(MaxRangeTo);
        TypeMember(DisplayName);
        TypeMember(AATitle);
        AddMember(xGroupLeader,"GroupLeader");
        TypeMember(Mark);
        TypeMember(Assist);
        TypeMember(Anonymous);
        TypeMember(Roleplaying);
        AddMember(xLineOfSight,"LineOfSight");
        TypeMember(HeadingToLoc);
        TypeMember(Title);  //84
        TypeMember(Suffix); //85
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
		AddMember(xTargetable,"Targetable");
		TypeMember(PlayerState);
		TypeMember(Stuck);
		TypeMember(Aggressive);
		
        TypeMethod(Target);
        TypeMethod(Face);
        TypeMethod(LeftClick);
        TypeMethod(RightClick);
        AddMethod(xAssist,"Assist");
    }

    ~MQ2SpawnType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (!VarPtr.Ptr)
            return false;
        strcpy(Destination,((PSPAWNINFO)VarPtr.Ptr)->Name);
        return true;
    }
    void InitVariable(MQ2VARPTR &VarPtr) 
    {
        VarPtr.Ptr=malloc(sizeof(SPAWNINFO));
        ZeroMemory(VarPtr.Ptr,sizeof(SPAWNINFO));
    }
    void FreeVariable(MQ2VARPTR &VarPtr) 
    {
        free(VarPtr.Ptr);
    }

    virtual bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type==pSpawnType)
        {
            memcpy(VarPtr.Ptr,Source.Ptr,sizeof(SPAWNINFO));
            return true;
        }
        else
        {
            if (PSPAWNINFO pOther=(PSPAWNINFO)GetSpawnByID(Source.DWord))
            {
                memcpy(VarPtr.Ptr,pOther,sizeof(SPAWNINFO));
                return true;
            }
        }
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        if (PSPAWNINFO pOther=(PSPAWNINFO)GetSpawnByID(atoi(Source)))
        {
            memcpy(VarPtr.Ptr,pOther,sizeof(SPAWNINFO));
            return true;
        }
        return false;
    }
};

class MQ2CharacterType : public MQ2Type
{
public:
    static enum CharacterMembers
    {
		CountSongs=2,
		MaxBuffSlots=3,
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
        Cash=24,
        CashBank=25,
        PlatinumShared=26,
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
        Combat=42,
        FreeInventory=43,
        Gem=44,
        SpellReady=45,
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
        PetBuff=77,
        Platinum=78,
        Gold=79,
        Silver=80,
        Copper=81,
        PlatinumBank=82,
        GoldBank=83,
        SilverBank=84,
        CopperBank=85,
        Stunned=88,
        RangedReady=89,
        AltTimerReady=90,
        MaxEndurance=91,
        PctEndurance=92,
        AltAbility=93,  
        AltAbilityReady=94,
        AltAbilityTimer=95,
        CombatAbility=96,
        CombatAbilityTimer=97,
        LargestFreeInventory=98,
        TargetOfTarget=99,
        RaidAssistTarget=100,
        GroupAssistTarget=101,
        RaidMarkNPC=102,
        GroupMarkNPC=103,
        CountBuffs=104,
        LanguageSkill=105,
        EnduranceBonus=106,
        CombatEffectsBonus=107,
        ShieldingBonus=108,
        SpellShieldBonus=109,
        AvoidanceBonus=110,
        AccuracyBonus=111,
        StunResistBonus=112,
        StrikeThroughBonus=113,
        AttackBonus=114,
        HPRegenBonus=115,
        ManaRegenBonus=116,
        DamageShieldBonus=117,
        DoTShieldBonus=118,
        AttackSpeed=119,
        GroupList=120,
        AmIGroupLeader=121,
        CurrentEndurance=122,
        EnduranceRegen=123,
        FreeBuffSlots=124,
        CurrentWeight=125,
        AAPointsSpent=126,
        AAPointsTotal=127,
        TributeActive=128,
        CombatAbilityReady=129,
        Running=130,
        GroupSize=131,
        TributeTimer=132,
        RadiantCrystals=133,
        EbonCrystals=134,
        Shrouded=135,
        AutoFire=136,
        Language=137,
        Aura=138,
        LAMarkNPC=139,
        LANPCHealth=140,
        LADelegateMA=141,
        LADelegateMarkNPC=142,
        LAInspectBuffs=143,
        LASpellAwareness=144,
        LAOffenseEnhancement=145,
        LAManaEnhancement=146,
        LAHealthEnhancement=147,
        LAHealthRegen=148,
        LAFindPathPC=149,
        LAHoTT=150,
        ActiveFavorCost=151,
        CombatState=152,
        svCorruption=153,
        svPrismatic=154,
        svChromatic=155,
        Doubloons=156,
        Orux=157,
        Phosphenes=158,
        Phosphites=159,
        Fellowship=160,
        Downtime=161,
        DamageShieldMitigationBonus=162,
        HeroicSTRBonus=163,
        HeroicINTBonus=164,
        HeroicWISBonus=165,
        HeroicAGIBonus=166,
        HeroicDEXBonus=167,
        HeroicSTABonus=168,
        HeroicCHABonus=169,
        HealAmountBonus=170,
        SpellDamageBonus=171,
        ClairvoyanceBonus=172,
        EnduranceRegenBonus=173,
        Counters=174,
        Faycites=175,
        Chronobines=176,
        Mercenary=177,
        XTarget=178,
        Haste=179,
        MercenaryStance=180,
        SkillCap=181,
        GemTimer=182,
        HaveExpansion=183,
        PctAggro=184,
        SecondaryPctAggro=185,
        SecondaryAggroPlayer=186,
        AggroLock=187,
        ZoneBound=188,
        ZoneBoundX=189,
        ZoneBoundY=190,
        ZoneBoundZ=191,
		PctMercAAExp=192,
		MercAAExp=193,
		Subscription=194,
		AAPointsAssigned=195,
		AltCurrency=196,
		ActiveDisc=197,
		Slowed=198,
		Rooted=199,
		Mezzed=200,
		Snared=201,
		Hasted=202,
		Commemoratives=203,
		Nobles=204,
		Zoning=205,
		DSed=206,
		RevDSed=207,
		InInstance=208,
		Instance=209,
		MercListInfo=210,
		UseAdvancedLooting=211,
		Fists=212,
		EnergyCrystals=213,
		PiecesofEight=214,
		SpellInCooldown=215,
    };
    static enum CharacterMethods
    {
        Stand, 
        Sit, 
        Dismount, 
    };
    MQ2CharacterType():MQ2Type("character")
    {
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
        TypeMember(Cash);//24,
        TypeMember(CashBank);//25,
        TypeMember(PlatinumShared);//26,
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
        TypeMember(Combat);
        TypeMember(FreeInventory);
        TypeMember(Gem);
        TypeMember(SpellReady);
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
        TypeMember(RaidAssistTarget);//=100,
        TypeMember(GroupAssistTarget);//=101,
        TypeMember(RaidMarkNPC);//=102,
        TypeMember(GroupMarkNPC);//=103
        TypeMember(CountBuffs);
        TypeMember(LanguageSkill); //105
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
        TypeMember(AttackSpeed); //119
        TypeMember(GroupList); 
        TypeMember(AmIGroupLeader); //121
        TypeMember(CurrentEndurance);
        TypeMember(EnduranceRegen);
        TypeMember(FreeBuffSlots); //124
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
        TypeMember(Counters);
        TypeMember(Faycites);
        TypeMember(Chronobines);
        TypeMember(Mercenary);
        TypeMember(XTarget);
        TypeMember(Haste);
        TypeMember(MercenaryStance);
        TypeMember(SkillCap);  // 181
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
		TypeMember(Slowed);
		TypeMember(Rooted);
		TypeMember(Mezzed);
		TypeMember(Snared);
		TypeMember(Hasted);
		TypeMember(Commemoratives);
		TypeMember(Nobles);
		TypeMember(Zoning);
		TypeMember(DSed);
		TypeMember(RevDSed);
		TypeMember(InInstance);
		TypeMember(Instance);
		TypeMember(MercListInfo);
		TypeMember(UseAdvancedLooting);
		TypeMember(Fists);
		TypeMember(EnergyCrystals);
		TypeMember(PiecesofEight);
		TypeMember(SpellInCooldown);
		
        TypeMethod(Stand); 
        TypeMethod(Sit); 
        TypeMethod(Dismount); 
    }

    ~MQ2CharacterType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();
    INHERITINDIRECT(pSpawnType,Temp.Ptr=((PCHARINFO)ObjectData.Ptr)->pSpawn,0);

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (!pLocalPlayer)
            return false;
        strcpy(Destination,((PSPAWNINFO)pLocalPlayer)->Name);
        return true;
    }
    void InitVariable(MQ2VARPTR &VarPtr) 
    {
        VarPtr.Ptr=malloc(sizeof(CHARINFO));
        ZeroMemory(VarPtr.Ptr,sizeof(CHARINFO));
    }
    void FreeVariable(MQ2VARPTR &VarPtr) 
    {
        free(VarPtr.Ptr);
    }

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pCharacterType)
            return false;
        memcpy(VarPtr.Ptr,Source.Ptr,sizeof(CHARINFO));
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
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
        CastOnYou=19, 
        CastOnAnother=20, 
        WearOff=21, 
        CounterType=22,
        CounterNumber=23,
        Stacks=24,
        StacksPet=25,
        WillStack=26,
        MyRange=27,
        Address=28,
		EnduranceCost=29,
		MaxLevel=30,
		Category=31,
		Subcategory=32,
		Restrictions=33,
		Base=34,
		Base2=35,
		Max=36,
		Calc=37,
		Attrib=38,
		AutoCast=39,
		Extra=40,
		RecastTimerID=41,
		SPA=42,
		ReagentID=43,
		ReagentCount=44,
		CastByOther=45,
		TimeOfDay=46,
		DurationWindow=47,
		CanMGB=48,
		Deletable=49,
		BookIcon=50,
		Target=51,
		Description=52,
		StacksWith=53,
		Caster=54,
		Rank=55,
		RankName=56,
		SpellGroup=57,
		SubSpellGroup=58,
		Beneficial=59,
		xIsActiveAA=60,
    };
    static enum SpellMethods
    {
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
        TypeMember(CastOnYou);//19, 
        TypeMember(CastOnAnother);//20, 
        TypeMember(WearOff);//21, 
        TypeMember(CounterType);//22,
        TypeMember(CounterNumber);//23,
        TypeMember(Stacks);//24,
        TypeMember(StacksPet);//25,
        TypeMember(WillStack);//26,
        TypeMember(MyRange);//27
        TypeMember(Address);//28
		TypeMember(EnduranceCost);//29
		TypeMember(MaxLevel);//30
		TypeMember(Category);//31
		TypeMember(Subcategory);//32
		TypeMember(Restrictions);//33
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
		AddMember(xIsActiveAA,"IsActiveAA");
		
    }

    ~MQ2SpellType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (!VarPtr.Ptr)
            return false;
        strcpy(Destination,((PSPELL)VarPtr.Ptr)->Name);
        return true;
    }
    void InitVariable(MQ2VARPTR &VarPtr) 
    {
        VarPtr.Ptr=malloc(sizeof(SPELL));
        ZeroMemory(VarPtr.Ptr,sizeof(SPELL));
    }
    void FreeVariable(MQ2VARPTR &VarPtr) 
    {
        free(VarPtr.Ptr);
    }

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pSpellType)
            return false;
        memcpy(VarPtr.Ptr,Source.Ptr,sizeof(SPELL));
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};

class MQ2BuffType : public MQ2Type
{
public:
    static enum BuffMembers
    {
        Address=1,
        ID=2,
        Level=3,
        Spell=4,
        Mod=5,
        Duration=6,
        Dar=7,
        Counters=8,
		HitCount=9,
    };
    static enum BuffMethods
    {
        Remove=1,
    };
    MQ2BuffType():MQ2Type("buff")
    {
        TypeMember(Address);
        TypeMember(ID);
        TypeMember(Level);
        TypeMember(Spell);
        TypeMember(Mod);
        TypeMember(Duration);
        TypeMember(Dar);
        TypeMember(Counters);
        TypeMember(HitCount);

        TypeMethod(Remove);
    }

    ~MQ2BuffType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();
    INHERITINDIRECT(pSpellType,Temp.Ptr=GetSpellByID(((PSPELLBUFF)ObjectData.Ptr)->SpellID),0);
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
    void InitVariable(MQ2VARPTR &VarPtr) 
    {
        VarPtr.Ptr=malloc(sizeof(SPELLBUFF));
        ZeroMemory(VarPtr.Ptr,sizeof(SPELLBUFF));
    }
    void FreeVariable(MQ2VARPTR &VarPtr)
    {
        free(VarPtr.Ptr);
    }

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pBuffType)
            return false;
        memcpy(VarPtr.Ptr,Source.Ptr,sizeof(SPELLBUFF));
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};
class MQ2TargetBuffType : public MQ2Type
{
public:
    static enum TargetBuffMembers
    {
        Address=1,
        xIndex=2,
        Duration=3,
    };
    MQ2TargetBuffType():MQ2Type("targetbuff")
    {
        TypeMember(Address);
		AddMember(xIndex,"Index");
        TypeMember(Duration);
    }

    ~MQ2TargetBuffType()
    {
    }
	//buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
    bool GETMEMBER();
    //DECLAREGETMETHOD();
    INHERITINDIRECT(pSpellType,Temp.Ptr=GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[ObjectData.Int]),0);
    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (VarPtr.Int==-1)
            return false;
		int buffid = ((PCTARGETWND)pTargetWnd)->BuffSpellID[VarPtr.Int];
        if (buffid > 0)
        {
            if (PSPELL pSpell=GetSpellByID(buffid))
            {
                strcpy(Destination,pSpell->Name);
                return true;
            }
        }
        return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.Int=Source.Int;
        return true;
    }

    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        VarPtr.Int=atoi(Source);
        return true;
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
        BuyPrice=15,
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
        AugSlot6=42,
        Damage=43,
        Range=44,
        DMGBonus=45,
        RecommendedLevel=46,
        RecommendedSkill=47,
        Delay=48,
        Light=49,
        Level=50,
        BaneDMG=51,
        Proc=52,
        SkillModValue=53,
        InstrumentType=54,
        InstrumentMod=55,
        RequiredLevel=56,
        BaneDMGType=57,
        AC=58,
        HP=59,
        Mana=60,
        STR=61,
        STA=62,
        AGI=63,
        DEX=64,
        CHA=65,
        INT=66,
        WIS=67,
        svCold=68,
        svFire=69,
        svMagic=70,
        svDisease=71,
        svPoison=72,
        Summoned=73,
        Artifact=74,
        PendingLore=75,
        LoreText=76,
        Items=77,
        Item=78,
        Container=79,
        Stackable=80,
        InvSlot=81,
        SellPrice=82,
        WornSlot=83,
        WornSlots=84,
        CastTime=85,
        Spell=86,
        EffectType=87,
        Tribute=88,
        Attuneable=89,
        Timer=90,
        ItemDelay=91,
        TimerReady=92,
        StackSize=93,
        Stacks=94,
        StackCount=95,
        FreeStack=96,
        MerchQuantity=97,
        Classes=98,
        Class=99,
        Races=100,
        Race=101,
        Deities=102,
        Deity=103,
        Evolving=104,
        svCorruption=105,
        Power=106,
        MaxPower=107,
        Purity=108,
        Accuracy=109,
        CombatEffects=110,
        DoTShielding=111,
        HeroicSTR=112,
        HeroicINT=113,
        HeroicWIS=114,
        HeroicAGI=115,
        HeroicDEX=116,
        HeroicSTA=117,
        HeroicCHA=118,
        HeroicSvMagic=119,
        HeroicSvFire=120,
        HeroicSvCold=121,
        HeroicSvDisease=122,
        HeroicSvPoison=123,
        HeroicSvCorruption=124,
        EnduranceRegen=125,
        HealAmount=126,
        Clairvoyance=127,
        DamageShieldMitigation=128,
        SpellDamage=129,
        Augs=130,
        Tradeskills=131,
		ItemSlot=132,
		ItemSlot2=133,
		Address=134,
		PctPower=135,
		Prestige=136,
		FirstFreeSlot=137,
		SlotsUsedByItem=138,
		Heirloom=139,
		Collectible=140,
		NoDestroy=141,
		Quest=142,
		Expendable=143,
		ContAddress = 144,
		ItemLink = 145,
		Icon = 146,
    };
    static enum ItemMethods
    {
    };
    MQ2ItemType():MQ2Type("item")
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
        TypeMember(BuyPrice);//15,
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
        TypeMember(Proc);
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
        TypeMember(Timer);//89,
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
    }

    ~MQ2ItemType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (!VarPtr.Ptr)
            return false;
        strcpy(Destination,GetItemFromContents((PCONTENTS)VarPtr.Ptr)->Name);
        return true;
    }
    void InitVariable(MQ2VARPTR &VarPtr) 
    {
        VarPtr.Ptr=malloc(sizeof(CONTENTS));
        ZeroMemory(VarPtr.Ptr,sizeof(CONTENTS));
    }
    void FreeVariable(MQ2VARPTR &VarPtr) 
    {
        free(VarPtr.Ptr);
    }

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pItemType)
            return false;
        memcpy(VarPtr.Ptr,Source.Ptr,sizeof(CONTENTS));
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
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
        N=14,
        W=15,
        U=16,
        DefaultN=17,
        DefaultW=18,
        DefaultU=19,
        xLineOfSight=20,
		Address=21,
		Distance3D=22,
    };
    static enum SwitchMethods
    {
        Toggle=1,
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
        AddMember(xLineOfSight,"LineOfSight");
        TypeMember(Address);//21,
        TypeMember(Distance3D);//22,
    }

    ~MQ2SwitchType()
    {
        TypeMethod(Toggle);
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (VarPtr.Ptr)
        {
            itoa(((PDOOR)VarPtr.Ptr)->ID,Destination,10);
            return true;
        }
        return false;
    }
    void InitVariable(MQ2VARPTR &VarPtr) 
    {
        VarPtr.Ptr=malloc(sizeof(DOOR));
        ZeroMemory(VarPtr.Ptr,sizeof(DOOR));
    }
    void FreeVariable(MQ2VARPTR &VarPtr) 
    {
        free(VarPtr.Ptr);
    }

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pSwitchType)
            return false;
        memcpy(VarPtr.Ptr,Source.Ptr,sizeof(DOOR));
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
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
        HeadingTo=8,
        N=9,
        W=10,
        U=11,
        xLineOfSight=12,
        Address=13,
    };
    static enum GroundMethods
    {
        Grab=1,
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
        AddMember(xLineOfSight,"LineOfSight");
        TypeMethod(Grab);
        TypeMember(Address);
    }

    ~MQ2GroundType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (VarPtr.Ptr)
        {
            itoa(((PGROUNDITEM)VarPtr.Ptr)->DropID,Destination,10);
            return true;
        }
        return false;
    }
    void InitVariable(MQ2VARPTR &VarPtr) 
    {
        VarPtr.Ptr=malloc(sizeof(GROUNDITEM));
        ZeroMemory(VarPtr.Ptr,sizeof(GROUNDITEM));
    }
    void FreeVariable(MQ2VARPTR &VarPtr) 
    {
        free(VarPtr.Ptr);
    }

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pGroundType)
            return false;
        memcpy(VarPtr.Ptr,Source.Ptr,sizeof(GROUNDITEM));
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};


class MQ2CorpseType : public MQ2Type
{
public:
    static enum CorpseMembers
    {
        Open=1,
        Item=2,
        Items=3,
    };
    static enum CorpseMethods
    {
    };
    MQ2CorpseType():MQ2Type("corpse")
    {
        TypeMember(Open);
        TypeMember(Item);
        TypeMember(Items);
    }

    ~MQ2CorpseType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (pActiveCorpse && pLootWnd)
        {
            strcpy(Destination,"TRUE");
        }
        else
        {
            strcpy(Destination,"FALSE");
        }
        return true;
    }

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};

class MQ2MerchantType : public MQ2Type
{
public:
    static enum MerchantMembers
    {
        Markup=1,
        Item=2,
        Items=3,
        Open=4,
        Full=5,
    };
    static enum MerchantMethods
    {
    };
    MQ2MerchantType():MQ2Type("merchant")
    {
        TypeMember(Markup);
        TypeMember(Item);
        TypeMember(Items);
        TypeMember(Open);
        TypeMember(Full);
    }

    ~MQ2MerchantType()
    {

    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (pActiveMerchant && pMerchantWnd)
        {
            strcpy(Destination,"TRUE");
        }
        else
        {
            strcpy(Destination,"FALSE");
        }
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};
class MQ2MercenaryType : public MQ2Type
{
public:
    static enum MercenaryMembers
    {
		AAPoints=1,
		Stance=2,
        State=3,
		StateID=4,
		xIndex=5,
#ifdef MULETESTING
		CurrentHPs=6,
		MaxHPs=7,
		PctHPs=8,
		CurrentMana=9,
		MaxMana=10,
		PctMana=11,
		AC=12,
		AGI=13,
		Attack=14,
		CHA=15,
		CombatEnduranceRegen=16,
		CombatHPRegen=17,
		CurrentEndurance=18, 
		MaxEndurance=19,
		PctEndurance=20,
		DEX=21, 
		Haste=22,
		HealAmount=23,
		INT=24,
		SpellDamage=25,
		STA=26,
		STR=27, 
		WIS=28,
#endif
    };
    static enum MercenaryMethods
    {
    };
    MQ2MercenaryType():MQ2Type("mercenary")
    {
        TypeMember(AAPoints);
        TypeMember(Stance);
        TypeMember(State);
        TypeMember(StateID);
		AddMember(xIndex,"Index");
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

    ~MQ2MercenaryType()
    {

    }
	bool GETMEMBER();
    //DECLAREGETMETHOD();
    INHERITDIRECT(pSpawnType);

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (!VarPtr.Ptr)
            return false;
        strcpy(Destination,((PSPAWNINFO)VarPtr.Ptr)->Name);
        return true;
    }
    void InitVariable(MQ2VARPTR &VarPtr) 
    {
        VarPtr.Ptr=malloc(sizeof(SPAWNINFO));
        ZeroMemory(VarPtr.Ptr,sizeof(SPAWNINFO));
    }
    void FreeVariable(MQ2VARPTR &VarPtr) 
    {
        free(VarPtr.Ptr);
    }

    virtual bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type==pSpawnType)
        {
            memcpy(VarPtr.Ptr,Source.Ptr,sizeof(SPAWNINFO));
            return true;
        }
        else
        {
            if (PSPAWNINFO pOther=(PSPAWNINFO)GetSpawnByID(Source.DWord))
            {
                memcpy(VarPtr.Ptr,pOther,sizeof(SPAWNINFO));
                return true;
            }
        }
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        if (PSPAWNINFO pOther=(PSPAWNINFO)GetSpawnByID(atoi(Source)))
        {
            memcpy(VarPtr.Ptr,pOther,sizeof(SPAWNINFO));
            return true;
        }
        return false;
    }
};
class MQ2PetType : public MQ2Type
{
public:
    static enum PetMembers
    {
        Buff=1,
        Combat=2,
		GHold=3,
		Hold=4,
		ReGroup=5,
		Stance=6,
		Stop=7,
		Target=8,
		Taunt=9,
		BuffDuration=10,
    };
    static enum PetMethods
    {
    };
    MQ2PetType():MQ2Type("pet")
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

    ~MQ2PetType()
    {

    }
	bool GETMEMBER();
    //DECLAREGETMETHOD();
	//INHERITINDIRECT(pSpawnType,Temp.Ptr=GetSpawnByID(((PCHARINFO)ObjectData.Ptr)->pSpawn->PetID),0);
    INHERITDIRECT(pSpawnType);

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (!VarPtr.Ptr)
            return false;
        strcpy(Destination,((PSPAWNINFO)VarPtr.Ptr)->Name);
        return true;
    }
    void InitVariable(MQ2VARPTR &VarPtr) 
    {
        VarPtr.Ptr=malloc(sizeof(SPAWNINFO));
        ZeroMemory(VarPtr.Ptr,sizeof(SPAWNINFO));
    }
    void FreeVariable(MQ2VARPTR &VarPtr) 
    {
        free(VarPtr.Ptr);
    }

    virtual bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type==pSpawnType)
        {
            memcpy(VarPtr.Ptr,Source.Ptr,sizeof(SPAWNINFO));
            return true;
        }
        else
        {
            if (PSPAWNINFO pOther=(PSPAWNINFO)GetSpawnByID(Source.DWord))
            {
                memcpy(VarPtr.Ptr,pOther,sizeof(SPAWNINFO));
                return true;
            }
        }
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        if (PSPAWNINFO pOther=(PSPAWNINFO)GetSpawnByID(atoi(Source)))
        {
            memcpy(VarPtr.Ptr,pOther,sizeof(SPAWNINFO));
            return true;
        }
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
        List=23,
        Checked=24,
        Style=25,
        Enabled=26,
        Highlighted=27,
        Name=28,
        ScreenID=29,
        Type=30,
        Items=31,
        HisTradeReady=32,
        MyTradeReady=33,
		GetCurSel=34,
		Address=35,
    };
    static enum WindowMethods
    {
        LeftMouseDown=1,
        LeftMouseUp=2,
        LeftMouseHeldDown=3,
        LeftMouseHeldUp=4,
        RightMouseDown=5,
        RightMouseUp=6,
        RightMouseHeldDown=7,
        RightMouseHeldUp=8,
        ListSelect=9,
        ComboSelect=10,
    };
#ifdef ISBOXER_COMPAT
    MQ2WindowType():MQ2Type("eqwindow")
#else
    MQ2WindowType():MQ2Type("window")
#endif
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
        TypeMember(Minimized);//14,
        TypeMember(X);//15,
        TypeMember(Y);//16,
        TypeMember(Height);//17,
        TypeMember(Width);//18,
        TypeMember(MouseOver);//19,
        TypeMember(BGColor);//20,
        TypeMember(Text);//21,
        TypeMember(Tooltip);//22,
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


        TypeMethod(LeftMouseDown);
        TypeMethod(LeftMouseUp);
        TypeMethod(LeftMouseHeldDown);
        TypeMethod(LeftMouseHeldUp);
        TypeMethod(RightMouseDown);
        TypeMethod(RightMouseUp);
        TypeMethod(RightMouseHeldDown);
        TypeMethod(RightMouseHeldUp);
        TypeMethod(ListSelect);
		TypeMember(GetCurSel);
		TypeMember(ComboSelect);
		TypeMember(Address);
    }

    ~MQ2WindowType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (VarPtr.Ptr && ((PCSIDLWND)VarPtr.Ptr)->dShow)
            strcpy(Destination,"TRUE");
        else
            strcpy(Destination,"FALSE");
        return true;
    }

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pWindowType)
            return false;
        VarPtr.Ptr=Source.Ptr;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        if (VarPtr.Ptr=FindMQ2Window(Source))
            return true;
        return false;
    }
};

#ifndef ISXEQ
class MQ2MacroType : public MQ2Type
{
public:
    static enum MacroMembers
    {
        Name=1,
        RunTime=2,
        Paused=3,
        Return=4,
        Params=5,
        Param=6,
        CurLine=7,
    };
    MQ2MacroType():MQ2Type("macro")
    {
        TypeMember(Name);
        TypeMember(RunTime);
        TypeMember(Paused);
        TypeMember(Return);
        TypeMember(Params);
        TypeMember(Param);
        TypeMember(CurLine);
    }

    ~MQ2MacroType()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (gRunning)
        {
            strcpy(Destination,gszMacroName);
            return true;
        }
        return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};
#endif

class MQ2ZoneType : public MQ2Type
{
public:
    static enum ZoneMembers
    {
        Name=1,
        ShortName=2,
        ID=3,
        Address=4,
        ZoneFlags=5,
    };
    MQ2ZoneType():MQ2Type("zone")
    {
        TypeMember(Name);
        TypeMember(ShortName);//2,
        TypeMember(ID);//3,
        TypeMember(Address);//4,
        TypeMember(ZoneFlags);//5,
    }

    ~MQ2ZoneType()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        strcpy(Destination,&((PZONELIST)VarPtr.Int)->LongName[0]);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type==pZoneType)
        {
            VarPtr.Ptr=Source.Ptr;
            return true;
        }
        if (Source.Type==(MQ2Type*)pCurrentZoneType)
        {
            VarPtr.Ptr=&((PWORLDDATA)pWorldData)->ZoneArray[(GetCharInfo()->zoneId && 0x7FFF)];
            return true;
        }
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
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
        SafeN=12,
        SafeW=13,
        SafeU=14,
        Address=15,
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
        TypeMember(ID);
        TypeMember(SafeN);
        TypeMember(SafeW);
        TypeMember(SafeU);
        TypeMember(Address);
    }

    ~MQ2CurrentZoneType()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        strcpy(Destination,&((PZONEINFO)pZoneInfo)->LongName[0]);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pCurrentZoneType)
            return false;
        VarPtr.Ptr=Source.Ptr;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};

class MQ2EverQuestType : public MQ2Type
{
public:
    static enum EverQuestMembers
    {
        GameState=1,
        LoginName=2,
        Server=3,
        LastCommand=4,
        LastTell=5,
        Running=6,
        MouseX=7,
        MouseY=8,
        Ping=9,
        LClickedObject=10,
        WinTitle=11,
        PID=12,
		ChatChannels=13,
        ChatChannel=14,
        ViewportX=15,
        ViewportY=16,
        ViewportXMax=17,
        ViewportYMax=18,
        ViewportXCenter=19,
        ViewportYCenter=20,
    };
    static enum EverQuestMethods
    {
    };
    MQ2EverQuestType():MQ2Type("everquest")
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
    }

    ~MQ2EverQuestType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};

class MQ2MacroQuestType : public MQ2Type
{
public:
	static enum MacroQuestMembers
    {
		Error=1,
        SyntaxError=2,
        MQ2DataError=3,
		BuildDate=4,
	};
	MQ2MacroQuestType() :MQ2Type("macroquest")
	{
		TypeMember(Error);
        TypeMember(SyntaxError);
        TypeMember(MQ2DataError);
        TypeMember(BuildDate);
	}
	~MQ2MacroQuestType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();
	INHERITDIRECT(pEverQuestType);// This inherits for Legacy reasons; All data from both types used to be under this type.

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};
#ifndef ISXEQ
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
        Sqrt=14,
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
        TypeMember(Sqrt);
    }

    ~MQ2MathType()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};
#endif
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

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        PCHAR pDesc=pEverQuest->GetRaceDesc(VarPtr.DWord);
        strcpy(Destination,pDesc);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.DWord=Source.DWord;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        VarPtr.DWord=atoi(Source);
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
        ID=3,
        PureCaster=4,
        CanCast=5,
        DruidType=6,
        NecromancerType=7,
        ShamanType=8,
        ClericType=9,
        PetClass=10,
        HealerType=11,
		MercType=12,
    };
    MQ2ClassType():MQ2Type("class")
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

    ~MQ2ClassType()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        PCHAR pDesc=GetClassDesc(VarPtr.DWord);
        strcpy(Destination,pDesc);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.DWord=Source.DWord;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        VarPtr.DWord=atoi(Source);
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

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        PCHAR pDesc=GetBodyTypeDesc(VarPtr.DWord);
        strcpy(Destination,pDesc);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.DWord=Source.DWord;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        VarPtr.DWord=atoi(Source);
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

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        PCHAR pDesc=pEverQuest->GetDeityDesc(VarPtr.DWord);
        strcpy(Destination,pDesc);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.DWord=Source.DWord;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        VarPtr.DWord=atoi(Source);
        return true;
    }
};
#ifndef ISXEQ
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
        Night=11,
        SecondsSinceMidnight=12,
		Hour12=13,
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
        TypeMember(SecondsSinceMidnight);
		TypeMember(Hour12);
    }

    ~MQ2TimeType()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        struct tm *Now=(struct tm*)VarPtr.Ptr;
        sprintf(Destination,"%02d:%02d:%02d",Now->tm_hour,Now->tm_min, Now->tm_sec);
        return true;
    }
    void InitVariable(MQ2VARPTR &VarPtr) 
    {
        VarPtr.Ptr=malloc(sizeof(struct tm));
        ZeroMemory(VarPtr.Ptr,sizeof(struct tm));
    }
    void FreeVariable(MQ2VARPTR &VarPtr) 
    {
        free(VarPtr.Ptr);
    }

#ifndef MQ2PLUGIN
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pTimeType)
            return false;
        memcpy(VarPtr.Ptr,Source.Ptr,sizeof(struct tm));
        return true;
    }
#else
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source);
#endif

    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};
#endif
#ifndef ISXEQ
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

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        strcpy(Destination,((MQ2Type*)VarPtr.Ptr)->GetName());
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.Ptr=Source.Type;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        if (VarPtr.Ptr=FindMQ2DataType(Source))
            return true;
        return false;
    }
}; 
#endif
class MQ2HeadingType : public MQ2Type
{
public:
    static enum HeadingMembers
    {
        Name=1,
        ShortName=2,
        Degrees=3,
        Clock=4,
        DegreesCCW=5,
    };
    static enum HeadingMethods
    {
    };
    MQ2HeadingType():MQ2Type("heading")
    {
        TypeMember(Name);
        TypeMember(ShortName);
        TypeMember(Degrees);
        TypeMember(Clock);
        TypeMember(DegreesCCW);
    }

    ~MQ2HeadingType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        strcpy(Destination,szHeadingNormalShort[(INT)((360.0f-VarPtr.Float)/ 22.5f + 0.5f)%16]);
        return true;
    }
#ifndef MQ2PLUGIN
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pHeadingType && Source.Type!=pFloatType)
            VarPtr.Float=(FLOAT)Source.DWord;
        else
            VarPtr.Float=Source.Float;
        return true;
    }
#else
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source);
#endif
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        VarPtr.Float=(FLOAT)atof(Source);
        return true;
    }
}; 

class MQ2InvSlotType : public MQ2Type
{
public:
    static enum InvSlotMembers
    {
        Pack=1,
        Slot=2,
        ID=3,
        Name=4,
        Item=5,
    };
    static enum InvSlotMethods
    {
    };
    MQ2InvSlotType():MQ2Type("invslot")
    {
        TypeMember(Pack);
        TypeMember(Slot);
        TypeMember(ID);
        TypeMember(Name);
        TypeMember(Item);
    }

    ~MQ2InvSlotType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        itoa(VarPtr.Int,Destination,10);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.DWord=Source.DWord;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        if (IsNumber(Source))
        {
            VarPtr.DWord=atoi(Source);
            return true;
        }
        else
        {
            CHAR Temp[MAX_STRING]={0};
            strlwr(strcpy(Temp,Source));
            VarPtr.DWord=ItemSlotMap[Temp];
            if (VarPtr.DWord || !stricmp(Temp,"charm"))
            {
                return true;
            }
        }
        return false;
    }
}; 

#ifndef ISXEQ
class MQ2PluginType : public MQ2Type
{
public:
    static enum PluginMembers
    {
        Name=1,
        Version=2,
    };
    MQ2PluginType():MQ2Type("plugin")
    {
        TypeMember(Name);
        TypeMember(Version);
    }

    ~MQ2PluginType()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (VarPtr.Ptr)
        {
            strcpy(Destination,((PMQPLUGIN)VarPtr.Ptr)->szFilename);
            return true;
        }
        return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pPluginType)
            return false;
        VarPtr.Ptr=Source.Ptr;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
}; 
#endif
class MQ2BenchmarkType : public MQ2Type
{
public:
    static enum BenchmarkMembers
    {
        Name=1,
        ID=2,
        Iterations=3,
        TimeSpent=4,
        AvgTimeSpent=5,
    };
    MQ2BenchmarkType():MQ2Type("benchmark")
    {
        TypeMember(Name);
        TypeMember(ID);
        TypeMember(Iterations);
        TypeMember(TimeSpent);
        TypeMember(AvgTimeSpent);
    }

    ~MQ2BenchmarkType()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        VarPtr.DWord=Source.DWord;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        if (IsNumber(Source))
        {
            VarPtr.DWord=atoi(Source);
            return true;
        }
        return false;
    }
}; 

class MQ2SkillType : public MQ2Type
{
public:
    static enum SkillMembers
    {
        Name=1,
        ID=2,
        ReuseTime=3,
        MinLevel=4,
        SkillCap=5,
        AltTimer=6,
        Activated=7,
    };
    static enum SkillMethods
    {
    };
    MQ2SkillType():MQ2Type("skill")
    {
        TypeMember(Name);
        TypeMember(ID);
        TypeMember(ReuseTime);
        TypeMember(MinLevel);
        TypeMember(SkillCap);
        TypeMember(AltTimer);
        TypeMember(Activated);
    }

    ~MQ2SkillType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (!VarPtr.Ptr)
            return false;
        if (PSKILL pSkill=*(PSKILL*)VarPtr.Ptr)
            if (PCHAR pName=pStringTable->getString(pSkill->nName,0))
            {
                strcpy(Destination,pName);
                return true;
            }
            return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pSkillType)
            return false;
        VarPtr.Ptr=Source.Ptr;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
}; 

class MQ2AltAbilityType : public MQ2Type
{
public:
    static enum AltAbilityMembers
    {
        Name=1,
        ShortName=2,
        Description=3,
        MinLevel=4,
        Cost=5,
        RequiresAbility=6,
        RequiresAbilityPoints=7,
        MaxRank=8,
        AARankRequired=9,
        Spell=10,
        Type=11,
        ReuseTime=12,
        ID=13,
        MyReuseTime=14,
        Flags=15,
		Expansion=16,
		Passive=17,
    };
    static enum AltAbilityMethods
    {
    };
    MQ2AltAbilityType():MQ2Type("altability")
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
    }

    ~MQ2AltAbilityType()
    {
    }
    bool MQ2AltAbilityType::ToString(MQ2VARPTR VarPtr, PCHAR Destination);

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pAltAbilityType)
            return false;
        VarPtr.Ptr=Source.Ptr;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
}; 

class MQ2TimerType : public MQ2Type
{
public:
    static enum TimerMembers
    {
        Value=1,
        OriginalValue=2,
    };
    static enum TimerMethods
    {
        Reset=1,
        Expire=2,
        Set=3, 
    };
    MQ2TimerType():MQ2Type("timer")
    {
        TypeMember(Value);
        TypeMember(OriginalValue);

        TypeMethod(Reset);
        TypeMethod(Expire);
        TypeMethod(Set); 
    }

    ~MQ2TimerType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        PMQTIMER pTimer=(PMQTIMER)VarPtr.Ptr;
        _ultoa(pTimer->Current,Destination,10);
        return true;
    }
    void InitVariable(MQ2VARPTR &VarPtr) 
    {
        PMQTIMER pVar = (PMQTIMER)malloc(sizeof(MQTIMER));
        pVar->szName[0]=0;
        pVar->Current = 0;
        pVar->Original= 0;
        pVar->pNext = gTimer;
        pVar->pPrev=0;
        if (gTimer)
            gTimer->pPrev=pVar;
        gTimer=pVar;
        VarPtr.Ptr=pVar;
    }
    void FreeVariable(MQ2VARPTR &VarPtr) 
    {
        PMQTIMER pVar=(PMQTIMER)VarPtr.Ptr;
        if (pVar->pPrev)
            pVar->pPrev->pNext=pVar->pNext;
        else
            gTimer=pVar->pNext;
        if (pVar->pNext)
            pVar->pNext->pPrev=pVar->pPrev;
        free(VarPtr.Ptr);
    }
#ifndef MQ2PLUGIN
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        PMQTIMER pTimer=(PMQTIMER)VarPtr.Ptr;
        if (Source.Type==pFloatType)
        {
            pTimer->Current=(DWORD)Source.Float;
            pTimer->Original=pTimer->Current;
        }
        else
        {
            pTimer->Current=Source.DWord;
            pTimer->Original=pTimer->Current;
        }
        return true;
    }
#else
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source);
#endif

    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        PMQTIMER pTimer=(PMQTIMER)VarPtr.Ptr;


        FLOAT VarValue = (FLOAT)atof(Source);
        switch (Source[strlen(Source)-1])
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
#ifndef ISXEQ
class MQ2ArrayType : public MQ2Type
{
public:
    static enum ArrayMembers
    {
        Dimensions=1,
        Size=2,
    };
    MQ2ArrayType():MQ2Type("array")
    {
        TypeMember(Dimensions);
        TypeMember(Size);
    }

    ~MQ2ArrayType()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        return false;
    }

    void InitVariable(MQ2VARPTR &VarPtr) 
    { 
    }
    void FreeVariable(MQ2VARPTR &VarPtr) 
    {
        CDataArray *pArray=(CDataArray*)VarPtr.Ptr;
        delete pArray;
    }

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
}; 
#endif

class MQ2GroupType : public MQ2Type
{
public:
    static enum GroupMembers
    {
        Address=1,
        xMember=2,
        Members=3,
        Leader=4,
        GroupSize=5,
        MainTank=6,
        MainAssist=7,
        Puller=8,
		MarkNpc=9,
		MasterLooter=10,
        AnyoneMissing=11,
		Present = 12,
		MercenaryCount = 13,
		TankMercCount = 14,
		HealerMercCount = 15,
		MeleeMercCount = 16,
		CasterMercCount = 17,

    };
    static enum GroupMethods
    {
    };
    MQ2GroupType():MQ2Type("group")
    {
        TypeMember(Address);
        AddMember(xMember,"Member");
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
    }

    ~MQ2GroupType()
    {
    }

    bool GETMEMBER();
    //DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination);
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
}; 

class MQ2GroupMemberType : public MQ2Type
{
public:
    static enum GroupMemberMembers
    {
        Address=1,
        Name=2,
        Leader=3,
        Spawn=4,
        Level=5,
        MainTank=6,
        MainAssist=7,
        Puller=8,
		MarkNpc=9,
		MasterLooter=10,
        Mercenary=11,
        PctAggro=12,
        xIndex=13,
        Offline=14,
        OtherZone=15,
		Present = 16,
    };
    static enum GroupMemberMethods
    {
    };
    MQ2GroupMemberType():MQ2Type("groupmember")
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
        AddMember(xIndex,"Index");
        TypeMember(Offline);
        TypeMember(OtherZone);
		TypeMember(Present);
    }

    ~MQ2GroupMemberType()
    {
    }

    bool GETMEMBER();
    //DECLAREGETMETHOD();

    INHERITINDIRECT(pSpawnType,Temp.Ptr=GetGroupMember(ObjectData.DWord),0);

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination);
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pGroupMemberType)
            return false;
        VarPtr.Ptr=Source.Ptr;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
}; 

class MQ2RaidType : public MQ2Type
{
public:
    static enum RaidMembers
    {
        xMember=1,
        Members=2,
        Target=3,
        Leader=4,
        TotalLevels=5,
        AverageLevel=6,
        LootType=7,
        Looter=8,
        Looters=9,
        Locked=10,
        Invited=11,
        MainAssist=12,
        MasterLooter=13,
    };
    static enum RaidMethods
    {
    };
    MQ2RaidType():MQ2Type("raid")
    {
        AddMember(xMember,"Member");
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

    ~MQ2RaidType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();
    INHERITINDIRECT(pSpawnType,Temp.Ptr=GetRaidMember(ObjectData.DWord-1),0);

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
}; 

class MQ2RaidMemberType : public MQ2Type
{
public:
    static enum RaidMemberMembers
    {
        Name=1,
        Group=3,
        GroupLeader=4,
        RaidLeader=5,
        Spawn=6,
        Looter=7,
        Class=8,
        Level=9,
    };
    static enum RaidMemberMethods
    {
    };
    MQ2RaidMemberType():MQ2Type("raidmember")
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

    ~MQ2RaidMemberType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        DWORD nRaidMember=VarPtr.DWord-1;
        if (VarPtr.DWord>=72)
            return false;
        if (!pRaid->RaidMemberUsed[nRaidMember])
            return false;
        PEQRAIDMEMBER pRaidMember=&pRaid->RaidMember[nRaidMember];
        strcpy(Destination,pRaidMember->Name);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pRaidMemberType)
            return false;
        VarPtr.Ptr=Source.Ptr;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
}; 

class MQ2EvolvingItemType : public MQ2Type
{
public:
    static enum EvolvingItemMembers
    {
        ExpPct=1,
        ExpOn=2,
        Level=3,
        MaxLevel=4,
    };
    MQ2EvolvingItemType():MQ2Type("Evolving")
    {
        TypeMember(ExpPct);
        TypeMember(ExpOn);
        TypeMember(Level);
        TypeMember(MaxLevel);
    }

    ~MQ2EvolvingItemType()
    {
    }

    bool GETMEMBER();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if(VarPtr.Ptr && ((PCONTENTS)VarPtr.Ptr)->IsEvolvingItem)
            strcpy(Destination,"TRUE");
        else
            strcpy(Destination,"FALSE");
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};

class MQ2DynamicZoneType : public MQ2Type
{
public:
    static enum DynamicZoneMembers
    {
        Name=1,
        Members=2,
        MaxMembers=3,
        xMember=4,
        Leader=5,
        InRaid=6,
    };
    MQ2DynamicZoneType():MQ2Type("dynamiczone")
    {
        TypeMember(Name);
        TypeMember(Members);
        TypeMember(MaxMembers);
        AddMember(xMember,"Member");
        TypeMember(Leader);
        TypeMember(InRaid);
    }
    ~MQ2DynamicZoneType()
    {
    }
    bool GETMEMBER();
    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if(pDZMember)
        {
            strcpy(Destination,pDynamicZone->ExpeditionName);
            return true;
        }
        return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};

class MQ2DZMemberType : public MQ2Type
{
public:
    static enum DZMemberTypeMembers
    {
        Name=1,
        Status=2,
    };
    MQ2DZMemberType():MQ2Type("dzmember")
    {
        TypeMember(Name);
        TypeMember(Status);
    }
    ~MQ2DZMemberType()
    {
    }
    bool GETMEMBER();
    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        strcpy(Destination,((PDZMEMBER)VarPtr.Ptr)->Name);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};

class MQ2FellowshipType : public MQ2Type
{
public:
    static enum FellowshipTypeMembers
    {
        ID=1,
        Leader=2,
        MotD=3,
        Members=4,
        xMember=5,
        CampfireDuration=6,
        CampfireY=7,
        CampfireX=8,
        CampfireZ=9,
        CampfireZone=10,
        Campfire=11,
    };
    MQ2FellowshipType():MQ2Type("fellowship")
    {
        TypeMember(ID);
        TypeMember(Leader);
        TypeMember(MotD);
        TypeMember(Members);
        AddMember(xMember,"Member");
        TypeMember(CampfireDuration);
        TypeMember(CampfireY);
        TypeMember(CampfireX);
        TypeMember(CampfireZ);
        TypeMember(CampfireZone);
        TypeMember(Campfire);
    }
    ~MQ2FellowshipType()
    {
    }
    bool GETMEMBER();
    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if(VarPtr.Ptr && ((PFELLOWSHIPINFO)VarPtr.Ptr)->FellowshipID)
            strcpy(Destination,"TRUE");
        else
            strcpy(Destination,"FALSE");
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};

class MQ2FellowshipMemberType : public MQ2Type
{
public:
    static enum FMTypeMembers
    {
        Zone=1,
        Level=2,
        Class=3,
        LastOn=4,
        Name=5,
    };
    MQ2FellowshipMemberType():MQ2Type("fellowshipmember")
    {
        TypeMember(Zone);
        TypeMember(Level);
        TypeMember(Class);
        TypeMember(LastOn);
        TypeMember(Name);
    }
    ~MQ2FellowshipMemberType()
    {
    }
    bool GETMEMBER();
    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        strcpy(Destination,((PFELLOWSHIPMEMBER)VarPtr.Ptr)->Name);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};

class MQ2FriendsType : public MQ2Type
{
public:
    static enum FriendsMembers
    {
        xFriend=1
    };
    static enum FriendsMethods
    {
    };

    MQ2FriendsType():MQ2Type("friend")
    {
        AddMember(xFriend,"Friend");
    }

    ~MQ2FriendsType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        // return the number of friends here...
        if(((PEVERQUEST)pEverQuest)->ChatService) {
            class CChatService *pChat=(class CChatService *) ((PEVERQUEST)pEverQuest)->ChatService;
            sprintf(Destination, "%d", pChat->GetNumberOfFriends());
            return true;
        }
        return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
}; 

class MQ2TargetType : public MQ2Type
{
public:
    static enum TargetMembers
    {
        Buff = 1,
        BuffCount = 2,
        BuffDuration = 3,
        PctAggro = 4,
        SecondaryPctAggro = 5,
        SecondaryAggroPlayer = 6,
		AggroHolder = 7,
		Slowed = 8,
		Rooted=9,
		Mezzed=10,
		Crippled=11,
		Malod=12,
		Tashed=13,
		Snared=14,
		Hasted=15,
		Aego=16,
		Skin=17,
		Focus=18,
		Regen=19,
		Symbol=20,
		Clarity=21,
		Pred=22,
		Strength=23,
		Brells=24,
		SV=25,
		SE=26,
		HybridHP=27,
		Growth=28,
		Shining=29,
		Beneficial=30,
		DSed=31,
		RevDSed=32,
    };

#ifdef ISBOXER_COMPAT
    MQ2TargetType():MQ2Type("eqtarget")
#else
    MQ2TargetType():MQ2Type("target")
#endif
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
		TypeMember(Malod);
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
    }

    ~MQ2TargetType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();
    INHERITDIRECT(pSpawnType);

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (!VarPtr.Ptr)
            return false;
        strcpy(Destination,((PSPAWNINFO)VarPtr.Ptr)->Name);
        return true;
    }
    void InitVariable(MQ2VARPTR &VarPtr) 
    {
        VarPtr.Ptr=malloc(sizeof(SPAWNINFO));
        ZeroMemory(VarPtr.Ptr,sizeof(SPAWNINFO));
    }
    void FreeVariable(MQ2VARPTR &VarPtr) 
    {
        free(VarPtr.Ptr);
    }

    virtual bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type==pSpawnType)
        {
            memcpy(VarPtr.Ptr,Source.Ptr,sizeof(SPAWNINFO));
            return true;
        }
        else
        {
            if (PSPAWNINFO pOther=(PSPAWNINFO)GetSpawnByID(Source.DWord))
            {
                memcpy(VarPtr.Ptr,pOther,sizeof(SPAWNINFO));
                return true;
            }
        }
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        if (PSPAWNINFO pOther=(PSPAWNINFO)GetSpawnByID(atoi(Source)))
        {
            memcpy(VarPtr.Ptr,pOther,sizeof(SPAWNINFO));
            return true;
        }
        return false;
    }
};

class MQ2TaskMemberType : public MQ2Type
{
public:
    static enum TaskMemberTypeMembers
    {
        Name=1,
        Leader=2,
		xIndex=3,
    };
    MQ2TaskMemberType():MQ2Type("taskmember")
    {
        TypeMember(Name);
        TypeMember(Leader);
		AddMember(xIndex,"Index");
    }
    ~MQ2TaskMemberType()
    {
    }
    bool GETMEMBER();
    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        strcpy(Destination,((PTASKMEMBER)VarPtr.Ptr)->Name);
        return true;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};
class MQ2TaskType : public MQ2Type
{
public:
	static enum TaskTypeMembers
    {
		Address=1,
        Title=2,
        Timer=3,
        xMember=4,
        Members=5,
        Leader=6,
        List=7,
    };
    MQ2TaskType():MQ2Type("task")
    {
        TypeMember(Address);
        TypeMember(Title);
        TypeMember(Timer);
        AddMember(xMember,"Member");
        TypeMember(Members);
        TypeMember(Leader);
        TypeMember(List);
    }
    ~MQ2TaskType()
    {
    }
    bool GETMEMBER();
    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
		if(pTaskWnd) {
			if(CListWnd *clist = (CListWnd *)pTaskWnd->GetChildItem("TASK_TaskList")) {
				CXStr Str;
				clist->GetItemText(&Str, 0, 1);
				CHAR szOut[255] = {0};
				GetCXStr(Str.Ptr,szOut,254);
				if(szOut[0]!='\0') {
					strcpy(Destination,szOut);
					return true;
				}
			}
		}
        return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};

class MQ2XTargetType : public MQ2Type
{
public:
    static enum xTargetMembers
    {
        xAddress = 1,
        TargetType = 2,
        ID = 3,
        Name = 4,
        PctAggro = 5,
    };

    MQ2XTargetType():MQ2Type("xtarget")
    {
        TypeMember(xAddress);
        TypeMember(TargetType);
        TypeMember(ID);
        TypeMember(Name);
        TypeMember(PctAggro);
    }

    ~MQ2XTargetType()
    {
    }

    bool GETMEMBER();
    DECLAREGETMETHOD();
	INHERITDIRECT(pSpawnType);

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if(GetCharInfo() && GetCharInfo()->pXTargetMgr)
        {
            XTARGETDATA xtd = GetCharInfo()->pXTargetMgr->pXTargetArray->pXTargetData[VarPtr.DWord];
            strcpy(Destination, xtd.Name);
        }
        else
            strcpy(Destination, "NULL");
        return true;
    }
	void InitVariable(MQ2VARPTR &VarPtr) 
    {
        VarPtr.Ptr=malloc(sizeof(SPAWNINFO));
        ZeroMemory(VarPtr.Ptr,sizeof(SPAWNINFO));
    }
    void FreeVariable(MQ2VARPTR &VarPtr) 
    {
        free(VarPtr.Ptr);
    }
    virtual bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type==pSpawnType)
        {
            memcpy(VarPtr.Ptr,Source.Ptr,sizeof(SPAWNINFO));
            return true;
        }
        else
        {
			if(GetCharInfo() && GetCharInfo()->pXTargetMgr)
			{
				XTARGETDATA xtd = GetCharInfo()->pXTargetMgr->pXTargetArray->pXTargetData[Source.DWord];
				if (PSPAWNINFO pOther=(PSPAWNINFO)GetSpawnByID(xtd.SpawnID))
				{
					memcpy(VarPtr.Ptr,pOther,sizeof(SPAWNINFO));
					return true;
				}
			}
        }
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
		if(GetCharInfo() && GetCharInfo()->pXTargetMgr)
		{
			XTARGETDATA xtd = GetCharInfo()->pXTargetMgr->pXTargetArray->pXTargetData[atoi(Source)];
			if (PSPAWNINFO pOther=(PSPAWNINFO)GetSpawnByID(xtd.SpawnID))
			{
				memcpy(VarPtr.Ptr,pOther,sizeof(SPAWNINFO));
				return true;
			}
		}
        return false;
    }
};

class MQ2MountType : public MQ2Type
{
public:
	static enum MountTypeMembers
    {
		xIndex=1,
		Name=2,
    };
    MQ2MountType():MQ2Type("mount")
    {
		AddMember(xIndex,"Index");
		TypeMember(Name);
    }
    ~MQ2MountType()
    {
    }
    bool GETMEMBER();
    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
		if(pInventoryWnd) {
			if(CListWnd *clist = (CListWnd *)pInventoryWnd->GetChildItem("IW_Mounts_MountList")) {
				CXStr Str;
				clist->GetItemText(&Str, VarPtr.DWord, 2);
				CHAR szOut[255] = {0};
				GetCXStr(Str.Ptr,szOut,254);
				if(szOut[0]!='\0') {
					strcpy(Destination,szOut);
					return true;
				}
			}
		}
        return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};
class MQ2AdvLootItemType : public MQ2Type
{
public:
    static enum AdvLootItemMembers
    {
        Address=1,
        xIndex=2,
        Name=3,
        ID=4,
        StackSize=5,
        Corpse=6,
		AutoRoll=7,
		Need=8,
		Greed=9,
		No=10,
		AlwaysNeed=11,
		AlwaysGreed=12,
		Never = 13,
		IconID = 14,
		xNoDrop = 15,
    };
    static enum MQ2AdvLootItemMethods
    {
    };
    MQ2AdvLootItemType():MQ2Type("advlootitem")
    {
        TypeMember(Address);
        AddMember(xIndex,"Index");
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
		AddMember(xNoDrop,"NoDrop");
    }

    ~MQ2AdvLootItemType()
    {
    }

    bool GETMEMBER();

    //INHERITINDIRECT(pSpawnType,Temp.Ptr=GetGroupMember(ObjectData.DWord),0);


	bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
		if(PLOOTITEM pitem = (PLOOTITEM)VarPtr.Ptr) {
			strcpy_s(Destination,64,pitem->Name);
			return true;
		}
		return false;
    }
    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        if (Source.Type!=pAdvLootItemType)
            return false;
        VarPtr.Ptr=Source.Ptr;
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
}; 
class MQ2AdvLootType : public MQ2Type
{
public:
	static enum AdvLootTypeMembers
	{
		PList = 1,
		PCount = 2,
		SList = 3,
		SCount = 4,
		PWantCount = 5,
		SWantCount = 6,
	};
	MQ2AdvLootType() :MQ2Type("advloot")
	{
		TypeMember(PList);
		TypeMember(PCount);
		TypeMember(SList);
		TypeMember(SCount);
		TypeMember(PWantCount);
		TypeMember(SWantCount);
	}
	~MQ2AdvLootType()
	{
	}
	bool GETMEMBER();
	bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		return false;
	}
	bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
	{
		return false;
	}
	bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
	{
		return false;
	}
};
