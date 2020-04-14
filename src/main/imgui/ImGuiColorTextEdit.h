/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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

namespace mq {
namespace imgui {

class TextEditor
{
public:
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

	enum class SelectionMode
	{
		Normal,
		Word,
		Line
	};

	struct Breakpoint
	{
		int mLine = -1;
		bool mEnabled = false;
		std::string mCondition;
	};

	// Represents a character coordinate from the user's point of view,
	// i. e. consider an uniform grid (assuming fixed-width font) on the
	// screen as it is rendered, and each cell has its own coordinate, starting from 0.
	// Tabs are counted as [1..mTabSize] count empty spaces, depending on
	// how many space is necessary to reach the next tab stop.
	// For example, coordinate (1, 5) represents the character 'B' in a line "\tABC", when mTabSize = 4,
	// because it is rendered as "    ABC" on the screen.
	struct Coordinates
	{
		int mLine = 0;
		int mColumn = 0;

		Coordinates() = default;
		Coordinates(int aLine, int aColumn)
			: mLine(aLine), mColumn(aColumn)
		{
			assert(aLine >= 0);
			assert(aColumn >= 0);
		}

		static Coordinates Invalid() { static Coordinates invalid(-1, -1); return invalid; }

		bool operator ==(const Coordinates& o) const
		{
			return
				mLine == o.mLine &&
				mColumn == o.mColumn;
		}

		bool operator !=(const Coordinates& o) const
		{
			return
				mLine != o.mLine ||
				mColumn != o.mColumn;
		}

		bool operator <(const Coordinates& o) const
		{
			if (mLine != o.mLine)
				return mLine < o.mLine;
			return mColumn < o.mColumn;
		}

		bool operator >(const Coordinates& o) const
		{
			if (mLine != o.mLine)
				return mLine > o.mLine;
			return mColumn > o.mColumn;
		}

		bool operator <=(const Coordinates& o) const
		{
			if (mLine != o.mLine)
				return mLine < o.mLine;
			return mColumn <= o.mColumn;
		}

		bool operator >=(const Coordinates& o) const
		{
			if (mLine != o.mLine)
				return mLine > o.mLine;
			return mColumn >= o.mColumn;
		}
	};

	struct Identifier
	{
		Coordinates mLocation;
		std::string mDeclaration;
	};

	using String = std::string;
	using Identifiers = std::unordered_map<std::string, Identifier>;
	using Keywords = std::unordered_set<std::string>;
	using ErrorMarkers = std::map<int, std::string>;
	using Breakpoints = std::unordered_set<int>;
	using Palette = std::array<ImU32, (unsigned)PaletteIndex::Max>;
	using Char = uint8_t;

	struct Glyph
	{
		Char mChar;
		union {
			PaletteIndex mColorIndex;
			ImU32 mARGBColor;
		};
		bool mComment : 1;
		bool mMultiLineComment : 1;
		bool mPreprocessor : 1;
		bool mRawColor : 1;

		Glyph(Char aChar, PaletteIndex aColorIndex) : mChar(aChar), mColorIndex(aColorIndex),
			mComment(false), mMultiLineComment(false), mPreprocessor(false), mRawColor(false) {}
		Glyph(Char aChar, uint32_t ARGB) : mChar(aChar), mARGBColor(ARGB),
			mComment(false), mMultiLineComment(false), mPreprocessor(false), mRawColor(true) {}
	};

	using Line = std::vector<Glyph>;
	using Lines = std::deque<Line>;

	struct LanguageDefinition
	{
		using TokenRegexString = std::pair<std::string, PaletteIndex>;
		using TokenRegexStrings = std::vector<TokenRegexString>;

		// inBegin, inEnd, outBegin, outEnd, palleteIndex
		using TokenizeCallback = bool(*)(const char*, const char*, const char*&, const char*&, PaletteIndex&);

