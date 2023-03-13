#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 600;

    Vec2 anchor = Vec2(width/2, 50);
    float coefficient = 20;
    float restLength = 150;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects
    const auto ball = engine.world.create();
    engine.world.emplace<TransformComponent>(ball, Vec2(width/2, 250));
    engine.world.emplace<KinematicComponent>(ball);
    engine.world.emplace<ParticleComponent>(ball, 1, 10);

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        const auto t = engine.world.get<TransformComponent>(ball);
        const auto k = engine.world.get<KinematicComponent>(ball);
        auto& p = engine.world.get<ParticleComponent>(ball);

        Vec2 dragForce = Force::GenerateDragVector(0.01, k.velocity);
        p.AddForce(dragForce);
        Vec2 weightForce = Vec2(0, 20);
        p.AddForce(weightForce);
        Vec2 springForce = Force::GenerateSpringVector(coefficient, t.position, anchor, restLength);

        Graphics::DrawLine(t.position, anchor, Color::White());
        Graphics::DrawFillRect(anchor.x, anchor.y, 40, 10, Color::Orange());
        
        engine.Render();
    }
    
    return 0;
}