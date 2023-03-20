#include <iostream>
#include "RungeKutta.hh"

int main(int argc, char *argv[]) {
    double t = 0.0;
    float dt = 1.0/100;
    void (*rshFuction) (double, double*, double*);
    RungeKutta runge = RungeKutta(t, rshFuction);

    while(t <= 10.0) {
        

        t += dt;
    }

    return 0;
}