		std::string mName;
		Keywords mKeywords;
		Identifiers mIdentifiers;
		Identifiers mPreprocIdentifiers;
		std::string mCommentStart, mCommentEnd, mSingleLineComment;
		char mPreprocChar = '#';
		bool mAutoIndentation = true;
		TokenizeCallback mTokenize = nullptr;
		TokenRegexStrings mTokenRegexStrings;
		bool mCaseSensitive = true;

		LanguageDefinition() = default;

		static const LanguageDefinition& CPlusPlus();
		static const LanguageDefinition& HLSL();
		static const LanguageDefinition& GLSL();
		static const LanguageDefinition& C();
		static const LanguageDefinition& SQL();
		static const LanguageDefinition& AngelScript();
		static const LanguageDefinition& Lua();
	};

	TextEditor();
	~TextEditor();

	void SetLanguageDefinition(const LanguageDefinition& aLanguageDef);
	const LanguageDefinition& GetLanguageDefinition() const { return m_languageDefinition; }

	const Palette& GetPalette() const { return m_paletteBase; }
	void SetPalette(const Palette& aValue);

	void SetErrorMarkers(const ErrorMarkers& aMarkers) { m_errorMarkers = aMarkers; }
	void SetBreakpoints(const Breakpoints& aMarkers) { m_breakPoints = aMarkers; }

	void Render(const char* aTitle, const ImVec2& aSize = ImVec2(), bool aBorder = false);

	void SetText(std::string_view text, ImU32 color);
	void SetText(std::string_view aText);

	std::string GetText() const;

	void SetTextLines(const std::vector<std::string>& aLines);
	std::vector<std::string> GetTextLines() const;

	std::string GetSelectedText() const;
	std::string GetCurrentLineText()const;

	int GetTotalLines() const { return (int)m_lines.size(); }
	bool IsOverwrite() const { return m_overwrite; }

	void SetReadOnly(bool aValue);
	bool IsReadOnly() const { return m_readOnly; }
	bool IsTextChanged() const { return m_textChanged; }
	bool IsCursorPositionChanged() const { return m_cursorPositionChanged; }

	void SetRenderCursor(bool bRender) { m_renderCursor = bRender; }
	void SetRenderLineNumbers(bool bRender) { m_renderLineNumbers = bRender; }

	bool IsColorizerEnabled() const { return m_colorizerEnabled; }
	void SetColorizerEnable(bool aValue);

	Coordinates GetEnd() const {
		return Coordinates((int)m_lines.size() - 1, 0);
	}

	Coordinates GetCursorPosition() const { return GetActualCursorCoordinates(); }
	void SetCursorPosition(const Coordinates& aPosition);

	inline void SetHandleMouseInputs(bool aValue) { m_handleMouseInputs = aValue; }
	inline bool IsHandleMouseInputsEnabled() const { return m_handleKeyboardInputs; }

	inline void SetHandleKeyboardInputs(bool aValue) { m_handleKeyboardInputs = aValue; }
	inline bool IsHandleKeyboardInputsEnabled() const { return m_handleKeyboardInputs; }

	inline void SetImGuiChildIgnored(bool aValue) { m_ignoreImGuiChild = aValue; }
	inline bool IsImGuiChildIgnored() const { return m_ignoreImGuiChild; }

	inline void SetShowWhitespace(bool aValue) { m_showWhitespace = aValue; }
	inline bool IsShowingWhitespace() const { return m_showWhitespace; }

	inline void SetShowShortTabGlyphs(bool aValue) { m_showShortTabGlyphs = aValue; }
	inline bool IsShowingShortTabGlyphs() const { return m_showShortTabGlyphs; }

	void SetTabSize(int aValue);
	inline int GetTabSize() const { return m_tabSize; }

	void InsertText(std::string_view aValue, ImU32 color);
	void InsertText(std::string_view aValue);

	void MoveUp(int aAmount = 1, bool aSelect = false);
	void MoveDown(int aAmount = 1, bool aSelect = false);
	void MoveLeft(int aAmount = 1, bool aSelect = false, bool aWordMode = false);
	void MoveRight(int aAmount = 1, bool aSelect = false, bool aWordMode = false);
	void MoveTop(bool aSelect = false);
	void MoveBottom(bool aSelect = false);
	void MoveHome(bool aSelect = false);
	void MoveEnd(bool aSelect = false);

