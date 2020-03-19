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
#include "SoeUtil.h"

namespace eqlib {

constexpr int ITEM_NAME_LEN = 64;
constexpr int LORE_NAME_LEN = 80;

constexpr int NUM_INV_SLOTS = 33;
constexpr int NUM_BANK_SLOTS = 24;
constexpr int NUM_BAG_SLOTS = 10;
constexpr int NUM_WORN_ITEMS = 21;
constexpr int NUM_SHAREDBANK_SLOTS = 6;
constexpr int MAX_KEYRINGITEMS = 27; // not really sure need to confirm this

#if 0 // to be enabled when compatible
class ItemClient;
using CONTENTS = ItemClient;
using CONTENTS* = ItemClient *;
#endif

enum ItemContainerInstance
{
	eItemContainerInvalid                        = -1,
	eItemContainerPossessions                    = 0,
	eItemContainerBank                           = 1,
	eItemContainerSharedBank                     = 2,
	eItemContainerTrade                          = 3,
	eItemContainerWorld                          = 4,
	eItemContainerLimbo                          = 5,
	eItemContainerTribute                        = 6,
	eItemContainerTrophyTribute                  = 7,
	eItemContainerGuildTribute                   = 8,
	eItemContainerMerchant                       = 9,
	eItemContainerDeleted                        = 10,
	eItemContainerCorpse                         = 11,
	eItemContainerBazaar                         = 12,
	eItemContainerInspect                        = 13,
	eItemContainerRealEstate                     = 14,
	eItemContainerViewModPC                      = 15,
	eItemContainerViewModBank                    = 16,
	eItemContainerViewModSharedBank              = 17,
	eItemContainerViewModLimbo                   = 18,
	eItemContainerAltStorage                     = 19,
	eItemContainerArchived                       = 20,
	eItemContainerMail                           = 21,
	eItemContainerGuildTrophyTribute             = 22,
	eItemContainerKrono                          = 23,
	eItemContainerOther                          = 24,
	eItemContainerMercenaryItems                 = 25,
	eItemContainerViewModMercenaryItems          = 26,
	eItemContainerMountKeyRingItems              = 27,
	eItemContainerViewModMountKeyRingItems       = 28,
	eItemContainerIllusionKeyRingItems           = 29,
	eItemContainerViewModIllusionKeyRingItems    = 30,
	eItemContainerFamiliarKeyRingItems           = 31,
	eItemContainerViewModFamiliarKeyRingItems    = 32,
	eItemContainerCursor                         = 33,

	eNumItemContainers                           = 34,
};

class [[offsetcomments]] ItemIndex
{
	enum { MAX_INVENTORY_DEPTH = 3 };

public:
/*0x00*/ short m_slots[MAX_INVENTORY_DEPTH];
/*0x08*/

	EQLIB_OBJECT ItemIndex()
	{
		memset(m_slots, -1, sizeof(m_slots));
	}

	EQLIB_OBJECT explicit ItemIndex(short slot1, short slot2 = -1, short slot3 = -1)
	{
		m_slots[0] = slot1;
		m_slots[1] = slot2;
		m_slots[2] = slot3;
	}

	EQLIB_OBJECT bool operator==(const ItemIndex& other) const
	{
		return m_slots[0] == other.m_slots[0]
			&& m_slots[1] == other.m_slots[1]
			&& m_slots[2] == other.m_slots[2];
	}

	EQLIB_OBJECT short GetTopSlot() const { return m_slots[0]; }

	EQLIB_OBJECT void SetSlot(int depth, short value)
	{
		if (depth < MAX_INVENTORY_DEPTH)
			m_slots[depth] = value;
	}

	EQLIB_OBJECT short GetSlot(int depth) const
	{
		if (depth < MAX_INVENTORY_DEPTH)
			return m_slots[depth];

		return -1;
	}

	EQLIB_OBJECT bool IsValid() const { return m_slots[0] != -1; }
	EQLIB_OBJECT bool IsBase() const { return m_slots[0] != -1 && m_slots[1] == -1; }
	EQLIB_OBJECT bool IsInContainer() const { return m_slots[0] != -1 && m_slots[1] != -1; }

	// Remote one depth to get index representing whatever the parent is.
	EQLIB_OBJECT ItemIndex GetParentIndex() const
	{
		ItemIndex copy = *this;

		for (int i = MAX_INVENTORY_DEPTH - 1; i >= 0; --i)
		{
			if (copy.m_slots[i] != -1)
			{
				copy.m_slots[i] = -1;
				return copy;
			}
		}

		return copy;
	}

