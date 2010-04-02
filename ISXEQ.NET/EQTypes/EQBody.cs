using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Body type.
    /// </summary>
    public class EQBody : LavishScriptAPI.LavishScriptPersistentObject
    {
        public EQBody(LavishScriptAPI.LavishScriptPersistentObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// The body types ID #
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// The full body type name
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

    }
}
