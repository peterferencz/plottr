#include "Expression.hpp"

double Expression::valueAt(double x) {
    double sum = 0;
    double _x = 1;
    
    for(size_t i = 0; i < coefficientsLen; i++){
        sum += coefficients[i] * _x;
        _x *= x;
    }
    return sum;
}

void Expression::set(double* coefficients, size_t coefficientsLen){
    delete[] this->coefficients;
    this->coefficients = coefficients;
    this->coefficientsLen = coefficientsLen;
}