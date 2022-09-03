/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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

#include "common/StringUtils.h"
#include <optional>

namespace mq {
/**
* A simple Lexer to allow for simple grouping DSLs
**/
class SimpleLexerParseError : public std::exception
{
private:
	std::string m_message;

public:
	SimpleLexerParseError(std::string_view message) : m_message(message) {}
	std::string msg() { return m_message; }
};
template <typename Reducible>
class SimpleLexer
{
public:
	using Condition = Reducible(*)();
	using Term = Reducible(*)(std::string_view);
	using Reducer = Reducible(*)(Reducible&&, Reducible&&);
	using Modifier = Reducible(*)(Reducible&&);
	using Error = Reducible(*)();

private:
	// store keywords as a view-keyed map backed by its values to allow for quick searching
	// with string_view arguments (you can always construct a string_view from a string trivially)
	ci_unordered::map<std::string_view, std::unique_ptr<std::string>> m_keywords;
	ci_unordered::map<std::string_view, Condition> m_conditions;
	ci_unordered::map<std::string_view, Term> m_terms;
	ci_unordered::map<std::string_view, Reducer> m_reducers;
	ci_unordered::map<std::string_view, Modifier> m_modifiers;
	Error m_error;

	std::optional<std::string_view> add_keyword(std::string_view keyword)
	{
		auto it = m_keywords.find(keyword);
		if (it == m_keywords.end())
		{
			// we need to store unique pointers here to explicitly avoid small string optimizations
			auto ins = std::make_unique<std::string>(keyword);
			m_keywords.emplace(*ins, std::move(ins));
			return *m_keywords.at(keyword);
		}

		return std::nullopt;
	}

	template <typename T>
	void add_rule(std::string_view command, const T& rule, ci_unordered::map<std::string_view, T>& map)
	{
		auto keyword = add_keyword(command);
		if (keyword)
			map.emplace(*keyword, rule);
	}

	Reducible lexer(std::vector<std::string_view>::iterator& it, std::vector<std::string_view>::iterator& end)
	{
		// the default will get completely replaced on the first successful term evaluation
		Reducible&& parsed = std::move(m_error());
		std::optional<Reducer> current_reducer = {};
		std::optional<Modifier> current_modifier = {};
		std::optional<Term> current_term = {};
		std::vector<std::string_view> args = {};

		auto&& eval = [](
			Reducible&& parsed,
			std::optional<Reducer>& current_reducer,
			std::optional<Modifier>& current_modifier,
			Reducible&& reducible)
		{
			if (current_modifier)
			{
				reducible = (*current_modifier)(std::move(reducible));
				current_modifier = std::nullopt;
			}

			if (current_reducer)
			{
				parsed = (*current_reducer)(std::move(parsed), std::move(reducible));
				current_reducer = std::nullopt;
				return std::move(parsed);
			}
			else
				return std::move(reducible);
		};

		auto concat_view = [](const std::vector<std::string_view>& args) -> std::string_view
		{
			if (args.empty())
				throw SimpleLexerParseError("Parse error: no arguments provided to term.");

			// since args are guaranteed to be ordered views from the same larger string_view, we can reconstruct the full argument like this
			return std::string_view(
				args.front().data(),
				std::distance(
					args.front().data(),
					args.back().data() + args.back().size()));
		};

		while (it != end && *it != ")")
		{
			if (m_keywords.find(*it) != m_keywords.end())
			{
				// two steps:
				// First, we need to process any pending arguments with the current term
				// Second, we need to process the new keyword we just found
				// if we have args and no current term, then we have a parse error
				// or if somehow we have a keyword that doesn't exist in a map, we have a lexer setup issue
				if (current_term)
				{
					parsed = eval(std::move(parsed), current_reducer, current_modifier, (*current_term)(concat_view(args)));
					args.clear();
					current_term = std::nullopt;
				}
				else if (!args.empty()) // parse error, we don't need to check the case where there are no args because that is expected
					throw SimpleLexerParseError(fmt::format("Parse error on term {} with args [{}].", *it, fmt::join(args, " ")));

				if (*it == "(")
				{
					parsed = eval(std::move(parsed), current_reducer, current_modifier, std::move(lexer(++it, end)));
					if (it == end)
						throw SimpleLexerParseError("Parse error: unbalanced grouping");
				}
				else if (*it == ")")
					return std::move(parsed);
				else if (auto condition = m_conditions.find(*it); condition != m_conditions.end())
					parsed = eval(std::move(parsed), current_reducer, current_modifier, condition->second());
				else if (auto term = m_terms.find(*it); term != m_terms.end())
					current_term = term->second;
				else if (auto reducer = m_reducers.find(*it); reducer != m_reducers.end())
					current_reducer = reducer->second;
				else if (auto modifier = m_modifiers.find(*it); modifier != m_modifiers.end())
					current_modifier = modifier->second;
				else // lexer setup error -- shouldn't be able to happen
					throw SimpleLexerParseError(fmt::format("Lexer error: {} is a keyword without a definition.", *it));
			}
			else
				args.push_back(*it);

			++it;
		}

		// don't need to worry about cleaning up temporary variables here, just do a final parse
		if (current_term)
			parsed = eval(std::move(parsed), current_reducer, current_modifier, (*current_term)(concat_view(args)));
		else if (!args.empty())
			throw SimpleLexerParseError(fmt::format("Parse error on last term with args [{}].", fmt::join(args, " ")));
		else if (current_modifier || current_reducer)
			throw SimpleLexerParseError("Parse error: dangling keyword.");

		return parsed;
	}

	std::vector<std::string_view> explode(std::string_view line)
	{
		auto tokenized = tokenize_args(line);
		std::vector<std::string_view> ret;
		for (auto token : tokenized)
		{
			if (!token.empty() && token.front() == '(')
			{
				ret.push_back(token.substr(0, 1));
				if (token.length() > 1) ret.push_back(token.substr(1, std::string_view::npos));
			}
			else if (!token.empty() && token.back() == ')')
			{
				ret.push_back(token.substr(0, token.length() - 1));
				if (token.length() > 1) ret.push_back(token.substr(token.length() - 1, std::string_view::npos));
			}
			else if (!token.empty())
			{
				ret.push_back(token);
			}
		}

		return ret;
	}

public:
	void AddRule(std::string_view command, const Condition& condition) { add_rule(command, condition, m_conditions); }
	void AddRule(std::string_view command, const Term& term) { add_rule(command, term, m_terms); }
	void AddRule(std::string_view command, const Reducer& reducer) { add_rule(command, reducer, m_reducers); }
	void AddRule(std::string_view command, const Modifier& modifier) { add_rule(command, modifier, m_modifiers); }

	template <typename T, typename... Args>
	void AddRules(std::string_view command, const T& f, Args&&... args)
	{
		AddRule(command, f);
		if constexpr (sizeof...(Args) > 0)
		{
			AddRules(std::forward<Args>(args)...);
		}
	}

	template <typename... Args>
	SimpleLexer(Error error, Args&&... args) : m_error(std::move(error))
	{
		// parens are specially processed, so prevent users from adding them, but consider them keywords
		add_keyword("(");
		add_keyword(")");
		AddRules(std::forward<Args>(args)...);
	}

	Reducible operator()(std::string_view line)
	{
		auto exploded = explode(line);
		auto begin = exploded.begin(), end = exploded.end();
		return lexer(begin, end);
	}
};

} // namespace mq
