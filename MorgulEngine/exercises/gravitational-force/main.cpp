#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects
    const auto earth = engine.world.create();
    engine.world.emplace<TransformComponent>(earth, Vec2(100, 100));
    engine.world.emplace<KinematicComponent>(earth, Vec2(150, 0));
    engine.world.emplace<ParticleComponent>(earth, 1, 10, Color::Green());

    const auto sun = engine.world.create();
    engine.world.emplace<TransformComponent>(sun, Vec2(width/2, heigth/2));
    engine.world.emplace<KinematicComponent>(sun);
    engine.world.emplace<ParticleComponent>(sun, 20, 30, Color::Orange());

    auto& tEarth = engine.world.get<TransformComponent>(earth);
    auto& pEarth = engine.world.get<ParticleComponent>(earth);
    auto& tSun = engine.world.get<TransformComponent>(sun);
    auto& pSun = engine.world.get<ParticleComponent>(sun);

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        Vec2 gravitationalForce = Force::GenerateGravitationalVector(tEarth.position, tSun.position, pEarth.mass, pSun.mass, 1000, 5, 100);
        pEarth.AddForce(gravitationalForce);
        pSun.AddForce(-gravitationalForce);

        engine.Render();
    }
    
    return 0;
}