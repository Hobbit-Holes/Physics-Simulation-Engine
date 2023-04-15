#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;
    int radius = 10;
    int numBalls = 17;

    MorgulEngine engine = MorgulEngine(width, heigth);

    //Shapes
    CircleShape figCir = CircleShape(radius, Color::White(), true);
    CircleShape &fig_refCir = figCir;

    auto player = engine.world.create();
    engine.world.emplace<TransformComponent>(player, Vec2(500, 400));
    engine.world.emplace<KinematicComponent>(player);
    engine.world.emplace<ColliderComponent>(player, figCir, false);
    engine.world.emplace<RigidBodyComponent>(player, 1.0f, fig_refCir);

    std::vector<entt::entity> balls;
    for (int i = 0; i < numBalls; i++) {
        auto ball = engine.world.create();
        engine.world.emplace<TransformComponent>(ball, Vec2(300, 400));
        engine.world.emplace<KinematicComponent>(ball);
        engine.world.emplace<ColliderComponent>(ball, figCir, false);
        engine.world.emplace<RigidBodyComponent>(ball, 1.0f, fig_refCir);
    }

    int i = 0;

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        Graphics::DrawGrid(50, true, true);
        const float angleIncrement = 2 * M_PI / numBalls;
        const float radiusIncrement = 100 / (numBalls / 3);
        const float xOffset = std::sqrt(3) * 100 / 2;

        for(auto ball: balls) {
            auto& transform = engine.world.get<TransformComponent>(ball);
            float angle = i * angleIncrement;
            float x = 300 + std::cos(angle) * 100;
            float y = 400 + std::sin(angle) * 100;
            if (i % 6 < 3) {
                x -= xOffset;
                y += radiusIncrement * (i % 6);
            } else {
                y += radiusIncrement * (i % 6 - 3);
            }

            transform.position = Vec2(x, y);
            i++;
        }
        

        engine.Render();
    }

    return 0;
}