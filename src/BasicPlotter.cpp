#include "BasicPlotter.hpp"

void BasicPlotter::Draw(Rect<int> consoleArea, Rect<double> worldArea) const{
    Console::setColor(CYAN);
    
    // double xSteps = worldArea.w / consoleArea.w;
    // double ySteps = worldArea.h / consoleArea.h;

    char** lines = new char*[consoleArea.h];
    for(int i = 0; i < consoleArea.h; i++){
        lines[i] = new char[consoleArea.w+1];
        for(int j = 0; j < consoleArea.w; j++){
            lines[i][j] = '.';
        }
        lines[i][consoleArea.w] = '\0';
    }

    for(int i = 0; i < consoleArea.w; i++){
        double wx = ((double)i) / consoleArea.w * worldArea.w + worldArea.x;
        double wy = this->exp.valueAt(wx);
        //TODO rounding errors
        int sy = (int)round((((wy - worldArea.y) / worldArea.h) * (-1) + 1) * (consoleArea.y+consoleArea.h)) - consoleArea.y;

        if(sy >= 0 && sy < consoleArea.h){
            lines[sy][i] = '*';
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