#ifndef SHIPMOVEMENTCOMPONENT_H
#define SHIPMOVEMENTCOMPONENT_H

struct ShipMovementComponent {
    Vec2 force;
    float torque;
    float maxVelocity;
    float maxRotation;

    ShipMovementComponent(Vec2 force, float torque, float maxVelocity, float maxRotation) {
        this->force = force;
        this->torque = torque;
        this->maxVelocity = maxVelocity;
        this->maxRotation = maxRotation;
    }
};

#endif