#ifndef RACKETCONTROLLERSYSTEM_H
#define RACKETCONTROLLERSYSTEM_H

#include "entt/entt.hpp"
#include "../../Events/KeyDownEvent.hh"
#include "../Components/IncludeComponents.hh"

class RacketControllerSystem {
    public:
        void Update(entt::registry& world, Keyboard* keyboard, const double dt) {
            auto view = world.view<TransformComponent, RacketControllerComponent>();

            for (auto entity: view) {
                auto& transform = view.get<TransformComponent>(entity);
                const auto racket = view.get<RacketControllerComponent>(entity);

                float speed = 0;
                if (racket.control == 0) {
                    if (keyboard->upKeyPressed) {
                        speed = racket.speed * -1;
                    } else if (keyboard->downKeyPressed) {
                        speed = racket.speed;
                    }
                } else {
                    if (keyboard->KeyW) {
                        speed = racket.speed * -1;
                    } else if (keyboard->KeyS) {
                        speed = racket.speed;
                    }
                }

                transform.position.y += speed * dt;

                if (transform.position.y < racket.limitUp) {
                    transform.position.y = racket.limitUp;
                } else if (transform.position.y > racket.limitDown) {
                    transform.position.y = racket.limitDown;
                }
            }
        }
};

#endif