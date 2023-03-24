#ifndef CLOTH_H
#define CLOTH_H

#include <stdint.h>
#include <vector>
#include "Vec2.hh"
#include "Point.hh"
#include "Stick.hh"

class Cloth {
    private: 
        Vec2 gravity = { 0.0f, 981.0f };
	    float drag = 0.01f;
	    float elasticity = 10.0f;

        std::vector<Point*> points;
        std::vector<Stick*> sticks;

    public:
        Cloth() = default;
        Cloth(int width, int height, int spacing, int startX, int startY);
        ~Cloth();

        void Update(Mouse* mouse, double deltaTime, int width, int height);
        void Draw();
};

#endif