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
//   PlayerClient -> PlayerZoneClinet -> PlayerBase

namespace eqlib {

class CLightInterface;
class CParticlePointInterface;
class EQObject;
class EQSwitch;
class EQPlacedItem;
class PlayerAnimationBase;
class PlayerBase;
class PlayerClient;
class MissileBase;

struct EQC_INFO;
struct LAUNCHSPELLDATA;
struct chngForm;

#if 0 // when we're ready
using SPAWNINFO = PlayerClient;
using PSPAWNINFO = PlayerClient *;
#endif

struct SPAWNINFO;

struct ARMOR
{
/*0x00*/ unsigned int ID;                        // idfile on Lucy
/*0x04*/ unsigned int Var;
/*0x08*/ unsigned int Material;
/*0x0c*/ unsigned int NewArmorID;
/*0x10*/ unsigned int NewArmorType;
/*0x14*/
};
using PARMOR [[deprecated]] = ARMOR*;

struct EQUIPMENT
{
	union {
		struct { ARMOR Item[9]; };               // EQUIPARRAY
		struct                                   // EQUIPUNIQUE
		{
			ARMOR Head;
			ARMOR Chest;
			ARMOR Arms;
			ARMOR Wrists;
			ARMOR Hands;
			ARMOR Legs;
			ARMOR Feet;
			ARMOR Primary;
			ARMOR Offhand;
		};
	};
};
using PEQUIPMENT [[deprecated]] = EQUIPMENT*;

class CObjectGroupStageInstance : public TListNode<CObjectGroupStageInstance>
{
public:
	void* pActor1;//CActorInterface
	void* pActor2;//CActorInterface
	void* pStage;//CObjectGroupStage
};

//============================================================================
// ActorAnimation
//============================================================================

// TODO: Move Actor classes to its own header
class ActorAnimation
{
public:
	ActorAnimation*    pPrev;
	ActorAnimation*    pNext;
	char               Name[30];
	void*              pActordef;                // CActorDefinitionInterface*
	void**             Anim;                     // EQAnimation
	int                NumBones;
	bool               bUsesLuclinAnimations;
	bool               bNewStyleModel;
	float              ParticleEmitterScaleFactor;
	float              TargetIndicatorScaleFactor;
	float              FirstPersonCameraOffset;
	float              ThirdPersonCameraOffset;
	float              VerticalCameraOffset;
	float              CollisionSphereScaleFactor;
	float              ZoomCameraMinimumDistance;
	int                NumAnimations;
	int                NumAnimationSlots;
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

class ActorBase
{
public:
	EQLIB_OBJECT float GetBoundingRadius();

/*0x0f7C*/ void*       vfTableActorClient;
/*0x0f68*/ char        TextureType;
/*0x0f69*/ char        Material;
/*0x0f6a*/ char        Variation;
/*0x0f6b*/ char        HeadType;
/*0x0f6c*/ uint8_t     FaceStyle;
/*0x0f6d*/ uint8_t     HairColor;
/*0x0f6e*/ uint8_t     FacialHairColor;
/*0x0f6f*/ uint8_t     EyeColor1;
/*0x0f70*/ uint8_t     EyeColor2;
/*0x0f71*/ uint8_t     HairStyle;
/*0x0f72*/ uint8_t     FacialHair;
/*0x0f74*/ int         Race;
/*0x0f78*/ int         Race2;
/*0x0f94*/ int         Class;
/*0x0f98*/ uint8_t     Gender;
/*0x0f81*/ char        ActorDef[0x40];
/*0x0fc4*/ unsigned intArmorColor[0x9];
/*0x0fe8*/ bool        bShowHelm;
/*0x0fec*/ int         Heritage;                 // drakkin only face setting
/*0x0ff0*/ int         Tattoo;                   // drakkin only face setting
/*0x0ff4*/ int         Details;                  // drakkin only face setting
/*0x0ff8*/ EQUIPMENT   ActorEquipment;           // 0x0ff8 is confirmed // size 0xb4
/*0x10ac*/
};

//============================================================================
// ActorClient
//============================================================================

// size 0x1140 see 63D777 in Sep 25 2018 Test
//.text:0063D777                 mov     [edi+1B8h], eax so last member is at 1B8h which makes the struct size 0x1bc
// 0x1bc + 0x0f84 is 0x1140
class ActorClient : public ActorBase
{
public:
	// EQLIB_OBJECT const CVector3& GetPosition() const;
	// EQLIB_OBJECT void GetPosition(CVector3*) const;

/*0x0f7C*/ int         LeftEyeMaterialIndex;
/*0x0f80*/ int         RightEyeMaterialIndex;
/*0x0f84*/ CParticlePointInterface* pParticlePoints[0xa];
/*0x0fac*/ void*       pLowerBones;
/*0x10e0*/ void*       pUpperBones;
/*0x10fc*/ void*       pcactorex;                // todo: move to ActorInterface*
/*0x10e8*/ CLightInterface* pLight;
/*0x10ec*/ ActorAnimation*  pActorAnimation;
/*0x10f0*/ TList<CObjectGroupStageInstance> StageInstances;          // size 0x8
/*0x10f8*/ bool        bActiveTransition;
/*0x10Fc*/ unsigned int CurrentStage;
/*0x1100*/ float       ZOffset;
/*0x1104*/ float       TempY;//related to ZOffset adjustments I *think*
/*0x1108*/ float       TempX;
/*0x110c*/ float       TempZ;
/*0x1110*/ bool        bReplacedStaticObject;
/*0x1114*/ int         PartialFaceNumber;
/*0x1118*/ bool        bNewArmorDisabled;
/*0x111c*/ CActorApplicationData* pAppData;
/*0x1120*/
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

class CPhysicsInfo
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

struct SDoCollisionMovementStats
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

class CLineBase
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

class CCapsule : public CLineSegment
{
public:
/*0x18*/ float Radius;
/*0x1c*/
};

struct PhysicsEffect
{
/*0x00*/ int SpellID;
/*0x04*/ int CasterID;
/*0x08*/ int EffectID;
/*0x0c*/ int BaseEffect;
/*0x10*/
};

struct FELLOWSHIPMEMBER
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
struct FELLOWSHIPINFO
{
	/*0x000*/ unsigned int     Version;
	/*0x004*/ unsigned int     Version2;                       // just place holders for now, ill fix these later
	/*0x008*/ unsigned int     Version3;
	/*0x00c*/ unsigned int     Version4;
	/*0x010*/ unsigned int     FellowshipID;
	/*0x014*/ unsigned int     FellowshipID2;                  // guild does this too, need to figure out why
	/*0x018*/ char             Leader[0x40];
	/*0x058*/ char             MotD[0x400];
	/*0x458*/ unsigned int     Members;
	/*0x45c*/ FELLOWSHIPMEMBER FellowshipMember[0xc];          // size 0xc * 0x54 = 0x3f0
	/*0x84c*/ unsigned int     Sync;
	/*0x850*/ FSDATA           Somedata[0xc];//size 0x180
	/*0x9d0*/ bool             bExpSharingEnabled[0xc];
	/*0x9dc*/ bool             bSharedExpCapped[0xc];
	/*0x9e8*/
};
using PFELLOWSHIPINFO [[deprecated]] = FELLOWSHIPINFO *;

// size 0x58 see 442783 in eqgame.exe 2017 04 11 test
struct LAUNCHSPELLDATA
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

class PhysicsBase
{
public:
/*0x1fA4*/ void* vtable2;
/*0x1FA8*/ bool  bApplyGravity;
};

class PlayerPhysics : public PhysicsBase
{
public:
/*0x1FAC*/ SPAWNINFO*       pSpawn;              // PlayerBase
/*0x1FB0*/ GravityBehavior  Levitate;
// bobbing control
/*0x1Fb4*/ int              UpDownIndex;
/*0x1Fb8*/ int              LeftRightIndex;
/*0x1Fbc*/ int              UpDownSpeed;
/*0x1Fc0*/ int              LeftRightSpeed;
/*0x1Fc4*/ float            LeftRightDist;
/*0x1Fc8*/ float            UpDownDist;
/*0x1Fcc*/
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
struct SPAWNINFO
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
/*0x00a0*/ uint8_t              HeadWet;                      // these really are environment related, like lava as well for example
/*0x00a1*/ uint8_t              FeetWet;
/*0x00a2*/ uint8_t              BodyWet;
/*0x00a3*/ uint8_t              LastBodyWet;
/*0x00a4*/ char              Name[0x40];                   // ie priest_of_discord00 
/*0x00e4*/ char              DisplayedName[0x40];          // ie Priest of Discord
/*0x0124*/ uint8_t              PossiblyStuck;                // never seen this be 1 so maybe it was used a a point but not now... 
/*0x0125*/ uint8_t              Type;
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

#include "../test/PlayerZoneClient-Members.h"

/*0x0614*/ // I wont finetune these comments every single patch cause they change since PLAYERZONECLIENT size change...
/*0x0614*/ TCircularBuffer<SDoCollisionMovementStats, 0x14> MovementStats; // size (0x74 * 0x14) +8 = 0x918
/*0x0f2C*/ SPAWNINFO*        WhoFollowing;                 // NULL if autofollow off
/*0x0f30*/ unsigned int      GroupAssistNPC[0x1];
/*0x0f34*/ unsigned int      RaidAssistNPC[0x3];
/*0x0f40*/ unsigned int      GroupMarkNPC[0x3];
/*0x0f4c*/ unsigned int      RaidMarkNPC[0x3];
/*0x0f58*/ unsigned int      TargetOfTarget;
/*0x0f5c*/ uint8_t           PhysStuff[0x20];
/*0x0f7c*/ unsigned int      ParticleCastStartTime;
/*0x0f80*/ unsigned int      ParticleCastDuration;
/*0x0f84*/ int               ParticleVisualSpellNum;
/*0x0f88*/ uint8_t           Filler0x0f88[0x4];
/*0x0f8C*/ ActorClient       mActorClient;                 // start of ActorClient struct  size 0x1BC?
/*0x1148*/ PlayerAnimationBase *pAnimation;
/*0x114c*/ float             MeleeRadius;                  // used by GetMeleeRange
/*0x1150*/ unsigned int      CollisionCounter;
/*0x1154*/ float             CachedFloorLocationY;
/*0x1158*/ float             CachedFloorLocationX;
/*0x115c*/ float             CachedFloorLocationZ;
/*0x1160*/ float             CachedFloorHeight;
/*0x1164*/ float             CachedCeilingLocationY;
/*0x1168*/ float             CachedCeilingLocationX;
/*0x116c*/ float             CachedCeilingLocationZ;
/*0x1170*/ float             CachedCeilingHeight;
/*0x1174*/ CCapsule          StaticCollision;              // size 0x1c
/*0x1190*/ ArrayClass<PhysicsEffect> mPhysicsEffects;      // size is 0x10
/*0x11a0*/ ArrayClass<bool>  PhysicsEffectsUpdated;        // size is 0x10
/* ********************* PlayerZoneClient Ends Here ******************* */
/* ********************** PlayerClient Starts Here ******************** */
/*0x11b0*/ int               Animation;                    // Current Animation Playing. see 5671F1 in feb 14 2019 test
/*0x11ac*/ int               NextAnim;
/*0x11b0*/ int               CurrLowerBodyAnim;
/*0x11b4*/ int               NextLowerBodyAnim;
/*0x11b8*/ int               CurrLowerAnimVariation;
/*0x11bc*/ int               CurrAnimVariation;
/*0x11c0*/ int               CurrAnimRndVariation;
/* ********************sound ID's BEGIN ******************* */
/*0x11c4*/ int               Loop3d_SoundID;               //see 567254 in feb 14 2019 test
/*0x11c8*/ int               Step_SoundID;;
/*0x11cc*/ int               CurLoop_SoundID;
/*0x11d0*/ int               Idle3d1_SoundID;
/*0x11d4*/ int               Idle3d2_SoundID;
/*0x11d8*/ int               Jump_SoundID;
/*0x11dc*/ int               Hit1_SoundID;
/*0x11e0*/ int               Hit2_SoundID;
/*0x11e4*/ int               Hit3_SoundID;
/*0x11e8*/ int               Hit4_SoundID;
/*0x11ec*/ int               Gasp1_SoundID;
/*0x11f0*/ int               Gasp2_SoundID;
/*0x11f4*/ int               Drown_SoundID;
/*0x11f8*/ int               Death_SoundID;
/*0x11fc*/ int               Attk1_SoundID;
/*0x1200*/ int               Attk2_SoundID;
/*0x1204*/ int               Attk3_SoundID;
/*0x1208*/ int               Walk_SoundID;
/*0x120c*/ int               Run_SoundID;
/*0x1210*/ int               Crouch_SoundID;
/*0x1214*/ int               Swim_SoundID;
/*0x1218*/ int               TreadWater_SoundID;
/*0x121c*/ int               Climb_SoundID;
/*0x1220*/ int               Sit_SoundID;
/*0x1224*/ int               Kick_SoundID;
/*0x1228*/ int               Bash_SoundID;
/*0x122c*/ int               FireBow_SoundID;
/*0x1230*/ int               MonkAttack1_SoundID;
/*0x1234*/ int               MonkAttack2_SoundID;
/*0x1238*/ int               MonkSpecial_SoundID;
/*0x123c*/ int               PrimaryBlunt_SoundID;
/*0x1240*/ int               PrimarySlash_SoundID;
/*0x1244*/ int               PrimaryStab_SoundID;
/*0x1248*/ int               Punch_SoundID;
/*0x124c*/ int               Roundhouse_SoundID;
/*0x1250*/ int               SecondaryBlunt_SoundID;
/*0x1254*/ int               SecondarySlash_SoundID;
/*0x1258*/ int               SecondaryStab_SoundID;
/*0x125c*/ int               SwimAttack_SoundID;
/*0x1260*/ int               TwoHandedBlunt_SoundID;
/*0x1264*/ int               TwoHandedSlash_SoundID;
/*0x1268*/ int               TwoHandedStab_SoundID;
/*0x126c*/ int               SecondaryPunch_SoundID;
/*0x1270*/ int               JumpAcross_SoundID;
/*0x1274*/ int               WalkBackwards_SoundID;
/*0x1278*/ int               CrouchWalk_SoundID;
/* ******************** sound ID's END ****************** */
/*0x127c*/ unsigned int      LastHurtSound;                // see 5E96E0 in feb 14 2019 test
/*0x1280*/ unsigned int      LastWalkTime;                 // used for animations
/*0x1284*/ int               ShipRelated;                  // ID? look into.
/*0x1288*/ int               RightHolding;                 // Nothing=0 Other/Weapon=1 shield=2
/*0x128c*/ int               LeftHolding;                  // old Holding
/*0x1290*/ unsigned int      DeathAnimationFinishTime;
/*0x1294*/ bool              bRemoveCorpseAfterDeathAnim;  // 0x1274 for sure used by /hidecorpse
/*0x1298*/ unsigned int      LastBubblesTime;
/*0x129c*/ unsigned int      LastBubblesTime1;
/*0x12a0*/ unsigned int      LastColdBreathTime;
/*0x12a4*/ unsigned int      LastParticleUpdateTime;
/*0x12a8*/ unsigned int      MercID;                       // IT IS 0x1288      //if the spawn is player and has a merc up this is it's spawn ID -eqmule 16 jul 2014
/*0x12ac*/ unsigned int      ContractorID;                 // if the spawn is a merc this is its contractor's spawn ID -eqmule 16 jul 2014
/*0x12b0*/ float             CeilingHeightAtCurrLocation;
/*0x12b4*/ void*             MobileEmitter;                // todo: change and map to EqMobileEmitter*
/*0x12b8*/ bool              bInstantHPGaugeChange;
/*0x12bc*/ unsigned int      LastUpdateReceivedTime;
/*0x12c0*/ float             MaxSpeakDistance;
/*0x12c4*/ float             WalkSpeed;                    // how much we will slow down while sneaking
/*0x12c8*/ bool              bHideCorpse;
/*0x12c9*/ char              AssistName[0x40];
/*0x1309*/ bool              InvitedToGroup;
/*0x130c*/ int               GroupMemberTargeted;          // 0xFFFFFFFF if no target, else 1 through 5
/*0x1310*/ bool              bRemovalPending;              // see 5E0763 in feb 14 2019 test
/*0x1314*/ void*             pCorpse;
/*0x1318*/ float             EmitterScalingRadius;
/*0x131c*/ int               DefaultEmitterID;
/*0x1320*/ bool              bDisplayNameSprite;
/*0x1321*/ bool              bIdleAnimationOff;
/*0x1322*/ bool              bIsInteractiveObject;
/*0x1323*/ uint8_t           InteractiveObjectModelName[0x80];
/*0x13a3*/ uint8_t           InteractiveObjectOtherName[0x80];
/*0x1423*/ uint8_t           InteractiveObjectName[0x40];
/*0x1464*/ CPhysicsInfo      PhysicsBeforeLastPort;        // size IS /*0x30*/ see 5E617B in feb 14 2019 test
/*0x1494*/ unsigned int      notsure;                      // could be part of CPhysicsInfo?
/*0x1498*/ FELLOWSHIPINFO    Fellowship;                   // IT IS AT 0x1498 see 63BEDD in feb 14 2019 test // size 0x9e8
/*0x1E80*/ float             CampfireY;
/*0x1e84*/ float             CampfireX;
/*0x1e88*/ float             CampfireZ;
/*0x1e8c*/ int               CampfireZoneID;               // zone ID where campfire is
/*0x1e90*/ int               CampfireTimestamp;            // CampfireTimestamp-FastTime()=time left on campfire
/*0x1e94*/ int               CampfireTimestamp2;
/*0x1e98*/ int               FellowShipID;
/*0x1e9c*/ int               FellowShipID2;
/*0x1eA0*/ int               CampType;
/*0x1eA4*/ bool              Campfire;
/*0x1eA8*/ TSafeArrayStatic<int, 3> SeeInvis;              // for sure see 63E23F or 63BD35 in feb 14 2019 test
/*0x1EB4*/ EQUIPMENT         Equipment;                    // size 0xb4 see 63BF44 in feb 14 2019 test
/*0x1F68*/ bool              bIsPlacingItem;               // for sure see 543626 in feb 14 2019 test
/*0x1f69*/ bool              bGMCreatedNPC;
/*0x1f6c*/ int               ObjectAnimationID;
/*0x1f70*/ bool              bInteractiveObjectCollidable;
/*0x1f74*/ int               InteractiveObjectType;
/*0x1f78*/ int               SoundIDs[0xa];                // 0x28 bytes for sure see 648AB2 in feb 14 2019 test
/*0x1fA0*/ unsigned int      LastHistorySentTime;          // for sure see 648E7E in feb 14 2019 test
/*0x1fA4*/ ArrayClass2<unsigned int> BardTwistSpells;      // size 0x18
/*0x1fBC*/ int               CurrentBardTwistIndex;
/*0x1fC0*/ int               CurrentBardTwistIndex2;
/*0x1fC4*/ PlayerPhysicsClient mPlayerPhysicsClient;//size 0x28
/*0x1FEC*/ int               SpawnStatus[6];               // todo: look closer at these i think they can show like status of mobs slowed, mezzed etc, but not sure
/*0x2004*/ int               BannerIndex0;                 // guild banners
/*0x2008*/ int               BannerIndex1;
/*0x200C*/ ARGBCOLOR         BannerTint0;
/*0x2010*/ ARGBCOLOR         BannerTint1;
/*0x2014*/ int               MountAnimationRelated;
/*0x2018*/ bool              bGuildShowAnim;               // or sprite? need to check
/*0x2019*/ bool              bWaitingForPort;              // for sure see 5C5445 in feb 14 2019 test
/*0x201C*/ int               Unknown0x201C;
/* ********************** PlayerClient Ends Here ******************** */
/*0x2028*/ // see SpawnInfoSize

