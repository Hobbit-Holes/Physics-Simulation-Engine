#include "MorgulEngine.hh"
#include <sol/sol.hpp>
#include <iostream>

void setup_scene(MorgulEngine &engine) {
    
}

int main(int argc, char* argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);
    engine.lua.script_file("./script-component-03.lua");
    setup_scene(engine);
    
    while (engine.NextFrame()) {
        engine.Update();
        engine.Render();
    }

    return 0;
}