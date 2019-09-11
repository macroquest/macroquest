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

/*0x0194*/ int                      RealEstateID;
/*0x0198*/ uint8_t                  CharClass;                    // Im pretty sure this isnt working
/*0x0199*/ bool                     LFG;
/*0x019a*/ uint8_t                  FindBits;
/*0x019c*/ float                    BearingToTarget;
/*0x01a0*/ bool                     Linkdead;
/*0x01a4*/ LAUNCHSPELLDATA          CastingData;                  // size: 0x58
/*0x01fc*/ int                      Stuff;
/*0x0200*/ int                      ManaMax;
/*0x0204*/ uint8_t                  FD;
/*0x0208*/ int                      AARank;                       // this really is the title id
/*0x020c*/ unsigned int             NextIntimidateTime;
/*0x0210*/ int                      ManaCurrent;
/*0x0214*/ uint8_t                  InPvPArea;                    // are we in a PvP area?
/*0x0215*/ uint8_t                  Light;
/*0x0216*/ uint8_t                  StandState;
/*0x0218*/ unsigned int             SpellCooldownETA;
/*0x021c*/ int                      AFK;
/*0x0220*/ char                     Suffix[0x80];
/*0x02a0*/ bool                     bTempPet;
/*0x02a4*/ float                    RunSpeed;                     // 0.70 on runspeed 5...
/*0x02a8*/ unsigned int             CorpseDragCount;
/*0x02ac*/ float                    GetMeleeRangeVar1;            // used by GetMeleeRange (fScaleFactor)
/*0x02b0*/ char                     LoginRelated[0x20];
/*0x02d0*/ int                      IsAttacking;                  // need to investigate
/*0x02d4*/ unsigned int             LastTick;
/*0x02d8*/ EQC_INFO*                spawneqc_info;
/*0x02dc*/ unsigned int             LastRangedUsedTime;
/*0x02e0*/ uint8_t                  IsPassenger;                  // if u are on a boat or airship or whatever
/*0x02e4*/ unsigned int             LastRefresh;                  // last 18 sec tick
/*0x02e8*/ unsigned int             LoginSerial;
/*0x02ec*/ unsigned int             FishingETA;
/*0x02f0*/ unsigned int             Meditating;
/*0x02f4*/ int                      Buyer;
/*0x02f8*/ uint8_t                  Type2;
/*0x02fc*/ unsigned int             LastPrimaryUseTime;
/*0x0300*/ int                      PrimaryTintIndex;
/*0x0304*/ void*                    pTouchingSwitch;              // need to get that in here : struct _EQSWITCH
/*0x0308*/ unsigned int             LastMealTime;                 // last time we eat or drank
/*0x030c*/ int                      Anon;                         // found in EQPlayer__SetNameSpriteTint_x
/*0x0310*/ int                      PetID;
/*0x0314*/ bool                     bSummoned;                    // by a PC or by anyone? need to investigate
/*0x0318*/ int                      LastCastNum;
/*0x031c*/ unsigned int             LastCastTime;
/*0x0320*/ bool                     bBuffTimersOnHold;            // no you can't control this client side so unless you want to get banned leave it alone
/*0x0324*/ unsigned int             EnduranceMax;
/*0x0328*/ char                     DragNames[0x2][0x40];
/*0x03a8*/ unsigned int             SitStartTime;
/*0x03ac*/ char                     GM;
/*0x03ad*/ bool                     bAlwaysShowAura;
/*0x03b0*/ unsigned int             MinuteTimer;
/*0x03b8*/ int64_t                  HPCurrent;
/*0x03c0*/ bool                     bShowHelm;
/*0x03c4*/ int                      NpcTintIndex;
/*0x03c8*/ CPhysicsInfo             LastCollision;
/*0x03f8*/ bool                     bStationary;
/*0x03f9*/ uint8_t                  IntimidateCount;
/*0x03fc*/ int                      DoSpecialMelee;
/*0x0400*/ unsigned int             TimeStamp;                    // updates all the time including when on a mount
/*0x0404*/ uint8_t                  Level;
/*0x0408*/ unsigned int             LastTrapDamageTime;
/*0x040c*/ float                    CameraOffset;
/*0x0410*/ float                    AnimationSpeedRelated;
/*0x0414*/ int                      RealEstateItemId;
/*0x0418*/ SPAWNINFO*               pViewPlayer;
/*0x041c*/ unsigned int             LastTimeStoodStill;
/*0x0420*/ unsigned int             RespawnTimer;                 // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
/*0x0424*/ unsigned int             CombatSkillUsed[0x2];
/*0x042c*/ unsigned int             StunTimer;
/*0x0430*/ unsigned int             LastSecondaryUseTime;
/*0x0434*/ int                      Deity;
/*0x0438*/ int64_t                  HPMax;
/*0x0440*/ int                      Dontknowyet2;
/*0x0444*/ unsigned int             SpellGemETA[0xf];             // InnateETA is now the last member in this array
/*0x0480*/ int                      EnduranceCurrent;
/*0x0484*/ int                      CurrIOState;
/*0x0488*/ unsigned int             ACounter;                     // not sure what this one is for (m_uHibernatingCount)
/*0x048c*/ void*                    pRaceGenderInfo;              // todo this is not a void* so... map the CRaceGenderInfo class
/*0x0490*/ int                      berserker;
/*0x0494*/ bool                     Mercenary;
/*0x0495*/ char                     Handle[0x20];
/*0x04b8*/ float                    FallingStartZ;
/*0x04bc*/ uint8_t                  FishingEvent;
/*0x04c0*/ int                      DontKnowYet;
/*0x04c4*/ char                     DraggingPlayer[0x40];
/*0x0504*/ int                      HideMode;
/*0x0508*/ unsigned int             Zone;
/*0x050c*/ bool                     bAnimationOnPop;
/*0x050d*/ uint8_t                  HoldingAnimation;             // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
/*0x0510*/ float                    MerchantGreed;
/*0x0514*/ uint8_t                  GMRank;
/*0x0518*/ int                      WarCry;
/*0x051c*/ bool                     bOfflineMode;
/*0x051d*/ bool                     PvPFlag;
/*0x0520*/ unsigned int             LastResendAddPlayerPacket;
/*0x0524*/ unsigned int             CombatSkillTicks[0x2];
/*0x052c*/ bool                     Sneak;
/*0x052d*/ uint8_t                  TitleVisible;
/*0x052e*/ uint8_t                  LastAttack;
/*0x0530*/ int64_t                  GuildID;
/*0x0538*/ float                    MyWalkSpeed;
/*0x053c*/ int                      SomeData[0x2];
/*0x0544*/ bool                     bAttackRelated;
/*0x0548*/ int                      Trader;                       // found in CEverQuest__RightClickedOnPlayer_x
/*0x054c*/ int                      SecondaryTintIndex;
/*0x0550*/ float                    MissileRangeToTarget;
/*0x0554*/ bool                     bSwitchMoved;                 // true when a door moves near the spawn
/*0x0555*/ uint8_t                  Blind;
/*0x0558*/ unsigned int             PotionTimer;
/*0x055c*/ unsigned int             MasterID;
/*0x0560*/ int                      AltAttack;
/*0x0564*/ bool                     bBetaBuffed;
/*0x0565*/ EqItemGuid               realEstateItemGuid;
/*0x0577*/ char                     Title[0x80];
/*0x05f8*/ unsigned int**           ppUDP;                        // UdpLibrary::UdpConnection
/*0x05fc*/ int                      SomethingElse;
/*0x0600*/ float                    ViewHeight;
/*0x0604*/ unsigned int             NextSwim;
/*0x0608*/ uint8_t                  HmmWhat;

