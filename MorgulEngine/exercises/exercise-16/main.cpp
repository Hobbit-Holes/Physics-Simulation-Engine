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
            auto& t = engine.world.get<TransformComponent>(ball);
            auto& k = engine.world.get<KinematicComponent>(ball);
            auto& rb = engine.world.get<RigidBodyComponent>(ball);

            if (k.velocity != Vec2(0, 0)) {
                Vec2 friction_vector = Force::GenerateFrictionVector(dragImpulse, k.velocity);
                rb.AddForce(friction_vector);
            }

            if (t.position.x < 70 && t.position.x > 30) {
                if (k.velocity.y > 0) {
                    Vec2 velocity = k.velocity;
                    k.velocity = k.velocity.UnitVector().Normal2();
                    k.velocity.x *= abs(velocity.x);
                    k.velocity.y *= abs(velocity.y);
                } else {
                    Vec2 velocity = k.velocity;
                    k.velocity = k.velocity.UnitVector().Normal();
                    k.velocity.x *= abs(velocity.x);
                    k.velocity.y *= abs(velocity.y);
                }

                t.position.x += (70 - t.position.x) + 0.1;

                
            } else if (t.position.x > 730 && t.position.x < 770) {
                if (k.velocity.y > 0) {
                    Vec2 velocity = k.velocity;
                    k.velocity = k.velocity.UnitVector().Normal();
                    k.velocity.x *= abs(velocity.x);
                    k.velocity.y *= abs(velocity.y);
                } else {
                    Vec2 velocity = k.velocity;
                    k.velocity = k.velocity.UnitVector().Normal2();
                    k.velocity.x *= abs(velocity.x);
                    k.velocity.y *= abs(velocity.y);
                }

                t.position.x -= (t.position.x - 730) + 0.1;
            }

            if (t.position.y < 220 && t.position.y > 180) {
                if (k.velocity.x > 0) {
                    Vec2 velocity = k.velocity;
                    k.velocity = k.velocity.UnitVector().Normal();
                    k.velocity.x *= abs(velocity.x);
                    k.velocity.y *= abs(velocity.y);
                } else {
                    Vec2 velocity = k.velocity;
                    k.velocity = k.velocity.UnitVector().Normal2();
                    k.velocity.x *= abs(velocity.x);
                    k.velocity.y *= abs(velocity.y);
                }

                t.position.y += (220 - t.position.y) + 0.1;

            } else if (t.position.y > 580 && t.position.y < 620) {
                if (k.velocity.x > 0) {
                    Vec2 velocity = k.velocity;
                    k.velocity = k.velocity.UnitVector().Normal2();
                    k.velocity.x *= abs(velocity.x);
                    k.velocity.y *= abs(velocity.y);
                } else {
                    Vec2 velocity = k.velocity;
                    k.velocity = k.velocity.UnitVector().Normal();
                    k.velocity.x *= abs(velocity.x);
                    k.velocity.y *= abs(velocity.y);
                }

                t.position.y -= (t.position.y - 580) + 0.1;
            }
        }

        engine.Render();
    }

    return 0;
}