#include "MorgulEngine.hh"

MorgulEngine::MorgulEngine(int width, int heigth) {
    Logger::Info("Morgul Engine constructor called.");

    // Setting core variables
    running = false;
    mouse = new Mouse();
    keyboard = new Keyboard();

    // Graphics initialization
    if (Graphics::OpenWindow(width, heigth)) {
        Logger::Info("Graphics initialized.");
    }
    running = true;
}

MorgulEngine::~MorgulEngine() {
    Logger::Info("Morgul Engine deconstructor called.");
    Graphics::CloseWindow();
}

bool MorgulEngine::NextFrame() {
    dt = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    last_frame_time = SDL_GetTicks();
    return running;
}