using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Timer type.
    /// </summary>
    public class EQTimer : LavishScriptAPI.LavishScriptObject
    {
        public EQTimer(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// 
        /// </summary>
        public void Reset()
        {
            ExecuteMethod("Reset"); 
        }

        /// <summary>
        /// 
        /// </summary>
        public void Expire()
        {
            ExecuteMethod("Expire"); 
        }

        /// <summary>
        /// 
        /// </summary>
                public void Set()
        {
            ExecuteMethod("Set"); 
        }



        /// <summary>
        /// Current value of the timer
        /// </summary>
        public int Value
        {
            get { return GetMember<int>( "Value"); }
        }

        /// <summary>
        /// Original value of the timer
        /// </summary>
        public int OriginalValue
        {
            get { return GetMember<int>( "OriginalValue"); }
        }


    }
}