	int GetClass() { return mActorClient.Class; }
	uint8_t GetCharacterType() { return Type; }
	unsigned int GetId() const { return SpawnID; }

	EQLIB_OBJECT void* GetCharacter() const;
	EQLIB_OBJECT int   GetZoneID() const;
	EQLIB_OBJECT int   GetCurrentMana() const;
	EQLIB_OBJECT int   GetMaxMana() const;
	EQLIB_OBJECT int   GetCurrentEndurance() const;
	EQLIB_OBJECT int   GetMaxEndurance() const;
	EQLIB_OBJECT int   GetSpellCooldownETA() const;
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

struct SPAWNMANAGER
{
/*0x000*/ void*        vftable;
/*0x004*/ DWORD        random;                   // rand() % 20000
/*0x008*/ SPAWNINFO*   FirstSpawn;
/*0x00c*/ SPAWNINFO*   LastSpawn;
/*0x010*/ DWORD        unknown10;
/*0x014*/ HASHTABLE*   SPHash;
};
using PSPAWNMANAGER = SPAWNMANAGER*;

// A.k.a. PlayerManagerClient
class EQPlayerManager
{
public:
	EQLIB_OBJECT PlayerClient* GetSpawnByID(int);
	EQLIB_OBJECT PlayerClient* GetSpawnByName(char*);
	EQLIB_OBJECT PlayerClient* GetPlayerFromPartialName(const char*, PlayerBase*);

