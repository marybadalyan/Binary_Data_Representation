
Memory and Performance Utilities (C++)
This C++ program demonstrates a collection of low-level utilities and benchmarks including:

- XOR-based vs. temporary-variable swapping performance

- Endianness detection

- Power-of-two checks

- Safe memory access testing (with invalid addresses)

- Cross-platform segmentation fault handling

Features
✅ Swap Benchmark
Performs 1,000,000 pairwise swaps on a randomly generated vector of integers to compare performance of:

XORSwap – a variable-less integer swap using bitwise XOR

swap – the standard temporary-variable based swap

✅ Endianness Detection
Checks whether the system is little-endian or big-endian by inspecting byte ordering.

✅ Power-of-Two Check
Validates whether given integers are powers of two using efficient bitwise logic.

✅ Memory Access Test
Attempts to read from an invalid memory address (0xDEADBEEF) and handles the resulting segmentation fault safely on:

Windows (via __try/__except)

POSIX systems (via sigsetjmp/siglongjmp)

This is useful for learning how low-level platforms handle memory violations.


##  Example output
```
XOR Swap Time: 0.647 ms
swap Time: 0.5636 ms
Endian: Big Endian
Power of 2: true
Power of 2: false
Memory Access: Attempting to read from: 0xdeadbeef
Segmentation fault at address: 0xdeadbeef
false
```

## Build Instructions

1. Clone the repository:
   ```
   git clone https://github.com/username/Binary_Data_Representation
   ```
2. Navigate to the repository:
   ```
   cd Binary_Data_Representation
   ```
3. Generate build files:
   ```
   cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
   ```
4. Build the project:
   ```
   cmake --build build --config Release
   ```
5. Run the executable from the build directory:
   ```
   ./build/Binary_Data_Representation
   ```

