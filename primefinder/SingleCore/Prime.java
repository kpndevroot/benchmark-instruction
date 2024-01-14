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

    static String formatNumber(int number) {
        if (number >= 1e9) {
            return String.format("%.2f billion", (double) number / 1e9);
        } else if (number >= 1e6) {
            return String.format("%.2f million", (double) number / 1e6);
        } else if (number >= 1e3) {
            return String.format("%.2f thousand", (double) number / 1e3);
        } else {
            return String.valueOf(number);
        }
    }

    public static void main(String[] args) {
        int start = 1, end = 100000000;
        int primeCount = 0;

        // Print the original 'end' number
        String formattedEnd = formatNumber(end);
        System.out.println("Total : " + formattedEnd);

        long startTime = System.currentTimeMillis();

        System.out.println("Prime numbers in the range " + start + " to " + end + " are:");
        for (int i = start; i <= end; i++) {
            if (isPrime(i)) {
                primeCount++;
            }
        }

        long endTime = System.currentTimeMillis();

        // Calculate the time taken
        double timeTaken = (endTime - startTime) / 1000.0;

        // Print the results
        formattedEnd = formatNumber(end);
        System.out.println("Total Number: " + formattedEnd);
        System.out.println("Time taken: " + timeTaken + " seconds");
        System.out.println("Total number of prime numbers in the range: " + primeCount);
    }
}
