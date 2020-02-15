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

#pragma once

#include "Common.h"
#include "Containers.h"
#include "CXStr.h"
#include "Items.h"
#include "Spells.h"

// This is the home of all things related to what used to be called SPAWNINFO,
// plus a few extra things until they find a home of their own.
//
// Class hierarchies:
//
// SPAWNINFO:
//   PlayerClient -> PlayerZoneClient -> PlayerBase

namespace eqlib {

class CLightInterface;
class CParticlePointInterface;
class EQObject;
class EQSwitch;
class EQPlacedItem;
class PlayerAnimationBase;
class PlayerBase;
class PlayerClient;
class PcClient;
class MissileBase;

struct EQC_INFO;
struct LAUNCHSPELLDATA;
struct chngForm;

#if 0 // when we're ready
using SPAWNINFO = PlayerClient;
using PSPAWNINFO = PlayerClient *;
#endif

struct SPAWNINFO;

struct [[offsetcomments]] ARMOR
{
/*0x00*/ unsigned int ID;                        // idfile on Lucy
/*0x04*/ unsigned int Var;
/*0x08*/ unsigned int Material;
/*0x0c*/ unsigned int NewArmorID;
/*0x10*/ unsigned int NewArmorType;
/*0x14*/
};
using PARMOR [[deprecated]] = ARMOR*;

struct [[offsetcomments]] EQUIPMENT
{
	union {
	/*0x00*/ struct { ARMOR Item[9]; };          // EQUIPARRAY
		struct                                   // EQUIPUNIQUE
		{
		/*0x00*/ ARMOR Head;
		/*0x14*/ ARMOR Chest;
		/*0x28*/ ARMOR Arms;
		/*0x3c*/ ARMOR Wrists;
		/*0x50*/ ARMOR Hands;
		/*0x64*/ ARMOR Legs;
		/*0x78*/ ARMOR Feet;
		/*0x8c*/ ARMOR Primary;
		/*0xa0*/ ARMOR Offhand;
		};
	};
/*0xb4*/
};
using PEQUIPMENT [[deprecated]] = EQUIPMENT*;

class CObjectGroupStage;

class [[offsetcomments]] CObjectGroupStageInstance : public TListNode<CObjectGroupStageInstance>
{
public:
/*0x0c*/ CActorInterface* pActor1;
/*0x10*/ CActorInterface* pActor2;
/*0x14*/ CObjectGroupStage* pStage;
/*0x18*/
};

//============================================================================
// ActorAnimation
//============================================================================

// TODO: Move Actor classes to its own header
class [[offsetcomments]] ActorAnimation
{
public:
/*0x00*/ ActorAnimation*    pPrev;
/*0x04*/ ActorAnimation*    pNext;
/*0x08*/ char               Name[30];
/*0x28*/ void*              pActordef;                // CActorDefinitionInterface*
/*0x2c*/ void**             Anim;                     // EQAnimation
/*0x30*/ int                NumBones;
/*0x34*/ bool               bUsesLuclinAnimations;
/*0x35*/ bool               bNewStyleModel;
/*0x38*/ float              ParticleEmitterScaleFactor;
/*0x3c*/ float              TargetIndicatorScaleFactor;
/*0x40*/ float              FirstPersonCameraOffset;
/*0x44*/ float              ThirdPersonCameraOffset;
/*0x48*/ float              VerticalCameraOffset;
/*0x4c*/ float              CollisionSphereScaleFactor;
/*0x50*/ float              ZoomCameraMinimumDistance;
/*0x54*/ int                NumAnimations;
/*0x58*/ int                NumAnimationSlots;
/*0x5c*/
};

//============================================================================
// CActorApplicationData
//============================================================================
class CActorApplicationData
{
public:
	enum EApplicationDataType
	{
		ePlayerBase,
		eMissileBase,
		eObject,
		eSwitch,
		eEnvEmitter,
		ePlacedItem
	};

	virtual EApplicationDataType GetActorApplicationDataType() const = 0;

	virtual const MissileBase* AsMissileBase() const = 0;
	virtual MissileBase* AsMissileBase() = 0;

	virtual const PlayerBase* AsPlayerBase() const = 0;
	virtual PlayerBase* AsPlayerBase() = 0;

	virtual const EQObject* AsObject() const = 0;
	virtual EQObject* AsObject() = 0;

	virtual const EQSwitch *AsSwitch() const = 0;
	virtual EQSwitch *AsSwitch() = 0;

	virtual const EQPlacedItem* AsPlacedItem() const = 0;
	virtual EQPlacedItem* AsPlacedItem() = 0;
};

//============================================================================
// ActorBase
//============================================================================

class [[offsetcomments]] ActorBase
{
public:
	EQLIB_OBJECT float GetBoundingRadius();

/*0x000*/ void*       vfTableActorClient;
/*0x004*/ char        TextureType;
/*0x005*/ char        Material;
/*0x006*/ char        Variation;
/*0x007*/ char        HeadType;
/*0x008*/ uint8_t     FaceStyle;
/*0x009*/ uint8_t     HairColor;
/*0x00a*/ uint8_t     FacialHairColor;
/*0x00b*/ uint8_t     EyeColor1;
/*0x00c*/ uint8_t     EyeColor2;
/*0x00d*/ uint8_t     HairStyle;
/*0x00e*/ uint8_t     FacialHair;
/*0x010*/ int         Race;
/*0x014*/ int         Race2;
/*0x018*/ int         Class;
/*0x01c*/ uint8_t     Gender;
/*0x01d*/ char        ActorDef[0x40];
/*0x060*/ unsigned intArmorColor[0x9];
/*0x084*/ bool        bShowHelm;
/*0x088*/ int         Heritage;                 // drakkin only face setting
/*0x08c*/ int         Tattoo;                   // drakkin only face setting
/*0x090*/ int         Details;                  // drakkin only face setting
/*0x094*/ EQUIPMENT   ActorEquipment;           // 0x0ff8 is confirmed // size 0xb4
/*0x148*/
};

//============================================================================
// ActorClient
//============================================================================

// size 0x1140 see 63D777 in Sep 25 2018 Test
//.text:0063D777                 mov     [edi+1B8h], eax so last member is at 1B8h which makes the struct size 0x1bc
// 0x1bc + 0x0f84 is 0x1140
class [[offsetcomments]] ActorClient : public ActorBase
{
public:
	// EQLIB_OBJECT const CVector3& GetPosition() const;
	// EQLIB_OBJECT void GetPosition(CVector3*) const;

/*0x148*/ int         LeftEyeMaterialIndex;
/*0x14c*/ int         RightEyeMaterialIndex;
/*0x150*/ CParticlePointInterface* pParticlePoints[0xa];
/*0x178*/ void*       pLowerBones;
/*0x17c*/ void*       pUpperBones;
/*0x180*/ void*       pcactorex;                // todo: move to ActorInterface*
/*0x184*/ CLightInterface* pLight;
/*0x188*/ ActorAnimation*  pActorAnimation;
/*0x18c*/ TList<CObjectGroupStageInstance> StageInstances;          // size 0x8
/*0x194*/ bool        bActiveTransition;
/*0x198*/ unsigned int CurrentStage;
/*0x19c*/ float       ZOffset;
/*0x1a0*/ float       TempY;//related to ZOffset adjustments I *think*
/*0x1a4*/ float       TempX;
/*0x1a8*/ float       TempZ;
/*0x1ac*/ bool        bReplacedStaticObject;
/*0x1b0*/ int         PartialFaceNumber;
/*0x1b4*/ bool        bNewArmorDisabled;
/*0x1b8*/ CActorApplicationData* pAppData;
/*0x1bc*/
};

//============================================================================
// Misc
//============================================================================

enum EActorType
{
	Undefined                = 0,
	Player                   = 1,
	Corpse                   = 2,
	Switch                   = 3,
	Missile                  = 4,
	Object                   = 5,
	Ladder                   = 6,
	Tree                     = 7,
	Wall                     = 8,
	PlacedObject             = 9,
};

enum GravityBehavior
{
	Ground,
	Flying,
	Levitating,
	Water,
	Floating,//boat
	LevitateWhileRunning
};

class [[offsetcomments]] CPhysicsInfo
{
public:
/*0x00*/ float               Y;
/*0x04*/ float               X;
/*0x08*/ float               Z;
/*0x0c*/ float               SpeedY;
/*0x10*/ float               SpeedX;
/*0x14*/ float               SpeedZ;
/*0x18*/ float               SpeedRun;
/*0x1c*/ float               Heading;
/*0x20*/ float               Angle;
/*0x24*/ float               AccelAngle;
/*0x28*/ float               SpeedHeading;
/*0x2c*/ float               CameraAngle;
/*0x30*/
};

struct [[offsetcomments]] SDoCollisionMovementStats
{
/*0x00*/ CPhysicsInfo        Source;
/*0x30*/ float               DestY;
/*0x34*/ float               DestX;
/*0x38*/ float               DestZ;
/*0x3c*/ float               SourceFloor;
/*0x40*/ float               DestFloor;
/*0x44*/ CPhysicsInfo        Dest;
/*0x74*/
};

class [[offsetcomments]] CLineBase
{
public:
/*0x00*/ float OriginY;
/*0x04*/ float OriginX;
/*0x08*/ float OriginZ;
/*0x0c*/ float DirectionY;
/*0x10*/ float DirectionX;
/*0x14*/ float DirectionZ;
/*0x18*/
};

class CLineSegment : public CLineBase
{
};

class [[offsetcomments]] CCapsule : public CLineSegment
{
public:
/*0x18*/ float Radius;
/*0x1c*/
};

struct [[offsetcomments]] PhysicsEffect
{
/*0x00*/ int SpellID;
/*0x04*/ int CasterID;
/*0x08*/ int EffectID;
/*0x0c*/ int BaseEffect;
/*0x10*/
};

struct [[offsetcomments]] FELLOWSHIPMEMBER
{
/*0x00*/ unsigned int WorldID;
/*0x04*/ char         Name[0x40];
/*0x44*/ unsigned int ZoneID;
/*0x48*/ unsigned int Level;
/*0x4c*/ unsigned int Class;
/*0x50*/ unsigned int LastOn;
/*0x54*/
};
using PFELLOWSHIPMEMBER [[deprecated]] = FELLOWSHIPMEMBER*;

struct FSDATA
{
	char Strings[0x20];   // need to check what these are...
};

// 20121128 - ieatacid  0x9e4
// Dec 13 2016 - eqmule  0x9e8 see 5C3F9F
struct [[offsetcomments]] FELLOWSHIPINFO
{
/*0x000*/ unsigned int     Version;
/*0x004*/ unsigned int     Version2;                       // just place holders for now, ill fix these later
/*0x008*/ unsigned int     Version3;
/*0x00c*/ unsigned int     Version4;
/*0x010*/ unsigned int     FellowshipID;
/*0x014*/ unsigned int     FellowshipID2;                  // guild does this too, need to figure out why
/*0x018*/ char             Leader[0x40];
/*0x058*/ char             MotD[0x400];
/*0x458*/ int              Members;
/*0x45c*/ FELLOWSHIPMEMBER FellowshipMember[0xc];          // size 0xc * 0x54 = 0x3f0
/*0x84c*/ unsigned int     Sync;
/*0x850*/ FSDATA           Somedata[0xc];//size 0x180
/*0x9d0*/ bool             bExpSharingEnabled[0xc];
/*0x9dc*/ bool             bSharedExpCapped[0xc];
/*0x9e8*/
};
using PFELLOWSHIPINFO [[deprecated]] = FELLOWSHIPINFO *;

// size 0x58 see 442783 in eqgame.exe 2017 04 11 test
struct [[offsetcomments]] LAUNCHSPELLDATA
{
/*0x00*/ UINT    SpellETA;                       // Calculated TimeStamp when current spell being cast will land. 0 while not casting.
/*0x04*/ int     SpellID;                        // -1 = not casting a spell
/*0x08*/ BYTE    SpellSlot;                      // 0xFF if not casting, otherwise it's the spell gem number (0 - 8)
/*0x09*/ BYTE    SpellLevel;
/*0x0c*/ ITEMLOCATION ItemLocation;
/*0x18*/ ItemSpellTypes ItemCastType;
/*0x1c*/ int     ItemID;
/*0x20*/ float   CastingY;
/*0x24*/ float   CastingX;
/*0x28*/ int     DamageID;
/*0x2c*/ UINT    TargetID;
/*0x30*/ bool    bDetrimental;
/*0x31*/ bool    bResetMeleeTimers;
/*0x32*/ bool    bResetAAOnNotTakeHold;
/*0x33*/ bool    bFreeTarget;
/*0x34*/ float   TargetPosY;
/*0x38*/ float   TargetPosX;
/*0x3c*/ float   TargetPosZ;
/*0x40*/ bool    bTwinCast;
/*0x41*/ bool    bLanded;
/*0x42*/ bool    bNPCTarget;
/*0x43*/ bool    bHasHitRecourse;
/*0x44*/ float   AnchorPosY;
/*0x48*/ float   AnchorPosX;
/*0x4c*/ float   AnchorPosZ;
/*0x50*/ bool    bIgnoreRange;
/*0x51*/ bool    bResetAAOnNotTakeHoldSuccess;
/*0x54*/ int     Unknown0x54;
/*0x58*/

