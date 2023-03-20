#include "RungeKutta.hh"

RungeKutta::RungeKutta(int dimension, void (*rhs)(double, double *, double *)) {
    this->dimension = dimension;
    this->rhs = rhs;

    rhs_ouput = new double[dimension];
    _x = new double[dimension];
    k1 = new double[dimension];
    k2 = new double[dimension];
    k3 = new double[dimension];
    k4 = new double[dimension];
    x = new double[dimension];

    for (int i = 0; i < dimension; i++) {
        rhs_ouput[i] = 0.0;
        _x[i] = 0.0;
        k1[i] = 0.0;
        k2[i] = 0.0;
        k3[i] = 0.0;
        k4[i] = 0.0;
        x[i] = 0.0;
    }
}

RungeKutta::~RungeKutta() {
    delete[] x;
    delete[] _x;
    delete[] k1;
    delete[] k2;
    delete[] k3;
    delete[] k4;
    delete[] rhs_ouput;
}

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