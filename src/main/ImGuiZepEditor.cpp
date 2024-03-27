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

#include "pch.h"
#include "ImGuiZepEditor.h"

#include "zep/display.h"
#include "zep/editor.h"
#include "zep/mode.h"
#include "zep/mode_standard.h"
#include "zep/tab_window.h"

#include <imgui.h>
#include <imgui_internal.h>

using namespace Zep;

namespace mq::imgui {

//----------------------------------------------------------------------------

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

class ZepFont_ImGui : public Zep::ZepFont
{
public:
	ZepFont_ImGui(Zep::ZepDisplay& display, ImFont* pFont, int pixelHeight);

	virtual void SetPixelHeight(int pixelHeight) override;
	virtual Zep::NVec2f GetTextSize(const uint8_t* begin, const uint8_t* end = nullptr) const override;

	ImFont* GetImFont() const { return m_pFont; }

private:
	ImFont* m_pFont = nullptr;
	float m_fontScale = 1.0f;
};

ZepFont_ImGui::ZepFont_ImGui(ZepDisplay& display, ImFont* pFont, int pixelHeight)
	: ZepFont(display)
	, m_pFont(pFont)
{
	SetPixelHeight(pixelHeight);
}

void ZepFont_ImGui::SetPixelHeight(int pixelHeight)
{
	InvalidateCharCache();
	m_pixelHeight = pixelHeight;
}

NVec2f ZepFont_ImGui::GetTextSize(const uint8_t* pBegin, const uint8_t* pEnd) const
{
	// This is the code from ImGui internals; we can't call GetTextSize, because it doesn't return the correct 'advance' formula, which we
	// need as we draw one character at a time...
	const float font_size = m_pFont->FontSize;
	ImVec2 text_size = m_pFont->CalcTextSizeA(float(GetPixelHeight()), FLT_MAX, FLT_MAX, (const char*)pBegin, (const char*)pEnd, NULL);
	if (text_size.x == 0.0)
	{
		// Make invalid characters a default fixed_size
		const char chDefault = 'A';
		text_size = m_pFont->CalcTextSizeA(float(GetPixelHeight()), FLT_MAX, FLT_MAX, &chDefault, (&chDefault + 1), NULL);
	}

	return toNVec2f(text_size);
}

//----------------------------------------------------------------------------

class ZepEditor_ImGui : public Zep::ZepDisplay, public Zep::ZepEditor
{
public:
	ZepEditor_ImGui(const ZepPath& root, uint32_t flags = 0, IZepFileSystem* pFileSystem = nullptr, const NVec2f& pixelScale = NVec2f{ 1.0f, 1.0f })
		: Zep::ZepDisplay(pixelScale)
		, Zep::ZepEditor(this, root, flags, pFileSystem)
	{
	}

	void HandleInput();
	void SetScreenPosition(const NVec2f& screenPos) { m_screenPos = screenPos; }

private:
	void HandleMouseInput();
	void HandleKeyboardInput();

