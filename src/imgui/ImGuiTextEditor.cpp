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
#include "ImGuiTextEditor.h"
#include "ImGuiUtils.h"

#include <algorithm>
#include <chrono>
#include <string>
#include <regex>
#include <cmath>

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h" // for imGui::GetCurrentWindow()

using namespace std::chrono_literals;

namespace mq::imgui::texteditor {

template <class InputIt1, class InputIt2, class BinaryPredicate>
bool equals(InputIt1 first1, InputIt1 last1,
	InputIt2 first2, InputIt2 last2, BinaryPredicate p)
{
	for (; first1 != last1 && first2 != last2; ++first1, ++first2)
	{
		if (!p(*first1, *first2))
			return false;
	}
	return first1 == last1 && first2 == last2;
}

// https://en.wikipedia.org/wiki/UTF-8
// We assume that the char is a standalone character (<128) or a leading byte of an UTF-8 code sequence (non-10xxxxxx code)
static int UTF8CharLength(Char c)
{
	if ((c & 0xFE) == 0xFC)
		return 6;
	if ((c & 0xFC) == 0xF8)
		return 5;
	if ((c & 0xF8) == 0xF0)
		return 4;
	else if ((c & 0xF0) == 0xE0)
		return 3;
	else if ((c & 0xE0) == 0xC0)
		return 2;
	return 1;
}

// "Borrowed" from ImGui source
static inline int ImTextCharToUtf8(char* buf, int buf_size, unsigned int c)
{
	if (c < 0x80)
	{
		buf[0] = (char)c;
		return 1;
	}
	if (c < 0x800)
	{
		if (buf_size < 2) return 0;
		buf[0] = (char)(0xc0 + (c >> 6));
		buf[1] = (char)(0x80 + (c & 0x3f));
		return 2;
	}
	if (c >= 0xdc00 && c < 0xe000)
	{
		return 0;
	}
	if (c >= 0xd800 && c < 0xdc00)
	{
		if (buf_size < 4) return 0;
		buf[0] = (char)(0xf0 + (c >> 18));
		buf[1] = (char)(0x80 + ((c >> 12) & 0x3f));
		buf[2] = (char)(0x80 + ((c >> 6) & 0x3f));
		buf[3] = (char)(0x80 + ((c) & 0x3f));
		return 4;
	}
	//else if (c < 0x10000)
	{
		if (buf_size < 3) return 0;
		buf[0] = (char)(0xe0 + (c >> 12));
		buf[1] = (char)(0x80 + ((c >> 6) & 0x3f));
		buf[2] = (char)(0x80 + ((c) & 0x3f));
		return 3;
	}
}

//============================================================================

std::string Line::to_string() const
{
	std::string text;
	text.resize(glyphs.size());

	for (size_t i = 0; i < glyphs.size(); ++i)
		text[i] = glyphs[i].ch;

	return text;
}

//============================================================================

UndoRecord::UndoRecord(
	const std::string& added,
	const Coordinates addedStart,
	const Coordinates addedEnd,
	const std::string& removed,
	const Coordinates removedStart,
	const Coordinates removedEnd,
	EditorState& before,
	EditorState& after)
	: added(added)
	, addedStart(addedStart)
	, addedEnd(addedEnd)
	, removed(removed)
	, removedStart(removedStart)
	, removedEnd(removedEnd)
	, before(before)
	, after(after)
{
	assert(addedStart <= addedEnd);
	assert(removedStart <= removedEnd);
}

void UndoRecord::Undo(TextEditor* editor)
{
	if (!added.empty())
	{
		editor->DeleteRange(addedStart, addedEnd);
		editor->Colorize(addedStart.line - 1, addedEnd.line - addedStart.line + 2);
	}

	if (!removed.empty())
	{
		editor->InsertTextAt(removedStart, removed.c_str());
		editor->Colorize(removedStart.line - 1, removedEnd.line - removedStart.line + 2);
	}

	editor->m_state = before;
	editor->EnsureCursorVisible();

}

void UndoRecord::Redo(TextEditor* editor)
{
	if (!removed.empty())
	{
		editor->DeleteRange(removedStart, removedEnd);
		editor->Colorize(removedStart.line - 1, removedEnd.line - removedStart.line + 1);
	}

	if (!added.empty())
	{
		editor->InsertTextAt(addedStart, added.c_str());
		editor->Colorize(addedStart.line - 1, addedEnd.line - addedStart.line + 1);
	}

	editor->m_state = after;
	editor->EnsureCursorVisible();
}

//============================================================================
//============================================================================

TextEditor::TextEditor()
	: m_startTime(std::chrono::steady_clock::now())
{
	SetPalette(GetDarkPalette());
	m_lines.emplace_back();
}

TextEditor::~TextEditor()
{
}

void TextEditor::SetLanguageDefinition(const LanguageDefinition& languageDef)
{
	m_languageDefinition = languageDef;
	m_regexList.clear();

	for (auto& r : m_languageDefinition.tokenRegexStrings)
		m_regexList.emplace_back(std::regex(r.first, std::regex_constants::optimize), r.second);

	Colorize();
}

void TextEditor::SetPalette(const Palette& value)
{
	m_paletteBase = value;
}

std::string TextEditor::GetText(const Coordinates& start, const Coordinates& end) const
{
	std::string result;

	int lstart = start.line;
	int lend = end.line;
	int istart = GetCharacterIndex(start);
	int iend = GetCharacterIndex(end);
	size_t s = 0;

	for (int i = lstart; i < lend; i++)
		s += m_lines[i].glyphs.size();

	result.reserve(s + s / 8);

	while (istart < iend || lstart < lend)
	{
		if (lstart >= (int)m_lines.size())
			break;

		const Line& line = m_lines[lstart];
		if (istart < (int)line.glyphs.size())
		{
			result += line.glyphs[istart].ch;
			istart++;
		}
		else
		{
			istart = 0;
			++lstart;
			result += '\n';
		}
	}

	return result;
}

Coordinates TextEditor::GetActualCursorCoordinates() const
{
	return SanitizeCoordinates(m_state.cursorPosition);
}

Coordinates TextEditor::SanitizeCoordinates(const Coordinates& value) const
{
	int line = value.line;
	int column = value.column;

	if (line >= (int)m_lines.size())
	{
		if (m_lines.empty())
		{
			line = 0;
			column = 0;
		}
		else
		{
			line = (int)m_lines.size() - 1;
			column = GetLineMaxColumn(line);
		}

		return Coordinates(line, column);
	}
	else
	{
		column = m_lines.empty() ? 0 : std::min(column, GetLineMaxColumn(line));
		return Coordinates(line, column);
	}
}

void TextEditor::Advance(Coordinates& coordinates) const
{
	if (coordinates.line < (int)m_lines.size())
	{
		const Line& line = m_lines[coordinates.line];
		int cindex = GetCharacterIndex(coordinates);

		if (cindex + 1 < (int)line.glyphs.size())
		{
			int delta = UTF8CharLength(line.glyphs[cindex].ch);
			cindex = std::min(cindex + delta, (int)line.glyphs.size() - 1);
		}
		else
		{
			++coordinates.line;
			cindex = 0;
		}

		coordinates.column = GetCharacterColumn(coordinates.line, cindex);
	}
}

void TextEditor::DeleteRange(const Coordinates& startpos, const Coordinates& endpos)
{
	assert(endpos >= startpos);
	assert(!m_readOnly);

	if (endpos == startpos)
		return;

	int start = GetCharacterIndex(startpos);
	int end = GetCharacterIndex(endpos);

	if (startpos.line == endpos.line)
	{
		Line& line = m_lines[startpos.line];
		int n = GetLineMaxColumn(startpos.line);

		if (endpos.column >= n)
			line.glyphs.erase(line.glyphs.begin() + start, line.glyphs.end());
		else
			line.glyphs.erase(line.glyphs.begin() + start, line.glyphs.begin() + end);
	}
	else
	{
		Line& firstLine = m_lines[startpos.line];
		Line& lastLine = m_lines[endpos.line];

		firstLine.glyphs.erase(firstLine.glyphs.begin() + start, firstLine.glyphs.end());
		lastLine.glyphs.erase(lastLine.glyphs.begin(), lastLine.glyphs.begin() + end);

		if (startpos.line < endpos.line)
			firstLine.glyphs.insert(firstLine.glyphs.end(), lastLine.glyphs.begin(), lastLine.glyphs.end());

		if (startpos.line < endpos.line)
			RemoveLine(startpos.line + 1, endpos.line + 1);
	}

	m_textChanged = true;
}

int TextEditor::InsertTextAt(Coordinates& /* inout */ position, std::string_view value)
{
	int cindex = GetCharacterIndex(position);
	int totalLines = 0;
	size_t i = 0;

	while (i < value.length())
	{
		assert(!m_lines.empty());

		if (value[i] == '\r')
		{
			// skip
			++i;
		}
		else if (value[i] == '\n')
		{
			if (cindex < (int)m_lines[position.line].glyphs.size())
			{
				Line& newLine = InsertLine(position.line + 1);
				Line& line = m_lines[position.line];
				newLine.glyphs.insert(newLine.glyphs.begin(), line.glyphs.begin() + cindex, line.glyphs.end());
				line.glyphs.erase(line.glyphs.begin() + cindex, line.glyphs.end());
			}
			else
			{
				InsertLine(position.line + 1);
			}

			++position.line;
			position.column = 0;
			cindex = 0;
			++totalLines;
			++i;
		}
		else
		{
			Line& line = m_lines[position.line];
			int d = UTF8CharLength(value[i]);

			while (d-- > 0 && i < value.length())
			{
				line.glyphs.emplace(line.glyphs.begin() + cindex++, value[i++], PaletteIndex::Default);
			}

			position.column = GetCharacterColumn(position.line, cindex);
		}

		m_textChanged = true;
	}

	return totalLines;
}

int TextEditor::InsertTextAt(Coordinates& /* inout */ position, std::string_view value, ImU32 color)
{
	int cindex = GetCharacterIndex(position);
	int totalLines = 0;
	size_t i = 0;

	while (i < value.length())
	{
		assert(!m_lines.empty());

		if (value[i] == '\r')
		{
			// skip
			++i;
		}
		else if (value[i] == '\n')
		{
			if (cindex < (int)m_lines[position.line].glyphs.size())
			{
				Line& newLine = InsertLine(position.line + 1);
				Line& line = m_lines[position.line];
				newLine.glyphs.insert(newLine.glyphs.begin(), line.glyphs.begin() + cindex, line.glyphs.end());
				line.glyphs.erase(line.glyphs.begin() + cindex, line.glyphs.end());
			}
			else
			{
				InsertLine(position.line + 1);
			}

			++position.line;
			position.column = 0;
			cindex = 0;
			++totalLines;
			++i;
		}
		else
		{
			Line& line = m_lines[position.line];
			int d = UTF8CharLength(value[i]);

			while (d-- > 0 && i < value.length())
			{
				line.glyphs.emplace(line.glyphs.begin() + cindex++, value[i++], color);
			}

			position.column = GetCharacterColumn(position.line, cindex);
		}

		m_textChanged = true;
	}

	return totalLines;
}

void TextEditor::AddUndo(UndoRecord& value)
{
	assert(!m_readOnly);

	m_undoBuffer.resize((size_t)(m_undoIndex + 1));
	m_undoBuffer.back() = value;
	++m_undoIndex;
}

Coordinates TextEditor::ScreenPosToCoordinates(const ImVec2& position, bool insertionMode) const
{
	ImVec2 origin = ImGui::GetCursorScreenPos();
	ImVec2 local(position.x - origin.x + 3.0f, position.y - origin.y);
	float spaceSize = ImGui::GetFont()->CalcTextSizeA(ImGui::GetFontSize(), FLT_MAX, -1.0f, " ").x;

	int lineNo = std::max(0, (int)floor(local.y / m_charAdvance.y));
	int columnCoord = 0;

	if (lineNo >= 0 && lineNo < (int)m_lines.size())
	{
		const Line& line = m_lines.at(lineNo);

		float columnX = 0.0f;

		// First we find the hovered column coord.
		for (size_t columnIndex = 0; columnIndex < line.glyphs.size(); ++columnIndex)
		{
			float columnWidth = 0.0f;
			int delta = 0;

			if (line.glyphs[columnIndex].ch == '\t')
			{
				float oldX = columnX;

				columnX = (1.0f + std::floor((1.0f + columnX) / (float(m_tabSize) * spaceSize))) * (float(m_tabSize) * spaceSize);
				columnWidth = columnX - oldX;
				delta = columnCoord - (columnCoord / m_tabSize) * m_tabSize + m_tabSize;
			}
			else
			{
				char buf[7];
				int d = UTF8CharLength(line.glyphs[columnIndex].ch);
				int i = 0;

				while (i < 6 && d-- > 0)
					buf[i++] = line.glyphs[columnIndex].ch;
				buf[i] = '\0';
				columnWidth = ImGui::GetFont()->CalcTextSizeA(ImGui::GetFontSize(), FLT_MAX, -1.0f, buf).x;
				columnX += columnWidth;
				delta = 1;
			}

			if (m_textStart + columnX - (insertionMode ? 0.5f : 0.0f) * columnWidth < local.x)
				columnCoord += delta;
			else
				break;
		}

		// Then we reduce by 1 column coord if cursor is on the left side of the hovered column.
		//if (aInsertionMode && mTextStart + columnX - columnWidth * 2.0f < local.x)
		//	columnIndex = std::min((int)line.size() - 1, columnIndex + 1);
	}

	return SanitizeCoordinates(Coordinates(lineNo, columnCoord));
}

Coordinates TextEditor::FindWordStart(const Coordinates& fromPos) const
{
	Coordinates at = fromPos;
	if (at.line >= (int)m_lines.size())
		return at;

	const Line& line = m_lines[at.line];
	int cindex = GetCharacterIndex(at);

	if (cindex >= (int)line.glyphs.size())
		return at;

	while (cindex > 0 && isspace(line.glyphs[cindex].ch))
		--cindex;

	PaletteIndex cstart = line.glyphs[cindex].colorIndex;
	while (cindex > 0)
	{
		char c = line.glyphs[cindex].ch;
		if ((c & 0xC0) != 0x80)	// not UTF code sequence 10xxxxxx
		{
			if (c <= 32 && isspace(c))
			{
				cindex++;
				break;
			}

			if (cstart != line.glyphs[size_t(cindex - 1)].colorIndex)
				break;
		}

		--cindex;
	}

	return Coordinates(at.line, GetCharacterColumn(at.line, cindex));
}

Coordinates TextEditor::FindWordEnd(const Coordinates& fromPos) const
{
	Coordinates at = fromPos;
	if (at.line >= (int)m_lines.size())
		return at;

	const Line& line = m_lines[at.line];
	int cindex = GetCharacterIndex(at);

	if (cindex >= (int)line.glyphs.size())
		return at;

	bool prevspace = (bool)!!isspace(line.glyphs[cindex].ch);
	PaletteIndex cstart = line.glyphs[cindex].colorIndex;

	while (cindex < (int)line.glyphs.size())
	{
		char c = line.glyphs[cindex].ch;
		int d = UTF8CharLength(c);

		if (cstart != line.glyphs[cindex].colorIndex)
			break;

		if (prevspace != !!isspace(c))
		{
			if (isspace(c))
				while (cindex < (int)line.glyphs.size() && isspace(line.glyphs[cindex].ch))
					++cindex;
			break;
		}

		cindex += d;
	}

	return Coordinates(fromPos.line, GetCharacterColumn(fromPos.line, cindex));
}

Coordinates TextEditor::FindNextWord(const Coordinates& fromPos) const
{
	Coordinates at = fromPos;
	if (at.line >= (int)m_lines.size())
		return at;

	// skip to the next non-word character
	int cindex = GetCharacterIndex(fromPos);
	bool isword = false;
	bool skip = false;

	if (cindex < (int)m_lines[at.line].glyphs.size())
	{
		const Line& line = m_lines[at.line];
		isword = !!isalnum(line.glyphs[cindex].ch);
		skip = isword;
	}

	while (!isword || skip)
	{
		if (at.line >= (int)m_lines.size())
		{
			int l = std::max(0, (int)m_lines.size() - 1);
			return Coordinates(l, GetLineMaxColumn(l));
		}

		const Line& line = m_lines[at.line];
		if (cindex < (int)line.glyphs.size())
		{
			isword = isalnum(line.glyphs[cindex].ch);

			if (isword && !skip)
				return Coordinates(at.line, GetCharacterColumn(at.line, cindex));

			if (!isword)
				skip = false;

			cindex++;
		}
		else
		{
			cindex = 0;
			++at.line;
			skip = false;
			isword = false;
		}
	}

	return at;
}

int TextEditor::GetCharacterIndex(const Coordinates& coordinates) const
{
	if (coordinates.line >= (int)m_lines.size())
		return -1;

	const Line& line = m_lines[coordinates.line];
	int c = 0;
	int i = 0;

	for (; i < (int)line.glyphs.size() && c < coordinates.column;)
	{
		if (line.glyphs[i].ch == '\t')
			c = (c / m_tabSize) * m_tabSize + m_tabSize;
		else
			++c;
		i += UTF8CharLength(line.glyphs[i].ch);
	}

	return i;
}

int TextEditor::GetCharacterColumn(int lineNum, int index) const
{
	if (lineNum >= (int)m_lines.size())
		return 0;

	const Line& line = m_lines[lineNum];
	int col = 0;
	int i = 0;

	while (i < index && i < (int)line.glyphs.size())
	{
		char c = line.glyphs[i].ch;
		i += UTF8CharLength(c);

		if (c == '\t')
			col = (col / m_tabSize) * m_tabSize + m_tabSize;
		else
			col++;
	}

	return col;
}

int TextEditor::GetLineCharacterCount(int lineNum) const
{
	if (lineNum >= (int)m_lines.size())
		return 0;

	const Line& line = m_lines[lineNum];
	int c = 0;

	for (unsigned i = 0; i < line.glyphs.size(); c++)
		i += UTF8CharLength(line.glyphs[i].ch);

	return c;
}

int TextEditor::GetLineMaxColumn(int lineNum) const
{
	if (lineNum >= (int)m_lines.size())
		return 0;

	const Line& line = m_lines[lineNum];
	int col = 0;

	for (unsigned i = 0; i < line.glyphs.size(); )
	{
		char c = line.glyphs[i].ch;

		if (c == '\t')
			col = (col / m_tabSize) * m_tabSize + m_tabSize;
		else
			col++;

		i += UTF8CharLength(c);
	}
	return col;
}

bool TextEditor::IsOnWordBoundary(const Coordinates& pos) const
{
	if (pos.line >= (int)m_lines.size() || pos.column == 0)
		return true;

	const Line& line = m_lines[pos.line];
	int cindex = GetCharacterIndex(pos);

	if (cindex >= (int)line.glyphs.size())
		return true;

	if (m_colorizerEnabled)
		return line.glyphs[cindex].colorIndex != line.glyphs[size_t(cindex - 1)].colorIndex;

	return isspace(line.glyphs[cindex].ch) != isspace(line.glyphs[cindex - 1].ch);
}

void TextEditor::RemoveLine(int start, int end)
{
	assert(!m_readOnly);
	assert(end >= start);
	assert(m_lines.size() > (size_t)(end - start));

	ErrorMarkers etmp;
	for (auto& [line, msg] : m_errorMarkers)
	{
		ErrorMarkers::value_type e(line >= start ? line - 1 : line, std::move(msg));
		if (line >= start && line <= end)
			continue;
		etmp.insert(std::move(e));
	}
	m_errorMarkers = std::move(etmp);

	Breakpoints btmp;
	for (int bpLine : m_breakPoints)
	{
		if (bpLine >= start && bpLine <= end)
			continue;
		btmp.insert(bpLine >= start ? bpLine - 1 : bpLine);
	}
	m_breakPoints = std::move(btmp);

	m_lines.erase(m_lines.begin() + start, m_lines.begin() + end);
	assert(!m_lines.empty());

	m_textChanged = true;
}

void TextEditor::RemoveLine(int lineIndex)
{
	assert(!m_readOnly);
	assert(m_lines.size() > 1);

	ErrorMarkers etmp;
	for (auto& [line, msg] : m_errorMarkers)
	{
		ErrorMarkers::value_type e(line > lineIndex ? line - 1 : line, std::move(msg));
		if (line - 1 == lineIndex)
			continue;
		etmp.insert(std::move(e));
	}
	m_errorMarkers = std::move(etmp);

	Breakpoints btmp;
	for (int bpLine : m_breakPoints)
	{
		if (bpLine == lineIndex)
			continue;
		btmp.insert(bpLine >= lineIndex ? bpLine - 1 : bpLine);
	}
	m_breakPoints = std::move(btmp);

	m_lines.erase(m_lines.begin() + lineIndex);
	assert(!m_lines.empty());

	m_textChanged = true;
}

Line& TextEditor::InsertLine(int index)
{
	//assert(!mReadOnly);

	Line& result = *m_lines.emplace(m_lines.begin() + index);

	ErrorMarkers etmp;
	for (auto& [line, msg] : m_errorMarkers)
		etmp.emplace(line >= index ? line + 1 : line, std::move(msg));
	m_errorMarkers = std::move(etmp);

	Breakpoints btmp;
	for (int bpLine : m_breakPoints)
		btmp.insert(bpLine >= index ? bpLine + 1 : bpLine);
	m_breakPoints = std::move(btmp);

	return result;
}

std::string TextEditor::GetWordUnderCursor() const
{
	Coordinates c = GetCursorPosition();
	return GetWordAt(c);
}

std::string TextEditor::GetWordAt(const Coordinates& pos) const
{
	Coordinates start = FindWordStart(pos);
	Coordinates end = FindWordEnd(pos);

	std::string r;

	int istart = GetCharacterIndex(start);
	int iend = GetCharacterIndex(end);

	for (int it = istart; it < iend; ++it)
		r.push_back(m_lines[pos.line].glyphs[it].ch);

	return r;
}

ImU32 TextEditor::GetGlyphColor(const Glyph& glyph) const
{
	if (!m_colorizerEnabled)
		return m_palette[(int)PaletteIndex::Default];
	if (glyph.rawColor)
		return glyph.argbColor;
	if (glyph.comment)
		return m_palette[(int)PaletteIndex::Comment];
	if (glyph.multlineComment)
		return m_palette[(int)PaletteIndex::MultiLineComment];

	const ImU32 color = m_palette[(int)glyph.colorIndex];
	if (glyph.preprocessor)
	{
		const ImU32 ppcolor = m_palette[(int)PaletteIndex::Preprocessor];
		const int c0 = ((ppcolor & 0xff) + (color & 0xff)) / 2;
		const int c1 = (((ppcolor >> 8) & 0xff) + ((color >> 8) & 0xff)) / 2;
		const int c2 = (((ppcolor >> 16) & 0xff) + ((color >> 16) & 0xff)) / 2;
		const int c3 = (((ppcolor >> 24) & 0xff) + ((color >> 24) & 0xff)) / 2;
		return ImU32(c0 | (c1 << 8) | (c2 << 16) | (c3 << 24));
	}

	return color;
}

void TextEditor::HandleKeyboardInputs()
{
	if (ImGui::IsWindowFocused())
	{
		if (ImGui::IsWindowHovered())
			ImGui::SetMouseCursor(ImGuiMouseCursor_TextInput);
		//ImGui::CaptureKeyboardFromApp(true);

		ImGuiIO& io = ImGui::GetIO();
		bool isOSX = io.ConfigMacOSXBehaviors;
		bool alt = io.KeyAlt;
		bool ctrl = io.KeyCtrl;
		bool shift = io.KeyShift;
		bool super = io.KeySuper;

		bool isShortcut = (isOSX ? (super && !ctrl) : (ctrl && !super)) && !alt && !shift;
		bool isShiftShortcut = (isOSX ? (super && !ctrl) : (ctrl && !super)) && shift && !alt;
		bool isWordmoveKey = isOSX ? alt : ctrl;
		bool isAltOnly = alt && !ctrl && !shift && !super;
		bool isCtrlOnly = ctrl && !alt && !shift && !super;
		bool isShiftOnly = shift && !alt && !ctrl && !super;

		io.WantCaptureKeyboard = true;
		io.WantTextInput = true;

		if (!IsReadOnly() && isShortcut && ImGui::IsKeyPressed(ImGuiKey_Z))
			Undo();
		else if (!IsReadOnly() && isAltOnly && ImGui::IsKeyPressed(ImGuiKey_Backspace))
			Undo();
		else if (!IsReadOnly() && isShortcut && ImGui::IsKeyPressed(ImGuiKey_Y))
			Redo();
		else if (!IsReadOnly() && isShiftShortcut && ImGui::IsKeyPressed(ImGuiKey_Z))
			Redo();
		else if (!alt && !ctrl && !super && ImGui::IsKeyPressed(ImGuiKey_UpArrow))
			MoveUp(1, shift);
		else if (!alt && !ctrl && !super && ImGui::IsKeyPressed(ImGuiKey_DownArrow))
			MoveDown(1, shift);
		else if ((isOSX ? !ctrl : !alt) && !super && ImGui::IsKeyPressed(ImGuiKey_LeftArrow))
			MoveLeft(1, shift, isWordmoveKey);
		else if ((isOSX ? !ctrl : !alt) && !super && ImGui::IsKeyPressed(ImGuiKey_RightArrow))
			MoveRight(1, shift, isWordmoveKey);
		else if (!alt && !ctrl && !super && ImGui::IsKeyPressed(ImGuiKey_PageUp))
			MoveUp(GetPageSize() - 4, shift);
		else if (!alt && !ctrl && !super && ImGui::IsKeyPressed(ImGuiKey_PageDown))
			MoveDown(GetPageSize() - 4, shift);
		else if (ctrl && !alt && !super && ImGui::IsKeyPressed(ImGuiKey_Home))
			MoveTop(shift);
		else if (ctrl && !alt && !super && ImGui::IsKeyPressed(ImGuiKey_End))
			MoveBottom(shift);
		else if (!alt && !ctrl && !super && ImGui::IsKeyPressed(ImGuiKey_Home))
			MoveHome(shift);
		else if (!alt && !ctrl && !super && ImGui::IsKeyPressed(ImGuiKey_End))
			MoveEnd(shift);
		else if (!IsReadOnly() && !alt && !ctrl && !shift && !super && ImGui::IsKeyPressed(ImGuiKey_Delete))
			Delete();
		else if (!IsReadOnly() && !alt && !ctrl && !shift && !super && ImGui::IsKeyPressed(ImGuiKey_Backspace))
			Backspace();
		else if (!alt && !ctrl && !shift && !super && ImGui::IsKeyPressed(ImGuiKey_Insert))
			m_overwrite ^= true;
		else if (isCtrlOnly && ImGui::IsKeyPressed(ImGuiKey_Insert))
			Copy();
		else if (isShortcut && ImGui::IsKeyPressed(ImGuiKey_C))
			Copy();
		else if (!IsReadOnly() && isShiftOnly && ImGui::IsKeyPressed(ImGuiKey_Insert))
			Paste();
		else if (!IsReadOnly() && isShortcut && ImGui::IsKeyPressed(ImGuiKey_V))
			Paste();
		else if (isShortcut && ImGui::IsKeyPressed(ImGuiKey_X))
			Cut();
		else if (isShiftOnly && ImGui::IsKeyPressed(ImGuiKey_Delete))
			Cut();
		else if (isShortcut && ImGui::IsKeyPressed(ImGuiKey_A))
			SelectAll();
		else if (!IsReadOnly() && !alt && !ctrl && !shift && !super && ImGui::IsKeyPressed(ImGuiKey_Enter))
			EnterCharacter('\n', false);
		else if (!IsReadOnly() && !alt && !ctrl && !super && ImGui::IsKeyPressed(ImGuiKey_Tab))
			EnterCharacter('\t', shift);
		if (!IsReadOnly() && !io.InputQueueCharacters.empty() && !ctrl && !super)
		{
			for (int i = 0; i < io.InputQueueCharacters.Size; i++)
			{
				ImWchar c = io.InputQueueCharacters[i];
				if (c != 0 && (c == '\n' || c >= 32))
					EnterCharacter(c, shift);
			}

			io.InputQueueCharacters.resize(0);
		}
	}
}

void TextEditor::HandleMouseInputs()
{
	ImGuiIO& io = ImGui::GetIO();

	bool shift = io.KeyShift;
	bool ctrl = io.ConfigMacOSXBehaviors ? io.KeySuper : io.KeyCtrl;
	bool alt = io.ConfigMacOSXBehaviors ? io.KeyCtrl : io.KeyAlt;

	if (ImGui::IsWindowHovered())
	{
		if (!shift && !alt)
		{
			bool click = ImGui::IsMouseClicked(0);
			bool doubleClick = ImGui::IsMouseDoubleClicked(0);
			double t = ImGui::GetTime();
			bool tripleClick = click && !doubleClick && (m_lastClick != -1.0f && (t - m_lastClick) < io.MouseDoubleClickTime);

			// Left mouse button triple click
			if (tripleClick)
			{
				if (!ctrl)
				{
					m_state.cursorPosition = m_interactiveStart = m_interactiveEnd = SanitizeCoordinates(ScreenPosToCoordinates(ImGui::GetMousePos()));
					m_selectionMode = SelectionMode::Line;
					SetSelection(m_interactiveStart, m_interactiveEnd, m_selectionMode);
				}

				m_lastClick = -1.0f;
			}

			// Left mouse button double click
			else if (doubleClick)
			{
				if (!ctrl)
				{
					m_state.cursorPosition = m_interactiveStart = m_interactiveEnd = SanitizeCoordinates(ScreenPosToCoordinates(ImGui::GetMousePos()));
					if (m_selectionMode == SelectionMode::Line)
						m_selectionMode = SelectionMode::Normal;
					else
						m_selectionMode = SelectionMode::Word;
					SetSelection(m_interactiveStart, m_interactiveEnd, m_selectionMode);
				}

				m_lastClick = (float)ImGui::GetTime();
			}

			// Left mouse button click
			else if (click)
			{
				m_state.cursorPosition = m_interactiveStart = m_interactiveEnd = SanitizeCoordinates(ScreenPosToCoordinates(ImGui::GetMousePos(), !m_overwrite));
				if (ctrl)
					m_selectionMode = SelectionMode::Word;
				else
					m_selectionMode = SelectionMode::Normal;
				SetSelection(m_interactiveStart, m_interactiveEnd, m_selectionMode);

				m_lastClick = (float)ImGui::GetTime();
			}

			// Mouse left button dragging (=> update selection)
			else if (ImGui::IsMouseDragging(0) && ImGui::IsMouseDown(0))
			{
				io.WantCaptureMouse = true;
				m_state.cursorPosition = m_interactiveEnd = SanitizeCoordinates(ScreenPosToCoordinates(ImGui::GetMousePos(), !m_overwrite));
				SetSelection(m_interactiveStart, m_interactiveEnd, m_selectionMode);
			}
		}
	}
}

void TextEditor::Render()
{
	// Compute mCharAdvance regarding to scaled font size (Ctrl + mouse wheel)
	const float fontSize = ImGui::GetFont()->CalcTextSizeA(ImGui::GetFontSize(), FLT_MAX, -1.0f, "#", nullptr, nullptr).x;
	m_charAdvance = ImVec2(fontSize, ImGui::GetTextLineHeightWithSpacing() * m_lineSpacing);

	// Update palette with the current alpha from style
	for (int i = 0; i < (int)PaletteIndex::Max; ++i)
	{
		ImVec4 color = ImGui::ColorConvertU32ToFloat4(m_paletteBase[i]);
		color.w *= ImGui::GetStyle().Alpha;
		m_palette[i] = ImGui::ColorConvertFloat4ToU32(color);
	}

	assert(m_lineBuffer.empty());

	ImVec2 contentSize = ImGui::GetWindowContentRegionMax();
	ImDrawList* drawList = ImGui::GetWindowDrawList();
	float longest = m_textStart;

	if (m_scrollToTop)
	{
		m_scrollToTop = false;
		ImGui::SetScrollY(0.f);
	}

	ImVec2 cursorScreenPos = ImGui::GetCursorScreenPos();
	float scrollX = ImGui::GetScrollX();
	float scrollY = ImGui::GetScrollY();

	int lineNo = (int)floor(scrollY / m_charAdvance.y);
	int globalLineMax = (int)m_lines.size();
	int lineMax = std::max(0, std::min((int)m_lines.size() - 1, lineNo + (int)floor((scrollY + contentSize.y) / m_charAdvance.y)));

	// Deduce m_textStart by evaluating mLines size (global lineMax) plus two spaces as text width
	float lineNoWidth = 0.0f;
	char buf[16];

	if (m_renderLineNumbers)
	{
		snprintf(buf, 16, " %d ", globalLineMax);

		lineNoWidth = ImGui::GetFont()->CalcTextSizeA(ImGui::GetFontSize(), FLT_MAX, -1.0f, buf, nullptr, nullptr).x;
		m_leftMargin = 10;
	}
	else
	{
		m_leftMargin = 5;
	}

	m_textStart = lineNoWidth + m_leftMargin;

	if (!m_lines.empty())
	{
		float spaceSize = ImGui::GetFont()->CalcTextSizeA(ImGui::GetFontSize(), FLT_MAX, -1.0f, " ", nullptr, nullptr).x;

		while (lineNo <= lineMax)
		{
			ImVec2 lineStartScreenPos{ cursorScreenPos.x, cursorScreenPos.y + lineNo * m_charAdvance.y };
			ImVec2 textScreenPos{ lineStartScreenPos.x + m_textStart, lineStartScreenPos.y };

			Line& line = m_lines[lineNo];
			longest = std::max(m_textStart + TextDistanceToLineStart(Coordinates(lineNo, GetLineMaxColumn(lineNo))), longest);
			int columnNo = 0;
			Coordinates lineStartCoord(lineNo, 0);
			Coordinates lineEndCoord(lineNo, GetLineMaxColumn(lineNo));

			// Draw selection for the current line
			float sstart = -1.0f;
			float ssend = -1.0f;

			assert(m_state.selectionStart <= m_state.selectionEnd);
			if (m_state.selectionStart <= lineEndCoord)
				sstart = m_state.selectionStart > lineStartCoord ? TextDistanceToLineStart(m_state.selectionStart) : 0.0f;
			if (m_state.selectionEnd > lineStartCoord)
				ssend = TextDistanceToLineStart(m_state.selectionEnd < lineEndCoord ? m_state.selectionEnd : lineEndCoord);

			if (m_state.selectionEnd.line > lineNo)
				ssend += m_charAdvance.x;

			if (sstart != -1 && ssend != -1 && sstart < ssend)
			{
				ImVec2 vstart{ lineStartScreenPos.x + m_textStart + sstart, lineStartScreenPos.y };
				ImVec2 vend{ lineStartScreenPos.x + m_textStart + ssend, lineStartScreenPos.y + m_charAdvance.y };
				drawList->AddRectFilled(vstart, vend, m_palette[(int)PaletteIndex::Selection]);
			}

			// Draw breakpoints
			ImVec2 start{ lineStartScreenPos.x + scrollX, lineStartScreenPos.y };

			if (m_breakPoints.count(lineNo + 1) != 0)
			{
				ImVec2 end{ lineStartScreenPos.x + contentSize.x + 2.0f * scrollX, lineStartScreenPos.y + m_charAdvance.y };
				drawList->AddRectFilled(start, end, m_palette[(int)PaletteIndex::Breakpoint]);
			}

			// Draw error markers
			auto errorIt = m_errorMarkers.find(lineNo + 1);
			if (errorIt != m_errorMarkers.end())
			{
				ImVec2 end{ lineStartScreenPos.x + contentSize.x + 2.0f * scrollX, lineStartScreenPos.y + m_charAdvance.y };
				drawList->AddRectFilled(start, end, m_palette[(int)PaletteIndex::ErrorMarker]);

				if (ImGui::IsMouseHoveringRect(lineStartScreenPos, end))
				{
					ImGui::BeginTooltip();
					ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.2f, 0.2f, 1.0f));
					ImGui::Text("Error at line %d:", errorIt->first);
					ImGui::PopStyleColor();
					ImGui::Separator();
					ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 0.2f, 1.0f));
					ImGui::Text("%s", errorIt->second.c_str());
					ImGui::PopStyleColor();
					ImGui::EndTooltip();
				}
			}

			// Draw line number (right aligned)
			if (m_renderLineNumbers)
			{
				snprintf(buf, 16, "%d  ", lineNo + 1);

				float lineNoWidth = ImGui::GetFont()->CalcTextSizeA(ImGui::GetFontSize(), FLT_MAX, -1.0f, buf, nullptr, nullptr).x;
				drawList->AddText(ImVec2{ lineStartScreenPos.x + m_textStart - lineNoWidth, lineStartScreenPos.y }, m_palette[(int)PaletteIndex::LineNumber], buf);
			}

			if (m_state.cursorPosition.line == lineNo && m_renderCursor)
			{
				bool focused = ImGui::IsWindowFocused();

				// Highlight the current line (where the cursor is)
				if (!HasSelection())
				{
					ImVec2 end{ start.x + contentSize.x + scrollX, start.y + m_charAdvance.y };
					drawList->AddRectFilled(start, end, m_palette[(int)(focused ? PaletteIndex::CurrentLineFill : PaletteIndex::CurrentLineFillInactive)]);
					drawList->AddRect(start, end, m_palette[(int)PaletteIndex::CurrentLineEdge], 1.0f);
				}

				// Render the cursor
				if (focused)
				{
					auto timeEnd = std::chrono::steady_clock::now();
					auto elapsed = timeEnd - m_startTime;

					if (elapsed > 400ms)
					{
						float width = 1.0f;
						int cindex = GetCharacterIndex(m_state.cursorPosition);
						float cx = TextDistanceToLineStart(m_state.cursorPosition);

						if (m_overwrite && cindex < (int)line.glyphs.size())
						{
							char c = line.glyphs[cindex].ch;
							if (c == '\t')
							{
								float x = (1.0f + std::floor((1.0f + cx) / (float(m_tabSize) * spaceSize))) * (float(m_tabSize) * spaceSize);
								width = x - cx;
							}
							else
							{
								char buf2[2];
								buf2[0] = line.glyphs[cindex].ch;
								buf2[1] = '\0';
								width = ImGui::GetFont()->CalcTextSizeA(ImGui::GetFontSize(), FLT_MAX, -1.0f, buf2).x;
							}
						}

						ImVec2 cstart{ textScreenPos.x + cx, lineStartScreenPos.y };
						ImVec2 cend{ textScreenPos.x + cx + width, lineStartScreenPos.y + m_charAdvance.y };

						drawList->AddRectFilled(cstart, cend, m_palette[(int)PaletteIndex::Cursor]);
						if (elapsed > 800ms)
							m_startTime = timeEnd;
					}
				}
			}

			// Render colorized text
			ImU32 prevColor = line.glyphs.empty() ? m_palette[(int)PaletteIndex::Default] : GetGlyphColor(line.glyphs[0]);
			ImVec2 bufferOffset;

			for (int i = 0; i < (int)line.glyphs.size();)
			{
				Glyph& glyph = line.glyphs[i];
				ImU32 color = GetGlyphColor(glyph);

				if ((color != prevColor || glyph.ch == '\t' || glyph.ch == ' ') && !m_lineBuffer.empty())
				{
					const ImVec2 newOffset{ textScreenPos.x + bufferOffset.x, textScreenPos.y + bufferOffset.y };
					drawList->AddText(newOffset, prevColor, m_lineBuffer.c_str());

					ImVec2 textSize = ImGui::GetFont()->CalcTextSizeA(ImGui::GetFontSize(), FLT_MAX, -1.0f, m_lineBuffer.c_str(), nullptr, nullptr);
					bufferOffset.x += textSize.x;
					m_lineBuffer.clear();
				}

				prevColor = color;

				if (glyph.ch == '\t')
				{
					float oldX = bufferOffset.x;
					bufferOffset.x = (1.0f + std::floor((1.0f + bufferOffset.x) / (float(m_tabSize) * spaceSize))) * (float(m_tabSize) * spaceSize);
					++i;

					if (m_showWhitespace)
					{
						ImVec2 p1, p2, p3, p4;

						if (m_showShortTabGlyphs)
						{
							const float s = ImGui::GetFontSize();
							const float x1 = textScreenPos.x + oldX + 1.0f;
							const float x2 = textScreenPos.x + oldX + m_charAdvance.x - 1.0f;
							const float y = textScreenPos.y + bufferOffset.y + s * 0.5f;

							p1 = ImVec2(x1, y);
							p2 = ImVec2(x2, y);
							p3 = ImVec2(x2 - s * 0.16f, y - s * 0.16f);
							p4 = ImVec2(x2 - s * 0.16f, y + s * 0.16f);
						}
						else
						{
							const float s = ImGui::GetFontSize();
							const float x1 = textScreenPos.x + oldX + 1.0f;
							const float x2 = textScreenPos.x + bufferOffset.x - 1.0f;
							const float y = textScreenPos.y + bufferOffset.y + s * 0.5f;

							p1 = ImVec2(x1, y);
							p2 = ImVec2(x2, y);
							p3 = ImVec2(x2 - s * 0.2f, y - s * 0.2f);
							p4 = ImVec2(x2 - s * 0.2f, y + s * 0.2f);
						}

						drawList->AddLine(p1, p2, 0x90909090);
						drawList->AddLine(p2, p3, 0x90909090);
						drawList->AddLine(p2, p4, 0x90909090);
					}
				}
				else if (glyph.ch == ' ')
				{
					if (m_showWhitespace)
					{
						const float s = ImGui::GetFontSize();
						const float x = textScreenPos.x + bufferOffset.x + spaceSize * 0.5f;
						const float y = textScreenPos.y + bufferOffset.y + s * 0.5f;
						drawList->AddCircleFilled(ImVec2(x, y), 1.5f, 0x80808080, 4);
					}

					bufferOffset.x += spaceSize;
					i++;
				}
				else
				{
					int l = UTF8CharLength(glyph.ch);
					while (l-- > 0)
						m_lineBuffer.push_back(line.glyphs[i++].ch);
				}

				++columnNo;
			}

			if (!m_lineBuffer.empty())
			{
				const ImVec2 newOffset(textScreenPos.x + bufferOffset.x, textScreenPos.y + bufferOffset.y);
				drawList->AddText(newOffset, prevColor, m_lineBuffer.c_str());
				m_lineBuffer.clear();
			}

			++lineNo;
		}

		// Draw a tooltip on known identifiers/preprocessor symbols
		if (ImGui::IsMousePosValid())
		{
			ImVec2 mpos = ImGui::GetMousePos();
			ImVec2 origin = ImGui::GetCursorScreenPos();
			ImVec2 local(mpos.x - origin.x, mpos.y - origin.y);

			if (local.x >= m_textStart)
			{
				Coordinates pos = ScreenPosToCoordinates(mpos);
				std::string id = GetWordAt(pos);

				if (!id.empty() && m_languageDefinition.enabled)
				{
					auto it = m_languageDefinition.identifiers.find(id);
					if (it != m_languageDefinition.identifiers.end())
					{
						ImGui::BeginTooltip();
						ImGui::TextUnformatted(it->second.declaration.c_str());
						ImGui::EndTooltip();
					}
					else
					{
						auto pi = m_languageDefinition.preprocIdentifiers.find(id);
						if (pi != m_languageDefinition.preprocIdentifiers.end())
						{
							ImGui::BeginTooltip();
							ImGui::TextUnformatted(pi->second.declaration.c_str());
							ImGui::EndTooltip();
						}
					}
				}
			}
		}
	}

	ImGui::Dummy(ImVec2((longest + 2), m_lines.size() * m_charAdvance.y));

	if (m_scrollToCursor)
	{
		EnsureCursorVisible();
		if (!m_readOnly)
			ImGui::SetWindowFocus();
		m_scrollToCursor = false;
	}
}

