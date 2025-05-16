#pragma once

#include <string>

#include "Console.hpp"
#include "PlotterScreen.hpp"


/// @brief A felhasználói felület és a kirajzolás vezérlője.
/// Ez az osztály felelős a képernyő tartalmának megjelenítéséért, valamint a felhasználói
/// bemenet bekéréséért és a képernyőváltásért.
class Front {
private:
    /// @brief A jelenleg megjelenített képernyő.
    Screen* currentDisplay;

public:
    Front(Screen* display) : currentDisplay(display) {}


public:
    /// @brief A képernyő kirajzolása.
    /// @note Amennyiben interaktív módban fut a program, keretet is rajzol.
    void Draw();

    Screen& getScreen() const;
    void setScreen(Screen& screen);

    /// @brief Felhasználói szövegbevitel lekérése.
    /// @return A felhasználó által beírt szöveg.
    std::string getInput();
};


