#ifndef BALLMOVEMENTSYSTEM_H
#define BALLMOVEMENTSYSTEM_H

#include "entt/entt.hpp"
#include "../../Events/CollisionEvent.hh"
#include "../Components/IncludeComponents.hh"

class BallMovementSystem {
    public:
        void OnCollison(CollisionEvent& collision) {
            auto& entityA = collision.a;
            auto& entityB = collision.b;

            std::string groupA = collision.world->get<NameGroupComponent>(entityA).group;
            std::string groupB = collision.world->get<NameGroupComponent>(entityB).group;

            if (groupA == "Players" && groupB == "Balls") {
                auto& transBall = collision.world->get<TransformComponent>(entityB);
                auto& kim = collision.world->get<KinematicComponent>(entityB);
                auto& mov = collision.world->get<BallMovementComponent>(entityB);

                auto& transPlayer = collision.world->get<TransformComponent>(entityA);
                
                // Velocity
                if (kim.velocity.Magnitude() < mov.maxVelocity) {
                    kim.velocity += kim.velocity.UnitVector() * mov.sumVelocity;
                }

                // Direction
                float direction = 1;
                float desviation = kim.velocity.Angle();
                if (kim.velocity.x > 0) {
                    direction = 1;
                    if (kim.velocity.y < 0) {
                        direction *= -1;
                    }
                    desviation *= direction;
                }
                else {
                    desviation = M_PI - desviation;
                    direction = -1;
                    if (kim.velocity.y < 0) {
                        direction *= -1;
                    }
                    desviation *= direction;
                }

                // Desviation
                if (kim.velocity.Angle() * direction < mov.maxDesviation) {
                    if (transBall.position.y > transPlayer.position.y + 16) {
                        kim.velocity = kim.velocity.Rotate(mov.sumDesviation * direction);
                        mov.numDesviation += 1;
                    } else if (transBall.position.y > transPlayer.position.y - 16) {
                        kim.velocity = kim.velocity.Rotate(mov.sumDesviation * direction);
                        mov.numDesviation += 1;
                    } else {
                        if (mov.numDesviation != 0) {
                            kim.velocity = kim.velocity.Rotate(mov.sumDesviation * direction * -1);
                            mov.numDesviation -= 1;
                        }
                    }
                }
                
                std::cout << "Ball hit Player" << std::endl;
            }

            if (groupA == "Goals" && groupB == "Balls") {
                collision.world->get<KinematicComponent>(entityB).velocity = Vec2(0, 0);

                if (collision.world->get<NameGroupComponent>(entityA).name == "Goal Player 1") {
                    collision.world->get<TransformComponent>(entityB).position = Vec2(350, 400);
                    collision.world->get<BallMovementComponent>(entityB).serve = 1;
                } else if (collision.world->get<NameGroupComponent>(entityA).name == "Goal Player 2") {
                    collision.world->get<TransformComponent>(entityB).position = Vec2(850, 400);
                    collision.world->get<BallMovementComponent>(entityB).serve = 2;
                }
            }
        }
        
        void Update(entt::registry& world, Keyboard* keyboard) {
            auto view = world.view<KinematicComponent, BallMovementComponent>();

            for (auto entity: view) {
                auto& kim = world.get<KinematicComponent>(entity);
                auto& ball = world.get<BallMovementComponent>(entity);

                if (ball.serve == 1) {
                    if (keyboard->spaceKeyPressed == true) {
                        ball.serve = 0;
                        float random = (rand() % 61 - 30) * (M_PI / 180);
                        kim.velocity = Vec2(ball.initialVelocity, 0).Rotate(random);
                    }
                } else if (ball.serve == 2) {
                    if (keyboard->spaceKeyPressed == true) {
                        ball.serve = 0;
                        float random = (rand() % 61 - 30) * (M_PI / 180);
                        kim.velocity = Vec2(ball.initialVelocity * -1, 0).Rotate(random);
                    }
                }
            }
        }
};

#endif