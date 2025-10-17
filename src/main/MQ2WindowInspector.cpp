/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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


#include "imgui/fonts/IconsFontAwesome.h"
#include "imgui/imgui_internal.h"
#include "imgui/ImGuiMemoryEditor.h"

#include "mq/imgui/ImGuiUtils.h"
#include "mq/imgui/Widgets.h"
#include "mq/zep/ImGuiZepEditor.h"
#include "zep/window.h"

#include "eqstd/unordered_map.h"
#include "eqstd/string.h"

#include <fmt/format.h>
#include <fmt/chrono.h>
#include <spdlog/spdlog.h>

using namespace std::chrono_literals;

namespace mq {

class ImGuiWindowPropertyViewer;

static void DisplayCustomWindowPropertyViewer(CSidlScreenWnd* pWindow, ImGuiWindowPropertyViewer* viewer);

static void DeveloperTools_WindowInspector_ViewString(std::string_view name, const CXStr& string);
static void DeveloperTools_WindowInspector_EditString(std::string_view name, CXStr* string);

static void DeveloperTools_WindowInspector_ViewString(std::string_view name, const SoeUtil::String& string);
static void DeveloperTools_WindowInspector_EditString(std::string_view name, SoeUtil::String* string);

static void DeveloperTools_windowInspector_SetHoveredWindow(CXWnd* pWnd);

static inline void  TreeAdvanceToLabelPos() { ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetTreeNodeToLabelSpacing()); }

//============================================================================

void CopyWindowChildTLO(CXWnd* pWindow)
{
	// Get the parent window
	CXWnd* pParentWindow = pWindow;
	while (CXWnd* pTemp = pParentWindow->GetParentWindow())
		pParentWindow = pTemp;

	char buffer[128];

	if (pParentWindow != pWindow)
	{
		sprintf_s(buffer, "${Window[%s].Child[%s]}", pParentWindow->GetXMLName().c_str(),
			pWindow->GetXMLName().c_str());
	}
	else
	{
		sprintf_s(buffer, "${Window[%s]}", pWindow->GetXMLName().c_str());
	}

	ImGui::SetClipboardText(buffer);
	WriteChatf("Copied: \ay%s", buffer);
}

static CXRect GetWndClientRect(CXWnd* pWnd)
{
#if HAS_GAMEFACE_UI
	if (GetGameState() == GAMESTATE_PRECHARSELECT)
		return pWnd->GetClientRectNonVirtual();
	else
#endif
		return pWnd->GetClientRect();
}

//----------------------------------------------------------------------------

#pragma region Memory Viewer

struct WindowMemoryViewer : public MemoryEditor
{
	using MemoryEditor::MemoryEditor;

	CXWnd* window;
	size_t size;
	std::string name;
};
std::vector<WindowMemoryViewer> s_memoryEditors;

void AddMemoryEditor(CXWnd* window, size_t size)
{
	auto& editor = s_memoryEditors.emplace_back();
	editor.ReadOnly = true;
	editor.Cols = 16;
	editor.OptShowDataPreview = true;
	editor.window = window;
	editor.size = ((size + 4095) / 4096) * 4096;
	editor.name = std::string("Memory Editor: ") + (window->GetWindowName() ? window->GetWindowName()->c_str() : "?");
}

void DrawMemoryEditors()
{
	s_memoryEditors.erase(std::remove_if(s_memoryEditors.begin(), s_memoryEditors.end(),
		[](auto& editor) {
			editor.DrawWindow(editor.name.c_str(), editor.window, editor.size /*,(size_t)editor.window*/);
			return !editor.Open; }), s_memoryEditors.end());
}

#pragma endregion

#pragma region Datatype Serializers

const char* UITypeToScreenPieceTemplateType(UIType type)
{
	switch (type)
	{
	case UI_LayoutStrategy: return "CLayoutStrategyTemplate*";
	case UI_LayoutVertical: return "CLayoutVerticalTemplate*";
	case UI_LayoutHorizontal: return "CLayoutHorizontalTemplate*";
	case UI_StaticScreenPiece: return "CStaticScreenPieceTemplate*";
	case UI_StaticAnimation: return "CStaticAnimationTemplate*";
	case UI_StaticText: return "CStaticTextTemplate*";
	case UI_StaticFrame: return "CStaticFrameTemplate*";
	case UI_StaticHeader: return "CStaticHeaderTemplate*";
	case UI_StaticTintedBlendAnimation: return "CStaticTintedBlendAnimationTemplate*";
	case UI_Control: return "CControlTemplate*";
	case UI_ListboxColumn: return "CListboxColumnTemplate*";
	case UI_Listbox: return "CListboxTemplate*";
	case UI_EditBox: return "CEditboxTemplate*";
	case UI_Slider: return "CSliderTemplate*";
	case UI_Label: return "CLabelTemplate*";
	case UI_STMLBox: return "CSTMLboxTemplate*";
	case UI_TreeView: return "CTreeViewTemplate*";
	case UI_Combobox: return "CComboboxTemplate*";
	case UI_Button: return "CButtonTemplate*";
	case UI_Gauge: return "CGaugeTemplate*";
	case UI_SpellGem: return "CSpellGemTemplate*";
	case UI_InvSlot: return "CInvSlotTemplate*";
	case UI_Page: return "CPageTemplate*";
	case UI_TabBox: return "CTabBoxTemplate*";
	case UI_LayoutBox: return "CLayoutBoxTemplate*";
	case UI_HorizontalLayoutBox: return "CHorizontalLayoutBoxTemplate*";
	case UI_VerticalLayoutBox: return "CVerticalLayoutBoxTemplate*";
	case UI_TileLayoutBox: return "CTileLayoutBoxTemplate*";
	case UI_Screen: return "CScreenTemplate*";
	case UI_TemplateContainer: return "CTemplateContainerTemplate*";
	case UI_HotButton: return "CHotButtonTemplate*";
	default:
		return "(other template)";
	}
}

inline const char* UIDirectoryToString(enDir dir)
{
	switch (dir)
	{
	case cUIDirectory: return "UI Directory";
	case cUIDirectoryAtlas: return "Altas Directory";
	case cUIDirectoryTexture: return "Texture Directory";
	case cUIDirectoryMaps: return "Maps Directory";
	default: return "Unknown Directory";
	}
}

#pragma endregion

#pragma region Column Widgets

bool IsEmptyValue(const char* val)
{
	return val[0] == '('
		&& (strcmp(val, "(empty)")
			|| strcmp(val, "(null)")
			|| strcmp(val, "(none)"));
}

static void ColumnValue(const char* fmt, va_list args)
{
	if (IsEmptyValue(fmt))
	{
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "%s", fmt);
	}
	else if (strcmp(fmt, "%s") == 0)
	{
		const char* str = va_arg(args, const char*);

		if (IsEmptyValue(str))
			ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "%s", str);
		else
			ImGui::Text("%s", str);
	}
	else
	{
		ImGui::TextV(fmt, args);
	}
}

static bool ColumnLinkValue(const char* str_id, MQColor color, const char* fmt, va_list args)
{
	bool clicked = false;

	if (IsEmptyValue(fmt))
	{
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "%s", fmt);
	}
	else if (strcmp(fmt, "%s") == 0)
	{
		const char* str = va_arg(args, const char*);

		if (IsEmptyValue(str))
			ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), str);
		else
			clicked = imgui::ItemLinkText(str_id, color, "%s", str);
	}
	else
	{
		clicked = imgui::ItemLinkTextV(str_id, color, fmt, args);
	}

	return clicked;
}

static void ColumnNumber(const char* Label, int* number)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	ImGui::PushID(Label);
	ImGui::SetNextItemWidth(-1);
	ImGui::InputInt("##", number);
	ImGui::PopID();

	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

static void ColumnText(const char* Label, const char* fmt, ...)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	va_list args;
	va_start(args, fmt);
	ColumnValue(fmt, args);
	va_end(args);

	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

static void ColumnTextType(const char* Label, const char* Type, const char* fmt, ...)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	va_list args;
	va_start(args, fmt);
	ColumnValue(fmt, args);
	va_end(args);
	ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), Type);
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

static bool ColumnLinkTextType(const char* Label, const char* str_id, const char* Type, const char* fmt, ...)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	va_list args;
	va_start(args, fmt);
	bool clicked = ColumnLinkValue(str_id, GetColorForChatColor(USERCOLOR_LINK), fmt, args);
	va_end(args);
	ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), Type);
	ImGui::TableNextRow();
	ImGui::TableNextColumn();

	return clicked;
}

static bool ColumnCheckBox(const char* Label, bool* value)
{
	bool result = false;
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();
	ImGui::PushID(Label); result = ImGui::Checkbox("", value); ImGui::PopID();
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	return result;
}

static bool ColumnCheckBox(const char* Label, bool value)
{
	bool result = false;
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();
	bool value2 = value;
	ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.6f);
	ImGui::PushID(Label); result = ImGui::Checkbox("", &value2); ImGui::PopID();
	ImGui::PopStyleVar();
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	return result;
}

template <typename T>
static bool ColummCheckBox(const char* Label, T* ptr, bool (T::* getter)(), void (T::* setter)(bool))
{
	bool result = false;
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();
	bool value = ptr->getter();
	ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.6f);
	ImGui::PushID(Label); result = ImGui::Checkbox("", &value); ImGui::PopID();
	if (result) ptr->setter(value);
	ImGui::PopStyleVar();
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	return result;
}

static bool ColummCheckBox(const char* Label, bool (* getter)(), void (* setter)(bool))
{
	bool result = false;
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();
	bool value = getter();
	ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.6f);
	ImGui::PushID(Label); result = ImGui::Checkbox("", &value); ImGui::PopID();
	if (result) setter(value);
	ImGui::PopStyleVar();
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	return result;
}

static bool ColumnCheckBoxFlags(const char* Label, unsigned int* flags, unsigned int flags_value)
{
	bool result = false;
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();
	ImGui::PushID(Label); result = ImGui::CheckboxFlags("", flags, flags_value); ImGui::PopID();
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	return result;
}

template <typename Rep, typename Period>
static bool ColumnElapsedTimestamp(const char* Label, std::chrono::milliseconds ms, std::chrono::duration<Rep, Period> epoch)
{
	bool result = false;
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();
	ImGui::PushID(Label);
	if (ms.count() > 0)
	{
		ms = (std::chrono::duration_cast<std::chrono::milliseconds>(epoch) - ms);

		char szTemp[32] = { 0 };
		fmt::format_to(szTemp, "{:%H:%M:%S}", ms);

		ImGui::TextUnformatted(szTemp);
	}
	else
	{
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(none)");
	}
	ImGui::PopID();
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	return result;
}

static bool ColumnElapsedTimestamp(const char* Label, int32_t ms)
{
	bool result = false;
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();
	ImGui::PushID(Label);
	if (ms != 0)
	{
		auto ms2 = std::chrono::milliseconds(std::abs(ms));

		char szTemp[32] = { 0 };
		fmt::format_to(szTemp, "{:%H:%M:%S}", ms2);

		if (ms < 0)
		{
			strcat_s(szTemp, " ago");
		}

		ImGui::TextUnformatted(szTemp);
	}
	else
	{
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(none)");
	}
	ImGui::PopID();
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	return result;
}

static bool ColumnTreeNode(const char* Label, const char* fmt, ...)
{
	bool result = ImGui::TreeNode(Label); ImGui::TableNextColumn();

	va_list args;
	va_start(args, fmt);
	ColumnValue(fmt, args);
	va_end(args);

	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	return result;
}

static bool ColumnTreeNodeType(const char* Label, const char* Type, const char* fmt, ...)
{
	bool result = ImGui::TreeNode(Label); ImGui::TableNextColumn();

	va_list args;
	va_start(args, fmt);
	ColumnValue(fmt, args);
	va_end(args);
	ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), Type);
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	return result;
}

static bool ColumnTreeNodeType2(const void* Id, const char* Label, const char* Type, const char* fmt, ...)
{
	bool result = ImGui::TreeNode(Id, "%s", Label); ImGui::TableNextColumn();

	va_list args;
	va_start(args, fmt);
	ColumnValue(fmt, args);
	va_end(args);
	ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), Type);
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	return result;
}

template <typename Iter, typename ContentsCb, typename SummaryCb = nullptr_t>
static void ColumnArrayList(const char* Label, const char* Type, int count,
	Iter begin, Iter end, ContentsCb contentsCb, SummaryCb summaryCb = nullptr)
{
	char szTypeLabel[32] = { 0 };
	sprintf_s(szTypeLabel, "%s[]", Type);

	if (ColumnTreeNodeType(Label, szTypeLabel, "%d", count))
	{
		int index = 0;
		for (Iter it = begin; it != end; ++it)
		{
			char szIndexLabel[32] = { 0 };
			sprintf_s(szIndexLabel, "%d", index + 1);

			char szSummaryLabel[256];
			szSummaryLabel[0] = 0;
			if constexpr (!std::is_same_v<SummaryCb, nullptr_t>) {
				summaryCb(szSummaryLabel, 256, *it);
			}

			if (ColumnTreeNodeType(szIndexLabel, Type, szSummaryLabel))
			{
				contentsCb(*it);

				ImGui::TreePop();
			}

			++index;
		}

		ImGui::TreePop();
	}
}

template <typename Iter, typename ContentsCb>
static void ColumnArrayList2(const char* Label, const char* Type, int count,
	Iter begin, Iter end, ContentsCb contentsCb)
{
	char szTypeLabel[32] = { 0 };
	sprintf_s(szTypeLabel, "%s[]", Type);

	if (ColumnTreeNodeType(Label, szTypeLabel, "%d", count))
	{
		int index = 0;
		for (Iter it = begin; it != end; ++it)
		{
			char szIndexLabel[32] = { 0 };
			sprintf_s(szIndexLabel, "%d", index + 1);

			contentsCb(szIndexLabel, *it);
			++index;
		}

		ImGui::TreePop();
	}
}

static bool InputCXRect(const char* label, CXRect& rect)
{
	return ImGui::InputInt4(label, (int*)&rect);
}

inline bool InputCXSize(const char* label, CXSize& size)
{
	return ImGui::InputInt2(label, (int*)&size);
}

inline bool InputCXPoint(const char* label, CXPoint& point)
{
	return ImGui::InputInt2(label, (int*)&point);
}

inline bool InputColorRef(const char* label, COLORREF& color)
{
	ImColor colors{ color };

	if (ImGui::ColorEdit4(label, (float*)&colors))
	{
		color = colors;
		return true;
	}

	return false;
}

inline void ColumnCXStr(const char* Label, CXStr* str)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	ImGui::PushID(Label);
	bool view = ImGui::Button(ICON_FA_PENCIL);
	ImGui::PopID();
	if (view)
	{
		DeveloperTools_WindowInspector_EditString(Label, str);
	}
	ImGui::SameLine();

	if (str->empty())
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(empty)");
	else
		ImGui::Text("%s", str->c_str());

	ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CXStr");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

inline void ColumnString(const char* label, CXStr* str)
{
	ColumnCXStr(label, str);
}

inline void ColumnCXStr(const char* Label, const CXStr& str, bool expandable = true)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	if (expandable)
	{
		ImGui::PushID(Label);
		bool view = ImGui::Button(ICON_FA_EYE);
		ImGui::PopID();
		if (view)
		{
			DeveloperTools_WindowInspector_ViewString(Label, str);
		}
		ImGui::SameLine();
	}

	if (str.empty())
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(empty)");
	else
		ImGui::Text("%s", str.c_str());

	ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CXStr");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

inline void ColumnString(const char* label, const CXStr& str, bool expandable = true)
{
	ColumnCXStr(label, str, expandable);
}

inline void ColumnString(const char* Label, SoeUtil::String* str)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	ImGui::PushID(Label);
	bool view = ImGui::Button(ICON_FA_PENCIL);
	ImGui::PopID();
	if (view)
	{
		DeveloperTools_WindowInspector_EditString(Label, str);
	}
	ImGui::SameLine();

	if (str->empty())
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(empty)");
	else
		ImGui::Text("%s", str->c_str());

	ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "SoeUtil::String");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

inline void ColumnString(const char* Label, const SoeUtil::String& str, bool expandable = true)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	if (expandable)
	{
		ImGui::PushID(Label);
		bool view = ImGui::Button(ICON_FA_EYE);
		ImGui::PopID();
		if (view)
		{
			DeveloperTools_WindowInspector_ViewString(Label, str);
		}
		ImGui::SameLine();
	}

	if (str.empty())
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(empty)");
	else
		ImGui::Text("%s", str.c_str());

	ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "SoeUtil::String");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

inline void ColumnCXSize(const char* Label, const CXSize& size)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	ImGui::Text("{ w=%d, h=%d }", size.cx, size.cy); ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CXSize");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

inline void ColumnCXRect(const char* Label, const CXRect& rect)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	ImGui::Text("{ x=%d, y=%d, w=%d, h=%d }", rect.left, rect.top, rect.GetWidth(), rect.GetHeight()); ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CXRect");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

inline bool ColumnCXRect(const char* Label, CXRect* rect)
{
	bool changed = false;

	if (ColumnTreeNodeType(Label, "CXRect",
		"{ x=%d, y=%d, w=%d, h=%d }", rect->left, rect->top, rect->GetWidth(), rect->GetHeight()))
	{
		// x
		TreeAdvanceToLabelPos(); ImGui::Text("X"); ImGui::TableNextColumn();
		ImGui::SetNextItemWidth(-1.0f);
		int x = rect->left;
		if (ImGui::InputInt("##x", &x))
		{
			changed = true;
			rect->SetLeft(x);
		}
		ImGui::TableNextColumn();
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "int");
		ImGui::TableNextRow();
		ImGui::TableNextColumn();

		// top
		TreeAdvanceToLabelPos(); ImGui::Text("Y"); ImGui::TableNextColumn();
		ImGui::SetNextItemWidth(-1.0f);
		int y = rect->top;
		if (ImGui::InputInt("##y", &y))
		{
			changed = true;
			rect->SetTop(y);
		}
		ImGui::TableNextColumn();
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "int");
		ImGui::TableNextRow();
		ImGui::TableNextColumn();

		// width
		TreeAdvanceToLabelPos(); ImGui::Text("Width"); ImGui::TableNextColumn();
		ImGui::SetNextItemWidth(-1.0f);
		int width = rect->GetWidth();
		if (ImGui::InputInt("##w", &width) && width > 0)
		{
			changed = true;
			rect->SetWidth(width);
		}
		ImGui::TableNextColumn();
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "int");
		ImGui::TableNextRow();
		ImGui::TableNextColumn();

		// height
		TreeAdvanceToLabelPos(); ImGui::Text("Height"); ImGui::TableNextColumn();
		ImGui::SetNextItemWidth(-1.0f);
		int height = rect->GetHeight();
		if (ImGui::InputInt("##h", &height) && height > 0)
		{
			changed = true;
			rect->SetHeight(height);
		}
		ImGui::TableNextColumn();
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "int");
		ImGui::TableNextRow();
		ImGui::TableNextColumn();

		ImGui::TreePop();
	}

	return changed;
}

inline void ColumnCXPoint(const char* Label, const CXPoint& point)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	ImGui::Text("{ x=%d, y=%d }", point.x, point.y); ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CXPoint");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

inline void ColumnCVector3(const char* Label, const CVector3& point)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	ImGui::Text("{ x=%.2f, y=%.2f, z=%.2f }", point.X, point.Y, point.Z); ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CVector3");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}


inline void ColumnColor(const char* Label, MQColor color)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	//ImGui::ColorButton(id, ImGui::ColorConvertU32ToFloat4(color),
	//ColorButton(const char* desc_id, const ImVec4& col, ImGuiColorEditFlags flags = 0, ImVec2 size = ImVec2(0, 0));

	ImGui::PushID(Label);
	ImColor colors = color.ToImColor();

	ImGui::ColorEdit4("", (float*)&colors, ImGuiColorEditFlags_NoInputs); ImGui::TableNextColumn();
	ImGui::PopID();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "Color");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

inline void ColumnColor(const char* Label, const COLORREF& color)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	//ImGui::ColorButton(id, ImGui::ColorConvertU32ToFloat4(color),
	//ColorButton(const char* desc_id, const ImVec4& col, ImGuiColorEditFlags flags = 0, ImVec2 size = ImVec2(0, 0));

	ImGui::PushID(Label);
	ImColor colors = MQColor{ MQColor::format_argb, color }.ToImColor();

	ImGui::ColorEdit4("", (float*)&colors, ImGuiColorEditFlags_NoInputs); ImGui::TableNextColumn();
	ImGui::PopID();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "Color");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

inline void ColumnColor(const char* Label, COLORREF* color)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	//ImGui::ColorButton(id, ImGui::ColorConvertU32ToFloat4(color),
	//ColorButton(const char* desc_id, const ImVec4& col, ImGuiColorEditFlags flags = 0, ImVec2 size = ImVec2(0, 0));

	ImGui::PushID(Label);
	ImColor colors = MQColor{ MQColor::format_argb, *color }.ToImColor();

	bool changed = ImGui::ColorEdit4("", (float*)&colors, ImGuiColorEditFlags_NoInputs); ImGui::TableNextColumn();
	if (changed)
		*color = MQColor(colors).ToARGB();
	ImGui::PopID();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "Color");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

template <typename T>
static bool ColumnColor(const char* Label, T* ptr, COLORREF(T::* getter)() const, void (T::* setter)(COLORREF))
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	ImGui::PushID(Label);
	ImColor colors = MQColor{ MQColor::format_argb, (ptr->*getter)()}.ToImColor();

	bool changed = ImGui::ColorEdit4("", (float*)&colors, ImGuiColorEditFlags_NoInputs); ImGui::TableNextColumn();
	if (changed)
		(ptr->*setter)(MQColor(colors).ToARGB());
	ImGui::PopID();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "Color");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();

	return changed;
}

