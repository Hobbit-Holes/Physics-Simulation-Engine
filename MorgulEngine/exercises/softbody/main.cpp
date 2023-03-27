#include <iostream>
#include <vector>
#include <cmath>
#include <SDL2/SDL.h>
#include "MorgulEngine.hh"

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

float getDistance(Particle* p1, Particle* p2) {
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

float getLength(Particle v) {
  return sqrt(v.x * v.x + v.y * v.y);
}

Particle getDifference(Particle* p1, Particle* p2) {
  return Particle(p1->x - p2->x, p1->y - p2->y, 0);
}

void keepInsideView(Particle* particle) {
  if (particle->y >= 600)
    particle->y = 600;
  if (particle->x >= 600)
    particle->x = 600;
  if (particle->y < 0)
    particle->y = 0;
  if (particle->x < 0)
    particle->x = 0;
}

int main(int argc, char* argv[]) {
  int width = 600;
  int height = 600;

  MorgulEngine engine = MorgulEngine(width, height);

  std::vector<Particle*> particles;
  std::vector<Stick*> sticks;

  // Add four particles
  Particle* pA = new Particle(200, 100, 1);
  Particle* pB = new Particle(250, 150, 1);
  Particle* pC = new Particle(200, 200, 1);
  Particle* pD = new Particle(150, 150, 1);
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

  while (engine.NextFrame()) {
    engine.Update();

    // Update particle position using Verlet integration
    for (Particle* particle: particles) {
      double delta_time = engine.GetDeltaTime();
      Particle force = Particle(0.0, 9.8, 0);

      Particle acceleration = Particle(force.x / particle->mass, force.y / particle->mass, 0);

      Particle prevPosition = Particle(particle->x, particle->y, 0);

      particle->x = particle->x * 2 - particle->prevx + acceleration.x * (delta_time * delta_time);
      particle->y = particle->y * 2 - particle->prevy + acceleration.y * (delta_time * delta_time);

      particle->prevx = prevPosition.x;
      particle->prevy = prevPosition.y;

      keepInsideView(particle);

      Graphics::DrawFillCircle(particle->x, particle->y, particle->radius, Color::White());
    }

    // Apply stick constraint to particles
    for (Stick* stick: sticks) {
      Particle diff = getDifference(stick->p1, stick->p2);
      float diffFactor = (stick->length - getLength(diff)) / getLength(diff) * 0.5f;
      Particle offset = Particle(diff.x * diffFactor, diff.y * diffFactor, 0);

      stick->p1->x += offset.x;
      stick->p1->y += offset.y;
      stick->p2->x -= offset.x;
      stick->p2->y -= offset.y;
      
      Graphics::DrawLineSDL(stick->p1->x, stick->p1->y, stick->p2->x, stick->p2->y, Color::White());
    }

    engine.Render();
  }

  return 0;
}
