#pragma once

#include <vector>
#include <string>
#include <istream>

#include "Command.hpp"
#include "Console.hpp"
#include "UI.hpp"

class CommandManager {
private:
    std::vector<Command*> commands;

public:
    CommandManager(std::initializer_list<Command*> commands) : commands(commands) {}
    ~CommandManager();

    bool CaptureInput(Front ui);

    //TODO parse cla here

private:
    std::vector<std::string> parseCommand(const std::string& line);
};