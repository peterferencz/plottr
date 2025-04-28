#pragma once

#include "Rect.h"

class Screen {
private:
    

public:
    // Screen(/* args */);
    // virtual ~Screen();

    // virtual void Show();
    // virtual void Hide();
    virtual void Draw(Rect<int> consoleArea) const = 0;
};


