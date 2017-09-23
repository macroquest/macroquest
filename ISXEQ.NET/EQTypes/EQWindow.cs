using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Window type.
    /// </summary>
    public class EQWindow : LavishScriptAPI.LavishScriptObject
    {
        public EQWindow(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// 
        /// </summary>
        public void LeftMouseDown()
        {
            ExecuteMethod("LeftMouseDown");
        }

        /// <summary>
        /// 
        /// </summary>
        public void LeftMouseUp()
        {
            ExecuteMethod("LeftMouseUp");
        }

        /// <summary>
        /// 
        /// </summary>
        public void LeftMouseHeldDown()
        {
            ExecuteMethod("LeftMouseHeldDown");
        }

        /// <summary>
        /// 
        /// </summary>
        public void LeftMouseHeldUp()
        {
            ExecuteMethod("LeftMouseHeldUp");
        }

        /// <summary>
        /// 
        /// </summary>
        public void RightMouseDown()
        {
            ExecuteMethod("RightMouseDown");
        }

        /// <summary>
        /// 
        /// </summary>
        public void RightMouseUp()
        {
            ExecuteMethod("RightMouseUp");
        }

        /// <summary>
        /// 
        /// </summary>
        public void RightMouseHeldDown()
        {
            ExecuteMethod("RightMouseHeldDown");
        }

        /// <summary>
        /// 
        /// </summary>
        public void RightMouseHeldUp()
        {
            ExecuteMethod("RightMouseHeldUp");
        }

        /// <summary>
        /// 
        /// </summary>
        public void ListSelect()
        {
            ExecuteMethod("ListSelect");
        }

        /// <summary>
        /// Background color
        /// </summary>
        public EQArgb BGColor
        {
            get { return new EQArgb(GetMember("BGColor")); }
        }

        /// <summary>
        /// Checked? (useful for buttons)
        /// </summary>
        public bool Checked
        {
            get { return GetMember<bool>( "Checked"); }
        }

        /// <summary>
        /// Child[name] Child with this name
        /// </summary>
        public EQWindow Child(string Name)
        {
            return new EQWindow(GetMember("Child", Name));
        }

        /// <summary>
        /// Has children?
        /// </summary>
        public bool Children
        {
            get { return GetMember<bool>( "Children"); }
        }

        /// <summary>
        /// Enabled?
        /// </summary>
        public bool Enabled
        {
            get { return GetMember<bool>( "Enabled"); }
        }

        /// <summary>
        /// First child window
        /// </summary>
        public EQWindow FirstChild
        {
            get { return new EQWindow(GetMember("FirstChild")); }
        }

        /// <summary>
        /// Height in pixels
        /// </summary>
        public int Height
        {
            get { return GetMember<int>( "Height"); }
        }

        /// <summary>
        /// Highlighted/mouse over?
        /// </summary>
        public bool Highlighted
        {
            get { return GetMember<bool>( "Highlighted"); }
        }

        /// <summary>
        /// Has the other person clicked the Trade button?
        /// </summary>
        public bool HisTradeReady
        {
            get { return GetMember<bool>( "HisTradeReady"); }
        }

        /// <summary>
        /// Horizontal scrollbar range
        /// </summary>
        public int HScrollMax
        {
            get { return GetMember<int>( "HScrollMax"); }
        }

        /// <summary>
        /// Horizontal scrollbar position
        /// </summary>
        public int HScrollPos
        {
            get { return GetMember<int>( "HScrollPos"); }
        }

        /// <summary>
        /// Horizontal scrollbar position in % to range from 0 to 100
        /// </summary>
        public int HScrollPct
        {
            get { return GetMember<int>( "HScrollPct"); }
        }

        /// <summary>
        /// Number of items in a Listbox or Combobox
        /// </summary>
        public int Items
        {
            get { return GetMember<int>( "Items"); }
        }

        public string List(int Row)
        {
            return GetMember<string>( "List", Row.ToString());
        }
        public string List(int Row, int Column)
        {
            return GetMember<string>("List", Row.ToString(),Column.ToString());
        }

        public int List(string search)
        {
            return GetMember<int>("List", search);
        }
        public int List(string search, bool exact)
        {
            if (exact)
                search.Insert(0, "=");
               
            return GetMember<int>( "List", search);
        }
        public int List(string search, bool exact, int column)
        {
            if (exact)
                search.Insert(0, "=");

            return GetMember<int>("List", search, column.ToString());
        }

        /// <summary>
        /// Minimized?
        /// </summary>
        public bool Minimized
        {
            get { return GetMember<bool>( "Minimized"); }
        }

        /// <summary>
        /// Mouse currently over?
        /// </summary>
        public bool MouseOver
        {
            get { return GetMember<bool>( "MouseOver"); }
        }

        /// <summary>
        /// Have I clicked the Trade button?
        /// </summary>
        public bool MyTradeReady
        {
            get { return GetMember<bool>( "MyTradeReady"); }
        }

        /// <summary>
        /// Name of window piece (e.g. "ChatWindow" for top level windows,or the Piece name (NOTE: CUSTOM UI DEPENDANT) for child windows)
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// Next sibling window
        /// </summary>
        public EQWindow Next
        {
            get { return new EQWindow(GetMember("Next")); }
        }

        /// <summary>
        /// TRUE if the window is open
        /// </summary>
        public bool Open
        {
            get { return GetMember<bool>( "Open"); }
        }

        /// <summary>
        /// Parent window
        /// </summary>
        public EQWindow Parent
        {
            get { return new EQWindow(GetMember("Parent")); }
        }

        /// <summary>
        /// ScreenID of window piece (ScreenID is NOT custom ui dependant, this *must be* the same on ALL UIs)
        /// </summary>
        public string ScreenID
        {
            get { return GetMember<string>( "ScreenID"); }
        }

        /// <summary>
        /// Has siblings?
        /// </summary>
        public bool Siblings
        {
            get { return GetMember<bool>( "Siblings"); }
        }

        /// <summary>
        /// Window style code
        /// </summary>
        public int Style
        {
            get { return GetMember<int>( "Style"); }
        }

        /// <summary>
        /// Window's text
        /// </summary>
        public string Text
        {
            get { return GetMember<string>( "Text"); }
        }

        /// <summary>
        /// TooltipReference text
        /// </summary>
        public string Tooltip
        {
            get { return GetMember<string>( "Tooltip"); }
        }

        /// <summary>
        /// Type of window piece (Screen for top level windows, or Listbox, Button, Gauge, Label, Editbox, Slider, etc)
        /// </summary>
        public string Type
        {
            get { return GetMember<string>( "Type"); }
        }

        /// <summary>
        /// Vertical scrollbar range
        /// </summary>
        public int VScrollMax
        {
            get { return GetMember<int>( "VScrollMax"); }
        }

        /// <summary>
        /// Vertical scrollbar position
        /// </summary>
        public int VScrollPos
        {
            get { return GetMember<int>( "VScrollPos"); }
        }

        /// <summary>
        /// Vertical scrollbar position in % to range from 0 to 100
        /// </summary>
        public int VScrollPct
        {
            get { return GetMember<int>( "VScrollPct"); }
        }

        /// <summary>
        /// Width in pixels
        /// </summary>
        public int Width
        {
            get { return GetMember<int>( "Width"); }
        }

        /// <summary>
        /// Screen X position
        /// </summary>
        public int X
        {
            get { return GetMember<int>( "X"); }
        }

        /// <summary>
        /// Screen Y position
        /// </summary>
        public int Y
        {
            get { return GetMember<int>( "Y"); }
        }


    }
}
