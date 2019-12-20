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

/*0x00c*/ EqItemGuid         ItemGUID;
/*0x020*/ int                AugFlag;
/*0x024*/ int                Luck;
/*0x028*/ bool               bConvertable;
/*0x02c*/ CXStr              ConvertItemName;
/*0x030*/ int                Power;
/*0x038*/ double             EvolvingExpPct;
/*0x040*/ unsigned int       Tint;
/*0x044*/ ItemGlobalIndex    GlobalIndex;                 // Size is 0xa (0xc)
/*0x050*/ int                ScriptIndex;
/*0x054*/ ITEMINFO*          Item1;
/*0x058*/ int                EvolvingMaxLevel;
/*0x05c*/ int                Charges;
/*0x060*/ bool               IsEvolvingItem;
/*0x064*/ unsigned int       RespawnTime;
/*0x068*/ int                ConvertItemID;
/*0x06c*/ bool               bItemNeedsUpdate;
/*0x070*/ int                EvolvingCurrentLevel;
/*0x074*/ unsigned int       ItemHash;
/*0x078*/ ItemBaseContainer2 Contents;                    // Size is 0x1c
/*0x094*/ int                NoteStatus;
/*0x098*/ unsigned int       LastCastTime;
/*0x09c*/ int                GroupID;
/*0x0a0*/ int                StackCount;
/*0x0a4*/ int                NoDropFlag;
/*0x0a8*/ unsigned int       NewArmorID;
/*0x0ac*/ int                MerchantQuantity;
/*0x0b0*/ int                Open;
/*0x0b4*/ bool               bCollected;
/*0x0b8*/ int64_t            MerchantSlot;
/*0x0c0*/ int                ItemColor;
/*0x0c4*/ char               ActorTag2[0x1e];
/*0x0e2*/ char               ActorTag1[0x1e];
/*0x100*/ long               LastEquipped;
/*0x104*/ bool               bRealEstateItemPlaceable;
/*0x108*/ int                OrnamentationIcon;
/*0x10c*/ int                ID;
/*0x110*/ bool               bDisableAugTexture;
/*0x114*/ int                ArmorType;
/*0x118*/ bool               bCopied;
/*0x11c*/ int                RealEstateID;
/*0x120*/ int64_t            Price;
/*0x128*/ CXStr              SaveString;
/*0x130*/ int64_t            DontKnow;
/*0x138*/ ArrayClass<unsigned int> RealEstateArray;
/*0x148*/ bool               bRankDisabled;
