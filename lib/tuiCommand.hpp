#pragma once

#include "Command.hpp"

class TUICommand : public Command {
public:
    TUICommand() : Command("tui", 't', 0) {}
    ~TUICommand() {}

    void exec(const std::vector<std::string>& params);
};