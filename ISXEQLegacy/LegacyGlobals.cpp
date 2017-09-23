#include "ISXEQLegacy.h"

namespace MQ2Globals
{

    PDATAVAR pGlobalVariables=0;
    PDATAVAR pMacroVariables=0;

    PMACROBLOCK gMacroBlock = NULL;
    PMACROSTACK gMacroStack = NULL;
    map<string,PMACROBLOCK> gMacroSubLookupMap; 
    PEVENTQUEUE gEventQueue = NULL;
    PMACROBLOCK gEventFunc[NUM_EVENTS] = {NULL};

    Blech *pMQ2Blech=0;
    CHAR EventMsg[MAX_STRING]={0};
#ifdef USEBLECHEVENTS
    Blech *pEventBlech = 0;
#endif
    PEVENTLIST pEventList = NULL;

};
