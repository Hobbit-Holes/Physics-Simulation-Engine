#ifndef KINEMATICCOMPONENT_H
#define KINEMATICCOMPONENT_H

#include "Vec2.hh"

struct KinematicComponent {
    Vec2 velocity;
    Vec2 acceleration;

    KinematicComponent(Vec2 velocity = Vec2(0,0), Vec2 acceleration = Vec2(0,0)) {
        this->velocity = velocity;
        this->acceleration = acceleration;
    }
};

#endif