	SPAWNMANAGER Data;
};

//============================================================================
// PlayerBase
//============================================================================

// this is the size of EQPlayer__EQPlayer_x
// actual size 0x2020 in Feb 20 2016 Live (see 64B6A0) - eqmule
// A.k.a. SPAWNINFO
class PlayerBase : public TListNode<PlayerBase>, public CActorApplicationData
{
public:
/*0x0010*/ float             JumpStrength;
/*0x0014*/ float             SwimStrength;
/*0x0018*/ float             SpeedMultiplier;
/*0x001c*/ float             AreaFriction;
/*0x0020*/ float             AccelerationFriction;
/*0x0024*/ EActorType        CollidingType;                // when we collide with something this gets set.
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
/*0x012c*/ uint8_t           CharPropFiller[0xc];          // well since the above is a CharacterPropertyHash we have to pad here...
/*0x0138*/ float             AvatarHeight;                 // height of avatar from groundwhen standing for sure see 5C06A0 in Jun 10 2019 test
/*0x013c*/ float             Height;
/*0x0140*/ float             Width;
/*0x0144*/ float             Length;
/*0x0148*/ int               Unknown0x0148;
/*0x014c*/ int               Unknown0x014C;
/*0x0150*/ unsigned int      SpawnID;
/*0x0154*/ unsigned int      PlayerState;                  // 0=Idle 1=Open 2=WeaponSheathed 4=Aggressive 8=ForcedAggressive 0x10=InstrumentEquipped 0x20=Stunned 0x40=PrimaryWeaponEquipped 0x80=SecondaryWeaponEquipped
/*0x0158*/ PlayerBase*       Vehicle;                      // NULL until you collide with a vehicle (boat,airship etc)
/*0x015c*/ PlayerBase*       Mount;                        // NULL if no mount present
/*0x0160*/ PlayerBase*       Rider;                        // SPAWNINFO of mount's rider
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

