local imgui = require('ImGui')
local iam = require('ImAnim')

local common = require('common')

-- ============================================================
-- USECASE 5: Card Hover Effects
-- ============================================================
local card_hover_state = {
    hovered = { false, false, false },
    lift_id = { ImHashStr('card_0_lift'), ImHashStr('card_1_lift'), ImHashStr('card_2_lift') },
    shadow_id = { ImHashStr('card_0_shadow'), ImHashStr('card_1_shadow'), ImHashStr('card_2_shadow') },
    border_id = { ImHashStr('card_0_border'), ImHashStr('card_1_border'), ImHashStr('card_2_border') },
    desc_id = { ImHashStr('card_0_desc'), ImHashStr('card_1_desc'), ImHashStr('card_2_desc') },
    titles = { 'Analytics', 'Reports', 'Settings' },
    descriptions = { 'View insights', 'Export data', 'Configure' }
}

local function ShowUsecase_CardHover()
    local state = card_hover_state

    imgui.TextWrapped('Card components with lift, shadow, and content reveal on hover. Shows coordinated multi-property animations.')

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()
    local start_pos = imgui.GetCursorScreenPosVec()

    local card_size = ImVec2(160, 120)
    local spacing = 20.0

    for i = 0, 2 do
        local id = ImHashStr('card_' .. i)
        local card_pos = ImVec2(start_pos.x + i * (card_size.x + spacing), start_pos.y)

        imgui.SetCursorScreenPos(card_pos)
        imgui.InvisibleButton(state.titles[i + 1], card_size)
        state.hovered[i + 1] = imgui.IsItemHovered()

        -- Animate lift (Y offset)
        local target_lift = state.hovered[i + 1] and -8.0 or 0.0
        local lift = iam.TweenFloat(id, state.lift_id[i + 1], target_lift, 0.25, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        -- Animate shadow
        local target_shadow = state.hovered[i + 1] and 20.0 or 8.0
        local shadow_blur = iam.TweenFloat(id, state.shadow_id[i + 1], target_shadow, 0.25, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        -- Animate description reveal
        local target_desc_alpha = state.hovered[i + 1] and 1.0 or 0.0
        local desc_alpha = iam.TweenFloat(id, state.desc_id[i + 1], target_desc_alpha, 0.2, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        -- Apply lift
        local drawn_pos = ImVec2(card_pos.x, card_pos.y + lift)

        -- Draw shadow (multiple layers for blur effect)
        for s = 3, 0, -1 do
            local offset = shadow_blur * 0.2 * (s + 1)
            local alpha = 15 - s * 3
            dl:AddRectFilled(
                ImVec2(drawn_pos.x + offset * 0.5, drawn_pos.y + offset),
                ImVec2(drawn_pos.x + card_size.x + offset * 0.5, drawn_pos.y + card_size.y + offset),
                IM_COL32(0, 0, 0, alpha), 8.0)
        end

        -- Draw card background
        dl:AddRectFilled(drawn_pos, ImVec2(drawn_pos.x + card_size.x, drawn_pos.y + card_size.y),
            IM_COL32(45, 48, 58, 255), 8.0)
        
        -- Border (note: simplified color - full version would use color tween)
        local border_col = state.hovered[i + 1] and IM_COL32(89, 194, 231, 255) or IM_COL32(76, 76, 89, 255)
        dl:AddRect(drawn_pos, ImVec2(drawn_pos.x + card_size.x, drawn_pos.y + card_size.y),
            border_col, 8.0, 0, 1.5)

        -- Draw title
        local title_pos = ImVec2(drawn_pos.x + 16.0, drawn_pos.y + 20.0)
        dl:AddText(title_pos, IM_COL32(220, 220, 230, 255), state.titles[i + 1])

        -- Draw description with animated alpha
        local desc_pos = ImVec2(drawn_pos.x + 16.0, drawn_pos.y + 50.0)
        dl:AddText(desc_pos, IM_COL32(140, 140, 150, math.floor(desc_alpha * 255)), state.descriptions[i + 1])

        -- Draw icon placeholder
        local icon_center = ImVec2(drawn_pos.x + card_size.x - 30.0, drawn_pos.y + 30.0)
        local icon_alpha = 100 + (state.hovered[i + 1] and 100 or 0)
        dl:AddCircleFilled(icon_center, 12.0, IM_COL32(91, 194, 231, icon_alpha))
    end

    imgui.SetCursorScreenPos(start_pos.x, start_pos.y + card_size.y + 20)
end

-- ============================================================
-- USECASE 21: Flip Card
-- ============================================================
local flip_card_state = {
    flipped = false,
    flip_id = ImHashStr('flip_progress'),
}

local function ShowUsecase_FlipCard()
    local state = flip_card_state

    imgui.TextWrapped('Card that flips to reveal content on the back. Uses perspective simulation for a 3D-like effect.')

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    if imgui.Button(state.flipped and 'Flip to Front' or 'Flip to Back') then
        state.flipped = not state.flipped
    end

    local id = ImHashStr('flip_card')

    -- Animate flip (0 = front, 1 = back)
    local target_flip = state.flipped and 1.0 or 0.0
    local flip_progress = iam.TweenFloat(id, state.flip_id, target_flip, 0.6, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

    local pos = imgui.GetCursorScreenPosVec()
    local card_size = ImVec2(240, 150)

    -- Calculate perspective scaling (card appears to rotate around Y axis)
    local angle = flip_progress * math.pi
    local scale_x = math.abs(math.cos(angle))
    local show_back = flip_progress > 0.5

    -- Center the card
    local card_center = ImVec2(pos.x + card_size.x * 0.5, pos.y + card_size.y * 0.5)
    local half_width = card_size.x * 0.5 * scale_x
    local half_height = card_size.y * 0.5

    local card_min = ImVec2(card_center.x - half_width, card_center.y - half_height)
    local card_max = ImVec2(card_center.x + half_width, card_center.y + half_height)

    -- Only draw if card has some width
    if scale_x > 0.05 then
        -- Shadow
        dl:AddRectFilled(
            ImVec2(card_min.x + 4, card_min.y + 6),
            ImVec2(card_max.x + 4, card_max.y + 6),
            IM_COL32(0, 0, 0, 40), 8.0)

        if show_back then
            -- Back of card
            dl:AddRectFilled(card_min, card_max, IM_COL32(91, 194, 231, 255), 8.0)

            -- Pattern on back
            local pattern_offset = half_width * 0.3
            dl:AddRect(
                ImVec2(card_min.x + pattern_offset, card_min.y + 20),
                ImVec2(card_max.x - pattern_offset, card_max.y - 20),
                IM_COL32(255, 255, 255, 100), 4.0, 0, 2.0)

            -- Back text
            local back_text = 'SECRET!'
            local text_size = imgui.CalcTextSizeVec(back_text)
            if text_size.x < half_width * 1.8 then
                dl:AddText(ImVec2(card_center.x - text_size.x * 0.5, card_center.y - text_size.y * 0.5),
                    common.IM_COL32_WHITE, back_text)
            end
        else
            -- Front of card
            dl:AddRectFilled(card_min, card_max, IM_COL32(50, 54, 65, 255), 8.0)

            -- Front content
            local front_title = 'Click to Flip'
            local title_size = imgui.CalcTextSizeVec(front_title)
            if title_size.x < half_width * 1.8 then
                dl:AddText(ImVec2(card_center.x - title_size.x * 0.5, card_center.y - 20),
                    IM_COL32(220, 220, 230, 255), front_title)

                local front_sub = 'Hover for info'
                local sub_size = imgui.CalcTextSizeVec(front_sub)
                dl:AddText(ImVec2(card_center.x - sub_size.x * 0.5, card_center.y + 10),
                    IM_COL32(140, 140, 150, 255), front_sub)
            end
        end
    end

    imgui.Dummy(card_size)
end

-- ============================================================
-- USECASE 17: Swipe Cards (Tinder-style)
-- ============================================================
local swipe_cards_state = {
    current_card = 0,
    swipe_x = 0.0,
    swipe_rotation = 0.0,
    swiping = false,
    swipe_x_id = ImHashStr('swipe_x_progress'),
    card_titles = { 'Project Alpha', 'Design Beta', 'Code Gamma', 'Launch Delta' },
    card_descs = { 'Innovation awaits', 'Creative vision', 'Build the future', 'Ship it!' },
    card_colors = {
        IM_COL32(91, 194, 231, 255),
        IM_COL32(204, 120, 88, 255),
        IM_COL32(130, 200, 130, 255),
        IM_COL32(200, 180, 100, 255)
    },
    total_cards = 4
}

local function ShowUsecase_SwipeCards()
    local state = swipe_cards_state

    imgui.TextWrapped('Stacked cards that can be swiped left or right. Popular in dating apps and decision-making interfaces.')

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    local canvas_pos = imgui.GetCursorScreenPosVec()
    local canvas_size = ImVec2(imgui.GetContentRegionAvailVec().x, 230)

    -- Background
    dl:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y),
        IM_COL32(20, 22, 30, 255), 4.0)

    local card_size = ImVec2(280, 180)
    local stack_center = ImVec2(canvas_pos.x + canvas_size.x * 0.5, canvas_pos.y + canvas_size.y * 0.5)

    -- Swipe buttons
    local btn_y = canvas_pos.y + canvas_size.y - 45
    imgui.SetCursorScreenPos(canvas_pos.x + 30, btn_y)
    if imgui.Button('< Reject') and not state.swiping and state.current_card < state.total_cards then
        state.swiping = true
        state.swipe_x = 0.0
    end
    imgui.SameLine()
    imgui.SetCursorScreenPos(canvas_pos.x + canvas_size.x - 110, btn_y)
    if imgui.Button('Accept >') and not state.swiping and state.current_card < state.total_cards then
        state.swiping = true
        state.swipe_x = 0.01 -- Small positive to indicate right swipe
    end

    -- Update swipe animation
    local id = ImHashStr('swipe_cards')
    if state.swiping then
        local target_x = state.swipe_x >= 0 and 400.0 or - 400.0
        state.swipe_x = iam.TweenFloat(id, state.swipe_x_id, target_x, 0.8, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)
        state.swipe_rotation = state.swipe_x * 0.04

        if math.abs(state.swipe_x) > 350.0 then
            state.current_card = state.current_card + 1
            state.swiping = false
            state.swipe_x = 0.0
            state.swipe_rotation = 0.0
            -- Reset tween
            iam.TweenFloat(id, state.swipe_x_id, 0.0, 0.01, iam.EasePreset(IamEaseType.Linear), IamPolicy.Cut, dt)
        end
    end

    -- Draw cards (back to front)
    local max_card = math.min(state.current_card + 2, state.total_cards - 1)
    for i = max_card, state.current_card, -1 do
        if i >= state.total_cards then goto continue end

        local stack_index = i - swipe_cards_state.current_card
        local scale = 1.0 - stack_index * 0.05
        local y_offset = stack_index * 8.0

        local card_center = stack_center
        card_center.y = card_center.y + y_offset

        local rotation = 0.0
        local x_offset = 0.0

        -- Apply swipe to top card only
        if i == state.current_card and state.swiping then
            x_offset = state.swipe_x
            rotation = state.swipe_rotation
        end

        card_center.x = card_center.x + x_offset

        -- Calculate rotated corners
        local half = ImVec2(card_size.x * 0.5 * scale, card_size.y * 0.5 * scale)
        local c = math.cos(rotation * math.pi / 180.0)
        local s = math.sin(rotation * math.pi / 180.0)

        local corners = {}
        local offsets = {
            ImVec2( - half.x, - half.y), ImVec2(half.x, - half.y),
            ImVec2(half.x, half.y), ImVec2( - half.x, half.y)
        }
        for j = 0, 3 do
            corners[j + 1] = ImVec2(
                card_center.x + offsets[j + 1].x * c - offsets[j + 1].y * s,
                card_center.y + offsets[j + 1].x * s + offsets[j + 1].y * c
            )
        end

        -- Shadow
        local shadow_offset = ImVec2(4 + math.abs(x_offset) * 0.02, 6 + math.abs(x_offset) * 0.02)
        local shadow_corners = {}
        for j = 0, 3 do
            shadow_corners[j + 1] = ImVec2(corners[j + 1].x + shadow_offset.x, corners[j + 1].y + shadow_offset.y)
        end
        dl:AddConvexPolyFilled(shadow_corners, IM_COL32(0, 0, 0, 40))

        -- Card
        dl:AddConvexPolyFilled(corners, IM_COL32(50, 54, 65, 255))

        -- Color accent bar (simplified)
        dl:AddConvexPolyFilled({ corners[1], corners[2],
            ImVec2(corners[2].x + (corners[3].x - corners[2].x) * 0.15, corners[2].y + (corners[3].y - corners[2].y) * 0.15),
            ImVec2(corners[1].x + (corners[4].x - corners[1].x) * 0.15, corners[1].y + (corners[4].y - corners[1].y) * 0.15) },
            state.card_colors[(i % state.total_cards) + 1])

        -- Title and description
        if i < state.total_cards then
            local title_size = imgui.CalcTextSizeVec(state.card_titles[i + 1])
            local desc_size = imgui.CalcTextSizeVec(state.card_descs[i + 1])
            dl:AddText(ImVec2(card_center.x - title_size.x * 0.5, card_center.y - 10), IM_COL32(220, 220, 230, 255), state.card_titles[i + 1])
            dl:AddText(ImVec2(card_center.x - desc_size.x * 0.5, card_center.y + 10), IM_COL32(150, 150, 160, 255), state.card_descs[i + 1])
        end

        -- Swipe indicators on top card
        if i == state.current_card and state.swiping then
            if state.swipe_x > 50 then
                dl:AddText(ImVec2(card_center.x - 30, card_center.y - 40),
                    IM_COL32(100, 200, 100, math.floor(math.min(state.swipe_x / 100.0, 1.0) * 255)), 'ACCEPT')
            elseif state.swipe_x < - 50 then
                dl:AddText(ImVec2(card_center.x - 30, card_center.y - 40),
                    IM_COL32(200, 100, 100, math.floor(math.min( - state.swipe_x / 100.0, 1.0) * 255)), 'REJECT')
            end
        end

        ::continue::
    end

    -- Reset button
    if state.current_card >= state.total_cards then
        imgui.SetCursorScreenPos(stack_center.x - 40, stack_center.y - 10)
        if imgui.Button('Reset Cards') then
            state.current_card = 0
        end
    end

    imgui.SetCursorScreenPos(canvas_pos.x, canvas_pos.y + canvas_size.y + 8)
    imgui.Dummy(ImVec2(1, 1))
end

-- ============================================================
-- USECASE 22: Carousel / Image Slider
-- ============================================================
local carousel_state = {
    slide_count = 4,
    current_slide = 0,
    auto_timer = 0.0,
    auto_advance = true,
    offset_id = ImHashStr('carousel_offset'),
    slide_colors = {
        IM_COL32(91, 194, 231, 255),
        IM_COL32(204, 120, 88, 255),
        IM_COL32(130, 200, 130, 255),
        IM_COL32(200, 180, 100, 255)
    },
    slide_labels = { 'Slide 1', 'Slide 2', 'Slide 3', 'Slide 4' }
}

local function ShowUsecase_Carousel()
    local state = carousel_state

    imgui.TextWrapped('Image carousel with smooth slide transitions. Includes navigation dots and auto-advance option.')

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    state.auto_advance = imgui.Checkbox('Auto-advance', state.auto_advance)

    if state.auto_advance then
        state.auto_timer = state.auto_timer + dt
        if state.auto_timer > 3.0 then
            state.current_slide = (state.current_slide + 1) % state.slide_count
            state.auto_timer = 0.0
        end
    end

    local pos = imgui.GetCursorScreenPosVec()
    local carousel_size = ImVec2(imgui.GetContentRegionAvailVec().x, 140)

    -- Background
    dl:AddRectFilled(pos, ImVec2(pos.x + carousel_size.x, pos.y + carousel_size.y),
        IM_COL32(20, 22, 30, 255), 8.0)

    -- Animate slide position
    local id = ImHashStr('carousel')
    local target_offset = state.current_slide
    local offset = iam.TweenFloat(id, state.offset_id, target_offset, 0.5, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

    -- Clip to carousel bounds
    local content_width = carousel_size.x - 80
    local slide_width = content_width
    local content_pos = ImVec2(pos.x + 40, pos.y + 10)
    local content_size = ImVec2(content_width, carousel_size.y - 50)

    dl:PushClipRect(content_pos, ImVec2(content_pos.x + content_size.x, content_pos.y + content_size.y), true)

    -- Draw slides
    for i = 0, state.slide_count - 1 do
        local slide_x = content_pos.x + (i - offset) * slide_width

        if slide_x > content_pos.x - slide_width and slide_x < content_pos.x + content_width then
            dl:AddRectFilled(
                ImVec2(slide_x + 4, content_pos.y),
                ImVec2(slide_x + slide_width - 4, content_pos.y + content_size.y),
                state.slide_colors[i + 1], 6.0)

            -- Slide label
            local label_size = imgui.CalcTextSizeVec(state.slide_labels[i + 1])
            dl:AddText(
                ImVec2(slide_x + (slide_width - label_size.x) * 0.5, content_pos.y + (content_size.y - label_size.y) * 0.5),
                common.IM_COL32_WHITE, state.slide_labels[i + 1])
        end
    end

    dl:PopClipRect()

    -- Navigation arrows
    local arrow_size = ImVec2(30, 30)

    -- Left arrow
    imgui.SetCursorScreenPos(pos.x + 5, pos.y + carousel_size.y * 0.5 - 25)
    if imgui.InvisibleButton('##carousel_left', arrow_size) then
        state.current_slide = (state.current_slide - 1 + state.slide_count) % state.slide_count
        state.auto_timer = 0.0
    end
    local left_center = ImVec2(pos.x + 20, pos.y + carousel_size.y * 0.5 - 10)
    dl:AddTriangleFilled(
        ImVec2(left_center.x + 8, left_center.y - 10),
        ImVec2(left_center.x + 8, left_center.y + 10),
        ImVec2(left_center.x - 6, left_center.y),
        imgui.IsItemHovered() and IM_COL32(255, 255, 255, 255) or IM_COL32(180, 180, 180, 255))

    -- Right arrow
    imgui.SetCursorScreenPos(pos.x + carousel_size.x - 35, pos.y + carousel_size.y * 0.5 - 25)
    if imgui.InvisibleButton('##carousel_right', arrow_size) then
        state.current_slide = (state.current_slide + 1) % state.slide_count
        state.auto_timer = 0.0
    end
    local right_center = ImVec2(pos.x + carousel_size.x - 20, pos.y + carousel_size.y * 0.5 - 10)
    dl:AddTriangleFilled(
        ImVec2(right_center.x - 8, right_center.y - 10),
        ImVec2(right_center.x - 8, right_center.y + 10),
        ImVec2(right_center.x + 6, right_center.y),
        imgui.IsItemHovered() and IM_COL32(255, 255, 255, 255) or IM_COL32(180, 180, 180, 255))

    -- Navigation dots
    local dots_y = pos.y + carousel_size.y - 25
    local dots_start_x = pos.x + (carousel_size.x - (state.slide_count * 20)) * 0.5
    for i = 0, state.slide_count - 1 do
        local dot_center = ImVec2(dots_start_x + i * 20 + 6, dots_y)

        imgui.SetCursorScreenPos(dot_center.x - 6, dot_center.y - 6)
        local dot_id = string.format("##dot%d", i)
        if imgui.InvisibleButton(dot_id, ImVec2(12, 12)) then
            state.current_slide = i
            state.auto_timer = 0.0
        end

        local dot_radius = (i == state.current_slide) and 5.0 or 4.0
        local dot_color = (i == state.current_slide) and IM_COL32(91, 194, 231, 255) or IM_COL32(100, 100, 110, 255)
        if imgui.IsItemHovered() then dot_color = IM_COL32(150, 150, 160, 255) end

        dl:AddCircleFilled(dot_center, dot_radius, dot_color)
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + carousel_size.y + 10)
    imgui.Dummy(ImVec2(1, 1))
end

-- ============================================================
-- USECASE: Expandable List Item
-- ============================================================
local expandable_list_state = {
    expanded_item = -1,
    expand_ids = { ImHashStr('expand_0'), ImHashStr('expand_1'), ImHashStr('expand_2') },
    items = {
        {
            title = 'Quick Task',
            subtitle = 'Due: Today',
            details = { 'Status: In Progress', 'Priority: High' },
            num_lines = 2,
            accent_color = IM_COL32(76, 175, 80, 255)
        },
        {
            title = 'Project Alpha',
            subtitle = 'Due: Dec 15',
            details = { 'Team: Alice, Bob, Charlie, Dana', 'Progress: 75% complete', 'Priority: Medium', 'Last updated: 2 hours ago' },
            num_lines = 4,
            accent_color = IM_COL32(33, 150, 243, 255)
        },
        {
            title = 'Major Release v2.0',
            subtitle = 'Due: Q1 2025',
            details = { 'Components: UI, Backend, API, Docs', 'Teams involved: 3 departments', 'Budget: Approved', 'Risk level: Low', 'Dependencies: 12 items', 'Sign-off required: Yes' },
            num_lines = 6,
            accent_color = IM_COL32(255, 152, 0, 255)
        }
    }
}

local function ShowUsecase_ExpandableListItem()
    local state = expandable_list_state

    imgui.TextWrapped('List items that expand to reveal additional content with dynamic heights. Each item has different content lengths to demonstrate adaptive sizing.')

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain

    local pos = imgui.GetCursorScreenPosVec()
    local dl = imgui.GetWindowDrawList()
    local width = imgui.GetContentRegionAvailVec().x
    local y_cursor = pos.y
    local line_height = imgui.GetTextLineHeightWithSpacing()

    for i = 0, 2 do
        local is_expanded = (state.expanded_item == i)
        local expand_anim = iam.TweenFloat(ImHashStr('list_expand_' .. i), state.expand_ids[i + 1],
            is_expanded and 1.0 or 0.0, 0.3, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        local base_height = 45 * scale
        local item = state.items[i + 1]
        local content_height = item.num_lines * (line_height + 4 * scale) + 15 * scale
        local expanded_height = base_height + content_height
        local item_height = base_height + content_height * expand_anim

        local item_pos = ImVec2(pos.x, y_cursor)
        local item_size = ImVec2(width, item_height)

        -- Background with hover effect
        local bg_col = is_expanded and IM_COL32(55, 60, 75, 255) or IM_COL32(40, 45, 55, 255)
        dl:AddRectFilled(item_pos, ImVec2(item_pos.x + item_size.x, item_pos.y + item_size.y),
            bg_col, 8 * scale)

        -- Left accent bar - different colors for different content sizes
        dl:AddRectFilled(item_pos, ImVec2(item_pos.x + 4 * scale, item_pos.y + item_size.y),
            item.accent_color, 8 * scale, ImDrawFlags.RoundCornersLeft)

        -- Title
        dl:AddText(ImVec2(item_pos.x + 15 * scale, item_pos.y + 8 * scale),
            IM_COL32(255, 255, 255, 255), item.title)

        -- Subtitle with line count hint
        local subtitle_with_count = string.format('%s  (%d items)', item.subtitle, item.num_lines)
        dl:AddText(ImVec2(item_pos.x + 15 * scale, item_pos.y + 30 * scale),
            IM_COL32(140, 145, 155, 255), subtitle_with_count)

        -- Expand indicator (chevron that rotates)
        local arrow_rot = expand_anim * math.pi * 0.5
        local arrow_center = ImVec2(item_pos.x + width - 25 * scale, item_pos.y + 22 * scale)
        local arrow_size = 6 * scale
        local p1 = ImVec2(arrow_center.x - arrow_size * math.cos(arrow_rot), arrow_center.y - arrow_size * math.sin(arrow_rot))
        local p2 = ImVec2(arrow_center.x + arrow_size * math.sin(arrow_rot), arrow_center.y - arrow_size * math.cos(arrow_rot))
        local p3 = ImVec2(arrow_center.x + arrow_size * math.cos(arrow_rot), arrow_center.y + arrow_size * math.sin(arrow_rot))
        dl:AddTriangleFilled(p1, p2, p3, IM_COL32(180, 185, 195, 255))

        -- Expanded content - each line fades in with slight stagger
        if expand_anim > 0.05 then
            local content_alpha = math.max(0.0, math.min((expand_anim - 0.05) / 0.5, 1.0))

            -- Separator line
            local sep_width = (width - 30 * scale) * math.min(expand_anim * 2.0, 1.0)
            dl:AddLine(
                ImVec2(item_pos.x + 15 * scale, item_pos.y + base_height - 2 * scale),
                ImVec2(item_pos.x + 15 * scale + sep_width, item_pos.y + base_height - 2 * scale),
                IM_COL32(80, 85, 95, math.floor(content_alpha * 200)))

            -- Draw each detail line
            for line = 0, item.num_lines - 1 do
                local line_delay = line * 0.08
                local line_alpha = math.max(0.0, math.min((expand_anim - 0.1 - line_delay) / 0.4, 1.0))

                if line_alpha > 0.0 then
                    local y_offset = base_height + 8 * scale + line * (line_height + 4 * scale)

                    -- Bullet point
                    local r = bit32.band(item.accent_color, 0xFF)
                    local g = bit32.band(bit32.rshift(item.accent_color, 8), 0xFF)
                    local b = bit32.band(bit32.rshift(item.accent_color, 16), 0xFF)
                    local bullet_col = IM_COL32(r, g, b, math.floor(line_alpha * 255))
                    dl:AddCircleFilled(
                        ImVec2(item_pos.x + 20 * scale, item_pos.y + y_offset + line_height * 0.5),
                        3 * scale, bullet_col)

                    -- Text
                    dl:AddText(
                        ImVec2(item_pos.x + 30 * scale, item_pos.y + y_offset),
                        IM_COL32(200, 205, 215, math.floor(line_alpha * 255)),
                        item.details[line + 1])
                end
            end
        end

        -- Click detection on header area
        local mouse = imgui.GetMousePosVec()
        if imgui.IsMouseClicked(0) and
            mouse.x >= item_pos.x and mouse.x <= item_pos.x + item_size.x and
            mouse.y >= item_pos.y and mouse.y <= item_pos.y + base_height then
            state.expanded_item = is_expanded and - 1 or i
        end

        y_cursor = y_cursor + item_height + 8 * scale
    end

    imgui.SetCursorScreenPos(pos.x, y_cursor)
end

-- ============================================================
-- USECASE: Image Gallery Grid
-- ============================================================
local gallery_grid_state = {
    selected_image = -1,
    hovered_image = -1,
    hover_scale_ids = {
        ImHashStr('gallery_hover_0'), ImHashStr('gallery_hover_1'), ImHashStr('gallery_hover_2'), ImHashStr('gallery_hover_3'),
        ImHashStr('gallery_hover_4'), ImHashStr('gallery_hover_5'), ImHashStr('gallery_hover_6'), ImHashStr('gallery_hover_7')
    },
    select_glow_ids = {
        ImHashStr('gallery_select_0'), ImHashStr('gallery_select_1'), ImHashStr('gallery_select_2'), ImHashStr('gallery_select_3'),
        ImHashStr('gallery_select_4'), ImHashStr('gallery_select_5'), ImHashStr('gallery_select_6'), ImHashStr('gallery_select_7')
    },
    colors = {
        IM_COL32(255, 107, 107, 255), IM_COL32(78, 205, 196, 255),
        IM_COL32(199, 244, 100, 255), IM_COL32(255, 230, 109, 255),
        IM_COL32(107, 185, 240, 255), IM_COL32(238, 130, 238, 255),
        IM_COL32(255, 165, 0, 255),   IM_COL32(50, 205, 50, 255)
    }
}

local function ShowUsecase_ImageGalleryGrid()
    local state = gallery_grid_state

    imgui.TextWrapped('Image gallery with hover zoom effect and selection animation. Grid items scale up smoothly on hover.')

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain

    local pos = imgui.GetCursorScreenPosVec()
    local dl = imgui.GetWindowDrawList()

    local cell_size = 70 * scale
    local gap = 8 * scale
    local cols = 4
    local rows = 2

    local mouse = imgui.GetMousePosVec()
    state.hovered_image = -1

    for row = 0, rows - 1 do
        for col = 0, cols - 1 do
            local idx = row * cols + col
            local x = pos.x + col * (cell_size + gap)
            local y = pos.y + row * (cell_size + gap)

            -- Check hover
            local is_hovered = mouse.x >= x and mouse.x <= x + cell_size and
                               mouse.y >= y and mouse.y <= y + cell_size
            if is_hovered then state.hovered_image = idx end

            local is_selected = (state.selected_image == idx)

            local hover_scale = iam.TweenFloat(ImHashStr('gallery_hover_' .. idx), state.hover_scale_ids[idx + 1],
                is_hovered and 1.1 or 1.0, 0.15, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

            local select_glow = iam.TweenFloat(ImHashStr('gallery_select_' .. idx), state.select_glow_ids[idx + 1],
                is_selected and 1.0 or 0.0, 0.2, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)

            local actual_size = cell_size * hover_scale
            local offset = (actual_size - cell_size) * 0.5

            -- Selection glow
            if select_glow > 0.01 then
                dl:AddRectFilled(
                    ImVec2(x - offset - 3 * scale, y - offset - 3 * scale),
                    ImVec2(x - offset + actual_size + 3 * scale, y - offset + actual_size + 3 * scale),
                    IM_COL32(255, 255, 255, math.floor(select_glow * 150)), 10 * scale)
            end

            -- Image placeholder (colored rectangle)
            dl:AddRectFilled(
                ImVec2(x - offset, y - offset),
                ImVec2(x - offset + actual_size, y - offset + actual_size),
                state.colors[idx + 1], 8 * scale)

            -- Checkmark for selected
            if select_glow > 0.5 then
                local check_center = ImVec2(x - offset + actual_size - 15 * scale, y - offset + 15 * scale)
                dl:AddCircleFilled(check_center, 10 * scale, IM_COL32(255, 255, 255, 255))
                dl:AddText(ImVec2(check_center.x - 5 * scale, check_center.y - 7 * scale),
                    IM_COL32(0, 150, 0, 255), '+')
            end

            -- Click to select
            if is_hovered and imgui.IsMouseClicked(0) then
                state.selected_image = is_selected and - 1 or idx
            end
        end
    end

    imgui.Dummy(ImVec2(cols * (cell_size + gap), rows * (cell_size + gap)))
end

-- ============================================================
-- USECASE: Stacked Cards
-- ============================================================
local stacked_cards_state = {
    expanded = false,
    card_offsets = { 0.0, 0.0, 0.0 },
    card_ids = { 0, 1, 2 },
    offset_ids = { ImHashStr('stack_card_0'), ImHashStr('stack_card_1'), ImHashStr('stack_card_2') },
}

local function ShowUsecase_StackedCards()
    local state = stacked_cards_state

    imgui.TextWrapped('Stacked card deck with animated reveal on hover.')

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    local pos = imgui.GetCursorScreenPosVec()
    local card_size = ImVec2(150 * scale, 100 * scale)

    imgui.InvisibleButton('stack_area', ImVec2(card_size.x + 60 * scale, card_size.y + 40 * scale))
    state.expanded = imgui.IsItemHovered()

    -- Draw cards back to front
    for i = 2, 0, -1 do
        local target_offset = state.expanded and i * 25 * scale or i * 5 * scale
        local offset = iam.TweenFloat(ImHashStr('card_' .. i), state.offset_ids[i + 1],
            target_offset, 0.25, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

        local card_pos = ImVec2(pos.x + offset, pos.y + offset * 0.5)
        local card_col = IM_COL32(50 + i * 15, 55 + i * 15, 65 + i * 15, 255)

        dl:AddRectFilled(card_pos, ImVec2(card_pos.x + card_size.x, card_pos.y + card_size.y),
            card_col, 8 * scale)

        local label = string.format('Card %d', i + 1)
        dl:AddText(ImVec2(card_pos.x + 15 * scale, card_pos.y + 15 * scale),
            IM_COL32(200, 200, 210, 255), label)
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + card_size.y + 50 * scale)
end

-- ============================================================
-- USECASE: Notification Card
-- ============================================================
local notification_card_state = {
    visible = false,
    dismiss_x = 0.0,
    slide_id = ImHashStr('notif_slide'),
}

local function ShowUsecase_NotificationCard()
    local state = notification_card_state

    imgui.TextWrapped('Notification card with slide-in and dismiss animation.')

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    local pos = imgui.GetCursorScreenPosVec()

    if imgui.Button(state.visible and 'Dismiss' or 'Show Notification') then
        state.visible = not state.visible
    end

    local card_pos = ImVec2(pos.x, pos.y + 35 * scale)
    local card_size = ImVec2(280 * scale, 70 * scale)

    -- Slide animation
    local slide_x = iam.TweenFloat(ImHashStr('notif_x'), state.slide_id,
        state.visible and 0.0 or - card_size.x - 20 * scale, 0.3, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

    if slide_x > - card_size.x then
        local final_pos = ImVec2(card_pos.x + slide_x, card_pos.y)

        -- Card
        dl:AddRectFilled(final_pos, ImVec2(final_pos.x + card_size.x, final_pos.y + card_size.y),
            IM_COL32(50, 55, 65, 255), 8 * scale)

        -- Accent bar
        dl:AddRectFilled(final_pos, ImVec2(final_pos.x + 4 * scale, final_pos.y + card_size.y),
            IM_COL32(76, 175, 80, 255), 8 * scale, ImDrawFlags.RoundCornersLeft)

        -- Content
        dl:AddText(ImVec2(final_pos.x + 15 * scale, final_pos.y + 12 * scale),
            IM_COL32(255, 255, 255, 255), 'New Message')
        dl:AddText(ImVec2(final_pos.x + 15 * scale, final_pos.y + 35 * scale),
            IM_COL32(150, 150, 160, 255), 'You have 3 unread messages')
    end

    imgui.SetCursorScreenPos(pos.x, card_pos.y + card_size.y + 15 * scale)
end

-- ============================================================
-- USECASE: Music Player
-- ============================================================
local music_player_state = {
    playing = false,
    progress = 0.0,
    wave_offset = 0.0,
    pulse_id = ImHashStr('album_pulse'),
    prog_id = ImHashStr('music_progress'),
    btn_scale_id = ImHashStr('play_btn_scale'),
}

local function ShowUsecase_ProductCard()
    local state = music_player_state

    imgui.TextWrapped('Music player with animated progress, waveform visualization, and playback controls.')

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    if state.playing then
        state.progress = state.progress + dt * 0.05
        if state.progress > 1.0 then
            state.progress = 0.0
        end
        state.wave_offset = state.wave_offset + dt * 3.0
    end

    local pos = imgui.GetCursorScreenPosVec()
    local card_size = ImVec2(840 * scale, 360 * scale)

    -- Card background
    dl:AddRectFilled(pos, ImVec2(pos.x + card_size.x, pos.y + card_size.y),
        IM_COL32(35, 40, 50, 255), 36 * scale)

    -- Album art placeholder
    local art_size = 240 * scale
    local art_pos = ImVec2(pos.x + 45 * scale, pos.y + 60 * scale)
    dl:AddRectFilled(art_pos, ImVec2(art_pos.x + art_size, art_pos.y + art_size),
        IM_COL32(100, 80, 140, 255), 24 * scale)

    -- Album art pulse when playing
    if state.playing then
        local pulse = iam.Oscillate(ImHashStr('pulse'), 1.0, 1.0, 0, 0.0, dt)
        pulse = pulse * 0.5 + 0.5 -- Convert - 1..1 to 0..1
        dl:AddRect(art_pos, ImVec2(art_pos.x + art_size, art_pos.y + art_size),
            IM_COL32(150, 120, 200, math.floor(50 + 50 * pulse)), 24 * scale, 0, 6 * scale)
    end

    -- Song info
    local info_x = art_pos.x + art_size + 45 * scale
    dl:AddText(ImVec2(info_x, pos.y + 60 * scale), IM_COL32(255, 255, 255, 255), 'Track Title')
    dl:AddText(ImVec2(info_x, pos.y + 120 * scale), IM_COL32(150, 150, 160, 255), 'Artist Name')

    -- Animated waveform
    local wave_y = pos.y + 180 * scale
    local wave_width = card_size.x - info_x + pos.x - 60 * scale
    for i = 0, 39 do
        local bar_x = info_x + i * (wave_width / 40)
        local height_factor = state.playing and
            (math.sin(state.wave_offset + i * 0.5) * 0.5 + 0.5) * 0.8 + 0.2 or 0.3
        local bar_height = 45 * scale * height_factor
        dl:AddRectFilled(
            ImVec2(bar_x, wave_y + (45 * scale - bar_height) * 0.5),
            ImVec2(bar_x + 8 * scale, wave_y + (45 * scale + bar_height) * 0.5),
            IM_COL32(150, 120, 200, state.playing and 255 or 100), 4 * scale)
    end

    -- Progress bar
    local prog_y = pos.y + 255 * scale
    local prog_width = card_size.x - 90 * scale
    dl:AddRectFilled(ImVec2(pos.x + 45 * scale, prog_y),
        ImVec2(pos.x + 45 * scale + prog_width, prog_y + 12 * scale),
        IM_COL32(60, 65, 75, 255), 6 * scale)

    -- Animated progress fill
    local animated_progress = iam.TweenFloat(ImHashStr('prog'), state.prog_id,
        state.progress, 0.1, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)
    dl:AddRectFilled(ImVec2(pos.x + 45 * scale, prog_y),
        ImVec2(pos.x + 45 * scale + prog_width * animated_progress, prog_y + 12 * scale),
        IM_COL32(150, 120, 200, 255), 6 * scale)

    -- Progress knob
    local knob_x = pos.x + 45 * scale + prog_width * animated_progress
    dl:AddCircleFilled(ImVec2(knob_x, prog_y + 6 * scale), 18 * scale, IM_COL32(255, 255, 255, 255))

    -- Time labels
    local cur_sec = math.floor(state.progress * 180)
    local time_cur = string.format('%d:%02d', cur_sec / 60, cur_sec % 60)
    local time_total = '3:00'
    dl:AddText(ImVec2(info_x, prog_y + 24 * scale), IM_COL32(120, 120, 130, 255), time_cur)
    local total_size = imgui.CalcTextSizeVec(time_total)
    dl:AddText(ImVec2(info_x + wave_width - total_size.x, prog_y + 24 * scale),
        IM_COL32(120, 120, 130, 255), time_total)

    -- Play button
    imgui.SetCursorScreenPos(pos.x + card_size.x - 135 * scale, pos.y + 45 * scale)
    if imgui.InvisibleButton('play_btn', ImVec2(90 * scale, 90 * scale)) then
        state.playing = not state.playing
    end

    -- Animate play button
    local btn_hover = imgui.IsItemHovered() and 1.15 or 1.0
    local btn_scale = iam.TweenFloat(ImHashStr('btn_s'), state.btn_scale_id,
        btn_hover, 0.15, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)

    local btn_center = ImVec2(pos.x + card_size.x - 90 * scale, pos.y + 90 * scale)
    local btn_r = 36 * scale * btn_scale
    dl:AddCircleFilled(btn_center, btn_r, IM_COL32(150, 120, 200, 255))

    if state.playing then
        -- Pause icon
        dl:AddRectFilled(ImVec2(btn_center.x - 12 * scale, btn_center.y - 15 * scale),
            ImVec2(btn_center.x - 3 * scale, btn_center.y + 15 * scale), IM_COL32(255, 255, 255, 255))
        dl:AddRectFilled(ImVec2(btn_center.x + 3 * scale, btn_center.y - 15 * scale),
            ImVec2(btn_center.x + 12 * scale, btn_center.y + 15 * scale), IM_COL32(255, 255, 255, 255))
    else
        -- Play icon (triangle)
        local p1 = ImVec2(btn_center.x - 9 * scale, btn_center.y - 18 * scale)
        local p2 = ImVec2(btn_center.x - 9 * scale, btn_center.y + 18 * scale)
        local p3 = ImVec2(btn_center.x + 18 * scale, btn_center.y)
        dl:AddTriangleFilled(p1, p2, p3, IM_COL32(255, 255, 255, 255))
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + card_size.y + 10 * scale)
end

-- ============================================================
-- USECASE: Timeline Card
-- ============================================================
local timeline_card_state = {
    anim_time = 0.0,
    item_x_ids = { ImHashStr('tl_0_x'), ImHashStr('tl_1_x'), ImHashStr('tl_2_x'), ImHashStr('tl_3_x') },
    events = { 'Created project', 'Added team member', 'Completed task', 'Deployed v1.0' }
}

local function ShowUsecase_TimelineCard()
    local state = timeline_card_state

    imgui.TextWrapped('Timeline/Activity feed card with staggered animation.')

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    state.anim_time = state.anim_time + dt

    local pos = imgui.GetCursorScreenPosVec()
    local item_height = 50 * scale

    for i = 0, 3 do
        -- Staggered entrance
        local item_progress = math.min(math.max((state.anim_time - i * 0.15) * 2.0, 0.0), 1.0)

        local item_x = iam.TweenFloat(ImHashStr('tl_x_' .. i), state.item_x_ids[i + 1],
            item_progress > 0.5 and 0.0 or - 30 * scale, 0.3, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)

        local item_alpha = item_progress
        local item_pos = ImVec2(pos.x + 20 * scale + item_x, pos.y + i * item_height)

        -- Timeline line
        if i < 3 then
            dl:AddLine(ImVec2(pos.x + 8 * scale, item_pos.y + 12 * scale),
                ImVec2(pos.x + 8 * scale, item_pos.y + item_height),
                IM_COL32(60, 65, 75, math.floor(item_alpha * 255)), 2 * scale)
        end

        -- Timeline dot
        dl:AddCircleFilled(ImVec2(pos.x + 8 * scale, item_pos.y + 8 * scale),
            5 * scale, IM_COL32(70, 130, 180, math.floor(item_alpha * 255)))

        -- Event text
        dl:AddText(item_pos, IM_COL32(255, 255, 255, math.floor(item_alpha * 255)), state.events[i + 1])
        dl:AddText(ImVec2(item_pos.x, item_pos.y + 18 * scale),
            IM_COL32(100, 100, 110, math.floor(item_alpha * 255)), '2 hours ago')
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + 4 * item_height + 10 * scale)
    if imgui.Button('Replay') then
        state.anim_time = 0.0
    end
end

local function RunCardsAndContentDemo()
    -- ========================================
    -- CARDS & CONTENT
    -- ========================================
    common.ApplyOpenAll()
    if imgui.CollapsingHeader("Cards & Content") then
        imgui.Indent()
        common.USECASE_ITEM('Card Hover Effects', ShowUsecase_CardHover)
        common.USECASE_ITEM('Flip Card', ShowUsecase_FlipCard)
        common.USECASE_ITEM('Swipe Cards', ShowUsecase_SwipeCards)
        common.USECASE_ITEM('Carousel / Image Slider', ShowUsecase_Carousel)
        common.USECASE_ITEM('Expandable List Item', ShowUsecase_ExpandableListItem)
        common.USECASE_ITEM('Image Gallery Grid', ShowUsecase_ImageGalleryGrid)
        common.USECASE_ITEM('Stacked Cards', ShowUsecase_StackedCards)
        common.USECASE_ITEM('Notification Card', ShowUsecase_NotificationCard)
        common.USECASE_ITEM('Music Player', ShowUsecase_ProductCard)
        common.USECASE_ITEM('Timeline Card', ShowUsecase_TimelineCard)
        imgui.Unindent()
    end
end

return RunCardsAndContentDemo
