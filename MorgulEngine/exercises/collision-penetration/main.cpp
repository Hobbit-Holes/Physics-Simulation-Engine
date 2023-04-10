#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    std::vector<entt::entity> obstacles;

    const auto a = engine.world.create();
    CircleShape figCir1 = CircleShape(75, Color::Blue(), false);
    CircleShape &fig_refCir1 = figCir1;
    engine.world.emplace<TransformComponent>(a, Vec2(250, 250));
    engine.world.emplace<KinematicComponent>(a);
    engine.world.emplace<ColliderComponent>(a, fig_refCir1, false, false);
    obstacles.push_back(a);

    const auto b = engine.world.create();
    RectangleShape figRect = RectangleShape(200, 150, Color::Red(), false);
    RectangleShape &fig_refRect = figRect;
    engine.world.emplace<TransformComponent>(b, Vec2(500, 500));
    engine.world.emplace<KinematicComponent>(b);
    engine.world.emplace<ColliderComponent>(b, fig_refRect, false, false);
    obstacles.push_back(b);

    auto c = engine.world.create();
    CircleShape figCir2 = CircleShape(75, Color::White(), false);
    CircleShape &fig_refCir2 = figCir2;
    engine.world.emplace<TransformComponent>(c, Vec2(250, 250));
    engine.world.emplace<KinematicComponent>(c);
    engine.world.emplace<ColliderComponent>(c, fig_refCir2, false, false);
    //obstacles.push_back(c);

    while (engine.NextFrame()) {
        engine.Update();

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
            engine.world.emplace<ColliderComponent>(new_ball, fig_ref, false, false);
            engine.world.emplace<RigidBodyComponent>(new_ball, 1, fig_ref);
            obstacles.push_back(new_ball);
        }

        if(engine.mouse->rightButtonPressed) {
            engine.mouse->rightButtonPressed = false;
            const auto new_ball = engine.world.create();
            CircleShape fig = CircleShape(60, Color::Yellow(), false);
            CircleShape &fig_ref = fig;

            engine.world.emplace<TransformComponent>(new_ball, engine.GetMousePosition());
            engine.world.emplace<KinematicComponent>(new_ball);
            engine.world.emplace<ColliderComponent>(new_ball, fig_ref, false, false);
            engine.world.emplace<RigidBodyComponent>(new_ball, 1, fig_ref);
            obstacles.push_back(new_ball);
        }

        engine.Render();
    }

    return 0;
}