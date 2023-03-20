#include <iostream>

int main(int argc, char *argv[]) {
    double t = 0.0;
    float dt = 1.0/100;
    float velocity = 0.0f;
    float position = 0.0f;
    float force = 10.0f;
    float mass = 1.0f;

    while(t <= 10.0) {
        std::cout << "t: " << t << "\t\tposition: " << position << "\t\tvelocity: " << velocity << std::endl;

        position = position + velocity * dt;
        velocity = velocity + (force/mass) * dt;

        t += dt;
    }

    return 0;
}