void TextEditor::Render(const char* title, const ImVec2& size, bool border)
{
	m_withinRender = true;
	m_textChanged = false;
	m_cursorPositionChanged = false;

	ImGui::PushFont(mq::imgui::ConsoleFont);
	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertU32ToFloat4(m_palette[(int)PaletteIndex::Background]));
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));
	if (!m_ignoreImGuiChild)
		ImGui::BeginChild(title, size, border, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_NoMove);

	if (m_handleKeyboardInputs)
	{
		HandleKeyboardInputs();
		ImGui::PushItemFlag(ImGuiItemFlags_NoTabStop, false);
	}

	if (m_handleMouseInputs)
		HandleMouseInputs();

	ColorizeInternal();
	Render();

	if (m_handleKeyboardInputs)
		ImGui::PopItemFlag();

	if (!m_ignoreImGuiChild)
		ImGui::EndChild();

	ImGui::PopStyleVar();
	ImGui::PopStyleColor();
	ImGui::PopFont();

	m_withinRender = false;
}

void TextEditor::SetText(std::string_view text, ImU32 color)
{
	m_lines.clear();
	m_lines.emplace_back();

	for (char chr : text)
	{
		if (chr == '\r')
		{
			// ignore the carriage return character
		}
		else if (chr == '\n')
		{
			m_lines.emplace_back();
		}
		else
		{
			m_lines.back().glyphs.emplace_back(chr, color);
		}
	}

	m_textChanged = true;
	m_scrollToTop = true;

	m_undoBuffer.clear();
	m_undoIndex = 0;

	Colorize();
}

