#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    std::vector<entt::entity> obstacles;

    // Shapes
    CircleShape figCir1 = CircleShape(75, Color::Blue(), false);
    CircleShape figCir2 = CircleShape(75, Color::White(), false);
    RectangleShape figRect = RectangleShape(300, 150, Color::Red(), false);

    // References
    CircleShape &fig_refCir1 = figCir1;
    CircleShape &fig_refCir2 = figCir2;
    RectangleShape &fig_refRect = figRect;

    // Entities
    const auto a = engine.world.create();
    engine.world.emplace<TransformComponent>(a, Vec2(250, 250));
    engine.world.emplace<KinematicComponent>(a);
    engine.world.emplace<ColliderComponent>(a, fig_refCir1, true);
    obstacles.push_back(a);

    auto b = engine.world.create();
    engine.world.emplace<TransformComponent>(b, Vec2(500, 500));
    engine.world.emplace<KinematicComponent>(b);
    engine.world.emplace<ColliderComponent>(b, fig_refRect, true);
    obstacles.push_back(b);

    auto c = engine.world.create();
    engine.world.emplace<TransformComponent>(c, Vec2(250, 250));
    engine.world.emplace<KinematicComponent>(c);
    //engine.world.emplace<RigidBodyComponent>(c, 1.0f, fig_refCir2, false);
    engine.world.emplace<ColliderComponent>(c, fig_refCir2, true);

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        Graphics::DrawGrid(100, true, true);

        engine.world.get<TransformComponent>(c).position = engine.GetMousePosition();
        //Graphics::DrawCircle(engine.world.get<TransformComponent>(a).position.x, engine.world.get<TransformComponent>(a).position.y, 75, 0, Color::Blue());
        //Graphics::DrawRect(engine.world.get<TransformComponent>(b).position.x, engine.world.get<TransformComponent>(b).position.y, 300, 150, Color::Red());

        for (auto obstacle: obstacles) {
            Contact contact;
            if(Collisions::IsColliding(c, obstacle, contact, engine.world)) {
                Graphics::DrawFillCircle(contact.start.x, contact.start.y, 3, 0xFFFF00FF);
                Graphics::DrawFillCircle(contact.end.x, contact.end.y, 3, 0xFFFF00FF);
                Graphics::DrawLine(contact.start.x, 
                                    contact.start.y, 
                                    contact.start.x + contact.normal.x * 15, 
                                    contact.start.y + contact.normal.y * 15,  0xFFFF00FF);
                std::cout << "Depth: " << contact.depth << std::endl; 
            }
        }

        if (engine.mouse->rightButtonPressed) {
            engine.mouse->rightButtonPressed = false;

            const auto new_rect = engine.world.create();
            CircleShape fig = CircleShape(60, Color::Yellow(), false);
            CircleShape &fig_ref = fig;

            engine.world.emplace<TransformComponent>(new_rect, engine.GetMousePosition());
            engine.world.emplace<KinematicComponent>(new_rect);
            engine.world.emplace<ColliderComponent>(new_rect, fig_ref, false);
            engine.world.emplace<RigidBodyComponent>(new_rect, 1.0f, fig_ref, false);

            obstacles.push_back(new_rect);
        }

        if(engine.mouse->leftButtonPressed) {
            engine.mouse->leftButtonPressed = false;

            const auto new_ball = engine.world.create();
            RectangleShape fig = RectangleShape(100, 75, Color::Yellow(), false);
            RectangleShape &fig_ref = fig;

            engine.world.emplace<TransformComponent>(new_ball, engine.GetMousePosition());
            engine.world.emplace<KinematicComponent>(new_ball);
            engine.world.emplace<ColliderComponent>(new_ball, fig_ref, false);
            engine.world.emplace<RigidBodyComponent>(new_ball, 1.0f, fig_ref, false);

            obstacles.push_back(new_ball);
        }

        engine.Render();
    }

    return 0;
}