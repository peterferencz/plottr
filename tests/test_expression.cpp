#include "test_expression.h"


void testExpression() {
    TEST(expression, init) {
        Expression e;

        EXPECT_EQ((size_t) 0, e.getCoefficients().second);
        EXPECT_EQ((double*)nullptr, e.getCoefficients().first);

        double* coeffs = new double[5]{0, 1, 2, 3, 4};
        Expression e2(coeffs, 5);

        EXPECT_EQ((size_t) 5, e2.getCoefficients().second);
        EXPECT_NE((double*)nullptr, e2.getCoefficients().first);

        e.set(coeffs, 5);
        EXPECT_EQ((size_t) 5, e.getCoefficients().second);
        EXPECT_NE((double*)nullptr, e.getCoefficients().first);
    } ENDM

    TEST(expression, values) {
        double* coeffs = new double[3]{1, -3, 2}; // 2x^2-3X+1
        Expression e(coeffs, 3);

        EXPECT_EQ((double) 1, e.valueAt(0));
        EXPECT_EQ((double) 2*1*1 -3*1+1, e.valueAt(1));
        EXPECT_EQ((double) 2*0.5*0.5 -3*0.5+1, e.valueAt(0.5));
        EXPECT_EQ((double) 2*(-9)*(-9) -3*(-9)+1, e.valueAt(-9));

        Expression e2;
        EXPECT_EQ((double) 0, e2.valueAt(0));
        EXPECT_EQ((double) 0, e2.valueAt(1));
        EXPECT_EQ((double) 0, e2.valueAt(-9));
        EXPECT_EQ((double) 0, e2.valueAt(3.5));
    } ENDM
}
