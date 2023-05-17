#ifndef RACKETCONTROLLERSYSTEM_H
#define RACKETCONTROLLERSYSTEM_H

#include "entt/entt.hpp"
#include "../../Events/KeyDownEvent.hh"
#include "../Components/IncludeComponents.hh"

class RacketControllerSystem {
    public:
        void Update(entt::registry& world, Keyboard* keyboard, const double dt) {
            auto view = world.view<TransformComponent, RigidBodyComponent, ColliderComponent, RacketControllerComponent>();

            for (auto entity: view) {
                auto& transform = view.get<TransformComponent>(entity);
                auto& racket = view.get<RacketControllerComponent>(entity);

                float speed = 0;
                // Who you can control the two players, one by pressing the w and s key and the other one by pressing the arrow down and arrow up key
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

                // Moving the rackets with velocity
                transform.position.y += speed * dt;

                // Boundarie of the rackets
                if (transform.position.y < racket.limitUp) {
                    transform.position.y = racket.limitUp;
                } else if (transform.position.y > racket.limitDown) {
                    transform.position.y = racket.limitDown;
                }

                // Making a racket bigger and replace the elements of one racket
                if (racket.extend == true) {
                    RectangleShape box =  RectangleShape(8, 128, Color::White(), false);
                    RectangleShape &box_ref = box;

                    world.replace<RigidBodyComponent>(entity, 1.0f, box_ref, true);
                    world.replace<ColliderComponent>(entity, box_ref, false, true, true);
                    world.replace<SpriteComponent>(entity, "PlayerExtended", 8, 128);
                    
                    racket.limitUp = 241;
                    racket.limitDown = 559;

                    racket.extend = false;
                }
            }
        }
};

#endif