#include "ISXFullTemplate.h"
#include "ISXFullTemplateServices.h"

#define SERVICE(_name_,_callback_,_variable_) HISXSERVICE _variable_=0;
#include "Services.h"
#undef SERVICE

bool FullTemplateFooFunction(const char *Name, unsigned int Age,float Height)
{
	printf("Foo: %s. Age %d. Height: %fcm",Name,Age,Height);
	return true;
}

void __cdecl FullTemplateService(ISXInterface *pClient, unsigned int MSG, void *lpData)
{
	switch(MSG)
	{
	case ISXSERVICE_CLIENTADDED:
		// This message indicates that a new client has been added to the service
		// pClient is 0, because this message is a system message from Inner Space
		// lpData is an ISXInterface* that is the pointer to the new client
		{
			// use lpData as the actual type, not as void *.  We can make a new
			// variable to do this:
			ISXInterface *pNewClient=(ISXInterface *)lpData;

			printf("FullTemplateService client added: %X",pNewClient);
			// You may use the client pointer (pNewClient here) as an ID to track client-specific
			// information.  Some services such as the memory service do this to automatically
			// remove memory modifications made by an extension when that extension is unloaded.
		}
		break;
	case ISXSERVICE_CLIENTREMOVED:
		// This message indicates that a client has been removed from the service
		// pClient is 0, because this message is a system message from Inner Space
		// lpData is an ISXInterface* that is the pointer to the removed client
		{
			// use lpData as the actual type, not as void *.  We can make a new
			// variable to do this:
			ISXInterface *pRemovedClient=(ISXInterface *)lpData;

			printf("FullTemplateService client removed: %X",pRemovedClient);
		}
		break;
	case FullTemplate_FOO:
		// This is a custom service request defined in ISXFullTemplateServices.h
		// pClient is a valid pointer to the client that sent this request
		// lpData is a FullTemplateRequest_Foo* as sent by the client
		{
			FullTemplateRequest_Foo *pFoo=(FullTemplateRequest_Foo*)lpData;

			/*
			 * As described in ISXFullTemplateServices.h, pFoo is simply a remote call
			 * to FullTemplateFooFunction, and has all of the parameters and the outgoing
			 * return value ready to go.
			 */
			pFoo->Success=FullTemplateFooFunction(pFoo->Name,pFoo->Age,pFoo->Height);

			/*
			 * That's it!  In many cases, the functionality provided by the service will
			 * be something that should be per-client to automatically handle cleanup.
			 * In such cases, it would be prudent to pass the pClient to the function call
			 * for proper handling.
			 */
		}
		break;
	}
}


/*
 * How to broadcast an outgoing service message (called a notification):
 	FullTemplateNotification_Bar Bar;
	Bar.Text="Some text to pass as part of the notification";
	pFoo->Success=pISInterface->ServiceBroadcast(pExtension,hFullTemplateService,FullTemplate_BAR,&Bar);
 */