/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

#include "pch.h"

#include "MQ2DeveloperTools.h"
#include "MQ2ImGuiTools.h"
#include "MQ2Utilities.h"

#include "imgui/ImGuiTreePanelWindow.h"
#include "imgui/ImGuiTextEditor.h"
#include <imgui/imgui_internal.h>

#include "zep.h"

namespace mq {

//----------------------------------------------------------------------------

extern bool gbToggleConsoleRequested;

static const ImU32 s_defaultColor = IM_COL32(0xf0, 0xf0, 0xf0, 255);
static ImGuiID s_dockspaceId = 0;

static bool s_dockspaceVisible = false;
static bool s_resetDockspace = false;
static bool s_setFocus = false;

constexpr const bool s_useZepConsole = true;

class ImGuiConsole;
ImGuiConsole* gImGuiConsole = nullptr;

const mq::imgui::texteditor::Palette& GetColorPalette()
{
	const static mq::imgui::texteditor::Palette p = { {
			0xffffffff, // Default
			0xffffffff, // Keyword
			0xffffffff, // Number
			0xffffffff, // String
			0xffffffff, // Char literal
			0xffffffff, // Punctuation
			0xffffffff, // Preprocessor
			0xffffffff, // Identifier
			0xffffffff, // Known identifier
			0xffffffff, // Preproc identifier
			0xffffffff, // Comment (single line)
			0xffffffff, // Comment (multi line)
			0x00000000, // Background
			0xffe0e0e0, // Cursor
			0x80a06020, // Selection
			0x800020ff, // ErrorMarker
			0x40f08000, // Breakpoint
			0xff707000, // Line number
			0x40000000, // Current line fill
			0x40808080, // Current line fill (inactive)
			0x40a0a0a0, // Current line edge
		} };
	return p;
}

static void Strtrim(char* str)
{
	char* str_end = str + strlen(str);
	while (str_end > str && str_end[-1] == ' ')
		str_end--;
	*str_end = 0;
}

unsigned int str_to_hex(char const* p, char const* e) noexcept
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

ImU32 str_to_col(std::string_view str)
{
	if (str.length() != 7 || str[0] != '#') { return 0; }

	auto r = str_to_hex(str.data() + 1, str.data() + 3);
	auto g = str_to_hex(str.data() + 3, str.data() + 5);
	auto b = str_to_hex(str.data() + 5, str.data() + 7);

	return IM_COL32(r, g, b, 255);
}

static void MakeColorGradient(float frequency1, float frequency2, float frequency3,
	float phase1, float phase2, float phase3,
	float center = 128, float width = 127, int length = 50);

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
			color = s_defaultColor;
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

#pragma region Zep Integration

// This theme extends the default theme to support arbitrary coloring via extended
// UserColor values of the ThemeColor enum.
class ZepConsoleTheme : public Zep::ZepTheme
{
	static inline constexpr int UserColorStart = (int)Zep::ThemeColor::UniqueColorLast + 1;

public:
	ZepConsoleTheme()
	{
	}

	virtual Zep::ZepColor GetColor(Zep::ThemeColor themeColor) const
	{
		if ((int)themeColor >= UserColorStart)
			return m_userColors[(size_t)themeColor - UserColorStart];

		if (themeColor == Zep::ThemeColor::Background)
			return Zep::ZepColor(0, 0, 0, 0);
		if (themeColor == Zep::ThemeColor::VisualSelectBackground)
			return Zep::ZepColor(0, 0, 128, 128);

		return Zep::ZepTheme::GetColor(themeColor);
	}

	// This overrides GetUniqueColor to treat any value over UniqueColorLast as an MQColor value.
	// It will be inserted into the user color map and the index + UserColorStart will be returned.
	Zep::ThemeColor GetUserColor(Zep::ZepColor color)
	{
		uint32_t id = color.ABGR;
		if (id < (int)Zep::ThemeColor::UniqueColorLast - (int)Zep::ThemeColor::UniqueColor0)
			return Zep::ZepTheme::GetUniqueColor(id);

		auto iter = std::find(std::begin(m_userColors), std::end(m_userColors), color);
		if (iter == std::end(m_userColors))
		{
			m_userColors.emplace_back(id);
			return (Zep::ThemeColor)(m_userColors.size() - 1 + UserColorStart);
		}

		int index = std::distance(std::begin(m_userColors), iter);
		return (Zep::ThemeColor)(index + UserColorStart);
	}

	Zep::ThemeColor GetHyperlinkColor(bool hovered)
	{
		if (hovered)
			return GetUserColor(Zep::ZepColor(255, 255, 0));
		else
			return GetUserColor(Zep::ZepColor(255, 0, 255));
	}

private:
	std::vector<Zep::ZepColor> m_userColors;
};

//----------------------------------------------------------------------------

enum class ZepAttributeType
{
	Color,
	Hyperlink,
};

struct ZepAttribute
{
	struct ColorAttributeData
	{
		uint32_t color;
	};

