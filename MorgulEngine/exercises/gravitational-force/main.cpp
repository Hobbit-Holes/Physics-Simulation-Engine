#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    int numPlanets = 4;
    if (argc == 2) {
        numPlanets = strtol(argv[1], nullptr, 0);
    }

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects
    const auto sun = engine.world.create();
    engine.world.emplace<TransformComponent>(sun, Vec2(width/2, heigth/2));
    engine.world.emplace<KinematicComponent>(sun);
    engine.world.emplace<ParticleComponent>(sun, 100, 30, Color::Orange());

    std::vector<entt::entity> planets;
    for (int i = 0; i < numPlanets; i++) {
        Vec2 position = position.FromModuleAngle(150, (2* M_PI / numPlanets) * (i));
        Vec2 velocity = position.UnitVector().Normal() * 200;
        Color color = Color::Lerp(Color:: Green(), Color:: Cyan(), (float)i/(float)numPlanets);

        const auto planet = engine.world.create();
        engine.world.emplace<TransformComponent>(planet, position + Vec2(width/2, heigth/2));
        engine.world.emplace<KinematicComponent>(planet, velocity);
        engine.world.emplace<ParticleComponent>(planet, 10, 10, color);

        planets.push_back(planet);
    }
    planets.push_back(sun);

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        for (auto& planet: planets) {
            auto i = &planet - &planets[0];
            auto& tPlanet = engine.world.get<TransformComponent>(planet);
            auto& pPlanet = engine.world.get<ParticleComponent>(planet);

            for (auto& planetAffected: planets) {
                auto j = &planetAffected - &planets[0];
                auto& tPlanetAffected = engine.world.get<TransformComponent>(planetAffected);
                auto& pPlanetAffected = engine.world.get<ParticleComponent>(planetAffected);

                if (i != j) {
                    Vec2 gravitationalForce = Force::GenerateGravitationalVector(tPlanet.position, tPlanetAffected.position, pPlanet.mass, pPlanetAffected.mass, 50, 10, 2000);
                    pPlanet.AddForce(gravitationalForce);
                }
            }
        }

        engine.Render();
    }
    
    return 0;
}