static bool FontComboGetter(void* data, int n, const char** out_str)
{
	if (n < 0 || n >= pWndMgr->GetNumFonts())
		return false;
	//CTextureFont* pFont = pWndMgr->GetFont(n);
	//if (!pFont) return false;
	//*out_str = pFont->GetName().c_str();
	static char tempName[32];
	sprintf_s(tempName, "Font %d", n + 1);
	*out_str = tempName;
	return true;
}

inline bool ColumnFont(const char* Label, CTextureFont** ppFont)
{
	bool changed = false;
	// Label
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	// Font ComboBox
	if (pWndMgr)
	{
		// Find the current font.
		CTextureFont* pFont = *ppFont;
		int currentIndex = pWndMgr->GetFontIndex(pFont);

		ImGui::SetNextItemWidth(-1.0f);
		if (ImGui::Combo("##FontCombo", &currentIndex, FontComboGetter, nullptr, pWndMgr->GetNumFonts(), 10))
		{
			if (CTextureFont* pNewFont = pWndMgr->GetFont(currentIndex))
			{
				if (*ppFont != pNewFont)
				{
					*ppFont = pNewFont;
					changed = true;
				}
			}
		}
	}
	ImGui::TableNextColumn();

	// DataType
	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CTextureFont*");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();

	return changed;
}

#pragma endregion

#pragma region Widgets - UI Textures

//----------------------------------------------------------------------------

void ColumnTextureAnimationPreview(const char* Label, const CTextureAnimation* pAnim)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	if (!pAnim)
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(null)");
	else
	{
		if (!imgui::DrawTextureAnimation(pAnim, CXSize(), true))
		{
			ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(empty)");
		}
	}

	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

bool ColumnTextureInfoPreview(const char* Label, const CUITextureInfo& textureInfo, const CXRect& rect = CXRect(0, 0, -1, -1))
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	bool result = imgui::DrawUITexture(textureInfo, CXSize(), rect, true);
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	return result;
}

void DisplayUITextureInfo(const char* Label, const CUITextureInfo& textureInfo)
{
	bool show = ColumnTreeNodeType2((const void*)&textureInfo, Label, "CUITextureInfo", "%s", textureInfo.Name.c_str());
	if (show)
	{
		//ColumnCXStr("Name", textureInfo.Name);
		ColumnTextureInfoPreview("Texture", textureInfo);
		ColumnCXSize("Size", textureInfo.TextureSize);
		ColumnText("Texture Id", "%d", textureInfo.TextureId);
		ColumnText("Valid", "%s", textureInfo.bValid ? "true" : "false");
		ColumnText("Directory", "%s", UIDirectoryToString(textureInfo.Directory));

		ImGui::TreePop();
	}
}

void DisplayUITexturePiece(const char* Label, const CUITexturePiece& texturePiece)
{
	bool show = ColumnTreeNodeType2((const void*)&texturePiece, Label, "CUITexturePiece", "%s", texturePiece.GetTextureInfo().Name.c_str());
	if (show)
	{
		ColumnCXStr("Name", texturePiece.GetTextureInfo().Name);
		DisplayUITextureInfo("TextureInfo", texturePiece.GetTextureInfo());
		ColumnCXRect("Rect", texturePiece.GetRect());
		ColumnCXSize("Size", texturePiece.GetSize());
		ColumnTextureInfoPreview("Preview", texturePiece.GetTextureInfo(), texturePiece.GetRect());

		ImGui::TreePop();
	}
}

void DisplaySTextureAnimationFrame(int frameId, const STextureAnimationFrame& frame, bool showNumber)
{
	char labelText[20];
	if (showNumber)
		sprintf_s(labelText, "Frame %d", frameId + 1);
	else
		strcpy_s(labelText, "Frame");

	bool showFrame = ColumnTreeNodeType2((const void*)&frame, labelText, "STextureAnimationFrame", "");
	if (showFrame)
	{
		DisplayUITexturePiece("TexturePiece", frame.Piece);
		ColumnText("Ticks", "%d", frame.Ticks);
		ColumnCXPoint("Hotspot", frame.Hotspot);

		ImGui::TreePop();
	}
}

void DisplayTextureAnimation(const char* Label, const CTextureAnimation* textureAnim, bool doEmpty = true)
{
	if (!textureAnim)
	{
		if (doEmpty)
			ColumnTextType(Label, "CTextureAnimation*", "(null)");
		return;
	}

	bool show = ColumnTreeNodeType(Label, "CTextureAnimation*", "%s", textureAnim->Name.c_str());
	if (show)
	{
		ColumnTextureAnimationPreview("Texture", textureAnim);
		ColumnCXSize("Size", textureAnim->bGrid ? textureAnim->CellRect.GetSize() : textureAnim->Size);

		if (ColumnTreeNode("Details", ""))
		{
			ColumnCXStr("Name", textureAnim->Name);

			if (textureAnim->Frames.GetLength() > 1)
			{
				bool showFrames = ColumnTreeNodeType("Frames", "STextureAnimationFrame[]", "%d", textureAnim->Frames.GetLength());
				if (showFrames)
				{
					for (int i = 0; i < textureAnim->Frames.GetLength(); ++i)
					{
						const STextureAnimationFrame& frame = textureAnim->Frames[i];

						DisplaySTextureAnimationFrame(i, frame, true);
					}

					ImGui::TreePop();
				}
			}
			else if (textureAnim->Frames.GetLength() == 1)
			{
				const STextureAnimationFrame& frame = textureAnim->Frames[0];

				DisplaySTextureAnimationFrame(0, frame, false);
			}
			else
			{
				ColumnText("Frames", "No frames");
			}

			ColumnText("Paused", textureAnim->bPaused ? "true" : "false");
			ColumnText("Vertical", textureAnim->bVertical ? "true" : "false");
			ColumnText("Grid", textureAnim->bGrid ? "true" : "false");

			if (textureAnim->bGrid)
			{
				ColumnCXSize("Cell size", CXSize(textureAnim->CellWidth, textureAnim->CellHeight));
				ColumnCXRect("Cell rect", textureAnim->CellRect);
				ColumnText("Current cell", "%d", textureAnim->CurCell);
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_NOS)
				ColumnText("Current cell in frame", "%d", textureAnim->CurCellInFrame);
#endif
			}

			if (textureAnim->ZeroFrame != 0)
			{
				ColumnText("Zero frame", "%d", textureAnim->ZeroFrame);
			}

			ColumnText("Cycle animation", textureAnim->bCycle ? "true" : "false");
			ColumnText("Total ticks", "%d", textureAnim->TotalTicks);
			ColumnText("Start ticks", "%d", textureAnim->StartTicks);

			ImGui::TreePop();
		}

		ImGui::TreePop();
	}
}

void DisplayTAFrameDraw(const char* Label, const CTAFrameDraw& frameDraw)
{
	bool show = ColumnTreeNodeType2((const void*)&frameDraw, Label, "CTAFrameDraw", "%s", frameDraw.GetName().c_str());
	if (show)
	{
		ColumnCXStr("Name", frameDraw.GetName());
		ColumnCXSize("Frame size", frameDraw.GetFrameSize());

		for (int i = 0; i < CTAFrameDraw::FrameDraw_Max; ++i)
		{
			CTextureAnimation* anim = frameDraw.GetAnimation(static_cast<CTAFrameDraw::EFrameDrawPiece>(i));
			if (!anim)
				continue;

			DisplayTextureAnimation(
				CTAFrameDraw::FrameDrawPieceToString(static_cast<CTAFrameDraw::EFrameDrawPiece>(i)),
				anim);
		}

		ImGui::TreePop();
	}
}

#pragma endregion

#pragma region Widgets - Templates

void DisplayDrawTemplate(const char* label, const CButtonDrawTemplate& drawTemplate)
{
	bool show = ColumnTreeNodeType2((const void*)&drawTemplate, label, "CButtonDrawTemplate", "%s", drawTemplate.strName.c_str());
	if (show)
	{
		ColumnCXStr("Name", drawTemplate.strName);
		DisplayTextureAnimation("Normal", drawTemplate.ptaNormal, false);
		DisplayTextureAnimation("Pressed", drawTemplate.ptaPressed, false);
		DisplayTextureAnimation("Hover", drawTemplate.ptaFlyby, false);
		DisplayTextureAnimation("Disabled", drawTemplate.ptaDisabled, false);
		DisplayTextureAnimation("Pressed hover", drawTemplate.ptaPressedFlyby, false);
		DisplayTextureAnimation("Pressed disabled", drawTemplate.ptaPressedDisabled, false);
		DisplayTextureAnimation("Normal decal", drawTemplate.ptaNormalDecal, false);
		DisplayTextureAnimation("Pressed decal", drawTemplate.ptaPressedDecal, false);
		DisplayTextureAnimation("Hover decal", drawTemplate.ptaFlybyDecal, false);
		DisplayTextureAnimation("Disabled decal", drawTemplate.ptaDisabledDecal, false);
		DisplayTextureAnimation("Pressed hover decal", drawTemplate.ptaPressedFlybyDecal, false);
		DisplayTextureAnimation("Pressed disabled decal", drawTemplate.ptaPressedDisabledDecal, false);

		ImGui::TreePop();
	}
}

void DisplayDrawTemplate(const char* label, const CSpellGemDrawTemplate& drawTemplate)
{
	if (ColumnTreeNodeType2((const void*)&drawTemplate, label, "CSpellGemDrawTemplate", "%s", drawTemplate.strName.c_str()))
	{
		ColumnCXStr("Name", drawTemplate.strName);

		DisplayTextureAnimation("Background", drawTemplate.ptaBackground);
		DisplayTextureAnimation("Holder", drawTemplate.ptaHolder);
		DisplayTextureAnimation("Highlight", drawTemplate.ptaHighlight);

		ImGui::TreePop();
	}
}

void DisplayDrawTemplate(const char* label, const CScrollbarTemplate& drawTemplate)
{
	bool show = ColumnTreeNodeType2((const void*)&drawTemplate, label, "CScrollbarTemplate", "%s", drawTemplate.strName.c_str());
	if (show)
	{
		ColumnCXStr("Name", drawTemplate.strName);
		DisplayDrawTemplate("Up Button", drawTemplate.bdtUp);
		DisplayDrawTemplate("Down Button", drawTemplate.bdtDown);
		DisplayTAFrameDraw("Thumb", drawTemplate.frameThumb);
		DisplayUITextureInfo("Middle", drawTemplate.tiMiddle);
		ColumnColor("Middle tint", drawTemplate.colorMiddleTint);

		ImGui::TreePop();
	}
}

void DisplayDrawTemplate(const char* label, const CXWndDrawTemplate* drawTemplate)
{
	if (!drawTemplate)
	{
		ColumnTextType(label, "CXWndDrawTemplate*", "(null)");
		return;
	}

	bool show = ColumnTreeNodeType2(drawTemplate, label, "CXWndDrawTemplate*", "%s", drawTemplate->strName.c_str());
	if (show)
	{
		ColumnCXStr("Name", drawTemplate->strName);
		DisplayUITextureInfo("Background texture", drawTemplate->tiBackground);
		ColumnText("Background type",
			XWndBackgroundDrawTypeToString(static_cast<XWndBackgroundDrawType>(drawTemplate->nBackgroundDrawType)));
		DisplayDrawTemplate("Vertical scroll bar", drawTemplate->sbtVScroll);
		DisplayDrawTemplate("Horizontal scroll bar", drawTemplate->sbtHScroll);
		DisplayDrawTemplate("Close box", drawTemplate->bdtCloseBox);
		DisplayDrawTemplate("Help box", drawTemplate->bdtQMarkBox);
		DisplayDrawTemplate("Minimize box", drawTemplate->bdtMinimizeBox);
		DisplayDrawTemplate("Maximize box", drawTemplate->bdtMaximizeBox);
		DisplayDrawTemplate("Tile box", drawTemplate->bdtTileBox);
		DisplayTAFrameDraw("Border", drawTemplate->frameBorder);
		DisplayTAFrameDraw("Title bar", drawTemplate->frameTitlebar);

		ImGui::TreePop();
	}
}

void DisplayDynamicTemplateExpand(const char* label, const CScreenPieceTemplate* pTemplate, const char* szTypeString = "CScreenPieceTemplate*");

void DisplayLayoutStrategyTemplate(const CLayoutStrategyTemplate* pTemplate)
{
	ColumnCXStr("Name", pTemplate->strName);
	ColumnText("Padding", "%d", pTemplate->nPadding);
	ColumnText("Type", "%d", pTemplate->nType);
	ColumnCheckBox("Resize Horizontal", pTemplate->bResizeHorizontal);
	ColumnCheckBox("Resize Vertical", pTemplate->bResizeVertical);
}

void DisplayListboxColumnTemplate(const CListboxColumnTemplate* pTemplate)
{
}

void DisplayScreenPieceTemplate(const CScreenPieceTemplate* pTemplate)
{
	uint32_t uParamObjectId = pTemplate->uParamObjectId;

	if (CXMLData* pXMLData = pSidlMgr->GetParamManager()->GetXMLData(uParamObjectId))
	{
		// Type
		ColumnText("Type", "%s (%d)", pXMLData->TypeName.c_str(), pXMLData->Type);
	}

	ColumnCXStr("Name", pTemplate->strName);
	ColumnText("Object Id", "%d", pTemplate->uParamObjectId);
	ColumnCXStr("Screen ID", pTemplate->strScreenId);

	std::vector<int> runtimeTypeInts;
	for (int i = 0; i < pTemplate->arRuntimeTypes.GetLength(); ++i)
		runtimeTypeInts.push_back(pTemplate->arRuntimeTypes[i]);
	std::string runtimeTypes = fmt::format("[{}]", fmt::join(runtimeTypeInts, ", "));

	if (ColumnTreeNodeType2(&pTemplate->arRuntimeTypes, "Runtime Types", "ArrayClass2<int>", "%s", runtimeTypes.c_str()))
	{
		for (int i = 0; i < pTemplate->arRuntimeTypes.GetLength(); ++i)
		{
			char szLabel[10] = { 0 };
			fmt::format_to(szLabel, "#{}", i + 1);
			ColumnText(szLabel, "%s (%d)", UITypeToString(static_cast<UIType>(pTemplate->arRuntimeTypes[i])), pTemplate->arRuntimeTypes[i]);
		}

		ImGui::TreePop();
	}

	// TODO: Font
	// TODO: RelativePosition
	// TODO: AutoStretchVertical
	// TODO: AutoStretchHorizontal
	// TODO: TopAnchorToTop
	// TODO: BottomAnchorToTop
	// TODO: LeftAnchorToLeft
	// TODO: RightAnchorToRight
	// TODO: TopOffset
	// TODO: BottomOffset
	// TODO: LeftOffset
	// TODO: RightOffset
	// TODO: MinVSize
	// TODO: MinHSize
	// TODO: MaxVSize
	// TODO: MaxHSize
	// TODO: UseInLayoutHorizontal
	// TODO: UseInLayoutVertical

	if (ColumnTreeNode("Colors", ""))
	{
		ColumnCXRect("Rect", pTemplate->rect);
		ColumnCXStr("Text", pTemplate->strText);
		ColumnColor("Text Color", pTemplate->colorText);
		ColumnColor("Disabled Color", pTemplate->colorDisabled);
		ColumnColor("Enabled Color", pTemplate->colorEnabled);
		ColumnColor("Background Texture Tint", pTemplate->colorBackgroundTextureTint);
		ColumnColor("Disabled Background Texture Tint", pTemplate->colorDisabledBackgroundTextureTint);

		ImGui::TreePop();
	}
}

void DisplayStaticAnimationTemplate(const CStaticAnimationTemplate* pTemplate)
{
	DisplayScreenPieceTemplate(pTemplate);
	DisplayTextureAnimation("Texture", pTemplate->ptaTextureAnimation, true);
}

void DisplayStaticScreenPieceTemplate(const CStaticScreenPieceTemplate* pTemplate)
{
	DisplayScreenPieceTemplate(pTemplate);
	ColumnCheckBox("Auto Draw", pTemplate->bAutoDraw);
}

void DisplayStaticTintedBlendAnimationTemplate(const CStaticTintedBlendAnimationTemplate* pTemplate)
{
	DisplayStaticScreenPieceTemplate(pTemplate);

	DisplayTextureAnimation("Layer 1", pTemplate->ptaLayerOneTexture);
	DisplayTextureAnimation("Layer 2", pTemplate->ptaLayerTwoTexture);
	ColumnColor("Layer 1 Tint", pTemplate->colorLayerOneTint);
	ColumnColor("Layer 2 Tint", pTemplate->colorLayerTwoTint);
}

void DisplayControlTemplate(const CControlTemplate* pTemplate)
{
	DisplayScreenPieceTemplate(pTemplate);

	// TODO: StyleBits
	// TODO: SizableMask
	ColumnCheckBox("Escapable", pTemplate->bEscapable);
	ColumnCXStr("Tooltip", pTemplate->strTooltip);
	DisplayDrawTemplate("Draw Template", pTemplate->pDrawTemplate);
	ColumnCXStr("Controller", pTemplate->strController);

	if (pTemplate->pLayoutStrategyTemplate)
	{
		if (ColumnTreeNodeType("Layout Strategy", "CLayoutStrategyTemplate*", "%s",
			pTemplate->pLayoutStrategyTemplate->strName.c_str()))
		{
			DisplayLayoutStrategyTemplate(pTemplate->pLayoutStrategyTemplate);

			ImGui::TreePop();
		}
	}
	else
	{
		ColumnTextType("Layout Strategy", "CLayoutStrategyTemplate*", "(null)");
	}
}

void DisplayLayoutBoxTemplate(const CLayoutBoxTemplate* pTemplate)
{
	DisplayControlTemplate(pTemplate);
}

void DisplayScreenTemplate(const CScreenTemplate* pTemplate);

// Looks up the type and casts it to the appropriate template type.
void DisplayDynamicTemplate(CXMLData* pXMLData, const CScreenPieceTemplate* pTemplate)
{
	switch (pXMLData->Type)
	{
	case UI_Screen:
		DisplayScreenTemplate(static_cast<const CScreenTemplate*>(pTemplate));
		break;

	case UI_Control:
	case UI_HotButton:
	case UI_Listbox:
	case UI_EditBox:
	case UI_Slider:
	case UI_Label:
	case UI_STMLBox:
	case UI_TreeView:
	case UI_Combobox:
	case UI_Button:
	case UI_Gauge:
	case UI_SpellGem:
	case UI_InvSlot:
	case UI_Page:
	case UI_TabBox:
	case UI_LayoutBox:
	case UI_HorizontalLayoutBox:
	case UI_VerticalLayoutBox:
	case UI_TileLayoutBox:
	case UI_TemplateContainer:
		DisplayControlTemplate(static_cast<const CControlTemplate*>(pTemplate));
		break;

	case UI_ListboxColumn:
		break; // not a screen piece

	case UI_StaticAnimation:
		DisplayStaticAnimationTemplate(static_cast<const CStaticAnimationTemplate*>(pTemplate));
		break;

	case UI_StaticScreenPiece:
		DisplayStaticScreenPieceTemplate(static_cast<const CStaticScreenPieceTemplate*>(pTemplate));
		break;

	case UI_StaticTintedBlendAnimation:
		DisplayStaticTintedBlendAnimationTemplate(static_cast<const CStaticTintedBlendAnimationTemplate*>(pTemplate));
		break;

	case UI_StaticText:
	case UI_StaticFrame:
	case UI_StaticHeader:
	default:
		DisplayScreenPieceTemplate(pTemplate);
	}
}

void DisplayDynamicTemplateExpand(const char* label, const CScreenPieceTemplate* pTemplate, const char* szTypeString)
{
	if (!pTemplate)
	{
		ColumnTextType(label, szTypeString, "(null)");
		return;
	}

	uint32_t uParamObjectId = pTemplate->uParamObjectId;
	if (CXMLData* pXMLData = pSidlMgr->GetParamManager()->GetXMLData(uParamObjectId))
	{
		if (ColumnTreeNodeType(label, UITypeToScreenPieceTemplateType(pXMLData->Type), "%s", pTemplate->strName.c_str()))
		{
			DisplayDynamicTemplate(pXMLData, pTemplate);

			ImGui::TreePop();
		}
	}
	else
	{
		if (ColumnTreeNodeType(label, szTypeString, "%s", pTemplate->strName.c_str()))
		{
			DisplayScreenPieceTemplate(pTemplate);

			ImGui::TreePop();
		}
	}
}

void DisplayScreenTemplate(const CScreenTemplate* pTemplate)
{
	DisplayControlTemplate(pTemplate);

	// TODO: Pieces
	int index = 0;
	for (CScreenPieceTemplate* pChildTemplate : pTemplate->Pieces)
	{
		char text[32];
		sprintf_s(text, "Piece[%d]", index++);

		DisplayDynamicTemplateExpand(text, pChildTemplate);
	}
}

template <typename T>
void DisplayTemplate(const char* label, const char* type, const T* pTemplate)
{
	if (!pTemplate)
	{
		ColumnTextType(label, type, "(null)");
		return;
	}

	if (ColumnTreeNodeType2(pTemplate, label, type, "%s", pTemplate->strName.c_str()))
	{
		DisplayScreenTemplate(pTemplate);

		ImGui::TreePop();
	}
}

