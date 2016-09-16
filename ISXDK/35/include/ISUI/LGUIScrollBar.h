#pragma once

struct _CreateScrollBar : public _CreateElement
{
	unsigned int Range;
	bool bVertical;
	bool DefaultTextures;
};

class LGUIScrollBar :
	public LGUIElement
{
public:
	LGUI_API LGUIScrollBar(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIScrollBar(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Create(_CreateScrollBar &CreateInfo, class XMLNode *pTemplate=0);

	LGUI_API void SizeRecalculated(bool Changed);
//	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);
	LGUI_API void OnNotify(LGUIElement *pElement, unsigned int Notification, UINT_PTR Value);

//	LGUI_API void RecalculateSize();

	LGUI_API virtual void SetRange(unsigned int NewRange);
	LGUI_API virtual void SetValue(unsigned int NewValue);
	LGUI_API virtual void RaiseValue(unsigned int Offset);
	LGUI_API virtual void LowerValue(unsigned int Offset);
	LGUI_API virtual unsigned int GetValue();


	unsigned int Range;
	bool bVertical;

	LGUIButton *pUp;
	LGUIButton *pDown;
	LGUISlider *pSlider;
};