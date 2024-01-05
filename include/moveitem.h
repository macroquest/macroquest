/*********************************************************************************/
/* moveitem.h by pms - item find and move functions centralized in a single file */
/* last update  - 2011-0415                                                      */
/* release      - 2010-1103                                                      */
// edited by: woobs 01/20/2014
//    Removed MQ2BagWindow dependency.
//    Removed EQINVSLOT type references.
//    Removed Item swapping routines.
/*********************************************************************************/

#define INVALID_PACK -1

// CItemLocation class is returned from functions
class CItemLocation
{
public:
	short InvSlot = 0;              // main inventory slot (with or without a pack)
	short BagSlot = INVALID_PACK;   // slot inside of the pack at InvSlot, 0xFFFF when not a bag
	ItemClient* pInvSlot = nullptr; // ItemClient* of the main inventory slot
	ItemClient* pBagSlot = nullptr; // ItemClient* of the bag slot inside of pInvSlot
	ItemClient* pItem = nullptr;    // ItemClient* of an item, regardless of where it is
};

/*********************************************************************************/
// generic inlines commonly used by most plugins that handle items

#define NOID -1

inline bool TypePack(ItemClient* Item)
{
	return Item && Item->IsContainer();
}

inline bool ItemIsStackable(ItemClient* Item)
{
	return Item && Item->IsStackable();
}

inline bool StackHasRoom(ItemClient* Item)
{
	return Item && Item->IsStackable() && Item->GetItemCount() < Item->GetMaxItemCount();
}

// cannot move items when casting. SOE has detection on this.
// returns true if a class other than bard is casting.
bool NonBardCasting()
{
	return pLocalPlayer && pLocalPlayer->GetClass() != Bard && pLocalPlayer->CastingData.SpellETA != 0;
}

inline bool IsCasting()
{
	return pLocalPlayer && pLocalPlayer->CastingData.SpellID != -1;
}

inline bool AbilityInUse()
{
	return pLocalPlayer && pLocalPlayer->CastingData.SpellETA != 0;
}

// returns true if there is something on the cursor
inline bool CursorHasItem()
{
	return GetPcProfile()->GetInventorySlot(InvSlot_Cursor) != nullptr;
}

/*********************************************************************************/
// ItemFind is called by passing the address of a new instance of CItemLocation
// and either the item number or item name in a string to support args such as
//       /exchange 1234 slot   OR    /exchange "my item" slot
// If the item is found, ItemFind fills in your CItemLocation instance with data.
// If the item is not found, it will return a NULL pointer so you know to halt.
//
// Example:
// CItemLocation FindThisItem;
// if (!ItemFind(&FindThisItem, szArg2)) // the item was not found, halt code
// else // item was found, proceed

CItemLocation* ItemFind(CItemLocation* pItemFound, char* pcItemName, unsigned short usMin = 0, unsigned short usInvSlots = NUM_INV_SLOTS);
// we prototype the third and fourth args to search from 0 to 33 (worn, inv, and cursor) by default. you can change this to search
// only bags by calling ItemFind() with usMin starting point BAG_SLOT_START -- ItemFind(&FindThisItem, szArg2, BAG_SLOT_START)

CItemLocation* ItemFind(CItemLocation* pItemFound, char* pcItemName, unsigned short usMin, unsigned short usInvSlots)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile) return nullptr;

	unsigned short usSlot = 0;
	int iIsNum = IsNumber(pcItemName);
	int iItemID = atoi(pcItemName);

	// loop through inv slots & worn slots
	for (usSlot = usMin; usSlot < usInvSlots; usSlot++)
	{
		if (ItemClient* pItem2 = pProfile->GetInventorySlot(usSlot))
		{
			if ((iIsNum && iItemID == pItem2->GetID()) || (!iIsNum && !_stricmp(pcItemName, pItem2->GetName())))
			{
				pItemFound->InvSlot = pItem2->GetItemLocation().GetTopSlot();
				pItemFound->BagSlot = -1;
				pItemFound->pInvSlot = pItem2;
				pItemFound->pBagSlot = pItem2;
				pItemFound->pItem = pItem2;
				return pItemFound;
			}
			// else if there is a non-empty bag in this slot
			if (pItem2->IsContainer())
			{
				for (const ItemPtr& pBagSlot : pItem2->GetHeldItems())
				{
					if (pBagSlot)
					{
						if ((iIsNum && iItemID == pBagSlot->GetID()) || (!iIsNum && !_stricmp(pcItemName, pBagSlot->GetName())))
						{
							pItemFound->InvSlot = pItem2->GetItemLocation().GetTopSlot();
							pItemFound->BagSlot = pBagSlot->GetItemLocation().GetSlot(1);
							pItemFound->pInvSlot = pItem2;
							pItemFound->pBagSlot = pBagSlot.get();
							pItemFound->pItem = pBagSlot.get();
							return pItemFound;
						}
					}
				}
			}
		}
	}
	return nullptr;
}

