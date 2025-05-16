#pragma once

#include <string>
#include <iostream>
#include <exception>


#ifdef CPORTA
#include "NcursesJportaCompatibility.h"
#else
#include <ncurses.h>

// Colors ported from ncurses (ncurses.h:288) macro defintions
/// @brief Ncurses makróval definiált színei enum típusban (ld.: ncurses.h:288)
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

/// @brief Akkor dobjuk, ha a program hamarabb hívna `Console` függvényeket, minthogy azt inicializálná (`init`)
class UnInitializedConsoleException : public std::exception{ };
/// @brief Akkor dobjuk, ha a program már inicializálta a konzolt, de azt mégegyszer megtenné a program.
class AlreadyInitializedConsoleException : public std::exception{ };
/// @brief Akkor dobjuk, ha a program érvénytelen méretet szeretne valamelyik komponensnek beállítani
class InvalidSizeConsoleException : public std::exception{ };

/// @brief A szabványos kimenetre írást felügyelő osztály. A program semelyik más
/// része nem írhat és olvashat a konzolról. Ncurses könyvtárbeli függvényeket is
/// csak ez az osztály hívhat meg.
/// @throws std::exception, ha példányosítani próbáljuk
class Console {
private:
    /// @brief Inicializáltuk-e a konzolt az `init` fv. meghívásával
    static bool initialized;
    /// @brief A program interaktív módban fut-e. (használja-e az ncurses könyvtárat)
    static bool tui;
    /// @brief Ha a program nem interaktív módban fut, megmondja hogy mekkora
    /// területre írhat ki
    static Rect<size_t> noninteractiveConsoleSize;
    /// @brief A kimenet, melyere az összes függvény ír
    static std::ostream* out;

public:
// Thank you memtrace.h, for having a delete macro -_-
#ifndef MEMTRACE
    Console() = delete;
#else
    Console() { throw std::exception(); } // Cannot Instantiate static class
#endif

private:
    /// @brief Inicializálja a Ncurses könyvtárat.
    /// A függvény inicializálja az Ncurses könyvtárat, beállítja a billentyűzet kezelést, a színeket és a kimeneti módot.
    /// Továbbá, beállítja az alapértelmezett színpárokat, ha a terminál támogatja a színeket. A konzol ezután törlődik.
    static void initNcurses();

public:
    /// @brief Inicializálja a konzolt.
    /// Ez a függvény előkészíti a konzolt a használatra. Ha a program interaktív
    /// módban fut, akkor meghívja az ncurses függvényeit.
    /// @throws AlreadyInitializedConsoleException Ha a konzol már egyszer inicializálva lett.
    static void init();

    /// @brief A konzol erőforrásainak felszabadítása. 
    /// Ez a függvény befejezi a konzolhasználatot, törli a képernyőt és
    /// lezárja a terminál kezelést (ncurses könyvtártból visszatér).
    /// @throws UnInitializedConsoleException Ha a konzol még nem lett inicializálva.
    static void destroy();
    
    static bool getTUI();
    static void setTUI(bool tui);

    static int getHeight();
    static int getWidth();

    static void setHeight(size_t h);    //Only in non tui mode
    static void setWidth(size_t w);     //Only in non tui mode

    /// @brief Bekér egy adott hosszúságú szöveget a felhasználótól.
    /// Ez a függvény legfeljebb `l` hosszúságú bemenetet olvas be a felhasználótól.
    /// TUI módban az ncurses `getnstr` függvényét használja,
    /// egyébként a szabványos bemenetről olvas `std::getline` segítségével.
    /// @param l A beolvasandó karakterek maximális száma.
    /// @return A beolvasott szöveg.
    /// @throws UnInitializedConsoleException ha a konzol nincs inicializálva.
    /// @note Ha nem TUI módban EOF érkezik, a program kilép.
    static std::string getInputOfLength(int l);

    /// @brief A kurzor mozgatása a megadott (x, y) pozícióra.
    /// A függvény a kurzort áthelyezi a megadott koordinátákra, ha a konzol inicializálva van.
    /// @note Csak TUI módban működik.
    /// @param x Az oszlop pozíció (vízszintes koordináta).
    /// @param y A sor pozíció (függőleges koordináta).
    /// @throws UnInitializedConsoleException ha a konzol nincs inicializálva.
    static void moveCursor(int x, int y);

    /// @brief Szöveg kiírása a megadott pozícióra.
    /// A megadott szöveget kiírja a (x, y) koordinátára TUI módban.
    /// Ha nem TUI módban van, akkor a szöveget a kimeneti adatfolyamba írja új sorral.
    /// @param x Az oszlop pozíció (vízszintes koordináta).
    /// @param y A sor pozíció (függőleges koordináta).
    /// @param str A kiírandó szöveg.
    /// @throws UnInitializedConsoleException ha a konzol nincs inicializálva.
    static void Print(int x, int y, const wchar_t* str);

    /// @brief Szöveg kiírása a megadott pozícióra.
    /// A megadott szöveget kiírja a (x, y) koordinátára TUI módban.
    /// Ha nem TUI módban van, akkor a szöveget a kimeneti adatfolyamba írja új sorral.
    /// @param x Az oszlop pozíció (vízszintes koordináta).
    /// @param y A sor pozíció (függőleges koordináta).
    /// @param str A kiírandó szöveg.
    /// @throws UnInitializedConsoleException ha a konzol nincs inicializálva.
    static void Print(int x, int y, const char* str);

    /// @brief Átirányítja a kimenetet egy új adatfolyamra.
    /// Ezzel a funkcióval beállítható egy új kimeneti adatfolyam.
    /// Az összes további kimenet az új adatfolyamba lesz irányítva.
    /// @param newOut Az új adatfolyam, amelyre a kimenet irányítva lesz.
    static void RedirectOutput(std::ostream& newOut);

    /// @brief Beállítja a színt a konzolon.
    /// A függvény beállítja a konzol színét a megadott `color` értékre.
    /// Ha a terminál nem támogatja a színeket, a függvény nem hajt végre semmilyen műveletet.
    /// @param color A beállítandó szín, amelyet a `CONSOLECOLOR` típus reprezentál.
    static void setColor(CONSOLECOLOR color = WHITE);

    /// @brief Kiüríti a kimenetet, frissíti a terminált.
    /// A függvény frissíti a konzolt, ha a `tui` mód engedélyezve van.
    /// @throws UnInitializedConsoleException Ha a konzol nincs inicializálva
    static void flush();

    /// @brief Törli a képernyőt.
    /// A függvény törli a képernyőt, ha a `tui` mód engedélyezve van.
    /// @throws UnInitializedConsoleException Ha a konzol nincs inicializálva
    static void Clear();

    /// @brief Törli a kijelölt területet a képernyőn.
    /// A függvény törli a képernyőn az adott (x, y) pozíciótól kezdődően a megadott szélességű (w) és magasságú (h) területet.
    /// @param x A terület bal felső sarkának vízszintes koordinátája.
    /// @param y A terület bal felső sarkának függőleges koordinátája.
    /// @param w A törlendő terület szélessége.
    /// @param h A törlendő terület magassága.
    /// @throws UnInitializedConsoleException Ha a konzol nincs inicializálva
    static void Clear(int x, int y, int w, int h);
};
