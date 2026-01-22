function(add_vcxproj PROJECT_LOCATION PROJECT_NAME PROJECT_PREFIX)
    # Optional 4th argument for dependencies
    set(DEPENDENCIES ${ARGN})

    find_file(VCXPROJ_LOCATION NAMES ${PROJECT_NAME}.vcxproj PATHS "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_LOCATION}" NO_DEFAULT_PATH REQUIRED)
    if(VCXPROJ_LOCATION)
        if(DEPENDENCIES)
            include_external_msproject(${PROJECT_NAME} ${VCXPROJ_LOCATION} ${DEPENDENCIES})
        else()
            include_external_msproject(${PROJECT_NAME} ${VCXPROJ_LOCATION})
        endif()

        set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROJECT_PREFIX})
        unset(VCXPROJ_LOCATION CACHE)  # Clear cache to allow next call to search fresh
    else()
        MESSAGE(WARNING "Attempted to include non-existent vcxproj ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_LOCATION}/${PROJECT_NAME}.vcxproj")
    endif()
endfunction()

# These could all be in their respective subdirectories, but prefer in this case a single
# file to specify the entire core project since everything here is maintained with
# bespoke vcxproj and prop files without CMakeLists.txt to build projects.

# Add main components
add_vcxproj(src/eqlib eqlib "core")
add_vcxproj(src/imgui imgui "core/libraries")
add_vcxproj(src/routing routing "core/libraries")
add_vcxproj(src/login login "core/libraries")
add_vcxproj(contrib/zep zep "core/libraries")
add_vcxproj(src/main MQ2Main "core" eqlib imgui routing zep)

# Set MQ2Main as the default startup project in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MQ2Main)

if(MQ_BUILD_LAUNCHER)
    add_vcxproj(src/loader MacroQuest "core/applications" imgui login routing)
endif()

# Add plugins
if(MQ_BUILD_PLUGINS)
    add_vcxproj(src/plugins/pluginapi pluginapi "core/plugins" routing)
    add_vcxproj(src/plugins/autobank MQ2AutoBank "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/autologin MQ2AutoLogin "core/plugins" login pluginapi MQ2Main)
    add_vcxproj(src/plugins/bzsrch MQ2Bzsrch "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/chat MQ2Chat "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/chatwnd MQ2ChatWnd "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/custombinds MQ2CustomBinds "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/eqbugfix MQ2EQBugFix "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/hud MQ2HUD "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/itemdisplay MQ2ItemDisplay "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/labels MQ2Labels "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/lua MQ2Lua "core/plugins" imgui pluginapi MQ2Main)
    add_vcxproj(src/plugins/map MQ2Map "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/targetinfo MQ2TargetInfo "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/xtarinfo MQ2XTarInfo "core/plugins" pluginapi MQ2Main)
endif()

# Add custom plugins from root plugins directory
if(MQ_BUILD_CUSTOM_PLUGINS)
    include(vcxproj_plugins.cmake)
endif()

# Add tests
if(MQ_BUILD_TESTS)
    add_vcxproj(src/tests/Actors Actors "core/applications/tests")
    add_vcxproj(src/tests/NamedPipeClient NamedPipeClient "core/applications/tests")
endif()

