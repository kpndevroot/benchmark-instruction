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

function formatNumber(number) {
  if (number >= 1e9) {
    return (number / 1e9).toFixed(2) + " billion";
  } else if (number >= 1e6) {
    return (number / 1e6).toFixed(2) + " million";
  } else if (number >= 1e3) {
    return (number / 1e3).toFixed(2) + " thousand";
  } else {
    return number.toString();
  }
}

const start = 1;
const end = 100000000;
let primeCount = 0;

const startTime = new Date().getTime() / 1000;

console.log(`Prime numbers in the range ${start} to ${end} are:`);
console.log(`Total ${formatNumber(end)} `);
for (let i = start; i <= end; i++) {
  if (isPrime(i)) {
    primeCount++;
  }
}

const endTime = new Date().getTime() / 1000;

const timeTaken = endTime - startTime;
console.log(`Time taken: ${timeTaken} seconds`);
console.log(
  `Total number of prime numbers in the range: ${formatNumber(primeCount)}`
);
