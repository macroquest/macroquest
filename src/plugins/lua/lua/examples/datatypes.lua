local mq = require 'mq'

---A simple datatype that holds a counter that can be increased. Provides access
---to the counter's current value as well as its name, and a method to increase
---the count and to clear it.
---@class ExampleCounterType
---@field value integer
---@field name string

---@type DataType
local counterType = mq.DataType.new('ExampleCounterType', {
    Members = {
        --- Data Member: Value retrieves the counter's current value.
        ---@param counter ExampleCounterType The current counter object
        Value = function(_, counter)
            return 'int', counter.value
        end,

        --- Data Member: Name retrieves the counter's name.
        ---@param counter ExampleCounterType The current counter object
        Name = function(_, counter)
            return 'string', counter.name
        end
    },

    Methods = {
        ---A method to reset the counter
        ---@param counter ExampleCounterType
        Reset = function(_, counter)
            counter.value = 0
        end,

        ---A method to increment the counter
        ---@param amount string The amount to increase the counter by
        ---@param counter ExampleCounterType The counter object
        Increment = function(amount, counter)
            local value = nil
            if #amount == 0 then
                value = 1
            else
                value = tonumber(amount)
            end

            if value ~= nil then
                counter.value = counter.value + value
            end
        end
    },

    ---@param counter ExampleCounterType
    ToString = function(counter)
        return string.format('Counter %s: %d', counter.name, counter.value)
    end
})

---@type { [string]: ExampleCounterType }
local activeCounters = {
    default = { name = 'default', value = 0 }
}

--- Our ExampleCounter TLO function
--- This function implements a TLO that accepts an optional parameter which specifies
--- the name of the counter to retrieve.
---
--- Example usage, in macro syntax:
--- ```plaintext
--- > /echo ${ExampleCounter.Increment}
--- Counter default: 1
--- > /echo ${ExampleCounter[test]}
--- Counter test: 0
--- > /invoke ${ExampleCounter[test].Increment}
--- > /echo ${ExampleCounter[test].Value}
--- 1
--- > /invoke ${ExampleCounter[test].Increment[5]}
--- > /echo ${ExampleCounter[test].Value}
--- 6
--- > /invoke ${ExampleCounter[test].Reset}
--- > /echo ${ExampleCounter[test].Value}
--- 0
--- ```
---@param param string
---@return MQType, ExampleCounterType
local function CounterDemo(param)
    local name = param
    if param == nil or #param == 0 then
        name = 'default'
    end

    local counter = activeCounters[name]
    if counter ~= nil then
        return counterType, counter
    else
        activeCounters[name] = {name = name, value = 0}
        return counterType, activeCounters[name]
    end
end

--- Our ExampleAllCounters TLO function.
--- This TLO implements a TLO that returns a table containing all of our counters.
--- 
--- See examples/datatypes_consumer.lua for examples of how this data could be consumed.
---@return MQType, table
local function AllCounters(_)
    return 'table', activeCounters
end

-- Register our TLO functions
mq.AddTopLevelObject('ExampleCounter', CounterDemo)
mq.AddTopLevelObject('ExampleAllCounters', AllCounters)

print('Example datatypes demo script started. Now run examples/datatypes_consumer to see it in action!')

while true do
    mq.delay(1000)
end