	unsigned int GetId() const { return SpawnID; }

	// These are methods that originated from EQPlayer. They might not
	// all still exist.
	bool IsAMount();
	bool MyFeetAreOnGround();
	bool HasProperty(unsigned int, int, int);
	bool IsTargetable();
	bool CanSee(const PlayerBase&);
	bool CanSee(const CVector3& pos);
	CLineSegment GetVisibilityLineSegment(const PlayerBase& other, unsigned int index = 0);

private:
	virtual void Dummy() {} // force a vtable
};

//============================================================================
// PlayerZoneClient
//============================================================================

class PlayerZoneClient : public PlayerBase
{
public:
/*0x0190*/ unsigned int                 LastIntimidateUse;

#include "../test/PlayerZoneClient-Members.h"

	enum { MAX_MOVEMENT_STATS = 20 };
/*0x0614*/ TCircularBuffer<SDoCollisionMovementStats, MAX_MOVEMENT_STATS> MovementStats; // size (0x74 * 0x14) +8 = 0x918
/*0x0f2C*/ PlayerClient*      WhoFollowing;                // NULL if autofollow off
/*0x0f30*/ unsigned int       GroupAssistNPC[0x1];
/*0x0f34*/ unsigned int       RaidAssistNPC[0x3];
/*0x0f40*/ unsigned int       GroupMarkNPC[0x3];
/*0x0f4c*/ unsigned int       RaidMarkNPC[0x3];
/*0x0f58*/ unsigned int       TargetOfTarget;
/*0x0f5c*/ uint8_t            PhysStuff[0x20];
/*0x0f7c*/ unsigned int       ParticleCastStartTime;
/*0x0f80*/ unsigned int       ParticleCastDuration;
/*0x0f84*/ int                ParticleVisualSpellNum;
/*0x0f88*/ uint8_t            Filler0x0f88[0x4];
/*0x0f8C*/ ActorClient        mActorClient;                // start of ActorClient struct  size 0x1BC?
/*0x1148*/ PlayerAnimationBase* pAnimation;
/*0x114c*/ float              MeleeRadius;                 // used by GetMeleeRange
/*0x1150*/ unsigned int       CollisionCounter;
/*0x1154*/ float              CachedFloorLocationY;
/*0x1158*/ float              CachedFloorLocationX;
/*0x115c*/ float              CachedFloorLocationZ;
/*0x1160*/ float              CachedFloorHeight;
/*0x1164*/ float              CachedCeilingLocationY;
/*0x1168*/ float              CachedCeilingLocationX;
/*0x116c*/ float              CachedCeilingLocationZ;
/*0x1170*/ float              CachedCeilingHeight;
/*0x1174*/ CCapsule           StaticCollision;
/*0x1190*/ ArrayClass<PhysicsEffect> mPhysicsEffects;
/*0x11a0*/ ArrayClass<bool>   PhysicsEffectsUpdated;

