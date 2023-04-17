#ifndef DAMAGESYSTEM_h
#define DAMAGESYSTEM_h

#include "entt/entt.hpp"
#include "../../Events/CollisionEvent.hh"
#include "../Components/IncludeComponents.hh"

class DamageSystem {
    public:
        void OnCollison(CollisionEvent& collision) {
            auto& entityA = collision.a;
            auto& entityB = collision.b;

            std::string groupA = collision.world->get<NameGroupComponent>(entityA).group;
            std::string groupB = collision.world->get<NameGroupComponent>(entityB).group;

            if (groupA == groupB) {
                std::cout << "We are friends" << std::endl;
            } else if (groupA == "Player" && groupB == "Enemy") {
                std::cout << "Oh no, there is an Enemy!" << std::endl;
            } else if (groupA == "Enemy" && groupB == "Player") {
                std::cout << "Oh no, there is an Enemy!" << std::endl;
            } else if (groupA == "Player" && groupB == "Hole") {
                auto& t = collision.world->get<TransformComponent>(entityA);
                auto& k = collision.world->get<KinematicComponent>(entityA);

                t.position = collision.world->get<DamageComponent>(entityA).position;
                k.velocity = Vec2(0, 0);

                std::cout << "I am inside the Hole!" << std::endl;
            } else if (groupA == "Hole" && groupB == "Player") {
                auto& t = collision.world->get<TransformComponent>(entityB);
                auto& k = collision.world->get<KinematicComponent>(entityB);

                t.position = collision.world->get<DamageComponent>(entityB).position;
                k.velocity = Vec2(0, 0);

                std::cout << "I am inside the Hole!" << std::endl;
            } else if (groupA == "Hole" && groupB == "Enemy") {
                auto& t = collision.world->get<TransformComponent>(entityB);
                auto& k = collision.world->get<KinematicComponent>(entityB);

                t.position = collision.world->get<DamageComponent>(entityB).position;
                k.velocity = Vec2(0, 0);

                std::cout << "I am inside the Hole!" << std::endl;
            } else if (groupA == "Enemy" && groupB == "Hole") {
                auto& t = collision.world->get<TransformComponent>(entityA);
                auto& k = collision.world->get<KinematicComponent>(entityA);

                t.position = collision.world->get<DamageComponent>(entityA).position;
                k.velocity = Vec2(0, 0);

                std::cout << "I am inside the Hole!" << std::endl;
            }
        }
};

#endif