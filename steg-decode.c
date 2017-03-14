/*
steg-decode.c
Riesenie IJC-DU1, priklad a), 14.3.2017
Autor: Tomas Lapsansky(xlapsa00), FIT VUT Brno
Prekladac: GCC 5.4.0
----------------------------------------------
Dekodovanie tajnej spravy z obrazka .ppm na zaklade prvocisel
*/

#include "ppm.h"
#include "error.h"
#include "primes.h"

#include <limits.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		error_msg("Chybny pocet argumentov.\n");
		return -1;
	}
	
	struct ppm *p = ppm_read(argv[1]);
	
	ba_create(p_bits, 1000*1000*3);
	
	Eratosthenes(p_bits);
	
	char secret_msg = 0;
	int times = 0;
	
	for(int index = 2; index < ba_size(p_bits); index++)
	{
		if(ba_get_bit(p_bits, index) == 0)
		{
			int b = p->data[index] & 1;
			
			(b != 0) ? (secret_msg |= 1L << (times%CHAR_BIT)) : (secret_msg &= ~(1L << (times%CHAR_BIT)));
			times++;
			
			if((times % 8) == 0)
			{				
				printf("%c", secret_msg);
				
				if(secret_msg == '\0')
				{
					printf("\n");
					ppm_free(p);
					return 0;
				}
				
				if(isprint(secret_msg) == 0)
				{
					ppm_free(p);
					error_msg("Sprava obsahuje netlacitelny znak.\n");
				}
				
				secret_msg = 0;
			}
		}
	}
	
	return 0;
}
