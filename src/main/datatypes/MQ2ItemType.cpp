#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2ItemType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CONTENTS* pItem = static_cast<CONTENTS*>(VarPtr.Ptr);
	if (!pItem)
		return false;

	PITEMINFO pItemInfo = GetItemFromContents(pItem);
	if (!pItemInfo)
		return false;

	MQTypeMember* pMember = MQ2ItemType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ItemMembers>(pMember->ID))
	{
	case ID:
		Dest.DWord = GetItemFromContents(pItem)->ItemNumber;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, GetItemFromContents(pItem)->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Lore:
		Dest.DWord = ((ItemBase*)pItem)->IsLore(false);
		Dest.Type = pBoolType;
		return true;
	case LoreEquipped:
		Dest.DWord = ((ItemBase*)pItem)->IsLoreEquipped(false);
		Dest.Type = pBoolType;
		return true;

	case NoDrop:
	case NoTrade:
		Dest.DWord = !((EQ_Item*)pItem)->CanDrop(0, 1);
		Dest.Type = pBoolType;
		return true;

	case NoRent:
		Dest.DWord = !GetItemFromContents(pItem)->NoRent;
		Dest.Type = pBoolType;
		return true;

	case Magic:
		Dest.DWord = ((GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL) && (GetItemFromContents(pItem)->Magic));
		Dest.Type = pBoolType;
		return true;

	case Value:
		Dest.DWord = GetItemFromContents(pItem)->Cost;
		Dest.Type = pIntType;
		return true;

	case Size:
		Dest.DWord = GetItemFromContents(pItem)->Size;
		Dest.Type = pIntType;
		return true;

	case SizeCapacity:
		Dest.DWord = GetItemFromContents(pItem)->SizeCapacity;
		Dest.Type = pIntType;
		return true;

	case Weight:
		Dest.DWord = GetItemFromContents(pItem)->Weight;
		Dest.Type = pIntType;
		return true;

	case Stack:
		if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) || (((EQ_Item*)pItem)->IsStackable() != 1))
			Dest.DWord = 1;
		else
			Dest.DWord = pItem->StackCount;
		Dest.Type = pIntType;
		return true;

	case Type:
		DataTypeTemp[0] = '\0';
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL)
		{
			if ((GetItemFromContents(pItem)->ItemType < MAX_ITEMTYPES) && (szItemTypes[GetItemFromContents(pItem)->ItemType] != nullptr))
			{
				strcpy_s(DataTypeTemp, szItemTypes[GetItemFromContents(pItem)->ItemType]);
			}
			else
			{
				sprintf_s(DataTypeTemp, "*UnknownType%d", GetItemFromContents(pItem)->ItemType);
			}
		}
		else if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			if ((GetItemFromContents(pItem)->Combine < MAX_COMBINES) && (szCombineTypes[GetItemFromContents(pItem)->Combine] != nullptr))
			{
				strcpy_s(DataTypeTemp, szCombineTypes[GetItemFromContents(pItem)->Combine]);
			}
			else
			{
				sprintf_s(DataTypeTemp, "*UnknownCombine%d", GetItemFromContents(pItem)->Combine);
			}
		}
		else if (GetItemFromContents(pItem)->Type == ITEMTYPE_BOOK)
		{
			strcpy_s(DataTypeTemp, "Book");
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Charges:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->Charges;
		Dest.Type = pIntType;
		return true;

	case LDoNTheme:
		strcpy_s(DataTypeTemp, GetLDoNTheme(GetItemFromContents(pItem)->LDTheme));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

		// we go to keep this for backward compatibility
		// but really it should be called case ElementalFlag:
	case DMGBonusType:
		strcpy_s(DataTypeTemp, szDmgBonusType[GetItemFromContents(pItem)->ElementalFlag]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Container:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			Dest.DWord = GetItemFromContents(pItem)->Slots;
		}
		return true;

	case Open:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			Dest.DWord = pItem->Open;
		}
		return true;

	case Items:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			if (pItem->Contents.ContainedItems.pItems) {
				for (unsigned long N = 0; N < GetItemFromContents(pItem)->Slots; N++) {
					if (pItem->GetContent(N))
						Dest.DWord++;
				}
			}
			return true;
		}
		return false;

	case Clicky:
		Dest.Ptr = &GetItemFromContents(pItem)->Clicky;
		Dest.Type = pItemSpellType;
		return true;

	case Proc:
		Dest.Ptr = &GetItemFromContents(pItem)->Proc;
		Dest.Type = pItemSpellType;
		return true;

	case Worn:
		Dest.Ptr = &GetItemFromContents(pItem)->Worn;
		Dest.Type = pItemSpellType;
		return true;

	case Focus:
		Dest.Ptr = &GetItemFromContents(pItem)->Focus;
		Dest.Type = pItemSpellType;
		return true;

	case Scroll:
		Dest.Ptr = &GetItemFromContents(pItem)->Scroll;
		Dest.Type = pItemSpellType;
		return true;

	case Focus2:
		Dest.Ptr = &GetItemFromContents(pItem)->Focus2;
		Dest.Type = pItemSpellType;
		return true;

	case Mount:
		Dest.Ptr = &GetItemFromContents(pItem)->Mount;
		Dest.Type = pItemSpellType;
		return true;

	case Illusion:
		Dest.Ptr = &GetItemFromContents(pItem)->Illusion;
		Dest.Type = pItemSpellType;
		return true;

	case Familiar:
		Dest.Ptr = &GetItemFromContents(pItem)->Familiar;
		Dest.Type = pItemSpellType;
		return true;

	case Item: {
		Dest.Type = pItemType;
		CONTENTS* pCont = (CONTENTS*)pItem;

		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK && IsNumber(Index))
		{
			// FIXME:  Add some safety checks here for bad conversion
			int num = GetIntFromString(Index, 1) - 1;
			if (num < GetItemFromContents(pItem)->Slots)
			{
				if (pItem->Contents.ContainedItems.pItems)
				{
					if (Dest.Ptr = pItem->GetContent(num))
					{
						return true;
					}
				}
			}
		}
		else if (GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL && IsNumber(Index))
		{
			// FIXME:  Add some safety checks here for bad conversion
			int num = GetIntFromString(Index, 1) - 1;
			Dest.Ptr = nullptr;

			if (pItem->Contents.ContainedItems.pItems)
			{
				if (GetItemFromContents(pItem)->AugData.Sockets[num].Type)
					Dest.Ptr = pItem->Contents.ContainedItems.pItems->Item[num];
			}

			if (Dest.Ptr)
				return true;
		}
		return false;
	}
	case Stackable:
		Dest.DWord = ((EQ_Item*)pItem)->IsStackable();
		Dest.Type = pBoolType;
		return true;

	case InvSlot:
		Dest.Int = FindInvSlotForContents(pItem);
		if (Dest.Int >= 0)
		{
			Dest.Type = pInvSlotType;
			return true;
		}
		return false;

	case ItemSlot:
		Dest.Int = pItem->GetGlobalIndex().GetIndex().GetSlot(0);
		Dest.Type = pIntType;
		return true;

	case ItemSlot2:
		Dest.Int = pItem->GetGlobalIndex().GetIndex().GetSlot(1);
		Dest.Type = pIntType;
		return true;

	case BuyPrice:
		Dest.Int64 = 0;
		Dest.Type = pInt64Type;
		if (pActiveMerchant && pItem->MerchantSlot)
		{
			Dest.Int64 = pItem->Price;
			return true;
		}
		return false;

	case SellPrice:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pActiveMerchant)
		{
			Dest.DWord = static_cast<int>(
				static_cast<float>(GetItemFromContents(pItem)->Cost) * (1.0f / pMerchantWnd->MerchantGreed));
			return true;
		}
		return false;

	case WornSlot:
		Dest.DWord = 0;
		Dest.Type = pInvSlotType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count)
					return false;

				int cmp = GetItemFromContents(pItem)->EquipSlots;
				for (int num = 0; num < 32; num++)
				{
					if (cmp & (1 << num))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = num;
							Dest.Type = pInvSlotType;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				uint32_t nInvSlot = ItemSlotMap[Index];
				if ((nInvSlot || !_stricmp(Index, "charm")) && nInvSlot < 32)
				{
					Dest.DWord = (GetItemFromContents(pItem)->EquipSlots & (1 << nInvSlot));
					Dest.Type = pBoolType;
					return true;
				}
			}
		}
		return false;

	case WornSlots: {
		Dest.DWord = 0;

		// count bits
		int cmp = GetItemFromContents(pItem)->EquipSlots;
		for (int num = 0; num < 32; num++)
		{
			if (cmp & (1 << num))
				Dest.DWord++;
		}
		Dest.Type = pIntType;
		return true;
	}

	case CastTime:
		Dest.UInt64 = GetItemFromContents(pItem)->Clicky.CastTime;
		Dest.Type = pTimeStampType;
		return true;

	case Spell:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Clicky.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Scroll.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Proc.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Focus.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Worn.SpellID))
			return true;
		return false;

	case EffectType:
		Dest.Type = pStringType;
		// 0 Proc
		// 1 Clickable from inventory (any class)
		// 2 Worn effect (haste, cleave)
		// 3 Unknown
		// 4 Clickable must be worn
		// 5 Clickable from inventory (class restricted)
		// 6 Focus effect
		// 7 Memmable spell scroll

		// This used to return an int type with a case statment, items could have
		// only one effect. For backwards compatibility we return based on a hierarchy.
		// A zero in any field indicates no effect (others will also be zero)
		if (!GetItemFromContents(pItem)->Clicky.SpellID)
		{
			return false;
		}
		else if (GetItemFromContents(pItem)->Scroll.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Spell Scroll");
		}
		else if (GetItemFromContents(pItem)->Clicky.SpellID != -1)
		{
			// code to detect must-be-worn etc here
			switch (GetItemFromContents(pItem)->Clicky.EffectType)
			{
			case ItemEffectClickyWorn:
				strcpy_s(DataTypeTemp, "Click Worn");
				break;
			case ItemEffectClicky:
			case ItemEffectClickyRestricted:
				strcpy_s(DataTypeTemp, "Click Inventory");
				break;
			default:
				strcpy_s(DataTypeTemp, "Click Unknown");
				break;
			}
		}
		else if (GetItemFromContents(pItem)->Focus.SpellID != -1 || GetItemFromContents(pItem)->Worn.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Worn");
		}
		else if (GetItemFromContents(pItem)->Proc.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Combat");
		}
		else
		{
			return false;
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case InstrumentMod:
		Dest.Float = ((float)GetItemFromContents(pItem)->InstrumentMod) / 10.0f;
		Dest.Type = pFloatType;
		return true;

	case Tribute:
		Dest.DWord = GetItemFromContents(pItem)->Favor;
		Dest.Type = pIntType;
		return true;

	case Attuneable:
		Dest.DWord = GetItemFromContents(pItem)->Attuneable;
		Dest.Type = pBoolType;
		return true;

	case Timer:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (GetItemFromContents(pItem)->Clicky.TimerID != -1)
		{
			Dest.DWord = (GetItemTimer(pItem) + 5) / 6;
			return true;
		}
		if (GetItemFromContents(pItem)->Clicky.SpellID != -1)
		{
			Dest.DWord = 0; // insta-clicky
			return true;
		}
		return false;

	case Damage:
		Dest.DWord = GetItemFromContents(pItem)->Damage;
		Dest.Type = pIntType;
		return true;

	case ItemDelay:
		Dest.DWord = GetItemFromContents(pItem)->Delay;
		Dest.Type = pIntType;
		return true;

	case TimerReady:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Clicky.TimerID != -1)
		{
			Dest.DWord = GetItemTimer(pItem);
			return true;
		}
		if (GetItemFromContents(pItem)->Clicky.SpellID != -1)
		{
			Dest.DWord = 0; // insta-click or instant recast
			return true;
		}
		return false;

	case StackSize:
		// This returns the MAX size of a stack for the item
		// If this was properly named it should be called MaxStack.
		Dest.DWord = 1; //we know its at least 1
		Dest.Type = pIntType;

		if (pItem)
		{
			if ((pItem->GetItemDefinition()->Type == ITEMTYPE_NORMAL) && (((EQ_Item*)pItem)->IsStackable()))
			{
				Dest.DWord = pItem->GetItemDefinition()->StackSize;
			}
		}
		return true;

	case Stacks:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (PcProfile* pProfile = GetPcProfile())
		{
			if (!((EQ_Item*)pItem)->IsStackable())
				return true;

			for (int slot = BAG_SLOT_START; slot < NUM_INV_SLOTS; slot++)
			{
				if (pProfile->pInventoryArray && pProfile->pInventoryArray->InventoryArray[slot])
				{
					if (CONTENTS* pTempItem = pProfile->pInventoryArray->InventoryArray[slot])
					{
						if (GetItemFromContents(pTempItem)->Type == ITEMTYPE_PACK && pTempItem->Contents.ContainedItems.pItems)
						{
							for (int pslot = 0; pslot < (GetItemFromContents(pTempItem)->Slots); pslot++)
							{
								if (pTempItem->Contents.ContainedItems.pItems->Item[pslot])
								{
									if (CONTENTS* pSlotItem = pTempItem->Contents.ContainedItems.pItems->Item[pslot])
									{
										if (GetItemFromContents(pSlotItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
										{
											Dest.DWord++;
										}
									}
								}
							}
						}
						else
						{
							if (GetItemFromContents(pTempItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
							{
								Dest.DWord++;
							}
						}
					}
				}
			}
		}
		return true;

	case StackCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (PcProfile* pProfile = GetPcProfile())
		{
			if (!((EQ_Item*)pItem)->IsStackable())
				return true;

			for (int slot = BAG_SLOT_START; slot < NUM_INV_SLOTS; slot++)
			{
				if (pProfile->pInventoryArray && pProfile->pInventoryArray->InventoryArray[slot])
				{
					if (CONTENTS* pTempItem = pProfile->pInventoryArray->InventoryArray[slot])
					{
						if (GetItemFromContents(pTempItem)->Type == ITEMTYPE_PACK && pTempItem->Contents.ContainedItems.pItems)
						{
							for (int pslot = 0; pslot < (GetItemFromContents(pTempItem)->Slots); pslot++)
							{
								if (pTempItem->Contents.ContainedItems.pItems->Item[pslot])
								{
									if (CONTENTS* pSlotItem = pTempItem->Contents.ContainedItems.pItems->Item[pslot])
									{
										if (GetItemFromContents(pSlotItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
										{
											Dest.DWord += pSlotItem->StackCount;
										}
									}
								}
							}
						}
						else
						{
							if (GetItemFromContents(pTempItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
							{
								Dest.DWord += pTempItem->StackCount;
							}
						}
					}
				}
			}
		}
		return true;

	case FreeStack:
		Dest.DWord = GetFreeStack(pItem);
		Dest.Type = pIntType;
		return true;

	case MerchQuantity:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pActiveMerchant && pItem->MerchantSlot)
		{
			Dest.DWord = pItem->MerchantQuantity;
			return true;
		}
		return false;

	case Classes: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		// count bits
		int cmp = GetItemFromContents(pItem)->Classes;
		for (int num = 0; num < TotalPlayerClasses; num++)
		{
			if (cmp & (1 << num))
				Dest.DWord++;
		}
		return true;
	}

	case Class:
		Dest.DWord = 0;
		Dest.Type = pClassType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count)
					return false;

				int cmp = GetItemFromContents(pItem)->Classes;
				for (int num = 0; num < TotalPlayerClasses; num++)
				{
					if (cmp & (1 << num))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = num + 1;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				int cmp = GetItemFromContents(pItem)->Classes;
				for (int num = 0; num < TotalPlayerClasses; num++)
				{
					if (cmp & (1 << num))
					{
						if (!_stricmp(Index, GetClassDesc(num + 1))
							|| !_stricmp(Index, pEverQuest->GetClassThreeLetterCode(num + 1)))
						{
							Dest.DWord = num + 1;
							return true;
						}
					}
				}
				return false;
			}
		}
		return false;

	case Races: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		// count bits
		int cmp = GetItemFromContents(pItem)->Races;
		for (int num = 0; num < NUM_RACES; num++)
		{
			if (cmp & (1 << num))
				Dest.DWord++;
		}
		return true;
	}

	case Race:
		Dest.DWord = 0;
		Dest.Type = pRaceType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count)
					return false;

				int cmp = GetItemFromContents(pItem)->Races;
				for (int num = 0; num < NUM_RACES; num++)
				{
					if (cmp & (1 << num))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = num + 1;
							switch (num)
							{
							case 12:
								Dest.DWord = 128;   // IKS
								break;
							case 13:
								Dest.DWord = 130;   // VAH
								break;
							case 14:
								Dest.DWord = 330;   // FRG
								break;
							case 15:
								Dest.DWord = 522;   // DRK
								break;
							}
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				int cmp = GetItemFromContents(pItem)->Races;
				for (int num = 0; num < NUM_RACES; num++)
				{
					if (cmp & (1 << num))
					{
						int tmp = num + 1;
						switch (num)
						{
						case 12:
							tmp = 128;   // IKS
							break;
						case 13:
							tmp = 130;   // VAH
							break;
						case 14:
							tmp = 330;   // FRG
							break;
						case 15:
							tmp = 522;   // DRK
							break;
						}

						if (!_stricmp(Index, pEverQuest->GetRaceDesc(tmp)))
						{
							Dest.DWord = tmp;
							return true;
						}
					}
				}
				return false;
			}
		}
		return false;

	case Deities: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		// count bits
		int cmp = GetItemFromContents(pItem)->Diety;
		for (int num = 0; num < NUM_DEITIES; num++)
		{
			if (cmp & (1 << num))
				Dest.DWord++;
		}
		return true;
	}

	case Deity:
		Dest.DWord = 0;
		Dest.Type = pDeityType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count)
					return false;
				int cmp = GetItemFromContents(pItem)->Diety;
				for (int num = 0; num < NUM_DEITIES; num++)
				{
					if (cmp & (1 << num))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = num + 200;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				int cmp = GetItemFromContents(pItem)->Diety;
				for (int num = 0; num < NUM_DEITIES; num++)
				{
					if (cmp & (1 << num))
					{
						if (!_stricmp(Index, pEverQuest->GetDeityDesc(num + 200)))
						{
							Dest.DWord = num + 200;
							return true;
						}
					}
				}
				return false;
			}
		}
		return false;

	case RequiredLevel:
		Dest.DWord = GetItemFromContents(pItem)->RequiredLevel;
		Dest.Type = pIntType;
		return true;

	case SkillModValue:
		Dest.DWord = GetItemFromContents(pItem)->SkillModValue;
		Dest.Type = pIntType;
		return true;

	case SkillModMax:
		Dest.DWord = GetItemFromContents(pItem)->SkillModMax;
		Dest.Type = pIntType;
		return true;

	case Evolving:
		Dest.Ptr = pItem;
		Dest.Type = pEvolvingItemType;
		return true;

	case AC:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AC;
		Dest.Type = pIntType;
		return true;

	case HP:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HP;
		Dest.Type = pIntType;
		return true;

	case STR:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->STR;
		Dest.Type = pIntType;
		return true;

	case STA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->STA;
		Dest.Type = pIntType;
		return true;

	case AGI:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AGI;
		Dest.Type = pIntType;
		return true;

	case DEX:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->DEX;
		Dest.Type = pIntType;
		return true;

	case CHA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->CHA;
		Dest.Type = pIntType;
		return true;

	case INT:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->INT;
		Dest.Type = pIntType;
		return true;

	case WIS:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->WIS;
		Dest.Type = pIntType;
		return true;

	case Mana:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Mana;
		Dest.Type = pIntType;
		return true;

	case ManaRegen:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->ManaRegen;
		Dest.Type = pIntType;
		return true;

	case HPRegen:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HPRegen;
		Dest.Type = pIntType;
		return true;

	case Endurance:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Endurance;
		Dest.Type = pIntType;
		return true;

	case Attack:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Attack;
		Dest.Type = pIntType;
		return true;

	case svCold:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvCold;
		Dest.Type = pIntType;
		return true;

	case svFire:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvFire;
		Dest.Type = pIntType;
		return true;

	case svMagic:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvMagic;
		Dest.Type = pIntType;
		return true;

	case svDisease:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvDisease;
		Dest.Type = pIntType;
		return true;

	case svPoison:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvPoison;
		Dest.Type = pIntType;
		return true;

	case svCorruption:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvCorruption;
		Dest.Type = pIntType;
		return true;

	case Haste:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Haste;
		Dest.Type = pIntType;
		return true;

	case DamShield:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case AugType:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugType;
		Dest.Type = pIntType;
		return true;

	case AugRestrictions:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugRestrictions;
		Dest.Type = pIntType;
		return true;

	case AugSlot:
		Dest.DWord = 0;
		Dest.Type = pAugType;
		if (IsNumber(Index))
		{
			if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			{
				Dest.DWord = 0;
			}
			else
			{
				int index = std::clamp(GetIntFromString(Index, 0), 0, 5);
				Dest.DWord = index;
				Dest.HighPart = (LONG)pItem;
			}
			return true;
		}
		return false;

	case AugSlot1:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[0].Type;
		Dest.Type = pIntType;
		return true;

	case AugSlot2:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[1].Type;
		Dest.Type = pIntType;
		return true;

	case AugSlot3:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[2].Type;
		Dest.Type = pIntType;
		return true;

	case AugSlot4:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[3].Type;
		Dest.Type = pIntType;
		return true;

	case AugSlot5:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[4].Type;
		Dest.Type = pIntType;
		return true;

	case AugSlot6:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[5].Type;
		Dest.Type = pIntType;
		return true;

	case Power:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->Power;
		Dest.Type = pIntType;
		return true;

	case PctPower:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
		{
			Dest.Float = 0;
		}
		else
		{
			if (int maxpower = GetItemFromContents(pItem)->MaxPower)
			{
				Dest.Float = (float)((pItem->Power * 100) / maxpower);
			}
			else
			{
				Dest.Float = 0;
			}
		}
		Dest.Type = pFloatType;
		return true;

	case MaxPower:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) {
			Dest.DWord = 0;
		}
		else {
			Dest.DWord = GetItemFromContents(pItem)->MaxPower;
		}
		Dest.Type = pIntType;
		return true;

	case Purity:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Purity;
		Dest.Type = pIntType;
		return true;

	case Range:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Range;
		Dest.Type = pIntType;
		return true;

	case Avoidance:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case SpellShield:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case StrikeThrough:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case StunResist:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case Shielding:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case Accuracy:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case CombatEffects:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case DoTShielding:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case HeroicSTR:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSTR;
		Dest.Type = pIntType;
		return true;

	case HeroicINT:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicINT;
		Dest.Type = pIntType;
		return true;

	case HeroicWIS:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicWIS;
		Dest.Type = pIntType;
		return true;

	case HeroicAGI:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicAGI;
		Dest.Type = pIntType;
		return true;

	case HeroicDEX:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicDEX;
		Dest.Type = pIntType;
		return true;

	case HeroicSTA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSTA;
		Dest.Type = pIntType;
		return true;

	case HeroicCHA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicCHA;
		Dest.Type = pIntType;
		return true;

	case EnduranceRegen:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->EnduranceRegen;
		Dest.Type = pIntType;
		return true;

	case HealAmount:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HealAmount;
		Dest.Type = pIntType;
		return true;

	case Clairvoyance:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Clairvoyance;
		Dest.Type = pIntType;
		return true;

	case DamageShieldMitigation:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case SpellDamage:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				Dest.DWord = pII->SpellDamage;
			}
		}
		Dest.Type = pIntType;
		return true;

	case Augs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ITEMINFO* pitem = GetItemFromContents(pItem))
		{
			if (pitem->Type == ITEMTYPE_NORMAL)
			{
				for (int i = 0; i < MAX_AUG_SOCKETS; ++i)
				{
					if (pitem->AugData.Sockets[i].Type > 0 && pitem->AugData.Sockets[i].Type < 20 && pitem->AugData.Sockets[i].bVisible)
						Dest.DWord++;
				}

				Dest.Type = pIntType;
			}
		}
		return true;

	case Tradeskills:
		Dest.DWord = GetItemFromContents(pItem)->TradeSkills;
		Dest.Type = pBoolType;
		return true;

	case Address:
		Dest.DWord = (DWORD)GetItemFromContents(pItem);
		Dest.Type = pIntType;
		return true;

	case ContAddress:
		Dest.DWord = (DWORD)pItem;
		Dest.Type = pIntType;
		return true;

	case Prestige:
		Dest.DWord = GetItemFromContents(pItem)->Prestige;
		Dest.Type = pBoolType;
		return true;

	case FirstFreeSlot: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		CONTENTS* pTheCont = pItem;
		if (ITEMINFO* pTheItem = GetItemFromContents(pItem))
		{
			if (pTheItem->Type == ITEMTYPE_PACK || (pTheItem->Type == ITEMTYPE_NORMAL && pTheCont->Item1)) //a worldcontainer has its item in Item1
			{
				Dest.DWord = -1;
				if (pTheCont->Contents.ContainedItems.pItems)
				{
					for (int num = 0; num < pTheItem->Slots; num++)
					{
						if (!pTheCont->Contents.ContainedItems.pItems->Item[num])
						{
							Dest.DWord = num;
							break;
						}
					}
				}
				return true;
			}
		}
		return false;
	}

	case SlotsUsedByItem:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;
		CONTENTS* pTheCont = pItem;
		if (ITEMINFO* pTheItem = GetItemFromContents(pItem))
		{
			if (pTheItem->Type == ITEMTYPE_PACK || (pTheItem->Type == ITEMTYPE_NORMAL && pTheCont->Item1))
			{
				Dest.DWord = 0;
				bool bExact = false;
				char* pName1 = Index;
				if (*pName1 == '=')
				{
					bExact = true;
					pName1++;
				}

				if (pTheCont->Contents.ContainedItems.pItems)
				{
					for (int nSlot = 0; nSlot < pTheItem->Slots; nSlot++)
					{
						if (pTheCont->Contents.ContainedItems.pItems->Item[nSlot])
						{
							if (ITEMINFO* bagitem = GetItemFromContents(pTheCont->Contents.ContainedItems.pItems->Item[nSlot]))
							{
								if (bExact)
								{
									if (ci_equals(bagitem->Name, pName1))
									{
										Dest.DWord++;
									}
								}
								else
								{
									if (ci_find_substr(bagitem->Name, pName1) != -1)
									{
										Dest.DWord++;
									}
								}
							}
						}
					}
					return true;
				}
			}
		}
		return false;
	}

	case Heirloom:
		Dest.DWord = GetItemFromContents(pItem)->Heirloom;
		Dest.Type = pBoolType;
		return true;

	case Collectible:
		Dest.DWord = GetItemFromContents(pItem)->Collectible;
		Dest.Type = pBoolType;
		return true;

	case NoDestroy:
		Dest.DWord = GetItemFromContents(pItem)->NoDestroy;
		Dest.Type = pBoolType;
		return true;

	case Quest:
		Dest.DWord = GetItemFromContents(pItem)->QuestItem;
		Dest.Type = pBoolType;
		return true;

	case Expendable:
		Dest.DWord = GetItemFromContents(pItem)->Expendable;
		Dest.Type = pBoolType;
		return true;

	case ItemLink:
		Dest.Type = pStringType;
		if (GetItemLink(pItem, DataTypeTemp, false))
		{
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Icon:
		Dest.DWord = GetItemFromContents(pItem)->IconNumber;
		Dest.Type = pIntType;
		return true;

	case OrnamentationIcon:
		Dest.DWord = pItem->OrnamentationIcon;
		Dest.Type = pIntType;
		return true;

	case ContentSize:
		Dest.DWord = pItem->Contents.ContentSize;
		Dest.Type = pIntType;
		return true;

	case CanUse:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (CONTENTS* pCont = pItem)
		{
			Dest.DWord = pCharData->CanUseItem(&pCont, false, false);
			return true;
		}
		return false;

	case Luck:
		Dest.DWord = pItem->Luck;
		Dest.Type = pIntType;
		return true;

	case MinLuck:
		Dest.DWord = GetItemFromContents(pItem)->MinLuck;
		Dest.Type = pIntType;
		return true;

	case MaxLuck:
		Dest.DWord = GetItemFromContents(pItem)->MaxLuck;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2ItemType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!VarPtr.Ptr)
		return false;

	CONTENTS* pContents = static_cast<CONTENTS*>(VarPtr.Ptr);
	strcpy_s(Destination, MAX_STRING, GetItemFromContents(pContents)->Name);
	return true;
}

