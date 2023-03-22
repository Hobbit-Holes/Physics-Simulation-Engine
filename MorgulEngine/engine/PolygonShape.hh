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
};

#endif