	bool IsCasting() const
	{
		return SpellID != -1;
	}
};
using PLAUNCHSPELLDATA [[deprecated]] = LAUNCHSPELLDATA*;

//============================================================================
// PhysicsBase & PlayerPhysics
//============================================================================

class [[offsetcomments]] PhysicsBase
{
public:
/*0x00*/ void* vtable2;
/*0x04*/ bool  bApplyGravity;
/*0x08*/
};

class [[offsetcomments]] PlayerPhysics : public PhysicsBase
{
public:
/*0x08*/ SPAWNINFO*       pSpawn;              // PlayerBase
/*0x0c*/ GravityBehavior  Levitate;
// bobbing control
/*0x10*/ int              UpDownIndex;
/*0x14*/ int              LeftRightIndex;
/*0x18*/ int              UpDownSpeed;
/*0x1c*/ int              LeftRightSpeed;
/*0x20*/ float            LeftRightDist;
/*0x24*/ float            UpDownDist;
/*0x28*/
};

class PlayerPhysicsClient : public PlayerPhysics
{
public:
/*0x1Fb8*/
};

//============================================================================
// SPAWNINFO
//============================================================================

// this is the old structure. It is equivalent to PlayerClient.

// actual size 0x2020 in Feb 20 2016 Live (see 64B6A0) - eqmule
struct [[offsetcomments]] SPAWNINFO
{
	// this is the "SPAWNINFOHEADER"
/*0x0000*/ void*             vtable;
/*0x0004*/ SPAWNINFO*        pPrev;
/*0x0008*/ SPAWNINFO*        pNext;
/*0x000c*/ void*             List;

/* ******************** PlayerBase Starts Here ***************** */
/*0x0010*/ float             JumpStrength;
/*0x0014*/ float             SwimStrength;
/*0x0018*/ float             SpeedMultiplier;
/*0x001c*/ float             AreaFriction;
/*0x0020*/ float             AccelerationFriction;
/*0x0024*/ EActorType        CollidingType;
/*0x0028*/ float             FloorHeight;
/*0x002c*/ bool              bSinksInWater;
/*0x0030*/ unsigned int      PlayerTimeStamp;              // doesn't update when on a Vehicle (mounts/boats etc)
/*0x0034*/ unsigned int      LastTimeIdle;
/*0x0038*/ char              Lastname[0x20];
/*0x0058*/ float             AreaHPRegenMod;               // from guild hall pools etc.
/*0x005c*/ float             AreaEndRegenMod;
/*0x0060*/ float             AreaManaRegenMod;
/*0x0064*/ float             Y;
/*0x0068*/ float             X;
/*0x006c*/ float             Z;
/*0x0070*/ float             SpeedY;
/*0x0074*/ float             SpeedX;
/*0x0078*/ float             SpeedZ;
/*0x007c*/ float             SpeedRun;
/*0x0080*/ float             Heading;
/*0x0084*/ float             Angle;
/*0x0088*/ float             AccelAngle;
/*0x008c*/ float             SpeedHeading;
/*0x0090*/ float             CameraAngle;
/*0x0094*/ unsigned int      UnderWater;                   // LastHeadEnvironmentType
/*0x0098*/ unsigned int      LastBodyEnvironmentType;
/*0x009c*/ unsigned int      LastFeetEnvironmentType;
/*0x00a0*/ uint8_t           HeadWet;                      // these really are environment related, like lava as well for example
/*0x00a1*/ uint8_t           FeetWet;
/*0x00a2*/ uint8_t           BodyWet;
/*0x00a3*/ uint8_t           LastBodyWet;
/*0x00a4*/ char              Name[0x40];                   // ie priest_of_discord00
/*0x00e4*/ char              DisplayedName[0x40];          // ie Priest of Discord
/*0x0124*/ uint8_t           PossiblyStuck;                // never seen this be 1 so maybe it was used a a point but not now...
/*0x0125*/ uint8_t           Type;
/*0x0128*/ unsigned int**    BodyType;                     // this really should be renamed to charprops or something its broken anyway
/*0x012c*/ uint8_t           CharPropFiller[0xc];          // well since the above is a CharacterPropertyHash we have to pad here
/*0x0138*/ float             AvatarHeight;                 // height of avatar from groundwhen standing for sure see 5C06A0 in Jun 10 2019 test
/*0x013c*/ float             Height;
/*0x0140*/ float             Width;
/*0x0144*/ float             Length;
/*0x0148*/ int               Unknown0x0148;
/*0x014c*/ int               Unknown0x014C;
/*0x0150*/ unsigned int      SpawnID;
/*0x0154*/ unsigned int      PlayerState;                  // 0=Idle 1=Open 2=WeaponSheathed 4=Aggressive 8=ForcedAggressive 0x10=InstrumentEquipped 0x20=Stunned 0x40=PrimaryWeaponEquipped 0x80=SecondaryWeaponEquipped
/*0x0158*/ SPAWNINFO*        Vehicle;                      // NULL until you collide with a vehicle (boat,airship etc)
/*0x015c*/ SPAWNINFO*        Mount;                        // NULL if no mount present
/*0x0160*/ SPAWNINFO*        Rider;                        // SPAWNINFO of mount's rider
/*0x0164*/ unsigned int      Unknown0x0164;
/*0x0168*/ bool              Targetable;                   // true if mob is targetable
/*0x0169*/ bool              bTargetCyclable;
/*0x016a*/ bool              bClickThrough;
/*0x016b*/ bool              bBeingFlung;
/*0x016c*/ unsigned int      FlingActiveTimer;
/*0x0170*/ unsigned int      FlingTimerStart;
/*0x0174*/ bool              bFlingSomething;
/*0x0178*/ float             FlingY;
/*0x017c*/ float             FlingX;
/*0x0180*/ float             FlingZ;
/*0x0184*/ bool              bFlingSnapToDest;
/*0x0188*/ int               SplineID;
/*0x018c*/ int               SplineRiderID;
/* *********************** PlayerBase Ends Here ********************** */
/* ******************** PlayerZoneClient Starts Here ***************** */
/*0x0190*/ unsigned int      LastIntimidateUse;

// @start: PlayerZoneClient Members
/*0x0194*/ bool                     bOfflineMode;
/*0x0198*/ int64_t                  HPCurrent;
/*0x01a0*/ uint8_t                  CharClass;                    // Im pretty sure this isnt working
/*0x01a1*/ bool                     bAlwaysShowAura;
/*0x01a4*/ int                      EnduranceCurrent;
/*0x01a8*/ uint8_t                  FD;
/*0x01ac*/ float                    AnimationSpeedRelated;
/*0x01b0*/ int                      RealEstateID;
/*0x01b4*/ char                     Suffix[0x80];
/*0x0234*/ unsigned int             LastRangedUsedTime;
/*0x0238*/ unsigned int             SpellGemETA[0xf];             // InnateETA is now the last member in this array
/*0x0274*/ char                     DraggingPlayer[0x40];
/*0x02b4*/ LAUNCHSPELLDATA          CastingData;                  // size: 0x58
/*0x030c*/ uint8_t                  FishingEvent;
/*0x030d*/ char                     Title[0x80];
/*0x038d*/ char                     Handle[0x20];
/*0x03ad*/ uint8_t                  LastAttack;
/*0x03b0*/ float                    CameraOffset;
/*0x03b4*/ bool                     bAttackRelated;
/*0x03b8*/ unsigned int             LastTrapDamageTime;
/*0x03bc*/ bool                     bShowHelm;
/*0x03c0*/ unsigned int             NextSwim;
/*0x03c4*/ unsigned int             CombatSkillUsed[0x2];
/*0x03cc*/ SPAWNINFO*               pViewPlayer;
/*0x03d0*/ int                      NpcTintIndex;
/*0x03d4*/ int                      PetID;
/*0x03d8*/ unsigned int             FishingETA;
/*0x03dc*/ void*                    pRaceGenderInfo;              // todo this is not a void* so... map the CRaceGenderInfo class
/*0x03e0*/ float                    GetMeleeRangeVar1;            // used by GetMeleeRange (fScaleFactor)
/*0x03e4*/ bool                     bBetaBuffed;
/*0x03e5*/ uint8_t                  Type2;
/*0x03e8*/ int                      LastCastNum;
/*0x03ec*/ int                      Deity;
/*0x03f0*/ bool                     Mercenary;
/*0x03f1*/ uint8_t                  GMRank;
/*0x03f2*/ bool                     Linkdead;
/*0x03f3*/ bool                     bBuffTimersOnHold;            // no you can't control this client side so unless you want to get banned leave it alone
/*0x03f4*/ int                      Stuff;
/*0x03f8*/ uint8_t                  StandState;
/*0x03fc*/ unsigned int             CombatSkillTicks[0x2];
/*0x0404*/ bool                     bAnimationOnPop;
/*0x0408*/ unsigned int             LastMealTime;                 // last time we eat or drank
/*0x040c*/ bool                     bTempPet;
/*0x040d*/ bool                     bStationary;
/*0x0410*/ int                      AltAttack;
/*0x0414*/ int                      Anon;                         // found in EQPlayer__SetNameSpriteTint_x
/*0x0418*/ uint8_t                  InPvPArea;                    // are we in a PvP area?
/*0x041c*/ int                      WarCry;
/*0x0420*/ unsigned int             CorpseDragCount;
/*0x0424*/ char                     GM;
/*0x0425*/ bool                     Sneak;
/*0x0428*/ int                      DontKnowYet;
/*0x042c*/ unsigned int             LastTick;
/*0x0430*/ CharacterZoneClient*     pCharacter;
/*0x0434*/ unsigned int             LastTimeStoodStill;
/*0x0438*/ uint8_t                  Blind;
/*0x043c*/ unsigned int             SitStartTime;
/*0x0440*/ int                      SomethingElse;
/*0x0444*/ bool                     PvPFlag;
/*0x0448*/ float                    BearingToTarget;
/*0x044c*/ int                      Buyer;
/*0x0450*/ char                     DragNames[0x2][0x40];
/*0x04d0*/ unsigned int             LastResendAddPlayerPacket;
/*0x04d4*/ unsigned int             ACounter;                     // not sure what this one is for (m_uHibernatingCount)
/*0x04d8*/ unsigned int             LastCastTime;
/*0x04dc*/ unsigned int             MasterID;
/*0x04e0*/ uint8_t                  FindBits;
/*0x04e4*/ unsigned int             LoginSerial;
/*0x04e8*/ uint8_t                  HoldingAnimation;             // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
/*0x04ec*/ float                    FallingStartZ;
/*0x04f0*/ uint8_t                  Level;
/*0x04f1*/ bool                     LFG;
/*0x04f4*/ float                    MyWalkSpeed;
/*0x04f8*/ unsigned int             NextIntimidateTime;
/*0x04fc*/ float                    ViewHeight;
/*0x0500*/ int                      RealEstateItemId;
/*0x0504*/ unsigned int             MinuteTimer;
/*0x0508*/ EqItemGuid               realEstateItemGuid;
/*0x051a*/ uint8_t                  HmmWhat;
/*0x051c*/ unsigned int             Meditating;
/*0x0520*/ unsigned int**           ppUDP;                        // UdpLibrary::UdpConnection
/*0x0524*/ uint8_t                  IntimidateCount;
/*0x0528*/ int                      HideMode;
/*0x052c*/ bool                     bSummoned;                    // by a PC or by anyone? need to investigate
/*0x0530*/ int                      berserker;
/*0x0538*/ int64_t                  HPMax;
/*0x0540*/ int                      SecondaryTintIndex;
/*0x0548*/ int64_t                  GuildID;
/*0x0550*/ unsigned int             EnduranceMax;
/*0x0554*/ uint8_t                  Light;
/*0x0558*/ int                      DoSpecialMelee;
/*0x055c*/ unsigned int             Zone;
/*0x0560*/ int                      SomeData[0x2];
/*0x0568*/ unsigned int             LastPrimaryUseTime;
/*0x056c*/ unsigned int             StunTimer;
/*0x0570*/ CPhysicsInfo             LastCollision;
/*0x05a0*/ void*                    pTouchingSwitch;              // need to get that in here : struct _EQSWITCH
/*0x05a4*/ float                    RunSpeed;                     // 0.70 on runspeed 5...
/*0x05a8*/ int                      IsAttacking;                  // need to investigate
/*0x05ac*/ int                      AARank;                       // this really is the title id
/*0x05b0*/ int                      ManaCurrent;
/*0x05b4*/ float                    MissileRangeToTarget;
/*0x05b8*/ uint8_t                  TitleVisible;
/*0x05b9*/ uint8_t                  IsPassenger;                  // if u are on a boat or airship or whatever
/*0x05bc*/ unsigned int             SpellCooldownETA;
/*0x05c0*/ bool                     bSwitchMoved;                 // true when a door moves near the spawn
/*0x05c4*/ int                      CurrIOState;
/*0x05c8*/ unsigned int             LastRefresh;                  // last 18 sec tick
/*0x05cc*/ int                      Trader;                       // found in CEverQuest__RightClickedOnPlayer_x
/*0x05d0*/ int                      ManaMax;
/*0x05d4*/ float                    MerchantGreed;
/*0x05d8*/ int                      PrimaryTintIndex;
/*0x05dc*/ char                     LoginRelated[0x20];
/*0x05fc*/ int                      AFK;
/*0x0600*/ unsigned int             PotionTimer;
/*0x0604*/ unsigned int             LastSecondaryUseTime;
/*0x0608*/ unsigned int             RespawnTimer;                 // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
/*0x060c*/ unsigned int             TimeStamp;                    // updates all the time including when on a mount
/*0x0610*/ int                      Dontknowyet2;

// @end: PlayerZoneClient Members

/*0x0614*/ TCircularBuffer<SDoCollisionMovementStats, 0x14> MovementStats; // size (0x74 * 0x14) +8 = 0x918
/*0x0f2c*/ SPAWNINFO*        WhoFollowing;                 // NULL if autofollow off
/*0x0f30*/ unsigned int      GroupAssistNPC[0x1];
/*0x0f34*/ unsigned int      RaidAssistNPC[0x3];
/*0x0f40*/ unsigned int      GroupMarkNPC[0x3];
/*0x0f4c*/ unsigned int      RaidMarkNPC[0x3];
/*0x0f58*/ unsigned int      TargetOfTarget;
/*0x0f5c*/ uint8_t           PhysStuff[0x20];
/*0x0f7c*/ unsigned int      ParticleCastStartTime;
/*0x0f80*/ unsigned int      ParticleCastDuration;
/*0x0f84*/ int               ParticleVisualSpellNum;
/*0x0f88*/ ActorClient       mActorClient;                 // start of ActorClient struct  size 0x1BC?
/*0x1144*/ PlayerAnimationBase *pAnimation;
/*0x1148*/ float             MeleeRadius;                  // used by GetMeleeRange
/*0x114c*/ unsigned int      CollisionCounter;
/*0x1150*/ float             CachedFloorLocationY;
/*0x1154*/ float             CachedFloorLocationX;
/*0x1158*/ float             CachedFloorLocationZ;
/*0x115c*/ float             CachedFloorHeight;
/*0x1160*/ float             CachedCeilingLocationY;
/*0x1164*/ float             CachedCeilingLocationX;
/*0x1168*/ float             CachedCeilingLocationZ;
/*0x116c*/ float             CachedCeilingHeight;
/*0x1170*/ CCapsule          StaticCollision;              // size 0x1c
/*0x118c*/ ArrayClass_RO<PhysicsEffect> mPhysicsEffects;   // size is 0x10
/*0x119c*/ ArrayClass_RO<bool>  PhysicsEffectsUpdated;     // size is 0x10
/* ********************* PlayerZoneClient Ends Here ******************* */
/* ********************** PlayerClient Starts Here ******************** */
/*0x11ac*/ uint8_t           Filler0x11ac[0x4];
/*0x11ac*/ int               Animation;                    // Current Animation Playing. see 5671F1 in feb 14 2019 test
/*0x11b0*/ int               NextAnim;
/*0x11b4*/ int               CurrLowerBodyAnim;
/*0x11b8*/ int               NextLowerBodyAnim;
/*0x11bc*/ int               CurrLowerAnimVariation;
/*0x11c0*/ int               CurrAnimVariation;
/*0x11c4*/ int               CurrAnimRndVariation;
/* ********************sound ID's BEGIN ******************* */
/*0x11c8*/ int               Loop3d_SoundID;               //see 567254 in feb 14 2019 test
/*0x11cc*/ int               Step_SoundID;;
/*0x11d0*/ int               CurLoop_SoundID;
/*0x11d4*/ int               Idle3d1_SoundID;
/*0x11d8*/ int               Idle3d2_SoundID;
/*0x11dc*/ int               Jump_SoundID;
/*0x11e0*/ int               Hit1_SoundID;
/*0x11e4*/ int               Hit2_SoundID;
/*0x11e8*/ int               Hit3_SoundID;
/*0x11ec*/ int               Hit4_SoundID;
/*0x11f0*/ int               Gasp1_SoundID;
/*0x11f4*/ int               Gasp2_SoundID;
/*0x11f8*/ int               Drown_SoundID;
/*0x11fc*/ int               Death_SoundID;
/*0x1200*/ int               Attk1_SoundID;
/*0x1204*/ int               Attk2_SoundID;
/*0x1208*/ int               Attk3_SoundID;
/*0x120c*/ int               Walk_SoundID;
/*0x1210*/ int               Run_SoundID;
/*0x1214*/ int               Crouch_SoundID;
/*0x1218*/ int               Swim_SoundID;
/*0x121c*/ int               TreadWater_SoundID;
/*0x1220*/ int               Climb_SoundID;
/*0x1224*/ int               Sit_SoundID;
/*0x1228*/ int               Kick_SoundID;
/*0x122c*/ int               Bash_SoundID;
/*0x1230*/ int               FireBow_SoundID;
/*0x1234*/ int               MonkAttack1_SoundID;
/*0x1238*/ int               MonkAttack2_SoundID;
/*0x123c*/ int               MonkSpecial_SoundID;
/*0x1240*/ int               PrimaryBlunt_SoundID;
/*0x1244*/ int               PrimarySlash_SoundID;
/*0x1248*/ int               PrimaryStab_SoundID;
/*0x124c*/ int               Punch_SoundID;
/*0x1250*/ int               Roundhouse_SoundID;
/*0x1254*/ int               SecondaryBlunt_SoundID;
/*0x1258*/ int               SecondarySlash_SoundID;
/*0x125c*/ int               SecondaryStab_SoundID;
/*0x1260*/ int               SwimAttack_SoundID;
/*0x1264*/ int               TwoHandedBlunt_SoundID;
/*0x1268*/ int               TwoHandedSlash_SoundID;
/*0x126c*/ int               TwoHandedStab_SoundID;
/*0x1270*/ int               SecondaryPunch_SoundID;
/*0x1274*/ int               JumpAcross_SoundID;
/*0x1278*/ int               WalkBackwards_SoundID;
/*0x127c*/ int               CrouchWalk_SoundID;
/* ******************** sound ID's END ****************** */
/*0x1280*/ unsigned int      LastHurtSound;                // see 5E96E0 in feb 14 2019 test
/*0x1284*/ unsigned int      LastWalkTime;                 // used for animations
/*0x1288*/ int               ShipRelated;                  // ID? look into.
/*0x128c*/ int               RightHolding;                 // Nothing=0 Other/Weapon=1 shield=2
/*0x1290*/ int               LeftHolding;                  // old Holding
/*0x1294*/ unsigned int      DeathAnimationFinishTime;
/*0x1298*/ bool              bRemoveCorpseAfterDeathAnim;  // 0x1274 for sure used by /hidecorpse
/*0x129c*/ unsigned int      LastBubblesTime;
/*0x12a0*/ unsigned int      LastBubblesTime1;
/*0x12a4*/ unsigned int      LastColdBreathTime;
/*0x12a8*/ unsigned int      LastParticleUpdateTime;
/*0x12ac*/ unsigned int      MercID;                       // IT IS 0x1288      //if the spawn is player and has a merc up this is it's spawn ID -eqmule 16 jul 2014
/*0x12b0*/ unsigned int      ContractorID;                 // if the spawn is a merc this is its contractor's spawn ID -eqmule 16 jul 2014
/*0x12b4*/ float             CeilingHeightAtCurrLocation;
/*0x12b8*/ void*             MobileEmitter;                // todo: change and map to EqMobileEmitter*
/*0x12bc*/ bool              bInstantHPGaugeChange;
/*0x12c0*/ unsigned int      LastUpdateReceivedTime;
/*0x12c4*/ float             MaxSpeakDistance;
/*0x12c8*/ float             WalkSpeed;                    // how much we will slow down while sneaking
/*0x12cc*/ bool              bHideCorpse;
/*0x12cd*/ char              AssistName[0x40];
/*0x130d*/ bool              InvitedToGroup;
/*0x1310*/ int               GroupMemberTargeted;          // -1 if no target, else 1 through 5
/*0x1314*/ bool              bRemovalPending;              // see 5E0763 in feb 14 2019 test
/*0x1318*/ void*             pCorpse;
/*0x131c*/ float             EmitterScalingRadius;
/*0x1320*/ int               DefaultEmitterID;
/*0x1324*/ bool              bDisplayNameSprite;
/*0x1325*/ bool              bIdleAnimationOff;
/*0x1326*/ bool              bIsInteractiveObject;
/*0x1327*/ uint8_t           InteractiveObjectModelName[0x80];
/*0x13a7*/ uint8_t           InteractiveObjectOtherName[0x80];
/*0x1427*/ uint8_t           InteractiveObjectName[0x40];
/*0x1468*/ CPhysicsInfo      PhysicsBeforeLastPort;        // size IS /*0x30*/ see 5E617B in feb 14 2019 test
/*0x1498*/ unsigned int      notsure;                      // could be part of CPhysicsInfo?
/*0x149c*/ FELLOWSHIPINFO    Fellowship;                   // IT IS AT 0x1498 see 63BEDD in feb 14 2019 test // size 0x9e8
/*0x1e84*/ float             CampfireY;
/*0x1e88*/ float             CampfireX;
/*0x1e8c*/ float             CampfireZ;
/*0x1e90*/ int               CampfireZoneID;               // zone ID where campfire is
/*0x1e94*/ int               CampfireTimestamp;            // CampfireTimestamp-FastTime()=time left on campfire
/*0x1e98*/ int               CampfireTimestamp2;
/*0x1e9c*/ int               FellowShipID;
/*0x1ea0*/ int               FellowShipID2;
/*0x1ea4*/ int               CampType;
/*0x1ea8*/ bool              Campfire;
/*0x1eac*/ TSafeArrayStatic<int, 3> SeeInvis;              // for sure see 63E23F or 63BD35 in feb 14 2019 test
/*0x1eb8*/ EQUIPMENT         Equipment;                    // size 0xb4 see 63BF44 in feb 14 2019 test
/*0x1f6c*/ bool              bIsPlacingItem;               // for sure see 543626 in feb 14 2019 test
/*0x1f6d*/ bool              bGMCreatedNPC;
/*0x1f70*/ int               ObjectAnimationID;
/*0x1f74*/ bool              bInteractiveObjectCollidable;
/*0x1f78*/ int               InteractiveObjectType;
/*0x1f7c*/ int               SoundIDs[0xa];                // 0x28 bytes for sure see 648AB2 in feb 14 2019 test
/*0x1fa4*/ unsigned int      LastHistorySentTime;          // for sure see 648E7E in feb 14 2019 test
/*0x1fa8*/ ArrayClass2_RO<unsigned int> BardTwistSpells;      // size 0x18
/*0x1fc0*/ int               CurrentBardTwistIndex;
/*0x1fc4*/ int               CurrentBardTwistIndex2;
/*0x1fc8*/ PlayerPhysicsClient mPlayerPhysicsClient;//size 0x28
/*0x1ff0*/ int               SpawnStatus[6];               // todo: look closer at these i think they can show like status of mobs slowed, mezzed etc, but not sure
/*0x2008*/ int               BannerIndex0;                 // guild banners
/*0x200c*/ int               BannerIndex1;
/*0x2010*/ ARGBCOLOR         BannerTint0;
/*0x2014*/ ARGBCOLOR         BannerTint1;
/*0x2018*/ int               MountAnimationRelated;
/*0x201c*/ bool              bGuildShowAnim;               // or sprite? need to check
/*0x201d*/ bool              bWaitingForPort;              // for sure see 5C5445 in feb 14 2019 test
/*0x2020*/ int               Unknown0x201C;
/*0x2024*/
/*0x2028*/ // see SpawnInfoSize

