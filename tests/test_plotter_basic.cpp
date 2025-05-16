#include "test_plotter_basic.h"

//Requires
// - Expression
// - Console
void testBasicPlotter() {
    TEST(basicplotter, init) {
        Expression exp;
        BasicPlotter plotter(exp);
    } ENDM

    TEST(basicplotter, plot) {
        double* coeffs = new double[2]{0, 1};
        Expression exp(coeffs, 2);
        BasicPlotter plotter(exp);
        
        Console::init();
        std::ostringstream oss;
        Console::RedirectOutput(oss);

        //TODO
        // plotter.Draw({0, 0, 3, 3}, {0, 0, 3, 3});
        // EXPECT_EQ(
        //     "  *"
        //     " * "
        //     "*  "
        //     ,oss.str());

        Console::RedirectOutput(std::cout);
        Console::destroy();
    } ENDM
}
