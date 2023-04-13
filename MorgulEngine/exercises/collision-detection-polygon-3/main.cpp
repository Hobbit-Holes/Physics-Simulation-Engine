#include "./MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    std::vector<entt::entity> obstacles;

    //Shapes
    RectangleShape figRect1 = RectangleShape(300, 150, Color::Red(), false);
    RectangleShape figRect2 = RectangleShape(200, 150, Color::White(), false);

    //References
    RectangleShape &fig_refRect1 = figRect1;
    RectangleShape &fig_refRect2 = figRect2;

    //Entities
    auto a = engine.world.create();
    engine.world.emplace<TransformComponent>(a, Vec2(400, 400));
    engine.world.emplace<KinematicComponent>(a);
    engine.world.emplace<ColliderComponent>(a, fig_refRect1, false);
    engine.world.emplace<RigidBodyComponent>(a, 1.0f, fig_refRect1);
    obstacles.push_back(a);


    auto c = engine.world.create();
    engine.world.emplace<TransformComponent>(c, Vec2(250, 250));
    engine.world.emplace<KinematicComponent>(c);
    engine.world.emplace<ColliderComponent>(c, figRect2, false);
    engine.world.emplace<RigidBodyComponent>(c, 1.0f, fig_refRect2);

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        Graphics::DrawGrid(100, true, true);
        engine.world.get<TransformComponent>(c).position = engine.GetMousePosition();

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

        if(engine.mouse->leftButtonPressed) {
            engine.mouse->leftButtonPressed = false;
            const auto new_ball = engine.world.create();
            RectangleShape fig = RectangleShape(100, 75, Color::Yellow(), false);
            RectangleShape &fig_ref = fig;

            engine.world.emplace<TransformComponent>(new_ball, engine.GetMousePosition());
            engine.world.emplace<KinematicComponent>(new_ball);
            engine.world.emplace<ColliderComponent>(new_ball, fig_ref, false);
            engine.world.emplace<RigidBodyComponent>(new_ball, 1.0f, fig_ref);
            obstacles.push_back(new_ball);
        }

        engine.Render();
    }

    return 0;
}