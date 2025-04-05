#pragma once 

#include "Screen.h"
#include "Expression.hpp"
#include "Console.hpp"

class InfoScreen : public Screen {
private:
    Expression& exp;

public:
    InfoScreen(Expression& exp) : exp(exp) {}
    // ~Plotter();

    // void Move(double x, double y);
    // void Offset(double dx, double dy);
    // void Scale(double xw, double yw);
    // void setExpression(Expression exp);
    void Draw(int x, int y, int w, int h) const;
};