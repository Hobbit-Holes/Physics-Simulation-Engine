#include "MorgulEngine.hh"

struct object {
    Vec2 position;
    int speed;
    int width;
    int heigth;
    Color color;
    Vec2 direction;
    float fov;
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
    enemy.speed = 100;
    enemy.direction = Vec2(1, 0);
    enemy.position = Vec2(width/2, heigth/2);
    enemy.color = Color::Red();
    enemy.fov = M_PI / 4;

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();
        
        Vec2 direction = (player.position - enemy.position).UnitVector();
        if (direction.Angle(enemy.direction.x, enemy.direction.y) <= enemy.fov) {
            double dt = engine.GetDeltaTime();
            enemy.position += direction * enemy.speed * dt;
            enemy.direction = direction;
        }

        Vec2 vecFOV_up = enemy.direction.Rotate(enemy.fov);
        Vec2 vecFOV_down = enemy.direction.Rotate(2 * M_PI - enemy.fov);

        Graphics::DrawLineSDL(enemy.position.x + enemy.width/2, enemy.position.y + enemy.heigth/2, enemy.position.x + enemy.direction.x * 100, enemy.position.y + enemy.direction.y * 100, Color::Red());
        Graphics::DrawLineSDL(enemy.position.x + enemy.width/2, enemy.position.y + enemy.heigth/2, enemy.position.x + vecFOV_up.x * 1000, enemy.position.y + vecFOV_up.y * 1000, Color(242, 135, 5, 25));
        Graphics::DrawLineSDL(enemy.position.x + enemy.width/2, enemy.position.y + enemy.heigth/2, enemy.position.x + vecFOV_down.x * 1000, enemy.position.y + vecFOV_down.y * 1000, Color(242, 135, 5, 25));
        
        player.position = engine.GetMousePosition();

        Graphics::DrawFillRect(player.position.x, player.position.y, player.width, player.heigth, player.color);
        Graphics::DrawFillRect(enemy.position.x, enemy.position.y, enemy.width, enemy.heigth, enemy.color);

        Logger::Info("Angle Player and Enemy: " + std::to_string(direction.Angle(enemy.direction.x, enemy.direction.y)));

        engine.Render();
    }

    // Destroy the Engine
    Graphics::CloseWindow();

    return 0;
}