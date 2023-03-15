#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Object
    const auto ball = engine.world.create();
    engine.world.emplace<TransformComponent>(ball, Vec2(50, heigth/2));
    engine.world.emplace<KinematicComponent>(ball, Vec2(75, -150), Vec2(0, 75));

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        // Logic
        auto& transform = engine.world.get<TransformComponent>(ball);

        if (transform.position.y > heigth/2) {
            transform.position.y = heigth / 2;
        }
        if (transform.position.x >= width) {
            transform.position.x = width;
        }

        // Rendering
        Graphics::DrawFillRect(width/2, heigth/4, width, heigth/2, Color(119, 207, 242));              // Sky
        Graphics::DrawFillRect(width/2, 3*heigth/4, width, heigth/2, Color(119, 166, 58));      // Ground
        Graphics::DrawFillCircle(transform.position.x, transform.position.y, 15, Color::Red());

        engine.Render();
    }

    return 0;
}