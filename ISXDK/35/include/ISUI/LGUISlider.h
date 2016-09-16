#pragma once
#include "LGUIelement.h"

struct _CreateSlider : public _CreateElement
{
	unsigned int Border;
	unsigned int Range;

	bool bVertical;

	bool DefaultTextures;
};

class LGUISlider :
	public LGUIElement
{
public:
	LGUI_API LGUISlider(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUISlider(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Create(_CreateSlider &CreateInfo, class XMLNode *pTemplate=0);

	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);

	LGUI_API bool OnLMouseUp(POINT2I &pt);
	LGUI_API bool OnLMouseDown(POINT2I &pt);
	LGUI_API bool OnMouseMove(POINT2I &pt);

	LGUI_API virtual void SetValue(unsigned int NewValue);
	LGUI_API virtual void SetPosition(unsigned int NewPosition);
	LGUI_API void RecalculateSize(bool RecalculateChildren);

	// -- XML Properties --
	LGUITexture *pTexture;
	LGUITexture *pHandleTexture;
	unsigned int Border;

	bool bVertical;

	unsigned int Range;

	LGUIEmbeddedScript *pOnChange;
	// --------------------

	unsigned int HandleWidth;
	unsigned int HandleHeight;
	unsigned int Value;
	unsigned int Position;
	bool bSliding;
};
