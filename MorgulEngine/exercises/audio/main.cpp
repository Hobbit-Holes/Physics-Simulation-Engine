#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 400;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);
    engine.luaSounds.script_file("./assets/scripts/sounds.lua");
    engine.lua.script_file("./assets/scripts/entities.lua");

    // Sounds
    engine.SetupSounds();

    // Entities
    std::vector<entt::entity> entities = engine.SetupScene();

    auto& music = engine.world.get<SoundComponent>(entities[1]);
    auto& effect = engine.world.get<SoundComponent>(entities[0]);

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        if (engine.keyboard->spaceKeyPressed) {
            engine.keyboard->spaceKeyPressed = false;

            music.play = true;
        }
        if (engine.keyboard->upKeyPressed) {
            engine.keyboard->upKeyPressed = false;

            effect.play = true;
        }

        engine.Render();
    }

    return 0;
}