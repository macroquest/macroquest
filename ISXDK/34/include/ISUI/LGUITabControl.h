#pragma once

class CLGUITab
{
public:
	CLGUITab(class LGUITabControl *p_Control,const char *p_Name, unsigned int p_ID)
	{
		Name=strdup(p_Name);
		ID=p_ID;
		Order=0;
		pFrame=0;
		pTabControl=p_Control;
//		Length=strlen(Name);
	}
	~CLGUITab()
	{
		free(Name);
	}

	LGUI_API void Rename(const char *NewName);

	char *Name;
//	unsigned int Length;
	unsigned int FullWidth;

	unsigned int ID;
	unsigned int Order;

	LGUIFrame *pFrame;
	class LGUITabControl *pTabControl;
};

class LGUITabControl :
	public LGUIElement
{
public:
	LGUI_API LGUITabControl(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUITabControl(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);
	LGUI_API bool OnLMouseDown(POINT2I &pt);
	LGUI_API bool OnLMouseUp(POINT2I &pt);
	LGUI_API bool OnMouseMove(POINT2I &pt);
	LGUI_API void RecalculateSize(bool RecalculateChildren);
	LGUI_API void SizeRecalculated(bool Changed);
	LGUI_API void OnNotify(LGUIElement *pElement, unsigned int Notification, unsigned int Value);

	LGUI_API virtual unsigned int AddTab(const char *Text,XMLNode *pXML, const char *ChildName, const char *Template);
	LGUI_API virtual void RemoveTab(unsigned int ID);
	LGUI_API virtual unsigned int GetTabFromPoint(POINT2I &pt);
	LGUI_API virtual unsigned int GetOrderFromPoint(POINT2I &pt);

	LGUI_API void MoveTab(CLGUITab *pTab, unsigned int Order);
	LGUI_API virtual void SelectTab(unsigned int ID);
	LGUI_API virtual void ClearSelection();

	LGUI_API CLGUITab *GetTabFromName(const char *Name);


	// -- XML Properties  --
	LGUIFont *pFont;
	LGUITexture *pTabTexture;
	LGUITexture *pTabSelectedTexture;

	LGUITexture *pFrameTexture;
	unsigned int FrameBackgroundColor;
	unsigned int FrameBorder;
	unsigned int FrameBorderColor;

	unsigned int TabHeight;
	unsigned int TabBorder;
	unsigned int SelectedTextColor;
	bool bDraggable;

	LGUIEmbeddedScript *pOnSelect;
	// ----------------------

	LGUIButton *pLeft;
	LGUIButton *pRight;

	unsigned int VisiblePos;
	unsigned int Selection;
	CIndex<CLGUITab *> Tabs;
	CIndex<CLGUITab *> OrderedTabs;

	unsigned int nTabs;
	unsigned int DraggingID;

};

