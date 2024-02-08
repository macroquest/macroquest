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

#include "imgui.h"

#include <array>
#include <chrono>
#include <deque>
#include <map>
#include <memory>
#include <regex>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>

namespace mq::imgui::texteditor {

//============================================================================

class TextEditor;

enum class PaletteIndex
{
	Default,
	Keyword,
	Number,
	String,
	CharLiteral,
	Punctuation,
	Preprocessor,
	Identifier,
	KnownIdentifier,
	PreprocIdentifier,
	Comment,
	MultiLineComment,
	Background,
	Cursor,
	Selection,
	ErrorMarker,
	Breakpoint,
	LineNumber,
	CurrentLineFill,
	CurrentLineFillInactive,
	CurrentLineEdge,
	Max
};

//============================================================================

enum class SelectionMode
{
	Normal,
	Word,
	Line
};

//============================================================================

struct Breakpoint
{
	int line = -1;
	bool enabled = false;
	std::string condition;
};

//============================================================================
// Represents a character coordinate from the user's point of view,
// i. e. consider an uniform grid (assuming fixed-width font) on the
// screen as it is rendered, and each cell has its own coordinate, starting from 0.
// Tabs are counted as [1..mTabSize] count empty spaces, depending on
// how many space is necessary to reach the next tab stop.
// For example, coordinate (1, 5) represents the character 'B' in a line "\tABC", when mTabSize = 4,
// because it is rendered as "    ABC" on the screen.
struct Coordinates
{
	int line = 0;
	int column = 0;

	IMGUI_API Coordinates() = default;
	IMGUI_API Coordinates(int aLine, int aColumn)
		: line(aLine), column(aColumn)
	{
		assert(aLine >= 0);
		assert(aColumn >= 0);
	}

	IMGUI_API static Coordinates Invalid()
	{
		static Coordinates invalid(-1, -1); return invalid;
	}

	inline bool operator ==(const Coordinates& o) const
	{
		return
			line == o.line &&
			column == o.column;
	}

	inline bool operator !=(const Coordinates& o) const
	{
		return
			line != o.line ||
			column != o.column;
	}

	inline bool operator <(const Coordinates& o) const
	{
		if (line != o.line)
			return line < o.line;
		return column < o.column;
	}

	inline bool operator >(const Coordinates& o) const
	{
		if (line != o.line)
			return line > o.line;
		return column > o.column;
	}

	inline bool operator <=(const Coordinates& o) const
	{
		if (line != o.line)
			return line < o.line;
		return column <= o.column;
	}

	inline bool operator >=(const Coordinates& o) const
	{
		if (line != o.line)
			return line > o.line;
		return column >= o.column;
	}
};

//============================================================================

struct Identifier
{
	Coordinates location;
	std::string declaration;
};

//============================================================================

using Char = uint8_t;
using String = std::string;

using Identifiers = std::unordered_map<std::string, texteditor::Identifier>;
using Keywords = std::unordered_set<std::string>;
using ErrorMarkers = std::map<int, std::string>;
using Breakpoints = std::unordered_set<int>;
using Palette = std::array<ImU32, (unsigned)texteditor::PaletteIndex::Max>;

//============================================================================

struct Glyph
{
	Char ch;
	union {
		PaletteIndex colorIndex;
		ImU32 argbColor;
	};
	bool comment : 1;
	bool multlineComment : 1;
	bool preprocessor : 1;
	bool rawColor : 1;

	Glyph(Char ch, PaletteIndex colorIndex) : ch(ch), colorIndex(colorIndex),
		comment(false), multlineComment(false), preprocessor(false), rawColor(false) {}
	Glyph(Char ch, uint32_t ARGB) : ch(ch), argbColor(ARGB),
		comment(false), multlineComment(false), preprocessor(false), rawColor(true) {}
};

using Glyphs = std::vector<Glyph>;

//============================================================================

struct Line
{
	Glyphs glyphs;

	std::string to_string() const;

	Line(Glyphs glyphs) : glyphs(std::move(glyphs)) {}
	Line() = default;
};

using Lines = std::deque<Line>;

//============================================================================

struct LanguageDefinition
{
	using TokenRegexString = std::pair<std::string, PaletteIndex>;
	using TokenRegexStrings = std::vector<TokenRegexString>;

	// inBegin, inEnd, outBegin, outEnd, palleteIndex
	using TokenizeCallback = bool(*)(const char*, const char*, const char*&, const char*&, PaletteIndex&);

	std::string name;
	Keywords keywords;
	Identifiers identifiers;
	Identifiers preprocIdentifiers;
	std::string commentStart, commentEnd, singleLineComment;
	char preprocChar = '#';
	bool autoIndentation = true;
	TokenizeCallback tokenize = nullptr;
	TokenRegexStrings tokenRegexStrings;
	bool caseSensitive = true;
	bool enabled = true;

	IMGUI_API LanguageDefinition() = default;

