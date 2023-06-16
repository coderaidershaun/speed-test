#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sieve_of_eratosthenes(size_t limit) {
    char* primes = (char*)calloc(limit, sizeof(char));

    for(size_t p = 2; p*p <= limit; p++) {
        if (primes[p] == 0) {
            for(size_t i = p*p; i < limit; i += p)
                primes[i] = 1;
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

    printf("C Speed: %.5f seconds\n", cpu_time_used);

    return 0;
}
