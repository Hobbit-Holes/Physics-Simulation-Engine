#include "Mouse.hh"

void Mouse::UpdatePosition(int x, int y) {
    prevPos.x = pos.x;
    prevPos.y = pos.y;
    pos.x = x;
    pos.y = y;
}

void Mouse::IncreaseCursorSize(float increment)
{
    if(cursorSize + increment > maxCursorSize || cursorSize + increment < minCursorSize) 
        return;

    cursorSize += increment;
}