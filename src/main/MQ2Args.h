/*
 * MacroQuest2: The extension platform for EverQuest
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

#include "MQ2Main.h"
#include <args/args.hxx>

namespace mq {

using Writer = void(*)(const char*, ...);
template <Writer writer = &WriteChatf>
class MQ2Args : public args::ArgumentParser
{
public:
	const char* reset_color = "\ax";
	const char* command_color = "\at";
	const char* command_description_color = "\a-t";
	const char* arg_color = "\ay";
	const char* arg_description_color = "\a-y";
	const char* epilog_color = "\at";

	MQ2Args(const std::string& description_, const std::string& epilog_ = std::string()) : ArgumentParser(description_, epilog_) {}

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

template <typename Ret, typename... Args>
auto MQ2AddArg(Args... help_args)
{
	return[help_args = std::make_tuple(std::forward<Args>(help_args)...)](args::Group& arguments)
	{
		return std::make_from_tuple<Ret>(std::tuple_cat(std::tie(arguments), help_args));
	};
}

class MQ2Argument : public args::Command
{
private:
	template <typename... Funcs, size_t... Indexes>
	static auto TransformSubargsHelper(std::tuple<Funcs...> const& funcs, Group& arguments, std::index_sequence<Indexes...>)
	{
		return std::make_tuple([&arguments](auto func) { return func(arguments); }(std::get<Indexes>(funcs))...);
	}

	template <typename... Funcs>
	static auto TransformSubargs(std::tuple<Funcs...> const& funcs, Group& arguments)
	{
		return TransformSubargsHelper(funcs, arguments, std::make_index_sequence<sizeof...(Funcs)> {});
	}

public:
	MQ2Argument() = delete;
	template <typename F, typename... SubArguments>
	MQ2Argument(Group& base, std::string name, std::string help, F parse, SubArguments... subargs) :
		Command(base, name, help,
			[parse = std::forward<F>(parse), subargs = std::make_tuple(std::forward<SubArguments>(subargs)...)](args::Subparser& parser)
			{
				args::Group arguments(parser, "", args::Group::Validators::AtMostOne);
				auto command_args = TransformSubargs(subargs, arguments);
				MQ2HelpArgument help(parser);
				parser.Parse();
				std::apply(parse, command_args);
			}) {}
};

class MQ2HelpArgument : public args::Command
{
private:
	Group base;

public:
	MQ2HelpArgument() = delete;
	MQ2HelpArgument(Group& base_) : base(base_), Command(base_, "help", "show command/argument help",
		[this](args::Subparser&)
		{
			SelectCommand(nullptr); // de-select the help command
			throw args::Help(Name());
		}) {}
};
}
