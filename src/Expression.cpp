#include "Expression.hpp"

// Expression::Expression(std::string str) {
//     size_t firstX = str.find('x');
//     if(firstX == std::string::npos){ // Const expression

//     }
// }

// Expression::~Expression() {
    
// }

//TODO implement
double Expression::valueAt(double x) {
    double sum = 0;
    double _x = 1;
    for(auto c : coefficients){
        sum += c * _x;
        _x *= x;
    }
    return sum;
}