void TextEditor::SetText(std::string_view text)
{
	m_lines.clear();
	m_lines.emplace_back();

	for (char chr : text)
	{
		if (chr == '\r')
		{
			// ignore the carriage return character
		}
		else if (chr == '\n')
		{
			m_lines.emplace_back();
		}
		else
		{
			m_lines.back().glyphs.emplace_back(chr, PaletteIndex::Default);
		}
	}

	m_textChanged = true;
	m_scrollToTop = true;

	m_undoBuffer.clear();
	m_undoIndex = 0;

	Colorize();
}

void TextEditor::SetTextLines(const std::vector<std::string>& lines)
{
	m_lines.clear();

	if (lines.empty())
	{
		m_lines.emplace_back();
	}
	else
	{
		m_lines.resize(lines.size());

		for (size_t i = 0; i < lines.size(); ++i)
		{
			const std::string& line = lines[i];
			Line& destLine = m_lines[i];
			destLine.glyphs.reserve(line.size());

			for (char ch : line)
			{
				destLine.glyphs.emplace_back(ch, PaletteIndex::Default);
			}
		}
	}

	m_textChanged = true;
	m_scrollToTop = true;

	m_undoBuffer.clear();
	m_undoIndex = 0;

	Colorize();
}

void TextEditor::EnterCharacter(ImWchar ch, bool shift)
{
	assert(!m_readOnly);

	UndoRecord u;
	u.before = m_state;

	if (HasSelection())
	{
		if (ch == '\t' && m_state.selectionStart.line != m_state.selectionEnd.line)
		{
			Coordinates start = m_state.selectionStart;
			Coordinates end = m_state.selectionEnd;
			Coordinates originalEnd = end;

			if (start > end)
				std::swap(start, end);
			start.column = 0;
			if (end.column == 0 && end.line > 0)
				--end.line;
			if (end.line >= (int)m_lines.size())
				end.line = m_lines.empty() ? 0 : (int)m_lines.size() - 1;
			end.column = GetLineMaxColumn(end.line);

			u.removedStart = start;
			u.removedEnd = end;
			u.removed = GetText(start, end);

			bool modified = false;

			for (int i = start.line; i <= end.line; i++)
			{
				Line& line = m_lines[i];

				if (shift)
				{
					if (!line.glyphs.empty())
					{
						if (line.glyphs.front().ch == '\t')
						{
							line.glyphs.erase(line.glyphs.begin());
							modified = true;
						}
						else
						{
							for (int j = 0; j < m_tabSize && !line.glyphs.empty() && line.glyphs.front().ch == ' '; j++)
							{
								line.glyphs.erase(line.glyphs.begin());
								modified = true;
							}
						}
					}
				}
				else
				{
					line.glyphs.emplace(line.glyphs.begin(), '\t', PaletteIndex::Background);
					modified = true;
				}
			}

			if (modified)
			{
				start = Coordinates(start.line, GetCharacterColumn(start.line, 0));

				Coordinates rangeEnd;
				if (originalEnd.column != 0)
				{
					end = Coordinates(end.line, GetLineMaxColumn(end.line));
					rangeEnd = end;
					u.added = GetText(start, end);
				}
				else
				{
					end = Coordinates(originalEnd.line, 0);
					rangeEnd = Coordinates(end.line - 1, GetLineMaxColumn(end.line - 1));
					u.added = GetText(start, rangeEnd);
				}

				u.addedStart = start;
				u.addedEnd = rangeEnd;
				u.after = m_state;

				m_state.selectionStart = start;
				m_state.selectionEnd = end;
				AddUndo(u);

				m_textChanged = true;

				EnsureCursorVisible();
			}

			return;
		} // c == '\t'
		else
		{
			u.removed = GetSelectedText();
			u.removedStart = m_state.selectionStart;
			u.removedEnd = m_state.selectionEnd;
			DeleteSelection();
		}
	} // HasSelection

	Coordinates coord = GetActualCursorCoordinates();
	u.addedStart = coord;

	assert(!m_lines.empty());

	if (ch == '\n')
	{
		InsertLine(coord.line + 1);
		Line& line = m_lines[coord.line];
		Line& newLine = m_lines[coord.line + 1];

		if (m_languageDefinition.autoIndentation)
		{
			for (size_t it = 0; it < line.glyphs.size() && isascii(line.glyphs[it].ch) && isblank(line.glyphs[it].ch); ++it)
				newLine.glyphs.push_back(line.glyphs[it]);
		}

		const size_t whitespaceSize = newLine.glyphs.size();
		int cindex = GetCharacterIndex(coord);
		newLine.glyphs.insert(newLine.glyphs.end(), line.glyphs.begin() + cindex, line.glyphs.end());
		line.glyphs.erase(line.glyphs.begin() + cindex, line.glyphs.begin() + line.glyphs.size());
		SetCursorPosition(Coordinates(coord.line + 1, GetCharacterColumn(coord.line + 1, (int)whitespaceSize)));
		u.added = (char)ch;
	}
	else
	{
		char buf[7];
		int e = ImTextCharToUtf8(buf, 7, ch);
		if (e > 0)
		{
			buf[e] = '\0';
			Line& line = m_lines[coord.line];
			int cindex = GetCharacterIndex(coord);

			if (m_overwrite && cindex < (int)line.glyphs.size())
			{
				int d = UTF8CharLength(line.glyphs[cindex].ch);

				u.removedStart = m_state.cursorPosition;
				u.removedEnd = Coordinates(coord.line, GetCharacterColumn(coord.line, cindex + d));

				while (d-- > 0 && cindex < (int)line.glyphs.size())
				{
					u.removed += line.glyphs[cindex].ch;
					line.glyphs.erase(line.glyphs.begin() + cindex);
				}
			}

			for (char* p = buf; *p != '\0'; p++, ++cindex)
			{
				line.glyphs.emplace(line.glyphs.begin() + cindex, *p, PaletteIndex::Default);
			}
			u.added = buf;

			SetCursorPosition(Coordinates(coord.line, GetCharacterColumn(coord.line, cindex)));
		}
		else
			return;
	}

	m_textChanged = true;

	u.addedEnd = GetActualCursorCoordinates();
	u.after = m_state;

	AddUndo(u);

	Colorize(coord.line - 1, 3);
	EnsureCursorVisible();
}

