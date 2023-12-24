public class Prime {

    static boolean isPrime(int number) {
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

    public static void main(String[] args) {
        int start = 1, end = 10000000;
        int primeCount = 0;

        long startTime = System.currentTimeMillis();

        System.out.println("Prime numbers in the range " + start + " to " + end + " are:");
        for (int i = start; i <= end; i++) {
            if (isPrime(i)) {
                primeCount++;
            }
        }

        long endTime = System.currentTimeMillis();

        double timeTaken = (endTime - startTime) / 1000.0;
        System.out.println("Time taken: " + timeTaken + " seconds");
        System.out.println("Total number of prime numbers in the range: " + primeCount);
    }
}
