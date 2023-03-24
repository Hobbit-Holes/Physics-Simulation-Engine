#ifndef MOUSE_H
#define MOUSE_H

#include "Vec2.hh"

struct Mouse
{
    Vec2 pos;
    Vec2 prevPos;
    bool leftButtonPressed = false;
    bool rightButtonPressed = false;

    float maxCursorSize = 100;
	float minCursorSize = 20;

	float cursorSize = 20;

    // Constructor and Deconstructor
    Mouse() = default;
    ~Mouse() = default;

    // Functions
    const Vec2& GetPosition() const { return pos; }
    const Vec2& GetPrevPosition() const { return prevPos; }
    void UpdatePosition(int x, int y);

    void IncreaseCursorSize(float increment);
	float GetCursorSize() const { return cursorSize; }
};

#endif