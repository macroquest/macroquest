--- @type Mq
local mq = require'mq'

--- @type ImGui
local imgui = require'ImGui'

local plugin = mq.plugin('spawninfo', '0.0.1')

plugin.settings = {}
plugin.settings.check_interval_ms = nil
plugin.settings.filters = nil

-- primary callback used in this plugin will be imgui
function plugin.SpawnListCompare(sort_specs, column_id)
  return function(a, b)
    for n = 1, sort_specs.SpecsCount, 1 do
      local sort_spec = sort_specs:Specs(n)
      local delta = 0

      if sort_spec.ColumnUserID == column_id.name then
        if a.Name < b.Name then
          delta = -1
        elseif b.Name < a.Name then
          delta = 1
        end
      elseif sort_spec.ColumnUserID == column_id.distance then
        delta = a.DistSquared - b.DistSquared
      end

      if delta ~= 0 then
        if sort_spec.SortDirection == ImGuiSortDirection.Ascending then
          return delta < 0
        end

        return delta > 0
      end
    end
  end
end

function plugin:DrawSpawnList()
  if not self.is_list_open then return end
  local is_drawn = false
  self.is_list_open, is_drawn = imgui.Begin('Spawn List', self.is_list_open)
  if is_drawn then
    -- set the flags for the table
    local flags = bit32.bor(
      ImGuiTableFlags.Resizable,
      ImGuiTableFlags.Reorderable,
      ImGuiTableFlags.Hideable,
      ImGuiTableFlags.Sortable,
      ImGuiTableFlags.SortMulti,
      ImGuiTableFlags.RowBg,
      ImGuiTableFlags.BordersOuter,
      ImGuiTableFlags.BordersV,
      ImGuiTableFlags.NoBordersInBody,
      ImGuiTableFlags.ScrollY
    )

    -- TODO: Add direction arrow based on heading once the draw list is implemented
    if imgui.BeginTable('spawns_table##spawnlist', 2, flags, 0, imgui.GetTextLineHeightWithSpacing() * 15, 0) then
      local column_id = { name = 1, distance = 2 }
      imgui.TableSetupColumn('Name##spawnlist', ImGuiTableColumnFlags.WidthStretch, 0, column_id.name)
      imgui.TableSetupColumn('Distance##spawnlist', bit32.bor(ImGuiTableColumnFlags.DefaultSort, ImGuiTableColumnFlags.WidthStretch, ImGuiTableColumnFlags.PreferSortAscending), 0, column_id.distance)
      imgui.TableSetupScrollFreeze(0, 1)

      local sort_specs = imgui.TableGetSortSpecs()
      if sort_specs and (sort_specs.SpecsDirty or self.dirty_spawns) then
        if #self.spawns > 1 then
          -- sort the list
          table.sort(self.spawns, self.SpawnListCompare(sort_specs, column_id))
        end
        sort_specs.SpecsDirty = false
        self.dirty_spawns = false
      end

      imgui.TableHeadersRow()

      local clipper = ImGuiListClipper.new()
      clipper:Begin(#self.spawns)
      while clipper:Step() do
        for row_n = clipper.DisplayStart, clipper.DisplayEnd - 1, 1 do
          local spawn = self.spawns[row_n + 1]
          imgui.PushID(spawn.ID)
          imgui.TableNextRow()
          imgui.TableNextColumn()
          if imgui.Selectable(spawn.Name, false, bit32.bor(ImGuiSelectableFlags.SpanAllColumns, ImGuiSelectableFlags.AllowDoubleClick)) and imgui.IsMouseDoubleClicked (0) then
            self.open_details[spawn.ID] = true
          end
          imgui.TableNextColumn()
          if not spawn.Distance then spawn.Distance = math.sqrt(spawn.DistSquared) end
          imgui.Text(string.format('%.2f', spawn.Distance))
          imgui.PopID()
        end
      end

      imgui.EndTable()
    end

    if imgui.Button('Config##spawnlist') then
      self.is_config_open = true
    end
  end
  imgui.End()
end

function plugin:DrawConfig()
  if not self.is_config_open then return end
  local is_drawn = false
  self.is_config_open, is_drawn = imgui.Begin('SpawnInfo Config', self.is_config_open)
  if is_drawn then
    self.is_list_open = imgui.Checkbox('List Open##spawnconfig', self.is_list_open)

    -- initialize filters if it doesn't exist
    if not self.settings.filters then self.settings.filters = {} end

    local name_filter_toggle, name_filter_pressed = imgui.Checkbox('Filter Name##spawnconfig', self.settings.filters['name_enabled'] or false)
    imgui.SameLine()
    local name_filter_entered = false
    self.settings.filters['name'], name_filter_entered = imgui.InputText('##filter##spawnconfig', self.settings.filters['name'] or '')
    if name_filter_pressed or name_filter_entered then
      if not name_filter_toggle then
        self.settings.filters['name_enabled'] = nil
        self.filter_functions['name'] = nil
      else
        self.settings.filters['name_enabled'] = true
        self.filter_functions['name'] = self:FilterByName()
      end
    end

    local rad_filter_toggle, rad_filter_pressed = imgui.Checkbox('Radius##spawnconfig', self.settings.filters['radius_squared'] ~= nil)
    imgui.SameLine()
    local rad_filter, rad_filter_entered = imgui.InputInt('##radius##spawnconfig', self.settings.filters['radius'] or 0)
    if rad_filter_pressed or rad_filter_entered then
      if not rad_filter_toggle then
        self.settings.filters['radius_squared'] = nil
        self.settings.filters['radius'] = rad_filter
      else
        self.settings.filters['radius'] = rad_filter
        self.settings.filters['radius_squared'] = math.pow(rad_filter, 2)
      end
    end

    if imgui.Button('Force Spawn Refresh##spawnconfig') then
      self.last_check_time = 0
    end

    imgui.SameLine()

    if imgui.Button('Save Config##spawnconfig') then
      mq.pickle('spawninfo.conf.lua', self.settings)
    end
  end
  imgui.End()
end

function plugin:DrawDetail(id, is_open)
  local spawn = mq.TLO.Spawn(id)
  if not spawn() or not mq.TLO.Me() or not is_open then
    -- remove it from the list if it's not open, we'll re-add it if it needs to be opened again
    self.open_details[id] = nil
    return
  end

  local is_drawn = false
  self.open_details[id], is_drawn = imgui.Begin(string.format('Spawn: %s', spawn.DisplayName()), self.open_details[id])
  if is_drawn then
    if imgui.BeginTable('spawns_table##spawnlist', 3, 0, 0, imgui.GetTextLineHeightWithSpacing() * 15, 0) then
      imgui.TableSetupColumn(string.format('Name##spawndetail%s', spawn.Name()), ImGuiTableColumnFlags.WidthStretch, 0, 1)
      imgui.TableSetupColumn(string.format('Distance##spawndetail%s', spawn.Name()), ImGuiTableColumnFlags.WidthStretch, 0, 2)
      imgui.TableSetupColumn(string.format('Heading##spawndetail%s', spawn.Name()), ImGuiTableColumnFlags.WidthStretch, 0, 3)
      
      imgui.TableHeadersRow()

      -- single entry table
      imgui.PushID(spawn.ID())
      imgui.TableNextRow()
      imgui.TableNextColumn()
      imgui.Text(spawn.DisplayName())
      imgui.TableNextColumn()
      imgui.Text(string.format('%.2f', spawn.Distance()))
      imgui.TableNextColumn()
      local heading = mq.TLO.Me.Heading.DegreesCCW() - spawn.HeadingTo.DegreesCCW()
      if heading < 0 then heading = heading + 360 end
      imgui.Text(string.format('%.2f', heading))
      imgui.PopID()

      imgui.EndTable()
    end
  end
  imgui.End()
end

function plugin:OnUpdateImGui()
  self:DrawSpawnList()
  self:DrawConfig()

  for id, is_open in pairs(self.open_details) do
    self:DrawDetail(id, is_open)
  end
end

function plugin:OnPulse()
  local current_time = mq.gettime()
  if not self.last_check_time or self.last_check_time + (self.settings.check_interval_ms or 1000) < current_time then
    self:PopulateSpawns()
    self.last_check_time = current_time
  end
end

-- create a command that will open/close the window
function plugin:SpawnInfoCommand(line)
  self.is_list_open = not self.is_list_open
end

-- finally let's create a datatype and register it to a TLO for information
-- Members need to return a tuple of MQ typename (as a string) and the value
plugin.spawninfotype = {
  Members = {
    ListOpen = function(val, index) return 'string', tostring(val.is_list_open) end, -- could also specify (self, val, index),
    NameFilter = function(val, index) return 'string', (val.settings.filters or {})['name'] end,
    NameEnabled = function(val, index) return 'bool', (val.settings.filters or {})['name_enabled'] or false end,
    RadiusFilter = function(val, index) return 'int', (val.settings.filters or {})['radius'] end,
    RadiusEnabled = function(val, index) return 'bool', (val.settings.filters or {})['radius_squared'] ~= nil end,
  },
  Methods = {
    RefreshSpawns = function(val, index) val.last_check_time = 0 end,
  },
  ToString = function(val) return tostring(val.is_list_open) end, -- could also specify function(self, val) if the val isn't expected to be a plugin
  -- FromData = function(source) or function(self, source) -- we don't want to specify setters for this type
  -- FromString = function(source) for function(self, source) -- same thing, no setter
}

-- this is similar to members function in that it needs to return the type name in addition to the value
function plugin:Data(index)
  return 'spawninfo', self
end

function plugin:InitializePlugin()
  local settings = loadfile(mq.configDir .. '/spawninfo.conf.lua')
  if settings then
    self.settings = settings()
  end

  if self.settings.filters and self.settings.filters['name_enabled'] then
    self.filter_functions['name'] = self:FilterByName()
  end

  self:addcommand('/spawninfo', self.SpawnInfoCommand)
  self:addtype('spawninfo', self.spawninfotype)
  self:addtlo('SpawnInfo', self.Data)
end

function plugin:ShutdownPlugin()
  mq.pickle('spawninfo.conf.lua', self.settings)

  self:removecommand('/spawninfo')
  self:removetype('spawninfo')
  self:removetlo('SpawnInfo')
end

plugin.is_list_open = true
plugin.is_config_open = false
plugin.open_details = {}

plugin.filter_functions = {}
function plugin:FilterByName()
	return function(spawn)
		local spawn_name = spawn.Name()
		return spawn_name and string.find(spawn_name, self.settings.filters["name"]) ~= nil
	end
end

function plugin:FilterFunction()
  -- need to return a function here so that we can use self as an upvalue
  -- then we can return the function that needs to be static for mq.getFilteredSpawns()
  return function(spawn)
    local is_valid = true
    for _, func in pairs(self.filter_functions) do
      is_valid = is_valid and func(spawn)

      -- this is just an early out for a small optimization
      if not is_valid then return is_valid end
    end
    return is_valid
  end
end

-- create a spawns list to update every so often in OnPulse
plugin.spawns = {}
plugin.dirty_spawns = false
function plugin:PopulateSpawns()
  local spawns = {}
  if next(self.filter_functions) ~= nil then
    spawns = mq.getFilteredSpawnInfo(self:FilterFunction())
  else
    spawns = mq.getAllSpawnInfo()
  end

  self.spawns = {}
  for _, spawn in ipairs(spawns) do
    local id = spawn.SpawnVar.ID()
    local name = spawn.SpawnVar.Name()
    local dist = spawn.DistSquared

    if id and name and dist then
      -- not sure if we need to nilcheck here, but to be safe
      if not self.settings.filters or not self.settings.filters['radius_squared'] or dist <= self.settings.filters['radius_squared'] then
        table.insert(self.spawns, { ID = id, Name = name, DistSquared = dist })
      end
    end
  end

  self.dirty_spawns = true
end

return plugin