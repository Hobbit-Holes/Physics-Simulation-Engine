#include "MorgulEngine.hh"

struct object {
    Vec2 position;
    int speed;
    int width;
    int heigth;
    Color color;
    Vec2 direction;
    float fov;
} player, enemy1, enemy2;

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

    enemy1.width = 10;
    enemy1.heigth = 10;
    enemy1.speed = 100;
    enemy1.direction = Vec2(1, 0);
    enemy1.position = Vec2(width/2, heigth/2);
    enemy1.color = Color::Red();
    enemy1.fov = M_PI / 4;

    enemy2.width = 10;
    enemy2.heigth = 10;
    enemy2.speed = 100;
    enemy2.direction = Vec2(0, -1);
    enemy2.position = Vec2(3*width/4, heigth/2);
    enemy2.color = Color::Red();
    enemy2.fov = M_PI / 3;

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();
        
        player.position = engine.GetMousePosition();
        
        // Enemy 1
        Vec2 direction = (player.position - enemy1.position).UnitVector();
        if (direction.Angle(enemy1.direction) <= enemy1.fov) {
            double dt = engine.GetDeltaTime();
            enemy1.position += direction * enemy1.speed * dt;
            enemy1.direction = direction;
        }

        Vec2 vecFOV_up = enemy1.direction.Rotate(enemy1.fov);
        Vec2 vecFOV_down = enemy1.direction.Rotate(2 * M_PI - enemy1.fov);

        Graphics::DrawLineSDL(enemy1.position.x, enemy1.position.y, enemy1.position.x + vecFOV_down.x * 1000, enemy1.position.y + vecFOV_down.y * 1000, Color(242, 135, 5, 50));
        Graphics::DrawLineSDL(enemy1.position.x, enemy1.position.y, enemy1.position.x + enemy1.direction.x * 100, enemy1.position.y + enemy1.direction.y * 100, Color::Red());
        Graphics::DrawLineSDL(enemy1.position.x, enemy1.position.y, enemy1.position.x + vecFOV_up.x * 1000, enemy1.position.y + vecFOV_up.y * 1000, Color(242, 135, 5, 50));
        
        Logger::Info("Angle Player and Enemy 1: " + std::to_string(direction.Angle(enemy1.direction)));

        // Enemy 2
        direction = (player.position - enemy2.position).UnitVector();
        if (direction.Angle(enemy2.direction) <= enemy2.fov) {
            double dt = engine.GetDeltaTime();
            enemy2.position += direction * enemy2.speed * dt;
            enemy2.direction = direction;
        }

        vecFOV_up = enemy2.direction.Rotate(enemy2.fov);
        vecFOV_down = enemy2.direction.Rotate(2 * M_PI - enemy2.fov);

        Graphics::DrawLineSDL(enemy2.position.x, enemy2.position.y, enemy2.position.x + enemy2.direction.x * 100, enemy2.position.y + enemy2.direction.y * 100, Color::Red());
        Graphics::DrawLineSDL(enemy2.position.x, enemy2.position.y, enemy2.position.x + vecFOV_up.x * 1000, enemy2.position.y + vecFOV_up.y * 1000, Color(242, 135, 5, 50));
        Graphics::DrawLineSDL(enemy2.position.x, enemy2.position.y, enemy2.position.x + vecFOV_down.x * 1000, enemy2.position.y + vecFOV_down.y * 1000, Color(242, 135, 5, 50));

        Graphics::DrawFillRect(player.position.x, player.position.y, player.width, player.heigth, player.color);
        Graphics::DrawFillRect(enemy1.position.x, enemy1.position.y, enemy1.width, enemy1.heigth, enemy1.color);
        Graphics::DrawFillRect(enemy2.position.x, enemy2.position.y, enemy2.width, enemy2.heigth, enemy2.color);

        Logger::Info("Angle Player and Enemy 2: " + std::to_string(direction.Angle(enemy2.direction)));

        engine.Render();
    }

    // Destroy the Engine
    Graphics::CloseWindow();

    return 0;
}