	// alias for existing bad code
	__declspec(property(get = getSlot1, put = setSlot1)) int Slot1;
	__declspec(property(get = getSlot2, put = setSlot2)) int Slot2;
	__declspec(property(get = getSlot3, put = setSlot3)) int Slot3;

	[[deprecated]] EQLIB_OBJECT int getSlot1() const { return m_slots[0]; }
	[[deprecated]] EQLIB_OBJECT void setSlot1(int v) { m_slots[0] = v; }
	[[deprecated]] EQLIB_OBJECT int getSlot2() const { return m_slots[1]; }
	[[deprecated]] EQLIB_OBJECT void setSlot2(int v) { m_slots[1] = v; }
	[[deprecated]] EQLIB_OBJECT int getSlot3() const { return m_slots[2]; }
	[[deprecated]] EQLIB_OBJECT void setSlot3(int v) { m_slots[2] = v; }
};

class [[offsetcomments]] ItemGlobalIndex
{
public:
/*0x00*/ ItemContainerInstance Location = eItemContainerInvalid;
/*0x04*/ ItemIndex Index;
/*0x0c*/

	EQLIB_OBJECT ItemGlobalIndex() = default;
	EQLIB_OBJECT ItemGlobalIndex(const ItemGlobalIndex& other)
		: Location(other.Location)
		, Index(other.Index)
	{}

	EQLIB_OBJECT bool operator==(const ItemGlobalIndex& other)
	{
		return Location == other.Location && Index == other.Index;
	}

	EQLIB_OBJECT void SetLocation(ItemContainerInstance location) { Location = location; }
	EQLIB_OBJECT ItemContainerInstance GetLocation() const { return Location; }

	EQLIB_OBJECT void SetIndex(const ItemIndex& index) { Index = index; }
	EQLIB_OBJECT ItemIndex& GetIndex() { return Index; }
	EQLIB_OBJECT const ItemIndex& GetIndex() const { return Index; }

	EQLIB_OBJECT short GetTopSlot() const { return GetIndex().GetTopSlot(); }

	EQLIB_OBJECT ItemGlobalIndex GetParent() const
	{
		ItemGlobalIndex copy = *this;

		copy.Index = copy.Index.GetParentIndex();
		return copy;
	}

	EQLIB_OBJECT bool IsKeyRingLocation() const
	{
		return Location == eItemContainerMountKeyRingItems
			|| Location == eItemContainerIllusionKeyRingItems
			|| Location == eItemContainerFamiliarKeyRingItems;
	}

	EQLIB_OBJECT bool IsEquippedLocation() const
	{
		return Location == eItemContainerPossessions
			&& Index.IsBase()
			&& Index.GetTopSlot() <= 22;
	}

	EQLIB_OBJECT bool IsValidIndex() const
	{
		return IsValidLocation() && Index.IsValid();
	}

	EQLIB_OBJECT bool IsValidLocation() const
	{
		return Location >= 0 && Location < eNumItemContainers;
	}
};

template <typename T>
class ItemContainer
{
public:
	using ItemPointer = VePointer<T>;
	using ItemArray = VeArray<ItemPointer>;

/*0x00*/ uint32_t                Size;
/*0x04*/ ItemContainerInstance   Spec;
/*0x08*/ ItemArray               Items;
/*0x0c*/ uint8_t                 AtDepth;
/*0x10*/ short                   Slots[2];
/*0x14*/ bool                    bDynamic;
/*0x18*/
};

class ItemBaseContainer : public ItemContainer<CONTENTS>
{
public:
};

template <typename T>
class IChildItemContainer
{
public:
	virtual ItemContainer<T>* GetChildItemContainer() = 0;
	virtual const ItemContainer<T>* GetChildItemContainer() const = 0;
	virtual VePointer<T> CreateCopy() const = 0;
	virtual void SetItemLocation(ItemContainerInstance container, const ItemIndex& index) = 0;
};

//============================================================================

enum eItemEffectType : uint8_t
{
	ItemEffectProc = 0,
	ItemEffectClicky,
	ItemEffectWorn,
	ItemEffectConsumable,
	ItemEffectClickyWorn,
	ItemEffectClickyRestricted,
	ItemEffectFocus,
	ItemEffectSpell,
	ItemEffectFocus2,
	ItemEffectMount,
	ItemEffectIllusion,
	ItemEffectFamiliar
};

// size is 0x64 02-16-2007
struct [[offsetcomments]] ITEMSPELLS
{
/*0x00*/ DWORD SpellID;
/*0x04*/ BYTE  RequiredLevel;
/*0x05*/ BYTE  EffectType;                       // bIsActivated
/*0x08*/ int   EffectiveCasterLevel;
/*0x0c*/ int   MaxCharges;
/*0x10*/ int   CastTime;
/*0x14*/ int   TimerID;                          // RecastTime
/*0x18*/ int   RecastType;
/*0x1c*/ int   ProcRate;                         // chance to proc
/*0x20*/ char  OtherName[0x40];                  // some kind of override
/*0x60*/ int   OtherID;                          // Description ID
/*0x64*/

