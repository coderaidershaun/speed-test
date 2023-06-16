#include <iostream>
#include <vector>
#include <ctime>

void sieve_of_eratosthenes(size_t limit) {
    if (limit < 2) return;

    std::vector<bool> primes((limit - 1) / 2, true);
    size_t p_limit = (limit - 1) / 2;

    for (size_t p = 3; p * p <= limit; p += 2) {
        if (primes[p / 2]) {
            for (size_t i = p * p / 2; i < p_limit; i += p) {
                primes[i] = false;
            }
        }
    }
}

int main() {
    size_t limit = 1000000;
    std::clock_t start, end;
    double cpu_time_used;

    start = std::clock();
    sieve_of_eratosthenes(limit);
    end = std::clock();

    cpu_time_used = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "C++ Speed: " << cpu_time_used << " seconds" << std::endl;

    return 0;
}
