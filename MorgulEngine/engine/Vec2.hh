#ifndef VEC2_H
#define VEC2_H

#include <iostream>
#include <math.h>

struct Vec2 {
    float x;
    float y;

    // Constructor and Deconstructor
    Vec2();
    Vec2(float x, float y);
    ~Vec2() = default;

    // Simple operations
    void Add(const Vec2& v);
    void Sub(const Vec2& v);
    void Scale(const float n);
    void Scale(const Vec2& v);
    Vec2 Rotate(const float angle);

    float Magnitude() const;
    float MagnitudeSquared() const;
    float Angle() const;
    float Angle(float a, float b);
    Vec2 FromModuleAngle(float a, float b);

    Vec2& Normalize();
    Vec2 UnitVector() const;
    Vec2 Normal() const;

    // Projections
    Vec2 Projection(Vec2 w) const;
    float ScalarProjection(Vec2 w) const;
    Vec2 OrthonormalProjection(Vec2 w) const;

    // Dot and Cross
    float Dot(const Vec2& v) const;
    float Cross(const Vec2& v) const;

    static Vec2 Lerp(Vec2 a, Vec2 b, float t);

    // Operators
    friend std::ostream& operator << (std::ostream& os, const Vec2& v);

    Vec2& operator = (const Vec2& v);
    bool operator == (const Vec2& v) const;
    bool operator != (const Vec2& v) const;

    Vec2 operator + (const Vec2& v) const;
    Vec2 operator - (const Vec2& v) const;
    Vec2 operator * (const float n) const;
    Vec2 operator / (const float n) const;
    Vec2 operator - ();

    Vec2& operator += (const Vec2& v);
    Vec2& operator -= (const Vec2& v);
    Vec2& operator *= (const float n);
    Vec2& operator /= (const float n);
};

#endif