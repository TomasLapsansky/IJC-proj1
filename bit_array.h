#include <limits.h>
#include <stdio.h>

typedef unsigned long* bit_array_t;

#define SIZE (sizeof(unsigned long)*CHAR_BIT)

#define ba_create(jmeno_pole, velikost) \
	unsigned long jmeno_pole[velikost/SIZE + 2] = {velikost}
	
#define BA_SET_BIT(p, i, b) \
	((b != 0) ? (p[i/SIZE + 1] |= 1L << (i%SIZE)) : (p[i/SIZE + 1] &= ~(1L << (i%SIZE))))

#define BA_GET_BIT(p, i) \
	((p[i/SIZE + 1] >> (i%SIZE)) & 1L)

#ifndef USE_INLINE
	
	#define ba_size(jmeno_pole) \
		jmeno_pole[0]
	
	#define ba_set_bit(jmeno_pole, index, vyraz) \
		((index + 1) > ba_size(jmeno_pole)) ? \
			printf("Error\n") : \
			BA_SET_BIT(jmeno_pole, index, vyraz)
		
	
	#define ba_get_bit(jmeno_pole, index) \
		((index + 1) > ba_size(jmeno_pole)) ? \
			printf("Error\n") : \
			BA_GET_BIT(jmeno_pole, index)
		
	
#else
	
	inline unsigned long ba_size(unsigned long jmeno_pole[])
	{
		return jmeno_pole[0];
	}
	
	inline void ba_set_bit(unsigned long jmeno_pole[], unsigned long index, int vyraz)
	{
		if((index + 1) > ba_size(jmeno_pole))
		{
			printf("Error\n");
		} else
		{
			BA_SET_BIT(jmeno_pole, index, vyraz);
		}
	}
	
	inline unsigned long ba_get_bit(unsigned long jmeno_pole[], unsigned long index)
	{
		if((index + 1) > ba_size(jmeno_pole))
		{
			printf("Error\n");
		} else
		{
			return BA_GET_BIT(jmeno_pole, index);
		}
		
		return -1;
	}
	
#endif
