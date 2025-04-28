#pragma once

#include "Plotter.hpp"
#include "Console.hpp"
#include "Rect.h"

#include <math.h>

class UnicodePlotter : public Plotter {
private:
    void DrawAxes(Rect<int> consoleArea, Rect<double> worldArea) const;

public:
    UnicodePlotter(Expression& exp) : Plotter(exp, "unicode") {}

    void Draw(Rect<int> consoleArea, Rect<double> worldArea) const;
};
