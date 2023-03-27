#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects
    for (int i = 1; i <= 4; i++) {
        const auto tank = engine.world.create();
        engine.world.emplace<TransformComponent>(tank, Vec2(50, 50 + 50 * i));
        engine.world.emplace<NameGroupComponent>(tank, "Tank " + std::to_string(i), "Tanks");
    }
    
    for (int i = 1; i <= 4; i++) {
        const auto tank = engine.world.create();
        engine.world.emplace<TransformComponent>(tank, Vec2(50, 400 + 50 * i));
        engine.world.emplace<NameGroupComponent>(tank, "Spaceship " + std::to_string(i), "Spaceships");
    }
    
    while (engine.NextFrame()) {
        engine.Update();

        float dt = engine.GetDeltaTime();
        float totalTime = engine.GetTotalTimeInMilliSeconds();

        // Logic
        auto view = engine.world.view<TransformComponent, NameGroupComponent>();
        for (auto entity: view) {
            const auto nameGroup = view.get<NameGroupComponent>(entity);
            auto& transform = view.get<TransformComponent>(entity);

            if (nameGroup.group == "Tanks") {
                transform.position += Vec2(50, 0) * dt;
                Graphics::DrawFillRect(transform.position.x, transform.position.y, 50, 20, Color::Orange());
            }
            
            if (nameGroup.group == "Spaceships") {
                transform.position.x += 100 * dt;
                transform.position.y += sin(totalTime * 0.002);
                Graphics::DrawFillCircle(transform.position.x, transform.position.y, 20, Color::Cyan());
            }

            std::cout << "Name: " << nameGroup.name << "\t\tGroup: " << nameGroup.group << std::endl;
        }

        engine.Render();
    }
    
    return 0;
}