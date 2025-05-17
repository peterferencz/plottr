#pragma once

#include "Plotter.hpp"
#include "Console.hpp"
#include "Rect.h"

#include <math.h>

class ASCIIPlotter : public Plotter {
public:
    ASCIIPlotter(Expression& exp) : Plotter(exp, "ascii") {}

    void Draw(Rect<int> consoleArea, Rect<double> worldArea) const;

private:
    void DrawAxes(Rect<int> consoleArea, Rect<double> worldArea, char** lines) const;
    void InterpolateDraw(Rect<int> consoleArea, char** lines, Rect<int> interpol) const;
};