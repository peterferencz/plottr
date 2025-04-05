#include "Console.hpp"
#include "Error.hpp"


bool Console::initialized = false;

void Console::init(){
    expect_eq(initialized, false); // Console was already initialized!
    initialized = true;
    
    initscr();
    keypad(stdscr, TRUE);
    setlocale(LC_ALL, "");
    cbreak();
    echo();
    // noecho();
    // curs_set(0);


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
    expect_eq(initialized, true);   // Console was not initialized!
    initialized = false;

    endwin();
}

void Console::flush() {
    refresh();
}

void Console::setColor(CONSOLECOLOR color) {
    if(!has_colors()) {return; } //Terminal doesn't support colors

    attron(COLOR_PAIR(color));
}

void Console::moveCursor(int x, int y){
    move(y, x);
}

void Console::Print(int x, int y, const wchar_t* str) {
    mvaddwstr(y, x, str);
}
void Console::Print(int x, int y, const char* str) {
    mvaddstr(y, x, str);
}

std::string Console::getInputOfLength(int l){
    char* input = new char[l];
    getnstr(input, l);

    std::string str(input);

    delete input;

    str[0];

    return str;
}

void Console::Clear() {
    clear();
}

void Console::Clear(int x, int y, int w, int h){
    std::string clr(w, ' ');
    for(int _y = y; _y < y + h; _y++){
        mvaddstr(_y, x, clr.c_str());
    }
    refresh();
}


int Console::getHeight() {
    return LINES;
}
int Console::getWidth() {
    return COLS;
}

// void Console::dBorder(int x, int y, int w, int h, FrameDecoration decoration){
//     expect_eq(initialized, true);   // Console was not initialized!

//     const int H = y + h;
//     const int W = x + w;
//     for(int _y = y; _y < H; _y++){
//         for(int _x = x; _x < x + w; _x++){
            
//             const wchar_t* c = L" ";
//             if(_x == x && _y == y){ c = decoration.tl; }
//             else if(_x == x && _y == H-1){ c = decoration.bl; }
//             else if(_x == W-1 && _y == H-1){ c = decoration.br; }
//             else if(_x == W-1 && _y == y){ c = decoration.tr; }
//             else if(_x == x){ c = decoration.l; }
//             else if(_x == W-1) {c = decoration.r; }
//             else if(_y == y){ c = decoration.t; }
//             else if(_y == H-1){ c = decoration.b; }
            

//             // mvaddch(_y, _x, '*');
//             mvaddwstr(_y, _x, c);
//         }
//     }

// }

// void Console::dBorderwTitle(int x, int y, int w, int h, std::string title, FrameDecoration decoration){
//     expect_eq(initialized, true);   // Console was not initialized!

//     dBorder(x, y, w, h, decoration);

//     const int titleIndex = (w - title.length()) / 2;
//     mvaddstr(y, x + titleIndex, title.c_str());
// }


// #if defined(WIN)
//     //TODO 
//     // #include <windows.h>
//     // CONSOLE_SCREEN_BUFFER_INFO csbi;
//     // int columns, rows;
  
//     // GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
//     // columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
//     // rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
  
//     // printf("columns: %d\n", columns);
//     // printf("rows: %d\n", rows);
//     // return 0;
// #endif

// #if defined(UNIX)
//     struct winsize w;
//     ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

//     printf ("lines %d\n", w.ws_row);
//     printf ("columns %d\n", w.ws_col);

// #endif