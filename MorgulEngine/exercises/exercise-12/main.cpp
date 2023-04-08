#include "MorgulEngine.hh"
#include <cstdlib>

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;
    int radio = 50;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    //Inizialization of verties
    int a = rand() % 4;
    std::vector<Vec2> worldVertices;
    if(a == 0) {
        for (int i = 1; i <= 3; i++) {
            Vec2 position = position.FromModuleAngle(radio, (2* M_PI / 3) * (i));
            worldVertices.push_back(position);
        }
    } 
    if (a == 1) {
        for (int i = 1; i <= 4; i++) {
            Vec2 position = position.FromModuleAngle(radio, (2* M_PI / 4) * (i));
            worldVertices.push_back(position);
        }
    }
    if (a == 2) {
        for (int i = 1; i <= 5; i++) {
            Vec2 position = position.FromModuleAngle(radio, (2* M_PI / 5) * (i));
            worldVertices.push_back(position);
        }
    }
    if (a == 3) {
        for (int i = 1; i <= 6; i++) {
            Vec2 position = position.FromModuleAngle(radio, (2* M_PI / 6) * (i));
            worldVertices.push_back(position);
        }
    }

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

    int n = rand() % 6 + 5;

    while (engine.NextFrame()) {
        engine.Update();
        
        // Logic
        Graphics::DrawGrid(100, true, true);

        if (engine.keyboard->upKeyPressed) {
            const auto transform = engine.world.get<TransformComponent>(star2);
            Graphics::DrawStarPlatinum(transform.position.x, transform.position.y, radio, worldVertices, Color::White());
        }
        if (engine.keyboard->downKeyPressed) {
            const auto transform = engine.world.get<TransformComponent>(star1);
            Graphics::DrawStar(transform.position.x, transform.position.y, radio, n, Color::White());
        }
        if (engine.keyboard->rightKeyPressed) {
            const auto transform = engine.world.get<TransformComponent>(ball);
            Graphics::DrawFillCircle(transform.position.x, transform.position.y, radio/2, Color::White());
        }
        if (engine.keyboard->leftKeyPressed) {
            const auto transform = engine.world.get<TransformComponent>(poligon);
            Graphics::DrawPolygon(transform.position.x, transform.position.y, worldVertices, Color::White());
        }

        engine.Render();
    }
    
    return 0;
}