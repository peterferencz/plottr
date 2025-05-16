#pragma once

#include "Command.hpp"
#include "PlotterScreen.hpp"

/// @brief Méretezési parancs a PlotterScreen számára.
/// A parancs beállítja a világkoordináta-rendszer szélességét és magasságát.
/// @note Ez nem módosítja a konzol méretét.
/// @throws std::invalid_argument ha a paraméterek nem számokká konvertálhatók.
class ScaleCommand : public Command {
private:
    /// A megjelenítendő grafikon képernyője, amelyen a változtatás történik.
    PlotterScreen& plot;

public:
    ScaleCommand(PlotterScreen& plotter) : Command("scale", 's', 2), plot(plotter) {}
    ~ScaleCommand() {}

    /// @brief A parancs végrehajtása.
    /// @param params A parancshoz tartozó paraméterek: szélesség, magasság.
    /// @throws std::invalid_argument Ha nem szám értékeket kap.
    void exec(const std::vector<std::string>& params);
    
};