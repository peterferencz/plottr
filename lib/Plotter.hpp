#pragma once

#include "Expression.hpp"
#include "Rect.h"

class Plotter {
protected:
    Expression& exp;
    const char* styleName;

public:
    Plotter(Expression& exp, const char* styleName)
    : exp(exp), styleName(styleName) { }
    virtual ~Plotter() = default;

    virtual const char* getStyleName() const { return styleName; }

    virtual void Draw(Rect<int> consoleArea, Rect<double> worldArea) const = 0;
};