void TextEditor::SetReadOnly(bool value)
{
	m_readOnly = value;
}

void TextEditor::SetColorizerEnable(bool value)
{
	m_colorizerEnabled = value;
}

void TextEditor::SetCursorPosition(const Coordinates& position)
{
	if (m_state.cursorPosition != position)
	{
		m_state.cursorPosition = position;
		m_cursorPositionChanged = true;
		EnsureCursorVisible();
	}
}

void TextEditor::SetSelectionStart(const Coordinates& position)
{
	m_state.selectionStart = SanitizeCoordinates(position);
	if (m_state.selectionStart > m_state.selectionEnd)
		std::swap(m_state.selectionStart, m_state.selectionEnd);
}

void TextEditor::SetSelectionEnd(const Coordinates& position)
{
	m_state.selectionEnd = SanitizeCoordinates(position);
	if (m_state.selectionStart > m_state.selectionEnd)
		std::swap(m_state.selectionStart, m_state.selectionEnd);
}

void TextEditor::SetSelection(const Coordinates& startPos, const Coordinates& endPos, SelectionMode mode)
{
	Coordinates oldSelStart = m_state.selectionStart;
	Coordinates oldSelEnd = m_state.selectionEnd;

	m_state.selectionStart = SanitizeCoordinates(startPos);
	m_state.selectionEnd = SanitizeCoordinates(endPos);
	if (m_state.selectionStart > m_state.selectionEnd)
		std::swap(m_state.selectionStart, m_state.selectionEnd);

	switch (mode)
	{
	case SelectionMode::Normal:
		break;
	case SelectionMode::Word:
	{
		m_state.selectionStart = FindWordStart(m_state.selectionStart);
		if (!IsOnWordBoundary(m_state.selectionEnd))
			m_state.selectionEnd = FindWordEnd(FindWordStart(m_state.selectionEnd));
		break;
	}
	case SelectionMode::Line:
	{
		const int lineNo = m_state.selectionEnd.line;
		const size_t lineSize = (size_t)lineNo < m_lines.size() ? m_lines[lineNo].glyphs.size() : 0;

		m_state.selectionStart = Coordinates(m_state.selectionStart.line, 0);
		m_state.selectionEnd = Coordinates(lineNo, GetLineMaxColumn(lineNo));
		break;
	}
	default:
		break;
	}

	if (m_state.selectionStart != oldSelStart || m_state.selectionEnd != oldSelEnd)
		m_cursorPositionChanged = true;
}

void TextEditor::SetTabSize(int value)
{
	m_tabSize = std::clamp(value, 0, 32);
}

void TextEditor::InsertText(std::string_view value)
{
	if (value.empty())
		return;

	Coordinates pos = GetActualCursorCoordinates();
	Coordinates start = std::min(pos, m_state.selectionStart);
	int totalLines = pos.line - start.line;

	totalLines += InsertTextAt(pos, value);

	SetSelection(pos, pos);
	SetCursorPosition(pos);
	Colorize(start.line - 1, totalLines + 2);
}

void TextEditor::InsertText(std::string_view value, ImU32 color)
{
	if (value.empty())
		return;

	Coordinates pos = GetActualCursorCoordinates();
	Coordinates start = std::min(pos, m_state.selectionStart);
	int totalLines = pos.line - start.line;

	totalLines += InsertTextAt(pos, value, color);

	SetSelection(pos, pos);
	SetCursorPosition(pos);
	Colorize(start.line - 1, totalLines + 2);
}

void TextEditor::DeleteSelection()
{
	assert(m_state.selectionEnd >= m_state.selectionStart);

	if (m_state.selectionEnd == m_state.selectionStart)
		return;

	DeleteRange(m_state.selectionStart, m_state.selectionEnd);

	SetSelection(m_state.selectionStart, m_state.selectionStart);
	SetCursorPosition(m_state.selectionStart);
	Colorize(m_state.selectionStart.line, 1);
}

void TextEditor::MoveUp(int amount, bool select)
{
	Coordinates oldPos = m_state.cursorPosition;
	m_state.cursorPosition.line = std::max(0, m_state.cursorPosition.line - amount);

	if (oldPos != m_state.cursorPosition)
	{
		if (select)
		{
			if (oldPos == m_interactiveStart)
				m_interactiveStart = m_state.cursorPosition;
			else if (oldPos == m_interactiveEnd)
				m_interactiveEnd = m_state.cursorPosition;
			else
			{
				m_interactiveStart = m_state.cursorPosition;
				m_interactiveEnd = oldPos;
			}
		}
		else
			m_interactiveStart = m_interactiveEnd = m_state.cursorPosition;

		SetSelection(m_interactiveStart, m_interactiveEnd);

		EnsureCursorVisible();
	}
}

void TextEditor::MoveDown(int amount, bool select)
{
	assert(m_state.cursorPosition.column >= 0);

	Coordinates oldPos = m_state.cursorPosition;
	m_state.cursorPosition.line = std::max(0, std::min((int)m_lines.size() - 1, m_state.cursorPosition.line + amount));

	if (m_state.cursorPosition != oldPos)
	{
		if (select)
		{
			if (oldPos == m_interactiveEnd)
				m_interactiveEnd = m_state.cursorPosition;
			else if (oldPos == m_interactiveStart)
				m_interactiveStart = m_state.cursorPosition;
			else
			{
				m_interactiveStart = oldPos;
				m_interactiveEnd = m_state.cursorPosition;
			}
		}
		else
			m_interactiveStart = m_interactiveEnd = m_state.cursorPosition;

		SetSelection(m_interactiveStart, m_interactiveEnd);

		EnsureCursorVisible();
	}
}

static bool IsUTFSequence(char ch)
{
	return (ch & 0xC0) == 0x80;
}

void TextEditor::MoveLeft(int amount, bool select, bool wordMode)
{
	if (m_lines.empty())
		return;

	Coordinates oldPos = m_state.cursorPosition;
	m_state.cursorPosition = GetActualCursorCoordinates();
	int line = m_state.cursorPosition.line;
	int cindex = GetCharacterIndex(m_state.cursorPosition);

	while (amount-- > 0)
	{
		if (cindex == 0)
		{
			if (line > 0)
			{
				--line;
				if ((int)m_lines.size() > line)
					cindex = (int)m_lines[line].glyphs.size();
				else
					cindex = 0;
			}
		}
		else
		{
			--cindex;
			if (cindex > 0)
			{
				if ((int)m_lines.size() > line)
				{
					while (cindex > 0 && IsUTFSequence(m_lines[line].glyphs[cindex].ch))
						--cindex;
				}
			}
		}

		m_state.cursorPosition = Coordinates(line, GetCharacterColumn(line, cindex));
		if (wordMode)
		{
			m_state.cursorPosition = FindWordStart(m_state.cursorPosition);
			cindex = GetCharacterIndex(m_state.cursorPosition);
		}
	}

	m_state.cursorPosition = Coordinates(line, GetCharacterColumn(line, cindex));
	assert(m_state.cursorPosition.column >= 0);

	if (select)
	{
		if (oldPos == m_interactiveStart)
			m_interactiveStart = m_state.cursorPosition;
		else if (oldPos == m_interactiveEnd)
			m_interactiveEnd = m_state.cursorPosition;
		else
		{
			m_interactiveStart = m_state.cursorPosition;
			m_interactiveEnd = oldPos;
		}
	}
	else
		m_interactiveStart = m_interactiveEnd = m_state.cursorPosition;

	SetSelection(m_interactiveStart, m_interactiveEnd, select && wordMode ? SelectionMode::Word : SelectionMode::Normal);

	EnsureCursorVisible();
}

