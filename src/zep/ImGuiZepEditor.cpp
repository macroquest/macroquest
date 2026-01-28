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
#include "mq/zep/ImGuiZepEditor.h"
#include "mq/imgui/ImGuiUtils.h"

#include "zep/display.h"
#include "zep/editor.h"
#include "zep/mode.h"
#include "zep/mode_standard.h"
#include "zep/tab_window.h"

#include <imgui.h>
#include <imgui_internal.h>

using namespace Zep;

namespace mq {

//----------------------------------------------------------------------------

static ImU32 GetStyleModulatedColor(ZepColor color)
{
	color.a = static_cast<uint8_t>(color.a * ImGui::GetStyle().Alpha);
	return color.ToPackedABGR();
}

class ZepFont_ImGui : public Zep::ZepFont
{
public:
	ZepFont_ImGui(ZepDisplay& display, ImFont* pFont, int fontSize)
		: ZepFont(display, fontSize)
		, m_pFont(pFont)
	{
	}

	Zep::NVec2f GetTextSize(const uint8_t* pBegin, const uint8_t* pEnd) const override
	{
		// This is the code from ImGui internals; we can't call GetTextSize, because it doesn't return the correct 'advance' formula, which we
		// need as we draw one character at a time...
		ImVec2 text_size = m_pFont->CalcTextSizeA(float(GetPixelHeight()), FLT_MAX, FLT_MAX, (const char*)pBegin, (const char*)pEnd, NULL);
		if (text_size.x == 0.0)
		{
			// Make invalid characters a default fixed_size
			const char chDefault = 'A';
			text_size = m_pFont->CalcTextSizeA(float(GetPixelHeight()), FLT_MAX, FLT_MAX, &chDefault, (&chDefault + 1), NULL);
		}

		return toNVec2f(text_size);
	}

