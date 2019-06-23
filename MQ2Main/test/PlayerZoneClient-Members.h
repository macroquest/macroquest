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

	int         EnduranceCurrent;
	DWORD       Meditating;
	BYTE        Type2;
	int         AARank;                              // this really is the title id
	BYTE        FD;
	EQC_INFO*   spawneqc_info;
	DWORD       PotionTimer;
	UINT        MasterID;
	int         SomeData[0x2];
	UINT        CorpseDragCount;
	UINT        SpellCooldownETA;
	int         Dontknowyet2;
	BYTE        Blind;
	UINT        TimeStamp;                           // updates all the time including when on a mount
	bool        Sneak;
	BYTE        GMRank;
	UINT        FishingETA;
	UINT        CombatSkillTicks[0x2];
	UINT        RespawnTimer;                        // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
	UINT        NextIntimidateTime;
	BYTE        CharClass;                           // Im pretty sure this isnt working
	BYTE        HoldingAnimation;                    // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
	FLOAT       AnimationSpeedRelated;
	BYTE        LastAttack;
	FLOAT       MissileRangeToTarget;
	CHAR        DragNames[0x2][0x40];
	CPhysicsInfo LastCollision;
	FLOAT       MyWalkSpeed;
	int         HideMode;
	BYTE        StandState;
	int         SomethingElse;
	bool        bTempPet;
	int         WarCry;
	int         Deity;
	BYTE        FindBits;
	int         IsAttacking;                         // need to investigate
	bool        LFG;
	UINT        LastPrimaryUseTime;
	UINT        LastMealTime;                        // last time we eat or drank
	bool        bAlwaysShowAura;
	int         ManaCurrent;
	int         Anon;                                // found in EQPlayer__SetNameSpriteTint_x
	FLOAT       GetMeleeRangeVar1;                   // used by GetMeleeRange (fScaleFactor)
	CHAR        Title[0x80];
	CHAR        DraggingPlayer[0x40];
	SPAWNINFO*  pViewPlayer;
	UINT        LastSecondaryUseTime;
	int64_t     HPMax;
	int         PrimaryTintIndex;
	UINT        LastRangedUsedTime;
	UINT        NextSwim;
	UINT        CombatSkillUsed[0x2];
	int         CurrIOState;
	FLOAT       MerchantGreed;
	int         AFK;
	int         berserker;
	BYTE        IsPassenger;                         // if u are on a boat or airship or whatever
	FLOAT       CameraOffset;
	int         DontKnowYet;
	bool        bSummoned;                           // by a PC or by anyone? need to investigate
	bool        Linkdead;
	UINT        StunTimer;
	UINT        SpellGemETA[0xf];                    // InnateETA is now the last member in this array
	UINT        LastRefresh;                         // last 18 sec tick
	CHAR        GM;
	UINT        LastResendAddPlayerPacket;
	EqItemGuid  realEstateItemGuid;
	CHAR        LoginRelated[0x20];
	FLOAT       ViewHeight;
	FLOAT       FallingStartZ;
	int         PetID;
	void*       pTouchingSwitch;                     // need to get that in here : struct _EQSWITCH
	int         RealEstateItemId;
	UINT        LastTrapDamageTime;
	BYTE        HmmWhat;
	int         Stuff;
	UINT        MinuteTimer;
	DWORD       LoginSerial;
	BYTE        FishingEvent;
	CHAR        Handle[0x20];
	bool        bStationary;
	bool        Mercenary;
	BYTE        Level;
	FLOAT       BearingToTarget;
	BYTE        Light;
	UINT        LastTimeStoodStill;
	LAUNCHSPELLDATA CastingData;                     // size: 0x58
	int         ManaMax;
	int         AltAttack;
	FLOAT       RunSpeed;                            // 0.70 on runspeed 5...
	UINT        SitStartTime;
	int64_t     GuildID;
	UINT        EnduranceMax;
	int         SecondaryTintIndex;
	int         DoSpecialMelee;
	DWORD       LastCastTime;
	DWORD       Zone;
	int         RealEstateID;
	BYTE        IntimidateCount;
	int         NpcTintIndex;
	bool        bBuffTimersOnHold;                   // no you can't control this client side so unless you want to get banned leave it alone
	bool        bOfflineMode;
	int         Trader;                              // found in CEverQuest__RightClickedOnPlayer_x
	int64_t     HPCurrent;
	bool        PvPFlag;
	void*       pRaceGenderInfo;                     // todo this is not a void* so... map the CRaceGenderInfo class
	BYTE        InPvPArea;                           // are we in a PvP area?
	bool        bBetaBuffed;
	DWORD**     ppUDP;                               // UdpLibrary::UdpConnection
	bool        bAttackRelated;
	bool        bSwitchMoved;                        // true when a door moves near the spawn
	int         LastCastNum;
	UINT        ACounter;                            // not sure what this one is for (m_uHibernatingCount)
	bool        bAnimationOnPop;
	bool        bShowHelm;
	int         Buyer;
	BYTE        TitleVisible;
	CHAR        Suffix[0x80];
	UINT        LastTick;
