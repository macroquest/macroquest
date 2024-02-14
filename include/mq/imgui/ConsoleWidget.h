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
#include "mq/base/Color.h"

#include <memory>
#include <string_view>

namespace mq {
	struct ImGuiZepConsole;
}

namespace mq::imgui {

// Interface to a ImGuiZepConsole, suitable for exposure to plugins.

class ConsoleWidget
{
public:
	static inline const MQColor DEFAULT_COLOR = MQColor(240, 240, 240, 255);

	MQLIB_OBJECT static  std::shared_ptr<ConsoleWidget> Create(std::string_view id);
	virtual ~ConsoleWidget() {};

	virtual void Render(const ImVec2& displaySize = ImVec2()) = 0;

	virtual void Clear() = 0;
	virtual void AppendText(std::string_view text, MQColor defaultColor = DEFAULT_COLOR,
		bool appendNewLine = false) = 0;

	virtual bool IsCursorAtEnd() const = 0;
	virtual void ScrollToBottom() = 0;

	virtual bool GetAutoScroll() const = 0;
	virtual void SetAutoScroll(bool autoScroll) = 0;

	virtual int GetMaxBufferLines() const = 0;
	virtual void SetMaxBufferLines(int maxBufferLines) = 0;

	virtual float GetOpacity() const = 0;
	virtual void SetOpacity(float opacity) = 0;
};

} // namespace mq::imgui
