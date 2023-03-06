#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Object
    const auto ball = engine.world.create();
    engine.world.emplace<TransformComponent>(ball, Vec2(width/2, heigth/2));
    engine.world.emplace<KinematicComponent>(ball, Vec2(0, -150), Vec2(0, 75));

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        // Logic
        const auto transform = engine.world.get<TransformComponent>(ball);
        Graphics::DrawFillCircle(transform.position.x, transform.position.y, 25, Color::Cyan());

        engine.Render();
    }

    return 0;
}