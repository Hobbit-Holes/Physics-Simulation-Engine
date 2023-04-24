#include "Graphics.hh"

// Variables
int Graphics::windowWidth = 0, Graphics::windowHeigth = 0;
SDL_Window* Graphics::window = NULL;
SDL_Renderer* Graphics::renderer = NULL;
uint32_t* Graphics::color_buffer = NULL;
SDL_Texture* Graphics::color_buffer_texture = NULL;
std::map<std::string, SDL_Texture*> Graphics::textures;

// Functions
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
    Logger::Info("Creating SDL renderer.");

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

void Graphics::DrawPixel(int x, int y, Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(renderer, x, y);
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
    int delta_x = x1 - x0;
    int delta_y = y1 - y0;
    int longest_side_length = (abs(delta_x) >= abs(delta_y)) ? abs(delta_x) : abs(delta_y);

    float x_inc = delta_x / (float)longest_side_length;
    float y_inc = delta_y / (float)longest_side_length;

    float current_x = x0;
    float current_y = y0;

    for (int i = 0; i <= longest_side_length; i++) {
        DrawPixel(round(current_x), round(current_y), color);//color.ToARG());
        current_x += x_inc;
        current_y += y_inc;
    }
}

void Graphics::DrawLine(Vec2 p0, Vec2 p1, Color color) {
    int delta_x = p1.x - p0.x;
    int delta_y = p1.y - p0.y;
    int longest_side_length = (abs(delta_x) >= abs(delta_y)) ? abs(delta_x) : abs(delta_y);

    float x_inc = delta_x / (float)longest_side_length;
    float y_inc = delta_y / (float)longest_side_length;

    float current_x = p0.x;
    float current_y = p0.y;

    for (int i = 0; i <= longest_side_length; i++) {
        DrawPixel(round(current_x), round(current_y), color);
        current_x += x_inc;
        current_y += y_inc;
    }
}

void Graphics::DrawRect(int x, int y, int width, int heigth, Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect box = {x - width/2, y - heigth/2, width, heigth};
    SDL_RenderDrawRect(renderer, &box);
}

void Graphics::DrawFillRect(int x, int y, int width, int heigth, Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect box = {x - width/2, y - heigth/2, width, heigth};
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

    SDL_RenderDrawLine(renderer, x0, y0, x0 + cos(angle) * radius, y0 + sin(angle) * radius);
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

void Graphics::DrawStar(int x, int y, int radius, int points, Color color) {
    // Check parameters
    if (radius <= 0) {
        radius = 1;
    }

    if (points < 5) {
        points = 5;
    }

    // Vertices
    std::vector<Vec2> pointsPosition;
    for (int i = 1; i <= points; i++) {
        Vec2 position = position.FromModuleAngle(radius, (2* M_PI / points) * (i));
        position += Vec2(x, y);
        pointsPosition.push_back(position);
    }

    // Draw star
    for (int i = 0; i < points; i++) {
        Vec2 actualPoint = pointsPosition[i];
        
        int j = i + 2;
        if (j >= points) {
            j = j - points;
        }

        Vec2 nextPoint = pointsPosition[j];

        DrawLineSDL(actualPoint.x, actualPoint.y, nextPoint.x, nextPoint.y, color);
    }
}

void Graphics::DrawStar(int x, int y, const std::vector<Vec2>& vertices, Color color) {
    // Draw star
    for (int i = 0; i < (int)vertices.size(); i++) {
        Vec2 actualPoint = vertices[i];
        
        int j = i + 2;
        if (j >= (int)vertices.size()) {
            j = j - (int)vertices.size();
        }

        Vec2 nextPoint = vertices[j];

        DrawLineSDL(x + actualPoint.x, y + actualPoint.y, x + nextPoint.x, y + nextPoint.y, color);
    }
}

void Graphics::DrawStarPlatinum(int x, int y, int radius, int points, Color color) {
    // Check parameters
    if (radius <= 0) {
        radius = 1;
    }

    if (points < 3) {
        points = 3;
    }

    // Vertices
    std::vector<Vec2> pointsPosition;
    for (int i = 1; i <= points; i++) {
        Vec2 position = position.FromModuleAngle(radius, (2* M_PI / points) * (i));
        pointsPosition.push_back(position);
    }

    // Draw star
    for (int i = 0; i < points; i++) {
        Vec2 actualPoint = pointsPosition[i];
        
        int j = i + 1;
        if (j >= points) {
            j = 0;
        }

        Vec2 nextPoint = pointsPosition[j];

        Vec2 distance = nextPoint - actualPoint;
        Vec2 middlePoint = distance / 2 + distance.UnitVector().Normal() * (radius / 4);

        DrawLineSDL(x + actualPoint.x, y + actualPoint.y, x + actualPoint.x + middlePoint.x, y + actualPoint.y + middlePoint.y, color);
        DrawLineSDL(x + actualPoint.x + middlePoint.x, y + actualPoint.y + middlePoint.y, x + nextPoint.x, y + nextPoint.y, color);
    }
}

void Graphics::DrawStarPlatinum(int x, int y, float radius, const std::vector<Vec2>& vertices, Color color) {
    // Draw star
    for (int i = 0; i < (int)vertices.size(); i++) {
        Vec2 actualPoint = vertices[i];
        
        int j = i + 1;
        if (j >= (int)vertices.size()) {
            j = 0;
        }

        Vec2 nextPoint = vertices[j];

        Vec2 distance = nextPoint - actualPoint;
        Vec2 middlePoint = distance / 2 + distance.UnitVector().Normal() * (radius / 4);

        DrawLineSDL(x + actualPoint.x, y + actualPoint.y, x + actualPoint.x + middlePoint.x, y + actualPoint.y + middlePoint.y, color);
        DrawLineSDL(x + actualPoint.x + middlePoint.x, y + actualPoint.y + middlePoint.y, x + nextPoint.x, y + nextPoint.y, color);
    }
}

void Graphics::DrawSprite(SDL_Texture* texture, Vec2 position, Vec2 scale, int width, int height, float rotation, SDL_Rect _srcRect) {
    SDL_Rect srcRect = _srcRect;

    SDL_Rect dstRect = {
        static_cast<int>(position.x - width * scale.x * 0.5),
        static_cast<int>(position.y - height * scale.y * 0.5),
        static_cast<int>(width * scale.x),
        static_cast<int>(height * scale.y)
    };

    if (SDL_RenderCopyEx(renderer, texture, &srcRect, &dstRect, rotation, NULL, SDL_FLIP_NONE) != 0) {
        std::cout << "Error rendering sprite: " << SDL_GetError() << std::endl;
    }
}
        
// Asset Manager
void Graphics::ClearAssets() {
    textures.clear();
}

void Graphics::AddTexture(const std::string& assetId, const std::string& filePath) {
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    textures.emplace(assetId, texture);
}

SDL_Texture* Graphics::GetTexture(const std::string& assetId) {
    return textures[assetId];
}