void TextEditor::MoveRight(int amount, bool select, bool wordMode)
{
	Coordinates oldPos = m_state.cursorPosition;

	if (m_lines.empty() || oldPos.line >= (int)m_lines.size())
		return;

	int cindex = GetCharacterIndex(m_state.cursorPosition);

	while (amount-- > 0)
	{
		int lindex = m_state.cursorPosition.line;
		Line& line = m_lines[lindex];

		if (cindex >= (int)line.glyphs.size())
		{
			if (m_state.cursorPosition.line < (int)m_lines.size() - 1)
			{
				m_state.cursorPosition.line = std::max(0, std::min((int)m_lines.size() - 1, m_state.cursorPosition.line + 1));
				m_state.cursorPosition.column = 0;
			}
			else
				return;
		}
		else
		{
			cindex += UTF8CharLength(line.glyphs[cindex].ch);
			m_state.cursorPosition = Coordinates(lindex, GetCharacterColumn(lindex, cindex));
			if (wordMode)
				m_state.cursorPosition = FindNextWord(m_state.cursorPosition);
		}
	}

	if (select)
	{
		if (oldPos == m_interactiveEnd)
			m_interactiveEnd = SanitizeCoordinates(m_state.cursorPosition);
		else if (oldPos == m_interactiveStart)
			m_interactiveStart = m_state.cursorPosition;
		else
		{
			m_interactiveStart = oldPos;
			m_interactiveEnd = m_state.cursorPosition;
		}
	}
	else
		m_interactiveStart = m_interactiveEnd = m_state.cursorPosition;

	SetSelection(m_interactiveStart, m_interactiveEnd, select && wordMode ? SelectionMode::Word : SelectionMode::Normal);

	EnsureCursorVisible();
}

void TextEditor::MoveTop(bool select)
{
	Coordinates oldPos = m_state.cursorPosition;
	SetCursorPosition(Coordinates(0, 0));

	if (m_state.cursorPosition != oldPos)
	{
		if (select)
		{
			m_interactiveEnd = oldPos;
			m_interactiveStart = m_state.cursorPosition;
		}
		else
			m_interactiveStart = m_interactiveEnd = m_state.cursorPosition;

		SetSelection(m_interactiveStart, m_interactiveEnd);
	}
}

void TextEditor::MoveBottom(bool select)
{
	Coordinates oldPos = GetCursorPosition();
	Coordinates newPos{ (int)m_lines.size() - 1, 0 };
	SetCursorPosition(newPos);

	if (select)
	{
		m_interactiveStart = oldPos;
		m_interactiveEnd = newPos;
	}
	else
		m_interactiveStart = m_interactiveEnd = newPos;

	SetSelection(m_interactiveStart, m_interactiveEnd);
}

void TextEditor::MoveHome(bool select)
{
	Coordinates oldPos = m_state.cursorPosition;
	SetCursorPosition(Coordinates(m_state.cursorPosition.line, 0));

	if (m_state.cursorPosition != oldPos)
	{
		if (select)
		{
			if (oldPos == m_interactiveStart)
				m_interactiveStart = m_state.cursorPosition;
			else if (oldPos == m_interactiveEnd)
				m_interactiveEnd = m_state.cursorPosition;
			else
			{
				m_interactiveStart = m_state.cursorPosition;
				m_interactiveEnd = oldPos;
			}
		}
		else
			m_interactiveStart = m_interactiveEnd = m_state.cursorPosition;

		SetSelection(m_interactiveStart, m_interactiveEnd);
	}
}

void TextEditor::MoveEnd(bool select)
{
	Coordinates oldPos = m_state.cursorPosition;
	SetCursorPosition(Coordinates(m_state.cursorPosition.line, GetLineMaxColumn(oldPos.line)));

	if (m_state.cursorPosition != oldPos)
	{
		if (select)
		{
			if (oldPos == m_interactiveEnd)
				m_interactiveEnd = m_state.cursorPosition;
			else if (oldPos == m_interactiveStart)
				m_interactiveStart = m_state.cursorPosition;
			else
			{
				m_interactiveStart = oldPos;
				m_interactiveEnd = m_state.cursorPosition;
			}
		}
		else
			m_interactiveStart = m_interactiveEnd = m_state.cursorPosition;

		SetSelection(m_interactiveStart, m_interactiveEnd);
	}
}

void TextEditor::Delete()
{
	assert(!m_readOnly);

	if (m_lines.empty())
		return;

	UndoRecord u;
	u.before = m_state;

	if (HasSelection())
	{
		u.removed = GetSelectedText();
		u.removedStart = m_state.selectionStart;
		u.removedEnd = m_state.selectionEnd;

		DeleteSelection();
	}
	else
	{
		Coordinates pos = GetActualCursorCoordinates();
		SetCursorPosition(pos);
		Line& line = m_lines[pos.line];

		if (pos.column == GetLineMaxColumn(pos.line))
		{
			if (pos.line == (int)m_lines.size() - 1)
				return;

			u.removed = '\n';
			u.removedStart = u.removedEnd = GetActualCursorCoordinates();
			Advance(u.removedEnd);

			Line& nextLine = m_lines[pos.line + 1];
			line.glyphs.insert(line.glyphs.end(), nextLine.glyphs.begin(), nextLine.glyphs.end());
			RemoveLine(pos.line + 1);
		}
		else
		{
			int cindex = GetCharacterIndex(pos);
			u.removedStart = u.removedEnd = GetActualCursorCoordinates();
			u.removedEnd.column++;
			u.removed = GetText(u.removedStart, u.removedEnd);

			int d = UTF8CharLength(line.glyphs[cindex].ch);
			while (d-- > 0 && cindex < (int)line.glyphs.size())
				line.glyphs.erase(line.glyphs.begin() + cindex);
		}

		m_textChanged = true;
		Colorize(pos.line, 1);
	}

	u.after = m_state;
	AddUndo(u);
}

void TextEditor::Backspace()
{
	assert(!m_readOnly);

	if (m_lines.empty())
		return;

	UndoRecord u;
	u.before = m_state;

	if (HasSelection())
	{
		u.removed = GetSelectedText();
		u.removedStart = m_state.selectionStart;
		u.removedEnd = m_state.selectionEnd;

		DeleteSelection();
	}
	else
	{
		Coordinates pos = GetActualCursorCoordinates();
		SetCursorPosition(pos);

		if (m_state.cursorPosition.column == 0)
		{
			if (m_state.cursorPosition.line == 0)
				return;

			u.removed = '\n';
			u.removedStart = u.removedEnd = Coordinates{ pos.line - 1, GetLineMaxColumn(pos.line - 1) };
			Advance(u.removedEnd);

			Line& line = m_lines[m_state.cursorPosition.line];
			Line& prevLine = m_lines[m_state.cursorPosition.line - 1];
			int prevSize = GetLineMaxColumn(m_state.cursorPosition.line - 1);
			prevLine.glyphs.insert(prevLine.glyphs.end(), line.glyphs.begin(), line.glyphs.end());

			ErrorMarkers etmp;
			for (auto& [line, marker] : m_errorMarkers)
				etmp.emplace(line - 1 == m_state.cursorPosition.line ? line - 1 : line, std::move(marker));
			m_errorMarkers = std::move(etmp);

			RemoveLine(m_state.cursorPosition.line);
			--m_state.cursorPosition.line;
			m_state.cursorPosition.column = prevSize;
		}
		else
		{
			Line& line = m_lines[m_state.cursorPosition.line];
			int cindex = GetCharacterIndex(pos) - 1;
			int cend = cindex + 1;

			while (cindex > 0 && IsUTFSequence(line.glyphs[cindex].ch))
				--cindex;

			u.removedStart = u.removedEnd = GetActualCursorCoordinates();
			--u.removedStart.column;

			if (line.glyphs[cindex].ch == '\t')
				m_state.cursorPosition.column -= m_tabSize;
			else
				--m_state.cursorPosition.column;

			while (cindex < (int)line.glyphs.size() && cend-- > cindex)
			{
				u.removed += line.glyphs[cindex].ch;
				line.glyphs.erase(line.glyphs.begin() + cindex);
			}
		}

		m_textChanged = true;

		EnsureCursorVisible();
		Colorize(m_state.cursorPosition.line, 1);
	}

	u.after = m_state;
	AddUndo(u);
}

void TextEditor::SelectWordUnderCursor()
{
	Coordinates c = GetCursorPosition();
	SetSelection(FindWordStart(c), FindWordEnd(c));
}

void TextEditor::SelectAll()
{
	SetSelection(Coordinates(0, 0), Coordinates((int)m_lines.size(), 0));
}

bool TextEditor::HasSelection() const
{
	return m_state.selectionEnd > m_state.selectionStart;
}

void TextEditor::Copy()
{
	if (HasSelection())
	{
		ImGui::SetClipboardText(GetSelectedText().c_str());
	}
	else
	{
		if (!m_lines.empty())
		{
			std::string str = m_lines[GetActualCursorCoordinates().line].to_string();
			ImGui::SetClipboardText(str.c_str());
		}
	}
}

void TextEditor::Cut()
{
	if (IsReadOnly())
	{
		Copy();
	}
	else
	{
		if (HasSelection())
		{
			UndoRecord u;
			u.before = m_state;
			u.removed = GetSelectedText();
			u.removedStart = m_state.selectionStart;
			u.removedEnd = m_state.selectionEnd;

			Copy();
			DeleteSelection();

			u.after = m_state;
			AddUndo(u);
		}
	}
}

void TextEditor::Paste()
{
	if (IsReadOnly())
		return;

	const char* clipText = ImGui::GetClipboardText();
	if (clipText != nullptr && strlen(clipText) > 0)
	{
		UndoRecord u;
		u.before = m_state;

		if (HasSelection())
		{
			u.removed = GetSelectedText();
			u.removedStart = m_state.selectionStart;
			u.removedEnd = m_state.selectionEnd;
			DeleteSelection();
		}

		u.added = clipText;
		u.addedStart = GetActualCursorCoordinates();

		InsertText(clipText);

		u.addedEnd = GetActualCursorCoordinates();
		u.after = m_state;
		AddUndo(u);
	}
}

bool TextEditor::CanUndo() const
{
	return !m_readOnly && m_undoIndex > 0;
}

bool TextEditor::CanRedo() const
{
	return !m_readOnly && m_undoIndex < (int)m_undoBuffer.size();
}

void TextEditor::Undo(int steps)
{
	while (CanUndo() && steps-- > 0)
		m_undoBuffer[--m_undoIndex].Undo(this);
}

void TextEditor::Redo(int steps)
{
	while (CanRedo() && steps-- > 0)
		m_undoBuffer[m_undoIndex++].Redo(this);
}

