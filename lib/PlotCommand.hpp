#pragma once

#include <vector>
#include <string>

#include "Command.hpp"
#include "InfoScreen.hpp"
#include "Front.hpp"

/// @brief Parancs, amely beállítja a kirajzolandó polinomot és átvált a grafikon nézetre.
/// A PlotCommand lehetővé teszi új polinom kifejezés beállítását a megadott
/// együtthatók alapján, valamint átvált a grafikon megjelenítésére szolgáló képernyőre.
class PlotCommand : public Command {
private:
    /// @brief A kezelőfelület referenciája.
    Front& ui;
    /// @brief A megjelenítésre szolgáló képernyő, ahol a grafikon látható.
    PlotterScreen& screen;
    /// @brief A polinom kifejezést reprezentáló objektum, amelyet frissítünk.
    Expression& exp;

public:
    PlotCommand(Front& ui, PlotterScreen& info, Expression& exp)
    : Command("plot", 'p', -1), ui(ui), screen(info), exp(exp) {}
    ~PlotCommand() {}

    /// @brief A parancs végrehajtása, amely új polinomot állít be.
    /// Ha nem adunk meg paramétert, csak átvált a nézetre anélkül, hogy módosítaná
    /// a jelenlegi polinomot.
    /// @param params Együtthatók tömbje karakterláncként (string), amiket double-é konvertál.
    /// @throws std::invalid_argument Ha valamelyik paraméter nem alakítható át double típusra.
    void exec(const std::vector<std::string>& params);
};