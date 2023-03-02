#include "Vec2.hh"

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

void Vec2::Scale(const Vec2& v) {
    x *= v.x;
    y *= v.y;
}

void Vec2::Rotate(const float angle) {
    x = x * cos(angle) - y * sin(angle);
    y = x * sin(angle) - y * cos(angle);
}

float Vec2::Magnitude() const {
    return sqrtf(x * x + y * y);
}

float Vec2::MagnitudeSquared() const {
    return (x * x + y * y);
}

float Vec2::Angle() const {
    return atan(x / y);
}

float Vec2::Angle(const Vec2& v) {
    return acos((x * v.x + y * v.y) / (sqrtf(x * x + y * y) * sqrtf(v.x * v.x + v.y * v.y)));
}

float Vec2::FromModuleAngle(float m, float a) {
    return acos(Vec2::Dot(Vec2(m,a))/(m*a));
}

Vec2& Vec2::Normalize() {
    float normal = sqrtf(x * x + y * y);
    x /= normal;
    y /= normal;
    return *this;
}

Vec2 Vec2::UnitVector() const {
    float normal = sqrtf(x * x + y * y);
    return Vec2(x / normal, y / normal);
}

Vec2 Vec2::Normal() const {
    return Vec2(-y, x);
}

Vec2 Vec2::Projection() const {
    return Vec2();
}

Vec2 Vec2::ScalarProjection() const {
    return Vec2();
}

Vec2 Vec2::OrthogonalProjection() const {
    return Vec2();
}

float Vec2::Dot(const Vec2& v) const {
    return (x * v.x + y * v.y);
}

float Vec2::Cross(const Vec2& v) const {
    return ((x * v.y - y * v.x) / 1);
}

Vec2 Vec2::Lerp(Vec2 a, Vec2 b, float t) {
    return Vec2(a * (1 - t) + b * t);
}

// OPERATORS
std::ostream& operator << (std::ostream& os, const Vec2& v) {
    return std::cout << "("<< v.x << ", " << v.y << ")";
}

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
