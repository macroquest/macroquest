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

/*0x0194*/ uint8_t                  StandState;
/*0x0195*/ uint8_t                  InPvPArea;                    // are we in a PvP area?
/*0x0198*/ unsigned int             LastRangedUsedTime;
/*0x019c*/ int                      EnduranceCurrent;
/*0x01a0*/ char                     GM;
/*0x01a1*/ bool                     bBetaBuffed;
/*0x01a4*/ unsigned int             CorpseDragCount;
/*0x01a8*/ int                      PetID;
/*0x01ac*/ unsigned int             FishingETA;
/*0x01b0*/ unsigned int             MasterID;
/*0x01b4*/ float                    RunSpeed;                     // 0.70 on runspeed 5...
/*0x01b8*/ bool                     Linkdead;
/*0x01bc*/ int                      berserker;
/*0x01c0*/ unsigned int             MinuteTimer;
/*0x01c4*/ bool                     bSummoned;                    // by a PC or by anyone? need to investigate
/*0x01c8*/ int                      Anon;                         // found in EQPlayer__SetNameSpriteTint_x
/*0x01cc*/ float                    BearingToTarget;
/*0x01d0*/ float                    MissileRangeToTarget;
/*0x01d4*/ bool                     bAlwaysShowAura;
/*0x01d8*/ unsigned int             LastCastTime;
/*0x01dc*/ int                      AltAttack;
/*0x01e0*/ float                    ViewHeight;
/*0x01e4*/ int                      Buyer;
/*0x01e8*/ int                      DoSpecialMelee;
/*0x01ec*/ uint8_t                  CharClass;                    // Im pretty sure this isnt working
/*0x01f0*/ int64_t                  HPCurrent;
/*0x01f8*/ int64_t                  HPMax;
/*0x0200*/ bool                     bBuffTimersOnHold;            // no you can't control this client side so unless you want to get banned leave it alone
/*0x0204*/ int                      ManaCurrent;
/*0x0208*/ int                      RealEstateItemId;
/*0x020c*/ int                      Dontknowyet2;
/*0x0210*/ int64_t                  GuildID;
/*0x0218*/ void*                    pRaceGenderInfo;              // todo this is not a void* so... map the CRaceGenderInfo class
/*0x021c*/ unsigned int             CombatSkillUsed[0x2];
/*0x0224*/ unsigned int             LastSecondaryUseTime;
/*0x0228*/ int                      CurrIOState;
/*0x022c*/ int                      Stuff;
/*0x0230*/ unsigned int             Zone;
/*0x0234*/ uint8_t                  LastAttack;
/*0x0235*/ uint8_t                  HoldingAnimation;             // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
/*0x0238*/ unsigned int             TimeStamp;                    // updates all the time including when on a mount
/*0x023c*/ bool                     bShowHelm;
/*0x023d*/ uint8_t                  IntimidateCount;
/*0x0240*/ unsigned int             LastTimeStoodStill;
/*0x0244*/ bool                     bAttackRelated;
/*0x0248*/ float                    MerchantGreed;
/*0x024c*/ unsigned int             EnduranceMax;
/*0x0250*/ unsigned int             LastMealTime;                 // last time we eat or drank
/*0x0254*/ unsigned int             LastTick;
/*0x0258*/ bool                     bSwitchMoved;                 // true when a door moves near the spawn
/*0x025c*/ int                      RealEstateID;
/*0x0260*/ unsigned int             PotionTimer;
/*0x0264*/ int                      LastCastNum;
/*0x0268*/ bool                     Mercenary;
/*0x026c*/ int                      SecondaryTintIndex;
/*0x0270*/ char                     Handle[0x20];
/*0x0290*/ unsigned int             ACounter;                     // not sure what this one is for (m_uHibernatingCount)
/*0x0294*/ unsigned int             SpellCooldownETA;
/*0x0298*/ int                      Trader;                       // found in CEverQuest__RightClickedOnPlayer_x
/*0x029c*/ uint8_t                  FishingEvent;
/*0x029d*/ char                     Suffix[0x80];
/*0x0320*/ float                    CameraOffset;
/*0x0324*/ float                    AnimationSpeedRelated;
/*0x0328*/ unsigned int             LastResendAddPlayerPacket;
/*0x032c*/ int                      AARank;                       // this really is the title id
/*0x0330*/ bool                     PvPFlag;
/*0x0331*/ bool                     bAnimationOnPop;
/*0x0332*/ char                     DragNames[0x2][0x40];
/*0x03b2*/ uint8_t                  IsPassenger;                  // if u are on a boat or airship or whatever
/*0x03b4*/ int                      PrimaryTintIndex;
/*0x03b8*/ int                      SomethingElse;
/*0x03bc*/ unsigned int             SpellGemETA[0xf];             // InnateETA is now the last member in this array
/*0x03f8*/ int                      SomeData[0x2];
/*0x0400*/ unsigned int             LastRefresh;                  // last 18 sec tick
/*0x0404*/ float                    MyWalkSpeed;
/*0x0408*/ unsigned int             Meditating;
/*0x040c*/ unsigned int             LoginSerial;
/*0x0410*/ uint8_t                  Light;
/*0x0414*/ unsigned int**           ppUDP;                        // UdpLibrary::UdpConnection
/*0x0418*/ int                      DontKnowYet;
/*0x041c*/ int                      AFK;
/*0x0420*/ EqItemGuid               RealEstateItemGuid;
/*0x0434*/ unsigned int             NextIntimidateTime;
/*0x0438*/ float                    FallingStartZ;
/*0x043c*/ int                      ManaMax;
/*0x0440*/ unsigned int             CombatSkillTicks[0x2];
/*0x0448*/ unsigned int             StunTimer;
/*0x044c*/ uint8_t                  FD;
/*0x0450*/ int                      IsAttacking;                  // need to investigate
/*0x0454*/ LAUNCHSPELLDATA          CastingData;                  // size: 0x58
/*0x04ac*/ SPAWNINFO*               pViewPlayer;
/*0x04b0*/ uint8_t                  GMRank;
/*0x04b1*/ char                     DraggingPlayer[0x40];
/*0x04f4*/ unsigned int             NextSwim;
/*0x04f8*/ int                      HideMode;
/*0x04fc*/ float                    GetMeleeRangeVar1;            // used by GetMeleeRange (fScaleFactor)
/*0x0500*/ uint8_t                  Type2;
/*0x0504*/ void*                    pTouchingSwitch;              // need to get that in here : struct _EQSWITCH
/*0x0508*/ EQC_INFO*                spawneqc_info;
/*0x050c*/ bool                     LFG;
/*0x050d*/ bool                     Sneak;
/*0x0510*/ int                      Deity;
/*0x0514*/ uint8_t                  HmmWhat;
/*0x0515*/ uint8_t                  Level;
/*0x0516*/ uint8_t                  FindBits;
/*0x0518*/ int                      NpcTintIndex;
/*0x051c*/ unsigned int             SitStartTime;
/*0x0520*/ uint8_t                  TitleVisible;
/*0x0521*/ char                     Title[0x80];
/*0x05a4*/ unsigned int             LastTrapDamageTime;
/*0x05a8*/ char                     LoginRelated[0x20];
/*0x05c8*/ bool                     bTempPet;
/*0x05cc*/ int                      WarCry;
/*0x05d0*/ bool                     bOfflineMode;
/*0x05d1*/ uint8_t                  Blind;
/*0x05d2*/ bool                     bStationary;
/*0x05d4*/ CPhysicsInfo             LastCollision;
/*0x0604*/ unsigned int             LastPrimaryUseTime;
/*0x0608*/ unsigned int             RespawnTimer;                 // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
