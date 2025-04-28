#pragma once

#include <string>
#include <utility>


class Expression {
private:
    // Stored as such: c[0] + c[1] * x + c[2]*x^2 + ...
    double* coefficients;
    size_t coefficientsLen;

public:
    Expression()
    : coefficients(nullptr),  coefficientsLen(0) {}
    Expression(double* coefficients, size_t coefficientsLen)
    : coefficients(coefficients), coefficientsLen(coefficientsLen) {}
    
    void set(double* coefficients, size_t coefficientsLen);

    std::pair<double*, size_t> getCoefficients() const {
        return { coefficients, coefficientsLen };
    }

    double valueAt(double x);
};
