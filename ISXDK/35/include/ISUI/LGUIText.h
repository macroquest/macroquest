#pragma once
#include "LGUIelement.h"

enum eTextAlign
{
	ALIGN_LEFT=0,
	ALIGN_CENTER=1,
	ALIGN_RIGHT=2,

	VALIGN_TOP=3,
	VALIGN_CENTER=4,
	VALIGN_BOTTOM=5,
};

struct _CreateText : public _CreateElement
{
	char *Text;
	_CreateFont Font;
//	char *Font;
//	unsigned int FontSize;
//	unsigned int Color;

	bool bWrap;
	eTextAlign Alignment;
	eTextAlign VerticalAlignment;
};

class LGUIText : public LGUIElement
{
public:
	LGUI_API LGUIText(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIText(void);
	LGUI_API bool IsTypeOf(char *TestFactory);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API static size_t SplitFixed(char *Value, size_t MaxChars, size_t &Width);
	LGUI_API static size_t Split(char *Value, size_t MaxWidth, LGUIFont *pFont, size_t &Width);
	LGUI_API size_t Split(char *Value);

	LGUI_API void Render();
	LGUI_API bool RenderCustom();

	LGUI_API void Create(_CreateText &CreateInfo, class XMLNode *pTemplate=0);

	LGUI_API void RenderLeft(char *Value);
	LGUI_API void RenderCenter(char *Value);
	LGUI_API void RenderRight(char *Value);
	LGUI_API void RecalculateSize(bool RecalculateChildren);


	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);

	LGUI_API void SetText(char *NewText);
	LGUI_API void SetHorizontalAlignment(eTextAlign value);
	LGUI_API void SetVerticalAlignment(eTextAlign value);
	LGUI_API void SetWrap(bool value);

	// -- XML Properties --
	char *Text;
	LGUIFont *pFont;

	bool bWrap;
	eTextAlign Alignment;
	eTextAlign VerticalAlignment;
	// --------------------

	char *NonVariable;
	size_t nLines;
};
