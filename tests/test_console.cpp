#include "test_console.h"


void testConsole() {
    TEST(init, console) {
        EXPECT_THROW(Console::Print(0, 0, "Test!"), UnInitializedConsoleException&);
        EXPECT_NO_THROW(Console::init());
        EXPECT_EQ(false, Console::getTUI());
    } ENDM
}