	int LegalPlayerRace(int race);

	// Some methods that were from EQPlayer in the past
	bool AllowedToAttack(PlayerZoneClient*, int);
	bool CanChangeForm(int Race, unsigned char Sex, float Height);
	bool CanIFitHere(const CVector3& pos, bool ignoreHeight = false);
	bool CanIHit(const PlayerZoneClient*, int);
	bool IsFlyer();
	bool IsInvisible(PlayerZoneClient*, bool = false);
	bool IWasHit(EQMissileHitinfo*, LAUNCHSPELLDATA*, int = 0);
	bool UpdatePlayerActor();
	float GetDefaultHeight(int race, unsigned char);
	float GetPlayerFloorHeight(float, float, float, unsigned char);
	int AimAtTarget(PlayerZoneClient*, EQMissile*);
	int CheckForJump();
	int GetArmorType(int, char*);
	int GetGuild() const;
	bool IsValidTeleport(float X, float Y, float Z, float Heading, float Distance);
	int Levitating();
	int MountableRace();
	int MovePlayer();
	int NotOnSameDeity(const PlayerZoneClient*, const EQ_Spell*);
	static void ComputeSpecialHeights(int, float*, float*, float*, float*, bool);
	unsigned char DoTeleport(char*, int);
	unsigned char DoTeleportB(int, float, float, float, float, char*, int);
	unsigned char GetNearestActorTag(char*, EActorType);
	unsigned char HandleAmmo();
	static unsigned char SkillUsed(unsigned char);
	unsigned int ModifyAttackSpeed(unsigned int, int);
	unsigned long GetArmorTint(int);
	void BodyEnvironmentChange(unsigned char);
	void ChangeHeight(float);
	void ChangePosition(unsigned char);
	void CheckForUnderFloor();
	void CleanUpVehicle();
	void DeleteMyMissiles();
	void DoFloorCheck();
	void FacePlayer(PlayerZoneClient*);
	void FeetEnvironmentChange(unsigned char);
	void GetActorTag(char*);
	void GetConscious();
	void HeadEnvironmentChange(unsigned char);
	void IDied(EQPlayerDeath*);
	void IHaveFallen(float);
	void InitSneakMod();
	void KnockedOut();
	void MakeRiderMountUp();
	void PositionOnFloor();
	void PushAlongHeading(float);
	void PutPlayerOnFloor();
	void ResetVariables();
	void SetAnimVariation();
	void SetArmorTint(int, unsigned long);
	void SetHeights();
	void SetRace(int);
	unsigned char GetLevel() const;

