using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Corpse type.
    /// </summary>
    public class EQCorpse : LavishScriptAPI.LavishScriptObject
    {
        public EQCorpse(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Item count on the corpse
        /// </summary>
        public int Items
        {
            get { return GetMember<int>( "Items"); }
        }


        public EQItem Item(int Number)
        {
            return new EQItem(GetMember("Item", Number.ToString())); 
        }
        public EQItem Item(string Partial_Name)
        {
            return new EQItem(GetMember("Item", Partial_Name));
        }
        public EQItem Item(string Name, bool exact)
        {
            if (exact)
                Name.Insert(0, "=");
            return new EQItem(GetMember("Item", Name));
        }

        /// <summary>
        /// Corpse open?
        /// </summary>
        public bool Open
        {
            get { return GetMember<bool>( "Open"); }
        }

        public static EQCorpse Corpse
        {
            get
            {
                return new EQCorpse(LavishScriptAPI.LavishScript.Objects.GetObject("Corpse"));
            }
        }

    }
}
