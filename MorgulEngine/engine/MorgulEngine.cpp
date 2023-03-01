#include "MorgulEngine.hh"

// CONSTRUCTOR AND DECONSTRUCTOR
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

// GAME LOOP
bool MorgulEngine::NextFrame() {
    dt = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    last_frame_time = SDL_GetTicks();
    return running;
}

void MorgulEngine::CheckInput() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_MOUSEMOTION:
            {
                int x = event.motion.x;
                int y = event.motion.y;
                mouse->UpdatePosition(x, y);
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x, y;
            SDL_GetMouseState(&x, &y);
            mouse->UpdatePosition(x, y);
            if (event.button.button == SDL_BUTTON_LEFT) {
                mouse->leftButtonPressed = true;
            }
            if (event.button.button == SDL_BUTTON_RIGHT) {
                mouse->rightButtonPressed = true;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT) {
                mouse->leftButtonPressed = false;
            }
            if (event.button.button == SDL_BUTTON_RIGHT) {
                mouse->rightButtonPressed = false;
            }
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
            if (event.key.keysym.sym == SDLK_UP) {
                keyboard->upKeyPressed = true;
            }
            if (event.key.keysym.sym == SDLK_DOWN) {
                keyboard->downKeyPressed = true;
            }
            break;
        case SDL_KEYUP:
            if (event.key.keysym.sym == SDLK_F1) {
                debug = !debug;
            }
            if (event.key.keysym.sym == SDLK_UP) {
                keyboard->upKeyPressed = false;
            }
            if (event.key.keysym.sym == SDLK_DOWN) {
                keyboard->downKeyPressed = false;
            }
            break;
        default:
            break;
        }
    }
}

void MorgulEngine::Update() {
    CheckInput();
}

void MorgulEngine::Render() {
    Graphics::RenderFrame();
}

double MorgulEngine::GetDeltaTime() {
    return dt;
}

int MorgulEngine::GetTotalTimeInMilliSeconds() {
    return last_frame_time;
}

double MorgulEngine::GetTotalTimeInSeconds() {
    return 0;
}

Vec2 MorgulEngine::GetMousePosition() {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    return Vec2(mouseX, mouseY);
}