	int GetClass() { return mActorClient.Class; }
	uint8_t GetCharacterType() { return Type; }
	unsigned int GetId() const { return SpawnID; }

	// a.k.a. GetPcClient
	[[deprecated("Use GetPcClient instead")]] EQLIB_OBJECT void* GetCharacter() const { return GetPcClient(); }
	EQLIB_OBJECT PcClient* GetPcClient() const;

	EQLIB_OBJECT unsigned int GetZoneID() const { return (int)Zone; }
	EQLIB_OBJECT int GetCurrentMana() const { return ManaCurrent; }
	EQLIB_OBJECT int GetMaxMana() const { return ManaMax; }
	EQLIB_OBJECT int GetCurrentEndurance() const { return EnduranceCurrent; }
	EQLIB_OBJECT int GetMaxEndurance() const { return EnduranceMax; }
	EQLIB_OBJECT unsigned int GetSpellCooldownETA() const { return SpellCooldownETA; }

	// TODO: Add a PlayerClient() constructor
};
using PSPAWNINFO /*[[deprecated]]*/ = SPAWNINFO*;

struct HASHENTRY
{
	SPAWNINFO*  spawn;
	DWORD       key;                             // same as SpawnID for spawns
	HASHENTRY*  next;
};
using PHASHENTRY = HASHENTRY*;

struct HASHTABLE
{
    HASHENTRY** table;
    int size;
};
using PHASHTABLE = HASHTABLE*;

class [[offsetcomments]] PlayerManagerBase
{
public:
	virtual ~PlayerManagerBase() {}

/*0x04*/ DWORD        random;                   // rand() % 20000
/*0x08*/ SPAWNINFO*   FirstSpawn;
/*0x0c*/ SPAWNINFO*   LastSpawn;
/*0x10*/ DWORD        unknown10;
/*0x14*/ HASHTABLE*   SPHash;
/*0x18*/
};

class PlayerManagerClient : public PlayerManagerBase
{
public:
	//PlayerClient* GetPlayerFromPartialName(const char* szName, PlayerBase* = nullptr);
	//PlayerClient* GetPlayerFromName(const char* szName);

