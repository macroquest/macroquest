#pragma once

class LGUIVariableGauge :
	public LGUIGauge
{
public:
	LGUI_API LGUIVariableGauge(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIVariableGauge(void);
//	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);

	// -- XML Properties --
	LGUIDataSequence Data;
	float Offset;
	// --------------------

};


class LGUIVariableGaugeFactory : public LGUIElementFactory
{
public:
	LGUIVariableGaugeFactory():LGUIElementFactory("variablegauge",LGUI_VERSION)
	{
	}

	~LGUIVariableGaugeFactory()
	{
	}

	virtual LGUIElement *CreateUIElement(LGUIElement *pParent, const char *Name, class XMLNode *pXML, const char *Template = 0)
	{
		LGUIVariableGauge *pElement = new LGUIVariableGauge(Type,pParent,Name);
		
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
		LGUIVariableGauge *pElement = new LGUIVariableGauge(Type,pParent,Name);
		Elements[pElement]=1;	
		return pElement;
	}

};