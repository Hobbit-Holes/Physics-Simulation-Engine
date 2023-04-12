#ifndef DAMAGESYSTEM_h
#define DAMAGESYSTEM_h

#include "entt/entt.hpp"
#include "../../Events/CollisionEvent.hh"
#include "../Components/IncludeComponents.hh"

class DamageSystem {
    public:
        void OnDamage(CollisionEvent& event) {
            auto view = event.world->view<TransformComponent, ColliderComponent>();

            for (auto entity: view) {
                auto& transform = view.get<TransformComponent>(entity);
                auto& collision = view.get<ColliderComponent>(entity);    
            }
        }
};

#endif