	EQLIB_OBJECT PlayerClient* GetSpawnByID(int);
	EQLIB_OBJECT PlayerClient* GetSpawnByName(const char*);
	EQLIB_OBJECT PlayerClient* GetPlayerFromPartialName(const char*, PlayerBase*);
};

using EQPlayerManager [[deprecated]] = PlayerManagerClient;
using SPAWNMANAGER [[deprecated]] = PlayerManagerClient;
using PSPAWNMANAGER [[deprecated]] = PlayerManagerClient *;

//============================================================================
// PlayerBase
//============================================================================

// this is the size of EQPlayer__EQPlayer_x
// actual size 0x2020 in Feb 20 2016 Live (see 64B6A0) - eqmule
// A.k.a. SPAWNINFO
class [[offsetcomments]] PlayerBase : public TListNode<PlayerBase>, public CActorApplicationData
{
public:
/*0x010*/ float             JumpStrength;
/*0x014*/ float             SwimStrength;
/*0x018*/ float             SpeedMultiplier;
/*0x01c*/ float             AreaFriction;
/*0x020*/ float             AccelerationFriction;
/*0x024*/ EActorType        CollidingType;                // when we collide with something this gets set.
/*0x028*/ float             FloorHeight;
/*0x02c*/ bool              bSinksInWater;
/*0x030*/ unsigned int      PlayerTimeStamp;              // doesn't update when on a Vehicle (mounts/boats etc)
/*0x034*/ unsigned int      LastTimeIdle;
/*0x038*/ char              Lastname[0x20];
/*0x058*/ float             AreaHPRegenMod;               // from guild hall pools etc.
/*0x05c*/ float             AreaEndRegenMod;
/*0x060*/ float             AreaManaRegenMod;
/*0x064*/ float             Y;
/*0x068*/ float             X;
/*0x06c*/ float             Z;
/*0x070*/ float             SpeedY;
/*0x074*/ float             SpeedX;
/*0x078*/ float             SpeedZ;
/*0x07c*/ float             SpeedRun;
/*0x080*/ float             Heading;
/*0x084*/ float             Angle;
/*0x088*/ float             AccelAngle;
/*0x08c*/ float             SpeedHeading;
/*0x090*/ float             CameraAngle;
/*0x094*/ unsigned int      UnderWater;                   // LastHeadEnvironmentType
/*0x098*/ unsigned int      LastBodyEnvironmentType;
/*0x09c*/ unsigned int      LastFeetEnvironmentType;
/*0x0a0*/ uint8_t           HeadWet;                      // these really are environment related, like lava as well for example
/*0x0a1*/ uint8_t           FeetWet;
/*0x0a2*/ uint8_t           BodyWet;
/*0x0a3*/ uint8_t           LastBodyWet;
/*0x0a4*/ char              Name[0x40];                   // ie priest_of_discord00
/*0x0e4*/ char              DisplayedName[0x40];          // ie Priest of Discord
/*0x124*/ uint8_t           PossiblyStuck;                // never seen this be 1 so maybe it was used a a point but not now...
/*0x125*/ uint8_t           Type;
/*0x128*/ unsigned int**    BodyType;                     // this really should be renamed to charprops or something its broken anyway
/*0x12c*/ uint8_t           CharPropFiller[0xc];          // well since the above is a CharacterPropertyHash we have to pad here...
/*0x138*/ float             AvatarHeight;                 // height of avatar from groundwhen standing for sure see 5C06A0 in Jun 10 2019 test
/*0x13c*/ float             Height;
/*0x140*/ float             Width;
/*0x144*/ float             Length;
/*0x148*/ int               Unknown0x0148;
/*0x14c*/ int               Unknown0x014C;
/*0x150*/ unsigned int      SpawnID;
/*0x154*/ unsigned int      PlayerState;                  // 0=Idle 1=Open 2=WeaponSheathed 4=Aggressive 8=ForcedAggressive 0x10=InstrumentEquipped 0x20=Stunned 0x40=PrimaryWeaponEquipped 0x80=SecondaryWeaponEquipped
/*0x158*/ PlayerBase*       Vehicle;                      // NULL until you collide with a vehicle (boat,airship etc)
/*0x15c*/ PlayerBase*       Mount;                        // NULL if no mount present
/*0x160*/ PlayerBase*       Rider;                        // SPAWNINFO of mount's rider
/*0x164*/ unsigned int      Unknown0x0164;
/*0x168*/ bool              Targetable;                   // true if mob is targetable
/*0x169*/ bool              bTargetCyclable;
/*0x16a*/ bool              bClickThrough;
/*0x16b*/ bool              bBeingFlung;
/*0x16c*/ unsigned int      FlingActiveTimer;
/*0x170*/ unsigned int      FlingTimerStart;
/*0x174*/ bool              bFlingSomething;
/*0x178*/ float             FlingY;
/*0x17c*/ float             FlingX;
/*0x180*/ float             FlingZ;
/*0x184*/ bool              bFlingSnapToDest;
/*0x188*/ int               SplineID;
/*0x18c*/ int               SplineRiderID;
/*0x190*/

