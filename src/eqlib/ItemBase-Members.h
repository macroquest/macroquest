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

/*0x00c*/ int                      RealEstateID;
/*0x010*/ CXStr                    ConvertItemName;
/*0x014*/ int                      AugFlag;
/*0x018*/ int                      Power;
/*0x020*/ int64_t                  MerchantSlot;
/*0x028*/ int                      NoDropFlag;
/*0x02c*/ int                      MerchantQuantity;
/*0x030*/ double                   EvolvingExpPct;
/*0x038*/ int                      ConvertItemID;
/*0x03c*/ long                     LastEquipped;
/*0x040*/ char                     ActorTag2[0x1e];
/*0x060*/ ArrayClass<uint32_t>     RealEstateArray;
/*0x070*/ int                      ID;
/*0x074*/ int                      EvolvingMaxLevel;
/*0x078*/ int                      Luck;
/*0x07c*/ CXStr                    SaveString;
/*0x080*/ int                      GroupID;
/*0x084*/ int                      StackCount;
/*0x088*/ int                      ScriptIndex;
/*0x08c*/ bool                     bItemNeedsUpdate;
/*0x08d*/ bool                     bRealEstateItemPlaceable;
/*0x090*/ int                      EvolvingCurrentLevel;
/*0x094*/ int                      Open;
/*0x098*/ char                     ActorTag1[0x1e];
/*0x0b8*/ int                      NoteStatus;
/*0x0bc*/ bool                     bCollected;
/*0x0c0*/ unsigned int             LastCastTime;
/*0x0c4*/ ItemGlobalIndex          GlobalIndex;                 // Size is 0xa (0xc)
/*0x0d0*/ ITEMINFO*                Item1;
/*0x0d4*/ unsigned int             RespawnTime;
/*0x0d8*/ bool                     bRankDisabled;
/*0x0dc*/ int                      ItemColor;
/*0x0e0*/ int64_t                  Price;
/*0x0e8*/ int                      OrnamentationIcon;
/*0x0ec*/ bool                     bCopied;
/*0x0f0*/ unsigned int             NewArmorID;
/*0x0f4*/ bool                     bConvertable;
/*0x0f8*/ unsigned int             Tint;
/*0x0fc*/ int                      Charges;
/*0x100*/ EqItemGuid               ItemGUID;
/*0x112*/ bool                     IsEvolvingItem;
/*0x114*/ unsigned int             ItemHash;
/*0x118*/ int64_t                  DontKnow;
/*0x120*/ ItemBaseContainer2       Contents;                    // Size is 0x1c
/*0x13c*/ int                      ArmorType;
/*0x140*/ bool                     bDisableAugTexture;
