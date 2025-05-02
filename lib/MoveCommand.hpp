#pragma once

#include <vector>
#include <string>

#include "Command.hpp"
#include "PlotterScreen.hpp"

class MoveCommand : public Command {
private:
    PlotterScreen& plot;

public:
    MoveCommand(PlotterScreen& plotter) : Command("move", 'm', 2), plot(plotter) {}
    ~MoveCommand() {}

    void exec(const std::vector<std::string>& params);
    
};