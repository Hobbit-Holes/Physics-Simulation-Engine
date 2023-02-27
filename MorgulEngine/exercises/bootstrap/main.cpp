#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 600;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Player
    float player_x = 20;
    float player_y = 20;
    float player_width = 10;
    float player_heigth = 10;
    float player_speed = 60;

    // Game Loop
    while (engine.NextFrame()) {
        // Update Engine
        engine.Update();

        // Custom Logic
        double dt = engine.GetDeltaTime();
        
        player_x += player_speed * dt;
        player_y += player_speed * dt;

        Graphics::DrawFillRect(player_x, player_y, player_width, player_heigth, Color::Orange());

        Logger::Info("Player position: " + std::to_string(player_x) + ", " + std::to_string(player_y));

        // Engine Render
        engine.Render();
    }

    // Destroy the Engine
    Graphics::CloseWindow();

    return 0;
}