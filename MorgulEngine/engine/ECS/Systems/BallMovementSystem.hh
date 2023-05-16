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

            entt::registry* world = collision.world;

            // Resolve collision
            if (groupA == "Balls" && collision.world->get<ColliderComponent>(entityB).resolve == true) {
                collision.world->get<SoundComponent>(entityA).play = true;
                Collisions::ResolvePenetration(collision.a, collision.b, collision.contact, *world);

                // Change direction of the ball
                auto& kim = collision.world->get<KinematicComponent>(entityA);
                
                Vec2 normal = collision.contact.normal;
                
                if (normal.x != 0) {
                    kim.velocity.x *= -1;
                } 
                if (normal.y != 0) {
                    kim.velocity.y *= -1;
                }
            } else if (groupB == "Balls" && collision.world->get<ColliderComponent>(entityA).resolve == true) {
                collision.world->get<SoundComponent>(entityB).play = true;
                Collisions::ResolvePenetration(collision.a, collision.b, collision.contact, *world);

                // Change direction of the ball
                auto& kim = collision.world->get<KinematicComponent>(entityB);
                
                Vec2 normal = collision.contact.normal;
                
                if (normal.x != 0) {
                    kim.velocity.x *= -1;
                } 
                if (normal.y != 0) {
                    kim.velocity.y *= -1;
                }
            }

            // Interaction between the PLayer and the Ball
            if (groupA == "Players" && groupB == "Balls") {
                collision.world->get<SoundComponent>(entityB).play = true;

                auto& transBall = collision.world->get<TransformComponent>(entityB);
                auto& kim = collision.world->get<KinematicComponent>(entityB);
                auto& mov = collision.world->get<BallMovementComponent>(entityB);

                auto& transPlayer = collision.world->get<TransformComponent>(entityA);

                // Player that hit the ball
                if (collision.world->get<NameGroupComponent>(entityA).name == "Player 1") {
                    mov.lastHit = 1;
                } else {
                    mov.lastHit = 2;
                }
                
                // Dont increase the velocity if it is too fast
                if (kim.velocity.Magnitude() < mov.maxVelocity) {
                    kim.velocity += kim.velocity.UnitVector() * mov.sumVelocity;
                }
                if (kim.velocity.Magnitude() > mov.maxVelocity) {
                    kim.velocity = kim.velocity.UnitVector() * mov.maxVelocity;
                }

                // Determine the direction that the ball will be desviated and which angle
                Vec2 velocity = kim.velocity;
                float desviation = 0;

                if (transBall.position.y > transPlayer.position.y + 16) {
                    velocity.y = abs(velocity.y);

                    if (abs(M_PI - velocity.Angle()) > mov.maxDesviation) {
                        if (velocity.x > 0) {
                            desviation = mov.sumDesviation;
                        } else {
                            desviation = mov.sumDesviation * -1;
                        }
                        mov.numDesviation += 1;
                    }
                } else if (transBall.position.y < transPlayer.position.y - 16) {
                    velocity.y = abs(velocity.y) * -1;

                    if (abs(M_PI - velocity.Angle()) > mov.maxDesviation) {
                        if (velocity.x > 0) {
                            desviation = mov.sumDesviation * -1;
                        } else {
                            desviation = mov.sumDesviation;
                        }
                        mov.numDesviation += 1;
                    }
                } else {
                    if (mov.numDesviation > 0) {
                        if (velocity.y > 0) {
                            if (velocity.x > 0) {
                                desviation = mov.sumDesviation * -1;
                            } else {
                                desviation = mov.sumDesviation;
                            }
                        } else {
                            if (velocity.x > 0) {
                                desviation = mov.sumDesviation;
                            } else {
                                desviation = mov.sumDesviation * -1;
                            }
                        }
                        mov.numDesviation -= 1;
                    }
                }

                kim.velocity = velocity.Rotate(desviation);
            }

            // Interaction between the Goal and the Ball
            if (groupA == "Goals" && groupB == "Balls") {
                // Reset velocity if any player is scored
                collision.world->get<KinematicComponent>(entityB).velocity = Vec2(0, 0);

                // Change sprite of the ball
                int random = rand() % 4 + 1;
                collision.world->get<SpriteComponent>(entityB).assetId = "Ball" + std::to_string(random);

                // Reset of the positions and determine the one who serve
                if (collision.world->get<NameGroupComponent>(entityA).name == "Goal Player 1") {
                    collision.world->get<TransformComponent>(entityB).position = Vec2(350, 400);
                    collision.world->get<BallMovementComponent>(entityB).serve = 1;
                    collision.world->get<SoundComponent>(entityA).play = true;
                } else if (collision.world->get<NameGroupComponent>(entityA).name == "Goal Player 2") {
                    collision.world->get<TransformComponent>(entityB).position = Vec2(850, 400);
                    collision.world->get<BallMovementComponent>(entityB).serve = 2;
                    collision.world->get<SoundComponent>(entityA).play = true;
                }
            }
        }
        
        void Update(entt::registry& world, Keyboard* keyboard) {
            auto view = world.view<KinematicComponent, BallMovementComponent>();

            for (auto entity: view) {
                auto& kim = world.get<KinematicComponent>(entity);
                auto& ball = world.get<BallMovementComponent>(entity);

                // Player who serve
                if (ball.serve == 1) {
                    if (keyboard->spaceKeyPressed == true) {
                        ball.serve = 0;
                        float random = (rand() % 61 - 30) * (M_PI / 180);
                        kim.velocity = Vec2(ball.initialVelocity, 0).Rotate(random);

                        ball.lastHit = 1;
                    }
                } else if (ball.serve == 2) {
                    if (keyboard->spaceKeyPressed == true) {
                        ball.serve = 0;
                        float random = (rand() % 61 - 30) * (M_PI / 180);
                        kim.velocity = Vec2(ball.initialVelocity * -1, 0).Rotate(random);
                        
                        ball.lastHit = 2;
                    }
                }
            }
        }
};

#endif