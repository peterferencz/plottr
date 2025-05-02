#pragma once

#include "Command.hpp"
#include "PlotterScreen.hpp"

class ScaleCommand : public Command {
private:
    PlotterScreen& plot;

public:
    ScaleCommand(PlotterScreen& plotter) : Command("scale", 's', 2), plot(plotter) {}
    ~ScaleCommand() {}

    void exec(const std::vector<std::string>& params);
    
};