	EQLIB_OBJECT unsigned int GetId() const { return SpawnID; }

	// These are methods that originated from EQPlayer. They might not
	// all still exist.
	EQLIB_OBJECT bool IsAMount();
	EQLIB_OBJECT bool MyFeetAreOnGround();
	EQLIB_OBJECT bool HasProperty(unsigned int, int, int);
	EQLIB_OBJECT bool IsTargetable();
	EQLIB_OBJECT bool CanSee(const PlayerBase&);
	EQLIB_OBJECT bool CanSee(const CVector3& pos);
	EQLIB_OBJECT CLineSegment GetVisibilityLineSegment(const PlayerBase& other, unsigned int index = 0);

private:
	virtual void Dummy() {} // force a vtable
};

//============================================================================
// PlayerZoneClient
//============================================================================

class [[offsetcomments]] PlayerZoneClient : public PlayerBase
{
public:
/*0x0190*/ unsigned int                 LastIntimidateUse;

// @start: PlayerZoneClient Members
/*0x0194*/ bool                     bOfflineMode;
/*0x0198*/ int64_t                  HPCurrent;
/*0x01a0*/ uint8_t                  CharClass;                    // Im pretty sure this isnt working
/*0x01a1*/ bool                     bAlwaysShowAura;
/*0x01a4*/ int                      EnduranceCurrent;
/*0x01a8*/ uint8_t                  FD;
/*0x01ac*/ float                    AnimationSpeedRelated;
/*0x01b0*/ int                      RealEstateID;
/*0x01b4*/ char                     Suffix[0x80];
/*0x0234*/ unsigned int             LastRangedUsedTime;
/*0x0238*/ unsigned int             SpellGemETA[0xf];             // InnateETA is now the last member in this array
/*0x0274*/ char                     DraggingPlayer[0x40];
/*0x02b4*/ LAUNCHSPELLDATA          CastingData;                  // size: 0x58
/*0x030c*/ uint8_t                  FishingEvent;
/*0x030d*/ char                     Title[0x80];
/*0x038d*/ char                     Handle[0x20];
/*0x03ad*/ uint8_t                  LastAttack;
/*0x03b0*/ float                    CameraOffset;
/*0x03b4*/ bool                     bAttackRelated;
/*0x03b8*/ unsigned int             LastTrapDamageTime;
/*0x03bc*/ bool                     bShowHelm;
/*0x03c0*/ unsigned int             NextSwim;
/*0x03c4*/ unsigned int             CombatSkillUsed[0x2];
/*0x03cc*/ SPAWNINFO*               pViewPlayer;
/*0x03d0*/ int                      NpcTintIndex;
/*0x03d4*/ int                      PetID;
/*0x03d8*/ unsigned int             FishingETA;
/*0x03dc*/ void*                    pRaceGenderInfo;              // todo this is not a void* so... map the CRaceGenderInfo class
/*0x03e0*/ float                    GetMeleeRangeVar1;            // used by GetMeleeRange (fScaleFactor)
/*0x03e4*/ bool                     bBetaBuffed;
/*0x03e5*/ uint8_t                  Type2;
/*0x03e8*/ int                      LastCastNum;
/*0x03ec*/ int                      Deity;
/*0x03f0*/ bool                     Mercenary;
/*0x03f1*/ uint8_t                  GMRank;
/*0x03f2*/ bool                     Linkdead;
/*0x03f3*/ bool                     bBuffTimersOnHold;            // no you can't control this client side so unless you want to get banned leave it alone
/*0x03f4*/ int                      Stuff;
/*0x03f8*/ uint8_t                  StandState;
/*0x03fc*/ unsigned int             CombatSkillTicks[0x2];
/*0x0404*/ bool                     bAnimationOnPop;
/*0x0408*/ unsigned int             LastMealTime;                 // last time we eat or drank
/*0x040c*/ bool                     bTempPet;
/*0x040d*/ bool                     bStationary;
/*0x0410*/ int                      AltAttack;
/*0x0414*/ int                      Anon;                         // found in EQPlayer__SetNameSpriteTint_x
/*0x0418*/ uint8_t                  InPvPArea;                    // are we in a PvP area?
/*0x041c*/ int                      WarCry;
/*0x0420*/ unsigned int             CorpseDragCount;
/*0x0424*/ char                     GM;
/*0x0425*/ bool                     Sneak;
/*0x0428*/ int                      DontKnowYet;
/*0x042c*/ unsigned int             LastTick;
/*0x0430*/ CharacterZoneClient*     pCharacter;
/*0x0434*/ unsigned int             LastTimeStoodStill;
/*0x0438*/ uint8_t                  Blind;
/*0x043c*/ unsigned int             SitStartTime;
/*0x0440*/ int                      SomethingElse;
/*0x0444*/ bool                     PvPFlag;
/*0x0448*/ float                    BearingToTarget;
/*0x044c*/ int                      Buyer;
/*0x0450*/ char                     DragNames[0x2][0x40];
/*0x04d0*/ unsigned int             LastResendAddPlayerPacket;
/*0x04d4*/ unsigned int             ACounter;                     // not sure what this one is for (m_uHibernatingCount)
/*0x04d8*/ unsigned int             LastCastTime;
/*0x04dc*/ unsigned int             MasterID;
/*0x04e0*/ uint8_t                  FindBits;
/*0x04e4*/ unsigned int             LoginSerial;
/*0x04e8*/ uint8_t                  HoldingAnimation;             // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
/*0x04ec*/ float                    FallingStartZ;
/*0x04f0*/ uint8_t                  Level;
/*0x04f1*/ bool                     LFG;
/*0x04f4*/ float                    MyWalkSpeed;
/*0x04f8*/ unsigned int             NextIntimidateTime;
/*0x04fc*/ float                    ViewHeight;
/*0x0500*/ int                      RealEstateItemId;
/*0x0504*/ unsigned int             MinuteTimer;
/*0x0508*/ EqItemGuid               realEstateItemGuid;
/*0x051a*/ uint8_t                  HmmWhat;
/*0x051c*/ unsigned int             Meditating;
/*0x0520*/ unsigned int**           ppUDP;                        // UdpLibrary::UdpConnection
/*0x0524*/ uint8_t                  IntimidateCount;
/*0x0528*/ int                      HideMode;
/*0x052c*/ bool                     bSummoned;                    // by a PC or by anyone? need to investigate
/*0x0530*/ int                      berserker;
/*0x0538*/ int64_t                  HPMax;
/*0x0540*/ int                      SecondaryTintIndex;
/*0x0548*/ int64_t                  GuildID;
/*0x0550*/ unsigned int             EnduranceMax;
/*0x0554*/ uint8_t                  Light;
/*0x0558*/ int                      DoSpecialMelee;
/*0x055c*/ unsigned int             Zone;
/*0x0560*/ int                      SomeData[0x2];
/*0x0568*/ unsigned int             LastPrimaryUseTime;
/*0x056c*/ unsigned int             StunTimer;
/*0x0570*/ CPhysicsInfo             LastCollision;
/*0x05a0*/ void*                    pTouchingSwitch;              // need to get that in here : struct _EQSWITCH
/*0x05a4*/ float                    RunSpeed;                     // 0.70 on runspeed 5...
/*0x05a8*/ int                      IsAttacking;                  // need to investigate
/*0x05ac*/ int                      AARank;                       // this really is the title id
/*0x05b0*/ int                      ManaCurrent;
/*0x05b4*/ float                    MissileRangeToTarget;
/*0x05b8*/ uint8_t                  TitleVisible;
/*0x05b9*/ uint8_t                  IsPassenger;                  // if u are on a boat or airship or whatever
/*0x05bc*/ unsigned int             SpellCooldownETA;
/*0x05c0*/ bool                     bSwitchMoved;                 // true when a door moves near the spawn
/*0x05c4*/ int                      CurrIOState;
/*0x05c8*/ unsigned int             LastRefresh;                  // last 18 sec tick
/*0x05cc*/ int                      Trader;                       // found in CEverQuest__RightClickedOnPlayer_x
/*0x05d0*/ int                      ManaMax;
/*0x05d4*/ float                    MerchantGreed;
/*0x05d8*/ int                      PrimaryTintIndex;
/*0x05dc*/ char                     LoginRelated[0x20];
/*0x05fc*/ int                      AFK;
/*0x0600*/ unsigned int             PotionTimer;
/*0x0604*/ unsigned int             LastSecondaryUseTime;
/*0x0608*/ unsigned int             RespawnTimer;                 // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
/*0x060c*/ unsigned int             TimeStamp;                    // updates all the time including when on a mount
/*0x0610*/ int                      Dontknowyet2;

// @end: PlayerZoneClient Members

