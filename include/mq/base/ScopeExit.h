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

namespace mq {

template <typename Callback>
class [[nodiscard]] ScopeExit final
{
public:
	explicit ScopeExit(Callback&& callback) noexcept;
	~ScopeExit() noexcept;

	// non-copyable
	ScopeExit(const ScopeExit&) = delete;
	ScopeExit& operator=(const ScopeExit&) = delete;

	// moveable-only
	ScopeExit(ScopeExit&& other) = default;
	ScopeExit& operator=(ScopeExit&&) = default;

	void release() noexcept;

private:
	Callback m_callback;
	bool m_active = true;
};

template <typename Callback>
ScopeExit<Callback>::ScopeExit(Callback&& callback) noexcept
	: m_callback(std::move(callback))
{
}

template <typename Callback>
ScopeExit<Callback>::~ScopeExit() noexcept
{
	if (m_active)
	{
		m_callback();
	}
}

template <typename Callback>
void ScopeExit<Callback>::release() noexcept
{
	m_active = false;
}

template <typename Callback>
auto MakeScopeExit(Callback&& callback) noexcept -> ScopeExit<Callback>
{
	return ScopeExit<Callback>(std::forward<Callback>(callback));
}

#define SCOPE_EXIT_CAT2(a, b) a##b
#define SCOPE_EXIT_CAT(a, b) SCOPE_EXIT_CAT2(a, b)
#define SCOPE_EXIT(callback) const auto SCOPE_EXIT_CAT(scope_exit_, __LINE__) = MakeScopeExit([&]() { callback; })

} // namespace mq
