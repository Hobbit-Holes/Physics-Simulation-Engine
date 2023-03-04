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

    // Operators
    friend std::ostream& operator << (std::ostream& os, const Vec3& v);

    Vec3& operator = (const Vec3& v);
    bool operator == (const Vec3& v) const;
    bool operator != (const Vec3& v) const;

    Vec3 operator + (const Vec3& v) const;
    Vec3 operator - (const Vec3& v) const;
    Vec3 operator * (const float n) const;
    Vec3 operator / (const float n) const;
    Vec3 operator - ();

    Vec3& operator += (const Vec3& v);
    Vec3& operator -= (const Vec3& v);
    Vec3& operator *= (const float n);
    Vec3& operator /= (const float n);
};

#endif