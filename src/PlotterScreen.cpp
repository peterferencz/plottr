#include "PlotterScreen.hpp"

PlotterScreen::PlotterScreen(Expression& exp, Plotter* plotter)
: exp(exp), plotter(plotter) {
    int w = Console::getWidth()-2;
    int h = Console::getHeight()-4;
    Scale(w, h);
    // Offset(- w / 2, - h / 2);
}

void PlotterScreen::Draw(Rect<int> consoleArea) const {
    plotter->Draw(consoleArea, worldArea);

    Console::setColor();
}

void PlotterScreen::Move(double x, double y) {
    worldArea.x = x;
    worldArea.y = y;
}

void PlotterScreen::Offset(double dx, double dy){
    worldArea.x += dx;
    worldArea.y += dy;
}

void PlotterScreen::Scale(double w, double h) {
    worldArea.w = w;
    worldArea.h = h;
}


void PlotterScreen::setPlotter(Plotter* plotter) {
    this->plotter = plotter;
}