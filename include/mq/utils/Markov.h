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

#include <fmt/format.h>

#include <random>

namespace mq {
namespace markov {

/**
 * \brief markov chain class for using to generate similar words from lists of words
 */
class Chain
{
	/**
	 * \brief helper class that will determine next letter probabilities based on combinations
	 */
	class ContextualSampler
	{
	public:
		ContextualSampler(const std::unordered_set<char>& letters, const float prior)
			: m_random(std::random_device{}())
		{
			for (const auto l : letters)
			{
				m_counts[l] = prior;
				m_total += prior;
			}
		}

		void Observe(const char event, const float count = 1.f)
		{
			m_counts[event] += count;
			m_total += count;
		}

		[[nodiscard]] char Sample()
		{
			auto sample = std::uniform_real_distribution(0.f, m_total)(m_random);
			for (const auto [event, count] : m_counts)
			{
				if (sample <= count)
					return event;

				sample -= count;
			}

			return m_suffix;
		}

	private:
		std::default_random_engine m_random;
		std::unordered_map<char, float> m_counts;
		float m_total = 0.f;
	};

public:
	/**
	 * \brief construct a markov chain from at least a list of words
	 * \param words a list of words that you want the results to mimic
	 * \param order the number of letters to consider when deciding next letters
	 * \param prior the baseline probability for any letter to occur next (lower means less random)
	 */
	Chain(const std::vector<std::string>& words, const uint8_t order = 3, const float prior = 0.001f)
		: m_order(order)
		, m_prior(prior)
		, m_prefix(order, m_boundary)
		, m_letters({ m_boundary, m_suffix })
	{
		for (const auto& word : words)
			m_letters.insert(word.begin(), word.end());

		for (const auto& word : words)
			Observe(word);
	}

	/**
	 * \brief the primary interface of the class, used to generate new words
	 * \return a word that mimics the list of words the chain was created with
	 */
	[[nodiscard]] std::string Generate()
	{
		std::string context = m_prefix;
		auto next_char = Sample(context);
		std::string result = { next_char };
		context.push_back(next_char);

		while (result.back() != m_suffix)
		{
			next_char = Sample(context);
			result.push_back(next_char);
			context.push_back(next_char);
		}

		result.pop_back();
		return result;
	}

private:
	/**
	 * \brief samples the distribution to determine the next character
	 * \param context a context (list of characters) for which to generate the next character
	 * \return the next character in the sequence based on the context
	 */
	[[nodiscard]] char Sample(std::string& context)
	{
		Backoff(context);
		return Get(context).Sample();
	}

	/**
	 * \brief observe a word and add it to the markov model
	 * \param word the word to add to the sampling algorithm
	 * \param count the weight of the character chains in this word
	 */
	void Observe(const std::string& word, float count = 1.f)
	{
		const auto sample = fmt::format("{}{}{}", m_prefix, word, m_suffix);
		for (size_t idx = 0; idx < sample.size() - m_order; ++idx)
		{
			const auto context = sample.substr(idx, m_order);
			const auto event = sample.at(idx + m_order);

			for (auto ctx_it = context.begin(); ctx_it != context.end(); ++ctx_it)
			{
				Get(std::string(ctx_it, context.end())).Observe(event, count);
			}
		}
	}

	/**
	 * \brief get the correct probabilistic model based on the context
	 * \param context the small string context used to generate a character from the model
	 * \return the sampling model to use for the context
	 */
	ContextualSampler& Get(const std::string& context)
	{
		return m_data.try_emplace(context, m_letters, m_prior).first->second;
	}

	/**
	 * \brief backs off the context until we find something we have in the model
	 * \param context the small string context we want to regulate
	 */
	void Backoff(std::string& context)
	{
		if (context.size() > m_order)
			context.erase(0, context.size() - m_order);
		else if (context.size() < m_order)
			context.insert(context.begin(), m_order - context.size(), m_boundary);

		for (auto it = m_data.find(context); it == m_data.end() && !context.empty(); it = m_data.find(context))
			context.erase(0, 1);
	}

	std::unordered_map<std::string, ContextualSampler> m_data;
	const uint8_t m_order;
	const float m_prior;
	const std::string m_prefix;
	std::unordered_set<char> m_letters;

	static constexpr char m_boundary = '\2';
	static constexpr char m_suffix = '\3';
};

} // namespace markov
} // namespace mq