#pragma endregion

#pragma region Widgets - Misc References

void DisplayTextObject(const char* label, CTextObjectInterface* pTextObjectInterface)
{
	if (!pTextObjectInterface)
	{
		ColumnTextType(label, "CTextObject*", "(null)");
		return;
	}

	CTextObjectBase* pTextObject = static_cast<CTextObjectBase*>(pTextObjectInterface);

	if (ColumnTreeNodeType2(pTextObject, label, "CTextObject*", "%s", pTextObject->GetText().c_str()))
	{
		ColumnCXStr("Text", pTextObject->GetText());
		ColumnColor("Color", pTextObject->GetColor());

		ImGui::TreePop();
	}
}

void ColumnWindow(const char* Label, CXWnd* window)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	if (!window)
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(null)");
	else
	{
		ImGui::PushID(window);
		//ImGui::SetNextItemWidth(21);
		bool view = ImGui::Button(ICON_FA_EXTERNAL_LINK_SQUARE);
		ImGui::PopID();
		if (view)
		{
			DeveloperTools_WindowInspector_Show(window);
		}

		ImGui::SameLine();

		CXStr name = window->GetXMLName();
		if (name.empty())
			ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .75f), "(Unnamed)");
		else
			ImGui::Text("%s", name.c_str());

		if (ImGui::IsItemHovered())
		{
			DeveloperTools_windowInspector_SetHoveredWindow(window);
		}
	}
	ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CXWnd");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}

#if HAS_GAMEFACE_UI
void ColumnWindow(const char* Label, eqlib::eqmain::CXWnd* window)
{
	TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();

	if (!window)
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(null)");
	else
	{
		ImGui::PushID(window);
		//ImGui::SetNextItemWidth(21);
		bool view = ImGui::Button(ICON_FA_EXTERNAL_LINK_SQUARE);
		ImGui::PopID();
		if (view)
		{
			DeveloperTools_WindowInspector_Show(reinterpret_cast<CXWnd*>(window));
		}

		ImGui::SameLine();

		CXStr name = window->GetXMLName();
		if (name.empty())
			ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .75f), "(Unnamed)");
		else
			ImGui::Text("%s", name.c_str());

		if (ImGui::IsItemHovered())
		{
			DeveloperTools_windowInspector_SetHoveredWindow(reinterpret_cast<CXWnd*>(window));
		}
	}
	ImGui::TableNextColumn();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CXWnd");
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
}
#endif // HAS_GAMEFACE_UI

void ColumnItemContainerInstance(const char* Label, ItemContainerInstance instance)
{
	ColumnTextType(Label, "ItemContainerInstance", GetNameForContainerInstance(instance));
}

void ColumnItemIndex(const char* Label, const ItemIndex& index)
{
	char indexStr[32];
	index.FormatItemIndex(indexStr, lengthof(indexStr));

	ColumnTextType(Label, "ItemIndex", "%s", indexStr);
}

void ColumnItemGlobalIndex(const char* Label, const ItemGlobalIndex& index)
{
	char globIndexStr[32];

	strcpy_s(globIndexStr, GetNameForContainerInstance(index.GetLocation()));
	strcat_s(globIndexStr, ": ");

	char indexStr[32];
	index.GetIndex().FormatItemIndex(indexStr, lengthof(indexStr));
	strcat_s(globIndexStr, indexStr);

	// Maybe in future this can be used to look up the item in another inspector.
	if (ColumnTreeNodeType2(&index, Label, "ItemGlobalIndex", "%s", globIndexStr))
	{
		ColumnItemContainerInstance("Container", index.GetLocation());
		ColumnItemIndex("Index", index.GetIndex());

		ImGui::TreePop();
	}
}

void ColumnItem(const char* Label, const ItemPtr& pItem)
{
	if (ColumnLinkTextType(Label, pItem ? pItem->ItemGUID.guid : "blank", "ItemPtr", "%s", pItem ? pItem->GetName() : "(null)"))
	{
		if (pItemDisplayManager) pItemDisplayManager->ShowItem(pItem);
	}
}

bool ColumnEQZoneIndex(const char* Label, EQZoneIndex zoneId, bool treeNode = false, const char* type = nullptr)
{
	bool result = true;

	if (treeNode)
	{
#pragma warning(suppress : 4312)
		result = ImGui::TreeNode((void*)zoneId, Label); ImGui::TableNextColumn();
	}
	else
	{
		TreeAdvanceToLabelPos(); ImGui::TextUnformatted(Label); ImGui::TableNextColumn();
	}

	EQZoneInfo* pZoneInfo = pWorldData->GetZone(zoneId);
	if (pZoneInfo && pZoneInfo->Id > 0)
	{
		ImGui::TextColored(MQColor(0, 255, 255).ToImColor(), "%s", pZoneInfo->LongName);

		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::TextColored(MQColor(0, 255, 255).ToImColor(), pZoneInfo->LongName);
			ImGui::Separator();

			ImGui::TextUnformatted("Short name:"); ImGui::SameLine(0.0f, 4.0f); ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "%s", pZoneInfo->ShortName);
			ImGui::TextUnformatted("Zone ID:"); ImGui::SameLine(0.0f, 4.0f); ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "%d", zoneId);
			ImGui::TextUnformatted("Expansion:"); ImGui::SameLine(0.0f, 4.0f); ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "%s", GetZoneExpansionName(pZoneInfo->EQExpansion));

			ImGui::EndTooltip();
		}
	}
	else
	{
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(none)");
	}

	ImGui::TableNextColumn();
	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), type ? type : "EQZoneIndex");

	ImGui::TableNextRow();
	ImGui::TableNextColumn();

	return result;
}

#pragma endregion

#pragma region Property Viewer
#pragma region Property Viewer - Table

struct WindowPropertiesTable
{
	inline static ImU32 s_propertyColors[] = {
		MQColor(4, 32, 39, 120).ToImU32(),
		MQColor(39, 32, 4, 120).ToImU32(),
		MQColor(70, 23, 10, 80).ToImU32(),
		MQColor(42, 20, 68, 80).ToImU32(),
		MQColor(66, 68, 20, 80).ToImU32(),
		MQColor(68, 20, 67, 80).ToImU32(),
	};

	int m_currentColor = 0;
	bool m_started = false;

public:
	void Reset()
	{
		m_currentColor = 0;
		m_started = false;
	}

	bool Begin()
	{
		ImGuiTableFlags tableFlags = ImGuiTableFlags_ScrollY
			| ImGuiTableFlags_BordersV
			| ImGuiTableFlags_BordersH
			| ImGuiTableFlags_Resizable
			| ImGuiTableFlags_RowBg
			;

		// Set up a table with three columns: Name, Value, Type
		if (!ImGui::BeginTable("##WindowDetailsTable", 3, tableFlags) && !m_started)
			return false;

		if (!m_started)
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("Property", ImGuiTableColumnFlags_NoHide | ImGuiTableColumnFlags_WidthFixed, 120.f);
			ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_NoHide | ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthFixed, 40.0f);
			ImGui::TableHeadersRow();
		}

		m_started = true;
		ImGui::TableNextRow();
		ImGui::TableNextColumn();

		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4);
		return true;
	}

	void End()
	{
		if (m_currentColor != 0)
			ImGui::PopStyleColor(2);

		ImGui::PopStyleVar();
		ImGui::EndTable();
	}

	bool StartNewSection(const char* sectionName, bool open)
	{
		if (m_currentColor != 0)
			ImGui::PopStyleColor(2);

		// black background for heading.
		ImU32 black = IM_COL32_BLACK;
		ImGui::PushStyleColor(ImGuiCol_TableRowBg, (ImU32)black);
		ImGui::PushStyleColor(ImGuiCol_TableRowBgAlt, (ImU32)black);

		bool expand = ImGui::CollapsingHeader(sectionName, open ? ImGuiTreeNodeFlags_DefaultOpen : 0);
		ImGui::PopStyleColor(2);
		ImGui::TableNextRow();
		ImGui::TableNextColumn();

		ImColor rowColor = s_propertyColors[m_currentColor++];
		if (m_currentColor >= (int)lengthof(s_propertyColors))
			m_currentColor = 0;

		ImGui::PushStyleColor(ImGuiCol_TableRowBg, (ImU32)rowColor);
		ImGui::PushStyleColor(ImGuiCol_TableRowBgAlt, (ImU32)rowColor);

		return expand;
	}
};

#pragma endregion
#pragma region Property Viewer - String Viewer

struct StringStorage
{
public:
	StringStorage(const CXStr& str)
		: m_storage(str)
		, m_mutable(false)
	{
	}

	StringStorage(const SoeUtil::String& str)
		: m_storage(str)
		, m_mutable(false)
	{
	}

	StringStorage(const std::string& str)
		: m_storage(str)
		, m_mutable(false)
	{
	}

	StringStorage(const eqstd::string& str)
		: m_storage(str)
		, m_mutable(false)
	{
	}

	StringStorage(CXStr* str)
		: m_storage(str)
		, m_mutable(true)
	{
	}

	StringStorage(SoeUtil::String* str)
		: m_storage(str)
		, m_mutable(true)
	{
	}

	StringStorage(std::string* str)
		: m_storage(str)
		, m_mutable(true)
	{
	}

	StringStorage(eqstd::string* str)
		: m_storage(str)
		, m_mutable(true)
	{
	}

	bool IsMutable() const { return m_mutable; }

private:
	template <typename T>
	static std::string_view read_string_view(T* ptr)
	{
		if (ptr)
			return std::string_view(*ptr);

		return {};
	}

	template <typename T>
	static std::string_view read_string_view(const T& str)
	{
		return std::string_view(str);
	}

	template <typename T>
	static void write_string_view(T* ptr, std::string_view sv)
	{
		if (ptr)
			*ptr = sv;
	}

	template <typename T>
	static void write_string_view(const T&, std::string_view) 
	{
		// Its immutable
	}

public:
	std::string_view GetStringView() const
	{
		return std::visit([](const auto& str) -> std::string_view
			{ return read_string_view(str); }, m_storage);
	}

	void Assign(std::string_view sv)
	{
		if (m_mutable)
			std::visit([&sv](auto& str) { write_string_view(str, sv); }, m_storage);
	}

	using Storage = std::variant<
		CXStr,
		SoeUtil::String,
		std::string,
		eqstd::string,
		CXStr*,
		SoeUtil::String*,
		std::string*,
		eqstd::string*
	>;

	Storage m_storage;
	bool m_mutable;
};

class ImGuiWindowStringEditor
{
public:
	ImGuiWindowStringEditor(std::string_view name, const CXStr& readOnlyString)
		: m_storage(readOnlyString)
		, m_stringName(name)
	{
	}

	ImGuiWindowStringEditor(std::string_view name, CXStr* mutableString)
		: m_storage(mutableString)
		, m_stringName(name)
	{
	}

	ImGuiWindowStringEditor(std::string_view name, const SoeUtil::String& readOnlyString)
		: m_storage(readOnlyString)
		, m_stringName(name)
	{
	}

	ImGuiWindowStringEditor(std::string_view name, SoeUtil::String* mutableString)
		: m_storage(mutableString)
		, m_stringName(name)
	{
	}

	ImGuiWindowStringEditor(std::string_view name, const std::string& readOnlyString)
		: m_storage(readOnlyString)
		, m_stringName(name)
	{
	}

	ImGuiWindowStringEditor(std::string_view name, std::string* mutableString)
		: m_storage(mutableString)
		, m_stringName(name)
	{
	}

	ImGuiWindowStringEditor(std::string_view name, const eqstd::string& readOnlyString)
		: m_storage(readOnlyString)
		, m_stringName(name)
	{
	}

	ImGuiWindowStringEditor(std::string_view name, eqstd::string* mutableString)
		: m_storage(mutableString)
		, m_stringName(name)
	{
	}

	ImGuiWindowStringEditor(ImGuiWindowStringEditor&& other) noexcept
		: m_storage(other.m_storage)
		, m_stringName(std::move(other.m_stringName))
		, m_textEditor(std::move(other.m_textEditor))
		, m_closeRequested(other.m_closeRequested)
		, m_changed(other.m_changed)
		, m_requestFocus(other.m_requestFocus)
	{
	}

	~ImGuiWindowStringEditor()
	{
	}

	ImGuiWindowStringEditor& operator=(ImGuiWindowStringEditor&& other) noexcept
	{
		m_storage = other.m_storage;
		m_stringName = std::move(other.m_stringName);
		m_closeRequested = other.m_closeRequested;
		m_textEditor = std::move(other.m_textEditor);
		m_changed = other.m_changed;
		m_requestFocus = other.m_requestFocus;
		return *this;
	}

	bool IsMutable() const { return m_storage.IsMutable(); }

	void Render(bool* open)
	{
		if (m_requestFocus)
		{
			ImGui::SetNextWindowFocus();
			m_requestFocus = false;
		}

		ImGui::SetNextWindowSize(ImVec2(320, 220), ImGuiCond_Appearing);
		if (ImGui::Begin(m_stringName.c_str(), open, m_changed ? ImGuiWindowFlags_UnsavedDocument : 0))
		{
			ImGui::SetNextItemWidth(-1.0f);

			if (!m_storage.IsMutable())
			{
				std::string_view sv = m_storage.GetStringView();

				ImGui::TextWrapped("%.*s", static_cast<uint32_t>(sv.length()), sv.data());
			}
			else
			{
				if (!m_textEditor)
				{
					m_textEditor = std::make_unique<mq::ImGuiZepEditor>("##StringEditor");
					m_textEditor->SetWindowFlags(Zep::WindowFlags::ShowLineNumbers);

					m_textEditor->GetEditor().InitWithText(m_stringName, m_storage.GetStringView());
				}

				m_textEditor->Render(ImVec2(0, ImGui::GetContentRegionAvail().y - 26));

				auto buffer = m_textEditor->GetActiveBuffer();
				if (buffer->HasFileFlags(Zep::FileFlags::Dirty))
				{
					m_changed = true;
				}

				if (ImGui::Button("Save"))
				{
					m_changed = false;
					m_storage.Assign(buffer->GetText());

					buffer->ClearFileFlags(Zep::FileFlags::Dirty);
				}

				ImGui::SameLine();
			}

			if (ImGui::Button("Close"))
			{
				m_closeRequested = true;
				*open = false;
			}
		}

		ImGui::End();
	}

	StringStorage m_storage;
	std::string m_stringName;
	std::unique_ptr<ImGuiZepEditor> m_textEditor;
	bool m_closeRequested = false;
	bool m_changed = false;
	bool m_requestFocus = false;
};

#pragma endregion
#pragma region Property Viewer - ImGuiWindowPropertyViewer

class ImGuiWindowPropertyViewer
{
	CXWnd* m_window = nullptr;
	std::string m_windowDisplayName;
	std::string m_viewerTitle;

	WindowPropertiesTable m_table;
	int m_instanceId = 0;
	bool m_needDock = true;
	bool m_needFocus = false;
	std::vector<ImGuiWindowStringEditor> m_stringEditors;
	inline static ImGuiWindowPropertyViewer* s_currentPropertyViewer = nullptr;

public:
	static ImGuiWindowPropertyViewer* GetCurrentViewer() { return s_currentPropertyViewer; }

public:
	ImGuiWindowPropertyViewer(int instanceId, CXWnd* pWnd = nullptr)
		: m_instanceId(instanceId)
	{
		SetWindow(pWnd);
	}

	void SetNeedDock(bool need) { m_needDock = need; }
	bool GetNeedDock() const { return m_needDock; }

	void SetNeedFocus(bool need) { m_needFocus = need; }

	int GetInstanceId() const { return m_instanceId; }
	const char* GetWindowId() const { return m_viewerTitle.c_str(); }

	void SetWindow(CXWnd* pWindow)
	{
		if (!test_and_set(m_window, pWindow))
			return;

		m_needFocus = true;

		if (m_window)
		{
			m_windowDisplayName = m_window->GetXMLName();

			// TODO: Might be empty string for dynamic windows.
		}
		else
		{
			m_windowDisplayName = "(none)";
		}

		if (m_instanceId == 1)
		{
			m_viewerTitle = fmt::format("Selected: {}###WindowPropertyViewer{}", m_windowDisplayName, m_instanceId);
		}
		else
		{
			m_viewerTitle = fmt::format("Wnd: {}###WindowPropertyViewer{}", m_windowDisplayName, m_instanceId);
		}
	}

	CXWnd* GetWindow() const { return m_window; }
	const char* GetWindowName() const { return m_windowDisplayName.c_str(); }

	bool Draw()
	{
		if (m_needFocus)
		{
			ImGui::SetNextWindowFocus();
			m_needFocus = false;
		}

		bool open = true;

		ImGui::SetNextWindowSize(ImVec2(480, 640), ImGuiCond_FirstUseEver);
		if (ImGui::Begin(m_viewerTitle.c_str(), &open))
		{
			ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 9);

			if (!m_window)
			{
				ImGui::Text("Select a window to see details");
				return open;
			}

			s_currentPropertyViewer = this;
			DisplayPropertiesPanel();
			s_currentPropertyViewer = nullptr;
		}

		ImGui::End(); // Begin properties

		DrawStringEditors();

		return open;
	}

	void DrawStringEditors()
	{
		bool closeRequestedAny = false;
		for (auto& stringEditor : m_stringEditors)
		{
			bool open = true;

			stringEditor.Render(&open);

			if (!open)
			{
				stringEditor.m_closeRequested = true;
				closeRequestedAny = true;
			}
		}

		// If a window was requested to be closed, remove it from the list of windows
		if (closeRequestedAny)
		{
			m_stringEditors.erase(
				std::remove_if(m_stringEditors.begin(), m_stringEditors.end(),
					[](const auto& editor) { return editor.m_closeRequested; }),
				m_stringEditors.end());
		}
	}

	void AddStringEditor(ImGuiWindowStringEditor editor)
	{
		editor.m_stringName = fmt::format("String {}: {} - {}",
			!editor.IsMutable() ? "Viewer" : "Editor", m_windowDisplayName, editor.m_stringName);
		m_stringEditors.push_back(std::move(editor));
		editor.m_requestFocus = true;
	}

	bool BeginColorSection(const char* properties, bool open)
	{
		return m_table.StartNewSection(properties, open);
	}

	void DisplayPropertiesPanel()
	{
		if (!m_window)
			return;

		m_table.Reset();
		if (!m_table.Begin())
			return;

#if HAS_GAMEFACE_UI
		if (GetGameState() == GAMESTATE_PRECHARSELECT)
		{
			// Trying to support all of this just for login is nuts.
			DisplayCXWndProperties(reinterpret_cast<eqlib::eqmain::CXWnd*>(m_window));
			m_table.End();
			return;
		}
#endif

		switch (m_window->GetType())
		{
		case UI_Screen:
			DisplayCSidlScreenWndProperties(static_cast<CSidlScreenWnd*>(m_window));
			break;

		case UI_Button:
			DisplayCButtonWndProperties(static_cast<CButtonWnd*>(m_window));
			break;

		case UI_SpellGem:
			DisplayCSpellGemWndProperties(static_cast<CSpellGemWnd*>(m_window));
			break;

		case UI_Page:
			DisplayCPageWndProperties(static_cast<CPageWnd*>(m_window));
			break;

		case UI_LayoutBox:
			DisplayLayoutWndProperties(static_cast<CLayoutWnd*>(m_window));
			break;

		case UI_HorizontalLayoutBox:
			DisplayHorizontalLayoutWndProperties(static_cast<CHorizontalLayoutWnd*>(m_window));
			break;

		case UI_VerticalLayoutBox:
			DisplayVerticalLayoutWndProperties(static_cast<CVerticalLayoutWnd*>(m_window));
			break;

		case UI_TileLayoutBox:
			DisplayTileLayoutWndProperties(static_cast<CTileLayoutWnd*>(m_window));
			break;

		case UI_Label:
			// All labels with UI_Label were created by XML. they are CLabels.
			// Any other label with the WRT_LABEL type are only CLabelWnds.
			// Unless we are in login, then its all CLabelWnd
			if (gGameState == GAMESTATE_PRECHARSELECT)
				DisplayCLabelWndProperties(static_cast<CLabelWnd*>(m_window));
			else
				DisplayCLabelProperties(static_cast<CLabel*>(m_window));
			break;

		case UI_Gauge:
			DisplayCGaugeWndProperties(static_cast<CGaugeWnd*>(m_window));
			break;

		case UI_STMLBox:
			DisplayCStmlWndProperties(static_cast<CStmlWnd*>(m_window));
			break;

		case UI_HotButton:
			// HotButton is cloned into a CButtonWnd as well, so the dynamic type information is wrong.
			// we need to tell the difference apart, so the best way I can find is to compare the vftable.
			if (m_window->GetVFTable() == CButtonWnd::sm_vftable)
				DisplayCButtonWndProperties(static_cast<CButtonWnd*>(m_window));
			else
				DisplayCHotButtonProperties(static_cast<CHotButton*>(m_window));
			break;

		case UI_InvSlot:
			DisplayInvSlotWndProperties(static_cast<CInvSlotWnd*>(m_window));
			break;

		case UI_Listbox:
		case UI_Unknown:
		default:
			if (m_window->IsType(WRT_SIDLSCREENWND))
			{
				DisplayCSidlScreenWndProperties(static_cast<CSidlScreenWnd*>(m_window));
				break;
			}

			// Dynamic types have no XML type. So we use dynamic type to figure out what they are. Do these
			// in the correct order so we don't lose data!
			if (m_window->IsType(WRT_BUTTON))
			{
				DisplayCButtonWndProperties(static_cast<CButtonWnd*>(m_window));
				break;
			}

			if (m_window->IsType(WRT_LABEL))
			{
				DisplayCLabelWndProperties(static_cast<CLabelWnd*>(m_window));
				break;
			}

			if (m_window->IsType(WRT_LISTWND))
			{
				DisplayCListWndProperties(static_cast<CListWnd*>(m_window));
				break;
			}

			if (m_window->IsType(WRT_HOTKEYWND))
			{
				DisplayCHotButtonProperties(static_cast<CHotButton*>(m_window));
				break;
			}

			if (m_window->IsType(WRT_TABWND))
			{
				DisplayCTabWndProperties(static_cast<CTabWnd*>(m_window));
				break;
			}

			if (m_window->IsType(WRT_PAGEWND))
			{
				DisplayCPageWndProperties(static_cast<CPageWnd*>(m_window));
				break;
			}

			if (m_window->IsType(WRT_STMLWND))
			{
				DisplayCStmlWndProperties(static_cast<CStmlWnd*>(m_window));
				break;
			}

			//WRT_EDITWND,
			//WRT_TREEWND,
			//WRT_HTMLWND,
			//WRT_EDITHOTKEYWND,
			//WRT_RANGESLIDERWND,
			//WRT_STMLWND,
			//WRT_MODALMESSAGEWND,
			//WRT_CHECKBOXWND,
			//WRT_SLIDERWND,
			//WRT_GAUGE,
			//WRT_COMBOBOX,
			//WRT_CHATWND,
			//WRT_HELPWND,

			if (m_window->IsType(WRT_WND))
			{
				DisplayCXWndProperties(m_window);
				break;
			}
			break;
		}

		m_table.End();
	}

	void DisplayCXMLDataProperties(CXWnd* pWnd, bool open = true)
	{
		CXMLData* pXMLData = pWnd->GetXMLData();
		if (!pXMLData) return;

		if (BeginColorSection("XML Properties", open))
		{
			// Type
			ColumnText("Type", "%s (%d)", pXMLData->TypeName.c_str(), pXMLData->Type);

			if (!pXMLData->ScreenID.empty())
			{
				// ScreenID
				ColumnText("Screen ID", "%s", pXMLData->ScreenID.c_str());
			}

			if (!pXMLData->Name.empty() && pXMLData->Name != pXMLData->ScreenID)
			{
				// Name
				ColumnText("Name", "%s", pXMLData->Name.c_str());
			}

			if (pSidlMgr)
			{
				if (CScreenPieceTemplate* pTemplate = pSidlMgr->FindScreenPieceTemplate(pWnd->GetXMLIndex()))
				{
					DisplayDynamicTemplateExpand("Template", pTemplate);
				}
			}
		}
	}

