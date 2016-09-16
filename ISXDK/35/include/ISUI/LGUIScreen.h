#pragma once
#include "LGUIelement.h"

class LGUIScreen :
	public LGUIElement
{
public:
	LGUIScreen(void);
	~LGUIScreen(void);
	bool IsTypeOf(char *TestFactory);

	//void Render();
	void RecalculateSize(bool RecalculateChildren);
	void MoveZTop(bool bAncestorsToo);
	void MoveZUp();
	void MoveZDown();
	void MoveZBottom();

	bool OnLMouseDown(POINT2I &pt);
};
