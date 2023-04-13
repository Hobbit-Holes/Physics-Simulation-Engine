#include "./MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    //Shapes
    RectangleShape figRect1 = RectangleShape(300, 150, Color::Blue(), false);
    RectangleShape figRect2 = RectangleShape(200, 150, Color::Red(), false);

    //References
    RectangleShape &fig_refRect1 = figRect1;
    RectangleShape &fig_refRect2 = figRect2;

    //Entities
    auto a = engine.world.create();
    engine.world.emplace<TransformComponent>(a, Vec2(400, 400));
    engine.world.emplace<KinematicComponent>(a);
    engine.world.emplace<RigidBodyComponent>(a, 1.0f, fig_refRect1);
    engine.world.emplace<ColliderComponent>(a, fig_refRect1, false);

    auto b = engine.world.create();
    engine.world.emplace<TransformComponent>(b, Vec2(100, 100));
    engine.world.emplace<KinematicComponent>(b);
    engine.world.emplace<RigidBodyComponent>(b, 1.0f, fig_refRect2);
    engine.world.emplace<ColliderComponent>(b, fig_refRect2, false);

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
                                contact.start.x + contact.normal.x * 15, contact.start.y + contact.normal.y * 15,  0xFFFF00FF);
            std::cout << "Depth: " << contact.depth << std::endl; 
        }

        engine.Render();
    }

    return 0;
}