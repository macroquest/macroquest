/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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
#include "zep/mcommon/math/math.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>

namespace mq::imgui {

//============================================================================

inline Zep::NVec2f toNVec2f(const ImVec2& im)
{
	return Zep::NVec2f(im.x, im.y);
}
inline ImVec2 toImVec2(const Zep::NVec2f& im)
{
	return ImVec2(im.x, im.y);
}

inline Zep::NVec2f toNVec2fAdjusted(const ImVec2& im, const Zep::NVec2f& rel)
{
	return Zep::NVec2f(im.x + rel.x, im.y + rel.y);
}

inline ImVec2 toImVec2Adjusted(const Zep::NVec2f& im, const Zep::NVec2f& rel)
{
	return ImVec2(im.x + rel.x, im.y + rel.y);
}

//----------------------------------------------------------------------------

class ZepDisplay_ImGui : public Zep::ZepDisplay
{
public:
	ZepDisplay_ImGui(const Zep::NVec2f& pixelScale);

	virtual void DrawChars(Zep::ZepFont& font, const Zep::NVec2f& pos, Zep::ZepColor col, const uint8_t* text_begin, const uint8_t* text_end /* = nullptr */) const override;
	virtual void DrawLine(const Zep::NVec2f& start, const Zep::NVec2f& end, Zep::ZepColor color /* = ZepColor(255u) */, float width /* = 1.0f */) const override;
	virtual void DrawRectFilled(const Zep::NRectf& rc, Zep::ZepColor col /* = ZepColor(255u) */) const override;
	virtual void SetClipRect(const Zep::NRectf& rc) override { m_clipRect = rc; }
	virtual Zep::ZepFont& GetFont(Zep::ZepTextType type) override;

	void SetScreenPosition(const Zep::NVec2f& screenPos) { m_screenPos = screenPos; }

private:
	Zep::NRectf m_clipRect;
	Zep::NVec2f m_screenPos;
};

//----------------------------------------------------------------------------

class ZepEditor_ImGui : public Zep::ZepEditor
{
public:
	using Zep::ZepEditor::ZepEditor;

	void HandleInput();
	void SetScreenPosition(const Zep::NVec2f& screenPos) { m_screenPos = screenPos; }

private:
	void HandleMouseInput();
	void HandleKeyboardInput();

private:
	float m_lastClick = -1.0f;
	bool m_hasMouse = false;
	Zep::NVec2f m_screenPos;
};

//----------------------------------------------------------------------------

class ImGuiZepEditor : public Zep::IZepComponent
{
public:
	ImGuiZepEditor();
	virtual ~ImGuiZepEditor();

	void SetFont(Zep::ZepTextType, ImFont* pFont, int pixelHeight);

	virtual Zep::ZepEditor& GetEditor() const override
	{
		return *m_editor;
	}

	virtual void Render(const char* id, const ImVec2& displaySize = ImVec2());

protected:
	virtual void Notify(std::shared_ptr<Zep::ZepMessage> message) override;

private:
	ZepDisplay_ImGui* m_display = nullptr;
	ZepEditor_ImGui* m_editor = nullptr;
};


} // namespace mq::imgui
