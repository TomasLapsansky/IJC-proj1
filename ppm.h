/*
ppm.h
Riesenie IJC-DU1, priklad a), 14.3.2017
Autor: Tomas Lapsansky(xlapsa00), FIT VUT Brno
Prekladac: GCC 5.4.0
----------------------------------------------
Hlavickovy subor pre ppm.h
*/

#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ppm {
        unsigned xsize;
        unsigned ysize;
        char data[];    // RGB bajty, celkem 3*xsize*ysize
     };
     
struct ppm * ppm_read(const char * filename);

int ppm_write(struct ppm *p, const char * filename);
void ppm_free(struct ppm *p);
