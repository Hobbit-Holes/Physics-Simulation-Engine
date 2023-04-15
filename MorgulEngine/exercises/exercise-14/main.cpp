#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    std::vector<entt::entity> bodies;

    // Walls
    RectangleShape figRect1 = RectangleShape(700, 100, Color::Blue(), false);
    RectangleShape &fig_refRect1 = figRect1;

    const auto bottomWall = engine.world.create();
    engine.world.emplace<TransformComponent>(bottomWall, Vec2(400, 800));
    engine.world.emplace<KinematicComponent>(bottomWall);
    engine.world.emplace<ColliderComponent>(bottomWall, fig_refRect1, false);
    engine.world.emplace<RigidBodyComponent>(bottomWall, 0.0f, fig_refRect1, true);

    RectangleShape figRect2 = RectangleShape(100, 700, Color::Blue(), false);
    RectangleShape &fig_refRect2 = figRect2;

    const auto leftWall = engine.world.create();
    engine.world.emplace<TransformComponent>(leftWall, Vec2(0, 400));
    engine.world.emplace<KinematicComponent>(leftWall);
    engine.world.emplace<ColliderComponent>(leftWall, fig_refRect2, false);
    engine.world.emplace<RigidBodyComponent>(leftWall, 0.0f, fig_refRect2, true);

    RectangleShape figRect3 = RectangleShape(100, 700, Color::Blue(), false);
    RectangleShape &fig_refRect3 = figRect3;

    const auto rightWall = engine.world.create();
    engine.world.emplace<TransformComponent>(rightWall, Vec2(800, 400));
    engine.world.emplace<KinematicComponent>(rightWall);
    engine.world.emplace<ColliderComponent>(rightWall, fig_refRect3, false);
    engine.world.emplace<RigidBodyComponent>(rightWall, 0.0f, fig_refRect3, true);

    // Objects
    RectangleShape figRect4 = RectangleShape(100, 100, Color::White(), false);
    RectangleShape &fig_refRect4 = figRect4;

    const auto obstacle1 = engine.world.create();
    engine.world.emplace<TransformComponent>(obstacle1, Vec2(400, 400));
    engine.world.emplace<KinematicComponent>(obstacle1);
    engine.world.emplace<ColliderComponent>(obstacle1, fig_refRect4, false);
    engine.world.emplace<RigidBodyComponent>(obstacle1, 0.0f, fig_refRect4, true);

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        for (auto entity: bodies) {
            engine.world.get<RigidBodyComponent>(entity).AddForce(Vec2(0, 200));
        }

        // Generate objects
        if (engine.mouse->leftButtonPressed) {
            engine.mouse->leftButtonPressed = false;

            entt::entity newPolygon = engine.world.create();

            RegularPolygonShape figPoly = RegularPolygonShape(20, 6, Color::Orange(), false);
            RegularPolygonShape &fig_refPoly = figPoly;

            engine.world.emplace<TransformComponent>(newPolygon, engine.GetMousePosition());
            engine.world.emplace<KinematicComponent>(newPolygon);
            engine.world.emplace<ColliderComponent>(newPolygon, fig_refPoly);
            engine.world.emplace<RigidBodyComponent>(newPolygon, 1.0f, fig_refPoly);

            bodies.push_back(newPolygon);
        }

        if (engine.mouse->rightButtonPressed) {
            engine.mouse->rightButtonPressed = false;

            entt::entity newBall = engine.world.create();

            CircleShape figCircle = CircleShape(20, Color::Orange(), false);
            CircleShape &fig_refCircle = figCircle;

            engine.world.emplace<TransformComponent>(newBall, engine.GetMousePosition());
            engine.world.emplace<KinematicComponent>(newBall);
            engine.world.emplace<ColliderComponent>(newBall, fig_refCircle);
            engine.world.emplace<RigidBodyComponent>(newBall, 1.0f, fig_refCircle);

            bodies.push_back(newBall);
        }

        engine.Render();
    }

    return 0;
}