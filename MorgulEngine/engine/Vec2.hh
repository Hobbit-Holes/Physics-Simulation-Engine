#ifndef VEC2_H
#define VEC2_H

#include <iostream>

struct Vec2 {
    float x;
    float y;

    // Constructor and Deconstructor
    Vec2();
    Vec2(float x, float y);
    ~Vec2() = default;

    // Functions
    void Add(const Vec2& v);
    void Sub(const Vec2& v);
    void Scale(const float n);
    void Scale(const Vec2& v);
    void Rotate(const float angle) const;

    float Magnitude() const;
    float MagnitudeSquared() const;
    float Angle() const;

    Vec2& Normalize();
    Vec2 UnitVector() const;
    Vec2 Normala() const;

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