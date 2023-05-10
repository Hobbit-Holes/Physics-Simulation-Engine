#ifndef BALLMOVEMENTCOMPONENT_H
#define BALLMOVEMENTCOMPONENT_H

struct BallMovementComponent {
    float initialVelocity;

    float maxVelocity;
    float maxDesviation;
    
    float sumVelocity;          // Determine how much the ball can increase the velocity per step
    float sumDesviation;        // Determine how much the ball can be desviated per step

    int numDesviation;          // Determine the times the desviation has benn applied
    int serve;                  // If 0 the ball is moving, If 1 the Player 1 serve, If 2 the Player 2 serve

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