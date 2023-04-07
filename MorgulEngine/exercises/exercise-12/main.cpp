#include "MorgulEngine.hh"
#include <cstdlib>

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    std::vector<Vec2> worldVertices;

    worldVertices.push_back(Vec2(-100 / 2.0, -100 / 2.0));
    worldVertices.push_back(Vec2(+100 / 2.0, -100 / 2.0));
    worldVertices.push_back(Vec2(+100 / 2.0, +100 / 2.0));
    worldVertices.push_back(Vec2(-100 / 2.0, +100 / 2.0));

    // Objects
    const auto ball = engine.world.create();
    engine.world.emplace<TransformComponent>(ball, Vec2(width/2, heigth/2));
    engine.world.emplace<GridMovementComponent>(ball, 100);

    const auto poligon = engine.world.create();
    engine.world.emplace<TransformComponent>(poligon, Vec2(width/2, heigth/2));
    engine.world.emplace<GridMovementComponent>(poligon, 100);

    const auto star1 = engine.world.create();
    engine.world.emplace<TransformComponent>(star1, Vec2(width/2, heigth/2));
    engine.world.emplace<GridMovementComponent>(star1, 100);

    const auto star2 = engine.world.create();
    engine.world.emplace<TransformComponent>(star2, Vec2(width/2, heigth/2));
    engine.world.emplace<GridMovementComponent>(star2, 100);

    while (engine.NextFrame()) {
        engine.Update();
        
        // Logic
        Graphics::DrawGrid(100, true, true);
        const auto transform = engine.world.get<TransformComponent>(ball);

        if (engine.keyboard->upKeyPressed) {
            Graphics::DrawStarPlatinum(transform.position.x, transform.position.y, 25, worldVertices, Color::White());
        }
        if (engine.keyboard->downKeyPressed) {
            Graphics::DrawStar(transform.position.x, transform.position.y, 50, 5, Color::White());
        }
        if (engine.keyboard->rightKeyPressed) {
            Graphics::DrawFillCircle(transform.position.x, transform.position.y, 25, Color::White());
        }
        if (engine.keyboard->leftKeyPressed) {
            Graphics::DrawPolygon(transform.position.x, transform.position.y, worldVertices, Color::White());
        }

        engine.Render();
    }
    
    return 0;
}