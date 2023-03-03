#include "MorgulEngine.hh"
#include <math.h>

int main(int argc, char *argv[]) {
    
    std::vector<entt::entity> filledParticles;
    std::vector<entt::entity> particles;
    std::vector<entt::entity> filledRectangles;
    std::vector<entt::entity> rectangles;

    int numFilledBalls = 20;
    int numBalls = 20;
    int numFillRect = 10;
    int numRect = 10;

    int particleRadius = 15;
    float angle = 10;
    int w = 30;
    int h = 20;

    int width = 1000;
    int heigth = 800;

    float PI = M_PI;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    for (int i = 0; i < numFilledBalls; i++) {
        const auto filledBall = engine.world.create();
        Vec2 position = position.FromModuleAngle(300, (2* PI / numFilledBalls) * (i));
        engine.world.emplace<TransformComponent>(filledBall,  position + Vec2(width/2, heigth/2));
        filledParticles.push_back(filledBall);
    }

    for (int i = 0; i < numBalls; i++) {
        const auto ball = engine.world.create();
        Vec2 position = position.FromModuleAngle(300, (2* PI / numBalls) * (i));
        engine.world.emplace<TransformComponent>(ball,  position + Vec2(width/2 + 5, heigth/2 + 5));
        particles.push_back(ball);
    }

    for (int i = 0; i < numFillRect; i++) {
        const auto filledRect = engine.world.create();
        Vec2 position = position.FromModuleAngle(200, (2* PI / numFillRect) * (i));
        engine.world.emplace<TransformComponent>(filledRect,  position + Vec2(width/2, heigth/2));
        filledRectangles.push_back(filledRect);
    }

    for (int i = 0; i < numRect; i++) {
        const auto rect = engine.world.create();
        Vec2 position = position.FromModuleAngle(100, (2* PI / numRect) * (i));
        engine.world.emplace<TransformComponent>(rect,  position + Vec2(width/2, heigth/2));
        rectangles.push_back(rect);
    }

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        for (auto& filledBall: filledParticles) {
            auto i = &filledBall - &filledParticles[0];
            auto& transform = engine.world.get<TransformComponent>(filledBall);

            Vec2 localPosition = Vec2(width/2, heigth/2) - transform.position;
            transform.position = Vec2(width/2, heigth/2) + localPosition.Rotate(M_PI / 450);
            
            Color color = Color::Lerp(Color:: Magenta(), Color:: Cyan(), (float)i/(float)numFilledBalls);
            Graphics::DrawFillCircle(transform.position.x, transform.position.y, particleRadius, color);
        }

        for (auto& ball: particles) {
            auto i = &ball - &particles[0];
            auto& transform = engine.world.get<TransformComponent>(ball);

            Vec2 localPosition = Vec2(width/2 + 5, heigth/2 + 5) - transform.position;
            transform.position = Vec2(width/2 + 5, heigth/2 + 5) + localPosition.Rotate(M_PI / 450);
            
            Color color = Color::Lerp(Color:: Orange(), Color:: Red(), (float)i/(float)numBalls);
            Graphics::DrawCircle(transform.position.x, transform.position.y, particleRadius, angle, color);
        }

        for (auto& filledRect: filledRectangles) {
            auto i = &filledRect - &filledRectangles[0];
            auto& transform = engine.world.get<TransformComponent>(filledRect);

            Vec2 localPosition = Vec2(width/2, heigth/2) - transform.position;
            transform.position = Vec2(width/2, heigth/2) + localPosition.Rotate(-M_PI / 450);
            
            Color color = Color::Lerp(Color:: Yellow(), Color:: Cyan(), (float)i/(float)numFillRect);
            Graphics::DrawFillRect(transform.position.x, transform.position.y, w, h, color);
        }

        for (auto& rect: rectangles) {
            auto i = &rect - &rectangles[0];
            auto& transform = engine.world.get<TransformComponent>(rect);
            
            Vec2 localPosition = Vec2(width/2, heigth/2) - transform.position;
            transform.position = Vec2(width/2, heigth/2) + localPosition.Rotate(M_PI / 450);
            
            Color color = Color::Lerp(Color:: Cyan(), Color:: Green(), (float)i/(float)numRect);
            Graphics::DrawRect(transform.position.x, transform.position.y, w, h, color);
        }

        engine.Render();
    }

    return 0;
}