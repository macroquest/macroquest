#pragma once

class LGUIFullTemplateFrame :
	public LGUIFrame
{
public:
	LGUIFullTemplateFrame(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	~LGUIFullTemplateFrame(void);
	bool IsTypeOf(char *TestFactory);
	bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	void OnCreate();
	void Render();

	LGUIText *pText;
	unsigned int Count;
};

extern LGUIFactory<LGUIFullTemplateFrame> FullTemplateFrameFactory;

