#pragma once

#include <string>
#include <iostream>

#include <ncurses.h>

// COlors ported from ncurses (ncurses.h:288) macro defintions
enum CONSOLECOLOR {
    BLACK   =	0,
    RED     =	1,
    GREEN   =	2,
    YELLOW  =	3,
    BLUE    =	4,
    MAGENTA =	5,
    CYAN    =	6,
    WHITE   =	7
};

class Console {
private:
    static bool initialized;

public:
    Console() = delete;

public:
    static void init();
    static void destroy();

    static int getHeight();
    static int getWidth();

    static std::string getInputOfLength(int l);

    static void moveCursor(int x, int y);

    static void Print(int x, int y, const wchar_t* str);
    static void Print(int x, int y, const char* str);

    static void setColor(CONSOLECOLOR color = WHITE);

    static void flush();
    static void Clear();
    static void Clear(int x, int y, int w, int h);

    // static void flush();
    // static void dBorder(int x, int y, int w, int h, FrameDecoration decoration = DefaultFrameDecoration);
    // static void dBorderwTitle(int x, int y, int w, int h, std::string title, FrameDecoration decoration = DefaultFrameDecoration);
};