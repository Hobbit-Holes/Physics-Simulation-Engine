#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects
    const auto ball = engine.world.create();
    engine.world.emplace<TransformComponent>(ball, Vec2(width/2, heigth/2));
    engine.world.emplace<GridMovementComponent>(ball, 100);
    
    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        Graphics::DrawGrid(100, true, true);

        const auto transform = engine.world.get<TransformComponent>(ball);
        Graphics::DrawFillCircle(transform.position.x, transform.position.y, 25, Color::White());

        engine.Render();
    }
    
    return 0;
}