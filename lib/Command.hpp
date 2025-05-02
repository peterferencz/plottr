#pragma once

#include <string>
#include <vector>
#include <array>
#include <string_view>

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
    virtual char getShortName() const { return shortName; }
    virtual int getParamCount() const { return paramCount; }

    virtual void exec(const std::vector<std::string>& params) = 0;
};


