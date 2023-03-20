#include <iostream>
#include <math.h>
#include "RungeKutta.hh"

void rhs(double t, double *y, double *dydt) {
    dydt[0] = y[1];
    dydt[1] = -2.0 * y[1] - 2.0 * y[0] + cos(t);
}

int main() {
    double y0[2] = {0.0, 0.0};

    RungeKutta rk(2, &rhs);
    rk.x[0] = y0[0];
    rk.x[1] = y0[1];

    double t0 = 0.0;
    double dt = 0.01;

    while(t0 <= 10) {
        rk.Step(t0, dt);
        t0 += dt;
        std::cout << "t = " << t0 << "\tx:" << rk.x[0] << "\tx(real) = " << rk._x[0] << std::endl;
    }

    return 0;
}
