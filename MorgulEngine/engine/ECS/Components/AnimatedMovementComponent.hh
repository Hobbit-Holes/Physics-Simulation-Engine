#ifndef ANIMATEDMOVEMENTCOMPONENT_H
#define ANIMATEDMOVEMENTCOMPONENT_H

#include "Vec2.hh"

struct AnimatedMovementComponent {
    // Value "x" is the start frame of the animation
    // Value "y" is the number of frames
    Vec2 animationUp;
    Vec2 animationDown;
    Vec2 animationRight;
    Vec2 animationLeft;
    Vec2 animationFinal;

    AnimatedMovementComponent(Vec2 animationUp = Vec2(0, 1), Vec2 animationDown = Vec2(0, 1), Vec2 animationRight = Vec2(0, 1), Vec2 animationLeft = Vec2(0, 1), Vec2 animationFinal = Vec2(0, 1)) {
        this->animationUp = animationUp;
        this->animationDown = animationDown;
        this->animationRight = animationRight;
        this->animationLeft = animationLeft;
        this->animationFinal = animationFinal;
    }
};

#endif