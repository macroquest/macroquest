local mq = require('mq')
local imgui = require('ImGui')
local zep = require('Zep')

local openGUI = true
local shouldDrawGUI = true

---@type Zep.Console
local console = nil
local localEcho = false
local resetPosition = false
local commandBuffer = ''
local setFocus = false

function MakeColorGradient(freq1, freq2, freq3, phase1, phase2, phase3, center, width, length)
    local text = ''

    for i = 1, length do
        local color = IM_COL32(
            math.floor(math.sin(freq1 * i + phase1) * width + center),
            math.floor(math.sin(freq2 * i + phase2) * width + center),
            math.floor(math.sin(freq3 * i + phase3) * width + center)
        )

        text = text .. string.format("\a#%06xx", bit32.band(color, 0xffffff))

        if i % 50 == 0 then
            console:AppendText(text)
            text = ''
        end
    end

    console:AppendText(text)
end

local GUI = function()
    if console == nil then
        console = zep.Console.new("##Console")

        console.eventCallback = function(type, data)
            if type == 'link' then
                -- We can change the color of text by using Push/Pop instead of passing a color to the AppendText call
                console:PushStyleColor(zep.ConsoleCol.Text, IM_COL32(255, 255, 0))
                console:AppendText("Message: %s => %d %d %s", type, data.button, data.modifiers, data.data)
                console:PopStyleColor()
                return true
            end
        end
    end

    local flags = ImGuiWindowFlags.MenuBar
    imgui.SetNextWindowSize(ImVec2(640, 240), resetPosition and ImGuiCond.Always or ImGuiCond.Once)
    imgui.PushStyleVar(ImGuiStyleVar.WindowPadding, ImVec2(1, 0));

    openGUI, shouldDrawGUI = ImGui.Begin('Demo Console Window', openGUI, flags)
    imgui.PopStyleVar()
    if not shouldDrawGUI then
        imgui.End()
        return
    end

    -- Main menu bar
    if imgui.BeginMenuBar() then
        if imgui.BeginMenu('Options') then
            _, console.autoScroll = imgui.MenuItem('Auto-scroll', nil, console.autoScroll)
            _, localEcho = imgui.MenuItem('Local echo', nil, localEcho)

            imgui.Separator()

            if imgui.MenuItem('Close Console') then
                openGUI = false
            end
            if imgui.MenuItem('Reset Position') then
                resetPosition = true
            end

            imgui.Separator()

            if imgui.MenuItem('Clear Console') then
                console:Clear()
            end

            if imgui.BeginMenu('Extras') then

                if imgui.MenuItem('Color Test 1') then
                    console:AppendText("\ayYELLOW    \a-yDARK YELLOW");
                    console:AppendText("\aoORANGE    \a-oDARK ORANGE");
                    console:AppendText("\agGREEN     \a-gDARK GREEN");
                    console:AppendText("\auBLUE      \a-uDARK BLUE");
                    console:AppendText("\arRED       \a-rDARK RED");
                    console:AppendText("\atTEAL      \a-tDARK TEAL");
                    console:AppendText("\abBLACK");
                    console:AppendText("\amMAGENTA   \a-mDARK MAGENTA");
                    console:AppendText("\apPURPLE    \a-pDARK PURPLE");
                    console:AppendText("\awWHITE     \a-wGREY");
                end

                if imgui.MenuItem('Color Test 2') then
                    MakeColorGradient(0.3, 0.3, 0.3, 0, 2, 4, 128, 127, 50)
                end

                if imgui.MenuItem('Insert Hyperlink') then
                    console:PushStyleColor(zep.ConsoleCol.Link, IM_COL32(255, 0, 0))
                    console:PushStyleColor(zep.ConsoleCol.LinkHover, IM_COL32(0, 0, 192))
                    console:PushStyleColor(zep.ConsoleCol.Text, IM_COL32(0, 255, 0))
                    console:AppendHyperlink("LINKDATA", "Link Text"):AppendText(" <-- red link with blue hover")
                    console:PopStyleColor(3)
                end

                imgui.EndMenu()
            end

            imgui.EndMenu()
        end
        imgui.EndMenuBar()
    end
    -- End of menu bar

    local footerHeight = imgui.GetStyle().ItemSpacing.y + imgui.GetFrameHeightWithSpacing()

    if imgui.BeginPopupContextWindow() then
        if imgui.Selectable('Clear') then
            console:Clear()
        end
        imgui.EndPopup()
    end

    -- Reduce spacing so everything fits snugly together
    imgui.PushStyleVar(ImGuiStyleVar.ItemSpacing, ImVec2(0, 0))
    local contentSizeX, contentSizeY = imgui.GetContentRegionAvail()
    contentSizeY = contentSizeY - footerHeight

    console:Render(ImVec2(contentSizeX, contentSizeY))

    -- Command line
    imgui.PushStyleVar(ImGuiStyleVar.WindowPadding, ImVec2(2, 4))
    imgui.Separator()

    local textFlags = bit32.bor(0,
        ImGuiInputTextFlags.EnterReturnsTrue
        -- not implemented yet
        -- ImGuiInputTextFlags.CallbackCompletion,
        -- ImGuiInputTextFlags.CallbackHistory
    )

    imgui.SetCursorPosX(imgui.GetCursorPosX() + 6)
    imgui.SetCursorPosY(imgui.GetCursorPosY() + 4)
    imgui.PushItemWidth(imgui.GetContentRegionAvailVec().x)
    imgui.PushStyleColor(ImGuiCol.FrameBg, ImVec4(0, 0, 0, 0))
    imgui.PushFont(imgui.ConsoleFont)

    local accept = false
    commandBuffer, accept = imgui.InputText('##Input', commandBuffer, textFlags)

    imgui.PopFont()
    imgui.PopStyleColor()
    imgui.PopStyleVar(2)

    if accept then
        ExecCommand(commandBuffer)
        commandBuffer = ''
        setFocus = true
    end

    imgui.SetItemDefaultFocus()

    if setFocus then
        setFocus = false
        imgui.SetKeyboardFocusHere(-1)
    end

    ImGui.End()
end

function StringTrim(s)
    return s:gsub("^%s*(.-)%s*$", "%1")
 end

function ExecCommand(text)
    if localEcho then
        console:AppendText(IM_COL32(128, 128, 128), "> %s", text)
    end

    -- todo: implement history
    if string.len(text) > 0 then

        text = StringTrim(text)
        if text == 'clear' then
            console:Clear()
        elseif string.sub(text, 1, 1) == '/' then
            mq.cmdf("%s", text)
        else
            console:AppendText(IM_COL32(255, 0, 0), "Unknown command: '%s'", text)
        end
    end
end

function EventFunc(text)
    if console ~= nil then
        console:AppendText(text)
    end
end

mq.imgui.init('demoGUI', GUI)
mq.event('echo_all_output', '#*#', EventFunc)

while openGUI do
    mq.delay(100)
    mq.doevents()
end
