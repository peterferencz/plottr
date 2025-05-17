#include "ASCIIPlotter.hpp"

void ASCIIPlotter::Draw(Rect<int> consoleArea, Rect<double> worldArea) const{
    worldArea.x -= worldArea.w / 2;
    worldArea.y -= worldArea.h / 2;

    char** lines = new char*[consoleArea.h] {nullptr};
    for(int i = 0; i < consoleArea.h; i++){
        lines[i] = new char[consoleArea.w+1]; //+1 for terminating '\0'
        for(int j = 0; j < consoleArea.w; j++){
            lines[i][j] = ' ';
        }
        lines[i][consoleArea.w] = '\0';
    }

    DrawAxes(consoleArea, worldArea, lines);
    
    // Plotting of function
    int prevSy = -1;
    int prevSx = -1;

    Console::setColor(CYAN);
    for(int sx = 0; sx < consoleArea.w; sx++){
        double wx = worldArea.x + (double(sx) / (consoleArea.w - 1)) * worldArea.w;
        double wy = exp.valueAt(wx);
        int sy = static_cast<int>((1.0 - ((wy - worldArea.y) / worldArea.h)) * (consoleArea.h - 1));


        if (sy >= 0 && sy < consoleArea.h) {
            lines[sy][sx] = Plotter::dot;

            if (prevSx != -1 && prevSy != -1) {
                InterpolateDraw(consoleArea, lines, Rect<int>{prevSx, prevSy, sx, sy});
            }

            prevSx = sx;
            prevSy = sy;
        } else {
            prevSx = prevSy = -1; // reset connection
        }
    }

    for(int i = 0; i < consoleArea.h; i++){
        Console::Print(consoleArea.x, i + consoleArea.y, lines[i]);
    }

    for(int i = 0; i < consoleArea.h; i++){
        delete[] lines[i];
    }
    delete[] lines;

    Console::flush();
}


/// @brief Kirajzolja az X és Y tengelyeket az ASCII karakterekből álló diagramra.
/// A megadott világkoordináta-rendszer (`worldArea`) és konzolkoordináta-rendszer (`consoleArea`) 
/// alapján kiszámolja és elhelyezi az X és Y tengelyeket a `lines` karaktertömbben. 
/// Csak akkor rajzol tengelyt, ha az adott tengely a megjelenített világterületen belül van.
/// @note Nem dob kivételt. (Nincs explicit kivételkezelés, de a tömbök érvényességét feltételezi.)
/// @param consoleArea A konzol területe karakterkoordinátában, amelyre a tengelyeket kell rajzolni.
/// @param worldArea A világkoordináta-rendszer területe, amelyet a konzolterületre vetítünk.
/// @param lines Egy kétdimenziós karaktertömb, amely a konzol képernyőjét reprezentálja. A tengelyek ebbe lesznek belerajzolva.
void ASCIIPlotter::DrawAxes(Rect<int> consoleArea, Rect<double> worldArea, char** lines) const{
    //FIXME not compatible with buffer
    Console::setColor(YELLOW);
    // Y-axis
    if (worldArea.x <= 0 && (worldArea.x + worldArea.w) >= 0) {
        int axisX = static_cast<int>(((0 - worldArea.x) / worldArea.w) * (consoleArea.w - 1));
        for (int i = 0; i < consoleArea.h; i++) {
            lines[i][axisX] = '|';
        }
    }

    // X-axis
    if (worldArea.y <= 0 && (worldArea.y + worldArea.h) >= 0) {
        int axisY = static_cast<int>((1.0 - ((0 - worldArea.y) / worldArea.h)) * (consoleArea.h - 1));
        if (axisY >= 0 && axisY < consoleArea.h) {
            for (int j = 0; j < consoleArea.w; j++) {
                lines[axisY][j] = '-';
            }
        }
    }
}

/// @brief Két pont között interpolálva rajzol összekötő vonalat ASCII karakterekkel.
/// A megadott konzolterületen belül két pont (az `interpol` téglalap bal-felső és jobb-alsó sarka) között
/// lépésenként haladva kirajzol egy vonalat. A megfelelő karakter (`-`, `|`, `/`, `\`) választása a vonal irányától függ.
/// @note Ez a függvény csak a vizuális összekötés céljából használatos, nem végez matematikai interpolációt.
/// A `lines` tömbben történik a tényleges módosítás.
/// @note Nem dob kivételt, de feltételezi, hogy a `lines` tömb érvényes és a koordináták határon belül vannak.
/// @param consoleArea A konzol rajzterülete karakterkoordinátában.
/// @param lines A kétdimenziós karaktertömb, amely a képernyő tartalmát reprezentálja.
/// @param interpol Egy téglalap, melynek bal-felső (`x`,`y`) és jobb-alsó (`w`,`h`) pontját köti össze a függvény.
void ASCIIPlotter::InterpolateDraw(Rect<int> consoleArea, char** lines, Rect<int> interpol) const{
    int dx = interpol.w - interpol.x;
    int dy = interpol.h - interpol.y;

    int steps = std::max(std::abs(dx), std::abs(dy));
    for (int step = 1; step < steps; ++step) {
        int xi = interpol.x + (dx * step) / steps;
        int yi = interpol.y + (dy * step) / steps;

        if (xi >= 0 && xi < consoleArea.w && yi >= 0 && yi < consoleArea.h) {
            char connector = '|';
            if (dy == 0) {
                connector = '-';
            } else if (dy < 0) {
                connector = '/';
            } else if (dy > 0) {
                connector = '\\';
            }

            lines[yi][xi] = connector;
        }
    }
}