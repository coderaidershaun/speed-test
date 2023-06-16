package main

import (
	"fmt"
	"time"
)

func sieveOfEratosthenes(limit int) []bool {
	primes := make([]bool, limit)
	for i := 2; i < limit; i++ {
		primes[i] = true
	}

	for p := 2; p*p <= limit; p++ {
		if primes[p] {
			for i := p * p; i < limit; i += p {
				primes[i] = false
			}
		}
	}
	return primes
}

func main() {
	limit := 100000000

	start := time.Now()
	sieveOfEratosthenes(limit)
	end := time.Now()

	elapsed := end.Sub(start)
	fmt.Printf("Go Speed: %s\n", elapsed)
}
