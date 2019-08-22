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

/*0x00c*/ unsigned int       RespawnTime;
/*0x010*/ int                NoteStatus;
/*0x014*/ bool               bCollected;
/*0x018*/ int                Luck;
/*0x01c*/ int                AugFlag;
/*0x020*/ int                MerchantQuantity;
/*0x024*/ CXStr              SaveString;
/*0x028*/ int                ScriptIndex;
/*0x02c*/ bool               IsEvolvingItem;
/*0x030*/ double             EvolvingExpPct;
/*0x038*/ int                ArmorType;
/*0x03c*/ int                Power;
/*0x040*/ CXStr              ConvertItemName;
/*0x044*/ int                EvolvingCurrentLevel;
/*0x048*/ int                GroupID;
/*0x04c*/ unsigned int       LastCastTime;
/*0x050*/ int                Open;
/*0x054*/ char               ActorTag2[0x1e];
/*0x078*/ int64_t            MerchantSlot;
/*0x080*/ bool               bCopied;
/*0x081*/ bool               bRealEstateItemPlaceable;
/*0x088*/ int64_t            Price;
/*0x090*/ unsigned int       ItemHash;
/*0x094*/ int                RealEstateID;
/*0x098*/ int                StackCount;
/*0x09c*/ bool               bItemNeedsUpdate;
/*0x0a0*/ int                ConvertItemID;
/*0x0a4*/ int                NoDropFlag;
/*0x0a8*/ int                ID;
/*0x0ac*/ EqItemGuid         ItemGUID;
/*0x0be*/ bool               bConvertable;
/*0x0bf*/ bool               bDisableAugTexture;
/*0x0c0*/ int                Charges;
/*0x0c4*/ int                ItemColor;
/*0x0c8*/ unsigned int       NewArmorID;
/*0x0cc*/ char               ActorTag1[0x1e];
/*0x0ec*/ ArrayClass<unsigned int> RealEstateArray;
/*0x0fc*/ unsigned int       Tint;
/*0x100*/ ItemBaseContainer2 Contents;                    // Size is 0x1c
/*0x11c*/ long               LastEquipped;
/*0x120*/ int64_t            DontKnow;
/*0x128*/ bool               bRankDisabled;
/*0x12c*/ int                OrnamentationIcon;
/*0x130*/ int                EvolvingMaxLevel;
/*0x134*/ ITEMINFO*          Item1;
/*0x138*/ ItemGlobalIndex    GlobalIndex;                 // Size is 0xa (0xc)
