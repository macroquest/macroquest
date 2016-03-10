#pragma once
#include "LGUI.h"


struct _UISettings
{
	unsigned int AutoTooltipTime;
	unsigned int DoubleClickTime;
	unsigned int TypematicRate;
	unsigned int TypematicDelay;
};

class LGUISkin
{
public:
	LGUISkin(const char *p_Name);
	~LGUISkin();

	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);

	LGUI_API void AddTemplate(const char *BaseTemplate, const char *SkinTemplate);
	LGUI_API void RemoveTemplate(const char *BaseTemplate);

	char *Name;
	map<utf8stringnocase,char *> Templates;
};

class MetadataStore
{
public:
	const char *Get(const char *key);
	bool Set(const char *key, const char *value);
	bool Unset(const char *key);

	map<utf8stringnocase,std::string> m_Metadata;
};

class CUIManager
{
public:
	CUIManager(void);
	~CUIManager(void);

	virtual void Initialize();
	virtual void Shutdown();

	virtual unsigned int GetVersion();
	virtual void DisableMouse();

	LGUI_API void Reset();
	LGUI_API bool LoadInterfaceXML(const char *Filename, bool Reload = false, LGUISkin *pSkin = 0);
	LGUI_API bool LoadInterfaceXML(const char *Filename, const char *Element, const char *NewName, bool Reload = false, LGUISkin *pSkin = 0);
	LGUI_API bool LoadInterfaceXML(LGUIElement *pParent, const char *Filename, bool Reload = false, LGUISkin *pSkin = 0);
	LGUI_API bool LoadInterfaceXML(LGUIElement *pParent, const char *Filename, const char *Element, const char *NewName, bool Reload = false, LGUISkin *pSkin = 0);
	LGUI_API bool UnloadInterfaceXML(const char *Filename);

	LGUI_API bool OnLMouseUp();
	LGUI_API bool OnLMouseDown();
	LGUI_API bool OnRMouseUp();
	LGUI_API bool OnRMouseDown();
	LGUI_API bool OnMouseMove(POINT2I &pt);
	LGUI_API bool OnMouseWheel(int Offset);
	LGUI_API bool OnKeyUp(unsigned int VKey);
	LGUI_API bool OnKeyDown(unsigned int VKey);

	LGUI_API void SetFocusElement(class LGUIElement *pElement);

	inline class LGUIElement *GetElementByID(unsigned int ID)
	{
		map<unsigned int,class LGUIElement *>::iterator i=AllElements.find(ID);
		if (i==AllElements.end())
			return 0;
		return i->second;
	}

	LGUI_API class LGUIElement *GetFocusElement();
	LGUI_API class LGUIElement *SetFocusElement();
	LGUI_API class LGUIElement *GetMouseOverElement();

	LGUI_API class LGUIElement *SetMouseOverElement();

	LGUI_API bool ShowElement(const char *Name, bool Show);
	LGUI_API bool ToggleElement(const char *Name);

	LGUI_API void Render();

	LGUI_API class LGUIElementFactory *FindFactory(const char *Type);
	LGUI_API class LGUIElement *FindElement(const char *Name);

	unsigned int LoadTexture(const char *Filename, unsigned int ColorKey);
	LGUI_API bool GetTextureSize(unsigned int ID, POINT2I &pt);
	void ReleaseTexture(unsigned int ID);

	unsigned int LoadFont(const char *Face, unsigned char Height, bool Fixed, bool Bold=0);
	void ReleaseFont(unsigned int ID);

//	LGUI_API unsigned int DrawText(const char *Text,int p_X, int p_Y,unsigned int Color,unsigned int FontHeight);

	unsigned int FocusID;
	unsigned int MouseOverID;
	unsigned int LockMouseOverIDLeft;
	unsigned int LockMouseOverIDRight;
	unsigned int MousePriorityID;

	unsigned int CurrentFontID;

	bool bShift;
	bool bAlt;
	bool bCtrl;

	char LeftMouse;
	char RightMouse;
	POINT2I MousePos;

	unsigned char KeyboardState[256];

	map<utf8stringnocase,class LGUIElement *> AllElementsByName;
	map<unsigned int,class LGUIElement *> AllElements;
	class LGUIElement *pScreen;
	map<utf8stringnocase,class LGUIElementFactory *> ElementFactories;
	unsigned int NextID;
	CSemaphore S;

	LGUI_API class XMLNode *AddTemplate(const char *Name, const char *XML);
	LGUI_API class XMLNode *AddTemplate(const char *Name, class XMLNode *pXML);
	LGUI_API void RemoveTemplate(const char *Name);
	LGUI_API class XMLNode *FindTemplate(const char *Name);
	LGUI_API void ClearTemplates();

	map<utf8stringnocase,class XMLNode *> Templates;
	map<utf8stringnocase,LGUISkin *> Skins;

	LGUI_API LGUISkin *NewSkin(const char *Name);
	LGUI_API LGUISkin *FindSkin(const char *Name);
	LGUI_API void RemoveSkin(const char *Name);

	LGUISkin *pCurrentSkin;

	char OuterTag[64];
	char CurrentXMLFile[512];

	bool bShutdown;
	unsigned int MouseOverTime;
	unsigned int LastActionTime;

	POINT2I LastClickPos;
	unsigned int LastLeftClickTime;
	unsigned int LastLeftClickID;
	unsigned int LastRightClickTime;
	unsigned int LastRightClickID;

	unsigned int RenderTime;

	unsigned int AutoTooltipShownID;

	_UISettings Settings;

	bool bZOrderChanged;

	map<unsigned int,unsigned char> KeyboardStateEx;
	unsigned int PersistentClass;

	void OnDeleteElement(class LGUIElement *pElement);

	const char *GetMetadata(unsigned int elementid, const char *key);
	bool SetMetadata(unsigned int elementid, const char *key, const char *value);
	bool UnsetMetadata(unsigned int elementid, const char *key);
	map<unsigned int,MetadataStore *> m_MetadataStores;

//protected:
	LGUI_API LGUIElement *LoadElement(class LGUIElement *pParent, const char *Type, const char *Name, class XMLNode *pXML, const char *Template = 0);
	LGUI_API LGUIElement *LoadElement(class LGUIElement *pParent, const char *Type, const char *Name);
};

extern LGUI_API CUIManager g_UIManager;
