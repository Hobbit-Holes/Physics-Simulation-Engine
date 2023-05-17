#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include "../../Shape.hh"

struct ColliderComponent {
    Shape* shape;
    bool renderCollider;    // If the collider component is render or not
    bool isColliding;       // If the entities are colliding or not
    bool resolve;           // If we want to resolve the colision or not
    bool aabb;              // If it is a collision between rectangle and rectangle or not

    ColliderComponent(Shape& shape, bool renderCollider = false, bool resolve = true, bool aabb = false) {
        this->shape = shape.Clone();
        this->renderCollider = renderCollider;
        this->isColliding = false;
        this->resolve = resolve;
        this->aabb = aabb;
    } 
};

#endif