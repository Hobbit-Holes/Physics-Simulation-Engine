#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include <SDL2/SDL.h>

struct AnimationComponent {
    int numFrames; 
    int startFrame;         // Total amount of frames
    int currentFrame;
    int frameSpeedRate;     // Number of frames showed per secons
    bool isLoop;
    int startTime;          // SDL_GetTicks()

    AnimationComponent(int numFrames, int startFrame = 0, int frameSpeedRate = 1, bool isLoop = true) {
        this->numFrames = numFrames;
        this->startFrame = startFrame;
        this->frameSpeedRate = frameSpeedRate;
        this->isLoop = isLoop;
        this->startTime = SDL_GetTicks();
    }
};

#endif