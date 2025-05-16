#pragma once

#include "Rect.h"

/// @brief Absztrakt alaposztály a képernyőfelületekhez.
/// Ez az osztály határozza meg az interfészt minden képernyő-típushoz, amely
/// valamilyen módon megjelenítést végez a konzolon.
class Screen {
public:
    /// @brief A képernyő kirajzolása a megadott konzolterületre.
    /// @param consoleArea A konzolon használt téglalap alakú terület (x, y, szélesség, magasság).
    virtual void Draw(Rect<int> consoleArea) const = 0;
};


