#pragma once

class LGUIVariableSlider :
	public LGUISlider
{
public:
	LGUI_API LGUIVariableSlider(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIVariableSlider(void);
//	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);

//	LGUI_API bool OnLMouseUp(POINT2I &pt);
//	LGUI_API bool OnLMouseDown(POINT2I &pt);
//	LGUI_API bool OnMouseMove(POINT2I &pt);
	LGUI_API void SetValue(unsigned int NewValue);

	// -- XML Properties --
	LGUIDataSequence Data;
	const char *OriginalData;

	float Offset;
	float VariableRange;
	// --------------------

	bool InitialValue;
};
