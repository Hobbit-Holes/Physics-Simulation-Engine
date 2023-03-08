#include "Mouse.hh"

void Mouse::UpdatePosition(int x, int y) {
    prevPos.x = pos.x;
    prevPos.y = pos.y;
    pos.x = x;
    pos.y = y;
}