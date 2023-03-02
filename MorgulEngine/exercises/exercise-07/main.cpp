#include "MorgulEngine.hh"

struct object {
    Vec2 position;
    int speed;
    int width;
    int heigth;
    Color color;
    Vec2 direction;
    bool detect;
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
    enemy.speed = 150;
    enemy.direction = Vec2(1, 0);
    enemy.position = Vec2(width/2, heigth/2);
    enemy.color = Color::Red();
    enemy.detect = false;

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        if (enemy.position.FromModuleAngle(player.position) < 0) {
            enemy.detect = true;
        }
        
        if (enemy.detect == true) {
            double dt = engine.GetDeltaTime();
            Vec2 direction = (player.position - enemy.position).UnitVector();
            enemy.position += direction * enemy.speed * dt;
            enemy.direction = direction;
        }
        Graphics::DrawLineSDL(enemy.position.x + enemy.width/2, enemy.position.y + enemy.heigth/2, enemy.position.x + enemy.direction.x * 100, enemy.position.y + enemy.direction.y * 100, Color::Red());
        
        player.position = engine.GetMousePosition();

        Graphics::DrawFillRect(player.position.x, player.position.y, player.width, player.heigth, player.color);
        Graphics::DrawFillRect(enemy.position.x, enemy.position.y, enemy.width, enemy.heigth, enemy.color);

        Logger::Info("Angle Player and Enemy: " + std::to_string(enemy.position.FromModuleAngle(player.position)));

        engine.Render();
    }

    // Destroy the Engine
    Graphics::CloseWindow();

    return 0;
}