#include "MorgulEngine.hh"

int main(int argc, char *args[]){
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    const auto ball = engine.world.create();
    engine.world.emplace<TransformComponent>(ball, Vec2(300,100));

    while(engine.NextFrame()){
        engine.Update();

        auto view = engine.world.view<TransformComponent>();
        for(auto entity: view){
            auto& transform = view.get<TransformComponent>(entity);
            Logger::Info("Ball position: ("
                + std::to_string(transform.position.x)
                + ","
                + std::to_string(transform.position.y)
                + ")"
            );
            transform.position += Vec2(1, 2);
        }

        engine.Render();

    }

    return 0;
}