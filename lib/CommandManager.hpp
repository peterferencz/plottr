#pragma once

#include <vector>
#include <array>
#include <string>
#include <istream>
#include <unistd.h>
#include <getopt.h>
#include <cstring>

#include "Command.hpp"
#include "Console.hpp"
#include "Front.hpp"

/// @brief Akkor dobjuk, ha a `ConsoleManager`-ben nem lett regisztrálva a parancs
class UnknownCommandException : public std::exception{ };

/// @brief A `Command` osztályok kezelése, és a felhasználó által megadott parancsok végrehajtását szolgáló osztály.
/// A `CommandManager` osztály felelős a parancsok tárolásáért és kezeléséért.
/// A parancsokat egy heterogén kollekcióban tárolja, és biztosítja azok végrehajtását a felhasználó által adott bemeneti utasítások alapján.
class CommandManager {
private:
    /// @brief `Command`-ok heterogén kollekciója, melyet elfogadunk
    const std::vector<Command*> commands;


public:
    CommandManager(const std::initializer_list<Command*>& commands) : commands(commands) {}
    ~CommandManager();

    /// @brief Parancsot kér a felhasználótól, melyet ha tud futtat is
    /// @param ui Az adott felület, ahonnan a parancsot kéri
    /// @return Megmondja, hogy a felhasználó ki akar-e lépni a programból (false: igen, true: nem)
    /// @throw UnknownCommandException, ha a `commands` nem tartalmazza a prancsot.
    bool CaptureInput(Front ui);

    /// @brief Parancssori kapcsolókat dolgoz fel, melyeket a bekérés sorrendjében futtat is
    /// @param argc A `argv` elemeinek száma
    /// @param argv C-sztringek a kapcsolókra
    /// @throw UnknownCommandException, ha a `commands` nem tartalmazza a prancsot.
    void parseCLA(size_t argc, char** argv);

private:
    /// @brief Adott sort tördel fel, és adja vissza azokat egy sztring vektorban
    /// @param line A feltördelendő sor
    /// @return A feltördelt sor
    std::vector<std::string> parseCommand(const std::string& line);
};