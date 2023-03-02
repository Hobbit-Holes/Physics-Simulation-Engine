#include "MorgulEngine.hh"
#include <math.h>

int main(int argc, char *argv[]){
    
    std::vector<entt::entity> filledParticles;
    std::vector<entt::entity> particles;
    std::vector<entt::entity> filledRectangles;
    std::vector<entt::entity> rectangles;

    int particleRadius = 15;
    float angle = 10;
    int w = 30;
    int h = 20;

    int width = 1000;
    int heigth = 800;

    float PI = M_PI;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    for(int i = 0; i < 5; i++){
        const auto filledBall = engine.world.create();
        Vec2 position = position.FromModuleAngle(300, (2* PI /2) * (i));
        engine.world.emplace<TransformComponent>(filledBall,  position + Vec2(450,450));
        filledParticles.push_back(filledBall);
    }

    for(int i = 0; i < 5; i++){
        const auto ball = engine.world.create();
        Vec2 position = position.FromModuleAngle(300, (2* PI /3) * (i));
        engine.world.emplace<TransformComponent>(ball,  position + Vec2(400,400));
        particles.push_back(ball);
    }

    for(int i = 0; i < 5; i++){
        const auto filledRect = engine.world.create();
        Vec2 position = position.FromModuleAngle(300, (2* PI /2) * (i));
        engine.world.emplace<TransformComponent>(filledRect,  position + Vec2(500,500));
        filledRectangles.push_back(filledRect);
    }

    for(int i = 0; i < 5; i++){
        const auto rect = engine.world.create();
        Vec2 position = position.FromModuleAngle(300, (2* PI /3) * (i));
        engine.world.emplace<TransformComponent>(rect,  position + Vec2(480,480));
        rectangles.push_back(rect);
    }

    while(engine.NextFrame()){
        engine.Update();

        for(auto& filledBall: filledParticles){
            auto i = &filledBall - &filledParticles[0];
            auto& transform = engine.world.get<TransformComponent>(filledBall);
            
            Color color = Color::Lerp(Color:: Magenta(), Color:: Cyan(), (float)i/(float)3);
            Graphics::DrawFillCircle(transform.position.x, transform.position.y, particleRadius, color);
        }

        for(auto& ball: particles){
            auto i = &ball - &particles[0];
            auto& transform = engine.world.get<TransformComponent>(ball);
            
            Color color = Color::Lerp(Color:: Orange(), Color:: Cyan(), (float)i/(float)2);
            Graphics::DrawCircle(transform.position.x, transform.position.y, particleRadius, angle, color);
        }

        for(auto& filledRect: filledRectangles){
            auto i = &filledRect - &filledRectangles[0];
            auto& transform = engine.world.get<TransformComponent>(filledRect);
            
            Color color = Color::Lerp(Color:: Red(), Color:: Cyan(), (float)i/(float)2);
            Graphics::DrawFillRect(transform.position.x, transform.position.y,  w, h, color);
        }

        for(auto& rect: rectangles){
            auto i = &rect - &rectangles[0];
            auto& transform = engine.world.get<TransformComponent>(rect);
            
            Color color = Color::Lerp(Color:: Yellow(), Color:: Green(), (float)i/(float)3);
            Graphics::DrawRect(transform.position.x, transform.position.y, w, h, color);
        }

        engine.Render();
    }

    return 0;
}