	// Currently necessary because of MQ2DataTypes
	ITEMSPELLS() { ZeroMemory(this, sizeof(ITEMSPELLS)); }
};
using PITEMSPELLS = ITEMSPELLS*;

class [[offsetcomments]] ArmorProperties
{
public:
/*0x00*/ unsigned int Type;
/*0x04*/ unsigned int Variation;
/*0x08*/ unsigned int Material;
/*0x0c*/ unsigned int NewArmorID;
/*0x10*/ unsigned int NewArmorType;
/*0x14*/
};

struct [[offsetcomments]] AugSocket
{
/*0x00*/ int Type;
/*0x04*/ bool bVisible;
/*0x05*/ bool bInfusible;
/*0x08*/
};

#define MAX_AUG_SOCKETS 6

class ItemSocketData
{
public:
	AugSocket Sockets[MAX_AUG_SOCKETS];
};


// ItemDefinition class
// to check this look at ItemBase__ResetItemInstance_x
// actual size: 0x704 Nov  6 2018 Test (see 63F00F)
// actual size: 0x70c Oct 31 2018 Beta (see 7291CC)
struct [[offsetcomments]] ITEMINFO
{
/*0x000*/ char                Name[ITEM_NAME_LEN];
/*0x040*/ char                LoreName[LORE_NAME_LEN];
/*0x090*/ char                AdvancedLoreName[0x20];
/*0x0b0*/ char                IDFile[0x1e];
/*0x0ce*/ char                IDFile2[0x1e];
/*0x0ec*/ int                 ItemNumber;                        // recordnum
/*0x0f0*/ int                 EquipSlots;                        // its position, where it can be equipped
/*0x0f4*/ int                 Cost;
/*0x0f8*/ DWORD               IconNumber;
/*0x0fc*/ BYTE                eGMRequirement;                    // todo figure out this enum
/*0x0fd*/ bool                bPoofOnDeath;
/*0x100*/ DWORD               Weight;
/*0x104*/ bool                NoRent;                            // 0=temp, 1=default
/*0x105*/ bool                NoDrop;                            // 0=no drop, 1=can drop
/*0x106*/ bool                Attuneable;
/*0x107*/ bool                Heirloom;
/*0x108*/ bool                Collectible;
/*0x109*/ bool                NoDestroy;
/*0x10a*/ bool                bNoNPC;
/*0x10b*/ bool                NoZone;
/*0x10c*/ DWORD               MakerID;                           // 0-?? I did up to 12, I think it asks server for the name see 883655 in 11 jun 2018 test - eqmule
/*0x110*/ bool                NoGround;                          // 88607E 11 jun 2018 test
/*0x111*/ bool                bNoLoot;
/*0x112*/ bool                MarketPlace;                       // 886F85 11 jun 2018 test
/*0x113*/ bool                bFreeSlot;                         // 885565 11 jun 2018 test
/*0x114*/ bool                bAutoUse;                          // 885865 11 jun 2018 test
/*0x118*/ int                 Unknown0x0118;
/*0x11c*/ BYTE                Size;                              // 884920 11 jun 2018 test
/*0x11d*/ BYTE                Type;                              // 884BA5 11 jun 2018 test
/*0x11e*/ bool                TradeSkills;                       // 886EC5 11 jun 2018 test
/*0x120*/ int                 Lore;                              // -1=Lore 0=Not Lore >=1=Lore Group see 885EE1 in 11 jun 2018 test
/*0x124*/ int                 LoreEquipped;                      // just guessing todo: check
/*0x128*/ bool                Artifact;
/*0x129*/ bool                Summoned;
/*0x12a*/ char                SvCold;
/*0x12b*/ char                SvFire;                            // 8848B0 jun 11 2018 test
/*0x12c*/ char                SvMagic;
/*0x12d*/ char                SvDisease;
/*0x12e*/ char                SvPoison;
/*0x12f*/ char                SvCorruption;
/*0x130*/ char                STR;
/*0x131*/ char                STA;                               // 884B20 jun 11 2018 test
/*0x132*/ char                AGI;
/*0x133*/ char                DEX;
/*0x134*/ char                CHA;                               // 883E20 jun 11 2018 test
/*0x135*/ char                INT;
/*0x136*/ char                WIS;
/*0x138*/ int                 HP;                                // 884010 jun 11 2018 test
/*0x13c*/ int                 Mana;
/*0x140*/ int                 AC;
/*0x144*/ int                 RequiredLevel;
/*0x148*/ int                 RecommendedLevel;
/*0x14c*/ int                 RecommendedSkill;
/*0x150*/ int                 SkillModType;
/*0x154*/ int                 SkillModValue;
/*0x158*/ int                 SkillModMax;
/*0x15c*/ int                 SkillModBonus;
/*0x160*/ int                 BaneDMGRace;
/*0x164*/ int                 BaneDMGBodyType;
/*0x168*/ int                 BaneDMGBodyTypeValue;
/*0x16c*/ int                 BaneDMGRaceValue;
/*0x170*/ int                 InstrumentType;
/*0x174*/ int                 InstrumentMod;
/*0x178*/ int                 Classes;
/*0x17c*/ int                 Races;
/*0x180*/ int                 Diety;
/*0x184*/ UINT                MaterialTintIndex;
/*0x188*/ bool                Magic;
/*0x189*/ BYTE                Light;                      // 884045 jun 11 2018 test
/*0x18a*/ BYTE                Delay;
/*0x18b*/ BYTE                ElementalFlag;              // used to be called DmgBonusType;
/*0x18c*/ BYTE                ElementalDamage;            // used to be called DmgBonusVal
/*0x18d*/ BYTE                Range;
/*0x190*/ DWORD               Damage;                     // BaseDamage
/*0x194*/ DWORD               BackstabDamage;
/*0x198*/ DWORD               HeroicSTR;
/*0x19c*/ DWORD               HeroicINT;                  // 883A30 jun 11 2018 test
/*0x1a0*/ DWORD               HeroicWIS;                  // 883A90 jun 11 2018 test
/*0x1a4*/ DWORD               HeroicAGI;                  // 8839D0 jun 11 2018 test
/*0x1a8*/ DWORD               HeroicDEX;
/*0x1ac*/ DWORD               HeroicSTA;                  // 883A50 jun 11 2018 test
/*0x1b0*/ DWORD               HeroicCHA;                  // 8839F0 jun 11 2018 test
/*0x1b4*/ DWORD               HealAmount;                 // 883980 jun 11 2018 test
/*0x1b8*/ DWORD               SpellDamage;
/*0x1bc*/ int                 MinLuck;
/*0x1c0*/ int                 MaxLuck;
/*0x1c4*/ int                 Prestige;                   // 884816 jun 11 2018 test
/*0x1c8*/ BYTE                ItemType;
/*0x1cc*/ ArmorProperties     ArmorProps;                 // size is 0x14
/*0x1e0*/ ItemSocketData      AugData;
/*0x210*/ DWORD               AugType;
/*0x214*/ DWORD               AugSkinTypeMask;
/*0x218*/ DWORD               AugRestrictions;
/*0x21c*/ DWORD               SolventItemID;              // ID# of Solvent (Augs only)
/*0x220*/ DWORD               LDTheme;
/*0x224*/ DWORD               LDCost;
/*0x228*/ DWORD               LDType;
/*0x22c*/ int                 Unknown0x022c;
/*0x230*/ int                 Unknown0x0230;
//*0x0228*/ DWORD               FactionModType[0x4];
//*0x0238*/ DWORD               FactionModValue[0x4];
/*0x234*/ char                CharmFile[0x20];
/*0x254*/ float               Unknown0x0254;
/*0x258*/ ITEMSPELLS          Clicky;                     // size 0x64
/*0x2bc*/ ITEMSPELLS          Proc;
/*0x320*/ ITEMSPELLS          Worn;
/*0x384*/ ITEMSPELLS          Focus;
/*0x3e8*/ ITEMSPELLS          Scroll;
/*0x44c*/ ITEMSPELLS          Focus2;
/*0x4b0*/ ITEMSPELLS          Mount;
/*0x514*/ ITEMSPELLS          Illusion;
/*0x578*/ ITEMSPELLS          Familiar;
/*0x5dc*/ DWORD               SkillMask[5];               // this is just an array but I dont have time to figure it out for now.
/*0x5f0*/ DWORD               DmgBonusSkill;              // SkillMinDamageMod;
/*0x5f4*/ DWORD               DmgBonusValue;              // MinDamageMod;
/*0x5f8*/ DWORD               CharmFileID;
/*0x5fc*/ DWORD               FoodDuration;               // 0-5 snack 6-20 meal 21-30 hearty 31-40 banquet 41-50 feast 51-60 enduring 60- miraculous
/*0x600*/ BYTE                Combine;
/*0x601*/ BYTE                Slots;
/*0x602*/ BYTE                SizeCapacity;
/*0x603*/ BYTE                WeightReduction;
/*0x604*/ BYTE                BookType;                   // 0=note, !0=book 884CF5 jun 11 2018 test
/*0x605*/ BYTE                BookLang;
/*0x606*/ char                BookFile[0x1e];
/*0x624*/ DWORD               Favor;                      // Tribute Value
/*0x628*/ DWORD               GuildFavor;
/*0x62c*/ bool                bIsFVNoDrop;
/*0x630*/ DWORD               Endurance;
/*0x634*/ DWORD               Attack;
/*0x638*/ DWORD               HPRegen;
/*0x63c*/ DWORD               ManaRegen;
/*0x640*/ DWORD               EnduranceRegen;
/*0x644*/ DWORD               Haste;
/*0x648*/ int                 AnimationOverride;
/*0x64c*/ int                 PaletteTintIndex;
/*0x650*/ bool                bNoPetGive;
/*0x651*/ bool                bSomeProfile;
/*0x654*/ int                 SomeIDFlag;
/*0x658*/ int                 StackSize;
/*0x65c*/ bool                bNoStorage;
/*0x660*/ int                 MaxPower;
/*0x664*/ int                 Purity;
/*0x668*/ bool                bIsEpic;
/*0x66c*/ int                 RightClickScriptID;
/*0x670*/ int                 ItemLaunchScriptID;
/*0x674*/ BYTE                QuestItem;
/*0x675*/ BYTE                Expendable;
/*0x678*/ DWORD               Clairvoyance;
/*0x67c*/ int                 SubClass;
/*0x680*/ bool                bLoginRegReqItem;
/*0x684*/ DWORD               Placeable;
/*0x688*/ bool                bPlaceableIgnoreCollisions;
/*0x68c*/ int                 PlacementType;              // todo: this is an enum need to figure out.
/*0x690*/ int                 RealEstateDefID;
/*0x694*/ float               PlaceableScaleRangeMin;
/*0x698*/ float               PlaceableScaleRangeMax;
/*0x69c*/ int                 RealEstateUpkeepID;
/*0x6a0*/ int                 MaxPerRealEstate;
/*0x6a4*/ char                HousepetFileName[0x20];
/*0x6c4*/ int                 TrophyBenefitID;
/*0x6c8*/ bool                bDisablePlacementRotation;
/*0x6c9*/ bool                bDisableFreePlacement;
/*0x6cc*/ int                 NpcRespawnInterval;
/*0x6d0*/ float               PlaceableDefScale;
/*0x6d4*/ float               PlaceableDefHeading;
/*0x6d8*/ float               PlaceableDefPitch;
/*0x6dc*/ float               PlaceableDefRoll;
/*0x6e0*/ bool                bInteractiveObject;
/*0x6e1*/ uint8_t             SocketSubClassCount;
/*0x6e4*/ int                 SocketSubClass[0xa];
/*0x70c*/
};
using PITEMINFO = ITEMINFO*;

class EqItemGuid
{
public:
	enum { GUID = 18 };

