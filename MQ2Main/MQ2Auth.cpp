#include "MQ2Main.h"
DWORD gh;
LRESULT CALLBACK proc( int nCode, WPARAM wParam, LPARAM lParam ){return ::CallNextHookEx( (HHOOK)gh, nCode, wParam, lParam );}
typedef DWORD	(__cdecl *FNCB)(DWORD,HINSTANCE,DWORD&);
#include "MQ2Auth1.h"