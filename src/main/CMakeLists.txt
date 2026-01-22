# Generated from MQ2Main.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../Common.cmake")

# ---------------------------------------------------------------------
# vcpkg dependencies
# ---------------------------------------------------------------------
find_package(crashpad REQUIRED)
find_package(fmt REQUIRED)
find_package(wil REQUIRED)
find_package(date REQUIRED)
find_package(detours REQUIRED)
find_package(protobuf REQUIRED)
find_package(unofficial-sqlite3 REQUIRED)
find_package(unofficial-argon2 REQUIRED)
find_package(dxsdk-d3dx REQUIRED)

# ---------------------------------------------------------------------
# Header files
# ---------------------------------------------------------------------
set(MQ2Main_HEADERS
    "../../contrib/args/args.hxx"
    "../../contrib/Blech/Blech.h"
    "../../contrib/mini-yaml/yaml/Yaml.hpp"
    "../../contrib/renderdoc/renderdoc_app.h"
    "../../contrib/tinyfsm/include/tinyfsm.hpp"
    "../../include/extras/wil/Constants.h"
    "../../include/moveitem.h"
    "../../include/mq/api/Abilities.h"
    "../../include/mq/api/Achievements.h"
    "../../include/mq/api/ActorAPI.h"
    "../../include/mq/api/CommandAPI.h"
    "../../include/mq/api/DetourAPI.h"
    "../../include/mq/api/Inventory.h"
    "../../include/mq/api/Items.h"
    "../../include/mq/api/MacroAPI.h"
    "../../include/mq/api/MacroDataTypes.h"
    "../../include/mq/api/Main.h"
    "../../include/mq/api/PluginAPI.h"
    "../../include/mq/api/RenderDoc.h"
    "../../include/mq/api/Spawns.h"
    "../../include/mq/api/Spells.h"
    "../../include/mq/api/Textures.h"
    "../../include/mq/base/Base.h"
    "../../include/mq/base/BuildInfo.h"
    "../../include/mq/base/Color.h"
    "../../include/mq/base/Common.h"
    "../../include/mq/base/Config.h"
    "../../include/mq/base/Deprecation.h"
    "../../include/mq/base/Enum.h"
    "../../include/mq/base/EnumFmt.h"
    "../../include/mq/base/GlobalBuffer.h"
    "../../include/mq/base/Iterator.h"
    "../../include/mq/base/Logging.h"
    "../../include/mq/base/PluginHandle.h"
    "../../include/mq/base/ScopeExit.h"
    "../../include/mq/base/Signal.h"
    "../../include/mq/base/SimpleLexer.h"
    "../../include/mq/base/String.h"
    "../../include/mq/base/Threading.h"
    "../../include/mq/base/Vector.h"
    "../../include/mq/base/WString.h"
    "../../include/mq/imgui/ConsoleWidget.h"
    "../../include/mq/imgui/ImGuiUtils.h"
    "../../include/mq/imgui/MQConsoleDelegate.h"
    "../../include/mq/imgui/Widgets.h"
    "../../include/mq/Plugin.h"
    "../../include/mq/utils/Args.h"
    "../../include/mq/utils/Benchmarks.h"
    "../../include/mq/utils/HotKeys.h"
    "../../include/mq/utils/Keybinds.h"
    "../../include/mq/utils/Markov.h"
    "../../include/mq/utils/Naming.h"
    "../../include/mq/utils/OS.h"
    "../common/Common.h"
    "../common/ConfigUtils.h"
    "../common/MiscUtils.h"
    "../common/StringUtils.h"
    "datatypes/DataTypeList.h"
    "datatypes/MQ2DataTypes.h"
    "CrashHandler.h"
    "emu/EmuExtensions.h"
    "GraphicsEngine.h"
    "GraphicsResources.h"
    "ImGuiBackend.h"
    "ImGuiManager.h"
    "Logging.h"
    "MacroQuest.h"
    "MQ2Commands.h"
    "MQActorAPI.h"
    "MQCommandAPI.h"
    "MQDataAPI.h"
    "MQ2DataContainers.h"
    "MQ2DeveloperTools.h"
    "MQ2Globals.h"
    "MQ2ImGuiTools.h"
    "MQ2Inlines.h"
    "MQ2Internal.h"
    "MQ2KeyBinds.h"
    "MQ2Main.h"
    "MQ2MainBase.h"
    "MQ2Mercenaries.h"
    "MQ2Prototypes.h"
    "MQ2SpellSearch.h"
    "MQ2Utilities.h"
    "MQPluginHandler.h"
    "MQRenderDoc.h"
    "MQVersionInfo.h"
    "pch.h"
    "MQPostOffice.h"
    "resource.h"
)

