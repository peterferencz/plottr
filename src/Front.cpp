#include "Front.hpp"


void Front::Draw(){
    const int H = Console::getHeight();
    const int W = Console::getWidth();

if(Console::getTUI()){
    Console::Clear();

    for(int y = 0; y < H; y++){
        for(int x = 0; x < W; x++){
            
            const wchar_t* c = L" ";
            if(x == 0 && y == 0)            { c = L"┌"; } // F
            else if(x == 0 && y == H-1)     { c = L"└"; } // U
            else if(x == W-1 && y == H-1)   { c = L"┘"; } // N
            else if(x == W-1 && y == 0)     { c = L"┐"; } // K
            else if(x == 0 && y == H-3)     { c = L"├"; } // Y
            else if(x == W-1 && y == H-3)   { c = L"┤"; } // 
            else if(y == H-3)               { c = L"─"; } // K
            else if(x == 0 || x == W-1)     { c = L"│"; } // Ó
            else if(y == 0 || y == H-1)     { c = L"─"; } // D
            else { continue; }
            
            Console::Print(x, y, c);
        }
    }

    //Title
    Console::Print((W - 15) / 2, 0, "==[ PlottR ]==");
    // Draw: Subtract frame + input box
    currentDisplay->Draw({1, 1, W-3, H-4});
}else{
    currentDisplay->Draw({0, 0, W, H});
}


    Console::flush();
    // Console::moveCursor(1, Console::getHeight()-2);
}

std::string Front::getInput(){
    Console::moveCursor(1, Console::getHeight()-2);
    std::string s = Console::getInputOfLength(Console::getWidth()-2);

    Console::Clear(1, Console::getHeight() -2, Console::getWidth()-2, 1);    

    return s;
}

void Front::setScreen(Screen& screen){
    currentDisplay = &screen;
}