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

            if (groupA == "Balls" && groupB == "Players") {
                auto& transBall = collision.world->get<TransformComponent>(entityA);
                auto& kim = collision.world->get<KinematicComponent>(entityA);
                const auto mov = collision.world->get<BallMovementComponent>(entityA);

                auto& transPlayer = collision.world->get<TransformComponent>(entityB);
                
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
                    if (transBall.position.y > transPlayer.position.y + 32) {
                        kim.velocity = kim.velocity.Rotate(mov.sumDesviation * direction);
                    } else if (transBall.position.y > transPlayer.position.y - 32) {
                        kim.velocity = kim.velocity.Rotate(mov.sumDesviation * direction);
                    } else {
                        kim.velocity = kim.velocity.Rotate(mov.sumDesviation * direction * -1);
                    }
                }
                
                std::cout << "Ball hit Player" << std::endl;
            } else if (groupA == "Players" && groupB == "Balls") {
                auto& transBall = collision.world->get<TransformComponent>(entityB);
                auto& kim = collision.world->get<KinematicComponent>(entityB);
                const auto mov = collision.world->get<BallMovementComponent>(entityB);

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
                    if (transBall.position.y > transPlayer.position.y + 32) {
                        kim.velocity = kim.velocity.Rotate(mov.sumDesviation * direction);
                    } else if (transBall.position.y > transPlayer.position.y - 32) {
                        kim.velocity = kim.velocity.Rotate(mov.sumDesviation * direction);
                    } else {
                        kim.velocity = kim.velocity.Rotate(mov.sumDesviation * direction * -1);
                    }
                }
                
                std::cout << "Ball hit Player" << std::endl;
            }

            if (groupA == "Balls" && groupB == "Goals") {
                collision.world->get<TransformComponent>(entityA).position = Vec2(600, 400);
            } else if (groupA == "Goals" && groupB == "Balls") {
                collision.world->get<TransformComponent>(entityB).position = Vec2(600, 400);
            }
        }
};

#endif