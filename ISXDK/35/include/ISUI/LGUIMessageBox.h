#pragma once

enum eMessageBoxType
{
	MSGBOX_OK=1,
	MSGBOX_OKCANCEL=2,
	MSGBOX_YESNO=3,
};

class LGUIMessageBox : public LGUIWindow
{
public:
	LGUI_API LGUIMessageBox(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIMessageBox(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Create(char *p_Title, char *p_Text, eMessageBoxType p_Type, class XMLNode *pTemplate=0);

	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);
	LGUI_API void OnNotify(LGUIElement *pElement, unsigned int Notification, UINT_PTR Value);


	// Text
	LGUIFont *pFont;

	eMessageBoxType MessageBoxType;

	// --------------------

	LGUIButton *pOK;
	LGUIButton *pCancel;
	LGUIButton *pYes;
	LGUIButton *pNo;
};
