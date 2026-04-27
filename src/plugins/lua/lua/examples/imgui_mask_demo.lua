-- Demonstrates masked drawing with ImGui.

local mq    = require 'mq'
local imgui = require 'ImGui'

local winTex     ---@type MQTexture
local logoTex    ---@type MQTexture
local classAnim  ---@type CTextureAnimation

local isOpen = true

-- window_pieces01.tga: 256x256 sprite sheet
-- A_RecessedBox region: pixel (180,110)-(221,151), 41×41 px
local TEX_W, TEX_H         = 256.0, 256.0
local NS_SRC_X1, NS_SRC_Y1 = 180, 110
local NS_SRC_X2, NS_SRC_Y2 = 221, 151

-- A_GaugeBackground region: pixel (108,7)-(208,17) — used in coverage mask Demo B
local GAUGE_UV_MIN = ImVec2(108 / 256, 7  / 256)
local GAUGE_UV_MAX = ImVec2(208 / 256, 17 / 256)

-- Stencil Mask tab state
local stencilComboIdx = AlphaMaskOp.Union + 1

local function loadTextures()
    if not winTex then
        winTex = mq.CreateTexture('uifiles/default/window_pieces01.tga')
    end
    if not logoTex then
        logoTex = mq.CreateTexture('uifiles/default/EQLS_background_01.tga')
    end
    if not classAnim then
        classAnim = mq.FindTextureAnimation('A_ClassAnim06')
    end
end


--
-- Tab 1: Stencil Mask
--

local function drawStencilMaskTab()
    imgui.TextWrapped(
        'Stencil masking composites two mask layers with a boolean operation, ' ..
        'then draws content clipped to the result.\n\n' ..
        'Each CreateMaskLayer call begins a new mask layer; shapes drawn ' ..
        'afterward become that layer\'s mask. BeginMaskedDraw combines them ' ..
        'all with the chosen operation and clips all subsequent draws until ' ..
        'EndMaskedDraw.')

    imgui.Spacing()
    imgui.SetNextItemWidth(200)
    stencilComboIdx = imgui.Combo('AlphaMaskOp##stencil', stencilComboIdx,
        'Intersect\0Union\0Subtract\0Complement\0\0')

    imgui.Spacing()
    imgui.Text('Mask Layer 0: 100x100 filled rect   (+10, +10) to (+110, +110)')
    imgui.Text('Mask Layer 1: circle r=25 centered at (+110, +60)')
    imgui.Text('Content: texture drawn over 200x200 canvas')
    imgui.Spacing()

    local dl = imgui.GetWindowDrawList()
    local p  = imgui.GetCursorScreenPosVec()

    -- Layer 0 — rectangular mask shape
    dl:CreateMaskLayer()
    dl:AddRectFilled(
        ImVec2(p.x + 10,  p.y + 10),
        ImVec2(p.x + 110, p.y + 110),
        IM_COL32(255, 255, 255, 255))

    -- Layer 1 — circular mask shape
    dl:CreateMaskLayer()
    dl:AddCircleFilled(
        ImVec2(p.x + 110, p.y + 60),
        25,
        IM_COL32(255, 255, 255, 255))

    -- Apply the chosen boolean operation and draw content through the mask
    dl:BeginMaskedDraw(stencilComboIdx - 1)
    dl:AddImage(
        logoTex:GetTextureID(),
        ImVec2(p.x,       p.y),
        ImVec2(p.x + 200, p.y + 200))
    dl:EndMaskedDraw()

    -- Reserve layout space so other widgets don't overlap the drawn area
    imgui.Dummy(200, 200)

    imgui.Spacing()
    imgui.Separator()
    imgui.TextWrapped(
        'Union: content shows where rect OR circle exists\n' ..
        'Intersect: only where both overlap\n' ..
        'Subtract: rect area minus the circle\n' ..
        'Complement: inverts the final combined mask')
end

