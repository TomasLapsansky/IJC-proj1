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
