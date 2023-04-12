#include <iostream>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "entt/entt.hpp"

enum class EntityType {
    None = 0,
    Ball,
    Paddle,
    Brcik
};

struct Transform {
    float x = 0.0f;
    float y = 0.0f;
};

struct Velocity {
    float x = 0.0f;
    float y = 0.0f;
};

struct Collider {
    float width = 0.0f;
    float height = 0.0f;
    EntityType type = EntityType::None;
};


SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event sdl_event;
entt::registry world;

bool game_running = false;
int last_frame_time = 0;

int width = 800;
int height = 800;

bool graphics_initialization() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL" << std::endl;
        return false;
    }

    window = SDL_CreateWindow(
        "BreakOut Game",
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

bool checkRectangleCollisions(entt::entity r1, entt::entity r2) {
    const Transform r1_transform = world.get<Transform>(r1);
    const Transform r2_transform = world.get<Transform>(r2);
    const Collider r1_collider = world.get<Collider>(r1);
    const Collider r2_collider = world.get<Collider>(r2);

    bool collision_x = r1_transform.x + r1_collider.width * 0.5f >= r2_transform.x - r2_collider.width * 0.5f
                        && r1_transform.x - r1_collider.width * 0.5f <= r2_transform.x + r2_collider.width * 0.5f;
    bool collision_y = r1_transform.y + r1_collider.height * 0.5f >= r2_transform.y - r2_collider.height * 0.5f
                        && r1_transform.y - r1_collider.height * 0.5f <= r2_transform.y + r2_collider.height * 0.5f;

    return collision_x && collision_y;
}

void handleBallCollisions() {
    auto ballView = world.view<Transform, Velocity, Collider>();
    auto brickView = world.view<Transform, Collider>();

    for (auto ballEntity : ballView) {
        Transform& ballTransform = ballView.get<Transform>(ballEntity);
        Velocity& ballVelocity = ballView.get<Velocity>(ballEntity);
        Collider& ballCollider = ballView.get<Collider>(ballEntity);

        for (auto brickEntity : brickView) {
            Collider& brickCollider = brickView.get<Collider>(brickEntity);
            if (ballCollider.type != EntityType::Ball || brickCollider.type != EntityType::Brcik) {
                continue;
            }

            if (checkRectangleCollisions(ballEntity, brickEntity)) {
                world.destroy(brickEntity);
                float halfBrickWidth = brickCollider.width * 0.5f;
                float halfBrickHeight = brickCollider.height * 0.5f;
                float brickCenterX = brickView.get<Transform>(brickEntity).x;
                float brickCenterY = brickView.get<Transform>(brickEntity).y;
                float ballCenterX = ballTransform.x;
                float ballCenterY = ballTransform.y;

                bool fromLeft = ballCenterX < brickCenterX - halfBrickWidth;
                bool fromRight = ballCenterX > brickCenterX + halfBrickWidth;
                bool fromTop = ballCenterY < brickCenterY - halfBrickHeight;
                bool fromBottom = ballCenterY > brickCenterY + halfBrickHeight;

                float ballVelocityX = ballVelocity.x;
                float ballVelocityY = ballVelocity.y;

                if ((fromLeft && ballVelocityX > 0.0f) || (fromRight && ballVelocityX < 0.0f)) {
                    ballVelocityX = -ballVelocityX;
                }

                if ((fromTop && ballVelocityY > 0.0f) || (fromBottom && ballVelocityY < 0.0f)) {
                    ballVelocityY = -ballVelocityY;
                }

                ballVelocity = { ballVelocityX, ballVelocityY };
            }
        }
    }
}

void handlePaddleCollisions() {
    auto paddleView = world.view<Transform, Collider>();
    auto ballView = world.view<Transform, Velocity, Collider>();

    for (auto paddleEntity : paddleView) {
        Transform& paddleTransform = paddleView.get<Transform>(paddleEntity);
        Collider& paddleCollider = paddleView.get<Collider>(paddleEntity);

        for (auto ballEntity : ballView) {
            Transform& ballTransform = ballView.get<Transform>(ballEntity);
            Velocity& ballVelocity = ballView.get<Velocity>(ballEntity);
            Collider& ballCollider = ballView.get<Collider>(ballEntity);

            if (ballCollider.type != EntityType::Ball || paddleCollider.type != EntityType::Paddle) {
                continue;
            }

            if (checkRectangleCollisions(paddleEntity, ballEntity)) {
                float ballDistanceFromPaddleCenter = ballTransform.x - paddleTransform.x;
                float maxDistanceFromCenter = paddleCollider.width / 2.0f + ballCollider.width / 2.0f;
                float normalizedDistanceFromCenter = ballDistanceFromPaddleCenter / maxDistanceFromCenter;
                float bounceAngle = normalizedDistanceFromCenter * 45.0f;

                float ballSpeed = sqrt(ballVelocity.x * ballVelocity.x + ballVelocity.y * ballVelocity.y);
                ballVelocity.x = ballSpeed * sin(bounceAngle);
                ballVelocity.y = -ballSpeed * cos(bounceAngle);

                ballTransform.y = paddleTransform.y - paddleCollider.height / 2.0f - ballCollider.height / 2.0f;
            }
        }
    }
}

void update() {
    //Game Loop
    float dt = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    last_frame_time = SDL_GetTicks();

    //Check for collisions
    handleBallCollisions();
    handlePaddleCollisions();

    //Update game state
    auto view = world.view<Transform, Velocity>();
    for(auto entity : view) {
        Transform& transform = view.get<Transform>(entity);
        Velocity& velocity = view.get<Velocity>(entity);

        transform.x += velocity.x + dt;
        transform.y += velocity.y + dt;
    }
}

bool inicializate() {
    graphics_initialization();

    //Create ball
    const auto ballEntity = world.create();
    world.emplace<Transform>(ballEntity, width * 0.5f, height * 0.4f);
    world.emplace<Velocity>(ballEntity, 1000.0f, 1000.0f);
    world.emplace<Collider>(ballEntity, 25 * 2.0f, 10 * 2.0f, EntityType::Ball);

    //Create paddle
    const auto paddelEntity = world.create();
    world.emplace<Transform>(paddelEntity, width * 0.5f, (height - 50) * 0.4f);
    world.emplace<Velocity>(paddelEntity);
    world.emplace<Collider>(paddelEntity, 75 * 1.0f, 25 * 1.0f, EntityType::Paddle);

   //Create bricks
   std::vector<entt::entity> brickEntities;
   float offset_x = 25.0f;
   float offset_y = 20.0f;
    for (int row = 0; row < 5; ++row) {
        for(int col = 0; col < 10; ++col) {
            entt::entity brickEntity = world.create();
            float x = offset_x + (col + 0.5f) * 25 * 1.25;
            float y = offset_y + (row + 0.5f) * 10 * 1.25;
            world.emplace<Transform>(brickEntity, x, y);
            world.emplace<Collider>(brickEntity, 25 * 1.0f, 10 * 0.1f, EntityType::Brcik);
            brickEntities.push_back(brickEntity);
        }
    }

    return true;
}

void render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    auto view = world.view<Transform, Collider>();
        for (auto entity : view) {
            Transform& transform = view.get<Transform>(entity);
            Collider& collider = view.get<Collider>(entity);
            
            SDL_Rect rect;
            rect.x = static_cast<int>(transform.x - collider.width / 2.0f);
            rect.y = static_cast<int>(transform.y - collider.height / 2.0f);
            rect.w = static_cast<int>(collider.width);
            rect.h = static_cast<int>(collider.height);

            switch (collider.type)
            {
            case EntityType::Ball:
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &rect);
                break;
            case EntityType::Paddle:
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
                break;
            case EntityType::Brcik:
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
                break;            
            default:
                break;
            }

        }

    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {
    game_running = inicializate();

    while (game_running) {
        process_input(&game_running);
        update();
        render();
    }
    
    destroy();

    return 0;
}