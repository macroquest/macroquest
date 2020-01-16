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

	/*0x00c*/ unsigned int       ItemHash;
	/*0x010*/ int64_t            MerchantSlot;
	/*0x018*/ int64_t            Price;
	/*0x020*/ bool               bConvertable;
	/*0x024*/ int                NoteStatus;
	/*0x028*/ int                StackCount;
	/*0x02c*/ int                RealEstateID;
	/*0x030*/ int                AugFlag;
	/*0x034*/ ItemGlobalIndex    GlobalIndex;                 // Size is 0xa (0xc)
	/*0x040*/ int                ScriptIndex;
	/*0x044*/ unsigned int       Tint;
	/*0x048*/ EqItemGuid         ItemGUID;
	/*0x05c*/ int                MerchantQuantity;
	/*0x060*/ bool               bCollected;
	/*0x064*/ ItemEvolutionDataPtr pEvolutionData;
	/*0x06c*/ int                ConvertItemID;
	/*0x070*/ int                NoDropFlag;
	/*0x074*/ int                Power;
	/*0x078*/ char               ActorTag2[0x1e];
	/*0x098*/ int64_t            DontKnow;
	/*0x0a0*/ bool               bItemNeedsUpdate;
	/*0x0a4*/ int                Luck;
	/*0x0a8*/ CXStr              ConvertItemName;
	/*0x0ac*/ unsigned int       NewArmorID;
	/*0x0b0*/ ITEMINFO*          Item1;
	/*0x0b4*/ ArrayClass<unsigned int> RealEstateArray;
	/*0x0c4*/ int                OrnamentationIcon;
	/*0x0c8*/ bool               bRealEstateItemPlaceable;
	/*0x0cc*/ unsigned int       LastCastTime;
	/*0x0d0*/ int                Charges;
	/*0x0d4*/ CXStr              SaveString;
	/*0x0d8*/ bool               bCopied;
	/*0x0dc*/ int                Open;
	/*0x0e0*/ int                ArmorType;
	/*0x0e4*/ unsigned int       RespawnTime;
	/*0x0e8*/ ItemBaseContainer2 Contents;                    // Size is 0x1c
	/*0x104*/ int                ID;
	/*0x108*/ bool               bDisableAugTexture;
	/*0x109*/ char               ActorTag1[0x1e];
	/*0x127*/ bool               bRankDisabled;
