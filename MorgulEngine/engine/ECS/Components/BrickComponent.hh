#ifndef BRICKCOMPONENT_H
#define BRICKCOMPONENT_H

struct BrickComponent {
    int numLifes;
    int restingLifes;

    BrickComponent(int numLifes, int restingLifes) {
        this->numLifes = numLifes;
        this->restingLifes = restingLifes;
    }
};

#endif