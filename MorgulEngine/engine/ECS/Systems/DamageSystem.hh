#ifndef DAMAGESYSTEM_h
#define DAMAGESYSTEM_h

#include "entt/entt.hpp"
#include "../../Events/CollisionEvent.hh"
#include "../Components/IncludeComponents.hh"

class DamageSystem {
    public:
        void onCollison(entt::dispatcher& enventBus, entt::registry& registry) {
            auto colliders = registry.view<ColliderComponent>();
            for (auto entity : colliders) {
                auto& collider = colliders.get<ColliderComponent>(entity);

                if (collider.isColliding) {
                    auto groups = registry.view<NameGroupComponent>();
                    auto& group = groups.get<NameGroupComponent>(entity);

                    if (group.group == "Enemy") {
                        std::cout << "Enemy hit enemy!" << std::endl;
                    } else if (group.group == "Player") {
                        std::cout << "Player hit by enemy!" << std::endl;
                    }
                }
                collider.isColliding = false;
            }
            
        }
};
#endif