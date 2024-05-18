from numba import jit, cuda
import numpy as np
from timeit import default_timer as timer
import multiprocessing
import math

def get_cuda_cores():
    device = cuda.get_current_device()
    mp_count = device.MULTIPROCESSOR_COUNT
    # Common values for CUDA cores per multiprocessor; adjust based on GPU architecture
    cores_per_mp = 128  # Adjust based on your GPU's specific architecture
    return mp_count * cores_per_mp

# Normal function to check for primes on CPU
def is_prime_cpu(n):
    if n <= 1:
        return False
    for i in range(2, int(np.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def find_primes_cpu_chunk(start, end):
    primes = []
    for num in range(start, end):
        if is_prime_cpu(num):
            primes.append(num)
    return primes

def find_primes_cpu(limit, num_workers):
    chunk_size = limit // num_workers
    chunks = [(i * chunk_size + 2, (i + 1) * chunk_size + 2) for i in range(num_workers)]
    
    with multiprocessing.Pool(processes=num_workers) as pool:
        results = pool.starmap(find_primes_cpu_chunk, chunks)
    
    primes = []
    for result in results:
        primes.extend(result)
    return primes

# GPU-optimized prime checking function
@cuda.jit
def is_prime_gpu(results, limit):
    idx = cuda.grid(1)
    if idx < limit:
        num = idx + 2  # since range starts from 2
        is_prime = True
        if num <= 1:
            is_prime = False
        for i in range(2, int(math.sqrt(num)) + 1):
            if num % i == 0:
                is_prime = False
                break
        results[idx] = is_prime

def find_primes_gpu(limit):
    n = limit - 1  # since we're starting from 2
    results_device = cuda.device_array(n, dtype=np.int32)
    
    threads_per_block = 1024
    blocks_per_grid = (n + threads_per_block - 1) // threads_per_block
    
    is_prime_gpu[blocks_per_grid, threads_per_block](results_device, n)
    
    results_host = results_device.copy_to_host()
    
    primes = [num + 2 for num in range(n) if results_host[num]]
    return primes

if __name__ == "__main__":
    limit = 100000000
    num_workers = multiprocessing.cpu_count()
    
    # Get CPU core count
    print(f"Number of CPU cores: {num_workers}")
    
    # Get CUDA core count
    cuda_cores = get_cuda_cores()
    print(f"Number of CUDA cores: {cuda_cores}")

    start = timer()
    primes_cpu = find_primes_cpu(limit, num_workers)
    print("CPU time:", timer() - start)

    start = timer()
    primes_gpu = find_primes_gpu(limit)
    print("GPU time:", timer() - start)
    
    # Optional: print the number of primes found for verification
    print(f"Number of primes found (CPU): {len(primes_cpu)}")
    print(f"Number of primes found (GPU): {len(primes_gpu)}")
