/*********************************************************************************/
/* moveitem.h by pms - item find and move functions centralized in a single file */
/* last update  - 2011-0415                                                      */
/* release      - 2010-1103                                                      */
/*********************************************************************************/

#define INVALID_PACK 0xFFFF

// CItemLocation class is returned from functions
class CItemLocation
{
public:
    unsigned short InvSlot;    // main inventory slot (with or without a pack)
    unsigned short BagSlot;    // slot inside of the pack at InvSlot, 0xFFFF when not a bag
    EQINVSLOT*     pEQInvSlot; // EQINVSLOT* of the slot that has item to be moved
    PCONTENTS      pInvSlot;   // CONTENTS* of the main inventory slot
    PCONTENTS      pBagSlot;   // CONTENTS* of the bag slot inside of pInvSlot, NULL if no bag
    PCONTENTS      pItem;      // CONTENTS* of an item, regardless of where it is

    CItemLocation()
    {
        InvSlot    = 0;
        BagSlot    = INVALID_PACK;
        pEQInvSlot = NULL;
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
// /exchange 1234 slot           OR               /exchange "my item" slot
// if the item is found, ItemFind fills in your CItemLocation instance with data
// if the item is not found, it will return a NULL pointer so you know to halt
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

    // loop through inv slots & worn slots
	PCHARINFO2 pChar2 = GetCharInfo2();
	if(pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
		for (usSlot = usMin; usSlot < usInvSlots; usSlot++)
		{
			if (PCONTENTS pInvSlot = pChar2->pInventoryArray->InventoryArray[usSlot])
			{
				PITEMINFO pItemInfo = GetItemFromContents(pInvSlot);
				// if item provided by user is an item id and it matches, or item is by name and it matches
				if (pItemInfo && ((iIsNum && iItemID == pItemInfo->ItemNumber) || (!iIsNum && !_stricmp(pcItemName, pItemInfo->Name))))
				{
					// fill in contents pointers & slot id for class
					pItemFound->pInvSlot   = pInvSlot;
					pItemFound->pItem      = pInvSlot;
					pItemFound->pBagSlot   = pInvSlot;
					pItemFound->InvSlot    = usSlot;
					pItemFound->BagSlot    = 0xFFFF;
					// find actual slotmgr array index (true inv slot)
					int iInvMgrSlot        = FindInvSlotForContents(pInvSlot);
					PEQINVSLOTMGR pInvMgr  = (PEQINVSLOTMGR)pInvSlotMgr;
					pItemFound->pEQInvSlot = pInvMgr->SlotArray[iInvMgrSlot];
					if (!pItemFound->pEQInvSlot)
					{
						WriteChatf("\aymoveitem.h\aw:: Slot is NULL. Cannot move item.");
						return NULL;
					}
					return pItemFound;
				}
				// else if there is a non-empty bag in this slot
				else if (pItemInfo && TypePack(pInvSlot) && pInvSlot->Contents.ContainedItems.pItems)
				{
					// cycle through the number of pack slots
					unsigned short usPack = 0;
					for (usPack = 0; usPack < pItemInfo->Slots; usPack++)
					{
						if (PCONTENTS pBagSlot = pInvSlot->Contents.ContainedItems.pItems->Item[usPack])
						{
							PITEMINFO pBagInfo = GetItemFromContents(pBagSlot);
							if (pBagInfo && ((iIsNum && iItemID == pBagInfo->ItemNumber) || (!iIsNum && !_stricmp(pcItemName, pBagInfo->Name))))
							{
								// fill in contents pointers & slot id for class
								pItemFound->pInvSlot   = pInvSlot;
								pItemFound->pBagSlot   = pBagSlot;
								pItemFound->pItem      = pBagSlot;
								pItemFound->InvSlot    = usSlot;
								pItemFound->BagSlot    = usPack;
								// find actual slotmgr array index (true inv slot)
								int iInvMgrSlot        = FindInvSlotForContents(pBagSlot);
								PEQINVSLOTMGR pInvMgr  = (PEQINVSLOTMGR)pInvSlotMgr;
								pItemFound->pEQInvSlot = pInvMgr->SlotArray[iInvMgrSlot];
								if (!pItemFound->pInvSlot)
								{
									WriteChatf("\aymoveitem.h\aw:: Slot is NULL. Cannot move item.");
									return NULL;
								}
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
// SlotFind is called with a string containing an MQ-defined slot or slot number
// This function returns the slot number as a long, if it is found, or -1 if not found
// useful for validating user-supplied destinations such as /exchange __ mainhand
// were they to use /exchange __ primary, the -1 return of SlotFind indicates invalid argument
//
// Example
// char mainhand[] = "mainhand";
// long MainHandIndex = SlotFind(mainhand)
// if (MainHandIndex < 0) // slot not found, halt code

long SlotFind(char* pcSlotID)
{
    long lSlotNum = 0;
    if (IsNumber(pcSlotID))
    {
        lSlotNum = atoi(pcSlotID);
        // if the slot provided is a worn or main inventory slot, excludes old "magic numbers" for packs
        if (lSlotNum >= 0 && lSlotNum < NUM_INV_SLOTS) return lSlotNum;
    }
    else
    {
        for (lSlotNum = 0; szItemSlot[lSlotNum]; lSlotNum++)
        {
            if (!_stricmp(pcSlotID, szItemSlot[lSlotNum])) return lSlotNum;
        }
    }
    // mq slot was not found by name or number
    return NOID;
}

/*********************************************************************************/
// Count item cycles through all inventory and returns a count of items
// pcItemName is a string that either contains the item name or item ID to be compared
// return will be your count as unsigned long, adjusted if found, 0 if not


unsigned long CountItemByID(unsigned long ulID, unsigned short usMin = 0, unsigned short usInvSlots = NUM_INV_SLOTS);

// we prototype the args to search from 0 to 33 (worn, inv, and cursor) by default. you can change this to search
// only bags by calling CountItem() with usMin starting point BAG_SLOT_START

// counts by item name
template <unsigned int _Size> unsigned long CountItemByName(CHAR(&pcItemName)[_Size], size_t BufferSize, unsigned short usMin = 0, unsigned short usInvSlots = NUM_INV_SLOTS)
{
    unsigned long  ulCount = 0;
    unsigned short usSlot  = 0;

    // loop through inv slots & worn slots
	PCHARINFO2 pChar2 = GetCharInfo2();
	if(pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
		for (usSlot = usMin; usSlot < usInvSlots; usSlot++)
		{
			if (PCONTENTS pInvSlot = pChar2->pInventoryArray->InventoryArray[usSlot])
			{
				PITEMINFO pItemInfo = GetItemFromContents(pInvSlot);
				if (pItemInfo && !_stricmp(pcItemName, pItemInfo->Name))
				{
					if (ItemIsStackable(pInvSlot))
					{
						ulCount += pInvSlot->StackCount; // increment by the size of stack
					}
					else
					{
						ulCount++; // increment by a single item
					}

				}
				// else if there is a non-empty bag in this slot
				else if (pItemInfo && TypePack(pInvSlot) && pInvSlot->Contents.ContainedItems.pItems)
				{
					// cycle through the number of pack slots
					unsigned short usPack = 0;
					for (usPack = 0; usPack < pItemInfo->Slots; usPack++)
					{
						if (PCONTENTS pBagSlot = pInvSlot->Contents.ContainedItems.pItems->Item[usPack])
						{
							PITEMINFO pBagInfo = GetItemFromContents(pBagSlot);
							if (pBagInfo && !_stricmp(pcItemName, pBagInfo->Name))
							{
								if (ItemIsStackable(pBagSlot))
								{
									ulCount += pBagSlot->StackCount; // increment by the size of stack
								}
								else
								{
									ulCount++; // increment by a single item
								}
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
	PCHARINFO2 pChar2 = GetCharInfo2();
	if(pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
		for (usSlot = usMin; usSlot < usInvSlots; usSlot++)
		{
			if (PCONTENTS pInvSlot = pChar2->pInventoryArray->InventoryArray[usSlot])
			{
				PITEMINFO pItemInfo = GetItemFromContents(pInvSlot);
				// if item provided by user is an item id and it matches, or item is by name and it matches
				if (pItemInfo && (ulID == pItemInfo->ItemNumber))
				{
					if (ItemIsStackable(pInvSlot))
					{
						ulCount += pInvSlot->StackCount; // increment by the size of stack
					}
					else
					{
						ulCount++; // increment by a single item
					}

				}
				// else if there is a non-empty bag in this slot
				else if (pItemInfo && TypePack(pInvSlot) && pInvSlot->Contents.ContainedItems.pItems)
				{
					// cycle through the number of pack slots
					unsigned short usPack = 0;
					for (usPack = 0; usPack < pItemInfo->Slots; usPack++)
					{
						if (PCONTENTS pBagSlot = pInvSlot->Contents.ContainedItems.pItems->Item[usPack])
						{
							PITEMINFO pBagInfo = GetItemFromContents(pBagSlot);
							if (ulID == pBagInfo->ItemNumber)
							{
								if (ItemIsStackable(pBagSlot))
								{
									ulCount += pBagSlot->StackCount; // increment by the size of stack
								}
								else
								{
									ulCount++; // increment by a single item
								}
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
template <unsigned int _Size> unsigned long CountItem(CHAR(&pcItemName)[_Size], unsigned short usMin = 0, unsigned short usInvSlots = NUM_INV_SLOTS)
//unsigned long CountItem(char* pcItemName, size_t BufferSize, unsigned short usMin, unsigned short usInvSlots)
{
    int iIsNum  = IsNumber(pcItemName);
    int iItemID = atoi(pcItemName);
    if (iIsNum) return CountItemByID((unsigned long)iItemID, usMin, usInvSlots);
    return CountItemByName(pcItemName, usMin, usInvSlots);
}

/*********************************************************************************/
// returns an EQINVSLOT* for use in plugins that call SendInvClick() directly
// but find items using their own methods (e.g. MQ2FeedMe comparing to food items)

EQINVSLOT* GetSlotArray(PCONTENTS pSlot)
{
    int iInvMgrSlot        = FindInvSlotForContents(pSlot);
    PEQINVSLOTMGR pInvMgr  = (PEQINVSLOTMGR)pInvSlotMgr;
    return pInvMgr->SlotArray[iInvMgrSlot];
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
	PCHARINFO2 pChar2 = GetCharInfo2();
	if(pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
		for (usSlot = BAG_SLOT_START; usSlot < NUM_INV_SLOTS; usSlot++)
		{
			if (PCONTENTS pInvSlot = pChar2->pInventoryArray->InventoryArray[usSlot])
			{
				PITEMINFO pItemInfo    = GetItemFromContents(pInvSlot);
				PITEMINFO pUnequipInfo = GetItemFromContents(pUnequipSlot);

				if (pItemInfo && pUnequipInfo && TypePack(pInvSlot) && pInvSlot->Contents.ContainedItems.pItems && pItemInfo->Combine != 2 &&
					pUnequipInfo->Size <= pItemInfo->SizeCapacity) //&& (!PackSlot->InvSlot || cSlot->Item->SizeCapacity < ucCurSize))
				{
					PCONTENTS pLAST = pInvSlot->Contents.ContainedItems.pItems->Item[0];
					int iInvMgrSlot = 0;

					unsigned short usPack = 0;
					for (usPack = 0; usPack < pItemInfo->Slots; usPack++)
					{
						if (!pInvSlot->Contents.ContainedItems.pItems->Item[usPack])
						{
							//DebugSpewAlways("no pointer at %hu of pack %hu", usPack, usSlot);
							if (pLAST)
							{
								iInvMgrSlot = FindInvSlotForContents(pLAST) + 1;
								pFreeSlot->BagSlot   = usPack;
								pFreeSlot->pBagSlot  = pInvSlot->Contents.ContainedItems.pItems->Item[usPack]; // will be NULL
								pFreeSlot->pInvSlot  = pInvSlot;
								//ucCurSize        = cSlot->Item->SizeCapacity;
								//break;
								PEQINVSLOTMGR pInvMgr = (PEQINVSLOTMGR)pInvSlotMgr;
								pFreeSlot->pEQInvSlot = pInvMgr->SlotArray[iInvMgrSlot];
								if (!pFreeSlot->pInvSlot)
								{
									WriteChatf("\aymoveitem.h\aw:: SLOT IS NULL. Cannot send notification.");
									return NULL;
								}
								return pFreeSlot;
							}
							// else first bag slot was empty
							else
							{
								usDecrement++;
							}
						}
						else if (usDecrement)
						{
							//DebugSpewAlways("pack %hu minus decrement %hu equals %hu", usPack, usDecrement, usPack-usDecrement);
							iInvMgrSlot = FindInvSlotForContents(pInvSlot->Contents.ContainedItems.pItems->Item[usPack]);
							iInvMgrSlot -= usDecrement;
							//DebugSpewAlways("slot %hu packslot %hu has InvMgr SlotArray position %u", usSlot, usPack, ulInvMgrSlot);
							pFreeSlot->BagSlot    = usPack;
							pFreeSlot->pBagSlot   = pInvSlot->Contents.ContainedItems.pItems->Item[usPack - usDecrement]; // will be NULL
							pFreeSlot->pInvSlot   = pInvSlot;
							PEQINVSLOTMGR pInvMgr = (PEQINVSLOTMGR)pInvSlotMgr;
							pFreeSlot->pEQInvSlot = pInvMgr->SlotArray[iInvMgrSlot];
							if (!pFreeSlot->pInvSlot)
							{
								WriteChatf("\aymoveitem.h\aw:: SLOT IS NULL. Cannot send notification.");
								return NULL;
							}
							return pFreeSlot;
						}
						pLAST = pInvSlot->Contents.ContainedItems.pItems->Item[usPack];
					}
					usDecrement = 0;
					pLAST = NULL;
				}
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
    for (lSlot = BAG_SLOT_START; lSlot < NUM_INV_SLOTS; lSlot++)
    {
        PCONTENTS pInvSlot = GetCharInfo2()->pInventoryArray->InventoryArray[lSlot];
        if (!pInvSlot)
        {
            // main inventory slot is empty
            return lSlot;
        }
        PITEMINFO pItemInfo = GetItemFromContents(pInvSlot);
        // if there is an item that is not a pack             // if the item is a pack, but the pack is empty, we can swap it
        if (pItemInfo && ((pItemInfo->Type != ITEMTYPE_PACK) || (pItemInfo->Type == ITEMTYPE_PACK && !pInvSlot->Contents.ContainedItems.pItems)))
        {
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

    for (lSlot = BAG_SLOT_START; lSlot < NUM_INV_SLOTS; lSlot++)
    {
        PCONTENTS pInvSlot = GetCharInfo2()->pInventoryArray->InventoryArray[lSlot];
        if (!pInvSlot)
			return lSlot; // free main inv slot, we are done
        PITEMINFO pItemInfo = GetItemFromContents(pItem);
        PITEMINFO pSlotInfo = GetItemFromContents(pInvSlot);
        if (pItemInfo && pSlotInfo)
        {
            if (bCheckStack && pSlotInfo->Type != ITEMTYPE_PACK) // check for stackable
            {
                if (pItemInfo->ItemNumber == pSlotInfo->ItemNumber && StackHasRoom(pInvSlot))
					return NOID; // use autoinventory
            }
            // search through the pack for a free slot
            if (TypePack(pInvSlot) && pItemInfo->Size <= pSlotInfo->SizeCapacity && (pSlotInfo->Combine == 2) ? (pItemInfo->ItemType == 27) : true)
            {
                if (!pInvSlot->Contents.ContainedItems.pItems)
					return NOID; // the pack is empty, use autoinventory
                unsigned short usPack = 0;
                for (usPack = 0; usPack < pSlotInfo->Slots; usPack++)
                {
                    PCONTENTS pBagSlot = pInvSlot->Contents.ContainedItems.pItems->Item[usPack];
                    if (!pBagSlot)
						return NOID;
                    PITEMINFO pBagInfo = GetItemFromContents(pBagSlot);
                    if (bCheckStack && pItemInfo->ItemNumber == pBagInfo->ItemNumber && StackHasRoom(pBagSlot))
						return NOID;
                    // return if the slot is free or meets stacking requirements
                }
            }
        }
        // if its not stackable to main inventory or in this pack, move on to next slot
    }
    return 0;
}

/*********************************************************************************/
// these functions are used to click the actual slots. currently bag window must
// be open or you must be using MQ2BagWindow by devestator to ensure SendInvClick()
// into a bag will be valid. SendWornClick() is always valid.

// keystate
enum click_states
{
    NOKEY     = 0,    // WinClick(KeyState) nokey pressed
    SHIFTKEY  = 1,    // WinClick(KeyState) Shiftkey pressed
    CTRLKEY   = 256,  // WinClick(KeyState) Ctrlkey pressed
};

// clicks into bag slots.
// fails if bag is not open.
void SendInvClick(EQINVSLOT* pClickThis, unsigned long ulKeyState)
{
    if (pClickThis)
    {
        if (pClickThis->pInvSlotWnd)
        {
            int KeyboardFlags[4] = {0};
            *(unsigned long*)&KeyboardFlags = *(unsigned long*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags;
            *(unsigned long*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags = ulKeyState;
            if (!SendWndClick2((CXWnd*)pClickThis->pInvSlotWnd, "leftmouseup"))
            {
                WriteChatf("\aymoveitem.h\aw:: Failed to send left click notification");
            }
            *(unsigned long*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags = *(unsigned long*)&KeyboardFlags;
        }
        else
        {
            DebugSpewAlways("moveitem.h:: SendInvClick() didnt find EQINVSLOT->pInvSlotWnd");
        }
    }
    else
    {
        DebugSpewAlways("moveitem.h:: SendInvClick() was not passed a valid EQINVSLOT");
    }
}

// clicks actual worn & inv slots using the inventory window.
// forces server-side appearance update on worn items.
// this is passed a string for the slot (from EQ's UI Files) e.g. InvSlot1
void SendWornClick(char* pcScreenID, unsigned long ulKeyState, char* pcNotification = NULL);
// prototyped to default to leftmouseup
void SendWornClick(char* pcScreenID, unsigned long ulKeyState, char* pcNotification)
{
    if (pInventoryWnd)
    {
        if (CXWnd* wndInv = pInventoryWnd->GetChildItem(pcScreenID))
        {
            int KeyboardFlags[4] = {0};
            *(unsigned long*)&KeyboardFlags = *(unsigned long*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags;
            *(unsigned long*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags = ulKeyState;
            SendWndClick2(wndInv, !pcNotification ? "leftmouseup" : pcNotification);
            *(unsigned long*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags = *(unsigned long*)&KeyboardFlags;
        }
    }
}

// clicks autoinventory section of inventory window
void SendAutoInvClick()
{
    if (pInventoryWnd && pCharSpawn)
    {
        DoCommand((PSPAWNINFO)pCharSpawn,"/autoinventory");
    }
}

/*********************************************************************************/
// support for MQ2BagWindow

PMQPLUGIN FindPlugin(char* PluginName)
{
    unsigned int uiLength = strlen(PluginName) + 1;
    PMQPLUGIN pLook = pPlugins;
    while (pLook && _strnicmp(PluginName, pLook->szFilename, uiLength))
    {
        pLook = pLook->pNext;
    }
    return pLook;
}

bool BagWndLoaded()
{
    bool (*pfBagWndOpen)();
    pfBagWndOpen = NULL;
    if (PMQPLUGIN pLook = FindPlugin("mq2bagwindow"))
    {
        pfBagWndOpen = (bool(*)())GetProcAddress(pLook->hModule, "BagWindowOpen");
    }
    // if no pointer, or exported bool function return is false
    if (!pfBagWndOpen || !(*pfBagWndOpen)())
    {
        return false;
    }
    return true;
}

/*********************************************************************************/
// suport for opening and closing bags (if not using mq2bagwindow)

int iOpenBagKey                 = 0;
int iCloseBagKey                = 0;
const unsigned long MOVE_DELAY  = 80; // user can change this value to specify how long bags need to stay open to populate contents

void OpenBags()
{
    if (BagWndLoaded()) return;
    MQ2Globals::ExecuteCmd(iOpenBagKey, 1, 0);
    MQ2Globals::ExecuteCmd(iOpenBagKey, 0, 0);
}

void CloseBags()
{
    if (BagWndLoaded()) return;
    MQ2Globals::ExecuteCmd(iCloseBagKey, 1, 0);
    MQ2Globals::ExecuteCmd(iCloseBagKey, 0, 0);
}

void FindBagKeys()
{
    if (GetGameState() == GAMESTATE_INGAME)
    {
        iOpenBagKey  = FindMappableCommand("OPEN_INV_BAGS");
        iCloseBagKey = FindMappableCommand("CLOSE_INV_BAGS");
    }
}
