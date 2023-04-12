#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;
    int nEnemies = 10;

    MorgulEngine engine = MorgulEngine(width, heigth);

    //Objects
    CircleShape str =  CircleShape(30, Color::Red(), false);
    CircleShape &str_ref = str;

    auto star = engine.world.create();
    engine.world.emplace<TransformComponent>(star, Vec2(width/2, heigth/2));
    engine.world.emplace<KinematicComponent>(star);
    engine.world.emplace<RigidBodyComponent>(star, 1.0f, str_ref);
    engine.world.emplace<NameGroupComponent>(star, "player " + std::to_string(1), "plaayer");
    engine.world.emplace<ColliderComponent>(star, str_ref, false);

    std::vector<entt::entity> enemies;
    for (int i = 1; i <= nEnemies; i++) {
        float positionX = width / (nEnemies + 1);
        CircleShape obj = CircleShape(25, Color::Cyan(), false);
        CircleShape &obj_ref = obj;

        const auto object = engine.world.create();
        engine.world.emplace<TransformComponent>(object, Vec2(positionX * i, 400));
        engine.world.emplace<KinematicComponent>(object);
        engine.world.emplace<RigidBodyComponent>(object, 1.0f, obj_ref);
        engine.world.emplace<NameGroupComponent>(object, "Enemies " + std::to_string(i), "ENEMIES");
        engine.world.emplace<ColliderComponent>(object, obj_ref, false);

        enemies.push_back(object);
    }
    
    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        Graphics::DrawGrid(100, true, true);
        engine.world.get<TransformComponent>(star).position = engine.GetMousePosition();

        for (auto enemy: enemies) {
            Contact contact;
            if(Collisions::IsColliding(star, enemy, contact, engine.world)) {
                Graphics::DrawFillCircle(contact.start.x, contact.start.y, 3, 0xFFFF00FF);
                Graphics::DrawFillCircle(contact.end.x, contact.end.y, 3, 0xFFFF00FF);
                Graphics::DrawLine(contact.start.x, contact.start.y, 
                                    contact.start.x + contact.normal.x * 15, contact.start.y + contact.normal.y * 15,  0xFFFF00FF);
                std::cout << "Depth :" << contact.depth << std::endl; 
            }
        }

        engine.Render();
    }

    return 0;
}