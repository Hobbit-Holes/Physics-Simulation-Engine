#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    std::vector<entt::entity> obstacles;

    //Shapes
    RectangleShape figCir = RectangleShape(75, 100, Color::Blue(), false);
    RectangleShape figRect = RectangleShape(200, 150, Color::Red(), false);

    //References
    RectangleShape &fig_refCir = figCir;
    RectangleShape &fig_refRect = figRect;

    //Entities
    auto a = engine.world.create();
    engine.world.emplace<TransformComponent>(a, Vec2(400, 400));
    engine.world.emplace<KinematicComponent>(a);
    engine.world.emplace<ColliderComponent>(a, fig_refCir, false);
    obstacles.push_back(a);

    auto b = engine.world.create();
    engine.world.emplace<TransformComponent>(b, Vec2(100, 100));
    engine.world.emplace<KinematicComponent>(b);
    engine.world.emplace<ColliderComponent>(b, fig_refRect, false);

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        Graphics::DrawGrid(100, true, true);
        engine.world.get<TransformComponent>(b).position = engine.GetMousePosition();
        Graphics::DrawRect(engine.world.get<TransformComponent>(a).position.x, engine.world.get<TransformComponent>(a).position.y, 75, 100, Color::Blue());
        Graphics::DrawRect(engine.world.get<TransformComponent>(b).position.x, engine.world.get<TransformComponent>(b).position.y, 200, 150, Color::Red());

        for (auto obstacle: obstacles) {
            Contact contact;
            if(Collisions::IsColliding(b, obstacle, contact, engine.world)) {
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