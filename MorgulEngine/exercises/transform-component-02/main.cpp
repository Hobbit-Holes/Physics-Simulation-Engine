#include "MorgulEngine.hh"
#include <math.h>

int main(int argc, char *argv[]){
    
    std::vector<entt::entity> particles;

    int totalParticles = 4;
    int particleRadius = 20;

    if (argc == 3){
        totalParticles = strtol(argv[1], nullptr, 0);
        particleRadius = strtol(argv[2], nullptr, 0);
    }

    int width = 600;
    int heigth = 400;

    float PI = M_PI;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    for(int i = 0; i < totalParticles; i++){
        const auto ball = engine.world.create();
        Vec2 position = Vec2::FromModuleAngle(300, (2* PI /totalParticles) * (i));
        engine.world.emplace<TransformComponent>(ball, position + Vec2(400,400));
        particles.push_back(ball);
    }

    while(engine.NextFrame()){
        engine.Update();

        for(auto& ball: particles){
            auto i = &ball - &particles[0];
            auto& transform = engine.world.get<TransformComponent>(ball);
            Color color = Color::Lerp(
                Color:: Red(),
                Color:: Green(),
                (float)i/(float)totalParticles);

            Graphics::DrawFillCircle(
                transform.position.x,
                transform.position.y,
                particleRadius,
                color);
        }

        engine.Render();
    }

    return 0;
}