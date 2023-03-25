#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 800;

    int radius = 3.5;
    int numParticles = 10;

    if (argc == 2) {
        numParticles = strtol(argv[1], nullptr, 0);
    }

    // Spring
    Vec2 anchor = Vec2(width/2, 50);
    float coefficient = 5;
    float restLength = 30;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects
    std::vector<entt::entity> balls;
    Vec2 initialPosition = Vec2(width/2, 100);
    for (int i = 0; i <= numParticles; i++) {
        const auto ball = engine.world.create();
        engine.world.emplace<TransformComponent>(ball, initialPosition);
        engine.world.emplace<KinematicComponent>(ball);
        engine.world.emplace<ParticleComponent>(ball, 1, radius);

        balls.push_back(ball);
        initialPosition += Vec2(0, radius*3);
    }

    // Gravity object
    const auto planet1 = engine.world.create();
    engine.world.emplace<TransformComponent>(planet1, Vec2(500, 100));
    engine.world.emplace<KinematicComponent>(planet1);
    engine.world.emplace<ParticleComponent>(planet1, 20, 15, Color::Red());

    const auto planet2 = engine.world.create();
    engine.world.emplace<TransformComponent>(planet2, Vec2(100, 700));
    engine.world.emplace<KinematicComponent>(planet2);
    engine.world.emplace<ParticleComponent>(planet2, 20, 15, Color::Red());

    auto& tPlanet1 = engine.world.get<TransformComponent>(planet1);
    auto& pPlanet1 = engine.world.get<ParticleComponent>(planet1);

    auto& tPlanet2 = engine.world.get<TransformComponent>(planet2);
    auto& pPlanet2 = engine.world.get<ParticleComponent>(planet2);

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        for (auto& ball: balls) {
            auto i = &ball - &balls[0];
            
            const auto t1 = engine.world.get<TransformComponent>(ball);
            const auto k1 = engine.world.get<KinematicComponent>(ball);
            auto& p1 = engine.world.get<ParticleComponent>(ball);

            Vec2 dragForce = Force::GenerateDragVector(0.01, k1.velocity);
            p1.AddForce(dragForce);
            Vec2 weightForce = Vec2(0, 20);
            p1.AddForce(weightForce);

            Vec2 gravitationalForce1 = Force::GenerateGravitationalVector(tPlanet1.position, t1.position, pPlanet1.mass, p1.mass, 10, 20, 350);
            p1.AddForce(-gravitationalForce1);
            Vec2 gravitationalForce2 = Force::GenerateGravitationalVector(tPlanet2.position, t1.position, pPlanet2.mass, p1.mass, 10, 20, 350);
            p1.AddForce(-gravitationalForce2);
            
            if (i == 0) {
                Vec2 springForce = Force::GenerateSpringVector(coefficient, t1.position, anchor, restLength);
                p1.AddForce(springForce);

                Graphics::DrawLine(t1.position, anchor, Color::White());
            }
            else {
                auto previousBall = balls[i-1];

                const auto t2 = engine.world.get<TransformComponent>(previousBall);
                auto& p2 = engine.world.get<ParticleComponent>(previousBall);

                Vec2 springForce = Force::GenerateSpringVector(coefficient, t1.position, t2.position, restLength);
                p1.AddForce(springForce);
                p2.AddForce(-springForce);

                Graphics::DrawLine(t1.position, t2.position, Color::White());
            }
        }

        float seconds = SDL_GetTicks()/1000.0f;
        float timer_speed = 3.0f;
        float timer = 1 - fabs(fmod(seconds/timer_speed, 2) - 1);

        Vec2 newPosition1 = Vec2::Lerp(Vec2(500, 100), Vec2(500, 700), timer);
        tPlanet1.position = newPosition1;
        Vec2 newPosition2 = Vec2::Lerp(Vec2(100, 100), Vec2(100, 700), 1 - timer);
        tPlanet2.position = newPosition2;

        Graphics::DrawFillRect(anchor.x, anchor.y, 40, 10, Color::Orange());

        engine.Render();
    }

    return 0;
}