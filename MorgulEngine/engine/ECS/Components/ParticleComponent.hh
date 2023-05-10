#ifndef PARTICLECOMPONENT_H
#define PARTICLECOMPONENT_H

#include "Vec2.hh"
#include "Color.hh"

struct ParticleComponent {
    float mass;
    float invMass;      // 1 / mass

    float angle;        // Rotation of the particle
    int radius;         // Radius of the particle
    Color color;        // Color of the particle
    Vec2 sumForces;
    bool render;        // If we want to render it

    ParticleComponent(float mass = 1, int radius = 1, Color color = Color::White(), bool render = true, float angle = 0) {
        this->mass = mass;
        if (mass != 0) {
            this->invMass = 1 / mass;
        } else {
            this->invMass = 0;
        }

        this->radius = radius;
        this->color = color;
        this->sumForces = Vec2(0, 0);
        this->render = render;
        this->angle = angle;
    }

    void AddForce(Vec2 force) {
        sumForces += force;
    }

    void ClearForces() {
        sumForces = Vec2(0, 0);
    }
};

#endif