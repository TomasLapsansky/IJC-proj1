#include <math.h>
#include "primes.h"

void Eratosthenes(bit_array_t pole)
{
	unsigned long N = ba_size(pole); //<0, N> period
	
	ba_set_bit(pole, 0, 1); // 0 & 1 are not primes
	ba_set_bit(pole, 1, 1);
	
	for(unsigned long i = 2; i < N; i++)
	{
		if(ba_get_bit(pole, i) == 0)
		{
			for(unsigned long index = 2*i; index < N; index += i)
			{
				ba_set_bit(pole, index, 1);
			}
		}
	}
}
