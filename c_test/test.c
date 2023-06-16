#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ISBITSET(x, i) ((x[i >> 3] & (1 << (i & 7))) != 0)
#define SETBIT(x, i) (x[i >> 3] |= (1 << (i & 7)))

void sieve_of_eratosthenes(size_t limit) {
    size_t i, p;
    size_t size = (limit + 7) / 8; // Round up division

    char* primes = (char*) calloc(size, sizeof(char));

    for(p = 2; p * p <= limit; p++) {
        if (!ISBITSET(primes, p)) {
            for(i = p * p; i < limit; i += p)
                SETBIT(primes, i);
        }
    }

    free(primes);
}

int main() {
    size_t limit = 1000000;
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sieve_of_eratosthenes(limit);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("C Speed: %f seconds\n", cpu_time_used);

    return 0;
}
