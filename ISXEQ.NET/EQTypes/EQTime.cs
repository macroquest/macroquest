using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Time type.
    /// </summary>
    public class EQTime : LavishScriptAPI.LavishScriptObject
    {
        public EQTime(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Date in the format MM/DD/YYYY
        /// </summary>
        public string Date
        {
            get { return GetMember<string>( "Date"); }
        }

        /// <summary>
        /// Day of the month
        /// </summary>
        public int Day
        {
            get { return GetMember<int>( "Day"); }
        }

        /// <summary>
        /// Day of the week (1=sunday to 7=saturday)
        /// </summary>
        public int DayOfWeek
        {
            get { return GetMember<int>( "DayOfWeek"); }
        }

        /// <summary>
        /// Hour (0-23)
        /// </summary>
        public int Hour
        {
            get { return GetMember<int>( "Hour"); }
        }

        /// <summary>
        /// Minute (0-59)
        /// </summary>
        public int Minute
        {
            get { return GetMember<int>( "Minute"); }
        }

        /// <summary>
        /// Month of the year (1-12)
        /// </summary>
        public int Month
        {
            get { return GetMember<int>( "Month"); }
        }

        /// <summary>
        /// Gives true if the current hour is considered "night" in EQ (7:00pm-6:59am)
        /// </summary>
        public bool Night
        {
            get { return GetMember<bool>( "Night"); }
        }

        /// <summary>
        /// Second (0-59)
        /// </summary>
        public int Second
        {
            get { return GetMember<int>( "Second"); }
        }

        /// <summary>
        /// Number of seconds since midnight
        /// </summary>
        public int SecondsSinceMidnight
        {
            get { return GetMember<int>( "SecondsSinceMidnight"); }
        }

        /// <summary>
        /// Time in 12-hour format (HH:MM:SS)
        /// </summary>
        public string Time12
        {
            get { return GetMember<string>( "Time12"); }
        }

        /// <summary>
        /// Time in 24-hour format (HH:MM:SS)
        /// </summary>
        public string Time24
        {
            get { return GetMember<string>( "Time24"); }
        }

        /// <summary>
        /// Year
        /// </summary>
        public int Year
        {
            get { return GetMember<int>( "Year"); }
        }


    }
}
