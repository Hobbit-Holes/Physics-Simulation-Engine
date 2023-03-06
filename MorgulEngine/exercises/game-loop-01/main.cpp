#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Player 1
    int player_x = 0;
    int player_y = 0;
    float player_width = 10;
    float player_heigth = 10;
    
    // Game Loop
    while (engine.NextFrame()) {
        // Update Engine
        Graphics::CleanUpScreen();
        engine.Update();

        // Player
        player_x += 1;
        player_y += 1;

        Graphics::DrawFillRect(player_x, player_y, player_width, player_heigth, Color::Red());

        Logger::Info("Player position: " + std::to_string(player_x) + ", " + std::to_string(player_y));

        // Engine Render
        engine.Render();
    }

    // Destroy the Engine
    Graphics::CloseWindow();

    return 0;
}