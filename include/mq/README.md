# MQ Includes

These are the public include files for the MacroQuest project.

## Folders

### api

Items related to the MacroQuest API, things like interaction with items or spawns

### base

Base includes, generally generic inclusions like strings or math functions

### imgui

Items and helpers related to the ImGui library

### libutils

Anything that requires additional libraries to be linked in before the include can be used.  Contain all utilities in a single file with the library name as in glmUtils.h

Items that don't require additional libraries should be in the `utils` folder

### plugin

Items and related to the plugin api

### utils

Generic utils like operating system utilities, naming, or keybinds.  Items that require additional libraries should be in the `libutils` folder