#if HAS_GAMEFACE_UI
	void DisplayCXMLDataProperties(eqlib::eqmain::CXWnd* pWnd, bool open = true)
	{
		CXMLData* pXMLData = pWnd->GetXMLData();
		if (!pXMLData) return;

		if (BeginColorSection("XML Properties", open))
		{
			// Type
			ColumnText("Type", "%s (%d)", pXMLData->TypeName.c_str(), pXMLData->Type);

			if (!pXMLData->ScreenID.empty())
			{
				// ScreenID
				ColumnText("Screen ID", "%s", pXMLData->ScreenID.c_str());
			}

			if (!pXMLData->Name.empty() && pXMLData->Name != pXMLData->ScreenID)
			{
				// Name
				ColumnText("Name", "%s", pXMLData->Name.c_str());
			}

			if (pSidlMgr)
			{
				if (CScreenPieceTemplate* pTemplate = pSidlMgr->FindScreenPieceTemplate(pWnd->GetXMLIndex()))
				{
					DisplayDynamicTemplateExpand("Template", pTemplate);
				}
			}
		}
	}
#endif // HAS_GAMEFACE_UI

	void DisplayCXWndProperties(CXWnd* pWnd, bool open = true)
	{
		DisplayCXMLDataProperties(pWnd, open);

		// Add CXWnd specific details here
		if (BeginColorSection("CXWnd Properties", open))
		{
#if HAS_GAMEFACE_UI
			// Don't render if we're still at login
			if (g_pLoginClient == nullptr)
				ColumnText("Type Name", "%s", pWnd->GetWndClassName());
#endif
			DisplayDrawTemplate("Template", pWnd->DrawTemplate);

			std::vector<int> runtimeTypeInts;
			for (int i = 0; i < pWnd->RuntimeTypes.GetLength(); ++i)
				runtimeTypeInts.push_back(pWnd->RuntimeTypes[i]);
			std::string runtimeTypes = fmt::format("[{}]", fmt::join(runtimeTypeInts, ", "));

			if (ColumnTreeNodeType2(&pWnd->RuntimeTypes, "Runtime Types", "ArrayClass2<int>", "%s", runtimeTypes.c_str()))
			{
				for (int i = 0; i < pWnd->RuntimeTypes.GetLength(); ++i)
				{
					char szLabel[10] = { 0 };
					fmt::format_to(szLabel, "#{}", i + 1);
					ColumnText(szLabel, "%s (%d)",
						EWndRuntimeTypeToString(static_cast<EWndRuntimeType>(pWnd->RuntimeTypes[i])),
						pWnd->RuntimeTypes[i]);
				}

				ImGui::TreePop();
			}

			CXRect positionRect = pWnd->Location;
			if (ColumnCXRect("Position", &positionRect))
			{
				if (positionRect != pWnd->Location)
					pWnd->Move(positionRect);
			}

			ColumnCXRect("Client rect", pWnd->ClientRect);
			ColumnCXStr("Text", &pWnd->WindowText);
			ColumnCXStr("Tooltip", &pWnd->Tooltip);
			ColumnWindow("Parent", pWnd->ParentWindow);

			// Style
			if (ColumnTreeNode("Style", "0x%08x", pWnd->WindowStyle))
			{
				ColumnCheckBoxFlags("Vertical Scroll", &pWnd->WindowStyle, CWS_VSCROLL);
				ColumnCheckBoxFlags("Horizontal Scroll", &pWnd->WindowStyle, CWS_HSCROLL);
				ColumnCheckBoxFlags("Title Bar", &pWnd->WindowStyle, CWS_TITLE);
				ColumnCheckBoxFlags("Close Box", &pWnd->WindowStyle, CWS_CLOSE);
				ColumnCheckBoxFlags("Tile Box", &pWnd->WindowStyle, CWS_TILEBOX);
				ColumnCheckBoxFlags("Minimize Box", &pWnd->WindowStyle, CWS_MINIMIZE);
				ColumnCheckBoxFlags("Border", &pWnd->WindowStyle, CWS_BORDER);
				ColumnCheckBoxFlags("Relative Rect", &pWnd->WindowStyle, CWS_RELATIVERECT);
				ColumnCheckBoxFlags("Vertical Auto Stretch", &pWnd->WindowStyle, CWS_AUTOSTRETCHV);
				ColumnCheckBoxFlags("Horizontal Auto Stretch", &pWnd->WindowStyle, CWS_AUTOSTRETCH);
				ColumnCheckBoxFlags("Resizable", &pWnd->WindowStyle, CWS_RESIZEALL);
				ColumnCheckBoxFlags("Transparent", &pWnd->WindowStyle, CWS_TRANSPARENT);
				ColumnCheckBoxFlags("Use My Alpha", &pWnd->WindowStyle, CWS_USEMYALPHA);
				ColumnCheckBoxFlags("Docking Enabled", &pWnd->WindowStyle, CWS_DOCKING);
				ColumnCheckBoxFlags("Immediate Tooltip", &pWnd->WindowStyle, CWS_TOOLTIP_NODELAY);
				ColumnCheckBoxFlags("Frame", &pWnd->WindowStyle, CWS_FRAMEWND);
				ColumnCheckBoxFlags("No Hit Test", &pWnd->WindowStyle, CWS_NOHITTEST);
				ColumnCheckBoxFlags("QMark Box", &pWnd->WindowStyle, CWS_QMARK);
				ColumnCheckBoxFlags("Disable Move", &pWnd->WindowStyle, CWS_NOMOVABLE);
				ColumnCheckBoxFlags("Maximize Box", &pWnd->WindowStyle, CWS_MAXIMIZE);
				ColumnCheckBoxFlags("Vertical Auto Scroll", &pWnd->WindowStyle, CWS_AUTOVSCROLL);
				ColumnCheckBoxFlags("Horizontal Auto Scroll", &pWnd->WindowStyle, CWS_AUTOHSCROLL);
				ColumnCheckBoxFlags("Client Movable", &pWnd->WindowStyle, CWS_CLIENTMOVABLE);
				ColumnCheckBoxFlags("Transparent Control", &pWnd->WindowStyle, CWS_TRANSPARENTCONTROL);

				ImGui::TreePop();
			}

			bool show = pWnd->dShow;
			if (ColumnCheckBox("Visible", &show))
			{
				if (show)
					pWnd->Activate();
				else
					pWnd->Deactivate();
			}
			ColumnCheckBox("Enabled", &pWnd->Enabled);

			CTextureFont* pFont = pWnd->pFont;
			if (ColumnFont("Font", &pFont))
			{
				pWnd->SetFont(pFont);
			}

			if (ColumnTreeNode("Details", ""))
			{
				DisplayDynamicTemplateExpand("TitlePiece 1", pWnd->TitlePiece);
				DisplayDynamicTemplateExpand("TitlePiece 2", pWnd->TitlePiece2);
				DisplayTextObject("Text object", pWnd->pTextObject);
				DisplayTextObject("Tooltip text object", pWnd->pTipTextObject);
				ColumnText("Z layer", "%d", pWnd->ZLayer);

				DisplayTextureAnimation("Icon", static_cast<CTextureAnimation*>(pWnd->IconTextureAnim));
				ColumnCXRect("Icon rect", pWnd->IconRect);

				ColumnCheckBox("Minimized", &pWnd->Minimized);
				ColumnCheckBox("Maximized", &pWnd->bMaximized);
				ColumnCheckBox("Maximizable", &pWnd->bMaximizable);
				ColumnCheckBox("Tiled", &pWnd->bTiled);
				ColumnCheckBox("Action", &pWnd->bAction);
				ColumnCheckBox("Bring to top when clicked", &pWnd->bBringToTopWhenClicked);
				ColumnCheckBox("Mouse over", &pWnd->MouseOver);

				// Background
				ColumnText("Background type", XWndBackgroundTypeToString(static_cast<XWndBackgroundType>(pWnd->BGType)));
				ColumnText("Background draw type", XWndBackgroundDrawTypeToString(static_cast<XWndBackgroundDrawType>(pWnd->BackgroundDrawType)));
				ColumnColor("Normal color", &pWnd->CRNormal);
				ColumnColor("Background color", &pWnd->BGColor);
				ColumnColor<CXWnd>("Disabled background color", pWnd, &CXWnd::GetDisabledBackground, &CXWnd::SetDisabledBackground);

				ColumnCXStr("XML Tooltip", pWnd->XMLToolTip);

				// size
				ColumnCXSize("Min size", pWnd->MinClientSize);
				ColumnCXSize("Max size", pWnd->MaxClientSize);

				ColumnText("Horizontal scroll", "{ pos=%d, max=%d }", pWnd->HScrollPos, pWnd->HScrollMax);
				ColumnText("Vertical scroll", "{ pos=%d, max=%d }", pWnd->VScrollPos, pWnd->VScrollMax);

				ColumnCheckBox("Use in horizontal layout", &pWnd->bUseInLayoutHorizontal);
				ColumnCheckBox("Use in vertical layout", &pWnd->bUseInLayoutVertical);
				ColumnText("Anchors", "{ top=%d, right=%d, bottom=%d, left=%d }", pWnd->bTopAnchoredToTop, pWnd->bRightAnchoredToLeft, pWnd->bBottomAnchoredToTop, pWnd->bLeftAnchoredToLeft);
				ColumnText("Offsets", "{ top=%d, right=%d, bottom=%d, left=%d", pWnd->TopOffset, pWnd->RightOffset, pWnd->BottomOffset, pWnd->LeftOffset);

				// Alpha
				ColumnCheckBox("Fade enabled", &pWnd->Fades);
				ColumnText("Current fade alpha", "%d", pWnd->FadeAlpha);
				ColumnText("Current max alpha", "%d", pWnd->Alpha);

				// Mouse over / fading stuff
				ColumnCheckBox("Faded", &pWnd->Faded);
				ColumnText("Last time mouse over", "%d", pWnd->LastTimeMouseOver);
				ColumnText("Fade delay", "%d", pWnd->FadeDelay);
				ColumnText("Fade duration", "%d", pWnd->FadeDuration);
				ColumnText("Fade to alpha", "%d", pWnd->FadeToAlpha);

				// Transition effects
				if (ColumnTreeNode("Transition Properties", ""))
				{
					ColumnText("Start alpha", "%d", pWnd->StartAlpha);
					ColumnText("Target alpha", "%d", pWnd->TargetAlpha);
					ColumnText("Transition start tick", "%d", pWnd->TransitionStartTick);
					ColumnText("Transition duration", "%d", pWnd->TransitionDuration);
					ColumnCheckBox("Is transitioning", &pWnd->bIsTransitioning);
					ColumnText("Transition", "%d", pWnd->Transition);
					ColumnCXRect("Transition rect", pWnd->TransitionRect);

					ImGui::TreePop();
				}

				if (ColumnTreeNode("Blink Properties", ""))
				{
					ColumnText("Blink fade frequency", "%d", pWnd->BlinkFadeFreq);
					ColumnText("Last blink fade refresh time", "%d", pWnd->LastBlinkFadeRefreshTime);
					ColumnText("Blink fade duration", "%d", pWnd->BlinkFadeDuration);
					ColumnText("Blink fade start time", "%d", pWnd->BlinkFadeStartTime);
					ColumnText("Blink state", "%d", pWnd->BlinkState);
					ColumnText("Blink start timer", "%d", pWnd->BlinkStartTimer);
					ColumnText("Blink duration", "%d", pWnd->BlinkDuration);

					ImGui::TreePop();
				}

				ColumnText("Valid", pWnd->ValidCXWnd ? "true" : "false");

				ColumnCheckBox("Unlockable", &pWnd->Unlockable);
				ColumnCheckBox("Locked", &pWnd->Locked);

				ColumnCheckBox("Keep on screen", &pWnd->bKeepOnScreen);
				ColumnCheckBox("Clip to parent", &pWnd->bClipToParent);
				ColumnCheckBox("Active", &pWnd->bActive);

				ColumnCheckBox("Escapable", &pWnd->bEscapable);
				ColumnCheckBox("Escapable locked", &pWnd->bEscapableLocked);

				ColumnCheckBox("Show Border MenuItem Enabled", &pWnd->bEnableShowBorder);
				ColumnCheckBox("Show Border", &pWnd->bShowBorder);

				ColumnCheckBox("Click Through", &pWnd->bClickThrough);
				ColumnCheckBox("Click Through (to background)", &pWnd->bClickThroughToBackground);
				ColumnCheckBox("Click Through Menu Status", &pWnd->bClickThroughMenuItemStatus);
				ColumnCheckBox("Click Through Menu Enabled", &pWnd->bShowClickThroughMenuItem);

				ColumnCheckBox("Capture Events from Title", &pWnd->bCaptureTitle);

				//ColumnText("Resizable mask", "0x%08x", pWnd->bResizableMask);
				//ColumnCheckBox("Border", &pWnd->bBorder);
				//ColumnCheckBox("Border 2", &pWnd->bBorder2);
				//ColumnCheckBox("Top anchored to top", &pWnd->bTopAnchoredToTop);
				//ColumnCheckBox("Right anchored to left", &pWnd->bRightAnchoredToLeft);
				//ColumnCheckBox("Bottom anchored to top", &pWnd->bBottomAnchoredToTop);
				//ColumnCheckBox("Left anchored to left", &pWnd->bLeftAnchoredToLeft);
				//ColumnText("Top offset", "%d", pWnd->TopOffset);
				//ColumnText("Right offset", "%d", pWnd->RightOffset);
				//ColumnText("Left offset", "%d", pWnd->LeftOffset);
				//ColumnText("Bottom offset", "%d", pWnd->BottomOffset);
				//ColumnText("Parent/Context Menu array index", "%d", pWnd->ParentAndContextMenuArrayIndex);
				//ColumnCheckBox("Click through menu item", &pWnd->bClickThroughMenuItemStatus);
				//ColumnText("Fully clipped", pWnd->bFullyScreenClipped ? "true" : "false");
				//ColumnCheckBox("Needs saving", &pWnd->bNeedsSaving);
				//ColumnCheckBox("Is parent/context menu window", &pWnd->bIsParentOrContextMenuWindow);
				//ColumnText("Data", "%lld", pWnd->Data);
				//ColumnCXStr("DataStr", pWnd->DataStr);
				//ColumnCXRect("Clip rect screen", pWnd->ClipRectScreen);
				//ColumnText("XML Index", "%d", pWnd->XMLIndex);
				//ColumnCheckBox("Capture title", &pWnd->bCaptureTitle);
				// TextObject
				// bClientClipRectChanged
				// ParentWindow
				// pTipTextObject
				// bScreenClipRectChanged
				// FocusProxy
				// pFont
				// OldLocation
				// LayoutStrategy
				// TitlePiece
				//ColumnCXRect("Clip client rect", pWnd->ClipRectClient);

				ImGui::TreePop();
			}
		}
	}