	bool DoAttack(BYTE slot, BYTE skill, PlayerZoneClient* Target, bool bSomething = false, bool bAuto = false, bool bDontknow = false);

	static PlayerZoneClient* GetClosestPlayerFromPartialName(const char* name, PlayerZoneClient* player, int maxPlayerType = 1);
};

//============================================================================
// PlayerClient
//============================================================================

class PlayerClient : public PlayerZoneClient
{
public:
/*0x11b0*/ int               Animation;                    // Current Animation Playing. see 5671F1 in feb 14 2019 test
/*0x11ac*/ int               NextAnim;
/*0x11b0*/ int               CurrLowerBodyAnim;
/*0x11b4*/ int               NextLowerBodyAnim;
/*0x11b8*/ int               CurrLowerAnimVariation;
/*0x11bc*/ int               CurrAnimVariation;
/*0x11c0*/ int               CurrAnimRndVariation;

	// Beginning of sound ids
/*0x11c4*/ int               Loop3d_SoundID;               // see 567254 in feb 14 2019 test
/*0x11c8*/ int               Step_SoundID;;
/*0x11cc*/ int               CurLoop_SoundID;
/*0x11d0*/ int               Idle3d1_SoundID;
/*0x11d4*/ int               Idle3d2_SoundID;
/*0x11d8*/ int               Jump_SoundID;
/*0x11dc*/ int               Hit1_SoundID;
/*0x11e0*/ int               Hit2_SoundID;
/*0x11e4*/ int               Hit3_SoundID;
/*0x11e8*/ int               Hit4_SoundID;
/*0x11ec*/ int               Gasp1_SoundID;
/*0x11f0*/ int               Gasp2_SoundID;
/*0x11f4*/ int               Drown_SoundID;
/*0x11f8*/ int               Death_SoundID;
/*0x11fc*/ int               Attk1_SoundID;
/*0x1200*/ int               Attk2_SoundID;
/*0x1204*/ int               Attk3_SoundID;
/*0x1208*/ int               Walk_SoundID;
/*0x120c*/ int               Run_SoundID;
/*0x1210*/ int               Crouch_SoundID;
/*0x1214*/ int               Swim_SoundID;
/*0x1218*/ int               TreadWater_SoundID;
/*0x121c*/ int               Climb_SoundID;
/*0x1220*/ int               Sit_SoundID;
/*0x1224*/ int               Kick_SoundID;
/*0x1228*/ int               Bash_SoundID;
/*0x122c*/ int               FireBow_SoundID;
/*0x1230*/ int               MonkAttack1_SoundID;
/*0x1234*/ int               MonkAttack2_SoundID;
/*0x1238*/ int               MonkSpecial_SoundID;
/*0x123c*/ int               PrimaryBlunt_SoundID;
/*0x1240*/ int               PrimarySlash_SoundID;
/*0x1244*/ int               PrimaryStab_SoundID;
/*0x1248*/ int               Punch_SoundID;
/*0x124c*/ int               Roundhouse_SoundID;
/*0x1250*/ int               SecondaryBlunt_SoundID;
/*0x1254*/ int               SecondarySlash_SoundID;
/*0x1258*/ int               SecondaryStab_SoundID;
/*0x125c*/ int               SwimAttack_SoundID;
/*0x1260*/ int               TwoHandedBlunt_SoundID;
/*0x1264*/ int               TwoHandedSlash_SoundID;
/*0x1268*/ int               TwoHandedStab_SoundID;
/*0x126c*/ int               SecondaryPunch_SoundID;
/*0x1270*/ int               JumpAcross_SoundID;
/*0x1274*/ int               WalkBackwards_SoundID;
/*0x1278*/ int               CrouchWalk_SoundID;

/*0x127c*/ unsigned int      LastHurtSound;                // see 5E96E0 in feb 14 2019 test
/*0x1280*/ unsigned int      LastWalkTime;                 // used for animations
/*0x1284*/ int               ShipRelated;                  // ID? look into.
/*0x1288*/ int               RightHolding;                 // Nothing=0 Other/Weapon=1 shield=2
/*0x128c*/ int               LeftHolding;                  // old Holding
/*0x1290*/ unsigned int      DeathAnimationFinishTime;
/*0x1294*/ bool              bRemoveCorpseAfterDeathAnim;  // 0x1274 for sure used by /hidecorpse
/*0x1298*/ unsigned int      LastBubblesTime;
/*0x129c*/ unsigned int      LastBubblesTime1;
/*0x12a0*/ unsigned int      LastColdBreathTime;
/*0x12a4*/ unsigned int      LastParticleUpdateTime;
/*0x12a8*/ unsigned int      MercID;                       // IT IS 0x1288      //if the spawn is player and has a merc up this is it's spawn ID - 16 jul 2014
/*0x12ac*/ unsigned int      ContractorID;                 // if the spawn is a merc this is its contractor's spawn ID - 16 jul 2014
/*0x12b0*/ float             CeilingHeightAtCurrLocation;
/*0x12b4*/ void*             MobileEmitter;                // todo: change and map to EqMobileEmitter*
/*0x12b8*/ bool              bInstantHPGaugeChange;
/*0x12bc*/ unsigned int      LastUpdateReceivedTime;
/*0x12c0*/ float             MaxSpeakDistance;
/*0x12c4*/ float             WalkSpeed;                    // how much we will slow down while sneaking
/*0x12c8*/ bool              bHideCorpse;
/*0x12c9*/ char              AssistName[0x40];
/*0x1309*/ bool              InvitedToGroup;
/*0x130c*/ int               GroupMemberTargeted;          // 0xFFFFFFFF if no target, else 1 through 5
/*0x1310*/ bool              bRemovalPending;              // see 5E0763 in feb 14 2019 test
/*0x1314*/ void*             pCorpse;
/*0x1318*/ float             EmitterScalingRadius;
/*0x131c*/ int               DefaultEmitterID;
/*0x1320*/ bool              bDisplayNameSprite;
/*0x1321*/ bool              bIdleAnimationOff;
/*0x1322*/ bool              bIsInteractiveObject;
/*0x1323*/ uint8_t           InteractiveObjectModelName[0x80];
/*0x13a3*/ uint8_t           InteractiveObjectOtherName[0x80];
/*0x1423*/ uint8_t           InteractiveObjectName[0x40];
/*0x1463*/
/*0x1464*/ CPhysicsInfo      PhysicsBeforeLastPort;        // size IS /*0x30*/ see 5E617B in feb 14 2019 test
/*0x1494*/ unsigned int      notsure;                      // could be part of CPhysicsInfo?
/*0x1498*/ FELLOWSHIPINFO    Fellowship;                   // IT IS AT 0x1498 see 63BEDD in feb 14 2019 test // size 0x9e8
/*0x1E80*/ float             CampfireY;
/*0x1e84*/ float             CampfireX;
/*0x1e88*/ float             CampfireZ;
/*0x1e8c*/ int               CampfireZoneID;               // zone ID where campfire is
/*0x1e90*/ int               CampfireTimestamp;            // CampfireTimestamp-FastTime()=time left on campfire
/*0x1e94*/ int               CampfireTimestamp2;
/*0x1e98*/ int               FellowShipID;
/*0x1e9c*/ int               FellowShipID2;
/*0x1eA0*/ int               CampType;
/*0x1eA4*/ bool              Campfire;
/*0x1eA8*/ TSafeArrayStatic<int, 3> SeeInvis;              // for sure see 63E23F or 63BD35 in feb 14 2019 test
/*0x1EB4*/ EQUIPMENT         Equipment;                    // size 0xb4 see 63BF44 in feb 14 2019 test
/*0x1F68*/ bool              bIsPlacingItem;               // for sure see 543626 in feb 14 2019 test
/*0x1f69*/ bool              bGMCreatedNPC;
/*0x1f6c*/ int               ObjectAnimationID;
/*0x1f70*/ bool              bInteractiveObjectCollidable;
/*0x1f74*/ int               InteractiveObjectType;
/*0x1f78*/ int               SoundIDs[0xa];                // 0x28 bytes for sure see 648AB2 in feb 14 2019 test
/*0x1fA0*/ unsigned int      LastHistorySentTime;          // for sure see 648E7E in feb 14 2019 test
/*0x1fA4*/ ArrayClass2<unsigned int> BardTwistSpells;      // size 0x18
/*0x1fBC*/ int               CurrentBardTwistIndex;
/*0x1fC0*/ int               CurrentBardTwistIndex2;
/*0x1fC4*/ PlayerPhysicsClient mPlayerPhysicsClient;       // size 0x28
/*0x1FEC*/ int               SpawnStatus[6];               // todo: look closer at these i think they can show like status of mobs slowed, mezzed etc, but not sure
/*0x2004*/ int               BannerIndex0;                 // guild banners
/*0x2008*/ int               BannerIndex1;
/*0x200C*/ ARGBCOLOR         BannerTint0;
/*0x2010*/ ARGBCOLOR         BannerTint1;
/*0x2014*/ int               MountAnimationRelated;
/*0x2018*/ bool              bGuildShowAnim;               // or sprite? need to check
/*0x2019*/ bool              bWaitingForPort;              // for sure see 5C5445 in feb 14 2019 test
/*0x201C*/ int               Unknown0x201C;

/*0x2028*/ //see SpawnInfoSize

