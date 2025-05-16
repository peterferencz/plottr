#pragma once

#include "Expression.hpp"
#include "Rect.h"

/// @brief Absztrakt ősosztály grafikus kirajzolásokhoz.
/// A Plotter osztály egy interfész, amely különféle kirajzolási stílusok
/// implementálására szolgál. Minden származtatott osztálynak meg kell valósítania
/// a Draw függvényt.
class Plotter {
protected:
    /// @brief Az ábrázolandó kifejezés.
    Expression& exp;
    /// @brief A stílus neve, amely megkülönbözteti a megjelenítési módokat.
    const char* styleName;

public:
    Plotter(Expression& exp, const char* styleName)
    : exp(exp), styleName(styleName) { }
    virtual ~Plotter() = default;

    static const char dot = '*';

    virtual const char* getStyleName() const { return styleName; }

    /// @brief Kirajzolja a kifejezést a megadott konzol- és világkoordináták alapján.
    /// Ezt a függvényt a származtatott osztályok valósítják meg. A megadott
    /// területre (konzol és világ) rajzolják ki a kifejezést.
    /// @param consoleArea A konzol területe (karakterkoordinátákban).
    /// @param worldArea A világ területe (valós koordinátákban).
    virtual void Draw(Rect<int> consoleArea, Rect<double> worldArea) const = 0;
};
