#include "Plotter.hpp"

Plotter::Plotter(Expression& exp)
: exp(exp) {
    int w = Console::getWidth()-2;
    int h = Console::getHeight()-4;
    Scale(w, h);
    // Offset(- w / 2, - h / 2);
}

void Plotter::Draw(int x, int y, int w, int h) const {
#pragma region Axes
    Console::setColor(CONSOLECOLOR::YELLOW);
    for(int sx = x; sx <= x + w; sx ++) {
        
        // double wx = ((double)sx - x) / w * xWidth - xOffset;
        double wy = 0;
        double sy = (((wy - yOffset) / yWidth) * (-1) + 1) * (y+h);

        if(sy >= y && sy <= y + h){
            Console::Print(sx, sy, L"─");
        }
    }
    for(int sy = y; sy <= y + h; sy ++) {
        // double wy = ((sy - y) / h * (-1) + 1) * yWidth + yOffset;
        double wx = 0;
        double sx = (wx - xOffset) / xWidth * w + x;
        // double sy = (((wy - yOffset) / yWidth) * (-1) + 1) * (y+h);

        if(sx >= x && sx < sx+w){
            Console::Print(sx, sy, L"│");
        }
    }

    double sx = (0 - xOffset) / xWidth * w + x;
    double sy = (((0 - yOffset) / yWidth) * (-1) + 1) * (y+h);
    if(sx >= x && sx < sx+w && sy >= y && sy <= y + h){
        Console::Print(sx, sy, L"┼");
    }
    Console::flush();
#pragma endregion
    
    Console::setColor(CYAN);
    
    double xSteps = xWidth / w;
    double ySteps = yWidth / h;
    
    for(int sx = x; sx <= x + w; sx ++) {
        
        double wx = ((double)sx - x) / w * xWidth + xOffset;
        double wy = exp.valueAt(wx);
        double sy = (((wy - yOffset) / yWidth) * (-1) + 1) * (y+h);
        sy = round(sy);

        // Constrain to bounds
        if(sy >= y && sy <= y+h){
            Console::Print(sx, sy, "*");
        }
    }

    Console::flush();


    

    Console::setColor();
}

void Plotter::Move(double x, double y) {
    xOffset = x;
    yOffset = y;
}

void Plotter::Offset(double dx, double dy){
    xOffset += dx;
    yOffset += dy;
}

void Plotter::Scale(double xw, double yw) {
    xWidth = xw;
    yWidth = yw;
}
