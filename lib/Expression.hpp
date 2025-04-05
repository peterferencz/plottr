#pragma once

#include <string>
#include <vector>

class Expression {
private:
    // Stored as such: c[0] + c[1] * x + c[2]*x^2 + ...
    std::vector<double> coefficients;

public:
    Expression() : coefficients{{0}} {}
    Expression(std::vector<double> coefficients) : coefficients(coefficients) {}
    // ~Expression();

    double valueAt(double x);
};
