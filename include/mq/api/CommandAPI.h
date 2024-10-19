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

#include "mq/base/Common.h"
#include <functional>

namespace eqlib
{
	class PlayerClient;
}

namespace mq {

//
// MacroQuest Commands
//

/**
 * A handler function that is invoked when a chat command is executed.
 *
 * @param pChar Pointer to the current player.
 * @param szLine Line of text passed as an argument to the command
 */
using MQCommandHandler = std::function<void(eqlib::PlayerClient* pChar, const char* szLine)>;


/**
 * Adds a new chat command. If the command conflicts with an existing EverQuest command, then
 * this command will take precedence. If the ocmmand conflicts with another MacroQuest command,
 * then this call will fail.
 *
 * @param command The name of the command to register, including a leading forward slash, e.g. "/hello"
 * @param handler The function that will be call when the command is executed.
 * @param eq If true, the handler is ignored and the command will be forwarded to EQ.
 * @param parse If true, any macro expressions will be parsed before passing the text to the handler.
 * @param inGame If true, the command will only be registered while in the game world.
 * @return True if the command is successfully added.
 */
bool AddCommand(std::string_view command, MQCommandHandler handler, bool eq = false, bool parse = true, bool inGame = false);

/**
 * Remove a previously registered chat command.
 *
 * @param command The name of the command to remove, including leading forward slash, e.g. "/hello"
 * @return True if the command was successfully removed
 */
bool RemoveCommand(std::string_view command);

/**
 * Check if a given chat command is registered
 *
 * @param command The chat command to check, including leading forward slash.
 * @return True if the given string is registered as a chat command.
 */
bool IsCommand(std::string_view command);

/**
 * Execute a chat command
 *
 * @param command The chat command to execute
 * @param delayed If true, this function will return immediate and the command will be.
 * executed on the next Pulse.
 */
void DoCommand(const char* command, bool delayed = true);

/**
 * Execute a chat command with printf style formatting. Behaves the same as `DoCommand`,
 * with delay set to false. This version is provided as a convenience.
 *
 * @param szFormat The format string of the chat command to execute
 * @param ... parameters to pass to the format string
 */
void DoCommandf(const char* szFormat, ...);

/**
 * Execute a chat command after a delay.
 *
 * @param command The chat command to execute
 * @param msDelay Delay in milliseconds to wait before executing the command.
 */
void TimedCommand(const char* command, int msDelay);

/**
 * Add a new alias.
 *
 * @param alias The alias as a slash command (e.g. /foo)
 * @param replacement The replacement when the alias is executed (e.g. /echo hello, foo!)
 * @param persist If true, the alias will be persisted to disk.
 * @return True if the alias was created.
 */
bool AddAlias(const std::string& alias, const std::string& replacement, bool persist = true);

/**
 * Remove an alias.
 *
 * @param alias Name of the alias to remove.
 * @return True if the alias was removed.
 */
bool RemoveAlias(const std::string& alias);

/**
 * Check if an alias exists.
 *
 * @param alias Name of the alias to check.
 * @return True if the alias exists.
 */
bool IsAlias(const std::string& alias);

/**
 * Old command handler. Do not use! Only provided for backwards compatibility. New code
 * should always provide a const char* parameter.
 *
 * @deprecated
 */
using fEQCommandOld = void(*)(eqlib::PlayerClient* pChar, char* command);

/**
 * A handler function that is invoked with a slash command is executed.
 *
 * @param pChar Pointer to the current player.
 * @param command Line of text passed as an argument to the command
 */
using fEQCommand = void(*)(eqlib::PlayerClient* pChar, const char* command);


/**
 * Search the list of EQ commands and return a function pointer to the command if it exists
 *
 * @param command The EQ slash command to search for (e.g. "/xtarget")
 * @return A pointer to the command function, or nullptr if not found.
 */
MQLIB_API fEQCommand FindEQCommand(std::string_view command);

/**
 * Adds a new chat command. If the command conflicts with an existing EverQuest command, then
 * this command will take precedence. If the ocmmand conflicts with another MacroQuest command,
 * then this call will fail.
 *
 * @param command The name of the command to register, including a leading forward slash, e.g. "/hello"
 * @param handler The function that will be call when the command is executed.
 * @param eq If true, the handler is ignored and the command will be forwarded to EQ.
 * @param parse If true, any macro expressions will be parsed before passing the text to the handler.
 * @param inGame If true, the command will only be registered while in the game world.
 * @return True if the command is successfully added.
 *
 * @deprecated This overload of AddCommand is deprecated. Please instead use the version that expects a
 * const char* parameter in its handler
 */
inline void AddCommand(std::string_view command, fEQCommandOld handler, bool eq = false, bool parse = true, bool inGame = false)
{
	AddCommand(command, (fEQCommand)handler, eq, parse, inGame);
}

/**
 * Execute a command. This used to be an internal function, and wasn't meant to be used by plugins, but some
 * plugins used it anyways, so it remains. Please use the non-deprecated version of DoCommand instead.
 *
 * @param pChar [Ignored] Pointer to the current PlayerClient.
 * @param szLine The command string to execute.
 * @param delayed True if the command should be deferred until the next pulse.
 *
 * @deprecated Use `DoCommand(const char* command, bool delayed)` instead.
 */
void HideDoCommand(eqlib::PlayerClient* pChar, const char* szLine, bool delayed);

/**
 * Execute a command. This version of DoCommand is deprecated in favor of the version that takes a delayed
 * parameter instead of pChar. This overlay of DoCommand always delays the call.
 *
 * @param pChar [Ignored] Pointer to the current PlayerClient.
 * @param szLine The command string to execute.
 *
 * @deprecated Use `DoCommand(const char* command, bool delayed)` instead.
 */
void DoCommand(eqlib::PlayerClient* pChar, const char* szLine);

/**
 * Execute a command. This function used to be a macro that called HideDoCommand, and just like that function,
 * this one is also deprecated. Use the version of DoCommand that takes the delayed parameter instead.
 *
 * @param szLine The command string to execute.
 *
 * @deprecated Use `DoCommand(const char* command, bool delayed)` instead.
 */
void EzCommand(const char* szLine);

} // namespace mq
