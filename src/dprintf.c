// file name: dprintf.c
// CreateTime: 2015.04.14
// Author    : rxp 
// introduce: print string of color

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "dprintf.h"

//-------------------------------------------------------------------------
// Function : dprintf_impl 
// Author   : rxp 
// time     : 2015-4-14 
// function : print console with color message;Detail with file name/line/
//			 function name and afferent content of string
// input key: filename: file name
//			 linenum : lime number
//			 funcname: function name
//			 enable  : if enable == 0, there is no any information
//			 fmt     : afferent string context
// return   : 
// modify   : 
//-------------------------------------------------------------------------
void dprintf_impl (const char *filename, size_t linenum, const char *funcname, int enable, const char *fmt, ...)
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
		fflush (stderr);
		fprintf (stderr, "\n");
	}
}

/*
other color:
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