#if HAS_GAMEFACE_UI
	void DisplayCXWndProperties(eqlib::eqmain::CXWnd* pWnd, bool open = true)
	{
		DisplayCXMLDataProperties(pWnd, open);

		// Add CXWnd specific details here
		if (BeginColorSection("CXWnd Properties", open))
		{
			DisplayDrawTemplate("Template", pWnd->DrawTemplate);

			std::vector<int> runtimeTypeInts;
			for (int i = 0; i < pWnd->RuntimeTypes.GetLength(); ++i)
				runtimeTypeInts.push_back(pWnd->RuntimeTypes[i]);
			std::string runtimeTypes = fmt::format("[{}]", fmt::join(runtimeTypeInts, ", "));

			if (ColumnTreeNodeType2(&pWnd->RuntimeTypes, "Runtime Types", "ArrayClass2<int>", "%s", runtimeTypes.c_str()))
			{
				for (int i = 0; i < pWnd->RuntimeTypes.GetLength(); ++i)
				{
					char szLabel[10] = { 0 };
					fmt::format_to(szLabel, "#{}", i + 1);
					ColumnText(szLabel, "%s (%d)",
						EWndRuntimeTypeToString(static_cast<EWndRuntimeType>(pWnd->RuntimeTypes[i])),
						pWnd->RuntimeTypes[i]);
				}

				ImGui::TreePop();
			}

			CXRect positionRect = pWnd->Location;
			if (ColumnCXRect("Position", &positionRect))
			{
				if (positionRect != pWnd->Location)
					pWnd->Move(positionRect);
			}

			ColumnCXRect("Client rect", pWnd->ClientRect);
			ColumnCXStr("Text", &pWnd->WindowText);
			ColumnCXStr("Tooltip", &pWnd->Tooltip);
			ColumnWindow("Parent", pWnd->ParentWindow);

			// Style
			if (ColumnTreeNode("Style", "0x%08x", pWnd->WindowStyle))
			{
				ColumnCheckBoxFlags("Vertical Scroll", &pWnd->WindowStyle, CWS_VSCROLL);
				ColumnCheckBoxFlags("Horizontal Scroll", &pWnd->WindowStyle, CWS_HSCROLL);
				ColumnCheckBoxFlags("Title Bar", &pWnd->WindowStyle, CWS_TITLE);
				ColumnCheckBoxFlags("Close Box", &pWnd->WindowStyle, CWS_CLOSE);
				ColumnCheckBoxFlags("Tile Box", &pWnd->WindowStyle, CWS_TILEBOX);
				ColumnCheckBoxFlags("Minimize Box", &pWnd->WindowStyle, CWS_MINIMIZE);
				ColumnCheckBoxFlags("Border", &pWnd->WindowStyle, CWS_BORDER);
				ColumnCheckBoxFlags("Relative Rect", &pWnd->WindowStyle, CWS_RELATIVERECT);
				ColumnCheckBoxFlags("Vertical Auto Stretch", &pWnd->WindowStyle, CWS_AUTOSTRETCHV);
				ColumnCheckBoxFlags("Horizontal Auto Stretch", &pWnd->WindowStyle, CWS_AUTOSTRETCH);
				ColumnCheckBoxFlags("Resizable", &pWnd->WindowStyle, CWS_RESIZEALL);
				ColumnCheckBoxFlags("Transparent", &pWnd->WindowStyle, CWS_TRANSPARENT);
				ColumnCheckBoxFlags("Use My Alpha", &pWnd->WindowStyle, CWS_USEMYALPHA);
				ColumnCheckBoxFlags("Docking Enabled", &pWnd->WindowStyle, CWS_DOCKING);
				ColumnCheckBoxFlags("Immediate Tooltip", &pWnd->WindowStyle, CWS_TOOLTIP_NODELAY);
				ColumnCheckBoxFlags("Frame", &pWnd->WindowStyle, CWS_FRAMEWND);
				ColumnCheckBoxFlags("No Hit Test", &pWnd->WindowStyle, CWS_NOHITTEST);
				ColumnCheckBoxFlags("QMark Box", &pWnd->WindowStyle, CWS_QMARK);
				ColumnCheckBoxFlags("Disable Move", &pWnd->WindowStyle, CWS_NOMOVABLE);
				ColumnCheckBoxFlags("Maximize Box", &pWnd->WindowStyle, CWS_MAXIMIZE);
				ColumnCheckBoxFlags("Vertical Auto Scroll", &pWnd->WindowStyle, CWS_AUTOVSCROLL);
				ColumnCheckBoxFlags("Horizontal Auto Scroll", &pWnd->WindowStyle, CWS_AUTOHSCROLL);
				ColumnCheckBoxFlags("Client Movable", &pWnd->WindowStyle, CWS_CLIENTMOVABLE);
				ColumnCheckBoxFlags("Transparent Control", &pWnd->WindowStyle, CWS_TRANSPARENTCONTROL);

				ImGui::TreePop();
			}

			bool show = pWnd->dShow;
			if (ColumnCheckBox("Visible", &show))
			{
				if (show)
					pWnd->Activate();
				else
					pWnd->Deactivate();
			}
			ColumnCheckBox("Enabled", &pWnd->Enabled);

			CTextureFont* pFont = pWnd->pFont;
			ColumnFont("Font", &pFont);

			if (ColumnTreeNode("Details", ""))
			{
				DisplayDynamicTemplateExpand("TitlePiece 1", pWnd->TitlePiece);
				DisplayDynamicTemplateExpand("TitlePiece 2", pWnd->TitlePiece2);
				DisplayTextObject("Text object", pWnd->pTextObject);
				DisplayTextObject("Tooltip text object", pWnd->pTipTextObject);
				ColumnText("Z layer", "%d", pWnd->ZLayer);

				DisplayTextureAnimation("Icon", pWnd->IconTextureAnim);
				ColumnCXRect("Icon rect", pWnd->IconRect);

				ColumnCheckBox("Minimized", &pWnd->Minimized);
				ColumnCheckBox("Maximized", &pWnd->bMaximized);
				ColumnCheckBox("Maximizable", &pWnd->bMaximizable);
				ColumnCheckBox("Tiled", &pWnd->bTiled);
				ColumnCheckBox("Action", &pWnd->bAction);
				ColumnCheckBox("Bring to top when clicked", &pWnd->bBringToTopWhenClicked);
				ColumnCheckBox("Mouse over", &pWnd->MouseOver);

				// Background
				ColumnText("Background type", XWndBackgroundTypeToString(static_cast<XWndBackgroundType>(pWnd->BGType)));
				ColumnText("Background draw type", XWndBackgroundDrawTypeToString(static_cast<XWndBackgroundDrawType>(pWnd->BackgroundDrawType)));
				ColumnColor("Normal color", &pWnd->CRNormal);
				ColumnColor("Background color", &pWnd->BGColor);
				ColumnColor<eqlib::eqmain::CXWnd>("Disabled background color", pWnd,
					&eqlib::eqmain::CXWnd::GetDisabledBackground, &eqlib::eqmain::CXWnd::SetDisabledBackground);

				ColumnCXStr("XML Tooltip", pWnd->XMLToolTip);

				// size
				ColumnCXSize("Min size", pWnd->MinClientSize);
				ColumnCXSize("Max size", pWnd->MaxClientSize);

				ColumnText("Horizontal scroll", "{ pos=%d, max=%d }", pWnd->HScrollPos, pWnd->HScrollMax);
				ColumnText("Vertical scroll", "{ pos=%d, max=%d }", pWnd->VScrollPos, pWnd->VScrollMax);

				ColumnCheckBox("Use in horizontal layout", &pWnd->bUseInLayoutHorizontal);
				ColumnCheckBox("Use in vertical layout", &pWnd->bUseInLayoutVertical);
				ColumnText("Anchors", "{ top=%d, right=%d, bottom=%d, left=%d }", pWnd->bTopAnchoredToTop, pWnd->bRightAnchoredToLeft, pWnd->bBottomAnchoredToTop, pWnd->bLeftAnchoredToLeft);
				ColumnText("Offsets", "{ top=%d, right=%d, bottom=%d, left=%d", pWnd->TopOffset, pWnd->RightOffset, pWnd->BottomOffset, pWnd->LeftOffset);

				// Alpha
				ColumnCheckBox("Fade enabled", &pWnd->Fades);
				ColumnText("Current fade alpha", "%d", pWnd->FadeAlpha);
				ColumnText("Current max alpha", "%d", pWnd->Alpha);

				// Mouse over / fading stuff
				ColumnCheckBox("Faded", &pWnd->Faded);
				ColumnText("Last time mouse over", "%d", pWnd->LastTimeMouseOver);
				ColumnText("Fade delay", "%d", pWnd->FadeDelay);
				ColumnText("Fade duration", "%d", pWnd->FadeDuration);
				ColumnText("Fade to alpha", "%d", pWnd->FadeToAlpha);

				ColumnText("Valid", pWnd->ValidCXWnd ? "true" : "false");

				ColumnCheckBox("Unlockable", &pWnd->Unlockable);
				ColumnCheckBox("Locked", &pWnd->Locked);

				ColumnCheckBox("Keep on screen", &pWnd->bKeepOnScreen);
				ColumnCheckBox("Clip to parent", &pWnd->bClipToParent);
				ColumnCheckBox("Active", &pWnd->bActive);

				ImGui::TreePop();
			}
		}
	}

	void DisplayUIComponent(const char* label, UIComponent* component)
	{
		if (ColumnTreeNodeType(label, component->GetTypeName().c_str(), ""))
		{
			ColumnText("Name", "%s", component->name.c_str());
			ColumnText("Full Name", "%s", component->fullName.c_str());
			ColumnText("Model Prefix", "%s", component->modelPrefix.c_str());
			ColumnWindow("Window", component->parent);
			ColumnWindow("Parent Window", component->parent);
			ColumnText("str_78", "%s", component->str_78.c_str());
			ColumnText("u64_98", "%p", (uintptr_t)component->u64_98);

			ImGui::TreePop();
		}
	}

	void DisplayCGFScreenWndProperties(CGFScreenWnd* pWnd, bool open = true)
	{
		// Add CGFScreenWnd specific details here
		if (BeginColorSection("CGFScreenWnd Properties", open))
		{
			DisplayUIComponent("Window Component", &pWnd->WindowComponent);
			ColumnText("u8_a0", "%d", (int)pWnd->WindowComponent.u8_a0);

			if (ColumnTreeNode("Children Components", "%d", pWnd->ChildComponents.size()))
			{
				for (auto& [name, component] : pWnd->ChildComponents)
				{
					DisplayUIComponent(name.c_str(), component);
				}

				ImGui::TreePop();
			}
		}
	}
#endif

	void DisplayCSidlScreenWndProperties(CSidlScreenWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(static_cast<CXWnd*>(pWnd), open);

		// Add CSidlScreenWnd specific details here
		if (BeginColorSection("CSidlScreenWnd Properties", open))
		{
			DisplayTemplate("SIDL Template", "CScreenTemplate*", pWnd->SidlPiece);

			if (ColumnTreeNode("INI Settings", ""))
			{
				ColumnText("Flags", pWnd->IniFlags == eIniFlag_All ? "(all)" : pWnd->IniFlags ? "0x%08x" : "(none)", pWnd->IniFlags);
				ColumnCXStr("INI Settings Group", pWnd->IniStorageName);
				ColumnText("INI Settings Version", "%d", pWnd->IniVersion);
				ColumnCheckBoxFlags("Position", (unsigned int*)&pWnd->IniFlags, eIniFlag_Position);
				ColumnCheckBoxFlags("Size", (unsigned int*)&pWnd->IniFlags, eIniFlag_Size);
				ColumnCheckBoxFlags("Font", (unsigned int*)&pWnd->IniFlags, eIniFlag_Font);
				ColumnCheckBoxFlags("Alpha", (unsigned int*)&pWnd->IniFlags, eIniFlag_Alpha);
				ColumnCheckBoxFlags("Color", (unsigned int*)&pWnd->IniFlags, eIniFlag_Color);
				ColumnCheckBoxFlags("Visibility", (unsigned int*)&pWnd->IniFlags, eIniFlag_Visibility);
				ColumnCheckBoxFlags("First Time Visibility", (unsigned int*)&pWnd->IniFlags, eIniFlag_FirstTimeVisibility);
				ColumnCheckBoxFlags("Min/Max State", (unsigned int*)&pWnd->IniFlags, eIniFlag_MinMaxState);

				ImGui::TreePop();
			}

			// TODO: RadioGroup
			//ColumnText("Last resolution pos", "{ x=%d, y=%d }", pWnd->LastResX, pWnd->LastResY);
			//ColumnText("Last resolution fullscreen", pWnd->bLastResFullscreen ? "true" : "false");
			//ColumnText("Context menu id", "%d", pWnd->ContextMenuID);
			//ColumnText("Context menu tip id", "%d", pWnd->ContextMenuTipID);
		}

#if HAS_GAMEFACE_UI
		if (GetGameState() != GAMESTATE_PRECHARSELECT)
		{
			if (string_equals(m_window->GetWndClassName(), "GFScreenWnd"))
			{
				DisplayCGFScreenWndProperties(static_cast<CGFScreenWnd*>(m_window));
			}
		}
#endif

		DisplayCustomWindowPropertyViewer(pWnd, this);
	}

	void DisplayCButtonWndProperties(CButtonWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(pWnd, open);

		if (BeginColorSection("CButtonWnd Properties", open))
		{
			DisplayDrawTemplate("Template", pWnd->DrawTemplate);

			ColumnText("Picture button", pWnd->bPicture ? "true" : "false");
			// CRadioGroup
			ColumnCheckBox("Checked", &pWnd->bChecked);
			//ColumnText("Is check box", pWnd->bIsCheckbox ? "true" : "false");

			// bMouseOverLastFrame
			ColumnCXPoint("Decal offset", pWnd->DecalOffset);
			ColumnCXSize("Decal size", pWnd->DecalSize);
			ColumnColor("Decal tint", pWnd->DecalTint);

			ColumnCXRect("Text offsets", pWnd->TextOffsets);

			// TODO: flags for text mode
			ColumnText("Text mode bits", "%d", pWnd->TextModeBits);

			ColumnColor("Hover tint", pWnd->Mouseover);
			ColumnColor("Pressed tint", pWnd->Pressed);
			ColumnColor("Disabled tint", pWnd->Disabled);

			ColumnText("Cooldown time", "%d", pWnd->CoolDownBeginTime);
			ColumnText("Cooldown duration", "%d", pWnd->CoolDownDuration);


			if (ColumnTreeNodeType("Radio Group", "CRadioGroup*", "%s", pWnd->pGroup ? pWnd->pGroup->Name.c_str() : "")
				&& pWnd->pGroup)
			{
				ColumnCXStr("Name", pWnd->pGroup->Name);
				if (ColumnTreeNodeType("Buttons", "CButtonWnd*[]", "%d", pWnd->pGroup->Buttons.GetLength()))
				{
					for (int i = 0; i < pWnd->pGroup->Buttons.GetLength(); ++i)
					{
						CButtonWnd* pButton = pWnd->pGroup->GetButton(i);

						char szTemp[32];
						sprintf_s(szTemp, "Button %d", i + 1);

						ColumnWindow(szTemp, pButton);
					}

					ImGui::TreePop();
				}

				ColumnText("Current Selection", "%d", pWnd->pGroup->CurSel);
				ColumnText("Selection limit", "%d", pWnd->pGroup->nSelectionLimit);
				ColumnCheckBox("Allow Multi-select", &pWnd->pGroup->bAllowMultiSelect);
				ColumnCheckBox("Allow None", &pWnd->pGroup->bAllowNullable);

				ImGui::TreePop();
			}
			
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COV)
			ColumnCXStr("Indicator", pWnd->Indicator);
			ColumnText("Indicator value", "%d", pWnd->IndicatorVal);
			DisplayTextObject("Indicator", pWnd->pIndicatorTextObject);

			// pIndicatorTextObject
			// bAllowButtonClickThrough
			// bCoolDownDoDelayedStart
			// bIsDrawLasso
			//ColumnText("Button style", "0x%08x", pWnd->ButtonStyle);
#endif

			// CLabel
		}
	}

	void DisplayCSpellGemWndProperties(CSpellGemWnd* pWnd, bool open = true)
	{
		DisplayCButtonWndProperties(static_cast<CButtonWnd*>(m_window), false);

		if (BeginColorSection("CSpellGemWnd Properties", open))
		{
			DisplayDrawTemplate("Template", pWnd->DrawTemplate);

			DisplayTextureAnimation("Spell icon texture", pWnd->SpellIconTexture);
			DisplayTextureAnimation("Custom icon texture", pWnd->CustomIconTexture);
			ColumnCheckBox("Checked", &pWnd->bChecked);

			size_t numTints = lengthof(pWnd->SpellGemTintArray);
			if (ColumnTreeNodeType("SpellGemTintArray", "MQColor[]", "%d", numTints))
			{
				char label[16] = { 0 };

				for (size_t i = 0; i < numTints; ++i)
				{
					sprintf_s(label, "%zd", i);
					ColumnColor(label, MQColor(pWnd->SpellGemTintArray[i]));
				}

				ImGui::TreePop();
			}

			pWnd->bChecked = static_cast<CButtonWnd*>(pWnd)->bChecked;

			// Draw the spell gem
			TreeAdvanceToLabelPos(); ImGui::TextUnformatted("Spell Gem"); ImGui::TableNextColumn();
			mq::imgui::SpellGem("##InspectorSpellGem", pWnd, ImGuiSpellGemFlags_AllowAll);

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

		}
	}

	void DisplayCLabelWndProperties(CLabelWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(pWnd, true);

		if (BeginColorSection("CLabelWnd Properties", open))
		{
			bool changed = false;
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COV)
			ColumnCXStr("Prepend Text", &pWnd->PrependText);
			ColumnCXStr("Text###LabelText", &pWnd->Text);
			ColumnCXStr("Append Text", &pWnd->AppendText);
			if (ColumnCheckBox("Text Dirty", &pWnd->bTextDirty) && pWnd->bTextDirty)
				pWnd->UpdateText();
#else
			ColumnCXStr("Text###LabelText", pWnd->Text);
#endif
			ColumnCheckBox("No wrap", &pWnd->bNoWrap);
			ColumnCheckBox("Right align", &pWnd->bAlignRight);
			ColumnCheckBox("Center align", &pWnd->bAlignCenter);
			ColumnText("Offset", "%d", pWnd->xOffset);
			ColumnCheckBox("Resize height to text", &pWnd->bResizeHeightToText);
		}
	}

	void DisplayCLabelProperties(CLabel* pWnd, bool open = true)
	{
		DisplayCLabelWndProperties(pWnd, true);

		if (BeginColorSection("CLabel Properties", open))
		{
			ColumnNumber("EQ Type", &pWnd->EQType);
		}
	}

	void DisplayCGaugeWndProperties(CGaugeWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(pWnd, true);

		if (BeginColorSection("CGaugeWnd Properties", open))
		{
			ColumnText("EQ Type", "%d", pWnd->EQType);
			ColumnColor("Fill tint", pWnd->FillTint);
			ColumnColor("Lines tint", pWnd->LinesFillTint);
			ColumnCheckBox("Draw lines fill", &pWnd->bDrawLinesFill);
			ColumnCXPoint("Text offset", CXPoint(pWnd->TextOffsetX, pWnd->TextOffsetY));
			ColumnCXSize("Gauge offset", CXSize(pWnd->GaugeOffsetX, pWnd->GaugeOffsetY));
			ColumnText("Last frame value", "%.2f", pWnd->LastFrameVal);
			ColumnCXStr("Last frame label", pWnd->LastFrameName);
			ColumnText("Last frame time", "%d", pWnd->LastFrameTime);
			ColumnText("Last frame target", "%d", pWnd->LastFrameTarget);
			ColumnCXStr("Gauge tooltip", pWnd->GaugeTooltip);
			ColumnText("Tooltip value", "%d", pWnd->TooltipVal);

			// DrawTemplate
			DisplayTextObject("Text object", pWnd->pTextObject);

			ColumnCXStr("Next draw string", pWnd->NextDrawStr);
			ColumnCheckBox("Smooth", &pWnd->bSmooth);
			ColumnText("Target value", "%d", pWnd->TargetVal);
			ColumnCheckBox("Use target value", &pWnd->bUseTargetVal);
		}
	}

	void DisplayCHotButtonProperties(CHotButton* pWnd, bool open = true)
	{
		DisplayCXWndProperties(pWnd, true);

		if (BeginColorSection("CHotButton Properties", open))
		{
			ColumnText("Bar index", "%d", pWnd->BarIndex);
			ColumnText("Button index", "%d", pWnd->ButtonIndex);
			ColumnText("Timer", "%d", std::max<int>(0, pWnd->Timer - pDisplay->TimeStamp));
			DisplayTextureAnimation("Decal icon", pWnd->DecalIcon);
			ColumnText("Button type", "%s (%d)", HotButtonTypeToString(pWnd->LastButtonType), pWnd->LastButtonType);
			ColumnText("Button slot", "%d", pWnd->LastButtonSlot);
			ColumnText("Button page", "%d", (int)pWnd->LastButtonPage);
			ColumnText("Item Guid", "%s", pWnd->LastItemGuid.guid);
			ColumnText("Item ID", "%d", pWnd->LastItemId);
			ColumnText("Icon type", "%d", pWnd->LastIconType);
			ColumnText("Icon slot", "%d", pWnd->LastIconSlot);
			ColumnCXStr("Label", pWnd->LastLabel);
			ColumnCXStr("Default label", pWnd->DefaultLabel);
			DisplayTextObject("Keymap text", pWnd->pKeyMapText);
			ColumnWindow("Button", pWnd->pButtonWnd);
			ColumnWindow("InvSlot", pWnd->pInvSlotWnd);
			ColumnWindow("SpellGem", pWnd->pSpellGemWnd);
			ColumnCXSize("Base size", pWnd->BaseSize);
			ColumnText("Percent size", "%d", pWnd->ButtonPercentSize);
			ColumnCXSize("Base button size", pWnd->BaseButtonSize);
			ColumnCXSize("Base decal size", pWnd->BaseDecalSize);
			ColumnCXSize("Base inv button size", pWnd->BaseInvButtonSize);
			ColumnCXSize("Base spell button size", pWnd->BaseSpellButtonSize);

			const HotButtonData& data = pEverQuestInfo->hotButtons[pWnd->BarIndex][pEverQuestInfo->hotBank[pWnd->BarIndex]][pWnd->ButtonIndex];

			if (ColumnTreeNodeType("HotButton Data", "HotButtonData", "%s", data.Label[0] ? data.Label : data.ItemName))
			{
				ColumnItem("Item", data.Item);
				ColumnText("ItemGuid", "%s", data.ItemGuid.guid);
				ColumnText("Label", "%s", data.Label);
				ColumnText("Item Name", data.ItemName);
				ColumnText("Item ID", "%d", data.ItemId);
				ColumnTextType("Icon Type", "eIconCacheType", "%s (%d)", IconCacheTypeToString(static_cast<eIconCacheType>(data.IconType)), data.IconType);
				ColumnText("Icon Slot", "%d", data.IconSlot);
				ColumnText("Icon ID", "%d", data.IconId);
				ColumnText("Slot", "%d", data.Slot);
				ColumnTextType("Type", "HotButtonTypes", "%s (%d)", HotButtonTypeToString(static_cast<HotButtonTypes>(data.Type)), (int)data.Type);
				ColumnCheckBox("Item Valid", data.ItemValid);

				ImGui::TreePop();
			}
		}
	}

	void DisplayCTabWndProperties(CTabWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(pWnd, true);

		if (BeginColorSection("CTabWnd Properties", open))
		{
			ColumnText("Current Tab Index", "%d", pWnd->CurTabIndex);
			ColumnText("Tab Height", "%d", pWnd->TabHeight);
			ColumnCXRect("Page Rect", pWnd->PageRect);
			ColumnCheckBox("Show Tabs", pWnd->bShowTabs);
			ColumnText("Tab Width", "%d", pWnd->TabWidth);
			DisplayTAFrameDraw("Tab Border", *pWnd->pTabBorder);
			DisplayTAFrameDraw("Page Border", *pWnd->pPageBorder);
			if (pWnd->TabStyle == 0)
				ColumnText("Tab Style", "Stretched");
			else
				ColumnText("Tab Style", "Fixed");

			if (ColumnTreeNodeType("Pages", "CPageWnd[]", "%d", pWnd->PageArray.GetLength()))
			{
				for (int i = 0; i < pWnd->PageArray.GetLength(); ++i)
				{
					CPageWnd* pPageWnd = pWnd->PageArray[i];

					char szTemp[32];
					sprintf_s(szTemp, "Page %d", i + 1);

					ColumnWindow(szTemp, pPageWnd);
				}

				ImGui::TreePop();
			}
		}
	}

	void DisplayCPageWndProperties(CPageWnd* pWnd, bool open = true)
	{
		DisplayCSidlScreenWndProperties(pWnd, true);

		if (BeginColorSection("CPageWndProperties", open))
		{
			ColumnCXStr("Tab Text", pWnd->TabText);
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_TBM)
			ColumnCXStr("Original Tab Text", pWnd->OrigTabText);
#endif
			ColumnColor("Tab Color", pWnd->CRTabText);
			ColumnColor("Tab Color (Active)", pWnd->CRTabTextActive);
			DisplayTextureAnimation("Tab Icon", pWnd->pTATabIcon, true);
			DisplayTextureAnimation("Tab Icon (Active)", pWnd->pTATabIconActive, true);
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_TBM)
			ColumnColor("Flash Highlight Color", pWnd->CRHighlightFlashColor);

			ColumnElapsedTimestamp("Last Flash Time", std::chrono::milliseconds(pWnd->LastFlashTime),
				std::chrono::system_clock::now().time_since_epoch());

			ColumnCheckBox("Flash On Message", pWnd->bHighlightOnNewMessages);
			ColumnCheckBox("Flashing", &pWnd->bFlashing);
