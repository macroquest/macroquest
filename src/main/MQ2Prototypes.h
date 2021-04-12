/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

#pragma once

namespace mq {

struct MQGroundSpawn;

using fEQGetMelee            = float  (*)(PlayerClient*, PlayerClient*);

// MQ2 Callback types
using fEQCommand             = void   (*)(SPAWNINFO*, char* Buffer);
using fMQCommand             = void   (*)(SPAWNINFO*, char* Buffer, size_t BuffLen);
using fCascadeItemFunction   = void   (*)();
struct TokenTextParam;
using fMQTokenMessageCmd     = void   (*)(const TokenTextParam&);

// Plugin Function Types
using fMQWriteChatColor      = DWORD  (*)(const char*, DWORD, DWORD);
using fMQPulse               = void   (*)();
using fMQIncomingChat        = bool   (*)(const char* Line, DWORD Color);
using fMQInitializePlugin    = void   (*)();
using fMQShutdownPlugin      = void   (*)();
using fMQZoned               = void   (*)();
using fMQReloadUI            = void   (*)();
using fMQCleanUI             = void   (*)();
using fMQDrawHUD             = void   (*)();
using fMQSetGameState        = void   (*)(DWORD GameState);
using fMQSpawn               = void   (*)(SPAWNINFO*);
using fMQGroundItem          = void   (*)(GROUNDITEM*);
using fMQBeginZone           = void   (*)();
using fMQEndZone             = void   (*)();
using fMQUpdateImGui         = void   (*)();
using fMQMacroStart          = void   (*)(const char*);
using fMQMacroStop           = void   (*)(const char*);
using fMQLoadPlugin          = void   (*)(const char*);
using fMQUnloadPlugin        = void   (*)(const char*);

// Misc Function types
using fEQW_GetDisplayWindow  = HWND(CALLBACK*)();

// Overlay function types
using fMQCreateDeviceObjects = void   (*)();
using fMQInvalidateDeviceObjects = void(*)();
using fMQImGuiRender         = void   (*)();
using fMQGraphicsSceneRender = void   (*)();

} // namespace mq
