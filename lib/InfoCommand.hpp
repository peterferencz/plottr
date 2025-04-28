#pragma once

#include <vector>
#include <string>

#include "Command.hpp"
#include "InfoScreen.hpp"
#include "Front.hpp"

class InfoCommand : public Command {
private:
    Front& ui;
    InfoScreen& screen;

public:
    InfoCommand(Front& ui, InfoScreen& info) : Command("info", 'i', 0), ui(ui), screen(info) {}
    ~InfoCommand() {}

    void exec(const char* params[]);
};