source_groups("Header Files" ${MQ2Main_HEADERS})

# ---------------------------------------------------------------------
# Other files
# ---------------------------------------------------------------------
set(MQ2Main_OTHERFILES
    "MQ2Main.rc"
    "../MacroQuest.natvis"
    "../../data/resources/CHANGELOG.md"
    "../../data/resources/Zones.ini"
    "../../LICENSE.md"
    "../../data/resources/ItemDB.txt"
)

source_group("Resource Files" FILES ${MQ2Main_OTHERFILES})

# ---------------------------------------------------------------------
# Assembly files
# ---------------------------------------------------------------------
set(MQ2Main_ASSEMBLY
    "AssemblyFunctions64.asm"
)

source_groups("Assembly Files" ${MQ2Main_ASSEMBLY})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(MQ2Main_SOURCES
    "../../contrib/mini-yaml/yaml/Yaml.cpp"
    "../common/HotKeys.cpp"
    "api/Abilities.cpp"
    "api/Spawns.cpp"
    "datatypes/MQ2AchievementType.cpp"
    "datatypes/MQ2AdvLootType.cpp"
    "datatypes/MQ2AlertListType.cpp"
    "datatypes/MQ2AlertType.cpp"
    "datatypes/MQ2AltAbilityType.cpp"
    "datatypes/MQ2AugType.cpp"
    "datatypes/MQ2AuraType.cpp"
    "datatypes/MQ2BandolierType.cpp"
    "datatypes/MQ2BodyType.cpp"
    "datatypes/MQ2BuffType.cpp"
    "datatypes/MQ2CachedBuffType.cpp"
    "datatypes/MQ2CharacterType.cpp"
    "datatypes/MQ2CharSelectListType.cpp"
    "datatypes/MQ2ClassType.cpp"
    "datatypes/MQ2CorpseType.cpp"
    "datatypes/MQ2CurrentZoneType.cpp"
    "datatypes/MQ2DataTypes.cpp"
    "datatypes/MQ2DeityType.cpp"
    "datatypes/MQ2DynamicZoneType.cpp"
    "datatypes/MQ2EverQuestType.cpp"
    "datatypes/MQ2EvolvingItemType.cpp"
    "datatypes/MQ2FellowshipType.cpp"
    "datatypes/MQ2FriendsType.cpp"
    "datatypes/MQ2GroundType.cpp"
    "datatypes/MQ2GroupType.cpp"
    "datatypes/MQ2InvSlotType.cpp"
    "datatypes/MQ2TradeskillDepotType.cpp"
    "datatypes/MQ2ItemFilterDataType.cpp"
    "datatypes/MQ2ItemSpellType.cpp"
    "datatypes/MQ2ItemType.cpp"
    "datatypes/MQ2KeyRingType.cpp"
    "datatypes/MQ2MacroQuestType.cpp"
    "datatypes/MQ2MacroType.cpp"
    "datatypes/MQ2MathType.cpp"
    "datatypes/MQ2MenuType.cpp"
    "datatypes/MQ2MercenaryType.cpp"
    "datatypes/MQ2MerchantType.cpp"
    "datatypes/MQ2PetType.cpp"
    "datatypes/MQ2PluginType.cpp"
    "datatypes/MQ2PointMerchantType.cpp"
    "datatypes/MQ2BasicTypes.cpp"
    "datatypes/MQ2RaceType.cpp"
    "datatypes/MQ2RaidType.cpp"
    "datatypes/MQ2SkillType.cpp"
    "datatypes/MQ2SolventType.cpp"
    "datatypes/MQ2SpawnType.cpp"
    "datatypes/MQ2SpellType.cpp"
    "datatypes/MQ2SwitchType.cpp"
    "datatypes/MQ2TargetType.cpp"
    "datatypes/MQ2TaskType.cpp"
    "datatypes/MQ2TimerType.cpp"
    "datatypes/MQ2WindowType.cpp"
    "datatypes/MQ2WorldLocationType.cpp"
    "datatypes/MQ2XTargetType.cpp"
    "datatypes/MQ2ZoneType.cpp"
    "datatypes/MQCursorAttachmentType.cpp"
    "datatypes/MQIniType.cpp"
    "datatypes/MQInventoryType.cpp"
    "datatypes/MQSocialType.cpp"
    "emu/EmuExtensions.cpp"
    "GraphicsEngine.cpp"
    "GraphicsEngineDX11.cpp"
    "GraphicsEngineDX9.cpp"
    "GraphicsResources.cpp"
    "ImGuiBackendDX11.cpp"
    "ImGuiBackendDX9.cpp"
    "ImGuiBackendWin32.cpp"
    "MQ2Anonymize.cpp"
    "MQ2AutoInventory.cpp"
    "MQ2Benchmarks.cpp"
    "MQ2CachedBuffs.cpp"
    "MQ2ChatHook.cpp"
    "MQDisplayHook.cpp"
    "MQCommandAPI.cpp"
    "MQCommands.cpp"
    "MQ2DeveloperTools.cpp"
    "MQInputAPI.cpp"
    "MQ2Data.cpp"
    "MQActorAPI.cpp"
    "MQDataAPI.cpp"
    "MQ2DataVars.cpp"
    "MQDetourAPI.cpp"
    "MQ2FrameLimiter.cpp"
    "MQ2Globals.cpp"
    "MQ2ImGuiTools.cpp"
    "MQ2GroundSpawns.cpp"
    "MQImGuiConsole.cpp"
    "MQImguiWidgets.cpp"
    "MQ2Items.cpp"
    "MQ2KeyBinds.cpp"
    "MQ2LoginFrontend.cpp"
    "MQ2MacroCommands.cpp"
    "MacroQuest.cpp"
    "MQPostOffice.cpp"
    "MQPluginHandler.cpp"
    "MQ2Pulse.cpp"
    "MQ2Spawns.cpp"
    "MQ2Spells.cpp"
    "MQ2StringDB.cpp"
    "MQ2Utilities.cpp"
    "MQ2WindowInspector.cpp"
    "MQ2Windows.cpp"
    "MQAchievements.cpp"
    "MQInventory.cpp"
    "MQRenderDoc.cpp"
    "CrashHandler.cpp"
    "ImGuiManager.cpp"
)

