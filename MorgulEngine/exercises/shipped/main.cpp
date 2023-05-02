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

std::vector<Vec2> GenerateIsles(std::vector<Vec2> centers, int numIsles) {
    std::vector<Vec2> islesPositions;

    int random;
    Vec2 position;
    bool repeat = false;
    for (int i = 0; i < numIsles; i++) {
        do {
            random = rand() % centers.size();
            position = centers[random];
            repeat = false;

            for (auto islePositions: islesPositions) {
                if (position == islePositions) {
                    repeat = true;
                }
            }  
        } while (repeat);

        islesPositions.push_back(position);
    }

    return islesPositions;
}

int main(int argc, char *argv[]) {
    int width = 1000;
    int height = 1000;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, height);
    engine.luaTextures.script_file("./assets/scripts/sprites.lua");
    engine.luaSounds.script_file("./assets/scripts/sounds.lua");
    engine.luaFonts.script_file("./assets/scripts/fonts.lua");
    engine.lua.script_file("./assets/scripts/entities.lua");

    // Add Textures
    engine.SetupTextures();

    // Add sounds
    engine.SetupSounds();

    // Fonts
    engine.SetupFonts();
    
    // Variables
    float dragImpulse = engine.lua["dragImpulse"];
    float dragRotation = engine.lua["dragRotation"];

    // Entities
    std::vector<entt::entity> entities = engine.SetupScene();
    
    std::vector<Vec2> centers = GenerateMap(width, height, 47);
    std::vector<Vec2> islesPosition = GenerateIsles(centers, engine.lua["numIsles"]);
    
    for (auto islePosition: islesPosition) {
        entt::entity isle = engine.world.create();
        engine.world.emplace<TransformComponent>(isle, islePosition);
        engine.world.emplace<SpriteComponent>(isle, "Isle", 96, 96);
    }

    for (auto center: centers) {
        int random = rand() % 6;
        std::string type = "Water" + std::to_string(random + 1);

        entt::entity water = engine.world.create();
        engine.world.emplace<TransformComponent>(water, center);
        engine.world.emplace<SpriteComponent>(water, type, 96, 96);
    }

    // Game Loop
    while (engine.NextFrame()) {
        // Update Engine
        engine.Update();

        // Custom Logic
        for (auto entity: entities) {
            std::string name = engine.world.get<NameGroupComponent>(entity).name;
            
            if (name == "Player") {
                const auto k = engine.world.get<KinematicComponent>(entity);
                auto& rb = engine.world.get<RigidBodyComponent>(entity);

                Vec2 friction_vector = Force::GenerateFrictionVector(dragImpulse, k.velocity);
                rb.AddForce(friction_vector);
                float friction_rotation = Force::GenerateFrictionRotation(dragRotation, k.angularVelocity);
                rb.AddTorque(friction_rotation);
            }
        }

        // Engine Render
        engine.Render();
    }

    return 0;
}