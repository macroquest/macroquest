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

/*0x0194*/ unsigned int             SpellCooldownETA;
/*0x0198*/ uint8_t                  CharClass;                    // Im pretty sure this isnt working
/*0x0199*/ bool                     bSummoned;                    // by a PC or by anyone? need to investigate
/*0x019c*/ unsigned int             Zone;
/*0x01a0*/ void*                    pRaceGenderInfo;              // todo this is not a void* so... map the CRaceGenderInfo class
/*0x01a4*/ float                    MyWalkSpeed;
/*0x01a8*/ unsigned int             NextIntimidateTime;
/*0x01ac*/ unsigned int             CombatSkillTicks[0x2];
/*0x01b4*/ uint8_t                  StandState;
/*0x01b8*/ unsigned int             LastRangedUsedTime;
/*0x01bc*/ char                     DraggingPlayer[0x40];
/*0x01fc*/ LAUNCHSPELLDATA          CastingData;                  // size: 0x58
/*0x0254*/ bool                     Mercenary;
/*0x0255*/ char                     Suffix[0x80];
/*0x02d8*/ int                      PetID;
/*0x02dc*/ float                    RunSpeed;                     // 0.70 on runspeed 5...
/*0x02e0*/ float                    BearingToTarget;
/*0x02e4*/ bool                     bBetaBuffed;
/*0x02e8*/ SPAWNINFO*               pViewPlayer;
/*0x02ec*/ bool                     bStationary;
/*0x02f0*/ int                      HideMode;
/*0x02f4*/ uint8_t                  LastAttack;
/*0x02f8*/ int64_t                  GuildID;
/*0x0300*/ int                      AltAttack;
/*0x0304*/ char                     Title[0x80];
/*0x0384*/ unsigned int             LastResendAddPlayerPacket;
/*0x0388*/ bool                     bSwitchMoved;                 // true when a door moves near the spawn
/*0x0389*/ bool                     bShowHelm;
/*0x038c*/ int                      DontKnowYet;
/*0x0390*/ bool                     bBuffTimersOnHold;            // no you can't control this client side so unless you want to get banned leave it alone
/*0x0394*/ int                      ManaMax;
/*0x0398*/ int                      Stuff;
/*0x039c*/ unsigned int             PotionTimer;
/*0x03a0*/ unsigned int             ACounter;                     // not sure what this one is for (m_uHibernatingCount)
/*0x03a4*/ int                      RealEstateID;
/*0x03a8*/ char                     LoginRelated[0x20];
/*0x03c8*/ int                      EnduranceCurrent;
/*0x03cc*/ unsigned int             LastTick;
/*0x03d0*/ int                      WarCry;
/*0x03d4*/ uint8_t                  Blind;
/*0x03d5*/ uint8_t                  IsPassenger;                  // if u are on a boat or airship or whatever
/*0x03d6*/ char                     DragNames[0x2][0x40];
/*0x0458*/ int                      SomeData[0x2];
/*0x0460*/ unsigned int             LastSecondaryUseTime;
/*0x0464*/ uint8_t                  HmmWhat;
/*0x0468*/ int                      AFK;
/*0x046c*/ unsigned int             FishingETA;
/*0x0470*/ float                    MissileRangeToTarget;
/*0x0474*/ unsigned int             LoginSerial;
/*0x0478*/ bool                     Sneak;
/*0x047c*/ int                      Buyer;
/*0x0480*/ unsigned int             EnduranceMax;
/*0x0484*/ bool                     bAnimationOnPop;
/*0x0488*/ int                      NpcTintIndex;
/*0x048c*/ unsigned int             CombatSkillUsed[0x2];
/*0x0494*/ int                      RealEstateItemId;
/*0x0498*/ unsigned int             LastCastTime;
/*0x049c*/ unsigned int             SpellGemETA[0xf];             // InnateETA is now the last member in this array
/*0x04d8*/ int                      SomethingElse;
/*0x04dc*/ int                      AARank;                       // this really is the title id
/*0x04e0*/ char                     Handle[0x20];
/*0x0500*/ unsigned int             LastPrimaryUseTime;
/*0x0504*/ unsigned int             Meditating;
/*0x0508*/ int                      PrimaryTintIndex;
/*0x050c*/ unsigned int             TimeStamp;                    // updates all the time including when on a mount
/*0x0510*/ uint8_t                  FishingEvent;
/*0x0518*/ int64_t                  HPCurrent;
/*0x0520*/ uint8_t                  Light;
/*0x0524*/ unsigned int             LastTrapDamageTime;
/*0x0528*/ EqItemGuid               realEstateItemGuid;
/*0x053c*/ unsigned int             MinuteTimer;
/*0x0540*/ int                      Dontknowyet2;
/*0x0544*/ int                      Trader;                       // found in CEverQuest__RightClickedOnPlayer_x
/*0x0548*/ void*                    pTouchingSwitch;              // need to get that in here : struct _EQSWITCH
/*0x054c*/ bool                     bAlwaysShowAura;
/*0x054d*/ bool                     LFG;
/*0x0550*/ unsigned int**           ppUDP;                        // UdpLibrary::UdpConnection
/*0x0554*/ bool                     Linkdead;
/*0x0558*/ unsigned int             NextSwim;
/*0x055c*/ unsigned int             StunTimer;
/*0x0560*/ float                    FallingStartZ;
/*0x0564*/ float                    AnimationSpeedRelated;
/*0x0568*/ unsigned int             CorpseDragCount;
/*0x0570*/ int64_t                  HPMax;
/*0x0578*/ int                      LastCastNum;
/*0x057c*/ int                      IsAttacking;                  // need to investigate
/*0x0580*/ unsigned int             LastMealTime;                 // last time we eat or drank
/*0x0584*/ uint8_t                  TitleVisible;
/*0x0585*/ uint8_t                  GMRank;
/*0x0588*/ unsigned int             LastRefresh;                  // last 18 sec tick
/*0x058c*/ int                      ManaCurrent;
/*0x0590*/ int                      SecondaryTintIndex;
/*0x0594*/ float                    GetMeleeRangeVar1;            // used by GetMeleeRange (fScaleFactor)
/*0x0598*/ bool                     PvPFlag;
/*0x0599*/ uint8_t                  InPvPArea;                    // are we in a PvP area?
/*0x059c*/ unsigned int             MasterID;
/*0x05a0*/ uint8_t                  Type2;
/*0x05a1*/ bool                     bOfflineMode;
/*0x05a2*/ uint8_t                  FindBits;
/*0x05a4*/ int                      Deity;
/*0x05a8*/ unsigned int             RespawnTimer;                 // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
/*0x05ac*/ EQC_INFO*                spawneqc_info;
/*0x05b0*/ bool                     bAttackRelated;
/*0x05b4*/ unsigned int             SitStartTime;
/*0x05b8*/ int                      DoSpecialMelee;
/*0x05bc*/ uint8_t                  FD;
/*0x05c0*/ float                    MerchantGreed;
/*0x05c4*/ unsigned int             LastTimeStoodStill;
/*0x05c8*/ bool                     bTempPet;
/*0x05c9*/ uint8_t                  IntimidateCount;
/*0x05cc*/ int                      Anon;                         // found in EQPlayer__SetNameSpriteTint_x
/*0x05d0*/ uint8_t                  HoldingAnimation;             // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
/*0x05d4*/ int                      berserker;
/*0x05d8*/ CPhysicsInfo             LastCollision;
/*0x0608*/ char                     GM;
/*0x060c*/ int                      CurrIOState;
/*0x0610*/ float                    CameraOffset;
/*0x0614*/ float                    ViewHeight;
/*0x0618*/ uint8_t                  Level;
