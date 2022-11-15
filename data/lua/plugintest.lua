local mq = require'mq'

-- this returns a table with an embedded userdata used to validate definitions
local plugin = mq.plugin('test', '0.0.1')

-- all of the c++ callbacks can be defined, number of arguments are checked when the plugin 
-- is started so that both the member function and the static function are valid callbacks 
-- (ie, plugin:InitializePlugin() and plugin.InitializePlugin() and plugin.InitializePlugin(self) are all valid)
function plugin:InitializePlugin()
  print(self['testval'])
  self['testval'] = 'test3'
end

-- binding commands has the same limitations as the callbacks. You can either have self and line or just line
-- as arguments
plugin:bindcommand('/mycommand', function (self, line)
  print(line)
  print(self.testval)
end)

-- This is a function that has no defined callback, it's just used to retrieve internal state
-- the ignored argument here is required to pass the number of arguments check successfully 
-- when we assign this to a datatype member. We don't care about the index, but it must be 
-- accounted for
function plugin:TestVal(_, _)
  return 'string', self.testval
end

-- datatypes are defined as a table of functions (with Members being another table of functions)
-- these are all the entried checked for in the table, again with the optional `self` argument
-- signatures: 
-- Members: returns { string, object } where string is the MQ type name and the object
--   is the value that can be converted to the type 
--   takes a string Index value if the result is indexed
-- ToString: returns string value of the single argument. The argument is the internal representation
--   of the value of this type.
-- FromData: returns an object that is the internal representation of this type, the argument is
--   the source value, converted into a lua representation. This should be checked for a sensible type
-- FromString: returns an object that is the internal representation of this type, the argument is
--   the source value as a string
local mytype = {
  Members = {
    TestVal = plugin.TestVal, -- can use functions defined locally (or on the plugin table)
  },
  ToString = function(self, val) return self.testval .. (val or '') end,
  FromData = function(source) return tostring(source) end,
  FromString = function(self, source) return self.testval .. (source or '') end,
}

-- the bindtype function binds the type name to the type table definition
plugin:bindtype('mytype', mytype)

-- this is the nominal signature for a TLO getter. It takes a string index and then returns the tuple
-- { type, value } as before. The value will be brought from lua in the way that the type defines. In
-- this case, we are returning a type of mytype, so it will actually copy the value specified here in lua
function plugin:Data(index)
  return 'mytype', 'test4'
end

-- the bindtlo function binds the TLO name to the function that populates the value
plugin:bindtlo('MyType', plugin.Data)

-- this is some internal state that anything with a `self` reference can access
plugin['testval'] = 'test1'
plugin['testval'] = 'test2'

return plugin