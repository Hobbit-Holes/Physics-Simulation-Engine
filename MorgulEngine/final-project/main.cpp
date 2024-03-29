#include "MorgulEngine.hh"

std::vector<Vec2> GenerateMap(int width, int height, int radius) {
    std::vector<Vec2> centers;

    float lateral = sin(M_PI / 6) * 2 * radius;
    float verticalSeparation = sqrt((lateral + radius) * (lateral + radius) - radius * radius);
    float verticalDisp = cos(M_PI / 6) * radius;

    float positionX = 0;
    float positionY = 0;
    for (int i = 0; i < (int)(width/radius); i++) {
        for (int j = 0; j < (int)(height/radius); j++) {
            positionY = (verticalSeparation * j) - verticalDisp * (i % 2);

            centers.push_back(Vec2(positionX, positionY));
        }
        positionX += radius + (lateral / 2);
    }

    return centers;
}

int main(int argc, char *argv[]) {
    int width = 1200;
    int height = 800;

    int scene = 1;
    if (argc == 2) {
        scene = strtol(argv[1], nullptr, 0);
    }

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, height);
    engine.luaTextures.script_file("./assets/scripts/sprites.lua");
    engine.luaSounds.script_file("./assets/scripts/sounds.lua");
    engine.luaFonts.script_file("./assets/scripts/fonts.lua");

    if (scene == 1) {
        engine.lua.script_file("./assets/scripts/entitiesScene1.lua");
    } else {
        engine.lua.script_file("./assets/scripts/entitiesScene2.lua");
    }

    // Systems
    BrickSystem brickSystem;
    BallMovementSystem ballMovementSystem;
    TextPunctuationSystem textPunctuationSystem;

    engine.eventBus.sink<CollisionEvent>().connect<&BrickSystem::OnCollison>(brickSystem);
    engine.eventBus.sink<CollisionEvent>().connect<&BallMovementSystem::OnCollison>(ballMovementSystem);
    engine.eventBus.sink<CollisionEvent>().connect<&TextPunctuationSystem::OnCollison>(textPunctuationSystem);

    // Add Textures
    engine.SetupTextures();

    // Add sounds
    engine.SetupSounds();

    // Fonts
    engine.SetupFonts();
    
    // Variables

    // Entities
    std::vector<entt::entity> entities = engine.SetupScene();
    
    std::vector<Vec2> centers = GenerateMap(width, height, 47);
    for (auto center: centers) {
        int random = rand() % 6;
        std::string type = "Tile" + std::to_string(random + 1);

        entt::entity water = engine.world.create();
        engine.world.emplace<TransformComponent>(water, center);
        engine.world.emplace<SpriteComponent>(water, type, 96, 96);
    }

    // Start Systems
    engine.brickSystem.Start(engine.world);

    // Game Loop
    while (engine.NextFrame()) {
        // Update Engine
        engine.Update();

        // Custom Logic
        

        // Engine Render
        engine.Render();
    }

    return 0;
}