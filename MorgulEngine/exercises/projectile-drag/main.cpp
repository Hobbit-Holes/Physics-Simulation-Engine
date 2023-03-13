#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    Vec2 gravityForce = Vec2(0, 50);
    float drag = 0.01;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects
    const auto projectile = engine.world.create();
    engine.world.emplace<TransformComponent>(projectile, Vec2(10, width/2));
    engine.world.emplace<KinematicComponent>(projectile, Vec2(150, -150), Vec2(0, 9.81));
    engine.world.emplace<ParticleComponent>(projectile, 1, 10, Color::Red());

    auto& k = engine.world.get<KinematicComponent>(projectile);
    auto& p = engine.world.get<ParticleComponent>(projectile);

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        p.AddForce(gravityForce);
        p.AddForce(Force::GenerateDragVector(drag, k.velocity));

        Graphics::DrawFillRect(width/2, heigth*0.25, width, heigth/2, Color(51, 198, 219));
        Graphics::DrawFillRect(width/2, heigth*0.75, width, heigth/2, Color(3, 166, 60));

        engine.Render();
    }
    
    return 0;
}