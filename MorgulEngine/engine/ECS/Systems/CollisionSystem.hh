#ifndef COLLISIONSYSTEM_HH
#define COLLISIONSYSTEM_HH

#include "entt/entt.hpp"
#include "../../Collisions.hh"
#include "../../Events/CollisionEvent.hh"
#include "../Components/IncludeComponents.hh"

class CollisionSystem {
    public:
        void Update(entt::dispatcher& enventBus, entt::registry& world) {
            auto view = world.view<TransformComponent, KinematicComponent, RigidBodyComponent, ColliderComponent>();

            //Reset the collision flag to false
            for (auto entity : view) {
                auto& collider = view.get<ColliderComponent>(entity);
                collider.isColliding = false;
            }

            //Check every entity with the next one for collisions
            for (auto entityA : view) {
                const auto transformA = world.get<TransformComponent>(entityA);

                for (auto entityB : view) {
                    if (entityA == entityB) {
                        break;
                    }

                    const auto transformB = world.get<TransformComponent>(entityB);

                    if ((transformA.position - transformB.position).Magnitude() > 5000) {
                        break;
                    }

                    Contact contact;
                    if (Collisions::IsColliding(entityA, entityB, contact, world)) {
                        enventBus.trigger(CollisionEvent(entityA, entityB, world, contact));
                        world.get<ColliderComponent>(entityA).isColliding = true;
                        world.get<ColliderComponent>(entityB).isColliding = true;

                        if (world.get<ColliderComponent>(entityA).resolve == true && world.get<ColliderComponent>(entityB).resolve == true) {
                            Collisions::ResolveCollision(entityA, entityB, contact, world);
                        }
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