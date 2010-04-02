using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Ticks type.
    /// </summary>
    public class EQMerchant : LavishScriptAPI.LavishScriptObject
    {
        public EQMerchant(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Merchant full?
        /// </summary>
        public bool Full
        {
            get { return GetMember<bool>( "Full"); }
        }

        /// <summary>
        /// Number of items on the merchant
        /// </summary>
        public int Items
        {
            get { return GetMember<int>( "Items"); }
        }

        public EQItem Item(int Number)
        {
            return new EQItem(GetMember("Item", Number.ToString())); 
        }
        public EQItem Item(string partial_name)
        {
            return new EQItem(GetMember("Item", partial_name));
        }
        public EQItem Item(string name, bool exact)
        {
            if (exact)
                name.Insert(0, "=");
            return new EQItem(GetMember("Item", name));
        }

        /// <summary>
        /// The value used to calculate item values for merchant (Markup is what your charisma and faction change)    * Markup*Cost=Merchant sell price.    * Cost*(1/Markup)=Your sell price. 1.05 is the cap, so there might not be a cap based on Charisma.
        /// </summary>
        public float Markup
        {
            get { return GetMember<float>("Markup"); }
        }

        /// <summary>
        /// Merchant open?
        /// </summary>
        public bool Open
        {
            get { return GetMember<bool>( "Open"); }
        }


    }
}
