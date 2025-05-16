#pragma once

#include <string>
#include <vector>
#include <array>
#include <string_view>

/// @brief A felhasználó által adott parancsok ősosztálya.
/// Ez az osztály az összes parancs alapja, amelyet a felhasználó futtathat. 
/// A parancsokat az osztály név és rövid név alapján azonosítjuk. 
/// Az osztály az argumentumok számát is tárolja, és meghatározza, hogy hány paramétert fogad el egy parancs.
/// A parancsokat egy `exec` virtuális metódus segítségével lehet végrehajtani.
class Command {
private:
    /// @brief A név, amellyel a felhasználó kiválasztja melyik parancsot futtatja
    const char* name;
    /// @brief Olyan mint `name`, csak egy karakterrel
    const char shortName;
    // paramCount of -1 resembles any number of arguments
    
    /// @brief A parancsnak adható paraméterek száma.
    /// @note Ha -1, akkor bármennyi paraméterrel hívható
    const int paramCount;


public:
    /// @brief Konstruktor, amely beállítja a parancs nevét, rövid nevét és paraméterek számát.
    /// @param name A parancs neve
    /// @param shortName A parancs rövid neve
    /// @param paramCount A parancsnak adható paraméterek száma (-1 ha bármennyi paramétert elfogad)
    Command(const char* name, const char shortName, const int paramCount) 
    : name(name), shortName(shortName), paramCount(paramCount) { }
    virtual ~Command() = default;

    virtual const char* getName() const { return name; }
    virtual char getShortName() const { return shortName; }
    virtual int getParamCount() const { return paramCount; }

    /// @brief Végrehajtja a parancsot.
    /// @param params A felhasználó által a parancsnak adott paraméterek
    virtual void exec(const std::vector<std::string>& params) = 0;
};


