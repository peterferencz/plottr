#include "test_console.h"
#include "test_expression.h"
#include "test_plotter_basic.h"
#include "test_commandSuite.h"

int testMain(void) {
#ifdef CPORTA
    GTINIT(std::cin);   //Jporta
#endif
    
    std::cout << "==== Starting tests for PlottR ====" << std::endl;

    std::cout << "---- Test - Console ----" << std::endl;
    testConsole();

    std::cout << "---- Test - Expression ----" << std::endl;
    testExpression();

    std::cout << "---- Test - Expression ----" << std::endl;
    testBasicPlotter();

    std::cout << "---- Test - Command suite ----" << std::endl;
    testCommandSuite();

    std::cout << "==== End of tests for PlottR ====" << std::endl;
    
    return 0;
}