#include "zep/mode.h"
#include "zep/buffer.h"
#include "zep/editor.h"
#include "zep/filesystem.h"
#include "zep/mcommon/logger.h"
#include "zep/mode_search.h"
#include "zep/regress.h"
#include "zep/syntax.h"
#include "zep/tab_window.h"

namespace Zep {

CommandContext::CommandContext(const std::string& commandIn, ZepMode& md, EditorMode editorMode)
    : owner(md)
    , fullCommand(commandIn)
    , buffer(md.GetCurrentWindow()->GetBuffer())
    , bufferCursor(md.GetCurrentWindow()->GetBufferCursor())
    , mouseCursor(md.GetCurrentWindow()->GetMouseCursor())
    , tempReg("", false)
    , currentMode(editorMode)
{
    registers.push('"');
    pRegister = &tempReg;

    bool needMore = false;
    auto extraMaps = md.GetEditor().GetGlobalKeyMaps(md);
    for (auto& extra : extraMaps)
    {
        keymap_find(*extra, fullCommand, keymap);
        if (keymap.foundMapping.id != 0)
        {
            break;
        }
    }

    if (keymap.foundMapping.id == 0)
    {
        keymap_find(owner.GetKeyMappings(currentMode), fullCommand, keymap);
        if (keymap.foundMapping.id == 0 && needMore)
        {
            keymap.needMoreChars = true;
        }
    }

    GetCommandRegisters();
}

void CommandContext::UpdateRegisters()
{
    // Store in a register
    if (registers.empty())
        return;

    if (op == CommandOperation::Delete || op == CommandOperation::DeleteLines)
    {
        beginRange.Clamp();
        endRange.Clamp();
        if (beginRange > endRange)
        {
            std::swap(beginRange, endRange);
        }

        // TODO: Make a helper for this
        std::string str = std::string(buffer.GetWorkingBuffer().begin() + beginRange.Index(), buffer.GetWorkingBuffer().begin() + endRange.Index());

        // Delete commands fill up 1-9 registers
        if (keymap.commandWithoutGroups[0] == 'd' || keymap.commandWithoutGroups[0] == 'D')
        {
            for (int i = 9; i > 1; i--)
            {
                owner.GetEditor().SetRegister('0' + (char)i, owner.GetEditor().GetRegister('0' + (char)i - 1));
            }
            owner.GetEditor().SetRegister('1', Register(str, (op == CommandOperation::DeleteLines)));
        }

        // Fill up any other required registers
        while (!registers.empty())
        {
            owner.GetEditor().SetRegister(registers.top(), Register(str, (op == CommandOperation::DeleteLines)));
            registers.pop();
        }
    }
    else if (op == CommandOperation::Copy || op == CommandOperation::CopyLines)
    {
        beginRange = beginRange.Clamp();
        endRange = endRange.Clamp();
        if (beginRange > endRange)
        {
            std::swap(beginRange, endRange);
        }

        std::string str = std::string(buffer.GetWorkingBuffer().begin() + beginRange.Index(), buffer.GetWorkingBuffer().begin() + endRange.Index());
        while (!registers.empty())
        {
            auto& ed = owner.GetEditor();

            // Capital letters append to registers instead of replacing them
            if (registers.top() >= 'A' && registers.top() <= 'Z')
            {
                auto chlow = (char)std::tolower(registers.top());
                ed.SetRegister(chlow, Register(ed.GetRegister(chlow).text + str, (op == CommandOperation::CopyLines)));
            }
            else
            {
                ed.SetRegister(registers.top(), Register(str, op == CommandOperation::CopyLines));
            }
            registers.pop();
        }
    }
}

void CommandContext::GetCommandRegisters()
{
    // No specified register, so use the default
    if (keymap.RegisterName() == 0)
    {
        keymap.captureRegisters.push_back('"');
        keymap.captureRegisters.push_back('*');
        keymap.captureRegisters.push_back('+');
    }

    if (keymap.RegisterName() == '_')
    {
        std::stack<char> temp;
        registers.swap(temp);
    }
    else
    {
        registers.push(keymap.RegisterName());

        char reg = keymap.RegisterName();

        // Demote capitals to lower registers when pasting (all both)
        if (reg >= 'A' && reg <= 'Z')
        {
            reg = (char)std::tolower((char)reg);
        }

        if (owner.GetEditor().GetRegisters().find(std::string({ reg })) != owner.GetEditor().GetRegisters().end())
        {
            pRegister = &owner.GetEditor().GetRegister(reg);
        }
    }

    // Default register
    if (pRegister->text.empty())
    {
        pRegister = &owner.GetEditor().GetRegister('"');
    }
}

ZepMode::ZepMode(ZepEditor& editor)
    : ZepComponent(editor)
{
}

ZepMode::~ZepMode()
{
}

ZepWindow* ZepMode::GetCurrentWindow() const
{
    // Mode begin should always set this and we should always have a valid window associated with the mode
    assert(m_pCurrentWindow != nullptr);
    return m_pCurrentWindow;
}

EditorMode ZepMode::GetEditorMode() const
{
    return m_currentMode;
}

void ZepMode::AddCommandText(std::string strText)
{
    if (m_pCurrentWindow == nullptr)
    {
        return;
    }

    for (auto& ch : strText)
    {
        AddKeyPress(ch);
    }
}

void ZepMode::ClampCursorForMode()
{
    if (m_pCurrentWindow == nullptr)
    {
        return;
    }

    // Normal mode cursor is never on a CR/0
    // This stops an edit, such as an undo from leaving the cursor on the CR.
    if (m_currentMode == EditorMode::Normal)
    {
        GetCurrentWindow()->SetBufferCursor(GetCurrentWindow()->GetBuffer().ClampToVisibleLine(GetCurrentWindow()->GetBufferCursor()));
    }
}

void ZepMode::SwitchMode(EditorMode currentMode)
{
    if (m_pCurrentWindow == nullptr)
    {
        return;
    }

    // Don't switch to invalid mode
    if (currentMode == EditorMode::None)
        return;

    // Don't switch to the same thing again
    if (currentMode == m_currentMode)
        return;

    auto pWindow = GetCurrentWindow();
    auto& buffer = pWindow->GetBuffer();
    auto cursor = pWindow->GetBufferCursor();

    // Force normal mode if the file is read only
    if (currentMode == EditorMode::Insert && buffer.HasFileFlags(FileFlags::ReadOnly))
    {
        currentMode = DefaultMode();
    }

    // When leaving Ex mode, reset search markers
    if (m_currentMode == EditorMode::Ex)
    {
        buffer.HideMarkers(RangeMarkerType::Search);

        // Bailed out of ex mode; reset the start location
        /*if (mode != EditorMode::Ex)
        {
            pWindow->SetBufferCursor(m_exCommandStartLocation);
        }
        */
    }
    else if (m_currentMode == EditorMode::Insert)
    {
        // When switching back to normal mode, put the cursor on the last character typed
        if (currentMode == EditorMode::Normal)
        {
            // Move back, but not to the previous line
            GlyphIterator itr(cursor);
            itr.MoveClamped(-1);
            GetCurrentWindow()->SetBufferCursor(itr);
        }
    }

    m_currentMode = currentMode;

    switch (currentMode)
    {
    case EditorMode::Normal:
    {
        buffer.ClearSelection();
        ClampCursorForMode();
        ResetCommand();
    }
    break;
    case EditorMode::Insert:
        buffer.ClearSelection();
        ResetCommand();
        break;
    case EditorMode::Visual:
    {
        ResetCommand();
    }
    break;
    case EditorMode::Ex:
    {
        m_exCommandStartLocation = cursor;
        // Ensure we show the command at the bottom
        GetEditor().SetCommandText(m_currentCommand);
    }
    break;
    default:
    case EditorMode::None:
        break;
    }
}

std::string ZepMode::ConvertInputToMapString(uint32_t key, uint32_t modifierKeys)
{
    std::ostringstream str;
    bool closeBracket = false;
    if (modifierKeys & ModifierKey::Ctrl)
    {
        str << "<C-";
        if (modifierKeys & ModifierKey::Shift)
        {
#if 0
            // Add the S- modifier for shift enabled special keys
            // We want to avoid adding S- to capitalized (and already shifted)
            // keys
            if (key < ' ')
            {
                str << "S-";
            }
#else
            str << "S-";
#endif
        }
        closeBracket = true;
    }
    else if (modifierKeys & ModifierKey::Shift)
    {
        if (key < ' ')
        {
            str << "<S-";
            closeBracket = true;
        }
    }

    std::string mapped;

    switch (key)
    {
    case ExtKeys::RETURN: mapped = "Return"; break;
    case ExtKeys::ESCAPE: mapped = "Escape"; break;
    case ExtKeys::BACKSPACE: mapped = "Backspace"; break;
    case ExtKeys::LEFT: mapped = "Left"; break;
    case ExtKeys::RIGHT: mapped = "Right"; break;
    case ExtKeys::UP: mapped = "Up"; break;
    case ExtKeys::DOWN: mapped = "Down"; break;
    case ExtKeys::TAB: mapped = "Tab"; break;
    case ExtKeys::DEL: mapped = "Del"; break;
    case ExtKeys::HOME: mapped = "Home"; break;
    case ExtKeys::END: mapped = "End"; break;
    case ExtKeys::PAGEDOWN: mapped = "PageDown"; break;
    case ExtKeys::PAGEUP: mapped = "PageUp"; break;
    case ExtKeys::F1: mapped = "F1"; break;
    case ExtKeys::F2: mapped = "F2"; break;
    case ExtKeys::F3: mapped = "F3"; break;
    case ExtKeys::F4: mapped = "F4"; break;
    case ExtKeys::F5: mapped = "F5"; break;
    case ExtKeys::F6: mapped = "F6"; break;
    case ExtKeys::F7: mapped = "F7"; break;
    case ExtKeys::F8: mapped = "F8"; break;
    case ExtKeys::F9: mapped = "F9"; break;
    case ExtKeys::F10: mapped = "F10"; break;
    case ExtKeys::F11: mapped = "F11"; break;
    case ExtKeys::F12: mapped = "F12"; break;
    default: break;
    }

    if (!mapped.empty())
    {
        if (!closeBracket)
        {
            str << "<" << mapped;
            closeBracket = true;
        }
        else
        {
            str << mapped;
        }
    }
    else
    {
        str << std::string((const char*)&key);
    }

    if (closeBracket)
    {
        str << ">";
    }

    return str.str();
}

std::string ZepMode::ConvertMouseInputToMapString(ZepMouseButton button, bool isDrag, uint32_t modifierKeys, int clicks)
{
    std::ostringstream str;
    bool closeBracket = false;
    if (modifierKeys & ModifierKey::Ctrl)
    {
        str << "<C-";
        if (modifierKeys & ModifierKey::Shift)
        {
            // Add the S- modifier for shift enabled special keys
            // We want to avoid adding S- to capitalized (and already shifted)
            // keys
             str << "S-";
        }
        closeBracket = true;
    }
    else if (modifierKeys & ModifierKey::Shift)
    {
        str << "<S-";
        closeBracket = true;
    }

    if (clicks > 1)
    {
        if (!closeBracket)
        {
            str << "<";
            closeBracket = true;
        }
        else
        {
            str << "-";
        }

        str << clicks << "-";
    }

    std::string mapped;

    switch (button)
    {
    case ZepMouseButton::Left:
        if (isDrag)
            mapped = "LeftDrag";
        else
            mapped = "LeftMouse";
        break;
    case ZepMouseButton::Middle:
        if (isDrag)
            mapped = "MiddleDrag";
        else
            mapped = "MiddleMouse";
        break;
    case ZepMouseButton::Right:
        if (isDrag)
            mapped = "RightDrag";
        else
            mapped = "RightMouse";
        break;
    case ZepMouseButton::Button4:
        if (isDrag)
            mapped = "X4MouseDrag";
        else
            mapped = "X4Mouse";
        break;
    case ZepMouseButton::Button5:
        if (isDrag)
            mapped = "X5MouseDrag";
        else
            mapped = "X5Mouse";
        break;
    default:
        break;
    }

    if (!closeBracket)
    {
        str << "<" << mapped;
        closeBracket = true;
    }
    else
    {
        str << mapped;
    }

    if (closeBracket)
    {
        str << ">";
    }

    return str.str();
}

// Handle a key press, convert it to an input command and context, and execute it.
void ZepMode::AddKeyPress(uint32_t key, uint32_t modifierKeys)
{
    if (m_pCurrentWindow == nullptr)
    {
        return;
    }

    // Temporarily accept up to 255; this is not fully allowing UTF8 input yet (though display and management of buffers with
    // utf8 is just fine)
    key &= 0xFF;

    // Keys in this range converted to UTF8.  I need to figure out how to generically receive UTF8 here, but this
    // temporary fix enables £-sign and other specials to display and work correctly
    if (key >= 127 && key <= 255)
    {

        key = (0x00C2 | ((key & 0xFF) << 8));
    }

    m_lastKey = key;

    // Get the new command by parsing out the keys
    // We convert CTRL + f to a string: "<C-f>"
    HandleMappedInput(ConvertInputToMapString(key, modifierKeys));

    auto notifier = m_pCurrentWindow->GetBuffer().GetPostKeyNotifier();
    if (notifier != nullptr)
    {
        notifier(key, modifierKeys);
    }

    timer_restart(m_lastKeyPressTimer);
}

// Handle a mouse press. convert it to an input command and context, and execute it.
void ZepMode::AddMouseEvent(ZepMouseButton mouseButton, bool isDrag /*= false*/, uint32_t modifierKeys /*= ModifierKey::None*/, int clicks /*= 1 */)
{
    if (m_pCurrentWindow == nullptr)
    {
        return;
    }

    HandleMappedInput(ConvertMouseInputToMapString(mouseButton, isDrag, modifierKeys, clicks));

    timer_restart(m_lastKeyPressTimer);
}

void ZepMode::HandleMappedInput(const std::string& input)
{
    if (input.empty())
    {
        return;
    }

    //ZLOG(DBG, input);

    // Special case, dot command (do last edit again)
    // Dot command is complicated, this is my second attempt at implementing it and is less
    // complex.  The approach is to store relevent key strokes for the last edit operation,
    // and replay them when the user uses the dot.
    if (m_currentMode == EditorMode::Normal && input[input.size() - 1] == '.')
    {
        // Save and restore the last command while doing it.
        auto lastCommand = m_dotCommand;
        for (auto& last : lastCommand)
        {
            HandleMappedInput(std::string(1, last));
        }
        m_dotCommand = lastCommand;

        SwitchMode(EditorMode::Normal);

        return;
    }

    // The current command is our currently typed multi-key operation
    m_currentCommand += input;

    // Reset the timer for the last edit, for time-sensitive key strokes
    GetEditor().ResetLastEditTimer();

    // Reset the cursor to keep it visible during typing, and not flashing
    GetEditor().ResetCursorTimer();

    // Reset command text - it may get updated later.
    GetEditor().SetCommandText("");

    // Figure out the command we have typed. foundCommand means that the command was interpreted and understood.
    // If spCommand is returned, then there is an atomic command operation that needs to be done.
    auto spContext = std::make_shared<CommandContext>(m_currentCommand, *this, m_currentMode);

    // Before handling the command, change the command text, since the command might override it
    if (GetEditor().GetConfig().showNormalModeKeyStrokes && (m_currentMode == EditorMode::Normal || m_currentMode == EditorMode::Visual))
    {
        GetEditor().SetCommandText(spContext->keymap.searchPath);
    }

    spContext->foundCommand = GetCommand(*spContext);

    // Stay in insert mode unless commanded otherwise
    if (spContext->commandResult.modeSwitch == EditorMode::None && spContext->foundCommand)
    {
        if (m_modeFlags & ModeFlags::StayInInsertMode)
        {
            spContext->commandResult.modeSwitch = EditorMode::Insert;
        }
    }

    // A lambda to check for a pending mode switch after the command
    auto enteringMode = [=](auto mode) {
        if (m_currentMode != spContext->commandResult.modeSwitch && spContext->commandResult.modeSwitch == mode)
        {
            return true;
        }
        return false;
    };

    // Escape Nukes the current command - we handle it in the keyboard mappings after that
    // TODO: This feels awkward
    if (m_lastKey == ExtKeys::ESCAPE)
    {
        m_currentCommand.clear();
    }

    // Did we find something to do?
    if (spContext->foundCommand)
    {
        // It's an undoable command  - add it
        // Note: a command here is something that modifies the text.  It can be something like a delete
        // or a simple insert
        if (spContext->commandResult.spCommand)
        {
            // If not in insert mode, begin the group, because we have started a new operation
            if (m_currentMode != EditorMode::Insert || ZTestFlags(spContext->commandResult.flags, CommandResultFlags::BeginUndoGroup))
            {
                AddCommand(std::make_shared<ZepCommand_GroupMarker>(spContext->buffer));

                // Record for the dot command
                m_dotCommand = m_currentCommand;
            }
            else
            {
                // In insert mode keep the text for the dot command.  An insert adds a command too!
                m_dotCommand += input;
            }

            // Do the command
            AddCommand(spContext->commandResult.spCommand);
        }
        else
        {
            // This command didn't change anything, but switched into insert mode, so
            // remember the dot command that did it
#if 0
            if (enteringMode(EditorMode::Insert))
            {
                AddCommand(std::make_shared<ZepCommand_GroupMarker>(spContext->buffer));
                m_dotCommand = m_currentCommand;
            }
#endif
        }

        // If the command can't manage the count, we do it
        // Maybe all commands should handle the count?  What are the implications of that?  This bit is a bit messy
        if (!(spContext->commandResult.flags & CommandResultFlags::HandledCount))
        {
            // Ignore count == 1, we already did it
            for (int i = 1; i < spContext->keymap.TotalCount(); i++)
            {
                // May immediate execute and not return a command...
                // Create a new 'inner' spContext-> for the next command, because we need to re-initialize the command
                // spContext-> for 'after' what just happened!
                CommandContext contextInner(m_currentCommand, *this, m_currentMode);
                if (GetCommand(contextInner) && contextInner.commandResult.spCommand)
                {
                    // Actually queue/do command
                    AddCommand(contextInner.commandResult.spCommand);
                }
            }
        }

        // A mode to switch to after the command is done
        SwitchMode(spContext->commandResult.modeSwitch);

        // If not in ex mode, wait for a new command
        // Can this be cleaner?
        if (m_currentMode != EditorMode::Ex)
        {
            ResetCommand();
        }

        // Motions can update the visual selection
        UpdateVisualSelection();
    }
    else
    {
        // If not found, and there was no request for more characters, and we aren't in Ex mode
        if (m_currentMode != EditorMode::Ex)
        {
            if (HandleIgnoredInput(*spContext) || !spContext->keymap.needMoreChars)
            {
                ResetCommand();
            }
        }
    }
    ClampCursorForMode();
}

void ZepMode::AddCommand(std::shared_ptr<ZepCommand> spCmd)
{
    if (m_pCurrentWindow == nullptr)
    {
        return;
    }

    if (GetCurrentWindow()->GetBuffer().HasFileFlags(FileFlags::Locked))
    {
        // Ignore commands on buffers because we are view only,
        // and all commands currently modify the buffer!
        return;
    }

    spCmd->Redo();
    m_undoStack.push(spCmd);

    // Can't redo anything beyond this point
    std::stack<std::shared_ptr<ZepCommand>> empty;
    m_redoStack.swap(empty);

    if (spCmd->GetCursorAfter().Valid())
    {
        GetCurrentWindow()->SetBufferCursor(spCmd->GetCursorAfter());
    }
}

void ZepMode::Redo()
{
    if (m_pCurrentWindow == nullptr)
    {
        return;
    }

    if (m_redoStack.empty())
        return;

    if (std::dynamic_pointer_cast<ZepCommand_GroupMarker>(m_redoStack.top()) != nullptr)
    {
        m_undoStack.push(m_redoStack.top());
        m_redoStack.pop();
    }

    while (!m_redoStack.empty())
    {
        auto& spCommand = m_redoStack.top();
        spCommand->Redo();

        if (spCommand->GetCursorAfter().Valid())
        {
            GetCurrentWindow()->SetBufferCursor(spCommand->GetCursorAfter());
        }

        m_undoStack.push(spCommand);
        m_redoStack.pop();

        if (std::dynamic_pointer_cast<ZepCommand_GroupMarker>(spCommand) != nullptr)
        {
            break;
        }
    };
}

void ZepMode::Undo()
{
    if (m_pCurrentWindow == nullptr)
    {
        return;
    }

    if (m_undoStack.empty())
        return;

    if (std::dynamic_pointer_cast<ZepCommand_GroupMarker>(m_undoStack.top()) != nullptr)
    {
        m_redoStack.push(m_undoStack.top());
        m_undoStack.pop();
    }

    while (!m_undoStack.empty())
    {
        auto& spCommand = m_undoStack.top();
        spCommand->Undo();

        if (spCommand->GetCursorBefore().Valid())
        {
            GetCurrentWindow()->SetBufferCursor(spCommand->GetCursorBefore());
        }

        m_redoStack.push(spCommand);
        m_undoStack.pop();

        if (std::dynamic_pointer_cast<ZepCommand_GroupMarker>(spCommand) != nullptr)
        {
            break;
        }
    };
}

GlyphRange ZepMode::GetInclusiveVisualRange() const
{
    // Clamp and orient the correct way around
    auto startOffset = m_visualBegin.Clamped();
    auto endOffset = m_visualEnd.Clamped();

    if (startOffset > endOffset)
    {
        std::swap(startOffset, endOffset);
    }

    if (DefaultMode() == EditorMode::Insert)
    {
        if (startOffset == endOffset)
        {
            return GlyphRange();
        }

        // In standard/insert mode, selections exclude the last character
        endOffset.Move(-1);
    }

    return GlyphRange(startOffset, endOffset);
}

const std::string& ZepMode::GetLastCommand() const
{
    return m_dotCommand;
}

bool ZepMode::GetCommand(CommandContext& context)
{
    auto bufferCursor = GetCurrentWindow()->GetBufferCursor();
    auto& buffer = GetCurrentWindow()->GetBuffer();

    if (m_currentMode == EditorMode::Ex)
    {
        // TODO: Is it possible extend our key mapping to better process ex commands?  Or are these
        // too specialized?
        if (HandleExCommand(context.fullCommand))
        {
            //buffer.GetMode()->Begin(GetCurrentWindow());
            SwitchMode(DefaultMode());
            ResetCommand();
            return true;
        }
        GetEditor().SetCommandText(m_currentCommand);

        return false;
    }

    // The keymapper is waiting for more input
    if (context.keymap.needMoreChars)
    {
        return false;
    }

    // This flag is for non-modal editors which like to break insertions into undo groups.
    // Vim, for example, doesn't do that; an insert mode operation is a single 'group'
    bool shouldGroupInserts = ZTestFlags(m_modeFlags, ModeFlags::InsertModeGroupUndo);

    GlyphIterator cursorItr = bufferCursor;

    StringId mappedCommand = context.keymap.foundMapping;

    ZepExCommand* pEx = GetEditor().FindExCommand(mappedCommand);
    if (pEx)
    {
        pEx->Run();
        return true;
    }

    // Inherited modes can handle extra commands this way
    if (HandleSpecialCommand(context))
    {
        return true;
    }

    switch (mappedCommand)
    {
    case id_NormalMode:
        // TODO: I think this should be a 'command' which would get replayed with dot;
        // instead of special casing it later, we could just insert it into the stream of commands
        context.commandResult.modeSwitch = EditorMode::Normal;
        return true;

    case id_ExMode:
        context.commandResult.modeSwitch = EditorMode::Ex;
        return true;

        // Control

    case id_MotionNextMarker:
    {
        auto pFound = buffer.FindNextMarker(GetCurrentWindow()->GetBufferCursor(), Direction::Forward, RangeMarkerType::Mark);
        if (pFound)
        {
            GetCurrentWindow()->SetBufferCursor(GlyphIterator(&context.buffer, pFound->GetRange().first));
        }
        return true;
    }
    case id_MotionPreviousMarker:
    {
        auto pFound = buffer.FindNextMarker(GetCurrentWindow()->GetBufferCursor(), Direction::Backward, RangeMarkerType::Mark);
        if (pFound)
        {
            GetCurrentWindow()->SetBufferCursor(GlyphIterator(&context.buffer, pFound->GetRange().first));
        }
        return true;
    }
    case id_MotionNextSearch:
    {
        auto pFound = buffer.FindNextMarker(GetCurrentWindow()->GetBufferCursor(), m_lastSearchDirection, RangeMarkerType::Search);
        if (pFound)
        {
            GetCurrentWindow()->SetBufferCursor(GlyphIterator(&context.buffer, pFound->GetRange().first));
        }
        return true;
    }
    case id_MotionPreviousSearch:
    {
        auto pFound = buffer.FindNextMarker(GetCurrentWindow()->GetBufferCursor(), m_lastSearchDirection == Direction::Forward ? Direction::Backward : Direction::Forward, RangeMarkerType::Search);
        if (pFound)
        {
            GetCurrentWindow()->SetBufferCursor(GlyphIterator(&context.buffer, pFound->GetRange().first));
        }
        return true;
    }
    case id_SwitchToAlternateFile:
    {
        // This is a quick and easy 'alternate file swap'.
        // It searches a preset list of useful folder targets around the current file.
        // A better alternative might be a wildcard list of relations, but this works well enough
        // It also only looks for a file with the same name and different extension!
        // it is good enough for my current needs...
        auto path = buffer.GetFilePath();
        if (!path.empty() && GetEditor().GetFileSystem().Exists(path))
        {
            auto ext = path.extension();
            auto searchPaths = std::vector<ZepPath>{
                path.parent_path(),
                path.parent_path().parent_path(),
                path.parent_path().parent_path().parent_path()
            };

            auto ignoreFolders = std::vector<std::string>{ "build", ".git", "obj", "debug", "release" };

            auto priorityFolders = std::vector<std::string>{ "source", "include", "src", "inc", "lib" };

            // Search the paths, starting near and widening
            for (auto& p : searchPaths)
            {
                if (p.empty())
                    continue;

                bool found = false;

                // Look for the priority folder locations
                std::vector<ZepPath> searchFolders{ path.parent_path() };
                for (auto& priorityFolder : priorityFolders)
                {
                    GetEditor().GetFileSystem().ScanDirectory(p, [&](const ZepPath& currentPath, bool& recurse) {
                        recurse = false;
                        if (GetEditor().GetFileSystem().IsDirectory(currentPath))
                        {
                            auto lower = string_tolower(currentPath.filename().string());
                            if (std::find(ignoreFolders.begin(), ignoreFolders.end(), lower) != ignoreFolders.end())
                            {
                                return true;
                            }

                            if (priorityFolder == lower)
                            {
                                searchFolders.push_back(currentPath);
                            }
                        }
                        return true;
                    });
                }

                for (auto& folder : searchFolders)
                {
                    ZLOG(INFO, "Searching: " << folder.string());

                    GetEditor().GetFileSystem().ScanDirectory(folder, [&](const ZepPath& currentPath, bool& recurse) {
                        recurse = true;
                        if (path.stem() == currentPath.stem() && !(currentPath.extension() == path.extension()))
                        {
                            auto load = GetEditor().GetFileBuffer(currentPath, 0, true);
                            if (load != nullptr)
                            {
                                GetCurrentWindow()->SetBuffer(load);
                                found = true;
                                return false;
                            }
                        }
                        return true;
                    });
                    if (found)
                        return true;
                }
            }
        }
    }
    case id_FontBigger:
        GetEditor().GetDisplay().Bigger();
        return true;
    case id_FontSmaller:
        GetEditor().GetDisplay().Smaller();
        return true;
    case id_FontReset:
        GetEditor().GetDisplay().ResetFontScale();
        return true;

    // Moving between splits
    case id_MotionDownSplit:
        GetCurrentWindow()->GetTabWindow().DoMotion(WindowMotion::Down);
        return true;
    case id_MotionUpSplit:
        GetCurrentWindow()->GetTabWindow().DoMotion(WindowMotion::Up);
        return true;
    case id_MotionLeftSplit:
        GetCurrentWindow()->GetTabWindow().DoMotion(WindowMotion::Left);
        return true;
    case id_MotionRightSplit:
        GetCurrentWindow()->GetTabWindow().DoMotion(WindowMotion::Right);
        return true;

    // global search
    case id_QuickSearch:
        GetEditor().AddSearch();
        return true;
    case id_Redo:
        context.commandResult.modeSwitch = DefaultMode();
        Redo();
        return true;
    case id_Undo:
        context.commandResult.modeSwitch = DefaultMode();
        Undo();
        return true;
    case id_MotionLineEnd:
        GetCurrentWindow()->SetBufferCursor(context.buffer.GetLinePos(bufferCursor, LineLocation::LineLastNonCR));
        return true;
    case id_MotionLineBegin:
        GetCurrentWindow()->SetBufferCursor(context.buffer.GetLinePos(bufferCursor, LineLocation::LineBegin));
        return true;
    case id_MotionLineFirstChar:
        GetCurrentWindow()->SetBufferCursor(context.buffer.GetLinePos(bufferCursor, LineLocation::LineFirstGraphChar));
        return true;

    // Moving between tabs
    case id_PreviousTabWindow:
        GetEditor().PreviousTabWindow();
        return true;
    case id_NextTabWindow:
        GetEditor().NextTabWindow();
        return true;
    case id_MotionDown:
        GetCurrentWindow()->MoveCursorY(context.keymap.TotalCount());
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        return true;
    case id_MotionUp:
        GetCurrentWindow()->MoveCursorY(-context.keymap.TotalCount());
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        return true;
    case id_MotionRight:
        GetCurrentWindow()->SetBufferCursor(cursorItr.MoveClamped(context.keymap.TotalCount()));
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        return true;
    case id_MotionLeft:
        GetCurrentWindow()->SetBufferCursor(cursorItr.MoveClamped(-context.keymap.TotalCount()));
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        return true;
    case id_MotionStandardRight:
        GetCurrentWindow()->SetBufferCursor(cursorItr.Move(context.keymap.TotalCount()));
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        return true;
    case id_MotionStandardLeft:
        GetCurrentWindow()->SetBufferCursor(cursorItr.Move(-context.keymap.TotalCount()));
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        return true;
    case id_MotionStandardUp:
        GetCurrentWindow()->MoveCursorY(-1, LineLocation::LineCRBegin);
        return true;
    case id_MotionStandardDown:
        GetCurrentWindow()->MoveCursorY(1, LineLocation::LineCRBegin);
        return true;
    case id_MotionStandardRightSelect:
    {
        context.commandResult.modeSwitch = EditorMode::Visual;
        if (m_currentMode != EditorMode::Visual)
        {
            m_visualBegin = GetCurrentWindow()->GetBufferCursor();
        }
        GetCurrentWindow()->SetBufferCursor(bufferCursor + 1);
        UpdateVisualSelection();
        return true;
    }
    case id_MotionStandardLeftSelect:
    {
        context.commandResult.modeSwitch = EditorMode::Visual;
        if (m_currentMode != EditorMode::Visual)
        {
            m_visualBegin = GetCurrentWindow()->GetBufferCursor();
        }
        GetCurrentWindow()->SetBufferCursor(bufferCursor - 1);
        UpdateVisualSelection();
        return true;
    }
    case id_MotionStandardUpSelect:
    {
        context.commandResult.modeSwitch = EditorMode::Visual;
        if (m_currentMode != EditorMode::Visual)
        {
            m_visualBegin = GetCurrentWindow()->GetBufferCursor();
        }
        GetCurrentWindow()->MoveCursorY(-1, LineLocation::LineCRBegin);
        UpdateVisualSelection();
        return true;
    }
    case id_MotionStandardDownSelect:
    {
        context.commandResult.modeSwitch = EditorMode::Visual;
        if (m_currentMode != EditorMode::Visual)
        {
            m_visualBegin = GetCurrentWindow()->GetBufferCursor();
        }
        GetCurrentWindow()->MoveCursorY(1, LineLocation::LineCRBegin);
        UpdateVisualSelection();
        return true;
    }
    case id_MotionStandardRightWord:
    {
        auto target = buffer.StandardCtrlMotion(bufferCursor, Direction::Forward);
        GetCurrentWindow()->SetBufferCursor(target.second);
        return true;
    }
    case id_MotionStandardLeftWord:
    {
        auto target = buffer.StandardCtrlMotion(bufferCursor, Direction::Backward);
        GetCurrentWindow()->SetBufferCursor(target.second);
        return true;
    }
    case id_MotionStandardRightWordSelect:
    {
        context.commandResult.modeSwitch = EditorMode::Visual;
        if (m_currentMode != EditorMode::Visual)
        {
            m_visualBegin = GetCurrentWindow()->GetBufferCursor();
        }
        auto target = buffer.StandardCtrlMotion(bufferCursor, Direction::Forward);
        GetCurrentWindow()->SetBufferCursor(target.second);
        UpdateVisualSelection();
        return true;
    }
    case id_MotionStandardLeftWordSelect:
    {
        context.commandResult.modeSwitch = EditorMode::Visual;
        if (m_currentMode != EditorMode::Visual)
        {
            m_visualBegin = GetCurrentWindow()->GetBufferCursor();
        }
        auto target = buffer.StandardCtrlMotion(bufferCursor, Direction::Backward);
        GetCurrentWindow()->SetBufferCursor(target.second);
        UpdateVisualSelection();
        return true;
    }
    case id_MotionStandardLineBegin:
        GetCurrentWindow()->SetBufferCursor(context.buffer.GetLinePos(bufferCursor, LineLocation::LineBegin));
        return true;
    case id_MotionStandardLineEnd:
        GetCurrentWindow()->SetBufferCursor(context.buffer.GetLinePos(bufferCursor, LineLocation::LineCRBegin));
        return true;
    case id_MotionStandardLineBeginSelect:
        context.commandResult.modeSwitch = EditorMode::Visual;
        if (m_currentMode != EditorMode::Visual)
        {
            m_visualBegin = GetCurrentWindow()->GetBufferCursor();
        }
        GetCurrentWindow()->SetBufferCursor(context.buffer.GetLinePos(bufferCursor, LineLocation::LineBegin));
        UpdateVisualSelection();
        return true;
    case id_MotionStandardLineEndSelect:
        context.commandResult.modeSwitch = EditorMode::Visual;
        if (m_currentMode != EditorMode::Visual)
        {
            m_visualBegin = GetCurrentWindow()->GetBufferCursor();
        }
        GetCurrentWindow()->SetBufferCursor(context.buffer.GetLinePos(bufferCursor, LineLocation::LineCRBegin));
        UpdateVisualSelection();
        return true;

    case id_MotionPageForward:
        // Note: the vim spec says 'visible lines - 2' for a 'page'.
        // We jump the max possible lines, which might hit the end of the text; this matches observed vim behavior
        GetCurrentWindow()->MoveCursorY((GetCurrentWindow()->GetMaxDisplayLines() - 2) * context.keymap.TotalCount());
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        return true;
    case id_MotionHalfPageForward:
        // Note: the vim spec says 'half visible lines' for up/down
        GetCurrentWindow()->MoveCursorY((GetCurrentWindow()->GetNumDisplayedLines() / 2) * context.keymap.TotalCount());
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        return true;
    case id_MotionStandardPageForward:
        GetCurrentWindow()->MoveCursorY(GetCurrentWindow()->GetMaxDisplayLines() * context.keymap.TotalCount());
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        return true;
    case id_MotionStandardPageForwardSelect:
        context.commandResult.modeSwitch = EditorMode::Visual;
        if (m_currentMode != EditorMode::Visual)
        {
            m_visualBegin = GetCurrentWindow()->GetBufferCursor();
        }
        GetCurrentWindow()->MoveCursorY(GetCurrentWindow()->GetMaxDisplayLines() * context.keymap.TotalCount());
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        UpdateVisualSelection();
        return true;

    case id_MotionPageBackward:
        // Note: the vim spec says 'visible lines - 2' for a 'page'
        GetCurrentWindow()->MoveCursorY(-(GetCurrentWindow()->GetMaxDisplayLines() - 2) * context.keymap.TotalCount());
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        return true;
    case id_MotionHalfPageBackward:
        GetCurrentWindow()->MoveCursorY(-(GetCurrentWindow()->GetNumDisplayedLines() / 2) * context.keymap.TotalCount());
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        return true;
    case id_MotionStandardPageBackward:
        GetCurrentWindow()->MoveCursorY(-GetCurrentWindow()->GetMaxDisplayLines() * context.keymap.TotalCount());
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        return true;
    case id_MotionStandardPageBackwardSelect:
        context.commandResult.modeSwitch = EditorMode::Visual;
        if (m_currentMode != EditorMode::Visual)
        {
            m_visualBegin = GetCurrentWindow()->GetBufferCursor();
        }
        GetCurrentWindow()->MoveCursorY(-GetCurrentWindow()->GetMaxDisplayLines() * context.keymap.TotalCount());
        context.commandResult.flags |= CommandResultFlags::HandledCount;
        UpdateVisualSelection();
        return true;

    case id_ViewLineForward:
        GetCurrentWindow()->ScrollByLine(1);
        return true;
    case id_ViewLineBackward:
        GetCurrentWindow()->ScrollByLine(-1);
        return true;
    case id_MotionGotoLine:
        if (!context.keymap.captureNumbers.empty())
        {
            // In Vim, 0G means go to end!  1G is the first line...
            long count = context.keymap.TotalCount() - 1;
            count = std::min(context.buffer.GetLineCount() - 1, count);
            if (count < 0)
                count = context.buffer.GetLineCount() - 1;

            ByteRange range;
            if (context.buffer.GetLineOffsets(count, range))
            {
                GetCurrentWindow()->SetBufferCursor(GlyphIterator(&context.buffer, range.first));
            }
        }
        else
        {
            // Move right to the end
            auto lastLine = context.buffer.GetLinePos(context.buffer.End(), LineLocation::LineBegin);
            GetCurrentWindow()->SetBufferCursor(lastLine);
            context.commandResult.flags |= CommandResultFlags::HandledCount;
        }
        return true;
    case id_Backspace:
        // In insert mode, we are 'on' the character after the one we want to delete
        if (m_currentMode != EditorMode::Visual)
        {
            context.beginRange = cursorItr.Peek(-1);
            context.endRange = cursorItr;
        }
        else
        {
            context.beginRange = m_visualBegin;
            context.endRange = m_visualEnd;
        }
        context.op = CommandOperation::Delete;
        break;
    case id_MotionWord:
    {
        auto target = context.buffer.WordMotion(context.bufferCursor, SearchType::Word, Direction::Forward);
        GetCurrentWindow()->SetBufferCursor(target);
        return true;
    }
    case id_MotionWORD:
    {
        auto target = context.buffer.WordMotion(context.bufferCursor, SearchType::WORD, Direction::Forward);
        GetCurrentWindow()->SetBufferCursor(target);
        return true;
    }
    case id_MotionBackWord:
    {
        auto target = context.buffer.WordMotion(context.bufferCursor, SearchType::Word, Direction::Backward);
        GetCurrentWindow()->SetBufferCursor(target);
        return true;
    }
    case id_MotionBackWORD:
    {
        auto target = context.buffer.WordMotion(context.bufferCursor, SearchType::WORD, Direction::Backward);
        GetCurrentWindow()->SetBufferCursor(target);
        return true;
    }
    case id_MotionEndWord:
    {
        auto target = context.buffer.EndWordMotion(context.bufferCursor, SearchType::Word, Direction::Forward);
        GetCurrentWindow()->SetBufferCursor(target);
        return true;
    }
    case id_MotionEndWORD:
    {
        auto target = context.buffer.EndWordMotion(context.bufferCursor, SearchType::WORD, Direction::Forward);
        GetCurrentWindow()->SetBufferCursor(target);
        return true;
    }
    case id_MotionBackEndWord:
    {
        auto target = context.buffer.EndWordMotion(context.bufferCursor, SearchType::Word, Direction::Backward);
        GetCurrentWindow()->SetBufferCursor(target);
        return true;
    }
    case id_MotionBackEndWORD:
    {
        auto target = context.buffer.EndWordMotion(context.bufferCursor, SearchType::WORD, Direction::Backward);
        GetCurrentWindow()->SetBufferCursor(target);
        return true;
    }
    case id_MotionGotoBeginning:
        GetCurrentWindow()->SetBufferCursor(context.buffer.Begin());
        return true;
    case id_MotionStandardGotoBeginningSelect:
        context.commandResult.modeSwitch = EditorMode::Visual;
        if (m_currentMode != EditorMode::Visual)
        {
            m_visualBegin = GetCurrentWindow()->GetBufferCursor();
        }
        GetCurrentWindow()->SetBufferCursor(context.buffer.Begin());
        UpdateVisualSelection();
        return true;

    case id_MotionGotoEnd:
        GetCurrentWindow()->SetBufferCursor(context.buffer.End());
        return true;
    case id_MotionStandardGotoEndSelect:
        context.commandResult.modeSwitch = EditorMode::Visual;
        if (m_currentMode != EditorMode::Visual)
        {
            m_visualBegin = GetCurrentWindow()->GetBufferCursor();
        }
        GetCurrentWindow()->SetBufferCursor(context.buffer.End());
        UpdateVisualSelection();
        return true;

    case id_MotionStandardMoveCursor:
        if (context.mouseCursor.Valid())
            GetCurrentWindow()->SetBufferCursor(context.mouseCursor);
        return true;
    case id_MotionStandardMoveCursorSelect:
        if (context.mouseCursor.Valid())
        {
            context.commandResult.modeSwitch = EditorMode::Visual;
            if (m_currentMode != EditorMode::Visual)
            {
                m_visualBegin = GetCurrentWindow()->GetBufferCursor();
            }
            GetCurrentWindow()->SetBufferCursor(context.mouseCursor);
        }
        return true;
    case id_MotionStandardSelectWord:
        if (context.mouseCursor.Valid())
        {
            context.commandResult.modeSwitch = EditorMode::Visual;
            auto range = buffer.InnerWordMotion(context.mouseCursor, SearchType::Word);
            m_visualBegin = range.first;
            GetCurrentWindow()->SetBufferCursor(range.second);
            UpdateVisualSelection();
        }
        return true;
    case id_MotionStandardSelectLine:
        if (context.mouseCursor.Valid())
        {
            context.commandResult.modeSwitch = EditorMode::Visual;
            m_visualBegin = buffer.GetLinePos(context.mouseCursor, LineLocation::BeyondLineEnd);
            GetCurrentWindow()->SetBufferCursor(buffer.GetLinePos(context.mouseCursor, LineLocation::LineBegin));
            UpdateVisualSelection();
        }
        return true;
    case id_MotionStandardSelectAll:
    {
        context.commandResult.modeSwitch = EditorMode::Visual;
        m_visualBegin = context.buffer.Begin();
        GetCurrentWindow()->SetBufferCursor(context.buffer.End());
        UpdateVisualSelection();
        return true;
    }

    case id_JoinLines:
    {
        // Special case, join on empy line, just pull out the newline
        if (context.bufferCursor.Char() == '\n')
        {
            context.beginRange = context.bufferCursor;
            context.endRange = context.bufferCursor.PeekByteOffset(1);
            context.op = CommandOperation::Delete;
        }
        else
        {
            // Replace the CR (and thus join lines)
            context.beginRange = context.buffer.GetLinePos(context.bufferCursor, LineLocation::LineCRBegin);
            context.endRange = context.buffer.GetLinePos(context.bufferCursor, LineLocation::BeyondLineEnd);

            // Replace all white space (as the J append command does)
            context.tempReg.text = " ";
            context.pRegister = &context.tempReg;
            context.endRange = std::max(context.endRange, buffer.GetLinePos(context.endRange, LineLocation::LineFirstGraphChar));
            context.replaceRangeMode = ReplaceRangeMode::Replace;

            context.op = CommandOperation::Replace;
            context.commandResult.flags = ZSetFlags(context.commandResult.flags, CommandResultFlags::BeginUndoGroup);
        }
        break;
    }
    default:
        if (mappedCommand == id_VisualMode || mappedCommand == id_VisualLineMode)
        {
            if (m_currentMode == EditorMode::Visual)
            {
                context.commandResult.modeSwitch = DefaultMode();
            }
            else
            {
                if (mappedCommand == id_VisualLineMode)
                {
                    m_visualBegin = context.buffer.GetLinePos(context.bufferCursor, LineLocation::LineBegin);
                    m_visualEnd = context.buffer.GetLinePos(context.bufferCursor, LineLocation::LineCRBegin);
                }
                else
                {
                    m_visualBegin = context.bufferCursor;
                    m_visualEnd = m_visualBegin;
                }
                context.commandResult.modeSwitch = EditorMode::Visual;
            }
            m_lineWise = (mappedCommand == id_VisualLineMode ? true : false);
            return true;
        }

        switch (mappedCommand)
        {
        case id_Delete:
            if (m_currentMode == EditorMode::Visual)
            {
                auto range = GetInclusiveVisualRange();
                context.beginRange = range.first;
                context.endRange = range.second.Peek(1);
                context.op = CommandOperation::Delete;
                context.commandResult.modeSwitch = DefaultMode();
            }
            else
            {
                context.beginRange = cursorItr;
                if (m_currentMode == EditorMode::Normal)
                {
                    // Normal/Vim mode clamped to end of line
                    context.endRange = cursorItr.PeekLineClamped(context.keymap.TotalCount(), LineLocation::LineCRBegin);
                }
                else
                {
                    context.endRange = cursorItr.Peek(context.keymap.TotalCount());
                }
                context.op = CommandOperation::Delete;
                context.commandResult.flags |= CommandResultFlags::HandledCount;
            }
            break;
        case id_OpenLineBelow:
            context.beginRange = context.buffer.GetLinePos(context.bufferCursor, LineLocation::LineCRBegin);
            context.tempReg.text = "\n";
            context.pRegister = &context.tempReg;
            context.op = CommandOperation::Insert;
            context.commandResult.modeSwitch = EditorMode::Insert;
            context.commandResult.flags = ZSetFlags(context.commandResult.flags, CommandResultFlags::BeginUndoGroup);
            break;
        case id_OpenLineAbove:
            context.beginRange = context.buffer.GetLinePos(context.bufferCursor, LineLocation::LineBegin);
            context.tempReg.text = "\n";
            context.pRegister = &context.tempReg;
            context.op = CommandOperation::Insert;
            context.commandResult.modeSwitch = EditorMode::Insert;
            context.cursorAfterOverride = context.bufferCursor;
            context.commandResult.flags = ZSetFlags(context.commandResult.flags, CommandResultFlags::BeginUndoGroup, shouldGroupInserts);
            break;
        case id_YankLine:
            // Copy the whole line, including the CR
            context.registers.push('0');
            context.registers.push('*');
            context.registers.push('+');
            context.beginRange = context.buffer.GetLinePos(context.bufferCursor, LineLocation::LineBegin);
            context.endRange = context.buffer.GetLinePos(context.bufferCursor, LineLocation::BeyondLineEnd);
            context.op = CommandOperation::CopyLines;
            context.commandResult.modeSwitch = DefaultMode();
            context.cursorAfterOverride = context.beginRange;
            break;
        case id_Yank:
        {
            context.registers.push('0');
            context.registers.push('*');
            context.registers.push('+');
            auto range = GetInclusiveVisualRange();
            context.beginRange = range.first;
            context.endRange = range.second.Peek(1);
            // Note: select line wise yank if we started in linewise copy mode
            context.op = m_lineWise ? CommandOperation::CopyLines : CommandOperation::Copy;
            context.commandResult.modeSwitch = DefaultMode();
            context.cursorAfterOverride = context.beginRange;
            break;
        }
        case id_StandardCopy:
        {
            // Ignore empty copy
            auto range = GetInclusiveVisualRange();
            if (context.currentMode == EditorMode::Visual && range.IsValid())
            {
                context.beginRange = range.first;
                context.endRange = range.second.Peek(1);
            }
            else
            {
                context.beginRange = context.buffer.GetLinePos(bufferCursor, LineLocation::LineBegin);
                context.endRange = context.buffer.GetLinePos(bufferCursor, LineLocation::BeyondLineEnd);
            }

            if (context.beginRange == context.endRange)
            {
                return true;
            }

            // Copy in standard mode stays in visual mode
            if (context.currentMode == EditorMode::Visual)
                context.commandResult.modeSwitch = EditorMode::Visual;
            context.registers.push('0');
            context.registers.push('*');
            context.registers.push('+');
            context.cursorAfterOverride = context.bufferCursor;

            // Note: select line wise yank if we started in linewise copy mode
            context.op = CommandOperation::Copy;
            break;
        }
        case id_StandardCut:
        {
            // Ignore empty copy
            auto range = GetInclusiveVisualRange();
            if (context.currentMode == EditorMode::Visual && range.IsValid())
            {
                context.beginRange = range.first;
                context.endRange = range.second.Peek(1);
            }
            else
            {
                context.beginRange = context.buffer.GetLinePos(bufferCursor, LineLocation::LineBegin);
                context.endRange = context.buffer.GetLinePos(bufferCursor, LineLocation::BeyondLineEnd);
            }

            if (context.beginRange == context.endRange)
            {
                return true;
            }

            context.registers.push('0');
            context.registers.push('*');
            context.registers.push('+');
            context.cursorAfterOverride = context.bufferCursor;

            // Note: select line wise yank if we started in linewise copy mode
            context.op = CommandOperation::Delete;
            break;
        }
        case id_StandardPaste:
        {
            context.pRegister = &GetEditor().GetRegister(DefaultMode() == EditorMode::Insert ? '*' : '"');

            if (context.currentMode == EditorMode::Visual)
            {
                context.replaceRangeMode = ReplaceRangeMode::Replace;
                context.op = CommandOperation::Replace;
                auto range = GetInclusiveVisualRange();
                context.beginRange = range.first;
                context.endRange = range.second.Peek(1);
                context.cursorAfterOverride = context.beginRange.PeekByteOffset(long(context.pRegister->text.size()));
                context.commandResult.modeSwitch = EditorMode::Insert;
            }
            else
            {
                context.beginRange = context.bufferCursor;
                context.op = CommandOperation::Insert;
            }
            context.commandResult.flags = ZSetFlags(context.commandResult.flags, CommandResultFlags::BeginUndoGroup);
            break;
        }
        case id_PasteAfter:
        {
            if (!context.pRegister->text.empty())
            {
                // Already in visual mode, so replace the selection
                if (context.currentMode == EditorMode::Visual)
                {
                    context.replaceRangeMode = ReplaceRangeMode::Replace;
                    context.op = CommandOperation::Replace;
                    context.pRegister = &GetEditor().GetRegister('"');
                    auto range = GetInclusiveVisualRange();
                    context.beginRange = range.first;
                    context.endRange = range.second.Peek(1);
                    context.cursorAfterOverride = context.beginRange.PeekByteOffset(long(context.pRegister->text.size()));
                    context.commandResult.modeSwitch = EditorMode::Insert;
                }
                else
                {
                    if (context.pRegister->lineWise)
                    {
                        context.beginRange = context.buffer.GetLinePos(context.bufferCursor, LineLocation::BeyondLineEnd);
                        context.cursorAfterOverride = context.beginRange;
                    }
                    else
                    {
                        context.beginRange = cursorItr.PeekLineClamped(1, LineLocation::LineCRBegin);
                    }
                    context.op = CommandOperation::Insert;
                }
            }
            context.commandResult.flags = ZSetFlags(context.commandResult.flags, CommandResultFlags::BeginUndoGroup);
            break;
        }
        case id_PasteBefore:
        {
            if (!context.pRegister->text.empty())
            {
                // Already in visual mode, so replace the selection with whatever we copied
                if (context.currentMode == EditorMode::Visual)
                {
                    context.pRegister = &GetEditor().GetRegister('"');
                    auto range = GetInclusiveVisualRange();
                    context.beginRange = range.first;
                    context.endRange = range.second.Peek(1);
                    context.cursorAfterOverride = context.beginRange.PeekByteOffset(long(context.pRegister->text.size()));
                    context.commandResult.modeSwitch = EditorMode::Insert;
                    context.replaceRangeMode = ReplaceRangeMode::Replace;
                    context.op = CommandOperation::Replace;
                }
                else
                {
                    if (context.pRegister->lineWise)
                    {
                        context.beginRange = context.buffer.GetLinePos(context.bufferCursor, LineLocation::LineBegin);
                    }
                    else
                    {
                        context.beginRange = context.bufferCursor;
                    }
                    context.op = CommandOperation::Insert;
                }
            }
            context.commandResult.flags = ZSetFlags(context.commandResult.flags, CommandResultFlags::BeginUndoGroup);
            break;
        }

        case id_InsertMode:
            // TODO: I think this should be a 'command' which would get replayed with dot;
            // instead of special casing it later, we could just insert it into the stream of commands
            // Then undo/redo would replay the insert operation neatly
            context.commandResult.modeSwitch = EditorMode::Insert;
            return true;

        case id_VisualSelectInnerWORD:
            if (GetOperationRange("iW", context.currentMode, context.beginRange, context.endRange))
            {
                m_visualBegin = context.beginRange;
                GetCurrentWindow()->SetBufferCursor(context.endRange - 1);
                UpdateVisualSelection();
                return true;
            }
            return true;

        case id_VisualSelectInnerWord:
            if (GetOperationRange("iw", context.currentMode, context.beginRange, context.endRange))
            {
                m_visualBegin = context.beginRange;
                GetCurrentWindow()->SetBufferCursor(context.endRange - 1);
                UpdateVisualSelection();
                return true;
            }
            break;
        case id_VisualSelectAWord:
            if (GetOperationRange("aw", context.currentMode, context.beginRange, context.endRange))
            {
                m_visualBegin = context.beginRange;
                GetCurrentWindow()->SetBufferCursor(context.endRange - 1);
                UpdateVisualSelection();
                return true;
            }
            break;
        case id_VisualSelectAWORD:
            if (GetOperationRange("aW", context.currentMode, context.beginRange, context.endRange))
            {
                m_visualBegin = context.beginRange;
                GetCurrentWindow()->SetBufferCursor(context.endRange - 1);
                UpdateVisualSelection();
                return true;
            }
            return true;
        case id_DeleteToLineEnd:
            if (GetOperationRange("$", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
            }
            break;
        case id_VisualDelete:
            // Only in visual mode; delete selected block
            if (GetOperationRange("visual", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
                context.commandResult.modeSwitch = DefaultMode();
            }
            break;
        case id_DeleteLine:
            if (GetOperationRange("line", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::DeleteLines;
                context.commandResult.modeSwitch = DefaultMode();
                context.cursorAfterOverride = context.buffer.GetLinePos(context.beginRange, LineLocation::LineBegin);
            }
            break;
        case id_DeleteWord:
            if (GetOperationRange("w", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
            }
            break;
        case id_DeleteWORD:
            if (GetOperationRange("W", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
            }
            break;
        case id_DeleteAWord:
            if (GetOperationRange("aw", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
            }
            break;
        case id_DeleteAWORD:
            if (GetOperationRange("aW", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
            }
            break;
        case id_DeleteInnerWord:
            if (GetOperationRange("iw", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
            }
            break;
        case id_DeleteInnerWORD:
            if (GetOperationRange("iW", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
            }
            break;
        case id_ChangeToLineEnd:
            if (GetOperationRange("$", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
                context.commandResult.modeSwitch = EditorMode::Insert;
            }
            break;
        case id_VisualChange:
            // Only in visual mode; delete selected block
            if (GetOperationRange("visual", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
                context.commandResult.modeSwitch = EditorMode::Insert;
            }
            break;
        case id_ChangeLine:
            if (GetOperationRange("line", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::DeleteLines;
                context.commandResult.modeSwitch = EditorMode::Insert;
            }
            break;
        case id_ChangeWord:
            if (GetOperationRange("cw", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
                context.commandResult.modeSwitch = EditorMode::Insert;
            }
            break;
        case id_ChangeWORD:
            if (GetOperationRange("cW", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
                context.commandResult.modeSwitch = EditorMode::Insert;
            }
            break;
        case id_ChangeAWord:
            if (GetOperationRange("aw", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
                context.commandResult.modeSwitch = EditorMode::Insert;
            }
            break;
        case id_ChangeAWORD:
            if (GetOperationRange("aW", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
                context.commandResult.modeSwitch = EditorMode::Insert;
            }
            break;
        case id_ChangeInnerWord:
            if (GetOperationRange("iw", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
                context.commandResult.modeSwitch = EditorMode::Insert;
            }
            break;
        case id_ChangeInnerWORD:
            if (GetOperationRange("iW", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
                context.commandResult.modeSwitch = EditorMode::Insert;
            }
            break;
        case id_SubstituteLine:
            // Delete whole line and go to insert mode
            context.beginRange = context.buffer.GetLinePos(context.bufferCursor, LineLocation::LineBegin);
            context.endRange = context.buffer.GetLinePos(context.bufferCursor, LineLocation::LineCRBegin);
            context.op = CommandOperation::Delete;
            context.commandResult.modeSwitch = EditorMode::Insert;
            break;
        case id_Substitute:
            // Only in visual mode; delete selected block and go to insert mode
            // Just delete under m_bufferCursor and insert
            if (GetOperationRange("cursor", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
                context.commandResult.modeSwitch = EditorMode::Insert;
            }
            break;
        case id_VisualSubstitute:
            if (GetOperationRange("visual", context.currentMode, context.beginRange, context.endRange))
            {
                context.op = CommandOperation::Delete;
                context.commandResult.modeSwitch = EditorMode::Insert;
            }
            break;
        case id_Find:
            if (!context.keymap.captureChars.empty())
            {
                GetCurrentWindow()->SetBufferCursor(context.buffer.FindOnLineMotion(bufferCursor, (const uint8_t*)&context.keymap.captureChars[0], Direction::Forward));
                m_lastFind = context.keymap.captureChars[0];
                m_lastFindDirection = Direction::Forward;
            }
            return true;
        case id_FindBackwards:
            if (!context.keymap.captureChars.empty())
            {
                GetCurrentWindow()->SetBufferCursor(context.buffer.FindOnLineMotion(bufferCursor, (const uint8_t*)&context.keymap.captureChars[0], Direction::Backward));
                m_lastFind = context.keymap.captureChars[0];
                m_lastFindDirection = Direction::Backward;
            }
            return true;
        case id_FindNext:
            GetCurrentWindow()->SetBufferCursor(context.buffer.FindOnLineMotion(bufferCursor, (const uint8_t*)m_lastFind.c_str(), m_lastFindDirection));
            return true;
        case id_Append:
            // Cursor append
            cursorItr.MoveClamped(1, LineLocation::LineCRBegin);
            GetCurrentWindow()->SetBufferCursor(cursorItr);
            context.commandResult.modeSwitch = EditorMode::Insert;
            return true;
        case id_AppendToLine:
        {
            GlyphIterator appendItr = context.buffer.GetLinePos(bufferCursor, LineLocation::LineLastNonCR);
            appendItr.MoveClamped(1, LineLocation::LineCRBegin);
            GetCurrentWindow()->SetBufferCursor(appendItr);
            context.commandResult.modeSwitch = EditorMode::Insert;
            return true;
        }
        case id_InsertAtFirstChar:
            GetCurrentWindow()->SetBufferCursor(context.buffer.GetLinePos(bufferCursor, LineLocation::LineFirstGraphChar));
            context.commandResult.modeSwitch = EditorMode::Insert;
            return true;
        case id_MotionNextFirstChar:
            GetCurrentWindow()->MoveCursorY(1);
            GetCurrentWindow()->SetBufferCursor(context.buffer.GetLinePos(GetCurrentWindow()->GetBufferCursor(), LineLocation::LineBegin));
            return true;
        case id_Replace:
            if (!context.keymap.captureChars.empty())
            {
                context.commandResult.flags |= CommandResultFlags::HandledCount;

                if (!bufferCursor.PeekByteOffset(context.keymap.TotalCount()).Valid())
                {
                    // Outside the valid buffer; an invalid replace with count!
                    return true;
                }

                context.replaceRangeMode = ReplaceRangeMode::Fill;
                context.op = CommandOperation::Replace;
                context.tempReg.text = context.keymap.captureChars[0];
                context.pRegister = &context.tempReg;

                // Get the range from visual, or use the cursor location
                if (!GetOperationRange("visual", context.currentMode, context.beginRange, context.endRange))
                {
                    context.beginRange = cursorItr;
                    context.endRange = cursorItr.PeekLineClamped(context.keymap.TotalCount(), LineLocation::LineCRBegin);
                }

                context.commandResult.modeSwitch = DefaultMode();
            }
            break;
        case id_ChangeToChar:
            if (!context.keymap.captureChars.empty())
            {
                context.beginRange = bufferCursor;
                context.endRange = buffer.FindOnLineMotion(bufferCursor, (const uint8_t*)&context.keymap.captureChars[0], Direction::Forward);
                context.op = CommandOperation::Delete;
                context.commandResult.modeSwitch = EditorMode::Insert;
            }
            break;
        case id_DeleteToChar:
            if (!context.keymap.captureChars.empty())
            {
                context.beginRange = bufferCursor;
                context.endRange = buffer.FindOnLineMotion(bufferCursor, (const uint8_t*)&context.keymap.captureChars[0], Direction::Forward);
                context.op = CommandOperation::Delete;
            }
            break;

        default:
            if (m_currentMode == EditorMode::Visual && m_visualBegin != m_visualEnd)
            {
                // Clamp and orient the correct way around
                GlyphIterator startOffset = m_visualBegin.Clamped();
                GlyphIterator endOffset = m_visualEnd.Clamped();

                if (startOffset > endOffset)
                {
                    std::swap(startOffset, endOffset);
                }
                context.beginRange = startOffset;
                context.endRange = endOffset;
                context.op = CommandOperation::Replace;
                context.replaceRangeMode = ReplaceRangeMode::Replace;
            }
            else
            {
                context.beginRange = context.bufferCursor;
                context.op = CommandOperation::Insert;
            }

            context.commandResult.modeSwitch = EditorMode::Insert;
            bool beginUndoGroup = false;

            switch (mappedCommand)
            {
            case id_InsertTab:
                if (buffer.HasFileFlags(FileFlags::InsertTabs))
                    context.tempReg.text = "\t";
                else
                    context.tempReg.text = "    ";
                context.pRegister = &context.tempReg;
                beginUndoGroup = true;
                break;
            case id_InsertCarriageReturn:
                context.tempReg.text = "\n";
                context.pRegister = &context.tempReg;
                beginUndoGroup = true;
                break;
            default:
                // No command match at this point means its verbatim insert/replace. If its just
                // a key combo at this point, then abort out.
                if (context.keymap.isCommandToken)
                    return false;
                context.tempReg.text = context.keymap.commandWithoutGroups;
                context.pRegister = &context.tempReg;
                context.commandResult.flags |= CommandResultFlags::HandledCount;
                beginUndoGroup = (context.fullCommand == " ");
                break;
            }

            // Insert grouping command if necessary
            if (beginUndoGroup)
            {
                context.commandResult.flags = ZSetFlags(context.commandResult.flags, CommandResultFlags::BeginUndoGroup, shouldGroupInserts);
            }
            break;
        }
    }

    if (buffer.HasFileFlags(Zep::FileFlags::ReadOnly))
    {
        switch (context.op)
        {
        case CommandOperation::Delete:
        case CommandOperation::DeleteLines:
        case CommandOperation::Insert:
        case CommandOperation::Replace:
        case CommandOperation::Paste:
            return false;

        default:
            break;
        }
    }

    // Update the registers based on context state
    context.UpdateRegisters();

    // Setup command, if any
    if (context.op == CommandOperation::Delete || context.op == CommandOperation::DeleteLines)
    {
        auto cmd = std::make_shared<ZepCommand_DeleteRange>(
            context.buffer,
            context.beginRange,
            context.endRange,
            context.bufferCursor,
            context.cursorAfterOverride);
        context.commandResult.spCommand = std::static_pointer_cast<ZepCommand>(cmd);
        context.commandResult.flags = ZSetFlags(context.commandResult.flags, CommandResultFlags::BeginUndoGroup);
        return true;
    }
    else if (context.op == CommandOperation::Insert && !context.pRegister->text.empty())
    {
        auto cmd = std::make_shared<ZepCommand_Insert>(
            context.buffer,
            context.beginRange,
            context.pRegister->text,
            context.bufferCursor,
            context.cursorAfterOverride);
        context.commandResult.spCommand = std::static_pointer_cast<ZepCommand>(cmd);
        return true;
    }
    else if (context.op == CommandOperation::Replace && !context.pRegister->text.empty())
    {
        auto cmd = std::make_shared<ZepCommand_ReplaceRange>(
            context.buffer,
            context.replaceRangeMode,
            context.beginRange,
            context.endRange,
            context.pRegister->text,
            context.bufferCursor,
            context.cursorAfterOverride);
        context.commandResult.spCommand = std::static_pointer_cast<ZepCommand>(cmd);
        return true;
    }
    else if (context.op == CommandOperation::Copy || context.op == CommandOperation::CopyLines)
    {
        // Put the cursor where the command says it should be
        GetCurrentWindow()->SetBufferCursor(context.cursorAfterOverride);
        return true;
    }

    return false;
} // namespace Zep

void ZepMode::ResetCommand()
{
    m_currentCommand.clear();
}

bool ZepMode::GetOperationRange(const std::string& op, EditorMode currentMode, GlyphIterator& beginRange, GlyphIterator& endRange) const
{
    auto& buffer = GetCurrentWindow()->GetBuffer();
    const auto bufferCursor = GetCurrentWindow()->GetBufferCursor();

    beginRange = GlyphIterator();
    if (op == "visual")
    {
        if (currentMode == EditorMode::Visual)
        {
            auto range = GetInclusiveVisualRange();
            beginRange = range.first;
            endRange = range.second.Peek(1);
        }
    }
    // Whole line
    else if (op == "line")
    {
        beginRange = buffer.GetLinePos(bufferCursor, LineLocation::LineBegin);
        endRange = buffer.GetLinePos(bufferCursor, LineLocation::BeyondLineEnd);

        // Special case; if this is the last line, remove the previous newline in favour of the terminator
        if (endRange.Char() == 0)
        {
            beginRange.Move(-1);
        }
    }
    else if (op == "$")
    {
        beginRange = bufferCursor;
        endRange = buffer.GetLinePos(bufferCursor, LineLocation::LineCRBegin);
    }
    else if (op == "w")
    {
        beginRange = bufferCursor;
        endRange = buffer.WordMotion(bufferCursor, SearchType::Word, Direction::Forward);
    }
    else if (op == "cw")
    {
        // Change word doesn't extend over the next space
        beginRange = bufferCursor;
        endRange = buffer.ChangeWordMotion(bufferCursor, SearchType::Word, Direction::Forward);
    }
    else if (op == "cW")
    {
        beginRange = bufferCursor;
        endRange = buffer.ChangeWordMotion(bufferCursor, SearchType::WORD, Direction::Forward);
    }
    else if (op == "W")
    {
        beginRange = bufferCursor;
        endRange = buffer.WordMotion(bufferCursor, SearchType::WORD, Direction::Forward);
    }
    else if (op == "aw")
    {
        auto range = buffer.AWordMotion(bufferCursor, SearchType::Word);
        beginRange = range.first;
        endRange = range.second;
    }
    else if (op == "aW")
    {
        auto range = buffer.AWordMotion(bufferCursor, SearchType::WORD);
        beginRange = range.first;
        endRange = range.second;
    }
    else if (op == "iw")
    {
        auto range = buffer.InnerWordMotion(bufferCursor, SearchType::Word);
        beginRange = range.first;
        endRange = range.second;
    }
    else if (op == "iW")
    {
        auto range = buffer.InnerWordMotion(bufferCursor, SearchType::WORD);
        beginRange = range.first;
        endRange = range.second;
    }
    else if (op == "cursor")
    {
        auto cursorItr = bufferCursor;
        beginRange = cursorItr;
        endRange = cursorItr.PeekLineClamped(1);
    }
    return beginRange.Valid();
}

void ZepMode::UpdateVisualSelection()
{
    // Visual mode update - after a command
    if (m_currentMode == EditorMode::Visual)
    {
        // Update the visual range
        if (m_lineWise)
        {
            m_visualEnd = GetCurrentWindow()->GetBuffer().GetLinePos(GetCurrentWindow()->GetBufferCursor(), LineLocation::LineCRBegin);
        }
        else
        {
            m_visualEnd = GetCurrentWindow()->GetBufferCursor();
        }

        auto range = GetInclusiveVisualRange();
        GetCurrentWindow()->GetBuffer().SetSelection(range);
    }
}

bool ZepMode::HandleExCommand(std::string strCommand)
{
    if (strCommand.empty())
        return false;

    auto eraseExtKey = [](std::string& str) {
        auto pos = str.find_last_of('<');
        if (pos != std::string::npos)
        {
            str.erase(pos, str.size() - pos);
        }
    };

    if (m_lastKey == ExtKeys::BACKSPACE)
    {
        eraseExtKey(strCommand);

        // Remove the previous character
        if (!strCommand.empty())
            strCommand.pop_back();

        if (strCommand.empty())
        {
            GetCurrentWindow()->SetBufferCursor(m_exCommandStartLocation);
            return true;
        }

        m_currentCommand = strCommand;
        return false;
    }

    if (m_lastKey == ExtKeys::ESCAPE)
    {
        GetCurrentWindow()->SetBufferCursor(m_exCommandStartLocation);
        return true;
    }

    if (m_lastKey == ExtKeys::RETURN)
    {
        assert(GetCurrentWindow());

        auto& buffer = GetCurrentWindow()->GetBuffer();
        auto bufferCursor = GetCurrentWindow()->GetBufferCursor();

        if (strCommand[0] == '/' || strCommand[0] == '?')
        {
            // Just exit Ex mode when finished the search
            return true;
        }

        // Remove the return
        eraseExtKey(strCommand);
        if (strCommand == "")
        {
            return false;
        }

        if (GetEditor().Broadcast(std::make_shared<ZepMessage>(Msg::HandleCommand, strCommand)))
        {
            return true;
        }

        auto pCommand = GetEditor().FindExCommand(strCommand.substr(1));
        if (pCommand)
        {
            auto strTok = string_split(strCommand, " ");
            pCommand->Run(strTok);
        }
        else if (strCommand == ":reg")
        {
            std::ostringstream str;
            str << "--- Registers ---" << '\n';
            for (auto& reg : GetEditor().GetRegisters())
            {
                if (!reg.second.text.empty())
                {
                    std::string displayText = reg.second.text;
                    displayText = string_replace(displayText, "\n", "^J");
                    displayText = string_replace(displayText, "\r", "");
                    str << "\"" << reg.first << "   " << displayText << '\n';
                }
            }
            GetEditor().SetCommandText(str.str());
        }
        else if (strCommand == ":map")
        {
            std::ostringstream str;

            // TODO: CM: this overflows; need to page the output
            str << "--- Mappings ---" << std::endl;
            str << "Normal Maps:" << std::endl;
            keymap_dump(m_normalMap, str);
            str << "Insert Maps:" << std::endl;
            keymap_dump(m_insertMap, str);
            str << "Visual Maps:" << std::endl;
            keymap_dump(m_visualMap, str);

            auto pMapBuffer = GetEditor().GetEmptyBuffer("Mappings");

            pMapBuffer->SetFileFlags(FileFlags::Locked | FileFlags::ReadOnly);
            pMapBuffer->SetText(str.str());
            GetEditor().GetActiveTabWindow()->AddWindow(pMapBuffer, nullptr, RegionLayoutType::VBox);
        }
        else if (strCommand.find(":tabedit") == 0)
        {
            auto pTab = GetEditor().AddTabWindow();
            auto strTok = string_split(strCommand, " ");
            if (strTok.size() > 1)
            {
                if (strTok[1] == "%")
                {
                    pTab->AddWindow(&buffer, nullptr, RegionLayoutType::HBox);
                }
                else
                {
                    auto fname = strTok[1];
                    auto pBuffer = GetEditor().GetFileBuffer(fname);
                    pTab->AddWindow(pBuffer, nullptr, RegionLayoutType::HBox);
                }
            }
            GetEditor().SetCurrentTabWindow(pTab);
        }
        else if (strCommand.find(":tree") == 0)
        {
            GetEditor().AddTree();
        }
        else if (strCommand.find(":vsplit") == 0)
        {
            auto pTab = GetEditor().GetActiveTabWindow();
            auto strTok = string_split(strCommand, " ");
            if (strTok.size() > 1)
            {
                if (strTok[1] == "%")
                {
                    pTab->AddWindow(&GetCurrentWindow()->GetBuffer(), GetCurrentWindow(), RegionLayoutType::HBox);
                }
                else
                {
                    auto fname = strTok[1];
                    auto pBuffer = GetEditor().GetFileBuffer(fname);
                    pTab->AddWindow(pBuffer, GetCurrentWindow(), RegionLayoutType::HBox);
                }
            }
            else
            {
                pTab->AddWindow(&GetCurrentWindow()->GetBuffer(), GetCurrentWindow(), RegionLayoutType::HBox);
            }
        }
        else if (strCommand.find(":hsplit") == 0 || strCommand.find(":split") == 0)
        {
            auto pTab = GetEditor().GetActiveTabWindow();
            auto strTok = string_split(strCommand, " ");
            if (strTok.size() > 1)
            {
                if (strTok[1] == "%")
                {
                    pTab->AddWindow(&GetCurrentWindow()->GetBuffer(), GetCurrentWindow(), RegionLayoutType::VBox);
                }
                else
                {
                    auto fname = strTok[1];
                    auto pBuffer = GetEditor().GetFileBuffer(fname);
                    pTab->AddWindow(pBuffer, GetCurrentWindow(), RegionLayoutType::VBox);
                }
            }
            else
            {
                pTab->AddWindow(&GetCurrentWindow()->GetBuffer(), GetCurrentWindow(), RegionLayoutType::VBox);
            }
        }
        else if (strCommand.find(":e") == 0)
        {
            auto strTok = string_split(strCommand, " ");
            if (strTok.size() > 1)
            {
                auto fname = strTok[1];
                auto pBuffer = GetEditor().GetFileBuffer(fname);
                GetCurrentWindow()->SetBuffer(pBuffer);
            }
        }
        else if (strCommand.find(":w") == 0)
        {
            auto strTok = string_split(strCommand, " ");
            if (strTok.size() > 1)
            {
                auto fname = strTok[1];
                GetCurrentWindow()->GetBuffer().SetFilePath(fname);
            }
            GetEditor().SaveBuffer(GetCurrentWindow()->GetBuffer());
        }
        else if (strCommand == ":close" || strCommand == ":clo")
        {
            GetEditor().GetActiveTabWindow()->CloseActiveWindow();
        }
        else if (strCommand[1] == 'q')
        {
            if (strCommand == ":q")
            {
                GetEditor().GetActiveTabWindow()->CloseActiveWindow();
            }
        }
        else if (strCommand.find(":ZConfigPath") == 0)
        {
            GetEditor().SetCommandText(GetEditor().GetFileSystem().GetConfigPath().string());
        }
        else if (strCommand.find(":ZConfig") == 0)
        {
            auto pBuffer = GetEditor().GetFileBuffer(GetEditor().GetFileSystem().GetConfigPath() / "zep.cfg");
            GetCurrentWindow()->SetBuffer(pBuffer);
        }
        else if (strCommand.find(":cd") == 0)
        {
            GetEditor().SetCommandText(GetEditor().GetFileSystem().GetWorkingDirectory().string());
        }
        else if (strCommand.find(":ZTestFloatSlider") == 0)
        {
            //auto line = buffer.GetBufferLine(bufferCursor);
            auto pSlider = std::make_shared<FloatSlider>(GetEditor(), 4);

            auto spMarker = std::make_shared<RangeMarker>(buffer);
            spMarker->SetRange(ByteRange(bufferCursor.Index(), bufferCursor.Peek(1).Index()));
            spMarker->spWidget = pSlider;
            spMarker->markerType = RangeMarkerType::LineWidget;
            spMarker->displayType = RangeMarkerDisplayType::Hidden;
        }
        else if (strCommand.find(":ZTestColorPicker") == 0)
        {
            //auto line = buffer.GetBufferLine(bufferCursor);
            auto pPicker = std::make_shared<ColorPicker>(GetEditor());
            auto spMarker = std::make_shared<RangeMarker>(buffer);
            spMarker->SetRange(ByteRange(bufferCursor.Index(), bufferCursor.Peek(1).Index()));
            spMarker->spWidget = pPicker;
            spMarker->markerType = RangeMarkerType::Widget;
            spMarker->displayType = RangeMarkerDisplayType::Background;
        }
        else if (strCommand.find(":ZTestFlash") == 0)
        {
            if (buffer.GetSyntax())
            {
                FlashType flashType = FlashType::Flash;
                float time = 1.0f;
                auto strTok = string_split(strCommand, " ");
                if (strTok.size() > 1)
                {
                    if (std::stoi(strTok[1]) > 0)
                    {
                        flashType = FlashType::Flash;
                    }
                }
                if (strTok.size() > 2)
                {
                    try
                    {
                        time = std::stof(strTok[2]);
                    }
                    catch (std::exception&)
                    {
                    }
                }
                buffer.BeginFlash(time, flashType, GlyphRange(buffer.Begin(), buffer.End()));
            }
        }
        else if (strCommand.find(":ZTestMarkers") == 0)
        {
            static uint32_t unique = 0;
            int markerSelection = 0;
            auto strTok = string_split(strCommand, " ");
            if (strTok.size() > 1)
            {
                markerSelection = std::stoi(strTok[1]);
            }
            auto spMarker = std::make_shared<RangeMarker>(buffer);
            GlyphIterator start;
            GlyphIterator end;

            if (GetCurrentWindow()->GetBuffer().HasSelection())
            {
                // Markers are exclusive
                auto range = GetCurrentWindow()->GetBuffer().GetInclusiveSelection();
                start = range.first;
                end = range.second.Peek(1);
            }
            else
            {
                start = buffer.GetLinePos(bufferCursor, LineLocation::LineFirstGraphChar);
                end = buffer.GetLinePos(bufferCursor, LineLocation::LineLastGraphChar) + 1;
            }
            spMarker->SetRange(ByteRange(start.Index(), end.Index()));
            switch (markerSelection)
            {
            case 5:
                spMarker->SetColors(ThemeColor::Error, ThemeColor::Text, ThemeColor::Error);
                spMarker->SetName("All Marker");
                spMarker->SetDescription("This is an example tooltip\nThey can be added to any range of characters");
                spMarker->displayType = RangeMarkerDisplayType::All;
                break;
            case 4:
                spMarker->SetColors(ThemeColor::Error, ThemeColor::Text, ThemeColor::Error);
                spMarker->SetName("Filled Marker");
                spMarker->SetDescription("This is an example tooltip\nThey can be added to any range of characters");
                spMarker->displayType = RangeMarkerDisplayType::Tooltip | RangeMarkerDisplayType::Underline | RangeMarkerDisplayType::Indicator | RangeMarkerDisplayType::Background;
                break;
            case 3:
                spMarker->SetColors(ThemeColor::Background, ThemeColor::Text, GetEditor().GetTheme().GetUniqueColor(unique++));
                spMarker->SetName("Underline Marker");
                spMarker->SetDescription("This is an example tooltip\nThey can be added to any range of characters");
                spMarker->displayType = RangeMarkerDisplayType::Tooltip | RangeMarkerDisplayType::Underline | RangeMarkerDisplayType::CursorTip;
                break;
            case 2:
                spMarker->SetColors(ThemeColor::Background, ThemeColor::Text, ThemeColor::Warning);
                spMarker->SetName("Tooltip");
                spMarker->SetDescription("This is an example tooltip\nThey can be added to any range of characters");
                spMarker->displayType = RangeMarkerDisplayType::Tooltip;
                break;
            case 1:
                spMarker->SetColors(ThemeColor::Background, ThemeColor::Text, ThemeColor::Warning);
                spMarker->SetName("Warning");
                spMarker->SetDescription("This is an example warning mark");
                break;
            case 0:
            default:
                spMarker->SetColors(ThemeColor::Background, ThemeColor::Text, ThemeColor::Error);
                spMarker->SetName("Error");
                spMarker->SetDescription("This is an example error mark");
            }
            SwitchMode(DefaultMode());
        }
        else if (strCommand == ":ZTabs")
        {
            buffer.ToggleFileFlag(FileFlags::InsertTabs);
        }
        else if (strCommand == ":ZShowCR")
        {
            GetCurrentWindow()->ToggleFlag(WindowFlags::ShowCR);
        }
        else if (strCommand == ":ZShowLineNumbers")
        {
            GetCurrentWindow()->ToggleFlag(WindowFlags::ShowLineNumbers);
        }
        else if (strCommand == ":ZWrapText")
        {
            // Wrapping is not fully supported yet, but useful for the Orca optional mode.
            // To enable wrapping fully, the editor needs to scroll in X as well as Y...
            GetCurrentWindow()->ToggleFlag(WindowFlags::WrapText);
        }
        else if (strCommand == ":ZShowIndicators")
        {
            GetCurrentWindow()->ToggleFlag(WindowFlags::ShowIndicators);
        }
        else if (strCommand == ":ZShowInput")
        {
            GetEditor().GetConfig().showNormalModeKeyStrokes = !GetEditor().GetConfig().showNormalModeKeyStrokes;
        }
        else if (strCommand == ":ZThemeToggle")
        {
            // An easy test command to check per-buffer themeing
            // Just gets the current theme on the buffer and makes a new
            // one that is opposite
            auto theme = GetCurrentWindow()->GetBuffer().GetTheme();
            auto spNewTheme = std::make_shared<ZepTheme>();
            if (theme.GetThemeType() == ThemeType::Dark)
            {
                spNewTheme->SetThemeType(ThemeType::Light);
            }
            else
            {
                spNewTheme->SetThemeType(ThemeType::Dark);
            }
            GetCurrentWindow()->GetBuffer().SetTheme(spNewTheme);
        }
        else if (strCommand == ":ls")
        {
            std::ostringstream str;
            str << "--- buffers ---" << '\n';
            int index = 0;
            for (auto& editor_buffer : GetEditor().GetBuffers())
            {
                if (!editor_buffer->GetName().empty())
                {
                    std::string displayText = editor_buffer->GetName();
                    displayText = string_replace(displayText, "\n", "^J");
                    if (editor_buffer->IsHidden())
                    {
                        str << "h";
                    }
                    else
                    {
                        str << " ";
                    }

                    if (&GetCurrentWindow()->GetBuffer() == editor_buffer.get())
                    {
                        str << "*";
                    }
                    else
                    {
                        str << " ";
                    }

                    if (editor_buffer->HasFileFlags(FileFlags::Dirty))
                    {
                        str << "+";
                    }
                    else
                    {
                        str << " ";
                    }
                    str << index++ << " : " << displayText << '\n';
                }
            }
            GetEditor().SetCommandText(str.str());
        }
        else if (strCommand.find(":bu") == 0)
        {
            auto strTok = string_split(strCommand, " ");

            if (strTok.size() > 1)
            {
                try
                {
                    auto index = std::stoi(strTok[1]);
                    auto current = 0;
                    for (auto& editor_buffer : GetEditor().GetBuffers())
                    {
                        if (index == current)
                        {
                            GetCurrentWindow()->SetBuffer(editor_buffer.get());
                        }
                        current++;
                    }
                }
                catch (std::exception&)
                {
                }
            }
        }
        else
        {
            GetEditor().SetCommandText("Not a command");
        }
        return true;
    }
    else if (!m_currentCommand.empty() && (m_currentCommand[0] == '/' || m_currentCommand[0] == '?'))
    {
        // TODO: Busy editing the search string; do the search
        if (m_currentCommand.length() > 0)
        {
            auto pWindow = GetCurrentWindow();
            auto& buffer = pWindow->GetBuffer();
            auto searchString = m_currentCommand.substr(1);

            buffer.ClearRangeMarkers(RangeMarkerType::Search);

            uint32_t numMarkers = 0;
            GlyphIterator start = buffer.Begin();

            if (!searchString.empty())
            {
                static const uint32_t MaxMarkers = 1000;
                while (numMarkers < MaxMarkers)
                {
                    auto found = buffer.Find(start, (uint8_t*)&searchString[0], (uint8_t*)&searchString[searchString.length()]);
                    if (!found.Valid())
                    {
                        break;
                    }

                    start = found + 1;

                    auto spMarker = std::make_shared<RangeMarker>(buffer);
                    spMarker->SetColors(ThemeColor::VisualSelectBackground, ThemeColor::Text);
                    spMarker->SetRange(ByteRange(found.Index(), found.PeekByteOffset(long(searchString.size())).Index()));
                    spMarker->displayType = RangeMarkerDisplayType::Background;
                    spMarker->markerType = RangeMarkerType::Search;

                    numMarkers++;
                }
            }

            Direction dir = (m_currentCommand[0] == '/') ? Direction::Forward : Direction::Backward;
            m_lastSearchDirection = dir;

            // Find the one on or in front of the cursor, in either direction.
            auto startLocation = m_exCommandStartLocation;
            if (dir == Direction::Forward)
                startLocation--;
            else
                startLocation++;

            auto pMark = buffer.FindNextMarker(startLocation, dir, RangeMarkerType::Search);
            if (pMark)
            {
                pWindow->SetBufferCursor(GlyphIterator(&buffer, pMark->GetRange().first));
                pMark->SetBackgroundColor(ThemeColor::Info);
            }
            else
            {
                pWindow->SetBufferCursor(m_exCommandStartLocation);
            }
        }
    }
    return false;
}

const KeyMap& ZepMode::GetKeyMappings(EditorMode mode) const
{
    if (mode == EditorMode::Visual)
    {
        return m_visualMap;
    }
    else if (mode == EditorMode::Normal)
    {
        return m_normalMap;
    }
    return m_insertMap;
}

void ZepMode::AddKeyMapWithCountRegisters(const std::vector<KeyMap*>& maps, const std::vector<std::string>& commands, const StringId& id)
{
    for (auto& m : maps)
    {
        for (auto& c : commands)
        {
            keymap_add({ m }, { "<D><R>" + c }, id);
            keymap_add({ m }, { "<R>" + c }, id);
            keymap_add({ m }, { "<D>" + c }, id);
            keymap_add({ m }, { c }, id);
        }
    }
}

void ZepMode::AddNavigationKeyMaps(bool allowInVisualMode)
{
    std::vector<KeyMap*> navigationMaps = { &m_normalMap };
    if (allowInVisualMode)
    {
        navigationMaps.push_back(&m_visualMap);
    }

    // Up/Down/Left/Right
    AddKeyMapWithCountRegisters(navigationMaps, { "j", "<Down>" }, id_MotionDown);
    AddKeyMapWithCountRegisters(navigationMaps, { "k", "<Up>" }, id_MotionUp);
    AddKeyMapWithCountRegisters(navigationMaps, { "l", "<Right>" }, id_MotionRight);
    AddKeyMapWithCountRegisters(navigationMaps, { "h", "<Left>" }, id_MotionLeft);

    // Page Motions
    AddKeyMapWithCountRegisters(navigationMaps, { "<C-f>", "<PageDown>" }, id_MotionPageForward);
    AddKeyMapWithCountRegisters(navigationMaps, { "<C-b>", "<PageUp>" }, id_MotionPageBackward);
    AddKeyMapWithCountRegisters(navigationMaps, { "<C-d>" }, id_MotionHalfPageForward);
    AddKeyMapWithCountRegisters(navigationMaps, { "<C-u>" }, id_MotionHalfPageBackward);
    AddKeyMapWithCountRegisters(navigationMaps, { "G" }, id_MotionGotoLine);

    // Line Motions
    AddKeyMapWithCountRegisters(navigationMaps, { "$" }, id_MotionLineEnd);
    AddKeyMapWithCountRegisters(navigationMaps, { "^" }, id_MotionLineFirstChar);
    keymap_add(navigationMaps, { "0" }, id_MotionLineBegin);

    // Word motions
    AddKeyMapWithCountRegisters(navigationMaps, { "w" }, id_MotionWord);
    AddKeyMapWithCountRegisters(navigationMaps, { "b" }, id_MotionBackWord);
    AddKeyMapWithCountRegisters(navigationMaps, { "W" }, id_MotionWORD);
    AddKeyMapWithCountRegisters(navigationMaps, { "B" }, id_MotionBackWORD);
    AddKeyMapWithCountRegisters(navigationMaps, { "e" }, id_MotionEndWord);
    AddKeyMapWithCountRegisters(navigationMaps, { "E" }, id_MotionEndWORD);
    AddKeyMapWithCountRegisters(navigationMaps, { "ge" }, id_MotionBackEndWord);
    AddKeyMapWithCountRegisters(navigationMaps, { "gE" }, id_MotionBackEndWORD);
    AddKeyMapWithCountRegisters(navigationMaps, { "gg" }, id_MotionGotoBeginning);

    // Navigate between splits
    keymap_add(navigationMaps, { "<C-j>" }, id_MotionDownSplit);
    keymap_add(navigationMaps, { "<C-l>" }, id_MotionRightSplit);
    keymap_add(navigationMaps, { "<C-k>" }, id_MotionUpSplit);
    keymap_add(navigationMaps, { "<C-h>" }, id_MotionLeftSplit);

    // Arrows always navigate in insert mode
    keymap_add({ &m_insertMap }, { "<Down>" }, id_MotionDown);
    keymap_add({ &m_insertMap }, { "<Up>" }, id_MotionUp);
    keymap_add({ &m_insertMap }, { "<Right>" }, id_MotionRight);
    keymap_add({ &m_insertMap }, { "<Left>" }, id_MotionLeft);
}

void ZepMode::AddSearchKeyMaps()
{
    // Normal mode searching
    AddKeyMapWithCountRegisters({ &m_normalMap }, { "f<.>" }, id_Find);
    AddKeyMapWithCountRegisters({ &m_normalMap }, { "F<.>" }, id_FindBackwards);
    AddKeyMapWithCountRegisters({ &m_normalMap }, { ";" }, id_FindNext);
    AddKeyMapWithCountRegisters({ &m_normalMap }, { "n" }, id_MotionNextSearch);
    AddKeyMapWithCountRegisters({ &m_normalMap }, { "N" }, id_MotionPreviousSearch);
    keymap_add({ &m_normalMap }, { "<F8>" }, id_MotionNextMarker);
    keymap_add({ &m_normalMap }, { "<S-F8>" }, id_MotionPreviousMarker);
}

void ZepMode::AddGlobalKeyMaps()
{
    // Global bits
    keymap_add({ &m_normalMap, &m_insertMap }, { "<C-p>", "<C-,>" }, id_QuickSearch);
    keymap_add({ &m_normalMap }, { ":", "/", "?" }, id_ExMode);
    keymap_add({ &m_normalMap }, { "H" }, id_PreviousTabWindow);
    keymap_add({ &m_normalMap }, { "L" }, id_NextTabWindow);
    keymap_add({ &m_normalMap }, { "<C-i><C-o>" }, id_SwitchToAlternateFile);
    keymap_add({ &m_normalMap }, { "+" }, id_FontBigger);
    keymap_add({ &m_normalMap }, { "-" }, id_FontSmaller);
}

CursorType ZepMode::GetCursorType() const
{
    switch (m_currentMode)
    {
    default:
    case EditorMode::None:
    case EditorMode::Ex:
        return CursorType::None;
    case EditorMode::Insert:
        return CursorType::Insert;
    case EditorMode::Normal:
        return CursorType::Normal;
    case EditorMode::Visual:
        return m_visualCursorType;
    }
}

void ZepMode::Begin(ZepWindow* pWindow)
{
    timer_restart(m_lastKeyPressTimer);

    m_pCurrentWindow = pWindow;

    if (pWindow)
    {
        m_visualBegin = pWindow->GetBuffer().Begin();
        m_visualEnd = pWindow->GetBuffer().End();
        pWindow->GetBuffer().ClearSelection();
    }

    // If we are an overlay mode, make sure that the global mode is also begun on the new window
    if (GetEditor().GetGlobalMode() != this)
    {
        GetEditor().GetGlobalMode()->Begin(pWindow);
    }
}

} // namespace Zep
