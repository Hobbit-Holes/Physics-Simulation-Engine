#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);
    engine.luaTextures.script_file("./assets/scripts/sprites.lua");
    engine.lua.script_file("./assets/scripts/entities.lua");

    // Events
    AnimatedMovementSystem animMovSystem;
    engine.eventBus.sink<KeyDownEvent>().connect<&AnimatedMovementSystem::OnKeyDown>(animMovSystem);

    // Add Textures
    engine.SetupTextures();

    // Variables
    float velocity = engine.lua["velocity"].get_or(50);

    // Entities
    std::vector<entt::entity> entities = engine.SetupScene();
    
    entt::entity player = entities[0];
    auto& kinematic = engine.world.get<KinematicComponent>(player);

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        if (engine.keyboard->downKeyPressed == true) {
            engine.keyboard->downKeyPressed = false;
            kinematic.velocity = Vec2(0, velocity);
        } else if (engine.keyboard->upKeyPressed == true) {
            engine.keyboard->upKeyPressed = false;
            kinematic.velocity = Vec2(0, -velocity);
        } else if (engine.keyboard->rightKeyPressed == true) {
            engine.keyboard->rightKeyPressed = false;
            kinematic.velocity = Vec2(velocity, 0);
        } else if (engine.keyboard->leftKeyPressed == true) {
            engine.keyboard->leftKeyPressed = false;
            kinematic.velocity = Vec2(-velocity, 0);
        } else if (engine.keyboard->spaceKeyPressed == true) {
            engine.keyboard->spaceKeyPressed = false;
            kinematic.velocity = Vec2(0, 0);
        }

        engine.Render();
    }

    return 0;
}