	EqItemGuid()
	{
		memset(guid, 0, sizeof(guid));
	}

	char guid[GUID];
};

struct ITEMBASEARRAY;

class [[offsetcomments]] ItemArray
{
public:
/*0x00*/ ITEMBASEARRAY* pItems;
/*0x04*/ size_t         Size;
/*0x08*/ unsigned int   Capacity;
/*0x0c*/
};

class [[offsetcomments]] ItemBaseContainer2
{
public:
/*0x00*/ unsigned int ContentSize;
/*0x04*/ int          ItemLocation;
/*0x08*/ ItemArray    ContainedItems;
/*0x14*/ BYTE         Depth;
/*0x16*/ short        ItemSlot;
/*0x18*/ short        ItemSlot2;
/*0x1a*/ bool         bDynamic;
/*0x1c*/
};

struct [[offsetcomments]] ItemEvolutionData
{
	/*0x00*/ int    GroupID;
	/*0x04*/ int    EvolvingCurrentLevel;
	/*0x08*/ double EvolvingExpPct;
	/*0x10*/ int    EvolvingMaxLevel;
	/*0x14*/ int    LastEquipped;
/*0x18*/ };
using ItemEvolutionDataPtr = SoeUtil::SharedPtr<ItemEvolutionData>;

//============================================================================
// ItemBase
//============================================================================

class [[offsetcomments]] ItemBase
{
public:
/*0x00*/ void* vtable;

