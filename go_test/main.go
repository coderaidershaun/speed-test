package main

import (
	"fmt"
	"time"
)

func sieveOfEratosthenes(limit int) []uint8 {
	size := (limit + 7) / 8 // Round up division
	primes := make([]uint8, size)

	for p := 2; p*p <= limit; p++ {
		if primes[p/8]&(1<<(p%8)) == 0 {
			for i := p * p; i < limit; i += p {
				primes[i/8] |= 1 << (i % 8)
			}
		}
	}
	return primes
}

func main() {
	limit := 1_000_000

	start := time.Now()
	sieveOfEratosthenes(limit)
	end := time.Now()

	elapsed := end.Sub(start)
	fmt.Printf("Go Speed: %s\n", elapsed)
}
