#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects
    Vec2 smallWindForce = Vec2(2, 0);
    Vec2 bigWindForce = Vec2(4, 0);

    const auto smallBall = engine.world.create();
    engine.world.emplace<TransformComponent>(smallBall, Vec2(100, heigth*0.33));
    engine.world.emplace<KinematicComponent>(smallBall, Vec2(30, 0));
    engine.world.emplace<ParticleComponent>(smallBall, 1, 10);

    const auto bigBall = engine.world.create();
    engine.world.emplace<TransformComponent>(bigBall, Vec2(100, heigth*0.66));
    engine.world.emplace<KinematicComponent>(bigBall, Vec2(30, 0));
    engine.world.emplace<ParticleComponent>(bigBall, 5, 20, Color::Magenta());

    auto& smallParticleComponent = engine.world.get<ParticleComponent>(smallBall);
    auto& bigParticleComponent = engine.world.get<ParticleComponent>(bigBall);

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        // Wind forces
        smallParticleComponent.AddForce(Vec2(8, 2));
        bigParticleComponent.AddForce(Vec2(6, -4));

        engine.Render();
    }

    return 0;
}