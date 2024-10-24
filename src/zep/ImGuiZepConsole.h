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

#include "zep/syntax.h"
#include "zep/theme.h"
#include "zep/ImGuiZepEditor.h"
#include "mq/imgui/ConsoleWidget.h"

#include <imgui/imgui.h>
#include <memory>

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
protected:

public:
	virtual ~ImGuiZepConsoleDelegate() = default;

	// Called when a hyperlink is clicked.
	virtual void OnHyperlinkClicked(ImGuiZepConsole* console, Zep::ZepMouseButton button, uint32_t modifiers,
		const std::string& hyperlinkData, int hyperlinkId) {}

	// Called when AppendFormattedText is called to perform formatting.
	virtual bool OnInsertFormattedText(ImGuiZepConsole* console, Zep::GlyphIterator position,
		std::string_view text, ImU32 color) { return false; }
};

//============================================================================

// This is the imgui container for the Zep component.
class ImGuiZepConsole : public mq::imgui::ConsoleWidget, public mq::imgui::ImGuiZepEditor
{
public:
	ImGuiZepConsole(std::string_view id = "");
	virtual ~ImGuiZepConsole();

	// Set a delegate to receive notification
	void SetDelegate(std::shared_ptr<ImGuiZepConsoleDelegate> delegate);

	// Render to ImGui
	void Render(const ImVec2& displaySize = ImVec2()) override;

	// Append text to the console, parsing it for hyperlinks and color codes.
	void AppendText(std::string_view text, MQColor defaultColor = DEFAULT_COLOR, bool appendNewLine = false) override;

	// Clear the console buffer
	void Clear() override;

	// If auto-scroll is enabled, trigger a scroll to the bottom on next render.
	void TriggerAutoScroll()
	{
		if (m_autoScroll)
		{
			m_deferredCursorToEnd = true;
		}
	}

	// Force a scroll to the bottom on next render
	void ScrollToBottom() override
	{
		m_deferredCursorToEnd = true;
	}

	// Returns true if the cursor is at the bottom (would trigger auto-scroll)
	bool IsCursorAtEnd() const override;

	// Get/Set autoscroll property
	bool GetAutoScroll() const override { return m_autoScroll; }
	void SetAutoScroll(bool autoScroll) override { m_autoScroll = autoScroll; }

	// Get/Set max number of lines in buffer
	int GetMaxBufferLines() const override { return m_maxBufferLines; }
	void SetMaxBufferLines(int maxBufferLines) override { m_maxBufferLines = maxBufferLines; }

	// Get/Set Opacity multiplier
	float GetOpacity() const override;
	void SetOpacity(float opacity) override;

	// Insert text at position with color
	Zep::GlyphIterator InsertText(Zep::GlyphIterator position, std::string_view text, ImU32 color = -1);
	// Insert hyperlink at position with color properties
	Zep::GlyphIterator InsertHyperlink(Zep::GlyphIterator position, std::string_view text, std::string hyperlinkData,
		uint32_t color, uint32_t hoverColor);

	Zep::ZepWindow* GetWindow() const { return m_window; }
	Zep::ZepBuffer* GetBuffer() const { return m_buffer; }

private:
	// Message handler
	void Notify(const std::shared_ptr<Zep::ZepMessage>& message) override;

	// Parse formatted text
	void InsertFormattedText(Zep::GlyphIterator position, std::string_view text, ImU32 color);

	// Remove lines to keep us within the linecount limit
	void PruneBuffer();

private:
	std::shared_ptr<ImGuiZepConsoleTheme> m_theme;
	std::shared_ptr<ImGuiZepConsoleSyntax> m_syntax;
	std::shared_ptr<ImGuiZepConsoleDelegate> m_delegate;

	Zep::ZepBuffer* m_buffer = nullptr;
	Zep::ZepWindow* m_window = nullptr;

	bool m_deferredCursorToEnd = false;
	bool m_autoScroll = true;
	int m_maxBufferLines = 10000;
};

} // namespace mq
