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
                auto& brick = collision.world->get<BrickComponent>(entityB);
                
                // If the brick is kick but has lives, it will not break
                if (brick.restingLifes > 0) {
                    animation.startFrame += 1;
                    brick.restingLifes -= 1;
                    
                    // If the brick is kick but has no lives, it will has an animation and the it will be destroyed
                    if (brick.restingLifes <= 0) {
                        collision.world->get<ColliderComponent>(entityB).resolve = false;
                        animation.numFrames = 4;
                        animation.frameSpeedRate = 1;
                    }
                }
            }
        }

        void Update(entt::registry& world) {
            auto view = world.view<ColliderComponent, AnimationComponent, BrickComponent>();
            
            for (auto entity: view) {
                auto& animation = world.get<AnimationComponent>(entity);
                auto& brick = world.get<BrickComponent>(entity);

                // After the animation of destruction, the brick dissapear
                if (animation.currentFrame == brick.numLifes + 3) {
                    animation.startFrame = brick.numLifes + 3;
                    animation.frameSpeedRate = 1;
                    animation.numFrames = 1;
                }
            }
        }

        void Start(entt::registry& world) {
            auto view = world.view<BrickComponent, SpriteComponent, AnimationComponent>();
            
            for (auto entity: view) {
                const auto brick = world.get<BrickComponent>(entity);
                auto& anim = world.get<AnimationComponent>(entity);

                if (brick.restingLifes == 1) {
                    world.get<SpriteComponent>(entity).assetId == "Bricks";
                    anim.startFrame = brick.numLifes - 1;
                } else if (brick.restingLifes == 2) {
                    world.get<SpriteComponent>(entity).assetId == "Bricks";
                    anim.startFrame = brick.numLifes - 2;
                } else if (brick.restingLifes == 3) {
                    world.get<SpriteComponent>(entity).assetId == "Bricks";
                    anim.startFrame = brick.numLifes - 3;
                }
            }
        }
};

#endif