/*
primes.c
Riesenie IJC-DU1, priklad a), 14.3.2017
Autor: Tomas Lapsansky(xlapsa00), FIT VUT Brno
Prekladac: GCC 5.4.0
----------------------------------------------
Vytvorenie a nasledne naplnenie pola[N] prvocislami, prvocislo: index == 0
*/

#include "primes.h"
#include <stdio.h>

#define N 303000000

int main(void)
{
	ba_create(primes, N);
	
	Eratosthenes(primes);
	
	unsigned long last_primes[10];
	int count = 10;
	for(unsigned long i = N - 1; i > 1; i--)
	{
		if(ba_get_bit(primes, i) == 0)
		{
			last_primes[count - 1] = i;
			count--;
		}
		
		if(count == 0)
			break;
	}
	
	for(int i = 0; i < 10; i++)
	{
		printf("%lu\n", last_primes[i]);
	}
	
	return 0;
}
