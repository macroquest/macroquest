-- This is an example of how to use the Zep editor in lua. This demo is not feature complete
-- and some functionality is not implemented yet.

local mq                = require('mq')
local imgui             = require('ImGui')
local zep               = require('Zep')

local PackageMan        = require('mq.PackageMan')
local lfs               = PackageMan.Require('luafilesystem', 'lfs')

---@type Zep.Editor
local editor = nil

local openGUI = true
local shouldDrawGUI = true
local resetPosition = false
local bufferNumber = 1
local bufferTable = {}
local syntaxList = {}
local themeList = zep.GetThemes()

local function GUI()
    if editor == nil then
        editor = zep.Editor.new('##Editor')
        local newBuffer = editor:CreateBuffer("Buffer 1")
        bufferNumber = 2
        table.insert(bufferTable, newBuffer)
        syntaxList = editor:GetSyntaxList()
    end

    local flags = ImGuiWindowFlags.MenuBar
    imgui.SetNextWindowSize(ImVec2(640, 240), resetPosition and ImGuiCond.Always or ImGuiCond.Once)
    resetPosition = false
    imgui.PushStyleVar(ImGuiStyleVar.WindowPadding, ImVec2(1, 0))

    openGUI, shouldDrawGUI = imgui.Begin('Demo Text Editor', openGUI, flags)
    imgui.PopStyleVar()
    if not shouldDrawGUI then
        imgui.End()
        return
    end

    local activeBuffer = editor.activeBuffer

    -- Main menu bar
    if imgui.BeginMenuBar() then
        if imgui.BeginMenu('File') then
            imgui.MenuItem('New')
            imgui.MenuItem('Open')
            imgui.Separator()
            imgui.MenuItem('Save')
            imgui.Separator()
            imgui.MenuItem('Close')

            if imgui.MenuItem('Exit') then
                openGUI = false
            end
            imgui.EndMenu()
        end

        if imgui.BeginMenu('Edit') then

            if imgui.MenuItem('Reset Position') then
                resetPosition = true
            end

            if imgui.BeginMenu('Syntax') then
                local currentSyntax = activeBuffer.syntax
                for _, value in ipairs(syntaxList) do
                    if imgui.MenuItem(value.name, nil, currentSyntax == value.id) then
                        activeBuffer.syntax = value.id
                    end
                end
                imgui.EndMenu()
            end

            if imgui.BeginMenu('Themes') then
                local currentTheme = editor.theme
                for _, value in ipairs(themeList) do
                    if imgui.MenuItem(value.name, nil, currentTheme == value.id) then
                        editor.theme = value.id
                    end
                end
                imgui.EndMenu()
            end

            imgui.EndMenu()
        end

        if imgui.BeginMenu('View') then
            if imgui.MenuItem('Show Whitespace', nil, bit32.band(editor.windowFlags, zep.WindowFlags.ShowWhiteSpace) ~= 0, true) then
                editor:ToggleFlag(zep.WindowFlags.ShowWhiteSpace)
            end
            if imgui.MenuItem('Show Line Endings', nil, bit32.band(editor.windowFlags, zep.WindowFlags.ShowCR) ~= 0, true) then
                editor:ToggleFlag(zep.WindowFlags.ShowCR)
            end
            if imgui.MenuItem('Show Line Numbers', nil, bit32.band(editor.windowFlags, zep.WindowFlags.ShowLineNumbers) ~= 0, true) then
                editor:ToggleFlag(zep.WindowFlags.ShowLineNumbers)
            end
            if imgui.MenuItem('Show Line Background', nil, bit32.band(editor.windowFlags, zep.WindowFlags.ShowLineBackground) ~= 0, true) then
                editor:ToggleFlag(zep.WindowFlags.ShowLineBackground)
            end
            if imgui.MenuItem('Show Airline', nil, bit32.band(editor.windowFlags, zep.WindowFlags.ShowAirLine) ~= 0, true) then
                editor:ToggleFlag(zep.WindowFlags.ShowAirLine)
            end

            imgui.EndMenu()
        end

        imgui.EndMenuBar()
    end
    -- End of menu bar

    local footerHeight = 0 --imgui.GetStyle().ItemSpacing.y + imgui.GetFrameHeightWithSpacing()

    -- Context menu
    if imgui.BeginPopupContextWindow() then
       imgui.EndPopup()
    end
    -- End Context menu

    imgui.PushStyleVar(ImGuiStyleVar.ItemSpacing, ImVec2(0, 0))

    -- Tab Bar
    if imgui.BeginTabBar('##DocumentTabBar') then
        local removeBufferIndex = nil
        local bufferCount = #bufferTable
        -- Draw new tab for each buffer
        for i, buffer in ipairs(bufferTable) do
            local unsaved = buffer:HasFlag(zep.BufferFlags.Dirty)
            local show, open = imgui.BeginTabItem((buffer.displayName or 'Unnamed File') .. '##Tab' .. tostring(i), bufferCount == 1 and nil or true, unsaved and ImGuiTabItemFlags.UnsavedDocument or 0)
            if open then
                if buffer ~= activeBuffer then
                   editor.activeBuffer = buffer
                end
                imgui.EndTabItem()
            end
            if not show then removeBufferIndex = i end
        end
        if imgui.TabItemButton('+') then
            local newBuffer = editor:CreateBuffer(string.format("Buffer %d", bufferNumber))
            bufferNumber = bufferNumber + 1
            table.insert(bufferTable, newBuffer)
        end
        imgui.EndTabBar()

        if removeBufferIndex ~= nil then
            local removedBuffer = bufferTable[removeBufferIndex]
            table.remove(bufferTable, removeBufferIndex)
            editor:RemoveBuffer(removedBuffer)
        end
    end
    -- end Tab Bar

    -- Reduce spacing so everything fits snugly together
    local contentSizeX, contentSizeY = imgui.GetContentRegionAvail()
    contentSizeY = contentSizeY - footerHeight

    editor:Render(ImVec2(contentSizeX, contentSizeY))

    -- Status bar
    imgui.PopStyleVar()
    imgui.SetItemDefaultFocus()

    imgui.End()
end

mq.imgui.init('textEditorGui', GUI)

while openGUI do
    mq.delay(100)
    mq.doevents()
end