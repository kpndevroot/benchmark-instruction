import time

def is_prime(number):
    if number <= 1:
        return False

    for i in range(2, int(number**0.5) + 1):
        if number % i == 0:
            return False

    return True

def format_number(number):
    if number >= 1e9:
        return f"{number / 1e9:.2f} billion"
    elif number >= 1e6:
        return f"{number / 1e6:.2f} million"
    elif number >= 1e3:
        return f"{number / 1e3:.2f} thousand"
    else:
        return str(number)

start = 1
end = 100000000
prime_count = 0

# Print the original 'end' number
formatted_end = format_number(end)
print(f"Total : {formatted_end}")

start_time = time.time()

print(f"Prime numbers in the range {start} to {end} are:")
for i in range(start, end + 1):
    if is_prime(i):
        prime_count += 1

end_time = time.time()

time_taken = end_time - start_time

# Print the results
formatted_end = format_number(end)
print(f"Total Number: {formatted_end}")
print(f"Time taken: {time_taken} seconds")
print(f"Total number of prime numbers in the range: {prime_count}")
