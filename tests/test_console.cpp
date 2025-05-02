#include "test_console.h"


void testConsole() {
    std::cout << "---> Test - Console <---" << std::endl;
    
    TEST(console, init) {
        EXPECT_THROW(Console::Print(0, 0, "Test!"), UnInitializedConsoleException&);
        EXPECT_NO_THROW(Console::init());
        EXPECT_EQ(false, Console::getTUI());
        #ifdef CPORTA
        EXPECT_THROW(Console::setTUI(true), NonInteractiveEnvironmentConsoleException);
        #endif
        EXPECT_NO_THROW(Console::destroy());
    } ENDM

    TEST(console, redirecting_output+print) {
        Console::init();

        std::ostringstream oss;
        Console::RedirectOutput(oss);
        Console::Print(0, 0, "Hello!");
        Console::RedirectOutput(std::cout);
        Console::destroy();

        EXPECT_EQ("Hello!\n", oss.str());
    } ENDM

    TEST(console, dimensions) {
        Console::init();
        Console::setTUI(false);

        Console::setWidth(43);
        EXPECT_EQ(43, Console::getWidth());

        Console::setHeight(72);
        EXPECT_EQ(72, Console::getHeight());
        
        Console::destroy();

    } ENDM
}