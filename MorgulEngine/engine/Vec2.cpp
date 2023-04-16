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

Vec2 Vec2::Rotate(const float angle) {
    return Vec2(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
}

float Vec2::Magnitude() const {
    return sqrtf(x * x + y * y);
}

float Vec2::MagnitudeSquared() const {
    return (x * x + y * y);
}

float Vec2::Angle() const {
    if (y > 0 || y < 0) {
        return atan(x / y);
    }
    return 0;
}

float Vec2::Angle(Vec2 v) {
    float aux = sqrtf(x * x + y * y) * sqrtf(v.x * v.x + v.y * v.y);
    if (aux > 0 || aux < 0) {
        return acos((x * v.x + y * v.y) / aux);
    } 
    return 0;
}

float Vec2::Angle(float a, float b) {
    float aux = sqrtf(x * x + y * y) * sqrtf(a * a + b * b);
    if (aux > 0 || aux < 0) {
        return acos((x * a + y * b) / aux);
    }
    return 0;
}

Vec2 Vec2::FromModuleAngle(float a, float b) {
    return Vec2(a * cos(b), a * sin(b));
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

Vec2 Vec2::Normal2() const {
    return Vec2(y, -x);
}

// Projections
Vec2 Vec2::Projection(Vec2 w) const {
    float b = (x*x + y*y);
    if (b == 0) {
        return Vec2(0, 0);
    }
    float a = (x*w.x + y*w.y);
    return Vec2((a/b)*x, (a/b)*y);
}

float Vec2::ScalarProjection(Vec2 w) const {
    float b = (x*x + y*y);
    if (b == 0) {
        return 0;
    }
    float a = (x*w.x + y*w.y);
    return a/b;
}

Vec2 Vec2::OrthonormalProjection(Vec2 w) const {
    float b = (x*x + y*y);
    if (b == 0) {
        return Vec2(0, 0);
    }
    float a = (x*w.x + y*w.y);
    Vec2 c((a/b)*x, (a/b)*y);
    float module = sqrt(c.x*c.x + c.y*c.y);
    if (module == 0) {
        return Vec2(0, 0);
    }
    return Vec2(c.x/module, c.y/module);
}

// Dot and Cross
float Vec2::Dot(const Vec2& v) const {
    return (x * v.x + y * v.y);
}

float Vec2::Cross(const Vec2& v) const {
    return ((x * v.y - y * v.x) / 1);
}

// Lerp
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

// Simple operations
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

// Equal operations
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
