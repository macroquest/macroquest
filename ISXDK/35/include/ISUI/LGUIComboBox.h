#pragma once

class LGUIComboBox :
	public LGUIElement
{
public:
	LGUI_API LGUIComboBox(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIComboBox(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);
	LGUI_API void RecalculateSize(bool RecalculateChildren);
	LGUI_API void OnNotify(LGUIElement *pElement, unsigned int Notification, UINT_PTR Value);
	LGUI_API bool OnLMouseUp(POINT2I &pt);
	LGUI_API bool OnLMouseDown(POINT2I &pt);
	LGUI_API void OnLMouseDownOther(LGUIElement *pOther);

	// -- XML Properties  --
	LGUITexture *pTexture;
	LGUITexture *pButtonTexture;
	LGUIFont *pFont;

	unsigned int Border;

	unsigned int FullHeight;


	unsigned int ButtonWidth;

	LGUIEmbeddedScript *pOnSelect;
	// ----------------------


	LGUIListBox *pListBox;
	bool bDown;
	unsigned int NormalHeight;
	int Selection;
};
