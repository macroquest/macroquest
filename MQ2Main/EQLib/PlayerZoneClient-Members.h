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

	int                      EnduranceCurrent;
	unsigned int             Meditating;
	uint8_t                  Type2;
	int                      AARank;                       // this really is the title id
	uint8_t                  FD;
	EQC_INFO*                spawneqc_info;
	unsigned int             PotionTimer;
	unsigned int             MasterID;
	int                      SomeData[0x2];
	unsigned int             CorpseDragCount;
	unsigned int             SpellCooldownETA;
	int                      Dontknowyet2;
	uint8_t                  Blind;
	unsigned int             TimeStamp;                    // updates all the time including when on a mount
	bool                     Sneak;
	uint8_t                  GMRank;
	unsigned int             FishingETA;
	unsigned int             CombatSkillTicks[0x2];
	unsigned int             RespawnTimer;                 // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
	unsigned int             NextIntimidateTime;
	uint8_t                  CharClass;                    // Im pretty sure this isnt working
	uint8_t                  HoldingAnimation;             // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
	float                    AnimationSpeedRelated;
	uint8_t                  LastAttack;
	float                    MissileRangeToTarget;
	char                     DragNames[0x2][0x40];
	CPhysicsInfo             LastCollision;
	float                    MyWalkSpeed;
	int                      HideMode;
	uint8_t                  StandState;
	int                      SomethingElse;
	bool                     bTempPet;
	int                      WarCry;
	int                      Deity;
	uint8_t                  FindBits;
	int                      IsAttacking;                  // need to investigate
	bool                     LFG;
	unsigned int             LastPrimaryUseTime;
	unsigned int             LastMealTime;                 // last time we eat or drank
	bool                     bAlwaysShowAura;
	int                      ManaCurrent;
	int                      Anon;                         // found in EQPlayer__SetNameSpriteTint_x
	float                    GetMeleeRangeVar1;            // used by GetMeleeRange (fScaleFactor)
	char                     Title[0x80];
	char                     DraggingPlayer[0x40];
	SPAWNINFO*               pViewPlayer;
	unsigned int             LastSecondaryUseTime;
	int64_t                  HPMax;
	int                      PrimaryTintIndex;
	unsigned int             LastRangedUsedTime;
	unsigned int             NextSwim;
	unsigned int             CombatSkillUsed[0x2];
	int                      CurrIOState;
	float                    MerchantGreed;
	int                      AFK;
	int                      berserker;
	uint8_t                  IsPassenger;                  // if u are on a boat or airship or whatever
	float                    CameraOffset;
	int                      DontKnowYet;
	bool                     bSummoned;                    // by a PC or by anyone? need to investigate
	bool                     Linkdead;
	unsigned int             StunTimer;
	unsigned int             SpellGemETA[0xf];             // InnateETA is now the last member in this array
	unsigned int             LastRefresh;                  // last 18 sec tick
	char                     GM;
	unsigned int             LastResendAddPlayerPacket;
	EqItemGuid               realEstateItemGuid;
	char                     LoginRelated[0x20];
	float                    ViewHeight;
	float                    FallingStartZ;
	int                      PetID;
	void*                    pTouchingSwitch;              // need to get that in here : struct _EQSWITCH
	int                      RealEstateItemId;
	unsigned int             LastTrapDamageTime;
	uint8_t                  HmmWhat;
	int                      Stuff;
	unsigned int             MinuteTimer;
	unsigned int             LoginSerial;
	uint8_t                  FishingEvent;
	char                     Handle[0x20];
	bool                     bStationary;
	bool                     Mercenary;
	uint8_t                  Level;
	float                    BearingToTarget;
	uint8_t                  Light;
	unsigned int             LastTimeStoodStill;
	LAUNCHSPELLDATA          CastingData;                  // size: 0x58
	int                      ManaMax;
	int                      AltAttack;
	float                    RunSpeed;                     // 0.70 on runspeed 5...
	unsigned int             SitStartTime;
	int64_t                  GuildID;
	unsigned int             EnduranceMax;
	int                      SecondaryTintIndex;
	int                      DoSpecialMelee;
	unsigned int             LastCastTime;
	unsigned int             Zone;
	int                      RealEstateID;
	uint8_t                  IntimidateCount;
	int                      NpcTintIndex;
	bool                     bBuffTimersOnHold;            // no you can't control this client side so unless you want to get banned leave it alone
	bool                     bOfflineMode;
	int                      Trader;                       // found in CEverQuest__RightClickedOnPlayer_x
	int64_t                  HPCurrent;
	bool                     PvPFlag;
	void*                    pRaceGenderInfo;              // todo this is not a void* so... map the CRaceGenderInfo class
	uint8_t                  InPvPArea;                    // are we in a PvP area?
	bool                     bBetaBuffed;
	unsigned int**           ppUDP;                        // UdpLibrary::UdpConnection
	bool                     bAttackRelated;
	bool                     bSwitchMoved;                 // true when a door moves near the spawn
	int                      LastCastNum;
	unsigned int             ACounter;                     // not sure what this one is for (m_uHibernatingCount)
	bool                     bAnimationOnPop;
	bool                     bShowHelm;
	int                      Buyer;
	uint8_t                  TitleVisible;
	char                     Suffix[0x80];
	unsigned int             LastTick;
