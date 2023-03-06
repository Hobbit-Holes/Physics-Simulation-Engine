#ifndef FORCE_H
#define FORCE_H

#include "Vec2.hh"

struct Force {
    static Vec2 GenerateDragVector(float k, Vec2 v);
    static Vec2 GenerateFrictionVector(float k, Vec2 v);
    static Vec2 GenerateGravitationalVector(Vec2 positionA, Vec2 positionB, float massA, float massB, float G, float minDistance, float maxDistance);
    static Vec2 GenerateSpringVector(float k, Vec2 position, Vec2 anchor, float restLength);
    static Vec2 GenerateMagnusVector(float k, Vec2 velocity, float angularVelocity);
};

#endif