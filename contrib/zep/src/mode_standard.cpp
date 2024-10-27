#include "zep/mode_standard.h"
#include "zep/tab_window.h"
#include "zep/window.h"
#include "zep/mcommon/string/stringutils.h"

// Note:
// This is a version of the buffer that behaves like notepad.
// It is basic, but can easily be extended

// STANDARD:
//
// DONE:
// -----
// CTRLZ/Y Undo Redo
// Insert
// Delete/Backspace
// TAB
// Arrows - up,down, left, right
// Home (+Ctrl) move top/startline
// End (+Ctrol) move bottom/endline
// Shift == Select
// control+Shift == select word
// CTRL - CVX (copy paste, cut) + Delete Selection

namespace Zep
{

ZepMode_Standard::ZepMode_Standard(ZepEditor& editor)
    : ZepMode(editor)
{
}

ZepMode_Standard::~ZepMode_Standard()
{
}

void ZepMode_Standard::Init()
{
    // In standard mode, we always show the insert cursor type
    m_visualCursorType = CursorType::Insert;

    m_modeFlags |= ModeFlags::InsertModeGroupUndo | ModeFlags::StayInInsertMode;

    for (int i = 0; i <= 9; i++)
    {
        GetEditor().SetRegister('0' + (const char)i, "");
    }
    GetEditor().SetRegister('"', "");

    std::vector<KeyMap*> keyMaps = { &m_insertMap, &m_visualMap };

    // Insert Mode
    keymap_add(keyMaps, { "<Backspace>" }, id_Backspace);
    keymap_add(keyMaps, { "<Return>" }, id_InsertCarriageReturn);
    keymap_add(keyMaps, { "<Tab>" }, id_InsertTab);
    keymap_add(keyMaps, { "<Del>" }, id_Delete);
    keymap_add(keyMaps, { "<C-y>", "<C-S-z>" }, id_Redo);
    keymap_add(keyMaps, { "<C-z>" }, id_Undo);

    keymap_add(keyMaps, { "<Left>" }, id_MotionStandardLeft);
    keymap_add(keyMaps, { "<Right>" }, id_MotionStandardRight);
    keymap_add(keyMaps, { "<Up>" }, id_MotionStandardUp);
    keymap_add(keyMaps, { "<Down>" }, id_MotionStandardDown);
    keymap_add(keyMaps, { "<Home>" }, id_MotionStandardLineBegin);
    keymap_add(keyMaps, { "<End>" }, id_MotionStandardLineEnd);
    keymap_add(keyMaps, { "<PageUp>" }, id_MotionStandardPageBackward);
    keymap_add(keyMaps, { "<PageDown>" }, id_MotionStandardPageForward);

    keymap_add(keyMaps, { "<C-Left>" }, id_MotionStandardLeftWord);
    keymap_add(keyMaps, { "<C-Right>" }, id_MotionStandardRightWord);
    keymap_add(keyMaps, { "<C-Home>" }, id_MotionGotoBeginning);
    keymap_add(keyMaps, { "<C-End>" }, id_MotionGotoEnd);
    keymap_add(keyMaps, { "<C-a>" }, id_MotionStandardSelectAll);

    keymap_add(keyMaps, { "<S-Left>" }, id_MotionStandardLeftSelect);
    keymap_add(keyMaps, { "<S-Right>" }, id_MotionStandardRightSelect);
    keymap_add(keyMaps, { "<S-Up>" }, id_MotionStandardUpSelect);
    keymap_add(keyMaps, { "<S-Down>" }, id_MotionStandardDownSelect);
    keymap_add(keyMaps, { "<S-Home>" }, id_MotionStandardLineBeginSelect);
    keymap_add(keyMaps, { "<S-End>" }, id_MotionStandardLineEndSelect);
    keymap_add(keyMaps, { "<S-PageUp>" }, id_MotionStandardPageBackwardSelect);
    keymap_add(keyMaps, { "<S-PageDown>" }, id_MotionStandardPageForwardSelect);

    keymap_add(keyMaps, { "<C-S-Left>" }, id_MotionStandardLeftWordSelect);
    keymap_add(keyMaps, { "<C-S-Right>" }, id_MotionStandardRightWordSelect);
    keymap_add(keyMaps, { "<C-S-Home>" }, id_MotionStandardGotoBeginningSelect);
    keymap_add(keyMaps, { "<C-S-End>" }, id_MotionStandardGotoEndSelect);

    keymap_add(keyMaps, { "<C-=>" }, id_FontBigger);
    keymap_add(keyMaps, { "<C-->" }, id_FontSmaller);
    keymap_add(keyMaps, { "<C-0>" }, id_FontReset);

    keymap_add(keyMaps, { "<C-Up>" }, id_ViewLineBackward);
    keymap_add(keyMaps, { "<C-Down>" }, id_ViewLineForward);

    keymap_add(keyMaps, { "<C-v>" }, id_StandardPaste);
    keymap_add(keyMaps, { "<C-x>" }, id_StandardCut);
    keymap_add(keyMaps, { "<C-c>" }, id_StandardCopy);

    keymap_add({ &m_normalMap, &m_visualMap, &m_insertMap }, { "<Escape>" }, id_InsertMode);

    // mouse binds
    keymap_add({ &m_insertMap, &m_visualMap }, { "<LeftMouse>", "<C-LeftMouse>" }, id_MotionStandardMoveCursor);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<S-LeftMouse>" }, id_MotionStandardMoveCursorSelect);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<LeftDrag>", "<S-LeftDrag>" }, id_MotionStandardMoveCursorSelect);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<2-LeftMouse>" }, id_MotionStandardSelectWord);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<3-LeftMouse>" }, id_MotionStandardSelectLine);
}

void ZepMode_Standard::Begin(ZepWindow* pWindow)
{
    ZepMode::Begin(pWindow);

    // This will also set the cursor type
    SwitchMode(EditorMode::Insert);
}

void ZepMode_Standard::Notify(std::shared_ptr<ZepMessage> message)
{
}

void ZepMode_Standard::DispatchMouseEvent(std::shared_ptr<ZepMessage> message)
{

    if (message->messageId == Msg::MouseDown)
    {
        if (message->button == ZepMouseButton::Left)
            GetEditor().CaptureMouse(this, true);

        AddMouseEvent(message->button, false, message->modifiers, message->clicks);
        message->handled = true;
    }
    else if (message->messageId == Msg::MouseUp)
    {
        if (message->button == ZepMouseButton::Left)
            GetEditor().CaptureMouse(this, false);
        message->handled = true;
    }
    else if (message->messageId == Msg::MouseMove)
    {
        if (message->button != ZepMouseButton::Unknown)
        {
            AddMouseEvent(message->button, true, message->modifiers, 1);
        }
        message->handled = true;
    }
}

} // namespace Zep
