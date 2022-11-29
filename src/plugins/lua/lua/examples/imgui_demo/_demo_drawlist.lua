---@type Mq
local mq = require('mq')
---@type ImGui
local imgui = require 'ImGui'

local openGUI = true
local shouldDrawGUI = true

------------------------------------------------------------------------------------------------------------------------

-- globals used for Primitives section
local sz = 36.0
local thickness = 3.0
local ngon_sides = 6
local circle_segments_override = false
local circle_segments_override_v = 12
local curve_segments_override = false
local curve_segments_override_v = 8
local colf = ImVec4(1.0, 1.0, 0.4, 1.0)

-- globals used for Canvas section
local points = {}
local scrolling = ImVec2(0, 0)
local opt_enable_grid = true
local opt_enable_context_menu = true
local adding_line = false

-- globals used for BG/FG draw lists
local draw_bg = true
local draw_fg = true

function ShowExampleAppCustomRendering(open)
    local show
    open, show = imgui.Begin("Example: Custom rendering (lua)", open)
    if not show then
        imgui.End()
        return open
    end

    if imgui.BeginTabBar('##TabBar') then
        if imgui.BeginTabItem('Primitives') then
            imgui.PushItemWidth(-imgui.GetFontSize() * 15)
            local draw_list = imgui.GetWindowDrawList()

            -- Draw gradients
            -- (note that those are currently exacerbating our sRGB/Linear issues)
            -- Calling ImGui::GetColorU32() multiplies the given colors by the current Style Alpha, but you may pass the IM_COL32() directly as well..
            imgui.Text('Gradients')
            local gradient_size = ImVec2(imgui.CalcItemWidth(), imgui.GetFrameHeight())
            local changed

            -- 1
            local p0 = imgui.GetCursorScreenPosVec()
            local p1 = ImVec2(p0.x + gradient_size.x, p0.y + gradient_size.y)
            local col_a = IM_COL32(0, 0, 0, 255)
            local col_b = IM_COL32(255, 255, 255, 255)

            draw_list:AddRectFilledMultiColor(p0, p1, col_a, col_b, col_b, col_a)
            imgui.InvisibleButton('##gradient1', gradient_size)

            -- 2
            p0 = imgui.GetCursorScreenPosVec()
            p1 = ImVec2(p0.x + gradient_size.x, p0.y + gradient_size.y)
            col_a = IM_COL32(0, 255, 0, 255)
            col_b = IM_COL32(255, 0, 0, 255)

            draw_list:AddRectFilledMultiColor(p0, p1, col_a, col_b, col_b, col_a)
            imgui.InvisibleButton('##gradient2', gradient_size)

            -- Draw a bunch of primitives
            imgui.Text('All primitives')
            sz = imgui.DragFloat('Size', sz, 0.2, 2.0, 100.0, "%.0f")
            thickness = imgui.DragFloat('Thickness', thickness, 0.05, 1.0, 8.0, "%.02f")
            ngon_sides = imgui.SliderInt('N-gon sides', ngon_sides, 3, 12)
            circle_segments_override = imgui.Checkbox('##circlesegmentoverride', circle_segments_override)
            imgui.SameLine(0.0, imgui.GetStyle().ItemInnerSpacing.x)
            circle_segments_override_v, changed = imgui.SliderInt('Circle segments override', circle_segments_override_v, 3, 40)
            if changed then circle_segments_override = true end
            curve_segments_override = imgui.Checkbox('##curvesegmentoverride', curve_segments_override)
            imgui.SameLine(0.0, imgui.GetStyle().ItemInnerSpacing.x)
            curve_segments_override_v, changed = imgui.SliderInt('Curves segments override', curve_segments_override_v, 3, 40)
            if changed then curve_segments_override = true end
            colf = imgui.ColorEdit4('Color', colf)

            local p = imgui.GetCursorScreenPosVec()
            local col = imgui.GetColorU32(colf)
            local spacing = 10.0

            local corners_tl_br = bit32.bor(ImDrawFlags.RoundCornersTopLeft, ImDrawFlags.RoundCornersBottomRight)
            local rounding = sz / 5.0
            local circle_segments = circle_segments_override and circle_segments_override_v or 0
            local curve_segments = curve_segments_override and curve_segments_override_v or 0
            local x = p.x + 4.0
            local y = p.y + 4.0

            for n = 1, 2 do
                -- First line uses a thickness of 1.0, second line uses the configurable thickness
                local th = n == 1 and 1.0 or thickness

                -- N-gon
                draw_list:AddNgon(ImVec2(x + sz * 0.5, y + sz * 0.5), sz * 0.5, col, ngon_sides, th)
                x = x + sz + spacing

                -- Circle
                draw_list:AddCircle(ImVec2(x + sz * 0.5, y + sz * 0.5), sz * 0.5, col, circle_segments, th)
                x = x + sz + spacing

                -- Square
                draw_list:AddRect(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 0.0, ImDrawFlags.None, th)
                x = x + sz + spacing

                -- Triangle
                draw_list:AddTriangle(ImVec2(x + sz * 0.5, y), ImVec2(x + sz, y + sz - 0.5), ImVec2(x, y + sz - 0.5), col, th)
                x = x + sz + spacing

                -- Horizontal line (note: drawing a filled rectangle will be faster)
                draw_list:AddLine(ImVec2(x, y), ImVec2(x + sz, y), col, th)
                x = x + sz + spacing

                -- Vertical line
                draw_list:AddLine(ImVec2(x, y), ImVec2(x, y + sz), col, th)
                x = x + spacing

                -- Diagonal line
                draw_list:AddLine(ImVec2(x, y), ImVec2(x + sz, y + sz), col, th)
                x = x + sz + spacing

                -- Quadratic bezier curve (3 control points)
                local cp3 = {
                    ImVec2(x, y + sz * 0.6), ImVec2(x + sz * 0.5, y - sz * 0.4), ImVec2(x + sz, y + sz)
                }
                draw_list:AddBezierQuadratic(cp3[1], cp3[2], cp3[3], col, th, curve_segments)
                x = x + sz + spacing

                -- Cubic bezier curve (4 control points)
                local cp4 = {
                    ImVec2(x, y),
                    ImVec2(x + sz * 1.3, y + sz * 0.3),
                    ImVec2(x + sz - sz * 1.3, y + sz - sz * 0.3),
                    ImVec2(x + sz, y + sz)
                }
                draw_list:AddBezierCubic(cp4[1], cp4[2], cp4[3], cp4[4], col, th, curve_segments)

                x = p.x + 4
                y = y + sz + spacing
            end

            -- N-gon
            draw_list:AddNgonFilled(ImVec2(x + sz * 0.5, y + sz * 0.5), sz * 0.5, col, ngon_sides)
            x = x + sz + spacing;

            -- Circle
            draw_list:AddCircleFilled(ImVec2(x + sz * 0.5, y + sz * 0.5), sz * 0.5, col, circle_segments)
            x = x + sz + spacing;

            -- Square
            draw_list:AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col)
            x = x + sz + spacing;

            -- Square with all rounded corners
            draw_list:AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 10.0)
            x = x + sz + spacing

            -- Square with two rounded corners
            draw_list:AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 10.0, corners_tl_br)
            x = x + sz + spacing;

            -- Triangle
            draw_list:AddTriangleFilled(ImVec2(x+sz * 0.5, y), ImVec2(x + sz, y + sz - 0.5), ImVec2(x, y + sz - 0.5), col)
            x = x + sz + spacing

            -- Horizontal line (faster than AddLine, but only handle integer thickness)
            draw_list:AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + thickness), col)
            x = x + sz + spacing

            -- Vertical line (faster than AddLine, but only handle integer thickness)
            draw_list:AddRectFilled(ImVec2(x, y), ImVec2(x + thickness, y + sz), col)
            x = x + spacing * 2.0

            -- Pixel (faster than AddLine)
            draw_list:AddRectFilled(ImVec2(x, y), ImVec2(x + 1, y + 1), col)
            x = x + sz;

            draw_list:AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + sz, y + sz), IM_COL32(0, 0, 0, 255),
                IM_COL32(255, 0, 0, 255), IM_COL32(255, 255, 0, 255), IM_COL32(0, 255, 0, 255));

            imgui.Dummy((sz + spacing) * 10.2, (sz + spacing) * 3.0)

            imgui.PopItemWidth()
            imgui.EndTabItem()
        end

        if imgui.BeginTabItem('Canvas') then
            opt_enable_grid = imgui.Checkbox('Enable grid', opt_enable_grid)
            opt_enable_context_menu = imgui.Checkbox('Enable context menu', opt_enable_context_menu)
            local io = imgui.GetIO()

            imgui.Text('Mouse Left: drag to add lines,\nMouse Right: drag to scroll, click for context menu')

            -- Typically you would use a BeginChild()/EndChild() pair to benefit from a clipping region + own scrolling.
            -- Here we demonstrate that this can be replaced by simple offsetting + custom drawing + PushClipRect/PopClipRect() calls.
            -- To use a child window instead we could use, e.g:
            --      ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));      // Disable padding
            --      ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(50, 50, 50, 255));  // Set a background color
            --      ImGui::BeginChild("canvas", ImVec2(0.0f, 0.0f), true, ImGuiWindowFlags_NoMove);
            --      ImGui::PopStyleColor();
            --      ImGui::PopStyleVar();
            --      [...]
            --      ImGui::EndChild();

            -- Using InvisibleButton() as a convenience 1) it will advance the layout cursor and 2) allows us to use IsItemHovered()/IsItemActive()
            local canvas_p0 = imgui.GetCursorScreenPosVec()
            local canvas_sz = imgui.GetContentRegionAvailVec()
            if canvas_sz.x < 50.0 then canvas_sz.x = 50.0 end
            if canvas_sz.y < 50.0 then canvas_sz.y = 50.0 end

            local canvas_p1 = ImVec2(canvas_p0.x + canvas_sz.x, canvas_p0.y + canvas_sz.y)

            -- Draw border and background color
            local draw_list = imgui.GetWindowDrawList()
            draw_list:AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255))
            draw_list:AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255))

            -- This will catch our interactions
            imgui.InvisibleButton('canvas', canvas_sz, bit32.bor(ImGuiButtonFlags.MouseButtonLeft, ImGuiButtonFlags.MouseButtonRight))
            local is_hovered = imgui.IsItemHovered()
            local is_active = imgui.IsItemActive()
            local origin = ImVec2(canvas_p0.x + scrolling.x, canvas_p0.y + scrolling.y)
            local mouse = imgui.GetMousePosVec()
            local mouse_pos_in_canvas = ImVec2(mouse.x - origin.x, mouse.y - origin.y)

            -- Add first and second point
            if is_hovered and not adding_line and imgui.IsMouseClicked(ImGuiMouseButton.Left) then
                table.insert(points, mouse_pos_in_canvas)
                table.insert(points, mouse_pos_in_canvas)
                adding_line = true
            end
            if adding_line then
                points[#points] = mouse_pos_in_canvas
                if not imgui.IsMouseDown(ImGuiMouseButton.Left) then
                    adding_line = false
                end
            end

            -- Pan (we use a zero mouse threshold when there's no context menu)
            -- You may decide to make that threshold dynamic based on whether the mouse is hovering something etc.
            local mouse_threshold_for_pan = opt_enable_context_menu and -1 or 0
            if is_active and imgui.IsMouseDragging(ImGuiMouseButton.Right, mouse_threshold_for_pan) then
                scrolling = scrolling + io.MouseDelta
            end

            -- Context menu (under default mouse threshold)
            local drag_delta = imgui.GetMouseDragDeltaVec(ImGuiMouseButton.Right)
            if opt_enable_context_menu and imgui.IsMouseReleased(ImGuiMouseButton.Right) and drag_delta.x == 0 and drag_delta.y == 0 then
                imgui.OpenPopupOnItemClick("context")
            end
            if imgui.BeginPopup("context") then
                if adding_line then
                    table.remove(points, #points)
                    table.remove(points, #points)
                end
                adding_line = false

                if imgui.MenuItem("Remove one", "", false, #points > 0) then
                    table.remove(points, #points)
                    table.remove(points, #points)
                end
                if imgui.MenuItem("Remove all", "", false, #points > 0) then
                    points = {}
                end

                imgui.EndPopup()
            end

            -- draw grid + all lines in the canvas
            draw_list:PushClipRect(canvas_p0, canvas_p1, true)
            if opt_enable_grid then
                local GRID_STEP = 64.0
                for x = math.fmod(scrolling.x, GRID_STEP), canvas_sz.x - 1, GRID_STEP do
                    draw_list:AddLine(ImVec2(canvas_p0.x + x, canvas_p0.y), ImVec2(canvas_p0.x + x, canvas_p1.y), IM_COL32(200, 200, 200, 40))
                end
                for y = math.fmod(scrolling.y, GRID_STEP), canvas_sz.y - 1, GRID_STEP do
                    draw_list:AddLine(ImVec2(canvas_p0.x, canvas_p0.y + y), ImVec2(canvas_p1.x, canvas_p0.y + y), IM_COL32(200, 200, 200, 40))
                end
            end
            for n = 1, #points, 2 do
                draw_list:AddLine(ImVec2(origin.x + points[n].x, origin.y + points[n].y), ImVec2(origin.x + points[n + 1].x, origin.y + points[n + 1].y), IM_COL32(255, 255, 0, 255), 2.0)
            end

            draw_list:PopClipRect()
            imgui.EndTabItem()
        end

        if imgui.BeginTabItem('BG/FG draw lists') then
            draw_bg = imgui.Checkbox("Draw in Background draw list", draw_bg)
            imgui.SameLine()
            imgui.HelpMarker("The Background draw list will be rendered below every Dear ImGui window.")

            draw_fg = imgui.Checkbox("Draw in foreground draw list", draw_fg)
            imgui.SameLine()
            imgui.HelpMarker("The Foreground draw list will be rendered over every Dear ImGui window.")

            local window_pos = imgui.GetWindowPosVec()
            local window_size = imgui.GetWindowSizeVec()
            local window_center = ImVec2(window_pos.x + window_size.x * 0.5, window_pos.y + window_size.y * 0.5)
            if draw_bg then
                imgui.GetBackgroundDrawList():AddCircle(window_center, window_size.x * 0.6, IM_COL32(255, 0, 0, 200), 0, 10 + 4)
            end
            if draw_fg then
                imgui.GetForegroundDrawList():AddCircle(window_center, window_size.x * 0.6, IM_COL32(0, 255, 0, 200), 0, 10)
            end

            imgui.EndTabItem()
        end

        imgui.EndTabBar()
    end

    imgui.End()
    return open
end

return ShowExampleAppCustomRendering
