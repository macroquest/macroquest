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
#include <argparse/argparse.h>

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

class anon_args {
public:
	enum class sub_commands {
		none,
		add,
		drop,
		alias,
		unalias,
		unknown
	};

	argparse::ArgumentParser main;
	argparse::ArgumentParser unknown;
	ci_unordered::map<argparse::ArgumentParser> subcommands;

	anon_args() {
		main = argparse::ArgumentParser("main parser");
		main.add_argument("category")
			.default_value("none")
			.help("the action you want to take with argument parser")
			.action([this](std::string_view value)
				{
					auto it = subcommands.find(value);
					if (it != subcommands.end())
						return it->second;
					else
						return unknown;
				});


		main.add_argument("remaining")
			.remaining();

		unknown = argparse::ArgumentParser("unknown command");
		unknown.help("unknown parameter value");
	}
};

void AddAnonymization(SPAWNINFO* pChar, std::string_view args)
{

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

	char szBuff[MAX_STRING] = { 0 };
	GetArg(szBuff, szLine, 1);

	using CommandFunc = void(*)(SPAWNINFO*, std::string_view);
	ci_unordered::map<CommandFunc> arg_map;

	arg_map.emplace("add", [](SPAWNINFO* pChar, std::string_view args) {});
}
}
