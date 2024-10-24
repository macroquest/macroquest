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
#include "ImGuiZepConsole.h"
#include "imgui/ImGuiUtils.h"

#include "zep/display.h"
#include "zep/editor.h"
#include "zep/mode.h"
#include "zep/mode_standard.h"
#include "zep/tab_window.h"

#include <imgui.h>
#include <imgui_internal.h>

using namespace Zep;

namespace mq {

//============================================================================


//============================================================================

ImGuiZepConsoleTheme::ImGuiZepConsoleTheme()
{
}

ImGuiZepConsoleTheme::~ImGuiZepConsoleTheme()
{
}

Zep::ZepColor ImGuiZepConsoleTheme::GetColor(Zep::ThemeColor themeColor) const
{
	Zep::ZepColor finalColor;

	if (static_cast<int>(themeColor) >= UserColorStart)
		finalColor = m_userColors[static_cast<size_t>(themeColor) - UserColorStart];
	else if (themeColor == Zep::ThemeColor::Background)
		finalColor = Zep::ZepColor(0, 0, 0, 0);
	else if (themeColor == Zep::ThemeColor::VisualSelectBackground)
		finalColor = Zep::ZepColor(66, 150, 249, 89);
	else
		finalColor = Zep::ZepTheme::GetColor(themeColor);

	// apply user alpha
	finalColor.a = static_cast<uint8_t>(finalColor.a * m_opacity);

	return finalColor;
}

Zep::ThemeColor ImGuiZepConsoleTheme::GetUserColor(Zep::ZepColor color)
{
	uint32_t id = color.ABGR;
	if (id < static_cast<int>(Zep::ThemeColor::UniqueColorLast) - static_cast<int>(Zep::ThemeColor::UniqueColor0))
		return Zep::ZepTheme::GetUniqueColor(id);

	auto iter = std::find(std::begin(m_userColors), std::end(m_userColors), color);
	if (iter == std::end(m_userColors))
	{
		m_userColors.emplace_back(id);
		return static_cast<Zep::ThemeColor>(m_userColors.size() - 1 + UserColorStart);
	}

	int index = static_cast<int>(std::distance(std::begin(m_userColors), iter));
	return static_cast<Zep::ThemeColor>(index + UserColorStart);
}

//============================================================================

ImGuiZepConsoleSyntax::ImGuiZepConsoleSyntax(Zep::ZepBuffer& buffer,
	const std::shared_ptr<ImGuiZepConsoleTheme>& theme, Zep::ZepWindow* window)
	: Zep::ZepSyntax(buffer)
	, m_theme(theme)
{
	SetWindow(window);
}

ImGuiZepConsoleSyntax::~ImGuiZepConsoleSyntax()
{
}

void ImGuiZepConsoleSyntax::SetWindow(Zep::ZepWindow* window)
{
	onMouseCursorChanged = window->sigMouseCursorChanged.connect(
		[=](Zep::ZepBuffer& buffer, const Zep::GlyphIterator& mousePos)
		{
			if (&buffer != &m_buffer)
				return;
			UpdateMouseCursor(mousePos);
		});
}

Zep::SyntaxResult ImGuiZepConsoleSyntax::GetSyntaxAt(const Zep::GlyphIterator& offset) const
{
	Zep::SyntaxResult result{};

	if (m_latestPosition < offset.Index() || (long)m_syntax.size() <= offset.Index())
	{
		return result;
	}

	const SyntaxData& syntaxData = m_syntax[offset.Index()];

	if (syntaxData.hyperlinkId)
	{
		result.foreground = GetHyperlinkColor(syntaxData.hyperlinkId, m_hoveredHyperlink == syntaxData.hyperlinkId);
	}
	else
	{
		result.foreground = syntaxData.foreground;
	}

	return result;
}

void ImGuiZepConsoleSyntax::Notify(std::shared_ptr<Zep::ZepMessage> msg)
{
	if (msg->messageId == Zep::Msg::Buffer)
	{
		auto spBufferMsg = std::static_pointer_cast<Zep::BufferMessage>(msg);
		if (spBufferMsg->pBuffer != &m_buffer)
		{
			return;
		}

		if (spBufferMsg->type == Zep::BufferMessageType::PreBufferChange)
		{
		}
		else if (spBufferMsg->type == Zep::BufferMessageType::TextDeleted)
		{
			// Remove any hyperlinks in deleted text.
			for (int pos = spBufferMsg->startLocation.Index(); pos != spBufferMsg->endLocation.Index(); ++pos)
			{
				if (m_syntax[pos].hyperlinkId != 0)
				{
					RemoveHyperlink(m_syntax[pos].hyperlinkId);
				}
			}

			m_syntax.erase(m_syntax.begin() + spBufferMsg->startLocation.Index(),
				m_syntax.begin() + spBufferMsg->endLocation.Index());

			m_latestPosition -= (spBufferMsg->endLocation.Index() - spBufferMsg->endLocation.Index());
		}
		else if (spBufferMsg->type == Zep::BufferMessageType::TextAdded
			|| spBufferMsg->type == Zep::BufferMessageType::Loaded)
		{
			auto dist = Zep::ByteDistance(spBufferMsg->startLocation, spBufferMsg->endLocation);
			m_syntax.insert(m_syntax.begin() + spBufferMsg->startLocation.Index(), dist, SyntaxData{});

			// Fill in syntax data from attributes.
			for (const ZepBufferAttribute& attribute : m_pendingAttributes)
			{
				if (attribute.attribute.type == ZepAttribute::Type::Color)
				{
					uint32_t color = std::get<(int)ZepAttribute::Type::Color>(attribute.attribute.data).color;
					Zep::ThemeColor themeColor = m_theme->GetUserColor(color);

					Zep::GlyphRange range = { attribute.start + attribute.startIndex, attribute.start + attribute.endIndex };
					for (Zep::GlyphIterator iter = range.first; iter != range.second; iter++)
					{
						m_syntax[iter.Index()].foreground = themeColor;
					}
				}

				if (attribute.attribute.type == ZepAttribute::Type::Hyperlink)
				{
					auto& hyperlinkData = std::get<(int)ZepAttribute::Type::Hyperlink>(attribute.attribute.data);
					uint32_t hyperlinkId = MakeHyperlink(hyperlinkData);

					Zep::GlyphRange range = { attribute.start + attribute.startIndex, attribute.start + attribute.endIndex };
					for (Zep::GlyphIterator iter = range.first; iter != range.second; iter++)
					{
						m_syntax[iter.Index()].hyperlinkId = hyperlinkId;
					}
				}
			}
			m_pendingAttributes.clear();
			m_latestPosition += (spBufferMsg->endLocation.Index() - spBufferMsg->startLocation.Index());
		}
		else if (spBufferMsg->type == Zep::BufferMessageType::TextChanged)
		{
			auto dist = Zep::ByteDistance(spBufferMsg->startLocation, spBufferMsg->endLocation);

			// Just clear syntax data. Changed text has no new attributes.
			std::fill_n(m_syntax.begin() + spBufferMsg->startLocation.Index(), dist, SyntaxData{});
		}
	}
}

void ImGuiZepConsoleSyntax::DispatchMouseEvent(std::shared_ptr<Zep::ZepMessage> message)
{
	if (message->messageId == Zep::Msg::MouseDown
		&& m_hoveredHyperlink != 0)
	{
		auto hyperlinkMsg = std::make_shared<Zep::ZepMessage>(Zep::Msg::HyperlinkClick, m_hyperlinkData[m_hoveredHyperlink].linkData);
		hyperlinkMsg->clicks = m_hoveredHyperlink;  // Overload the "clicks" field to send the id of the hyperlink.
		hyperlinkMsg->modifiers = message->modifiers;
		hyperlinkMsg->button = message->button;

		GetEditor().Broadcast(hyperlinkMsg);
		message->handled = true;
	}
	else if (message->messageId == Zep::Msg::MouseMove
		&& message->button == Zep::ZepMouseButton::Left)
	{
		// Don't drag from links.
		message->handled = true;
	}
}

void ImGuiZepConsoleSyntax::UpdateMouseCursor(const Zep::GlyphIterator& offset)
{
	m_hoveredHyperlink = 0;

	if (m_latestPosition < offset.Index() || (long)m_syntax.size() <= offset.Index())
	{
		return;
	}

	if (offset.Valid())
	{
		m_hoveredHyperlink = m_syntax[offset.Index()].hyperlinkId;
	}
}

Zep::ThemeColor ImGuiZepConsoleSyntax::GetHyperlinkColor(uint32_t linkId, bool hovered) const
{
	// Get the color tied to this hyperlink.
	auto iter = m_hyperlinkData.find(linkId);
	if (iter != m_hyperlinkData.end())
	{
		return m_theme->GetUserColor(hovered ? iter->second.hoverColor : iter->second.color);
	}

	return m_theme->GetUserColor(hovered ? s_defaultLinkColorHover : s_defaultLinkColor);
}

uint32_t ImGuiZepConsoleSyntax::MakeHyperlink(const ZepAttribute::HyperlinkAttributeData& hyperlinkData)
{
	uint32_t hyperlinkId = m_nextHyperlinkId++;
	m_hyperlinkData[hyperlinkId] = hyperlinkData;
	return hyperlinkId;
}

void ImGuiZepConsoleSyntax::RemoveHyperlink(uint32_t hyperlinkId)
{
	m_hyperlinkData.erase(hyperlinkId);
	m_hoveredHyperlink = 0;
}

void ImGuiZepConsoleSyntax::AddAttribute(const Zep::GlyphIterator& position, ZepTextAttribute attr)
{
	ZepBufferAttribute& buffAttr = m_pendingAttributes.emplace_back();
	buffAttr.start = position;
	buffAttr.startIndex = attr.startIndex;
	buffAttr.endIndex = attr.endIndex;
	buffAttr.attribute = std::move(attr.attribute);
}

//============================================================================

static constexpr unsigned int str_to_hex(char const* p, char const* e) noexcept
{
	unsigned int result = 0;
	while (p != e)
	{
		result *= 16;
		if ('0' <= *p && *p <= '9') { result += *p - '0'; p++; continue; }
		if ('A' <= *p && *p <= 'F') { result += *p + 10 - 'A'; p++; continue; }
		if ('a' <= *p && *p <= 'f') { result += *p + 10 - 'a'; p++; continue; }
		return -1;
	}

	return result;
}
static constexpr ImU32 str_to_col(std::string_view str)
{
	if (str.length() != 7 || str[0] != '#') { return 0; }

	auto r = str_to_hex(str.data() + 1, str.data() + 3);
	auto g = str_to_hex(str.data() + 3, str.data() + 5);
	auto b = str_to_hex(str.data() + 5, str.data() + 7);

	return IM_COL32(r, g, b, 255);
}

static std::pair<std::string_view, ImU32> ParseColorTags(std::string_view line, std::vector<ImU32>& colorStack,
	ImU32 defaultColor)
{
	size_t length = line.length();
	const char* pos = line.data();
	const char* end = line.data() + length;

	ImU32 color = defaultColor;

	// skip over the \a
	if (*(pos++) != '\a')
		return { {}, color };

	if (pos == end) return { {}, color };

	bool dark = false;

	// clear
	if (*pos == 'x')
	{
		pos++;

		if (!colorStack.empty())
		{
			colorStack.pop_back();
		}

		if (!colorStack.empty())
		{
			color = colorStack.back();
		}
		else
		{
			color = defaultColor;
		}

		return { std::string_view{ pos, (size_t)(end - pos) }, color };
	}

	// custom color
	if (*pos == '#')
	{
		// we need 7 to do anything (6 for hex code and 1 for #)
		if (end - pos < 7) return { {}, color };
		std::string_view colorCode{ pos, 7 };

		// convert hex to color
		color = str_to_col(colorCode);
		colorStack.push_back(color);

		pos += 7;
		return { std::string_view{ pos, (size_t)(end - pos) }, color };
	}

	// darken
	if (*pos == '-')
	{
		dark = true;
		pos++;

		if (pos == end) return { {}, color };
	}

	switch (*pos)
	{
	case 'y': // yellow (green/red)
		if (dark)
			color = 0xff009999;
		else
			color = 0xff00ffff;
		break;
	case 'o': // orange (green/red)
		if (dark)
			color = 0xff006699;
		else
			color = 0xff0099ff;
		break;
	case 'g': // green   (green)
		if (dark)
			color = 0xff009900;
		else
			color = 0xff00ff00;
		break;
	case 'u': // blue   (blue)
		if (dark)
			color = 0xff990000;
		else
			color = 0xffff0000;
		break;
	case 'r': // red     (red)
		if (dark)
			color = 0xff000099;
		else
			color = 0xff0000ff;
		break;
	case 't': // teal (blue/green)
		if (dark)
			color = 0xff999900;
		else
			color = 0xffffff00;
		break;
	case 'b': // black   (none)
		color = 0xff000000;
		break;
	case 'm': // magenta (blue/red)
		if (dark)
			color = 0xff990099;
		else
			color = 0xffff00ff;
		break;
	case 'p': // purple (blue/red)
		if (dark)
			color = 0xff990066;
		else
			color = 0xffff0099;
		break;
	case 'w': // white   (all)
		if (dark)
			color = 0xff999999;
		else
			color = 0xffffffff;
		break;
	}
	pos++;
	colorStack.push_back(color);

	return { { pos, (size_t)(end - pos) }, color };
}

//============================================================================

class ZepMode_ImGuiConsole : public Zep::ZepMode_Standard
{
public:
	using ZepMode_Standard::ZepMode_Standard;

