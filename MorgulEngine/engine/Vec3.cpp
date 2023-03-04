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