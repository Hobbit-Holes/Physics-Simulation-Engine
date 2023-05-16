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
                    if (brick.restingLifes == 0) {
                        animation.numFrames = 11;
                        animation.frameSpeedRate = 8;
                        animation.startTime = SDL_GetTicks();
                    }
                }
            } else if (groupA == "Balls" && groupB == "Bonus") {
                auto& animation = collision.world->get<AnimationComponent>(entityB);
                auto& brick = collision.world->get<BrickComponent>(entityB);

                auto& ball = collision.world->get<BallMovementComponent>(entityA);
                
                // Break the Brick
                if (brick.restingLifes > 0) {
                    brick.restingLifes -= 1;
                    animation.startFrame += 1;
                    animation.numFrames = 11;
                    animation.frameSpeedRate = 8;
                    animation.startTime = SDL_GetTicks();

                    // Give PowerUps / Boosters
                    if (collision.world->get<NameGroupComponent>(entityB).name == "Bonus Racket") {
                        auto view = collision.world->view<NameGroupComponent, RacketControllerComponent>();

                        for (auto entity: view) {
                            if (collision.world->get<NameGroupComponent>(entity).name == "Player " + std::to_string(ball.lastHit)) {
                                collision.world->get<RacketControllerComponent>(entity).extend = true;      // Expand racket
                            }
                        }
                    } else if (collision.world->get<NameGroupComponent>(entityB).name == "Bonus Speed") {
                        auto& kim = collision.world->get<KinematicComponent>(entityA);
                        Vec2 velocity = kim.velocity;
                        kim.velocity = velocity.UnitVector() * ball.initialVelocity;
                    } else if (collision.world->get<NameGroupComponent>(entityB).name == "Bonus Restart") {
                        collision.world->get<KinematicComponent>(entityA).velocity = Vec2(0, 0);

                        // Reset of the positions and determine the one who serve
                        if (ball.lastHit == 1) {
                            collision.world->get<TransformComponent>(entityA).position = Vec2(350, 400);
                        } else if (ball.lastHit == 2) {
                            collision.world->get<TransformComponent>(entityA).position = Vec2(850, 400);
                        }
                        
                        ball.serve = ball.lastHit;
                    }
                }
            }
        }

        void Update(entt::registry& world) {
            auto view = world.view<NameGroupComponent, ColliderComponent, AnimationComponent, BrickComponent>();
            
            for (auto entity: view) {
                auto& animation = world.get<AnimationComponent>(entity);
                auto& brick = world.get<BrickComponent>(entity);
                
                if (world.get<NameGroupComponent>(entity).group == "Bricks") {

                    // Remove collider when die
                    if (animation.startFrame > 2) {
                        world.get<ColliderComponent>(entity).resolve = false;
                    }

                    // After the animation of destruction, the brick dissapear
                    if (animation.currentFrame == brick.numLifes + 10) {
                        animation.startFrame = brick.numLifes + 10;
                        animation.frameSpeedRate = 1;
                        animation.numFrames = 1;
                    }
                } else if (world.get<NameGroupComponent>(entity).group == "Bonus") {
                    // Remove collider when die
                    if (animation.startFrame > 0) {
                        world.get<ColliderComponent>(entity).resolve = false;
                    }

                    // After the animation of destruction, the brick dissapear
                    if (animation.currentFrame == brick.numLifes + 10) {
                        animation.startFrame = brick.numLifes + 10;
                        animation.frameSpeedRate = 1;
                        animation.numFrames = 1;
                    }
                }
            }
        }

        void Start(entt::registry& world) {
            auto view = world.view<BrickComponent, AnimationComponent>();
            
            for (auto entity: view) {
                const auto brick = world.get<BrickComponent>(entity);
                auto& anim = world.get<AnimationComponent>(entity);
                
                anim.startFrame = brick.numLifes - brick.restingLifes;
            }
        }
};

#endif