	struct HyperlinkAttributeData
	{
		std::string linkData;
	};

	using ZepAttributeData = std::variant<ColorAttributeData, HyperlinkAttributeData>;

	ZepAttributeType type;
	ZepAttributeData data;

	ZepAttribute(ZepAttributeType type, ZepAttributeData data)
		: type(type)
		, data(std::move(data))
	{
	}

	ZepAttribute() = default;
};

struct ZepTextAttribute
{
	int startIndex;
	int endIndex;
	ZepAttribute attribute;
};

struct ZepBufferAttribute
{
	Zep::GlyphIterator start;
	int startIndex;
	int endIndex;
	ZepAttribute attribute;
};

using ZepAttributes = std::vector<ZepBufferAttribute>;

// This custom syntax makes use of ranged-based "attributes" that annotate the text to produce
// colorization and hyperlinks for the editor.
class ZepConsoleSyntax : public Zep::ZepSyntax
{
public:
	ZepConsoleSyntax(Zep::ZepBuffer& buffer, const std::shared_ptr<ZepConsoleTheme>& theme, Zep::ZepWindow* window)
		: Zep::ZepSyntax(buffer)
		, m_theme(theme)
	{
		SetWindow(window);
	}

	void SetWindow(Zep::ZepWindow* window)
	{
		onMouseCursorChanged = window->sigMouseCursorChanged.connect(
			[=](Zep::ZepBuffer& buffer, const Zep::GlyphIterator& mousePos)
			{
				if (&buffer != &m_buffer)
					return;
				UpdateMouseCursor(mousePos);
			});
	}

	struct SyntaxData
	{
		Zep::ThemeColor foreground = Zep::ThemeColor::Normal;
		uint32_t hyperlinkId = 0;
	};

	Zep::SyntaxResult GetSyntaxAt(const Zep::GlyphIterator& offset) const
	{
		Zep::SyntaxResult result{};

		if (m_latestPosition < offset.Index() || (long)m_syntax.size() <= offset.Index())
		{
			return result;
		}

		const SyntaxData& syntaxData = m_syntax[offset.Index()];

		if (syntaxData.hyperlinkId)
		{
			result.foreground = m_theme->GetHyperlinkColor(m_hoveredHyperlink == syntaxData.hyperlinkId);
		}
		else
		{
			result.foreground = syntaxData.foreground;
		}

		return result;
	}

