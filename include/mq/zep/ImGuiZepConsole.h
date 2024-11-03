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

#include "mq/base/Color.h"
#include "mq/zep/ImGuiZepEditor.h"
#include "zep/syntax.h"
#include "zep/theme.h"

#include <imgui/imgui.h>
#include <memory>

#pragma comment(lib, "zep.lib")

namespace Zep
{
	class ZepMessage;
	class ZepEditor;
}

namespace mq {

//============================================================================

// This theme extends the default theme to support arbitrary coloring via extended
// UserColor values of the ThemeColor enum.
class ImGuiZepConsoleTheme : public Zep::ZepTheme
{
public:
	static constexpr int UserColorStart = static_cast<int>(Zep::ThemeColor::UniqueColorLast) + 1;

	ImGuiZepConsoleTheme();
	virtual ~ImGuiZepConsoleTheme() override;

	virtual Zep::ZepColor GetColor(Zep::ThemeColor themeColor) const override;
	Zep::ThemeColor GetUserColor(Zep::ZepColor color);

	float GetOpacity() { return m_opacity; }
	void SetOpacity(float opacity) { m_opacity = opacity; }

private:
	std::vector<Zep::ZepColor> m_userColors;
	float m_opacity = 1.0f;
};

//============================================================================

// Some plain default colors
static constexpr ImU32 s_defaultLinkColor = MQColor(0, 128, 255).ToImU32();
static constexpr ImU32 s_defaultLinkColorHover = MQColor(255, 255, 128).ToImU32();

struct ZepAttribute
{
	enum class Type
	{
		Color,
		Hyperlink
	};

	struct ColorAttributeData
	{
		uint32_t color;
	};

	struct HyperlinkAttributeData
	{
		std::string linkData;
		uint32_t color = s_defaultLinkColor;
		uint32_t hoverColor = s_defaultLinkColorHover;
	};

	using ZepAttributeData = std::variant<ColorAttributeData, HyperlinkAttributeData>;

	Type type;
	ZepAttributeData data;

	ZepAttribute(Type type, ZepAttributeData data)
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
class ImGuiZepConsoleSyntax : public Zep::ZepSyntax
{
public:
	ImGuiZepConsoleSyntax(Zep::ZepBuffer& buffer,
		const std::shared_ptr<ImGuiZepConsoleTheme>& theme,
		Zep::ZepWindow* window);

	~ImGuiZepConsoleSyntax() override;

	void SetWindow(Zep::ZepWindow* window);

	struct SyntaxData
	{
		Zep::ThemeColor foreground = Zep::ThemeColor::Normal;
		uint32_t hyperlinkId = 0;
	};

	Zep::SyntaxResult GetSyntaxAt(const Zep::GlyphIterator& index) const override;

	void Notify(std::shared_ptr<Zep::ZepMessage> msg) override;
	void DispatchMouseEvent(std::shared_ptr<Zep::ZepMessage> msg) override;

	void UpdateMouseCursor(const Zep::GlyphIterator& offset);

	Zep::ThemeColor GetHyperlinkColor(uint32_t linkId, bool hovered) const;
	uint32_t MakeHyperlink(const ZepAttribute::HyperlinkAttributeData& hyperlinkData);
	void RemoveHyperlink(uint32_t hyperlinkId);

	void AddAttribute(const Zep::GlyphIterator& position, ZepTextAttribute attr);

private:
	std::vector<SyntaxData> m_syntax;
	std::shared_ptr<ImGuiZepConsoleTheme> m_theme;
	std::vector<ZepBufferAttribute> m_pendingAttributes;
	uint32_t m_nextHyperlinkId = 1;
	std::unordered_map<uint32_t, ZepAttribute::HyperlinkAttributeData> m_hyperlinkData;
	uint32_t m_hoveredHyperlink = 0;
	Zep::scoped_connection onMouseCursorChanged;
	int m_latestPosition = 0;
};

//============================================================================

class ImGuiZepConsole;

class ImGuiZepConsoleDelegate
{
public:
	virtual ~ImGuiZepConsoleDelegate() = default;

	// Called when a hyperlink is clicked.
	virtual bool OnHyperlinkClicked(ImGuiZepConsole* console, Zep::ZepMouseButton button, uint32_t modifiers,
		const std::string& hyperlinkData, int hyperlinkId) { return false; }

	// Called when AppendFormattedText is called to perform formatting.
	virtual bool OnInsertFormattedText(ImGuiZepConsole* console, Zep::GlyphIterator position,
		std::string_view text, ImU32 color) { return false; }
};

//============================================================================

enum ImGuiZepConsoleCol_
{
	ImGuiZepConsoleCol_Text,
	ImGuiZepConsoleCol_Link,
	ImGuiZepConsoleCol_LinkHover,

