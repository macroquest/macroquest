#ifndef ISXEQ
#include "MQ2Main.h"

DWORD gh;
LRESULT CALLBACK proc( int nCode, WPARAM wParam, LPARAM lParam ){return ::CallNextHookEx( (HHOOK)gh, nCode, wParam, lParam );}
typedef DWORD    (__cdecl *FNCB)(DWORD,HINSTANCE,DWORD&);
#undef MQ2AUTH
#define    MQ2AUTH(z) VOID z(DWORD x){FNCB f=(FNCB)x;f((DWORD)proc,ghInstance,gh);}
#include "MQ2Auth0.h"

#endif
