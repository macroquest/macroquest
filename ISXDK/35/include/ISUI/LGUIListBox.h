#pragma once

enum eListBoxSort
{
	LBSORT_NONE=0,
	LBSORT_USER=1,
	LBSORT_TEXT=2,
	LBSORT_VALUE=3,
	LBSORT_CUSTOM=4,
	LBSORT_TEXTREVERSE=5,
	LBSORT_VALUEREVERSE=6,
};


class ListBoxItem
{
public:
	ListBoxItem(class LGUIListBox *p_pListBox, const char *p_Text, unsigned int p_Color, const char *p_Value, unsigned int p_ID)
	{
		pListBox=p_pListBox;
		Text=strdup(p_Text);
		Color=p_Color;
		if (p_Value)
			Value=p_Value;
		ID=p_ID;

		Order=0;
	}

	~ListBoxItem()
	{
		free(Text);
		Text="Error";
	}

	unsigned int ID;
	char *Text;
	unsigned int Color;
	std::string Value;

	unsigned int Order;

	class LGUIListBox *pListBox;
};

struct _CreateListBox : public _CreateElement
{
//	unsigned int FontSize;
//	unsigned int TextColor;
	_CreateFont Font;
	unsigned int BackgroundColor;
	unsigned int Border;
	unsigned int BorderColor;

	unsigned int SelectionColor;

	eListBoxSort SortType;

	bool bSelectMultiple;

	char *ScrollBarTemplate;
};

class LGUIListBox :
	public LGUIElement
{
public:
	LGUI_API LGUIListBox(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIListBox(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Create(_CreateListBox &CreateInfo, class XMLNode *pTemplate=0);
	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);
	LGUI_API void RecalculateSize(bool RecalculateChildren);
	LGUI_API void OnNotify(LGUIElement *pElement, unsigned int Notification, UINT_PTR Value);

	LGUI_API bool OnLMouseDown(POINT2I &pt);
	LGUI_API bool OnLMouseUp(POINT2I &pt);
	LGUI_API bool OnLMouseDoubleClick(POINT2I &pt);
	LGUI_API bool OnMouseMove(POINT2I &pt);
	LGUI_API bool OnMouseWheel(int Offset);

	LGUI_API virtual void DeselectItem(unsigned int ID);
	LGUI_API virtual void SelectItem(unsigned int ID);
	LGUI_API virtual void ItemToggleSelect(unsigned int ID);
	LGUI_API virtual void ClearSelection();
	LGUI_API virtual unsigned int AddItem(const char *Text, const char *Value, unsigned int Color=0);
	LGUI_API virtual void RemoveItem(unsigned int ID);
	LGUI_API virtual void ClearItems();
	LGUI_API virtual bool GetItemValue(unsigned int ID, unsigned int &Value);

	LGUI_API virtual void SetItemText(unsigned int ID, const char *Text);
	LGUI_API virtual void SetItemColor(unsigned int ID, unsigned int Color);

	LGUI_API virtual unsigned int FindItemByText(const char *Text, unsigned int BeginInclusive=1);
	LGUI_API virtual unsigned int FindItemByValue(const char *Value, unsigned int BeginInclusive=1);

	LGUI_API virtual unsigned int GetItemFromPoint(POINT2I &pt);
	LGUI_API virtual unsigned int GetOrderFromPoint(POINT2I &pt);

	LGUI_API virtual void ApplySort();

	LGUI_API ListBoxItem *RetrieveItem(unsigned int ID);

	void Sort(int (__cdecl* customCompare)(const void *,const void *));

	// -- XML Properties --
	LGUIFont *pFont;
	unsigned int BackgroundColor;
	unsigned int Border;
	unsigned int BorderColor;

	unsigned int SelectionColor;

	eListBoxSort SortType;

	bool bSelectMultiple;

	LGUITexture *pTexture;

	LGUIEmbeddedScript *pOnSelect;
	LGUIEmbeddedScript *pOnDeSelect;

	// --------------------

	unsigned int TextColor;

	LGUIScrollBar *pVerticalBar;

	bool bAutoSort;

	int (__cdecl* fCustomCompare)(const void *,const void *);

	unsigned int VisiblePos;
	set<ListBoxItem *> Selection;

	CIndex<ListBoxItem *> Items;
	CIndex<ListBoxItem *> OrderedItems;
	unsigned int nItems;

	unsigned int DraggingID;
	bool Reordered;
};
