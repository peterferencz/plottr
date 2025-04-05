#include "InfoScreen.hpp"


void InfoScreen::Draw(int x, int y, int w, int h) const {
    Console::Print(x, y, "I'm an info screen");
}