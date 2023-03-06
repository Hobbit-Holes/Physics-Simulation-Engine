#include "MorgulEngine.hh"

#define FPS 30
#define FRAME_TARGET_TIME (1000 / FPS)

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    int last_frame_time = 0;

    // Player 1
    int player_x = 0;
    int player_y = 0;
    float player_width = 10;
    float player_heigth = 10;
    int player_speed = 5;
    
    // Game Loop
    while (engine.NextFrame()) {
        // Update Engine
        Graphics::CleanUpScreen();
        engine.Update();

        // Player
        int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

        if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
            SDL_Delay(time_to_wait);

        player_x += player_speed;
        player_y += player_speed;

        last_frame_time = SDL_GetTicks();

        Graphics::DrawFillRect(player_x, player_y, player_width, player_heigth, Color(255, 211, 147, 255));

        //Logger::Info("Player position: " + std::to_string(player_x) + ", " + std::to_string(player_y));

        // Engine Render
        engine.Render();
    }

    // Destroy the Engine
    Graphics::CloseWindow();

    return 0;
}