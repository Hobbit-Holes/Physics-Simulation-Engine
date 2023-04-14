#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

#include "PolygonShape.hh"

struct RectangleShape: public PolygonShape {
    float width;
    float heigth;

    RectangleShape(float width = 1.0f, float heigth = 1.0f, Color color = Color::White(), bool filled = true) {
        this->width = width;
        this->heigth = heigth;
        
        this->color = color;
        this->filled = filled;

        // Local Vertices
        this->localVertices.push_back(Vec2(-width / 2.0, -heigth / 2.0));
        this->localVertices.push_back(Vec2(+width / 2.0, -heigth / 2.0));
        this->localVertices.push_back(Vec2(+width / 2.0, +heigth / 2.0));
        this->localVertices.push_back(Vec2(-width / 2.0, +heigth / 2.0));

        // World Vertices
        this->worldVertices.push_back(Vec2(-width / 2.0, -heigth / 2.0));
        this->worldVertices.push_back(Vec2(+width / 2.0, -heigth / 2.0));
        this->worldVertices.push_back(Vec2(+width / 2.0, +heigth / 2.0));
        this->worldVertices.push_back(Vec2(-width / 2.0, +heigth / 2.0));
    }

    Shape* Clone() const {
        return new RectangleShape(width, heigth, color, filled);
    }

    ShapeType GetType() const {
        return RECTANGLE;
    }

    float GetMomentOfInertia() const {
        return (0.0833333) * (width * width + heigth * heigth);
    }

    void Render(TransformComponent transform) const override {
        if (this->filled) {
            Graphics::DrawFillRect(transform.position.x, transform.position.y, this->width, this->heigth, this->color);
        } else {
            Graphics::DrawRect(transform.position.x, transform.position.y, this->width, this->heigth, this->color);
        }
    }
};

#endif