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
#include "mq/base/Common.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>

#include "zep/component.h"

// Forward Declares
namespace Zep
{
	class ZepEditor;
	class ZepBuffer;
	class ZepWindow;
	class ZepMessage;
	class GlyphIterator;
	enum class ZepTextType;
}

namespace mq::imgui {

//============================================================================

class ZepEditor_ImGui;

class ImGuiZepEditor : public Zep::IZepComponent
{
public:
	ImGuiZepEditor(std::string_view id);
	virtual ~ImGuiZepEditor();

	MQLIB_OBJECT static std::shared_ptr<ImGuiZepEditor> Create(std::string_view id);

	void SetFont(Zep::ZepTextType, ImFont* pFont, int pixelHeight);

	virtual Zep::ZepEditor& GetEditor() const override;
	virtual void Render(const ImVec2& displaySize = ImVec2());

	virtual void Clear();
	virtual void GetText(std::string& outBuffer) const;
	virtual size_t GetTextLength() const;
	virtual Zep::GlyphIterator InsertText(Zep::GlyphIterator position, std::string_view text, ImU32 color = -1);
	virtual void SetText(std::string_view text);

	virtual int GetFontSize() const { return m_fontSize; }
	virtual void SetFontSize(int size);
	virtual int GetWindowFlags() const;
	virtual void SetWindowFlags(int flags) const;

	virtual void SetSyntaxProvider(const char* syntaxName) const;

	Zep::ZepWindow* GetWindow() const { return m_window; }
	Zep::ZepBuffer* GetBuffer() const { return m_buffer; }

	Zep::ZepBuffer* m_buffer = nullptr;
	Zep::ZepWindow* m_window = nullptr;
	int m_fontSize = 13;
	std::string m_id;

protected:
	virtual void Notify(std::shared_ptr<Zep::ZepMessage> message) override;

private:
	ZepEditor_ImGui* m_editor = nullptr;
};


} // namespace mq::imgui
