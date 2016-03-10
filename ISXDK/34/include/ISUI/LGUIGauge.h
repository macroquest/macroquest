#pragma once

class LGUIGauge :
	public LGUIFrame
{
public:
	LGUI_API LGUIGauge(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIGauge(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);

	LGUI_API virtual void SetValue(float NewValue);

	// -- XML Properties --
	LGUITexture *pTopTexture;

	bool bVertical;

	float fRange;

	// --------------------

	bool Mod;
	class LGUIGaugeFiller* pFiller;
	float fValue;
};

class LGUIGaugeFiller:
	public LGUIElement
{
public:
	LGUIGaugeFiller(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	~LGUIGaugeFiller(void);
//	LGUI_API class LSTypeDefinition *GetLSType();

	void Render();
	bool FromXML(class XMLNode *pXML);
	bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate);

	bool IsTypeOf(char *TestFactory);
//	void Default();
	virtual void SetValue(float NewValue);
	void RecalculateSize(bool RecalculateChildren);

	// -- XML Properties --
	LGUITexture *pTexture;
	// --------------------

	float fRange;
	float fValue;
	bool bVertical;
	unsigned int Repeat;

	class LGUIGauge *pGauge;
};

class LGUIGaugeFactory : public LGUIElementFactory
{
public:
	LGUIGaugeFactory():LGUIElementFactory("gauge",LGUI_VERSION)
	{
	}

	~LGUIGaugeFactory()
	{
	}

	virtual LGUIElement *CreateUIElement(LGUIElement *pParent, const char *Name, class XMLNode *pXML, const char *Template = 0)
	{
		LGUIGauge *pElement = new LGUIGauge(Type,pParent,Name);
		
		if (!pElement->FromXML(pXML,g_UIManager.FindTemplate(Template)))
		{
			delete pElement;
			return 0;
		}
		Elements[pElement]=1;
		if (pElement->pFiller)
			return pElement->pFiller;
		return pElement;
	}
	virtual LGUIElement *CreateUIElement(LGUIElement *pParent, const char *Name)
	{
		LGUIGauge *pElement = new LGUIGauge(Type,pParent,Name);
		Elements[pElement]=1;
		return pElement;
	}

	virtual LSType *GetLSType();
};