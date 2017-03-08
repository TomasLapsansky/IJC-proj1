#include "primes.h"
#include <stdio.h>

#define N 2048000//303000000

int main(void)
{
	ba_create(primes, N);
	
	Eratosthenes(primes);
	
	int count = 10;
	for(unsigned long i = N - 1; i >= 0; i--)
	{
		if(ba_get_bit(primes, i) == 0)
		{
			printf("%lu\n", i);
			count--;
		}
		
		if(count == 0)
			break;
	}
}
