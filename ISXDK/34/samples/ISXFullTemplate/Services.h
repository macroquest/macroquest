#ifndef SERVICE
#define SERVICE_SELF
#define SERVICE(_name_,_callback_,_variable_) extern HISXSERVICE _variable_;extern void __cdecl _callback_(ISXInterface *pClient, unsigned int MSG, void *lpData);
#endif
// ----------------------------------------------------
// services

SERVICE("FullTemplate Service",FullTemplateService,hFullTemplateService);












// ----------------------------------------------------
#ifdef SERVICE_SELF
#undef SERVICE_SELF
#undef SERVICE
#endif