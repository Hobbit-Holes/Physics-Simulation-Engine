#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);
    engine.luaTextures.script_file("./assets/scripts/sprites.lua");
    engine.lua.script_file("./assets/scripts/entities.lua");

    // Events
    AnimatedMovementSystem animMovSystem;
    engine.eventBus.sink<KeyDownEvent>().connect<&AnimatedMovementSystem::OnKeyDown>(animMovSystem);

    // Add Textures
    engine.SetupTextures();

    // Entities
    std::vector<entt::entity> entities = engine.SetupScene();

    while (engine.NextFrame()) {
        engine.Update();
        engine.Render();
    }

    return 0;
}