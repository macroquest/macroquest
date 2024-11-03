/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#pragma once

#include "mq/zep/ImGuiZepConsole.h"

namespace eqlib
{
	struct TextTagInfo;
}

namespace mq {

// This delegate extends the default delegate by adding support for EQ chat links.
class MQConsoleDelegate : public ImGuiZepConsoleDelegate
{
public:
	MQLIB_OBJECT virtual bool OnHyperlinkClicked(ImGuiZepConsole* console, Zep::ZepMouseButton button, uint32_t modifiers,
		const std::string& hyperlinkData, int hyperlinkId) override;

	MQLIB_OBJECT virtual bool OnInsertFormattedText(ImGuiZepConsole* console, Zep::GlyphIterator position,
		std::string_view text, ImU32 color) override;

private:
	void InsertHyperlink(ImGuiZepConsole* console, Zep::GlyphIterator position, const eqlib::TextTagInfo& tagInfo);
};

} // namespace mq
