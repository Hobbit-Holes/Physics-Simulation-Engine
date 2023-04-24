#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 1000;
    int heigth = 1000;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);
    engine.lua.script_file("./assets/scripts/entities.lua");
    engine.luaTextures.script_file("./assets/scripts/sprites.lua");

    // Add Textures
    engine.SetupTextures();
    
    // Variables
    float dragImpulse = engine.lua["dragImpulse"];
    float dragRotation = engine.lua["dragRotation"];

    // Entities
    std::vector<entt::entity> entities = engine.SetupScene();

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