	void Notify(std::shared_ptr<Zep::ZepMessage> spMsg)
	{
		if (spMsg->messageId == Zep::Msg::MouseDown
			&& m_hoveredHyperlink != 0)
		{
			if ((spMsg->modifiers & Zep::ModifierKey::Ctrl)
				&& spMsg->button == Zep::ZepMouseButton::Left)
			{
				std::string text = fmt::format("Clicked hyperlink: {}\n", m_hyperlinkData[m_hoveredHyperlink]);

				Zep::ChangeRecord changeRecord;
				m_buffer.Insert(m_buffer.End(), text, changeRecord);
			}
		}

		if (spMsg->messageId == Zep::Msg::Buffer)
		{
			auto spBufferMsg = std::static_pointer_cast<Zep::BufferMessage>(spMsg);
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
					if (attribute.attribute.type == ZepAttributeType::Color)
					{
						uint32_t color = std::get<(int)ZepAttributeType::Color>(attribute.attribute.data).color;
						Zep::ThemeColor themeColor = m_theme->GetUserColor(color);

						Zep::GlyphRange range = { attribute.start + attribute.startIndex, attribute.start + attribute.endIndex };
						for (Zep::GlyphIterator iter = range.first; iter != range.second; iter++)
						{
							m_syntax[iter.Index()].foreground = themeColor;
						}
					}

					if (attribute.attribute.type == ZepAttributeType::Hyperlink)
					{
						uint32_t hyperlinkId = MakeHyperlink(std::get<(int)ZepAttributeType::Hyperlink>(attribute.attribute.data).linkData);

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

	void AddAttribute(const Zep::GlyphIterator& position, ZepTextAttribute attr)
	{
		ZepBufferAttribute& buffAttr = m_pendingAttributes.emplace_back();
		buffAttr.start = position;
		buffAttr.startIndex = attr.startIndex;
		buffAttr.endIndex = attr.endIndex;
		buffAttr.attribute = std::move(attr.attribute);
	}

	uint32_t MakeHyperlink(const std::string& hyperlinkData)
	{
		uint32_t hyperlinkId = m_nextHyperlinkId++;
		m_hyperlinkData[hyperlinkId] = hyperlinkData;
		return hyperlinkId;
	}

	void RemoveHyperlink(uint32_t hyperlinkId)
	{
		m_hyperlinkData.erase(hyperlinkId);
		m_hoveredHyperlink = 0;
	}

	void UpdateMouseCursor(const Zep::GlyphIterator& offset)
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

private:
	std::vector<SyntaxData> m_syntax;
	std::shared_ptr<ZepConsoleTheme> m_theme;
	std::vector<ZepBufferAttribute> m_pendingAttributes;
	uint32_t m_nextHyperlinkId = 1;
	std::map<uint32_t, std::string> m_hyperlinkData;
	uint32_t m_hoveredHyperlink = 0;
	Zep::scoped_connection onMouseCursorChanged;
	int m_latestPosition = 0;
};

//----------------------------------------------------------------------------

// This is the imgui container for the Zep component.
struct ZepContainerImGui : public Zep::IZepComponent
{
	Zep::ZepBuffer* m_buffer = nullptr;
	Zep::ZepWindow* m_window = nullptr;

	ZepContainerImGui(bool consoleMode, const std::string& filename = "")
	{
		Zep::NVec2f pixelScale = { 1.0f, 1.0f };
		auto display = new Zep::ZepDisplay_ImGui(pixelScale);
		display->SetFont(Zep::ZepTextType::UI, std::make_shared<Zep::ZepFont_ImGui>(*display, mq::imgui::DefaultFont, 16));
		display->SetFont(Zep::ZepTextType::Text, std::make_shared<Zep::ZepFont_ImGui>(*display, mq::imgui::ConsoleFont, 13));
		display->SetFont(Zep::ZepTextType::Heading1, std::make_shared<Zep::ZepFont_ImGui>(*display, mq::imgui::DefaultFont, 28));
		display->SetFont(Zep::ZepTextType::Heading2, std::make_shared<Zep::ZepFont_ImGui>(*display, mq::imgui::DefaultFont, 14));
		display->SetFont(Zep::ZepTextType::Heading3, std::make_shared<Zep::ZepFont_ImGui>(*display, mq::imgui::DefaultFont, 20));

		Zep::ZepEditorParams params;
		params.pDisplay = display;
		params.flags = Zep::ZepEditorFlags::DisableThreads;

		m_editor = std::make_unique<Zep::ZepEditor_ImGui>(params);
		m_editor->RegisterCallback(this);
		m_editor->SetGlobalMode(Zep::ZepMode_Standard::StaticName());

		m_window = m_editor->GetActiveTabWindow()->GetActiveWindow();
		m_theme = std::make_shared<ZepConsoleTheme>();
		m_editor->SetTheme(m_theme);

		if (consoleMode)
		{
			m_editor->GetConfig().style = Zep::EditorStyle::Minimal;
			m_window->SetWindowFlags(Zep::WindowFlags::WrapText);

			m_editor->RegisterSyntaxFactory(
				{ "Console" },
				Zep::SyntaxProvider{ "Console", Zep::tSyntaxFactory([this](Zep::ZepBuffer* pBuffer) {
					return std::make_shared<ZepConsoleSyntax>(*pBuffer, m_theme, m_window);
				})
			});

			m_buffer = m_editor->InitWithText("Console", "");
			m_buffer->SetTheme(m_theme);
			m_window->SetBufferCursor(m_buffer->End());
			m_buffer->SetFileFlags(Zep::FileFlags::ReadOnly);
		}
		else
		{
			m_editor->GetConfig().style = Zep::EditorStyle::Normal;
			m_window->SetWindowFlags(Zep::WindowFlags::None
				| Zep::WindowFlags::ShowWhiteSpace | Zep::WindowFlags::ShowLineNumbers | Zep::WindowFlags::WrapText
				| Zep::WindowFlags::ShowLineBackground
			);

			m_buffer = m_editor->InitWithFileOrDir(filename);
			//m_editor->GetTheme().SetThemeType(Zep::ThemeType::SolarizedLight);
		}
	}

	~ZepContainerImGui()
	{
		Destroy();
	}

	void Destroy()
	{
		if (m_editor)
		{
			m_editor->UnRegisterCallback(this);
			m_editor.reset();
		}
	}

	// Inherited via IZepComponent
	virtual void Notify(std::shared_ptr<Zep::ZepMessage> message) override
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
		else if (message->messageId == Zep::Msg::RequestQuit)
		{
			//quit = true;
		}
		else if (message->messageId == Zep::Msg::ToolTip)
		{
			//auto spTipMsg = std::static_pointer_cast<Zep::ToolTipMessage>(message);
			//if (spTipMsg->location.Valid() && spTipMsg->pBuffer)
			//{
			//	auto pSyntax = spTipMsg->pBuffer->GetSyntax();
			//	if (pSyntax)
			//	{
			//		if (pSyntax->GetSyntaxAt(spTipMsg->location).foreground == Zep::ThemeColor::Identifier)
			//		{
			//			auto spMarker = std::make_shared<Zep::RangeMarker>(*spTipMsg->pBuffer);
			//			spMarker->SetDescription("This is an identifier");
			//			spMarker->SetHighlightColor(Zep::ThemeColor::Identifier);
			//			spMarker->SetTextColor(Zep::ThemeColor::Text);
			//			spTipMsg->spMarker = spMarker;
			//			spTipMsg->handled = true;
			//		}
			//		else if (pSyntax->GetSyntaxAt(spTipMsg->location).foreground == Zep::ThemeColor::Keyword)
			//		{
			//			auto spMarker = std::make_shared<Zep::RangeMarker>(*spTipMsg->pBuffer);
			//			spMarker->SetDescription("This is a keyword");
			//			spMarker->SetHighlightColor(Zep::ThemeColor::Keyword);
			//			spMarker->SetTextColor(Zep::ThemeColor::Text);
			//			spTipMsg->spMarker = spMarker;
			//			spTipMsg->handled = true;
			//		}
			//	}
			//}
		}
	}

	virtual Zep::ZepEditor_ImGui& GetEditor() const override
	{
		return *m_editor;
	}

	void Clear()
	{

	}

	void InsertText(std::string_view text, ImU32 color)
	{
		ZepTextAttribute attribute;
		attribute.startIndex = 0;
		attribute.endIndex = text.length();
		attribute.attribute.type = ZepAttributeType::Color;
		attribute.attribute.data = ZepAttribute::ColorAttributeData{ color };

		// Append to end of buffer
		Zep::GlyphIterator position = m_buffer->End();

		ZepConsoleSyntax* syntax = static_cast<ZepConsoleSyntax*>(m_buffer->GetSyntax());
		syntax->AddAttribute(position, std::move(attribute));

		Zep::ChangeRecord changeRecord;
		m_buffer->Insert(position, text, changeRecord);
	}

	void InsertText(std::string_view text)
	{
		Zep::ChangeRecord changeRecord;
		m_buffer->Insert(m_buffer->End(), text, changeRecord);
	}

	void AddColoredText(std::string_view text, uint32_t defaultColor, bool newline = false)
	{
		Zep::GlyphIterator cursor = m_window->GetBufferCursor();
		bool cursorAtEnd = cursor == m_buffer->End();

		std::string_view lineView = text;
		ImU32 currentColor = defaultColor;

		std::vector<ImU32> colorStack;

		while (!lineView.empty())
		{
			auto colorPos = lineView.find("\a");

			// this is everything before the color code.
			auto beforeColor = lineView.substr(0, colorPos);
			if (!beforeColor.empty())
			{
				// no color codes, write out with current color
				InsertText(beforeColor, currentColor);
			}

			// did we find a color?
			if (colorPos == std::string_view::npos)
				break;

			lineView = lineView.substr(colorPos);

			auto& [nextSegment, nextColor] = ParseColorTags(lineView, colorStack, defaultColor);
			// Parse the color and get the next segment. We pass in the
			// default color to handle \ax properly

			if (nextSegment.empty())
				break;

			currentColor = nextColor;
			lineView = nextSegment;
		}

		if (newline)
			InsertText("\n");

		if (cursorAtEnd)
		{
			m_window->SetBufferCursor(m_buffer->End());
			m_window->ScrollToCursor();
		}
	}

	void DoHyperlinkTest()
	{
		static int hyperlinkNum = 1;
		std::string text = fmt::format("This is hyperlink {}", hyperlinkNum++);

		ZepTextAttribute attribute;
		attribute.startIndex = 0;
		attribute.endIndex = text.length();
		attribute.attribute.type = ZepAttributeType::Hyperlink;
		attribute.attribute.data = ZepAttribute::HyperlinkAttributeData{ text + "'s data" };

		// Append to end of buffer
		Zep::GlyphIterator position = m_buffer->End();

		ZepConsoleSyntax* syntax = static_cast<ZepConsoleSyntax*>(m_buffer->GetSyntax());
		syntax->AddAttribute(position, std::move(attribute));

		Zep::ChangeRecord changeRecord;
		m_buffer->Insert(position, text + "\n", changeRecord);
	}

	void Render(const ImRect& displayRect)
	{
		if (!ImGui::BeginChild("ZepEditor", displayRect.GetSize(), false, ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoBackground))
		{
			ImGui::EndChild();
			return;
		}

		m_editor->SetDisplayRegion(Zep::NVec2f(displayRect.Min.x, displayRect.Min.y),
			Zep::NVec2f(displayRect.Max.x, displayRect.Max.y));

		// Display the editor inside this window
		m_editor->HandleInput();

		ImGui::PushAllowKeyboardFocus(true);
		m_editor->SetHasFocus(ImGui::IsWindowFocused());
		m_editor->Display();

		ImGui::PopAllowKeyboardFocus();

		ImGui::EndChild();
	}

	std::unique_ptr<Zep::ZepEditor_ImGui> m_editor;
	std::shared_ptr<ZepConsoleTheme> m_theme;
	std::shared_ptr<ZepConsoleSyntax> m_syntax;
};

#pragma endregion

//============================================================================

#pragma region ImGui Console

class ImGuiConsole
{
public:
	char m_inputBuffer[2048];
	ImVector<const char*> m_commands;
	std::vector<std::string> m_history;
	int m_historyPos = -1;    // -1: new line, 0..History.Size-1 browsing history.
	bool m_autoScroll = true;
	bool m_scrollToBottom = true;
	std::unique_ptr<mq::imgui::TextEditor> m_imguiEditor;
	std::unique_ptr<ZepContainerImGui> m_zepEditor;

	ImGuiConsole()
	{
		ZeroMemory(m_inputBuffer, lengthof(m_inputBuffer));

		if constexpr (s_useZepConsole)
		{
			m_zepEditor = std::make_unique<ZepContainerImGui>(true);
		}
		else
		{
			m_imguiEditor = std::make_unique<mq::imgui::TextEditor>();
			m_imguiEditor->SetPalette(GetColorPalette());
			m_imguiEditor->SetReadOnly(true);
			m_imguiEditor->SetRenderCursor(false);
			m_imguiEditor->SetShowWhitespace(false);
			m_imguiEditor->SetRenderLineNumbers(false);
			m_imguiEditor->SetLanguageDefinition(mq::imgui::texteditor::LanguageDefinition::PlainText());
			//m_imguiEditor->SetImGuiChildIgnored(true);
		}
	}

	~ImGuiConsole()
	{
		ClearLog();
	}

	void ClearLog()
	{
		if (m_zepEditor)
		{
			m_zepEditor->Clear();
		}
		else
		{
			m_imguiEditor->SetText("");
		}
	}

	template <typename... Args>
	void AddLog(ImU32 color, std::string_view fmt, const Args&... args)
	{
		fmt::basic_memory_buffer<char> buf;
		fmt::format_to(buf, fmt, args...);

		if (m_zepEditor)
		{
			m_zepEditor->AddColoredText(std::string_view(buf.data(), buf.size()), color, false);
		}
		else
		{
			m_imguiEditor->MoveBottom();
			m_imguiEditor->MoveEnd();
			m_imguiEditor->InsertText(std::string_view(buf.data(), buf.size()), color);
		}
	}

	template <typename... Args>
	void AddLog(std::string_view fmt, const Args&... args)
	{
		AddLog(s_defaultColor, std::move(fmt), args...);
	}

	void AddWriteChatColorLog(const char* line, ImU32 defaultColor = s_defaultColor, bool newline = false)
	{
		if (m_zepEditor)
		{
			m_zepEditor->AddColoredText(line, defaultColor, newline);
			return;
		}

		m_imguiEditor->MoveBottom();
		m_imguiEditor->MoveEnd();

		std::string_view lineView{ line };
		ImU32 currentColor = defaultColor;

		std::vector<ImU32> colorStack;

		while (!lineView.empty())
		{
			auto colorPos = lineView.find("\a");

			// this is everything before the color code.
			auto beforeColor = lineView.substr(0, colorPos);
			if (!beforeColor.empty())
			{
				// no color codes, write out with current color
				m_imguiEditor->InsertText(beforeColor, currentColor);
			}

			// did we find a color?
			if (colorPos == std::string_view::npos)
				break;

			lineView = lineView.substr(colorPos);

			auto& [nextSegment, nextColor] = ParseColorTags(lineView, colorStack, defaultColor);
			// Parse the color and get the next segment. We pass in the
			// default color to handle \ax properly

			if (nextSegment.empty())
				break;

			currentColor = nextColor;
			lineView = nextSegment;
		}

		if (newline)
			m_imguiEditor->InsertText("\n");
	}

	void Draw(bool* pOpen)
	{
		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_MenuBar;

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(2, 4));

		if (!ImGui::Begin("MacroQuest Console", pOpen, windowFlags))
		{
			ImGui::End();

			ImGui::PopStyleVar();
			return;
		}

		// Need to unpop this for the menu.
		ImGui::PopStyleVar();

		// As a specific feature guaranteed by the library, after calling Begin() the last Item
		// represent the title bar. So e.g. IsItemHovered() will return true when hovering the title bar.
		// Here we create a context menu only available from the title bar.
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("Options"))
			{
				ImGui::MenuItem("Auto-scroll", nullptr, &m_autoScroll);

				ImGui::Separator();

				if (ImGui::MenuItem("Close Console"))
					*pOpen = false;
				if (ImGui::MenuItem("Reset Position"))
					s_resetDockspace = true;

				ImGui::Separator();

				if (ImGui::MenuItem("Clear Console"))
					ClearLog();

				if (ImGui::BeginMenu("Extras"))
				{
					if (ImGui::MenuItem("Color Test"))
					{
						WriteChatColor("\ayYELLOW    \a-yDARK YELLOW");
						WriteChatColor("\aoORANGE    \a-oDARK ORANGE");
						WriteChatColor("\agGREEN     \a-gDARK GREEN");
						WriteChatColor("\auBLUE      \a-uDARK BLUE");
						WriteChatColor("\arRED       \a-rDARK RED");
						WriteChatColor("\atTEAL      \a-tDARK TEAL");
						WriteChatColor("\abBLACK");
						WriteChatColor("\amMAGENTA   \a-mDARK MAGENTA");
						WriteChatColor("\apPURPLE    \a-pDARK PURPLE");
						WriteChatColor("\awWHITE     \a-wGREY");

						MakeColorGradient(.3f, .3f, .3f, 0, 2, 4);
					}

					if (m_zepEditor)
					{
						if (ImGui::MenuItem("Hyperlink Test"))
						{
							m_zepEditor->DoHyperlinkTest();
						}
					}

					ImGui::EndMenu();
				}
				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Windows"))
			{
				ImGuiTools_DrawWindowsMenu();
				ImGui::EndMenu();
			}

			DeveloperTools_DrawMenu();

			ImGui::EndMenuBar();
		}

		// And put it back ...

		const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing(); // 1 separator, 1 input text

		if (m_zepEditor)
		{
			//ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
			//ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			//ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 0.0f);
			//ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
			//ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 0.0f);
			//ImGui::BeginChild("ZepContainer", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove);
		}
		else
		{
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(2, 4));
			ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar); // Leave room for 1 separator + 1 InputText
		}

