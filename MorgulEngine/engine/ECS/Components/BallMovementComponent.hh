#ifndef BALLMOVEMENTCOMPONENT_H
#define BALLMOVEMENTCOMPONENT_H

struct BallMovementComponent {
    float initialVelocity;

    float maxVelocity;
    float maxDesviation;
    
    float sumVelocity;
    float sumDesviation;

    int numDesviation;
    int serve;

    BallMovementComponent(float initialVelocity, float maxVelocity, float maxDesviation, float sumVelocity, float sumDesviation, int numDesviation = 0, int serve = 1) {
        this->initialVelocity = initialVelocity;
        this->maxVelocity = maxVelocity;
        this->maxDesviation = maxDesviation;

        this->sumVelocity = sumVelocity;
        this->sumDesviation = sumDesviation;

        this->numDesviation = numDesviation;
        this->serve = serve;
    }
};

#endif