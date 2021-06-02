This folder is reserved for third party customizations to the core libraries.

If files with the following names exist here, they will be automatically included in
the specified projects. This feature is provided at the convenience of the user so that
project file customizations do not need to be maintained.

Private includes for the MQ2Main project:
- MQ2Globals-private.cpp
- MQ2Globals-private.h
- MQ2Main-private.cpp
- MQ2Main-private.h

Private includes for the EQLib project:
- eqgame-private.h
- eqgraphics-private.h
- eqmain-private.h
- EQLib-private.h
- EQLib-private.cpp
- EQClasses-private.h
- EQClasses-private.cpp

If the following files are present, they will be included in the property
sheets. This can be used for adjusting visual studio project settings:
- Plugin-private.props
- Common-private.props

If these files are added, they will be included into pluginapi and made
available as code linked into and available to all plugins. This is different
than the MQ2Main includes as these sources will be compiled directly into the plugin.
- pluginapi-private.cpp
- pluginapi-private.h