	enum { MAX_MOVEMENT_STATS = 20 };
/*0x0614*/ TCircularBuffer<SDoCollisionMovementStats, MAX_MOVEMENT_STATS> MovementStats; // size (0x74 * 0x14) +8 = 0x918
/*0x0f2c*/ PlayerClient*      WhoFollowing;                // NULL if autofollow off
/*0x0f30*/ unsigned int       GroupAssistNPC[0x1];
/*0x0f34*/ unsigned int       RaidAssistNPC[0x3];
/*0x0f40*/ unsigned int       GroupMarkNPC[0x3];
/*0x0f4c*/ unsigned int       RaidMarkNPC[0x3];
/*0x0f58*/ unsigned int       TargetOfTarget;
/*0x0f5c*/ uint8_t            PhysStuff[0x20];
/*0x0f7c*/ unsigned int       ParticleCastStartTime;
/*0x0f80*/ unsigned int       ParticleCastDuration;
/*0x0f84*/ int                ParticleVisualSpellNum;
/*0x0f88*/ uint8_t            Filler0x0f88[0x8];
/*0x0f90*/ ActorClient        mActorClient;                // start of ActorClient struct  size 0x1BC?
/*0x114c*/ PlayerAnimationBase* pAnimation;
/*0x1150*/ float              MeleeRadius;                 // used by GetMeleeRange
/*0x1154*/ unsigned int       CollisionCounter;
/*0x1158*/ float              CachedFloorLocationY;
/*0x115c*/ float              CachedFloorLocationX;
/*0x1160*/ float              CachedFloorLocationZ;
/*0x1164*/ float              CachedFloorHeight;
/*0x1168*/ float              CachedCeilingLocationY;
/*0x116c*/ float              CachedCeilingLocationX;
/*0x1170*/ float              CachedCeilingLocationZ;
/*0x1174*/ float              CachedCeilingHeight;
/*0x1178*/ CCapsule           StaticCollision;
/*0x1194*/ ArrayClass<PhysicsEffect> mPhysicsEffects;
/*0x11a4*/ ArrayClass<bool>   PhysicsEffectsUpdated;
/*0x11b4*/
	EQLIB_OBJECT int LegalPlayerRace(int race);

