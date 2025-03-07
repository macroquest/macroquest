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

#include "pch.h"
#include "MQLogging.h"

#include "mq/base/Logging.h"

#include "MQ2Main.h"
#include "EQLib/Logging.h"

#include <fmt/printf.h>
#include <spdlog/async.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>

namespace fs = std::filesystem;

#ifdef _DEBUG
#define DBG_SPEW // enable DebugSpew messages in debug builds
#endif

namespace mq {

//============================================================================

#if LOG_FILENAMES
constexpr const char* DEFAULT_LOG_PATTERN = "%L %Y-%m-%d %T.%f [%n] %v (%@)";
#else
constexpr const char* DEFAULT_LOG_PATTERN = "%L %Y-%m-%d %T.%f [%n] %v";
#endif

// Logger design:
//
// Each plugin gets its own logger, attached to a single proxy sink. The sink
// has a file sink, a chat sink, and a debug sink. The log message is created with
// the color_range_start and color_range end fields set to the color and filter, which
// are read by the chat sink to color the chat message.
//
// After the chat sink has a chance to write the message, the message has its MQ colors
// stripped, and is then fed to the debug and file sinks.
//
// The log levels of each are stored in the proxy sink instead of the other sinks, because
// those other sinks are re-used across the various loggers. This allows all the loggers
// to write to the same file, etc.

// Implemented in MQ2PluginHandler.cpp
void PluginsWriteChatColor(const char* line, int color, int filter);

class MQChatSink : public spdlog::sinks::base_sink<spdlog::details::null_mutex>
{
public:
	MQChatSink()
	{
		set_pattern("%v");
	}

	~MQChatSink() override
	{
	}

protected:
	void sink_it_(const spdlog::details::log_msg& msg) override
	{
		int color = static_cast<int>(msg.color_range_start);
		int filter = static_cast<int>(msg.color_range_end);

		spdlog::memory_buf_t formatted;
		spdlog::sinks::base_sink<spdlog::details::null_mutex>::formatter_->format(msg, formatted);

		std::string_view sv(formatted.data(), formatted.size());
		if (mq::ends_with(sv, "\r\n"))
			formatted.resize(formatted.size() - 2);
		else if (mq::ends_with(sv, "\n"))
			formatted.resize(formatted.size() - 1);
		formatted.push_back('\0');

		// If we're already on the main thread, avoid copying anything and just call
		// straight to PluginsWriteChatColor

		if (IsMainThread())
		{
			PluginsWriteChatColor(formatted.data(), color, filter);
			return;
		}

		// we're not on the main thread, we need to copy the string and queue up a function
		// to be executed on the main thread.
		size_t length = formatted.size() + 1;
		std::shared_ptr<char[]> Ptr{ new char[length] };
		strcpy_s(Ptr.get(), length, formatted.data());

		// Queue it up to run on the main thread
		PostToMainThread([Ptr, color, filter]()
		{
			PluginsWriteChatColor(Ptr.get(), color, filter);
		});
	}

	void flush_() override {}
};

class MQFileSink : public spdlog::sinks::base_sink<std::mutex>
{
public:
	explicit MQFileSink()
	{
		set_pattern(DEFAULT_LOG_PATTERN);
	}

	bool reopen()
	{
		try
		{
			m_fileHelper.reopen(false);
			m_hasError = false;

			return true;
		}
		catch (const spdlog::spdlog_ex& ex)
		{
			m_hasError = true;
			m_lastError = ex;
			return false;
		}
	}

	void set_filename(const std::string& filename)
	{
		try
		{
			m_fileHelper.open(filename, false);
		}
		catch (const spdlog::spdlog_ex& ex)
		{
			m_hasError = true;
			m_lastError = ex;
		}
	}

	const spdlog::filename_t& filename() const
	{
		return m_fileHelper.filename();
	}

	bool has_error() const
	{
		return m_hasError;
	}

	const spdlog::spdlog_ex& last_error() const
	{
		return m_lastError;
	}

	void log_formatted(const spdlog::memory_buf_t& formatted)
	{
		try
		{
			m_fileHelper.write(formatted);
		}
		catch (const spdlog::spdlog_ex& ex)
		{
			m_hasError = true;
			m_lastError = ex;
		}
	}

