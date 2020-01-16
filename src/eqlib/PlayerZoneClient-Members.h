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

	/*0x0194*/ int                      Buyer;
	/*0x0198*/ bool                     Sneak;
	/*0x019c*/ int                      EnduranceCurrent;
	/*0x01a0*/ unsigned int             LastCastTime;
	/*0x01a4*/ bool                     PvPFlag;
	/*0x01a8*/ unsigned int             SpellCooldownETA;
	/*0x01ac*/ unsigned int             SitStartTime;
	/*0x01b0*/ bool                     bAnimationOnPop;
	/*0x01b4*/ int                      Deity;
	/*0x01b8*/ unsigned int             StunTimer;
	/*0x01bc*/ uint8_t                  FishingEvent;
	/*0x01bd*/ char                     Handle[0x20];
	/*0x01e0*/ int                      IsAttacking;                  // need to investigate
	/*0x01e4*/ uint8_t                  FindBits;
	/*0x01e8*/ int                      PetID;
	/*0x01ec*/ unsigned int             LastResendAddPlayerPacket;
	/*0x01f0*/ int                      ManaCurrent;
	/*0x01f4*/ int                      ManaMax;
	/*0x01f8*/ unsigned int             NextSwim;
	/*0x01fc*/ unsigned int             CombatSkillTicks[0x2];
	/*0x0204*/ bool                     bOfflineMode;
	/*0x0208*/ int64_t                  HPCurrent;
	/*0x0210*/ int                      HideMode;
	/*0x0214*/ int                      berserker;
	/*0x0218*/ bool                     bBuffTimersOnHold;            // no you can't control this client side so unless you want to get banned leave it alone
	/*0x021c*/ int                      SecondaryTintIndex;
	/*0x0220*/ bool                     bSwitchMoved;                 // true when a door moves near the spawn
	/*0x0221*/ uint8_t                  CharClass;                    // Im pretty sure this isnt working
	/*0x0222*/ bool                     LFG;
	/*0x0223*/ uint8_t                  IsPassenger;                  // if u are on a boat or airship or whatever
	/*0x0224*/ float                    GetMeleeRangeVar1;            // used by GetMeleeRange (fScaleFactor)
	/*0x0228*/ int                      CurrIOState;
	/*0x022c*/ int                      LastCastNum;
	/*0x0230*/ unsigned int             PotionTimer;
	/*0x0234*/ int                      Dontknowyet2;
	/*0x0238*/ float                    FallingStartZ;
	/*0x023c*/ int                      DoSpecialMelee;
	/*0x0240*/ unsigned int             Meditating;
	/*0x0244*/ unsigned int             SpellGemETA[0xf];             // InnateETA is now the last member in this array
	/*0x0280*/ float                    ViewHeight;
	/*0x0284*/ EqItemGuid               realEstateItemGuid;
	/*0x0296*/ char                     LoginRelated[0x20];
	/*0x02b8*/ int                      NpcTintIndex;
	/*0x02bc*/ uint8_t                  Blind;
	/*0x02c0*/ float                    BearingToTarget;
	/*0x02c4*/ bool                     Linkdead;
	/*0x02c5*/ bool                     bSummoned;                    // by a PC or by anyone? need to investigate
	/*0x02c8*/ unsigned int             EnduranceMax;
	/*0x02cc*/ uint8_t                  FD;
	/*0x02cd*/ char                     DragNames[0x2][0x40];
	/*0x0350*/ unsigned int**           ppUDP;                        // UdpLibrary::UdpConnection
	/*0x0354*/ int                      SomethingElse;
	/*0x0358*/ uint8_t                  HoldingAnimation;             // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
	/*0x035c*/ int                      Stuff;
	/*0x0360*/ unsigned int             TimeStamp;                    // updates all the time including when on a mount
	/*0x0364*/ bool                     bShowHelm;
	/*0x0365*/ bool                     bTempPet;
	/*0x0368*/ float                    MerchantGreed;
	/*0x036c*/ float                    CameraOffset;
	/*0x0370*/ unsigned int             LastRangedUsedTime;
	/*0x0374*/ unsigned int             ACounter;                     // not sure what this one is for (m_uHibernatingCount)
	/*0x0378*/ char                     GM;
	/*0x037c*/ unsigned int             LastTrapDamageTime;
	/*0x0380*/ unsigned int             LastSecondaryUseTime;
	/*0x0384*/ uint8_t                  LastAttack;
	/*0x0385*/ uint8_t                  GMRank;
	/*0x0388*/ int                      SomeData[0x2];
	/*0x0390*/ uint8_t                  IntimidateCount;
	/*0x0394*/ int                      PrimaryTintIndex;
	/*0x0398*/ int                      Anon;                         // found in EQPlayer__SetNameSpriteTint_x
	/*0x039c*/ unsigned int             LoginSerial;
	/*0x03a0*/ int                      AltAttack;
	/*0x03a4*/ SPAWNINFO*               pViewPlayer;
	/*0x03a8*/ bool                     bStationary;
	/*0x03ac*/ int                      DontKnowYet;
	/*0x03b0*/ bool                     bAttackRelated;
	/*0x03b4*/ unsigned int             MasterID;
	/*0x03b8*/ CharacterZoneClient*     pCharacter;
	/*0x03bc*/ bool                     Mercenary;
	/*0x03bd*/ char                     Title[0x80];
	/*0x043d*/ uint8_t                  StandState;
	/*0x0440*/ float                    MissileRangeToTarget;
	/*0x0444*/ unsigned int             Zone;
	/*0x0448*/ unsigned int             MinuteTimer;
	/*0x044c*/ bool                     bBetaBuffed;
	/*0x044d*/ bool                     bAlwaysShowAura;
	/*0x0450*/ unsigned int             LastRefresh;                  // last 18 sec tick
	/*0x0454*/ unsigned int             NextIntimidateTime;
	/*0x0458*/ unsigned int             LastMealTime;                 // last time we eat or drank
	/*0x045c*/ int                      RealEstateItemId;
	/*0x0460*/ uint8_t                  Level;
	/*0x0461*/ uint8_t                  HmmWhat;
	/*0x0468*/ int64_t                  GuildID;
	/*0x0470*/ uint8_t                  InPvPArea;                    // are we in a PvP area?
	/*0x0474*/ unsigned int             LastPrimaryUseTime;
	/*0x0478*/ int64_t                  HPMax;
	/*0x0480*/ unsigned int             LastTick;
	/*0x0484*/ int                      RealEstateID;
	/*0x0488*/ int                      AFK;
	/*0x048c*/ unsigned int             LastTimeStoodStill;
	/*0x0490*/ void*                    pRaceGenderInfo;              // todo this is not a void* so... map the CRaceGenderInfo class
	/*0x0494*/ char                     DraggingPlayer[0x40];
	/*0x04d4*/ uint8_t                  TitleVisible;
	/*0x04d8*/ void*                    pTouchingSwitch;              // need to get that in here : struct _EQSWITCH
	/*0x04dc*/ unsigned int             CorpseDragCount;
	/*0x04e0*/ LAUNCHSPELLDATA          CastingData;                  // size: 0x58
	/*0x0538*/ unsigned int             FishingETA;
	/*0x053c*/ unsigned int             RespawnTimer;                 // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
	/*0x0540*/ char                     Suffix[0x80];
	/*0x05c0*/ float                    AnimationSpeedRelated;
	/*0x05c4*/ int                      Trader;                       // found in CEverQuest__RightClickedOnPlayer_x
	/*0x05c8*/ unsigned int             CombatSkillUsed[0x2];
	/*0x05d0*/ int                      WarCry;
	/*0x05d4*/ float                    MyWalkSpeed;
	/*0x05d8*/ uint8_t                  Type2;
	/*0x05dc*/ float                    RunSpeed;                     // 0.70 on runspeed 5...
	/*0x05e0*/ uint8_t                  Light;
	/*0x05e4*/ int                      AARank;                       // this really is the title id
	/*0x05e8*/ CPhysicsInfo             LastCollision;
