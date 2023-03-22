#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    const auto circle = engine.world.create();
    engine.world.emplace<TransformComponent>(circle, Vec2(200, 200));
    engine.world.emplace<KinematicComponent>(circle);
    engine.world.emplace<RigidBodyComponent>(circle, 1, CircleShape(100, Color::Red(), false));

    const auto circleFilled = engine.world.create();
    engine.world.emplace<TransformComponent>(circleFilled, Vec2(600, 200));
    engine.world.emplace<KinematicComponent>(circleFilled);
    engine.world.emplace<RigidBodyComponent>(circleFilled, 1, CircleShape(100, Color::Green(), true));

    const auto rectangle = engine.world.create();
    engine.world.emplace<TransformComponent>(rectangle, Vec2(200, 600));
    engine.world.emplace<KinematicComponent>(rectangle);
    engine.world.emplace<RigidBodyComponent>(rectangle, 1, RectangleShape(200, 100, Color::Yellow(), false));

    const auto rectangleFilled = engine.world.create();
    engine.world.emplace<TransformComponent>(rectangleFilled, Vec2(600, 600));
    engine.world.emplace<KinematicComponent>(rectangleFilled);
    engine.world.emplace<RigidBodyComponent>(rectangleFilled, 1, RectangleShape(200, 100, Color::Orange(), true));

    while (engine.NextFrame()) {
        engine.Update();

        auto& circleRb = engine.world.get<RigidBodyComponent>(circle);
        circleRb.AddTroque(500);

        auto& rectangleRb = engine.world.get<RigidBodyComponent>(rectangle);
        rectangleRb.AddTroque(500);

        std::cout << "Rectangle Angular velocity: " << engine.world.get<KinematicComponent>(rectangle).angularVelocity << 
        "\tCircle Angular velocity: " << engine.world.get<KinematicComponent>(circle).angularVelocity << std::endl;

        engine.Render();
    }

    return 0;
}