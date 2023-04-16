#ifndef DAMAGECOMPONENT_H
#define DAMAGECOMPONENT_H

struct DamageComponent {
    Vec2 position;

    DamageComponent(Vec2 position) {
        this->position = position;
    }
};

#endif