#ifndef MOUSE_H
#define MOUSE_H

struct Mouse
{
    bool leftButtonPressed = false;
    bool rightButtonPressed = false;

    // Constructor and Deconstructor
    Mouse() = default;
    ~Mouse() = default;
};

#endif