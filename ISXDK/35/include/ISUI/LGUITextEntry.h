#pragma once
#include "LGUIelement.h"

struct _CreateTextEntry : public _CreateElement
{
	char *Text;
	_CreateFont Font;
//	char *Font;

//	unsigned int FontHeight;
//	unsigned int TextColor;
	unsigned int BackgroundColor;
	unsigned int SelectionColor;
	unsigned int MaxLength;
	unsigned int BorderColor;
	unsigned int Border;
	unsigned int CaretOuterColor;
	unsigned int CaretInnerColor;
	char PasswordChar;
};

class LGUITextEntry :
	public LGUIElement
{
public:
	LGUI_API LGUITextEntry(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUITextEntry(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Create(_CreateTextEntry &CreateInfo, class XMLNode *pTemplate=0);
	LGUI_API void Render();
	LGUI_API void RenderCustom();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);

	LGUI_API virtual void SetText(char *NewValue);
	LGUI_API virtual void SetFontSize(unsigned int NewHeight);
	LGUI_API virtual bool OnKeyUp(unsigned int VKey);
	LGUI_API virtual bool OnKeyDown(unsigned int VKey);
	LGUI_API virtual bool OnLMouseDown(POINT2I &pt);
	LGUI_API virtual void InsertCharacter(char C);
	LGUI_API virtual void HandleBackspace();
	LGUI_API virtual void HandleDelete();
	LGUI_API virtual void HandleEnter();
	LGUI_API virtual void HandleEscape();

	LGUI_API virtual void PasteClipboard();

	LGUI_API unsigned int GetPositionFromPoint(POINT2I &pt);

	LGUI_API virtual void OnKeyboardExit(LGUIElement *pNewFocus);

	// -- XML PROPERTIES --
	char *Text;
	LGUIFont *pFont;
	unsigned int BackgroundColor;
	unsigned int SelectionColor;
	unsigned int MaxLength;
	unsigned int BorderColor;
	unsigned int Border;
	unsigned int CaretOuterColor;
	unsigned int CaretInnerColor;

	LGUITexture *pTexture;
	LGUITexture *pTextureFocused;
	LGUITexture *pTextureCaret;
	LGUITexture *pTextureCaretOverwrite;

	LGUIEmbeddedScript *pOnChange;

	char PasswordChar;
	//---------------------

//	unsigned int FontWidth;

	bool InsertMode;
	size_t Position;

	unsigned int LastVKey;
	size_t TextEnd;
	unsigned int LastVKeyTimer;
	size_t VisiblePos;
};