		if (m_zepEditor)
		{
			//ImGui::PopStyleVar(5);
		}
		else
		{
			ImGui::PopStyleVar();
		}

		// Right click menu for editor
		if (ImGui::BeginPopupContextWindow())
		{
			if (ImGui::Selectable("Clear")) ClearLog();
			ImGui::EndPopup();
		}

		if (m_zepEditor)
		{
			ImVec2 min = ImGui::GetCursorScreenPos();
			ImVec2 contentSize = ImGui::GetContentRegionMaxAbs();
			contentSize.y -= footer_height_to_reserve;
			ImVec2 max = contentSize;
			max.x = std::max(1.0f, max.x);
			max.y = std::max(1.0f, max.y);

			m_zepEditor->Render(ImRect(min, max));
		}
		else
		{
			ImGui::PushAllowKeyboardFocus(false);
			m_imguiEditor->Render("TextEditor");
			ImGui::PopAllowKeyboardFocus();
			if (m_scrollToBottom || (m_autoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()))
				ImGui::SetScrollHereY(1.0f);
			ImGui::EndChild();
			m_scrollToBottom = false;
		}

		ImGui::Separator();

		// Command-line

		int textFlags = ImGuiInputTextFlags_EnterReturnsTrue
			| ImGuiInputTextFlags_CallbackCompletion
			| ImGuiInputTextFlags_CallbackHistory;

		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 4);
		ImGui::PushItemWidth(ImGui::GetContentRegionAvailWidth());
		ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));
		ImGui::PushFont(mq::imgui::ConsoleFont);

		bool bTextEdit = ImGui::InputText("##Input", m_inputBuffer, IM_ARRAYSIZE(m_inputBuffer), textFlags,
			[](ImGuiInputTextCallbackData* data)
		{ return static_cast<ImGuiConsole*>(data->UserData)->TextEditCallback(data); }, this);

		ImGui::PopFont();
		ImGui::PopStyleColor();

		if (bTextEdit)
		{
			char* s = m_inputBuffer;
			Strtrim(s);
			if (s[0])
				ExecCommand(s);
			strcpy_s(s, MAX_STRING, "");
			s_setFocus = true;
		}

		// Auto-focus on window apparition
		ImGui::SetItemDefaultFocus();
		if (s_setFocus)
		{
			s_setFocus = false;
			ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget
		}

		ImGui::End();
	}

	void ExecCommand(const char* commandLine)
	{
		AddLog(MQColor(128, 128, 128), "> {0}\n", commandLine);

		// Inhsert into history. First find match and delete it so i can be pushed to the back. This isn't
		// trying to be smart or optimal.
		m_historyPos = -1;

		for (int i = (int)m_history.size() - 1; i >= 0; --i)
		{
			if (ci_equals(m_history[i], commandLine))
			{
				m_history.erase(m_history.begin() + i);
				break;
			}
		}
		m_history.emplace_back(commandLine);

		// Process command
		if (ci_equals(commandLine, "clear"))
		{
			ClearLog();
		}
		else if (ci_equals(commandLine, "help"))
		{
			AddLog("Commands:\n");

			for (int i = 0; i < m_commands.Size; i++)
				AddLog("- {0}\n", m_commands[i]);
		}
		else if (ci_equals(commandLine, "history"))
		{
			int first = m_history.size() - 10;

			for (size_t i = first > 0 ? first : 0; i < m_history.size(); i++)
				AddLog("{0:3d}: {1}\n", i, m_history[i].c_str());
		}
		else if (strlen(commandLine) > 1 && commandLine[0] == '/')
		{
			mq::EzCommand(commandLine);
		}
		else
		{
			AddLog(IM_COL32(255, 0, 0, 255), "Unknown command: '{0}'\n", commandLine);
		}

		// On command input, we scroll to bottom even if AutoScroll == false
		m_scrollToBottom = true;
	}

	int TextEditCallback(ImGuiInputTextCallbackData* data)
	{
		switch (data->EventFlag)
		{
		case ImGuiInputTextFlags_CallbackCompletion:
		{
			// Example of TEXT COMPLETION

			// Locate beginning of current word
			const char* word_end = data->Buf + data->CursorPos;
			const char* word_start = word_end;
			while (word_start > data->Buf)
			{
				const char c = word_start[-1];
				if (c == ' ' || c == '\t' || c == ',' || c == ';')
					break;

				word_start--;
			}

			// Build a list of candidates
			ImVector<const char*> candidates;
			std::string_view word{ word_start, (size_t)(word_end - word_start) };

			for (int i = 0; i < m_commands.Size; i++)
			{
				if (ci_starts_with(m_commands[i], word))
					candidates.push_back(m_commands[i]);
			}

			if (candidates.Size == 0)
			{
				// No match
				AddLog("No match for \"{0}\"!\n", word);
			}
			else if (candidates.size() == 1)
			{
				// Single match. Delete the beginning of the word and replace it entirely so we've got nice casing
				data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
				data->InsertChars(data->CursorPos, candidates[0]);
				data->InsertChars(data->CursorPos, " ");
			}
			else
			{
				// Multiple matches. Complete as much as we can, so inputing "C" will complete to "CL" and display "CLEAR" and "CLASSIFY"
				int match_len = (int)(word_end - word_start);
				for (;;)
				{
					int c = 0;
					bool all_candidates_matches = true;
					for (int i = 0; i < candidates.Size && all_candidates_matches; i++)
						if (i == 0)
							c = toupper(candidates[i][match_len]);
						else if (c == 0 || c != toupper(candidates[i][match_len]))
							all_candidates_matches = false;
					if (!all_candidates_matches)
						break;
					match_len++;
				}

				if (match_len > 0)
				{
					data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
					data->InsertChars(data->CursorPos, candidates[0], candidates[0] + match_len);
				}

				// List matches
				AddLog("Possible matches:\n");
				for (int i = 0; i < candidates.Size; i++)
					AddLog("- {0}\n", candidates[i]);
			}

			break;
		}

		case ImGuiInputTextFlags_CallbackHistory:
		{
			// Example of HISTORY
			const int prev_history_pos = m_historyPos;
			if (data->EventKey == ImGuiKey_UpArrow)
			{
				if (m_historyPos == -1)
					m_historyPos = m_history.size() - 1;
				else if (m_historyPos > 0)
					m_historyPos--;
			}
			else if (data->EventKey == ImGuiKey_DownArrow)
			{
				if (m_historyPos != -1)
					if (++m_historyPos >= (int)m_history.size())
						m_historyPos = -1;
			}

			// A better implementation would preserve the data on the current input line along with cursor position.
			if (prev_history_pos != m_historyPos)
			{
				const char* history_str = (m_historyPos >= 0) ? m_history[m_historyPos].c_str() : "";
				data->DeleteChars(0, data->BufTextLen);
				data->InsertChars(0, history_str);
			}
		}
		}
		return 0;
	}
};

