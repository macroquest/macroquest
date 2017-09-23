using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Argb type.
    /// </summary>
    public class EQArgb : LavishScriptAPI.LavishScriptObject
    {
        public EQArgb(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Alpha
        /// </summary>
        public int Alpha
        {
            get { return GetMember<int>( "A"); }
        }

        /// <summary>
        /// Red
        /// </summary>
        public int Red
        {
            get { return GetMember<int>( "R"); }
        }

        /// <summary>
        /// Green
        /// </summary>
        public int Green
        {
            get { return GetMember<int>( "G"); }
        }

        /// <summary>
        /// Blue
        /// </summary>
        public int Blue
        {
            get { return GetMember<int>( "B"); }
        }

        /// <summary>
        /// The integer formed by ARGB
        /// </summary>
        public int Int
        {
            get { return GetMember<int>( "Int"); }
        }


    }
}
