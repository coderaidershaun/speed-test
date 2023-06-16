use std::time::Instant;

fn sieve_of_eratosthenes(limit: usize) {
    let mut primes = vec![0u8; (limit + 7) / 8];

    for p in 2.. {
        if p * p > limit {
            break;
        }
        if primes[p / 8] & (1 << (p % 8)) == 0 {
            let mut i = p * p;
            while i < limit {
                primes[i / 8] |= 1 << (i % 8);
                i += p;
            }
        }
    }
}

fn main() {
    let limit: usize = 1_000_000;

    let start: Instant = Instant::now();
    sieve_of_eratosthenes(limit);
    let duration: std::time::Duration = start.elapsed();

    println!("RUST LANG: {:?}", duration);
}
