#pragma once

#include <vector>
#include <array>
#include <string>
#include <istream>
#include <unistd.h>
#include <getopt.h>
#include <cstring>

#include "Command.hpp"
#include "Console.hpp"
#include "Front.hpp"

class CommandManager {
private:
    const std::vector<Command*> commands;


public:
    CommandManager(const std::initializer_list<Command*>& commands) : commands(commands) {}
    ~CommandManager();

    bool CaptureInput(Front ui);

    bool parseCLA(size_t argc, char** argv);

private:
    std::vector<std::string> parseCommand(const std::string& line);
};