import time
import numpy as np

def sieve_of_eratosthenes(limit):
    primes = np.ones(limit, dtype=bool)
    primes[:2] = 0
    for ind, val in enumerate(primes):
        if val is True:
            primes[ind*2::ind] = 0

def main():
    limit = 1_000_000

    start = time.time()
    sieve_of_eratosthenes(limit)
    end = time.time()

    cpu_time_used = end - start

    print(f"Time taken: {cpu_time_used:.5f} seconds")

if __name__ == "__main__":
    main()
