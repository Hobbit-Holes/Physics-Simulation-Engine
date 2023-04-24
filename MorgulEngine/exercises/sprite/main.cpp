#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);
    engine.luaTextures.script_file("./assets/scripts/sprites.lua");
    engine.lua.script_file("./assets/scripts/entities.lua");

    // Add Textures
    engine.SetupTextures();

    // Entities
    std::vector<entt::entity> entities = engine.SetupScene();

    entt::entity smallSpaceship = entities[0];
    entt::entity bigSpaceship = entities[1];
    
    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        auto & smallSpaceshipTransform = engine.world.get<TransformComponent>(smallSpaceship);
        smallSpaceshipTransform.rotation += 1;

        auto & bigSpaceshipTransform = engine.world.get<TransformComponent>(bigSpaceship);
        bigSpaceshipTransform.scale = Vec2(1.5, 1.5) * sin(engine.GetTotalTimeInMilliSeconds() * 0.001);

        engine.Render();
    }

    return 0;
}