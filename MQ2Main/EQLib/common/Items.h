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

namespace eqlib {

#define NUM_SLOTDATA                             0x6

#define ITEM_NAME_LEN                            0x40
#define LORE_NAME_LEN                            0x50

#define NUM_INV_SLOTS                            0x21
#define NUM_BANK_SLOTS                           24
#define NUM_SHAREDBANK_SLOTS                     6
#define MAX_KEYRINGITEMS                         0x1B // not really sure need to confirm this

#if 0 // to be enabled when compatible
class ItemClient;
using CONTENTS = ItemClient;
using PCONTENTS = ItemClient *;
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

class ItemIndex
{
	enum { MAX_INVENTORY_DEPTH = 3 };

public:
	short m_slots[MAX_INVENTORY_DEPTH];

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

	[[deprecated]] EQLIB_OBJECT int getSlot1() { return m_slots[0]; }
	[[deprecated]] EQLIB_OBJECT void setSlot1(int v) { m_slots[0] = v; }
	[[deprecated]] EQLIB_OBJECT int getSlot2() { return m_slots[1]; }
	[[deprecated]] EQLIB_OBJECT void setSlot2(int v) { m_slots[1] = v; }
	[[deprecated]] EQLIB_OBJECT int getSlot3() { return m_slots[2]; }
	[[deprecated]] EQLIB_OBJECT void setSlot3(int v) { m_slots[2] = v; }
};

class ItemGlobalIndex
{
public:
	ItemContainerInstance Location = eItemContainerInvalid;
	ItemIndex Index;

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

//============================================================================

// size is 0x64 02-16-2007
struct ITEMSPELLS
{
/*0x00*/ DWORD SpellID;
/*0x04*/ BYTE  RequiredLevel;
/*0x05*/ BYTE  EffectType;                       // bIsActivated
/*0x08*/ DWORD EffectiveCasterLevel;
/*0x0c*/ DWORD MaxCharges;
/*0x10*/ DWORD CastTime;
/*0x14*/ DWORD TimerID;                          // RecastTime
/*0x18*/ DWORD RecastType;
/*0x1c*/ DWORD ProcRate;                         // chance to proc
/*0x20*/ CHAR  OtherName[0x40];                  // some kind of override
/*0x60*/ DWORD OtherID;                          // Description ID
/*0x64*/
};
using PITEMSPELLS = ITEMSPELLS*;

class ArmorProperties
{
public:
/*0x00*/ unsigned int Type;
/*0x04*/ unsigned int Variation;
/*0x08*/ unsigned int Material;
/*0x0c*/ unsigned int NewArmorID;
/*0x10*/ unsigned int NewArmorType;
/*0x14*/
};

struct AugSocket
{
	int Type;
	bool bVisible;
	bool bInfusible;
};

class ItemSocketData
{
public:
	AugSocket Sockets[6];
};

// ItemDefinition class
// to check this look at ItemBase__ResetItemInstance_x
// actual size: 0x704 Nov  6 2018 Test (see 63F00F)
// actual size: 0x70c Oct 31 2018 Beta (see 7291CC)
struct ITEMINFO
{
/*0x0000*/ CHAR                Name[ITEM_NAME_LEN];
/*0x0040*/ CHAR                LoreName[LORE_NAME_LEN];
/*0x0090*/ CHAR                AdvancedLoreName[0x20];
/*0x00b0*/ CHAR                IDFile[0x1e];
/*0x00ce*/ CHAR                IDFile2[0x1e];
/*0x00ec*/ DWORD               ItemNumber;                        // recordnum
/*0x00f0*/ DWORD               EquipSlots;                        // its position, where it can be equipped
/*0x00f4*/ DWORD               Cost;
/*0x00f8*/ DWORD               IconNumber;
/*0x00fc*/ BYTE                eGMRequirement;                    // todo figure out this enum
/*0x00fd*/ bool                bPoofOnDeath;
/*0x0100*/ DWORD               Weight;
/*0x0104*/ bool                NoRent;                            // 0=temp, 1=default
/*0x0105*/ bool                NoDrop;                            // 0=no drop, 1=can drop
/*0x0106*/ bool                Attuneable;
/*0x0107*/ bool                Heirloom;
/*0x0108*/ bool                Collectible;
/*0x0109*/ bool                NoDestroy;
/*0x010a*/ bool                bNoNPC;
/*0x010b*/ bool                NoZone;
/*0x010c*/ DWORD               MakerID;                           // 0-?? I did up to 12, I think it asks server for the name see 883655 in 11 jun 2018 test - eqmule
/*0x0110*/ bool                NoGround;                          // 88607E 11 jun 2018 test
/*0x0111*/ bool                bNoLoot;
/*0x0112*/ bool                MarketPlace;                       // 886F85 11 jun 2018 test
/*0x0113*/ bool                bFreeSlot;                         // 885565 11 jun 2018 test
/*0x0114*/ bool                bAutoUse;                          // 885865 11 jun 2018 test
/*0x0118*/ int                 Unknown0x0118;
/*0x011C*/ BYTE                Size;                              // 884920 11 jun 2018 test
/*0x011D*/ BYTE                Type;                              // 884BA5 11 jun 2018 test
/*0x011E*/ bool                TradeSkills;                       // 886EC5 11 jun 2018 test
/*0x0120*/ int                 Lore;                              // -1=Lore 0=Not Lore >=1=Lore Group see 885EE1 in 11 jun 2018 test
/*0x0124*/ int                 LoreEquipped;                      // just guessing todo: check
/*0x0128*/ bool                Artifact;
/*0x0129*/ bool                Summoned;
/*0x0130*/ CHAR                SvCold;
/*0x0131*/ CHAR                SvFire;                            // 8848B0 jun 11 2018 test
/*0x0132*/ CHAR                SvMagic;
/*0x0133*/ CHAR                SvDisease;
/*0x0134*/ CHAR                SvPoison;
/*0x0135*/ CHAR                SvCorruption;
/*0x0136*/ CHAR                STR;
/*0x0137*/ CHAR                STA;                               // 884B20 jun 11 2018 test
/*0x0138*/ CHAR                AGI;
/*0x0139*/ CHAR                DEX;
/*0x013a*/ CHAR                CHA;                               // 883E20 jun 11 2018 test
/*0x013b*/ CHAR                INT;
/*0x013c*/ CHAR                WIS;
/*0x0138*/ int                 HP;                                // 884010 jun 11 2018 test
/*0x013c*/ int                 Mana;
/*0x0140*/ int                 AC;
/*0x0144*/ int                 RequiredLevel;
/*0x0148*/ int                 RecommendedLevel;
/*0x014c*/ int                 RecommendedSkill;
/*0x0150*/ int                 SkillModType;
/*0x0154*/ int                 SkillModValue;
/*0x0158*/ int                 SkillModMax;
/*0x015c*/ int                 SkillModBonus;
/*0x0160*/ int                 BaneDMGRace;
/*0x0164*/ int                 BaneDMGBodyType;
/*0x0168*/ int                 BaneDMGBodyTypeValue;
/*0x016c*/ int                 BaneDMGRaceValue;
/*0x0170*/ int                 InstrumentType;
/*0x0174*/ int                 InstrumentMod;
/*0x0178*/ int                 Classes;
/*0x017c*/ int                 Races;
/*0x0180*/ int                 Diety;
/*0x0184*/ UINT                MaterialTintIndex;
/*0x0188*/ bool                Magic;
/*0x0189*/ BYTE                Light;                      // 884045 jun 11 2018 test
/*0x018a*/ BYTE                Delay;
/*0x018b*/ BYTE                ElementalFlag;              // used to be called DmgBonusType;
/*0x018c*/ BYTE                ElementalDamage;            // used to be called DmgBonusVal
/*0x018d*/ BYTE                Range;
/*0x0190*/ DWORD               Damage;                     // BaseDamage
/*0x0194*/ DWORD               BackstabDamage;
/*0x0198*/ DWORD               HeroicSTR;
/*0x019c*/ DWORD               HeroicINT;                  // 883A30 jun 11 2018 test
/*0x01a0*/ DWORD               HeroicWIS;                  // 883A90 jun 11 2018 test
/*0x01a4*/ DWORD               HeroicAGI;                  // 8839D0 jun 11 2018 test
/*0x01a8*/ DWORD               HeroicDEX;
/*0x01ac*/ DWORD               HeroicSTA;                  // 883A50 jun 11 2018 test
/*0x01b0*/ DWORD               HeroicCHA;                  // 8839F0 jun 11 2018 test
/*0x01b4*/ DWORD               HealAmount;                 // 883980 jun 11 2018 test
/*0x01b8*/ DWORD               SpellDamage;
/*0x01bc*/ int                 MinLuck;
/*0x01c0*/ int                 MaxLuck;
/*0x01c4*/ int                 Prestige;                   // 884816 jun 11 2018 test
/*0x01c8*/ BYTE                ItemType;
/*0x01cc*/ ArmorProperties     ArmorProps;                 // size is 0x14
/*0x01e0*/ ItemSocketData      AugData;
/*0x0210*/ DWORD               AugType;
/*0x0214*/ DWORD               AugSkinTypeMask;
/*0x0218*/ DWORD               AugRestrictions;
/*0x021c*/ DWORD               SolventItemID;              // ID# of Solvent (Augs only)
/*0x0220*/ DWORD               LDTheme;
/*0x0224*/ DWORD               LDCost;
/*0x0228*/ DWORD               LDType;
/*0x022c*/ int                 Unknown0x022c;
/*0x0230*/ int                 Unknown0x0230;
//*0x0228*/ DWORD               FactionModType[0x4];
//*0x0238*/ DWORD               FactionModValue[0x4];
/*0x0234*/ CHAR                CharmFile[0x20];
/*0x0254*/ float               Unknown0x0254;
/*0x0258*/ ITEMSPELLS          Clicky;                     // size 0x64
/*0x02BC*/ ITEMSPELLS          Proc;
/*0x0320*/ ITEMSPELLS          Worn;
/*0x0384*/ ITEMSPELLS          Focus;
/*0x03E8*/ ITEMSPELLS          Scroll;
/*0x044C*/ ITEMSPELLS          Focus2;
/*0x04B0*/ ITEMSPELLS          Mount;
/*0x0514*/ ITEMSPELLS          Illusion;
/*0x0578*/ ITEMSPELLS          Familiar;
/*0x05dc*/ DWORD               SkillMask[5];               // this is just an array but I dont have time to figure it out for now.
/*0x05f0*/ DWORD               DmgBonusSkill;              // SkillMinDamageMod;
/*0x05f4*/ DWORD               DmgBonusValue;              // MinDamageMod;
/*0x05f8*/ DWORD               CharmFileID;
/*0x05fc*/ DWORD               FoodDuration;               // 0-5 snack 6-20 meal 21-30 hearty 31-40 banquet 41-50 feast 51-60 enduring 60- miraculous
/*0x0600*/ BYTE                Combine;
/*0x0601*/ BYTE                Slots;
/*0x0602*/ BYTE                SizeCapacity;
/*0x0603*/ BYTE                WeightReduction;
/*0x0604*/ BYTE                BookType;                   // 0=note, !0=book 884CF5 jun 11 2018 test
/*0x0605*/ BYTE                BookLang;
/*0x0606*/ CHAR                BookFile[0x1e];
/*0x0624*/ DWORD               Favor;                      // Tribute Value
/*0x0628*/ DWORD               GuildFavor;
/*0x062c*/ bool                bIsFVNoDrop;
/*0x0630*/ DWORD               Endurance;
/*0x0634*/ DWORD               Attack;
/*0x0638*/ DWORD               HPRegen;
/*0x063c*/ DWORD               ManaRegen;
/*0x0640*/ DWORD               EnduranceRegen;
/*0x0644*/ DWORD               Haste;
/*0x0648*/ int                 AnimationOverride;
/*0x064c*/ int                 PaletteTintIndex;
/*0x0650*/ bool                bNoPetGive;
/*0x0651*/ bool                bSomeProfile;
/*0x0654*/ int                 SomeIDFlag;
/*0x0658*/ DWORD               StackSize;
/*0x065c*/ bool                bNoStorage;
/*0x0660*/ DWORD               MaxPower;
/*0x0664*/ DWORD               Purity;
/*0x0668*/ bool                bIsEpic;
/*0x066c*/ int                 RightClickScriptID;
/*0x0670*/ int                 ItemLaunchScriptID;
/*0x0674*/ BYTE                QuestItem;
/*0x0675*/ BYTE                Expendable;
/*0x0678*/ DWORD               Clairvoyance;
/*0x067c*/ int                 SubClass;
/*0x0680*/ bool                bLoginRegReqItem;
/*0x0684*/ DWORD               Placeable;
/*0x0688*/ bool                bPlaceableIgnoreCollisions;
/*0x068c*/ int                 PlacementType;              // todo: this is an enum need to figure out.
/*0x0690*/ int                 RealEstateDefID;
/*0x0694*/ float               PlaceableScaleRangeMin;
/*0x0698*/ float               PlaceableScaleRangeMax;
/*0x069c*/ int                 RealEstateUpkeepID;
/*0x06a0*/ int                 MaxPerRealEstate;
/*0x06a4*/ char                HousepetFileName[0x20];
/*0x06c4*/ int                 TrophyBenefitID;
/*0x06c8*/ bool                bDisablePlacementRotation;
/*0x06c9*/ bool                bDisableFreePlacement;
/*0x06cc*/ int                 NpcRespawnInterval;
/*0x06d0*/ float               PlaceableDefScale;
/*0x06d4*/ float               PlaceableDefHeading;
/*0x06d8*/ float               PlaceableDefPitch;
/*0x06dc*/ float               PlaceableDefRoll;
/*0x06e0*/ bool                bInteractiveObject;
/*0x06e1*/ uint8_t             SocketSubClassCount;
/*0x06e4*/ int                 SocketSubClass[0xa];
/*0x070c*/
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

class ItemArray
{
public:
/*0xa4*/ ITEMBASEARRAY* pItems;
/*0xa8*/ unsigned int   Size;
/*0xac*/ unsigned int   Capacity;
};

class ItemBaseContainer2
{
public:
/*0x9c*/ unsigned int ContentSize;
/*0xa0*/ int          ItemLocation;
/*0xa4*/ ItemArray    ContainedItems;
/*0xb0*/ BYTE         Depth;
/*0xB2*/ short        ItemSlot;
/*0xB4*/ short        ItemSlot2;
/*0xB6*/ bool         bDynamic;
/*0xb8*/
};

//============================================================================
// ItemBase
//============================================================================

// Actual Size: 0x158 (see 0x611DAC in eqgame.exe Test dated Jun 10 2019)
class ItemBase
{
public:
/*0x0000*/ void* vtable;

// base class member - reference count
/*0x0004*/ mutable int  RefCount;
// base class vftable
/*0x0008*/ void* punknown;

#if defined(TEST)
#include "../test/ItemBase-Members.h"
#elif defined(LIVE)
#include "../live/ItemBase-Members.h"
#endif

