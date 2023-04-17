#include "MorgulEngine.hh"
#include <sol/sol.hpp>
#include <iostream>

void setup_scene(MorgulEngine &engine) {
    sol::table lua_table = engine.lua["table"];

    sol::table lua_walls = engine.lua["walls"];
    for(int i = 1; i <= static_cast<int>(lua_walls.size()); i++) {
        int x = lua_walls[i]["x"];
        int y = lua_walls[i]["y"];

        int width = lua_walls[i]["width"];
        int heigth = lua_walls[i]["heigth"];
        Color color = Color(lua_walls[i]["color"]["r"], lua_walls[i]["color"]["g"], lua_walls[i]["color"]["b"]);

        RectangleShape rect = RectangleShape(width, heigth, color, true);
        RectangleShape &ref_Rect = rect;

        auto wall = engine.world.create();
        engine.world.emplace<TransformComponent>(wall, Vec2(x, y));
        engine.world.emplace<KinematicComponent>(wall);
        engine.world.emplace<ColliderComponent>(wall, ref_Rect);
        engine.world.emplace<RigidBodyComponent>(wall, 1.0f, ref_Rect);
    }
}

int main(int argc, char* argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    engine.lua.open_libraries(sol::lib::base);
    engine.lua.script_file("./myfirstscriptlua.lua");
    setup_scene(engine);
    
    while (engine.NextFrame()) {
        engine.Update();

        engine.Render();
    }

    return 0;
}