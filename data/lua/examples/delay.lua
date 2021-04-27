-- usage: 
--   local delay = require 'examples.delay'
--   delay[<delay in seconds>](callbacks...)
--   ...
--   delay()
-- this will create a series of callbacks that will get executed the first time that delay() is called and the time in seconds has passed

local D_events_metatable = {
    __index = function (self, t)
        return rawget(self.events, t)
    end,
    __newindex = function (self, t, v)
        if not self.events[t] then
            rawset(self.events, t, {v})
        else
            -- this will guard against the edge case of simultaneous events, so we don't lose events
            table.insert(rawget(self.events, t), v)
        end
    end,
    __call = function (self, ...)
        if #{...} == 0 then
            local rem = {}
            local now = os.clock()

            for t, callbacks in pairs(self.events) do
                if os.difftime(now, t) >= self.duration then
                    for i=1,#callbacks do callbacks[i]() end
                    rem[#rem + 1] = t
                end
            end

            for i=1,#rem do self.events[rem[i]] = nil end
        else
            local now = os.clock()
            for _, c in pairs{...} do
                self[now] = c
            end
        end
    end
}

local function new_D_events(duration)
    local obj = {
        events = {},
        duration = duration
    }
    return setmetatable(obj, D_events_metatable)
end

local D_queue_metatable = {
    __index = function (self, d)
        if d ~= nil and not self.durations[d] then
            rawset(self.durations, d, new_D_events(d))
        end

        return rawget(self.durations, d)
    end,
    __newindex = function (self, d, q)
        rawset(self.durations, d, q)
    end,
    __call = function (self, d)
        if not d then
            for _, duration in pairs(self.durations) do
                duration()
            end
        else
            self[d]()
        end
    end
}

local D = setmetatable({durations = {}}, D_queue_metatable)
return D