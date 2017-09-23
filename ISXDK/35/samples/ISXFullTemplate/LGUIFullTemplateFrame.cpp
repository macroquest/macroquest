#include "ISXFullTemplate.h"
#include "LGUIFullTemplateFrame.h"

LGUIFactory<LGUIFullTemplateFrame> FullTemplateFrameFactory("fulltemplateframe");

LGUIFullTemplateFrame::LGUIFullTemplateFrame(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name):LGUIFrame(p_Factory,p_pParent,p_Name)
{
	pText=0;
	Count=0;
}
LGUIFullTemplateFrame::~LGUIFullTemplateFrame(void)
{
}
bool LGUIFullTemplateFrame::IsTypeOf(char *TestFactory)
{
	return (!_stricmp(TestFactory,"fulltemplateframe")) || LGUIFrame::IsTypeOf(TestFactory);
}
bool LGUIFullTemplateFrame::FromXML(class XMLNode *pXML, class XMLNode *pTemplate)
{
	if (!pTemplate)
		pTemplate=g_UIManager.FindTemplate(XMLHelper::GetStringAttribute(pXML,"Template"));
	if (!pTemplate)
		pTemplate=g_UIManager.FindTemplate("fulltemplateframe");
	if (!LGUIFrame::FromXML(pXML,pTemplate))
		return false;

	// custom xml properties
	return true;
}

void LGUIFullTemplateFrame::OnCreate()
{
	// All children of this element are guaranteed to have been created now.
	pText = (LGUIText*)FindUsableChild("Output","text");
}

void LGUIFullTemplateFrame::Render()
{
	Count++;
	if (pText)
	{
		char Temp[256];
		sprintf_s(Temp,"This frame has been rendered %d times.",Count);
		pText->SetText(Temp);
	}

	LGUIFrame::Render();
}