const Palette& TextEditor::GetDarkPalette()
{
	const static Palette p = { {
		0xff7f7f7f,	// Default
		0xffd69c56,	// Keyword
		0xff00ff00,	// Number
		0xff7070e0,	// String
		0xff70a0e0, // Char literal
		0xffffffff, // Punctuation
		0xff408080,	// Preprocessor
		0xffaaaaaa, // Identifier
		0xff9bc64d, // Known identifier
		0xffc040a0, // Preproc identifier
		0xff206020, // Comment (single line)
		0xff406020, // Comment (multi line)
		0xff101010, // Background
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

const Palette& TextEditor::GetLightPalette()
{
	const static Palette p = { {
		0xff7f7f7f,	// None
		0xffff0c06,	// Keyword
		0xff008000,	// Number
		0xff2020a0,	// String
		0xff304070, // Char literal
		0xff000000, // Punctuation
		0xff406060,	// Preprocessor
		0xff404040, // Identifier
		0xff606010, // Known identifier
		0xffc040a0, // Preproc identifier
		0xff205020, // Comment (single line)
		0xff405020, // Comment (multi line)
		0xffffffff, // Background
		0xff000000, // Cursor
		0x80600000, // Selection
		0xa00010ff, // ErrorMarker
		0x80f08000, // Breakpoint
		0xff505000, // Line number
		0x40000000, // Current line fill
		0x40808080, // Current line fill (inactive)
		0x40000000, // Current line edge
	} };
	return p;
}

const Palette& TextEditor::GetRetroBluePalette()
{
	const static Palette p = { {
		0xff00ffff,	// None
		0xffffff00,	// Keyword
		0xff00ff00,	// Number
		0xff808000,	// String
		0xff808000, // Char literal
		0xffffffff, // Punctuation
		0xff008000,	// Preprocessor
		0xff00ffff, // Identifier
		0xffffffff, // Known identifier
		0xffff00ff, // Preproc identifier
		0xff808080, // Comment (single line)
		0xff404040, // Comment (multi line)
		0xff800000, // Background
		0xff0080ff, // Cursor
		0x80ffff00, // Selection
		0xa00000ff, // ErrorMarker
		0x80ff8000, // Breakpoint
		0xff808000, // Line number
		0x40000000, // Current line fill
		0x40808080, // Current line fill (inactive)
		0x40000000, // Current line edge
	} };
	return p;
}

std::string TextEditor::GetText() const
{
	int lastLine = (int)m_lines.size() - 1;
	int lastLineLength = GetLineMaxColumn(lastLine);
	return GetText(Coordinates(), Coordinates(lastLine, lastLineLength));
}

std::vector<std::string> TextEditor::GetTextLines() const
{
	std::vector<std::string> result;
	result.reserve(m_lines.size());

	for (const Line& line : m_lines)
	{
		std::string text = line.to_string();
		result.push_back(std::move(text));
	}

	return result;
}

std::string TextEditor::GetSelectedText() const
{
	return GetText(m_state.selectionStart, m_state.selectionEnd);
}

std::string TextEditor::GetCurrentLineText()const
{
	int lineLength = GetLineMaxColumn(m_state.cursorPosition.line);
	return GetText(
		Coordinates(m_state.cursorPosition.line, 0),
		Coordinates(m_state.cursorPosition.line, lineLength));
}

void TextEditor::ProcessInputs()
{
}

void TextEditor::Colorize(int fromLine, int lineCount)
{
	int toLine = lineCount == -1 ? (int)m_lines.size() : std::min((int)m_lines.size(), fromLine + lineCount);
	m_colorRangeMin = std::min(m_colorRangeMin, fromLine);
	m_colorRangeMax = std::max(m_colorRangeMax, toLine);
	m_colorRangeMin = std::max(0, m_colorRangeMin);
	m_colorRangeMax = std::max(m_colorRangeMin, m_colorRangeMax);
	m_checkComments = true;
}

void TextEditor::ColorizeRange(int fromLine, int toLine)
{
	if (m_lines.empty() || fromLine >= toLine)
		return;

	std::string buffer;
	std::cmatch results;
	std::string id;

	int endLine = std::max(0, std::min((int)m_lines.size(), toLine));
	for (int i = fromLine; i < endLine; ++i)
	{
		Line& line = m_lines[i];

		if (line.glyphs.empty())
			continue;

		buffer.resize(line.glyphs.size());
		for (size_t j = 0; j < line.glyphs.size(); ++j)
		{
			Glyph& col = line.glyphs[j];
			buffer[j] = col.ch;
			if (!col.rawColor)
				col.colorIndex = PaletteIndex::Default;
		}

		const char* bufferBegin = &buffer.front();
		const char* bufferEnd = bufferBegin + buffer.size();

		const char* last = bufferEnd;

		for (const char* first = bufferBegin; first != last; )
		{
			const char* token_begin = nullptr;
			const char* token_end = nullptr;
			PaletteIndex token_color = PaletteIndex::Default;

			bool hasTokenizeResult = false;

			if (m_languageDefinition.tokenize != nullptr)
			{
				if (m_languageDefinition.tokenize(first, last, token_begin, token_end, token_color))
					hasTokenizeResult = true;
			}

			if (hasTokenizeResult == false)
			{
				for (auto& [re, pi] : m_regexList)
				{
					if (std::regex_search(first, last, results, re, std::regex_constants::match_continuous))
					{
						hasTokenizeResult = true;
						auto& v = *results.begin();
						token_begin = v.first;
						token_end = v.second;
						token_color = pi;
						break;
					}
				}
			}

			if (hasTokenizeResult == false)
			{
				first++;
			}
			else
			{
				const size_t token_length = token_end - token_begin;

				if (token_color == PaletteIndex::Identifier)
				{
					id.assign(token_begin, token_end);

					// todo : allmost all language definitions use lower case to specify keywords, so shouldn't this use ::tolower ?
					if (!m_languageDefinition.caseSensitive)
						std::transform(id.begin(), id.end(), id.begin(), ::toupper);

					if (!line.glyphs[first - bufferBegin].preprocessor)
					{
						if (m_languageDefinition.keywords.count(id) != 0)
							token_color = PaletteIndex::Keyword;
						else if (m_languageDefinition.identifiers.count(id) != 0)
							token_color = PaletteIndex::KnownIdentifier;
						else if (m_languageDefinition.preprocIdentifiers.count(id) != 0)
							token_color = PaletteIndex::PreprocIdentifier;
					}
					else
					{
						if (m_languageDefinition.preprocIdentifiers.count(id) != 0)
							token_color = PaletteIndex::PreprocIdentifier;
					}
				}

				for (size_t j = 0; j < token_length; ++j)
				{
					Glyph& g = line.glyphs[(token_begin - bufferBegin) + j];

					g.colorIndex = token_color;
					g.rawColor = false;
				}

				first = token_end;
			}
		}
	}
}

void TextEditor::ColorizeInternal()
{
	if (m_lines.empty() || !m_colorizerEnabled)
		return;

	if (m_checkComments && m_languageDefinition.enabled)
	{
		int endLine = (int)m_lines.size();
		int endIndex = 0;
		int commentStartLine = endLine;
		int commentStartIndex = endIndex;
		bool withinString = false;
		bool withinSingleLineComment = false;
		bool withinPreproc = false;
		bool firstChar = true;          // there is no other non-whitespace characters in the line before
		bool concatenate = false;       // '\' on the very end of the line
		int currentLine = 0;
		int currentIndex = 0;

		while (currentLine < endLine || currentIndex < endIndex)
		{
			Line& line = m_lines[currentLine];

			if (currentIndex == 0 && !concatenate)
			{
				withinSingleLineComment = false;
				withinPreproc = false;
				firstChar = true;
			}

			concatenate = false;

			if (!line.glyphs.empty())
			{
				Glyph& g = line.glyphs[currentIndex];
				char c = g.ch;

				if (c != m_languageDefinition.preprocChar && !isspace(c))
					firstChar = false;

				if (currentIndex == (int)line.glyphs.size() - 1 && line.glyphs[line.glyphs.size() - 1].ch == '\\')
					concatenate = true;

				bool inComment = (commentStartLine < currentLine || (commentStartLine == currentLine && commentStartIndex <= currentIndex));

				if (withinString)
				{
					line.glyphs[currentIndex].multlineComment = inComment;

					if (c == '\"')
					{
						if (currentIndex + 1 < (int)line.glyphs.size() && line.glyphs[currentIndex + 1].ch == '\"')
						{
							currentIndex += 1;
							if (currentIndex < (int)line.glyphs.size())
								line.glyphs[currentIndex].multlineComment = inComment;
						}
						else
							withinString = false;
					}
					else if (c == '\\')
					{
						currentIndex += 1;
						if (currentIndex < (int)line.glyphs.size())
							line.glyphs[currentIndex].multlineComment = inComment;
					}
				}
				else
				{
					if (firstChar && c == m_languageDefinition.preprocChar)
						withinPreproc = true;

					if (c == '\"')
					{
						withinString = true;
						line.glyphs[currentIndex].multlineComment = inComment;
					}
					else
					{
						auto pred = [](const char& a, const Glyph& b) { return a == b.ch; };
						auto from = line.glyphs.begin() + currentIndex;

						const std::string& startStr = m_languageDefinition.commentStart;
						const std::string& singleStartStr = m_languageDefinition.singleLineComment;
						const std::string& endStr = m_languageDefinition.commentEnd;

						if (!withinSingleLineComment
							&& currentIndex + startStr.size() <= line.glyphs.size()
							&& equals(startStr.begin(), startStr.end(), from, from + startStr.size(), pred))
						{
							commentStartLine = currentLine;
							commentStartIndex = currentIndex;
						}
						else if (!singleStartStr.empty()
							&& currentIndex + singleStartStr.size() <= line.glyphs.size()
							&& equals(singleStartStr.begin(), singleStartStr.end(), from, from + singleStartStr.size(), pred))
						{
							withinSingleLineComment = true;
						}

						inComment = inComment = (commentStartLine < currentLine || (commentStartLine == currentLine && commentStartIndex <= currentIndex));

						line.glyphs[currentIndex].multlineComment = inComment;
						line.glyphs[currentIndex].comment = withinSingleLineComment;

						if (currentIndex + 1 >= (int)endStr.size() &&
							equals(endStr.begin(), endStr.end(), from + 1 - endStr.size(), from + 1, pred))
						{
							commentStartIndex = endIndex;
							commentStartLine = endLine;
						}
					}
				}

				line.glyphs[currentIndex].preprocessor = withinPreproc;
				currentIndex += UTF8CharLength(c);

				if (currentIndex >= (int)line.glyphs.size())
				{
					currentIndex = 0;
					++currentLine;
				}
			}
			else
			{
				currentIndex = 0;
				++currentLine;
			}
		}
		m_checkComments = false;
	}

	if (m_colorRangeMin < m_colorRangeMax)
	{
		const int increment = (m_languageDefinition.tokenize == nullptr) ? 10 : 10000;
		const int to = std::min(m_colorRangeMin + increment, m_colorRangeMax);
		ColorizeRange(m_colorRangeMin, to);
		m_colorRangeMin = to;

		if (m_colorRangeMax == m_colorRangeMin)
		{
			m_colorRangeMin = std::numeric_limits<int>::max();
			m_colorRangeMax = 0;
		}

		return;
	}
}

float TextEditor::TextDistanceToLineStart(const Coordinates& fromPos) const
{
	const Line& line = m_lines[fromPos.line];
	float distance = 0.0f;
	float spaceSize = ImGui::GetFont()->CalcTextSizeA(ImGui::GetFontSize(), FLT_MAX, -1.0f, " ", nullptr, nullptr).x;
	int colIndex = GetCharacterIndex(fromPos);

	for (int it = 0; it < (int)line.glyphs.size() && it < colIndex; )
	{
		if (line.glyphs[it].ch == '\t')
		{
			distance = (1.0f + std::floor((1.0f + distance) / (float(m_tabSize) * spaceSize))) * (float(m_tabSize) * spaceSize);
			++it;
		}
		else
		{
			int d = UTF8CharLength(line.glyphs[it].ch);
			char tempCString[7];
			int i = 0;

			for (; i < 6 && d-- > 0 && it < (int)line.glyphs.size(); i++, it++)
				tempCString[i] = line.glyphs[it].ch;

			tempCString[i] = '\0';
			distance += ImGui::GetFont()->CalcTextSizeA(ImGui::GetFontSize(), FLT_MAX, -1.0f, tempCString, nullptr, nullptr).x;
		}
	}

	return distance;
}

void TextEditor::EnsureCursorVisible()
{
	if (!m_withinRender)
	{
		m_scrollToCursor = true;
		return;
	}

	float scrollX = ImGui::GetScrollX();
	float scrollY = ImGui::GetScrollY();

	float height = ImGui::GetWindowHeight();
	float width = ImGui::GetWindowWidth();

	int top = 1 + (int)ceil(scrollY / m_charAdvance.y);
	int bottom = (int)ceil((scrollY + height) / m_charAdvance.y);

	int left = (int)ceil(scrollX / m_charAdvance.x);
	int right = (int)ceil((scrollX + width) / m_charAdvance.x);

	Coordinates pos = GetActualCursorCoordinates();
	float len = TextDistanceToLineStart(pos);

	if (pos.line < top)
		ImGui::SetScrollY(std::max(0.0f, (pos.line - 1) * m_charAdvance.y));
	if (pos.line > bottom - 4)
		ImGui::SetScrollY(std::max(0.0f, (pos.line + 4) * m_charAdvance.y - height));
	if (len + m_textStart < left + 4)
		ImGui::SetScrollX(std::max(0.0f, len + m_textStart - 4));
	if (len + m_textStart > right - 4)
		ImGui::SetScrollX(std::max(0.0f, len + m_textStart + 4 - width));
}

int TextEditor::GetPageSize() const
{
	float height = ImGui::GetWindowHeight() - 20.0f;
	return (int)floor(height / m_charAdvance.y);
}

#pragma region Syntax Highlighting

static bool TokenizeCStyleString(const char* in_begin, const char* in_end, const char*& out_begin, const char*& out_end)
{
	const char* p = in_begin;

	if (*p == '"')
	{
		p++;

		while (p < in_end)
		{
			// handle end of string
			if (*p == '"')
			{
				out_begin = in_begin;
				out_end = p + 1;
				return true;
			}

			// handle escape character for "
			if (*p == '\\' && p + 1 < in_end && p[1] == '"')
				p++;

			p++;
		}
	}

	return false;
}

static bool TokenizeCStyleCharacterLiteral(const char* in_begin, const char* in_end, const char*& out_begin, const char*& out_end)
{
	const char* p = in_begin;

	if (*p == '\'')
	{
		p++;

		// handle escape characters
		if (p < in_end && *p == '\\')
			p++;

		if (p < in_end)
			p++;

		// handle end of character literal
		if (p < in_end && *p == '\'')
		{
			out_begin = in_begin;
			out_end = p + 1;
			return true;
		}
	}

	return false;
}

static bool TokenizeCStyleIdentifier(const char* in_begin, const char* in_end, const char*& out_begin, const char*& out_end)
{
	const char* p = in_begin;

	if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || *p == '_')
	{
		p++;

		while ((p < in_end) && ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || *p == '_'))
			p++;

		out_begin = in_begin;
		out_end = p;
		return true;
	}

	return false;
}

static bool TokenizeCStyleNumber(const char* in_begin, const char* in_end, const char*& out_begin, const char*& out_end)
{
	const char* p = in_begin;

	const bool startsWithNumber = *p >= '0' && *p <= '9';

	if (*p != '+' && *p != '-' && !startsWithNumber)
		return false;

	p++;

	bool hasNumber = startsWithNumber;

	while (p < in_end && (*p >= '0' && *p <= '9'))
	{
		hasNumber = true;

		p++;
	}

	if (hasNumber == false)
		return false;

	bool isFloat = false;
	bool isHex = false;
	bool isBinary = false;

	if (p < in_end)
	{
		if (*p == '.')
		{
			isFloat = true;

			p++;

			while (p < in_end && (*p >= '0' && *p <= '9'))
				p++;
		}
		else if (*p == 'x' || *p == 'X')
		{
			// hex formatted integer of the type 0xef80

			isHex = true;

			p++;

			while (p < in_end && ((*p >= '0' && *p <= '9') || (*p >= 'a' && *p <= 'f') || (*p >= 'A' && *p <= 'F')))
				p++;
		}
		else if (*p == 'b' || *p == 'B')
		{
			// binary formatted integer of the type 0b01011101

			isBinary = true;

			p++;

			while (p < in_end && (*p >= '0' && *p <= '1'))
				p++;
		}
	}

	if (isHex == false && isBinary == false)
	{
		// floating point exponent
		if (p < in_end && (*p == 'e' || *p == 'E'))
		{
			isFloat = true;

			p++;

			if (p < in_end && (*p == '+' || *p == '-'))
				p++;

			bool hasDigits = false;

			while (p < in_end && (*p >= '0' && *p <= '9'))
			{
				hasDigits = true;

				p++;
			}

			if (hasDigits == false)
				return false;
		}

		// single precision floating point type
		if (p < in_end && *p == 'f')
			p++;
	}

	if (isFloat == false)
	{
		// integer size type
		while (p < in_end && (*p == 'u' || *p == 'U' || *p == 'l' || *p == 'L'))
			p++;
	}

	out_begin = in_begin;
	out_end = p;
	return true;
}

static bool TokenizeCStylePunctuation(const char* in_begin, const char* in_end, const char*& out_begin, const char*& out_end)
{
	(void)in_end;

	switch (*in_begin)
	{
	case '[':
	case ']':
	case '{':
	case '}':
	case '!':
	case '%':
	case '^':
	case '&':
	case '*':
	case '(':
	case ')':
	case '-':
	case '+':
	case '=':
	case '~':
	case '|':
	case '<':
	case '>':
	case '?':
	case ':':
	case '/':
	case ';':
	case ',':
	case '.':
		out_begin = in_begin;
		out_end = in_begin + 1;
		return true;
	}

	return false;
}

static bool TokenizeLuaStyleString(const char* in_begin, const char* in_end, const char*& out_begin, const char*& out_end)
{
	const char* p = in_begin;

	bool is_single_quote = false;
	bool is_double_quotes = false;
	bool is_double_square_brackets = false;

	switch (*p)
	{
	case '\'':
		is_single_quote = true;
		break;
	case '"':
		is_double_quotes = true;
		break;
	case '[':
		p++;
		if (p < in_end && *(p) == '[')
			is_double_square_brackets = true;
		break;
	}

	if (is_single_quote || is_double_quotes || is_double_square_brackets)
	{
		p++;

		while (p < in_end)
		{
			// handle end of string
			if ((is_single_quote && *p == '\'') || (is_double_quotes && *p == '"') || (is_double_square_brackets && *p == ']' && p + 1 < in_end && *(p + 1) == ']'))
			{
				out_begin = in_begin;

				if (is_double_square_brackets)
					out_end = p + 2;
				else
					out_end = p + 1;

				return true;
			}

			// handle escape character for "
			if (*p == '\\' && p + 1 < in_end && (is_single_quote || is_double_quotes))
				p++;

			p++;
		}
	}

	return false;
}

static bool TokenizeLuaStyleIdentifier(const char* in_begin, const char* in_end, const char*& out_begin, const char*& out_end)
{
	const char* p = in_begin;

	if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || *p == '_')
	{
		p++;

		while ((p < in_end) && ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || *p == '_'))
			p++;

		out_begin = in_begin;
		out_end = p;
		return true;
	}

	return false;
}

