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

            CircleShape fig1 = CircleShape(50, Color::Blue(), false);
            CircleShape &fig_ref1 = fig1;

            CircleShape fig2 = CircleShape(50, Color::Red(), false);
            CircleShape &fig_ref2 = fig2;

            engine.world.replace<ColliderComponent>(a, fig_ref1, false);
            engine.world.replace<RigidBodyComponent>(a, 1.0f, fig_ref1, false);
            
            engine.world.replace<ColliderComponent>(b, fig_ref2, false);
            engine.world.replace<RigidBodyComponent>(b, 1.0f, fig_ref2, false);
        }
        if (engine.mouse->leftButtonPressed) {
            engine.mouse->leftButtonPressed = false;

            RegularPolygonShape fig1 = RegularPolygonShape(50, numVertices1, Color::Blue(), false);
            RegularPolygonShape &fig_ref1 = fig1;

            RegularPolygonShape fig2 = RegularPolygonShape(50, numVertices2, Color::Red(), false);
            RegularPolygonShape &fig_ref2 = fig2;

            engine.world.replace<ColliderComponent>(a, fig_ref1, false);
            engine.world.replace<RigidBodyComponent>(a, 1.0f, fig_ref1, false);
            
            engine.world.replace<ColliderComponent>(b, fig_ref2, false);
            engine.world.replace<RigidBodyComponent>(b, 1.0f, fig_ref2, false);
        }

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