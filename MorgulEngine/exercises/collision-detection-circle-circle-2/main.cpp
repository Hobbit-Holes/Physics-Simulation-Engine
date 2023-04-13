#include "./MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    std::vector<entt::entity> obstacles;

    //Shapes
    CircleShape figCir1 = CircleShape(75, Color::Blue(), false);
    CircleShape figCir2 = CircleShape(75, Color::White(), false);

    //References
    CircleShape &fig_refCir1 = figCir1;
    CircleShape &fig_refCir2 = figCir2;

    //Entities
    const auto a = engine.world.create();
    engine.world.emplace<TransformComponent>(a, Vec2(400, 400));
    engine.world.emplace<KinematicComponent>(a);
    engine.world.emplace<ColliderComponent>(a, fig_refCir1, false);
    obstacles.push_back(a);

    auto c = engine.world.create();
    engine.world.emplace<TransformComponent>(c, Vec2(250, 250));
    engine.world.emplace<KinematicComponent>(c);
    engine.world.emplace<RigidBodyComponent>(c, 1.0f, fig_refCir2);
    engine.world.emplace<ColliderComponent>(c, fig_refCir2, false);

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        Graphics::DrawGrid(100, true, true);
        engine.world.get<TransformComponent>(c).position = engine.GetMousePosition();
        Graphics::DrawCircle(engine.world.get<TransformComponent>(a).position.x, engine.world.get<TransformComponent>(a).position.y, 75, 0, Color::Blue());

        for (auto obstacle: obstacles) {
            Contact contact;
            if(Collisions::IsColliding(c, obstacle, contact, engine.world)) {
                Graphics::DrawFillCircle(contact.start.x, contact.start.y, 3, 0xFFFF00FF);
                Graphics::DrawFillCircle(contact.end.x, contact.end.y, 3, 0xFFFF00FF);
                Graphics::DrawLine(contact.start.x, contact.start.y, 
                                    contact.start.x + contact.normal.x * 15, contact.start.y + contact.normal.y * 15,  0xFFFF00FF);
                std::cout << "Depth :" << contact.depth << std::endl; 
            }
        }

        if(engine.mouse->rightButtonPressed) {
            engine.mouse->rightButtonPressed = false;
            const auto new_ball = engine.world.create();
            CircleShape fig = CircleShape(60, Color::Yellow(), false);
            CircleShape &fig_ref = fig;

            engine.world.emplace<TransformComponent>(new_ball, engine.GetMousePosition());
            engine.world.emplace<KinematicComponent>(new_ball);
            engine.world.emplace<ColliderComponent>(new_ball, fig_ref, false);
            engine.world.emplace<RigidBodyComponent>(new_ball, 1, fig_ref);
            obstacles.push_back(new_ball);
        }

        engine.Render();
    }

    return 0;
}