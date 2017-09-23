using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Race type.
    /// </summary>
    public class EQRace : LavishScriptAPI.LavishScriptPersistentObject
    {
        public EQRace(LavishScriptAPI.LavishScriptPersistentObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// 
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

    }
}