	IMGUI_API static const LanguageDefinition& CPlusPlus();
	IMGUI_API static const LanguageDefinition& HLSL();
	IMGUI_API static const LanguageDefinition& GLSL();
	IMGUI_API static const LanguageDefinition& C();
	IMGUI_API static const LanguageDefinition& SQL();
	IMGUI_API static const LanguageDefinition& Lua();
	IMGUI_API static const LanguageDefinition& PlainText();
};

//============================================================================

using RegexList = std::vector<std::pair<std::regex, PaletteIndex>>;

struct EditorState
{
	Coordinates selectionStart;
	Coordinates selectionEnd;
	Coordinates cursorPosition;
};

class UndoRecord
{
public:
	UndoRecord() {}
	~UndoRecord() {}

	UndoRecord(
		const std::string& added,
		const Coordinates addedStart,
		const Coordinates addedEnd,
		const std::string& removed,
		const Coordinates removedStart,
		const Coordinates removedEnd,
		EditorState& before,
		EditorState& after);

	void Undo(TextEditor* editor);
	void Redo(TextEditor* editor);

	std::string added;
	Coordinates addedStart;
	Coordinates addedEnd;

	std::string removed;
	Coordinates removedStart;
	Coordinates removedEnd;

	EditorState before;
	EditorState after;
};

using UndoBuffer = std::vector<UndoRecord>;

//============================================================================

class TextEditor
{
	friend class UndoRecord;

public:
	IMGUI_API TextEditor();
	IMGUI_API ~TextEditor();

	IMGUI_API void SetLanguageDefinition(const LanguageDefinition& languageDef);
	inline const LanguageDefinition& GetLanguageDefinition() const { return m_languageDefinition; }

	inline const Palette& GetPalette() const { return m_paletteBase; }
	IMGUI_API void SetPalette(const Palette& value);

	inline void SetErrorMarkers(const ErrorMarkers& markers) { m_errorMarkers = markers; }
	inline void SetBreakpoints(const Breakpoints& bps) { m_breakPoints = bps; }

	IMGUI_API void Render(const char* title, const ImVec2& size = ImVec2(), bool border = false);

	IMGUI_API void SetText(std::string_view text, ImU32 color);
	IMGUI_API void SetText(std::string_view text);

	IMGUI_API std::string GetText() const;

	IMGUI_API void SetTextLines(const std::vector<std::string>& lines);
	IMGUI_API std::vector<std::string> GetTextLines() const;

	IMGUI_API std::string GetSelectedText() const;
	IMGUI_API std::string GetCurrentLineText()const;

	inline int GetTotalLines() const { return (int)m_lines.size(); }
	inline bool IsOverwrite() const { return m_overwrite; }

	IMGUI_API void SetReadOnly(bool value);
	inline bool IsReadOnly() const { return m_readOnly; }
	inline bool IsTextChanged() const { return m_textChanged; }
	inline bool IsCursorPositionChanged() const { return m_cursorPositionChanged; }

	inline void SetRenderCursor(bool render) { m_renderCursor = render; }
	inline void SetRenderLineNumbers(bool render) { m_renderLineNumbers = render; }

	inline bool IsColorizerEnabled() const { return m_colorizerEnabled; }
	IMGUI_API void SetColorizerEnable(bool vValue);

	inline Coordinates GetEnd() const
	{
		return Coordinates((int)m_lines.size() - 1, 0);
	}

	inline Coordinates GetCursorPosition() const { return GetActualCursorCoordinates(); }
	IMGUI_API void SetCursorPosition(const Coordinates& position);

	inline void SetHandleMouseInputs(bool value) { m_handleMouseInputs = value; }
	inline bool IsHandleMouseInputsEnabled() const { return m_handleKeyboardInputs; }

	inline void SetHandleKeyboardInputs(bool value) { m_handleKeyboardInputs = value; }
	inline bool IsHandleKeyboardInputsEnabled() const { return m_handleKeyboardInputs; }

	inline void SetImGuiChildIgnored(bool value) { m_ignoreImGuiChild = value; }
	inline bool IsImGuiChildIgnored() const { return m_ignoreImGuiChild; }

	inline void SetShowWhitespace(bool value) { m_showWhitespace = value; }
	inline bool IsShowingWhitespace() const { return m_showWhitespace; }

	inline void SetShowShortTabGlyphs(bool value) { m_showShortTabGlyphs = value; }
	inline bool IsShowingShortTabGlyphs() const { return m_showShortTabGlyphs; }

	IMGUI_API void SetTabSize(int value);
	inline int GetTabSize() const { return m_tabSize; }

	IMGUI_API void InsertText(std::string_view value, ImU32 color);
	IMGUI_API void InsertText(std::string_view value);

