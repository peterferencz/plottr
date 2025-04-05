#pragma once

#include <string>
#include <vector>

class Command {
private:
    const char* name;
    const char shortName;
    const int paramCount;


public:
    Command(const char* name, const char shortName, const int paramCount) 
    : name(name), shortName(shortName), paramCount(paramCount) { }
    virtual ~Command() = default;

    virtual const char* getName() const { return name; }
    virtual const char getShortName() const { return shortName; }

    virtual void exec(std::vector<std::string>& params) = 0;
};


