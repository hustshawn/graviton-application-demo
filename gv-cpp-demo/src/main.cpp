#include <iostream>

int main() {
    std::cout << "Hello from ARM Architecture!" << std::endl;
    
    // Print architecture information
    #if defined(__aarch64__)
        std::cout << "Running on ARM64 architecture" << std::endl;
    #elif defined(__arm__)
        std::cout << "Running on ARM32 architecture" << std::endl;
    #else
        std::cout << "Running on different architecture" << std::endl;
    #endif
    
    return 0;
} 