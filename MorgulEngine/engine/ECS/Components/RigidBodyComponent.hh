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
    float invMass;          // 1 / mass
    float I;                // Inertia
    float invI;             // 1 / I
    float restitution;

    // Static
    bool isStatic;          // If static is "true", the object will not move

    // Forces and Torques
    Vec2 sumForces;
    float sumTorques;

    Shape* shape;

    RigidBodyComponent(float mass, Shape &shape, bool isStatic = false) {
        this->shape = shape.Clone();

        this->isStatic = isStatic;
        if (this->isStatic == true) {
            this->mass = 0;
        } else {
            this->mass = mass;
        }
        
        if (this->mass != 0.0) {
            this->invMass = 1.0 / mass;
        } else {
            this->invMass = 0.0;
        }

        I = shape.GetMomentOfInertia() * this->mass;
        if (I != 0.0) {
            this->invI = 1.0 / I;
        } else {
            this->invI = 0.0;
        }

        this->sumForces = Vec2(0, 0);
        this->sumTorques = 0.0;
        this->restitution = 0.005f;
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

    bool IsStatic() const {
        const float epsilon = 0.005f;
        return fabs(invMass - 0.0) < epsilon;
    }
};

#endif