	void Initialize(PlayerClient*, unsigned char, unsigned int, unsigned char, char*);
	~PlayerClient();

	int GetClass() const { return mActorClient.Class; }
	BYTE GetCharacterType() const { return Type; }
	unsigned int GetId() const { return SpawnID; }
	CharacterZoneClient* GetCharacter() const { return (CharacterZoneClient*)spawneqc_info; }
	int GetZoneID() const { return Zone; }
	int GetCurrentMana() const { return ManaCurrent; }
	int GetMaxMana() const { return ManaMax; }
	int GetCurrentEndurance() const { return EnduranceCurrent; }
	int GetMaxEndurance() const { return EnduranceMax; }
	int GetSpellCooldownETA() const { return SpellCooldownETA; }
	bool IsGm() const { return GM; }

	PcClient* GetPcClient() const;

	// These come from the old EQPlayer class. Not all of these methods still exist.
	bool IsInvited();
	bool IsRoleplaying();
	bool IsUntexturedHorse();
	bool const HasInvalidRiderTexture() const;
	int CanBeBald();
	int SetPlayerPitchType();
	int SwapBody(int, int);
	int SwapFace(int, int);
	int SwapHead(int, int, unsigned long, int);
	int SwapMaterial(int, int, int, int, unsigned char);
	int SwapNPCMaterials();
	static void UpdateAllPlayersVisibility();
	CLightInterface* CreateUserLight(CLightDefinitionInterface*, int);
	unsigned char GetBaseFaceNbr(int, unsigned char*);
	unsigned char HasAttachedBeard();
	unsigned char HasAttachedHair();
	unsigned char UpdateItemSlot(unsigned char, char*, int);
	unsigned int CalcAnimLength(int);
	void ChangeLight();
	void CleanUpMyEffects();
	void CleanUpTarget();
	void Dismount();
	void DisplayWeaponsAndArmor();
	void do_change_form(chngForm*);
	void DoCamAi();
	void DoClassRandomAnimation();
	void DoItemSlot(int);
	void DoSwimJump(unsigned char);
	void FollowPlayerAI();
	void ForceInvisible(bool);
	void HandleMaterialEx(int, unsigned int, unsigned int, unsigned long, int);
	void HandoverControlToZoneserver();
	void MountEQPlayer(PlayerZoneClient*);
	void PlaySound(int);
	void SetAccel(float, int);
	void SetAfk(int);
	void SetCurrentLoopSound(int);
	void SetDefaultFacialFeaturesByFace(int, unsigned char, unsigned char);
	void SetInvited(bool);
	void SetSounds();
	void SetToRandomRace();
	void TouchingSwitch();
	void TriggerSpellEffect(EQMissileHitinfo*);
	void TurnOffAutoFollow();
	void UpdateAppearance();
	void UpdateBonePointers();
	void UpdateNameSprite();
	void UpdatePlayerVisibility();
	void ChangeBoneStringSprite(int bone, char* spriteText);
	int SetNameSpriteState(bool);
	bool SetNameSpriteTint();

	static PlayerClient* IsPlayerActor(CActorInterface*);
};

// For compatibility with all the old stuff
using EQPlayer [[deprecated]] = PlayerClient;

} // namespace eqlib

using namespace eqlib;
