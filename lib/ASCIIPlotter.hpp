#pragma once

#include "Plotter.hpp"
#include "Console.hpp"
#include "Rect.h"

#include <math.h>

class ASCIIPlotter : public Plotter {
private:
    void DrawAxes(Rect<int> consoleArea, Rect<double> worldArea) const;

public:
    ASCIIPlotter(Expression& exp) : Plotter(exp, "ascii") {}

    void Draw(Rect<int> consoleArea, Rect<double> worldArea) const;
};