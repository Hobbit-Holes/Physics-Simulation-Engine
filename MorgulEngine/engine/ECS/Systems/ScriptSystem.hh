#ifndef SCRIPTSYSTEM_H
#define SCRIPTSYSTEM_H

#include "entt/entt.hpp"
#include "../Components/IncludeComponents.hh"

class ScriptSystem {
    public:
        void CreateLuaBindings(sol::state& lua) {
            lua.new_usertype<Vec2> (
                "Vec2",
                sol::constructors<Vec2(float, float)> (),
                "x", &Vec2::x,
                "y", &Vec2::y
            );

            lua.set_function("set_position", [](entt::entity entity, entt::registry& world, double x, double y) {
                if (world.all_of<TransformComponent>(entity)) {
                    auto& transform = world.get<TransformComponent>(entity);
                    transform.position = Vec2(x, y);
                } else {
                    Logger::Error("Traying to set the position of an entity that has no transform component");
                }
            });

            lua.set_function("set_velocity", [](entt::entity entity, entt::registry& world, double x, double y) {
                if (world.all_of<KinematicComponent>(entity)) {
                    auto& kinematic = world.get<KinematicComponent>(entity);
                    kinematic.velocity = Vec2(x, y);
                } else {
                    Logger::Error("Traying to set the position of an entity that has no kinematic component");
                }
            });
        }

        void Update(const double dt, const int ellapsedTime, entt::registry& world) {
            auto view = world.view<ScriptComponent>();

            for (auto entity : view) {
                const auto script = view.get<ScriptComponent>(entity);
                script.func(entity, world, dt, ellapsedTime);
            }
        }
};

#endif