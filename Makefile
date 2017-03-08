all: primes.c
	gcc -O2 -std=c99 -Wall -pedantic primes.c eratosthenes.c -o primes
	gcc -O2 -std=c99 -Wall -pedantic -DUSE_INLINE primes.c eratosthenes.c -o primes-i

run:
	time ./primes
	time ./primes-i
