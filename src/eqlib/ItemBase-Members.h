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

/*0x00c*/ bool               bConvertable;
/*0x00d*/ bool               bCollected;
/*0x010*/ int                NoDropFlag;
/*0x014*/ int                OrnamentationIcon;
/*0x018*/ unsigned int       LastCastTime;
/*0x01c*/ bool               bItemNeedsUpdate;
/*0x020*/ int                Charges;
/*0x024*/ int                ConvertItemID;
/*0x028*/ unsigned int       RespawnTime;
/*0x02c*/ bool               bRankDisabled;
/*0x030*/ int                ArmorType;
/*0x034*/ int                ID;
/*0x038*/ unsigned int       NewArmorID;
/*0x03c*/ int                EvolvingMaxLevel;
/*0x040*/ int                ScriptIndex;
/*0x044*/ long               LastEquipped;
/*0x048*/ int                ItemColor;
/*0x04c*/ CXStr              SaveString;
/*0x050*/ int64_t            DontKnow;
/*0x058*/ ItemGlobalIndex    GlobalIndex;                 // Size is 0xa (0xc)
/*0x064*/ int                NoteStatus;
/*0x068*/ bool               IsEvolvingItem;
/*0x06c*/ int                AugFlag;
/*0x070*/ double             EvolvingExpPct;
/*0x078*/ int64_t            MerchantSlot;
/*0x080*/ CXStr              ConvertItemName;
/*0x084*/ char               ActorTag1[0x1e];
/*0x0a4*/ unsigned int       ItemHash;
/*0x0a8*/ EqItemGuid         ItemGUID;
/*0x0bc*/ ArrayClass<unsigned int> RealEstateArray;
/*0x0cc*/ ItemBaseContainer2 Contents;                    // Size is 0x1c
/*0x0e8*/ int                Open;
/*0x0ec*/ int                GroupID;
/*0x0f0*/ int                StackCount;
/*0x0f4*/ int                EvolvingCurrentLevel;
/*0x0f8*/ unsigned int       Tint;
/*0x0fc*/ int                MerchantQuantity;
/*0x100*/ int64_t            Price;
/*0x108*/ int                Luck;
/*0x10c*/ bool               bDisableAugTexture;
/*0x110*/ ITEMINFO*          Item1;
/*0x114*/ bool               bCopied;
/*0x118*/ int                Power;
/*0x11c*/ bool               bRealEstateItemPlaceable;
/*0x120*/ int                RealEstateID;
/*0x124*/ char               ActorTag2[0x1e];
