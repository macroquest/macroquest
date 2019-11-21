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
/*0x01a0*/ float                    ViewHeight;
/*0x01a4*/ float                    MissileRangeToTarget;
/*0x01a8*/ unsigned int             StunTimer;
/*0x01ac*/ uint8_t                  HoldingAnimation;             // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
/*0x01b0*/ float                    MerchantGreed;
/*0x01b4*/ float                    MyWalkSpeed;
/*0x01b8*/ unsigned int             MasterID;
/*0x01bc*/ char                     Handle[0x20];
/*0x01dc*/ uint8_t                  CharClass;                    // Im pretty sure this isnt working
/*0x01e0*/ unsigned int             SpellCooldownETA;
/*0x01e4*/ float                    AnimationSpeedRelated;
/*0x01e8*/ int                      EnduranceCurrent;
/*0x01ec*/ char                     LoginRelated[0x20];
/*0x020c*/ char                     DragNames[0x2][0x40];
/*0x028c*/ int                      DoSpecialMelee;
/*0x0290*/ unsigned int             LastRangedUsedTime;
/*0x0294*/ int                      LastCastNum;
/*0x0298*/ int                      SecondaryTintIndex;
/*0x029c*/ bool                     Linkdead;
/*0x029d*/ uint8_t                  LastAttack;
/*0x029e*/ uint8_t                  InPvPArea;                    // are we in a PvP area?
/*0x029f*/ char                     Suffix[0x80];
/*0x031f*/ uint8_t                  IsPassenger;                  // if u are on a boat or airship or whatever
/*0x0320*/ int                      AltAttack;
/*0x0324*/ uint8_t                  Blind;
/*0x0328*/ int                      IsAttacking;                  // need to investigate
/*0x032c*/ unsigned int             Meditating;
/*0x0330*/ unsigned int             FishingETA;
/*0x0334*/ bool                     bBetaBuffed;
/*0x0338*/ unsigned int             RespawnTimer;                 // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
/*0x033c*/ int                      Stuff;
/*0x0340*/ char                     DraggingPlayer[0x40];
/*0x0380*/ uint8_t                  FindBits;
/*0x0381*/ bool                     bOfflineMode;
/*0x0382*/ bool                     bTempPet;
/*0x0383*/ bool                     bSwitchMoved;                 // true when a door moves near the spawn
/*0x0384*/ unsigned int             LastTrapDamageTime;
/*0x0388*/ unsigned int             ACounter;                     // not sure what this one is for (m_uHibernatingCount)
/*0x038c*/ unsigned int             Zone;
/*0x0390*/ LAUNCHSPELLDATA          CastingData;                  // size: 0x58
/*0x03e8*/ float                    FallingStartZ;
/*0x03ec*/ unsigned int             LastRefresh;                  // last 18 sec tick
/*0x03f0*/ void*                    pTouchingSwitch;              // need to get that in here : struct _EQSWITCH
/*0x03f4*/ float                    RunSpeed;                     // 0.70 on runspeed 5...
/*0x03f8*/ EQC_INFO*                spawneqc_info;
/*0x03fc*/ unsigned int             EnduranceMax;
/*0x0400*/ uint8_t                  Light;
/*0x0404*/ int                      Anon;                         // found in EQPlayer__SetNameSpriteTint_x
/*0x0408*/ int                      WarCry;
/*0x040c*/ bool                     bShowHelm;
/*0x0410*/ int                      Dontknowyet2;
/*0x0414*/ unsigned int             NextSwim;
/*0x0418*/ uint8_t                  FD;
/*0x0419*/ char                     Title[0x80];
/*0x0499*/ bool                     PvPFlag;
/*0x049c*/ unsigned int             NextIntimidateTime;
/*0x04a0*/ uint8_t                  Type2;
/*0x04a4*/ int                      AFK;
/*0x04a8*/ int                      Deity;
/*0x04b0*/ int64_t                  GuildID;
/*0x04b8*/ int                      AARank;                       // this really is the title id
/*0x04bc*/ int                      RealEstateItemId;
/*0x04c0*/ unsigned int             PotionTimer;
/*0x04c4*/ bool                     bAnimationOnPop;
/*0x04c8*/ int                      HideMode;
/*0x04cc*/ char                     GM;
/*0x04d0*/ unsigned int             LastSecondaryUseTime;
/*0x04d8*/ int64_t                  HPMax;
/*0x04e0*/ int                      RealEstateID;
/*0x04e4*/ uint8_t                  StandState;
/*0x04e8*/ unsigned int             SpellGemETA[0xf];             // InnateETA is now the last member in this array
/*0x0524*/ float                    CameraOffset;
/*0x0528*/ int                      Trader;                       // found in CEverQuest__RightClickedOnPlayer_x
/*0x052c*/ unsigned int             MinuteTimer;
/*0x0530*/ unsigned int             TimeStamp;                    // updates all the time including when on a mount
/*0x0534*/ unsigned int             LoginSerial;
/*0x0538*/ bool                     bBuffTimersOnHold;            // no you can't control this client side so unless you want to get banned leave it alone
/*0x053c*/ SPAWNINFO*               pViewPlayer;
/*0x0540*/ int                      PetID;
/*0x0544*/ float                    BearingToTarget;
/*0x0548*/ uint8_t                  HmmWhat;
/*0x0549*/ bool                     bAlwaysShowAura;
/*0x054a*/ bool                     bSummoned;                    // by a PC or by anyone? need to investigate
/*0x054c*/ int                      CurrIOState;
/*0x0550*/ unsigned int             LastPrimaryUseTime;
/*0x0554*/ void*                    pRaceGenderInfo;              // todo this is not a void* so... map the CRaceGenderInfo class
/*0x0558*/ unsigned int             SitStartTime;
/*0x055c*/ bool                     Sneak;
/*0x055d*/ uint8_t                  TitleVisible;
/*0x055e*/ uint8_t                  FishingEvent;
/*0x0560*/ int                      SomeData[0x2];
/*0x0568*/ bool                     bStationary;
/*0x0569*/ bool                     bAttackRelated;
/*0x056c*/ unsigned int             CombatSkillTicks[0x2];
/*0x0574*/ uint8_t                  GMRank;
/*0x0578*/ int                      NpcTintIndex;
/*0x057c*/ uint8_t                  Level;
/*0x057d*/ EqItemGuid               realEstateItemGuid;
/*0x0590*/ int                      ManaMax;
/*0x0594*/ bool                     Mercenary;
/*0x0598*/ unsigned int             CorpseDragCount;
/*0x059c*/ unsigned int             LastTimeStoodStill;
/*0x05a0*/ CPhysicsInfo             LastCollision;
/*0x05d0*/ unsigned int             LastCastTime;
/*0x05d4*/ int                      Buyer;
/*0x05d8*/ int                      SomethingElse;
/*0x05dc*/ unsigned int             LastMealTime;                 // last time we eat or drank
/*0x05e0*/ int                      ManaCurrent;
/*0x05e4*/ uint8_t                  IntimidateCount;
/*0x05e8*/ float                    GetMeleeRangeVar1;            // used by GetMeleeRange (fScaleFactor)
/*0x05ec*/ bool                     LFG;
/*0x05f0*/ int                      DontKnowYet;
/*0x05f4*/ unsigned int             LastTick;
/*0x05f8*/ unsigned int**           ppUDP;                        // UdpLibrary::UdpConnection
/*0x05fc*/ unsigned int             LastResendAddPlayerPacket;
/*0x0600*/ unsigned int             CombatSkillUsed[0x2];
/*0x0608*/ int                      PrimaryTintIndex;
/*0x060c*/ int                      berserker;
