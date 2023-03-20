#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 600;
    int height = 400;
    MorgulEngine engine = MorgulEngine(width, height);

    const auto ball = engine.world.create();
    engine.world.emplace<TransformComponent>(ball, Vec2(width/2, height*0.9));
    engine.world.emplace<KinematicComponent>(ball);
    engine.world.emplace<ParticleComponent>(ball, 0.01, 10, Color::White(), false, 10);

    bool shoot = false;
    Vec2 magnusForce = Vec2();

    while(engine.NextFrame()) {
        engine.Update();
        //Graphics::DrawGrid(20, true, true);

        const auto t = engine.world.get<TransformComponent>(ball);
        auto& k = engine.world.get<KinematicComponent>(ball);
        auto& p = engine.world.get<ParticleComponent>(ball);

        //Adjust ball angular velocity
        if (engine.keyboard->rightKeyPressed)
            k.angularVelocity += 0.1;
        if (engine.keyboard->leftKeyPressed)
            k.angularVelocity -= 0.1;
        
        //Should we shoot?
        if (engine.keyboard->upKeyPressed) {
            shoot = true;
            Vec2 impulseDirection = engine.mouse->GetPosition() - t.position;
            float impulseMagnitude = MathUtils::Clamp(impulseDirection.Magnitude() * 0.001, 0.0f, 1.0f);
            k.velocity = impulseDirection * impulseMagnitude;
        }

        if (shoot) {
            magnusForce = Force::GenerateMagnusVector(0.000001, k.velocity, k.angularVelocity);
            p.AddForce(magnusForce);
        }

        //Drawing the defencise wall and goal zone
        Graphics::DrawRect(width/2, height * 0.6, 100, 50, Color::Red());
        Graphics::DrawFillRect(width/2, height * 0.1, 200, 25, Color::White());

        std::cout << "Position: " << t.position
                  << "\n Velocity: " << k.velocity.Magnitude()
                  << "\n Angular Velocity: " << k.angularVelocity
                  << "\n Magnus force: " << magnusForce << std::endl;

        engine.Render();
    }
    
    return 0;
}