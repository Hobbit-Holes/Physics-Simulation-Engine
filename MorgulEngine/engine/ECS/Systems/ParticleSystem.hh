#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "../Components/TransformComponent.hh"
#include "../Components/KinematicComponent.hh"
#include "../Components/ParticleComponent.hh"

class ParticleSystem {
    public:
        void Update(entt::registry& world) {
            auto view = world.view<KinematicComponent, ParticleComponent>();

            for (auto entity: view) {
                auto& kinematic = view.get<KinematicComponent>(entity);
                auto& rb = view.get<ParticleComponent>(entity);

                kinematic.acceleration = rb.sumForces * rb.invMass;
                rb.angle += kinematic.angularVelocity * M_PI/180;
                rb.ClearForces();
            }
        }

        void Render(entt::registry& world) {
            auto view = world.view<TransformComponent, ParticleComponent>();

            for (auto entity: view) {
                const auto transform = view.get<TransformComponent>(entity);
                const auto particle = view.get<ParticleComponent>(entity);
                if(particle.render) {
                    Graphics::DrawFillCircle(transform.position.x, transform.position.y, particle.radius, particle.color);
                }
                else {
                    Graphics::DrawCircle(transform.position.x, transform.position.y, particle.radius, particle.angle, particle.color);
                }
            }
        }
};

#endif