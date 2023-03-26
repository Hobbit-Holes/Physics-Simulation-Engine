#include <iostream>
#include <math.h>
#include "RungeKutta.hh"

// Hay que buscar la funcion adecuada
void rhs(double t, double *y, double *dydt) {
    dydt[0] = y[1];
    dydt[1] = y[0];
}

int main() {
    double y0[2] = {1.27, 0.0};

    RungeKutta rk(2, &rhs);
    rk.x[0] = y0[0];
    rk.x[1] = y0[1];

    double t0 = 0.0;
    double dt = 0.01;

    while(t0 < 10) {
        rk.Step(t0, dt);
        std::cout << "t = " << t0 << "\tx:" << rk.x[0] << "\tx(real) = " << rk._x[0] << std::endl;
        t0 += dt;
    }

    return 0;
}
