#ifndef RACKETCONTROLLERCOMPONENT_H
#define RACKETCONTROLLERCOMPONENT_H

struct RacketControllerComponent {
    int control;            // Determine the keys that the player will use
    int limitUp;            // Determine the upper zone
    int limitDown;          // Determine the lower zone
    float speed;
    bool extend;            // The length of the racket is bigger or not

    RacketControllerComponent(int control = 0, int limitUp = 100, int limitDown = 300, float speed = 1.0, bool extend = false) {
        this->control = control;
        this->limitUp = limitUp;
        this->limitDown = limitDown;
        this->speed = speed;
        this->extend = extend;
    }
};

#endif