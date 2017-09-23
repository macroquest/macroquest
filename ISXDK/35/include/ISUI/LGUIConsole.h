#pragma once
#include "LGUIelement.h"

class LGUIConsoleSelector
{
public:
	LGUI_API LGUIConsoleSelector(class LGUIConsole *pConsole);
	LGUI_API LGUIConsoleSelector(const char *FullyQualifiedName);
	LGUI_API ~LGUIConsoleSelector();
protected:
	char PreviousConsole[1024];
};


class LGUIConsole :
	public LGUIElement
{
public:
	LGUI_API LGUIConsole(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIConsole(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API bool IsTypeOf(char *TestFactory);
	LGUI_API void SizeRecalculated(bool Changed);
	LGUI_API void OnNotify(LGUIElement *pElement, unsigned int Notification, UINT_PTR Value);

	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API void Render();
	LGUI_API bool OnMouseMove(POINT2I &pt);
	LGUI_API bool OnMouseWheel(int Offset);
	LGUI_API bool OnLMouseUp(POINT2I &pt);
	LGUI_API bool OnLMouseDown(POINT2I &pt);

	LGUI_API virtual void HandlePageUp();
	LGUI_API virtual void HandlePageDown();
	LGUI_API virtual void HandleUp();
	LGUI_API virtual void HandleDown();

	LGUI_API void SetFontSize(unsigned int NewHeight);
	LGUI_API void SnapToGrid(POINT2I &pt);
	LGUI_API void CopySelection();


	LGUI_API void SplitFixed(char *in, size_t MaxWidth);
	LGUI_API void Clear();
	LGUI_API void Printf(const char *szFormat, ...);
	LGUI_API void Print(const char *Text);


// -- XML PROPERTIES --
	LGUIFixedFont *pFont;

	unsigned int Border;
	unsigned int BorderColor;
	unsigned int ScrollbackColor;
	unsigned int BackgroundColor;

	unsigned int SelectionColor;

	LGUITexture *pTexture;
	LGUITexture *pTextureScrollback;

// ----------------------


	unsigned int BackBufferSize;
	char **BackBuffer;
	int LastLine;

	class LGUIScrollBar *pVerticalBar;

	int ScrollBack;
	int VisibleLines;

	bool bSelect;
	RECT Selection;

protected:
	LGUI_API virtual void AddLineInternal(char *Line);
};
