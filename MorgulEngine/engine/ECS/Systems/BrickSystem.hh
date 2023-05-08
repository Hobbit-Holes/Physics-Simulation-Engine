#ifndef BRICKSYSTEM_H
#define BRICKSYSTEM_H

#include "entt/entt.hpp"
#include "../../Events/CollisionEvent.hh"
#include "../Components/IncludeComponents.hh"

class BrickSystem {
    public:
        void OnCollison(CollisionEvent& collision) {
            auto& entityA = collision.a;
            auto& entityB = collision.b;

            std::string groupA = collision.world->get<NameGroupComponent>(entityA).group;
            std::string groupB = collision.world->get<NameGroupComponent>(entityB).group;

            if (groupA == "Balls" && groupB == "Bricks") {
                auto& animation = collision.world->get<AnimationComponent>(entityB);
                
                if (animation.startFrame < 3) {
                    animation.startFrame += 1;
                }
                if (animation.startFrame == 3) {
                    animation.numFrames = 3;
                }
            }
        }

        void Update(entt::registry& world) {
            auto view = world.view<NameGroupComponent, ColliderComponent, AnimationComponent>();
            
            for (auto entity: view) {
                if (world.get<NameGroupComponent>(entity).group == "Bricks") {
                    auto& animation = world.get<AnimationComponent>(entity);
                    if (animation.currentFrame == 5) {
                        world.get<ColliderComponent>(entity).resolve = false;
                        animation.numFrames = 1;
                        animation.currentFrame = 6;
                    }
                }
            }
        }
};

#endif