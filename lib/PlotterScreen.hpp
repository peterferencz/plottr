#pragma once 

#include <cmath>

#include "Expression.hpp"
#include "Console.hpp"
#include "Screen.h"
#include "Plotter.hpp"
#include "Rect.h"
#include "BasicPlotter.hpp"
#include "ASCIIPlotter.hpp"
#include "UnicodePlotter.hpp"

class PlotterScreen : public Screen {
private:
    Expression& exp;
    Plotter* plotter;

    Rect<double> worldArea;

private:
    void DrawAxes(Rect<int> consoleArea) const;

public:
    PlotterScreen(Expression& exp, Plotter* plotter);
    // ~Plotter();

    void Move(double x, double y);
    void Offset(double dx, double dy);
    void Scale(double w, double h);
    // void setExpression(Expression exp);
    void Draw(Rect<int> consoleArea) const;

    void setPlotter(Plotter* plotter);
};