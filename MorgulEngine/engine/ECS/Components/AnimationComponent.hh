#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include <SDL2/SDL.h>

struct AnimationComponent {
    int numFrames;          // Total amount of frames
    int startFrame;         // Start frame of the loop
    int currentFrame;
    int frameSpeedRate;     // Number of frames showed per secons
    bool isLoop;            // If loop indefinitely
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