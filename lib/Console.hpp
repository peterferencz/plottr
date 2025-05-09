#pragma once

#include <string>
#include <iostream>
#include <exception>


#ifdef CPORTA
#include "NcursesJportaCompatibility.h"
#else
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
#endif

#include "Rect.h"

class UnInitializedConsoleException : public std::exception{ };
class AlreadyInitializedConsoleException : public std::exception{ };

class Console {
private:
    static bool initialized;
    static bool tui;
    static Rect<size_t> noninteractiveConsoleSize;
    static std::ostream* out;

public:
// Thank you memtrace.h, for having a delete macro -_-
#ifndef MEMTRACE
    Console() = delete;
#endif
    static void initNcurses();

public:
    static void init();
    static void destroy();
    static bool getTUI();
    static void setTUI(bool tui);

    static int getHeight();
    static int getWidth();
    static void setHeight(size_t h);    //Only in non tui mode
    static void setWidth(size_t w);     //Only in non tui mode

    static std::string getInputOfLength(int l);

    static void moveCursor(int x, int y);

    static void Print(int x, int y, const wchar_t* str);
    static void Print(int x, int y, const char* str);

    static void RedirectOutput(std::ostream& newOut);

    static void setColor(CONSOLECOLOR color = WHITE);

    static void flush();
    static void Clear();
    static void Clear(int x, int y, int w, int h);

    // static void flush();
    // static void dBorder(int x, int y, int w, int h, FrameDecoration decoration = DefaultFrameDecoration);
    // static void dBorderwTitle(int x, int y, int w, int h, std::string title, FrameDecoration decoration = DefaultFrameDecoration);
};