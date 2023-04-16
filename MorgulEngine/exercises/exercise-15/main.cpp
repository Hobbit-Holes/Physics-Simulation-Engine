#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;
    int radius = 10;

    MorgulEngine engine = MorgulEngine(width, heigth);
    std::vector<entt::entity> balls;

    //Shapes
    CircleShape figCir = CircleShape(radius, Color::White(), true);
    CircleShape &fig_refCir = figCir;

    CircleShape ball1 = CircleShape(radius, Color(249, 132, 4), true);
    CircleShape &ref_ball1 = ball1;

    CircleShape ball2 = CircleShape(radius, Color(233, 12, 1), true);
    CircleShape &ref_ball2 = ball2;

    CircleShape ball3 = CircleShape(radius, Color(248, 254, 35), true);
    CircleShape &ref_ball3 = ball3;

    CircleShape ball4 = CircleShape(radius, Color(7, 1, 220), true);
    CircleShape &ref_ball4 = ball4;

    CircleShape ball5 = CircleShape(radius, Color(230, 25, 230), true);
    CircleShape &ref_ball5 = ball5;

    CircleShape ball6 = CircleShape(radius, Color(0, 204, 102), true);
    CircleShape &ref_ball6 = ball6;

    CircleShape ball7 = CircleShape(radius, Color(133, 250, 255), true);
    CircleShape &ref_ball7 = ball7;

    CircleShape ball8 = CircleShape(radius, Color(221, 150, 0), true);
    CircleShape &ref_ball8 = ball8;

    CircleShape ball9 = CircleShape(radius, Color(109, 63, 0), true);
    CircleShape &ref_ball9 = ball9;

    CircleShape ball10 = CircleShape(radius, Color(128, 128, 0), true);
    CircleShape &ref_ball10 = ball10;

    auto player = engine.world.create();
    engine.world.emplace<TransformComponent>(player, Vec2(500, 400));
    engine.world.emplace<KinematicComponent>(player);
    engine.world.emplace<ColliderComponent>(player, fig_refCir);
    engine.world.emplace<RigidBodyComponent>(player, 1.0f, fig_refCir);
    engine.world.emplace<NameGroupComponent>(player, "Player ", "Player");

    auto balls1 = engine.world.create();
    engine.world.emplace<TransformComponent>(balls1, Vec2(300, 400));
    engine.world.emplace<KinematicComponent>(balls1);
    engine.world.emplace<ColliderComponent>(balls1, ref_ball1);
    engine.world.emplace<RigidBodyComponent>(balls1, 1.0f, ref_ball1);
    engine.world.emplace<NameGroupComponent>(balls1, "Enemy " + std::to_string(1), "Enemy");
    balls.push_back(balls1);

    auto balls2 = engine.world.create();
    engine.world.emplace<TransformComponent>(balls2, Vec2(275, 390));
    engine.world.emplace<KinematicComponent>(balls2);
    engine.world.emplace<ColliderComponent>(balls2, ref_ball2);
    engine.world.emplace<RigidBodyComponent>(balls2, 1.0f, ref_ball2);
    engine.world.emplace<NameGroupComponent>(balls2, "Enemy " + std::to_string(2), "Enemy");
    balls.push_back(balls2);

    auto balls3 = engine.world.create();
    engine.world.emplace<TransformComponent>(balls3, Vec2(275, 412));
    engine.world.emplace<KinematicComponent>(balls3);
    engine.world.emplace<ColliderComponent>(balls3, ref_ball3);
    engine.world.emplace<RigidBodyComponent>(balls3, 1.0f, ref_ball3);
    engine.world.emplace<NameGroupComponent>(balls3, "Enemy " + std::to_string(3), "Enemy");
    balls.push_back(balls3);

    auto balls4 = engine.world.create();
    engine.world.emplace<TransformComponent>(balls4, Vec2(250, 375));
    engine.world.emplace<KinematicComponent>(balls4);
    engine.world.emplace<ColliderComponent>(balls4, ref_ball4);
    engine.world.emplace<RigidBodyComponent>(balls4, 1.0f, ref_ball4);
    engine.world.emplace<NameGroupComponent>(balls4, "Enemy " + std::to_string(4), "Enemy");
    balls.push_back(balls4);

    auto balls5 = engine.world.create();
    engine.world.emplace<TransformComponent>(balls5, Vec2(250, 400));
    engine.world.emplace<KinematicComponent>(balls5);
    engine.world.emplace<ColliderComponent>(balls5, ref_ball5);
    engine.world.emplace<RigidBodyComponent>(balls5, 1.0f, ref_ball5);
    engine.world.emplace<NameGroupComponent>(balls5, "Enemy " + std::to_string(5), "Enemy");
    balls.push_back(balls5);

    auto balls6 = engine.world.create();
    engine.world.emplace<TransformComponent>(balls6, Vec2(250, 425));
    engine.world.emplace<KinematicComponent>(balls6);
    engine.world.emplace<ColliderComponent>(balls6, ref_ball6);
    engine.world.emplace<RigidBodyComponent>(balls6, 1.0f, ref_ball6);
    engine.world.emplace<NameGroupComponent>(balls6, "Enemy " + std::to_string(6), "Enemy");
    balls.push_back(balls6);

    auto balls7 = engine.world.create();
    engine.world.emplace<TransformComponent>(balls7, Vec2(225, 360));
    engine.world.emplace<KinematicComponent>(balls7);
    engine.world.emplace<ColliderComponent>(balls7, ref_ball7);
    engine.world.emplace<RigidBodyComponent>(balls7, 1.0f, ref_ball7);
    engine.world.emplace<NameGroupComponent>(balls7, "Enemy " + std::to_string(7), "Enemy");
    balls.push_back(balls7);

    auto balls8 = engine.world.create();
    engine.world.emplace<TransformComponent>(balls8, Vec2(225, 385));
    engine.world.emplace<KinematicComponent>(balls8);
    engine.world.emplace<ColliderComponent>(balls8, ref_ball8);
    engine.world.emplace<RigidBodyComponent>(balls8, 1.0f, ref_ball8);
    engine.world.emplace<NameGroupComponent>(balls8, "Enemy " + std::to_string(8), "Enemy");
    balls.push_back(balls8);

    auto balls9 = engine.world.create();
    engine.world.emplace<TransformComponent>(balls9, Vec2(225, 410));
    engine.world.emplace<KinematicComponent>(balls9);
    engine.world.emplace<ColliderComponent>(balls9, ref_ball9);
    engine.world.emplace<RigidBodyComponent>(balls9, 1.0f, ref_ball9);
    engine.world.emplace<NameGroupComponent>(balls9, "Enemy " + std::to_string(9), "Enemy");
    balls.push_back(balls9);

    auto balls10 = engine.world.create();
    engine.world.emplace<TransformComponent>(balls10, Vec2(225, 435));
    engine.world.emplace<KinematicComponent>(balls10);
    engine.world.emplace<ColliderComponent>(balls10, ref_ball10);
    engine.world.emplace<RigidBodyComponent>(balls10, 1.0f, ref_ball10);
    engine.world.emplace<NameGroupComponent>(balls10, "Enemy " + std::to_string(10), "Enemy");
    balls.push_back(balls10);

    //Table
    RectangleShape table1 = RectangleShape(300, 25, Color(125, 85, 0), true);
    RectangleShape &ref_table1 = table1;

    RectangleShape table2 = RectangleShape(25, 340, Color(125, 85, 0), true);
    RectangleShape &ref_table2 = table2;

    RectangleShape table3 = RectangleShape(35, 10, Color(155, 155, 155), true);
    RectangleShape &ref_table3 = table3;

    auto tables1 = engine.world.create();
    engine.world.emplace<TransformComponent>(tables1, Vec2(230, 200));
    engine.world.emplace<KinematicComponent>(tables1);
    engine.world.emplace<RigidBodyComponent>(tables1, 0.0f, ref_table1, true);

    auto tables2 = engine.world.create();
    engine.world.emplace<TransformComponent>(tables2, Vec2(580, 200));
    engine.world.emplace<KinematicComponent>(tables2);
    engine.world.emplace<RigidBodyComponent>(tables2, 0.0f, ref_table1, true);

    auto tables3 = engine.world.create();
    engine.world.emplace<TransformComponent>(tables3, Vec2(230, 600));
    engine.world.emplace<KinematicComponent>(tables3);
    engine.world.emplace<RigidBodyComponent>(tables3, 0.0f, ref_table1, true);

    auto tables4 = engine.world.create();
    engine.world.emplace<TransformComponent>(tables4, Vec2(580, 600));
    engine.world.emplace<KinematicComponent>(tables4);
    engine.world.emplace<RigidBodyComponent>(tables4, 0.0f, ref_table1, true);

    auto tables5 = engine.world.create();
    engine.world.emplace<TransformComponent>(tables5, Vec2(750, 400));
    engine.world.emplace<KinematicComponent>(tables5);
    engine.world.emplace<RigidBodyComponent>(tables5, 0.0f, ref_table2, true);

    auto tables6 = engine.world.create();
    engine.world.emplace<TransformComponent>(tables6, Vec2(50, 400));
    engine.world.emplace<KinematicComponent>(tables6);
    engine.world.emplace<RigidBodyComponent>(tables6, 0.0f, ref_table2, true);

    auto tables7 = engine.world.create();
    engine.world.emplace<TransformComponent>(tables7, Vec2(405, 600));
    engine.world.emplace<KinematicComponent>(tables7);
    engine.world.emplace<RigidBodyComponent>(tables7, 0.0f, ref_table3, true);

    auto tables8 = engine.world.create();
    engine.world.emplace<TransformComponent>(tables8, Vec2(405, 200));
    engine.world.emplace<KinematicComponent>(tables8);
    engine.world.emplace<RigidBodyComponent>(tables8, 0.0f, ref_table3, true);

    CircleShape hole = CircleShape(25, Color(155, 155, 155), true);
    CircleShape &fig_Hole = hole;

    auto hole1 = engine.world.create();
    engine.world.emplace<TransformComponent>(hole1, Vec2(50, 200));
    engine.world.emplace<KinematicComponent>(hole1);
    engine.world.emplace<RigidBodyComponent>(hole1, 0.0f, fig_Hole, true);

    auto hole2 = engine.world.create();
    engine.world.emplace<TransformComponent>(hole2, Vec2(50, 600));
    engine.world.emplace<KinematicComponent>(hole2);
    engine.world.emplace<RigidBodyComponent>(hole2, 0.0f, fig_Hole, true);

    auto hole3 = engine.world.create();
    engine.world.emplace<TransformComponent>(hole3, Vec2(755, 200));
    engine.world.emplace<KinematicComponent>(hole3);
    engine.world.emplace<RigidBodyComponent>(hole3, 0.0f, fig_Hole, true);

    auto hole4 = engine.world.create();
    engine.world.emplace<TransformComponent>(hole4, Vec2(755, 600));
    engine.world.emplace<KinematicComponent>(hole4);
    engine.world.emplace<RigidBodyComponent>(hole4, 0.0f, fig_Hole, true);

    RectangleShape table = RectangleShape(700, 400, Color(0, 143, 57), true);
    RectangleShape &ref_table = table;

    auto tables = engine.world.create();
    engine.world.emplace<TransformComponent>(tables, Vec2(400, 400));
    engine.world.emplace<KinematicComponent>(tables);
    engine.world.emplace<RigidBodyComponent>(tables, 0.0f, ref_table, true);

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        Graphics::DrawGrid(50, true, true);

        engine.Render();
    }

    return 0;
}