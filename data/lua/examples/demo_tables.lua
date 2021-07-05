---@type Mq
local mq = require('mq')
ImGui = ImGui or {}


local openGUI = true
local shouldDrawGUI = true

local disable_indent = false

local function HelpMarker(desc)
    ImGui.TextDisabled('(?)')
    if ImGui.IsItemHovered() then
        ImGui.BeginTooltip()
        ImGui.PushTextWrapPos(ImGui.GetFontSize() * 35.0)
        ImGui.Text(desc)
        ImGui.PopTextWrapPos()
        ImGui.EndTooltip()
    end
end

local function dump(o)
    if type(o) == 'table' then
       local s = '{ '
       for k,v in pairs(o) do
          if type(k) ~= 'number' then k = '"'..k..'"' end
          s = s .. '['..k..'] = ' .. dump(v) .. ','
       end
       return s .. '} '
    else
       return tostring(o)
    end
end

local template_items_names = {
    'Banana', 'Apple', 'Cherry', 'Watermelon', 'Grapefruit', 'Strawberry', 'Mango',
    'Kiwi', 'Orange', 'Pineapple', 'Blueberry', 'Plum', 'Coconut', 'Pear', 'Apricot'
}

local sorting_demo_items = nil

local ColumnID_ID = 0
local ColumnID_Name = 1
local ColumnID_Action = 2
local ColumnID_Quantity = 3
local ColumnID_Description = 4

local current_sort_specs = nil
local function CompareWithSortSpecs(a, b)
    for n = 1, current_sort_specs.SpecsCount, 1 do
        -- Here we identify columns using the ColumnUserID value that we ourselves passed to TableSetupColumn()
        -- We could also choose to identify columns based on their index (sort_spec.ColumnIndex), which is simpler!
        local sort_spec = current_sort_specs:Specs(n)
        local delta = 0

        if sort_spec.ColumnUserID == ColumnID_ID then
            delta = a.ID - b.ID
        elseif sort_spec.ColumnUserID == ColumnID_Name then
            if a.Name < b.Name then
                delta = -1
            elseif b.Name < a.Name then
                delta = 1
            else
                delta = 0
            end
        elseif sort_spec.ColumnUserID == ColumnID_Quantity then
            delta = a.Quantity - b.Quantity
        elseif sort_spec.ColumnUserID == ColumnID_Description then
            if a.Name < b.Name then
                delta = -1
            elseif b.Name < a.Name then
                delta = 1
            else
                delta = 0
            end
        end

        if delta ~= 0 then
            if sort_spec.SortDirection == ImGuiSortDirection.Ascending then
                return delta < 0
            end
            return delta > 0
        end
    end

    -- Always return a way to differentiate items.
    -- Your own compare function may want to avoid fallback on implicit sort specs e.g. a Name compare if it wasn't already part of the sort specs.
    return a.ID - b.ID < 0
end

local function ShowTableDemoBackgroundColor(open_action)
    -- Using those as a base value to create width/height that are factor of the size of our font
    local TEXT_BASE_HEIGHT = ImGui.GetTextLineHeightWithSpacing();

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Background color') then
        ImGui.TreePop()
    end
end