/*********************************************************************************/
// SlotFind is called with a string containing an MQ-defined slot or slot number.
// This function returns the slot number as a long, if it is found, or -1 if not found.
// Useful for validating user-supplied destinations such as /exchange __ mainhand
// where they to use /exchange __ primary, the -1 return of SlotFind indicates invalid argument.
//
// Example
// char mainhand[] = "mainhand";
// long MainHandIndex = SlotFind(mainhand)
// if (MainHandIndex < 0) // slot not found, halt code

long SlotFind(char* pcSlotID)
{
	long lSlotNum = 0;
	if (IsNumber(pcSlotID)) {
		lSlotNum = atoi(pcSlotID);
		// if the slot provided is a worn or main inventory slot, excludes old "magic numbers" for packs
		if (lSlotNum >= 0 && lSlotNum < NUM_INV_SLOTS) return lSlotNum;
	} else {
		for (lSlotNum = 0; szItemSlot[lSlotNum]; lSlotNum++) {
			if (!_stricmp(pcSlotID, szItemSlot[lSlotNum])) return lSlotNum;
		}
	}
	// mq slot was not found by name or number
	return NOID;
}

/*********************************************************************************/
// Count item cycles through all inventory and returns a count of items.
// pcItemName is a string that either contains the item name or item ID to be compared.
// Return will be your count as unsigned long, adjusted if found, 0 if not.

inline int CountItemByID(int ulID, int usMin = 0, int usInvSlots = NUM_INV_SLOTS);
// We prototype the args to search from 0 to 33 (worn, inv, and cursor) by default. You can change this to search
// only bags by calling CountItem() with usMin starting point BAG_SLOT_START.

// counts by item name
inline int CountItemByName(const char* pcItemName, unsigned short usMin = 0, unsigned short usInvSlots = NUM_INV_SLOTS)
{
	return FindInventoryItemCountByName(pcItemName, StringMatchType::CaseInsensitive, usMin, usInvSlots);
}

inline int CountItemByID(int ulID, int usMin, int usInvSlots)
{
	return FindInventoryItemCountByID(ulID, usMin, usInvSlots);
}

// wrapper for string id passing
inline int CountItem(const char* pcItemName, int usMin, int usInvSlots)
{
	if (IsNumber(pcItemName))
	{
		int iItemID = atoi(pcItemName);
		return CountItemByID(iItemID, usMin, usInvSlots);
	}

	return CountItemByName(pcItemName, usMin, usInvSlots);
}

/*********************************************************************************/
// PackFind will fill a CItemLocation passed to it, or NULL if item not found
//

// finds an open slot in a bag that has items (not empty bags)
CItemLocation* PackFind(CItemLocation* pFreeSlot, ItemClient* pUnequipSlot)
{
	unsigned char  ucCurSize = 10;
	unsigned short usSlot    = 0;

	unsigned short usDecrement = 0;

	// no user-specific slot given, find the first free bag slot
	for (usSlot = InvSlot_FirstBagSlot; usSlot <= GetHighestAvailableBagSlot(); usSlot++)
	{
		if (ItemClient* pInvSlot = GetPcProfile()->GetInventorySlot(usSlot))
		{
			ItemDefinition* pItemInfo    = GetItemFromContents(pInvSlot);
			ItemDefinition* pUnequipInfo = GetItemFromContents(pUnequipSlot);

			if (pItemInfo && pUnequipInfo && pInvSlot->IsContainer()
				&& pItemInfo->Combine != 2
				&& pUnequipInfo->Size <= pItemInfo->SizeCapacity)
			{
				ItemClient* pLAST = pInvSlot->GetHeldItem(0);

				unsigned short usPack = 0;
				for (usPack = 0; pInvSlot->GetHeldItems().GetSize(); usPack++) {
					if (!pInvSlot->GetHeldItem(usPack)) {
						//DebugSpewAlways("no pointer at %hu of pack %hu", usPack, usSlot);
						if (pLAST) {
							pFreeSlot->InvSlot   = usSlot;
							pFreeSlot->BagSlot   = usPack;
							pFreeSlot->pBagSlot  = pInvSlot->GetHeldItem(usPack); // will be NULL
							pFreeSlot->pInvSlot  = pInvSlot;
							return pFreeSlot;
						// else first bag slot was empty
						} else {
							usDecrement++;
						}
					} else if (usDecrement) {
						//DebugSpewAlways("pack %hu minus decrement %hu equals %hu", usPack, usDecrement, usPack-usDecrement);
						pFreeSlot->InvSlot    = usSlot;
						pFreeSlot->BagSlot    = usPack;
						pFreeSlot->pBagSlot   = pInvSlot->GetHeldItem(usPack - usDecrement); // will be NULL
						pFreeSlot->pInvSlot   = pInvSlot;
						return pFreeSlot;
					}
					pLAST = pInvSlot->GetHeldItem(usPack);
				}
				usDecrement = 0;
				pLAST = nullptr;
			}
		}
	}
	return nullptr;
}

