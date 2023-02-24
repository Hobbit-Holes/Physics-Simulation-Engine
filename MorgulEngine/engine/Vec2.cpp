#include "Vec2.hh"
#include <math.h>
#include <iostream>

// CONSTRUCTORS
Vec2::Vec2(): x(0.0), y(0.0) {}

Vec2::Vec2(float x, float y): x(x), y(y) {}

// FUNCTIONS
void Vec2::Add(const Vec2& v) {
    x += v.x;
    y += v.y;
}

void Vec2::Sub(const Vec2& v) {
    x -= v.x;
    y -= v.y;
}

void Vec2::Scale(const float n) {
    x *= n;
    y *= n;
}


float Vec2::Magnitude() const {
    return sqrtf(x * x + y * y);
}

// OPERATORS
Vec2& Vec2::operator = (const Vec2& v) {
    x = v.x;
    y = v.y;
    return *this;
}

bool Vec2::operator == (const Vec2& v) const {
    if (x == v.x && y == v.y) {
        return true;
    } else {
        return false;
    }
}

bool Vec2::operator != (const Vec2& v) const {
    if (x == v.x && y == v.y) {
        return false;
    } else {
        return true;
    }
}

Vec2 Vec2::operator + (const Vec2& v) const {
    return Vec2(x + v.x, y + v.y);
}

Vec2 Vec2::operator - (const Vec2& v) const {
    return Vec2(x - v.x, y - v.y);
}

Vec2 Vec2::operator * (const float n) const {
    return Vec2(x * n, y * n);
}

Vec2 Vec2::operator / (const float n) const {
    return Vec2(x / n, y / n);
}

Vec2 Vec2::operator - () {
    return Vec2(-1 * x, -1 * y);
}

Vec2& Vec2::operator += (const Vec2& v) {
    x += v.x;
    y += v.y;
    return *this;
}

Vec2& Vec2::operator -= (const Vec2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

Vec2& Vec2::operator *= (const float n) {
    x *= n;
    y *= n;
    return *this;
}

Vec2& Vec2::operator /= (const float n) {
    x /= n;
    y /= n;
    return *this;
}
