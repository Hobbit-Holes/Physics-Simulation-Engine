#include "MorgulEngine.hh"

#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event sdl_event;

bool game_running = false;
int last_frame_time = 0;

int player_x = 0;
int player_y = 0;
int player_speed = 200;

// INPUTS
void process_input(bool *game_is_running) {
    SDL_PollEvent(&sdl_event);

    switch (sdl_event.type) {
    case SDL_QUIT:
        *game_is_running = false;
        break;
    case SDL_KEYDOWN:
        if (sdl_event.key.keysym.sym == SDLK_ESCAPE) 
            *game_is_running = false;
        break;
    }
}

// UPDATE PLAYER POSITION
void update() {
    int delta_time_ms = SDL_GetTicks() - last_frame_time;
    float dt = delta_time_ms / 1000.0f;

    player_x += player_speed * dt;
    player_y += player_speed * dt;

    last_frame_time = SDL_GetTicks();
}

// DRAW THE PIXELS OF THE SCREEN
void render() {
    SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);      // Background Color
    SDL_RenderClear(renderer);

    SDL_Rect box = {player_x, player_y, 10, 10};            // Shape of the player
    SDL_SetRenderDrawColor(renderer, 255, 211, 147, 255);   // Player color
    SDL_RenderFillRect(renderer, &box);

    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    game_running = Graphics::OpenWindow(600, 400);

    while (game_running) {
        process_input(&game_running);
        update();
        render();
    }

    Graphics::CloseWindow();

    return 0;
}