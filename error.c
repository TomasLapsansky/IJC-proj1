/*
error.c
Riesenie IJC-DU1, priklad a), 14.3.2017
Autor: Tomas Lapsansky(xlapsa00), FIT VUT Brno
Prekladac: GCC 5.4.0
----------------------------------------------
Warning sprava a Error sprava pre zadanie projektu
*/

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
