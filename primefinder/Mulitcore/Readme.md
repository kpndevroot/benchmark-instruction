# Prime Finder With GPU

This project demonstrates how to find prime numbers up to a specified limit using both CPU and GPU computations. It leverages Python, Numba, and CUDA for GPU acceleration, providing a comparison between CPU and GPU performance for the same task.

## Prerequisites

- [anaconda](https://docs.anaconda.com/free/anaconda/install/index.html)
- [Python 3.x](https://www.python.org/downloads/)
- [Numba](https://numba.readthedocs.io/en/stable/user/installing.html)
- [CUDA Toolkit installed (for GPU computation)](https://docs.nvidia.com/cuda/cuda-toolkit-release-notes/index.html)

## Installation

1. **Python Installation:**
   Ensure Python 3.x is installed on your system. You can download it from the official Python website.

2. **Python Dependencies:**
   Install the required Python packages using pip:
   ```bash
    conda create --name primefinder python=3.8
    conda activate primefinder
   ```
   ```bash
    conda install numpy
    conda install numba
    conda install cudatoolkit
   ```
3. **Run the Code**

   ```bash
   python primefinder.py
   ```
