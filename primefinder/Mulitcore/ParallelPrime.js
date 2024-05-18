const {
  Worker,
  isMainThread,
  parentPort,
  workerData,
} = require("worker_threads");
const os = require("os");

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

function countPrimesInRange(start, end) {
  let count = 0;
  for (let i = start; i <= end; i++) {
    if (isPrime(i)) {
      count++;
    }
  }
  return count;
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

if (isMainThread) {
  const start = 1;
  const end = 1000000000;
  const numThreads = os.cpus().length;
  console.log(`total ${formatNumber(end)}`);
  const chunkSize = Math.ceil((end - start + 1) / numThreads);

  const threads = [];

  let completedThreads = 0;
  let primeCount = 0;

  const threadCompleteHandler = (count) => {
    primeCount += count;
    completedThreads++;

    if (completedThreads === numThreads) {
      const endTime = new Date().getTime() / 1000;
      const timeTaken = endTime - startTime;
      console.log(`Time taken: ${timeTaken} seconds`);
      console.log(
        `Total number of prime numbers in the range: ${formatNumber(
          primeCount
        )}`
      );
    }
  };

  const startTime = new Date().getTime() / 1000;

  for (let i = 0; i < numThreads; i++) {
    const threadStart = start + i * chunkSize;
    const threadEnd = Math.min(threadStart + chunkSize - 1, end);

    const workerData = { start: threadStart, end: threadEnd };

    const worker = new Worker(__filename, { workerData });
    threads.push(worker);

    worker.on("message", threadCompleteHandler);
  }
} else {
  const { start, end } = workerData;
  const count = countPrimesInRange(start, end);
  parentPort.postMessage(count);
}
