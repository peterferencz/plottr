#pragma once

#include <vector>
#include <string>

#include "Command.hpp"
#include "InfoScreen.hpp"
#include "Front.hpp"

class PlotCommand : public Command {
private:
    Front& ui;
    PlotterScreen& screen;
    Expression& exp;

public:
    PlotCommand(Front& ui, PlotterScreen& info, Expression& exp)
    : Command("plot", 'p', -1), ui(ui), screen(info), exp(exp) {}
    ~PlotCommand() {}

    void exec(const std::vector<std::string>& params);
};