#endif
		}
	}

	void DisplayCStmlWndProperties(CStmlWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(static_cast<CXWnd*>(pWnd), open);

		if (BeginColorSection("CStmlWnd Properties", open))
		{
			ColumnCXStr("STMLText", &pWnd->STMLText);
			// TextLines
			ColumnCXSize("Text Size", CXSize(pWnd->TextTotalWidth, pWnd->TextTotalHeight));
			// Unknown0x224
			// Links
			// Tables
			ColumnCheckBox("Reparse Requested", &pWnd->bReparseNow);
			ColumnCheckBox("Resized", pWnd->bResized);
			ColumnCheckBox("Center Aligned", pWnd->bAlignCenter);
			ColumnText("Line Spacing", "%d", pWnd->LineSpacingAdjust);

			ColumnText("Captured Link ID", "%d", pWnd->CapturedLinkID);
			ColumnText("Hovered Link ID", "%d", pWnd->MousedOverLinkID);
			ColumnColor("Background Color", &pWnd->BackGroundColor);
			ColumnColor("Text Color", &pWnd->TextColor);
			ColumnColor("Link Color", &pWnd->LinkColor);
			ColumnColor("Link Color (Visited)", &pWnd->VLinkColor);
			ColumnColor("Link Color (Active)", &pWnd->ALinkColor);
			ColumnColor("Link Color (Hover)", &pWnd->MLinkColor);
			// CurrentParseState
			// HistoryArray
			// HistoryIndex
			// pStmlReport
			ColumnText("Max Lines", "%d", pWnd->MaxLines);
			// PlayerContextMenuIndex
			// Unknowns
		}
	}

	void DisplayLayoutWndProperties(CLayoutWnd* pWnd, bool open = true)
	{
		DisplayCSidlScreenWndProperties(pWnd, true);

		if (BeginColorSection("CLayoutWnd Properties", open))
		{
			ColumnText("Spacing", "%d", pWnd->spacing);
			ColumnText("Padding Left", "%d", pWnd->paddingLeft);
			ColumnText("Padding Right", "%d", pWnd->paddingRight);
			ColumnText("Padding Top", "%d", pWnd->paddingTop);
			ColumnText("Padding Bottom", "%d", pWnd->paddingBottom);
			ColumnCheckBox("Expand Last", pWnd->expandLast);
		}
	}

	void DisplayHorizontalLayoutWndProperties(CHorizontalLayoutWnd* pWnd, bool open = true)
	{
		DisplayLayoutWndProperties(pWnd, true);

		if (BeginColorSection("CHorizontalLayoutWnd Properties", open))
		{
			// visibleChildren
			if (ColumnTreeNodeType("Visible Children", "ArrayClass<CXWnd*>", "%d", pWnd->visibleChildren.GetCount()))
			{
				for (int i = 0; i < pWnd->visibleChildren.GetCount(); ++i)
				{
					char szIndexLabel[32] = { 0 };
					sprintf_s(szIndexLabel, "%d", i + 1);
					ColumnWindow(szIndexLabel, pWnd->visibleChildren[i]);
				}

				ImGui::TreePop();
			}

			// dividerRects
			if (ColumnTreeNodeType("Divider Rects", "ArrayClass<CXRect>", "%d", pWnd->dividerRects.GetCount()))
			{

				for (int i = 0; i < pWnd->dividerRects.GetCount(); ++i)
				{
					char szIndexLabel[32] = { 0 };
					sprintf_s(szIndexLabel, "%d", i + 1);
					ColumnCXRect(szIndexLabel, pWnd->dividerRects[i]);
				}

				ImGui::TreePop();
			}

			ColumnText("Active Divider", "%d", pWnd->activeDivider);
			ColumnCheckBox("Divider Hovered", pWnd->dividerHover);
			ColumnCheckBox("Divider Moving", pWnd->dividerMoving);
			ColumnText("Divider X Pos", "%d", pWnd->oldPosCoord);
			ColumnCheckBox("Style: Dividers", pWnd->bStyle_Dividers);
		}
	}

	void DisplayVerticalLayoutWndProperties(CVerticalLayoutWnd* pWnd, bool open = true)
	{
		DisplayLayoutWndProperties(pWnd, true);

		if (BeginColorSection("CVerticalLayoutWnd Properties", open))
		{
			// visibleChildren
			if (ColumnTreeNodeType("Visible Children", "ArrayClass<CXWnd*>", "%d", pWnd->visibleChildren.GetCount()))
			{
				for (int i = 0; i < pWnd->visibleChildren.GetCount(); ++i)
				{
					char szIndexLabel[32] = { 0 };
					sprintf_s(szIndexLabel, "%d", i + 1);
					ColumnWindow(szIndexLabel, pWnd->visibleChildren[i]);
				}

				ImGui::TreePop();
			}

			// dividerRects
			if (ColumnTreeNodeType("Divider Rects", "ArrayClass<CXRect>", "%d", pWnd->dividerRects.GetCount()))
			{

				for (int i = 0; i < pWnd->dividerRects.GetCount(); ++i)
				{
					char szIndexLabel[32] = { 0 };
					sprintf_s(szIndexLabel, "%d", i + 1);
					ColumnCXRect(szIndexLabel, pWnd->dividerRects[i]);
				}

				ImGui::TreePop();
			}

			ColumnText("Active Divider", "%d", pWnd->activeDivider);
			ColumnCheckBox("Divider Hovered", pWnd->dividerHover);
			ColumnCheckBox("Divider Moving", pWnd->dividerMoving);
			ColumnText("Divider Y Pos", "%d", pWnd->oldPosCoord);
			ColumnCheckBox("Style: Dividers", pWnd->bStyle_Dividers);
		}
	}

	void DisplayTileLayoutWndProperties(CTileLayoutWnd* pWnd, bool open = true)
	{
		DisplayLayoutWndProperties(pWnd, true);

		if (BeginColorSection("CTileLayoutWnd Properties", open))
		{
			ColumnCheckBox("Horizontal First", pWnd->horizontalFirst);
			ColumnCheckBox("Anchor to Top", pWnd->anchorToTop);
			ColumnCheckBox("Anchor to Left", pWnd->anchorToLeft);
			ColumnText("Secondary Spacing", "%d", pWnd->secondarySpacing);
			ColumnCheckBox("First Piece Template", pWnd->firstPieceTemplate);
			ColumnCheckBox("Snap to Children", pWnd->snapToChildren);
			ColumnWindow("Autostretch Window", pWnd->autoStretchWindow);
		}
	}

	void DisplayInvSlotWndProperties(CInvSlotWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(pWnd, true);

		if (BeginColorSection("CInvSlotWnd Properties", open))
		{
			DisplayTextureAnimation("Background", pWnd->pBackground);
			ColumnItemGlobalIndex("Item location", pWnd->ItemLocation);

			// An invslot is either linked to a slot, or an item. Slots on the character pane are linked to slots.
			// Slots in your hotbar are usually linked to an item.
			if (pWnd->LinkedItem)
				ColumnItem("Linked item", pWnd->LinkedItem);
			else
			{
				ItemPtr pItem = pLocalPC->GetItemByGlobalIndex(pWnd->ItemLocation);
				ColumnItem("Item in slot", pItem);
			}

			ColumnCXSize("Item offset", CXSize(pWnd->ItemOffsetX, pWnd->ItemOffsetY));
			DisplayTextureAnimation("Item texture", pWnd->ptItem);
			ColumnText("Quantity", "%d", pWnd->Quantity);
			ColumnCheckBox("Selected", pWnd->bSelected);
			ColumnCheckBox("Find selected", pWnd->bFindSelected);
			ColumnCheckBox("Is hotbutton", pWnd->bHotButton);
			ColumnCheckBox("Is linked to inv slot", pWnd->bInventorySlotLinked);
			// TODO: CInvSlot
			DisplayTextObject("Text object", pWnd->pTextObject);
			ColumnText("Text style", "%d", pWnd->TextFontStyle);
			ColumnText("Mode", "%d", pWnd->Mode);
			ColumnColor("Background normal", pWnd->BGTintNormal);
			ColumnColor("Background Rollover", pWnd->BGTintRollover);
		}
	}

	void DisplayCListWndProperties(CListWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(pWnd, true);

		if (BeginColorSection("CListWnd Properties", open))
		{
			ColumnText("Rows", "%d", pWnd->ItemsArray.GetLength());

			if (ColumnTreeNodeType("Columns", "SListWndColumn[]", "%d", pWnd->Columns.GetLength()))
			{
				for (int i = 0; i < pWnd->Columns.GetLength(); ++i)
				{
					const SListWndColumn& column = pWnd->Columns[i];

					char label[32];
					sprintf_s(label, "Column %d", i + 1);

					const char* text = column.StrLabel.c_str();

					if (ColumnTreeNodeType(label, "SListWndColumn", "%s", text))
					{
						ColumnText("Width", "%d", column.Width);
						ColumnText("Minimum Width", "%d", column.MinWidth);
						ColumnCXSize("Texture Size", column.TextureSize);
						ColumnCXPoint("Texture Offset", column.TextureOffset);
						ColumnCXStr("Label", column.StrLabel);
						ColumnText("Data", "0x%08x", column.Data);
						ColumnText("Flags", "0x%08x", column.Flags);
						switch (column.Type)
						{
						case CellTypeBasicText: ColumnText("Cell Type", "%s", "Text"); break;
						case CellTypeBasicIcon: ColumnText("Cell Type", "%s", "Icon"); break;
						case CellTypeTextIcon: ColumnText("Cell Type", "%s", "Text & Icon"); break;
						default: ColumnText("Cell Type", "Unknown (%d)", column.Type); break;
						}
						DisplayTextureAnimation("Texture", column.pTextureAnim, true);
						DisplayTextureAnimation("Selected Texture", column.pSelected, true);
						DisplayTextureAnimation("MouseOver Texture", column.pMouseOver, true);
						ColumnCXStr("Tooltip", column.Tooltip);
						ColumnCheckBox("Resizable", column.bResizable);

						ImGui::TreePop();
					}
				}

				ImGui::TreePop();
			}

			if (ColumnTreeNodeType("Items", "SListWndLine[]", ""))
			{
				for (int i = 0; i < pWnd->ItemsArray.GetLength(); ++i)
				{
					const SListWndLine& line = pWnd->ItemsArray[i];

					char label[32];
					sprintf_s(label, "Row %d", i + 1);

					int cells = line.Cells.GetLength();

					static auto GetCellName = [](const SListWndCell& cell) -> const char*
					{
						const char* text = "(empty)";

						if (cell.pWnd)
							text = cell.pWnd->GetFirstChildWnd()->GetWindowText().c_str();
						else
							text = cell.Text.c_str();

						return text;
					};

					const char* text = "";

					if (cells >= 1)
					{
						text = GetCellName(line.Cells[0]);
					}

					if (ColumnTreeNodeType(label, "SListWndLine", "%s", text))
					{
						auto DoCell = [&](const SListWndCell& cell)
						{
							ColumnCXStr("Text", cell.Text);
							DisplayTextureAnimation("Texture", cell.pTA);
							ColumnColor("Color", cell.Color);
							ColumnWindow("Window", cell.pWnd);

							ColumnText("Texture only", cell.bOnlyDrawTexture ? "true" : "false");
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_TOL)
							ColumnText("Unknown1", "%p", cell.Unknown1);
#endif
						};

						if (cells > 0)
						{
							bool show = false;

							if (cells == 1)
							{
								if (ColumnTreeNodeType("Cell", "SListWndCell", "%s", text))
								{
									// do the one cell
									DoCell(line.Cells[0]);

									ImGui::TreePop();
								}
							}
							else
							{
								if (ColumnTreeNodeType("Cells", "SListWndCell[]", "%d", line.Cells.GetLength()))
								{
									// iterate
									for (int j = 0; j < line.Cells.GetLength(); ++j)
									{
										sprintf_s(label, "Column %d", j + 1);
										const SListWndCell& cell = line.Cells[j];

										if (ColumnTreeNodeType(label, "SListWndCell", "%s", GetCellName(cell)))
										{
											DoCell(cell);

											ImGui::TreePop();
										}
									}

									ImGui::TreePop();
								}
							}
						}

						ColumnText("Data", "%llu", line.Data);
						ColumnCheckBox("Selected", line.bSelected);
						ColumnCheckBox("Enabled", line.bEnabled);
						ColumnCheckBox("Visible", line.bVisible);

						ImGui::TreePop();
					}
				}

				ImGui::TreePop();
			}

			// Style
			if (ColumnTreeNode("List Style", "0x%08x", pWnd->ListWndStyle))
			{
				// TODO: Extract constants to eqlib
				ColumnCheckBoxFlags("Selectable", &pWnd->ListWndStyle, 0x10000);
				ColumnCheckBoxFlags("Multiselect", &pWnd->ListWndStyle, 0x20000);
				ColumnCheckBoxFlags("Autosort", &pWnd->ListWndStyle, 0x40000);
				ColumnCheckBoxFlags("Combobox", &pWnd->ListWndStyle, 0x100000);
				ColumnCheckBoxFlags("Header", &pWnd->ListWndStyle, 0x200000);
				ColumnCheckBoxFlags("HeaderSort", &pWnd->ListWndStyle, 0x400000);

				ImGui::TreePop();
			}

			if (ColumnTreeNode("List Details", ""))
			{
				ColumnColor("Header text color", pWnd->HeaderText);
				ColumnColor("Highlight color", pWnd->Highlight);
				ColumnColor("Selected color", pWnd->Selected);
				DisplayUITextureInfo("BG header", pWnd->BGHeader);
				ColumnColor("BG header tint", pWnd->BGHeaderTint);
				DisplayTextureAnimation("Row Separator", pWnd->pRowSep);
				DisplayTextureAnimation("Col Separator", pWnd->pColumnSep);

				ImGui::TreePop();
			}
		}
	}
};

#pragma endregion

#pragma region Window Inspector

class WindowInspector : public ImGuiWindowBase
{
	CXWnd* m_pSelectedWnd = nullptr;
	CXWnd* m_pHoveredWnd = nullptr;
	CXWnd* m_pLastSelected = nullptr;
	bool m_selectionChanged = false;
	bool m_picking = false;
	bool m_selectPicking = false;
	bool m_pickWindowChanged = false;
	CXWnd* m_pPickingWnd = nullptr;
	int m_lastWindowCount = 0;

	// this is a pointer because we want to lazy init it
	std::unique_ptr<ImGuiWindowPropertyViewer> m_selectedViewer;
	std::map<CXWnd*, ImGuiWindowPropertyViewer> m_propertyViewers;
	ImGuiID m_topNode = 0;
	ImGuiID m_bottomNode = 0;
	bool m_firstTime = true;
	ImGuiID m_mainDockId = 0;

public:
	WindowInspector()
		: ImGuiWindowBase("Window Inspector")
	{
	}

	void Reset()
	{
		m_selectedViewer.reset();
		m_pSelectedWnd = nullptr;
		m_pHoveredWnd = nullptr;
		m_pPickingWnd = nullptr;
		m_pLastSelected = nullptr;
		m_picking = false;
		m_selectPicking = false;
	}

