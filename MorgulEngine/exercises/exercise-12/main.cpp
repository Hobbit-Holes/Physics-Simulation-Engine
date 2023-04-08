#include "MorgulEngine.hh"
#include <cstdlib>

void OnKeyDown(const KeyDownEvent& keyDown) noexcept {
    std::cout << "KeyDown event" << keyDown.symbol << std::endl;

    if (keyDown.symbol == SDLK_UP) {
        std::cout << "Pressed UP arrow" << std::endl;
    }
    if (keyDown.symbol == SDLK_DOWN) {
        std::cout << "Pressed DOWN arrow" << std::endl;
    }
    if (keyDown.symbol == SDLK_RIGHT) {
        std::cout << "Pressed RIGHT arrow" << std::endl;
    }
    if (keyDown.symbol == SDLK_LEFT) {
        std::cout << "Pressed LEFT arrow" << std::endl;
    }
}

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

    // Event
    engine.eventBus.sink<KeyDownEvent>().connect<&OnKeyDown>();

    while (engine.NextFrame()) {
        engine.Update();
        
        // Logic
        Graphics::DrawGrid(100, true, true);

        if (engine.keyboard->upKeyPressed) {
            int n = rand() % 6 + 6;
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

            CircleShape fig = CircleShape(radius, Color::Magenta(), true);
            CircleShape &fig_ref = fig;

            const auto newObject = engine.world.create();
            engine.world.emplace<TransformComponent>(newObject, Vec2(transform.position.x, transform.position.y));
            engine.world.emplace<KinematicComponent>(newObject);
            engine.world.emplace<RigidBodyComponent>(newObject, 1.0f, fig_ref);
        }
        if (engine.keyboard->rightKeyPressed) {
            int n = rand() % 6 + 6;
            const auto transform = engine.world.get<TransformComponent>(player);

            StarShape fig = StarShape(radius, n, Color::Cyan(), false);
            StarShape &fig_ref = fig;

            const auto newObject = engine.world.create();
            engine.world.emplace<TransformComponent>(newObject, Vec2(transform.position.x, transform.position.y));
            engine.world.emplace<KinematicComponent>(newObject);
            engine.world.emplace<RigidBodyComponent>(newObject, 1.0f, fig_ref);
        }
        if (engine.keyboard->leftKeyPressed) {
            int n = rand() % 6 + 6;
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