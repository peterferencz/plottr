#include "UnicodePlotter.hpp"

void UnicodePlotter::Draw(Rect<int> consoleArea, Rect<double> worldArea) const{
    Console::setColor(YELLOW);
    DrawAxes(consoleArea, worldArea);
    Console::flush();
    Console::setColor(CYAN);
    
    // double xSteps = worldArea.w / consoleArea.w;
    // double ySteps = worldArea.h / consoleArea.h;
    
    for(int sx = consoleArea.x; sx <= consoleArea.x + consoleArea.w; sx ++) {
        
        double wx = ((double)sx - consoleArea.x) / consoleArea.w * worldArea.w + worldArea.x;
        double wy = this->exp.valueAt(wx);
        double sy = (((wy - worldArea.y) / worldArea.h) * (-1) + 1) * (consoleArea.y+consoleArea.h);
        sy = round(sy);

        // Constrain to bounds
        if(sy >= consoleArea.y && sy <= consoleArea.y+consoleArea.h){
            Console::Print(sx, sy, "*");
        }
    }

    Console::flush();
}

void UnicodePlotter::DrawAxes(Rect<int> consoleArea, Rect<double> worldArea) const {
    for(int sx = consoleArea.x; sx <= consoleArea.x + consoleArea.w; sx ++) {
        
        // double wx = ((double)sx - x) / w * xWidth - xOffset;
        double wy = 0;
        double sy = (((wy - worldArea.y) / worldArea.h) * (-1) + 1) * (consoleArea.y+consoleArea.h);

        if(sy >= consoleArea.y && sy <= consoleArea.y + consoleArea.h){
            Console::Print(sx, sy, L"─");
        }
    }
    for(int sy = consoleArea.y; sy <= consoleArea.y + consoleArea.h; sy ++) {
        // double wy = ((sy - y) / h * (-1) + 1) * yWidth + yOffset;
        double wx = 0;
        double sx = (wx - worldArea.x) / worldArea.w * consoleArea.w + consoleArea.x;
        // double sy = (((wy - yOffset) / yWidth) * (-1) + 1) * (y+h);

        if(sx >= consoleArea.x && sx < sx+consoleArea.w){
            Console::Print(sx, sy, L"│");
        }
    }

    double sx = (0 - worldArea.x) / worldArea.w * consoleArea.w + consoleArea.x;
    double sy = (((0 - worldArea.y) / worldArea.h) * (-1) + 1) * (consoleArea.y+consoleArea.h);
    if(sx >= consoleArea.x && sx < sx+consoleArea.w && sy >= consoleArea.y && sy <= consoleArea.y + consoleArea.h){
        Console::Print(sx, sy, L"┼");
    }
}