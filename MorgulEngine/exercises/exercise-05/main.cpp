#include "Vec2.hh"
#include <iostream>

int main(int argc, char *argv[]) {
    Vec2 v1(3, 4);
    Vec2 v2(-1, 7);

    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl << std::endl;

    // Simple operations
    std::cout << "v1 + v2 = " << v1 + v2 << std::endl;
    std::cout << "v1 - v2 = " << v1 - v2 << std::endl;
    std::cout << "v1 * 2 = " << v1 * 2 << std::endl;
    std::cout << "v1 / 2 = " << v1 / 2 << std::endl;
    std::cout << "(Inverse) v1 = " << -v1 << std::endl << std::endl;

    v1.Scale(5);
    std::cout << "(Scale) v1 * 5 = " << v1 << std::endl;
    v1.Scale(v2);
    std::cout << "(Scale) v1 * v2 = " << v1 << std::endl;
    v1 = Vec2(3, 4);
    v1.Rotate(30);
    std::cout << "(Rotate 30) v1 = " << v1 << std::endl << std::endl;

    v1 = Vec2(3, 4);
    std::cout << "(Magnitude) v1 = " << v1.Magnitude() << std::endl;
    std::cout << "(Magnitude Squared) v1 = " << v1.MagnitudeSquared() << std::endl;
    std::cout << "(Angle) v1 = " << v1.Angle() << std::endl;
    std::cout << "(From Module Angle) v1, v2 = " << v1.Angle(v2.x, v2.y) << std::endl << std::endl;

    std::cout << "(Normalize) v1 = " << v1.Normalize() << std::endl;
    std::cout << "(Unit Vector) v1 = " << v1.UnitVector() << std::endl;
    std::cout << "(Normal) v1 = " << v1.Normal() << std::endl << std::endl;

    // Projections
    std::cout << "(Projection) v1 = " << v1.Projection(v2) << std::endl;
    std::cout << "(Scalar Projection) v1 = " << v1.ScalarProjection(v2) << std::endl;
    std::cout << "(Orthonormal Projection) v1 = " << v1.OrthonormalProjection(v2) << std::endl << std::endl;
    
    // Dot and Cross operations
    std::cout << "(Dot) v1 * v2 = " << v1.Dot(v2) << std::endl;
    std::cout << "(Cross) v1 * v2 = " << v1.Cross(v2) << std::endl;
    std::cout << "(Lerp) v1, v2, 0.1 = " << v1.Lerp(v1, v2, 0.1) << std::endl << std::endl;

    // Other operators
    Vec2 v3 = v1;
    
    std::cout << "v1 = v3 = " << v3 << std::endl;
    std::cout << "v1 == v2: " << (v1 == v2) << std::endl;
    std::cout << "v1 != v2: " << (v1 != v2) << std::endl;

    return 0;
}