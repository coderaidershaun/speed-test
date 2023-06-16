import time

def sieve_of_eratosthenes(limit):
    primes = [True] * limit

    for i in range(2, int(limit**0.5) + 1):
        if primes[i]:
            for j in range(i*i, limit, i):
                primes[j] = False

def main():
    limit = 100_000_000

    start = time.time()
    sieve_of_eratosthenes(limit)
    end = time.time()

    cpu_time_used = end - start

    print(f"Time taken: {cpu_time_used:.5f} seconds")

if __name__ == "__main__":
    main()
