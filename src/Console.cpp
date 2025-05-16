#include "Console.hpp"


bool Console::initialized = false;
bool Console::tui = false;
std::ostream* Console::out = &std::cout;
Rect<size_t> Console::noninteractiveConsoleSize = {0, 0, 20, 10};

void Console::init(){
    if(initialized){ throw AlreadyInitializedConsoleException(); }
    
    initialized = true;

    if(tui){
        initNcurses();
    }
}

void Console::setTUI(bool tui){
    //Prevent tui mode on cporta eval system
    #ifdef CPORTA
        if(tui == true){
            throw NonInteractiveEnvironmentConsoleException();
        }
    #endif
    Console::destroy();
    Console::tui = tui;
    Console::init();
}

bool Console::getTUI(){
    return tui;
}

void Console::initNcurses() {    
    initscr();
    keypad(stdscr, true);
    setlocale(LC_ALL, "");
    cbreak();
    echo();



    if(has_colors()){
        start_color();

        //Color list form Console::CONSOLECOLOR
        init_pair(0, COLOR_BLACK, COLOR_BLACK);
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(6, COLOR_CYAN, COLOR_BLACK);
        init_pair(7, COLOR_WHITE, COLOR_BLACK);

        attron(COLOR_PAIR(WHITE));
    }
    

    clear();
    refresh();
}


void Console::destroy() {
    if(!initialized){ throw UnInitializedConsoleException(); }
    

    Console::Clear();
    if(tui){
        endwin();
    }

    initialized = false;
}

void Console::flush() {
    if(!initialized){ throw UnInitializedConsoleException(); }

    if(tui){
        refresh();
    }
}

void Console::setColor(CONSOLECOLOR color) {
    if(!initialized){ throw UnInitializedConsoleException(); }

    if(tui){
        if(!has_colors()) {return; } //Terminal doesn't support colors

        attron(COLOR_PAIR(color));
    }
}

void Console::moveCursor(int x, int y){
    if(!initialized){ throw UnInitializedConsoleException(); }

    if(tui){
        move(y, x);
    }
}

void Console::Print(int x, int y, const wchar_t* str) {
    if(!initialized){ throw UnInitializedConsoleException(); }

    if(tui){
        mvaddwstr(y, x, str);
    }else{
        *out << str << std::endl;
    }
}
void Console::Print(int x, int y, const char* str) {
    if(!initialized){ throw UnInitializedConsoleException(); }

    if(tui){
        mvaddstr(y, x, str);

    }else{
        *out << str << std::endl;
    }
}

void Console::RedirectOutput(std::ostream& newOut){
    out = &newOut;
}

std::string Console::getInputOfLength(int l){
    if(!initialized){ throw UnInitializedConsoleException(); }

    if(tui){
        char* input = new char[l+1];
        getnstr(input, l);
        std::string str(input);
        delete[] input;
        return str;
    }else{
        std::string toRet;
        toRet.reserve(l);
        std::getline(std::cin, toRet);
        if(std::cin.eof()){
            exit(0);
        }
        
        return toRet;
    }
}

void Console::Clear() {
    if(!initialized){ throw UnInitializedConsoleException(); }

    if(tui){
        clear();
    }
}

void Console::Clear(int x, int y, int w, int h){
    if(!initialized){ throw UnInitializedConsoleException(); }

    if(tui){
        std::string clr(w, ' ');
        for(int _y = y; _y < y + h; _y++){
            mvaddstr(_y, x, clr.c_str());
        }
        refresh();
    }
} 

int Console::getHeight() {
    if(tui){
        #ifndef CPORTA
            return LINES;
        #endif
        return 0;
    }else{
        return noninteractiveConsoleSize.h;
    }
}
int Console::getWidth() {
    if(tui){
        #ifndef CPORTA
            return COLS;
        #endif
        return 0;
    }else{
        return noninteractiveConsoleSize.w;
    }
}

void Console::setHeight(size_t h) {
    if(tui){ return; }
    if(h == 0) {throw InvalidSizeConsoleException(); }

    noninteractiveConsoleSize.h = h;
}

void Console::setWidth(size_t w) {
    if(tui){ return; }
    if(w == 0) {throw InvalidSizeConsoleException(); }

    noninteractiveConsoleSize.w = w;
}