	spdlog::formatter& formatter()
	{
		return *spdlog::sinks::base_sink<std::mutex>::formatter_;
	}

protected:
	void sink_it_(const spdlog::details::log_msg& msg) override
	{
		if (m_hasError)
			return;

		spdlog::memory_buf_t formatted;
		spdlog::sinks::base_sink<std::mutex>::formatter_->format(msg, formatted);

		log_formatted(formatted);
	}

	void flush_() override
	{
		try
		{
			m_fileHelper.flush();
		}
		catch (const spdlog::spdlog_ex& ex)
		{
			m_hasError = true;
			m_lastError = ex;
		}
	}

private:
	spdlog::details::file_helper m_fileHelper{ {} };
	bool m_hasError = false;
	spdlog::spdlog_ex m_lastError{ {} };
};

class MQDebugSink : public spdlog::sinks::msvc_sink<spdlog::details::null_mutex>
{
public:
	MQDebugSink()
	{
		set_level(spdlog::level::trace);
		set_pattern(DEFAULT_LOG_PATTERN);
	}

	void log_format(const spdlog::memory_buf_t& formatted)
	{
		OutputDebugStringA(formatted.data());
	}
};

class ProxySink : public spdlog::sinks::base_sink<spdlog::details::null_mutex>
{
public:
	ProxySink(
		const std::shared_ptr<MQFileSink>& fileSink,
		const std::shared_ptr<MQChatSink>& chatSink,
		const std::shared_ptr<MQDebugSink>& debugSink)
		: m_fileSink(fileSink)
		, m_chatSink(chatSink)
		, m_debugSink(debugSink)
	{
		level_ = spdlog::level::trace;
	}

	void flush_() override {}

	void sink_it_(const spdlog::details::log_msg& msg) override
	{
		log_message(msg);
	}

	void set_filename(const std::string& filename)
	{
		m_fileSink->set_filename(filename);
	}

	void log_message(const spdlog::details::log_msg& msg, bool doFile = true)
	{
		if (msg.level >= m_chatLevel)
		{
			m_chatSink->log(msg);
		}

		auto fileLevel = doFile ? m_fileLevel : spdlog::level::off;
	
		if (msg.level >= fileLevel || msg.level >= m_debugLevel)
		{
			// both of these sinks have the same format, so we'll optimize to
			// only have to format it once.
			spdlog::memory_buf_t formatted;
			m_fileSink->formatter().format(msg, formatted);
			formatted.push_back('\0');

			// Strip MQ colors from the message before writing to the file
			size_t newLength = StripMQChat(std::string_view(formatted.data(), formatted.size()), formatted.data());
			formatted.resize(newLength);

			if (msg.level >= fileLevel)
			{
				m_fileSink->log_formatted(formatted);

				if (msg.level >= spdlog::level::debug)
				{
					m_fileSink->flush();
				}
			}

			if (msg.level >= m_debugLevel)
			{
				m_debugSink->log_format(formatted);
			}
		}
	}

	enum LogDestination : uint8_t
	{
		File,
		Chat,
		Debug,

		Any,
	};

	void set_level(LogDestination dest, spdlog::level::level_enum log_level)
	{
		switch (dest)
		{
		case Any:
			m_fileLevel = log_level;
			m_chatLevel = log_level;
			m_debugLevel = log_level;
			break;
		case File:
			m_fileLevel = log_level;
			break;
		case Chat:
			m_chatLevel = log_level;
			break;
		case Debug:
			m_debugLevel = log_level;
			break;
		}
	}

	bool should_log(LogDestination dest, spdlog::level::level_enum log_level)
	{
		switch (dest)
		{
		case Any:
			return log_level >= m_fileLevel || log_level >= m_chatLevel || log_level >= m_debugLevel;
		case File:
			return log_level >= m_fileLevel;
		case Chat:
			return log_level >= m_chatLevel;
		case Debug:
			return log_level >= m_debugLevel;

		default: break;
		}

		return false;
	}

private:
	std::shared_ptr<MQFileSink> m_fileSink;
	spdlog::level::level_enum m_fileLevel = spdlog::level::debug;
	std::shared_ptr<MQChatSink> m_chatSink;
	spdlog::level::level_enum m_chatLevel = spdlog::level::info;
	std::shared_ptr<MQDebugSink> m_debugSink;
	spdlog::level::level_enum m_debugLevel = spdlog::level::trace;
};

class MQPluginLogger : public spdlog::logger
{
public:
	MQPluginLogger(
		const std::string& name,
		const MQPluginHandle& pluginHandle,
		const std::shared_ptr<MQFileSink>& fileSink,
		const std::shared_ptr<MQChatSink>& chatSink,
		const std::shared_ptr<MQDebugSink>& debugSink)
		: spdlog::logger(name)
		, m_pluginHandle(pluginHandle)
		, m_proxySink(std::make_shared<ProxySink>(fileSink, chatSink, debugSink))
	{
		sinks_.push_back(m_proxySink);
		level_ = spdlog::level::trace;
		flush_level_ = spdlog::level::debug;
	}

