using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Ticks type.
    /// </summary>
    public class EQTicks : LavishScriptAPI.LavishScriptObject
    {
        public EQTicks(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// The number of hours in HH:MM:SS (0-23)
        /// </summary>
        public int Hours
        {
            get { return GetMember<int>( "Hours"); }
        }

        /// <summary>
        /// The number of minutes in HH:MM:SS (1-59)
        /// </summary>
        public int Minutes
        {
            get { return GetMember<int>( "Minutes"); }
        }

        /// <summary>
        /// The number of seconds in HH:MM:SS (1-59)
        /// </summary>
        public int Seconds
        {
            get { return GetMember<int>( "Seconds"); }
        }

        /// <summary>
        /// Time in the form MM:SS
        /// </summary>
        public string Time
        {
            get { return GetMember<string>( "Time"); }
        }

        /// <summary>
        /// The total number of minutes
        /// </summary>
        public int TotalMinutes
        {
            get { return GetMember<int>( "TotalMinutes"); }
        }

        /// <summary>
        /// The total number of seconds
        /// </summary>
        public int TotalSeconds
        {
            get { return GetMember<int>( "TotalSeconds"); }
        }

        /// <summary>
        /// The value in ticks
        /// </summary>
        public int Ticks
        {
            get { return GetMember<int>( "Ticks"); }
        }

        /// <summary>
        /// Time in the form HH:MM:SS (if there are no hours, the form will be MM:SS)
        /// </summary>
        public string TimeHMS
        {
            get { return GetMember<string>( "TimeHMS"); }
        }


    }
}
