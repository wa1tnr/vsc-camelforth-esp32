#warning tried to include common.h and I hate intellisense on wokwi btw

// NEED a wokwi-specific trigger
// have one somewhere ;)
// no you must maintain on your own atm:

// ex.
// https://wokwi.com/projects/361670038747009025

#ifndef __COMMON_H__
#define __COMMON_H__

// swap these two to use wokwi webbed, or wokwi vscode:
#undef NOT_WOKWI
#define NOT_WOKWI
// #define NOT_WOKWI

#ifdef NOT_WOKWI
#define HAVE_FOUND_NON_WOKWI_ENVIRONMENT
#warning this is not wokwi

#ifndef WOKWI_VSCODE

#define WOKWI_VSCODE

#endif
#endif
#ifndef NOT_WOKWI
#define HAVE_FOUND_WOKWI_ENVIRONMENT
#undef WOKWI_VSCODE
#warning this is very much wokwi
#endif
#endif // #ifndef __COMMON_H__

// end.
