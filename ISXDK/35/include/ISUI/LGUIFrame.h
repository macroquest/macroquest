#pragma once


struct _CreateFrame : public _CreateElement
{
	unsigned int BackgroundColor;
	unsigned int Border;
	unsigned int BorderColor;
};

class LGUIFrame :
	public LGUIElement
{
public:
	LGUI_API LGUIFrame(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIFrame(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);
	LGUI_API void Create(_CreateFrame &CreateInfo);

	LGUI_API bool OnLMouseUp(POINT2I &pt);
	LGUI_API bool OnLMouseDown(POINT2I &pt);
	LGUI_API bool OnLMouseDoubleClick(POINT2I &pt);
	LGUI_API bool OnRMouseDoubleClick(POINT2I &pt);
	LGUI_API bool OnRMouseUp(POINT2I &pt);
	LGUI_API bool OnRMouseDown(POINT2I &pt);
	LGUI_API bool OnMouseMove(POINT2I &pt);
	LGUI_API bool OnMouseWheel(int Offset);

	// -- XML Properties  --
	LGUITexture *pTexture;
	unsigned int BackgroundColor;
	unsigned int Border;
	unsigned int BorderColor;

	// ----------------------

};