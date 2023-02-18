#include "Graphics.hh"

SDL_Window* Graphics::window = NULL;
SDL_Renderer* Graphics::renderer = NULL;
int Graphics::windowWidth, Graphics::windowHeigth = 0;

bool Graphics::OpenWindow(int width, int heigth) {
    windowWidth = width;
    windowHeigth = heigth;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        Logger::Error("Error initializing SDL.");
        return false;
    }

    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED,  SDL_WINDOWPOS_CENTERED, width, heigth, SDL_WINDOW_BORDERLESS);
    if (!window) {
        Logger::Error("Error creating SDL Window.");
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        Logger::Error("Error creating SDL renderer.");
        return false;
    }

    return true;
}

void Graphics::CloseWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    Logger::Info("Graphics terminated.");
}

void Graphics::CleanUpScreen() {
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Graphics::RenderFrame() {
    SDL_RenderPresent(renderer);
}