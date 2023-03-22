#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "Shape.hh"

struct CircleShape: public Shape {
    float radius;

    CircleShape(float radius = 1.0f, Color color = Color::White(), bool filled = true) {
        this->radius = radius;
        this->color = color;
        this->filled = filled;
    }

    Shape* Clone() const {
        return new CircleShape(radius, color, filled);
    }

    ShapeType GetType() const {
        return CIRCLE;
    }

    float GetMomentOfInertia() const {
        return 0.5 * (radius * radius);
    }

    void Render(TransformComponent transform) const override {
        if (this->filled) {
            Graphics::DrawFillCircle(transform.position.x, transform.position.y, this->radius, this->color);
        } else {
            Graphics::DrawCircle(transform.position.x, transform.position.y, this->radius, transform.rotation, this->color);
        }
    }

};

#endif