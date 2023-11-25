#ifndef __COMMONS_H__
#define __COMMONS_H__

#include <Arduino.h>

// Macro to find the count of items in an array
#ifndef MAXITEMS
#define MAXITEMS(x) sizeof(x)/sizeof(x[0])
#endif

extern void strprintf(Stream& str, const char * fmt, ...);

#endif