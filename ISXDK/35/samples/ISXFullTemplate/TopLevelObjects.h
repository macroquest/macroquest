#ifndef TOPLEVELOBJECT
#define TOPLEVELOBJECT_SELF
#define TOPLEVELOBJECT(name,funcname) extern bool funcname(int argc, char *argv[], LSTYPEVAR &Ret);
#endif

// ----------------------------------------------------
// Top-Level Objects

TOPLEVELOBJECT("FullTemplate",TLO_FullTemplate);

















// ----------------------------------------------------
#ifdef TOPLEVELOBJECT_SELF
#undef TOPLEVELOBJECT_SELF
#undef TOPLEVELOBJECT
#endif