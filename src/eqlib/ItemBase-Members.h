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

/*0x00c*/ ItemGlobalIndex          GlobalIndex;                 // Size is 0xa (0xc)
/*0x018*/ int                      NoDropFlag;
/*0x01c*/ bool                     bCopied;
/*0x01d*/ bool                     bRankDisabled;
/*0x020*/ int                      ItemColor;
/*0x024*/ char                     ActorTag1[0x1e];
/*0x042*/ bool                     bRealEstateItemPlaceable;
/*0x043*/ bool                     IsEvolvingItem;
/*0x044*/ int                      RealEstateID;
/*0x048*/ int                      Charges;
/*0x04c*/ bool                     bDisableAugTexture;
/*0x050*/ int                      OrnamentationIcon;
/*0x054*/ unsigned int             RespawnTime;
/*0x058*/ EqItemGuid               ItemGUID;
/*0x06c*/ int                      EvolvingMaxLevel;
/*0x070*/ int                      StackCount;
/*0x074*/ CXStr                    ConvertItemName;
/*0x078*/ int                      EvolvingCurrentLevel;
/*0x07c*/ int                      ArmorType;
/*0x080*/ int64_t                  Price;
/*0x088*/ int64_t                  DontKnow;
/*0x090*/ int                      GroupID;
/*0x098*/ double                   EvolvingExpPct;
/*0x0a0*/ int                      NoteStatus;
/*0x0a4*/ int                      MerchantQuantity;
/*0x0a8*/ int                      Power;
/*0x0ac*/ CXStr                    SaveString;
/*0x0b0*/ long                     LastEquipped;
/*0x0b4*/ int                      ID;
/*0x0b8*/ bool                     bConvertable;
/*0x0bc*/ ItemBaseContainer2       Contents;                    // Size is 0x1c
/*0x0d8*/ bool                     bCollected;
/*0x0dc*/ int                      Open;
/*0x0e0*/ int64_t                  MerchantSlot;
/*0x0e8*/ ArrayClass<uint32_t>     RealEstateArray;
/*0x0f8*/ int                      AugFlag;
/*0x0fc*/ unsigned int             Tint;
/*0x100*/ int                      ScriptIndex;
/*0x104*/ ITEMINFO* Item1;
/*0x108*/ unsigned int             LastCastTime;
/*0x10c*/ char                     ActorTag2[0x1e];
/*0x12c*/ int                      ConvertItemID;
/*0x130*/ unsigned int             ItemHash;
/*0x134*/ bool                     bItemNeedsUpdate;
/*0x138*/ int                      Luck;
/*0x13c*/ unsigned int             NewArmorID;
