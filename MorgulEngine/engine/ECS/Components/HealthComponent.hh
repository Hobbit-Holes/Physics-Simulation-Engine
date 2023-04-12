#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

struct HealthComponent {
    int health;

    HealthComponent(int health) {
        this->health = health;
    }
};

#endif