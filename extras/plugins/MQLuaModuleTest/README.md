# MQLuaModuleTest

One Paragraph project description goes here

## Getting Started

Quick start instructions to get users up and going

```txt
/plugin MQLuaModuleTest
```

### Commands

Describe the commands available and how to use them.

```txt
Give examples
```

### Configuration File

Describe the configuration file and what the settings do

```yaml
- Example goes here
```

## Other Notes

Add additional notes

## Authors

* **Your name** - *Initial work*

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## Acknowledgments

* Inspiration from...
* I'd like to thank the Thieves' Guild for helping me with all the code I stole...
# MQLuaModuleTest (POC)

This is a proof-of-concept plugin for MQ2Lua module registration.
It lives under `extras/plugins` and is not part of the core plugin set.

Usage:
- Load MQ2Lua (`/plugin mq2lua`)
- Load this plugin (`/plugin MQLuaModuleTest`)
- Run the Lua test script (see `build/bin/<config>/lua/luamoduletest_test.lua`)

Notes:
- The module name is `luamoduletest`.
- This plugin demonstrates returning native Lua types, accepting tables, and error propagation.
