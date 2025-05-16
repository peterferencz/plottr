#pragma once 

#include "Screen.h"
#include "Expression.hpp"
#include "Console.hpp"

#include <sstream>

/// @brief Információs képernyő osztály, amely az aktuális kifejezésről jelenít meg információkat.
/// Az InfoScreen osztály célja, hogy szöveges formában megjelenítse az aktuálisan
/// használt matematikai kifejezést, amelyet a felhasználó éppen rajzoltat.
class InfoScreen : public Screen {
private:
    /// @brief Az aktuálisan ábrázolt kifejezés.
    Expression& exp;

public:
    InfoScreen(Expression& exp) : exp(exp) {}

    /// @brief A képernyő tartalmának kirajzolása a konzolra.
    /// @param consoleArea A konzolon megjelenítendő terület, ahova a képernyőt írjuk.
    void Draw(Rect<int> consoleArea) const;
};