	ImFont* GetImFont() const { return m_pFont; }

private:
	ImFont* m_pFont = nullptr;
};

//----------------------------------------------------------------------------

class ZepEditor_ImGui : public Zep::ZepDisplay, public Zep::ZepEditor
{
public:
	ZepEditor_ImGui(const ZepPath& root, uint32_t flags = 0, IZepFileSystem* pFileSystem = nullptr, const NVec2f& pixelScale = NVec2f{ 1.0f, 1.0f })
		: Zep::ZepDisplay(pixelScale)
		, Zep::ZepEditor(this, root, flags, pFileSystem)
	{
		m_fonts[static_cast<int>(Zep::ZepTextType::Text)] =
			std::make_shared<ZepFont_ImGui>(*this, mq::imgui::ConsoleFont, 16);
		m_fonts[static_cast<int>(Zep::ZepTextType::UI)] =
			std::make_shared<ZepFont_ImGui>(*this, mq::imgui::ConsoleFont, 16);
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

	ImU32 color = GetStyleModulatedColor(col);

	if (m_clipRect.Width() == 0)
	{
		drawList->AddText(imFont, float(font.GetPixelHeight()), toImVec2Adjusted(pos, m_screenPos), color, (const char*)text_begin, (const char*)text_end);
	}
	else
	{
		drawList->PushClipRect(toImVec2Adjusted(m_clipRect.topLeftPx, m_screenPos), toImVec2Adjusted(m_clipRect.bottomRightPx, m_screenPos), true);
		drawList->AddText(imFont, float(font.GetPixelHeight()), toImVec2Adjusted(pos, m_screenPos), color, (const char*)text_begin, (const char*)text_end);
		drawList->PopClipRect();
	}
}

void ZepEditor_ImGui::DrawLine(const NVec2f& start, const NVec2f& end, ZepColor col, float width) const
{
	ImDrawList* drawList = ImGui::GetWindowDrawList();

	ImU32 color = GetStyleModulatedColor(col);

	// Background rect for numbers
	if (m_clipRect.Width() == 0)
	{
		drawList->AddLine(toImVec2Adjusted(start, m_screenPos), toImVec2Adjusted(end, m_screenPos), color, width);
	}
	else
	{
		drawList->PushClipRect(toImVec2Adjusted(m_clipRect.topLeftPx, m_screenPos), toImVec2Adjusted(m_clipRect.bottomRightPx, m_screenPos), true);
		drawList->AddLine(toImVec2Adjusted(start, m_screenPos), toImVec2Adjusted(end, m_screenPos), color, width);
		drawList->PopClipRect();
	}
}

void ZepEditor_ImGui::DrawRectFilled(const NRectf& rc, ZepColor col) const
{
	ImDrawList* drawList = ImGui::GetWindowDrawList();

	ImU32 color = GetStyleModulatedColor(col);

	// Background rect for numbers
	if (m_clipRect.Width() == 0)
	{
		drawList->AddRectFilled(toImVec2Adjusted(rc.topLeftPx, m_screenPos), toImVec2Adjusted(rc.bottomRightPx, m_screenPos), color);
	}
	else
	{
		drawList->PushClipRect(toImVec2Adjusted(m_clipRect.topLeftPx, m_screenPos), toImVec2Adjusted(m_clipRect.bottomRightPx, m_screenPos), true);
		drawList->AddRectFilled(toImVec2Adjusted(rc.topLeftPx, m_screenPos), toImVec2Adjusted(rc.bottomRightPx, m_screenPos), color);
		drawList->PopClipRect();
	}
}

ZepFont& ZepEditor_ImGui::GetFont(ZepTextType type)
{
	ZepFont* font = m_fonts[static_cast<int>(type)].get();

	return *font;
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

struct ZepImGuiKeyMap
{
	ImGuiKey imguiKey;
	uint32_t zepKey;
};

static ZepImGuiKeyMap s_zepSpecialKeyMap[] = {
	{ ImGuiKey_Enter,          Zep::ExtKeys::RETURN },
	{ ImGuiKey_Escape,         Zep::ExtKeys::ESCAPE },
	{ ImGuiKey_Backspace,      Zep::ExtKeys::BACKSPACE },
	{ ImGuiKey_LeftArrow,      Zep::ExtKeys::LEFT },
	{ ImGuiKey_RightArrow,     Zep::ExtKeys::RIGHT },
	{ ImGuiKey_UpArrow,        Zep::ExtKeys::UP },
	{ ImGuiKey_DownArrow,      Zep::ExtKeys::DOWN },
	{ ImGuiKey_Tab,            Zep::ExtKeys::TAB },
	{ ImGuiKey_Delete,         Zep::ExtKeys::DEL },
	{ ImGuiKey_Home,           Zep::ExtKeys::HOME },
	{ ImGuiKey_End,            Zep::ExtKeys::END },
	{ ImGuiKey_PageDown,       Zep::ExtKeys::PAGEDOWN },
	{ ImGuiKey_PageUp,         Zep::ExtKeys::PAGEUP },
	{ ImGuiKey_F1,             Zep::ExtKeys::F1 },
	{ ImGuiKey_F2,             Zep::ExtKeys::F2 },
	{ ImGuiKey_F3,             Zep::ExtKeys::F3 },
	{ ImGuiKey_F4,             Zep::ExtKeys::F4 },
	{ ImGuiKey_F5,             Zep::ExtKeys::F5 },
	{ ImGuiKey_F6,             Zep::ExtKeys::F6 },
	{ ImGuiKey_F7,             Zep::ExtKeys::F7 },
	{ ImGuiKey_F8,             Zep::ExtKeys::F8 },
	{ ImGuiKey_F9,             Zep::ExtKeys::F9 },
	{ ImGuiKey_F10,            Zep::ExtKeys::F10 },
	{ ImGuiKey_F11,            Zep::ExtKeys::F11 },
	{ ImGuiKey_F12,            Zep::ExtKeys::F12 },
};

static ZepImGuiKeyMap s_zepPrintableKeyMap[] = {
	{ ImGuiKey_Space,          ' ' },
	{ ImGuiKey_0,              '0' },
	{ ImGuiKey_1,              '1' },
	{ ImGuiKey_2,              '2' },
	{ ImGuiKey_3,              '3' },
	{ ImGuiKey_4,              '4' },
	{ ImGuiKey_5,              '5' },
	{ ImGuiKey_6,              '6' },
	{ ImGuiKey_7,              '7' },
	{ ImGuiKey_8,              '8' },
	{ ImGuiKey_9,              '9' },
	{ ImGuiKey_A,              'a' },
	{ ImGuiKey_B,              'b' },
	{ ImGuiKey_C,              'c' },
	{ ImGuiKey_D,              'd' },
	{ ImGuiKey_E,              'e' },
	{ ImGuiKey_F,              'f' },
	{ ImGuiKey_G,              'g' },
	{ ImGuiKey_H,              'h' },
	{ ImGuiKey_I,              'i' },
	{ ImGuiKey_J,              'j' },
	{ ImGuiKey_K,              'k' },
	{ ImGuiKey_L,              'l' },
	{ ImGuiKey_M,              'm' },
	{ ImGuiKey_N,              'n' },
	{ ImGuiKey_O,              'o' },
	{ ImGuiKey_P,              'p' },
	{ ImGuiKey_Q,              'q' },
	{ ImGuiKey_R,              'r' },
	{ ImGuiKey_S,              's' },
	{ ImGuiKey_T,              't' },
	{ ImGuiKey_U,              'u' },
	{ ImGuiKey_V,              'v' },
	{ ImGuiKey_W,              'w' },
	{ ImGuiKey_X,              'x' },
	{ ImGuiKey_Y,              'y' },
	{ ImGuiKey_Z,              'z' },
	{ ImGuiKey_Apostrophe,     '\'' },
	{ ImGuiKey_Comma,          ',' },
	{ ImGuiKey_Minus,          '-' },
	{ ImGuiKey_Period,         '.' },
	{ ImGuiKey_Slash,          '/' },
	{ ImGuiKey_Semicolon,      ';' },
	{ ImGuiKey_Equal,          '=' },
	{ ImGuiKey_LeftBracket,    '[' },
	{ ImGuiKey_Backslash,      '\\' },
	{ ImGuiKey_RightBracket,   ']' },
	{ ImGuiKey_GraveAccent,    '`' },
};


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

	if (ZepBuffer* pBuffer = GetActiveBuffer())
	{
		for (const auto [imguiKey, zepKey] : s_zepSpecialKeyMap)
		{
			if (ImGui::IsKeyPressed(imguiKey))
			{
				pBuffer->GetMode()->AddKeyPress(zepKey, mod);
				return;
			}
		}

		if (io.KeyCtrl)
		{
			for (const auto [imguiKey, zepKey] : s_zepPrintableKeyMap)
			{
				if (ImGui::IsKeyPressed(imguiKey))
				{
					pBuffer->GetMode()->AddKeyPress(zepKey, mod);
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

				pBuffer->GetMode()->AddKeyPress(io.InputQueueCharacters[n], mod);
			}
		}
	}
}

//----------------------------------------------------------------------------

struct ImGuiZepEditor::EventReceiver : Zep::IZepComponent
{
	ImGuiZepEditor* m_editor = nullptr;

	EventReceiver(ImGuiZepEditor* editor)
		: m_editor(editor)
	{
	}

	void Notify(std::shared_ptr<ZepMessage> message) override
	{
		m_editor->Notify(message);
	}

	void DispatchMouseEvent(std::shared_ptr<ZepMessage> message) override
	{
		m_editor->DispatchMouseEvent(message);
	}

	ZepEditor& GetEditor() const override
	{
		return m_editor->m_editor->GetEditor();
	}
};


ImGuiZepEditor::ImGuiZepEditor(std::string_view id /* = "" */)
	: m_id(id)
{
	m_editor = new ZepEditor_ImGui(ZepPath(), ZepEditorFlags::DisableThreads);
	m_eventReceiver = std::make_unique<EventReceiver>(this);
	m_editor->RegisterCallback(m_eventReceiver.get());
	m_editor->SetGlobalMode(ZepMode_Standard::StaticName());

	EditorConfig& config = m_editor->GetConfig();
	config.showLineNumbers = true;
	config.style = Zep::EditorStyle::Normal;
	config.autoHideCommandRegion = true;
	m_editor->GetTheme().SetThemeType(Zep::ThemeType::VSCodeDefault);

	// Create default tab/window
	m_editor->EnsureTab();

	m_window = m_editor->GetActiveWindow();
	SetWindowFlags(Zep::WindowFlags::WrapText | Zep::WindowFlags::ShowLineNumbers | Zep::WindowFlags::ShowIndicators);
}

ImGuiZepEditor::~ImGuiZepEditor()
{
	m_editor->UnRegisterCallback(m_eventReceiver.get());
	delete m_editor;
}

void ImGuiZepEditor::Notify(const std::shared_ptr<Zep::ZepMessage>& message)
{
	if (message->messageId == Zep::Msg::GetClipBoard)
	{
		if (const char* clipboard = ImGui::GetClipboardText())
		{
			// In-place Replace \r\n line endings with \n as this is what Zep expects.
			std::string text = clipboard;

			int found = 0;
			for (size_t src = 0, dst = 0; src < text.length(); ++src, ++dst)
			{
				if (src < text.length() - 1)
				{
					if (text[src] == '\r' && text[src + 1] == '\n')
					{
						src++;
						found++;
					}
				}

				if (src != dst)
					text[dst] = text[src];
			}

			if (found > 0)
				text.resize(text.length() - found);

			message->str = std::move(text);
		}
		else
		{
			message->str = "";
		}

		message->handled = true;
	}
	else if (message->messageId == Zep::Msg::SetClipBoard)
	{
		ImGui::SetClipboardText(message->str.c_str());
		message->handled = true;
	}
}

void ImGuiZepEditor::DispatchMouseEvent(const std::shared_ptr<Zep::ZepMessage>& message)
{
}

void ImGuiZepEditor::SetFont(Zep::ZepTextType type, ImFont* pFont, int fontSize)
{
	m_editor->SetFont(type, std::make_shared<ZepFont_ImGui>(*m_editor, pFont, fontSize));
}

ZepEditor& ImGuiZepEditor::GetEditor() const
{
	return *m_editor;
}

std::shared_ptr<Zep::ZepBuffer> ImGuiZepEditor::CreateFileBuffer(std::string_view file)
{
	ZepBuffer* pBuffer = m_editor->GetFileBuffer(file, 0, true);

	// Replace the default buffer if it is still present.
	ZepTabWindow* pTabs = m_editor->EnsureTab();
	if (ZepWindow* pDefaultWindow = pTabs->GetDefaultWindow())
	{
		auto oldBuffer = pDefaultWindow->GetBuffer().shared_from_this();
		pDefaultWindow->SetBuffer(pBuffer);

		RemoveBuffer(oldBuffer);
	}
	
	return pBuffer->shared_from_this();
}

std::shared_ptr<Zep::ZepBuffer> ImGuiZepEditor::CreateBuffer(std::string_view name, std::string_view text)
{
	ZepBuffer* pBuffer = m_editor->GetEmptyBuffer(name);
	if (!text.empty())
	{
		pBuffer->SetText(text, true);
	}

	// Replace the default buffer if it is still present.
	ZepTabWindow* pTabs = m_editor->EnsureTab();
	if (ZepWindow* pDefaultWindow = pTabs->GetDefaultWindow())
	{
		auto oldBuffer = pDefaultWindow->GetBuffer().shared_from_this();
		pDefaultWindow->SetBuffer(pBuffer);

		RemoveBuffer(oldBuffer);
	}
	
	return pBuffer->shared_from_this();
}

Zep::GlyphIterator ImGuiZepEditor::Begin() const
{
	if (ZepBuffer* pBuffer = m_editor->GetActiveBuffer())
	{
		return pBuffer->Begin();
	}
	
	return GlyphIterator();
}

Zep::GlyphIterator ImGuiZepEditor::End() const
{
	if (ZepBuffer* pBuffer = m_editor->GetActiveBuffer())
	{
		return pBuffer->End();
	}

	return GlyphIterator();
}

std::shared_ptr<Zep::ZepBuffer> ImGuiZepEditor::GetActiveBuffer() const
{
	if (ZepBuffer* pBuffer = m_editor->GetActiveBuffer())
	{
		return pBuffer->shared_from_this();
	}

	return nullptr;
}

void ImGuiZepEditor::SetActiveBuffer(const std::shared_ptr<Zep::ZepBuffer>& buffer)
{
	if (buffer)
	{
		m_editor->EnsureWindow(buffer.get());
	}
}

bool ImGuiZepEditor::RemoveBuffer(const std::shared_ptr<Zep::ZepBuffer>& buffer)
{
	// Cannot remove the last buffer
	auto& buffers = m_editor->GetBuffers();
	if (buffers.size() == 1 && buffers[0] == buffer)
		return false;

	// Passed by raw pointer. Assumes that this buffer is already owned by this editor.
	m_editor->RemoveBuffer(buffer.get());

	buffer->Clear();
	return true;
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

		ImGui::PushItemFlag(ImGuiItemFlags_NoTabStop, false);

		m_editor->SetHasFocus(ImGui::IsWindowFocused());
		if (ImGui::IsWindowFocused())
		{
			io.WantCaptureKeyboard = true;
			io.WantTextInput = true;
		}
		m_editor->Display();

		ImGui::PopItemFlag();
	}

	ImGui::EndChild();
}

void ImGuiZepEditor::SetWindowFlags(uint32_t flags)
{
	if (m_wordWrap)
		flags |= Zep::WindowFlags::WrapText;

	m_window->SetWindowFlags(flags);
}

uint32_t ImGuiZepEditor::GetWindowFlags() const
{
	return m_window->GetWindowFlags();
}

void ImGuiZepEditor::ToggleFlag(uint32_t flag)
{
	if (!m_wordWrap)
		flag &= ~Zep::WindowFlags::WrapText;

	m_window->ToggleFlag(flag);
}

} // namespace mq
