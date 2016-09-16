#pragma once
#include "LGUIelement.h"

class LGUIHudElement :
	public LGUIElement
{
public:
	LGUIHudElement(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	~LGUIHudElement(void);
	bool IsTypeOf(char *TestFactory);
	class LSTypeDefinition *GetLSType();

	bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);

	bool OnLMouseUp(POINT2I &pt);
	bool OnLMouseDown(POINT2I &pt);
	bool OnMouseMove(POINT2I &pt);
	void Render();

	virtual void UpdateElement();
	virtual void SetText(char *NewValue);
	// -- From XML --
	//char *Text;
	LGUIPreParse PreParsed;
	char *Group;

	LGUIFont *pFont;

	unsigned int UpdateInterval;

	// --------------------------------

	char *CurrentValue;
	unsigned int CurrentInterval;
	bool bMoving;
	POINT2I MovingOffset;
};