source_groups("Source Files" ${MQ2Main_SOURCES})

# Exclude files from being built
set_source_files_properties(
    "AssemblyFunctions64.asm"
    PROPERTIES
        VS_SETTINGS "$<$<STREQUAL:${CMAKE_GENERATOR_PLATFORM},Win32>:ExcludedFromBuild=true>")

# Exclude files from being built
set_source_files_properties(
    "datatypes/MQ2AchievementType.cpp"
    "datatypes/MQ2AdvLootType.cpp"
    "datatypes/MQ2AlertListType.cpp"
    "datatypes/MQ2AlertType.cpp"
    "datatypes/MQ2AltAbilityType.cpp"
    "datatypes/MQ2AugType.cpp"
    "datatypes/MQ2AuraType.cpp"
    "datatypes/MQ2BandolierType.cpp"
    "datatypes/MQ2BodyType.cpp"
    "datatypes/MQ2BuffType.cpp"
    "datatypes/MQ2CachedBuffType.cpp"
    "datatypes/MQ2CharacterType.cpp"
    "datatypes/MQ2CharSelectListType.cpp"
    "datatypes/MQ2ClassType.cpp"
    "datatypes/MQ2CorpseType.cpp"
    "datatypes/MQ2CurrentZoneType.cpp"
    "datatypes/MQ2DeityType.cpp"
    "datatypes/MQ2DynamicZoneType.cpp"
    "datatypes/MQ2EverQuestType.cpp"
    "datatypes/MQ2EvolvingItemType.cpp"
    "datatypes/MQ2FellowshipType.cpp"
    "datatypes/MQ2FriendsType.cpp"
    "datatypes/MQ2GroundType.cpp"
    "datatypes/MQ2GroupType.cpp"
    "datatypes/MQ2InvSlotType.cpp"
    "datatypes/MQ2TradeskillDepotType.cpp"
    "datatypes/MQ2ItemFilterDataType.cpp"
    "datatypes/MQ2ItemSpellType.cpp"
    "datatypes/MQ2ItemType.cpp"
    "datatypes/MQ2KeyRingType.cpp"
    "datatypes/MQ2MacroQuestType.cpp"
    "datatypes/MQ2MacroType.cpp"
    "datatypes/MQ2MathType.cpp"
    "datatypes/MQ2MenuType.cpp"
    "datatypes/MQ2MercenaryType.cpp"
    "datatypes/MQ2MerchantType.cpp"
    "datatypes/MQ2PetType.cpp"
    "datatypes/MQ2PluginType.cpp"
    "datatypes/MQ2PointMerchantType.cpp"
    "datatypes/MQ2BasicTypes.cpp"
    "datatypes/MQ2RaceType.cpp"
    "datatypes/MQ2RaidType.cpp"
    "datatypes/MQ2SkillType.cpp"
    "datatypes/MQ2SolventType.cpp"
    "datatypes/MQ2SpawnType.cpp"
    "datatypes/MQ2SpellType.cpp"
    "datatypes/MQ2SwitchType.cpp"
    "datatypes/MQ2TargetType.cpp"
    "datatypes/MQ2TaskType.cpp"
    "datatypes/MQ2TimerType.cpp"
    "datatypes/MQ2WindowType.cpp"
    "datatypes/MQ2WorldLocationType.cpp"
    "datatypes/MQ2XTargetType.cpp"
    "datatypes/MQ2ZoneType.cpp"
    "datatypes/MQCursorAttachmentType.cpp"
    "datatypes/MQIniType.cpp"
    "datatypes/MQInventoryType.cpp"
    "datatypes/MQSocialType.cpp"
    PROPERTIES
        VS_SETTINGS "ExcludedFromBuild=true")

