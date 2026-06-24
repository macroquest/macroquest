# MQ Includes

These are the public include files for the MacroQuest project.

## Folders

### api

Items related to the MacroQuest API, things like interaction with items, spawns, or spells.

### base

Generic, dependency-light building blocks like strings, math, color, and enums. Headers here avoid third party libraries and don't reach for MacroQuest runtime globals, though some exceptions exist for that last one.

### contrib

Helpers for a specific third party library, one folder per library named after it, as in contrib/protobuf/ProtobufLibs.h or contrib/glm/glmUtils.h.

### imgui

Items and helpers related to the ImGui library.

### plugin

Items related to the plugin api.

### utils

Generic MacroQuest utilities like operating system helpers, naming, keybinds, or argument parsing. Items here should mostly be standalone if possible.

### zep

Integration headers for the bundled Zep editor used by the console widgets.