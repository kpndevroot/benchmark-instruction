#include <iostream>
#include <iomanip>
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

std::string format_number(int number) {
    if (number >= 1e9) {
        return std::to_string(static_cast<double>(number) / 1e9) + " billion";
    } else if (number >= 1e6) {
        return std::to_string(static_cast<double>(number) / 1e6) + " million";
    } else if (number >= 1e3) {
        return std::to_string(static_cast<double>(number) / 1e3) + " thousand";
    } else {
        return std::to_string(number);
    }
}

int main() {
    int start = 1, end = 100000000;
    int prime_count = 0;

    clock_t start_time = clock();

    std::cout << "Prime numbers in the range " << start << " to " << end << " are:\n";
    std::cout << "Original End Number: " << std::fixed << std::setprecision(2) << format_number(end) << '\n';
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            prime_count++;
        }
    }

    clock_t end_time = clock();

    double time_taken = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the original 'end' number
    std::cout << "Original End Number: " << std::fixed << std::setprecision(2) << format_number(end) << '\n';

    // Print the results
    std::cout << "Total Number: " << std::fixed << std::setprecision(2) << format_number(end) << '\n';
    std::cout << "Time taken: " << time_taken << " seconds\n";
    std::cout << "Total number of prime numbers in the range: " << prime_count << '\n';

    return 0;
}
