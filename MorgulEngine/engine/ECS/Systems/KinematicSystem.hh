#ifndef KINEMATICSYSTEM_H
#define KINEMATICSYSTEM_H

#include "../Components/TransformComponent.hh"
#include "../Components/KinematicComponent.hh"

class KinematicSystem {
    public:
        void Update(const double dt, entt::registry& world) {
            auto view = world.view<TransformComponent, KinematicComponent>();

            for (auto entity: view) {
                auto& transform = view.get<TransformComponent>(entity);
                auto& kinematic = view.get<KinematicComponent>(entity);

                kinematic.velocity += kinematic.acceleration * dt;
                transform.position += kinematic.velocity * dt;
            }
        }
};

#endif