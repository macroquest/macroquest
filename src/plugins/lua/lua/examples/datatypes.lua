
local mq = require 'mq'

local counter = 1

---An example data member
---@param index string The string parameter for the data member
---@param value any The value for the instance of the custom data type being accessed.
---@return string|DataType type The datatype being returned
---@return any value The value of the datatype being returned
function ExampleMember(index, value)
    if index == 'demo' then
        return 'string', 'demo value'
    end

    return 'string', tostring(value)
end

---An example method
---@param index string The string parameter for the method
---@param value any The value for the instance of the custom data type being accessed.
function ResetCounter()
    counter = 0
end

--[[
Construct a new DataType in lua. The first parameter is the name of the
datatype. it must be unique. The second parameter is a table containing the
list of Members and Methods that are available to the datatype.

Each Member function takes up to two parameters:
* index: The index string passed to the data member
* value: The value for the instance of the datatype being queried.

For Methods, the return value is ignored. For Members, two values are
expected to be returned:
* string: The name of the datatype that is being returned. An instance of a datatype
          can be returned here as well, if one is available.
* value:  The value for this new instance of the datatype. This corresponds with
          the value argument in the parameter list.
--]]
local myType = mq.DataType.new('ExampleDataType', {
    Members = {
        -- See the function above
        Value = ExampleMember,

        -- Return a value that is continually changing
        Counter = function ()
            return 'int', counter
        end,

        -- Test the table datatype
        TableTest = function (index)
            if index == 'indexed' then
                return 'table', { 'hello', 'world' }
            elseif index == 'keyed' then
                return 'table', { a = 1, b = 2, c = 3.5, d = true, e = 'tacos' }
            elseif index == 'nil' then
                return 'table', nil
            elseif index == 'empty' then
                return 'table', {}
            elseif index == 'values' then
                return 'table', { 1, 3.5, 'hello', true, { 1, 2 } }
            elseif index == 'invalid' then
                return 'table', 3
            end
        end
    },

    Methods = {
        Echo = function (value) printf('Echo: %s', value) end,
        ResetCounter = ResetCounter,
    }
})

-- Additionally, the ToString function may be overridden to customize the stringified
-- representation of your datatype
function myType.ToString(value)
    local result = '(Nothing)'
    if type(value) == 'string' then
        result = value
    elseif type(value) == 'table' then
        if value.bad then
            return nil
        end

        result = tostring(value.a)
    end

    return 'ExampleDataType.ToString(): ' .. result
end

--- An example TLO function. Similar to a data member, takes an input as a string, and
--- returns a tuple of datatype, value.
---
---@param index string The input string passed to the TLO
---@return string|DataType type The datatype being returned
---@return any value The value of the datatype being returned
local function Test(index)
    if index == 'table' then
        return myType, { a = 1, b = 2 }
    elseif index == 'table_bad' then
        return myType, { bad = true }
    elseif index == 'tablestring' then
        return 'string', { a = 1, b = 2 }
    elseif index == 'string' then
        return 'string', 'Test TLO created from script'
    end

    -- We can also refer to our custom type by name.
    return 'ExampleDataType', { a = 1, b = 2 }
end

-- Register the new TLO with the macro system. DataTypes are automatically registered
-- when they are created. TLOs are not and need to be manually associated with a name.
-- The TLO will stay registered as long as the script is running. It can also be manually
-- unregistered with mq.RemoveTopLevelObject('Example').
mq.AddTopLevelObject('Example', Test)

while true do
    mq.delay(500)
    counter = counter + 1
end
