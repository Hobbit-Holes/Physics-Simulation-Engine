#include "MorgulEngine.hh"

float getDistance(Vec2 p1, Vec2 p2) {
  float dx = p1.x - p2.x;
  float dy = p1.y - p2.y;
  return sqrt(dx * dx + dy * dy);
}

float getLength(Vec2 v) {
  return sqrt(v.x * v.x + v.y * v.y);
}

Vec2 getDifference(Vec2 p1, Vec2 p2) {
  return Vec2(p1.x - p2.x, p1.y - p2.y);
}

int main(int argc, char* argv[]) {
    int width = 600;
    int height = 400;
    MorgulEngine engine = MorgulEngine(width, height);

    std::vector<entt::entity> particles;
    Vec2 initialPosition = Vec2(200, 100);
    int numParticles = 4;
    int radius = 5;
    for(int i = 0; i < numParticles; i++) {
        const auto particle = engine.world.create();

        engine.world.emplace<TransformComponent>(particle, initialPosition);
        engine.world.emplace<KinematicComponent>(particle);
        engine.world.emplace<ParticleComponent>(particle, 1, radius);

        particles.push_back(particle);
        if(i == 0)
            initialPosition = Vec2(250, 150);
        else if(i==1)
            initialPosition = Vec2(200, 200);
        else if(i==2)
            initialPosition = Vec2(150, 150);
    }

    while(engine.NextFrame()) {
        engine.Update();
        for (auto& ball: particles) {
            auto i = &ball - &particles[0];
            
            const auto t1 = engine.world.get<TransformComponent>(ball);
            const auto k1 = engine.world.get<KinematicComponent>(ball);
            auto& p1 = engine.world.get<ParticleComponent>(ball);

            //float a = getDistance(Vec2(200, 100), Vec2(250, 250));
        }

        engine.Render();
    }
}