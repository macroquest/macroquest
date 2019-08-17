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

/*0x0194*/ int                      EnduranceCurrent;
/*0x0198*/ unsigned int             Meditating;
/*0x019c*/ uint8_t                  Type2;
/*0x01a0*/ int                      AARank;                       // this really is the title id
/*0x01a4*/ uint8_t                  FD;
/*0x01a8*/ EQC_INFO*                spawneqc_info;
/*0x01ac*/ unsigned int             PotionTimer;
/*0x01b0*/ unsigned int             MasterID;
/*0x01b4*/ int                      SomeData[0x2];
/*0x01bc*/ unsigned int             CorpseDragCount;
/*0x01c0*/ unsigned int             SpellCooldownETA;
/*0x01c4*/ int                      Dontknowyet2;
/*0x01c8*/ uint8_t                  Blind;
/*0x01cc*/ unsigned int             TimeStamp;                    // updates all the time including when on a mount
/*0x01d0*/ bool                     Sneak;
/*0x01d1*/ uint8_t                  GMRank;
/*0x01d4*/ unsigned int             FishingETA;
/*0x01d8*/ unsigned int             CombatSkillTicks[0x2];
/*0x01e0*/ unsigned int             RespawnTimer;                 // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
/*0x01e4*/ unsigned int             NextIntimidateTime;
/*0x01e8*/ uint8_t                  CharClass;                    // Im pretty sure this isnt working
/*0x01e9*/ uint8_t                  HoldingAnimation;             // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
/*0x01ec*/ float                    AnimationSpeedRelated;
/*0x01f0*/ uint8_t                  LastAttack;
/*0x01f4*/ float                    MissileRangeToTarget;
/*0x01f8*/ char                     DragNames[0x2][0x40];
/*0x0278*/ CPhysicsInfo             LastCollision;
/*0x02a8*/ float                    MyWalkSpeed;
/*0x02ac*/ int                      HideMode;
/*0x02b0*/ uint8_t                  StandState;
/*0x02b4*/ int                      SomethingElse;
/*0x02b8*/ bool                     bTempPet;
/*0x02bc*/ int                      WarCry;
/*0x02c0*/ int                      Deity;
/*0x02c4*/ uint8_t                  FindBits;
/*0x02c8*/ int                      IsAttacking;                  // need to investigate
/*0x02cc*/ bool                     LFG;
/*0x02d0*/ unsigned int             LastPrimaryUseTime;
/*0x02d4*/ unsigned int             LastMealTime;                 // last time we eat or drank
/*0x02d8*/ bool                     bAlwaysShowAura;
/*0x02dc*/ int                      ManaCurrent;
/*0x02e0*/ int                      Anon;                         // found in EQPlayer__SetNameSpriteTint_x
/*0x02e4*/ float                    GetMeleeRangeVar1;            // used by GetMeleeRange (fScaleFactor)
/*0x02e8*/ char                     Title[0x80];
/*0x0368*/ char                     DraggingPlayer[0x40];
/*0x03a8*/ SPAWNINFO*               pViewPlayer;
/*0x03ac*/ unsigned int             LastSecondaryUseTime;
/*0x03b0*/ int64_t                  HPMax;
/*0x03b8*/ int                      PrimaryTintIndex;
/*0x03bc*/ unsigned int             LastRangedUsedTime;
/*0x03c0*/ unsigned int             NextSwim;
/*0x03c4*/ unsigned int             CombatSkillUsed[0x2];
/*0x03cc*/ int                      CurrIOState;
/*0x03d0*/ float                    MerchantGreed;
/*0x03d4*/ int                      AFK;
/*0x03d8*/ int                      berserker;
/*0x03dc*/ uint8_t                  IsPassenger;                  // if u are on a boat or airship or whatever
/*0x03e0*/ float                    CameraOffset;
/*0x03e4*/ int                      DontKnowYet;
/*0x03e8*/ bool                     bSummoned;                    // by a PC or by anyone? need to investigate
/*0x03e9*/ bool                     Linkdead;
/*0x03ec*/ unsigned int             StunTimer;
/*0x03f0*/ unsigned int             SpellGemETA[0xf];             // InnateETA is now the last member in this array
/*0x042c*/ unsigned int             LastRefresh;                  // last 18 sec tick
/*0x0430*/ char                     GM;
/*0x0434*/ unsigned int             LastResendAddPlayerPacket;
/*0x0438*/ EqItemGuid               realEstateItemGuid;
/*0x044a*/ char                     LoginRelated[0x20];
/*0x046c*/ float                    ViewHeight;
/*0x0470*/ float                    FallingStartZ;
/*0x0474*/ int                      PetID;
/*0x0478*/ void*                    pTouchingSwitch;              // need to get that in here : struct _EQSWITCH
/*0x047c*/ int                      RealEstateItemId;
/*0x0480*/ unsigned int             LastTrapDamageTime;
/*0x0484*/ uint8_t                  HmmWhat;
/*0x0488*/ int                      Stuff;
/*0x048c*/ unsigned int             MinuteTimer;
/*0x0490*/ unsigned int             LoginSerial;
/*0x0494*/ uint8_t                  FishingEvent;
/*0x0495*/ char                     Handle[0x20];
/*0x04b5*/ bool                     bStationary;
/*0x04b6*/ bool                     Mercenary;
/*0x04b7*/ uint8_t                  Level;
/*0x04b8*/ float                    BearingToTarget;
/*0x04bc*/ uint8_t                  Light;
/*0x04c0*/ unsigned int             LastTimeStoodStill;
/*0x04c4*/ LAUNCHSPELLDATA          CastingData;                  // size: 0x58
/*0x051c*/ int                      ManaMax;
/*0x0520*/ int                      AltAttack;
/*0x0524*/ float                    RunSpeed;                     // 0.70 on runspeed 5...
/*0x0528*/ unsigned int             SitStartTime;
/*0x0530*/ int64_t                  GuildID;
/*0x0538*/ unsigned int             EnduranceMax;
/*0x053c*/ int                      SecondaryTintIndex;
/*0x0540*/ int                      DoSpecialMelee;
/*0x0544*/ unsigned int             LastCastTime;
/*0x0548*/ unsigned int             Zone;
/*0x054c*/ int                      RealEstateID;
/*0x0550*/ uint8_t                  IntimidateCount;
/*0x0554*/ int                      NpcTintIndex;
/*0x0558*/ bool                     bBuffTimersOnHold;            // no you can't control this client side so unless you want to get banned leave it alone
/*0x0559*/ bool                     bOfflineMode;
/*0x055c*/ int                      Trader;                       // found in CEverQuest__RightClickedOnPlayer_x
/*0x0560*/ int64_t                  HPCurrent;
/*0x0568*/ bool                     PvPFlag;
/*0x056c*/ void*                    pRaceGenderInfo;              // todo this is not a void* so... map the CRaceGenderInfo class
/*0x0570*/ uint8_t                  InPvPArea;                    // are we in a PvP area?
/*0x0571*/ bool                     bBetaBuffed;
/*0x0574*/ unsigned int**           ppUDP;                        // UdpLibrary::UdpConnection
/*0x0578*/ bool                     bAttackRelated;
/*0x0579*/ bool                     bSwitchMoved;                 // true when a door moves near the spawn
/*0x057c*/ int                      LastCastNum;
/*0x0580*/ unsigned int             ACounter;                     // not sure what this one is for (m_uHibernatingCount)
/*0x0584*/ bool                     bAnimationOnPop;
/*0x0585*/ bool                     bShowHelm;
/*0x0588*/ int                      Buyer;
/*0x058c*/ uint8_t                  TitleVisible;
/*0x058d*/ char                     Suffix[0x80];
/*0x0610*/ unsigned int             LastTick;
