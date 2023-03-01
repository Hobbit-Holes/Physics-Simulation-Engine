#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Player 1
    float player1_x = 20;
    float player1_y = 20;
    float player1_width = 10;
    float player1_heigth = 10;
    float player_speed = 60;

    // Player 2
    float player2_x = width - 20;
    float player2_y = 20;
    float player2_width = 20;
    float player2_heigth = 30;

    // Player 3
    float player3_x = 20;
    float player3_y = heigth - 20;
    float radius3 = 10;

    // Player 4
    float player4_x = width - 20;
    float player4_y = heigth - 20;
    float radius4 = 10;

    // Game Loop
    while (engine.NextFrame()) {
        // Update Engine
        Graphics::CleanUpScreen();
        engine.Update();

        // Custom Logic
        double dt = engine.GetDeltaTime();
        
        // Player 1
        player1_x += player_speed * dt;
        player1_y += player_speed * dt;

        // Player 2
        player2_x -= player_speed * dt;
        player2_y += player_speed * dt;

        // Player 3
        player3_x += player_speed * dt;
        player3_y -= player_speed * dt;

        // Player 4
        player4_x -= player_speed * dt;
        player4_y -= player_speed * dt;

        Graphics::DrawGrid(10, true, true);

        Graphics::DrawFillRect(player1_x, player1_y, player1_width, player1_heigth, Color::Red());
        Graphics::DrawRect(player2_x, player2_y, player2_width, player2_heigth, Color::Cyan());
        Graphics::DrawCircle(player3_x, player3_y, radius3, 0, Color::Orange());
        Graphics::DrawFillCircle(player4_x, player4_y, radius4, 0, Color(182, 255, 230));

        Logger::Info("Player 1 position: " + std::to_string(player1_x) + ", " + std::to_string(player1_y));
        Logger::Info("Player 2 position: " + std::to_string(player2_x) + ", " + std::to_string(player2_y));
        Logger::Info("Player 3 position: " + std::to_string(player3_x) + ", " + std::to_string(player3_y));
        Logger::Info("Player 4 position: " + std::to_string(player4_x) + ", " + std::to_string(player4_y));
        Logger::Info("------------------------------------------------");

        // Engine Render
        engine.Render();
    }

    // Destroy the Engine
    Graphics::CloseWindow();

    return 0;
}