#include "Graphics.hh"

SDL_Window* Graphics::window = NULL;
SDL_Renderer* Graphics::renderer = NULL;
uint32_t* Graphics::color_buffer = NULL;
SDL_Texture* Graphics::color_buffer_texture = NULL;
int Graphics::windowWidth, Graphics::windowHeigth = 0;

bool Graphics::OpenWindow(int width, int heigth) {
    windowWidth = width;
    windowHeigth = heigth;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        Logger::Error("Error initializing SDL.");
        return false;
    }
    Logger::Info("Initializing SDL.");

    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED,  SDL_WINDOWPOS_CENTERED, width, heigth, SDL_WINDOW_BORDERLESS);
    if (!window) {
        Logger::Error("Error creating SDL Window.");
        return false;
    }
    Logger::Info("Creating SDL Window.");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        Logger::Error("Error creating SDL renderer.");
        return false;
    }
    Logger::Error("Creating SDL renderer.");

    int resolution = windowHeigth * windowWidth;
    color_buffer = (uint32_t*) malloc(sizeof(uint32_t) * resolution);

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
    SDL_UpdateTexture(color_buffer_texture, NULL, color_buffer, (int)(windowWidth * sizeof(uint32_t)));

    SDL_RenderCopy(renderer, color_buffer_texture, NULL, NULL);

    memset(color_buffer, 0, windowWidth * windowHeigth * sizeof(uint32_t));

    SDL_RenderPresent(renderer);
}

// DRAW FUNCTIONS
void Graphics::DrawPixel(int x, int y, uint32_t color) {
    if (x >= 0 && x < windowWidth && y >= 0 && y < windowHeigth) {
        color_buffer[(windowWidth * y) + x] = color;
    }
}

void Graphics::DrawGrid(int space, bool gridX, bool gridY) {
    Color color = Color(217, 217, 217, 20);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    if (gridX == true) {
        int iterationsX = (int)(windowWidth / space) - 1;
        
        int x = space;
        int y = 0;

        for (int i = 0; i < iterationsX; i++) {
            SDL_RenderDrawLine(renderer, x, y, x, y + windowHeigth);
            x += space;
        }
    }

    if (gridY == true) {
        int iterationsY = (int)(windowHeigth / space) - 1;

        int x = 0;
        int y = space;

        for (int i = 0; i < iterationsY; i++) {
            SDL_RenderDrawLine(renderer, x, y, x + windowWidth, y);
            y += space;
        }
    }    
}

void Graphics::DrawLineSDL(int x0, int y0, int x1, int y1, Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, x0, y0, x1, y1);
}

void Graphics::DrawLine(int x0, int y0, int x1, int y1, Color color) {
    //SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    //SDL_RenderDrawLine(renderer, x0, y0, x1, y1);

    int delta_x = x1 - x0;
    int delta_y = y1 - y0;
    int longest_side_length = (abs(delta_x) >= abs(delta_y)) ? abs(delta_x) : abs(delta_y);

    float x_inc = delta_x / (float)longest_side_length;
    float y_inc = delta_y / (float)longest_side_length;

    float current_x = x0;
    float current_y = y0;

    for (int i = 0; i <= longest_side_length; i++) {
        DrawPixel(round(current_x), round(current_y), color.ToARG());
        current_x += x_inc;
        current_y += y_inc;
    }
}

void Graphics::DrawRect(int x, int y, int width, int heigth, Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect box = {x, y, width, heigth};
    SDL_RenderDrawRect(renderer, &box);
}

void Graphics::DrawFillRect(int x, int y, int width, int heigth, Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect box = {x, y, width, heigth};
    SDL_RenderFillRect(renderer, &box);
}

void Graphics::DrawPolygon(int x, int y, const std::vector<Vec2>& vertices, Color color) {
    for (int i = 0; i < (int)vertices.size(); i++) {
        int j = i + 1;
        if (j == (int)vertices.size()) {
            j = 0;
        }
        DrawLineSDL(x + vertices[i].x, y + vertices[i].y, x + vertices[j].x, y + vertices[j].y, color);
    }
}

void Graphics::DrawCircle(int x0, int y0, int radius, float angle, Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    const int32_t diameter = radius * 2;

    int32_t x = radius - 1;
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t  error = tx - diameter;

    while (x >= y) {
        SDL_RenderDrawPoint(renderer, x0 + x, y0 - y);
        SDL_RenderDrawPoint(renderer, x0 + x, y0 + y);
        SDL_RenderDrawPoint(renderer, x0 - x, y0 - y);
        SDL_RenderDrawPoint(renderer, x0 - x, y0 + y);
        SDL_RenderDrawPoint(renderer, x0 + y, y0 - x);
        SDL_RenderDrawPoint(renderer, x0 + y, y0 + x);
        SDL_RenderDrawPoint(renderer, x0 - y, y0 - x);
        SDL_RenderDrawPoint(renderer, x0 - y, y0 + x);

        if (error <= 0) {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0) {
            --x;
            error += (tx - diameter);
            tx += 2;
        }
    }

    //SDL_RenderDrawLine(renderer, x0, y0, x0 + cos(angle) * radius, y0 + sin(angle) * radius);
}

void Graphics::DrawFillCircle(int x0, int y0, int radius, Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    const int32_t diameter = radius * 2;

    int32_t x = radius - 1;
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t  error = tx - diameter;

    while (x >= y) {
        SDL_RenderDrawLine(renderer, x0 + x, y0 - y, x0 + x, y0 + y);
        SDL_RenderDrawLine(renderer, x0 - x, y0 - y, x0 - x, y0 + y);
        SDL_RenderDrawLine(renderer, x0 + y, y0 - x, x0 + y, y0 + x);
        SDL_RenderDrawLine(renderer, x0 - y, y0 - x, x0 - y, y0 + x);

        if (error <= 0) {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0) {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}