static bool TokenizeLuaStyleNumber(const char* in_begin, const char* in_end, const char*& out_begin, const char*& out_end)
{
	const char* p = in_begin;

	const bool startsWithNumber = *p >= '0' && *p <= '9';

	if (*p != '+' && *p != '-' && !startsWithNumber)
		return false;

	p++;

	bool hasNumber = startsWithNumber;

	while (p < in_end && (*p >= '0' && *p <= '9'))
	{
		hasNumber = true;

		p++;
	}

	if (hasNumber == false)
		return false;

	if (p < in_end)
	{
		if (*p == '.')
		{
			p++;

			while (p < in_end && (*p >= '0' && *p <= '9'))
				p++;
		}

		// floating point exponent
		if (p < in_end && (*p == 'e' || *p == 'E'))
		{
			p++;

			if (p < in_end && (*p == '+' || *p == '-'))
				p++;

			bool hasDigits = false;

			while (p < in_end && (*p >= '0' && *p <= '9'))
			{
				hasDigits = true;

				p++;
			}

			if (hasDigits == false)
				return false;
		}
	}

	out_begin = in_begin;
	out_end = p;
	return true;
}

static bool TokenizeLuaStylePunctuation(const char* in_begin, const char* in_end, const char*& out_begin, const char*& out_end)
{
	(void)in_end;

	switch (*in_begin)
	{
	case '[':
	case ']':
	case '{':
	case '}':
	case '!':
	case '%':
	case '#':
	case '^':
	case '&':
	case '*':
	case '(':
	case ')':
	case '-':
	case '+':
	case '=':
	case '~':
	case '|':
	case '<':
	case '>':
	case '?':
	case ':':
	case '/':
	case ';':
	case ',':
	case '.':
		out_begin = in_begin;
		out_end = in_begin + 1;
		return true;
	}

	return false;
}

