#include "MoveCommand.hpp"
#include "OffsetCommand.hpp"
#include "InfoCommand.hpp"
#include "PlotCommand.hpp"
#include "StyleCommand.hpp"
#include "tuiCommand.hpp"
#include "Scalecommand.hpp"
#include "OutCommand.hpp"

#include <cstring>
#include <stdexcept>

void MoveCommand::exec(const std::vector<std::string>& params) {
    try{
        double x = std::stod(params[0]);
        double y = std::stod(params[1]);
        plot.Move(x, y);
    }catch (std::invalid_argument&) {
        throw std::invalid_argument("Can't convert string to double!");
    }
}

void OffsetCommand::exec(const std::vector<std::string>& params) {
    try {
        double x = std::stod(params[0]);
        double y = std::stod(params[1]);
        plot.Offset(x, y);
        
    } catch(const std::invalid_argument&) {
        throw std::invalid_argument("Can't convert string to double!");
    }
    

}

void InfoCommand::exec(const std::vector<std::string>&) {
    ui.setScreen(screen);
}

void PlotCommand::exec(const std::vector<std::string>& params) {
    // Used to switch between views
    ui.setScreen(screen);
    
    // Only switch to plot screen, don't override plot if no arguments given
    if(params.size() == 0){
        return;
    }

    // set new command
    double* newExp = new double[params.size()];
    for(size_t i = 0; i < params.size(); i++){
        try{
            newExp[i] = std::stod(params[i]);
        } catch (const std::invalid_argument&){
            throw std::invalid_argument("Can't convert string to double!");
        }
    }
    exp.set(newExp, params.size());
}

void ScaleCommand::exec(const std::vector<std::string>& params) {
    double w = std::stod(params[0]);
    double h = std::stod(params[1]);

    plot.Scale(w, h);
    
    //TODO make it a different command
    // if(Console::getTUI()){
    // }else{
    //     Console::setWidth(w);
    //     Console::setHeight(h);
    // }
}

void StyleCommand::exec(const std::vector<std::string>& params) {
    std::string style(params[0]);
    
    for(size_t i = 0; i < styles.size(); i++){
        if(params[0] != styles[i]->getStyleName()){ continue;}

        plot.setPlotter(styles[i]);
        return;
    }

    throw InvalidStyleException();
}

void TUICommand::exec(const std::vector<std::string>&) {
    Console::setTUI(!Console::getTUI());
}

void OutCommand::exec(const std::vector<std::string>& params) {
    bool prevTui = Console::getTUI();
    Console::setTUI(false);
    std::ofstream file(params[0]);
    if(!file.is_open()) { throw new UnableToOpenFileException(); }
    Console::RedirectOutput(file);
    
    plot.Draw({0, 0, Console::getWidth(), Console::getHeight()});
    
    Console::RedirectOutput(std::cout);
    Console::setTUI(prevTui);
}