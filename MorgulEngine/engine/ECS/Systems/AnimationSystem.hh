#ifndef ANIMATIONSYSTEM_H
#define ANIMATIONSYSTEM_H

#include "entt/entt.hpp"
#include "../Components/IncludeComponents.hh"

class AnimationSystem {
    public:
        void Render(entt::registry& world) {
            auto view = world.view<SpriteComponent, AnimationComponent>();

            for (auto entity: view) {
                auto& s = view.get<SpriteComponent>(entity);
                auto& a = view.get<AnimationComponent>(entity);
                
                // Get frame of the loop
                int currentFrame = ((SDL_GetTicks() - a.startTime) * a.frameSpeedRate / 1000);
                int moduledCurrentFrame = currentFrame % a.numFrames;

                if (currentFrame >= a.numFrames && !a.isLoop) {
                    moduledCurrentFrame = a.numFrames - 1;
                }

                // Set the frame and the position in the Sprite
                a.currentFrame = a.startFrame + moduledCurrentFrame;
                s.srcRect.x = a.currentFrame * s.width;
            }
        }
};

#endif