#ifndef RIGIDBODYSYSTEM_H
#define RIGIDBODYSYSTEM_H

#include "../Components/TransformComponent.hh"
#include "../Components/KinematicComponent.hh"
#include "../Components/ParticleComponent.hh"
#include "../Components/RigidBodyComponent.hh"

class RigidBodySystem {
    public:
        void Update(const double dt, entt::registry& world) {
            auto view = world.view<KinematicComponent, RigidBodyComponent>();
            
            for (auto entity: view) {
                auto& kinematic = view.get<KinematicComponent>(entity);
                auto& rb = view.get<RigidBodyComponent>(entity);

                if (!rb.IsStatic()) {
                    kinematic.acceleration = rb.sumForces * rb.invMass;
                    rb.ClearForces();

                    if (rb.I != 0.0) {
                        kinematic.angularAcceleration = rb.sumTorques * rb.invI;
                        rb.ClearTorques();
                    }
                }
            }
        }

        void Render(entt::registry& world) {
            auto view = world.view<TransformComponent, RigidBodyComponent>();

            for (auto entity: view) {
                const auto transform = view.get<TransformComponent>(entity);
                const auto rb = view.get<RigidBodyComponent>(entity);

                rb.shape->Render(transform);
            }
        }
};

#endif