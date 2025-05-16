#pragma once

#include <vector>
#include <string>

#include "Command.hpp"
#include "PlotterScreen.hpp"

/// @brief Parancs, amely elmozdítja a kirajzolt grafikon nézetét.
/// A MoveCommand segítségével a felhasználó eltolhatja a kirajzolt területet
/// a megadott x és y irányú értékek szerint.
class MoveCommand : public Command {
private:
    /// @brief A kirajzolandó képernyő, amelyen a mozgatás történik.
    PlotterScreen& plot;

public:
    MoveCommand(PlotterScreen& plotter) : Command("move", 'm', 2), plot(plotter) {}
    ~MoveCommand() {}

    /// @brief A parancs végrehajtása.
    /// @param params A parancs paraméterei: két szám, amelyek az x és y irányú eltolást adják meg.
    /// @throws std::invalid_argument Ha a paraméterek nem konvertálhatók számokká.
    void exec(const std::vector<std::string>& params);
    
};