#pragma endregion

//============================================================================

ImGuiID MyDockSpaceOverViewport(ImGuiViewport* viewport, ImGuiDockNodeFlags dockspace_flags, const ImGuiWindowClass* window_class = nullptr)
{
	using namespace ImGui;

	if (viewport == nullptr)
		viewport = GetMainViewport();

	SetNextWindowPos(viewport->Pos);
	SetNextWindowSize(viewport->Size);
	SetNextWindowViewport(viewport->ID);

	ImGuiWindowFlags host_window_flags = 0;
	host_window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDocking;
	host_window_flags |= ImGuiWindowFlags_NoNavFocus;
	if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
		host_window_flags |= ImGuiWindowFlags_NoBackground;
	host_window_flags |= ImGuiWindowFlags_NoInputs;

	char label[32];
	ImFormatString(label, IM_ARRAYSIZE(label), "DockSpaceViewport_%08X", viewport->ID);

	PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
	PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.9f));
	Begin(label, nullptr, host_window_flags);

	ImGuiID dockspace_id = GetID("DockSpace");
	DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags, window_class);

	PopStyleVar(3);
	PopStyleColor();
	End();

	return dockspace_id;
}

void DrawDockSpace()
{
	// when using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
	// and handle the pass-thru hole, so we ask Begin() to not render a background.
	ImGuiDockNodeFlags dockspaceFlags = ImGuiDockNodeFlags_None
		| ImGuiDockNodeFlags_PassthruCentralNode
		| ImGuiDockNodeFlags_NoDockingInCentralNode;

	if (!s_dockspaceVisible)
	{
		dockspaceFlags |= ImGuiDockNodeFlags_KeepAliveOnly;
	}

	if (s_setFocus)
	{
		ImGui::SetNextWindowFocus();
	}
	s_dockspaceId = MyDockSpaceOverViewport(nullptr, dockspaceFlags);

	ImGuiDockNode* node = ImGui::DockBuilderGetNode(s_dockspaceId);
	if (node == nullptr || s_resetDockspace || (!node->Windows.empty() && node->ChildNodes[0] == nullptr && node->ChildNodes[1] == nullptr))
	{
		s_resetDockspace = false;

		// Preserve the windows
		ImVector<ImGuiWindow*> Windows;
		if (node)
		{
			Windows = node->Windows;
		}

		ImGuiViewport* viewport = ImGui::GetMainViewport();
		// Reset layout
		ImGui::DockBuilderRemoveNode(s_dockspaceId);
		ImGui::DockBuilderAddNode(s_dockspaceId, ImGuiDockNodeFlags_DockSpace);
		ImGui::DockBuilderSetNodeSize(s_dockspaceId, viewport->Size);

		// This variable will track the document node, however we are not using it
		// here as we aren't docking anything into it.
		ImGuiID dock_main_id = s_dockspaceId;

		ImGuiID dock_id_console = ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Up, 0.25f, nullptr, &dock_main_id);
		ImGui::DockBuilderDockWindow("MacroQuest Console", dock_id_console);
		for (ImGuiWindow* window : Windows)
			ImGui::DockBuilderDockWindow(window->Name, dock_id_console);

		ImGui::DockBuilderFinish(s_dockspaceId);
	}
}

