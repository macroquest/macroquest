/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

	// Order slightly matters here

MODULE(MQCommandAPI)           // Instantiates pCommandAPI
MODULE(CrashHandlerModule)
MODULE(MQDataAPI)              // Instantiates pDataAPI
MODULE(MacroSystem)
#ifndef MQLIB_STATIC 
MODULE(MQActorAPI)             // Instantiates pActorAPI
MODULE(MQPluginHandler)
#endif
MODULE(KeyBindsModule)

MODULE(DetoursModule)
MODULE(SpellsModule)
#ifndef MQLIB_STATIC 
MODULE(MQPostOffice)
#endif
MODULE(BenchmarksModule)
MODULE(DisplayHookModule)
MODULE(LoadingScreenModule)
MODULE(ChatHookModule)
MODULE(PulseModule)
MODULE(LoginModule)
MODULE(EmuExtensionsModule)
MODULE(FrameLimiterModule)
MODULE(WindowsModule)
MODULE(ObservedObjectsModule)
MODULE(SpawnsModule)
MODULE(GroundSpawnsModule)
MODULE(ItemsModule)
MODULE(CachedBuffsModule)
MODULE(DeveloperToolsModule)
MODULE(ImGuiAPIModule)
MODULE(InputModule)
MODULE(MQCfgFileHandler)
MODULE(StringDBModule)
MODULE(AnonymizerModule)
MODULE(AutoInventoryModule)
MODULE(GraphicsResourcesModule)
MODULE(ImGuiModule)
MODULE(RecentChangesModule)
MODULE(CameraModule)
MODULE(EQBugFixModule)

PLUGIN_MODULE(AutoLoginPlugin)
PLUGIN_MODULE(MapPlugin)
PLUGIN_MODULE(ItemDisplayPlugin)

#if __has_include("../private/ModuleList-private.inl")
#include "../private/ModuleList-private.inl"
#endif
