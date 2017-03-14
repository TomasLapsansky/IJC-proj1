CFLAGS = -O2 -std=c99 -Wall -pedantic

all: primes primes-i steg-decode

primes: primes.o eratosthenes.o error.o
	gcc $(CFLAGS) primes.o eratosthenes.o error.o -o primes

primes.o: primes.c primes.h bit_array.h
	gcc $(CFLAGS) -c primes.c -o primes.o

eratosthenes.o: eratosthenes.c primes.h bit_array.h
	gcc $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

error.o: error.c error.h error.h
	gcc $(CFLAGS) -c error.c -o error.o




primes-i: primes-i.o eratosthenes-i.o error.o
	gcc $(CFLAGS) -DUSE_INLINE primes-i.o eratosthenes-i.o error.o -o primes-i

primes-i.o: primes.c primes.h bit_array.h
	gcc $(CFLAGS) -c -DUSE_INLINE primes.c -o primes-i.o
	
eratosthenes-i.o: eratosthenes.c primes.h bit_array.h
	gcc $(CFLAGS) -c -DUSE_INLINE eratosthenes.c -o eratosthenes-i.o
	



steg-decode: steg-decode.o eratosthenes.o error.o ppm.o
	gcc $(CFLAGS) steg-decode.o eratosthenes.o error.o ppm.o -o steg-decode

steg-decode.o: steg-decode.c primes.h bit_array.h error.h ppm.h
	gcc $(CFLAGS) -c steg-decode.c -o steg-decode.o

ppm.o: ppm.c error.h ppm.h
	gcc $(CFLAGS) -c ppm.c -o ppm.o
	
	
	

clean:
	rm primes primes-i steg-decode *.o

run:
	time ./primes
	time ./primes-i