	virtual void DrawChars(ZepFont& font, const NVec2f& pos, ZepColor col, const uint8_t* text_begin, const uint8_t* text_end) const override;
	virtual void DrawLine(const NVec2f& start, const NVec2f& end, ZepColor color, float width) const override;
	virtual void DrawRectFilled(const NRectf& rc, ZepColor col) const override;
	virtual void SetClipRect(const NRectf& rc) override { m_clipRect = rc; }
	virtual Zep::ZepFont& GetFont(ZepTextType type) override;

private:
	float m_lastClick = -1.0f;
	bool m_mouseDrag = false;
	bool m_mouseInside = false;
	NVec2f m_screenPos;
	NRectf m_clipRect;
};

static ZepMouseButton ImGuiMouseToZepButton(int index)
{
	switch (index)
	{
	case 0:
		return ZepMouseButton::Left;
	case 1:
		return ZepMouseButton::Right;
	case 2:
		return ZepMouseButton::Middle;
	case 3:
		return ZepMouseButton::Button4;
	case 4:
		return ZepMouseButton::Button5;
	default:
		return ZepMouseButton::Unknown;
	}
}

void ZepEditor_ImGui::DrawChars(ZepFont& font, const NVec2f& pos, ZepColor col,
	const uint8_t* text_begin, const uint8_t* text_end) const
{
	ImFont* imFont = static_cast<ZepFont_ImGui&>(font).GetImFont();
	ImDrawList* drawList = ImGui::GetWindowDrawList();

	if (text_end == nullptr)
	{
		text_end = text_begin + strlen((const char*)text_begin);
	}
	if (m_clipRect.Width() == 0)
	{
		drawList->AddText(imFont, float(font.GetPixelHeight()), toImVec2Adjusted(pos, m_screenPos), col.ToPackedABGR(), (const char*)text_begin, (const char*)text_end);
	}
	else
	{
		drawList->PushClipRect(toImVec2Adjusted(m_clipRect.topLeftPx, m_screenPos), toImVec2Adjusted(m_clipRect.bottomRightPx, m_screenPos), true);
		drawList->AddText(imFont, float(font.GetPixelHeight()), toImVec2Adjusted(pos, m_screenPos), col.ToPackedABGR(), (const char*)text_begin, (const char*)text_end);
		drawList->PopClipRect();
	}
}

void ZepEditor_ImGui::DrawLine(const NVec2f& start, const NVec2f& end, ZepColor color, float width) const
{
	ImDrawList* drawList = ImGui::GetWindowDrawList();

	// Background rect for numbers
	if (m_clipRect.Width() == 0)
	{
		drawList->AddLine(toImVec2Adjusted(start, m_screenPos), toImVec2Adjusted(end, m_screenPos), color.ToPackedABGR(), width);
	}
	else
	{
		drawList->PushClipRect(toImVec2Adjusted(m_clipRect.topLeftPx, m_screenPos), toImVec2Adjusted(m_clipRect.bottomRightPx, m_screenPos), true);
		drawList->AddLine(toImVec2Adjusted(start, m_screenPos), toImVec2Adjusted(end, m_screenPos), color.ToPackedABGR(), width);
		drawList->PopClipRect();
	}
}

void ZepEditor_ImGui::DrawRectFilled(const NRectf& rc, ZepColor color) const
{
	ImDrawList* drawList = ImGui::GetWindowDrawList();

	// Background rect for numbers
	if (m_clipRect.Width() == 0)
	{
		drawList->AddRectFilled(toImVec2Adjusted(rc.topLeftPx, m_screenPos), toImVec2Adjusted(rc.bottomRightPx, m_screenPos), color.ToPackedABGR());
	}
	else
	{
		drawList->PushClipRect(toImVec2Adjusted(m_clipRect.topLeftPx, m_screenPos), toImVec2Adjusted(m_clipRect.bottomRightPx, m_screenPos), true);
		drawList->AddRectFilled(toImVec2Adjusted(rc.topLeftPx, m_screenPos), toImVec2Adjusted(rc.bottomRightPx, m_screenPos), color.ToPackedABGR());
		drawList->PopClipRect();
	}
}

ZepFont& ZepEditor_ImGui::GetFont(ZepTextType type)
{
	if (m_fonts[(int)type] == nullptr)
	{
		m_fonts[(int)type] = std::make_shared<ZepFont_ImGui>(*this, ImGui::GetIO().Fonts[0].Fonts[0], int(16.0f * GetPixelScale().y));
	}

	return *m_fonts[(int)type];
}


void ZepEditor_ImGui::HandleInput()
{
	if (ImGui::IsWindowFocused())
	{
		HandleKeyboardInput();
	}

	if (ImGui::IsWindowHovered() || m_mouseDrag)
	{
		m_mouseInside = true;
		HandleMouseInput();
	}
	else if (m_mouseInside)
	{
		m_mouseInside = false;

		// Send a move event outside the window
		auto& io = ImGui::GetIO();
		NVec2f mousePos = toNVec2f(io.MousePos) - m_screenPos;
		OnMouseMove(mousePos, ImGuiMouseToZepButton(-1), 0);
	}
}

void ZepEditor_ImGui::HandleMouseInput()
{
	auto& io = ImGui::GetIO();
	uint32_t mod = 0;

	if (io.KeyCtrl)
	{
		mod |= ModifierKey::Ctrl;
	}

	if (io.KeyShift)
	{
		mod |= ModifierKey::Shift;
	}

	int clickCount = 1;
	m_mouseDrag = false;

	NVec2f mousePos = toNVec2f(io.MousePos) - m_screenPos;

	if (mod == 0)
	{
		bool click = ImGui::IsMouseClicked(0);
		bool doubleClick = ImGui::IsMouseDoubleClicked(0);
		double t = ImGui::GetTime();
		bool tripleClick = click && !doubleClick && (m_lastClick != -1.0f && (t - m_lastClick) < io.MouseDoubleClickTime);

		if (tripleClick)
		{
			m_lastClick = -1.0f;
			clickCount = 3;
		}
		else if (click || doubleClick)
		{
			m_lastClick = (float)ImGui::GetTime();
			clickCount = doubleClick ? 2 : 1;
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		if (ImGui::IsMouseClicked(i) || ImGui::IsMouseDoubleClicked(i))
		{
			OnMouseDown(mousePos, ImGuiMouseToZepButton(i), mod, clickCount);
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		if (ImGui::IsMouseDragging(i) && ImGui::IsMouseDown(i))
		{
			OnMouseMove(mousePos, ImGuiMouseToZepButton(i), mod);
			m_mouseDrag = true;
		}
	}

	if (!m_mouseDrag)
	{
		OnMouseMove(mousePos, ImGuiMouseToZepButton(-1), 0);
	}

	for (int i = 0; i < 5; ++i)
	{
		if (ImGui::IsMouseReleased(i))
		{
			OnMouseUp(mousePos, ImGuiMouseToZepButton(i));
		}
	}

	if (io.MouseWheel != 0.f)
	{
		// TODO: Customize the scroll rate
		OnMouseWheel(mousePos, io.MouseWheel * 12.5f);
	}


	//if (ImGui::IsWindowHovered())
	//    ImGui::SetMouseCursor(ImGuiMouseCursor_TextInput);
}

void ZepEditor_ImGui::HandleKeyboardInput()
{
	auto& io = ImGui::GetIO();

	bool handled = false;
	uint32_t mod = 0;

	if (io.KeyCtrl)
	{
		mod |= ModifierKey::Ctrl;
	}

	if (io.KeyShift)
	{
		mod |= ModifierKey::Shift;
	}

	auto pWindow = GetActiveTabWindow()->GetActiveWindow();
	const auto& buffer = pWindow->GetBuffer();

	if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Tab)))
	{
		buffer.GetMode()->AddKeyPress(ExtKeys::TAB, mod);
		return;
	}
	if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Escape)))
	{
		buffer.GetMode()->AddKeyPress(ExtKeys::ESCAPE, mod);
		return;
	}
	else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Enter)))
	{
		buffer.GetMode()->AddKeyPress(ExtKeys::RETURN, mod);
		return;
	}
	else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Delete)))
	{
		buffer.GetMode()->AddKeyPress(ExtKeys::DEL, mod);
		return;
	}
	else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Home)))
	{
		buffer.GetMode()->AddKeyPress(ExtKeys::HOME, mod);
		return;
	}
	else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_End)))
	{
		buffer.GetMode()->AddKeyPress(ExtKeys::END, mod);
		return;
	}
	else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Backspace)))
	{
		buffer.GetMode()->AddKeyPress(ExtKeys::BACKSPACE, mod);
		return;
	}
	else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_RightArrow)))
	{
		buffer.GetMode()->AddKeyPress(ExtKeys::RIGHT, mod);
		return;
	}
	else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_LeftArrow)))
	{
		buffer.GetMode()->AddKeyPress(ExtKeys::LEFT, mod);
		return;
	}
	else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_UpArrow)))
	{
		buffer.GetMode()->AddKeyPress(ExtKeys::UP, mod);
		return;
	}
	else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_DownArrow)))
	{
		buffer.GetMode()->AddKeyPress(ExtKeys::DOWN, mod);
		return;
	}
	else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_PageDown)))
	{
		buffer.GetMode()->AddKeyPress(ExtKeys::PAGEDOWN, mod);
		return;
	}
	else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_PageUp)))
	{
		buffer.GetMode()->AddKeyPress(ExtKeys::PAGEUP, mod);
		return;
	}
	else if (io.KeyCtrl)
	{
		for (int ch = 'A'; ch <= 'Z'; ch++)
		{
			if (ImGui::IsKeyPressed(static_cast<ImGuiKey>(ch)))
			{
				buffer.GetMode()->AddKeyPress(ch - 'A' + 'a', mod);
				handled = true;
			}
		}
	}

	if (!handled)
	{
		for (int n = 0; n < io.InputQueueCharacters.Size && io.InputQueueCharacters[n]; n++)
		{
			// Ignore '\r' - sometimes ImGui generates it!
			if (io.InputQueueCharacters[n] == '\r')
				continue;

			buffer.GetMode()->AddKeyPress(io.InputQueueCharacters[n], mod);
		}
	}
}

