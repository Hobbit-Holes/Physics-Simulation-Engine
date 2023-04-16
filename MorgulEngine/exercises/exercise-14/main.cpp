#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    int numVertices1 = 5;
    int numVertices2 = 5;
    if (argc == 3) {
        numVertices1 = strtol(argv[1], nullptr, 0);
        numVertices2 = strtol(argv[2], nullptr, 0);
    }

    MorgulEngine engine = MorgulEngine(width, heigth);
    int status = 0;

    std::vector<entt::entity> obstacles;

    //Shapes
    RegularPolygonShape figCir = RegularPolygonShape(50, numVertices1, Color::Blue(), false);
    RegularPolygonShape figRect = RegularPolygonShape(50, numVertices2, Color::Red(), false);

    //References
    RegularPolygonShape &fig_refCir = figCir;
    RegularPolygonShape &fig_refRect = figRect;

    //Entities
    auto a = engine.world.create();
    engine.world.emplace<TransformComponent>(a, Vec2(400, 400));
    engine.world.emplace<KinematicComponent>(a);
    engine.world.emplace<ColliderComponent>(a, fig_refCir, false);
    engine.world.emplace<RigidBodyComponent>(a, 1.0f, fig_refCir);

    auto b = engine.world.create();
    engine.world.emplace<TransformComponent>(b, Vec2(100, 100));
    engine.world.emplace<KinematicComponent>(b);
    engine.world.emplace<ColliderComponent>(b, fig_refRect, false);
    engine.world.emplace<RigidBodyComponent>(b, 1.0f, fig_refRect);

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        engine.world.get<TransformComponent>(b).position = engine.GetMousePosition();

        if (engine.mouse->rightButtonPressed) {
            engine.mouse->rightButtonPressed = false;
            status = 1;

            CircleShape fig1 = CircleShape(50, Color::Blue(), false);
            CircleShape &fig_ref1 = fig1;

            CircleShape fig2 = CircleShape(50, Color::Red(), false);
            CircleShape &fig_ref2 = fig2;

            engine.world.replace<ColliderComponent>(a, fig_ref1, false);
            engine.world.replace<RigidBodyComponent>(a, 1.0f, fig_ref1, false);
            
            engine.world.replace<ColliderComponent>(b, fig_ref2, false);
            engine.world.replace<RigidBodyComponent>(b, 1.0f, fig_ref2, false);

            for (auto obstacle: obstacles) {
                CircleShape fig1 = CircleShape(30, Color::Green(), false);
                CircleShape &fig_ref1 = fig1;

                engine.world.replace<ColliderComponent>(obstacle, fig_ref1, false);
                engine.world.replace<RigidBodyComponent>(obstacle, 1.0f, fig_ref1, false);
            }
        }

        if (engine.mouse->leftButtonPressed) {
            engine.mouse->leftButtonPressed = false;
            status = 0;

            RegularPolygonShape fig1 = RegularPolygonShape(50, numVertices1, Color::Blue(), false);
            RegularPolygonShape &fig_ref1 = fig1;

            RegularPolygonShape fig2 = RegularPolygonShape(50, numVertices2, Color::Red(), false);
            RegularPolygonShape &fig_ref2 = fig2;

            engine.world.replace<ColliderComponent>(a, fig_ref1, false);
            engine.world.replace<RigidBodyComponent>(a, 1.0f, fig_ref1, false);
            
            engine.world.replace<ColliderComponent>(b, fig_ref2, false);
            engine.world.replace<RigidBodyComponent>(b, 1.0f, fig_ref2, false);

            for (auto obstacle: obstacles) {
                RegularPolygonShape fig1 = RegularPolygonShape(30, 6, Color::Green(), false);
                RegularPolygonShape &fig_ref1 = fig1;

                engine.world.replace<ColliderComponent>(obstacle, fig_ref1, false);
                engine.world.replace<RigidBodyComponent>(obstacle, 1.0f, fig_ref1, false);
            }
        }

        if (engine.keyboard->spaceKeyPressed) {
            engine.keyboard->spaceKeyPressed = false;

            if (status == 0) {
                const auto new_ball = engine.world.create();
                RegularPolygonShape fig = RegularPolygonShape(30, 6, Color::Green(), false);
                RegularPolygonShape &fig_ref = fig;

                engine.world.emplace<TransformComponent>(new_ball, engine.GetMousePosition() + Vec2(1, 1));
                engine.world.emplace<KinematicComponent>(new_ball);
                engine.world.emplace<ColliderComponent>(new_ball, fig_ref, false);
                engine.world.emplace<RigidBodyComponent>(new_ball, 1, fig_ref, false);
                obstacles.push_back(new_ball);
            } else {
                const auto new_ball = engine.world.create();
                CircleShape fig = CircleShape(30, Color::Green(), false);
                CircleShape &fig_ref = fig;

                engine.world.emplace<TransformComponent>(new_ball, engine.GetMousePosition() + Vec2(1, 1));
                engine.world.emplace<KinematicComponent>(new_ball);
                engine.world.emplace<ColliderComponent>(new_ball, fig_ref, false);
                engine.world.emplace<RigidBodyComponent>(new_ball, 1, fig_ref, false);
                obstacles.push_back(new_ball);
            }
        }

        Contact contact;
        if (Collisions::IsColliding(a, b, contact, engine.world)) {
            Graphics::DrawFillCircle(contact.start.x, contact.start.y, 3, 0xFFFF00FF);
            Graphics::DrawFillCircle(contact.end.x, contact.end.y, 3, 0xFFFF00FF);
            Graphics::DrawLine(contact.start.x, contact.start.y, 
                                contact.start.x + contact.normal.x, contact.start.y + contact.normal.y,  0xFFFF00FF);
            std::cout << "Depth: " << contact.depth << std::endl;
        }

        engine.Render();
    }

    return 0;
}