	virtual Zep::CursorType GetCursorType() const override { return Zep::CursorType::None; }

	static const char* StaticName()
	{
		return "Console";
	}

	virtual const char* Name() const override
	{
		return StaticName();
	}
};

//============================================================================

ImGuiZepConsole::ImGuiZepConsole(std::string_view id)
	: ImGuiZepEditor(id)
{
	auto& editor = GetEditor();

	editor.RegisterGlobalMode(std::make_shared<ZepMode_ImGuiConsole>(editor));
	editor.SetGlobalMode(ZepMode_ImGuiConsole::StaticName());

	m_window = editor.GetActiveTabWindow()->GetActiveWindow();
	m_window->SetWindowFlags(Zep::WindowFlags::WrapText);
	m_theme = std::make_shared<ImGuiZepConsoleTheme>();
	editor.SetTheme(m_theme);

	editor.GetConfig().style = Zep::EditorStyle::Minimal;

	editor.RegisterSyntaxFactory(
		{ "Console" },
		Zep::SyntaxProvider{
			"Console",
			Zep::tSyntaxFactory([this](Zep::ZepBuffer* buffer) {
				return std::make_shared<ImGuiZepConsoleSyntax>(*buffer, m_theme, m_window);
			})
		});

	m_buffer = editor.InitWithText("Console", "");
	m_buffer->SetTheme(m_theme);
	m_window->SetBufferCursor(m_buffer->End());
	m_window->ToggleFlag(Zep::WindowFlags::HideTrailingNewline);
	m_buffer->SetFileFlags(Zep::FileFlags::ReadOnly | Zep::FileFlags::CrudeUtf8Vaidate);
}

ImGuiZepConsole::~ImGuiZepConsole()
{
}

void ImGuiZepConsole::SetDelegate(std::shared_ptr<ImGuiZepConsoleDelegate> delegate)
{
	m_delegate = std::move(delegate);
}

void ImGuiZepConsole::Render(const ImVec2& displaySize)
{
	if (m_deferredCursorToEnd)
	{
		m_deferredCursorToEnd = false;
		m_window->ScrollToBottom();
	}

	ImGuiZepEditor::Render(displaySize);
}

Zep::GlyphIterator ImGuiZepConsole::InsertText(Zep::GlyphIterator position, std::string_view text, ImU32 color)
{
	if (color != -1)
	{
		ZepTextAttribute attribute;
		attribute.startIndex = 0;
		attribute.endIndex = static_cast<int>(text.length());
		attribute.attribute.type = ZepAttribute::Type::Color;
		attribute.attribute.data = ZepAttribute::ColorAttributeData{ color };

		ImGuiZepConsoleSyntax* syntax = static_cast<ImGuiZepConsoleSyntax*>(m_buffer->GetSyntax());
		syntax->AddAttribute(position, std::move(attribute));
	}

	Zep::ChangeRecord changeRecord;
	m_buffer->Insert(position, text, changeRecord);

	return position.Move(static_cast<long>(text.length()));
}

Zep::GlyphIterator ImGuiZepConsole::InsertHyperlink(Zep::GlyphIterator position, std::string_view text,
	std::string hyperlinkData, uint32_t color, uint32_t hoverColor)
{
	ZepTextAttribute attribute;
	attribute.startIndex = 0;
	attribute.endIndex = static_cast<int>(text.length());
	attribute.attribute.type = ZepAttribute::Type::Hyperlink;
	attribute.attribute.data = ZepAttribute::HyperlinkAttributeData{ std::move(hyperlinkData), color, hoverColor };

	ImGuiZepConsoleSyntax* syntax = static_cast<ImGuiZepConsoleSyntax*>(m_buffer->GetSyntax());
	syntax->AddAttribute(position, std::move(attribute));

	Zep::ChangeRecord changeRecord;
	m_buffer->Insert(position, text, changeRecord);

	return position.Move(static_cast<long>(text.length()));
}

void ImGuiZepConsole::Notify(const std::shared_ptr<Zep::ZepMessage>& message)
{
	if (message->messageId == Zep::Msg::HyperlinkClick)
	{
		if (m_delegate)
		{
			m_delegate->OnHyperlinkClicked(this, message->button, message->modifiers, message->str, message->clicks);
		}
	}
	else
	{
		ImGuiZepEditor::Notify(message);
	}
}

void ImGuiZepConsole::AppendText(std::string_view text, MQColor defaultColor, bool appendNewLine)
{
	Zep::GlyphIterator cursor = m_window->GetBufferCursor();
	bool cursorAtEnd = m_window->IsAtBottom();

	std::string_view lineView = text;
	ImU32 currentColor = defaultColor.ToImU32();

	std::vector<ImU32> colorStack;

	while (!lineView.empty())
	{
		auto colorPos = lineView.find("\a");

		// this is everything before the color code.
		auto beforeColor = lineView.substr(0, colorPos);
		if (!beforeColor.empty())
		{
			InsertFormattedText(m_buffer->End(), beforeColor, currentColor);
		}

		// did we find a color?
		if (colorPos == std::string_view::npos)
			break;

		lineView = lineView.substr(colorPos);

		auto [nextSegment, nextColor] = ParseColorTags(lineView, colorStack, defaultColor.ToImU32());
		// Parse the color and get the next segment. We pass in the
		// default color to handle \ax properly

		if (nextSegment.empty())
			break;

		currentColor = nextColor;
		lineView = nextSegment;
	}

	if (appendNewLine)
		InsertText(m_buffer->End(), "\n");

	PruneBuffer();

	if (cursorAtEnd)
	{
		TriggerAutoScroll();
	}
}

void ImGuiZepConsole::Clear()
{
	m_buffer->Clear();
}

bool ImGuiZepConsole::IsCursorAtEnd() const
{
	return m_window->IsAtBottom();
}

void ImGuiZepConsole::PruneBuffer()
{
	int lineCount = m_buffer->GetLineCount();
	if (lineCount > m_maxBufferLines + 1)
	{
		int linesToDelete = lineCount - (m_maxBufferLines + 1);

		Zep::ByteRange range;
		if (m_buffer->GetLineOffsets(linesToDelete, range))
		{
			Zep::GlyphIterator end(m_buffer, range.first);

			Zep::ChangeRecord changeRecord;
			m_buffer->Delete(m_buffer->Begin(), end, changeRecord);
		}
	}
}

float ImGuiZepConsole::GetOpacity() const
{
	return m_theme->GetOpacity();
}

void ImGuiZepConsole::SetOpacity(float opacity)
{
	m_theme->SetOpacity(opacity);
}


void ImGuiZepConsole::InsertFormattedText(Zep::GlyphIterator position, std::string_view text, ImU32 color)
{
	if (!m_delegate || !m_delegate->OnInsertFormattedText(this, position, text, color))
	{
		InsertText(position, text, color);
	}
}



//============================================================================
} // namespace mq