-- Tab 2: Coverage Mask
-- Demonstrates framebuffer-alpha-based soft masking.
local function drawCoverageMaskTab()
    imgui.TextWrapped(
        'Coverage masking uses the framebuffer alpha channel as a per-pixel ' ..
        'opacity map.\n\n' ..
        'CreateCoverageMaskLayer defines the region. Draw the mask shape ' ..
        'normally — the alpha of those draws is stored as the mask. ' ..
        'BeginCoverageMaskedDraw / EndCoverageMaskedDraw then multiplies ' ..
        'content alpha by that stored mask, producing smooth soft edges.\n\n' ..
        'Unlike stencil masking, semi-transparent mask shapes produce ' ..
        'proportionally faded content rather than hard clip boundaries.')

    imgui.Spacing()

    local dl = imgui.GetWindowDrawList()

    -- Demo A: animated texture silhouette as a coverage mask
    -- The class texture's alpha channel (includes transparency in the sprite
    -- background) becomes the mask — content fills the texture's silhouette with
    -- a rainbow gradient and fades naturally at the sprite's soft edges.
    imgui.Separator()
    imgui.Text('Demo A — CTextureAnimation alpha as coverage mask')
    imgui.Separator()
    imgui.TextWrapped('Left = rainbow gradient masked to the textures\'s alpha silhouette\n' ..
                      'Right = unmasked texture for reference')
    imgui.Spacing()

    local size = ImVec2(64, 128)
    local a0 = imgui.GetCursorScreenPosVec()

    -- Write the texture's alpha channel into the coverage mask
    dl:CreateCoverageMaskLayer(a0, a0 + size)
    dl:AddTextureAnimation(classAnim, a0, size)

    -- Draw a rainbow gradient, feathered by the mask
    dl:BeginCoverageMaskedDraw()
    dl:AddRectFilledMultiColor(a0, a0 + size,
        IM_COL32(255,  50,  50, 255),   -- top-left:     red
        IM_COL32(255, 200,  50, 255),   -- top-right:    yellow
        IM_COL32( 50, 200, 255, 255),   -- bottom-right: cyan
        IM_COL32(180,  50, 255, 255))   -- bottom-left:  purple
    dl:EndCoverageMaskedDraw()

    imgui.Dummy(size)
    imgui.SameLine()
    imgui.DrawTextureAnimation(classAnim, size)

    imgui.Text('Note: Image will not appear if loaded before being ingame!')

    -- Demo B: Text as coverage mask
    imgui.Spacing()
    imgui.Separator()
    imgui.Text('Demo B — Text as coverage mask')
    imgui.Separator()
    imgui.Spacing()

    local bW, bH = 200, 36
    local b0 = imgui.GetCursorScreenPosVec()
    local b1 = ImVec2(b0.x + bW, b0.y + bH)

    -- Write the gauge strip's alpha as the coverage mask
    dl:CreateCoverageMaskLayer(b0, b1)
    dl:AddText(nil, 36, b0, IM_COL32(255, 255, 255, 255), "Hello, World!")

    -- Draw a blue-to-green gradient, shaped by the gauge strip's alpha
    dl:BeginCoverageMaskedDraw()
    dl:AddRectFilledMultiColor(b0, b1,
        IM_COL32(255,  50,  50, 255),   -- top-left:     red
        IM_COL32(255, 200,  50, 255),   -- top-right:    yellow
        IM_COL32( 50, 200, 255, 255),   -- bottom-right: cyan
        IM_COL32(180,  50, 255, 255))   -- bottom-left:  purple
    dl:EndCoverageMaskedDraw()

    imgui.Dummy(bW, bH)
end

local function renderUI()
    loadTextures()
    if not isOpen then return end

    local show
    isOpen, show = imgui.Begin('ImGui Masked Drawing Demo', isOpen)
    if show then
        if imgui.BeginTabBar('##NSDemoTabs') then
            if imgui.BeginTabItem('Stencil Mask') then
                drawStencilMaskTab()
                imgui.EndTabItem()
            end
            if imgui.BeginTabItem('Coverage Mask') then
                drawCoverageMaskTab()
                imgui.EndTabItem()
            end
            imgui.EndTabBar()
        end
    end
    imgui.End()
end

mq.imgui.init('imgui_mask_nineslice_demo', renderUI)

while isOpen do
    mq.delay(1000)
end
