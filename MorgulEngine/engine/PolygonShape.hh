#ifndef POLYGONSHAPE_H
#define POLYGONSHAPE_H

#include "Shape.hh"

struct PolygonShape: public Shape {
    std::vector<Vec2> localVertices;
    std::vector<Vec2> worldVertices;

    PolygonShape() = default;
    PolygonShape(const std::vector<Vec2> vertices);

    virtual Shape* Clone() const = 0;
    virtual ShapeType GetType() const = 0;
    virtual float GetMomentOfInertia() const = 0;
    void UpdateVertices(float angle, const Vec2& position) {
        worldVertices.clear();
        for (const auto& localVertex : localVertices) {
            float sinAngle = sin(angle);
            float cosAngle = cos(angle);
            Vec2 rotatedVertex(cosAngle * localVertex.x - sinAngle * localVertex.y,
                                sinAngle * localVertex.x + cosAngle * localVertex.y);
            worldVertices.push_back(rotatedVertex + position);
        }
    }
};

#endif