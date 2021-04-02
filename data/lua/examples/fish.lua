local mq = require('mq')
local ForceEnd = function ()
    mq.exit()
end

mq.event('BrokenPole', "#*#You can't fish without a fishing pole, go buy one.#*#", ForceEnd)
mq.event('NoBait', "#*#You can't fish without fishing bait, go buy some.#*#", ForceEnd)

local KeepItem = function ()
    while (mq.TLO.Cursor.ID() ~= 0) do
        if (mq.TLO.Cursor.Name() == "Tattered Cloth Sandal" or mq.TLO.Cursor.Name() == "Rusty Dagger") then
            mq.cmd.destroy()
            mq.delay('1s')
        else 
            if (mq.TLO.Cursor.Name() ~= "Fish Scales") then
                mq.cmd.echo('Caught '..mq.TLO.Cursor.Name())
            end
            cmd.autoinventory()
        end
    end
end

local CheckPole = function ()
    if (string.find(mq.TLO.Me.Inventory('mainhand').Name(), 'The Bone Rod') ~= nil) then return end
    mq.cmd.echo('You need to put your fishing pole in your primary hand.')
    mq.exit()
end

while true do
    CheckPole()
    mq.delay(10)

    KeepItem()
    mq.cmd.doability('Fishing')
    mq.delay(10)

    KeepItem()
    mq.cmd.doability('Forage')
    mq.delay(10)

    mq.doevents()
end