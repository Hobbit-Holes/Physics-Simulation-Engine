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
        for (const auto& localVertex : this->localVertices) {
            float sinAngle = sin(angle);
            float cosAngle = cos(angle);

            float xAxis = cosAngle * localVertex.x - sinAngle * localVertex.y;
            float yAxis = sinAngle * localVertex.x + cosAngle * localVertex.y;

            Vec2 rotatedVertex(xAxis, yAxis);
            worldVertices.push_back(rotatedVertex + position);
        }
    }
};

#endif