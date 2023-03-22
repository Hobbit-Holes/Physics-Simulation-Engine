#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 800;

    int radius = 5;
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
        initialPosition += Vec2(0, 15);
    }

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

        Graphics::DrawFillRect(anchor.x, anchor.y, 40, 10, Color::Orange());

        engine.Render();
    }

    return 0;
}