	// base class member - reference count
/*0x04*/ mutable int  RefCount;
	// base class vftable
/*0x08*/ void* punknown;

// @start: ItemBase Members
/*0x0c*/ int                AugFlag;
/*0x10*/ ItemGlobalIndex    GlobalIndex;                 // Size is 0xa (0xc)
/*0x1c*/ ITEMINFO*          Item1;
/*0x20*/ CXStr              ActorTag2;
/*0x28*/ int64_t            Price;
/*0x30*/ unsigned int       Tint;
/*0x34*/ int                NoDropFlag;
/*0x38*/ bool               bDisableAugTexture;
/*0x40*/ int64_t            MerchantSlot;
/*0x48*/ int                ID;
/*0x4c*/ ItemEvolutionDataPtr pEvolutionData;
/*0x54*/ CXStr              SaveString;
/*0x58*/ int                Luck;
/*0x5c*/ bool               bRankDisabled;
/*0x60*/ int                NoteStatus;
/*0x64*/ unsigned int       RespawnTime;
/*0x68*/ unsigned int       ItemHash;
/*0x6c*/ CXStr              ConvertItemName;
/*0x70*/ unsigned int       LastCastTime;
/*0x74*/ int                ArmorType;
/*0x78*/ int                StackCount;
/*0x7c*/ ItemBaseContainer2 Contents;                    // Size is 0x1c
/*0x98*/ unsigned int       NewArmorID;
/*0x9c*/ ArrayClass<unsigned int> RealEstateArray;
/*0xac*/ int                ConvertItemID;
/*0xb0*/ bool               bConvertable;
/*0xb4*/ int                OrnamentationIcon;
/*0xb8*/ int                ScriptIndex;
/*0xbc*/ bool               bCollected;
/*0xc0*/ int                MerchantQuantity;
/*0xc4*/ int                RealEstateID;
/*0xc8*/ CXStr              ActorTag1;
/*0xcc*/ int                Open;
/*0xd0*/ int                Charges;
/*0xd4*/ bool               bCopied;
/*0xd8*/ int                Power;
/*0xdc*/ bool               bItemNeedsUpdate;
/*0xdd*/ EqItemGuid         ItemGUID;
/*0xef*/ bool               bRealEstateItemPlaceable;
/*0xf0*/ int64_t            DontKnow;
/*0xf8*/
// @end: ItemBase Members

