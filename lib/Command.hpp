#pragma once

#include <string>
#include <vector>
#include <array>

class Command {
private:
    const char* name;
    const char shortName;
    // paramCount of -1 resembles any number of arguments
    const int paramCount;


public:
    Command(const char* name, const char shortName, const int paramCount) 
    : name(name), shortName(shortName), paramCount(paramCount) { }
    virtual ~Command() = default;

    virtual const char* getName() const { return name; }
    virtual const char getShortName() const { return shortName; }
    virtual const int getParamCount() const { return paramCount; }

    //TODO make const
    virtual void exec(const char* params[]) = 0;
};


