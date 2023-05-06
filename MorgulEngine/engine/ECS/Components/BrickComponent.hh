#ifndef BRICKCOMPONENT_H
#define BRICKCOMPONENT_H

struct BrickComponent {
    int numLifes;

    BrickComponent(int numLifes) {
        this->numLifes = numLifes;
    }
};

#endif