#ifndef REGULARPOLYGONSHAPE_H
#define REGULARPOLYGONSHAPE_H

#include "PolygonShape.hh"

struct RegularPolygonShape: public PolygonShape {
    float radius;
    int numVertices;
 
    RegularPolygonShape(float radius = 1.0f, int numVertices = 3, Color color = Color::White(), bool filled = true) {
        this->radius = radius;
        if (numVertices < 3) {
            this->numVertices = 3;
        } else {
            this->numVertices = numVertices;
        }

        this->color = color;
        this->filled = filled;

        // Vertices
        std::vector<entt::entity> balls;
        for (int i = 1; i <= this->numVertices; i++) {
            Vec2 position = position.FromModuleAngle(this->radius, (2* M_PI / this->numVertices) * (i));

            this->localVertices.push_back(position);
            this->worldVertices.push_back(position);
        }
    }

    Shape* Clone() const {
        return new RegularPolygonShape(radius, numVertices, color, filled);
    }

    ShapeType GetType() const {
        return POLYGON;
    }

    float GetMomentOfInertia() const {
        return 0.5 * (radius * radius);
    }

    void Render(TransformComponent transform) const override {
        if (this->filled) {
            Graphics::DrawPolygon(0, 0, this->worldVertices, this->color);
        } else {
            Graphics::DrawPolygon(0, 0, this->worldVertices, this->color);
        }
    }
};

#endif