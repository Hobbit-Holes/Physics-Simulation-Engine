#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 1200;
    int heigth = 800;

    int margin = 25;
    float dragImpulse = 200;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects
    const auto ball = engine.world.create();
    engine.world.emplace<TransformComponent>(ball, Vec2(width/2, heigth/2));
    engine.world.emplace<KinematicComponent>(ball);
    engine.world.emplace<ParticleComponent>(ball, 1, 10);

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        const auto t = engine.world.get<TransformComponent>(ball);
        auto& k = engine.world.get<KinematicComponent>(ball);
        auto& p = engine.world.get<ParticleComponent>(ball);

        Vec2 friction_vector = Force::GenerateFrictionVector(dragImpulse, k.velocity);
        std::cout << "Velocity: " << k.velocity << "\tMagnitude: " << k.velocity.Magnitude() << "\tFriction: " << friction_vector << std::endl;
        p.AddForce(friction_vector);

        Graphics::DrawFillRect(width/2, heigth/2, width-2*margin, heigth-2*margin, Color(2, 115, 51));

        // Borders
        if (t.position.y - p.radius < margin) {
            k.velocity.y *= -1;
        }
        if (t.position.y + p.radius > heigth - margin) {
            k.velocity.y *= -1;
        }
        if (t.position.x - p.radius < margin) {
            k.velocity.x *= -1;
        }
        if (t.position.x + p.radius >  width - margin) {
            k.velocity.x *= -1;
        }
        
        engine.Render();
    }
    
    return 0;
}