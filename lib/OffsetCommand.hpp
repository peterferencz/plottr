#pragma once

#include <vector>
#include <string>

#include "Command.hpp"
#include "PlotterScreen.hpp"

/// @brief Parancs, amely eltolja a világterületet relatív mértékben.
/// Az OffsetCommand segítségével a felhasználó relatív eltolást adhat meg
/// a grafikon kirajzolási világterületére vonatkozóan.
class OffsetCommand : public Command {
private:
    /// @brief A kirajzolt nézet, amelyet eltolunk.
    PlotterScreen& plot;

public:
    OffsetCommand(PlotterScreen& plotter) : Command("offset", 'o', 2), plot(plotter) {}
    ~OffsetCommand() {}

    /// @brief A parancs végrehajtása.
    /// @param params Két számot tartalmazó vektor: az x és y irányú relatív eltolás értékei.
    /// @throws std::invalid_argument Ha a paraméterek nem konvertálhatók számokká.
    void exec(const std::vector<std::string>& params);
};