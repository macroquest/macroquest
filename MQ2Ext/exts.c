/*****************************************************************************
mqext.dll: NTSD extensions for EQLib.dll
Copyright (C) 2002 Plazmic

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
******************************************************************************/
#include "mqext.h"
//
// Extension to dump inventory
//
DECLARE_API ( inv )
{
#if defined(EXT_API_VERSION_NUMBER64)
    ULONG64 ppCharInfo, pCharInfo, pInventory, pItem, hr=0;
    DWORD index, cb, offset;
    DWORD Inventory[30];
    CHAR Name[64];

    ppCharInfo = GetExpression("EQADDR_CHAR_INFO");
    hr = ReadMemory(ppCharInfo,&pCharInfo,sizeof(pCharInfo),&cb);
    hr = ReadMemory(pCharInfo,&pCharInfo,sizeof(pCharInfo),&cb);
    if (cb!=sizeof(pCharInfo) || !pCharInfo) {
        dprintf("EQADDR_CHAR_INFO is not valid.");
        return;
    }
    hr = InitTypeRead(pCharInfo, _CHARINFO );
    GetFieldOffset("_CHARINFO","Name",&offset);
    ReadMemory(pCharInfo+offset,Name,sizeof(Name),&cb);
    dprintf("Inventory for %s:\n",Name);
    GetFieldOffset("_ITEMINFO","Name",&offset);
    pInventory = ReadField(Inventory);
    ReadMemory(pInventory,Inventory,sizeof(Inventory[0])*30,&cb);
    for (index=0;index<30;index++) {
        pItem=Inventory[index];
        if (pItem) {
            InitTypeRead(pItem, _ITEMINFO);
            ReadMemory(pItem+offset,Name,sizeof(Name),&cb);
        } else {
            strcpy(Name,"NULL");
        }
        dprintf("Inventory[%d]= %p (%s)\n",index, pItem, Name);
    }
    pInventory = ReadField(Bank);
    ReadMemory(pInventory,Inventory,sizeof(Inventory[0])*8,&cb);
    for (index=0;index<8;index++) {
        pItem = Inventory[index];
        if (pItem) {
            InitTypeRead(pItem, _ITEMINFO);
            ReadMemory(pItem+offset,Name,sizeof(Name),&cb);
        } else {
            strcpy(Name,"NULL");
        }
        dprintf("Bank[%d]= %p (%s)\n",index, pItem, Name);
    }
#else
    dprintf("command not supported with VS6\n");
#endif
}
//
// Extension to dump pack contents
//
DECLARE_API ( pack )
{
#if defined(EXT_API_VERSION_NUMBER64)
    ULONG64 pPack, pItem, slots, combine, hr=0;
    DWORD Contents[10];
    DWORD index, cb, offset;
    CHAR Name[64];

    pPack = GetExpression(args);
    hr = InitTypeRead(pPack, _ITEMINFO );
    slots = ReadField(Slots);
    combine = ReadField(Combine);
    GetFieldOffset("_ITEMINFO","Name",&offset);
    ReadMemory(pPack+offset,Name,sizeof(Name),&cb);
    dprintf("Pack: %s, %I64d slots, combine=%I64d\n",Name,slots, combine);
    if (!ReadField(IsContainer)) dprintf("*** Item does not appear to be a container, contents are probably wrong.\n");
    if (slots>10) {
        dprintf("*** Slots>10, definately not a valid \n");
        return;
    }
    pPack = ReadField(Contents);
    ReadMemory(pPack,Contents,sizeof(Contents[0])*10,&cb);
    GetFieldOffset("_ITEMINFO","Name",&offset);
    for (index=0;index<slots;index++) {
        pItem = Contents[index];
        if (pItem) {
            InitTypeRead(pItem, _ITEMINFO);
            ReadMemory(pItem+offset,Name,sizeof(Name),&cb);
        } else {
            strcpy(Name,"NULL");
        }
        dprintf("Contents[%d]= %p (%s)\n",index, pItem, Name);
    }
#else
    dprintf("command not supported with VS6\n");
#endif
}
//
// Extension help
//
DECLARE_API ( help ) 
{
    dprintf("Help for MQ extensions\n"
        "   inv           - Display inventory\n"
        "   pack          - Display pack contents\n"
        "   help          - Shows this help\n"
        "   pchar         - Display CHARINFO struct\n"
        "   pspawn        - Display SPAWNINFO struct\n"
        "   pitem         - Display ITEMINFO struct\n"
        "   pcommon       - Display COMMON struct\n"
        "   pcontainer    - Display CONTAINER struct\n"
        "   pgroundspawn  - Display GROUNDITEM struct\n"
        "   pdoor         - Display DOOR struct\n"
        "   pswitch          - Display EQSWITCH struct\n"
        "   pspellbuff    - Display SPELLBUFF struct\n"
        "   pspell        - Display SPELLLIST struct\n"
        "   pzone         - Display ZONELIST struct\n"
        "   pzoneinfo     - Display ZONEINFO struct\n"
        "   plootcorpse   - Display LOOTCORPSE struct\n"
        "   pactorinfo    - Display ACTORINFO struct\n"
        "   plootwnd      - Display EQLOOTWINDOW struct\n"
        "   ptradeskillwnd - Display EQTRADESKILLWINDOW struct\n"
        "   precipe       - Display EQTRADESKILLRECIPE struct\n"
        "   ppetinfownd   - Display EQPETINFOWINDOW struct\n"
        "   pguildwnd     - Display EQGUILDWINDOW struct\n"
        "   pguildmemberinfo - Display EQGUILDMEMBERINFO struct\n"
        "   praid         - Display EQRAID struct\n"
        "   paltability   - Display ALTABILITY struct\n"
        );
}
