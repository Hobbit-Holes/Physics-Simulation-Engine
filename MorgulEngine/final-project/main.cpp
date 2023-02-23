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
    float player_speed = 50;

    // Game Loop
    while (engine.NextFrame()) {
        // Update Engine


        // Custom Logic
        Logger::Info("Player position: " + std::to_string(player_x) + ", " + std::to_string(player_y));

        // Engine Render

    }

    // Destroy the Engine


    return 0;
}