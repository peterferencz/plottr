#include <iostream>
#include <getopt.h>

#include "Console.hpp"
#include "UI.hpp"
#include "CommandManager.hpp"
#include "Plotter.hpp"
#include "InfoScreen.hpp"
#include "MoveCommand.hpp"
#include "InfoCommand.hpp"
#include "PlotCommand.hpp"
#include "OffsetCommand.hpp"


int main(int argc, char** argv){
    Console::init();

    Expression expression({0, 2, 0});

    Plotter plotter(expression);
    InfoScreen infoScreen(expression);

    Front ui(&plotter);

    CommandManager manager{
        new MoveCommand(plotter),
        new OffsetCommand(plotter),
        new InfoCommand(ui, infoScreen),
        new PlotCommand(ui, plotter)
    };

    //Draw ui while we don't quit through exit command
    do {
        ui.Draw();
    }  while(manager.CaptureInput(ui));

    Console::destroy();
}
