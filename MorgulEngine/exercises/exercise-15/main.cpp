#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;
    int radius = 12;
    float dragImpulse = 100;

    MorgulEngine engine = MorgulEngine(width, heigth);
    DamageSystem damageSystem;
    engine.eventBus.sink<CollisionEvent>().connect<&DamageSystem::OnCollison>(damageSystem);
    std::vector<entt::entity> balls;

    // Balls
    Vec2 position = Vec2(0, 0);
    int quan = 0;
    for (int i = 1; i <= 4; i++) {
        if(i == 1) {
            position = Vec2(300, heigth/2);
        } else if (i == 2) {
            position.x = 270;
            position.y = heigth/2 - 15;
        } else if (i == 3) {
            position.x = 240;
            position.y = heigth/2 - 30;
        } else {
            position.x = 210;
            position.y = heigth/2 - 45;
        }
        for (int j = 0; j < i; j++) {
            Color color = Color::Lerp(Color:: Cyan(), Color::Magenta(), (float)quan/(float)10);
            CircleShape circ = CircleShape(radius, color, true);
            CircleShape &ref_ball = circ;

            auto ball = engine.world.create();
            engine.world.emplace<TransformComponent>(ball, position);
            engine.world.emplace<KinematicComponent>(ball);
            engine.world.emplace<ColliderComponent>(ball, ref_ball);
            engine.world.emplace<RigidBodyComponent>(ball, 1.0f, ref_ball);
            engine.world.emplace<NameGroupComponent>(ball, "Enemy " + std::to_string(quan + 1), "Enemy");
            engine.world.emplace<DamageComponent>(ball, Vec2(100 + 50 * quan, 100));
            balls.push_back(ball);

            quan++;
            position.y += 30;
        }
    }

    CircleShape figCir = CircleShape(radius, Color::White(), true);
    CircleShape &fig_refCir = figCir;

    auto player = engine.world.create();
    engine.world.emplace<TransformComponent>(player, Vec2(500, 400));
    engine.world.emplace<KinematicComponent>(player);
    engine.world.emplace<ColliderComponent>(player, fig_refCir);
    engine.world.emplace<RigidBodyComponent>(player, 1.0f, fig_refCir);
    engine.world.emplace<NameGroupComponent>(player, "Player ", "Player");
    engine.world.emplace<DamageComponent>(player, Vec2(500, 400));
    balls.push_back(player);

    // Holes
    position = Vec2(50, 200);
    for (int i = 1; i <= 3; i++) {
        CircleShape hole = CircleShape(30, Color(155, 155, 155), true);
        CircleShape &fig_Hole = hole;

        auto hole1 = engine.world.create();
        engine.world.emplace<TransformComponent>(hole1, position);
        engine.world.emplace<KinematicComponent>(hole1);
        engine.world.emplace<ColliderComponent>(hole1, fig_Hole);
        engine.world.emplace<RigidBodyComponent>(hole1, 0.0f, fig_Hole, true);
        engine.world.emplace<NameGroupComponent>(hole1, "Hole " + std::to_string(i), "Hole");

        position.x += width/2 - 50;
    }

    position = Vec2(50, 600);
    for (int i = 4; i <= 6; i++) {
        CircleShape hole = CircleShape(30, Color(155, 155, 155), true);
        CircleShape &fig_Hole = hole;

        auto hole1 = engine.world.create();
        engine.world.emplace<TransformComponent>(hole1, position);
        engine.world.emplace<KinematicComponent>(hole1);
        engine.world.emplace<ColliderComponent>(hole1, fig_Hole);
        engine.world.emplace<RigidBodyComponent>(hole1, 0.0f, fig_Hole, true);
        engine.world.emplace<NameGroupComponent>(hole1, "Hole " + std::to_string(i), "Hole");

        position.x += width/2 - 50;
    }

    // Tables
    RectangleShape table1 = RectangleShape(700, 20, Color(125, 85, 0), true);
    RectangleShape &ref_table1 = table1;

    RectangleShape table2 = RectangleShape(20, 400, Color(125, 85, 0), true);
    RectangleShape &ref_table2 = table2;

    auto tables1 = engine.world.create();
    engine.world.emplace<TransformComponent>(tables1, Vec2(width/2, 200));
    engine.world.emplace<KinematicComponent>(tables1);
    engine.world.emplace<RigidBodyComponent>(tables1, 0.0f, ref_table1, true);

    auto tables2 = engine.world.create();
    engine.world.emplace<TransformComponent>(tables2, Vec2(width/2, 600));
    engine.world.emplace<KinematicComponent>(tables2);
    engine.world.emplace<RigidBodyComponent>(tables2, 0.0f, ref_table1, true);

    auto tables5 = engine.world.create();
    engine.world.emplace<TransformComponent>(tables5, Vec2(750, heigth/2));
    engine.world.emplace<KinematicComponent>(tables5);
    engine.world.emplace<RigidBodyComponent>(tables5, 0.0f, ref_table2, true);

    auto tables6 = engine.world.create();
    engine.world.emplace<TransformComponent>(tables6, Vec2(50, heigth/2));
    engine.world.emplace<KinematicComponent>(tables6);
    engine.world.emplace<RigidBodyComponent>(tables6, 0.0f, ref_table2, true);

    RectangleShape table = RectangleShape(700, 400, Color(0, 143, 57), true);
    RectangleShape &ref_table = table;

    auto tables = engine.world.create();
    engine.world.emplace<TransformComponent>(tables, Vec2(400, 400));
    engine.world.emplace<KinematicComponent>(tables);
    engine.world.emplace<RigidBodyComponent>(tables, 0.0f, ref_table, true);

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