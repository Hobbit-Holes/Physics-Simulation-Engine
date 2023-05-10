#ifndef GRIDMOVEMENTCOMPONENT_H
#define GRIDMOVEMENTCOMPONENT_H

struct GridMovementComponent {
    int stepSize;       // Size of the grid spaces

    GridMovementComponent(int stepSize) {
        this->stepSize = stepSize;
    }
};

#endif