#pragma once

#include <vector>
#include <string>

#include "Command.hpp"
#include "PlotterScreen.hpp"

class OffsetCommand : public Command {
private:
    PlotterScreen& plot;

public:
    OffsetCommand(PlotterScreen& plotter) : Command("offset", 'o', 2), plot(plotter) {}
    ~OffsetCommand() {}

    void exec(const std::vector<std::string>& params);
    
};