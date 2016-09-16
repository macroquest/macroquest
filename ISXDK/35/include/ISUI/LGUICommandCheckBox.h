#pragma once
#include "LGUIelement.h"

class LGUICommandCheckBox :
	public LGUICheckBox
{
public:
	LGUI_API LGUICommandCheckBox(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUICommandCheckBox(void);
//	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);

	LGUI_API bool OnLMouseUp(POINT2I &pt);
	LGUI_API void Render();

	// -- XML Properties --
	LGUIPreParse Data;

	char *Command;
	char *CommandChecked;
	char *Console;

	// --------------------

};