#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

struct AnimationComponent {
    int numFrames;          // Total amount of frames
    int currentFrame;
    int frameSpeedRate;     // Number of frames showed per secons
    bool isLoop;
    int startTime;          // SDL_GetTicks()

    AnimationComponent(int numFrames, int frameSpeedRate, bool isLoop, int startTime = 0) {
        this->numFrames = numFrames;
        this->frameSpeedRate = frameSpeedRate;
        this->isLoop = isLoop;
        this->startTime = startTime;
    }
};

#endif