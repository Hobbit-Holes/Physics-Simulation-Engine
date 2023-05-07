#ifndef RACKETCONTROLLERSYSTEM_H
#define RACKETCONTROLLERSYSTEM_H

#include "entt/entt.hpp"
#include "../../Events/KeyDownEvent.hh"
#include "../Components/IncludeComponents.hh"

class RacketControllerSystem {
    public:
        void Update(entt::registry& world) {
            auto view = world.view<TransformComponent, RacketControllerComponent>();
            
            for (auto entity: view) {
                if (world.get<TransformComponent>(entity).position.y < world.get<RacketControllerComponent>(entity).limitUp) {
                    world.get<TransformComponent>(entity).position.y = world.get<RacketControllerComponent>(entity).limitUp;
                } else if (world.get<TransformComponent>(entity).position.y > world.get<RacketControllerComponent>(entity).limitDown) {
                    world.get<TransformComponent>(entity).position.y = world.get<RacketControllerComponent>(entity).limitDown;
                }
            }
        }

        void OnKeyDown(KeyDownEvent& keyDown) {
            auto view = keyDown.world->view<TransformComponent, KinematicComponent, RacketControllerComponent>();

            for (auto entity: view) {
                auto& transform = view.get<TransformComponent>(entity);
                const auto racket = view.get<RacketControllerComponent>(entity);

                float speed = 0;
                if (racket.control == 0) {
                    switch (keyDown.symbol) {
                        case SDLK_UP:
                            speed = racket.speed * -1;
                            break;
                        case SDLK_DOWN:
                            speed = racket.speed;
                            break;
                    }
                } else {
                    switch (keyDown.symbol) {
                        case SDLK_w:
                            speed = racket.speed * -1;
                            break;
                        case SDLK_s:
                            speed = racket.speed;
                            break;
                    }
                }
                transform.position.y += speed * 0.016;
            }
        }
};

#endif