#pragma once

#include <string>
#include <utility>

/// @brief Polinomiális kifejezést reprezentáló osztály.
/// A kifejezés formája: `c[0] + c[1]*x + c[2]*x^2 + ...`,
/// ahol a `c[i]` értékeket a `coefficients` tömb tartalmazza.
class Expression {
private:
    /// A polinom együtthatóinak tömbje.
    double* coefficients;
    /// Az együtthatók tömbjének hossza.
    size_t coefficientsLen;

public:
    Expression()
    : coefficients(nullptr),  coefficientsLen(0) {}

    /// @brief Adott együtthatósorozattal létrehozott kifejezés.
    /// @param coefficients A polinom együtthatói.
    /// @param coefficientsLen Az együtthatók száma.
    Expression(double* coefficients, size_t coefficientsLen)
    : coefficients(coefficients), coefficientsLen(coefficientsLen) {}
    
    /// @brief Új együtthatók beállítása.
    /// @param coefficients A polinom új együtthatói.
    /// @param coefficientsLen Az új együtthatók száma.
    /// @note Ez a függvény nem másolja le a tömböt, csak a pointert tárolja.
    void set(double* coefficients, size_t coefficientsLen);

    /// @brief Az együtthatók lekérdezése.
    /// @return A `coefficients` tömb pointere és hossza egy `std::pair`-ben.
    std::pair<double*, size_t> getCoefficients() const {
        return { coefficients, coefficientsLen };
    }

    /// @brief A kifejezés kiértékelése egy adott `x` értéknél.
    /// @param x Az `x` változó értéke, ahol a kifejezést kiértékeljük.
    /// @return A polinom értéke az adott `x`-nél.
    double valueAt(double x) const;
};
