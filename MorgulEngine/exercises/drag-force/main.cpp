#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    Vec2 gravityForce = Vec2(0, 50);
    Vec2 dragForce = Vec2();

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects
    const auto particle = engine.world.create();
    engine.world.emplace<TransformComponent>(particle, Vec2(width/2, 50));
    engine.world.emplace<KinematicComponent>(particle, Vec2(10, 0));
    engine.world.emplace<ParticleComponent>(particle, 1, 20, Color::Red());

    auto& t = engine.world.get<TransformComponent>(particle);
    auto& k = engine.world.get<KinematicComponent>(particle);
    auto& p = engine.world.get<ParticleComponent>(particle);

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        p.AddForce(gravityForce);

        if (t.position.y >= heigth / 2) {
            dragForce = Force::GenerateDragVector(0.1, k.velocity);
        } else {
            dragForce = Vec2();
        }
        p.AddForce(dragForce);

        Logger::Info("Velocity: (" + std::to_string(k.velocity.x) + ", " + std::to_string(k.velocity.y) + ")");
        Logger::Info("Drag Force: (" + std::to_string(dragForce.x) + ", " + std::to_string(dragForce.y) + ")");

        Graphics::DrawFillRect(width/2, heigth*0.75, width, heigth/2, Color(35, 165, 217));

        engine.Render();
    }
    
    return 0;
}