	IMGUI_API void MoveUp(int amount = 1, bool select = false);
	IMGUI_API void MoveDown(int amount = 1, bool select = false);
	IMGUI_API void MoveLeft(int amount = 1, bool select = false, bool wordMode = false);
	IMGUI_API void MoveRight(int amount = 1, bool select = false, bool wordMode = false);
	IMGUI_API void MoveTop(bool select = false);
	IMGUI_API void MoveBottom(bool select = false);
	IMGUI_API void MoveHome(bool select = false);
	IMGUI_API void MoveEnd(bool select = false);

	IMGUI_API void SetSelectionStart(const Coordinates& pos);
	IMGUI_API void SetSelectionEnd(const Coordinates& pos);
	IMGUI_API void SetSelection(const Coordinates& start, const Coordinates& end, SelectionMode mode = SelectionMode::Normal);
	IMGUI_API void SelectWordUnderCursor();
	IMGUI_API void SelectAll();
	IMGUI_API bool HasSelection() const;

	IMGUI_API void Copy();
	IMGUI_API void Cut();
	IMGUI_API void Paste();
	IMGUI_API void Delete();

	IMGUI_API bool CanUndo() const;
	IMGUI_API bool CanRedo() const;
	IMGUI_API void Undo(int steps = 1);
	IMGUI_API void Redo(int steps = 1);

	IMGUI_API static const Palette& GetDarkPalette();
	IMGUI_API static const Palette& GetLightPalette();
	IMGUI_API static const Palette& GetRetroBluePalette();

private:
	void ProcessInputs();
	void Colorize(int fromLine = 0, int count = -1);
	void ColorizeRange(int fromLine = 0, int toLine = 0);
	void ColorizeInternal();
	float TextDistanceToLineStart(const Coordinates& from) const;
	void EnsureCursorVisible();
	int GetPageSize() const;
	std::string GetText(const Coordinates& start, const Coordinates& end) const;
	Coordinates GetActualCursorCoordinates() const;
	Coordinates SanitizeCoordinates(const Coordinates& value) const;
	void Advance(Coordinates& coordinates) const;
	void DeleteRange(const Coordinates& start, const Coordinates& end);
	int InsertTextAt(Coordinates& position, std::string_view value);
	int InsertTextAt(Coordinates& position, std::string_view value, ImU32 color);
	void AddUndo(UndoRecord& value);
	Coordinates ScreenPosToCoordinates(const ImVec2& position, bool insertionMode = false) const;
	Coordinates FindWordStart(const Coordinates& from) const;
	Coordinates FindWordEnd(const Coordinates& from) const;
	Coordinates FindNextWord(const Coordinates& from) const;
	int GetCharacterIndex(const Coordinates& coordinates) const;
	int GetCharacterColumn(int line, int index) const;
	int GetLineCharacterCount(int line) const;
	int GetLineMaxColumn(int line) const;
	bool IsOnWordBoundary(const Coordinates& at) const;
	void RemoveLine(int start, int end);
	void RemoveLine(int index);
	Line& InsertLine(int index);
	void EnterCharacter(ImWchar ch, bool shift);
	void Backspace();
	void DeleteSelection();
	std::string GetWordUnderCursor() const;
	std::string GetWordAt(const Coordinates& coords) const;
	ImU32 GetGlyphColor(const Glyph& glyph) const;

	void HandleKeyboardInputs();
	void HandleMouseInputs();
	void Render();

private:
	float m_lineSpacing = 1.0f;
	Lines m_lines;
	EditorState m_state;
	UndoBuffer m_undoBuffer;
	int m_undoIndex = 0;

	int m_tabSize = 4;
	bool m_overwrite = false;
	bool m_readOnly = false;
	bool m_withinRender = false;
	bool m_scrollToCursor = false;
	bool m_scrollToTop = false;
	bool m_textChanged = false;
	bool m_colorizerEnabled = true;
	float m_textStart = 20.0f;                   // position (in pixels) where a code line starts relative to the left of the TextEditor.
	int m_leftMargin = 10;
	bool m_cursorPositionChanged = false;
	int m_colorRangeMin = 0;
	int m_colorRangeMax = 0;
	SelectionMode m_selectionMode = SelectionMode::Normal;
	bool m_handleKeyboardInputs = true;
	bool m_handleMouseInputs = true;
	bool m_ignoreImGuiChild = false;
	bool m_showWhitespace = true;
	bool m_showShortTabGlyphs = false;
	bool m_renderCursor = true;
	bool m_renderLineNumbers = true;
	float m_lastClick = -1.0f;

	Palette m_paletteBase;
	Palette m_palette;
	LanguageDefinition m_languageDefinition;
	RegexList m_regexList;
	bool m_checkComments = true;
	Breakpoints m_breakPoints;
	ErrorMarkers m_errorMarkers;
	ImVec2 m_charAdvance;
	Coordinates m_interactiveStart, m_interactiveEnd;
	std::string m_lineBuffer;
	std::chrono::steady_clock::time_point m_startTime;
};

} // namespace mq::imgui::texteditor

namespace mq::imgui {
	using mq::imgui::texteditor::TextEditor;
}
