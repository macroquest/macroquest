using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest InventorySlot type.
    /// </summary>
    public class EQInvSlot : LavishScriptAPI.LavishScriptPersistentObject
    {
        public EQInvSlot(LavishScriptAPI.LavishScriptPersistentObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Number of this item slot (usable directly by /itemnotify)
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// Item contained by this item slot
        /// </summary>
        public EQItem Item
        {
            get { return new EQItem(GetMember("Item")); }
        }

        /// <summary>
        /// For inventory slots not inside packs, the slot name, otherwise NULL
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// Container that must be opened to access the slot with /itemnotify
        /// </summary>
        public EQInvSlot Pack
        {
            get { return new EQInvSlot(GetPersistentMember("Pack")); }
        }

        /// <summary>
        /// Slot number inside the pack which holds the item, otherwise NULL
        /// </summary>
        public int Slot
        {
            get { return GetMember<int>( "Slot"); }
        }


    }
}
