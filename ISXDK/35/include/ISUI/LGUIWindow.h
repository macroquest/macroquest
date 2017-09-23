#pragma once
#include "LGUIElement.h"

#define ISW_CLOSE					1
#define ISW_MINIMIZE				2
//#define ISW_TITLEBAR				4
#define ISW_RESIZEWIDTH				8
#define ISW_RESIZEHEIGHT			16
#define ISW_RESIZE					(ISW_RESIZEWIDTH|ISW_RESIZEHEIGHT)
#define ISW_OFFSETTITLEBARWIDTH		32
#define ISW_OFFSETTITLEBARHEIGHT	64

#define SIZING_LEFT		1
#define SIZING_RIGHT	2
#define SIZING_TOP		4
#define SIZING_BOTTOM	8

struct _CreateWindow : public _CreateFrame
{
	unsigned int Flags;
	char *Title;
	char *ClickFocus;
};

class CWindowContextMenu : public CContextMenuHandler
{
public:
	LGUI_API CWindowContextMenu();
	LGUI_API ~CWindowContextMenu();

	LGUI_API virtual void OnCreate(unsigned int ParentItemID);
	LGUI_API virtual void OnClick(unsigned int ItemID);

	class LGUIWindow *pWindow;
};

class LGUIWindow : public LGUIFrame
{
public:
	LGUI_API LGUIWindow(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIWindow(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Create(_CreateWindow &CreateInfo, class XMLNode *pTemplate=0);

	LGUI_API bool IsTypeOf(char *TestFactory);
	LGUI_API void Render();
	LGUI_API void RenderChildren();
	LGUI_API void OnCreate();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API void RecalculateSize(bool RecalculateChildren);
	LGUI_API bool OnLMouseUp(POINT2I &pt);
	LGUI_API bool OnLMouseDown(POINT2I &pt);
	LGUI_API bool OnLMouseDoubleClick(POINT2I &pt);
	LGUI_API bool OnRMouseUp(POINT2I &pt);
	LGUI_API bool OnRMouseDown(POINT2I &pt);
	LGUI_API bool OnMouseMove(POINT2I &pt);
	LGUI_API bool OnMouseWheel(int Offset);
	LGUI_API void Show(bool bShow);
	LGUI_API void OnNotify(LGUIElement *pElement, unsigned int Notification, UINT_PTR Value);

	LGUI_API virtual void OnResize();

	LGUI_API LGUIElement *FindChild(const char *Name);

	LGUI_API void Minimize(bool bMinimize);


	LGUI_API void ResetWindowPosition();

	LGUI_API bool GetStoragePosition(int &StoreX, int &StoreY, unsigned int &StoreWidth, unsigned int &StoreHeight);

	LGUI_API void SetTitle(const char *title);

	// -- XML Properties --

	unsigned int Flags;

	char *Title;
	char *ClickFocus;
	unsigned int MinHeight;
	unsigned int MinWidth;

	LGUIEmbeddedScript *pOnMove;
	LGUIEmbeddedScript *pOnSize;
	LGUIEmbeddedScript *pOnReset;
	// ---

	unsigned int PreMinimizeHeight;
	unsigned int PreMinimizeWidth;
	int PreMinimizeTitleBarX;
	int PreMinimizeTitleBarY;
	bool bMinimized;
	bool bMoving;
	bool bLocked;
	unsigned int Sizing;
	POINT2I SizingOffset;
	POINT2I MovingOffset;

	class LGUIWindowClient *pClient;
	class LGUIFrame *pTitleBar;
	class LGUIText *pTitle;
	class LGUIButton *pMinimize;
	class LGUIButton *pMaximize;
	class LGUIButton *pClose;

	CWindowContextMenu ContextMenu;
//	CWindowSubmenu SubMenu;
};

class LGUIWindowClient : public LGUIFrame
{
public:
	LGUIWindowClient(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	~LGUIWindowClient(void);

	bool IsTypeOf(char *TestFactory);
	void OnCreate()
	{
		pWindow->OnCreate();
	}
	void OnNotify(LGUIElement *pElement, unsigned int Notification, unsigned int Value)
	{
		pWindow->OnNotify(pElement,Notification,Value);
	}

	class LGUIWindow *pWindow;
};

template<class T,LSTypeDefinition **Q=0>
class LGUIWindowFactory : public LGUIElementFactory
{
public:
	LGUIWindowFactory(const char *p_Type):LGUIElementFactory(p_Type,LGUI_VERSION)
	{
	}

	~LGUIWindowFactory()
	{
	}

	virtual LGUIElement *CreateUIElement(LGUIElement *pParent, const char *Name, class XMLNode *pXML, const char *Template = 0)
	{
		T *pElement = new T(Type,pParent,Name);
		
		if (!pElement->FromXML(pXML,g_UIManager.FindTemplate(Template)))
		{
			if (pParent)
				pParent->DeleteChild(pElement);
			else
				delete pElement;
			return 0;
		}
		Elements[pElement]=1;
		pElement->OnCreate();
		pElement->ExecuteOnLoad();
		return pElement->pClient;
	}
	virtual LGUIElement *CreateUIElement(LGUIElement *pParent, const char *Name)
	{
		T *pElement = new T(Type,pParent,Name);
		Elements[pElement]=1;
		return pElement;
	}

	virtual LSTypeDefinition *GetLSType() {if (!Q) return 0; return *Q;}
};
/**/
