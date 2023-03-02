#include "Vec2.hh"
#include <iostream>

int main(int argc, char *argv[]) {
    Vec2 v1(3, 4);
    Vec2 v2(-1, 7);

    std::cout << "v1 + v2 = " << v1 + v2 << std::endl;
    std::cout << "v1 . v2 = " << v1 - v2 << std::endl;
    std::cout << "v1 Magnitude = " << v1.Magnitude() << std::endl;
    std::cout << "v1 Magnitude Squared = " << v1.MagnitudeSquared() << std::endl;
    std::cout << "v1 Unit Vector = " << v1.UnitVector() << std::endl;
    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v1 Normalized = " << v1.Normalize() << std::endl;
    std::cout << "v1 = " << v1 << std::endl;

    return 0;
}