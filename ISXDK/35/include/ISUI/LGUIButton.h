#pragma once
#include "LGUIelement.h"

struct _CreateButton : public _CreateElement
{
	char *Text;	// may be 0 for no text
//	char *Font;
//	unsigned int FontSize; // may be 0 to use default
//	unsigned int TextColor; // may be 0 to use default (use 0xFF000000 for solid black)


	_CreateFont Font;

	unsigned int BackgroundColor; // may be 0 to use default (0xFF000000 for solid black)

	bool DefaultTextures; // // You may create textures directly if you do not use default textures flag

	unsigned int Border;
	unsigned int BorderColor; // may be 0 to use default (use 0xFF000000 for solid black)

};

class LGUIButton :
	public LGUIElement
{
public:
	LGUI_API LGUIButton(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIButton(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Create(_CreateButton &CreateInfo, class XMLNode *pTemplate=0);

	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);

	LGUI_API bool OnLMouseUp(POINT2I &pt);
	LGUI_API bool OnLMouseDown(POINT2I &pt);

	// -- XML Properties --
	LGUIPreParse Text;

	LGUIFont *pFont;

	unsigned int BackgroundColor;
	unsigned int Border;
	unsigned int BorderColor;

	LGUITexture *pTexture;
	LGUITexture *pTexturePressed;
	LGUITexture *pTextureHover;
	// --------------------

	bool bDown;
};
