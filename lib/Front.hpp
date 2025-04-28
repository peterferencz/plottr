#pragma once

#include <string>

#include "Console.hpp"
#include "PlotterScreen.hpp"

class Front {
private:
    Screen* currentDisplay;

public:
    Front(Screen* display) : currentDisplay(display) {}


public:
    void Draw();
    void setScreen(Screen& screen);
    std::string getInput();
};


