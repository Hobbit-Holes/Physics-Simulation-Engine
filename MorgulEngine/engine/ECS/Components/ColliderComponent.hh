#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include "../../Shape.hh"

struct ColliderComponent {
    Shape* shape;
    bool renderCollider;
    bool isColliding;
    bool resolve;
    bool aabb;

    ColliderComponent(Shape& shape, bool renderCollider = false, bool resolve = true, bool aabb = false) {
        this->shape = shape.Clone();
        this->renderCollider = renderCollider;
        this->isColliding = false;
        this->resolve = resolve;
        this->aabb = aabb;
    } 
};

#endif