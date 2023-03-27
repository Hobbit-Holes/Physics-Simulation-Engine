#include "Vec3.hh"

// CONSTRUCTORS
Vec3::Vec3(): x(0.0), y(0.0), z(0.0) {}

Vec3::Vec3(float x, float y, float z): x(x), y(y), z(z) {}

// FUNCTIONS
void Vec3::Add(const Vec3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
}

void Vec3::Sub(const Vec3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

void Vec3::Scale(const float n) {
    x *= n;
    y *= n;
    z *= n;
}

void Vec3::Scale(const Vec3& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
}

Vec3 Vec3::Rotate(const float angle) {

}


float Vec3::Magnitude() const {
    return sqrtf(x * x + y * y + z * z);
}

float Vec3::MagnitudeSquared() const {
    return (x * x + y * y + z * z);
}

float Vec3::Angle() const {

}

float Vec3::Angle(Vec3 v) {

}

float Vec3::Angle(float a, float b) {

}

Vec3 Vec3::FromModuleAngle(float a, float b) {

}


Vec3&Vec3:: Normalize() {
    float normal = sqrtf(x * x + y * y + z * z);
    x /= normal;
    y /= normal;
    z /= normal;
    return *this;
}

Vec3 Vec3::UnitVector() const {
    float normal = sqrtf(x * x + y * y + z * z);
    return Vec3(x / normal, y / normal, z / normal);
}

Vec3 Vec3::Normal() const {

}


// Projections
Vec3 Vec3::Projection(Vec3 w) const {

}

float Vec3::ScalarProjection(Vec3 w) const {

}

Vec3 Vec3::OrthonormalProjection(Vec3 w) const {

}


// Dot and Cross
float Vec3::Dot(const Vec3& v) const {
    return (x * v.x + y * v.y + z * v.z);
}

float Vec3::Cross(const Vec3& v) const {

}

// Lerp
Vec3 Vec3::Lerp(Vec3 a, Vec3 b, float t) {
    return Vec3(a * (1 - t) + b * t);
}


// OPERATORS
std::ostream& operator << (std::ostream& os, const Vec3& v) {
    return std::cout << "("<< v.x << ", " << v.y << ", " << v.z << ")";
}

Vec3& Vec3::operator = (const Vec3& v) {
    x = v.x;
    y = v.y;
    z = v.z;

    return *this;
}

bool Vec3::operator == (const Vec3& v) const {
    if (x == v.x && y == v.y && z == v.z) {
        return true;
    } else {
        return false;
    }
}

bool Vec3::operator != (const Vec3& v) const {
    if (x == v.x && y == v.y && z == v.z) {
        return false;
    } else {
        return true;
    }
}

// Simple operations
Vec3 Vec3::operator + (const Vec3& v) const {
    return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator - (const Vec3& v) const {
    return Vec3(x - v.x, y - v.y, z - v.z);
}

Vec3 Vec3::operator * (const float n) const {
    return Vec3(x * n, y * n, z * n);
}

Vec3 Vec3::operator / (const float n) const {
    return Vec3(x / n, y / n, z / n);
}

Vec3 Vec3::operator - () {
    return Vec3(-1 * x, -1 * y, -1 * z);
}

// Equal operations
Vec3& Vec3::operator += (const Vec3& v) {
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

Vec3& Vec3::operator -= (const Vec3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    
    return *this;
}

Vec3& Vec3::operator *= (const float n) {
    x *= n;
    y *= n;
    z *= n;
    
    return *this;
}

Vec3& Vec3::operator /= (const float n) {
    x /= n;
    y /= n;
    z /= n;
    
    return *this;
}