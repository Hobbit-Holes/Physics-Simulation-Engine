#ifndef MOUSE_H
#define MOUSE_H

#include "Vec2.hh"

struct Mouse
{
    Vec2 pos;
    Vec2 prevPos;
    bool leftButtonPressed = false;
    bool rightButtonPressed = false;

    // Constructor and Deconstructor
    Mouse() = default;
    ~Mouse() = default;

    // Functions
    const Vec2& GetPosition() const { return pos; }
    const Vec2& GetPrevPosition() const { return prevPos; }
    void UpdatePosition(int x, int y);
};

#endif