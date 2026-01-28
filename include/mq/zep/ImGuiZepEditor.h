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

#include "zep/display.h"
#include "zep/editor.h"

#include <imgui/imgui.h>
#include <memory>

namespace Zep
{
	class ZepMessage;
	class ZepEditor;
}

namespace mq {

//============================================================================

class ZepEditor_ImGui;

inline Zep::NVec2f toNVec2f(const ImVec2& im)
{
	return Zep::NVec2f(im.x, im.y);
}
inline ImVec2 toImVec2(const Zep::NVec2f& im)
{
	return ImVec2(im.x, im.y);
}
inline ImVec2 toImVec2(const Zep::NVec2i& im)
{
	return ImVec2(static_cast<float>(im.x), static_cast<float>(im.y));
}

inline Zep::NVec2f toNVec2fAdjusted(const ImVec2& im, const Zep::NVec2f& rel)
{
	return Zep::NVec2f(im.x + rel.x, im.y + rel.y);
}

inline ImVec2 toImVec2Adjusted(const Zep::NVec2f& im, const Zep::NVec2f& rel)
{
	return ImVec2(im.x + rel.x, im.y + rel.y);
}

class ImGuiZepEditor
{
public:
	ImGuiZepEditor(std::string_view id = "");
	virtual ~ImGuiZepEditor();

	void SetFont(Zep::ZepTextType, ImFont* pFont, int fontSize);

	virtual void Render(const char* id, const ImVec2& displaySize = ImVec2());

	virtual void Render(const ImVec2& displaySize = ImVec2())
	{
		Render(m_id.c_str(), displaySize);
	}

	Zep::ZepEditor& GetEditor() const;
	Zep::ZepWindow& GetWindow() const { return *m_window; }

	std::shared_ptr<Zep::ZepBuffer> CreateFileBuffer(std::string_view file);
	std::shared_ptr<Zep::ZepBuffer> CreateBuffer(std::string_view name, std::string_view text);
	std::shared_ptr<Zep::ZepBuffer> GetActiveBuffer() const;
	void SetActiveBuffer(const std::shared_ptr<Zep::ZepBuffer>& buffer);
	bool RemoveBuffer(const std::shared_ptr<Zep::ZepBuffer>& buffer);

	Zep::GlyphIterator Begin() const;
	Zep::GlyphIterator End() const;

	uint32_t GetWindowFlags() const;
	void SetWindowFlags(uint32_t flags);
	void ToggleFlag(uint32_t flag);

protected:
	virtual void Notify(const std::shared_ptr<Zep::ZepMessage>& message);
	virtual void DispatchMouseEvent(const std::shared_ptr<Zep::ZepMessage>& message);

	ZepEditor_ImGui* m_editor = nullptr;
	Zep::ZepWindow* m_window = nullptr;

	const bool m_wordWrap = true; // Word-wrap disabled doesn't work properly.

private:
	std::string m_id;

	struct EventReceiver;
	std::unique_ptr<EventReceiver> m_eventReceiver;
};

} // namespace mq
