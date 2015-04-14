#ifndef	__DPRINTF_H__
#define	__DPRINTF_H__

#include <stdio.h>
#define DPRINTF(enable, ...) dprintf_impl (__FILE__, __LINE__, __FUNCTION__, enable, ## __VA_ARGS__)
void dprintf_impl (const char *filename, size_t linenum, const char *funcname, int enable, const char *fmt, ...);

#endif	// __DPRINTF_H__