	void do_log(spdlog::log_clock::time_point log_time,
		spdlog::source_loc loc,
		spdlog::level::level_enum lvl,
		spdlog::string_view_t msg,
		int color = -1,
		int filter = 0,
		bool doFile = true)
	{
		spdlog::details::log_msg log_msg(log_time, loc, name_, lvl, msg);
		if (color == -1)
			color = USERCOLOR_DEFAULT;
	
		log_msg.color_range_start = static_cast<size_t>(color);
		log_msg.color_range_end = static_cast<size_t>(filter);

		m_proxySink->log_message(log_msg, doFile);
	}

	void set_filename(const std::string& filename)
	{
		m_proxySink->set_filename(filename);
	}

	const std::shared_ptr<ProxySink>& proxy_sink() const
	{
		return m_proxySink;
	}

	bool should_log(spdlog::level::level_enum lvl)
	{
		return m_proxySink->should_log(ProxySink::Any, lvl);
	}

private:
	MQPluginHandle m_pluginHandle;
	std::shared_ptr<ProxySink> m_proxySink;
};

LoggingManager* g_loggingManager = nullptr;

//----------------------------------------------------------------------------

LoggingManager::LoggingManager()
{
}

LoggingManager::~LoggingManager()
{
	eqlib::ShutdownLogging();
	spdlog::shutdown();
}

void LoggingManager::Initialize()
{
	fs::path loggingPath = mq::internal_paths::Logs;

	// TODO: Load logging configuration
	m_chatSink = std::make_shared<MQChatSink>();
	m_debugSink = std::make_shared<MQDebugSink>();
	m_fileSink = std::make_shared<MQFileSink>();

	m_mainLogger = std::static_pointer_cast<MQPluginLogger>(CreatePluginLogger("MQ", mqplugin::ThisPluginHandle));
	m_pluginLoggers[mqplugin::ThisPluginHandle.pluginID] = m_mainLogger;
	spdlog::set_default_logger(m_mainLogger);

	SPDLOG_DEBUG("Logging Initialized");

	// Create a temporary logger to initialize the eqlib logging system. It
	// will make a copy.
	auto tempLogger = std::make_shared<spdlog::logger>("eqlib");
	tempLogger->sinks().push_back(m_debugSink);
	tempLogger->sinks().push_back(m_fileSink);

	eqlib::InitializeLogging(tempLogger);
}

void LoggingManager::InitializeLogfile()
{
	fmt::memory_buffer filename;
	auto out = fmt::format_to(fmt::appender(filename),
		"{}\\{}", mq::internal_paths::Logs, mq::CreateLogFilename("MacroQuest"));
	*out = 0;

	m_fileSink->set_filename(filename.data());
}

void LoggingManager::Shutdown()
{
	m_fileSink.reset();
	m_debugSink.reset();
	m_chatSink.reset();
	m_mainLogger.reset();
	m_pluginLoggers.clear();
}

std::shared_ptr<MQFileSink> LoggingManager::CreateFileSink(std::string_view baseName,
	spdlog::level::level_enum log_level) const
{
	fmt::memory_buffer filename;
	auto out = fmt::format_to(fmt::appender(filename),
		"{}\\{}", mq::internal_paths::Logs, mq::CreateLogFilename(baseName));
	*out = 0;

	// Create file sink
	auto sink = std::make_shared<MQFileSink>();
	sink->set_filename(filename.data());
	sink->set_level(log_level);

	return sink;
}

std::shared_ptr<spdlog::logger> LoggingManager::CreatePluginLogger(
	const std::string& pluginName, const MQPluginHandle& pluginHandle)
{
	auto iter = m_pluginLoggers.find(pluginHandle.pluginID);
	if (iter != m_pluginLoggers.end())
		return iter->second;

	auto new_logger = std::make_shared<MQPluginLogger>(pluginName, pluginHandle,
		m_fileSink, m_chatSink, m_debugSink);
	// TODO: Configure logger from settings.

	m_pluginLoggers[pluginHandle.pluginID] = new_logger;

	return new_logger;
}

std::shared_ptr<spdlog::logger> LoggingManager::GetLogger(const MQPluginHandle& pluginHandle) const
{
	auto iter = m_pluginLoggers.find(pluginHandle.pluginID);
	if (iter != m_pluginLoggers.end())
		return iter->second;

	return nullptr;
}

std::shared_ptr<MQPluginLogger> LoggingManager::GetLoggerInternal(const MQPluginHandle& pluginHandle) const
{
	auto iter = m_pluginLoggers.find(pluginHandle.pluginID);
	if (iter != m_pluginLoggers.end())
		return iter->second;

	return nullptr;
}

void LoggingManager::RemovePluginLogger(const MQPluginHandle& pluginHandle)
{
	m_pluginLoggers.erase(pluginHandle.pluginID);
}

void LoggingManager::WriteChatColor(const char* line, int color, int filter, const MQPluginHandle& pluginHandle)
{
	if (std::shared_ptr<MQPluginLogger> logger = GetLoggerInternal(pluginHandle))
	{
		spdlog::level::level_enum level = spdlog::level::info;

		if (!logger->should_log(level))
			return;

		logger->do_log(spdlog::log_clock::now(), spdlog::source_loc{}, level, line, color, filter);
	}
}

void LoggingManager::WriteChatFormat(const char* format, va_list va, int color, const MQPluginHandle& pluginHandle)
{
	if (std::shared_ptr<MQPluginLogger> logger = GetLoggerInternal(pluginHandle))
	{
		spdlog::level::level_enum level = spdlog::level::info;

		if (!logger->should_log(level))
			return;

		// _vscprintf doesn't count terminating '\0'
		size_t len = _vscprintf(format, va) + 1;

		fmt::memory_buffer buffer;
		buffer.resize(len);

		vsprintf_s(buffer.data(), len, format, va);
		logger->do_log(spdlog::log_clock::now(), spdlog::source_loc{}, level, buffer.data(), color);
	}
}

void LoggingManager::LogMessage(const char* format, va_list va, int level_, bool toFile, const MQPluginHandle& pluginHandle)
{
	if (std::shared_ptr<MQPluginLogger> logger = GetLoggerInternal(pluginHandle))
	{
		spdlog::level::level_enum level = static_cast<spdlog::level::level_enum>(level_);

		if (!logger->should_log(level))
			return;

		// _vscprintf doesn't count terminating '\0'
		size_t len = _vscprintf(format, va) + 1;

		fmt::memory_buffer buffer;
		buffer.resize(len);

		vsprintf_s(buffer.data(), len, format, va);
		logger->do_log(spdlog::log_clock::now(), spdlog::source_loc{}, level, buffer.data(), 0, toFile);
	}
}

//----------------------------------------------------------------------------

// Outputs to debug console when gFilterDebug is false.  Does not output to file. (/filter debug or FilterDebug=0 in ini)
void DebugSpew(const char* szFormat, ...)
{
	if (gFilterDebug)
		return;

	va_list vaList;
	va_start(vaList, szFormat);

	g_loggingManager->LogMessage(szFormat, vaList, spdlog::level::debug, false,
		mqplugin::ThisPluginHandle);
}

// Outputs to debug console always.  Outputs to file when gSpewToFile is true. (/spewfile or DebugSpewToFile=1 in ini)
void DebugSpewAlways(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	g_loggingManager->LogMessage(szFormat, vaList, spdlog::level::debug, gSpewToFile,
		mqplugin::ThisPluginHandle);
}

// Outputs to debug console when DBG_SPEW is defined
void DebugSpewNoFile(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	g_loggingManager->LogMessage(szFormat, vaList, spdlog::level::debug, false,
		mqplugin::ThisPluginHandle);
}

void WriteChatColor(const char* line, int color, int filter)
{
	g_loggingManager->WriteChatColor(line, color, filter, mqplugin::ThisPluginHandle);
}

void WriteChatf(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	g_loggingManager->WriteChatFormat(szFormat, vaList, -1, mqplugin::ThisPluginHandle);
}

void WriteChatColorf(const char* szFormat, int color, ...)
{
	va_list vaList;
	va_start(vaList, color);

	g_loggingManager->WriteChatFormat(szFormat, vaList, color, mqplugin::ThisPluginHandle);
}

//============================================================================
//============================================================================

void InitializeLogging()
{
	g_loggingManager = new LoggingManager();
	g_loggingManager->Initialize();
}

void InitializeLogFile()
{
	g_loggingManager->InitializeLogfile();
}

void ShutdownLogging()
{
	if (g_loggingManager)
	{
		g_loggingManager->Shutdown();
		delete g_loggingManager;
	}
}

//----------------------------------------------------------------------------
// Eventually these will get replaced too

void SyntaxError(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	int len = _vscprintf(szFormat, vaList) + 1 + 32;

	auto out = std::make_unique<char[]>(len);
	char* szOutput = out.get();

	vsprintf_s(szOutput, len, szFormat, vaList);
	WriteChatColor(szOutput, CONCOLOR_YELLOW);
	strcpy_s(gszLastSyntaxError, szOutput);
}

void FatalError(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	int len = _vscprintf(szFormat, vaList) + 1 + 32;

	auto out = std::make_unique<char[]>(len);
	char* szOutput = out.get();

	vsprintf_s(szOutput, len, szFormat, vaList);
	WriteChatColor(szOutput, CONCOLOR_RED);
	strcpy_s(gszLastNormalError, szOutput);

	if (bAllErrorsLog)
	{
		MacroLog(nullptr, "Fatal Error");
		MacroLog(nullptr, szOutput);
	}

	if (gMacroBlock)
	{
		DumpStack(nullptr, nullptr);
		EndMacro(pLocalPlayer, "");
	}
}

void MacroError(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	int len = _vscprintf(szFormat, vaList) + 1 + 32;

	auto out = std::make_unique<char[]>(len);
	char* szOutput = out.get();

	vsprintf_s(szOutput, len, szFormat, vaList);
	WriteChatColor(szOutput, CONCOLOR_RED);
	strcpy_s(gszLastNormalError, szOutput);

	if (bAllErrorsLog)
	{
		MacroLog(nullptr, "Macro Error");
		MacroLog(nullptr, szOutput);
	}

	if (gMacroBlock)
	{
		if (bAllErrorsDumpStack || bAllErrorsFatal)
			DumpStack(nullptr, nullptr);

		if (bAllErrorsFatal)
			EndMacro(pLocalPlayer, "");
	}
}

void MQ2DataError(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	int len = _vscprintf(szFormat, vaList) + 1 + 32;

	auto out = std::make_unique<char[]>(len);
	char* szOutput = out.get();

	vsprintf_s(szOutput, len, szFormat, vaList);
	WriteChatColor(szOutput, CONCOLOR_RED);
	strcpy_s(gszLastMQ2DataError, szOutput);

	if (bAllErrorsLog)
	{
		MacroLog(nullptr, "Data Error");
		MacroLog(nullptr, szOutput);
	}

	if (gMacroBlock)
	{
		if (bAllErrorsDumpStack || bAllErrorsFatal)
			DumpStack(nullptr, nullptr);

		if (bAllErrorsFatal)
			EndMacro(pLocalPlayer, "");
	}
}

//----------------------------------------------------------------------------
// Utility functions

static void StrReplaceSection(char* szInsert, size_t InsertLen, DWORD Length, const char* szNewString)
{
	DWORD NewLength = (DWORD)strlen(szNewString);
	memmove(&szInsert[NewLength], &szInsert[Length], strlen(&szInsert[Length]) + 1);
	memcpy_s(szInsert, InsertLen - NewLength, szNewString, NewLength);
}

void ConvertCR(char* Text, size_t LineLen)
{
	// not super-efficient but this is only being called at initialization currently.
	while (char* Next = strstr(Text, "\\n"))
	{
		int len = (int)(Next - Text);
		StrReplaceSection(Next, LineLen - len, 2, "\n");
	}
}

//============================================================================

} // namespace mq
