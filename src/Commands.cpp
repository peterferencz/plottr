#include "MoveCommand.hpp"
#include "OffsetCommand.hpp"
#include "InfoCommand.hpp"
#include "PlotCommand.hpp"

void MoveCommand::exec(std::vector<std::string>& params) {
    if(params.size() < 3) { return; }
    double x = std::stod(params[1]);
    double y = std::stod(params[2]);

    plot.Move(x, y);
}

void OffsetCommand::exec(std::vector<std::string>& params) {
    if(params.size() < 3) { return; }
    double x = std::stod(params[1]);
    double y = std::stod(params[2]);

    plot.Offset(x, y);
}

void InfoCommand::exec(std::vector<std::string>& params) {
    ui.setScreen(screen);
}

void PlotCommand::exec(std::vector<std::string>& params) {
    // Used to switch between views
    if(params.size() == 1) {
        ui.setScreen(screen);
        return;
    }

    //
}