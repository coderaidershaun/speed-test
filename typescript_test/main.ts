function sieveOfEratosthenes(limit: number): void {
  let primes: boolean[] = new Array(limit).fill(true);

  for (let i = 2; i * i <= limit; i++) {
    if (primes[i]) {
      for (let j = i * i; j < limit; j += i) {
        primes[j] = false;
      }
    }
  }
}

function main(): void {
  let limit: number = 1000000;

  let start: number = new Date().getTime();
  sieveOfEratosthenes(limit);
  let end: number = new Date().getTime();

  let cpuTimeUsed: number = (end - start) / 1000.0;

  console.log("Time taken: " + cpuTimeUsed.toFixed(5) + " seconds");
}

main();
