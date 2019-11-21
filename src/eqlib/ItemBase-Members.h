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

/*0x00c*/ int                ConvertItemID;
/*0x010*/ int                EvolvingCurrentLevel;
/*0x014*/ int                AugFlag;
/*0x018*/ double             EvolvingExpPct;
/*0x020*/ unsigned int       Tint;
/*0x024*/ bool               bCopied;
/*0x025*/ char               ActorTag1[0x1e];
/*0x044*/ unsigned int       LastCastTime;
/*0x048*/ char               ActorTag2[0x1e];
/*0x068*/ long               LastEquipped;
/*0x06c*/ EqItemGuid         ItemGUID;
/*0x080*/ int                Open;
/*0x084*/ bool               bConvertable;
/*0x088*/ int                StackCount;
/*0x08c*/ int                Luck;
/*0x090*/ ITEMINFO*          Item1;
/*0x094*/ unsigned int       ItemHash;
/*0x098*/ ArrayClass<unsigned int> RealEstateArray;
/*0x0a8*/ int                ID;
/*0x0ac*/ int                NoDropFlag;
/*0x0b0*/ bool               bDisableAugTexture;
/*0x0b4*/ int                NoteStatus;
/*0x0b8*/ unsigned int       NewArmorID;
/*0x0bc*/ bool               bRealEstateItemPlaceable;
/*0x0c0*/ int                ScriptIndex;
/*0x0c4*/ int                EvolvingMaxLevel;
/*0x0c8*/ CXStr              ConvertItemName;
/*0x0cc*/ int                MerchantQuantity;
/*0x0d0*/ int                ArmorType;
/*0x0d8*/ int64_t            MerchantSlot;
/*0x0e0*/ int                ItemColor;
/*0x0e4*/ int                Charges;
/*0x0e8*/ unsigned int       RespawnTime;
/*0x0ec*/ int                OrnamentationIcon;
/*0x0f0*/ bool               bItemNeedsUpdate;
/*0x0f4*/ ItemBaseContainer2 Contents;                    // Size is 0x1c
/*0x110*/ bool               IsEvolvingItem;
/*0x114*/ int                RealEstateID;
/*0x118*/ bool               bRankDisabled;
/*0x11c*/ CXStr              SaveString;
/*0x120*/ int64_t            DontKnow;
/*0x128*/ int                Power;
/*0x12c*/ ItemGlobalIndex    GlobalIndex;                 // Size is 0xa (0xc)
/*0x138*/ int                GroupID;
/*0x140*/ int64_t            Price;
/*0x148*/ bool               bCollected;
