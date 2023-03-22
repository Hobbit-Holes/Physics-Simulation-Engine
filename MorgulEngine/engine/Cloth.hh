#ifndef CLOTH_H
#define CLOTH_H

#include <stdint.h>
#include "Vec2.hh"

class Cloth {
    private: 
        Vec2 gravity;
        float drag;
        float elasticity;

        std::vector<Point*> points;
        std::vector<Stick*> sticks;
    public:
        Cloth() = default;
        ~Cloth();
        void Update();
};

#endif