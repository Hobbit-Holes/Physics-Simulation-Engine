#include <iostream>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <sol.hpp>

#define FPS 30
#define FRAME_TARGET_TIME (1000 / FPS)

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event sdl_event;

bool game_running = false;
int last_frame_time = 0;

int player_x = 0;
int player_y = 0;
int player_speed = 5;

bool graphics_initialization(int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL" << std::endl;
        return false;
    }

    window = SDL_CreateWindow(
        "First Game Loop",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Error creating SDL window" << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (!renderer) {
        std::cerr << "Error creatinf SDL renderer" << std::endl;
        return false;
    }

    std::cout << "Graphics initialized" << std::endl;

    return true;
}

void destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    std::cout << "Graphics destroyed" << std::endl;
}

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

void update() {
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
        SDL_Delay(time_to_wait);

    player_x += player_speed;
    player_y += player_speed;

    last_frame_time = SDL_GetTicks();
}

void render() {
    SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);
    SDL_RenderClear(renderer);

    SDL_Rect box = {player_x, player_y, 10, 10};
    SDL_SetRenderDrawColor(renderer, 255, 211, 147, 255);
    SDL_RenderFillRect(renderer, &box);

    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    game_running = graphics_initialization(600, 400);

    while (game_running) {
        process_input(&game_running);
        update();
        render();
    }

    destroy();

    return 0;
}