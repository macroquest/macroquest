local mq = require 'mq'
local imgui = require 'ImGui'

local terminate = false
local isOpen, shouldDraw = true, true

local function updateImGui()
    if not isOpen then return end

    isOpen, shouldDraw = ImGui.Begin('DataTypes Example: Consumer', isOpen)
    if shouldDraw then
        local value = mq.TLO.Example.Counter()
        imgui.Text("Counter: %d", value)

        if imgui.Button("Reset") then
            mq.TLO.Example.ResetCounter()
        end
    end
    ImGui.End()
end

if mq.TLO.Example == nil then
    print("\arPlease run the examples/datatypes script first!")
    mq.exit()
end

mq.imgui.init('datatypes_consumer', updateImGui)

while not terminate do
    mq.delay(1000)
end