	void Update() override
	{
		m_mainDockId = ImGui::GetID("WindowDeveloperTool");
		ImGuiDockNode* node = ImGui::DockBuilderGetNode(m_mainDockId);
		if (!node || m_bottomNode == 0)
		{
			if (node)
			{
				ImGui::DockBuilderRemoveNodeChildNodes(m_mainDockId);
			}
			else
			{
				ImGui::DockBuilderRemoveNode(m_mainDockId);
				ImGui::DockBuilderAddNode(m_mainDockId, ImGuiDockNodeFlags_None);
				ImGui::DockBuilderSetNodeSize(m_mainDockId, ImVec2(480, 640));

				ImGuiViewport* viewport = ImGui::GetMainViewport();
				ImGui::DockBuilderSetNodePos(m_mainDockId, ImVec2(viewport->Pos.x + 100, viewport->Pos.y + 100));

				node = ImGui::DockBuilderGetNode(m_mainDockId);
			}

			ImGuiDockNode* topNode = nullptr;

			if (!node->IsSplitNode())
			{
				ImGui::DockBuilderSplitNode(m_mainDockId, ImGuiDir_Up, 0.5f, &m_topNode, &m_bottomNode);
				topNode = ImGui::DockBuilderGetNode(m_topNode);
			}
			else
			{
				topNode = node->ChildNodes[0];
				m_topNode = topNode->ID;
			}

			topNode->LocalFlags |= ImGuiDockNodeFlags_NoWindowMenuButton;

			ImGui::DockBuilderDockWindow("Window Inspector", m_topNode);
			ImGui::DockBuilderDockWindow("###WindowPropertyViewer1", m_bottomNode);
			ImGui::DockBuilderFinish(m_mainDockId);
		}

		//----------------------------------------------------------------------------
		// Top Part: Show the window tree

		m_pHoveredWnd = nullptr;
		m_pPickingWnd = nullptr;
		m_pickWindowChanged = false;
		bool clearPicking = true;

		if (m_open)
		{
			bool doShow = ImGui::Begin("Window Inspector", m_open.get_ptr());
			m_open.Update();
			if (doShow)
			{
				if (m_picking)
				{
					// Don't pick anything if the mouse is out of the viewport. This check
					// clears the pick window when we leave the window because LastMouseOver doesn't
					// get cleared if the mouse isn't hovering the window.
					CXWnd* lastMouseOver = nullptr;
					ImGuiViewport* viewPort = ImGui::GetMainViewport();
					if (viewPort == ImGui::GetCurrentContext()->MouseViewport)
						lastMouseOver = pWndMgr->LastMouseOver;
					m_pickWindowChanged = test_and_set(m_pPickingWnd, lastMouseOver);
				}

				if (m_picking && m_selectPicking)
				{
					m_selectPicking = false;
					m_picking = false;

					m_pSelectedWnd = m_pPickingWnd;
					m_pPickingWnd = nullptr;
				}

				bool clicked = false;

				if (m_picking)
				{
					ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.13f, 0.6f, 0.6f));
					ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.13f, 0.7f, 0.7f));
					ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.13f, 0.8f, 0.8f));
				}

				clicked = ImGui::Button(ICON_MD_LOCATION_SEARCHING);

				if (m_picking)
				{
					ImGui::PopStyleColor(3);
				}

				if (ImGui::IsItemHovered())
				{
					if (!m_picking)
					{
						ImGui::SetTooltip("Click to start picking\n"
							"\n"
							"While picking is enabled, hover over UI components to highlight and identify them in the tree.\n"
							"Click a UI component to select it in the tree.");
					}
				}

				if (clicked)
				{
					m_picking = !m_picking;

					if (m_picking)
					{
						// activate main viewport
						ImGuiViewport* mainViewport = ImGui::GetMainViewport();

						if (ImGui::GetCurrentWindow()->Viewport->ID != mainViewport->ID)
						{
							// Activate the main viewport window.
							::SetActiveWindow((HWND)mainViewport->PlatformHandle);
						}
					}
				}

				if (m_picking)
				{
					ImGui::SameLine();
					ImGui::Text("Pick:");
					ImGui::SameLine();

					if (m_pPickingWnd)
					{
						ImGui::TextColored(ImColor(0.f, 1.0f, 0.0f, 1.0f), "%s", m_pPickingWnd->GetXMLName().c_str());
					}
					else
					{
						ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, 0.5f), "(none)");
					}
				}

				if (m_lastWindowCount != 0)
				{
					ImGui::SameLine();
					ImGui::PushItemWidth(-1);
					ImGui::Text("%d Windows", m_lastWindowCount);
				}

				DisplayWindowTree();
			}
			ImGui::End();

			// Close this window and all windows that are children of the current dock
			if (!m_open)
			{
				// Remove any property viewers still attached to the window
				for (auto iter = m_propertyViewers.begin(); iter != m_propertyViewers.end();)
				{
					const auto& [_, viewer] = *iter;

					if (ImGuiWindow* window = ImGui::FindWindowByName(viewer.GetWindowId()))
					{
						if (window->DockId == m_bottomNode || window->DockId == m_topNode)
						{
							iter = m_propertyViewers.erase(iter);
							continue;
						}
					}

					++iter;
				}
			}

			DrawMemoryEditors();
		}

		if (!m_open)
		{
			m_picking = false; // can't pick if not showing picker
			m_pSelectedWnd = nullptr;
			m_pHoveredWnd = nullptr;
			m_pPickingWnd = nullptr;
			m_pLastSelected = nullptr;
		}

		// update last selected to remember selection for next iteration
		m_selectionChanged = test_and_set(m_pLastSelected, m_pSelectedWnd);

		//----------------------------------------------------------------------------
		// Bottom part: show the dock area of property windows

		// Update the targeted window inspector
		if (m_selectionChanged)
		{
			ShowWindowInspector(m_pSelectedWnd, true);
		}

		// Draw all the window inspectors
		DrawPropertyViewers();

		// Update background overlay showing whats currently highlighted or selected
		DrawBackgroundWindowHighlights();
	}

	void ShowWindowInspector(CXWnd* pWnd, bool isSelected = false)
	{
		if (isSelected)
		{
			if (pWnd)
			{
				if (!m_selectedViewer)
				{
					m_selectedViewer = std::make_unique<ImGuiWindowPropertyViewer>(1);
				}

				m_selectedViewer->SetWindow(pWnd);
				m_selectedViewer->SetNeedFocus(true);
				m_open = true;
			}
			else if (m_selectedViewer)
			{
				m_selectedViewer.reset();
			}
		}
		else if (pWnd)
		{
			// find pWnd.
			auto iter = m_propertyViewers.find(pWnd);
			if (iter == m_propertyViewers.end())
			{
				static int nextInstanceId = 2; // 1 = target viewer. start at 2.
				auto [iter, _] = m_propertyViewers.emplace(
					std::piecewise_construct,
					std::forward_as_tuple(pWnd),
					std::forward_as_tuple(nextInstanceId++, pWnd));
			}
			else
			{
				iter->second.SetNeedFocus(true);
			}
		}
	}

	void RemoveWindowInspector(CXWnd* pWnd)
	{
		if (pWnd == m_pSelectedWnd)
		{
			m_selectedViewer.reset();
			m_pSelectedWnd = nullptr;
		}
		m_propertyViewers.erase(pWnd);
	}

	void DrawPropertyViewers()
	{
		if (m_pSelectedWnd && m_selectedViewer)
		{
			if (!m_selectedViewer->Draw())
			{
				m_selectedViewer.reset();
				m_pSelectedWnd = nullptr;
			}
		}

		// Iterate over each property viewer and show it. If its closed then remove it from the map
		for (auto iter = m_propertyViewers.begin(); iter != m_propertyViewers.end();)
		{
			if (iter->second.GetNeedDock())
			{
				ImGui::DockBuilderDockWindow(iter->second.GetWindowId(), m_bottomNode);
				iter->second.SetNeedDock(false);
			}

			if (!iter->second.Draw())
			{
				iter = m_propertyViewers.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	void DrawBackgroundWindowHighlights()
	{
		if (m_pSelectedWnd && m_pSelectedWnd->IsVisible())
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImDrawList* drawList = ImGui::GetBackgroundDrawList(viewport);

			CXRect clientRect = GetWndClientRect(m_pSelectedWnd);
			drawList->AddRect(
				ImVec2(clientRect.left + viewport->Pos.x, clientRect.top + viewport->Pos.y),
				ImVec2(clientRect.right + viewport->Pos.x, clientRect.bottom + viewport->Pos.y),
				IM_COL32(124, 252, 0, 200));
		}

		if (m_pPickingWnd)
		{
			CXWnd* wnd = m_pPickingWnd ? m_pPickingWnd : m_pSelectedWnd;

			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImDrawList* drawList = ImGui::GetBackgroundDrawList(viewport);

			CXRect clientRect = GetWndClientRect(wnd);
			drawList->AddRectFilled(
				ImVec2(clientRect.left + viewport->Pos.x, clientRect.top + viewport->Pos.y),
				ImVec2(clientRect.right + viewport->Pos.x, clientRect.bottom + viewport->Pos.y),
				IM_COL32(138, 179, 191, 128));
		}

		if (m_pHoveredWnd)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImDrawList* drawList = ImGui::GetBackgroundDrawList(viewport);

			CXRect clientRect = GetWndClientRect(m_pHoveredWnd);
			drawList->AddRect(
				ImVec2(clientRect.left + viewport->Pos.x, clientRect.top + viewport->Pos.y),
				ImVec2(clientRect.right + viewport->Pos.x, clientRect.bottom + viewport->Pos.y),
				m_pHoveredWnd->IsReallyVisible() ? IM_COL32(255, 215, 0, 200) : IM_COL32(200, 20, 60, 200));
		}
	}

	std::vector<std::pair<std::string_view, CXWnd*>> m_windows;
	std::unordered_set<CXWnd*> m_traversedWindows;

	void DisplayWindowTree()
	{
		ImGuiTableFlags tableFlags = ImGuiTableFlags_ScrollY
			| ImGuiTableFlags_BordersV
			| ImGuiTableFlags_BordersOuterH
			| ImGuiTableFlags_Resizable
			| ImGuiTableFlags_RowBg;

		m_traversedWindows.clear();

		if (ImGui::BeginTable("##WindowTable", 2, tableFlags))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch, .9f);
			ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthFixed);
			ImGui::TableHeadersRow();

			m_windows.reserve(m_lastWindowCount);
			m_lastWindowCount = 0;

			if (pWndMgr)
			{
				m_windows.clear();

				for (CXWnd* pWnd : pWndMgr->ParentAndContextMenuWindows)
				{
					if (pWnd->ParentWindow == nullptr
						&& (pWnd->GetXMLData() != nullptr
							|| pWnd->GetFirstChildWnd() != nullptr
							|| !pWnd->GetWindowText().empty()
							|| !pWnd->GetXMLName().empty()))
					{
						m_windows.emplace_back(std::string_view{ pWnd->GetXMLName() }, pWnd);
					}
				}

				std::sort(std::begin(m_windows), std::end(m_windows),
					[](const auto& l, const auto& r) { return ci_less()(l.first, r.first); });

				for (const auto& [_, pWnd] : m_windows)
				{
					DisplayWindowTreeNode(pWnd, true);
				}

				m_lastWindowCount = static_cast<int>(m_windows.size());
			}

			ImGui::EndTable();
		}
	}

	void DisplayWindowTreeNode(CXWnd* pWnd, bool isRoot = false, const char* nameOverride = nullptr)
	{
		if (!isRoot)
		{
			if (m_traversedWindows.count(pWnd) != 0)
				return;
			m_traversedWindows.insert(pWnd);
		}

		ImGui::TableNextRow();
		ImGui::TableNextColumn();

		const bool hasChildren = pWnd->GetFirstChildWnd() != nullptr;

		std::string_view name;
		if (nameOverride != nullptr)
			name = nameOverride;
		else
			name = pWnd->GetXMLNameSv();
		std::string_view typeName = pWnd->GetTypeNameSv();

		if (name.empty())
		{
			// Try to find something to display
			if (!pWnd->WindowText.empty())
			{
				name = pWnd->WindowText;
			}
			else if (pWnd->pTextObject)
			{
				name = pWnd->pTextObject->GetText();
			}

			if (name.empty())
			{
				name = "(no name)";
			}
		}

#if HAS_GAMEFACE_UI
		if (static_cast<int>(gGameState) >= GAMESTATE_CHARSELECT
			&& string_equals(typeName, "Screen")
			&& string_equals(pWnd->GetWndClassName(), "GFScreenWnd"))
		{
			typeName = "GameFace Screen";
		}
#endif

		ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_SpanAvailWidth;
		bool open = false;
		bool selected = (m_pLastSelected == pWnd);
		bool selectPicking = false;

		if (m_picking)
		{
			if (m_pPickingWnd == pWnd && m_pickWindowChanged)
			{
				selected = true;
				selectPicking = true;
			}
		}

		if (selected)
		{
			flags |= ImGuiTreeNodeFlags_Selected;
		}

		if (!hasChildren)
		{
			flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
		}

		if (hasChildren)
		{
			if (m_pPickingWnd)
			{
				if (m_pPickingWnd->IsDescendantOf(pWnd))
					flags |= ImGuiTreeNodeFlags_DefaultOpen;
			}
			else if (m_pSelectedWnd && m_selectionChanged)
			{
				if (m_pSelectedWnd->IsDescendantOf(pWnd))
				{
					ImGui::SetNextItemOpen(true);
				}
			}

			open = ImGui::TreeNodeEx(pWnd, flags, "%.*s", name.length(), name.data());
		}
		else
		{
			ImGui::TreeNodeEx(pWnd, flags, "%.*s", name.length(), name.data());
		}

		bool openNew = false;

		if (ImGui::BeginPopupContextItem())
		{
			if (ImGui::Selectable("Open New Inspector"))
				openNew = true;
			ImGui::Separator();
			if (ImGui::Selectable("Copy Window Child TLO"))
				CopyWindowChildTLO(pWnd);
			if (ImGui::Selectable("View Memory"))
				AddMemoryEditor(pWnd, sizeof(CXWnd));

			ImGui::EndPopup();
		}

		if (selectPicking)
		{
			ImGui::SetScrollHereY();
		}

		if (ImGui::IsItemHovered())
		{
			m_pHoveredWnd = pWnd;
		}

		if (ImGui::IsItemClicked())
		{
			// If ctrl key is pressed, create a secondary inspector instead
			if (ImGui::GetIO().KeyCtrl)
				DeveloperTools_WindowInspector_Show(pWnd);
			else
			{
				m_pSelectedWnd = pWnd;
				m_selectionChanged = true;
			}
		}
		else if (openNew)
		{
			DeveloperTools_WindowInspector_Show(pWnd);
		}

		ImGui::TableNextColumn();
		ImGui::TextUnformatted(typeName.data(), typeName.data() + typeName.length());

		if (open)
		{
			// If this is a list box, then also traverse its child list windows.
			if (pWnd->GetType() == UI_Listbox || pWnd->GetType() == UI_TreeView)
			{
				CListWnd* listWnd = static_cast<CListWnd*>(pWnd);
				int rowNum = 0;

				for (const SListWndLine& line : listWnd->ItemsArray)
				{
					bool hasWndCell = false;
					int rowFlags = 0;
					++rowNum;

					for (const SListWndCell& cell : line.Cells)
					{
						if (cell.pWnd)
						{
							CXWnd* pListChildWnd = cell.pWnd;

							if (m_pPickingWnd)
							{
								if (m_pPickingWnd->IsDescendantOf(pListChildWnd))
									rowFlags |= ImGuiTreeNodeFlags_DefaultOpen;
							}
							else if (m_pSelectedWnd && m_selectionChanged)
							{
								if (m_pSelectedWnd == pListChildWnd
									|| m_pSelectedWnd->IsDescendantOf(pListChildWnd))
								{
									ImGui::SetNextItemOpen(true);
								}
							}

							hasWndCell = true;
						}
					}

					if (!hasWndCell)
						continue;

					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					if (ImGui::TreeNodeEx(&line, rowFlags, "Row %d", rowNum))
					{
						int colNum = 1;
						for (const SListWndCell& cell : line.Cells)
						{
							// The children of the list are stored in wrapper windows. They show up
							// as Unknown types. We just skip past them.
							if (cell.pWnd && cell.pWnd->GetFirstChildWnd())
							{
								CXWnd* pListChildWnd = cell.pWnd;

								char columnName[64];
								sprintf_s(columnName, "Col %d", colNum);

								DisplayWindowTreeNode(pListChildWnd, false, columnName);
							}
							colNum++;
						}
						ImGui::TreePop();
					}
					else
					{
						for (const SListWndCell& cell : line.Cells)
						{
							if (cell.pWnd)
								m_traversedWindows.insert(cell.pWnd);
						}
					}
				}
			}

			CXWnd* pChild = pWnd->GetFirstChildWnd();
			while (pChild)
			{
				DisplayWindowTreeNode(pChild);
				pChild = pChild->GetNextSiblingWnd();
			}

			ImGui::TreePop();
		}
	}

	void OnWindowRemoved(CXWnd* pWnd)
	{
		// Clear the property viewer if its using this window.
		if (m_selectedViewer && m_selectedViewer->GetWindow() == pWnd)
		{
			m_selectedViewer.reset();
		}

		// Clear any matching selections in the window.
		if (m_pSelectedWnd == pWnd)
			m_pSelectedWnd = nullptr;
		if (m_pHoveredWnd == pWnd)
			m_pHoveredWnd = nullptr;
		if (m_pPickingWnd == pWnd)
			m_pPickingWnd = nullptr;
		if (m_pLastSelected == pWnd)
			m_pLastSelected = nullptr;

		RemoveWindowInspector(pWnd);
	}

	bool IsPicking() const { return m_picking; }

	void Pick()
	{
		if (m_picking)
			m_selectPicking = true;
	}

	void SetSelectedWindow(CXWnd* pWnd)
	{
		m_pSelectedWnd = pWnd;
	}

	void SetHoveredWindow(CXWnd* pWnd)
	{
		m_pHoveredWnd = pWnd;
	}
};
static WindowInspector* s_windowInspector = nullptr;

#pragma endregion

#pragma region Window Property Customizations

// We grant the ability to specialize the window property viewer for windows with specific names.
using WindowPropertyViewerCustomization = void(*)(CSidlScreenWnd*, ImGuiWindowPropertyViewer*);
std::unordered_map<std::string_view, WindowPropertyViewerCustomization> s_windowDisplayCustomizations;

static void RegisterWindowPropertyViewer(const char* windowName, const WindowPropertyViewerCustomization& callback)
{
	s_windowDisplayCustomizations.emplace(windowName, callback);
}

static void DisplayCustomWindowPropertyViewer(CSidlScreenWnd* pWindow, ImGuiWindowPropertyViewer* viewer)
{
	if (!pWindow) return;
	if (!pWindow->SidlPiece) return;

	std::string_view windowName = pWindow->SidlPiece->strName;

	auto iter = s_windowDisplayCustomizations.find(windowName);
	if (iter == s_windowDisplayCustomizations.end())
	{
		return;
	}

	const WindowPropertyViewerCustomization& callback = iter->second;

	char szSectionTitle[64] = { 0 };
	sprintf_s(szSectionTitle, "%s Properties", pWindow->SidlPiece->strName.c_str());

	if (viewer->BeginColorSection(szSectionTitle, true))
	{
		callback(pWindow, viewer);
	}
}

// Property Viewer for ItemDisplayWindow
static void WindowProperties_ItemDisplayWindow(CSidlScreenWnd* pSidlWindow, ImGuiWindowPropertyViewer* viewer)
{
	CItemDisplayWnd* pWindow = static_cast<CItemDisplayWnd*>(pSidlWindow);

	ColumnCXStr("ItemInfo", pWindow->ItemInfo);
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COV)
	ColumnCXStr("Unknown0x2ac", pWindow->Unknown0x2ac);
	ColumnCXStr("Unknown0x2b0", pWindow->Unknown0x2b0);
#endif
	ColumnCXStr("WindowTitle", pWindow->WindowTitle);
	ColumnCXStr("ItemAdvancedLoreText", pWindow->ItemAdvancedLoreText);
	ColumnCXStr("ItemMadeByText", pWindow->ItemMadeByText);
	ColumnCXStr("SolventText", pWindow->SolventText);
	ColumnCXStr("ItemInformationText", pWindow->ItemInformationText);
	// Item pItem
	ColumnCheckBox("Active Item", pWindow->bActiveItem);
	ColumnCheckBox("Item Text Set", pWindow->bItemTextSet);

	DisplayTextureAnimation("DragIcons", pWindow->DragIcons, true);
	ColumnText("Tab Count", "%d", pWindow->TabCount);

	ColumnText("Window Index", "%d", pWindow->ItemWndIndex);
}

// Property Viewer for SpellDisplayWindow
static void WindowProperties_SpellDisplayWindow(CSidlScreenWnd* pSidlWindow, ImGuiWindowPropertyViewer* viewer)
{
	CSpellDisplayWnd* pWindow = static_cast<CSpellDisplayWnd*>(pSidlWindow);

	ColumnText("Spell ID", "%d", pWindow->SpellID);
	ColumnText("Window ID", "%d", pWindow->WindowID);
	ColumnString("Title Text", &pWindow->TitleText);
	ColumnString("Description Text", &pWindow->DescriptionText);
#if IS_LIVE_CLIENT
	ColumnString("Caster Name", &pWindow->CasterName);
#endif
	DisplayTextureAnimation("Spell Icon", pWindow->ptaBuffIcons);
	DisplayTextureAnimation("Drag Icon", pWindow->ptaDragIcons);
	ColumnText("Display Type", "%d", pWindow->SpellDisplayType);
	ColumnElapsedTimestamp("Last Update Time", pWindow->LastUpdateTime - EQGetTime());
#if IS_LIVE_CLIENT
	ColumnText("Unknown", "%d", pWindow->Unknown);
#endif
}

// Property Viewer for Buffwindow
static void WindowProperties_BuffWindow(CSidlScreenWnd* pSidlWindow, ImGuiWindowPropertyViewer* viewer)
{
	CBuffWindow* pWindow = static_cast<CBuffWindow*>(pSidlWindow);

	DisplayTextureAnimation("Blue Icon Background", pWindow->ptaBlueIconBackground);
	DisplayTextureAnimation("Red Icon Background", pWindow->ptaRedIconBackground);
	DisplayTextureAnimation("Yellow Icon Background", pWindow->ptaYellowIconBackground);

	int count = pWindow->GetTotalBuffCount();

	if (ColumnTreeNode("Buffs", "%d", count))
	{
		for (const auto& buffInfo : pWindow->GetBuffRange())
		{
			EQ_Spell* pSpell = buffInfo.GetSpell();

			char szName[32];
			sprintf_s(szName, "Buff %d", buffInfo.GetIndex() + 1);

			if (ColumnTreeNode(szName, "%s", pSpell->Name))
			{
				ColumnTextType("SpellId", "int", "%d", buffInfo.GetSpellID());
				ColumnTextType("Name", "char[64]", "%s", pSpell->Name);
				if (buffInfo.GetBuffTimer() < 0)
					ColumnText("Buff Timer", "Permanent");
				else
					ColumnElapsedTimestamp("Buff Timer", buffInfo.GetBuffTimer());
				DisplayTextureAnimation("Buff Icon", buffInfo.GetBuffIcon());
				ColumnWindow("Button", buffInfo.GetBuffButton());
				DisplayTextObject("Time Remaining", buffInfo.GetTimeRemainingText());
				DisplayTextObject("Counter", buffInfo.GetCounterText());
				DisplayTextObject("Limited Uses", buffInfo.GetLimitUseText());
				ColumnText("Caster", "%s", buffInfo.GetCaster());

				ImGui::TreePop();
			}
		}

		ImGui::TreePop();
	}

	ColumnElapsedTimestamp("Next Refresh Time", pWindow->nextRefreshTime - pDisplay->TimeStamp);
	ColumnText("Init Window Size", "%d, %d", pWindow->initWindowWidth, pWindow->initWindowHeight);
	ColumnText("WindowType", "%s (%d)", pWindow->buffWindowType == BuffWindowStandard ? "Buffs" : "ShortBuffs", pWindow->buffWindowType);
	ColumnText("First Effect Slot", "%d", pWindow->firstEffectSlot);
	ColumnText("Last Effect Slot", "%d", pWindow->lastEffectSlot);
	ColumnText("Max Buff Buttons", "%d", pWindow->maxBuffButtons);
	ColumnText("Context Menu ID", "%d", pWindow->ContextMenuID);
	//ColumnWindow("Select Button", pWindow->selectedButtonWnd);
	ColumnElapsedTimestamp("Last Buff Refresh Time", pWindow->lastBuffRefreshTime);
}

// Propert Viewer for CompassWindow
static void WindowProperties_CompassWindow(CSidlScreenWnd* pSidlWindow, ImGuiWindowPropertyViewer* viewer)
{
	CCompassWnd* pWindow = static_cast<CCompassWnd*>(pSidlWindow);

	DisplayTextureAnimation("Compass 1", pWindow->pStrip1 ? pWindow->pStrip1->ptaTextureAnimation : nullptr);
	DisplayTextureAnimation("Compass 2", pWindow->pStrip2 ? pWindow->pStrip2->ptaTextureAnimation : nullptr);
	ColumnText("Offset", "%d", pWindow->offset);
	ColumnText("Speed", "%.2f", pWindow->speed);

	ColumnArrayList("Line Data", "CompassLineSource", pWindow->lineData.GetLength(),
		pWindow->lineData.begin(), pWindow->lineData.end(), [](CompassLineSource* line)
	{
		MQColor lineColor(line->Red, line->Green, line->Blue);
		ColumnColor("Color", lineColor);
		CVector3 point(line->Y, line->X, line->Z);
		ColumnCVector3("Point", point);
		ColumnCheckBox("Visible", line->ShowLine);
	});
}

// Property Viewer for CCursorAttachment
static void WindowProperty_CursorAttachment(CSidlScreenWnd* pSidlWindow, ImGuiWindowPropertyViewer* viewer)
{
	CCursorAttachment* pCursorAttachment = static_cast<CCursorAttachment*>(pSidlWindow);

#if HAS_GAMEFACE_UI
	if (!pEverQuestInfo->bUseNewUIEngine)
#endif
	{
		DisplayDynamicTemplateExpand("Background", pCursorAttachment->pBGStaticAnim, "CStaticAnimationTemplate*");
		DisplayDynamicTemplateExpand("Overlay", pCursorAttachment->pOverlayStaticAnim, "CStaticAnimationTemplate*");
		DisplayTextObject("Text Object", pCursorAttachment->pTextObject);
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_TBL)
		DisplayTextObject("Button Text Object", pCursorAttachment->pButtonTextObject);
#endif
		ColumnText("Text Font Style", "%d", pCursorAttachment->TextFontStyle);
	}

	ColumnText("Type", "%d", pCursorAttachment->Type);
	ColumnText("Index", "%d", pCursorAttachment->Index);
	ColumnText("Item Guid", "%s", pCursorAttachment->ItemGuid.guid);
	ColumnText("Item ID", "%d", pCursorAttachment->ItemID);
	ColumnText("Quantity", "%d", pCursorAttachment->Qty);
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_TBL) // Rough approximation -- Added in 2018/06/19
	ColumnText("IconID", "%d", pCursorAttachment->IconID);
	ColumnText("Assigned Name", pCursorAttachment->AssignedName.c_str());
