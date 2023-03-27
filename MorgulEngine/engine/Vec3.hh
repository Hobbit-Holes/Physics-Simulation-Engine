#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>

struct Vec3 {
    float x;
    float y;
    float z;

    // Contructor and Deconstructor
    Vec3();
    Vec3(float x, float y, float z);
    ~Vec3() = default;

    // Simple operations
    void Add(const Vec3& v);
    void Sub(const Vec3& v);
    void Scale(const float n);
    void Scale(const Vec3& v);
    Vec3 Rotate(const float angle);

    float Magnitude() const;
    float MagnitudeSquared() const;
    float Angle() const;
    float Angle(Vec3 v);
    float Angle(float a, float b);
    Vec3 FromModuleAngle(float a, float b);

    Vec3& Normalize();
    Vec3 UnitVector() const;
    Vec3 Normal() const;

    // Projections
    Vec3 Projection(Vec3 w) const;
    float ScalarProjection(Vec3 w) const;
    Vec3 OrthonormalProjection(Vec3 w) const;

    // Dot and Cross
    float Dot(const Vec3& v) const;
    float Cross(const Vec3& v) const;

    // Lerp
    static Vec3 Lerp(Vec3 a, Vec3 b, float t);

    // OPERATORS
    friend std::ostream& operator << (std::ostream& os, const Vec3& v);

    Vec3& operator = (const Vec3& v);
    bool operator == (const Vec3& v) const;
    bool operator != (const Vec3& v) const;

    // Simple operations
    Vec3 operator + (const Vec3& v) const;
    Vec3 operator - (const Vec3& v) const;
    Vec3 operator * (const float n) const;
    Vec3 operator / (const float n) const;
    Vec3 operator - ();

    // Equal operations
    Vec3& operator += (const Vec3& v);
    Vec3& operator -= (const Vec3& v);
    Vec3& operator *= (const float n);
    Vec3& operator /= (const float n);
};

#endif