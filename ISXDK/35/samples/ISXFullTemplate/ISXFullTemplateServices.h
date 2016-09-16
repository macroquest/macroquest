#pragma once
/**********************************************************************
 ISXFullTemplateServices.h is a redistributable file that can be used 
 by other extensions to access the services provided by ISXFullTemplate.
 It should contain all information for any message that can be sent to
 clients from the master (individually or broadcast), or to the master 
 from clients.

 All "in/out" information is relative to the client.  If it says "in"
 it means the client feeds information in.  If it says "out" it means
 the client pulls information out.
 **********************************************************************/

// ----- "FullTemplate Service" messages ------------------------------
// Note: ISXSERVICE_MSG defines the starting point for service-specific
//       message numbers.  Numbers below ISXSERVICE_MSG are reserved for
//       future system use.
//       These message numbers are PER SERVICE, so you can and should
//       reuse numbers for different services

/* in  (requests) */
#define FullTemplate_FOO						(ISXSERVICE_MSG+1)
// add all requests

/* out (notifications) */
#define FullTemplate_BAR						(ISXSERVICE_MSG+2)
// add all notifications

// ----- "FullTemplate Service" request structures ---------------------
// These structures are sent as the "lpData" in requests or notifications.

/*
 * All structures are essentially used to build a function call.  Our first
 * example handles a call to this function:
   bool FullTemplateFooFunction(const char *Name, unsigned int Age,float Height);
 * This function has 3 parameters, and 1 return value.  The structure used will
 * reflect exactly this.
 *
 * Note that because services are all executed in-process, data does not need to
 * be serialized, as it would with using network sockets and such -- in other words,
 * it is safe to pass original pointers.
 */

// FullTemplate_FOO
struct FullTemplateRequest_Foo
{
	/* in  */ const char *Name;  // Parameter 1
	/* in  */ unsigned int Age;  // Parameter 2
	/* int */ float Height;      // Parameter 3

	/* out */ bool Success;      // Return value
};

// ----- "FullTemplate Service" Helper Functions -----------------------
// Put any helper functions for REQUESTS here.  Notifications (in contrast) are done by
// the service master, and do not need redistributable helper functions.

/*
 * This function sets up the actual service request.  It follows the same form as the function we
 * are calling, but takes additional parameters to set up the remote service request.  This will
 * be used by our EzFoo macro, which will hide the service portion from developers wishing to use
 * the remote function.  
 */
static inline bool FullTemplateFoo(ISXInterface *pClient, ISInterface *pISInterface, HISXSERVICE hFullTemplateService, const char *Name, unsigned int Age, float Height)
{
	// set up lpData
	FullTemplateRequest_Foo RemoteFunctionCall;
	RemoteFunctionCall.Name=Name;
	RemoteFunctionCall.Age=Age;
	RemoteFunctionCall.Height=Height;
	RemoteFunctionCall.Success=false;
	// return true if a) the service request was sent correctly and b) the service set Success to true, indicating
	// that the Foo operation was successfully completed
	return pISInterface->ServiceRequest(pClient,hFullTemplateService,FullTemplate_FOO,&RemoteFunctionCall) && RemoteFunctionCall.Success;
}
// Most extensions will opt to use the default naming conventions, with a global pISInterface and pExtension,
// and your service handle name.  This means you can make an "easy" macro to call FullTemplateFoo for them,
// and they can just use EzFoo as if they were calling the actual remote function:
#define EzFoo(_name_,_age_,_height_) FullTemplateFoo(pExtension,pISInterface,hFullTemplateService,_name_,_age_,_height_)
// Note that EzFoo is now used exactly the same as bool FullTemplateFooFunction(const char *Name, unsigned int Age,float Height)

// ----- "FullTemplate Service" notification structures ---------------------
// The following structures are for use in FullTemplate Service notification handlers
// FullTemplate_BAR
// NOTE: For structures that have only one data item, we dont really need a structure.  But to make things
//       easy to use and understand, it's perfectly fine and compiles to the same machine code anyway.
struct FullTemplateNotification_Bar
{
	/* out */ const char *Text;
};

