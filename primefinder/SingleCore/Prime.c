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

void format_number(int number, char* buffer, size_t size) {
    if (number >= 1e9) {
        snprintf(buffer, size, "%.2f billion", (double)number / 1e9);
    } else if (number >= 1e6) {
        snprintf(buffer, size, "%.2f million", (double)number / 1e6);
    } else if (number >= 1e3) {
        snprintf(buffer, size, "%.2f thousand", (double)number / 1e3);
    } else {
        snprintf(buffer, size, "%d", number);
    }
}

int main() {
    int start = 1, end = 100000000;
    int prime_count = 0;

    // Print the original 'end' number
    char formatted_end[50];
    format_number(end, formatted_end, sizeof(formatted_end));
    printf("Total : %s\n", formatted_end);

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

    format_number(end, formatted_end, sizeof(formatted_end));

    printf("Total Number: %s\n", formatted_end);
    printf("Time taken: %f seconds\n", time_taken);
    printf("Total number of prime numbers in the range: %d\n", prime_count);

    return 0;
}
