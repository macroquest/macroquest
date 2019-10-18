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

/*0x0194*/ float                    RunSpeed;                     // 0.70 on runspeed 5...
/*0x0198*/ int                      PrimaryTintIndex;
/*0x019c*/ unsigned int             LastTimeStoodStill;
/*0x01a0*/ float                    CameraOffset;
/*0x01a4*/ int                      AARank;                       // this really is the title id
/*0x01a8*/ int                      RealEstateID;
/*0x01ac*/ float                    FallingStartZ;
/*0x01b0*/ uint8_t                  LastAttack;
/*0x01b4*/ int                      SecondaryTintIndex;
/*0x01b8*/ unsigned int             CombatSkillUsed[0x2];
/*0x01c0*/ bool                     PvPFlag;
/*0x01c1*/ char                     Title[0x80];
/*0x0244*/ unsigned int             NextSwim;
/*0x0248*/ uint8_t                  GMRank;
/*0x024c*/ int                      NpcTintIndex;
/*0x0250*/ int                      Stuff;
/*0x0258*/ int64_t                  GuildID;
/*0x0260*/ unsigned int             PotionTimer;
/*0x0264*/ float                    MerchantGreed;
/*0x0268*/ unsigned int             LastSecondaryUseTime;
/*0x026c*/ bool                     bOfflineMode;
/*0x026d*/ char                     DragNames[0x2][0x40];
/*0x02f0*/ unsigned int             SpellGemETA[0xf];             // InnateETA is now the last member in this array
/*0x032c*/ float                    GetMeleeRangeVar1;            // used by GetMeleeRange (fScaleFactor)
/*0x0330*/ float                    MyWalkSpeed;
/*0x0334*/ uint8_t                  Light;
/*0x0335*/ uint8_t                  Type2;
/*0x0338*/ int64_t                  HPCurrent;
/*0x0340*/ bool                     bTempPet;
/*0x0341*/ uint8_t                  HoldingAnimation;             // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
/*0x0344*/ unsigned int             LastCastTime;
/*0x0348*/ unsigned int             SpellCooldownETA;
/*0x034c*/ uint8_t                  InPvPArea;                    // are we in a PvP area?
/*0x0350*/ int                      Anon;                         // found in EQPlayer__SetNameSpriteTint_x
/*0x0354*/ unsigned int             LastTick;
/*0x0358*/ unsigned int             LastPrimaryUseTime;
/*0x035c*/ bool                     bAttackRelated;
/*0x0360*/ unsigned int             RespawnTimer;                 // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
/*0x0364*/ uint8_t                  HmmWhat;
/*0x0368*/ int                      AFK;
/*0x036c*/ int                      LastCastNum;
/*0x0370*/ unsigned int**           ppUDP;                        // UdpLibrary::UdpConnection
/*0x0374*/ int                      SomethingElse;
/*0x0378*/ float                    AnimationSpeedRelated;
/*0x037c*/ int                      IsAttacking;                  // need to investigate
/*0x0380*/ bool                     bBetaBuffed;
/*0x0384*/ int                      Dontknowyet2;
/*0x0388*/ EqItemGuid               RealEstateItemGuid;
/*0x039c*/ int                      Buyer;
/*0x03a0*/ char                     Handle[0x20];
/*0x03c0*/ unsigned int             ACounter;                     // not sure what this one is for (m_uHibernatingCount)
/*0x03c4*/ int                      ManaCurrent;
/*0x03c8*/ unsigned int             MinuteTimer;
/*0x03cc*/ int                      EnduranceCurrent;
/*0x03d0*/ int64_t                  HPMax;
/*0x03d8*/ bool                     Sneak;
/*0x03dc*/ unsigned int             LastRangedUsedTime;
/*0x03e0*/ uint8_t                  IsPassenger;                  // if u are on a boat or airship or whatever
/*0x03e1*/ char                     DraggingPlayer[0x40];
/*0x0424*/ unsigned int             CombatSkillTicks[0x2];
/*0x042c*/ int                      PetID;
/*0x0430*/ unsigned int             LastMealTime;                 // last time we eat or drank
/*0x0434*/ int                      ManaMax;
/*0x0438*/ unsigned int             SitStartTime;
/*0x043c*/ EQC_INFO*                spawneqc_info;
/*0x0440*/ bool                     bStationary;
/*0x0444*/ SPAWNINFO*               pViewPlayer;
/*0x0448*/ uint8_t                  TitleVisible;
/*0x044c*/ unsigned int             LastRefresh;                  // last 18 sec tick
/*0x0450*/ bool                     bShowHelm;
/*0x0451*/ bool                     bAlwaysShowAura;
/*0x0454*/ unsigned int             LastResendAddPlayerPacket;
/*0x0458*/ uint8_t                  FindBits;
/*0x045c*/ unsigned int             MasterID;
/*0x0460*/ CPhysicsInfo             LastCollision;
/*0x0490*/ LAUNCHSPELLDATA          CastingData;                  // size: 0x58
/*0x04e8*/ bool                     LFG;
/*0x04e9*/ bool                     bBuffTimersOnHold;            // no you can't control this client side so unless you want to get banned leave it alone
/*0x04ec*/ unsigned int             TimeStamp;                    // updates all the time including when on a mount
/*0x04f0*/ void*                    pRaceGenderInfo;              // todo this is not a void* so... map the CRaceGenderInfo class
/*0x04f4*/ unsigned int             FishingETA;
/*0x04f8*/ unsigned int             NextIntimidateTime;
/*0x04fc*/ char                     LoginRelated[0x20];
/*0x051c*/ void*                    pTouchingSwitch;              // need to get that in here : struct _EQSWITCH
/*0x0520*/ uint8_t                  IntimidateCount;
/*0x0524*/ unsigned int             Meditating;
/*0x0528*/ uint8_t                  FD;
/*0x0529*/ char                     GM;
/*0x052a*/ bool                     bSummoned;                    // by a PC or by anyone? need to investigate
/*0x052c*/ unsigned int             LoginSerial;
/*0x0530*/ int                      RealEstateItemId;
/*0x0534*/ bool                     Linkdead;
/*0x0538*/ int                      WarCry;
/*0x053c*/ bool                     bAnimationOnPop;
/*0x0540*/ unsigned int             Zone;
/*0x0544*/ uint8_t                  Level;
/*0x0548*/ int                      DoSpecialMelee;
/*0x054c*/ char                     Suffix[0x80];
/*0x05cc*/ bool                     bSwitchMoved;                 // true when a door moves near the spawn
/*0x05d0*/ int                      AltAttack;
/*0x05d4*/ int                      Trader;                       // found in CEverQuest__RightClickedOnPlayer_x
/*0x05d8*/ unsigned int             StunTimer;
/*0x05dc*/ int                      berserker;
/*0x05e0*/ int                      CurrIOState;
/*0x05e4*/ unsigned int             CorpseDragCount;
/*0x05e8*/ unsigned int             LastTrapDamageTime;
/*0x05ec*/ float                    MissileRangeToTarget;
/*0x05f0*/ uint8_t                  FishingEvent;
/*0x05f1*/ uint8_t                  StandState;
/*0x05f2*/ uint8_t                  Blind;
/*0x05f4*/ int                      Deity;
/*0x05f8*/ float                    ViewHeight;
/*0x05fc*/ int                      SomeData[0x2];
/*0x0604*/ float                    BearingToTarget;
/*0x0608*/ int                      DontKnowYet;
/*0x060c*/ int                      HideMode;
/*0x0610*/ bool                     Mercenary;
/*0x0614*/ unsigned int             EnduranceMax;
/*0x0618*/ uint8_t                  CharClass;                    // Im pretty sure this isnt working
