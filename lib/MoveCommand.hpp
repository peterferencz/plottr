#pragma once

#include <vector>
#include <string>

#include "Command.hpp"
#include "Plotter.hpp"

class MoveCommand : public Command {
private:
    Plotter& plot;

public:
    MoveCommand(Plotter& plotter) : Command("move", 109, 2), plot(plotter) {}
    ~MoveCommand() {}

    void exec(std::vector<std::string>& params);
    
};