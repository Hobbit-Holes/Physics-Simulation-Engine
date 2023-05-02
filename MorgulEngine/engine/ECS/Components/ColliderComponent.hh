#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include "../../Shape.hh"

struct ColliderComponent {
    Shape* shape;
    bool renderCollider;
    bool isColliding;
    bool resolve;

    ColliderComponent(Shape& shape, bool renderCollider = false, bool resolve = true) {
        this->shape = shape.Clone();
        this->renderCollider = renderCollider;
        this->isColliding = false;
        this->resolve = resolve;
    } 
};

#endif