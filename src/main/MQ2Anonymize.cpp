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

#include <regex>
#include <utility>

#include "pch.h"
#include "MQ2Main.h"

namespace mq {

static class anon_replacer {
public:
	const std::string target;
	const ci_unordered::set alternates;
	const std::regex search_string;

private:

	static std::regex build_regex(std::string_view Name, const ci_unordered::set& Alternates) {
		return std::regex(
			fmt::format("\b({}{})\b", Name, std::accumulate(Alternates.cbegin(), Alternates.cend(), std::string(),
				[](const std::string& _text, const std::string& alt) -> std::string {
					return _text + "|" + alt;
				})),
			std::regex_constants::icase);
	}

	static ci_unordered::set add_alternate(std::string_view _alternate, ci_unordered::set _alternates) {
		_alternates.emplace(_alternate);
		return _alternates;
	}

	static ci_unordered::set drop_alternate(std::string_view _alternate, ci_unordered::set _alternates) {
		_alternates.erase(_alternate);
		_alternates;
	}

public:
	anon_replacer(std::string_view _name, std::string_view _target, ci_unordered::set _alternates)
		: target(_target), alternates(_alternates), search_string(build_regex(_name, _alternates)) {}

	anon_replacer(const anon_replacer& other)
		: target(other.target), alternates(other.alternates), search_string(other.search_string) {}

	anon_replacer& operator=(const anon_replacer& other) { return anon_replacer(other); }

	static anon_replacer with_alternate(std::string_view _name, std::string_view _alternate, const anon_replacer& replacer) {
		return anon_replacer(_name, replacer.target, add_alternate(_alternate, replacer.alternates));
	}

	static anon_replacer without_alternate(std::string_view _name, std::string_view _alternate, const anon_replacer& replacer) {
		return anon_replacer(_name, replacer.target, drop_alternate(_alternate, replacer.alternates));
	}
};

// the source string_view is checked _after_ string parsing
// the target string is parsed before replacement
ci_unordered::map<anon_replacer> filter_map;

// the source string_view here will be used to index
// creating a regex that looks like `(source|all|the|alternates)`

// add an anonymization rule to the map -- if the rule already exists, assume we want to updated the target
void AddAnonymization(std::string_view Name, std::string_view Replace) {
	auto [it, result] = filter_map.try_emplace(Name, anon_replacer(Name, Replace, {}));

	if (!result)
		it->second = anon_replacer(Name, Replace, it->second.alternates);
}

void DropAnonymization(std::string_view Name) {
	filter_map.erase(Name);
}

void AddAlternate(std::string_view Name, std::string_view Alternate) {
	filter_map[Name] = anon_replacer::with_alternate(Name, Alternate, filter_map[Name]);
}

void DropAlternate(std::string_view Name, std::string_view Alternate) {
	filter_map[Name] = anon_replacer::without_alternate(Name, Alternate, filter_map[Name]);
}

// process string to anonymize
std::string Anonymize(std::string_view Text) {
	return std::accumulate(filter_map.cbegin(), filter_map.cend(), std::string(Text),
		[](const std::string& _text, std::pair<std::string_view, anon_replacer> _pair) -> std::string {
			return std::regex_replace(_text, _pair.second.search_string, ModifyMacroString(_pair.second.target));
		});
}
}
