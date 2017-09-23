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
    short InvSlot;    // main inventory slot (with or without a pack)
    short BagSlot;    // slot inside of the pack at InvSlot, 0xFFFF when not a bag
    PCONTENTS      pInvSlot;   // CONTENTS* of the main inventory slot
    PCONTENTS      pBagSlot;   // CONTENTS* of the bag slot inside of pInvSlot
    PCONTENTS      pItem;      // CONTENTS* of an item, regardless of where it is

    CItemLocation()
    {
        InvSlot    = 0;
        BagSlot    = INVALID_PACK;
        pInvSlot   = NULL;
        pBagSlot   = NULL;
        pItem      = NULL;
    }
};

/*********************************************************************************/
// generic inlines commonly used by most plugins that handle items

#define NOID -1

inline bool TypePack(PCONTENTS Item)
{
    PITEMINFO pItemInfo = GetItemFromContents(Item);
    return (Item && pItemInfo && pItemInfo->Type == ITEMTYPE_PACK);
}

inline bool ItemIsStackable(PCONTENTS Item)
{
    PITEMINFO pItemInfo = GetItemFromContents(Item);
    return (Item && pItemInfo && pItemInfo->Type == ITEMTYPE_NORMAL && ((EQ_Item*)Item)->IsStackable());
}

inline long StackHasRoom(PCONTENTS Item)
{
    PITEMINFO pItemInfo = GetItemFromContents(Item);
    return (Item && pItemInfo && pItemInfo->Type == ITEMTYPE_NORMAL && ((EQ_Item*)Item)->IsStackable()) ? pItemInfo->StackSize - Item->StackCount : 0;
}

// cannot move items when casting. SOE has detection on this.
// returns true if a class other than bard is casting.
bool NonBardCasting()
{
    if (!GetCharInfo() || !GetCharInfo2() || !pCharSpawn) return false;
    if (GetCharInfo2()->Class == Bard) return false;
    if (GetCharInfo()->pSpawn && GetCharInfo()->pSpawn->mActorClient.Class == Bard) return false;
    if (((PSPAWNINFO)pCharSpawn)->CastingData.SpellETA) return true;
    return false;
}

inline bool IsCasting()
{
    return (pCharSpawn && ((PSPAWNINFO)pCharSpawn)->CastingData.SpellID != NOID);
}

inline bool AbilityInUse()
{
    if (pCharSpawn && ((PSPAWNINFO)pCharSpawn)->CastingData.SpellETA == 0) return false;
    return true;
}

