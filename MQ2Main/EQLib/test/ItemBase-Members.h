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

	ITEMINFO*   Item1;
	int         Luck;
	ArrayClass_RO<UINT> RealEstateArray;
	int         Open;
	int         RealEstateID;
	UINT        Tint;
	ItemBaseContainer2 Contents;                     // Size is 0x1c
	int         NoDropFlag;
	CHAR        ActorTag1[0x1e];
	bool        bCopied;
	CHAR        ActorTag2[0x1e];
	int64_t     DontKnow;
	bool        bDisableAugTexture;
	int         EvolvingMaxLevel;
	UINT        RespawnTime;
	int         ConvertItemID;
	double      EvolvingExpPct;
	bool        bRankDisabled;
	int64_t     Price;
	CXStr       SaveString;
	int         ID;
	UINT        NewArmorID;
	int         Power;
	int         ArmorType;
	int         OrnamentationIcon;
	UINT        LastCastTime;
	EqItemGuid  ItemGUID;
	bool        bConvertable;
	int         MerchantQuantity;
	int         GroupID;
	int         StackCount;
	UINT        ItemHash;
	bool        IsEvolvingItem;
	LONG        LastEquipped;
	ItemGlobalIndex GlobalIndex;                    // Size is 0xa (0xc)
	bool        bItemNeedsUpdate;
	bool        bRealEstateItemPlaceable;
	int         AugFlag;
	int         NoteStatus;
	CXStr       ConvertItemName;
	int64_t     MerchantSlot;
	int         Charges;
	int         ItemColor;
	int         ScriptIndex;
	int         EvolvingCurrentLevel;
	bool        bCollected;
