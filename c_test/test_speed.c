#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void sieve_of_eratosthenes(long unsigned int limit) {
    int i, j;

    int* primes = (int*)malloc(sizeof(int) * limit);
    memset(primes, 1, sizeof(int) * limit);

    for (i = 2; i * i < limit; i++) {
        if (primes[i] == 1) {
            for (j = i * i; j < limit; j += i)
                primes[j] = 0;
        }
    }

    free(primes);
}

int main() {
    long unsigned int limit = 100000000;

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sieve_of_eratosthenes(limit);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("C Memory: %.5f seconds\n", cpu_time_used);

    return 0;
}
