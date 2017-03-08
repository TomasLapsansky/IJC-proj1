#include <math.h>
#include "primes.h"

void Eratosthenes(bit_array_t pole)
{
	int N = ba_size(pole); //<0, N> period
	
	ba_set_bit(pole, 0, 1); // 0 & 1 are not primes
	ba_set_bit(pole, 1, 1);
	
	for(int i = 2; i <= sqrt(N); i++)
	{
		if(ba_get_bit(pole, i) == 0)
		{
			for(int index = 2*i; index < N; index += i)
			{
				ba_set_bit(pole, index, 1);
			}
		}
	}
}
