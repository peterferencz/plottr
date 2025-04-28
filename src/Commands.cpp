#include "MoveCommand.hpp"
#include "OffsetCommand.hpp"
#include "InfoCommand.hpp"
#include "PlotCommand.hpp"
#include "StyleCommand.hpp"
#include "tuiCommand.hpp"
#include "Scalecommand.hpp"

#include "cstring"

void MoveCommand::exec(const char* params[]) {
    try{
        double x = std::stod(params[0]);
        double y = std::stod(params[1]);
        plot.Move(x, y);
    }catch (std::invalid_argument _) {
        //TODO feedback
    }
}

void OffsetCommand::exec(const char* params[]) {
    double x = std::stod(params[0]);
    double y = std::stod(params[1]);

    plot.Offset(x, y);
}

void InfoCommand::exec(const char* params[]) {
    ui.setScreen(screen);
}

void PlotCommand::exec(const char* params[]) {
    // Used to switch between views
    ui.setScreen(screen);

    // set new commandű
    size_t pLen = 0;
    while(params[pLen++] != nullptr){}
    pLen--;
    double* newExp = new double[pLen];
    for(size_t i = 0; i < pLen; i++){
        newExp[i] = std::stod(params[i]);
    }
    exp.set(newExp, pLen);
}

void ScaleCommand::exec(const char* params[]) {
    double w = std::stod(params[0]);
    double h = std::stod(params[1]);

    if(Console::getTUI()){
        plot.Scale(w, h);
    }else{
        Console::setWidth(w);
        Console::setHeight(h);
    }
}

void StyleCommand::exec(const char* params[]) {
    std::string style(params[0]);
    
    for(size_t i = 0; i < styles.size(); i++){
        if(strcmp(params[0], styles[i]->getStyleName()) != 0){ continue;}

        plot.setPlotter(styles[i]);
        return;
    }
}

void TUICommand::exec(const char* params[]) {
    Console::setTUI(!Console::getTUI());
}