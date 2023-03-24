#ifndef CLOTH_H
#define CLOTH_H

#include <stdint.h>
#include <vector>
#include "Vec2.hh"
#include "Point.hh"
#include "Stick.hh"

class Cloth {
    private: 
        Vec2 gravity;
        float drag;
        float elasticity;

        std::vector<Point*> points;
        std::vector<Stick*> sticks;
    public:
        Cloth() = default;
        Cloth(int width, int height, int spacing, int startX, int startY);
        ~Cloth();

        void Update(Mouse* mouse, float deltaTime, int width, int height);
        void Draw();
};

#endif