// searches only main inventory for somewhere to put a pack
// returns slot number if it exists
long FindSlotForPack()
{
	long lSlot = 0;
	for (lSlot = InvSlot_FirstBagSlot; lSlot <= GetHighestAvailableBagSlot(); lSlot++) {
		ItemClient* pInvSlot = GetPcProfile()->GetInventorySlot(lSlot);
		if (!pInvSlot) {
			// main inventory slot is empty
			return lSlot;
		}

		// if there is an item that is not a pack             // if the item is a pack, but the pack is empty, we can swap it
		if (!pInvSlot->IsContainer() || pInvSlot->GetHeldItems().IsEmpty()) {
			return lSlot;
		}
	}
	// no room for another pack
	return NOID;
}

// searches for any available inventory/pack slot -  to use with auto-inventory
// this includes stackable support, does not include main worn
int FreeSlotForItem(ItemClient* pItem)
{
	bool bCheckStack = ItemIsStackable(pItem);

	for (int lSlot = InvSlot_FirstBagSlot; lSlot <= GetHighestAvailableBagSlot(); lSlot++) {
		ItemClient* pInvSlot = GetPcProfile()->GetInventorySlot(lSlot);
		if (!pInvSlot) return lSlot; // free main inv slot, we are done
		ItemDefinition* pItemInfo = GetItemFromContents(pItem);
		ItemDefinition* pSlotInfo = GetItemFromContents(pInvSlot);
		if (pItemInfo && pSlotInfo) {
			if (bCheckStack && pSlotInfo->Type != ITEMTYPE_PACK) { // check for stackable
				if (pItemInfo->ItemNumber == pSlotInfo->ItemNumber && StackHasRoom(pInvSlot)) return NOID; // use autoinventory
			}
			// search through the pack for a free slot
			if (TypePack(pInvSlot) && pItemInfo->Size <= pSlotInfo->SizeCapacity && (pSlotInfo->Combine == ContainerType_Quiver) ? (pItemInfo->ItemType == ItemClass_Arrow) : true) {
				if (pInvSlot->GetHeldItems().IsEmpty()) return NOID; // the pack is empty, use autoinventory
				unsigned short usPack = 0;
				for (usPack = 0; usPack < pSlotInfo->Slots; usPack++) {
					ItemClient* pBagSlot = pInvSlot->GetHeldItem(usPack);
					if (!pBagSlot) return NOID;
					ItemDefinition* pBagInfo = GetItemFromContents(pBagSlot);
					if (bCheckStack && pItemInfo->ItemNumber == pBagInfo->ItemNumber && StackHasRoom(pBagSlot)) return NOID;
					// return if the slot is free or meets stacking requirements
				}
			}
		}
		// if its not stackable to main inventory or in this pack, move on to next slot
	}
	return 0;
}

CItemLocation* FreeItemLocationForItem(CItemLocation* pFreeSlot, ItemClient* pItemClient)
{
	unsigned char  ucCurSize = 10;
	ItemDefinition* pUnequipInfo = pItemClient->GetItemDefinition();

	for (unsigned short usSlot = InvSlot_FirstBagSlot; usSlot <= GetHighestAvailableBagSlot(); usSlot++)
	{
		if (ItemClient* pInvSlot = GetPcProfile()->GetInventorySlot(usSlot))
		{
			ItemDefinition* pItemInfo = pInvSlot->GetItemDefinition();
			if (pItemInfo->ContainerType != ContainerType_Quiver
				&& pInvSlot->IsContainer()
				&& pUnequipInfo->Size <= pItemInfo->SizeCapacity)
			{
				for (unsigned short usPack = 0; usPack < pItemInfo->Slots; usPack++) {
					auto pBagSlot = pInvSlot->GetHeldItem(usPack);
					if (!pBagSlot) {
						pFreeSlot->InvSlot = usSlot;
						pFreeSlot->BagSlot = usPack;
						pFreeSlot->pBagSlot = pBagSlot;
						pFreeSlot->pInvSlot = pInvSlot;
						return pFreeSlot;
					}
				}
			}
		}
		else {
			pFreeSlot->InvSlot = usSlot;
			pFreeSlot->BagSlot = INVALID_PACK;
			pFreeSlot->pBagSlot = nullptr;
			pFreeSlot->pInvSlot = nullptr;
			return pFreeSlot;
		}
	}
	return nullptr;
}