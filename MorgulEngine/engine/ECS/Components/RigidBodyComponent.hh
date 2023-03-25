#ifndef RIGIDBODYCOMPONENT_H
#define RIGIDBODYCOMPONENT_H

#include "../../Shape.hh"
#include "../../CircleShape.hh"
#include "../../PolygonShape.hh"
#include "../../RegularPolygonShape.hh"
#include "../../RectangleShape.hh"
#include "../../StarShape.hh"

struct RigidBodyComponent {
    // Mass
    float mass;
    float invMass;
    float I;
    float invI;

    // Static
    bool isStatic;

    // Forces and Torques
    Vec2 sumForces;
    float sumTorques;

    Shape* shape;

    RigidBodyComponent(float mass, Shape &shape, bool isStatic = false) {
        this->isStatic = isStatic;
        this->shape = shape.Clone();
        this->mass = mass;

        if (mass != 0.0) {
            this->invMass = 1.0 / mass;
        } else {
            this->invMass = 0.0;
        }

        I = shape.GetMomentOfInertia() * mass;
        if (I != 0.0) {
            this->invI = 1.0 / I;
        } else {
            this->invI = 0.0;
        }

        this->sumForces = Vec2(0, 0);
        this->sumTorques = 0.0;
    }

    void AddForce(const Vec2& force) {
        sumForces += force;
    }

    void ClearForces() {
        sumForces = Vec2(0, 0);
    }

    void AddTorque(float torque) {
        sumTorques += torque;
    }

    void ClearTorques() {
        sumTorques = 0.0;
    }

    bool IsStatic() {
        return this->isStatic;
    }
};

#endif