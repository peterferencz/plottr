#pragma once

#include <vector>
#include <string>

#include "Command.hpp"
#include "PlotterScreen.hpp"

class StyleCommand : public Command {
private:
    PlotterScreen& plot;
    std::vector<Plotter*> styles;

public:
    StyleCommand(PlotterScreen& plotter, std::vector<Plotter*> styles)
    : Command("style", 's', 1), plot(plotter), styles(styles) {}
    ~StyleCommand() {
        for(Plotter* p : styles){
            delete p;
        }
    }

    void exec(const std::vector<std::string>& params);
    
};