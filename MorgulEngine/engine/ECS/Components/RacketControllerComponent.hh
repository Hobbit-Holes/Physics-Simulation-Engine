#ifndef RACKETCONTROLLERCOMPONENT_H
#define RACKETCONTROLLERCOMPONENT_H

struct RacketControllerComponent {
    int control;
    int limitUp;
    int limitDown;
    float speed;

    RacketControllerComponent(int control = 0, int limitUp = 100, int limitDown = 300, float speed = 1.0) {
        this->control = control;
        this->limitUp = limitUp;
        this->limitDown = limitDown;
        this->speed = speed;
    }
};

#endif