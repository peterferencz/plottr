#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "Command.hpp"
#include "PlotterScreen.hpp"

class UnableToOpenFileException : public std::exception {};

class OutCommand : public Command {
private:
    PlotterScreen& plot;

public:
    OutCommand(PlotterScreen& plotter) : Command("out", 'o', 1), plot(plotter) {}
    ~OutCommand() {}

    void exec(const std::vector<std::string>& params);
    
};