#pragma once 

#include <cmath>

#include "Expression.hpp"
#include "Console.hpp"
#include "Screen.h"

class Plotter : public Screen {
private:
    Expression& exp;
    //Offset from top-left of screen
    double xOffset, yOffset;
    double xWidth, yWidth;

public:
    Plotter(Expression& exp);
    // ~Plotter();

    void Move(double x, double y);
    void Offset(double dx, double dy);
    void Scale(double xw, double yw);
    // void setExpression(Expression exp);
    void Draw(int x, int y, int w, int h) const;
};