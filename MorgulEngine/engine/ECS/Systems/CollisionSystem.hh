#ifndef COLLISIONSYSTEM_HH
#define COLLISIONSYSTEM_HH

#include "entt/entt.hpp"
#include "../../Collisions.hh"
#include "../Components/IncludeComponents.hh"

class CollisionSystem {
    public:
        void Update(entt::dispatcher& enventBus, entt::registry& world) {
            auto view = world.view<TransformComponent, KinematicComponent, RigidBodyComponent, ColliderComponent>();

            //Reset the collision flag to false
            for (auto entity : view) {
                auto& collider = view.get<ColliderComponent>(entity);
                collider.isColliding = false;

                /*if (collider.isColliding) {
                    enventBus.EmitEvent<CollisionEvent>(a, b);
                }*/
            }

            //Check every entity with the next one for collisions
            for (auto entityA : view) {
                for (auto entityB : view) {
                    if (entityA == entityB) {
                        break;
                    }

                    Contact contact;
                    if (Collisions::IsColliding(entityA, entityB, contact, world)) {
                        world.get<ColliderComponent>(entityA).isColliding = true;
                        world.get<ColliderComponent>(entityB).isColliding = true;
                        Collisions::ResolveCollision(entityA, entityB, contact, world);
                    }
                }
            }
        }

        void Render(entt::registry& world) {
            auto view = world.view<TransformComponent, KinematicComponent, ColliderComponent>();
            
            for (auto entity: view) {
                const auto collider = view.get<ColliderComponent>(entity);
                
                if (collider.renderCollider) {
                    const auto transform = view.get<TransformComponent>(entity);
                    collider.shape->Render(transform);
                }
            }
        }
};

#endif