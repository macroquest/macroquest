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
	/*0x078*/ CXStr              ActorTag2;
	/*0x080*/ int64_t            DontKnow;
	/*0x088*/ bool               bItemNeedsUpdate;
	/*0x08c*/ int                Luck;
	/*0x090*/ CXStr              ConvertItemName;
	/*0x094*/ unsigned int       NewArmorID;
	/*0x098*/ ITEMINFO*          Item1;
	/*0x09c*/ ArrayClass<unsigned int> RealEstateArray;
	/*0x0ac*/ int                OrnamentationIcon;
	/*0x0b0*/ bool               bRealEstateItemPlaceable;
	/*0x0b4*/ unsigned int       LastCastTime;
	/*0x0b8*/ int                Charges;
	/*0x0bc*/ CXStr              SaveString;
	/*0x0c0*/ bool               bCopied;
	/*0x0c4*/ int                Open;
	/*0x0c8*/ int                ArmorType;
	/*0x0cc*/ unsigned int       RespawnTime;
	/*0x0d0*/ ItemBaseContainer2 Contents;                    // Size is 0x1c
	/*0x0ec*/ int                ID;
	/*0x0f0*/ bool               bDisableAugTexture;
	/*0x0f4*/ CXStr              ActorTag1;
	/*0x0f8*/ bool               bRankDisabled;
