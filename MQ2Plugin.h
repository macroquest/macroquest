#include "MQ2Main/MQ2Main.h"
#include "MQ2Main/MQ2Globals.h"

#pragma comment(lib, "MQ2Main")

#ifdef EQLIB_EXPORTS
#pragma message("EQLIB_EXPORTS")
#else
#pragma message("EQLIB_IMPORTS")
#endif

#define PLUGIN_API extern "C" __declspec(dllexport)