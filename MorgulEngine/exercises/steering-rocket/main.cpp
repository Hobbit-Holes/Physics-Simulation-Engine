#include "MorgulEngine.hh"

struct rocket_t {
    Vec2 position;
    float rotation;
    float maxTurn;
    float linear_speed;
} rocket;

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Entities initialization
    rocket.position = Vec2(25, 25);
    rocket.rotation = M_PI / 4;
    rocket.maxTurn = M_PI / 12;
    rocket.linear_speed = 100;

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        double dt = engine.GetDeltaTime();

        // Rocket
        rocket.rotation += ((rand() % 201 - 100) / 100) * rocket.maxTurn;
        Vec2 direction = Vec2(cos(rocket.rotation), sin(rocket.rotation));
        rocket.position += direction * rocket.linear_speed * dt;

        Graphics::DrawFillRect(rocket.position.x, rocket.position.y, 10, 10, Color::Red());
        Logger::Info("Rocket position: (" + std::to_string(rocket.position.x) + ", " + std::to_string(rocket.position.y) + ")");

        engine.Render();
    }

    // Destroy the Engine
    Graphics::CloseWindow();

    return 0;
}