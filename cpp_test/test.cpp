// g++ -std=c++11 test.cpp -o test
#include <iostream>
#include <vector>
#include <ctime>

void sieve_of_eratosthenes(unsigned long int limit) {
    std::vector<bool> primes(limit, true);
    for (unsigned long int i = 2; i * i < limit; i++) {
        if (primes[i] == true) {
            for (unsigned long int j = i * i; j < limit; j += i)
                primes[j] = false;
        }
    }
}

int main() {
    unsigned long int limit = 1000000;
    std::clock_t start, end;
    double cpu_time_used;

    start = std::clock();
    sieve_of_eratosthenes(limit);
    end = std::clock();

    cpu_time_used = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "C++ Memory: " << cpu_time_used << " seconds" << std::endl;

    return 0;
}
