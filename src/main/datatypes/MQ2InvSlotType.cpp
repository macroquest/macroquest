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

#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

// item slots:
// 2000-2015 bank window
// 2500-2503 shared bank
// 5000-5031 loot window
// 3000-3015 trade window (including npc) 3000-3007 are your slots, 3008-3015 are other character's slots
// 4000-4010 world container window
// 6000-6080 merchant window
// 7000-7080 bazaar window
// 8000-8031 inspect window
bool MQ2InvSlotType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2InvSlotType::FindMember(Member);
	if (!pMember)
		return false;

	int nInvSlot = VarPtr.Int;

	switch (static_cast<InvSlotMembers>(pMember->ID))
	{
	case ID:
		Dest.DWord = VarPtr.Int;
		Dest.Type = pIntType;
		return true;

	case Item:
		Dest.Type = pItemType;
		if (PcProfile* pProfile = GetPcProfile())
		{
			if (pProfile->pInventoryArray && nInvSlot >= 0)
			{
				if (nInvSlot < NUM_INV_SLOTS)
				{
					if (Dest.Ptr = pProfile->pInventoryArray->InventoryArray[nInvSlot])
					{
						return true;
					}
				}
				else
				{
					if (CHARINFO* pCharInfo = GetCharInfo())
					{
						if (nInvSlot >= 262 && nInvSlot < 342)
						{
							int nPack = (nInvSlot - 262) / 10;
							int nSlot = (nInvSlot - 262) % 10;

							if (CONTENTS* pPack = pProfile->pInventoryArray->Inventory.Pack[nPack])
							{
								if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && nSlot < GetItemFromContents(pPack)->Slots)
								{
									if (pPack->Contents.ContainedItems.pItems)
									{
										if (Dest.Ptr = pPack->Contents.ContainedItems.pItems->Item[nSlot])
										{
											return true;
										}
									}
								}
							}
						}
						else if (nInvSlot >= 2032 && nInvSlot < 2272)
						{
							unsigned long nPack = (nInvSlot - 2032) / 10;
							unsigned long nSlot = (nInvSlot - 2) % 10;
							CONTENTS* pPack = nullptr;

							if (pCharInfo && pCharInfo->pBankArray)
								pPack = pCharInfo->pBankArray->Bank[nPack];

							if (pPack)
							{
								if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && nSlot < GetItemFromContents(pPack)->Slots)
								{
									if (pPack->Contents.ContainedItems.pItems)
									{
										if (Dest.Ptr = pPack->Contents.ContainedItems.pItems->Item[nSlot])
										{
											return true;
										}
									}
								}
							}
						}
						else if (nInvSlot >= 2532 && nInvSlot < 2552)
						{
							unsigned long nPack = 23 + ((nInvSlot - 2532) / 10);
							unsigned long nSlot = (nInvSlot - 2) % 10;
							CONTENTS* pPack = nullptr;

							if (pCharInfo && pCharInfo->pBankArray)
								pPack = pCharInfo->pBankArray->Bank[nPack];

							if (pPack)
							{
								if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && nSlot < GetItemFromContents(pPack)->Slots)
								{
									if (pPack->Contents.ContainedItems.pItems)
									{
										if (Dest.Ptr = pPack->Contents.ContainedItems.pItems->Item[nSlot])
										{
											return true;
										}
									}
								}
							}
						}
						else if (nInvSlot >= 2000 && nInvSlot < 2024)
						{
							if (pCharInfo && pCharInfo->pBankArray)
							{
								if (Dest.Ptr = pCharInfo->pBankArray->Bank[nInvSlot - 2000])
								{
									return true;
								}
							}
						}
						else if (nInvSlot == 2500 || nInvSlot == 2501)
						{
							if (pCharInfo && pCharInfo->pBankArray)
							{
								if (Dest.Ptr = pCharInfo->pBankArray->Bank[nInvSlot - 2500 + 22])
								{
									if (Dest.Ptr)
									{
										return true;
									}
								}
							}
						}
						else if (nInvSlot > 2999 && nInvSlot < 3016)
						{
							CInvSlotWnd* pInvSlotWnd = nullptr;

							if (pGiveWnd && pGiveWnd->IsVisible())
							{
								int slot = std::min(nInvSlot - 3000, MAX_GIVE_SLOTS);
								if (slot >= MAX_TRADE_SLOTS)
									slot = 0;

								pInvSlotWnd = pGiveWnd->pInvSlotWnd[slot];
							}
							else if (pTradeWnd && pTradeWnd->IsVisible())
							{
								int slot = std::min(nInvSlot - 3000, MAX_TRADE_SLOTS);
								if (slot >= MAX_TRADE_SLOTS)
									slot = 0;

								pInvSlotWnd = pTradeWnd->pInvSlotWnd[slot];
							}

							if (pInvSlotWnd)
							{
								if (CInvSlot* pInvSlot = pInvSlotWnd->pInvSlot)
								{
									CONTENTS* pC = nullptr;
									pInvSlot->GetItemBase(&pC);
									if (pC)
									{
										Dest.Ptr = pC;
										return true;
									}
								}
							}
						}
						else if (nInvSlot > 3999 && nInvSlot < 4011) // enviro slots
						{
							if (pContainerMgr)
							{
								uint32_t index = nInvSlot - 4000;
								if (CONTENTS* pContents = pContainerMgr->pWorldContainer.get())
								{
									if (index < pContents->Contents.ContainedItems.Size
										&& pContents->Contents.ContainedItems.pItems)
									{
										Dest.Ptr = pContents->Contents.ContainedItems.pItems->Item[index];
										return true;
									}
								}
							}
						}
						else if (nInvSlot == 4100) // enviro
						{
							if ( pContainerMgr)
							{
								if (pContainerMgr->pWorldContainer)
								{
									Dest.Ptr = pContainerMgr->pWorldContainer.get();
									return true;
								}
							}
						}
					}
				}
			}
		}
		return false;

	case Pack:
		Dest.DWord = 0;
		Dest.Type = pInvSlotType;
		if (nInvSlot >= 262 && nInvSlot < 342)
		{
			Dest.DWord = ((nInvSlot - 262) / 10) + BAG_SLOT_START;
			return true;
		}

		if (nInvSlot >= 2032 && nInvSlot < 2272)
		{
			Dest.DWord = ((nInvSlot - 2032) / 10) + 2000;
			return true;
		}

		if (nInvSlot >= 2532 && nInvSlot < 2552)
		{
			Dest.DWord = ((nInvSlot - 2532) / 10) + 2500;
			return true;
		}
		return false;

	case Slot:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (nInvSlot >= 262 && nInvSlot < 342)
		{
			Dest.DWord = (nInvSlot - 262) % 10;
			return true;
		}

		if (nInvSlot >= 2032 && nInvSlot < 2272)
		{
			Dest.DWord = (nInvSlot - 2032) % 10;
			return true;
		}

		if (nInvSlot >= 2532 && nInvSlot < 2552)
		{
			Dest.DWord = (nInvSlot - 2532) % 10;
			return true;
		}
		return false;

	case Name:
		Dest.Type = pStringType;
		if (nInvSlot >= 0 && nInvSlot < NUM_INV_SLOTS)
		{
			strcpy_s(DataTypeTemp, szItemSlot[nInvSlot]);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= BAG_SLOT_START && nInvSlot < NUM_INV_SLOTS)
		{
			sprintf_s(DataTypeTemp, "pack%d", nInvSlot - 21);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 2000 && nInvSlot < 2024)
		{
			sprintf_s(DataTypeTemp, "bank%d", nInvSlot - 1999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 2500 && nInvSlot < 2502)
		{
			sprintf_s(DataTypeTemp, "sharedbank%d", nInvSlot - 2499);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 5000 && nInvSlot < 5032)
		{
			sprintf_s(DataTypeTemp, "loot%d", nInvSlot - 4999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 3000 && nInvSlot < 3009)
		{
			sprintf_s(DataTypeTemp, "trade%d", nInvSlot - 2999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 4000 && nInvSlot < 4009)
		{
			sprintf_s(DataTypeTemp, "enviro%d", nInvSlot - 3999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot == 4100) // its the worldcontainer
		{
			if (pContainerMgr)
			{
				if (ITEMINFO* pItemInfo = pContainerMgr->pWorldContainer->GetItemDefinition())
				{
					strcpy_s(DataTypeTemp, pItemInfo->Name);
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}

			return false;
		}

		if (nInvSlot >= 6000 && nInvSlot < 6080)
		{
			sprintf_s(DataTypeTemp, "merchant%d", nInvSlot - 5999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 7000 && nInvSlot < 7089)
		{
			sprintf_s(DataTypeTemp, "bazaar%d", nInvSlot - 6999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}

		if (nInvSlot >= 8000 && nInvSlot < 8031)
		{
			sprintf_s(DataTypeTemp, "inspect%d", nInvSlot - 7999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

