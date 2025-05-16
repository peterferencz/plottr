#pragma once

#include <vector>
#include <string>

#include "Command.hpp"
#include "PlotterScreen.hpp"

/// @brief Kivétel, ha érvénytelen stílusnevet ad meg a 
/// Ez a kivétel akkor kerül dobásra, ha a felhasználó által megadott stílusnév
/// nem szerepel az elérhető stílusok között.
class InvalidStyleException : public std::exception{ };

/// @brief A stílusváltást megvalósító parancsosztály.
class StyleCommand : public Command {
private:
    /// @brief A megjelenítendő grafikon képernyő.
    PlotterScreen& plot;

    /// @brief Az elérhető rajzolási stílusok.
    std::vector<Plotter*> styles;

public:
    StyleCommand(PlotterScreen& plotter, std::vector<Plotter*> styles)
    : Command("style", 's', 1), plot(plotter), styles(styles) {}
    ~StyleCommand() {
        for(Plotter* p : styles){
            delete p;
        }
    }

    /// @brief Végrehajtja a stílusváltást a megadott név alapján.
    /// @param params Egyetlen paraméterként a kiválasztott stílus neve.
    /// @throws InvalidStyleException Ha a stílus nem található.
    void exec(const std::vector<std::string>& params);
    
};