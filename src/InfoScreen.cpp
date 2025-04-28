#include "InfoScreen.hpp"


void InfoScreen::Draw(Rect<int> consoleArea) const {
    Console::Print(consoleArea.x, consoleArea.y, "Currently plotting:");
    std::pair<double*, size_t> arr = exp.getCoefficients();


    std::ostringstream oss;
    for(size_t i = 0; i < arr.second; i++){
        oss << arr.first[i] << " * X^" << i;

        if(i != arr.second-1){
            oss << " + ";
        }
    }
    
    Console::Print(consoleArea.x, consoleArea.y+1, oss.str().c_str());
    Console::flush();
}