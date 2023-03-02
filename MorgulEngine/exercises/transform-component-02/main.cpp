#include "MorgulEngine.hh"
#include <math.h>

int main(int argc, char *argv[]) {
    
    std::vector<entt::entity> particles;

    int totalParticles = 100;
    int particleRadius = 5;

    if (argc == 3) {
        totalParticles = strtol(argv[1], nullptr, 0);
        particleRadius = strtol(argv[2], nullptr, 0);
    }

    int width = 800;
    int heigth = 800;

    float PI = M_PI;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    for (int i = 0; i < totalParticles; i++) {
        const auto ball = engine.world.create();
        Vec2 position = position.FromModuleAngle(300, (2* PI /totalParticles) * (i));
        engine.world.emplace<TransformComponent>(ball,  position + Vec2(400, 400));
        particles.push_back(ball);
    }

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        for (auto& ball: particles) {
            auto i = &ball - &particles[0];
            auto& transform = engine.world.get<TransformComponent>(ball);
            
            Color color = Color::Lerp(Color:: Magenta(), Color:: Cyan(), (float)i/(float)totalParticles);
            Graphics::DrawFillCircle(transform.position.x, transform.position.y, particleRadius, color);
        }

        engine.Render();
    }

    return 0;
}