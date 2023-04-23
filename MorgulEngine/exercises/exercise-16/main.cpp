#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);
    engine.lua.script_file("./snooker.lua");
    std::vector<entt::entity> entities = engine.SetupScene();

    DamageSystem damageSystem;
    engine.eventBus.sink<CollisionEvent>().connect<&DamageSystem::OnCollison>(damageSystem);

    // Variables
    float dragImpulse = engine.lua["dragImpulse"];

    // Objects
    entt::entity player;

    std::vector<entt::entity> balls;
    std::vector<entt::entity> holes;
    std::vector<entt::entity> walls;

    for (auto entity: entities) {
        std::string group = engine.world.get<NameGroupComponent>(entity).group;

        if (group == "Enemy") {
            balls.push_back(entity);
        } else if (group == "Hole") {
            holes.push_back(entity);
        } else if (group == "Wall") {
            walls.push_back(entity);
        } else if (group == "Player") {
            player = entity;
            balls.push_back(entity);
        }
    }


    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        const auto t = engine.world.get<TransformComponent>(player);
        auto& k = engine.world.get<KinematicComponent>(player);

        if (engine.keyboard->spaceKeyPressed) {
            Vec2 impulseDirection = engine.mouse->GetPosition() - t.position;
            float impulseMagnitude = MathUtils::Clamp(impulseDirection.Magnitude() * 0.001, 0.0f, 1.0f);
            k.velocity = impulseDirection * impulseMagnitude * 5;
        }

        for (auto ball: balls) {
            auto& k = engine.world.get<KinematicComponent>(ball);
            auto& rb = engine.world.get<RigidBodyComponent>(ball);

            if (k.velocity != Vec2(0, 0)) {
                Vec2 friction_vector = Force::GenerateFrictionVector(dragImpulse, k.velocity);
                rb.AddForce(friction_vector);
            }
        }

        engine.Render();
    }

    return 0;
}