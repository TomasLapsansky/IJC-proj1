#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "error.h"

void warning_msg(const char *fmt, ...)
{
	fprintf(stderr, "CHYBA: ");
	
	va_list arg;
	va_start(arg, fmt);
	vfprintf(stderr, fmt, arg);
	va_end(arg);
}

void error_msg(const char *fmt, ...)
{
	fprintf(stderr, "CHYBA: ");
	
	va_list arg;
	va_start(arg, fmt);
	vfprintf(stderr, fmt, arg);
	va_end(arg);

	exit(1);
}
