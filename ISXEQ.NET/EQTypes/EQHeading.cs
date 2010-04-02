using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Heading type.
    /// </summary>
    public class EQHeading : LavishScriptAPI.LavishScriptObject
    {
        public EQHeading(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// The long compass direction, eg. "south", "south by southeast"
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// The short compass direction, eg. "S", "SSE"
        /// </summary>
        public string ShortName
        {
            get { return GetMember<string>( "ShortName"); }
        }

        /// <summary>
        /// Heading in degrees (same as casting to float)
        /// </summary>
        public float Degrees
        {
            get { return GetMember<float>("Degrees"); }
        }

        /// <summary>
        /// The nearest clock direction, e.g. 1-12
        /// </summary>
        public int Clock
        {
            get { return GetMember<int>( "Clock"); }
        }

        /// <summary>
        /// Heading in degrees Counter-Clockwise (the way the rest of MQ2 and EQ uses it)
        /// </summary>
        public float DegreesCCW
        {
            get { return GetMember<float>("DegreesCCW"); }
        }
    }
}
