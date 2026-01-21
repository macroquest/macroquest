# Generated from Plugin.props
# This file should be included in CMakeLists.txt files that need these settings
# NOTE: Import order preserved from original .props file

include_guard()

set(PATH_TO_Plugin_DIR ${CMAKE_CURRENT_LIST_DIR})

macro(target_Plugin_props TARGET_NAME)

    # ---------------------------------------------------------------------
    # Import from original props file
    # ---------------------------------------------------------------------
    # Depends on conversion of: ./Common.props
    include(${PATH_TO_Plugin_DIR}/Common.cmake)
    target_Common_props(${TARGET_NAME})
    
    # TODO: Manual conversion required for element: ItemGroup
    
    # TODO: Manual conversion required for element: CopyMQPluginFiles
    
    # ---------------------------------------------------------------------
    # Import from original props file
    # ---------------------------------------------------------------------
    # Depends on conversion of: ./private/Plugin-private.props
    if(EXISTS "${PATH_TO_Common_DIR}/./private/Plugin-private.cmake")
        include(${PATH_TO_Plugin_DIR}/./private/Plugin-private.cmake)
        target_Plugin_private_props(${TARGET_NAME})
    endif()

    # set the output directory, MQBinaryDirName is a generator expression which prevents
    # cmake from auto-appending the configuration
    set_target_properties(${TARGET_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${MQBinaryDirName}/plugins" # .exe files
            LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${MQBinaryDirName}/plugins" # .dll files
            ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${MQBinaryDirName}/plugins" # .lib files
    )


    # ---------------------------------------------------------------------
    # Linker settings
    # ---------------------------------------------------------------------
    # Library directories
#    target_link_directories(${TARGET_NAME} PRIVATE
#        "${CMAKE_BINARY_DIR}/bin/$<CONFIG>"
#    )

    add_dependencies(${TARGET_NAME} pluginapi MQ2Main)
    # Additional dependencies
    target_link_libraries(${TARGET_NAME} PRIVATE
#        "$<$<CONFIG:Debug>:fmtd.lib>"
#        "$<$<CONFIG:Release>:fmt.lib>"
#        "mq2main.lib"
        pluginapi
        MQ2Main
    )
    
     
endmacro()