	bool IsLore(bool bIncludeSockets = false) const;
	bool IsLoreEquipped(bool bIncludeSockets = false) const;
};

class ItemClient : public ItemBase
{
public:
	///*0x0141*/ BYTE Filler0x0141[0xB];

	// Reference counted pointer to ItemDefinition
/*0x0148*/ DWORD        Item2RefCnt;
/*0x014C*/ ITEMINFO*    Item2;

/*0x0150*/ CXStr        ClientString;
/*0x0158*/

	EQLIB_OBJECT ItemClient* GetContent(uint32_t index);
	EQLIB_OBJECT ItemGlobalIndex GetGlobalIndex() const;
};

//============================================================================
// CONTENTS
// This is ItemClient/ItemBase
//============================================================================

// Actual Size: 0x158 (see 0x610D4C in eqgame.exe Test dated May 17 2019) - eqmule
 struct CONTENTS {
/*0x0000*/ void*             vtable;
/*0x0004*/ int               RefCount;
/*0x0008*/ void*             unknown;

	// start of ItemBase
#if defined(TEST)
#include "../test/ItemBase-Members.h"
#elif defined(LIVE)
#include "../live/ItemBase-Members.h"
#endif

	//start of ItemClient
/*0x0141*/ uint8_t           Filler0x0141[0xB];
/*0x014C*/ ITEMINFO*         Item2;
/*0x0150*/ CXStr             ClientString;
/*0x0154*/ uint8_t           Filler0x0154[0x4];

EQLIB_OBJECT CONTENTS* GetContent(unsigned int index);
EQLIB_OBJECT ItemGlobalIndex GetGlobalIndex();
};
using PCONTENTS [[deprecated]] = CONTENTS*;


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
};

// 20101012 - ieatacid
struct INVENTORY
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
/*0x5c*/ CONTENTS* Pack[0xa];
/*0x84*/ CONTENTS* Cursor;
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

//added dec 08 2014
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

template <typename TItem>
class ItemContainer
{
public:
	/*0x00*/ UINT Size;
	/*0x04*/ int Spec;
	/*0x08*/ VeArray<VePointer<TItem>> Items;
	/*0x0c*/ BYTE AtDepth;
	/*0x10*/ short Slots[2];
	/*0x14*/ bool bDynamic;
	/*0x18*/
};

class ItemBaseContainer : public ItemContainer<CONTENTS>
{
public:
};

// offsets are relative to their position in LAUNCHSPELLDATA
struct ITEMLOCATION
{
/*0x0c*/ ItemContainerInstance Location [[deprecated("Use ItemGlobalIndex")]] ;
/*0x10*/ short InvSlot [[deprecated("Use ItemGlobalIndex")]] ;
/*0x12*/ short BagSlot [[deprecated("Use ItemGlobalIndex")]] ;
/*0x14*/ short AugSlot [[deprecated("Use ItemGlobalIndex")]] ;
/*0x16*/
};
using PITEMLOCATION [[deprecated("Use ItemGlobalIndex")]] = ITEMLOCATION*;


} // namespace eqlib

using namespace eqlib;