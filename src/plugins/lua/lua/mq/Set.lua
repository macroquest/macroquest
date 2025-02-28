local Set = { _version = '1.0', author = 'Coldblooded' }
Set.__index = Set

---Creates a new set from a table of values
---@param t any
---@return table
function Set.new(t)
    local newSet = setmetatable({}, Set)
    for _, value in ipairs(t) do
        newSet[value] = true
    end
    return newSet
end

---Adds a value to the set
---@param value any
function Set:add(value)
    self[value] = true
end

---Removes a value from the set
---@param value any
function Set:remove(value)
    self[value] = nil
end

---Returns a table of the values in the set
---@return table
function Set:toList()
   local list = {}
   for key in pairs(self) do
       table.insert(list, key)
   end
   return list
end

---Prints the values in the set
function Set:print()
   for key in pairs(self) do
       print(key)
   end
end

---Returns true if the set contains the value(s) provided
---@param valueOrValues any
---@return boolean
function Set:contains(valueOrValues)
    if type(valueOrValues) == 'table' then
        for _, value in ipairs(valueOrValues) do
            if not self[value] then
                return false
            end
        end
        return true
    else
        return self[valueOrValues] ~= nil
    end
end

---Allows the set to be printed as a string
---@return string
function Set:__tostring()
   local elements = {}
   for key in pairs(self) do
       -- Assuming that 'key' can be converted to a string
       table.insert(elements, tostring(key))
   end
   return "{" .. table.concat(elements, ", ") .. "}"
end

setmetatable(Set, { __tostring = Set.__tostring })

return Set