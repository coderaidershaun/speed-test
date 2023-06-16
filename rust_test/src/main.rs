// ts-node main.ts

use std::time::Instant;

fn sieve_of_eratosthenes(limit: usize) {
    let mut primes = vec![true; limit];
    let mut p = 2;
    while p * p <= limit {
        if primes[p] {
            let mut i = p * p;
            while i < limit {
                primes[i] = false;
                i += p;
            }
        }
        p += 1;
    }
}

fn main() {
    let limit: usize = 1000000;

    let start: Instant = Instant::now();
    sieve_of_eratosthenes(limit);
    let duration: std::time::Duration = start.elapsed();

    println!("RUST LANG: {:?}", duration);
}