	// Some methods that were from EQPlayer in the past
	EQLIB_OBJECT bool AllowedToAttack(PlayerZoneClient*, int);
	EQLIB_OBJECT bool CanChangeForm(int Race, unsigned char Sex, float Height);
	EQLIB_OBJECT bool CanIFitHere(const CVector3& pos, bool ignoreHeight = false);
	EQLIB_OBJECT bool CanIHit(const PlayerZoneClient*, int);
	EQLIB_OBJECT bool IsFlyer();
	EQLIB_OBJECT bool IsInvisible(PlayerZoneClient*, bool = false);
	EQLIB_OBJECT bool IWasHit(EQMissileHitinfo*, LAUNCHSPELLDATA*, int = 0);
	EQLIB_OBJECT bool UpdatePlayerActor();
	EQLIB_OBJECT float GetDefaultHeight(int race, unsigned char);
	EQLIB_OBJECT float GetPlayerFloorHeight(float, float, float, unsigned char);
	EQLIB_OBJECT int AimAtTarget(PlayerZoneClient*, EQMissile*);
	EQLIB_OBJECT int CheckForJump();
	EQLIB_OBJECT int GetArmorType(int, char*);
	EQLIB_OBJECT int GetGuild() const;
	EQLIB_OBJECT bool IsValidTeleport(float X, float Y, float Z, float Heading, float Distance);
	EQLIB_OBJECT int Levitating();
	EQLIB_OBJECT int MountableRace();
	EQLIB_OBJECT int MovePlayer();
	EQLIB_OBJECT int NotOnSameDeity(const PlayerZoneClient*, const EQ_Spell*);
	EQLIB_OBJECT static void ComputeSpecialHeights(int, float*, float*, float*, float*, bool);
	EQLIB_OBJECT unsigned char DoTeleport(char*, int);
	EQLIB_OBJECT unsigned char DoTeleportB(int, float, float, float, float, char*, int);
	EQLIB_OBJECT unsigned char GetNearestActorTag(char*, EActorType);
	EQLIB_OBJECT unsigned char HandleAmmo();
	EQLIB_OBJECT static unsigned char SkillUsed(unsigned char);
	EQLIB_OBJECT unsigned int ModifyAttackSpeed(unsigned int, int);
	EQLIB_OBJECT unsigned long GetArmorTint(int);
	EQLIB_OBJECT void BodyEnvironmentChange(unsigned char);
	EQLIB_OBJECT void ChangeHeight(float);
	EQLIB_OBJECT void ChangePosition(unsigned char);
	EQLIB_OBJECT void CheckForUnderFloor();
	EQLIB_OBJECT void CleanUpVehicle();
	EQLIB_OBJECT void DeleteMyMissiles();
	EQLIB_OBJECT void DoFloorCheck();
	EQLIB_OBJECT void FacePlayer(PlayerZoneClient*);
	EQLIB_OBJECT void FeetEnvironmentChange(unsigned char);
	EQLIB_OBJECT void GetActorTag(char*);
	EQLIB_OBJECT void GetConscious();
	EQLIB_OBJECT void HeadEnvironmentChange(unsigned char);
	EQLIB_OBJECT void IDied(EQPlayerDeath*);
	EQLIB_OBJECT void IHaveFallen(float);
	EQLIB_OBJECT void InitSneakMod();
	EQLIB_OBJECT void KnockedOut();
	EQLIB_OBJECT void MakeRiderMountUp();
	EQLIB_OBJECT void PositionOnFloor();
	EQLIB_OBJECT void PushAlongHeading(float);
	EQLIB_OBJECT void PutPlayerOnFloor();
	EQLIB_OBJECT void ResetVariables();
	EQLIB_OBJECT void SetAnimVariation();
	EQLIB_OBJECT void SetArmorTint(int, unsigned long);
	EQLIB_OBJECT void SetHeights();
	EQLIB_OBJECT void SetRace(int);
	EQLIB_OBJECT unsigned char GetLevel() const;

	EQLIB_OBJECT bool DoAttack(BYTE slot, BYTE skill, PlayerZoneClient* Target, bool bSomething = false, bool bAuto = false, bool bDontknow = false);

	EQLIB_OBJECT static PlayerZoneClient* GetClosestPlayerFromPartialName(const char* name, PlayerZoneClient* player, int maxPlayerType = 1);
};

//============================================================================
// PlayerClient
//============================================================================

class [[offsetcomments]] PlayerClient : public PlayerZoneClient
{
public:
/*0x11b8*/ int               Animation;                    // Current Animation Playing. see 5671F1 in feb 14 2019 test
/*0x11bc*/ int               NextAnim;
/*0x11c0*/ int               CurrLowerBodyAnim;
/*0x11c4*/ int               NextLowerBodyAnim;
/*0x11c8*/ int               CurrLowerAnimVariation;
/*0x11cc*/ int               CurrAnimVariation;
/*0x11d0*/ int               CurrAnimRndVariation;

