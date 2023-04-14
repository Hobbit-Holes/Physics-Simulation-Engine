#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include "../../Shape.hh"

struct ColliderComponent {
    Shape* shape;
    bool renderCollider;
    bool isColliding;

    ColliderComponent(Shape& shape, bool renderCollider = false) {
        this->shape = shape.Clone();
        this->renderCollider = renderCollider;
        this->isColliding = false;
    } 
};

#endif