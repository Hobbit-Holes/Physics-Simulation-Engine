#include "MorgulEngine.hh"

void setup_scene(MorgulEngine &engine) {
    sol::table entities = engine.lua["entities"];

    for (int i = 1; i <= static_cast<int>(entities.size()); i++) {
        sol::table lua_entity = entities[i];
        entt::entity newEntity = engine.world.create();

        // Group
        sol::optional<std::string> group = lua_entity["group"];
        sol::optional<std::string> name = lua_entity["name"];
        if (group != sol::nullopt && name != sol::nullopt) {
            engine.world.emplace<NameGroupComponent>(newEntity,  (std::string) lua_entity["name"], (std::string) lua_entity["group"]);
        }

        // Components
        sol::optional<sol::table> hasComponents = lua_entity["components"];
        if (hasComponents != sol::nullopt) {
            // Transform
            sol::optional<sol::table> transform = lua_entity["components"]["transform"];
            if (transform != sol::nullopt) {
                engine.world.emplace<TransformComponent>(newEntity,
                    Vec2(lua_entity["components"]["transform"]["position"]["x"], lua_entity["components"]["transform"]["position"]["y"]),
                    lua_entity["components"]["transform"]["rotation"].get_or(0.0),
                    Vec2(lua_entity["components"]["transform"]["scale"]["x"].get_or(1.0), lua_entity["components"]["transform"]["scale"]["y"].get_or(1.0))
                );

            }

            // Kinematic
            sol::optional<sol::table> kinematic = lua_entity["components"]["kinematic"];
            if (kinematic != sol::nullopt) {
                engine.world.emplace<KinematicComponent>(newEntity, 
                    Vec2(lua_entity["components"]["kinematic"]["velocity"]["x"], lua_entity["components"]["kinematic"]["velocity"]["y"]),
                    Vec2(lua_entity["components"]["kinematic"]["acceleration"]["x"].get_or(0.0), lua_entity["components"]["kinematic"]["acceleration"]["y"].get_or(0.0)),
                    lua_entity["components"]["kinematic"]["angularVelocity"].get_or(0.0),
                    lua_entity["components"]["kinematic"]["angularAcceleration"].get_or(0.0)
                );
            }

            // Collider
            sol::optional<sol::table> collider = lua_entity["components"]["collider"];
            if (collider != sol::nullopt) {
                std::string aux = lua_entity["components"]["collider"]["shape"]["type"];
                if ((std::string) lua_entity["components"]["collider"]["shape"]["type"] == "circle") {
                    CircleShape fig = CircleShape(
                        lua_entity["components"]["collider"]["shape"]["radius"], 
                        Color(
                            lua_entity["components"]["collider"]["shape"]["color"]["r"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["g"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["b"]),
                        false);
                    CircleShape &fig_Fig = fig;

                    engine.world.emplace<ColliderComponent>(newEntity, fig_Fig);
                } else if ((std::string) lua_entity["components"]["collider"]["shape"]["type"] == "rectangle") {
                    RectangleShape fig = RectangleShape(
                        lua_entity["components"]["collider"]["shape"]["width"],
                        lua_entity["components"]["collider"]["shape"]["height"], 
                        Color(
                            lua_entity["components"]["collider"]["shape"]["color"]["r"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["g"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["b"]),
                        lua_entity["components"]["collider"]["shape"]["filled"].get_or(false));
                    RectangleShape &fig_Fig = fig;
;
                    engine.world.emplace<ColliderComponent>(newEntity, fig_Fig);
                } else {
                    RegularPolygonShape fig = RegularPolygonShape(
                        lua_entity["components"]["collider"]["shape"]["radius"],
                        lua_entity["components"]["collider"]["shape"]["vertices"], 
                        Color(
                            lua_entity["components"]["collider"]["shape"]["color"]["r"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["g"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["b"]),
                        lua_entity["components"]["collider"]["shape"]["filled"].get_or(false));
                    RegularPolygonShape &fig_Fig = fig;

                    engine.world.emplace<ColliderComponent>(newEntity, fig_Fig);
                }
            }

            // RigidBody
            sol::optional<sol::table> rigidbody = lua_entity["components"]["rigidbody"];
            if (rigidbody != sol::nullopt) {
                if ((std::string) lua_entity["components"]["rigidbody"]["shape"]["type"] == "circle") {
                    CircleShape fig = CircleShape(
                        lua_entity["components"]["rigidbody"]["shape"]["radius"], 
                        Color(
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["r"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["g"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["b"]),
                        lua_entity["components"]["rigidbody"]["shape"]["filled"].get_or(false));
                    CircleShape &fig_Fig = fig;

                    engine.world.emplace<RigidBodyComponent>(newEntity, lua_entity["components"]["rigidbody"]["mass"], fig_Fig, lua_entity["components"]["rigidbody"]["isStatic"].get_or(false));
                } else if ((std::string) lua_entity["components"]["rigidbody"]["shape"]["type"] == "rectangle") {
                    RectangleShape fig = RectangleShape(
                        lua_entity["components"]["rigidbody"]["shape"]["width"],
                        lua_entity["components"]["rigidbody"]["shape"]["height"], 
                        Color(
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["r"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["g"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["b"]),
                        lua_entity["components"]["rigidbody"]["shape"]["filled"].get_or(false));
                    RectangleShape &fig_Fig = fig;

                    engine.world.emplace<RigidBodyComponent>(newEntity, lua_entity["components"]["rigidbody"]["mass"], fig_Fig, lua_entity["components"]["rigidbody"]["isStatic"].get_or(false));
                } else if ((std::string) lua_entity["components"]["rigidbody"]["shape"]["type"] == "regularPolygon") {
                    RegularPolygonShape fig = RegularPolygonShape(
                        lua_entity["components"]["rigidbody"]["shape"]["radius"],
                        lua_entity["components"]["rigidbody"]["shape"]["vertices"], 
                        Color(
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["r"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["g"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["b"]),
                        lua_entity["components"]["rigidbody"]["shape"]["filled"].get_or(false));
                    RegularPolygonShape &fig_Fig = fig;

                    engine.world.emplace<RigidBodyComponent>(newEntity, lua_entity["components"]["rigidbody"]["mass"], fig_Fig, lua_entity["components"]["rigidbody"]["isStatic"].get_or(false));
                } else {
                    StarShape fig = StarShape(
                        lua_entity["components"]["rigidbody"]["shape"]["radius"],
                        lua_entity["components"]["rigidbody"]["shape"]["vertices"], 
                        Color(
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["r"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["g"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["b"]),
                        lua_entity["components"]["rigidbody"]["shape"]["filled"].get_or(false));
                    StarShape &fig_Fig = fig;

                    engine.world.emplace<RigidBodyComponent>(newEntity, lua_entity["components"]["rigidbody"]["mass"], fig_Fig, lua_entity["components"]["rigidbody"]["isStatic"].get_or(false));
                }
            }

            // Scripts
            sol::optional<sol::table> script = lua_entity["component"]["on_update_script"];
            if (script != sol::nullopt) {
                sol::function func = lua_entity["component"]["on_update_script"][1];
                engine.world.emplace<ScriptComponent>(newEntity, func);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);
    engine.lua.script_file("./script-component-03.lua");
    setup_scene(engine);
    
    while (engine.NextFrame()) {
        engine.Update();
        engine.Render();
    }

    return 0;
}