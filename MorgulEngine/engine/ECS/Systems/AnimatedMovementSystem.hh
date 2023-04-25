#ifndef ANIMATEDMOVEMENTSYSTEM_H
#define ANIMATEDMOVEMENTSYSTEM_H

#include "entt/entt.hpp"
#include "../../Events/KeyDownEvent.hh"
#include "../Components/IncludeComponents.hh"

class AnimatedMovementSystem {
    public:
        void OnKeyDown(KeyDownEvent& keyDown) {
            auto view = keyDown.world->view<AnimationComponent, AnimatedMovementComponent>();

            for (auto entity: view) {
                auto& animation = view.get<AnimationComponent>(entity);
                const auto amc = view.get<AnimatedMovementComponent>(entity);

                Vec2 animationDirection = Vec2(animation.startFrame, animation.numFrames);
                switch (keyDown.symbol) {
                    case SDLK_UP:
                        animationDirection = amc.animationUp;
                        break;
                    case SDLK_RIGHT:
                        animationDirection = amc.animationRight;
                        break;
                    case SDLK_DOWN:
                        animationDirection = amc.animationDown;
                        break;
                    case SDLK_LEFT:
                        animationDirection = amc.animationLeft;
                        break;
                    case SDLK_SPACE:
                        animationDirection = amc.animationFinal;
                        break;
                }
                
                animation.startFrame = (int) animationDirection.x;
                animation.numFrames = (int) animationDirection.y;
            }
        }
};

#endif