#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool is_prime(int number) {
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

int main() {
    int start=1, end=100000000;
    int prime_count = 0;


    // Record the starting time
    clock_t start_time = clock();

    printf("Prime numbers in the range %d to %d are:\n", start, end);

    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
         prime_count++;
        }
    }

    // Record the ending time
    clock_t end_time = clock();

    // Calculate the time taken
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    printf("Total number of prime numbers in the range: %d\n", prime_count);
    return 0;
}

