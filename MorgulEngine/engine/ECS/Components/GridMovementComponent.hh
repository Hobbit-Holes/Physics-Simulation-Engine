#ifndef GRIDMOVEMENTCOMPONENT_H
#define GRIDMOVEMENTCOMPONENT_H

struct GridMovementComponent {
    int stepSize;

    GridMovementComponent(int stepSize) {
        this->stepSize = stepSize;
    }
};

#endif