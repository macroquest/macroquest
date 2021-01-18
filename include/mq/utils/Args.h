/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2020 MacroQuest Authors
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

#include <args/args.hxx>

namespace mq {

using Writer = void(*)(const char*, ...);
template <Writer writer>
class Args : public args::ArgumentParser
{
public:
	const char* reset_color = "\ax";
	const char* command_color = "\at";
	const char* command_description_color = "\a-t";
	const char* arg_color = "\ay";
	const char* arg_description_color = "\a-y";
	const char* epilog_color = "\at";

	Args(const std::string& description_, const std::string& epilog_ = std::string()) : ArgumentParser(description_, epilog_)
	{
		helpParams.addChoices = true;
		helpParams.choiceString = " -- Choices: ";
		LongPrefix("hel");
	}

	virtual void Help() const
	{
		auto& command = SelectedCommand();

		auto commandProgLine = command.GetProgramLine(helpParams);
		writer("\n%s%s%s %s", command_color, Prog().c_str(), reset_color, join(commandProgLine, " ").c_str());

		const auto& commandDescription = command.Description().empty() ? command.Help() : command.Description();
		writer("%s%s%s\n", command_description_color, commandDescription.c_str(), reset_color);

		for (const auto& desc : command.GetDescription(helpParams, 0))
		{
			auto flags = std::get<0>(desc);
			auto info = std::get<1>(desc);

			writer("%s%s%s -- %s%s%s", arg_color, flags.c_str(), reset_color, arg_description_color, info.c_str(), reset_color);
		}

		if (!command.Epilog().empty())
			writer("%s%s%s", epilog_color, command.Epilog().c_str(), reset_color);
	}
};

class HelpArgument : public args::HelpFlag
{
public:
	HelpArgument() = delete;
	HelpArgument(args::Group& base) : HelpFlag(base, "help", "displays this help text", { 'h', '?', "p" }) {}
};
}
