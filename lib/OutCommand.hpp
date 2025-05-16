#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "Command.hpp"
#include "PlotterScreen.hpp"

/// @brief Kivétel, ha nem sikerül megnyitni a fájlt írásra.
class UnableToOpenFileException : public std::exception {};

/// @brief Parancs, amely a grafikon kimenetét fájlba menti.
/// Lehetővé teszi, hogy a kirajzolt grafikon szöveges formában féjlba mentsük.
class OutCommand : public Command {
private:
    /// @brief A rajzoló képernyő, amelyet fájlba írunk ki.
    PlotterScreen& plot;

public:
    OutCommand(PlotterScreen& plotter) : Command("out", 'o', 1), plot(plotter) {}
    ~OutCommand() {}

    /// @brief A grafikon fájlba mentésének végrehajtása.
    /// A paraméterként megadott fájlba kerül a grafikon mentésre.
    /// @param params Egyetlen fájlnév stringet tartalmazó vektor.
    /// @throws UnableToOpenFileException ha nem sikerül megnyitni a fájlt írásra.
    void exec(const std::vector<std::string>& params);
    
};