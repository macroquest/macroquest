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

/*0x00c*/ ITEMINFO*          Item1;
/*0x010*/ int                Luck;
/*0x014*/ ArrayClass<unsigned int> RealEstateArray;
/*0x024*/ int                Open;
/*0x028*/ int                RealEstateID;
/*0x02c*/ unsigned int       Tint;
/*0x030*/ ItemBaseContainer2 Contents;                    // Size is 0x1c
/*0x04c*/ int                NoDropFlag;
/*0x050*/ char               ActorTag1[0x1e];
/*0x06e*/ bool               bCopied;
/*0x06f*/ char               ActorTag2[0x1e];
/*0x090*/ int64_t            DontKnow;
/*0x098*/ bool               bDisableAugTexture;
/*0x09c*/ int                EvolvingMaxLevel;
/*0x0a0*/ unsigned int       RespawnTime;
/*0x0a4*/ int                ConvertItemID;
/*0x0a8*/ double             EvolvingExpPct;
/*0x0b0*/ bool               bRankDisabled;
/*0x0b8*/ int64_t            Price;
/*0x0c0*/ CXStr              SaveString;
/*0x0c4*/ int                ID;
/*0x0c8*/ unsigned int       NewArmorID;
/*0x0cc*/ int                Power;
/*0x0d0*/ int                ArmorType;
/*0x0d4*/ int                OrnamentationIcon;
/*0x0d8*/ unsigned int       LastCastTime;
/*0x0dc*/ EqItemGuid         ItemGUID;
/*0x0ee*/ bool               bConvertable;
/*0x0f0*/ int                MerchantQuantity;
/*0x0f4*/ int                GroupID;
/*0x0f8*/ int                StackCount;
/*0x0fc*/ unsigned int       ItemHash;
/*0x100*/ bool               IsEvolvingItem;
/*0x104*/ long               LastEquipped;
/*0x108*/ ItemGlobalIndex    GlobalIndex;                 // Size is 0xa (0xc)
/*0x114*/ bool               bItemNeedsUpdate;
/*0x115*/ bool               bRealEstateItemPlaceable;
/*0x118*/ int                AugFlag;
/*0x11c*/ int                NoteStatus;
/*0x120*/ CXStr              ConvertItemName;
/*0x128*/ int64_t            MerchantSlot;
/*0x130*/ int                Charges;
/*0x134*/ int                ItemColor;
/*0x138*/ int                ScriptIndex;
/*0x13c*/ int                EvolvingCurrentLevel;
/*0x140*/ bool               bCollected;
