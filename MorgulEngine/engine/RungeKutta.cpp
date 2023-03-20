#include "RungeKutta.hh"

void RungeKutta::Step(float t, float dt) {
    //K1
    rhs(t, x, rhs_ouput);
    for(int j = 0; j < dimension; j++) {
        k1[j] = rhs_ouput[j];
    }

    //K2
    for(int j = 0; j < dimension; j++) {
        _x[j] = x[j] + 0.5 * dt * k1[j];
    }
    rhs(t + dt * 0.5, _x, rhs_ouput);
    for(int j = 0; j < dimension; j++) {
        k2[j] = rhs_ouput[j];
    }

    //K3
    for(int j = 0; j < dimension; j++) {
        _x[j] = x[j] + 0.5 * dt * k2[j];
    }
    rhs(t + dt * 0.5, _x, rhs_ouput);
    for(int j = 0; j < dimension; j++) {
        k3[j] = rhs_ouput[j];
    }

    //K4
    for(int j = 0; j < dimension; j++) {
        _x[j] = x[j] + 0.5 * dt * k3[j];
    }
    rhs(t + dt * 0.5, _x, rhs_ouput);
    for(int j = 0; j < dimension; j++) {
        k4[j] = rhs_ouput[j];
    }

    //Net value
    for(int j = 0; j < dimension; j++) {
        x[j] += (dt / 6.0) * (k1[j] + 2.0 * k3[j] + k4[j]);
    }
}