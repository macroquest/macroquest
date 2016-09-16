#pragma once
#include "DataTypeList.h"

// custom data type declarations 

class FullTemplateType : public LSTypeDefinition
{
public:
	// All data members (retrieving data) should be listed in this enumeration
	enum FullTemplateTypeMembers
	{
		RetrieveData,
	};
	// All data methods (performing actions on or with the object) should be listed in this enumeration
	enum FullTemplateTypeMethods
	{
		PerformAction,
	};

	FullTemplateType() : LSType("fulltemplate")
	{
		// Use the TypeMember macro to activate each member, or use AddMember
		TypeMember(RetrieveData);

		// Use the TypeMethod macro to activate each member, or use AddMethod
		TypeMethod(PerformAction);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);
};
