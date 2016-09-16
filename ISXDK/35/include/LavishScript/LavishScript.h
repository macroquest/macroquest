#define MAX_VARSTRING 4096
#include "LSType.h"
#include "LSSTLTypes.h"

typedef bool (__cdecl *fLSTopLevelObject)(int argc, char *argv[], LSTYPEVAR &);
typedef int (__cdecl *fLSCommand)(int argc, char *argv[]);
typedef void (__cdecl *fLSGenericEnumCallback)(const char *Name, void *pData);

