---@type Mq
local mq = require('mq')
require 'ImGui'

-- Using those as a base value to create width/height that are factor of the size of our font
local TEXT_BASE_WIDTH, _ = ImGui.CalcTextSize("A")
local TEXT_BASE_HEIGHT = ImGui.GetTextLineHeightWithSpacing();

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

local function PushStyleCompact()
    local style = ImGui.GetStyle()
    ImGui.PushStyleVar(ImGuiStyleVar.FramePadding, ImVec2.new(style.FramePadding.x, style.FramePadding.y * 0.70))
    ImGui.PushStyleVar(ImGuiStyleVar.ItemSpacing, ImVec2.new(style.ItemSpacing.x, style.ItemSpacing.y * 0.70))
end

local function PopStyleCompact()
    ImGui.PopStyleVar(2)
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

local function class(base, init)
    local c = {}    -- a new class instance
    if not init and type(base) == 'function' then
       init = base
       base = nil
    elseif type(base) == 'table' then
     -- our new class is a shallow copy of the base class!
       for i,v in pairs(base) do
          c[i] = v
       end
       c._base = base
    end
    -- the class will be the metatable for all its objects,
    -- and they will look up their methods in it.
    c.__index = c
 
    -- expose a constructor which can be called by <classname>(<args>)
    local mt = {}
    mt.__call = function(class_tbl, ...)
    local obj = {}
    setmetatable(obj,c)
    if init then
       init(obj,...)
    else 
       -- make sure that any stuff from the base class is initialized!
       if base and base.init then
       base.init(obj, ...)
       end
    end
    return obj
    end
    c.init = init
    c.is_a = function(self, klass)
       local m = getmetatable(self)
       while m do 
          if m == klass then return true end
          m = m._base
       end
       return false
    end
    setmetatable(c, mt)
    return c
 end

------------------------------------------------------------------------------------------------------------------------

local bgcolor_table_flags = ImGuiTableFlags.RowBg
local row_bg_type = 1
local row_bg_target = 1
local cell_bg_type = 1

local function ShowTableDemoBackgroundColor(open_action)
    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Background color') then
        PushStyleCompact()
        bgcolor_table_flags = ImGui.CheckboxFlags('ImGuiTableFlags.Borders', bgcolor_table_flags, ImGuiTableFlags.Borders)
        bgcolor_table_flags = ImGui.CheckboxFlags('ImGuiTableFlags.RowBg', bgcolor_table_flags, ImGuiTableFlags.RowBg)
        ImGui.SameLine(); HelpMarker('ImGuiTableFlags_RowBg automatically sets RowBg0 to alternative colors pulled from the Style.')
        row_bg_type = ImGui.Combo('row bg type', row_bg_type, 'None\0Red\0Gradient\0')
        row_bg_target = ImGui.Combo('row bg target', row_bg_target, 'RowBg0\0RowBg1\0'); ImGui.SameLine(); HelpMarker('Target RowBg0 to override the alternating odd/even colors,\nTarget RowBg1 to blend with them.')
        cell_bg_type = ImGui.Combo('cell bg type', cell_bg_type, 'None\0Blue\0'); ImGui.SameLine(); HelpMarker('We are colorizing cells to B1->C2 here.')
        PopStyleCompact()

        if ImGui.BeginTable('##Table', 5, bgcolor_table_flags) then
            for row = 0, 5 do
                ImGui.TableNextRow()


                -- Demonstrate setting a row background color with 'ImGui::TableSetBgColor(ImGuiTableBgTarget_RowBgX, ...)'
                -- We use a transparent color so we can see the one behind in case our target is RowBg1 and RowBg0 was already targeted by the ImGuiTableFlags_RowBg flag.
                if row_bg_type ~= 0 then
                    if row_bg_type == 1 then
                        ImGui.TableSetBgColor(ImGuiTableBgTarget.RowBg0 + row_bg_target, 0.7, 0.3, 0.3, 0.65)
                    else
                        ImGui.TableSetBgColor(ImGuiTableBgTarget.RowBg0 + row_bg_target, 0.2 + row * .1, 0.2, 0.2, 0.65)
                    end
                end

                -- Fill cells
                for column = 0, 4 do
                    ImGui.TableSetColumnIndex(column)
                    ImGui.Text(string.format('%c%c', string.byte('A') + row, string.byte('0') + column))

                    -- Change background of Cells B1->C2
                    -- Demonstrate setting a cell background color with 'ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, ...)'
                    -- (the CellBg color will be blended over the RowBg and ColumnBg colors)
                    -- We can also pass a column number as a third parameter to TableSetBgColor() and do this outside the column loop.
                    if row >= 1 and row <= 2 and column >= 1 and column <= 2 and cell_bg_type == 1 then
                        ImGui.TableSetBgColor(ImGuiTableBgTarget.CellBg, 0.3, 0.3, 0.7, 0.65)
                    end
                end
            end
            ImGui.EndTable()
        end
        ImGui.TreePop()
    end
end

------------------------------------------------------------------------------------------------------------------------

local treeview_table_flags = bit32.bor(ImGuiTableFlags.BordersV, ImGuiTableFlags.BordersOuterH, ImGuiTableFlags.Resizable, ImGuiTableFlags.RowBg, ImGuiTableFlags.NoBordersInBody)

MyTreeNode = class(function(inst, name, type, size, childIdx, childCount)
    inst.Name = name
    inst.Type = type
    inst.Size = size
    inst.ChildIdx = childIdx
    inst.ChildCount = childCount
end)

function MyTreeNode:new(name, type, size, childIdx, childCount)
    local o = {}
    setmetatable(o, MyTreeNode)
    o.Name = name
    o.Type = type
    o.Size = size
    o.ChildIdx = childIdx
    o.ChildCount = childCount
    return o
