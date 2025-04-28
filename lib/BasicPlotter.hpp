#pragma once

#include "Plotter.hpp"
#include "Console.hpp"
#include "Rect.h"

#include <math.h>

class BasicPlotter : public Plotter {

public:
    BasicPlotter(Expression& exp) : Plotter(exp, "basic") {}

    void Draw(Rect<int> consoleArea, Rect<double> worldArea) const;
};