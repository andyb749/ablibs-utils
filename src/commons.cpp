#include "commons.h"

static char buf [128];

void strprintf(Stream& str, const char * fmt, ...)
{
  va_list args;
  va_start (args, fmt);
  vsprintf (buf, fmt, args);
  va_end (args);
  str.print(buf);
}
