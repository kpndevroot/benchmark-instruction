function isPrime(number) {
  if (number <= 1) {
    return false;
  }

  for (let i = 2; i * i <= number; i++) {
    if (number % i === 0) {
      return false;
    }
  }

  return true;
}

const start = 1;
const end = 100000000;
let primeCount = 0;

const startTime = new Date().getTime() / 1000;

console.log(`Prime numbers in the range ${start} to ${end} are:`);
for (let i = start; i <= end; i++) {
  if (isPrime(i)) {
    primeCount++;
  }
}

const endTime = new Date().getTime() / 1000;

const timeTaken = endTime - startTime;
console.log(`Time taken: ${timeTaken} seconds`);
console.log(`Total number of prime numbers in the range: ${primeCount}`);
