#pragma once
#include "LGUIelement.h"

class LGUICheckBox :
	public LGUIElement
{
public:
	LGUI_API LGUICheckBox(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUICheckBox(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);

	LGUI_API bool OnLMouseUp(POINT2I &pt);
	LGUI_API bool OnLMouseDown(POINT2I &pt);

	// -- XML Properties --
	LGUIPreParse Text;
	LGUIFont *pFont;

	LGUITexture *pTexture;
	LGUITexture *pTexturePressed;
	LGUITexture *pTextureHover;
	LGUITexture *pTextureChecked;
	LGUITexture *pTextureCheckedPressed;
	LGUITexture *pTextureCheckedHover;
	
	// --------------------

	bool bDown;
	bool bChecked;
};
