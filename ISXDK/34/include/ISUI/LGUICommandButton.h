#pragma once
#include "LGUIelement.h"

class LGUICommandButton :
	public LGUIButton
{
public:
	LGUI_API LGUICommandButton(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUICommandButton(void);
//	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);

	LGUI_API bool OnLMouseUp(POINT2I &pt);

	// -- XML Properties --

	char *Command;
	char *Console;
	// --------------------

};
