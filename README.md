# MacroQuest
---

MacroQuest is an open source scripting and plugin platform for EverQuest.

## How To Build

### Prererequisites

* [Visual Studio 2019/2022 Community](https://visualstudio.microsoft.com/downloads/)
* [Git for Windows](https://git-scm.com/)

The recommended way to build MacroQuest is from a source code checkout using Git. There are many how to guides for installing and setting up git. [Here is one of them](https://docs.gitlab.com/ee/gitlab-basics/start-using-git.html)

### Check out the latest source code

Create the checkout. This will create the subfolder **mqnext** that containes a copy of the project.  **ACTUAL URL TBD**

```
git clone git@gitlab.com:macroquest/next/mqnext.git
```

Make sure that submodules are initialized. Move (cd) to the newly created **mqnext** folder before executing this command.  If you have run this step already, you can skip it
```
git submodule init
```

Update the submodules to the correct version. Ensure you are in the newly created **mqnext** folder before executing this command.
```
git submodule update
```

Run `MQ2Auth.exe` to generate the authorization file for your computer. Personal builds of MacroQuest are machine-locked, and can only be run on the machine the built it.

### Updating an existing checkout

MacroQuest is updated often, especially after a patch. Make sure before you build that you have the latest source code for MacroQuest and all of its dependencies.

If you already have the source, it is a good idea to make sure that you pull all the latest changes.
```
git pull --rebase
```

Update submodules. This ensures that dependencies have the latest code.
```
git submodule update
```

At this point, the source should be ready to compile. Proceed to building.

### Build Steps

1. Open the `MacroQuest.sln` file in src.
1. Select the `Release` and `(x64)` configuration from the drop-down menu near the top of the window.
1. Since the project moved to 64-bit, ensure all project configurations are set to `(x64)` in the **Solution Macroquest** Property Pages.  You can check this by right-clicking on **Solution Macroquest**, select Properties from the pull down menu, click the Configuration Manager button, then ensure the Platform colum for each project is set to `(x64)`. 
1. Select `Build -> Build Solution` from the menu.

The built files will be placed in `build/bin/Release`. To start MacroQuest, run `MacroQuest.exe`. This will launch the application to the tray, and install MacroQuest into any running EverQuest processes.

### Adding Your Own Plugins

_NOTE:_ If you have any custom plugins you want to build, put the sources for them in the `plugins` folder, for example:
`plugins/MQ2Foo/MQ2Foo.cpp`. Do not put them in src/plugins - this path is reserved for the MacroQuest developers

To add any personal plugins to the solution:
1. Right clicking the solution in solution explorer and clicking `Add -> Add Existing Project...`.
1. Select your .vcxproj file.
1. Repeat as necessary

### Updating Plugins from Legacy MacroQuest

If you are converting plugins over from Legacy MacroQuest, it is recommended that you re-run the plugin generator first, and copy your source files into the generated project.

For Example:
```
cd plugins
mkplugin MQ2Foo
```

This will generate a MQ2Foo.vcxproj, MQ2Foo.cpp and several other files in a MQ2Foo folder. You can now add this project to the solution and add/replace the sources with your own.

## Directory Structure

Folder Name | Purpose
------------|-------------
build       | Build artifacts. This is where you can find the output when you compile MacroQuest and your plugins.
contrib     | Third-Party source code.
data        | Additional non-source code files used by MacroQuest.
docs        | Documentation
extras      | Optional files that aren't required but may be useful. This includes sources for plugins that are no longer maintained.
include     | Public header files that are used for building MacroQuest and plugins.
plugins     | This folder is reserved for you to add your own personal plugins.
src         | The source code for MacroQuest and its core plugins.
tools       | Source code and additional tools that are used for MacroQuest development, but not part of the main project.

### Additional files of interest

**MQ2Auth.exe** Generates MQ2Auth.h, run this first before building the solution

**plugins/mkplugin.exe** Generates a new plugin from the template. Use this when creating a new plugin, or when converting an existing plugin from legacy MacroQuest.

**src/MacroQuest.sln** The main MacroQuest solution file. Use this to build the project.
