#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);
    engine.lua.script_file("./snooker.lua");
    std::vector<entt::entity> entities = engine.SetupScene();

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        

        engine.Render();
    }

    return 0;
}