local function ShowTableDemoSorting(open_action)
    -- Using those as a base value to create width/height that are factor of the size of our font
    local TEXT_BASE_HEIGHT = ImGui.GetTextLineHeightWithSpacing();

    -- This is a simplified version of the 'Advanced' example, where we mostly focus on the code necessaray to handle sorting.
    -- Note that the 'Advanced' example also showcases manually triggering sort (e.g. if item quantities have been modified)
    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Sorting') then
        HelpMarker('Use Shift+Click to sort on multiple columns')

        -- Create item list
        if not sorting_demo_items then
            sorting_demo_items = {}
            for n = 1, 50 do
                local z = n % #template_items_names
                local item = {
                    ID       = n - 1,
                    Name     = template_items_names[z + 1],
                    Quantity = (n * n - n) % 20
                }
                table.insert(sorting_demo_items, item)
            end
        end

        local flags = bit32.bor(ImGuiTableFlags.Resizable, ImGuiTableFlags.Reorderable, ImGuiTableFlags.Hideable, ImGuiTableFlags.MultiSortable,
            ImGuiTableFlags.RowBg, ImGuiTableFlags.BordersOuter, ImGuiTableFlags.BordersV, ImGuiTableFlags.NoBordersInBody, ImGuiTableFlags.ScrollY)
        if ImGui.BeginTable('##table', 4, flags, 0, TEXT_BASE_HEIGHT * 15, 0.0) then
            -- Declare columns
            -- We use the 'user_id' parameter of TableSetupColumn() to specify a user id that will be stored in the sort specifications.
            -- This is so our sort function can identify a column given our own identifier. We could also identify them based on their index.
            -- Demonstrate using a mixture of flags among available sort-related flags:
            -- - ImGuiTableColumnFlags.DefaultSort
            -- - ImGuiTableColumnFlags.NoSort / ImGuiTableColumnFlags.NoSortAscending / ImGuiTableColumnFlags.NoSortDescending
            -- - ImGuiTableColumnFlags.PreferSortAscending / ImGuiTableColumnFlags.PreferSortDescending
            ImGui.TableSetupColumn('ID',        bit32.bor(ImGuiTableColumnFlags.DefaultSort,         ImGuiTableColumnFlags.WidthFixed),   -1.0, ColumnID_ID)
            ImGui.TableSetupColumn('Name',                                                           ImGuiTableColumnFlags.WidthFixed,    -1.0, ColumnID_Name)
            ImGui.TableSetupColumn('Action',    bit32.bor(ImGuiTableColumnFlags.NoSort,              ImGuiTableColumnFlags.WidthFixed),   -1.0, ColumnID_Action)
            ImGui.TableSetupColumn('Quantity',  bit32.bor(ImGuiTableColumnFlags.PreferSortAscending, ImGuiTableColumnFlags.WidthStretch), -1.0, ColumnID_Quantity)
            ImGui.TableSetupScrollFreeze(0, 1) -- Make row always visible

            local sort_specs = ImGui.TableGetSortSpecs()
            if sort_specs then
                if sort_specs.SpecsDirty then
                    print(string.format('Sort %d items:', #sorting_demo_items))
                    for n = 1, sort_specs.SpecsCount, 1 do
                        -- Here we identify columns using the ColumnUserID value that we ourselves passed to TableSetupColumn()
                        -- We could also choose to identify columns based on their index (sort_spec.ColumnIndex), which is simpler!
                        local sort_spec = sort_specs:Specs(n)
                        print(string.format('  Spec=%d ColumnUserID ColumnIndex=%d SortOrder=%d SortDirection=%d',
                            n, sort_spec.ColumnUserID, sort_spec.ColumnIndex, sort_spec.SortOrder, sort_spec.SortDirection))
                    end

                    if #sorting_demo_items > 1 then
                        current_sort_specs = sort_specs
                        table.sort(sorting_demo_items, CompareWithSortSpecs)
                        current_sort_specs = nil
                    end
                    sort_specs.SpecsDirty = false
                end
            end

            -- Display data
            ImGui.TableHeadersRow()

            local clipper = ImGuiListClipper.new()
            clipper:Begin(#sorting_demo_items)
            while clipper:Step() do
                for row_n = clipper.DisplayStart, clipper.DisplayEnd - 1, 1 do
                    local item = sorting_demo_items[row_n + 1]
                    ImGui.PushID(item)
                    ImGui.TableNextRow()
                    ImGui.TableNextColumn()
                    ImGui.Text(string.format("%04d", item.ID))
                    ImGui.TableNextColumn()
                    ImGui.Text(item.Name)
                    ImGui.TableNextColumn()
                    ImGui.SmallButton('None')
                    ImGui.TableNextColumn()
                    ImGui.Text(string.format('%d', item.Quantity))
                    ImGui.PopID()
                end
            end
            ImGui.EndTable()
        end
        ImGui.TreePop()
    end
end

-- Converted from imgui_demo.cpp
local function ShowDemoWindowTables()
    if not ImGui.CollapsingHeader('Tables & Columns') then
        return
    end

    ImGui.PushID('Tables')

    local open_action = -1
    if ImGui.Button('Open all') then
        open_action = 1
    end
    ImGui.SameLine()
    if ImGui.Button('Close all') then
        open_action = 0
    end
    ImGui.SameLine()

    -- Options
    local disable_indent, pressed = ImGui.Checkbox('Disable tree indentation', disable_indent)
    ImGui.SameLine()
    HelpMarker('Disable the indenting of tree nodes so demo tables can use the full window width.')
    ImGui.Separator()

    if disable_indent then
        ImGui.PushStyleVar(ImGui.ImGuiStyleVar.IndentSpacing, 0.0)
    end

    -- About Style of tables
    -- Most settings are configured on a per-table basis via the flags passed to BeginTable() and TableSetupColumns APIs.
    -- There are however a few settings that are shared and part of the ImGuiStyle structure:
    --   style.CellPadding                        -- Padding within each cell
    --   style.Colors[ImGuiCol_TableHeaderBg]     -- Table header background
    --   style.Colors[ImGuiCol_TableBorderStrong] -- Table outer and header borders
    --   style.Colors[ImGuiCol_TableBorderLight]  -- Table inner borders
    --   style.Colors[ImGuiCol_TableRowBg]        -- Table row background when ImGuiTableFlags_RowBg is enabled (even rows)
    --   style.Colors[ImGuiCol_TableRowBgAlt]     -- Table row background when ImGuiTableFlags_RowBg is enabled (odd rows)

    -- Demos
    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Basic') then
        -- Here we will showcase three different ways to output a table. They are very simple variations of the same thing!

        -- Basic use of tables using TableNextRow() to create a new row, and TableSetColumnIndex() t o select the column.
        -- In many situations, this is the most flexible and easy to use pattern.
        HelpMarker('Using TableNextRow() + calling TableSetColumnIndex() _before_ each cell, in a loop.')
        if ImGui.BeginTable('##table1', 3) then
            local row, col
            for row = 0, 3 do
                ImGui.TableNextRow()
                for col = 0, 2 do
                    ImGui.TableSetColumnIndex(col)
                    ImGui.Text(string.format('Row %d Column %d', row, col))
                end
            end
            ImGui.EndTable()
        end

        -- This is essentially the same as above, except instead of using a for loop we call TableSetColumnIndex() manually.
        -- Sometimes this makes more sense.
        HelpMarker('Using TableNextRow() + calling TableNextColumn() _before_ each cell, manually.')
        if ImGui.BeginTable('##table2', 3) then
            local row
            for row = 0, 3 do
                ImGui.TableNextRow()
                ImGui.TableNextColumn()
                ImGui.Text(string.format('Row %d', row))
                ImGui.TableNextColumn()
                ImGui.Text(string.format('Some contents'))
                ImGui.TableNextColumn()
                ImGui.Text('123.456')
            end
            ImGui.EndTable()
        end

        -- Another subtle variant, we call TableNextColumn() _before_ each cell. At the end of a row, TableNextColumn() will create a new row.
        -- Note that we never TableNextRow() here
        HelpMarker('Only using TableNextColumn(), which tends to be convenient for tables where every cell contains the same type of contents.\n' ..
            'This is also more similar to the old NextColumn() function of the Columns API, andd provided to facilitate the Columns->Tables API transition.')
        if ImGui.BeginTable('##table4', 3) then
            local item
            for item = 0, 13 do
                ImGui.TableNextColumn()
                ImGui.Text(string.format('Item %d', item))
            end
            ImGui.EndTable()
        end

        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Borders, background') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Resizable, stretch') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Resizable, fixed') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Resizable, mixed') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Reorderable, hideable, with headers') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Explicit widths') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Vertical scrolling, with clipping') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Horizontal scrolling') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Column flags') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Recursive') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Sizing policies, cell contents') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Compact table') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Row height') then
        ImGui.TreePop()
    end

    ShowTableDemoBackgroundColor(open_action)

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Tree view') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Custom headers') then
        ImGui.TreePop()
    end

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Context menus') then
        ImGui.TreePop()
    end

    ShowTableDemoSorting(open_action)

    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Advanced') then
        ImGui.TreePop()
    end

    if disable_indent then
        ImGui.PopStyleVar()
    end
    ImGui.PopID()
end

local function DemoTablesGUI()
    openGUI, shouldDrawGUI = ImGui.Begin('Tables Demo', openGUI)
    if shouldDrawGUI then
        ShowDemoWindowTables()
        ImGui.End()
    end
end

mq.imgui.init('DemoTablesGUI', DemoTablesGUI)

while shouldDrawGUI do
    mq.delay(1000) -- equivalent to '1s'
end