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

/*0x10c*/ unsigned int       RespawnTime;
/*0x148*/ int                NoteStatus;
/*0x0bc*/ bool               bCollected;
/*0x098*/ int                Luck;
/*0x0f8*/ int                AugFlag;
/*0x140*/ int                MerchantQuantity;
/*0x010*/ CXStr              SaveString;
/*0x110*/ int                ScriptIndex;
/*0x138*/ bool               IsEvolvingItem;
/*0x130*/ double             EvolvingExpPct;
/*0x0b4*/ int                ArmorType;
/*0x014*/ int                Power;
/*0x00c*/ CXStr              ConvertItemName;
/*0x038*/ int                EvolvingCurrentLevel;
/*0x0dc*/ int                GroupID;
/*0x0b8*/ unsigned int       LastCastTime;
/*0x13c*/ int                Open;
/*0x0bd*/ char               ActorTag2[0x1e];
/*0x128*/ int64_t            MerchantSlot;
/*0x120*/ bool               bCopied;
/*0x0ec*/ bool               bRealEstateItemPlaceable;
/*0x118*/ int64_t            Price;
/*0x104*/ unsigned int       ItemHash;
/*0x108*/ int                RealEstateID;
/*0x090*/ int                StackCount;
/*0x064*/ bool               bItemNeedsUpdate;
/*0x144*/ int                ConvertItemID;
/*0x0f0*/ int                NoDropFlag;
/*0x050*/ int                ID;
/*0x09c*/ EqItemGuid         ItemGUID;
/*0x100*/ bool               bConvertable;
/*0x0f4*/ bool               bDisableAugTexture;
/*0x048*/ int                Charges;
/*0x124*/ int                ItemColor;
/*0x0e8*/ unsigned int       NewArmorID;
/*0x018*/ char               ActorTag1[0x1e];
/*0x054*/ ArrayClass<unsigned int> RealEstateArray;
/*0x0e0*/ unsigned int       Tint;
/*0x068*/ ItemBaseContainer2 Contents;                    // Size is 0x1c
/*0x0fc*/ long               LastEquipped;
/*0x040*/ int64_t            DontKnow;
/*0x094*/ bool               bRankDisabled;
/*0x04c*/ int                OrnamentationIcon;
/*0x0b0*/ int                EvolvingMaxLevel;
/*0x0e4*/ ITEMINFO*          Item1;
/*0x084*/ ItemGlobalIndex    GlobalIndex;                 // Size is 0xa (0xc)
