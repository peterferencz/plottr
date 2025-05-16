#include "ASCIIPlotter.hpp"

void ASCIIPlotter::Draw(Rect<int> consoleArea, Rect<double> worldArea) const{
//     Console::setColor(CONSOLECOLOR::YELLOW);
//     DrawAxes(consoleArea, worldArea);
//     Console::flush();

//     Console::setColor(CYAN);

//     // double xSteps = worldArea.w / consoleArea.w;
//     // double ySteps = worldArea.h / consoleArea.h;
    
//     for(int sx = consoleArea.x; sx <= consoleArea.x + consoleArea.w; sx ++) {
        
//         double wx = ((double)sx - consoleArea.x) / consoleArea.w * worldArea.w + worldArea.x;
//         double wy = this->exp.valueAt(wx);
//         double sy = (((wy - worldArea.y) / worldArea.h) * (-1) + 1) * (consoleArea.y+consoleArea.h);
//         sy = round(sy);

//         // Constrain to bounds
//         if(sy >= consoleArea.y && sy <= consoleArea.y+consoleArea.h){
//             Console::Print(sx, sy, "*");
//         }
//     }

//     Console::flush();
// }

// void ASCIIPlotter::DrawAxes(Rect<int> consoleArea, Rect<double> worldArea) const {
//     for(int sx = consoleArea.x; sx <= consoleArea.x + consoleArea.w; sx ++) {
        
//         // double wx = ((double)sx - x) / w * xWidth - xOffset;
//         double wy = 0;
//         double sy = (((wy - worldArea.y) / worldArea.h) * (-1) + 1) * (consoleArea.y+consoleArea.h);

//         if(sy >= consoleArea.y && sy <= consoleArea.y + consoleArea.h){
//             Console::Print(sx, sy, "-");
//         }
//     }
//     for(int sy = consoleArea.y; sy <= consoleArea.y + consoleArea.h; sy ++) {
//         // double wy = ((sy - y) / h * (-1) + 1) * yWidth + yOffset;
//         double wx = 0;
//         double sx = (wx - worldArea.x) / worldArea.w * consoleArea.w + consoleArea.x;
//         // double sy = (((wy - yOffset) / yWidth) * (-1) + 1) * (y+h);

//         if(sx >= consoleArea.x && sx < sx+consoleArea.w){
//             Console::Print(sx, sy, "|");
//         }
//     }

//     double sx = (0 - worldArea.x) / worldArea.w * consoleArea.w + consoleArea.x;
//     double sy = (((0 - worldArea.y) / worldArea.h) * (-1) + 1) * (consoleArea.y+consoleArea.h);
//     if(sx >= consoleArea.x && sx < sx+consoleArea.w && sy >= consoleArea.y && sy <= consoleArea.y + consoleArea.h){
//         Console::Print(sx, sy, "0");
//     }

    //TODO finish this pls
    Console::setColor(CYAN);
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

    
    for(int sx = 0; sx < consoleArea.w; sx++){
        double wx = worldArea.x + (double(sx) / (consoleArea.w - 1)) * worldArea.w;
        double wy = exp.valueAt(wx);
        int sy = static_cast<int>((1.0 - ((wy - worldArea.y) / worldArea.h)) * (consoleArea.h - 1));

        if(sy >= 0 && sy < consoleArea.h){
            lines[sy][sx] = Plotter::dot;
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