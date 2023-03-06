#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    int radius = 10;
    int numParticles = 12;

    if (argc == 2) {
        numParticles = strtol(argv[1], nullptr, 0);
    }

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects
    std::vector<entt::entity> balls;
    for (int i = 0; i <= numParticles; i++) {
        const auto ball = engine.world.create();
        engine.world.emplace<TransformComponent>(ball, Vec2(width/2, heigth/2));
        engine.world.emplace<KinematicComponent>(ball, Vec2(0, -125).Rotate(i*M_PI/(numParticles/2)), Vec2(0, 75));

        balls.push_back(ball);
    }

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        // Logic
        for (auto& ball: balls) {
            auto i = &ball - &balls[0];
            auto& transform = engine.world.get<TransformComponent>(ball);
            Color color = Color::Lerp(Color:: Magenta(), Color:: Cyan(), (float)i/(float)numParticles);

            if (transform.position.x >= width - radius) {
                transform.position.x = width - radius;
                color = Color::Orange();
            }
            if (transform.position.y >= heigth - radius) {
                transform.position.y = heigth - radius;
                color = Color::Orange();
            }
            if (transform.position.x <= radius) {
                transform.position.x = radius;
                color = Color::Orange();
            }

            if ((transform.position.x >= width - radius || transform.position.x <= radius) && (transform.position.y >= heigth - radius)) {
                color = Color::Red();
            }

            Graphics::DrawFillCircle(transform.position.x, transform.position.y, radius, color);
        }

        engine.Render();
    }

    return 0;
}