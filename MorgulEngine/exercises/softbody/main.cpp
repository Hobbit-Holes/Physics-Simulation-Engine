#include <iostream>
#include <vector>
#include <cmath>
#include <SDL2/SDL.h>

// Constants
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;
bool game_running = false;
int last_frame_time = 0;

// Particle class
class Particle {
  public:
    Particle(float x, float y, float mass) {
        this->x = x;
        this->y = y;
        this->prevx = x;
        this->prevy = y;
        this->mass = mass;
        this->radius = 5;
    }
    float x, y, prevx, prevy, mass, radius;
};

// Stick class
class Stick {
  public:
    Stick(Particle* p1, Particle* p2, float length) {
        this->p1 = p1;
        this->p2 = p2;
        this->length = length;
    }
    Particle* p1, * p2;
    float length;
};

// Variables
std::vector<Particle*> particles;
std::vector<Stick*> sticks;
Particle* hover = nullptr;
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Event sdl_event;

// Functions
float getDistance(Particle* p1, Particle* p2) {
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

float getLength(SDL_Point v) {
  return sqrt(v.x * v.x + v.y * v.y);
}

SDL_Point getDifference(Particle* p1, Particle* p2) {
  return { static_cast<int>(p1->x - p2->x), static_cast<int>(p1->y - p2->y) };
}

void keepInsideView(Particle* particle) {
  if (particle->y >= WINDOW_HEIGHT)
    particle->y = WINDOW_HEIGHT;
  if (particle->x >= WINDOW_WIDTH)
    particle->x = WINDOW_WIDTH;
  if (particle->y < 0)
    particle->y = 0;
  if (particle->x < 0)
    particle->x = 0;
}

bool graphics_initialization(int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL" << std::endl;
        return false;
    }

    // Characteristics of the window
    window = SDL_CreateWindow(
        "Softbody",
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

// QUIT GAME
void destroy() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  std::cout << "Graphics destroyed" << std::endl;
}

void update_physics() {
  int delta_time_ms = SDL_GetTicks() - last_frame_time;
  float delta_time = delta_time_ms / 1000.0f;

  // Update particle position using Verlet integration
  for (size_t i = 0; i < particles.size(); i++) {
    Particle* particle = particles[i];

    SDL_Point force = { 0, 1 };

    SDL_Point acceleration = { static_cast<int>(force.x / particle->mass), static_cast<int>(force.y / particle->mass) };

    SDL_Point prevPosition = { static_cast<int>(particle->x), static_cast<int>(particle->y) };

    particle->x = particle->x * 2 - particle->prevx + acceleration.x * (delta_time * delta_time);
    particle->y = particle->y * 2 - particle->prevy + acceleration.y * (delta_time * delta_time);

    particle->prevx = prevPosition.x;
    particle->prevy = prevPosition.y;

    keepInsideView(particle);

  }

  // Apply stick constraint to particles
  for (size_t i = 0; i < sticks.size(); i++) {
    Stick* stick = sticks[i];

    SDL_Point diff = getDifference(stick->p1, stick->p2);
    float diffFactor = (stick->length - getLength(diff)) / getLength(diff) * 0.5f;
    SDL_Point offset = { static_cast<int>(diff.x * diffFactor), static_cast<int>(diff.y * diffFactor) };

    stick->p1->x += offset.x;
    stick->p1->y += offset.y;
    stick->p2->x -= offset.x;
    stick->p2->y -= offset.y;
  }

  last_frame_time = SDL_GetTicks();
}

void setup(int width, int height) {
  // Add four particles
  Particle* pA = new Particle(200, 100, 10000);
  Particle* pB = new Particle(250, 150, 10000);
  Particle* pC = new Particle(200, 200, 10000);
  Particle* pD = new Particle(150, 150, 10000);
  particles.push_back(pA);
  particles.push_back(pB);
  particles.push_back(pC);
  particles.push_back(pD);
 
  // Add four stick constraints between particles
  Stick* stickAB = new Stick(pA, pB, getDistance(pA, pB));
  Stick* stickBC = new Stick(pB, pC, getDistance(pB, pC));
  Stick* stickCD = new Stick(pC, pD, getDistance(pC, pD));
  Stick* stickDA = new Stick(pD, pA, getDistance(pD, pA));
  Stick* stickAC = new Stick(pA, pC, getDistance(pA, pC));
  Stick* stickDB = new Stick(pD, pB, getDistance(pD, pB));
  sticks.push_back(stickAB);
  sticks.push_back(stickBC);
  sticks.push_back(stickCD);
  sticks.push_back(stickDA);
  sticks.push_back(stickAC);
  sticks.push_back(stickDB);
}

void draw() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  hover = NULL;

  update_physics();
 
  for (const Particle* const& particle : particles) {
    if (particle == hover) {
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    } else {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }
  }

  for (const Particle* const& particle : particles) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect rect = {static_cast<int>(particle->x - particle->radius / 2), 
                    static_cast<int>(particle->y - particle->radius / 2), 
                    static_cast<int>(particle->radius), static_cast<int>(particle->radius)};
    SDL_RenderFillRect(renderer, &rect);
  }

  for (const Stick* const& stick : sticks) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, stick->p1->x, stick->p1->y, stick->p2->x, stick->p2->y);
  }

  SDL_RenderPresent(renderer);
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

int main(int argc, char* argv[]) {
  game_running = graphics_initialization(600, 600);
  setup(600, 600);
  while (game_running) {
    process_input(&game_running);
    draw();
  }
  destroy();

  return 0;
}
