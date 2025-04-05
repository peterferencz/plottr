#include "CommandManager.hpp"

bool CommandManager::CaptureInput(Front ui){
    using namespace std;

    vector<string> input = parseCommand(ui.getInput());
    
    // Ignore empty commands
    if(input.size() == 0){
        return true; 
    }
    string& commandName = input[0];
    
    if(commandName == "exit" || commandName == "quit" || commandName == "q"){
        return false;
    }
    
    for(auto cmd : commands){
        if(cmd->getName() == commandName || cmd->getShortName() == commandName[0]){
            cmd->exec(input);
            break;
        }
    }

    return true;
}

// Source: https://stackoverflow.com/a/5888676 
std::vector<std::string> CommandManager::parseCommand(const std::string& line){
    const char SEP = ' ';
    using namespace std;
    

    size_t pos = line.find(SEP);
    size_t initPos = 0;
    vector<string> tokens;

    while (pos != string::npos) {
        tokens.push_back( line.substr( initPos, pos - initPos ) );
        initPos = pos + 1;

        pos = line.find( SEP, initPos );
    }

    //Last item
    tokens.push_back( line.substr( initPos, min( pos, line.size() ) - initPos + 1 ) );
    
    return tokens;
}


CommandManager::~CommandManager() {
    for(auto cmd : commands){
        delete cmd;
    }
}