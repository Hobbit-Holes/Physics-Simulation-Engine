#include "MorgulEngine.hh"

struct object {
    Vec2 position;
    int width;
    int heigth;
    Color color;
} player, enemy;

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Entities initialization
    player.width = 10;
    player.heigth = 10;
    player.position = Vec2(10, 10);
    player.color = Color::Orange();

    enemy.width = 10;
    enemy.heigth = 10;
    enemy.position = Vec2(width, heigth);
    enemy.color = Color::Red();

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        double dt = engine.GetDeltaTime();

        enemy.position += (player.position - enemy.position) * dt;
        player.position = engine.GetMousePosition();

        Graphics::DrawFillRect(player.position.x, player.position.y, player.width, player.heigth, player.color);
        Graphics::DrawFillRect(enemy.position.x, enemy.position.y, enemy.width, enemy.heigth, enemy.color);

        Logger::Info("Player position: " + std::to_string(player.position.x) + ", " + std::to_string(player.position.y));

        engine.Render();
    }

    // Destroy the Engine
    Graphics::CloseWindow();

    return 0;
}