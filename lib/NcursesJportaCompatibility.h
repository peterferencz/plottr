#pragma once

// This file is solely for the Jporta system, so it compiles.

typedef struct _win_st WINDOW;
typedef short NCURSES_PAIRS_T;
typedef short NCURSES_COLOR_T;
typedef unsigned chtype;
typedef	chtype attr_t;

#define COLOR_BLACK 	0
#define COLOR_RED   	1
#define COLOR_GREEN 	2
#define COLOR_YELLOW    3
#define COLOR_BLUE  	4
#define COLOR_MAGENTA   5
#define COLOR_CYAN  	6
#define COLOR_WHITE 	7

extern WINDOW* stdscr;
extern int LINES;
extern int COLS;

#include <exception>
class NonInteractiveEnvironmentConsoleException : public std::exception{ };

inline WINDOW* initscr (void) {throw NonInteractiveEnvironmentConsoleException();}
inline int keypad(WINDOW *, bool) {throw NonInteractiveEnvironmentConsoleException();}
inline char *setlocale (int, const char *) {throw NonInteractiveEnvironmentConsoleException();}
inline int cbreak() {throw NonInteractiveEnvironmentConsoleException();}
inline int echo() {throw NonInteractiveEnvironmentConsoleException();}
inline bool has_colors () {throw NonInteractiveEnvironmentConsoleException();}
inline int start_color () {throw NonInteractiveEnvironmentConsoleException();}
inline int init_pair (NCURSES_PAIRS_T,NCURSES_COLOR_T,NCURSES_COLOR_T) {throw NonInteractiveEnvironmentConsoleException();}
inline int attron (attr_t) {throw NonInteractiveEnvironmentConsoleException();}
inline int clear(){throw NonInteractiveEnvironmentConsoleException();}
inline int refresh() {throw NonInteractiveEnvironmentConsoleException();}
inline int endwin() {throw NonInteractiveEnvironmentConsoleException();}
inline int wmove (int,int){throw NonInteractiveEnvironmentConsoleException();}
inline int move (int,int){throw NonInteractiveEnvironmentConsoleException();}
inline int mvaddwstr(int, int, const wchar_t*) {throw NonInteractiveEnvironmentConsoleException();}
inline int mvaddstr(int, int, const char*) {throw NonInteractiveEnvironmentConsoleException();}
inline int getnstr(char*, int){throw NonInteractiveEnvironmentConsoleException();}

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
inline attr_t COLOR_PAIR(CONSOLECOLOR) {throw NonInteractiveEnvironmentConsoleException();}