	EQLIB_OBJECT bool IsLore(bool bIncludeSockets = false) const;
	EQLIB_OBJECT bool IsLoreEquipped(bool bIncludeSockets = false) const;
};

// Actual Size: 0x158 (see 0x611DAC in eqgame.exe Test dated Jun 10 2019)
class [[offsetcomments]] ItemClient : public ItemBase
{
	FORCE_SYMBOLS;

public:
	// Reference counted pointer to ItemDefinition
/*0x0f8*/ DWORD        Item2RefCnt;
/*0x0fc*/ ITEMINFO*    Item2;
/*0x100*/ CXStr        ClientString;
/*0x104*/

	EQLIB_OBJECT ItemClient* GetContent(uint32_t index);
	EQLIB_OBJECT ItemGlobalIndex GetGlobalIndex() const;
};

//============================================================================
// CONTENTS
// This is ItemClient/ItemBase
//============================================================================

// Actual Size: 0x160 (see 0x62856C in eqgame.exe Live dated Dec 19 2019)
struct [[offsetcomments]] CONTENTS : public VeBaseReferenceCount,
	public IChildItemContainer<CONTENTS>
{
// @start: ItemBase Members
/*0x00c*/ int                AugFlag;
/*0x010*/ ItemGlobalIndex    GlobalIndex;                 // Size is 0xa (0xc)
/*0x01c*/ ITEMINFO*          Item1;
/*0x020*/ CXStr              ActorTag2;
/*0x028*/ int64_t            Price;
/*0x030*/ unsigned int       Tint;
/*0x034*/ int                NoDropFlag;
/*0x038*/ bool               bDisableAugTexture;
/*0x040*/ int64_t            MerchantSlot;
/*0x048*/ int                ID;
/*0x04c*/ ItemEvolutionDataPtr pEvolutionData;
/*0x054*/ CXStr              SaveString;
/*0x058*/ int                Luck;
/*0x05c*/ bool               bRankDisabled;
/*0x060*/ int                NoteStatus;
/*0x064*/ unsigned int       RespawnTime;
/*0x068*/ unsigned int       ItemHash;
/*0x06c*/ CXStr              ConvertItemName;
/*0x070*/ unsigned int       LastCastTime;
/*0x074*/ int                ArmorType;
/*0x078*/ int                StackCount;
/*0x07c*/ ItemBaseContainer2 Contents;                    // Size is 0x1c
/*0x098*/ unsigned int       NewArmorID;
/*0x09c*/ ArrayClass<unsigned int> RealEstateArray;
/*0x0ac*/ int                ConvertItemID;
/*0x0b0*/ bool               bConvertable;
/*0x0b4*/ int                OrnamentationIcon;
/*0x0b8*/ int                ScriptIndex;
/*0x0bc*/ bool               bCollected;
/*0x0c0*/ int                MerchantQuantity;
/*0x0c4*/ int                RealEstateID;
/*0x0c8*/ CXStr              ActorTag1;
/*0x0cc*/ int                Open;
/*0x0d0*/ int                Charges;
/*0x0d4*/ bool               bCopied;
/*0x0d8*/ int                Power;
/*0x0dc*/ bool               bItemNeedsUpdate;
/*0x0dd*/ EqItemGuid         ItemGUID;
/*0x0ef*/ bool               bRealEstateItemPlaceable;
/*0x0f0*/ int64_t            DontKnow;

// @end: ItemBase Members

	// start of ItemClient
/*0x0f8*/ uint32_t          Item2RefCnt;
/*0x0fc*/ ITEMINFO*         Item2;
/*0x100*/ CXStr             ClientString;
/*0x104*/ uint8_t           Filler0x0154[0x4];
/*0x108*/

	// Constructor is technically for ItemClient. Make sure the size
	// of the class matches.
	CONTENTS();

	// ItemClient::`vftable'{for `VeBaseReferenceCount'}
	virtual ~CONTENTS();
	virtual ITEMINFO* GetItemDefinition() { return nullptr; }
	virtual void SetItemDefinition(const ITEMINFO* item) {}
	// ... more


	// ItemClient::`vftable'{for `IChildItemContainer<class ItemBase>'}
	virtual ItemContainer<CONTENTS>* GetChildItemContainer() override { return (ItemContainer<CONTENTS>*)&Contents; }
	virtual const ItemContainer<CONTENTS>* GetChildItemContainer() const override { return (const ItemContainer<CONTENTS>*) & Contents; }
	virtual VePointer<CONTENTS> CreateCopy() const { return nullptr; }
	virtual void SetItemLocation(ItemContainerInstance container, const ItemIndex& index) {};

	EQLIB_OBJECT CONTENTS* GetContent(unsigned int index);
	EQLIB_OBJECT ItemGlobalIndex GetGlobalIndex() const;

	// Compatibility properties for ItemEvolutionData
	[[deprecated("Use pEvolutionData->GroupID instead")]]
	inline int get_EvolvingGroupID() { return pEvolutionData ? pEvolutionData->GroupID : 0; }
	__declspec(property(get = get_EvolvingGroupID)) int GroupID;

	[[deprecated("Use pEvolutionData->EvolvingCurrentLevel instead")]]
	inline int get_EvolvingCurrentLevel() { return pEvolutionData ? pEvolutionData->EvolvingCurrentLevel : 0; }
	__declspec(property(get = get_EvolvingCurrentLevel)) int EvolvingCurrentLevel;

	[[deprecated("Use pEvolutionData->EvolvingExpPct instead")]]
	inline double get_EvolvingExpPct() { return pEvolutionData ? pEvolutionData->EvolvingExpPct : 0.0; }
	__declspec(property(get = get_EvolvingExpPct)) double EvolvingExpPct;

	[[deprecated("Use pEvolutionData->EvolvingMaxLevel instead")]]
	inline int get_EvolvingMaxLevel() { return pEvolutionData ? pEvolutionData->EvolvingMaxLevel : 0; }
	__declspec(property(get = get_EvolvingMaxLevel)) int EvolvingMaxLevel;

	[[deprecated("Use pEvolutionData->LastEquipped instead")]]
	inline int get_LastEquipped() { return pEvolutionData ? pEvolutionData->LastEquipped : 0; }
	__declspec(property(get = get_LastEquipped)) int LastEquipped;
};
using PCONTENTS = CONTENTS*;


struct ITEMBASEARRAY
{
	CONTENTS* Item[1];
};
using PITEMBASEARRAY [[deprecated]] = ITEMBASEARRAY *;

union EqGuid
{
	struct
	{
		uint32_t UniqueEntityID;
		uint16_t WorldUniqueID;
		uint16_t Reserved;
	} fields;
	uint64_t GUID;

