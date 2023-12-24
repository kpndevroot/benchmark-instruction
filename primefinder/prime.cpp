#include <iostream>
#include <ctime>

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
    int start = 1, end = 10000000;
    int prime_count = 0;

    clock_t start_time = clock();

    std::cout << "Prime numbers in the range " << start << " to " << end << " are:\n";
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            prime_count++;
        }
    }

    clock_t end_time = clock();

    double time_taken = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Time taken: " << time_taken << " seconds\n";
    std::cout << "Total number of prime numbers in the range: " << prime_count << "\n";

    return 0;
}