#endif
	ColumnCXStr("Button Text", pCursorAttachment->ButtonText);
	ColumnWindow("Spell Gem", pCursorAttachment->pSpellGem);
}

// Property Viewer for FindLocationWnd
static void WindowProperties_FindLocationWnd(CSidlScreenWnd* pSidlWindow, ImGuiWindowPropertyViewer* viewer)
{
	CFindLocationWnd* pWnd = (CFindLocationWnd*)pSidlWindow;

	ColumnElapsedTimestamp("Last Update Time", pWnd->lastUpdateTime - pDisplay->TimeStamp);
	ColumnElapsedTimestamp("Last Find Request Time", pWnd->lastFindRequestTime - pDisplay->TimeStamp);
	ColumnCheckBox("Did Find Request", pWnd->didFindRequest);

	auto doPlayerData = [](const CFindLocationWnd::FindPlayerData& data)
	{
		ColumnText("Spawn ID", "%d", data.spawnId);
		ColumnCXStr("Name", data.name);
		ColumnCXStr("Description", data.description);
		ColumnText("Race", "%d", data.race);
		ColumnText("Class", "%d", data.Class);
	};
	auto doPlayerLabel = [](char* szLabel, size_t len, const CFindLocationWnd::FindPlayerData& data)
	{
		strcpy_s(szLabel, len, data.name.c_str());
	};

	ColumnArrayList("Unfiltered Players", "FindPlayerData", pWnd->unfilteredPlayerList.GetLength(),
		pWnd->unfilteredPlayerList.begin(), pWnd->unfilteredPlayerList.end(), doPlayerData, doPlayerLabel);
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
	ColumnArrayList("Filtered Group Players", "FindPlayerData", pWnd->filteredGroupPlayerList.GetLength(),
		pWnd->filteredGroupPlayerList.begin(), pWnd->filteredGroupPlayerList.end(), doPlayerData, doPlayerLabel);
	ColumnArrayList("Unfiltered Raid Players", "FindPlayerData", pWnd->unfilteredRaidPlayerList.GetLength(),
		pWnd->unfilteredRaidPlayerList.begin(), pWnd->unfilteredRaidPlayerList.end(), doPlayerData, doPlayerLabel);
#endif

	ColumnArrayList("Unfiltered POIs", "FindPOIData", pWnd->unfilteredPOIDataList.GetLength(),
		pWnd->unfilteredPOIDataList.begin(), pWnd->unfilteredPOIDataList.end(),
		[](const CFindLocationWnd::FindPOIData& data)
	{
		ColumnText("ID", "%d", data.id);
		ColumnCXStr("Name", data.name, false);
		ColumnCXStr("Description", data.description, false);
	}, [](char* szLabel, size_t len, const CFindLocationWnd::FindPOIData& data)
	{
		strcpy_s(szLabel, len, data.name.c_str());
	});

	ColumnArrayList2("Zone Connections", "ZoneConnectionData", pWnd->unfilteredZoneConnectionList.GetLength(),
		pWnd->unfilteredZoneConnectionList.begin(), pWnd->unfilteredZoneConnectionList.end(),
		[](const char* szLabel, const CFindLocationWnd::FindZoneConnectionData& data)
	{
		if (ColumnEQZoneIndex(szLabel, data.zoneId, true))
		{
			ColumnText("Type", "%s", FindLocationTypeToString(data.type));
			ColumnText("ID", "%d", data.id);
			ColumnText("SubID", "%d", data.subId);
			ColumnText("ZoneID", "%d", data.zoneId);
			ColumnText("Zone Identifier", "%d", data.zoneIdentifier);
			ColumnCVector3("Location", data.location);
			ImGui::TreePop();
		}
	});

	ColumnArrayList("Reference List", "FindableReference", static_cast<int>(pWnd->referenceList.size()),
		pWnd->referenceList.begin(), pWnd->referenceList.end(),
		[pWnd](const std::pair<CFindLocationWnd::FindableReference, int>& data)
	{
		ColumnText("Reference Key", "%d", data.second);
		ColumnText("Type", "%s", FindLocationTypeToString(data.first.type));

		if (data.first.type == FindLocation_Player)
		{
			ColumnText("Spawn ID", "%d", data.first.index);
			if (PlayerClient* pPlayer = GetSpawnByID(data.first.index))
			{
				if (pPlayer->Lastname[0] && pPlayer->Type == SPAWN_NPC)
					ColumnText("Name", "%s (%s)", pPlayer->DisplayedName, pPlayer->Lastname);
				else
					ColumnText("Name", "%s", pPlayer->DisplayedName);
				ColumnCVector3("Location", *(CVector3*)&pPlayer->Y);
			}
			return;
		}

		ColumnText("Index", "%d", data.first.index);

		switch (data.first.type)
		{
		case FindLocation_Switch: {
			const CFindLocationWnd::FindZoneConnectionData& connData = pWnd->unfilteredZoneConnectionList[data.first.index];
			ColumnEQZoneIndex("Zone Connection", connData.zoneId);
			ColumnCVector3("Location", connData.location);

			ColumnText("Switch ID", "%d", connData.id);
			if (EQSwitch* pSwitch = pSwitchMgr->GetSwitchById(connData.id))
			{
				ColumnText("Switch", "%s", pSwitch->Name);
			}
			break;
		}

		case FindLocation_Location: {
			const CFindLocationWnd::FindZoneConnectionData& connData = pWnd->unfilteredZoneConnectionList[data.first.index];
			ColumnEQZoneIndex("Zone Connection", connData.zoneId);
			ColumnCVector3("Location", connData.location);
			break;
		}

		default: break;
		}
	},
		[pWnd](char* szLabel, size_t len, const std::pair<CFindLocationWnd::FindableReference, int>& data)
	{
		sprintf_s(szLabel, len, "%d - %s: ", data.second, FindLocationTypeToString(data.first.type));

		if (data.first.type == FindLocation_Player)
		{
			if (PlayerClient* pPlayer = GetSpawnByID(data.first.index))
			{
				char szTemp[64] = { 0 };
				if (pPlayer->Lastname[0] && pPlayer->Type == SPAWN_NPC)
					sprintf_s(szTemp, "%s (%s)", pPlayer->DisplayedName, pPlayer->Lastname);
				else
					sprintf_s(szTemp, "%s", pPlayer->DisplayedName);
				strcat_s(szLabel, len, szTemp);
			}
		}
		else if (data.first.type == FindLocation_Switch || data.first.type == FindLocation_Location)
		{
			const CFindLocationWnd::FindZoneConnectionData& connData = pWnd->unfilteredZoneConnectionList[data.first.index];
			strcat_s(szLabel, len, GetFullZone(connData.zoneId));
		}
		else
		{
			strcat_s(szLabel, len, "Unknown");
		}
	});

	ColumnText("Last ID", "%d", pWnd->lastId);
	ColumnCheckBox("Data Requested", pWnd->dataRequested);
	ColumnCheckBox("Player List Dirty", pWnd->playerListDirty);
	ColumnCheckBox("Zone Connections Received", pWnd->zoneConnectionsRcvd);
}

//----------------------------------------------------------------------------
// Property Viewer for ZoneGuideWnd and ZoneGuideManagerClient


static void WindowProperties_ZoneGuideWnd(CSidlScreenWnd* pSidlWindow, ImGuiWindowPropertyViewer* viewer)
{
	CZoneGuideWnd* pWnd = (CZoneGuideWnd*)pSidlWindow;

	ColumnElapsedTimestamp("Next button refresh time", pWnd->NextButtonRefreshTime - pDisplay->TimeStamp);

	EQZoneInfo* pZone = pWorldData->GetZone(pWnd->CurrentZone);
	ColumnText("Current zone", "%s", pZone ? pZone->ShortName : "(null)");

	ColumnCheckBox("Filter active", pWnd->bFilterActive);
	ColumnText("Filter level", "%d", pWnd->FilterLevel);
	ColumnText("Filter continent", "%d", pWnd->FilterContinentIndex);     // maps to zone guide continents
	ColumnText("Filter zone type", "%d", pWnd->FilterZoneTypeIndex);
	ColumnCheckBox("Select current zone", pWnd->bSelectCurrentZone);
	ColumnText("Zone search string", "%s", pWnd->ZoneSearchString.c_str());
	ColumnText("Current connections view", "%d", pWnd->eCurrConnectionsView);
	ColumnCheckBox("Preview path changed", pWnd->bCurrentConnectionsViewPreviewPathChanged);
	ColumnCheckBox("Active path changed", pWnd->bCurrentConnectionsViewActivePathChanged);

	pZone = pWorldData->GetZone(pWnd->StartZone);
	ColumnText("Start zone", "%s", pZone ? pZone->ShortName : "(null)");
	pZone = pWorldData->GetZone(pWnd->EndZone);
	ColumnText("End zone", "%s", pZone ? pZone->ShortName : "(null)");

	ColumnCheckBox("Zone guide data changed", pWnd->bZoneGuideDataChanged);
	ColumnCheckBox("Zone list changed", pWnd->bZoneListChanged);
	ColumnCheckBox("Zone connections list changed", pWnd->bZoneConnectionsListChanged);
	ColumnText("Context Menu ID", "%d", pWnd->RightClickMenuID);

	// TODO: Maybe this should be its own viewer?
	if (ColumnTreeNode("Zone guide data", ""))
	{
		ZoneGuideManagerClient& zoneGuide = ZoneGuideManagerClient::Instance();

		// List of continents
		ColumnArrayList("Continents", "ZoneGuideContinent", static_cast<int>(zoneGuide.continents.size()),
			zoneGuide.continents.begin(), zoneGuide.continents.end(),
			[](const ZoneGuideContinent& continent)
		{
			ColumnCXStr("Name", continent.name, false);
			ColumnText("ID", "%d", continent.id);
			ColumnText("Display sequence", "%d", continent.displaySequence);
		},
			[](char* szLabel, size_t len, const ZoneGuideContinent& continent)
		{
			strcpy_s(szLabel, len, continent.name.c_str());
		});

		// List of zone types
		ColumnArrayList("Zone types", "ZoneGuideZoneType", static_cast<int>(zoneGuide.zoneTypes.size()),
			zoneGuide.zoneTypes.begin(), zoneGuide.zoneTypes.end(),
			[](const ZoneGuideZoneType& zoneType)
		{
			ColumnCXStr("Name", zoneType.name, false);
			ColumnText("ID", "%d", zoneType.id);
			ColumnText("Display sequence", "%d", zoneType.displaySequence);
		},
			[](char* szLabel, size_t len, const ZoneGuideZoneType& zoneType)
		{
			strcpy_s(szLabel, len, zoneType.name.c_str());
		});

		// List Zones
		static int zoneCount = 0;
		if (zoneCount == 0)
		{
			for (int i = 1; i < ZONE_COUNT; ++i)
			{
				if (zoneGuide.zones[i].zoneId != 0)
					++zoneCount;
			}

		}

		if (ColumnTreeNodeType("Zone Data", "ZoneGuideZone[]", "%d", zoneCount))
		{
			for (int index = 0; index < ZONE_COUNT; ++index)
			{
				if (zoneGuide.zones[index].zoneId == 0)
					continue;
				char szLabel[32] = { 0 };
				sprintf_s(szLabel, "%d", index);

				ZoneGuideZone& zone = zoneGuide.zones[index];

				if (ColumnEQZoneIndex(szLabel, zone.zoneId, true, "ZoneGuideZone"))
				{
					if (!zone.name.empty())
					{
						ColumnCXStr("Name", zone.name, false);
					}
					ColumnText("Continent", "%s (%d)", zoneGuide.GetContinentNameByIndex(zone.continentIndex).c_str(), zone.continentIndex);
					ColumnText("Level range", "%d - %d", zone.minLevel, zone.maxLevel);

					// zone types
					if (ColumnTreeNode("Types", ""))
					{
						int index = 0;
						for (uint16_t bit = 0; bit < zone.types.GetNumBits(); ++bit)
						{
							if (zone.types.IsBitSet(bit))
							{
								++index;
								char szIndexLabel[32] = { 0 };
								sprintf_s(szIndexLabel, "%d", index);
								ColumnCXStr(szIndexLabel, zoneGuide.GetZoneTypeNameByIndex(bit), false);
							}
						}

						ImGui::TreePop();
					}

					// zone connections
					ColumnArrayList2("Zone connections", "ZoneGuideConnection", static_cast<int>(zone.zoneConnections.size()),
						zone.zoneConnections.begin(), zone.zoneConnections.end(),
						[&zoneGuide](const char* szLabel, const ZoneGuideConnection& connection)
					{
						if (ColumnEQZoneIndex(szLabel, connection.destZoneId, true))
						{
							ColumnText("Transfer type", "%s", zoneGuide.GetZoneTransferTypeNameByIndex(connection.transferTypeIndex).c_str());
							ColumnText("Required expansion", "%d", connection.requiredExpansions);
							ColumnCheckBox("Disabled", connection.disabled);
							ImGui::TreePop();
						}
					});

					ImGui::TreePop();
				}
			}

			ImGui::TreePop();
		}

		// List of transfer types
		ColumnArrayList("Transfer types", "ZoneGuideTransferType", static_cast<int>(zoneGuide.transferTypes.size()),
			zoneGuide.transferTypes.begin(), zoneGuide.transferTypes.end(),
			[](const ZoneGuideTransferType& transferType)
		{
			ColumnCXStr("Name", transferType.description, false);
			ColumnText("ID", "%d", transferType.id);
		}, [](char* szLabel, size_t len, const ZoneGuideTransferType& transferType) { strcpy_s(szLabel, len, transferType.description.c_str()); });

		ColumnArrayList2("Active path", "ZonePathData", zoneGuide.activePath.GetLength(),
			zoneGuide.activePath.begin(), zoneGuide.activePath.end(),
			[&zoneGuide](const char* szLabel, const ZonePathData& data)
		{
			if (ColumnEQZoneIndex(szLabel, data.zoneId, true))
			{
				ColumnText("Transfer type", "%s (%d)", zoneGuide.GetZoneTransferTypeNameByIndex(data.transferTypeIndex).c_str(), data.transferTypeIndex);
				ImGui::TreePop();
			}
		});

		ColumnArrayList2("Preview path", "ZonePathData", zoneGuide.previewPath.GetLength(),
			zoneGuide.previewPath.begin(), zoneGuide.previewPath.end(),
			[&zoneGuide](const char* szLabel, const ZonePathData& data)
		{
			if (ColumnEQZoneIndex(szLabel, data.zoneId, true))
			{
				ColumnText("Transfer type", "%s (%d)", zoneGuide.GetZoneTransferTypeNameByIndex(data.transferTypeIndex).c_str(), data.transferTypeIndex);
				ImGui::TreePop();
			}
		});

		ColumnText("Heroes journey index", "%d", zoneGuide.heroesJourneyIndex);
		ColumnCheckBox("Zone guide data set", zoneGuide.zoneGuideDataSet);
		ColumnCheckBox("Include bind zone in path", zoneGuide.includeBindZoneInPath);
		ColumnCheckBox("Auto find active path", zoneGuide.autoFindActivePath);
		ColumnCheckBox("Find active path", zoneGuide.findActivePath);

		ImGui::TreePop();
	}
}

static void WindowProperties_ZonePathWnd(CSidlScreenWnd* pSidlWindow, ImGuiWindowPropertyViewer* viewer)
{
	CZonePathWnd* pWnd = (CZonePathWnd*)pSidlWindow;

	ColumnEQZoneIndex("Current zone", pWnd->currentZone);
	ColumnCheckBox("Zone path dirty", pWnd->zonePathDirty);
}

#if HAS_TRADESKILL_DEPOT
static void WindowProperties_TradeskillDepotWnd(CSidlScreenWnd* pSidlWindow, ImGuiWindowPropertyViewer* viewer)
{
	CTradeskillDepotWnd* pWnd = (CTradeskillDepotWnd*)pSidlWindow;

	ColumnCheckBox("Needs Update", &pWnd->bNeedsUpdate);
	ColumnItem("Selected Item", pWnd->pSelectedItem);
	ColumnText("Selected Item ID", "%d", pWnd->SelectedItemID);

	auto elapsed = std::chrono::steady_clock::now() - std::chrono::steady_clock::time_point(
		std::chrono::milliseconds(pWnd->lastUpdateTime));
	ColumnElapsedTimestamp("Time since last Update", (int)std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count());

	ColumnCheckBox("Unknown0x378", &pWnd->bUnknown5);
}
#endif

#if HAS_DRAGON_HOARD
static void WindowProperties_DragronHoardWnd(CSidlScreenWnd* pSidlWindow, ImGuiWindowPropertyViewer* viewer)
{
	CDragonHoardWnd* pWnd = (CDragonHoardWnd*)pSidlWindow;

	ColumnCheckBox("Needs Update", &pWnd->bNeedsUpdate);
	ColumnItem("Selected Item", pWnd->pSelectedItem);
	ColumnText("Selected Item ID", "%d", pWnd->SelectedItemId);
}
#endif

#pragma endregion

//============================================================================

void DeveloperTools_WindowInspector_Initialize()
{
	s_windowInspector = new WindowInspector();
	DeveloperTools_RegisterMenuItem(s_windowInspector, "Windows", s_menuNameInspectors);

	RegisterWindowPropertyViewer("BuffWindow", WindowProperties_BuffWindow);
	RegisterWindowPropertyViewer("CompassWindow", WindowProperties_CompassWindow);
	RegisterWindowPropertyViewer("CursorAttachment", WindowProperty_CursorAttachment);
#if HAS_DRAGON_HOARD
	RegisterWindowPropertyViewer("DragonHoardWnd", WindowProperties_DragronHoardWnd);
#endif
	RegisterWindowPropertyViewer("FindLocationWnd", WindowProperties_FindLocationWnd);
	RegisterWindowPropertyViewer("ItemDisplayWindow", WindowProperties_ItemDisplayWindow);
	RegisterWindowPropertyViewer("ShortDurationBuffWindow", WindowProperties_BuffWindow);
	RegisterWindowPropertyViewer("SpellDisplayWindow", WindowProperties_SpellDisplayWindow);
#if HAS_TRADESKILL_DEPOT
	RegisterWindowPropertyViewer("TradeskillDepotWnd", WindowProperties_TradeskillDepotWnd);
#endif
	RegisterWindowPropertyViewer("ZoneGuideWnd", WindowProperties_ZoneGuideWnd);
	RegisterWindowPropertyViewer("ZonePathWnd", WindowProperties_ZonePathWnd);
}

void DeveloperTools_WindowInspector_Shutdown()
{
	DeveloperTools_UnregisterMenuItem(s_windowInspector);
	delete s_windowInspector; s_windowInspector = nullptr;
}

void DeveloperTools_WindowInspector_SetGameState(int gameState)
{
	s_windowInspector->Reset();
}

void DeveloperTools_WindowInspector_ViewString(std::string_view name, const CXStr& string)
{
	ImGuiWindowPropertyViewer* currentPropertyViewer = ImGuiWindowPropertyViewer::GetCurrentViewer();
	if (!currentPropertyViewer)
		return;

	currentPropertyViewer->AddStringEditor(ImGuiWindowStringEditor(name, string));
}

void DeveloperTools_WindowInspector_EditString(std::string_view name, CXStr* string)
{
	ImGuiWindowPropertyViewer* currentPropertyViewer = ImGuiWindowPropertyViewer::GetCurrentViewer();
	if (!currentPropertyViewer)
		return;

	currentPropertyViewer->AddStringEditor(ImGuiWindowStringEditor(name, string));
}

void DeveloperTools_WindowInspector_ViewString(std::string_view name, const SoeUtil::String& string)
{
	ImGuiWindowPropertyViewer* currentPropertyViewer = ImGuiWindowPropertyViewer::GetCurrentViewer();
	if (!currentPropertyViewer)
		return;

	currentPropertyViewer->AddStringEditor(ImGuiWindowStringEditor(name, string));
}

void DeveloperTools_WindowInspector_EditString(std::string_view name, SoeUtil::String* string)
{
	ImGuiWindowPropertyViewer* currentPropertyViewer = ImGuiWindowPropertyViewer::GetCurrentViewer();
	if (!currentPropertyViewer)
		return;

	currentPropertyViewer->AddStringEditor(ImGuiWindowStringEditor(name, string));
}


//----------------------------------------------------------------------------

bool DeveloperTools_WindowInspector_HandleClick(int mouseButton, bool clicked)
{
	// If the picker is active, tell it that we clicked. Returns true (to consume the click) if this happens.
	if (mouseButton == 0 && clicked
		&& s_windowInspector
		&& s_windowInspector->IsPicking())
	{
		s_windowInspector->Pick();
		return true;
	}

	return false;
}

void DeveloperTools_WindowInspector_RemoveWindow(CXWnd* pWnd)
{
	if (s_windowInspector)
		s_windowInspector->OnWindowRemoved(pWnd);
}

void DeveloperTools_WindowInspector_Show(CXWnd* pWnd)
{
	if (s_windowInspector)
		s_windowInspector->ShowWindowInspector(pWnd);
}

void DeveloperTools_WindowInspector_SetSelectedWindow(CXWnd* pWnd)
{
	if (s_windowInspector)
		s_windowInspector->SetSelectedWindow(pWnd);
}

void DeveloperTools_CloseLoginFrontend()
{
	if (s_windowInspector)
		s_windowInspector->Reset();
}

void DeveloperTools_windowInspector_SetHoveredWindow(CXWnd* pWnd)
{
	if (s_windowInspector)
		s_windowInspector->SetHoveredWindow(pWnd);
}

} // namespace mq
