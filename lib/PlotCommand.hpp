#pragma once

#include <vector>
#include <string>

#include "Command.hpp"
#include "InfoScreen.hpp"
#include "UI.hpp"

class PlotCommand : public Command {
private:
    Front& ui;
    Plotter& screen;

public:
    PlotCommand(Front& ui, Plotter& info) : Command("plot", 'p', 0), ui(ui), screen(info) {}
    ~PlotCommand() {}

    void exec(std::vector<std::string>& params);
};