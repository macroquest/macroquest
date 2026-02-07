# vcxproj to CMake Conversion Script

## Overview

`Convert-VcxprojToCMake.ps1` is a PowerShell script that automatically converts Visual Studio `.vcxproj` project files into `CMakeLists.txt` files suitable for use with CMake's `add_subdirectory()` command.

This tool can be used in two ways:
1. **Standalone**: Manually convert individual projects or directories
2. **Integrated**: Automatically convert projects during CMake configuration via `gen_solution.ps1`

## CMake Build System Integration

The converter is integrated into the MacroQuest CMake build system and can automatically convert `.vcxproj` files to `CMakeLists.txt` during configuration.

### Quick Start

```powershell
# Convert all custom plugins to CMake during build configuration
# (automatically converts .props files too via lazy generation)
.\gen_solution.ps1 -ConvertVcxproj

# Force reconversion even if CMakeLists.txt already exists
.\gen_solution.ps1 -ConvertVcxproj -ConvertVcxprojForce
```

### How It Works

When `-ConvertVcxproj` is enabled:
1. CMake scans for `.vcxproj` files in the `plugins/` directory
2. For each project found, it checks if `CMakeLists.txt` exists
3. If not (or if `-ConvertVcxprojForce` is set), it runs the converter script with `-ConvertPropsFiles`
4. Props files are converted to `.cmake` includes (lazy generation - only if they don't exist)
5. The generated `CMakeLists.txt` is then included via `add_subdirectory()`
6. Projects build as native CMake targets instead of external MSBuild projects

### Benefits

- **Better IDE integration**: Projects become native CMake targets
- **Faster reconfiguration**: No need to rebuild the entire solution
- **Cross-platform potential**: Converted projects can be adapted for other platforms
- **Cleaner solution files**: No `VCXPROJ_DUMMY_` projects needed

### CMake Options

- `MQ_CONVERT_VCXPROJ` - Enable vcxproj-to-CMake conversion, includes props files (default: OFF)
- `MQ_CONVERT_VCXPROJ_FORCE` - Force reconversion even if files exist (default: OFF)

## Standalone Usage

### Single File Conversion

```powershell
# Basic conversion
.\Convert-VcxprojToCMake.ps1 -VcxprojPath path\to\project.vcxproj

# With analysis report
.\Convert-VcxprojToCMake.ps1 -VcxprojPath path\to\project.vcxproj -GenerateAnalysis

# Convert .props files to .cmake includes
.\Convert-VcxprojToCMake.ps1 -VcxprojPath path\to\project.vcxproj -ConvertPropsFiles

# Full conversion with analysis and props
.\Convert-VcxprojToCMake.ps1 -VcxprojPath path\to\project.vcxproj -GenerateAnalysis -ConvertPropsFiles

# Force overwrite existing CMakeLists.txt
.\Convert-VcxprojToCMake.ps1 -VcxprojPath path\to\project.vcxproj -Force

# Force overwrite with backup
.\Convert-VcxprojToCMake.ps1 -VcxprojPath path\to\project.vcxproj -Force -BackupExisting

# Custom output location
.\Convert-VcxprojToCMake.ps1 -VcxprojPath path\to\project.vcxproj -OutputPath path\to\CMakeLists.txt
```

### Batch Conversion (Convert Entire Directory Tree)

```powershell
# Convert all .vcxproj files in a directory (skips if CMakeLists.txt exists)
.\Convert-VcxprojToCMake.ps1 -ScanDirectory src

# With props file conversion
.\Convert-VcxprojToCMake.ps1 -ScanDirectory src -ConvertPropsFiles

# Force overwrite all existing CMakeLists.txt files
.\Convert-VcxprojToCMake.ps1 -ScanDirectory src -Force

# Force overwrite with backups
.\Convert-VcxprojToCMake.ps1 -ScanDirectory src -Force -BackupExisting

# Full batch conversion with analysis
.\Convert-VcxprojToCMake.ps1 -ScanDirectory src -Force -BackupExisting -GenerateAnalysis -ConvertPropsFiles

# Exclude additional directories
.\Convert-VcxprojToCMake.ps1 -ScanDirectory src -ExcludeDirectories @('build', 'temp', 'external')
```

### Parameters

**Single File Mode:**
- **`-VcxprojPath`** (Required): Path to the `.vcxproj` file to convert
- **`-OutputPath`** (Optional): Custom path for generated `CMakeLists.txt` (defaults to same directory as vcxproj)

**Batch Mode:**
- **`-ScanDirectory`** (Required): Root directory to scan for `.vcxproj` files recursively
- **`-ExcludeDirectories`** (Optional): Array of directory patterns to exclude (default: `build`, `build_*`, `.vs`, `.git`, `node_modules`, `obj`, `bin`)

**Common Options:**
- **`-GenerateAnalysis`** (Switch): Generate a detailed analysis report of the conversion
- **`-ConvertPropsFiles`** (Switch): Also convert imported `.props` files to `.cmake` include files
- **`-Force`** (Switch): Overwrite existing `CMakeLists.txt` files (default: skip if exists)
- **`-BackupExisting`** (Switch): Create timestamped backup before overwriting (use with `-Force`)

## What It Converts

### ✓ Successfully Converted

The script automatically handles the following:

1. **Source Files**
   - Extracts all `.cpp` and `.c` files from `<ClCompile>` items
   - Identifies and excludes files marked with `<ExcludedFromBuild>true</ExcludedFromBuild>`
   - Generates `set(TARGET_SOURCES ...)` with all active source files

2. **Project Type Detection**
   - Detects if project is DynamicLibrary, StaticLibrary, or Application
   - Handles mixed configuration types (DLL for Debug/Release, Static for Debug-Static/Release-Static)
   - Generates appropriate `add_library()` or `add_executable()` command

3. **Preprocessor Definitions**
   - Extracts `<PreprocessorDefinitions>` from each configuration
   - Groups definitions by configuration (Debug, Release, Debug-Static, Release-Static)
   - Identifies common definitions across all configurations
   - Generates `target_compile_definitions()` with CMake generator expressions

4. **Include Directories**
   - Extracts `<AdditionalIncludeDirectories>` from all configurations
   - Extracts `<IncludePath>` from property groups
   - Converts paths to CMake format (`${CMAKE_SOURCE_DIR}`, etc.)
   - Generates `target_include_directories()` with all unique includes

5. **Project References**
   - Extracts `<ProjectReference>` items
   - Converts to `target_link_libraries()` entries
   - Uses project name from referenced `.vcxproj` file

6. **Linker Options**
   - Extracts DLL base addresses from `<Link><BaseAddress>`
   - Generates platform-specific `target_link_options()` with generator expressions
   - Handles both Win32 and x64 base addresses

7. **Target Name Customization**
   - Detects `<TargetName>` overrides (e.g., `-static` suffix for static builds)
   - Generates `set_target_properties(... OUTPUT_NAME ...)` with conditional naming

8. **Precompiled Headers**
   - Detects precompiled header source (`.cpp` file with `<PrecompiledHeader>Create</PrecompiledHeader>`)
   - Extracts precompiled header file name from `<PrecompiledHeaderFile>`
   - Generates `target_precompile_headers()` command

9. **Path Normalization**
   - Converts MSBuild variables to CMake equivalents:
     - `$(MQRoot)` → `${CMAKE_SOURCE_DIR}/`
     - `$(MSBuildThisFileDirectory)` → `${CMAKE_CURRENT_SOURCE_DIR}/`
   - Converts backslashes to forward slashes
   - Handles relative paths (`..`)

10. **Generator Expression Syntax**
    - Properly handles configurations with hyphens using `$<STREQUAL:$<CONFIG>,Debug-Static>`
    - Uses `$<CONFIG:Release>` for configurations without hyphens
    - Handles platform checks with `CMAKE_SIZEOF_VOID_P`

11. **Property Sheets (.props) Conversion** (with `-ConvertPropsFiles`)
    - Detects `.props` file imports in the project
    - Parses `.props` files to extract shared settings
    - Generates corresponding `.cmake` include files
    - **Auto-resolves user macros** by tracing dependencies:
      - Builds dependency graph (e.g., `MQRoot` depends on `MQSolutionDirectory`)
      - Converts MSBuild built-in variables to CMake equivalents
      - Resolves variables in correct dependency order
      - Outputs fully resolved macros as actual `set()` commands
      - Marks partially resolved or unresolved macros with comments
    - Extracts:
      - User macros (MSBuild variables) → Auto-resolved to CMake variables
      - Preprocessor definitions → `set(PropsName_DEFINITIONS ...)`
      - Include directories → `set(PropsName_INCLUDES ...)`
      - Library directories → `set(PropsName_LIBRARY_DIRS ...)`
      - Additional dependencies → `set(PropsName_LIBRARIES ...)`
      - Compiler/linker options → Comments for manual conversion
      - Nested `.props` imports → Listed for reference
    - Generates reusable CMake variables that can be shared across multiple projects
    - Adds commented `include()` statements in generated `CMakeLists.txt`

## What Requires Manual Attention

### ⚠ Partially Converted (May Need Manual Adjustment)

1. **Files with Special PCH Settings**
   - Files marked with `<PrecompiledHeader>NotUsing</PrecompiledHeader>`
   - **Action Required:** May need `set_source_files_properties()` to disable PCH for specific files

2. **Excluded Files**
   - Files marked with `<ExcludedFromBuild>true</ExcludedFromBuild>`
   - **Action Required:** Verify these should remain excluded (often unity build files)

3. **Assembly Files (.asm)**
   - NASM files are detected but commented out
   - **Action Required:** Implement NASM custom commands (see CLAUDE.md for pattern)

4. **Path Variables**
   - Some MSBuild variables may not be converted (e.g., `$(VCPKG_IncludeStatic)`)
   - **Action Required:** Replace with appropriate CMake equivalents

5. **Preprocessor Definition Edge Cases**
   - If definitions differ significantly across configs, may need manual grouping
   - **Action Required:** Verify definitions match original `.vcxproj`

### ✗ Not Converted (Requires Manual Implementation)

1. **Pre-Build Events**
   - `<PreBuildEvent><Command>` entries
   - **Action Required:** Convert to `add_custom_command(TARGET ... PRE_BUILD ...)`

2. **Post-Build Events**
   - `<PostBuildEvent><Command>` entries
   - **Action Required:** Convert to `add_custom_command(TARGET ... POST_BUILD ...)`

3. **Resource Files**
   - `.rc` resource compilation files
   - **Action Required:** Add resource files to sources if needed

4. **Import/Export Definitions**
   - Hand-maintained `PROJECTNAME_EXPORTS` vs `PROJECTNAME_STATIC` patterns
   - **Action Required:** Add appropriate export definitions (see CLAUDE.md)

5. **Custom Build Steps**
   - `<CustomBuild>` items with custom commands
   - **Action Required:** Convert to `add_custom_command()` or `add_custom_target()`

6. **Property Sheets**
   - `.props` file imports (`<Import Project="...">`)
   - **Action Required:** Use `-ConvertPropsFiles` flag to generate `.cmake` include files
   - Or manually move common settings to root `CMakeLists.txt`

7. **Conditional Compilation**
   - Platform-specific file exclusions (e.g., x64-only or Win32-only files)
   - **Action Required:** Use generator expressions in `target_sources()`

8. **Additional Library Dependencies**
   - `<AdditionalDependencies>` with specific `.lib` files
   - **Action Required:** Add to `target_link_libraries()` if needed

9. **Compiler Flags**
   - Special compiler flags from `<ClCompile>` options (e.g., `/EHsc`, `/W4`)
   - **Action Required:** Add via `target_compile_options()` if not in common config

10. **Linker Flags**
    - Special linker flags beyond base addresses
    - **Action Required:** Add via `target_link_options()` if needed

## Analysis Report

When run with `-GenerateAnalysis`, the script generates a `conversion-analysis.txt` file containing:

- **Successfully Converted:** Features that were automatically handled
- **Partially Converted:** Items that may need manual review
- **Not Converted:** Features requiring manual implementation
- **Warnings:** Potential issues detected
- **Summary:** Statistics about the conversion
- **Next Steps:** Recommended actions after conversion

## Example Output

Given `MQ2Main.vcxproj`, the script generates:

### CMakeLists.txt
```cmake
# Generated from MQ2Main.vcxproj

cmake_minimum_required(VERSION 3.16)
project(MQ2Main)

# Collect source files
set(TARGET_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/../../contrib/mini-yaml/yaml/Yaml.cpp"
    "MQ2Globals.cpp"
    "MacroQuest.cpp"
    # ... more files
)

# Library type depends on configuration
if("${CMAKE_BUILD_TYPE}" MATCHES "Static")
    set(LIB_TYPE STATIC)
else()
    set(LIB_TYPE SHARED)
endif()

add_library(MQ2Main ${LIB_TYPE} ${TARGET_SOURCES})

# Set target name for static configurations
set_target_properties(MQ2Main PROPERTIES
    OUTPUT_NAME "$<IF:$<OR:$<STREQUAL:$<CONFIG>,Debug-Static>,$<STREQUAL:$<CONFIG>,Release-Static>>,MQ2Main-static,MQ2Main>"
)

# Preprocessor definitions
target_compile_definitions(MQ2Main PRIVATE
    MQ2MAIN_IMPL
    NOMINMAX
    $<$<CONFIG:Debug>:DEBUG_BUILD>
    $<$<STREQUAL:$<CONFIG>,Debug-Static>:MQLIB_STATIC>
    # ... more definitions
)

# Include directories
target_include_directories(MQ2Main PRIVATE
    "${CMAKE_SOURCE_DIR}/src/main"
    "${CMAKE_SOURCE_DIR}/src"
    # ... more includes
)

# Link dependencies
target_link_libraries(MQ2Main PRIVATE
    eqlib
    imgui
    routing
)

# Linker options (base addresses)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_link_options(MQ2Main PRIVATE $<$<CONFIG:Release>:/BASE:0x030000000000>)
else()
    target_link_options(MQ2Main PRIVATE $<$<CONFIG:Release>:/BASE:0x03000000>)
endif()

# Precompiled header
target_precompile_headers(MQ2Main PRIVATE "pch.h")
```

## Testing the Conversion

After running the script, test the generated `CMakeLists.txt`:

```bash
# Configure CMake
cmake -B build -G "Visual Studio 17 2022" -A x64

# Build all configurations
cmake --build build --config Debug
cmake --build build --config Release
cmake --build build --config Debug-Static
cmake --build build --config Release-Static
```

## Common Issues and Fixes

### Issue: Preprocessor Definitions Missing

**Symptom:** `target_compile_definitions()` is empty or incomplete

**Fix:** Manually add missing definitions. Check the original `.vcxproj` `<PreprocessorDefinitions>` sections.

### Issue: Base Addresses Not Applied

**Symptom:** Linker warnings about default base address

**Fix:** Check that the configuration names match (Debug/Release vs Debug-Static/Release-Static)

### Issue: Assembly Files Not Building

**Symptom:** NASM files are commented out in `TARGET_SOURCES`

**Fix:** Implement NASM custom command pattern from CLAUDE.md

### Issue: Unity Build Errors

**Symptom:** "file not found" errors for headers in unity build files

**Fix:** Ensure unity build files are excluded (script does this automatically)

## Working with .props Files

### Why Convert .props Files?

Visual Studio `.props` files (property sheets) contain shared settings used across multiple projects. Converting them to `.cmake` includes maintains this sharing behavior in CMake.

### How It Works

1. **Detection**: Script detects all `.props` imports in the `.vcxproj` file
2. **Parsing**: Extracts settings from each `.props` file:
   - User macros (MSBuild variables)
   - Preprocessor definitions
   - Include/library directories
   - Additional dependencies
   - Compiler/linker options
3. **Generation**: Creates a `.cmake` file with CMake equivalents
4. **Usage**: Provides reusable variables for multiple projects

### Auto-Resolution of User Macros

The script automatically resolves MSBuild user macros by:

1. **Building a dependency graph**: Identifies which macros depend on others
2. **Converting built-ins first**: `$(MSBuildThisFileDirectory)` → `${CMAKE_CURRENT_SOURCE_DIR}/`
3. **Resolving in order**: Variables with no dependencies first, then dependent variables
4. **Categorizing results**: Fully resolved, partially resolved, or unresolved

**Example from Common.props:**

```xml
<!-- MSBuild user macros -->
<MQSolutionDirectory>$(MSBuildThisFileDirectory)</MQSolutionDirectory>
<MQRoot>$(MQSolutionDirectory)..\</MQRoot>
<MQBuildDirectory>$(MQRoot)build\</MQBuildDirectory>
<MQLibDir>$(MQBuildDirectory)lib\$(Platform)\$(MQBinaryDirName)\</MQLibDir>
```

**Auto-converted to CMake:**

```cmake
# Fully resolved macros (ready to use):
set(Common_MQSolutionDirectory "${CMAKE_CURRENT_SOURCE_DIR}/")
set(Common_MQRoot "${CMAKE_CURRENT_SOURCE_DIR}/../")
set(Common_MQBuildDirectory "${CMAKE_CURRENT_SOURCE_DIR}/../build/")
set(Common_MQLibDir "${CMAKE_CURRENT_SOURCE_DIR}/../build/lib/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,Win32>/release/")
```

Notice how:
- `MQSolutionDirectory` was resolved from `MSBuildThisFileDirectory`
- `MQRoot` used the resolved value of `MQSolutionDirectory`
- `MQBuildDirectory` used the resolved value of `MQRoot`
- `$(Platform)` was converted to a generator expression for Win32/x64

### Generated .cmake Structure

Example `Common.cmake` generated from `Common.props`:

```cmake
# User macros (auto-resolved from MSBuild variables)
#
# Original MSBuild definitions:
#   MQRoot = $(MQSolutionDirectory)..\
#   MQBuildDirectory = $(MQRoot)build\
#   MQLibDir = $(MQBuildDirectory)lib\$(Platform)\$(MQBinaryDirName)\

# Fully resolved macros (ready to use):
set(Common_MQRoot "${CMAKE_CURRENT_SOURCE_DIR}/../")
set(Common_MQBuildDirectory "${CMAKE_CURRENT_SOURCE_DIR}/../build/")
set(Common_MQLibDir "${CMAKE_CURRENT_SOURCE_DIR}/../build/lib/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,Win32>/release/")

# Preprocessor definitions from props
set(Common_DEFINITIONS
    SOL_SAFE_FUNCTIONS
    WIN32_LEAN_AND_MEAN
    NOMINMAX
    # ... more definitions
)

# Include directories from props
set(Common_INCLUDES
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/contrib"
    # ... more includes
)

# Library dependencies from props
set(Common_LIBRARIES
    winmm.lib
    psapi.lib
    # ... more libraries
)
```

### Using Generated .cmake Files

In your `CMakeLists.txt`:

```cmake
# Include the generated props file
include(${CMAKE_CURRENT_SOURCE_DIR}/../Common.cmake)

# Use the variables in your target
target_compile_definitions(MyTarget PRIVATE ${Common_DEFINITIONS})
target_include_directories(MyTarget PRIVATE ${Common_INCLUDES})
target_link_libraries(MyTarget PRIVATE ${Common_LIBRARIES})
```

### Shared Settings Across Multiple Projects

For projects sharing the same `.props` file (like `Common.props`):

```cmake
# In root CMakeLists.txt
include(${CMAKE_SOURCE_DIR}/src/Common.cmake)

# In project A's CMakeLists.txt
target_compile_definitions(ProjectA PRIVATE ${Common_DEFINITIONS})
target_include_directories(ProjectA PRIVATE ${Common_INCLUDES})

# In project B's CMakeLists.txt
target_compile_definitions(ProjectB PRIVATE ${Common_DEFINITIONS})
target_include_directories(ProjectB PRIVATE ${Common_INCLUDES})
```

### Manual Adjustments Needed

The generated `.cmake` files may contain:

1. **MSBuild Variable References**: Still need conversion
   ```cmake
   # Before (needs manual fix):
   "$(VCPKG_IncludeStatic)"

   # After:
   "${VCPKG_ROOT}/installed/${VCPKG_TRIPLET}/include"
   ```

2. **Partially Resolved Macros**: Variables that still contain some unresolved references
   ```cmake
   # Partially resolved macros (manual adjustments needed):
   # set(Common_SomeVariable "${CMAKE_CURRENT_SOURCE_DIR}/path/$(UnresolvedVar)")
   ```
   Most user macros are now fully auto-resolved! Only macros with environment variables or complex conditions need manual adjustment.

3. **Compiler/Linker Options**: Listed as comments for manual conversion
   ```cmake
   # Compiler options from props (manual conversion needed)
   # LanguageStandard = stdcpp20
   # WarningLevel = Level3
   ```

### Nested .props Imports

If a `.props` file imports other `.props` files, they're listed for reference:

```cmake
# Nested props imports (convert separately if needed)
# - .\private\Common-private.props (Condition: exists(...))
# - .\eqlib\eqlib.props (Condition: exists(...))
```

Run the converter on these nested files separately if needed.

## Batch Conversion Workflow

The batch conversion mode provides an efficient way to convert an entire codebase from MSBuild to CMake:

### How It Works

1. **Scans Directory Tree**: Recursively finds all `.vcxproj` files
2. **Filters Excluded Directories**: Skips build output, version control, etc.
3. **Checks Existing CMakeLists.txt**: By default, skips projects already converted
4. **Respects Existing Conversions**: Won't overwrite unless `-Force` is used
5. **Creates Backups**: With `-BackupExisting`, creates timestamped backups before overwriting
6. **Provides Summary**: Shows statistics on converted, skipped, and failed projects

### Safety Features

- **Non-destructive by default**: Won't overwrite existing `CMakeLists.txt` files
- **Explicit -Force required**: Must explicitly choose to overwrite
- **Timestamped backups**: Backups include timestamp to prevent collisions
- **Excluded directories**: Automatically skips build artifacts and version control

### Typical Workflow

**Initial Conversion:**
```powershell
# First time: convert all projects that don't have CMakeLists.txt
.\Convert-VcxprojToCMake.ps1 -ScanDirectory src -ConvertPropsFiles -GenerateAnalysis
```

**Review and Iterate:**
```powershell
# Fix any issues, test builds
# If you need to regenerate a specific project:
.\Convert-VcxprojToCMake.ps1 -VcxprojPath src/myproject/MyProject.vcxproj -Force
```

**Batch Regeneration:**
```powershell
# Regenerate all with backups (after testing initial conversion)
.\Convert-VcxprojToCMake.ps1 -ScanDirectory src -Force -BackupExisting -ConvertPropsFiles
```

### Example Output

```
==============================================================================
BATCH CONVERSION MODE
==============================================================================

Scanning directory: C:\workspace\project\src
Exclude patterns: build, build_*, .vs, .git, node_modules, obj, bin

Found 25 .vcxproj file(s) (excluded 3)

-----------------------------------------------------------
Project: CoreLibrary
  Path: C:\workspace\project\src\core\CoreLibrary.vcxproj
  Status: CONVERTED

-----------------------------------------------------------
Project: UtilityLib
  Path: C:\workspace\project\src\utils\UtilityLib.vcxproj
  Status: SKIPPED (CMakeLists.txt already exists)

[... more projects ...]

==============================================================================
BATCH CONVERSION SUMMARY
==============================================================================

Total projects found:       25
Successfully converted:     20
Skipped (already exists):   5
Forced overwrites:          0
Backups created:            0
Failed:                     0

Next steps:
1. Review generated CMakeLists.txt files
2. Test builds with all configurations
3. Address items in analysis reports (if generated)
```

## Integration with Existing CMake Projects

To use the generated `CMakeLists.txt` in an existing CMake project:

```cmake
# In parent CMakeLists.txt
add_subdirectory(src/component_name)
```

The generated file is designed to work with:
- Multi-configuration generators (Visual Studio, Ninja Multi-Config)
- Custom configurations (Debug-Static, Release-Static)
- The MacroQuest build system patterns (see CLAUDE.md)

## Limitations

1. **MSBuild-specific Features**
   - Complex property evaluation
   - Conditional imports
   - Item transformations

2. **Advanced Scenarios**
   - Projects with multiple output types per configuration
   - Projects using custom MSBuild tasks
   - Projects with complex dependency chains

3. **Configuration Assumptions**
   - Assumes standard Debug/Release/Debug-Static/Release-Static pattern
   - May not handle custom configuration names well

4. **Path Assumptions**
   - Assumes standard MacroQuest directory structure for variable substitution
   - May need adjustment for different project layouts

## Best Practices

1. **Always Generate Analysis Report**
   - Use `-GenerateAnalysis` to track what needs manual attention
   - Review all items in "PARTIALLY CONVERTED" and "NOT CONVERTED" sections

2. **Test All Configurations**
   - Build Debug, Release, Debug-Static, Release-Static after conversion
   - Compare binary sizes and dependencies with original builds

3. **Version Control**
   - Commit the generated `CMakeLists.txt` as a starting point
   - Iterate and refine based on build results

4. **Refer to CLAUDE.md**
   - Follow patterns documented in CLAUDE.md for consistency
   - Apply lessons learned from other conversions

## See Also

- **CLAUDE.md** - CMake conversion patterns and lessons learned
- **CMAKE_BUILD.md** - Complete CMake build documentation
- **MIGRATION_GUIDE.md** - Migrating from .vcxproj to CMake

## Changelog

### Version 1.3 (2025-11-16)
- **Batch Conversion Mode**: Added `-ScanDirectory` parameter to convert entire directory trees
  - Recursively scans for all `.vcxproj` files in a directory
  - Filters out build artifacts, version control, and other excluded directories
  - Configurable exclusion patterns with `-ExcludeDirectories`
  - Provides detailed progress and summary statistics
- **Safety Features for Existing Files**:
  - By default, skips projects that already have `CMakeLists.txt` files
  - `-Force` parameter to override and regenerate existing files
  - `-BackupExisting` parameter to create timestamped backups before overwriting
  - Backups use format: `CMakeLists.txt.backup_YYYYMMDD_HHMMSS`
- **Improved Single File Mode**:
  - Checks for existing `CMakeLists.txt` and warns before overwriting
  - Respects `-Force` and `-BackupExisting` flags in single file mode
- **Better Error Handling**: Continues batch conversion even if individual projects fail

### Version 1.2 (2025-11-16)
- **Auto-resolution of MSBuild user macros**: Script now automatically resolves user macros by:
  - Building dependency graphs (e.g., `MQRoot` depends on `MQSolutionDirectory`)
  - Converting MSBuild built-in variables to CMake equivalents
  - Resolving variables in correct dependency order (topological sort)
  - Outputting fully resolved macros as actual `set()` commands
  - Categorizing macros as fully resolved, partially resolved, or unresolved
- Converts `$(MSBuildThisFileDirectory)` → `${CMAKE_CURRENT_SOURCE_DIR}/`
- Converts `$(Platform)` → Generator expression for Win32/x64 detection
- Converts `$(Configuration)` → `${CMAKE_BUILD_TYPE}`
- Successfully resolves complex nested dependencies (tested with MacroQuest's Common.props)

### Version 1.1 (2025-11-16)
- Added `.props` file conversion support with `-ConvertPropsFiles` flag
- Generates reusable `.cmake` include files from property sheets
- Extracts user macros, definitions, includes, libraries, and compiler options
- Detects and lists nested `.props` imports
- Enhanced analysis report to track detected `.props` files

### Version 1.0 (2025-11-16)
- Initial release
- Supports standard vcxproj features
- Handles MacroQuest-specific patterns
- Generates analysis reports