	void SetSelectionStart(const Coordinates& aPosition);
	void SetSelectionEnd(const Coordinates& aPosition);
	void SetSelection(const Coordinates& aStart, const Coordinates& aEnd, SelectionMode aMode = SelectionMode::Normal);
	void SelectWordUnderCursor();
	void SelectAll();
	bool HasSelection() const;

	void Copy();
	void Cut();
	void Paste();
	void Delete();

	bool CanUndo() const;
	bool CanRedo() const;
	void Undo(int aSteps = 1);
	void Redo(int aSteps = 1);

	static const Palette& GetDarkPalette();
	static const Palette& GetLightPalette();
	static const Palette& GetRetroBluePalette();

private:
	using RegexList = std::vector<std::pair<std::regex, PaletteIndex>>;

	struct EditorState
	{
		Coordinates mSelectionStart;
		Coordinates mSelectionEnd;
		Coordinates mCursorPosition;
	};

	class UndoRecord
	{
	public:
		UndoRecord() {}
		~UndoRecord() {}

		UndoRecord(
			const std::string& aAdded,
			const TextEditor::Coordinates aAddedStart,
			const TextEditor::Coordinates aAddedEnd,

			const std::string& aRemoved,
			const TextEditor::Coordinates aRemovedStart,
			const TextEditor::Coordinates aRemovedEnd,

			TextEditor::EditorState& aBefore,
			TextEditor::EditorState& aAfter);

		void Undo(TextEditor* aEditor);
		void Redo(TextEditor* aEditor);

		std::string mAdded;
		Coordinates mAddedStart;
		Coordinates mAddedEnd;

		std::string mRemoved;
		Coordinates mRemovedStart;
		Coordinates mRemovedEnd;

		EditorState mBefore;
		EditorState mAfter;
	};

	using UndoBuffer = std::vector<UndoRecord>;

	void ProcessInputs();
	void Colorize(int aFromLine = 0, int aCount = -1);
	void ColorizeRange(int aFromLine = 0, int aToLine = 0);
	void ColorizeInternal();
	float TextDistanceToLineStart(const Coordinates& aFrom) const;
	void EnsureCursorVisible();
	int GetPageSize() const;
	std::string GetText(const Coordinates& aStart, const Coordinates& aEnd) const;
	Coordinates GetActualCursorCoordinates() const;
	Coordinates SanitizeCoordinates(const Coordinates& aValue) const;
	void Advance(Coordinates& aCoordinates) const;
	void DeleteRange(const Coordinates& aStart, const Coordinates& aEnd);
	int InsertTextAt(Coordinates& aWhere, std::string_view aValue);
	int InsertTextAt(Coordinates& aWhere, std::string_view aValue, ImU32 aColor);
	void AddUndo(UndoRecord& aValue);
	Coordinates ScreenPosToCoordinates(const ImVec2& aPosition, bool aInsertionMode = false) const;
	Coordinates FindWordStart(const Coordinates& aFrom) const;
	Coordinates FindWordEnd(const Coordinates& aFrom) const;
	Coordinates FindNextWord(const Coordinates& aFrom) const;
	int GetCharacterIndex(const Coordinates& aCoordinates) const;
	int GetCharacterColumn(int aLine, int aIndex) const;
	int GetLineCharacterCount(int aLine) const;
	int GetLineMaxColumn(int aLine) const;
	bool IsOnWordBoundary(const Coordinates& aAt) const;
	void RemoveLine(int aStart, int aEnd);
	void RemoveLine(int aIndex);
	Line& InsertLine(int aIndex);
	void EnterCharacter(ImWchar aChar, bool aShift);
	void Backspace();
	void DeleteSelection();
	std::string GetWordUnderCursor() const;
	std::string GetWordAt(const Coordinates& aCoords) const;
	ImU32 GetGlyphColor(const Glyph& aGlyph) const;

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

}} // namespace mq::imgui
