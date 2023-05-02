#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);
    engine.luaTextures.script_file("./assets/scripts/sprites.lua");
    engine.luaSounds.script_file("./assets/scripts/sounds.lua");
    engine.luaFonts.script_file("./assets/scripts/fonts.lua");
    engine.lua.script_file("./assets/scripts/entities.lua");

    // Events
    AnimatedMovementSystem animMovSystem;
    engine.eventBus.sink<KeyDownEvent>().connect<&AnimatedMovementSystem::OnKeyDown>(animMovSystem);

    // Add Textures
    engine.SetupTextures();

    // Add sounds
    engine.SetupSounds();

    // Fonts
    engine.SetupFonts();

    // Variables
    float velocity = engine.lua["velocity"].get_or(50);

    // Entities
    std::vector<entt::entity> entities = engine.SetupScene();
    
    entt::entity player = entities[0];
    entt::entity title = entities[1];
    
    auto& kinematic = engine.world.get<KinematicComponent>(player);
    auto& sound = engine.world.get<SoundComponent>(player);
    auto& text = engine.world.get<FontComponent>(title);
    
    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        if (engine.keyboard->downKeyPressed == true) {
            engine.keyboard->downKeyPressed = false;
            kinematic.velocity = Vec2(0, velocity);
            sound.play = true;
            text.text = "DOWN";
        } else if (engine.keyboard->upKeyPressed == true) {
            engine.keyboard->upKeyPressed = false;
            kinematic.velocity = Vec2(0, -velocity);
            sound.play = true;
            text.text = "UP";
        } else if (engine.keyboard->rightKeyPressed == true) {
            engine.keyboard->rightKeyPressed = false;
            kinematic.velocity = Vec2(velocity, 0);
            sound.play = true;
            text.text = "RIGHT";
        } else if (engine.keyboard->leftKeyPressed == true) {
            engine.keyboard->leftKeyPressed = false;
            kinematic.velocity = Vec2(-velocity, 0);
            sound.play = true;
            text.text = "LEFT";
        } else if (engine.keyboard->spaceKeyPressed == true) {
            engine.keyboard->spaceKeyPressed = false;
            kinematic.velocity = Vec2(0, 0);
            sound.play = true;
            text.text = "PAUSE";
        }

        engine.Render();
    }

    return 0;
}