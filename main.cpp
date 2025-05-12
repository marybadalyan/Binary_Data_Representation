#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <stdio.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <signal.h>
    #include <setjmp.h>
    
    static sigjmp_buf jump_buffer;

    void handler(int sig) {
        std::cerr << "Segmentation fault at address (invalid access)\n";
        siglongjmp(jump_buffer, 1);
    }
#endif

bool MemoryAccess(const char* p = nullptr) {
    uintptr_t addr = 0xDEADBEEF; //  invalid
#ifdef _WIN32

    __try {
        unsigned char* p = reinterpret_cast<unsigned char*>(addr);
        std::cout << "Attempting to read from: 0x" << std::hex << addr << std::endl;
        unsigned char val = *p; // Triggers access violation
        std::cout << "Value: 0x" << std::hex << (int)val << std::endl;
    }
    __except (GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ?
            EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) {
        std::cerr << "Segmentation fault at address: 0x" << std::hex << addr << std::endl;
    }
#else
    signal(SIGSEGV, handler);

    if (sigsetjmp(jump_buffer, 1) == 0) {
        uintptr_t addr = 0xDEADBEEF; // deliberately invalid
        unsigned char* p = reinterpret_cast<unsigned char*>(addr);
        std::cout << "Attempting to read from: 0x" << std::hex << addr << std::endl;
        unsigned char val = *p; // Triggers segfault
        std::cout << "Value: 0x" << std::hex << (int)val << std::endl;
    } else {
        std::cerr << "Recovered from segmentation fault.\n";
    }
#endif
    return false;
}
  
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}


bool detect_endian(){
    short num = 0000'0001'0000'0000;

    unsigned char firstByte = *((unsigned char*)&num);

    return (bool)firstByte;
}

void XORSwap(int& a, int& b){
    if (a!= b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}   

int main(){

    std::mt19937 mt(12345); 
    std::uniform_int_distribution<> dist_int(0, 100);  
    int swap_count = 1000000;

    std::vector<int> vec(swap_count);
    for (int i = 0; i < swap_count; ++i) {
        vec[i] = dist_int(mt);  
    }

    std::chrono::high_resolution_clock::time_point start, end;
    start = std::chrono::high_resolution_clock::now();  
    for (int i = 0; i < swap_count - 1; i += 2) {
        XORSwap(vec[i], vec[i + 1]);
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "XOR Swap Time: " << elapsed.count() << " ms" << std::endl;
    
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < swap_count - 1; i += 2) {
        swap(vec[i], vec[i + 1]);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;      
    std::cout << "swap Time: " << elapsed.count() << " ms" << std::endl;


    std::cout << "Endian: " << (detect_endian() ? "Little Endian" : "Big Endian") << std::endl;
    std::cout << "Power of 2: " << (isPowerOfTwo(16) ? "true" : "false") << std::endl; // 16 is a power of 2
    std::cout << "Power of 2: " << (isPowerOfTwo(18) ? "true" : "false") << std::endl; // 18 is not a power of 2


    std::cout << "Memory Access: " << (MemoryAccess() ? "true" : "false") << std::endl; 
    
}