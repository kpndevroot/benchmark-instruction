import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class ParallelPrime {

    static boolean isPrime(long number) {
        if (number <= 1) {
            return false;
        }

        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return false;
            }
        }

        return true;
    }

    private static String convertToBillion(long number) {
        if (number >= 1_000_000_000) {
            return (number / 1_000_000_000) + " Billion";
        } else if (number >= 1_000_000) {
            return (number / 1_000_000) + " Million";
        } else if (number >= 1_000) {
            return (number / 1_000) + " Thousand";
        } else {
            return String.valueOf(number);
        }
    }

    public static void main(String[] args) {
        long start = 1, end = 1000000000;
        int primeCount = 0;

        int availableProcessors = Runtime.getRuntime().availableProcessors();
        ExecutorService executorService = Executors.newFixedThreadPool(availableProcessors);

        long startTime = System.currentTimeMillis();
        String result = convertToBillion(end);

        System.out.println("Converted to Billion: " + result);
        System.out.println("Prime numbers in the range " + start + " to " + result + " are:");

        List<Future<Integer>> futures = new ArrayList<>();

        int batchSize = (int) ((end - start + 1) / availableProcessors);

        for (int i = 0; i < availableProcessors; i++) {
            long batchStart = start + i * batchSize;
            long batchEnd = (i == availableProcessors - 1) ? end : batchStart + batchSize - 1;

            Callable<Integer> primeCounter = () -> {
                int count = 0;
                for (long j = batchStart; j <= batchEnd; j++) {
                    if (isPrime(j)) {
                        count++;
                    }
                }
                return count;
            };

            futures.add(executorService.submit(primeCounter));
        }

        for (Future<Integer> future : futures) {
            try {
                primeCount += future.get();
            } catch (InterruptedException | ExecutionException e) {
                e.printStackTrace();
            }
        }

        executorService.shutdown();

        long endTime = System.currentTimeMillis();

        double timeTaken = (endTime - startTime) / 1000.0;
        System.out.println("Time taken: " + timeTaken + " seconds");
        System.out.println("Total number of prime numbers in the range: " + primeCount);
    }
}
