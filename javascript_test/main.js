// node main.js

function sieveOfEratosthenes(limit) {
  let primes = new Array(limit).fill(true);

  for (let i = 2; i * i <= limit; i++) {
      if (primes[i]) {
          for (let j = i * i; j < limit; j += i) {
              primes[j] = false;
          }
      }
  }
}

function main() {
  let limit = 1000000;

  let start = new Date().getTime();
  sieveOfEratosthenes(limit);
  let end = new Date().getTime();

  let cpuTimeUsed = (end - start) / 1000.0;

  console.log("Time taken: " + cpuTimeUsed.toFixed(5) + " seconds");
}

main();
