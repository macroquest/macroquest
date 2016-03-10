#pragma once


struct _CreateTooltip : public _CreateElement
{
	unsigned int BackgroundColor;
	unsigned int Border;
	unsigned int BorderColor;
	_CreateFont Font;
//	unsigned int TextColor;
//	unsigned int FontSize;
	bool DefaultTextures;
};

class LGUITooltipLine
{
public:
	LGUI_API LGUITooltipLine(const char *p_Text);
	LGUI_API ~LGUITooltipLine();
	LGUI_API char *Parse();

	LGUI_API void Set(const char *p_Text);

	char *Text;
	bool bVariable;
};

class LGUITooltip :
	public LGUIFrame
{
public:
	LGUI_API LGUITooltip(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUITooltip(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);
//	LGUI_API void Create(_CreateTooltip &CreateInfo, class XMLNode *pTemplate=0);
	LGUI_API bool OnMouseMove(POINT2I &pt);

	LGUI_API void Reset();
	LGUI_API void Printf(const char *Format, ...);
	LGUI_API void Print(const char *Text);

	// -- XML Properties  --
	LGUIFont *pFont;

	// ----------------------

	CIndex<LGUITooltipLine*> Lines;
	unsigned int nLines;

protected:
	LGUI_API void AddLine(const char *Text);

};

