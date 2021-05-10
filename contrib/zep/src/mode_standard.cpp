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

    // Insert Mode
    keymap_add({ &m_insertMap }, { "<Backspace>" }, id_Backspace);
    keymap_add({ &m_insertMap }, { "<Return>" }, id_InsertCarriageReturn);
    keymap_add({ &m_insertMap }, { "<Tab>" }, id_InsertTab);
    keymap_add({ &m_insertMap }, { "<Del>" }, id_Delete);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<C-y>" }, id_Redo);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<C-z>" }, id_Undo);

    keymap_add({ &m_insertMap, &m_visualMap }, { "<Left>" }, id_MotionStandardLeft);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<Right>" }, id_MotionStandardRight);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<Up>" }, id_MotionStandardUp);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<Down>" }, id_MotionStandardDown);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<Home>" }, id_MotionStandardLineBegin);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<End>" }, id_MotionStandardLineEnd);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<PageUp>" }, id_MotionStandardPageBackward);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<PageDown>" }, id_MotionStandardPageForward);

    keymap_add({ &m_insertMap }, { "<C-Left>" }, id_MotionStandardLeftWord);
    keymap_add({ &m_insertMap }, { "<C-Right>" }, id_MotionStandardRightWord);
    keymap_add({ &m_insertMap }, { "<C-Home>" }, id_MotionGotoBeginning);
    keymap_add({ &m_insertMap }, { "<C-End>" }, id_MotionGotoEnd);

    keymap_add({ &m_insertMap, &m_visualMap }, { "<C-Up>" }, id_ViewLineBackward);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<C-Down>" }, id_ViewLineForward);

    keymap_add({ &m_insertMap, &m_visualMap }, { "<C-S-Left>" }, id_MotionStandardLeftWordSelect);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<C-S-Right>" }, id_MotionStandardRightWordSelect);

    keymap_add({ &m_insertMap, &m_visualMap }, { "<S-Left>" }, id_MotionStandardLeftSelect);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<S-Right>" }, id_MotionStandardRightSelect);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<S-Up>" }, id_MotionStandardUpSelect);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<S-Down>" }, id_MotionStandardDownSelect);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<S-Home>" }, id_MotionStandardLineBeginSelect);
    keymap_add({ &m_insertMap, &m_visualMap }, { "<S-End>" }, id_MotionStandardLineEndSelect);

    keymap_add({ &m_visualMap }, { "<C-x>" }, id_Delete);

    keymap_add({ &m_insertMap, &m_visualMap }, { "<C-v>" }, id_StandardPaste);
    keymap_add({ &m_visualMap }, { "<C-c>" }, id_StandardCopy);

    keymap_add({ &m_normalMap, &m_visualMap, &m_insertMap }, { "<Escape>" }, id_InsertMode);
    keymap_add({ &m_normalMap }, { "<Backspace>" }, id_MotionStandardLeft);

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
    if (message->messageId == Msg::MouseDown)
    {
        AddMouseEvent(message->button, false, message->modifiers, message->clicks);
    }
    else if (message->messageId == Msg::MouseMove)
    {
        if (message->button != ZepMouseButton::Unknown)
        {
            AddMouseEvent(message->button, true, message->modifiers, 1);
        }
    }
    else if (message->messageId == Msg::MouseScroll)
    {
        // Get the window under the cursor.
        for (const auto& tw : GetEditor().GetTabWindows())
        {
            for (const auto& w : tw->GetWindows())
            {
                if (w->GetDisplayRect().Contains(message->pos))
                {
                    w->AdjustScroll(-message->fval * 3);
                }
            }
        }
    }
}

} // namespace Zep
