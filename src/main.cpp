#include <iostream>
#include <getopt.h>

#include "Console.hpp"
#include "Front.hpp"
#include "memtrace.h"
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
#include "OutCommand.hpp"

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
        new ScaleCommand(plotterScreen),
        new InfoCommand(ui, infoScreen),
        new PlotCommand(ui, plotterScreen, expression),
        new StyleCommand(plotterScreen, {
            basicPlotter,
            new ASCIIPlotter(expression),
            new UnicodePlotter(expression)
        }),
        new OutCommand(plotterScreen)
    };

    // Parse Command line arguments
    try{
        manager.parseCLA(argc, argv);
    }catch(const UnknownCommandException&){
        Console::Print(0,0, "Invalid command line arguments (ignoring)!");
    }
    

    //Draw ui while we don't quit through exit command
    while(true){
        try{
            if(!manager.CaptureInput(ui)){ break; }
        } catch (const UnknownCommandException&){
            //TODO notify user
        }

        ui.Draw();
    }

    Console::destroy();

    delete[] defaultArray;
}
