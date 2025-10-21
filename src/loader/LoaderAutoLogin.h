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

#pragma once

#include "login/Login.h"


// AutoLogin
void LoadCharacter(const ProfileRecord& profile, bool force);
void LoadProfileGroup(std::string_view group, bool force);

void LaunchCleanSession();
void ProcessPendingLogins();
void Import();
std::string GetEQRoot();

// ImGui
bool ShowPasswordWindow();
void InitializeAutoLoginImGui();
void ShutdownAutoLoginImGui();

// Actors

void Post(uint32_t pid, const mq::proto::login::MessageId& messageId, const std::string& data);
void Post(const std::string& name, const mq::proto::login::MessageId& messageId, const std::string& data);

template <typename T>
void Post(uint32_t pid, const mq::proto::login::MessageId& messageId, const T& data)
{
	Post(pid, messageId, data.SerializeAsString());
}

template <typename T>
void Post(const std::string& name, const mq::proto::login::MessageId& messageId, const T& data)
{
	Post(name, messageId, data.SerializeAsString());
}
