#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Entities
    // const auto campfire = engine.world.create();
    // engine.world.emplace<TransformComponent>(campfire, Vec2(400, 400));
    // engine.world.emplace<SpriteComponent>(campfire, "campfire-fire-spritesheet", 64, 64);
    // engine.world.emplace<AnimationComponent>(campfire, 5, 8, true);

    while (engine.NextFrame()) {
        engine.Update();
        engine.Render();
    }

    return 0;
}