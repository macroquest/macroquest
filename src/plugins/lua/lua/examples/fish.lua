local mq = require('mq')
local function ForceEnd()
    mq.exit()
end

mq.event('BrokenPole', "#*#You can't fish without a fishing pole, go buy one.#*#", ForceEnd)
mq.event('NoBait', "#*#You can't fish without fishing bait, go buy some.#*#", ForceEnd)

local function KeepItem()
    while (mq.TLO.Cursor()) do
        if (mq.TLO.Cursor.Name() == "Tattered Cloth Sandal" or mq.TLO.Cursor.Name() == "Rusty Dagger") then
            mq.cmd('/destroy')
            mq.delay(1000)
        else
            if (mq.TLO.Cursor.Name() ~= "Fish Scales") then
                printf('Caught %s', mq.TLO.Cursor.Name())
            end
            mq.cmd('/autoinventory')
        end
    end
end

local function CheckPole()
    if mq.TLO.Me.Inventory('mainhand').Type() == 'Fishing Pole' then return end
    print('You need to put your fishing pole in your primary hand.')
    mq.exit()
end

while true do
    CheckPole()
    mq.delay(10)

    KeepItem()
    mq.cmd('/doability Fishing')
    mq.delay(10)

    KeepItem()
    mq.cmd('/doability Forage')
    mq.delay(10)

    mq.doevents()
end
