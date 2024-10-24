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

namespace mq::imgui {

//============================================================================

class ZepEditor_ImGui;

class ImGuiZepEditor
{
public:
	ImGuiZepEditor(std::string_view id = "");
	virtual ~ImGuiZepEditor();

	void SetFont(Zep::ZepTextType, ImFont* pFont);

	virtual void Render(const char* id, const ImVec2& displaySize = ImVec2());

	virtual void Render(const ImVec2& displaySize = ImVec2())
	{
		Render(m_id.c_str(), displaySize);
	}

	Zep::ZepEditor& GetEditor() const;

protected:
	virtual void Notify(const std::shared_ptr<Zep::ZepMessage>& message);
	virtual void DispatchMouseEvent(const std::shared_ptr<Zep::ZepMessage>& message);

private:
	ZepEditor_ImGui* m_editor = nullptr;
	std::string m_id;

	struct EventReceiver;
	std::unique_ptr<EventReceiver> m_eventReceiver;
};


} // namespace mq::imgui
