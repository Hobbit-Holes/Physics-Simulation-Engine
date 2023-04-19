#include "MorgulEngine.hh"
#include <sol/sol.hpp>
#include <iostream>

void setup_scene(MorgulEngine &engine) {
    sol::table lua_table = engine.lua["table"];

    // Player
    sol::table playerBall = engine.lua["player"];
    Color color = Color(playerBall["color"]["r"], playerBall["color"]["g"], playerBall["color"]["b"]);

    CircleShape circ = CircleShape(playerBall["radius"], color, true);
    CircleShape &ref_Circ = circ;

    auto player = engine.world.create();
    engine.world.emplace<TransformComponent>(player, Vec2(playerBall["x"], playerBall["y"]));
    engine.world.emplace<KinematicComponent>(player);
    engine.world.emplace<ColliderComponent>(player, ref_Circ);
    engine.world.emplace<RigidBodyComponent>(player, 1.0f, ref_Circ);
    engine.world.emplace<NameGroupComponent>(player, "Player", "Players");

    // Balls
    sol::table lua_balls = engine.lua["enemies"];
    for(int i = 1; i <= static_cast<int>(lua_balls.size()); i++) {
        int x = lua_balls[i]["x"];
        int y = lua_balls[i]["y"];

        int radius = lua_balls[i]["radius"];
        Color color = Color(lua_balls[i]["color"]["r"], lua_balls[i]["color"]["g"], lua_balls[i]["color"]["b"]);

        CircleShape circ = CircleShape(radius, color, true);
        CircleShape &ref_Circ = circ;

        auto ball = engine.world.create();
        engine.world.emplace<TransformComponent>(ball, Vec2(x, y));
        engine.world.emplace<KinematicComponent>(ball);
        engine.world.emplace<ColliderComponent>(ball, ref_Circ);
        engine.world.emplace<RigidBodyComponent>(ball, 1.0f, ref_Circ);
        engine.world.emplace<NameGroupComponent>(ball, "Enemy " + std::to_string(i), "Enemys");
    }

    // Holes
    sol::table lua_holes = engine.lua["holes"];
    for(int i = 1; i <= static_cast<int>(lua_holes.size()); i++) {
        int x = lua_holes[i]["x"];
        int y = lua_holes[i]["y"];

        int radius = lua_holes[i]["radius"];
        Color color = Color(lua_holes[i]["color"]["r"], lua_holes[i]["color"]["g"], lua_holes[i]["color"]["b"]);

        CircleShape circ = CircleShape(radius, color, true);
        CircleShape &ref_Circ = circ;

        auto hole = engine.world.create();
        engine.world.emplace<TransformComponent>(hole, Vec2(x, y));
        engine.world.emplace<KinematicComponent>(hole);
        engine.world.emplace<ColliderComponent>(hole, ref_Circ);
        engine.world.emplace<RigidBodyComponent>(hole, 1.0f, ref_Circ);
        engine.world.emplace<NameGroupComponent>(hole, "Hole " + std::to_string(i), "Holes");
    }

    // Walls
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
        engine.world.emplace<RigidBodyComponent>(wall, 1.0f, ref_Rect);
    }

    // Floor
    sol::table floor = engine.lua["floor"];
    color = Color(floor["color"]["r"], floor["color"]["g"], floor["color"]["b"]);

    RectangleShape rect = RectangleShape(floor["width"], floor["heigth"], color, true);
    RectangleShape &ref_Rect = rect;

    auto wall = engine.world.create();
    engine.world.emplace<TransformComponent>(wall, Vec2(floor["x"], floor["y"]));
    engine.world.emplace<KinematicComponent>(wall);
    engine.world.emplace<RigidBodyComponent>(wall, 1.0f, ref_Rect);
}

int main(int argc, char* argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);
    engine.lua.script_file("./snooker.lua");
    setup_scene(engine);
    
    while (engine.NextFrame()) {
        engine.Update();
        engine.Render();
    }

    return 0;
}