// returns true if there is something on the cursor
inline bool CursorHasItem()
{
    if (GetCharInfo2()->pInventoryArray->Inventory.Cursor) return true;
    return false;
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
    unsigned short usSlot  = 0;
    int iIsNum  = IsNumber(pcItemName);
    int iItemID = atoi(pcItemName);
    PCHARINFO2 pChar2 = GetCharInfo2();

	if (pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
        // loop through inv slots & worn slots
		for (usSlot = usMin; usSlot < usInvSlots; usSlot++) {
			if (PCONTENTS pItem2 = pChar2->pInventoryArray->InventoryArray[usSlot]) {
				if ((iIsNum && iItemID == GetItemFromContents(pItem2)->ItemNumber) || (!iIsNum && !_stricmp(pcItemName, GetItemFromContents(pItem2)->Name))) {
                    pItemFound->InvSlot   = pItem2->Contents.ItemSlot;
					pItemFound->BagSlot   = -1;
                    pItemFound->pInvSlot  = pItem2;
                    pItemFound->pBagSlot  = pItem2;
					pItemFound->pItem     = pItem2;
                    return pItemFound;
				}
                // else if there is a non-empty bag in this slot
				if (GetItemFromContents(pItem2)->Type==ITEMTYPE_PACK && pItem2->Contents.ContainedItems.pItems) {
					for (unsigned long nItem=0; nItem < GetItemFromContents(pItem2)->Slots; nItem++) {
						if (PCONTENTS pBagSlot = pItem2->Contents.ContainedItems.pItems->Item[nItem]) {
							if ((iIsNum && iItemID == GetItemFromContents(pBagSlot)->ItemNumber) || (!iIsNum && !_stricmp(pcItemName, GetItemFromContents(pBagSlot)->Name))) {
                               pItemFound->InvSlot   = pBagSlot->Contents.ItemSlot;
					           pItemFound->BagSlot   = pBagSlot->Contents.ItemSlot2;
                               pItemFound->pInvSlot  = pItem2;
                               pItemFound->pBagSlot  = pBagSlot;
					           pItemFound->pItem     = pBagSlot;
                               return pItemFound;
                            }
                        }
                    }
                }
			}
        }
    }
    return NULL;
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

unsigned long CountItemByID(unsigned long ulID, unsigned short usMin = 0, unsigned short usInvSlots = NUM_INV_SLOTS);
// We prototype the args to search from 0 to 33 (worn, inv, and cursor) by default. You can change this to search
// only bags by calling CountItem() with usMin starting point BAG_SLOT_START.

// counts by item name
template <unsigned int _Size> unsigned long CountItemByName(CHAR(&pcItemName)[_Size], unsigned short usMin = 0, unsigned short usInvSlots = NUM_INV_SLOTS)
{
    unsigned long  ulCount = 0;
    unsigned short usSlot  = 0;

    // loop through inv slots & worn slots
    for (usSlot = usMin; usSlot < usInvSlots; usSlot++) {
        if (PCONTENTS pInvSlot = GetCharInfo2()->pInventoryArray->InventoryArray[usSlot]) {
            PITEMINFO pItemInfo = GetItemFromContents(pInvSlot);
            if (pItemInfo && !_stricmp(pcItemName, pItemInfo->Name)) {
                if (ItemIsStackable(pInvSlot)) {
                    ulCount += pInvSlot->StackCount; // increment by the size of stack
                } else {
                    ulCount++; // increment by a single item
                }
            // else if there is a non-empty bag in this slot
		    } else if (pItemInfo && TypePack(pInvSlot) && pInvSlot->Contents.ContainedItems.pItems) {
                // cycle through the number of pack slots
                unsigned short usPack = 0;
                for (usPack = 0; usPack < pItemInfo->Slots; usPack++) {
                    if (PCONTENTS pBagSlot = pInvSlot->Contents.ContainedItems.pItems->Item[usPack]) {
                        PITEMINFO pBagInfo = GetItemFromContents(pBagSlot);
                        if (pBagInfo && !_stricmp(pcItemName, pBagInfo->Name)) {
                            if (ItemIsStackable(pBagSlot)) {
                                ulCount += pBagSlot->StackCount; // increment by the size of stack
                            } else {
                                ulCount++; // increment by a single item
                            }
                        }
                    }
                }
            }
        }
    }
    return ulCount;
}

unsigned long CountItemByID(unsigned long ulID, unsigned short usMin, unsigned short usInvSlots)
{
    unsigned long  ulCount = 0;
    unsigned short usSlot  = 0;

    // loop through inv slots & worn slots
    for (usSlot = usMin; usSlot < usInvSlots; usSlot++) {
        if (PCONTENTS pInvSlot = GetCharInfo2()->pInventoryArray->InventoryArray[usSlot]) {
            PITEMINFO pItemInfo = GetItemFromContents(pInvSlot);
            // if item provided by user is an item id and it matches, or item is by name and it matches
            if (pItemInfo && (ulID == pItemInfo->ItemNumber)) {
                if (ItemIsStackable(pInvSlot)) {
                    ulCount += pInvSlot->StackCount; // increment by the size of stack
                } else {
                    ulCount++; // increment by a single item
                }
            // else if there is a non-empty bag in this slot
		    } else if (pItemInfo && TypePack(pInvSlot) && pInvSlot->Contents.ContainedItems.pItems) {
                // cycle through the number of pack slots
                unsigned short usPack = 0;
                for (usPack = 0; usPack < pItemInfo->Slots; usPack++) {
                    if (PCONTENTS pBagSlot = pInvSlot->Contents.ContainedItems.pItems->Item[usPack]) {
                        PITEMINFO pBagInfo = GetItemFromContents(pBagSlot);
                        if (ulID == pBagInfo->ItemNumber) {
                            if (ItemIsStackable(pBagSlot)) {
                                ulCount += pBagSlot->StackCount; // increment by the size of stack
                            } else {
                                ulCount++; // increment by a single item
                            }
                        }
                    }
                }
            }
        }
    }
    return ulCount;
}

// wrapper for string id passing
template <unsigned int _Size>unsigned long CountItem(CHAR(&pcItemName)[_Size], unsigned short usMin, unsigned short usInvSlots)
{
    int iIsNum  = IsNumber(pcItemName);
    int iItemID = atoi(pcItemName);
    if (iIsNum) return CountItemByID((unsigned long)iItemID, usMin, usInvSlots);
    return CountItemByName(pcItemName, usMin, usInvSlots);
}

/*********************************************************************************/
// PackFind will fill a CItemLocation passed to it, or NULL if item not found
//

// finds an open slot in a bag that has items (not empty bags)
CItemLocation* PackFind(CItemLocation* pFreeSlot, PCONTENTS pUnequipSlot)
{
    unsigned char  ucCurSize = 10;
    unsigned short usSlot    = 0;

    unsigned short usDecrement = 0;

    // no user-specific slot given, find the first free bag slot
    for (usSlot = BAG_SLOT_START; usSlot < NUM_INV_SLOTS; usSlot++) {
        if (PCONTENTS pInvSlot = GetCharInfo2()->pInventoryArray->InventoryArray[usSlot]) {
            PITEMINFO pItemInfo    = GetItemFromContents(pInvSlot);
            PITEMINFO pUnequipInfo = GetItemFromContents(pUnequipSlot);

            if (pItemInfo && pUnequipInfo && TypePack(pInvSlot) && pInvSlot->Contents.ContainedItems.pItems && pItemInfo->Combine != 2 && pUnequipInfo->Size <= pItemInfo->SizeCapacity) { 
                PCONTENTS pLAST = pInvSlot->Contents.ContainedItems.pItems->Item[0];

                unsigned short usPack = 0;
                for (usPack = 0; usPack < pItemInfo->Slots; usPack++) {
                    if (!pInvSlot->Contents.ContainedItems.pItems->Item[usPack]) {
                        //DebugSpewAlways("no pointer at %hu of pack %hu", usPack, usSlot);
                        if (pLAST) {
                            pFreeSlot->InvSlot   = pInvSlot->Contents.ItemSlot;
                            pFreeSlot->BagSlot   = usPack;
                            pFreeSlot->pBagSlot  = pInvSlot->Contents.ContainedItems.pItems->Item[usPack]; // will be NULL
                            pFreeSlot->pInvSlot  = pInvSlot;
                            return pFreeSlot;
                        // else first bag slot was empty
					    } else {
                            usDecrement++;
                        }
                    } else if (usDecrement) {
                        //DebugSpewAlways("pack %hu minus decrement %hu equals %hu", usPack, usDecrement, usPack-usDecrement);
                        pFreeSlot->InvSlot    = pInvSlot->Contents.ItemSlot;
                        pFreeSlot->BagSlot    = usPack;
                        pFreeSlot->pBagSlot   = pInvSlot->Contents.ContainedItems.pItems->Item[usPack - usDecrement]; // will be NULL
                        pFreeSlot->pInvSlot   = pInvSlot;
                        return pFreeSlot;
                    }
                    pLAST = pInvSlot->Contents.ContainedItems.pItems->Item[usPack];
                }
                usDecrement = 0;
                pLAST = NULL;
            }
        }
    }
    return NULL;
}

// searches only main inventory for somewhere to put a pack
// returns slot number if it exists
long FindSlotForPack()
{
    long lSlot = 0;
    for (lSlot = BAG_SLOT_START; lSlot < NUM_INV_SLOTS; lSlot++) {
        PCONTENTS pInvSlot = GetCharInfo2()->pInventoryArray->InventoryArray[lSlot];
        if (!pInvSlot) {
            // main inventory slot is empty
            return lSlot;
        }
        PITEMINFO pItemInfo = GetItemFromContents(pInvSlot);
        // if there is an item that is not a pack             // if the item is a pack, but the pack is empty, we can swap it
        if (pItemInfo && ((pItemInfo->Type != ITEMTYPE_PACK) || (pItemInfo->Type == ITEMTYPE_PACK && !pInvSlot->Contents.ContainedItems.pItems))) {
            return lSlot;
        }
    }
    // no room for another pack
    return NOID;
}

// searches for any available inventory/pack slot -  to use with auto-inventory
// this includes stackable support, does not include main worn
long FreeSlotForItem(PCONTENTS pItem)
{
    long lSlot = 0;
    bool bCheckStack = ItemIsStackable(pItem);

    for (lSlot = BAG_SLOT_START; lSlot < NUM_INV_SLOTS; lSlot++) {
        PCONTENTS pInvSlot = GetCharInfo2()->pInventoryArray->InventoryArray[lSlot];
        if (!pInvSlot) return lSlot; // free main inv slot, we are done
        PITEMINFO pItemInfo = GetItemFromContents(pItem);
        PITEMINFO pSlotInfo = GetItemFromContents(pInvSlot);
        if (pItemInfo && pSlotInfo) {
			if (bCheckStack && pSlotInfo->Type != ITEMTYPE_PACK) { // check for stackable
                if (pItemInfo->ItemNumber == pSlotInfo->ItemNumber && StackHasRoom(pInvSlot)) return NOID; // use autoinventory
            }
            // search through the pack for a free slot
            if (TypePack(pInvSlot) && pItemInfo->Size <= pSlotInfo->SizeCapacity && (pSlotInfo->Combine == 2) ? (pItemInfo->ItemType == 27) : true) {
                if (!pInvSlot->Contents.ContainedItems.pItems) return NOID; // the pack is empty, use autoinventory
                unsigned short usPack = 0;
                for (usPack = 0; usPack < pSlotInfo->Slots; usPack++) {
                    PCONTENTS pBagSlot = pInvSlot->Contents.ContainedItems.pItems->Item[usPack];
                    if (!pBagSlot) return NOID;
                    PITEMINFO pBagInfo = GetItemFromContents(pBagSlot);
                    if (bCheckStack && pItemInfo->ItemNumber == pBagInfo->ItemNumber && StackHasRoom(pBagSlot)) return NOID;
                    // return if the slot is free or meets stacking requirements
                }
            }
        }
        // if its not stackable to main inventory or in this pack, move on to next slot
    }
    return 0;
}
