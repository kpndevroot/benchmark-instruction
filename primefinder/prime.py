import time

def is_prime(number):
    if number <= 1:
        return False

    for i in range(2, int(number**0.5) + 1):
        if number % i == 0:
            return False

    return True

start = 1
# end=1000
end = 100000000
prime_count = 0

start_time = time.time()

print(f"Prime numbers in the range {start} to {end} are:")
for i in range(start, end + 1):
    if is_prime(i):
        prime_count += 1

end_time = time.time()

time_taken = end_time - start_time
print(f"Time taken: {time_taken} seconds")
print(f"Total number of prime numbers in the range: {prime_count}")
