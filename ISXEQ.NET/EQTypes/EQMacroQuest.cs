using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest MacroQuest type.
    /// </summary>
    public class EQMacroQuest : LavishScriptAPI.LavishScriptPersistentObject
    {
        public EQMacroQuest(LavishScriptAPI.LavishScriptPersistentObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Date that mq2main.dll was built
        /// </summary>
        public string BuildDate
        {
            get { return GetMember<string>( "BuildDate"); }
        }

        /// <summary>
        /// Returns the name of chat channel #
        /// </summary>
        public string ChatChannelName(int Number)
        {
            return GetMember<string>( "ChatChannel", Number.ToString());
        }

        /// <summary>
        /// Returns true if channel name is joined
        /// </summary>
        public bool ChatChannelJoined(string Name)
        {
            return GetMember<bool>( "ChatChannel", Name);
        }

        /// <summary>
        /// Returns the number of channels currently joined
        /// </summary>
        public int ChatChannels
        {
            get { return GetMember<int>( "ChatChannels"); }
        }

        /// <summary>
        /// Last normal error message
        /// </summary>
        public string Error
        {
            get { return GetMember<string>( "Error"); }
        }

        /// <summary>
        /// CHARSELECT INGAME UNKNOWN
        /// </summary>
        public string GameState
        {
            get { return GetMember<string>( "GameState"); }
        }

        /// <summary>
        /// Last command entered
        /// </summary>
        public string LastCommand
        {
            get { return GetMember<string>( "LastCommand"); }
        }

        /// <summary>
        /// Name of last person to send you a tell
        /// </summary>
        public string LastTell
        {
            get { return GetMember<string>( "LastTell"); }
        }

        /// <summary>
        /// Your station name
        /// </summary>
        public string LoginName
        {
            get { return GetMember<string>( "LoginName"); }
        }

        /// <summary>
        /// Mouse's X location
        /// </summary>
        public int MouseX
        {
            get { return GetMember<int>( "MouseX"); }
        }

        /// <summary>
        /// Mouse's Y location
        /// </summary>
        public int MouseY
        {
            get { return GetMember<int>( "MouseY"); }
        }

        /// <summary>
        /// Last MQ2Data parsing error message
        /// </summary>
        public string MQ2DataError
        {
            get { return GetMember<string>( "MQ2DataError"); }
        }

        /// <summary>
        /// Your current ping
        /// </summary>
        public int Ping
        {
            get { return GetMember<int>( "Ping"); }
        }

        /// <summary>
        /// Running time of current MQ2 session, in milliseconds
        /// </summary>
        public int Running
        {
            get { return GetMember<int>( "Running"); }
        }

        /// <summary>
        /// Full name of your server
        /// </summary>
        public string Server
        {
            get { return GetMember<string>( "Server"); }
        }

        /// <summary>
        /// Last syntax error message
        /// </summary>
        public string SyntaxError
        {
            get { return GetMember<string>( "SyntaxError"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int ViewportX
        {
            get { return GetMember<int>( "ViewportX"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int ViewportXCenter
        {
            get { return GetMember<int>( "ViewportXCenter"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int ViewportXMax
        {
            get { return GetMember<int>( "ViewportXMax"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int ViewportY
        {
            get { return GetMember<int>( "ViewportY"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int ViewportYCenter
        {
            get { return GetMember<int>( "ViewportYCenter"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int ViewportYMax
        {
            get { return GetMember<int>( "ViewportYMax"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool LClickedObject
        {
            get { return GetMember<bool>( "LClickedObject"); }
        }


    }
}
