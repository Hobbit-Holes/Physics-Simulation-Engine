#ifndef SHIPMOVEMENTSYSTEM_H
#define SHIPMOVEMENTSYSTEM_H

#include "entt/entt.hpp"
#include "../../Events/KeyDownEvent.hh"
#include "../Components/IncludeComponents.hh"

class ShipMovementSystem {
    public:
        void OnKeyDown(KeyDownEvent& keyDown) {
            auto view = keyDown.world->view<TransformComponent, KinematicComponent, RigidBodyComponent, ShipMovementComponent>();

            for (auto entity: view) {
                const auto tr = view.get<TransformComponent>(entity);
                const auto k = view.get<KinematicComponent>(entity);
                auto& rb = view.get<RigidBodyComponent>(entity);
                const auto ship = view.get<ShipMovementComponent>(entity);

                float rotation;
                Vec2 force;

                switch (keyDown.symbol) {
                    case SDLK_UP:
                        if (k.velocity.Magnitude() < ship.maxVelocity) {
                            rotation = tr.rotation;
                            force = ship.force;
                            rb.AddForce(force.Rotate(rotation));
                        }
                        break;
                    case SDLK_RIGHT:
                        if (k.angularVelocity < ship.maxRotation) {
                            rb.AddTorque(ship.torque);
                        }
                        break;
                    case SDLK_DOWN:
                        if (k.velocity.Magnitude() < ship.maxVelocity) {
                            rotation = tr.rotation;
                            force = ship.force;
                            rb.AddForce(force.Rotate(rotation) * -0.5);
                        }
                        break;
                    case SDLK_LEFT:
                        if (k.angularVelocity > -ship.maxRotation) {
                            rb.AddTorque(-ship.torque);
                        }
                        break;
                }

                std::cout << k.velocity << std::endl;
                std::cout << std::to_string(k.angularVelocity) << std::endl;
            }
        }
};

#endif