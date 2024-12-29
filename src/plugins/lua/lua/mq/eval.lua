-- eval.lua
local mq = require 'mq'
local imgui = require 'ImGui'

-- GUI Control variables
local openGUI = true
local shouldDrawGUI = true

local inputs = {}
local arguments = { ... }

if #arguments > 0 then
    table.insert(inputs, table.concat(arguments, ' '))
end

local function drawControlButtons()
    if imgui.Button('Add') then
        table.insert(inputs, '')
    end
    imgui.SameLine()
    imgui.PushStyleColor(ImGuiCol.Button, .6, 0, 0, 1)
    if ImGui.Button('Clear') then
        inputs = {}
    end
    imgui.PopStyleColor()
end

local function processInput(input)
    local luaType, mqType = nil, nil
    local success, result = pcall(loadstring, 'local mq = require(\'mq\'); return '..input)
    if success then
        if type(result) == 'function' then
            success, result = pcall(result)
            if success then
                luaType = type(result)
                if luaType == 'userdata' then
                    success, mqType = pcall(mq.gettype, result)
                    if not success then mqType = 'error' end
                end
            end
        end
    end
    return result, luaType, mqType or ''
end

local function handleEvalEntry(input)
    if not input or input:len() == 0 then return end
    -- evaluating 'mq.tlo' causes a client crash, so prevent parsing it and warn about case sensitivity instead.
    local output, outputType, mqType
    if input:lower():find('mq.tlo') and not input:find('mq.TLO') then
        output = '\'mq.TLO\' is case sensitive'
        outputType = 'N/A'
        mqType = 'N/A'
    else
        output, outputType, mqType = processInput(input)
    end
    imgui.TextColored(0,1,1,1,'Output:')
    imgui.SameLine()
    imgui.SetCursorPosX(60)
    imgui.PushTextWrapPos(imgui.GetContentRegionAvail() + 50)
    imgui.Text('%s', output)
    imgui.PopTextWrapPos()
    imgui.TextColored(0,1,1,1,'Type:')
    imgui.SameLine()
    imgui.SetCursorPosX(60)
    imgui.Text('%s', outputType)
    imgui.SameLine()
    imgui.SetCursorPosX(140)
    imgui.TextColored(0,1,1,1,'MQType:')
    imgui.SameLine()
    imgui.SetCursorPosX(200)
    imgui.Text('%s', mqType)
    if outputType == 'userdata' and mqType ~= 'error' then
        imgui.TextColored(0,1,1,1,'Note:')
        imgui.SameLine()
        imgui.SetCursorPosX(60)
        imgui.PushTextWrapPos(imgui.GetContentRegionAvail() + 50)
        imgui.Text('Add () to resolve userdata to a primitive lua type')
        imgui.PopTextWrapPos()
    end
end

local evalui = function()
    openGUI, shouldDrawGUI = imgui.Begin('Lua Expression Evaluator', openGUI)
    if shouldDrawGUI then
        local width, height = imgui.GetWindowSize()
        if width < 350 then imgui.SetWindowSize(350, height) end
        drawControlButtons()

        imgui.PushStyleColor(ImGuiCol.Button, .6, 0, 0, 1)
        for i,_ in ipairs(inputs) do
            imgui.PushItemWidth(width-45)
            inputs[i] = imgui.InputTextWithHint('##input'..i, 'mq.TLO.Me.CleanName()', inputs[i])
            imgui.PopItemWidth()
            imgui.SameLine()

            if imgui.Button('X##'..i) then
                table.remove(inputs, i)
            end

            handleEvalEntry(inputs[i])
        end
        imgui.PopStyleColor()
    end
    imgui.End()
end

mq.imgui.init('LuaExpressionEvaluator', evalui)

while openGUI do
    mq.delay(1000)
end
