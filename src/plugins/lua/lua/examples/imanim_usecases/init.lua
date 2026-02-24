-- imanim_demo.lua — Mockup UI usecases showcasing im_anim.h in real-world scenarios.
-- Ported from im_anim_usecases.cpp
-- Original Author: Soufiane KHIAT
--
-- Usage: /lua run examples/imanim_usecases

local mq = require('mq')
local imgui = require('ImGui')

local common = require('common')

local RunButtonsAndIndicatorsDemo = require('buttons_and_indicators')
local RunNavigationAndMenusDemo = require('navigation_and_menus')
local RunDialogsAndModalsDemo = require('dialogs_and_modals')
local RunLoadingAndProgressDemo = require('loading_and_progress')
local RunInputControlsDemo = require('input_controls')
local RunCardsAndContentDemo = require('cards_and_content')
local RunTextAndDisplayDemo = require('text_and_display')
local RunVisualEffectsDemo = require('visual_effects')
local RunVfxGameTimelineToolsDemo = require('vfx_game_timeline_tools')
local RunDataVisualizationDemo = require('data_visualization')

local openGUI = true

-- ============================================================
-- MAIN USECASE WINDOW
-- ============================================================
local function ImAnimUsecaseWindow()
    if not openGUI then
        return
    end

    imgui.SetNextWindowSize(ImVec2(700, 800), ImGuiCond.FirstUseEver)
    local draw
    openGUI, draw = imgui.Begin('ImAnim Usecases - UI Mockups (Lua)', openGUI)
    if not draw then
        imgui.End()
        return
    end

    imgui.TextColored(ImVec4(0.4, 0.8, 0.9, 1.0), 'Real-World UI Animation Patterns')
    imgui.TextWrapped(
        "This window showcases practical animation patterns commonly used in modern UI design. " ..
        "Each example demonstrates how ImAnim's tween API can create polished, responsive interfaces.")
    imgui.Separator()
    imgui.Spacing()

    -- Buttons for expand/collapse all
    if imgui.Button('Expand All') then common.open_all = 1 end
    imgui.SameLine()
    if imgui.Button('Collapse All') then common.open_all = -1 end
    imgui.Spacing()

    RunButtonsAndIndicatorsDemo()
    RunNavigationAndMenusDemo()
    RunDialogsAndModalsDemo()
    RunLoadingAndProgressDemo()
    RunInputControlsDemo()
    RunCardsAndContentDemo()
    RunTextAndDisplayDemo()
    RunVisualEffectsDemo()
    RunVfxGameTimelineToolsDemo()
    RunDataVisualizationDemo()

    -- Reset open/class all state after processing all headers
    common.open_all = 0

    imgui.End()
end

imgui.Register('ImAnimUsecases', ImAnimUsecaseWindow)

while openGUI do
    mq.delay(1000)
end
