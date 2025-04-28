#pragma once

#include "Command.hpp"

class TUICommand : public Command {
public:
    TUICommand() : Command("tui", 't', 0) {}
    ~TUICommand() {}

    void exec(const char* params[]);
};