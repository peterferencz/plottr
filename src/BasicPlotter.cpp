#include "BasicPlotter.hpp"

void BasicPlotter::Draw(Rect<int> consoleArea, Rect<double> worldArea) const{
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