	ImGuiZepConsoleCol_Count
};
using ImGuiZepConsoleCol = int;

struct ImGuiZepConsoleStyle
{
	ImU32 colors[ImGuiZepConsoleCol_Count];

	ImGuiZepConsoleStyle();
};

struct ImGuiZepConsoleColorMod
{
	ImGuiZepConsoleCol Col;
	ImU32              BackupValue;
};

//============================================================================

// This is the imgui container for the Zep component.
class ImGuiZepConsole : public ImGuiZepEditor
{
public:
	static constexpr MQColor DEFAULT_COLOR = MQColor(240, 240, 240, 255);

	ImGuiZepConsole(std::string_view id = "");
	virtual ~ImGuiZepConsole() override;

	// Set a delegate to receive notification
	void SetDelegate(std::shared_ptr<ImGuiZepConsoleDelegate> delegate);

	// Render to ImGui
	void Render(const char* id, const ImVec2& displaySize = ImVec2()) override;
	using ImGuiZepEditor::Render;

	// Clear the console buffer
	void Clear();

	// Force a scroll to the bottom on next render
	void ScrollToBottom()
	{
		m_deferredCursorToEnd = true;
	}

	// Returns true if the cursor is at the bottom (would trigger auto-scroll)
	bool IsCursorAtEnd() const;

	// Get/Set autoscroll property
	bool GetAutoScroll() const { return m_autoScroll; }
	void SetAutoScroll(bool autoScroll) { m_autoScroll = autoScroll; }

	// Get/Set max number of lines in buffer
	int GetMaxBufferLines() const { return m_maxBufferLines; }
	void SetMaxBufferLines(int maxBufferLines) { m_maxBufferLines = maxBufferLines; }

	// Get/Set Opacity multiplier
	float GetOpacity() const;
	void SetOpacity(float opacity);

	// Append text to the console, parsing it for hyperlinks and color codes.
	void AppendText(std::string_view text, MQColor defaultColor = MQColor(0, 0, 0, 0), bool appendNewLine = false);

	// Insert text at position with color
	Zep::GlyphIterator InsertText(Zep::GlyphIterator position, std::string_view text, ImU32 color = 0);
	// Insert hyperlink at position with color properties
	Zep::GlyphIterator InsertHyperlink(Zep::GlyphIterator position, std::string_view text, std::string hyperlinkData,
		ImU32 color = 0, ImU32 hoverColor = 0);
	Zep::GlyphIterator InsertHyperlink(Zep::GlyphIterator position, std::string_view text,
		const ZepAttribute::HyperlinkAttributeData& attributeData);

	Zep::GlyphIterator InsertAttributedText(Zep::GlyphIterator position, std::string_view text,
		ZepTextAttribute attribute);

	template <typename... Attrs>
	Zep::GlyphIterator InsertAttributedText(Zep::GlyphIterator position, std::string_view text, Attrs&&... attrs)
	{
		// Add all the attributes
		ImGuiZepConsoleSyntax* syntax = static_cast<ImGuiZepConsoleSyntax*>(m_buffer->GetSyntax());
		(syntax->AddAttribute(position, std::forward<Attrs>(attrs)), ...);

		// Insert the text
		Zep::ChangeRecord changeRecord;
		m_buffer->Insert(position, text, changeRecord);

		return position.Move(static_cast<long>(text.length()));
	}

	void PushStyleColor(ImGuiZepConsoleCol index, ImU32 col);
	void PushStyleColor(ImGuiZepConsoleCol index, MQColor col);
	void PushStyleColor(ImGuiZepConsoleCol index, const ImVec4& col);

	void PopStyleColor(int count = 1);

	ImGuiZepConsoleStyle& GetStyle() { return m_style; }

private:
	// Message handler
	void Notify(const std::shared_ptr<Zep::ZepMessage>& message) override;

	// Parse formatted text
	void InsertFormattedText(Zep::GlyphIterator position, std::string_view text, ImU32 color);

	// Remove lines to keep us within the linecount limit
	void PruneBuffer();

	std::string_view ParseColorTags(std::string_view line, int& pushed);

private:
	std::shared_ptr<ImGuiZepConsoleTheme> m_theme;
	std::shared_ptr<ImGuiZepConsoleSyntax> m_syntax;
	std::shared_ptr<ImGuiZepConsoleDelegate> m_delegate;
	ImGuiZepConsoleStyle m_style;
	std::vector<ImGuiZepConsoleColorMod> m_colorStack;

	Zep::ZepBuffer* m_buffer = nullptr;
	int m_maxBufferLines = 10000;

	// Tracking information for autoscroll
	int m_lastCursorIndex = 0;
	bool m_lastCursorAtEnd = true;
	bool m_autoScroll = true;
	bool m_deferredCursorToEnd = false;
};

} // namespace mq
