#pragma once

enum ContextMenuType
{
	CMT_ITEM=1,
	CMT_SUBMENU=2,
	CMT_SEPARATOR=3,
};

class LGUIContextMenuNode
{
public:
	LGUIContextMenuNode(class LGUIContextMenu *p_pParent, ContextMenuType p_Type, unsigned int p_ID=0);

	LGUIContextMenuNode(class LGUIContextMenu *p_pParent, LGUIContextMenuNode *pInsertAfter, ContextMenuType p_Type, unsigned int ID=0);
	virtual ~LGUIContextMenuNode();

	RECT r;
	virtual size_t Render()=0;
	virtual void OnLMouseUp()=0;

	class LGUIContextMenu *pMenu;
	LGUIContextMenuNode *pPrev;
	LGUIContextMenuNode *pNext;

	ContextMenuType Type;
	unsigned int ID;
};

class LGUIContextMenuItem : public LGUIContextMenuNode
{
public:
	LGUIContextMenuItem(class LGUIContextMenu *p_pParent, char *p_Text, unsigned int p_ID=0);
	~LGUIContextMenuItem();

	size_t Render();
	void OnLMouseUp();

	char *Text;

	bool bChecked;
};


class LGUIContextMenuSubmenu : public LGUIContextMenuNode
{
public:
	LGUIContextMenuSubmenu(class LGUIContextMenu *p_pParent, char *Text, class CContextMenuHandler *p_pHandler, unsigned int p_ID=0);
	~LGUIContextMenuSubmenu();
	size_t Render();
	void OnLMouseUp();

	char *Text;
	class CContextMenuHandler *pHandler;
};

class LGUIContextMenuSeparator : public LGUIContextMenuNode
{
public:
	LGUIContextMenuSeparator(class LGUIContextMenu *p_pParent);
	~LGUIContextMenuSeparator();
	size_t Render();
	void OnLMouseUp()
	{
	}
};

class LGUIContextMenu :
	public LGUIFrame
{
public:
	LGUIContextMenu(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	~LGUIContextMenu(void);
	bool IsTypeOf(char *TestFactory);
//	class LSTypeDefinition *GetLSType();

	bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	bool Create(class CContextMenuHandler *p_pMenuHandler, class XMLNode *pTemplate=0);


	void Render();

	bool OnLMouseUp(POINT2I &pt);
	bool OnLMouseDown(POINT2I &pt);
	bool OnMouseMove(POINT2I &pt);

	unsigned int AddItem(char *Text, unsigned int ID=0);
	unsigned int AddSubmenu(char *Text, CContextMenuHandler *pHandler, unsigned int ID=0);
	unsigned int AddSeparator();
	bool GetItemCheck(unsigned int ID, bool &bChecked);
	void SetItemCheck(unsigned int ID, bool bChecked);

	void OnKeyboardExit(LGUIElement *pNewFocus);
	void OnLMouseDownOther(LGUIElement *pOther);

	// -- From XML --
	LGUIFont *pFont;
	unsigned int HighlightColor;

	LGUITexture *pItemTexture;
	LGUITexture *pSubmenuTexture;
	LGUITexture *pSeparatorTexture;
	LGUITexture *pHighlightItemTexture;
	LGUITexture *pHighlightSubmenuTexture;
	LGUITexture *pItemCheckTexture;


	// --------------------------------

	unsigned int ParentMenuID;
	unsigned int ChildMenuID;


	unsigned int NextID;
	LGUIContextMenuNode *pItems;
	unsigned int nItems;

	LGUIContextMenuNode *pMouseOver;
	class CContextMenuHandler *pMenuHandler;
};

class CContextMenuHandler
{
public:
	LGUI_API CContextMenuHandler()
	{
		pMenu=0;
		pTemplate=0;
		pChildMenu=0;
		pParentMenu=0;
	}
	LGUI_API virtual ~CContextMenuHandler()
	{
		DestroyMenu();
	}

	inline bool IsMenu()
	{
		return pMenu!=0;
	}
	inline void SetTemplate(class XMLNode *pNewTemplate)
	{
		pTemplate=pNewTemplate;
	}

	bool Create(CContextMenuHandler *p_pParentMenu, unsigned int ParentItemID, int X, int Y);
	LGUI_API bool Create(int X, int Y);
	LGUI_API unsigned int AddItem(char *Text, unsigned int ID=0);
	LGUI_API unsigned int AddSubMenu(char *Text, CContextMenuHandler *pHandler, unsigned int ID=0);
	LGUI_API unsigned int AddSeparator();
	LGUI_API bool GetItemCheck(unsigned int ID, bool &bChecked);
	LGUI_API void SetItemCheck(unsigned int ID, bool bChecked);

	LGUI_API virtual void OnCreate(unsigned int ParentItemID) {}
	virtual void OnClick(unsigned int ItemID)=0;

	LGUI_API void DestroyMenu(bool bParentsToo=false);
	
	LGUI_API virtual void OnMenuDestroyed()
	{
		pMenu=0;
	}

private:
	class XMLNode *pTemplate;
	class LGUIContextMenu *pMenu;

	class CContextMenuHandler *pChildMenu;
	class CContextMenuHandler *pParentMenu;
};