const LanguageDefinition& LanguageDefinition::CPlusPlus()
{
	static bool inited = false;
	static LanguageDefinition langDef;
	if (!inited)
	{
		static const char* const cppKeywords[] = {
			"alignas", "alignof", "and", "and_eq", "asm", "atomic_cancel", "atomic_commit", "atomic_noexcept", "auto", "bitand", "bitor", "bool", "break", "case", "catch", "char", "char16_t", "char32_t", "class",
			"compl", "concept", "const", "constexpr", "const_cast", "continue", "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float",
			"for", "friend", "goto", "if", "import", "inline", "int", "long", "module", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public",
			"register", "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch", "synchronized", "template", "this", "thread_local",
			"throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
		};
		for (auto& k : cppKeywords)
			langDef.keywords.insert(k);

		static const char* const identifiers[] = {
			"abort", "abs", "acos", "asin", "atan", "atexit", "atof", "atoi", "atol", "ceil", "clock", "cosh", "ctime", "div", "exit", "fabs", "floor", "fmod", "getchar", "getenv", "isalnum", "isalpha", "isdigit", "isgraph",
			"ispunct", "isspace", "isupper", "kbhit", "log10", "log2", "log", "memcmp", "modf", "pow", "printf", "sprintf", "snprintf", "putchar", "putenv", "puts", "rand", "remove", "rename", "sinh", "sqrt", "srand", "strcat", "strcmp", "strerror", "time", "tolower", "toupper",
			"std", "string", "vector", "map", "unordered_map", "set", "unordered_set", "min", "max"
		};
		for (auto& k : identifiers)
		{
			Identifier id;
			id.declaration = "Built-in function";
			langDef.identifiers.emplace(std::string(k), id);
		}

		langDef.tokenize = [](const char* in_begin, const char* in_end, const char*& out_begin, const char*& out_end, PaletteIndex& paletteIndex) -> bool
		{
			paletteIndex = PaletteIndex::Max;

			while (in_begin < in_end && isascii(*in_begin) && isblank(*in_begin))
				in_begin++;

			if (in_begin == in_end)
			{
				out_begin = in_end;
				out_end = in_end;
				paletteIndex = PaletteIndex::Default;
			}
			else if (TokenizeCStyleString(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::String;
			else if (TokenizeCStyleCharacterLiteral(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::CharLiteral;
			else if (TokenizeCStyleIdentifier(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::Identifier;
			else if (TokenizeCStyleNumber(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::Number;
			else if (TokenizeCStylePunctuation(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::Punctuation;

			return paletteIndex != PaletteIndex::Max;
		};

		langDef.commentStart = "/*";
		langDef.commentEnd = "*/";
		langDef.singleLineComment = "//";

		langDef.caseSensitive = true;
		langDef.autoIndentation = true;

		langDef.name = "C++";

		inited = true;
	}
	return langDef;
}

const LanguageDefinition& LanguageDefinition::HLSL()
{
	static bool inited = false;
	static LanguageDefinition langDef;
	if (!inited)
	{
		static const char* const keywords[] = {
			"AppendStructuredBuffer", "asm", "asm_fragment", "BlendState", "bool", "break", "Buffer", "ByteAddressBuffer", "case", "cbuffer", "centroid", "class", "column_major", "compile", "compile_fragment",
			"CompileShader", "const", "continue", "ComputeShader", "ConsumeStructuredBuffer", "default", "DepthStencilState", "DepthStencilView", "discard", "do", "double", "DomainShader", "dword", "else",
			"export", "extern", "false", "float", "for", "fxgroup", "GeometryShader", "groupshared", "half", "Hullshader", "if", "in", "inline", "inout", "InputPatch", "int", "interface", "line", "lineadj",
			"linear", "LineStream", "matrix", "min16float", "min10float", "min16int", "min12int", "min16uint", "namespace", "nointerpolation", "noperspective", "NULL", "out", "OutputPatch", "packoffset",
			"pass", "pixelfragment", "PixelShader", "point", "PointStream", "precise", "RasterizerState", "RenderTargetView", "return", "register", "row_major", "RWBuffer", "RWByteAddressBuffer", "RWStructuredBuffer",
			"RWTexture1D", "RWTexture1DArray", "RWTexture2D", "RWTexture2DArray", "RWTexture3D", "sample", "sampler", "SamplerState", "SamplerComparisonState", "shared", "snorm", "stateblock", "stateblock_state",
			"static", "string", "struct", "switch", "StructuredBuffer", "tbuffer", "technique", "technique10", "technique11", "texture", "Texture1D", "Texture1DArray", "Texture2D", "Texture2DArray", "Texture2DMS",
			"Texture2DMSArray", "Texture3D", "TextureCube", "TextureCubeArray", "true", "typedef", "triangle", "triangleadj", "TriangleStream", "uint", "uniform", "unorm", "unsigned", "vector", "vertexfragment",
			"VertexShader", "void", "volatile", "while",
			"bool1","bool2","bool3","bool4","double1","double2","double3","double4", "float1", "float2", "float3", "float4", "int1", "int2", "int3", "int4", "in", "out", "inout",
			"uint1", "uint2", "uint3", "uint4", "dword1", "dword2", "dword3", "dword4", "half1", "half2", "half3", "half4",
			"float1x1","float2x1","float3x1","float4x1","float1x2","float2x2","float3x2","float4x2",
			"float1x3","float2x3","float3x3","float4x3","float1x4","float2x4","float3x4","float4x4",
			"half1x1","half2x1","half3x1","half4x1","half1x2","half2x2","half3x2","half4x2",
			"half1x3","half2x3","half3x3","half4x3","half1x4","half2x4","half3x4","half4x4",
		};
		for (auto& k : keywords)
			langDef.keywords.insert(k);

		static const char* const identifiers[] = {
			"abort", "abs", "acos", "all", "AllMemoryBarrier", "AllMemoryBarrierWithGroupSync", "any", "asdouble", "asfloat", "asin", "asint", "asint", "asuint",
			"asuint", "atan", "atan2", "ceil", "CheckAccessFullyMapped", "clamp", "clip", "cos", "cosh", "countbits", "cross", "D3DCOLORtoUBYTE4", "ddx",
			"ddx_coarse", "ddx_fine", "ddy", "ddy_coarse", "ddy_fine", "degrees", "determinant", "DeviceMemoryBarrier", "DeviceMemoryBarrierWithGroupSync",
			"distance", "dot", "dst", "errorf", "EvaluateAttributeAtCentroid", "EvaluateAttributeAtSample", "EvaluateAttributeSnapped", "exp", "exp2",
			"f16tof32", "f32tof16", "faceforward", "firstbithigh", "firstbitlow", "floor", "fma", "fmod", "frac", "frexp", "fwidth", "GetRenderTargetSampleCount",
			"GetRenderTargetSamplePosition", "GroupMemoryBarrier", "GroupMemoryBarrierWithGroupSync", "InterlockedAdd", "InterlockedAnd", "InterlockedCompareExchange",
			"InterlockedCompareStore", "InterlockedExchange", "InterlockedMax", "InterlockedMin", "InterlockedOr", "InterlockedXor", "isfinite", "isinf", "isnan",
			"ldexp", "length", "lerp", "lit", "log", "log10", "log2", "mad", "max", "min", "modf", "msad4", "mul", "noise", "normalize", "pow", "printf",
			"Process2DQuadTessFactorsAvg", "Process2DQuadTessFactorsMax", "Process2DQuadTessFactorsMin", "ProcessIsolineTessFactors", "ProcessQuadTessFactorsAvg",
			"ProcessQuadTessFactorsMax", "ProcessQuadTessFactorsMin", "ProcessTriTessFactorsAvg", "ProcessTriTessFactorsMax", "ProcessTriTessFactorsMin",
			"radians", "rcp", "reflect", "refract", "reversebits", "round", "rsqrt", "saturate", "sign", "sin", "sincos", "sinh", "smoothstep", "sqrt", "step",
			"tan", "tanh", "tex1D", "tex1D", "tex1Dbias", "tex1Dgrad", "tex1Dlod", "tex1Dproj", "tex2D", "tex2D", "tex2Dbias", "tex2Dgrad", "tex2Dlod", "tex2Dproj",
			"tex3D", "tex3D", "tex3Dbias", "tex3Dgrad", "tex3Dlod", "tex3Dproj", "texCUBE", "texCUBE", "texCUBEbias", "texCUBEgrad", "texCUBElod", "texCUBEproj", "transpose", "trunc"
		};
		for (auto& k : identifiers)
		{
			Identifier id;
			id.declaration = "Built-in function";
			langDef.identifiers.emplace(std::string(k), id);
		}

		langDef.tokenRegexStrings.emplace_back("[ \\t]*#[ \\t]*[a-zA-Z_]+", PaletteIndex::Preprocessor);
		langDef.tokenRegexStrings.emplace_back("L?\\\"(\\\\.|[^\\\"])*\\\"", PaletteIndex::String);
		langDef.tokenRegexStrings.emplace_back("\\'\\\\?[^\\']\\'", PaletteIndex::CharLiteral);
		langDef.tokenRegexStrings.emplace_back("[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)([eE][+-]?[0-9]+)?[fF]?", PaletteIndex::Number);
		langDef.tokenRegexStrings.emplace_back("[+-]?[0-9]+[Uu]?[lL]?[lL]?", PaletteIndex::Number);
		langDef.tokenRegexStrings.emplace_back("0[0-7]+[Uu]?[lL]?[lL]?", PaletteIndex::Number);
		langDef.tokenRegexStrings.emplace_back("0[xX][0-9a-fA-F]+[uU]?[lL]?[lL]?", PaletteIndex::Number);
		langDef.tokenRegexStrings.emplace_back("[a-zA-Z_][a-zA-Z0-9_]*", PaletteIndex::Identifier);
		langDef.tokenRegexStrings.emplace_back("[\\[\\]\\{\\}\\!\\%\\^\\&\\*\\(\\)\\-\\+\\=\\~\\|\\<\\>\\?\\/\\;\\,\\.]", PaletteIndex::Punctuation);

		langDef.commentStart = "/*";
		langDef.commentEnd = "*/";
		langDef.singleLineComment = "//";

		langDef.caseSensitive = true;
		langDef.autoIndentation = true;

		langDef.name = "HLSL";

		inited = true;
	}
	return langDef;
}

const LanguageDefinition& LanguageDefinition::GLSL()
{
	static bool inited = false;
	static LanguageDefinition langDef;
	if (!inited)
	{
		static const char* const keywords[] = {
			"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short",
			"signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "_Alignas", "_Alignof", "_Atomic", "_Bool", "_Complex", "_Generic", "_Imaginary",
			"_Noreturn", "_Static_assert", "_Thread_local"
		};
		for (auto& k : keywords)
			langDef.keywords.insert(k);

		static const char* const identifiers[] = {
			"abort", "abs", "acos", "asin", "atan", "atexit", "atof", "atoi", "atol", "ceil", "clock", "cosh", "ctime", "div", "exit", "fabs", "floor", "fmod", "getchar", "getenv", "isalnum", "isalpha", "isdigit", "isgraph",
			"ispunct", "isspace", "isupper", "kbhit", "log10", "log2", "log", "memcmp", "modf", "pow", "putchar", "putenv", "puts", "rand", "remove", "rename", "sinh", "sqrt", "srand", "strcat", "strcmp", "strerror", "time", "tolower", "toupper"
		};
		for (auto& k : identifiers)
		{
			Identifier id;
			id.declaration = "Built-in function";
			langDef.identifiers.emplace(std::string(k), id);
		}

		langDef.tokenRegexStrings.emplace_back("[ \\t]*#[ \\t]*[a-zA-Z_]+", PaletteIndex::Preprocessor);
		langDef.tokenRegexStrings.emplace_back("L?\\\"(\\\\.|[^\\\"])*\\\"", PaletteIndex::String);
		langDef.tokenRegexStrings.emplace_back("\\'\\\\?[^\\']\\'", PaletteIndex::CharLiteral);
		langDef.tokenRegexStrings.emplace_back("[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)([eE][+-]?[0-9]+)?[fF]?", PaletteIndex::Number);
		langDef.tokenRegexStrings.emplace_back("[+-]?[0-9]+[Uu]?[lL]?[lL]?", PaletteIndex::Number);
		langDef.tokenRegexStrings.emplace_back("0[0-7]+[Uu]?[lL]?[lL]?", PaletteIndex::Number);
		langDef.tokenRegexStrings.emplace_back("0[xX][0-9a-fA-F]+[uU]?[lL]?[lL]?", PaletteIndex::Number);
		langDef.tokenRegexStrings.emplace_back("[a-zA-Z_][a-zA-Z0-9_]*", PaletteIndex::Identifier);
		langDef.tokenRegexStrings.emplace_back("[\\[\\]\\{\\}\\!\\%\\^\\&\\*\\(\\)\\-\\+\\=\\~\\|\\<\\>\\?\\/\\;\\,\\.]", PaletteIndex::Punctuation);

		langDef.commentStart = "/*";
		langDef.commentEnd = "*/";
		langDef.singleLineComment = "//";

		langDef.caseSensitive = true;
		langDef.autoIndentation = true;

		langDef.name = "GLSL";

		inited = true;
	}
	return langDef;
}

const LanguageDefinition& LanguageDefinition::C()
{
	static bool inited = false;
	static LanguageDefinition langDef;
	if (!inited)
	{
		static const char* const keywords[] = {
			"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short",
			"signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "_Alignas", "_Alignof", "_Atomic", "_Bool", "_Complex", "_Generic", "_Imaginary",
			"_Noreturn", "_Static_assert", "_Thread_local"
		};
		for (auto& k : keywords)
			langDef.keywords.insert(k);

		static const char* const identifiers[] = {
			"abort", "abs", "acos", "asin", "atan", "atexit", "atof", "atoi", "atol", "ceil", "clock", "cosh", "ctime", "div", "exit", "fabs", "floor", "fmod", "getchar", "getenv", "isalnum", "isalpha", "isdigit", "isgraph",
			"ispunct", "isspace", "isupper", "kbhit", "log10", "log2", "log", "memcmp", "modf", "pow", "putchar", "putenv", "puts", "rand", "remove", "rename", "sinh", "sqrt", "srand", "strcat", "strcmp", "strerror", "time", "tolower", "toupper"
		};
		for (auto& k : identifiers)
		{
			Identifier id;
			id.declaration = "Built-in function";
			langDef.identifiers.emplace(std::string(k), id);
		}

		langDef.tokenize = [](const char* in_begin, const char* in_end, const char*& out_begin, const char*& out_end, PaletteIndex& paletteIndex) -> bool
		{
			paletteIndex = PaletteIndex::Max;

			while (in_begin < in_end && isascii(*in_begin) && isblank(*in_begin))
				in_begin++;

			if (in_begin == in_end)
			{
				out_begin = in_end;
				out_end = in_end;
				paletteIndex = PaletteIndex::Default;
			}
			else if (TokenizeCStyleString(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::String;
			else if (TokenizeCStyleCharacterLiteral(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::CharLiteral;
			else if (TokenizeCStyleIdentifier(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::Identifier;
			else if (TokenizeCStyleNumber(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::Number;
			else if (TokenizeCStylePunctuation(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::Punctuation;

			return paletteIndex != PaletteIndex::Max;
		};

		langDef.commentStart = "/*";
		langDef.commentEnd = "*/";
		langDef.singleLineComment = "//";

		langDef.caseSensitive = true;
		langDef.autoIndentation = true;

		langDef.name = "C";

		inited = true;
	}
	return langDef;
}

const LanguageDefinition& LanguageDefinition::SQL()
{
	static bool inited = false;
	static LanguageDefinition langDef;
	if (!inited)
	{
		static const char* const keywords[] = {
			"ADD", "EXCEPT", "PERCENT", "ALL", "EXEC", "PLAN", "ALTER", "EXECUTE", "PRECISION", "AND", "EXISTS", "PRIMARY", "ANY", "EXIT", "PRINT", "AS", "FETCH", "PROC", "ASC", "FILE", "PROCEDURE",
			"AUTHORIZATION", "FILLFACTOR", "PUBLIC", "BACKUP", "FOR", "RAISERROR", "BEGIN", "FOREIGN", "READ", "BETWEEN", "FREETEXT", "READTEXT", "BREAK", "FREETEXTTABLE", "RECONFIGURE",
			"BROWSE", "FROM", "REFERENCES", "BULK", "FULL", "REPLICATION", "BY", "FUNCTION", "RESTORE", "CASCADE", "GOTO", "RESTRICT", "CASE", "GRANT", "RETURN", "CHECK", "GROUP", "REVOKE",
			"CHECKPOINT", "HAVING", "RIGHT", "CLOSE", "HOLDLOCK", "ROLLBACK", "CLUSTERED", "IDENTITY", "ROWCOUNT", "COALESCE", "IDENTITY_INSERT", "ROWGUIDCOL", "COLLATE", "IDENTITYCOL", "RULE",
			"COLUMN", "IF", "SAVE", "COMMIT", "IN", "SCHEMA", "COMPUTE", "INDEX", "SELECT", "CONSTRAINT", "INNER", "SESSION_USER", "CONTAINS", "INSERT", "SET", "CONTAINSTABLE", "INTERSECT", "SETUSER",
			"CONTINUE", "INTO", "SHUTDOWN", "CONVERT", "IS", "SOME", "CREATE", "JOIN", "STATISTICS", "CROSS", "KEY", "SYSTEM_USER", "CURRENT", "KILL", "TABLE", "CURRENT_DATE", "LEFT", "TEXTSIZE",
			"CURRENT_TIME", "LIKE", "THEN", "CURRENT_TIMESTAMP", "LINENO", "TO", "CURRENT_USER", "LOAD", "TOP", "CURSOR", "NATIONAL", "TRAN", "DATABASE", "NOCHECK", "TRANSACTION",
			"DBCC", "NONCLUSTERED", "TRIGGER", "DEALLOCATE", "NOT", "TRUNCATE", "DECLARE", "NULL", "TSEQUAL", "DEFAULT", "NULLIF", "UNION", "DELETE", "OF", "UNIQUE", "DENY", "OFF", "UPDATE",
			"DESC", "OFFSETS", "UPDATETEXT", "DISK", "ON", "USE", "DISTINCT", "OPEN", "USER", "DISTRIBUTED", "OPENDATASOURCE", "VALUES", "DOUBLE", "OPENQUERY", "VARYING","DROP", "OPENROWSET", "VIEW",
			"DUMMY", "OPENXML", "WAITFOR", "DUMP", "OPTION", "WHEN", "ELSE", "OR", "WHERE", "END", "ORDER", "WHILE", "ERRLVL", "OUTER", "WITH", "ESCAPE", "OVER", "WRITETEXT"
		};

		for (auto& k : keywords)
			langDef.keywords.insert(k);

		static const char* const identifiers[] = {
			"ABS",  "ACOS",  "ADD_MONTHS",  "ASCII",  "ASCIISTR",  "ASIN",  "ATAN",  "ATAN2",  "AVG",  "BFILENAME",  "BIN_TO_NUM",  "BITAND",  "CARDINALITY",  "CASE",  "CAST",  "CEIL",
			"CHARTOROWID",  "CHR",  "COALESCE",  "COMPOSE",  "CONCAT",  "CONVERT",  "CORR",  "COS",  "COSH",  "COUNT",  "COVAR_POP",  "COVAR_SAMP",  "CUME_DIST",  "CURRENT_DATE",
			"CURRENT_TIMESTAMP",  "DBTIMEZONE",  "DECODE",  "DECOMPOSE",  "DENSE_RANK",  "DUMP",  "EMPTY_BLOB",  "EMPTY_CLOB",  "EXP",  "EXTRACT",  "FIRST_VALUE",  "FLOOR",  "FROM_TZ",  "GREATEST",
			"GROUP_ID",  "HEXTORAW",  "INITCAP",  "INSTR",  "INSTR2",  "INSTR4",  "INSTRB",  "INSTRC",  "LAG",  "LAST_DAY",  "LAST_VALUE",  "LEAD",  "LEAST",  "LENGTH",  "LENGTH2",  "LENGTH4",
			"LENGTHB",  "LENGTHC",  "LISTAGG",  "LN",  "LNNVL",  "LOCALTIMESTAMP",  "LOG",  "LOWER",  "LPAD",  "LTRIM",  "MAX",  "MEDIAN",  "MIN",  "MOD",  "MONTHS_BETWEEN",  "NANVL",  "NCHR",
			"NEW_TIME",  "NEXT_DAY",  "NTH_VALUE",  "NULLIF",  "NUMTODSINTERVAL",  "NUMTOYMINTERVAL",  "NVL",  "NVL2",  "POWER",  "RANK",  "RAWTOHEX",  "REGEXP_COUNT",  "REGEXP_INSTR",
			"REGEXP_REPLACE",  "REGEXP_SUBSTR",  "REMAINDER",  "REPLACE",  "ROUND",  "ROWNUM",  "RPAD",  "RTRIM",  "SESSIONTIMEZONE",  "SIGN",  "SIN",  "SINH",
			"SOUNDEX",  "SQRT",  "STDDEV",  "SUBSTR",  "SUM",  "SYS_CONTEXT",  "SYSDATE",  "SYSTIMESTAMP",  "TAN",  "TANH",  "TO_CHAR",  "TO_CLOB",  "TO_DATE",  "TO_DSINTERVAL",  "TO_LOB",
			"TO_MULTI_BYTE",  "TO_NCLOB",  "TO_NUMBER",  "TO_SINGLE_BYTE",  "TO_TIMESTAMP",  "TO_TIMESTAMP_TZ",  "TO_YMINTERVAL",  "TRANSLATE",  "TRIM",  "TRUNC", "TZ_OFFSET",  "UID",  "UPPER",
			"USER",  "USERENV",  "VAR_POP",  "VAR_SAMP",  "VARIANCE",  "VSIZE "
		};
		for (auto& k : identifiers)
		{
			Identifier id;
			id.declaration = "Built-in function";
			langDef.identifiers.emplace(std::string(k), id);
		}

		langDef.tokenRegexStrings.emplace_back("L?\\\"(\\\\.|[^\\\"])*\\\"", PaletteIndex::String);
		langDef.tokenRegexStrings.emplace_back("\\\'[^\\\']*\\\'", PaletteIndex::String);
		langDef.tokenRegexStrings.emplace_back("[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)([eE][+-]?[0-9]+)?[fF]?", PaletteIndex::Number);
		langDef.tokenRegexStrings.emplace_back("[+-]?[0-9]+[Uu]?[lL]?[lL]?", PaletteIndex::Number);
		langDef.tokenRegexStrings.emplace_back("0[0-7]+[Uu]?[lL]?[lL]?", PaletteIndex::Number);
		langDef.tokenRegexStrings.emplace_back("0[xX][0-9a-fA-F]+[uU]?[lL]?[lL]?", PaletteIndex::Number);
		langDef.tokenRegexStrings.emplace_back("[a-zA-Z_][a-zA-Z0-9_]*", PaletteIndex::Identifier);
		langDef.tokenRegexStrings.emplace_back("[\\[\\]\\{\\}\\!\\%\\^\\&\\*\\(\\)\\-\\+\\=\\~\\|\\<\\>\\?\\/\\;\\,\\.]", PaletteIndex::Punctuation);

		langDef.commentStart = "/*";
		langDef.commentEnd = "*/";
		langDef.singleLineComment = "//";

		langDef.caseSensitive = false;
		langDef.autoIndentation = false;

		langDef.name = "SQL";

		inited = true;
	}
	return langDef;
}

const LanguageDefinition& LanguageDefinition::Lua()
{
	static bool inited = false;
	static LanguageDefinition langDef;
	if (!inited)
	{
		static const char* const keywords[] = {
			"and", "break", "do", "else", "elseif", "end", "false", "for", "function", "goto", "if", "in", "local", "nil", "not", "or", "repeat", "return", "then", "true", "until", "while"
		};

		for (auto& k : keywords)
			langDef.keywords.insert(k);

		static const char* const identifiers[] = {
			"assert", "collectgarbage", "dofile", "error", "getmetatable", "ipairs", "loadfile", "load", "loadstring",  "next",  "pairs",  "pcall",  "print",  "rawequal",  "rawlen",  "rawget",  "rawset",
			"select",  "setmetatable",  "tonumber",  "tostring",  "type",  "xpcall",  "_G",  "_VERSION","arshift", "band", "bnot", "bor", "bxor", "btest", "extract", "lrotate", "lshift", "replace",
			"rrotate", "rshift", "create", "resume", "running", "status", "wrap", "yield", "isyieldable", "debug","getuservalue", "gethook", "getinfo", "getlocal", "getregistry", "getmetatable",
			"getupvalue", "upvaluejoin", "upvalueid", "setuservalue", "sethook", "setlocal", "setmetatable", "setupvalue", "traceback", "close", "flush", "input", "lines", "open", "output", "popen",
			"read", "tmpfile", "type", "write", "close", "flush", "lines", "read", "seek", "setvbuf", "write", "__gc", "__tostring", "abs", "acos", "asin", "atan", "ceil", "cos", "deg", "exp", "tointeger",
			"floor", "fmod", "ult", "log", "max", "min", "modf", "rad", "random", "randomseed", "sin", "sqrt", "string", "tan", "type", "atan2", "cosh", "sinh", "tanh",
			"pow", "frexp", "ldexp", "log10", "pi", "huge", "maxinteger", "mininteger", "loadlib", "searchpath", "seeall", "preload", "cpath", "path", "searchers", "loaded", "module", "require", "clock",
			"date", "difftime", "execute", "exit", "getenv", "remove", "rename", "setlocale", "time", "tmpname", "byte", "char", "dump", "find", "format", "gmatch", "gsub", "len", "lower", "match", "rep",
			"reverse", "sub", "upper", "pack", "packsize", "unpack", "concat", "maxn", "insert", "pack", "unpack", "remove", "move", "sort", "offset", "codepoint", "char", "len", "codes", "charpattern",
			"coroutine", "table", "io", "os", "string", "utf8", "bit32", "math", "debug", "package"
		};
		for (auto& k : identifiers)
		{
			Identifier id;
			id.declaration = "Built-in function";
			langDef.identifiers.emplace(std::string(k), id);
		}

		langDef.tokenize = [](const char* in_begin, const char* in_end, const char*& out_begin, const char*& out_end, PaletteIndex& paletteIndex) -> bool
		{
			paletteIndex = PaletteIndex::Max;

			while (in_begin < in_end && isascii(*in_begin) && isblank(*in_begin))
				in_begin++;

			if (in_begin == in_end)
			{
				out_begin = in_end;
				out_end = in_end;
				paletteIndex = PaletteIndex::Default;
			}
			else if (TokenizeLuaStyleString(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::String;
			else if (TokenizeLuaStyleIdentifier(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::Identifier;
			else if (TokenizeLuaStyleNumber(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::Number;
			else if (TokenizeLuaStylePunctuation(in_begin, in_end, out_begin, out_end))
				paletteIndex = PaletteIndex::Punctuation;

			return paletteIndex != PaletteIndex::Max;
		};

		langDef.commentStart = "--[[";
		langDef.commentEnd = "]]";
		langDef.singleLineComment = "--";

		langDef.caseSensitive = true;
		langDef.autoIndentation = false;

		langDef.name = "Lua";

		inited = true;
	}
	return langDef;
}

const LanguageDefinition& LanguageDefinition::PlainText()
{
	static bool inited = false;
	static LanguageDefinition langDef;

	if (!inited)
	{
		langDef.name = "PlainText";
		langDef.enabled = false;
		langDef.autoIndentation = false;
		langDef.caseSensitive = false;

		inited = true;
	}

	return langDef;
}

#pragma endregion

} // namespace mq::imgui::texteditor
