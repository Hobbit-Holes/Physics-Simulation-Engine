#ifndef SCRIPTCOMPONENT_H
#define SCRIPTCOMPONENT_H

#include <sol/sol.hpp>
#include <iostream>

struct ScriptComponent {
    sol::function func;

    ScriptComponent(sol::function func = sol::lua_nil) {
        this->func = func;
    }
};

#endif