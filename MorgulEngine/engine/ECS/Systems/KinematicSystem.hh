#ifndef KINEMATICSYSTEM_H
#define KINEMATICSYSTEM_H

#include "../Components/TransformComponent.hh"
#include "../Components/KinematicComponent.hh"
#include "../Components/RigidBodyComponent.hh"

class KinematicSystem {
    public:
        void Update(const double dt, entt::registry& world) {
            auto view = world.view<TransformComponent, KinematicComponent>();

            for (auto entity: view) {
                auto& transform = view.get<TransformComponent>(entity);
                auto& kinematic = view.get<KinematicComponent>(entity);

                kinematic.velocity += kinematic.acceleration * dt;
                transform.position += kinematic.velocity * dt;

                kinematic.angularVelocity += kinematic.angularAcceleration * dt;
                transform.rotation += kinematic.angularVelocity * dt;

                if (world.all_of<RigidBodyComponent>(entity)) {
                    Shape* shape;
                    shape = world.get<RigidBodyComponent>(entity).shape;

                    if (shape->GetType() == RECTANGLE || shape->GetType() == POLYGON) {
                        PolygonShape* polygonShape = (PolygonShape*) world.get<RigidBodyComponent>(entity).shape;
                        polygonShape->UpdateVertices(transform.rotation, transform.position);
                    }
                }

                if (world.all_of<ColliderComponent>(entity)) {
                    Shape* shape;
                    shape = world.get<ColliderComponent>(entity).shape;

                    if (shape->GetType() == RECTANGLE || shape->GetType() == POLYGON) {
                        PolygonShape* polygonShape = (PolygonShape*) world.get<ColliderComponent>(entity).shape;
                        polygonShape->UpdateVertices(transform.rotation, transform.position);
                    }
                }
            }
        }
};

#endif