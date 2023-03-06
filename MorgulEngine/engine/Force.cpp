#include "Force.hh"

Vec2 Force::GenerateDragVector(float k, Vec2 velocity) {
    return Vec2(0, 0);
}

Vec2 Force::GenerateFrictionVector(float k, Vec2 v) {
    return Vec2(0, 0);
}

Vec2 Force::GenerateGravitationalVector(Vec2 positionA, Vec2 positionB, float massA, float massB, float G, float minDistance, float maxDistance) {
    return Vec2(0, 0);
}

Vec2 Force::GenerateSpringVector(float k, Vec2 position, Vec2 anchor, Vec2 restLength) {
    return Vec2(0, 0);
}

Vec2 Force::GenerateMagnusVector(float k, Vec2 velocity, float angularVelocity) {
    return Vec2(0, 0);
}