//----------------------------------------------------------------------------

ImGuiZepEditor::ImGuiZepEditor()
{
	m_editor = new ZepEditor_ImGui(ZepPath(), ZepEditorFlags::DisableThreads);
	m_editor->RegisterCallback(this);
	m_editor->SetGlobalMode(ZepMode_Standard::StaticName());
}

ImGuiZepEditor::~ImGuiZepEditor()
{
	if (m_editor)
	{
		m_editor->UnRegisterCallback(this);
		delete m_editor;
	}
}

void ImGuiZepEditor::Notify(std::shared_ptr<Zep::ZepMessage> message)
{
	if (message->messageId == Zep::Msg::GetClipBoard)
	{
		const char* clipboard = ImGui::GetClipboardText();
		message->str = clipboard ? clipboard : "";
		message->handled = true;
	}
	else if (message->messageId == Zep::Msg::SetClipBoard)
	{
		ImGui::SetClipboardText(message->str.c_str());
		message->handled = true;
	}
}

void ImGuiZepEditor::SetFont(Zep::ZepTextType type, ImFont* pFont, int pixelHeight)
{
	m_editor->SetFont(type, std::make_shared<ZepFont_ImGui>(*m_editor, pFont, pixelHeight));
}

ZepEditor& ImGuiZepEditor::GetEditor() const
{
	return *m_editor;
}

void ImGuiZepEditor::Render(const char* id, const ImVec2& displaySize)
{
	ImVec2 actualSize = ImGui::GetContentRegionAvail();
	if (displaySize.x != 0)
		actualSize.x = displaySize.x;
	if (displaySize.y != 0)
		actualSize.y = displaySize.y;

	ImGuiIO& io = ImGui::GetIO();

	if (ImGui::BeginChild(id, actualSize, false, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground))
	{
		m_editor->SetScreenPosition(toNVec2f(ImGui::GetCursorScreenPos()));
		m_editor->SetDisplayRegionSize(toNVec2f(actualSize));

		m_editor->HandleInput();

		ImGui::PushAllowKeyboardFocus(true);

		m_editor->SetHasFocus(ImGui::IsWindowFocused());
		if (ImGui::IsWindowFocused())
		{
			io.WantCaptureKeyboard = true;
			io.WantTextInput = true;
		}
		m_editor->Display();

		ImGui::PopAllowKeyboardFocus();
	}

	ImGui::EndChild();
}

} // namespace mq::imgui
