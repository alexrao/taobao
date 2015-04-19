#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "dprintf.h"

void dprintf_impl (const char *filename, int linenum, const char *funcname, int enable, const char *fmt, ...)
{
	//return;
	if (enable == 0)
		return;
	else
	{
		va_list ap;
		
		if (enable == 1)	// light_purple
			fprintf (stderr, "\033[1;35m[%s] %d (%s): ", filename, linenum, funcname);
		else if (enable == 2)	// red
			fprintf (stderr, "\033[0;31m[%s] %d (%s): ", filename, linenum, funcname);
		else if (enable == 3)	// cyan
			fprintf (stderr, "\033[0;36m[%s] %d (%s): ", filename, linenum, funcname);
		else if (enable == 4)	// yellow
		{
			fprintf (stderr, "\033[1;33m[%s] %d (%s): ", filename, linenum, funcname);
		}
		va_start (ap, fmt);
		vfprintf (stderr, fmt, ap);
		va_end (ap);
		fprintf (stderr, "\033[0m");	// none
		fprintf (stderr, "\n");
	}
}

/*
ÑÕÉ«ÈçÏÂ:
none="\033[0m"
black="\033[0;30m"
dark_gray="\033[1;30m"
blue="\033[0;34m"
light_blue="\033[1;34m"
green="\033[0;32m"
light_green="\033[1;32m"
cyan="\033[0;36m"
light_cyan="\033[1;36m"
red="\033[0;31m"
light_red="\033[1;31m"
purple="\033[0;35m"
light_purple="\033[1;35m"
brown="\033[0;33m"
yellow="\033[1;33m"
light_gray="\033[0;37m"
white="\033[1;37m"
*/
