function sieveOfEratosthenes(limit: number): void {
  let primes = new Uint8Array(limit).fill(1);

  for (let i = 2; i * i <= limit; i++) {
      if (primes[i]) {
          for (let j = i * i; j < limit; j += i) {
              primes[j] = 0;
          }
      }
  }
}

function main(): void {
  let limit = 1_000_000;

  let start = new Date().getTime();
  sieveOfEratosthenes(limit);
  let end = new Date().getTime();

  let cpuTimeUsed = (end - start) / 1000.0;

  console.log("Time taken: " + cpuTimeUsed.toFixed(5) + " seconds");
}

main();