# Force includes in source files
set_source_files_properties(
    "../common/HotKeys.cpp"
    PROPERTIES
        COMPILE_OPTIONS "/FI;pch.h")

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
# Library type depends on configuration
if(MQ_STATIC_BUILD)
    set(LIB_TYPE STATIC)
else()
    set(LIB_TYPE SHARED)
endif()

add_library(MQ2Main ${LIB_TYPE}
    ${MQ2Main_HEADERS}
    ${MQ2Main_OTHERFILES}
    ${MQ2Main_ASSEMBLY}
    ${MQ2Main_SOURCES}
)

set_target_properties(MQ2Main PROPERTIES FOLDER "core")

# ---------------------------------------------------------------------
# Output name customization
# ---------------------------------------------------------------------
if(CMAKE_GENERATOR_PLATFORM STREQUAL "x64")
    if(MQ_STATIC_BUILD)
        set_target_properties(MQ2Main PROPERTIES OUTPUT_NAME
            "$<IF:$<CONFIG:Debug>,MQ2Main-static,MQ2Main-static>"
        )
    endif()
elseif(CMAKE_GENERATOR_PLATFORM STREQUAL "Win32")
    if(MQ_STATIC_BUILD)
        set_target_properties(MQ2Main PROPERTIES OUTPUT_NAME
            "$<IF:$<CONFIG:Debug>,MQ2Main-static,MQ2Main-static>"
        )
    endif()
endif()

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Common_props(MQ2Main)

