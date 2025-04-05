#pragma once

class Screen {
private:
    

public:
    // Screen(/* args */);
    // virtual ~Screen();

    // virtual void Show();
    // virtual void Hide();
    virtual void Draw(int x, int y, int w, int h) const = 0;
};