	// Beginning of sound ids
/*0x11d4*/ int               Loop3d_SoundID;               // see 567254 in feb 14 2019 test
/*0x11d8*/ int               Step_SoundID;;
/*0x11dc*/ int               CurLoop_SoundID;
/*0x11e0*/ int               Idle3d1_SoundID;
/*0x11e4*/ int               Idle3d2_SoundID;
/*0x11e8*/ int               Jump_SoundID;
/*0x11ec*/ int               Hit1_SoundID;
/*0x11f0*/ int               Hit2_SoundID;
/*0x11f4*/ int               Hit3_SoundID;
/*0x11f8*/ int               Hit4_SoundID;
/*0x11fc*/ int               Gasp1_SoundID;
/*0x1200*/ int               Gasp2_SoundID;
/*0x1204*/ int               Drown_SoundID;
/*0x1208*/ int               Death_SoundID;
/*0x120c*/ int               Attk1_SoundID;
/*0x1210*/ int               Attk2_SoundID;
/*0x1214*/ int               Attk3_SoundID;
/*0x1218*/ int               Walk_SoundID;
/*0x121c*/ int               Run_SoundID;
/*0x1220*/ int               Crouch_SoundID;
/*0x1224*/ int               Swim_SoundID;
/*0x1228*/ int               TreadWater_SoundID;
/*0x122c*/ int               Climb_SoundID;
/*0x1230*/ int               Sit_SoundID;
/*0x1234*/ int               Kick_SoundID;
/*0x1238*/ int               Bash_SoundID;
/*0x123c*/ int               FireBow_SoundID;
/*0x1240*/ int               MonkAttack1_SoundID;
/*0x1244*/ int               MonkAttack2_SoundID;
/*0x1248*/ int               MonkSpecial_SoundID;
/*0x124c*/ int               PrimaryBlunt_SoundID;
/*0x1250*/ int               PrimarySlash_SoundID;
/*0x1254*/ int               PrimaryStab_SoundID;
/*0x1258*/ int               Punch_SoundID;
/*0x125c*/ int               Roundhouse_SoundID;
/*0x1260*/ int               SecondaryBlunt_SoundID;
/*0x1264*/ int               SecondarySlash_SoundID;
/*0x1268*/ int               SecondaryStab_SoundID;
/*0x126c*/ int               SwimAttack_SoundID;
/*0x1270*/ int               TwoHandedBlunt_SoundID;
/*0x1274*/ int               TwoHandedSlash_SoundID;
/*0x1278*/ int               TwoHandedStab_SoundID;
/*0x127c*/ int               SecondaryPunch_SoundID;
/*0x1280*/ int               JumpAcross_SoundID;
/*0x1284*/ int               WalkBackwards_SoundID;
/*0x1288*/ int               CrouchWalk_SoundID;

/*0x128c*/ unsigned int      LastHurtSound;                // see 5E96E0 in feb 14 2019 test
/*0x1290*/ unsigned int      LastWalkTime;                 // used for animations
/*0x1294*/ int               ShipRelated;                  // ID? look into.
/*0x1298*/ int               RightHolding;                 // Nothing=0 Other/Weapon=1 shield=2
/*0x129c*/ int               LeftHolding;                  // old Holding
/*0x12a0*/ unsigned int      DeathAnimationFinishTime;
/*0x12a4*/ bool              bRemoveCorpseAfterDeathAnim;  // 0x1274 for sure used by /hidecorpse
/*0x12a8*/ unsigned int      LastBubblesTime;
/*0x12ac*/ unsigned int      LastBubblesTime1;
/*0x12b0*/ unsigned int      LastColdBreathTime;
/*0x12b4*/ unsigned int      LastParticleUpdateTime;
/*0x12b8*/ unsigned int      MercID;                       // IT IS 0x1288      //if the spawn is player and has a merc up this is it's spawn ID - 16 jul 2014
/*0x12bc*/ unsigned int      ContractorID;                 // if the spawn is a merc this is its contractor's spawn ID - 16 jul 2014
/*0x12c0*/ float             CeilingHeightAtCurrLocation;
/*0x12c4*/ void*             MobileEmitter;                // todo: change and map to EqMobileEmitter*
/*0x12c8*/ bool              bInstantHPGaugeChange;
/*0x12cc*/ unsigned int      LastUpdateReceivedTime;
/*0x12d0*/ float             MaxSpeakDistance;
/*0x12d4*/ float             WalkSpeed;                    // how much we will slow down while sneaking
/*0x12d8*/ bool              bHideCorpse;
/*0x12d9*/ char              AssistName[0x40];
/*0x1319*/ bool              InvitedToGroup;
/*0x131c*/ int               GroupMemberTargeted;          // 0xFFFFFFFF if no target, else 1 through 5
/*0x1320*/ bool              bRemovalPending;              // see 5E0763 in feb 14 2019 test
/*0x1324*/ void*             pCorpse;
/*0x1328*/ float             EmitterScalingRadius;
/*0x132c*/ int               DefaultEmitterID;
/*0x1330*/ bool              bDisplayNameSprite;
/*0x1331*/ bool              bIdleAnimationOff;
/*0x1332*/ bool              bIsInteractiveObject;
/*0x1333*/ uint8_t           InteractiveObjectModelName[0x80];
/*0x13b3*/ uint8_t           InteractiveObjectOtherName[0x80];
/*0x1433*/ uint8_t           InteractiveObjectName[0x40];
/*0x1463*/
/*0x1474*/ CPhysicsInfo      PhysicsBeforeLastPort;        // size IS /*0x30*/ see 5E617B in feb 14 2019 test
/*0x14a4*/ unsigned int      notsure;                      // could be part of CPhysicsInfo?
/*0x14a8*/ FELLOWSHIPINFO    Fellowship;                   // IT IS AT 0x1498 see 63BEDD in feb 14 2019 test // size 0x9e8
/*0x1e90*/ float             CampfireY;
/*0x1e94*/ float             CampfireX;
/*0x1e98*/ float             CampfireZ;
/*0x1e9c*/ int               CampfireZoneID;               // zone ID where campfire is
/*0x1ea0*/ int               CampfireTimestamp;            // CampfireTimestamp-FastTime()=time left on campfire
/*0x1ea4*/ int               CampfireTimestamp2;
/*0x1ea8*/ int               FellowShipID;
/*0x1eac*/ int               FellowShipID2;
/*0x1eb0*/ int               CampType;
/*0x1eb4*/ bool              Campfire;
/*0x1eb8*/ TSafeArrayStatic<int, 3> SeeInvis;              // for sure see 63E23F or 63BD35 in feb 14 2019 test
/*0x1ec4*/ EQUIPMENT         Equipment;                    // size 0xb4 see 63BF44 in feb 14 2019 test
/*0x1f78*/ bool              bIsPlacingItem;               // for sure see 543626 in feb 14 2019 test
/*0x1f79*/ bool              bGMCreatedNPC;
/*0x1f7c*/ int               ObjectAnimationID;
/*0x1f80*/ bool              bInteractiveObjectCollidable;
/*0x1f84*/ int               InteractiveObjectType;
/*0x1f88*/ int               SoundIDs[0xa];                // 0x28 bytes for sure see 648AB2 in feb 14 2019 test
/*0x1fb0*/ unsigned int      LastHistorySentTime;          // for sure see 648E7E in feb 14 2019 test
/*0x1fb4*/ ArrayClass2<unsigned int> BardTwistSpells;      // size 0x18
/*0x1fcc*/ int               CurrentBardTwistIndex;
/*0x1fd0*/ int               CurrentBardTwistIndex2;
/*0x1fd4*/ PlayerPhysicsClient mPlayerPhysicsClient;       // size 0x28
/*0x1ffc*/ int               SpawnStatus[6];               // todo: look closer at these i think they can show like status of mobs slowed, mezzed etc, but not sure
/*0x2014*/ int               BannerIndex0;                 // guild banners
/*0x2018*/ int               BannerIndex1;
/*0x201c*/ ARGBCOLOR         BannerTint0;
/*0x2020*/ ARGBCOLOR         BannerTint1;
/*0x2024*/ int               MountAnimationRelated;
/*0x2028*/ bool              bGuildShowAnim;               // or sprite? need to check
/*0x2029*/ bool              bWaitingForPort;              // for sure see 5C5445 in feb 14 2019 test
/*0x202c*/ int               Unknown0x201C;
/*0x2030*/

	void Initialize(PlayerClient*, unsigned char, unsigned int, unsigned char, char*);
	~PlayerClient();

	inline int GetClass() const { return mActorClient.Class; }
	inline BYTE GetCharacterType() const { return Type; }
	inline unsigned int GetId() const { return SpawnID; }
	inline CharacterZoneClient* GetCharacter() const { return (CharacterZoneClient*)GetPcClient(); }
	inline int GetZoneID() const { return Zone; }
	inline int GetCurrentMana() const { return ManaCurrent; }
	inline int GetMaxMana() const { return ManaMax; }
	inline int GetCurrentEndurance() const { return EnduranceCurrent; }
	inline int GetMaxEndurance() const { return EnduranceMax; }
	inline int GetSpellCooldownETA() const { return SpellCooldownETA; }
	inline bool IsGm() const { return GM; }

	EQLIB_OBJECT PcClient* GetPcClient() const;

	// These come from the old EQPlayer class. Not all of these methods still exist.
	EQLIB_OBJECT bool IsInvited();
	EQLIB_OBJECT bool IsRoleplaying();
	EQLIB_OBJECT bool IsUntexturedHorse();
	EQLIB_OBJECT bool const HasInvalidRiderTexture() const;
	EQLIB_OBJECT int CanBeBald();
	EQLIB_OBJECT int SetPlayerPitchType();
	EQLIB_OBJECT int SwapBody(int, int);
	EQLIB_OBJECT int SwapFace(int, int);
	EQLIB_OBJECT int SwapHead(int, int, unsigned long, int);
	EQLIB_OBJECT int SwapMaterial(int, int, int, int, unsigned char);
	EQLIB_OBJECT int SwapNPCMaterials();
	EQLIB_OBJECT static void UpdateAllPlayersVisibility();
	EQLIB_OBJECT CLightInterface* CreateUserLight(CLightDefinitionInterface*, int);
	EQLIB_OBJECT unsigned char GetBaseFaceNbr(int, unsigned char*);
	EQLIB_OBJECT unsigned char HasAttachedBeard();
	EQLIB_OBJECT unsigned char HasAttachedHair();
	EQLIB_OBJECT unsigned char UpdateItemSlot(unsigned char, char*, int);
	EQLIB_OBJECT unsigned int CalcAnimLength(int);
	EQLIB_OBJECT void ChangeLight();
	EQLIB_OBJECT void CleanUpMyEffects();
	EQLIB_OBJECT void CleanUpTarget();
	EQLIB_OBJECT void Dismount();
	EQLIB_OBJECT void DisplayWeaponsAndArmor();
	EQLIB_OBJECT void do_change_form(chngForm*);
	EQLIB_OBJECT void DoCamAi();
	EQLIB_OBJECT void DoClassRandomAnimation();
	EQLIB_OBJECT void DoItemSlot(int);
	EQLIB_OBJECT void DoSwimJump(unsigned char);
	EQLIB_OBJECT void FollowPlayerAI();
	EQLIB_OBJECT void ForceInvisible(bool);
	EQLIB_OBJECT void HandleMaterialEx(int, unsigned int, unsigned int, unsigned long, int);
	EQLIB_OBJECT void HandoverControlToZoneserver();
	EQLIB_OBJECT void MountEQPlayer(PlayerZoneClient*);
	EQLIB_OBJECT void PlaySound(int);
	EQLIB_OBJECT void SetAccel(float, int);
	EQLIB_OBJECT void SetAfk(int);
	EQLIB_OBJECT void SetCurrentLoopSound(int);
	EQLIB_OBJECT void SetDefaultFacialFeaturesByFace(int, unsigned char, unsigned char);
	EQLIB_OBJECT void SetInvited(bool);
	EQLIB_OBJECT void SetSounds();
	EQLIB_OBJECT void SetToRandomRace();
	EQLIB_OBJECT void TouchingSwitch();
	EQLIB_OBJECT void TriggerSpellEffect(EQMissileHitinfo*);
	EQLIB_OBJECT void TurnOffAutoFollow();
	EQLIB_OBJECT void UpdateAppearance();
	EQLIB_OBJECT void UpdateBonePointers();
	EQLIB_OBJECT void UpdateNameSprite();
	EQLIB_OBJECT void UpdatePlayerVisibility();
	EQLIB_OBJECT void ChangeBoneStringSprite(int bone, const char* spriteText);
	EQLIB_OBJECT int SetNameSpriteState(bool);
	EQLIB_OBJECT bool SetNameSpriteTint();

	EQLIB_OBJECT static PlayerClient* IsPlayerActor(CActorInterface*);
};

// For compatibility with all the old stuff
using EQPlayer [[deprecated]] = PlayerClient;

inline PcClient* SPAWNINFO::GetPcClient() const { return ((PlayerClient*)this)->GetPcClient(); }

} // namespace eqlib
