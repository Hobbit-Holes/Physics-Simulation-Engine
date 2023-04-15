#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    int numVertices = 5;
    if (argc == 2) {
        numVertices = strtol(argv[1], nullptr, 0);
    }

    MorgulEngine engine = MorgulEngine(width, heigth);

    std::vector<entt::entity> obstacles;

    //Shapes
    RegularPolygonShape figPoly = RegularPolygonShape(50, numVertices, Color::Blue(), false);
    CircleShape figCircle = CircleShape(70, Color::White(), false);

    //References
    RegularPolygonShape &fig_refPoly = figPoly;
    CircleShape &fig_refCircle = figCircle;

    //Entities
    auto a = engine.world.create();
    engine.world.emplace<TransformComponent>(a, Vec2(400, 400));
    engine.world.emplace<KinematicComponent>(a);
    engine.world.emplace<RigidBodyComponent>(a, 1.0f, fig_refCircle);
    engine.world.emplace<ColliderComponent>(a, fig_refCircle, false);

    auto b = engine.world.create();
    engine.world.emplace<TransformComponent>(b, Vec2(100, 100));
    engine.world.emplace<KinematicComponent>(b);
    engine.world.emplace<RigidBodyComponent>(b, 1.0f, fig_refPoly);
    engine.world.emplace<ColliderComponent>(b, fig_refPoly, false);

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        Graphics::DrawGrid(100, true, true);
        engine.world.get<TransformComponent>(b).position = engine.GetMousePosition();

        Contact contact;
        if(Collisions::IsColliding(a, b, contact, engine.world)) {
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