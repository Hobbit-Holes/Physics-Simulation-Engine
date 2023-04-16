#ifndef DAMAGECOMPONENT_H
#define DAMAGECOMPONENT_H

struct DamageComponent {
    int stepSize;

    DamageComponent(int stepSize) {
        this->stepSize = stepSize;
    }
};

#endif