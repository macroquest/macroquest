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

/*0x0424*/ int                      RealEstateID;
/*0x0304*/ uint8_t                  CharClass;                    // Im pretty sure this isnt working
/*0x05bc*/ bool                     LFG;
/*0x0610*/ uint8_t                  FindBits;
/*0x0230*/ float                    BearingToTarget;
/*0x04cd*/ bool                     Linkdead;
/*0x0468*/ LAUNCHSPELLDATA          CastingData;                  // size: 0x58
/*0x01a4*/ int                      Stuff;
/*0x04d0*/ int                      ManaMax;
/*0x01f8*/ uint8_t                  FD;
/*0x01f4*/ int                      AARank;                       // this really is the title id
/*0x0210*/ unsigned int             NextIntimidateTime;
/*0x0300*/ int                      ManaCurrent;
/*0x0515*/ uint8_t                  InPvPArea;                    // are we in a PvP area?
/*0x01a9*/ uint8_t                  Light;
/*0x04cc*/ uint8_t                  StandState;
/*0x0418*/ unsigned int             SpellCooldownETA;
/*0x0278*/ int                      AFK;
/*0x0305*/ char                     Suffix[0x80];
/*0x0530*/ bool                     bTempPet;
/*0x05e0*/ float                    RunSpeed;                     // 0.70 on runspeed 5...
/*0x05d4*/ unsigned int             CorpseDragCount;
/*0x04ec*/ float                    GetMeleeRangeVar1;            // used by GetMeleeRange (fScaleFactor)
/*0x04f0*/ char                     LoginRelated[0x20];
/*0x0264*/ int                      IsAttacking;                  // need to investigate
/*0x05c8*/ unsigned int             LastTick;
/*0x0428*/ EQC_INFO*                spawneqc_info;
/*0x022c*/ unsigned int             LastRangedUsedTime;
/*0x01a8*/ uint8_t                  IsPassenger;                  // if u are on a boat or airship or whatever
/*0x05ac*/ unsigned int             LastRefresh;                  // last 18 sec tick
/*0x05b4*/ unsigned int             LoginSerial;
/*0x05b8*/ unsigned int             FishingETA;
/*0x0590*/ unsigned int             Meditating;
/*0x0224*/ int                      Buyer;
/*0x05f0*/ uint8_t                  Type2;
/*0x0588*/ unsigned int             LastPrimaryUseTime;
/*0x05fc*/ int                      PrimaryTintIndex;
/*0x05dc*/ void*                    pTouchingSwitch;              // need to get that in here : struct _EQSWITCH
/*0x026c*/ unsigned int             LastMealTime;                 // last time we eat or drank
/*0x0464*/ int                      Anon;                         // found in EQPlayer__SetNameSpriteTint_x
/*0x05cc*/ int                      PetID;
/*0x05f9*/ bool                     bSummoned;                    // by a PC or by anyone? need to investigate
/*0x05ec*/ int                      LastCastNum;
/*0x058c*/ unsigned int             LastCastTime;
/*0x0584*/ bool                     bBuffTimersOnHold;            // no you can't control this client side so unless you want to get banned leave it alone
/*0x05b0*/ unsigned int             EnduranceMax;
/*0x0385*/ char                     DragNames[0x2][0x40];
/*0x052c*/ unsigned int             SitStartTime;
/*0x0261*/ char                     GM;
/*0x0220*/ bool                     bAlwaysShowAura;
/*0x0614*/ unsigned int             MinuteTimer;
/*0x0198*/ int64_t                  HPCurrent;
/*0x0240*/ bool                     bShowHelm;
/*0x0510*/ int                      NpcTintIndex;
/*0x0430*/ CPhysicsInfo             LastCollision;
/*0x0221*/ bool                     bStationary;
/*0x0460*/ uint8_t                  IntimidateCount;
/*0x01fc*/ int                      DoSpecialMelee;
/*0x057c*/ unsigned int             TimeStamp;                    // updates all the time including when on a mount
/*0x05a8*/ uint8_t                  Level;
/*0x0524*/ unsigned int             LastTrapDamageTime;
/*0x0600*/ float                    CameraOffset;
/*0x0528*/ float                    AnimationSpeedRelated;
/*0x05d8*/ int                      RealEstateItemId;
/*0x04c8*/ SPAWNINFO*               pViewPlayer;
/*0x059c*/ unsigned int             LastTimeStoodStill;
/*0x0194*/ unsigned int             RespawnTimer;                 // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
/*0x0204*/ unsigned int             CombatSkillUsed[0x2];
/*0x04c0*/ unsigned int             StunTimer;
/*0x0414*/ unsigned int             LastSecondaryUseTime;
/*0x01ac*/ int                      Deity;
/*0x05a0*/ int64_t                  HPMax;
/*0x0228*/ int                      Dontknowyet2;
/*0x0534*/ unsigned int             SpellGemETA[0xf];             // InnateETA is now the last member in this array
/*0x05c0*/ int                      EnduranceCurrent;
/*0x0238*/ int                      CurrIOState;
/*0x0214*/ unsigned int             ACounter;                     // not sure what this one is for (m_uHibernatingCount)
/*0x0604*/ void*                    pRaceGenderInfo;              // todo this is not a void* so... map the CRaceGenderInfo class
/*0x0580*/ int                      berserker;
/*0x01a0*/ bool                     Mercenary;
/*0x0241*/ char                     Handle[0x20];
/*0x060c*/ float                    FallingStartZ;
/*0x0234*/ uint8_t                  FishingEvent;
/*0x05f4*/ int                      DontKnowYet;
/*0x01b1*/ char                     DraggingPlayer[0x40];
/*0x05e4*/ int                      HideMode;
/*0x0608*/ unsigned int             Zone;
/*0x0520*/ bool                     bAnimationOnPop;
/*0x0594*/ uint8_t                  HoldingAnimation;             // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
/*0x05c4*/ float                    MerchantGreed;
/*0x0611*/ uint8_t                  GMRank;
/*0x0570*/ int                      WarCry;
/*0x05f8*/ bool                     bOfflineMode;
/*0x0235*/ bool                     PvPFlag;
/*0x05d0*/ unsigned int             LastResendAddPlayerPacket;
/*0x0270*/ unsigned int             CombatSkillTicks[0x2];
/*0x0410*/ bool                     Sneak;
/*0x0268*/ uint8_t                  TitleVisible;
/*0x01b0*/ uint8_t                  LastAttack;
/*0x0218*/ int64_t                  GuildID;
/*0x04e8*/ float                    MyWalkSpeed;
/*0x0408*/ int                      SomeData[0x2];
/*0x05e8*/ bool                     bAttackRelated;
/*0x023c*/ int                      Trader;                       // found in CEverQuest__RightClickedOnPlayer_x
/*0x0598*/ int                      SecondaryTintIndex;
/*0x04c4*/ float                    MissileRangeToTarget;
/*0x0578*/ bool                     bSwitchMoved;                 // true when a door moves near the spawn
/*0x0200*/ uint8_t                  Blind;
/*0x041c*/ unsigned int             PotionTimer;
/*0x0518*/ unsigned int             MasterID;
/*0x0574*/ int                      AltAttack;
/*0x0514*/ bool                     bBetaBuffed;
/*0x04d4*/ EqItemGuid               realEstateItemGuid;
/*0x027c*/ char                     Title[0x80];
/*0x051c*/ unsigned int**           ppUDP;                        // UdpLibrary::UdpConnection
/*0x0420*/ int                      SomethingElse;
/*0x020c*/ float                    ViewHeight;
/*0x042c*/ unsigned int             NextSwim;
/*0x02fc*/ uint8_t                  HmmWhat;

