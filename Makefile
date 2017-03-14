all: primes primes-i steg-decode

primes: primes.o eratosthenes.o error.o
	gcc -O2 -std=c99 -Wall -pedantic primes.o eratosthenes.o error.o -o primes

primes.o: primes.c
	gcc -O2 -std=c99 -c -Wall -pedantic primes.c -o primes.o

eratosthenes.o: eratosthenes.c
	gcc -O2 -std=c99 -c -Wall -pedantic eratosthenes.c -o eratosthenes.o

error.o: error.c
	gcc -O2 -std=c99 -c -Wall -pedantic error.c -o error.o




primes-i: primes-i.o eratosthenes-i.o error.o
	gcc -O2 -std=c99 -Wall -pedantic -DUSE_INLINE primes.o eratosthenes.o error.o -o primes-i

primes-i.o: primes.c
	gcc -O2 -std=c99 -c -Wall -pedantic -DUSE_INLINE primes.c -o primes-i.o
	
eratosthenes-i.o: eratosthenes.c
	gcc -O2 -std=c99 -c -Wall -pedantic -DUSE_INLINE primes.c -o eratosthenes-i.o
	



steg-decode: steg-decode.o eratosthenes.o error.o ppm.o
	gcc -O2 -std=c99 -Wall -pedantic steg-decode.o eratosthenes.o error.o ppm.o -o steg-decode

steg-decode.o: steg-decode.c
	gcc -O2 -std=c99 -c -Wall -pedantic steg-decode.c -o steg-decode.o

ppm.o: ppm.c
	gcc -O2 -std=c99 -c -Wall -pedantic ppm.c -o ppm.o
	
	
	

clean:
	rm primes primes-i steg-decode *.o

run:
	time ./primes
	time ./primes-i
