#ifndef BALLMOVEMENTCOMPONENT_H
#define BALLMOVEMENTCOMPONENT_H

struct BallMovementComponent {
    float maxVelocity;
    float maxDesviation;
    
    float sumVelocity;
    float sumDesviation;

    BallMovementComponent(float maxVelocity, float maxDesviation, float sumVelocity, float sumDesviation) {
        this->maxVelocity = maxVelocity;
        this->maxDesviation = maxDesviation;

        this->sumVelocity = sumVelocity;
        this->sumDesviation = sumDesviation;
    }
};

#endif