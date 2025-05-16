#pragma once

#include <vector>
#include <string>

#include "Command.hpp"
#include "InfoScreen.hpp"
#include "Front.hpp"

/// @brief Az információs képernyőt megjelenítő parancs.
/// Ez a parancs felelős az InfoScreen aktiválásáért, amikor a felhasználó
/// beírja az "info" parancsot vagy az 'i' rövidítést.
class InfoCommand : public Command {
private:
    /// @brief A felhasználói felület kezelője.
    Front& ui;
    
    /// @brief Az információs képernyő, amit meg kell jeleníteni.
    InfoScreen& screen;

public:
    InfoCommand(Front& ui, InfoScreen& info) : Command("info", 'i', 0), ui(ui), screen(info) {}
    ~InfoCommand() {}

    /// @brief A parancs végrehajtása.
    /// @param params A parancs paraméterei.
    /// @note Ez a függvény beállítja az InfoScreen-t az aktuális képernyőként.
    void exec(const std::vector<std::string>& params);
};