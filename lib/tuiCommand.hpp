#pragma once

#include "Command.hpp"

/// @brief A parancs, amely ki- vagy bekapcsolja a szöveges felhasználói felületet (TUI).
/// Ezzel a paranccsal a felhasználó be- vagy kikapcsolhatja a TUI megjelenítést.
/// Ha a TUI engedélyezve van, akkor keretek és fejlécek jelennek meg; ha nem, akkor
/// nyers konzolra történik a rajzolás
class TUICommand : public Command {
public:
    TUICommand() : Command("tui", 't', 0) {}
    ~TUICommand() {}

    /// @brief Végrehajtja a TUI mód be- vagy kikapcsolását.
    /// A `Console` osztály statikus metódusát használja az aktuális állapot lekérdezésére
    /// és annak megfordítására.
    /// @param params Nincs paramétere.
    void exec(const std::vector<std::string>& params);
};