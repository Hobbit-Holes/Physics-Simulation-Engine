#ifndef SCRIPTSYSTEM_H
#define SCRIPTSYSTEM_H

#include "entt/entt.hpp"
#include "../Components/IncludeComponents.hh"

class ScriptSystem { //:public System {
    public:
        void Update(entt::registry& world) {
            auto view = world.view<ScriptComponent>();

            for (auto entity : view) {
                const auto script = view.get<ScriptComponent>(entity);
                script.func();
            }
        }
};

#endif