end

function MyTreeNode:display(all_nodes)
    ImGui.TableNextRow()
    ImGui.TableNextColumn()

    local is_folder = self.ChildCount > 0
    if is_folder then
        local open = ImGui.TreeNodeEx(self.Name, ImGuiTreeNodeFlags.SpanFullWidth)
        ImGui.TableNextColumn()
        ImGui.TextDisabled('--')
        ImGui.TableNextColumn()
        ImGui.Text(self.Type)
        if open then
            for child_n = 1, self.ChildCount do
                all_nodes[self.ChildIdx + child_n]:display(all_nodes)
            end
            ImGui.TreePop()
        end
    else
        ImGui.TreeNodeEx(self.Name, bit32.bor(ImGuiTreeNodeFlags.Leaf, ImGuiTreeNodeFlags.Bullet, ImGuiTreeNodeFlags.NoTreePushOnOpen, ImGuiTreeNodeFlags.SpanFullWidth))
        ImGui.TableNextColumn()
        ImGui.Text(string.format('%d', self.Size))
        ImGui.TableNextColumn()
        ImGui.Text(self.Type)
    end
end

local treeview_nodes = {
    MyTreeNode("Root",                          "Folder",      -1,      1, 3),
    MyTreeNode("Music",                         "Folder",      -1,      4, 2),
    MyTreeNode("Textures",                      "Folder",      -1,      6, 3),
    MyTreeNode("desktop.ini",                   "System file", 1024,   -1,-1),
    MyTreeNode("File1_a.wav",                   "Audio file",  123000, -1,-1),
    MyTreeNode("File1_b.wav",                   "Audio file",  456000, -1,-1),
    MyTreeNode("Image001.png",                  "Image file",  203128, -1,-1),
    MyTreeNode("Copy of Image001.png",          "Image file",  203256, -1,-1),
    MyTreeNode("Copy of Image001 (Final2).png", "Image file",  203512, -1,-1),
}

local function ShowTableDemoTreeView(open_action)
    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Tree view') then
        if ImGui.BeginTable('##3ways', 3, treeview_table_flags) then
            -- The first column will use the default _WidthStretch when ScrollX is Off and _WidthFixed when ScrollX is On
            ImGui.TableSetupColumn('Name', ImGuiTableColumnFlags.NoHide)
            ImGui.TableSetupColumn('Size', ImGuiTableColumnFlags.WidthFixed, TEXT_BASE_WIDTH * 12.0)
            ImGui.TableSetupColumn('Type', ImGuiTableColumnFlags.WidthFixed, TEXT_BASE_WIDTH * 18.0)

            treeview_nodes[1]:display(treeview_nodes)

            ImGui.EndTable()
        end

        ImGui.TreePop()
    end
end

------------------------------------------------------------------------------------------------------------------------

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

local tableSorting_flags = bit32.bor(ImGuiTableFlags.Resizable,
                                     ImGuiTableFlags.Reorderable,
                                     ImGuiTableFlags.Hideable,
                                     ImGuiTableFlags.Sortable,
                                     ImGuiTableFlags.SortMulti,
                                     ImGuiTableFlags.RowBg,
                                     ImGuiTableFlags.BordersOuter,
                                     ImGuiTableFlags.BordersV,
                                     ImGuiTableFlags.NoBordersInBody,
                                     ImGuiTableFlags.ScrollY)

local function ShowTableDemoSorting(open_action)
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

        PushStyleCompact()
        tableSorting_flags = ImGui.CheckboxFlags('ImGuiTableFlags.SortMulti', tableSorting_flags, ImGuiTableFlags.SortMulti)
        ImGui.SameLine(); HelpMarker('When sorting is enabled: hold shift when clicking headers to sort on multiple column. TableGetSortSpecs() may return specs where (SpecsCount > 1).')
        tableSorting_flags = ImGui.CheckboxFlags('ImGuiTableFlags.SortTristate', tableSorting_flags, ImGuiTableFlags.SortTristate)
        ImGui.SameLine(); HelpMarker('When sorting is enabled: allow no sorting, disable default sorting. TableGetSortSpecs() may return specs where (SpecsCount == 0).')
        PopStyleCompact()

        if ImGui.BeginTable('table_sorting', 4, tableSorting_flags, 0, TEXT_BASE_HEIGHT * 15, 0.0) then
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
    disable_indent, pressed = ImGui.Checkbox('Disable tree indentation', disable_indent)
    ImGui.SameLine()
    HelpMarker('Disable the indenting of tree nodes so demo tables can use the full window width.')
    ImGui.Separator()

    if disable_indent then
        ImGui.PushStyleVar(ImGuiStyleVar.IndentSpacing, 0.0)
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

    --[[
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
    --]]

    ShowTableDemoBackgroundColor(open_action)

    ShowTableDemoTreeView(open_action)

    --[[
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
    --]]

    ShowTableDemoSorting(open_action)

    --[[
    if open_action ~= -1 then
        ImGui.SetNextItemOpen(open_action ~= 0)
    end
    if ImGui.TreeNode('Advanced') then
        ImGui.TreePop()
    end
    --]]

    if disable_indent then
        ImGui.PopStyleVar()
    end
    ImGui.PopID()
end

function DemoTablesGUI()
    if not openGUI then return end
    openGUI, shouldDrawGUI = ImGui.Begin('Tables Demo', openGUI)
    if shouldDrawGUI then
        ShowDemoWindowTables()
    end
    ImGui.End()
end
ImGui.Register('DemoTablesGUI', DemoTablesGUI)

while openGUI do
    mq.delay(1000) -- equivalent to '1s'
end