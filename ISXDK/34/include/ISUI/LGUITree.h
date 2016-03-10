#pragma once

class LGUITreeNode
{
public:
	LGUI_API LGUITreeNode(class LGUITree *p_pTree, LGUITreeNode *p_pParent, const char *p_Text, unsigned int p_Color);
	LGUI_API ~LGUITreeNode();

	bool Render(RECT &bounds, unsigned int height, int &Skip);
	bool RenderChildren(RECT &bounds, unsigned int height, int &Skip);

	void ClearChildren();

	void ToggleExpand();
	void Expand(bool bExpand);
	void Remove();
	void SetText(const char *text);

	LGUITreeNode *ParseNode(int argc, char *argv[]);

	LGUITreeNode *AddChild(int argc, char *argv[]);
	LGUITreeNode *InsertSiblingBefore(int argc, char *argv[]);
	LGUITreeNode *InsertSiblingAfter(int argc, char *argv[]);

	LGUITreeNode *m_pParent;
	LGUITreeNode *m_pChildren;
	LGUITreeNode *m_pPrevious;
	LGUITreeNode *m_pNext;

	LGUITreeNode *WalkTree(bool bIncludeCollapsed);

	class LGUITexture *m_pImage;
	class LGUITexture *m_pImageCollapsible;
	class LGUITexture *m_pImageCollapsed;
	const char *m_Text;
	bool m_bExpanded;

	unsigned int m_Color;

	class LGUITree *m_pTree;
	MetadataStore *m_pMetadataStore;

	const char *GetMetadata(const char *key);
	bool SetMetadata(const char *key, const char *value);
	bool UnsetMetadata(const char *key);
};

class LGUITree :
	public LGUIFrame
{
public:
	LGUI_API LGUITree(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUITree(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);

	LGUI_API void OnNotify(LGUIElement *pElement, unsigned int Notification, unsigned int Value);

	LGUI_API bool OnLMouseDown(POINT2I &pt);
	LGUI_API bool OnLMouseUp(POINT2I &pt);
	LGUI_API bool OnLMouseDoubleClick(POINT2I &pt);
	LGUI_API bool OnRMouseUp(POINT2I &pt);
	LGUI_API bool OnRMouseDown(POINT2I &pt);
	LGUI_API bool OnMouseMove(POINT2I &pt);
	LGUI_API bool OnMouseWheel(int Offset);

	LGUITreeNode *GetNodeByHandle(unsigned int handle);
	LGUITreeNode *GetNodeByQuery(const char *query);
	LGUITreeNode *GetNodeByPosition(int X, int Y, bool &bOnImage);
	void SetSelected(LGUITreeNode *node);

	LGUIFont *pFont;
	class LGUITexture *m_pImage;
	class LGUITexture *m_pImageCollapsible;
	class LGUITexture *m_pImageCollapsed;
	unsigned int VisiblePos;

	unsigned int IndentPerDepth;
	unsigned int ImageSize;
	unsigned int ImageBorder;
	unsigned int TextMargin;
	unsigned int TextColor;
	unsigned int ItemHeight;

	unsigned int SelectionBackgroundColor;
	unsigned int SelectionTextColor;
	LGUITreeNode *pRoot;

	LGUIScrollBar *pVerticalBar;
	LGUIEmbeddedScript *pOnSelect;
	LGUIEmbeddedScript *pOnDeSelect;

	LGUITreeNode *pSelectedNode;
	
	std::set<LGUITreeNode *> m_AllNodes;
};
