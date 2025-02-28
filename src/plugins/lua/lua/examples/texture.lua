
local mq = require 'mq'
local imgui = require 'ImGui'

local isOpen = true
local shouldDraw = true
local filename = "uiresources\\default\\assets\\images\\class.png"

---@type MQTexture | nil
local texture = mq.CreateTexture(filename)
local textureCoords = { 0, 0, 1, 1 }

local function updateImGui()
    -- Don't draw the UI if the UI was closed by pressing the X button
    if not isOpen then return end

    isOpen, shouldDraw = ImGui.Begin('Texture Demo', isOpen)
        if shouldDraw then
            filename = imgui.InputText("Texture File", filename)
            if imgui.Button('Load') then
                texture = mq.CreateTexture(filename)
            end
            imgui.SameLine()
            if imgui.Button('Unload') then
                texture = nil
            end
            
            imgui.Separator()

            if texture ~= nil then
                imgui.Text("Texture Object: %s", texture)
                imgui.Text("File: %s", texture.fileName)
                imgui.Text("Size: %s", texture.size)

                textureCoords = imgui.SliderFloat4("Texture Coordnates", textureCoords, 0, 1)

                imgui.Separator()
                imgui.Image(texture:GetTextureID(), texture.size,
                    ImVec2(textureCoords[1], textureCoords[2]), ImVec2(textureCoords[3], textureCoords[4]))
            end
        end
    ImGui.End()
end

mq.imgui.init('texture', updateImGui)

while isOpen do
    mq.delay(1000)
end