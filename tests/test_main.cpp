#include "test_console.h"

int main(void) {
#ifdef CPORTA
    GTINIT(std::cin);   //Jporta
#endif
    
    std::cout << "==== Starting tests for PlottR ====" << std::endl;

    testConsole();

    return 0;
}