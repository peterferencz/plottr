#pragma once

#include <vector>
#include <string>

#include "Command.hpp"
#include "Plotter.hpp"

class OffsetCommand : public Command {
private:
    Plotter& plot;

public:
    OffsetCommand(Plotter& plotter) : Command("offset", 'o', 2), plot(plotter) {}
    ~OffsetCommand() {}

    void exec(std::vector<std::string>& params);
    
};