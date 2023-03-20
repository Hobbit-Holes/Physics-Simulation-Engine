#ifndef RUNGE_KUTTA_H
#define RUNGE_KUTTA_H

class RungeKutta {
    public:
        int dimension;
        void (*rhs)(double, double *, double *);
        double *rhs_ouput;
        double *_x;
        double *k1;
        double *k2;
        double *k3;
        double *k4;
        double *x;

        RungeKutta(int dimension, void (*rhs)(double, double *, double *));
        ~RungeKutta();
        void Step(float t, float dt);
        void Rsh(double t, double *y, double *dydt);
};

#endif