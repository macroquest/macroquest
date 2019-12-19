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

/*0x0198*/ int64_t                  HPCurrent;
/*0x01a0*/ unsigned int             ACounter;                     // not sure what this one is for (m_uHibernatingCount)
/*0x01a4*/ unsigned int             LastPrimaryUseTime;
/*0x01a8*/ int                      Buyer;
/*0x01ac*/ uint8_t                  FindBits;
/*0x01b0*/ int                      ManaMax;
/*0x01b4*/ unsigned int             Zone;
/*0x01b8*/ float                    CameraOffset;
/*0x01bc*/ bool                     bBetaBuffed;
/*0x01bd*/ bool                     Linkdead;
/*0x01be*/ char                     DragNames[0x2][0x40];
/*0x023e*/ uint8_t                  Blind;
/*0x023f*/ char                     Suffix[0x80];
/*0x02c0*/ float                    MissileRangeToTarget;
/*0x02c4*/ int                      PetID;
/*0x02c8*/ bool                     bAlwaysShowAura;
/*0x02cc*/ unsigned int             LastSecondaryUseTime;
/*0x02d0*/ int                      SomethingElse;
/*0x02d4*/ unsigned int             NextSwim;
/*0x02d8*/ int                      SecondaryTintIndex;
/*0x02dc*/ uint8_t                  HmmWhat;
/*0x02dd*/ bool                     bTempPet;
/*0x02e0*/ int                      Dontknowyet2;
/*0x02e4*/ unsigned int             RespawnTimer;                 // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
/*0x02e8*/ int                      SomeData[0x2];
/*0x02f0*/ char                     Handle[0x20];
/*0x0310*/ EQC_INFO*                spawneqc_info;
/*0x0314*/ SPAWNINFO*               pViewPlayer;
/*0x0318*/ EqItemGuid               realEstateItemGuid;
/*0x032a*/ char                     DraggingPlayer[0x40];
/*0x036c*/ void*                    pRaceGenderInfo;              // todo this is not a void* so... map the CRaceGenderInfo class
/*0x0370*/ bool                     PvPFlag;
/*0x0371*/ uint8_t                  Level;
/*0x0372*/ uint8_t                  FD;
/*0x0373*/ uint8_t                  CharClass;                    // Im pretty sure this isnt working
/*0x0374*/ int                      AltAttack;
/*0x0378*/ unsigned int             LastMealTime;                 // last time we eat or drank
/*0x037c*/ unsigned int             LastTimeStoodStill;
/*0x0380*/ float                    MyWalkSpeed;
/*0x0384*/ uint8_t                  TitleVisible;
/*0x0385*/ bool                     bAnimationOnPop;
/*0x0386*/ bool                     bStationary;
/*0x0387*/ bool                     Mercenary;
/*0x0388*/ unsigned int             LastCastTime;
/*0x038c*/ int                      IsAttacking;                  // need to investigate
/*0x0390*/ bool                     bAttackRelated;
/*0x0394*/ unsigned int             CombatSkillTicks[0x2];
/*0x039c*/ char                     LoginRelated[0x20];
/*0x03bc*/ unsigned int             TimeStamp;                    // updates all the time including when on a mount
/*0x03c0*/ int                      Anon;                         // found in EQPlayer__SetNameSpriteTint_x
/*0x03c4*/ unsigned int             LoginSerial;
/*0x03c8*/ bool                     bSwitchMoved;                 // true when a door moves near the spawn
/*0x03d0*/ int64_t                  HPMax;
/*0x03d8*/ unsigned int             LastRefresh;                  // last 18 sec tick
/*0x03dc*/ int                      berserker;
/*0x03e0*/ unsigned int             PotionTimer;
/*0x03e4*/ unsigned int             SpellGemETA[0xf];             // InnateETA is now the last member in this array
/*0x0420*/ char                     GM;
/*0x0424*/ float                    ViewHeight;
/*0x0428*/ int64_t                  GuildID;
/*0x0430*/ int                      EnduranceCurrent;
/*0x0434*/ int                      RealEstateItemId;
/*0x0438*/ unsigned int             StunTimer;
/*0x043c*/ bool                     bOfflineMode;
/*0x0440*/ int                      Trader;                       // found in CEverQuest__RightClickedOnPlayer_x
/*0x0444*/ uint8_t                  Light;
/*0x0448*/ unsigned int             MasterID;
/*0x044c*/ bool                     Sneak;
/*0x0450*/ void*                    pTouchingSwitch;              // need to get that in here : struct _EQSWITCH
/*0x0454*/ unsigned int             SpellCooldownETA;
/*0x0458*/ uint8_t                  FishingEvent;
/*0x0459*/ bool                     bSummoned;                    // by a PC or by anyone? need to investigate
/*0x045c*/ CPhysicsInfo             LastCollision;
/*0x048c*/ unsigned int             Meditating;
/*0x0490*/ int                      Stuff;
/*0x0494*/ unsigned int             LastTick;
/*0x0498*/ uint8_t                  LastAttack;
/*0x049c*/ int                      CurrIOState;
/*0x04a0*/ float                    GetMeleeRangeVar1;            // used by GetMeleeRange (fScaleFactor)
/*0x04a4*/ float                    BearingToTarget;
/*0x04a8*/ int                      ManaCurrent;
/*0x04ac*/ uint8_t                  GMRank;
/*0x04b0*/ float                    FallingStartZ;
/*0x04b4*/ unsigned int             CorpseDragCount;
/*0x04b8*/ unsigned int             CombatSkillUsed[0x2];
/*0x04c0*/ int                      RealEstateID;
/*0x04c4*/ int                      DontKnowYet;
/*0x04c8*/ int                      HideMode;
/*0x04cc*/ uint8_t                  StandState;
/*0x04d0*/ int                      WarCry;
/*0x04d4*/ uint8_t                  Type2;
/*0x04d8*/ LAUNCHSPELLDATA          CastingData;                  // size: 0x58
/*0x0530*/ unsigned int             EnduranceMax;
/*0x0534*/ char                     Title[0x80];
/*0x05b4*/ unsigned int             MinuteTimer;
/*0x05b8*/ unsigned int**           ppUDP;                        // UdpLibrary::UdpConnection
/*0x05bc*/ uint8_t                  IsPassenger;                  // if u are on a boat or airship or whatever
/*0x05c0*/ unsigned int             NextIntimidateTime;
/*0x05c4*/ uint8_t                  HoldingAnimation;             // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
/*0x05c8*/ unsigned int             SitStartTime;
/*0x05cc*/ float                    AnimationSpeedRelated;
/*0x05d0*/ int                      PrimaryTintIndex;
/*0x05d4*/ int                      Deity;
/*0x05d8*/ bool                     LFG;
/*0x05dc*/ int                      AFK;
/*0x05e0*/ float                    MerchantGreed;
/*0x05e4*/ unsigned int             LastRangedUsedTime;
/*0x05e8*/ bool                     bBuffTimersOnHold;            // no you can't control this client side so unless you want to get banned leave it alone
/*0x05ec*/ int                      NpcTintIndex;
/*0x05f0*/ float                    RunSpeed;                     // 0.70 on runspeed 5...
/*0x05f4*/ int                      LastCastNum;
/*0x05f8*/ unsigned int             LastTrapDamageTime;
/*0x05fc*/ int                      AARank;                       // this really is the title id
/*0x0600*/ unsigned int             LastResendAddPlayerPacket;
/*0x0604*/ uint8_t                  InPvPArea;                    // are we in a PvP area?
/*0x0605*/ uint8_t                  IntimidateCount;
/*0x0606*/ bool                     bShowHelm;
/*0x0608*/ unsigned int             FishingETA;
/*0x060c*/ int                      DoSpecialMelee;
