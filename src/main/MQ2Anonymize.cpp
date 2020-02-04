/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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
#include "MQ2Main.h"

#include <locale>
#include <codecvt>
#include <regex>
#include <args/args.hxx>

namespace mq {

class anon_replacer {
public:
	std::string target;
	ci_unordered::set alternates;
	std::regex search_string;

private:
	std::regex build_regex(std::string_view name)
	{
		return std::regex(
			fmt::format("\b({}{})\b", name, std::accumulate(alternates.cbegin(), alternates.cend(), std::string(),
				[](const std::string& text, std::string_view alt) -> std::string {
					return fmt::format("{}|{}", text, alt);
				})),
			std::regex_constants::icase);
	}

	static ci_unordered::set add_alternate(std::string_view alternate, ci_unordered::set&& alternates)
	{
		alternates.emplace(alternate);
		return alternates;
	}

	static ci_unordered::set drop_alternate(std::string_view alternate, ci_unordered::set&& alternates)
	{
		alternates.erase(alternate);
		return alternates;
	}

public:
	anon_replacer(std::string_view name, std::string_view target, ci_unordered::set&& alternates)
		: target(target), alternates(std::move(alternates))
	{
		search_string = build_regex(name);
	}

	static anon_replacer with_alternate(std::string_view name, std::string_view alternate, anon_replacer&& replacer)
	{
		return anon_replacer(name, replacer.target, add_alternate(alternate, std::move(replacer.alternates)));
	}

	static anon_replacer without_alternate(std::string_view name, std::string_view alternate, anon_replacer&& replacer)
	{
		return anon_replacer(name, replacer.target, drop_alternate(alternate, std::move(replacer.alternates)));
	}

	// this is designed to be used with an accumulate that returns a string, so move the old text in
	std::string replace_text(std::string&& text)
	{
		return std::regex_replace(std::move(text), search_string, ModifyMacroString(target));
	}
};

// the source string_view is checked _after_ string parsing
// the target string is parsed before replacement
ci_unordered::map<anon_replacer> filter_map;

// the source string_view here will be used to index
// creating a regex that looks like `(source|all|the|alternates)`

// add an anonymization rule to the map -- if the rule already exists, assume we want to update the target
void AddAnonymization(std::string_view Name, std::string_view Replace)
{
	auto [it, result] = filter_map.try_emplace(Name, anon_replacer(Name, Replace, {}));

	if (!result) // this is automatically an assign since result is false
		filter_map.insert_or_assign(Name, anon_replacer(Name, Replace, std::move(it->second.alternates)));
}

void DropAnonymization(std::string_view Name)
{
	filter_map.erase(Name);
}

// will not add an entry if there is nothing available
void AddAlternate(std::string_view Name, std::string_view Alternate)
{
	auto result = filter_map.find(Name);
	// automatically an assign, but we want to make sure not to add an element without a target
	if (result != filter_map.end())
		filter_map.insert_or_assign(Name, anon_replacer::with_alternate(Name, Alternate, std::move(result->second)));
}

// will not add an entry if there is nothing available
void DropAlternate(std::string_view Name, std::string_view Alternate)
{
	auto result = filter_map.find(Name);
	// automatically an assign, but we want to make sure not to add an element without a target
	if (result != filter_map.end())
		filter_map.insert_or_assign(Name, anon_replacer::without_alternate(Name, Alternate, std::move(result->second)));
}

// process string to anonymize
std::string Anonymize(std::string_view Text)
{
	return std::accumulate(filter_map.cbegin(), filter_map.cend(), std::string(Text),
		[](std::string text, std::pair<std::string_view, anon_replacer> pair) -> std::string {
			return pair.second.replace_text(std::move(text));
		});
}

// ***************************************************************************
// Function:    MQAnon
// Description: Our '/mqanon' command
//              Controls the anonymization filtering of text
// Usage:       /mqanon [add|drop|alias|unalias]
// ***************************************************************************

// TODO: Make sure to add this command with `Parse = false`!
void MQAnon(SPAWNINFO* pChar, char* szLine)
{
	if (!pChar)
		return;

	args::ArgumentParser arg_parser("mqanon parser");
	arg_parser.Prog("/mqanon");
	args::Group commands(arg_parser, "commands");

	args::Command add(commands, "add", "adds anonymization name and replacement text", [](args::Subparser& parser) {
		args::Group command(parser, "command", args::Group::Validators::AtMostOne);

		args::Group arguments(command, "arguments", args::Group::Validators::All);
		args::Positional<std::string> name(arguments, "name", "the name to anonymize");
		args::Positional<std::string> replace(arguments, "replace", "the text to replace the name with");

		args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
		args::HelpFlag h(flags, "help", "help", { 'h', "help" });
		parser.Parse();

		AddAnonymization(name.Get(), replace.Get());
	});

	args::Command drop(commands, "drop", "drops anonymization name from list of filtered names", [](args::Subparser& parser) {
		args::Group command(parser, "command", args::Group::Validators::AtMostOne);

		args::Group arguments(command, "arguments", args::Group::Validators::All);
		args::Positional<std::string> name(arguments, "name", "the name to de-anonymize");

		args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
		args::HelpFlag h(flags, "help", "help", { 'h', "help" });
		parser.Parse();

		DropAnonymization(name.Get());
	});

	args::Command alias(commands, "alias", "adds an alias for a name in the list of filtered names", [](args::Subparser& parser) {
		args::Group command(parser, "command", args::Group::Validators::AtMostOne);

		args::Group arguments(command, "arguments", args::Group::Validators::All);
		args::Positional<std::string> name(arguments, "name", "the name entry to alias");
		args::Positional<std::string> alias(arguments, "alias", "the alias to also search for when replacing the name");

		args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
		args::HelpFlag h(flags, "help", "help", { 'h', "help" });
		parser.Parse();

		AddAlternate(name.Get(), alias.Get());
	});

	args::Command unalias(commands, "unalias", "drops an alias for a name in the list of filtered names", [](args::Subparser& parser) {
		args::Group command(parser, "command", args::Group::Validators::AtMostOne);

		args::Group arguments(command, "arguments", args::Group::Validators::All);
		args::Positional<std::string> name(arguments, "name", "the name entry to unalias");
		args::Positional<std::string> alias(arguments, "alias", "the alias to also stop searching for when replacing the name");

		args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
		args::HelpFlag h(flags, "help", "help", { 'h', "help" });
		parser.Parse();

		DropAlternate(name.Get(), alias.Get());
	});

	args::HelpFlag h(commands, "help", "help", { 'h', "help" });

	try
	{
		arg_parser.ParseArgs(allocate_args(szLine));
	}
	catch (args::Help)
	{
		WriteChatColor(arg_parser.Help().c_str());
	}
	catch (const args::Error& e)
	{
		WriteChatColor(e.what());
	}
}
}