static void MakeColorGradient(float frequency1, float frequency2, float frequency3,
	float phase1, float phase2, float phase3,
	float center, float width, int length)
{
	if (!gImGuiConsole)
		return;

	char szBuffer[2048] = { 0 };

	for (int i = 1; i < length + 1; ++i)
	{
		ImU32 color = ImGui::ColorConvertFloat4ToU32(ImVec4(
			(sin(frequency1 * i + phase1) * width + center) / 255,
			(sin(frequency2 * i + phase2) * width + center) / 255,
			(sin(frequency3 * i + phase3) * width + center) / 255, 1.0));

		std::string test = fmt::format("\a#{:06x}x", (color & 0xffffff));
		strcat_s(szBuffer, test.c_str());
		//gImGuiConsole->AddWriteChatColorLog(test.c_str());

		if (i % 50 == 0)
		{
			WriteChatColor(szBuffer);
			szBuffer[0] = 0;
		}
	}

	WriteChatColor(szBuffer);
}

//----------------------------------------------------------------------------

void UpdateImGuiConsole()
{
	if (gbToggleConsoleRequested)
	{
		gbToggleConsoleRequested = false;

		s_dockspaceVisible = !s_dockspaceVisible;
		if (s_dockspaceVisible)
		{
			s_setFocus = true;

			// activate main viewport
			ImGuiViewport* mainViewport = ImGui::GetMainViewport();

			if (ImGui::GetCurrentWindow()->Viewport->ID != mainViewport->ID)
			{
				// Activate the main viewport window.
				::SetActiveWindow((HWND)mainViewport->PlatformHandle);
			}
		}
	}

	// Initialize dockspace first so other windows can utilize it.+
	DrawDockSpace();

	if (s_dockspaceVisible)
	{
		ImGui::SetNextWindowDockID(s_dockspaceId, ImGuiCond_FirstUseEver);
		gImGuiConsole->Draw(&s_dockspaceVisible);
	}
}

void InitializeImGuiConsole()
{
	gImGuiConsole = new ImGuiConsole();
}

void ShutdownImGuiConsole()
{
	delete gImGuiConsole;
	gImGuiConsole = nullptr;
}

DWORD ImGuiConsoleAddText(const char* line, DWORD color, DWORD filter)
{
	ImU32 col = GetColorForChatColor(color).ToRGBA8();

	if (!gImGuiConsole)
		return 0;

	gImGuiConsole->AddWriteChatColorLog(line, col, true);

	return 0;
}

} // namespace mq
