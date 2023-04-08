#include "MorgulEngine.hh"
#include <cstdlib>

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    int radius = 35;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Player
    const auto player = engine.world.create();
    engine.world.emplace<TransformComponent>(player, Vec2(width/2, heigth/2));
    engine.world.emplace<GridMovementComponent>(player, 100);

    int n = rand() % 4 + 5;

    while (engine.NextFrame()) {
        engine.Update();
        
        // Logic
        Graphics::DrawGrid(100, true, true);

        if (engine.keyboard->upKeyPressed) {
            const auto transform = engine.world.get<TransformComponent>(player);

            RegularPolygonShape fig = RegularPolygonShape(radius, n, Color::Orange(), false);
            RegularPolygonShape &fig_ref = fig;

            const auto newObject = engine.world.create();
            engine.world.emplace<TransformComponent>(newObject, Vec2(transform.position.x, transform.position.y));
            engine.world.emplace<KinematicComponent>(newObject);
            engine.world.emplace<RigidBodyComponent>(newObject, 1.0f, fig_ref);
        }
        if (engine.keyboard->downKeyPressed) {
            const auto transform = engine.world.get<TransformComponent>(player);

            CircleShape fig = CircleShape(radius, Color::Magenta(), false);
            CircleShape &fig_ref = fig;

            const auto newObject = engine.world.create();
            engine.world.emplace<TransformComponent>(newObject, Vec2(transform.position.x, transform.position.y));
            engine.world.emplace<KinematicComponent>(newObject);
            engine.world.emplace<RigidBodyComponent>(newObject, 1.0f, fig_ref);
        }
        if (engine.keyboard->rightKeyPressed) {
            const auto transform = engine.world.get<TransformComponent>(player);

            StarShape fig = StarShape(radius, n, Color::Cyan(), false);
            StarShape &fig_ref = fig;

            const auto newObject = engine.world.create();
            engine.world.emplace<TransformComponent>(newObject, Vec2(transform.position.x, transform.position.y));
            engine.world.emplace<KinematicComponent>(newObject);
            engine.world.emplace<RigidBodyComponent>(newObject, 1.0f, fig_ref);
        }
        if (engine.keyboard->leftKeyPressed) {
            const auto transform = engine.world.get<TransformComponent>(player);

            StarShape fig = StarShape(radius, n, Color::Green(), true);
            StarShape &fig_ref = fig;

            const auto newObject = engine.world.create();
            engine.world.emplace<TransformComponent>(newObject, Vec2(transform.position.x, transform.position.y));
            engine.world.emplace<KinematicComponent>(newObject);
            engine.world.emplace<RigidBodyComponent>(newObject, 1.0f, fig_ref);
        }

        engine.Render();
    }
    
    return 0;
}