#include <algorithm>
#include <math.h>

#include "Force.hh"
# define M_PI           3.14159265358979323846  /* pi */

Vec2 Force::GenerateDragVector(float k, Vec2 v) {
    Vec2 dragForce = Vec2(0, 0);

    if (v.MagnitudeSquared() > 0) {
        Vec2 dragDirection = v.UnitVector() * -1;
        float dragMagnitude = k * v.MagnitudeSquared();
        dragForce = dragDirection * dragMagnitude;
    }

    return dragForce;
}

Vec2 Force::GenerateFrictionVector(float k, Vec2 v) {
    Vec2 frictionForce = Vec2(0, 0);

    if (v.Magnitude() > 1) {
        Vec2 frictionDirection = v.UnitVector() * -1;
        float frictionMagnitude = k;
        frictionForce = frictionDirection * frictionMagnitude;
    }

    return frictionForce;
}

float Force::GenerateFrictionRotation(float k, float rotation) {
    float frictionForce = 0;

    if (rotation != 0) {
        float frictionDirection = rotation * -1;
        float frictionMagnitude = k;
        frictionForce = frictionDirection * frictionMagnitude;
    }

    return frictionForce;
}

Vec2 Force::GenerateGravitationalVector(Vec2 positionA, Vec2 positionB, float massA, float massB, float G, float minDistance, float maxDistance) {
    // Distance between the objects
    Vec2 distance = positionB - positionA;
    float distanceSquared = std::clamp(distanceSquared, minDistance, maxDistance);
    
    // Direction of the force
    Vec2 attractionDirection = distance.UnitVector();

    // Strength of the force
    float attractionMagnitude = G * (massA * massB) / distanceSquared;

    // Final force
    Vec2 attractionForce = attractionDirection * attractionMagnitude;
    return attractionForce;
}

Vec2 Force::GenerateSpringVector(float k, Vec2 position, Vec2 anchor, float restLength) {
    // Distance between the obejcts
    Vec2 distance = position - anchor;

    // Spring displacement
    float displacement = distance.Magnitude() - restLength;

    // Direction of the force
    Vec2 springDirection = distance.UnitVector();

    // Magnitude of the force
    float springMagnitude = -k * displacement;
    
    // Final force
    Vec2 springForce = springDirection * springMagnitude;    
    return springForce;
}

Vec2 Force::GenerateMagnusVector(float k, Vec2 velocity, float angularVelocity) {
    Vec2 magnusForce = Vec2(0, 0);
    if(velocity.MagnitudeSquared() > 0) {
        Vec2 normalVelocity = velocity.Normal();
        Vec2 unitVector = normalVelocity.UnitVector();
        float magnusMagnitude = k * velocity.MagnitudeSquared();
        magnusForce = unitVector * magnusMagnitude * angularVelocity * 2;
    }

    return magnusForce;
}

