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

#include <spdlog/fwd.h>

#include "mq/base/PluginHandle.h"

namespace mq {

class MQChatSink;
class MQDebugSink;
class MQFileSink;
class MQPluginLogger;

class LoggingManager
{
public:
	LoggingManager();
	~LoggingManager();

	void Initialize();
	void Shutdown();

	struct PluginLogger
	{
		std::shared_ptr<spdlog::logger> logger;
	};

	void InitializeLogfile();

	void AddSinkToLogger(spdlog::logger& logger, const std::shared_ptr<spdlog::sinks::sink>& sink,
		spdlog::level::level_enum log_level);
	void RemoveSinkFromLogger(spdlog::logger& logger, const std::shared_ptr<spdlog::sinks::sink>& sink);

	void SetLoggerSinkLevel(spdlog::logger& logger, const std::shared_ptr<spdlog::sinks::sink>& sink,
		spdlog::level::level_enum log_level);


	std::shared_ptr<MQFileSink> CreateFileSink(std::string_view baseName,
		spdlog::level::level_enum log_level) const;

	// Public interface calls in to here.
	void WriteChatColor(const char* line, int color, int filter, const MQPluginHandle& pluginHandle);
	void WriteChatFormat(const char* format, va_list va, int color, const MQPluginHandle& pluginHandle);
	void LogMessage(const char* format, va_list va, int level, bool toFile, const MQPluginHandle& pluginHandle);

	std::shared_ptr<spdlog::logger> CreatePluginLogger(const std::string& pluginName, const MQPluginHandle& pluginHandle);
	void RemovePluginLogger(const MQPluginHandle& pluginHandle);

	std::shared_ptr<spdlog::logger> GetLogger(const MQPluginHandle& pluginHandle) const;

private:
	std::shared_ptr<MQPluginLogger> GetLoggerInternal(const MQPluginHandle& pluginHandle) const;

	std::string m_logFile;

	std::shared_ptr<MQPluginLogger> m_mainLogger;

	std::shared_ptr<MQChatSink> m_chatSink;
	std::shared_ptr<MQDebugSink> m_debugSink;
	std::shared_ptr<MQFileSink> m_fileSink;

	std::unordered_map<uint64_t, std::shared_ptr<MQPluginLogger>> m_pluginLoggers;
};

extern LoggingManager* g_loggingManager;

} // namespace mq
