#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Add Textures
    Graphics::AddTexture("dango_01", "./dango_01.png");

    // Entities
    const auto smallSpaceship = engine.world.create();
    engine.world.emplace<TransformComponent>(smallSpaceship, Vec2(400, 400));
    engine.world.emplace<SpriteComponent>(smallSpaceship, "dango_01", 32, 32);

    const auto bigSpaceship = engine.world.create();
    engine.world.emplace<TransformComponent>(bigSpaceship, Vec2(200, 600), 0 , Vec2(2, 2));
    engine.world.emplace<SpriteComponent>(bigSpaceship, "dango_01", 32, 32);

    
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