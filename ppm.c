#include "ppm.h"

struct ppm * ppm_read(const char * filename)
{
	FILE *fr = fopen(filename, "r");
	if(fr == NULL)
	{
		warning_msg("Chyba, subor sa nepodarilo otvorit.\n");
		return NULL;
	}
	
	unsigned xsize = 0;
	unsigned ysize = 0;
	
	if(fscanf(fr, "P6 %u %u 255 ", &xsize, &ysize) != 2)
	{
		warning_msg("Chyba nacitavania rozsahu suboru.\n");
		return NULL;
	}
	
	if(!(xsize > 0) && !(ysize > 0))
	{
		warning_msg("Chybny rozsah.\n");
		return NULL;
	}
	
	struct ppm *ppm = (struct ppm*)malloc(sizeof(struct ppm) + sizeof(char) * 3 * xsize * ysize);
	ppm->xsize = xsize;
	ppm->ysize = ysize;
	
	int index = 0;
	int scan = 0;
	while((scan = fgetc(fr)) != EOF)
	{
		ppm->data[index++] = (char)scan;
	}
	
	fclose(fr);
	
	return ppm;
}

int ppm_write(struct ppm *p, const char * filename)
{
	if(p == NULL)
	{
		warning_msg("Chyba vlozenej struktury.\n");
		return -1;
	}
	
	if(!(p->xsize > 0) && !(p->ysize > 0))
	{
		warning_msg("Chyba rozsahu vlozenej struktury.\n");
		return -1;
	}

	FILE *fw = fopen(filename, "w");
	if(fw == NULL)
	{
		warning_msg("Chyba nacitavania rozsahu suboru.\n");
		return -1;
	}
	
	fprintf(fw, "P6\n%u %u\n255\n", p->xsize, p->ysize);
	
	for(int i = 0; i < (3 * p->xsize * p->ysize); i++)
	{
		fputc(p->data[i], fw);
	}
	
	fclose(fw);
	return 0;
}

void ppm_free(struct ppm *p)
{
	free(p);
}
