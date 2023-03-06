#include "MorgulEngine.hh"

#define FPS 30
#define FRAME_TARGET_TIME (1000 / FPS)


int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Player 1
    int player_x = width / 2;
    int player_y = heigth / 2;
    int player_speed = 200;

    int direction_x = 1;
    int direction_y = 1;
    
    // Game Loop
    while (engine.NextFrame()) {
        // Update Engine
        Graphics::CleanUpScreen();
        engine.Update();

        // Custom Logic
        double dt = engine.GetDeltaTime();

        // Player
        player_x += player_speed * dt * direction_x;
        player_y += player_speed * dt * direction_y;

        if ((player_x < 0 || player_x > width) || (player_y > heigth || player_y < 0)) {
            player_x = width / 2;
            player_y = heigth / 2;

            direction_x = (rand() % 3) - 1;
            direction_y = (rand() % 3) - 1;

            if (direction_x == 0 && direction_y == 0) {
                direction_y = 1;
            }
        }

        Graphics::DrawFillRect(player_x, player_y, 10, 10, Color(255, 211, 147, 255));

        //Logger::Info("Player position: " + std::to_string(player_x) + ", " + std::to_string(player_y));

        // Engine Render
        engine.Render();
    }

    // Destroy the Engine
    Graphics::CloseWindow();

    return 0;
}