	EqGuid() : GUID(0) {}
};

// 20101012 - ieatacid
struct [[offsetcomments]] INVENTORY
{
/*0x00*/ CONTENTS* Charm;
/*0x04*/ CONTENTS* LeftEar;
/*0x08*/ CONTENTS* Head;
/*0x0c*/ CONTENTS* Face;
/*0x10*/ CONTENTS* RightEar;
/*0x14*/ CONTENTS* Neck;
/*0x18*/ CONTENTS* Shoulders;
/*0x1c*/ CONTENTS* Arms;
/*0x20*/ CONTENTS* Back;
/*0x24*/ CONTENTS* LeftWrist;
/*0x28*/ CONTENTS* RightWrist;
/*0x2c*/ CONTENTS* Range;
/*0x30*/ CONTENTS* Hands;
/*0x34*/ CONTENTS* Primary;
/*0x38*/ CONTENTS* Secondary;
/*0x3c*/ CONTENTS* LeftFinger;
/*0x40*/ CONTENTS* RightFinger;
/*0x44*/ CONTENTS* Chest;
/*0x48*/ CONTENTS* Legs;
/*0x4c*/ CONTENTS* Feet;
/*0x50*/ CONTENTS* Waist;
/*0x54*/ CONTENTS* PowerSource;
/*0x58*/ CONTENTS* Ammo;
/*0x5c*/ CONTENTS* Pack[NUM_BAG_SLOTS];
/*0x84*/ CONTENTS* Cursor;
/*0x88*/
};
using PINVENTORY [[deprecated]] = INVENTORY;

struct INVENTORYARRAY
{
	union
	{
	/*0x00*/ INVENTORY Inventory;
	/*0x00*/ CONTENTS* InventoryArray[NUM_INV_SLOTS];
	};
};
using PINVENTORYARRAY [[deprecated]] = INVENTORYARRAY*;

struct BANKARRAY
{
/*0x00*/ CONTENTS* Bank[NUM_BANK_SLOTS];
/*0x60*/
};
using PBANKARRAY [[deprecated]] = BANKARRAY *;

struct SHAREDBANKARRAY
{
/*0x00*/ CONTENTS* SharedBank[NUM_SHAREDBANK_SLOTS];
/*0x10*/
};
using PSHAREDBANKARRAY [[deprecated]] = SHAREDBANKARRAY*;

struct MERCEQUIPMENT
{
/*0x00*/ CONTENTS* MercEquipment[4];
/*0x68*/
};
using PMERCEQUIPMENT [[deprecated]] = MERCEQUIPMENT*;

struct KEYRINGARRAY
{
	union
	{
	/*0x00*/ CONTENTS* Mounts[MAX_KEYRINGITEMS];
	/*0x00*/ CONTENTS* Illusions[MAX_KEYRINGITEMS];
	/*0x00*/ CONTENTS* Familiars[MAX_KEYRINGITEMS];
	};
	/*0x28*/
};
using PKEYRINGARRAY [[deprecated]] = KEYRINGARRAY*;

// offsets are relative to their position in LAUNCHSPELLDATA
struct [[offsetcomments]] ITEMLOCATION
{
/*0x00*/ ItemContainerInstance Location [[deprecated("Use ItemGlobalIndex")]] ;
/*0x04*/ short InvSlot [[deprecated("Use ItemGlobalIndex")]] ;
/*0x06*/ short BagSlot [[deprecated("Use ItemGlobalIndex")]] ;
/*0x08*/ short AugSlot [[deprecated("Use ItemGlobalIndex")]] ;
/*0x0c*/
};
using PITEMLOCATION [[deprecated("Use ItemGlobalIndex")]] = ITEMLOCATION*;


} // namespace eqlib