# ---------------------------------------------------------------------
# Add NASM tool to ASM files
# ---------------------------------------------------------------------
add_nasm_sources(${MQ2Main_ASSEMBLY})

# ---------------------------------------------------------------------
# Link vcpkg dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2Main PRIVATE
    crashpad::crashpad
    fmt::fmt
    WIL::WIL
    date::date
    detours::detours
    protobuf::libprotobuf
    unofficial::sqlite3::sqlite3
    unofficial::argon2::libargon2
    Microsoft::D3DX9
)

# ---------------------------------------------------------------------
# Project dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2Main PRIVATE zep eqlib imgui routing)

# ---------------------------------------------------------------------
# Preprocessor definitions
# ---------------------------------------------------------------------
target_compile_definitions(MQ2Main PRIVATE
    "NOMINMAX"
    "MQ2MAIN_IMPL"
    "$<$<BOOL:${MQ_STATIC_BUILD}>:MQLIB_STATIC>"
    "$<$<NOT:$<BOOL:${MQ_STATIC_BUILD}>>:MQ2MAIN_EXPORTS>"
)

# ---------------------------------------------------------------------
# Include directories
# ---------------------------------------------------------------------
target_include_directories(MQ2Main PRIVATE
    "${CMAKE_SOURCE_DIR}/contrib/mini-yaml/yaml"
    "${CMAKE_SOURCE_DIR}/src/main"
    "${CMAKE_SOURCE_DIR}/src"
)

# ---------------------------------------------------------------------
# Compiler options
# ---------------------------------------------------------------------
target_compile_options(MQ2Main PRIVATE
    "/EHsc"
)

# ---------------------------------------------------------------------
# Link libraries
# ---------------------------------------------------------------------
target_link_libraries(MQ2Main PRIVATE
    "$<$<NOT:$<BOOL:${MQ_STATIC_BUILD}>>:${MQ2MainLibs}>"
)

# ---------------------------------------------------------------------
# Linker options
# ---------------------------------------------------------------------
target_link_options(MQ2Main PRIVATE
    "$<$<STREQUAL:${CMAKE_GENERATOR_PLATFORM},x64>:$<$<NOT:$<BOOL:${MQ_STATIC_BUILD}>>:/BASE:0x030000000000>>"
    "$<$<STREQUAL:${CMAKE_GENERATOR_PLATFORM},Win32>:$<$<NOT:$<BOOL:${MQ_STATIC_BUILD}>>:/BASE:0x03000000>>"
)

# ---------------------------------------------------------------------
# Precompiled header
# ---------------------------------------------------------------------
set_source_files_properties(
    "../../contrib/mini-yaml/yaml/Yaml.cpp"    PROPERTIES SKIP_PRECOMPILE_HEADERS ON)

target_precompile_headers(MQ2Main PRIVATE "pch.h")

# ---------------------------------------------------------------------
# PRE_BUILD events
# ---------------------------------------------------------------------

add_custom_command(TARGET MQ2Main PRE_BUILD
    COMMAND powershell.exe -ExecutionPolicy Bypass -NoProfile -NonInteractive -File "${CMAKE_SOURCE_DIR}/tools/build_scripts/MQ2Main_PreBuild.ps1" ${CMAKE_GENERATOR_PLATFORM}
    VERBATIM
)

# ---------------------------------------------------------------------
# POST_BUILD events
# ---------------------------------------------------------------------

add_custom_command(TARGET MQ2Main POST_BUILD
    COMMAND powershell.exe -ExecutionPolicy Bypass -NoProfile -NonInteractive -File "${CMAKE_SOURCE_DIR}/tools/build_scripts/MQ2Main_PostBuild.ps1" "${CMAKE_SOURCE_DIR}/data" "${CMAKE_BINARY_DIR}/bin/$<CONFIG>" ${CMAKE_GENERATOR_PLATFORM}
    COMMENT "Performing PostBuild for ${PROJECT_NAME}..."
    VERBATIM
)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Warnings:
#   - Project has mixed configuration types (DLL/Static)
# - Review and adjust as needed
