#include "CommandManager.hpp"

bool CommandManager::CaptureInput(Front ui){
    using namespace std;

    vector<string> input = parseCommand(ui.getInput());
    
    // Ignore empty commands
    if(input.size() == 0){
        return true; 
    }
    string commandName(input[0]);
    input.erase(input.begin()); // Remove first element
    
    if(commandName == "exit" || commandName == "quit" || commandName == "q"){
        return false;
    }
    
    for(Command* cmd : commands){
        if(cmd->getName() != commandName && cmd->getShortName() != commandName[0]){ continue; }
        // Parameter count doesn't match
        if((size_t)cmd->getParamCount() != input.size() && cmd->getParamCount() != -1){ continue; }
            
        cmd->exec(input);
        break;
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


bool CommandManager::parseCLA(size_t argc, char** argv){
    option* claOptions = new option[commands.size() + 1];
    
    // Reserve for short_name and the optional ':'
    std::string argsString(commands.size() * 2, '\0');

    //Constructing the required struct array for getopt_long_only
    for(size_t i = 0; i < commands.size(); i++){
        Command& cmd = *commands[i];
        const bool has_args = cmd.getParamCount() != 0;
        
        claOptions[i].name = cmd.getName();
        claOptions[i].has_arg = has_args ? required_argument : no_argument;
        claOptions[i].flag = NULL;
        claOptions[i].val = cmd.getShortName();

        argsString += cmd.getShortName();
        if(has_args){
            argsString += ':';
        }
    }
    claOptions[commands.size()] = {NULL, 0, NULL, '\0'};
    
    // Walking through argc using getopt_long
    char ch = '\0';
    while ((ch = getopt_long_only(argc, argv, argsString.c_str(), claOptions, NULL)) != -1){
        bool foundCommand = false;

        for(Command* cmd : commands){
            if(cmd->getShortName() != ch){ continue; }
            foundCommand = true;
            
            // const char** params = new const char*[cmd->getParamCount()];
            std::vector<std::string> params;
            params.reserve(cmd->getParamCount());

            size_t i = 0;
            params[i++] = optarg;

            // Collect more space separated arguments
            while ((size_t)optind < argc && argv[optind][0] != '-'){
                if(i == (size_t)cmd->getParamCount()){ break; }
                params.emplace_back(argv[optind++]);
            }

            cmd->exec(params);
            
            break;
        }
        if(!foundCommand){
            // Unkown command
            return false;
        }
    }

    delete[] claOptions;
    return true;
}

CommandManager::~CommandManager() {
    for(Command* cmd : commands){
        delete cmd;
    }
}