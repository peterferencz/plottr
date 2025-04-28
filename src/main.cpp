#include <iostream>
#include <getopt.h>

#include "Console.hpp"
#include "Front.hpp"
#include "CommandManager.hpp"
#include "PlotterScreen.hpp"
#include "InfoScreen.hpp"
#include "MoveCommand.hpp"
#include "InfoCommand.hpp"
#include "PlotCommand.hpp"
#include "OffsetCommand.hpp"
#include "StyleCommand.hpp"
#include "tuiCommand.hpp"
#include "Scalecommand.hpp"

int main(int argc, char** argv){
    Console::init();
    // Main polinomial expressionn
    double* defaultArray = new double[3];
    defaultArray[0] = 0;
    defaultArray[1] = 1;
    defaultArray[2] = 0;
    Expression expression(defaultArray, 3);

    Plotter* basicPlotter = new BasicPlotter(expression);

    // Screens
    PlotterScreen plotterScreen(expression, basicPlotter);
    InfoScreen infoScreen(expression);

    // Screen container
    Front ui(&plotterScreen);

    // Init all commands
    CommandManager manager{
        new TUICommand(),
        new MoveCommand(plotterScreen),
        new OffsetCommand(plotterScreen),
        new InfoCommand(ui, infoScreen),
        new PlotCommand(ui, plotterScreen, expression),
        new ScaleCommand(plotterScreen),
        new StyleCommand(plotterScreen, {
            basicPlotter,
            new ASCIIPlotter(expression),
            new UnicodePlotter(expression)
        })
    };

    // Parse Command line arguments
    if(!manager.parseCLA(argc, argv)){
        Console::Print(0,0, "Invalid command line arguments (ignoring)!");
    }
    

    //Draw ui while we don't quit through exit command
    do {
        ui.Draw();
    }  while(manager.CaptureInput(ui));

    Console::destroy();

    delete[] defaultArray;
}
