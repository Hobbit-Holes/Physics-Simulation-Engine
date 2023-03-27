#ifndef STARSHAPE_H
#define STARSHAPE_H

#include "PolygonShape.hh"

struct StarShape: public PolygonShape {
    float radius;
    int numVertices;
    bool platinum;
 
    StarShape(float radius = 1.0f, int numVertices = 3, Color color = Color::White(), bool platinum = false) {
        this->radius = radius;
        this->platinum = platinum;

        int minimum = 3;
        if (this->platinum == false) {
            minimum = 5;
        }

        if (numVertices < minimum) {
            this->numVertices = minimum;
        } else {
            this->numVertices = numVertices;
        }

        this->color = color;
        this->filled = false;

        // Vertices
        std::vector<entt::entity> balls;
        for (int i = 1; i <= this->numVertices; i++) {
            Vec2 position = position.FromModuleAngle(this->radius, (2* M_PI / this->numVertices) * (i));

            this->localVertices.push_back(position);
            this->worldVertices.push_back(position);
        }
    }

    Shape* Clone() const {
        return new StarShape(radius, numVertices, color, platinum);
    }

    ShapeType GetType() const {
        return POLYGON;
    }

    float GetMomentOfInertia() const {
        float l = 2 * radius * sin(2 * M_PI / numVertices);
        float aux = 1 / (3 * tan(M_PI / numVertices) * tan(M_PI / numVertices));
        return (0.0416666) * (l * l) * (1 + aux);
    }

    void Render(TransformComponent transform) const override {
        if (this->platinum) {
            Graphics::DrawStarPlatinum(0, 0, this->radius, this->worldVertices, this->color);
        } else {
            Graphics::DrawStar(0, 0, this->worldVertices, this->color);
        }
    }
};

#endif