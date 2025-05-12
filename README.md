
# Memory and Performance Utilities (C++)
This C++ program demonstrates a collection of low-level utilities and benchmarks including:

✅ XOR-based vs. temporary-variable swapping performance

Performs 1,000,000 pairwise swaps on a randomly generated vector of integers to compare performance of:

- XORSwap – a variable-less integer swap using bitwise XOR

- swap – the standard temporary-variable based swap
  
✅ Endianness Detection
Checks whether the system is little-endian or big-endian by inspecting byte ordering.

✅ Power-of-Two Check
Validates whether given integers are powers of two using efficient bitwise logic.

✅ Memory Access Test
Attempts to read from an invalid memory address (0xDEADBEEF) and handles the resulting segmentation fault safely on:

- Safe memory access testing (with invalid addresses)

- Cross-platform segmentation fault handling

Windows (via __try/__except)

POSIX systems (via sigsetjmp/siglongjmp)

This is useful for learning how low-level platforms handle memory violations.
```
XOR Swap Time: 0.647 ms
swap Time: 0.5636 ms
```
Benchmarks two methods of swapping integers over a large dataset (1,000,000 swaps).

On your system, standard swap using a temporary variable is slightly faster than XOR-based swap, which aligns with typical CPU behavior where XOR swap is less efficient due to lack of optimization and potential instruction dependencies.

```
Endian: Big Endian
```
The system is Big Endian, meaning the most significant byte is stored first in memory.

This is uncommon in most modern desktops (which are typically Little Endian), so you're likely testing on an unusual architecture or using byte-reversed simulation/emulation.

```
Power of 2: true
Power of 2: false
```
Confirms that 16 is a power of two and 18 is not — using bitwise logic.
```
Memory Access: Attempting to read from: 0xdeadbeef
Segmentation fault at address: 0xdeadbeef
false
Tries to read an invalid memory address (0xDEADBEEF).
```
Program catches the segmentation fault safely and reports it without crashing — demonstrating cross-platform fault handling.

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

