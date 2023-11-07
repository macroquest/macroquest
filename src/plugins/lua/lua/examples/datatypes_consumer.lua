local mq = require 'mq'
local imgui = require 'ImGui'

local terminate = false
local isOpen, shouldDraw = true, true

if mq.TLO.ExampleCounter == nil then
    print("\arPlease run the examples/datatypes script first!")
    mq.exit()
end


local ExampleCounter = mq.TLO.ExampleCounter
local inputNumber = 1

local currentCounter = 'default'
local currentIndex = 1

local newCounter = ''

local function updateImGui()
    if not isOpen then return end

    isOpen, shouldDraw = ImGui.Begin('DataTypes Example: Consumer', isOpen)
    if shouldDraw then
        ---This gets us the list of counter names from the other script
        local allCounterNames = mq.TLO.ExampleAllCounters.Keys
        local clicked = false
        currentIndex, clicked = imgui.Combo('Select Counter', currentIndex, allCounterNames(), allCounterNames.Length())
        if clicked then
            currentCounter = allCounterNames.Index(currentIndex)
        end

        local counter = ExampleCounter(currentCounter)
        local value = counter.Value()
        imgui.Text("Name: %s, Value: %d", counter.Name(), value)

        inputNumber, _ = imgui.InputInt("Increment Amount", inputNumber)
        if imgui.Button('Increment') then
            counter.Increment(inputNumber)
        end

        imgui.SameLine()

        if imgui.Button("Reset") then
            counter.Reset()
        end

        imgui.Separator()

        newCounter, _ = imgui.InputText('Counter Name', newCounter)
        imgui.BeginDisabled(#newCounter == 0)
        if imgui.Button('Create New') and #newCounter > 0 then
            ExampleCounter(newCounter).Increment()
            currentCounter = newCounter
            newCounter = ''
        end
        imgui.EndDisabled()
    end
    ImGui.End()
end


mq.imgui.init('datatypes_consumer', updateImGui)

while not terminate do
    mq.delay(1000)
end
