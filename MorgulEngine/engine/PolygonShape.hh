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

    Vec2 EdgeAt(int index) const {
        int nextIndex = index + 1;
        if (nextIndex >= static_cast<int>(this->worldVertices.size())) {
            nextIndex = 0;
        }
        return this->worldVertices[nextIndex] - this->worldVertices[index];
    }

    float FindMinSeparation(const PolygonShape* other, Vec2& axis, Vec2& point) const {
        float separation = std::numeric_limits<float>::lowest();
        //Loop all the vertices of "this" polygon
        for(int i = 0; i < static_cast<int>(this->worldVertices.size()); i++) {
            Vec2 va = this->worldVertices[i];
            Vec2 normal = this->EdgeAt(i).Normal();
            //Loop all the vertices of the "other" polygon
            float minSep = std::numeric_limits<float>::max();
            Vec2 minVertex;
            for(int j = 0; j < static_cast<int>(other->worldVertices.size()); j++) {
                Vec2 vb = other->worldVertices[j];
                float proj = (vb - va).Dot(normal);
                if(proj < minSep) {
                    minSep = proj;
                    minVertex = vb;
                }
            }
            if (minSep > separation) {
                separation = minSep;
                axis = this->EdgeAt(i);
                point = minVertex;
            }
        }

        return separation;
    }
};

#endif