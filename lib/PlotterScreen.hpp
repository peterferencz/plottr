#pragma once 

#include <cmath>

#include "Expression.hpp"
#include "Console.hpp"
#include "Screen.h"
#include "Plotter.hpp"
#include "Rect.h"
#include "BasicPlotter.hpp"
#include "ASCIIPlotter.hpp"

/// @brief A grafikon kirajzolásáért felelős képernyő.
/// A PlotterScreen osztály kezeli a kirajzolt világ, a hozzá tartozó kifejezést,
/// valamint a Plotter példányt, amely a tényleges kirajzolást végzi.
class PlotterScreen : public Screen {
private:
    /// @brief A kirajzolandó kifejezés.
    Expression& exp;
    /// @brief A kirajzolásért felelős objektum.
    Plotter* plotter;

    /// @brief A világterület, amely meghatározza, mit látunk a grafikonból.
    Rect<double> worldArea;

public:
    PlotterScreen(Expression& exp, Plotter* plotter);
    
    Rect<double> getWorldArea() const;
    const Plotter* getPlotter() const;

    /// @brief A világterület abszolút pozíciójának beállítása.
    /// @param x Az új bal szélső x-koordináta.
    /// @param y Az új alsó y-koordináta.
    void Move(double x, double y);
    
    /// @brief A világterület relatív eltolása.
    /// @param dx Eltolás x irányban.
    /// @param dy Eltolás y irányban.
    void Offset(double dx, double dy);

    /// @brief A világterület méretének (léptékének) beállítása.
    /// @param w Új szélesség.
    /// @param h Új magasság.
    void Scale(double w, double h);
    
    
    /// @brief Kirajzolás végrehajtása a konzol adott területére.
    /// @param consoleArea A konzol terület, amelyre rajzolunk.
    void Draw(Rect<int> consoleArea) const;

    void setPlotter(Plotter* plotter);
};